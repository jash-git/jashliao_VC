// Command.cpp : implementation file
//

#include "stdafx.h"
#include "Tab.h"
#include "Command.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCommand property page

IMPLEMENT_DYNCREATE(CCommand, CPropertyPage)

CCommand::CCommand() : CPropertyPage(CCommand::IDD)
{
	//{{AFX_DATA_INIT(CCommand)
	m_v1 = 0.0;
	//}}AFX_DATA_INIT
}

CCommand::~CCommand()
{
}

void CCommand::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCommand)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCommand, CPropertyPage)
	//{{AFX_MSG_MAP(CCommand)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCommand message handlers

void CCommand::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
		m_v1++;
	UpdateData(false);
}
