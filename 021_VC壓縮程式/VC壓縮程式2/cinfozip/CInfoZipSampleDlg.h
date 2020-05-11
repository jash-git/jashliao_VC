// CInfoZipSampleDlg.h : header file
//

#if !defined(AFX_CINFOZIPSAMPLEDLG_H__0CA4A9F9_3A87_11D3_ABFD_00A0C9B4D8AB__INCLUDED_)
#define AFX_CINFOZIPSAMPLEDLG_H__0CA4A9F9_3A87_11D3_ABFD_00A0C9B4D8AB__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CCInfoZipSampleDlg dialog

class CCInfoZipSampleDlg : public CDialog
{
// Construction
public:
	CCInfoZipSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCInfoZipSampleDlg)
	enum { IDD = IDD_CINFOZIPSAMPLE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCInfoZipSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCInfoZipSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CINFOZIPSAMPLEDLG_H__0CA4A9F9_3A87_11D3_ABFD_00A0C9B4D8AB__INCLUDED_)
