// noc_h_SendEmailDlg.cpp : implementation file
//

#include "stdafx.h"
#include "noc_h_SendEmail.h"
#include "noc_h_SendEmailDlg.h"
#include "MailMessage.h"
#include "POP3.h"
#include "SMTP.h"
#include<fstream.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
TCHAR gstrCurDrt[500];//存放目其目錄字串
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
// CNoc_h_SendEmailDlg dialog

CNoc_h_SendEmailDlg::CNoc_h_SendEmailDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNoc_h_SendEmailDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNoc_h_SendEmailDlg)
	m_Straddress = _T("\"網管中心\"<noc_hsend@tw-airnet.net>;");
	m_Strbody = _T("");
	m_Strtitle = _T("網管中心通報 - ");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNoc_h_SendEmailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNoc_h_SendEmailDlg)
	DDX_Control(pDX, IDC_BUTOpen, m_Open);
	DDX_Control(pDX, IDC_BMP, m_BMP);
	DDX_Control(pDX, IDC_BUTClear, m_Clear);
	DDX_Control(pDX, IDC_BUTSendMail, m_SM);
	DDX_Control(pDX, IDC_BUTEmail9, m_E09);
	DDX_Control(pDX, IDC_BUTEmail8, m_E08);
	DDX_Control(pDX, IDC_BUTEmail7, m_E07);
	DDX_Control(pDX, IDC_BUTEmail6, m_E06);
	DDX_Control(pDX, IDC_BUTEmail5, m_E05);
	DDX_Control(pDX, IDC_BUTEmail4, m_E04);
	DDX_Control(pDX, IDC_BUTEmail3, m_E03);
	DDX_Control(pDX, IDC_BUTEmail2, m_E02);
	DDX_Control(pDX, IDC_BUTEmail1, m_E01);
	DDX_Text(pDX, IDC_address, m_Straddress);
	DDX_Text(pDX, IDC_body, m_Strbody);
	DDX_Text(pDX, IDC_title, m_Strtitle);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNoc_h_SendEmailDlg, CDialog)
	//{{AFX_MSG_MAP(CNoc_h_SendEmailDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTSendMail, OnBUTSendMail)
	ON_BN_CLICKED(IDC_BUTEmail1, OnBUTEmail1)
	ON_BN_CLICKED(IDC_BUTEmail2, OnBUTEmail2)
	ON_BN_CLICKED(IDC_BUTEmail3, OnBUTEmail3)
	ON_BN_CLICKED(IDC_BUTEmail4, OnBUTEmail4)
	ON_BN_CLICKED(IDC_BUTEmail5, OnBUTEmail5)
	ON_BN_CLICKED(IDC_BUTEmail6, OnBUTEmail6)
	ON_BN_CLICKED(IDC_BUTEmail7, OnBUTEmail7)
	ON_BN_CLICKED(IDC_BUTEmail8, OnBUTEmail8)
	ON_BN_CLICKED(IDC_BUTEmail9, OnBUTEmail9)
	ON_BN_CLICKED(IDC_BUTClear, OnBUTClear)
	ON_BN_CLICKED(IDC_BUTOpen, OnBUTOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNoc_h_SendEmailDlg message handlers

BOOL CNoc_h_SendEmailDlg::OnInitDialog()
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
	GetParameter();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNoc_h_SendEmailDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNoc_h_SendEmailDlg::OnPaint() 
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
HCURSOR CNoc_h_SendEmailDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CNoc_h_SendEmailDlg::GetParameter()
{
	MSXML2::IXMLDOMDocumentPtr pDoc;
	CTime t1=CTime::GetCurrentTime();
	_variant_t vtStr;
	bool blnRead=false;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="EmailConfig.xml";
	blnRead=pDoc->load((_bstr_t)strFileName1); 
	if(blnRead)//第11.0版的功能
	{

			MSXML2::IXMLDOMNodePtr  NodeData;
			/*
			CString	m_username;
			CString	m_password;
			CString	m_smtpserver;
			*/
			////////////////////////////////////////////////////////////
			NodeData=pDoc->selectSingleNode("//username");	
			NodeData->get_nodeTypedValue(&vtStr);
			m_username=vtStr.bstrVal;
			//*************************************************
			NodeData=pDoc->selectSingleNode("//password");	
			NodeData->get_nodeTypedValue(&vtStr);
			m_password=vtStr.bstrVal;
			//*************************************************
			NodeData=pDoc->selectSingleNode("//smtpserver");	
			NodeData->get_nodeTypedValue(&vtStr);
			m_smtpserver=vtStr.bstrVal;
	}
	CString StrBody,StrBuf;
	fstream a;
	char fg[500];
	a.open("sample_body.txt",ios::in);
	while(!a.eof())
	{
		a.getline(fg,500);
		StrBuf=fg;
		StrBody+=StrBuf;
		StrBody+="\r\n";
	}
	a.close();
	UpdateData(true);
		m_Strbody=StrBody;
	UpdateData(false);
	m_BMP.SetBitmap(LoadBitmap(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDB_BITMAP1)));
}
void CNoc_h_SendEmailDlg::OnBUTSendMail() 
{
	// TODO: Add your control notification handler code here
	//////////////////////////////////////
	CSMTP smtp(m_smtpserver);
	CMailMessage msg;
	msg.m_sFrom =m_username;
	UpdateData(true);
	msg.AddMultipleRecipients(m_Straddress);
	msg.m_sSubject =m_Strtitle;
	msg.m_sBody =m_Strbody;
	UpdateData(false);
	//////////////////////////////////////
	m_BMP.SetBitmap(LoadBitmap(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDB_BITMAP2)));
	m_Clear.EnableWindow(FALSE);
	m_SM.EnableWindow(FALSE);
	m_E09.EnableWindow(FALSE);
	m_E08.EnableWindow(FALSE);
	m_E07.EnableWindow(FALSE);
	m_E06.EnableWindow(FALSE);
	m_E05.EnableWindow(FALSE);
	m_E04.EnableWindow(FALSE);
	m_E03.EnableWindow(FALSE);
	m_E02.EnableWindow(FALSE);
	m_E01.EnableWindow(FALSE);
	m_Open.EnableWindow(FALSE);
	if( !smtp.Connect() )
	{
		AfxMessageBox( smtp.GetLastError() );
		return;
	}
	else
	{
		if( !smtp.SendMessage( &msg ) )
		{
			AfxMessageBox( smtp.GetLastError() );
			return;
		}
		if( !smtp.Disconnect() )
		{
			AfxMessageBox( smtp.GetLastError() );
			return;
		}
		AfxMessageBox( _T( "Message Sent Successfully") );
		CTime now=CTime::GetCurrentTime();
		CString StrFileName;
		StrFileName=gstrCurDrt;
		StrFileName+="BackupEmail\\";
		StrFileName+=now.Format("%Y%m%d%H%M%S");
		StrFileName+=m_Strtitle;
		StrFileName+=".txt";
		FILE *pf;
		pf=fopen(StrFileName.GetBuffer(0),"w");
		fprintf(pf,"%s\n\n",m_Straddress.GetBuffer(0));
		fprintf(pf,"%s\n\n",m_Strtitle.GetBuffer(0));
		fprintf(pf,"%s\n\n",m_Strbody.GetBuffer(0));
		fclose(pf);
		pf=NULL;
		m_SM.EnableWindow(TRUE);
		m_E09.EnableWindow(TRUE);
		m_E08.EnableWindow(TRUE);
		m_E07.EnableWindow(TRUE);
		m_E06.EnableWindow(TRUE);
		m_E05.EnableWindow(TRUE);
		m_E04.EnableWindow(TRUE);
		m_E03.EnableWindow(TRUE);
		m_E02.EnableWindow(TRUE);
		m_E01.EnableWindow(TRUE);
		m_Clear.EnableWindow(TRUE);
		m_Open.EnableWindow(TRUE);
		m_BMP.SetBitmap(LoadBitmap(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDB_BITMAP1)));
	}
}

