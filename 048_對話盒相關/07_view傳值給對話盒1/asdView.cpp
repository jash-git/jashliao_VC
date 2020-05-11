// asdView.cpp : implementation of the CAsdView class
//

#include "stdafx.h"
#include "asd.h"
#include "Dia.h"
#include "asdDoc.h"
#include "asdView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAsdView

IMPLEMENT_DYNCREATE(CAsdView, CView)

BEGIN_MESSAGE_MAP(CAsdView, CView)
	//{{AFX_MSG_MAP(CAsdView)
	ON_COMMAND(ID_t, Ont)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsdView construction/destruction

CAsdView::CAsdView()
{
	// TODO: add construction code here

}

CAsdView::~CAsdView()
{
}

BOOL CAsdView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAsdView drawing

void CAsdView::OnDraw(CDC* pDC)
{
	CAsdDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CAsdView printing

BOOL CAsdView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAsdView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAsdView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAsdView diagnostics

#ifdef _DEBUG
void CAsdView::AssertValid() const
{
	CView::AssertValid();
}

void CAsdView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAsdDoc* CAsdView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAsdDoc)));
	return (CAsdDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAsdView message handlers

void CAsdView::Ont() 
{
	// TODO: Add your command handler code here
	CDia a1(this);
	value=1001;
	a1.show(); 
	a1.DoModal();
	
	
}
