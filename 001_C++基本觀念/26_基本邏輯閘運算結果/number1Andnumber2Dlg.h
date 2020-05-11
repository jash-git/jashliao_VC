// number1Andnumber2Dlg.h : header file
//

#if !defined(AFX_NUMBER1ANDNUMBER2DLG_H__FEABCAF8_36A1_40C1_BEB1_E80E059C9C0D__INCLUDED_)
#define AFX_NUMBER1ANDNUMBER2DLG_H__FEABCAF8_36A1_40C1_BEB1_E80E059C9C0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNumber1Andnumber2Dlg dialog

class CNumber1Andnumber2Dlg : public CDialog
{
// Construction
public:
	CNumber1Andnumber2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNumber1Andnumber2Dlg)
	enum { IDD = IDD_NUMBER1ANDNUMBER2_DIALOG };
	long	m_v1;
	long	m_v2;
	long	m_v3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumber1Andnumber2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNumber1Andnumber2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMBER1ANDNUMBER2DLG_H__FEABCAF8_36A1_40C1_BEB1_E80E059C9C0D__INCLUDED_)
