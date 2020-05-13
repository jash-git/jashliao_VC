// chtvSignage_Communication.h : main header file for the CHTVSIGNAGE_COMMUNICATION application
//

#if !defined(AFX_CHTVSIGNAGE_COMMUNICATION_H__FE31BEEC_3A5E_4E8D_88DC_1C8E12122E25__INCLUDED_)
#define AFX_CHTVSIGNAGE_COMMUNICATION_H__FE31BEEC_3A5E_4E8D_88DC_1C8E12122E25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CChtvSignage_CommunicationApp:
// See chtvSignage_Communication.cpp for the implementation of this class
//

class CChtvSignage_CommunicationApp : public CWinApp
{
public:
	CChtvSignage_CommunicationApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChtvSignage_CommunicationApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CChtvSignage_CommunicationApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHTVSIGNAGE_COMMUNICATION_H__FE31BEEC_3A5E_4E8D_88DC_1C8E12122E25__INCLUDED_)
