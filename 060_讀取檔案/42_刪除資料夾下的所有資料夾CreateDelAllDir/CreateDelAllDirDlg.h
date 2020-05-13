// CreateDelAllDirDlg.h : header file
//

#if !defined(AFX_CREATEDELALLDIRDLG_H__DB397383_16CB_40AB_8BEB_22D766B439DF__INCLUDED_)
#define AFX_CREATEDELALLDIRDLG_H__DB397383_16CB_40AB_8BEB_22D766B439DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCreateDelAllDirDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CCreateDelAllDirDlg dialog

class CCreateDelAllDirDlg : public CDialog
{
	DECLARE_DYNAMIC(CCreateDelAllDirDlg);
	friend class CCreateDelAllDirDlgAutoProxy;

// Construction
public:
	CCreateDelAllDirDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CCreateDelAllDirDlg();

// Dialog Data
	//{{AFX_DATA(CCreateDelAllDirDlg)
	enum { IDD = IDD_CREATEDELALLDIR_DIALOG };
	CString	m_v1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateDelAllDirDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CCreateDelAllDirDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CCreateDelAllDirDlg)
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

#endif // !defined(AFX_CREATEDELALLDIRDLG_H__DB397383_16CB_40AB_8BEB_22D766B439DF__INCLUDED_)
