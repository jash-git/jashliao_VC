// ShowMACDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShowMAC.h"
#include "ShowMACDlg.h"
////////////////////////////
#include < windows.h >
#include < wincon.h >
#include < stdlib.h >
#include < stdio.h >
#include < time.h >
#include < nb30.h >
///////////////////////////
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////
typedef struct _ASTAT_{    
	ADAPTER_STATUS adapt;    
	NAME_BUFFER    NameBuff [30];
}ASTAT, * PASTAT;
ASTAT Adapter;
/////////////////////////////////////////////////
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
// CShowMACDlg dialog

CShowMACDlg::CShowMACDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShowMACDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShowMACDlg)
	m_MAC = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShowMACDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShowMACDlg)
	DDX_Text(pDX, IDC_EDIT1, m_MAC);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShowMACDlg, CDialog)
	//{{AFX_MSG_MAP(CShowMACDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowMACDlg message handlers

BOOL CShowMACDlg::OnInitDialog()
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

void CShowMACDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CShowMACDlg::OnPaint() 
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
HCURSOR CShowMACDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CShowMACDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	NCB Ncb;
    UCHAR uRetCode;
    //char NetName[50];
    LANA_ENUM lenum;
    int i;
	char sMacAddress[100];
    memset( &Ncb, 0, sizeof(Ncb) );
    Ncb.ncb_command = NCBENUM;
    Ncb.ncb_buffer = (UCHAR *)&lenum;
    Ncb.ncb_length = sizeof(lenum);
    uRetCode = Netbios( &Ncb );
    for(i=0; i < lenum.length ;i++)
    {
		memset( &Ncb, 0, sizeof(Ncb) );
		Ncb.ncb_command = NCBRESET;
		Ncb.ncb_lana_num = lenum.lana[i];
		uRetCode = Netbios( &Ncb );

		memset( &Ncb, 0, sizeof (Ncb) );
		Ncb.ncb_command = NCBASTAT;
		Ncb.ncb_lana_num = lenum.lana[i];

		strcpy( (char*)Ncb.ncb_callname, "* " );
		Ncb.ncb_buffer = (unsigned char *) &Adapter;
		Ncb.ncb_length = sizeof(Adapter);
		uRetCode = Netbios( &Ncb );
	}
	if ( uRetCode == 0 )
	{		
     sprintf(sMacAddress, "MAC : %02x-%02x-%02x-%02x-%02x-%02x\n",
     Adapter.adapt.adapter_address[0],
     Adapter.adapt.adapter_address[1],
     Adapter.adapt.adapter_address[2],
     Adapter.adapt.adapter_address[3],
     Adapter.adapt.adapter_address[4],
     Adapter.adapt.adapter_address[5] );

	}
	UpdateData(true);
		m_MAC=sMacAddress;
	UpdateData(false);
}
