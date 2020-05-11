// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "kk1.h"
#include "view1.h"
#include "kk1Doc.h"
#include "kk1View.h"
#include "MainFrm.h"
#include "Dialog_set.h"
#include "SetCoordinate.h"
#include <stdlib.h>
#include <math.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CKk1Doc *CKk1Doc2;
/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_bar, Onbar)
	ON_COMMAND(ID_test, Ontest)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_Set, OnSet)
	ON_COMMAND(ID_Set1, OnSet1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here

}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

/*
BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class

	StaticSplit.CreateStatic(this,2,1);	//建立靜態分裂視窗
	StaticSplit.CreateView(0,0,RUNTIME_CLASS(view1),CSize(500,500),pContext);
	//建立瀏覽區所使用的View物件
	StaticSplit.CreateView(1,0,RUNTIME_CLASS(CKk1View),CSize(400,300),pContext);
	//建立繪圖區所使用的View物件
	//StaticSplit.SetActivePane(1,0);	//設定繪圖區為作用的子視窗
	CKk1View1=(CKk1View*)StaticSplit.GetPane(1,0);
	return true;
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
}
*/
void CMainFrame::Onbar() 
{
	// TODO: Add your command handler code here

	viewbar1.Show();
}

void CMainFrame::Ontest() 
{
	// TODO: Add your command handler code here
	viewbar1.UpdateData(true);
	CKk1Doc2=(CKk1Doc*)GetActiveDocument();
	
	if((viewbar1.m_setvalue-viewbar1.m_trackingvalue)<=0)
	{
		CKk1Doc2->SetTitle("ok");
	}
	else
	{
		CKk1Doc2->SetTitle("ko");
	}
}

void CMainFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	MessageBox("ok");
	CFrameWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
void CMainFrame::Update(int x,int y,int pitch,int yaw,int row,int sw)
{
	
	CKk1View1->Update(x,y,pitch,yaw,row,sw);
}

void CMainFrame::OnSet() 
{
	// TODO: Add your command handler code here
	Dialog_set d1(this);
	if(d1.DoModal()==IDOK)
	{
		CKk1View1->dialog_set=d1.m_set; 
		CKk1View1->Invalidate(true);
	}
}

void CMainFrame::OnSet1() 
{
	// TODO: Add your command handler code here
	int set_value,set_value1,set_x,set_y,set_z,set_x1,set_y1,set_z1,set_x2,set_y2,set_z2;
	SetCoordinate dlg(this);
	if(dlg.DoModal()==IDOK)
	{
		set_value=dlg.m_set; 
		set_value1=dlg.m_set1; 
		set_x=dlg.m_x;
		set_y=dlg.m_y;
		set_z=dlg.m_z;
		set_x1=dlg.m_x1;
		set_y1=dlg.m_y1;
		set_z1=dlg.m_z1;
		set_x2=dlg.m_x2;
		set_y2=dlg.m_y2;
		set_z2=dlg.m_z2;
		f1(set_value,set_value1,set_x,set_y,set_z,set_x1,set_y1,set_z1,set_x2,set_y2,set_z2);
	}
}
void CMainFrame::f1(int set_value,int set_value1,float x1,float y1,float z1,float x2,float y2,float z2,float x3,float y3,float z3)
{
/*	
	printf("轉換後資料\n");
	printf("%f\t%f\t%f\n",x1,y1,z1);
	printf("%f\t%f\t%f\n",x2,y2,z2);
	printf("%f\t%f\t%f\n",x3,y3,z3);
*/
	float X_Value,Y_Value;
	switch(set_value)
	{
	case 1:
		if(set_value1==1)
		{
			X_Value=88.6;
			Y_Value=189;
		}
		else
		{
			X_Value=119.4;
			Y_Value=73.8;
		}
		break;
	case 2:
		if(set_value1==1)
		{
			X_Value=53.8;
			Y_Value=350;
		}
		else
		{
			X_Value=84.6;
			Y_Value=200;
		}
		break;
	case 3:
		if(set_value1==1)
		{
			X_Value=19;
			Y_Value=430;
		}
		else
		{
			X_Value=49.8;
			Y_Value=330;
		}
		break;
	}
	float a[3][3];
	float x,y,z;
	a[0][0]=1;
	a[0][1]=1;
	a[0][2]=1;
	a[1][0]=(x2-x1);
	a[1][1]=(y2-y1);
	a[1][2]=(z2*-1)-(z1*-1);
	a[2][0]=(x3-x1);
	a[2][1]=(y3-y1);
	a[2][2]=(z3*-1)-(z1*-1);
/*
	printf("矩陣資料\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%f\t",a[i][j]);
			if(j==2)
				printf("\n");
		}
	}
*/	
	x=(a[0][0]*a[1][1]*a[2][2])-(a[0][0]*a[2][1]*a[1][2]);
	y=(a[0][1]*a[1][2]*a[2][0])-(a[0][1]*a[1][0]*a[2][2]);
	z=(a[0][2]*a[2][1]*a[1][0])-(a[0][2]*a[1][1]*a[2][0]);
/*
	printf("法向量\n");
	printf("%f\t%f\t%f\n",x,y,z);
*/
	double alpha,beta,gamma,phi,phi1,thita_3;
	alpha=acos(x/sqrt(pow(x,2)+pow(y,2)+pow(z,2)));
	beta=acos(y/sqrt(pow(x,2)+pow(y,2)+pow(z,2)));
	gamma=acos(z/sqrt(pow(x,2)+pow(y,2)+pow(z,2)));
	phi=acos(cos(alpha)/sin(gamma));
	phi1=-phi;//Rotate1
	thita_3=acos(sqrt(pow(x,2)+pow(y,2))/sqrt(pow(x,2)+pow(y,2)+pow(z,2)))+0;//Rotate3
	Update(X_Value,Y_Value,(phi1*57.3)+180,0,thita_3*57.3,2);
/*
	printf("角度\n");

	printf("%f\t%f\t%f\t%f\t%f\t%f\n",alpha*57.3,beta*57.3,gamma*57.3,phi*57.3,phi1*57.3,thita_2*57.3);
*/

}
