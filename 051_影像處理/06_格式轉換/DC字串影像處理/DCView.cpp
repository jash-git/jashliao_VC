// DCView.cpp : implementation of the CDCView class
//

#include "stdafx.h"
#include "DC.h"

#include "DCDoc.h"
#include "DCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDCView

IMPLEMENT_DYNCREATE(CDCView, CView)

BEGIN_MESSAGE_MAP(CDCView, CView)
	//{{AFX_MSG_MAP(CDCView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDCView construction/destruction

CDCView::CDCView()
{
	// TODO: add construction code here

}

CDCView::~CDCView()
{
}

BOOL CDCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDCView drawing

void CDCView::OnDraw(CDC* pDC)
{
	
	int i,j;
	int R,G,B;
	COLORREF RGB1,RGB2;
	CDCDoc* pDoc = GetDocument();
	pDC->TextOut(10,10,"Struct");
	for(i=0;i<30;i++)
		for(j=0;j<30;j++)
		{
			RGB1=pDC->GetPixel(i,j);
			R=GetRValue(RGB1);
			G=GetGValue(RGB1);
			B=GetBValue(RGB1);
			if((B==255)&&(G==255) &&(R==255) )
			{
				RGB2=RGB(0,0,0);
			}
			else
			{
				RGB2=RGB(255,255,255);
			}
			pDC->SetPixel(i,j,RGB2); 
		} 
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDCView printing

BOOL CDCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDCView diagnostics

#ifdef _DEBUG
void CDCView::AssertValid() const
{
	CView::AssertValid();
}

void CDCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDCDoc* CDCView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDCDoc)));
	return (CDCDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDCView message handlers
