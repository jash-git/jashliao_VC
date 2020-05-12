// ShowBmp.cpp : implementation file
//

#include "stdafx.h"
#include "Image1.h"
#include "ShowBmp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CDibSection Dib2;
CDibSection Dib3;
int v;
bool bf=false;
CString Strfilename;
/////////////////////////////////////////////////////////////////////////////
// CShowBmp

IMPLEMENT_DYNCREATE(CShowBmp, CView)

CShowBmp::CShowBmp()
{
}

CShowBmp::~CShowBmp()
{
}


BEGIN_MESSAGE_MAP(CShowBmp, CView)
	//{{AFX_MSG_MAP(CShowBmp)
	ON_COMMAND(ID_show1, Onshow1)
	ON_WM_SIZE()
	ON_COMMAND(ID_show2, Onshow2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowBmp drawing

void CShowBmp::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();

//Dib2.Copy(Dib3);
	CClientDC dc(this);
	Dib3.Draw(dc,0,0,Dib3.Width(),Dib3.Height());
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CShowBmp diagnostics

#ifdef _DEBUG
void CShowBmp::AssertValid() const
{
	CView::AssertValid();
}

void CShowBmp::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG
void CShowBmp::Data(int Invalue)
{
	
	v=Invalue;
	int x,y;
	int Width,Height;
	int R,G,B;
	BYTE *q1;
	if(bf==false)
	{
		CFileDialog fdlg(true,NULL,"openfile",NULL,"BMP|*.bmp");
		//f=fopen("time.txt","w");
		if(fdlg.DoModal()==IDOK)
		{
			Strfilename=fdlg.GetPathName();
		}
		Dib1.LoadBmp(Strfilename.GetBuffer(0));
		bf=true;
	}
	Width=Dib1.Width();
	Height=Dib1.Height();


	Dib2.Create(Width,Height,24);
	CClientDC dc(this);
	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)Dib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q=(BYTE *)Dib2.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			B=*q1++;
			G=*q1++;
			R=*q1++;
			*q++=(0.299*R+0.587*G+0.114*B);
			*q++=(0.299*R+0.587*G+0.114*B);
			*q++=(0.299*R+0.587*G+0.114*B);
		}
	}
	Width=Dib2.Width();
	Height=Dib2.Height(); 
	Dib3.Create(Width,Height,24);
	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)Dib3.GetBits(x,y);
			BYTE *q=(BYTE *)Dib2.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			B=*q++;
			if( B > v)
			{
			*q1++=255;
			*q1++=255;
			*q1++=255;
			}
			else
			{
			*q1++=0;
			*q1++=0;
			*q1++=0;
			}

		}
	}
	Dib3.Draw(dc,0,0,Dib3.Width(),Dib3.Height());	
}
/////////////////////////////////////////////////////////////////////////////
// CShowBmp message handlers

void CShowBmp::Onshow1() 
{
	// TODO: Add your command handler code here
	//Dib1
//	CDibSection Dib2;
	int x,y;
	int Width,Height;
	int R,G,B;
	//struct timeb t,t1;
	CFileDialog fdlg(true,NULL,"openfile",NULL,"BMP|*.bmp");
	CString Strfilename;
	//f=fopen("time.txt","w");
	if(fdlg.DoModal()==IDOK)
	{
		Strfilename=fdlg.GetPathName();
	}
	Dib1.LoadBmp(Strfilename.GetBuffer(0));
	Width=Dib1.Width();
	Height=Dib1.Height();
	Dib3.Create(Width,Height,24);
	CClientDC dc(this);
	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)Dib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q=(BYTE *)Dib3.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			B=*q1++;
			G=*q1++;
			R=*q1++;
			*q++=(0.299*R+0.587*G+0.114*B);
			*q++=(0.299*R+0.587*G+0.114*B);
			*q++=(0.299*R+0.587*G+0.114*B);
		}
	}
	Dib3.Draw(dc,0,0,Dib2.Width(),Dib2.Height());
	Invalidate(true);
}

void CShowBmp::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	Invalidate(true);
	// TODO: Add your message handler code here
	
}

void CShowBmp::Onshow2() 
{
MessageBox("test");
}
