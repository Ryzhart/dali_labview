// DALIdll.cpp : implementation file
//

#include "stdafx.h"
#include "DALIdll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


typedef _TCHAR  DevNames[100];

DevNames   g_szDevNames[DD_MAXTYPES+1]= 
                     { _T("Port not available"),				// 0
                       _T("no device detected"),				// 1
                       _T("normal DSI cable"),					// 2
                       _T("winDIM DSI cable"),					// 3
                       _T("radioDIM transceiver"),				// 4 
                       _T("DALI BusMaster"),					// 5
                       _T("DSI Monitor"),						// 6
                       _T("DALI Monitor"),						// 7
                       _T("DALI SCI"),							// 8
                       _T("DALI SCI2"),							// 9 
                       _T("DALI SCI3"),							// 10 
                       _T("DALI USB"),							// 11
                       _T("WMS Bus Monitor"),					// 12  
                       _T("xtouch DALI interface"),				// 13
                       _T("Virtual Device") };					// 14


/////////////////////////////////////////////////////////////////////////////
// CDALIdll


CDALIdll::CDALIdll()
{
 
   m_hDLLInstance= NULL;
   m_iDevice= DD_AUTODEVICE;
   m_dwPort= 0;
   m_hDeviceHandle= 0;



   m_DLLPath= DALI_DLL_NAME;


}

CDALIdll::~CDALIdll()
{
	if( m_hDLLInstance)
	{
		FreeLibrary(m_hDLLInstance);
		m_hDLLInstance= NULL;
	}
}


/////////////////////////////////////////////////////////////////////////////
// CDALIdll implementation
//


// ----------------------------------------------------------------------------
//  returns e.g. 10 = Version 1.0          (for backward compatibility)
//    if dwFlags!= 0: 
//               100 = Version 1.0.0
//               251 = Version 2.5.1
//
//  returns 0.0 if the DLL could not be loaded
//
// dwFlags:  GVS_DLL_VERSION       ...   DLL version information
//           GVS_BUSSERVER_VERSION ...   BusServer version information
// 
int CDALIdll::GetDLLVersion( DWORD dwFlags /*= 0 */)
{
  int iRet= 0;

  
    if( Init() )
     {
		 int iIndex= 0;
		 if( dwFlags & GVS_DLL_VERSION)
			 iIndex= 1;
		 if( dwFlags & GVS_BUSSERVER_VERSION)
			 iIndex= 2;
         pGETDLLVERSION pFunc;
         pFunc= (pGETDLLVERSION)GetProcAddress( m_hDLLInstance, _T("GetDLLVersion")); 
         // Prototype:  int WINAPI GetDLLVersion( void)
		 if( pFunc)
			iRet= (*pFunc)( iIndex);
     } 

  return iRet; 
}

// ----------------------------------------------------------------------------
// e.g. "Version 1.0" 
//  
// returns:  TRUE:  DLL loaded and version string filled in
//           FALSE: DLL not loaded
//
// dwFlags:  the flags may be or'ed together 
//           GVS_DLL_VERSION   ...   version information
//           GVS_DLL_NAME      ...   the DLL's name
//           GVS_DLL_PATH      ...   the dll's full path name
//			 GVS_BUSSERVER_VERSION   DALIBusServer version information (starts bus server
//																   if not already running)
// 
BOOL CDALIdll::GetDLLVersionString( CString* pStr, DWORD dwFlags /*= GVS_VERSION */)
{
  BOOL bOK= FALSE;

    if( Init() )      // be shure to load the DLL..
     {
       int iVer= GetDLLVersion( GVS_DLL_VERSION);
       if( iVer > 0)
        { 
		  CString cStr;
		  BOOL bAdded= FALSE;
		  if( dwFlags & GVS_DLL_PATH)            // add full path name...
		  {
			 cStr= m_DLLPath;
			 bAdded= TRUE;
             bOK= TRUE;
		  }
		  else if( dwFlags & GVS_DLL_NAME)       // or name only
		  {
			 cStr= DALI_DLL_NAME;
			 bAdded= TRUE;
             bOK= TRUE;
		  }
		  if( dwFlags & GVS_DLL_VERSION)
		  {
			  if( bAdded)
				  cStr+= ": ";
			  CString cVersion;
			  cVersion.Format( _T("V%d.%d.%d"), iVer/100, (iVer%100)/10, iVer%10);
			  cStr+= cVersion;
              bOK= TRUE;
		  }
		  if( dwFlags & GVS_BUSSERVER_VERSION)
		  {
		      int iVer= GetDLLVersion( GVS_BUSSERVER_VERSION);
			  if( bAdded)
				  cStr+= ": ";
			  CString cVersion;
			  cVersion.Format( _T("V%d.%d.%d"), iVer/100, (iVer%100)/10, iVer%10);
			  cStr+= cVersion;
			  if( iVer > 0)
	            bOK= TRUE;
		  }

          if( pStr)  
           *pStr= cStr;
        }   
     }  

  return bOK;
}


