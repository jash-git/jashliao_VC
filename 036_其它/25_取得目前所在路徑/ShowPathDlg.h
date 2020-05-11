// ShowPathDlg.h : header file
//

#if !defined(AFX_SHOWPATHDLG_H__2E254FB7_F63A_44C5_9ECB_1FDF5EDE3D44__INCLUDED_)
#define AFX_SHOWPATHDLG_H__2E254FB7_F63A_44C5_9ECB_1FDF5EDE3D44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShowPathDlg dialog

class CShowPathDlg : public CDialog
{
// Construction
public:
	CShowPathDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CShowPathDlg)
	enum { IDD = IDD_SHOWPATH_DIALOG };
	CString	m_S1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowPathDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShowPathDlg)
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

#endif // !defined(AFX_SHOWPATHDLG_H__2E254FB7_F63A_44C5_9ECB_1FDF5EDE3D44__INCLUDED_)
