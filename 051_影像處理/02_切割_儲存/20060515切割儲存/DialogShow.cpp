// DialogShow.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "DialogShow.h"
#include <stdio.h>
#include <stdlib.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int k[256]={0};
/////////////////////////////////////////////////////////////////////////////
// CDialogShow dialog


CDialogShow::CDialogShow(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogShow::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogShow)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialogShow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogShow)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogShow, CDialog)
	//{{AFX_MSG_MAP(CDialogShow)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogShow message handlers

void CDialogShow::OnPaint() 
{
	CPaintDC dc(this);
	/*
	CRect rect;
	CWnd *pWnd;
	FILE *Y;
	int i=0,j,G;
	Y=fopen("tx1.txt","w");
	pWnd=GetDlgItem(IDC_STATIC1);
	pWnd->GetClientRect(&rect);
	int h=rect.Height();
	int w=rect.Width();
	CPaintDC dc(pWnd); // device context for painting
	dc.MoveTo(0,h); 
	dc.LineTo(w,h);
	dc.MoveTo(0,h); 
	dc.LineTo(0,0);
	for(i=0;i<254;i++)
	{
		dc.MoveTo(i,h-(k[i]/35));
		dc.LineTo((i+1),h-(k[i+1]/35));
		
	}
	*/

}
void CDialogShow::getvalue(int **p,int w,int h)
{
	FILE *Y;
	int i,j,G;

	for(i=0;i<w;i++)
	{
		for(j=0;j<h;j++)
		{
			G=*(*(p+i)+j);
			k[G]=k[G]+1;
			//fprintf(Y,"%d\n",G);
		}
	}
}

void CDialogShow::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CRect rect;
	CWnd *pWnd;

	int i=0,j,G;

	pWnd=GetDlgItem(IDC_STATIC1);
	pWnd->GetClientRect(&rect);
	int h=rect.Height();
	int w=rect.Width();
	CClientDC dc(pWnd); // device context for painting
	dc.MoveTo(0,h); 
	dc.LineTo(w,h);
	dc.MoveTo(0,h); 
	dc.LineTo(0,0);
	for(i=0;i<254;i++)
	{
		dc.MoveTo(i,h-(k[i]/35));
		dc.LineTo((i+1),h-(k[i+1]/35));
		
	}
	for(i=0;i<255;i++)
	{
		k[i]=0;
	}

}
