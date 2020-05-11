// MainFactor.cpp: implementation of the MainFactor class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ProGram2.h"
#include "MainFactor.h"
#include "math.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MainFactor::MainFactor()
{

}

MainFactor::~MainFactor()
{

}
MainFactor::MainFactor(CMatrix A,double p,int Tag)
{
	m_Matrix1=A;
	m_p=p;
	m_t=Tag;
}

CMatrix MainFactor::GetL(CMatrix B)        
{
	CMatrix MatrixX(B);
	CMatrix MatrixL(B);
	int m=MatrixX.GetNumRows();
	int n=MatrixX.GetNumCols();
	for(int i=0;i<m;i++)
	{	
		double p=0.0;
		for(int j=0;j<n;j++)
		{
			p=p+MatrixX.GetElement(i,j);
		}
		for(int k=0;k<n;k++)
		{   
			MatrixX.SetElement(i,k,MatrixX.GetElement(i,k)-p/n);
		}
	}
MatrixL=MatrixX*MatrixX.Transpose();
return MatrixL;
}

CMatrix MainFactor::GetStX()
{
	CMatrix MatrixX(m_Matrix1);
	CMatrix MatrixL=GetL(m_Matrix1);
	int m=MatrixX.GetNumRows();
	int n=MatrixX.GetNumCols();
	for(int i=0;i<m;i++)
	{	
		double p=0.0;
		for(int j=0;j<n;j++)
		{
			p=p+MatrixX.GetElement(i,j);
		}
		for(int k=0;k<n;k++)
		{   
			MatrixX.SetElement(i,k,(MatrixX.GetElement(i,k)-p/n)/sqrt(MatrixL.GetElement(i,i)/(n-1)));
		}
	}
return MatrixX;
}
CMatrix MainFactor::GetS()
{
	CMatrix MatrixL=GetL(m_Matrix1);
	int n=m_Matrix1.GetNumCols();
	CMatrix MatrixS;
	MatrixS=MatrixL*((double) 1/(n-1));
	return MatrixS;
}
CMatrix MainFactor::GetR()
{
	CMatrix MatrixX=GetStX();
	CMatrix MatrixL=GetL(MatrixX);
	int n=MatrixL.GetNumCols();
	CMatrix MatrixR;
	MatrixR.Init(n,n);
	for(int i=0;i<n;i++)
	{
		double k1=MatrixL.GetElement(i,i);
		for(int j=0;j<n;j++)
		{
			double k2=MatrixL.GetElement(j,j);
			MatrixR.SetElement(i,j,MatrixL.GetElement(i,j)/sqrt(k1*k2));	
		}
	}
	return MatrixR;
}

void MainFactor::Analyze1()
{
	CMatrix MatrixF;	//分析所用的矩阵（协方差阵或相关阵）
//	CMatrix MatrixT;		
	if (m_t==0)
	{
		MatrixF=GetS();
		m_Matrix2=m_Matrix1;
	//	show(m_Matrix2);
	//	show(MatrixF);
		
	}
	else
	{
		m_Matrix2=GetStX();
		MatrixF=GetR();
		//show(MatrixF);
	}
	CMatrix MatrixT(MatrixF.Eigenv());
	CMatrix m_Result11(3,MatrixT.GetNumCols());
	double k=0;	
	double tr=0;
	int j=0;
	int d=1;
	
	for(int h=0;h<MatrixT.GetNumCols();h++)
	{
		tr=tr+MatrixT.GetElement(0,h);
	}
	
	while (k<m_p)
	{
		k=k+MatrixT.GetElement(0,j)/tr;//计算主成分的累计方差贡献率
		m_Result11.SetElement(0,j,MatrixT.GetElement(0,j));
		m_Result11.SetElement(1,j,MatrixT.GetElement(0,j)/tr);
		m_Result11.SetElement(2,j,k);
		j=j+1;	
	}
	m_mainNum=j;
	m_Result1.Init(3,3);
	m_Result1.Init(3,j);
	CMatrix MatrixU(j,j);
	m_Result2.Init(MatrixT.GetNumCols(),j);
	m_Result3.Init(m_Matrix2.GetNumCols(),MatrixT.GetNumCols());
	m_Result4.Init(MatrixT.GetNumCols(),j);
	for(int i=0;i<j;i++)
	{	
		for(int q=0;q<3;q++)
		{
			m_Result1.SetElement(q,i,m_Result11.GetElement(q,i));       // 主成分的特征根、贡献率和累计贡献率
		}
		for(int r=0;r<m_Result2.GetNumRows();r++)
		{
			m_Result2.SetElement(r,i,MatrixT.GetElement(r+1,i));
		}
		MatrixU.SetElement(i,i,sqrt(MatrixT.GetElement(0,i)));
	}
m_Result3=m_Matrix2.Transpose()*m_Result2;	
m_Result4=m_Result2*MatrixU;	                       
}
void MainFactor::showMatrix(CMatrix a)
{
	if(a.GetNumCols==0)
		return;
	CString s,c;
	for(int i=0;i<a.GetNumRows();i++)
	{
		s="";
		for(int j=0;j<a.GetNumCols();j++)
		{
			c.Format("    %f",(double)a.GetElement(i,j));
			s=s+c;
		}
		AfxMessageBox(s);
	}
}