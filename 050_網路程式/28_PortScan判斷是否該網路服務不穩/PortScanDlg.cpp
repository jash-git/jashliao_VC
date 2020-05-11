// PortScanDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PortScan.h"
#include "PortScanDlg.h"

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>

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
// CPortScanDlg dialog

CPortScanDlg::CPortScanDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPortScanDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPortScanDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_pColumns = new CStringList;
	ASSERT(m_pColumns);
	m_bSinglePort = TRUE;
	m_nMaxAttempts = 1;	
	m_pStatusList = new CPtrList;
	ASSERT(m_pStatusList);
}

void CPortScanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPortScanDlg)
	DDX_Control(pDX, IDC_PROGRESS, m_cProgress);
	DDX_Control(pDX, IDC_LIST_RESULT, m_cResult);
	DDX_Control(pDX, IDC_IP_ADDRESS, m_cIP);
	DDX_Control(pDX, IDC_EDIT_SINGLE_PORT_TO, m_cPortTo);
	DDX_Control(pDX, IDC_EDIT_SINGLE_PORT_FROM, m_cPortFrom);
	DDX_Control(pDX, IDC_EDIT_SINGLE_PORT, m_cSinglePort);
	DDX_Control(pDX, IDC_EDIT_ATTEMPTS, m_cAttempts);
	DDX_Control(pDX, IDC_BUTTON_STOP, m_cBtnStop);
	DDX_Control(pDX, IDC_BUTTON_SCAN, m_cBtnScan);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPortScanDlg, CDialog)
	//{{AFX_MSG_MAP(CPortScanDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_RADIO_SINGLE, OnRadioSingle)
	ON_BN_CLICKED(IDC_RADIO_RANGE, OnRadioRange)
	ON_BN_CLICKED(IDC_BUTTON_SCAN, OnButtonScan)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPortScanDlg message handlers

