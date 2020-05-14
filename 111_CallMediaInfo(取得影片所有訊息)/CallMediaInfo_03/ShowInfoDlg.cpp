// ShowInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CallMediaInfo.h"
#include "ShowInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CString StrShowData[11];
/////////////////////////////////////////////////////////////////////////////
// CShowInfoDlg dialog


CShowInfoDlg::CShowInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShowInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShowInfoDlg)
	m_V1 = _T("");
	m_V2 = _T("");
	m_V3 = _T("");
	m_V4 = _T("");
	m_V5 = _T("");
	m_V6 = _T("");
	m_V7 = _T("");
	m_V8 = _T("");
	m_V9 = _T("");
	m_V10 = _T("");
	m_V11 = _T("");
	//}}AFX_DATA_INIT
}


void CShowInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShowInfoDlg)
	DDX_Text(pDX, IDC_EDIT1, m_V1);
	DDX_Text(pDX, IDC_EDIT2, m_V2);
	DDX_Text(pDX, IDC_EDIT3, m_V3);
	DDX_Text(pDX, IDC_EDIT4, m_V4);
	DDX_Text(pDX, IDC_EDIT5, m_V5);
	DDX_Text(pDX, IDC_EDIT6, m_V6);
	DDX_Text(pDX, IDC_EDIT7, m_V7);
	DDX_Text(pDX, IDC_EDIT8, m_V8);
	DDX_Text(pDX, IDC_EDIT9, m_V9);
	DDX_Text(pDX, IDC_EDIT10, m_V10);
	DDX_Text(pDX, IDC_EDIT11, m_V11);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShowInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CShowInfoDlg)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowInfoDlg message handlers

BOOL CShowInfoDlg::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::Create(IDD, pParentWnd);
}

int CShowInfoDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

BOOL CShowInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	UpdateData(true);
		m_V1 = StrShowData[0];
		m_V2 = StrShowData[1];
		m_V3 = StrShowData[2];
		m_V4 = StrShowData[3];
		m_V5 = StrShowData[4];
		m_V6 = StrShowData[5];
		m_V7 = StrShowData[6];
		m_V8 = StrShowData[7];
		m_V9 = StrShowData[8];
		m_V10 = StrShowData[9];
		m_V11 = StrShowData[10];
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
