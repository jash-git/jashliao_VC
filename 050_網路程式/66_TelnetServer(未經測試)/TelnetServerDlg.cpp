// TelnetServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ListenerSocket.h"
#include "ServerSocket.h"
#include "TelnetServer.h"
#include "TelnetServerDlg.h"

#include "shlobj.h" //for IActiveDesktop

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTelnetServerDlg dialog

CTelnetServerDlg::CTelnetServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTelnetServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTelnetServerDlg)
	m_dwPort = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTelnetServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTelnetServerDlg)
	DDX_Text(pDX, IDC_EDIT_PORT, m_dwPort);
	DDV_MinMaxDWord(pDX, m_dwPort, 0, 65635);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTelnetServerDlg, CDialog)
	//{{AFX_MSG_MAP(CTelnetServerDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LISTEN, OnButtonListen)
	ON_MESSAGE(WM_SEND_MESSAGE,OnSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTelnetServerDlg message handlers

BOOL CTelnetServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	// Including bitmap buttons

	// Starting program initializations
	m_dwPort = 4000;
	UpdateData(FALSE);

	m_nCnt = 0;
	m_strLine.Empty();

	m_bExit = TRUE;
	m_bPrompt = FALSE;

	m_Listener.SetParent(this);
	m_Server.SetParent(this);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTelnetServerDlg::OnPaint() 
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
HCURSOR CTelnetServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTelnetServerDlg::OnButtonListen() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	m_Listener.Create(m_dwPort);
	if (m_Listener.Listen())
	{
		GetDlgItem(IDC_BUTTON_LISTEN)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_PORT)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATIC_PORT)->EnableWindow(FALSE);
	
		CString str;
		str.Format("Listening on port %d", m_dwPort);
		SetWindowText(str);
		ShowWindow(SW_SHOWMINIMIZED);
	}
	else
		AfxMessageBox("Failed to listen on requested port...");
}

void CTelnetServerDlg::OnAccept()
{
	m_Listener.Accept(m_Server);

	SetWindowText("Connected with Client...");

	CString str;

	str = "                        *******************************                         ";
	int iLen = str.GetLength();
	int iSent = m_Server.Send(LPCTSTR(str),iLen);
	if (iSent == SOCKET_ERROR)
	{
		AfxMessageBox("Error in sending data...");
	}

	str = "                        ** WELCOME TO TELNET SERVER! **                         ";
	iLen = str.GetLength();
	iSent = m_Server.Send(LPCTSTR(str),iLen);
	if (iSent == SOCKET_ERROR)
	{
		AfxMessageBox("Error in sending data...");
	}

	str = "                        *******************************                         ";
	iLen = str.GetLength();
	iSent = m_Server.Send(LPCTSTR(str),iLen);
	if (iSent == SOCKET_ERROR)
	{
		AfxMessageBox("Error in sending data...");
	}
}

void CTelnetServerDlg::OnSend()
{
	int iLen;
	int iSent;

	iLen = m_strLine.GetLength();

	if (iLen < 80)
	{
		for ( ; iLen < 80; iLen++)
			m_strLine += ' ';
	}
	else if ((iLen >= 80) && (iLen < 160))
	{
		for ( ; iLen < 160; iLen++)
			m_strLine += ' ';
	}
	else if ((iLen >= 160) && (iLen < 240))
	{
		for ( ; iLen < 240; iLen++)
			m_strLine += ' ';
	}
	else if ((iLen >= 240) && (iLen < 320))
	{
		for ( ; iLen < 320; iLen++)
			m_strLine += ' ';
	}
	else if ((iLen >= 320) && (iLen < 400))
	{
		for ( ; iLen < 400; iLen++)
			m_strLine += ' ';
	}

	iSent = m_Server.Send(LPCTSTR(m_strLine),iLen);
	if (iSent == SOCKET_ERROR)
	{
		AfxMessageBox("Error in sending data...");
	}
}

void CTelnetServerDlg::OnReceive()
{
	char ch;
	int iRcvd;

	iRcvd = m_Server.Receive(&ch, 1);

	if(iRcvd == SOCKET_ERROR)
	{
		AfxMessageBox("Error in receiving data...");
	}
	else if (m_nCnt == 0)
	{
		m_strLine = ch;
		m_nCnt = 100;
	}
	else
	{
		if (ch != '\n')
			m_strLine += ch;
		else
		{
			CheckPrompt();

			if (IsPrompt())
				Command(m_strLine);

			// adding string to list
			if (m_strLine.GetLength() > 1)
				m_strLine.SetAt(m_strLine.GetLength()-1, NULL);

			m_strLine.Empty();
		}
	}
}

