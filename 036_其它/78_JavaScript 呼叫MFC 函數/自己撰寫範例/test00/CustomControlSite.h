/********************************************************************
	created:	2006/07/21
	created:	21:7:2006   20:26
	filename: 	D:\BeiJing\VC6\SmallTech\MFCHtml\CustomControlSite.h
	file path:	D:\BeiJing\VC6\SmallTech\MFCHtml
	file base:	CustomControlSite
	file ext:	h
	author:		万连文
	
	purpose:	重新实现AxtiveX控件站点，这样可以自定义站点行为
*********************************************************************/
#ifndef _CUSTOMESITE_H_
#define _CUSTOMESITE_H_

#include "ImpIDispatch.h"
#include <mshtmhst.h>


class CCustomControlSite : public COleControlSite
{
public:
	CCustomControlSite(COleControlContainer* pCtrlCnt) : COleControlSite(pCtrlCnt)
	{
	}

	BEGIN_INTERFACE_PART(DocHostShowUI, IDocHostShowUI)
		INIT_INTERFACE_PART(CDocHostSite, DocHostShowUI)
		STDMETHOD(ShowHelp)(
			/* [in ] */	HWND hwnd,
			/* [in ] */	LPOLESTR pszHelpFile,
			/* [in ] */	UINT uCommand,
			/* [in ] */	DWORD dwData,
			/* [in ] */	POINT ptMouse,
			/* [out] */	IDispatch __RPC_FAR* pDispatchObjectHit);
		STDMETHOD(ShowMessage)(
			/* [in ] */	HWND hwnd,
			/* [in ] */	LPOLESTR lpstrText,
			/* [in ] */	LPOLESTR lpstrCaption,
			/* [in ] */	DWORD dwType,
			/* [in ] */	LPOLESTR lpstrHelpFile,
			/* [in ] */	DWORD dwHelpContext,
			/* [out] */	LRESULT __RPC_FAR* plResult);
	END_INTERFACE_PART(DocHostShowUI)

	
	BEGIN_INTERFACE_PART(DocHostUIHandler, IDocHostUIHandler)
		STDMETHOD(ShowContextMenu)(
			/* [in] */ DWORD dwID,
			/* [in] */ POINT __RPC_FAR* ppt,
			/* [in] */ IUnknown __RPC_FAR* pcmdtReserved,
			/* [in] */ IDispatch __RPC_FAR* pdispReserved);
		STDMETHOD(GetHostInfo)(
			/* [out][in] */ DOCHOSTUIINFO __RPC_FAR* pInfo);
		STDMETHOD(ShowUI)( 
			/* [in] */ DWORD dwID,
			/* [in] */ IOleInPlaceActiveObject __RPC_FAR* pActiveObject,
			/* [in] */ IOleCommandTarget __RPC_FAR* pCommandTarget,
			/* [in] */ IOleInPlaceFrame __RPC_FAR* pFrame,
			/* [in] */ IOleInPlaceUIWindow __RPC_FAR* pDoc);
		STDMETHOD(HideUI)(void);
		STDMETHOD(UpdateUI)(void);
		STDMETHOD(EnableModeless)(/* [in] */ BOOL fEnable);
		STDMETHOD(OnDocWindowActivate)(/* [in] */ BOOL fEnable);
		STDMETHOD(OnFrameWindowActivate)(/* [in] */ BOOL fEnable);
		STDMETHOD(ResizeBorder)( 
			/* [in] */ LPCRECT prcBorder,
			/* [in] */ IOleInPlaceUIWindow __RPC_FAR* pUIWindow,
			/* [in] */ BOOL fRameWindow);
		STDMETHOD(TranslateAccelerator)( 
			/* [in] */ LPMSG lpMsg,
			/* [in] */ const GUID __RPC_FAR* pguidCmdGroup,
			/* [in] */ DWORD nCmdID);
		STDMETHOD(GetOptionKeyPath)( 
			/* [out] */ LPOLESTR __RPC_FAR* pchKey,
			/* [in] */ DWORD dw);
		STDMETHOD(GetDropTarget)(
			/* [in] */ IDropTarget __RPC_FAR* pDropTarget,
			/* [out] */ IDropTarget __RPC_FAR*__RPC_FAR* ppDropTarget);
		STDMETHOD(GetExternal)(
            /* [out] */ IDispatch __RPC_FAR*__RPC_FAR* ppDispatch);
		STDMETHOD(TranslateUrl)(
            /* [in] */ DWORD dwTranslate,
            /* [in] */ OLECHAR __RPC_FAR* pchURLIn,
            /* [out] */ OLECHAR __RPC_FAR*__RPC_FAR* ppchURLOut);
		STDMETHOD(FilterDataObject)(
			/* [in] */ IDataObject __RPC_FAR* pDO,
		/* [out] */ IDataObject __RPC_FAR*__RPC_FAR* ppDORet);
	END_INTERFACE_PART(DocHostUIHandler)

	DECLARE_INTERFACE_MAP();
};


class CCustomOccManager : public COccManager
{
public:
	CCustomOccManager(){}
	COleControlSite* CreateSite(COleControlContainer* pCtrlCont)
	{
		CCustomControlSite*	pSite	= NULL;
		pSite = new CCustomControlSite(pCtrlCont);
		return pSite;
	}
};

#endif
