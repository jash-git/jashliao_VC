/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 18 16:42:10 2005
 */
/* Compiler settings for D:\SDK 專案開發\PaPaGO! SDK V5\SDK 1.3 Source\SDK for PC\BmpSDK_V5\bmpsdkv5\bmpsdkv5.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IDrawObject = {0x13C8F52D,0x7182,0x4B98,{0xAE,0x5B,0xA5,0x92,0xF5,0xC3,0xE1,0x05}};


const IID LIBID_BMPSDKV5Lib = {0x9BF776CB,0x98C6,0x41E0,{0x81,0x5B,0x43,0xCE,0x67,0x7D,0xAE,0x16}};


const CLSID CLSID_DrawObject = {0x13FC7CD6,0x1732,0x4607,{0x93,0x80,0xB5,0xE6,0x67,0x49,0xA2,0xAC}};


#ifdef __cplusplus
}
#endif

