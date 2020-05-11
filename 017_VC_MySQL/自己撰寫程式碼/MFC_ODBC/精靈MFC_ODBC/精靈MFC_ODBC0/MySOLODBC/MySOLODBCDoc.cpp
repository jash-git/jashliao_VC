// MySOLODBCDoc.cpp : implementation of the CMySOLODBCDoc class
//

#include "stdafx.h"
#include "MySOLODBC.h"

#include "MySOLODBCSet.h"
#include "MySOLODBCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMySOLODBCDoc

IMPLEMENT_DYNCREATE(CMySOLODBCDoc, CDocument)

BEGIN_MESSAGE_MAP(CMySOLODBCDoc, CDocument)
	//{{AFX_MSG_MAP(CMySOLODBCDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMySOLODBCDoc construction/destruction

CMySOLODBCDoc::CMySOLODBCDoc()
{
	// TODO: add one-time construction code here

}

CMySOLODBCDoc::~CMySOLODBCDoc()
{
}

BOOL CMySOLODBCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMySOLODBCDoc serialization

void CMySOLODBCDoc::Serialize(CArchive& ar)
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
// CMySOLODBCDoc diagnostics

#ifdef _DEBUG
void CMySOLODBCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMySOLODBCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMySOLODBCDoc commands
