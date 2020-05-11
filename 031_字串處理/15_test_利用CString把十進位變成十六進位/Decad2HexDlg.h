// Decad2HexDlg.h : header file
//

#if !defined(AFX_DECAD2HEXDLG_H__9225FEE4_D238_4A0E_BC21_BB039EC44362__INCLUDED_)
#define AFX_DECAD2HEXDLG_H__9225FEE4_D238_4A0E_BC21_BB039EC44362__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDecad2HexDlg dialog

class CDecad2HexDlg : public CDialog
{
// Construction
public:
	CDecad2HexDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDecad2HexDlg)
	enum { IDD = IDD_DECAD2HEX_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDecad2HexDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDecad2HexDlg)
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

#endif // !defined(AFX_DECAD2HEXDLG_H__9225FEE4_D238_4A0E_BC21_BB039EC44362__INCLUDED_)