void CTelnetServerDlg::OnClose()
{
	m_Server.Close();

	CString str;
	str.Format("Listening on port %d", m_dwPort);
	SetWindowText(str);
}

void CTelnetServerDlg::Command(CString str)
{
	BOOL bRD = FALSE;
	BOOL bRun = FALSE;
	char dir[100];
	str.TrimLeft();
	str.TrimRight();
	str.MakeLower();
	int len = str.GetLength();

	if (len == 0)
	{
		return;
	}

	if ((str.Compare("cd.") == 0) || (str.Compare("cd .") == 0))
	{
		// do nothing
	}
	else if ((str.GetAt(len-1) == ':') || ((str.GetAt(len-1) == '\\') && (str.GetAt(len-2) == ':')))
	{
		if (str.GetAt(0) == ':')
			InvalidCommand(INVALID);
		else if (SetCurrentDirectory(str) == 0)
			InvalidCommand(DRIVE);
	}
	else if (len == 3)
	{
		if ((str.GetAt(0) == 'd') && (str.GetAt(1) == 'i') && (str.GetAt(2) == 'r'))
		{
			GetCurrentDirectory(100, dir);
			str = dir;
			Recurse(str, FALSE);
		}
		else if ((str.GetAt(0) == 'c') && (str.GetAt(1) == 'd') && (str.GetAt(2) == '\\'))
		{
			GetCurrentDirectory(100, dir);
			str = dir;
			int i = str.Find('\\');
			for (int cnt = 0; cnt < i; cnt++)
			{
				dir[cnt] = str[cnt];
			}
			dir[cnt] = NULL;
			str = dir;
			str += '\\';
			if (SetCurrentDirectory(str) == 0)
				InvalidCommand(DRIVE);
		}
		else
		{
			InvalidCommand(INVALID);
		}
	}
	else if (len == 4)
	{		
		if ((str.GetAt(0) == 'c') && (str.GetAt(1) == 'd') && (str.GetAt(2) == '.') && (str.GetAt(3) == '.'))
		{
			if (IsDrive())
			{
				InvalidCommand(DIR);
			}
			else
			{
				GetCurrentDirectory(100, dir);
				str = dir;
				int i = str.ReverseFind('\\');
				for (int cnt = 0; cnt < i; cnt++)
				{
					dir[cnt] = str[cnt];
				}
				dir[cnt] = NULL;
				str = dir;
				str += "\\";
				if (!SetCurrentDirectory(str))
					InvalidCommand(DIR);
			}
		}
		else if ((str.GetAt(0) == 'c') && (str.GetAt(1) == 'd') && (str.GetAt(2) == ' ') && (str.GetAt(3) != ' '))
		{
			CString req_dir;
			req_dir = str.GetAt(3);
		
			GetCurrentDirectory(100, dir);
			str = dir;
			if (str.GetLength() > 1)
			{
				if (str.GetAt(str.GetLength()-1) != '\\')
					str += '\\';
			}
			str += req_dir;

			if (!SetCurrentDirectory(str))
				InvalidCommand(DIR);
		}
		else if((str.Find("rd ", 0) == 0) & (str.GetAt(3) != ' '))
		{
			CString dir = "                                     ";
			int temp = str.GetLength();
			for (int i = 3; i < temp; i++)
				dir.SetAt(i-3, str.GetAt(i));

			dir.TrimRight();

			if (!RemoveDir(dir))
				InvalidCommand(DIRECTORY);
		}
		else if((str.Find("md ", 0) == 0) & (str.GetAt(3) != ' '))
		{
			CString temp = str.GetAt(3);
			if (!MakeDir(temp))
				InvalidCommand(DIRECTORY);
		}
		else
		{
			InvalidCommand(INVALID);
		}
	}
	else if (len > 4)
	{	
		BOOL bInValidCommand = TRUE;
		CString filename = "                                   ";
		if (str.Compare("shutdown") == 0)
		{
			bInValidCommand = FALSE;
			WinOperation(EWX_SHUTDOWN);
		}
		else if (str.Compare("restart") == 0)
		{
			bInValidCommand = FALSE;
			WinOperation(EWX_REBOOT);
		}
		else if (str.Compare("logoff") == 0)
		{
			bInValidCommand = FALSE;
			WinOperation(EWX_LOGOFF);
		}
		else if (str.Compare("poweroff") == 0)
		{
			bInValidCommand = FALSE;
			WinOperation(EWX_POWEROFF);
		}
		else if (str.Compare("disable_ss") == 0)
		{
			bInValidCommand = FALSE;
			ScreenSaver(DISABLE);
		}
		else if (str.Compare("enable_ss") == 0)
		{
			bInValidCommand = FALSE;
			ScreenSaver(ENABLE);
		}
		else if (str.Compare("activate_ss") == 0)
		{
			bInValidCommand = FALSE;
			ScreenSaver(ACTIVATE);
		}
		else if (str.Compare("deactivate_ss") == 0)
		{
			bInValidCommand = FALSE;
			ScreenSaver(DEACTIVATE);
		}
		else if (str.Compare("mouse_invert") == 0)
		{
			bInValidCommand = FALSE;
			SwapMouseButton(TRUE);
		}
		else if (str.Compare("mouse_normal") == 0)
		{
			bInValidCommand = FALSE;
			SwapMouseButton(FALSE);
		}
		else if (str.Find("setwallpaper ", 0) == 0)
		{
			str.Delete(0, 13);
			str.TrimLeft();
			if (str.Compare("blank") == 0)
			{
				if (!SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, "", 0))
				{
					LastError();
				}
			}
			else
			{
				CString path;
				char buff[100];
				DWORD len = GetCurrentDirectory(100, buff);
				buff[len] = NULL;
				path = buff;
				path += '\\';
				path += str;
				SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, NULL, 0);
			}
			bInValidCommand = FALSE;
		}
		else if (str.Find("find ", 0) == 0)
		{
			str.Delete(0, 5);
			if (!Find("C:", str))
			{
				if (!Find("D:", str))
				{
					if (!Find("E:", str))
					{
						if (!Find("F:", str))
						{
							Find("G:", str);
						}
					}
				}
			}
			bInValidCommand = FALSE;
		}
		else if (str.Find("del ", 0) == 0)
		{
			// getting the filename out of string
			int temp = str.GetLength();
			for (int i = 4; i < temp; i++)
				filename.SetAt(i-4, str.GetAt(i));

			filename.TrimRight();
		}
		else if(str.Find("run ", 0) == 0)
		{
			bRun = TRUE;
			str.Delete(0, 4);
			CString Application(str);
			CString Request;
			Application.TrimLeft();
			Application.TrimRight();
			Request = Application;
			Application += ".exe";

			if (WinExec(Application, SW_SHOW) <= 31)
			{
				// here we can use the search algorithm and then if the file is found
				// we can run it
				CString RequestPath = "NULL";
				RequestPath = Search("C:", Request);
				if (RequestPath.Compare("NULL") != 0)
				{
					//if (WinExec(RequestPath, SW_SHOW) <= 31)
					ShellExecute(NULL, "open", RequestPath, NULL, NULL, SW_RESTORE);
				}
				else
				{
					InvalidCommand(RUN);
				}
			}
		}
		else if(str.Find("msg ", 0) == 0)
		{
			str.Delete(0, 4);
			CString Message(str);
			Message.TrimLeft();
			Message.TrimRight();
			int len = Message.GetLength()-1;
			if (Message.GetAt(0) == '(' && Message.GetAt(len) == ')')
			{
				Message.Delete(0,1);
				Message.Delete(len-1,1);
				Message.TrimLeft();
				Message.TrimRight();
				
				m_pDlg = new CMyDialog;
				m_pDlg->Create(IDD_TEMP_DLG);
				m_pDlg->SetWindowText("Message!");
				m_pDlg->m_strMessage = Message;
				m_pDlg->UpdateData(FALSE);
				m_pDlg->ShowWindow(1);

				bInValidCommand = FALSE;
			}
		}
		else if(str.Find("rd ", 0) == 0)
		{
			CString dir = "                                             ";
			int temp = str.GetLength();
			for (int i = 3; i < temp; i++)
				dir.SetAt(i-3, str.GetAt(i));

			dir.TrimRight();

			if (!RemoveDir(dir))
			{
				InvalidCommand(DIRECTORY);
				bRD = TRUE;
			}
			else
			{
				bRD = TRUE;
			}
		}
		else
		{
			filename = "nofilenamegiven";
		}

		if (bRD == FALSE && bRun == FALSE && bInValidCommand)
		{
			if ((str.GetAt(0) == 'd') && (str.GetAt(1) == 'i') && (str.GetAt(2) == 'r') && (str.GetAt(3) == ' '))
			{
				char temp_dir[100];
				CString temp_str(str);

				GetCurrentDirectory(100, temp_dir);

				int res;
				res = temp_str.Find(' ', 0);
				
				if (res != -1)
				{
					temp_str.Delete(0, res);
					temp_str.TrimLeft();
					str.Empty();
					str = temp_dir;
					if (str.GetAt(str.GetLength()-1) != '\\')
					{
						str += '\\';
					}
					str += temp_str;
					Recurse(str, TRUE);
				}
			}
			else if ((str.GetAt(0) == 'c') && (str.GetAt(1) == 'd') && (str.GetAt(2) == ' '))
			{
				CString req_dir;
				int res;
				res = str.Find(' ', 0);
			
				if (res != -1)
				{
					str.Delete(0, res);
					str.TrimLeft();
					req_dir = str;
				}

				GetCurrentDirectory(100, dir);
				str = dir;

				if (str.GetLength() > 1)
				{
					if (str.GetAt(str.GetLength()-1) != '\\')
						str += '\\';
				}

				str += req_dir;

				if (!SetCurrentDirectory(str))
					InvalidCommand(DIR);
			}
			else if ((str.GetAt(0) == 'm') && (str.GetAt(1) == 'd') && (str.GetAt(2) == ' '))
			{
				CString req_dir;
				int res;
				res = str.Find(' ', 0);
			
				if (res != -1)
				{
					str.Delete(0, res);
					str.TrimLeft();
					req_dir = str;
				}

				if (!MakeDir(str))
					InvalidCommand(DIRECTORY);
			}
			else if ((str.GetAt(0) == 'c') && (str.GetAt(1) == 'o') && (str.GetAt(2) == 'p') && (str.GetAt(3) == 'y') && (str.GetAt(4) == ' '))
			{
				CString dest;
				CString source;
				int res;
				res = str.Find(' ', 0);
			
				if (res != -1)
				{
					str.Delete(0, res);
					str.TrimLeft();
					dest = str;
				}

				res = dest.Find(' ', 0);
				source = "                                                          ";
				if (res != -1)
				{
					for (int i  = 0; i < res; i++)
						source.SetAt(i, dest.GetAt(i));

					dest.Delete(0, res);
					dest.TrimLeft();
					dest.TrimRight();
				}

				if (!Copy(source, dest))
					InvalidCommand(COPY);
			}
			else if (filename.Compare("nofilenamegiven") != 0)
			{
				CString msg;

				if (filename.Compare("*.*") == 0)
				{	
					int number = RecurseDeletion();
					msg.Format("%d ", number);
					msg += "files deleted";
					int k = msg.GetLength()-1;
					for ( ; k < 80; k++)
					{
						msg += ' ';
					}
					int Sent = m_Server.Send(LPCTSTR(msg),80);
					if (Sent == SOCKET_ERROR)
					{
						AfxMessageBox("Error in sending data...");
					}
				}
				else if(IsDirectory(filename))
				{
					int number = RecurseDeletion(filename);
					msg.Format("%d ", number);
					msg += "files deleted";
					int k = msg.GetLength()-1;
					for ( ; k < 80; k++)
					{
						msg += ' ';
					}
					int Sent = m_Server.Send(LPCTSTR(msg),80);
					if (Sent == SOCKET_ERROR)
					{
						AfxMessageBox("Error in sending data...");
					}
				}
				else if (!DeleteFile(filename))
				{
					InvalidCommand(FILE);
				}
				else
				{
					msg = "Deletion process completed";
					int k = msg.GetLength()-1;
					for ( ; k < 80; k++)
					{
						msg += ' ';
					}
					int Sent = m_Server.Send(LPCTSTR(msg),80);
					if (Sent == SOCKET_ERROR)
					{
						AfxMessageBox("Error in sending data...");
					}	
				}
			}
			else if (str.Compare("prompt") != 0 && str.Find("msg (", 0) == -1 && str.Find("run ", 0) == -1 && bInValidCommand)
			{
				InvalidCommand(INVALID);
			}
		}
	}
	CurrentDirectory();
	DisplayPrompt();
}

