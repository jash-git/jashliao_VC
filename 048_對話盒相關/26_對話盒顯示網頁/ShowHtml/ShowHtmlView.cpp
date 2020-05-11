// ShowHtmlView.cpp : implementation of the CShowHtmlView class
//

#include "stdafx.h"
#include "ShowHtml.h"

#include "ShowHtmlDoc.h"
#include "ShowHtmlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowHtmlView

IMPLEMENT_DYNCREATE(CShowHtmlView, CView)

BEGIN_MESSAGE_MAP(CShowHtmlView, CView)
	//{{AFX_MSG_MAP(CShowHtmlView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowHtmlView construction/destruction

CShowHtmlView::CShowHtmlView()
{
	// TODO: add construction code here

}

CShowHtmlView::~CShowHtmlView()
{
}

BOOL CShowHtmlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShowHtmlView drawing

void CShowHtmlView::OnDraw(CDC* pDC)
{
	CShowHtmlDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CShowHtmlView printing

BOOL CShowHtmlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CShowHtmlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CShowHtmlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CShowHtmlView diagnostics

#ifdef _DEBUG
void CShowHtmlView::AssertValid() const
{
	CView::AssertValid();
}

void CShowHtmlView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShowHtmlDoc* CShowHtmlView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShowHtmlDoc)));
	return (CShowHtmlDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowHtmlView message handlers
