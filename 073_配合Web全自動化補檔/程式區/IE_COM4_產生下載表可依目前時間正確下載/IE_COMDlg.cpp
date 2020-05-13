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
struct file_data
{
	int intuid;
	int intaction;
	char chrip[50];
	char chrfile_path[250];
	int intstatus;
	char chrStart_Date[50];
	char chrEnd_Date[50];
};
struct file_data fd;
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
	CTime t1=CTime::GetCurrentTime();
	CString StrData1,StrData2,StrData3;
	StrData1="http://eipflow.chtv.com.tw/module/resupply_media_file.php?";
	StrData2=t1.Format("%Y-%m-%d");
	StrData2="play_start_date="+StrData2;
	StrData3=t1.Format("%Y-%m-%d");
	StrData3="&play_end_date="+StrData3;
	StrData1=StrData1+StrData2+StrData3;
	//COleVariant vaUrl="http://eipflow.chtv.com.tw/module/resupply_media_file.php?play_start_date=2008-08-24&play_end_date=2008-08-24";
	COleVariant vaUrl(StrData1);
	COleVariant vtMissing;
	m_ctrlWeb.Navigate2(&vaUrl,&vtMissing,&vtMissing,&vtMissing,&vtMissing); 
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

	char str1[12];
	int i=0;
/*
	fstream a;
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
	pf=fopen("text.xml","w");
	CString StrHTML;
	BSTR pdata;
	HTMLElement->get_outerHTML(&pdata);
	StrHTML=pdata;
	fprintf(pf,"%s",StrHTML.GetBuffer(0)); 
	fclose(pf);
	////////////////////////////////////////
	//*
	CString StrListFileName;
	FILE *pfdata,*pfwebfilelist,*pfListdata;
	StrListFileName="Log\\List_";
	StrListFileName+=t1.Format("%Y%m%d");
	StrListFileName+=".txt";
	pfListdata=fopen(StrListFileName.GetBuffer(0),"w");
	pfdata=fopen("data.txt","w");
	pfwebfilelist=fopen("webfilelist.txt","w");
	////////////////////////////////////
	CString StrIP="";
	CString StrBuf="";
	char *chrInBuf;//建立暫存輸入資料指標
	char *chrOutBuf;//建立暫存輸出分割資料指標
	long lngLen=0;//建立長度暫存變數
	long lngGetLen1=0;//提取資料長度
	long lngGetLen2=0;//剩餘資料長度
	CString m_strInData="";//主
	CString strInData="";//m_strInData分身
	CString strRemain="";//剩餘資料
	char chrSeps[]=",";//建立分割符號
	chrInBuf=new char('\0');//指標初始化
	chrOutBuf=new char('\0');//指標初始化
	bool blnLen=false;
	int intCount=0;
	//////////////////////////////01_start
	openfile("text.xml");
	count=0;
	str2array();
	for(i=0;i<count;i++)
	{
		if(node[i].name=="TD"||node[i].name=="td")
		{
			fprintf(pfdata,"%s\n",node[i].value.GetBuffer(0));
			fprintf(pfListdata,"%s\n",node[i].value.GetBuffer(0));
			///////////////////////////////////////////////////////////
			strInData=node[i].value;//取出原來資料
			m_strInData=node[i].value;;
			do
			{
				chrInBuf=strInData.GetBuffer(0);//賦予資料
				lngLen=strlen(chrInBuf);
				if(lngLen<= 0)//防堵最後一筆資料換行所造成誤判
				{
					blnLen=true;
					break;
				}
				chrOutBuf=strtok(chrInBuf,chrSeps);//擷取的資料
				intCount++;
				switch(intCount)
				{
					case 1://uid
						fd.intuid=atoi(chrOutBuf); 
						break;
					case 2://action
						fd.intaction=atoi(chrOutBuf); 
						break;
					case 3://ip
						strcpy(fd.chrip,chrOutBuf);
						break;
					case 4://file_path
						strcpy(fd.chrfile_path,chrOutBuf);
						break;
					case 5://status
						fd.intstatus=atoi(chrOutBuf); 
						break;
					case 6://Start_Data
						strcpy(fd.chrStart_Date,chrOutBuf);
						break;
					case 7://End_Date
						strcpy(fd.chrEnd_Date,chrOutBuf);
						break;
				}
				lngGetLen1=strlen(chrOutBuf);//提取資料長度
				lngGetLen2=lngLen-lngGetLen1;//剩餘資料長度
				if(intCount==1)
				{
					strRemain=m_strInData.Mid(lngGetLen1+1,lngGetLen2);//剩餘資料
				}
				else
				{
					if(lngGetLen2>0)
						strRemain=strRemain.Mid(lngGetLen1+1,lngGetLen2);//剩餘資料
				}
				strInData=strRemain;
			}while(intCount<7);
			intCount=0;
			lngLen=0;//建立長度暫存變數
			lngGetLen1=0;//提取資料長度
			lngGetLen2=0;//剩餘資料長度
			fprintf(pfwebfilelist,"%s\n",fd.chrfile_path);
			////////////////////////////////////////////////////////////
		}
	}
	//*/
	fclose(pfdata);
	fclose(pfListdata);
	fclose(pfwebfilelist);
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
	Sleep(5000);
	ShellExecute(NULL,"open","JashtestFTP.exe",NULL,NULL,SW_SHOWNORMAL);
	this->OnOK(); 	
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
 ///////////////////////////////////////////////////////////////////////////////////
