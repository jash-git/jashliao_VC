// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "menu.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_menu1, OnUpdatemenu1)
	ON_UPDATE_COMMAND_UI(iD_menu2, OnUpdatemenu2)
	ON_COMMAND(ID_test1, Ontest1)
	ON_COMMAND(ID_test2, Ontest2)
	ON_COMMAND(ID_test3, Ontest3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	this->m_bAutoMenuEnable = false;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnUpdatemenu1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	MessageBox("menu1");
}

void CMainFrame::OnUpdatemenu2(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	MessageBox("menu2");
}

void CMainFrame::Ontest1() 
{
	// TODO: Add your command handler code here
	MessageBox("test1");
}

void CMainFrame::Ontest2() 
{
	// TODO: Add your command handler code here
	//HMENU EditMenu = GetMenu()->GetSafeHmenu();
    //::EnableMenuItem(EditMenu, ID_test1, MF_DISABLED);
	CMenu *pMenu = GetMenu();
	pMenu->EnableMenuItem(ID_test1,MF_BYCOMMAND|MF_DISABLED|MF_GRAYED);
	
}

void CMainFrame::Ontest3() 
{
	// TODO: Add your command handler code here
	CMenu *pMenu = GetMenu();
	pMenu->EnableMenuItem(ID_test1,MF_BYCOMMAND|MF_ENABLED);

}
