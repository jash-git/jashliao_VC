// GribbleWnd.cpp : implementation file
//

#include "stdafx.h"

#include "GribbleWnd.h"

#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGribbleWnd

CGribbleWnd::CGribbleWnd()
{

}

CGribbleWnd::~CGribbleWnd()
{
}


BEGIN_MESSAGE_MAP(CGribbleWnd, CWnd)
	//{{AFX_MSG_MAP(CGribbleWnd)
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_WM_ACTIVATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CGribbleWnd message handlers

BOOL CGribbleWnd::OnEraseBkgnd(CDC* pDC) 
{
    // 重画背景
    m_backColor = RGB(25,200,125);
    //生成一个新的画刷，用自定义的颜色刷新显示区域；
    CBrush cb(m_backColor);
    HBRUSH hOldBrush = (HBRUSH)pDC->SelectObject(cb);
    RECT rect = {0,0,m_pixelsX,m_pixelsY};
    pDC->FillRect(&rect,&cb);
    pDC->SelectObject(hOldBrush);
    cb.DeleteObject();
 
    return TRUE;
}

int CGribbleWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
 
    // load nifty cursor
    m_hCursor =LoadCursor(NULL,IDC_ARROW);
 
    // we'll want to do this in OnActivate too
    SetCursor(m_hCursor);
    ShowCursor(true);
 
    // since this window has its own DC we can stash it away... 
    m_pDC = GetDC();
 
    // get some screen stats...
    m_pixelsX = m_pDC->GetDeviceCaps(HORZRES);
    m_pixelsY = m_pDC->GetDeviceCaps(VERTRES);
    m_bitsPixel = m_pDC->GetDeviceCaps(BITSPIXEL);
     
    TRACE("Screen is %d by %d\n", m_pixelsX, m_pixelsY);
    TRACE("Color depth is %d bits per pixel\n", m_bitsPixel);
 
    // full screen - in whatever color OnEraseBkgnd is using...
    MoveWindow(0,0,m_pixelsX, m_pixelsY);
 
	return 0;
}

void CGribbleWnd::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

    Invalidate();

	//CWnd::OnLButtonDown(nFlags, point);
}

void CGribbleWnd::OnPaint() 
{
 
    CPaintDC dc(this); // device context for painting
    
 

    // normally we'd do this kind of initialization in OnCreate or the constructor,
    // but I want to localize things here, so we can treat OnPaint as a mini program!

    // start with a classic seed for the Lissajou... one time init...
    static int s_nLisXCoef = 1;
    static int s_nLisYCoef = 3;
    static int s_nLisYOffset = 44;

    ++s_nLisXCoef;
    ++s_nLisYCoef;

    
    int x,y;
    for (float t = 0; t < 32767; t+=0.2) {
 
        x = sin(s_nLisXCoef*t) * m_pixelsX/2 + m_pixelsX/2;
        y = sin(s_nLisYCoef*t+s_nLisYOffset) * m_pixelsY/2 + m_pixelsY/2;
 
        dc.SetPixel(x, y, RGB(255,80,255));
    }
   
    
    // Do not call CWnd::OnPaint() for painting messages
}

void CGribbleWnd::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// Commit CWnd suicide if user hits escape...
    if(VK_ESCAPE == nChar)
        DestroyWindow();
	
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CGribbleWnd::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
    CWnd::OnActivate(nState, pWndOther, bMinimized);
    
    // TODO: Add your message handler code here
    if(nState != WA_INACTIVE ) {
 
    }
}
