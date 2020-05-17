#ifndef _BSS_QRCODE_GENERATOR_H_
#define _BSS_QRCODE_GENERATOR_H_


/*
// Import/Export support
*/

#if defined(_MSC_VER) && defined(_BSS_QRCODE_DLL)
#if defined(_BSS_QRCODE_EXPORTS)
#define BSS_DLL __declspec(dllexport)
#else
#define BSS_DLL __declspec(dllimport)
#endif
#else
#define BSS_DLL
#endif

#ifdef __cplusplus
extern "C" {
#endif


/*
// Definitions of return codes
*/

#define BSSG_QRCODE_OK                 ( 0)
#define BSSG_QRCODE_ERR_GENERIC        (-1)
#define BSSG_QRCODE_ERR_OUTOFMEMORY    (-2)
#define BSSG_QRCODE_ERR_NOTSUPPORTED   (-3)
#define BSSG_QRCODE_ERR_INVALIDARGS    (-4)
#define BSSG_QRCODE_ERR_OUTOFSYMBOLOGY (-5)

/* 
// Generate QRCode barcode symbol
*/
BSS_DLL int BSS_GenerateQRCode
(
    const char*        pchData,       /* Barcode data for encoding                */
    int                nDataLength,   /* Barcode data length                      */
    int                nModSize,      /* Barcode module size (in pixels)          */
    int                nRowDistMult,  /* Desired row distance multiplier          */
    void**             ppImgData,     /* Pointer to image data pointer            */
    int*               pnImgWidth,    /* Pointer to image width                   */
    int*               pnImgHeight,   /* Pointer to image height                  */
    int*               pnImgRowDist   /* Pointer to distance between image's rows */
);

/* 
// Release allocated resources 
*/
BSS_DLL int BSS_ReleaseQRCodeImage
(
    void*              pImgData,      /* Pointer to barcode's image data          */
    int                nImgWidth,     /* Image width                              */
    int                nImgHeight,    /* Image height                             */
    int                nImgRowDist    /* Distance between image's rows (in bytes) */
);

#ifdef __cplusplus
}       /* extern "C" */
#endif

#endif /* _BSS_QRCODE_GENERATOR_H_ */
