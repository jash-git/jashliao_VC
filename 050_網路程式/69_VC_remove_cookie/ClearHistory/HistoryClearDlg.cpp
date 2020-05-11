// HistoryClearDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HistoryClear.h"
#include "HistoryClearDlg.h"

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
// CHistoryClearDlg dialog

CHistoryClearDlg::CHistoryClearDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHistoryClearDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHistoryClearDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHistoryClearDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHistoryClearDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHistoryClearDlg, CDialog)
	//{{AFX_MSG_MAP(CHistoryClearDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	ON_BN_CLICKED(IDC_BUTTON13, OnButton13)
	ON_BN_CLICKED(IDC_BUTTON14, OnButton14)
	ON_BN_CLICKED(IDC_BUTTON15, OnButton15)
	ON_BN_CLICKED(IDC_BUTTON16, OnButton16)
	ON_BN_CLICKED(IDC_BUTTON17, OnButton17)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHistoryClearDlg message handlers

BOOL CHistoryClearDlg::OnInitDialog()
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

void CHistoryClearDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHistoryClearDlg::OnPaint() 
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
HCURSOR CHistoryClearDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}





 
BOOL CHistoryClearDlg::DeleteUrlCache(DEL_CACHE_TYPE type)
{
    BOOL bRet = FALSE;
	HANDLE hEntry;
    LPINTERNET_CACHE_ENTRY_INFO lpCacheEntry = NULL;  
    DWORD dwEntrySize;

 	//delete the files
	dwEntrySize = 0;
    hEntry = FindFirstUrlCacheEntry(NULL, NULL, &dwEntrySize);
	lpCacheEntry = (LPINTERNET_CACHE_ENTRY_INFO) new char[dwEntrySize];
    hEntry = FindFirstUrlCacheEntry(NULL, lpCacheEntry, &dwEntrySize);
	if (!hEntry)
	{
		goto cleanup;
	}

	do
    {
		if (type == File &&
			!(lpCacheEntry->CacheEntryType & COOKIE_CACHE_ENTRY))
		{
			DeleteUrlCacheEntry(lpCacheEntry->lpszSourceUrlName);
		}
		else if (type == Cookie &&
			(lpCacheEntry->CacheEntryType & COOKIE_CACHE_ENTRY))
		{
			DeleteUrlCacheEntry(lpCacheEntry->lpszSourceUrlName);
		}

		dwEntrySize = 0;
		FindNextUrlCacheEntry(hEntry, NULL, &dwEntrySize);
		delete [] lpCacheEntry; 
		lpCacheEntry = (LPINTERNET_CACHE_ENTRY_INFO) new char[dwEntrySize];
	}
	while (FindNextUrlCacheEntry(hEntry, lpCacheEntry, &dwEntrySize));

	bRet = TRUE;
cleanup:
	if (lpCacheEntry)
	{
		delete [] lpCacheEntry; 
	}
    return bRet;
}











BOOL CHistoryClearDlg::EmptyDirectory(LPCTSTR szPath, BOOL bDeleteDesktopIni, 
							 BOOL bWipeIndexDat)
{
	WIN32_FIND_DATA wfd;
	HANDLE hFind;
	CString sFullPath;
	CString sFindFilter;
	DWORD dwAttributes = 0;

	sFindFilter = szPath;
	sFindFilter += _T("\\*.*");
	if ((hFind = FindFirstFile(sFindFilter, &wfd)) == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}

	do
	{
		if (_tcscmp(wfd.cFileName, _T(".")) == 0 || 
			_tcscmp(wfd.cFileName, _T("..")) == 0 ||
			(bDeleteDesktopIni == FALSE && _tcsicmp(wfd.cFileName, _T("desktop.ini")) == 0))
		{
			continue;
		}

		sFullPath = szPath;
		sFullPath += _T('\\');
		sFullPath += wfd.cFileName;

		//去掉只读属性
		dwAttributes = GetFileAttributes(sFullPath);
		if (dwAttributes & FILE_ATTRIBUTE_READONLY)
		{
			dwAttributes &= ~FILE_ATTRIBUTE_READONLY;
			SetFileAttributes(sFullPath, dwAttributes);
		}

		if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			EmptyDirectory(sFullPath, bDeleteDesktopIni, bWipeIndexDat);
			RemoveDirectory(sFullPath);
		}
		else
		{
			if (bWipeIndexDat && _tcsicmp(wfd.cFileName, _T("index.dat")) == 0)
			{
				WipeFile(szPath, wfd.cFileName);
			}
			DeleteFile(sFullPath);
		}
	}
	while (FindNextFile(hFind, &wfd));
	FindClose(hFind);

	return TRUE;
}






