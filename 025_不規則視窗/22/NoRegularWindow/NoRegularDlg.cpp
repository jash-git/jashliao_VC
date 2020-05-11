// NoRegularDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NoRegular.h"
#include "NoRegularDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNoRegularDlg dialog

CNoRegularDlg::CNoRegularDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNoRegularDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNoRegularDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNoRegularDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNoRegularDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNoRegularDlg, CDialog)
	//{{AFX_MSG_MAP(CNoRegularDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_NCHITTEST()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNoRegularDlg message handlers

BOOL CNoRegularDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	//根据路径创建不规则窗体
	CDC* pDC;

	pDC = this->GetDC();
	::BeginPath(pDC->m_hDC);
	
	//设置为透明模式	
	::SetBkMode(pDC->m_hDC, TRANSPARENT);		
	//
	RECT rect;
	this->GetClientRect(&rect);
	
	pDC->MoveTo(rect.left, rect.top);
	pDC->LineTo(rect.right, rect.top);

	pDC->LineTo(rect.right, rect.bottom - GLOBAL_OVERLEN);

	pDC->LineTo(rect.left + (rect.right - rect.left) / 2, rect.bottom - GLOBAL_OVERLEN);
	pDC->LineTo(rect.left + (rect.right - rect.left) / 2, rect.bottom);
	pDC->LineTo(rect.left + (rect.right - rect.left) / 2 - GLOBAL_OVERWIDTH, rect.bottom - GLOBAL_OVERLEN);

	pDC->LineTo(rect.left, rect.bottom - GLOBAL_OVERLEN);
	pDC->LineTo(rect.left, rect.top);
	//
	
	::EndPath(pDC->m_hDC);
	hRgn = ::PathToRegion(pDC->m_hDC);
	this->SetWindowRgn(hRgn, TRUE);
	//
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNoRegularDlg::OnPaint() 
{
	CDialog::OnPaint();
}

HCURSOR CNoRegularDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

UINT CNoRegularDlg::OnNcHitTest(CPoint point) 
{	
	UINT uRet = CDialog::OnNcHitTest(point);
	uRet = (uRet == HTCLIENT) ? HTCAPTION : uRet;
	return uRet;
}

HBRUSH CNoRegularDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here	
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(0, 0, 255));	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
