// 8136_3asixDlg.h : header file
//

#if !defined(AFX_8136_3ASIXDLG_H__0C23E499_63B2_4A27_9408_41C5BEEC747C__INCLUDED_)
#define AFX_8136_3ASIXDLG_H__0C23E499_63B2_4A27_9408_41C5BEEC747C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy8136_3asixDlg dialog

class CMy8136_3asixDlg : public CDialog
{
// Construction
public:
	CMy8136_3asixDlg(CWnd* pParent = NULL);	// standard constructor
	
	long SetTimer1;
	bool m_CloseCard;		//避免讓卡重覆關閉

	// 變數定義
	int x_dir;	// x軸方向變數
	int y_dir;	// y軸方向變數
	int z_dir;	// z軸方向變數
	float x_pos;	// x軸位置
	float y_pos;	// y軸位置
	float z_pos;	// z軸位置
	int	Axis_Reset_Index;		//s_reset,步驟用
	long Axis_Reset_Counter;	//s_reset,計時用

	short m_nCards;
	long m_lDinput;

    void CloseCard();
	void OnSensor();
	void Reset11();
	void Reset12();
	void Reset13();
	void Reset14();
	void Reset15();

// Dialog Data
	//{{AFX_DATA(CMy8136_3asixDlg)
	enum { IDD = IDD_MY8136_3ASIX_DIALOG };
	float	m_ParaDis;
	int		m_ParaMV;
	int		m_ParaSV;
	float	m_ParaTacc;
	float	m_ParaTdec;
	long	m_Sensor;
	double	m_Pressure;
	int		m_Axis;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy8136_3asixDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy8136_3asixDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	afx_msg void OnExit();
	afx_msg void OnXr();
	afx_msg void OnXl();
	afx_msg void OnYf();
	afx_msg void OnYb();
	afx_msg void OnZd();
	afx_msg void OnZu();
	afx_msg void OnStop();
	afx_msg void OnReset();
	afx_msg void OnXl2();
	afx_msg void OnXr2();
	afx_msg void OnYf2();
	afx_msg void OnYb2();
	afx_msg void OnZd2();
	afx_msg void OnTest();
	afx_msg void OnButton2();
	afx_msg void OnHome();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_8136_3ASIXDLG_H__0C23E499_63B2_4A27_9408_41C5BEEC747C__INCLUDED_)
