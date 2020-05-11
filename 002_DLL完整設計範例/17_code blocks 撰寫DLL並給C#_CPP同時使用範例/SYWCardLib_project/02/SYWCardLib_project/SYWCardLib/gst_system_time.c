/*
============================================
 檔案名稱：gst_system_time.c
 程式功能：時間工具
 設計者：Seamus Berloz (軒摩斯貝爾羅)
 版權擁有者：SYRIS Technology Corp.
 最後更新日期：2016/05/30 上午 11:32:29
 其他資訊：
============================================
*/
/*---------------------------------------------------------------------------*/
/* 包含標頭檔 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 自定義包含檔 =- */
/* 硬體抽象層程式庫定義包含檔 */
#ifndef GHLD_LIBRARY
  #include "ghld_hallib_define.h"
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 標準包含檔 =- */
/* 在未搭配硬體抽象層程式庫定義時引入相關標準包含檔 */
#if ((!defined(GHLD_LIBRARY)) || (GHLD_LIBRARY == GHLD_LIBRARY_NONE))
  //#include <errno.h>
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* Include system network headers */
#if (defined(WIN32) || defined(_WIN32))
  #include <windows.h>
  #include <unistd.h>

/* UNIX or others */
#else
  #include <sys/time.h>
  #include <unistd.h>

#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 自定義包含檔 =- */
//#include "include/gnet.h"

/*---------------------------------------------------------------------------*/
/* 僅供本模組專用之常數定義 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用常數宣告定義 =- */
/* 時間修正值常數宣告定義 */
#define GST_TIME_DELTA_EPOCH_IN_MICROSECOND 11644473600000000ULL

/*---------------------------------------------------------------------------*/
/* 僅供本模組專用之宣告型態定義 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用資料型態宣告定義 =- */
/* struct timeval 型態別名宣告定義 */
#ifndef TIMEVALUE
  #define TIMEVALUE struct timeval
#endif

/*---------------------------------------------------------------------------*/
/* 僅供本模組專用之變數定義 */

/*---------------------------------------------------------------------------*/
/* 函式原型定義 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用公用函數宣告定義 =- */
long GSTTimeGetTime(void);
int GSTTimeSleep(long lMillisecondValue);
int GSTTimeCheckTimeUp(long lMillisecondValue, long lMillisecondValueLimit);

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 私用函數宣告定義 =- */
#if (defined(WIN32) || defined(_WIN32))
static unsigned long long FiletimeToUnixEpoch(const FILETIME *lpFiletime);
#endif

/*---------------------------------------------------------------------------*/
/* 取得時間 */
long GSTTimeGetTime(void)
  {
    long lDeltaMillisecond, lCurrentMillisecond;
    TIMEVALUE timTimeValue;

    static long s_lTotalMillisecond = 0;
    static long s_lLastMillisecond = 0;

    #if (defined(WIN32) || defined(_WIN32))

    unsigned long long ullTime;
    FILETIME ftFiletime;

    GetSystemTimeAsFileTime(&ftFiletime);
    ullTime = FiletimeToUnixEpoch(&ftFiletime);

    timTimeValue.tv_usec = (long)(ullTime % 1000000L);
    timTimeValue.tv_sec = ((long)(ullTime / 1000000L) % GGD_LONG_MAX);

    #else

    gettimeofday(&timTimeValue, NULL);

    //printf("timTimeValue.tv_sec=%ld\n", timTimeValue.tv_sec);

    timTimeValue.tv_sec %= GGD_LONG_MAX;

    #endif

    lCurrentMillisecond = (((timTimeValue.tv_sec % 1000000L) * 1000L) + (timTimeValue.tv_usec / 1000L)) % GGD_LONG_MAX;
    if(lCurrentMillisecond >= s_lLastMillisecond)
      {
        lDeltaMillisecond = (lCurrentMillisecond - s_lLastMillisecond);
      }
    else
      {
        lDeltaMillisecond = ((GGD_LONG_MAX - lCurrentMillisecond) + s_lLastMillisecond);
      }

    s_lLastMillisecond = lCurrentMillisecond;
    s_lTotalMillisecond = (s_lTotalMillisecond + lDeltaMillisecond) % GGD_LONG_MAX;

    //printf("s_lTotalMillisecond=%ld, s_lLastMillisecond=%ld, lCurrentMillisecond=%ld\n", s_lTotalMillisecond, s_lLastMillisecond, lCurrentMillisecond);

    return s_lTotalMillisecond;
  }

/*---------------------------------------------------------------------------*/
/* 計時休眠 */
int GSTTimeSleep(long lMillisecondValue)
  {
    int iReturnValue;

    #if 0

    #if (defined(WIN32) || defined(_WIN32))

    iReturnValue = 0;
    Sleep(lMillisecondValue);

    #else

    TIMEVALUE timTimeValue;

    /* 設定等候逾時時間，以毫秒單位計算式來計算時間 */
    timTimeValue.tv_sec = lMillisecondValue / 1000;
    timTimeValue.tv_usec = (lMillisecondValue % 1000) * 1000;

    /* 僅僅只有關心時間設置 */
    iReturnValue = select((int)NULL, NULL, NULL, NULL, &timTimeValue);

    #endif

    #else

    iReturnValue = 0;
    usleep(lMillisecondValue);

    #endif

    return iReturnValue;
  }

/*---------------------------------------------------------------------------*/
/* 逾時運算 */
int GSTTimeCheckTimeUp(long lMillisecondValue, long lMillisecondValueLimit)
  {
    long lCurrentMillisecond;

    return ((((lCurrentMillisecond = GSTTimeGetTime()) >= lMillisecondValue) ? (lCurrentMillisecond - lMillisecondValue) : ((GGD_LONG_MAX - lMillisecondValue) + lCurrentMillisecond)) >= lMillisecondValueLimit);
  }

/*---------------------------------------------------------------------------*/
/* 系統時間值修正 */
#if (defined(WIN32) || defined(_WIN32))

static unsigned long long  FiletimeToUnixEpoch(const FILETIME *lpFiletime)
  {
    unsigned long long ullReturnValue = (unsigned long long)(lpFiletime->dwHighDateTime) << 32;

    ullReturnValue |= lpFiletime->dwLowDateTime;

    /* from 100 nano-sec periods to usec */
    ullReturnValue /= 10;

    /* from Win epoch to Unix epoch */
    ullReturnValue -= GST_TIME_DELTA_EPOCH_IN_MICROSECOND;

    return ullReturnValue;
  }

#endif

/*---------------------------------------------------------------------------*/
/* 檔案結束 */

