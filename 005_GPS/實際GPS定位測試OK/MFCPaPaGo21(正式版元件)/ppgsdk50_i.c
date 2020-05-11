/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Nov 16 11:18:12 2004
 */
/* Compiler settings for F:\WorkDisk\MyScheme\200411\Project\ATL\PaPaGOSDK_V5\ppgsdk50\ppgsdk50.idl:
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

const IID IID_IMapObject = {0x28A525FE,0x7DD2,0x4667,{0xA5,0x85,0x79,0x0D,0x66,0x65,0x36,0x3F}};


const IID LIBID_PPGSDK50Lib = {0x4CC21C03,0x04FC,0x4CA6,{0x8F,0x6E,0xE0,0xD4,0x07,0xC7,0x02,0x20}};


const CLSID CLSID_MapObject = {0xA83D2D9C,0x1FFE,0x4044,{0x8B,0x9D,0xD4,0xCB,0x17,0x3A,0xA1,0x63}};


#ifdef __cplusplus
}
#endif

