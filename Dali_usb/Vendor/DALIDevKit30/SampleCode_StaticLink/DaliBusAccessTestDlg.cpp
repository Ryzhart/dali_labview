// DaliBusAccessTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DaliBusAccessTest.h"
#include "DaliBusAccessTestDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif





/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDaliBusAccessTestDlg dialog

CDaliBusAccessTestDlg::CDaliBusAccessTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDaliBusAccessTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDaliBusAccessTestDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hDeviceHandle= NULL;
}

void CDaliBusAccessTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDaliBusAccessTestDlg)
	DDX_Control(pDX, IDC_CMDNUMBER, m_CmdNumber);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDaliBusAccessTestDlg, CDialog)
	//{{AFX_MSG_MAP(CDaliBusAccessTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED( IDC_BCAST_ON, OnBCastOn)
    ON_BN_CLICKED( IDC_BCAST_OFF, OnBCastOff)
    ON_BN_CLICKED( IDC_SEND, OnSendCommand)
    ON_BN_CLICKED( IDC_OPENBUS, OnBusOpen)
	ON_WM_DESTROY()
	ON_EN_CHANGE(IDC_CMDNUMBER, OnChangeCmdnumber)
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
	ON_REGISTERED_MESSAGE(RWM_DALIDATA, OnReceivedDALIData)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDaliBusAccessTestDlg message handlers

BOOL CDaliBusAccessTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();


	m_bError= FALSE;
	m_iGroup= 0;


	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	

    // --------------------------------------------------------------------------
    // --------------------------------------------------------------------------
    // --------------------------------------------------------------------------
    // in this sample we use the C++ wrapper object to open, close and communicate
    // with the DALI interface device:
    //
    //
    // first of all test for the availability and version of the DALIBusAccessDLL:
    //
	// The wrapper object provides two methods for this:
	//   GetDLLVersion() and
	//   GetDLLVersionString()
	// For convenience we use the string method here:
	//
    CString Str;
	CString VersionStr;	
	int iV;
    if( iV= GetDLLVersion( 1))
     {
       // DLL loaded successfully:
		Str.Format( "V%d.%d.%d", iV/100, (iV%100)/10, iV%10);
		VersionStr= "DLL: "+ Str;
		// test if BusServer is accessible and display version info:	
		if( iV= GetDLLVersion( 2))
		{
		  Str.Format( "V%d.%d.%d", iV/100, (iV%100)/10, iV%10);
		  VersionStr+= "  |  BusServer: "+ Str;
		}
		else
		  VersionStr+= "  |  Error reading DALIServer Version!";
     } 
     else
     {
       // DALI DLL could not be loaded 
	   VersionStr= "DaliBusAccessDLL could not be loaded!";
       GetDlgItem( IDC_TESTGROUP1)->EnableWindow( FALSE);
       GetDlgItem( IDC_TESTGROUP2)->EnableWindow( FALSE);
       GetDlgItem( IDC_OPENBUS)->EnableWindow( FALSE);
       GetDlgItem( IDC_BCAST_ON)->EnableWindow( FALSE);
       GetDlgItem( IDC_BCAST_OFF)->EnableWindow( FALSE);
       GetDlgItem( IDC_CMDTXT)->EnableWindow( FALSE);
       GetDlgItem( IDC_CMDNUMBER)->EnableWindow( FALSE);
       GetDlgItem( IDC_DTRTXT)->EnableWindow( FALSE);
       GetDlgItem( IDC_DTRVAL)->EnableWindow( FALSE);
       GetDlgItem( IDC_SEND)->EnableWindow( FALSE);
       GetDlgItem( IDC_ANSWERTXT)->EnableWindow( FALSE);
       GetDlgItem( IDC_ANSWER)->EnableWindow( FALSE);
     }

     SetDlgItemText( IDC_DLLVERSIONTXT, VersionStr); 
 

	 SetTimer( 1234, 100, NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDaliBusAccessTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDaliBusAccessTestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}


// --------------------------------------------------------------------------
//
// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDaliBusAccessTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


// --------------------------------------------------------------------------
//
void CDaliBusAccessTestDlg::OnDestroy() 
{
	if(m_hDeviceHandle)
	{
		ClosePort( m_hDeviceHandle);           // close the DALI access gateway
		m_hDeviceHandle= NULL;
	}


	KillTimer( 1234);
	CDialog::OnDestroy();

}


