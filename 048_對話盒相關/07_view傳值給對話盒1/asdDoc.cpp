// asdDoc.cpp : implementation of the CAsdDoc class
//

#include "stdafx.h"
#include "asd.h"

#include "asdDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAsdDoc

IMPLEMENT_DYNCREATE(CAsdDoc, CDocument)

BEGIN_MESSAGE_MAP(CAsdDoc, CDocument)
	//{{AFX_MSG_MAP(CAsdDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsdDoc construction/destruction

CAsdDoc::CAsdDoc()
{
	// TODO: add one-time construction code here

}

CAsdDoc::~CAsdDoc()
{
}

BOOL CAsdDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAsdDoc serialization

void CAsdDoc::Serialize(CArchive& ar)
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
// CAsdDoc diagnostics

#ifdef _DEBUG
void CAsdDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAsdDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAsdDoc commands
