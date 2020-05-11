/*
============================================
 檔案名稱：ghld_hallib_define.h
 程式功能：HAL Library Definition
 設計者：Seamus Berloz (軒摩斯貝爾羅)
 版權擁有者：SYRIS Technology Corp.
 最後更新日期：2016/05/06 上午 11:32:29
 其他資訊：
============================================
*/
/*---------------------------------------------------------------------------*/
/* 定義標頭 */
#ifndef _GHLD_HAL_LIBRARY_DEFINITION_H
#define _GHLD_HAL_LIBRARY_DEFINITION_H

/*---------------------------------------------------------------------------*/
/* 包含標頭檔 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 標準包含檔 =- */
#ifdef GHLD_BINDING_HAL_LIBRARY_ENABLED
  #ifdef GHLD_BINDING_HAL_LIBRARY_WITH_SDL
    #include <SDL/SDL.h>
  #endif
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 自定義包含檔 =- */
#include "ggd_global_define.h"

/*---------------------------------------------------------------------------*/
/* 編譯識別常數定義 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用編譯識別常數宣告定義 =- */
/* 硬體抽象層程式庫種類宣告定義 */
#define GHLD_LIBRARY_NONE 0
#define GHLD_LIBRARY_SDL 1

/* 硬體抽象層程式庫致能宣告定義 */
#ifdef GHLD_BINDING_HAL_LIBRARY_ENABLED
  #ifdef GHLD_BINDING_HAL_LIBRARY_WITH_SDL
    #define GHLD_LIBRARY GHLD_LIBRARY_SDL
  #else
    #define GHLD_LIBRARY GHLD_LIBRARY_NONE
  #endif
#endif

/* 系統位元組編排方式識別常數定義 */
/* 搭配 SDL 函式庫定義 */
#if (GHLD_LIBRARY == GHLD_LIBRARY_SDL)
  /* system endian */
  #define GHLD_SYSTEM_BIG_ENDIAN SDL_BIG_ENDIAN
  #define GHLD_SYSTEM_LITTLE_ENDIAN SDL_LIL_ENDIAN
  
  #ifndef GHLD_SYSTEM_ENDIAN
    #if (defined(__hppa__) || defined(__sparc__) || defined(__ARMEB__) || \
        (defined(__MIPS__) && defined(__MISPEB__)) || \
        (defined(__ppc__) || defined(__POWERPC__)  || defined(_M_PPC)) || \
        (defined(__m68k__) || defined(mc68000)  || defined(_M_M68K)))
      
      #define GHLD_SYSTEM_ENDIAN GHLD_SYSTEM_BIG_ENDIAN
    #else
      #define GHLD_SYSTEM_ENDIAN GHLD_SYSTEM_LITTLE_ENDIAN
    #endif
  #endif
  
  #ifndef GHLD_SYSTEM_ENDIAN
    /* ARM embedded system endian */
    #ifdef __ARMEB__
      #define GHLD_SYSTEM_ENDIAN GHLD_SYSTEM_BIG_ENDIAN
    #else
      #define GHLD_SYSTEM_ENDIAN GHLD_SYSTEM_LITTLE_ENDIAN
    #endif
  #endif
#endif

/*---------------------------------------------------------------------------*/
/* 全域常數定義 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用全域常數定義 =- */
/* 搭配 SDL 函式庫定義 */
#if (GHLD_LIBRARY == GHLD_LIBRARY_SDL)
  /* 顯示模式設定旗標巨集常數列舉資料型態宣告定義 */
  #define GHLD_VIDEO_MODE_FLAG_MACRO (SDL_HWSURFACE | SDL_DOUBLEBUF)