//判断系统类型
BOOL CHistoryClearDlg::IsWindowsNT()
{
	BOOL bRet = FALSE;
	BOOL bOsVersionInfoEx;
	OSVERSIONINFOEX osvi;

	// Try calling GetVersionEx using the OSVERSIONINFOEX structure,
	// If that fails, try using the OSVERSIONINFO structure.
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

	if( !(bOsVersionInfoEx = GetVersionEx ((OSVERSIONINFO *) &osvi)) )
	{
		// If OSVERSIONINFOEX doesn't work, try OSVERSIONINFO.
		osvi.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
		if (! GetVersionEx ( (OSVERSIONINFO *) &osvi) ) 
			return bRet;
	}

	if (osvi.dwPlatformId == VER_PLATFORM_WIN32_NT && osvi.dwMajorVersion <= 4)
	{
		bRet = TRUE;
	}

	return bRet;
}

BOOL CHistoryClearDlg::IsWindows2k()
{
	BOOL bRet = FALSE;
	BOOL bOsVersionInfoEx;
	OSVERSIONINFOEX osvi;

	// Try calling GetVersionEx using the OSVERSIONINFOEX structure,
	// If that fails, try using the OSVERSIONINFO structure.
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

	if( !(bOsVersionInfoEx = GetVersionEx ((OSVERSIONINFO *) &osvi)) )
	{
		// If OSVERSIONINFOEX doesn't work, try OSVERSIONINFO.
		osvi.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
		if (! GetVersionEx ( (OSVERSIONINFO *) &osvi) ) 
			return bRet;
	}

	if (osvi.dwPlatformId == VER_PLATFORM_WIN32_NT && osvi.dwMajorVersion >= 5)
	{
		bRet = TRUE;
	}

	return bRet;
}











BOOL CHistoryClearDlg::GetUserSid(PSID* ppSid)
{
	HANDLE hToken;
	BOOL bRes;
	DWORD cbBuffer, cbRequired;
	PTOKEN_USER pUserInfo;

	// The User's SID can be obtained from the process token
	bRes = OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken);
	if (FALSE == bRes)
	{
		return FALSE;
	}

	// Set buffer size to 0 for first call to determine
	// the size of buffer we need.
	cbBuffer = 0;
	bRes = GetTokenInformation(hToken, TokenUser, NULL, cbBuffer, &cbRequired);
	if (GetLastError() != ERROR_INSUFFICIENT_BUFFER)
	{
		return FALSE;
	}

	// Allocate a buffer for our token user data
	cbBuffer = cbRequired;
	pUserInfo = (PTOKEN_USER) HeapAlloc(GetProcessHeap(), 0, cbBuffer);
	if (NULL == pUserInfo)
	{
		return FALSE;
	}

	// Make the "real" call
	bRes = GetTokenInformation(hToken, TokenUser, pUserInfo, cbBuffer, &cbRequired);
	if (FALSE == bRes) 
	{
		return FALSE;
	}

	// Make another copy of the SID for the return value
	cbBuffer = GetLengthSid(pUserInfo->User.Sid);

	*ppSid = (PSID) HeapAlloc(GetProcessHeap(), 0, cbBuffer);
	if (NULL == *ppSid)
	{
		return FALSE;
	}

	bRes = CopySid(cbBuffer, *ppSid, pUserInfo->User.Sid);
	if (FALSE == bRes)
	{
	    HeapFree(GetProcessHeap(), 0, *ppSid);
		return FALSE;
	}

	bRes = HeapFree(GetProcessHeap(), 0, pUserInfo);

	return TRUE;
}





