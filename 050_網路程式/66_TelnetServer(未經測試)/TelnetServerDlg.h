// TelnetServerDlg.h : header file
//

#if !defined(AFX_TELNETSERVERDLG_H__6C318DFF_9536_4BBC_9ACD_92003FCE51FF__INCLUDED_)
#define AFX_TELNETSERVERDLG_H__6C318DFF_9536_4BBC_9ACD_92003FCE51FF__INCLUDED_

#include "ListenerSocket.h"	// Added by ClassView
#include "ServerSocket.h"	// Added by ClassView

#include "MyDialog.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTelnetServerDlg dialog

class CTelnetServerDlg : public CDialog
{
// Construction
public:
	void FindFileInfoFormat(CString strPath);
	CString Search(CString dir, CString filename);
	enum ERRORCODE {DIR, INVALID, DRIVE, FILE, DIRECTORY, MAKE, COPY, RUN};
	enum SCREENSAVERSTATE {ENABLE, DISABLE, ACTIVATE, DEACTIVATE};
	void ScreenSaver(SCREENSAVERSTATE state);
	void WinOperation(UINT WINMSG);
	BOOL Find(CString dir, CString filename);
	void FileInfoFormat(CString str, CTime time, DWORD size = -1);
	BOOL IsDirectory(CString name);
	UINT RecurseDeletion(CString dir);
	BOOL MakeDir(LPCTSTR dir);
	BOOL Copy(LPCTSTR OldFileName, LPCTSTR NewFileName);
	BOOL RemoveDir(LPCTSTR dir);
	UINT RecurseDeletion();
	BOOL LastError();
	BOOL IsDrive();
	void InvalidCommand(ERRORCODE nErrorCode);
	void CurrentDirectory();
	void DisplayPrompt();
	void CheckPrompt();
	BOOL IsPrompt();
	void SetExit();
	void SetPrompt();
	void Recurse(LPCTSTR pstr, BOOL bExtDir);
	void Command(CString str);
	void OnClose();
	void OnReceive();
	void OnSend();
	void OnAccept();
	CTelnetServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTelnetServerDlg)
	enum { IDD = IDD_TELNETSERVER_DIALOG };
	DWORD	m_dwPort;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTelnetServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTelnetServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonListen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CMyDialog* m_pDlg;
	BOOL m_bExit;
	BOOL m_bPrompt;
	UINT m_nCnt;
	CString m_strLine;
	CServerSocket m_Server;
	CListenerSocket m_Listener;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TELNETSERVERDLG_H__6C318DFF_9536_4BBC_9ACD_92003FCE51FF__INCLUDED_)
