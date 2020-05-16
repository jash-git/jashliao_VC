// Reverie_PC_2Dlg.h : header file
//

#if !defined(AFX_REVERIE_PC_2DLG_H__289259AD_9126_46CB_8311_AAF487EA2206__INCLUDED_)
#define AFX_REVERIE_PC_2DLG_H__289259AD_9126_46CB_8311_AAF487EA2206__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RS232.h"
/////////////////////////////////////////////////////////////////////////////
// CReverie_PC_2Dlg dialog

class CReverie_PC_2Dlg : public CDialog
{
// Construction
public:
	CReverie_PC_2Dlg(CWnd* pParent = NULL);	// standard constructor
	HWND m_mp3player;
	////////////////////////////////////////////////////////////////////
	//Jash.Liao add member function
	void InitialVariable(void);
	////////////////////////////////////////////////////////////////////
	//Jash.Liao add member variable
	TCHAR m_chrCurDrt[500];//存放目前目錄字串
	CString m_StrSettingFileName;
	long m_lngTop,m_lngLeft,m_lngWidth,m_lngHeight;
	CRgn m_rgn;
	int m_intCOMPort;
	CString m_StrSHexhvVideo,m_StrSHexhaAudio;
	////////////////////////////////////////////////////////////////////
	CRS232 RS;
	void OnOpenRS485();
	///////////////////////////////////////////////////////////////////
	void ButtonEnable();
	void ButtonDisable();
// Dialog Data
	//{{AFX_DATA(CReverie_PC_2Dlg)
	enum { IDD = IDD_REVERIE_PC_2_DIALOG };
	CButton	m_ButtNoSnore;
	CButton	m_ButtMovie;
	CButton	m_ButtTVMode;
	CButton	m_ButtMother;
	CButton	m_ButtMemoryFunction2;
	CButton	m_ButtStopVibration;
	CButton	m_ButtFootMassage;
	CButton	m_ButtWaistMassage;
	CButton	m_ButtFootUp;
	CButton	m_ButtMusic;
	CButton	m_ButtAuto;
	CButton	m_ButtCalibrateBed;
	CString	m_StrState;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReverie_PC_2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CReverie_PC_2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnBUTCalibrateBed();
	afx_msg void OnBUTAuto();
	afx_msg void OnBUTMusic();
	afx_msg void OnBUTFootUp();
	afx_msg void OnBUTWaistMassage();
	afx_msg void OnBUTFootMassage();
	afx_msg void OnBUTStopVibration();
	afx_msg void OnBUTMemoryFunction2();
	afx_msg void OnBUTMother();
	afx_msg void OnBUTTVMode();
	afx_msg void OnBUTMovie();
	afx_msg void OnBUTNoSnore();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REVERIE_PC_2DLG_H__289259AD_9126_46CB_8311_AAF487EA2206__INCLUDED_)