// --------------------------------------------------------------------------
//   open the DALI bus interface
//
void CDaliBusAccessTestDlg::OnBusOpen() 
{
    DWORD dwPort= USB_PORT_BASE;
    int iDevice= DD_DALIUSB;


   if( !m_hDeviceHandle)
    {

	   DWORD dwPort= USB_PORT_BASE;   // we open a DALI USB for demonstration
									  // to open a std. SCI use 1 for COM1, 2 for COM2:
	   int iDevice= DD_DALIUSB;       // test for connected device type
									  // if you are shure what is connected you may supply
									  // the device type here (e.g. DD_DALISCI if iPort [1..255])
	    
		// example on how to open a DALI SCI (if we know one should be connected)
//		dwPort= 1;					  // COM1 for example
//		iDevice= DD_AUTODEVICE;

	   // now try to open the device:
	   //
	   m_hDeviceHandle= OpenPort( &dwPort, &iDevice, m_hWnd);
	   //
	   // if everything is fine, we get the opened device type in iRet:
	   //
	   if( m_hDeviceHandle > 0)
	   {
		 CString Str;  
		 switch( iDevice)
			{
			  case DD_NORMAL:        Str= "std. DSI cable";     break;
			  case DD_EXTENDED:      Str= "extended DSI cable"; break; 
			  case DD_DALIBM:        Str= "USA DALI BusMaster"; break;  
			  case DD_MONITOR:       Str= "DSI Monitor";        break;
			  case DD_DALIMONITOR:   Str= "DALI/DSI Monitor";   break;
			  case DD_DALISCI:       Str= "DALI SCI";           break;
			  case DD_DALISCI2:      Str= "DALI SCI2";          break;
			  case DD_DALISCI3:      Str= "DALI SCI3";          break;
			  case DD_DALIUSB:       Str= "DALI SCI USB";       break;
			  case DD_WMSBUSMONITOR: Str= "WMS Bus Monitor";    break;
			  case DD_XTOUCHPANEL:   Str= "DALI x-touchPANEL"; break;
			  case DD_VIRTUAL:       Str= "DALI Virtual Device"; break;
			  default:               Str= "unsupported device.";  break;  
			}   
		 if( iDevice == DD_DALIUSB)
		 {
			 CString SerNr;
			 SerNr.Format( "  (SerNo.: %d)", dwPort- USB_PORT_DEV_BASE);
			 Str+= SerNr;
		 }
		 SetDlgItemText( IDC_CONNECTEDDEVICE, Str); 

         GetDlgItem( IDC_TESTGROUP1)->EnableWindow( TRUE);
         GetDlgItem( IDC_TESTGROUP2)->EnableWindow( TRUE);
         GetDlgItem( IDC_BCAST_ON)->EnableWindow( TRUE);
         GetDlgItem( IDC_BCAST_OFF)->EnableWindow( TRUE);
         GetDlgItem( IDC_CMDTXT)->EnableWindow( TRUE);
         GetDlgItem( IDC_CMDNUMBER)->EnableWindow( TRUE);
         GetDlgItem( IDC_SEND)->EnableWindow( TRUE);
		 SetDTRVisibility();	
         GetDlgItem( IDC_ANSWERTXT)->EnableWindow( TRUE);
         GetDlgItem( IDC_ANSWER)->EnableWindow( TRUE);
	   }
	   else
	   {
		 SetDlgItemText( IDC_CONNECTEDDEVICE, "DALI bus interface could not be opened!"); 
	   }
    }  
}

// --------------------------------------------------------------------------
//
void CDaliBusAccessTestDlg::SetDTRVisibility( void)
{	

   int iCmd= GetDlgItemInt( IDC_CMDNUMBER, NULL, FALSE);


   BOOL bDTREnable= FALSE;
	if( ((iCmd >= CMD_STORE_MAX_LEVEL) && (iCmd <= CMD_STORE_FADERATE)) ||	// 42...47
		((iCmd >= CMD_STORE_SCENE0) && (iCmd <= CMD_STORE_SCENE15)) ||	    // 64...79
		(iCmd == CMD_STORE_SHORT_ADDR) )								    // 128
	  bDTREnable= TRUE;
   

   GetDlgItem( IDC_DTRTXT)->EnableWindow( bDTREnable);
   GetDlgItem( IDC_DTRVAL)->EnableWindow( bDTREnable);
}