#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用常數名稱別名對應 =- */
/* 硬體抽象層常數名稱別名對應 */
/* 搭配 SDL 函式庫定義 */
#if (GHLD_LIBRARY == GHLD_LIBRARY_SDL)
  /* Transparency definitions: These define alpha as the opacity of a surface */
  #define GHLD_PIXEL_ALPHA_OPAQUE SDL_ALPHA_OPAQUE
  #define GHLD_PIXEL_ALPHA_TRANSPARENT SDL_ALPHA_TRANSPARENT
  
  /* color in 16 bit screen color space operation */
  #define GHLD_PIXEL_RED_COLOR_MASK 0x1f
  #define GHLD_PIXEL_GREEN_COLOR_MASK 0x1f
  #define GHLD_PIXEL_BLUE_COLOR_MASK 0x1f
  #define GHLD_PIXEL_RED_COLOR_SHIFT GHLD_PIXEL_BITS_FLAGS_FIELD_RED_COLOR_BIT0
  #define GHLD_PIXEL_GREEN_COLOR_SHIFT GHLD_PIXEL_BITS_FLAGS_FIELD_GREEN_COLOR_BIT0
  #define GHLD_PIXEL_BLUE_COLOR_SHIFT GHLD_PIXEL_BITS_FLAGS_FIELD_BLUE_COLOR_BIT0

#endif

/*---------------------------------------------------------------------------*/
/* 全域常用巨集宣告定義 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用全域巨集宣告定義 =- */
/* 搭配 SDL 函式庫定義 */
#if (GHLD_LIBRARY == GHLD_LIBRARY_SDL)
  /* RGB 三元色 (in 24-bits) 轉 555 巨集定義 */
  #define GHLD_GET_RGB555(RedColor, GreenColor, BlueColor) ((((((DWORD)(RedColor)) >> 3) & 0x1f) << 10) | (((((DWORD)(GreenColor)) >> 3) & 0x1f) << 5) | ((((DWORD)(BlueColor)) >> 3) & 0x1f))
  /* RGB 三元色 (in 24-bits) 轉 565 巨集定義 */
  #define GHLD_GET_RGB565(RedColor, GreenColor, BlueColor) ((((((DWORD)(RedColor)) >> 3) & 0x1f) << 11) | (((((DWORD)(GreenColor)) >> 3) & 0x3f) << 5) | ((((DWORD)(BlueColor)) >> 3) & 0x1f))
  
  /* color transformation to 16 bit color space */
  #define GHLD_COLORS_FROM_RGB555(RedColor, GreenColor, BlueColor) (((((DWORD)(RedColor)) << 10) & 0x7c00) | ((((DWORD)(GreenColor)) << 5) & 0x3e0) | (((DWORD)(BlueColor)) & 0x1f))
  #define GHLD_COLORS_FROM_RGB565(RedColor, GreenColor, BlueColor) (((((DWORD)(RedColor)) << 11) & 0xf800) | ((((DWORD)(GreenColor)) << 5) & 0x7e0) | (((DWORD)(BlueColor)) & 0x1f))
  #define GHLD_COLORS_FROM_RGB888(RedColor, GreenColor, BlueColor) GHLD_GET_RGB555(RedColor, GreenColor, BlueColor)
  
#endif

