// AccessforSTB.h: interface for the CAccessforSTB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACCESSFORSTB_H__AA0C2EC3_0296_494F_AA02_4D866A792079__INCLUDED_)
#define AFX_ACCESSFORSTB_H__AA0C2EC3_0296_494F_AA02_4D866A792079__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxtempl.h>//CArray Step_01 
class CAccessforSTB  
{
public:
	CAccessforSTB();
	void GetConfigParameter();//step 3:Åª¨úXML
	void GetSTBInformation();
	void GetSTBMovieInformation(CString StrSTBuid);
	bool GetWebFile(CString theUrl, CString Filename);//http_download
	void ReadAVListXML(CString Struid);
	bool ConnectSTB(CString StrIP,int count);
	void ReadSTBAVList(CString StrIP);
	void STBAddAVFile(CString Struid,CString StrIP);
	void STBDelAVFile(CString Struid,CString StrIP);
	void InitReadXML();
	CString GetFilePath2FileName(CString Strdata);
	CString CreatInfoFileHead(CString StrStart,CString StrEnd);
	////////////////////////////////////////////////
	CString m_StrEnableSTBUrl;
	CString m_StrEnableuidUrl;
	CString m_StrNetDir;
	CArray <CString,CString&> m_ArraySTBuid;//CArray Step
	CArray <CString,CString&> m_ArraySTBIP;//CArray Step
	CArray <CString,CString&> m_ArrayFileSourcePath;
	CArray <CString,CString&> m_ArrayFileDestPath;
	CArray <CString,CString&> m_ArrayFileStartDate;
	CArray <CString,CString&> m_ArrayFileEndDate;
	CArray <CString,CString&> m_ArrayBrowseData;
	virtual ~CAccessforSTB();

};

#endif // !defined(AFX_ACCESSFORSTB_H__AA0C2EC3_0296_494F_AA02_4D866A792079__INCLUDED_)
