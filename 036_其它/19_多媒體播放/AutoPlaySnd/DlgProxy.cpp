// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "player.h"
#include "DlgProxy.h"
#include "playerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlayerDlgAutoProxy

IMPLEMENT_DYNCREATE(CPlayerDlgAutoProxy, CCmdTarget)

CPlayerDlgAutoProxy::CPlayerDlgAutoProxy()
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
	ASSERT_KINDOF(CPlayerDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CPlayerDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CPlayerDlgAutoProxy::~CPlayerDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CPlayerDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CPlayerDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CPlayerDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CPlayerDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CPlayerDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IPlayer to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {F5B21A85-5EE9-11D7-BCB5-CEB29E77AC3D}
static const IID IID_IPlayer =
{ 0xf5b21a85, 0x5ee9, 0x11d7, { 0xbc, 0xb5, 0xce, 0xb2, 0x9e, 0x77, 0xac, 0x3d } };

BEGIN_INTERFACE_MAP(CPlayerDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CPlayerDlgAutoProxy, IID_IPlayer, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {F5B21A83-5EE9-11D7-BCB5-CEB29E77AC3D}
IMPLEMENT_OLECREATE2(CPlayerDlgAutoProxy, "Player.Application", 0xf5b21a83, 0x5ee9, 0x11d7, 0xbc, 0xb5, 0xce, 0xb2, 0x9e, 0x77, 0xac, 0x3d)

/////////////////////////////////////////////////////////////////////////////
// CPlayerDlgAutoProxy message handlers
