/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Nov 16 11:18:12 2004
 */
/* Compiler settings for F:\WorkDisk\MyScheme\200411\Project\ATL\PaPaGOSDK_V5\ppgsdk50\ppgsdk50.idl:
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

#ifndef __ppgsdk50_h__
#define __ppgsdk50_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IMapObject_FWD_DEFINED__
#define __IMapObject_FWD_DEFINED__
typedef interface IMapObject IMapObject;
#endif 	/* __IMapObject_FWD_DEFINED__ */


#ifndef __MapObject_FWD_DEFINED__
#define __MapObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class MapObject MapObject;
#else
typedef struct MapObject MapObject;
#endif /* __cplusplus */

#endif 	/* __MapObject_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IMapObject_INTERFACE_DEFINED__
#define __IMapObject_INTERFACE_DEFINED__

/* interface IMapObject */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IMapObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("28A525FE-7DD2-4667-A585-790D6665363F")
    IMapObject : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseMap( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenMap( 
            /* [in] */ BSTR filename,
            /* [out] */ BOOL __RPC_FAR *bResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadProfile( 
            /* [in] */ BSTR filename,
            /* [out] */ BOOL __RPC_FAR *bResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadBackgroundFile( 
            /* [in] */ BSTR filename,
            /* [out] */ BOOL __RPC_FAR *bResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMapCenterXY( 
            /* [in] */ long ValX,
            /* [in] */ long ValY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMapCenterXY( 
            /* [out] */ long __RPC_FAR *pValX,
            /* [out] */ long __RPC_FAR *pValY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OutputMapImage( 
            /* [in] */ BSTR filename,
            /* [out] */ BOOL __RPC_FAR *bResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTotalScale( 
            /* [out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMapCurrentScale( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMapCurrentScale( 
            /* [out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMapCurrentSize( 
            /* [out] */ long __RPC_FAR *pValWidth,
            /* [out] */ long __RPC_FAR *pValHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetImageSize( 
            /* [in] */ long nWidth,
            /* [in] */ long nHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetImageSize( 
            /* [out] */ long __RPC_FAR *nWidth,
            /* [out] */ long __RPC_FAR *nHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MapShift( 
            /* [in] */ long ValX,
            /* [in] */ long ValY,
            /* [in] */ short nShiftRL,
            /* [in] */ short nShiftUD) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFlagXY( 
            /* [in] */ long ValX,
            /* [in] */ long ValY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearFlag( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMapBanner( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowAreaInMap( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowAreaInMap( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CalCoordinate_Gis2Scr( 
            /* [in] */ long nGisX,
            /* [in] */ long nGisY,
            /* [out] */ long __RPC_FAR *nScrX,
            /* [out] */ long __RPC_FAR *nScrY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CalCoordinate_Scr2Gis( 
            /* [in] */ long nScrX,
            /* [in] */ long nScrY,
            /* [out] */ long __RPC_FAR *nGisX,
            /* [out] */ long __RPC_FAR *nGisY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFindItemSize( 
            /* [in] */ long nSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindByIndex( 
            /* [in] */ BSTR strKey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindByLocation( 
            /* [in] */ long nGisX,
            /* [in] */ long nGisY,
            /* [in] */ long nRange) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFindResult_Count( 
            /* [out] */ long __RPC_FAR *pValCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFindResult( 
            /* [in] */ long nItemIdx,
            /* [out] */ long __RPC_FAR *pValX,
            /* [out] */ long __RPC_FAR *pValY,
            /* [out] */ BSTR __RPC_FAR *strName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFindResultExt( 
            /* [in] */ long nItemIdx,
            /* [out] */ BSTR __RPC_FAR *strCity,
            /* [out] */ BSTR __RPC_FAR *strTown,
            /* [out] */ BSTR __RPC_FAR *strType,
            /* [out] */ BSTR __RPC_FAR *strClass,
            /* [out] */ long __RPC_FAR *nDistToXY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetRoutingPreference( 
            /* [in] */ long nPref) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRoutingPreference( 
            /* [out] */ long __RPC_FAR *nPref) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearRouting( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Routing( 
            /* [in] */ long nGisX1,
            /* [in] */ long nGisY1,
            /* [in] */ long nGisX2,
            /* [in] */ long nGisY2,
            /* [out] */ BOOL __RPC_FAR *bResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OutputRoutingText( 
            BSTR filename,
            BOOL __RPC_FAR *bResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CalScaleByRect( 
            /* [in] */ long nGisX1,
            /* [in] */ long nGisY1,
            /* [in] */ long nGisX2,
            /* [in] */ long nGisY,
            /* [out] */ long __RPC_FAR *nNewScale) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMapRotation( 
            /* [in] */ long nNewAngle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMapRotation( 
            /* [out] */ long __RPC_FAR *pValAngle) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowBannerInMap( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowBannerInMap( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsDivergeRoutingPath( 
            /* [in] */ long ValX,
            /* [in] */ long ValY,
            /* [in] */ long nCheckDist,
            /* [out] */ BOOL __RPC_FAR *bResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNaviCurrentPath( 
            /* [in] */ long ValX,
            /* [in] */ long ValY,
            /* [out] */ BSTR __RPC_FAR *bstrRoad,
            /* [out] */ long __RPC_FAR *nDistLeft) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNaviNextAction( 
            /* [in] */ long ValX,
            /* [in] */ long ValY,
            /* [out] */ long __RPC_FAR *nDistTurn,
            /* [out] */ BSTR __RPC_FAR *nRoad,
            /* [out] */ BSTR __RPC_FAR *nActionTurn,
            /* [out] */ BSTR __RPC_FAR *nActionVoice) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetWhereString( 
            /* [in] */ long ValX,
            /* [in] */ long ValY,
            /* [out] */ BSTR __RPC_FAR *bstrWhere) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FixGPSPosition( 
            /* [in] */ long ValX,
            /* [in] */ long ValY,
            /* [out] */ long __RPC_FAR *pFixX,
            /* [out] */ long __RPC_FAR *pFixY,
            /* [out] */ BSTR __RPC_FAR *bstrRoad) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMapBitmap( 
            /* [out] */ long __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMapObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IMapObject __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IMapObject __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IMapObject __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseMap )( 
            IMapObject __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenMap )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ BSTR filename,
            /* [out] */ BOOL __RPC_FAR *bResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadProfile )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ BSTR filename,
            /* [out] */ BOOL __RPC_FAR *bResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadBackgroundFile )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ BSTR filename,
            /* [out] */ BOOL __RPC_FAR *bResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMapCenterXY )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long ValX,
            /* [in] */ long ValY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMapCenterXY )( 
            IMapObject __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pValX,
            /* [out] */ long __RPC_FAR *pValY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OutputMapImage )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ BSTR filename,
            /* [out] */ BOOL __RPC_FAR *bResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTotalScale )( 
            IMapObject __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMapCurrentScale )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMapCurrentScale )( 
            IMapObject __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMapCurrentSize )( 
            IMapObject __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pValWidth,
            /* [out] */ long __RPC_FAR *pValHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetImageSize )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long nWidth,
            /* [in] */ long nHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetImageSize )( 
            IMapObject __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *nWidth,
            /* [out] */ long __RPC_FAR *nHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MapShift )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long ValX,
            /* [in] */ long ValY,
            /* [in] */ short nShiftRL,
            /* [in] */ short nShiftUD);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFlagXY )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long ValX,
            /* [in] */ long ValY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearFlag )( 
            IMapObject __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMapBanner )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ShowAreaInMap )( 
            IMapObject __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShowAreaInMap )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CalCoordinate_Gis2Scr )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long nGisX,
            /* [in] */ long nGisY,
            /* [out] */ long __RPC_FAR *nScrX,
            /* [out] */ long __RPC_FAR *nScrY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CalCoordinate_Scr2Gis )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long nScrX,
            /* [in] */ long nScrY,
            /* [out] */ long __RPC_FAR *nGisX,
            /* [out] */ long __RPC_FAR *nGisY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFindItemSize )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long nSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindByIndex )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ BSTR strKey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindByLocation )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long nGisX,
            /* [in] */ long nGisY,
            /* [in] */ long nRange);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFindResult_Count )( 
            IMapObject __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pValCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFindResult )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long nItemIdx,
            /* [out] */ long __RPC_FAR *pValX,
            /* [out] */ long __RPC_FAR *pValY,
            /* [out] */ BSTR __RPC_FAR *strName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFindResultExt )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long nItemIdx,
            /* [out] */ BSTR __RPC_FAR *strCity,
            /* [out] */ BSTR __RPC_FAR *strTown,
            /* [out] */ BSTR __RPC_FAR *strType,
            /* [out] */ BSTR __RPC_FAR *strClass,
            /* [out] */ long __RPC_FAR *nDistToXY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRoutingPreference )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long nPref);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRoutingPreference )( 
            IMapObject __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *nPref);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearRouting )( 
            IMapObject __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Routing )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long nGisX1,
            /* [in] */ long nGisY1,
            /* [in] */ long nGisX2,
            /* [in] */ long nGisY2,
            /* [out] */ BOOL __RPC_FAR *bResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OutputRoutingText )( 
            IMapObject __RPC_FAR * This,
            BSTR filename,
            BOOL __RPC_FAR *bResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CalScaleByRect )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long nGisX1,
            /* [in] */ long nGisY1,
            /* [in] */ long nGisX2,
            /* [in] */ long nGisY,
            /* [out] */ long __RPC_FAR *nNewScale);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMapRotation )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long nNewAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMapRotation )( 
            IMapObject __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pValAngle);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ShowBannerInMap )( 
            IMapObject __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShowBannerInMap )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsDivergeRoutingPath )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long ValX,
            /* [in] */ long ValY,
            /* [in] */ long nCheckDist,
            /* [out] */ BOOL __RPC_FAR *bResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNaviCurrentPath )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long ValX,
            /* [in] */ long ValY,
            /* [out] */ BSTR __RPC_FAR *bstrRoad,
            /* [out] */ long __RPC_FAR *nDistLeft);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNaviNextAction )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long ValX,
            /* [in] */ long ValY,
            /* [out] */ long __RPC_FAR *nDistTurn,
            /* [out] */ BSTR __RPC_FAR *nRoad,
            /* [out] */ BSTR __RPC_FAR *nActionTurn,
            /* [out] */ BSTR __RPC_FAR *nActionVoice);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetWhereString )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long ValX,
            /* [in] */ long ValY,
            /* [out] */ BSTR __RPC_FAR *bstrWhere);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FixGPSPosition )( 
            IMapObject __RPC_FAR * This,
            /* [in] */ long ValX,
            /* [in] */ long ValY,
            /* [out] */ long __RPC_FAR *pFixX,
            /* [out] */ long __RPC_FAR *pFixY,
            /* [out] */ BSTR __RPC_FAR *bstrRoad);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMapBitmap )( 
            IMapObject __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pVal);
        
        END_INTERFACE
    } IMapObjectVtbl;

    interface IMapObject
    {
        CONST_VTBL struct IMapObjectVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMapObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMapObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMapObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMapObject_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMapObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMapObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMapObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMapObject_CloseMap(This)	\
    (This)->lpVtbl -> CloseMap(This)

#define IMapObject_OpenMap(This,filename,bResult)	\
    (This)->lpVtbl -> OpenMap(This,filename,bResult)

#define IMapObject_LoadProfile(This,filename,bResult)	\
    (This)->lpVtbl -> LoadProfile(This,filename,bResult)

#define IMapObject_LoadBackgroundFile(This,filename,bResult)	\
    (This)->lpVtbl -> LoadBackgroundFile(This,filename,bResult)

#define IMapObject_SetMapCenterXY(This,ValX,ValY)	\
    (This)->lpVtbl -> SetMapCenterXY(This,ValX,ValY)

#define IMapObject_GetMapCenterXY(This,pValX,pValY)	\
    (This)->lpVtbl -> GetMapCenterXY(This,pValX,pValY)

#define IMapObject_OutputMapImage(This,filename,bResult)	\
    (This)->lpVtbl -> OutputMapImage(This,filename,bResult)

#define IMapObject_GetTotalScale(This,pVal)	\
    (This)->lpVtbl -> GetTotalScale(This,pVal)

#define IMapObject_SetMapCurrentScale(This,newVal)	\
    (This)->lpVtbl -> SetMapCurrentScale(This,newVal)

#define IMapObject_GetMapCurrentScale(This,pVal)	\
    (This)->lpVtbl -> GetMapCurrentScale(This,pVal)

#define IMapObject_GetMapCurrentSize(This,pValWidth,pValHeight)	\
    (This)->lpVtbl -> GetMapCurrentSize(This,pValWidth,pValHeight)

#define IMapObject_SetImageSize(This,nWidth,nHeight)	\
    (This)->lpVtbl -> SetImageSize(This,nWidth,nHeight)

#define IMapObject_GetImageSize(This,nWidth,nHeight)	\
    (This)->lpVtbl -> GetImageSize(This,nWidth,nHeight)

#define IMapObject_MapShift(This,ValX,ValY,nShiftRL,nShiftUD)	\
    (This)->lpVtbl -> MapShift(This,ValX,ValY,nShiftRL,nShiftUD)

#define IMapObject_SetFlagXY(This,ValX,ValY)	\
    (This)->lpVtbl -> SetFlagXY(This,ValX,ValY)

#define IMapObject_ClearFlag(This)	\
    (This)->lpVtbl -> ClearFlag(This)

#define IMapObject_SetMapBanner(This,newVal)	\
    (This)->lpVtbl -> SetMapBanner(This,newVal)

#define IMapObject_get_ShowAreaInMap(This,pVal)	\
    (This)->lpVtbl -> get_ShowAreaInMap(This,pVal)

#define IMapObject_put_ShowAreaInMap(This,newVal)	\
    (This)->lpVtbl -> put_ShowAreaInMap(This,newVal)

#define IMapObject_CalCoordinate_Gis2Scr(This,nGisX,nGisY,nScrX,nScrY)	\
    (This)->lpVtbl -> CalCoordinate_Gis2Scr(This,nGisX,nGisY,nScrX,nScrY)

#define IMapObject_CalCoordinate_Scr2Gis(This,nScrX,nScrY,nGisX,nGisY)	\
    (This)->lpVtbl -> CalCoordinate_Scr2Gis(This,nScrX,nScrY,nGisX,nGisY)

#define IMapObject_SetFindItemSize(This,nSize)	\
    (This)->lpVtbl -> SetFindItemSize(This,nSize)

#define IMapObject_FindByIndex(This,strKey)	\
    (This)->lpVtbl -> FindByIndex(This,strKey)

#define IMapObject_FindByLocation(This,nGisX,nGisY,nRange)	\
    (This)->lpVtbl -> FindByLocation(This,nGisX,nGisY,nRange)

#define IMapObject_GetFindResult_Count(This,pValCount)	\
    (This)->lpVtbl -> GetFindResult_Count(This,pValCount)

#define IMapObject_GetFindResult(This,nItemIdx,pValX,pValY,strName)	\
    (This)->lpVtbl -> GetFindResult(This,nItemIdx,pValX,pValY,strName)

#define IMapObject_GetFindResultExt(This,nItemIdx,strCity,strTown,strType,strClass,nDistToXY)	\
    (This)->lpVtbl -> GetFindResultExt(This,nItemIdx,strCity,strTown,strType,strClass,nDistToXY)

#define IMapObject_SetRoutingPreference(This,nPref)	\
    (This)->lpVtbl -> SetRoutingPreference(This,nPref)

#define IMapObject_GetRoutingPreference(This,nPref)	\
    (This)->lpVtbl -> GetRoutingPreference(This,nPref)

#define IMapObject_ClearRouting(This)	\
    (This)->lpVtbl -> ClearRouting(This)

#define IMapObject_Routing(This,nGisX1,nGisY1,nGisX2,nGisY2,bResult)	\
    (This)->lpVtbl -> Routing(This,nGisX1,nGisY1,nGisX2,nGisY2,bResult)

#define IMapObject_OutputRoutingText(This,filename,bResult)	\
    (This)->lpVtbl -> OutputRoutingText(This,filename,bResult)

#define IMapObject_CalScaleByRect(This,nGisX1,nGisY1,nGisX2,nGisY,nNewScale)	\
    (This)->lpVtbl -> CalScaleByRect(This,nGisX1,nGisY1,nGisX2,nGisY,nNewScale)

#define IMapObject_SetMapRotation(This,nNewAngle)	\
    (This)->lpVtbl -> SetMapRotation(This,nNewAngle)

#define IMapObject_GetMapRotation(This,pValAngle)	\
    (This)->lpVtbl -> GetMapRotation(This,pValAngle)

#define IMapObject_get_ShowBannerInMap(This,pVal)	\
    (This)->lpVtbl -> get_ShowBannerInMap(This,pVal)

#define IMapObject_put_ShowBannerInMap(This,newVal)	\
    (This)->lpVtbl -> put_ShowBannerInMap(This,newVal)

#define IMapObject_IsDivergeRoutingPath(This,ValX,ValY,nCheckDist,bResult)	\
    (This)->lpVtbl -> IsDivergeRoutingPath(This,ValX,ValY,nCheckDist,bResult)

#define IMapObject_GetNaviCurrentPath(This,ValX,ValY,bstrRoad,nDistLeft)	\
    (This)->lpVtbl -> GetNaviCurrentPath(This,ValX,ValY,bstrRoad,nDistLeft)

#define IMapObject_GetNaviNextAction(This,ValX,ValY,nDistTurn,nRoad,nActionTurn,nActionVoice)	\
    (This)->lpVtbl -> GetNaviNextAction(This,ValX,ValY,nDistTurn,nRoad,nActionTurn,nActionVoice)

#define IMapObject_GetWhereString(This,ValX,ValY,bstrWhere)	\
    (This)->lpVtbl -> GetWhereString(This,ValX,ValY,bstrWhere)

#define IMapObject_FixGPSPosition(This,ValX,ValY,pFixX,pFixY,bstrRoad)	\
    (This)->lpVtbl -> FixGPSPosition(This,ValX,ValY,pFixX,pFixY,bstrRoad)

#define IMapObject_GetMapBitmap(This,pVal)	\
    (This)->lpVtbl -> GetMapBitmap(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_CloseMap_Proxy( 
    IMapObject __RPC_FAR * This);


void __RPC_STUB IMapObject_CloseMap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_OpenMap_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ BSTR filename,
    /* [out] */ BOOL __RPC_FAR *bResult);


void __RPC_STUB IMapObject_OpenMap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_LoadProfile_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ BSTR filename,
    /* [out] */ BOOL __RPC_FAR *bResult);


