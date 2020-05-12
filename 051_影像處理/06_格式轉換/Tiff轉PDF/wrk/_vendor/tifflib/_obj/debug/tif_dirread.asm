	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_dirread.c
	.386P
include listing.inc
if @Version gt 510
.model FLAT
else
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
_DATA	SEGMENT DWORD USE32 PUBLIC 'DATA'
_DATA	ENDS
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
_BSS	SEGMENT DWORD USE32 PUBLIC 'BSS'
_BSS	ENDS
$$SYMBOLS	SEGMENT BYTE USE32 'DEBSYM'
$$SYMBOLS	ENDS
$$TYPES	SEGMENT BYTE USE32 'DEBTYP'
$$TYPES	ENDS
_TLS	SEGMENT DWORD USE32 PUBLIC 'TLS'
_TLS	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
CONST	SEGMENT
_?mesg@?1??TIFFFetchNormalTag@@9@9 DB 'to fetch tag value', 00H
	ORG $+1
_?mesg@?1??TIFFFetchRefBlackWhite@@9@9 DB 'for "ReferenceBlackWhite" arra'
	DB	'y', 00H
CONST	ENDS
PUBLIC	_TIFFReadDirectory
EXTRN	__fltused:NEAR
EXTRN	_TIFFFreeDirectory:NEAR
EXTRN	_TIFFDefaultDirectory:NEAR
EXTRN	__TIFFmemcpy:NEAR
EXTRN	__TIFFfree:NEAR
EXTRN	_TIFFScanlineSize:NEAR
EXTRN	_TIFFTileSize:NEAR
EXTRN	_TIFFSetField:NEAR
EXTRN	_TIFFReassignTagToIgnore:NEAR
EXTRN	_TIFFError:NEAR
EXTRN	_TIFFWarning:NEAR
EXTRN	_TIFFNumberOfTiles:NEAR
EXTRN	_TIFFNumberOfStrips:NEAR
EXTRN	_TIFFSwabShort:NEAR
EXTRN	_TIFFSwabLong:NEAR
EXTRN	_TIFFSwabArrayOfShort:NEAR
EXTRN	_TIFFSwabArrayOfLong:NEAR
EXTRN	__TIFFFieldWithTag:NEAR
_DATA	SEGMENT
$SG65889 DB	'Seek error accessing TIFF directory', 00H
$SG65896 DB	'Can not read TIFF directory count', 00H
	ORG $+2
$SG65900 DB	'to read TIFF directory', 00H
	ORG $+1
$SG65909 DB	'Can not read TIFF directory', 00H
$SG65921 DB	'Can not read TIFF directory count', 00H
	ORG $+2
$SG65928 DB	'to read TIFF directory', 00H
	ORG $+1
$SG65933 DB	'Can not read TIFF directory', 00H
$SG65954 DB	'invalid TIFF directory; tags are not sorted in ascending'
	DB	' order', 00H
	ORG $+1
$SG65960 DB	'unknown field with tag %d (0x%x) ignored', 00H
	ORG $+3
$SG65970 DB	'wrong data type %d for "%s"; tag ignored', 00H
	ORG $+3
$SG65995 DB	'ImageLength', 00H
$SG65998 DB	'PlanarConfiguration', 00H
$SG66005 DB	'TileOffsets', 00H
$SG66006 DB	'StripOffsets', 00H
	ORG $+3
$SG66038 DB	'to read "TransferFunction" tag', 00H
	ORG $+1
$SG66064 DB	'Colormap', 00H
	ORG $+3
$SG66070 DB	'StripByteCounts', 00H
$SG66071 DB	'TIFF directory is missing required "%s" field, calculati'
	DB	'ng from imagelength', 00H
$SG66077 DB	'Bogus "%s" field, ignoring and calculating from imagelen'
	DB	'gth', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_dp$ = -28
_n$ = -56
_td$ = -36
_dir$ = -52
_iv$ = -8
_v$ = -24
_dv$ = -48
_fip$ = -40
_fix$ = -20
_dircount$ = -32
_nextdiroff$ = -4
_cp$ = -16
_diroutoforderwarning$ = -12
_off$65918 = -60
_expected$65972 = -64
_c$66042 = -68
_TIFFReadDirectory PROC NEAR

; 80   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 100				; 00000064H
	push	esi

; 81   : 	register TIFFDirEntry* dp;
; 82   : 	register int n;
; 83   : 	register TIFFDirectory* td;
; 84   : 	TIFFDirEntry* dir;
; 85   : 	int iv;
; 86   : 	long v;
; 87   : 	double dv;
; 88   : 	const TIFFFieldInfo* fip;
; 89   : 	int fix;
; 90   : 	uint16 dircount;
; 91   : 	toff_t nextdiroff;
; 92   : 	char* cp;
; 93   : 	int diroutoforderwarning = 0;

	mov	DWORD PTR _diroutoforderwarning$[ebp], 0

; 94   : 
; 95   : 	tif->tif_diroff = tif->tif_nextdiroff;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+20]
	mov	DWORD PTR [eax+16], edx

; 96   : 	if (tif->tif_diroff == 0)		/* no more directories */

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+16], 0
	jne	SHORT $L65883

; 97   : 		return (0);

	xor	eax, eax
	jmp	$L65869
$L65883:

; 98   : 	/*
; 99   : 	 * Cleanup any previous compression state.
; 100  : 	 */
; 101  : 	(*tif->tif_cleanup)(tif);

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+448]
	add	esp, 4

; 102  : 	tif->tif_curdir++;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	cx, WORD PTR [eax+360]
	add	cx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	WORD PTR [edx+360], cx

; 103  : 	nextdiroff = 0;

	mov	DWORD PTR _nextdiroff$[ebp], 0

; 104  : 	if (!isMapped(tif)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 2048				; 00000800H
	test	ecx, ecx
	jne	$L65884

; 105  : 		if (!SeekOK(tif, tif->tif_diroff)) {

	push	0
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+516]
	add	esp, 12					; 0000000cH
	mov	ecx, DWORD PTR _tif$[ebp]
	cmp	eax, DWORD PTR [ecx+16]
	je	SHORT $L65888

; 106  : 			TIFFError(tif->tif_name,
; 107  : 			    "Seek error accessing TIFF directory");

	push	OFFSET FLAT:$SG65889
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 8

; 108  : 			return (0);

	xor	eax, eax
	jmp	$L65869
$L65888:

; 110  : 		if (!ReadOK(tif, &dircount, sizeof (uint16))) {

	push	2
	lea	ecx, DWORD PTR _dircount$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+504]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+508]
	add	esp, 12					; 0000000cH
	cmp	eax, 2
	je	SHORT $L65895

; 111  : 			TIFFError(tif->tif_name,
; 112  : 			    "Can not read TIFF directory count");

	push	OFFSET FLAT:$SG65896
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 8

; 113  : 			return (0);

	xor	eax, eax
	jmp	$L65869
$L65895:

; 115  : 		if (tif->tif_flags & TIFF_SWAB)

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 128				; 00000080H
	test	edx, edx
	je	SHORT $L65897

; 116  : 			TIFFSwabShort(&dircount);

	lea	eax, DWORD PTR _dircount$[ebp]
	push	eax
	call	_TIFFSwabShort
	add	esp, 4
$L65897:

; 117  : 		dir = (TIFFDirEntry *)CheckMalloc(tif,
; 118  : 		    dircount * sizeof (TIFFDirEntry), "to read TIFF directory");

	push	OFFSET FLAT:$SG65900
	mov	ecx, DWORD PTR _dircount$[ebp]
	and	ecx, 65535				; 0000ffffH
	imul	ecx, 12					; 0000000cH
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_CheckMalloc
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _dir$[ebp], eax

; 119  : 		if (dir == NULL)

	cmp	DWORD PTR _dir$[ebp], 0
	jne	SHORT $L65902

; 120  : 			return (0);

	xor	eax, eax
	jmp	$L65869
$L65902:

; 121  : 		if (!ReadOK(tif, dir, dircount*sizeof (TIFFDirEntry))) {

	mov	eax, DWORD PTR _dircount$[ebp]
	and	eax, 65535				; 0000ffffH
	imul	eax, 12					; 0000000cH
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+504]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+508]
	add	esp, 12					; 0000000cH
	mov	edx, DWORD PTR _dircount$[ebp]
	and	edx, 65535				; 0000ffffH
	imul	edx, 12					; 0000000cH
	cmp	eax, edx
	je	SHORT $L65908

; 122  : 			TIFFError(tif->tif_name, "Can not read TIFF directory");

	push	OFFSET FLAT:$SG65909
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 8

; 123  : 			goto bad;

	jmp	$bad$65910
$L65908:

; 125  : 		/*
; 126  : 		 * Read offset to next directory for sequential scans.
; 127  : 		 */
; 128  : 		(void) ReadOK(tif, &nextdiroff, sizeof (uint32));

	push	4
	lea	edx, DWORD PTR _nextdiroff$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+508]
	add	esp, 12					; 0000000cH

; 129  : 	} else {

	jmp	$L65938
$L65884:

; 130  : 		toff_t off = tif->tif_diroff;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	mov	DWORD PTR _off$65918[ebp], ecx

; 131  : 
; 132  : 		if (off + sizeof (uint16) > tif->tif_size) {

	mov	edx, DWORD PTR _off$65918[ebp]
	add	edx, 2
	mov	eax, DWORD PTR _tif$[ebp]
	cmp	edx, DWORD PTR [eax+492]
	jbe	SHORT $L65920

; 133  : 			TIFFError(tif->tif_name,
; 134  : 			    "Can not read TIFF directory count");

	push	OFFSET FLAT:$SG65921
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 8

; 135  : 			return (0);

	xor	eax, eax
	jmp	$L65869
$L65920:

; 137  : 			_TIFFmemcpy(&dircount, tif->tif_base + off, sizeof (uint16));

	push	2
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+488]
	add	ecx, DWORD PTR _off$65918[ebp]
	push	ecx
	lea	edx, DWORD PTR _dircount$[ebp]
	push	edx
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH

; 138  : 		off += sizeof (uint16);

	mov	eax, DWORD PTR _off$65918[ebp]
	add	eax, 2
	mov	DWORD PTR _off$65918[ebp], eax

; 139  : 		if (tif->tif_flags & TIFF_SWAB)

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 128				; 00000080H
	test	edx, edx
	je	SHORT $L65925

; 140  : 			TIFFSwabShort(&dircount);

	lea	eax, DWORD PTR _dircount$[ebp]
	push	eax
	call	_TIFFSwabShort
	add	esp, 4
$L65925:

; 141  : 		dir = (TIFFDirEntry *)CheckMalloc(tif,
; 142  : 		    dircount * sizeof (TIFFDirEntry), "to read TIFF directory");

	push	OFFSET FLAT:$SG65928
	mov	ecx, DWORD PTR _dircount$[ebp]
	and	ecx, 65535				; 0000ffffH
	imul	ecx, 12					; 0000000cH
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_CheckMalloc
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _dir$[ebp], eax

; 143  : 		if (dir == NULL)

	cmp	DWORD PTR _dir$[ebp], 0
	jne	SHORT $L65930

; 144  : 			return (0);

	xor	eax, eax
	jmp	$L65869
$L65930:

; 145  : 		if (off + dircount*sizeof (TIFFDirEntry) > tif->tif_size) {

	mov	eax, DWORD PTR _dircount$[ebp]
	and	eax, 65535				; 0000ffffH
	imul	eax, 12					; 0000000cH
	mov	ecx, DWORD PTR _off$65918[ebp]
	add	ecx, eax
	mov	edx, DWORD PTR _tif$[ebp]
	cmp	ecx, DWORD PTR [edx+492]
	jbe	SHORT $L65932

; 146  : 			TIFFError(tif->tif_name, "Can not read TIFF directory");

	push	OFFSET FLAT:$SG65933
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 8

; 147  : 			goto bad;

	jmp	$bad$65910
$L65932:

; 149  : 			_TIFFmemcpy(dir, tif->tif_base + off,
; 150  : 			    dircount*sizeof (TIFFDirEntry));

	mov	edx, DWORD PTR _dircount$[ebp]
	and	edx, 65535				; 0000ffffH
	imul	edx, 12					; 0000000cH
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+488]
	add	ecx, DWORD PTR _off$65918[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH

; 151  : 		off += dircount* sizeof (TIFFDirEntry);

	mov	eax, DWORD PTR _dircount$[ebp]
	and	eax, 65535				; 0000ffffH
	imul	eax, 12					; 0000000cH
	mov	ecx, DWORD PTR _off$65918[ebp]
	add	ecx, eax
	mov	DWORD PTR _off$65918[ebp], ecx

; 152  : 		if (off + sizeof (uint32) <= tif->tif_size)

	mov	edx, DWORD PTR _off$65918[ebp]
	add	edx, 4
	mov	eax, DWORD PTR _tif$[ebp]
	cmp	edx, DWORD PTR [eax+492]
	ja	SHORT $L65938

; 153  : 			_TIFFmemcpy(&nextdiroff, tif->tif_base+off, sizeof (uint32));

	push	4
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+488]
	add	edx, DWORD PTR _off$65918[ebp]
	push	edx
	lea	eax, DWORD PTR _nextdiroff$[ebp]
	push	eax
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH
$L65938:

; 155  : 	if (tif->tif_flags & TIFF_SWAB)

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 128				; 00000080H
	test	edx, edx
	je	SHORT $L65940

; 156  : 		TIFFSwabLong(&nextdiroff);

	lea	eax, DWORD PTR _nextdiroff$[ebp]
	push	eax
	call	_TIFFSwabLong
	add	esp, 4
$L65940:

; 157  : 	tif->tif_nextdiroff = nextdiroff;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _nextdiroff$[ebp]
	mov	DWORD PTR [ecx+20], edx

; 158  : 
; 159  : 	tif->tif_flags &= ~TIFF_BEENWRITING;	/* reset before new dir */

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, -65				; ffffffbfH
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx

; 160  : 	/*
; 161  : 	 * Setup default value and then make a pass over
; 162  : 	 * the fields to check type and tag information,
; 163  : 	 * and to extract info required to size data
; 164  : 	 * structures.  A second pass is made afterwards
; 165  : 	 * to read in everthing not taken in the first pass.
; 166  : 	 */
; 167  : 	td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 168  : 	/* free any old stuff and reinit */
; 169  : 	TIFFFreeDirectory(tif);

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFreeDirectory
	add	esp, 4

; 170  : 	TIFFDefaultDirectory(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFDefaultDirectory
	add	esp, 4

; 171  : 	/*
; 172  : 	 * Electronic Arts writes gray-scale TIFF files
; 173  : 	 * without a PlanarConfiguration directory entry.
; 174  : 	 * Thus we setup a default value here, even though
; 175  : 	 * the TIFF spec says there is no default value.
; 176  : 	 */
; 177  : 	TIFFSetField(tif, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);

	push	1
	push	284					; 0000011cH
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFSetField
	add	esp, 12					; 0000000cH

; 178  : 
; 179  : 	/*
; 180  : 	 * Sigh, we must make a separate pass through the
; 181  : 	 * directory for the following reason:
; 182  : 	 *
; 183  : 	 * We must process the Compression tag in the first pass
; 184  : 	 * in order to merge in codec-private tag definitions (otherwise
; 185  : 	 * we may get complaints about unknown tags).  However, the
; 186  : 	 * Compression tag may be dependent on the SamplesPerPixel
; 187  : 	 * tag value because older TIFF specs permited Compression
; 188  : 	 * to be written as a SamplesPerPixel-count tag entry.
; 189  : 	 * Thus if we don't first figure out the correct SamplesPerPixel
; 190  : 	 * tag value then we may end up ignoring the Compression tag
; 191  : 	 * value because it has an incorrect count value (if the
; 192  : 	 * true value of SamplesPerPixel is not 1).
; 193  : 	 *
; 194  : 	 * It sure would have been nice if Aldus had really thought
; 195  : 	 * this stuff through carefully.
; 196  : 	 */ 
; 197  : 	for (dp = dir, n = dircount; n > 0; n--, dp++) {

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	DWORD PTR _dp$[ebp], ecx
	mov	edx, DWORD PTR _dircount$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	DWORD PTR _n$[ebp], edx
	jmp	SHORT $L65941
$L65942:
	mov	eax, DWORD PTR _n$[ebp]
	sub	eax, 1
	mov	DWORD PTR _n$[ebp], eax
	mov	ecx, DWORD PTR _dp$[ebp]
	add	ecx, 12					; 0000000cH
	mov	DWORD PTR _dp$[ebp], ecx
$L65941:
	cmp	DWORD PTR _n$[ebp], 0
	jle	SHORT $L65943

; 198  : 		if (tif->tif_flags & TIFF_SWAB) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 128				; 00000080H
	test	eax, eax
	je	SHORT $L65944

; 199  : 			TIFFSwabArrayOfShort(&dp->tdir_tag, 2);

	push	2
	mov	ecx, DWORD PTR _dp$[ebp]
	push	ecx
	call	_TIFFSwabArrayOfShort
	add	esp, 8

; 200  : 			TIFFSwabArrayOfLong(&dp->tdir_count, 2);

	push	2
	mov	edx, DWORD PTR _dp$[ebp]
	add	edx, 4
	push	edx
	call	_TIFFSwabArrayOfLong
	add	esp, 8
$L65944:

; 202  : 		if (dp->tdir_tag == TIFFTAG_SAMPLESPERPIXEL) {

	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	cmp	ecx, 277				; 00000115H
	jne	SHORT $L65945

; 203  : 			if (!TIFFFetchNormalTag(tif, dp))

	mov	edx, DWORD PTR _dp$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchNormalTag
	add	esp, 8
	test	eax, eax
	jne	SHORT $L65946

; 204  : 				goto bad;

	jmp	$bad$65910
$L65946:

; 205  : 			dp->tdir_tag = IGNORE;

	mov	ecx, DWORD PTR _dp$[ebp]
	mov	WORD PTR [ecx], 0
$L65945:

; 207  : 	}

	jmp	SHORT $L65942
$L65943:

; 208  : 	/*
; 209  : 	 * First real pass over the directory.
; 210  : 	 */
; 211  : 	fix = 0;

	mov	DWORD PTR _fix$[ebp], 0

; 212  : 	for (dp = dir, n = dircount; n > 0; n--, dp++) {

	mov	edx, DWORD PTR _dir$[ebp]
	mov	DWORD PTR _dp$[ebp], edx
	mov	eax, DWORD PTR _dircount$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	DWORD PTR _n$[ebp], eax
	jmp	SHORT $L65947
$L65948:
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	mov	edx, DWORD PTR _dp$[ebp]
	add	edx, 12					; 0000000cH
	mov	DWORD PTR _dp$[ebp], edx
$L65947:
	cmp	DWORD PTR _n$[ebp], 0
	jle	$L65949

; 213  : 
; 214  :                 /*
; 215  :                  * Find the field information entry for this tag.
; 216  : 		 * Added check for tags to ignore ... [BFC]
; 217  :                  */
; 218  : 		if( TIFFReassignTagToIgnore(TIS_EXTRACT, dp->tdir_tag) )

	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	push	ecx
	push	1
	call	_TIFFReassignTagToIgnore
	add	esp, 8
	test	eax, eax
	je	SHORT $L65950

; 219  :                     dp->tdir_tag = IGNORE;

	mov	edx, DWORD PTR _dp$[ebp]
	mov	WORD PTR [edx], 0
$L65950:

; 220  : 
; 221  : 		if (dp->tdir_tag == IGNORE)

	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	test	ecx, ecx
	jne	SHORT $L65951

; 222  :                     continue;

	jmp	SHORT $L65948
$L65951:

; 223  :                 
; 224  : 		/*
; 225  : 		 * Silicon Beach (at least) writes unordered
; 226  : 		 * directory tags (violating the spec).  Handle
; 227  : 		 * it here, but be obnoxious (maybe they'll fix it?).
; 228  : 		 */
; 229  : 		if (dp->tdir_tag < tif->tif_fieldinfo[fix]->field_tag) {

	mov	edx, DWORD PTR _dp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+532]
	mov	ecx, DWORD PTR _fix$[ebp]
	mov	edx, DWORD PTR [edx+ecx*4]
	cmp	eax, DWORD PTR [edx]
	jae	SHORT $L65952

; 230  : 			if (!diroutoforderwarning) {

	cmp	DWORD PTR _diroutoforderwarning$[ebp], 0
	jne	SHORT $L65953

; 231  : 				TIFFWarning(tif->tif_name,
; 232  : 	"invalid TIFF directory; tags are not sorted in ascending order");

	push	OFFSET FLAT:$SG65954
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFWarning
	add	esp, 8

; 233  : 				diroutoforderwarning = 1;

	mov	DWORD PTR _diroutoforderwarning$[ebp], 1
$L65953:

; 235  : 			fix = 0;			/* O(n^2) */

	mov	DWORD PTR _fix$[ebp], 0
$L65952:

; 237  : 		while (fix < tif->tif_nfields &&
; 238  : 		    tif->tif_fieldinfo[fix]->field_tag < dp->tdir_tag)

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _fix$[ebp]
	cmp	eax, DWORD PTR [edx+536]
	jge	SHORT $L65957
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+532]
	mov	eax, DWORD PTR _fix$[ebp]
	mov	ecx, DWORD PTR [edx+eax*4]
	mov	edx, DWORD PTR _dp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	cmp	DWORD PTR [ecx], eax
	jae	SHORT $L65957

; 239  : 			fix++;

	mov	ecx, DWORD PTR _fix$[ebp]
	add	ecx, 1
	mov	DWORD PTR _fix$[ebp], ecx
	jmp	SHORT $L65952
$L65957:

; 240  : 		if (fix == tif->tif_nfields ||
; 241  : 		    tif->tif_fieldinfo[fix]->field_tag != dp->tdir_tag) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _fix$[ebp]
	cmp	eax, DWORD PTR [edx+536]
	je	SHORT $L65959
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+532]
	mov	eax, DWORD PTR _fix$[ebp]
	mov	ecx, DWORD PTR [edx+eax*4]
	mov	edx, DWORD PTR _dp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	cmp	DWORD PTR [ecx], eax
	je	SHORT $L65958
$L65959:

; 242  : 			TIFFWarning(tif->tif_name,
; 243  : 			    "unknown field with tag %d (0x%x) ignored",
; 244  : 			    dp->tdir_tag,  dp->tdir_tag);

	mov	ecx, DWORD PTR _dp$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG65960
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFWarning
	add	esp, 16					; 00000010H

; 245  : 			dp->tdir_tag = IGNORE;

	mov	ecx, DWORD PTR _dp$[ebp]
	mov	WORD PTR [ecx], 0

; 246  : 			fix = 0;			/* restart search */

	mov	DWORD PTR _fix$[ebp], 0

; 247  : 			continue;

	jmp	$L65948
$L65958:

; 249  : 		/*
; 250  : 		 * Null out old tags that we ignore.
; 251  : 		 */
; 252  : 		if (tif->tif_fieldinfo[fix]->field_bit == FIELD_IGNORE) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+532]
	mov	ecx, DWORD PTR _fix$[ebp]
	mov	edx, DWORD PTR [eax+ecx*4]
	xor	eax, eax
	mov	ax, WORD PTR [edx+12]
	test	eax, eax
	jne	SHORT $L65961
$ignore$65962:

; 253  : 	ignore:
; 254  : 			dp->tdir_tag = IGNORE;

	mov	ecx, DWORD PTR _dp$[ebp]
	mov	WORD PTR [ecx], 0

; 255  : 			continue;

	jmp	$L65948
$L65961:

; 257  : 		/*
; 258  : 		 * Check data type.
; 259  : 		 */
; 260  : 		fip = tif->tif_fieldinfo[fix];

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+532]
	mov	ecx, DWORD PTR _fix$[ebp]
	mov	edx, DWORD PTR [eax+ecx*4]
	mov	DWORD PTR _fip$[ebp], edx
$L65965:

; 261  : 		while (dp->tdir_type != (u_short) fip->field_type) {

	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+2]
	mov	edx, DWORD PTR _fip$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+8]
	cmp	ecx, eax
	je	SHORT $L65966

