// CVolumControl.h: interface for the CVolumControl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined _CVolumControl_H
#define  _CVolumControl_H

#if _MSC_VER > 1000
#pragma once
#endif 

class CVolumControl  
{
protected:
	CWnd *m_pWnd;
	LONG m_min;
	LONG m_max;
	HMIXER m_hMixer;
public:
	CString m_strName;
	DWORD m_ControlNum;
	DWORD m_ControlID;

public:
	void SetValue(DWORD  vl ,DWORD vr);
	DWORD GetValue(DWORD *vl,DWORD *vr);
	DWORD GetMin();
	DWORD GetMax();

	void Close();
	void Create(CWnd *m_ControlID,DWORD type1,DWORD type2,DWORD type3);

	CVolumControl();
	virtual ~CVolumControl();
};

#endif 
