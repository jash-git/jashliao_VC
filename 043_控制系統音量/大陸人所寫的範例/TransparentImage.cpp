#include "StdAfx.h"
#include "TransparentImage.h"

#define ROP4_TRANSPARENTBLIT		0xCCAA0020
#define SRCMASK						0x00220326
#define	MASKCOLOR					RGB(255,0,255)//指定要透明的颜色

CTransparentImage::CTransparentImage()
{}
CTransparentImage::~CTransparentImage()
{}

BEGIN_MESSAGE_MAP( CTransparentImage, CStatic)
	//{{AFX_MSG_MAP( CTransparentImage)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CTransparentImage::OnPaint() 
{
	HBITMAP hBmp = GetBitmap() ;
	if( hBmp == NULL)
	{
		Default() ;
		return ;
	}

	CRect rc ;
	GetClientRect( &rc) ;
	int nW=rc.Width();
	int nH=rc.Height();	

	CPaintDC dc( this) ;

	CDC		 cDC ;
	cDC.CreateCompatibleDC( &dc) ;
	CBitmap  cBmp ;
	cBmp.CreateCompatibleBitmap( &dc, nW, nH) ;
	CBitmap* pOldBmp = cDC.SelectObject( &cBmp) ;

	///////////////////创建要透明颜色的位图////////////////////////
	CDC		 cMaskDC ;                             
	cMaskDC.CreateCompatibleDC( &dc) ;
	CBitmap  cMaskBmp ;
	cMaskBmp.CreateBitmap(nW, nH, 1, 1, NULL) ;   
	CBitmap* pOldMaskBmp = cMaskDC.SelectObject( &cMaskBmp) ;

	cDC.FillSolidRect( &rc, MASKCOLOR) ; 

	///////////////////Blit the bitmap to the buffer////////////////////////
	CDC		 cMemDC ;
	cMemDC.CreateCompatibleDC( &dc) ;
	CBitmap* pOldMemBmp = cMemDC.SelectObject( CBitmap::FromHandle( hBmp)) ;
	cDC.BitBlt(0,0, nW, nH, &cMemDC,0,0, SRCCOPY) ;
	cMemDC.SelectObject( pOldMemBmp) ;

	//////////////////Create the mask.//////////////////////////////////////
	COLORREF crOldBack = cDC.SetBkColor(MASKCOLOR) ;
	cMaskDC.BitBlt(0,0, nW, nH, &cDC,0,0, SRCCOPY) ;
	cDC.SetBkColor( crOldBack) ;

	////////////////////////////////////////////////////////////////////////////
	if( ! dc.MaskBlt(0,0, nW, nH,&cDC,0,0,cMaskBmp,0,0,ROP4_TRANSPARENTBLIT))
	{
		CDC		 cCopyDC ;
		cCopyDC.CreateCompatibleDC( &dc) ;
		CBitmap  cCopyBmp ;
		cCopyBmp.CreateCompatibleBitmap( &dc, nW, nH) ;
		CBitmap* pOldCopyBmp = cCopyDC.SelectObject( &cCopyBmp) ;

		cCopyDC.BitBlt(0,0, nW, nH, &dc,0,0, SRCCOPY) ;
		cCopyDC.BitBlt(0,0, nW, nH, &cMaskDC,0,0, SRCAND) ;
		cDC.BitBlt(0,0, nW, nH, &cMaskDC,0,0, SRCMASK) ;
		cCopyDC.BitBlt(0,0, nW, nH, &cDC,0,0, SRCPAINT) ;
		dc.BitBlt(0,0, nW, nH, &cCopyDC,0,0, SRCCOPY) ;

		cCopyDC.SelectObject( pOldCopyBmp) ;
	}

	////////////////////////////////////////////////////////////////////////////
	cMaskDC.SelectObject( pOldMaskBmp) ;
	cDC.SelectObject( pOldBmp) ;
}
