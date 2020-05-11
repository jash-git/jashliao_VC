// viewDoc.cpp : implementation of the CViewDoc class
//

#include "stdafx.h"
#include "view.h"

#include "viewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewDoc

IMPLEMENT_DYNCREATE(CViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CViewDoc, CDocument)
	//{{AFX_MSG_MAP(CViewDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewDoc construction/destruction

CViewDoc::CViewDoc()
{
	// TODO: add one-time construction code here

}

CViewDoc::~CViewDoc()
{
}

BOOL CViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CViewDoc serialization

void CViewDoc::Serialize(CArchive& ar)
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
// CViewDoc diagnostics

#ifdef _DEBUG
void CViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CViewDoc commands
