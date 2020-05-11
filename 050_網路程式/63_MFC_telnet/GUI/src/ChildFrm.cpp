// ChildFrm.cpp : implementation of the CChildFrame class
//
#include "stdafx.h"
#include "Telnet.h"

#include "ChildFrm.h"
#include ".\childfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
        ON_UPDATE_COMMAND_UI(ID_PANE1, OnPane1)
        ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] = {
        ID_PANE1,
};

// CChildFrame construction/destruction

CChildFrame::CChildFrame()
                : m_pane1(_T("Offline."))
{
        // TODO: add member initialization code here
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
        // TODO: Modify the Window class or styles here by modifying the CREATESTRUCT cs
        if (!CMDIChildWnd::PreCreateWindow(cs))
                return FALSE;

        return TRUE;
}


// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
        CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
        CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG


// CChildFrame message handlers

int CChildFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
        if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
                return -1;

        if (!m_wndStatusBar.Create(this) ||	!m_wndStatusBar.SetIndicators(indicators,
                        sizeof(indicators) / sizeof(UINT))) {
                TRACE0("Failed to create status bar\n");
                return -1;      // fail to create
        }
        m_wndStatusBar.SetPaneStyle(0, SBPS_STRETCH | SBPS_NOBORDERS);


        return 0;
}

void CChildFrame::OnPane1(CCmdUI* pCmdUI)
{
        pCmdUI->Enable();
        pCmdUI->SetText(m_pane1);
}
