// VDlg.cpp : implementation file
//

#include "stdafx.h"
#include "V.h"
#include "VDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define AW_HOR_POSITIVE             0x00000001
#define AW_HOR_NEGATIVE             0x00000002
#define AW_VER_POSITIVE             0x00000004
#define AW_VER_NEGATIVE             0x00000008
#define AW_CENTER                   0x00000010
#define AW_HIDE                     0x00010000
#define AW_ACTIVATE                 0x00020000
#define AW_SLIDE                    0x00040000
#define AW_BLEND                    0x00080000
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CLink	m_link2;
	CLink	m_link1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual void OnOK();
	afx_msg void OnLink();
	afx_msg void OnLink2();
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
	DDX_Control(pDX, IDC_LINK2, m_link2);
	DDX_Control(pDX, IDC_LINK, m_link1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_BN_CLICKED(IDC_LINK, OnLink)
	ON_BN_CLICKED(IDC_LINK2, OnLink2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVDlg dialog

CVDlg::CVDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVDlg)
	m_bMini = AfxGetApp()->GetProfileInt("Setting","bMini",0);
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_mmv.Create(this,MIXERLINE_COMPONENTTYPE_DST_SPEAKERS,-1);
	m_pDlg=new CPPDlg;
	m_pDlg->Create(IDD_PP);
	m_pProgress=&m_pDlg->m_p;
	m_pSld=&m_pDlg->m_sld;

	
	DWORD vl;
	m_VControl.Create(this,MIXERLINE_COMPONENTTYPE_DST_SPEAKERS,-1,MIXERCONTROL_CONTROLTYPE_VOLUME);
	m_VControl.GetValue(&vl,&vl); 

 	m_pProgress->SetRange32(m_VControl.GetMin(),m_VControl.GetMax());
 	m_pProgress->SetPos(vl); 

//	m_pSld->SetTicFreq(m_VControl.GetMax()/15); 
	m_pSld->SetRange(m_VControl.GetMin(),m_VControl.GetMax());
	m_pSld->SetPos(vl);


	
}

void CVDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVDlg)
	DDX_Control(pDX, IDC_HOTKEY3, m_hot3);
	DDX_Control(pDX, IDC_HOTKEY2, m_hot2);
	DDX_Control(pDX, IDC_HOTKEY1, m_hot1);
	DDX_Check(pDX, IDC_MINIMIZED, m_bMini);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CVDlg, CDialog)
	//{{AFX_MSG_MAP(CVDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_HOTKEY,OnHotKey)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_MESSAGE(MM_MIXM_CONTROL_CHANGE, OnMixerChange)
	ON_BN_CLICKED(IDC_MINIMIZED, OnMinimized)
	ON_MESSAGE(WM_MY_NOTIFYICON,OnMyIconNotify)      //消息映射
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_ABOUT, OnAbout)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(IDC_SET, OnSet)
	ON_WM_CTLCOLOR()
	ON_WM_CREATE()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVDlg message handlers
