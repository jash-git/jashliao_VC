// Moniter_Set_On_OFFDlg.h : header file
//

#if !defined(AFX_MONITER_SET_ON_OFFDLG_H__131BE2D3_A211_4E4B_BD5F_7FDCB8656E74__INCLUDED_)
#define AFX_MONITER_SET_ON_OFFDLG_H__131BE2D3_A211_4E4B_BD5F_7FDCB8656E74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMoniter_Set_On_OFFDlg dialog

class CMoniter_Set_On_OFFDlg : public CDialog
{
// Construction
public:
	CMoniter_Set_On_OFFDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMoniter_Set_On_OFFDlg)
	enum { IDD = IDD_MONITER_SET_ON_OFF_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMoniter_Set_On_OFFDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMoniter_Set_On_OFFDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTurnoff();
	afx_msg void OnTurnon();
	afx_msg void OnLowpower();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONITER_SET_ON_OFFDLG_H__131BE2D3_A211_4E4B_BD5F_7FDCB8656E74__INCLUDED_)
