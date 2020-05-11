// testGetWebPictureDlg.h : header file
//

#if !defined(AFX_TESTGETWEBPICTUREDLG_H__E2542488_54D0_4B71_8CAF_620BD742077D__INCLUDED_)
#define AFX_TESTGETWEBPICTUREDLG_H__E2542488_54D0_4B71_8CAF_620BD742077D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestGetWebPictureDlg dialog

class CTestGetWebPictureDlg : public CDialog
{
// Construction
public:
	CTestGetWebPictureDlg(CWnd* pParent = NULL);	// standard constructor
	BOOL GetSourceHtml(CString theUrl,CString Filename);
// Dialog Data
	//{{AFX_DATA(CTestGetWebPictureDlg)
	enum { IDD = IDD_TESTGETWEBPICTURE_DIALOG };
	CString	m_V1;
	CString	m_V2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestGetWebPictureDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestGetWebPictureDlg)
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

#endif // !defined(AFX_TESTGETWEBPICTUREDLG_H__E2542488_54D0_4B71_8CAF_620BD742077D__INCLUDED_)
