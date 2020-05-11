/*******************************************************************
 *
 *	filename	: FormatDrive.cpp
 *
 *	Title		: implementation of the CFormatDriveDialog class.
 *	Abstract	: This class can be used to format a drive
 *				: from Sourcecode. The normal Windows dialog
 *				: is used of Windows 95/98/NT4/2000/XP
 *
 *	Interface	: 2 functions are exported.The constructor
 *				: and the DoModal function. First an instance
 *				: of this class need to be created and the
 *				: DoModal function can be called with the proper
 *				: arguments. An errorcode can be returned.
 *
 *	Keywords	: Format Drive
 *
 *	Version:	: 1
 *	Created_by	: R.W.G. Böhmer (www.bohmer.net)
 *	Date_created: 2002, June, 23
 *
 *  2002 R.W.G.Böhmer, Grubbenvorst, The Netherlands
 *
 *******************************************************************
 *
 *  You may freely use this source code in personal, freeware, 
 *  shareware or commercial applications provided that my name is 
 *  recognized in the code. IF this code represents a 
 *  substantial portion of the application, my name must be included
 *  in the credits for the application (about box, etc)
 * 
 *  Use this code at your own risk. This code is provided AS-IS.
 *  No warranty is granted as to the correctness, usefulness or
 *  value of this code. 
 *  If you discover any bug, please solve this bug and email me the
 *  bugfix (entire source file) which I can use for future release.
 *  Please, email it to OpenSource@bohmer.net
 *
 *******************************************************************
 *
 *  TECHNICAL NOTES:
 *
 *  DO NOT USE THE NAME 'Format' anywhere in one of the parent dialog
 *  ClassNames, or dialog titles.
 *  This will cause undesired effects to the parent window components!
 *  Otherwise place the parent names in the if-statement in the method
 *  CBTProc, just like the delivered example does!
 *
 *  This code is suitable for Windows 95/98/NT4/2000/XP only.
 *  Other OS can also work properly, but this is never tested!
 *	Maybe some configuring work need to be done.
 *  
 *  This Source file does use a precompiled header.
 *  If precompiled header are not used, then add the project property
 *
 *					NOT_USE_PRECOMPILED_HEADER
 *
 *	Otherwise the normal include file 'StdAfx.h' will be used.
 *
 ******************************************************************
 * Date			: 23 june 2002
 * Version		: 1
 * Modified by	: R.W.G. Böhmer
 * Reference	: 
 * Description	: Initial Version
 * ***************************************************************** 
*/ 
#ifndef NOT_USE_PRECOMPILED_HEADER
#	include "StdAfx.h"
#else
#	define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#	include <afxwin.h>         // MFC core and standard components
#endif

#include "formatdrive.h"

#define QUICK_DETECT_TEXT_ON_FORMATDLG	"Quick"
#define FULL_DETECT_TEXT_ON_FORMATDLG	"Full"

// For the following dialognames, See the Technical Notes above
#define INCLUDE_DIALOG_TITLE1			"Format"
#define EXCLUDE_DIALOG_TITLE1			"FormatDriveSample"
#define EXCLUDE_DIALOG_TITLE2			"Howto: Format"

#define PRODUCT_TYPE_BUFSIZE			80