; 262  : 			if (fip->field_type == TIFF_ANY)	/* wildcard */

	mov	ecx, DWORD PTR _fip$[ebp]
	cmp	DWORD PTR [ecx+8], 0
	jne	SHORT $L65967

; 263  : 				break;

	jmp	SHORT $L65966
$L65967:

; 264  : 			fip++, fix++;

	mov	edx, DWORD PTR _fip$[ebp]
	add	edx, 20					; 00000014H
	mov	DWORD PTR _fip$[ebp], edx
	mov	eax, DWORD PTR _fix$[ebp]
	add	eax, 1
	mov	DWORD PTR _fix$[ebp], eax

; 265  : 			if (fix == tif->tif_nfields ||
; 266  : 			    fip->field_tag != dp->tdir_tag) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _fix$[ebp]
	cmp	edx, DWORD PTR [ecx+536]
	je	SHORT $L65969
	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	mov	edx, DWORD PTR _fip$[ebp]
	cmp	DWORD PTR [edx], ecx
	je	SHORT $L65968
$L65969:

; 267  : 				TIFFWarning(tif->tif_name,
; 268  : 				   "wrong data type %d for \"%s\"; tag ignored",
; 269  : 				    dp->tdir_type, fip[-1].field_name);

	mov	eax, DWORD PTR _fip$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	push	ecx
	mov	edx, DWORD PTR _dp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+2]
	push	eax
	push	OFFSET FLAT:$SG65970
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFWarning
	add	esp, 16					; 00000010H

; 270  : 				goto ignore;

	jmp	$ignore$65962
$L65968:

; 272  : 		}

	jmp	SHORT $L65965
$L65966:

; 273  : 		/*
; 274  : 		 * Check count if known in advance.
; 275  : 		 */
; 276  : 		if (fip->field_readcount != TIFF_VARIABLE) {

	mov	eax, DWORD PTR _fip$[ebp]
	movsx	ecx, WORD PTR [eax+4]
	cmp	ecx, -1
	je	SHORT $L65975

; 277  : 			uint32 expected = (fip->field_readcount == TIFF_SPP) ?
; 278  : 			    (uint32) td->td_samplesperpixel :
; 279  : 			    (uint32) fip->field_readcount;

	mov	edx, DWORD PTR _fip$[ebp]
	movsx	eax, WORD PTR [edx+4]
	cmp	eax, -2					; fffffffeH
	jne	SHORT $L66680
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+54]
	mov	DWORD PTR -72+[ebp], edx
	jmp	SHORT $L66681
$L66680:
	mov	eax, DWORD PTR _fip$[ebp]
	movsx	ecx, WORD PTR [eax+4]
	mov	DWORD PTR -72+[ebp], ecx
$L66681:
	mov	edx, DWORD PTR -72+[ebp]
	mov	DWORD PTR _expected$65972[ebp], edx

; 280  : 			if (!CheckDirCount(tif, dp, expected))

	mov	eax, DWORD PTR _expected$65972[ebp]
	push	eax
	mov	ecx, DWORD PTR _dp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_CheckDirCount
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65975

; 281  : 				goto ignore;

	jmp	$ignore$65962
$L65975:

; 283  : 
; 284  : 		switch (dp->tdir_tag) {

	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	mov	DWORD PTR -76+[ebp], ecx
	cmp	DWORD PTR -76+[ebp], 284		; 0000011cH
	jg	SHORT $L66684
	cmp	DWORD PTR -76+[ebp], 284		; 0000011cH
	je	$L65989
	mov	edx, DWORD PTR -76+[ebp]
	sub	edx, 256				; 00000100H
	mov	DWORD PTR -76+[ebp], edx
	cmp	DWORD PTR -76+[ebp], 23			; 00000017H
	ja	$L65977
	mov	ecx, DWORD PTR -76+[ebp]
	xor	eax, eax
	mov	al, BYTE PTR $L66694[ecx]
	jmp	DWORD PTR $L66695[eax*4]
$L66684:
	cmp	DWORD PTR -76+[ebp], 338		; 00000152H
	jg	SHORT $L66685
	cmp	DWORD PTR -76+[ebp], 338		; 00000152H
	je	$L65991
	mov	edx, DWORD PTR -76+[ebp]
	sub	edx, 322				; 00000142H
	mov	DWORD PTR -76+[ebp], edx
	cmp	DWORD PTR -76+[ebp], 3
	ja	$L65977
	mov	eax, DWORD PTR -76+[ebp]
	jmp	DWORD PTR $L66696[eax*4]
$L66685:
	cmp	DWORD PTR -76+[ebp], 32997		; 000080e5H
	jl	$L65977
	cmp	DWORD PTR -76+[ebp], 32998		; 000080e6H
	jle	$L65989
	jmp	$L65977
$L65980:

; 285  : 		case TIFFTAG_COMPRESSION:
; 286  : 			/*
; 287  : 			 * The 5.0 spec says the Compression tag has
; 288  : 			 * one value, while earlier specs say it has
; 289  : 			 * one value per sample.  Because of this, we
; 290  : 			 * accept the tag if one value is supplied.
; 291  : 			 */
; 292  : 			if (dp->tdir_count == 1) {

	mov	ecx, DWORD PTR _dp$[ebp]
	cmp	DWORD PTR [ecx+4], 1
	jne	$L65981

; 293  : 				v = TIFFExtractData(tif,
; 294  : 				    dp->tdir_type, dp->tdir_offset);

	mov	edx, DWORD PTR _tif$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+336]
	cmp	eax, 19789				; 00004d4dH
	jne	SHORT $L66682
	mov	ecx, DWORD PTR _dp$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+2]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+348]
	mov	eax, DWORD PTR _dp$[ebp]
	mov	eax, DWORD PTR [eax+8]
	mov	ecx, DWORD PTR [ecx+edx*4]
	shr	eax, cl
	mov	ecx, DWORD PTR _dp$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+2]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [ecx+352]
	and	eax, DWORD PTR [ecx+edx*4]
	mov	DWORD PTR -80+[ebp], eax
	jmp	SHORT $L66683
$L66682:
	mov	edx, DWORD PTR _dp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+2]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+352]
	mov	ecx, DWORD PTR _dp$[ebp]
	mov	ecx, DWORD PTR [ecx+8]
	and	ecx, DWORD PTR [edx+eax*4]
	mov	DWORD PTR -80+[ebp], ecx
$L66683:
	mov	edx, DWORD PTR -80+[ebp]
	mov	DWORD PTR _v$[ebp], edx

; 295  : 				if (!TIFFSetField(tif, dp->tdir_tag, (int)v))

	mov	eax, DWORD PTR _v$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dp$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFSetField
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65984

; 296  : 					goto bad;

	jmp	$bad$65910
$L65984:

; 297  : 				break;

	jmp	$L65977
$L65981:

; 299  : 			if (!TIFFFetchPerSampleShorts(tif, dp, &iv) ||
; 300  : 			    !TIFFSetField(tif, dp->tdir_tag, iv))

	lea	ecx, DWORD PTR _iv$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dp$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchPerSampleShorts
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L65986
	mov	ecx, DWORD PTR _iv$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFSetField
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65985
$L65986:

; 301  : 				goto bad;

	jmp	$bad$65910
$L65985:

; 302  : 			dp->tdir_tag = IGNORE;

	mov	edx, DWORD PTR _dp$[ebp]
	mov	WORD PTR [edx], 0

; 303  : 			break;

	jmp	$L65977
$L65987:

; 304  : 		case TIFFTAG_STRIPOFFSETS:
; 305  : 		case TIFFTAG_STRIPBYTECOUNTS:
; 306  : 		case TIFFTAG_TILEOFFSETS:
; 307  : 		case TIFFTAG_TILEBYTECOUNTS:
; 308  : 			TIFFSetFieldBit(tif, fip->field_bit);

	mov	eax, DWORD PTR _fip$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+12]
	mov	eax, ecx
	cdq
	and	edx, 31					; 0000001fH
	add	eax, edx
	sar	eax, 5
	mov	edx, DWORD PTR _fip$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+12]
	and	ecx, 31					; 0000001fH
	mov	edx, 1
	shl	edx, cl
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [ecx+eax*4+24]
	or	ecx, edx
	mov	edx, DWORD PTR _fip$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+12]
	cdq
	and	edx, 31					; 0000001fH
	add	eax, edx
	sar	eax, 5
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+eax*4+24], ecx

; 309  : 			break;

	jmp	SHORT $L65977
$L65989:

; 310  : 		case TIFFTAG_IMAGEWIDTH:
; 311  : 		case TIFFTAG_IMAGELENGTH:
; 312  : 		case TIFFTAG_IMAGEDEPTH:
; 313  : 		case TIFFTAG_TILELENGTH:
; 314  : 		case TIFFTAG_TILEWIDTH:
; 315  : 		case TIFFTAG_TILEDEPTH:
; 316  : 		case TIFFTAG_PLANARCONFIG:
; 317  : 		case TIFFTAG_ROWSPERSTRIP:
; 318  : 			if (!TIFFFetchNormalTag(tif, dp))

	mov	eax, DWORD PTR _dp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFetchNormalTag
	add	esp, 8
	test	eax, eax
	jne	SHORT $L65990

; 319  : 				goto bad;

	jmp	$bad$65910
$L65990:

; 320  : 			dp->tdir_tag = IGNORE;

	mov	edx, DWORD PTR _dp$[ebp]
	mov	WORD PTR [edx], 0

; 321  : 			break;

	jmp	SHORT $L65977
$L65991:

; 322  : 		case TIFFTAG_EXTRASAMPLES:
; 323  : 			(void) TIFFFetchExtraSamples(tif, dp);

	mov	eax, DWORD PTR _dp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFetchExtraSamples
	add	esp, 8

; 324  : 			dp->tdir_tag = IGNORE;

	mov	edx, DWORD PTR _dp$[ebp]
	mov	WORD PTR [edx], 0
$L65977:

; 327  : 	}

	jmp	$L65948
$L65949:

; 328  : 
; 329  : 	/*
; 330  : 	 * Allocate directory structure and setup defaults.
; 331  : 	 */
; 332  : 	if (!TIFFFieldSet(tif, FIELD_IMAGEDIMENSIONS)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 2
	test	ecx, ecx
	jne	SHORT $L65994

; 333  : 		MissingRequired(tif, "ImageLength");

	push	OFFSET FLAT:$SG65995
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_MissingRequired
	add	esp, 8

; 334  : 		goto bad;

	jmp	$bad$65910
$L65994:

; 336  : 	if (!TIFFFieldSet(tif, FIELD_PLANARCONFIG)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 1048576				; 00100000H
	test	ecx, ecx
	jne	SHORT $L65997

; 337  : 		MissingRequired(tif, "PlanarConfiguration");

	push	OFFSET FLAT:$SG65998
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_MissingRequired
	add	esp, 8

; 338  : 		goto bad;

	jmp	$bad$65910
$L65997:

; 340  : 	/* 
; 341  :  	 * Setup appropriate structures (by strip or by tile)
; 342  : 	 */
; 343  : 	if (!TIFFFieldSet(tif, FIELD_TILEDIMENSIONS)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 4
	test	ecx, ecx
	jne	SHORT $L66000

; 344  : 		td->td_nstrips = TIFFNumberOfStrips(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFNumberOfStrips
	add	esp, 4
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+180], eax

; 345  : 		td->td_tilewidth = td->td_imagewidth;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [edx+24], ecx

; 346  : 		td->td_tilelength = td->td_rowsperstrip;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	DWORD PTR [edx+28], ecx

; 347  : 		td->td_tiledepth = td->td_imagedepth;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+20]
	mov	DWORD PTR [edx+32], ecx

; 348  : 		tif->tif_flags &= ~TIFF_ISTILED;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	ah, -5					; fffffffbH
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+12], eax

; 349  : 	} else {

	jmp	SHORT $L66001
$L66000:

; 350  : 		td->td_nstrips = TIFFNumberOfTiles(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFNumberOfTiles
	add	esp, 4
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+180], eax

; 351  : 		tif->tif_flags |= TIFF_ISTILED;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	or	ah, 4
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+12], eax
$L66001:

; 353  : 	td->td_stripsperimage = td->td_nstrips;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+180]
	mov	DWORD PTR [edx+176], ecx

; 354  : 	if (td->td_planarconfig == PLANARCONFIG_SEPARATE)

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+90]
	cmp	eax, 2
	jne	SHORT $L66002

; 355  : 		td->td_stripsperimage /= td->td_samplesperpixel;

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+54]
	mov	ecx, edx
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+176]
	xor	edx, edx
	div	ecx
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+176], eax
$L66002:

; 356  : 	if (!TIFFFieldSet(tif, FIELD_STRIPOFFSETS)) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+24]
	and	eax, 33554432				; 02000000H
	test	eax, eax
	jne	SHORT $L66004

; 357  : 		MissingRequired(tif,
; 358  : 		    isTiled(tif) ? "TileOffsets" : "StripOffsets");

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 1024				; 00000400H
	test	edx, edx
	je	SHORT $L66686
	mov	DWORD PTR -84+[ebp], OFFSET FLAT:$SG66005
	jmp	SHORT $L66687
$L66686:
	mov	DWORD PTR -84+[ebp], OFFSET FLAT:$SG66006
$L66687:
	mov	eax, DWORD PTR -84+[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_MissingRequired
	add	esp, 8

; 359  : 		goto bad;

	jmp	$bad$65910
$L66004:

; 361  : 
; 362  : 	/*
; 363  : 	 * Second pass: extract other information.
; 364  : 	 */
; 365  : 	for (dp = dir, n = dircount; n > 0; n--, dp++) {

	mov	edx, DWORD PTR _dir$[ebp]
	mov	DWORD PTR _dp$[ebp], edx
	mov	eax, DWORD PTR _dircount$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	DWORD PTR _n$[ebp], eax
	jmp	SHORT $L66007
$L66008:
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	mov	edx, DWORD PTR _dp$[ebp]
	add	edx, 12					; 0000000cH
	mov	DWORD PTR _dp$[ebp], edx
$L66007:
	cmp	DWORD PTR _n$[ebp], 0
	jle	$L66009

; 366  : 		if (dp->tdir_tag == IGNORE)

	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	test	ecx, ecx
	jne	SHORT $L66010

; 367  : 			continue;

	jmp	SHORT $L66008
$L66010:

; 368  : 		switch (dp->tdir_tag) {

	mov	edx, DWORD PTR _dp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	mov	DWORD PTR -88+[ebp], eax
	cmp	DWORD PTR -88+[ebp], 321		; 00000141H
	jg	SHORT $L66692
	cmp	DWORD PTR -88+[ebp], 321		; 00000141H
	je	$L66045
	mov	ecx, DWORD PTR -88+[ebp]
	sub	ecx, 255				; 000000ffH
	mov	DWORD PTR -88+[ebp], ecx
	cmp	DWORD PTR -88+[ebp], 65			; 00000041H
	ja	$L66060
	mov	eax, DWORD PTR -88+[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR $L66697[eax]
	jmp	DWORD PTR $L66698[edx*4]
$L66692:
	cmp	DWORD PTR -88+[ebp], 341		; 00000155H
	jg	SHORT $L66693
	cmp	DWORD PTR -88+[ebp], 340		; 00000154H
	jge	$L66023
	mov	ecx, DWORD PTR -88+[ebp]
	sub	ecx, 324				; 00000144H
	mov	DWORD PTR -88+[ebp], ecx
	cmp	DWORD PTR -88+[ebp], 15			; 0000000fH
	ja	$L66060
	mov	eax, DWORD PTR -88+[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR $L66699[eax]
	jmp	DWORD PTR $L66700[edx*4]
$L66693:
	cmp	DWORD PTR -88+[ebp], 530		; 00000212H
	je	$L66045
	cmp	DWORD PTR -88+[ebp], 532		; 00000214H
	je	$L66047
	cmp	DWORD PTR -88+[ebp], 32996		; 000080e4H
	je	$L66016
	jmp	$L66060
$L66015:

; 369  : 		case TIFFTAG_MINSAMPLEVALUE:
; 370  : 		case TIFFTAG_MAXSAMPLEVALUE:
; 371  : 		case TIFFTAG_BITSPERSAMPLE:
; 372  : 			/*
; 373  : 			 * The 5.0 spec says the Compression tag has
; 374  : 			 * one value, while earlier specs say it has
; 375  : 			 * one value per sample.  Because of this, we
; 376  : 			 * accept the tag if one value is supplied.
; 377  : 			 *
; 378  : 			 * The MinSampleValue, MaxSampleValue and
; 379  : 			 * BitsPerSample tags are supposed to be written
; 380  : 			 * as one value/sample, but some vendors incorrectly
; 381  : 			 * write one value only -- so we accept that
; 382  : 			 * as well (yech).
; 383  : 			 */
; 384  : 			if (dp->tdir_count == 1) {

	mov	ecx, DWORD PTR _dp$[ebp]
	cmp	DWORD PTR [ecx+4], 1
	jne	$L66016

; 385  : 				v = TIFFExtractData(tif,
; 386  : 				    dp->tdir_type, dp->tdir_offset);

	mov	edx, DWORD PTR _tif$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+336]
	cmp	eax, 19789				; 00004d4dH
	jne	SHORT $L66688
	mov	ecx, DWORD PTR _dp$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+2]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+348]
	mov	eax, DWORD PTR _dp$[ebp]
	mov	eax, DWORD PTR [eax+8]
	mov	ecx, DWORD PTR [ecx+edx*4]
	shr	eax, cl
	mov	ecx, DWORD PTR _dp$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+2]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [ecx+352]
	and	eax, DWORD PTR [ecx+edx*4]
	mov	DWORD PTR -92+[ebp], eax
	jmp	SHORT $L66689
$L66688:
	mov	edx, DWORD PTR _dp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+2]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+352]
	mov	ecx, DWORD PTR _dp$[ebp]
	mov	ecx, DWORD PTR [ecx+8]
	and	ecx, DWORD PTR [edx+eax*4]
	mov	DWORD PTR -92+[ebp], ecx
