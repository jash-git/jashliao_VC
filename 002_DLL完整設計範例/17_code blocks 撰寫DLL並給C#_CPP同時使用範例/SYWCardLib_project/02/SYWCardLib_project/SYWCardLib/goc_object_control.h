/*
============================================
 檔案名稱：goc_object_control.h
 程式功能：物件控制模組
 設計者：Seamus Berloz (軒摩斯貝爾羅)
 版權擁有者：SYRIS Technology Corp.
 最後更新日期：2015/08/10 上午 11:32:29
 其他資訊：
============================================
*/
/*---------------------------------------------------------------------------*/
/* 定義標頭 */
#ifndef _GOC_OBJECT_CONTROL_H
#define _GOC_OBJECT_CONTROL_H

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

  #ifndef GOCDLLIMPORT
    #define GOCDLLIMPORT __declspec(dllimport)
  #endif

  #ifndef GOCDLLEXPORT
    #define GOCDLLEXPORT __declspec(dllexport)
  #endif

  #ifndef GOCAPI
    #define GOCAPI __cdecl
  #endif

  #ifndef GOCCALLBACK
    #define GOCCALLBACK __cdecl
  #endif

#else

  #define GOCDLLIMPORT
  #define GOCDLLEXPORT

  #define GOCAPI
  #define GOCCALLBACK

#endif

/*---------------------------------------------------------------------------*/
/* 全域常數定義 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用全域巨集宣告定義 =- */
/* 未知物件識別常數宣告定義 */
#define GOC_OBJECT_HAVE_NO_IDENTIFICATION (-1)
/* 物件未設定識別常數宣告定義 */
#define GOC_OBJECT_NEED_TO_SETUP_IDENTIFICATION 0

/*---------------------------------------------------------------------------*/
/* 全域常用巨集宣告定義 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用巨集宣告定義 =- */
/* 物件方法巨集宣告定義 */
#define GOC_METHOD_DECLARE(Method) (GOCAPI * Method) /* Define the functions as pointers */

/* 物件方法結構擷取巨集宣告定義 */
#define GOC_GET_METHOD(Object) (GOCObjectControlGetObjectMethod((GOCObject *)(Object)))
#define GOC_GET_METHOD_IN_TYPE(Object, ObjectMethodType) (ObjectMethodType *)(GOC_GET_METHOD(Object))
#define GOC_GET_PARENT_METHOD(Object) GOCObjectControlGetParentObjectMethod((GOCObject *)(Object))
#define GOC_GET_PARENT_METHOD_IN_TYPE(Object, ParentObjectMethodType) (ParentObjectMethodType *)(GOC_GET_PARENT_METHOD(Object))

/* 物件釋放巨集宣告定義 */
 #define GOC_SAFE_RELEASE(MethodType, Object) \
  { \
    if((Object) != NULL) \
      { \
        ((MethodType *)(GOC_GET_METHOD(Object)))->Release(); \
        (Object) = NULL; \
      } \
  }

/* 物件銷毀巨集宣告定義 */
 #define GOC_SAFE_DESTROY(Object) \
  { \
    if((Object) != NULL) \
      { \
        GOCObjectControlDestroy((GOCObject *)(Object)); \
        (Object) = NULL; \
      } \
  }

/*---------------------------------------------------------------------------*/
/* 全域宣告型態定義 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 物件型態宣告定義 =- */
/* 物件型態宣告定義 */
/* Object */
typedef struct SGOCObject GOCObject;
/* Object Method */
typedef struct SGOCObjectMethod GOCObjectMethod;

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 函式指標型態宣告定義 =- */
typedef int (GOCAPI * GOCOREGISTERPROC)(void);
typedef void (GOCAPI * GOCOCONSTRUCTOR)(GOCObject *pObject, void *lpParmeter);
typedef void (GOCAPI * GOCOMCONSTRUCTOR)(GOCObjectMethod *pObjectMethod, GOCObjectMethod *pParentObjectMethod);
typedef void (GOCAPI * GOCODECONSTRUCTOR)(GOCObject *pObject);

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 資料結構型態宣告定義 =- */
/* 物件註冊資訊資料結構宣告定義 */
typedef struct _GOC_OBJECT_REGISTER_INFORMATION_DATAGRAM_STRUCTURE
  {
    int iParentObjectIdentification;

    /* 物件資訊 */
    int iObjectStructureSize;
    int iObjectMethodStructureSize;

    /* 物件建構處理函式指標 */
    GOCOCONSTRUCTOR pObjectConstructor;
    GOCOMCONSTRUCTOR pObjectMethodConstructor;
    GOCODECONSTRUCTOR pObjectDeconstructor;
  } GOCORIDS, *LPGOCORIDS;

/*---------------------------------------------------------------------------*/
/* 公用物件結構宣告定義 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 物件結構宣告定義 =- */
/* Object */
struct SGOCObject;
/* Object Method */
struct SGOCObjectMethod;

/*---------------------------------------------------------------------------*/
/* 公用物件結構樣版定義 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 物件結構樣版宣告定義 =- */
/* Object Structure */
struct SGOCObject
  {
    /*-----------------------------------------*/
    /* -= 物件識別處理 =- */
    /* 物件識別 */
    int m_iObjectIdentification;

  };

/* Object Method Structure */
struct SGOCObjectMethod
  {
    /*-----------------------------------------*/
    /* -= 建構與解構 =- */
    int GOC_METHOD_DECLARE(Constructor)(void);
    void GOC_METHOD_DECLARE(Deconstructor)(void);

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
  /* 初始化函數 */
  extern GOCDLLEXPORT void GOCAPI GOCObjectControlInitialize(void);
  /* 建立工具函數 */
  extern GOCDLLEXPORT GOCObject * GOCAPI GOCObjectControlCreate(GOCOREGISTERPROC pObjectRegisterProcessor, void *lpParmeter);
  extern GOCDLLEXPORT void GOCAPI GOCObjectControlDestroy(GOCObject *pObject);
  /* 註冊工具函數 */
  extern GOCDLLEXPORT int GOCAPI GOCObjectControlObjectRegister(GOCORIDS *lpObjectRegisterInfoDS);
  extern GOCDLLEXPORT int GOCAPI GOCObjectControlObjectMethodRegister(int iObjectIdentification, GOCObjectMethod *lpObjectMethod);
  /* 建構與解構工具函數 */
  extern GOCDLLEXPORT void GOCAPI GOCObjectControlParentObjectConstructor(GOCObject *pObject, int iObjectIdentification, void *lpParmeter);
  extern GOCDLLEXPORT void GOCAPI GOCObjectControlParentObjectDeconstructor(GOCObject *pObject, int iObjectIdentification);
  /* 存取工具函數 */
  extern GOCDLLEXPORT GOCObjectMethod * GOCAPI GOCObjectControlGetObjectMethod(GOCObject *pObject);
  extern GOCDLLEXPORT GOCObjectMethod * GOCAPI GOCObjectControlGetParentObjectMethod(GOCObject *pObject);
  extern GOCDLLEXPORT GOCObjectMethod * GOCAPI GOCObjectControlGetObjectMethodFromIdentification(int iObjectIdentification);
  extern GOCDLLEXPORT GOCObjectMethod * GOCAPI GOCObjectControlGetParentObjectMethodFromIdentification(int iObjectIdentification);

#ifdef __cplusplus
  }
#endif

/*---------------------------------------------------------------------------*/
/* 定義標頭結束 */
#endif

/*---------------------------------------------------------------------------*/
/* 檔案結束 */

