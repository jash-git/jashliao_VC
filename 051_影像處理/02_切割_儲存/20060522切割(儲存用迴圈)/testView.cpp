// testView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "test.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys\timeb.h>
#include "testDoc.h"
#include "testView.h"
#include "DialogShow.h"
#include <string.h>
#include<math.h>
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CPoint start,end;
FILE *f;
CDibSection testDib2;
/////////////////////////////////////////////////////////////////////////////
// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	//{{AFX_MSG_MAP(CTestView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_change, Onchange)
	ON_COMMAND(ID_change1, Onchange1)
	ON_COMMAND(ID_copchange, Oncopchange)
	ON_COMMAND(ID_changegray, Onchangegray)
	ON_COMMAND(IDRGB2CMY, OnRgb2cmy)
	ON_COMMAND(ID_RGB2HSI1, OnRgb2hsi1)
	ON_COMMAND(ID_RGB2HSI2, OnRgb2hsi2)
	ON_COMMAND(ID_RGB2HSI3, OnRgb2hsi3)
	ON_COMMAND(ID_gray_rulers, Ongrayrulers)
	ON_COMMAND(ID_Stretch, OnStretch)
	ON_COMMAND(ID_Equalization, OnEqualization)
	ON_COMMAND(ID_sobel, Onsobel)
	ON_WM_SIZE()
	ON_COMMAND(ID_OpenBmp, OnOpenBmp)
	ON_COMMAND(ID_CutSave, OnCutSave)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestView construction/destruction

CTestView::CTestView()
{
	// TODO: add construction code here

}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestView drawing

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CClientDC dc(this);
	testDib1.Draw(dc,0,0,testDib.Width(),testDib.Height());

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTestView printing

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestView diagnostics

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestView message handlers

void CTestView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	start=point;
	CView::OnLButtonDown(nFlags, point);
}

void CTestView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int w1,h1;
	int i,j;
	int R,G,B;
	end=point;
	w1=abs(end.x-start.x);//任意剪裁產生灰階圖  
	h1=abs(end.y-start.y);
	testDib2.Create(w1,h1,24);
	for(i=0;i<w1;i++)
		for(j=0;j<h1;j++)
		{
			BYTE *q1=(BYTE *)testDib2.GetBits(i,j);
			BYTE *q=(BYTE *)testDib1.GetBits(start.x+i,start.y+j);
/*
			*q1++=*q++;
			*q1++=*q++;
			*q1++=*q++;
*/
			B=*q++;
			G=*q++;
			R=*q++;
			*q1++=(0.299*R+0.587*G+0.114*B);
			*q1++=(0.299*R+0.587*G+0.114*B);
			*q1++=(0.299*R+0.587*G+0.114*B);
		}
	CMainFrame *CMain=(CMainFrame*)AfxGetMainWnd();
	CMain->UpData(testDib2);
	CView::OnLButtonUp(nFlags, point);
}

void CTestView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
/*	void CDibSection::Copy(const CDibSection &dib, CPoint to, CSize size, CPoint from)
{
	BitBlt(CDibDC(*this), to.x, to.y, size.cx, size.cy, CDibDC(dib), from.x, from.y, SRCCOPY);
}
*/
	int R,G,B;
	CSize size;
	CClientDC dc(this);
 	//CDibSection testDib1;
	size.cx=end.x-start.x;//終點座標-起始座標
	size.cy=end.y-start.y;//變成選取範圍
	//設定新圖像在畫布起始位置
	CPoint from;
	from.x =0;
	from.y =0;
	testDib1.Create(640,480,24); 
	//複製(來源物件,目的起始位置,範圍大小,來源起始位置)
	testDib1.Copy(testDib,from,size,start);
	testDib1.Fade(testDib1,256);//改變明亮度
	//const BYTE *q=(const BYTE *)testDib1.GetBits(point.x,point.y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(參考用法)
	BYTE *q=(BYTE *)testDib1.GetBits(point.x,point.y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
	B=*q++;
	G=*q++;
	R=*q++;
	testDib1.Draw(dc,0,0,testDib.Width(),testDib.Height()); //畫圖
	CView::OnRButtonDown(nFlags, point);
}

