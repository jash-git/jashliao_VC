// ReadMultiLevelXMLDlg.h : header file
//

#if !defined(AFX_READMULTILEVELXMLDLG_H__49DB3543_54D2_4B12_AFA0_E32DF0068274__INCLUDED_)
#define AFX_READMULTILEVELXMLDLG_H__49DB3543_54D2_4B12_AFA0_E32DF0068274__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CReadMultiLevelXMLDlg dialog

class CReadMultiLevelXMLDlg : public CDialog
{
// Construction
public:
	CReadMultiLevelXMLDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CReadMultiLevelXMLDlg)
	enum { IDD = IDD_READMULTILEVELXML_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadMultiLevelXMLDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReadMultiLevelXMLDlg)
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

#endif // !defined(AFX_READMULTILEVELXMLDLG_H__49DB3543_54D2_4B12_AFA0_E32DF0068274__INCLUDED_)
