// GetMACAddress.cpp : 定義 DLL 的初始化常式。
//

#include "stdafx.h"
#include "GetMACAddress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: 如果這個 DLL 是動態地對 MFC DLL 連結，
//		那麼從這個 DLL 匯出的任何會呼叫
//		MFC 內部的函式，都必須在函式一開頭加上 AFX_MANAGE_STATE
//		巨集。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此處為正常函式主體
//		}
//
//		這個巨集一定要出現在每一個
//		函式中，才能夠呼叫 MFC 的內部。這意味著
//		它必須是函式內的第一個陳述式
//		，甚至必須在任何物件變數宣告前面
//		，因為它們的建構函式可能會產生對 MFC
//		DLL 內部的呼叫。
//
//		請參閱 MFC 技術提示 33 和 58 中的
//		詳細資料。
//

// CGetMACAddressApp

BEGIN_MESSAGE_MAP(CGetMACAddressApp, CWinApp)
END_MESSAGE_MAP()

BSTR EXPORTED_DLL_FUNCTION GetMACAddress ()
{
	//step 03 by jash at 2010/10/20
	bool blnreturn=false;
	CString StrMac;
	char *chrData;
	IP_ADAPTER_INFO AdapterInfo[16];			// Allocate information for up to 16 NICs
	DWORD dwBufLen = sizeof(AdapterInfo);		// Save the memory size of buffer
	try
	{
		DWORD dwStatus = GetAdaptersInfo(			// Call GetAdapterInfo
			AdapterInfo,							// [out] buffer to receive data
			&dwBufLen);								// [in] size of receive data buffer
		assert(dwStatus == ERROR_SUCCESS);			// Verify return value is valid, no buffer overflow

		PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;// Contains pointer to current adapter info
		do {
			StrMac.Format("%02X-%02X-%02X-%02X-%02X-%02X",pAdapterInfo->Address[0],pAdapterInfo->Address[1],pAdapterInfo->Address[2],pAdapterInfo->Address[3],pAdapterInfo->Address[4],pAdapterInfo->Address[5]);
			pAdapterInfo = pAdapterInfo->Next;		// Progress through linked list
		}
		while(pAdapterInfo);						// Terminate if last adapter
	}
	catch(...)
	{
		StrMac="error";
	}
	chrData=StrMac.GetBuffer(0);
	return  SysAllocString((BSTR)chrData);
}
// CGetMACAddressApp 建構

CGetMACAddressApp::CGetMACAddressApp()
{
	// TODO: 在此加入建構程式碼，
	// 將所有重要的初始設定加入 InitInstance 中
}


// 僅有的一個 CGetMACAddressApp 物件

CGetMACAddressApp theApp;


// CGetMACAddressApp 初始設定

BOOL CGetMACAddressApp::InitInstance()
{
	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	return TRUE;
}
