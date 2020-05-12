// DCDoc.cpp : implementation of the CDCDoc class
//

#include "stdafx.h"
#include "DC.h"

#include "DCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDCDoc

IMPLEMENT_DYNCREATE(CDCDoc, CDocument)

BEGIN_MESSAGE_MAP(CDCDoc, CDocument)
	//{{AFX_MSG_MAP(CDCDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDCDoc construction/destruction

CDCDoc::CDCDoc()
{
	// TODO: add one-time construction code here

}

CDCDoc::~CDCDoc()
{
}

BOOL CDCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDCDoc serialization

void CDCDoc::Serialize(CArchive& ar)
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
// CDCDoc diagnostics

#ifdef _DEBUG
void CDCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDCDoc commands
