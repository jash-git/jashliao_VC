// Dlg2.cpp : implementation file
//

#include "stdafx.h"
#include "Dlg.h"
#include "Dlg2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg2 dialog


CDlg2::CDlg2(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg2)
	m_value = 0.0;
	//}}AFX_DATA_INIT
}


void CDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg2)
	DDX_Text(pDX, IDC_EDIT1, m_value);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg2, CDialog)
	//{{AFX_MSG_MAP(CDlg2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg2 message handlers

void CDlg2::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_value+=100;
	UpdateData(false);
}
void CDlg2::setvalue(double a)
{
	m_value=a;
}