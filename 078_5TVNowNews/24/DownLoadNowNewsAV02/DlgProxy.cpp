// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "DownLoadNowNewsAV.h"
#include "DlgProxy.h"
#include "DownLoadNowNewsAVDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDownLoadNowNewsAVDlgAutoProxy

IMPLEMENT_DYNCREATE(CDownLoadNowNewsAVDlgAutoProxy, CCmdTarget)

CDownLoadNowNewsAVDlgAutoProxy::CDownLoadNowNewsAVDlgAutoProxy()
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
	ASSERT_KINDOF(CDownLoadNowNewsAVDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CDownLoadNowNewsAVDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CDownLoadNowNewsAVDlgAutoProxy::~CDownLoadNowNewsAVDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CDownLoadNowNewsAVDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CDownLoadNowNewsAVDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CDownLoadNowNewsAVDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CDownLoadNowNewsAVDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CDownLoadNowNewsAVDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IDownLoadNowNewsAV to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {95986D42-5CA7-4AFF-B5F7-5E653DADAE32}
static const IID IID_IDownLoadNowNewsAV =
{ 0x95986d42, 0x5ca7, 0x4aff, { 0xb5, 0xf7, 0x5e, 0x65, 0x3d, 0xad, 0xae, 0x32 } };

BEGIN_INTERFACE_MAP(CDownLoadNowNewsAVDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CDownLoadNowNewsAVDlgAutoProxy, IID_IDownLoadNowNewsAV, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {261D84C1-33A1-4081-BFC4-10F98CCAB738}
IMPLEMENT_OLECREATE2(CDownLoadNowNewsAVDlgAutoProxy, "DownLoadNowNewsAV.Application", 0x261d84c1, 0x33a1, 0x4081, 0xbf, 0xc4, 0x10, 0xf9, 0x8c, 0xca, 0xb7, 0x38)

/////////////////////////////////////////////////////////////////////////////
// CDownLoadNowNewsAVDlgAutoProxy message handlers
