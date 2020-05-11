// view1.cpp : implementation file
//

#include "stdafx.h"
#include "kk1.h"
#include "view1.h"
#include "MainFrm.h"
#include "RungeKutta.h"
#include <stdio.h>
#include <iostream>
#include<math.h>
#define PI 3.14159267

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int i;
double d2r = PI/180;
double test_value_x = 0.0;
double test_value_y = 0.0;

FILE *p;
	FILE *inx, *iny;

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
int count = 0;


///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//RungeKutta T11, T12, T21, T22;
//RungeKutta T11(18.0,24.0,344.0,463.0,53.0,67.0,27.0,89.0,99.0,140.0,161.0,132.0,163.0, 0.01);
RungeKutta T11(1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0,13.0, 0.01);
double PDX = 0.0;
double PDY = 0.0;
double PAX = 0.0;
double PAY = 0.0;
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////


int add_x;

/////////////////////////////////////////////////////////////////////////////
// view1

IMPLEMENT_DYNCREATE(view1, CScrollView)

view1::view1()
{

	p=fopen("t.txt","w");
		inx = fopen("x.txt", "r");
		iny = fopen("y.txt", "r");
}

view1::~view1()
{
}


BEGIN_MESSAGE_MAP(view1, CScrollView)
	//{{AFX_MSG_MAP(view1)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// view1 drawing
void view1::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = 100;
	sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, CSize(4096,200));
}
void view1::OnDraw(CDC* pDC)
{
	int k;
	CRect view1_Rect;
	POSITION pos;
	aDC=new CClientDC(this);	
	CDocument* pDoc = GetDocument();
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
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// view1 diagnostics

#ifdef _DEBUG
void view1::AssertValid() const
{
	CView::AssertValid();
}

void view1::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// view1 message handlers

void view1::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnMouseMove(nFlags, point);
}

void view1::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CPen pen(PS_SOLID,1,RGB(0,255,0));
	cb=point;
	aDC->SelectObject(&pen);
	aDC->MoveTo(ca);
	aDC->LineTo(cb);
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}

void view1::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int k=0;
	int x,y;
	SetCapture();
	ca=point;
	//aDC=new CClientDC(this);
	fprintf(p,"%d\t", point.x); 
	fprintf(p,"%d\n", point.y); 
	CView::OnLButtonDown(nFlags, point);
}

int view1::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	add_x=1;
	cb.y=0;
	ca.y=0;
	ca.x=50;
	cb.x=50+1;
	aDC=new CClientDC(this);

	//CKk1View *CKk1View1;
	SetTimer(1,10,NULL);	
	// TODO: Add your specialized creation code here
	return 0;
}

void view1::OnTimer(UINT nIDEvent) 
{
	test();
	// TODO: Add your message handler code here and/or call default
/*	//記憶體映射
	char *a;
	float i=0;
	int j=1;
	LPVOID mapView,mapView1;
	CRect view1_Rect;
	GetClientRect(&view1_Rect);
	int y=view1_Rect.Height();
	if(j==0)
	{
		mapView = MapViewOfFile( hFileMap,FILE_MAP_WRITE, 0, 0, 0 ) ;
	}
	else
	{
		mapView1 = MapViewOfFile( hFileMap1,FILE_MAP_WRITE, 0, 0, 0 ) ;
	}
	if( mapView1 != NULL ) 
	{
		if( lstrcmp( szOldData, (char*)mapView1 ) ) //比較資料
		{
			a=(LPTSTR)mapView1;
			//a=(LPTSTR)mapView;
			i=atof(a);
			fprintf(p,"%f\n",i);
			lstrcpy( szOldData, (char*)mapView1 ) ;//複製資料
			/////////////////////////////////////////////
			cb.y=y-i-15;
			LogicalCoor(&ca);	//轉換至邏輯座標 ScrollView new
			aDC->MoveTo(ca);
			LogicalCoor(&cb);	//轉換至邏輯座標 ScrollView new
			aDC->LineTo(cb);
			list1.AddTail(ca);
			list1.AddTail(cb);
			ca.y=cb.y;
			ca.x+=add_x;
			cb.x=ca.x+1;
			////////////////////
			//View_lock = TRUE;
			//X_shift+=100 ;
			CMainFrame *CMain=(CMainFrame*)AfxGetMainWnd();
			CMain->Update(5,5,0,0,5,1);
			///////////////////
		}
		if(j==1)
		{
			UnmapViewOfFile( (LPVOID)mapView1 ) ;
		}
		else
		{
			UnmapViewOfFile( (LPVOID)mapView ) ;
		}
	}
*/
	CView::OnTimer(nIDEvent);
}

BOOL view1::OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll) 
{
	// TODO: Add your specialized code here and/or call the base class
	Invalidate(true);
	return CScrollView::OnScroll(nScrollCode, nPos, bDoScroll);
}

