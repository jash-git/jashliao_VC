#pragma once

#include "Lib\Socket.h"

// CServerDoc document

class CServerDoc : public CDocument
{
protected:
        CServerDoc();
        DECLARE_DYNCREATE(CServerDoc)

public:
        virtual ~CServerDoc();
        virtual void Serialize(CArchive& ar);   // overridden for document i/o
#ifdef _DEBUG
        virtual void AssertValid() const;
        virtual void Dump(CDumpContext& dc) const;
#endif


private:
        CString str;
        Socket *m_sSock;
public:
        Socket *getsocket() {
                return m_sSock;
        }
        virtual BOOL OnNewDocument();

        DECLARE_MESSAGE_MAP()
};
