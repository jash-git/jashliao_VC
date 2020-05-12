// DC2DC.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "DC2DC.h"
#include "DibSection.h"
#include "ToolPath.h"
CObArray ListOfBTool;	//4-step//被取代CArray <CData,CData> gArray;
//CObArray ListOfWTool;	//4-step//被取代CArray <CData,CData> gArray;
bool BCheck,WCheck;
CToolPath *pBData;//5-step
//CToolPath *pWData;//5-step
void AddBObject(CToolPath *g);
//void AddWObject(CToolPath *g);
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CDC2DCApp

BEGIN_MESSAGE_MAP(CDC2DCApp, CWinApp)
	//{{AFX_MSG_MAP(CDC2DCApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDC2DCApp construction

CDC2DCApp::CDC2DCApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CDC2DCApp object
void EXPORTED_DLL_FUNCTION DC2DC (long GetHDC,long w,long h)
{
	int Width,Height;
	int x,y;
	int R,G,B;
	BCheck=false;//為建立資料
	CDibSection testDib;
	CDibSection testDib1;
	testDib.Create(w/15,h/15,24);
	Width=testDib.Width();
	Height=testDib.Height();
	testDib1.Create(Width,Height,24);
	BitBlt(CDibDC(testDib),0,0,w/1,h/1,(HDC)GetHDC,0,0,SRCCOPY);
	pBData=new CToolPath();//建立實體物件
	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)testDib.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q=(BYTE *)testDib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			B=*q1++;
			G=*q1++;
			R=*q1++;
			if((B!=0)&&(G!=0)&&(R!=0))//如果白色設成黑色
			{
				*q++=0;//黑色
				*q++=0;
				*q++=0;
				if(BCheck==true)//當有建立新線段時執行
				{
					BCheck=false;//有白點，所以要先把黑色值紀錄下來
						//pBData->m_CPEnd=pBData->m_CPStart; //把起始點與終點設成同一點
					pBData->m_CPEnd.x=x;
					pBData->m_CPEnd.y=y;
					AddBObject(pBData);//把線段儲存
					pBData=new CToolPath();//建立新資料結構
				}

			}//if-else-------((B==255)&&(G==255)&&(R=255))
			else
			{//當為白點時執行
				if(BCheck==false)//false表示是新的線段開始
				{
					pBData->SetState(1);//設定為黑點旗標
					pBData->m_CPStart.x=x;//把目前的xy紀錄在起始位置
					pBData->m_CPStart.y=y;
					BCheck=true;//true表示已不是新的線段
				}//if-else-------(BCheck==false)
				else
				{//當true時執行
					pBData->m_CPEnd.x=x;
					pBData->m_CPEnd.y=y;
				}//if-else-------(BCheck==false)				
				*q++=255;//白色
				*q++=255;
				*q++=255;
			}//if-else-------((B==255)&&(G==255)&&(R=255))
		}//for------y
		/////////////////////////////////
		if(BCheck==true)
		{
			if((pBData->m_CPEnd.x==0)&&(pBData->m_CPEnd.y==0))
			{
				pBData->m_CPEnd=pBData->m_CPStart;
				AddBObject(pBData);
				BCheck=false;
			}
		}
	}//for------x
	testDib1.SaveBmp("test1.bmp");
	testDib.SaveBmp("test.bmp");
	CFile file1,file2;
    CFileException fe1,fe2;
	char* pFileName1 = "BData.jas";
    if(!file1.Open(pFileName1,CFile::modeCreate | CFile::modeWrite,&fe1))
    {
		fe1.ReportError();
        return;
    }
	CArchive arc1(&file1, CArchive::store);
	ListOfBTool.Serialize(arc1);
    arc1.Flush();
    arc1.Close();
    file1.Close();
	ListOfBTool.RemoveAll(); 
}
void AddBObject(CToolPath *g)//黑點
{
	ListOfBTool.Add(g); 
}
/*
void AddWObject(CToolPath *g)//白點
{
	ListOfWTool.Add(g); 
}
*/
CDC2DCApp theApp;
