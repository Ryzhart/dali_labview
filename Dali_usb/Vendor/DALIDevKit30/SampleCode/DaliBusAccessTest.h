// DaliBusAccessTest.h : main header file for the DALIBUSACCESSTEST application
//

#if !defined(AFX_DALIBUSACCESSTEST_H__864C0EAC_D049_4F9C_B148_3443592644CE__INCLUDED_)
#define AFX_DALIBUSACCESSTEST_H__864C0EAC_D049_4F9C_B148_3443592644CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDaliBusAccessTestApp:
// See DaliBusAccessTest.cpp for the implementation of this class
//

class CDaliBusAccessTestApp : public CWinApp
{
public:
	CDaliBusAccessTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDaliBusAccessTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDaliBusAccessTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DALIBUSACCESSTEST_H__864C0EAC_D049_4F9C_B148_3443592644CE__INCLUDED_)