void view1::test ()
{

	CRect view1_Rect;
	GetClientRect(&view1_Rect);
	double X_Scal = 1.0;
	double Y_Scal = 50.0;
	double X = 0;
	double Y = 0;
	float tempx, tempy;
	int Plot_X_Start = 100;
	int Plot_Y_Start = (view1_Rect.Height ()-Y_Offset)/2;
	if(count <= 2000)
	{
		count++;
	CPen pend(PS_SOLID,1,RGB(0, 200, 0));
	aDC->SelectObject(&pend);

	ca.x = PDX*X_Scal+Plot_X_Start;
	ca.y =-PDY*Y_Scal+Plot_Y_Start;
	aDC->MoveTo(ca);
	
	cb.x = PDX*X_Scal+Plot_X_Start;
	cb.y =-PDY*Y_Scal+Plot_Y_Start;
	aDC->LineTo(cb);
	list1.AddTail(ca);
	list1.AddTail(cb);
	ca = cb;

//	PDX+=1.0;
//	PDY = 100.0;
	////////////////////////////////////////////////////////////////////////////
	//////////	RungeKutta									////////////////////
	////////////////////////////////////////////////////////////////////////////

	double Delta[7];
	double J1[6];
	double J2[6];
	double J3[6];
	double J4[6];
	Delta[0]=1.0;
	Delta[1]=2.0;
	Delta[2]=3.0;
	Delta[3]=4.0;
	Delta[4]=5.0;
	Delta[5]=6.0;
	Delta[6]=7.0;
	J1[0]=8.0;
	J1[1]=9.0;
	J1[2]=10.0;
	J1[3]=11.0;
	J1[4]=12.0;
	J1[5]=13.0;

	////////////////////////////////////////////////////////////////////////////
	PDX+= 0.1;
	PDY = 1.0;
//	T11(Delta[0], Delta[1], Delta[2], Delta[3], Delta[4], Delta[5], Delta[6], J1[0], J1[1], J1[2], J1[3], J1[4], J1[5], 0.01);
//	RungeKutta T11(1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0,13.0, 1.0);

//	RungeKutta T11(18.0,24.0,344.0,463.0,53.0,67.0,27.0,89.0,99.0,140.0,161.0,132.0,163.0, 0.01);

	T11.Compute(PDY, 0.0, 0.0, 0.0, 0.0, 0.0);
	PAX = PDX;
	PAY = T11.Y;


	////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////
	CPen pena(PS_SOLID,1,RGB(200, 0, 0));
	aDC->SelectObject(&pena);
	ca.x = PAX*X_Scal+Plot_X_Start;
	ca.y =-PAY*Y_Scal+Plot_Y_Start;
	aDC->MoveTo(ca);
	cb.x = PAX*X_Scal+Plot_X_Start;
	cb.y =-PAY*Y_Scal+Plot_Y_Start;
	aDC->LineTo(cb);
	list1.AddTail(ca);
	list1.AddTail(cb);
	ca = cb;
	fprintf(p, "%12f\n", PAY);
	}
/*	
	CRect view1_Rect;
	GetClientRect(&view1_Rect);
	double X_Scal = 0.1;
	double Y_Scal = 1.0;
	double X = 0;
	double Y = 0;
	float tempx, tempy;
	int Plot_X_Start = 100;
	int Plot_Y_Start = (view1_Rect.Height ()-Y_Offset)/2;
	CPen pen(PS_SOLID,1,RGB(0, 200, 0));
	aDC->SelectObject(&pen);
	

	if((fscanf(inx, "%f\n", &tempx) != EOF) && (fscanf(iny, "%f\n", &tempy) != EOF ))
	{	
	
		X = tempx;
		Y = tempy;
		
		ca.x = X*X_Scal+Plot_X_Start;
		ca.y =-Y*Y_Scal+Plot_Y_Start;
		aDC->MoveTo(ca);

		cb.x = X*X_Scal+Plot_X_Start;
		cb.y =-Y*Y_Scal+Plot_Y_Start;
		aDC->LineTo(cb);
		list1.AddTail(ca);
		list1.AddTail(cb);
		ca = cb;
	}
	else 
	{
		//MessageBox("Reading", "Error", MB_ICONINFORMATION | MB_OK);
	}
*/


/*
	if(count <= 500)
	{	

		int Plot_X_Start = 100;
		int Plot_Y_Start = (view1_Rect.Height ()-Y_Offset)/2;

		CPen pen(PS_SOLID,1,RGB(0, 200, 0));
		aDC->SelectObject(&pen);

		fprintf(p,"%d\t", test_value_x); 
		fprintf(p,"%d\n", test_value_y); 

//		X = test_value_x*X_Scal;
//		Y =-test_value_y*Y_Scal;
		ca.x = test_value_x*X_Scal+Plot_X_Start;
		ca.y =-test_value_y*Y_Scal+Plot_Y_Start;
//		LogicalCoor(&ca);	//轉換至邏輯座標 ScrollView new
		aDC->MoveTo(ca);

		test_value_x += 1.0;
		test_value_y = 100*sin(test_value_x*d2r)*Y_Scal;

//		X = test_value_x*X_Scal;
//		Y =-test_value_y*Y_Scal;
		cb.x = test_value_x*X_Scal+Plot_X_Start;
		cb.y =-test_value_y*Y_Scal+Plot_Y_Start;
//		LogicalCoor(&cb);	//轉換至邏輯座標 ScrollView new
		aDC->LineTo(cb);
		list1.AddTail(ca);
		list1.AddTail(cb);
		ca = cb;
		count += 1;
	}
*/	


}
/*
void main()
{
	int k = 0;
	int j = 0;
	float a[100000];
	float temp;
	FILE *in;
	FILE *out;
	out = fopen("test1.txt", "w");
	in = fopen("test1.txt", "r");

	for(double i=0; i<=0.005; i+=0.0005)
	{
		fprintf(out, "%f\n", i);
	}
	fclose(out);


	while(fscanf(in, "%f\n", &temp) != EOF )
	{	
	
		a[k] = temp;
		cout << temp << endl;
		k++;
	}
	cout << endl;
	fclose(in);

	for(j=0; j<k; j++)
	{
		cout << a[j] <<endl;
	}

}
*/