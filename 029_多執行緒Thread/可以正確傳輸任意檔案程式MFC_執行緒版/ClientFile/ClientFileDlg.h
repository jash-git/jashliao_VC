// ClientFileDlg.h : header file
//

#if !defined(AFX_CLIENTFILEDLG_H__C6A61946_30E1_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_CLIENTFILEDLG_H__C6A61946_30E1_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClientFileDlg dialog

class CClientFileDlg : public CDialog
{
// Construction
public:
	CClientFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CClientFileDlg)
	enum { IDD = IDD_CLIENTFILE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClientFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTFILEDLG_H__C6A61946_30E1_11DA_B776_0040F43A9B72__INCLUDED_)
