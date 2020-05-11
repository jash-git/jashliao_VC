// CVolumControl.cpp: implementation of the CVolumControl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VolumControl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CVolumControl::CVolumControl()
{
	m_max=0;
	m_min=0;
}

CVolumControl::~CVolumControl()
{}

void CVolumControl::Create(CWnd *pWnd,DWORD type1,DWORD type2,DWORD type3)
{
	m_pWnd=pWnd;
	m_hMixer = NULL;
	MIXERCAPS m_mxcaps;
	::ZeroMemory(&m_mxcaps, sizeof(MIXERCAPS));
	if (::mixerGetNumDevs() != 0)
	{
		if (::mixerOpen(&m_hMixer,0,(DWORD)m_pWnd->m_hWnd,NULL,MIXER_OBJECTF_MIXER | CALLBACK_WINDOW)
			!= MMSYSERR_NOERROR)
			return ;
		if (::mixerGetDevCaps((UINT)m_hMixer, &m_mxcaps, sizeof(MIXERCAPS))
			!= MMSYSERR_NOERROR)
			return ;
	}
	if (m_hMixer == NULL)	
		return ;

	MIXERLINE mxl;
	MIXERCONTROL mxc;
	MIXERLINECONTROLS mxlc;
	mxl.cbStruct = sizeof(MIXERLINE);
	mxl.dwComponentType = type1;
	if (::mixerGetLineInfo((HMIXEROBJ)m_hMixer,&mxl,MIXER_OBJECTF_HMIXER |MIXER_GETLINEINFOF_COMPONENTTYPE)!= MMSYSERR_NOERROR)	
		return ;

	if(type2!=-1)
	{
		DWORD num=mxl.cConnections;
		DWORD type=mxl.dwDestination; 
		for( DWORD i=0;i<num;i++)
		{
			mxl.cbStruct      = sizeof(mxl);
			mxl.dwDestination = type;
			mxl.dwSource      = i;
			if(mixerGetLineInfo((HMIXEROBJ)m_hMixer, &mxl, MIXER_GETLINEINFOF_SOURCE|MIXER_OBJECTF_HMIXER)!= MMSYSERR_NOERROR)
			{
				AfxMessageBox("GetLinInfo Resource faile!");
				continue;
			}
			if(mxl.dwComponentType==type2) break; 
			if(i==num) 
			{
				AfxMessageBox("GetLinInfo Resource faile!");
				return;
			}
		}
	}
    m_ControlNum=mxl.cChannels; 
	mxlc.cbStruct = sizeof(MIXERLINECONTROLS);
	mxlc.dwLineID = mxl.dwLineID;
	mxlc.dwControlType =type3; 
	mxlc.cControls =1;
	mxlc.cbmxctrl = sizeof(MIXERCONTROL);
	mxlc.pamxctrl = &mxc;
	if (::mixerGetLineControls((HMIXEROBJ)m_hMixer,&mxlc,MIXER_OBJECTF_HMIXER |MIXER_GETLINECONTROLSF_ONEBYTYPE )!= MMSYSERR_NOERROR)
		return;
    m_strName=mxc.szName; 
	m_ControlID = mxc.dwControlID;
	m_min= mxc.Bounds.lMinimum;
	m_max= mxc.Bounds.lMaximum;
}

void CVolumControl::Close()
{
	if (m_hMixer != NULL)
	{
		::mixerClose(m_hMixer);
		m_hMixer = NULL;
	}
}
DWORD CVolumControl::GetMax()
{
	return m_max;
}

DWORD CVolumControl::GetMin()
{
	return m_min;
}
DWORD CVolumControl::GetValue(DWORD *vl,DWORD *vr)
{	
	if (m_hMixer == NULL) return -1;
	MIXERCONTROLDETAILS_SIGNED mxcdVolume[2];
	MIXERCONTROLDETAILS mxcd;
	*vl=-1;
	*vr=-1;
	mxcd.cbStruct = sizeof(MIXERCONTROLDETAILS);
	mxcd.dwControlID = m_ControlID;
	mxcd.cChannels = m_ControlNum;
	mxcd.cMultipleItems = 0;
	mxcd.cbDetails = sizeof(MIXERCONTROLDETAILS_SIGNED);
	mxcd.paDetails = mxcdVolume;
	if (::mixerGetControlDetails((HMIXEROBJ)m_hMixer,
								&mxcd,
								MIXER_OBJECTF_HMIXER |
								MIXER_GETCONTROLDETAILSF_VALUE)
								!= MMSYSERR_NOERROR)
		return -1;
	*vl=mxcdVolume[0].lValue;
	if(m_ControlNum==2)  
		*vr=mxcdVolume[1].lValue;
	return 1;
}
void CVolumControl::SetValue(DWORD vl,DWORD vr)
{
	MIXERCONTROLDETAILS_SIGNED mxcdVolume[2] = {vl,vr};
	MIXERCONTROLDETAILS mxcd;
	mxcd.cbStruct = sizeof(MIXERCONTROLDETAILS);
	mxcd.dwControlID = m_ControlID;
	mxcd.cChannels = m_ControlNum;
	mxcd.cMultipleItems = 0;
	mxcd.cbDetails = sizeof(MIXERCONTROLDETAILS_SIGNED);
	mxcd.paDetails = &mxcdVolume;
	if (::mixerSetControlDetails((HMIXEROBJ)m_hMixer,
									&mxcd,
									MIXER_OBJECTF_HMIXER |
									MIXER_SETCONTROLDETAILSF_VALUE)
									!= MMSYSERR_NOERROR)	
		return ;
}
