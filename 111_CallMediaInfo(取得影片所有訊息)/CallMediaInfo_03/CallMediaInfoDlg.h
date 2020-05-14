// CallMediaInfoDlg.h : header file
//

#if !defined(AFX_CALLMEDIAINFODLG_H__12F2AD77_115F_4680_8EE1_7D1B7FDCBAEF__INCLUDED_)
#define AFX_CALLMEDIAINFODLG_H__12F2AD77_115F_4680_8EE1_7D1B7FDCBAEF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCallMediaInfoDlg dialog

class CCallMediaInfoDlg : public CDialog
{
// Construction
public:
	CCallMediaInfoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCallMediaInfoDlg)
	enum { IDD = IDD_CALLMEDIAINFO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCallMediaInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCallMediaInfoDlg)
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

#endif // !defined(AFX_CALLMEDIAINFODLG_H__12F2AD77_115F_4680_8EE1_7D1B7FDCBAEF__INCLUDED_)
