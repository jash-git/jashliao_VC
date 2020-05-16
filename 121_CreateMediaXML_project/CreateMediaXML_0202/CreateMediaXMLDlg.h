// CreateMediaXMLDlg.h : header file
//

#if !defined(AFX_CREATEMEDIAXMLDLG_H__580750D8_7D06_4676_8DF9_581EBE98716E__INCLUDED_)
#define AFX_CREATEMEDIAXMLDLG_H__580750D8_7D06_4676_8DF9_581EBE98716E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreateMediaXMLDlg dialog

class CCreateMediaXMLDlg : public CDialog
{
// Construction
public:
	CCreateMediaXMLDlg(CWnd* pParent = NULL);	// standard constructor
	void InitialVariable(void);
	////////////////////////////////////////////////////////////////////
	//Jash.Liao add member variable
	TCHAR m_chrCurDrt[500];//存放目前目錄字串
	CString m_StrInputPath,m_StrOutputPath;
	CString m_StrSettingFileName;
	////////////////////////////////////////////////////////////////////
	CArray <CString,CString&> m_ArrayTitle;//CArray Step
	void BrowseDir(CString strDir);
// Dialog Data
	//{{AFX_DATA(CCreateMediaXMLDlg)
	enum { IDD = IDD_CREATEMEDIAXML_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateMediaXMLDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreateMediaXMLDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEMEDIAXMLDLG_H__580750D8_7D06_4676_8DF9_581EBE98716E__INCLUDED_)