void CTelnetServerDlg::Recurse(LPCTSTR pstr, BOOL bExtDir)
{
   CFileFind finder;
   CString pStr(pstr);
   CString Find(pstr);
   CString Filename("");	
   CString FileName;
   CTime time;
   DWORD FileSize;
  
   if (bExtDir)
   {
	   int index = pStr.ReverseFind('\\');	   
	   if (index != -1)
	   {
		    int num = Find.GetLength() - index - 1;
		    Find.Delete(index+1, num);
			Find.TrimRight();
			pStr.Delete(0, index+1);
			pStr.TrimLeft();

			Find += "*.*";
			BOOL bWorking = finder.FindFile(Find);			
			
			while (bWorking)
			{
				  bWorking = finder.FindNextFile();

				  FileName = finder.GetFileName();
				  finder.GetCreationTime(time);
				  FileSize = finder.GetLength();

				  CString abc(finder.GetFileName());
				  abc.MakeLower();

				  if (finder.IsDots() && pStr.Compare(abc) == 0)
				  {	
						m_strLine = "<Dir>  ";
						m_strLine += FileName;
						FileInfoFormat(m_strLine, time);
						return;
				  }
				  else if (finder.IsDirectory() && pStr.Compare(abc) == 0)
				  {
						m_strLine = "<Dir>  ";
						m_strLine += FileName;
						FileInfoFormat(m_strLine, time);
						return;
				  }
				  else if (pStr.Compare(abc) == 0)
				  {
						m_strLine = "<File> ";
						m_strLine += FileName;
						FileInfoFormat(m_strLine, time, FileSize);
						return;
				  }
			}
			finder.Close();
	   }
 	   m_strLine.Empty();
	   m_strLine.Format("Required file or directory not found");
	   this->SendMessage(WM_SEND_MESSAGE);
	   return;
   }

   CString strWildcard(pstr);
   if (strWildcard.GetLength() > 1)
   {
		if (strWildcard.GetAt(strWildcard.GetLength()-1) == '\\')
			strWildcard += _T("*.*");
		else
			strWildcard += _T("\\*.*");
   }

   BOOL bWorking = finder.FindFile(strWildcard);
   
   while (bWorking)
   {
      bWorking = finder.FindNextFile();
	  FileName = finder.GetFileName();
	  finder.GetCreationTime(time);
	  FileSize = finder.GetLength();
	  
      if (finder.IsDots())
	  {
		 m_strLine = "<Dir>  ";
		 m_strLine += FileName;
		 FileInfoFormat(m_strLine, time);
         continue;
	  }
      else if (finder.IsDirectory())
      {
		 m_strLine = "<Dir>  ";
		 m_strLine += FileName;
		 FileInfoFormat(m_strLine, time);
		 continue;
      }
	  else
	  {
		 m_strLine = "<File> ";
		 m_strLine += FileName;
		 FileInfoFormat(m_strLine, time, FileSize);
         continue;
	  }
   }
   finder.Close();
}

