// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "mouse.h"
#include "oleidl.h" 

#include "MainFrm.h"
#include "afxmt.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame
POINT mp,cursorNew;
//CEvent threadMoveS,threadShutS,threadSureS;
//CEvent threadMoveE,threadShutE,threadSureE;
IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction
UINT FMouse(LPVOID param){

    WINDOWPLACEMENT wp;///窗口位置
	wp.length=sizeof(WINDOWPLACEMENT);

	HWND hWnd;
	char tmp[20];
    RECT rt;
    int iResult;
	iResult=AfxMessageBox("確實要隱藏嗎？",MB_OKCANCEL);
	if(iResult==IDOK)
	{
	while(1){
		hWnd=GetForegroundWindow();//GetDesktopWindow();
		GetWindowRect(hWnd,&rt);
		GetWindowText(hWnd,tmp,20);
		GetWindowPlacement(hWnd,&wp);
		GetCursorPos(&cursorNew);
			while(1){
			::mouse_event(MOUSEEVENTF_MOVE,cursorNew.x,cursorNew.y,0,0);

			}
	}
	}
	else
	{
	}
	return 0;
}

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	HWND hWnd=::GetParent(NULL);
	GetCursorPos(&mp);
	AfxBeginThread(FMouse,hWnd,0);
	
}

CMainFrame::~CMainFrame()
{
}



BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	
	
    cs.cx=1;
	cs.cy=1;
    cs.lpszName="隐藏程序图标";
	cs.style &= ~(FWS_ADDTOTITLE|WS_MINIMIZEBOX|WS_MAXIMIZEBOX);
	return CFrameWnd::PreCreateWindow(cs);
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

