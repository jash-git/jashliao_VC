// CreateCImageView.h : interface of the CCreateCImageView class
//


#pragma once


class CCreateCImageView : public CView
{
protected: // create from serialization only
	CCreateCImageView();
	DECLARE_DYNCREATE(CCreateCImageView)

// Attributes
public:
	CCreateCImageDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CCreateCImageView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CImage m_Image;
// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Ontest();
};

#ifndef _DEBUG  // debug version in CreateCImageView.cpp
inline CCreateCImageDoc* CCreateCImageView::GetDocument() const
   { return reinterpret_cast<CCreateCImageDoc*>(m_pDocument); }
#endif

