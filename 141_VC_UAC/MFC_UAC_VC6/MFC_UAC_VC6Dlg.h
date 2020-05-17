// MFC_UAC_VC6Dlg.h : header file
//

#if !defined(AFX_MFC_UAC_VC6DLG_H__D12808A9_C8AC_4274_A7D1_ADD7D3305FE5__INCLUDED_)
#define AFX_MFC_UAC_VC6DLG_H__D12808A9_C8AC_4274_A7D1_ADD7D3305FE5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFC_UAC_VC6Dlg dialog

class CMFC_UAC_VC6Dlg : public CDialog
{
// Construction
public:
	CMFC_UAC_VC6Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFC_UAC_VC6Dlg)
	enum { IDD = IDD_MFC_UAC_VC6_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFC_UAC_VC6Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFC_UAC_VC6Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFC_UAC_VC6DLG_H__D12808A9_C8AC_4274_A7D1_ADD7D3305FE5__INCLUDED_)
