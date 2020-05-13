// FrameMediaView.cpp : implementation of the CFrameMediaView class
//

#include "stdafx.h"
#include "FrameMedia.h"

#include "FrameMediaDoc.h"
#include "FrameMediaView.h"
#include "wmpcontrols.h"
#include "wmpmedia.h"
#include "wmpplaylist.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
bool blnloop=false;
/////////////////////////////////////////////////////////////////////////////
// CFrameMediaView

IMPLEMENT_DYNCREATE(CFrameMediaView, CFormView)

BEGIN_MESSAGE_MAP(CFrameMediaView, CFormView)
	//{{AFX_MSG_MAP(CFrameMediaView)
	ON_COMMAND(ID_test, Ontest)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrameMediaView construction/destruction

CFrameMediaView::CFrameMediaView()
	: CFormView(CFrameMediaView::IDD)
{
	//{{AFX_DATA_INIT(CFrameMediaView)
	m_v3 = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CFrameMediaView::~CFrameMediaView()
{
}

void CFrameMediaView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrameMediaView)
	DDX_Control(pDX, IDC_OCX1, m_WMP);
	DDX_Text(pDX, IDC_EDIT1, m_v3);
	//}}AFX_DATA_MAP
}

BOOL CFrameMediaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CFrameMediaView::OnInitialUpdate()
{
	int i;
	CWMPMedia newMedia1;
	CString data[3];
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	m_WMP.SetUrl("C:\\"); 
	CWMPPlaylist curPlaylist = m_WMP.GetCurrentPlaylist();
	data[0]="D:\\Media\\000 Pioneer-HDTV Demo-Video-1920 x 1080.avi";
	data[1]="D:\\Media\\20080219 National Geographic_1.wmv";
	data[2]="D:\\Media\\aa2009.mpg";
	for(i=0;i<3;i++)
	{
		newMedia1=m_WMP.newMedia(data[i]);
		curPlaylist.insertItem(i,newMedia1.m_lpDispatch);
	}
	m_WMP.SetCurrentPlaylist(curPlaylist);
	m_WMP.GetControls().play();	
	blnloop=true;

}

/////////////////////////////////////////////////////////////////////////////
// CFrameMediaView printing

BOOL CFrameMediaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFrameMediaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFrameMediaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CFrameMediaView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CFrameMediaView diagnostics

#ifdef _DEBUG
void CFrameMediaView::AssertValid() const
{
	CFormView::AssertValid();
}

void CFrameMediaView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CFrameMediaDoc* CFrameMediaView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFrameMediaDoc)));
	return (CFrameMediaDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFrameMediaView message handlers

void CFrameMediaView::Ontest() 
{
	// TODO: Add your command handler code here

}
