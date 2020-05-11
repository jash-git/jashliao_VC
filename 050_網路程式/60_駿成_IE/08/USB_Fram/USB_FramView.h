// USB_FramView.h : interface of the CUSB_FramView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_USB_FRAMVIEW_H__9EC9A688_91F2_4F5C_B21E_78D64C9D44F4__INCLUDED_)
#define AFX_USB_FRAMVIEW_H__9EC9A688_91F2_4F5C_B21E_78D64C9D44F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CUSB_FramView : public CHtmlView
{
protected: // create from serialization only
	CUSB_FramView();
	DECLARE_DYNCREATE(CUSB_FramView)

// Attributes
public:
	CUSB_FramDoc* GetDocument();
	BOOL CheckInternet(LPCTSTR URL);//判斷網路是否正常
	void DisDriver();//判斷磁碟機代號

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUSB_FramView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnNavigateComplete2(LPCTSTR strURL);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUSB_FramView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUSB_FramView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in USB_FramView.cpp
inline CUSB_FramDoc* CUSB_FramView::GetDocument()
   { return (CUSB_FramDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USB_FRAMVIEW_H__9EC9A688_91F2_4F5C_B21E_78D64C9D44F4__INCLUDED_)
