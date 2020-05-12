// showfontView.cpp : implementation of the CShowfontView class
//

#include "stdafx.h"
#include "showfont.h"

#include "showfontDoc.h"
#include "showfontView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowfontView

IMPLEMENT_DYNCREATE(CShowfontView, CView)

BEGIN_MESSAGE_MAP(CShowfontView, CView)
	//{{AFX_MSG_MAP(CShowfontView)
	ON_COMMAND(ID_BUT1, OnBut1)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowfontView construction/destruction

CShowfontView::CShowfontView()
{
	// TODO: add construction code here

}

CShowfontView::~CShowfontView()
{
}

BOOL CShowfontView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShowfontView drawing

void CShowfontView::OnDraw(CDC* pDC)
{
	CShowfontDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CShowfontView printing

BOOL CShowfontView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CShowfontView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CShowfontView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CShowfontView diagnostics

#ifdef _DEBUG
void CShowfontView::AssertValid() const
{
	CView::AssertValid();
}

void CShowfontView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShowfontDoc* CShowfontView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShowfontDoc)));
	return (CShowfontDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowfontView message handlers

void CShowfontView::OnBut1() 
{
	int i,j;
	int R,G,B;
	COLORREF RGB1,RGB2;
	CFontDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
	   // Create the font using the selected font from CFontDialog.
	   LOGFONT lf;
	   memcpy(&lf, dlg.m_cf.lpLogFont, sizeof(LOGFONT));

	   CFont font;
	   VERIFY(font.CreateFontIndirect(&lf));

	   // Do something with the font just created...
	   CClientDC dc(this);
	   CFont* def_font = dc.SelectObject(&font);
	   dc.TextOut(5, 5, "Hello", 5);
	   dc.SelectObject(def_font);
	   // Done with the font. Delete the font object.
	   font.DeleteObject();
	   for(i=0;i<300;i++)
		for(j=0;j<300;j++)
		{
			RGB1=dc.GetPixel(i,j);
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
			dc.SetPixel(i,j,RGB2); 
		} 
	}	
}
