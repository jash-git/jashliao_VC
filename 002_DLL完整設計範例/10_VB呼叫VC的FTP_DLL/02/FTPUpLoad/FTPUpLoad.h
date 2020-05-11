// FTPUpLoad.h : main header file for the FTPUPLOAD DLL
//

#if !defined(AFX_FTPUPLOAD_H__43464847_1068_4125_B5D5_D692C2D39A7D__INCLUDED_)
#define AFX_FTPUPLOAD_H__43464847_1068_4125_B5D5_D692C2D39A7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFTPUpLoadApp
// See FTPUpLoad.cpp for the implementation of this class
//
#define EXPORTED_DLL_FUNCTION \
__declspec(dllexport) __stdcall
bool EXPORTED_DLL_FUNCTION ConnectFTP (char *chrFTPServer,char *chruser,char *chrpws,int intport);
void EXPORTED_DLL_FUNCTION ClosetFTP ();
bool EXPORTED_DLL_FUNCTION UpLoadFTP (char *chrfilename);
bool EXPORTED_DLL_FUNCTION DownLoadFTP (char *chrfilename);
class CFTPUpLoadApp : public CWinApp
{
public:
	CFTPUpLoadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFTPUpLoadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CFTPUpLoadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTPUPLOAD_H__43464847_1068_4125_B5D5_D692C2D39A7D__INCLUDED_)
