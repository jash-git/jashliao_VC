// playlistDoc.cpp : implementation of the CPlaylistDoc class
//

#include "stdafx.h"
#include "playlist.h"

#include "playlistDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlaylistDoc

IMPLEMENT_DYNCREATE(CPlaylistDoc, CDocument)

BEGIN_MESSAGE_MAP(CPlaylistDoc, CDocument)
	//{{AFX_MSG_MAP(CPlaylistDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlaylistDoc construction/destruction

CPlaylistDoc::CPlaylistDoc()
{
	// TODO: add one-time construction code here

}

CPlaylistDoc::~CPlaylistDoc()
{
}

BOOL CPlaylistDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPlaylistDoc serialization

void CPlaylistDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPlaylistDoc diagnostics

#ifdef _DEBUG
void CPlaylistDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPlaylistDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPlaylistDoc commands
