// ListenDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Telnet.h"
#include "ListenDlg.h"
#include ".\listendlg.h"


// CListenDlg dialog

IMPLEMENT_DYNAMIC(CListenDlg, CDialog)
CListenDlg::CListenDlg(CWnd* pParent /*=NULL*/)
                : CDialog(CListenDlg::IDD, pParent)
                , m_Port(0)
{
}

CListenDlg::~CListenDlg()
{
}

void CListenDlg::DoDataExchange(CDataExchange* pDX)
{
        CDialog::DoDataExchange(pDX);
        DDX_Text(pDX, IDC_PORT_EDIT, m_Port);
        DDV_MinMaxUInt(pDX, m_Port, 0, 65535);
        DDX_Control(pDX, IDC_PORT_EDIT, m_Edit);
}


BEGIN_MESSAGE_MAP(CListenDlg, CDialog)
END_MESSAGE_MAP()


// CListenDlg message handlers

BOOL CListenDlg::OnInitDialog()
{
        CDialog::OnInitDialog();

        // TODO:  Add extra initialization here
        m_Edit.SetFocus();

        return false;  // return TRUE unless you set the focus to a control
        // EXCEPTION: OCX Property Pages should return FALSE
}
