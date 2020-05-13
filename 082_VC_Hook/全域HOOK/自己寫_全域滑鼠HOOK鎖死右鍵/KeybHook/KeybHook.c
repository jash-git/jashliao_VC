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
	if(nCode>=0) 
	{
		HWND hWnd = FindWindow(NULL, "test_UI");
		if(wParam==WM_RBUTTONDOWN)
			PostMessage(hWnd,ON_3,0,0);
	}
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

   hhook = SetWindowsHookEx(WH_MOUSE, KeyboardHook_HookProc, g_hinstDll, 0);
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