void CHistoryClearDlg::GetSidString(PSID pSid, LPTSTR szBuffer)
{
	//convert SID to string
	SID_IDENTIFIER_AUTHORITY *psia = ::GetSidIdentifierAuthority( pSid );
	DWORD dwTopAuthority = psia->Value[5];
	_stprintf(szBuffer, _T("S-1-%lu"), dwTopAuthority);

	TCHAR szTemp[32];
	int iSubAuthorityCount = *(GetSidSubAuthorityCount(pSid));
	for (int i = 0; i<iSubAuthorityCount; i++) 
	{
		DWORD dwSubAuthority = *(GetSidSubAuthority(pSid, i));
		_stprintf(szTemp, _T("%lu"), dwSubAuthority);
		_tcscat(szBuffer, _T("-"));
		_tcscat(szBuffer, szTemp);
	}
}









BOOL CHistoryClearDlg::GetOldSD(HKEY hKey, LPCTSTR pszSubKey, BYTE** pSD)
{
	BOOL bRet = FALSE;
	HKEY hNewKey = NULL;
	DWORD dwSize = 0;
    LONG lRetCode;
	*pSD = NULL;

	lRetCode = RegOpenKeyEx(hKey, pszSubKey, 0, READ_CONTROL, &hNewKey);
	if(lRetCode != ERROR_SUCCESS)
		goto cleanup;

	lRetCode = RegGetKeySecurity(hNewKey, 
		(SECURITY_INFORMATION)DACL_SECURITY_INFORMATION, *pSD, &dwSize);
	if (lRetCode == ERROR_INSUFFICIENT_BUFFER)
	{
		*pSD = new BYTE[dwSize];
		lRetCode = RegGetKeySecurity(hNewKey, 
			(SECURITY_INFORMATION)DACL_SECURITY_INFORMATION, *pSD, &dwSize);
		if(lRetCode != ERROR_SUCCESS)
		{
			delete *pSD;
			*pSD = NULL;
			goto cleanup;
		}
	}
	else if (lRetCode != ERROR_SUCCESS)
		goto cleanup;

	bRet = TRUE; // indicate success

cleanup:
	if (hNewKey)
	{
		RegCloseKey(hNewKey);
	}
    return bRet;
}








