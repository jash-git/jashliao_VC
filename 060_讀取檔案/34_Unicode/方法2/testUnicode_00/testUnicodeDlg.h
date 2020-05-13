// testUnicodeDlg.h : header file
//

#if !defined(AFX_TESTUNICODEDLG_H__3D72A362_3FC0_40AA_A284_F0A7BF2F1603__INCLUDED_)
#define AFX_TESTUNICODEDLG_H__3D72A362_3FC0_40AA_A284_F0A7BF2F1603__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestUnicodeDlg dialog

class CTestUnicodeDlg : public CDialog
{
// Construction
public:
	CTestUnicodeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTestUnicodeDlg)
	enum { IDD = IDD_TESTUNICODE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestUnicodeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestUnicodeDlg)
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

#endif // !defined(AFX_TESTUNICODEDLG_H__3D72A362_3FC0_40AA_A284_F0A7BF2F1603__INCLUDED_)
