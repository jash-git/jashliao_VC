// TopShowDoc.cpp : implementation of the CTopShowDoc class
//

#include "stdafx.h"
#include "TopShow.h"

#include "TopShowDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTopShowDoc

IMPLEMENT_DYNCREATE(CTopShowDoc, CDocument)

BEGIN_MESSAGE_MAP(CTopShowDoc, CDocument)
	//{{AFX_MSG_MAP(CTopShowDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTopShowDoc construction/destruction

CTopShowDoc::CTopShowDoc()
{
	// TODO: add one-time construction code here

}

CTopShowDoc::~CTopShowDoc()
{
}

BOOL CTopShowDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTopShowDoc serialization

void CTopShowDoc::Serialize(CArchive& ar)
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
// CTopShowDoc diagnostics

#ifdef _DEBUG
void CTopShowDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTopShowDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTopShowDoc commands
