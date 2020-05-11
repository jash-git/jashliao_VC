/*
============================================
 檔案名稱：gwc_control.h
 程式功能：wCard 控制工具函數庫
 設計者：Seamus Berloz (軒摩斯貝爾羅)
 版權擁有者：SYRIS Technology Corp.
 最後更新日期：2016/05/31 上午 11:32:29
 其他資訊：
============================================
*/
/*---------------------------------------------------------------------------*/
/* 定義標頭 */
#ifndef _GWC_CONTROL_H
#define _GWC_CONTROL_H

/*---------------------------------------------------------------------------*/
/* 包含標頭檔 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 自定義包含檔 =- */
#include "ggd_global_define.h"

/*---------------------------------------------------------------------------*/
/* 編譯識別常數定義 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用編譯識別常數定義 =- */
/* 提供一些編譯器特殊的函式修飾關鍵字 */
#if defined(WIN32) || defined(_WIN32)

  #ifndef GWCDLLIMPORT
    #define GWCDLLIMPORT __declspec(dllimport)
  #endif

  #ifndef GWCDLLEXPORT
    #define GWCDLLEXPORT __declspec(dllexport)
  #endif

  #ifndef GWCAPI
    #define GWCAPI __cdecl
  #endif

  #ifndef GWCCALLBACK
    #define GWCCALLBACK __cdecl
  #endif

#else

  #define GWCDLLIMPORT
  #define GWCDLLEXPORT

  #define GWCAPI
  #define GWCCALLBACK

#endif

/*---------------------------------------------------------------------------*/
/* 全域常數定義 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用常數定義宣告 =- */
/* 資料資訊長度常數定義宣告 */
#define GWC_AES_KEY_LENGTH_MAXIMUM 16
#define GWC_DOOR_NAME_LENGTH_MAXIMUM 8
#define GWC_SCRAMBLER_CODE_LENGTH_MAXIMUM 4
#define GWC_USER_AES_KEY_LENGTH_MAXIMUM 16
#define GWC_USER_ACCESS_KEY_LENGTH_MAXIMUM 6
#define GWC_USER_PASSWORD_CODE_LENGTH_MAXIMUM 8
#define GWC_USER_UNIQUE_IDENTIFIER_LENGTH_MAXIMUM 8

//#define GWC_DOOR_GROUP_CODE_STRING_LENGTH_MAXIMUM 32

/*---------------------------------------------------------------------------*/
/* 全域常用巨集宣告定義 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用巨集宣告定義 =- */
/* 銷毀巨集宣告定義 */
 #define GWC_SAFE_DESTROY(ControlDS) \
  { \
    if((ControlDS) != NULL) \
      { \
        GWCDestroy(ControlDS); \
        (ControlDS) = NULL; \
      } \
  }

/* Reader 銷毀巨集宣告定義 */
 #define GWC_SAFE_READER_DESTROY(ReaderDS) \
  { \
    if((ReaderDS) != NULL) \
      { \
        GWCReaderDestroy(ReaderDS); \
        (ReaderDS) = NULL; \
      } \
  }

/* WCard 銷毀巨集宣告定義 */
 #define GWC_SAFE_WCARD_DESTROY(WCardDS) \
  { \
    if((WCardDS) != NULL) \
      { \
        GWCCardDestroy(WCardDS); \
        (WCardDS) = NULL; \
      } \
  }

/*---------------------------------------------------------------------------*/
/* 全域宣告型態定義 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 資料結構型態宣告定義 =- */
/* WCard 資料結構型態宣告定義 */
typedef struct _GWC_WCARD_DATAGRAM_STRUCTURE GWCARDDS;
/* Reader 資料結構型態宣告定義 */
typedef struct _GWC_READER_DATAGRAM_STRUCTURE GWCREADERDS;
/* Control 資料結構型態宣告定義 */
typedef struct _GWC_CONTROL_DATAGRAM_STRUCTURE GWCONTROLDS;

