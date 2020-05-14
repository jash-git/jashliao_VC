// WebInformation.cpp : implementation file
//

#include "stdafx.h"
#include "ChangeSTBforJenny.h"
#include "WebInformation.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWebInformation dialog


CWebInformation::CWebInformation(CWnd* pParent /*=NULL*/)
	: CDialog(CWebInformation::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWebInformation)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWebInformation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWebInformation)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWebInformation, CDialog)
	//{{AFX_MSG_MAP(CWebInformation)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWebInformation message handlers
void CWebInformation::SetInformation(CString StrUrl,CString StrName,CString StrPassWord)
{
	m_StrUrl=StrUrl;
	m_StrName=StrName;
	m_StrPassWord=StrPassWord;	
}

BOOL CWebInformation::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	this->SetDlgItemText(IDC_ShowURL,m_StrUrl);
	this->SetDlgItemText(IDC_ShowName,m_StrName);
	this->SetDlgItemText(IDC_ShowPassWord,m_StrPassWord);
	HWND hwnd;
	GetDlgItem(IDC_ShowURL,&hwnd);
	m_SLabel.SubWindow(hwnd);	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
