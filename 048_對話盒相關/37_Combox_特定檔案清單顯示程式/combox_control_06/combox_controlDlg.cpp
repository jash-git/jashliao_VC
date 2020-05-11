// combox_controlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "combox_control.h"
#include "combox_controlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
FILE *pf;
long glngAllCount=0;//記錄檔案總數
long glngNowPage=0;//記錄目前頁數
/////////////////////////////////////////////////////////////////////////////
#define ON_0 WM_USER + 500
#define ON_1 WM_USER + 501
#define ON_2 WM_USER + 502
#define ON_3 WM_USER + 503 
#define ON_4 WM_USER + 504 
#define ON_5 WM_USER + 505 
#define ON_6 WM_USER + 506 
#define ON_7 WM_USER + 507 
#define ON_8 WM_USER + 508 
#define ON_9 WM_USER + 509 
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
// CCombox_controlDlg dialog

CCombox_controlDlg::CCombox_controlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCombox_controlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCombox_controlDlg)
	m_pages = 0;
	m_NowPage = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCombox_controlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCombox_controlDlg)
	DDX_Control(pDX, IDC_CHECK8, m_combox8);
	DDX_Control(pDX, IDC_CHECK7, m_combox7);
	DDX_Control(pDX, IDC_CHECK6, m_combox6);
	DDX_Control(pDX, IDC_CHECK4, m_combox4);
	DDX_Control(pDX, IDC_CHECK5, m_combox5);
	DDX_Control(pDX, IDC_CHECK3, m_combox3);
	DDX_Control(pDX, IDC_CHECK2, m_combox2);
	DDX_Control(pDX, IDC_CHECK1, m_combox1);
	DDX_Text(pDX, IDC_EDIT1, m_pages);
	DDX_Text(pDX, IDC_EDIT2, m_NowPage);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCombox_controlDlg, CDialog)
	//{{AFX_MSG_MAP(CCombox_controlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck4)
	ON_BN_CLICKED(IDC_CHECK5, OnCheck5)
	ON_BN_CLICKED(IDC_CHECK6, OnCheck6)
	ON_BN_CLICKED(IDC_CHECK7, OnCheck7)
	ON_BN_CLICKED(IDC_CHECK8, OnCheck8)
	ON_MESSAGE(ON_0,On_click0)
	ON_MESSAGE(ON_1,On_click1)
	ON_MESSAGE(ON_2,On_click2)
	ON_MESSAGE(ON_3,On_click3)
	ON_MESSAGE(ON_4,On_click4)
	ON_MESSAGE(ON_5,On_click5)
	ON_MESSAGE(ON_6,On_click6)
	ON_MESSAGE(ON_7,On_click7)
	ON_MESSAGE(ON_8,On_click8)
	ON_MESSAGE(ON_9,On_click9)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCombox_controlDlg message handlers

