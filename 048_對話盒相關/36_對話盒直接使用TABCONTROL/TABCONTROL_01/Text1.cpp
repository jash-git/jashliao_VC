// Text1.cpp : implementation file
//

#include "stdafx.h"
#include "TABCONTROL.h"
#include "Text1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CText1 property page

IMPLEMENT_DYNCREATE(CText1, CPropertyPage)

CText1::CText1() : CPropertyPage(CText1::IDD)
{
	//{{AFX_DATA_INIT(CText1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CText1::~CText1()
{
}

void CText1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CText1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CText1, CPropertyPage)
	//{{AFX_MSG_MAP(CText1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CText1 message handlers

void CText1::OnButton1() 
{
	// TODO: Add your control notification handler code here
	MessageBox("CText1");
}
