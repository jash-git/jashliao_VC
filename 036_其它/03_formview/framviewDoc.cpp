// framviewDoc.cpp : implementation of the CFramviewDoc class
//

#include "stdafx.h"
#include "framview.h"

#include "framviewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFramviewDoc

IMPLEMENT_DYNCREATE(CFramviewDoc, CDocument)

BEGIN_MESSAGE_MAP(CFramviewDoc, CDocument)
	//{{AFX_MSG_MAP(CFramviewDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFramviewDoc construction/destruction

CFramviewDoc::CFramviewDoc()
{
	// TODO: add one-time construction code here

}

CFramviewDoc::~CFramviewDoc()
{
}

BOOL CFramviewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFramviewDoc serialization

void CFramviewDoc::Serialize(CArchive& ar)
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
// CFramviewDoc diagnostics

#ifdef _DEBUG
void CFramviewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFramviewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFramviewDoc commands