void CTestView::Onchange()//左右翻轉 
{		
	int x,y;
	int Width,Height;
	CSize size;
	struct timeb t,t1;
	CClientDC dc(this);
 	//CDibSection testDib1(testDib);//直接複製影像
	testDib1.Create(640,480,24);
	for(x=0;x<Width;x++)
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)testDib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			//BYTE *q=(BYTE *)testDib.GetBits(x,Height-1-y);
			//要轉換就要R,G,B一起轉
			COLORREF c1=dc.GetPixel(x,Height-1-y);
			*q1++=GetBValue(c1);
			*q1++=GetGValue(c1);
			*q1++=GetRValue(c1);
		}
	Width=testDib1.Width();
	Height=testDib.Height();
	f=fopen("time.txt","w");
	ftime(&t);
	for(y=0;y<Height;y++)
		for(x=0;x<Width;x++)
		{
			BYTE *q1=(BYTE *)testDib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q=(BYTE *)testDib.GetBits(Width-1-x,y);
			//要轉換就要R,G,B一起轉
			*q1++=*q++;
			*q1++=*q++;
			*q1++=*q++;
		}
	ftime(&t1);
	fprintf(f,"%d\t%d\n%d\t%d\n",t.time,t.millitm,t1.time,t1.millitm);
	fclose(f);
	testDib1.Draw(dc,0,0,testDib.Width(),testDib.Height()); 
}

void CTestView::Onchange1()//上下翻轉 
{
	// TODO: Add your command handler code here
		int x,y;
	int Width,Height;
	CSize size;
	CClientDC dc(this);
 	//CDibSection testDib1(testDib);//直接複製影像
	testDib1.Create(640,480,24);
	for(x=0;x<Width;x++)
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)testDib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			//BYTE *q=(BYTE *)testDib.GetBits(x,Height-1-y);
			//要轉換就要R,G,B一起轉
			COLORREF c1=dc.GetPixel(x,Height-1-y);
			*q1++=GetBValue(c1);
			*q1++=GetGValue(c1);
			*q1++=GetRValue(c1);
		}
	Width=testDib1.Width();
	Height=testDib.Height();
	for(x=0;x<Width;x++)
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)testDib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q=(BYTE *)testDib.GetBits(x,Height-1-y);
			//要轉換就要R,G,B一起轉
			*q1++=*q++;
			*q1++=*q++;
			*q1++=*q++;
		}
	testDib1.Draw(dc,0,0,testDib.Width(),testDib.Height()); 
}

void CTestView::Oncopchange()//從畫布擷取資料送至物件 
{
	// TODO: Add your command handler code here
	int x,y;
	int Width,Height;
	//CDibSection testDib1;
	testDib.LoadBmp("C:\\Documents and Settings\\jash\\桌面\\秀圖和抓像素值和簡易複製\\SAMPLE.BMP");
	CClientDC dc(this);
	testDib.Draw(dc,0,0,testDib.Width(),testDib.Height());
	testDib1.Create(640,480,24);
	Width=testDib1.Width();
	Height=testDib.Height();
	for(x=0;x<Width;x++)
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)testDib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			//BYTE *q=(BYTE *)testDib.GetBits(x,Height-1-y);
			//要轉換就要R,G,B一起轉
			COLORREF c1=dc.GetPixel(x,Height-1-y);
			*q1++=GetBValue(c1);
			*q1++=GetGValue(c1);
			*q1++=GetRValue(c1);
		} 
	testDib1.Draw(dc,0,0,testDib.Width(),testDib.Height());
	testDib1.SaveBmp("C:\\t.bmp");
	MessageBox("saved");
}

