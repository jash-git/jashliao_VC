// MultiThreadFTPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MultiThreadFTP.h"
#include "MultiThreadFTPDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CString sCmdLine;
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
// CMultiThreadFTPDlg dialog

CMultiThreadFTPDlg::CMultiThreadFTPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMultiThreadFTPDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMultiThreadFTPDlg)
	m_StrIP00 = _T("");
	m_StrIP01 = _T("");
	m_StrIP02 = _T("");
	m_StrIP03 = _T("");
	m_StrIP04 = _T("");
	m_StrIPCount = _T("");
	m_StrIPSum = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMultiThreadFTPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMultiThreadFTPDlg)
	DDX_Text(pDX, IDC_IP00, m_StrIP00);
	DDX_Text(pDX, IDC_IP01, m_StrIP01);
	DDX_Text(pDX, IDC_IP02, m_StrIP02);
	DDX_Text(pDX, IDC_IP03, m_StrIP03);
	DDX_Text(pDX, IDC_IP04, m_StrIP04);
	DDX_Text(pDX, IDC_IPCount, m_StrIPCount);
	DDX_Text(pDX, IDC_IPSum, m_StrIPSum);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMultiThreadFTPDlg, CDialog)
	//{{AFX_MSG_MAP(CMultiThreadFTPDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiThreadFTPDlg message handlers

