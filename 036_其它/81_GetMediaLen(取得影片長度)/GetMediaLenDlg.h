// GetMediaLenDlg.h : header file
//

#if !defined(AFX_GETMEDIALENDLG_H__23863223_0953_441C_B038_788E01F8073D__INCLUDED_)
#define AFX_GETMEDIALENDLG_H__23863223_0953_441C_B038_788E01F8073D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetMediaLenDlg dialog

class CGetMediaLenDlg : public CDialog
{
// Construction
public:
	CGetMediaLenDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetMediaLenDlg)
	enum { IDD = IDD_GETMEDIALEN_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetMediaLenDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetMediaLenDlg)
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

#endif // !defined(AFX_GETMEDIALENDLG_H__23863223_0953_441C_B038_788E01F8073D__INCLUDED_)