void __RPC_STUB IMapObject_LoadProfile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_LoadBackgroundFile_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ BSTR filename,
    /* [out] */ BOOL __RPC_FAR *bResult);


void __RPC_STUB IMapObject_LoadBackgroundFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_SetMapCenterXY_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long ValX,
    /* [in] */ long ValY);


void __RPC_STUB IMapObject_SetMapCenterXY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_GetMapCenterXY_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pValX,
    /* [out] */ long __RPC_FAR *pValY);


void __RPC_STUB IMapObject_GetMapCenterXY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_OutputMapImage_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ BSTR filename,
    /* [out] */ BOOL __RPC_FAR *bResult);


void __RPC_STUB IMapObject_OutputMapImage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_GetTotalScale_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pVal);


void __RPC_STUB IMapObject_GetTotalScale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_SetMapCurrentScale_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IMapObject_SetMapCurrentScale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_GetMapCurrentScale_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pVal);


void __RPC_STUB IMapObject_GetMapCurrentScale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_GetMapCurrentSize_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pValWidth,
    /* [out] */ long __RPC_FAR *pValHeight);


void __RPC_STUB IMapObject_GetMapCurrentSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_SetImageSize_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long nWidth,
    /* [in] */ long nHeight);


void __RPC_STUB IMapObject_SetImageSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_GetImageSize_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *nWidth,
    /* [out] */ long __RPC_FAR *nHeight);


