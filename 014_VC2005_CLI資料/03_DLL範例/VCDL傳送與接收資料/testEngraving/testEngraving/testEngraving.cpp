// testEngraving.cpp : 定義 DLL 的初始化常式。
//

#include "stdafx.h"
#include "testEngraving.h"

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


// CtestEngravingApp

BEGIN_MESSAGE_MAP(CtestEngravingApp, CWinApp)
END_MESSAGE_MAP()


// CtestEngravingApp 建構
void EXPORTED_DLL_FUNCTION GetValue1(EngarveElement *p,long number)
{
	FILE *p1;
	int k;
	EE=p;
	n=number;
	p1=fopen("data.txt","w");
	for(k=0;k<number;k++)
		fprintf(p1,"%d\t%d\t%f\t%f\t%f\t%f\t%f\t%f\n",(EE+k)->CCW ,(EE+k)->Type,(EE+k)->X1,(EE+k)->Y1,(EE+k)->Z1,(EE+k)->X2,(EE+k)->Y2,(EE+k)->Z2 );
	fclose(p1);
}
long EXPORTED_DLL_FUNCTION SendValue1(EngarveElement *p)
{
	int k;
	FILE *p1;
	p1=fopen("data1.txt","w");
	for(k=0;k<n;k++)
	{
		(EE+k)->CCW+=1;
		(p+k)->CCW=(EE+k)->CCW;
		(EE+k)->Type+=1;
		(p+k)->Type=(EE+k)->Type;
		(EE+k)->X1+=1;
		(p+k)->X1=(EE+k)->X1;
		(EE+k)->Y1+=1;
		(p+k)->Y1=(EE+k)->Y1;
		(EE+k)->Z1+=1;
		(p+k)->Z1=(EE+k)->Z1;
		(EE+k)->X2+=1;
		(p+k)->X2=(EE+k)->X2;
		(EE+k)->Y2+=1;
		(p+k)->Y2=(EE+k)->Y2;
		(EE+k)->Z2+=1;
		(p+k)->Z2=(EE+k)->Z2;
		fprintf(p1,"%d\t%d\t%f\t%f\t%f\t%f\t%f\t%f\n",(EE+k)->CCW ,(EE+k)->Type,(EE+k)->X1,(EE+k)->Y1,(EE+k)->Z1,(EE+k)->X2,(EE+k)->Y2,(EE+k)->Z2 );
	}
	fclose(p1);
	return n;
}
CtestEngravingApp::CtestEngravingApp()
{
	// TODO: 在此加入建構程式碼，
	// 將所有重要的初始設定加入 InitInstance 中
}


// 僅有的一個 CtestEngravingApp 物件

CtestEngravingApp theApp;


// CtestEngravingApp 初始設定

BOOL CtestEngravingApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