/*****************************************************************
The SHFormatDrive API provides access to the Shell's format
dialog box. This allows applications that want to format disks to bring
up the same dialog box that the Shell uses for disk formatting.

PARAMETERS
  hwnd    = The window handle of the window that will own the
			dialog. NOTE that hwnd == NULL does not cause this
			dialog to come up as a "top level application"
			window. This parameter should always be non-null,
			this dialog box is only designed to be the child of
			another window, not a stand-alone application.

  drive   = The 0 based (A: == 0) drive number of the drive
			to format.

  fmtID   = Currently must be set to SHFMT_ID_DEFAULT.

  options = There are currently only two option bits defined.

			   SHFMT_OPT_FULL
			   SHFMT_OPT_SYSONLY

			SHFMT_OPT_FULL specifies that the "Quick Format"
			setting should be cleared by default. If the user
			leaves the "Quick Format" setting cleared, then a
			full format will be applied (this is useful for
			users that detect "unformatted" disks and want
			to bring up the format dialog box).

			If options is set to zero (0), then the "Quick Format"
			setting is set by default. In addition, if the user leaves
			it set, a quick format is performed. Under Windows NT 4.0,
			this flag is ignored and the "Quick Format" box is always
			checked when the dialog box first appears. The user can
			still change it. This is by design.

			The SHFMT_OPT_SYSONLY initializes the dialog to
			default to just sys the disk.

			All other bits are reserved for future expansion
			and must be 0.

			Please note that this is a bit field and not a
			value, treat it accordingly.

  RETURN
	 The return is either one of the SHFMT_* values, or if
	 the returned DWORD value is not == to one of these
	 values, then the return is the physical format ID of the
	 last successful format. The LOWORD of this value can be
	 passed on subsequent calls as the fmtID parameter to
	 "format the same type you did last time".

*****************************************************************/

//
// Special value of fmtID which means "use the defaultformat"
//
#define SHFMT_ID_DEFAULT		 0xFFFF
//
// Option bits for options parameter
//
#define SHFMT_OPT_FULL			 0x0001
#define SHFMT_OPT_SYSONLY		 0x0002
//
// Special return values. PLEASE NOTE that these are DWORD values.
//
#define SHFMT_ERROR				 0xFFFFFFFFL // Error on last format,
											 // drive may be formatable
#define SHFMT_CANCEL			 0xFFFFFFFEL // Last format wascanceled
#define SHFMT_NOFORMAT			 0xFFFFFFFDL // Drive is not formatable
#define SHFMT_FMTSUCCESS		 0x00000000L // Drive is formatted
#define SHFMT_FMT_UNKNOWN_BUT_OK 0x00000006L // Unknown, but OK

typedef	DWORD WINAPI SH_FORMATDRIVE( HWND hwnd,
									 UINT drive,
									 UINT fmtID,
									 UINT options);
	

// Instance of the static Class Members
HHOOK	CFormatDriveDialog::m_hHook			= NULL;
HWND	CFormatDriveDialog::m_hFormatDialog	= NULL;
bool	CFormatDriveDialog::m_bQuick		= false;
char    CFormatDriveDialog::m_sVolumeLabel[MAX_LABEL];

// Construction/Destruction
CFormatDriveDialog::CFormatDriveDialog(void)
{
	strcpy(m_sVolumeLabel,"");
}

CFormatDriveDialog::~CFormatDriveDialog(void)
{
}