void CVDlg::OnSave() 
{
	UpdateData();
	
	WORD vk1, sk1,  vk2,sk2, vk3,sk3;
	m_hot1.GetHotKey(vk1, sk1);
	m_hot2.GetHotKey(vk2,sk2);
	m_hot3.GetHotKey(vk3,sk3);
	
	AfxGetApp()->WriteProfileInt("HotKey","sk1",sk1);
	AfxGetApp()->WriteProfileInt("HotKey","vk1",vk1);
	AfxGetApp()->WriteProfileInt("HotKey","sk2",sk2);
	AfxGetApp()->WriteProfileInt("HotKey","vk2",vk2);
	AfxGetApp()->WriteProfileInt("HotKey","sk3",sk3);
	AfxGetApp()->WriteProfileInt("HotKey","vk3",vk3);

	
	UINT fs1 = 0;
	if (sk1 & HOTKEYF_ALT)	    fs1|= MOD_ALT;
	if (sk1 & HOTKEYF_CONTROL)   fs1|= MOD_CONTROL;
	if (sk1 & HOTKEYF_SHIFT) 	fs1|= MOD_SHIFT; 	
	
	UINT fs2 = 0;
	if (sk2 & HOTKEYF_ALT)	    fs2|= MOD_ALT;
	if (sk2 & HOTKEYF_CONTROL)   fs2|= MOD_CONTROL;
	if (sk2 & HOTKEYF_SHIFT) 	fs2|= MOD_SHIFT; 	

	UINT fs3 = 0;
	if (sk3 & HOTKEYF_ALT)	    fs3|= MOD_ALT;
	if (sk3 & HOTKEYF_CONTROL)   fs3|= MOD_CONTROL;
	if (sk3 & HOTKEYF_SHIFT) 	fs3|= MOD_SHIFT; 	

	BOOL bb=true;
	CString str;
	if(!::RegisterHotKey(m_hWnd, 111, fs1, vk1))
	{
		str="增大音量 ";
		bb=false;
	}	
	if(!::RegisterHotKey(m_hWnd, 222, fs2, vk2))
	{
		str="减小音量 ";
		bb=false;
	}
	if(!::RegisterHotKey(m_hWnd, 333, fs3, vk3))
	{
		str="静音开关 ";
		bb=false;
	}
	SetDlgItemText(IDC_STATE,bb?" 设置热键成功!":str+" 热键设置失败!");


}

void CVDlg::OnDestroy() 
{
	CDialog::OnDestroy();

	m_pDlg->DestroyWindow();
	delete m_pDlg;

	m_mmv.Close();
	m_VControl.Close();

	::UnregisterHotKey(m_hWnd,301);
	TaskBarDeleteIcon(GetSafeHwnd(),500);




}

void CVDlg::OnTimer(UINT nIDEvent) 
{
	//new CFaderWnd(this);
 	m_pDlg->ShowWindow(SW_HIDE);


	KillTimer(1);
	CDialog::OnTimer(nIDEvent);
}

void CVDlg::OnMixerChange(WPARAM wparam, LPARAM lparam)
{
	DWORD vl;
	if((DWORD)lparam==m_VControl.m_ControlID)
	{
		m_VControl.GetValue(&vl,&vl);
		m_pProgress->SetPos(vl);
	}

	else if((DWORD)lparam==m_mmv.m_controlid)
	{
		m_pDlg->m_icon.SetIcon(m_mmv.GetValue()?
							AfxGetApp()->LoadIcon(IDI_2):
							AfxGetApp()->LoadIcon(IDI_1));
	}

}

LRESULT CVDlg::OnHotKey(WPARAM wp,LPARAM lp)   //热键处理函数
{
    		
	CString strPos;
	int nn;
	SetTimer(1,1000,NULL);

	if(!m_pDlg->IsWindowVisible())
	{
		int xx=::GetSystemMetrics(SM_CXSCREEN);
		int yy=::GetSystemMetrics(SM_CYSCREEN);

		CRect rc;
		m_pDlg->GetWindowRect(rc);
 		m_pDlg->ShowWindow(SW_SHOWNORMAL);
		m_pDlg->SetWindowPos(&CWnd::wndTopMost,(xx-rc.Width())/2,yy-100,0,0,SWP_NOSIZE);
	}
	
	switch(wp)
	{
	case 111:
		m_pSld->SetPos(m_pSld->GetPos()+3000);		
		nn=m_pSld->GetPos();
		m_pProgress->SetPos(nn);
		m_VControl.SetValue(nn,nn);
		break;
	
	case 222:	 
		m_pSld->SetPos(m_pSld->GetPos()-3000);		
		nn=m_pSld->GetPos();
		m_pProgress->SetPos(nn);
		m_VControl.SetValue(nn,nn);
		break;
		
	case 333:
		m_mmv.SetValue(m_mmv.GetValue()? 0:1);		
		m_pDlg->m_icon.SetIcon(m_mmv.GetValue()?
								AfxGetApp()->LoadIcon(IDI_2):
								AfxGetApp()->LoadIcon(IDI_1));
		
		break;
	}


	return 0;
}

