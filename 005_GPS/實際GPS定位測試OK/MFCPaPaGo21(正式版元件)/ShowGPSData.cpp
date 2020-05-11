// ShowGPSData.cpp : implementation file
//

#include "stdafx.h"
#include "MFCPaPaGo.h"
#include "ShowGPSData.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CMainFrame *CMainFrame1;
/////////////////////////////////////////////////////////////////////////////
// CShowGPSData dialog


CShowGPSData::CShowGPSData(CWnd* pParent /*=NULL*/)
	: CDialogBar()
{
	//{{AFX_DATA_INIT(CShowGPSData)
	m_X = 0;
	m_Rate = 0.0;
	m_Y = 0;
	m_length = _T("");
	m_v1 = 0;
	m_v2 = 0;
	//}}AFX_DATA_INIT
}


void CShowGPSData::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShowGPSData)
	DDX_Text(pDX, IDC_EDIT1, m_X);
	DDX_Text(pDX, IDC_EDIT3, m_Rate);
	DDX_Text(pDX, IDC_EDIT2, m_Y);
	DDX_Text(pDX, IDC_EDIT4, m_length);
	DDX_Text(pDX, IDC_EDIT5, m_v1);
	DDX_Text(pDX, IDC_EDIT6, m_v2);
	//}}AFX_DATA_MAP
}

void CShowGPSData::show(void)
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
void CShowGPSData::showdata(long a,long b,double c,CString &strlength)
{
	UpdateData(true);
		m_X=a;
		m_Y=b;
		m_Rate=c;
		m_length=strlength;
	UpdateData(false);
}
void CShowGPSData::showdata(long a1,long b1)
{
	UpdateData(true);
		m_v1=a1;
		m_v2=b1;
	UpdateData(false);
}
BEGIN_MESSAGE_MAP(CShowGPSData, CDialogBar)
	//{{AFX_MSG_MAP(CShowGPSData)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowGPSData message handlers
