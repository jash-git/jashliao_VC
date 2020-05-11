// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "USB_Fram.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
//HOOK
#define ON_0 WM_USER + 500
#define ON_1 WM_USER + 501
#define ON_2 WM_USER + 502
#define ON_3 WM_USER + 503 
#define ON_4 WM_USER + 504 
#define ON_5 WM_USER + 505 
#define ON_6 WM_USER + 506 
#define ON_7 WM_USER + 507 
#define ON_8 WM_USER + 508 
#define ON_9 WM_USER + 509
HINSTANCE hInstLibrary;
typedef void (*SetKeyboardHook)();
typedef void (*ReleaseKeyboardHook)();
SetKeyboardHook _SetKeyboardHook;
ReleaseKeyboardHook _ReleaseKeyboardHook;
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	ON_WM_CREATE()
	ON_MESSAGE(ON_0,On_click0)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

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
	//移除Menu
	SetMenu(NULL);
    ::DestroyMenu(m_hMenuDefault);
	//停用放大
	SetWindowLong(m_hWnd,GWL_STYLE,GetWindowLong(m_hWnd,GWL_STYLE) & ~WS_MAXIMIZEBOX);
	//禁止調整大小
	SetWindowLong(m_hWnd,GWL_STYLE,GetWindowLong(m_hWnd,GWL_STYLE) & ~WS_THICKFRAME);
	//無邊框
	//SetWindowLong(m_hWnd,GWL_STYLE,GetWindowLong(m_hWnd,GWL_STYLE) & WS_EX_STATICEDGE);
	/////////////////////////////////////////////////////
	//HOOK
///*
	hInstLibrary = LoadLibrary("KeybHook.dll");
	if (hInstLibrary == NULL)
	{
		FreeLibrary(hInstLibrary);
	}
	_SetKeyboardHook = (SetKeyboardHook)GetProcAddress(hInstLibrary, "SetKeyboardHook");
	_ReleaseKeyboardHook = (ReleaseKeyboardHook)GetProcAddress(hInstLibrary, "ReleaseKeyboardHook");
	if ((_SetKeyboardHook == NULL) || (_ReleaseKeyboardHook == NULL))
	{
		FreeLibrary(hInstLibrary);
	}
	_SetKeyboardHook();
//*/
	///////////////////////////////////////////////////////////////////	
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
void CMainFrame::On_click0()
{
	MessageBox("本軟體並無提供滑鼠右鍵功能，還請見諒。","Wow TV");
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

