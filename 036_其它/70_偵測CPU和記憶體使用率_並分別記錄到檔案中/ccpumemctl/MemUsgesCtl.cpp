// NetCtl.cpp : implementation file
//

#include "stdafx.h"
#include "CNetControl.h"
#include "MemUsgesCtl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMemUsgesCtl

CMemUsgesCtl::CMemUsgesCtl()
{
	m_iRefreshInterval = 10;
	m_ForeFontColor    = RGB(255, 0, 0);
	m_ForeColor        = RGB(0, 150, 0);
	m_BackColor        = RGB(0, 0, 0);	
	m_FreeColor		   = RGB(0, 80, 0);
	m_LableColor       = RGB(255, 255, 0);
	m_UsedColor        = RGB(0, 140, 0);
	m_iGridHeight      = 0;
	m_iGridCount       = 50;
	m_ulTotalAvail     = 0;
	m_ulNewUsges       = 0;
}

CMemUsgesCtl::~CMemUsgesCtl()
{
	fclose(m_pf);
}


BEGIN_MESSAGE_MAP(CMemUsgesCtl, CWnd)
	//{{AFX_MSG_MAP(CMemUsgesCtl)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_WM_SHOWWINDOW()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMemUsgesCtl message handlers

void CMemUsgesCtl::OnPaint() 
{	  
	GetMemUsgesNt();	
	//CPaintDC dc(this); 
}

int CMemUsgesCtl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	return 0;
}

void CMemUsgesCtl::GetMemUsgesNt()
{
	MEMORYSTATUS MemStat;
	MemStat.dwLength = sizeof(MEMORYSTATUS);
	GlobalMemoryStatus(&MemStat);
	m_ulNewUsges     = MemStat.dwMemoryLoad;
	DrawMemUsges();	
}

void CMemUsgesCtl::SetRefreshInterval(int iMs)
{
	 m_iRefreshInterval = iMs;
	 SetTimer(1, m_iRefreshInterval, NULL); 
}


void CMemUsgesCtl::OnTimer(UINT nIDEvent) 
{  	
	fprintf(m_pf,"%d\n",m_ulNewUsges);
	Invalidate();
	CWnd::OnTimer(nIDEvent);
}

void CMemUsgesCtl::SetGridCount(int iNewCounts)
{
    m_iGridCount	= iNewCounts;

}

void CMemUsgesCtl::SetGridHeight(int iNewHeight)
{
	m_iGridHeight  = iNewHeight;
}

void CMemUsgesCtl::OnSize(UINT nType, int cx, int cy) 
{ 	
	CWnd::OnSize(nType, cx, cy);
}

void CMemUsgesCtl::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CWnd::OnShowWindow(bShow, nStatus);
}


void CMemUsgesCtl::DrawMemUsges()
{
   	CDC memDC;
	CString strLable;
	CBitmap memBitmap;
	CBitmap* pOldBmp = NULL;	
	CString strUsges;
	CPen BackFreePen;
	CPen BackUsedPen;
	CPen *pOldPen    = NULL;
	CPen *pOldMemPen = NULL;
	CRect rectClient;

	CPaintDC dc(this);

	GetClientRect(&rectClient);
	m_iGridHeight = rectClient.Height() / m_iGridCount;
	
	//draw cpu free usges
	BackFreePen.CreatePen(PS_SOLID, m_iGridHeight - 2, m_FreeColor);

	memDC.CreateCompatibleDC(&dc); 
	pOldMemPen = memDC.SelectObject(&BackFreePen);
	memBitmap.CreateCompatibleBitmap(&dc, rectClient.right, rectClient.bottom);
	pOldBmp = memDC.SelectObject(&memBitmap);

	for(int i = 0; i < 50 - (int)(m_ulNewUsges / 2); i ++)   
	{
		memDC.MoveTo(rectClient.left + 12,  rectClient.top + i * m_iGridHeight + 12);
		memDC.LineTo(rectClient.right - 12, rectClient.top + i * m_iGridHeight + 12);
	}

	//draw cpu used usges
	BackUsedPen.CreatePen(PS_SOLID, m_iGridHeight - 2, m_UsedColor);
	memDC.SelectObject(&BackUsedPen);

	for(int j = 0; j < (int)(m_ulNewUsges / 2); j ++)	   //fill used percent
	{
		memDC.MoveTo(rectClient.left + 12,  rectClient.bottom - j * m_iGridHeight - 12);
		memDC.LineTo(rectClient.right - 12, rectClient.bottom - j * m_iGridHeight - 12);
	}

	strLable = _T("memory");
	memDC.SetBkMode(TRANSPARENT);
	memDC.SetTextAlign(TA_LEFT);
	memDC.SetTextColor(m_LableColor);
	memDC.TextOut(rectClient.left + 40, rectClient.top + 30, strLable);

	strUsges.Format("%u", m_ulNewUsges);
	strUsges += "%";
	memDC.SetTextAlign(TA_LEFT | TA_CENTER);
	memDC.SetTextColor(m_ForeFontColor);
	memDC.TextOut(rectClient.left + rectClient.Width() / 2 - 10, rectClient.bottom - 60, strUsges);
	
	dc.BitBlt(rectClient.left, rectClient.top, rectClient.right, rectClient.bottom,
		      &memDC, 0, 0, SRCCOPY); 
	
	memDC.SelectObject(pOldBmp);
	memDC.SelectObject(pOldMemPen);
	memDC.DeleteDC();
	memBitmap.DeleteObject();
}

BOOL CMemUsgesCtl::OnEraseBkgnd(CDC* pDC) 
{
	return TRUE;//CWnd::OnEraseBkgnd(pDC);
}

BOOL CMemUsgesCtl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID) 
{
	m_pf=fopen("Mem.txt","w");
	return CWnd::Create(NULL, NULL, dwStyle, rect, pParentWnd, nID, NULL);
}
