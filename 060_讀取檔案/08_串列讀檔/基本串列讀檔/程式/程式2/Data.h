// Data.h: interface for the CData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATA_H__8D2000AE_2C0E_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_DATA_H__8D2000AE_2C0E_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CData : public CObject//2-step  
{
public:
	CString strData;//3-step
	CData();
	virtual ~CData();
	virtual void Serialize(CArchive& ar);
	CData(CData & g)	//½Æ»s«Øºc¤l6-step
		: strData(g.strData) {}
	CData & operator= (CData & g){//7-step
		strData = g.strData;
		return *this;
	}
DECLARE_SERIAL(CData)
};

#endif // !defined(AFX_DATA_H__8D2000AE_2C0E_11DA_B776_0040F43A9B72__INCLUDED_)
