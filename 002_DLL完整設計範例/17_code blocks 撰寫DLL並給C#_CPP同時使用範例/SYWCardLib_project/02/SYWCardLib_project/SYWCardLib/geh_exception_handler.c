/*
============================================
 檔案名稱：geh_exception_handler.c
 程式功能：Exception Handler
 設計者：Seamus Berloz (軒摩斯貝爾羅)
 版權擁有者：SYRIS Technology Corp.
 最後更新日期：2016/04/27 上午 11:32:29
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

#endif

/* 編譯時期決定是否啟用意外捕捉 */
#ifdef GEH_EXCEPTION_HANDLER_ENABLED
  #include <windows.h>
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 自定義包含檔 =- */
#include "geh_exception_handler.h"

/*---------------------------------------------------------------------------*/
/* 僅供本模組專用之常數宣告定義 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用常數定義宣告 =- */
/* Exception Handler DLL */
#ifndef GEH_EXCEPTION_HANDLER_LIBRARY_FILENAME
  #define GEH_EXCEPTION_HANDLER_LIBRARY_FILENAME "./exchndl.dll"
#endif

/*---------------------------------------------------------------------------*/
/* 僅供本模組專用之巨集宣告定義 */

/*---------------------------------------------------------------------------*/
/* 僅供本模組專用之型態宣告定義 */

/*---------------------------------------------------------------------------*/
/* 僅供本模組專用之變數定義 */

/* 其他全域變數 */

/*---------------------------------------------------------------------------*/
/* 函式原型定義 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 基本公用函數 =- */
void GEHExceptionHandler(void);

/*---------------------------------------------------------------------------*/
/* 分隔取得字串 */
void GEHExceptionHandler(void)
  {
    #ifdef GEH_EXCEPTION_HANDLER_ENABLED

    LoadLibraryA(GEH_EXCEPTION_HANDLER_LIBRARY_FILENAME);

    #endif
  }

/*---------------------------------------------------------------------------*/
/* 檔案結束 */

