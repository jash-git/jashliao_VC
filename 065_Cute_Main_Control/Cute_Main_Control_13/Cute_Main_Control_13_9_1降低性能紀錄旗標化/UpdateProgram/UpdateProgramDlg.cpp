// UpdateProgramDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UpdateProgram.h"
#include "UpdateProgramDlg.h"

char MAP_NAME0[20]=	"spacesoft1 corp0.";
char MAP_NAME1[20]=	"spacesoft1 corp1.";
char MAP_NAME2[20]=	"spacesoft1 corp2.";
char MAP_NAME3[20]=	"spacesoft1 corp3.";
#define	MAP_LENGTH	8
HANDLE hFileMap[4] ={NULL,NULL,NULL,NULL} ;
static char szOldData[MAP_LENGTH] = "" ;
int gintStep;
TCHAR gstrCurDrt[500];//存放目前目錄字串
bool gblncheck=false;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CUpdateProgramDlg dialog

CUpdateProgramDlg::CUpdateProgramDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUpdateProgramDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUpdateProgramDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	hFileMap[0] = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME0 ) ;
	//hFileMap[1] = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME1 ) ;
	//hFileMap[2] = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME2 ) ;
	//hFileMap[3] = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME3 ) ;

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUpdateProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUpdateProgramDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUpdateProgramDlg, CDialog)
	//{{AFX_MSG_MAP(CUpdateProgramDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUpdateProgramDlg message handlers

BOOL CUpdateProgramDlg::OnInitDialog()
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
	gintStep=0;
	SetTimer(1,20000,NULL);
	ShowWindow(SW_MINIMIZE);//縮小主視窗
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CUpdateProgramDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CUpdateProgramDlg::OnPaint() 
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
HCURSOR CUpdateProgramDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CUpdateProgramDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	LPVOID mapView[4];
	bool bln1;
	int i=0,j,intCount=0;
	HINSTANCE result;
	char data[250],data1[250];
	char ch1[10];
	int nLen=0;
	CString StrFileName1,StrFileName2;
	CWnd* hWnd1;
	FILE *pf1;
	KillTimer(1);
	////////////////////////////////////////////////////////////////////
	//for(i=0;i<4;i++)
	//{
		//mapView[i] = MapViewOfFile( hFileMap[i],FILE_MAP_WRITE, 0, 0, 0 ) ;
	//}
	mapView[0] = MapViewOfFile( hFileMap[0],FILE_MAP_WRITE, 0, 0, 0 ) ;
	intCount=atoi((LPTSTR)mapView[0]);
	if(intCount>0)
	{
		switch(gintStep)
		{
			case 0://關閉Cute_Main
				hWnd1=FindWindow(NULL, "Cute_Main_Control");
				if(hWnd1!=NULL)
				{
					hWnd1->SendMessage(WM_CLOSE,0,0);
					gintStep=0;
				}
				else
				{
					gintStep=1;
				}
				break;
			case 1://複製檔案和刪除
				j=0;
				pf1=fopen("UpdateProgram.txt","r");
				nLen=::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
				if( gstrCurDrt[nLen]!='\\' )
				{
					gstrCurDrt[nLen++] = '\\';
					gstrCurDrt[nLen] = '\0';
				}
				while(fgets(data,250,pf1)!=NULL)
				{
					fgets(data1,250,pf1);
					j++;
					if(j<=intCount)
					{
						StrFileName1=data;
						StrFileName1=StrFileName1.Mid(0,(StrFileName1.GetLength()-1) );//刪除換行字元  
						StrFileName2=gstrCurDrt;
						StrFileName2+=data1;
						StrFileName2=StrFileName2.Mid(0,(StrFileName2.GetLength()-1) );//刪除換行字元  
						bln1=CopyFile(StrFileName1.GetBuffer(0),StrFileName2.GetBuffer(0),false);
						bln1=DeleteFile(StrFileName1.GetBuffer(0));
					}
				}
				fclose(pf1);
				gintStep=2;
				break;
			case 2://清除共享記憶體，呼叫Cute_Main
				intCount=0;
				itoa(intCount,ch1,10);//將更新筆數從數值變字串
				strcpy((LPTSTR)mapView[0],ch1);//將筆數資料給映射變數
				//strcpy((LPTSTR)mapView[1],ch1);//將筆數資料給映射變數
				//strcpy((LPTSTR)mapView[2],ch1);//將筆數資料給映射變數
				//strcpy((LPTSTR)mapView[3],ch1);//將筆數資料給映射變數
				UnmapViewOfFile( (LPVOID)mapView[0]);
				//UnmapViewOfFile( (LPVOID)mapView[1]);
				//UnmapViewOfFile( (LPVOID)mapView[2]);
				//UnmapViewOfFile( (LPVOID)mapView[3]);
				do
				{
					result=ShellExecute(NULL,"open","Cute_Main_Control.exe",NULL,NULL,SW_SHOWNORMAL);
				}while((int)result<32);
				OnOK();
				break;
		}
	}
	else
	{
		if(gblncheck)
		{
			intCount=-1;
		}
		else
		{
			intCount=-2;
		}
		gblncheck=!gblncheck;
		itoa(intCount,ch1,10);//將更新筆數從數值變字串
		strcpy((LPTSTR)mapView[0],ch1);//將筆數資料給映射變數
		//strcpy((LPTSTR)mapView[1],ch1);//將筆數資料給映射變數
		//strcpy((LPTSTR)mapView[2],ch1);//將筆數資料給映射變數
		//strcpy((LPTSTR)mapView[3],ch1);//將筆數資料給映射變數
		UnmapViewOfFile( (LPVOID)mapView[0]);
		//UnmapViewOfFile( (LPVOID)mapView[1]);
		//UnmapViewOfFile( (LPVOID)mapView[2]);
		//UnmapViewOfFile( (LPVOID)mapView[3]);
	}
	//////////////////////////////////////////////////////////
	SetTimer(1,20000,NULL);
	CDialog::OnTimer(nIDEvent);
}
