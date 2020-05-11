// DC2DC.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "DC2DC.h"
#include "DibSection.h"
#include <stdlib.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int n;
char str1[10];
//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CDC2DCApp

BEGIN_MESSAGE_MAP(CDC2DCApp, CWinApp)
	//{{AFX_MSG_MAP(CDC2DCApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDC2DCApp construction

CDC2DCApp::CDC2DCApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	n=0;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDC2DCApp object
void EXPORTED_DLL_FUNCTION DC2DC (long GetHDC,long w,long h)
{
	long Width,Height;
	long x,y;
	long R,G,B;
	CString  str2;
	itoa(n,str1,10);
	n++;
	str2=str1;
	str2=str2+".bmp";
	CDibSection testDib;
	CDibSection testDib1;
	testDib.Create(w,h,24);
	Width=testDib.Width();
	Height=testDib.Height();
	testDib1.Create(Width,Height,24);
	BitBlt(CDibDC(testDib),0,0,w/1,h/1,(HDC)GetHDC,0,0,SRCCOPY);
	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)testDib.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q=(BYTE *)testDib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			B=*q1++;
			G=*q1++;
			R=*q1++;
			*q++=(0.299*R+0.587*G+0.114*B);
			*q++=(0.299*R+0.587*G+0.114*B);
			*q++=(0.299*R+0.587*G+0.114*B);
		}
	}
	testDib1.SaveBmp("test1.bmp");
	testDib.SaveBmp(str2.GetBuffer(0));
}
CDC2DCApp theApp;