BOOL CPortScanDlg::OnInitDialog()
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
	//给列表框加标题栏
	AddHeader(_T("IP address"));
	AddHeader(_T("Port number"));
	AddHeader(_T("Port Status"));
	AddHeader(_T("Attempts"));
	AddHeader(_T("Remarks"));
	ShowHeaders();

	//设置扫描单个端口
	CheckRadioButton(IDC_RADIO_SINGLE,IDC_RADIO_RANGE,IDC_RADIO_SINGLE);
	
	//设置控件的默认状态
	m_cSinglePort.EnableWindow();
	m_cPortFrom.EnableWindow(FALSE);
	m_cPortTo.EnableWindow(FALSE);
	m_cBtnStop.EnableWindow(FALSE);
	m_cAttempts.SetWindowText(_T("1"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPortScanDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPortScanDlg::OnPaint() 
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
HCURSOR CPortScanDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPortScanDlg::OnDestroy() 
{
	//清除扫描结果
	if (m_pStatusList)
	{
		POSITION p = m_pStatusList->GetHeadPosition();
		while (p)
		{
			POSITION temp = p;
			DATA* pNode = (DATA*)m_pStatusList->GetNext(p);
			m_pStatusList->RemoveAt(temp);
			if (pNode)
				delete pNode;
		}
		delete m_pStatusList;
	}

	CDialog::OnDestroy();	
}

//增加列表框标题栏的某一列
BOOL CPortScanDlg::AddColumn(LPCTSTR strItem,int nItem,int nSubItem,int nMask,int nFmt)
{
	LV_COLUMN lvc;
	lvc.mask = nMask;
	lvc.fmt = nFmt;
	lvc.pszText = (LPTSTR) strItem;
	lvc.cx = m_cResult.GetStringWidth(lvc.pszText) + 25;
	if(nMask & LVCF_SUBITEM)
	{
		if(nSubItem != -1)
			lvc.iSubItem = nSubItem;
		else
			lvc.iSubItem = nItem;
	}
	return m_cResult.InsertColumn(nItem,&lvc);
}

//在列表框中加一条
BOOL CPortScanDlg::AddItem(int nItem,int nSubItem,LPCTSTR strItem ,int nImageIndex)
{
	LV_ITEM lvItem;
	lvItem.mask = LVIF_TEXT;
	lvItem.iItem = nItem;
	lvItem.iSubItem = nSubItem;
	lvItem.pszText = (LPTSTR)strItem;

	if(nImageIndex != -1)
	{
		lvItem.mask |= LVIF_IMAGE;
		lvItem.iImage |= LVIF_IMAGE;
	}

	if(nSubItem == 0)
		return m_cResult.InsertItem(&lvItem);

	return m_cResult.SetItem(&lvItem);
}

//加一列标题栏字符
void CPortScanDlg::AddHeader(LPTSTR hdr)
{
	if (m_pColumns)
		m_pColumns->AddTail(hdr);
}

//显示列表框标题栏
void CPortScanDlg::ShowHeaders()
{
	int nIndex = 0;
	POSITION pos = m_pColumns->GetHeadPosition();
	while(pos)
	{
		CString hdr = (CString)m_pColumns->GetNext(pos);
		AddColumn(hdr,nIndex++);
	}
}

//单击“扫描单个端口”单选按钮
void CPortScanDlg::OnRadioSingle() 
{
	m_bSinglePort = TRUE;
	m_cSinglePort.EnableWindow();
	m_cPortFrom.EnableWindow(FALSE);
	m_cPortTo.EnableWindow(FALSE);
}

//单击“扫描多个端口”单选按钮
void CPortScanDlg::OnRadioRange() 
{
	m_bSinglePort = FALSE;
	m_cSinglePort.EnableWindow(FALSE);
	m_cPortFrom.EnableWindow();
	m_cPortTo.EnableWindow();
	m_cBtnStop.EnableWindow(FALSE);
}

//开始扫描
void CPortScanDlg::OnButtonScan() 
{
	CString btnTxt,IP;
	UINT nSinglePort;
	BYTE f1,f2,f3,f4;
	TCHAR temp[10] = "\0";

	//设置进度条初始位置
	m_cProgress.SetPos(0);

	//清空列表框
	m_cResult.DeleteAllItems();

	//清空扫描结果链表
	POSITION p = m_pStatusList->GetHeadPosition();
	while (p)
	{
		POSITION temp = p;
		DATA* pNode = (DATA*)m_pStatusList->GetNext(p);
		m_pStatusList->RemoveAt(temp);
		if (pNode)
			delete pNode;
	}

	//如果输入没有主机地址
	if (m_cIP.IsBlank())
	{
		MessageBox(_T("Please specify the remote machine's IP address."),
			_T("Error"),
			MB_OK | MB_ICONEXCLAMATION);
		return;
	}
	
	//不合理的IP
	if (m_cIP.GetAddress(f1,f2,f3,f4) < 4)
	{
		MessageBox(_T("Please specify the IP address again."),
			_T("Invalid IP address"),MB_OK | MB_ICONEXCLAMATION);
		return;
	}
	//获得IP字符串
	IP = _itoa(f1,temp,10);
	IP += _T('.');
	IP += _itoa(f2,temp,10);
	IP += _T('.');
	IP += _itoa(f3,temp,10);
	IP += _T('.');
	IP += _itoa(f4,temp,10);

	//设置按钮状态
	m_cBtnStop.EnableWindow();
	m_cBtnScan.EnableWindow(FALSE);

	//扫描单个端口
	if (m_bSinglePort)
	{
		CString port;
		m_cSinglePort.GetWindowText(port);
		m_minPort = m_maxPort = nSinglePort = atoi(port);
	}
	else//扫描多个端口
	{
		CString port1,port2;
		m_cPortFrom.GetWindowText(port1);
		m_cPortTo.GetWindowText(port2);
		m_minPort = atoi(port1);
		m_maxPort = atoi(port2);
		m_cProgress.SetRange32(0,m_maxPort - m_minPort+1);
		m_cProgress.SetStep(1);
	}

	//不合理的端口范围
	if (!m_bSinglePort && m_maxPort < m_minPort)
	{
		MessageBox(_T("The maximum range cannot be less than the minimum one."),
			_T("Caution"),
			MB_OK | MB_ICONINFORMATION);
		return;
	}

	UINT m_nMaxAttempts = GetDlgItemInt(IDC_EDIT_ATTEMPTS);

	for (m_nCounter = m_minPort; m_nCounter <= m_maxPort; m_nCounter++)
	{
		BOOL bIsOpen = FALSE;
		UINT nAttempt = 1;
		
		while(nAttempt <= m_nMaxAttempts && !bIsOpen)
		{
			//显示扫描状态
			TCHAR temp[10]="\0";
			CString str = _T("Trying port# ");

			str += itoa(m_nCounter,temp,10);
			str += _T(", IP Address=");
			str += IP;
			str += _T(", Attempt=");
			str += itoa(nAttempt,temp,10);

			CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STATIC_STATUS);
			pStatic->SetWindowText(str);
			str.Empty();

			//连接主机，测试端口是否打开
			bIsOpen = TestConnection(IP,m_nCounter);

			//如果是打开的，将结果保存到链表中
			if (bIsOpen)
			{
				DATA* pNode = new DATA;
				ASSERT(pNode);
				strcpy(pNode->IPAddress,IP.GetBuffer(IP.GetLength()));
				strcpy(pNode->port,_itoa(m_nCounter,temp,10));
				pNode->bStatus = 1; //open
				pNode->nAttempts = nAttempt;
				m_pStatusList->AddTail(pNode);
			}
			nAttempt++;
		}

		//如果没有被打开，也将结果保存到链表中
		if (!bIsOpen)
		{
			DATA* pNode = new DATA;
			ASSERT(pNode);
			strcpy(pNode->IPAddress,IP.GetBuffer(IP.GetLength()));
			strcpy(pNode->port,_itoa(m_nCounter,temp,10));
			pNode->bStatus = 0; //close
			pNode->nAttempts = nAttempt-1;
			m_pStatusList->AddTail(pNode);
		}
		
		MSG message;
		if (::PeekMessage(&message,NULL,0,0,PM_REMOVE))
		{
			::TranslateMessage(&message);
			::DispatchMessage(&message);
		}
		m_cProgress.StepIt();
	}
	
	//设置扫描完毕状态
	CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STATIC_STATUS);
	pStatic->SetWindowText((CString)_T("Ready"));
	m_cBtnScan.EnableWindow();
	m_cBtnStop.EnableWindow(FALSE);

	//将扫描结果填充到列表框中
	UINT nIndex = 0;
	POSITION pos = m_pStatusList->GetHeadPosition();
	while (pos)
	{
		DATA* pNode = (DATA*)m_pStatusList->GetNext(pos);
		AddItem(nIndex,0,pNode->IPAddress);
		AddItem(nIndex,1,pNode->port);
		if (pNode->bStatus)
		{
			AddItem(nIndex,2,_T("Open"));
			AddItem(nIndex,4,_T("*"));
			MessageBox("OK");
		}
		else
		{
			AddItem(nIndex,2,_T("Close"));
			AddItem(nIndex,4,_T(" "));
			MessageBox("KO");
		}
		AddItem(nIndex++,3,_itoa(pNode->nAttempts,temp,10));
	}	
}

