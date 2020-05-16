// BeckRS485ControlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BeckRS485Control.h"
#include "BeckRS485ControlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
bool blnopenRS485;
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
// CBeckRS485ControlDlg dialog

CBeckRS485ControlDlg::CBeckRS485ControlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBeckRS485ControlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBeckRS485ControlDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBeckRS485ControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBeckRS485ControlDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBeckRS485ControlDlg, CDialog)
	//{{AFX_MSG_MAP(CBeckRS485ControlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OpenRS485, OnOpenRS485)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_CalibrateBed, OnCalibrateBed)
	ON_BN_CLICKED(IDC_MoveHeadUp, OnMoveHeadUp)
	ON_BN_CLICKED(IDC_MoveHeadDn, OnMoveHeadDn)
	ON_BN_CLICKED(IDC_MoveFootUp, OnMoveFootUp)
	ON_BN_CLICKED(IDC_MoveFootDn, OnMoveFootDn)
	ON_BN_CLICKED(IDC_StopMove, OnStopMove)
	ON_BN_CLICKED(IDC_MemoryFunction, OnMemoryFunction)
	ON_BN_CLICKED(IDC_SetBedHeadPosition, OnSetBedHeadPosition)
	ON_BN_CLICKED(IDC_SetBedFootPosition, OnSetBedFootPosition)
	ON_BN_CLICKED(IDC_HeadVibrationUp, OnHeadVibrationUp)
	ON_BN_CLICKED(IDC_HeadVibrationDn, OnHeadVibrationDn)
	ON_BN_CLICKED(IDC_FootVibrationUp, OnFootVibrationUp)
	ON_BN_CLICKED(IDC_FootVibrationDn, OnFootVibrationDn)
	ON_BN_CLICKED(IDC_StopVibration, OnStopVibration)
	ON_BN_CLICKED(IDC_VibrationFunction, OnVibrationFunction)
	ON_BN_CLICKED(IDC_SetBedHeadVibration, OnSetBedHeadVibration)
	ON_BN_CLICKED(IDC_SetBedFootVibration, OnSetBedFootVibration)
	ON_BN_CLICKED(IDC_GetPosition, OnGetPosition)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBeckRS485ControlDlg message handlers

BOOL CBeckRS485ControlDlg::OnInitDialog()
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

void CBeckRS485ControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBeckRS485ControlDlg::OnPaint() 
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
HCURSOR CBeckRS485ControlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBeckRS485ControlDlg::OnOpenRS485() 
{
	// TODO: Add your control notification handler code here
	blnopenRS485=RS.OpenCom(3,9600,8,0,1);
	if(blnopenRS485)
		MessageBox("Open OK");
	else
		MessageBox("Open Fail");	
}

void CBeckRS485ControlDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	if(blnopenRS485)
		RS.Close();
	else
		MessageBox("Not Open RS485");
	// TODO: Add your message handler code here
	
}

