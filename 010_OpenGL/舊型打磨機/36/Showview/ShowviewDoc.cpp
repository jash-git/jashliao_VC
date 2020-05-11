// ShowviewDoc.cpp : implementation of the CShowviewDoc class
//

#include "stdafx.h"
#include "Showview.h"

#include "ShowviewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowviewDoc

IMPLEMENT_DYNCREATE(CShowviewDoc, CDocument)

BEGIN_MESSAGE_MAP(CShowviewDoc, CDocument)
	//{{AFX_MSG_MAP(CShowviewDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowviewDoc construction/destruction

CShowviewDoc::CShowviewDoc()
{
	// TODO: add one-time construction code here

}

CShowviewDoc::~CShowviewDoc()
{
}

BOOL CShowviewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CShowviewDoc serialization

void CShowviewDoc::Serialize(CArchive& ar)
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
// CShowviewDoc diagnostics

#ifdef _DEBUG
void CShowviewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShowviewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowviewDoc commands
