// ServerSocket.cpp : implementation file
//

#include "stdafx.h"
#include "TelnetServer.h"
#include "ServerSocket.h"
#include "TelnetServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerSocket

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CServerSocket, CSocket)
	//{{AFX_MSG_MAP(CServerSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CServerSocket member functions

void CServerSocket::SetParent(CDialog *pWnd)
{
	m_pWnd = pWnd;
}

void CServerSocket::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	if (nErrorCode == 0)
		((CTelnetServerDlg*)m_pWnd)->OnClose();
}

void CServerSocket::OnSend(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	if (nErrorCode == 0)
		((CTelnetServerDlg*)m_pWnd)->OnSend();
}

void CServerSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	if (nErrorCode == 0)
		((CTelnetServerDlg*)m_pWnd)->OnReceive();
}
