// Get_IPDlg.h : header file
//

#if !defined(AFX_GET_IPDLG_H__E58E8336_A18F_4266_8F27_02E7F614B6F4__INCLUDED_)
#define AFX_GET_IPDLG_H__E58E8336_A18F_4266_8F27_02E7F614B6F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGet_IPDlg dialog

class CGet_IPDlg : public CDialog
{
// Construction
public:
	CGet_IPDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGet_IPDlg)
	enum { IDD = IDD_GET_IP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGet_IPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGet_IPDlg)
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

#endif // !defined(AFX_GET_IPDLG_H__E58E8336_A18F_4266_8F27_02E7F614B6F4__INCLUDED_)
