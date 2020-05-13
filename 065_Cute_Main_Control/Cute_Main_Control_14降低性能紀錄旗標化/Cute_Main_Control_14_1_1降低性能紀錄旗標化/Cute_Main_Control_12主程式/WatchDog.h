// WatchDog.h: interface for the CWatchDog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WATCHDOG_H__8CCCF118_37F4_4B74_82CB_A770C8085E96__INCLUDED_)
#define AFX_WATCHDOG_H__8CCCF118_37F4_4B74_82CB_A770C8085E96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
typedef struct
{
    short int pitch;
    short int duration;
} NOTE;
class CWatchDog  
{
public:
	NOTE notes[5];
	CWatchDog();
	virtual ~CWatchDog();
	void DisableWDT();
	void StartWDT();
	void ResetWDT();
	void SetBaseTime();
	void SetSeconds();
	void ActivateWDT();
	void SelectDevice();
	void UnlockWDT();
	void playnote(NOTE note);
	void setfreq(int hz);
	char EnablePrivilege(IN const char*szPrivilege,IN const char bEnable);
	void ShowErrorMsg(const char* szName, const DWORD dwLine,const DWORD dwError);
};

#endif // !defined(AFX_WATCHDOG_H__8CCCF118_37F4_4B74_82CB_A770C8085E96__INCLUDED_)
