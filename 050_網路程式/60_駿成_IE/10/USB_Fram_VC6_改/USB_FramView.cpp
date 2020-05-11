// USB_FramView.cpp : implementation of the CUSB_FramView class
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
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
TCHAR gstrCurDrt[500];//存放目前目錄字串
CString gStrLocalFile;//URL
CString gStrDisDriver;
/////////////////////////////////////////////////////////////////////////////
// CUSB_FramView

IMPLEMENT_DYNCREATE(CUSB_FramView, CHtmlView)

BEGIN_MESSAGE_MAP(CUSB_FramView, CHtmlView)
	//{{AFX_MSG_MAP(CUSB_FramView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUSB_FramView construction/destruction

CUSB_FramView::CUSB_FramView()
{
	// TODO: add construction code here

}

CUSB_FramView::~CUSB_FramView()
{
}

BOOL CUSB_FramView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style ^= WS_VSCROLL;//hide the scrollbar(s) 
	return CHtmlView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CUSB_FramView drawing

void CUSB_FramView::OnDraw(CDC* pDC)
{
	CUSB_FramDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CUSB_FramView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	// TODO: This code navigates to a popular spot on the web.
	//  change the code to go where you'd like.
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
	//Navigate2(gStrLocalFile.GetBuffer(0),NULL,NULL);
}

/////////////////////////////////////////////////////////////////////////////
// CUSB_FramView diagnostics

#ifdef _DEBUG
void CUSB_FramView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CUSB_FramView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CUSB_FramDoc* CUSB_FramView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUSB_FramDoc)));
	return (CUSB_FramDoc*)m_pDocument;
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
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUSB_FramView message handlers

void CUSB_FramView::OnNavigateComplete2(LPCTSTR strURL) 
{
	// TODO: Add your specialized code here and/or call the base class
	///*
    CComPtr<IDispatch>   spDisp   =   GetHtmlDocument(); 
    if(spDisp!=NULL)  
    { 
        CComPtr<IHTMLDocument2> doc;
        spDisp->QueryInterface(IID_IHTMLDocument2, reinterpret_cast<void**>(&doc));
        if(doc != NULL)
        {   
            IHTMLWindow2 * pIhtmlwindow2 = NULL;
            doc->get_parentWindow(&pIhtmlwindow2);
            if(pIhtmlwindow2 != NULL)
            {
				//"function fnOnError(msg,url,lineno){alert('script error:\\n\\nURL:'+url+'\\n\\nMSG:'+msg +'\\n\\nLine:'+lineno);return true;}window.onerror=fnOnError;";
                //遮罩javascript腳本錯誤的javascript腳本
                CString strJavaScriptCode ="function fnOnError(){return true;}window.onerror=fnOnError;";
                BSTR bstrScript = strJavaScriptCode.AllocSysString();
                CString strLanguage("JavaScript");
                BSTR bstrLanguage = strLanguage.AllocSysString();
                long lTime =1*1000;
                long lTimeID =0;
                VARIANT varLanguage;
                varLanguage.vt = VT_BSTR;
                varLanguage.bstrVal = bstrLanguage;
                VARIANT pRet;
                //把window.onerror函數插入入當前頁面中去
                pIhtmlwindow2->execScript(bstrScript, bstrLanguage, &pRet);
                ::SysFreeString(bstrScript);
                ::SysFreeString(bstrLanguage);
                pIhtmlwindow2->Release();
            }
        }
    }
	//*/
	CHtmlView::OnNavigateComplete2(strURL);
}
HRESULT CUSB_FramView::OnGetHostInfo(DOCHOSTUIINFO *pInfo)
{
pInfo->dwFlags |= DOCHOSTUIFLAG_SCROLL_NO | DOCHOSTUIFLAG_NO3DBORDER;
return S_OK;
}