BOOL CCombox_controlDlg::OnInitDialog()
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
	/////////////////////////////////////////////////////
	long i,j;
	m_Array1.RemoveAll();
	pf=fopen("data.txt","w");
	BrowseDir("D:\\備份資料\\wmv2flv\\video");
	fclose(pf);
	j=m_Array1.GetSize();
	glngAllCount=j;
	i=j/8;
	UpdateData(true);
		if(i*8<j)
		{
			m_pages=i+1;
		}
		else
		{
			m_pages=i;
		}
	UpdateData(false);
	/////////////////////////////////////////////////////
	m_combox1.SetWindowText(m_Array1.GetAt(0));
	m_combox1.SetWindowText("");
	m_combox2.SetWindowText("");
	m_combox3.SetWindowText("");
	m_combox4.SetWindowText("");
	m_combox5.SetWindowText("");
	m_combox6.SetWindowText("");
	m_combox7.SetWindowText("");
	m_combox8.SetWindowText(""); 
	/////////////////////////////////////////////////////
	glngNowPage=1;
	UpdateData(true);
		m_NowPage=glngNowPage; 
	UpdateData(false);
	ShowData(glngNowPage);
	/*
	m_combox1.SetCheck(1);
	m_combox2.SetCheck(!m_combox1.GetCheck()); 
	m_combox3.SetCheck(1);
	m_combox4.SetCheck(!m_combox1.GetCheck()); 
	m_combox5.SetCheck(1);
	m_combox6.SetCheck(!m_combox1.GetCheck()); 
	m_combox7.SetCheck(1);
	m_combox8.SetCheck(!m_combox1.GetCheck());
	*/
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCombox_controlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCombox_controlDlg::OnPaint() 
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
HCURSOR CCombox_controlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CCombox_controlDlg::BrowseDir(CString strDir)
{
	CFileFind ff;
	CString szDir = strDir;
	
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
			CString str;
			int result;
			char *chrall;
			char chrname[100]={"\0"};
			char chrtype[10]={"\0"};
			CString StrFileName;
			CString StrFileType;
			StrFileName=ff.GetFileName();
			chrall=StrFileName.GetBuffer(0);
			result = sscanf(chrall,"%[^'.'].%s",chrname,chrtype);
			StrFileType=chrtype;
			StrFileType.MakeLower();
			if(StrFileType=="rmvb"||StrFileType=="rm"||StrFileType=="wmv"||StrFileType=="avi"||StrFileType=="mpg"||StrFileType=="mpeg")
			{
				str.Format("目前檔案%s",ff.GetFilePath());
				m_Array1.Add(ff.GetFilePath());
				fprintf(pf,"%s\n",ff.GetFilePath());
			}
			//Sleep(500);
		}
	}
	ff.Close();//關閉
}
void CCombox_controlDlg::ShowData(long lngNowPage)
{
	int i,j,flg;
	CString StrShowString[8];
	for(i=0;i<8;i++)
	{
		StrShowString[i]="";
	}
	j=m_Array1.GetSize();
	for(i=0;i<8;i++)
	{
		flg=((lngNowPage-1)*8+i);
		if((flg-1)<(j-1))
		{
			StrShowString[i]=m_Array1.GetAt(flg);
		}
	}
	m_combox1.SetCheck(0);
	m_combox2.SetCheck(0);
	m_combox3.SetCheck(0);
	m_combox4.SetCheck(0);
	m_combox5.SetCheck(0);
	m_combox6.SetCheck(0);
	m_combox7.SetCheck(0);
	m_combox8.SetCheck(0);
	m_combox1.SetWindowText("1=>"+StrShowString[0]);
	m_combox2.SetWindowText("2=>"+StrShowString[1]);
	m_combox3.SetWindowText("3=>"+StrShowString[2]);
	m_combox4.SetWindowText("4=>"+StrShowString[3]);
	m_combox5.SetWindowText("5=>"+StrShowString[4]);
	m_combox6.SetWindowText("6=>"+StrShowString[5]);
	m_combox7.SetWindowText("7=>"+StrShowString[6]);
	m_combox8.SetWindowText("8=>"+StrShowString[7]);
}

void CCombox_controlDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	if((glngNowPage-1)<=0)
	{
		glngNowPage=1;
	}
	else
	{
		glngNowPage--;
	}
	UpdateData(true);
		m_NowPage=glngNowPage; 
	UpdateData(false);
	ShowData(glngNowPage);	
}

void CCombox_controlDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	if((glngNowPage+1)>m_pages)
	{
		glngNowPage=m_pages;
	}
	else
	{
		glngNowPage++;
	}
	UpdateData(true);
		m_NowPage=glngNowPage; 
	UpdateData(false);
	ShowData(glngNowPage);	
}

void CCombox_controlDlg::OnCheck1() 
{
	// TODO: Add your control notification handler code here
	CString StrBuf1,StrBuf2;
	int result;
	char *chrall;
	char chrbuf2[500]={"\0"};
	char chrbuf1[10]={"\0"};
	if(m_combox1.GetCheck())
	{
		m_combox1.GetWindowText(StrBuf1);
		chrall=StrBuf1.GetBuffer(0);
		result = sscanf(chrall,"%[^'>']>%s",chrbuf1,chrbuf2);
		StrBuf2=chrbuf2;
		MessageBox(StrBuf2);
	}
}

void CCombox_controlDlg::OnCheck2() 
{
	// TODO: Add your control notification handler code here
	CString StrBuf1,StrBuf2;
	int result;
	char *chrall;
	char chrbuf2[500]={"\0"};
	char chrbuf1[10]={"\0"};
	if(m_combox2.GetCheck())
	{
		m_combox2.GetWindowText(StrBuf1);
		chrall=StrBuf1.GetBuffer(0);
		result = sscanf(chrall,"%[^'>']>%s",chrbuf1,chrbuf2);
		StrBuf2=chrbuf2;
		MessageBox(StrBuf2);
	}	
}

void CCombox_controlDlg::OnCheck3() 
{
	// TODO: Add your control notification handler code here
	CString StrBuf1,StrBuf2;
	int result;
	char *chrall;
	char chrbuf2[500]={"\0"};
	char chrbuf1[10]={"\0"};
	if(m_combox3.GetCheck())
	{
		m_combox3.GetWindowText(StrBuf1);
		chrall=StrBuf1.GetBuffer(0);
		result = sscanf(chrall,"%[^'>']>%s",chrbuf1,chrbuf2);
		StrBuf2=chrbuf2;
		MessageBox(StrBuf2);
	}	
}

