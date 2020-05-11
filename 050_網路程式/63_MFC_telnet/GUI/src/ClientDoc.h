// ClientDoc.h : interface of the CClientDoc class
//


#pragma once

class CClientView;
#include "Lib\Socket.h"

class CClientDoc : public CDocument
{
protected: // create from serialization only
        CClientDoc();
        DECLARE_DYNCREATE(CClientDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
        virtual BOOL OnNewDocument();
        virtual void Serialize(CArchive& ar);

// Implementation
public:
        virtual ~CClientDoc();
#ifdef _DEBUG
        virtual void AssertValid() const;
        virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
        DECLARE_MESSAGE_MAP()

private:
        Socket *m_cSock;
        CStringList *m_pAddrs;
        CString str;
        CClientView *pc;

        CString m_hostname;        //inet addr to which we get connected
        CString m_ipaddr;          //IP
        int m_port;           //host port

public:
        bool Connect(CString, int);
        void Disconnect();
        Socket *getsocket() {
                return m_cSock;
        }
        //SOCKET *getsocket(){ return m_cSock->getsocket(); }

        afx_msg void OnClntRedial();
        afx_msg void OnClntDisconnect();
        afx_msg void OnClntShell();
};


