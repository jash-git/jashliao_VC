// yedlg.cpp : implementation file
//

#include "stdafx.h"
#include "transparent.h"
#include "yedlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Cyedlg dialog


Cyedlg::Cyedlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cyedlg::IDD, pParent)
{
	start=true;
	x=0;
	y=0;
	k=false;
	counter=0;
	big=0;
	width=0;
	l=false;
	//{{AFX_DATA_INIT(Cyedlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Cyedlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cyedlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cyedlg, CDialog)
	//{{AFX_MSG_MAP(Cyedlg)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_NCHITTEST()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cyedlg message handlers

BOOL Cyedlg::OnInitDialog() 
{
	CRect rect;
	GetClientRect(&rect);
	CDialog::OnInitDialog();


MoveWindow(x,y+80,rect.right-rect.left,rect.Height());
big=rect.bottom-rect.top;
width=rect.right-rect.left;
SetTimer(2,60,0);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
UINT Cyedlg::OnNcHitTest(CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    UINT nHitTest = CWnd :: OnNcHitTest(point) ; 
    return (nHitTest == HTCLIENT) ? HTCAPTION : nHitTest ;

}

void Cyedlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
}

void Cyedlg::OnTimer(UINT nIDEvent) 
{


	// TODO: Add your message handler code here and/or call default


	CDialog::OnTimer(nIDEvent);
}
