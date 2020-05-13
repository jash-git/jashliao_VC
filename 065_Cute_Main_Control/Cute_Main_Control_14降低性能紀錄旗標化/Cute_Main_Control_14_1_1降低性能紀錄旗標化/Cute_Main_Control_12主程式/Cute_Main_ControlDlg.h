// Cute_Main_ControlDlg.h : header file
//
//{{AFX_INCLUDES()
#include "jpg.h"
//}}AFX_INCLUDES

#if !defined(AFX_CUTE_MAIN_CONTROLDLG_H__B0A24405_5F0B_48B0_A720_4072D0FEF259__INCLUDED_)
#define AFX_CUTE_MAIN_CONTROLDLG_H__B0A24405_5F0B_48B0_A720_4072D0FEF259__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define PDData_Max 10	//ProgramData最大陣列值
/////////////////////////////////////////////////////////////////////////////
// CCute_Main_ControlDlg dialog
#include "WatchDog.h"
class CCute_Main_ControlDlg : public CDialog
{
// Construction
public:
	CCute_Main_ControlDlg(CWnd* pParent = NULL);	// standard constructor
	bool m_MainMonitor_On;//強制On_OFF旗標1
	bool m_MainMonitor_Off;//強制On_OFF旗標2
	void Read_Monitor();//step 讀取XML4
	void InitializeXMLMemory();//初始化變數函數
	void MonitorRipData(CString Datainput,int day);//螢幕開關機字串拆解函數
	void ChangeFormRipData(CString Datainput);//改變版型串拆解函數
	void Detect_Command();//偵測讀取命令檔
	void Run_Command(int intCommandNumber);//執行命令
	void Start_Program();//啟動程式函數
	void Stop_Program();//關閉程式函數
	void Stop_ALL();//關閉程式函數，連通訊式
	void TimerFunction();//主程式
	bool Read_ChangeForm();//讀取改變版型訊息函數
	void Create_ChangeForm();//建立改變版型訊息函數
	void GetProgramInfo();//取讀啟動程式資訊
	void ChangeStyle(CString StrStyleName);//改變版型程式
	void OnlyControlMovie(bool blnflag);//控制Movie程式
	void GetMonitorPicture();//擷取螢幕畫面
	void GetSpeciallyDay();//取得特別關機日
	void CreateCommunication();//一開程式就把通訊程式
	void CreateLogFile();//開啟紀錄資訊功能
	void GetCreateFileFlag();//讀取是否建立記錄檔案旗標
	void BoBoProgramZindex(int p[PDData_Max][2],long n);//ProgramZindex氣泡排序
	void SetSystemVolume( const DWORD dwVolume );//設定系統音量//第12.5版->系統音量設定
	DWORD GetSystemVolume( void );//取得系統音量//第12.5版->系統音量設定
	void SetVolume();////第12.5版->讀取音量設定值並修改系統值
	void SwitchMonitor();//第12.7版->送CTRL+ALT+F9使新的STBㄧ定要選監視器輸出
	void ChangMonitorSize();//第12.8版->擷取與設定螢幕解析度
	void BrowseUpdateProgram(CString strDir);//第13.3版->搜尋更新程式數量與紀錄
	CString GetProgramVersion(CString StrDir);//第13.7版->查詢程式版本
	void Reset_Computer();//第13.8版
	CWatchDog m_WDT;//第14.1版->Watch Dog Timer
// Dialog Data
	//{{AFX_DATA(CCute_Main_ControlDlg)
	enum { IDD = IDD_CUTE_MAIN_CONTROL_DIALOG };
	CJPG	m_JPG;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCute_Main_ControlDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCute_Main_ControlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton2();
	afx_msg LRESULT onShowTask(WPARAM wParam,LPARAM lParam); //Step 縮小到系統工作列4
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton1();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUTE_MAIN_CONTROLDLG_H__B0A24405_5F0B_48B0_A720_4072D0FEF259__INCLUDED_)
