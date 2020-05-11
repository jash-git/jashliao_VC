// Text3.cpp : implementation file
//

#include "stdafx.h"
#include "TABCONTROL.h"
#include "Text3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CText3 property page

IMPLEMENT_DYNCREATE(CText3, CPropertyPage)

CText3::CText3() : CPropertyPage(CText3::IDD)
{
	//{{AFX_DATA_INIT(CText3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CText3::~CText3()
{
}

void CText3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CText3)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CText3, CPropertyPage)
	//{{AFX_MSG_MAP(CText3)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CText3 message handlers

void CText3::OnButton1() 
{
	// TODO: Add your control notification handler code here
	MessageBox("CText3");
}
