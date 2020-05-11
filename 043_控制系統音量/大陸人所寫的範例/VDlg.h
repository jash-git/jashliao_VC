// VDlg.h : header file
//

#if !defined(AFX_VDLG_H__6F443E96_6FA2_4687_9F84_8A461A4EB513__INCLUDED_)
#define AFX_VDLG_H__6F443E96_6FA2_4687_9F84_8A461A4EB513__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
#define WM_MY_NOTIFYICON   WM_USER+111	

#include"ppdlg.h";
#include"VolumControl.h"
#include"mutecontrol.h"

class CVDlg : public CDialog
{
// Construction
public:
	BOOL TaskBarDeleteIcon(HWND hwnd, UINT uID);
	BOOL TaskBarAddIcon(HWND hwnd, UINT uID, HICON hicon, LPSTR lpszTip,BOOL bb);
	CVDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CVDlg)
	enum { IDD = IDD_V_DIALOG };
	CHotKeyCtrl	m_hot3;
	CHotKeyCtrl	m_hot2;
	CHotKeyCtrl	m_hot1;
	BOOL	m_bMini;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CVolumControl  m_VControl;
    CMuteControl   m_mmv;
	// Generated message map functions
	//{{AFX_MSG(CVDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnHotKey(WPARAM wp,LPARAM lp);
	afx_msg void OnSave();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnMixerChange(WPARAM wparam,LPARAM lparam);
	afx_msg void OnMinimized();
	afx_msg void OnMyIconNotify(WPARAM wParam,LPARAM lParam);
	afx_msg void OnExit();
	afx_msg void OnAbout();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSet();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CFont m_font;
	CSliderCtrl* m_pSld;

	CProgressCtrl* m_pProgress;
	CPPDlg* m_pDlg;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VDLG_H__6F443E96_6FA2_4687_9F84_8A461A4EB513__INCLUDED_)