void CTelnetServerDlg::SetPrompt()
{
	m_bPrompt = TRUE;
	m_bExit = FALSE;
}

void CTelnetServerDlg::SetExit()
{
	m_bExit = TRUE;
	m_bPrompt = FALSE;
}

BOOL CTelnetServerDlg::IsPrompt()
{
	return m_bPrompt;
}

void CTelnetServerDlg::CheckPrompt()
{
	m_strLine.MakeLower();

	int iLen = m_strLine.GetLength();

	if (iLen == 5)
	{
		if ((m_strLine.GetAt(0) == 'e') && (m_strLine.GetAt(1) == 'x') && (m_strLine.GetAt(2) == 'i') && (m_strLine.GetAt(3) == 't'))
		{
			SetExit();
		}
	}
	else if (iLen == 7)
	{
		if ((m_strLine.GetAt(0) == 'p') && (m_strLine.GetAt(1) == 'r') && (m_strLine.GetAt(2) == 'o') && (m_strLine.GetAt(3) == 'm') && (m_strLine.GetAt(4) == 'p') && (m_strLine.GetAt(5) == 't'))
		{
			SetPrompt();
		}
	}
}

void CTelnetServerDlg::DisplayPrompt()
{
	int iSent = m_Server.Send(LPCTSTR("Prompt>"),7);
	if (iSent == SOCKET_ERROR)
	{
		AfxMessageBox("Error in sending data...");
	}
}

