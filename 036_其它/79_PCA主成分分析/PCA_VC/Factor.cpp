// Factor.cpp: implementation of the Factor class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ProGram2.h"
#include "Factor.h"
#include "Matrix.h"
#include "math.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Factor::Factor()
{

}

Factor::~Factor()
{

}
Factor::Factor(CMatrix mx, double dep_m)
{
	X=mx;
	this->dep_m=dep_m;
	n=X.GetNumRows();
	p=X.GetNumCols();
	h2=new double[p];
	a2=new double[p];
	CMatrix A1(p,p);
	A=A1;
//	delete A1;
	R.MakeUnitMatrix(p);
//	AfxMessageBox("接收数据完成");

}
void Factor::Run(void)
{
	int i,j,k,h;
	double *avex1,*avex2,sum;
	avex1=new double[n];
	avex2=new double[p];

	sum=0;
	for(i=0;i<n;i++)
	{	sum=0;
		for (j=0;j<p;j++)
		{
			sum=sum+X.GetElement(i,j);
		}
		avex1[i]=sum/p;
	}
	//求列均值
	for( i=0;i<p;i++)
	{	sum=0;
		for (j=0;j<n;j++)
		{
			sum=sum+X.GetElement(j,i);
		}
		avex2[i]=sum/n;
	}
	//求离差阵
	CMatrix E(p,p);
	for( i=0;i<p;i++)
	{	
		for (j=0;j<p;j++)
		{   
			sum=0;
			for(k=0;k<n;k++) 
			{	
				sum=sum+(X.GetElement(k,i)-avex1[i])*(X.GetElement(k,j)-avex2[j]);
			}
			E.SetElement(i,j,sum/(n-1));
		}
	}

	for( i=0;i<n;i++)
	{	
		for (j=0;j<p;j++)
		{   
			X.SetElement(i,j,(X.GetElement(i,j)-avex2[j])/sqrt(E.GetElement(j,j)/(n-1)));//数据标准化
		}
	}

//	CMatrix R(p,p);
	for( i=0;i<p;i++)
	{	
		for (j=0;j<p;j++)
		{	
			R.SetElement(i,j,E.GetElement(i,j)/sqrt(E.GetElement(i,i)*E.GetElement(j,j)));
		}
	}

	//cout<<"\n 2\n";
	////这里可能需要输出相关矩阵；

	///////////////////////////（三）求解相关矩阵R的特征值和特征向量////////////////////
//	CMatrix te_R;
	te_R=R.Eigenv();
	double temp;
/*	for(i=0;i<p;i++)
	{	temp=-te_R.GetElement(i,p);
		//cout<<te_R.GetElement(i,p)<<endl;
		te_R.SetElement(i,p,temp);//先改正过来，看看后面的结果对不对????????????????

	}*/
	//show(te_R);//特征值是正确的,第san个特征向量符号反了。。。。。

	//////////////////////////（四）计算特征值的百分率和累积百分率//////////////////////
	double lamda[20],Eve_lamda[20],Acu_lamda[20];
	for( i=0;i<p;i++)
	{
		lamda[i]=te_R.GetElement(0,i);//特征值保存在该一维数组中
		//cout<<lamda[i]<<endl;
	}
	//cout<<All_lamda<<endl;
	for( i=0;i<p;i++)
	{
		Eve_lamda[i]=lamda[i]/p;//特征值的百分率
	}
	Acu_lamda[0]=Eve_lamda[0];
	for( i=1;i<p;i++)
	{
		Acu_lamda[i]=Acu_lamda[i-1]+Eve_lamda[i];//特征值的累积百分率
	}
	

	/////////////////////////（五）确定主因子数/////////////////////
//	cout<<"请选择累积百分率确定主因子数m"<<endl;
//	double dep_m;
//	cin>>dep_m;
	int m=0;
	for( i=0;i<p;i++)
	{
		if(Acu_lamda[i]>=dep_m)
		{
			m=i+1;
			break;
		}
	}
	m_ColsOfA=m;
//	cout<<m<<endl;
	////////////////////////（六）对特征向量矩阵进行规格化处理，得因子载荷A/////////////
//	CMatrix A(p,p);
	for( i=0;i<p;i++)
	{	
		for (j=0;j<p;j++)
		{	
			if(lamda[j]<=0)//??????????????????????
			{
				lamda[j]=0;
			}
			//cout<<te_R.GetElement(j+1,i)<<endl;
			A.SetElement(j,i,te_R.GetElement(j+1,i)*sqrt(lamda[i]));//lamda[i];////每一行是一个主因子的载荷
		}
	}

	//show(A);///所有因子的载荷
	///////////////////////////（七）计算共同度和特殊方差////////////////////

	h2=new double[p];
	a2=new double[p];///确定个数
	//h2[0]=0;
	for( i=0;i<p;i++)
	{	h2[i]=0;
		for (j=0;j<m;j++)
		{	
			h2[i]=h2[i]+A.GetElement(i,j)*A.GetElement(i,j);
			a2[i]=1-h2[i];
		}
		h2[i]=sqrt(h2[i]);
		
	}

	///////////////////////////（八）方差正交旋转///////////////////////////
            
	double a,b,c,d,u,v,tan_sifaijiao_ij,t1,t2,V,V1,V2;//,temp;
	CMatrix T;
	CMatrix B1(p,m);//主因子载荷阵
	B=B1;
	for(i=0;i<p;i++)
	{
		for(j=0;j<m;j++)
		{
			B.SetElement(i,j,A.GetElement(i,j));
		}
	}
	//show(B);
	temp=0;
	V=0;
	for(h=0;h<m;h++)
	{	
		V1=0;	
		V2=0; 
		for(k=0;k<p;k++)
		{
			V1=V1+3*(B.GetElement(k,h)/h2[h])*(B.GetElement(k,h)/h2[h])*(B.GetElement(k,h)/h2[k])*(B.GetElement(k,h)/h2[h]);
			V2=V2+(B.GetElement(k,h)/h2[h])*(B.GetElement(k,h)/h2[h]);	
		}
		V=V+((double) 1/(p*p))*(V1-V2*V2);
	}
	//cout<<V<<"**************"<<endl;	
	while (fabs(V-temp)>=0.0001)
	{		
		for(i=0;i<m;i++)
		{
			for(j=i+1;j<m;j++)
			{	
				a=0;
				b=0;
				c=0;
				d=0;
				t1=0;
				t2=0;
				for(k=0;k<p;k++)
				{
					u=0;
					v=0;
					u=(B.GetElement(k,i)/h2[k])*(B.GetElement(k,i)/h2[k])-(B.GetElement(k,j)/h2[k])*(B.GetElement(k,j)/h2[k]);
					v=2*(B.GetElement(k,i)/h2[k])*(B.GetElement(k,j)/h2[k]);
					//cout<<v<<"$$$";
					a=a+u;
					b=b+v;
					c=c+(u*u-v*v);
					d=d+2*u*v;
				}
				//cout<<a<<"****"<<b<<"****"<<c<<"****"<<d<<endl;
				tan_sifaijiao_ij=(d-2*a*b/p)/(c-(a*a-b*b)/p);///1、计算旋转角////////
				t1=sin(atan(tan_sifaijiao_ij)/4);
				t2=cos(atan(tan_sifaijiao_ij)/4);
				//cout<<t2<<endl;//<<"%%%%%%%%"<<endl;
				T.MakeUnitMatrix(m);///2、生成一系列旋转矩阵////
				T.SetElement(i,i,t2);
				T.SetElement(i,j,-t1);
				T.SetElement(j,i,t1);
				T.SetElement(j,j,t2);
				//show(T);
				B=B*T;
				//show(B);
			}
		}

		temp=V;
		V=0;
		for(h=0;h<m;h++)
		{	
			V1=0;
			V2=0; 
			for(k=0;k<p;k++)
			{
				V1=V1+3*(B.GetElement(k,h)/h2[h])*(B.GetElement(k,h)/h2[h])*(B.GetElement(k,h)/h2[k])*(B.GetElement(k,h)/h2[h]);
				V2=V2+(B.GetElement(k,h)/h2[h])*(B.GetElement(k,h)/h2[h]);	
			}
			V=V+((double) 1/(p*p))*(V1-V2*V2);
		}  
//	cout<<fabs(V-temp)<<endl;
	}
//	show(B);//4.最后输出旋转后的主因子载荷////


					  //////////////////////////（十）进行斜旋转/////////////////////////

						 //原理还没搞清楚，进一步研究中。。。。。。

					  //////////////////////////////////////////////////////////////////
			//////////////////////////（十一）计算因子得分//////////////////////////////
//	CMatrix F;

	F=B.Transpose()*R.Invert()*X.Transpose();//

}