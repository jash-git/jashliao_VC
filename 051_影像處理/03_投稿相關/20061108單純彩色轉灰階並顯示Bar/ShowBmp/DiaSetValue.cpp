// DiaSetValue.cpp : implementation file
//

#include "stdafx.h"
#include "ShowBmp.h"
#include "DiaSetValue.h"
#include "MainFrm.h"
#include "ShowBmpView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CMainFrame*	CMainFrame1;
/////////////////////////////////////////////////////////////////////////////
// CDiaSetValue dialog


CDiaSetValue::CDiaSetValue(CWnd* pParent /*=NULL*/)
	: CDialogBar()
{
	//{{AFX_DATA_INIT(CDiaSetValue)
	m_v1 = 0;
	//}}AFX_DATA_INIT
}


void CDiaSetValue::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDiaSetValue)
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	//}}AFX_DATA_MAP
}
void CDiaSetValue::show()
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
	m_slider.SetRange(0,255);
}

BEGIN_MESSAGE_MAP(CDiaSetValue, CDialogBar)
	//{{AFX_MSG_MAP(CDiaSetValue)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiaSetValue message handlers


