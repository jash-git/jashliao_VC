// TopShowView.cpp : implementation of the CTopShowView class
//

#include "stdafx.h"
#include "TopShow.h"

#include "TopShowDoc.h"
#include "TopShowView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTopShowView

IMPLEMENT_DYNCREATE(CTopShowView, CView)

BEGIN_MESSAGE_MAP(CTopShowView, CView)
	//{{AFX_MSG_MAP(CTopShowView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTopShowView construction/destruction

CTopShowView::CTopShowView()
{
	// TODO: add construction code here

}

CTopShowView::~CTopShowView()
{
}

BOOL CTopShowView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTopShowView drawing

void CTopShowView::OnDraw(CDC* pDC)
{
	CTopShowDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTopShowView printing

BOOL CTopShowView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTopShowView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTopShowView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTopShowView diagnostics

#ifdef _DEBUG
void CTopShowView::AssertValid() const
{
	CView::AssertValid();
}

void CTopShowView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTopShowDoc* CTopShowView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTopShowDoc)));
	return (CTopShowDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTopShowView message handlers
