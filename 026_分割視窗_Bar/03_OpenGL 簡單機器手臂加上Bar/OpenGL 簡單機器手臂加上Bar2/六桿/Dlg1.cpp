// Dlg1.cpp : implementation file
//

#include "stdafx.h"
#include "GLbase.h"
#include "Dlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg1 dialog


CDlg1::CDlg1(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg1)
	m_v1 = 0.0f;
	m_v2 = 0.0f;
	m_v3 = 0.0f;
	m_v4 = 0.0f;
	m_v5 = 0.0f;
	m_v6 = 0.0f;
	//}}AFX_DATA_INIT
}


void CDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg1)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	DDX_Text(pDX, IDC_EDIT2, m_v2);
	DDX_Text(pDX, IDC_EDIT3, m_v3);
	DDX_Text(pDX, IDC_EDIT4, m_v4);
	DDX_Text(pDX, IDC_EDIT5, m_v5);
	DDX_Text(pDX, IDC_EDIT6, m_v6);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg1, CDialog)
	//{{AFX_MSG_MAP(CDlg1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg1 message handlers
