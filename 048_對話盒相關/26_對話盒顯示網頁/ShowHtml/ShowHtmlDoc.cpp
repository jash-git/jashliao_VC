// ShowHtmlDoc.cpp : implementation of the CShowHtmlDoc class
//

#include "stdafx.h"
#include "ShowHtml.h"

#include "ShowHtmlDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowHtmlDoc

IMPLEMENT_DYNCREATE(CShowHtmlDoc, CDocument)

BEGIN_MESSAGE_MAP(CShowHtmlDoc, CDocument)
	//{{AFX_MSG_MAP(CShowHtmlDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowHtmlDoc construction/destruction

CShowHtmlDoc::CShowHtmlDoc()
{
	// TODO: add one-time construction code here

}

CShowHtmlDoc::~CShowHtmlDoc()
{
}

BOOL CShowHtmlDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CShowHtmlDoc serialization

void CShowHtmlDoc::Serialize(CArchive& ar)
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
// CShowHtmlDoc diagnostics

#ifdef _DEBUG
void CShowHtmlDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShowHtmlDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowHtmlDoc commands