/*---------------------------------------------------------------------------*/
/* 全域宣告型態定義 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 型態別名宣告定義 =- */
/* 搭配 SDL 函式庫定義 */
#if (GHLD_LIBRARY == GHLD_LIBRARY_SDL)
  /* SDL 結構名稱別名對應 */
  #define SDLRECT SDL_Rect
  #define SDLEVENT SDL_Event
  #define SDLTHREAD SDL_Thread
  #define SDLSURFACE SDL_Surface
  #define SDLVIDEOINFO SDL_VideoInfo
  #define SDLAUDIOSPEC SDL_AudioSpec
  #define SDLAUDIOCONVERTER SDL_AudioCVT
  
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用常數列舉資料型態宣告定義 =- */
/* 搭配 SDL 函式庫定義 */
#if (GHLD_LIBRARY == GHLD_LIBRARY_SDL)
  
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用旗標欄位常數列舉資料型態宣告定義 =- */
/* 搭配 SDL 函式庫定義 */
#if (GHLD_LIBRARY == GHLD_LIBRARY_SDL)
  /* 像素位元旗標常數列舉型態宣告定義 */
  enum _GHLD_PIXEL_BITS_FLAGS_FIELD_DEFINITION
    {
      /* 藍色顏色值域 */
      GHLD_PIXEL_BITS_FLAGS_FIELD_BLUE_COLOR_BIT0,
      GHLD_PIXEL_BITS_FLAGS_FIELD_BLUE_COLOR_BIT1,
      GHLD_PIXEL_BITS_FLAGS_FIELD_BLUE_COLOR_BIT2,
      GHLD_PIXEL_BITS_FLAGS_FIELD_BLUE_COLOR_BIT3,
      GHLD_PIXEL_BITS_FLAGS_FIELD_BLUE_COLOR_BIT4,
      
      /* 綠色顏色值域 */
      GHLD_PIXEL_BITS_FLAGS_FIELD_GREEN_COLOR_BIT0,
      GHLD_PIXEL_BITS_FLAGS_FIELD_GREEN_COLOR_BIT1,
      GHLD_PIXEL_BITS_FLAGS_FIELD_GREEN_COLOR_BIT2,
      GHLD_PIXEL_BITS_FLAGS_FIELD_GREEN_COLOR_BIT3,
      GHLD_PIXEL_BITS_FLAGS_FIELD_GREEN_COLOR_BIT4,
      
      /* 紅色顏色值域 */
      GHLD_PIXEL_BITS_FLAGS_FIELD_RED_COLOR_BIT0,
      GHLD_PIXEL_BITS_FLAGS_FIELD_RED_COLOR_BIT1,
      GHLD_PIXEL_BITS_FLAGS_FIELD_RED_COLOR_BIT2,
      GHLD_PIXEL_BITS_FLAGS_FIELD_RED_COLOR_BIT3,
      GHLD_PIXEL_BITS_FLAGS_FIELD_RED_COLOR_BIT4,
      
      GHLD_PIXEL_BITS_FLAGS_FIELD_AMOUNT = 15
    };
  
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用旗標常數列舉型態別名宣告定義 =- */
/* 搭配 SDL 函式庫定義 */
#if (GHLD_LIBRARY == GHLD_LIBRARY_SDL)
  /* 像素值域遮罩常數列舉型態宣告定義 */
  enum _GHLD_PIXEL_MASK_DEFINITION
    {
      GHLD_PIXEL_RED_COLOR_FIELD_MASK = GGD_GET_FIELD_MASK(GHLD_PIXEL_RED_COLOR_MASK, GHLD_PIXEL_BITS_FLAGS_FIELD_RED_COLOR_BIT0),
      GHLD_PIXEL_GREEN_COLOR_FIELD_MASK = GGD_GET_FIELD_MASK(GHLD_PIXEL_GREEN_COLOR_MASK, GHLD_PIXEL_BITS_FLAGS_FIELD_GREEN_COLOR_BIT0),
      GHLD_PIXEL_BLUE_COLOR_FIELD_MASK = GGD_GET_FIELD_MASK(GHLD_PIXEL_BLUE_COLOR_MASK, GHLD_PIXEL_BITS_FLAGS_FIELD_BLUE_COLOR_BIT0),
      
    };
  
#endif

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 常用旗標巨集常數列舉資料型態宣告定義 =- */
/* 搭配 SDL 函式庫定義 */
#if (GHLD_LIBRARY == GHLD_LIBRARY_SDL)
  
#endif

/*---------------------------------------------------------------------------*/
/* 公用變數宣告 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 全域公用變數宣告定義 =- */
/* 搭配 SDL 函式庫定義 */
#if (GHLD_LIBRARY == GHLD_LIBRARY_SDL)
  
#endif

/*---------------------------------------------------------------------------*/
/* 公用物件類別宣告 */

/*---------------------------------------------------------------------------*/
/* 公用物件類別樣版 */