/////////////////////////////////////////////////////////////////////////////
// if iDevice == -1 (default) the current device m_iDevice will be taken
// else iDevice specifies the device
//
BOOL CDALIdll::GetInterfaceName( CString* psName, int iDevice/*=-1*/)
{
   CString sName;

   if( iDevice < 0)
    iDevice= m_iDevice;    

    if( (iDevice >= 0) && (iDevice <= DD_MAXTYPES))
      sName= (LPCTSTR)g_szDevNames[iDevice];
     else
      sName= "unknown device";
       

    if( psName)
     *psName= sName;         // copy it...

  return TRUE;
}



// ----------------------------------------------------------------------------
// OpenPort( ) 
//
//  dwPort:    1..255                          serial port
//             USB_PORT_BASE...USB_PORT_MAX    USB port
//
//  iDevice:   DD_AUTODEVICE ... DD_DEVICE_VIRTUAL  (see DLL documentation)
//
//  hWnd:      window handle that receives the DALI commands from the 
//             opened gateway. 
//             Set to NULL if no messages should be received.                           
//
//
//  Return:    the device identifier (device type DD_EXTENDED ... DD_SCIUSB)
//             < 0 error (DD_
//
int  CDALIdll::OpenPort( DWORD dwPort, int iDevice/*= DD_AUTODEVICE*/,
						 HWND hWnd /*= NULL*/, DWORD* pdwSerialNumber/*= NULL*/)
{
	int	iRet= -1;

	if( pdwSerialNumber)
	   *pdwSerialNumber= 0;

	if( Init() )   // be shure to load the DLL..
	 {
		//if( m_hDeviceHandle < 1)
		 {
			pOPENPORT pFunc;
			pFunc= (pOPENPORT)GetProcAddress( m_hDLLInstance, _T("OpenPort")); 
			// Prototype:  int WINAPI OpenPortCB( DWORD*, int*, HWND)
			if( pFunc)
			{
				int iDev= iDevice;
				HDALI hDev = (*pFunc)( &dwPort, &iDev, hWnd);
				if( iDevice != DD_TESTPORT)
				{
					TRACE( _T("OpenPort : Handle:%x Port:%d Device:%d\n"), m_hDeviceHandle,dwPort,iDevice);
					m_iDevice= iDev;
					m_dwPort= dwPort;           // return the actually opened port (the device ID for USB devices)
					m_hDeviceHandle= hDev;
				}

				if (hDev > 0)
				 {
					iRet= iDev;              // return the opened device type
					if( pdwSerialNumber)
					   *pdwSerialNumber= dwPort- USB_PORT_DEV_BASE;
				 }
				else
				 {
				   iRet=  hDev;      // return the error code
				   if( iDevice != DD_TESTPORT)
					{
						m_iDevice= iRet;
						m_dwPort= 0;
				   }
				 }

			}
		 }

	 }

	return iRet;
}

