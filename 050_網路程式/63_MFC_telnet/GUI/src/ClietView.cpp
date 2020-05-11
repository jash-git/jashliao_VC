// ClietView.cpp : implementation of the CClientView class
//

#include "stdafx.h"
#include "Telnet.h"

#include "ClientDoc.h"
#include "ClientView.h"

#include "Lib\Socket.h"
#include ".\clientview.h"

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CClientView

IMPLEMENT_DYNCREATE(CClientView, CEditView)

BEGIN_MESSAGE_MAP(CClientView, CEditView)
        ON_MESSAGE(WM_CLIENT, Client)
        ON_WM_CREATE()
        ON_WM_KEYDOWN()
END_MESSAGE_MAP()



LRESULT CClientView::Client(WPARAM wParam, LPARAM lParam)
{
        CClientDoc *pDoc = GetDocument();
        Socket *psock = pDoc->getsocket();
        char *buff;
        int len = 0;
        CString sbuff;

        switch (LOWORD(lParam)) {
        case FD_CONNECT:
                if (HIWORD(lParam)) {        //error
                        WSASetLastError(HIWORD(lParam));
                        ::MessageBox(m_hWnd, psock->GetError(), "Connection Error.", MB_OK | MB_ICONHAND);
                        STATIC_DOWNCAST(CChildFrame, GetParent())->m_pane1 = "Offline.";
                        //GetParent()->DestroyWindow();
                        return 0;
                }

                STATIC_DOWNCAST(CChildFrame, GetParent())->m_pane1 = "ONLINE.";

                break;

        case FD_READ:
                buff = psock->Read();
                len = psock->getlastread();
                for (int i = 0; i < len; i++) {            //get "\r\n" format
                        if (buff[i] == '\n' && i > 0 && buff[i-1] != '\r')
                                sbuff.AppendChar('\r');

                        sbuff.AppendChar(buff[i]);
                }
                pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
                pEdit->ReplaceSel(sbuff + "\r\n");
                break;

        case FD_CLOSE:
                pDoc->SetTitle(pDoc->GetTitle() + "  -  connection closed!");
                STATIC_DOWNCAST(CChildFrame, GetParent())->m_pane1 = "Offline.";
                if (HIWORD(lParam)) {
                        pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
                        WSASetLastError(HIWORD(lParam));
                        pEdit->ReplaceSel("\r\n\r\n" + CString(psock->GetError()));
                }
                pDoc->Disconnect();
                break;
        }

        return 0;
}





// CClientView construction/destruction
CClientView::CClientView(): m_Edited(false)
{
}

CClientView::~CClientView()
{
}

BOOL CClientView::PreCreateWindow(CREATESTRUCT& cs)
{
        // TODO: Modify the Window class or styles here by modifying
        //  the CREATESTRUCT cs

        BOOL bPreCreated = CEditView::PreCreateWindow(cs);
        cs.style &= ~(ES_AUTOHSCROLL | WS_HSCROLL);	// Enable word-wrapping

        return bPreCreated;
}


// CClientView diagnostics

#ifdef _DEBUG
void CClientView::AssertValid() const
{
        CEditView::AssertValid();
}

void CClientView::Dump(CDumpContext& dc) const
{
        CEditView::Dump(dc);
}

CClientDoc* CClientView::GetDocument() const // non-debug version is inline
{
        ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CClientDoc)));
        return (CClientDoc*)m_pDocument;
}
#endif //_DEBUG


// CClientView message handlers

int CClientView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
        if (CEditView::OnCreate(lpCreateStruct) == -1)
                return -1;

        pEdit = &GetEditCtrl();
        pEdit->SetLimitText(-1);

        return 0;
}

void CClientView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
        CClientDoc *pDoc = GetDocument();
        char *data = 0, *err;
        int len;

        if (nChar == 45) {                                 //EDIT DATA   "Insert" key
                pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
                pEdit->ReplaceSel("\r\n--------------------Client begin--------------------\r\n");

                m_Line = pEdit->LineFromChar();
                m_Edited = true;
        } else if (m_Edited && nChar == 27) {               //SEND DATA   "Esc" key
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
                        pEdit->ReplaceSel("--------------------Client end----------------------\r\n");


                        data = new char[mess.GetLength()+1];
                        sprintf(data, "%s", mess);
                        if (err = pDoc->getsocket()->Send(data)) {
                                pEdit->SetSel(pEdit->GetWindowTextLength(), pEdit->GetWindowTextLength());
                                pEdit->ReplaceSel("\r\n ERROR: " + (CString)err + "\r\n");
                        }
                }


                m_Edited = false;
        }


        if (data)
                delete[] data;

        CEditView::OnKeyDown(nChar, nRepCnt, nFlags);
}
