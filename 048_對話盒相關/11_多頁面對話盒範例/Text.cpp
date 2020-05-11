// Text.cpp : implementation file
//

#include "stdafx.h"
#include "Tab.h"
#include "Text.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CText property page

IMPLEMENT_DYNCREATE(CText, CPropertyPage)

CText::CText() : CPropertyPage(CText::IDD)
{
	//{{AFX_DATA_INIT(CText)
	m_v1 = 0.0;
	//}}AFX_DATA_INIT
}

CText::~CText()
{
}

void CText::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CText)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CText, CPropertyPage)
	//{{AFX_MSG_MAP(CText)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CText message handlers

void CText::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
		m_v1++;
	UpdateData(false);	
}
