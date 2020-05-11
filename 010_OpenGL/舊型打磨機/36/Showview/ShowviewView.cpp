// ShowviewView.cpp : implementation of the CShowviewView class
//

#include "stdafx.h"
#include "Showview.h"

#include "ShowviewDoc.h"
#include "ShowviewView.h"
#include "RungeKutta.h"
#include "rossCouplePara.h"
#include "KPID.h"
#include <stdio.h>
#include <time.h>
#include <iostream.h>
#include <fstream.h>
#include<math.h>
//#define PI 3.14159267
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int i;
double d2r = PI/180;
double test_value_x = 0.0;
double test_value_y = 0.0;

viewbar PIDStatus;
KPID PID;

ofstream DesiredX;
ofstream DesiredY;
ofstream ActualX;
ofstream ActualY;

ofstream filePtr;
ofstream Delta;
ofstream Slope;
ofstream K11;
ofstream K12;
ofstream K21;
ofstream K22;
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
	int X_Offset = 100;
	int Y_Offset = 20;
	int X_Interval = 25;
	int Y_Interval = 25;
	
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
int count = 1;


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//RungeKutta T11, T12, T21, T22;

RungeKutta T11;
RungeKutta T12;
RungeKutta T21;
RungeKutta T22;

CrossCouplePara T;

double Delta_T = 0.001;

double PDX = 0.0;		//此次x軸期望值
double PDX_Last = 0.0;	//上次x軸期望值
double PDY = 0.0;		//此次y軸期望值
double PDY_Last = 0.0;	//上次y軸期望值
double PAX = 0.0;		//此次x軸實際值
double PAX_Last = 0.0;	//上次x軸實際值
double PAY = 0.0;		//此次y軸實際值
double PAY_Last = 0.0;	//上次y軸實際值
double Theta = 0.0;	//片段直線斜率
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////
///////////////////////////////////////////
//傳送
#define	MAP_NAME0	"spacesoft corp0."
#define	MAP_NAME1	"spacesoft corp1."
#define	MAP_NAME2	"spacesoft corp2."
#define	MAP_NAME3	"spacesoft corp3."
#define	MAP_NAME4	"spacesoft corp4."
#define	MAP_NAME5	"spacesoft corp5."
#define	MAP_LENGTH	16
HANDLE hFileMap0 = NULL ;
HANDLE hFileMap1 = NULL ;
HANDLE hFileMap2 = NULL ;
HANDLE hFileMap3 = NULL ;
HANDLE hFileMap4 = NULL ;
HANDLE hFileMap5 = NULL ;
static char szOldData[MAP_LENGTH] = "" ;
int add_x;
/////////////////////////////////////////////////////////////////////////////
//接收
#define	MAP_NAME6	"spacesoft corp6."
#define	MAP_NAME7	"spacesoft corp7."
#define	MAP_NAME8	"spacesoft corp8."
#define	MAP_NAME9	"spacesoft corp9."
HANDLE hFileMap6 = NULL ;
HANDLE hFileMap7 = NULL ;
HANDLE hFileMap8 = NULL ;
HANDLE hFileMap9 = NULL ;
/////////////////////////////////////////////////////////////////////////////
FILE *p;
///////////////////////
// CShowviewView

IMPLEMENT_DYNCREATE(CShowviewView, CScrollView)

BEGIN_MESSAGE_MAP(CShowviewView, CScrollView)
	//{{AFX_MSG_MAP(CShowviewView)
	ON_WM_TIMER()
	ON_COMMAND(ID_Settimer, OnSettimer)
	ON_COMMAND(ID_Bar, OnBar)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowviewView construction/destruction

CShowviewView::CShowviewView()
{
	// TODO: add construction code here
	DesiredX.open ("DesiredX.txt", ios::out);
	DesiredY.open ("DesiredY.txt", ios::out);
	ActualX.open ("ActualX.txt", ios::out);
	ActualY.open ("ActualY.txt", ios::out);
	filePtr.open ("timer1.txt", ios::out);
	Delta.open ("Delta.txt", ios::out);
	Slope.open ("Slope.txt", ios::out);
	K11.open ("K11.txt", ios::out);
	K12.open ("K12.txt", ios::out);
	K21.open ("K21.txt", ios::out);
	K22.open ("K22.txt", ios::out);
	
}

