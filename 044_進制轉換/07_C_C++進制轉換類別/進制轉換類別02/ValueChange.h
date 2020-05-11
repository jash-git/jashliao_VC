// ValueChange.h: interface for the CValueChange class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VALUECHANGE_H__464385DF_5908_4D27_BFB0_56E2D35AA271__INCLUDED_)
#define AFX_VALUECHANGE_H__464385DF_5908_4D27_BFB0_56E2D35AA271__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CValueChange  
{
public:
	char *m_strInputData;
	CValueChange();
	virtual ~CValueChange();
	char * Chang2to10(char *);
	char * Chang10to2(char *);
	char * Chang2to8(char *);
	char * Chang8to2(char *);
	char * Chang16to2(char *);
	char * Chang2to16(char *);
	long GetOutputLen();
private:
	long m_lngInputLen;
	long m_lngOutputLen;
	bool m_bnlActive;
protected:
	char *m_strOutputData;
};

#endif // !defined(AFX_VALUECHANGE_H__464385DF_5908_4D27_BFB0_56E2D35AA271__INCLUDED_)
