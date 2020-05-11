// thread6Dlg.h : header file
//

#if !defined(AFX_THREAD6DLG_H__6F149406_2FFA_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_THREAD6DLG_H__6F149406_2FFA_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CThread6Dlg dialog

class CThread6Dlg : public CDialog
{
// Construction
public:
	CThread6Dlg(CWnd* pParent = NULL);	// standard constructor
	afx_msg void clearvalue();
	afx_msg void OnButton2();
// Dialog Data
	//{{AFX_DATA(CThread6Dlg)
	enum { IDD = IDD_THREAD6_DIALOG };
	float	m_v1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThread6Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CThread6Dlg)
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

#endif // !defined(AFX_THREAD6DLG_H__6F149406_2FFA_11DA_B776_0040F43A9B72__INCLUDED_)
