// testUnicodeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "testUnicode.h"
#include "testUnicodeDlg.h"

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
// CTestUnicodeDlg dialog

CTestUnicodeDlg::CTestUnicodeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestUnicodeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestUnicodeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestUnicodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestUnicodeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestUnicodeDlg, CDialog)
	//{{AFX_MSG_MAP(CTestUnicodeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestUnicodeDlg message handlers

BOOL CTestUnicodeDlg::OnInitDialog()
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

void CTestUnicodeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestUnicodeDlg::OnPaint() 
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
HCURSOR CTestUnicodeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestUnicodeDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
   // 寫入 Unicode 內容  
    TCHAR* recordfilename=_T("123456.mp3");   
  
    // 開啟文件: (注意: 要用 wb 不能用 wt)  
    // 請放心! 寫入後還是可以用 Notepad 看到內容(This is a Unicode document file)  
    FILE *fp=_tfopen(_T("RecordInfo_API.txt"),_T("wb"));  
    if(fp!=NULL){  
        //  Step 1: 寫入 Unicode 檔頭, 標明這是 Unicode 檔 (關鍵片段)  
        unsigned char u[2]={0xff,0xfe}; // Unicode 檔頭   = 0xfeff  
        fwrite(u,2,1,fp);   
  
        // Step 2: 寫入真正 Unicode 資料  
        //_ftprintf(fp,_T("Record_Filename=%s\n"),recordfilename);
		_ftprintf(fp,_T("%s\n"),recordfilename);
		recordfilename=_T("654321.mp3");
		_ftprintf(fp,_T("%s\n"),recordfilename);
        // Step 3: 關檔寫入  
        fclose(fp);  
  
        // Step 4: 請用 NotePad 看看內容  
    }else{  
        ::MessageBox(NULL,_T("錄音資訊檔建立失敗"),_T("Error"),MB_OK);  
    }  	
}

void CTestUnicodeDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
    TCHAR recordfilename[256];
	TCHAR recordfilename1[256];
  
    // 開啟文件: (注意: 要用 rb 不能用 rt)  
    FILE *fp=_tfopen(_T("RecordInfo_API.txt"),_T("rb"));  
    if(fp!=NULL){  
                // (關鍵片段)  
        // Step 1: 先讀取 0xfffe (你也可以跳過 2 bytes)  
        char unicodeheader[2];  
        fread(unicodeheader,2,1,fp);  
  
        // Step 2: 真正讀取 Unicode 內容  
        //_ftscanf(fp,_T("Record_Filename=%s\n"),&recordfilename);
		_ftscanf(fp,_T("%s\n"),&recordfilename);
		_ftscanf(fp,_T("%s\n"),&recordfilename1);
        fclose(fp);  
        } 
	MessageBox(recordfilename);
	MessageBox(recordfilename1);
}
