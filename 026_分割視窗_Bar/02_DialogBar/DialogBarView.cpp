// DialogBarView.cpp : implementation of the CDialogBarView class
//

#include "stdafx.h"
#include "DialogBar.h"

#include "DialogBarDoc.h"
#include "DialogBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogBarView

IMPLEMENT_DYNCREATE(CDialogBarView, CView)

BEGIN_MESSAGE_MAP(CDialogBarView, CView)
	//{{AFX_MSG_MAP(CDialogBarView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogBarView construction/destruction

CDialogBarView::CDialogBarView()
{
	// TODO: add construction code here

}

CDialogBarView::~CDialogBarView()
{
}

BOOL CDialogBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDialogBarView drawing

void CDialogBarView::OnDraw(CDC* pDC)
{
	CDialogBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDialogBarView printing

BOOL CDialogBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDialogBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDialogBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDialogBarView diagnostics

#ifdef _DEBUG
void CDialogBarView::AssertValid() const
{
	CView::AssertValid();
}

void CDialogBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDialogBarDoc* CDialogBarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDialogBarDoc)));
	return (CDialogBarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDialogBarView message handlers
