// tool2View.cpp : implementation of the CTool2View class
//

#include "stdafx.h"
#include "tool2.h"

#include "tool2Doc.h"
#include "tool2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTool2View

IMPLEMENT_DYNCREATE(CTool2View, CView)

BEGIN_MESSAGE_MAP(CTool2View, CView)
	//{{AFX_MSG_MAP(CTool2View)
	ON_COMMAND(ID_BU1, OnBu1)
	ON_COMMAND(ID_BU2, OnBu2)
	ON_COMMAND(ID_BU3, OnBu3)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTool2View construction/destruction

CTool2View::CTool2View()
{
	// TODO: add construction code here

}

CTool2View::~CTool2View()
{
}

BOOL CTool2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTool2View drawing

void CTool2View::OnDraw(CDC* pDC)
{
	CTool2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTool2View printing

BOOL CTool2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTool2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTool2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTool2View diagnostics

#ifdef _DEBUG
void CTool2View::AssertValid() const
{
	CView::AssertValid();
}

void CTool2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTool2Doc* CTool2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTool2Doc)));
	return (CTool2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTool2View message handlers

BOOL CTool2View::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CTool2View::OnBu1() 
{
	// TODO: Add your command handler code here
	MessageBox("Bu1");
}

void CTool2View::OnBu2() 
{
	// TODO: Add your command handler code here
	MessageBox("Bu2");
}

void CTool2View::OnBu3() 
{
	// TODO: Add your command handler code here
	MessageBox("Bu3");
}
