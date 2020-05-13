// testView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "test.h"
#include "RungeKutta.h"
#include "testDoc.h"
#include "testView.h"
#include <stdio.h>
#include <math.h>
#include <sys\timeb.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	//{{AFX_MSG_MAP(CTestView)
	ON_COMMAND(ID_RungeKutta, OnRungeKutta)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestView construction/destruction

CTestView::CTestView()
{
	// TODO: add construction code here

}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestView drawing

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTestView printing

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestView diagnostics

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestView message handlers

void CTestView::OnRungeKutta() 
{
	// TODO: Add your command handler code here
	FILE *s,*c;
	struct timeb t1,t2;
	float u=0;
	//RungeKutta_SixOder RungeKutta1(1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0,11.0,12.0,13.0,0.01);
	RungeKutta_SixOder RungeKutta1(1,2,3,4,1,0.55,2,0,0,0,0,0,2,0.01);
	c=fopen("cos.txt","w");
	s=fopen("sin.txt","w");
	for(int i=0;i<=2000;i++)
	{
		u=1.0;
		//u=10*sin(i/pi);
		fprintf(s,"%f\n",u);
		if (i==1)
			ftime(&t1);
		RungeKutta1.RungeKutta_SixOder_compute(u,0.0,0.0,0.0,0.0,0.0);
		if (i==1)
			ftime(&t2);
		fprintf(c,"%f\n",RungeKutta1.Y);
		//fprintf(s,"%f\n",RungeKutta1.Yp5);
		
	}
	fclose(c);
	fclose(s);
	MessageBox("test");
}
