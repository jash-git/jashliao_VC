/* PDFlib GmbH cvsid: $Id: tiffvers.h,v 1.5 2004/03/26 18:36:54 rjs Exp $ */

#define TIFFLIB_VERSION_STR "LIBTIFF, Version 3.6.1\n\
Copyright (c) 1988-1996 Sam Leffler\n\
Copyright (c) 1991-1996 Silicon Graphics, Inc."
/*
 * This define can be used in code that requires
 * compilation-related definitions specific to a
 * version or versions of the library.  Runtime
 * version checking should be done based on the
 * string returned by TIFFGetVersion.
 */
#define TIFFLIB_VERSION 20031226