$L66689:
	mov	edx, DWORD PTR -92+[ebp]
	mov	DWORD PTR _v$[ebp], edx

; 387  : 				if (!TIFFSetField(tif, dp->tdir_tag, (int)v))

	mov	eax, DWORD PTR _v$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dp$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFSetField
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66019

; 388  : 					goto bad;

	jmp	$bad$65910
$L66019:

; 389  : 				break;

	jmp	$L66012
$L66016:

; 391  : 			/* fall thru... */
; 392  : 		case TIFFTAG_DATATYPE:
; 393  : 		case TIFFTAG_SAMPLEFORMAT:
; 394  : 			if (!TIFFFetchPerSampleShorts(tif, dp, &iv) ||
; 395  : 			    !TIFFSetField(tif, dp->tdir_tag, iv))

	lea	ecx, DWORD PTR _iv$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dp$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchPerSampleShorts
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L66022
	mov	ecx, DWORD PTR _iv$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFSetField
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66021
$L66022:

; 396  : 				goto bad;

	jmp	$bad$65910
$L66021:

; 397  : 			break;

	jmp	$L66012
$L66023:

; 398  : 		case TIFFTAG_SMINSAMPLEVALUE:
; 399  : 		case TIFFTAG_SMAXSAMPLEVALUE:
; 400  : 			if (!TIFFFetchPerSampleAnys(tif, dp, &dv) ||
; 401  : 			    !TIFFSetField(tif, dp->tdir_tag, dv))

	lea	edx, DWORD PTR _dv$[ebp]
	push	edx
	mov	eax, DWORD PTR _dp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFetchPerSampleAnys
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L66025
	mov	edx, DWORD PTR _dv$[ebp+4]
	push	edx
	mov	eax, DWORD PTR _dv$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dp$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFSetField
	add	esp, 16					; 00000010H
	test	eax, eax
	jne	SHORT $L66024
$L66025:

; 402  : 				goto bad;

	jmp	$bad$65910
$L66024:

; 403  : 			break;

	jmp	$L66012
$L66026:

; 404  : 		case TIFFTAG_STRIPOFFSETS:
; 405  : 		case TIFFTAG_TILEOFFSETS:
; 406  : 			if (!TIFFFetchStripThing(tif, dp,
; 407  : 			    td->td_nstrips, &td->td_stripoffset))

	mov	ecx, DWORD PTR _td$[ebp]
	add	ecx, 184				; 000000b8H
	push	ecx
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+180]
	push	eax
	mov	ecx, DWORD PTR _dp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFetchStripThing
	add	esp, 16					; 00000010H
	test	eax, eax
	jne	SHORT $L66027

; 408  : 				goto bad;

	jmp	$bad$65910
$L66027:

; 409  : 			break;

	jmp	$L66012
$L66028:

; 410  : 		case TIFFTAG_STRIPBYTECOUNTS:
; 411  : 		case TIFFTAG_TILEBYTECOUNTS:
; 412  : 			if (!TIFFFetchStripThing(tif, dp,
; 413  : 			    td->td_nstrips, &td->td_stripbytecount))

	mov	eax, DWORD PTR _td$[ebp]
	add	eax, 188				; 000000bcH
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+180]
	push	edx
	mov	eax, DWORD PTR _dp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFetchStripThing
	add	esp, 16					; 00000010H
	test	eax, eax
	jne	SHORT $L66029

; 414  : 				goto bad;

	jmp	$bad$65910
$L66029:

; 415  : 			break;

	jmp	$L66012
$L66030:

; 416  : 		case TIFFTAG_COLORMAP:
; 417  : 		case TIFFTAG_TRANSFERFUNCTION:
; 418  : 			/*
; 419  : 			 * TransferFunction can have either 1x or 3x data
; 420  : 			 * values; Colormap can have only 3x items.
; 421  : 			 */
; 422  : 			v = 1L<<td->td_bitspersample;

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+40]
	mov	ecx, eax
	mov	edx, 1
	shl	edx, cl
	mov	DWORD PTR _v$[ebp], edx

; 423  : 			if (dp->tdir_tag == TIFFTAG_COLORMAP ||
; 424  : 			    dp->tdir_count != (uint32) v) {

	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	cmp	ecx, 320				; 00000140H
	je	SHORT $L66033
	mov	edx, DWORD PTR _dp$[ebp]
	mov	eax, DWORD PTR [edx+4]
	cmp	eax, DWORD PTR _v$[ebp]
	je	SHORT $L66035
$L66033:

; 425  : 				if (!CheckDirCount(tif, dp, (uint32)(3*v)))

	mov	ecx, DWORD PTR _v$[ebp]
	imul	ecx, 3
	push	ecx
	mov	edx, DWORD PTR _dp$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_CheckDirCount
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66035

; 426  : 					break;

	jmp	$L66012
$L66035:

; 428  : 			v *= sizeof (uint16);

	mov	ecx, DWORD PTR _v$[ebp]
	shl	ecx, 1
	mov	DWORD PTR _v$[ebp], ecx

; 429  : 			cp = CheckMalloc(tif, dp->tdir_count * sizeof (uint16),
; 430  : 			    "to read \"TransferFunction\" tag");

	push	OFFSET FLAT:$SG66038
	mov	edx, DWORD PTR _dp$[ebp]
	mov	eax, DWORD PTR [edx+4]
	shl	eax, 1
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_CheckMalloc
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _cp$[ebp], eax

; 431  : 			if (cp != NULL) {

	cmp	DWORD PTR _cp$[ebp], 0
	je	SHORT $L66040

; 432  : 				if (TIFFFetchData(tif, dp, cp)) {

	mov	edx, DWORD PTR _cp$[ebp]
	push	edx
	mov	eax, DWORD PTR _dp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFetchData
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L66041

; 433  : 					/*
; 434  : 					 * This deals with there being only
; 435  : 					 * one array to apply to all samples.
; 436  : 					 */
; 437  : 					uint32 c =
; 438  : 					    (uint32)1 << td->td_bitspersample;

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+40]
	mov	ecx, eax
	mov	edx, 1
	shl	edx, cl
	mov	DWORD PTR _c$66042[ebp], edx

; 439  : 					if (dp->tdir_count == c)

	mov	eax, DWORD PTR _dp$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	cmp	ecx, DWORD PTR _c$66042[ebp]
	jne	SHORT $L66044

; 440  : 						v = 0;

	mov	DWORD PTR _v$[ebp], 0
$L66044:

; 441  : 					TIFFSetField(tif, dp->tdir_tag,
; 442  : 					    cp, cp+v, cp+2*v);

	mov	edx, DWORD PTR _v$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	lea	ecx, DWORD PTR [eax+edx*2]
	push	ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, DWORD PTR _v$[ebp]
	push	edx
	mov	eax, DWORD PTR _cp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dp$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFSetField
	add	esp, 20					; 00000014H
$L66041:

; 444  : 				_TIFFfree(cp);

	mov	ecx, DWORD PTR _cp$[ebp]
	push	ecx
	call	__TIFFfree
	add	esp, 4
$L66040:

; 446  : 			break;

	jmp	$L66012
$L66045:

; 447  : 		case TIFFTAG_PAGENUMBER:
; 448  : 		case TIFFTAG_HALFTONEHINTS:
; 449  : 		case TIFFTAG_YCBCRSUBSAMPLING:
; 450  : 		case TIFFTAG_DOTRANGE:
; 451  : 			(void) TIFFFetchShortPair(tif, dp);

	mov	edx, DWORD PTR _dp$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchShortPair
	add	esp, 8

; 452  : 			break;

	jmp	$L66012
$L66047:

; 453  : #ifdef COLORIMETRY_SUPPORT
; 454  : 		case TIFFTAG_REFERENCEBLACKWHITE:
; 455  : 			(void) TIFFFetchRefBlackWhite(tif, dp);

	mov	ecx, DWORD PTR _dp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFetchRefBlackWhite
	add	esp, 8

; 456  : 			break;

	jmp	$L66012
$L66049:

; 457  : #endif
; 458  : /* BEGIN REV 4.0 COMPATIBILITY */
; 459  : 		case TIFFTAG_OSUBFILETYPE:
; 460  : 			v = 0;

	mov	DWORD PTR _v$[ebp], 0

; 461  : 			switch (TIFFExtractData(tif, dp->tdir_type,
; 462  : 			    dp->tdir_offset)) {

	mov	eax, DWORD PTR _tif$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+336]
	cmp	ecx, 19789				; 00004d4dH
	jne	SHORT $L66690
	mov	edx, DWORD PTR _dp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+2]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+348]
	mov	ecx, DWORD PTR _dp$[ebp]
	mov	esi, DWORD PTR [ecx+8]
	mov	ecx, DWORD PTR [edx+eax*4]
	shr	esi, cl
	mov	edx, DWORD PTR _dp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+2]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+352]
	and	esi, DWORD PTR [edx+eax*4]
	mov	DWORD PTR -96+[ebp], esi
	jmp	SHORT $L66691
$L66690:
	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+2]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+352]
	mov	edx, DWORD PTR _dp$[ebp]
	mov	edx, DWORD PTR [edx+8]
	and	edx, DWORD PTR [eax+ecx*4]
	mov	DWORD PTR -96+[ebp], edx
$L66691:
	mov	eax, DWORD PTR -96+[ebp]
	mov	DWORD PTR -100+[ebp], eax
	cmp	DWORD PTR -100+[ebp], 2
	je	SHORT $L66055
	cmp	DWORD PTR -100+[ebp], 3
	je	SHORT $L66056
	jmp	SHORT $L66052
$L66055:

; 463  : 			case OFILETYPE_REDUCEDIMAGE:
; 464  : 				v = FILETYPE_REDUCEDIMAGE;

	mov	DWORD PTR _v$[ebp], 1

; 465  : 				break;

	jmp	SHORT $L66052
$L66056:

; 466  : 			case OFILETYPE_PAGE:
; 467  : 				v = FILETYPE_PAGE;

	mov	DWORD PTR _v$[ebp], 2
$L66052:

; 470  : 			if (v)

	cmp	DWORD PTR _v$[ebp], 0
	je	SHORT $L66057

; 471  : 				(void) TIFFSetField(tif,
; 472  : 				    TIFFTAG_SUBFILETYPE, (int)v);

	mov	ecx, DWORD PTR _v$[ebp]
	push	ecx
	push	254					; 000000feH
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFSetField
	add	esp, 12					; 0000000cH
$L66057:

; 473  : 			break;

	jmp	SHORT $L66012
$L66060:

; 474  : /* END REV 4.0 COMPATIBILITY */
; 475  : 		default:
; 476  : 			(void) TIFFFetchNormalTag(tif, dp);

	mov	eax, DWORD PTR _dp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFetchNormalTag
	add	esp, 8
$L66012:

; 479  : 	}

	jmp	$L66008
$L66009:

; 480  : 	/*
; 481  : 	 * Verify Palette image has a Colormap.
; 482  : 	 */
; 483  : 	if (td->td_photometric == PHOTOMETRIC_PALETTE &&
; 484  : 	    !TIFFFieldSet(tif, FIELD_COLORMAP)) {

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+46]
	cmp	eax, 3
	jne	SHORT $L66063
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	and	edx, 67108864				; 04000000H
	test	edx, edx
	jne	SHORT $L66063

; 485  : 		MissingRequired(tif, "Colormap");

	push	OFFSET FLAT:$SG66064
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_MissingRequired
	add	esp, 8

; 486  : 		goto bad;

	jmp	$bad$65910
$L66063:

; 488  : 	/*
; 489  : 	 * Attempt to deal with a missing StripByteCounts tag.
; 490  : 	 */
; 491  : 	if (!TIFFFieldSet(tif, FIELD_STRIPBYTECOUNTS)) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	and	edx, 16777216				; 01000000H
	test	edx, edx
	jne	$L66066

; 492  : 		/*
; 493  : 		 * Some manufacturers violate the spec by not giving
; 494  : 		 * the size of the strips.  In this case, assume there
; 495  : 		 * is one uncompressed strip of data.
; 496  : 		 */
; 497  : 		if ((td->td_planarconfig == PLANARCONFIG_CONTIG &&
; 498  : 		    td->td_nstrips > 1) ||
; 499  : 		    (td->td_planarconfig == PLANARCONFIG_SEPARATE &&
; 500  : 		     td->td_nstrips != td->td_samplesperpixel)) {

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+90]
	cmp	ecx, 1
	jne	SHORT $L66069
	mov	edx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [edx+180], 1
	ja	SHORT $L66068
$L66069:
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+90]
	cmp	ecx, 2
	jne	SHORT $L66067
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+54]
	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+180], eax
	je	SHORT $L66067
$L66068:

; 501  : 		    MissingRequired(tif, "StripByteCounts");

	push	OFFSET FLAT:$SG66070
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_MissingRequired
	add	esp, 8

; 502  : 		    goto bad;

	jmp	$bad$65910
$L66067:

; 504  : 		TIFFWarning(tif->tif_name,
; 505  : "TIFF directory is missing required \"%s\" field, calculating from imagelength",
; 506  : 		    _TIFFFieldWithTag(tif,TIFFTAG_STRIPBYTECOUNTS)->field_name);

	push	279					; 00000117H
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	__TIFFFieldWithTag
	add	esp, 8
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:$SG66071
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFWarning
	add	esp, 12					; 0000000cH

; 507  : 		EstimateStripByteCounts(tif, dir, dircount);

	mov	cx, WORD PTR _dircount$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_EstimateStripByteCounts
	add	esp, 12					; 0000000cH

; 508  : #define	BYTECOUNTLOOKSBAD \
; 509  :     ((td->td_stripbytecount[0] == 0 && td->td_stripoffset[0] != 0) || \
; 510  :     (td->td_compression == COMPRESSION_NONE && \
; 511  :      td->td_stripbytecount[0] > TIFFGetFileSize(tif) - td->td_stripoffset[0]))
; 512  : 	} else if (td->td_nstrips == 1 && BYTECOUNTLOOKSBAD) {

	jmp	$L66074
$L66066:
	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+180], 1
	jne	$L66074
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+188]
	cmp	DWORD PTR [eax], 0
	jne	SHORT $L66076
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	cmp	DWORD PTR [edx], 0
	jne	SHORT $L66075
$L66076:
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+44]
	cmp	ecx, 1
	jne	SHORT $L66074
	mov	edx, DWORD PTR _td$[ebp]
	mov	esi, DWORD PTR [edx+188]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+524]
	add	esp, 4
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	sub	eax, DWORD PTR [edx]
	cmp	DWORD PTR [esi], eax
	jbe	SHORT $L66074
$L66075:

; 513  : 		/*
; 514  : 		 * Plexus (and others) sometimes give a value
; 515  : 		 * of zero for a tag when they don't know what
; 516  : 		 * the correct value is!  Try and handle the
; 517  : 		 * simple case of estimating the size of a one
; 518  : 		 * strip image.
; 519  : 		 */
; 520  : 		TIFFWarning(tif->tif_name,
; 521  : 	    "Bogus \"%s\" field, ignoring and calculating from imagelength",
; 522  : 		    _TIFFFieldWithTag(tif,TIFFTAG_STRIPBYTECOUNTS)->field_name);

	push	279					; 00000117H
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	__TIFFFieldWithTag
	add	esp, 8
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:$SG66077
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFWarning
	add	esp, 12					; 0000000cH

; 523  : 		EstimateStripByteCounts(tif, dir, dircount);

	mov	cx, WORD PTR _dircount$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_EstimateStripByteCounts
	add	esp, 12					; 0000000cH
$L66074:

; 525  : 	if (dir)

	cmp	DWORD PTR _dir$[ebp], 0
	je	SHORT $L66078

; 526  : 		_TIFFfree((char *)dir);

	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	call	__TIFFfree
	add	esp, 4
$L66078:

; 527  : 	if (!TIFFFieldSet(tif, FIELD_MAXSAMPLEVALUE))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+24]
	and	eax, 524288				; 00080000H
	test	eax, eax
	jne	SHORT $L66081

; 528  : 		td->td_maxsamplevalue = (uint16)((1L<<td->td_bitspersample)-1);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+40]
	mov	ecx, edx
	mov	eax, 1
	shl	eax, cl
	sub	eax, 1
	mov	ecx, DWORD PTR _td$[ebp]
	mov	WORD PTR [ecx+62], ax
$L66081:

; 529  : 	/*
; 530  : 	 * Setup default compression scheme.
; 531  : 	 */
; 532  : 	if (!TIFFFieldSet(tif, FIELD_COMPRESSION))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+24]
	and	eax, 128				; 00000080H
	test	eax, eax
	jne	SHORT $L66084

; 533  : 		TIFFSetField(tif, TIFFTAG_COMPRESSION, COMPRESSION_NONE);

	push	1
	push	259					; 00000103H
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFSetField
	add	esp, 12					; 0000000cH
$L66084:

; 534  :         /*
; 535  :          * Some manufacturers make life difficult by writing
; 536  : 	 * large amounts of uncompressed data as a single strip.
; 537  : 	 * This is contrary to the recommendations of the spec.
; 538  :          * The following makes an attempt at breaking such images
; 539  : 	 * into strips closer to the recommended 8k bytes.  A
; 540  : 	 * side effect, however, is that the RowsPerStrip tag
; 541  : 	 * value may be changed.
; 542  :          */
; 543  : 	if (td->td_nstrips == 1 && td->td_compression == COMPRESSION_NONE &&
; 544  : 	    (tif->tif_flags & (TIFF_STRIPCHOP|TIFF_ISTILED)) == TIFF_STRIPCHOP)

	mov	edx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [edx+180], 1
	jne	SHORT $L66085
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+44]
	cmp	ecx, 1
	jne	SHORT $L66085
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 33792				; 00008400H
	cmp	eax, 32768				; 00008000H
	jne	SHORT $L66085

; 545  : 		ChopUpSingleUncompressedStrip(tif);

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_ChopUpSingleUncompressedStrip
	add	esp, 4
$L66085:

; 546  : 	/*
; 547  : 	 * Reinitialize i/o since we are starting on a new directory.
; 548  : 	 */
; 549  : 	tif->tif_row = (uint32) -1;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+356], -1

; 550  : 	tif->tif_curstrip = (tstrip_t) -1;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+364], -1

; 551  : 	tif->tif_col = (uint32) -1;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+384], -1

; 552  : 	tif->tif_curtile = (ttile_t) -1;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+388], -1

; 553  : 	tif->tif_tilesize = TIFFTileSize(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFTileSize
	add	esp, 4
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+392], eax

; 554  : 	tif->tif_scanlinesize = TIFFScanlineSize(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFScanlineSize
	add	esp, 4
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+464], eax

; 555  : 	return (1);

	mov	eax, 1
	jmp	SHORT $L65869
$bad$65910:

; 556  : bad:
; 557  : 	if (dir)

	cmp	DWORD PTR _dir$[ebp], 0
	je	SHORT $L66090

; 558  : 		_TIFFfree(dir);

	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	call	__TIFFfree
	add	esp, 4
$L66090:

; 559  : 	return (0);

	xor	eax, eax
$L65869:

; 560  : }

	pop	esi
	mov	esp, ebp
	pop	ebp
	ret	0
$L66695:
	DD	$L65989
	DD	$L65980
	DD	$L65987
	DD	$L65977
$L66694:
	DB	0
	DB	0
	DB	3
	DB	1
	DB	3
	DB	3
	DB	3
	DB	3
	DB	3
	DB	3
	DB	3
	DB	3
	DB	3
	DB	3
	DB	3
	DB	3
	DB	3
	DB	2
	DB	3
	DB	3
	DB	3
	DB	3
	DB	0
	DB	2
