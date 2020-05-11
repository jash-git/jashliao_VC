// forview.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "forview.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// forview

IMPLEMENT_DYNCREATE(forview, CFormView)

forview::forview()
	: CFormView(forview::IDD)
{
	//{{AFX_DATA_INIT(forview)
	m_v1 = 0;
	//}}AFX_DATA_INIT
}

forview::~forview()
{
}

void forview::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(forview)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(forview, CFormView)
	//{{AFX_MSG_MAP(forview)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// forview diagnostics

#ifdef _DEBUG
void forview::AssertValid() const
{
	CFormView::AssertValid();
}

void forview::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// forview message handlers

void forview::OnButton1() 
{
	// TODO: Add your control notification handler code here
UpdateData(true);
m_v1+=1;
CMainFrame *mf=(CMainFrame *)AfxGetMainWnd();
mf->draw_value(m_v1); 
CButton *pButton=(CButton *)this->GetDlgItem( IDC_BUTTON1);
pButton->EnableWindow(false); 
UpdateData(false);	
}