int  CDALIdll::OpenPortCB( DWORD dwPort, int iDevice/*= DD_AUTODEVICE*/,
						 pDALICALLBACK pCallBack/*=NULL*/, DWORD dwUserData/*=0*/,
						 DWORD* pdwSerialNumber/*= NULL*/)
{
	int	iRet= -1;

	if( pdwSerialNumber)
	   *pdwSerialNumber= 0;

	if( Init() )   // be shure to load the DLL..
	 {
		//if( m_hDeviceHandle < 1)
		 {
			pOPENPORTCB pFunc;
			pFunc= (pOPENPORTCB)GetProcAddress( m_hDLLInstance, _T("OpenPortCB")); 
			// Prototype:  int WINAPI OpenPortCB( DWORD*, int*, pDALICALLBACK, DWORD)
			if( pFunc)
			{
				int iDev= iDevice;
				HDALI hDev = (*pFunc)( &dwPort, &iDev, pCallBack, dwUserData);
				if( iDevice != DD_TESTPORT)
				{
					TRACE( _T("OpenPortCB : Handle:%x Port:%d Device:%d\n"), m_hDeviceHandle,dwPort,iDevice);
					m_iDevice= iDev;
					m_dwPort= dwPort;           // return the actually opened port (the device ID for USB devices)
					m_hDeviceHandle= hDev;
				}

				if (hDev > 0)
				 {
					iRet= iDev;              // return the opened device type
					if( pdwSerialNumber)
					   *pdwSerialNumber= dwPort- USB_PORT_DEV_BASE;
				 }
				else
				 {
				   iRet=  hDev;      // return the error code
				   if( iDevice != DD_TESTPORT)
					{
						m_iDevice= iRet;
						m_dwPort= 0;
				   }
				 }

			}
		 }

	 }

	return iRet;
}


// --------------------------------------------------------------------------
// ClosePort( ) -------------------------------------------------------------
//
//  Closes a COM Port previously opend with OpenPort
//
//  Return:   TRUE:   OK
//            FALSE:  Port could not be closed
//
BOOL  CDALIdll::ClosePort( void)
{
	int iRet= 0;

	if( Init() && (m_hDeviceHandle > 0) )   // be shure the DLL is loaded..
	 {
		pCLOSEPORT  pFunc;
		pFunc= (pCLOSEPORT)GetProcAddress( m_hDLLInstance, _T("ClosePort")); 
		if( pFunc)
			iRet= (*pFunc)(m_hDeviceHandle);
		m_hDeviceHandle = 0;
		m_iDevice = DD_AUTODEVICE;
        m_dwPort= 0; 
	 }

	return (BOOL)iRet;
}


// --------------------------------------------------------------------------
//  Tests if there is a DALI interface device connected. Does not actually
//  open the port, since we use iDev= DD_TESTPORT.
//
//  For DALI USB devices the serial number will be returned in *pdwSerialNumber.
//	This feature is not supported for the serial interface devices.
//
//  Return:    the device identifier (device type DD_EXTENDED ... DD_SCIUSB)
//             < 0 error (DD_
//
int CDALIdll::TestPort( DWORD dwPort, DWORD* pdwSerialNumber/*= NULL*/)   
{

	int iDev= DD_TESTPORT;

	if( pdwSerialNumber)
	   *pdwSerialNumber= 0;

	if( Init() )   // be shure to load the DLL..
	 {
		pOPENPORT pFunc;
		pFunc= (pOPENPORT)GetProcAddress( m_hDLLInstance, _T("OpenPort")); 
		// Prototype:  int WINAPI OpenPort( int iCom, int iDevice, HWND hWnd, PDALICALLBACK
		if( pFunc)
		{
			HDALI hDev = (*pFunc)( &dwPort, &iDev, NULL);
			if (hDev > 0)
			 {
				if( pdwSerialNumber)
				   *pdwSerialNumber= dwPort- USB_PORT_DEV_BASE;
			 }
			else
			 {
			   iDev=  hDev;      // return the error code
			 }
		}

	 }
 
  return iDev;
}


