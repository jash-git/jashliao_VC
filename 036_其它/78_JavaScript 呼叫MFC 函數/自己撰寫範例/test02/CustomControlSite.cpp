/********************************************************************
	created:	2006/07/21
	created:	21:7:2006   21:37
	filename: 	D:\BeiJing\VC6\SmallTech\MFCHtml\CustomControlSite.cpp
	file path:	D:\BeiJing\VC6\SmallTech\MFCHtml
	file base:	CustomControlSite
	file ext:	cpp
	author:		万连文
	
	purpose:	重新实现AxtiveX控件站点，这样可以自定义站点行为
*********************************************************************/

#include "stdafx.h"
#undef AFX_DATA
#define AFX_DATA AFX_DATA_IMPORT
#include "test.h"//modify by jash

#include <..\src\occimpl.h>
#undef AFX_DATA
#define AFX_DATA AFX_DATA_EXPORT
#include "CustomControlSite.h"



BEGIN_INTERFACE_MAP(CCustomControlSite, COleControlSite)
	INTERFACE_PART(CCustomControlSite, IID_IDocHostShowUI, DocHostShowUI)
	INTERFACE_PART(CCustomControlSite, IID_IDocHostUIHandler, DocHostUIHandler)
END_INTERFACE_MAP()


ULONG CCustomControlSite::XDocHostShowUI::AddRef()
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostShowUI);
	return pThis->ExternalAddRef();
}

ULONG CCustomControlSite::XDocHostShowUI::Release()
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostShowUI);
	return pThis->ExternalRelease();
}

HRESULT CCustomControlSite::XDocHostShowUI::QueryInterface(REFIID riid, void** ppvObj)
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostShowUI);
	return pThis->ExternalQueryInterface(&riid, ppvObj);
}


HRESULT CCustomControlSite::XDocHostShowUI::ShowHelp(
								HWND hwnd,
								LPOLESTR pszHelpFile,
								UINT nCommand,
								DWORD dwData,
								POINT ptMouse,
								IDispatch* pDispatchObjectHit)
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostShowUI);
	return S_OK;
}

HRESULT CCustomControlSite::XDocHostShowUI::ShowMessage(
								HWND hwnd,
								LPOLESTR lpstrText,
								LPOLESTR lpstrCaption,
								DWORD dwType,
								LPOLESTR lpstrHelpFile,
								DWORD dwHelpContext,
								LRESULT * plResult)
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostShowUI);
	MessageBox(hwnd, (CString)lpstrText, "自定义浏览器", MB_ICONERROR);
	return S_OK;
}


ULONG CCustomControlSite::XDocHostUIHandler::AddRef()
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	return pThis->ExternalAddRef();
}


ULONG CCustomControlSite::XDocHostUIHandler::Release()
{                            
    METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	return pThis->ExternalRelease();
}

HRESULT CCustomControlSite::XDocHostUIHandler::QueryInterface(REFIID riid, void** ppvObj)
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
    HRESULT hr = (HRESULT)pThis->ExternalQueryInterface(&riid, ppvObj);
	return hr;
}

HRESULT CCustomControlSite::XDocHostUIHandler::GetHostInfo(DOCHOSTUIINFO* pInfo)
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	pInfo->dwFlags = DOCHOSTUIFLAG_NO3DBORDER;
	pInfo->dwDoubleClick = DOCHOSTUIDBLCLK_DEFAULT;
	return S_OK;
}

HRESULT CCustomControlSite::XDocHostUIHandler::ShowUI(
				DWORD dwID,
				IOleInPlaceActiveObject* /*pActiveObject*/,
				IOleCommandTarget* pCommandTarget,
				IOleInPlaceFrame* /*pFrame*/,
				IOleInPlaceUIWindow* /*pDoc*/)
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	return S_OK;
}

HRESULT CCustomControlSite::XDocHostUIHandler::HideUI(void)
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	return S_OK;
}

