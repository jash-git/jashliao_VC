// QR_analysis.cpp: implementation of the QR_analysis class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ProGram2.h"
#include "QR_analysis.h"
#include "math.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

QR_analysis::QR_analysis()
{

}

QR_analysis::~QR_analysis()
{

}
void QR_analysis::run(CMatrix q)
{
	int m,n,i,j;
	n=q.GetNumRows();
	m=q.GetNumCols();
	double T,*row,*col,z;
	row= new double[n];
	col= new double[m];
	T=0;
	for(i=0;i<n;i++)
	{
		row[i]=0;
		for(j=0;j<m;j++)
		{
			row[i]=row[i]+q.GetElement(i,j);
			T=T+q.GetElement(i,j);
		}
	}

	for(j=0;j<m;j++)
	{	col[j]=0;
		for(i=0;i<n;i++)
		{
			col[j]=col[j]+q.GetElement(i,j);
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			z=(q.GetElement(i,j)-row[i]*col[j]/T)/(sqrt(row[i]*col[j]));
			q.SetElement(i,j,z);
		}
	}

	delete[]row;
	delete[]col;
////////////////////////////////////////////////////////////////////////////////	
	CMatrix Z=q;
	//R_analysis
	//协方差A
	CMatrix A;
	A=Z*Z.Transpose();
	double *pt;
//	int m,n,i,j;
	n=Z.GetNumRows();
	m=Z.GetNumCols();
	pt=new double[n];
	//cout<<"/n特征值和特征向量"<<endl;
	//特征值和特征向量
	//show(A.Eigenv());
	//特征值开方后的对角阵
	CMatrix N(n);
	N.Init(n,n);

	for(i=0;i<n;i++)
	{
		N.SetElement(i,i,sqrt(A.Eigenv().GetElement(0,i)));
	}

	//选择贡献率最大的两个的特征向量和因子载荷阵
	CMatrix U(n,2);
	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
		{
			U.SetElement(i,j,A.Eigenv().GetElement(i+1,j));
		}
	}

	//cout<<"\n R因子载荷阵"<<endl;
	CMatrix Ar(n,2);
	for(j=0;j<2;j++)
	{
		for(i=0;i<n;i++)
		{
			Ar.SetElement(i,j,U.GetElement(i,j)*N.GetElement(j,j));
		}
	}

	//show(Ar);
	result2=Ar;
	//各样品第一第二主成分值
	//cout<<"\n各样品的主成分值"<<endl;
	CMatrix RS;
	RS=Z.Transpose()*U;
	//show(RS);
	result1=RS;
	//Q_analysis
	//cout<<"\n Q_analysis"<<endl;
	//对应前面的两个特征值的在Q中的特征向量和因子载荷阵
	CMatrix V(m);
	V=Z.Transpose()*U;
	//show(V);
	//cout<<"\n Q因子载荷阵"<<endl;
	CMatrix Aq(m,2);

	for(j=0;j<2;j++)
	{
		for(i=0;i<m;i++)
		{
			Aq.SetElement(i,j,V.GetElement(i,j)*N.GetElement(j,j));
		}
	}

	//show(Aq);
	result4=Aq;
	////各变量第一第二主成分值
	//cout<<"\n各变量的主成分值"<<endl;
	CMatrix QS;
	QS=Z*V;
	//show(QS);
	
	result3=QS;

	//画图
	//cout<<"\n选取第一和第二主成分的分值为x,y轴，划出图"<<endl;
}