//非正規XML分析
void CIE_COMDlg::openfile(CString file)
{
	char ch;
	FILE *of;
	of=fopen(file,"r");
	ch=fgetc(of);
	while(ch!=EOF)
	{
		context+=ch;
		ch=fgetc(of);
	}
}

CString CIE_COMDlg::getcontext(CString context,int i,int j)
{
	CString str;
	for(int k=i+1;k<j;k++)
	{
		str+=context[k];
	}
	return str;
}

void CIE_COMDlg::str2array(void)
{
	CString firstname;
	CString nextname;
	CString tempname;
	CString tempvalue;
	CStringArray stack;
	stack.Add("");
	int max=0;
	int nid=1;
	int k=0;
	int i1,i2,j1,j2,k1,k2;
	while((k<context.GetLength())&&(context[k]!='<'))
	{
		k++;
	}
	i1=k;

	while((k<context.GetLength())&&(context[k]!=' ')&&(context[k]!='>'))
	{
		k++;
	}
	k1=k;

	while((k<context.GetLength())&&(context[k]!='>'))
	{
		k++;
	}
	j1=k;

	firstname=getcontext(context,i1,k1);

	while((k<context.GetLength())&&(context[k]!='<'))
	{
		k++;
	}
	i2=k;

	while((k<context.GetLength())&&(context[k]!=' ')&&(context[k]!='>'))
	{
		k++;
	}
	k2=k;

	while((k<context.GetLength())&&(context[k]!='>'))
	{
		k++;
	}
	j2=k;

	nextname=getcontext(context,i2,k2);
	tempname='/'+firstname;

	

	while(k<context.GetLength())
	{
		if(tempname.Compare(nextname)==0)
		{
			node[count].name=firstname;
			tempvalue=getcontext(context,j1,i2);
			tempvalue.TrimLeft();
			tempvalue.TrimRight();
			node[count].value=tempvalue;
			node[count].id=nid;
			count++;
			do
			{
				while((k<context.GetLength())&&(context[k]!='<'))
				{
					k++;
				}
				i2=k;

				while((k<context.GetLength())&&(context[k]!=' ')&&(context[k]!='>'))
				{
					k++;
				}
				k2=k;

				while((k<context.GetLength())&&(context[k]!='>'))
				{
					k++;
				}
				j2=k;

				nextname=getcontext(context,i2,k2);
				if(nextname.Compare(stack.GetAt(max))==0)
				{
					stack.RemoveAt(max);
					nid--;
					max--;
				}
			}while((nextname.GetLength()>0)&&(nextname[0]=='/'));
			//same
		}
		else
		{
			tempname='/'+firstname;
			max++;
			stack.Add(tempname);
			node[count].name=firstname;
			node[count].value="";
			node[count].id=nid;
			count++;
			nid++;
			//different
		}

		firstname=nextname;
		i1=i2;
		k1=k2;
		j1=j2;

		while((k<context.GetLength())&&(context[k]!='<'))
		{
			k++;
		}
		i2=k;

		while((k<context.GetLength())&&(context[k]!=' ')&&(context[k]!='>'))
		{
			k++;
		}
		k2=k;

		while((k<context.GetLength())&&(context[k]!='>'))
		{
			k++;
		}
		j2=k;

		nextname=getcontext(context,i2,k2);
		tempname='/'+firstname;
	}
}
 /////////////////////////////////////////////////////////////////////////////////////////////////