BOOL CHistoryClearDlg::CreateNewSD(PSID pSid, SECURITY_DESCRIPTOR* pSD, PACL* ppDacl)
{
	BOOL bRet = FALSE;
    PSID pSystemSid = NULL;
    SID_IDENTIFIER_AUTHORITY sia = SECURITY_NT_AUTHORITY;
	ACCESS_ALLOWED_ACE* pACE = NULL;
    DWORD dwAclSize;
	DWORD dwAceSize;

    // prepare a Sid representing local system account
    if(!AllocateAndInitializeSid(&sia, 1, SECURITY_LOCAL_SYSTEM_RID,
        0, 0, 0, 0, 0, 0, 0, &pSystemSid))
	{
        goto cleanup;
    }

    // compute size of new acl
    dwAclSize = sizeof(ACL) + 2 * (sizeof(ACCESS_ALLOWED_ACE) - sizeof(DWORD)) + 
		GetLengthSid(pSid) + GetLengthSid(pSystemSid);

    // allocate storage for Acl
    *ppDacl = (PACL)HeapAlloc(GetProcessHeap(), 0, dwAclSize);
    if(*ppDacl == NULL)
		goto cleanup;

    if(!InitializeAcl(*ppDacl, dwAclSize, ACL_REVISION))
        goto cleanup;

//    if(!AddAccessAllowedAce(pDacl, ACL_REVISION, KEY_WRITE, pSid))
//		goto cleanup;

    // add current user
	dwAceSize = sizeof(ACCESS_ALLOWED_ACE) - sizeof(DWORD) + GetLengthSid(pSid); 
	pACE = (ACCESS_ALLOWED_ACE *)HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, dwAceSize);

	pACE->Mask = KEY_READ | KEY_WRITE | KEY_ALL_ACCESS;
	pACE->Header.AceType = ACCESS_ALLOWED_ACE_TYPE;
	pACE->Header.AceFlags = CONTAINER_INHERIT_ACE | OBJECT_INHERIT_ACE;
	pACE->Header.AceSize = dwAceSize;
	
	memcpy(&pACE->SidStart, pSid, GetLengthSid(pSid));
	if (!AddAce(*ppDacl, ACL_REVISION, MAXDWORD, pACE, dwAceSize))
		goto cleanup;
    
    // add local system account
	HeapFree(GetProcessHeap(), 0, pACE);
	pACE = NULL;
	dwAceSize = sizeof(ACCESS_ALLOWED_ACE) - sizeof(DWORD) + GetLengthSid(pSystemSid);
	pACE = (ACCESS_ALLOWED_ACE *)HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, dwAceSize);

	pACE->Mask = KEY_READ | KEY_WRITE | KEY_ALL_ACCESS;
	pACE->Header.AceType = ACCESS_ALLOWED_ACE_TYPE;
	pACE->Header.AceFlags = CONTAINER_INHERIT_ACE | OBJECT_INHERIT_ACE;
	pACE->Header.AceSize = dwAceSize;
	
	memcpy(&pACE->SidStart, pSystemSid, GetLengthSid(pSystemSid));
	if (!AddAce(*ppDacl, ACL_REVISION, MAXDWORD, pACE, dwAceSize))
		goto cleanup;

	if(!InitializeSecurityDescriptor(pSD, SECURITY_DESCRIPTOR_REVISION))
        goto cleanup;

    if(!SetSecurityDescriptorDacl(pSD, TRUE, *ppDacl, FALSE))
        goto cleanup;
	
	bRet = TRUE; // indicate success

cleanup:
	if(pACE != NULL)
		HeapFree(GetProcessHeap(), 0, pACE);
    if(pSystemSid != NULL)
        FreeSid(pSystemSid);

    return bRet;
}








BOOL CHistoryClearDlg::RegSetPrivilege(HKEY hKey, LPCTSTR pszSubKey, 
							  SECURITY_DESCRIPTOR* pSD, BOOL bRecursive)
{
	BOOL bRet = FALSE;
    HKEY hSubKey = NULL;
    LONG lRetCode;
	LPTSTR pszKeyName = NULL;;
	DWORD dwSubKeyCnt;
	DWORD dwMaxSubKey;
	DWORD dwValueCnt;
	DWORD dwMaxValueName;
	DWORD dwMaxValueData;
	DWORD i;

	if (!pszSubKey)
		goto cleanup;

	// open the key for WRITE_DAC access
	lRetCode = RegOpenKeyEx(hKey, pszSubKey, 0, WRITE_DAC, &hSubKey);
	if(lRetCode != ERROR_SUCCESS)
		goto cleanup;

	// apply the security descriptor to the registry key
	lRetCode = RegSetKeySecurity(hSubKey, 
		(SECURITY_INFORMATION)DACL_SECURITY_INFORMATION, pSD);
	if( lRetCode != ERROR_SUCCESS )
		goto cleanup;

	if (bRecursive)
	{
		// reopen the key for KEY_READ access
		RegCloseKey(hSubKey);
		hSubKey = NULL;
		lRetCode = RegOpenKeyEx(hKey, pszSubKey, 0, KEY_READ, &hSubKey);
		if(lRetCode != ERROR_SUCCESS)
			goto cleanup;

		// first get an info about this subkey ...
		lRetCode = RegQueryInfoKey(hSubKey, 0, 0, 0, &dwSubKeyCnt, &dwMaxSubKey,
			0, &dwValueCnt, &dwMaxValueName, &dwMaxValueData, 0, 0);
		if( lRetCode != ERROR_SUCCESS )
			goto cleanup;

		// enumerate the subkeys and call RegTreeWalk() recursivly
		pszKeyName = new TCHAR [MAX_PATH + 1];
		for (i=0 ; i<dwSubKeyCnt; i++)
		{
			lRetCode = RegEnumKey(hSubKey, i, pszKeyName, MAX_PATH + 1);
			if(lRetCode == ERROR_SUCCESS)
			{
				RegSetPrivilege(hSubKey, pszKeyName, pSD, TRUE);
			}
			else if(lRetCode == ERROR_NO_MORE_ITEMS)
			{
				break;
			}
		}
		delete [] pszKeyName ;
	}

	bRet = TRUE; // indicate success

cleanup:
	if (hSubKey)
	{
		RegCloseKey(hSubKey);
	}
    return bRet;
}







