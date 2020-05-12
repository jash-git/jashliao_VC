// ShowBmpView.cpp : implementation of the CShowBmpView class
//

#include "stdafx.h"
#include "ShowBmp.h"
#include <math.h>
#include "ShowBmpDoc.h"
#include "ShowBmpView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowBmpView

IMPLEMENT_DYNCREATE(CShowBmpView, CView)

BEGIN_MESSAGE_MAP(CShowBmpView, CView)
	//{{AFX_MSG_MAP(CShowBmpView)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_Gray, OnGray)
	ON_COMMAND(ID_ShowBar, OnShowBar)
	ON_COMMAND(ID_Sobel, OnSobel)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowBmpView construction/destruction

CShowBmpView::CShowBmpView()
{
	// TODO: add construction code here

}

CShowBmpView::~CShowBmpView()
{
}

BOOL CShowBmpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShowBmpView drawing

void CShowBmpView::OnDraw(CDC* pDC)
{
	CShowBmpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CClientDC dc1(this);
	m_DibShow.Draw(dc1,0,0,m_DibShow.Width(),m_DibShow.Height());
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CShowBmpView printing

BOOL CShowBmpView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CShowBmpView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CShowBmpView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CShowBmpView diagnostics

#ifdef _DEBUG
void CShowBmpView::AssertValid() const
{
	CView::AssertValid();
}

void CShowBmpView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShowBmpDoc* CShowBmpView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShowBmpDoc)));
	return (CShowBmpDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShowBmpView message handlers

void CShowBmpView::OnFileNew() 
{
	// TODO: Add your command handler code here
	
}

void CShowBmpView::OnFileOpen() 
{
	// TODO: Add your command handler code here
	CFileDialog fdlg(true,NULL,"openfile",NULL,"BMP|*.bmp");
	CString Strfilename;
	if(fdlg.DoModal()==IDOK)
	{
		Strfilename=fdlg.GetPathName();
		m_Dib.LoadBmp(Strfilename.GetBuffer(0));
		m_DibShow.Destroy();
		m_DibShow.Create(m_Dib.Width(),m_Dib.Height(),24);
		m_DibShow.Copy(m_Dib); 
		Invalidate(true);
	}	
}

void CShowBmpView::OnGray() 
{
	// TODO: Add your command handler code here
	int x,y,Width,Height;//宣告回悛變數
	int R,G,B;//宣告資料暫存變數
	/////////////////////////
	//變數初始
	x=0;
	y=0;
	R=0;
	G=0;
	B=0;
	/////////////////////////
	Width=m_Dib.Width();//取得影像寬度像素值
	Height=m_Dib.Height();//取得影像高度像素值
	m_DibShow.Destroy();//清空資料
	m_DibShow.Create(m_Dib.Width(),m_Dib.Height(),24);//重新建立空白資料
	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)m_Dib.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q=(BYTE *)m_DibShow.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			///////////////
			//依序分離每一個像素點的RGB，並存入暫存變數
			B=*q1++;
			G=*q1++;
			R=*q1++;
			//////////////
			//////////////
			//利用灰階度公式計算每一點的灰階度，並存入m_DibShow
			*q++=(unsigned char)(0.299*R+0.587*G+0.114*B);
			*q++=(unsigned char)(0.299*R+0.587*G+0.114*B);
			*q++=(unsigned char)(0.299*R+0.587*G+0.114*B);
			//////////////
		}
	}
	Invalidate(true);//觸發重繪
}

void CShowBmpView::OnShowBar() 
{
	// TODO: Add your command handler code here
	m_Dia1.show();	
}
void CShowBmpView::GetData(int a)
{
	// TODO: Add your command handler code here
	int x,y,Width,Height;//宣告回悛變數
	int R,G,B;//宣告資料暫存變數
	int value;
	/////////////////////////
	//變數初始
	x=0;
	y=0;
	R=0;
	G=0;
	B=0;
	value=0;
	/////////////////////////
	Width=m_Dib.Width();//取得影像寬度像素值
	Height=m_Dib.Height();//取得影像高度像素值
	m_DibShow.Destroy();//清空資料
	m_DibShow.Create(m_Dib.Width(),m_Dib.Height(),24);//重新建立空白資料
	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)m_Dib.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q=(BYTE *)m_DibShow.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			///////////////
			//依序分離每一個像素點的RGB，並存入暫存變數
			B=*q1++;
			G=*q1++;
			R=*q1++;
			//////////////
			//////////////
			//利用灰階度公式計算每一點的灰階度，並存入m_DibShow
			value=(int)(0.299*R+0.587*G+0.114*B);
			if(value>=a)
			{
				*q++=(unsigned char)255;
				*q++=(unsigned char)255;
				*q++=(unsigned char)255;
			}
			else
			{
				*q++=(unsigned char)0;
				*q++=(unsigned char)0;
				*q++=(unsigned char)0;
			}
			//////////////
		}
	}
	Invalidate(true);//觸發重繪
}