void QR_analysis::plot(CMatrix CMatriB,CMatrix CMatriC)
{/*

	LRESULT CALLBACK WinSunProc(
	  HWND hwnd,      // handle to window
	  UINT uMsg,      // message identifier
	  WPARAM wParam,  // first message parameter
	  LPARAM lParam   // second message parameter
	);


	int WINAPI WinMain(
	  HINSTANCE hInstance,      // handle to current instance
	  HINSTANCE hPrevInstance,  // handle to previous instance
	  LPSTR lpCmdLine,          // command line
	  int nCmdShow              // show state
	)
	{
		WNDCLASS wndcls;
		wndcls.cbClsExtra=0;
		wndcls.cbWndExtra=0;
		wndcls.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
		wndcls.hCursor=LoadCursor(NULL,IDC_ARROW);
		wndcls.hIcon=LoadIcon(NULL,IDI_INFORMATION);
		wndcls.hInstance=hInstance;
		wndcls.lpfnWndProc=WinSunProc;
		wndcls.lpszClassName="R_Qanalysis";
		wndcls.lpszMenuName=NULL;
		wndcls.style=CS_HREDRAW | CS_VREDRAW;
		RegisterClass(&wndcls);

		HWND hwnd;
		hwnd=CreateWindow("R_Qanalysis","R-Q对应分析",WS_OVERLAPPEDWINDOW,
			250,100,800,600,NULL,NULL,hInstance,NULL);

		ShowWindow(hwnd,SW_SHOWNORMAL);
		UpdateWindow(hwnd);

		MSG msg;
		while(GetMessage(&msg,NULL,0,0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		return 0;
		
	}

	LRESULT CALLBACK WinSunProc(
	  HWND hwnd,      // handle to window
	  UINT uMsg,      // message identifier
	  WPARAM wParam,  // first message parameter
	  LPARAM lParam   // second message parameter
	)
	{
		switch(uMsg)
		{
		case WM_CHAR:
			//		char szChar[20];
			//		sprintf(szChar,"char is %d",wParam);
			//		MessageBox(hwnd,szChar,"weixin",0);
			break;
		case WM_LBUTTONDOWN:
			//		MessageBox(hwnd,"mouse clicked","R_Qanalysis",0);
			//		HDC hdc;
			//		hdc=GetDC(hwnd);
			//		TextOut(hdc,0,50,"计算机编程语言培训",strlen("计算机编程语言培训"));
			//		ReleaseDC(hwnd,hdc);
			break;




		case WM_PAINT:
			{
				HDC hDC;
				PAINTSTRUCT ps;
				hDC=BeginPaint(hwnd,&ps);
				//CRect rectClient;
				//GetClientRect(hDC,&rectClient);		
			
				double value1[12]={0.2368,0.2471,0.2568,1.2671,1.1161,0.1254,0.1397,0.149,0.1582,1.1675,0.1768,0.1871};
				CMatrix MatrixA(6,2,value1);
				double value2[6]={0.234,0.2342,0.3534,1.2323,0.2432,1.323};
				CMatrix MatrixB(3,2,value2);



				int n,m,i,j;
				n=MatrixA.GetNumRows();
				m=MatrixB.GetNumRows();
				//////////数据矩阵
				for(i=0;i<n;i++)
				{
					CString str1,str2;
					str1.Format("%f",MatrixA.GetElement(i,0));
					TextOut(hDC,50,20*i,str1,strlen(str1));
					str2.Format("%f",MatrixA.GetElement(i,1));
					TextOut(hDC,150,20*i,str2,strlen(str2));
				}

				for(i=0;i<m;i++)
				{
					CString str1,str2;
					str1.Format("%f",MatrixB.GetElement(i,0));
					TextOut(hDC,250,20*i,str1,strlen(str1));
					str2.Format("%f",MatrixB.GetElement(i,1));
					TextOut(hDC,350,20*i,str2,strlen(str2));
				}
			
				const double xOrg=150,yOrg=400;
				const double xMax=650,yMin=100;
				///////////实际数据的x,y最大值最小值		
				double dbXMax=MatrixA.GetElement(0,0),dbXMin=MatrixA.GetElement(0,0);
				double dbYMax=MatrixA.GetElement(0,1),dbYMin=MatrixA.GetElement(0,1);
				for(i=0;i<n-1;i++)
				{
					dbXMax=dbXMax>MatrixA.GetElement(i+1,0)?dbXMax:MatrixA.GetElement(i+1,0);
					dbXMin=MatrixA.GetElement(i+1,0)>dbXMin?dbXMin:MatrixA.GetElement(i+1,0);
					dbYMax=dbYMax>MatrixA.GetElement(i+1,1)?dbYMax:MatrixA.GetElement(i+1,1);
					dbYMin=dbYMin<MatrixA.GetElement(i+1,1)?dbYMin:MatrixA.GetElement(i+1,1);					
				}

				for(i=0;i<m;i++)
				{
					dbXMax=dbXMax>MatrixB.GetElement(i,0)?dbXMax:MatrixB.GetElement(i,0);
					dbXMin=MatrixB.GetElement(i,0)>dbXMin?dbXMin:MatrixB.GetElement(i,0);
					dbYMax=dbYMax>MatrixB.GetElement(i,1)?dbYMax:MatrixB.GetElement(i,1);
					dbYMin=dbYMin<MatrixB.GetElement(i,1)?dbYMin:MatrixB.GetElement(i,1);					
				}
			
				////////////换算比例	
				double dbXRatio=(xMax-xOrg)/(dbXMax-dbXMin);
				double dbYRatio=(yOrg-yMin)/(dbYMax-dbYMin);

			
				//	CString str;
				//	str.Format("%f",dbYMin);
				//	TextOut(hDC,400,500,str,strlen(str));
			
				////////////填色
				CPen penNewPen(PS_SOLID,1,RGB(0,0,255));
				CPen *ppenOldPen=(CPen *)SelectObject(hDC,&penNewPen);
				CBrush brushNewBrush(RGB(0,0,255));
				CBrush *pbrushOldBrush=(CBrush *)SelectObject(hDC,brushNewBrush);

				////////////画点
				double x,y;
				for(i=0;i<n;i++)
				{
					x=dbXRatio*(MatrixA.GetElement(i,0)-dbXMin)+xOrg;
					y=yOrg-dbYRatio*(MatrixA.GetElement(i,1)-dbYMin);
					Ellipse(hDC,x-3,y-3,x+3,y+3);
					CString str;
					str.Format("%d",i+1);
					TextOut(hDC,x+6,y,str,strlen(str));

				}

				for(i=0;i<m;i++)
				{
					x=dbXRatio*(MatrixB.GetElement(i,0)-dbXMin)+xOrg;
					y=yOrg-dbYRatio*(MatrixB.GetElement(i,1)-dbYMin);
					Rectangle(hDC,x-3,y-3,x+3,y+3);
					CString str;
					str.Format("%d",i+1);
					TextOut(hDC,x+6,y,str,strlen(str));

				}
			
				///////////画轴		
				double ox,oy;
				ox=dbXRatio*(0-dbXMin)+xOrg;
				oy=yOrg-dbYRatio*(0-dbYMin);
				Ellipse(hDC,ox-5,oy-5,ox+5,oy+5);
				MoveToEx(hDC,20,oy,0);
				LineTo(hDC,750,oy);
				LineTo(hDC,730,oy-10);
				MoveToEx(hDC,750,oy,0);
				LineTo(hDC,730,oy+10);
				MoveToEx(hDC,ox,530,0);
				LineTo(hDC,ox,30);
				LineTo(hDC,ox+10,50);
				MoveToEx(hDC,ox,30,0);
				LineTo(hDC,ox-10,50);
				CString str;
				str="(0,0)";
				TextOut(hDC,ox+5,oy+5,str,strlen(str));

				EndPaint(hwnd,&ps);
				break;
			}
		case WM_CLOSE:
			if(IDYES==MessageBox(hwnd,"是否真的结束？","weixin",MB_YESNO))
			{
				DestroyWindow(hwnd);
			}
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd,uMsg,wParam,lParam);
		}
		return 0;
	}*/

}