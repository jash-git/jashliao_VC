// DownLoad_RSS_WMVDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DownLoad_RSS_WMV.h"
#include "DownLoad_RSS_WMVDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define BUFFER_SIZE 2048
TCHAR gstrCurDrt[500];//存放目其目錄字串
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
// CDownLoad_RSS_WMVDlg dialog

CDownLoad_RSS_WMVDlg::CDownLoad_RSS_WMVDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDownLoad_RSS_WMVDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDownLoad_RSS_WMVDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDownLoad_RSS_WMVDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownLoad_RSS_WMVDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownLoad_RSS_WMVDlg, CDialog)
	//{{AFX_MSG_MAP(CDownLoad_RSS_WMVDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDownLoad_RSS_WMVDlg message handlers

BOOL CDownLoad_RSS_WMVDlg::OnInitDialog()
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
	SetTimer(1,1000,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDownLoad_RSS_WMVDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDownLoad_RSS_WMVDlg::OnPaint() 
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
HCURSOR CDownLoad_RSS_WMVDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
bool CDownLoad_RSS_WMVDlg::GetWebFile(CString theUrl, CString Filename)
{
    CInternetSession session;
    CInternetFile* file = NULL;
    try
    {
        // Try to connect with the URL
        file = (CInternetFile*)session.OpenURL(theUrl); 
    }
    catch (CInternetException* m_pException)
    {
        // if some error occurs, set the file with NULL
        file = NULL; 
        m_pException->Delete();
        return FALSE;
    }

    BOOL bRet = FALSE;
    // use dataStore to save the file content
    CStdioFile dataStore;
    if(dataStore.Open(Filename, CFile::modeCreate | CFile::modeWrite | CFile::shareDenyWrite | CFile::typeBinary))
    {
        if (file)
        {
            UINT somelen = 0;
            BYTE somecode[BUFFER_SIZE];
            while((somelen = file->Read(somecode, BUFFER_SIZE)) > 0)
            {
                dataStore.Write(somecode, somelen);
            }
            bRet = TRUE;
        }
        dataStore.Close();
    }
    if(file)
    {
        file->Close();
        delete file;
    }
    return bRet;
}

void CDownLoad_RSS_WMVDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	//http://www.newdaai.tv/?view=rsstest&id=1&date=2010-06-21
	KillTimer(1);
	CString StrUrl,StrBuf,StrDate;
	StrUrl="http://www.newdaai.tv/?view=rsstest&id=1&date=";
	CTime NowTime=CTime::GetCurrentTime();
	StrBuf.Format("%d-",NowTime.GetYear());
	StrDate=StrBuf;
	if(NowTime.GetMonth()>9)
	{
		StrBuf.Format("%d-",NowTime.GetMonth());
	}
	else
	{
		StrBuf.Format("0%d-",NowTime.GetMonth());
	}
	StrDate+=StrBuf;
	if(NowTime.GetDay()>9)
	{
		StrBuf.Format("%d",NowTime.GetDay());
	}
	else
	{
		StrBuf.Format("0%d",NowTime.GetDay());
	}
	StrDate+=StrBuf;
	StrUrl+=StrDate;
	StrBuf=StrDate;
	StrBuf+=".xml";
	//MessageBox(StrDate);
	if(GetWebFile(StrUrl,StrBuf))
	{
		ReadRSSXML(StrBuf);
		this->OnOK();
	}
	else
	{
		SetTimer(1,1000,NULL);
	}
	CDialog::OnTimer(nIDEvent);
}
void CDownLoad_RSS_WMVDlg::ReadRSSXML(CString Filename)
{
	MSXML2::IXMLDOMDocumentPtr pDoc;
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
	strFileName1 +=Filename;
	bool blnRead=pDoc->load((_bstr_t)strFileName1);
	int i,j,k,l,m,n;
	if(blnRead)
	{
		MSXML2::IXMLDOMNodePtr pNodeRoot;
		MSXML2::IXMLDOMNodePtr pNodechild;
		MSXML2::IXMLDOMNodeListPtr pRootNodes;
		MSXML2::IXMLDOMNodeListPtr pchildNodes;
		//MSXML2::IXMLDOMNamedNodeMapPtr pAttrMap=NULL;
		pRootNodes=pDoc->selectNodes("//item");
		i=0,k=0;
		j=pRootNodes->length;
		for(i=0;i<j;i++)
		{
			pNodeRoot=pRootNodes->item[i];
			pNodeRoot->get_childNodes(&pchildNodes);
			l=pchildNodes->length;
			for(k=0;k<l;k++)
			{
				_variant_t vtStr;
				CString StrValue;
				pNodechild=pchildNodes->item[k];
				pNodechild->get_nodeTypedValue(&vtStr);
				StrValue=vtStr.bstrVal; 
				if(k==2)
				{
					CString StrUrl;
					CString StrBuf;
					bool blnStart,blnEnd;
					blnStart=false;
					blnEnd=false;
					n=StrValue.GetLength();
					for(m=(n-1);m>=0;m--)
					{
						StrBuf=StrValue.Mid(m,1);
						if(StrBuf=="<")
						{
							blnStart=true;
						}
						if(StrBuf==">"&& (blnStart==true))
						{
							blnEnd=true;
							break;
						}
						if(blnStart && StrBuf!="<" && (blnEnd==false))
						{
							StrUrl=StrBuf+StrUrl;
						}
					}
					StrBuf=StrUrl.Mid(0,19);
					if(StrBuf=="http://vod.daai.tv/")
					{
						CString StrFileName;
						n=StrUrl.GetLength();
						for(m=(n-1);m>=0;m--)
						{
							StrBuf=StrUrl.Mid(m,1);
							if(StrBuf!="/")
							{
								StrFileName=StrBuf+StrFileName;
							}
							else
							{
								break;
							}
						}
						GetWebFile(StrUrl,StrFileName);
					}
				}
			}
		}
	}//pDoc->load((_bstr_t)strFileName1);
}