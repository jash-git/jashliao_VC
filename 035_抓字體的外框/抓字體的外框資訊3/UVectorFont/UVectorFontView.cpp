// UVectorFontView.cpp : implementation of the CUVectorFontView class
//
/////////////////////////////////////////////////////////////////////
//作者：项坚煜（浙江工业大学信息工程学院）
//联系方式: QQ 125422950
//          e_mail unfirewood@etang.com
//
//
//
////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "UVectorFont.h"

#include "UVectorFontDoc.h"
#include "UVectorFontView.h"

#include "UTextInputDlg.h"
#include "math.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUVectorFontView

IMPLEMENT_DYNCREATE(CUVectorFontView, CView)

BEGIN_MESSAGE_MAP(CUVectorFontView, CView)
	//{{AFX_MSG_MAP(CUVectorFontView)
	ON_COMMAND(ID_TEXT_INPUT, OnTextInput)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUVectorFontView construction/destruction

CUVectorFontView::CUVectorFontView()
{
	// TODO: add construction code here
    m_sTextEdit = "";
    m_iFontHeight = 0;
    m_iFontSpace = 0;
    m_sFontFaceName = "";

}

CUVectorFontView::~CUVectorFontView()
{
}

BOOL CUVectorFontView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CUVectorFontView drawing

void CUVectorFontView::OnDraw(CDC* pDC)
{
	CUVectorFontDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

    drawOutLine(pDC);


}

/////////////////////////////////////////////////////////////////////////////
// CUVectorFontView printing

BOOL CUVectorFontView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CUVectorFontView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CUVectorFontView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CUVectorFontView diagnostics

#ifdef _DEBUG
void CUVectorFontView::AssertValid() const
{
	CView::AssertValid();
}

