// VS2008CTimeSpanCTime.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "VS2008CTimeSpanCTime.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 僅有的一個應用程式物件

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// 初始化 MFC 並於失敗時列印錯誤
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: 配合您的需要變更錯誤碼
		_tprintf(_T("嚴重錯誤: MFC 初始化失敗\n"));
		nRetCode = 1;
	}
	else
	{
		// TODO: 在此撰寫應用程式行為的程式碼。
		//////////////////////////////////////////////////////////////

		//取得現在時間
		CTime cur_tm = CTime::GetCurrentTime();
		
		//取得CTime ->CString 
		CString StrCurrentTime= cur_tm.Format("%Y-%m-%d %H:%M:%S");

		//取得2000年1月1日0時0分0秒 時間
		CTime tmY2000(2000,1,1,0,0,0);


		//取得 年月日時分秒
		int year = cur_tm.GetYear();
		int month = cur_tm.GetMonth();
		int date = cur_tm.GetDay();
		int DayOfWeek = cur_tm.GetDayOfWeek(); // 禮拜幾,1=SUN ... 7=SAT
		int hour = cur_tm.GetHour();
		int minute = cur_tm.GetMinute();
		int Second = cur_tm.GetSecond();

		//取得一天的時間差
		CTimeSpan ts_day(1,0,0,0); // 日 時 分 秒

		//取得兩個時間的時間差
		CTimeSpan ts = cur_tm - tmY2000;

		//取得差值
		int Days= ts.GetDays();
		int Hours=ts.GetHours();
		int Minutes=ts.GetMinutes();
		int Seconds=ts.GetSeconds();
		long TotalHours=ts.GetTotalHours();
		long TotalMinutes=ts.GetTotalMinutes();
		long TotalSeconds=ts.GetTotalSeconds();


		//將時間差與現在時間相加產生一天後的時間
		CTime tm = cur_tm + ts_day;

		//取得一天後的 年月日時分秒
		year = tm.GetYear();
		month = tm.GetMonth();
		date = tm.GetDay();
		DayOfWeek = tm.GetDayOfWeek(); // 禮拜幾,1=SUN ... 7=SAT
		hour = tm.GetHour();
		minute = tm.GetMinute();
		Second = tm.GetSecond();
	}

	return nRetCode;
}
