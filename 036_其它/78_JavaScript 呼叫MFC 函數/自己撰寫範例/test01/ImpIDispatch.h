/********************************************************************
	created:	2006/07/21
	created:	21:7:2006   22:14
	filename: 	D:\BeiJing\VC6\SmallTech\MFCHtml\ImpIDispatch.h
	file path:	D:\BeiJing\VC6\SmallTech\MFCHtml
	file base:	ImpIDispatch
	file ext:	h
	author:		万连文
	
	purpose:	重新实现自动化接口，实现和网页交互
*********************************************************************/

#ifndef _IMPIDISPATCH_H_
#define _IMPIDISPATCH_H_

class CImpIDispatch : public IDispatch
{
protected:
	ULONG			m_cRef;

public:
	CImpIDispatch(void);
	~CImpIDispatch(void);
	
	STDMETHODIMP QueryInterface(REFIID, void**);
	STDMETHODIMP_(ULONG) AddRef(void);
	STDMETHODIMP_(ULONG) Release(void);
	
	//IDispatch
	STDMETHODIMP GetTypeInfoCount(UINT* pctinfo);
	STDMETHODIMP GetTypeInfo(
		/* [in] */ UINT iTInfo,
		/* [in] */ LCID lcid,
		/* [out] */ ITypeInfo** ppTInfo);
	STDMETHODIMP GetIDsOfNames(
		/* [in] */ REFIID riid,
		/* [size_is][in] */ LPOLESTR* rgszNames,
		/* [in] */ UINT cNames,
		/* [in] */ LCID lcid,
		/* [size_is][out] */ DISPID* rgDispId);
	STDMETHODIMP Invoke(
		/* [in] */ DISPID dispIdMember,
		/* [in] */ REFIID riid,
		/* [in] */ LCID lcid,
		/* [in] */ WORD wFlags,
		/* [out][in] */ DISPPARAMS* pDispParams,
		/* [out] */ VARIANT* pVarResult,
		/* [out] */ EXCEPINFO* pExcepInfo,
		/* [out] */ UINT* puArgErr);
};

#endif
