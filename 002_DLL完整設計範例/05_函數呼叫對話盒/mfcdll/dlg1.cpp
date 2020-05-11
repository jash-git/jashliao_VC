// dlg1.cpp : implementation file
//

#include "stdafx.h"
#include "mfcdll.h"
#include "dlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// dlg1 dialog


dlg1::dlg1(CWnd* pParent /*=NULL*/)
	: CDialog(dlg1::IDD, pParent)
{
	//{{AFX_DATA_INIT(dlg1)
	m_v1 = 0;
	//}}AFX_DATA_INIT
}


void dlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(dlg1)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(dlg1, CDialog)
	//{{AFX_MSG_MAP(dlg1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// dlg1 message handlers

void dlg1::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
		m_v1++;
	UpdateData(false);
}
