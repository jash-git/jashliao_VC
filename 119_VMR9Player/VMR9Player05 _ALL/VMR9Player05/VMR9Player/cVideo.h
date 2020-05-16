#pragma once
#include <dshow.h>
#include <d3d9.h>
#include <vmr9.h>

#define WM_GRAPHNOTIFY  WM_USER + 100

class cVideo
{
public:
	cVideo(void);
	~cVideo(void);

private:
	IGraphBuilder			*pGraph ;
	IBaseFilter				*pVmr;
	IVMRWindowlessControl9  *pWC;
	IVMRFilterConfig9       *pConfig;
	IVMRMixerBitmap9        *pBmp;
	VMR9AlphaBitmap			bmpInfo;
	CRect					mRect;
	VMR9NormalizedRect      mDesRect;
	float					fBmpCompWidth , mTop, mBottom;
public:
	IMediaControl			*pMC;
	IMediaEventEx		    *pME;
	IMediaSeeking			*pMS;

public:
	void InitInterfaces(BSTR mFileToPlay, CWnd* pParentWnd, CRect* pRect);
	void Clean(void);
	void Play(void);
	void ShowImage(CDC* pDC, CRect rectSize);
	void HideImage(void);
	void SetTransparency(int mTransLevel);
	void Animate(void);
};
