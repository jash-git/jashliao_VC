// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__030C2F5E_C74E_47FD_9B4E_36AD55A934F8__INCLUDED_)
#define AFX_STDAFX_H__030C2F5E_C74E_47FD_9B4E_36AD55A934F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afx.h>
#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <iostream>
#include <afxsock.h>		// MFC socket extensions
#include <afxinet.h>//FTP_1
#include <afxtempl.h>//CArray Step_01 

#import "msxml3.dll"//step Åª¨úXML1
using namespace MSXML2;

//////////////////////////////////////////
//sqlite step 01
#include "sqlite3.h"
#pragma comment(lib, "sqlite3.lib")
//////////////////////////////////////////
#include <intshcut.h>
#include <Wininet.h>
//////////////////////////////////////////
// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__030C2F5E_C74E_47FD_9B4E_36AD55A934F8__INCLUDED_)
