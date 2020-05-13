// ChangeDesktopDlg.h : header file
//

#if !defined(AFX_CHANGEDESKTOPDLG_H__D3C93E82_2DE5_4192_A298_124BD80355F9__INCLUDED_)
#define AFX_CHANGEDESKTOPDLG_H__D3C93E82_2DE5_4192_A298_124BD80355F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChangeDesktopDlg dialog

class CChangeDesktopDlg : public CDialog
{
// Construction
public:
	CChangeDesktopDlg(CWnd* pParent = NULL);	// standard constructor
	CArray <CString,CString&> m_Array;//Step 2:CArray
	void BrowseDir(CString strDir);//Step 2:列出檔案清單
	bool GetandSetParameter();//step 3:讀取XML
	void SaveParameter();//step 6:讀取XML
	void CreateXMLParameter();//step 5:讀取XML
	int m_intCount;
	bool m_blnOnTimer;
// Dialog Data
	//{{AFX_DATA(CChangeDesktopDlg)
	enum { IDD = IDD_CHANGEDESKTOP_DIALOG };
	UINT	m_ALL;
	UINT	m_NOW;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeDesktopDlg)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChangeDesktopDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHide();
	afx_msg LRESULT onShowTask(WPARAM wParam,LPARAM lParam); //Step 4:ICON
	afx_msg void OnRun();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSetShow();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnNextPage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEDESKTOPDLG_H__D3C93E82_2DE5_4192_A298_124BD80355F9__INCLUDED_)
