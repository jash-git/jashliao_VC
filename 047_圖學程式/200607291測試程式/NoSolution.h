// NoSolution.h: interface for the CNoSolution class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NOSOLUTION_H__7E11B027_EF06_440B_9653_3A67A2B27B1E__INCLUDED_)
#define AFX_NOSOLUTION_H__7E11B027_EF06_440B_9653_3A67A2B27B1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Point3D.h"
#include "InputData.h"
#include "TwoPointCircle.h"
#include "ArcPoint2Circle.h"
#include "Arc.h"
#include "Line.h"
#include "CircleRightLeft.h"
#include <afxtempl.h>
class CNoSolution  
{
public:
	CInputData m_InputData;
	CPoint3D *m_pPoint3DCross;
	CPoint3D m_Point3DRip;
	long m_lngnumber;
	CNoSolution();
	CNoSolution(const CInputData &InputData,const long lngIDNum,const CPoint3D &Point3DRip,const CPoint3D *Point3DCross,const long lngnumber);
	void SetData(const CInputData &InputData,const long lngIDNum,const CPoint3D &Point3DRip,const CPoint3D *Point3DCross,const long lngnumber);
	bool GetAns(CCircle *CC);
	virtual ~CNoSolution();
private:
	CLine m_LineRip;
	CTwoPointCircle m_TPC;
	CArc m_ArcRip;
	CArcPoint2Circle m_APC;
	CCircle m_Circlebuf;
	CCircleRightLeft m_CRL;
	CArray <CCircle,CCircle> gArrayAnsBuf;
	double m_dblRBuf;
	bool m_check;
	long m_lngIDNum;
	void CheckEntity();
protected:
	CCircle m_CircleAns;
	void Calculate();
};

#endif // !defined(AFX_NOSOLUTION_H__7E11B027_EF06_440B_9653_3A67A2B27B1E__INCLUDED_)
