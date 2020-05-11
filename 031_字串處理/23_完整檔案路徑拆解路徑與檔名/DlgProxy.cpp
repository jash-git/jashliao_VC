// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "GetPathAndName.h"
#include "DlgProxy.h"
#include "GetPathAndNameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGetPathAndNameDlgAutoProxy

IMPLEMENT_DYNCREATE(CGetPathAndNameDlgAutoProxy, CCmdTarget)

CGetPathAndNameDlgAutoProxy::CGetPathAndNameDlgAutoProxy()
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
	ASSERT_KINDOF(CGetPathAndNameDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CGetPathAndNameDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CGetPathAndNameDlgAutoProxy::~CGetPathAndNameDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CGetPathAndNameDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CGetPathAndNameDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CGetPathAndNameDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CGetPathAndNameDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CGetPathAndNameDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IGetPathAndName to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {F405204B-FEB6-4536-83E4-332BD25F6196}
static const IID IID_IGetPathAndName =
{ 0xf405204b, 0xfeb6, 0x4536, { 0x83, 0xe4, 0x33, 0x2b, 0xd2, 0x5f, 0x61, 0x96 } };

BEGIN_INTERFACE_MAP(CGetPathAndNameDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CGetPathAndNameDlgAutoProxy, IID_IGetPathAndName, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {4C100DF5-D25F-4BCF-962A-7D0BA1BFE1A2}
IMPLEMENT_OLECREATE2(CGetPathAndNameDlgAutoProxy, "GetPathAndName.Application", 0x4c100df5, 0xd25f, 0x4bcf, 0x96, 0x2a, 0x7d, 0xb, 0xa1, 0xbf, 0xe1, 0xa2)

/////////////////////////////////////////////////////////////////////////////
// CGetPathAndNameDlgAutoProxy message handlers