void CTestView::Onchangegray() //灰階
{
	int x,y;
	int Width,Height;
	int R,G,B;
	struct timeb t,t1;
	CFileDialog fdlg(true,NULL,"openfile",NULL,"BMP|*.bmp");
	CString Strfilename;
	f=fopen("time.txt","w");
	if(fdlg.DoModal()==IDOK)
	{
		Strfilename=fdlg.GetPathName();

		//MessageBox(filename);
	}
	//CDibSection testDib1;
	ftime(&t);
	testDib.LoadBmp(Strfilename.GetBuffer(0));
	Width=testDib.Width();
	Height=testDib.Height();
	testDib1.Create(Width,Height,24);
	testDib2.Create(Width,Height,24);	

	CClientDC dc(this);
	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)testDib.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q=(BYTE *)testDib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			B=*q1++;
			G=*q1++;
			R=*q1++;
			*q++=(0.299*R+0.587*G+0.114*B);
			*q++=(0.299*R+0.587*G+0.114*B);
			*q++=(0.299*R+0.587*G+0.114*B);
		}
	}
	testDib1.Draw(dc,0,0,testDib.Width(),testDib.Height());
	CMainFrame *CMain=(CMainFrame*)AfxGetMainWnd();
	//CMain->UpData(testDib1);
	testDib2.Copy(testDib1);
	CMain->UpData(testDib2);
	ftime(&t1);
	fprintf(f,"起始時間%d(s)\t%d(ms)\n結束時間%d(s)\t%d(ms)\n",t.time,t.millitm,t1.time,t1.millitm);
	fclose(f);
}

void CTestView::OnRgb2cmy() 
{
	// TODO: Add your command handler code here
	int x,y;
	int Width,Height;
	int R,G,B;
	CFileDialog fdlg(true,NULL,"openfile",NULL,"BMP|*.bmp");
	CString Strfilename;
	if(fdlg.DoModal()==IDOK)
	{
		Strfilename=fdlg.GetPathName();
	}
	testDib.LoadBmp(Strfilename.GetBuffer(0));
	Width=testDib.Width();
	Height=testDib.Height();
	testDib1.Create(Width,Height,24);

	CClientDC dc(this);
	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)testDib.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q=(BYTE *)testDib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			B=*q1++;
			G=*q1++;
			R=*q1++;
			*q++=255-B;
			*q++=255-G;
			*q++=255-R;
		}
	}
	testDib1.Draw(dc,0,0,testDib.Width(),testDib.Height());
}

void CTestView::OnRgb2hsi1() //I
{

	int x,y;
	int Width,Height;
	int R,G,B;
	double I; 
	CFileDialog fdlg(true,NULL,"openfile",NULL,"BMP|*.bmp");
	CString Strfilename;
	if(fdlg.DoModal()==IDOK)
	{
		Strfilename=fdlg.GetPathName();
	}
	testDib.LoadBmp(Strfilename.GetBuffer(0));
	Width=testDib.Width();
	Height=testDib.Height();
	testDib1.Create(Width,Height,24);

	CClientDC dc(this);
	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)testDib.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q=(BYTE *)testDib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			B=*q1++;
			G=*q1++;
			R=*q1++;
			I=R+G+B;
			int k;
			k=3;
			I/=k;
			*q++=I;
			*q++=I;
			*q++=I;
		}
	}
	testDib1.Draw(dc,0,0,testDib.Width(),testDib.Height());
}

void CTestView::OnRgb2hsi2() //H
{

	int x,y;
	int Width,Height;
	int R,G,B;
	double I,H,S,F; 
	CFileDialog fdlg(true,NULL,"openfile",NULL,"BMP|*.bmp");
	CString Strfilename;
	if(fdlg.DoModal()==IDOK)
	{
		Strfilename=fdlg.GetPathName();
	}
	testDib.LoadBmp(Strfilename.GetBuffer(0));
	Width=testDib.Width();
	Height=testDib.Height();
	testDib1.Create(Width,Height,24);

	CClientDC dc(this);
	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)testDib.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q=(BYTE *)testDib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			B=*q1++;
			G=*q1++;
			R=*q1++;
			I=R+G+B;
			F=double(2*R-G-B);
			F=F/double(G-B);
			F=F/1.738;
			if(G>B)
				H=(90-atan(F)*57.3+0)/double(1);//原本為360
			else
				H=(90-atan(F)*57.3+180)/double(1);//原本為360
			*q++=H;
			*q++=H;
			*q++=H;
		}
	}
	testDib1.Draw(dc,0,0,testDib.Width(),testDib.Height());
}

