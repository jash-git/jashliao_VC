// Show1Dlg.h : header file
//

#if !defined(AFX_SHOW1DLG_H__144531F4_B7E3_4EA6_ADB7_4FD951DF6C38__INCLUDED_)
#define AFX_SHOW1DLG_H__144531F4_B7E3_4EA6_ADB7_4FD951DF6C38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShow1Dlg dialog

class CShow1Dlg : public CDialog
{
// Construction
public:
	CShow1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CShow1Dlg)
	enum { IDD = IDD_SHOW1_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShow1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShow1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOW1DLG_H__144531F4_B7E3_4EA6_ADB7_4FD951DF6C38__INCLUDED_)
