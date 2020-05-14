// playlistView.h : interface of the CPlaylistView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "wmpplayer4.h"
#include "webbrowser2.h"
//}}AFX_INCLUDES

#if !defined(AFX_PLAYLISTVIEW_H__6EAEE4E2_7148_41D2_926F_A77536C0C2AE__INCLUDED_)
#define AFX_PLAYLISTVIEW_H__6EAEE4E2_7148_41D2_926F_A77536C0C2AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPlaylistView : public CFormView
{
protected: // create from serialization only
	CPlaylistView();
	DECLARE_DYNCREATE(CPlaylistView)

public:
	//{{AFX_DATA(CPlaylistView)
	enum { IDD = IDD_PLAYLIST_FORM };
	CEdit	m_status;
	CListBox	m_list;
	CWMPPlayer4	m_player;
	CWebBrowser2	m_Web;
	//}}AFX_DATA

// Attributes
public:
	CPlaylistDoc* GetDocument();
    void InitEncoder(void) ;
	bool GetPlayerState();
	void WriteLogFile(int intindex,CString StrMessage);
	void EmailError(CString StrWriteMessage);
	bool ReadXMLConfig();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlaylistView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnFinalRelease();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPlaylistView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPlaylistView)
	afx_msg void OnButton1();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in playlistView.cpp
inline CPlaylistDoc* CPlaylistView::GetDocument()
   { return (CPlaylistDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYLISTVIEW_H__6EAEE4E2_7148_41D2_926F_A77536C0C2AE__INCLUDED_)