HRESULT CCustomControlSite::XDocHostUIHandler::UpdateUI(void)
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	return S_OK;
}

HRESULT CCustomControlSite::XDocHostUIHandler::EnableModeless(BOOL /*fEnable*/)
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::OnDocWindowActivate(BOOL /*fActivate*/)
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::OnFrameWindowActivate(BOOL /*fActivate*/)
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::ResizeBorder(
				LPCRECT /*prcBorder*/,
				IOleInPlaceUIWindow* /*pUIWindow*/,
				BOOL /*fRameWindow*/)
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	return E_NOTIMPL;
}

HRESULT CCustomControlSite::XDocHostUIHandler::ShowContextMenu(
				DWORD /*dwID*/,
				POINT* pptPosition,
				IUnknown* /*pCommandTarget*/,
				IDispatch* /*pDispatchObjectHit*/)
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	return S_OK; // We've shown our own context menu. MSHTML.DLL will no longer try to show its own.
}

HRESULT CCustomControlSite::XDocHostUIHandler::TranslateAccelerator(
			/* [in] */ LPMSG lpMsg,
            /* [in] */ const GUID __RPC_FAR* pguidCmdGroup,
            /* [in] */ DWORD nCmdID)
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	
	//disable F5
	if(lpMsg->message==WM_KEYDOWN && GetAsyncKeyState(VK_F5)<0)
	{
		return S_OK;
	}
	
	if(GetKeyState(VK_CONTROL) & 0x8000)
	{
		// disable ctrl + O
		if(lpMsg->message==WM_KEYDOWN && GetAsyncKeyState(0x4F)<0)
		{
			return S_OK;
		}
		//disable ctrl + p
		if(lpMsg->message==WM_KEYDOWN && GetAsyncKeyState(0x50)<0)
		{
			return S_OK;
		}
		//disable ctrl + N
		if(lpMsg->message==WM_KEYDOWN && GetAsyncKeyState(0x4E)<0)
		{
			return S_OK;
		}
	}
	
	//disable back space
// 	if(lpMsg->wParam == VK_BACK)
// 	{
// 		return S_OK;
// 	}
	
	return S_FALSE;
}

HRESULT CCustomControlSite::XDocHostUIHandler::GetOptionKeyPath(BSTR* pbstrKey, DWORD)
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	return E_NOTIMPL;
}

STDMETHODIMP CCustomControlSite::XDocHostUIHandler::GetDropTarget(
            /* [in] */ IDropTarget __RPC_FAR* pDropTarget,
            /* [out] */ IDropTarget __RPC_FAR*__RPC_FAR* ppDropTarget)
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	return E_NOTIMPL;
}

STDMETHODIMP CCustomControlSite::XDocHostUIHandler::GetExternal( 
            /* [out] */ IDispatch __RPC_FAR*__RPC_FAR* ppDispatch)
{
	// return the IDispatch we have for extending the object Model
	IDispatch*	pDisp	= (IDispatch*)theApp.m_pCustDisp;
	pDisp->AddRef();
	*ppDispatch = pDisp;
    return S_OK;
}
        
STDMETHODIMP CCustomControlSite::XDocHostUIHandler::TranslateUrl(
			/* [in] */ DWORD dwTranslate,
			/* [in] */ OLECHAR __RPC_FAR *pchURLIn,
			/* [out] */ OLECHAR __RPC_FAR*__RPC_FAR* ppchURLOut)
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	return E_NOTIMPL;
}
        
STDMETHODIMP CCustomControlSite::XDocHostUIHandler::FilterDataObject( 
            /* [in] */ IDataObject __RPC_FAR* pDO,
            /* [out] */ IDataObject __RPC_FAR*__RPC_FAR* ppDORet)
{
	METHOD_PROLOGUE(CCustomControlSite, DocHostUIHandler)
	return E_NOTIMPL;
}