$L66696:
	DD	$L65989
	DD	$L65989
	DD	$L65987
	DD	$L65987
$L66698:
	DD	$L66049
	DD	$L66015
	DD	$L66026
	DD	$L66028
	DD	$L66045
	DD	$L66030
	DD	$L66060
$L66697:
	DB	0
	DB	6
	DB	6
	DB	1
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	2
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	3
	DB	1
	DB	1
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	4
	DB	6
	DB	6
	DB	6
	DB	5
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	5
$L66700:
	DD	$L66026
	DD	$L66028
	DD	$L66045
	DD	$L66016
	DD	$L66060
$L66699:
	DB	0
	DB	1
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	2
	DB	4
	DB	4
	DB	3
_TIFFReadDirectory ENDP
_TEXT	ENDS
EXTRN	__TIFFmalloc:NEAR
_DATA	SEGMENT
$SG65866 DB	'No space %s', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_n$ = 12
_what$ = 16
_cp$ = -4
_CheckMalloc PROC NEAR

; 66   : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 67   : 	char *cp = (char*)_TIFFmalloc(n);

	mov	eax, DWORD PTR _n$[ebp]
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	DWORD PTR _cp$[ebp], eax

; 68   : 	if (cp == NULL)

	cmp	DWORD PTR _cp$[ebp], 0
	jne	SHORT $L65865

; 69   : 		TIFFError(tif->tif_name, "No space %s", what);

	mov	ecx, DWORD PTR _what$[ebp]
	push	ecx
	push	OFFSET FLAT:$SG65866
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 12					; 0000000cH
$L65865:

; 70   : 	return (cp);

	mov	eax, DWORD PTR _cp$[ebp]

; 71   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_CheckMalloc ENDP
_TEXT	ENDS
EXTRN	_tiffDataWidth:BYTE
_DATA	SEGMENT
$SG66104 DB	'for "StripByteCounts" array', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_dir$ = 12
_dircount$ = 16
_dp$ = -4
_td$ = -12
_i$ = -8
_space$66106 = -16
_filesize$66112 = -24
_n$66113 = -20
_cc$66117 = -28
_rowbytes$66127 = -32
_rowsperstrip$66128 = -36
_EstimateStripByteCounts PROC NEAR

; 564  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 36					; 00000024H
	push	esi

; 565  : 	register TIFFDirEntry *dp;
; 566  : 	register TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 567  : 	uint16 i;
; 568  : 
; 569  : 	if (td->td_stripbytecount)

	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+188], 0
	je	SHORT $L66101

; 570  : 		_TIFFfree(td->td_stripbytecount);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+188]
	push	eax
	call	__TIFFfree
	add	esp, 4
$L66101:

; 571  : 	td->td_stripbytecount = (uint32*)
; 572  : 	    CheckMalloc(tif, td->td_nstrips * sizeof (uint32),
; 573  : 		"for \"StripByteCounts\" array");

	push	OFFSET FLAT:$SG66104
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+180]
	shl	edx, 2
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_CheckMalloc
	add	esp, 12					; 0000000cH
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+188], eax

; 574  : 	if (td->td_compression != COMPRESSION_NONE) {

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+44]
	cmp	eax, 1
	je	$L66105

; 575  : 		uint32 space = (uint32)(sizeof (TIFFHeader)
; 576  : 		    + sizeof (uint16)
; 577  : 		    + (dircount * sizeof (TIFFDirEntry))
; 578  : 		    + sizeof (uint32));

	mov	ecx, DWORD PTR _dircount$[ebp]
	and	ecx, 65535				; 0000ffffH
	imul	ecx, 12					; 0000000cH
	add	ecx, 14					; 0000000eH
	mov	DWORD PTR _space$66106[ebp], ecx

; 579  : 		toff_t filesize = TIFFGetFileSize(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+504]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+524]
	add	esp, 4
	mov	DWORD PTR _filesize$66112[ebp], eax

; 580  : 		uint16 n;
; 581  : 
; 582  : 		/* calculate amount of space used by indirect values */
; 583  : 		for (dp = dir, n = dircount; n > 0; n--, dp++) {

	mov	edx, DWORD PTR _dir$[ebp]
	mov	DWORD PTR _dp$[ebp], edx
	mov	ax, WORD PTR _dircount$[ebp]
	mov	WORD PTR _n$66113[ebp], ax
	jmp	SHORT $L66114
$L66115:
	mov	cx, WORD PTR _n$66113[ebp]
	sub	cx, 1
	mov	WORD PTR _n$66113[ebp], cx
	mov	edx, DWORD PTR _dp$[ebp]
	add	edx, 12					; 0000000cH
	mov	DWORD PTR _dp$[ebp], edx
$L66114:
	mov	eax, DWORD PTR _n$66113[ebp]
	and	eax, 65535				; 0000ffffH
	test	eax, eax
	jle	SHORT $L66116

; 584  : 			uint32 cc = dp->tdir_count*tiffDataWidth[dp->tdir_type];

	mov	ecx, DWORD PTR _dp$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+2]
	mov	eax, DWORD PTR _dp$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	imul	ecx, DWORD PTR _tiffDataWidth[edx*4]
	mov	DWORD PTR _cc$66117[ebp], ecx

; 585  : 			if (cc > sizeof (uint32))

	cmp	DWORD PTR _cc$66117[ebp], 4
	jbe	SHORT $L66119

; 586  : 				space += cc;

	mov	edx, DWORD PTR _space$66106[ebp]
	add	edx, DWORD PTR _cc$66117[ebp]
	mov	DWORD PTR _space$66106[ebp], edx
$L66119:

; 587  : 		}

	jmp	SHORT $L66115
$L66116:

; 588  : 		space = filesize - space;

	mov	eax, DWORD PTR _filesize$66112[ebp]
	sub	eax, DWORD PTR _space$66106[ebp]
	mov	DWORD PTR _space$66106[ebp], eax

; 589  : 		if (td->td_planarconfig == PLANARCONFIG_SEPARATE)

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+90]
	cmp	edx, 2
	jne	SHORT $L66120

; 590  : 			space /= td->td_samplesperpixel;

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+54]
	mov	eax, DWORD PTR _space$66106[ebp]
	xor	edx, edx
	div	ecx
	mov	DWORD PTR _space$66106[ebp], eax
$L66120:

; 591  : 		for (i = 0; i < td->td_nstrips; i++)

	mov	WORD PTR _i$[ebp], 0
	jmp	SHORT $L66121
$L66122:
	mov	dx, WORD PTR _i$[ebp]
	add	dx, 1
	mov	WORD PTR _i$[ebp], dx
$L66121:
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _td$[ebp]
	cmp	eax, DWORD PTR [ecx+180]
	jae	SHORT $L66123

; 592  : 			td->td_stripbytecount[i] = space;

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+188]
	mov	eax, DWORD PTR _space$66106[ebp]
	mov	DWORD PTR [ecx+edx*4], eax
	jmp	SHORT $L66122
$L66123:

; 593  : 		/*
; 594  : 		 * This gross hack handles the case were the offset to
; 595  : 		 * the last strip is past the place where we think the strip
; 596  : 		 * should begin.  Since a strip of data must be contiguous,
; 597  : 		 * it's safe to assume that we've overestimated the amount
; 598  : 		 * of data in the strip and trim this number back accordingly.
; 599  : 		 */ 
; 600  : 		i--;

	mov	cx, WORD PTR _i$[ebp]
	sub	cx, 1
	mov	WORD PTR _i$[ebp], cx

; 601  : 		if (((toff_t)(td->td_stripoffset[i]+td->td_stripbytecount[i]))
; 602  :                                                                > filesize)

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+184]
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	esi, DWORD PTR _td$[ebp]
	mov	esi, DWORD PTR [esi+188]
	mov	ecx, DWORD PTR [ecx+edx*4]
	add	ecx, DWORD PTR [esi+eax*4]
	cmp	ecx, DWORD PTR _filesize$66112[ebp]
	jbe	SHORT $L66125

; 603  : 			td->td_stripbytecount[i] =
; 604  : 			    filesize - td->td_stripoffset[i];

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+184]
	mov	eax, DWORD PTR _filesize$66112[ebp]
	sub	eax, DWORD PTR [ecx+edx*4]
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [edx+188]
	mov	DWORD PTR [edx+ecx*4], eax
$L66125:

; 605  : 	} else {

	jmp	SHORT $L66131
$L66105:

; 606  : 		uint32 rowbytes = TIFFScanlineSize(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFScanlineSize
	add	esp, 4
	mov	DWORD PTR _rowbytes$66127[ebp], eax

; 607  : 		uint32 rowsperstrip = td->td_imagelength/td->td_stripsperimage;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	esi, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [ecx+16]
	xor	edx, edx
	div	DWORD PTR [esi+176]
	mov	DWORD PTR _rowsperstrip$66128[ebp], eax

; 608  : 		for (i = 0; i < td->td_nstrips; i++)

	mov	WORD PTR _i$[ebp], 0
	jmp	SHORT $L66129
$L66130:
	mov	dx, WORD PTR _i$[ebp]
	add	dx, 1
	mov	WORD PTR _i$[ebp], dx
$L66129:
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _td$[ebp]
	cmp	eax, DWORD PTR [ecx+180]
	jae	SHORT $L66131

; 609  : 			td->td_stripbytecount[i] = rowbytes*rowsperstrip;

	mov	edx, DWORD PTR _rowbytes$66127[ebp]
	imul	edx, DWORD PTR _rowsperstrip$66128[ebp]
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [ecx+188]
	mov	DWORD PTR [ecx+eax*4], edx
	jmp	SHORT $L66130
$L66131:

; 611  : 	TIFFSetFieldBit(tif, FIELD_STRIPBYTECOUNTS);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+24]
	or	eax, 16777216				; 01000000H
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+24], eax

; 612  : 	if (!TIFFFieldSet(tif, FIELD_ROWSPERSTRIP))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+24]
	and	eax, 131072				; 00020000H
	test	eax, eax
	jne	SHORT $L66134

; 613  : 		td->td_rowsperstrip = td->td_imagelength;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+16]
	mov	DWORD PTR [ecx+56], eax
$L66134:

; 614  : }

	pop	esi
	mov	esp, ebp
	pop	ebp
	ret	0
_EstimateStripByteCounts ENDP
_TEXT	ENDS
_DATA	SEGMENT
$SG66140 DB	'TIFF directory is missing required "%s" field', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_tagname$ = 12
_MissingRequired PROC NEAR

; 618  : {

	push	ebp
	mov	ebp, esp

; 619  : 	TIFFError(tif->tif_name,
; 620  : 	    "TIFF directory is missing required \"%s\" field", tagname);

	mov	eax, DWORD PTR _tagname$[ebp]
	push	eax
	push	OFFSET FLAT:$SG66140
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 621  : }

	pop	ebp
	ret	0
_MissingRequired ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+2
$SG66149 DB	'incorrect count for field "%s" (%lu, expecting %lu); tag'
	DB	' ignored', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_dir$ = 12
_count$ = 16
_CheckDirCount PROC NEAR

; 631  : {

	push	ebp
	mov	ebp, esp

; 632  : 	if (count != dir->tdir_count) {

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR _count$[ebp]
	cmp	ecx, DWORD PTR [eax+4]
	je	SHORT $L66148

; 633  : 		TIFFWarning(tif->tif_name,
; 634  : 	"incorrect count for field \"%s\" (%lu, expecting %lu); tag ignored",
; 635  : 		    _TIFFFieldWithTag(tif, dir->tdir_tag)->field_name,
; 636  : 		    dir->tdir_count, count);

	mov	edx, DWORD PTR _count$[ebp]
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	__TIFFFieldWithTag
	add	esp, 8
	mov	edx, DWORD PTR [eax+16]
	push	edx
	push	OFFSET FLAT:$SG66149
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFWarning
	add	esp, 20					; 00000014H

; 637  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L66147
$L66148:

; 639  : 	return (1);

	mov	eax, 1
$L66147:

; 640  : }

	pop	ebp
	ret	0
_CheckDirCount ENDP
_TEXT	ENDS
EXTRN	_TIFFSwabArrayOfDouble:NEAR
_DATA	SEGMENT
	ORG $+3
$SG66184 DB	'Error fetching data for field "%s"', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_dir$ = 12
_cp$ = 16
_w$ = -8
_cc$ = -4
_TIFFFetchData PROC NEAR

; 647  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 648  : 	int w = tiffDataWidth[dir->tdir_type];

	mov	eax, DWORD PTR _dir$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+2]
	mov	edx, DWORD PTR _tiffDataWidth[ecx*4]
	mov	DWORD PTR _w$[ebp], edx

; 649  : 	tsize_t cc = dir->tdir_count * w;

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	imul	ecx, DWORD PTR _w$[ebp]
	mov	DWORD PTR _cc$[ebp], ecx

; 650  : 
; 651  : 	if (!isMapped(tif)) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 2048				; 00000800H
	test	eax, eax
	jne	SHORT $L66159

; 652  : 		if (!SeekOK(tif, dir->tdir_offset))

	push	0
	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+516]
	add	esp, 12					; 0000000cH
	mov	ecx, DWORD PTR _dir$[ebp]
	cmp	eax, DWORD PTR [ecx+8]
	je	SHORT $L66163

; 653  : 			goto bad;

	jmp	$bad$66164
$L66163:

; 654  : 		if (!ReadOK(tif, cp, cc))

	mov	edx, DWORD PTR _cc$[ebp]
	push	edx
	mov	eax, DWORD PTR _cp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+508]
	add	esp, 12					; 0000000cH
	cmp	eax, DWORD PTR _cc$[ebp]
	je	SHORT $L66168

; 655  : 			goto bad;

	jmp	$bad$66164
$L66168:

; 656  : 	} else {

	jmp	SHORT $L66169
$L66159:

; 657  : 		if (dir->tdir_offset + cc > tif->tif_size)

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	add	edx, DWORD PTR _cc$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	cmp	edx, DWORD PTR [eax+492]
	jbe	SHORT $L66170

; 658  : 			goto bad;

	jmp	$bad$66164
$L66170:

; 659  : 		_TIFFmemcpy(cp, tif->tif_base + dir->tdir_offset, cc);

	mov	ecx, DWORD PTR _cc$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+488]
	mov	ecx, DWORD PTR _dir$[ebp]
	add	eax, DWORD PTR [ecx+8]
	push	eax
	mov	edx, DWORD PTR _cp$[ebp]
	push	edx
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH
$L66169:

; 661  : 	if (tif->tif_flags & TIFF_SWAB) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 128				; 00000080H
	test	ecx, ecx
	je	SHORT $L66173

; 662  : 		switch (dir->tdir_type) {

	mov	edx, DWORD PTR _dir$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+2]
	mov	DWORD PTR -12+[ebp], eax
	mov	ecx, DWORD PTR -12+[ebp]
	sub	ecx, 3
	mov	DWORD PTR -12+[ebp], ecx
	cmp	DWORD PTR -12+[ebp], 9
	ja	SHORT $L66173
	mov	edx, DWORD PTR -12+[ebp]
	jmp	DWORD PTR $L66707[edx*4]
$L66176:

; 663  : 		case TIFF_SHORT:
; 664  : 		case TIFF_SSHORT:
; 665  : 			TIFFSwabArrayOfShort((uint16*) cp, dir->tdir_count);

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR _cp$[ebp]
	push	edx
	call	_TIFFSwabArrayOfShort
	add	esp, 8

; 666  : 			break;

	jmp	SHORT $L66173
$L66178:

; 667  : 		case TIFF_LONG:
; 668  : 		case TIFF_SLONG:
; 669  : 		case TIFF_FLOAT:
; 670  : 			TIFFSwabArrayOfLong((uint32*) cp, dir->tdir_count);

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR _cp$[ebp]
	push	edx
	call	_TIFFSwabArrayOfLong
	add	esp, 8

; 671  : 			break;

	jmp	SHORT $L66173
$L66180:

; 672  : 		case TIFF_RATIONAL:
; 673  : 		case TIFF_SRATIONAL:
; 674  : 			TIFFSwabArrayOfLong((uint32*) cp, 2*dir->tdir_count);

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	shl	ecx, 1
	push	ecx
	mov	edx, DWORD PTR _cp$[ebp]
	push	edx
	call	_TIFFSwabArrayOfLong
	add	esp, 8

; 675  : 			break;

	jmp	SHORT $L66173
$L66182:

; 676  : 		case TIFF_DOUBLE:
; 677  : 			TIFFSwabArrayOfDouble((double*) cp, dir->tdir_count);

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR _cp$[ebp]
	push	edx
	call	_TIFFSwabArrayOfDouble
	add	esp, 8
$L66173:

; 681  : 	return (cc);

	mov	eax, DWORD PTR _cc$[ebp]
	jmp	SHORT $L66156
$bad$66164:

; 682  : bad:
; 683  : 	TIFFError(tif->tif_name, "Error fetching data for field \"%s\"",
; 684  : 	    _TIFFFieldWithTag(tif, dir->tdir_tag)->field_name);

	mov	eax, DWORD PTR _dir$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	__TIFFFieldWithTag
	add	esp, 8
	mov	eax, DWORD PTR [eax+16]
	push	eax
	push	OFFSET FLAT:$SG66184
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 685  : 	return ((tsize_t) 0);

	xor	eax, eax
$L66156:

; 686  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L66707:
	DD	$L66176
	DD	$L66178
	DD	$L66180
	DD	$L66173
	DD	$L66173
	DD	$L66176
	DD	$L66178
	DD	$L66180
	DD	$L66178
	DD	$L66182
_TIFFFetchData ENDP
_tif$ = 8
_dir$ = 12
_v$ = -4
_ok$ = -8
_TIFFFetchShortPair PROC NEAR

; 811  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 812  : 	uint16 v[2];
; 813  : 	int ok = 0;

	mov	DWORD PTR _ok$[ebp], 0

; 814  : 
; 815  : 	switch (dir->tdir_type) {

	mov	eax, DWORD PTR _dir$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+2]
	mov	DWORD PTR -12+[ebp], ecx
	mov	edx, DWORD PTR -12+[ebp]
	sub	edx, 1
	mov	DWORD PTR -12+[ebp], edx
	cmp	DWORD PTR -12+[ebp], 7
	ja	SHORT $L66309
	mov	eax, DWORD PTR -12+[ebp]
	jmp	DWORD PTR $L66709[eax*4]
$L66312:

; 816  : 	case TIFF_SHORT:
; 817  : 	case TIFF_SSHORT:
; 818  : 		ok = TIFFFetchShortArray(tif, dir, v);

	lea	ecx, DWORD PTR _v$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchShortArray
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _ok$[ebp], eax

; 819  : 		break;

	jmp	SHORT $L66309
$L66313:

; 820  : 	case TIFF_BYTE:
; 821  : 	case TIFF_SBYTE:
; 822  : 		ok  = TIFFFetchByteArray(tif, dir, v);

	lea	ecx, DWORD PTR _v$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchByteArray
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _ok$[ebp], eax
$L66309:

; 825  : 	if (ok)

	cmp	DWORD PTR _ok$[ebp], 0
	je	SHORT $L66314

; 826  : 		TIFFSetField(tif, dir->tdir_tag, v[0], v[1]);

	mov	ecx, DWORD PTR _v$[ebp+2]
	and	ecx, 65535				; 0000ffffH
	push	ecx
	mov	edx, DWORD PTR _v$[ebp]
	and	edx, 65535				; 0000ffffH
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFSetField
	add	esp, 16					; 00000010H
$L66314:

; 827  : 	return (ok);

	mov	eax, DWORD PTR _ok$[ebp]

; 828  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L66709:
	DD	$L66313
	DD	$L66309
	DD	$L66312
	DD	$L66309
	DD	$L66309
	DD	$L66313
	DD	$L66309
	DD	$L66312
_TIFFFetchShortPair ENDP
_tif$ = 8
_dir$ = 12
_v$ = 16
_TIFFFetchByteArray PROC NEAR

