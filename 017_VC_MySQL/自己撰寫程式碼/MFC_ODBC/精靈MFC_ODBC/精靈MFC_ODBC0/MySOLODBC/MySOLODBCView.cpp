// MySOLODBCView.cpp : implementation of the CMySOLODBCView class
//

#include "stdafx.h"
#include "MySOLODBC.h"

#include "MySOLODBCSet.h"
#include "MySOLODBCDoc.h"
#include "MySOLODBCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMySOLODBCView

IMPLEMENT_DYNCREATE(CMySOLODBCView, CRecordView)

BEGIN_MESSAGE_MAP(CMySOLODBCView, CRecordView)
	//{{AFX_MSG_MAP(CMySOLODBCView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMySOLODBCView construction/destruction

CMySOLODBCView::CMySOLODBCView()
	: CRecordView(CMySOLODBCView::IDD)
{
	//{{AFX_DATA_INIT(CMySOLODBCView)
		// NOTE: the ClassWizard will add member initialization here
	m_pSet = NULL;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CMySOLODBCView::~CMySOLODBCView()
{
}

void CMySOLODBCView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMySOLODBCView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CMySOLODBCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void CMySOLODBCView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_mySOLODBCSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CMySOLODBCView printing

BOOL CMySOLODBCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMySOLODBCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMySOLODBCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMySOLODBCView diagnostics

#ifdef _DEBUG
void CMySOLODBCView::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMySOLODBCView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMySOLODBCDoc* CMySOLODBCView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMySOLODBCDoc)));
	return (CMySOLODBCDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMySOLODBCView database support
CRecordset* CMySOLODBCView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// CMySOLODBCView message handlers
