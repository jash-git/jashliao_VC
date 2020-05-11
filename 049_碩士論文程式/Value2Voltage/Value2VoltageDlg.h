// Value2VoltageDlg.h : header file
//

#if !defined(AFX_VALUE2VOLTAGEDLG_H__83279419_F240_4C9E_B066_425BEA74E795__INCLUDED_)
#define AFX_VALUE2VOLTAGEDLG_H__83279419_F240_4C9E_B066_425BEA74E795__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CValue2VoltageDlg dialog

class CValue2VoltageDlg : public CDialog
{
// Construction
public:
	CValue2VoltageDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CValue2VoltageDlg)
	enum { IDD = IDD_VALUE2VOLTAGE_DIALOG };
	CString	m_v1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CValue2VoltageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CValue2VoltageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnInt2Vol();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VALUE2VOLTAGEDLG_H__83279419_F240_4C9E_B066_425BEA74E795__INCLUDED_)
