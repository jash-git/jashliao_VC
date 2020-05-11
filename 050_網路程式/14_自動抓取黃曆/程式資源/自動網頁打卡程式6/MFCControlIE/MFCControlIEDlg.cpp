// MFCControlIEDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCControlIE.h"
#include "MFCControlIEDlg.h"
#include <stdlib.h>
#include <time.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
int check=0;
int intrand=1;
FILE *fp,*fp1;
FILE *fp2;
int **GetDay;
int datanumer=0;
bool bnlSaturday=false;
bool bnlSunday=false;
TCHAR strCurDrt[500];
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
// CMFCControlIEDlg dialog

CMFCControlIEDlg::CMFCControlIEDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCControlIEDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFCControlIEDlg)
	m_hr = 0;
	m_min = 0;
	m_v1 = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCControlIEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCControlIEDlg)
	DDX_Control(pDX, IDC_BUTTON1, m_CBut1);
	DDX_Text(pDX, IDC_EDIT1, m_hr);
	DDX_Text(pDX, IDC_EDIT2, m_min);
	DDX_Text(pDX, IDC_EDIT3, m_v1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFCControlIEDlg, CDialog)
	//{{AFX_MSG_MAP(CMFCControlIEDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCControlIEDlg message handlers

BOOL CMFCControlIEDlg::OnInitDialog()
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
	// TODO: Add your control notification handler code here
	///測試筆數
	int a,b,i,j;//a,b為月日，i,j為旗標
	fp=fopen("day.txt","r");
	j=0;
	while(fscanf(fp,"%d%d",&a,&b)!=EOF)
		j++;
	fclose(fp);
	////
	////讀取資料
	GetDay=new int *[j];
	for(i=0;i<j;i++)
	{
		GetDay[i]=new int[2];
	}
	fp=fopen("Day.txt","r");
	j=0;
	while(fscanf(fp,"%d%d",&a,&b)!=EOF)
	{
		*(*(GetDay+j)+0)=a;//月
		*(*(GetDay+j)+1)=b;//日
		j++;
	}
	datanumer=j;
	////////////////////////////////////
	fp1=fopen("Week1.txt","r");
	while(fscanf(fp1,"%d%d",&a,&b)!=EOF)
	{
		//true--->不打卡
		//false-->打卡
		bnlSaturday=a;
		bnlSunday=b;		
	}
	fclose(fp1);
	int nLen = ::GetCurrentDirectory(500,strCurDrt);//取得目前程式路徑
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}
	fp2=fopen("rand1.txt","r");
	fscanf(fp2,"%d",&intrand);
	fclose(fp2);
	SetTimer(1,60000,NULL);
	m_CBut1.EnableWindow(false); 	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCControlIEDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCControlIEDlg::OnPaint() 
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
HCURSOR CMFCControlIEDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFCControlIEDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	///測試筆數
	int a,b,i,j;//a,b為月日，i,j為旗標
	fp=fopen("day.txt","r");
	j=0;
	while(fscanf(fp,"%d%d",&a,&b)!=EOF)
		j++;
	fclose(fp);
	////
	////讀取資料
	GetDay=new int *[j];
	for(i=0;i<j;i++)
	{
		GetDay[i]=new int[2];
	}
	fp=fopen("Day.txt","r");
	j=0;
	while(fscanf(fp,"%d%d",&a,&b)!=EOF)
	{
		*(*(GetDay+j)+0)=a;//月
		*(*(GetDay+j)+1)=b;//日
		j++;
	}
	datanumer=j;
	////////////////////////////////////
	fp1=fopen("Week1.txt","r");
	while(fscanf(fp1,"%d%d",&a,&b)!=EOF)
	{
		//true--->不打卡
		//false-->打卡
		bnlSaturday=a;
		bnlSunday=b;		
	}
	fclose(fp1);
	int nLen = ::GetCurrentDirectory(500,strCurDrt);//取得目前程式路徑
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}
	SetTimer(1,60000,NULL);
	m_CBut1.EnableWindow(false); 
}

void CMFCControlIEDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	int hr,min;
	int nowday;
	int i,a,b;
	int startmin,endmin;
	CTime t1=CTime::GetCurrentTime();
	int Month=t1.GetMonth(); //月
	int Day=t1.GetDay();//日
	int week=t1.GetDayOfWeek(); 
	bool bnlCloseApp0=false;//日期
	bool bnlCloseApp1=false;//星期六
	bool bnlCloseApp2=false;//星期日
	hr=t1.GetHour();
	min=t1.GetMinute();
	UpdateData(true);
		m_min=min;
		m_hr=hr;
		m_v1=intrand;
	UpdateData(false);
	min+=hr*60;
	startmin=510+intrand;//8:30
	endmin=1080+intrand;//18:00
	CString strFileName1 = strCurDrt;
	strFileName1+="IE_COM.exe";
	if(week==1 && bnlSunday)
	{
		//true--->不打卡
		//false-->打卡
		bnlCloseApp1=true;//星期日
	}
	if(week==7 && bnlSaturday)
	{
		//true--->不打卡
		//false-->打卡
		bnlCloseApp2=true;//星期六
	}
	for(i=0;i<datanumer;i++)
	{
		a=*(*(GetDay+i)+0);//月
		b=*(*(GetDay+i)+1);//日
		if(a==Month && b==Day)
		{
			bnlCloseApp0=true;//因為設定日期，所以不打卡
			break;
		}
		else
		{
			bnlCloseApp0=false;
		}
	}
	if(min>=startmin && min<=525 && check==0 )
	{
		check++;
		if((bnlCloseApp0!=true) && (bnlCloseApp1!=true) && (bnlCloseApp2!=true))//式設定日期
			ShellExecute(NULL,"open",strFileName1,NULL,NULL,SW_SHOWNORMAL); 
	}
	if(min>=endmin && check==1)
	{
		check++;
		if((bnlCloseApp0!=true) && (bnlCloseApp1!=true) && (bnlCloseApp2!=true))//式設定日期
			ShellExecute(NULL,"open",strFileName1,NULL,NULL,SW_SHOWNORMAL);
	}
	if(check==2)
	{
		srand(time(NULL));
		//srand(GetTickCount()); 
		intrand=(rand()%10)+1;
		fp2=fopen("rand1.txt","w");
		fprintf(fp2,"%d\n",intrand);
		fclose(fp2);
		check=0;
	}
	CDialog::OnTimer(nIDEvent);
}

void CMFCControlIEDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	this->ShowWindow(SW_MINIMIZE);
	//this->ShowWindow(SW_SHOWMINNOACTIVE);
	//this->ShowWindow(SW_HIDE);
}

void CMFCControlIEDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	check=1;
}