/**********************************************************************************
// FUNCTION      : CFormatDriveDialog::DoModal()
// 
// Description   : This function creates the Format disk dialog and and installs
//				   the hook and callback functions that will configure the
//				   FormatDrive dialog.	
// 
// Created       : [23-6-2002 17:20:30]
// Returns       : [int] - IDOK:	 Format has completed successfully
//                         IDCANCEL: Format has been Cancelled
//                         IDABORT:  Format has aborted due to Operating System
//									 problems
// Parameters    : [IN     : hWnd]	 Handle to the calling Window(Class) This may 
//									 not be NULL.
//                 [IN     : cDrive] Character that specifies the drive letter
//									 e.g. 'A', or 'C', ONLY UPPERCASE!!
//                 [IN     : bQuickFormat]  Default setting for Quickformat. This
//											can be overruled by the user!
//                 [IN     : sLabel] Volume name of the drive. This cannot be 
//									 altered by the user!
***********************************************************************************/
int CFormatDriveDialog::DoModal(HWND hWnd, char cDrive, bool bQuickFormat, LPCTSTR sLabel)
{
	ASSERT(hWnd);
	ASSERT((cDrive >= 'A') && (cDrive<='Z'));

	bool DisplayErrorDialog = false;
	int  RetVal				= IDABORT;
		 m_bQuick			= bQuickFormat;

	strncpy(m_sVolumeLabel, sLabel, MAX_LABEL-1);
	
	SH_FORMATDRIVE* dl_SHFormatDrive;
	HINSTANCE hShell = LoadLibrary("shell32.dll");

	if(hShell != NULL) // If the method is found in the shell32.dll library
	{
		dl_SHFormatDrive = reinterpret_cast<SH_FORMATDRIVE*>(GetProcAddress(hShell,"SHFormatDrive"));

		if (dl_SHFormatDrive != NULL)
		{
			// Set a callback function that will be called before activating, creating, destroying, 
			// minimizing, maximizing, moving, or sizing a window; before completing a system 
			// command; before removing a mouse or keyboard event from the system message queue;
			// before setting the keyboard focus; or before synchronizing with the system message queue.
			m_hHook = SetWindowsHookEx( WH_CBT,
										CBTProc,
										AfxGetApp()->m_hInstance,
										AfxGetApp()->m_nThreadID);
			
			// Call the SHFormatDrive function
			DWORD FormatResult;
			switch (GetTheSystemVersion())
			{
			case WINDOWS_95OSR1:
			case WINDOWS_95OSR2:
			case WINDOWS_98FE:
			case WINDOWS_98SE:
			case WINDOWS_NT4:
				// Notice that the Win98's SHFormatDrive function needs a different argument
				// list as the Windows 2000 based versions (Quickformat option is inverted)
				FormatResult = (*dl_SHFormatDrive)( hWnd,
								 cDrive - 'A',
								 SHFMT_ID_DEFAULT,
								 bQuickFormat?0:SHFMT_OPT_FULL);
				break;
			case WINDOWS_XP:
			case WINDOWS_2000:
				FormatResult = (*dl_SHFormatDrive)( hWnd,
								 cDrive - 'A',
								 SHFMT_ID_DEFAULT,
								 bQuickFormat?SHFMT_OPT_FULL:0);
				break;
			case UNKNOWN_OS:
			case WINDOWS_ME:
			case WINDOWS_NT35:
			default:
				DisplayErrorDialog = true;
				FormatResult = SHFMT_NOFORMAT;
				break;
			}
			if ( (SHFMT_FMTSUCCESS == FormatResult) ||
				 (SHFMT_FMT_UNKNOWN_BUT_OK == FormatResult) )
			{
				// Setting the volumelabel is not entirely reliable in the
				// SH_Format function.
				CString sDrive;
				sDrive.Format("%c:\\",cDrive);
				SetVolumeLabel( sDrive, m_sVolumeLabel );
				RetVal = IDOK;
			}
			else
			{
				RetVal = IDCANCEL;
			}
		}
		else
		{
			DisplayErrorDialog = true;
		}
		FreeLibrary(hShell);
	}
	else
	{
		DisplayErrorDialog = true;
	}

	// When there was an error accessing the Format Drive dialog an alternative
	// Window will be thrown. This dialog should make clear to the user what to do
	// now.
	if (DisplayErrorDialog)
	{
		CString csBuffer;
		CString csDefaultText("Not possible to open the Disk Format dialog\n\n" \
							  "Open 'My Computer' and Format the Floppy manually.\n\n");
		CString csLabel(m_sVolumeLabel);

		if (0 != csLabel.GetLength())
		{
			csBuffer.Format("%sSet volumelabel to: '%s'", csDefaultText, csLabel);
		}
		else
		{
			csBuffer.Format("%sLeave Volumename Empty!",csDefaultText);
		}
		MessageBox(NULL,csBuffer,"Error Accessing FormatDrive Dialog",MB_ICONEXCLAMATION);
	}
	return RetVal;
}

