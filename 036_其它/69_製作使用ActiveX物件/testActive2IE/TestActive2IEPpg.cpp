// TestActive2IEPpg.cpp : Implementation of the CTestActive2IEPropPage property page class.

#include "stdafx.h"
#include "testActive2IE.h"
#include "TestActive2IEPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CTestActive2IEPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTestActive2IEPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CTestActive2IEPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CTestActive2IEPropPage, "TESTACTIVE2IE.TestActive2IEPropPage.1",
	0x58ebfc6, 0x8e4b, 0x4e36, 0xb1, 0xfa, 0x21, 0x80, 0x77, 0x5e, 0xc5, 0x67)


/////////////////////////////////////////////////////////////////////////////
// CTestActive2IEPropPage::CTestActive2IEPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CTestActive2IEPropPage

BOOL CTestActive2IEPropPage::CTestActive2IEPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_TESTACTIVE2IE_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CTestActive2IEPropPage::CTestActive2IEPropPage - Constructor

CTestActive2IEPropPage::CTestActive2IEPropPage() :
	COlePropertyPage(IDD, IDS_TESTACTIVE2IE_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CTestActive2IEPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CTestActive2IEPropPage::DoDataExchange - Moves data between page and properties

void CTestActive2IEPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CTestActive2IEPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CTestActive2IEPropPage message handlers