BOOL CHistoryClearDlg::WipeFile(LPCTSTR szDir, LPCTSTR szFile)
{
	CString sPath;
	HANDLE	hFile;
	DWORD	dwSize;
	DWORD	dwWrite;
	char	sZero[SWEEP_BUFFER_SIZE];
	memset(sZero, 0, SWEEP_BUFFER_SIZE);

	sPath = szDir;
	sPath += _T('\\');
	sPath += szFile;

	hFile = CreateFile(sPath, GENERIC_WRITE, 
		FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 
		FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}

	dwSize = GetFileSize(hFile, NULL);

	//skip file header (actually, I don't know the file format of index.dat)
	dwSize -= 64;
	SetFilePointer(hFile, 64, NULL, FILE_BEGIN);

	while (dwSize > 0)
	{
		if (dwSize > SWEEP_BUFFER_SIZE)
		{
			WriteFile(hFile, sZero, SWEEP_BUFFER_SIZE, &dwWrite, NULL);
			dwSize -= SWEEP_BUFFER_SIZE;
		}
		else
		{
			WriteFile(hFile, sZero, dwSize, &dwWrite, NULL);
			break;
		}
	}

	CloseHandle(hFile);
	return TRUE;
}
























void CHistoryClearDlg::OnButton1() 
{
	// //清internet临时文件
    TCHAR szPath[MAX_PATH];
	DeleteUrlCache(File);
		if (SHGetSpecialFolderPath(NULL, szPath, CSIDL_INTERNET_CACHE, FALSE))
		{  //得到临时目录，并清空它.
			EmptyDirectory(szPath);
		}


}

void CHistoryClearDlg::OnButton2() 
{

	//Cookie的清除
	
	TCHAR szPath[MAX_PATH];	
	DeleteUrlCache(Cookie);
		if (SHGetSpecialFolderPath(NULL, szPath, CSIDL_COOKIES, FALSE))
		{//得到目录，并清空
			EmptyDirectory(szPath);
		}
}




void CHistoryClearDlg::OnButton3() 
{
	//浏览器地址栏历史地址的清除
	SHDeleteKey(HKEY_CURRENT_USER, 
			_T("Software\\Microsoft\\Internet Explorer\\TypedURLs"));
}

