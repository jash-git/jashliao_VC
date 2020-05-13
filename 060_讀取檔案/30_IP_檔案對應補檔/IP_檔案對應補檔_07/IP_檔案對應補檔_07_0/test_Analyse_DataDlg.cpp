// test_Analyse_DataDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test_Analyse_Data.h"
#include "test_Analyse_DataDlg.h"
#include <string.h>
#include <stdlib.h>
#include<fstream.h>
#include <Winnetwk.h> 
#include <mmsystem.h>//icon_Step 1
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//////////////////////////////////////
#define WM_SHOWTASK	WM_USER+5//icon_Step 2
bool gblnCheckHide=false;//icon_Step 2
//////////////////////////////////////
bool gblnCheckSQL=false;//SQL_Step 4 ;true->成功.false->失敗
//////////////////////////////////////////////////////////////
CString gStrInfoFileHead="";
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
bool gblnConnectCheck=false;
CString gStrIP,gStrNetWorkDir;
CString gStrSearchDrt;
FILE *pfNotConnect;//無連線IP
FILE *pfNotRun;//無法失敗資料
FILE *pfRunOK;//紀錄成功資料
FILE *pfResult;//紀錄要回寫SQL資料
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
// CTest_Analyse_DataDlg dialog

CTest_Analyse_DataDlg::CTest_Analyse_DataDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTest_Analyse_DataDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTest_Analyse_DataDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest_Analyse_DataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTest_Analyse_DataDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTest_Analyse_DataDlg, CDialog)
	//{{AFX_MSG_MAP(CTest_Analyse_DataDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_MESSAGE(WM_SHOWTASK,onShowTask)//icon_Step 4
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest_Analyse_DataDlg message handlers

