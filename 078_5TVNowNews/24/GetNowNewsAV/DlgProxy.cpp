// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "GetNowNewsAV.h"
#include "DlgProxy.h"
#include "GetNowNewsAVDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGetNowNewsAVDlgAutoProxy

IMPLEMENT_DYNCREATE(CGetNowNewsAVDlgAutoProxy, CCmdTarget)

CGetNowNewsAVDlgAutoProxy::CGetNowNewsAVDlgAutoProxy()
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
	ASSERT_KINDOF(CGetNowNewsAVDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CGetNowNewsAVDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CGetNowNewsAVDlgAutoProxy::~CGetNowNewsAVDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CGetNowNewsAVDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CGetNowNewsAVDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CGetNowNewsAVDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CGetNowNewsAVDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CGetNowNewsAVDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IGetNowNewsAV to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {81D371FD-B305-4755-88D0-164CDAA7B86F}
static const IID IID_IGetNowNewsAV =
{ 0x81d371fd, 0xb305, 0x4755, { 0x88, 0xd0, 0x16, 0x4c, 0xda, 0xa7, 0xb8, 0x6f } };

BEGIN_INTERFACE_MAP(CGetNowNewsAVDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CGetNowNewsAVDlgAutoProxy, IID_IGetNowNewsAV, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {A427B7ED-B04A-417C-8CDD-566F555C9E94}
IMPLEMENT_OLECREATE2(CGetNowNewsAVDlgAutoProxy, "GetNowNewsAV.Application", 0xa427b7ed, 0xb04a, 0x417c, 0x8c, 0xdd, 0x56, 0x6f, 0x55, 0x5c, 0x9e, 0x94)

/////////////////////////////////////////////////////////////////////////////
// CGetNowNewsAVDlgAutoProxy message handlers
