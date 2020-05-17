#pragma once
#include <GdiPlus.h>

using namespace Gdiplus;

// CPrCardDlg dialog

class CPrCardDlg : public CDialog
{
	DECLARE_DYNAMIC(CPrCardDlg)

public:
	CPrCardDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPrCardDlg();

// Dialog Data
	enum { IDD = IDD_PRCARDDLG };

public:
	void SetReadParam(int nPort, int nTimer, int nRepeat);

protected:
	CStatic m_name;
	CStatic m_sex;
	CStatic m_nation;
	CStatic m_birth;
	CStatic m_idcode;
	CStatic m_addr;
	CStatic m_depart;
	CStatic m_depCode;
	CStatic m_valid;
	CStatic m_stChineseName;
	CStatic m_stCertVer;

	Bitmap * m_pBmp;
	UINT_PTR m_nTimerEvent;

	int m_nPort;
	int m_nTimer;
	BOOL m_nRepeat;
	BOOL m_bParamChanged;

	void OnLoadForeinerPic();
	void ShowPhoto(int nPhotoID);

	void ReadCard();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedReadForeinIdCard();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
};
