// VFWView.cpp : implementation of the CVFWView class
//

#include "stdafx.h"
#include "VFW.h"
#include <vfw.h>
#include "VFWDoc.h"
#include "VFWView.h"
#include "DibSection.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVFWView

IMPLEMENT_DYNCREATE(CVFWView, CView)

BEGIN_MESSAGE_MAP(CVFWView, CView)
	//{{AFX_MSG_MAP(CVFWView)
	ON_COMMAND(ID_GetNumber, OnGetNumber)
	ON_COMMAND(ID_Get, OnGet)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVFWView construction/destruction

CVFWView::CVFWView()
{
	// TODO: add construction code here

}

CVFWView::~CVFWView()
{
}

BOOL CVFWView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CVFWView drawing

void CVFWView::OnDraw(CDC* pDC)
{
	CVFWDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CVFWView printing

BOOL CVFWView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVFWView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVFWView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CVFWView diagnostics

#ifdef _DEBUG
void CVFWView::AssertValid() const
{
	CView::AssertValid();
}

void CVFWView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVFWDoc* CVFWView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVFWDoc)));
	return (CVFWDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVFWView message handlers

void CVFWView::OnGetNumber() 
{
	// TODO: Add your command handler code here
	char DrvName[80];
	char DrvVer[80];
	BOOL res;
	res=capGetDriverDescription(0,DrvName,sizeof(DrvName),DrvVer,sizeof(DrvVer));
	if(res)
	{
		MessageBox(DrvName);
		MessageBox(DrvVer);
		m_hWndCap=capCreateCaptureWindow("Video Window",
										WS_CHILD | WS_VISIBLE ,
										0, 0, 640, 480,this->m_hWnd,0);
		res=capDriverConnect(m_hWndCap,0);
		/*
		res=capOverlay(m_hWndCap,TRUE);
		if(res)
		{
			MessageBox("it is ok");
		}
		else
		{
			MessageBox("it is not ok");
		}
		*/
		capPreviewScale(m_hWndCap,FALSE);
		capPreviewRate(m_hWndCap,33);
		res=capPreview(m_hWndCap,TRUE);
	}
	else
	{
		MessageBox("¨S¦³");
	}
	//this->m_hWnd
}

void CVFWView::OnGet() 
{
	// TODO: Add your command handler code here
/*
	CDibSection dib;
	dib.Create(640,480,24);
	CClientDC dc1(this);
	int i,j;
	COLORREF c1;
	for(i=0;i<640;i++)
		for(j=0;j<480;j++)
		{
			BYTE *q1=(BYTE *)dib.GetBits(i,j);
			c1=dc1.GetPixel(i,j);
			*q1++=GetBValue(c1);
			*q1++=GetGValue(c1);
			*q1++=GetRValue(c1);		
		}
	dib.SaveBmp("C:\\t.bmp");
	MessageBox("ok");
//*/
	SetTimer(1,300,NULL);
}

void CVFWView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CDibSection dib;
	dib.Create(320,240,24);
	CClientDC dc1(this);
	int i,j;
	COLORREF c1;
	for(i=0;i<320;i++)
		for(j=0;j<240;j++)
		{
			BYTE *q1=(BYTE *)dib.GetBits(i,j);
			c1=dc1.GetPixel(i,j);
			*q1++=GetBValue(c1);
			*q1++=GetGValue(c1);
			*q1++=GetRValue(c1);		
		}
	dib.SaveBmp("C:\\t.bmp");
	KillTimer(1);
	MessageBox("ok");	
	CView::OnTimer(nIDEvent);
}
