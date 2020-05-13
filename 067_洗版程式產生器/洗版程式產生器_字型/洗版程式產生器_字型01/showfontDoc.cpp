// showfontDoc.cpp : implementation of the CShowfontDoc class
//

#include "stdafx.h"
#include "showfont.h"

#include "showfontDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowfontDoc

IMPLEMENT_DYNCREATE(CShowfontDoc, CDocument)

BEGIN_MESSAGE_MAP(CShowfontDoc, CDocument)
	//{{AFX_MSG_MAP(CShowfontDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowfontDoc construction/destruction

CShowfontDoc::CShowfontDoc()
{
	// TODO: add one-time construction code here

}

CShowfontDoc::~CShowfontDoc()
{
}

BOOL CShowfontDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CShowfontDoc serialization

void CShowfontDoc::Serialize(CArchive& ar)
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
// CShowfontDoc diagnostics

#ifdef _DEBUG
void CShowfontDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShowfontDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowfontDoc commands
