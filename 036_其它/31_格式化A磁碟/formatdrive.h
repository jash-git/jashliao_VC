/*******************************************************************
 *
 *	filename	: FormatDrive.h
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
 *				: arguments/ An errorcode can be returned.
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
#if !defined(AFX_FORMATDISK_H__03003AF3_1D87_4A66_8F85_3118B8E4BDF1__INCLUDED_)
#define AFX_FORMATDISK_H__03003AF3_1D87_4A66_8F85_3118B8E4BDF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAX_LABEL	12

typedef enum
{
	UNKNOWN_OS = 0,			
	WINDOWS_NT35,
	WINDOWS_95OSR1,
	WINDOWS_95OSR2,
	WINDOWS_NT4,
	WINDOWS_98FE,
	WINDOWS_98SE,
	WINDOWS_ME,
	WINDOWS_2000,
	WINDOWS_XP
} OS_VERSIONS;

class CFormatDriveDialog
{
public:
		   CFormatDriveDialog  (void);
		   ~CFormatDriveDialog (void);	

/**********************************************************************************
// FUNCTION      : CFormatDriveDialog::DoModal()
// 
// Description   : This function pops up the Format disk dialog and configures it.
//				   (Only one instance allowed at a time within one single App!!!)
// 
// Pre-Condition : Instance created of CFormatDriveDialog.
//
// Returns       : [int] - IDOK:	 Format has completed successfully
//                         IDCANCEL: Format has been Cancelled
//                         IDABORT:  Format has aborted due to Operating System
//									 problems
// Parameters    : [IN     : hWnd]	 
//									Handle to the calling Window(Class) that will
//									own the dialog. NOTE that hwnd == NULL does 
//									not cause this dialog to come up as a 
//									"top level application" window. This parameter
//									should always be non-null, this dialog box is
//									only designed to be the child of another window,
//									not a stand-alone application.
//                 [IN     : cDrive] 
//									Character that specifies the drive letter
//									e.g. 'A', or 'C', ONLY UPPERCASE!!
//                 [IN     : bQuickFormat]
//									Default setting for Quickformat. This can be
//									overruled by the user! (default is ignored on
//									NT4, NT4 comes	always up with quickformat set)
//                 [IN     : sLabel] 
//									Volume name of the drive. This cannot be 
//									altered by the user!
***********************************************************************************/
	int	   DoModal (HWND hWnd, char cDrive, bool bQuickFormat, LPCTSTR sLabel);

private:
	static BOOL CALLBACK	EvaluateWindowElements( HWND hwnd, LPARAM lParam );
	static LRESULT CALLBACK CBTProc(int nCode,WPARAM wParam, LPARAM lParam);
	static OS_VERSIONS		GetTheSystemVersion(void);
	
	static HHOOK	m_hHook;	
	static char		m_sVolumeLabel[MAX_LABEL];
	static bool		m_bQuick;
	static HWND		m_hFormatDialog;
};

#endif // !defined(AFX_FORMATDISK_H__03003AF3_1D87_4A66_8F85_3118B8E4BDF1__INCLUDED_)
