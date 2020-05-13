// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__14891723_77F4_40DB_950E_2C75D2DA03A8__INCLUDED_)
#define AFX_STDAFX_H__14891723_77F4_40DB_950E_2C75D2DA03A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxsock.h>		// MFC socket extensions
#include <Winver.h>//第13.7版->查詢程式版本
#include "mmsystem.h"//第12.5版->系統音量設定
#import "msxml3.dll"//step 讀取XML1
using namespace MSXML2;
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__14891723_77F4_40DB_950E_2C75D2DA03A8__INCLUDED_)
