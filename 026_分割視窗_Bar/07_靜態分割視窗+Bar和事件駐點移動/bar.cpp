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
	CMainFrame1->StaticSplit.SetActivePane(0,1);//重點，如果把這一行變成註解，則當產生bar之後駐點會在view1上，
												//因此CTestView上的OnOtherView按鈕回應事件則馬上不能使用，
												//必須要利用滑鼠去點選CTestView才可以，但若加上此行程式，
												//則依顯示bar之後menu上的OtherView按鈕馬上會動，藉此證明CTestView已得到事件回應權
}