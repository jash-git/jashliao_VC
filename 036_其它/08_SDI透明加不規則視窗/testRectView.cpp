// testRectView.cpp : implementation of the CTestRectView class
//

#include "stdafx.h"
#include "testRect.h"

#include "testRectDoc.h"
#include "testRectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestRectView

IMPLEMENT_DYNCREATE(CTestRectView, CView)

BEGIN_MESSAGE_MAP(CTestRectView, CView)
	//{{AFX_MSG_MAP(CTestRectView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestRectView construction/destruction

CTestRectView::CTestRectView()
{
	// TODO: add construction code here

}

CTestRectView::~CTestRectView()
{
}

BOOL CTestRectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestRectView drawing

void CTestRectView::OnDraw(CDC* pDC)
{
	CTestRectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTestRectView printing

BOOL CTestRectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestRectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestRectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestRectView diagnostics

#ifdef _DEBUG
void CTestRectView::AssertValid() const
{
	CView::AssertValid();
}

void CTestRectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestRectDoc* CTestRectView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestRectDoc)));
	return (CTestRectDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestRectView message handlers