CShowviewView::~CShowviewView()
{
}

BOOL CShowviewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShowviewView drawing

void CShowviewView::OnDraw(CDC* pDC)
{
	CShowviewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CRect view1_Rect;
	POSITION pos;
	aDC=new CClientDC(this);	
	CPen pen(PS_SOLID,1,RGB(255,0,0));
	//	pen(線條形式，寬度，顏色)
	aDC->SelectObject(&pen);
	GetClientRect(&view1_Rect);
//	aDC->TextOut(0,0,"50");
	
	//取得view的長寬
	//view1_Rect.Width()
	//view1_Rect.Height()	
	///

	aDC->TextOut (0, (view1_Rect.Height ())*1/5, "Desire");
	CPen pen1(PS_SOLID,1,RGB(0,255,0));
	aDC->SelectObject(&pen1);
	aDC->MoveTo (0, (view1_Rect.Height ())*1/5+20);
	aDC->LineTo (40, (view1_Rect.Height ())*1/5+20);

	aDC->TextOut (0, (view1_Rect.Height ())*4/5, "Actual");
	CPen pen2(PS_SOLID,1,RGB(255,0,0));
	aDC->SelectObject(&pen2);
	aDC->MoveTo (0, (view1_Rect.Height ())*4/5+20);
	aDC->LineTo (40, (view1_Rect.Height ())*4/5+20);

	CPen pen3(PS_SOLID,3,RGB(0,0,255));
	aDC->SelectObject(&pen3);
	aDC->MoveTo (50, 0);
	aDC->LineTo (50, view1_Rect.Height ());

	CPen pen4(PS_SOLID,2,RGB(0,0,0));
	aDC->SelectObject(&pen4);
	aDC->MoveTo (100, 0);
	aDC->LineTo (100, view1_Rect.Height ()-20);
	aDC->MoveTo (0, 0);
	aDC->LineTo (view1_Rect.Width (), 0);
	aDC->MoveTo (100, view1_Rect.Height ()-20);
	aDC->LineTo (view1_Rect.Width (), view1_Rect.Height ()-20);

	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	//	LABEL
	float Text_Shift = -3;
	int Mid_Y = (view1_Rect.Height ()-Y_Offset)/2;
	aDC->TextOut (60 ,   0+Mid_Y+Text_Shift, "    0");
	aDC->TextOut (60 ,  25+Mid_Y+Text_Shift, "  -25");
	aDC->TextOut (60 , -25+Mid_Y+Text_Shift, "   25");
	aDC->TextOut (60 ,  50+Mid_Y+Text_Shift, "  -50");
	aDC->TextOut (60 , -50+Mid_Y+Text_Shift, "   50");
	aDC->TextOut (60 ,  75+Mid_Y+Text_Shift, "  -75");
	aDC->TextOut (60 , -75+Mid_Y+Text_Shift, "   75");
	aDC->TextOut (60 , 100+Mid_Y+Text_Shift, "-100");
	aDC->TextOut (60 ,-100+Mid_Y+Text_Shift, " 100");
	//	LABEL
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	//	GRID

	int Plot_X_Start = 100;
	int Plot_Y_Start = (view1_Rect.Height ()-Y_Offset)/2;
	int X_Line = (view1_Rect.Width ()-X_Offset)/X_Interval;
	int Y_Line = (view1_Rect.Height ()-Y_Offset)/2/Y_Interval;
	CPen pen5(PS_DOT,1,RGB(0,0,0));
	aDC->SelectObject(&pen5);
	for(int i=0; i<X_Line; i++)
	{
		aDC->MoveTo ((i+1)*X_Interval+Plot_X_Start, 0);
		aDC->LineTo ((i+1)*X_Interval+Plot_X_Start, view1_Rect.Height ()-Y_Offset);
	}
	for(int j=0; j<=4/*Y_Line*/; j++)
	{
		aDC->MoveTo (X_Offset			,  j*Y_Interval+Plot_Y_Start);
		aDC->LineTo (view1_Rect.Width (),  j*Y_Interval+Plot_Y_Start);
		aDC->MoveTo (X_Offset			, -j*Y_Interval+Plot_Y_Start);
		aDC->LineTo (view1_Rect.Width (), -j*Y_Interval+Plot_Y_Start);
	}
	//	GRID
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	CPen pen6(PS_SOLID,1,RGB(255,0,0));
	aDC->SelectObject(&pen6);
	int y1=((view1_Rect.Height()-Y_Offset)/2);
	aDC->TextOut(0,y1-5,"0");
	aDC->TextOut(0,(y1*2)-15,"-50");



	pos=list1.GetHeadPosition();
	while(pos !=NULL)
	{
		ca=list1.GetNext(pos);
		cb=list1.GetNext(pos);
		PhysicalCoor(&ca);
		aDC->MoveTo ( ca );
		PhysicalCoor(&cb);
		aDC->LineTo ( cb );
	}

	// TODO: add draw code for native data here
}

