// tes.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "tes.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// tes dialog


tes::tes(CWnd* pParent /*=NULL*/)
	: CDialog(tes::IDD, pParent)
{
	//{{AFX_DATA_INIT(tes)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void tes::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(tes)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(tes, CDialog)
	//{{AFX_MSG_MAP(tes)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// tes message handlers

void tes::OnButton1() 
{
	// TODO: Add your control notification handler code here
	pr->ShowWindow(SW_SHOWNORMAL);
	////////////////////////
	//this->EndDialog(0);
	this->OnOK();
}
void tes::getdata(CTestDlg *k)
{
	pr=k;
}