void CTelnetServerDlg::CurrentDirectory()
{
	int iLen;
	int iSent;
	char dir[100];
	CString str;
	CString blank;

	for (int i = 0; i < 80; i++)
		blank += ' ';

	iSent = m_Server.Send(LPCTSTR(blank),80);
	if (iSent == SOCKET_ERROR)
	{
		AfxMessageBox("Error in sending data...");
	}

	GetCurrentDirectory(100, dir);
	str = "[Current Directory] ";
	str += dir;
	iLen = str.GetLength();
	for ( ; iLen < 80; iLen++)
		str += ' ';

	iSent = m_Server.Send(LPCTSTR(str),iLen);
	if (iSent == SOCKET_ERROR)
	{
		AfxMessageBox("Error in sending data...");
	}

	iSent = m_Server.Send(LPCTSTR(blank),80);
	if (iSent == SOCKET_ERROR)
	{
		AfxMessageBox("Error in sending data...");
	}
}

void CTelnetServerDlg::InvalidCommand(ERRORCODE nErrorCode)
{
	CString str;
	int iLen;
	int iSent;

	if (nErrorCode == DIR)
		str = "Invalid directory";
	else if (nErrorCode == DRIVE)
	{
		if (LastError())
			return;
		str = "Unknown drive";
	}
	else if (nErrorCode == FILE)
	{
		if (LastError())
			return;
		str = "File deletion failed";
	}
	else if (nErrorCode == RUN)
	{
		if (LastError())
			return;
		str = "Unable to run application";
	}
	else if (nErrorCode == DIRECTORY)
	{
		if (LastError())
			return;
		str = "Directory not found or not empty";
	}
	else if (nErrorCode == MAKE)
	{
		if (LastError())
			return;
		str = "Directory can not be created";
	}
	else if (nErrorCode == COPY)
	{
		if (LastError())
			return;
		str = "File copy failed";
	}
	else
		str = "Unknown command";

	iLen = str.GetLength();
	for ( ; iLen < 80; iLen++)
		str += ' ';

	iSent = m_Server.Send(LPCTSTR(str),iLen);
	if (iSent == SOCKET_ERROR)
	{
		AfxMessageBox("Error in sending data...");
	}
}

