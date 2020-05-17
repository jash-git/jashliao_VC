// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__393E7D72_20BB_45DF_AD67_7C29E313780A__INCLUDED_)
#define AFX_STDAFX_H__393E7D72_20BB_45DF_AD67_7C29E313780A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__393E7D72_20BB_45DF_AD67_7C29E313780A__INCLUDED_)


typedef int(PASCAL *lpCVR_InitComm)(int port);
typedef int(PASCAL *lpCVR_CloseComm)();
typedef int(PASCAL *lpCVR_Authenticate)();
typedef int(PASCAL *lpCVR_Read_Content)();

typedef int(PASCAL *lpGetPeopleName)( unsigned char *strTmp, int *strLen);
typedef int(PASCAL *lpGetPeopleSex)(unsigned char *strTmp, int *strLen);
typedef int(PASCAL *lpGetPeopleNation)(unsigned char *strTmp, int *strLen);
typedef int(PASCAL *lpGetPeopleBirthday)(unsigned char *strTmp, int *strLen);
typedef int(PASCAL *lpGetPeopleAddress)(unsigned char *strTmp, int *strLen);
typedef int(PASCAL *lpGetPeopleIDCode)(unsigned char *strTmp, int *strLen);
typedef int(PASCAL *lpGetDepartment)(unsigned char *strTmp, int *strLen);
typedef int(PASCAL *lpGetStartDate)(unsigned char *strTmp, int *strLen);
typedef int(PASCAL *lpGetEndDate)(unsigned char *strTmp, int *strLen);
typedef int(PASCAL *lpGetNationCode)(UCHAR *sexData, int * pLen);
typedef int(PASCAL *lpGetNationCodeStrU)(unsigned char * nationData, int *pLen);
typedef int(PASCAL *lpCVR_GetSAMIDU)(unsigned char *SAMID);

typedef int(PASCAL *lpGetPeopleChineseName)( unsigned char *strTmp, int *strLen);
typedef int(PASCAL *lpGetPeopleCertVersion)( unsigned char *strTmp, int *strLen);

typedef int(PASCAL *lpGetNewAppMsgU)( unsigned char *strTmp, int *strLen);
typedef int(PASCAL *lpGetCertTypeU)( unsigned char *strTmp, int *strLen);
typedef int(PASCAL *lpGetBMPData)(UCHAR * bmpdate, int * pLen);
typedef int(PASCAL *lpGetFPDate)(UCHAR *strTmp, int * pLen);