// virtual ------------------------------------------------------------------
// override this if a special behaviour is needed:
//
// TRUE if the DALI cmd needs to be sent twice	
//
BOOL CDALIdll::NeedSendTwice( int iCmd)
{
	BOOL bTwice= FALSE;


	if( ((iCmd >= CMD_RESET) && (iCmd <= CMD_STORE_SHORT_ADDR)) ||	// 32..128
		(iCmd == CMD_INITIALISE) || (iCmd == CMD_RANDOMISE) )       // 258, 259
	  bTwice= TRUE;

  return bTwice;
}


// virtual ------------------------------------------------------------------
// override this if a special behaviour is needed:
//
// TRUE if the DALI cmd needs the DTR to be set before the command is sent
//
BOOL CDALIdll::NeedSetDTR( int iCmd)
{
	BOOL bTwice= FALSE;


	if( ((iCmd >= CMD_STORE_MAX_LEVEL) && (iCmd <= CMD_STORE_FADERATE)) ||	// 42...47
		((iCmd >= CMD_STORE_SCENE0) && (iCmd <= CMD_STORE_SCENE15)) ||	    // 64...79
		(iCmd == CMD_STORE_SHORT_ADDR) )								    // 128
	  bTwice= TRUE;

  return bTwice;
}


/////////////////////////////////////////////////////////////////////////////
// HighLevel function, that provides complete DALI- functionality
//
/////////////////////////////////////////////////////////////////////////////
//
//
// wBusCommand:    CMD_xxx  as defined in DALICommands.h
//
// wBusData:       data byte used for some CMD_xxx. (see DALI draft)
//
// wFlags:         ADDR_DEFAULT, ADDR_BROADCAST:  send to all ballasts,
//                                                wBusAddress not used 
//                 ADDR_GROUP  send to DALI- group 0..15
//                 ADDR_ADDR   send to DALI- device 0..63
//
//                 BDF_NOCMDREPEAT suppress automatic command repetition for 
//                                 DALI special commands.
//                 BDF_NOAUTODTR   suppress automatic loading of the DTR.
//                                 default: use wBusData to load the DTR if necessary
//                                 for a particular command.
//
//				Flags that are new in V2.5:
//				   BDF_SETDTR	   send the DTR command with wBusData before the actual command
//				   BDF_SENDTWICE   send the comand twice (uses Prio 0)
//				   BDF_SENDDEVTYPE send the command 272 (EnableDeviceType) before a DTR/Cmd sequence.
//								   The device type is given in the LowByte of dwAdditionalData.
//								   If CMD_SEND_eDALI is used as the command see description of dwAdditionalData.
//
//				Flags that are no longer supported in V2.5:
//                 BDF_REPEATTIME  programmable repeattime no longer supported. (makes no sense in multimaster environment)
//
// wBusAddress:    device address or group address (see wFlags)
//
// dwAdditionalData:    For std. DALI commands (CMD_DIRECT_LIGHT_CONTROL,CMD_OFF....CDM_RESERVED287) this is
//						used for the Device type if BDF_SENDDEVTYPE is set in wFlags.
//						For the pecial command definitions CMD_SEND_DALI8bit...CMD_SEND_DALI24bit this holds
//						the DTR value in the low byte (if BDF_SETDTR is set) and the device type in the next byte.
//                      For CMD_SEND_eDALI commands the DeviceType will be sent using the eDALI SetControlType command.
//
// dwAdditionalAddress:  not used at the moment, set to 0;
//
// ---------------------------------------------------------------------------------
//
//  Return:    >=0:  the device's answer (8bit DALI data)
//              -1:  OK - there is no answer for the current DALI command  
//              -2:  DALI NO   
//              -3:  DALI Error (2 or more devices are answering simultaneously) 
//              -4:  ser. port Error (CheckSum, Timeout)
//
//
int  CDALIdll::SendDALIData( WORD  wBusCommand,     
                             DWORD dwBusData /*= 0*/, DWORD  dwFlags /*= 0*/, 
                             WORD  wBusAddress /*= 0*/, DWORD  dwAdditionalData /*= 0*/)
{

  int   iRet= -4; 


	// now send the command (eventually including EnableDeviceType and DTR command)
	if( Init())   // DLL loaded?
    {
       DWORD dwAdditionalAddress= 0;
       pSENDBUSDATA  pFunc;
       pFunc= (pSENDBUSDATA)GetProcAddress( m_hDLLInstance, _T("SendBusData")); 
	   if( pFunc)
		iRet=  (*pFunc)( m_hDeviceHandle, (DWORD)wBusCommand, dwBusData, dwFlags, wBusAddress,
                         dwAdditionalData, dwAdditionalAddress);
    }
	return iRet;
}

