// Create_Unicode_FileDlg.h : header file
//

#if !defined(AFX_CREATE_UNICODE_FILEDLG_H__9D426B3D_72DD_433F_90FF_B32176FBACB3__INCLUDED_)
#define AFX_CREATE_UNICODE_FILEDLG_H__9D426B3D_72DD_433F_90FF_B32176FBACB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCreate_Unicode_FileDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CCreate_Unicode_FileDlg dialog

class CCreate_Unicode_FileDlg : public CDialog
{
	DECLARE_DYNAMIC(CCreate_Unicode_FileDlg);
	friend class CCreate_Unicode_FileDlgAutoProxy;

// Construction
public:
	CCreate_Unicode_FileDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CCreate_Unicode_FileDlg();

// Dialog Data
	//{{AFX_DATA(CCreate_Unicode_FileDlg)
	enum { IDD = IDD_CREATE_UNICODE_FILE_DIALOG };
	int		m_v1;
	int		m_v2;
	int		m_v3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreate_Unicode_FileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CCreate_Unicode_FileDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CCreate_Unicode_FileDlg)
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

#endif // !defined(AFX_CREATE_UNICODE_FILEDLG_H__9D426B3D_72DD_433F_90FF_B32176FBACB3__INCLUDED_)
