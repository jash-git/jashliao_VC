// WebDoc.cpp : implementation of the CWebDoc class
//

#include "stdafx.h"
#include "Web.h"

#include "WebDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWebDoc

IMPLEMENT_DYNCREATE(CWebDoc, CDocument)

BEGIN_MESSAGE_MAP(CWebDoc, CDocument)
	//{{AFX_MSG_MAP(CWebDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWebDoc construction/destruction

CWebDoc::CWebDoc()
{
	// TODO: add one-time construction code here

}

CWebDoc::~CWebDoc()
{
}

BOOL CWebDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWebDoc serialization

void CWebDoc::Serialize(CArchive& ar)
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
// CWebDoc diagnostics

#ifdef _DEBUG
void CWebDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWebDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWebDoc commands