/**********************************************************************************
// FUNCTION      : CFormatDriveDialog::CBTProc()
// 
// Description   : This function will be called as Hook Callback procedure every-
//				   time before activating, creating, destroying, minimizing, 
//				   maximizing, moving, or sizing a window; before completing a system 
//				   command; before removing a mouse or keyboard event from the
//				   system message queue; before setting the keyboard focus; 
//				   or before synchronizing with the system message queue.
// 
// Created       : [23-6-2002 17:20:30]
// Returns       : [int] - ALWAYS FALSE!!
// Parameters    : [IN     : xxx] See MSDN (SetWindowsHookEx method)
***********************************************************************************/
LRESULT CALLBACK CFormatDriveDialog::CBTProc(int nCode,WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	switch (nCode)
	{
	case HCBT_DESTROYWND:
		{
			char buffer[255];
			GetWindowText(reinterpret_cast<HWND>(wParam),buffer,sizeof(buffer));
			CString csWindowTitle(buffer);

			// only handle the 'Format' dialog and Exclude the FormatDriveSample dialog.
			if (reinterpret_cast<HWND>(wParam) == m_hFormatDialog)
			{
				UnhookWindowsHookEx(m_hHook);
				CFormatDriveDialog::m_hHook = NULL;
				m_hFormatDialog = NULL;
			}
		}
		break;
	case HCBT_ACTIVATE:
		{
			char buffer[255];
			GetWindowText(reinterpret_cast<HWND>(wParam),buffer,sizeof(buffer));
			CString csWindowTitle(buffer);

			// only handle the 'Format' dialog and Exclude the FormatDriveSample dialog.
			if ( (-1 != csWindowTitle.Find(INCLUDE_DIALOG_TITLE1)) && 
				 (-1 == csWindowTitle.Find(EXCLUDE_DIALOG_TITLE1)) &&
				 (-1 == csWindowTitle.Find(EXCLUDE_DIALOG_TITLE2)) )
			{
				// Set the FormatDialog to the window that is created
				m_hFormatDialog = reinterpret_cast<HWND>(wParam);
				EnumChildWindows(m_hFormatDialog,EvaluateWindowElements,NULL);	
			}
		}
		break;
	case HCBT_CREATEWND:
	case HCBT_CLICKSKIPPED:
	case HCBT_KEYSKIPPED:
	case HCBT_SETFOCUS:
		if (NULL != m_hFormatDialog)
		{
			switch (GetTheSystemVersion())
			{
			case WINDOWS_95OSR1:
			case WINDOWS_95OSR2:
			case WINDOWS_98FE:
			case WINDOWS_98SE:
			case WINDOWS_NT4:
				EnumChildWindows(m_hFormatDialog,EvaluateWindowElements,NULL);	
				break;
			case WINDOWS_2000:
			case WINDOWS_XP:
			case UNKNOWN_OS:
			case WINDOWS_ME:
			case WINDOWS_NT35:
			default:
				break;
			}
		}
		break;
	case HCBT_SYSCOMMAND:
	case HCBT_MOVESIZE:
	case HCBT_MINMAX:
	case HCBT_QS:
	default:
		// Unknown code for this type of dialog
		break;
	}
	return FALSE;
}

