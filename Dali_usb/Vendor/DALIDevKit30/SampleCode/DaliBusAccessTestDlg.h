// DaliBusAccessTestDlg.h : header file
//

#if !defined(AFX_DALIBUSACCESSTESTDLG_H__C378E19E_F773_45C5_AE9B_46A57F040B02__INCLUDED_)
#define AFX_DALIBUSACCESSTESTDLG_H__C378E19E_F773_45C5_AE9B_46A57F040B02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// the DALI DLL access:
#include "..\DALIdll.h"


/////////////////////////////////////////////////////////////////////////////
// CDaliBusAccessTestDlg dialog

class CDaliBusAccessTestDlg : public CDialog
{
// Construction
public:
	CDaliBusAccessTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDaliBusAccessTestDlg)
	enum { IDD = IDD_DALIBUSACCESSTEST_DIALOG };
	CEdit	m_CmdNumber;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDaliBusAccessTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void SetDTRVisibility( void);
	void SetAnswerText( int iRet); 
	void ClearAnswerText( void); 

protected:
	BOOL	m_bError;
	int		m_iGroup;

protected:
	HICON m_hIcon;
	CDALIdll	m_DaliBus;            // the DALI gateway object

	// Generated message map functions
	//{{AFX_MSG(CDaliBusAccessTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBCastOn();
	afx_msg void OnBCastOff();
	afx_msg void OnSendCommand();
	afx_msg void OnBusOpen();
	afx_msg void OnDestroy();
	afx_msg void OnChangeCmdnumber();
	//}}AFX_MSG
	afx_msg LRESULT OnReceivedDALIData (UINT wParam, LONG lParam);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DALIBUSACCESSTESTDLG_H__C378E19E_F773_45C5_AE9B_46A57F040B02__INCLUDED_)
