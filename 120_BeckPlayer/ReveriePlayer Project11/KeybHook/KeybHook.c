#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
/////////////////////////////////////////////////
//jash.liao write 
#define ON_0 WM_USER + 500
#define ON_1 WM_USER + 501
#define ON_2 WM_USER + 502
#define ON_3 WM_USER + 503 
#define ON_4 WM_USER + 504 
#define ON_5 WM_USER + 505 
#define ON_6 WM_USER + 506 
#define ON_7 WM_USER + 507 
#define ON_8 WM_USER + 508 
#define ON_9 WM_USER + 509 
/////////////////////////////////////////////////
HINSTANCE g_hinstDll = NULL;

#pragma data_seg(".drectve")
    static char szLinkDirectiveShared[] = "-section:Shared,rws";
#pragma data_seg()
#pragma data_seg("Shared")

HHOOK g_hhook      = NULL;
HWND  g_hwndPost   = NULL;
UINT  g_uMsgNotify = WM_USER;
BOOL gblnCtrl;
#pragma data_seg()

static LRESULT WINAPI KeyboardHook_HookProc (
   int nCode,
   WPARAM wParam, 
   LPARAM lParam) 
{

   LRESULT lResult = CallNextHookEx(g_hhook, nCode, wParam, lParam);
/*
//jash.liao write 
   if (nCode == HC_ACTION) 
   {
      PostMessage(g_hwndPost, g_uMsgNotify, wParam, lParam);
   }
*/
   //////////////////////////////////////////////////////////////
   //jash.liao write 
   int intvalue=0;
	if(nCode==HC_ACTION) 
	{ 
		if((lParam & 0x80000000)==0) 
		{ 
			//保存按键消息
			char c[1]; 
			c[0]=wParam;
			intvalue=wParam;
			if(intvalue==17)
			{
				gblnCtrl=TRUE;
			}
			if(intvalue==82 && gblnCtrl)//ctrl+R
			{
				HWND hWnd = FindWindow(NULL, "ReveriePlayer");
				PostMessage(hWnd,ON_0,0,0);
				gblnCtrl=FALSE;
			}
			if(intvalue==79 && gblnCtrl)//ctrl+O
			{
				HWND hWnd = FindWindow(NULL, "ReveriePlayer");
				PostMessage(hWnd,ON_1,0,0);
				gblnCtrl=FALSE;
			}
			if(intvalue==72 && gblnCtrl)//ctrl+H
			{
				FILE *pf;
				pf=fopen("close.msg","w");
				fprintf(pf,"closemsg");
				fclose(pf);
				gblnCtrl=FALSE;
			}
		}//if(lParam & 0x80000000)  
	}//if(nCode==HC_ACTION)
	////////////////////////////////////////////////////////////////////////
   return(lResult);
}

BOOL WINAPI SetKeyboardHook (void) 
{
   HHOOK hhook;

   if (g_hhook != NULL) return(FALSE);
   /*
   g_hwndPost   = hWndPost;
   g_uMsgNotify = Msg;
   */
   Sleep(0);

   hhook = SetWindowsHookEx(WH_KEYBOARD, KeyboardHook_HookProc, g_hinstDll, 0);
   InterlockedExchange((PLONG) &g_hhook, (LONG) hhook);
   return(g_hhook != NULL);
}

BOOL WINAPI ReleaseKeyboardHook() 
{
   BOOL fOK = TRUE;

   if (g_hhook != NULL) 
   {
      fOK = UnhookWindowsHookEx(g_hhook);
      g_hhook = NULL;
   }
   return(fOK);
}

BOOL WINAPI DllMain (HINSTANCE hinstDll, DWORD fdwReason, LPVOID lpvReserved) 
{
   switch (fdwReason) 
   {
      case DLL_PROCESS_ATTACH:
         g_hinstDll = hinstDll;
         break;
   }
   return(TRUE);
}
