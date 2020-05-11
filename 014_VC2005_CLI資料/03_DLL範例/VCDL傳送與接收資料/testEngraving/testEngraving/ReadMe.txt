========================================================================
    MFC 程式庫：testEngraving 專案概觀
========================================================================


AppWizard 已經為您建立了這個 testEngraving DLL。這個 DLL 不僅
示範了使用 MFC 的基本概念，也是您撰寫 DLL 的起點。

這個檔案包含一份摘要，簡要說明構成 testEngraving DLL 的
所有檔案，它們個別的內容。

testEngraving.vcproj
    這是使用應用程式精靈所產生之 VC++ 專案的主要專案檔。 
    它含有產生該檔案之 Visual C++ 的版本資訊，以及有關使用應用程式精靈
    所選取之平台、組態和專案功能的資訊。

testEngraving.h
    這是 DLL 的主要標頭檔。它宣告了 CtestEngravingApp 類別。

testEngraving.cpp
    這是主要 DLL 原始程式檔。它含有 CtestEngravingApp 類別。

testEngraving.rc
    這份清單包含了所有程式要使用的 Microsoft Windows 資源。其中包括了
    儲存在 RES 子目錄下的圖示、點陣圖和游標。您可以直接在     Microsoft Visual C++ 內編輯這個檔案。

res\testEngraving.rc2
    這個檔案包含 Microsoft Visual C++ 編輯無法編輯的資源。您應該將
    所有資源編輯器無法編輯的資源放到這個檔案。

testEngraving.def
    這個檔案含有配合 Microsoft Windows 執行時，必須提供之 DLL 的相關資訊。
    它定義了如 DLL 的名稱和描述這類參數。它也從 DLL 匯出函式。

/////////////////////////////////////////////////////////////////////////////
其他標準檔案：

StdAfx.h, StdAfx.cpp
    這些檔案是用來建置名為 testEngraving.pch 的先行編譯標頭 (PCH) 檔，
    以及名為 StdAfx.obj 的先行編譯型別檔。

Resource.h
    這是標準標頭檔，它定義新的資源 ID。
    Microsoft Visual C++ 會讀取和更新這個檔案。

/////////////////////////////////////////////////////////////////////////////
其他注意事項:

AppWizard 使用 "TODO:" 來指示您應該加入或自訂的原始程式碼部分。

/////////////////////////////////////////////////////////////////////////////
