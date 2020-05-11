// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_sscanf_pro.h"
#include "DlgProxy.h"
#include "MFC_sscanf_proDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFC_sscanf_proDlgAutoProxy

IMPLEMENT_DYNCREATE(CMFC_sscanf_proDlgAutoProxy, CCmdTarget)

CMFC_sscanf_proDlgAutoProxy::CMFC_sscanf_proDlgAutoProxy()
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
	ASSERT_KINDOF(CMFC_sscanf_proDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CMFC_sscanf_proDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CMFC_sscanf_proDlgAutoProxy::~CMFC_sscanf_proDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CMFC_sscanf_proDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CMFC_sscanf_proDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CMFC_sscanf_proDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMFC_sscanf_proDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CMFC_sscanf_proDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IMFC_sscanf_pro to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {B6B0CDD5-8BFC-4D72-96D5-08F48F977F7A}
static const IID IID_IMFC_sscanf_pro =
{ 0xb6b0cdd5, 0x8bfc, 0x4d72, { 0x96, 0xd5, 0x8, 0xf4, 0x8f, 0x97, 0x7f, 0x7a } };

BEGIN_INTERFACE_MAP(CMFC_sscanf_proDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CMFC_sscanf_proDlgAutoProxy, IID_IMFC_sscanf_pro, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {B6671145-FC1F-4C8B-8B0C-E55C5AF55BCA}
IMPLEMENT_OLECREATE2(CMFC_sscanf_proDlgAutoProxy, "MFC_sscanf_pro.Application", 0xb6671145, 0xfc1f, 0x4c8b, 0x8b, 0xc, 0xe5, 0x5c, 0x5a, 0xf5, 0x5b, 0xca)

/////////////////////////////////////////////////////////////////////////////
// CMFC_sscanf_proDlgAutoProxy message handlers
