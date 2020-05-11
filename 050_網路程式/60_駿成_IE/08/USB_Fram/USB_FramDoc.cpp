// USB_FramDoc.cpp : implementation of the CUSB_FramDoc class
//

#include "stdafx.h"
#include "USB_Fram.h"

#include "USB_FramDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUSB_FramDoc

IMPLEMENT_DYNCREATE(CUSB_FramDoc, CDocument)

BEGIN_MESSAGE_MAP(CUSB_FramDoc, CDocument)
	//{{AFX_MSG_MAP(CUSB_FramDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUSB_FramDoc construction/destruction

CUSB_FramDoc::CUSB_FramDoc()
{
	// TODO: add one-time construction code here

}

CUSB_FramDoc::~CUSB_FramDoc()
{
}

BOOL CUSB_FramDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CUSB_FramDoc serialization

void CUSB_FramDoc::Serialize(CArchive& ar)
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
// CUSB_FramDoc diagnostics

#ifdef _DEBUG
void CUSB_FramDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUSB_FramDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUSB_FramDoc commands
