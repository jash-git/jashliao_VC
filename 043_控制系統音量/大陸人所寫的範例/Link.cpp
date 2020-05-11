
#include "stdafx.h"
#include "link.h"

#define TIP_ID 1

CLink::CLink()
{
    m_bOver      = false; 
	m_hLinkCursor=NULL; //初值设置为NULL，这样如果没有在程序中设置该值，就会使用默认的手形光标
}

CLink::~CLink()
{}

/////////////////////////////////////////////////////////////////////////////

BOOL CLink::DestroyWindow() 
{
    KillTimer(1);	
	return CStatic::DestroyWindow();
}

BOOL CLink::PreTranslateMessage(MSG* pMsg) 
{
    m_ToolTip.RelayEvent(pMsg);
    return CStatic::PreTranslateMessage(pMsg);
}


void CLink::PreSubclassWindow() 
{
    DWORD dwStyle = GetStyle();  //修改属性，使之可接受消息
    ::SetWindowLong(GetSafeHwnd(), GWL_STYLE, dwStyle | SS_NOTIFY);
    
    SetDefaultCursor();     //设置默认光标为手形光标
   
	CRect rect; 
    GetClientRect(rect);
    m_ToolTip.Create(this);
	m_ToolTip.SetDelayTime(100);
	m_ToolTip.SetMaxTipWidth(200);

    m_ToolTip.AddTool(this, "", rect, TIP_ID);    CStatic::PreSubclassWindow();
}

BEGIN_MESSAGE_MAP(CLink, CStatic)
    //{{AFX_MSG_MAP(CLink)
    ON_WM_CTLCOLOR_REFLECT()
    ON_WM_SETCURSOR()
    ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////

HBRUSH CLink::CtlColor(CDC* pDC, UINT nCtlColor) 
{
    if (m_bOver)
        pDC->SetTextColor(RGB(255,   0,   0));
    else
        pDC->SetTextColor( RGB(  0,   0, 238));

    pDC->SetBkMode(TRANSPARENT);   //设置背景是透明的
    return (HBRUSH)GetStockObject(NULL_BRUSH);
}

void CLink::OnMouseMove(UINT nFlags, CPoint point) 
{ 
	m_bOver = true;
	Invalidate();
	SetTimer(1, 100, NULL); //设置一个定时器，用于设置鼠标离开时的颜色
	
    CStatic::OnMouseMove(nFlags, point);
}

void CLink::OnTimer(UINT nIDEvent) 
{
    CPoint pt(::GetMessagePos());
    ScreenToClient(&pt);

    CRect rc;
    GetClientRect(rc);

    if (!rc.PtInRect(pt))
    {
        m_bOver = false;
        KillTimer(1);        
        Invalidate();
    }    
	CStatic::OnTimer(nIDEvent);
}

BOOL CLink::OnSetCursor(CWnd* /*pWnd*/, UINT /*nHitTest*/, UINT /*message*/) 
{
    if (m_hLinkCursor)  //如果设置了光标，就使用新设置的 光标
    {
        ::SetCursor(m_hLinkCursor);
        return true;
    }
    return false;
}


/////////////////////////////////////////////////////////////////////////////
void CLink::SetToolTipText(CString str)
{
	m_ToolTip.UpdateTipText(str,this,TIP_ID);
}

void CLink::SetLinkCursor(HCURSOR hCursor)
{ 
    m_hLinkCursor = hCursor;
    if (m_hLinkCursor == NULL)
        SetDefaultCursor();
}


void CLink::SetDefaultCursor()   //从winhlp32.exe中提取手形光标，用做默认的光标
{    
	CString str;
	::GetWindowsDirectory(str.GetBuffer(MAX_PATH), MAX_PATH);
	str.ReleaseBuffer();
	str += _T("\\winhlp32.exe");
	
	HMODULE hModule = ::LoadLibrary(str);
	if (hModule) 
	{
		HCURSOR hHandCursor = ::LoadCursor(hModule, MAKEINTRESOURCE(106));
		if (hHandCursor)
			m_hLinkCursor =CopyCursor(hHandCursor);
	}
	FreeLibrary(hModule);
	
}