/**********************************************************************************
// FUNCTION      : CFormatDriveDialog::EvaluateWindowElements()
// 
// Description   : This function will be called whenever the FormatDrive dialog
//				   is created and every element on that dialog need to be
//				   evaluated
// 
// Created       : [23-6-2002 17:20:30]
// Returns       : [int] - ALWAYS TRUE!!
// Parameters    : [IN     : xxx] See MSDN (EnumChildWindows method)
***********************************************************************************/
BOOL CALLBACK CFormatDriveDialog::EvaluateWindowElements( HWND hwnd, LPARAM lParam )
{	
	UNREFERENCED_PARAMETER(lParam);

	char sClassName[256];
	GetClassName(hwnd,sClassName,sizeof(sClassName));
	
	// Disable all the Edit boxes on the window
	if(0 == strcmp(sClassName,"Edit"))
	{
		SetWindowText(hwnd,m_sVolumeLabel);
		EnableWindow(hwnd,FALSE);
	}
	
	// Disable all the Combo boxes on the window
	if(0 == strcmp(sClassName,"ComboBox"))
	{
		EnableWindow(hwnd,FALSE);
	}
	
	// Disable some Buttons on the window (depends on OS type)
	// Windows 95/98 contain a different dialog than Windows 2000 based
	// systems.
	if(0 == strcmp(sClassName,"Button"))
	{
		char sButtonText[255];
		GetWindowText(hwnd,sButtonText,sizeof(sButtonText));

		long ButtonStyle = GetWindowLong(hwnd,GWL_STYLE);

		// Now disable only the buttons that are allowed to be disabled.
		// (If due to language problems some language problems some buttons cannot
		// be properly detected they will be disabled. Therefore the default
		// format settings must be logical chosen.)
		switch (GetTheSystemVersion())
		{
		case WINDOWS_95OSR1:
		case WINDOWS_95OSR2:
		case WINDOWS_98FE:
		case WINDOWS_98SE:
		case WINDOWS_NT4:
			{
				CString csButtonText(sButtonText);
				if ((-1 == csButtonText.Find(QUICK_DETECT_TEXT_ON_FORMATDLG)) &&
					(-1 == csButtonText.Find(FULL_DETECT_TEXT_ON_FORMATDLG)) )
				{
					// Only Checkboxes can have these options set
					if ((ButtonStyle & BS_CHECKBOX) || (ButtonStyle & BS_RADIOBUTTON))
					{
						EnableWindow(hwnd,FALSE);
					}
				}
			}
			break;
		case WINDOWS_2000:
			{
				// Only Checkboxes can have these options set
				if ((ButtonStyle & BS_CHECKBOX) || (ButtonStyle & BS_RADIOBUTTON))
				{
					EnableWindow(hwnd,FALSE);
				}
				CString csButtonText(sButtonText);
				if (-1 != csButtonText.Find(QUICK_DETECT_TEXT_ON_FORMATDLG))
				{
					EnableWindow(hwnd,TRUE);
				}			 
			}
			break;
		case WINDOWS_XP:
			{
				// Only Checkboxes can have these options set
				if ((ButtonStyle & BS_CHECKBOX) || (ButtonStyle & BS_RADIOBUTTON))
				{
					EnableWindow(hwnd,FALSE);
				}

				CString csButtonText(sButtonText);
				if (-1 != csButtonText.Find(QUICK_DETECT_TEXT_ON_FORMATDLG))
				{
					EnableWindow(hwnd,TRUE);
				}			 
			}
			break;
		case UNKNOWN_OS:
		case WINDOWS_ME:
		case WINDOWS_NT35:
		default:
			{
				// Only Checkboxes can have these options set
				if ((ButtonStyle & BS_CHECKBOX) || (ButtonStyle & BS_RADIOBUTTON))
				{
					EnableWindow(hwnd,FALSE);
				}
				//unsupported Operating system
			}
			break;
		}
	}
	return TRUE;
}

