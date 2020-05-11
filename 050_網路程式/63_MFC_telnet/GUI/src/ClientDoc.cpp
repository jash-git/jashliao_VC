// ClientDoc.cpp : implementation of the CClientDoc class
//

#include "stdafx.h"
#include "Telnet.h"

#include "ClientDoc.h"
#include "ClientView.h"
#include ".\clientdoc.h"

#include "ConnectDlg.h"
#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CClientDoc

IMPLEMENT_DYNCREATE(CClientDoc, CDocument)

BEGIN_MESSAGE_MAP(CClientDoc, CDocument)
        ON_COMMAND(ID_CLNT_REDIAL, OnClntRedial)
        ON_COMMAND(ID_CLNT_DISCONNECT, OnClntDisconnect)
        ON_COMMAND(ID_CLNT_SHELL, OnClntShell)
END_MESSAGE_MAP()


// CClientDoc construction/destruction

CClientDoc::CClientDoc() : m_cSock(0)
{
}

CClientDoc::~CClientDoc()
{
        Disconnect();
}

BOOL CClientDoc::OnNewDocument()
{
        if (!CDocument::OnNewDocument())
                return FALSE;


        POSITION pos = GetFirstViewPosition();

        while (pos != 0) {
                CView *pv = GetNextView(pos);
                if (!pv->IsKindOf(RUNTIME_CLASS(CClientView)))
                        return false;

                pc = STATIC_DOWNCAST(CClientView, pv);
        }


        m_pAddrs = &(STATIC_DOWNCAST(CTelnetApp, AfxGetApp())->m_addrList);
        CConnectDlg dlg(m_pAddrs);
        if (dlg.DoModal() == IDOK) {
                if (m_pAddrs->Find(dlg.m_Address) == 0)
                        m_pAddrs->AddHead(dlg.m_Address);

                return Connect(dlg.m_Address, dlg.m_Port);
        }

        return false;
}


////////////////////////////////////////////////////////////////////////////////////////
bool CClientDoc::Connect(CString addr, int port)
{
        char *err;
        Disconnect();

        m_cSock = new Socket;

        if (err = m_cSock->Create(AF_INET, SOCK_STREAM, IPPROTO_IP)) {
                ::MessageBox(pc->m_hWnd, err, "Error.", MB_OK | MB_ICONHAND);
                return false;
        }
        if (err = m_cSock->Select(pc->m_hWnd, WM_CLIENT, FD_READ | FD_CONNECT | FD_CLOSE)) {
                ::MessageBox(pc->m_hWnd, err, "Error.", MB_OK | MB_ICONHAND);
                return false;
        }
        if (err = m_cSock->Connect(addr, (WORD)port)) {
                ::MessageBox(pc->m_hWnd, err, "Error.", MB_OK | MB_ICONHAND);
                return false;
        }


        m_port = m_cSock->getport();
        m_hostname = m_cSock->gethostname();
        m_ipaddr = m_cSock->getaddr();

        str.Format("[%s]%s/%d", m_ipaddr, m_hostname, m_port);
        SetTitle(str);

        STATIC_DOWNCAST(CChildFrame, pc->GetParent())->m_pane1 = "Connection is in progress...";
        return true;
}

void CClientDoc::Disconnect()
{
        if (m_cSock) {
                delete m_cSock;
                m_cSock = 0;
        }
}

////////////////////////////////////////////////////////////////////////////////////////



// CClientDoc serialization

void CClientDoc::Serialize(CArchive& ar)
{
        // CEditView contains an edit control which handles all serialization
        reinterpret_cast<CEditView*>(m_viewList.GetHead())->SerializeRaw(ar);
}


// CClientDoc diagnostics

#ifdef _DEBUG
void CClientDoc::AssertValid() const
{
        CDocument::AssertValid();
}

void CClientDoc::Dump(CDumpContext& dc) const
{
        CDocument::Dump(dc);
}
#endif //_DEBUG



void CClientDoc::OnClntRedial()
{
        Connect(m_ipaddr, m_port);
}

void CClientDoc::OnClntDisconnect()
{
        PostMessage(pc->m_hWnd, WM_CLIENT, WPARAM(0), LPARAM(32));
}

void CClientDoc::OnClntShell()
{
        CArray<BYTE> *parray = m_cSock->getarray();
        //if(parray->IsKindOf(RUNTIME_CLASS(CArray)))

        if (parray->GetCount() == 0)
                return;

        CString file;
        if (m_port == 110 || m_port == 119)
                file = "temp.eml";
        else if (m_port == 80)
                file = "temp.html";
        else
                file = "temp.txt" ;

        CFile pfile(file, CFile::modeCreate | CFile::modeWrite);
        pfile.Write((void *)parray->GetData(), (int)parray->GetCount());
        pfile.Close();

        ShellExecute(0, "open", file, 0, 0, SW_SHOWNORMAL);
}
