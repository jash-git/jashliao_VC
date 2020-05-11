// SDIShowDoc.cpp : implementation of the CSDIShowDoc class
//

#include "stdafx.h"
#include "SDIShow.h"

#include "SDIShowDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSDIShowDoc

IMPLEMENT_DYNCREATE(CSDIShowDoc, CDocument)

BEGIN_MESSAGE_MAP(CSDIShowDoc, CDocument)
	//{{AFX_MSG_MAP(CSDIShowDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSDIShowDoc construction/destruction

CSDIShowDoc::CSDIShowDoc()
{
	// TODO: add one-time construction code here

}

CSDIShowDoc::~CSDIShowDoc()
{
}

BOOL CSDIShowDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	SetTitle("≈Á√“µ{¶°");
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSDIShowDoc serialization

void CSDIShowDoc::Serialize(CArchive& ar)
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
// CSDIShowDoc diagnostics

#ifdef _DEBUG
void CSDIShowDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSDIShowDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSDIShowDoc commands
