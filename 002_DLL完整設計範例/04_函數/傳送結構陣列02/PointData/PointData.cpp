// PointData.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "PointData.h"
#include <stdio.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CPointDataApp

BEGIN_MESSAGE_MAP(CPointDataApp, CWinApp)
	//{{AFX_MSG_MAP(CPointDataApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
void EXPORTED_DLL_FUNCTION GetValue1(point *p,long number)
{
	FILE *p1;
	int k;
	p1=fopen("data.txt","w");
	for(k=0;k<number;k++)
		fprintf(p1,"%f\t%f\n",(p+k)->x,(p+k)->y);
	fclose(p1);
}
void EXPORTED_DLL_FUNCTION ChangeValue1(point *p,point *p1)
{
	p1->y=p->x;
	p1->x=p->y;
}
CPointDataApp::CPointDataApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPointDataApp object

CPointDataApp theApp;
