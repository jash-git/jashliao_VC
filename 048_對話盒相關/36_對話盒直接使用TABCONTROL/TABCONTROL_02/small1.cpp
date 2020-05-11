// small1.cpp : implementation file
//

#include "stdafx.h"
#include "TABCONTROL.h"
#include "small1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Csmall1 property page

IMPLEMENT_DYNCREATE(Csmall1, CPropertyPage)

Csmall1::Csmall1() : CPropertyPage(Csmall1::IDD)
{
	//{{AFX_DATA_INIT(Csmall1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

Csmall1::~Csmall1()
{
}

void Csmall1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Csmall1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Csmall1, CPropertyPage)
	//{{AFX_MSG_MAP(Csmall1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Csmall1 message handlers

void Csmall1::OnButton1() 
{
	// TODO: Add your control notification handler code here
	MessageBox("Csmall1");
}
