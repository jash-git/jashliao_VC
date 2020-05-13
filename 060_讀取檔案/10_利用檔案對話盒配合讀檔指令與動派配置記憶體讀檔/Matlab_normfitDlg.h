// Matlab_normfitDlg.h : header file
//

#if !defined(AFX_MATLAB_NORMFITDLG_H__70088394_1C7A_40E4_ABE2_E2E8FCCB4D92__INCLUDED_)
#define AFX_MATLAB_NORMFITDLG_H__70088394_1C7A_40E4_ABE2_E2E8FCCB4D92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMatlab_normfitDlg dialog

class CMatlab_normfitDlg : public CDialog
{
// Construction
public:
	CMatlab_normfitDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMatlab_normfitDlg)
	enum { IDD = IDD_MATLAB_NORMFIT_DIALOG };
	double	m_douMean;
	double	m_douSigma;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMatlab_normfitDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMatlab_normfitDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnClose();
	virtual void OnOK();
	afx_msg void OnDestroy();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MATLAB_NORMFITDLG_H__70088394_1C7A_40E4_ABE2_E2E8FCCB4D92__INCLUDED_)
