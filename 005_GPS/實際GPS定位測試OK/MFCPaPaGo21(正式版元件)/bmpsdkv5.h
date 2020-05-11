/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 18 16:42:10 2005
 */
/* Compiler settings for D:\SDK 專案開發\PaPaGO! SDK V5\SDK 1.3 Source\SDK for PC\BmpSDK_V5\bmpsdkv5\bmpsdkv5.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __bmpsdkv5_h__
#define __bmpsdkv5_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IDrawObject_FWD_DEFINED__
#define __IDrawObject_FWD_DEFINED__
typedef interface IDrawObject IDrawObject;
#endif 	/* __IDrawObject_FWD_DEFINED__ */


#ifndef __DrawObject_FWD_DEFINED__
#define __DrawObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class DrawObject DrawObject;
#else
typedef struct DrawObject DrawObject;
#endif /* __cplusplus */

#endif 	/* __DrawObject_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IDrawObject_INTERFACE_DEFINED__
#define __IDrawObject_INTERFACE_DEFINED__

/* interface IDrawObject */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDrawObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("13C8F52D-7182-4B98-AE5B-A592F5C3E105")
    IDrawObject : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseImage( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenImage( 
            /* [in] */ BSTR filename,
            /* [out] */ BOOL __RPC_FAR *bResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OutputImageFile( 
            /* [in] */ BSTR filename,
            /* [out] */ BOOL __RPC_FAR *bResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawBitmap( 
            /* [in] */ long ValXCenter,
            /* [in] */ long ValYCenter,
            /* [in] */ BSTR bstrBmpFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawBitmap_Mask( 
            /* [in] */ long ValXCenter,
            /* [in] */ long ValYCenter,
            /* [in] */ BSTR bstrBmpFile,
            /* [in] */ BSTR bstrMaskBmpFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawText( 
            /* [in] */ long ValXLeft,
            /* [in] */ long ValYTop,
            /* [in] */ BSTR bstrString,
            /* [in] */ BSTR bstrFontName,
            /* [in] */ long FontSize,
            /* [in] */ long colorTxt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawText_Frame( 
            /* [in] */ long ValXLeft,
            /* [in] */ long ValYTop,
            /* [in] */ BSTR bstrString,
            /* [in] */ BSTR bstrFontName,
            /* [in] */ long FontSize,
            /* [in] */ long colorTxt,
            /* [in] */ long colorBK) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawRect( 
            /* [in] */ long ValXCenter,
            /* [in] */ long ValYCenter,
            /* [in] */ long RadiusX,
            /* [in] */ long RadiusY,
            /* [in] */ long colorRect,
            /* [in] */ long colorInner) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawEllipse( 
            /* [in] */ long ValXCenter,
            /* [in] */ long ValYCenter,
            /* [in] */ long RadiusX,
            /* [in] */ long RadiusY,
            /* [in] */ long colorEllipse,
            /* [in] */ long colorInner) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawLine( 
            /* [in] */ long ValX1,
            /* [in] */ long ValY1,
            /* [in] */ long ValX2,
            /* [in] */ long ValY2,
            /* [in] */ long LineWidth,
            /* [in] */ long color) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPixel( 
            /* [in] */ long ValX,
            /* [in] */ long ValY,
            /* [in] */ long color) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetImage( 
            /* [in] */ long bmpHandle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetImage( 
            /* [out] */ long __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDrawObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDrawObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDrawObject __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDrawObject __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDrawObject __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDrawObject __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDrawObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDrawObject __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseImage )( 
            IDrawObject __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenImage )( 
            IDrawObject __RPC_FAR * This,
            /* [in] */ BSTR filename,
            /* [out] */ BOOL __RPC_FAR *bResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OutputImageFile )( 
            IDrawObject __RPC_FAR * This,
            /* [in] */ BSTR filename,
            /* [out] */ BOOL __RPC_FAR *bResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawBitmap )( 
            IDrawObject __RPC_FAR * This,
            /* [in] */ long ValXCenter,
            /* [in] */ long ValYCenter,
            /* [in] */ BSTR bstrBmpFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawBitmap_Mask )( 
            IDrawObject __RPC_FAR * This,
            /* [in] */ long ValXCenter,
            /* [in] */ long ValYCenter,
            /* [in] */ BSTR bstrBmpFile,
            /* [in] */ BSTR bstrMaskBmpFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawText )( 
            IDrawObject __RPC_FAR * This,
            /* [in] */ long ValXLeft,
            /* [in] */ long ValYTop,
            /* [in] */ BSTR bstrString,
            /* [in] */ BSTR bstrFontName,
            /* [in] */ long FontSize,
            /* [in] */ long colorTxt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawText_Frame )( 
            IDrawObject __RPC_FAR * This,
            /* [in] */ long ValXLeft,
            /* [in] */ long ValYTop,
            /* [in] */ BSTR bstrString,
            /* [in] */ BSTR bstrFontName,
            /* [in] */ long FontSize,
            /* [in] */ long colorTxt,
            /* [in] */ long colorBK);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawRect )( 
            IDrawObject __RPC_FAR * This,
            /* [in] */ long ValXCenter,
            /* [in] */ long ValYCenter,
            /* [in] */ long RadiusX,
            /* [in] */ long RadiusY,
            /* [in] */ long colorRect,
            /* [in] */ long colorInner);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawEllipse )( 
            IDrawObject __RPC_FAR * This,
            /* [in] */ long ValXCenter,
            /* [in] */ long ValYCenter,
            /* [in] */ long RadiusX,
            /* [in] */ long RadiusY,
            /* [in] */ long colorEllipse,
            /* [in] */ long colorInner);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DrawLine )( 
            IDrawObject __RPC_FAR * This,
            /* [in] */ long ValX1,
            /* [in] */ long ValY1,
            /* [in] */ long ValX2,
            /* [in] */ long ValY2,
            /* [in] */ long LineWidth,
            /* [in] */ long color);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPixel )( 
            IDrawObject __RPC_FAR * This,
            /* [in] */ long ValX,
            /* [in] */ long ValY,
            /* [in] */ long color);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetImage )( 
            IDrawObject __RPC_FAR * This,
            /* [in] */ long bmpHandle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetImage )( 
            IDrawObject __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pVal);
        
        END_INTERFACE
    } IDrawObjectVtbl;

    interface IDrawObject
    {
        CONST_VTBL struct IDrawObjectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDrawObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDrawObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDrawObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDrawObject_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDrawObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDrawObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDrawObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDrawObject_CloseImage(This)	\
    (This)->lpVtbl -> CloseImage(This)

#define IDrawObject_OpenImage(This,filename,bResult)	\
    (This)->lpVtbl -> OpenImage(This,filename,bResult)

#define IDrawObject_OutputImageFile(This,filename,bResult)	\
    (This)->lpVtbl -> OutputImageFile(This,filename,bResult)

#define IDrawObject_DrawBitmap(This,ValXCenter,ValYCenter,bstrBmpFile)	\
    (This)->lpVtbl -> DrawBitmap(This,ValXCenter,ValYCenter,bstrBmpFile)

#define IDrawObject_DrawBitmap_Mask(This,ValXCenter,ValYCenter,bstrBmpFile,bstrMaskBmpFile)	\
    (This)->lpVtbl -> DrawBitmap_Mask(This,ValXCenter,ValYCenter,bstrBmpFile,bstrMaskBmpFile)

#define IDrawObject_DrawText(This,ValXLeft,ValYTop,bstrString,bstrFontName,FontSize,colorTxt)	\
    (This)->lpVtbl -> DrawText(This,ValXLeft,ValYTop,bstrString,bstrFontName,FontSize,colorTxt)

#define IDrawObject_DrawText_Frame(This,ValXLeft,ValYTop,bstrString,bstrFontName,FontSize,colorTxt,colorBK)	\
    (This)->lpVtbl -> DrawText_Frame(This,ValXLeft,ValYTop,bstrString,bstrFontName,FontSize,colorTxt,colorBK)

#define IDrawObject_DrawRect(This,ValXCenter,ValYCenter,RadiusX,RadiusY,colorRect,colorInner)	\
    (This)->lpVtbl -> DrawRect(This,ValXCenter,ValYCenter,RadiusX,RadiusY,colorRect,colorInner)

#define IDrawObject_DrawEllipse(This,ValXCenter,ValYCenter,RadiusX,RadiusY,colorEllipse,colorInner)	\
    (This)->lpVtbl -> DrawEllipse(This,ValXCenter,ValYCenter,RadiusX,RadiusY,colorEllipse,colorInner)

#define IDrawObject_DrawLine(This,ValX1,ValY1,ValX2,ValY2,LineWidth,color)	\
    (This)->lpVtbl -> DrawLine(This,ValX1,ValY1,ValX2,ValY2,LineWidth,color)

#define IDrawObject_SetPixel(This,ValX,ValY,color)	\
    (This)->lpVtbl -> SetPixel(This,ValX,ValY,color)

#define IDrawObject_SetImage(This,bmpHandle)	\
    (This)->lpVtbl -> SetImage(This,bmpHandle)

#define IDrawObject_GetImage(This,pVal)	\
    (This)->lpVtbl -> GetImage(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDrawObject_CloseImage_Proxy( 
    IDrawObject __RPC_FAR * This);


void __RPC_STUB IDrawObject_CloseImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDrawObject_OpenImage_Proxy( 
    IDrawObject __RPC_FAR * This,
    /* [in] */ BSTR filename,
    /* [out] */ BOOL __RPC_FAR *bResult);


void __RPC_STUB IDrawObject_OpenImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDrawObject_OutputImageFile_Proxy( 
    IDrawObject __RPC_FAR * This,
    /* [in] */ BSTR filename,
    /* [out] */ BOOL __RPC_FAR *bResult);


void __RPC_STUB IDrawObject_OutputImageFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDrawObject_DrawBitmap_Proxy( 
    IDrawObject __RPC_FAR * This,
    /* [in] */ long ValXCenter,
    /* [in] */ long ValYCenter,
    /* [in] */ BSTR bstrBmpFile);


void __RPC_STUB IDrawObject_DrawBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDrawObject_DrawBitmap_Mask_Proxy( 
    IDrawObject __RPC_FAR * This,
    /* [in] */ long ValXCenter,
    /* [in] */ long ValYCenter,
    /* [in] */ BSTR bstrBmpFile,
    /* [in] */ BSTR bstrMaskBmpFile);


void __RPC_STUB IDrawObject_DrawBitmap_Mask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDrawObject_DrawText_Proxy( 
    IDrawObject __RPC_FAR * This,
    /* [in] */ long ValXLeft,
    /* [in] */ long ValYTop,
    /* [in] */ BSTR bstrString,
    /* [in] */ BSTR bstrFontName,
    /* [in] */ long FontSize,
    /* [in] */ long colorTxt);


void __RPC_STUB IDrawObject_DrawText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDrawObject_DrawText_Frame_Proxy( 
    IDrawObject __RPC_FAR * This,
    /* [in] */ long ValXLeft,
    /* [in] */ long ValYTop,
    /* [in] */ BSTR bstrString,
    /* [in] */ BSTR bstrFontName,
    /* [in] */ long FontSize,
    /* [in] */ long colorTxt,
    /* [in] */ long colorBK);


void __RPC_STUB IDrawObject_DrawText_Frame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDrawObject_DrawRect_Proxy( 
    IDrawObject __RPC_FAR * This,
    /* [in] */ long ValXCenter,
    /* [in] */ long ValYCenter,
    /* [in] */ long RadiusX,
    /* [in] */ long RadiusY,
    /* [in] */ long colorRect,
    /* [in] */ long colorInner);


void __RPC_STUB IDrawObject_DrawRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDrawObject_DrawEllipse_Proxy( 
    IDrawObject __RPC_FAR * This,
    /* [in] */ long ValXCenter,
    /* [in] */ long ValYCenter,
    /* [in] */ long RadiusX,
    /* [in] */ long RadiusY,
    /* [in] */ long colorEllipse,
    /* [in] */ long colorInner);


void __RPC_STUB IDrawObject_DrawEllipse_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDrawObject_DrawLine_Proxy( 
    IDrawObject __RPC_FAR * This,
    /* [in] */ long ValX1,
    /* [in] */ long ValY1,
    /* [in] */ long ValX2,
    /* [in] */ long ValY2,
    /* [in] */ long LineWidth,
    /* [in] */ long color);


void __RPC_STUB IDrawObject_DrawLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDrawObject_SetPixel_Proxy( 
    IDrawObject __RPC_FAR * This,
    /* [in] */ long ValX,
    /* [in] */ long ValY,
    /* [in] */ long color);


void __RPC_STUB IDrawObject_SetPixel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDrawObject_SetImage_Proxy( 
    IDrawObject __RPC_FAR * This,
    /* [in] */ long bmpHandle);


void __RPC_STUB IDrawObject_SetImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDrawObject_GetImage_Proxy( 
    IDrawObject __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pVal);


void __RPC_STUB IDrawObject_GetImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDrawObject_INTERFACE_DEFINED__ */



#ifndef __BMPSDKV5Lib_LIBRARY_DEFINED__
#define __BMPSDKV5Lib_LIBRARY_DEFINED__

/* library BMPSDKV5Lib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_BMPSDKV5Lib;

EXTERN_C const CLSID CLSID_DrawObject;

#ifdef __cplusplus

class DECLSPEC_UUID("13FC7CD6-1732-4607-9380-B5E66749A2AC")
DrawObject;
#endif
#endif /* __BMPSDKV5Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
