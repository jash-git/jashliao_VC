// ServerView.cpp : implementation file
//

#include "stdafx.h"
#include "Telnet.h"

#include "ServerDoc.h"
#include "ServerView.h"
#include ".\serverview.h"

#include "SendCancelDlg.h"


// CServerView

IMPLEMENT_DYNCREATE(CServerView, CEditView)


BEGIN_MESSAGE_MAP(CServerView, CEditView)
        ON_MESSAGE(WM_SERVER, Server)
        ON_WM_CREATE()
        ON_WM_KEYDOWN()
END_MESSAGE_MAP()


LRESULT CServerView::Server(WPARAM wParam, LPARAM lParam)
{
        CServerDoc *pDoc = GetDocument();
        Socket *psock = pDoc->getsocket();
        char *buff;

        switch (LOWORD(lParam)) {
        case FD_ACCEPT:    //wParam = this->server sock=socket() handle
                if (buff = psock->Accept()) {
                        pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
                        pEdit->ReplaceSel("\r\n\r\n" + CString(buff) + "\r\n\r\n");
                } else {
                        mess.Format("Listening port: %d  [clients:%d]", psock->getport(), psock->getclientsnum());
                        pDoc->SetTitle(mess);
                        mess.Format("-------------------- CLIENT connected: %s/%d -------------------------",
                                    psock->getaddr(psock->getlastaccepted()), psock->getport(psock->getlastaccepted()));
                        pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
                        pEdit->ReplaceSel("\r\n" + mess + "\r\n");
                }
                break;

        case FD_READ:     //wParam servsock=accept() that send data
                mess.Format("---------- FROM: %s/%d -------------",
                            psock->getaddr(SOCKET(wParam)), psock->getport(SOCKET(wParam)));
                pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
                pEdit->ReplaceSel("\r\n" + mess + "\r\n");

                buff = psock->Read((SOCKET)wParam);
                pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
                pEdit->ReplaceSel(CString(buff) + "\r\n");
                break;

        case FD_CLOSE:    //wParam servsock that disconnected
                mess.Format("-------------------- CLIENT disconnected: %s/%d --------------------",
                            psock->getaddr(SOCKET(wParam)), psock->getport(SOCKET(wParam)));
                pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
                pEdit->ReplaceSel("\r\n" + mess + "\r\n");

                psock->Canceled(SOCKET(wParam));

                mess.Format("Listening port: %d  [clients:%d]", psock->getport(), psock->getclientsnum());
                pDoc->SetTitle(mess);

                if (HIWORD(lParam)) { //error during FD_CLOSE
                        pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
                        WSASetLastError(HIWORD(lParam));
                        pEdit->ReplaceSel(CString(psock->GetError()));
                }
                break;
        }

        return 0;
}



// CServerView construction/destruction
CServerView::CServerView(): m_Edited(false)
{
}

CServerView::~CServerView()
{
}


// CServerView diagnostics

#ifdef _DEBUG
void CServerView::AssertValid() const
{
        CEditView::AssertValid();
}

void CServerView::Dump(CDumpContext& dc) const
{
        CEditView::Dump(dc);
}

CServerDoc* CServerView::GetDocument() const // non-debug version is inline
{
        ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CServerDoc)));
        return (CServerDoc*)m_pDocument;
}
#endif //_DEBUG


// CServerView message handlers

int CServerView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
        if (CEditView::OnCreate(lpCreateStruct) == -1)
                return -1;

        pEdit = &GetEditCtrl();
        pEdit->SetLimitText(-1);

        return 0;
}

BOOL CServerView::PreCreateWindow(CREATESTRUCT& cs)
{
        // TODO: Add your specialized code here and/or call the base class

        BOOL bPreCreated = CEditView::PreCreateWindow(cs);
        cs.style &= ~(ES_AUTOHSCROLL | WS_HSCROLL);	// Enable word-wrapping

        return bPreCreated;
}

void CServerView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
        CServerDoc *pDoc = GetDocument();
        Socket *psock = pDoc->getsocket();
        char *data = 0, *err;
        int len;


        if (nChar == 45) {                                //EDIT DATA
                if (psock->getclientsnum()) {
                        CSendCancelDlg dlg(psock);
                        //dlg.SetWindowText("Send to client");

                        if (dlg.DoModal() == IDOK) {
                                if ((client = dlg.m_clientAddr) != "" && (clientSock = dlg.m_clientSock)) {
                                        pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
                                        pEdit->ReplaceSel("\r\n----------- TO: " + client + " -------------\r\n");
                                        m_Line = pEdit->LineFromChar();
                                        m_Edited = true;
                                }
                        }
                }
        } else if (m_Edited && nChar == 27) {               //SEND DATA
                int Line = pEdit->LineFromChar();

                if (Line > m_Line) {
                        mess = "";
                        for (int i = m_Line; i < Line; i++) {
                                len = pEdit->GetLine(i, temp, 256);
                                temp[len] = 0;
                                mess += temp;
                                mess += "\r\n";
                        }


                        pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
                        pEdit->ReplaceSel("----------- endTO: " + client + " -----------\r\n");


                        data = new char[mess.GetLength()+1];
                        sprintf(data, "%s", mess);
                        if (err = psock->Send(data, clientSock)) {
                                pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
                                pEdit->ReplaceSel("\r\n ERROR: " + (CString)err + "\r\n");
                        }
                }


                m_Edited = false;
        } else if (nChar == 46) {             //DELETE client
                CSendCancelDlg dlg(psock);
                //dlg.SetWindowText("Disconnect client");

                if (dlg.DoModal() == IDOK) {
                        if (err = psock->Disconnect(dlg.m_clientSock)) {
                                pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
                                mess.Format("\r\n-------- ERROR disconneting client: %s/%d - %s -----------\r\n",
                                            psock->getaddr(dlg.m_clientSock), psock->getport(dlg.m_clientSock), err);
                                pEdit->ReplaceSel(mess);
                        }
                        PostMessage(WM_SERVER, WPARAM(dlg.m_clientSock), LPARAM(32));
                        /*if(!psock->Canceled(dlg.m_clientSock))
                        {
                        pEdit->SetSel(pEdit->GetWindowTextLength(),pEdit->GetWindowTextLength());
                          pEdit->ReplaceSel("\r\n------- ERROR in Socket::Canceled() -------\r\n");
                        }*/
                }
        }


        if (data)
                delete[] data;

        CEditView::OnKeyDown(nChar, nRepCnt, nFlags);
}
