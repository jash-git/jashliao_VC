// NetWork_Browse_CopyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetWork_Browse_Copy.h"
#include "NetWork_Browse_CopyDlg.h"
#include <string.h>
#include <fstream.h>//純c++
#include <Winnetwk.h> 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//////////////////////////////
FILE *pf;
CString StrIP,StrNetWorkDir;
CString StrSearchDrt="";
struct FileData{
       int intnumber;
       char chrDir[500];
	   char chrFilName[100];
};
struct FileData *FD;
bool blnnewFileData=false;
int intShowCount=0;
///////////////////////////////
struct IPData{
       int intnumber;
       char chrIP[20];
};
struct IPData *IPD;
bool blnnewIPData=false;
int intTimer2Step=0;
int intIPCount=0;
FILE *pfNotConnect;//無連線IP
FILE *pfNotDelete;//無法刪除FileName與UP
FILE *pfDeleteOK;//紀錄刪除成功資料
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
// CNetWork_Browse_CopyDlg dialog

CNetWork_Browse_CopyDlg::CNetWork_Browse_CopyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNetWork_Browse_CopyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNetWork_Browse_CopyDlg)
	m_FileAmount = 0;
	m_StrNetWorkDir = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetWork_Browse_CopyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetWork_Browse_CopyDlg)
	DDX_Control(pDX, IDC_IPADDRESS1, m_IPData);
	DDX_Text(pDX, IDC_EDIT1, m_FileAmount);
	DDX_Text(pDX, IDC_EDIT3, m_StrNetWorkDir);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNetWork_Browse_CopyDlg, CDialog)
	//{{AFX_MSG_MAP(CNetWork_Browse_CopyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetWork_Browse_CopyDlg message handlers

BOOL CNetWork_Browse_CopyDlg::OnInitDialog()
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
	m_IPData.SetWindowText("172.19.0.0"); 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNetWork_Browse_CopyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNetWork_Browse_CopyDlg::OnPaint() 
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
HCURSOR CNetWork_Browse_CopyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNetWork_Browse_CopyDlg::OnButton1()//取得比對檔案數並紀錄檔名 
{
	// TODO: Add your control notification handler code here
	/*
	////////////////////////取得目前路徑
	TCHAR strCurDrt[500];
	m_FileAmount=0;
	int nLen = ::GetCurrentDirectory(500,strCurDrt);//取得目前程式路徑
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}
	///////////////////////產生搜尋路徑
	StrSearchDrt=strCurDrt;
	StrSearchDrt=StrSearchDrt+"\\AV";
	/////////////////////產生檔案
	pf=fopen("data.txt","w");
	BrowseDir(StrSearchDrt);
	fclose(pf);
	UpdateData(false);
	////////////////////
	*/
	GetLocalFileAmount();
	//MessageBox("OK");

}
void CNetWork_Browse_CopyDlg::BrowseDir(CString strDir)//列出所有資料夾內的檔案
{
	CFileFind ff;
	CString szDir = strDir;
	CString StrData;
	
	if(szDir.Right(1) != "\\")
		szDir += "\\";
	
	szDir += "*.*";
	
	BOOL res = ff.FindFile(szDir);
	while(res)
	{
		res = ff.FindNextFile();
		if(ff.IsDirectory() && !ff.IsDots())
		{
			//�蝚偶禤ぃ�
			BrowseDir(ff.GetFilePath());
		}
		else if(!ff.IsDirectory() && !ff.IsDots())
		{
			//為檔案
			StrData=ff.GetFilePath();
			fprintf(pf,"%s\n",StrData.GetBuffer(0));//完整路徑
			StrData=ff.GetFileName();
			fprintf(pf,"%s\n",StrData.GetBuffer(0));//純檔名
			m_FileAmount++;
		}
	}
	ff.Close();//關閉
}

void CNetWork_Browse_CopyDlg::OnButton2() //產生目標路徑
{
	// TODO: Add your control notification handler code here
	/*
	m_IPData.GetWindowText(StrIP); 
	StrNetWorkDir="\\\\";
	StrNetWorkDir+=StrIP;
	StrNetWorkDir+="\\d$\\NabroClient\\AV";
	m_StrNetWorkDir=StrNetWorkDir;
	UpdateData(false);
	*/
	CreateNetWorkPath();
}

