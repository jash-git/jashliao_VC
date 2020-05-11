// test123View.cpp : implementation of the CTest123View class
//

#include "stdafx.h"
#include "test123.h"
#include "MainFrm.h"
#include "test123Doc.h"
#include "test123View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest123View

IMPLEMENT_DYNCREATE(CTest123View, CView)

BEGIN_MESSAGE_MAP(CTest123View, CView)
	//{{AFX_MSG_MAP(CTest123View)
	ON_COMMAND(ID_test, Ontest)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest123View construction/destruction

CTest123View::CTest123View()
{
	// TODO: add construction code here

}

CTest123View::~CTest123View()
{
}

BOOL CTest123View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest123View drawing

void CTest123View::OnDraw(CDC* pDC)
{
	CTest123Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTest123View printing

BOOL CTest123View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest123View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest123View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest123View diagnostics

#ifdef _DEBUG
void CTest123View::AssertValid() const
{
	CView::AssertValid();
}

void CTest123View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest123Doc* CTest123View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest123Doc)));
	return (CTest123Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest123View message handlers

void CTest123View::Ontest() 
{
	// TODO: Add your command handler code here
	CMainFrame *f1=(CMainFrame *)AfxGetMainWnd();
	f1->SetWindowPos(NULL,0,0,250,150,SWP_NOZORDER);

}
