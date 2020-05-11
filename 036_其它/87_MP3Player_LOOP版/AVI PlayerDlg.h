// AVI PlayerDlg.h : header file
//

#if !defined(AFX_AVIPLAYERDLG_H__F88E8973_5775_4DC0_ADFD_E821627A0F71__INCLUDED_)
#define AFX_AVIPLAYERDLG_H__F88E8973_5775_4DC0_ADFD_E821627A0F71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAVIPlayerDlg dialog

class CAVIPlayerDlg : public CDialog
{
// Construction
public:
	CAVIPlayerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAVIPlayerDlg)
	enum { IDD = IDD_AVIPLAYER_DIALOG };
	CButton	m_Play;
	CButton	m_Pause;
	CString	m_Path;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAVIPlayerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAVIPlayerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPlay();
	afx_msg void OnPause();
	virtual void OnCancel();
	afx_msg void OnStop();
	afx_msg void OnBrowse();
	afx_msg void OnMCINotify(WPARAM   wParam,LPARAM   lParam); 
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HWND m_Video;
	BOOL Pause;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVIPLAYERDLG_H__F88E8973_5775_4DC0_ADFD_E821627A0F71__INCLUDED_)
