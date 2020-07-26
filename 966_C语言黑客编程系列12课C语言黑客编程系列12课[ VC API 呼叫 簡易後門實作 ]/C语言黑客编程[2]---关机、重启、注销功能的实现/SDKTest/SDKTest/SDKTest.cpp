
#include <tchar.h>
#include <Windows.h>


BOOL EnableShutDownPriv()
{
	HANDLE hToken = NULL;
	TOKEN_PRIVILEGES tkp = {0};
	if ( !OpenProcessToken( GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken ) ) {
		return FALSE;
	}
	if ( !LookupPrivilegeValue( NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid ) ) {
		CloseHandle( hToken );
		return FALSE;
	}
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if ( !AdjustTokenPrivileges( hToken, FALSE, &tkp, sizeof(TOKEN_PRIVILEGES), NULL, NULL ) ) {
		CloseHandle( hToken );
		return FALSE;
	}
	return TRUE;
}

BOOL ReSetWindows(DWORD dwFlags, BOOL bForce)
{
	//Check the param;
	if ( dwFlags != EWX_LOGOFF && dwFlags != EWX_REBOOT && dwFlags != EWX_SHUTDOWN ) {
		return FALSE;
	}

	//Get the os version;
	OSVERSIONINFO osvi = {0};
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	if ( !GetVersionEx(&osvi) ) {
		return FALSE;
	}
	if ( osvi.dwPlatformId == VER_PLATFORM_WIN32_NT ) {
		EnableShutDownPriv();
	}
	dwFlags |= (bForce != FALSE) ? EWX_FORCE : EWX_FORCEIFHUNG;
	return ExitWindowsEx(dwFlags, 0);
}

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	if ( _tcscmp(lpCmdLine, _T("/r")) == 0 ) {
		ReSetWindows(EWX_REBOOT, FALSE);
	}else if ( _tcscmp(lpCmdLine, _T("/s")) == 0 ) {
		ReSetWindows(EWX_SHUTDOWN, FALSE);
	}else if ( _tcscmp(lpCmdLine, _T("/l")) == 0 ) {
		ReSetWindows(EWX_LOGOFF, FALSE);
	}
	return 0;
}