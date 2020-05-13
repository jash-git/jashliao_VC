// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "CreateDelAllDir.h"
#include "DlgProxy.h"
#include "CreateDelAllDirDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCreateDelAllDirDlgAutoProxy

IMPLEMENT_DYNCREATE(CCreateDelAllDirDlgAutoProxy, CCmdTarget)

CCreateDelAllDirDlgAutoProxy::CCreateDelAllDirDlgAutoProxy()
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
	ASSERT_KINDOF(CCreateDelAllDirDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CCreateDelAllDirDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CCreateDelAllDirDlgAutoProxy::~CCreateDelAllDirDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CCreateDelAllDirDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CCreateDelAllDirDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CCreateDelAllDirDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CCreateDelAllDirDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CCreateDelAllDirDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_ICreateDelAllDir to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {90424D72-BBB1-4A2D-9027-5DAE4E4E88D5}
static const IID IID_ICreateDelAllDir =
{ 0x90424d72, 0xbbb1, 0x4a2d, { 0x90, 0x27, 0x5d, 0xae, 0x4e, 0x4e, 0x88, 0xd5 } };

BEGIN_INTERFACE_MAP(CCreateDelAllDirDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CCreateDelAllDirDlgAutoProxy, IID_ICreateDelAllDir, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {AAE41487-6949-4D21-A03F-BF05D0221E08}
IMPLEMENT_OLECREATE2(CCreateDelAllDirDlgAutoProxy, "CreateDelAllDir.Application", 0xaae41487, 0x6949, 0x4d21, 0xa0, 0x3f, 0xbf, 0x5, 0xd0, 0x22, 0x1e, 0x8)

/////////////////////////////////////////////////////////////////////////////
// CCreateDelAllDirDlgAutoProxy message handlers
