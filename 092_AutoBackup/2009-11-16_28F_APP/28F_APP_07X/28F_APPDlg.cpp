// 28F_APPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "28F_APP.h"
#include "28F_APPDlg.h"
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
// CMy28F_APPDlg dialog

CMy28F_APPDlg::CMy28F_APPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy28F_APPDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy28F_APPDlg)
	m_FileName = _T("Data.txt");
	m_SavePath = _T("");
	m_FilePath = _T("folder.txt");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy28F_APPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy28F_APPDlg)
	DDX_Text(pDX, IDC_EDIT1, m_FileName);
	DDX_Text(pDX, IDC_EDIT2, m_SavePath);
	DDX_Text(pDX, IDC_EDIT3, m_FilePath);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy28F_APPDlg, CDialog)
	//{{AFX_MSG_MAP(CMy28F_APPDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ShowDir, OnShowDir)
	ON_BN_CLICKED(IDC_Start, OnStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy28F_APPDlg message handlers

BOOL CMy28F_APPDlg::OnInitDialog()
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
	CButton *But1;
	But1=(CButton *)this->GetDlgItem(IDC_Start); 
	But1->EnableWindow(false); 
	But1=NULL;	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy28F_APPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy28F_APPDlg::OnPaint() 
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
HCURSOR CMy28F_APPDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy28F_APPDlg::OnShowDir() 
{
	// TODO: Add your control notification handler code here
	CString str;
	CString StrBuf;
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
	this->m_SavePath=str; 
	if(m_SavePath!="")
	{
		But1=(CButton *)this->GetDlgItem(IDC_ShowDir); 
		But1->EnableWindow(false); 
		But1=NULL;
		But1=(CButton *)this->GetDlgItem(IDC_Start); 
		But1->EnableWindow(true); 
		But1=NULL;	
		if(str.GetAt(str.GetLength()-1)!='\\')
			m_SavePath+="\\";
	}
	else
	{
		MessageBox("Not select folders....");
	}
	UpdateData(false);
}

void CMy28F_APPDlg::OnStart() 
{
	// TODO: Add your control notification handler code here
	fstream a;
	fstream b;
	CString StrName[2];
	CString StrBuf;
	CString StrBuf1;
	CButton *But1;
	But1=(CButton *)this->GetDlgItem(IDC_Start); 
	But1->EnableWindow(false); 
	But1=NULL;	
	//////////////////////////////////////////
	//建立目錄檔案
	m_StrSaveFile="";
	m_StrDataFile="";
	m_StrSaveFile=this->m_SavePath;
	m_StrDataFile=this->m_SavePath;
	m_StrSaveFile+="folders.txt";
	m_StrDataFile+="Files.txt";
	pf=fopen(m_StrSaveFile.GetBuffer(0),"w");
	fclose(pf);
	pf=NULL;
	//////////////////////////////////////////
	//搜尋資料夾
	a.open(this->m_FilePath.GetBuffer(0),ios::in);
	while(!a.eof())
	{
		StrBuf="";
		a.getline(StrBuf.GetBuffer(0),400);
		if(StrBuf!="")
		{
			//MessageBox(StrBuf);
			pf=fopen(m_StrSaveFile.GetBuffer(0),"a");
			fprintf(pf,"%s\n",StrBuf.GetBuffer(0));
			fclose(pf);
			pf=NULL;
			BrowseDir(StrBuf);
		}
	}
	a.close();
	//////////////////////////////////////////
	//建立記錄檔
	pf=fopen(m_StrDataFile.GetBuffer(0),"w");
	fclose(pf);
	pf=NULL;
	//****************************************
	//將搜尋結果寫道記錄檔並複製檔案
	a.open(this->m_StrSaveFile.GetBuffer(0),ios::in);
	while(!a.eof())
	{
		StrBuf="";
		a.getline(StrBuf.GetBuffer(0),400);
		m_StrSearchA.Format("%s",StrBuf.GetBuffer(0));
		if(StrBuf!="")
		{
			b.open(this->m_FileName.GetBuffer(0),ios::in);
			while(!b.eof())
			{
				StrBuf1="";
				b.getline(StrBuf1.GetBuffer(0),400);
				m_StrSearchB.Format("%s",StrBuf1.GetBuffer(0));
				if(StrBuf1!="")
				{
					BrowseFile(m_StrSearchA,m_StrSearchB);//副檔名
					//BrowseFile(m_StrSearchA,m_StrSearchB,false);//主檔名
				}
			}
			b.close();
		}
	}
	a.close();
	//////////////////////////////////////////
	if(m_blncheck)
	{
		MessageBox("OK","finished....");
	}
	else
	{
		MessageBox("Error ...","Error ...");
	}
}
void CMy28F_APPDlg::BrowseDir(CString strDir)
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
			StrBuf+="\\";
			pf=fopen(m_StrSaveFile.GetBuffer(0),"a");
			fprintf(pf,"%s\n",StrBuf.GetBuffer(0));
			fclose(pf);
			pf=NULL;
			if(GetDirSize(StrBuf)>0)
				BrowseDir(ff.GetFilePath());
		}
	}
	ff.Close();//關閉
}
void CMy28F_APPDlg::BrowseFile(CString strDir,CString strfile,bool blnchecktype)
{
	CFileFind ff;
	bool blncheck=true;
	CString szDir = strDir;
	CString StrBuf1,StrBuf2,StrBuf3;
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
			StrBuf3.Format("%s%s",this->m_SavePath.GetBuffer(0),ff.GetFileName());  
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
				////////////////////////////////////////////////////////////
				blncheck=true;
				blncheck=::CopyFile(StrBuf1.GetBuffer(0),StrBuf3.GetBuffer(0),true);
				if(blncheck==false)
				{
					m_blncheck=false;
				}
				/////////////////////////////////////////////////////////////
				pf=fopen(m_StrDataFile.GetBuffer(0),"a");
				fprintf(pf,"%s\n",StrBuf1.GetBuffer(0));
				fclose(pf);
				pf=NULL;
			}
			StrBuf1="";
			StrBuf2="";
			StrBuf3="";
			//Sleep(500);
		}
	}
	ff.Close();//關閉
}
DWORD CMy28F_APPDlg::GetDirSize(CString strDirPath)
{
    CString strFilePath;
    DWORD    dwDirSize = 0;
    
    strFilePath += strDirPath;
    strFilePath += "\\*.*";
    
    CFileFind finder;
    BOOL bFind = finder.FindFile(strFilePath);
    while (bFind)
    {
        bFind = finder.FindNextFile();
        if (!finder.IsDots())
        {
            CString strTempPath = finder.GetFilePath();
            if (!finder.IsDirectory())
            {
                dwDirSize += finder.GetLength();
            }
            else
            {
                dwDirSize += GetDirSize(strTempPath);
            }
        }
    }
    finder.Close();
    return dwDirSize;
}