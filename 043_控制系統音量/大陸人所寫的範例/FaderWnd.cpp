#include "stdafx.h"
#include "FaderWnd.h"

#define ALPHA_STEP 20  //每次减少的透明度数

/////////////////////////////////////////////////////////////////////////////
CFaderWnd::CFaderWnd(CWnd *pWndToFade, UINT nFadeTime/*=500*/, BYTE byAlpha/*=255*/)
{
	m_bMainWnd=FALSE;

	ASSERT(pWndToFade);
	ASSERT_VALID(pWndToFade);
	m_pWndToFade=pWndToFade;
	
	HMODULE hInst = ::LoadLibrary("user32.dll");	
	m_pFun = (LPFUN)::GetProcAddress(hInst, "UpdateLayeredWindow");	
	if (m_pFun==NULL)  //如果操作系统没有提供这个函数
		delete this;
	else
	{
		CRect	rc;
		CPoint	pt(0, 0);
		SIZE	size;
		
		m_pWndToFade->GetWindowRect(rc);
		
		CreateEx(WS_EX_LAYERED|WS_EX_TRANSPARENT|WS_EX_TOPMOST|WS_EX_TOOLWINDOW, 
			"STATIC", "", WS_POPUP|WS_VISIBLE, rc, AfxGetMainWnd(), 0);
		
		size.cx = rc.Width();
		size.cy = rc.Height();
		pt = rc.TopLeft();
		
		m_Blend.BlendOp = AC_SRC_OVER;			
		m_Blend.BlendFlags = 0;			
		m_Blend.AlphaFormat = 0;	
		m_Blend.SourceConstantAlpha = byAlpha;	
		
		m_pFun(GetSafeHwnd(),
				NULL, 
				NULL, 
				&size, 
				::GetDC(m_pWndToFade->GetSafeHwnd()),				
				&pt, 
				0, 
				&m_Blend, 
				ULW_ALPHA
				);      //调用动态连接库中的函数
			
//		UINT	nElapse = nFadeTime / (byAlpha / ALPHA_STEP);
//		SetTimer(1, nElapse, NULL);
		SetTimer(1,1,NULL);
	}
}


CFaderWnd::~CFaderWnd()
{}


BEGIN_MESSAGE_MAP(CFaderWnd, CWnd)
//{{AFX_MSG_MAP(CFaderWnd)
ON_WM_TIMER()
ON_WM_SETFOCUS()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
void CFaderWnd::OnTimer(UINT nIDEvent) 	
{
	if (m_Blend.SourceConstantAlpha >= ALPHA_STEP)	
	{		
		m_Blend.SourceConstantAlpha -= ALPHA_STEP;  //减少透明度
		m_pFun(GetSafeHwnd(), 
			NULL, 
			NULL, 
			NULL, 
			NULL, 
			NULL, 
			NULL, 
			&m_Blend, 
			ULW_ALPHA);		
	}
	else		
	{
		KillTimer(nIDEvent);
		DestroyWindow();
		if(m_bMainWnd==TRUE)   
	 		AfxGetMainWnd()->SendMessage(WM_CLOSE);
	}	
}

void CFaderWnd::OnSetFocus(CWnd* pOldWnd) 	
{
	if (pOldWnd)
		pOldWnd->SetFocus();
}



