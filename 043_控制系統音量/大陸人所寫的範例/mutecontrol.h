#if !defined AFX_CMuteControl_H
#define  AFX_CMuteControl_H

#if _MSC_VER > 1000
#pragma once
#endif

#include "mmsystem.h"

class CMuteControl  
{
public:
	void Close();
	DWORD GetValue();
	void SetValue(DWORD value);
	void Create(CWnd *pWnd,DWORD type,DWORD type1);
	CMuteControl();
	virtual ~CMuteControl();
	DWORD m_controlid;

protected:
	HMIXER m_hMixer;
	CWnd *m_pWnd;
	MIXERCAPS m_mxcaps;
};

#endif 
