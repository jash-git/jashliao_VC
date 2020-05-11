// MountNetDrvDlg.h : header file
//

#if !defined(AFX_MOUNTNETDRVDLG_H__A3345F73_096D_4337_9B9C_8F6129ADF0E3__INCLUDED_)
#define AFX_MOUNTNETDRVDLG_H__A3345F73_096D_4337_9B9C_8F6129ADF0E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMountNetDrvDlg dialog

class CMountNetDrvDlg : public CDialog
{
// Construction
public:
	CMountNetDrvDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMountNetDrvDlg)
	enum { IDD = IDD_MOUNTNETDRV_DIALOG };
	CEdit	m_NetpathEdit;
	CEdit	m_DriveEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMountNetDrvDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMountNetDrvDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonMount();
	afx_msg void OnButtonUnmount();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUNTNETDRVDLG_H__A3345F73_096D_4337_9B9C_8F6129ADF0E3__INCLUDED_)