/*---------------------------------------------------------------------------*/
/* 公用函數宣告 */
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
/* -= 函數別名宣告定義 =- */
/* 搭配 SDL 函式庫定義 */
#if (GHLD_LIBRARY == GHLD_LIBRARY_SDL)
  /* SDL 函數名稱別名對應 */
  /* SDL 運作訊息處理相關 */
  #define SDLSetError SDL_SetError
  #define SDLGetError SDL_GetError
  /* SDL 時間運作處理相關 */
  #define SDLGetTicks SDL_GetTicks
  #define SDLDelay SDL_Delay
  /* 動態程式庫處理相關 */
  #define SDLLoadObject SDL_LoadObject
  #define SDLUnloadObject SDL_UnloadObject
  #define SDLLoadFunction SDL_LoadFunction
  /* SDL 多執行緒處理相關 */
  #define SDLCreateThread SDL_CreateThread
  #define SDLThreadID SDL_ThreadID
  #define SDLGetThreadID SDL_GetThreadID
  #define SDLWaitThread SDL_WaitThread
  #define SDLKillThread SDL_KillThread
  /* SDL 運作初始化處理相關 */
  #define SDLInitialize SDL_Init
  #define SDLQuit SDL_Quit
  #define SDLSubSystemInitialize SDL_InitSubSystem
  #define SDLWasInitial SDL_WasInit
  /* SDL 事件運作處理相關 */
  #define SDLPollEvent SDL_PollEvent
  /* SDL 週邊輸入運作處理相關 */
  #define SDLGetKeyState SDL_GetKeyState
  #define SDLWarpMouse SDL_WarpMouse
  #define SDLShowCursor SDL_ShowCursor
  /* SDL 顯示運作處理相關 */
  #define SDLGetVideoInfo SDL_GetVideoInfo
  #define SDLVideoDriverName SDL_VideoDriverName
  #define SDLVideoModeOK SDL_VideoModeOK
  #define SDLSetVideoMode SDL_SetVideoMode
  /* SDL 繪圖運作處理相關 */
  #define SDLCreateRGBSurface SDL_CreateRGBSurface
  #define SDLFreeSurface SDL_FreeSurface
  #define SDLDisplayFormat SDL_DisplayFormat
  #define SDLDisplayFormatAlpha SDL_DisplayFormatAlpha
  #define SDLSetAlpha SDL_SetAlpha
  #define SDLSetColorKey SDL_SetColorKey
  #define SDLBlitSurface SDL_BlitSurface
  #define SDLFillRect SDL_FillRect
  #define SDLMapRGB SDL_MapRGB
  #define SDLFlip SDL_Flip
  #define SDLMustLock SDL_MUSTLOCK
  #define SDLLockSurface SDL_LockSurface
  #define SDLUnlockSurface SDL_UnlockSurface
  /* SDL 視窗管理相關 */
  #define SDLWMGetWindowInfo SDL_GetWMInfo
  #define SDLWMSetCaption SDL_WM_SetCaption
  #define SDLWMToggleFullScreen SDL_WM_ToggleFullScreen
  /* SDL 聲音處理相關 */
  #define SDLOpenAudio SDL_OpenAudio
  #define SDLCloseAudio SDL_CloseAudio
  #define SDLPauseAudio SDL_PauseAudio 
  #define SDLLockAudio SDL_LockAudio
  #define SDLUnlockAudio SDL_UnlockAudio
  #define SDLLoadWaveWithSDLRW SDL_LoadWAV_RW
  #define SDLFreeWave SDL_FreeWAV
  #define SDLMixAudio SDL_MixAudio
  #define SDLConvertAudio SDL_ConvertAudio
  #define SDLBuildAudioConverter SDL_BuildAudioCVT
  /* SDL 特化讀寫處理相關 */
  #define SDLRWFromFile SDL_RWFromFile
  #define SDLRWFromMem SDL_RWFromMem
  #define SDLRWTell SDL_RWtell
  #define SDLRWRead SDL_RWread
  #define SDLRWClose SDL_RWclose
  #define SDLRWSeek SDL_RWseek
  /* SDL 原生字節搭配特化讀寫處理相關 */
  #define SDLReadLE32 SDL_ReadLE32
  
#endif

/*---------------------------------------------------------------------------*/
/* 定義標頭結束 */
#endif

/*---------------------------------------------------------------------------*/
/* 檔案結束 */