/**********************************************************************************
// FUNCTION      : CFormatDriveDialog::GetTheSystemVersion()
// 
// Description   : This function can be used to detect the OS version this app is
//				   running on.
// 
// Created       : [23-6-2002 17:20:30]
// Returns       : [int] - OS_VERSIONS: Version ID of the OS this app is running
// Parameters    : [IN     : void]
***********************************************************************************/
OS_VERSIONS CFormatDriveDialog::GetTheSystemVersion(void)
{
	OSVERSIONINFOEX osvi;
	BOOL bOsVersionInfoEx;
	static OS_VERSIONS OsAlreadyDetected = UNKNOWN_OS;

	// The following check is only used for performance improvement of this check
	// (This check normally returns always the same value per Application Run, the
	// OS will never change during runtime of this application)
	if (UNKNOWN_OS != OsAlreadyDetected)
	{
		return OsAlreadyDetected;
	}

	// Try calling GetVersionEx using the OSVERSIONINFOEX structure.
	// If that fails, try using the OSVERSIONINFO structure.

	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

	bOsVersionInfoEx = GetVersionEx ((OSVERSIONINFO *) &osvi);
	if( !bOsVersionInfoEx )
	{
		// If OSVERSIONINFOEX doesn't work, try OSVERSIONINFO.
		osvi.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
		if (! GetVersionEx ( (OSVERSIONINFO *) &osvi) ) 
		{
			OsAlreadyDetected = UNKNOWN_OS;
			return UNKNOWN_OS;
		}
	}

	switch (osvi.dwPlatformId)
	{
	// Tests for Windows NT product family.
	case VER_PLATFORM_WIN32_NT:
		// Test for the product.
		if ( osvi.dwMajorVersion <= 4 )
		{
			OsAlreadyDetected = WINDOWS_NT35;
			return WINDOWS_NT35;
		}
		if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0 )
		{
			OsAlreadyDetected = WINDOWS_2000;
			return WINDOWS_2000;
		}
		if( bOsVersionInfoEx )  // Use information from GetVersionEx.
		{ 
			if ((osvi.dwMajorVersion == 5) && (osvi.dwMinorVersion == 1) )
			{
				OsAlreadyDetected = WINDOWS_XP;
				return WINDOWS_XP;
			}
			else
			{
				OsAlreadyDetected = UNKNOWN_OS;
				return UNKNOWN_OS;
			}
		}
		else   // Use the registry on early versions of Windows NT.
		{
			HKEY hKey;
			char szProductType[PRODUCT_TYPE_BUFSIZE];
			DWORD dwBufLen = PRODUCT_TYPE_BUFSIZE;
			LONG lRet;

			lRet = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
								 "SYSTEM\\CurrentControlSet\\Control\\ProductOptions",
						 		 0, KEY_QUERY_VALUE, &hKey );
			if( lRet != ERROR_SUCCESS )
			{
				OsAlreadyDetected = UNKNOWN_OS;
				return UNKNOWN_OS;
			}

			lRet = RegQueryValueEx( hKey, "ProductType", NULL, NULL,
									(LPBYTE) szProductType, &dwBufLen);
			if( (lRet != ERROR_SUCCESS) || (dwBufLen > PRODUCT_TYPE_BUFSIZE) )
			{
				OsAlreadyDetected = UNKNOWN_OS;
				return UNKNOWN_OS;
			}

			RegCloseKey( hKey );

			if (( lstrcmpi( "WINNT", szProductType) == 0 ) ||
				( lstrcmpi( "LANMANNT", szProductType) == 0 ) ||
				( lstrcmpi( "SERVERNT", szProductType) == 0 ) )
			{
				OsAlreadyDetected = WINDOWS_NT4;
				return WINDOWS_NT4;
			}
		}
		break;


	// Test for the Windows 95 product family.
	case VER_PLATFORM_WIN32_WINDOWS:
		if ((osvi.dwMajorVersion == 4) && (osvi.dwMinorVersion == 0))
		{
			if ( (osvi.szCSDVersion[1] == 'C') || (osvi.szCSDVersion[1] == 'B') )
			{
				OsAlreadyDetected = WINDOWS_95OSR2;
				return WINDOWS_95OSR2;
			}
			else
			{
				OsAlreadyDetected = WINDOWS_95OSR1;
				return WINDOWS_95OSR1;
			}
		} 
		if ((osvi.dwMajorVersion == 4) && (osvi.dwMinorVersion == 10))
		{
			if ( osvi.szCSDVersion[1] == 'A' )
			{
				OsAlreadyDetected = WINDOWS_98SE;
				return WINDOWS_98SE;
			}
			else
			{
				OsAlreadyDetected = WINDOWS_98FE;
				return WINDOWS_98FE;
			}
		} 
		if ((osvi.dwMajorVersion == 4) && (osvi.dwMinorVersion == 90))
		{
			OsAlreadyDetected = WINDOWS_ME;
			return WINDOWS_ME;
		} 
		break;
	}
	OsAlreadyDetected = UNKNOWN_OS;
	return UNKNOWN_OS; 
}