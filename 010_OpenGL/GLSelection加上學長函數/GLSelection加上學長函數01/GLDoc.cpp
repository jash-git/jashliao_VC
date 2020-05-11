// GLDoc.cpp : implementation of the CGLDoc class
//

#include "stdafx.h"
#include "GL.h"

#include "GLDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGLDoc

IMPLEMENT_DYNCREATE(CGLDoc, CDocument)

BEGIN_MESSAGE_MAP(CGLDoc, CDocument)
	//{{AFX_MSG_MAP(CGLDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGLDoc construction/destruction

CGLDoc::CGLDoc()
{
	// TODO: add one-time construction code here

}

CGLDoc::~CGLDoc()
{
}

BOOL CGLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGLDoc serialization

void CGLDoc::Serialize(CArchive& ar)
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
// CGLDoc diagnostics

#ifdef _DEBUG
void CGLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGLDoc commands
