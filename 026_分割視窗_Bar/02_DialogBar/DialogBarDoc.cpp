// DialogBarDoc.cpp : implementation of the CDialogBarDoc class
//

#include "stdafx.h"
#include "DialogBar.h"

#include "DialogBarDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogBarDoc

IMPLEMENT_DYNCREATE(CDialogBarDoc, CDocument)

BEGIN_MESSAGE_MAP(CDialogBarDoc, CDocument)
	//{{AFX_MSG_MAP(CDialogBarDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogBarDoc construction/destruction

CDialogBarDoc::CDialogBarDoc()
{
	// TODO: add one-time construction code here

}

CDialogBarDoc::~CDialogBarDoc()
{
}

BOOL CDialogBarDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDialogBarDoc serialization

void CDialogBarDoc::Serialize(CArchive& ar)
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
// CDialogBarDoc diagnostics

#ifdef _DEBUG
void CDialogBarDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDialogBarDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDialogBarDoc commands
