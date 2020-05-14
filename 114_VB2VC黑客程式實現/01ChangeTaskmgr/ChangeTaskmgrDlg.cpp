// ChangeTaskmgrDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChangeTaskmgr.h"
#include "ChangeTaskmgrDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//   globals   
HANDLE   hCurrentProcess,   hSelfDeleteThread;   
DWORD   dwSelfDeleteThreadId,   dwExitCode;
DWORD WINAPI tSelfDelete()   
{   
    
	TCHAR   szModule   [MAX_PATH],   
	szComspec[MAX_PATH],   
	szParams   [MAX_PATH];   
	//   get   file   path   names   
	if((GetModuleFileName(0,szModule,MAX_PATH)!=0)&&(GetShortPathName(szModule,szModule,MAX_PATH)!=0)&&(GetEnvironmentVariable("Comspec",szComspec,MAX_PATH)!=0))   
	{   
		//   create   comspec   parameters   
		lstrcpy(szParams,"/c   del   ");   //   run   single   command   to...   
		lstrcat(szParams,   szModule);   //   del(ete)   self   file   and...   
		lstrcat(szParams,   "   >   nul");   //   output   results   to   nowhere    
		//   execute   command   shell   
		//   and   increase   process+thread   priorities   
		if(((INT)ShellExecute(0,0,szComspec,szParams,0,SW_HIDE)   >   32)&&(SetPriorityClass(hCurrentProcess,HIGH_PRIORITY_CLASS))&&(SetThreadPriority(hSelfDeleteThread,THREAD_PRIORITY_HIGHEST)))   
		{   
			//   notify   explorer   shell   
			SHChangeNotify(SHCNE_DELETE,SHCNF_PATH,szModule,0);   
			return   1;   
		}   
	}   
	return   0;   
}
/////////////////////////////////////////////////////////////////////////////
// CChangeTaskmgrDlg dialog

CChangeTaskmgrDlg::CChangeTaskmgrDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChangeTaskmgrDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChangeTaskmgrDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChangeTaskmgrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChangeTaskmgrDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChangeTaskmgrDlg, CDialog)
	//{{AFX_MSG_MAP(CChangeTaskmgrDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RUN, OnRun)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangeTaskmgrDlg message handlers

BOOL CChangeTaskmgrDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CChangeTaskmgrDlg::OnPaint() 
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
HCURSOR CChangeTaskmgrDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CChangeTaskmgrDlg::OnRun() 
{
	// TODO: Add your control notification handler code here
	MessageBox(GetAPPEXEPath());
	MessageBox(FullPath2FileName(GetAPPEXEPath()));

	//-------------------------------------------------------------
	//取得系統目錄
	char   szSystemDirectory[512];
	CString StrSystemDirectory;
	memset(szSystemDirectory,'"0',sizeof(szSystemDirectory));

	GetSystemDirectory(szSystemDirectory,sizeof(szSystemDirectory));

	StrSystemDirectory=szSystemDirectory;
	//---------------------------------------------------------------

	//---------------------------------------------------------------
	//taskmgr rename
	CString StrOldName,StrNewName;

	StrOldName=StrSystemDirectory+"\\taskmgr.exe";
	StrNewName=StrSystemDirectory+"\\taskmgrold.exe";
	
	bool check=false;
	check=CopyFile(StrOldName,StrNewName,true);

	check=false;
	check=CopyFile(GetAPPEXEPath(),StrOldName,false);
	//---------------------------------------------------------------

	//---------------------------------------------------------------
	//kill self
	//   set   current   process   to   "all_access"   
	hCurrentProcess=OpenProcess( PROCESS_ALL_ACCESS,TRUE, GetCurrentProcessId());
	
	//   create   self-delete   thread   
	hSelfDeleteThread=CreateThread(0,0,(LPTHREAD_START_ROUTINE)tSelfDelete,0,0,&dwSelfDeleteThreadId);
	
	//   create   thread   state   loop   
	GetExitCodeThread(hSelfDeleteThread,&dwExitCode);   
	
	while(dwExitCode==STILL_ACTIVE)   
	{   
		GetExitCodeThread(hSelfDeleteThread,&dwExitCode);   
	}       
	
	//   exit   program   stuff   
	CloseHandle(hSelfDeleteThread);   
	CloseHandle(hCurrentProcess);   
	PostQuitMessage(0);   
	//---------------------------------------------------------------


}
CString CChangeTaskmgrDlg::GetAPPEXEPath()//取得目前程式所在完整路徑檔名
{
    char   szFileName[256];
	CString StrReturn;

    memset(szFileName,'"0',sizeof(szFileName));
    GetModuleFileName(NULL,szFileName, sizeof(szFileName));

	StrReturn=szFileName;
	return StrReturn;
}
CString CChangeTaskmgrDlg::FullPath2FileName(CString StrPath)//從全路徑取得檔名
{
    char   seps[]   =   "\\"   ;  
    char   *token   =   NULL; 
    CString StrReturn;
    char exeName[256];

    memset(exeName,'\0',sizeof(exeName));

    token=strtok(StrPath.GetBuffer(0),seps);  
    while(token!=NULL)  
    {  
        sprintf(exeName,"%s",token);
		token=strtok(NULL, seps);              
    }

	StrReturn=exeName;
	return StrReturn;
}