; 758  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 759  :     if (dir->tdir_count <= 4) {

	mov	eax, DWORD PTR _dir$[ebp]
	cmp	DWORD PTR [eax+4], 4
	ja	$L66244

; 760  :         /*
; 761  :          * Extract data from offset field.
; 762  :          */
; 763  :         if (tif->tif_header.tiff_magic == TIFF_BIGENDIAN) {

	mov	ecx, DWORD PTR _tif$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+336]
	cmp	edx, 19789				; 00004d4dH
	jne	SHORT $L66245

; 764  :             switch (dir->tdir_count) {

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR -4+[ebp], ecx
	mov	edx, DWORD PTR -4+[ebp]
	sub	edx, 1
	mov	DWORD PTR -4+[ebp], edx
	cmp	DWORD PTR -4+[ebp], 3
	ja	SHORT $L66247
	mov	eax, DWORD PTR -4+[ebp]
	jmp	DWORD PTR $L66711[eax*4]
$L66250:

; 765  :                 case 4: v[3] = (uint16)(dir->tdir_offset & 0xff);

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _v$[ebp]
	mov	WORD PTR [eax+6], dx
$L66252:

; 766  :                 case 3: v[2] = (uint16)((dir->tdir_offset >> 8) & 0xff);

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	shr	edx, 8
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _v$[ebp]
	mov	WORD PTR [eax+4], dx
$L66254:

; 767  :                 case 2: v[1] = (uint16)((dir->tdir_offset >> 16) & 0xff);

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	shr	edx, 16					; 00000010H
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _v$[ebp]
	mov	WORD PTR [eax+2], dx
$L66256:

; 768  :                 case 1: v[0] = (uint16)(dir->tdir_offset >> 24);

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	shr	edx, 24					; 00000018H
	mov	eax, DWORD PTR _v$[ebp]
	mov	WORD PTR [eax], dx
$L66247:

; 770  :         } else {

	jmp	SHORT $L66260
$L66245:

; 771  :             switch (dir->tdir_count) {

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR -8+[ebp], edx
	mov	eax, DWORD PTR -8+[ebp]
	sub	eax, 1
	mov	DWORD PTR -8+[ebp], eax
	cmp	DWORD PTR -8+[ebp], 3
	ja	SHORT $L66260
	mov	ecx, DWORD PTR -8+[ebp]
	jmp	DWORD PTR $L66712[ecx*4]
$L66263:

; 772  :                 case 4: v[3] = (uint16)(dir->tdir_offset >> 24);

	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR [edx+8]
	shr	eax, 24					; 00000018H
	mov	ecx, DWORD PTR _v$[ebp]
	mov	WORD PTR [ecx+6], ax
$L66265:

; 773  :                 case 3: v[2] = (uint16)((dir->tdir_offset >> 16) & 0xff);

	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR [edx+8]
	shr	eax, 16					; 00000010H
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _v$[ebp]
	mov	WORD PTR [ecx+4], ax
$L66267:

; 774  :                 case 2: v[1] = (uint16)((dir->tdir_offset >> 8) & 0xff);

	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR [edx+8]
	shr	eax, 8
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _v$[ebp]
	mov	WORD PTR [ecx+2], ax
$L66269:

; 775  :                 case 1: v[0] = (uint16)(dir->tdir_offset & 0xff);

	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR [edx+8]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _v$[ebp]
	mov	WORD PTR [ecx], ax
$L66260:

; 778  :         return (1);

	mov	eax, 1
	jmp	SHORT $L66271
$L66244:

; 780  :         return (TIFFFetchData(tif, dir, (char*) v) != 0);	/* XXX */

	mov	edx, DWORD PTR _v$[ebp]
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFetchData
	add	esp, 12					; 0000000cH
	neg	eax
	sbb	eax, eax
	neg	eax
$L66271:

; 781  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L66711:
	DD	$L66256
	DD	$L66254
	DD	$L66252
	DD	$L66250
$L66712:
	DD	$L66269
	DD	$L66267
	DD	$L66265
	DD	$L66263
_TIFFFetchByteArray ENDP
_tif$ = 8
_dir$ = 12
_v$ = 16
_TIFFFetchShortArray PROC NEAR

; 788  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 789  : 	if (dir->tdir_count <= 2) {

	mov	eax, DWORD PTR _dir$[ebp]
	cmp	DWORD PTR [eax+4], 2
	ja	$L66280

; 790  : 		if (tif->tif_header.tiff_magic == TIFF_BIGENDIAN) {

	mov	ecx, DWORD PTR _tif$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+336]
	cmp	edx, 19789				; 00004d4dH
	jne	SHORT $L66281

; 791  : 			switch (dir->tdir_count) {

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR -4+[ebp], ecx
	cmp	DWORD PTR -4+[ebp], 1
	je	SHORT $L66288
	cmp	DWORD PTR -4+[ebp], 2
	je	SHORT $L66286
	jmp	SHORT $L66283
$L66286:

; 792  : 			case 2: v[1] = (uint16) (dir->tdir_offset & 0xffff);

	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR [edx+8]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _v$[ebp]
	mov	WORD PTR [ecx+2], ax
$L66288:

; 793  : 			case 1: v[0] = (uint16) (dir->tdir_offset >> 16);

	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR [edx+8]
	shr	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _v$[ebp]
	mov	WORD PTR [ecx], ax
$L66283:

; 795  : 		} else {

	jmp	SHORT $L66292
$L66281:

; 796  : 			switch (dir->tdir_count) {

	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR -8+[ebp], eax
	cmp	DWORD PTR -8+[ebp], 1
	je	SHORT $L66297
	cmp	DWORD PTR -8+[ebp], 2
	je	SHORT $L66295
	jmp	SHORT $L66292
$L66295:

; 797  : 			case 2: v[1] = (uint16) (dir->tdir_offset >> 16);

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	shr	edx, 16					; 00000010H
	mov	eax, DWORD PTR _v$[ebp]
	mov	WORD PTR [eax+2], dx
$L66297:

; 798  : 			case 1: v[0] = (uint16) (dir->tdir_offset & 0xffff);

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _v$[ebp]
	mov	WORD PTR [eax], dx
$L66292:

; 801  : 		return (1);

	mov	eax, 1
	jmp	SHORT $L66299
$L66280:

; 803  : 		return (TIFFFetchData(tif, dir, (char *)v) != 0);

	mov	ecx, DWORD PTR _v$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchData
	add	esp, 12					; 0000000cH
	neg	eax
	sbb	eax, eax
	neg	eax
$L66299:

; 804  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFFetchShortArray ENDP
_tif$ = 8
_dp$ = 12
_ok$ = -8
_fip$ = -4
_cp$66457 = -12
_type$66493 = -16
_v$66495 = -20
_v32$66499 = -24
_v$66502 = -28
_v$66504 = -36
_c$66506 = -40
_TIFFFetchNormalTag PROC NEAR

; 996  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 112				; 00000070H

; 997  : 	static const char mesg[] = "to fetch tag value";
; 998  : 	int ok = 0;

	mov	DWORD PTR _ok$[ebp], 0

; 999  : 	const TIFFFieldInfo* fip = _TIFFFieldWithTag(tif, dp->tdir_tag);

	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	__TIFFFieldWithTag
	add	esp, 8
	mov	DWORD PTR _fip$[ebp], eax

; 1000 : 
; 1001 : 	if (dp->tdir_count > 1) {		/* array of values */

	mov	eax, DWORD PTR _dp$[ebp]
	cmp	DWORD PTR [eax+4], 1
	jbe	$L66456

; 1002 : 		char* cp = NULL;

	mov	DWORD PTR _cp$66457[ebp], 0

; 1003 : 
; 1004 : 		switch (dp->tdir_type) {

	mov	ecx, DWORD PTR _dp$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+2]
	mov	DWORD PTR -44+[ebp], edx
	mov	eax, DWORD PTR -44+[ebp]
	sub	eax, 1
	mov	DWORD PTR -44+[ebp], eax
	cmp	DWORD PTR -44+[ebp], 11			; 0000000bH
	ja	$L66460
	mov	ecx, DWORD PTR -44+[ebp]
	jmp	DWORD PTR $L66747[ecx*4]
$L66463:

; 1005 : 		case TIFF_BYTE:
; 1006 : 		case TIFF_SBYTE:
; 1007 : 			/* NB: always expand BYTE values to shorts */
; 1008 : 			cp = CheckMalloc(tif,
; 1009 : 			    dp->tdir_count * sizeof (uint16), mesg);

	push	OFFSET FLAT:_?mesg@?1??TIFFFetchNormalTag@@9@9
	mov	edx, DWORD PTR _dp$[ebp]
	mov	eax, DWORD PTR [edx+4]
	shl	eax, 1
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_CheckMalloc
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _cp$66457[ebp], eax

; 1010 : 			ok = cp && TIFFFetchByteArray(tif, dp, (uint16*) cp);

	cmp	DWORD PTR _cp$66457[ebp], 0
	je	SHORT $L66715
	mov	edx, DWORD PTR _cp$66457[ebp]
	push	edx
	mov	eax, DWORD PTR _dp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFetchByteArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L66715
	mov	DWORD PTR -48+[ebp], 1
	jmp	SHORT $L66716
$L66715:
	mov	DWORD PTR -48+[ebp], 0
$L66716:
	mov	edx, DWORD PTR -48+[ebp]
	mov	DWORD PTR _ok$[ebp], edx

; 1011 : 			break;

	jmp	$L66460
$L66466:

; 1012 : 		case TIFF_SHORT:
; 1013 : 		case TIFF_SSHORT:
; 1014 : 			cp = CheckMalloc(tif,
; 1015 : 			    dp->tdir_count * sizeof (uint16), mesg);

	push	OFFSET FLAT:_?mesg@?1??TIFFFetchNormalTag@@9@9
	mov	eax, DWORD PTR _dp$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	shl	ecx, 1
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_CheckMalloc
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _cp$66457[ebp], eax

; 1016 : 			ok = cp && TIFFFetchShortArray(tif, dp, (uint16*) cp);

	cmp	DWORD PTR _cp$66457[ebp], 0
	je	SHORT $L66717
	mov	eax, DWORD PTR _cp$66457[ebp]
	push	eax
	mov	ecx, DWORD PTR _dp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFetchShortArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L66717
	mov	DWORD PTR -52+[ebp], 1
	jmp	SHORT $L66718
$L66717:
	mov	DWORD PTR -52+[ebp], 0
$L66718:
	mov	eax, DWORD PTR -52+[ebp]
	mov	DWORD PTR _ok$[ebp], eax

; 1017 : 			break;

	jmp	$L66460
$L66469:

; 1018 : 		case TIFF_LONG:
; 1019 : 		case TIFF_SLONG:
; 1020 : 			cp = CheckMalloc(tif,
; 1021 : 			    dp->tdir_count * sizeof (uint32), mesg);

	push	OFFSET FLAT:_?mesg@?1??TIFFFetchNormalTag@@9@9
	mov	ecx, DWORD PTR _dp$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	shl	edx, 2
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_CheckMalloc
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _cp$66457[ebp], eax

; 1022 : 			ok = cp && TIFFFetchLongArray(tif, dp, (uint32*) cp);

	cmp	DWORD PTR _cp$66457[ebp], 0
	je	SHORT $L66719
	mov	ecx, DWORD PTR _cp$66457[ebp]
	push	ecx
	mov	edx, DWORD PTR _dp$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchLongArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L66719
	mov	DWORD PTR -56+[ebp], 1
	jmp	SHORT $L66720
$L66719:
	mov	DWORD PTR -56+[ebp], 0
$L66720:
	mov	ecx, DWORD PTR -56+[ebp]
	mov	DWORD PTR _ok$[ebp], ecx

; 1023 : 			break;

	jmp	$L66460
$L66472:

; 1024 : 		case TIFF_RATIONAL:
; 1025 : 		case TIFF_SRATIONAL:
; 1026 : 			cp = CheckMalloc(tif,
; 1027 : 			    dp->tdir_count * sizeof (float), mesg);

	push	OFFSET FLAT:_?mesg@?1??TIFFFetchNormalTag@@9@9
	mov	edx, DWORD PTR _dp$[ebp]
	mov	eax, DWORD PTR [edx+4]
	shl	eax, 2
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_CheckMalloc
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _cp$66457[ebp], eax

; 1028 : 			ok = cp && TIFFFetchRationalArray(tif, dp, (float*) cp);

	cmp	DWORD PTR _cp$66457[ebp], 0
	je	SHORT $L66721
	mov	edx, DWORD PTR _cp$66457[ebp]
	push	edx
	mov	eax, DWORD PTR _dp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFetchRationalArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L66721
	mov	DWORD PTR -60+[ebp], 1
	jmp	SHORT $L66722
$L66721:
	mov	DWORD PTR -60+[ebp], 0
$L66722:
	mov	edx, DWORD PTR -60+[ebp]
	mov	DWORD PTR _ok$[ebp], edx

; 1029 : 			break;

	jmp	$L66460
$L66475:

; 1030 : 		case TIFF_FLOAT:
; 1031 : 			cp = CheckMalloc(tif,
; 1032 : 			    dp->tdir_count * sizeof (float), mesg);

	push	OFFSET FLAT:_?mesg@?1??TIFFFetchNormalTag@@9@9
	mov	eax, DWORD PTR _dp$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	shl	ecx, 2
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_CheckMalloc
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _cp$66457[ebp], eax

; 1033 : 			ok = cp && TIFFFetchFloatArray(tif, dp, (float*) cp);

	cmp	DWORD PTR _cp$66457[ebp], 0
	je	SHORT $L66723
	mov	eax, DWORD PTR _cp$66457[ebp]
	push	eax
	mov	ecx, DWORD PTR _dp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFetchFloatArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L66723
	mov	DWORD PTR -64+[ebp], 1
	jmp	SHORT $L66724
$L66723:
	mov	DWORD PTR -64+[ebp], 0
$L66724:
	mov	eax, DWORD PTR -64+[ebp]
	mov	DWORD PTR _ok$[ebp], eax

; 1034 : 			break;

	jmp	$L66460
$L66478:

; 1035 : 		case TIFF_DOUBLE:
; 1036 : 			cp = CheckMalloc(tif,
; 1037 : 			    dp->tdir_count * sizeof (double), mesg);

	push	OFFSET FLAT:_?mesg@?1??TIFFFetchNormalTag@@9@9
	mov	ecx, DWORD PTR _dp$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	shl	edx, 3
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_CheckMalloc
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _cp$66457[ebp], eax

; 1038 : 			ok = cp && TIFFFetchDoubleArray(tif, dp, (double*) cp);

	cmp	DWORD PTR _cp$66457[ebp], 0
	je	SHORT $L66725
	mov	ecx, DWORD PTR _cp$66457[ebp]
	push	ecx
	mov	edx, DWORD PTR _dp$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchDoubleArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L66725
	mov	DWORD PTR -68+[ebp], 1
	jmp	SHORT $L66726
$L66725:
	mov	DWORD PTR -68+[ebp], 0
$L66726:
	mov	ecx, DWORD PTR -68+[ebp]
	mov	DWORD PTR _ok$[ebp], ecx

; 1039 : 			break;

	jmp	SHORT $L66460
$L66481:

; 1040 : 		case TIFF_ASCII:
; 1041 : 		case TIFF_UNDEFINED:		/* bit of a cheat... */
; 1042 : 			/*
; 1043 : 			 * Some vendors write strings w/o the trailing
; 1044 : 			 * NULL byte, so always append one just in case.
; 1045 : 			 */
; 1046 : 			cp = CheckMalloc(tif, dp->tdir_count+1, mesg);

	push	OFFSET FLAT:_?mesg@?1??TIFFFetchNormalTag@@9@9
	mov	edx, DWORD PTR _dp$[ebp]
	mov	eax, DWORD PTR [edx+4]
	add	eax, 1
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_CheckMalloc
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _cp$66457[ebp], eax

; 1047 : 			if( (ok = (cp && TIFFFetchString(tif, dp, cp))) != 0 )

	cmp	DWORD PTR _cp$66457[ebp], 0
	je	SHORT $L66727
	mov	edx, DWORD PTR _cp$66457[ebp]
	push	edx
	mov	eax, DWORD PTR _dp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFetchString
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L66727
	mov	DWORD PTR -72+[ebp], 1
	jmp	SHORT $L66728
$L66727:
	mov	DWORD PTR -72+[ebp], 0
$L66728:
	mov	edx, DWORD PTR -72+[ebp]
	mov	DWORD PTR _ok$[ebp], edx
	cmp	DWORD PTR _ok$[ebp], 0
	je	SHORT $L66482

; 1048 : 				cp[dp->tdir_count] = '\0';	/* XXX */

	mov	eax, DWORD PTR _dp$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	mov	edx, DWORD PTR _cp$66457[ebp]
	mov	BYTE PTR [edx+ecx], 0
$L66482:
$L66460:

; 1051 : 		if (ok) {

	cmp	DWORD PTR _ok$[ebp], 0
	je	SHORT $L66483

; 1052 : 			ok = (fip->field_passcount ?
; 1053 : 			    TIFFSetField(tif, dp->tdir_tag, dp->tdir_count, cp)
; 1054 : 			  : TIFFSetField(tif, dp->tdir_tag, cp));

	mov	eax, DWORD PTR _fip$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+15]
	test	ecx, ecx
	je	SHORT $L66729
	mov	edx, DWORD PTR _cp$66457[ebp]
	push	edx
	mov	eax, DWORD PTR _dp$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR _dp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFSetField
	add	esp, 16					; 00000010H
	mov	DWORD PTR -76+[ebp], eax
	jmp	SHORT $L66730
$L66729:
	mov	edx, DWORD PTR _cp$66457[ebp]
	push	edx
	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFSetField
	add	esp, 12					; 0000000cH
	mov	DWORD PTR -76+[ebp], eax
$L66730:
	mov	eax, DWORD PTR -76+[ebp]
	mov	DWORD PTR _ok$[ebp], eax
$L66483:

; 1056 : 		if (cp != NULL)

	cmp	DWORD PTR _cp$66457[ebp], 0
	je	SHORT $L66485

; 1057 : 			_TIFFfree(cp);

	mov	ecx, DWORD PTR _cp$66457[ebp]
	push	ecx
	call	__TIFFfree
	add	esp, 4
$L66485:

; 1058 : 	} else if (CheckDirCount(tif, dp, 1)) {	/* singleton value */

	jmp	$L66489
$L66456:
	push	1
	mov	edx, DWORD PTR _dp$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_CheckDirCount
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	$L66489

; 1059 : 		switch (dp->tdir_type) {

	mov	ecx, DWORD PTR _dp$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+2]
	mov	DWORD PTR -80+[ebp], edx
	mov	eax, DWORD PTR -80+[ebp]
	sub	eax, 1
	mov	DWORD PTR -80+[ebp], eax
	cmp	DWORD PTR -80+[ebp], 11			; 0000000bH
	ja	$L66489
	mov	ecx, DWORD PTR -80+[ebp]
	jmp	DWORD PTR $L66748[ecx*4]
$L66492:

; 1060 : 		case TIFF_BYTE:
; 1061 : 		case TIFF_SBYTE:
; 1062 : 		case TIFF_SHORT:
; 1063 : 		case TIFF_SSHORT:
; 1064 : 			/*
; 1065 : 			 * If the tag is also acceptable as a LONG or SLONG
; 1066 : 			 * then TIFFSetField will expect an uint32 parameter
; 1067 : 			 * passed to it (through varargs).  Thus, for machines
; 1068 : 			 * where sizeof (int) != sizeof (uint32) we must do
; 1069 : 			 * a careful check here.  It's hard to say if this
; 1070 : 			 * is worth optimizing.
; 1071 : 			 *
; 1072 : 			 * NB: We use TIFFFieldWithTag here knowing that
; 1073 : 			 *     it returns us the first entry in the table
; 1074 : 			 *     for the tag and that that entry is for the
; 1075 : 			 *     widest potential data type the tag may have.
; 1076 : 			 */
; 1077 : 			{ TIFFDataType type = fip->field_type;

	mov	edx, DWORD PTR _fip$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	DWORD PTR _type$66493[ebp], eax

; 1078 : 			  if (type != TIFF_LONG && type != TIFF_SLONG) {

	cmp	DWORD PTR _type$66493[ebp], 4
	je	$L66494
	cmp	DWORD PTR _type$66493[ebp], 9
	je	$L66494

; 1079 : 				uint16 v = (uint16)
; 1080 : 			   TIFFExtractData(tif, dp->tdir_type, dp->tdir_offset);

	mov	ecx, DWORD PTR _tif$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+336]
	cmp	edx, 19789				; 00004d4dH
	jne	SHORT $L66731
	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+2]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+348]
	mov	edx, DWORD PTR _dp$[ebp]
	mov	edx, DWORD PTR [edx+8]
	mov	ecx, DWORD PTR [eax+ecx*4]
	shr	edx, cl
	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+2]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [eax+352]
	and	edx, DWORD PTR [eax+ecx*4]
	mov	DWORD PTR -84+[ebp], edx
	jmp	SHORT $L66732
$L66731:
	mov	ecx, DWORD PTR _dp$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+2]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+352]
	mov	eax, DWORD PTR _dp$[ebp]
	mov	eax, DWORD PTR [eax+8]
	and	eax, DWORD PTR [ecx+edx*4]
	mov	DWORD PTR -84+[ebp], eax
$L66732:
	mov	cx, WORD PTR -84+[ebp]
	mov	WORD PTR _v$66495[ebp], cx

; 1081 : 				ok = (fip->field_passcount ?
; 1082 : 				    TIFFSetField(tif, dp->tdir_tag, 1, &v)
; 1083 : 				  : TIFFSetField(tif, dp->tdir_tag, v));

	mov	edx, DWORD PTR _fip$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+15]
	test	eax, eax
	je	SHORT $L66733
	lea	ecx, DWORD PTR _v$66495[ebp]
	push	ecx
	push	1
	mov	edx, DWORD PTR _dp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFSetField
	add	esp, 16					; 00000010H
	mov	DWORD PTR -88+[ebp], eax
	jmp	SHORT $L66734
$L66733:
	mov	edx, DWORD PTR _v$66495[ebp]
	and	edx, 65535				; 0000ffffH
	push	edx
	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFSetField
	add	esp, 12					; 0000000cH
	mov	DWORD PTR -88+[ebp], eax
$L66734:
	mov	eax, DWORD PTR -88+[ebp]
	mov	DWORD PTR _ok$[ebp], eax

; 1084 : 				break;

	jmp	$L66489
$L66494:

; 1091 : 		    TIFFExtractData(tif, dp->tdir_type, dp->tdir_offset);

	mov	ecx, DWORD PTR _tif$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+336]
	cmp	edx, 19789				; 00004d4dH
	jne	SHORT $L66735
	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+2]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+348]
	mov	edx, DWORD PTR _dp$[ebp]
	mov	edx, DWORD PTR [edx+8]
	mov	ecx, DWORD PTR [eax+ecx*4]
	shr	edx, cl
	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+2]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [eax+352]
	and	edx, DWORD PTR [eax+ecx*4]
	mov	DWORD PTR -92+[ebp], edx
	jmp	SHORT $L66736
