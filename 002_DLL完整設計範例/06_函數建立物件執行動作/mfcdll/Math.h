// Math.h: interface for the CMath class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATH_H__69C9B5CB_28EF_4E6D_8E31_8AF8D9FEA2C3__INCLUDED_)
#define AFX_MATH_H__69C9B5CB_28EF_4E6D_8E31_8AF8D9FEA2C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMath  
{
private:
	double m_dblData1,m_dblData2;
public:
	double m_dblData3;
	CMath();
	void add(double a,double b);
	virtual ~CMath();


};

#endif // !defined(AFX_MATH_H__69C9B5CB_28EF_4E6D_8E31_8AF8D9FEA2C3__INCLUDED_)
