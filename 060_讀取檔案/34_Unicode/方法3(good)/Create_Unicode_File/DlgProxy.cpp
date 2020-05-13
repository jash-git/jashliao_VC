// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "Create_Unicode_File.h"
#include "DlgProxy.h"
#include "Create_Unicode_FileDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCreate_Unicode_FileDlgAutoProxy

IMPLEMENT_DYNCREATE(CCreate_Unicode_FileDlgAutoProxy, CCmdTarget)

CCreate_Unicode_FileDlgAutoProxy::CCreate_Unicode_FileDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT (AfxGetApp()->m_pMainWnd != NULL);
	ASSERT_VALID (AfxGetApp()->m_pMainWnd);
	ASSERT_KINDOF(CCreate_Unicode_FileDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CCreate_Unicode_FileDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CCreate_Unicode_FileDlgAutoProxy::~CCreate_Unicode_FileDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CCreate_Unicode_FileDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CCreate_Unicode_FileDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CCreate_Unicode_FileDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CCreate_Unicode_FileDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CCreate_Unicode_FileDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_ICreate_Unicode_File to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {D3E9C2B4-0031-438A-8C41-89CBDB133BC7}
static const IID IID_ICreate_Unicode_File =
{ 0xd3e9c2b4, 0x31, 0x438a, { 0x8c, 0x41, 0x89, 0xcb, 0xdb, 0x13, 0x3b, 0xc7 } };

BEGIN_INTERFACE_MAP(CCreate_Unicode_FileDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CCreate_Unicode_FileDlgAutoProxy, IID_ICreate_Unicode_File, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {F1139B3A-8B4D-415A-B93E-C11A6DB436FB}
IMPLEMENT_OLECREATE2(CCreate_Unicode_FileDlgAutoProxy, "Create_Unicode_File.Application", 0xf1139b3a, 0x8b4d, 0x415a, 0xb9, 0x3e, 0xc1, 0x1a, 0x6d, 0xb4, 0x36, 0xfb)

/////////////////////////////////////////////////////////////////////////////
// CCreate_Unicode_FileDlgAutoProxy message handlers
