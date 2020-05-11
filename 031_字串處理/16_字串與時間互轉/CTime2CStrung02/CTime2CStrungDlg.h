// CTime2CStrungDlg.h : header file
//

#if !defined(AFX_CTIME2CSTRUNGDLG_H__F890EF3B_59B8_43BD_9CCB_E131BC6ABD65__INCLUDED_)
#define AFX_CTIME2CSTRUNGDLG_H__F890EF3B_59B8_43BD_9CCB_E131BC6ABD65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCTime2CStrungDlg dialog

class CCTime2CStrungDlg : public CDialog
{
// Construction
public:
	CCTime2CStrungDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCTime2CStrungDlg)
	enum { IDD = IDD_CTIME2CSTRUNG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCTime2CStrungDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCTime2CStrungDlg)
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

#endif // !defined(AFX_CTIME2CSTRUNGDLG_H__F890EF3B_59B8_43BD_9CCB_E131BC6ABD65__INCLUDED_)
