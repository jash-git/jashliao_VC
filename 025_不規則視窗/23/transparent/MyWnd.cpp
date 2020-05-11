// MyWnd.cpp : implementation file
//

#include "stdafx.h"
#include "transparent.h"
#include "MyWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyWnd

CMyWnd::CMyWnd()
{

}

CMyWnd::~CMyWnd()
{
	
}


BEGIN_MESSAGE_MAP(CMyWnd, CWnd)
	//{{AFX_MSG_MAP(CMyWnd)
	ON_WM_ERASEBKGND()
	ON_WM_NCHITTEST()

	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMyWnd message handlers

BOOL CMyWnd::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rectWnd;
	this->GetWindowRect(&rectWnd);

	CDC memDC;
	CBitmap	myBitmap,*pOldBitmap;
	myBitmap.LoadBitmap(m_nBitmapId);
	memDC.CreateCompatibleDC(pDC);
	pOldBitmap = memDC.SelectObject(&myBitmap);
	pDC->BitBlt(0,0,rectWnd.Width(),rectWnd.Height(), &memDC,0,0,SRCCOPY);

	// 将设备还原
	memDC.SelectObject(pOldBitmap );
	
	return TRUE;
}

UINT CMyWnd::OnNcHitTest(CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    UINT nHitTest = CWnd :: OnNcHitTest(point) ; 
    return (nHitTest == HTCLIENT) ? HTCAPTION : nHitTest ;	

}

void CMyWnd::Display(CDC *pDC, UINT nMaskId)
{
	// 获得窗体矩形	
	CRect rectWnd;
	this->GetWindowRect(rectWnd);

	// 读取位图资源
	CBitmap myBitmap,*pOldBitmap;
	myBitmap.LoadBitmap(nMaskId);

	// 创建"内存一致"设备
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	
	// 选择绘图设备
	pOldBitmap = memDC.SelectObject(&myBitmap);

	// 创建窗体的初始区域
	CRgn rgnWnd,rgnTemp;
	rgnWnd.CreateRectRgn(0,0,rectWnd.Width(),rectWnd.Height());

	int nWidth,nHeight;
	COLORREF color;
	for (nWidth = 0;nWidth <= rectWnd.Width()-1;nWidth++)
	{
		for (nHeight = 0;nHeight <= rectWnd.Height();nHeight++)
		{
			color = memDC.GetPixel(nWidth,nHeight);
			
			// 当象素是白色时，去掉该点
			if (color == RGB(255,255,255))
			{
				rgnTemp.CreateRectRgn(nWidth,nHeight,nWidth+1,nHeight+1);
				rgnWnd.CombineRgn(&rgnWnd,&rgnTemp,RGN_XOR);
				rgnTemp.DeleteObject();	
			}
		}
	}

	memDC.SelectObject(pOldBitmap);
	SetWindowRgn((HRGN)rgnWnd,TRUE);
}

void CMyWnd::Initialize(LPCTSTR lpszName, CRect &rectWnd, UINT nMaskId, UINT nShowId)
{
	this->CreateEx(0,AfxRegisterWndClass(0),lpszName,WS_POPUP | WS_SYSMENU,rectWnd,NULL,
				NULL,NULL);
	this->Display(GetWindowDC(),nMaskId);
	m_nBitmapId = nShowId;


}


void CMyWnd::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar==VK_ESCAPE)
	{

	//	dlg.PostMessage(WM_QUIT);
PostMessage(WM_QUIT);
//AfxGetApp()->ExitInstance();
	}
	CWnd::OnChar(nChar, nRepCnt, nFlags);
}
