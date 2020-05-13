// test_HideDoc.cpp : implementation of the CTest_HideDoc class
//

#include "stdafx.h"
#include "test_Hide.h"

#include "test_HideDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest_HideDoc

IMPLEMENT_DYNCREATE(CTest_HideDoc, CDocument)

BEGIN_MESSAGE_MAP(CTest_HideDoc, CDocument)
	//{{AFX_MSG_MAP(CTest_HideDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest_HideDoc construction/destruction

CTest_HideDoc::CTest_HideDoc()
{
	// TODO: add one-time construction code here

}

CTest_HideDoc::~CTest_HideDoc()
{
}

BOOL CTest_HideDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTest_HideDoc serialization

void CTest_HideDoc::Serialize(CArchive& ar)
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
// CTest_HideDoc diagnostics

#ifdef _DEBUG
void CTest_HideDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTest_HideDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest_HideDoc commands
