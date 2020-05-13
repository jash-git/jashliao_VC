// MenuTextDoc.cpp : implementation of the CMenuTextDoc class
//

#include "stdafx.h"
#include "MenuText.h"

#include "MenuTextDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenuTextDoc

IMPLEMENT_DYNCREATE(CMenuTextDoc, CDocument)

BEGIN_MESSAGE_MAP(CMenuTextDoc, CDocument)
	//{{AFX_MSG_MAP(CMenuTextDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenuTextDoc construction/destruction

CMenuTextDoc::CMenuTextDoc()
{
	// TODO: add one-time construction code here

}

CMenuTextDoc::~CMenuTextDoc()
{
}

BOOL CMenuTextDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMenuTextDoc serialization

void CMenuTextDoc::Serialize(CArchive& ar)
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
// CMenuTextDoc diagnostics

#ifdef _DEBUG
void CMenuTextDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMenuTextDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMenuTextDoc commands
