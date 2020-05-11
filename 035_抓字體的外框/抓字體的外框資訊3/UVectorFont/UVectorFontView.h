// UVectorFontView.h : interface of the CUVectorFontView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UVECTORFONTVIEW_H__480796D1_7E62_4D80_BF8C_D41DACD192A8__INCLUDED_)
#define AFX_UVECTORFONTVIEW_H__480796D1_7E62_4D80_BF8C_D41DACD192A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CUVectorFontView : public CView
{
protected: // create from serialization only
	CUVectorFontView();
	DECLARE_DYNCREATE(CUVectorFontView)

// Attributes
public:
	CUVectorFontDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUVectorFontView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUVectorFontView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUVectorFontView)
	afx_msg void OnTextInput();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
protected:
    CString m_sTextEdit;
    int m_iFontHeight;
    int m_iFontSpace;
    CString m_sFontFaceName;

protected:
    FIXED FloatToFixed(double d);
    int mapFXY(FIXED fxy);
    void drawOutLine(CDC *pDC,int wType,int cpfx, POINTFX apfx[], int x, int y);
    void drawOutLine(CDC *pDC);
};

#ifndef _DEBUG  // debug version in UVectorFontView.cpp
inline CUVectorFontDoc* CUVectorFontView::GetDocument()
   { return (CUVectorFontDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UVECTORFONTVIEW_H__480796D1_7E62_4D80_BF8C_D41DACD192A8__INCLUDED_)
