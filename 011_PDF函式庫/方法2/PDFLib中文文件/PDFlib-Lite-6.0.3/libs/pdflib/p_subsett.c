/*---------------------------------------------------------------------------*
 |              PDFlib - A library for generating PDF on the fly             |
 +---------------------------------------------------------------------------+
 | Copyright (c) 1997-2005 Thomas Merz and PDFlib GmbH. All rights reserved. |
 +---------------------------------------------------------------------------+
 |                                                                           |
 |    This software is subject to the PDFlib license. It is NOT in the       |
 |    public domain. Extended versions and commercial licenses are           |
 |    available, please check http://www.pdflib.com.                         |
 |                                                                           |
 *---------------------------------------------------------------------------*/

/* $Id: p_subsett.c,v 1.58.2.23 2006/01/09 14:22:30 kurt Exp $
 *
 * PDFlib subsetting routines
 *
 */

#include <time.h>

#include "p_intern.h"
#include "p_font.h"
#include "p_truetype.h"

#include "pc_md5.h"

