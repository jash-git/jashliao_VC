// ShowBmpDoc.cpp : implementation of the CShowBmpDoc class
//

#include "stdafx.h"
#include "ShowBmp.h"

#include "ShowBmpDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowBmpDoc

IMPLEMENT_DYNCREATE(CShowBmpDoc, CDocument)

BEGIN_MESSAGE_MAP(CShowBmpDoc, CDocument)
	//{{AFX_MSG_MAP(CShowBmpDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowBmpDoc construction/destruction

CShowBmpDoc::CShowBmpDoc()
{
	// TODO: add one-time construction code here

}

CShowBmpDoc::~CShowBmpDoc()
{
}

BOOL CShowBmpDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CShowBmpDoc serialization

void CShowBmpDoc::Serialize(CArchive& ar)
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
// CShowBmpDoc diagnostics

#ifdef _DEBUG
void CShowBmpDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShowBmpDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowBmpDoc commands
