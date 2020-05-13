// MenuTextView.cpp : implementation of the CMenuTextView class
//

#include "stdafx.h"
#include "MenuText.h"

#include "MenuTextDoc.h"
#include "MenuTextView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenuTextView

IMPLEMENT_DYNCREATE(CMenuTextView, CView)

BEGIN_MESSAGE_MAP(CMenuTextView, CView)
	//{{AFX_MSG_MAP(CMenuTextView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenuTextView construction/destruction

CMenuTextView::CMenuTextView()
{
	// TODO: add construction code here

}

CMenuTextView::~CMenuTextView()
{
}

BOOL CMenuTextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMenuTextView drawing

void CMenuTextView::OnDraw(CDC* pDC)
{
	CMenuTextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMenuTextView printing

BOOL CMenuTextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMenuTextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMenuTextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMenuTextView diagnostics

#ifdef _DEBUG
void CMenuTextView::AssertValid() const
{
	CView::AssertValid();
}

void CMenuTextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMenuTextDoc* CMenuTextView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMenuTextDoc)));
	return (CMenuTextDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMenuTextView message handlers
