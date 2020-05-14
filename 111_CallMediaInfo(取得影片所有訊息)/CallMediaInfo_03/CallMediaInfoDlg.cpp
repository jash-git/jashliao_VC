// CallMediaInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CallMediaInfo.h"
#include "CallMediaInfoDlg.h"
#include "ShowInfoDlg.h"
#include<fstream.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
TCHAR strCurDrt[500];
CString StrEXEPath;
CString StrlogPath;
CString StrCmd;
CString StrCheckData[10];
CString StrShowData[11];
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
// CCallMediaInfoDlg dialog

CCallMediaInfoDlg::CCallMediaInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCallMediaInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCallMediaInfoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCallMediaInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCallMediaInfoDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCallMediaInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CCallMediaInfoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCallMediaInfoDlg message handlers

BOOL CCallMediaInfoDlg::OnInitDialog()
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
	////////////////////////////
	int nLen = ::GetCurrentDirectory(500,strCurDrt);//取得目前程式路徑
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}
	////////////////////////////
	StrCheckData[0]="Complete name                    :";//完整路徑檔名
	StrCheckData[1]="Format                           :";//格式
	StrCheckData[2]="File size                        :";//檔案大小
	StrCheckData[3]="Duration                         :";//影片長度
	StrCheckData[4]="Bit rate                         :";//影片BIT RATE X2
	StrCheckData[5]="Width                            :";//影片寬度
	StrCheckData[6]="Height                           :";//影片高度
	StrCheckData[7]="Display aspect ratio             :";//顯示比例
	StrCheckData[8]="Frame rate                       :";//影片每秒影格數
	StrCheckData[9]="Sampling rate                    :";//聲音取樣頻率
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCallMediaInfoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCallMediaInfoDlg::OnPaint() 
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
HCURSOR CCallMediaInfoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCallMediaInfoDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	////////////////////////////
	//影片檔名資訊
	CString strFileName;
	CString strPathName;
	CString strFileTitle;
	CString strBatPath;
	FILE *pfBat=NULL;
	CFileDialog fdlg(true,NULL,"openfile",NULL,"ALL FILES|*.*");
	if(fdlg.DoModal()==IDOK)
	{
		strPathName=fdlg.GetPathName();
		strFileName=fdlg.GetFileName();
		strFileTitle=fdlg.GetFileTitle();
		strBatPath=strCurDrt;
		strBatPath+="GetMediaInfo.bat";
		pfBat=fopen(strBatPath.GetBuffer(0),"w");
		if(pfBat!=NULL)
		{
			StrEXEPath=strCurDrt;
			StrEXEPath+="MediaInfo_cmd\\MediaInfo.exe";
			StrEXEPath+=" ";
			strPathName+=" > ";
			StrlogPath=strCurDrt;
			StrlogPath+=strFileTitle;
			StrlogPath+=".txt";
			StrCmd=StrEXEPath+strPathName+StrlogPath;
			fprintf(pfBat,"%s\n",StrCmd.GetBuffer(0));
			fclose(pfBat);
			//ShellExecute(NULL,"open",strBatPath.GetBuffer(0),NULL,NULL,SW_SHOWNORMAL); 
			PROCESS_INFORMATION pi;
			STARTUPINFO si;
			memset(&si,0,sizeof(si));
			si.cb=sizeof(si);
			si.wShowWindow=SW_SHOW;
			si.dwFlags=STARTF_USESHOWWINDOW;
			BOOL fRet=CreateProcess(NULL,
									strBatPath.GetBuffer(0),
									NULL,
									NULL,
									FALSE,
									NORMAL_PRIORITY_CLASS|CREATE_NEW_CONSOLE,
									NULL,
									NULL,
									&si,
									&pi);
			if(!fRet)   
			{   
				int errorNo = ::GetLastError();
				AfxMessageBox("create process failed");     
			}
			else
			{
				::WaitForSingleObject(pi.hProcess, INFINITE); 
				fstream a;
				int i,count,len;
				i=0;count=0;
				for(i=0;i<11;i++)
				{
					StrShowData[i]="";
				}
				CString StrBuf;
				char fg[700];
				a.open(StrlogPath.GetBuffer(0),ios::in);
				while(!a.eof())
				{
					a.getline(fg,500);
					for(i=0;i<10;i++)
					{
						StrBuf="";
						StrBuf=fg;
						len=StrCheckData[i].GetLength();
						StrBuf=StrBuf.Mid(0,len);
						if(StrCheckData[i]==StrBuf)
						{
							StrBuf=fg;
							StrBuf=StrBuf.Mid(len);
							if(i==4)
							{
								count++;
								if(count<2)
								{
									StrShowData[i]=StrBuf;
								}
								else
								{
									StrShowData[10]=StrBuf;
								}
							}
							else
							{
								StrShowData[i]=StrBuf;
							}
							break;
						}
					}
				}
			}
		}
	}
	CShowInfoDlg SID(this);
	SID.DoModal();
}