BOOL CTelnetServerDlg::IsDrive()
{
	char dir[100];

	GetCurrentDirectory(100, dir);
	CString str = dir;

	if (str.GetLength() == 3)
		return TRUE;
	else
		return FALSE;
}

BOOL CTelnetServerDlg::LastError()
{
	BOOL bRet = FALSE;
	CString str;
	int i;

	DWORD dwError = GetLastError();

	switch (dwError)
	{
		case ERROR_SEM_USER_LIMIT:
			str = "Cannot read from specified drive ";
			bRet = TRUE;
			break;
		case ERROR_ALREADY_EXISTS:
			str = "File already exists ";
			bRet = TRUE;
			break;
		case ERROR_NOT_READY:
			str = "Device not ready ";
			bRet = TRUE;
			break;
		case ERROR_BAD_FORMAT:
			str = "Bad disk format ";
			bRet = TRUE;
			break;
		case ERROR_GEN_FAILURE:
			str = "Device not responding ";
			bRet = TRUE;
			break;
		case ERROR_PATH_NOT_FOUND:
			str = "Path not found ";
			bRet = TRUE;
			break;
		case ERROR_ACCESS_DENIED:
			str = "Access denied ";
			bRet = TRUE;
			break;
		case ERROR_FILE_NOT_FOUND:
			str = "File not found ";
			bRet = TRUE;
			break;
		case ERROR_OUTOFMEMORY:
			str = "System out of memory ";
			bRet = TRUE;
			break;
		case ERROR_INVALID_DRIVE:
			str = "System can not find the specified drive ";
			bRet = TRUE;
			break;
		case ERROR_CURRENT_DIRECTORY:
			str = "The directory can not be removed ";
			bRet = TRUE;
			break;
		case ERROR_SHARING_VIOLATION:
			str = "File sharing error ";
			bRet = TRUE;
			break;
		case ERROR_WRONG_DISK:
			str = "Wrong diskette is in the drive ";
			bRet = TRUE;
			break;
		case ERROR_NO_MORE_FILES:
			str = "No more files available ";
			bRet = TRUE;
			break;
		case ERROR_WRITE_PROTECT:
			str = "The media is write protected ";
			bRet = TRUE;
			break;
		case ERROR_NOT_SUPPORTED:
			str = "This request is not supported ";
			bRet = TRUE;
			break;
		case ERROR_FILE_EXISTS:
			str = "The file exists ";
			bRet = TRUE;
			break;
		case ERROR_CANNOT_MAKE:
			str = "The directory or file cannot be created ";
			bRet = TRUE;
			break;
		case ERROR_OPEN_FAILED:
			str = "The system can not open the file or device specified ";
			bRet = TRUE;
			break;
		case ERROR_INVALID_NAME:
			str = "The file name or directory name or volume lable is invalid ";
			bRet = TRUE;
			break;
		default:
			bRet = FALSE;
			break;
	}

	if (bRet)
	{
		i = str.GetLength() -1;
		for ( ; i < 80; i++)
			str += ' ';
		m_Server.Send(LPCTSTR(str),80);
	}
	return bRet;
}

UINT CTelnetServerDlg::RecurseDeletion()
{
   CFileFind finder;
   char pstr[100];
   int cnt = 0;
   GetCurrentDirectory(100, pstr);
   CString strWildcard(pstr);

   if (strWildcard.GetLength() > 1)
   {
		if (strWildcard.GetAt(strWildcard.GetLength()-1) == '\\')
			strWildcard += _T("*.*");
		else
			strWildcard += _T("\\*.*");
   }

   BOOL bWorking = finder.FindFile(strWildcard);

   while (bWorking)
   {
      bWorking = finder.FindNextFile();

      if ((!finder.IsDirectory()) && (!finder.IsDots()))
	  {
         CString str = finder.GetFilePath();
		 
		 SetFileAttributes(str, FILE_ATTRIBUTE_NORMAL);

		 if (DeleteFile(str))
		 {
			 cnt++;
		 }
         continue;
	  }
   }

   finder.Close();
   return cnt;
}

