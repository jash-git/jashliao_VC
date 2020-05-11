// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__2969ECE6_2BD8_4CF2_9D1C_F3364932D7EE__INCLUDED_)
#define AFX_MAINFRM_H__2969ECE6_2BD8_4CF2_9D1C_F3364932D7EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	//}}AFX_VIRTUAL

protected:  // control bar embedded members
	CStatusBar m_wndStatusBar;
	CToolBar   m_wndToolBar;
	CReBar     m_wndReBar;
	CDialogBar m_wndDlgBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__2969ECE6_2BD8_4CF2_9D1C_F3364932D7EE__INCLUDED_)
