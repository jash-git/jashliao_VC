// viewbar.cpp : implementation file
//

#include "stdafx.h"
#include "Showview.h"
#include "viewbar.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CMainFrame *CMainFrame1;
/////////////////////////////////////////////////////////////////////////////
// viewbar dialog


viewbar::viewbar(CWnd* pParent /*=NULL*/)
	: CDialogBar(/*viewbar::IDD, pParent*/)
{
	//{{AFX_DATA_INIT(viewbar)
	m_Kdc = 0.0;
	m_Kdx = 0.0;
	m_Kdy = 0.0;
	m_Kic = 0.0;
	m_Kix = 0.0;
	m_Kiy = 0.0;
	m_Kpc = 0.0;
	m_Kpx = 0.0;
	m_Kpy = 0.0;
	m_Slope = 0.0;
	m_LifeX = 0.0;
	m_LifeY = 0.0;
	m_LifeZ = 0.0;
	m_WorkN = 0.0;
	//}}AFX_DATA_INIT
}


void viewbar::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(viewbar)
	DDX_Text(pDX, IDC_Kdc, m_Kdc);
	DDX_Text(pDX, IDC_Kdx, m_Kdx);
	DDX_Text(pDX, IDC_Kdy, m_Kdy);
	DDX_Text(pDX, IDC_Kic, m_Kic);
	DDX_Text(pDX, IDC_Kix, m_Kix);
	DDX_Text(pDX, IDC_Kiy, m_Kiy);
	DDX_Text(pDX, IDC_Kpc, m_Kpc);
	DDX_Text(pDX, IDC_Kpx, m_Kpx);
	DDX_Text(pDX, IDC_Kpy, m_Kpy);
	DDX_Text(pDX, IDC_Slope, m_Slope);
	DDX_Text(pDX, IDC_LifeX, m_LifeX);
	DDX_Text(pDX, IDC_LifeY, m_LifeY);
	DDX_Text(pDX, IDC_LifeZ, m_LifeZ);
	DDX_Text(pDX, IDC_WorkN, m_WorkN);
	//}}AFX_DATA_MAP
}
void viewbar::Show(void)
{
	CMainFrame1=(CMainFrame*)AfxGetMainWnd();
	if(!IsWindow(m_hWnd))
	{
		if(Create(CMainFrame1,IDD_DIALOGBAR,CBRS_LEFT,AFX_IDW_CONTROLBAR_FIRST+32))
		{
			UpdateData(false);
			EnableDocking(CBRS_ALIGN_LEFT);
			CMainFrame1->DockControlBar(this,AFX_IDW_DOCKBAR_LEFT);
			m_Kdc = 10.0;
			m_Kdx = 20.0;
			m_Kdy = 30.0;
			m_Kic = 40.0;
			m_Kix = 50.0;
			m_Kiy = 60.0;
			m_Kpc = 70.0;
			m_Kpx = 80.0;
			m_Kpy = 90.0;
			m_Slope = 100.0;
			UpdateData(false);
		}
	}
	else
	{
		CMainFrame1->ShowControlBar(this,!IsWindowVisible(),false); 
	}
}
void viewbar::SetValue(double pid[9], double theta)
{
			m_Kdx = *(pid+0);
			m_Kpx = *(pid+1);
			m_Kix = *(pid+2);
			m_Kdy = *(pid+3);
			m_Kpy = *(pid+4);
			m_Kiy = *(pid+5);
			m_Kdc = *(pid+6);
			m_Kpc = *(pid+7);
			m_Kic = *(pid+8);
			m_Slope = theta;
			UpdateData(false);
}
void viewbar::map_value(double x,double y,double z,double n)
{
	m_LifeX = x;
	m_LifeY = y;
	m_LifeZ = z;
	m_WorkN = n;
	UpdateData(false);
}
BEGIN_MESSAGE_MAP(viewbar, CDialogBar)
	//{{AFX_MSG_MAP(viewbar)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// viewbar message handlers
