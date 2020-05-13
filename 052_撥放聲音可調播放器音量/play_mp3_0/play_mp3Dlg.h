// play_mp3Dlg.h : header file
//

#if !defined(AFX_PLAY_MP3DLG_H__77760670_7EC3_453F_81D6_0C1EDA99E758__INCLUDED_)
#define AFX_PLAY_MP3DLG_H__77760670_7EC3_453F_81D6_0C1EDA99E758__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPlay_mp3Dlg dialog

class CPlay_mp3Dlg : public CDialog
{
// Construction
public:
	CPlay_mp3Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPlay_mp3Dlg)
	enum { IDD = IDD_PLAY_MP3_DIALOG };
	long	m_v1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlay_mp3Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPlay_mp3Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton3();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAY_MP3DLG_H__77760670_7EC3_453F_81D6_0C1EDA99E758__INCLUDED_)