void CCombox_controlDlg::OnCheck4() 
{
	// TODO: Add your control notification handler code here
	CString StrBuf1,StrBuf2;
	int result;
	char *chrall;
	char chrbuf2[500]={"\0"};
	char chrbuf1[10]={"\0"};
	if(m_combox4.GetCheck())
	{
		m_combox4.GetWindowText(StrBuf1);
		chrall=StrBuf1.GetBuffer(0);
		result = sscanf(chrall,"%[^'>']>%s",chrbuf1,chrbuf2);
		StrBuf2=chrbuf2;
		MessageBox(StrBuf2);
	}	
}

void CCombox_controlDlg::OnCheck5() 
{
	// TODO: Add your control notification handler code here
	CString StrBuf1,StrBuf2;
	int result;
	char *chrall;
	char chrbuf2[500]={"\0"};
	char chrbuf1[10]={"\0"};
	if(m_combox5.GetCheck())
	{
		m_combox5.GetWindowText(StrBuf1);
		chrall=StrBuf1.GetBuffer(0);
		result = sscanf(chrall,"%[^'>']>%s",chrbuf1,chrbuf2);
		StrBuf2=chrbuf2;
		MessageBox(StrBuf2);
	}	
}

void CCombox_controlDlg::OnCheck6() 
{
	// TODO: Add your control notification handler code here
	CString StrBuf1,StrBuf2;
	int result;
	char *chrall;
	char chrbuf2[500]={"\0"};
	char chrbuf1[10]={"\0"};
	if(m_combox6.GetCheck())
	{
		m_combox6.GetWindowText(StrBuf1);
		chrall=StrBuf1.GetBuffer(0);
		result = sscanf(chrall,"%[^'>']>%s",chrbuf1,chrbuf2);
		StrBuf2=chrbuf2;
		MessageBox(StrBuf2);
	}	
}

void CCombox_controlDlg::OnCheck7() 
{
	// TODO: Add your control notification handler code here
	CString StrBuf1,StrBuf2;
	int result;
	char *chrall;
	char chrbuf2[500]={"\0"};
	char chrbuf1[10]={"\0"};
	if(m_combox7.GetCheck())
	{
		m_combox7.GetWindowText(StrBuf1);
		chrall=StrBuf1.GetBuffer(0);
		result = sscanf(chrall,"%[^'>']>%s",chrbuf1,chrbuf2);
		StrBuf2=chrbuf2;
		MessageBox(StrBuf2);
	}	
}

void CCombox_controlDlg::OnCheck8() 
{
	// TODO: Add your control notification handler code h.ere
	CString StrBuf1,StrBuf2;
	int result;
	char *chrall;
	char chrbuf2[500]={"\0"};
	char chrbuf1[10]={"\0"};
	if(m_combox8.GetCheck())
	{
		m_combox8.GetWindowText(StrBuf1);
		chrall=StrBuf1.GetBuffer(0);
		result = sscanf(chrall,"%[^'>']>%s",chrbuf1,chrbuf2);
		StrBuf2=chrbuf2;
		MessageBox(StrBuf2);
	}	
}
void CCombox_controlDlg::On_click0()
{
	OnButton1();
}
void CCombox_controlDlg::On_click1()
{
	m_combox1.SetCheck(!m_combox1.GetCheck()); 
	OnCheck1();
}
void CCombox_controlDlg::On_click2()
{
	m_combox2.SetCheck(!m_combox2.GetCheck()); 
	OnCheck2();
}
void CCombox_controlDlg::On_click3()
{
	m_combox3.SetCheck(!m_combox3.GetCheck()); 
	OnCheck3();
}
void CCombox_controlDlg::On_click4()
{
	m_combox4.SetCheck(!m_combox4.GetCheck()); 
	OnCheck4();
}
void CCombox_controlDlg::On_click5()
{
	m_combox5.SetCheck(!m_combox5.GetCheck()); 
	OnCheck5();
}
void CCombox_controlDlg::On_click6()
{
	m_combox6.SetCheck(!m_combox6.GetCheck()); 
	OnCheck6();
}
void CCombox_controlDlg::On_click7()
{
	m_combox7.SetCheck(!m_combox7.GetCheck()); 
	OnCheck7();
}
void CCombox_controlDlg::On_click8()
{
	m_combox8.SetCheck(!m_combox8.GetCheck()); 
	OnCheck8();
}
void CCombox_controlDlg::On_click9()
{
	OnButton2();
}