// Call Control_RunDLLDlg.h : header file
//

#if !defined(AFX_CALLCONTROL_RUNDLLDLG_H__D119A885_07AF_41F0_A630_B96047B547BB__INCLUDED_)
#define AFX_CALLCONTROL_RUNDLLDLG_H__D119A885_07AF_41F0_A630_B96047B547BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCallControl_RunDLLDlg dialog

class CCallControl_RunDLLDlg : public CDialog
{
// Construction
public:
	CCallControl_RunDLLDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCallControl_RunDLLDlg)
	enum { IDD = IDD_CALLCONTROL_RUNDLL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCallControl_RunDLLDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCallControl_RunDLLDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALLCONTROL_RUNDLLDLG_H__D119A885_07AF_41F0_A630_B96047B547BB__INCLUDED_)