void CNoc_h_SendEmailDlg::OnBUTEmail1() 
{
	//集團董事
	CString StrFileName;
	CString StrEmail;
	CString StrBuf;
	StrFileName=gstrCurDrt;
	StrFileName+="emaillist\\集團董事.txt";
	fstream a;
	char fg[500];
	a.open(StrFileName.GetBuffer(0),ios::in);
	StrEmail="";
	while(!a.eof())
	{
		a.getline(fg,500);
		StrBuf=fg;
		if(StrBuf!="")
		{
			StrEmail+=StrBuf;
			StrEmail+=";";
		}
	}
	a.close();
	UpdateData(true);
		m_Straddress+=StrEmail;
	UpdateData(false);	
}

void CNoc_h_SendEmailDlg::OnBUTEmail2() 
{
	//協理以上
	CString StrFileName;
	CString StrEmail;
	CString StrBuf;
	StrFileName=gstrCurDrt;
	StrFileName+="emaillist\\協理以上.txt";
	fstream a;
	char fg[500];
	a.open(StrFileName.GetBuffer(0),ios::in);
	StrEmail="";
	while(!a.eof())
	{
		a.getline(fg,500);
		StrBuf=fg;
		if(StrBuf!="")
		{
			StrEmail+=StrBuf;
			StrEmail+=";";
		}
	}
	a.close();
	UpdateData(true);
		m_Straddress+=StrEmail;
	UpdateData(false);		
}

