// wed2Doc.cpp : implementation of the CWed2Doc class
//

#include "stdafx.h"
#include "wed2.h"

#include "wed2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#include <gl/gl.h>


/////////////////////////////////////////////////////////////////////////////
// CWed2Doc

IMPLEMENT_DYNCREATE(CWed2Doc, CDocument)

BEGIN_MESSAGE_MAP(CWed2Doc, CDocument)
	//{{AFX_MSG_MAP(CWed2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWed2Doc construction/destruction

CWed2Doc::CWed2Doc()
{
	// TODO: add one-time construction code here
	model = NULL;
}

CWed2Doc::~CWed2Doc()
{
}

BOOL CWed2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	if(model != NULL )
	{
		delete model;
		model = NULL;
	}

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWed2Doc serialization

void CWed2Doc::Serialize(CArchive& ar)
{
	int		ok;
	CString filename;

	filename = ar.GetFile()->GetFileName();

	if (ar.IsStoring())
	{
		// TODO: add storing code here
		::MessageBox(::GetFocus(),"Save not implemented","Error",MB_OK);
	}
	else
	{
		// TODO: add loading code here
		model = new Model;
		ok = model->loadFromMs3dAsciiFile( filename );
		if(!ok)
		{
			::MessageBox(::GetFocus(),"Error loading model","Error",MB_OK);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWed2Doc diagnostics

#ifdef _DEBUG
void CWed2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWed2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWed2Doc commands

void CWed2Doc::draw()
{
	if( model != NULL )
		model->render();
}
