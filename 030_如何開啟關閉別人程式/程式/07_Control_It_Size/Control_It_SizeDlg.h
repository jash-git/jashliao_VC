// Control_It_SizeDlg.h : header file
//

#if !defined(AFX_CONTROL_IT_SIZEDLG_H__D4CF8638_948E_4A4B_8372_FA591C880ECA__INCLUDED_)
#define AFX_CONTROL_IT_SIZEDLG_H__D4CF8638_948E_4A4B_8372_FA591C880ECA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CControl_It_SizeDlg dialog

class CControl_It_SizeDlg : public CDialog
{
// Construction
public:
	CControl_It_SizeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CControl_It_SizeDlg)
	enum { IDD = IDD_CONTROL_IT_SIZE_DIALOG };
	CString	m_v1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControl_It_SizeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CControl_It_SizeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROL_IT_SIZEDLG_H__D4CF8638_948E_4A4B_8372_FA591C880ECA__INCLUDED_)
