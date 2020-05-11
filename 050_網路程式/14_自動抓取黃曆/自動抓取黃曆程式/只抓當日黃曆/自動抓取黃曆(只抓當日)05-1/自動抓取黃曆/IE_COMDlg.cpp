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
int intHttpSiteAll=11;
COleVariant datavaUrl[10];
COleVariant vaUrl01;
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
	CString StrUrl;
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
	if(Month<10)
	{
		Strdata2=chrdata2;
		Strdata2="0"+Strdata2;
	}
	else
	{
		Strdata2=chrdata2;
	}
	if(Day<10)
	{
		Strdata3=chrdata3;
		Strdata3="0"+Strdata3;
	}
	else
	{
		Strdata3=chrdata3;
	}
	StrUrl="http://lunar.anet.net.tw/index.jsp?year=";
	StrUrl=StrUrl+Strdata1;
	StrUrl=StrUrl+"&mmdd=";
	StrUrl=StrUrl+Strdata2+Strdata3;
	//Strdata=Strdata1+Strdata2+Strdata3+".html";
	vaUrl01=StrUrl;
	COleVariant vtMissing;
	m_ctrlWeb.Navigate2(&vaUrl01,&vtMissing,&vtMissing,&vtMissing,&vtMissing);
	/*
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
	*/
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
	GetSaveMyData();
	/*
	////////////////////////////////////////
	if(strUrl=="http://office.tw-airnet.net/office/airnet_office_big5/webroot/emp_data/emp_online_log.php") 
	{
		CComPtr<IDispatch>pDisp;
		if(HasItem(objAllElement,"form_login")==true) //voteform為投票選項所在的Form
		{
			objAllElement->item(COleVariant("form_login"),COleVariant((long)0),&pDisp);
			CComQIPtr<IHTMLFormElement , &IID_IHTMLFormElement >pElement; 
			if(pDisp==NULL)
			{
				//介面指標獲取失敗，結束程式，不另外作處理，原因見後
				EndDialog(IDOK);
				return;
			}
			//////////////////////////////////////////////////////
			//str[2]=GetHidText(objAllElement,"user_chknum_hid");
			char data[1024];
			long lngnum=1;
			pf=fopen("text.txt","r");
			CString Strdata="請輸入右方驗證號碼：";
			CString m_v2,m_v3;
			UpdateData(true);
			///*
			while(fscanf(pf,"%s",&data)!=EOF)
			{
				m_v2=data;
				if(m_v2==Strdata)
				{
					fscanf(pf,"%s",&data);
					fscanf(pf,"%s",&data);
					fscanf(pf,"%s",&data);
					fscanf(pf,"%s",&data);
					m_v2=data;
					m_v3=m_v2.Mid(11,4);
					str[2]=m_v3;
					break;
				}
				lngnum++;
			}
			//////////////////////////////////////////////////////
			PutIEText(objAllElement,"user_id",str[0]);
			PutIEText(objAllElement,"user_chknum",str[2]);
			PutIEText(objAllElement,"user_pass",str[1]);
			if(hr<=9)
			{
				SelectItemValue(objAllElement,"on_type",1);//上班
			}
			else if(hr>=18)
			{
				SelectItemValue(objAllElement,"on_type",2);//下班
			}
			//SelectItemValue(objAllElement,"on_type",0);//沒選
			SubmitPage(objAllElement,"submit_login"); //提交網頁，vote為submit按鈕的id或name

		}
	}
	///////////////////////////////6_end
	*/
	this->OnOK(); 
	//SetTimer(1,6000,NULL);
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
	char chra[1000];
	char *chrHtmldata;
	CString Strdata1,Strdata2,Strdata3;
	CString StrSaveData;
	int intCount_Count=0;
	int intCount_a=0;
	int intCount_b=0;
	int intCount_c=0;
	int intCount_d=0;
	int intCount_date=0;
	//CString StrDataTitle[8];
	//StrDataTitle[0]="日期 : ";
	//StrDataTitle[1]="宜 : ";
	//StrDataTitle[2]="忌 : ";
	//StrDataTitle[3]="沖 : ";
	//StrDataTitle[4]="煞 : ";
	//StrDataTitle[5]="成 : ";
	//StrDataTitle[6]="正沖 : ";
	//StrDataTitle[7]="胎神 : ";
	p=fopen("text.txt","r");
	/////////////////////////////////////////
	try
	{
	/*
	Strdata1=vaUrl01.bstrVal;
	Strdata2=Strdata1.Mid(40,4);
	Strdata3=Strdata1.Mid(51,4);
	StrSaveData=Strdata2+Strdata3;
	StrSaveData=StrSaveData+".html";
	*/
	StrSaveData="黃曆.html";
	p1=fopen(StrSaveData.GetBuffer(0) ,"w");
	chrHtmldata="<html>";
	fprintf(p1,"%s\n",chrHtmldata);
	chrHtmldata="<head>";
	fprintf(p1,"%s\n",chrHtmldata);
	chrHtmldata="<title>data</title>";
	fprintf(p1,"%s\n",chrHtmldata);
	chrHtmldata="<meta http-equiv=\"Content-Type\" content=\"text/html\; charset=big5\"><style type=\"text/css\"><!--body {margin-left: 0px\;margin-top: 0px\;margin-right: 0px\;margin-bottom: 0px\;}--></style>";
	fprintf(p1,"%s\n",chrHtmldata);
	chrHtmldata="</head>";
	fprintf(p1,"%s\n",chrHtmldata);
	chrHtmldata="<body>";
	fprintf(p1,"%s\n",chrHtmldata);
	chrHtmldata="<table width=\"256\" height=\"471\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">";
	fprintf(p1,"%s\n",chrHtmldata);
	chrHtmldata="<tr>";
	fprintf(p1,"%s\n",chrHtmldata);
	chrHtmldata="<td background=\"images/bg.jpg\"><table width=\"256\" height=\"471\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">";
	fprintf(p1,"%s\n",chrHtmldata);
	chrHtmldata="<tr><td width=\"63\" height=\"73\"></td><td width=\"193\"></td></tr>";
	fprintf(p1,"%s\n",chrHtmldata);
	}
	catch(const char *str)
	{
		MessageBox("GET");
	}
	///////////////////////////////////////////
	CString data="";
	CString StrSave1="";
	CString StrSave2="";
	CString StrCheck="class=c2";
	CString StrCheckDate="width=315><SPAN";
	while(fscanf(p,"%s",chra)!=EOF)
	{
		intCount_a++;
		data=chra;
		if(intCount_b!=0)
			intCount_c++;
		if(intCount_c!=0)
		{
			if(intCount_date!=101)
			{
				StrSave1=data.Mid(16); 
				switch(intCount_d)
				{
					case 1:
						StrSave2="<tr><td height=\"65\"></td>";
						break;
					case 2:
						StrSave2="<tr><td height=\"61\"></td>";
						break;
					case 3:
						StrSave2="<tr><td height=\"50\"></td>";
						break;
					case 4:
						StrSave2="<tr><td height=\"47\"></td>";
						break;
					case 5:
						StrSave2="<tr><td height=\"46\"></td>";
						break;
					case 6:
						StrSave2="<tr><td height=\"41\"></td>";
						break;
					case 7:
						StrSave2="<tr><td></td>";
						break;
				}
				StrSave2=StrSave2+"<td><b><font color=\"#FF0000\" face=\"標楷體\" size=\"4\">";
				StrSave2=StrSave2+StrSave1.Mid(0,(StrSave1.GetLength()-36));
				//StrSave2=StrDataTitle[intCount_d]+StrSave2;
				StrSave2=StrSave2+"</b></td></tr>";
				fprintf(p1,"%s\n",StrSave2.GetBuffer(0));
				intCount_c=0;
				intCount_b=0;
				intCount_d++;
			}
			else
			{
				StrSave1="<tr><td height=\"36\"></td>";
				StrSave1=StrSave1+"<td><b><font color=\"#FF0000\" face=\"標楷體\" size=\"4\">";
				StrSave1=StrSave1+data.Mid(8);
				//StrSave1=StrDataTitle[intCount_d]+StrSave1;
				StrSave1=StrSave1+"</b></td></tr>";
				fprintf(p1,"%s\n",StrSave1.GetBuffer(0));
				intCount_c=0;
				intCount_b=0;
				intCount_d++;
				intCount_date=0;
			}
		}
		if(data==StrCheckDate)
		{
			intCount_b=intCount_a;
			intCount_date=101;
		}
		if(data==StrCheck)
		{
			intCount_Count++;
			if(intCount_Count<=7)
			{
				intCount_b=intCount_a;
			}
			else
			{
				break;
			}
		}
	}
	chrHtmldata="</table></td></tr></table>";
	fprintf(p1,"%s\n",chrHtmldata);
	chrHtmldata="</body>";
	fprintf(p1,"%s\n",chrHtmldata);
	chrHtmldata="</html>";
	fprintf(p1,"%s\n",chrHtmldata);
	fclose(p);
	fclose(p1);	

}
void CIE_COMDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(1);
	COleVariant vtMissing;
	if(intHttpSiteCount<10)
	{
		m_ctrlWeb.Navigate2((datavaUrl+intHttpSiteCount),&vtMissing,&vtMissing,&vtMissing,&vtMissing);
	}
	else
	{
		MessageBox("GET ALL");
		this->OnOK();
	}
	intHttpSiteCount++;
	CDialog::OnTimer(nIDEvent);
}
