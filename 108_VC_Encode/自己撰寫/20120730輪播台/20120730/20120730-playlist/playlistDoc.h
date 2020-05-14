// playlistDoc.h : interface of the CPlaylistDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLAYLISTDOC_H__778E0934_D9E8_4F2C_8F82_3023BFCFAB05__INCLUDED_)
#define AFX_PLAYLISTDOC_H__778E0934_D9E8_4F2C_8F82_3023BFCFAB05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPlaylistDoc : public CDocument
{
protected: // create from serialization only
	CPlaylistDoc();
	DECLARE_DYNCREATE(CPlaylistDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlaylistDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPlaylistDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPlaylistDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYLISTDOC_H__778E0934_D9E8_4F2C_8F82_3023BFCFAB05__INCLUDED_)
