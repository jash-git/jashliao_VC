// MFCPaPaGoDoc.cpp : implementation of the CMFCPaPaGoDoc class
//

#include "stdafx.h"
#include "MFCPaPaGo.h"

#include "MFCPaPaGoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCPaPaGoDoc

IMPLEMENT_DYNCREATE(CMFCPaPaGoDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCPaPaGoDoc, CDocument)
	//{{AFX_MSG_MAP(CMFCPaPaGoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCPaPaGoDoc construction/destruction

CMFCPaPaGoDoc::CMFCPaPaGoDoc()
{
	// TODO: add one-time construction code here

}

CMFCPaPaGoDoc::~CMFCPaPaGoDoc()
{
}

BOOL CMFCPaPaGoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFCPaPaGoDoc serialization

void CMFCPaPaGoDoc::Serialize(CArchive& ar)
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
// CMFCPaPaGoDoc diagnostics

#ifdef _DEBUG
void CMFCPaPaGoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCPaPaGoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCPaPaGoDoc commands