void CTestView::OnRgb2hsi3() //S
{

	int x,y;
	int Width,Height;
	int R,G,B;
	double I,S; //重點
	CFileDialog fdlg(true,NULL,"openfile",NULL,"BMP|*.bmp");
	CString Strfilename;
	if(fdlg.DoModal()==IDOK)
	{
		Strfilename=fdlg.GetPathName();
	}
	testDib.LoadBmp(Strfilename.GetBuffer(0));
	Width=testDib.Width();
	Height=testDib.Height();
	testDib1.Create(Width,Height,24);

	CClientDC dc(this);
	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)testDib.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q=(BYTE *)testDib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			B=*q1++;
			G=*q1++;
			R=*q1++;
			I=R+G+B;
			I/=3;
			S=min(R,min(G,B));
			I=255-(S/I);
			*q++=I;
			*q++=I;
			*q++=I;
		}
	}
	testDib1.Draw(dc,0,0,testDib.Width(),testDib.Height());
}

void CTestView::Ongrayrulers()//直方圖 
{
	int **p;
	int i,j,B=0,G=0,w,h;
	w=testDib2.Width();
	h=testDib2.Height();

	p=new int *[w];
	for(i=0;i<w;i++)
		p[i]=new int[h];
	for(i=0;i<w;i++)
		for(j=0;j<h;j++)
		{
			*(*(p+i)+j)=0;
		}

	for(i=0;i<w;i++)
	{
		for(j=0;j<h;j++)
		{
			BYTE *q1=(BYTE *)testDib2.GetBits(i,j);
			B=*q1++;
			*(*(p+i)+j)=B;
		}
	}
	CDialogShow show1(this);
	show1.getvalue(p,w,h);
	show1.DoModal();
	for(i=0;i<w;i++)
		delete[] p[i];
	delete[] p;
	
	
}

void CTestView::OnStretch()//拉升 
{
	// TODO: Add your command handler code here
	int x,y;
	int Width,Height;
	int R,G,B;
	int **NewData;
	//CDibSection testDib2;
	////////////////////////
	int graylevel[256]={0};
	int temp;
	int Start1 = 0, End1 = 0;
	float temp1,temp2,treshold = 70;
	////////////////////////
	CFileDialog fdlg(true,NULL,"openfile",NULL,"BMP|*.bmp");
	CString Strfilename;
	if(fdlg.DoModal()==IDOK)
	{
		Strfilename=fdlg.GetPathName();

		//MessageBox(filename);
	}

	testDib.LoadBmp(Strfilename.GetBuffer(0));
	Width=testDib.Width();
	Height=testDib.Height();
	testDib1.Create(Width,Height,24);
	testDib2.Create(Width,Height,24);

	CClientDC dc(this);
	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)testDib.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q=(BYTE *)testDib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			B=*q1++;
			G=*q1++;
			R=*q1++;
			*q++=(0.299*R+0.587*G+0.114*B);
			*q++=(0.299*R+0.587*G+0.114*B);
			*q++=(0.299*R+0.587*G+0.114*B);
		}
	}
	testDib1.Draw(dc,0,0,testDib.Width(),testDib.Height());
	NewData = new int*[Width];
	for(x=0;x<Width;x++)
		NewData[x] = new int[Height];
	////////////////////////////////////
	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q=(BYTE *)testDib1.GetBits(x,y);
			B=*q++;
			G=*q++;
			R=*q++;
			*(*(NewData+x)+y) = R;
		}
	}

	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			temp = *(*(NewData+x)+y);
			graylevel[temp]++;
		}
	}

	for(x=0;x<256;x++)
	{
		if(graylevel[x]!=0)
		{
			End1=x;
			if(Start1==0)
				Start1 = x;
		}
	}

	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q=(BYTE *)testDib2.GetBits(x,y);
			temp1 = *(*(NewData+x)+y)-Start1;
			temp2 = End1-Start1;
			temp1 = (temp1/temp2)*255;
			*(*(NewData+x)+y) = (int)temp1;
			*q++=*(*(NewData+x)+y);
			*q++=*(*(NewData+x)+y);
			*q++=*(*(NewData+x)+y);

		}
	}
	
	CMainFrame *CMain=(CMainFrame*)AfxGetMainWnd();
	CMain->UpData(testDib2);
	for(x=0;x<Width;x++)
		delete[] NewData[x];
	delete[] NewData;

	
}

