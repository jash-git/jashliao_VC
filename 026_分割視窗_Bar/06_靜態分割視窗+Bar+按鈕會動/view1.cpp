// view1.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "view1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// view1

IMPLEMENT_DYNCREATE(view1, CView)

view1::view1()
{
}

view1::~view1()
{
}


BEGIN_MESSAGE_MAP(view1, CView)
	//{{AFX_MSG_MAP(view1)
	ON_COMMAND(ID_bar, Onbar)
	ON_COMMAND(ID_show, Onshow)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// view1 drawing

void view1::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// view1 diagnostics

#ifdef _DEBUG
void view1::AssertValid() const
{
	CView::AssertValid();
}

void view1::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// view1 message handlers

void view1::Onbar() 
{
	// TODO: Add your command handler code here
bar1.show(); 	
}

void view1::Onshow() 
{
	// TODO: Add your command handler code here
	bar1.showdata(10,20);  
}

void view1::OnButton2() 
{
	// TODO: Add your control notification handler code here
	MessageBox("test");
}
