// MenuCtrlView.cpp : implementation of the CMenuCtrlView class
//

#include "stdafx.h"
#include "MenuCtrl.h"

#include "MenuCtrlDoc.h"
#include "MenuCtrlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
bool bolCh1;
/////////////////////////////////////////////////////////////////////////////
// CMenuCtrlView

IMPLEMENT_DYNCREATE(CMenuCtrlView, CView)

BEGIN_MESSAGE_MAP(CMenuCtrlView, CView)
	//{{AFX_MSG_MAP(CMenuCtrlView)
	ON_COMMAND(ID_test1, Ontest1)
	ON_UPDATE_COMMAND_UI(ID_test1, OnUpdatetest1)
	ON_COMMAND(ID_test2, Ontest2)
	ON_UPDATE_COMMAND_UI(ID_test2, OnUpdatetest2)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenuCtrlView construction/destruction

CMenuCtrlView::CMenuCtrlView()
{
	// TODO: add construction code here
	bolCh1=true;
	
}

CMenuCtrlView::~CMenuCtrlView()
{
}

BOOL CMenuCtrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMenuCtrlView drawing

void CMenuCtrlView::OnDraw(CDC* pDC)
{
	CMenuCtrlDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMenuCtrlView printing

BOOL CMenuCtrlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMenuCtrlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMenuCtrlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMenuCtrlView diagnostics

#ifdef _DEBUG
void CMenuCtrlView::AssertValid() const
{
	CView::AssertValid();
}

void CMenuCtrlView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMenuCtrlDoc* CMenuCtrlView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMenuCtrlDoc)));
	return (CMenuCtrlDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMenuCtrlView message handlers

void CMenuCtrlView::Ontest1() 
{
	// TODO: Add your command handler code here
	MessageBox("test1");
	bolCh1=true;
	
}

void CMenuCtrlView::OnUpdatetest1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(!bolCh1); 
}

void CMenuCtrlView::Ontest2() 
{
	// TODO: Add your command handler code here
	MessageBox("test2");
	bolCh1=false;
}

void CMenuCtrlView::OnUpdatetest2(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(bolCh1);
}
