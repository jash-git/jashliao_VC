// framviewView.cpp : implementation of the CFramviewView class
//

#include "stdafx.h"
#include "framview.h"

#include "framviewDoc.h"
#include "framviewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFramviewView

IMPLEMENT_DYNCREATE(CFramviewView, CFormView)

BEGIN_MESSAGE_MAP(CFramviewView, CFormView)
	//{{AFX_MSG_MAP(CFramviewView)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFramviewView construction/destruction

CFramviewView::CFramviewView()
	: CFormView(CFramviewView::IDD)
{
	//{{AFX_DATA_INIT(CFramviewView)
	m_v1 = 0.0f;
	m_v2 = 0.0f;
	m_v3 = 0.0;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CFramviewView::~CFramviewView()
{
}

void CFramviewView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFramviewView)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	DDX_Text(pDX, IDC_EDIT2, m_v2);
	DDX_Text(pDX, IDC_EDIT3, m_v3);
	//}}AFX_DATA_MAP
}

BOOL CFramviewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CFramviewView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CFramviewView printing

BOOL CFramviewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFramviewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFramviewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CFramviewView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CFramviewView diagnostics

#ifdef _DEBUG
void CFramviewView::AssertValid() const
{
	CFormView::AssertValid();
}

void CFramviewView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CFramviewDoc* CFramviewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFramviewDoc)));
	return (CFramviewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFramviewView message handlers

void CFramviewView::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_v3=m_v1+m_v2;
	UpdateData(false);
}

void CFramviewView::OnButton2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_v3=m_v1-m_v2;
	UpdateData(false);
}

void CFramviewView::OnButton3() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_v3=m_v1*m_v2;
	UpdateData(false);
}

void CFramviewView::OnButton4() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_v3=m_v1/m_v2;
	UpdateData(false);	
}
