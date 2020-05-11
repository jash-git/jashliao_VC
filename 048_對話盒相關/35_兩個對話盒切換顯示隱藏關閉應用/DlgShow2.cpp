// DlgShow2.cpp : implementation file
//

#include "stdafx.h"
#include "howhideDlg.h"
#include "DlgShow2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgShow2 dialog


CDlgShow2::CDlgShow2(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgShow2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgShow2)
	m_v1 = 0.0;
	//}}AFX_DATA_INIT
}


void CDlgShow2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgShow2)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgShow2, CDialog)
	//{{AFX_MSG_MAP(CDlgShow2)
	ON_WM_TIMER()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgShow2 message handlers

BOOL CDlgShow2::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::Create(IDD, pParentWnd);
}

void CDlgShow2::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	UpdateData(true);
	m_v1++;
	if(m_v1>20)
		this->OnOK(); 
	UpdateData(false);
	CDialog::OnTimer(nIDEvent);
}

int CDlgShow2::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	SetTimer(1,1000,NULL);
	return 0;
}
