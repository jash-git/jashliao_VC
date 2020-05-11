// CircleRightLeft.h: interface for the CCircleRightLeft class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CIRCLERIGHTLEFT_H__C148B2B5_636E_40BD_81C5_E149DEDDDE87__INCLUDED_)
#define AFX_CIRCLERIGHTLEFT_H__C148B2B5_636E_40BD_81C5_E149DEDDDE87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "InputData.h"
#include "Vector.h"
class CCircleRightLeft  
{
public:
	CCircleRightLeft();
	CInputData m_InputData;
	CCircle m_Circle;
	bool Check();//輸出函數
	void SetData(const CInputData &ID,const CCircle &CC);//初始化函數
	virtual ~CCircleRightLeft();
private:
	long m_CCW;//紀錄方向，0->右；1->左
	long m_Direction;//紀錄順逆，0->順；1->逆
	long m_lngLineArc;//用來儲存型態0->Line；1->Arc
protected:
	bool m_blnAns;//紀錄運算結果
	void calculate();

};

#endif // !defined(AFX_CIRCLERIGHTLEFT_H__C148B2B5_636E_40BD_81C5_E149DEDDDE87__INCLUDED_)
