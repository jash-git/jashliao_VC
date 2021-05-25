// Texture.h : main header file for the TEXTURE application
//

#if !defined(AFX_TEXTURE_H__8F197651_3E9F_4D5F_B43A_F18CB80F9A71__INCLUDED_)
#define AFX_TEXTURE_H__8F197651_3E9F_4D5F_B43A_F18CB80F9A71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTextureApp:
// See Texture.cpp for the implementation of this class
//

class CTextureApp : public CWinApp
{
public:
	CTextureApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextureApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTextureApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEXTURE_H__8F197651_3E9F_4D5F_B43A_F18CB80F9A71__INCLUDED_)
