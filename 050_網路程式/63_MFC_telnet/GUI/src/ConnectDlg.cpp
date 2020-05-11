// ConnectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Telnet.h"
#include "ConnectDlg.h"
#include ".\connectdlg.h"


// CConnectDlg dialog

IMPLEMENT_DYNAMIC(CConnectDlg, CDialog)
CConnectDlg::CConnectDlg(CStringList *strs, CWnd* pParent /*=NULL*/)
                : CDialog(CConnectDlg::IDD, pParent)
                , m_Address(_T(""))
                , m_Port(0)
{
        addrs = strs;
        if (addrs->GetCount())
                m_Address = addrs->GetHead();
}

CConnectDlg::~CConnectDlg()
{
}

void CConnectDlg::DoDataExchange(CDataExchange* pDX)
{
        CDialog::DoDataExchange(pDX);
        DDX_Control(pDX, IDC_ADDR_COMBO, m_addrCombo);
        DDX_CBString(pDX, IDC_ADDR_COMBO, m_Address);
        DDV_MaxChars(pDX, m_Address, 100);
        DDX_Text(pDX, IDC_PORT_EDIT, m_Port);
        DDV_MinMaxUInt(pDX, m_Port, 0, 65535);
}


BEGIN_MESSAGE_MAP(CConnectDlg, CDialog)
END_MESSAGE_MAP()


// CConnectDlg message handlers

BOOL CConnectDlg::OnInitDialog()
{
        CDialog::OnInitDialog();

        if (addrs->GetCount()) {
                POSITION pos = addrs->GetHeadPosition();
                for (int i = 0; i < addrs->GetCount(); i++) {
                        m_addrCombo.AddString(addrs->GetAt(pos));
                        addrs->GetNext(pos);
                }
        }

        RECT r;
        m_addrCombo.GetWindowRect(&r);
        ScreenToClient(&r);
        m_addrCombo.MoveWindow(r.top, r.left, r.right, r.bottom + 12*6);
        m_addrCombo.SetFocus();
        m_addrCombo.LimitText(NI_MAXHOST);


        return false;  // return TRUE unless you set the focus to a control
        // EXCEPTION: OCX Property Pages should return FALSE
}




