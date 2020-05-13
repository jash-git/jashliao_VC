// File_ApartDlg.h : header file
//

#if !defined(AFX_FILE_APARTDLG_H__64C8D086_4233_46E5_9B92_AC9A6E9E0F62__INCLUDED_)
#define AFX_FILE_APARTDLG_H__64C8D086_4233_46E5_9B92_AC9A6E9E0F62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFile_ApartDlg dialog

class CFile_ApartDlg : public CDialog
{
// Construction
public:
	CFile_ApartDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFile_ApartDlg)
	enum { IDD = IDD_FILE_APART_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFile_ApartDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFile_ApartDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILE_APARTDLG_H__64C8D086_4233_46E5_9B92_AC9A6E9E0F62__INCLUDED_)
