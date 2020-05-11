// SoyalRS232ReaderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SoyalRS232Reader.h"
#include "SoyalRS232ReaderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
TCHAR gstrCurDrt[500];//存放目其目錄字串
int count=0;
FILE *pfile;
bool gblncheck=false;
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
// CSoyalRS232ReaderDlg dialog

CSoyalRS232ReaderDlg::CSoyalRS232ReaderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSoyalRS232ReaderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSoyalRS232ReaderDlg)
	m_v1 = _T("");
	m_v2 = _T("");
	m_v3 = _T("");
	m_v4 = _T("");
	m_v5 = _T("");
	m_v6 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSoyalRS232ReaderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSoyalRS232ReaderDlg)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	DDX_Text(pDX, IDC_EDIT2, m_v2);
	DDX_Text(pDX, IDC_EDIT3, m_v3);
	DDX_Text(pDX, IDC_EDIT4, m_v4);
	DDX_Text(pDX, IDC_EDIT5, m_v5);
	DDX_Text(pDX, IDC_EDIT6, m_v6);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSoyalRS232ReaderDlg, CDialog)
	//{{AFX_MSG_MAP(CSoyalRS232ReaderDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_AutoRead, OnAutoRead)
	ON_WM_DESTROY()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSoyalRS232ReaderDlg message handlers

BOOL CSoyalRS232ReaderDlg::OnInitDialog()
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
	GetandSetParameter();//step 5:讀取XML
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSoyalRS232ReaderDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSoyalRS232ReaderDlg::OnPaint() 
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
HCURSOR CSoyalRS232ReaderDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CSoyalRS232ReaderDlg::GetandSetParameter()//step 4:讀取XML
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
	strFileName1 +="RS232Config.xml";
	blnRead=pDoc->load((_bstr_t)strFileName1); 
	if(blnRead)//第11.0版的功能
	{
			UpdateData(true);
			MSXML2::IXMLDOMNodePtr  NodeData;
			////////////////////////////////////////////////////////////
			NodeData=pDoc->selectSingleNode("//COMPort");	
			NodeData->get_nodeTypedValue(&vtStr);
			m_v1=vtStr.bstrVal;
			//*************************************************
			NodeData=pDoc->selectSingleNode("//BaudRate");	
			NodeData->get_nodeTypedValue(&vtStr);
			m_v2=vtStr.bstrVal;
			//*************************************************
			NodeData=pDoc->selectSingleNode("//ByteSize");	
			NodeData->get_nodeTypedValue(&vtStr);
			m_v3=vtStr.bstrVal;
			//*************************************************
			NodeData=pDoc->selectSingleNode("//Parity");	
			NodeData->get_nodeTypedValue(&vtStr);
			m_v4=vtStr.bstrVal;
			//*************************************************
			NodeData=pDoc->selectSingleNode("//StopBits");	
			NodeData->get_nodeTypedValue(&vtStr);
			m_v5=vtStr.bstrVal;
			UpdateData(false);
	}
}

void CSoyalRS232ReaderDlg::OnAutoRead()//Step 3:RS-232 
{
	// TODO: Add your control notification handler code here
	char *p;
	int v1,v2,v3,v4;
	float v5;
	CString str;
	UpdateData(true);
		p=m_v1.GetBuffer(0);
		v1=atoi(p);
		p=m_v2.GetBuffer(0);
		v2=atoi(p);
		p=m_v3.GetBuffer(0); 
		v3=atoi(p);
		str=m_v4.Mid(9);
		p=str.GetBuffer(0); 
		v4=atoi(p);
		p=m_v5.GetBuffer(0); 
		v5=(float)atof(p);
	UpdateData(false);
	//v1通訊埠
	//v2速度
	//v3資料個數
	//v4同位元
	//v5停止位元
	pRS232=new CRS232();
	pRS232->OpenCom(v1,v2,v3,v4,v5);
	gblncheck=true;
	pfile=fopen("data.txt","a");
	SetTimer(1,1000,NULL);	
}

void CSoyalRS232ReaderDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	if(gblncheck)
	{
		KillTimer(1);
		delete pRS232;
		count=0;
	}
	// TODO: Add your message handler code here
}

void CSoyalRS232ReaderDlg::OnTimer(UINT nIDEvent)//Step 4:RS-232 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent==1)
	{
		/////////////////////////////////
		//讀取資料
		unsigned char d[1024];
		CString StrDataBuf,StrDataBuf1,StrDataBuf2;
		int intdata;
		long number=0;
		char chrbuf1[7];
		UpdateData(true);
			m_v6=L"";
			pRS232->Read(d,&number);
			if(number>0)
			{
				//KillTimer(1);
				StrDataBuf="";
				StrDataBuf1="";
				for(int i=0;i<number;i++)
				{
					intdata=d[i];
					StrDataBuf2="";
					if(i==4||i==5)
					{
						StrDataBuf2.Format("%x",intdata);
						if(StrDataBuf2.GetLength()==2)
						{
							StrDataBuf+=StrDataBuf2;
						}
						else
						{
							StrDataBuf+="0";
							StrDataBuf+=StrDataBuf2;
						}

					}
					if(i==6||i==7)
					{
						StrDataBuf2.Format("%x",intdata);
						if(StrDataBuf2.GetLength()==2)
						{
							StrDataBuf1+=StrDataBuf2;
						}
						else
						{
							StrDataBuf1+="0";
							StrDataBuf1+=StrDataBuf2;
						}
					}
				}
				m_v6=StrDataBuf+StrDataBuf1;
				fprintf(pfile,"%s\t%s\n",StrDataBuf.GetBuffer(0),StrDataBuf1.GetBuffer(0));
				StrDataBuf.Format("%f",Fun16to10(StrDataBuf));
				StrDataBuf1.Format("%f",Fun16to10(StrDataBuf1));
				fprintf(pfile,"%s\t%s\n",StrDataBuf.GetBuffer(0),StrDataBuf1.GetBuffer(0));
			}
			else
			{
				count++;
				m_v6=L"無任何資料";
				itoa(count,chrbuf1,10);
				m_v6+=chrbuf1;
			}
		UpdateData(false);
		/////////////////////////////////
	}	
	CDialog::OnTimer(nIDEvent);
}
float CSoyalRS232ReaderDlg::Fun16to10(CString StrInput)
{
	int i,j,v1,n,ascii,k;
	v1=0;
	n=0;
	k=0;
	char *str=StrInput.GetBuffer(0);//取的16位元字串
	j=strlen(str);//計算字串長度
	for(i=(j-1);i>=0;i--)
	{
		ascii=*(str+i);//由右至左分別取出單獨字元
		if(ascii>=97 && ascii<=102)
		{
			k=10+(ascii-97);
		}
		else if(ascii>=65 && ascii<=72)
		{
			k=10+(ascii-65);
		}
		else if(ascii>=48 && ascii<=57 )
		{
			k=(ascii-48);
		}
		////////////////////////////////
		for(j=n;j>0;j--)//乘上權重
			k*=16;
		/////////////////////////////////
		n++;
		v1+=k;
	}
	return (float)v1;
}