#include "StdAfx.h"
#include ".\cvideo.h"
//VMR9_step 01 ¥[¤Jcvideo.h cvideo.cpp 
#define SAFE_RELEASE(i) {if (i) i->Release(); i = NULL;}
const float EDGE_BUFFER  = 0.04f;  // Pixel buffer between bitmap and window edge

cVideo::cVideo(void)
{	
	pGraph = NULL;
	pVmr   = NULL;
	pWC	   = NULL;
	pME	   = NULL;
	pMS	   = NULL;
	pMC    = NULL;
	pBmp   = NULL;
	pConfig= NULL;
}

cVideo::~cVideo(void)
{
}

void cVideo::InitInterfaces(BSTR mFileToPlay, CWnd* pParentWnd, CRect* pRect)
{  
				// Create the Graph Builder.
				CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, 
                IID_IGraphBuilder, (void **)&pGraph);
				
				// create the VMR9 filter
				CoCreateInstance(CLSID_VideoMixingRenderer9, NULL, CLSCTX_INPROC,
				IID_IBaseFilter, (void**)&pVmr);
				// add the VMR9 filter to the Graph Manager
				pGraph->AddFilter(pVmr, L"Video");
				// get a pointer to the IVMRFilterConfig9 interface 
				pVmr->QueryInterface(IID_IVMRFilterConfig9, (void**)&pConfig);
				// make sure VMR9 is in windowless mode
				pConfig->SetRenderingMode(VMR9Mode_Windowless);
	
				// get a pointer to the IVMRWindowlessControl9 interface 
				pVmr->QueryInterface(IID_IVMRWindowlessControl9, (void**)&pWC);
				// Where to show video
		
				// IMediaControl controls flow of data through the graph
				pGraph->QueryInterface(IID_IMediaControl, (void **)&pMC);
				
				// IMediaEventEx tells that an event has occured (e.g. stopped paused)
				pGraph->QueryInterface(IID_IMediaEventEx, (void **)&pME);
				pME->SetNotifyWindow ( ( OAHWND ) pParentWnd->GetParent()->m_hWnd, WM_GRAPHNOTIFY, 0 ) ;
				
				// IMediaSeeking helps in seeking the video 
				pGraph->QueryInterface(IID_IMediaSeeking, (void **)&pMS);
				if (pMS)
				{
					pMS->SetTimeFormat(&TIME_FORMAT_MEDIA_TIME);
				}
				// set destination rectangle for the video
				pWC->SetVideoPosition(NULL, pRect);
				// specify the container window that the video should be clipped to
				pWC->SetVideoClippingWindow(pParentWnd->m_hWnd);

				// used for display of bmp on video
				pWC->QueryInterface(IID_IVMRMixerBitmap9, (LPVOID *)&pBmp);
				ZeroMemory(&bmpInfo, sizeof(bmpInfo) );    
				// Actually build the graph
				pGraph->RenderFile(mFileToPlay, NULL);


}

void cVideo::Clean(void)
{	
				SAFE_RELEASE(pWC);
				SAFE_RELEASE(pBmp);				
				SAFE_RELEASE(pVmr);
				SAFE_RELEASE(pConfig);
				SAFE_RELEASE(pMC);
				SAFE_RELEASE(pMS);
				SAFE_RELEASE(pME);
				SAFE_RELEASE(pGraph);
}

void cVideo::Play(void)
{
	pMC->Run();
}

void cVideo::ShowImage(CDC* pDC, CRect rectSize)
{	
	bmpInfo.dwFlags |= VMRBITMAP_HDC;
	bmpInfo.hdc = pDC->m_hDC;
	bmpInfo.rSrc = rectSize;
	mRect.SetRect(0,0,45,75);
    LONG cx, cy;
    pWC->GetNativeVideoSize(&cx, &cy, NULL, NULL);
	// This value is used to reposition the bitmap in composition space.
	fBmpCompWidth = (float)45 / (float)cx;
  // rDest specifies the destination rectangle in composition space (0.0f to 1.0f)
    bmpInfo.rDest.right  = 1.0f - EDGE_BUFFER;
	bmpInfo.rDest.left   = 1.0f - fBmpCompWidth- EDGE_BUFFER;
	mTop = (float)(cy - 75) / (float)cy - EDGE_BUFFER;
	bmpInfo.rDest.top = mTop;
	mBottom = 1.0f - EDGE_BUFFER;
	bmpInfo.rDest.bottom = mBottom; 
	mDesRect = bmpInfo.rDest;
	// Set the transparency value (1.0 is opaque, 0.0 is transparent).
    bmpInfo.fAlpha = 0.0;
	// Set the COLORREF so that the bitmap outline will be transparent
	bmpInfo.dwFlags |= VMRBITMAP_SRCCOLORKEY; 
    bmpInfo.clrSrcKey = RGB(0, 255, 0);
	pBmp->SetAlphaBitmap(&bmpInfo);	
}

void cVideo::HideImage(void)
{
// Set the transparency value (1.0 is opaque, 0.0 is transparent).
    bmpInfo.fAlpha = 0.0;
    pBmp->UpdateAlphaBitmapParameters(&bmpInfo);
}

void cVideo::SetTransparency(int mTransLevel)
{
	// Set the transparency value (1.0 is opaque, 0.0 is transparent).
    bmpInfo.fAlpha = (float)mTransLevel/10;
    pBmp->UpdateAlphaBitmapParameters(&bmpInfo);
}

void cVideo::Animate(void)
{
	mDesRect.left += 0.05;
	if(mDesRect.left > 1)
			mDesRect.left = 0.0;

	bmpInfo.rDest.left   = mDesRect.left ;
	bmpInfo.rDest.right  = mDesRect.left + fBmpCompWidth;
	bmpInfo.rDest.top = mTop;
	bmpInfo.rDest.bottom = mBottom;
	mDesRect = bmpInfo.rDest;

	bmpInfo.dwFlags |= VMRBITMAP_SRCRECT ;
	mRect.OffsetRect(45,0);
	if(mRect.left >= 360)
		mRect.SetRect(0,0,45,75);
	bmpInfo.rSrc = mRect;
    pBmp->UpdateAlphaBitmapParameters(&bmpInfo);
}
