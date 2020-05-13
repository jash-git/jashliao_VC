// CWMPMediaCollection2.h  : 以 Microsoft Visual C++ 建立之 ActiveX 控制項包裝函式類別的宣告

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CWMPMediaCollection2

class CWMPMediaCollection2 : public COleDispatchDriver
{
public:
	CWMPMediaCollection2() {}		// 呼叫 COleDispatchDriver 預設建構函式
	CWMPMediaCollection2(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CWMPMediaCollection2(const CWMPMediaCollection2& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// 屬性
public:

// 作業
public:

	LPDISPATCH add(LPCTSTR bstrURL)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1c4, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrURL);
		return result;
	}
	LPDISPATCH getAll()
	{
		LPDISPATCH result;
		InvokeHelper(0x1c5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH getByName(LPCTSTR bstrName)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1c6, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrName);
		return result;
	}
	LPDISPATCH getByGenre(LPCTSTR bstrGenre)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1c7, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrGenre);
		return result;
	}
	LPDISPATCH getByAuthor(LPCTSTR bstrAuthor)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1c8, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrAuthor);
		return result;
	}
	LPDISPATCH getByAlbum(LPCTSTR bstrAlbum)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1c9, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrAlbum);
		return result;
	}
	LPDISPATCH getByAttribute(LPCTSTR bstrAttribute, LPCTSTR bstrValue)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x1ca, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrAttribute, bstrValue);
		return result;
	}
	void remove(LPDISPATCH pItem, BOOL varfDeleteFile)
	{
		static BYTE parms[] = VTS_DISPATCH VTS_BOOL ;
		InvokeHelper(0x1cb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pItem, varfDeleteFile);
	}
	LPDISPATCH getAttributeStringCollection(LPCTSTR bstrAttribute, LPCTSTR bstrMediaType)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x1cd, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrAttribute, bstrMediaType);
		return result;
	}
	long getMediaAtom(LPCTSTR bstrItemName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1d6, DISPATCH_METHOD, VT_I4, (void*)&result, parms, bstrItemName);
		return result;
	}
	void setDeleted(LPDISPATCH pItem, BOOL varfIsDeleted)
	{
		static BYTE parms[] = VTS_DISPATCH VTS_BOOL ;
		InvokeHelper(0x1d7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pItem, varfIsDeleted);
	}
	BOOL isDeleted(LPDISPATCH pItem)
	{
		BOOL result;
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x1d8, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, pItem);
		return result;
	}
	LPDISPATCH createQuery()
	{
		LPDISPATCH result;
		InvokeHelper(0x579, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH getPlaylistByQuery(LPDISPATCH pQuery, LPCTSTR bstrMediaType, LPCTSTR bstrSortAttribute, BOOL fSortAscending)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_DISPATCH VTS_BSTR VTS_BSTR VTS_BOOL ;
		InvokeHelper(0x57a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, pQuery, bstrMediaType, bstrSortAttribute, fSortAscending);
		return result;
	}
	LPDISPATCH getStringCollectionByQuery(LPCTSTR bstrAttribute, LPDISPATCH pQuery, LPCTSTR bstrMediaType, LPCTSTR bstrSortAttribute, BOOL fSortAscending)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_DISPATCH VTS_BSTR VTS_BSTR VTS_BOOL ;
		InvokeHelper(0x57b, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrAttribute, pQuery, bstrMediaType, bstrSortAttribute, fSortAscending);
		return result;
	}
	LPDISPATCH getByAttributeAndMediaType(LPCTSTR bstrAttribute, LPCTSTR bstrValue, LPCTSTR bstrMediaType)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x57c, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, bstrAttribute, bstrValue, bstrMediaType);
		return result;
	}


};
