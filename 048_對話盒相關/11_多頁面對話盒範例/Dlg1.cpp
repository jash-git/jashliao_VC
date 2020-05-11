// Dlg1.cpp : implementation file
//

#include "stdafx.h"
#include "Tab.h"
#include "Dlg1.h"
#include "Command.h"
#include "Text.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg1 dialog


CDlg1::CDlg1(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

}


void CDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg1, CDialog)
	//{{AFX_MSG_MAP(CDlg1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg1 message handlers

int CDlg1::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class

	return CDialog::DoModal();
}
void CDlg1::show()
{
	sheet=new CPropertySheet("test");
	CCommand c1;
	CText t1;
	sheet->AddPage(&c1);
	sheet->AddPage(&t1);
	if(sheet->DoModal()==IDOK)
	{
		m_v1=c1.m_v1; 
		m_v2=t1.m_v1;
	}
}