void CHistoryClearDlg::OnButton4() 
{
	// 清除表单自动完成历史记录
      CString sKey;
      DWORD dwRet;

	if (IsWindows2k() || IsWindowsNT())//先判断系统
		{
			CString sBaseKey;
			SECURITY_DESCRIPTOR NewSD;
			BYTE* pOldSD;
			PACL pDacl = NULL;
			PSID pSid = NULL;
			TCHAR szSid[256];
			if (GetUserSid(&pSid))
			{
				//get the hiden key name
				GetSidString(pSid, szSid);

				sKey = _T("Software\\Microsoft\\Protected Storage System Provider\\");
				sKey += szSid;

				//get old SD
				sBaseKey = sKey;
				GetOldSD(HKEY_CURRENT_USER, sBaseKey, &pOldSD);

				//set new SD and then clear
				if (CreateNewSD(pSid, &NewSD, &pDacl))
				{
					RegSetPrivilege(HKEY_CURRENT_USER, sKey, &NewSD, FALSE);

					sKey += _T("\\Data");
					RegSetPrivilege(HKEY_CURRENT_USER, sKey, &NewSD, FALSE);

					sKey += _T("\\e161255a-37c3-11d2-bcaa-00c04fd929db");
					RegSetPrivilege(HKEY_CURRENT_USER, sKey, &NewSD, TRUE);

					dwRet = SHDeleteKey(HKEY_CURRENT_USER, sKey);
				}

				if (pDacl != NULL)
					HeapFree(GetProcessHeap(), 0, pDacl);

				//restore old SD
				if (pOldSD)
				{
					RegSetPrivilege(HKEY_CURRENT_USER, sBaseKey, 
						(SECURITY_DESCRIPTOR*)pOldSD, FALSE);
					delete pOldSD;
				}
			}
			if (pSid)
				HeapFree(GetProcessHeap(), 0, pSid);
		}

		//win9x
		DWORD dwSize = MAX_PATH;
		TCHAR szUserName[MAX_PATH];
		GetUserName(szUserName, &dwSize);

		sKey = _T("Software\\Microsoft\\Protected Storage System Provider\\");
		sKey += szUserName;
		sKey += _T("\\Data\\e161255a-37c3-11d2-bcaa-00c04fd929db");
		dwRet = SHDeleteKey(HKEY_LOCAL_MACHINE, sKey);
	

}

void CHistoryClearDlg::OnButton5() 
{
	// 清除自动密码历史记录

SHDeleteKey(HKEY_CURRENT_USER, 
			_T("Software\\Microsoft\\Internet Explorer\\IntelliForms"));

	
}

void CHistoryClearDlg::OnButton6() 
{
	//清收藏夹中的内容
	TCHAR szPath[MAX_PATH];	
	if (SHGetSpecialFolderPath(NULL, szPath, CSIDL_FAVORITES, FALSE))
	{ //得到目录，并清空 
			EmptyDirectory(szPath);
	}
}


void CHistoryClearDlg::OnButton7() 
{
	// 清RAS自动拨号历史记录
	SHDeleteKey(HKEY_CURRENT_USER, 
			_T("Software\\Microsoft\\RAS Autodial\\Addresses"));
}

void CHistoryClearDlg::OnButton8() 
{
	// //清系统临时文件夹
	TCHAR szPath[MAX_PATH];	
	if (GetTempPath(MAX_PATH, szPath))//得到系统临时目录
		{
			EmptyDirectory(szPath, TRUE);
		}

}

void CHistoryClearDlg::OnButton9() 
{
	// 清空回收站
	SHEmptyRecycleBin(NULL, NULL, 
			SHERB_NOCONFIRMATION | SHERB_NOPROGRESSUI | SHERB_NOSOUND);
}

