// viewView.cpp : implementation of the CViewView class
//

#include "stdafx.h"
#include "view.h"
#include "ExternalVarApp2View.h"
#include "viewDoc.h"
#include "viewView.h"
#include "DibSection.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CPoint ppt;
bool test=false;
/////////////////////////////////////////////////////////////////////////////
// CViewView
IMPLEMENT_DYNCREATE(CViewView, CScrollView)

BEGIN_MESSAGE_MAP(CViewView, CScrollView)
	//{{AFX_MSG_MAP(CViewView)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_COMMAND(ID_StartTimer, OnStartTimer)
	ON_COMMAND(ID_StopTimer, OnStopTimer)
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewView construction/destruction

CViewView::CViewView()
{
	// TODO: add construction code here
	lngtime=0;
	p1.x=50;
	p1.y=350;
	p2.x=50;
	p2.y=350;

}

CViewView::~CViewView()
{
}

BOOL CViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CViewView drawing

void CViewView::OnDraw(CDC* pDC)
{
	CViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	long pos;
	CView::OnDraw(pDC);	//呼叫CView類別的OnDraw成員函數
	DrawFrame();
	DrawGrid();
	pos=Array1.GetSize();
	for(long i=0;i<pos;i++)
	{
		p1=Array1[i];
		i++;
		p2=Array1[i];
		PhysicalCoor(&p1);
		PhysicalCoor(&p2);
		aDC->MoveTo ( p1 );
		aDC->LineTo ( p2 );
	}
	char *buf;
	if(pos>0)
	{
		p1=Array1[0];
		//buf=new char[10];
		//itoa(p1.x,buf,10);
		//CString str;
		//str="X:";
		//str+=buf;
		//aDC->TextOut(100,200,str); 
	}
	// TODO: add draw code for native data here
}

void CViewView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes( MM_TEXT, CSize ( glngViewWide, glngViewhigh ) );

}

/////////////////////////////////////////////////////////////////////////////
// CViewView printing

BOOL CViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CViewView diagnostics

#ifdef _DEBUG
void CViewView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CViewView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CViewDoc* CViewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CViewDoc)));
	return (CViewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewView message handlers

BOOL CViewView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CViewView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CScrollView::OnLButtonUp(nFlags, point);
}

void CViewView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	/*
	SetCapture();	//取得滑鼠訊息的接收權
	if (this == GetCapture())	//判斷滑鼠游標是否在正在執行的視窗中
	{
		LogicalCoor(&point);
		p1 = p2 = point;
	}
	*/
	CScrollView::OnLButtonDown(nFlags, point);
}

void CViewView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default


	CScrollView::OnMouseMove(nFlags, point);
}

CScrollBar* CViewView::GetScrollBarCtrl(int nBar) const
{
	// TODO: Add your specialized code here and/or call the base class
	return CScrollView::GetScrollBarCtrl(nBar);
}

