// CreateCImageDoc.cpp : implementation of the CCreateCImageDoc class
//

#include "stdafx.h"
#include "CreateCImage.h"

#include "CreateCImageDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCreateCImageDoc

IMPLEMENT_DYNCREATE(CCreateCImageDoc, CDocument)

BEGIN_MESSAGE_MAP(CCreateCImageDoc, CDocument)
END_MESSAGE_MAP()


// CCreateCImageDoc construction/destruction

CCreateCImageDoc::CCreateCImageDoc()
{
	// TODO: add one-time construction code here

}

CCreateCImageDoc::~CCreateCImageDoc()
{
}

BOOL CCreateCImageDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CCreateCImageDoc serialization

void CCreateCImageDoc::Serialize(CArchive& ar)
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


// CCreateCImageDoc diagnostics

#ifdef _DEBUG
void CCreateCImageDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCreateCImageDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCreateCImageDoc commands
