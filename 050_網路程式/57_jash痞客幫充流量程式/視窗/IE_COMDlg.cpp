// IE_COMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "IE_COM.h"
#include "IE_COMDlg.h"
#include<fstream.h>//7
#include <stdlib.h> //srand() ,rand() ,system()
#include <time.h>   //time()
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int gintSize;
int gintindex;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
void Rand_One2N(int intrange,int intstart=1)
{
	srand(time(NULL));
	gintindex=intstart+(rand()%intrange);
}
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
// CIE_COMDlg dialog

CIE_COMDlg::CIE_COMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIE_COMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIE_COMDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIE_COMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIE_COMDlg)
	DDX_Control(pDX, IDC_EXPLORER1, m_ctrlWeb);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CIE_COMDlg, CDialog)
	//{{AFX_MSG_MAP(CIE_COMDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIE_COMDlg message handlers

BOOL CIE_COMDlg::OnInitDialog()
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
	fstream a;
	char fg[700];
	char Num[200];
	char Title[200];
	char Url[200];
	CString StrBuf;
	a.open("jashliaoblog.csv",ios::in);
	while(!a.eof())
	{
		a.getline(fg,500);
		sscanf (fg ,"%[^','],%[^','],%[^','],",Num,Title,Url);
		StrBuf=Url;
		m_UrlArray.Add(StrBuf);
		StrBuf=Title;
		m_TitleArray.Add(StrBuf);;
	}
	gintSize=m_UrlArray.GetSize();
	Rand_One2N(gintSize,0);
	StrBuf=m_UrlArray.GetAt(gintindex);
	COleVariant vaUrl=StrBuf;
	COleVariant vtMissing;
	m_ctrlWeb.Navigate2(&vaUrl,&vtMissing,&vtMissing,&vtMissing,&vtMissing); 
	StrBuf=m_TitleArray.GetAt(gintindex);
	this->SetWindowText(StrBuf); 
	FILE *pf;
	pf=fopen("log.txt","a");
	fprintf(pf,"%s\n",StrBuf.GetBuffer(0));
	fclose(pf);
	SetTimer(1,300000,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CIE_COMDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CIE_COMDlg::OnPaint() 
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
HCURSOR CIE_COMDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BEGIN_EVENTSINK_MAP(CIE_COMDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CIE_COMDlg)
	ON_EVENT(CIE_COMDlg, IDC_EXPLORER1, 104 /* DownloadComplete */, OnDownloadCompleteExplorer1, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CIE_COMDlg::OnDownloadCompleteExplorer1()////3 
{
	//設定標題
	CString StrBuf;
	StrBuf=m_TitleArray.GetAt(gintindex);
	this->SetWindowText(StrBuf); 
}
///////////////////////////5_start
bool CIE_COMDlg::HasItem(IHTMLElementCollection *pobjAllElement,CString strName)
{
	CComPtr<IDispatch>pDisp;
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp);
	if(pDisp==NULL)
		return false;
	else 
		return true; 
}
void CIE_COMDlg::PutIEText(IHTMLElementCollection *pobjAllElement,CString strName,CString strText)
{
	CComPtr<IDispatch> pDisp; 
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp); 
	CComQIPtr<IHTMLInputTextElement,&IID_IHTMLInputTextElement>pElement; 
	if(pDisp==NULL)
	{
		MessageBox(strName + "沒有找到!"); 
	}
	else
	{
		pElement=pDisp; 
		pElement->put_value(strText.AllocSysString()); 
	}
} 
void CIE_COMDlg::SubmitPage(IHTMLElementCollection *pobjAllElement,CString strName)
{
	CComPtr<IDispatch> pDisp; 
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp); 
	CComQIPtr<IHTMLElement, &IID_IHTMLElement>pElement; 
	if(pDisp==NULL)
	{
		AfxMessageBox(strName + "沒有找到!"); 
	}
	else
	{
		pElement=pDisp;
		pElement->click();
	}
} 
void CIE_COMDlg::CheckItem(IHTMLElementCollection *pobjAllElement,CString strName)
{
	CComPtr<IDispatch> pDisp;
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp);
	CComQIPtr<IHTMLElement, &IID_IHTMLElement>pElement;
	if(pDisp==NULL)
	{
		AfxMessageBox(strName + "沒有找到!");
	}
	else
	{
		pElement=pDisp;
		pElement->click();
	}
}
CString CIE_COMDlg::GetHidText(IHTMLElementCollection *pobjAllElement,CString strName)
{
	_bstr_t   bstText;   
	BSTR   bsText;
	CString str;
	CComPtr<IDispatch> pDisp;
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp);
	CComQIPtr < IHTMLInputHiddenElement,&IID_IHTMLInputHiddenElement > pElement;
	if(pDisp==NULL)
	{
		AfxMessageBox(strName + "沒有找到!");
	}
	else
	{
		pElement=pDisp;
		pElement->get_value(&bsText);
		bstText=bsText;
		str=(LPCSTR)bstText;
	}
	return   str; 
}
void CIE_COMDlg::SelectItemValue(IHTMLElementCollection *pobjAllElement,CString strName,long number)
{
	CComPtr<IDispatch> pDisp;
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp);
	CComQIPtr < IHTMLSelectElement,&IID_IHTMLSelectElement > pElement;
	if(pDisp==NULL)
	{
		AfxMessageBox(strName + "沒有找到!");
	}
	else
	{
		pElement=pDisp;
		pElement->put_selectedIndex(number);
	}
}
/////////////////////////5_end
 

void CIE_COMDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	///////////4_start
	CString StrBuf;
	Rand_One2N(gintSize,0);
	StrBuf=m_UrlArray.GetAt(gintindex);
	COleVariant vaUrl=StrBuf;
	COleVariant vtMissing;
	m_ctrlWeb.Navigate2(&vaUrl,&vtMissing,&vtMissing,&vtMissing,&vtMissing); 	
	///////////4_end
	StrBuf=m_TitleArray.GetAt(gintindex);
	FILE *pf;
	pf=fopen("log.txt","a");
	fprintf(pf,"%s\n",StrBuf.GetBuffer(0));
	fclose(pf);
	CDialog::OnTimer(nIDEvent);
}
