// MixertestDlg.h : header file
//

#if !defined(AFX_MIXERTESTDLG_H__0557EDAA_0999_46C2_9983_7800F840FB3D__INCLUDED_)
#define AFX_MIXERTESTDLG_H__0557EDAA_0999_46C2_9983_7800F840FB3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMixertestDlg dialog

class CMixertestDlg : public CDialog
{
// Construction
public:
	CMixertestDlg(CWnd* pParent = NULL);	// standard constructor
    void SetVolume( const DWORD dwVolume );
	DWORD GetVolume( void );
// Dialog Data
	//{{AFX_DATA(CMixertestDlg)
	enum { IDD = IDD_MIXERTEST_DIALOG };
	long	m_v1;
	long	m_v2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMixertestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMixertestDlg)
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

#endif // !defined(AFX_MIXERTESTDLG_H__0557EDAA_0999_46C2_9983_7800F840FB3D__INCLUDED_)
