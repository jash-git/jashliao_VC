// bmp2pdfDlg.h : header file
//

#if !defined(AFX_BMP2PDFDLG_H__2E64BBDD_EAA0_485E_95FB_EF3BE7ABAA1F__INCLUDED_)
#define AFX_BMP2PDFDLG_H__2E64BBDD_EAA0_485E_95FB_EF3BE7ABAA1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBmp2pdfDlg dialog

class CBmp2pdfDlg : public CDialog
{
// Construction
public:
	CBmp2pdfDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBmp2pdfDlg)
	enum { IDD = IDD_BMP2PDF_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmp2pdfDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBmp2pdfDlg)
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

#endif // !defined(AFX_BMP2PDFDLG_H__2E64BBDD_EAA0_485E_95FB_EF3BE7ABAA1F__INCLUDED_)
