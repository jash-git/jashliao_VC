// DataSocket.cpp : implementation file
//

#include "stdafx.h"
#include "MultiServer.h"
#include "DataSocket.h"
#include "GlobalVar.h"
#include "MultiServerDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define ONGetData WM_USER + 233 

/////////////////////////////////////////////////////////////////////////////
// CDataSocket

CDataSocket::CDataSocket()
{
}

CDataSocket::~CDataSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CDataSocket, CSocket)
	//{{AFX_MSG_MAP(CDataSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CDataSocket member functions

void CDataSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	struct DataType GetData;
	GetData.lngNumber=-1; 
	memset(GetData.chrFirstData,'\0',sizeof(GetData.chrFirstData)); 
	memset(GetData.chrSecondData,'\0',sizeof(GetData.chrSecondData));
	memset(GetData.chrThirdData,'\0',sizeof(GetData.chrThirdData));
	memset(GetData.chrFourthData,'\0',sizeof(GetData.chrFourthData));
	Receive(&GetData,sizeof(GetData));
	CMultiServerDlg * dlg=((CMultiServerDlg *) AfxGetMainWnd());
	glngNumber=GetData.lngNumber; 
	gstrFirstData=GetData.chrFirstData; 
	gstrSecondData=GetData.chrSecondData;
	gstrThirdData=GetData.chrThirdData;
	gstrFourthData=GetData.chrFourthData;
	::PostMessage(dlg->m_hWnd,ONGetData,0,0);
	CSocket::OnReceive(nErrorCode);
}

void CDataSocket::OnClose(int nErrorCode) //§PÂ_«È¤áºÝÂ÷½u
{
	// TODO: Add your specialized code here and/or call the base class
	AfxMessageBox("Get Close Message");
	CSocket::OnClose(nErrorCode);
}
