// AutoBackupDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AutoBackup.h"
#include "AutoBackupDlg.h"
#include <fstream.h>
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
// CAutoBackupDlg dialog

CAutoBackupDlg::CAutoBackupDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAutoBackupDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAutoBackupDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAutoBackupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAutoBackupDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAutoBackupDlg, CDialog)
	//{{AFX_MSG_MAP(CAutoBackupDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Findfolders, OnFindfolders)
	ON_BN_CLICKED(IDC_FindWord, OnFindWord)
	ON_BN_CLICKED(IDC_FindExcel, OnFindExcel)
	ON_BN_CLICKED(IDC_FindPowerPoint1, OnFindPowerPoint1)
	ON_BN_CLICKED(IDC_FindPowerPoint2, OnFindPowerPoint2)
	ON_BN_CLICKED(IDC_FindWinZip, OnFindWinZip)
	ON_BN_CLICKED(IDC_FindWinRAR, OnFindWinRAR)
	ON_BN_CLICKED(IDC_FindAccess, OnFindAccess)
	ON_BN_CLICKED(IDC_FindMXF, OnFindMXF)
	ON_BN_CLICKED(IDC_FindName, OnFindName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoBackupDlg message handlers

BOOL CAutoBackupDlg::OnInitDialog()
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

void CAutoBackupDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAutoBackupDlg::OnPaint() 
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
HCURSOR CAutoBackupDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAutoBackupDlg::OnFindfolders() 
{
	// TODO: Add your control notification handler code here
	CString str;
	CButton *But1;
	BROWSEINFO bi;
	char name[MAX_PATH];
	ZeroMemory(&bi,sizeof(BROWSEINFO));
	bi.hwndOwner=GetSafeHwnd();
	bi.pszDisplayName=name;
	bi.lpszTitle="Select folder";
	//bi.ulFlags=BIF_BROWSEINCLUDEURLS;
	LPITEMIDLIST idl=SHBrowseForFolder(&bi);
	if(idl==NULL)
	{
		MessageBox("Not select folders....");
		return;
	}
	SHGetPathFromIDList(idl,str.GetBuffer(MAX_PATH));
	str.ReleaseBuffer();
	UpdateData(true);
	m_StrRoot=str;
	if(str!="")
	{
		But1=(CButton *)this->GetDlgItem(IDC_Findfolders); 
		But1->EnableWindow(false); 
		But1=NULL;
		if(str.GetAt(str.GetLength()-1)!='\\')
			m_StrRoot+="\\";
		//MessageBox(m_StrRoot);
		pf=fopen("folders.txt","w");
		fprintf(pf,"%s\n",m_StrRoot.GetBuffer(0));
		fclose(pf);
		pf=NULL;
		BrowseDir(m_StrRoot);
		pf=fopen("Files.txt","w");
		fclose(pf);
		pf=NULL;
		MessageBox("finished....");
	}
	else
	{
		MessageBox("Not select folders....");
	}
}
void CAutoBackupDlg::BrowseDir(CString strDir)
{
	CFileFind ff;
	CString szDir = strDir;
	CString StrBuf;
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
			StrBuf=ff.GetFilePath();
			pf=fopen("folders.txt","a");
			fprintf(pf,"%s\n",StrBuf.GetBuffer(0));
			fclose(pf);
			pf=NULL;
			BrowseDir(ff.GetFilePath());
		}
	}
	ff.Close();//關閉
}
void CAutoBackupDlg::BrowseFile(CString strDir,CString strfile,bool blnchecktype)
{
	CFileFind ff;
	CString szDir = strDir;
	CString StrBuf1,StrBuf2;
	if(szDir.Right(1) != "\\")
		szDir += "\\";
	
	szDir += "*.*";
	
	BOOL res = ff.FindFile(szDir);
	while(res)
	{
		res = ff.FindNextFile();
		if(!ff.IsDirectory() && !ff.IsDots())
		{
			//為檔案
			StrBuf1.Format("%s",ff.GetFilePath());
			if(blnchecktype==true)
			{
				StrBuf2=StrBuf1.Mid((StrBuf1.GetLength()-3),3);
			}
			else
			{
				StrBuf2=ff.GetFileName();
				StrBuf2=StrBuf2.Mid(0,strfile.GetLength()); 
			}
			if(StrBuf2==strfile)
			{
				pf=fopen("Files.txt","a");
				fprintf(pf,"%s\n",StrBuf1.GetBuffer(0));
				fclose(pf);
				pf=NULL;
			}
			StrBuf1="";
			StrBuf2="";
			//Sleep(500);
		}
	}
	ff.Close();//關閉
}

void CAutoBackupDlg::OnFindWord() 
{
	// TODO: Add your control notification handler code here
	fstream a;
	CString StrBuf;
	CButton *But1;
	But1=(CButton *)this->GetDlgItem(IDC_FindWord); 
	But1->EnableWindow(false); 
	But1=NULL;
	a.open("folders.txt",ios::in);
	while(!a.eof())
	{
		StrBuf="";
		a.getline(StrBuf.GetBuffer(0),400);
		//a>>StrBuf.GetBuffer(0);
		if(StrBuf!="")
			BrowseFile(StrBuf,"doc");
	}
	MessageBox("finished....");
}

