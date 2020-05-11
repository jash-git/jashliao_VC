// Kalman.cpp: implementation of the CKalman class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MemsGroServer.h"
#include "Kalman.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CKalman::CKalman()
{
	int i,j;
////////////////////////////////////
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			P_1[i][j]=0.0f;
			P_0[i][j]=0.0f;
			R[i][j]=0.0f;
			Q[i][j]=0.0f;
			K[i][j]=0.0f;
			alfa[i][j]=0.0f;
			beta[i][j]=0.0f;
		}
////////////////////////////////////
	for(i=0;i<3;i++)//設定為單位矩陣
		for(j=0;j<3;j++)
		{
			if(i==j)
			{
				H[i][j]=1.0f;
				I[i][j]=1.0f;
			}
			else
			{
				H[i][j]=0.0;
				I[i][j]=0.0f;
			}
		}
///////////////////////////////////
	for(i=0;i<3;i++)
	{
		X_1[i]=0.0f;
		X_0[i]=0.0f;
		y[i]=0.0f;
	}
////////////////////////////////////
	f1=fopen("kalman.txt","w");
}

CKalman::~CKalman()
{

}
void CKalman::Init(float R1[3][3],float Q1[3][3])//初值設定量側和系統的標準偏差值
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			R[i][j]=R1[i][j];
			Q[i][j]=Q1[i][j];
		}
	fprintf(f1,"原始R  :%f\t%f\t%f\t",R[0][0],R[1][1],R[2][2]);
	fprintf(f1,"原始Q  :%f\t%f\t%f\n",Q[0][0],Q[1][1],Q[2][2]);
	fprintf(f1,"原始P_0:%f\t%f\t%f\t",P_0[0][0],P_0[1][1],P_0[2][2]);
	fprintf(f1,"原始P_1:%f\t%f\t%f\n",P_1[0][0],P_1[1][1],P_1[2][2]);
	fprintf(f1,"原始K  :%f\t%f\t%f\n",K[0][0],K[1][1],K[2][2]);
	fprintf(f1,"*****************************************************\n");
}
void CKalman::comput(float *X,float *Z1,float alfa1[3][3],float beta1[3][3])//Kalman filter kernel
{
	int i,j,k;
	float buffer[3][3];
	float buffer1[3];
	float buffer2[3];
	float buffer3[3][3];
	////////////////////////////////暫存器青空
	for(i=0;i<3;i++)
	{
		buffer1[i]=0.0f;
		buffer2[i]=0.0f;
		for(j=0;j<3;j++)
		{
			alfa[i][j]=alfa1[i][j];
			beta[i][j]=beta1[i][j];
			buffer[i][j]=0.0f;
			buffer3[i][j]=0.0f;
			K[i][j]=0.0f;
		}
	}
	////////////////////////////////P(k|k-1)=I*P(k|k)*I+(Q*(I+beta))------1_start
	/////Q(I+beta)
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			if(i==j)
				Q[i][j]*=(I[i][j]+beta[i][j]);
		}
	/////
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			P_0[i][j]=P_1[i][j]+Q[i][j];
		}
	///////////////////////////////////////------1_end
	///////////////////////////////////////K=P(k|k-1)H^t[H*P(k|k-1)*H^t+(R/(I+alfa))]------2_start
	for(i=0;i<3;i++)//---[R/(I+alfa)]
		for(j=0;j<3;j++)
		{
			if(i==j)
				R[i][j]/=(I[i][j]+alfa[i][j]);
		}
	/////
	for(i=0;i<3;i++)//[(H*P(k|k-1)*H^t)+R]
		for(j=0;j<3;j++)
		{
			buffer[i][j]=P_0[i][j]+R[i][j];
		}
	/////
	for(i=0;i<3;i++)//K=P(k|k-1)*buffer
		for(j=0;j<3;j++)
			for(k=0;k<3;k++)
				K[i][j]+=P_0[i][k]*buffer[k][j];
	/////////////////////////////////////////////////////////------2_end
	/////////////////////////////X(k|k)=X(k|k-1)+K[Z-H*X(k|k-1)]------3_start
	///////[Z-H*X(k|k-1)]
	for(i=0;i<3;i++)
	{
		X_0[i]=*(X+i);//抓取系統模型狀態X(k|k-1)
		Z[i]=*(Z1+i);//抓取量測值Z(k)
		buffer1[i]=Z[i]-X_0[i];//[Z-H*X(k|k-1)]
	}
	////////K[Z-H*X(k|k-1)]
	buffer2[0]=((K[0][0]*buffer1[0])+(K[0][1]*buffer1[1])+(K[0][2]*buffer1[2]));
	buffer2[1]=((K[1][0]*buffer1[0])+(K[1][1]*buffer1[1])+(K[1][2]*buffer1[2]));
	buffer2[2]=((K[2][0]*buffer1[0])+(K[2][1]*buffer1[1])+(K[2][2]*buffer1[2]));
	for(i=0;i<3;i++)
	{
		X_1[i]=X_0[i]+buffer2[i];
	}
	//////////////////////////////////------3_end
	////////////////////////////P(k|k)=[I-KH]*P(k|k-1)------4_start
	for(i=0;i<3;i++)//[I-KH]
		for(j=0;j<3;j++)
		{
			buffer3[i][j]=I[i][j]-K[i][j];
			P_1[i][j]=0.0f;//由於下面的矩陣相乘,所以要先清空
		}
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			for(k=0;k<3;k++)
				P_1[i][j]+=buffer3[i][k]*P_0[k][j];
	/////////////////////////////////////------4_end
	fprintf(f1,"目前alfa:%f\t%f\t%f\t",alfa[0][0],alfa[1][1],alfa[2][2]);
	fprintf(f1,"目前beta:%f\t%f\t%f\n",beta[0][0],beta[1][1],beta[2][2]);
	fprintf(f1,"目前R   :%f\t%f\t%f\t",R[0][0],R[1][1],R[2][2]);
	fprintf(f1,"目前Q   :%f\t%f\t%f\n",Q[0][0],Q[1][1],Q[2][2]);
	fprintf(f1,"目前P_0 :%f\t%f\t%f\t",P_0[0][0],P_0[1][1],P_0[2][2]);
	fprintf(f1,"目前P_1 :%f\t%f\t%f\n",P_1[0][0],P_1[1][1],P_1[2][2]);
	fprintf(f1,"目前K   :%f\t%f\t%f\n",K[0][0],K[1][1],K[2][2]);
	fprintf(f1,"///////////////////////////////////////////////////////\n");

}
void CKalman::Output()
{
	for(int i=0;i<3;i++)
	{
		y[i]=X_1[i];

	}
}