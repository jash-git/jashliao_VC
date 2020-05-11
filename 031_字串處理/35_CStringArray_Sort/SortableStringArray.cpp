// SortableStringArray.cpp: implementation of the CSortableStringArray class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CStringArray_Sort.h"
#include "SortableStringArray.h"
#include <afxtempl.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSortableStringArray::CSortableStringArray()
{

}

CSortableStringArray::~CSortableStringArray()
{

}
int CSortableStringArray::Compare(const CString * pstr1, const CString * pstr2)
{
	ASSERT(pstr1);
	ASSERT(pstr2);
	return pstr1->Compare(*pstr2);
}

void CSortableStringArray::Sort(STRINGCOMPAREFN pfnCompare /*= CSortedStringArray::Compare */)
{
	CString * prgstr = GetData();
	qsort(prgstr,GetSize(),sizeof(CString),(GENERICCOMPAREFN)pfnCompare);
}