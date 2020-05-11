// VFWDoc.cpp : implementation of the CVFWDoc class
//

#include "stdafx.h"
#include "VFW.h"

#include "VFWDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVFWDoc

IMPLEMENT_DYNCREATE(CVFWDoc, CDocument)

BEGIN_MESSAGE_MAP(CVFWDoc, CDocument)
	//{{AFX_MSG_MAP(CVFWDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVFWDoc construction/destruction

CVFWDoc::CVFWDoc()
{
	// TODO: add one-time construction code here

}

CVFWDoc::~CVFWDoc()
{
}

BOOL CVFWDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CVFWDoc serialization

void CVFWDoc::Serialize(CArchive& ar)
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
// CVFWDoc diagnostics

#ifdef _DEBUG
void CVFWDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVFWDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVFWDoc commands
