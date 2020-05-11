#include "Matrix.h"
// MainFactor.h: interface for the MainFactor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFACTOR_H__BF4F7477_0675_4DFE_AA61_B58B2730B2E3__INCLUDED_)
#define AFX_MAINFACTOR_H__BF4F7477_0675_4DFE_AA61_B58B2730B2E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class MainFactor  
{
public:
	MainFactor();
	virtual ~MainFactor();
	CMatrix m_Matrix1;			//原始数据
	CMatrix m_Matrix2;			//标准化样本数据
	CMatrix m_Result1;			//存放主成分的特征根，贡献率和累计贡献率
	int m_mainNum;//记录主成份个数
	CMatrix m_Result2;			//存放主成分系数
	CMatrix m_Result3;			//存放样品的主成分得分值
	CMatrix m_Result4;			//主成分载荷因子
	double m_p;                 //用户给定贡献率
	int m_t;					//主成分分析所用模型，0表示选协方差阵；1表示用相关阵

	CMatrix GetL(CMatrix B);			//计算离差阵
	CMatrix GetStX();	       //样本数据标准化
	CMatrix GetR();			//计算样本相关阵
	CMatrix GetS();         //计算样本协方差阵
	void	Analyze1();		//返回主成分分析的结果
	MainFactor(CMatrix A,double p,int Tag);   //构造函数
	void showMatrix(CMatrix a);
};

#endif // !defined(AFX_MAINFACTOR_H__BF4F7477_0675_4DFE_AA61_B58B2730B2E3__INCLUDED_)
