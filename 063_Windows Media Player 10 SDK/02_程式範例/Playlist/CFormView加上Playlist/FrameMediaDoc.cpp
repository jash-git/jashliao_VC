// FrameMediaDoc.cpp : implementation of the CFrameMediaDoc class
//

#include "stdafx.h"
#include "FrameMedia.h"

#include "FrameMediaDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrameMediaDoc

IMPLEMENT_DYNCREATE(CFrameMediaDoc, CDocument)

BEGIN_MESSAGE_MAP(CFrameMediaDoc, CDocument)
	//{{AFX_MSG_MAP(CFrameMediaDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrameMediaDoc construction/destruction

CFrameMediaDoc::CFrameMediaDoc()
{
	// TODO: add one-time construction code here

}

CFrameMediaDoc::~CFrameMediaDoc()
{
}

BOOL CFrameMediaDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFrameMediaDoc serialization

void CFrameMediaDoc::Serialize(CArchive& ar)
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
// CFrameMediaDoc diagnostics

#ifdef _DEBUG
void CFrameMediaDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFrameMediaDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFrameMediaDoc commands
