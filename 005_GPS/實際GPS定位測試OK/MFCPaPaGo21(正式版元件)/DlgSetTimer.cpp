// DlgSetTimer.cpp : implementation file
//

#include "stdafx.h"
#include "MFCPaPaGo.h"
#include "DlgSetTimer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSetTimer dialog


CDlgSetTimer::CDlgSetTimer(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSetTimer::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSetTimer)
	m_v1 = 0.0f;
	//}}AFX_DATA_INIT
}


void CDlgSetTimer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSetTimer)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSetTimer, CDialog)
	//{{AFX_MSG_MAP(CDlgSetTimer)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSetTimer message handlers