void CShowBmpView::OnSobel() 
{
	// TODO: Add your command handler code here
	int x,y,Width,Height;//宣告回悛變數
	int R,G,B;//宣告資料暫存變數
	/////////////////////////
	//變數初始
	x=0;
	y=0;
	R=0;
	G=0;
	B=0;
	/////////////////////////
	Width=m_Dib.Width();//取得影像寬度像素值
	Height=m_Dib.Height();//取得影像高度像素值
	m_DibShow.Destroy();//清空資料
	m_DibShow.Create(m_Dib.Width(),m_Dib.Height(),24);//重新建立空白資料
	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)m_Dib.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q=(BYTE *)m_DibShow.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			///////////////
			//依序分離每一個像素點的RGB，並存入暫存變數
			B=*q1++;
			G=*q1++;
			R=*q1++;
			//////////////
			//////////////
			//利用灰階度公式計算每一點的灰階度，並存入m_DibShow
			*q++=(unsigned char)(0.299*R+0.587*G+0.114*B);
			*q++=(unsigned char)(0.299*R+0.587*G+0.114*B);
			*q++=(unsigned char)(0.299*R+0.587*G+0.114*B);
			//////////////
		}
	}
//////////////////////////////////////////////////////////////////////////////////////////
	///*
	static int cx[9]={0,0,0,
		0,1,0,
		0,0,-1
	};
	static int cy[9]={0,0,0,
		0,0,1,
		0,-1,0
	};
	int d[9];
	int dat;
	float xx,yy,zz;
	///////////////////////////////
	int **image_in,**image_out;
	int *pimage_in,*pimage_out;
	image_in = new int*[Width];
	for(x=0;x<Width;x++)
		image_in[x] = new int[Height];
	image_out = new int*[Width];
	for(x=0;x<Width;x++)
		image_out[x] = new int[Height];
	for(x=0;x<Width;x++)
		for(y=0;y<Height;y++)
		{
			BYTE *q=(BYTE *)m_DibShow.GetBits(x,y);
			B=*q++;
			*(*(image_in+x)+y) = B;
			*(*(image_out+x)+y) = 0;
		}
	pimage_in=(int *)image_in;
	pimage_out=(int *)image_out;
	///////////////////////////////
	for(y=1;y<Height-1;y++)
	{
		for(x=1;x<Width-1;x++)
		{
			d[0]=*(*(image_in+x-1)+y-1);
			d[1]=*(*(image_in+x)+y-1);
			d[2]=*(*(image_in+x+1)+y-1);
			d[3]=*(*(image_in+x-1)+y);
			d[4]=*(*(image_in+x)+y);
			d[5]=*(*(image_in+x+1)+y);
			d[6]=*(*(image_in+x-1)+y+1);
			d[7]=*(*(image_in+x)+y+1);
			d[8]=*(*(image_in+x+1)+y+1);
			xx=(float)(cx[0]*d[0]+cx[1]*d[1]+cx[2]*d[2]
				+cx[3]*d[3]+cx[4]*d[4]+cx[5]*d[5]
				+cx[6]*d[6]+cx[7]*d[7]+cx[8]*d[8]);
			yy=(float)(cy[0]*d[0]+cy[1]*d[1]+cy[2]*d[2]
				+cy[3]*d[3]+cy[4]*d[4]+cy[5]*d[5]
				+cy[6]*d[6]+cy[7]*d[7]+cy[8]*d[8]);
			zz=(float)(1*sqrt(xx*xx+yy*yy));
			dat=(int)zz;
			if(dat>255) dat=255;
			*(*(image_out+x)+y)=dat;
		}
	}

	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q=(BYTE *)m_DibShow.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			//////////////
			//利用灰階度公式計算每一點的灰階度，並存入m_DibShow
			*q++=(unsigned char)*(*(image_out+x)+y);
			*q++=(unsigned char)*(*(image_out+x)+y);
			*q++=(unsigned char)*(*(image_out+x)+y);
			//////////////
		}
	}
	//*/
	/////////////////////////////////////////////////////////////////////
	Invalidate(true);//觸發重繪	
}
