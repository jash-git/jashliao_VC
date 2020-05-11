// ServerDoc.cpp : implementation file
//

#include "stdafx.h"
#include "Telnet.h"
#include "ServerDoc.h"
#include "ServerView.h"

#include "ListenDlg.h"
#include "ChildFrm.h"

// CServerDoc

IMPLEMENT_DYNCREATE(CServerDoc, CDocument)

CServerDoc::CServerDoc(): m_sSock(0)
{
}
CServerDoc::~CServerDoc()
{
        if (m_sSock)
                delete m_sSock;
}

BOOL CServerDoc::OnNewDocument()
{
        if (!CDocument::OnNewDocument())
                return FALSE;


        POSITION pos = GetFirstViewPosition();
        CServerView *pc;

        while (pos != 0) {
                CView *pv = GetNextView(pos);
                if (!pv->IsKindOf(RUNTIME_CLASS(CServerView)))
                        return false;

                pc = STATIC_DOWNCAST(CServerView, pv);
        }

        CListenDlg dlg;
        if (dlg.DoModal() == IDOK) {

                char *err;
                m_sSock = new Socket;
                if (err = m_sSock->Create(AF_INET, SOCK_STREAM, IPPROTO_IP)) {
                        ::MessageBox(pc->m_hWnd, err, "Error.", MB_OK | MB_ICONHAND);
                        return false;
                }
                if (err = m_sSock->Select(pc->m_hWnd, WM_SERVER, FD_READ | FD_ACCEPT | FD_CLOSE)) {
                        ::MessageBox(pc->m_hWnd, err, "Error.", MB_OK | MB_ICONHAND);
                        return false;
                }
                if (err = m_sSock->Listen(dlg.m_Port)) {
                        ::MessageBox(pc->m_hWnd, err, "Error.", MB_OK | MB_ICONHAND);
                        return false;
                }

                str.Format("Listening port: %d  [clients:%d]", m_sSock->getport(), m_sSock->getclientsnum());
                SetTitle(str);

                STATIC_DOWNCAST(CChildFrame, pc->GetParent())->m_pane1 = "Listening for incoming connection...";
                return true;
        }

        return false;
}


BEGIN_MESSAGE_MAP(CServerDoc, CDocument)
END_MESSAGE_MAP()


// CServerDoc diagnostics

#ifdef _DEBUG
void CServerDoc::AssertValid() const
{
        CDocument::AssertValid();
}

void CServerDoc::Dump(CDumpContext& dc) const
{
        CDocument::Dump(dc);
}
#endif //_DEBUG


// CServerDoc serialization

void CServerDoc::Serialize(CArchive& ar)
{
        if (ar.IsStoring()) {
                // TODO: add storing code here
        } else {
                // TODO: add loading code here
        }
}


// CServerDoc commands
