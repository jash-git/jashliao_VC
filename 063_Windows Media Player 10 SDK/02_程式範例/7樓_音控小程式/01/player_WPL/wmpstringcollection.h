#if !defined(AFX_WMPSTRINGCOLLECTION_H__4390D4D2_5189_4E4A_8698_E8B31842FC8B__INCLUDED_)
#define AFX_WMPSTRINGCOLLECTION_H__4390D4D2_5189_4E4A_8698_E8B31842FC8B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CWMPStringCollection wrapper class

class CWMPStringCollection : public COleDispatchDriver
{
public:
	CWMPStringCollection() {}		// Calls COleDispatchDriver default constructor
	CWMPStringCollection(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPStringCollection(const CWMPStringCollection& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetCount();
	CString Item(long lIndex);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WMPSTRINGCOLLECTION_H__4390D4D2_5189_4E4A_8698_E8B31842FC8B__INCLUDED_)
