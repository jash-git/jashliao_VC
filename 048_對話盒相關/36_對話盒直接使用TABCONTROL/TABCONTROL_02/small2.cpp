// small2.cpp : implementation file
//

#include "stdafx.h"
#include "TABCONTROL.h"
#include "small2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Csmall2 property page

IMPLEMENT_DYNCREATE(Csmall2, CPropertyPage)

Csmall2::Csmall2() : CPropertyPage(Csmall2::IDD)
{
	//{{AFX_DATA_INIT(Csmall2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

Csmall2::~Csmall2()
{
}

void Csmall2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Csmall2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Csmall2, CPropertyPage)
	//{{AFX_MSG_MAP(Csmall2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Csmall2 message handlers

void Csmall2::OnButton1() 
{
	// TODO: Add your control notification handler code here
	MessageBox("Csmall2");
}