void CTestView::OnEqualization() 
{
// TODO: Add your command handler code here

	int x,y;
	int Width,Height;
	int R,G,B;
	int **NewData;
	float graylevel[256]={0};
	int temp;
	//CDibSection testDib2;
	CFileDialog fdlg(true,NULL,"openfile",NULL,"BMP|*.bmp");
	CString Strfilename;
	if(fdlg.DoModal()==IDOK)
	{
		Strfilename=fdlg.GetPathName();
	}


	testDib.LoadBmp(Strfilename.GetBuffer(0));
	Width=testDib.Width();
	Height=testDib.Height();
	testDib1.Create(Width,Height,24);
	testDib2.Create(Width,Height,24); 
	CClientDC dc(this);
	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)testDib.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q=(BYTE *)testDib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			B=*q1++;
			G=*q1++;
			R=*q1++;
			*q++=(0.299*R+0.587*G+0.114*B);
			*q++=(0.299*R+0.587*G+0.114*B);
			*q++=(0.299*R+0.587*G+0.114*B);
		}
	}
	testDib1.Draw(dc,0,0,testDib.Width(),testDib.Height());
	Width = testDib1.Width();
	Height = testDib1.Height();

	//二維指標陣列
	NewData = new int*[Width];
	for(x=0;x<Width;x++)
		NewData[x] = new int[Height];

	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q=(BYTE *)testDib1.GetBits(x,y);
			B=*q++;
			G=*q++;
			R=*q++;
			*(*(NewData+x)+y) = R;
		}
	}

	for(x=0;x<Width;x++)
		for(y=0;y<Height;y++)
		{
			temp = *(*(NewData+x)+y);
			graylevel[temp]++;
		}
		for(x=0;x<256;x++)

		graylevel[x]=(graylevel[x]/((Width)*(Height)));// probability of each intensiity level
	for(x=0;x<256;x++)
		graylevel[x]=graylevel[x]+graylevel[x-1];// P.D.F. of intensity level
	for(x=0;x<256;x++)
		graylevel[x]=graylevel[x]*255;

	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q=(BYTE *)testDib2.GetBits(x,y);
			temp = *(*(NewData+x)+y);
			*q++=int(graylevel[temp]);
			*q++=int(graylevel[temp]);
			*q++=int(graylevel[temp]);		
		}
	}

	for(x=0;x<Width;x++)
	delete[] NewData[x];
	delete[] NewData;
	
	CMainFrame *CMain=(CMainFrame*)AfxGetMainWnd();
	CMain->UpData(testDib2);
	//testDib1.Draw(dc,0,0,testDib.Width(),testDib.Height());
}

void CTestView::Onsobel() 
{
	// TODO: Add your command handler code here
	//BYTE
	int x,y;
	int Width,Height;
	int R,G,B;
	//BYTE q,q1;
	//CDibSection testDib2;
	CFileDialog fdlg(true,NULL,"openfile",NULL,"BMP|*.bmp");
	CString Strfilename;
	if(fdlg.DoModal()==IDOK)
	{
		Strfilename=fdlg.GetPathName();
	}
	testDib.LoadBmp(Strfilename.GetBuffer(0));
	Width=testDib.Width();
	Height=testDib.Height();
	testDib1.Create(Width,Height,24);
	testDib2.Create(Width,Height,24); 
	///////////////////////////////////////
	int **NewData;
	NewData = new int*[Width];
	for(x=0;x<Width;x++)
		NewData[x] = new int[Height];
	/////////////////////////////////////
	for(x=0;x<Width;x++)
		for(y=0;y<Height;y++)
			*(*(NewData+x)+y) = 0;
	///////////////////////////////////////	

	CClientDC dc(this);
	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)testDib.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q=(BYTE *)testDib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			B=*q1++;
			G=*q1++;
			R=*q1++;
			*q++=(0.299*R+0.587*G+0.114*B);
			*q++=(0.299*R+0.587*G+0.114*B);
			*q++=(0.299*R+0.587*G+0.114*B);
		}
	}
	testDib1.Draw(dc,0,0,testDib.Width(),testDib.Height());
