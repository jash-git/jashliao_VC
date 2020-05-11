// bmp2pdf.h : main header file for the BMP2PDF application
//

#if !defined(AFX_BMP2PDF_H__FFFF42F4_F92C_4E5C_8A3D_31C546ED7EFA__INCLUDED_)
#define AFX_BMP2PDF_H__FFFF42F4_F92C_4E5C_8A3D_31C546ED7EFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBmp2pdfApp:
// See bmp2pdf.cpp for the implementation of this class
//

class CBmp2pdfApp : public CWinApp
{
public:
	CBmp2pdfApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmp2pdfApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBmp2pdfApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMP2PDF_H__FFFF42F4_F92C_4E5C_8A3D_31C546ED7EFA__INCLUDED_)