/* WCard Fetch Door Name 資料結構型態宣告定義 */
typedef struct _GWC_WCARD_FETCH_DOOR_NAME_DATAGRAM_STRUCTURE GWCARDFDNDS;
/* WCard Fetch Door Access 資料結構型態宣告定義 */
typedef struct _GWC_WCARD_FETCH_DOOR_ACCESS_DATAGRAM_STRUCTURE GWCARDFDADS;

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 函式指標型態宣告定義 =- */
/* 階段狀態回呼函式指標型態宣告定義 */
typedef void (GWCCALLBACK * GWCOPSTAGECB)(void *lpOPStageCBParameter);

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用常數列舉資料型態宣告定義 =- */
/* 狀態常數列舉資料型態宣告定義 */
enum _GWC_STATUS_DEFINITION
  {
    GWC_STATUS_OK,
    GWC_STATUS_BUSY,
    GWC_STATUS_SHUTDOWN,

    GWC_STATUS_ERROR,
    GWC_STATUS_NO_DEVICE,
    GWC_STATUS_ERROR_DEVICE,
    GWC_STATUS_INTERNAL_ERROR,

    GWC_STATUS_AMOUNT
  };

/* Reader 狀態常數列舉資料型態宣告定義 */
enum _GWC_READER_STATUS_DEFINITION
  {
    GWC_READER_STATUS_OK,
    GWC_READER_STATUS_BUSY,

    GWC_READER_STATUS_ERROR,
    GWC_READER_STATUS_TIMEOUT,
    GWC_READER_STATUS_NO_CARD,
    GWC_READER_STATUS_ACCESS_DENY,
    GWC_READER_STATUS_FORMAT_ERROR,
    GWC_READER_STATUS_INTERNAL_ERROR,

    GWC_READER_STATUS_AMOUNT
  };

/* WCard 用途常數列舉定義宣告 */
enum _GWC_WCARD_USAGE_DEFINITION
  {
    /*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
    /* -= 用途列表 =- */
    /*-----------------------------------------*/
    /* 未知 */
    GWC_WCARD_USAGE_UNKNOWN,

    /*-----------------------------------------*/
    /* 常用用途 */
    GWC_WCARD_USAGE_FOR_NORMAL,
    GWC_WCARD_USAGE_FOR_PATROL,

    /*-----------------------------------------*/
    /* 特殊用途 */
    GWC_WCARD_USAGE_FOR_SETUP = 15,

    /*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
    /* -= 用途代碼總數 =- */
    GWC_WCARD_USAGE_AMOUNT
  };

/* WCard 類型常數列舉定義宣告 */
enum _GWC_WCARD_TYPE_DEFINITION
  {
    /*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
    /* -= 類型列表 =- */
    /*-----------------------------------------*/
    /* 未知 */
    GWC_WCARD_TYPE_UNKNOWN,

    /*-----------------------------------------*/
    /* 常用類型 */
    GWC_WCARD_TYPE_NORMAL,
    GWC_WCARD_TYPE_VIP,
    GWC_WCARD_TYPE_ADMIN,

    /*-----------------------------------------*/
    /* 特殊類型 */
    GWC_WCARD_TYPE_DATETIME_SETUP = 14,
    GWC_WCARD_TYPE_AES_KEY_SETUP = 15,

    /*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
    /* -= 類型代碼總數 =- */
    GWC_WCARD_TYPE_AMOUNT
  };

/* WCard 配置常數列舉定義宣告 */
enum _GWC_WCARD_CONFIGURATION_DEFINITION
  {
    /*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
    /* -= 配置列表 =- */
    GWC_WCARD_CONFIGURATION_64_DOOR_1_NAME,
    GWC_WCARD_CONFIGURATION_64_DOOR_WITH_PASSWORD,
    GWC_WCARD_CONFIGURATION_128_DOOR_OR_OTHERS,
    GWC_WCARD_CONFIGURATION_256_DOOR_3_NAME_WITH_PASSWORD,
    GWC_WCARD_CONFIGURATION_320_DOOR_2_NAME_WITH_PASSWORD,
    GWC_WCARD_CONFIGURATION_384_DOOR_1_NAME_WITH_PASSWORD,
    GWC_WCARD_CONFIGURATION_384_DOOR_2_NAME,
    GWC_WCARD_CONFIGURATION_768_DOOR_1_NAME_WITH_PASSWORD,
    GWC_WCARD_CONFIGURATION_768_DOOR_2_NAME,
    GWC_WCARD_CONFIGURATION_1152_DOOR_1_NAME_WITH_PASSWORD,
    GWC_WCARD_CONFIGURATION_1152_DOOR_2_NAME,

    /*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
    /* -= 類型代碼總數 =- */
    GWC_WCARD_CONFIGURATION_AMOUNT
  };

