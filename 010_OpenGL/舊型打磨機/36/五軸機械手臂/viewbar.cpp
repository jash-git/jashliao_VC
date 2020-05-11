// viewbar.cpp : implementation file
//

#include "stdafx.h"
#include "kk1.h"
#include "viewbar.h"

#include "view1.h"
#include "kk1Doc.h"
#include "kk1View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CMainFrame *CMainFrame1;
//CKk1View *CKk1View1;
/////////////////////////////////////////////////////////////////////////////
// viewbar dialog


void viewbar::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(viewbar)
	DDX_Text(pDX, IDC_EDIT1, m_setvalue);
	DDX_Text(pDX, IDC_EDIT2, m_trackingvalue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(viewbar, CDialogBar)
	//{{AFX_MSG_MAP(viewbar)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// viewbar message handlers
/*
BOOL viewbar::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::Create(IDD, pParentWnd);
}
*/
void viewbar::Show(void)
{
	//MessageBox("viewbar::Show");
	CMainFrame1=(CMainFrame*)AfxGetMainWnd();
	if(!IsWindow(m_hWnd))
	{
		if(Create(CMainFrame1,IDD_DIALOGBAR,CBRS_LEFT,AFX_IDW_CONTROLBAR_FIRST+32))
		{
			UpdateData(false);
			EnableDocking(CBRS_ALIGN_LEFT);
			CMainFrame1->DockControlBar(this,AFX_IDW_DOCKBAR_LEFT);
			m_setvalue=0;
			m_trackingvalue=0;
			UpdateData(false);
		}
	}
	else
	{
		CMainFrame1->ShowControlBar(this,!IsWindowVisible(),false); 
	}
}
void viewbar::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if((m_setvalue-m_trackingvalue)<=0)
	{
		CMainFrame1->SetTitle("ok"); 
	}
	else
	{
		CMainFrame1->SetTitle("ko");
	}
}
