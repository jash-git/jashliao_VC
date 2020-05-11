// Frame1.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "Frame1.h"
#include "View2.h"
#include "testView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrame1

IMPLEMENT_DYNCREATE(CFrame1, CFrameWnd)

CFrame1::CFrame1()
{
}

CFrame1::~CFrame1()
{
}


BEGIN_MESSAGE_MAP(CFrame1, CFrameWnd)
	//{{AFX_MSG_MAP(CFrame1)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrame1 message handlers

BOOL CFrame1::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	StaticSplit.CreateStatic(this,2,1);	//建立靜態分裂視窗
	StaticSplit.CreateView(0,0,RUNTIME_CLASS(CTestView),CSize(400,120),pContext);
	//建立瀏覽區所使用的View物件
	StaticSplit.CreateView(1,0,RUNTIME_CLASS(CView2),CSize(400,300),pContext);
	//建立繪圖區所使用的View物件
	//StaticSplit.SetActivePane(0,0);	//設定繪圖區為作用的子視窗
	//CTestView1=(CTestView*)StaticSplit.GetPane(0,1);
	return true;
}
