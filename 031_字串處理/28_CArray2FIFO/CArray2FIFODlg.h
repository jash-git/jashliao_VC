// CArray2FIFODlg.h : header file
//

#if !defined(AFX_CARRAY2FIFODLG_H__201B9373_31B4_4F4F_AADD_64A5F54F064F__INCLUDED_)
#define AFX_CARRAY2FIFODLG_H__201B9373_31B4_4F4F_AADD_64A5F54F064F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCArray2FIFODlg dialog

class CCArray2FIFODlg : public CDialog
{
// Construction
public:
	CCArray2FIFODlg(CWnd* pParent = NULL);	// standard constructor
	CArray <CString,CString&> m_ArrayData;	//CArray Step_02
	int m_intArrayCount;
// Dialog Data
	//{{AFX_DATA(CCArray2FIFODlg)
	enum { IDD = IDD_CARRAY2FIFO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCArray2FIFODlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCArray2FIFODlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnIN1();
	afx_msg void OnDel1();
	afx_msg void OnIN2();
	afx_msg void OnShow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARRAY2FIFODLG_H__201B9373_31B4_4F4F_AADD_64A5F54F064F__INCLUDED_)