void CAutoBackupDlg::OnFindExcel() 
{
	// TODO: Add your control notification handler code here
	fstream a;
	CString StrBuf;
	CButton *But1;
	But1=(CButton *)this->GetDlgItem(IDC_FindExcel); 
	But1->EnableWindow(false); 
	But1=NULL;
	a.open("folders.txt",ios::in);
	while(!a.eof())
	{
		StrBuf="";
		a.getline(StrBuf.GetBuffer(0),400);
		//a>>StrBuf.GetBuffer(0);
		if(StrBuf!="")
			BrowseFile(StrBuf,"xls");
	}
	MessageBox("finished....");	
}

void CAutoBackupDlg::OnFindPowerPoint1() 
{
	// TODO: Add your control notification handler code here
	fstream a;
	CString StrBuf;
	CButton *But1;
	But1=(CButton *)this->GetDlgItem(IDC_FindPowerPoint1); 
	But1->EnableWindow(false); 
	But1=NULL;
	a.open("folders.txt",ios::in);
	while(!a.eof())
	{
		StrBuf="";
		a.getline(StrBuf.GetBuffer(0),400);
		//a>>StrBuf.GetBuffer(0);
		if(StrBuf!="")
			BrowseFile(StrBuf,"ppt");
	}
	MessageBox("finished....");		
}

void CAutoBackupDlg::OnFindPowerPoint2() 
{
	// TODO: Add your control notification handler code here
	fstream a;
	CString StrBuf;
	CButton *But1;
	But1=(CButton *)this->GetDlgItem(IDC_FindPowerPoint2); 
	But1->EnableWindow(false); 
	But1=NULL;
	a.open("folders.txt",ios::in);
	while(!a.eof())
	{
		StrBuf="";
		a.getline(StrBuf.GetBuffer(0),400);
		//a>>StrBuf.GetBuffer(0);
		if(StrBuf!="")
			BrowseFile(StrBuf,"pps");
	}
	MessageBox("finished....");		
}

void CAutoBackupDlg::OnFindWinZip() 
{
	// TODO: Add your control notification handler code here
	fstream a;
	CString StrBuf;
	CButton *But1;
	But1=(CButton *)this->GetDlgItem(IDC_FindWinZip); 
	But1->EnableWindow(false); 
	But1=NULL;
	a.open("folders.txt",ios::in);
	while(!a.eof())
	{
		StrBuf="";
		a.getline(StrBuf.GetBuffer(0),400);
		//a>>StrBuf.GetBuffer(0);
		if(StrBuf!="")
			BrowseFile(StrBuf,"zip");
	}
	MessageBox("finished....");		
}

void CAutoBackupDlg::OnFindWinRAR() 
{
	// TODO: Add your control notification handler code here
	fstream a;
	CString StrBuf;
	CButton *But1;
	But1=(CButton *)this->GetDlgItem(IDC_FindWinRAR); 
	But1->EnableWindow(false); 
	But1=NULL;
	a.open("folders.txt",ios::in);
	while(!a.eof())
	{
		StrBuf="";
		a.getline(StrBuf.GetBuffer(0),400);
		//a>>StrBuf.GetBuffer(0);
		if(StrBuf!="")
			BrowseFile(StrBuf,"rar");
	}
	MessageBox("finished....");		
}

void CAutoBackupDlg::OnFindAccess() 
{
	// TODO: Add your control notification handler code here
	fstream a;
	CString StrBuf;
	CButton *But1;
	But1=(CButton *)this->GetDlgItem(IDC_FindAccess); 
	But1->EnableWindow(false); 
	But1=NULL;
	a.open("folders.txt",ios::in);
	while(!a.eof())
	{
		StrBuf="";
		a.getline(StrBuf.GetBuffer(0),400);
		//a>>StrBuf.GetBuffer(0);
		if(StrBuf!="")
			BrowseFile(StrBuf,"mdb");
	}
	MessageBox("finished....");		
}

void CAutoBackupDlg::OnFindMXF() 
{
	// TODO: Add your control notification handler code here
	fstream a;
	CString StrBuf;
	CButton *But1;
	But1=(CButton *)this->GetDlgItem(IDC_FindMXF); 
	But1->EnableWindow(false); 
	But1=NULL;
	a.open("folders.txt",ios::in);
	while(!a.eof())
	{
		StrBuf="";
		a.getline(StrBuf.GetBuffer(0),400);
		//a>>StrBuf.GetBuffer(0);
		if(StrBuf!="")
			BrowseFile(StrBuf,"mxf");
	}
	MessageBox("finished....");		
}

void CAutoBackupDlg::OnFindName() 
{
	// TODO: Add your control notification handler code here
	fstream a;
	CString StrBuf;
	CString StrName;
	CButton *But1;
	CEdit *Edit1;
	Edit1=(CEdit *)this->GetDlgItem(IDC_EDIT1); 
	Edit1->EnableWindow(false);
	Edit1->GetWindowText(StrName); 
	But1=(CButton *)this->GetDlgItem(IDC_FindName); 
	But1->EnableWindow(false); 
	But1=NULL;
	a.open("folders.txt",ios::in);
	while(!a.eof())
	{
		StrBuf="";
		a.getline(StrBuf.GetBuffer(0),400);
		//a>>StrBuf.GetBuffer(0);
		if(StrBuf!="")
			BrowseFile(StrBuf,StrName,false);
	}
	MessageBox("finished....");		
}
