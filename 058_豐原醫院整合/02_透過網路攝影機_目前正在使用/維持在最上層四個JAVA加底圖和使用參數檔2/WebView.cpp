// WebView.cpp : implementation of the CWebView class
//

#include "stdafx.h"
#include "Web.h"

#include "WebDoc.h"
#include "WebView.h"
#include "ExternalVar.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int intChangCount=0;
/////////////////////////////////////////////////////////////////////////////
// CWebView

IMPLEMENT_DYNCREATE(CWebView, CHtmlView)

BEGIN_MESSAGE_MAP(CWebView, CHtmlView)
	//{{AFX_MSG_MAP(CWebView)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CHtmlView::OnFilePrint)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWebView construction/destruction

CWebView::CWebView()
{
	// TODO: add construction code here

}

CWebView::~CWebView()
{
}

BOOL CWebView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWebView drawing

void CWebView::OnDraw(CDC* pDC)
{
	CWebDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CWebView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	// TODO: This code navigates to a popular spot on the web.
	//  change the code to go where you'd like.
	TCHAR strCurDrt[500];
	int nLen = ::GetCurrentDirectory(500,strCurDrt);//取得目前程式路徑
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}
	CString strFileName = strCurDrt;
	strFileName += "test.html";
	Navigate2(strFileName,NULL,NULL);
	SetTimer(1,180000,NULL);
}

/////////////////////////////////////////////////////////////////////////////
// CWebView printing


/////////////////////////////////////////////////////////////////////////////
// CWebView diagnostics

#ifdef _DEBUG
void CWebView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CWebView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CWebDoc* CWebView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWebDoc)));
	return (CWebDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWebView message handlers

void CWebView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	TCHAR strCurDrt[500];
	int nLen = ::GetCurrentDirectory(500,strCurDrt);//取得目前程式路徑
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}
	CTime time = CTime::GetCurrentTime();
	int m_nHour = time.GetHour();      ///時
	CString strFileName = strCurDrt;
	m_StartTime=intStartTime;
	m_EndTime=intEndTime;
	if(m_nHour>=m_StartTime && m_nHour<=m_EndTime)
	{
		if(intChangCount)
		{
			strFileName += "test.html";
			intChangCount=0;
		}
		else
		{
			strFileName += "blank.html";
			intChangCount++;
		}
	}
	else
	{
		strFileName += "blank.html";
	}
	Navigate2(strFileName,NULL,NULL);	
	CHtmlView::OnTimer(nIDEvent);
}