BOOL CMultiThreadFTPDlg::OnInitDialog()
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
	m_intStep=0;
	m_intSum=0;
	m_intCount=0;
	SetTimer(1,1000,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMultiThreadFTPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMultiThreadFTPDlg::OnPaint() 
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
HCURSOR CMultiThreadFTPDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMultiThreadFTPDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(m_intStep)
	{
		case 0://Read List File
			KillTimer(1);
			m_intStep=1;
			ReadListFile();
			SetTimer(1,1000,NULL);
			break;
		case 1://Get IP
			KillTimer(1);
			m_intThreadCount=0;
			m_intThreadCount=GetIPData();
			//ShowIPData();
			m_intStep=2;
			SetTimer(1,1000,NULL);
			break;
		case 2:// Create Thread and Show Data
			KillTimer(1);
			ShowIPData();
			m_intThreadSum=0;
			switch(m_intThreadCount)
			{
				case 1:
					AfxBeginThread(Thread00,this,0,0,0,NULL);
					break;
				case 2:
					AfxBeginThread(Thread00,this,0,0,0,NULL);
					AfxBeginThread(Thread01,this,0,0,0,NULL);
					break;
				case 3:
					AfxBeginThread(Thread00,this,0,0,0,NULL);
					AfxBeginThread(Thread01,this,0,0,0,NULL);
					AfxBeginThread(Thread02,this,0,0,0,NULL);
					break;
				case 4:
					AfxBeginThread(Thread00,this,0,0,0,NULL);
					AfxBeginThread(Thread01,this,0,0,0,NULL);
					AfxBeginThread(Thread02,this,0,0,0,NULL);
					AfxBeginThread(Thread03,this,0,0,0,NULL);
					break;
				case 5:
					AfxBeginThread(Thread00,this,0,0,0,NULL);
					AfxBeginThread(Thread01,this,0,0,0,NULL);
					AfxBeginThread(Thread02,this,0,0,0,NULL);
					AfxBeginThread(Thread03,this,0,0,0,NULL);
					AfxBeginThread(Thread04,this,0,0,0,NULL);
					break;
			}
			m_intStep=3;
			SetTimer(1,1000,NULL);
			break;
		case 3:// Wait Thread
			KillTimer(1);
			WaitThread();
			SetTimer(1,1000,NULL);
			break;
		case 4:// Check Data
			KillTimer(1);
			if((m_intSum-m_intCount)>0)
			{
				m_intStep=1;
				SetTimer(1,1000,NULL);
			}
			else
			{
				this->OnOK();
				//MessageBox("Finish...");
			}
			break;
	}
	CDialog::OnTimer(nIDEvent);
}
void CMultiThreadFTPDlg::Thread00Fun()
{
	FILE *pflog;
	CString StrLogName;
	CFtpConnection *m_pFtpConnection; //FTP_2
	CString StrIP=StrShowData[0];
	StrLogName=StrIP;
	StrLogName+="log.txt";
	pflog=fopen(StrLogName.GetBuffer(0),"a");
	::CreateDirectory(StrIP,NULL);
	CInternetSession Session;//FTP_3
	try 
	{ 
		//m_pFtpConnection=m_pInetSession->GetFtpConnection("FTP.MICROSOFT.COM");
		m_pFtpConnection=Session.GetFtpConnection(StrIP,"jovi","jovi"); 
	} 
	catch(CInternetException *pEx) 
	{ 
		TCHAR szError[1024]; 
		if(pEx->GetErrorMessage(szError,1024)) 
			//AfxMessageBox(szError); 
			fprintf(pflog,"%s\n",szError);
		else 
			fprintf(pflog,"%s\n","There was an exception"); 
			pEx->Delete(); 
		m_pFtpConnection=NULL;
	}
	if(m_pFtpConnection!=NULL)
	{
		if(m_pFtpConnection->SetCurrentDirectory(".//broadcast//社資_log//"))
		{
			CFtpFileFind Find(m_pFtpConnection);
			CString StrBuf;
			CString StrDir;
			BOOL ret;
			long lngCount=0;
			ret=Find.FindFile(NULL,INTERNET_FLAG_EXISTING_CONNECT);
			if(ret)
			{
				while(Find.FindNextFile())
				{
					StrBuf=Find.GetFileName();
					if(m_pFtpConnection->GetFile(StrBuf,StrBuf,true,FILE_ATTRIBUTE_NORMAL,FTP_TRANSFER_TYPE_BINARY,1))
					{
						lngCount++;
						m_pFtpConnection->Remove(StrBuf);
						StrDir=StrIP+"\\";
						StrDir+=StrBuf;
						if(::CopyFile(StrBuf,StrDir,true))
						{
							::DeleteFile(StrBuf);
							fprintf(pflog,"%s\n",StrBuf.GetBuffer(0));
						}
					}
				}
				StrBuf.Format("Find and Download %d Files...",lngCount);
				fprintf(pflog,"%s\n",StrBuf.GetBuffer(0));
			}
			else
			{
				fprintf(pflog,"%s\n","Find 0 Files... ");
			}
		}
		else
		{
			fprintf(pflog,"%s\n","Do not change CurrentDirectory...");
		}
	}
	//FTP_4
	if(m_pFtpConnection!=NULL) 
	{ 
		m_pFtpConnection->Close(); 
		delete m_pFtpConnection; 
	} 
	m_intThreadSum+=2;
}
void CMultiThreadFTPDlg::Thread01Fun()
{
	FILE *pflog;
	CString StrLogName;
	CFtpConnection *m_pFtpConnection; //FTP_2
	CString StrIP=StrShowData[1];
	StrLogName=StrIP;
	StrLogName+="log.txt";
	pflog=fopen(StrLogName.GetBuffer(0),"a");
	::CreateDirectory(StrIP,NULL);
	CInternetSession Session;//FTP_3
	try 
	{ 
		//m_pFtpConnection=m_pInetSession->GetFtpConnection("FTP.MICROSOFT.COM");
		m_pFtpConnection=Session.GetFtpConnection(StrIP,"jovi","jovi"); 
	} 
	catch(CInternetException *pEx) 
	{ 
		TCHAR szError[1024]; 
		if(pEx->GetErrorMessage(szError,1024)) 
			//AfxMessageBox(szError); 
			fprintf(pflog,"%s\n",szError);
		else 
			fprintf(pflog,"%s\n","There was an exception"); 
			pEx->Delete(); 
		m_pFtpConnection=NULL;
	}
	if(m_pFtpConnection!=NULL)
	{
		if(m_pFtpConnection->SetCurrentDirectory(".//broadcast//社資_log//"))
		{
			CFtpFileFind Find(m_pFtpConnection);
			CString StrBuf;
			CString StrDir;
			BOOL ret;
			long lngCount=0;
			ret=Find.FindFile(NULL,INTERNET_FLAG_EXISTING_CONNECT);
			if(ret)
			{
				while(Find.FindNextFile())
				{
					StrBuf=Find.GetFileName();
					if(m_pFtpConnection->GetFile(StrBuf,StrBuf,true,FILE_ATTRIBUTE_NORMAL,FTP_TRANSFER_TYPE_BINARY,1))
					{
						lngCount++;
						m_pFtpConnection->Remove(StrBuf);
						StrDir=StrIP+"\\";
						StrDir+=StrBuf;
						if(::CopyFile(StrBuf,StrDir,true))
						{
							::DeleteFile(StrBuf);
							fprintf(pflog,"%s\n",StrBuf.GetBuffer(0));
						}
					}
				}
				StrBuf.Format("Find and Download %d Files...",lngCount);
				fprintf(pflog,"%s\n",StrBuf.GetBuffer(0));
			}
			else
			{
				fprintf(pflog,"%s\n","Find 0 Files... ");
			}
		}
		else
		{
			fprintf(pflog,"%s\n","Do not change CurrentDirectory...");
		}
	}
	//FTP_4
	if(m_pFtpConnection!=NULL) 
	{ 
		m_pFtpConnection->Close(); 
		delete m_pFtpConnection; 
	} 
	m_intThreadSum+=4;
}
void CMultiThreadFTPDlg::Thread02Fun()
{
	FILE *pflog;
	CString StrLogName;
	CFtpConnection *m_pFtpConnection; //FTP_2
	CString StrIP=StrShowData[2];
	StrLogName=StrIP;
	StrLogName+="log.txt";
	pflog=fopen(StrLogName.GetBuffer(0),"a");
	::CreateDirectory(StrIP,NULL);
	CInternetSession Session;//FTP_3
	try 
	{ 
		//m_pFtpConnection=m_pInetSession->GetFtpConnection("FTP.MICROSOFT.COM");
		m_pFtpConnection=Session.GetFtpConnection(StrIP,"jovi","jovi"); 
	} 
	catch(CInternetException *pEx) 
	{ 
		TCHAR szError[1024]; 
		if(pEx->GetErrorMessage(szError,1024)) 
			//AfxMessageBox(szError); 
			fprintf(pflog,"%s\n",szError);
		else 
			fprintf(pflog,"%s\n","There was an exception"); 
			pEx->Delete(); 
		m_pFtpConnection=NULL;
	}
	if(m_pFtpConnection!=NULL)
	{
		if(m_pFtpConnection->SetCurrentDirectory(".//broadcast//社資_log//"))
		{
			CFtpFileFind Find(m_pFtpConnection);
			CString StrBuf;
			CString StrDir;
			BOOL ret;
			long lngCount=0;
			ret=Find.FindFile(NULL,INTERNET_FLAG_EXISTING_CONNECT);
			if(ret)
			{
				while(Find.FindNextFile())
				{
					StrBuf=Find.GetFileName();
					if(m_pFtpConnection->GetFile(StrBuf,StrBuf,true,FILE_ATTRIBUTE_NORMAL,FTP_TRANSFER_TYPE_BINARY,1))
					{
						lngCount++;
						m_pFtpConnection->Remove(StrBuf);
						StrDir=StrIP+"\\";
						StrDir+=StrBuf;
						if(::CopyFile(StrBuf,StrDir,true))
						{
							::DeleteFile(StrBuf);
							fprintf(pflog,"%s\n",StrBuf.GetBuffer(0));
						}
					}
				}
				StrBuf.Format("Find and Download %d Files...",lngCount);
				fprintf(pflog,"%s\n",StrBuf.GetBuffer(0));
			}
			else
			{
				fprintf(pflog,"%s\n","Find 0 Files... ");
			}
		}
		else
		{
			fprintf(pflog,"%s\n","Do not change CurrentDirectory...");
		}
	}
	//FTP_4
	if(m_pFtpConnection!=NULL) 
	{ 
		m_pFtpConnection->Close(); 
		delete m_pFtpConnection; 
	} 
	m_intThreadSum+=8;
}
void CMultiThreadFTPDlg::Thread03Fun()
{
	FILE *pflog;
	CString StrLogName;
	CFtpConnection *m_pFtpConnection; //FTP_2
	CString StrIP=StrShowData[3];
	StrLogName=StrIP;
	StrLogName+="log.txt";
	pflog=fopen(StrLogName.GetBuffer(0),"a");
	::CreateDirectory(StrIP,NULL);
	CInternetSession Session;//FTP_3
	try 
	{ 
		//m_pFtpConnection=m_pInetSession->GetFtpConnection("FTP.MICROSOFT.COM");
		m_pFtpConnection=Session.GetFtpConnection(StrIP,"jovi","jovi"); 
	} 
	catch(CInternetException *pEx) 
	{ 
		TCHAR szError[1024]; 
		if(pEx->GetErrorMessage(szError,1024)) 
			//AfxMessageBox(szError); 
			fprintf(pflog,"%s\n",szError);
		else 
			fprintf(pflog,"%s\n","There was an exception"); 
			pEx->Delete(); 
		m_pFtpConnection=NULL;
	}
	if(m_pFtpConnection!=NULL)
	{
		if(m_pFtpConnection->SetCurrentDirectory(".//broadcast//社資_log//"))
		{
			CFtpFileFind Find(m_pFtpConnection);
			CString StrBuf;
			CString StrDir;
			BOOL ret;
			long lngCount=0;
			ret=Find.FindFile(NULL,INTERNET_FLAG_EXISTING_CONNECT);
			if(ret)
			{
				while(Find.FindNextFile())
				{
					StrBuf=Find.GetFileName();
					if(m_pFtpConnection->GetFile(StrBuf,StrBuf,true,FILE_ATTRIBUTE_NORMAL,FTP_TRANSFER_TYPE_BINARY,1))
					{
						lngCount++;
						m_pFtpConnection->Remove(StrBuf);
						StrDir=StrIP+"\\";
						StrDir+=StrBuf;
						if(::CopyFile(StrBuf,StrDir,true))
						{
							::DeleteFile(StrBuf);
							fprintf(pflog,"%s\n",StrBuf.GetBuffer(0));
						}
					}
				}
				StrBuf.Format("Find and Download %d Files...",lngCount);
				fprintf(pflog,"%s\n",StrBuf.GetBuffer(0));
			}
			else
			{
				fprintf(pflog,"%s\n","Find 0 Files... ");
			}
		}
		else
		{
			fprintf(pflog,"%s\n","Do not change CurrentDirectory...");
		}
	}
	//FTP_4
	if(m_pFtpConnection!=NULL) 
	{ 
		m_pFtpConnection->Close(); 
		delete m_pFtpConnection; 
	} 
	m_intThreadSum+=16;
}
void CMultiThreadFTPDlg::Thread04Fun()
{
	FILE *pflog;
	CString StrLogName;
	CFtpConnection *m_pFtpConnection; //FTP_2
	CString StrIP=StrShowData[4];
	StrLogName=StrIP;
	StrLogName+="log.txt";
	pflog=fopen(StrLogName.GetBuffer(0),"a");
	::CreateDirectory(StrIP,NULL);
	CInternetSession Session;//FTP_3
	try 
	{ 
		//m_pFtpConnection=m_pInetSession->GetFtpConnection("FTP.MICROSOFT.COM");
		m_pFtpConnection=Session.GetFtpConnection(StrIP,"jovi","jovi"); 
	} 
	catch(CInternetException *pEx) 
	{ 
		TCHAR szError[1024]; 
		if(pEx->GetErrorMessage(szError,1024)) 
			//AfxMessageBox(szError); 
			fprintf(pflog,"%s\n",szError);
		else 
			fprintf(pflog,"%s\n","There was an exception"); 
			pEx->Delete(); 
		m_pFtpConnection=NULL;
	}
	if(m_pFtpConnection!=NULL)
	{
		if(m_pFtpConnection->SetCurrentDirectory(".//broadcast//社資_log//"))
		{
			CFtpFileFind Find(m_pFtpConnection);
			CString StrBuf;
			CString StrDir;
			BOOL ret;
			long lngCount=0;
			ret=Find.FindFile(NULL,INTERNET_FLAG_EXISTING_CONNECT);
			if(ret)
			{
				while(Find.FindNextFile())
				{
					StrBuf=Find.GetFileName();
					if(m_pFtpConnection->GetFile(StrBuf,StrBuf,true,FILE_ATTRIBUTE_NORMAL,FTP_TRANSFER_TYPE_BINARY,1))
					{
						lngCount++;
						m_pFtpConnection->Remove(StrBuf);
						StrDir=StrIP+"\\";
						StrDir+=StrBuf;
						if(::CopyFile(StrBuf,StrDir,true))
						{
							::DeleteFile(StrBuf);
							fprintf(pflog,"%s\n",StrBuf.GetBuffer(0));
						}
					}
				}
				StrBuf.Format("Find and Download %d Files...",lngCount);
				fprintf(pflog,"%s\n",StrBuf.GetBuffer(0));
			}
			else
			{
				fprintf(pflog,"%s\n","Find 0 Files... ");
			}
		}
		else
		{
			fprintf(pflog,"%s\n","Do not change CurrentDirectory...");
		}
	}
	//FTP_4
	if(m_pFtpConnection!=NULL) 
	{ 
		m_pFtpConnection->Close(); 
		delete m_pFtpConnection; 
	} 
	m_intThreadSum+=32;
}
UINT CMultiThreadFTPDlg::Thread00(LPVOID lpram)
{
	CMultiThreadFTPDlg *u=(CMultiThreadFTPDlg *)lpram;
	u->Thread00Fun();
	return 0;
}
UINT CMultiThreadFTPDlg::Thread01(LPVOID lpram)
{
	CMultiThreadFTPDlg *u=(CMultiThreadFTPDlg *)lpram;
	u->Thread01Fun();
	return 0;
}
UINT CMultiThreadFTPDlg::Thread02(LPVOID lpram)
{
	CMultiThreadFTPDlg *u=(CMultiThreadFTPDlg *)lpram;
	u->Thread02Fun();
	return 0;
}
UINT CMultiThreadFTPDlg::Thread03(LPVOID lpram)
{
	CMultiThreadFTPDlg *u=(CMultiThreadFTPDlg *)lpram;
	u->Thread03Fun();
	return 0;
}
UINT CMultiThreadFTPDlg::Thread04(LPVOID lpram)
{
	CMultiThreadFTPDlg *u=(CMultiThreadFTPDlg *)lpram;
	u->Thread04Fun();
	return 0;
}
void CMultiThreadFTPDlg::WaitThread()
{
	m_intCheckThread=0;
	switch(m_intThreadCount)
	{
		case 1:
			m_intCheckThread=2;
			break;
		case 2:
			m_intCheckThread=(2+4);
			break;
		case 3:
			m_intCheckThread=(2+4+8);
			break;
		case 4:
			m_intCheckThread=(2+4+8+16);
			break;
		case 5:
			m_intCheckThread=(2+4+8+16+32);
			break;
	}
	if(m_intThreadSum==m_intCheckThread)
	{
		m_intStep=4;
	}
	else
	{
		m_intStep=3;
	}
}
void CMultiThreadFTPDlg::ShowIPData()
{
	UpdateData(true);
		m_StrIP00=StrShowData[0];
		m_StrIP01=StrShowData[1];
		m_StrIP02=StrShowData[2];
		m_StrIP03=StrShowData[3];
		m_StrIP04=StrShowData[4];
	UpdateData(false);
}
int CMultiThreadFTPDlg::GetIPData()
{
	int j=0;
	int i=0;
	CString StrBuf;
	if((m_intSum-m_intCount)>=5)
	{
		j=5;
	}
	else
	{
		j=m_intSum-m_intCount;
	}
	for(i=0;i<5;i++)
	{
		StrShowData[i]="";
	}
	for(i=0;i<j;i++)
	{
		StrBuf=m_ArrayListIP.GetAt(m_intCount);
		StrShowData[i]=StrBuf;
		m_intCount++;
	}
	UpdateData(true);
		m_StrIPCount.Format("%d",m_intCount);
	UpdateData(false);
	return j;
}
void CMultiThreadFTPDlg::ReadListFile()
{
	FILE *pf;
	char chrData[50];
	m_ArrayListIP.RemoveAll();
	CString StrBuf;
	m_intSum=0;
	if(sCmdLine=="")
	{
		pf=fopen("ListIP.txt","r");
	}
	else
	{
		pf=fopen(sCmdLine.GetBuffer(0),"r");
	}
	if(pf!=NULL)
	{
		while(fscanf(pf,"%s",chrData)!=EOF)
		{
			StrBuf="";
			StrBuf=chrData;
			if(StrBuf!="")
			{
				m_ArrayListIP.Add(StrBuf);
			}
		}
		m_intSum=m_ArrayListIP.GetSize();
		fclose(pf);
	}
	UpdateData(true);
		m_StrIPCount.Format("%d",m_intCount);
		m_StrIPSum.Format("%d",m_intSum);
	UpdateData(false);
}
