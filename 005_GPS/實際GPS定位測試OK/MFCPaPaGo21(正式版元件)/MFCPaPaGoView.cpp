// MFCPaPaGoView.cpp : implementation of the CMFCPaPaGoView class
//

#include "stdafx.h"
#include "MFCPaPaGo.h"
#include <cstdlib>
#include <ctime>
#include <vfw.h>//播放聲音1
#include "MFCPaPaGoDoc.h"
#include "MFCPaPaGoView.h"
#include "DlgSetTimer.h"
#include "MainFrm.h"
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//////////////////////////////////////
struct SiteInformation//存放檔案內容結構體
{
	long lngNO;
	char strSiteName[100];
	long lngX;
	long lngY;
};
FILE *pfdata=NULL;//讀檔旗標
struct SiteInformation *pSiteInformation;//要動態配置記憶體的結構體指標變數
long lngMarrValue=0;//記錄筆數
long lngBufer=0;//指定動態陣列旗標
long lngNO;//SiteInformation的站存記憶體1
char strSiteName[100]={"\0"};//SiteInformation的站存記憶體2
long lngX=0;//SiteInformation的站存記憶體3
long lngY=0;//SiteInformation的站存記憶體4 
//////////////////////////////////////
HWND m_hwndMCI;//播放聲音2
//////////////////////////////////////
long scrX,scrY;
bool blnchange=false;
FILE *p;
CString strdata[30];
CString strInPut;
FILE *fp_point;
bool blnrtcheck=false;
long lngRouteEndX=0;
long lngRouteEndY=0;
/////////////////////////////////////
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IMapObject = {0x28A525FE,0x7DD2,0x4667,{0xA5,0x85,0x79,0x0D,0x66,0x65,0x36,0x3F}};


const IID LIBID_PPGSDK50Lib = {0x4CC21C03,0x04FC,0x4CA6,{0x8F,0x6E,0xE0,0xD4,0x07,0xC7,0x02,0x20}};


const CLSID CLSID_MapObject = {0xA83D2D9C,0x1FFE,0x4044,{0x8B,0x9D,0xD4,0xCB,0x17,0x3A,0xA1,0x63}};


#ifdef __cplusplus
}
#endif
/////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// CMFCPaPaGoView

IMPLEMENT_DYNCREATE(CMFCPaPaGoView, CView)

BEGIN_MESSAGE_MAP(CMFCPaPaGoView, CView)
	//{{AFX_MSG_MAP(CMFCPaPaGoView)
	ON_COMMAND(ID_LoadMap, OnLoadMap)
	ON_COMMAND(ID_UPMAP, OnUpmap)
	ON_COMMAND(ID_DOWNMAP, OnDownmap)
	ON_COMMAND(ID_LEFTMAP, OnLeftmap)
	ON_COMMAND(ID_RIGHTMAP, OnRightmap)
	ON_COMMAND(ID_CENTER, OnCenter)
	ON_WM_TIMER()
	ON_COMMAND(ID_RUNTIMER, OnRuntimer)
	ON_COMMAND(ID_DirectBMP, OnDirectBMP)
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_Routing, OnRouting)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCPaPaGoView construction/destruction

