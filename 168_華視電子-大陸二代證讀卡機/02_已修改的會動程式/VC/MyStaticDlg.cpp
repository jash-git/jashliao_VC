// MyStaticDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyStatic.h"
#include "MyStaticDlg.h"
#include "resource.h"
#include <vector>
#include <string>


lpCVR_InitComm CVR_InitComm						= NULL;
lpCVR_CloseComm CVR_CloseComm					= NULL;
lpCVR_Authenticate CVR_Authenticate				= NULL;
lpCVR_Read_Content CVR_Read_Content				= NULL;
lpCVR_GetSAMIDU CVR_GetSAMID					= NULL;

lpGetPeopleChineseName CVR_GetPeopleChineseName	= NULL;
lpGetPeopleCertVersion CVR_GetPeopleCertVersion	= NULL;

lpGetPeopleName CVR_GetPeopleName				= NULL;
lpGetPeopleSex CVR_GetPeopleSex					= NULL;
lpGetPeopleNation CVR_GetPeopleNation			= NULL;
lpGetPeopleBirthday CVR_GetPeopleBirthday		= NULL;
lpGetPeopleAddress CVR_GetPeopleAddress			= NULL;
lpGetPeopleIDCode CVR_GetPeopleIDCode			= NULL;
lpGetDepartment CVR_GetDepartment				= NULL;
lpGetStartDate CVR_GetStartDate					= NULL;
lpGetEndDate CVR_GetEndDate						= NULL;
lpGetNationCode CVR_GetNationCode				= NULL;
lpGetNationCodeStrU CVR_GetNationCodeStrU		= NULL;
lpGetNewAppMsgU CVR_GetNewAppAddressU			= NULL;
lpGetCertTypeU CVR_GetCertTypeU					= NULL;
lpGetBMPData CVR_GetBmpData						= NULL;
lpGetFPDate CVR_GetFPDate						= NULL;

HINSTANCE g_dllHandle							= NULL;


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyStaticDlg dialog

CMyStaticDlg::CMyStaticDlg(CWnd* pParent /*=NULL*/)
: CDialog(CMyStaticDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyStaticDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1); //
}

void CMyStaticDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_CERT_TYPE, m_tab);
}

BEGIN_MESSAGE_MAP(CMyStaticDlg, CDialog)
	//{{AFX_MSG_MAP(CMyStaticDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()		
	//}}AFX_MSG_MAP
	ON_WM_CLOSE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_CERT_TYPE, &CMyStaticDlg::OnTcnSelchangeTabCertType)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyStaticDlg message handlers

