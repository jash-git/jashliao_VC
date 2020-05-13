// DelAllDir.h: interface for the CDelAllDir class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DELALLDIR_H__EDB5C50B_F5FB_406C_8D40_F465A6037B44__INCLUDED_)
#define AFX_DELALLDIR_H__EDB5C50B_F5FB_406C_8D40_F465A6037B44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxtempl.h>//CArray Step_01 
class CDelAllDir  
{
public:
	CDelAllDir();
	void BrowseDir(CString strDir);
	void DelFolder(CString path);
	void Run();
	virtual ~CDelAllDir();
protected:
	CArray <CString,CString&> m_Array1;//CArray Step_02

};

#endif // !defined(AFX_DELALLDIR_H__EDB5C50B_F5FB_406C_8D40_F465A6037B44__INCLUDED_)