void CNetWork_Browse_CopyDlg::OnButton3() //執行檔案名稱儲存到記憶體
{
	// TODO: Add your control notification handler code here
	pfNotConnect=fopen("NotConnect.txt","w");//無連線IP
	pfNotDelete=fopen("NotDelete.txt","w");//無法刪除FileName與UP
	/*
	int i=0;
	char chrSeps='\\';//建立分割符號
	char *chrInBuf;//建立暫存輸入資料指標
	char *chrOutBuf;//建立暫存輸出分割資料指標
	chrInBuf=new char('\0');//指標初始化
	chrOutBuf=new char('\0');//指標初始化
	char strdata[500];
	char strdata1[100];
	fstream fp;
    fp.open("data.txt",ios::in);
	intShowCount=0;
	if(blnnewFileData==false)
	{
		FD=new FileData[m_FileAmount];
	}
	else
	{
		delete []FD;
		FD=new FileData[m_FileAmount];
	}
	blnnewFileData=true;
	do
	{
		fp.getline(strdata,500);
		m_FileData=strdata;//取出含有路徑檔名
		(FD+i)->intnumber=i;
		strcpy((FD+i)->chrDir,m_FileData.GetBuffer(0));
		/////////////////////////////取出純檔名 
		fp.getline(strdata1,100);
		m_FileName=strdata1;
		strcpy((FD+i)->chrFilName,m_FileName.GetBuffer(0));
		i++;
	}while(i<m_FileAmount);
	fp.close();
	*/
	GetFileName2Memory();
	/////////////////////////////////////////////////////////
	/*
	char netpath[100]; 
	char drv[100];
	strcpy(netpath,m_StrNetWorkDir.GetBuffer(0));
	strcpy(drv,"X:");
	NETRESOURCE netres;
	netres.dwScope=RESOURCE_GLOBALNET;
	netres.dwType=RESOURCETYPE_ANY;
	netres.dwDisplayType=RESOURCEDISPLAYTYPE_GENERIC;
	netres.dwUsage=RESOURCEUSAGE_CONNECTABLE;
	netres.lpLocalName=drv;
	netres.lpRemoteName=netpath;
	netres.lpComment=NULL;
	netres.lpProvider=NULL;	
	CButton *but1;
	but1=(CButton *)this->GetDlgItem(IDC_BUTTON3);
	but1->EnableWindow(false);
	DWORD rslt=WNetAddConnection2(&netres,"nabro","nabro",0);//NABRO
	if(rslt==0)
	{
		this->SetDlgItemText(IDC_EDIT6,"已建立連線...");
		SetTimer(1,1000,NULL);
	}
	else
	{
		NETRESOURCE netres1;
		netres1.dwScope=RESOURCE_GLOBALNET;
		netres1.dwType=RESOURCETYPE_ANY;
		netres1.dwDisplayType=RESOURCEDISPLAYTYPE_GENERIC;
		netres1.dwUsage=RESOURCEUSAGE_CONNECTABLE;
		netres1.lpLocalName=drv;
		netres1.lpRemoteName=netpath;
		netres1.lpComment=NULL;
		netres1.lpProvider=NULL;
		DWORD rslt1=WNetAddConnection2(&netres1,"hermes","Administrator",0);//HERMES
		if(rslt1==0)
		{
			this->SetDlgItemText(IDC_EDIT6,"已建立連線...");
			SetTimer(1,1000,NULL);
		}
		else
		{
			but1->EnableWindow(true);
			MessageBox("無法建立網路磁碟機");
		}
	}
	*/
	bool return1=MountNetWorkDir(1);
}
bool CNetWork_Browse_CopyDlg::SearchFile(CString strDir,CString strFile)//尋找檔案是否存在
{
	CFileFind ff;
	CString szDir = strDir;
	bool blnretien=false;
	if(szDir.Right(1) != "\\")
		szDir += "\\";
	
	szDir += "*.*";
	
	BOOL res = ff.FindFile(szDir);
	while(res)
	{
		res = ff.FindNextFile();
		if(ff.GetFileName()==strFile)
		{
			blnretien=true;
		}
		if(ff.IsDirectory() && !ff.IsDots())
		{
			//子目錄
			SearchFile(ff.GetFilePath(),strFile);
		}
	}
	ff.Close();//關閉
	return blnretien;

}