void __RPC_STUB IMapObject_GetImageSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_MapShift_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long ValX,
    /* [in] */ long ValY,
    /* [in] */ short nShiftRL,
    /* [in] */ short nShiftUD);


void __RPC_STUB IMapObject_MapShift_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_SetFlagXY_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long ValX,
    /* [in] */ long ValY);


void __RPC_STUB IMapObject_SetFlagXY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_ClearFlag_Proxy( 
    IMapObject __RPC_FAR * This);


void __RPC_STUB IMapObject_ClearFlag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_SetMapBanner_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IMapObject_SetMapBanner_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMapObject_get_ShowAreaInMap_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IMapObject_get_ShowAreaInMap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMapObject_put_ShowAreaInMap_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IMapObject_put_ShowAreaInMap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_CalCoordinate_Gis2Scr_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long nGisX,
    /* [in] */ long nGisY,
    /* [out] */ long __RPC_FAR *nScrX,
    /* [out] */ long __RPC_FAR *nScrY);


void __RPC_STUB IMapObject_CalCoordinate_Gis2Scr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_CalCoordinate_Scr2Gis_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long nScrX,
    /* [in] */ long nScrY,
    /* [out] */ long __RPC_FAR *nGisX,
    /* [out] */ long __RPC_FAR *nGisY);