////////////////////////////////////////////////////////////////
		static int nWeight[2][3][3] ;
		nWeight[0][0][0] = -1 ;   
		nWeight[0][0][1] =  0 ;   
		nWeight[0][0][2] =  1 ;   
		nWeight[0][1][0] = -2 ;   
		nWeight[0][1][1] =  0 ;   
		nWeight[0][1][2] =  2 ;   
		nWeight[0][2][0] = -1 ;   
		nWeight[0][2][1] =  0 ;   
		nWeight[0][2][2] =  1 ;   
		
		nWeight[1][0][0] =  1 ;   
		nWeight[1][0][1] =  2 ;   
		nWeight[1][0][2] =  1 ;   
		nWeight[1][1][0] =  0 ;   
		nWeight[1][1][1] =  0 ;   
		nWeight[1][1][2] =  0 ;   
		nWeight[1][2][0] = -1 ;   
		nWeight[1][2][1] = -2 ;   
		nWeight[1][2][2] = -1 ;   

		int nTmp[3][3];

		double dGrad   ;
		double dGradOne;
		double dGradTwo;

		int yy ;
		int xx ;
		for(y=1; y<Height-1 ; y++ )
			for(x=1 ; x<Width-1 ; x++ )
			{
				dGrad    = 0 ; 
				dGradOne = 0 ;
				dGradTwo = 0 ;
				// Laplacian
				

				BYTE *w1=(BYTE *)testDib.GetBits(x-1,y-1);
				nTmp[0][0] = *w1++;//lpImage[(y-1)*nSaveWidth + x - 1 ] ; 
				BYTE *w2=(BYTE *)testDib.GetBits(x,y-1);
				nTmp[0][1] = *w2++;//lpImage[(y-1)*nSaveWidth + x     ] ; 
				BYTE *w3=(BYTE *)testDib.GetBits(x,y-1);
				nTmp[0][2] = *w3++;//lpImage[(y-1)*nSaveWidth + x + 1 ] ; 

				

				BYTE *w4=(BYTE *)testDib.GetBits(x-1,y);
				nTmp[1][0] =*w4++; //lpImage[y*nSaveWidth + x - 1 ] ; 
				BYTE *w5=(BYTE *)testDib.GetBits(x,y);
				nTmp[1][1] =*w5++; //lpImage[y*nSaveWidth + x     ] ; 
				BYTE *w6=(BYTE *)testDib.GetBits(x+1,y);
				nTmp[1][2] =*w6++; //lpImage[y*nSaveWidth + x + 1 ] ; 
				
				
				BYTE *w7=(BYTE *)testDib.GetBits(x-1,y+1);
				nTmp[2][0] =*w7++; //lpImage[(y+1)*nSaveWidth + x - 1 ] ; 
				BYTE *w8=(BYTE *)testDib.GetBits(x,y+1);
				nTmp[2][1] = *w8++;//lpImage[(y+1)*nSaveWidth + x     ] ; 
				BYTE *w9=(BYTE *)testDib.GetBits(x+1,y+1);
				nTmp[2][2] =*w9++; //lpImage[(y+1)*nSaveWidth + x + 1 ] ;
				////////////////////////////////////////////////////////
				for(yy=0; yy<3; yy++)
					for(xx=0; xx<3; xx++)
					{
						dGradOne += nTmp[yy][xx] * nWeight[0][yy][xx] ;
						dGradTwo += nTmp[yy][xx] * nWeight[1][yy][xx] ;
					}
					dGrad = dGradOne*dGradOne + dGradTwo*dGradTwo  ;
					dGrad = sqrt(dGrad) ;
				////////////////////////////////////////////////////////

				if(dGrad > 50)
				{
					*(*(NewData+x)+y)=255;
				}
				else
				{
					*(*(NewData+x)+y)=0;
				}
			}
