// DALIdll.h : header file
//

///
/// \todo	remove MFC dependency  (CString, etc.)	
///

// 10.1.2012:  added OpenPortCB - uses callback function to receive DALI data
//             (instead of the PostMessage method)

#ifndef  __DALIDLL_H
  #define __DALIDLL_H

#include "DaliBusAccessAPI.h"

#ifdef _WIN32_WCE
	// Windows CE version:
	#define   DALI_DLL_NAME    _T("DALIBusAccessDllCe.dll")
#else
	// Windows version:
	#ifdef _NO_BUSSERVER
			#define   DALI_DLL_NAME    "DALIUSBAccess.dll"
	#else
			#define   DALI_DLL_NAME    "DaliBusAccess.dll"
	#endif
#endif

// flags for GetDLLVersionString()
#define   GVS_DLL_VERSION		    0x0001
#define   GVS_DLL_NAME              0x0002
#define   GVS_DLL_PATH              0x0004 
#define   GVS_BUSSERVER_VERSION		0x0100



/////////////////////////////////////////////////////////////////////////////
// CDALIdll Object

/// \brief A thin C++ wrapper around the DaliBusAccess.dll.
///
///
class CDALIdll
{

public:
	CDALIdll();           
	virtual ~CDALIdll( );

// Methods:
public:
    int  GetDLLVersion(  DWORD dwFlags = GVS_DLL_VERSION );                     // returns e.g. 10 = Version 1.0
    int  GetDLLVersionString( CString* pStr, DWORD dwFlags= GVS_DLL_VERSION);   // e.g. "V1.0"
    BOOL GetInterfaceName( CString* psName, int iDevice= -1); // e.g. "DALI SCI"

    int  OpenPort( DWORD dwPort, int iDevice= DD_AUTODEVICE, HWND hWnd= NULL, DWORD* pdwSerialNumber= NULL);
    int  OpenPortCB( DWORD dwPort, int iDevice= DD_AUTODEVICE, pDALICALLBACK pCallBack= NULL, DWORD dwUserData= 0, DWORD* pdwSerialNumber= NULL);
    BOOL ClosePort( void);                                              // closes a previously opened port      
    int  TestPort( DWORD dwPort, DWORD* pdwSerialNumber= NULL);         // return device type and serial number
    BOOL IsOpen( void)  { if( m_hDeviceHandle > 0)
                            return TRUE;
                           else
                            return FALSE;
                        } 
    DWORD GetPort( void)    { return m_dwPort; }
    int   GetDevType( void) { return m_iDevice; }

    int  SendDALIData( WORD  wBusCommand, DWORD dwBusData= 0, DWORD dwFlags= 0, 
                       WORD  wBusAddress= 0, DWORD  dwAdditionalData= 0);

    void SetDLLPath( LPCSTR pStr);   // normally not needded, set only for special environments (debugging...)

    int  SendGenericData( BYTE* pData, int iSize);


// Overridables:
public:
	virtual BOOL NeedSendTwice( int iCmd);	// TRUE if the DALI cmd needs to be sent twice	
	virtual BOOL NeedSetDTR( int iCmd);		// TRUE if the command needs the DTR to be set


protected:
    BOOL Init( void);               // dynamically loads the DLL
    HINSTANCE  m_hDLLInstance;      // holds the DLL's instance handle

    HDALI		m_hDeviceHandle;    // the device handle returned by OpenPort()
	int			m_iDevice;          // the device type
	DWORD		m_dwPort;           // the port 

    CString     m_DLLPath;          // the path to the DLL ( DALI_DLL_NAME per default)
};

#endif  // __DALIDLL_H

/////////////////////////////////////////////////////////////////////////////
