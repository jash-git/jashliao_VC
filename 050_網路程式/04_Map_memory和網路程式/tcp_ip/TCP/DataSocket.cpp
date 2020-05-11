// DataSocket.cpp : implementation file
//

#include "stdafx.h"
#include "TCP.h"
#include "DataSocket.h"
//////////////////////////
#include "ListenSocket.h"
#include "TCPDlg.h"
/////////////////////////
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
struct Net_Data
{
	int a;
	float b;
};
///////////////////////////////////////////////
#define	MAP_NAME	"spacesoft corp."
#define	MAP_LENGTH	1024
HANDLE hFileMap = NULL ;
static char szOldData[MAP_LENGTH] = "" ;
//////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// DataSocket

DataSocket::DataSocket()
{
	hFileMap = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME ) ;
}

DataSocket::~DataSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(DataSocket, CSocket)
	//{{AFX_MSG_MAP(DataSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// DataSocket member functions

void DataSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	//char buf[255];
	//memset(buf,'\0',sizeof(buf));
	struct Net_Data data1;
	int a;
	a=sizeof(data1.a)+sizeof(data1.b);
	Receive(&data1,a,0);
	((CTCPDlg*)AfxGetMainWnd())->m_st1="ok!!!!!!!!!";
	((CTCPDlg*)AfxGetMainWnd())->m_v1=data1.a;
	((CTCPDlg*)AfxGetMainWnd())->m_v2=data1.b;
	((CTCPDlg*)AfxGetMainWnd())->UpdateData(FALSE);
	//////////////////////////////////////////////
	LPVOID mapView = MapViewOfFile( hFileMap,FILE_MAP_WRITE, 0, 0, 0 ) ;
	if( mapView != NULL ) 
	{
		((CTCPDlg*)AfxGetMainWnd())->GetDlgItemText( IDC_EDIT2,(LPTSTR)mapView, MAP_LENGTH ) ;
		//GetDlgItemText( IDC_EDIT2,(LPTSTR)mapView, MAP_LENGTH ) ;
		UnmapViewOfFile( (LPVOID)mapView);
	} 
	else 
	{
		((CTCPDlg*)AfxGetMainWnd())->MessageBox("mMapViewOfFile¥¢±Ñ¡C");
		
	}
	//////////////////////////////////////////////
	CSocket::OnReceive(nErrorCode);
}