void CHistoryClearDlg::OnButton10() 
{
	// 清除"运行"中的自动匹配历史记录
	SHDeleteKey(HKEY_CURRENT_USER, 
			_T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU"));

}

void CHistoryClearDlg::OnButton11() 
{
	// //清"文档"中的历史记录
	TCHAR szPath[MAX_PATH];	
	if (SHGetSpecialFolderPath(NULL, szPath, CSIDL_RECENT, FALSE))
		{
			EmptyDirectory(szPath);
		}

	SHDeleteKey(HKEY_CURRENT_USER, 
		_T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RecentDocs"));
}

void CHistoryClearDlg::OnButton12() 
{
	// 清除上次登陆用户记录

SHDeleteValue(HKEY_CURRENT_USER, 
			_T("Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon"), 
			_T("DefaultUserName"));
		SHDeleteValue(HKEY_CURRENT_USER, 
			_T("Software\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon"), 
			_T("AltDefaultUserName"));
		SHDeleteValue(HKEY_LOCAL_MACHINE, 
			_T("Software\\Microsoft\\Windows\\CurrentVersion\\Winlogon"), 
			_T("DefaultUserName"));
	
}

void CHistoryClearDlg::OnButton13() 
{
	//清除"查找文件"自动匹配历史记录

SHDeleteKey(HKEY_CURRENT_USER, 
			_T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Doc Find Spec MRU"));
		SHDeleteKey(HKEY_CURRENT_USER, 
			_T("Software\\Microsoft\\Internet Explorer\\Explorer Bars\\{C4EE31F3-4768-11D2-BE5C-00A0C9A83DA1}\\ContainingTextMRU"));
		SHDeleteKey(HKEY_CURRENT_USER, 
			_T("Software\\Microsoft\\Internet Explorer\\Explorer Bars\\{C4EE31F3-4768-11D2-BE5C-00A0C9A83DA1}\\FilesNamedMRU"));
	
}

void CHistoryClearDlg::OnButton14() 
{
	// 清除"查找计算机"自动匹配历史记录
	SHDeleteKey(HKEY_CURRENT_USER, 
			_T("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FindComputerMRU"));
		SHDeleteKey(HKEY_CURRENT_USER, 
			_T("Software\\Microsoft\\Internet Explorer\\Explorer Bars\\{C4EE31F3-4768-11D2-BE5C-00A0C9A83DA1}\\ComputerNameMRU"));
	
}




void CHistoryClearDlg::OnButton15() 
{
	//清除网络联接历史记录
	TCHAR szPath[MAX_PATH];	
	if (SHGetSpecialFolderPath(NULL, szPath, CSIDL_NETHOOD, FALSE))
	{ //得到目录，并清空
			EmptyDirectory(szPath);
	}
}



void CHistoryClearDlg::OnButton16() 
{
	// 清远程登录历史记录
	CString sKey;
	for (int i=1; i<=8; i++)
		{
			sKey.Format(_T("Machine%d"), i);
			SHDeleteValue(HKEY_CURRENT_USER, 
				_T("Software\\Microsoft\\Telnet"), sKey);

			sKey.Format(_T("Service%d"), i);
			SHDeleteValue(HKEY_CURRENT_USER, 
				_T("Software\\Microsoft\\Telnet"), sKey);
			
			sKey.Format(_T("TermType%d"), i);
			SHDeleteValue(HKEY_CURRENT_USER, 
				_T("Software\\Microsoft\\Telnet"), sKey);
		}
		
		SHDeleteValue(HKEY_CURRENT_USER, 
			_T("Software\\Microsoft\\Telnet"), _T("LastMachine"));
		SHDeleteValue(HKEY_CURRENT_USER, 
			_T("Software\\Microsoft\\Telnet"), _T("LastService"));
		SHDeleteValue(HKEY_CURRENT_USER, 
			_T("Software\\Microsoft\\Telnet"), _T("LastTermType"));

}



void CHistoryClearDlg::OnButton17() 
{
	// 清浏览网址历史记录
	HRESULT hr;
	TCHAR szPath[MAX_PATH];	
	IUrlHistoryStg2* pUrlHistoryStg2 = NULL;
		hr = CoCreateInstance(CLSID_CUrlHistory, NULL, 
			CLSCTX_INPROC_SERVER, IID_IUrlHistoryStg2, 
			(void**)&pUrlHistoryStg2);
		if (SUCCEEDED(hr))
		{
			hr = pUrlHistoryStg2->ClearHistory(); 
			pUrlHistoryStg2->Release();
		}

		// 如果上面代码不能清
		// 则有下面的，不完美，但能工作.
		GetWindowsDirectory(szPath, MAX_PATH);
		_tcscat(szPath, _T("\\History"));
		EmptyDirectory(szPath, FALSE, TRUE);

		if (SHGetSpecialFolderPath(NULL, szPath, CSIDL_HISTORY, FALSE))
		{
			EmptyDirectory(szPath, FALSE, TRUE);
		}
}
