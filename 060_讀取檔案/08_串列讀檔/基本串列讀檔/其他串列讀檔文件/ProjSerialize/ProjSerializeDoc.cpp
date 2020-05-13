// ProjSerializeDoc.cpp : implementation of the CProjSerializeDoc class
//

#include "stdafx.h"
#include "ProjSerialize.h"

#include "ProjSerializeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProjSerializeDoc

IMPLEMENT_DYNCREATE(CProjSerializeDoc, CDocument)

BEGIN_MESSAGE_MAP(CProjSerializeDoc, CDocument)
	//{{AFX_MSG_MAP(CProjSerializeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProjSerializeDoc construction/destruction

CProjSerializeDoc::CProjSerializeDoc()
{
	// TODO: add one-time construction code here

}

CProjSerializeDoc::~CProjSerializeDoc()
{
}

BOOL CProjSerializeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CProjSerializeDoc serialization

void CProjSerializeDoc::Serialize(CArchive& ar)
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
// CProjSerializeDoc diagnostics

#ifdef _DEBUG
void CProjSerializeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CProjSerializeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProjSerializeDoc commands

BOOL CProjSerializeDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	AfxMessageBox("CProjSerializeDoc::OnOpenDocument");//證明當按下開檔時會執行app內建函數並互叫此函數
	return TRUE;
}
