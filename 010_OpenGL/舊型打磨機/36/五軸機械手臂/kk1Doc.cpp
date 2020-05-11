// kk1Doc.cpp : implementation of the CKk1Doc class
//

#include "stdafx.h"
#include "kk1.h"

#include "kk1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKk1Doc

IMPLEMENT_DYNCREATE(CKk1Doc, CDocument)

BEGIN_MESSAGE_MAP(CKk1Doc, CDocument)
	//{{AFX_MSG_MAP(CKk1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKk1Doc construction/destruction

CKk1Doc::CKk1Doc()
{
	// TODO: add one-time construction code here
	SetTitle("五軸鐘錶表框打磨機");
}

CKk1Doc::~CKk1Doc()
{
}

BOOL CKk1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CKk1Doc serialization

void CKk1Doc::Serialize(CArchive& ar)
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
// CKk1Doc diagnostics

#ifdef _DEBUG
void CKk1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKk1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKk1Doc commands