void CNetWork_Browse_CopyDlg::OnTimer(UINT nIDEvent)//真正執行的主程式 
{
	// TODO: Add your message handler code here and/or call default
	/*
	CString StrDir,StrFileName;//UI變數
	CString StrState,StrBuf;//UI變數
	CString StrNetWorkDir;
	StrNetWorkDir="X:\\";
	bool blnSearch=false;
	CString StrNetWorkFile;
	CButton *but1;
	but1=(CButton *)this->GetDlgItem(IDC_BUTTON3);
	//////////////////////////////////////////////UI介面顯示
	StrDir=(FD+intShowCount)->chrDir;
	StrFileName=(FD+intShowCount)->chrFilName;
	this->SetDlgItemText(IDC_EDIT4,StrDir);
	this->SetDlgItemText(IDC_EDIT5,StrFileName);
	this->SetDlgItemInt(IDC_EDIT2,(intShowCount+1));
	///////////////////////////////////////////////
	//比對檔案
	KillTimer(1);
	StrState="第 ";
	this->GetDlgItemText(IDC_EDIT2,StrBuf);
	StrState+=StrBuf;
	StrState+=" 筆比對檔案";
	this->SetDlgItemText(IDC_EDIT6,StrState);
	blnSearch=SearchFile(StrNetWorkDir,StrFileName);//檔案搜尋
	if(blnSearch)
	{//有檔案
		StrNetWorkFile=StrNetWorkDir+"\\"+StrFileName;
		if(DeleteFile(StrNetWorkFile.GetBuffer(0)))
		{

			this->SetDlgItemText(IDC_EDIT6,"此筆檔案刪除中...");
		}
		else
		{
			MessageBox("檔案刪除失敗");
		}	
	}
	else
	{//無檔案
		StrState+="->無檔案";
		this->SetDlgItemText(IDC_EDIT6,StrState);
	}
	//////////////////////////////////////////
	intShowCount++;
	if(intShowCount==m_FileAmount)
	{
		this->SetDlgItemText(IDC_EDIT6,"所有檔案複製完成");
		but1->EnableWindow(true);
		char drv[100];
		strcpy(drv,"X:");
		DWORD rslt=WNetCancelConnection2(drv, 0, FALSE);
		if(rslt!=0)
			MessageBox("無法中斷網路磁碟機");
		MessageBox("完成");
	}
	else
	{
		SetTimer(1,1000,NULL);
	}
	*/
	bool return1;
	CButton *but1;
	switch(nIDEvent)
	{
		case 1:
			Timer1Function();
			break;
		case 2:
			switch(intTimer2Step)
			{
				case 1://設定IP
					m_IPData.SetWindowText((IPD+intIPCount)->chrIP);
					intTimer2Step=2;
					intIPCount++;
					break;
				case 2://產生網路位置和把檔案名稱放到記憶體
					CreateNetWorkPath();
					GetFileName2Memory();
					intTimer2Step=3;
					break;
				case 3://建立網路磁碟
					KillTimer(2);
					return1=MountNetWorkDir(2);
					if(return1)
					{
						intTimer2Step=4;
					}
					else
					{
						intTimer2Step=5;
					}
					break;
					SetTimer(2,1000,NULL);//啟動Timer2
				case 4://執行刪檔
					return1=AutomaticDeleteFile();
					if(return1)
					{
						intTimer2Step=5;
					}
					else
					{
						intTimer2Step=4;
					}
					break;
				case 5://判斷所有IP是否做完
					if(intIPCount<lngIPDataAmount)
					{
						intTimer2Step=1;
					}
					else
					{
						intTimer2Step=0;
						fclose(pfNotConnect);//無連線IP
						fclose(pfNotDelete);//無法刪除FileName與UP
						fclose(pfDeleteOK);//紀錄刪除成功資料
						KillTimer(2);
						but1=(CButton *)this->GetDlgItem(IDC_BUTTON4);
						but1->EnableWindow(true);
						MessageBox("完成所有IP_請查看記錄檔");
					}
					break;
			}
			break;
	}
	CDialog::OnTimer(nIDEvent);
}
void CNetWork_Browse_CopyDlg::GetLocalFileAmount()//計算檔案數量
{
	////////////////////////取得目前路徑
	TCHAR strCurDrt[500];
	m_FileAmount=0;
	int nLen = ::GetCurrentDirectory(500,strCurDrt);//取得目前程式路徑
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}
	///////////////////////產生搜尋路徑
	StrSearchDrt=strCurDrt;
	StrSearchDrt=StrSearchDrt+"\\AV";
	/////////////////////產生檔案
	pf=fopen("data.txt","w");
	BrowseDir(StrSearchDrt);
	fclose(pf);
	UpdateData(false);
	////////////////////
}
void CNetWork_Browse_CopyDlg::CreateNetWorkPath()//產生連線網址
{
	m_IPData.GetWindowText(StrIP); 
	StrNetWorkDir="\\\\";
	StrNetWorkDir+=StrIP;
	StrNetWorkDir+="\\d$\\NabroClient\\Data\\Schedule";
	m_StrNetWorkDir=StrNetWorkDir;
	UpdateData(false);
}
void CNetWork_Browse_CopyDlg::GetFileName2Memory()//把檔案名稱存入記憶體
{
	int i=0;
	char chrSeps='\\';//建立分割符號
	char *chrInBuf;//建立暫存輸入資料指標
	char *chrOutBuf;//建立暫存輸出分割資料指標
	chrInBuf=new char('\0');//指標初始化
	chrOutBuf=new char('\0');//指標初始化
	char strdata[500];
	char strdata1[100];
	fstream fp;
    fp.open("data.txt",ios::in);
	intShowCount=0;
	if(blnnewFileData==false)
	{
		FD=new FileData[m_FileAmount];
	}
	else
	{
		delete []FD;
		FD=new FileData[m_FileAmount];
	}
	blnnewFileData=true;
	do
	{
		fp.getline(strdata,500);
		m_FileData=strdata;//取出含有路徑檔名
		(FD+i)->intnumber=i;
		strcpy((FD+i)->chrDir,m_FileData.GetBuffer(0));
		/////////////////////////////取出純檔名 
		fp.getline(strdata1,100);
		m_FileName=strdata1;
		strcpy((FD+i)->chrFilName,m_FileName.GetBuffer(0));
		i++;
	}while(i<m_FileAmount);
	fp.close(); 
}
bool CNetWork_Browse_CopyDlg::MountNetWorkDir(int intTimer)//建立網路磁碟機
{
	/////////////////////////////////////////////////////////
	char netpath[100]; 
	char drv[100];
	strcpy(netpath,m_StrNetWorkDir.GetBuffer(0));
	strcpy(drv,"X:");
	NETRESOURCE netres;
	netres.dwScope=RESOURCE_GLOBALNET;
	netres.dwType=RESOURCETYPE_ANY;
	netres.dwDisplayType=RESOURCEDISPLAYTYPE_GENERIC;
	netres.dwUsage=RESOURCEUSAGE_CONNECTABLE;
	netres.lpLocalName=drv;
	netres.lpRemoteName=netpath;
	netres.lpComment=NULL;
	netres.lpProvider=NULL;	
	CButton *but1;
	but1=(CButton *)this->GetDlgItem(IDC_BUTTON3);
	but1->EnableWindow(false);
	DWORD rslt=WNetAddConnection2(&netres,"nabro","nabro",0);//NABRO
	if(rslt==0)
	{
		this->SetDlgItemText(IDC_EDIT6,"已建立連線...");
		if(intTimer==1)
		{
			SetTimer(1,1000,NULL);
		}
		else
		{
			SetTimer(2,1000,NULL);
		}
		return true;
	}
	else
	{
		NETRESOURCE netres1;
		netres1.dwScope=RESOURCE_GLOBALNET;
		netres1.dwType=RESOURCETYPE_ANY;
		netres1.dwDisplayType=RESOURCEDISPLAYTYPE_GENERIC;
		netres1.dwUsage=RESOURCEUSAGE_CONNECTABLE;
		netres1.lpLocalName=drv;
		netres1.lpRemoteName=netpath;
		netres1.lpComment=NULL;
		netres1.lpProvider=NULL;
		DWORD rslt1=WNetAddConnection2(&netres1,"hermes","Administrator",0);//HERMES
		if(rslt1==0)
		{
			this->SetDlgItemText(IDC_EDIT6,"已建立連線...");
			if(intTimer==1)
			{
				SetTimer(1,1000,NULL);
			}
			else
			{
				SetTimer(2,1000,NULL);
			}
			return true;
		}
		else
		{
			but1->EnableWindow(true);
			m_IPData.GetWindowText(StrIP); 
			fprintf(pfNotConnect,"%s\n",StrIP.GetBuffer(0));//無連線IP
			if(intTimer==1)
			{
				MessageBox("無法建立網路磁碟機");
			}
			else
			{
				SetTimer(2,1000,NULL);
			}
			return false;
			
		}
	}
	/////////////////////////////////////////////////////////////
}
void CNetWork_Browse_CopyDlg::Timer1Function()
{
	CString StrDir,StrFileName;//UI變數
	CString StrState,StrBuf;//UI變數
	CString StrNetWorkDir;
	StrNetWorkDir="X:\\";
	bool blnSearch=false;
	CString StrNetWorkFile;
	CButton *but1;
	but1=(CButton *)this->GetDlgItem(IDC_BUTTON3);
	//////////////////////////////////////////////UI介面顯示
	StrDir=(FD+intShowCount)->chrDir;
	StrFileName=(FD+intShowCount)->chrFilName;
	this->SetDlgItemText(IDC_EDIT4,StrDir);
	this->SetDlgItemText(IDC_EDIT5,StrFileName);
	this->SetDlgItemInt(IDC_EDIT2,(intShowCount+1));
	///////////////////////////////////////////////
	//比對檔案
	KillTimer(1);
	StrState="第 ";
	this->GetDlgItemText(IDC_EDIT2,StrBuf);
	StrState+=StrBuf;
	StrState+=" 筆比對檔案";
	this->SetDlgItemText(IDC_EDIT6,StrState);
	blnSearch=SearchFile(StrNetWorkDir,StrFileName);//檔案搜尋
	if(blnSearch)
	{//有檔案
		StrNetWorkFile=StrNetWorkDir+"\\"+StrFileName;
		if(DeleteFile(StrNetWorkFile.GetBuffer(0)))
		{

			this->SetDlgItemText(IDC_EDIT6,"此筆檔案刪除中...");
		}
		else
		{
			MessageBox("檔案刪除失敗");
		}	
	}
	else
	{//無檔案
		StrState+="->無檔案";
		this->SetDlgItemText(IDC_EDIT6,StrState);
	}
	//////////////////////////////////////////
	intShowCount++;
	if(intShowCount==m_FileAmount)
	{
		this->SetDlgItemText(IDC_EDIT6,"所有檔案刪除完成");
		but1->EnableWindow(true);
		char drv[100];
		strcpy(drv,"X:");
		DWORD rslt=WNetCancelConnection2(drv, 0, FALSE);
		if(rslt!=0)
			MessageBox("無法中斷網路磁碟機");
		MessageBox("完成");
	}
	else
	{
		SetTimer(1,1000,NULL);
	}
}

