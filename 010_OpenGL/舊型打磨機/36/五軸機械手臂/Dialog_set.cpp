// Dialog_set.cpp : implementation file
//

#include "stdafx.h"
#include "kk1.h"
#include "Dialog_set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialog_set dialog


Dialog_set::Dialog_set(CWnd* pParent /*=NULL*/)
	: CDialog(Dialog_set::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dialog_set)
	m_set = 0;
	//}}AFX_DATA_INIT
}


void Dialog_set::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dialog_set)
	DDX_Text(pDX, IDC_EDIT1, m_set);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dialog_set, CDialog)
	//{{AFX_MSG_MAP(Dialog_set)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dialog_set message handlers


