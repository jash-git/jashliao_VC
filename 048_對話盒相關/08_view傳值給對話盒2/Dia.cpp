// Dia.cpp : implementation file
//

#include "stdafx.h"
#include "TEST.h"
#include "Dia.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDia dialog


CDia::CDia(CWnd* pParent /*=NULL*/)
	: CDialog(CDia::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDia)
	m_v1 = 0;
	//}}AFX_DATA_INIT
}


void CDia::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDia)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDia, CDialog)
	//{{AFX_MSG_MAP(CDia)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDia message handlers

void CDia::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_v1+=1;
	UpdateData(false);
}
void CDia::show(int a)
{
	m_v1=a;
}
