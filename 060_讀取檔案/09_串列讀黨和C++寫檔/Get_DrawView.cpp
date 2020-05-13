// Get_DrawView.cpp : implementation of the CGet_DrawView class
//

#include "stdafx.h"
#include "Get_Draw.h"
#include "ToolPath.h"
#include "Get_DrawDoc.h"
#include "Get_DrawView.h"
#include<fstream.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGet_DrawView

IMPLEMENT_DYNCREATE(CGet_DrawView, CView)

BEGIN_MESSAGE_MAP(CGet_DrawView, CView)
	//{{AFX_MSG_MAP(CGet_DrawView)
	ON_COMMAND(ID_test, Ontest)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGet_DrawView construction/destruction

CGet_DrawView::CGet_DrawView()
{
	// TODO: add construction code here

}

CGet_DrawView::~CGet_DrawView()
{
}

BOOL CGet_DrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGet_DrawView drawing

void CGet_DrawView::OnDraw(CDC* pDC)
{
	CGet_DrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CGet_DrawView printing

BOOL CGet_DrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGet_DrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGet_DrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGet_DrawView diagnostics

#ifdef _DEBUG
void CGet_DrawView::AssertValid() const
{
	CView::AssertValid();
}

void CGet_DrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGet_DrawDoc* CGet_DrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGet_DrawDoc)));
	return (CGet_DrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGet_DrawView message handlers

void CGet_DrawView::Ontest() 
{
	// TODO: Add your command handler code here
	int i=0,j=0;
	CFile file;
	CPen *pen1;
    CFileException fe;
	fstream a;
	int x1,x2;
	x1=0;
	x2=0;
	char* pFileName = "BData.jas";
	CObArray ListOfWTool;
	CClientDC dc(this);
	a.open("Line.txt",ios::out|ios::trunc);
    if(!file.Open(pFileName,CFile::modeRead,&fe))
    {
		fe.ReportError();
        return;
    }
	CArchive arc(&file, CArchive::load);
	ListOfWTool.Serialize(arc); 
	int num=ListOfWTool.GetSize(); 
	for(i=0;i<num;i++)
	{
		switch (i%3)
		{
			case 0:
				pen1=new CPen(PS_SOLID,1,RGB(255,0,0));
				break;
			case 1:
				pen1=new CPen(PS_SOLID,1,RGB(0,255,0));
				break;
			case 2:
				pen1=new CPen(PS_SOLID,1,RGB(0,0,255));
				break;
		}
		dc.SelectObject(pen1); 
		CToolPath *d=(CToolPath *)(ListOfWTool[i]);
		dc.MoveTo(d->m_CPStart);
		dc.LineTo(d->m_CPEnd);
		a <<d->m_CPStart.x <<"\t"<<d->m_CPStart.y <<"\t";
		a <<d->m_CPEnd.x <<"\t"<<d->m_CPEnd.y <<"\n";
		Sleep(1);
	}
	arc.Flush();
    arc.Close();
    file.Close();
	MessageBox("ok");
}
