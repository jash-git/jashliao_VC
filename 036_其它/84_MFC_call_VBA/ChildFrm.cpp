// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "ScriptControlMacro.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CChildFrame)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers

void CChildFrame::OnDestroy() 
{
	//TODO: Add your message handler code here

	// Save last window characteristics in the registry.

	if(theApp.m_pDocManager->GetOpenDocumentCount() == 1)
	{
		WINDOWPLACEMENT wp;

		wp.length = sizeof wp;

		if(GetWindowPlacement(&wp))
		{
			if(wp.showCmd == SW_SHOWMINIMIZED)
			{
				if(wp.flags & WPF_RESTORETOMAXIMIZED)
				{
					wp.flags &= ~WPF_RESTORETOMAXIMIZED;
					wp.showCmd = SW_SHOWMAXIMIZED;
				}
				else wp.showCmd = SW_RESTORE;
			}

			theApp.WriteProfileBinary(_T("Settings"), _T("ChildWndPos"), (BYTE*) &wp, sizeof wp);
		}
	}

	CMDIChildWnd::OnDestroy();
}