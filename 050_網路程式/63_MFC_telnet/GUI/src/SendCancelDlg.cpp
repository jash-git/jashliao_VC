// SendCancelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Telnet.h"
#include "SendCancelDlg.h"
#include ".\sendcanceldlg.h"


// CSendCancelDlg dialog

IMPLEMENT_DYNAMIC(CSendCancelDlg, CDialog)
CSendCancelDlg::CSendCancelDlg(Socket *sock, CWnd* pParent /*=NULL*/)
                : CDialog(CSendCancelDlg::IDD, pParent)
                , m_clientAddr(_T(""))
{
        pclients = sock;
}

CSendCancelDlg::~CSendCancelDlg()
{
}

void CSendCancelDlg::DoDataExchange(CDataExchange* pDX)
{
        CDialog::DoDataExchange(pDX);
        DDX_Control(pDX, IDC_CLIENTS_LIST, m_clientsList);
        DDX_LBString(pDX, IDC_CLIENTS_LIST, m_clientAddr);
}


BEGIN_MESSAGE_MAP(CSendCancelDlg, CDialog)
END_MESSAGE_MAP()


// CSendCancelDlg message handlers

BOOL CSendCancelDlg::OnInitDialog()
{
        CDialog::OnInitDialog();

        // TODO:  Add extra initialization here
        char client[256];
        for (int i = 0; i < pclients->getclientsnum(); i++) {
                sprintf(client, "%s", pclients->getaddr(i));
                m_clientsList.AddString(client);
                m_clientsList.SetItemData(i, (DWORD_PTR)pclients->getclientsocket(client));                   //server SOCKET
        }

        m_clientsList.SetFocus();

        return false;  // return TRUE unless you set the focus to a control
        // EXCEPTION: OCX Property Pages should return FALSE
}

void CSendCancelDlg::OnOK()
{
        // TODO: Add your specialized code here and/or call the base class
        for (int i = 0; i < m_clientsList.GetCount(); i++) {
                if (m_clientsList.GetSel(i)) {
                        m_clientSock = (SOCKET)m_clientsList.GetItemData(i);
                        break;
                }
        }

        CDialog::OnOK();
}
