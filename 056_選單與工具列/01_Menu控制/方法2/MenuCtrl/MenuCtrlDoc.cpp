// MenuCtrlDoc.cpp : implementation of the CMenuCtrlDoc class
//

#include "stdafx.h"
#include "MenuCtrl.h"

#include "MenuCtrlDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenuCtrlDoc

IMPLEMENT_DYNCREATE(CMenuCtrlDoc, CDocument)

BEGIN_MESSAGE_MAP(CMenuCtrlDoc, CDocument)
	//{{AFX_MSG_MAP(CMenuCtrlDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenuCtrlDoc construction/destruction

CMenuCtrlDoc::CMenuCtrlDoc()
{
	// TODO: add one-time construction code here

}

CMenuCtrlDoc::~CMenuCtrlDoc()
{
}

BOOL CMenuCtrlDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMenuCtrlDoc serialization

void CMenuCtrlDoc::Serialize(CArchive& ar)
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
// CMenuCtrlDoc diagnostics

#ifdef _DEBUG
void CMenuCtrlDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMenuCtrlDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMenuCtrlDoc commands
