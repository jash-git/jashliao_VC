// LaunchDLL.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "LaunchDLL.h"

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
// CLaunchDLLApp

HHOOK Hook;
/////////////////////////////////Step1_S 
int gintValueBuf=0;
bool gblnCheck=false;
/////////////////////////////////Step_E
LRESULT CALLBACK LauncherHook(int nCode,WPARAM wParam,LPARAM lParam); 
void SaveLog(char* c); 



BEGIN_MESSAGE_MAP(CLaunchDLLApp, CWinApp)
	//{{AFX_MSG_MAP(CLaunchDLLApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLaunchDLLApp construction



CLaunchDLLApp::CLaunchDLLApp()
{

}

/////////////////////////////////////////////////////////////////////////////
// The one and only CLaunchDLLApp object

CLaunchDLLApp theApp;

//输出函数
DllExport void WINAPI InstallLaunchEv() 
{ 
	//安装全局钩子
	Hook=(HHOOK)SetWindowsHookEx(WH_KEYBOARD, 
		(HOOKPROC)LauncherHook, 
		theApp.m_hInstance, 
		0); 
} 

//钩子函数
LRESULT CALLBACK LauncherHook(int nCode,WPARAM wParam,LPARAM lParam)//Step2 
{ 
	//让其它全局钩子获得消息
	LRESULT Result=CallNextHookEx(Hook,nCode,wParam,lParam); 

	if(nCode==HC_ACTION) 
	{ 
		if(lParam & 0x80000000) 
		{ 
			//保存按键消息
			char c[1]; 
			c[0]=wParam; 
			SaveLog(c); 
		} 
	} 
	return Result; 
} 

//保存按键记录
void SaveLog(char* c) 
{ 
	HWND hWnd0;
	int intInput=0;
	intInput=*(c+0);
	if(gblnCheck)
	{//gblnCheck==true
		if(gintValueBuf!=intInput)
		{
			if((intInput==112)||(intInput==18))//F1,Alt
			{
				//闽超祘Α
				hWnd0=FindWindow(NULL,"Cute_Main_Control");
				if(hWnd0!=NULL)
					SendMessage(hWnd0,WM_CLOSE,0,0);
				//AfxMessageBox("kill");
			}
			gintValueBuf=0;
			gblnCheck=false;
		}
	}
	else
	{//gblnCheck==false
		if((intInput==112)||(intInput==18))//F1,Alt
		{
			gintValueBuf=intInput;
			gblnCheck=true;
		}
	}
} 


