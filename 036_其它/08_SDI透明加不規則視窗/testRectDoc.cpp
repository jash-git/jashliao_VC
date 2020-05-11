// testRectDoc.cpp : implementation of the CTestRectDoc class
//

#include "stdafx.h"
#include "testRect.h"

#include "testRectDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestRectDoc

IMPLEMENT_DYNCREATE(CTestRectDoc, CDocument)

BEGIN_MESSAGE_MAP(CTestRectDoc, CDocument)
	//{{AFX_MSG_MAP(CTestRectDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestRectDoc construction/destruction

CTestRectDoc::CTestRectDoc()
{
	// TODO: add one-time construction code here

}

CTestRectDoc::~CTestRectDoc()
{
}

BOOL CTestRectDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTestRectDoc serialization

void CTestRectDoc::Serialize(CArchive& ar)
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
// CTestRectDoc diagnostics

#ifdef _DEBUG
void CTestRectDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestRectDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestRectDoc commands
