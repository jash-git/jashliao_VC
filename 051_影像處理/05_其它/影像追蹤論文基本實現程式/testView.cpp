// testView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "test.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys\timeb.h>
#include "testDoc.h"
#include "testView.h"
#include <string.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CPoint start,end;
FILE *p,*f;
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
	ON_COMMAND(ID_diff, Ondiff)
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

	int b;
	CFileDialog fdlg(true,NULL,"openfile",NULL,"BMP|*.bmp");
	CString Strfilename;
	f=fopen("time.txt","w");
	if(fdlg.DoModal()==IDOK)
	{
		Strfilename=fdlg.GetPathName();

		//MessageBox(filename);
	}
	testDib.LoadBmp(Strfilename.GetBuffer(0));
	CClientDC dc(this);
    //CDibSection testDib1(testDib);//直接複製影像
	/*//設定大小在複製影像
 	CDibSection testDib1;
	testDib1.Create(640,480,24); 
	testDib1.Copy(testDib);
	*/
	testDib.Draw(dc,0,0,testDib.Width(),testDib.Height());   
	b=testDib.ScanBytes(testDib.Width(),testDib.Depth());
	p=fopen("t.txt","w");
	/*
	fprintf(p,"%d\n",testDib.Width());
    fprintf(p,"%d\n",testDib.Height());
	fprintf(p,"%d\n",testDib.Depth());
	*/
	COLORREF c1=dc.GetPixel(point);
	/*
	fprintf(p,"%d\n",GetRValue(c1));
	fprintf(p,"%d\n",GetGValue(c1));
	fprintf(p,"%d\n",GetBValue(c1));
	*/
	start=point;
	fprintf(p,"%d\t",start.x);
	fprintf(p,"%d\n",start.y);
	CView::OnLButtonDown(nFlags, point);
}

void CTestView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	end=point;
	fprintf(p,"%d\t",end.x);
	fprintf(p,"%d\n",end.y);
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
 	CDibSection testDib1;
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
	fprintf(p,"%d\n",R);
	fprintf(p,"%d\n",G);
	fprintf(p,"%d\n",B);
	fclose(p);
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
 	CDibSection testDib1(testDib);//直接複製影像
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
 	CDibSection testDib1(testDib);//直接複製影像
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
	CDibSection testDib1;
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

void CTestView::Onchangegray() 
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
	CDibSection testDib1;
	ftime(&t);
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
			*q++=(0.299*R+0.587*G+0.114*B);
			*q++=(0.299*R+0.587*G+0.114*B);
			*q++=(0.299*R+0.587*G+0.114*B);
		}
	}

	testDib1.Draw(dc,0,0,testDib.Width(),testDib.Height());	
	ftime(&t1);
	fprintf(f,"起始時間%d(s)\t%d(ms)\n結束時間%d(s)\t%d(ms)\n",t.time,t.millitm,t1.time,t1.millitm);
	fclose(f);
}

void CTestView::Ondiff()//相減_相成
{
	// TODO: Add your command handler code here
	CFileDialog fdlg(true,NULL,"openfile",NULL,"BMP|*.bmp");
	int x,y;
	int R1,G1,B1;
	int R2,G2,B2;
	int R3,G3,B3;
	int R4,G4,B4;
	int R5,G5,B5;
	int Width,Height;
	CDibSection Dib1,Dib2,Dib3,Dib4;
	CString StrFileName1,StrFileName2,StrFileName3;
	if(fdlg.DoModal()==IDOK)
	{
		StrFileName1=fdlg.GetPathName();
		Dib1.LoadBmp(StrFileName1.GetBuffer(0));
	}
	else
	{
		return;
	}
	////////////////////////
	if(fdlg.DoModal()==IDOK)
	{
		StrFileName2=fdlg.GetPathName();
		Dib2.LoadBmp(StrFileName2.GetBuffer(0));
	}
	else
	{
		return;
	}
	////////////////////////
	if(fdlg.DoModal()==IDOK)
	{
		StrFileName3=fdlg.GetPathName();
		Dib3.LoadBmp(StrFileName3.GetBuffer(0));
	}
	else
	{
		return;
	}
	///////////////////
	Width=Dib1.Width();
	Height=Dib1.Height();
	Dib4.Create(Width,Height,24);
	CClientDC dc(this);
	for(x=0;x<Width;x++)
	{
		for(y=0;y<Height;y++)
		{
			BYTE *q1=(BYTE *)Dib1.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q2=(BYTE *)Dib2.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q3=(BYTE *)Dib3.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			BYTE *q4=(BYTE *)Dib4.GetBits(x,y);//利用物件本身所提供之成員函數取得一個像素的 R,G,B(指標用法)
			B1=*q1++;
			G1=*q1++;
			R1=*q1++;
			/////////
			B2=*q2++;
			G2=*q2++;
			R2=*q2++;
			/////////
			B3=*q3++;
			G3=*q3++;
			R3=*q3++;
			/////////
			B4=abs(B1-B2);
			G4=abs(G1-G2);
			R4=abs(R1-R2);
			/////////////////
			B5=abs(B2-B3);
			G5=abs(G2-B3);
			R5=abs(R2-R3);
			/////////////////
			*q4++=B4*B5/255;
			*q4++=G4*G5/255;
			*q4++=R4*R5/255;
		}
	}
	Dib4.Draw(dc,0,0,Dib4.Width(),Dib4.Height());	
}
