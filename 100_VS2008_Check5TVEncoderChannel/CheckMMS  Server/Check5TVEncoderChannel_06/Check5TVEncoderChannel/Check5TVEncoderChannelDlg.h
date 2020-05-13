// Check5TVEncoderChannelDlg.h : 標頭檔
//

#pragma once
#include "ocx1.h"
#include "CWMPControls.h"
#include "CWMPSettings.h" 
#include "CWMPPlaylist.h"
#include "CWMPMedia.h"
#include <afxtempl.h>//CArray Step_01 
// CCheck5TVEncoderChannelDlg 對話方塊
class CCheck5TVEncoderChannelDlg : public CDialog
{
// 建構
public:
	CCheck5TVEncoderChannelDlg(CWnd* pParent = NULL);	// 標準建構函式
	/////////////////////////////////////////////////
	void GetEncoderList(void);
	bool GetWebFile(CString theUrl, CString Filename);//http_download
	void GetXmlParameter();//step 3:讀取XML
	void init();
	void WebServiceUpdate(int id,int state,int value);
// 對話方塊資料
	enum { IDD = IDD_CHECK5TVENCODERCHANNEL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	/////////////////////////////////////
	//jash Write
	CWMPControls m_control;
	CWMPSettings m_set; 
	CWMPPlaylist m_playlist;
	CWMPMedia m_media;
	COcx1 m_Player;
	CArray <CString,CString&> m_ArrayServiceID;//CArray Step
	CArray <CString,CString&> m_ArrayChannelName;//CArray Step
	CArray <CString,CString&> m_ArrayChannelUrl;//CArray Step
	int m_intTimerCount;
	int m_intMMSUrlCount;
	int m_intMMSUrlNumber;
	bool m_blnState;
	int m_intSec;
	CString m_StrID;
	CString m_StrMMSUrl;
	CString m_StrMMSName;
	////////////////////////////////////
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
	CString m_StrShowChannel;
	CString m_StrShowLoadingTime;
};
