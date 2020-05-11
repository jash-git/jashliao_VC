// ChangeDisplayDlg.h : header file
//

#if !defined(AFX_CHANGEDISPLAYDLG_H__4479D08E_B4D2_44D4_BCDF_C62F201356C2__INCLUDED_)
#define AFX_CHANGEDISPLAYDLG_H__4479D08E_B4D2_44D4_BCDF_C62F201356C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChangeDisplayDlg dialog

class CChangeDisplayDlg : public CDialog
{
// Construction
public:
	CChangeDisplayDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChangeDisplayDlg)
	enum { IDD = IDD_CHANGEDISPLAY_DIALOG };
	UINT	m_nWidthPixels;
	UINT	m_nHeightPixels;
	UINT	m_nBitsPerPixel;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeDisplayDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChangeDisplayDlg)
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

#endif // !defined(AFX_CHANGEDISPLAYDLG_H__4479D08E_B4D2_44D4_BCDF_C62F201356C2__INCLUDED_)
