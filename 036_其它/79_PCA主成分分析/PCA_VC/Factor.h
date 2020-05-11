#include "Matrix.h"
// Factor.h: interface for the Factor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACTOR_H__C5426C88_4CD6_46BF_B320_0CE445B18713__INCLUDED_)
#define AFX_FACTOR_H__C5426C88_4CD6_46BF_B320_0CE445B18713__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Factor  
{
public:
	Factor();
	Factor(CMatrix mx, double dep_m);
	////////////////////////////
	CMatrix X;//原数据，最后为标准化后的数据
	double dep_m;//贡献率
	int n;//记录元数据行数
	int p;//记录元数据列数
	double *h2,*a2;///确定个数h2记录了输出A后的下一列
	double m_ColsOfA;//记录最终输出A的前多少行
    CMatrix R;//相关矩阵P*P
	CMatrix te_R;//特征值和特征矩阵
	CMatrix A;//因子载荷阵p*p
	CMatrix B;//正交旋转后的主因子载荷阵p*m
	CMatrix F;//因子得分m_ColsOfA*p
	///////////////////////////
	
	void Run(void);
	virtual ~Factor();

};

#endif // !defined(AFX_FACTOR_H__C5426C88_4CD6_46BF_B320_0CE445B18713__INCLUDED_)