$L66735:
	mov	ecx, DWORD PTR _dp$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+2]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+352]
	mov	eax, DWORD PTR _dp$[ebp]
	mov	eax, DWORD PTR [eax+8]
	and	eax, DWORD PTR [ecx+edx*4]
	mov	DWORD PTR -92+[ebp], eax
$L66736:
	mov	ecx, DWORD PTR -92+[ebp]
	mov	DWORD PTR _v32$66499[ebp], ecx

; 1092 : 			  ok = (fip->field_passcount ? 
; 1093 : 			      TIFFSetField(tif, dp->tdir_tag, 1, &v32)
; 1094 : 			    : TIFFSetField(tif, dp->tdir_tag, v32));

	mov	edx, DWORD PTR _fip$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+15]
	test	eax, eax
	je	SHORT $L66737
	lea	ecx, DWORD PTR _v32$66499[ebp]
	push	ecx
	push	1
	mov	edx, DWORD PTR _dp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFSetField
	add	esp, 16					; 00000010H
	mov	DWORD PTR -96+[ebp], eax
	jmp	SHORT $L66738
$L66737:
	mov	edx, DWORD PTR _v32$66499[ebp]
	push	edx
	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFSetField
	add	esp, 12					; 0000000cH
	mov	DWORD PTR -96+[ebp], eax
$L66738:
	mov	eax, DWORD PTR -96+[ebp]
	mov	DWORD PTR _ok$[ebp], eax

; 1096 : 			break;

	jmp	$L66489
$L66501:

; 1101 : 			      TIFFFetchFloat(tif, dp)
; 1102 : 			    : TIFFFetchRational(tif, dp));

	mov	ecx, DWORD PTR _dp$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+2]
	cmp	edx, 11					; 0000000bH
	jne	SHORT $L66739
	mov	eax, DWORD PTR _dp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFetchFloat
	add	esp, 8
	fstp	DWORD PTR -100+[ebp]
	jmp	SHORT $L66740
$L66739:
	mov	edx, DWORD PTR _dp$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchRational
	add	esp, 8
	fstp	DWORD PTR -100+[ebp]
$L66740:
	mov	ecx, DWORD PTR -100+[ebp]
	mov	DWORD PTR _v$66502[ebp], ecx

; 1103 : 			  ok = (fip->field_passcount ?
; 1104 : 			      TIFFSetField(tif, dp->tdir_tag, 1, &v)
; 1105 : 			    : TIFFSetField(tif, dp->tdir_tag, v));

	mov	edx, DWORD PTR _fip$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+15]
	test	eax, eax
	je	SHORT $L66741
	lea	ecx, DWORD PTR _v$66502[ebp]
	push	ecx
	push	1
	mov	edx, DWORD PTR _dp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFSetField
	add	esp, 16					; 00000010H
	mov	DWORD PTR -104+[ebp], eax
	jmp	SHORT $L66742
$L66741:
	fld	DWORD PTR _v$66502[ebp]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	edx, DWORD PTR _dp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFSetField
	add	esp, 16					; 00000010H
	mov	DWORD PTR -104+[ebp], eax
$L66742:
	mov	edx, DWORD PTR -104+[ebp]
	mov	DWORD PTR _ok$[ebp], edx

; 1107 : 			break;

	jmp	$L66489
$L66503:

; 1110 : 			  ok = (TIFFFetchDoubleArray(tif, dp, &v) &&
; 1111 : 			    (fip->field_passcount ?
; 1112 : 			      TIFFSetField(tif, dp->tdir_tag, 1, &v)
; 1113 : 			    : TIFFSetField(tif, dp->tdir_tag, v))
; 1114 : 			  );

	lea	eax, DWORD PTR _v$66504[ebp]
	push	eax
	mov	ecx, DWORD PTR _dp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFetchDoubleArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L66745
	mov	eax, DWORD PTR _fip$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+15]
	test	ecx, ecx
	je	SHORT $L66743
	lea	edx, DWORD PTR _v$66504[ebp]
	push	edx
	push	1
	mov	eax, DWORD PTR _dp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFSetField
	add	esp, 16					; 00000010H
	mov	DWORD PTR -108+[ebp], eax
	jmp	SHORT $L66744
$L66743:
	mov	eax, DWORD PTR _v$66504[ebp+4]
	push	eax
	mov	ecx, DWORD PTR _v$66504[ebp]
	push	ecx
	mov	edx, DWORD PTR _dp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFSetField
	add	esp, 16					; 00000010H
	mov	DWORD PTR -108+[ebp], eax
$L66744:
	cmp	DWORD PTR -108+[ebp], 0
	je	SHORT $L66745
	mov	DWORD PTR -112+[ebp], 1
	jmp	SHORT $L66746
$L66745:
	mov	DWORD PTR -112+[ebp], 0
$L66746:
	mov	edx, DWORD PTR -112+[ebp]
	mov	DWORD PTR _ok$[ebp], edx

; 1116 : 			break;

	jmp	SHORT $L66489
$L66505:

; 1120 : 			  if( (ok = (TIFFFetchString(tif, dp, c) != 0)) != 0 ){

	lea	eax, DWORD PTR _c$66506[ebp]
	push	eax
	mov	ecx, DWORD PTR _dp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFetchString
	add	esp, 12					; 0000000cH
	neg	eax
	sbb	eax, eax
	neg	eax
	mov	DWORD PTR _ok$[ebp], eax
	cmp	DWORD PTR _ok$[ebp], 0
	je	SHORT $L66507

; 1121 : 				c[1] = '\0';		/* XXX paranoid */

	mov	BYTE PTR _c$66506[ebp+1], 0

; 1122 : 				ok = TIFFSetField(tif, dp->tdir_tag, c);

	lea	eax, DWORD PTR _c$66506[ebp]
	push	eax
	mov	ecx, DWORD PTR _dp$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFSetField
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _ok$[ebp], eax
$L66507:
$L66489:

; 1128 : 	return (ok);

	mov	eax, DWORD PTR _ok$[ebp]

; 1129 : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L66747:
	DD	$L66463
	DD	$L66481
	DD	$L66466
	DD	$L66469
	DD	$L66472
	DD	$L66463
	DD	$L66481
	DD	$L66466
	DD	$L66469
	DD	$L66472
	DD	$L66475
	DD	$L66478
$L66748:
	DD	$L66492
	DD	$L66505
	DD	$L66492
	DD	$L66494
	DD	$L66501
	DD	$L66492
	DD	$L66505
	DD	$L66492
	DD	$L66494
	DD	$L66501
	DD	$L66501
	DD	$L66503
_TIFFFetchNormalTag ENDP
_tif$ = 8
_dir$ = 12
_cp$ = 16
_l$66194 = -4
_TIFFFetchString PROC NEAR

; 693  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 694  : 	if (dir->tdir_count <= 4) {

	mov	eax, DWORD PTR _dir$[ebp]
	cmp	DWORD PTR [eax+4], 4
	ja	SHORT $L66193

; 695  : 		uint32 l = dir->tdir_offset;

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR _l$66194[ebp], edx

; 696  : 		if (tif->tif_flags & TIFF_SWAB)

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 128				; 00000080H
	test	ecx, ecx
	je	SHORT $L66195

; 697  : 			TIFFSwabLong(&l);

	lea	edx, DWORD PTR _l$66194[ebp]
	push	edx
	call	_TIFFSwabLong
	add	esp, 4
$L66195:

; 698  : 		_TIFFmemcpy(cp, &l, dir->tdir_count);

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	lea	edx, DWORD PTR _l$66194[ebp]
	push	edx
	mov	eax, DWORD PTR _cp$[ebp]
	push	eax
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH

; 699  : 		return (1);

	mov	eax, 1
	jmp	SHORT $L66192
$L66193:

; 701  : 	return (TIFFFetchData(tif, dir, cp));

	mov	ecx, DWORD PTR _cp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchData
	add	esp, 12					; 0000000cH
$L66192:

; 702  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFFetchString ENDP
_tif$ = 8
_dir$ = 12
_l$ = -12
_v$ = -4
_TIFFFetchRational PROC NEAR

; 731  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 732  : 	uint32 l[2];
; 733  : 	float v;
; 734  : 
; 735  : 	return (!TIFFFetchData(tif, dir, (char *)l) ||
; 736  : 	    !cvtRational(tif, dir, l[0], l[1], &v) ? 1.0f : v);

	lea	eax, DWORD PTR _l$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFetchData
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L66751
	lea	eax, DWORD PTR _v$[ebp]
	push	eax
	mov	ecx, DWORD PTR _l$[ebp+4]
	push	ecx
	mov	edx, DWORD PTR _l$[ebp]
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_cvtRational
	add	esp, 20					; 00000014H
	test	eax, eax
	je	SHORT $L66751
	mov	edx, DWORD PTR _v$[ebp]
	mov	DWORD PTR -16+[ebp], edx
	jmp	SHORT $L66752
$L66751:
	mov	DWORD PTR -16+[ebp], 1065353216		; 3f800000H
$L66752:
	fld	DWORD PTR -16+[ebp]

; 737  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFFetchRational ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+1
$SG66209 DB	'%s: Rational with zero denominator (num = %lu)', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_dir$ = 12
_num$ = 16
_denom$ = 20
_rv$ = 24
_cvtRational PROC NEAR

; 709  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 710  : 	if (denom == 0) {

	cmp	DWORD PTR _denom$[ebp], 0
	jne	SHORT $L66208

; 711  : 		TIFFError(tif->tif_name,
; 712  : 		    "%s: Rational with zero denominator (num = %lu)",
; 713  : 		    _TIFFFieldWithTag(tif, dir->tdir_tag)->field_name, num);

	mov	eax, DWORD PTR _num$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	__TIFFFieldWithTag
	add	esp, 8
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:$SG66209
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 16					; 00000010H

; 714  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L66210
$L66208:

; 716  : 		if (dir->tdir_type == TIFF_RATIONAL)

	mov	ecx, DWORD PTR _dir$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+2]
	cmp	edx, 5
	jne	SHORT $L66211

; 717  : 			*rv = ((float)num / (float)denom);

	mov	eax, DWORD PTR _num$[ebp]
	mov	DWORD PTR -8+[ebp], eax
	mov	DWORD PTR -8+[ebp+4], 0
	fild	QWORD PTR -8+[ebp]
	mov	ecx, DWORD PTR _denom$[ebp]
	mov	DWORD PTR -16+[ebp], ecx
	mov	DWORD PTR -16+[ebp+4], 0
	fidiv	DWORD PTR -16+[ebp]
	mov	edx, DWORD PTR _rv$[ebp]
	fstp	DWORD PTR [edx]

; 718  : 		else

	jmp	SHORT $L66214
$L66211:

; 719  : 			*rv = ((float)(int32)num / (float)(int32)denom);

	fild	DWORD PTR _num$[ebp]
	fidiv	DWORD PTR _denom$[ebp]
	mov	eax, DWORD PTR _rv$[ebp]
	fstp	DWORD PTR [eax]
$L66214:

; 720  : 		return (1);

	mov	eax, 1
$L66210:

; 722  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_cvtRational ENDP
_tif$ = 8
_dir$ = 12
_l$ = -8
_v$ = -4
_TIFFFetchFloat PROC NEAR

; 746  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH
	push	esi

; 747  : 	long l = TIFFExtractData(tif, dir->tdir_type, dir->tdir_offset);

	mov	eax, DWORD PTR _tif$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+336]
	cmp	ecx, 19789				; 00004d4dH
	jne	SHORT $L66755
	mov	edx, DWORD PTR _dir$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+2]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+348]
	mov	ecx, DWORD PTR _dir$[ebp]
	mov	esi, DWORD PTR [ecx+8]
	mov	ecx, DWORD PTR [edx+eax*4]
	shr	esi, cl
	mov	edx, DWORD PTR _dir$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+2]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+352]
	and	esi, DWORD PTR [edx+eax*4]
	mov	DWORD PTR -12+[ebp], esi
	jmp	SHORT $L66756
$L66755:
	mov	eax, DWORD PTR _dir$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+2]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+352]
	mov	edx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [edx+8]
	and	edx, DWORD PTR [eax+ecx*4]
	mov	DWORD PTR -12+[ebp], edx
$L66756:
	mov	eax, DWORD PTR -12+[ebp]
	mov	DWORD PTR _l$[ebp], eax

; 748  : 	float v = *(float*) &l;

	mov	ecx, DWORD PTR _l$[ebp]
	mov	DWORD PTR _v$[ebp], ecx

; 749  : 	TIFFCvtIEEEFloatToNative(tif, 1, &v);
; 750  : 	return (v);

	fld	DWORD PTR _v$[ebp]

; 751  : }

	pop	esi
	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFFetchFloat ENDP
_tif$ = 8
_dir$ = 12
_v$ = 16
_TIFFFetchLongArray PROC NEAR

; 835  : {

	push	ebp
	mov	ebp, esp

; 836  : 	if (dir->tdir_count == 1) {

	mov	eax, DWORD PTR _dir$[ebp]
	cmp	DWORD PTR [eax+4], 1
	jne	SHORT $L66323

; 837  : 		v[0] = dir->tdir_offset;

	mov	ecx, DWORD PTR _v$[ebp]
	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	DWORD PTR [ecx], eax

; 838  : 		return (1);

	mov	eax, 1
	jmp	SHORT $L66324
$L66323:

; 840  : 		return (TIFFFetchData(tif, dir, (char*) v) != 0);

	mov	ecx, DWORD PTR _v$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchData
	add	esp, 12					; 0000000cH
	neg	eax
	sbb	eax, eax
	neg	eax
$L66324:

; 841  : }

	pop	ebp
	ret	0
_TIFFFetchLongArray ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+1
$SG66337 DB	'to fetch array of rationals', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_dir$ = 12
_v$ = 16
_ok$ = -8
_l$ = -4
_i$66341 = -12
_TIFFFetchRationalArray PROC NEAR

; 848  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 849  : 	int ok = 0;

	mov	DWORD PTR _ok$[ebp], 0

; 850  : 	uint32* l;
; 851  : 
; 852  : 	l = (uint32*)CheckMalloc(tif,
; 853  : 	    dir->tdir_count*tiffDataWidth[dir->tdir_type],
; 854  : 	    "to fetch array of rationals");

	push	OFFSET FLAT:$SG66337
	mov	eax, DWORD PTR _dir$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+2]
	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR [edx+4]
	imul	eax, DWORD PTR _tiffDataWidth[ecx*4]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_CheckMalloc
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _l$[ebp], eax