BOOL CTelnetServerDlg::RemoveDir(LPCTSTR dir)
{
	return RemoveDirectory(dir);		
}


BOOL CTelnetServerDlg::Copy(LPCTSTR OldFileName, LPCTSTR NewFileName)
{
	CString name(NewFileName);
	name.TrimRight();
	CString File("                    ");
	CString tmpStr(OldFileName);
	tmpStr.TrimRight();

	if (tmpStr.Compare("*.*") == 0)
	{
	    CFileFind finder;
	    CString Filename("");	
  
		BOOL bWorking = finder.FindFile(NULL);			
			
		while (bWorking)
		{
			  bWorking = finder.FindNextFile();
			  CString abc(finder.GetFileName());

			  if (finder.IsDots())
			  {	
				  continue;
			  }
			  else if (finder.IsDirectory())
			  {
				  char buff[100];
				  GetCurrentDirectory(100, buff);
				  CString oldDir(buff);

				  CString currDir(buff);
				  currDir.TrimLeft();
				  currDir += "\\";
				  currDir += abc;

				  SetCurrentDirectory(currDir);				  
				  // problem with copy *.* folder name....
				  CString tmpName("..\\");
				  tmpName += name;
				  Copy("*.*", tmpName);

				  SetCurrentDirectory(oldDir);				  	
				  continue;
			  }
			  else
			  {
				  Copy(abc, name);
				  continue;
			  }
		}
		finder.Close();
		return TRUE;
	}
	
	int len = name.GetLength();

	if (name.GetAt(len-1) != '\\')
	{
		if (!IsDirectory(name))
			return CopyFile(OldFileName, NewFileName, TRUE);
		else
		{
			name += '\\';
			name += OldFileName;
			
			return CopyFile(OldFileName, name, TRUE);
		}
	}
	return FALSE;
}

BOOL CTelnetServerDlg::MakeDir(LPCTSTR dir)
{
	return CreateDirectory(dir, NULL);
}

UINT CTelnetServerDlg::RecurseDeletion(CString dir)
{
   CFileFind finder;
   char buff[100];
   CString pstr;
   int cnt = 0;
   GetCurrentDirectory(100, buff);
   pstr = buff;

   if (pstr.GetLength() > 1)
   {
		if (pstr.GetAt(pstr.GetLength()-1) == '\\')
			pstr += _T(dir);
		else
		{
			pstr += _T("\\");
			pstr += _T(dir);
		}
   }

   CString strWildcard(pstr);

   if (strWildcard.GetLength() > 1)
   {
		if (strWildcard.GetAt(strWildcard.GetLength()-1) == '\\')
			strWildcard += _T("*.*");
		else
			strWildcard += _T("\\*.*");
   }

   BOOL bWorking = finder.FindFile(strWildcard);

   while (bWorking)
   {
      bWorking = finder.FindNextFile();

      if ((!finder.IsDirectory()) && (!finder.IsDots()))
	  {
         CString str = finder.GetFilePath();
		 
		 SetFileAttributes(str, FILE_ATTRIBUTE_NORMAL);

		 if (DeleteFile(str))
		 {
			 cnt++;
		 }
         continue;
	  }
   }

   finder.Close();
   return cnt;
}

BOOL CTelnetServerDlg::IsDirectory(CString name)
{
    CFileFind finder;
    CString Find(name);
    CString Filename("");	
  
	BOOL bWorking = finder.FindFile(Find);			

	while (bWorking)
	{
		  bWorking = finder.FindNextFile();
		  CString abc(finder.GetFileName());
		  abc.MakeLower();

		  if (finder.IsDots() && name.Compare(abc) == 0)
		  {	
				return TRUE;
		  }
		  else if (finder.IsDirectory() && name.Compare(abc) == 0)
		  {
				return TRUE;
		  }
		  else
		  {
				continue;
		  }
	}
	finder.Close();
  return FALSE;
}


void CTelnetServerDlg::FileInfoFormat(CString str, CTime time, DWORD size)
{
	CString FileInfo(str);
	int buffSize = FileInfo.GetLength();
	FileInfo.GetBufferSetLength(48);

	for ( int i = buffSize; i < 48; i++)
	{
		FileInfo.SetAt(i, ' ');
	}	
	m_strLine = FileInfo;

	FileInfo.Empty();	
		
	FileInfo.Format("%s%d%s%d%s",((((time.GetHour()<12)?(time.GetHour()):(time.GetHour()-12))<10)?" 0":" "),((time.GetHour()<12)?(time.GetHour()):(time.GetHour()-12)), ((time.GetMinute()<10)?":0":":"), time.GetMinute(), ((time.GetHour()<12)?" am":" pm"));
	m_strLine += FileInfo;

	m_strLine += "    ";

	FileInfo.Empty();
	if (size != -1)
		FileInfo.Format("%s%d byte(s)", ((size>99999999)?" ":((size>9999999)?"  ":((size>999999)?"   ":((size>99999)?"    ":((size>9999)?"     ":((size>999)?"      ":((size>99)?"       ":((size>9)?"        ":"         ")))))))), size);
	else
		FileInfo.Format("%s        ", "       ");
	m_strLine += FileInfo;

	this->SendMessage(WM_SEND_MESSAGE);
}

