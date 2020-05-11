// NetUsebat.h: interface for the CNetUsebat class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NETUSEBAT_H__8D9014BB_52AF_40EE_9BEA_77188FEB80F5__INCLUDED_)
#define AFX_NETUSEBAT_H__8D9014BB_52AF_40EE_9BEA_77188FEB80F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNetUsebat  
{
public:
	CNetUsebat();
	CNetUsebat(CString StrName,CString StrPWS,CString StrData,int intCount);
	void Createbat(CString StrName,CString StrPWS,CString StrData,int intCount);
	bool CreateShareDir();
	void DeleteShareDir();
	virtual ~CNetUsebat();
protected:
	CString StrCreateBuf,StrDeleteBuf;//Bat檔名
	CString StrCreateAns,StrDeleteAns;//結果檔名
};

#endif // !defined(AFX_NETUSEBAT_H__8D9014BB_52AF_40EE_9BEA_77188FEB80F5__INCLUDED_)
