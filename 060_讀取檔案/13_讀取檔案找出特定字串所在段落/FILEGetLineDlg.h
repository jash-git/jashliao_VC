// FILEGetLineDlg.h : header file
//

#if !defined(AFX_FILEGETLINEDLG_H__D6E20E81_7121_4FF6_922A_BBAF15C11E1D__INCLUDED_)
#define AFX_FILEGETLINEDLG_H__D6E20E81_7121_4FF6_922A_BBAF15C11E1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFILEGetLineDlg dialog

class CFILEGetLineDlg : public CDialog
{
// Construction
public:
	CFILEGetLineDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFILEGetLineDlg)
	enum { IDD = IDD_FILEGETLINE_DIALOG };
	long	m_v1;
	CString	m_v2;
	CString	m_v3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFILEGetLineDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFILEGetLineDlg)
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

#endif // !defined(AFX_FILEGETLINEDLG_H__D6E20E81_7121_4FF6_922A_BBAF15C11E1D__INCLUDED_)
