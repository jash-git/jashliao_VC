// MFC_sscanf_proDlg.h : header file
//

#if !defined(AFX_MFC_SSCANF_PRODLG_H__B386846F_7175_4AE9_8AE7_81E008B03147__INCLUDED_)
#define AFX_MFC_SSCANF_PRODLG_H__B386846F_7175_4AE9_8AE7_81E008B03147__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMFC_sscanf_proDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CMFC_sscanf_proDlg dialog

class CMFC_sscanf_proDlg : public CDialog
{
	DECLARE_DYNAMIC(CMFC_sscanf_proDlg);
	friend class CMFC_sscanf_proDlgAutoProxy;

// Construction
public:
	CMFC_sscanf_proDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CMFC_sscanf_proDlg();

// Dialog Data
	//{{AFX_DATA(CMFC_sscanf_proDlg)
	enum { IDD = IDD_MFC_SSCANF_PRO_DIALOG };
	CString	m_v1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_sscanf_proDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CMFC_sscanf_proDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CMFC_sscanf_proDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_SSCANF_PRODLG_H__B386846F_7175_4AE9_8AE7_81E008B03147__INCLUDED_)
