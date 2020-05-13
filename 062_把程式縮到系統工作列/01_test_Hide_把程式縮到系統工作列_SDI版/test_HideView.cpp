// test_HideView.cpp : implementation of the CTest_HideView class
//

#include "stdafx.h"
#include "test_Hide.h"

#include "test_HideDoc.h"
#include "test_HideView.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest_HideView

IMPLEMENT_DYNCREATE(CTest_HideView, CFormView)

BEGIN_MESSAGE_MAP(CTest_HideView, CFormView)
	//{{AFX_MSG_MAP(CTest_HideView)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest_HideView construction/destruction

CTest_HideView::CTest_HideView()
	: CFormView(CTest_HideView::IDD)
{
	//{{AFX_DATA_INIT(CTest_HideView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CTest_HideView::~CTest_HideView()
{
}

void CTest_HideView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTest_HideView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CTest_HideView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CTest_HideView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CTest_HideView printing

BOOL CTest_HideView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest_HideView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest_HideView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTest_HideView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CTest_HideView diagnostics

#ifdef _DEBUG
void CTest_HideView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTest_HideView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTest_HideDoc* CTest_HideView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest_HideDoc)));
	return (CTest_HideDoc*)m_pDocument;
}
#endif //_DEBUG


void CTest_HideView::OnButton1()  //step 10
{
	// TODO: Add your control notification handler code here
	CMainFrame *frame1;
	frame1=(CMainFrame *)AfxGetMainWnd();
	frame1->m_iWhichIcon=!frame1->m_iWhichIcon;
	frame1->m_trayIcon.SetIcon(IDI_ICON1);
	MessageBox("test1");
}

void CTest_HideView::OnButton2()  //step 11
{
	// TODO: Add your control notification handler code here
	CMainFrame *frame1;
	frame1=(CMainFrame *)AfxGetMainWnd();
	frame1->m_iWhichIcon=!frame1->m_iWhichIcon;
	frame1->m_trayIcon.SetIcon(IDI_ICON2);
	MessageBox("test1");
}