BOOL CTest_Analyse_DataDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTest_Analyse_DataDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTest_Analyse_DataDlg::OnPaint() 
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
HCURSOR CTest_Analyse_DataDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTest_Analyse_DataDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	fstream pf;
	FILE *pf1;
	int intFileNO=0;
	char chrFileName[20];
	CString StrFileName;
	CString StrSearchFileName;
	bool blnSearchFile=false;
	//struct file_data fd;---->移至全域變數
	char chrdata[500];
	bool blnLen=false;
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
	//////////////////////////////01_start
	CString StrDir;
	CString StrNetWorkDir;
	StrNetWorkDir="X:\\AV\\Standby\\";///----->因為只指到NabroClien
	CString StrNetWorkFile;
	pf.open("data.txt",ios::in);
	pfNotConnect=fopen("NotConnect.txt","w");//無連線IP
	pfNotRun=fopen("NotRun.txt","w");//無法複製FileName與UP
	pfRunOK=fopen("RunOK.txt","w");//紀錄複製成功資料
	pfResult=fopen("Result.txt","w");//紀錄要回寫SQL資料
	int intCount=0;
	////////////////////////取得目前路徑
	TCHAR strCurDrt[500];
	int nLen = ::GetCurrentDirectory(500,strCurDrt);//取得目前程式路徑
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}
	///////////////////////產生搜尋路徑
	gStrSearchDrt=strCurDrt;
	gStrSearchDrt=gStrSearchDrt+"AV\\";
	//////////////////////////////////
	CString StrInfoFileName="X:\\AV\\Schedule\\";
	FILE *pinfo;
	/////////////////////////////////
	while(!pf.eof())
	//////////////////////////////01_end
	{
		///////////////////////////////////02_start
		pf.getline(chrdata,500);
		m_strInData=chrdata;
		strInData=m_strInData;//取出原來資料
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
		if(blnLen==true)//防堵最後一筆資料換行所造成誤判
		{
			if(intFileNO!=0)
				fclose(pf1);
			break;
		}
		intCount=0;
		lngLen=0;//建立長度暫存變數
		lngGetLen1=0;//提取資料長度
		lngGetLen2=0;//剩餘資料長度
		/////////////////////////////////02_end
		////////////////////////////////03_start
		StrBuf=fd.chrip;
		if(StrIP!=StrBuf)
		{
			StrIP=StrBuf;
			gStrIP=StrIP;
			if(gblnConnectCheck==false)
			{//連線
				CreateNetWorkPath();//產生連線網址
				gblnConnectCheck=MountNetWorkDir();//建立網路磁碟機
			}
			else
			{//斷線&連線
				char drv[100];
				strcpy(drv,"X:");
				DWORD rslt=WNetCancelConnection2(drv, 0, FALSE);
				if(rslt!=0)
				{
					MessageBox("無法中斷網路磁碟機");
					return;
				}
				else
				{
					CreateNetWorkPath();//產生連線網址
					gblnConnectCheck=MountNetWorkDir();//建立網路磁碟機
				}
			}
			if(intFileNO!=0)
				fclose(pf1);
			intFileNO++;
			this->SetDlgItemInt(IDC_BUTTON1,intFileNO);//->UI 
			itoa(intFileNO,chrFileName,10);
			StrFileName=chrFileName;
			StrFileName+=".txt";
			pf1=fopen(StrFileName.GetBuffer(0),"w");
			fprintf(pf1,"%s\n",fd.chrip);
			fprintf(pf1,"%d\t%d\t%s\n",fd.intuid,fd.intaction,fd.chrfile_path); 
		}
		else
		{
			fprintf(pf1,"%d\t%d\t%s\n",fd.intuid,fd.intaction,fd.chrfile_path);
		}
		///////////////////////////////////////////////////////////////////
		StrDir=gStrSearchDrt+fd.chrfile_path;
		StrNetWorkFile=StrNetWorkDir+fd.chrfile_path;
		//////////////////////////////////////////////////////////
		CreatInfoFileHead();
		StrInfoFileName="X:\\AV\\Schedule\\";
		StrInfoFileName+=gStrInfoFileHead;
		StrInfoFileName+=fd.chrfile_path;
		StrInfoFileName+=".info";
		///////////////////////////////////////////////////////////
		if(gblnConnectCheck==true)
		{ 
			StrSearchFileName=fd.chrfile_path;
			blnSearchFile=SearchFile(StrNetWorkDir,StrSearchFileName);//"X:\\,StrSearchFileName"
			switch(fd.intaction)
			{
				case 0://Add
					if(blnSearchFile==true)
					{
						fd.intstatus=3;//不用做事 
					}
					else
					{
						if(CopyFile(StrDir.GetBuffer(0),StrNetWorkFile.GetBuffer(0),FALSE))
						{
							fd.intstatus=1;//成功
							pinfo=fopen(StrInfoFileName.GetBuffer(0),"w");
							fclose(pinfo);
							fprintf(pfRunOK,"%d\t%d\t%s\n",fd.intuid,fd.intaction,fd.chrfile_path); //複製成功資料
						}
						else
						{
							fd.intstatus=2;//失敗-斷線
							fprintf(pfNotRun,"%d\t%d\t%s\n",fd.intuid,fd.intaction,fd.chrfile_path);//無法複製
						}
					}
					break;
				case 1://Del
					if(blnSearchFile==true)
					{
						if(DeleteFile(StrNetWorkFile.GetBuffer(0)))
						{
							fd.intstatus=1;//成功
							fprintf(pfRunOK,"%d\t%d\t%s\n",fd.intuid,fd.intaction,fd.chrfile_path); //成功刪除資料
						}
						else
						{
							fd.intstatus=2;//失敗-斷線
							fprintf(pfNotRun,"%d\t%d\t%s\n",fd.intuid,fd.intaction,fd.chrfile_path);//無法刪除
						}
					}
					else
					{
						fd.intstatus=3;//不用做事 
					}
					break;
				case 2://Check
					if(blnSearchFile==true)
					{
						fd.intstatus=3;//Check OK
					}
					else
					{
						fd.intstatus=4;//Check NO File 
					}
					break;
			}
			Sleep(1000);
		}
		else
		{
			fd.intstatus=2;//失敗-斷線
		}
		//////////////////////////////////////////////////////////////////
		////////////////////////////////03_end
		fprintf(pfResult,"%d\t%d\n",fd.intuid,fd.intstatus); 
	}
	pf.close();
	fclose(pfNotConnect);//無連線IP
	fclose(pfResult);
	if(gblnConnectCheck==true)
	{
		char drv[100];
		strcpy(drv,"X:");
		DWORD rslt=WNetCancelConnection2(drv, 0, FALSE);
		if(rslt!=0)
		{
			MessageBox("無法中斷網路磁碟機");
			return;
		}
	}
	fclose(pfRunOK);
	fclose(pfNotRun);
	MessageBox("OK");
}

