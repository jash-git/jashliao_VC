// CSEventPlugin_AnalysisDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CSEventPlugin_Analysis.h"
#include "CSEventPlugin_AnalysisDlg.h"
#include<stdio.h>
#include<fstream.h>
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
// CCSEventPlugin_AnalysisDlg dialog

CCSEventPlugin_AnalysisDlg::CCSEventPlugin_AnalysisDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCSEventPlugin_AnalysisDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCSEventPlugin_AnalysisDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCSEventPlugin_AnalysisDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCSEventPlugin_AnalysisDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCSEventPlugin_AnalysisDlg, CDialog)
	//{{AFX_MSG_MAP(CCSEventPlugin_AnalysisDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTRun, OnBUTRun)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCSEventPlugin_AnalysisDlg message handlers

BOOL CCSEventPlugin_AnalysisDlg::OnInitDialog()
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

void CCSEventPlugin_AnalysisDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCSEventPlugin_AnalysisDlg::OnPaint() 
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
HCURSOR CCSEventPlugin_AnalysisDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCSEventPlugin_AnalysisDlg::OnBUTRun() 
{
	// TODO: Add your control notification handler code here
	CString StrOpenError="on open get data error";//OK
	long lngOpenError=0;//OK
	CString StrRequestError="StrRequestName error";//OK
	long lngRequestError=0;//OK
	CString StrUserID="lngUserID error";//OK
	long lngUserID=0;//OK
	CString StrIPAddressError="StrUserIPAddress error";//OK
	long lngIPAddressError=0;//OK
	CString StrAgentError="StrUserAgent error";//OK
	long lngAgentError=0;//OK
	CString StrControlProtocolError="StrUserControlProtocol error";//OK
	long lngControlProtocolError=0;//OK
	CString StrGuidError="StrUserGuid error";//OK
	long lngGuidError=0;//OK
	CString StrReferserError="StrUserReferser error";//OK
	long lngReferserError=0;//OK
	CString StrCloseError="on close get data error";//OK
	long lngCloseError=0;//OK
	//////////////////////////////
	CString StrCEPermited="The CE Box permited";//OK
	long lngCEPermited=0;//OK
	CString StrChannelPermited="The Channel permited";//OK
	long lngChannelPermited=0;//OK
	CString StrRequestPermited="The RequestName permited";//OK
	long lngRequestPermited=0;//OK
	CString StrIPPermited="The IP permited";//OK
	long lngIPPermited=0;//OK
	CString StrIPDenied="The IP denied";//OK
	long lngIPDenied=0;//OK
	CString StrOpenHttpReturn0="Open Http Post Return = 0";
	long lngOpenHttpReturn0=0;
	CString StrOpenHttpReturn1="Open Http Post Return = 1";
	long lngOpenHttpReturn1=0;
	CString StrCloseHttpReturn0="Close Http Post Return = 0";
	long lngCloseHttpReturn0=0;
	CString StrCloseHttpReturn1="Close Http Post Return = 1";
	long lngCloseHttpReturn1=0;
	CString StrOtherHttpReturn0="Http Post Return = 0";
	long lngOtherHttpReturn0=0;
	/////////////////////////////
	CString StrEventClose="WMS_EVENT_CLOSE,";
	long lngEventClose=0;
	CString StrEventOpen="WMS_EVENT_OPEN,";
	long lngEventOpen=0;
	long lngAllOpen=0;
	fstream a;
	CString Strfg;
	CString StrfgMid;
	char fg[700];
	CFileDialog fdlg(true,NULL,"openfile",NULL,"¤å¦r|*.txt");
	CString Strfilename;
	CString Strfilepath;
	if(fdlg.DoModal()==IDOK)
	{
		Strfilepath=fdlg.GetPathName();
		Strfilename=fdlg.GetFileTitle();
		a.open(Strfilepath.GetBuffer(0),ios::in);
		while(!a.eof())
		{
			a.getline(fg,500);
			Strfg=fg;
			/////////////////////////////////////////////////
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrEventOpen.GetLength());
			if(StrEventOpen==StrfgMid)
			{
				lngEventOpen++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrEventClose.GetLength());
			if(StrEventClose==StrfgMid)
			{
				lngEventClose++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrOpenError.GetLength());
			if(StrOpenError==StrfgMid)
			{
				lngOpenError++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrRequestError.GetLength());
			if(StrRequestError==StrfgMid)
			{
				lngRequestError++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrUserID.GetLength());
			if(StrUserID==StrfgMid)
			{
				lngUserID++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrIPAddressError.GetLength());
			if(StrIPAddressError==StrfgMid)
			{
				lngIPAddressError++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrControlProtocolError.GetLength());
			if(StrControlProtocolError==StrfgMid)
			{
				lngControlProtocolError++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrAgentError.GetLength());
			if(StrAgentError==StrfgMid)
			{
				lngAgentError++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrGuidError.GetLength());
			if(StrGuidError==StrfgMid)
			{
				lngGuidError++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrReferserError.GetLength());
			if(StrReferserError==StrfgMid)
			{
				lngReferserError++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrCloseError.GetLength());
			if(StrCloseError==StrfgMid)
			{
				lngCloseError++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrCEPermited.GetLength());
			if(StrCEPermited==StrfgMid)
			{
				lngCEPermited++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrRequestPermited.GetLength());
			if(StrRequestPermited==StrfgMid)
			{
				lngRequestPermited++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrChannelPermited.GetLength());
			if(StrChannelPermited==StrfgMid)
			{
				lngChannelPermited++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrIPPermited.GetLength());
			if(StrIPPermited==StrfgMid)
			{
				lngIPPermited++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrIPDenied.GetLength());
			if(StrIPDenied==StrfgMid)
			{
				lngIPDenied++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrOpenHttpReturn0.GetLength());
			if(StrOpenHttpReturn0==StrfgMid)
			{
				lngOpenHttpReturn0++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrOpenHttpReturn1.GetLength());
			if(StrOpenHttpReturn1==StrfgMid)
			{
				lngOpenHttpReturn1++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrCloseHttpReturn0.GetLength());
			if(StrCloseHttpReturn0==StrfgMid)
			{
				lngCloseHttpReturn0++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrCloseHttpReturn1.GetLength());
			if(StrCloseHttpReturn1==StrfgMid)
			{
				lngCloseHttpReturn1++;
			}
			//************************************************
			StrfgMid="";
			StrfgMid=Strfg.Mid(0,StrOtherHttpReturn0.GetLength());
			if(StrOtherHttpReturn0==StrfgMid)
			{
				lngOtherHttpReturn0++;
			}
			//////////////////////////////////////////////////
		}
		lngAllOpen=lngOpenHttpReturn1+lngOpenHttpReturn0+lngIPDenied+lngIPPermited+lngRequestPermited+lngChannelPermited+lngRequestError+lngUserID+lngAgentError+lngIPAddressError;
		Strfilename+="_Analysis.csv";
		FILE *pf;
		pf=fopen(Strfilename.GetBuffer(0),"w");
		fprintf(pf,"type,count\n");
		//****************************************************************
		fprintf(pf,"WMS_EVENT_OPEN,%ld\n",lngEventOpen);
		fprintf(pf,"WMS_EVENT_CLOSE,%ld\n",lngEventClose);
		fprintf(pf,"on open get data error,%ld\n",lngOpenError);
		fprintf(pf,"StrRequestName error,%ld\n",lngRequestError);
		fprintf(pf,"lngUserID error,%ld\n",lngUserID);
		fprintf(pf,"StrUserIPAddress error,%ld\n",lngIPAddressError);
		fprintf(pf,"StrUserControlProtocol error,%ld\n",lngControlProtocolError);
		fprintf(pf,"StrUserAgent error,%ld\n",lngAgentError);
		fprintf(pf,"StrUserGuid error,%ld\n",lngGuidError);
		fprintf(pf,"StrUserReferser error,%ld\n",lngReferserError);
		fprintf(pf,"on close get data error,%ld\n",lngCloseError);
		fprintf(pf,"The CE Box permited,%ld\n",lngCEPermited);
		fprintf(pf,"The Channel permited,%ld\n",lngChannelPermited);
		fprintf(pf,"The RequestName permited,%ld\n",lngChannelPermited);
		fprintf(pf,"The IP permited,%ld\n",lngIPPermited);
		fprintf(pf,"The IP denied,%ld\n",lngIPDenied);
		fprintf(pf,"Open Http Post Return = 0,%ld\n",lngOpenHttpReturn0);
		fprintf(pf,"Open Http Post Return = 1,%ld\n",lngOpenHttpReturn1);
		fprintf(pf,"Close Http Post Return = 0,%ld\n",lngCloseHttpReturn0);
		fprintf(pf,"Close Http Post Return = 1,%ld\n",lngCloseHttpReturn1);	
		fprintf(pf,"All Open,%ld,OpenHttpReturn1+OpenHttpReturn0+IPDenied+lngIPPermited+RequestPermited+ChannelPermited+RequestError+UserID+AgentError+IPAddressError\n",lngAllOpen);
		fprintf(pf,"Real denied,%ld,(Other Http Return 0/4)+IP denied+'Http Post Return=0'-CE Box permited",((lngOtherHttpReturn0/4)+lngIPDenied+lngOpenHttpReturn0-lngCEPermited));
		fclose(pf);
		MessageBox("finish...");
	}
	
}
