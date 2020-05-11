// ListenSocket.cpp : implementation file
//

#include "stdafx.h"
#include "TCP.h"
#include "ListenSocket.h"
////////////////////////////
#include "DataSocket.h"
#include "TCPDlg.h"
////////////////////////////
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ListenSocket

ListenSocket::ListenSocket()
{
}

ListenSocket::~ListenSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(ListenSocket, CSocket)
	//{{AFX_MSG_MAP(ListenSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// ListenSocket member functions

void ListenSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	//////////////////////////////
	DataSocket *ds=new DataSocket;
	Accept(*ds);
	/////////////////////////////
	CSocket::OnAccept(nErrorCode);
}