void __RPC_STUB IMapObject_CalCoordinate_Scr2Gis_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_SetFindItemSize_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long nSize);


void __RPC_STUB IMapObject_SetFindItemSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_FindByIndex_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ BSTR strKey);


void __RPC_STUB IMapObject_FindByIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_FindByLocation_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long nGisX,
    /* [in] */ long nGisY,
    /* [in] */ long nRange);


void __RPC_STUB IMapObject_FindByLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_GetFindResult_Count_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pValCount);


void __RPC_STUB IMapObject_GetFindResult_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_GetFindResult_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long nItemIdx,
    /* [out] */ long __RPC_FAR *pValX,
    /* [out] */ long __RPC_FAR *pValY,
    /* [out] */ BSTR __RPC_FAR *strName);


void __RPC_STUB IMapObject_GetFindResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_GetFindResultExt_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long nItemIdx,
    /* [out] */ BSTR __RPC_FAR *strCity,
    /* [out] */ BSTR __RPC_FAR *strTown,
    /* [out] */ BSTR __RPC_FAR *strType,
    /* [out] */ BSTR __RPC_FAR *strClass,
    /* [out] */ long __RPC_FAR *nDistToXY);


void __RPC_STUB IMapObject_GetFindResultExt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_SetRoutingPreference_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long nPref);


