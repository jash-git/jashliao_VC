#include "Matrix.h"

// QR_analysis.h: interface for the QR_analysis class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QR_ANALYSIS_H__5DF9147D_9C96_4355_9FD5_42C7E95AD2D4__INCLUDED_)
#define AFX_QR_ANALYSIS_H__5DF9147D_9C96_4355_9FD5_42C7E95AD2D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class QR_analysis  
{
public:
	QR_analysis();
	virtual ~QR_analysis();
	CMatrix result1;//各主样本的主成分得分值n*2(x-Y)
	CMatrix result2;//样本的因子载荷阵n*2-R
	CMatrix result3;//
	CMatrix result4;//样本的因子载荷阵n*2-Q
	void run(CMatrix CMatriA);
	void plot(CMatrix CMatriB,CMatrix CMatriC);
};

#endif // !defined(AFX_QR_ANALYSIS_H__5DF9147D_9C96_4355_9FD5_42C7E95AD2D4__INCLUDED_)
