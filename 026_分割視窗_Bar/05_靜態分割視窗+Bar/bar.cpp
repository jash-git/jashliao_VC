// bar.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "bar.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CMainFrame *CMainFrame1;
/////////////////////////////////////////////////////////////////////////////
// bar dialog


bar::bar(CWnd* pParent /*=NULL*/)
	: CDialogBar()
{
	//{{AFX_DATA_INIT(bar)
	m_v1 = 0;
	m_v2 = 0;
	//}}AFX_DATA_INIT
}


void bar::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(bar)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	DDX_Text(pDX, IDC_EDIT2, m_v2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(bar, CDialogBar)
	//{{AFX_MSG_MAP(bar)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// bar message handlers
void bar::showdata(int a,int b)
{
	UpdateData(true);
		m_v1=a;
		m_v2=b;
	UpdateData(false);

}
void bar::show(void)
{
	CMainFrame1=(CMainFrame*)AfxGetMainWnd();
	if(!IsWindow(m_hWnd))
	{
		if(Create(CMainFrame1,IDD_DIALOGBAR,CBRS_LEFT,AFX_IDW_CONTROLBAR_FIRST+32))
		{
			UpdateData(false);
			EnableDocking(CBRS_ALIGN_LEFT);
			CMainFrame1->DockControlBar(this,AFX_IDW_DOCKBAR_LEFT);
			UpdateData(false);
			//p=fopen("test.txt","w");
		}
	}
	else
	{
		CMainFrame1->ShowControlBar(this,!IsWindowVisible(),false); 
		//fclose(p);
	}

}