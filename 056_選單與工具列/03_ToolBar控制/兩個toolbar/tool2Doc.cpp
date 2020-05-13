// tool2Doc.cpp : implementation of the CTool2Doc class
//

#include "stdafx.h"
#include "tool2.h"

#include "tool2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTool2Doc

IMPLEMENT_DYNCREATE(CTool2Doc, CDocument)

BEGIN_MESSAGE_MAP(CTool2Doc, CDocument)
	//{{AFX_MSG_MAP(CTool2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTool2Doc construction/destruction

CTool2Doc::CTool2Doc()
{
	// TODO: add one-time construction code here

}

CTool2Doc::~CTool2Doc()
{
}

BOOL CTool2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTool2Doc serialization

void CTool2Doc::Serialize(CArchive& ar)
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
// CTool2Doc diagnostics

#ifdef _DEBUG
void CTool2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTool2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTool2Doc commands
