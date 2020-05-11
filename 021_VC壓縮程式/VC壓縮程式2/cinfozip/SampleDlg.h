#if !defined(AFX_SAMPLEDLG_H__0CA4AA02_3A87_11D3_ABFD_00A0C9B4D8AB__INCLUDED_)
#define AFX_SAMPLEDLG_H__0CA4AA02_3A87_11D3_ABFD_00A0C9B4D8AB__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// SampleDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSampleDlg dialog

class CSampleDlg : public CDialog
{
// Construction
public:
	CSampleDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSampleDlg)
	enum { IDD = IDD_SAMPLE_DIALOG };
	CListBox	m_lstFiles;
	CString	m_sArchive;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSampleDlg)
	afx_msg void OnAddFiles();
	afx_msg void OnDeleteFiles();
	afx_msg void OnSelectArchive();
	afx_msg void OnCompress();
	afx_msg void OnExtract();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SAMPLEDLG_H__0CA4AA02_3A87_11D3_ABFD_00A0C9B4D8AB__INCLUDED_)
