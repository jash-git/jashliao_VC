// Image1Doc.cpp : implementation of the CImage1Doc class
//

#include "stdafx.h"
#include "Image1.h"

#include "Image1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImage1Doc

IMPLEMENT_DYNCREATE(CImage1Doc, CDocument)

BEGIN_MESSAGE_MAP(CImage1Doc, CDocument)
	//{{AFX_MSG_MAP(CImage1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImage1Doc construction/destruction

CImage1Doc::CImage1Doc()
{
	// TODO: add one-time construction code here

}

CImage1Doc::~CImage1Doc()
{
}

BOOL CImage1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CImage1Doc serialization

void CImage1Doc::Serialize(CArchive& ar)
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
// CImage1Doc diagnostics

#ifdef _DEBUG
void CImage1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImage1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImage1Doc commands