BOOL CViewView::OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll) 
{
	// TODO: Add your specialized code here and/or call the base class
	test=true;
	Invalidate(true);
	return CScrollView::OnScroll(nScrollCode, nPos, bDoScroll);
}
void CViewView::DrawFrame()
{
	CPoint from1,from2;
	///////////////////////////
	from1.x=50;
	from1.y=50;
	from2.x=28850;
	from2.y=50;
	PhysicalCoor(&from1);
	PhysicalCoor(&from2);
	aDC->MoveTo ( from1 );
	aDC->LineTo ( from2 );
	///////////////////////////
	from1.x=28850;
	from1.y=50;
	from2.x=28850;
	from2.y=650;
	PhysicalCoor(&from1);
	PhysicalCoor(&from2);
	aDC->MoveTo ( from1 );
	aDC->LineTo ( from2 );
	//////////////////////////
	from1.x=28850;
	from1.y=650;
	from2.x=50;
	from2.y=650;
	PhysicalCoor(&from1);
	PhysicalCoor(&from2);
	aDC->MoveTo ( from1 );
	aDC->LineTo ( from2 );
	//////////////////////////
	from1.x=50;
	from1.y=650;
	from2.x=50;
	from2.y=50;
	PhysicalCoor(&from1);
	PhysicalCoor(&from2);
	aDC->MoveTo ( from1 );
	aDC->LineTo ( from2 );
	//////////////////////////
	CFont font;
	VERIFY(font.CreateFont(
	   12,                        // nHeight
	   0,                         // nWidth
	   0,                         // nEscapement
	   0,                         // nOrientation
	   FW_NORMAL,                 // nWeight
	   FALSE,                     // bItalic
	   FALSE,                     // bUnderline
	   0,                         // cStrikeOut
	   ANSI_CHARSET,              // nCharSet
	   OUT_DEFAULT_PRECIS,        // nOutPrecision
	   CLIP_DEFAULT_PRECIS,       // nClipPrecision
	   DEFAULT_QUALITY,           // nQuality
	   DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
	   "Arial"));                 // lpszFacename
	CFont* def_font = aDC->SelectObject(&font);
	//////////////////////////
	long i=0;
	char chrData[11][6]={"0.1","0.08","0.06","0.04","0.02","0.0","-0.02","-0.04","-0.06","-0.06","-0.1"};
	from1.x=30;
	from1.y=40;
	for(i=0;i<11;i++)
	{
		from1.x=25;
		from1.y=40+i*60;
		PhysicalCoor(&from1);
		aDC->TextOut(from1.x,from1.y,chrData[i]);
	}
	//////////////////////////
	long Data=0;
	char *chrData1;
	chrData1=new char[10];
	for(i=0;i<481;i++)
	{
		Data=0;
		Data+=i*60;
		itoa(Data,chrData1,10);
		from1.x=40+i*60;
		from1.y=655;
		PhysicalCoor(&from1);
		aDC->TextOut(from1.x,from1.y,chrData1);	
	}
	aDC->SelectObject(def_font);
	font.DeleteObject();
	///////////////////////////////////////////////////////
	VERIFY(font.CreateFont(
	   14,                        // nHeight
	   0,                         // nWidth
	   900,                       // nEscapement
	   0,                         // nOrientation
	   FW_NORMAL,                 // nWeight
	   FALSE,                     // bItalic
	   FALSE,                     // bUnderline
	   0,                         // cStrikeOut
	   ANSI_CHARSET,              // nCharSet
	   OUT_DEFAULT_PRECIS,        // nOutPrecision
	   CLIP_DEFAULT_PRECIS,       // nClipPrecision
	   DEFAULT_QUALITY,           // nQuality
	   DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
	   "新細明體"));              // lpszFacename
	CFont* def_font1 = aDC->SelectObject(&font);
	from1.x=3;
	from1.y=450;
	PhysicalCoor(&from1);
	aDC->TextOut(from1.x,from1.y,"伸 長 量 (um)");
	aDC->SelectObject(def_font1);
	font.DeleteObject();
	/////////////////////////////////////////////////////////
	VERIFY(font.CreateFont(
	   14,                        // nHeight
	   0,                         // nWidth
	   0,                         // nEscapement
	   0,                         // nOrientation
	   FW_NORMAL,                 // nWeight
	   FALSE,                     // bItalic
	   FALSE,                     // bUnderline
	   0,                         // cStrikeOut
	   ANSI_CHARSET,              // nCharSet
	   OUT_DEFAULT_PRECIS,        // nOutPrecision
	   CLIP_DEFAULT_PRECIS,       // nClipPrecision
	   DEFAULT_QUALITY,           // nQuality
	   DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
	   "新細明體"));              // lpszFacename
	CFont* def_font2 = aDC->SelectObject(&font);
	from1.x=14450;
	from1.y=680;
	PhysicalCoor(&from1);
	aDC->TextOut(from1.x,from1.y,"量測時間 (s)");
	aDC->SelectObject(def_font2);
	font.DeleteObject();
	/////////////////////////////////////////////////////////

}
void CViewView::DrawGrid()
{
	long i=0;
	COLORREF Bule=RGB(0,0,255);
	CPen BulePen(PS_DASH,1,Bule);
	CPoint from1,from2;
	from1.x=50;
	from1.y=650;
	from2.x=50;
	from2.y=50;
	CPen *oldPen=aDC->SelectObject(&BulePen); 
	for(i=1;i<480;i++)
	{
		from1.x=50+i*60;
		from1.y=650;
		from2.x=50+i*60;
		from2.y=50;
		PhysicalCoor(&from1);
		PhysicalCoor(&from2);
		aDC->MoveTo ( from1 );
		aDC->LineTo ( from2 );
	}
	for(i=1;i<10;i++)
	{
		from1.x=50;
		from1.y=50+i*60;
		from2.x=28850;
		from2.y=50+i*60;
		PhysicalCoor(&from1);
		PhysicalCoor(&from2);
		aDC->MoveTo ( from1 );
		aDC->LineTo ( from2 );
	}
	aDC->SelectObject(oldPen);  
}
int CViewView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO: Add your specialized creation code here
	aDC=new CClientDC(this); 
	return 0;
}
void CViewView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	double data;
	CPoint p3,p4;
	hFileMap[2] = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME2 ) ;
	mapView[2] = MapViewOfFile( hFileMap[2],FILE_MAP_WRITE, 0, 0, 0 ) ;
	if(test==true)
	{
		test=false;
		data=atof((LPTSTR)mapView[2]);
		data*=1000;
		data*=3;
		p2.x=50+lngtime;
		p2.y=350-data;
		p1=p2;
	}
	else
	{
		data=atof((LPTSTR)mapView[2]);
		data*=1000;
		data*=3;
		p2.x=50+lngtime;
		p2.y=350-data;
		Array1.Add(p1);
		Array1.Add(p2);
		p3=p1;
		p4=p2;
		PhysicalCoor(&p3);
		PhysicalCoor(&p4);
		aDC->MoveTo ( p3 );
		aDC->LineTo ( p4 );
		p1=p2;
	}
	lngtime++;
	CScrollView::OnTimer(nIDEvent);
}

void CViewView::OnStartTimer() 
{
	// TODO: Add your command handler code here
	SetTimer(1,10,NULL);
}

void CViewView::OnStopTimer() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

BOOL CViewView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return CScrollView::OnEraseBkgnd(pDC);
}

void CViewView::OnSize(UINT nType, int cx, int cy) 
{
	CScrollView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	//Origin = GetScrollPosition();
}
