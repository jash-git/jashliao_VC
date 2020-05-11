// Call_GOMDlg.h : header file
//

#if !defined(AFX_CALL_GOMDLG_H__1004F55A_A523_4D9D_A28B_B3AFA826844B__INCLUDED_)
#define AFX_CALL_GOMDLG_H__1004F55A_A523_4D9D_A28B_B3AFA826844B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCall_GOMDlg dialog

class CCall_GOMDlg : public CDialog
{
// Construction
public:
	CCall_GOMDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCall_GOMDlg)
	enum { IDD = IDD_CALL_GOM_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCall_GOMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCall_GOMDlg)
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

#endif // !defined(AFX_CALL_GOMDLG_H__1004F55A_A523_4D9D_A28B_B3AFA826844B__INCLUDED_)
