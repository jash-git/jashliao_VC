// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__99A0B1DF_4607_43FB_8A4B_E8C2D68D4093__INCLUDED_)
#define AFX_STDAFX_H__99A0B1DF_4607_43FB_8A4B_E8C2D68D4093__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <wininet.h> //添加這個。注意順序，順序亂了也編譯不過 //Step 1
#include <afxdisp.h>        // MFC Automation classes
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__99A0B1DF_4607_43FB_8A4B_E8C2D68D4093__INCLUDED_)
