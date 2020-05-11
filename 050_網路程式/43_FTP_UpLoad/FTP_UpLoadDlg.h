// FTP_UpLoadDlg.h : header file
//

#if !defined(AFX_FTP_UPLOADDLG_H__DF47A643_C1A2_4439_A25A_4224D04FC615__INCLUDED_)
#define AFX_FTP_UPLOADDLG_H__DF47A643_C1A2_4439_A25A_4224D04FC615__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFTP_UpLoadDlg dialog
#include <afxinet.h>//FTP_1
class CFTP_UpLoadDlg : public CDialog
{
// Construction
public:
	CFTP_UpLoadDlg(CWnd* pParent = NULL);	// standard constructor
	CInternetSession *m_pInetSession; //FTP_2
	CFtpConnection *m_pFtpConnection; 
// Dialog Data
	//{{AFX_DATA(CFTP_UpLoadDlg)
	enum { IDD = IDD_FTP_UPLOAD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFTP_UpLoadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFTP_UpLoadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FTP_UPLOADDLG_H__DF47A643_C1A2_4439_A25A_4224D04FC615__INCLUDED_)
