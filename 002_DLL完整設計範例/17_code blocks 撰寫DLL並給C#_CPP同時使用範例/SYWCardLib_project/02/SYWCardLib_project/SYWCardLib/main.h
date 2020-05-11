#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

typedef struct _CardInfo
{
    int intType;//卡片類型
    int intUsage;//卡片用途
    int intConfiguration;//延伸資料類型

    int intPassThroughCounter;//通行次數
    int intHolidayWeekProgramValue;//周計畫+假日通行設定

    int intStartExpirationDate;//卡片有效期限設定
    int intEnd1eExpirationDate;//卡片有效期限設定
	char strStartExpirationDate[17];//'YYYYMMddHHmm'
	char strEndleExpirationDate[17];//'YYYYMMddHHmm'

    int intFirstPassThroughTimeRange;//可通行時段
    int intSecondPassThroughTimeRange;//可通行時段
    int intThirdPassThroughTimeRange;//可通行時段

    char strUserUniqueIdentifier[17];//用戶識別碼 "AAAAAAAA"(PS長度和原本不同)
    char strScramblerCode[5];//擾碼設定 "aaaa"(PS長度和原本不同)

    //-----------------------------------------------------------
    //延伸資料
    char strUserPasswordCode[9];//使用者密碼設定 "12345678"(單一個)

    char strDoorName1[9];//門區名稱設定(使用類似ArrayList方式存取) GWC_DOOR_NAME_LENGTH_MAXIMUM=8
    char strDoorName2[9];//門區名稱設定(使用類似ArrayList方式存取) GWC_DOOR_NAME_LENGTH_MAXIMUM=8
    char strDoorName3[9];//門區名稱設定(使用類似ArrayList方式存取) GWC_DOOR_NAME_LENGTH_MAXIMUM=8
    int intDoorNameSize;//紀錄SIZE

    int intDoorAccess[1152];//門區群組設定(使用類似ArrayList方式存取) MAX=1152
    int intDoorAccessSize;//紀錄SIZE
}CardInfo;

#ifdef __cplusplus
extern "C"
{
#endif

void DLL_EXPORT SomeFunction(const LPCSTR sometext);
double DLL_EXPORT Add(double a, double b);//test_API
int DLL_EXPORT WCard_init();//只能執行一次
int DLL_EXPORT WCard_detectReader();//偵測Reader
int DLL_EXPORT WCard_read(CardInfo*& res);//讀取
int DLL_EXPORT WCard_write(CardInfo &res);//寫入
int DLL_EXPORT WCard_readTest();
int DLL_EXPORT WCard_writeTest(int state);
int DLL_EXPORT WCard_close();//結束時執行
#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
