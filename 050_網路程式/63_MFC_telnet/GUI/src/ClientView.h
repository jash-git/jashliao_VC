// ClientView.h : interface of the CClientView class
//


#pragma once


class CClientView : public CEditView
{
protected: // create from serialization only
        CClientView();
        DECLARE_DYNCREATE(CClientView)

// Attributes
public:
        CClientDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
        virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
        virtual ~CClientView();
#ifdef _DEBUG
        virtual void AssertValid() const;
        virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
        DECLARE_MESSAGE_MAP()

        afx_msg LRESULT Client(WPARAM, LPARAM);

private:
        int m_Line;
        bool m_Edited;
        CEdit *pEdit;
        CString mess;                //
        char temp[256];             //buffer for keydown event, Send(data)


public:
        afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
        afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in ClietView.cpp
inline CClientDoc* CClientView::GetDocument() const
{
        return reinterpret_cast<CClientDoc*>(m_pDocument);
}
#endif

