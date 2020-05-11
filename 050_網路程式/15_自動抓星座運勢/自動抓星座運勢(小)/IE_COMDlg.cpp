// IE_COMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "IE_COM.h"
#include "IE_COMDlg.h"
#include<fstream.h>//7
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int intHttpSiteCount=0;
int intHttpSiteAll=13;
COleVariant datavaUrl[12];
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIE_COMDlg dialog

CIE_COMDlg::CIE_COMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIE_COMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIE_COMDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIE_COMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIE_COMDlg)
	DDX_Control(pDX, IDC_EXPLORER1, m_ctrlWeb);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CIE_COMDlg, CDialog)
	//{{AFX_MSG_MAP(CIE_COMDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIE_COMDlg message handlers

BOOL CIE_COMDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	///////////4_start
	//COleVariant vaUrl="http://lunar.anet.net.tw/index.jsp?year=2007&mmdd=0821";
	//COleVariant vtMissing;
	//m_ctrlWeb.Navigate2(&vaUrl,&vtMissing,&vtMissing,&vtMissing,&vtMissing);
	FILE *p;
	char chra[1000];
	int intcount=0;
	p=fopen("httpdata.txt","r");
	while(fscanf(p,"%s",chra)!=EOF)
	{
		datavaUrl[intcount]=chra;
		intcount++;
	}
	intHttpSiteCount=0;
	SetTimer(1,600,NULL);
	///////////4_end
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CIE_COMDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CIE_COMDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CIE_COMDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BEGIN_EVENTSINK_MAP(CIE_COMDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CIE_COMDlg)
	ON_EVENT(CIE_COMDlg, IDC_EXPLORER1, 104 /* DownloadComplete */, OnDownloadCompleteExplorer1, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CIE_COMDlg::OnDownloadCompleteExplorer1()////3 
{
	// TODO: Add your control notification handler code here
	////////////////////////6_start
	FILE *pf;
	fstream a;
	CString str[3];
	//str[0]="jashliao";
	//str[1]="b700502";
	int hr,min;
	hr=0;
	min=0;
	CTime t1=CTime::GetCurrentTime();
	hr=t1.GetHour();
	min=t1.GetMinute();
	//min=min+(hr*60);
///*
	char str1[12];
	int i=0;
	a.open("帳號.txt",ios::in);
	while(!a.eof())
	{
		a>>str1;
		str[i]=str1;
		i++;
	}
//*/
	IHTMLElementCollection *objAllElement=NULL;
	IHTMLDocument2 *objDocument=NULL;
	CString strUrl,strTemp;
	strUrl=m_ctrlWeb.GetLocationURL();//得到當前網頁的URL
	if(strUrl.IsEmpty())
		return;
	objDocument=(IHTMLDocument2 *)m_ctrlWeb.GetDocument(); //由控制項得到IHTMLDocument2介面指標
	objDocument->get_all(&objAllElement); //得到網頁所有元素的集合
	//由於所有頁面下載完後都會執行這個函數，所以必須根據URL判斷消息來源網頁
	////////////////////////////////////
	IHTMLElement  *HTMLElement=NULL;
	objDocument->get_body(&HTMLElement);
	pf=fopen("text.txt","w");
	CString StrHTML;
	BSTR pdata;
	HTMLElement->get_outerHTML(&pdata);  
	StrHTML=pdata;
	fprintf(pf,"%s",StrHTML.GetBuffer(0)); 
	fclose(pf);
	///////////////////////////////////////////////
	char data[1024];
	CString Strdata;
	CString Strcheck;
	int intcount=0;
	Strcheck="class=mbody";
	pf=fopen("text.txt","r");
	FILE *pf1;
	pf1=fopen("data.txt","w");
	while(fscanf(pf,"%s",&data)!=EOF)
	{
		Strdata=data;
		if(intcount!=0)
		{
			fprintf(pf1,"%s\n",Strdata.GetBuffer(0));
			intcount=0;
		}
		if(Strdata==Strcheck)
		{
			intcount++;
		}
	}
	fclose(pf);
	fclose(pf1);
	GetSaveMyData();
	SetTimer(1,6000,NULL);

}
///////////////////////////5_start
bool CIE_COMDlg::HasItem(IHTMLElementCollection *pobjAllElement,CString strName)
{
	CComPtr<IDispatch>pDisp;
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp);
	if(pDisp==NULL)
		return false;
	else 
		return true; 
}
void CIE_COMDlg::PutIEText(IHTMLElementCollection *pobjAllElement,CString strName,CString strText)
{
	CComPtr<IDispatch> pDisp; 
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp); 
	CComQIPtr<IHTMLInputTextElement,&IID_IHTMLInputTextElement>pElement; 
	if(pDisp==NULL)
	{
		MessageBox(strName + "沒有找到!"); 
	}
	else
	{
		pElement=pDisp; 
		pElement->put_value(strText.AllocSysString()); 
	}
} 
void CIE_COMDlg::SubmitPage(IHTMLElementCollection *pobjAllElement,CString strName)
{
	CComPtr<IDispatch> pDisp; 
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp); 
	CComQIPtr<IHTMLElement, &IID_IHTMLElement>pElement; 
	if(pDisp==NULL)
	{
		AfxMessageBox(strName + "沒有找到!"); 
	}
	else
	{
		pElement=pDisp;
		pElement->click();
	}
} 
void CIE_COMDlg::CheckItem(IHTMLElementCollection *pobjAllElement,CString strName)
{
	CComPtr<IDispatch> pDisp;
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp);
	CComQIPtr<IHTMLElement, &IID_IHTMLElement>pElement;
	if(pDisp==NULL)
	{
		AfxMessageBox(strName + "沒有找到!");
	}
	else
	{
		pElement=pDisp;
		pElement->click();
	}
}
CString CIE_COMDlg::GetHidText(IHTMLElementCollection *pobjAllElement,CString strName)
{
	_bstr_t   bstText;   
	BSTR   bsText;
	CString str;
	CComPtr<IDispatch> pDisp;
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp);
	CComQIPtr < IHTMLInputHiddenElement,&IID_IHTMLInputHiddenElement > pElement;
	if(pDisp==NULL)
	{
		AfxMessageBox(strName + "沒有找到!");
	}
	else
	{
		pElement=pDisp;
		pElement->get_value(&bsText);
		bstText=bsText;
		str=(LPCSTR)bstText;
	}
	return   str; 
}
void CIE_COMDlg::SelectItemValue(IHTMLElementCollection *pobjAllElement,CString strName,long number)
{
	CComPtr<IDispatch> pDisp;
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp);
	CComQIPtr < IHTMLSelectElement,&IID_IHTMLSelectElement > pElement;
	if(pDisp==NULL)
	{
		AfxMessageBox(strName + "沒有找到!");
	}
	else
	{
		pElement=pDisp;
		pElement->put_selectedIndex(number);
	}
}
/////////////////////////5_end
void CIE_COMDlg::GetSaveMyData(void)
{
	FILE *p;
	FILE *p1;
	int intcount=0;
	int i,j;
	char chrBuf[1000];
	CString StrBuf[4];
	CString StrBuf_1[4];
	CString StrData[4];
	CString StrHtmlData;
	p=fopen("data.txt","r");
	i=0;
	j=0;
	while(fscanf(p,"%s",&chrBuf)!=EOF)
	{
		intcount++;
		if((intcount%2)==0)
		{
			if(intcount<9)
			{
				StrBuf[i]=chrBuf;
				i++;
			}
		}
	}
	fclose(p);
	for(j=0;j<4;j++)
	{
		StrBuf_1[j]=StrBuf[j].Mid(11);
		StrData[j]=StrBuf_1[j].Mid(0,(StrBuf_1[j].GetLength()-5));  
	}
	switch(intHttpSiteCount)
	{
		case 1:
			p1=fopen("01.html","w");
			StrHtmlData="<tr><td background=\"01.jpg\">";
			break;
		case 2:
			p1=fopen("02.html","w");
			StrHtmlData="<tr><td background=\"02.jpg\">";
			break;
		case 3:
			p1=fopen("03.html","w");
			StrHtmlData="<tr><td background=\"03.jpg\">";
			break;
		case 4:
			p1=fopen("04.html","w");
			StrHtmlData="<tr><td background=\"04.jpg\">";
			break;
		case 5:
			p1=fopen("05.html","w");
			StrHtmlData="<tr><td background=\"05.jpg\">";
			break;
		case 6:
			p1=fopen("06.html","w");
			StrHtmlData="<tr><td background=\"06.jpg\">";
			break;
		case 7:
			p1=fopen("07.html","w");
			StrHtmlData="<tr><td background=\"07.jpg\">";
			break;
		case 8:
			p1=fopen("08.html","w");
			StrHtmlData="<tr><td background=\"08.jpg\">";
			break;
		case 9:
			p1=fopen("09.html","w");
			StrHtmlData="<tr><td background=\"09.jpg\">";
			break;
		case 10:
			p1=fopen("10.html","w");
			StrHtmlData="<tr><td background=\"10.jpg\">";
			break;
		case 11:
			p1=fopen("11.html","w");
			StrHtmlData="<tr><td background=\"11.jpg\">";
			break;
		case 12:
			p1=fopen("12.html","w");
			StrHtmlData="<tr><td background=\"12.jpg\">";
			break;
	}
	CString StrWrite;
	StrWrite="<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=big5\" /><title>無標題文件</title>";
	fprintf(p1,"%s\n",StrWrite.GetBuffer(0));
	StrWrite="<style type=\"text/css\">";
	fprintf(p1,"%s\n",StrWrite.GetBuffer(0));
	StrWrite="<!--body {margin-left: 0px\;margin-top: 0px\;margin-right: 0px\;margin-bottom: 0px\;}-->";
	fprintf(p1,"%s\n",StrWrite.GetBuffer(0));
	StrWrite="</style></head><body>";
	fprintf(p1,"%s\n",StrWrite.GetBuffer(0));
	StrWrite="<table width=\"256\" height=\"471\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">";
	fprintf(p1,"%s\n",StrWrite.GetBuffer(0));
	//////////////////////////////////////////////
	fprintf(p1,"%s\n",StrHtmlData.GetBuffer(0));
	//////////////////////////////////////////////
	StrWrite="<table width=\"256\" height=\"471\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\"><tr><td width=\"64\" height=\"120\"></td><td width=\"182\" height=\"135\"></td></tr>";
	fprintf(p1,"%s\n",StrWrite.GetBuffer(0));
	////////////////////////////////////////////////////////////////////////
	StrWrite="<tr><td height=\"67\"></td><td height=\"65\" valign=\"top\"><b><font face=\"標楷體\" size=\"4\" color=\"#535353\">";
	StrWrite=StrWrite+StrData[0];
	StrWrite=StrWrite+"</font></b></td></tr>";
	fprintf(p1,"%s\n",StrWrite.GetBuffer(0));
	////////////////////////////////////////////////////////////////////////
	StrWrite="<tr><td height=\"71\"></td><td height=\"80\" valign=\"top\"><b><font face=\"標楷體\" size=\"4\" color=\"#535353\">";
	StrWrite=StrWrite+StrData[1];
	StrWrite=StrWrite+"</font></b></td></tr>";
	fprintf(p1,"%s\n",StrWrite.GetBuffer(0));
	////////////////////////////////////////////////////////////////////////
	StrWrite="<tr><td height=\"76\"></td><td height=\"76\" valign=\"top\"><b><font face=\"標楷體\" size=\"4\" color=\"#535353\">";
	StrWrite=StrWrite+StrData[2];
	StrWrite=StrWrite+"</font></b></td></tr>";
	fprintf(p1,"%s\n",StrWrite.GetBuffer(0));
	////////////////////////////////////////////////////////////
	StrWrite="<tr><td height=\"113\"></td><td valign=\"top\"><b><font face=\"標楷體\" size=\"4\" color=\"#535353\">";
	StrWrite=StrWrite+StrData[3];
	StrWrite=StrWrite+"</font></b></td></tr>";
	fprintf(p1,"%s\n",StrWrite.GetBuffer(0));
	////////////////////////////////////////////////////
	StrWrite="</table></td></tr></table></body></html>";
	fprintf(p1,"%s\n",StrWrite.GetBuffer(0));
	fclose(p1);

}

void CIE_COMDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(1);
	COleVariant vtMissing;
	if(intHttpSiteCount<12)
	{
		m_ctrlWeb.Navigate2((datavaUrl+intHttpSiteCount),&vtMissing,&vtMissing,&vtMissing,&vtMissing);
	}
	else
	{
		this->OnOK();
	}
	intHttpSiteCount++;	
	CDialog::OnTimer(nIDEvent);
}
