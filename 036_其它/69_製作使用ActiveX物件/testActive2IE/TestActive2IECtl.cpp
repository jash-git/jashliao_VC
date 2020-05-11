// TestActive2IECtl.cpp : Implementation of the CTestActive2IECtrl ActiveX Control class.

#include "stdafx.h"
#include "testActive2IE.h"
#include "TestActive2IECtl.h"
#include "TestActive2IEPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CTestActive2IECtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTestActive2IECtrl, COleControl)
	//{{AFX_MSG_MAP(CTestActive2IECtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CTestActive2IECtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CTestActive2IECtrl)
	DISP_FUNCTION(CTestActive2IECtrl, "SetIP", SetIP, VT_BOOL, VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CTestActive2IECtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CTestActive2IECtrl, COleControl)
	//{{AFX_EVENT_MAP(CTestActive2IECtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CTestActive2IECtrl, 1)
	PROPPAGEID(CTestActive2IEPropPage::guid)
END_PROPPAGEIDS(CTestActive2IECtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CTestActive2IECtrl, "TESTACTIVE2IE.TestActive2IECtrl.1",
	0xf6daf276, 0xf62f, 0x4322, 0x86, 0x4d, 0x18, 0x7d, 0x3e, 0x39, 0x75, 0x51)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CTestActive2IECtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DTestActive2IE =
		{ 0xd13fb5ae, 0x7d22, 0x4db3, { 0x80, 0xf1, 0x24, 0xa8, 0x8a, 0x9e, 0xe0, 0xd6 } };
const IID BASED_CODE IID_DTestActive2IEEvents =
		{ 0x92516cc0, 0x8e08, 0x42da, { 0xa6, 0x6b, 0x5d, 0xfc, 0xbf, 0x57, 0xf0, 0xb2 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwTestActive2IEOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CTestActive2IECtrl, IDS_TESTACTIVE2IE, _dwTestActive2IEOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CTestActive2IECtrl::CTestActive2IECtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CTestActive2IECtrl

BOOL CTestActive2IECtrl::CTestActive2IECtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_TESTACTIVE2IE,
			IDB_TESTACTIVE2IE,
			afxRegApartmentThreading,
			_dwTestActive2IEOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CTestActive2IECtrl::CTestActive2IECtrl - Constructor

CTestActive2IECtrl::CTestActive2IECtrl()
{
	InitializeIIDs(&IID_DTestActive2IE, &IID_DTestActive2IEEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CTestActive2IECtrl::~CTestActive2IECtrl - Destructor

CTestActive2IECtrl::~CTestActive2IECtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CTestActive2IECtrl::OnDraw - Drawing function

void CTestActive2IECtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CTestActive2IECtrl::DoPropExchange - Persistence support

void CTestActive2IECtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CTestActive2IECtrl::OnResetState - Reset control to default state

void CTestActive2IECtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CTestActive2IECtrl::AboutBox - Display an "About" box to the user

void CTestActive2IECtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_TESTACTIVE2IE);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CTestActive2IECtrl message handlers

BOOL CTestActive2IECtrl::SetIP(LPCTSTR IP, LPCTSTR Mak, LPCTSTR GatWay, LPCTSTR DNS1, LPCTSTR DNS2) 
{
	// TODO: Add your dispatch handler code here
	FILE *pf;
	pf=fopen("C:\\SetIP.bat","w");
	/////////////////////////////////////////////////////////////////////////////////////
	CString StrBuf="";
	StrBuf="netsh interface ip set address name=\"跋办硈絬\" source=static addr=";
	StrBuf+=IP;
	StrBuf+=" mask=";
	StrBuf+=Mak;
	fprintf(pf,"%s\n",StrBuf.GetBuffer(0));
	//**********************************************************************************
	StrBuf="";
	StrBuf="netsh interface ip set address name=\"跋办硈絬\" gateway=";
	StrBuf+=GatWay;
	StrBuf+=" gwmetric=0";
	fprintf(pf,"%s\n",StrBuf.GetBuffer(0));
	//**********************************************************************************
	StrBuf="";
	StrBuf="netsh interface ip set dns name=\"跋办硈絬\" source=static addr=";
	StrBuf+=DNS1;
	StrBuf+=" register=PRIMARY";
	fprintf(pf,"%s\n",StrBuf.GetBuffer(0));
	//**********************************************************************************
	StrBuf="";
	StrBuf="netsh interface ip add dns name=\"跋办硈絬\" addr=";
	StrBuf+=DNS2;
	StrBuf+=" index=2";
	fprintf(pf,"%s\n",StrBuf.GetBuffer(0));
	//***********************************************************************************
	StrBuf="";
	StrBuf="exit";
	fprintf(pf,"%s\n",StrBuf.GetBuffer(0));
	//////////////////////////////////////////////////////////////////////////////////////
	fclose(pf);
	//////////////////////////////////////////////////////////////////////////////////////
	SHELLEXECUTEINFO ShExecInfo = {0};
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = "C:\\SetIP.bat";		
	ShExecInfo.lpParameters = "";	
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_MINIMIZE;
	ShExecInfo.hInstApp = NULL;
	ShellExecuteEx(&ShExecInfo);
	WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
	return TRUE;
}
