// mouseDoc.cpp : implementation of the CMouseDoc class
//

#include "stdafx.h"
#include "mouse.h"

#include "mouseDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMouseDoc

IMPLEMENT_DYNCREATE(CMouseDoc, CDocument)

BEGIN_MESSAGE_MAP(CMouseDoc, CDocument)
	//{{AFX_MSG_MAP(CMouseDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMouseDoc construction/destruction

CMouseDoc::CMouseDoc()
{
	// TODO: add one-time construction code here

}

CMouseDoc::~CMouseDoc()
{
}

BOOL CMouseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMouseDoc serialization

void CMouseDoc::Serialize(CArchive& ar)
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
// CMouseDoc diagnostics

#ifdef _DEBUG
void CMouseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMouseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMouseDoc commands
