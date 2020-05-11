// ServerFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ServerFile.h"
#include "ServerFileDlg.h"
#include <Afxsock.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define PORT 34000 /// Select any free port you wish

UINT SendFile(LPVOID strFilename)
{
	///////////////////////////////////////
	AfxSocketInit(NULL);
	CSocket sockSrvr; 
	sockSrvr.Create(PORT); // Creates our server socket
	sockSrvr.Listen(1); // Start listening for the client at PORT
	CSocket sockRecv;
	sockSrvr.Accept(sockRecv); // Use another CSocket to accept the connection
	////////////////////////////////////////
	CFile myFile;
	if(!myFile.Open((LPCTSTR)strFilename, CFile::modeRead))
		return 0;
   UINT myFileLength = myFile.GetLength(); // Going to send the correct File Size
   int iBufSize = 1024 * 5;  
   int iSize = iBufSize; 
   LPBYTE pBuf = new BYTE[iBufSize];
   DWORD dwTemp = 0;
   /////////////////////////////////////////
   BOOL bTest = sockRecv.AsyncSelect(0);//由於CSocket實際是非同步，將它變?同步（阻塞）方式。 
   sockRecv.IOCtl( FIONBIO, &dwTemp);//用IOCtl要將AsyncSelect的第一個參數?0，參看MSDN
   sockRecv.Send(&myFileLength, 4); // 4 bytes long
   int iNumByte; 
   UINT uiTotal = 0;
   ////////////////////////////////
   while(uiTotal < myFileLength ) 
   { 
     //讀取文件內容 
     if((int)(myFileLength  - uiTotal) < iBufSize) 
       iSize = myFileLength  - uiTotal;//當小於緩衝區iTEST時的處理 
     iSize=myFile.Read(pBuf , iSize);//得到讀取的位元組數 
     int iCount=0; 
     //發送定長文件資料 
     while(iCount<iSize) 
     { 
       iNumByte = sockRecv.Send(pBuf, iSize-iCount);//注意iNumByte?實際的發送位元組數，不要以iSize?准 
       if(iNumByte == SOCKET_ERROR) 
       { 
          AfxMessageBox("發送錯誤！"); 
          goto ExitLable1; 
       } 
       iCount+=iNumByte; 
       if(iCount<iSize) 
       { 
          myFile.Seek(iSize-iCount,CFile::current); 
       } 
     } 
     uiTotal += iCount; 
   }
 AfxMessageBox("發送文件成功！"); 
ExitLable1: 
	delete[] pBuf; 
	myFile.Close();
	sockRecv.Close();
		return 1;
}
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
// CServerFileDlg dialog

CServerFileDlg::CServerFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServerFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CServerFileDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServerFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServerFileDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CServerFileDlg, CDialog)
	//{{AFX_MSG_MAP(CServerFileDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerFileDlg message handlers

BOOL CServerFileDlg::OnInitDialog()
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

void CServerFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CServerFileDlg::OnPaint() 
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
HCURSOR CServerFileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CServerFileDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	LPCTSTR str="C:\\WINDOWS\\Desktop\\28647.zip";
	CWinThread *pr=AfxBeginThread(SendFile,(LPVOID)str,0,0,0,NULL);
}
