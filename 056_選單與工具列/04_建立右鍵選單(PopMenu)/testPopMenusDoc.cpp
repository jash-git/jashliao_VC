// testPopMenusDoc.cpp : implementation of the CTestPopMenusDoc class
//

#include "stdafx.h"
#include "testPopMenus.h"

#include "testPopMenusDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestPopMenusDoc

IMPLEMENT_DYNCREATE(CTestPopMenusDoc, CDocument)

BEGIN_MESSAGE_MAP(CTestPopMenusDoc, CDocument)
	//{{AFX_MSG_MAP(CTestPopMenusDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestPopMenusDoc construction/destruction

CTestPopMenusDoc::CTestPopMenusDoc()
{
	// TODO: add one-time construction code here

}

CTestPopMenusDoc::~CTestPopMenusDoc()
{
}

BOOL CTestPopMenusDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTestPopMenusDoc serialization

void CTestPopMenusDoc::Serialize(CArchive& ar)
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
// CTestPopMenusDoc diagnostics

#ifdef _DEBUG
void CTestPopMenusDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestPopMenusDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestPopMenusDoc commands