CMFCPaPaGoView::CMFCPaPaGoView()
{
	// TODO: add construction code here
	///////////////////////////////3_start
	hr=::CoInitialize(NULL);
	if(FAILED(hr))
	{
		MessageBox("failed to initialize COM");
	}
	else
	{
		hr=::CoCreateInstance(CLSID_MapObject,NULL,CLSCTX_INPROC_SERVER,IID_IMapObject,(LPVOID *)&gpMapEngine); 
		if(FAILED(hr))
		{
			MessageBox("Coule not create Map Object");
		}
	}
	hrRoute=::CoInitialize(NULL);
	if(FAILED(hrRoute))
	{
		MessageBox("failed to initialize COM-Route");
	}
	else
	{
		hrRoute=::CoCreateInstance(CLSID_MapObject,NULL,CLSCTX_INPROC_SERVER,IID_IMapObject,(LPVOID *)&gpMapEngineRoute); 
		if(FAILED(hr))
		{
			MessageBox("Coule not create Map Object-Route");
		}
	}
	///////////////////////////////3_end
	bnlShowBmp=false;
	blnLoadMap=false;
	lngMoveIndex=-1;
	fp_point=fopen("point.txt","w");
	//////////////////////////////////////
	FILE *fpb1,*fpb2;
	fpb1=fopen("rt.txt","w");
	fpb2=fopen("rt1.txt","w");
	//總距離 740 m  
	fprintf(fpb1,"%s\n","總距離 740 m");
	fprintf(fpb2,"%s\n","總距離 740 m");
	fclose(fpb1);
	fclose(fpb2);
	//////////////////////////////////////
}

CMFCPaPaGoView::~CMFCPaPaGoView()
{
	//////////////////////4_start 
	gpMapEngine->Release();
	gpMapEngineRoute->Release();
	::CoUninitialize();
	gpMapEngine=0; 
	//////////////////////4_end
}

BOOL CMFCPaPaGoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs 
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCPaPaGoView drawing

