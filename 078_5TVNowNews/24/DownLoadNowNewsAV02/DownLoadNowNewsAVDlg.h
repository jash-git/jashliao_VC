// DownLoadNowNewsAVDlg.h : header file
//

#if !defined(AFX_DOWNLOADNOWNEWSAVDLG_H__F73E355B_E94D_411F_B48E_68A9C2822CDF__INCLUDED_)
#define AFX_DOWNLOADNOWNEWSAVDLG_H__F73E355B_E94D_411F_B48E_68A9C2822CDF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDownLoadNowNewsAVDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CDownLoadNowNewsAVDlg dialog
#include <afxtempl.h>//CArray Step_01 
class CDownLoadNowNewsAVDlg : public CDialog
{
	DECLARE_DYNAMIC(CDownLoadNowNewsAVDlg);
	friend class CDownLoadNowNewsAVDlgAutoProxy;
// Construction
public:
	CDownLoadNowNewsAVDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CDownLoadNowNewsAVDlg();
	CArray <CString,CString&> m_Array1;//CArray Step_02
	CArray <CString,CString&> m_Array2;//CArray Step_02
	CArray <CString,CString&> m_Array3;//CArray Step_02
	CString GetFileName(CString Strdata);
	bool GetWebFile(CString theUrl, CString Filename);//Step 2:Http
	bool WgetFtp2WMV();
// Dialog Data
	//{{AFX_DATA(CDownLoadNowNewsAVDlg)
	enum { IDD = IDD_DOWNLOADNOWNEWSAV_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownLoadNowNewsAVDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CDownLoadNowNewsAVDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CDownLoadNowNewsAVDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOWNLOADNOWNEWSAVDLG_H__F73E355B_E94D_411F_B48E_68A9C2822CDF__INCLUDED_)