//测试主机的某个端口是否打开
BOOL CPortScanDlg::TestConnection(CString IP, UINT nPort)
{
	//创建套节字
	CSocket* pSocket;
	pSocket = new CSocket;
	ASSERT(pSocket);

	if (!pSocket->Create())
	{
		delete pSocket;
		pSocket = NULL;
		return FALSE;
	}

	//连接主机
	while (!pSocket->Connect(IP , nPort))
	{
		delete pSocket;
		pSocket = NULL;
		return FALSE;
	}

	//清除套节字
	CString data;
	data="user";
	char chrdata[100];
	int i=0,j=0;
	Sleep(5000);
	Sleep(5000);
	i=pSocket->Send(data.GetBuffer(0),data.GetLength());
	Sleep(5000);
	j=pSocket->Receive(chrdata,100); 
	if(i>0 && j>0)
	{
		pSocket->Close();
		delete pSocket;
		MessageBox(chrdata);
		MessageBox("send OK");
		return TRUE;
	}
	else
	{
		pSocket->Close();
		delete pSocket;
		MessageBox("send XXXXXXXX");
		return FALSE;
	}
}

//停止扫描
void CPortScanDlg::OnButtonStop() 
{
	//设置控件状态
	m_nCounter = m_maxPort+1;
	m_cBtnStop.EnableWindow(FALSE);
	m_cBtnScan.EnableWindow();
	CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STATIC_STATUS);
	pStatic->SetWindowText((CString)_T("Ready"));
}

//保存扫描结果到文本文件中
void CPortScanDlg::OnButtonSave() 
{
	//构造文件对话框
	CFileDialog* pDlg = new CFileDialog(FALSE,
		_T("txt"),NULL,
		OFN_OVERWRITEPROMPT | 
		OFN_EXPLORER | OFN_LONGNAMES,
		_T("Scanned ports files (*.txt)"),this);
	ASSERT(pDlg);
	if (pDlg->DoModal() == IDOK)
	{
		int nHandle,retVal;
		//打开文件
		nHandle = _open(pDlg->GetPathName(),_O_BINARY | _O_CREAT | _O_TRUNC | _O_RDWR);
		if (nHandle == -1)
		{
			MessageBox(_T("Unable to open output file to write."),
				_T("Error"),
				MB_OK | MB_ICONEXCLAMATION);
			delete pDlg;
			return;
		}

		//保存结果
		POSITION pos = m_pStatusList->GetHeadPosition();
		while (pos)
		{
			CString buffer;
			DATA* pNode = (DATA*)m_pStatusList->GetNext(pos);
			buffer = pNode->IPAddress;
			buffer += _T(',');
			buffer += pNode->port;
			buffer += _T(',');

			if (pNode->bStatus)
				buffer += _T("Open");
			else
				buffer += _T("Close");

			buffer += _T("\r\n\0");
			retVal = _write(nHandle,
				(void*)buffer.GetBuffer(buffer.GetLength()), 
				buffer.GetLength());
			
			if (retVal != buffer.GetLength())
			{
				MessageBox(_T("An error occured while writing records."),
					_T("Error"),MB_OK | MB_ICONEXCLAMATION);
				delete pDlg;
				return;
			}
			buffer.Empty();
		}
		//关闭文件
		_close(nHandle);
	}
	delete pDlg;
}
