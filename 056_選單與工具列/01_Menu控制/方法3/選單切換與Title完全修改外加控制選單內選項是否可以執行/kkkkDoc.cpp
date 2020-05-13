// kkkkDoc.cpp : implementation of the CKkkkDoc class
//

#include "stdafx.h"
#include "kkkk.h"

#include "kkkkDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKkkkDoc

IMPLEMENT_DYNCREATE(CKkkkDoc, CDocument)

BEGIN_MESSAGE_MAP(CKkkkDoc, CDocument)
	//{{AFX_MSG_MAP(CKkkkDoc)
	ON_COMMAND(ID_test, Ontest)
	ON_COMMAND(ID_t, Ont)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKkkkDoc construction/destruction

CKkkkDoc::CKkkkDoc()
{
	// TODO: add one-time construction code here

}

CKkkkDoc::~CKkkkDoc()
{
}

BOOL CKkkkDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	SetTitle("test");
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CKkkkDoc serialization

void CKkkkDoc::Serialize(CArchive& ar)
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
// CKkkkDoc diagnostics

#ifdef _DEBUG
void CKkkkDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKkkkDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKkkkDoc commands

void CKkkkDoc::Ontest() 
{
	// TODO: Add your command handler code here
	
}

void CKkkkDoc::Ont() 
{
	// TODO: Add your command handler code here
	
}
