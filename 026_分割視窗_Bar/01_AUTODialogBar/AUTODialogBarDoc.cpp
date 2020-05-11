// AUTODialogBarDoc.cpp : implementation of the CAUTODialogBarDoc class
//

#include "stdafx.h"
#include "AUTODialogBar.h"

#include "AUTODialogBarDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAUTODialogBarDoc

IMPLEMENT_DYNCREATE(CAUTODialogBarDoc, CDocument)

BEGIN_MESSAGE_MAP(CAUTODialogBarDoc, CDocument)
	//{{AFX_MSG_MAP(CAUTODialogBarDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAUTODialogBarDoc construction/destruction

CAUTODialogBarDoc::CAUTODialogBarDoc()
{
	// TODO: add one-time construction code here

}

CAUTODialogBarDoc::~CAUTODialogBarDoc()
{
}

BOOL CAUTODialogBarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAUTODialogBarDoc serialization

void CAUTODialogBarDoc::Serialize(CArchive& ar)
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
// CAUTODialogBarDoc diagnostics

#ifdef _DEBUG
void CAUTODialogBarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAUTODialogBarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAUTODialogBarDoc commands
