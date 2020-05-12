// ShowBmpView.cpp : implementation of the CShowBmpView class
//

#include "stdafx.h"
#include "ShowBmp.h"

#include "ShowBmpDoc.h"
#include "ShowBmpView.h"
#include "DibSection.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowBmpView

IMPLEMENT_DYNCREATE(CShowBmpView, CView)

BEGIN_MESSAGE_MAP(CShowBmpView, CView)
	//{{AFX_MSG_MAP(CShowBmpView)
	ON_COMMAND(ID_GetDisplay, OnGetDisplay)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowBmpView construction/destruction

CShowBmpView::CShowBmpView()
{
	// TODO: add construction code here

}

CShowBmpView::~CShowBmpView()
{
}

BOOL CShowBmpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShowBmpView drawing

void CShowBmpView::OnDraw(CDC* pDC)
{
	CShowBmpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CShowBmpView printing

BOOL CShowBmpView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CShowBmpView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CShowBmpView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CShowBmpView diagnostics

#ifdef _DEBUG
void CShowBmpView::AssertValid() const
{
	CView::AssertValid();
}

void CShowBmpView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShowBmpDoc* CShowBmpView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShowBmpDoc)));
	return (CShowBmpDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowBmpView message handlers

void CShowBmpView::OnGetDisplay() 
{
	// TODO: Add your command handler code here
	CDibSection dib1;
	CDC dc1;
	dc1.CreateDC ("DISPLAY",NULL,NULL,NULL);
	int Width=GetSystemMetrics(SM_CXSCREEN);
	int Height=GetSystemMetrics(SM_CYSCREEN);
	dib1.Create(Width,Height,24);
	BitBlt(CDibDC(dib1), 0, 0, Width, Width, dc1, 0, 0, SRCCOPY);
	dib1.SaveBmp("test1.bmp");
}
