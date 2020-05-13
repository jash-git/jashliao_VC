// kkkkView.cpp : implementation of the CKkkkView class
//

#include "stdafx.h"
#include "kkkk.h"

#include "kkkkDoc.h"
#include "kkkkView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKkkkView

IMPLEMENT_DYNCREATE(CKkkkView, CView)

BEGIN_MESSAGE_MAP(CKkkkView, CView)
	//{{AFX_MSG_MAP(CKkkkView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKkkkView construction/destruction

CKkkkView::CKkkkView()
{
	// TODO: add construction code here

}

CKkkkView::~CKkkkView()
{
}

BOOL CKkkkView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CKkkkView drawing

void CKkkkView::OnDraw(CDC* pDC)
{
	CKkkkDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CKkkkView printing

BOOL CKkkkView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CKkkkView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CKkkkView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CKkkkView diagnostics

#ifdef _DEBUG
void CKkkkView::AssertValid() const
{
	CView::AssertValid();
}

void CKkkkView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKkkkDoc* CKkkkView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKkkkDoc)));
	return (CKkkkDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKkkkView message handlers
