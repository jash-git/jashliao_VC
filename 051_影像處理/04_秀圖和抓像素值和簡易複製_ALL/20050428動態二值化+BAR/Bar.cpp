// Bar.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "Bar.h"
#include "MainFrm.h"
#include "testView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CMainFrame *CMainFrame1;
CTestView *view1;
/////////////////////////////////////////////////////////////////////////////
// CBar dialog


CBar::CBar(CWnd* pParent /*=NULL*/)
	: CDialogBar()
{
	//{{AFX_DATA_INIT(CBar)
	m_v1 = 0;
	
	//}}AFX_DATA_INIT
}


void CBar::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBar)
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBar, CDialogBar)
	//{{AFX_MSG_MAP(CBar)
	ON_WM_CREATE()
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBar message handlers
void CBar::show()
{
	CMainFrame1=(CMainFrame*)AfxGetMainWnd();
	if(!IsWindow(m_hWnd))
	{
		if(Create(CMainFrame1,IDD_DIALOGBAR,CBRS_LEFT,AFX_IDW_CONTROLBAR_FIRST+32))
		{
			UpdateData(false);
			EnableDocking(CBRS_ALIGN_LEFT);
			CMainFrame1->DockControlBar(this,AFX_IDW_DOCKBAR_LEFT);
			UpdateData(false);
			//p=fopen("test.txt","w");
		}
	}
	else
	{
		CMainFrame1->ShowControlBar(this,!IsWindowVisible(),false); 
		//fclose(p);
	}
	m_slider.SetRange(0,255);
}

int CBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialogBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}



BOOL CBar::OnInitDialog() 
{
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBar::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CDialogBar::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CBar::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CMainFrame *Frame;
	
	Frame=(CMainFrame*)AfxGetMainWnd();
	view1=(CTestView *)Frame->GetActiveView(); 
	switch(pScrollBar->GetDlgCtrlID())
	{
	case IDC_SLIDER1:
		m_v1=m_slider.GetPos(); 
		
		break;
	}
	UpdateData(false);	
	view1->GetData(m_v1);
	CDialogBar::OnHScroll(nSBCode, nPos, pScrollBar);
}
