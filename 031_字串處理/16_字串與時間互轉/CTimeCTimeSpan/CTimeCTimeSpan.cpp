// CTimeCTimeSpan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CTimeCTimeSpan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		CString strHello;
		strHello.LoadString(IDS_HELLO);
		cout << (LPCTSTR)strHello << endl;
		//////////////////////////////////////////////////////////////

		//取得現在時間
		CTime cur_tm = CTime::GetCurrentTime();

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


