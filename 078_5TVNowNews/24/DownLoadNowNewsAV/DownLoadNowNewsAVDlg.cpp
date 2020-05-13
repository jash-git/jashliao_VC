// DownLoadNowNewsAVDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DownLoadNowNewsAV.h"
#include "DownLoadNowNewsAVDlg.h"
#include "DlgProxy.h"
#include <stdio.h>
#include <fstream.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define BUFFER_SIZE 2048//Step 3:Http
TCHAR gstrCurDrt[500];//存放目其目錄字串
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
// CDownLoadNowNewsAVDlg dialog

IMPLEMENT_DYNAMIC(CDownLoadNowNewsAVDlg, CDialog);

CDownLoadNowNewsAVDlg::CDownLoadNowNewsAVDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDownLoadNowNewsAVDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDownLoadNowNewsAVDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CDownLoadNowNewsAVDlg::~CDownLoadNowNewsAVDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CDownLoadNowNewsAVDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownLoadNowNewsAVDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownLoadNowNewsAVDlg, CDialog)
	//{{AFX_MSG_MAP(CDownLoadNowNewsAVDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDownLoadNowNewsAVDlg message handlers

BOOL CDownLoadNowNewsAVDlg::OnInitDialog()
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
	SetTimer(1,100,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDownLoadNowNewsAVDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDownLoadNowNewsAVDlg::OnPaint() 
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
HCURSOR CDownLoadNowNewsAVDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CDownLoadNowNewsAVDlg::OnClose() 
{
	if (CanExit())
		CDialog::OnClose();
}

void CDownLoadNowNewsAVDlg::OnOK() 
{
	if (CanExit())
		CDialog::OnOK();
}

void CDownLoadNowNewsAVDlg::OnCancel() 
{
	if (CanExit())
		CDialog::OnCancel();
}

BOOL CDownLoadNowNewsAVDlg::CanExit()
{
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}
CString CDownLoadNowNewsAVDlg::GetFileName(CString Strdata)
{
	int i,intnumber;
	CString Strbuf;
	intnumber=Strdata.GetLength();
	Strbuf="";
	for(i=(intnumber-1);i>=0;i--)
	{
		if(Strdata.Mid(i,1)!="/")
		{
			Strbuf=Strdata.Mid(i,1)+Strbuf;

		}
		else
		{
			break;
		}
	}
	return Strbuf;
}
bool CDownLoadNowNewsAVDlg::GetWebFile(CString theUrl, CString Filename)//Step 4:Http
{
    CInternetSession session;
	CTime t1=CTime::GetCurrentTime();
    CInternetFile* file = NULL;
	CString StrBuf;
	StrBuf.Format("%d%d%d%d%d%d",t1.GetYear(),t1.GetMonth(),t1.GetDay(),t1.GetHour(),t1.GetMinute(),t1.GetSecond());          
    try
    {
        // Try to connect with the URL
		theUrl=theUrl+"?aa=";
		theUrl=theUrl+StrBuf;
        file = (CInternetFile*)session.OpenURL(theUrl); 
    }
    catch (CInternetException* m_pException)
    {
        // if some error occurs, set the file with NULL
        file = NULL; 
        m_pException->Delete();
        return FALSE;
    }

    BOOL bRet = FALSE;
    // use dataStore to save the file content
    CStdioFile dataStore;
    if(dataStore.Open(Filename, CFile::modeCreate | CFile::modeWrite | CFile::shareDenyWrite | CFile::typeBinary))
    {
        if (file)
        {
            UINT somelen = 0;
            BYTE somecode[BUFFER_SIZE];
            while((somelen = file->Read(somecode, BUFFER_SIZE)) > 0)
            {
                dataStore.Write(somecode, somelen);
            }
            bRet = TRUE;
        }
        dataStore.Close();
    }
    if(file)
    {
        file->Close();
        delete file;
    }
    return bRet;
}
bool CDownLoadNowNewsAVDlg::WgetFtp2WMV()
{
		int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
		if( gstrCurDrt[nLen]!='\\' )
		{
			gstrCurDrt[nLen++] = '\\';
			gstrCurDrt[nLen] = '\0';
		}
		CString StrCallExeName;
		StrCallExeName=gstrCurDrt;
		StrCallExeName+="WgetFtp2Wmv.bat";
		PROCESS_INFORMATION pi;
		STARTUPINFO si;
		memset(&si,0,sizeof(si));
		si.cb=sizeof(si);
		si.wShowWindow=SW_MINIMIZE;
		si.dwFlags=STARTF_USESHOWWINDOW;
		BOOL fRet=CreateProcess(NULL,
								StrCallExeName.GetBuffer(0),
								NULL,
								NULL,
								FALSE,
								NORMAL_PRIORITY_CLASS|CREATE_NEW_CONSOLE,
								NULL,
								NULL,
								&si,
								&pi);
		if(fRet)
		{
			WaitForSingleObject(pi.hProcess,INFINITE);
		}
		return true;
}
void CDownLoadNowNewsAVDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(1);
	//MessageBox("OK");
	CTime timeNow=CTime::GetCurrentTime();
	CString StrBuf,StrBuf1,StrBuf2,StrBuf3;
	CString StrConvertWMV,StrWMVFileName;
	CString StrDelFile;
	char chrd1[100],chrd2[100],chrd3[100],chrd4[100],chrd5[100],chrd6[100];
	CString StrAll;
	fstream f1,f2;
	FILE *pf,*pf1,*pf2;
	char chrdata[500];
	bool blntodayfirst=false;
	bool blncheckdata=false;
	bool blnCallAP=false;
	int i,j,k,l;
	////////////////////////////////////////
	StrBuf1=timeNow.Format("%Y%m%d");
	StrBuf1+=".txt";
	////////////////////////////////////////
	StrBuf2=timeNow.Format("%Y%m%d");
	StrBuf2+="old.txt";
	/////////////////////////////////////////
	//f2.open(StrBuf2.GetBuffer(0),ios::in);
	m_Array1.RemoveAll();
	m_Array2.RemoveAll();
	m_Array3.RemoveAll();
	pf=fopen(StrBuf2.GetBuffer(0),"r");
	if(pf)
	{
		fclose(pf);
		f1.open(StrBuf1.GetBuffer(0),ios::in);
		f2.open(StrBuf2.GetBuffer(0),ios::in);
		while(!f1.eof())
		{
			f1.getline(chrdata,500);
			StrAll=chrdata;
			m_Array1.Add(StrAll); 
		}
		while(!f2.eof())
		{
			f2.getline(chrdata,500);
			StrAll=chrdata;
			m_Array2.Add(StrAll); 
		}
		blntodayfirst=false;
	}
	else
	{
		f1.open(StrBuf1.GetBuffer(0),ios::in);
		while(!f1.eof())
		{
			f1.getline(chrdata,500);
			StrAll=chrdata;
			m_Array1.Add(StrAll); 
		}
		blntodayfirst=true;
	}
	f1.close();
	f2.close();
	//////////////////////////////////////
	pf=fopen("filepath.txt","w");
	pf1=fopen("filename.txt","w");
	if(blntodayfirst)
	{
		j=m_Array1.GetSize(); 
		for(i=0;i<j;i++)
		{
			StrBuf1=m_Array1.GetAt(i);
			if(StrBuf1!="")
			{
				sscanf (StrBuf1.GetBuffer(0) ,"%[^ || ] || %s || %s %s || %s || %s",chrd1,chrd2,chrd3,chrd4,chrd5,chrd6);
				StrBuf=chrd6;
				StrBuf3=GetFileName(StrBuf);

				StrBuf="wget.exe \"ftp://jash:chwbnnoc@"+StrBuf;
				StrBuf+="\"";
					
				StrBuf+=" -O ";
				StrBuf+=StrBuf3;

				StrWMVFileName=StrBuf3.Mid(0,(StrBuf3.GetLength()-4));
				StrWMVFileName+=".wmv";
				StrConvertWMV.Format("cscript.exe wmcmd.vbs -input %s -output %s -loadprofile wmv_1m.prx",StrBuf3,StrWMVFileName);

				StrDelFile="Del "+StrBuf3;
				
				pf2=fopen("WgetFtp2Wmv.bat","w");
				fprintf(pf2,"%s\n",StrBuf.GetBuffer(0));
				fprintf(pf2,"%s\n",StrConvertWMV.GetBuffer(0));
				fprintf(pf2,"%s\n",StrDelFile.GetBuffer(0));
				fclose(pf2);
				pf2='\0';

				if(WgetFtp2WMV())//if(GetWebFile(StrBuf,StrBuf3))
				{
					fprintf(pf,"%s\n",StrBuf1.GetBuffer(0));
					fprintf(pf1,"%s\n",StrWMVFileName.GetBuffer(0));//fprintf(pf1,"%s\n",StrBuf3.GetBuffer(0));
					blnCallAP=true;
				}
			}
		}
	}
	else
	{
		j=m_Array1.GetSize();
		l=m_Array2.GetSize();
		for(i=0;i<j;i++)
		{
			blncheckdata=false;
			StrBuf1=m_Array1.GetAt(i);
			for(k=0;k<l;k++)
			{
				StrBuf2=m_Array2.GetAt(k);
				if(StrBuf1==StrBuf2)
				{
					blncheckdata=true;
					break;
				}
			}
			if(!blncheckdata)
			{
				if(StrBuf1!="")
				{
					sscanf (StrBuf1.GetBuffer(0) ,"%[^ || ] || %s || %s %s || %s || %s",chrd1,chrd2,chrd3,chrd4,chrd5,chrd6);
					StrBuf=chrd6;
					StrBuf3=GetFileName(StrBuf);

					StrBuf="wget.exe \"ftp://jash:chwbnnoc@"+StrBuf;
					StrBuf+="\"";
					
					StrBuf+=" -O ";
					StrBuf+=StrBuf3;

					StrWMVFileName=StrBuf3.Mid(0,(StrBuf3.GetLength()-4));
					StrWMVFileName+=".wmv";
					StrConvertWMV.Format("cscript.exe wmcmd.vbs -input %s -output %s -loadprofile wmv_1m.prx",StrBuf3,StrWMVFileName);

					StrDelFile="Del "+StrBuf3;

					pf2=fopen("WgetFtp2Wmv.bat","w");
					fprintf(pf2,"%s\n",StrBuf.GetBuffer(0));
					fprintf(pf2,"%s\n",StrConvertWMV.GetBuffer(0));
					fprintf(pf2,"%s\n",StrDelFile.GetBuffer(0));
					fclose(pf2);
					pf2='\0';

					if(WgetFtp2WMV())//if(GetWebFile(StrBuf,StrBuf3))
					{
						fprintf(pf,"%s\n",StrBuf1.GetBuffer(0));
						fprintf(pf1,"%s\n",StrWMVFileName.GetBuffer(0));//fprintf(pf1,"%s\n",StrBuf3.GetBuffer(0));
						blnCallAP=true;
					}
				}
			}
		}
	}
	fclose(pf);
	fclose(pf1);
	if(blnCallAP)
	{
		ShellExecute(NULL,"open","UpdateNowNewsAV.exe",NULL,NULL,SW_SHOWNORMAL); 
	}
	else
	{
			CString StrAllListFileName;
			fstream fileAllList;
			CTime timeNow=CTime::GetCurrentTime();
			int intAllListCount;
			StrAllListFileName=timeNow.Format("%Y%m%d.txt");
			fileAllList.open(StrAllListFileName.GetBuffer(0),ios::in);
			intAllListCount=-1;//-1是因為檔和最後一行為換行所造成
			while(!fileAllList.eof())
			{
				fileAllList.getline(chrdata,500);
				intAllListCount++;
			}
			fileAllList.close();
			int n;
			char buffer01 [150];
			char buffer02 [150];
			n=sprintf (buffer01, "wget.exe \"http://noc.tw-airnet.net/monitor/wService.aspx?OP=SetServiceStatusByID&ServiceID=320&Status=0&Value=%d\"",intAllListCount);
			n=sprintf (buffer02, "del \"wService.aspx?OP=SetServiceStatusByID&ServiceID=320&Status=0&Value=%d\"",intAllListCount);
			FILE *pf;
			pf=fopen("UpCount.bat","w");
			fprintf(pf,"%s\n%s\n",buffer01,buffer02);
			fclose(pf);
			ShellExecute(NULL,"open","UpCount.bat",NULL,NULL,SW_SHOWNORMAL); 

	}
	this->OnOK(); 
	CDialog::OnTimer(nIDEvent);
}
