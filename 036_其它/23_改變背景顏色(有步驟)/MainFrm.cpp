// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "ServerGetData.h"

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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
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
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
////////////////////////////////第一步
//掛載TOOLBAR和狀態列
/*		
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
//*/
//////////////////////////////////////////////////////
/////////////////////////////////////////////第二步
	this->SetMenu(NULL);//隱藏菜單
	this->DrawMenuBar();//重繪菜單
/////////////////////////////////////////////////////
///*
//////////////////////////////////////第三步
	long style=GetWindowLong(m_hWnd,GWL_STYLE);
	//style&=~WS_SYSMENU;//去除系統按鈕
	style&=~WS_CAPTION;//去除標題列
	SetWindowLong(m_hWnd,GWL_STYLE,style);
	SetWindowPos(NULL,0,0,1024,800,SWP_NOZORDER);
////////////////////////////////////
//*/
///*
///////////////////////////第四步
	/////變成橢圓
	FILE *pf;//讀取框架外部設定
	int intParameter[8]={0,0,0,0,0,0,0,0};
	int i=0;
	pf=fopen("WebFrm.par","r");
	CRect rcDialog;
	GetClientRect (rcDialog );
	if (pf==NULL)
	{
		SetWindowPos(NULL,-13,367,rcDialog.right,rcDialog.bottom,SWP_NOZORDER);
		rcDialog.top+=5;
		rcDialog.bottom-=188;
		rcDialog.left+=5;
		rcDialog.right-=426;
	}
	else
	{
		for(i=0;i<8;i++)
			fscanf(pf,"%d",&intParameter[i]);
		SetWindowPos(NULL,intParameter[0],intParameter[1],rcDialog.right,rcDialog.bottom,SWP_NOZORDER);
		rcDialog.top+=intParameter[2];
		rcDialog.bottom-=intParameter[3];
		rcDialog.left+=intParameter[4];
		rcDialog.right-=intParameter[5];
		//intStartTime=intParameter[6];
		//intEndTime=intParameter[7];
	}
	m_rgn.CreateRectRgnIndirect(&rcDialog);
	::SetWindowRgn(GetSafeHwnd(),(HRGN)m_rgn,TRUE);	
/////////////////////
//*/
///////////////////////////////////第五步
	/* //透明程式碼
	SetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE,
		GetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE)^0x80000);
	HINSTANCE hInst = LoadLibrary("User32.DLL"); 
	if(hInst) 
	{ 
		typedef BOOL (WINAPI *MYFUNC)(HWND,COLORREF,BYTE,DWORD); 
		MYFUNC fun = NULL;
		fun=(MYFUNC)GetProcAddress(hInst, "SetLayeredWindowAttributes");
		if(fun)fun(this->GetSafeHwnd(),0,200,2); 
		FreeLibrary(hInst); 
	}
	//*/
//////////////////////////////////////
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

