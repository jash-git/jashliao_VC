// Kalman.h: interface for the CKalman class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_KALMAN_H__779AA3D6_6C7B_4D44_9D34_80AF61BDCC8B__INCLUDED_)
#define AFX_KALMAN_H__779AA3D6_6C7B_4D44_9D34_80AF61BDCC8B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <stdio.h>
class CKalman  
{
public:
	void Init(float R1[3][3],float Q1[3][3],bool bGroError1);
	void comput(float *X,float *Z1,float alfa1[3][3],float beta1[3][3]);//Kalman filter kernel
	void Output();//y[3]set
	float y[3];//最佳估測之狀態的輸出
	bool bGroError;
	CKalman();
	virtual ~CKalman();
private:
	FILE *f1;
	float X_1[3],X_0[3];//X_0=X(k|k-1),X_1=X(k|k)
	float P_1[3][3],P_0[3][3];//P_0=P(k|k-1),P_1=P(k|k)
	float R[3][3],alfa[3][3];
	float Q[3][3],beta[3][3];
	float H[3][3];//y=HX
	float I[3][3];//E^At
	float K[3][3];//kalman Gain
	float Z[3];//量測結果
};

#endif // !defined(AFX_KALMAN_H__779AA3D6_6C7B_4D44_9D34_80AF61BDCC8B__INCLUDED_)
