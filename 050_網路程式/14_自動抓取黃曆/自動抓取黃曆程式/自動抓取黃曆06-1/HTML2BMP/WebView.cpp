// WebView.cpp : implementation of the CWebView class
//

#include "stdafx.h"
#include "Web.h"

#include "WebDoc.h"
#include "WebView.h"
#include "ExternalVar.h"
#include "DibSection.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
	CTime t1=CTime::GetCurrentTime(); 
	int Year=t1.GetYear(); 
	int Month=t1.GetMonth(); //月
	int Day=t1.GetDay();//日
	CString Strdata,Strdata1,Strdata2,Strdata3;
	char chrdata1[20];
	char chrdata2[20];
	char chrdata3[20];
	itoa(Year,chrdata1,10);
	itoa(Month,chrdata2,10);
	itoa(Day,chrdata3,10);
	Strdata1=chrdata1;
	Strdata2=chrdata2;
	if(Day<10)
	{
		Strdata3=chrdata3;
		Strdata3="0"+Strdata3;
	}
	else
	{
		Strdata3=chrdata3;
	}
	Strdata=Strdata1+Strdata2+Strdata3+".html";
	strFileName += Strdata;
	Navigate2(strFileName,NULL,NULL);
	SetTimer(1,600,NULL);
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
	KillTimer(1);
	CDibSection Dib;
	CClientDC dc(this);
	int x,y;
	int Width,Height;
	Dib.Create(256,663,24);
	Width=Dib.Width();
	Height=Dib.Height();
	for(x=Width-1;x>=0;x--)
		for(y=Height-1;y>=0;y--)
		{
			BYTE *q1=(BYTE *)Dib.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			//BYTE *q=(BYTE *)testDib.GetBits(x,Height-1-y);
			//要轉換就要R,G,B一起轉
			COLORREF c1=dc.GetPixel(x,y);
			*q1++=GetBValue(c1);
			*q1++=GetGValue(c1);
			*q1++=GetRValue(c1);
		}
	CTime t1=CTime::GetCurrentTime(); 
	int Year=t1.GetYear(); 
	int Month=t1.GetMonth(); //月
	int Day=t1.GetDay();//日
	CString Strdata,Strdata1,Strdata2,Strdata3;
	char chrdata1[20];
	char chrdata2[20];
	char chrdata3[20];
	itoa(Year,chrdata1,10);
	itoa(Month,chrdata2,10);
	itoa(Day,chrdata3,10);
	Strdata1=chrdata1;
	Strdata2=chrdata2;
	Strdata3=chrdata3;
	Strdata3+="黃曆663";
	Strdata=Strdata1+Strdata2+Strdata3+".bmp";
	Strdata="C:\\"+Strdata;
	Dib.SaveBmp(Strdata);
}