////////////////////////////////////////////////////////////////////////
	for(x=1;x<Width-1;x++)
		for(y=1;y<Height-1;y++)
		{
			BYTE *k=(BYTE *)testDib2.GetBits(x,y);
			if(*(*(NewData+x)+y) == 255)
			{
				*k++=0;
				*k++=0;
				*k++=0;
			}
			else
			{
				*k++=255;
				*k++=255;
				*k++=255;
			}
		}


	//testDib1.Draw(dc,0,0,testDib.Width(),testDib.Height());
	CMainFrame *CMain=(CMainFrame*)AfxGetMainWnd();
	CMain->UpData(testDib2);
}

void CTestView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	
}

void CTestView::OnOpenBmp() 
{
	// TODO: Add your command handler code here
	int b;
	CFileDialog fdlg(true,NULL,"openfile",NULL,"BMP|*.bmp");
	CString Strfilename;
	if(fdlg.DoModal()==IDOK)
	{
		Strfilename=fdlg.GetPathName();

		//MessageBox(filename);
	}
	testDib.LoadBmp(Strfilename.GetBuffer(0));
	CClientDC dc(this);
	testDib1.Create(testDib.Width(),testDib.Height(),24);

	for(int x=0;x<testDib.Width();x++)
	{
		for(int y=0;y<testDib.Height();y++)
		{
			int R,G,B;
			BYTE *q1=(BYTE *)testDib.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q=(BYTE *)testDib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			B=*q1++;
			G=*q1++;
			R=*q1++;
			*q++=B;
			*q++=G;
			*q++=R;
		}
	}
	testDib1.Draw(dc,0,0,testDib.Width(),testDib.Height());   
	b=testDib.ScanBytes(testDib.Width(),testDib.Depth());


}

void CTestView::OnCutSave() 
{
	// TODO: Add your command handler code here
	OnOpenBmp();
	int x,y;
	int i,j;
	int Width,Height;
	int R,G,B;
	CDibSection **CutDib;
	int n,m;
	int w1,h1;
///////////////////////////////
	n=2;
	m=2;
	Width=testDib1.Width();
	Height=testDib1.Height();
	w1=Width/n;
	h1=Height/m;
	CutDib=new CDibSection *[2];
	for(i=0;i<2;i++)
	{
		CutDib[i]=new CDibSection [2];
	}
	//testDib1.Create(testDib.Width(),testDib.Height(),24);
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			(*(*(CutDib+i)+j)).Create(w1,h1,24); 
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			for(x=(0+w1*i);x<(w1+w1*i);x++)
			{
				for(y=(0+h1*j);y<(h1+h1*j);y++)
				{
					BYTE *q=(BYTE *)testDib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
					BYTE *q1=(BYTE *)(*(*(CutDib+i)+j)).GetBits((x-(0+w1*i)),(y-(0+h1*j)));//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
					B=*q++;
					G=*q++;
					R=*q++;
					*q1++=B;
					*q1++=G;
					*q1++=R;
				}
			}
		}
	}
//testDib1.SaveBmp("C:\\t.bmp");
	char *charnumber1;
	char *charnumber2;
	charnumber1=new char[10];
	charnumber2=new char[10];
	char str[]=".bmp";
	char str1[]="C:\\";
	CString String; 
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			itoa(i,charnumber1,10);
			itoa(j,charnumber2,10);
			String=str1;
			String=String+charnumber1;
			String=String+charnumber2;
			String=String+str;
			(*(*(CutDib+i)+j)).SaveBmp(String.GetBuffer(0));  
		}
/*
	(*(*(CutDib+0)+0)).SaveBmp("C:\\00.bmp");
	(*(*(CutDib+0)+1)).SaveBmp("C:\\01.bmp");
	(*(*(CutDib+1)+0)).SaveBmp("C:\\10.bmp");
	(*(*(CutDib+1)+1)).SaveBmp("C:\\11.bmp");
*/
	MessageBox("ok");


}