// ---------------------------------------------------------------------------------
//  send generic data to a DALI USB.
// (internal use only - do not use unless you know what you are doing)
//
// The first bytes in pData needs to be the Cmd Byte (see description for DALI USB)
//
int  CDALIdll::SendGenericData( BYTE* pData, int iSize)
{
	int iRet= 0;

	if( Init())   // DLL loaded?
    {
       pSENDGENERICDATA  pFunc;
       pFunc= (pSENDGENERICDATA)GetProcAddress( m_hDLLInstance, _T("SendGenericData")); 
	   if( pFunc)
		iRet=  (*pFunc)( m_hDeviceHandle, pData, iSize);
    }
	return iRet;
}


// ----------------------------------------------------------------------------
// set path to the DLL (set to DALI_DLL_NAME per default)
//
void CDALIdll::SetDLLPath( LPCSTR pStr)
{

  m_DLLPath= pStr;
}


// ----------------------------------------------------------------------------
// used to load the DLL
//
BOOL CDALIdll::Init( void)
{

   if( m_hDLLInstance == NULL)
    {

      m_hDLLInstance= LoadLibrary( m_DLLPath);	// try to load with the default path
    
	  // registry entry currently only supported for Windows:
	  #ifndef _WIN32_WCE
      if( m_hDLLInstance == NULL)
       {										// could not load the DLL -> look in registry for the path
          HKEY hRegKey;
          if( ERROR_SUCCESS == RegOpenKeyEx(HKEY_CURRENT_USER, _T("Software\\Lunatone\\DALIBusServer"), 0, KEY_READ, &hRegKey))
           {
             _TCHAR szBuffer[500];
             DWORD dwLength= 500;
			 // the installer stores the entry DALIBusAccessDLLPath with the full path to the DLL and Busserver in the registry:
             long err= RegQueryValueEx( hRegKey, _T("DALIBusAccessDLLPath"), NULL, NULL, (unsigned char *)szBuffer, &dwLength);
             if( ERROR_SUCCESS == err) //RegQueryValue( hRegKey, "DALIBusAccessDLLPath", szBuffer, &lLength))
              {
				 #ifdef _UNICODE
					 wcscat( szBuffer, _T("\\"));
					 wcscat(  szBuffer, DALI_DLL_NAME);
				 #else
					 strcat( szBuffer, "\\");
					 strcat(  szBuffer, DALI_DLL_NAME);
				 #endif
                 RegCloseKey( hRegKey);
                 m_hDLLInstance= LoadLibrary( szBuffer);
                 if( m_hDLLInstance)
                   m_DLLPath= szBuffer;   // copy path name
              }
              else  
                 RegCloseKey( hRegKey);
           }  
       }    
	  #endif
    }


  return (m_hDLLInstance != NULL);
}


