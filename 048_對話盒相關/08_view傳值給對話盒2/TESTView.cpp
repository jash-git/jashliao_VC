// TESTView.cpp : implementation of the CTESTView class
//

#include "stdafx.h"
#include "TEST.h"
#include "Dia.h"
#include "TESTDoc.h"
#include "TESTView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTESTView

IMPLEMENT_DYNCREATE(CTESTView, CView)

BEGIN_MESSAGE_MAP(CTESTView, CView)
	//{{AFX_MSG_MAP(CTESTView)
	ON_COMMAND(ID_set, Onset)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTESTView construction/destruction

CTESTView::CTESTView()
{
	// TODO: add construction code here

}

CTESTView::~CTESTView()
{
}

BOOL CTESTView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTESTView drawing

void CTESTView::OnDraw(CDC* pDC)
{
	CTESTDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTESTView printing

BOOL CTESTView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTESTView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTESTView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTESTView diagnostics

#ifdef _DEBUG
void CTESTView::AssertValid() const
{
	CView::AssertValid();
}

void CTESTView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTESTDoc* CTESTView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTESTDoc)));
	return (CTESTDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTESTView message handlers

void CTESTView::Onset() 
{
	// TODO: Add your command handler code here
	CDia k(this);
	k.show(100);
	k.DoModal(); 
}
