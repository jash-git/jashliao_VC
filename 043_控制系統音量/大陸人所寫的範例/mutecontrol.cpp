// CMuteControl.cpp: implementation of the CMuteControl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MuteControl.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMuteControl::CMuteControl()
{}

CMuteControl::~CMuteControl()
{}

void CMuteControl::Create(CWnd *pWnd,DWORD type1,DWORD type2)
{
	m_pWnd=pWnd;
	m_hMixer = NULL;
	::ZeroMemory(&m_mxcaps, sizeof(MIXERCAPS));
	if (::mixerGetNumDevs()!= 0)
	{
		if (::mixerOpen(&m_hMixer,0,(DWORD)m_pWnd->m_hWnd,NULL,MIXER_OBJECTF_MIXER | CALLBACK_WINDOW)
			!= MMSYSERR_NOERROR)
			return ;
		if (::mixerGetDevCaps((UINT)m_hMixer, &m_mxcaps, sizeof(MIXERCAPS))
			!= MMSYSERR_NOERROR)
			return ;
	}
	if (m_hMixer == NULL)	return ;
	MIXERLINE mxl;
	mxl.cbStruct = sizeof(MIXERLINE);
	mxl.dwComponentType = type1;
	if (::mixerGetLineInfo((HMIXEROBJ)m_hMixer,
						   &mxl,
						   MIXER_OBJECTF_HMIXER |
						   MIXER_GETLINEINFOF_COMPONENTTYPE)
		!= MMSYSERR_NOERROR)		return ;
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
				AfxMessageBox("GetLinInfo Resource out!");
				return;
			}
		}
	}
	MIXERCONTROL mxc;
	MIXERLINECONTROLS mxlc;
	mxlc.cbStruct = sizeof(MIXERLINECONTROLS);
	mxlc.dwLineID = mxl.dwLineID;
	mxlc.dwControlType = MIXERCONTROL_CONTROLTYPE_MUTE;
	mxlc.cControls = 1;
	mxlc.cbmxctrl = sizeof(MIXERCONTROL);
	mxlc.pamxctrl = &mxc;
	if (::mixerGetLineControls((HMIXEROBJ)m_hMixer,
							   &mxlc,
							   MIXER_OBJECTF_HMIXER |
							   MIXER_GETLINECONTROLSF_ONEBYTYPE)
		!= MMSYSERR_NOERROR)		return ;
	m_controlid = mxc.dwControlID;
}

void CMuteControl::SetValue(DWORD value)
{
	if (m_hMixer == NULL) return ;
	MIXERCONTROLDETAILS_BOOLEAN mxcdMute = {value};
	MIXERCONTROLDETAILS mxcd;
	mxcd.cbStruct = sizeof(MIXERCONTROLDETAILS);
	mxcd.dwControlID = m_controlid;
	mxcd.cChannels = 1;
	mxcd.cMultipleItems = 0;
	mxcd.cbDetails = sizeof(MIXERCONTROLDETAILS_BOOLEAN);
	mxcd.paDetails = &mxcdMute;
	if (::mixerSetControlDetails((HMIXEROBJ)m_hMixer,
								 &mxcd,
								 MIXER_OBJECTF_HMIXER |
								 MIXER_SETCONTROLDETAILSF_VALUE)
		!= MMSYSERR_NOERROR)	return ;
}
DWORD CMuteControl::GetValue()
{
	if(m_hMixer==NULL) return -1;
	MIXERCONTROLDETAILS_BOOLEAN mxcdMute;
	MIXERCONTROLDETAILS mxcd;
	mxcd.cbStruct = sizeof(MIXERCONTROLDETAILS);
	mxcd.dwControlID = m_controlid;
	mxcd.cChannels = 1;
	mxcd.cMultipleItems = 0;
	mxcd.cbDetails = sizeof(MIXERCONTROLDETAILS_BOOLEAN);
	mxcd.paDetails =&mxcdMute;
	if (::mixerGetControlDetails((HMIXEROBJ)m_hMixer,
									&mxcd,
									MIXER_OBJECTF_HMIXER |
									MIXER_GETCONTROLDETAILSF_VALUE)
									!= MMSYSERR_NOERROR)		
		return -1;
	return mxcdMute.fValue;
}

void CMuteControl::Close()
{
	if (m_hMixer != NULL)
	{
		::mixerClose(m_hMixer);
		m_hMixer = NULL;
	}
}
