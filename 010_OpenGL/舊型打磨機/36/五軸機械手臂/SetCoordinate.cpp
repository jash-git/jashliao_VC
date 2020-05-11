// SetCoordinate.cpp : implementation file
//

#include "stdafx.h"
#include "kk1.h"
#include "SetCoordinate.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SetCoordinate dialog


SetCoordinate::SetCoordinate(CWnd* pParent /*=NULL*/)
	: CDialog(SetCoordinate::IDD, pParent)
{
	//{{AFX_DATA_INIT(SetCoordinate)
	m_set = 2;
	m_x = 0;
	m_y = -11;
	m_z = 0;
	m_x1 = 14;
	m_y1 = -11;
	m_z1 = 0;
	m_x2 = 0;
	m_y2 = -11;
	m_z2 = -4;
	m_set1 = 2;
	//}}AFX_DATA_INIT
}


void SetCoordinate::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SetCoordinate)
	DDX_Text(pDX, IDC_EDIT1, m_set);
	DDX_Text(pDX, IDC_EDIT2, m_x);
	DDX_Text(pDX, IDC_EDIT3, m_y);
	DDX_Text(pDX, IDC_EDIT4, m_z);
	DDX_Text(pDX, IDC_EDIT5, m_x1);
	DDX_Text(pDX, IDC_EDIT6, m_y1);
	DDX_Text(pDX, IDC_EDIT7, m_z1);
	DDX_Text(pDX, IDC_EDIT8, m_x2);
	DDX_Text(pDX, IDC_EDIT9, m_y2);
	DDX_Text(pDX, IDC_EDIT10, m_z2);
	DDX_Text(pDX, IDC_EDIT11, m_set1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SetCoordinate, CDialog)
	//{{AFX_MSG_MAP(SetCoordinate)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SetCoordinate message handlers