void CUVectorFontView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUVectorFontDoc* CUVectorFontView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUVectorFontDoc)));
	return (CUVectorFontDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUVectorFontView message handlers

void CUVectorFontView::OnTextInput() 
{
    CDC *pDC=GetDC();

	CUTextInputDlg dlg;
    if (dlg.DoModal() == IDOK)
    {
        m_sTextEdit = dlg.getsTextEdit();
        m_iFontHeight = dlg.getiFontHeight();
        m_iFontSpace = dlg.getiFontSpace();
        m_sFontFaceName = dlg.getsFontFaceName();
        Invalidate();
    }
	ReleaseDC(pDC);
}

FIXED CUVectorFontView::FloatToFixed( double d )
{
	long l;
	l = (long)(d * 65536L);
	return *(FIXED *)&l;
}

int CUVectorFontView::mapFXY(FIXED fxy)
{
	long   lxy;
	lxy = *(LONG *)&fxy;
	return (int)((double)(lxy)/65536.0);
}

void CUVectorFontView::drawOutLine(CDC *pDC)
{
    if (m_sTextEdit.IsEmpty())
        return;

	DWORD dwSize;
	HANDLE hMem;
	LPTTPOLYGONHEADER lpph;
	LPBYTE lpb;
	long cbOutline, cbTotal;
        
	MAT2 m2;
	GLYPHMETRICS gm;         
	TEXTMETRIC tm;
	CFont font;
	LOGFONT lf;
	CFont* def_font;
	CFontDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		// Create the font using the selected font from CFontDialog.
		memcpy(&lf, dlg.m_cf.lpLogFont, sizeof(LOGFONT));
		VERIFY(font.CreateFontIndirect(&lf));
	}
/*
    CFont font;
	VERIFY(font.CreateFont(
	   m_iFontHeight,             // nHeight
	   0,                         // nWidth
	   0,                         // nEscapement
	   0,                         // nOrientation
	   FW_NORMAL,                 // nWeight
	   FALSE,                     // bItalic
	   FALSE,                     // bUnderline
	   0,                         // cStrikeOut
	   ANSI_CHARSET,              // nCharSet
	   OUT_DEFAULT_PRECIS,        // nOutPrecision
	   CLIP_DEFAULT_PRECIS,       // nClipPrecision
	   DEFAULT_QUALITY,           // nQuality
	   DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
	   m_sFontFaceName));
*/
	CFont* pOldFont=pDC->SelectObject(&font);
    pDC->SelectObject(&font);
	pDC->GetTextMetrics(&tm);
   // Done with the font. Delete the font object.
   font.DeleteObject();
	m2.eM11 = FloatToFixed(1.0);
	m2.eM12 = FloatToFixed(0.0);
	m2.eM21 = FloatToFixed(0.0);
	m2.eM22 = FloatToFixed(1.0);

    //replace above code with follow code, there will be a surprise
/*  #define quartpi 3.1415926/4
    m2.eM11 = FloatToFixed(cos(quartpi));
	m2.eM12 = FloatToFixed(sin(quartpi));
	m2.eM21 = FloatToFixed(-sin(quartpi));
	m2.eM22 = FloatToFixed(cos(quartpi));
    
    // or 
/*  m2.eM11 = FloatToFixed(1.0);
	m2.eM12 = FloatToFixed(0);
	m2.eM21 = FloatToFixed(0.5);
	m2.eM22 = FloatToFixed(1);
*/
	int nChar = 0;  
    int x = 50; //startposition x-coordinate
    int y = 150; //startposition y-corrdinate
    for (int i = 0; i < m_sTextEdit.GetLength(); i++)
    {
        if (m_sTextEdit.GetAt(i) >= 0) //deal singlebyte char or multibyte char
            nChar = m_sTextEdit.GetAt(i);
        else
        {
            int th = m_sTextEdit.GetAt(i);
            int tl = m_sTextEdit.GetAt(i + 1);
            nChar = ((th & 0x00ff)<<8) + (tl & 0x00ff);
            i++;
        }
   
        CPen newpen;
        newpen.CreatePen(PS_DASHDOTDOT, 1, RGB(0,0,255));
        pDC->SelectObject(&newpen);
		dwSize = pDC->GetGlyphOutline(nChar,GGO_NATIVE,&gm,0L,NULL,&m2); //get the size of outline-information
		hMem=GlobalAlloc(GHND,dwSize);
		lpph=(LPTTPOLYGONHEADER)GlobalLock(hMem);
		pDC->GetGlyphOutline(nChar,GGO_NATIVE,&gm,dwSize,lpph,&m2); //get outline-line
		cbTotal = dwSize;
    
		while( cbTotal > 0 )
		{
			int xOld = mapFXY( lpph->pfxStart.x );
			int yOld = mapFXY( lpph->pfxStart.y );
            pDC->MoveTo(x+xOld, y-yOld );
			lpb   = (LPBYTE)lpph + sizeof(TTPOLYGONHEADER);
			cbOutline = (long)lpph->cb - sizeof(TTPOLYGONHEADER);
        
			while( cbOutline > 0 )
			{
				int  n;
				LPTTPOLYCURVE lpc;
				lpc = (LPTTPOLYCURVE)lpb;                                 
                drawOutLine(pDC,lpc->wType,lpc->cpfx,lpc->apfx, x, y);	//draw outline			
				n = sizeof(TTPOLYCURVE) + sizeof(POINTFX) * (lpc->cpfx - 1);
				lpb += n;
				cbOutline -= n;
			}                   

			pDC->LineTo(x+xOld,y-yOld);
			cbTotal -= lpph->cb;
			lpph     = (LPTTPOLYGONHEADER)lpb;
		}

	    GlobalUnlock(hMem);
	    GlobalFree(hMem);

        x += gm.gmCellIncX;  //control the next char position
        x += m_iFontSpace;
        y += gm.gmCellIncY;
    //  y += 50 * sin(x / 10);
    }
    pDC->SelectObject(pOldFont);
}

void CUVectorFontView::drawOutLine(CDC *pDC,int wType,int cpfx, POINTFX apfx[], int x, int y)
{
    CPoint lpPoint[1000];
	CPoint bezi[2];
    int i;
	for (i=0; i <cpfx;i++) 
	{
		lpPoint[i].x = x + mapFXY( apfx[i].x );
	    lpPoint[i].y = y - mapFXY( apfx[i].y );
	}
	switch (wType)
	{
	case TT_PRIM_LINE:
		for (i=0 ;i <cpfx;i++)
        {
			pDC->LineTo(lpPoint[i]); //you can replace lineto with polylineto, and so on
        }
        //pDC->PolylineTo(lpPoint,cpfx);
		break;
	case TT_PRIM_QSPLINE:
		for (i=0 ;i<cpfx;i++)   //if you replace lineto with curveto, it will be better
		    pDC->LineTo(lpPoint[i]);			
		break;
	default:
		MessageBox("字体不支持");
		break;
	}

}