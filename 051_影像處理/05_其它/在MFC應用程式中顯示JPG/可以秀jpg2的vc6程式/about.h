/////////////////////////////////////////////////////////////////////////////
// Project：MYIMGAPP
// Author：NorthTibet
// Date：星期四, 九月 26, 2002
// Description：通过定制的C++类在MFC框架中轻松显示多种格式的图象
//
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "StatLink.h"
#include "pictctrl.h"

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App Myimgapp

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
//ZXN
protected:
	CStaticLink	m_wndLink1;
	CStaticLink	m_wndLink2;
	CStaticLink	m_wndLink3;
	CStaticLink	m_wndLink4;
	CPictureCtrl m_wndPict;
//ZXN
// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_wndLink1.m_link = _T("http://www.vckbase.com");
	m_wndLink2.m_link = _T("http://www.vckbase.com");
	m_wndLink3.m_link = _T("mailto:vckbase@publik.hk.hi.cn");
	m_wndLink4.m_link = _T("http://www.vckbase.com");
	m_wndPict.m_link = _T("http://www.vckbase.com");
	m_wndLink1.SubclassDlgItem(IDC_STATIC_ICON, this);
	m_wndLink2.SubclassDlgItem(IDC_STATIC_TEXT, this);
	m_wndLink3.SubclassDlgItem(IDC_STATIC_MAIL, this);
	m_wndLink4.SubclassDlgItem(IDB_STATIC_IMG, this);
	m_wndPict.SubclassDlgItem(IDC_IMAGEMYDOG, this);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