void CTest_Analyse_DataDlg::CreateNetWorkPath()//產生連線網址
{ 
	gStrNetWorkDir="\\\\";
	gStrNetWorkDir+=gStrIP;
	//gStrNetWorkDir+="\\d$\\NabroClient\\AV";
	gStrNetWorkDir+="\\d$\\NabroClient";///----->因為只指到NabroClien
	m_StrNetWorkDir=gStrNetWorkDir;
}

bool CTest_Analyse_DataDlg::MountNetWorkDir()//建立網路磁碟機
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
	DWORD rslt=WNetAddConnection2(&netres,"nabro","nabro",0);//NABRO
	if(rslt==0)
	{
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
			return true;
		}
		else
		{
			fprintf(pfNotConnect,"%s\n",gStrIP.GetBuffer(0));//無連線IP
			return false;
			
		}
	}
	/////////////////////////////////////////////////////////////
}
LRESULT CTest_Analyse_DataDlg::onShowTask(WPARAM wParam,LPARAM lParam)//icon_Step 5
{
	//wParam接收的是圖示的ID，而lParam接收的是滑鼠的行為
	if(wParam!=IDR_MAINFRAME)
		return 1;
	switch(lParam)
	{
		case WM_RBUTTONUP://右鍵起來時彈出快顯功能表，這裏只有一個"關閉"
		{ 
			LPPOINT lpoint=new tagPOINT;
			::GetCursorPos(lpoint);//得到滑鼠位置
			CMenu menu;
			menu.CreatePopupMenu();//聲明一個彈出式功能表
			//增加功能表項"關閉"，點擊則發送消息WM_DESTROY給主視窗（已
			//隱藏），將程式結束。
			menu.AppendMenu(MF_STRING,WM_DESTROY,"關閉"); 
			//確定彈出式菜單的位置
			menu.TrackPopupMenu(TPM_LEFTALIGN,lpoint->x,lpoint->y,this);
			//資源回收
			HMENU hmenu=menu.Detach();
			menu.DestroyMenu();
			delete lpoint;
		}
		break;
		case WM_LBUTTONDBLCLK://雙擊左鍵的處理
		{
			this->ShowWindow(SW_SHOW);//簡單的顯示主視窗完事兒
		}
		break;
	}
	return 0;
}

void CTest_Analyse_DataDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	if(gblnCheckHide==false)
	{
		NOTIFYICONDATA nid;
		nid.cbSize=(DWORD)sizeof(NOTIFYICONDATA);
		nid.hWnd=this->m_hWnd;
		nid.uID=IDR_MAINFRAME;
		nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP ;
		nid.uCallbackMessage=WM_SHOWTASK;//自定義的消息名稱
		nid.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));
		strcpy(nid.szTip,"自動砍補檔");//資訊提示條為"計畫任務提醒"
		Shell_NotifyIcon(NIM_ADD,&nid);//在託盤區添加圖示
		gblnCheckHide=true;
	}
	ShowWindow(SW_HIDE);//隱藏主視窗	
}
void CTest_Analyse_DataDlg::ReadMySQLData()//SQL_Step 4
{
	bool checkDB=false;
	bool checkRS=false;
	CString d1,d2;
	FILE *pf;
	CString var0,var1,var2,var3,var4,var5,var6;//var可以轉換為其他類型的值
	m_DB=new CDatabase();
	d1="MySQL-Data";//ODBC名稱
	checkDB=m_DB->Open(d1);
	if(checkDB)
	{
		m_RS=new CRecordset(m_DB);
		d2="SELECT * FROM video_check WHERE status = 0 ORDER BY ip DESC";
		checkRS=m_RS->Open(CRecordset::forwardOnly,d2); 
		if(checkRS)
		{
			pf=fopen("data.txt","w");
			while (!m_RS->IsEOF())
			{
				//讀取內部數值
				m_RS->GetFieldValue(_T("uid"),var0);
				m_RS->GetFieldValue(_T("action"),var1);
				m_RS->GetFieldValue(_T("ip"),var2);
				m_RS->GetFieldValue(_T("file_path"),var3);
				m_RS->GetFieldValue(_T("status"),var4);
				m_RS->GetFieldValue(_T("Start_Date"),var5);
				m_RS->GetFieldValue(_T("End_Date"),var6);
				fprintf(pf,"%s,%s,%s,%s,%s,%s,%s\n",var0.GetBuffer(0),var1.GetBuffer(0),var2.GetBuffer(0),var3.GetBuffer(0),var4.GetBuffer(0),var5.GetBuffer(0),var6.GetBuffer(0));
				m_RS->MoveNext();
			}
			fclose(pf);
			m_DB->Close();
			gblnCheckSQL=true;//true->成功.false->失敗
		}
		else
		{
			//MessageBox("RS NOT OK");
			gblnCheckSQL=false;//true->成功.false->失敗
		}
	}
	else
	{
		//MessageBox("DB NOT OK");
		gblnCheckSQL=false;//true->成功.false->失敗
	}
}

