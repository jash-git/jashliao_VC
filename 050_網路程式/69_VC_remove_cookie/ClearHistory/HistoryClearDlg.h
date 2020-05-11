// HistoryClearDlg.h : header file
//

#if !defined(AFX_HISTORYCLEARDLG_H__E2BCB71F_FEC6_4359_AF88_0D1D6201AAFD__INCLUDED_)
#define AFX_HISTORYCLEARDLG_H__E2BCB71F_FEC6_4359_AF88_0D1D6201AAFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000




#include <wininet.h>
#include <UrlHist.h>

#define SWEEP_BUFFER_SIZE			10000


/////////////////////////////////////////////////////////////////////////////
// CHistoryClearDlg dialog

class CHistoryClearDlg : public CDialog
{
// Construction
public:
	CHistoryClearDlg(CWnd* pParent = NULL);	// standard constructor
  
	enum DEL_CACHE_TYPE //要删除的类型。
	 {
	 File,//表示internet临时文件
	 Cookie //表示Cookie
	 };

//以下为一些，辅助函数.
  BOOL DeleteUrlCache(DEL_CACHE_TYPE type);
  BOOL EmptyDirectory(LPCTSTR szPath, BOOL bDeleteDesktopIni = FALSE,   BOOL bWipeIndexDat = FALSE);
  BOOL IsWindowsNT();//判断系统
  BOOL IsWindows2k();
  BOOL GetUserSid(PSID* ppSid);
  void GetSidString(PSID pSid, LPTSTR szBuffer);
  BOOL GetOldSD(HKEY hKey, LPCTSTR pszSubKey, BYTE** pSD);
  BOOL CreateNewSD(PSID pSid, SECURITY_DESCRIPTOR* pSD, PACL* ppDacl);
  BOOL RegSetPrivilege(HKEY hKey, LPCTSTR pszSubKey, SECURITY_DESCRIPTOR* pSD, BOOL bRecursive);
  BOOL WipeFile(LPCTSTR szDir, LPCTSTR szFile);

// Dialog Data
	//{{AFX_DATA(CHistoryClearDlg)
	enum { IDD = IDD_HISTORYCLEAR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistoryClearDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHistoryClearDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton9();
	afx_msg void OnButton10();
	afx_msg void OnButton11();
	afx_msg void OnButton12();
	afx_msg void OnButton13();
	afx_msg void OnButton14();
	afx_msg void OnButton15();
	afx_msg void OnButton16();
	afx_msg void OnButton17();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTORYCLEARDLG_H__E2BCB71F_FEC6_4359_AF88_0D1D6201AAFD__INCLUDED_)
