// VMR9PlayerContorl.h : main header file for the VMR9PLAYERCONTORL application
//

#if !defined(AFX_VMR9PLAYERCONTORL_H__51CB3F43_6ED4_4B88_B03C_5FFD88EBEAE2__INCLUDED_)
#define AFX_VMR9PLAYERCONTORL_H__51CB3F43_6ED4_4B88_B03C_5FFD88EBEAE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVMR9PlayerContorlApp:
// See VMR9PlayerContorl.cpp for the implementation of this class
//

class CVMR9PlayerContorlApp : public CWinApp
{
public:
	CVMR9PlayerContorlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVMR9PlayerContorlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVMR9PlayerContorlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VMR9PLAYERCONTORL_H__51CB3F43_6ED4_4B88_B03C_5FFD88EBEAE2__INCLUDED_)