// --------------------------------------------------------------------------
//
void CDaliBusAccessTestDlg::OnBCastOn() 
{
	int iRet;

	ClearAnswerText();

	iRet = SendDALIData(CMD_RECALL_MAX);
	SetAnswerText( iRet);
}

// --------------------------------------------------------------------------
//
void CDaliBusAccessTestDlg::OnBCastOff() 
{
	int iRet;

	ClearAnswerText();

	iRet = SendDALIData(CMD_OFF);
	SetAnswerText( iRet);
}

// --------------------------------------------------------------------------
//
void CDaliBusAccessTestDlg::OnSendCommand() 
{
	int iRet;

	ClearAnswerText();

	int iCmd= GetDlgItemInt( IDC_CMDNUMBER, NULL, FALSE);
	int iDTR= 0;	
    if( NeedSetDTR( iCmd))
		iDTR= GetDlgItemInt( IDC_DTRVAL, NULL, FALSE);

	iRet= SendDALIData( iCmd, iDTR);
	SetAnswerText( iRet);
}


// --------------------------------------------------------------------------
//
void CDaliBusAccessTestDlg::ClearAnswerText( void) 
{
	SetDlgItemText( IDC_ANSWER, "-");
}

// --------------------------------------------------------------------------
//
void CDaliBusAccessTestDlg::SetAnswerText( int iRet) 
{
   CString Str;

	switch( iRet)
	{
		case DALI_BUSSHORT:  //	-5
			Str= "Bus Short!";
		  break;
		case DALI_ERROR:	 //	-4
			Str= "DALI Error!";
		  break;
		case DALI_TRASH:	 //	-3	
			Str= "Framing error!";
		  break;
		case DALI_NO:		 //	-2
			Str= "NO";
		  break;
		case DALI_OK:		 //	-1
			Str= "OK";
		  break;
		case DALI_YES:		 // 0xff 
			Str= "YES (0xFF)";
		  break;
		default:
			Str.Format( "%d  (0x%02X)", iRet, iRet);
		  break;
	}

	SetDlgItemText( IDC_ANSWER, Str);

}




// --------------------------------------------------------------------------
//
void CDaliBusAccessTestDlg::OnChangeCmdnumber() 
{
	
	SetDTRVisibility();
}



// --------------------------------------------------------------------------
//
// wParam: Messsage Code: (defined in DaliBusAccessAPI.h)
//						  DI_UNKNOWN			(0)
//						  DI_8BIT				(1)	 
//						  DI_16BIT, DI_DALI		(2)
//						  DI_eDALI				(3)
//
// lParam: DALI Data:	  8, 16 or 24bit DALI data	
//
LRESULT CDaliBusAccessTestDlg::OnReceivedDALIData (UINT wParam, LONG lParam)
{




  return 0;
}

void CDaliBusAccessTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	CDialog::OnTimer(nIDEvent);
}



int  CDaliBusAccessTestDlg::SendDALIData( WORD  wBusCommand,     
                             DWORD dwBusData /*= 0*/, DWORD  dwFlags /*= 0*/, 
                             WORD  wBusAddress /*= 0*/, DWORD  dwAdditionalData /*= 0*/)
{

  int   iRet= -4; 


	// now send the command (eventually including EnableDeviceType and DTR command)
//	if( Init())   // DLL loaded?
    {
       DWORD dwAdditionalAddress= 0;
       iRet= SendBusData( m_hDeviceHandle, (DWORD)wBusCommand, dwBusData, dwFlags, wBusAddress,
                         dwAdditionalData, dwAdditionalAddress);
    }
	return iRet;
}


BOOL CDaliBusAccessTestDlg::NeedSetDTR( int iCmd)
{
	BOOL bTwice= FALSE;


	if( ((iCmd >= CMD_STORE_MAX_LEVEL) && (iCmd <= CMD_STORE_FADERATE)) ||	// 42...47
		((iCmd >= CMD_STORE_SCENE0) && (iCmd <= CMD_STORE_SCENE15)) ||	    // 64...79
		(iCmd == CMD_STORE_SHORT_ADDR) )								    // 128
	  bTwice= TRUE;

  return bTwice;
}


