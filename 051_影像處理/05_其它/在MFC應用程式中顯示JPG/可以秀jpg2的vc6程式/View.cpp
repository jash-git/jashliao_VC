/////////////////////////////////////////////////////////////////////////////
// Project：MYIMGAPP
// Author：NorthTibet
// Date：星期四, 九月 26, 2002
// Description：通过定制的C++类在MFC框架中轻松显示多种格式的图象
//
/////////////////////////////////////////////////////////////////////////////
// View.cpp : implementation of the CPictureView class
//
#include "StdAfx.h"
#include "View.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////////////////////////////////////////////////////////////////
// CPictureView
//
IMPLEMENT_DYNCREATE(CPictureView, CScrollView)

BEGIN_MESSAGE_MAP(CPictureView, CScrollView)
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_COMMAND_RANGE(ID_VIEW_TOFIT, ID_VIEW100, OnViewScale)
	ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_TOFIT, ID_VIEW100, OnUpdateViewScale)
END_MESSAGE_MAP()

CPictureView::CPictureView()
{
	m_iHowScale = ID_VIEW_TOFIT;
}

CPictureView::~CPictureView()
{
}

void CPictureView::OnInitialUpdate()
{
	SetScrollSizes();
}

//////////////////
// Set scroll sizes based on picture. Page size = client hieight/width;
// line size = 1/10 of this.
//
void CPictureView::SetScrollSizes()
{
	CRect rcClient;
	GetClientRect(&rcClient);

	CRect rcImage;
	GetImageRect(rcImage);

	CSize szTotal = rcImage.Size();
	CSize szPage = rcClient.Size();

	CSize szLine = szPage;
	szLine.cx /= 10;
	szLine.cy /= 10;
	
	CScrollView::SetScrollSizes(MM_TEXT, szTotal, szPage, szLine);
	Invalidate();
}

//////////////////
// View was sized: readjust scroll sizes if I'm in "zoom to fit" mode
//
void CPictureView::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);
	if (m_iHowScale==ID_VIEW_TOFIT) {
		SetScrollSizes();
	}
}

//////////////////
// Erase the background. This is required in case the image is smaller than
// the client area, to paint the extra background. Use clipping to avoid
// flicker.
//
BOOL CPictureView::OnEraseBkgnd(CDC* pDC)
{
	CPictureDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// get client rectangle
	CRect rcClient;
	GetClientRect(&rcClient);
	CRect rc = rcClient;

	// get image rectangle
	CRect rcImage;
	GetImageRect(rcImage);
	rc = rcImage;

	CPoint pt = pDC->GetViewportOrg();
	CSize sz = GetTotalSize();

	// create clipping region
	CRgn clipRgn;
	clipRgn.CreateRectRgnIndirect(&rcClient);
	pDC->SelectClipRgn(&clipRgn);
	pDC->ExcludeClipRect(&rcImage);

	CBrush brush(RGB(0,0,0)); // black
	pDC->FillRect(&rcClient, &brush);

	pDC->SelectClipRgn(NULL);

	return TRUE;
}

//////////////////
// Draw the picture -- call CPicture to do it.
//
void CPictureView::OnDraw(CDC* pDC)
{
	CPictureDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CPicture* ppic = pDoc->GetPicture();
	ASSERT(ppic);
	if (*ppic) {
		CRect rc;
		GetImageRect(rc);
		ppic->Render(pDC,rc);
	}
}

//////////////////
// Get image rectangle, scaled for current zoom factor.
//
void CPictureView::GetImageRect(CRect& rc)
{
	CPictureDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CPicture* ppic = pDoc->GetPicture();
	ASSERT(ppic);

	if (!ppic || !*ppic) {
		rc.SetRect(0,0,0,0);
	} else if (m_iHowScale==ID_VIEW_TOFIT) {
		GetClientRect(&rc);
	} else {
		CSize sz = ppic->GetImageSize();
		switch (m_iHowScale) {
		case ID_VIEW25:
			sz.cx >>= 2;
			sz.cy >>= 2;
			break;
		case ID_VIEW33:
			sz.cx /= 3;
			sz.cy /= 3;
			break;
		case ID_VIEW50:
			sz.cx >>= 1;
			sz.cy >>= 1;
			break;
		case ID_VIEW75:
			sz.cx = (sz.cx * 3)/4;
			sz.cy = (sz.cy * 3)/4;
			break;
//		case ID_VIEW100:
//			sz.cx = (sz.cx * 3)/4;
//			sz.cy = (sz.cy * 3)/4;
//			sz.cx >>= 2;
//			sz.cy >>= 2;
//			break;
		}
		rc.SetRect(0,0,sz.cx,sz.cy);
	}
}

//////////////////
// Handle zoom command.
//
void CPictureView::OnViewScale(UINT nID)
{
	if (m_iHowScale != nID) {
		m_iHowScale = nID;
		ScrollToPosition(CPoint(0,0));
		OnInitialUpdate();
	}
}

//////////////////
// Update zoom menu -- check the whichever zoom factor I'm at now.
//
void CPictureView::OnUpdateViewScale(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(pCmdUI->m_nID == m_iHowScale);
}
