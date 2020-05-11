// ListenerSocket.cpp : implementation file
//

#include "stdafx.h"
#include "TelnetServer.h"
#include "ListenerSocket.h"
#include "TelnetServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListenerSocket

CListenerSocket::CListenerSocket()
{
}

CListenerSocket::~CListenerSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CListenerSocket, CSocket)
	//{{AFX_MSG_MAP(CListenerSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CListenerSocket member functions

void CListenerSocket::SetParent(CDialog *pWnd)
{
	m_pWnd = pWnd;
}

void CListenerSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (nErrorCode == 0)
		((CTelnetServerDlg*)m_pWnd)->OnAccept();
}