void __RPC_STUB IMapObject_SetRoutingPreference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_GetRoutingPreference_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *nPref);


void __RPC_STUB IMapObject_GetRoutingPreference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_ClearRouting_Proxy( 
    IMapObject __RPC_FAR * This);


void __RPC_STUB IMapObject_ClearRouting_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_Routing_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long nGisX1,
    /* [in] */ long nGisY1,
    /* [in] */ long nGisX2,
    /* [in] */ long nGisY2,
    /* [out] */ BOOL __RPC_FAR *bResult);


void __RPC_STUB IMapObject_Routing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_OutputRoutingText_Proxy( 
    IMapObject __RPC_FAR * This,
    BSTR filename,
    BOOL __RPC_FAR *bResult);


void __RPC_STUB IMapObject_OutputRoutingText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_CalScaleByRect_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long nGisX1,
    /* [in] */ long nGisY1,
    /* [in] */ long nGisX2,
    /* [in] */ long nGisY,
    /* [out] */ long __RPC_FAR *nNewScale);


void __RPC_STUB IMapObject_CalScaleByRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_SetMapRotation_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long nNewAngle);


void __RPC_STUB IMapObject_SetMapRotation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_GetMapRotation_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pValAngle);


void __RPC_STUB IMapObject_GetMapRotation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IMapObject_get_ShowBannerInMap_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IMapObject_get_ShowBannerInMap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IMapObject_put_ShowBannerInMap_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IMapObject_put_ShowBannerInMap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_IsDivergeRoutingPath_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long ValX,
    /* [in] */ long ValY,
    /* [in] */ long nCheckDist,
    /* [out] */ BOOL __RPC_FAR *bResult);


