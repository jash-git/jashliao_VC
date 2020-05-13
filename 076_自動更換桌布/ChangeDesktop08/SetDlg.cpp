// SetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChangeDesktop.h"
#include "SetDlg.h"
#include "ExternalVar.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include <shlobj.h>
/////////////////////////////////////////////////////////////////////////////
// CSetDlg dialog


CSetDlg::CSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetDlg)
	m_Style = _T("");
	m_time = 0;
	m_Dir = _T("");
	//}}AFX_DATA_INIT
}


void CSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetDlg)
	DDX_CBString(pDX, IDC_COMBO1, m_Style);
	DDX_Text(pDX, IDC_EDIT1, m_time);
	DDX_Text(pDX, IDC_EDIT3, m_Dir);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetDlg, CDialog)
	//{{AFX_MSG_MAP(CSetDlg)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_SwitchDir, OnSwitchDir)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetDlg message handlers

BOOL CSetDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

int CSetDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	//UpdateData(true);
	switch(gintStyle)
	{
		case 0:
				m_Style = _T("置中:0");
			break;
		case 1:
				m_Style = _T("填滿:1");
			break;
		case 2:
				m_Style = _T("並排:2");
			break;
	};
	m_time = gintChangetime;
	m_Dir = gStrImageDir;
	//UpdateData(false);
	return 0;
}

void CSetDlg::OnSwitchDir() 
{
	// TODO: Add your control notification handler code here
	CString str;
	BROWSEINFO bi;
	char name[MAX_PATH];
	ZeroMemory(&bi,sizeof(BROWSEINFO));
	bi.hwndOwner=GetSafeHwnd();
	bi.pszDisplayName=name;
	bi.lpszTitle="Select folder";
	//bi.ulFlags=BIF_BROWSEINCLUDEURLS;
	LPITEMIDLIST idl=SHBrowseForFolder(&bi);
	if(idl==NULL)
		return;
	SHGetPathFromIDList(idl,str.GetBuffer(MAX_PATH));
	str.ReleaseBuffer();
	m_Dir=str;
	if(str.GetAt(str.GetLength()-1)!='\\')
		m_Dir+="\\";
	UpdateData(FALSE);	
}
