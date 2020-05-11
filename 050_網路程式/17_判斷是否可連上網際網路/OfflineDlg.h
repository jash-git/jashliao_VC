// OfflineDlg.h : header file
//

#if !defined(AFX_OFFLINEDLG_H__CA3D191E_8AD0_40BD_8E57_A2745F374B23__INCLUDED_)
#define AFX_OFFLINEDLG_H__CA3D191E_8AD0_40BD_8E57_A2745F374B23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COfflineDlg dialog

class COfflineDlg : public CDialog
{
// Construction
public:
	COfflineDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COfflineDlg)
	enum { IDD = IDD_OFFLINE_DIALOG };
	CString	m_v1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COfflineDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COfflineDlg)
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

#endif // !defined(AFX_OFFLINEDLG_H__CA3D191E_8AD0_40BD_8E57_A2745F374B23__INCLUDED_)
