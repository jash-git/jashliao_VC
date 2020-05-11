// dlg2.cpp : implementation file
//

#include "stdafx.h"
#include "dlg.h"
#include "dlg2.h"
#include "ExtenalVarDlg2dlg2.h"
//#include "GobalVarDlg2dlg2.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// dlg2 dialog


dlg2::dlg2(CWnd* pParent /*=NULL*/)
	: CDialog(dlg2::IDD, pParent)
{
	//{{AFX_DATA_INIT(dlg2)
	m_v1 = 0;
	//}}AFX_DATA_INIT
}


void dlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(dlg2)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(dlg2, CDialog)
	//{{AFX_MSG_MAP(dlg2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// dlg2 message handlers

void dlg2::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_v1++;
	UpdateData(false);
}
void dlg2::getval(CDlgDlg *a)
{
	//m_v1=a->m_v1;
	m_v1=gv2;
}