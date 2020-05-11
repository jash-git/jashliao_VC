// Bar.cpp : implementation file
//

#include "stdafx.h"
#include "GLbase.h"
#include "Bar.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CMainFrame *CMainFrame1;
/////////////////////////////////////////////////////////////////////////////
// CBar dialog


CBar::CBar(CWnd* pParent /*=NULL*/)
	: CDialogBar()
{
	//{{AFX_DATA_INIT(CBar)
	m_str1 = _T("第一旋轉軸");
	m_str2 = _T("第二旋轉軸");
	m_str3 = _T("第一伸長量");
	m_v1 = 0.0f;
	m_v2 = 0.0f;
	m_v3 = 0.0f;
	//}}AFX_DATA_INIT
}


void CBar::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBar)
	DDX_Control(pDX, IDC_Down3, m_Down3);
	DDX_Control(pDX, IDC_Down2, m_Down2);
	DDX_Control(pDX, IDC_Down1, m_Down1);
	DDX_Control(pDX, IDC_UP3, m_UP3);
	DDX_Control(pDX, IDC_UP2, m_UP2);
	DDX_Control(pDX, IDC_UP1, m_UP1);
	DDX_Text(pDX, IDC_EDIT4, m_str1);
	DDX_Text(pDX, IDC_EDIT5, m_str2);
	DDX_Text(pDX, IDC_EDIT6, m_str3);
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	DDX_Text(pDX, IDC_EDIT2, m_v2);
	DDX_Text(pDX, IDC_EDIT3, m_v3);
	//}}AFX_DATA_MAP
	m_UP1.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON1)); 
	m_Down1.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_UP2.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON1)); 
	m_Down2.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_UP3.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON1)); 
	m_Down3.SetIcon(AfxGetApp()->LoadIcon(IDI_ICON2));
}


BEGIN_MESSAGE_MAP(CBar, CDialogBar)
	//{{AFX_MSG_MAP(CBar)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBar message handlers
void CBar::GetData(float *data)
{
	UpdateData(true);
		*(data+0)=m_v1;
		*(data+1)=m_v2;
		*(data+2)=m_v3;
	UpdateData(false);
}
void CBar::SentData(int index,float data)
{
	UpdateData(true);
	switch(index)
	{
		case 0:
			m_v1+=data;
			m_v2+=0;
			m_v3+=0;
			break;
		case 1:
			m_v1+=0;
			m_v2+=data;
			m_v3+=0;
			break;
		case 2:
			m_v1+=0;
			m_v2+=0;
			m_v3+=data;
			break;
	}
	UpdateData(false);
}
void CBar::show(void)
{
	CMainFrame1=(CMainFrame*)AfxGetMainWnd();
	if(!IsWindow(m_hWnd))
	{
		if(Create(CMainFrame1,IDD_DIALOGBAR,CBRS_LEFT,AFX_IDW_CONTROLBAR_FIRST+32))
		{
			UpdateData(false);
			EnableDocking(CBRS_ALIGN_ANY);
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
