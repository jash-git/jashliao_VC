// viewView.cpp : implementation of the CViewView class
//

#include "stdafx.h"
#include "view.h"
#include "ExternalVarApp2View.h"
#include "viewDoc.h"
#include "viewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewView

IMPLEMENT_DYNCREATE(CViewView, CScrollView)

BEGIN_MESSAGE_MAP(CViewView, CScrollView)
	//{{AFX_MSG_MAP(CViewView)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
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
	POSITION pos;
	CView::OnDraw(pDC);	//呼叫CView類別的OnDraw成員函數
	DrawFrame();
	DrawGrid();
	pos=list1.GetHeadPosition();
	while(pos !=NULL)
	{
		p1=list1.GetNext(pos);
		p2=list1.GetNext(pos);
		PhysicalCoor(&p1);
		aDC->MoveTo ( p1 );
		PhysicalCoor(&p2);
		aDC->LineTo ( p2 );
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
	if (this == GetCapture())	//判斷滑鼠游標是否在正在執行的視窗中
	{
		CClientDC aDC(this);	//建立畫布
		aDC.SetROP2(R2_NOT);	//設定繪圖模式
		OnPrepareDC(&aDC);	//修正畫布 ScrollView new
		LogicalCoor(&point);	//轉換至邏輯座標 ScrollView new
		aDC.MoveTo ( p1 );
		p2=point;
		aDC.LineTo ( p2 );
		list1.AddTail(p1);
		list1.AddTail(p2);
	}
	// 畫出新線段 //
	PhysicalCoor(&p1);	//轉換至物理座標 ScrollView new
	PhysicalCoor(&p2);	//轉換至物理座標 ScrollView new
	CRect rect(p1, p2);//建立重繪區域的矩形
	rect.NormalizeRect();	//將矩形正規化
	rect.InflateRect(5,5);	//加大重繪區域的矩形範圍
	InvalidateRect(&rect,true);	//標示重繪區域，並引發WM_PAINT訊息

	ReleaseCapture();	//釋放滑鼠訊息接收權
	
	CScrollView::OnLButtonUp(nFlags, point);
}

void CViewView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCapture();	//取得滑鼠訊息的接收權
	if (this == GetCapture())	//判斷滑鼠游標是否在正在執行的視窗中
	{
		LogicalCoor(&point);
		p1 = p2 = point;
	}
	CScrollView::OnLButtonDown(nFlags, point);
}

void CViewView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	/*
	if (this == GetCapture())	//判斷滑鼠游標是否在正在執行的視窗中
	{
		CClientDC aDC(this);	//建立畫布
		aDC.SetROP2(R2_NOT);	//設定繪圖模式
		OnPrepareDC(&aDC);	//修正畫布 ScrollView new
		LogicalCoor(&point);	//轉換至邏輯座標 ScrollView new
		aDC.MoveTo ( p1 );
		p2=point;
		aDC.LineTo ( p2 );
	}
	*/

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