/*---------------------------------------------------------------------------*/
/* 公用變數宣告 */

/*---------------------------------------------------------------------------*/
/* 公用函數宣告 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用公用函數宣告定義 =- */
/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
  extern "C" {
#endif

  /* 初始與終止 */
  extern GWCDLLEXPORT int GWCAPI GWCInitialize(void);//配置記憶體
  extern GWCDLLEXPORT void GWCAPI GWCTerminate(void);//釋放記憶體

  /* 控制函數 */
  extern GWCDLLEXPORT GWCONTROLDS * GWCAPI GWCCreate(void);//建立控制實體變數
  extern GWCDLLEXPORT void GWCAPI GWCDestroy(GWCONTROLDS *lpControlDS);
  extern GWCDLLEXPORT int GWCAPI GWCStart(GWCONTROLDS *lpControlDS);//建立工作執行序
  extern GWCDLLEXPORT int GWCAPI GWCStop(GWCONTROLDS *lpControlDS);//關閉工作執行序
  extern GWCDLLEXPORT int GWCAPI GWCGetStatus(GWCONTROLDS *lpControlDS);
  extern GWCDLLEXPORT int GWCAPI GWCSelect(GWCONTROLDS *lpControlDS, GWCREADERDS *lpReaderDS, const char *lpSerialNumber);
  extern GWCDLLEXPORT int GWCAPI GWCReadCard(GWCONTROLDS *lpControlDS, GWCOPSTAGECB pOPStageCBFunction, void *lpOPStageCBFunctionParameter);
  extern GWCDLLEXPORT int GWCAPI GWCWriteCard(GWCONTROLDS *lpControlDS, GWCOPSTAGECB pOPStageCBFunction, void *lpOPStageCBFunctionParameter);

  /* Reader 函數 */
  extern GWCDLLEXPORT GWCREADERDS * GWCAPI GWCReaderCreate(void);
  extern GWCDLLEXPORT void GWCAPI GWCReaderDestroy(GWCREADERDS *lpReaderDS);
  extern GWCDLLEXPORT int GWCAPI GWCReaderGetStatus(GWCREADERDS *lpReaderDS);
  extern GWCDLLEXPORT int GWCAPI GWCReaderGetCard(GWCREADERDS *lpReaderDS, GWCARDDS *lpWCardDS);
  extern GWCDLLEXPORT int GWCAPI GWCReaderBindCard(GWCREADERDS *lpReaderDS, GWCARDDS *lpWCardDS, BYTE *lpAccessKey, BYTE *lpNewAccessKey, BYTE *lpAESKey, int iOffset);

  /* WCard 函數 */
  extern GWCDLLEXPORT GWCARDDS * GWCAPI GWCCardCreate(void);
  extern GWCDLLEXPORT void GWCAPI GWCCardDestroy(GWCARDDS *lpWCardDS);
  extern GWCDLLEXPORT int GWCAPI GWCCardSetType(GWCARDDS *lpWCardDS, int iType);
  extern GWCDLLEXPORT int GWCAPI GWCCardSetUsage(GWCARDDS *lpWCardDS, int iUsage);
  extern GWCDLLEXPORT int GWCAPI GWCCardSetConfiguration(GWCARDDS *lpWCardDS, int iConfiguration);
  extern GWCDLLEXPORT int GWCAPI GWCCardSetAdjustDateTime(GWCARDDS *lpWCardDS, int iAdjustDateTime);
  extern GWCDLLEXPORT int GWCAPI GWCCardSetPassThroughCounter(GWCARDDS *lpWCardDS, int iPassThroughCounter);
  extern GWCDLLEXPORT int GWCAPI GWCCardSetHolidayWeekProgramValue(GWCARDDS *lpWCardDS, int iHolidayWeekProgramValue);
  extern GWCDLLEXPORT int GWCAPI GWCCardSetExpirationDate(GWCARDDS *lpWCardDS, int iStartUpExpirationDate, int iEndleExpirationDate);
  extern GWCDLLEXPORT int GWCAPI GWCCardSetPassThroughTimeRange(GWCARDDS *lpWCardDS, int iFirstPassThroughTimeRange, int iSecondPassThroughTimeRange, int iThirdPassThroughTimeRange);
  extern GWCDLLEXPORT int GWCAPI GWCCardGetType(GWCARDDS *lpWCardDS);
  extern GWCDLLEXPORT int GWCAPI GWCCardGetUsage(GWCARDDS *lpWCardDS);
  extern GWCDLLEXPORT int GWCAPI GWCCardGetConfiguration(GWCARDDS *lpWCardDS);
  extern GWCDLLEXPORT int GWCAPI GWCCardGetAdjustDateTime(GWCARDDS *lpWCardDS);
  extern GWCDLLEXPORT int GWCAPI GWCCardGetPassThroughCounter(GWCARDDS *lpWCardDS);
  extern GWCDLLEXPORT int GWCAPI GWCCardGetHolidayWeekProgramValue(GWCARDDS *lpWCardDS);
  extern GWCDLLEXPORT int GWCAPI GWCCardGetExpirationDate(GWCARDDS *lpWCardDS, int *lpStartUpExpirationDate, int *lpEndleExpirationDate);
  extern GWCDLLEXPORT int GWCAPI GWCCardGetPassThroughTimeRange(GWCARDDS *lpWCardDS, int *lpFirstPassThroughTimeRange, int *lpSecondPassThroughTimeRange, int *lpThirdPassThroughTimeRange);
  extern GWCDLLEXPORT int GWCAPI GWCCardSetScramblerCode(GWCARDDS *lpWCardDS, BYTE *lpScramblerCode);
  extern GWCDLLEXPORT int GWCAPI GWCCardSetUserAESKey(GWCARDDS *lpWCardDS, BYTE *lpUserAESKey);
  extern GWCDLLEXPORT int GWCAPI GWCCardSetUserPasswordCode(GWCARDDS *lpWCardDS, BYTE *lpUserPasswordCode);
  extern GWCDLLEXPORT int GWCAPI GWCCardSetUserUniqueIdentifier(GWCARDDS *lpWCardDS, BYTE *lpUserUniqueIdentifier);
  extern GWCDLLEXPORT BYTE GWCAPI * GWCCardGetScramblerCode(GWCARDDS *lpWCardDS, BYTE *lpScramblerCode);
  extern GWCDLLEXPORT BYTE GWCAPI * GWCCardGetUserAESKey(GWCARDDS *lpWCardDS, BYTE *lpUserAESKey);
  extern GWCDLLEXPORT BYTE GWCAPI * GWCCardGetUserPasswordCode(GWCARDDS *lpWCardDS, BYTE *lpUserPasswordCode);
  extern GWCDLLEXPORT BYTE GWCAPI * GWCCardGetUserUniqueIdentifier(GWCARDDS *lpWCardDS, BYTE *lpUserUniqueIdentifier);
  extern GWCDLLEXPORT int GWCAPI GWCCardAddDoorName(GWCARDDS *lpWCardDS, BYTE *lpName, int iLength);
  extern GWCDLLEXPORT int GWCAPI GWCCardFetchFirstDoorName(GWCARDDS *lpWCardDS, GWCARDFDNDS **lpWCardFetchDoorNameDS, BYTE *lpName);
  extern GWCDLLEXPORT int GWCAPI GWCCardFetchNextDoorName(GWCARDFDNDS *lpWCardFetchDoorNameDS, BYTE *lpName);
  extern GWCDLLEXPORT void GWCAPI GWCCardFetchCloseDoorName(GWCARDFDNDS *lpWCardFetchDoorNameDS);
  extern GWCDLLEXPORT int GWCAPI GWCCardAddDoorAccess(GWCARDDS *lpWCardDS, int iNumber);
  extern GWCDLLEXPORT int GWCAPI GWCCardFetchFirstDoorAccess(GWCARDDS *lpWCardDS, GWCARDFDADS **lpWCardFetchDoorAccessDS);
  extern GWCDLLEXPORT int GWCAPI GWCCardFetchNextDoorAccess(GWCARDFDADS *lpWCardFetchDoorAccessDS);
  extern GWCDLLEXPORT void GWCAPI GWCCardFetchCloseDoorAccess(GWCARDFDADS *lpWCardFetchDoorAccessDS);

#ifdef __cplusplus
  }
#endif

/*---------------------------------------------------------------------------*/
/* 定義標頭結束 */
#endif

/*---------------------------------------------------------------------------*/
/* 檔案結束 */