void CBeckRS485ControlDlg::OnCalibrateBed() 
{
	// TODO: Add your control notification handler code here
	char buf[3];
	buf[0]=35;//#
	buf[1]=66;//B
	buf[2]=buf[0]^buf[1];//# XOR B
	if(blnopenRS485)
	{
		RS.Write(buf,3);
		Sleep(5000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		MessageBox(Output);
	}
	else
		MessageBox("Not Open RS485");
}

void CBeckRS485ControlDlg::OnMoveHeadUp() 
{
	// TODO: Add your control notification handler code here
	char buf[3];
	buf[0]=35;//#
	buf[1]=67;//C
	buf[2]=buf[0]^buf[1];//# XOR C
	if(blnopenRS485)
	{
		RS.Write(buf,3);
		Sleep(5000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		MessageBox(Output);
	}
	else
		MessageBox("Not Open RS485");	
}

void CBeckRS485ControlDlg::OnMoveHeadDn() 
{
	// TODO: Add your control notification handler code here
	char buf[3];
	buf[0]=35;//#
	buf[1]=68;//D
	buf[2]=buf[0]^buf[1];//# XOR D
	if(blnopenRS485)
	{
		RS.Write(buf,3);
		Sleep(5000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		MessageBox(Output);
	}
	else
		MessageBox("Not Open RS485");	
}

void CBeckRS485ControlDlg::OnMoveFootUp() 
{
	// TODO: Add your control notification handler code here
	char buf[3];
	buf[0]=35;//#
	buf[1]=69;//E
	buf[2]=buf[0]^buf[1];//# XOR E
	if(blnopenRS485)
	{
		RS.Write(buf,3);
		Sleep(5000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		MessageBox(Output);
	}
	else
		MessageBox("Not Open RS485");	
}

void CBeckRS485ControlDlg::OnMoveFootDn() 
{
	// TODO: Add your control notification handler code here
	char buf[3];
	buf[0]=35;//#
	buf[1]=70;//F
	buf[2]=buf[0]^buf[1];//# XOR F
	if(blnopenRS485)
	{
		RS.Write(buf,3);
		Sleep(5000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		MessageBox(Output);
	}
	else
		MessageBox("Not Open RS485");	
}

void CBeckRS485ControlDlg::OnStopMove() 
{
	// TODO: Add your control notification handler code here
	char buf[3];
	buf[0]=35;//#
	buf[1]=71;//G
	buf[2]=buf[0]^buf[1];//# XOR G
	if(blnopenRS485)
	{
		RS.Write(buf,3);
		Sleep(5000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		MessageBox(Output);
	}
	else
		MessageBox("Not Open RS485");	
}

void CBeckRS485ControlDlg::OnMemoryFunction() 
{
	// TODO: Add your control notification handler code here
	char buf[4];
	buf[0]=35;//#
	buf[1]=72;//H
	buf[2]=02;//1->TV,2->Zero
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR H XOR 1
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		Sleep(5000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		MessageBox(Output);
	}
	else
		MessageBox("Not Open RS485");	
}

void CBeckRS485ControlDlg::OnSetBedHeadPosition() 
{
	// TODO: Add your control notification handler code here
	char buf[4];
	buf[0]=35;//#
	buf[1]=73;//I
	buf[2]=50;//十進位伸長量(50)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR H XOR 十進位伸長量(50)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		Sleep(5000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		MessageBox(Output);
	}
	else
		MessageBox("Not Open RS485");	
}

void CBeckRS485ControlDlg::OnSetBedFootPosition() 
{
	// TODO: Add your control notification handler code here
	char buf[4];
	buf[0]=35;//#
	buf[1]=74;//J
	buf[2]=50;//十進位伸長量(50)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR J XOR 十進位伸長量(50)
	if(blnopenRS485)
	{
		RS.Write(buf,5);
		Sleep(5000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		MessageBox(Output);
	}
	else
		MessageBox("Not Open RS485");	
}

void CBeckRS485ControlDlg::OnHeadVibrationUp() 
{
	// TODO: Add your control notification handler code here
	char buf[3];
	buf[0]=35;//#
	buf[1]=76;//L
	buf[2]=buf[0]^buf[1];//# XOR L
	if(blnopenRS485)
	{
		RS.Write(buf,3);
		Sleep(5000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		MessageBox(Output);
	}
	else
		MessageBox("Not Open RS485");
}

void CBeckRS485ControlDlg::OnHeadVibrationDn() 
{
	// TODO: Add your control notification handler code here
	char buf[3];
	buf[0]=35;//#
	buf[1]=77;//M
	buf[2]=buf[0]^buf[1];//# XOR M
	if(blnopenRS485)
	{
		RS.Write(buf,3);
		Sleep(5000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		MessageBox(Output);
	}
	else
		MessageBox("Not Open RS485");	
}

void CBeckRS485ControlDlg::OnFootVibrationUp() 
{
	// TODO: Add your control notification handler code here
	char buf[3];
	buf[0]=35;//#
	buf[1]=78;//N
	buf[2]=buf[0]^buf[1];//# XOR N
	if(blnopenRS485)
	{
		RS.Write(buf,3);
		Sleep(5000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		MessageBox(Output);
	}
	else
		MessageBox("Not Open RS485");	
}

void CBeckRS485ControlDlg::OnFootVibrationDn() 
{
	// TODO: Add your control notification handler code here
	char buf[3];
	buf[0]=35;//#
	buf[1]=79;//O
	buf[2]=buf[0]^buf[1];//# XOR O
	if(blnopenRS485)
	{
		RS.Write(buf,3);
		Sleep(5000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		MessageBox(Output);
	}
	else
		MessageBox("Not Open RS485");	
}

void CBeckRS485ControlDlg::OnStopVibration() 
{
	// TODO: Add your control notification handler code here
	char buf[3];
	buf[0]=35;//#
	buf[1]=80;//P
	buf[2]=buf[0]^buf[1];//# XOR P
	if(blnopenRS485)
	{
		RS.Write(buf,3);
		Sleep(5000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		MessageBox(Output);
	}
	else
		MessageBox("Not Open RS485");	
}

void CBeckRS485ControlDlg::OnVibrationFunction() 
{
	// TODO: Add your control notification handler code here
	char buf[4];
	buf[0]=35;//#
	buf[1]=81;//Q
	buf[2]=02;//1,2,3,4
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR Q XOR 1
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		Sleep(5000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		MessageBox(Output);
	}
	else
		MessageBox("Not Open RS485");	
}

void CBeckRS485ControlDlg::OnSetBedHeadVibration() 
{
	// TODO: Add your control notification handler code here
	char buf[4];
	buf[0]=35;//#
	buf[1]=82;//R
	buf[2]=9;//十進位振動量(9)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(9)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		Sleep(5000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		MessageBox(Output);
	}
	else
		MessageBox("Not Open RS485");		
}

void CBeckRS485ControlDlg::OnSetBedFootVibration() 
{
	// TODO: Add your control notification handler code here
	char buf[4];
	buf[0]=35;//#
	buf[1]=83;//S
	buf[2]=9;//十進位振動量(9)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(9)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		Sleep(5000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		MessageBox(Output);
	}
	else
		MessageBox("Not Open RS485");	
}

void CBeckRS485ControlDlg::OnGetPosition() 
{
	// TODO: Add your control notification handler code here
	char buf[3];
	buf[0]=35;//#
	buf[1]=75;//K
	buf[2]=buf[0]^buf[1];//# XOR K
	if(blnopenRS485)
	{
		RS.Write(buf,3);
		Sleep(5000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		MessageBox(Output);
	}
	else
		MessageBox("Not Open RS485");	
}
