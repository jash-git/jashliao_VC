// FullScreenView.cpp : implementation of the CFullScreenView class
//

#include "stdafx.h"
#include "FullScreen.h"

#include "FullScreenDoc.h"
#include "FullScreenView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFullScreenView

IMPLEMENT_DYNCREATE(CFullScreenView, CView)

BEGIN_MESSAGE_MAP(CFullScreenView, CView)
	//{{AFX_MSG_MAP(CFullScreenView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFullScreenView construction/destruction

CFullScreenView::CFullScreenView()
{
	// TODO: add construction code here

}

CFullScreenView::~CFullScreenView()
{
}

BOOL CFullScreenView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFullScreenView drawing

void CFullScreenView::OnDraw(CDC* pDC)
{
	CFullScreenDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CFullScreenView printing

BOOL CFullScreenView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFullScreenView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFullScreenView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFullScreenView diagnostics

#ifdef _DEBUG
void CFullScreenView::AssertValid() const
{
	CView::AssertValid();
}

void CFullScreenView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFullScreenDoc* CFullScreenView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFullScreenDoc)));
	return (CFullScreenDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFullScreenView message handlers
