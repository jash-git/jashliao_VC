// CreateCImageView.cpp : implementation of the CCreateCImageView class
//

#include "stdafx.h"
#include "CreateCImage.h"

#include "CreateCImageDoc.h"
#include "CreateCImageView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCreateCImageView

IMPLEMENT_DYNCREATE(CCreateCImageView, CView)

BEGIN_MESSAGE_MAP(CCreateCImageView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_test, &CCreateCImageView::Ontest)
END_MESSAGE_MAP()

// CCreateCImageView construction/destruction

CCreateCImageView::CCreateCImageView()
{
	// TODO: add construction code here

}

CCreateCImageView::~CCreateCImageView()
{
}

BOOL CCreateCImageView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCreateCImageView drawing

void CCreateCImageView::OnDraw(CDC* pDC)
{
	CCreateCImageDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CCreateCImageView printing

BOOL CCreateCImageView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCreateCImageView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCreateCImageView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCreateCImageView diagnostics

#ifdef _DEBUG
void CCreateCImageView::AssertValid() const
{
	CView::AssertValid();
}

void CCreateCImageView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCreateCImageDoc* CCreateCImageView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCreateCImageDoc)));
	return (CCreateCImageDoc*)m_pDocument;
}
#endif //_DEBUG


// CCreateCImageView message handlers

void CCreateCImageView::Ontest()
{
	// TODO: Add your command handler code here
	CString filter;
	filter="Tiff|*.tif";
	CString Strfilename;
	Strfilename="openfile";
	CFileDialog fdlg(true,NULL,Strfilename.GetBuffer(0) ,NULL,filter.GetBuffer(0));
	if(fdlg.DoModal()==IDOK)
	{
		Strfilename=fdlg.GetPathName();
	}
	m_Image.Load( Strfilename.GetBuffer(0));
	CClientDC dc1(this);
	m_Image.Draw(dc1.m_hDC,0,0);   
	//Invalidate(); // 强制调用OnDraw
	
}
