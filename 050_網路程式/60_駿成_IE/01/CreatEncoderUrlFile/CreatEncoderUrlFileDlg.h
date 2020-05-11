// CreatEncoderUrlFileDlg.h : header file
//

#if !defined(AFX_CREATENCODERURLFILEDLG_H__8D668775_14C7_48A6_9AE4_344EFE3EEEFA__INCLUDED_)
#define AFX_CREATENCODERURLFILEDLG_H__8D668775_14C7_48A6_9AE4_344EFE3EEEFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreatEncoderUrlFileDlg dialog

class CCreatEncoderUrlFileDlg : public CDialog
{
// Construction
public:
	CCreatEncoderUrlFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCreatEncoderUrlFileDlg)
	enum { IDD = IDD_CREATENCODERURLFILE_DIALOG };
	CString	m_V1;
	CString	m_V2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreatEncoderUrlFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreatEncoderUrlFileDlg)
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

#endif // !defined(AFX_CREATENCODERURLFILEDLG_H__8D668775_14C7_48A6_9AE4_344EFE3EEEFA__INCLUDED_)
