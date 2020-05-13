// testPopMenusView.cpp : implementation of the CTestPopMenusView class
//

#include "stdafx.h"
#include "testPopMenus.h"

#include "testPopMenusDoc.h"
#include "testPopMenusView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestPopMenusView

IMPLEMENT_DYNCREATE(CTestPopMenusView, CView)

BEGIN_MESSAGE_MAP(CTestPopMenusView, CView)
	//{{AFX_MSG_MAP(CTestPopMenusView)
	ON_COMMAND(ID_Pop1, OnPop1)
	ON_COMMAND(ID_Pop2, OnPop2)
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestPopMenusView construction/destruction

CTestPopMenusView::CTestPopMenusView()
{
	// TODO: add construction code here

}

CTestPopMenusView::~CTestPopMenusView()
{
}

BOOL CTestPopMenusView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestPopMenusView drawing

void CTestPopMenusView::OnDraw(CDC* pDC)
{
	CTestPopMenusDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTestPopMenusView printing

BOOL CTestPopMenusView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestPopMenusView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestPopMenusView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestPopMenusView diagnostics

#ifdef _DEBUG
void CTestPopMenusView::AssertValid() const
{
	CView::AssertValid();
}

void CTestPopMenusView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestPopMenusDoc* CTestPopMenusView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestPopMenusDoc)));
	return (CTestPopMenusDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestPopMenusView message handlers

void CTestPopMenusView::OnPop1() 
{
	// TODO: Add your command handler code here
	MessageBox("Pop1");
}

void CTestPopMenusView::OnPop2() 
{
	// TODO: Add your command handler code here
	MessageBox("Pop2");
}

void CTestPopMenusView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMenu menu;
	menu.LoadMenu(IDR_MENU1); 
	pPopMenu=menu.GetSubMenu(0);
	pPopMenu->TrackPopupMenu(TPM_CENTERALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);
	menu.Detach(); 
}
