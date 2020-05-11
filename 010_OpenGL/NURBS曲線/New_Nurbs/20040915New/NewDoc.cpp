// NewDoc.cpp : implementation of the CNewDoc class
//

#include "stdafx.h"
#include "New.h"

#include "NewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewDoc

IMPLEMENT_DYNCREATE(CNewDoc, CDocument)

BEGIN_MESSAGE_MAP(CNewDoc, CDocument)
	//{{AFX_MSG_MAP(CNewDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewDoc construction/destruction

CNewDoc::CNewDoc()
{
	// TODO: add one-time construction code here

}

CNewDoc::~CNewDoc()
{
}

BOOL CNewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	SetTitle("¤­¶b¥´¿i¾÷");
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CNewDoc serialization

void CNewDoc::Serialize(CArchive& ar)
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
// CNewDoc diagnostics

#ifdef _DEBUG
void CNewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNewDoc commands
