// View2.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "View2.h"
#include "DibSection.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CDibSection k;
/////////////////////////////////////////////////////////////////////////////
// CView2

IMPLEMENT_DYNCREATE(CView2, CView)

CView2::CView2()
{
}

CView2::~CView2()
{
}


BEGIN_MESSAGE_MAP(CView2, CView)
	//{{AFX_MSG_MAP(CView2)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CView2 drawing

void CView2::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	CClientDC dc(this);
	k.Draw(dc,0,0,k.Width(),k.Height());
	//MessageBox("ok");
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CView2 diagnostics

#ifdef _DEBUG
void CView2::AssertValid() const
{
	CView::AssertValid();
}

void CView2::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
void CView2::ShowFigure(CDibSection &a)
{
	CClientDC dc(this);
	int x,y,w,h;
	w=a.Width();
	h=a.Height();
	k.Create(w,h,24);
	for(x=0;x<w;x++)
		for(y=0;y<h;y++)
		{
			BYTE *q=(BYTE *)a.GetBits(x,y);
			BYTE *q1=(BYTE *)k.GetBits(x,y);
			*q1++=*q++;
			*q1++=*q++;
			*q1++=*q++;

		}

	//k.Copy(a);
	a.Draw(dc,0,0,a.Width(),a.Height());
	
	
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CView2 message handlers

void CView2::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	Invalidate(true);
	// TODO: Add your message handler code here
	
}
