// glDoc.cpp : implementation of the CGlDoc class
//

#include "stdafx.h"
#include "gl.h"

#include "glDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGlDoc

IMPLEMENT_DYNCREATE(CGlDoc, CDocument)

BEGIN_MESSAGE_MAP(CGlDoc, CDocument)
	//{{AFX_MSG_MAP(CGlDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGlDoc construction/destruction

CGlDoc::CGlDoc()
{
	// TODO: add one-time construction code here

}

CGlDoc::~CGlDoc()
{
}

BOOL CGlDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGlDoc serialization

void CGlDoc::Serialize(CArchive& ar)
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
// CGlDoc diagnostics

#ifdef _DEBUG
void CGlDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGlDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGlDoc commands
