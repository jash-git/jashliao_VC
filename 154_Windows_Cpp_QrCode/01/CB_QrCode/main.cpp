#include <iostream>
#include <string.h>
#include <stdio.h>
#include "BitmapImage.h"
#include "bssQRCodeGenerator.h"

using namespace std;


int main( int argc, char* argv[] )
{
    //
    // Check command line
    //
    if( argc != 3 )//if( argc != 3 || strcmp( argv[ 1 ], "?" ) == 0 )
    {
        cout << "Usage: BSSDemoAppCon <barcode content> <output filename>" << endl;
        return 0;
    }

    string Content  = argv[ argc - 2 ];
    string FileName = argv[ argc - 1 ];


    //
    // Start generation
    //

    int iHeight     = 0;
    int iWidth      = 0;
    int iRowStride  = 0;
    void* pvImage   = NULL;

    int nRes = BSS_GenerateQRCode( Content.c_str(),
                                   Content.length(),
                                   3,
                                   4,
                                   &pvImage,
                                   &iWidth,
                                   &iHeight,
                                   &iRowStride );

    //
    // Output results
    //

    if( nRes == BSSG_QRCODE_OK )
    {
        cout << "Barcode generation: SUCCESS" << endl;
    }
    else
    {
        cout << "Barcode generation: FAILURE" << endl;
    }

    switch( nRes )
    {
        case BSSG_QRCODE_ERR_GENERIC:
             cerr << endl << "Note: Generic error code. The library doesn̿ clarify or cannot determine what is happening." << endl;
             break;
        case BSSG_QRCODE_ERR_OUTOFMEMORY:
             cerr << endl << "Note: Ran out of memory. Some allocation failed." << endl;
             break;
        case BSSG_QRCODE_ERR_NOTSUPPORTED:
             cerr << endl << "Note: The feature requested is not supported." << endl;
             break;
        case BSSG_QRCODE_ERR_INVALIDARGS:
             cerr << endl << "Note: Argument validation failed." << endl;
             break;
        case BSSG_QRCODE_ERR_OUTOFSYMBOLOGY:
             cerr << endl << "Note: Cannot create the barcode symbol that would be contain this specified input data string by the reason of  some bar code symbology limitation (one or more characters from input data string do not belong  to symbology character set, input data string is too long, etc.)" << endl;
             break;
    }

    if( nRes != BSSG_QRCODE_OK )
        return 0;


    //
    // Save the barcode image into the file
    //
    unsigned char* pImage = static_cast<unsigned char*>( pvImage );

    CBitmapImage Image;
    Image.Attach( pImage, iWidth, iHeight, iRowStride );

    if( Image.Save8bppBitmap( FileName ) )
    {
        cerr << endl << "I/O Error: Unable to open the output file." << endl;
    }

    Image.Detach();


    //
    // Release allocated resources
    //

    BSS_ReleaseQRCodeImage( pvImage, iHeight, iWidth, iRowStride );

    return nRes;
}
