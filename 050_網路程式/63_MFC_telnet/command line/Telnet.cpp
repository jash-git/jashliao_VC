#include "stdafx.h"
#include <windows.h>
#include <winsock.h>
#include <process.h>
#include "SocketRx.h"
#include "SocketDx.h"
#include "SocketTx.h"
#include <conio.h>
#include "Telnet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CWinApp theApp;
using namespace std;
HANDLE stdin1;
HANDLE hHeap1;
HANDLE stdout1;
HANDLE stderr1;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
int nRet;
WSADATA wd;
int nPort;
char strIP[256];
char strTitle[256];
SOCKET hSocket;
HANDLE hThread[2];

	nRet = AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0);
	if ( nRet == FALSE )
	{
		printf("\nAfxWinInit Fail..............!\n");
		return 0;
	}

	nPort = IPPORT_TELNET;
	SetConsoleTitle("Try To connect...");
  	WSAStartup(0x0101,&wd);
    
	stdin1 = GetStdHandle(STD_INPUT_HANDLE);
	stdout1 = GetStdHandle(STD_OUTPUT_HANDLE);
	stderr1 = GetStdHandle(STD_ERROR_HANDLE);
	hHeap1 = GetProcessHeap();
	SetConsoleMode(stdin1,ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT);
	
	printf("\nPlease Enter IP/Domain.........:");
	scanf("%s",strIP);
	if ( strlen(strIP) < 3 ) { printf("\nBad IP/Domain\n"); getch(); return 0; }
	printf("\nPort...........%d :",nPort);
	
	CSocketDx	SocketDx(strIP,nPort);
	hSocket = SocketDx.TelnetConnect();
	if ( hSocket == NULL ) { printf("\nUnable To Connect\n");getche(); return 0; }

	CSocketRx	SocketRx(hSocket,hThread[0]); 
	CSocketTx	SocketTx(hSocket,hThread[1]);

	wsprintf(strTitle,"Connecting to %s:%d",strIP,nPort);
	SetConsoleTitle(strTitle);

	WaitForMultipleObjects(2,hThread,FALSE,INFINITE);
	return 0;
}
