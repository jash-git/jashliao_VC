// UVectorFontDoc.cpp : implementation of the CUVectorFontDoc class
//

#include "stdafx.h"
#include "UVectorFont.h"

#include "UVectorFontDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUVectorFontDoc

IMPLEMENT_DYNCREATE(CUVectorFontDoc, CDocument)

BEGIN_MESSAGE_MAP(CUVectorFontDoc, CDocument)
	//{{AFX_MSG_MAP(CUVectorFontDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUVectorFontDoc construction/destruction

CUVectorFontDoc::CUVectorFontDoc()
{
	// TODO: add one-time construction code here

}

CUVectorFontDoc::~CUVectorFontDoc()
{
}

BOOL CUVectorFontDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CUVectorFontDoc serialization

void CUVectorFontDoc::Serialize(CArchive& ar)
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
// CUVectorFontDoc diagnostics

#ifdef _DEBUG
void CUVectorFontDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUVectorFontDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUVectorFontDoc commands
