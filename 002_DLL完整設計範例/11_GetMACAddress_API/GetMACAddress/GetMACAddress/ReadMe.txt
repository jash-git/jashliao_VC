========================================================================
    MFC 程式庫：GetMACAddress 專案概觀
========================================================================


AppWizard 已經為您建立了這個 GetMACAddress DLL。這個 DLL 不僅
示範了使用 MFC 的基本概念，
也是您撰寫 DLL 的起點。

這個檔案包含一份摘要，
簡要說明構成您的 GetMACAddress DLL 的所有檔案，它們個別的內容。

GetMACAddress.vcproj
    這是使用應用程式精靈所產生之 VC++ 專案的主要專案檔。
    它含有產生該檔案之 Visual C++ 的版本資訊，
    以及有關使用應用程式精靈所選取之平台、組態和專案功能的
    資訊。

GetMACAddress.h
    這是 DLL 的主要標頭檔。它宣告了
    CGetMACAddressApp 類別。

GetMACAddress.cpp
    這是主要 DLL 原始程式檔。它含有 CGetMACAddressApp 類別。

GetMACAddress.rc
    這是程式所用的所有 Microsoft Windows 
    資源的列表。其中包括了儲存在 RES 子目錄下的
    圖示、點陣圖和游標。您可以直接在 Microsoft 
    Visual C++ 內編輯這個檔案。

res\GetMACAddress.rc2
    這個檔案含有不是由 Microsoft 
    Visual C++ 內編輯這個檔案。您應該將所有資源編輯器無法編輯的資源
    放到這個檔案。

GetMACAddress.def
    這個檔案含有配合 Microsoft Windows 執行時，
    必須提供之 DLL 的相關資訊。它定義了 
    如 DLL 的名稱和描述這類參數。它也從 DLL
    匯出函式。

/////////////////////////////////////////////////////////////////////////////
其他標準檔案：

StdAfx.h, StdAfx.cpp
    這些檔案是用來建置名為 GetMACAddress.pch 的先行編譯標頭 (PCH) 檔，
    以及名為 StdAfx.obj 的先行編譯型別檔。

Resource.h
    這是標準標頭檔，它定義新的資源 ID。
        Microsoft Visual C++ 會讀取和更新這個檔案。

/////////////////////////////////////////////////////////////////////////////
其他注意事項:

AppWizard 使用 "TODO:" 來指示您應該加入或自訂的
原始程式碼部分。

/////////////////////////////////////////////////////////////////////////////
