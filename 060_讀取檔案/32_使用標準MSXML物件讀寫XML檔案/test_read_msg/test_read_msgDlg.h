// test_read_msgDlg.h : header file
//

#if !defined(AFX_TEST_READ_MSGDLG_H__47925F27_66DC_473D_AD20_1A76F16A9025__INCLUDED_)
#define AFX_TEST_READ_MSGDLG_H__47925F27_66DC_473D_AD20_1A76F16A9025__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest_read_msgDlg dialog

class CTest_read_msgDlg : public CDialog
{
// Construction
public:
	CTest_read_msgDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest_read_msgDlg)
	enum { IDD = IDD_TEST_READ_MSG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_read_msgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest_read_msgDlg)
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

#endif // !defined(AFX_TEST_READ_MSGDLG_H__47925F27_66DC_473D_AD20_1A76F16A9025__INCLUDED_)