BOOL CMyStaticDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	TCHAR	szExePath[MAX_PATH];
	GetModuleFileName(AfxGetApp()->m_hInstance, szExePath, sizeof(szExePath));

	CString szDLLPath(szExePath);
	int nPos = szDLLPath.ReverseFind(_T('\\')) + 1;
	szExePath[nPos] = _T('\0');
	szDLLPath.Format(_T("%s%s"), szExePath, _T("termb.dll"));

	//CString szDLLPath(_T("C:\\CertReader\\HS_RdCard\\termb.dll"));

	g_dllHandle = LoadLibrary(szDLLPath);
	if (g_dllHandle != NULL)
	{
		CVR_InitComm			= (lpCVR_InitComm)GetProcAddress(g_dllHandle,"CVR_InitComm");
		CVR_CloseComm			= (lpCVR_CloseComm)GetProcAddress(g_dllHandle,"CVR_CloseComm");
		CVR_Authenticate		= (lpCVR_Authenticate)GetProcAddress(g_dllHandle,"CVR_Authenticate");
		CVR_Read_Content		= (lpCVR_Read_Content)GetProcAddress(g_dllHandle,"CVR_Read_FPContent");
#ifdef UNICODE
		CVR_GetPeopleName			= (lpGetPeopleName)GetProcAddress(g_dllHandle,"GetPeopleNameU");
		CVR_GetPeopleSex			= (lpGetPeopleSex)GetProcAddress(g_dllHandle,"GetPeopleSexU");
		CVR_GetPeopleNation			= (lpGetPeopleNation)GetProcAddress(g_dllHandle,"GetPeopleNationU");
		CVR_GetPeopleBirthday		= (lpGetPeopleBirthday)GetProcAddress(g_dllHandle,"GetPeopleBirthdayU");
		CVR_GetPeopleAddress		= (lpGetPeopleAddress)GetProcAddress(g_dllHandle,"GetPeopleAddressU");
		CVR_GetPeopleIDCode			= (lpGetPeopleIDCode)GetProcAddress(g_dllHandle,"GetPeopleIDCodeU");
		CVR_GetDepartment			= (lpGetDepartment)GetProcAddress(g_dllHandle,"GetDepartmentU");
		CVR_GetStartDate			= (lpGetStartDate)GetProcAddress(g_dllHandle,"GetStartDateU");
		CVR_GetEndDate				= (lpGetEndDate)GetProcAddress(g_dllHandle,"GetEndDateU");
		CVR_GetSAMID				= (lpCVR_GetSAMIDU)GetProcAddress(g_dllHandle,"CVR_GetSAMIDU");
		CVR_GetPeopleChineseName	= (lpGetPeopleChineseName)GetProcAddress(g_dllHandle,"GetPeopleChineseNameU");
		CVR_GetPeopleCertVersion	= (lpGetPeopleCertVersion)GetProcAddress(g_dllHandle,"GetPeopleCertVersionU");
		CVR_GetNationCodeStrU		= (lpGetNationCodeStrU)GetProcAddress(g_dllHandle,"GetNationCodeU");
		CVR_GetNewAppAddressU		= (lpGetNewAppMsgU)GetProcAddress(g_dllHandle,"GetNewAppMsgU");
		CVR_GetCertTypeU			= (lpGetCertTypeU)GetProcAddress(g_dllHandle,"GetCertTypeU");
		CVR_GetBmpData				= (lpGetBMPData)GetProcAddress(g_dllHandle,"GetBMPData");
		CVR_GetNationCode			= (lpGetNationCode)GetProcAddress(g_dllHandle,"GetNationCodeU");
#else
		CVR_GetPeopleName			= (lpGetPeopleName)GetProcAddress(g_dllHandle,"GetPeopleName");
		CVR_GetPeopleSex			= (lpGetPeopleSex)GetProcAddress(g_dllHandle,"GetPeopleSex");
		CVR_GetPeopleNation			= (lpGetPeopleNation)GetProcAddress(g_dllHandle,"GetPeopleNation");
		CVR_GetPeopleBirthday		= (lpGetPeopleBirthday)GetProcAddress(g_dllHandle,"GetPeopleBirthday");
		CVR_GetPeopleAddress		= (lpGetPeopleAddress)GetProcAddress(g_dllHandle,"GetPeopleAddress");
		CVR_GetPeopleIDCode			= (lpGetPeopleIDCode)GetProcAddress(g_dllHandle,"GetPeopleIDCode");
		CVR_GetDepartment			= (lpGetDepartment)GetProcAddress(g_dllHandle,"GetDepartment");
		CVR_GetStartDate			= (lpGetStartDate)GetProcAddress(g_dllHandle,"GetStartDate");
		CVR_GetEndDate				= (lpGetEndDate)GetProcAddress(g_dllHandle,"GetEndDate");
		CVR_GetPeopleChineseName	= (lpCVR_GetSAMIDU)GetProcAddress(g_dllHandle,"GetPeopleChineseName");
		CVR_GetPeopleCertVersion	= (lpCVR_GetSAMIDU)GetProcAddress(g_dllHandle,"GetPeopleCertVersion");
		CVR_GetNationCode			= (lpGetNationCode)GetProcAddress(g_dllHandle,"GetNationCode");
#endif
	}

	// TODO: Add extra initialization here	

	m_tab.InsertItem(0, _T("读身份证"));
	m_tab.InsertItem(1, _T("读外国人永久居留证"));
	m_tab.InsertItem(2, _T("读卡设置"));

	m_idCardDlg.Create(IDD_IDCARDDLG, this);
	m_prCardDlg.Create(IDD_PRCARDDLG, this);
	m_settingDlg.Create(IDD_SETTINGDLG, this);

	CRect rs;
	m_tab.GetClientRect(&rs);
	m_tab.MapWindowPoints(this, rs);
	rs.top		+= 20;
	rs.bottom	-= 2;
	rs.left		+= 1;
	rs.right	-= 2;

	m_idCardDlg.MoveWindow(&rs);
	m_idCardDlg.ShowWindow(SW_SHOW);
	m_prCardDlg.MoveWindow(&rs);
	m_settingDlg.MoveWindow(&rs);

	m_idCardDlg.SetReadParam(m_settingDlg.m_nPort, m_settingDlg.m_nTimer, m_settingDlg.m_nRepeat);
	m_prCardDlg.SetReadParam(m_settingDlg.m_nPort, m_settingDlg.m_nTimer, m_settingDlg.m_nRepeat);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.


void CMyStaticDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc1(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc1.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc1.DrawIcon(x, y, m_hIcon);  
	}
	else
	{
		CDialog::OnPaint();
	}

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyStaticDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyStaticDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	if(CVR_CloseComm)
		CVR_CloseComm(); 
	::PostQuitMessage(0);
}


BOOL CMyStaticDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE ) return TRUE;
	return CDialog::PreTranslateMessage(pMsg);
}

void CMyStaticDlg::OnTcnSelchangeTabCertType(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;

	int CurSel = m_tab.GetCurSel();
	switch(CurSel)
	{
	case 0:
		m_idCardDlg.ShowWindow(SW_SHOW);
		m_prCardDlg.ShowWindow(SW_HIDE);
		m_settingDlg.ShowWindow(SW_HIDE);
		break;
	case 1:
		m_idCardDlg.ShowWindow(SW_HIDE);
		m_prCardDlg.ShowWindow(SW_SHOW);
		m_settingDlg.ShowWindow(SW_HIDE);
		break;
	case 2:
		m_idCardDlg.ShowWindow(SW_HIDE);
		m_prCardDlg.ShowWindow(SW_HIDE);
		m_settingDlg.ShowWindow(SW_SHOW);
		break;
	}
}
