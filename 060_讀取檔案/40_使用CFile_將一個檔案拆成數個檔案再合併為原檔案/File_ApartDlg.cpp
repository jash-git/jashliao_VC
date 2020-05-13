// File_ApartDlg.cpp : implementation file
//

#include "stdafx.h"
#include "File_Apart.h"
#include "File_ApartDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
long number;
long size;
unsigned char *data;
long surplus;
CString s1;
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
// CFile_ApartDlg dialog

CFile_ApartDlg::CFile_ApartDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFile_ApartDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFile_ApartDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFile_ApartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFile_ApartDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFile_ApartDlg, CDialog)
	//{{AFX_MSG_MAP(CFile_ApartDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFile_ApartDlg message handlers

BOOL CFile_ApartDlg::OnInitDialog()
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

void CFile_ApartDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFile_ApartDlg::OnPaint() 
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
HCURSOR CFile_ApartDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFile_ApartDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CFile f1;
	f1.Open("desktop.JPG",CFile::modeRead);
	s1.Format("%ld",f1.GetLength());
	MessageBox(s1);
	//****************************
	size=10240;//10Kbyte
	number=f1.GetLength()/size;
	data=new unsigned char [size];
	long fsize=f1.GetLength(); 
	if(fsize>(size*number))
	{
		surplus=fsize-(size*number);
		number++;
	}
	CFile f2;
	for(int i=0;i<number;i++)
	{
		s1.Format("%d.jpg.jash",i);
		MessageBox(s1);
		f2.Open(s1,CFile::modeCreate|CFile::modeWrite); 
		memset(data,'\0',size);
		f1.Seek((i*size),CFile::begin);
		if((i+1)<number)
		{
			f1.Read(data,size);
			f2.Write(data,size);
		}
		else
		{
				f1.Read(data,surplus);
				f2.Write(data,surplus);
		}
		f2.Close(); 
	}
	f1.Close();
	delete []data;
	MessageBox("OK");
}

void CFile_ApartDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CFile f1,f2;
	f1.Open("jash.jpg",CFile::modeCreate|CFile::modeWrite);
	
	data=new unsigned char [size];
	for(int i=0;i<number;i++)
	{
		s1.Format("%d.jpg.jash",i);
		MessageBox(s1);
		f2.Open(s1,CFile::modeRead); 
		memset(data,'\0',size);
		if((i+1)<number)
		{
			f2.Read(data,size);
			f1.Write(data,size);
		}
		else
		{
			f2.Read(data,surplus);
			f1.Write(data,surplus);
		}
		f2.Close();
		DeleteFile(s1);
	}
	f1.Close();
	delete []data;
	MessageBox("OK");
}

void CFile_ApartDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	CString StrData;
	double s,d;
	long lngfilesize;
	CFile f1,f2;
	unsigned char chrd;
	int i;
	s=0.0;
	d=0.0;
	f1.Open("desktop.JPG",CFile::modeRead);
	f2.Open("jash.jpg",CFile::modeRead);
	lngfilesize=f1.GetLength();
	for(i=0;i<lngfilesize;i++)
	{
		f1.Seek(i,CFile::begin);
		f1.Read(&chrd,1);
		s+=(int)chrd;
	}
	StrData.Format("¨Ó·½=%f",s);
	MessageBox(StrData);
	//
	lngfilesize=f2.GetLength();
	for(i=0;i<lngfilesize;i++)
	{
		f2.Seek(i,CFile::begin);
		f2.Read(&chrd,1);
		d+=(int)chrd;
	}
	StrData.Format("¥Øªº=%f",d);
	MessageBox(StrData);	
}
