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
	m_str3 = _T("第三旋轉軸");
	m_str4 = _T("第四旋轉軸");
	m_str5 = _T("第五旋轉軸");
	m_str6 = _T("第一伸長量");
	m_v1 = 0.0f;
	m_v2 = 0.0f;
	m_v3 = 0.0f;
	m_v4 = 0.0f;
	m_v5 = 0.0f;
	m_v6 = 0.0f;
	//}}AFX_DATA_INIT
}


void CBar::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBar)
	DDX_Text(pDX, IDC_EDIT7, m_str1);
	DDX_Text(pDX, IDC_EDIT8, m_str2);
	DDX_Text(pDX, IDC_EDIT9, m_str3);
	DDX_Text(pDX, IDC_EDIT10, m_str4);
	DDX_Text(pDX, IDC_EDIT11, m_str5);
	DDX_Text(pDX, IDC_EDIT12, m_str6);
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	DDX_Text(pDX, IDC_EDIT2, m_v2);
	DDX_Text(pDX, IDC_EDIT3, m_v3);
	DDX_Text(pDX, IDC_EDIT4, m_v4);
	DDX_Text(pDX, IDC_EDIT5, m_v5);
	DDX_Text(pDX, IDC_EDIT6, m_v6);
	//}}AFX_DATA_MAP
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
		*(data+3)=m_v4;
		*(data+4)=m_v5;
		*(data+5)=m_v6;
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