; 855  : 	if (l) {

	cmp	DWORD PTR _l$[ebp], 0
	je	$L66338

; 856  : 		if (TIFFFetchData(tif, dir, (char *)l)) {

	mov	edx, DWORD PTR _l$[ebp]
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFetchData
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L66344

; 857  : 			uint32 i;
; 858  : 			for (i = 0; i < dir->tdir_count; i++) {

	mov	DWORD PTR _i$66341[ebp], 0
	jmp	SHORT $L66342
$L66343:
	mov	edx, DWORD PTR _i$66341[ebp]
	add	edx, 1
	mov	DWORD PTR _i$66341[ebp], edx
$L66342:
	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR _i$66341[ebp]
	cmp	ecx, DWORD PTR [eax+4]
	jae	SHORT $L66344

; 859  : 				ok = cvtRational(tif, dir,
; 860  : 				    l[2*i+0], l[2*i+1], &v[i]);

	mov	edx, DWORD PTR _i$66341[ebp]
	mov	eax, DWORD PTR _v$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	push	ecx
	mov	edx, DWORD PTR _i$66341[ebp]
	shl	edx, 1
	mov	eax, DWORD PTR _l$[ebp]
	mov	ecx, DWORD PTR [eax+edx*4+4]
	push	ecx
	mov	edx, DWORD PTR _i$66341[ebp]
	shl	edx, 1
	mov	eax, DWORD PTR _l$[ebp]
	mov	ecx, DWORD PTR [eax+edx*4]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_cvtRational
	add	esp, 20					; 00000014H
	mov	DWORD PTR _ok$[ebp], eax

; 861  : 				if (!ok)

	cmp	DWORD PTR _ok$[ebp], 0
	jne	SHORT $L66345

; 862  : 					break;

	jmp	SHORT $L66344
$L66345:

; 863  : 			}

	jmp	SHORT $L66343
$L66344:

; 865  : 		_TIFFfree((char *)l);

	mov	ecx, DWORD PTR _l$[ebp]
	push	ecx
	call	__TIFFfree
	add	esp, 4
$L66338:

; 867  : 	return (ok);

	mov	eax, DWORD PTR _ok$[ebp]

; 868  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFFetchRationalArray ENDP
_tif$ = 8
_dir$ = 12
_v$ = 16
_TIFFFetchFloatArray PROC NEAR

; 875  : {

	push	ebp
	mov	ebp, esp

; 876  : 
; 877  : 	if (dir->tdir_count == 1) {

	mov	eax, DWORD PTR _dir$[ebp]
	cmp	DWORD PTR [eax+4], 1
	jne	SHORT $L66354

; 878  : 		v[0] = *(float*) &dir->tdir_offset;

	mov	ecx, DWORD PTR _v$[ebp]
	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	DWORD PTR [ecx], eax

; 879  : 		TIFFCvtIEEEFloatToNative(tif, dir->tdir_count, v);
; 880  : 		return (1);

	mov	eax, 1
	jmp	SHORT $L66359
$L66354:

; 881  : 	} else	if (TIFFFetchData(tif, dir, (char*) v)) {

	mov	ecx, DWORD PTR _v$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchData
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L66358

; 882  : 		TIFFCvtIEEEFloatToNative(tif, dir->tdir_count, v);
; 883  : 		return (1);

	mov	eax, 1
	jmp	SHORT $L66359
$L66358:

; 885  : 		return (0);

	xor	eax, eax
$L66359:

; 886  : }

	pop	ebp
	ret	0
_TIFFFetchFloatArray ENDP
_tif$ = 8
_dir$ = 12
_v$ = 16
_TIFFFetchDoubleArray PROC NEAR

; 893  : {

	push	ebp
	mov	ebp, esp

; 894  : 	if (TIFFFetchData(tif, dir, (char*) v)) {

	mov	eax, DWORD PTR _v$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFetchData
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L66368

; 895  : 		TIFFCvtIEEEDoubleToNative(tif, dir->tdir_count, v);
; 896  : 		return (1);

	mov	eax, 1
	jmp	SHORT $L66369
$L66368:

; 898  : 		return (0);

	xor	eax, eax
$L66369:

; 899  : }

	pop	ebp
	ret	0
_TIFFFetchDoubleArray ENDP
_TEXT	ENDS
_DATA	SEGMENT
$SG66531 DB	'Cannot handle different per-sample values for field "%s"'
	DB	00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_dir$ = 12
_pl$ = 16
_samples$ = -4
_status$ = -8
_buf$66520 = -28
_v$66521 = -32
_i$66526 = -36
_TIFFFetchPerSampleShorts PROC NEAR

; 1139 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 36					; 00000024H

; 1140 : 	int samples = tif->tif_dir.td_samplesperpixel;

	mov	eax, DWORD PTR _tif$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+78]
	mov	DWORD PTR _samples$[ebp], ecx

; 1141 : 	int status = 0;

	mov	DWORD PTR _status$[ebp], 0

; 1142 : 
; 1143 : 	if (CheckDirCount(tif, dir, (uint32) samples)) {

	mov	edx, DWORD PTR _samples$[ebp]
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_CheckDirCount
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	$L66533

; 1144 : 		uint16 buf[10];
; 1145 : 		uint16* v = buf;

	lea	edx, DWORD PTR _buf$66520[ebp]
	mov	DWORD PTR _v$66521[ebp], edx

; 1146 : 
; 1147 : 		if (samples > NITEMS(buf))

	cmp	DWORD PTR _samples$[ebp], 10		; 0000000aH
	jbe	SHORT $L66522

; 1148 : 			v = (uint16*) _TIFFmalloc(samples * sizeof (uint16));

	mov	eax, DWORD PTR _samples$[ebp]
	shl	eax, 1
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	DWORD PTR _v$66521[ebp], eax
$L66522:

; 1149 : 		if (TIFFFetchShortArray(tif, dir, v)) {

	mov	ecx, DWORD PTR _v$66521[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchShortArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $bad$66532

; 1150 : 			int i;
; 1151 : 			for (i = 1; i < samples; i++)

	mov	DWORD PTR _i$66526[ebp], 1
	jmp	SHORT $L66527
$L66528:
	mov	ecx, DWORD PTR _i$66526[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$66526[ebp], ecx
$L66527:
	mov	edx, DWORD PTR _i$66526[ebp]
	cmp	edx, DWORD PTR _samples$[ebp]
	jge	SHORT $L66529

; 1152 : 				if (v[i] != v[0]) {

	mov	eax, DWORD PTR _i$66526[ebp]
	mov	ecx, DWORD PTR _v$66521[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+eax*2]
	mov	eax, DWORD PTR _v$66521[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	cmp	edx, ecx
	je	SHORT $L66530

; 1153 : 					TIFFError(tif->tif_name,
; 1154 : 		"Cannot handle different per-sample values for field \"%s\"",
; 1155 : 			   _TIFFFieldWithTag(tif, dir->tdir_tag)->field_name);

	mov	edx, DWORD PTR _dir$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	__TIFFFieldWithTag
	add	esp, 8
	mov	edx, DWORD PTR [eax+16]
	push	edx
	push	OFFSET FLAT:$SG66531
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 1156 : 					goto bad;

	jmp	SHORT $bad$66532
$L66530:

; 1158 : 			*pl = v[0];

	jmp	SHORT $L66528
$L66529:
	mov	edx, DWORD PTR _v$66521[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	mov	ecx, DWORD PTR _pl$[ebp]
	mov	DWORD PTR [ecx], eax

; 1159 : 			status = 1;

	mov	DWORD PTR _status$[ebp], 1
$bad$66532:

; 1161 : 	bad:
; 1162 : 		if (v != buf)

	mov	edx, DWORD PTR _v$66521[ebp]
	lea	eax, DWORD PTR _buf$66520[ebp]
	cmp	edx, eax
	je	SHORT $L66533

; 1163 : 			_TIFFfree((char*) v);

	mov	ecx, DWORD PTR _v$66521[ebp]
	push	ecx
	call	__TIFFfree
	add	esp, 4
$L66533:

; 1165 : 	return (status);

	mov	eax, DWORD PTR _status$[ebp]

; 1166 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFFetchPerSampleShorts ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+3
$SG66558 DB	'Cannot handle different per-sample values for field "%s"'
	DB	00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_dir$ = 12
_pl$ = 16
_samples$ = -4
_status$ = -8
_buf$66547 = -88
_v$66548 = -92
_i$66553 = -96
_TIFFFetchPerSampleAnys PROC NEAR

; 1175 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 96					; 00000060H

; 1176 : 	int samples = (int) tif->tif_dir.td_samplesperpixel;

	mov	eax, DWORD PTR _tif$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+78]
	mov	DWORD PTR _samples$[ebp], ecx

; 1177 : 	int status = 0;

	mov	DWORD PTR _status$[ebp], 0

; 1178 : 
; 1179 : 	if (CheckDirCount(tif, dir, (uint32) samples)) {

	mov	edx, DWORD PTR _samples$[ebp]
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_CheckDirCount
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	$L66560

; 1180 : 		double buf[10];
; 1181 : 		double* v = buf;

	lea	edx, DWORD PTR _buf$66547[ebp]
	mov	DWORD PTR _v$66548[ebp], edx

; 1182 : 
; 1183 : 		if (samples > NITEMS(buf))

	cmp	DWORD PTR _samples$[ebp], 10		; 0000000aH
	jbe	SHORT $L66549

; 1184 : 			v = (double*) _TIFFmalloc(samples * sizeof (double));

	mov	eax, DWORD PTR _samples$[ebp]
	shl	eax, 3
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	DWORD PTR _v$66548[ebp], eax
$L66549:

; 1185 : 		if (TIFFFetchAnyArray(tif, dir, v)) {

	mov	ecx, DWORD PTR _v$66548[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchAnyArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $bad$66559

; 1186 : 			int i;
; 1187 : 			for (i = 1; i < samples; i++)

	mov	DWORD PTR _i$66553[ebp], 1
	jmp	SHORT $L66554
$L66555:
	mov	ecx, DWORD PTR _i$66553[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$66553[ebp], ecx
$L66554:
	mov	edx, DWORD PTR _i$66553[ebp]
	cmp	edx, DWORD PTR _samples$[ebp]
	jge	SHORT $L66556

; 1188 : 				if (v[i] != v[0]) {

	mov	eax, DWORD PTR _i$66553[ebp]
	mov	ecx, DWORD PTR _v$66548[ebp]
	mov	edx, DWORD PTR _v$66548[ebp]
	fld	QWORD PTR [ecx+eax*8]
	fcomp	QWORD PTR [edx]
	fnstsw	ax
	test	ah, 64					; 00000040H
	jne	SHORT $L66557

; 1189 : 					TIFFError(tif->tif_name,
; 1190 : 		"Cannot handle different per-sample values for field \"%s\"",
; 1191 : 			   _TIFFFieldWithTag(tif, dir->tdir_tag)->field_name);

	mov	eax, DWORD PTR _dir$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	__TIFFFieldWithTag
	add	esp, 8
	mov	eax, DWORD PTR [eax+16]
	push	eax
	push	OFFSET FLAT:$SG66558
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 1192 : 					goto bad;

	jmp	SHORT $bad$66559
$L66557:

; 1194 : 			*pl = v[0];

	jmp	SHORT $L66555
$L66556:
	mov	eax, DWORD PTR _pl$[ebp]
	mov	ecx, DWORD PTR _v$66548[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR [ecx+4]
	mov	DWORD PTR [eax+4], ecx

; 1195 : 			status = 1;

	mov	DWORD PTR _status$[ebp], 1
$bad$66559:

; 1197 : 	bad:
; 1198 : 		if (v != buf)

	mov	edx, DWORD PTR _v$66548[ebp]
	lea	eax, DWORD PTR _buf$66547[ebp]
	cmp	edx, eax
	je	SHORT $L66560

; 1199 : 			_TIFFfree(v);

	mov	ecx, DWORD PTR _v$66548[ebp]
	push	ecx
	call	__TIFFfree
	add	esp, 4
$L66560:

; 1201 : 	return (status);

	mov	eax, DWORD PTR _status$[ebp]

; 1202 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFFetchPerSampleAnys ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+3
$SG66446 DB	'Cannot read TIFF_ANY type %d for field "%s"', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_dir$ = 12
_v$ = 16
_i$ = -4
_vp$66386 = -8
_vp$66392 = -12
_vp$66401 = -16
_vp$66407 = -20
_vp$66416 = -24
_vp$66422 = -28
_vp$66430 = -32
_vp$66438 = -36
_TIFFFetchAnyArray PROC NEAR

; 914  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H
	push	esi
	push	edi

; 915  : 	int i;
; 916  : 
; 917  : 	switch (dir->tdir_type) {

	mov	eax, DWORD PTR _dir$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+2]
	mov	DWORD PTR -40+[ebp], ecx
	mov	edx, DWORD PTR -40+[ebp]
	sub	edx, 1
	mov	DWORD PTR -40+[ebp], edx
	cmp	DWORD PTR -40+[ebp], 11			; 0000000bH
	ja	$L66445
	mov	eax, DWORD PTR -40+[ebp]
	jmp	DWORD PTR $L66764[eax*4]
$L66382:

; 918  : 	case TIFF_BYTE:
; 919  : 	case TIFF_SBYTE:
; 920  : 		if (!TIFFFetchByteArray(tif, dir, (uint16*) v))

	mov	ecx, DWORD PTR _v$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchByteArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66384

; 921  : 			return (0);

	xor	eax, eax
	jmp	$L66376
$L66384:

; 922  : 		if (dir->tdir_type == TIFF_BYTE) {

	mov	ecx, DWORD PTR _dir$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+2]
	cmp	edx, 1
	jne	SHORT $L66385

; 923  : 			uint16* vp = (uint16*) v;

	mov	eax, DWORD PTR _v$[ebp]
	mov	DWORD PTR _vp$66386[ebp], eax

; 924  : 			for (i = dir->tdir_count-1; i >= 0; i--)

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	sub	edx, 1
	mov	DWORD PTR _i$[ebp], edx
	jmp	SHORT $L66388
$L66389:
	mov	eax, DWORD PTR _i$[ebp]
	sub	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L66388:
	cmp	DWORD PTR _i$[ebp], 0
	jl	SHORT $L66390

; 925  : 				v[i] = vp[i];

	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _v$[ebp]
	mov	eax, DWORD PTR _i$[ebp]
	mov	esi, DWORD PTR _vp$66386[ebp]
	xor	edi, edi
	mov	di, WORD PTR [esi+eax*2]
	mov	DWORD PTR -44+[ebp], edi
	fild	DWORD PTR -44+[ebp]
	fstp	QWORD PTR [edx+ecx*8]
	jmp	SHORT $L66389
$L66390:

; 926  : 		} else {

	jmp	SHORT $L66396
$L66385:

; 927  : 			int16* vp = (int16*) v;

	mov	ecx, DWORD PTR _v$[ebp]
	mov	DWORD PTR _vp$66392[ebp], ecx

; 928  : 			for (i = dir->tdir_count-1; i >= 0; i--)

	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR [edx+4]
	sub	eax, 1
	mov	DWORD PTR _i$[ebp], eax
	jmp	SHORT $L66394
$L66395:
	mov	ecx, DWORD PTR _i$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L66394:
	cmp	DWORD PTR _i$[ebp], 0
	jl	SHORT $L66396

; 929  : 				v[i] = vp[i];

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _v$[ebp]
	mov	ecx, DWORD PTR _i$[ebp]
	mov	esi, DWORD PTR _vp$66392[ebp]
	movsx	ecx, WORD PTR [esi+ecx*2]
	mov	DWORD PTR -48+[ebp], ecx
	fild	DWORD PTR -48+[ebp]
	fstp	QWORD PTR [eax+edx*8]
	jmp	SHORT $L66395
$L66396:

; 931  : 		break;

	jmp	$L66379
$L66397:

; 932  : 	case TIFF_SHORT:
; 933  : 	case TIFF_SSHORT:
; 934  : 		if (!TIFFFetchShortArray(tif, dir, (uint16*) v))

	mov	edx, DWORD PTR _v$[ebp]
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFetchShortArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66399

; 935  : 			return (0);

	xor	eax, eax
	jmp	$L66376
$L66399:

; 936  : 		if (dir->tdir_type == TIFF_SHORT) {

	mov	edx, DWORD PTR _dir$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+2]
	cmp	eax, 3
	jne	SHORT $L66400

; 937  : 			uint16* vp = (uint16*) v;

	mov	ecx, DWORD PTR _v$[ebp]
	mov	DWORD PTR _vp$66401[ebp], ecx

; 938  : 			for (i = dir->tdir_count-1; i >= 0; i--)

	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR [edx+4]
	sub	eax, 1
	mov	DWORD PTR _i$[ebp], eax
	jmp	SHORT $L66403
$L66404:
	mov	ecx, DWORD PTR _i$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L66403:
	cmp	DWORD PTR _i$[ebp], 0
	jl	SHORT $L66405

; 939  : 				v[i] = vp[i];

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _v$[ebp]
	mov	ecx, DWORD PTR _i$[ebp]
	mov	esi, DWORD PTR _vp$66401[ebp]
	xor	edi, edi
	mov	di, WORD PTR [esi+ecx*2]
	mov	DWORD PTR -52+[ebp], edi
	fild	DWORD PTR -52+[ebp]
	fstp	QWORD PTR [eax+edx*8]
	jmp	SHORT $L66404
$L66405:

; 940  : 		} else {

	jmp	SHORT $L66411
$L66400:

; 941  : 			int16* vp = (int16*) v;

	mov	edx, DWORD PTR _v$[ebp]
	mov	DWORD PTR _vp$66407[ebp], edx

; 942  : 			for (i = dir->tdir_count-1; i >= 0; i--)

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	sub	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
	jmp	SHORT $L66409
$L66410:
	mov	edx, DWORD PTR _i$[ebp]
	sub	edx, 1
	mov	DWORD PTR _i$[ebp], edx
$L66409:
	cmp	DWORD PTR _i$[ebp], 0
	jl	SHORT $L66411

; 943  : 				v[i] = vp[i];

	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _v$[ebp]
	mov	edx, DWORD PTR _i$[ebp]
	mov	esi, DWORD PTR _vp$66407[ebp]
	movsx	edx, WORD PTR [esi+edx*2]
	mov	DWORD PTR -56+[ebp], edx
	fild	DWORD PTR -56+[ebp]
	fstp	QWORD PTR [ecx+eax*8]
	jmp	SHORT $L66410
$L66411:

; 945  : 		break;

	jmp	$L66379
$L66412:

; 946  : 	case TIFF_LONG:
; 947  : 	case TIFF_SLONG:
; 948  : 		if (!TIFFFetchLongArray(tif, dir, (uint32*) v))

	mov	eax, DWORD PTR _v$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFetchLongArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66414

; 949  : 			return (0);

	xor	eax, eax
	jmp	$L66376
$L66414:

; 950  : 		if (dir->tdir_type == TIFF_LONG) {

	mov	eax, DWORD PTR _dir$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+2]
	cmp	ecx, 4
	jne	SHORT $L66415

; 951  : 			uint32* vp = (uint32*) v;

	mov	edx, DWORD PTR _v$[ebp]
	mov	DWORD PTR _vp$66416[ebp], edx

; 952  : 			for (i = dir->tdir_count-1; i >= 0; i--)

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	sub	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
	jmp	SHORT $L66418
$L66419:
	mov	edx, DWORD PTR _i$[ebp]
	sub	edx, 1
	mov	DWORD PTR _i$[ebp], edx
$L66418:
	cmp	DWORD PTR _i$[ebp], 0
	jl	SHORT $L66420

; 953  : 				v[i] = vp[i];

	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _v$[ebp]
	mov	edx, DWORD PTR _i$[ebp]
	mov	esi, DWORD PTR _vp$66416[ebp]
	mov	edx, DWORD PTR [esi+edx*4]
	mov	DWORD PTR -64+[ebp], edx
	mov	DWORD PTR -64+[ebp+4], 0
	fild	QWORD PTR -64+[ebp]
	fstp	QWORD PTR [ecx+eax*8]
	jmp	SHORT $L66419
$L66420:

; 954  : 		} else {

	jmp	SHORT $L66426
$L66415:

; 955  : 			int32* vp = (int32*) v;

	mov	eax, DWORD PTR _v$[ebp]
	mov	DWORD PTR _vp$66422[ebp], eax

; 956  : 			for (i = dir->tdir_count-1; i >= 0; i--)

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	sub	edx, 1
	mov	DWORD PTR _i$[ebp], edx
	jmp	SHORT $L66424
$L66425:
	mov	eax, DWORD PTR _i$[ebp]
	sub	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L66424:
	cmp	DWORD PTR _i$[ebp], 0
	jl	SHORT $L66426

; 957  : 				v[i] = vp[i];

	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _v$[ebp]
	mov	eax, DWORD PTR _i$[ebp]
	mov	esi, DWORD PTR _vp$66422[ebp]
	fild	DWORD PTR [esi+eax*4]
	fstp	QWORD PTR [edx+ecx*8]
	jmp	SHORT $L66425
$L66426:

; 959  : 		break;

	jmp	$L66379
$L66427:

; 960  : 	case TIFF_RATIONAL:
; 961  : 	case TIFF_SRATIONAL:
; 962  : 		if (!TIFFFetchRationalArray(tif, dir, (float*) v))

	mov	ecx, DWORD PTR _v$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchRationalArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66429

; 963  : 			return (0);

	xor	eax, eax
	jmp	$L66376
$L66429:

; 964  : 		{ float* vp = (float*) v;

	mov	ecx, DWORD PTR _v$[ebp]
	mov	DWORD PTR _vp$66430[ebp], ecx

; 965  : 		  for (i = dir->tdir_count-1; i >= 0; i--)

	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR [edx+4]
	sub	eax, 1
	mov	DWORD PTR _i$[ebp], eax
	jmp	SHORT $L66432
$L66433:
	mov	ecx, DWORD PTR _i$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L66432:
	cmp	DWORD PTR _i$[ebp], 0
	jl	SHORT $L66434

; 966  : 			v[i] = vp[i];

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _v$[ebp]
	mov	ecx, DWORD PTR _i$[ebp]
	mov	esi, DWORD PTR _vp$66430[ebp]
	fld	DWORD PTR [esi+ecx*4]
	fstp	QWORD PTR [eax+edx*8]
	jmp	SHORT $L66433
$L66434:

; 968  : 		break;

	jmp	$L66379
$L66435:

; 969  : 	case TIFF_FLOAT:
; 970  : 		if (!TIFFFetchFloatArray(tif, dir, (float*) v))

	mov	edx, DWORD PTR _v$[ebp]
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFetchFloatArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66437

; 971  : 			return (0);

	xor	eax, eax
	jmp	$L66376
$L66437:

; 972  : 		{ float* vp = (float*) v;

	mov	edx, DWORD PTR _v$[ebp]
	mov	DWORD PTR _vp$66438[ebp], edx

; 973  : 		  for (i = dir->tdir_count-1; i >= 0; i--)

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	sub	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
	jmp	SHORT $L66440
$L66441:
	mov	edx, DWORD PTR _i$[ebp]
	sub	edx, 1
	mov	DWORD PTR _i$[ebp], edx
$L66440:
	cmp	DWORD PTR _i$[ebp], 0
	jl	SHORT $L66442

; 974  : 			v[i] = vp[i];

	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _v$[ebp]
	mov	edx, DWORD PTR _i$[ebp]
	mov	esi, DWORD PTR _vp$66438[ebp]
	fld	DWORD PTR [esi+edx*4]
	fstp	QWORD PTR [ecx+eax*8]
	jmp	SHORT $L66441
$L66442:

; 976  : 		break;

	jmp	SHORT $L66379
$L66443:

; 977  : 	case TIFF_DOUBLE:
; 978  : 		return (TIFFFetchDoubleArray(tif, dir, (double*) v));

	mov	eax, DWORD PTR _v$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFetchDoubleArray
	add	esp, 12					; 0000000cH
	jmp	SHORT $L66376
$L66445:

; 979  : 	default:
; 980  : 		/* TIFF_NOTYPE */
; 981  : 		/* TIFF_ASCII */
; 982  : 		/* TIFF_UNDEFINED */
; 983  : 		TIFFError(tif->tif_name,
; 984  : 		    "Cannot read TIFF_ANY type %d for field \"%s\"",
; 985  : 		    _TIFFFieldWithTag(tif, dir->tdir_tag)->field_name);

	mov	eax, DWORD PTR _dir$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	__TIFFFieldWithTag
	add	esp, 8
	mov	eax, DWORD PTR [eax+16]
	push	eax
	push	OFFSET FLAT:$SG66446
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 986  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L66376
$L66379:

; 988  : 	return (1);

	mov	eax, 1
$L66376:

; 989  : }

	pop	edi
	pop	esi
	mov	esp, ebp
	pop	ebp
	ret	0
$L66764:
	DD	$L66382
	DD	$L66445
	DD	$L66397
	DD	$L66412
	DD	$L66427
	DD	$L66382
	DD	$L66445
	DD	$L66397
	DD	$L66412
	DD	$L66427
	DD	$L66435
	DD	$L66443
_TIFFFetchAnyArray ENDP
_TEXT	ENDS
_DATA	SEGMENT
$SG66579 DB	'for strip array', 00H
$SG66585 DB	'to fetch strip tag', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_dir$ = 12
_nstrips$ = 16
_lpp$ = 20
_lp$ = -4
_status$ = -8
_dp$66582 = -12
_wp$66589 = -16
_TIFFFetchStripThing PROC NEAR

; 1212 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 1213 : 	register uint32* lp;
; 1214 : 	int status;
; 1215 : 
; 1216 : 	if (!CheckDirCount(tif, dir, (uint32) nstrips))

	mov	eax, DWORD PTR _nstrips$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_CheckDirCount
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66573

; 1217 : 		return (0);

	xor	eax, eax
	jmp	$L66569
$L66573:

; 1218 : 	/*
; 1219 : 	 * Allocate space for strip information.
; 1220 : 	 */
; 1221 : 	if (*lpp == NULL &&
; 1222 : 	    (*lpp = (uint32 *)CheckMalloc(tif,
; 1223 : 	      nstrips * sizeof (uint32), "for strip array")) == NULL)

	mov	eax, DWORD PTR _lpp$[ebp]
	cmp	DWORD PTR [eax], 0
	jne	SHORT $L66578
	push	OFFSET FLAT:$SG66579
	mov	ecx, DWORD PTR _nstrips$[ebp]
	shl	ecx, 2
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_CheckMalloc
	add	esp, 12					; 0000000cH
	mov	ecx, DWORD PTR _lpp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _lpp$[ebp]
	cmp	DWORD PTR [edx], 0
	jne	SHORT $L66578

; 1224 : 		return (0);

	xor	eax, eax
	jmp	$L66569
$L66578:

; 1225 : 	lp = *lpp;

	mov	eax, DWORD PTR _lpp$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _lp$[ebp], ecx

; 1226 : 	if (dir->tdir_type == (int)TIFF_SHORT) {

	mov	edx, DWORD PTR _dir$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+2]
	cmp	eax, 3
	jne	$L66581

; 1227 : 		/*
; 1228 : 		 * Handle uint16->uint32 expansion.
; 1229 : 		 */
; 1230 : 		uint16* dp = (uint16*) CheckMalloc(tif,
; 1231 : 		    dir->tdir_count* sizeof (uint16), "to fetch strip tag");

	push	OFFSET FLAT:$SG66585
	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	shl	edx, 1
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_CheckMalloc
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _dp$66582[ebp], eax

; 1232 : 		if (dp == NULL)

	cmp	DWORD PTR _dp$66582[ebp], 0
	jne	SHORT $L66587

; 1233 : 			return (0);

	xor	eax, eax
	jmp	SHORT $L66569
$L66587:

; 1234 : 		if( (status = TIFFFetchShortArray(tif, dir, dp)) != 0 ) {

	mov	ecx, DWORD PTR _dp$66582[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchShortArray
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _status$[ebp], eax
	cmp	DWORD PTR _status$[ebp], 0
	je	SHORT $L66592

; 1235 : 			register uint16* wp = dp;

	mov	ecx, DWORD PTR _dp$66582[ebp]
	mov	DWORD PTR _wp$66589[ebp], ecx
$L66591:

; 1236 : 			while (nstrips-- > 0)

	mov	edx, DWORD PTR _nstrips$[ebp]
	mov	eax, DWORD PTR _nstrips$[ebp]
	sub	eax, 1
	mov	DWORD PTR _nstrips$[ebp], eax
	test	edx, edx
	jle	SHORT $L66592

; 1237 : 				*lp++ = *wp++;

	mov	ecx, DWORD PTR _wp$66589[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx]
	mov	eax, DWORD PTR _lp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _lp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _lp$[ebp], ecx
	mov	edx, DWORD PTR _wp$66589[ebp]
	add	edx, 2
	mov	DWORD PTR _wp$66589[ebp], edx
	jmp	SHORT $L66591
$L66592:

; 1239 : 		_TIFFfree((char*) dp);

	mov	eax, DWORD PTR _dp$66582[ebp]
	push	eax
	call	__TIFFfree
	add	esp, 4

; 1240 : 	} else

	jmp	SHORT $L66594
$L66581:

; 1241 : 		status = TIFFFetchLongArray(tif, dir, lp);

	mov	ecx, DWORD PTR _lp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchLongArray
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _status$[ebp], eax
$L66594:

; 1242 : 	return (status);

	mov	eax, DWORD PTR _status$[ebp]
$L66569:

; 1243 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFFetchStripThing ENDP
_tif$ = 8
_dir$ = 12
_buf$ = -20
_v$ = -24
_status$ = -28
_TIFFFetchExtraSamples PROC NEAR

; 1251 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 28					; 0000001cH

; 1252 : 	uint16 buf[10];
; 1253 : 	uint16* v = buf;

	lea	eax, DWORD PTR _buf$[ebp]
	mov	DWORD PTR _v$[ebp], eax

; 1254 : 	int status;
; 1255 : 
; 1256 : 	if (dir->tdir_count > NITEMS(buf))

	mov	ecx, DWORD PTR _dir$[ebp]
	cmp	DWORD PTR [ecx+4], 10			; 0000000aH
	jbe	SHORT $L66604

; 1257 : 		v = (uint16*) _TIFFmalloc(dir->tdir_count * sizeof (uint16));

	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR [edx+4]
	shl	eax, 1
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	DWORD PTR _v$[ebp], eax
$L66604:

; 1258 : 	if (dir->tdir_type == TIFF_BYTE)

	mov	ecx, DWORD PTR _dir$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+2]
	cmp	edx, 1
	jne	SHORT $L66607

; 1259 : 		status = TIFFFetchByteArray(tif, dir, v);

	mov	eax, DWORD PTR _v$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFetchByteArray
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _status$[ebp], eax

; 1260 : 	else

	jmp	SHORT $L66608
$L66607:

; 1261 : 		status = TIFFFetchShortArray(tif, dir, v);

	mov	eax, DWORD PTR _v$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFetchShortArray
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _status$[ebp], eax
$L66608:

; 1262 : 	if (status)

	cmp	DWORD PTR _status$[ebp], 0
	je	SHORT $L66609

; 1263 : 		status = TIFFSetField(tif, dir->tdir_tag, dir->tdir_count, v);

	mov	eax, DWORD PTR _v$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFSetField
	add	esp, 16					; 00000010H
	mov	DWORD PTR _status$[ebp], eax
$L66609:

; 1264 : 	if (v != buf)

	mov	eax, DWORD PTR _v$[ebp]
	lea	ecx, DWORD PTR _buf$[ebp]
	cmp	eax, ecx
	je	SHORT $L66610

; 1265 : 		_TIFFfree((char*) v);

	mov	edx, DWORD PTR _v$[ebp]
	push	edx
	call	__TIFFfree
	add	esp, 4
$L66610:

; 1266 : 	return (status);

	mov	eax, DWORD PTR _status$[ebp]

; 1267 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFFetchExtraSamples ENDP
_tif$ = 8
_dir$ = 12
_cp$ = -4
_ok$ = -8
_fp$66625 = -12
_i$66630 = -16
_TIFFFetchRefBlackWhite PROC NEAR

; 1276 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 28					; 0000001cH

; 1277 : 	static const char mesg[] = "for \"ReferenceBlackWhite\" array";
; 1278 : 	char* cp;
; 1279 : 	int ok;
; 1280 : 
; 1281 : 	if (dir->tdir_type == TIFF_RATIONAL)

	mov	eax, DWORD PTR _dir$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+2]
	cmp	ecx, 5
	jne	SHORT $L66621

; 1282 : 		return (TIFFFetchNormalTag(tif, dir));

	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchNormalTag
	add	esp, 8
	jmp	$L66616
$L66621:

; 1283 : 	/*
; 1284 : 	 * Handle LONG's for backward compatibility.
; 1285 : 	 */
; 1286 : 	cp = CheckMalloc(tif, dir->tdir_count * sizeof (uint32), mesg);

	push	OFFSET FLAT:_?mesg@?1??TIFFFetchRefBlackWhite@@9@9
	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	shl	edx, 2
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_CheckMalloc
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _cp$[ebp], eax

; 1287 : 	if( (ok = (cp && TIFFFetchLongArray(tif, dir, (uint32*) cp))) != 0) {

	cmp	DWORD PTR _cp$[ebp], 0
	je	SHORT $L66768
	mov	ecx, DWORD PTR _cp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFetchLongArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L66768
	mov	DWORD PTR -20+[ebp], 1
	jmp	SHORT $L66769
$L66768:
	mov	DWORD PTR -20+[ebp], 0
$L66769:
	mov	ecx, DWORD PTR -20+[ebp]
	mov	DWORD PTR _ok$[ebp], ecx
	cmp	DWORD PTR _ok$[ebp], 0
	je	$L66629

; 1288 : 		float* fp = (float*)
; 1289 : 		    CheckMalloc(tif, dir->tdir_count * sizeof (float), mesg);

	push	OFFSET FLAT:_?mesg@?1??TIFFFetchRefBlackWhite@@9@9
	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR [edx+4]
	shl	eax, 2
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_CheckMalloc
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _fp$66625[ebp], eax

; 1290 : 		if( (ok = (fp != NULL)) != 0 ) {

	xor	edx, edx
	cmp	DWORD PTR _fp$66625[ebp], 0
	setne	dl
	mov	DWORD PTR _ok$[ebp], edx
	cmp	DWORD PTR _ok$[ebp], 0
	je	SHORT $L66629

; 1291 : 			uint32 i;
; 1292 : 			for (i = 0; i < dir->tdir_count; i++)

	mov	DWORD PTR _i$66630[ebp], 0
	jmp	SHORT $L66631
$L66632:
	mov	eax, DWORD PTR _i$66630[ebp]
	add	eax, 1
	mov	DWORD PTR _i$66630[ebp], eax
$L66631:
	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR _i$66630[ebp]
	cmp	edx, DWORD PTR [ecx+4]
	jae	SHORT $L66633

; 1293 : 				fp[i] = (float)((uint32*) cp)[i];

	mov	eax, DWORD PTR _i$66630[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR [ecx+eax*4]
	mov	DWORD PTR -28+[ebp], edx
	mov	DWORD PTR -28+[ebp+4], 0
	fild	QWORD PTR -28+[ebp]
	mov	eax, DWORD PTR _i$66630[ebp]
	mov	ecx, DWORD PTR _fp$66625[ebp]
	fstp	DWORD PTR [ecx+eax*4]
	jmp	SHORT $L66632
$L66633:

; 1294 : 			ok = TIFFSetField(tif, dir->tdir_tag, fp);

	mov	edx, DWORD PTR _fp$66625[ebp]
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFSetField
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _ok$[ebp], eax

; 1295 : 			_TIFFfree((char*) fp);

	mov	eax, DWORD PTR _fp$66625[ebp]
	push	eax
	call	__TIFFfree
	add	esp, 4
$L66629:

; 1298 : 	if (cp)

	cmp	DWORD PTR _cp$[ebp], 0
	je	SHORT $L66637

; 1299 : 		_TIFFfree(cp);

	mov	ecx, DWORD PTR _cp$[ebp]
	push	ecx
	call	__TIFFfree
	add	esp, 4
$L66637:

; 1300 : 	return (ok);

	mov	eax, DWORD PTR _ok$[ebp]
$L66616:

; 1301 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFFetchRefBlackWhite ENDP
_TEXT	ENDS
EXTRN	_TIFFVTileSize:NEAR
_DATA	SEGMENT
	ORG $+1
$SG66660 DB	'for chopped "StripByteCounts" array', 00H
$SG66663 DB	'for chopped "StripOffsets" array', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_td$ = -32
_bytecount$ = -12
_offset$ = -8
_rowbytes$ = -20
_stripbytes$ = -16
_strip$ = -40
_nstrips$ = -28
_rowsperstrip$ = -36
_newcounts$ = -24
_newoffsets$ = -4
_ChopUpSingleUncompressedStrip PROC NEAR

; 1313 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 40					; 00000028H

; 1314 : 	register TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 1315 : 	uint32 bytecount = td->td_stripbytecount[0];

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+188]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR _bytecount$[ebp], eax

; 1316 : 	uint32 offset = td->td_stripoffset[0];

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR _offset$[ebp], eax

; 1317 : 	tsize_t rowbytes = TIFFVTileSize(tif, 1), stripbytes;

	push	1
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFVTileSize
	add	esp, 8
	mov	DWORD PTR _rowbytes$[ebp], eax

; 1318 : 	tstrip_t strip, nstrips, rowsperstrip;
; 1319 : 	uint32* newcounts;
; 1320 : 	uint32* newoffsets;
; 1321 : 
; 1322 : 	/*
; 1323 : 	 * Make the rows hold at least one
; 1324 : 	 * scanline, but fill 8k if possible.
; 1325 : 	 */
; 1326 : 	if (rowbytes > 8192) {

	cmp	DWORD PTR _rowbytes$[ebp], 8192		; 00002000H
	jle	SHORT $L66651

; 1327 : 		stripbytes = rowbytes;

	mov	edx, DWORD PTR _rowbytes$[ebp]
	mov	DWORD PTR _stripbytes$[ebp], edx

; 1328 : 		rowsperstrip = 1;

	mov	DWORD PTR _rowsperstrip$[ebp], 1

; 1329 : 	} else {

	jmp	SHORT $L66652
$L66651:

; 1330 : 		rowsperstrip = 8192 / rowbytes;

	mov	eax, 8192				; 00002000H
	cdq
	idiv	DWORD PTR _rowbytes$[ebp]
	mov	DWORD PTR _rowsperstrip$[ebp], eax

; 1331 : 		stripbytes = rowbytes * rowsperstrip;

	mov	eax, DWORD PTR _rowbytes$[ebp]
	imul	eax, DWORD PTR _rowsperstrip$[ebp]
	mov	DWORD PTR _stripbytes$[ebp], eax
$L66652:

; 1333 : 	/* never increase the number of strips in an image */
; 1334 : 	if (rowsperstrip >= td->td_rowsperstrip)

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _rowsperstrip$[ebp]
	cmp	edx, DWORD PTR [ecx+56]
	jb	SHORT $L66653

; 1335 : 		return;

	jmp	$L66640
$L66653:

; 1336 : 	nstrips = (tstrip_t) TIFFhowmany(bytecount, stripbytes);

	mov	eax, DWORD PTR _stripbytes$[ebp]
	mov	ecx, DWORD PTR _bytecount$[ebp]
	lea	eax, DWORD PTR [ecx+eax-1]
	xor	edx, edx
	div	DWORD PTR _stripbytes$[ebp]
	mov	DWORD PTR _nstrips$[ebp], eax

; 1337 : 	newcounts = (uint32*) CheckMalloc(tif, nstrips * sizeof (uint32),
; 1338 : 				"for chopped \"StripByteCounts\" array");

	push	OFFSET FLAT:$SG66660
	mov	edx, DWORD PTR _nstrips$[ebp]
	shl	edx, 2
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_CheckMalloc
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _newcounts$[ebp], eax

; 1339 : 	newoffsets = (uint32*) CheckMalloc(tif, nstrips * sizeof (uint32),
; 1340 : 				"for chopped \"StripOffsets\" array");

	push	OFFSET FLAT:$SG66663
	mov	ecx, DWORD PTR _nstrips$[ebp]
	shl	ecx, 2
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_CheckMalloc
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _newoffsets$[ebp], eax

; 1341 : 	if (newcounts == NULL || newoffsets == NULL) {

	cmp	DWORD PTR _newcounts$[ebp], 0
	je	SHORT $L66667
	cmp	DWORD PTR _newoffsets$[ebp], 0
	jne	SHORT $L66666
$L66667:

; 1342 : 	        /*
; 1343 : 		 * Unable to allocate new strip information, give
; 1344 : 		 * up and use the original one strip information.
; 1345 : 		 */
; 1346 : 		if (newcounts != NULL)

	cmp	DWORD PTR _newcounts$[ebp], 0
	je	SHORT $L66669

; 1347 : 			_TIFFfree(newcounts);

	mov	eax, DWORD PTR _newcounts$[ebp]
	push	eax
	call	__TIFFfree
	add	esp, 4
$L66669:

; 1348 : 		if (newoffsets != NULL)

	cmp	DWORD PTR _newoffsets$[ebp], 0
	je	SHORT $L66671

; 1349 : 			_TIFFfree(newoffsets);

	mov	ecx, DWORD PTR _newoffsets$[ebp]
	push	ecx
	call	__TIFFfree
	add	esp, 4
$L66671:

; 1350 : 		return;

	jmp	$L66640
$L66666:

; 1352 : 	/*
; 1353 : 	 * Fill the strip information arrays with
; 1354 : 	 * new bytecounts and offsets that reflect
; 1355 : 	 * the broken-up format.
; 1356 : 	 */
; 1357 : 	for (strip = 0; strip < nstrips; strip++) {

	mov	DWORD PTR _strip$[ebp], 0
	jmp	SHORT $L66672
$L66673:
	mov	edx, DWORD PTR _strip$[ebp]
	add	edx, 1
	mov	DWORD PTR _strip$[ebp], edx
$L66672:
	mov	eax, DWORD PTR _strip$[ebp]
	cmp	eax, DWORD PTR _nstrips$[ebp]
	jae	SHORT $L66674

; 1358 : 		if (stripbytes > (tsize_t) bytecount)

	mov	ecx, DWORD PTR _stripbytes$[ebp]
	cmp	ecx, DWORD PTR _bytecount$[ebp]
	jle	SHORT $L66676

; 1359 : 			stripbytes = bytecount;

	mov	edx, DWORD PTR _bytecount$[ebp]
	mov	DWORD PTR _stripbytes$[ebp], edx
$L66676:

; 1360 : 		newcounts[strip] = stripbytes;

	mov	eax, DWORD PTR _strip$[ebp]
	mov	ecx, DWORD PTR _newcounts$[ebp]
	mov	edx, DWORD PTR _stripbytes$[ebp]
	mov	DWORD PTR [ecx+eax*4], edx

; 1361 : 		newoffsets[strip] = offset;

	mov	eax, DWORD PTR _strip$[ebp]
	mov	ecx, DWORD PTR _newoffsets$[ebp]
	mov	edx, DWORD PTR _offset$[ebp]
	mov	DWORD PTR [ecx+eax*4], edx

; 1362 : 		offset += stripbytes;

	mov	eax, DWORD PTR _offset$[ebp]
	add	eax, DWORD PTR _stripbytes$[ebp]
	mov	DWORD PTR _offset$[ebp], eax

; 1363 : 		bytecount -= stripbytes;

	mov	ecx, DWORD PTR _bytecount$[ebp]
	sub	ecx, DWORD PTR _stripbytes$[ebp]
	mov	DWORD PTR _bytecount$[ebp], ecx

; 1364 : 	}

	jmp	SHORT $L66673
$L66674:

; 1365 : 	/*
; 1366 : 	 * Replace old single strip info with multi-strip info.
; 1367 : 	 */
; 1368 : 	td->td_stripsperimage = td->td_nstrips = nstrips;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _nstrips$[ebp]
	mov	DWORD PTR [edx+180], eax
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _nstrips$[ebp]
	mov	DWORD PTR [ecx+176], edx

; 1369 : 	TIFFSetField(tif, TIFFTAG_ROWSPERSTRIP, rowsperstrip);

	mov	eax, DWORD PTR _rowsperstrip$[ebp]
	push	eax
	push	278					; 00000116H
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFSetField
	add	esp, 12					; 0000000cH

; 1370 : 
; 1371 : 	_TIFFfree(td->td_stripbytecount);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+188]
	push	eax
	call	__TIFFfree
	add	esp, 4

; 1372 : 	_TIFFfree(td->td_stripoffset);

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	push	edx
	call	__TIFFfree
	add	esp, 4

; 1373 : 	td->td_stripbytecount = newcounts;

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _newcounts$[ebp]
	mov	DWORD PTR [eax+188], ecx

; 1374 : 	td->td_stripoffset = newoffsets;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _newoffsets$[ebp]
	mov	DWORD PTR [edx+184], eax
$L66640:

; 1375 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_ChopUpSingleUncompressedStrip ENDP
_TEXT	ENDS
END
