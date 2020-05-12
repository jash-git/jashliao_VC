// Image1View.cpp : implementation of the CImage1View class
//

#include "stdafx.h"
#include "Image1.h"
#include "MainFrm.h"
#include "Image1Doc.h"
#include "Image1View.h"
#include "ShowBmp.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImage1View

IMPLEMENT_DYNCREATE(CImage1View, CFormView)

BEGIN_MESSAGE_MAP(CImage1View, CFormView)
	//{{AFX_MSG_MAP(CImage1View)
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_SLIDER1, OnOutofmemorySlider1)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImage1View construction/destruction

CImage1View::CImage1View()
	: CFormView(CImage1View::IDD)
{
	//{{AFX_DATA_INIT(CImage1View)
	m_v1 = 0;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CImage1View::~CImage1View()
{
}

void CImage1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImage1View)
	DDX_Control(pDX, IDC_SLIDER1, m_sl1);
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	//}}AFX_DATA_MAP
}

BOOL CImage1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CImage1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	m_sl1.SetRange(0,255); 


}

/////////////////////////////////////////////////////////////////////////////
// CImage1View printing

BOOL CImage1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CImage1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CImage1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CImage1View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CImage1View diagnostics

#ifdef _DEBUG
void CImage1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CImage1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CImage1Doc* CImage1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImage1Doc)));
	return (CImage1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImage1View message handlers

void CImage1View::OnOutofmemorySlider1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	MessageBox("test");
	*pResult = 0;
}

void CImage1View::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CMainFrame *Frame;
	Frame=(CMainFrame*)AfxGetMainWnd();
	switch(pScrollBar->GetDlgCtrlID())
	{
	case IDC_SLIDER1:
		m_v1=m_sl1.GetPos(); 
		break;
	}
	UpdateData(false);
	//CMainFrame *Frame;
	Frame=(CMainFrame*)AfxGetMainWnd();
	Frame->ShowData(m_v1);
	CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CImage1View::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CShowBmp *CShowBmp1;
	UpdateData(true);
	m_sl1.SetPos(m_v1); 
	UpdateData(false);
	CMainFrame *Frame;
	Frame=(CMainFrame*)AfxGetMainWnd();
	//Frame->ShowData(m_v1); 
	CShowBmp1=(CShowBmp*)Frame->StaticSplit.GetPane(0,1);
	CShowBmp1->Data(m_v1);
}
