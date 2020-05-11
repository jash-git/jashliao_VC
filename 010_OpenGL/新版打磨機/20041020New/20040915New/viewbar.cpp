// viewbar.cpp : implementation file
//

#include "stdafx.h"
#include "New.h"
#include "viewbar.h"
#include "MainFrm.h"
#include <stdio.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CMainFrame *CMainFrame1;
//FILE *p;
/////////////////////////////////////////////////////////////////////////////
// viewbar dialog


viewbar::viewbar(CWnd* pParent /*=NULL*/)
	: CDialogBar()
{
	//{{AFX_DATA_INIT(viewbar)
	m_X = 0.0f;
	m_Y = 0.0f;
	m_Z = 0.0f;
	m_R1 = 0.0f;
	m_R2 = 0.0f;
	m_Pxr3 = 0.0f;
	m_Pyr3 = 0.0f;
	m_Pzr3 = 0.0f;
	m_Theta = 0.0f;
	//}}AFX_DATA_INIT
}


void viewbar::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(viewbar)
	DDX_Text(pDX, IDC_EDIT1, m_X);
	DDX_Text(pDX, IDC_EDIT2, m_Y);
	DDX_Text(pDX, IDC_EDIT3, m_Z);
	DDX_Text(pDX, IDC_EDIT4, m_R1);
	DDX_Text(pDX, IDC_EDIT5, m_R2);
	DDX_Text(pDX, IDC_Pxr3, m_Pxr3);
	DDX_Text(pDX, IDC_Pyr3, m_Pyr3);
	DDX_Text(pDX, IDC_Pzr3, m_Pzr3);
	DDX_Text(pDX, IDC_Theta, m_Theta);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(viewbar, CDialogBar)
	//{{AFX_MSG_MAP(viewbar)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
void viewbar::show()
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
void viewbar::showdata(float x,float y,float z,float r1,float r2, float Pxr3, float Pyr3, float Pzr3, float Theta)
{
	UpdateData(true);
	m_X = x;
	m_Y = y;
	m_Z = z;
	m_R1 = r1;
	m_R2 = r2;
	m_Pxr3 = Pxr3;
	m_Pyr3 = Pyr3;
	m_Pzr3 = Pzr3;
	m_Theta = Theta;
	//fprintf(p,"%f\t%f\t%f\t%f\t%f\n",m_X,m_Y,m_Z,m_R1,m_R2);
	UpdateData(false);
}
/////////////////////////////////////////////////////////////////////////////
// viewbar message handlers
