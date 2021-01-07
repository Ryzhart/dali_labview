#ifndef  __DALIACCESSAPI_H_
  #define  __DALIACCESSAPI_H_

#include "DALICommands.h"


typedef int HDALI;


// device type definitions: ------------------------------------------------------------------------
//
#define DD_NOSERVER			-3									///< DaliBusServer not running
#define DD_PORTAVAIL		-2									///< Port available, but no valid device present
#define DD_PORTNOTAVAIL		-1									///< Port not available
#define DD_TESTPORT			0									///< Test if port available
#define DD_AUTODEVICE		1									///< don't care about device type
#define DD_OK				1

#define DD_NORMAL			2									///< ID of the standard DSI cable
#define DD_EXTENDED			3									///< ID of the extended DSI cable
#define DD_WIRELESS			4
#define DD_DALIBM			5									///< ID of the Dali Busmaster device
#define DD_MONITOR			6									///< ID of the DSI Monitor device
#define DD_DALIMONITOR		7									///< ID of the Dali Monitor device
#define DD_DALISCI			8									///< ID of the Dali SCI device
#define DD_DALISCI2			9									///< ID of the Dali SCI plus device
#define DD_DALISCI3         10                                  ///< ID of the USA- Dali SCI plus device
#define DD_DALIUSB		    11
#define DD_WMSBUSMONITOR	12									///< ID of a special purpose device (used by Lunatone)
#define DD_XTOUCHPANEL		13									///< ID of the Dali x-touchPANEL (connected via Bluetooth)
#define DD_VIRTUAL          14

// for compatibility with old software
#define  DD_MAXTYPES          14
#define  DD_NOTAVAIL          -1


// device type port offsets: ------------------------------------------------------------------------
//
#define SERIAL_PORT_MAX		   255 								///< max number of serial ports (127 for Win98, 255 for NT, XP...)

#define USB_PORT_BASE		       0x400   					    ///< Base port for the USB devices, used to iterate through all USB devices
#define USB_PORT_ITERATE_MAX       0x4FF     				    ///< max. 255 USB ports for iterations (see OpenPort)
#define USB_PORT_DEV_BASE          0x500
#define USB_PORT_MAX           0x0FFFFFF                        ///< abs. max. port no. (higher values conflict with IP addresses)


// Message sent to the window hWnd as specified in OpenPort(): --------------------------------------
//
static UINT RWM_DALIDATA = RegisterWindowMessage( _T("DALI_DATA_LT-{710C388E-A776-4996-87EB-FC87513107D5}"));
/// RWM_DALIDATA	wParam= DI_8BIT ... DI_NEMA
///					lParam= 8, 16, 24bit DALI data, in case of DI_8BIT: 0..255 and also DALI_NO...DALI_BUSSHORT

// callback for 
typedef int (WINAPI* pDALICALLBACK)( int iCmdType, DWORD dwData, DWORD dwFlags);
// the callback function will be called when a DALI frame is received. Normally the function
// should return a value <0 (e.g. DALI_NO). If >= 0 is returned this will be sent to the DALI
// bus as an 8bit answer frame
// iCmdType: DI_8BIT ... DI_NEMA
// dwData: 8, 16, 24bit DALI data


// --------------------------------------------------------------------------------------------------
// DLL interface API: (dynamic linking)
typedef int		(WINAPI*  pGETDLLVERSION)( int);  
typedef HDALI	(WINAPI*  pOPENPORT)(DWORD*, int*, HWND); 
typedef HDALI	(WINAPI*  pOPENPORTCB)(DWORD*, int*, pDALICALLBACK, DWORD); 
typedef int		(WINAPI*  pCLOSEPORT)(HDALI); 
typedef int		(WINAPI*  pSENDBUSDATA)(HDALI, DWORD, DWORD, DWORD, WORD, DWORD, DWORD);
typedef int		(WINAPI*  pGETDEVICEFEATURES)(HDALI, void*, DWORD);
typedef int		(WINAPI*  pSETDEVICEFEATURES)(HDALI, void*, DWORD);
typedef int		(WINAPI*  pSENDDALIDATA)(HDALI, WORD, DWORD, DWORD, DWORD);	  // historic, do not use
typedef int		(WINAPI*  pSENDGENERICDATA)(HDALI, BYTE*, int);				  // internal; do not use

// function prototypes for statically linking with the DLL:
extern "C"
{
int		WINAPI  GetDLLVersion( int);  
HDALI	WINAPI  OpenPort(DWORD*, int*, HWND); 
HDALI	WINAPI  OpenPortCB(DWORD*, int*, pDALICALLBACK, DWORD); 
int		WINAPI  ClosePort(HDALI); 
int		WINAPI  SendBusData(HDALI, DWORD, DWORD, DWORD, WORD, DWORD, DWORD);
int		WINAPI  GetDeviceFeatures(HDALI, void*, DWORD);
int		WINAPI  SetDeviceFeatures(HDALI, void*, DWORD);
}

