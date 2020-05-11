// GLbaseDoc.cpp : implementation of the CGLbaseDoc class
//

#include "stdafx.h"
#include "GLbase.h"

#include "GLbaseDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGLbaseDoc

IMPLEMENT_DYNCREATE(CGLbaseDoc, CDocument)

BEGIN_MESSAGE_MAP(CGLbaseDoc, CDocument)
	//{{AFX_MSG_MAP(CGLbaseDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGLbaseDoc construction/destruction

CGLbaseDoc::CGLbaseDoc()
{
	// TODO: add one-time construction code here

}

CGLbaseDoc::~CGLbaseDoc()
{
}

BOOL CGLbaseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGLbaseDoc serialization

void CGLbaseDoc::Serialize(CArchive& ar)
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
// CGLbaseDoc diagnostics

#ifdef _DEBUG
void CGLbaseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGLbaseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGLbaseDoc commands