void CNoc_h_SendEmailDlg::OnBUTEmail3() 
{
	//noc ( 含R )
	CString StrFileName;
	CString StrEmail;
	CString StrBuf;
	StrFileName=gstrCurDrt;
	StrFileName+="emaillist\\noc ( 含R ).txt";
	fstream a;
	char fg[500];
	a.open(StrFileName.GetBuffer(0),ios::in);
	StrEmail="";
	while(!a.eof())
	{
		a.getline(fg,500);
		StrBuf=fg;
		if(StrBuf!="")
		{
			StrEmail+=StrBuf;
			StrEmail+=";";
		}
	}
	a.close();
	UpdateData(true);
		m_Straddress+=StrEmail;
	UpdateData(false);	
}

void CNoc_h_SendEmailDlg::OnBUTEmail4() 
{
	//客服人員
	CString StrFileName;
	CString StrEmail;
	CString StrBuf;
	StrFileName=gstrCurDrt;
	StrFileName+="emaillist\\客服人員.txt";
	fstream a;
	char fg[500];
	a.open(StrFileName.GetBuffer(0),ios::in);
	StrEmail="";
	while(!a.eof())
	{
		a.getline(fg,500);
		StrBuf=fg;
		if(StrBuf!="")
		{
			StrEmail+=StrBuf;
			StrEmail+=";";
		}
	}
	a.close();
	UpdateData(true);
		m_Straddress+=StrEmail;
	UpdateData(false);	
}

void CNoc_h_SendEmailDlg::OnBUTEmail5() 
{
	//產品營運(5TV)
	CString StrFileName;
	CString StrEmail;
	CString StrBuf;
	StrFileName=gstrCurDrt;
	StrFileName+="emaillist\\產品營運(5TV).txt";
	fstream a;
	char fg[500];
	a.open(StrFileName.GetBuffer(0),ios::in);
	StrEmail="";
	while(!a.eof())
	{
		a.getline(fg,500);
		StrBuf=fg;
		if(StrBuf!="")
		{
			StrEmail+=StrBuf;
			StrEmail+=";";
		}
	}
	a.close();
	UpdateData(true);
		m_Straddress+=StrEmail;
	UpdateData(false);	
}

void CNoc_h_SendEmailDlg::OnBUTEmail6() 
{
	//技術開發(STB)
	CString StrFileName;
	CString StrEmail;
	CString StrBuf;
	StrFileName=gstrCurDrt;
	StrFileName+="emaillist\\技術開發(STB).txt";
	fstream a;
	char fg[500];
	a.open(StrFileName.GetBuffer(0),ios::in);
	StrEmail="";
	while(!a.eof())
	{
		a.getline(fg,500);
		StrBuf=fg;
		if(StrBuf!="")
		{
			StrEmail+=StrBuf;
			StrEmail+=";";
		}
	}
	a.close();
	UpdateData(true);
		m_Straddress+=StrEmail;
	UpdateData(false);		
}

