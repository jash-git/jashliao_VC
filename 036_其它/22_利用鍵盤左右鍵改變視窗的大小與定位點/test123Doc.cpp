// test123Doc.cpp : implementation of the CTest123Doc class
//

#include "stdafx.h"
#include "test123.h"

#include "test123Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest123Doc

IMPLEMENT_DYNCREATE(CTest123Doc, CDocument)

BEGIN_MESSAGE_MAP(CTest123Doc, CDocument)
	//{{AFX_MSG_MAP(CTest123Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest123Doc construction/destruction

CTest123Doc::CTest123Doc()
{
	// TODO: add one-time construction code here

}

CTest123Doc::~CTest123Doc()
{
}

BOOL CTest123Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTest123Doc serialization

void CTest123Doc::Serialize(CArchive& ar)
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
// CTest123Doc diagnostics

#ifdef _DEBUG
void CTest123Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTest123Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest123Doc commands
