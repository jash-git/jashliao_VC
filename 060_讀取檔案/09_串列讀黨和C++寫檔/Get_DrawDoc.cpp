// Get_DrawDoc.cpp : implementation of the CGet_DrawDoc class
//

#include "stdafx.h"
#include "Get_Draw.h"

#include "Get_DrawDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGet_DrawDoc

IMPLEMENT_DYNCREATE(CGet_DrawDoc, CDocument)

BEGIN_MESSAGE_MAP(CGet_DrawDoc, CDocument)
	//{{AFX_MSG_MAP(CGet_DrawDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGet_DrawDoc construction/destruction

CGet_DrawDoc::CGet_DrawDoc()
{
	// TODO: add one-time construction code here

}

CGet_DrawDoc::~CGet_DrawDoc()
{
}

BOOL CGet_DrawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGet_DrawDoc serialization

void CGet_DrawDoc::Serialize(CArchive& ar)
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
// CGet_DrawDoc diagnostics

#ifdef _DEBUG
void CGet_DrawDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGet_DrawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGet_DrawDoc commands