void CNoc_h_SendEmailDlg::OnBUTEmail7() 
{
	//工程(5TV相關)
	CString StrFileName;
	CString StrEmail;
	CString StrBuf;
	StrFileName=gstrCurDrt;
	StrFileName+="emaillist\\工程(5TV相關).txt";
	fstream a;
	char fg[500];
	a.open(StrFileName.GetBuffer(0),ios::in);
	StrEmail="";
	while(!a.eof())
	{
		a.getline(fg,500);
		StrBuf=fg;
		if(StrBuf!="")
		{
			StrEmail+=StrBuf;
			StrEmail+=";";
		}
	}
	a.close();
	UpdateData(true);
		m_Straddress+=StrEmail;
	UpdateData(false);	
}

void CNoc_h_SendEmailDlg::OnBUTEmail8() 
{
	//資訊中心(內網)
	CString StrFileName;
	CString StrEmail;
	CString StrBuf;
	StrFileName=gstrCurDrt;
	StrFileName+="emaillist\\資訊中心(內網).txt";
	fstream a;
	char fg[500];
	a.open(StrFileName.GetBuffer(0),ios::in);
	StrEmail="";
	while(!a.eof())
	{
		a.getline(fg,500);
		StrBuf=fg;
		if(StrBuf!="")
		{
			StrEmail+=StrBuf;
			StrEmail+=";";
		}
	}
	a.close();
	UpdateData(true);
		m_Straddress+=StrEmail;
	UpdateData(false);		
}

void CNoc_h_SendEmailDlg::OnBUTEmail9() 
{
	//NOWNEWS(影音)
	CString StrFileName;
	CString StrEmail;
	CString StrBuf;
	StrFileName=gstrCurDrt;
	StrFileName+="emaillist\\NOWNEWS(影音).txt";
	fstream a;
	char fg[500];
	a.open(StrFileName.GetBuffer(0),ios::in);
	StrEmail="";
	while(!a.eof())
	{
		a.getline(fg,500);
		StrBuf=fg;
		if(StrBuf!="")
		{
			StrEmail+=StrBuf;
			StrEmail+=";";
		}
	}
	a.close();
	UpdateData(true);
		m_Straddress+=StrEmail;
	UpdateData(false);		
}

void CNoc_h_SendEmailDlg::OnBUTClear() 
{
	// TODO: Add your control notification handler code here
	CString StrBody,StrBuf;
	fstream a;
	char fg[500];
	a.open("sample_body.txt",ios::in);
	while(!a.eof())
	{
		a.getline(fg,500);
		StrBuf=fg;
		StrBody+=StrBuf;
		StrBody+="\r\n";
	}
	a.close();
		
	UpdateData(true);
		m_Strtitle = "網管中心通報 - ";
		m_Straddress = "\"網管中心\"<noc_hsend@tw-airnet.net>;";
	UpdateData(false);
	m_BMP.SetBitmap(LoadBitmap(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDB_BITMAP1)));
}

void CNoc_h_SendEmailDlg::OnBUTOpen() 
{
	// TODO: Add your control notification handler code here
	char *chFileName;
	CString StrBuf,Strfilename;
	fstream a;
	int intcount=0;
	char fg[500];
	///////////////////////////////////////////////
	CFileDialog fdlg(true,NULL,"openfile",NULL,"文字檔|*.txt");
	if(fdlg.DoModal()==IDOK)
	{
		Strfilename=fdlg.GetPathName();
	}
	chFileName=Strfilename.GetBuffer(0);
	//////////////	
	a.open(chFileName,ios::in);
	UpdateData(true);
	m_Strbody="";
	m_Straddress="";
	m_Strtitle="";
	while(!a.eof())
	{
		a.getline(fg,500);
		StrBuf=fg;
		switch(intcount)
		{
			case 0:
				if(StrBuf==""||StrBuf=="\r"||StrBuf=="\n"||StrBuf=="\r\n")
				{
					intcount++;
				}
				else
				{
					m_Straddress =StrBuf;
				}
			break;
			case 1:
				if(StrBuf==""||StrBuf=="\r"||StrBuf=="\n"||StrBuf=="\r\n")
				{
					intcount++;
				}
				else
				{
					m_Strtitle =StrBuf;
				}
			break;
			default:
				if(StrBuf==""||StrBuf=="\r"||StrBuf=="\n"||StrBuf=="\r\n")
				{
					StrBuf="\r\n";
					m_Strbody +=StrBuf;
				}
				else
				{
					m_Strbody +=StrBuf;
					m_Strbody +="\r\n";

				}
		}
	}
	UpdateData(false);
	a.close();
}
