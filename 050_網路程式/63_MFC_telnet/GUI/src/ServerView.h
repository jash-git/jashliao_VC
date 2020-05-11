#pragma once


// CServerView view

class CServerView : public CEditView
{
        DECLARE_DYNCREATE(CServerView)

protected:
        CServerView();           // protected constructor used by dynamic creation
        virtual ~CServerView();

        // Attributes
public:
        CServerDoc* GetDocument() const;

public:
#ifdef _DEBUG
        virtual void AssertValid() const;
        virtual void Dump(CDumpContext& dc) const;
#endif

protected:
        DECLARE_MESSAGE_MAP()

        afx_msg LRESULT Server(WPARAM, LPARAM);

private:
        char temp[256];             //buffer for keydown event, Send(data)
        int m_Line;
        bool m_Edited;
        CString mess;
        CString client;
        SOCKET clientSock;
        CEdit *pEdit;

public:
        afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
protected:
        virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
        afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in ClietView.cpp
inline CServerDoc* CServerView::GetDocument() const
{
        return reinterpret_cast<CServerDoc*>(m_pDocument);
}
#endif