BOOL CVDlg::OnInitDialog()
{
	CDialog::OnInitDialog();


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

	m_font.CreateFont(12, 0,0,0,FW_BOLD, 0,0,0,
		DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "宋体");
	GetDlgItem(IDC_STATE)->SetFont(&m_font);
	SetDlgItemText(IDC_STATE,"欢迎使用!");

	
	m_pDlg->m_icon.SetIcon(m_mmv.GetValue()?
							AfxGetApp()->LoadIcon(IDI_2):
							AfxGetApp()->LoadIcon(IDI_1));
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	WORD vk1=AfxGetApp()->GetProfileInt("HotKey","vk1",0);
	WORD sk1=AfxGetApp()->GetProfileInt("HotKey","sk1",0);
	m_hot1.SetHotKey(vk1, sk1);	

	WORD vk2=AfxGetApp()->GetProfileInt("HotKey","vk2",0);
	WORD sk2=AfxGetApp()->GetProfileInt("HotKey","sk2",0);
	m_hot2.SetHotKey(vk2, sk2);	

	WORD vk3=AfxGetApp()->GetProfileInt("HotKey","vk3",0);
	WORD sk3=AfxGetApp()->GetProfileInt("HotKey","sk3",0);
	m_hot3.SetHotKey(vk3,sk3);	

	
	UINT fs1 = 0;
	if (sk1 & HOTKEYF_ALT)	    fs1|= MOD_ALT;
	if (sk1 & HOTKEYF_CONTROL)   fs1|= MOD_CONTROL;
	if (sk1 & HOTKEYF_SHIFT) 	fs1|= MOD_SHIFT; 	
	::RegisterHotKey(m_hWnd, 111, fs1, vk1);		

	UINT fs2 = 0;
	if (sk2 & HOTKEYF_ALT)	    fs2|= MOD_ALT;
	if (sk2 & HOTKEYF_CONTROL)   fs2|= MOD_CONTROL;
	if (sk2 & HOTKEYF_SHIFT) 	fs2|= MOD_SHIFT; 	
	::RegisterHotKey(m_hWnd, 222, fs2, vk2);		

	UINT fs3 = 0;
	if (sk3 & HOTKEYF_ALT)	    fs3|= MOD_ALT;
	if (sk3 & HOTKEYF_CONTROL)   fs3|= MOD_CONTROL;
	if (sk3 & HOTKEYF_SHIFT) 	fs3|= MOD_SHIFT; 	
	::RegisterHotKey(m_hWnd, 333, fs3, vk3);	

	if(this->m_bMini)
		PostMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
  
	TaskBarAddIcon(GetSafeHwnd(),500,AfxGetApp()->LoadIcon(IDR_MAINFRAME),_T("音量控制-三峡大学"),true);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CVDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}

	
	if(nID==SC_MINIMIZE)
	{
		new CFaderWnd(this);
		ShowWindow(SW_HIDE);
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVDlg::OnPaint() 
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
HCURSOR CVDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

 


void CVDlg::OnMinimized() 
{
	UpdateData(true);
	AfxGetApp()->WriteProfileInt("Setting","bMini",m_bMini? 1:0);
	
}

BOOL CVDlg::TaskBarAddIcon(HWND hwnd, UINT uID, HICON hicon, LPSTR lpszTip, BOOL bb)
{
	NOTIFYICONDATA d;
	d.cbSize=sizeof(NOTIFYICONDATA);
	d.hWnd=hwnd;
	d.uID=uID;
	d.uFlags=NIF_ICON | NIF_TIP | NIF_MESSAGE;
	d.uCallbackMessage=WM_MY_NOTIFYICON;
	d.hIcon=hicon;
	
	if(lpszTip)
		lstrcpy(d.szTip,lpszTip);
	else
		d.szTip[0]='\0';
	return Shell_NotifyIcon(bb? NIM_ADD:NIM_MODIFY,&d);  //bb为TRUE时，添加图标，bb为FALSE时修改图标
}

BOOL CVDlg::TaskBarDeleteIcon(HWND hwnd, UINT uID)
{

		NOTIFYICONDATA d;
		d.cbSize=sizeof(NOTIFYICONDATA);
		d.hWnd=hwnd;
		d.uID=uID;

		return Shell_NotifyIcon(NIM_DELETE,&d);
}

void CVDlg::OnMyIconNotify(WPARAM wParam,LPARAM lParam)    //处理消息
{
	UINT uMouseMsg=LOWORD(lParam);
	switch(uMouseMsg)
	{
	case WM_LBUTTONDBLCLK:	
		{
			new CFaderWnd(this);
			ShowWindow(IsWindowVisible()? SW_HIDE:SW_SHOWNORMAL);	
		}
		break;
	case WM_RBUTTONDOWN:
		{
			CPoint point;
			GetCursorPos(&point);
			this->SetForegroundWindow();  //最好加上这一句，这样当不选择弹出菜单项时，菜单可以消失掉
			
			COfficeXPMenu m_pop;
			m_pop.LoadMenu(IDR_MENU1);			
			m_pop.SetType(TYPE_XP);
			m_pop.LoadToolbar(IDR_TOOLBAR1);
			CMenu *psub = m_pop.GetSubMenu(0); //获取第一个子菜单的指针
			psub->SetDefaultItem(0,true);      //设置默认项
			DWORD dwID =psub->TrackPopupMenu((TPM_LEFTALIGN|TPM_RIGHTBUTTON),
					   		  point.x,point.y, this); 
		}
		break;  
	}
}


void CVDlg::OnExit() 
{
	SendMessage(WM_CLOSE,0,0);

}

void CVDlg::OnAbout() 
{
	new CFaderWnd(this);

	CAboutDlg dlg;
	dlg.DoModal();
}

void CVDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{

	SendMessage(WM_NCLBUTTONDOWN,HTCAPTION,0);
	CDialog::OnLButtonDown(nFlags, point);
}

void CAboutDlg::OnOK() 
{
	new CFaderWnd(this);
	CDialog::OnOK();
	
}

void CAboutDlg::OnLink() 
{
	::ShellExecute(NULL,"open","mailto:chx20@163.com",NULL,NULL,SW_SHOW);


	
}

void CAboutDlg::OnLink2() 
{
	::ShellExecute(NULL,"open","http://www.ctgu.edu.cn",NULL,NULL,SW_SHOW);
	
}

void CVDlg::OnSet() 
{

	new CFaderWnd(this);
	ShowWindow(SW_SHOW);

}

HBRUSH CVDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	

	if(pWnd->GetDlgCtrlID()==IDC_STATE)
		pDC->SetTextColor(RGB(41,105,222));
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CVDlg::PreTranslateMessage(MSG* pMsg) 
{
    if(pMsg -> message == WM_KEYDOWN)
	{
        if(pMsg -> wParam == VK_ESCAPE)
			return TRUE;
		if(pMsg -> wParam == VK_RETURN)
			return TRUE;
	}	
	
	return CDialog::PreTranslateMessage(pMsg);
}

int CVDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
 	
	
	return 0;
}

void CVDlg::OnClose() 
{
	typedef UINT (CALLBACK* LPFUN)(HWND hwnd, DWORD dwTime,DWORD dwFlags); //定义AnimateWindow的函数指针
	LPFUN p;	
	HINSTANCE hInst=::LoadLibrary("user32.dll");
	
	p = (LPFUN)::GetProcAddress(hInst, "AnimateWindow" );
	
	p(GetSafeHwnd(), 300,AW_BLEND|AW_HIDE);
	
	::FreeLibrary(hInst );	
	CDialog::OnClose();
}
