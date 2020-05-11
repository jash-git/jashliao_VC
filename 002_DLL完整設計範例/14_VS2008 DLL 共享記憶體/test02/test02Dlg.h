// test02Dlg.h : header file
//

#if !defined(AFX_TEST02DLG_H__AE7A7130_59AA_4F5A_B15A_4856D3E16B10__INCLUDED_)
#define AFX_TEST02DLG_H__AE7A7130_59AA_4F5A_B15A_4856D3E16B10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest02Dlg dialog

class CTest02Dlg : public CDialog
{
// Construction
public:
	CTest02Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest02Dlg)
	enum { IDD = IDD_TEST02_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest02Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest02Dlg)
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

#endif // !defined(AFX_TEST02DLG_H__AE7A7130_59AA_4F5A_B15A_4856D3E16B10__INCLUDED_)
