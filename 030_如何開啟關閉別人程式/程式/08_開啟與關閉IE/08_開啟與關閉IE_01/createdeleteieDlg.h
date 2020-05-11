// createdeleteieDlg.h : header file
//

#if !defined(AFX_CREATEDELETEIEDLG_H__2EBADC07_ADCA_441E_9E08_70B3CBD91EBE__INCLUDED_)
#define AFX_CREATEDELETEIEDLG_H__2EBADC07_ADCA_441E_9E08_70B3CBD91EBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreatedeleteieDlg dialog

class CCreatedeleteieDlg : public CDialog
{
// Construction
public:
	CCreatedeleteieDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCreatedeleteieDlg)
	enum { IDD = IDD_CREATEDELETEIE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreatedeleteieDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreatedeleteieDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEDELETEIEDLG_H__2EBADC07_ADCA_441E_9E08_70B3CBD91EBE__INCLUDED_)
