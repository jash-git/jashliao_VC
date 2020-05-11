// GetPathAndNameDlg.h : header file
//

#if !defined(AFX_GETPATHANDNAMEDLG_H__B439DA3E_489C_4BAA_878C_10ADC33775DD__INCLUDED_)
#define AFX_GETPATHANDNAMEDLG_H__B439DA3E_489C_4BAA_878C_10ADC33775DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGetPathAndNameDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CGetPathAndNameDlg dialog

class CGetPathAndNameDlg : public CDialog
{
	DECLARE_DYNAMIC(CGetPathAndNameDlg);
	friend class CGetPathAndNameDlgAutoProxy;

// Construction
public:
	CGetPathAndNameDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CGetPathAndNameDlg();

// Dialog Data
	//{{AFX_DATA(CGetPathAndNameDlg)
	enum { IDD = IDD_GETPATHANDNAME_DIALOG };
	CString	m_v1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetPathAndNameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CGetPathAndNameDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CGetPathAndNameDlg)
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

#endif // !defined(AFX_GETPATHANDNAMEDLG_H__B439DA3E_489C_4BAA_878C_10ADC33775DD__INCLUDED_)