// -------------------------------------------------------------------------------------------------
// return values for SendBusData()
//
#define DALI_SWITCHTO_DSI	-8		///< Info: switch to DSI receive after 8ms bus low
#define DALI_SWITCHTO_DALI	-7		///< Info: switch back to DALI receive mode after 8ms bus high
#define DALI_BUSOK			-6		///< Info: bus voltage OK (returns to normal operation after short circuit)
#define DALI_BUSSHORT		-5		///< Bus power supply disconnected or bus short circuit
#define DALI_ERROR			-4		///< 
#define DALI_TRASH			-3		///< 
#define DALI_NO				-2		///< 
#define DALI_OK				-1		///< 
#define DALI_YES			0xff	///< 

// -------------------------------------------------------------------------------------------------
// flags for wFlags in SendBusData()
//
#define  ADDR_DEFAULT       0x00000000	///< same as ADDR_BROADCAST
#define  ADDR_BROADCAST     0x00000001	///< send to all ballasts
#define  ADDR_GROUP         0x00000002	///< send to group only
#define  ADDR_ADDR          0x00000004	///< send to short address only
#define  ADDR_SPECIAL       0x00000008	///< 
#define  ADDR_FLAG_MASK     0x000000FF	///< 

#define  BDF_REPEATTIME     0x00000100	///< currently unused
#define  BDF_NOAUTODTR      0x00000200	///< suppress automatic setting of DTR
#define  BDF_NOCMDREPEAT    0x00000400 	///< suppress automatic command repetition
#define  BDF_PRIORITY_0     0x00001000	///< 
#define  BDF_PRIORITY_1     0x00002000	///< 
#define  BDF_PRIORITY_2     0x00003000	///< 
#define  BDF_PRIORITY_3     0x00004000	///< 
#define  BDF_PRIORITY_4     0x00005000	///< 
#define  BDF_PRIORITY_STD   0x00000000	///< 
#define  BDF_PRIORITY_MASK  0x0000f000	///< 
#define  BDF_PRIORITY_SHIFT 12
#define  BDF_FLAG_MASK      0x00000F00	///< 
// new flags in version 2.5:
#define  BDF_SETDTR			0x00010000	///< force the setting of the DTR before the command
#define  BDF_SENDTWICE		0x00020000  ///< force command repetition
#define  BDF_SETDEVTYPE		0x00040000  ///< send device type before command
#define  BDF_ACTUALLEVELDTR	0x00080000  ///< send 'store actual level to DTR' before command









// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// --------------------------------------------------------------------------------
// command type flags used for SendDaliData(),   (historic)
// command type values for the message sent to hWnd or the callback function:
//
#define DI_UNKNOWN		0
#define DI_8BIT			1	///< dwInfo in the DALIDataMessage structure
#define DI_16BIT		2	///< dwInfo in the DALIDataMessage structure
#define DI_DALI			2	///< dwInfo in the DALIDataMessage structure
#define DI_eDALI		3	///< dwInfo in the DALIDataMessage structure
#define DI_DSI			4	///< dwInfo in the DALIDataMessage structure
#define DI_extDSI		5	///< dwInfo in the DALIDataMessage structure
#define DI_NEMA			6	///< 24bit DALI NEMA protocol
							// 7: RESERVED
#define DI_17BIT		8	///< 17bit DALI protocol (requires DALI USB V1.5 or higher)
#define DI_PLC			12	///< PLC protocol (requires special DALI USB)
#define DI_DALIANSWER	13	///< send 8bit DALI frame immediately without collision detection

// --------------------------------------------------------------------------------
// flags for SendDaliData():    (historic)
#define DALI_SEND_PRIO_0    0x0000
#define DALI_SEND_PRIO_1    0x0000
#define DALI_SEND_PRIO_2    0x0000
#define DALI_SEND_PRIO_3    0x0000
#define DALI_SEND_PRIO_4    0x0000
#define DALI_SEND_PRIOMASK  0x00FF
//
// additional flags that can be OR'ed together with the priority flags
#define DALI_SEND_TWICE		0x0100	///< Flag for SendBusData function
#define DALI_SEND_DTR		0x0200
#define DALI_SEND_DEVTYPE   0x0400
#define DALI_SEND_ACTUALLEVELDTR   0x0800



// Lunatone specific: 
// WMS bus device info flags:
#define WMSBUS_ID       0x0100
#define WMSBUS_24BIT	0x0101	///< dwInfo in the DALIDataMessage structure
#define WMSBUS_8BIT	    0x0102	///< dwInfo in the DALIDataMessage structure
#define WMSBUS_18BIT	0x0103	///< dwInfo in the DALIDataMessage structure


//////////////////////////////////////////////////////////////


#endif