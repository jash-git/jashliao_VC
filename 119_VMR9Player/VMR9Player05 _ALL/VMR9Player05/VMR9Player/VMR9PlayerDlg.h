// VMR9PlayerDlg.h : 標頭檔
//

#pragma once
#include "cvideo.h"//VMR9_step 02
#include "afxwin.h"

// CVMR9PlayerDlg 對話方塊
class CVMR9PlayerDlg : public CDialog
{
// 建構
public:
	CVMR9PlayerDlg(CWnd* pParent = NULL);	// 標準建構函式
	////////////////////////////////////////////////////////////////////
	//Jash.Liao add member function
	void InitialVariable(void);
	////////////////////////////////////////////////////////////////////
	//Jash.Liao add member variable
	TCHAR m_chrCurDrt[500];//存放目前目錄字串
	CString m_StrSettingFileName;
	long m_lngTop,m_lngLeft,m_lngWidth,m_lngHeight;
	CRgn m_rgn;
	////////////////////////////////////////////////////////////////////
	double m_dblPosition;
	CString m_sourceFile;
	CString m_mediaFileName;
	CString  GetFileTitleFromFileName(CString FileName, BOOL Ext);
	CString GetMapMemory(double *dblPosition);//MAP memory_step 04
	////////////////////////////////////////////////
	//VMR9_step 03
	cVideo mVideoClass;
	LRESULT OnGraphNotify ( WPARAM wParam, LPARAM lParam ) ;
	///////////////////////////////////////////////
// 對話方塊資料
	enum { IDD = IDD_VMR9PLAYER_DIALOG };

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
	CStatic m_videoWindow;
};
