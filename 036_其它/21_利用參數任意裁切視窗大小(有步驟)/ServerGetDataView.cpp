// ServerGetDataView.cpp : implementation of the CServerGetDataView class
//

#include "stdafx.h"
#include "ServerGetData.h"

#include "ServerGetDataDoc.h"
#include "ServerGetDataView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerGetDataView

IMPLEMENT_DYNCREATE(CServerGetDataView, CView)

BEGIN_MESSAGE_MAP(CServerGetDataView, CView)
	//{{AFX_MSG_MAP(CServerGetDataView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerGetDataView construction/destruction

CServerGetDataView::CServerGetDataView()
{
	// TODO: add construction code here

}

CServerGetDataView::~CServerGetDataView()
{
}

BOOL CServerGetDataView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CServerGetDataView drawing

void CServerGetDataView::OnDraw(CDC* pDC)
{
	CServerGetDataDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CServerGetDataView printing

BOOL CServerGetDataView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CServerGetDataView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CServerGetDataView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CServerGetDataView diagnostics

#ifdef _DEBUG
void CServerGetDataView::AssertValid() const
{
	CView::AssertValid();
}

void CServerGetDataView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CServerGetDataDoc* CServerGetDataView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CServerGetDataDoc)));
	return (CServerGetDataDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CServerGetDataView message handlers