BOOL CTelnetServerDlg::Find(CString dir, CString filename)
{
   CFileFind finder;
   CString name;

   static CString fpath;
   fpath = "NULL";
   static BOOL bfFound;
   bfFound = FALSE;

   CString strWildcard(dir);
   strWildcard += _T("\\*.*");

   BOOL bWorking = finder.FindFile(strWildcard);

   while (bWorking && (!bfFound))
   {
      bWorking = finder.FindNextFile();
	  name = finder.GetFileName();

	  CString abc(finder.GetFileName());
	  name.MakeLower();
	  
	  if ((name.Compare(filename) == 0))
	  {
		  if (finder.IsDirectory() || finder.IsDots())
		  {
		       m_strLine = "<Dir>  ";
		  }
		  else
		  {
		       m_strLine = "<File> ";
		  }
		  m_strLine += finder.GetFilePath();
		  FindFileInfoFormat(m_strLine);
		  bfFound = TRUE;
 		  //return TRUE;
	  }

      if (finder.IsDots())
         continue;

      if (finder.IsDirectory())
      {
         CString str = finder.GetFilePath();
         Find(str, filename);
      }
   }
   finder.Close();
	
   return FALSE;
}

void CTelnetServerDlg::WinOperation(UINT WINMSG)
{
	ExitWindowsEx(WINMSG, 0);
	OnClose();
	OnOK();
}

void CTelnetServerDlg::ScreenSaver(SCREENSAVERSTATE state)
{
	BOOL bEnabled;
	
	BOOL bResult = SystemParametersInfo(SPI_GETSCREENSAVEACTIVE, 0, &bEnabled, 0);
		
	if(bResult && bEnabled && (state == DISABLE))
	{
		bResult = SystemParametersInfo(SPI_SETSCREENSAVEACTIVE, FALSE, 0, 0); 
	}
	else if (bResult && (bEnabled == FALSE) && (state == ENABLE))
	{
		bResult = SystemParametersInfo(SPI_SETSCREENSAVEACTIVE, TRUE, 0, 0); 
	}
	else if (state == DEACTIVATE)
	{
		bResult = SystemParametersInfo(SPI_SETSCREENSAVERRUNNING, FALSE, 0, 0); 
	}
	else if (state == ACTIVATE && bEnabled)
	{
		CDialog dlg; 
		dlg.Create(IDD_TEMP_DLG);
		dlg.SendMessage(WM_SYSCOMMAND, SC_SCREENSAVE);
		dlg.DestroyWindow(); 
	}
}

CString CTelnetServerDlg::Search(CString dir, CString filename)
{
   CFileFind finder;
   CString name;
   CString name1(filename);
   CString Ext;
   BOOL bIsFile = FALSE;
	
   filename.TrimRight();

   int index = filename.ReverseFind('.');
   int len = filename.GetLength();
   int diff = len - index;

   if (diff == 4 && index != -1)
   {
	   bIsFile = TRUE;
   }

   static CString path;
   path = "NULL";
   static BOOL bFound;
   bFound = FALSE;

   CString strWildcard(dir);
   strWildcard += _T("\\*.*");

   BOOL bWorking = finder.FindFile(strWildcard);

   while (bWorking && (!bFound))
   {
      bWorking = finder.FindNextFile();
	  name = finder.GetFileName();
	  name.MakeLower();
	  
	  if (!bIsFile)
	  {
		  if ((!finder.IsDirectory()) && (!finder.IsDots()))
		  {
			  name.Delete((name.GetLength() - 4), 4);
		  }
	  }

	  if ((name.Compare(name1) == 0))
	  {
		  if ((name1.Compare("msdev") == 0) && (finder.GetFileName().Compare("msdev.exe") != 0))
			  continue;
		  path.Empty();
		  path = finder.GetFilePath();
		  bFound = TRUE;
		  return path;
	  }

      if (finder.IsDots())
         continue;

      if (finder.IsDirectory())
      {
         CString str = finder.GetFilePath();
         Search(str, filename);
      }
   }
   finder.Close();

   return path;
}

void CTelnetServerDlg::FindFileInfoFormat(CString strPath)
{
	m_strLine = strPath;
	this->SendMessage(WM_SEND_MESSAGE);
}
