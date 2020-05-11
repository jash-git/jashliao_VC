
// USB_FramView.cpp : CUSB_FramView 類別的實作
//

#include "stdafx.h"
#include "USB_Fram.h"

#include "USB_FramDoc.h"
#include "USB_FramView.h"
#include "StrXorEncoder.h"
#include "MainFrm.h"
#include <Wininet.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

TCHAR gstrCurDrt[500];//存放目前目錄字串
CString gStrLocalFile;//URL
CString gStrDisDriver;
/////////////////////////////////////////////////////////////////////////////
// CUSB_FramView

IMPLEMENT_DYNCREATE(CUSB_FramView, CHtmlView)

BEGIN_MESSAGE_MAP(CUSB_FramView, CHtmlView)
END_MESSAGE_MAP()

// CUSB_FramView 建構/解構

CUSB_FramView::CUSB_FramView()
{
	// TODO: 在此加入建構程式碼

}

CUSB_FramView::~CUSB_FramView()
{
}

BOOL CUSB_FramView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CHtmlView::PreCreateWindow(cs);
}

void CUSB_FramView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	FILE *pf='\0';
	CStrXorEncoder CSXE;
	int j,data;
	j=0;
	data=-1;
	pf=fopen("url.txt","r");
	while(fscanf(pf,"%d,",&data)!=EOF)
	{
		CSXE.intDecoder[j]=data;
		j++;
	}
	fclose(pf);
	CSXE.XorDecoder(j);
	gStrLocalFile=CSXE.chrDecoder;
	bool checkin=false;
	checkin=CheckInternet(gStrLocalFile);
	DisDriver();
	int intHW=1;
	//if(gStrDisDriver=="硬碟")
	if(intHW==1)
	{
		if(checkin)
		{
			ModifyStyle(WS_VSCROLL,0);// hide the scrollbar(s)
			ShowScrollBar(SB_VERT,false);// hide the scrollbar(s)
			CScrollBar* pSB=AfxGetMainWnd()->GetScrollBarCtrl(SB_VERT);// hide the scrollbar(s)
			SetSilent(TRUE);
			Navigate2(gStrLocalFile, 0, NULL);
		}
		else
		{
			MessageBox("The Internet connection fails, please check the status of the primary network");
			CMainFrame *f1=(CMainFrame *)AfxGetMainWnd();
			f1->PostMessage(WM_CLOSE);//關閉程式
		}
	}
	else
	{
		//MessageBox("親愛的用戶你好，您可能已變成非法使用者，請儘快與原廠連絡保障自身權益。");
		CMainFrame *f2=(CMainFrame *)AfxGetMainWnd();
		f2->PostMessage(WM_CLOSE);//關閉程式
	}
}

BOOL CUSB_FramView::CheckInternet(LPCTSTR URL)
{
	// TODO: Add your dispatch handler code here
	DWORD dwFlags;
	dwFlags=0;
	if(InternetCheckConnection(URL,FLAG_ICC_FORCE_CONNECTION,dwFlags))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void CUSB_FramView::DisDriver()
{
	CString strResult,strRootPathName;
	strRootPathName=gstrCurDrt;
	strRootPathName=strRootPathName.Mid(0,3);
	UINT DrvType = GetDriveType(strRootPathName);
	switch(DrvType)
	{
	case DRIVE_CDROM:
		strResult = "光碟";
		break;
	case DRIVE_FIXED:
		strResult = "硬碟";
		break;
	case DRIVE_REMOVABLE:
		strResult = "磁片/USB";
		break;
	default:
		return;
		break;
	}
	gStrDisDriver=strResult;
	//MessageBox(strResult);
}
HRESULT CUSB_FramView::OnGetHostInfo(DOCHOSTUIINFO *pInfo)
{
	pInfo->dwFlags |= DOCHOSTUIFLAG_SCROLL_NO | DOCHOSTUIFLAG_NO3DBORDER;
	return S_OK;
}
// CUSB_FramView 診斷

#ifdef _DEBUG
void CUSB_FramView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CUSB_FramView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CUSB_FramDoc* CUSB_FramView::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUSB_FramDoc)));
	return (CUSB_FramDoc*)m_pDocument;
}
#endif //_DEBUG


// CUSB_FramView 訊息處理常式
