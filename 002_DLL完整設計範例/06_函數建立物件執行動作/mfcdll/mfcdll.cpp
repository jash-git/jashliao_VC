// mfcdll.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "mfcdll.h"
#include "Math.h"
////////////////////////////////////////////////
#pragma data_seg(".SHARDAT")
static HWND      ghWndMain  = 0;
static HHOOK     ghKeyHook = NULL ;
#pragma data_seg()

HINSTANCE ghInstance = 0;
HOOKPROC  glpfnHookProc = 0;
CMath *math;
/////////////////////////////////////////////////
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
// CMfcdllApp

BEGIN_MESSAGE_MAP(CMfcdllApp, CWinApp)
	//{{AFX_MSG_MAP(CMfcdllApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMfcdllApp construction

CMfcdllApp::CMfcdllApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMfcdllApp object
int EXPORTED_DLL_FUNCTION KbdHookProc (int a, int b)
{
	int r;
	math=new CMath();
	math->add(a,b);
	r=(int)math->m_dblData3;
	delete math;
	return (r);
}
CMfcdllApp theApp;

BOOL CMfcdllApp::InitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ghInstance = AfxGetInstanceHandle();
	return CWinApp::InitInstance();
}

int CMfcdllApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CWinApp::ExitInstance();
}
