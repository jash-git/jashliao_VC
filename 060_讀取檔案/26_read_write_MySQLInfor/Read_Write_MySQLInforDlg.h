// Read_Write_MySQLInforDlg.h : header file
//

#if !defined(AFX_READ_WRITE_MYSQLINFORDLG_H__83051900_1935_402D_8956_89024FD07803__INCLUDED_)
#define AFX_READ_WRITE_MYSQLINFORDLG_H__83051900_1935_402D_8956_89024FD07803__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRead_Write_MySQLInforDlg dialog

class CRead_Write_MySQLInforDlg : public CDialog
{
// Construction
public:
	CRead_Write_MySQLInforDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRead_Write_MySQLInforDlg)
	enum { IDD = IDD_READ_WRITE_MYSQLINFOR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRead_Write_MySQLInforDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRead_Write_MySQLInforDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTRead();
	afx_msg void OnBUTWrite();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READ_WRITE_MYSQLINFORDLG_H__83051900_1935_402D_8956_89024FD07803__INCLUDED_)