bool CTest_Analyse_DataDlg::SearchFile(CString strDir,CString strFile)//尋找檔案是否存在
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
			break;
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
void CTest_Analyse_DataDlg::CreatInfoFileHead()
{
	CString StrStart_Date,StrEnd_Date; 
	//////////////////////////////////
	CString StrYear,StrMonth,StrDay,StrCount;
	char *chrbuf;
	int intLen=0;
	int intCountYear=0;
	int intResultYear=0;
	int intYear,intMonth,intDay,intCount;
	/////////////////////////////////////
	int y1,m1,d1;
	int y2,m2,d2;
	gStrInfoFileHead="";
	StrEnd_Date=fd.chrEnd_Date;
	StrStart_Date=fd.chrStart_Date; 
	sscanf(StrStart_Date.GetBuffer(StrStart_Date.GetLength()),"%d-%d-%d",&y1,&m1,&d1);
	sscanf(StrEnd_Date.GetBuffer(StrEnd_Date.GetLength()),"%d-%d-%d",&y2,&m2,&d2); 
	CTime t1(y1,m1,d1,0,0,0);//起始時間     
	CTime t2(y2,m2,d2,0,0,0);//終止時間     
	CTimeSpan ts;
	ts =t2-t1;
	//intCount=ts.GetDays()+1;//天數=終止時間-起始時間+1
	intCount=ts.GetDays();
	intYear=y1;
	intMonth=m1;
	intDay=d1;
	do
	{
		intCountYear+=1000;
		intResultYear=intYear-intCountYear;
	}
	while(intResultYear>=0);
	intCountYear-=1000;
	intYear-=intCountYear;
	//////////////////////////////
	StrYear.Format("%x",intYear);
	chrbuf=StrYear.GetBuffer(0);
	intLen=strlen(chrbuf);
	if(intLen==1)
	{
		StrYear="0"+StrYear;
	}
	///////////////////////////////
	StrMonth.Format("%x",intMonth);
	chrbuf=StrMonth.GetBuffer(0);
	intLen=strlen(chrbuf);
	if(intLen==1)
	{
		StrMonth="0"+StrMonth;
	}
	///////////////////////////
	StrDay.Format("%x",intDay);
	chrbuf=StrDay.GetBuffer(0);
	intLen=strlen(chrbuf);
	if(intLen==1)
	{
		StrDay="0"+StrDay;
	}
	///////////////////////////
	StrCount.Format("%x",intCount);
	chrbuf=StrCount.GetBuffer(0);
	intLen=strlen(chrbuf);
	if(intLen==1)
	{
		StrCount="0"+StrCount;
	}
	/////////////////////
	gStrInfoFileHead=StrYear+StrMonth+StrDay+StrCount;
}

void CTest_Analyse_DataDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
ReadMySQLData();	
}
