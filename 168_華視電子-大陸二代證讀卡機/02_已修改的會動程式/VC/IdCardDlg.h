#pragma once
#include <GdiPlus.h>

using namespace Gdiplus;

// CIdCardDlg dialog

class CIdCardDlg : public CDialog
{
	DECLARE_DYNAMIC(CIdCardDlg)

public:
	CIdCardDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CIdCardDlg();

// Dialog Data
	enum { IDD = IDD_IDCARDDLG };

public:
	void SetReadParam(int nPort, int nTimer, int nRepeat);

protected:
	CStatic m_civicName;
	CStatic m_civicSex;
	CStatic m_civicNation;
	CStatic m_civicNationCode;
	CStatic m_civicBirthday;
	CStatic m_civicCardID;
	CStatic m_civicAddress;
	CStatic m_civicDepartment;
	CStatic m_civicValidDate;
	CStatic m_civicSamID;
	CStatic m_civicReadTime;

	Bitmap * m_pBmp;
	UINT_PTR m_nTimerEvent;

	int m_nPort;
	int m_nTimer;
	BOOL m_nRepeat;
	BOOL m_bParamChanged;

	void OnLoadCivicPic();
	void ShowPhoto(int nPhotoID);

	void ReadCard();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedReadIdCard();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	void CIdCardDlg::PictureSave(UINT ID);

};