void CShowviewView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, CSize(4096,4096));
	viewbar1.Show();
}

/////////////////////////////////////////////////////////////////////////////
// CShowviewView printing

BOOL CShowviewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CShowviewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CShowviewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CShowviewView diagnostics

#ifdef _DEBUG
void CShowviewView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CShowviewView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CShowviewDoc* CShowviewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShowviewDoc)));
	return (CShowviewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowviewView message handlers

BOOL CShowviewView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	add_x=1;
	cb.y=0;
	ca.y=0;
	ca.x=50;
	cb.x=50+1;
	//記憶體映射
	hFileMap0 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME0 ) ;
	hFileMap1 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME1 ) ;
	hFileMap2 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME2 ) ;
	hFileMap3 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME3 ) ;
	hFileMap4 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME4 ) ;
	hFileMap5 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME5 ) ;
	////////////////////////////////////////////////////////////////////////////////////////////////////
	hFileMap6 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME6 ) ;
	hFileMap7 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME7 ) ;
	hFileMap8 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME8 ) ;
	hFileMap9 = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME9 ) ;
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);

}


void CShowviewView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	test();
	CScrollView::OnTimer(nIDEvent);
}

void CShowviewView::OnSettimer() 
{
	// TODO: Add your command handler code here
	p=fopen("mapdata.txt","w");
	SetTimer(1,1,NULL);
}
void CShowviewView::test ()
{


	CRect view1_Rect;
	GetClientRect(&view1_Rect);
	double X_Scal = 1.0;
	double Y_Scal = 1.0;
	double X = 0;
	double Y = 0;
	float tempx, tempy;
	int Plot_X_Start = 100;
	int Plot_Y_Start = (view1_Rect.Height ()-Y_Offset)/2;

	if(count <= 360)
	{	

		int theta = count;
		PDX = theta;
		//PDY = 1.0;
		PDY = 50*sin(d2r*theta);
		////////////////////////////////////////////////////////////////////////////
		/////////	PDX vs PDY												////////
		////////////////////////////////////////////////////////////////////////////
		CPen pend(PS_SOLID,1,RGB(0, 200, 0));
		aDC->SelectObject(&pend);

		ca.x = PDX_Last*X_Scal+Plot_X_Start;
		ca.y =-PDY_Last*Y_Scal+Plot_Y_Start;
		aDC->MoveTo(ca);
	
		cb.x = PDX*X_Scal+Plot_X_Start;
		cb.y =-PDY*Y_Scal+Plot_Y_Start;
		aDC->LineTo(cb);

		list1.AddTail(ca);
		list1.AddTail(cb);
		ca = cb;
		DesiredX<<PDX<<endl;
		DesiredY<<PDY<<endl;


		////////////////////////////////////////////////////////////////////////////
		//////////	RungeKutta									////////////////////
		////////////////////////////////////////////////////////////////////////////
		double kdx, kpx, kix, kdy, kpy, kiy, kdc, kpc, kic, Theta, ax, bx, ay, by;
		double pid[9];
		Theta = atan((PDY-PDY_Last)/(PDX-PDX_Last))/d2r;
		PID.GetPID (Theta, pid);
/*		kdx = 76.0602;
		kpx = 959.8578;
		kix = 1.1427;
		kdy = 997.3307;
		kpy = 954.3631;
		kiy = 66.5850;
		kdc = 975.1950;
		kpc = 995.7358;
		kic = 89.0184;
*/
		ax = 12.571;
		bx = 266.15;
		ay = 12.571;
		by = 266.15;
//		double Parameter[14]={kdx, kpx, kix, kdy, kpy, kiy, kdc, kpc, kic, Theta, ax, bx, ay, by};
		double Parameter[14]={pid[0], pid[1], pid[2], pid[3], pid[4], pid[5], pid[6], pid[7], pid[8], Theta, ax, bx, ay, by};
		viewbar1.SetValue(pid, Theta);
		
		////////////////////////////////////////////////////////////////////////////
		/////////	CrossCoupling 設定參數									////////
		////////////////////////////////////////////////////////////////////////////
		T.SetPara (Parameter);
		////////////////////////////////////////////////////////////////////////////
		/////////	CrossCoupling 計算K11, K12, K21, K22					////////
		////////////////////////////////////////////////////////////////////////////
		T.Compute ();
		double delta[7], k11[6], k12[6], k21[6], k22[6];

		////////////////////////////////////////////////////////////////////////////
		/////////	CrossCoupling 將物件Private參數放回程式					////////
		////////////////////////////////////////////////////////////////////////////
		T.GetPara (delta, k11, k12, k21, k22);
		Slope<<Theta<<endl;
		Delta<<delta[0]<<"\t"<<delta[1]<<"\t"<<delta[2]<<"\t"<<delta[3]<<"\t"<<delta[4]<<"\t"<<delta[5]<<"\t"<<delta[6]<<endl;
		K11<<k11[0]<<"\t"<<k11[1]<<"\t"<<k11[2]<<"\t"<<k11[3]<<"\t"<<k11[4]<<"\t"<<k11[5]<<endl;
		K12<<k12[0]<<"\t"<<k12[1]<<"\t"<<k12[2]<<"\t"<<k12[3]<<"\t"<<k12[4]<<"\t"<<k12[5]<<endl;
		K21<<k21[0]<<"\t"<<k21[1]<<"\t"<<k21[2]<<"\t"<<k21[3]<<"\t"<<k21[4]<<"\t"<<k21[5]<<endl;
		K22<<k22[0]<<"\t"<<k22[1]<<"\t"<<k22[2]<<"\t"<<k22[3]<<"\t"<<k22[4]<<"\t"<<k22[5]<<endl;
		////////////////////////////////////////////////////////////////////////////
		/////////	RungeKutta 設定參數										////////
		////////////////////////////////////////////////////////////////////////////
		T11.SetPara (delta[0], delta[1], delta[2], delta[3], delta[4], delta[5], delta[6], k11[0], k11[1], k11[2], k11[3], k11[4], k11[5], Delta_T);
		T12.SetPara (delta[0], delta[1], delta[2], delta[3], delta[4], delta[5], delta[6], k12[0], k12[1], k12[2], k12[3], k12[4], k12[5], Delta_T);
		T21.SetPara (delta[0], delta[1], delta[2], delta[3], delta[4], delta[5], delta[6], k21[0], k21[1], k21[2], k21[3], k21[4], k21[5], Delta_T);
		T22.SetPara (delta[0], delta[1], delta[2], delta[3], delta[4], delta[5], delta[6], k22[0], k22[1], k22[2], k22[3], k22[4], k22[5], Delta_T);


		////////////////////////////////////////////////////////////////////////////
		/////////	RungeKutta 運算											////////
		////////////////////////////////////////////////////////////////////////////
		T11.Compute (PDX, 0.0, 0.0, 0.0, 0.0, 0.0);
		T12.Compute (PDY, 0.0, 0.0, 0.0, 0.0, 0.0);
		T21.Compute (PDX, 0.0, 0.0, 0.0, 0.0, 0.0);
		T22.Compute (PDY, 0.0, 0.0, 0.0, 0.0, 0.0);
		////////////////////////////////////////////////////////////////////////////
		/////////															////////
		////////////////////////////////////////////////////////////////////////////
		PAX = T11.Y +T12.Y ;
		PAY = T21.Y +T22.Y ;
		////////////////////////////////////////////////////////////////////////////
		/////////	PAX vs PAY												////////
		////////////////////////////////////////////////////////////////////////////
		CPen pena(PS_SOLID,1,RGB(200, 0, 0));
		aDC->SelectObject(&pena);
		ca.x = PAX_Last*X_Scal+Plot_X_Start;
		ca.y =-PAY_Last*Y_Scal+Plot_Y_Start;
		aDC->MoveTo(ca);
		
		cb.x = PAX*X_Scal+Plot_X_Start;
		cb.y =-PAY*Y_Scal+Plot_Y_Start;
		aDC->LineTo(cb);
		
		list1.AddTail(ca);
		list1.AddTail(cb);
		ca = cb;
		
		ActualX<<PAX<<endl;
		ActualY<<PAY<<endl;
		////////////////////////////////////////////////////////////////////////////
		/////////															////////
		////////////////////////////////////////////////////////////////////////////		

		PDX_Last = PDX;
		PDY_Last = PDY;
		PAX_Last = PAX;
		PAY_Last = PAY;

		count++;
	}
	///////////////////////////////////////////
	char *ch0,*ch1,*ch2,*ch3,*ch4,*ch5;
	char ch6[100],ch7[100],ch8[100],ch9[100];
	int d,s;
	double a,b,c,d1,e,f;
	LPVOID mapView0,mapView1,mapView2,mapView3,mapView4,mapView5,mapView6,mapView7,mapView8,mapView9;
	mapView0 = MapViewOfFile( hFileMap0,FILE_MAP_WRITE, 0, 0, 0 );
	mapView1 = MapViewOfFile( hFileMap1,FILE_MAP_WRITE, 0, 0, 0 );
	mapView2 = MapViewOfFile( hFileMap2,FILE_MAP_WRITE, 0, 0, 0 );
	mapView3 = MapViewOfFile( hFileMap3,FILE_MAP_WRITE, 0, 0, 0 );
	mapView4 = MapViewOfFile( hFileMap4,FILE_MAP_WRITE, 0, 0, 0 );
	mapView5 = MapViewOfFile( hFileMap5,FILE_MAP_WRITE, 0, 0, 0 );
	////////////////////////////////////////////////////////////
	mapView6 = MapViewOfFile( hFileMap6,FILE_MAP_WRITE, 0, 0, 0 );
	mapView7 = MapViewOfFile( hFileMap7,FILE_MAP_WRITE, 0, 0, 0 );
	mapView8 = MapViewOfFile( hFileMap8,FILE_MAP_WRITE, 0, 0, 0 );
	mapView9 = MapViewOfFile( hFileMap9,FILE_MAP_WRITE, 0, 0, 0 );
	////////////////////////////////////////////////////////////////
	ch0=fcvt(Theta,4,&d,&s);
	strcpy((LPTSTR)mapView0,ch0);
	ch1=fcvt(PDX,4,&d,&s);
	strcpy((LPTSTR)mapView1,ch1);
	ch2=fcvt(PDY,4,&d,&s);
	strcpy((LPTSTR)mapView2,ch2);
	ch3=fcvt(PAX,4,&d,&s);
	strcpy((LPTSTR)mapView3,ch3);
	ch4=fcvt(PAY,4,&d,&s);
	strcpy((LPTSTR)mapView4,ch4);
	ch5=fcvt(Delta_T,4,&d,&s);
	strcpy((LPTSTR)mapView4,ch5);
	UnmapViewOfFile( (LPVOID)mapView0);
	UnmapViewOfFile( (LPVOID)mapView1);
	UnmapViewOfFile( (LPVOID)mapView2);
	UnmapViewOfFile( (LPVOID)mapView3);
	UnmapViewOfFile( (LPVOID)mapView4);
	UnmapViewOfFile( (LPVOID)mapView5);
	////////////////////////////////////////
	strcpy(ch6,(LPTSTR)mapView6);
	strcpy(ch7,(LPTSTR)mapView7);
	strcpy(ch8,(LPTSTR)mapView8);
	strcpy(ch9,(LPTSTR)mapView9);	
	a=(atof(ch6)/10000);
	b=(atof(ch7)/10000);
	c=(atof(ch8)/10000);
	d1=(atof(ch9)/10000);
	fprintf(p,"%f\t%f\t%f\t%f\n",a,b,c,d1);
	viewbar1.map_value(a,b,c,d1);
	//////////////////////////////////////////
}

BOOL CShowviewView::OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll) 
{
	// TODO: Add your specialized code here and/or call the base class
	Invalidate(true);
	return CScrollView::OnScroll(nScrollCode, nPos, bDoScroll);
}

void CShowviewView::OnBar() 
{
	// TODO: Add your command handler code here
	viewbar1.Show();
}