void CMFCPaPaGoView::OnDraw(CDC* pDC)
{
	CMFCPaPaGoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CClientDC dc(this);
	//////////////////////////
	HBITMAP ghBitmapPPG;
	long bmpTmp;
	HDC hdcMem;
	/////////////////////////
	CDibSection Dib_ShowBmp;
	if(bnlShowBmp==true)
	{
		switch(lngMoveIndex)
		{
			case 0:
				Dib_ShowBmp.LoadBmp("test.bmp");
				break;
			case 1:
				Dib_ShowBmp.LoadBmp("Up.bmp");
				break;
			case 2:
				Dib_ShowBmp.LoadBmp("Down.bmp");
				break;
			case 3:
				Dib_ShowBmp.LoadBmp("Right.bmp");
				break;
			case 4:
				Dib_ShowBmp.LoadBmp("Left.bmp");
				break;
			case 5:
				break;
			case 6:
				Dib_ShowBmp.LoadBmp("Route.bmp");
				break;
		}
		Dib_ShowBmp.Draw(dc,0,0,Dib_ShowBmp.Width(),Dib_ShowBmp.Height());
	}
	if(blnchange==false)
		dc.Rectangle((scrX-5),(scrY-5),(scrX+5),(scrY+5));
	else
		dc.Ellipse((scrX-5),(scrY-5),(scrX+5),(scrY+5));
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMFCPaPaGoView printing

BOOL CMFCPaPaGoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCPaPaGoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCPaPaGoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFCPaPaGoView diagnostics

#ifdef _DEBUG
void CMFCPaPaGoView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCPaPaGoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCPaPaGoDoc* CMFCPaPaGoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCPaPaGoDoc)));
	return (CMFCPaPaGoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCPaPaGoView message handlers

void CMFCPaPaGoView::OnLoadMap() 
{
	// TODO: Add your command handler code here
	BOOL bResult;
	BOOL bResultRoute;
	SGD.show();
	///*
	CMainFrame *MainFrame1;
	MainFrame1=(CMainFrame *)AfxGetMainWnd(); 
	MainFrame1->SetWindowText("My PaPaGO-目前無資料"); 
	//*/
	gpMapEngine->LoadProfile(L"pc_standard.mpb",&bResult);
	gpMapEngineRoute->LoadProfile(L"pc_standard.mpb",&bResultRoute);
	////////////////////////////////////////////////////////////////////
	if(bResult==FALSE)
	{
		MessageBox("PPG-SDK:Load Profile Fail");
	}
	else
	{
		gpMapEngine->OpenMap(L"Taiwan_UYS.nv5",&bResult);
		if(bResult==FALSE)
		{
			MessageBox("PPG-SDK:Open Map File Fail");
		}
		else
		{
			gpMapEngine->LoadBackgroundFile(L"Taiwan_c0.mmh",&bResult);
			if(bResult==FALSE)
			{
				MessageBox("PPG-SDK: Load Background File Error");
			}
			else
			{
				gpMapEngine->SetImageSize( 640,480);
				gpMapEngine->OutputMapImage(L"test.bmp",&bResult);
				gpMapEngine->GetMapCenterXY(&m_lngGisX,&m_lngGisY);
				gpMapEngine->SetMapBanner( L"PaPaGO!SDK Sample, (C)2004, Maction." );
				bnlShowBmp=true;
				blnLoadMap=true;
				lngMoveIndex=0;
				Invalidate(true);
			}
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	if(bResultRoute==FALSE)
	{
		MessageBox("PPG-SDK:Load Profile Fail--Route");
	}
	else
	{
		gpMapEngineRoute->OpenMap(L"Taiwan_UYS.nv5",&bResultRoute);
		if(bResultRoute==FALSE)
		{
			MessageBox("PPG-SDK:Open Map File Fail----Route");
		}
		else
		{
			gpMapEngineRoute->LoadBackgroundFile(L"Taiwan_c0.mmh",&bResultRoute);
			if(bResultRoute==FALSE)
			{
				MessageBox("PPG-SDK: Load Background File Error---Route");
			}
			else
			{
				gpMapEngineRoute->SetImageSize( 640,480);
				//gpMapEngineRoute->OutputMapImage(L"test.bmp",&bResult);
				//gpMapEngineRoute->GetMapCenterXY(&m_lngGisX,&m_lngGisY);
				//gpMapEngineRoute->SetMapBanner( L"PaPaGO!SDK Sample, (C)2004, Maction." );
				//bnlShowBmp=true;
				//blnLoadMap=true;
				//lngMoveIndex=0;
				//Invalidate(true);
			}
		}
	}
}

void CMFCPaPaGoView::OnUpmap() 
{
	// TODO: Add your command handler code here
	if(blnLoadMap==true)
	{
		MapUp();
		bnlShowBmp=true;
		lngMoveIndex=1;
		Invalidate(true);
	}
}

void CMFCPaPaGoView::OnDownmap() 
{
	// TODO: Add your command handler code here
	if(blnLoadMap==true)
	{
		MapDown();
		bnlShowBmp=true;
		lngMoveIndex=2;
		Invalidate(true);
	}	
}

void CMFCPaPaGoView::OnLeftmap() 
{
	// TODO: Add your command handler code here
	if(blnLoadMap==true)
	{
		MapLeft();
		bnlShowBmp=true;
		lngMoveIndex=3;
		Invalidate(true);
	}	
}

void CMFCPaPaGoView::OnRightmap() 
{
	// TODO: Add your command handler code here
	if(blnLoadMap==true)
	{
		MapRight();
		bnlShowBmp=true;
		lngMoveIndex=4;
		Invalidate(true);
	}
}
void CMFCPaPaGoView::MapUp(void)
{
	BOOL bResult;
	long lngMapDistX,lngMapDistY;
	gpMapEngine->GetMapCurrentSize(&lngMapDistX,&lngMapDistY);
	long lngGisX,lngGisY;
	gpMapEngine->GetMapCenterXY(&lngGisX,&lngGisY);
	gpMapEngine->SetMapCenterXY(lngGisX,lngGisY+lngMapDistY/3);
	gpMapEngine->SetImageSize( 640,480);
	gpMapEngine->OutputMapImage(L"Up.bmp",&bResult);
	gpMapEngine->SetMapBanner( L"PaPaGO!SDK Sample, (C)2004, Maction." );
}
void CMFCPaPaGoView::MapDown(void)
{
	BOOL bResult;
	long lngMapDistX,lngMapDistY;
	gpMapEngine->GetMapCurrentSize(&lngMapDistX,&lngMapDistY);
	long lngGisX,lngGisY;
	gpMapEngine->GetMapCenterXY(&lngGisX,&lngGisY);
	gpMapEngine->SetMapCenterXY(lngGisX,lngGisY-lngMapDistY/3);
	gpMapEngine->SetImageSize( 640,480);
	gpMapEngine->OutputMapImage(L"Down.bmp",&bResult);
	gpMapEngine->SetMapBanner( L"PaPaGO!SDK Sample, (C)2004, Maction." );
}
void CMFCPaPaGoView::MapRight(void)
{
	BOOL bResult;
	long lngMapDistX,lngMapDistY;
	gpMapEngine->GetMapCurrentSize(&lngMapDistX,&lngMapDistY);
	long lngGisX,lngGisY;
	gpMapEngine->GetMapCenterXY(&lngGisX,&lngGisY);
	gpMapEngine->SetMapCenterXY(lngGisX+lngMapDistX/3,lngGisY);
	gpMapEngine->SetImageSize( 640,480);
	gpMapEngine->OutputMapImage(L"Right.bmp",&bResult);
	gpMapEngine->SetMapBanner( L"PaPaGO!SDK Sample, (C)2004, Maction." );

}
void CMFCPaPaGoView::MapLeft(void)
{
	BOOL bResult;
	long lngMapDistX,lngMapDistY;
	gpMapEngine->GetMapCurrentSize(&lngMapDistX,&lngMapDistY);
	long lngGisX,lngGisY;
	gpMapEngine->GetMapCenterXY(&lngGisX,&lngGisY);
	gpMapEngine->SetMapCenterXY(lngGisX-lngMapDistX/3,lngGisY);
	gpMapEngine->SetImageSize( 640,480);
	gpMapEngine->OutputMapImage(L"Left.bmp",&bResult);
	gpMapEngine->SetMapBanner( L"PaPaGO!SDK Sample, (C)2004, Maction." );
}
void CMFCPaPaGoView::center(void)
{
////////////////////////
/*
	//台中公園
	//東經120°41'04.3"
	double x1=(120+(41*60+4.3)/3600.0);
	//北緯24°08'30.2
	double y1=(24+(8*60+30.2)/3600.0);
//*/
//////////////////////
////////////////////////
/*
	//美術館
	//東經120°39'49.1"
	double x1=(120+(39*60+49.1)/3600.0);
	//北緯24°8'24.8"
	double y1=(24+(8*60+24.8)/3600.0);
//*/
//////////////////////
//////////////////////
	/*
	//東海大學
	//東經120°36'11.0"
		double x1=(120+(36*60+11.0)/3600.0);
	//北緯24°10'57.9"
		double y1=(24+(10*60+57.8)/3600.0);
	//*/
/////////////////////////
	//公司
	/*
	//東經120°39'56.6"
		double x1=(120+(39*60+56.0)/3600.0);
	//北緯24°9'11.6"
		double y1=(24+(9*60+11.6)/3600.0);
	//*/
/////////////////////////
	//公司
	//$GPRMC,052913.374,A,2409.1949,N,12039.9442,E,0.00,,050307,,,A*75
	//經度
	//12039.9442
	//120'39'(0.944*60)
	//120 ' 39 ' 56.64
	//double x1=(120+(39*60+(0.944*60))/3600.0);
	///
	//緯度
	//2409.1949
	//24'9'(0.194*60)
	//24 ' 9 ' 11.64
	//double y1=(24+(9*60+(0.194*60))/3600.0);
//////////////////
	//水舞饌
	//$GPRMC,050354.985,A,2409.0731,N,12040.1456,E,0.00,,050207,,,A*78
	//經度
	//12040.1456
	//120'40'(0.145*60)
	double x1=(120+(40*60+(0.145*60))/3600.0);
	///
	//緯度
	//2409.0731
	//24'09'(0.073*60)
	double y1=(24+(9*60+(0.073*60))/3600.0);
///////////////
	long x=x1*1000000;
	long y=y1*1000000;
	x=120661446;
	y=24155809;
	BOOL bResult;
	gpMapEngine->SetMapCurrentScale(15-2);
	gpMapEngine->SetMapCenterXY(x,y);
	gpMapEngine->SetImageSize( 640,480);
	gpMapEngine->CalCoordinate_Gis2Scr(x,y,&scrX,&scrY); 
	gpMapEngine->OutputMapImage(L"test.bmp",&bResult);
}

void CMFCPaPaGoView::OnCenter() 
{
	// TODO: Add your command handler code here
	if(blnLoadMap==true)
	{
		center();
		bnlShowBmp=true;
		lngMoveIndex=0;
		Invalidate(true);
	}	
}

void CMFCPaPaGoView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	unsigned char data[1024]={'\0'};
	CMainFrame *MainFrame1;
	FILE *fp_rt;
	char chrdata[1024]={'\0'};
	long lnglength=0;
	CString strlength;
	bool blncheck=false;
	long lngTotalScales=0;
	long n=0,n1=0;
	RS.Read(data,&n);
	n1=StringRipFunction(data,n);
	m_Input=strInPut;
	MainFrame1=(CMainFrame *)AfxGetMainWnd();
	switch(nIDEvent)
	{
		case 1:
			if(m_Input!="")
			{
				PaPaGo.SetData(m_Input);
				PaPaGo.CalculateXY(); 
				m_head=PaPaGo.GetHead(); 
				m_time=PaPaGo.GetTime();
				m_strLatitude=PaPaGo.GetLatitude();
				m_strLongitude=PaPaGo.GetLongitude();
				m_direction=PaPaGo.GetDirection();
				m_DataOK=PaPaGo.GetDataOK();
				m_X1=PaPaGo.GetXCoordinate(); 
				m_Y1=PaPaGo.GetYCoordinate();
				m_fltRate=PaPaGo.GetRate()*1.853;
				blncheck=true;
				blnrtcheck=!blnrtcheck;
				MainFrame1->SetWindowText("My PaPaGO-目前資料正確");
			}
			else
			{
				blncheck=false;
				MainFrame1->SetWindowText("My PaPaGO-目前無資料"); 
			}
			//////////////////////////////
				///*
			if(blncheck==true&& m_X1>0 && m_Y1>0)
			{
				BOOL bResult;
				gpMapEngine->SetMapCenterXY(m_X1,m_Y1);
				gpMapEngine->SetMapCurrentScale(15-2);
				gpMapEngine->CalCoordinate_Gis2Scr(m_X1,m_Y1,&scrX,&scrY); 
				gpMapEngine->OutputMapImage(L"test.bmp",&bResult);
				//////////////////////////////////////////////////////////
				gpMapEngineRoute->ClearRouting();
				gpMapEngineRoute->SetRoutingPreference(0); 
				lngRouteEndX=pSiteInformation[lngBufer].lngX;//公司中港路座標
				lngRouteEndY=pSiteInformation[lngBufer].lngY;//公司中港路座標
				//lngRouteEndX=120669018;//水舞饌	startx=120669018;
				//lngRouteEndY=24151148;//水舞饌 starty=24151148;
				gpMapEngineRoute->SetMapCenterXY(m_X1,m_Y1);
				gpMapEngineRoute->SetMapCurrentScale(15-2);
				gpMapEngineRoute->SetImageSize( 640,480);
				gpMapEngineRoute->Routing(m_X1,m_Y1,lngRouteEndX,lngRouteEndY,&bResult);
				if(blnrtcheck)
				{
					remove("rt1.txt");
					MainFrame1->SetWindowText("My PaPaGO-目前資料正確0");
					gpMapEngineRoute->OutputMapImage(L"Route.bmp",&bResult);
					gpMapEngineRoute->OutputRoutingText(L"rt.txt",&bResult);
					fp_rt=fopen("rt.txt","r");
				}
				else
				{
					remove("rt.txt");
					MainFrame1->SetWindowText("My PaPaGO-目前資料正確1");
					gpMapEngineRoute->OutputMapImage(L"Route1.bmp",&bResult);
					gpMapEngineRoute->OutputRoutingText(L"rt1.txt",&bResult);
					fp_rt=fopen("rt1.txt","r");
				}
				fscanf(fp_rt,"%s",chrdata);
				fscanf(fp_rt,"%s",chrdata);
				fclose(fp_rt);
				strlength=chrdata;		
				//////////////////////////////////////////////////////////
				SGD.showdata(m_X1,m_Y1,m_fltRate,strlength);
				lnglength=atol(chrdata);
				if(lnglength<=1000)//小於1000公尺
				{
					KillTimer(1);
					char lng2str[10];
					ltoa(pSiteInformation[lngBufer].lngNO,lng2str,10); 
					CString filename;
					filename=lng2str;
					filename+=".wav";
					int type=2; //隱藏默認工具欄 0表顯示
					m_hwndMCI=MCIWndCreate(this->m_hWnd,AfxGetInstanceHandle(),type,filename);
					MCIWndPlay(m_hwndMCI);
					SetTimer(2,1000,NULL);
					//MessageBox("到達目的地附近");
				}
				blnchange=!blnchange;
				bnlShowBmp=true;
				lngMoveIndex=6;
				Invalidate(true);
			}
			break;
		case 2:
			long lngPosition=0,lngLength=0;
			lngPosition=MCIWndGetPosition(m_hwndMCI);
			lngLength=MCIWndGetLength(m_hwndMCI);
			UpdateData(true);
			SGD.showdata(lngPosition,lngLength);
			if(lngPosition==lngLength && lngPosition!=0)
			{
				KillTimer(2);
				MCIWndClose(m_hwndMCI);
				lngBufer++;
				if(lngBufer<lngMarrValue)
				{
					lngPosition=0;
					lngLength=0;
					SetTimer(1,3000,NULL);
				}
			}
			UpdateData(false);	
			break;
	}
		//*/
		/////////////////////////////
	CView::OnTimer(nIDEvent);
}

void CMFCPaPaGoView::OnRuntimer() 
{
	// TODO: Add your command handler code here
	long lngtime=0;
	p=fopen("data.txt","w");
	RS.OpenCom(5,4800,8,0,1);
	///////////////////////////////////////////
	//讀取戰點資料---start
	pfdata=fopen("規劃資料.txt","r");
	while(fscanf(pfdata,"%ld%s%ld%ld",&lngNO,strSiteName,&lngX,&lngY)!=EOF)
		lngMarrValue++;
	fclose(pfdata);
	pSiteInformation=new SiteInformation[lngMarrValue];
	pfdata=fopen("規劃資料.txt","r");
	lngBufer=0;
	while(fscanf(pfdata,"%ld%s%ld%ld",&lngNO,strSiteName,&lngX,&lngY)!=EOF)
	{
		pSiteInformation[lngBufer].lngNO=lngNO;
		strcpy(pSiteInformation[lngBufer].strSiteName,strSiteName); 
		pSiteInformation[lngBufer].lngX=lngX;
		pSiteInformation[lngBufer].lngY=lngY; 
		lngBufer++;
	}
	fclose(pfdata);
	lngBufer=0;
	//讀取戰點資料---end
	///////////////////////////////////////////
	SetTimer(1,3000,NULL);
}

void CMFCPaPaGoView::OnDirectBMP() 
{
	// TODO: Add your command handler code here
	/////////////////////////	
}

void CMFCPaPaGoView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int x1,y1;
	x1=point.x;
	y1=point.y;
	long scrX1,scrY1;
	gpMapEngine->CalCoordinate_Scr2Gis(x1,y1,&scrX1,&scrY1); 
	CView::OnLButtonUp(nFlags, point);
}

void CMFCPaPaGoView::OnRouting() 
{
	// TODO: Add your command handler code here
	BOOL bResult;
	long lngTotalScales=0;
	gpMapEngineRoute->ClearRouting();
	gpMapEngineRoute->SetRoutingPreference(3);
	////////////////////////
	//水舞饌
	//$GPRMC,050354.985,A,2409.0731,N,12040.1456,E,0.00,,050207,,,A*78
	//經度
	//12040.1456
	//120'40'(0.145*60)
	double x1=(120+(40*60+(0.145*60))/3600.0);
	///
	//緯度
	//2409.0731
	//24'09'(0.073*60)
	double y1=(24+(9*60+(0.073*60))/3600.0);
	//////////////////////
	long startx=x1*1000000;
	long starty=y1*1000000;
	startx=120669018;
	starty=24151148;
	////////////////////////
	//公司
	//$GPRMC,052913.374,A,2409.1949,N,12039.9442,E,0.00,,050307,,,A*75
	//經度
	//12039.9442
	//120'39'(0.944*60)
	//120 ' 39 ' 56.64
	x1=(120+(39*60+(0.944*60))/3600.0);
	///
	//緯度
	//2409.1949
	//24'9'(0.194*60)
	//24 ' 9 ' 11.64
	y1=(24+(9*60+(0.194*60))/3600.0);
	//////////////////////
	long endx=x1*1000000;
	long endy=y1*1000000;
	endx=120666408;//中港路位置
	endy=24153428;//中港路位置
	gpMapEngineRoute->SetMapCenterXY(startx,starty);
	gpMapEngineRoute->SetImageSize( 640,480);
	gpMapEngineRoute->Routing(startx,starty,endx,endy,&bResult);
	gpMapEngineRoute->CalCoordinate_Gis2Scr(startx,starty,&scrX,&scrY); 
	gpMapEngineRoute->GetTotalScale(&lngTotalScales);
	gpMapEngineRoute->SetMapCurrentScale(lngTotalScales-1);
	gpMapEngineRoute->OutputMapImage(L"Route.bmp",&bResult);
	gpMapEngineRoute->OutputRoutingText(L"rt.txt",&bResult);
	bnlShowBmp=true;
	lngMoveIndex=6;
	Invalidate(true);

}

BOOL CMFCPaPaGoView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

int CMFCPaPaGoView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	return 0;
}
int CMFCPaPaGoView::StringRipFunction(unsigned char str[],long number)
{
	int i=0,j=0;
	char *chrInBuf;//建立暫存輸入資料指標
	char *chrOutBuf;//建立暫存輸出分割資料指標
	CString strbuf1,strbuf2,strbuf3;
	char chrSeps[]=",";//建立分割符號
	for(j=0;j<30;j++)
		strdata[j]="";
	j=0;
	for(i=0;i<number;i++)
	{
		if(j<30)
		{
			if(str[i]!=13 && str[i]!=10)
			{
				strdata[j]+=str[i];
			}
			else
			{
				if(str[i]==13)
					j++;
			}
		}
		else
		{
			break;
		}
	}
	strInPut="";
	for(i=0;i<j;i++)
	{
		fprintf(p,"%s\n",strdata[i].GetBuffer(0));
		strbuf1=strdata[i];
		chrInBuf=strbuf1.GetBuffer(0);//賦予資料
		////////////////////////////////////
		chrOutBuf=strtok(chrInBuf,chrSeps);//擷取檔頭
		strbuf2=chrOutBuf;
		strbuf3="$GPRMC";
		if(strbuf2==strbuf3)
		{
			strInPut=strdata[i];
		}
	}
	return j;
}

void CMFCPaPaGoView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CPoint data;
	gpMapEngineRoute->CalCoordinate_Scr2Gis(point.x,point.y,&data.x,&data.y); 
	fprintf(fp_point,"%d\t%d\n",data.x,data.y);
	CView::OnLButtonDown(nFlags, point);
}
