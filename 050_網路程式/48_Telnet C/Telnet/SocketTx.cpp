// SocketTx.cpp: implementation of the CSocketTx class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Telnet.h"
#include "conio.h"
#include "SocketTx.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
extern HANDLE stdin1;
extern HANDLE stdout1;
extern HANDLE stderr1;

CSocketTx::CSocketTx(SOCKET hSocket,HANDLE &hThread)
{
DWORD dwRet;

	m_nExit = 0;
	m_hThread = NULL;
	m_hSocket = hSocket;

	m_hThread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE) SendTh,(LPVOID)this,0,&dwRet);
	if ( m_hThread == NULL ) return;
	hThread = m_hThread;
}
CSocketTx::~CSocketTx()
{
	m_nExit = 1;
}
DWORD CSocketTx::SendTh(CSocketTx *pSocketTx)
{
char pBuff[256];
unsigned long dwLen;
int nRet;
char ch;

	dwLen = 1;
	while(1)
	{
		if ( pSocketTx->m_nExit == 1 ) { ExitThread(0); return 0; }
		WaitForSingleObject(stdin1,INFINITE);
		ch = getch();
		nRet = send(pSocketTx->m_hSocket,&ch,dwLen,0);
		if ( nRet == SOCKET_ERROR ) { TRACE("\nSend Fail........!\n"); pSocketTx->m_nExit = 0; continue;}
	}
  return 0;
}
