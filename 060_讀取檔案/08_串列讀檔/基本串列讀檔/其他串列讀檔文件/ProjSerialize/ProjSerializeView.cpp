// ProjSerializeView.cpp : implementation of the CProjSerializeView class
//

#include "stdafx.h"
#include "ProjSerialize.h"

#include "ProjSerializeDoc.h"
#include "ProjSerializeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProjSerializeView

IMPLEMENT_DYNCREATE(CProjSerializeView, CView)

BEGIN_MESSAGE_MAP(CProjSerializeView, CView)
	//{{AFX_MSG_MAP(CProjSerializeView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProjSerializeView construction/destruction

CProjSerializeView::CProjSerializeView()
{
	// TODO: add construction code here

}

CProjSerializeView::~CProjSerializeView()
{
}

BOOL CProjSerializeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CProjSerializeView drawing

void CProjSerializeView::OnDraw(CDC* pDC)
{
	CProjSerializeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CProjSerializeView printing

BOOL CProjSerializeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CProjSerializeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CProjSerializeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CProjSerializeView diagnostics

#ifdef _DEBUG
void CProjSerializeView::AssertValid() const
{
	CView::AssertValid();
}

void CProjSerializeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProjSerializeDoc* CProjSerializeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProjSerializeDoc)));
	return (CProjSerializeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProjSerializeView message handlers