void CNetWork_Browse_CopyDlg::OnButton4()//自動檔案刪除 
{
	// TODO: Add your control notification handler code here
	CButton *but1;
	but1=(CButton *)this->GetDlgItem(IDC_BUTTON4);
	but1->EnableWindow(false);
	//Step 0_0 讀取檔案計算數量
	char chrstringbuf[20];//暫存IP資料
	lngIPDataAmount=0;//IP數量變數初始化_全域變數
	pf=fopen("IP_Data.txt","r");
	while(fscanf(pf,"%s",chrstringbuf)!=EOF)
		lngIPDataAmount++;
	fclose(pf);
	//Step 0_1 把檔案把IP放到記憶體
	fstream fp;
	int i=0;
    fp.open("IP_Data.txt",ios::in);
	if(blnnewIPData==false)
	{
		IPD=new IPData[lngIPDataAmount];
	}
	else
	{
		delete []IPD;
		IPD=new IPData[lngIPDataAmount];
	}
	blnnewFileData=true;
	do
	{
		fp.getline(chrstringbuf,500);
		(IPD+i)->intnumber=i;  
		strcpy((IPD+i)->chrIP,chrstringbuf);
		i++;
	}while(i<lngIPDataAmount);
	fp.close(); 
	//Step 0_2 呼叫timer2
	intTimer2Step=1;//intTimer2Step初始化設定
	intIPCount=0;//intIPCount初始化設定
	GetLocalFileAmount();
	pfNotConnect=fopen("NotConnect.txt","w");//無連線IP
	pfNotDelete=fopen("NotDelete.txt","w");//無法刪除FileName與UP
	pfDeleteOK=fopen("DeleteOK.txt","w");//紀錄刪除成功資料
	SetTimer(2,1000,NULL);//啟動Timer2
}
bool CNetWork_Browse_CopyDlg::AutomaticDeleteFile()
{
	CString StrDir,StrFileName;//UI變數
	CString StrState,StrBuf;//UI變數
	CString StrNetWorkDir;
	StrNetWorkDir="X:\\";
	bool blnSearch=false;
	CString StrNetWorkFile;
	CButton *but1;
	but1=(CButton *)this->GetDlgItem(IDC_BUTTON3);
	//////////////////////////////////////////////UI介面顯示
	StrDir=(FD+intShowCount)->chrDir;
	StrFileName=(FD+intShowCount)->chrFilName;
	this->SetDlgItemText(IDC_EDIT4,StrDir);
	this->SetDlgItemText(IDC_EDIT5,StrFileName);
	this->SetDlgItemInt(IDC_EDIT2,(intShowCount+1));
	///////////////////////////////////////////////
	//比對檔案
	KillTimer(2);
	StrState="第 ";
	this->GetDlgItemText(IDC_EDIT2,StrBuf);
	StrState+=StrBuf;
	StrState+=" 筆比對檔案";
	this->SetDlgItemText(IDC_EDIT6,StrState);
	blnSearch=SearchFile(StrNetWorkDir,StrFileName);//檔案搜尋
	if(blnSearch)
	{//有檔案
		StrNetWorkFile=StrNetWorkDir+"\\"+StrFileName;
		if(DeleteFile(StrNetWorkFile.GetBuffer(0)))
		{
			m_IPData.GetWindowText(StrIP); 
			fprintf(pfDeleteOK,"%s\t%s\n",StrIP.GetBuffer(0),StrFileName.GetBuffer(0));//紀錄刪除成功資料
			this->SetDlgItemText(IDC_EDIT6,"此筆檔案刪除中...");
		}
		else
		{
			//MessageBox("檔案刪除失敗");
			m_IPData.GetWindowText(StrIP); 
			fprintf(pfNotDelete,"%s\t%s\n",StrIP.GetBuffer(0),StrFileName.GetBuffer(0));//無法刪除FileName與UP
		}	
	}
	else
	{//無檔案
		StrState+="->無檔案";
		this->SetDlgItemText(IDC_EDIT6,StrState);
	}
	//////////////////////////////////////////
	intShowCount++;
	if(intShowCount==m_FileAmount)
	{
		this->SetDlgItemText(IDC_EDIT6,"所有檔案刪除完成");
		but1->EnableWindow(true);
		char drv[100];
		strcpy(drv,"X:");
		DWORD rslt=WNetCancelConnection2(drv, 0, FALSE);
		if(rslt!=0)
		{
			MessageBox("無法中斷網路磁碟機");
		}
		else
		{
			SetTimer(2,1000,NULL);
			return true;
		}
		//MessageBox("完成");
	}
	else
	{
		SetTimer(2,1000,NULL);
		return false;
	}
	return false;
}