// TestGLDoc.cpp : implementation of the CTestGLDoc class
//

#include "stdafx.h"
#include "TestGL.h"
#include "TestGLDoc.h"
#include "TestGLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestGLDoc

IMPLEMENT_DYNCREATE(CTestGLDoc, CDocument)

BEGIN_MESSAGE_MAP(CTestGLDoc, CDocument)
	//{{AFX_MSG_MAP(CTestGLDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestGLDoc construction/destruction

CTestGLDoc::CTestGLDoc()
{
	// TODO: add one-time construction code here

}

CTestGLDoc::~CTestGLDoc()
{
}

BOOL CTestGLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
 	POSITION pos=GetFirstViewPosition();
	CTestGLView *DrawV=(CTestGLView *)GetNextView(pos);
	DrawV->SetObjXYZRange(100.,-100.,100.,-100.,100.,-100.);
	DrawV->SetModelViewMatrix(-60.,0.,45.);
	DrawV->ViewAll();
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTestGLDoc serialization

void CTestGLDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		POSITION pos=GetFirstViewPosition();
	CTestGLView *DrawV=(CTestGLView *)GetNextView(pos);
	DrawV->SaveDIBitmap(ar);

	}
	else
	{
		// TODO: add loading code here
	    
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTestGLDoc diagnostics

#ifdef _DEBUG
void CTestGLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestGLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestGLDoc commands

BOOL CTestGLDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	
	return TRUE;
}

BOOL CTestGLDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
/*	POSITION pos=GetFirstViewPosition();
	CTestGLView *DrawV=(CTestGLView *)GetNextView(pos);
	DrawV->SaveDIBitmap(lpszPathName);
    return TRUE;*/
	return CDocument::OnSaveDocument(lpszPathName);
}