void __RPC_STUB IMapObject_IsDivergeRoutingPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_GetNaviCurrentPath_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long ValX,
    /* [in] */ long ValY,
    /* [out] */ BSTR __RPC_FAR *bstrRoad,
    /* [out] */ long __RPC_FAR *nDistLeft);


void __RPC_STUB IMapObject_GetNaviCurrentPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_GetNaviNextAction_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long ValX,
    /* [in] */ long ValY,
    /* [out] */ long __RPC_FAR *nDistTurn,
    /* [out] */ BSTR __RPC_FAR *nRoad,
    /* [out] */ BSTR __RPC_FAR *nActionTurn,
    /* [out] */ BSTR __RPC_FAR *nActionVoice);


void __RPC_STUB IMapObject_GetNaviNextAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_GetWhereString_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long ValX,
    /* [in] */ long ValY,
    /* [out] */ BSTR __RPC_FAR *bstrWhere);


void __RPC_STUB IMapObject_GetWhereString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_FixGPSPosition_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [in] */ long ValX,
    /* [in] */ long ValY,
    /* [out] */ long __RPC_FAR *pFixX,
    /* [out] */ long __RPC_FAR *pFixY,
    /* [out] */ BSTR __RPC_FAR *bstrRoad);


void __RPC_STUB IMapObject_FixGPSPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMapObject_GetMapBitmap_Proxy( 
    IMapObject __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pVal);


void __RPC_STUB IMapObject_GetMapBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMapObject_INTERFACE_DEFINED__ */



#ifndef __PPGSDK50Lib_LIBRARY_DEFINED__
#define __PPGSDK50Lib_LIBRARY_DEFINED__

/* library PPGSDK50Lib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_PPGSDK50Lib;

EXTERN_C const CLSID CLSID_MapObject;

#ifdef __cplusplus

class DECLSPEC_UUID("A83D2D9C-1FFE-4044-8B9D-D4CB173AA163")
MapObject;
#endif
#endif /* __PPGSDK50Lib_LIBRARY_DEFINED__ */

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
