// SortableStringArray.h: interface for the CSortableStringArray class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SORTABLESTRINGARRAY_H__349A568A_2C25_4BC9_A63F_CF6DCC5FD4CC__INCLUDED_)
#define AFX_SORTABLESTRINGARRAY_H__349A568A_2C25_4BC9_A63F_CF6DCC5FD4CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef int (__cdecl *GENERICCOMPAREFN)(const void * elem1, const void * elem2);
typedef int (__cdecl *STRINGCOMPAREFN)(const CString * elem1, const CString * elem2);

class CSortableStringArray : public CStringArray 
{
public:
	CSortableStringArray();
	virtual ~CSortableStringArray();
	void Sort(STRINGCOMPAREFN pfnCompare = Compare);

protected:
	static int __cdecl Compare(const CString * pstr1, const CString * pstr2);
};

#endif // !defined(AFX_SORTABLESTRINGARRAY_H__349A568A_2C25_4BC9_A63F_CF6DCC5FD4CC__INCLUDED_)
