// AUTODialogBarView.cpp : implementation of the CAUTODialogBarView class
//

#include "stdafx.h"
#include "AUTODialogBar.h"

#include "AUTODialogBarDoc.h"
#include "AUTODialogBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAUTODialogBarView

IMPLEMENT_DYNCREATE(CAUTODialogBarView, CView)

BEGIN_MESSAGE_MAP(CAUTODialogBarView, CView)
	//{{AFX_MSG_MAP(CAUTODialogBarView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAUTODialogBarView construction/destruction

CAUTODialogBarView::CAUTODialogBarView()
{
	// TODO: add construction code here

}

CAUTODialogBarView::~CAUTODialogBarView()
{
}

BOOL CAUTODialogBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAUTODialogBarView drawing

void CAUTODialogBarView::OnDraw(CDC* pDC)
{
	CAUTODialogBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CAUTODialogBarView printing

BOOL CAUTODialogBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAUTODialogBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAUTODialogBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAUTODialogBarView diagnostics

#ifdef _DEBUG
void CAUTODialogBarView::AssertValid() const
{
	CView::AssertValid();
}

void CAUTODialogBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAUTODialogBarDoc* CAUTODialogBarView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAUTODialogBarDoc)));
	return (CAUTODialogBarDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAUTODialogBarView message handlers
