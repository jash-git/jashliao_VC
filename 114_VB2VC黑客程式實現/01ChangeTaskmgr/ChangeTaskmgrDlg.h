// ChangeTaskmgrDlg.h : header file
//

#if !defined(AFX_CHANGETASKMGRDLG_H__46C45A01_DDE1_48AF_A479_83FA55368EE7__INCLUDED_)
#define AFX_CHANGETASKMGRDLG_H__46C45A01_DDE1_48AF_A479_83FA55368EE7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChangeTaskmgrDlg dialog

class CChangeTaskmgrDlg : public CDialog
{
// Construction
public:
	CChangeTaskmgrDlg(CWnd* pParent = NULL);	// standard constructor
	CString GetAPPEXEPath();//取得目前程式所在完整路徑檔名
	CString FullPath2FileName(CString StrPath);//從全路徑取得檔名
// Dialog Data
	//{{AFX_DATA(CChangeTaskmgrDlg)
	enum { IDD = IDD_CHANGETASKMGR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeTaskmgrDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChangeTaskmgrDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRun();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGETASKMGRDLG_H__46C45A01_DDE1_48AF_A479_83FA55368EE7__INCLUDED_)
