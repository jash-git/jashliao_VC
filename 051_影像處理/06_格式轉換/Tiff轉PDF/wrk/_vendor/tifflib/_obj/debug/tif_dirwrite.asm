	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_dirwrite.c
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
_?module@?1??TIFFRewriteDirectory@@9@9 DB 'TIFFRewriteDirectory', 00H
	ORG $+3
_?module@?1??TIFFLinkDirectory@@9@9 DB 'TIFFLinkDirectory', 00H
CONST	ENDS
PUBLIC	_TIFFWriteDirectory
EXTRN	_TIFFFlushData1:NEAR
EXTRN	_TIFFFreeDirectory:NEAR
EXTRN	__TIFFmalloc:NEAR
EXTRN	__TIFFmemcpy:NEAR
EXTRN	__TIFFfree:NEAR
EXTRN	_TIFFCreateDirectory:NEAR
EXTRN	_TIFFError:NEAR
EXTRN	_TIFFSwabShort:NEAR
EXTRN	_TIFFSwabLong:NEAR
EXTRN	_TIFFSwabArrayOfShort:NEAR
EXTRN	_TIFFSwabArrayOfLong:NEAR
EXTRN	__TIFFSampleToTagType:NEAR
_DATA	SEGMENT
$SG65891 DB	'Error post-encoding before directory write', 00H
	ORG $+1
$SG65893 DB	'Error flushing data before directory write', 00H
	ORG $+1
$SG65905 DB	'Cannot write directory, out of space', 00H
	ORG $+3
$SG65984 DB	'Error writing directory count', 00H
	ORG $+2
$SG65989 DB	'Error writing directory contents', 00H
	ORG $+3
$SG65994 DB	'Error writing directory link', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_dircount$ = -32
_diroff$ = -36
_tag$ = -40
_nfields$ = -56
_dirsize$ = -12
_data$ = -8
_dir$ = -52
_td$ = -48
_b$ = -4
_fields$ = -24
_fi$ = -28
_nfi$ = -44
_fip$65922 = -60
_TIFFWriteDirectory PROC NEAR

; 92   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H

; 93   : 	uint16 dircount;
; 94   : 	toff_t diroff;
; 95   : 	ttag_t tag;
; 96   : 	uint32 nfields;
; 97   : 	tsize_t dirsize;
; 98   : 	char* data;
; 99   : 	TIFFDirEntry* dir;
; 100  : 	TIFFDirectory* td;
; 101  : 	u_long b, fields[FIELD_SETLONGS];
; 102  : 	int fi, nfi;
; 103  : 
; 104  : 	if (tif->tif_mode == O_RDONLY)

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+8], 0
	jne	SHORT $L65888

; 105  : 		return (1);

	mov	eax, 1
	jmp	$L65875
$L65888:

; 106  : 	/*
; 107  : 	 * Clear write state so that subsequent images with
; 108  : 	 * different characteristics get the right buffers
; 109  : 	 * setup for them.
; 110  : 	 */
; 111  : 	if (tif->tif_flags & TIFF_POSTENCODE) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 4096				; 00001000H
	test	edx, edx
	je	SHORT $L65890

; 112  : 		tif->tif_flags &= ~TIFF_POSTENCODE;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ch, -17					; ffffffefH
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx

; 113  : 		if (!(*tif->tif_postencode)(tif)) {

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+412]
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65890

; 114  : 			TIFFError(tif->tif_name,
; 115  : 			    "Error post-encoding before directory write");

	push	OFFSET FLAT:$SG65891
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 8

; 116  : 			return (0);

	xor	eax, eax
	jmp	$L65875
$L65890:

; 119  : 	(*tif->tif_close)(tif);			/* shutdown encoder */

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+440]
	add	esp, 4

; 120  : 	/*
; 121  : 	 * Flush any data that might have been written
; 122  : 	 * by the compression close+cleanup routines.
; 123  : 	 */
; 124  : 	if (tif->tif_rawcc > 0 && !TIFFFlushData1(tif)) {

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+484], 0
	jle	SHORT $L65892
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFlushData1
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65892

; 125  : 		TIFFError(tif->tif_name,
; 126  : 		    "Error flushing data before directory write");

	push	OFFSET FLAT:$SG65893
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 8

; 127  : 		return (0);

	xor	eax, eax
	jmp	$L65875
$L65892:

; 129  : 	if ((tif->tif_flags & TIFF_MYBUFFER) && tif->tif_rawdata) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 512				; 00000200H
	test	edx, edx
	je	SHORT $L65894
	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+472], 0
	je	SHORT $L65894

; 130  : 		_TIFFfree(tif->tif_rawdata);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+472]
	push	edx
	call	__TIFFfree
	add	esp, 4

; 131  : 		tif->tif_rawdata = NULL;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+472], 0

; 132  : 		tif->tif_rawcc = 0;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+484], 0

; 133  :                 tif->tif_rawdatasize = 0;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+476], 0
$L65894:

; 135  : 	tif->tif_flags &= ~(TIFF_BEENWRITING|TIFF_BUFFERSETUP);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, -81				; ffffffafH
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx

; 136  : 
; 137  : 	td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 138  : 	/*
; 139  : 	 * Size the directory so that we can calculate
; 140  : 	 * offsets for the data items that aren't kept
; 141  : 	 * in-place in each field.
; 142  : 	 */
; 143  : 	nfields = 0;

	mov	DWORD PTR _nfields$[ebp], 0

; 144  : 	for (b = 0; b <= FIELD_LAST; b++)

	mov	DWORD PTR _b$[ebp], 0
	jmp	SHORT $L65896
$L65897:
	mov	ecx, DWORD PTR _b$[ebp]
	add	ecx, 1
	mov	DWORD PTR _b$[ebp], ecx
$L65896:
	cmp	DWORD PTR _b$[ebp], 95			; 0000005fH
	ja	SHORT $L65898

; 145  : 		if (TIFFFieldSet(tif, b))

	mov	edx, DWORD PTR _b$[ebp]
	shr	edx, 5
	mov	ecx, DWORD PTR _b$[ebp]
	and	ecx, 31					; 0000001fH
	mov	eax, 1
	shl	eax, cl
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+edx*4+24]
	and	edx, eax
	test	edx, edx
	je	SHORT $L65900

; 146  : 			nfields += (b < FIELD_SUBFILETYPE ? 2 : 1);

	cmp	DWORD PTR _b$[ebp], 5
	sbb	eax, eax
	neg	eax
	add	eax, 1
	mov	ecx, DWORD PTR _nfields$[ebp]
	add	ecx, eax
	mov	DWORD PTR _nfields$[ebp], ecx
$L65900:

; 147  : 	dirsize = nfields * sizeof (TIFFDirEntry);

	jmp	SHORT $L65897
$L65898:
	mov	edx, DWORD PTR _nfields$[ebp]
	imul	edx, 12					; 0000000cH
	mov	DWORD PTR _dirsize$[ebp], edx

; 148  : 	data = (char*) _TIFFmalloc(dirsize);

	mov	eax, DWORD PTR _dirsize$[ebp]
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	DWORD PTR _data$[ebp], eax

; 149  : 	if (data == NULL) {

	cmp	DWORD PTR _data$[ebp], 0
	jne	SHORT $L65904

; 150  : 		TIFFError(tif->tif_name,
; 151  : 		    "Cannot write directory, out of space");

	push	OFFSET FLAT:$SG65905
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 8

; 152  : 		return (0);

	xor	eax, eax
	jmp	$L65875
$L65904:

; 154  : 	/*
; 155  : 	 * Directory hasn't been placed yet, put
; 156  : 	 * it at the end of the file and link it
; 157  : 	 * into the existing directory structure.
; 158  : 	 */
; 159  : 	if (tif->tif_diroff == 0 && !TIFFLinkDirectory(tif))

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+16], 0
	jne	SHORT $L65906
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFLinkDirectory
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65906

; 160  : 		goto bad;

	jmp	$bad$65907
$L65906:

; 161  : 	tif->tif_dataoff = (toff_t)(
; 162  : 	    tif->tif_diroff + sizeof (uint16) + dirsize + sizeof (toff_t));

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+16]
	mov	ecx, DWORD PTR _dirsize$[ebp]
	lea	edx, DWORD PTR [eax+ecx+6]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+372], edx

; 163  : 	if (tif->tif_dataoff & 1)

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+372]
	and	edx, 1
	test	edx, edx
	je	SHORT $L65911

; 164  : 		tif->tif_dataoff++;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+372]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+372], ecx
$L65911:

; 165  : 	(void) TIFFSeekFile(tif, tif->tif_dataoff, SEEK_SET);

	push	0
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+372]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+504]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+516]
	add	esp, 12					; 0000000cH

; 166  : 	tif->tif_curdir++;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	ax, WORD PTR [edx+360]
	add	ax, 1
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	WORD PTR [ecx+360], ax

; 167  : 	dir = (TIFFDirEntry*) data;

	mov	edx, DWORD PTR _data$[ebp]
	mov	DWORD PTR _dir$[ebp], edx

; 168  : 	/*
; 169  : 	 * Setup external form of directory
; 170  : 	 * entries and write data items.
; 171  : 	 */
; 172  : 	_TIFFmemcpy(fields, td->td_fieldsset, sizeof (fields));

	push	12					; 0000000cH
	mov	eax, DWORD PTR _td$[ebp]
	push	eax
	lea	ecx, DWORD PTR _fields$[ebp]
	push	ecx
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH

; 173  : 	/*
; 174  : 	 * Write out ExtraSamples tag only if
; 175  : 	 * extra samples are present in the data.
; 176  : 	 */
; 177  : 	if (FieldSet(fields, FIELD_EXTRASAMPLES) && !td->td_extrasamples) {

	mov	edx, DWORD PTR _fields$[ebp]
	and	edx, -2147483648			; 80000000H
	test	edx, edx
	je	SHORT $L65916
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+120]
	test	ecx, ecx
	jne	SHORT $L65916

; 178  : 		ResetFieldBit(fields, FIELD_EXTRASAMPLES);

	mov	edx, DWORD PTR _fields$[ebp]
	and	edx, 2147483647				; 7fffffffH
	mov	DWORD PTR _fields$[ebp], edx

; 179  : 		nfields--;

	mov	eax, DWORD PTR _nfields$[ebp]
	sub	eax, 1
	mov	DWORD PTR _nfields$[ebp], eax

; 180  : 		dirsize -= sizeof (TIFFDirEntry);

	mov	ecx, DWORD PTR _dirsize$[ebp]
	sub	ecx, 12					; 0000000cH
	mov	DWORD PTR _dirsize$[ebp], ecx
$L65916:

; 182  : 	for (fi = 0, nfi = tif->tif_nfields; nfi > 0; nfi--, fi++) {

	mov	DWORD PTR _fi$[ebp], 0
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+536]
	mov	DWORD PTR _nfi$[ebp], eax
	jmp	SHORT $L65919
$L65920:
	mov	ecx, DWORD PTR _nfi$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _nfi$[ebp], ecx
	mov	edx, DWORD PTR _fi$[ebp]
	add	edx, 1
	mov	DWORD PTR _fi$[ebp], edx
$L65919:
	cmp	DWORD PTR _nfi$[ebp], 0
	jle	$L65921

; 183  : 		const TIFFFieldInfo* fip = tif->tif_fieldinfo[fi];

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+532]
	mov	edx, DWORD PTR _fi$[ebp]
	mov	eax, DWORD PTR [ecx+edx*4]
	mov	DWORD PTR _fip$65922[ebp], eax

; 184  : 		if (!FieldSet(fields, fip->field_bit))

	mov	ecx, DWORD PTR _fip$65922[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [ecx+12]
	cdq
	and	edx, 31					; 0000001fH
	add	eax, edx
	sar	eax, 5
	mov	edx, DWORD PTR _fip$65922[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+12]
	and	ecx, 31					; 0000001fH
	mov	edx, 1
	shl	edx, cl
	mov	eax, DWORD PTR _fields$[ebp+eax*4]
	and	eax, edx
	test	eax, eax
	jne	SHORT $L65924

; 185  : 			continue;

	jmp	SHORT $L65920
$L65924:

; 186  : 		switch (fip->field_bit) {

	mov	ecx, DWORD PTR _fip$65922[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+12]
	mov	DWORD PTR -64+[ebp], edx
	mov	eax, DWORD PTR -64+[ebp]
	sub	eax, 1
	mov	DWORD PTR -64+[ebp], eax
	cmp	DWORD PTR -64+[ebp], 48			; 00000030H
	ja	$L65967
	mov	edx, DWORD PTR -64+[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR $L66577[edx]
	jmp	DWORD PTR $L66578[ecx*4]
$L65929:

; 187  : 		case FIELD_STRIPOFFSETS:
; 188  : 			/*
; 189  : 			 * We use one field bit for both strip and tile
; 190  : 			 * offsets, and so must be careful in selecting
; 191  : 			 * the appropriate field descriptor (so that tags
; 192  : 			 * are written in sorted order).
; 193  : 			 */
; 194  : 			tag = isTiled(tif) ?
; 195  : 			    TIFFTAG_TILEOFFSETS : TIFFTAG_STRIPOFFSETS;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 1024				; 00000400H
	neg	ecx
	sbb	ecx, ecx
	and	ecx, 51					; 00000033H
	add	ecx, 273				; 00000111H
	mov	DWORD PTR _tag$[ebp], ecx

; 196  : 			if (tag != fip->field_tag)

	mov	edx, DWORD PTR _fip$65922[ebp]
	mov	eax, DWORD PTR _tag$[ebp]
	cmp	eax, DWORD PTR [edx]
	je	SHORT $L65930

; 197  : 				continue;

	jmp	$L65920
$L65930:

; 198  : 			if (!TIFFWriteLongArray(tif, TIFF_LONG, tag, dir,
; 199  : 			    (uint32) td->td_nstrips, td->td_stripoffset))

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+180]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	push	4
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFWriteLongArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L65932

; 200  : 				goto bad;

	jmp	$bad$65907
$L65932:

; 201  : 			break;

	jmp	$L65926
$L65933:

; 202  : 		case FIELD_STRIPBYTECOUNTS:
; 203  : 			/*
; 204  : 			 * We use one field bit for both strip and tile
; 205  : 			 * byte counts, and so must be careful in selecting
; 206  : 			 * the appropriate field descriptor (so that tags
; 207  : 			 * are written in sorted order).
; 208  : 			 */
; 209  : 			tag = isTiled(tif) ?
; 210  : 			    TIFFTAG_TILEBYTECOUNTS : TIFFTAG_STRIPBYTECOUNTS;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 1024				; 00000400H
	neg	eax
	sbb	eax, eax
	and	eax, 46					; 0000002eH
	add	eax, 279				; 00000117H
	mov	DWORD PTR _tag$[ebp], eax

; 211  : 			if (tag != fip->field_tag)

	mov	ecx, DWORD PTR _fip$65922[ebp]
	mov	edx, DWORD PTR _tag$[ebp]
	cmp	edx, DWORD PTR [ecx]
	je	SHORT $L65934

; 212  : 				continue;

	jmp	$L65920
$L65934:

; 213  : 			if (!TIFFWriteLongArray(tif, TIFF_LONG, tag, dir,
; 214  : 			    (uint32) td->td_nstrips, td->td_stripbytecount))

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+188]
	push	ecx
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+180]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tag$[ebp]
	push	edx
	push	4
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFWriteLongArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L65936

; 215  : 				goto bad;

	jmp	$bad$65907
$L65936:

; 216  : 			break;

	jmp	$L65926
$L65937:

; 217  : 		case FIELD_ROWSPERSTRIP:
; 218  : 			TIFFSetupShortLong(tif, TIFFTAG_ROWSPERSTRIP,
; 219  : 			    dir, td->td_rowsperstrip);

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	push	278					; 00000116H
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFSetupShortLong
	add	esp, 16					; 00000010H

; 220  : 			break;

	jmp	$L65926
$L65938:

; 221  : 		case FIELD_COLORMAP:
; 222  : 			if (!TIFFWriteShortTable(tif, TIFFTAG_COLORMAP, dir,
; 223  : 			    3, td->td_colormap))

	mov	edx, DWORD PTR _td$[ebp]
	add	edx, 104				; 00000068H
	push	edx
	push	3
	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	push	320					; 00000140H
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFWriteShortTable
	add	esp, 20					; 00000014H
	test	eax, eax
	jne	SHORT $L65939

; 224  : 				goto bad;

	jmp	$bad$65907
$L65939:

; 225  : 			break;

	jmp	$L65926
$L65940:

; 226  : 		case FIELD_IMAGEDIMENSIONS:
; 227  : 			TIFFSetupShortLong(tif, TIFFTAG_IMAGEWIDTH,
; 228  : 			    dir++, td->td_imagewidth);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+12]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	mov	DWORD PTR -68+[ebp], ecx
	mov	edx, DWORD PTR -68+[ebp]
	push	edx
	push	256					; 00000100H
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	add	ecx, 12					; 0000000cH
	mov	DWORD PTR _dir$[ebp], ecx
	call	_TIFFSetupShortLong
	add	esp, 16					; 00000010H

; 229  : 			TIFFSetupShortLong(tif, TIFFTAG_IMAGELENGTH,
; 230  : 			    dir, td->td_imagelength);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	push	257					; 00000101H
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFSetupShortLong
	add	esp, 16					; 00000010H

; 231  : 			break;

	jmp	$L65926
$L65941:

; 232  : 		case FIELD_TILEDIMENSIONS:
; 233  : 			TIFFSetupShortLong(tif, TIFFTAG_TILEWIDTH,
; 234  : 			    dir++, td->td_tilewidth);

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	mov	DWORD PTR -72+[ebp], edx
	mov	eax, DWORD PTR -72+[ebp]
	push	eax
	push	322					; 00000142H
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	add	edx, 12					; 0000000cH
	mov	DWORD PTR _dir$[ebp], edx
	call	_TIFFSetupShortLong
	add	esp, 16					; 00000010H

; 235  : 			TIFFSetupShortLong(tif, TIFFTAG_TILELENGTH,
; 236  : 			    dir, td->td_tilelength);

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	push	323					; 00000143H
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFSetupShortLong
	add	esp, 16					; 00000010H

; 237  : 			break;

	jmp	$L65926
$L65942:

; 240  : 			    TIFFTAG_XPOSITION, td->td_xposition,
; 241  : 			    TIFFTAG_YPOSITION, td->td_yposition);

	mov	ecx, DWORD PTR _td$[ebp]
	add	ecx, 92					; 0000005cH
	push	ecx
	push	1
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	push	286					; 0000011eH
	push	5
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFWriteRationalArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L65943
	jmp	$bad$65907
$L65943:
	mov	ecx, DWORD PTR _td$[ebp]
	add	ecx, 96					; 00000060H
	push	ecx
	push	1
	mov	edx, DWORD PTR _dir$[ebp]
	add	edx, 12					; 0000000cH
	push	edx
	push	287					; 0000011fH
	push	5
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFWriteRationalArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L65944
	jmp	$bad$65907
$L65944:
	mov	ecx, DWORD PTR _dir$[ebp]
	add	ecx, 12					; 0000000cH
	mov	DWORD PTR _dir$[ebp], ecx

; 242  : 			break;

	jmp	$L65926
$L65945:

; 245  : 			    TIFFTAG_XRESOLUTION, td->td_xresolution,
; 246  : 			    TIFFTAG_YRESOLUTION, td->td_yresolution);

	mov	edx, DWORD PTR _td$[ebp]
	add	edx, 80					; 00000050H
	push	edx
	push	1
	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	push	282					; 0000011aH
	push	5
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFWriteRationalArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L65946
	jmp	$bad$65907
$L65946:
	mov	edx, DWORD PTR _td$[ebp]
	add	edx, 84					; 00000054H
	push	edx
	push	1
	mov	eax, DWORD PTR _dir$[ebp]
	add	eax, 12					; 0000000cH
	push	eax
	push	283					; 0000011bH
	push	5
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFWriteRationalArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L65947
	jmp	$bad$65907
$L65947:
	mov	edx, DWORD PTR _dir$[ebp]
	add	edx, 12					; 0000000cH
	mov	DWORD PTR _dir$[ebp], edx

; 247  : 			break;

	jmp	$L65926
$L65948:

; 248  : 		case FIELD_BITSPERSAMPLE:
; 249  : 		case FIELD_MINSAMPLEVALUE:
; 250  : 		case FIELD_MAXSAMPLEVALUE:
; 251  : 		case FIELD_SAMPLEFORMAT:
; 252  : 			if (!TIFFWritePerSampleShorts(tif, fip->field_tag, dir))

	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	mov	ecx, DWORD PTR _fip$65922[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFWritePerSampleShorts
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65949

; 253  : 				goto bad;

	jmp	$bad$65907
$L65949:

; 254  : 			break;

	jmp	$L65926
$L65950:

; 255  : 		case FIELD_SMINSAMPLEVALUE:
; 256  : 		case FIELD_SMAXSAMPLEVALUE:
; 257  : 			if (!TIFFWritePerSampleAnys(tif,
; 258  : 			    _TIFFSampleToTagType(tif), fip->field_tag, dir))

	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _fip$65922[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	__TIFFSampleToTagType
	add	esp, 4
	push	eax
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWritePerSampleAnys
	add	esp, 16					; 00000010H
	test	eax, eax
	jne	SHORT $L65951

; 259  : 				goto bad;

	jmp	$bad$65907
$L65951:

; 260  : 			break;

	jmp	$L65926
$L65952:

; 261  : 		case FIELD_PAGENUMBER:
; 262  : 		case FIELD_HALFTONEHINTS:
; 263  : #ifdef YCBCR_SUPPORT
; 264  : 		case FIELD_YCBCRSUBSAMPLING:
; 265  : #endif
; 266  : #ifdef CMYK_SUPPORT
; 267  : 		case FIELD_DOTRANGE:
; 268  : #endif
; 269  : 			if (!TIFFSetupShortPair(tif, fip->field_tag, dir))

	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	mov	ecx, DWORD PTR _fip$65922[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFSetupShortPair
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65953

; 270  : 				goto bad;

	jmp	$bad$65907
$L65953:

; 271  : 			break;

	jmp	$L65926
$L65954:

; 272  : #ifdef CMYK_SUPPORT
; 273  : 		case FIELD_INKNAMES:
; 274  : 			if (!TIFFWriteInkNames(tif, dir))

	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteInkNames
	add	esp, 8
	test	eax, eax
	jne	SHORT $L65955

; 275  : 				goto bad;

	jmp	$bad$65907
$L65955:

; 276  : 			break;

	jmp	$L65926
$L65956:

; 277  : #endif
; 278  : #ifdef COLORIMETRY_SUPPORT
; 279  : 		case FIELD_TRANSFERFUNCTION:
; 280  : 			if (!TIFFWriteTransferFunction(tif, dir))

	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFWriteTransferFunction
	add	esp, 8
	test	eax, eax
	jne	SHORT $L65957

; 281  : 				goto bad;

	jmp	$bad$65907
$L65957:

; 282  : 			break;

	jmp	$L65926
$L65958:

; 283  : #endif
; 284  : #if SUBIFD_SUPPORT
; 285  : 		case FIELD_SUBIFD:
; 286  : 			if (!TIFFWriteNormalTag(tif, dir, fip))

	mov	edx, DWORD PTR _fip$65922[ebp]
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFWriteNormalTag
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65959

; 287  : 				goto bad;

	jmp	$bad$65907
$L65959:

; 288  : 			/*
; 289  : 			 * Total hack: if this directory includes a SubIFD
; 290  : 			 * tag then force the next <n> directories to be
; 291  : 			 * written as ``sub directories'' of this one.  This
; 292  : 			 * is used to write things like thumbnails and
; 293  : 			 * image masks that one wants to keep out of the
; 294  : 			 * normal directory linkage access mechanism.
; 295  : 			 */
; 296  : 			if (dir->tdir_count > 0) {

	mov	edx, DWORD PTR _dir$[ebp]
	cmp	DWORD PTR [edx+4], 0
	jbe	SHORT $L65963

; 297  : 				tif->tif_flags |= TIFF_INSUBIFD;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	or	ch, 32					; 00000020H
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx

; 298  : 				tif->tif_nsubifd = (uint16) dir->tdir_count;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _dir$[ebp]
	mov	dx, WORD PTR [ecx+4]
	mov	WORD PTR [eax+376], dx

; 299  : 				if (dir->tdir_count > 1)

	mov	eax, DWORD PTR _dir$[ebp]
	cmp	DWORD PTR [eax+4], 1
	jbe	SHORT $L65962

; 300  : 					tif->tif_subifdoff = dir->tdir_offset;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	DWORD PTR [ecx+380], eax

; 301  : 				else

	jmp	SHORT $L65963
$L65962:

; 302  : 					tif->tif_subifdoff = (uint32)(
; 303  : 					      tif->tif_diroff
; 304  : 					    + sizeof (uint16)
; 305  : 					    + ((char*)&dir->tdir_offset-data));

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	mov	eax, DWORD PTR _dir$[ebp]
	add	eax, 8
	sub	eax, DWORD PTR _data$[ebp]
	lea	ecx, DWORD PTR [edx+eax+2]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+380], ecx
$L65963:

; 307  : 			break;

	jmp	SHORT $L65926
$L65967:

; 308  : #endif
; 309  : 		default:
; 310  : 			if (!TIFFWriteNormalTag(tif, dir, fip))

	mov	eax, DWORD PTR _fip$65922[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteNormalTag
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65968

; 311  : 				goto bad;

	jmp	$bad$65907
$L65968:
$L65926:

; 314  : 		dir++;

	mov	eax, DWORD PTR _dir$[ebp]
	add	eax, 12					; 0000000cH
	mov	DWORD PTR _dir$[ebp], eax

; 315  : 		ResetFieldBit(fields, fip->field_bit);

	mov	ecx, DWORD PTR _fip$65922[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [ecx+12]
	cdq
	and	edx, 31					; 0000001fH
	add	eax, edx
	sar	eax, 5
	mov	edx, DWORD PTR _fip$65922[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+12]
	and	ecx, 31					; 0000001fH
	mov	edx, 1
	shl	edx, cl
	not	edx
	mov	ecx, DWORD PTR _fields$[ebp+eax*4]
	and	ecx, edx
	mov	edx, DWORD PTR _fip$65922[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+12]
	cdq
	and	edx, 31					; 0000001fH
	add	eax, edx
	sar	eax, 5
	mov	DWORD PTR _fields$[ebp+eax*4], ecx

; 316  : 	}

	jmp	$L65920
$L65921:

; 317  : 	/*
; 318  : 	 * Write directory.
; 319  : 	 */
; 320  : 	dircount = (uint16) nfields;

	mov	ax, WORD PTR _nfields$[ebp]
	mov	WORD PTR _dircount$[ebp], ax

; 321  : 	diroff = (uint32) tif->tif_nextdiroff;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+20]
	mov	DWORD PTR _diroff$[ebp], edx

; 322  : 	if (tif->tif_flags & TIFF_SWAB) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 128				; 00000080H
	test	ecx, ecx
	je	SHORT $L65972

; 323  : 		/*
; 324  : 		 * The file's byte order is opposite to the
; 325  : 		 * native machine architecture.  We overwrite
; 326  : 		 * the directory information with impunity
; 327  : 		 * because it'll be released below after we
; 328  : 		 * write it to the file.  Note that all the
; 329  : 		 * other tag construction routines assume that
; 330  : 		 * we do this byte-swapping; i.e. they only
; 331  : 		 * byte-swap indirect data.
; 332  : 		 */
; 333  : 		for (dir = (TIFFDirEntry*) data; dircount; dir++, dircount--) {

	mov	edx, DWORD PTR _data$[ebp]
	mov	DWORD PTR _dir$[ebp], edx
	jmp	SHORT $L65974
$L65975:
	mov	eax, DWORD PTR _dir$[ebp]
	add	eax, 12					; 0000000cH
	mov	DWORD PTR _dir$[ebp], eax
	mov	cx, WORD PTR _dircount$[ebp]
	sub	cx, 1
	mov	WORD PTR _dircount$[ebp], cx
$L65974:
	mov	edx, DWORD PTR _dircount$[ebp]
	and	edx, 65535				; 0000ffffH
	test	edx, edx
	je	SHORT $L65976

; 334  : 			TIFFSwabArrayOfShort(&dir->tdir_tag, 2);

	push	2
	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	call	_TIFFSwabArrayOfShort
	add	esp, 8

; 335  : 			TIFFSwabArrayOfLong(&dir->tdir_count, 2);

	push	2
	mov	ecx, DWORD PTR _dir$[ebp]
	add	ecx, 4
	push	ecx
	call	_TIFFSwabArrayOfLong
	add	esp, 8

; 336  : 		}

	jmp	SHORT $L65975
$L65976:

; 337  : 		dircount = (uint16) nfields;

	mov	dx, WORD PTR _nfields$[ebp]
	mov	WORD PTR _dircount$[ebp], dx

; 338  : 		TIFFSwabShort(&dircount);

	lea	eax, DWORD PTR _dircount$[ebp]
	push	eax
	call	_TIFFSwabShort
	add	esp, 4

; 339  : 		TIFFSwabLong(&diroff);

	lea	ecx, DWORD PTR _diroff$[ebp]
	push	ecx
	call	_TIFFSwabLong
	add	esp, 4
$L65972:

; 341  : 	(void) TIFFSeekFile(tif, tif->tif_diroff, SEEK_SET);

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

; 342  : 	if (!WriteOK(tif, &dircount, sizeof (dircount))) {

	push	2
	lea	ecx, DWORD PTR _dircount$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+504]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+512]
	add	esp, 12					; 0000000cH
	cmp	eax, 2
	je	SHORT $L65983

; 343  : 		TIFFError(tif->tif_name, "Error writing directory count");

	push	OFFSET FLAT:$SG65984
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 8

; 344  : 		goto bad;

	jmp	$bad$65907
$L65983:

; 346  : 	if (!WriteOK(tif, data, dirsize)) {

	mov	ecx, DWORD PTR _dirsize$[ebp]
	push	ecx
	mov	edx, DWORD PTR _data$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+512]
	add	esp, 12					; 0000000cH
	cmp	eax, DWORD PTR _dirsize$[ebp]
	je	SHORT $L65988

; 347  : 		TIFFError(tif->tif_name, "Error writing directory contents");

	push	OFFSET FLAT:$SG65989
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 8

; 348  : 		goto bad;

	jmp	$bad$65907
$L65988:

; 350  : 	if (!WriteOK(tif, &diroff, sizeof (diroff))) {

	push	4
	lea	edx, DWORD PTR _diroff$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+512]
	add	esp, 12					; 0000000cH
	cmp	eax, 4
	je	SHORT $L65993

; 351  : 		TIFFError(tif->tif_name, "Error writing directory link");

	push	OFFSET FLAT:$SG65994
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 8

; 352  : 		goto bad;

	jmp	SHORT $bad$65907
$L65993:

; 354  : 	TIFFFreeDirectory(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFreeDirectory
	add	esp, 4

; 355  : 	_TIFFfree(data);

	mov	eax, DWORD PTR _data$[ebp]
	push	eax
	call	__TIFFfree
	add	esp, 4

; 356  : 	tif->tif_flags &= ~TIFF_DIRTYDIRECT;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, -9					; fffffff7H
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+12], edx

; 357  : 	(*tif->tif_cleanup)(tif);

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+448]
	add	esp, 4

; 358  : 
; 359  : 	/*
; 360  : 	 * Reset directory-related state for subsequent
; 361  : 	 * directories.
; 362  : 	 */
; 363  :         TIFFCreateDirectory(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFCreateDirectory
	add	esp, 4

; 364  : 	return (1);

	mov	eax, 1
	jmp	SHORT $L65875
$bad$65907:

; 365  : bad:
; 366  : 	_TIFFfree(data);

	mov	ecx, DWORD PTR _data$[ebp]
	push	ecx
	call	__TIFFfree
	add	esp, 4

; 367  : 	return (0);

	xor	eax, eax
$L65875:

; 368  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L66578:
	DD	$L65940
	DD	$L65941
	DD	$L65945
	DD	$L65942
	DD	$L65948
	DD	$L65937
	DD	$L65952
	DD	$L65933
	DD	$L65929
	DD	$L65938
	DD	$L65950
	DD	$L65956
	DD	$L65954
	DD	$L65958
	DD	$L65967
$L66577:
	DB	0
	DB	1
	DB	2
	DB	3
	DB	14					; 0000000eH
	DB	4
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	5
	DB	4
	DB	4
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	6
	DB	7
	DB	8
	DB	9
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	4
	DB	10					; 0000000aH
	DB	10					; 0000000aH
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	6
	DB	14					; 0000000eH
	DB	6
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	14					; 0000000eH
	DB	11					; 0000000bH
	DB	14					; 0000000eH
	DB	12					; 0000000cH
	DB	6
	DB	14					; 0000000eH
	DB	13					; 0000000dH
_TIFFWriteDirectory ENDP
_TEXT	ENDS
EXTRN	_strlen:NEAR
EXTRN	_TIFFGetField:NEAR
_TEXT	SEGMENT
_tif$ = 8
_dir$ = 12
_fip$ = 16
_wc$ = -4
_wc2$ = -8
_wp$66014 = -12
_sv$66020 = -16
_lp$66024 = -20
_fp$66032 = -24
_fv$66038 = -28
_fp$66042 = -32
_fv$66048 = -36
_dp$66052 = -40
_dv$66058 = -48
_cp$66061 = -52
_cp$66066 = -56
_cv$66075 = -60
_cp$66078 = -64
_TIFFWriteNormalTag PROC NEAR

; 376  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H

; 377  : 	u_short wc = (u_short) fip->field_writecount;

	mov	eax, DWORD PTR _fip$[ebp]
	mov	cx, WORD PTR [eax+6]
	mov	WORD PTR _wc$[ebp], cx

; 378  : 	uint32 wc2;
; 379  : 
; 380  : 	dir->tdir_tag = (uint16) fip->field_tag;

	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR _fip$[ebp]
	mov	cx, WORD PTR [eax]
	mov	WORD PTR [edx], cx

; 381  : 	dir->tdir_type = (u_short) fip->field_type;

	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR _fip$[ebp]
	mov	cx, WORD PTR [eax+8]
	mov	WORD PTR [edx+2], cx

; 382  : 	dir->tdir_count = wc;

	mov	edx, DWORD PTR _wc$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _dir$[ebp]
	mov	DWORD PTR [eax+4], edx

; 383  : #define	WRITEF(x,y)	x(tif, fip->field_type, fip->field_tag, dir, wc, y)
; 384  : 	switch (fip->field_type) {

	mov	ecx, DWORD PTR _fip$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR -68+[ebp], edx
	mov	eax, DWORD PTR -68+[ebp]
	sub	eax, 1
	mov	DWORD PTR -68+[ebp], eax
	cmp	DWORD PTR -68+[ebp], 11			; 0000000bH
	ja	$L66009
	mov	ecx, DWORD PTR -68+[ebp]
	jmp	DWORD PTR $L66582[ecx*4]
$L66012:

; 385  : 	case TIFF_SHORT:
; 386  : 	case TIFF_SSHORT:
; 387  : 		if (wc > 1) {

	mov	edx, DWORD PTR _wc$[ebp]
	and	edx, 65535				; 0000ffffH
	cmp	edx, 1
	jle	SHORT $L66013

; 388  : 			uint16* wp;
; 389  : 			if (wc == (u_short) TIFF_VARIABLE)

	mov	eax, DWORD PTR _wc$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 65535				; 0000ffffH
	jne	SHORT $L66016

; 390  : 				TIFFGetField(tif, fip->field_tag, &wc, &wp);

	lea	ecx, DWORD PTR _wp$66014[ebp]
	push	ecx
	lea	edx, DWORD PTR _wc$[ebp]
	push	edx
	mov	eax, DWORD PTR _fip$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFGetField
	add	esp, 16					; 00000010H

; 391  : 			else

	jmp	SHORT $L66017
$L66016:

; 392  : 				TIFFGetField(tif, fip->field_tag, &wp);

	lea	eax, DWORD PTR _wp$66014[ebp]
	push	eax
	mov	ecx, DWORD PTR _fip$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetField
	add	esp, 12					; 0000000cH
$L66017:

; 393  : 			if (!WRITEF(TIFFWriteShortArray, wp))

	mov	ecx, DWORD PTR _wp$66014[ebp]
	push	ecx
	mov	edx, DWORD PTR _wc$[ebp]
	and	edx, 65535				; 0000ffffH
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	mov	ecx, DWORD PTR _fip$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _fip$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteShortArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L66018

; 394  : 				return (0);

	xor	eax, eax
	jmp	$L66001
$L66018:

; 395  : 		} else {

	jmp	$L66019
$L66013:

; 396  : 			uint16 sv;
; 397  : 			TIFFGetField(tif, fip->field_tag, &sv);

	lea	eax, DWORD PTR _sv$66020[ebp]
	push	eax
	mov	ecx, DWORD PTR _fip$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetField
	add	esp, 12					; 0000000cH

; 398  : 			dir->tdir_offset =
; 399  : 			    TIFFInsertData(tif, dir->tdir_type, sv);

	mov	ecx, DWORD PTR _tif$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+336]
	cmp	edx, 19789				; 00004d4dH
	jne	SHORT $L66580
	mov	eax, DWORD PTR _sv$66020[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _dir$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+2]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [ecx+352]
	and	eax, DWORD PTR [ecx+edx*4]
	mov	edx, DWORD PTR _dir$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+2]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [edx+348]
	mov	ecx, DWORD PTR [edx+ecx*4]
	shl	eax, cl
	mov	DWORD PTR -72+[ebp], eax
	jmp	SHORT $L66581
$L66580:
	mov	eax, DWORD PTR _sv$66020[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _dir$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+2]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [ecx+352]
	and	eax, DWORD PTR [ecx+edx*4]
	mov	DWORD PTR -72+[ebp], eax
$L66581:
	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR -72+[ebp]
	mov	DWORD PTR [edx+8], eax
$L66019:

; 401  : 		break;

	jmp	$L66009
$L66022:

; 402  : 	case TIFF_LONG:
; 403  : 	case TIFF_SLONG:
; 404  : 		if (wc > 1) {

	mov	ecx, DWORD PTR _wc$[ebp]
	and	ecx, 65535				; 0000ffffH
	cmp	ecx, 1
	jle	SHORT $L66023

; 405  : 			uint32* lp;
; 406  : 			if (wc == (u_short) TIFF_VARIABLE)

	mov	edx, DWORD PTR _wc$[ebp]
	and	edx, 65535				; 0000ffffH
	cmp	edx, 65535				; 0000ffffH
	jne	SHORT $L66026

; 407  : 				TIFFGetField(tif, fip->field_tag, &wc, &lp);

	lea	eax, DWORD PTR _lp$66024[ebp]
	push	eax
	lea	ecx, DWORD PTR _wc$[ebp]
	push	ecx
	mov	edx, DWORD PTR _fip$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFGetField
	add	esp, 16					; 00000010H

; 408  : 			else

	jmp	SHORT $L66027
$L66026:

; 409  : 				TIFFGetField(tif, fip->field_tag, &lp);

	lea	edx, DWORD PTR _lp$66024[ebp]
	push	edx
	mov	eax, DWORD PTR _fip$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFGetField
	add	esp, 12					; 0000000cH
$L66027:

; 410  : 			if (!WRITEF(TIFFWriteLongArray, lp))

	mov	eax, DWORD PTR _lp$66024[ebp]
	push	eax
	mov	ecx, DWORD PTR _wc$[ebp]
	and	ecx, 65535				; 0000ffffH
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _fip$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _fip$[ebp]
	mov	eax, DWORD PTR [edx+8]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFWriteLongArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L66028

; 411  : 				return (0);

	xor	eax, eax
	jmp	$L66001
$L66028:

; 412  : 		} else {

	jmp	SHORT $L66029
$L66023:

; 413  : 			/* XXX handle LONG->SHORT conversion */
; 414  : 			TIFFGetField(tif, fip->field_tag, &dir->tdir_offset);

	mov	edx, DWORD PTR _dir$[ebp]
	add	edx, 8
	push	edx
	mov	eax, DWORD PTR _fip$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFGetField
	add	esp, 12					; 0000000cH
$L66029:

; 416  : 		break;

	jmp	$L66009
$L66030:

; 417  : 	case TIFF_RATIONAL:
; 418  : 	case TIFF_SRATIONAL:
; 419  : 		if (wc > 1) {

	mov	eax, DWORD PTR _wc$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 1
	jle	SHORT $L66031

; 420  : 			float* fp;
; 421  : 			if (wc == (u_short) TIFF_VARIABLE)

	mov	ecx, DWORD PTR _wc$[ebp]
	and	ecx, 65535				; 0000ffffH
	cmp	ecx, 65535				; 0000ffffH
	jne	SHORT $L66034

; 422  : 				TIFFGetField(tif, fip->field_tag, &wc, &fp);

	lea	edx, DWORD PTR _fp$66032[ebp]
	push	edx
	lea	eax, DWORD PTR _wc$[ebp]
	push	eax
	mov	ecx, DWORD PTR _fip$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetField
	add	esp, 16					; 00000010H

; 423  : 			else

	jmp	SHORT $L66035
$L66034:

; 424  : 				TIFFGetField(tif, fip->field_tag, &fp);

	lea	ecx, DWORD PTR _fp$66032[ebp]
	push	ecx
	mov	edx, DWORD PTR _fip$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFGetField
	add	esp, 12					; 0000000cH
$L66035:

; 425  : 			if (!WRITEF(TIFFWriteRationalArray, fp))

	mov	edx, DWORD PTR _fp$66032[ebp]
	push	edx
	mov	eax, DWORD PTR _wc$[ebp]
	and	eax, 65535				; 0000ffffH
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _fip$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _fip$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFWriteRationalArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L66036

; 426  : 				return (0);

	xor	eax, eax
	jmp	$L66001
$L66036:

; 427  : 		} else {

	jmp	SHORT $L66039
$L66031:

; 428  : 			float fv;
; 429  : 			TIFFGetField(tif, fip->field_tag, &fv);

	lea	ecx, DWORD PTR _fv$66038[ebp]
	push	ecx
	mov	edx, DWORD PTR _fip$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFGetField
	add	esp, 12					; 0000000cH

; 430  : 			if (!WRITEF(TIFFWriteRationalArray, &fv))

	lea	edx, DWORD PTR _fv$66038[ebp]
	push	edx
	mov	eax, DWORD PTR _wc$[ebp]
	and	eax, 65535				; 0000ffffH
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _fip$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _fip$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFWriteRationalArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L66039

; 431  : 				return (0);

	xor	eax, eax
	jmp	$L66001
$L66039:

; 433  : 		break;

	jmp	$L66009
$L66040:

; 434  : 	case TIFF_FLOAT:
; 435  : 		if (wc > 1) {

	mov	ecx, DWORD PTR _wc$[ebp]
	and	ecx, 65535				; 0000ffffH
	cmp	ecx, 1
	jle	SHORT $L66041

; 436  : 			float* fp;
; 437  : 			if (wc == (u_short) TIFF_VARIABLE)

	mov	edx, DWORD PTR _wc$[ebp]
	and	edx, 65535				; 0000ffffH
	cmp	edx, 65535				; 0000ffffH
	jne	SHORT $L66044

; 438  : 				TIFFGetField(tif, fip->field_tag, &wc, &fp);

	lea	eax, DWORD PTR _fp$66042[ebp]
	push	eax
	lea	ecx, DWORD PTR _wc$[ebp]
	push	ecx
	mov	edx, DWORD PTR _fip$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFGetField
	add	esp, 16					; 00000010H

; 439  : 			else

	jmp	SHORT $L66045
$L66044:

; 440  : 				TIFFGetField(tif, fip->field_tag, &fp);

	lea	edx, DWORD PTR _fp$66042[ebp]
	push	edx
	mov	eax, DWORD PTR _fip$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFGetField
	add	esp, 12					; 0000000cH
$L66045:

; 441  : 			if (!WRITEF(TIFFWriteFloatArray, fp))

	mov	eax, DWORD PTR _fp$66042[ebp]
	push	eax
	mov	ecx, DWORD PTR _wc$[ebp]
	and	ecx, 65535				; 0000ffffH
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _fip$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _fip$[ebp]
	mov	eax, DWORD PTR [edx+8]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFWriteFloatArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L66046

; 442  : 				return (0);

	xor	eax, eax
	jmp	$L66001
$L66046:

; 443  : 		} else {

	jmp	SHORT $L66049
$L66041:

; 444  : 			float fv;
; 445  : 			TIFFGetField(tif, fip->field_tag, &fv);

	lea	edx, DWORD PTR _fv$66048[ebp]
	push	edx
	mov	eax, DWORD PTR _fip$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFGetField
	add	esp, 12					; 0000000cH

; 446  : 			if (!WRITEF(TIFFWriteFloatArray, &fv))

	lea	eax, DWORD PTR _fv$66048[ebp]
	push	eax
	mov	ecx, DWORD PTR _wc$[ebp]
	and	ecx, 65535				; 0000ffffH
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _fip$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _fip$[ebp]
	mov	eax, DWORD PTR [edx+8]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFWriteFloatArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L66049

; 447  : 				return (0);

	xor	eax, eax
	jmp	$L66001
$L66049:

; 449  : 		break;

	jmp	$L66009
$L66050:

; 450  : 	case TIFF_DOUBLE:
; 451  : 		if (wc > 1) {

	mov	edx, DWORD PTR _wc$[ebp]
	and	edx, 65535				; 0000ffffH
	cmp	edx, 1
	jle	SHORT $L66051

; 452  : 			double* dp;
; 453  : 			if (wc == (u_short) TIFF_VARIABLE)

	mov	eax, DWORD PTR _wc$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 65535				; 0000ffffH
	jne	SHORT $L66054

; 454  : 				TIFFGetField(tif, fip->field_tag, &wc, &dp);

	lea	ecx, DWORD PTR _dp$66052[ebp]
	push	ecx
	lea	edx, DWORD PTR _wc$[ebp]
	push	edx
	mov	eax, DWORD PTR _fip$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFGetField
	add	esp, 16					; 00000010H

; 455  : 			else

	jmp	SHORT $L66055
$L66054:

; 456  : 				TIFFGetField(tif, fip->field_tag, &dp);

	lea	eax, DWORD PTR _dp$66052[ebp]
	push	eax
	mov	ecx, DWORD PTR _fip$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetField
	add	esp, 12					; 0000000cH
$L66055:

; 457  : 			if (!WRITEF(TIFFWriteDoubleArray, dp))

	mov	ecx, DWORD PTR _dp$66052[ebp]
	push	ecx
	mov	edx, DWORD PTR _wc$[ebp]
	and	edx, 65535				; 0000ffffH
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	mov	ecx, DWORD PTR _fip$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _fip$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteDoubleArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L66056

; 458  : 				return (0);

	xor	eax, eax
	jmp	$L66001
$L66056:

; 459  : 		} else {

	jmp	SHORT $L66059
$L66051:

; 460  : 			double dv;
; 461  : 			TIFFGetField(tif, fip->field_tag, &dv);

	lea	eax, DWORD PTR _dv$66058[ebp]
	push	eax
	mov	ecx, DWORD PTR _fip$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetField
	add	esp, 12					; 0000000cH

; 462  : 			if (!WRITEF(TIFFWriteDoubleArray, &dv))

	lea	ecx, DWORD PTR _dv$66058[ebp]
	push	ecx
	mov	edx, DWORD PTR _wc$[ebp]
	and	edx, 65535				; 0000ffffH
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	mov	ecx, DWORD PTR _fip$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _fip$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteDoubleArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L66059

; 463  : 				return (0);

	xor	eax, eax
	jmp	$L66001
$L66059:

; 465  : 		break;

	jmp	$L66009
$L66060:

; 468  : 		  TIFFGetField(tif, fip->field_tag, &cp);

	lea	eax, DWORD PTR _cp$66061[ebp]
	push	eax
	mov	ecx, DWORD PTR _fip$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetField
	add	esp, 12					; 0000000cH

; 469  : 		  dir->tdir_count = (uint32) (strlen(cp) + 1);

	mov	ecx, DWORD PTR _cp$66061[ebp]
	push	ecx
	call	_strlen
	add	esp, 4
	add	eax, 1
	mov	edx, DWORD PTR _dir$[ebp]
	mov	DWORD PTR [edx+4], eax

; 470  : 		  if (!TIFFWriteByteArray(tif, dir, cp))

	mov	eax, DWORD PTR _cp$66061[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteByteArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66063

; 471  : 			return (0);

	xor	eax, eax
	jmp	$L66001
$L66063:

; 473  : 		break;

	jmp	$L66009
$L66064:

; 474  : 
; 475  :         /* added based on patch request from MARTIN.MCBRIDE.MM@agfa.co.uk,
; 476  :            correctness not verified (FW, 99/08) */
; 477  :         case TIFF_BYTE:
; 478  :         case TIFF_SBYTE:          
; 479  :                 if (wc > 1) {

	mov	eax, DWORD PTR _wc$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 1
	jle	$L66065

; 480  :                     char* cp;
; 481  :                     if (wc == (u_short) TIFF_VARIABLE) {

	mov	ecx, DWORD PTR _wc$[ebp]
	and	ecx, 65535				; 0000ffffH
	cmp	ecx, 65535				; 0000ffffH
	jne	SHORT $L66068

; 482  :                         TIFFGetField(tif, fip->field_tag, &wc, &cp);

	lea	edx, DWORD PTR _cp$66066[ebp]
	push	edx
	lea	eax, DWORD PTR _wc$[ebp]
	push	eax
	mov	ecx, DWORD PTR _fip$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetField
	add	esp, 16					; 00000010H

; 483  :                         dir->tdir_count = wc;

	mov	ecx, DWORD PTR _wc$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _dir$[ebp]
	mov	DWORD PTR [edx+4], ecx

; 484  :                     } else if (wc == (u_short) TIFF_VARIABLE2) {

	jmp	SHORT $L66072
$L66068:
	mov	eax, DWORD PTR _wc$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 65533				; 0000fffdH
	jne	SHORT $L66071

; 485  : 			TIFFGetField(tif, fip->field_tag, &wc2, &cp);

	lea	ecx, DWORD PTR _cp$66066[ebp]
	push	ecx
	lea	edx, DWORD PTR _wc2$[ebp]
	push	edx
	mov	eax, DWORD PTR _fip$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFGetField
	add	esp, 16					; 00000010H

; 486  : 			dir->tdir_count = wc2;

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR _wc2$[ebp]
	mov	DWORD PTR [eax+4], ecx

; 487  :                     } else

	jmp	SHORT $L66072
$L66071:

; 488  :                         TIFFGetField(tif, fip->field_tag, &cp);

	lea	edx, DWORD PTR _cp$66066[ebp]
	push	edx
	mov	eax, DWORD PTR _fip$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFGetField
	add	esp, 12					; 0000000cH
$L66072:

; 489  :                     if (!TIFFWriteByteArray(tif, dir, cp))

	mov	eax, DWORD PTR _cp$66066[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteByteArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66073

; 490  :                         return (0);

	xor	eax, eax
	jmp	$L66001
$L66073:

; 491  :                 } else {

	jmp	SHORT $L66076
$L66065:

; 492  :                     char cv;
; 493  :                     TIFFGetField(tif, fip->field_tag, &cv);

	lea	eax, DWORD PTR _cv$66075[ebp]
	push	eax
	mov	ecx, DWORD PTR _fip$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetField
	add	esp, 12					; 0000000cH

; 494  :                     if (!TIFFWriteByteArray(tif, dir, &cv))

	lea	ecx, DWORD PTR _cv$66075[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFWriteByteArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66076

; 495  :                         return (0);

	xor	eax, eax
	jmp	$L66001
$L66076:

; 497  :                 break;

	jmp	$L66009
$L66077:

; 501  : 		  if (wc == (u_short) TIFF_VARIABLE) {

	mov	ecx, DWORD PTR _wc$[ebp]
	and	ecx, 65535				; 0000ffffH
	cmp	ecx, 65535				; 0000ffffH
	jne	SHORT $L66080

; 502  : 			TIFFGetField(tif, fip->field_tag, &wc, &cp);

	lea	edx, DWORD PTR _cp$66078[ebp]
	push	edx
	lea	eax, DWORD PTR _wc$[ebp]
	push	eax
	mov	ecx, DWORD PTR _fip$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetField
	add	esp, 16					; 00000010H

; 503  : 			dir->tdir_count = wc;

	mov	ecx, DWORD PTR _wc$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _dir$[ebp]
	mov	DWORD PTR [edx+4], ecx

; 504  : 		  } else if (wc == (u_short) TIFF_VARIABLE2) {

	jmp	SHORT $L66084
$L66080:
	mov	eax, DWORD PTR _wc$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 65533				; 0000fffdH
	jne	SHORT $L66083

; 505  : 			TIFFGetField(tif, fip->field_tag, &wc2, &cp);

	lea	ecx, DWORD PTR _cp$66078[ebp]
	push	ecx
	lea	edx, DWORD PTR _wc2$[ebp]
	push	edx
	mov	eax, DWORD PTR _fip$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFGetField
	add	esp, 16					; 00000010H

; 506  : 			dir->tdir_count = wc2;

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR _wc2$[ebp]
	mov	DWORD PTR [eax+4], ecx

; 507  : 		  } else 

	jmp	SHORT $L66084
$L66083:

; 508  : 			TIFFGetField(tif, fip->field_tag, &cp);

	lea	edx, DWORD PTR _cp$66078[ebp]
	push	edx
	mov	eax, DWORD PTR _fip$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFGetField
	add	esp, 12					; 0000000cH
$L66084:

; 509  : 		  if (!TIFFWriteByteArray(tif, dir, cp))

	mov	eax, DWORD PTR _cp$66078[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteByteArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66085

; 510  : 			return (0);

	xor	eax, eax
	jmp	SHORT $L66001
$L66085:
$L66009:

; 517  : 	return (1);

	mov	eax, 1
$L66001:

; 518  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L66582:
	DD	$L66064
	DD	$L66060
	DD	$L66012
	DD	$L66022
	DD	$L66030
	DD	$L66064
	DD	$L66077
	DD	$L66012
	DD	$L66022
	DD	$L66030
	DD	$L66040
	DD	$L66050
_TIFFWriteNormalTag ENDP
_tif$ = 8
_tag$ = 12
_dir$ = 16
_v$ = 20
_TIFFSetupShortLong PROC NEAR

; 527  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 528  : 	dir->tdir_tag = (uint16) tag;

	mov	eax, DWORD PTR _dir$[ebp]
	mov	cx, WORD PTR _tag$[ebp]
	mov	WORD PTR [eax], cx

; 529  : 	dir->tdir_count = 1;

	mov	edx, DWORD PTR _dir$[ebp]
	mov	DWORD PTR [edx+4], 1

; 530  : 	if (v > 0xffffL) {

	cmp	DWORD PTR _v$[ebp], 65535		; 0000ffffH
	jbe	SHORT $L66097

; 531  : 		dir->tdir_type = (short) TIFF_LONG;

	mov	eax, DWORD PTR _dir$[ebp]
	mov	WORD PTR [eax+2], 4

; 532  : 		dir->tdir_offset = v;

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR _v$[ebp]
	mov	DWORD PTR [ecx+8], edx

; 533  : 	} else {

	jmp	SHORT $L66099
$L66097:

; 534  : 		dir->tdir_type = (short) TIFF_SHORT;

	mov	eax, DWORD PTR _dir$[ebp]
	mov	WORD PTR [eax+2], 3

; 535  : 		dir->tdir_offset = TIFFInsertData(tif, (int) TIFF_SHORT, v);

	mov	ecx, DWORD PTR _tif$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+336]
	cmp	edx, 19789				; 00004d4dH
	jne	SHORT $L66584
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+352]
	mov	edx, DWORD PTR _v$[ebp]
	and	edx, DWORD PTR [ecx+12]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+348]
	mov	ecx, DWORD PTR [ecx+12]
	shl	edx, cl
	mov	DWORD PTR -4+[ebp], edx
	jmp	SHORT $L66585
$L66584:
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+352]
	mov	ecx, DWORD PTR _v$[ebp]
	and	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR -4+[ebp], ecx
$L66585:
	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR -4+[ebp]
	mov	DWORD PTR [edx+8], eax
$L66099:

; 537  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFSetupShortLong ENDP
_tif$ = 8
_tag$ = 12
_dir$ = 16
_buf$ = -20
_v$ = -24
_w$ = -32
_i$ = -36
_status$ = -40
_samples$ = -28
_TIFFWritePerSampleShorts PROC NEAR

; 562  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 40					; 00000028H

; 563  : 	uint16 buf[10], v;
; 564  : 	uint16* w = buf;

	lea	eax, DWORD PTR _buf$[ebp]
	mov	DWORD PTR _w$[ebp], eax

; 565  : 	int i, status, samples = tif->tif_dir.td_samplesperpixel;

	mov	ecx, DWORD PTR _tif$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+78]
	mov	DWORD PTR _samples$[ebp], edx

; 566  : 
; 567  : 	if (samples > NITEMS(buf))

	cmp	DWORD PTR _samples$[ebp], 10		; 0000000aH
	jbe	SHORT $L66119

; 568  : 		w = (uint16*) _TIFFmalloc(samples * sizeof (uint16));

	mov	eax, DWORD PTR _samples$[ebp]
	shl	eax, 1
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	DWORD PTR _w$[ebp], eax
$L66119:

; 569  : 	TIFFGetField(tif, tag, &v);

	lea	ecx, DWORD PTR _v$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tag$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetField
	add	esp, 12					; 0000000cH

; 570  : 	for (i = 0; i < samples; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L66122
$L66123:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L66122:
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR _samples$[ebp]
	jge	SHORT $L66124

; 571  : 		w[i] = v;

	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _w$[ebp]
	mov	dx, WORD PTR _v$[ebp]
	mov	WORD PTR [ecx+eax*2], dx
	jmp	SHORT $L66123
$L66124:

; 572  : 	status = TIFFWriteShortArray(tif, TIFF_SHORT, tag, dir, samples, w);

	mov	eax, DWORD PTR _w$[ebp]
	push	eax
	mov	ecx, DWORD PTR _samples$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	push	3
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFWriteShortArray
	add	esp, 24					; 00000018H
	mov	DWORD PTR _status$[ebp], eax

; 573  : 	if (w != buf)

	mov	edx, DWORD PTR _w$[ebp]
	lea	eax, DWORD PTR _buf$[ebp]
	cmp	edx, eax
	je	SHORT $L66125

; 574  : 		_TIFFfree((char*) w);

	mov	ecx, DWORD PTR _w$[ebp]
	push	ecx
	call	__TIFFfree
	add	esp, 4
$L66125:

; 575  : 	return (status);

	mov	eax, DWORD PTR _status$[ebp]

; 576  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFWritePerSampleShorts ENDP
_TEXT	ENDS
EXTRN	__fltused:NEAR
_TEXT	SEGMENT
_tif$ = 8
_type$ = 12
_tag$ = 16
_dir$ = 20
_buf$ = -80
_v$ = -88
_w$ = -96
_i$ = -100
_status$ = -104
_samples$ = -92
_TIFFWritePerSampleAnys PROC NEAR

; 586  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 104				; 00000068H

; 587  : 	double buf[10], v;
; 588  : 	double* w = buf;

	lea	eax, DWORD PTR _buf$[ebp]
	mov	DWORD PTR _w$[ebp], eax

; 589  : 	int i, status;
; 590  : 	int samples = (int) tif->tif_dir.td_samplesperpixel;

	mov	ecx, DWORD PTR _tif$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+78]
	mov	DWORD PTR _samples$[ebp], edx

; 591  : 
; 592  : 	if (samples > NITEMS(buf))

	cmp	DWORD PTR _samples$[ebp], 10		; 0000000aH
	jbe	SHORT $L66143

; 593  : 		w = (double*) _TIFFmalloc(samples * sizeof (double));

	mov	eax, DWORD PTR _samples$[ebp]
	shl	eax, 3
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	DWORD PTR _w$[ebp], eax
$L66143:

; 594  : 	TIFFGetField(tif, tag, &v);

	lea	ecx, DWORD PTR _v$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tag$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetField
	add	esp, 12					; 0000000cH

; 595  : 	for (i = 0; i < samples; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L66146
$L66147:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L66146:
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR _samples$[ebp]
	jge	SHORT $L66148

; 596  : 		w[i] = v;

	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _w$[ebp]
	mov	edx, DWORD PTR _v$[ebp]
	mov	DWORD PTR [ecx+eax*8], edx
	mov	edx, DWORD PTR _v$[ebp+4]
	mov	DWORD PTR [ecx+eax*8+4], edx
	jmp	SHORT $L66147
$L66148:

; 597  : 	status = TIFFWriteAnyArray(tif, type, tag, dir, samples, w);

	mov	eax, DWORD PTR _w$[ebp]
	push	eax
	mov	ecx, DWORD PTR _samples$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	mov	ecx, DWORD PTR _type$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteAnyArray
	add	esp, 24					; 00000018H
	mov	DWORD PTR _status$[ebp], eax

; 598  : 	if (w != buf)

	mov	eax, DWORD PTR _w$[ebp]
	lea	ecx, DWORD PTR _buf$[ebp]
	cmp	eax, ecx
	je	SHORT $L66149

; 599  : 		_TIFFfree(w);

	mov	edx, DWORD PTR _w$[ebp]
	push	edx
	call	__TIFFfree
	add	esp, 4
$L66149:

; 600  : 	return (status);

	mov	eax, DWORD PTR _status$[ebp]

; 601  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFWritePerSampleAnys ENDP
_tif$ = 8
_tag$ = 12
_dir$ = 16
_v$ = -4
_TIFFSetupShortPair PROC NEAR

; 610  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 611  : 	uint16 v[2];
; 612  : 
; 613  : 	TIFFGetField(tif, tag, &v[0], &v[1]);

	lea	eax, DWORD PTR _v$[ebp+2]
	push	eax
	lea	ecx, DWORD PTR _v$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tag$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetField
	add	esp, 16					; 00000010H

; 614  : 	return (TIFFWriteShortArray(tif, TIFF_SHORT, tag, dir, 2, v));

	lea	ecx, DWORD PTR _v$[ebp]
	push	ecx
	push	2
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	push	3
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFWriteShortArray
	add	esp, 24					; 00000018H

; 615  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFSetupShortPair ENDP
_tif$ = 8
_tag$ = 12
_dir$ = 16
_n$ = 20
_table$ = 24
_i$ = -8
_off$ = -4
_TIFFWriteShortTable PROC NEAR

; 625  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 626  : 	uint32 i, off;
; 627  : 
; 628  : 	dir->tdir_tag = (uint16) tag;

	mov	eax, DWORD PTR _dir$[ebp]
	mov	cx, WORD PTR _tag$[ebp]
	mov	WORD PTR [eax], cx

; 629  : 	dir->tdir_type = (short) TIFF_SHORT;

	mov	edx, DWORD PTR _dir$[ebp]
	mov	WORD PTR [edx+2], 3

; 630  : 	/* XXX -- yech, fool TIFFWriteData */
; 631  : 	dir->tdir_count = (uint32) (1L<<tif->tif_dir.td_bitspersample);

	mov	eax, DWORD PTR _tif$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+64]
	mov	edx, 1
	shl	edx, cl
	mov	eax, DWORD PTR _dir$[ebp]
	mov	DWORD PTR [eax+4], edx

; 632  : 	off = tif->tif_dataoff;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+372]
	mov	DWORD PTR _off$[ebp], edx

; 633  : 	for (i = 0; i < n; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L66174
$L66175:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L66174:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _n$[ebp]
	jae	SHORT $L66176

; 634  : 		if (!TIFFWriteData(tif, dir, (char *)table[i]))

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _table$[ebp]
	mov	ecx, DWORD PTR [eax+edx*4]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFWriteData
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66178

; 635  : 			return (0);

	xor	eax, eax
	jmp	SHORT $L66168
$L66178:

; 636  : 	dir->tdir_count *= n;

	jmp	SHORT $L66175
$L66176:
	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	imul	edx, DWORD PTR _n$[ebp]
	mov	eax, DWORD PTR _dir$[ebp]
	mov	DWORD PTR [eax+4], edx

; 637  : 	dir->tdir_offset = off;

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR _off$[ebp]
	mov	DWORD PTR [ecx+8], edx

; 638  : 	return (1);

	mov	eax, 1
$L66168:

; 639  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFWriteShortTable ENDP
_tif$ = 8
_dir$ = 12
_cp$ = 16
_TIFFWriteByteArray PROC NEAR

; 646  : {

	push	ebp
	mov	ebp, esp

; 647  : 	if (dir->tdir_count > 4) {

	mov	eax, DWORD PTR _dir$[ebp]
	cmp	DWORD PTR [eax+4], 4
	jbe	SHORT $L66186

; 648  : 		if (!TIFFWriteData(tif, dir, cp))

	mov	ecx, DWORD PTR _cp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFWriteData
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66187

; 649  : 			return (0);

	xor	eax, eax
	jmp	SHORT $L66185
$L66187:

; 650  : 	} else

	jmp	SHORT $L66188
$L66186:

; 651  : 		_TIFFmemcpy(&dir->tdir_offset, cp, dir->tdir_count);

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	push	edx
	mov	eax, DWORD PTR _cp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	add	ecx, 8
	push	ecx
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH
$L66188:

; 652  : 	return (1);

	mov	eax, 1
$L66185:

; 653  : }

	pop	ebp
	ret	0
_TIFFWriteByteArray ENDP
_tif$ = 8
_type$ = 12
_tag$ = 16
_dir$ = 20
_n$ = 24
_v$ = 28
_TIFFWriteShortArray PROC NEAR

; 662  : {

	push	ebp
	mov	ebp, esp

; 663  : 	dir->tdir_tag = (uint16) tag;

	mov	eax, DWORD PTR _dir$[ebp]
	mov	cx, WORD PTR _tag$[ebp]
	mov	WORD PTR [eax], cx

; 664  : 	dir->tdir_type = (short) type;

	mov	edx, DWORD PTR _dir$[ebp]
	mov	ax, WORD PTR _type$[ebp]
	mov	WORD PTR [edx+2], ax

; 665  : 	dir->tdir_count = n;

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR _n$[ebp]
	mov	DWORD PTR [ecx+4], edx

; 666  : 	if (n <= 2) {

	cmp	DWORD PTR _n$[ebp], 2
	ja	$L66204

; 667  : 		if (tif->tif_header.tiff_magic == TIFF_BIGENDIAN) {

	mov	eax, DWORD PTR _tif$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+336]
	cmp	ecx, 19789				; 00004d4dH
	jne	SHORT $L66205

; 668  : 			dir->tdir_offset = (uint32) ((long) v[0] << 16);

	mov	edx, DWORD PTR _v$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	shl	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _dir$[ebp]
	mov	DWORD PTR [ecx+8], eax

; 669  : 			if (n == 2)

	cmp	DWORD PTR _n$[ebp], 2
	jne	SHORT $L66208

; 670  : 				dir->tdir_offset |= v[1] & 0xffff;

	mov	edx, DWORD PTR _v$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+2]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	or	edx, eax
	mov	eax, DWORD PTR _dir$[ebp]
	mov	DWORD PTR [eax+8], edx
$L66208:

; 671  : 		} else {

	jmp	SHORT $L66210
$L66205:

; 672  : 			dir->tdir_offset = v[0] & 0xffff;

	mov	ecx, DWORD PTR _v$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _dir$[ebp]
	mov	DWORD PTR [eax+8], edx

; 673  : 			if (n == 2)

	cmp	DWORD PTR _n$[ebp], 2
	jne	SHORT $L66210

; 674  : 				dir->tdir_offset |= (long) v[1] << 16;

	mov	ecx, DWORD PTR _v$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+2]
	shl	edx, 16					; 00000010H
	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	or	ecx, edx
	mov	edx, DWORD PTR _dir$[ebp]
	mov	DWORD PTR [edx+8], ecx
$L66210:

; 676  : 		return (1);

	mov	eax, 1
	jmp	SHORT $L66212
$L66204:

; 678  : 		return (TIFFWriteData(tif, dir, (char*) v));

	mov	eax, DWORD PTR _v$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteData
	add	esp, 12					; 0000000cH
$L66212:

; 679  : }

	pop	ebp
	ret	0
_TIFFWriteShortArray ENDP
_tif$ = 8
_type$ = 12
_tag$ = 16
_dir$ = 20
_n$ = 24
_v$ = 28
_TIFFWriteLongArray PROC NEAR

; 688  : {

	push	ebp
	mov	ebp, esp

; 689  : 	dir->tdir_tag = (uint16) tag;

	mov	eax, DWORD PTR _dir$[ebp]
	mov	cx, WORD PTR _tag$[ebp]
	mov	WORD PTR [eax], cx

; 690  : 	dir->tdir_type = (short) type;

	mov	edx, DWORD PTR _dir$[ebp]
	mov	ax, WORD PTR _type$[ebp]
	mov	WORD PTR [edx+2], ax

; 691  : 	dir->tdir_count = n;

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR _n$[ebp]
	mov	DWORD PTR [ecx+4], edx

; 692  : 	if (n == 1) {

	cmp	DWORD PTR _n$[ebp], 1
	jne	SHORT $L66229

; 693  : 		dir->tdir_offset = v[0];

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR _v$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax+8], edx

; 694  : 		return (1);

	mov	eax, 1
	jmp	SHORT $L66230
$L66229:

; 696  : 		return (TIFFWriteData(tif, dir, (char*) v));

	mov	eax, DWORD PTR _v$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteData
	add	esp, 12					; 0000000cH
$L66230:

; 697  : }

	pop	ebp
	ret	0
_TIFFWriteLongArray ENDP
_TEXT	ENDS
PUBLIC	__real@4@00000000000000000000
PUBLIC	__real@4@401b8000000000000000
PUBLIC	__real@4@40028000000000000000
PUBLIC	__real@8@3ffe8000000000000000
EXTRN	__ftol:NEAR
EXTRN	_TIFFWarning:NEAR
EXTRN	__TIFFFieldWithTag:NEAR
_DATA	SEGMENT
	ORG $+3
$SG66260 DB	'"%s": Information lost writing value (%g) as (unsigned) '
	DB	'RATIONAL', 00H
_DATA	ENDS
;	COMDAT __real@4@00000000000000000000
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_dirwrite.c
CONST	SEGMENT
__real@4@00000000000000000000 DD 000000000r	; 0
CONST	ENDS
;	COMDAT __real@4@401b8000000000000000
CONST	SEGMENT
__real@4@401b8000000000000000 DD 04d800000r	; 2.68435e+008
CONST	ENDS
;	COMDAT __real@4@40028000000000000000
CONST	SEGMENT
__real@4@40028000000000000000 DD 041000000r	; 8
CONST	ENDS
;	COMDAT __real@8@3ffe8000000000000000
CONST	SEGMENT
__real@8@3ffe8000000000000000 DQ 03fe0000000000000r ; 0.5
CONST	ENDS
_TEXT	SEGMENT
_tif$ = 8
_type$ = 12
_tag$ = 16
_dir$ = 20
_n$ = 24
_v$ = 28
_i$ = -8
_t$ = -4
_status$ = -12
_fv$66255 = -16
_sign$66256 = -24
_den$66257 = -20
_TIFFWriteRationalArray PROC NEAR

; 706  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 24					; 00000018H

; 707  : 	uint32 i;
; 708  : 	uint32* t;
; 709  : 	int status;
; 710  : 
; 711  : 	dir->tdir_tag = (uint16) tag;

	mov	eax, DWORD PTR _dir$[ebp]
	mov	cx, WORD PTR _tag$[ebp]
	mov	WORD PTR [eax], cx

; 712  : 	dir->tdir_type = (short) type;

	mov	edx, DWORD PTR _dir$[ebp]
	mov	ax, WORD PTR _type$[ebp]
	mov	WORD PTR [edx+2], ax

; 713  : 	dir->tdir_count = n;

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR _n$[ebp]
	mov	DWORD PTR [ecx+4], edx

; 714  : 	t = (uint32*) _TIFFmalloc(2*n * sizeof (uint32));

	mov	eax, DWORD PTR _n$[ebp]
	shl	eax, 1
	shl	eax, 2
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	DWORD PTR _t$[ebp], eax

; 715  : 	for (i = 0; i < n; i++) {

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L66252
$L66253:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L66252:
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR _n$[ebp]
	jae	$L66254

; 716  : 		float fv = v[i];

	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _v$[ebp]
	mov	edx, DWORD PTR [ecx+eax*4]
	mov	DWORD PTR _fv$66255[ebp], edx

; 717  : 		int sign = 1;

	mov	DWORD PTR _sign$66256[ebp], 1

; 718  : 		uint32 den;
; 719  : 
; 720  : 		if (fv < 0) {

	fld	DWORD PTR _fv$66255[ebp]
	fcomp	DWORD PTR __real@4@00000000000000000000
	fnstsw	ax
	test	ah, 1
	je	SHORT $L66261

; 721  : 			if (type == TIFF_RATIONAL) {

	cmp	DWORD PTR _type$[ebp], 5
	jne	SHORT $L66259

; 722  : 				TIFFWarning(tif->tif_name,
; 723  : 	"\"%s\": Information lost writing value (%g) as (unsigned) RATIONAL",
; 724  : 				_TIFFFieldWithTag(tif,tag)->field_name, fv);

	fld	DWORD PTR _fv$66255[ebp]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	__TIFFFieldWithTag
	add	esp, 8
	mov	edx, DWORD PTR [eax+16]
	push	edx
	push	OFFSET FLAT:$SG66260
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFWarning
	add	esp, 20					; 00000014H

; 725  : 				fv = 0;

	mov	DWORD PTR _fv$66255[ebp], 0

; 726  : 			} else

	jmp	SHORT $L66261
$L66259:

; 727  : 				fv = -fv, sign = -1;

	fld	DWORD PTR _fv$66255[ebp]
	fchs
	fstp	DWORD PTR _fv$66255[ebp]
	mov	DWORD PTR _sign$66256[ebp], -1
$L66261:

; 729  : 		den = 1L;

	mov	DWORD PTR _den$66257[ebp], 1

; 730  : 		if (fv > 0) {

	fld	DWORD PTR _fv$66255[ebp]
	fcomp	DWORD PTR __real@4@00000000000000000000
	fnstsw	ax
	test	ah, 65					; 00000041H
	jne	SHORT $L66265
$L66264:

; 731  : 			while (fv < 1L<<(31-3) && den < 1L<<(31-3))

	fld	DWORD PTR _fv$66255[ebp]
	fcomp	DWORD PTR __real@4@401b8000000000000000
	fnstsw	ax
	test	ah, 1
	je	SHORT $L66265
	cmp	DWORD PTR _den$66257[ebp], 268435456	; 10000000H
	jae	SHORT $L66265

; 732  : 				fv *= 1<<3, den *= 1L<<3;

	fld	DWORD PTR _fv$66255[ebp]
	fmul	DWORD PTR __real@4@40028000000000000000
	fstp	DWORD PTR _fv$66255[ebp]
	mov	edx, DWORD PTR _den$66257[ebp]
	shl	edx, 3
	mov	DWORD PTR _den$66257[ebp], edx
	jmp	SHORT $L66264
$L66265:

; 734  : 		t[2*i+0] = (uint32) (sign * (fv + 0.5));

	fild	DWORD PTR _sign$66256[ebp]
	fld	DWORD PTR _fv$66255[ebp]
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	fmulp	ST(1), ST(0)
	call	__ftol
	mov	ecx, DWORD PTR _i$[ebp]
	shl	ecx, 1
	mov	edx, DWORD PTR _t$[ebp]
	mov	DWORD PTR [edx+ecx*4], eax

; 735  : 		t[2*i+1] = den;

	mov	eax, DWORD PTR _i$[ebp]
	shl	eax, 1
	mov	ecx, DWORD PTR _t$[ebp]
	mov	edx, DWORD PTR _den$66257[ebp]
	mov	DWORD PTR [ecx+eax*4+4], edx

; 736  : 	}

	jmp	$L66253
$L66254:

; 737  : 	status = TIFFWriteData(tif, dir, (char *)t);

	mov	eax, DWORD PTR _t$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteData
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _status$[ebp], eax

; 738  : 	_TIFFfree((char*) t);

	mov	eax, DWORD PTR _t$[ebp]
	push	eax
	call	__TIFFfree
	add	esp, 4

; 739  : 	return (status);

	mov	eax, DWORD PTR _status$[ebp]

; 740  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFWriteRationalArray ENDP
_tif$ = 8
_type$ = 12
_tag$ = 16
_dir$ = 20
_n$ = 24
_v$ = 28
_TIFFWriteFloatArray PROC NEAR

; 745  : {

	push	ebp
	mov	ebp, esp

; 746  : 	dir->tdir_tag = (uint16) tag;

	mov	eax, DWORD PTR _dir$[ebp]
	mov	cx, WORD PTR _tag$[ebp]
	mov	WORD PTR [eax], cx

; 747  : 	dir->tdir_type = (short) type;

	mov	edx, DWORD PTR _dir$[ebp]
	mov	ax, WORD PTR _type$[ebp]
	mov	WORD PTR [edx+2], ax

; 748  : 	dir->tdir_count = n;

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR _n$[ebp]
	mov	DWORD PTR [ecx+4], edx

; 749  : 	TIFFCvtNativeToIEEEFloat(tif, n, v);
; 750  : 	if (n == 1) {

	cmp	DWORD PTR _n$[ebp], 1
	jne	SHORT $L66284

; 751  : 		dir->tdir_offset = *(uint32*) &v[0];

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR _v$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax+8], edx

; 752  : 		return (1);

	mov	eax, 1
	jmp	SHORT $L66286
$L66284:

; 754  : 		return (TIFFWriteData(tif, dir, (char*) v));

	mov	eax, DWORD PTR _v$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteData
	add	esp, 12					; 0000000cH
$L66286:

; 755  : }

	pop	ebp
	ret	0
_TIFFWriteFloatArray ENDP
_tif$ = 8
_type$ = 12
_tag$ = 16
_dir$ = 20
_n$ = 24
_v$ = 28
_TIFFWriteDoubleArray PROC NEAR

; 760  : {

	push	ebp
	mov	ebp, esp

; 761  : 	dir->tdir_tag = (uint16) tag;

	mov	eax, DWORD PTR _dir$[ebp]
	mov	cx, WORD PTR _tag$[ebp]
	mov	WORD PTR [eax], cx

; 762  : 	dir->tdir_type = (short) type;

	mov	edx, DWORD PTR _dir$[ebp]
	mov	ax, WORD PTR _type$[ebp]
	mov	WORD PTR [edx+2], ax

; 763  : 	dir->tdir_count = n;

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	edx, DWORD PTR _n$[ebp]
	mov	DWORD PTR [ecx+4], edx

; 764  : 	TIFFCvtNativeToIEEEDouble(tif, n, v);
; 765  : 	return (TIFFWriteData(tif, dir, (char*) v));

	mov	eax, DWORD PTR _v$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteData
	add	esp, 12					; 0000000cH

; 766  : }

	pop	ebp
	ret	0
_TIFFWriteDoubleArray ENDP
_TEXT	ENDS
EXTRN	_tiffDataWidth:BYTE
_TEXT	SEGMENT
_tif$ = 8
_type$ = 12
_tag$ = 16
_dir$ = 20
_n$ = 24
_v$ = 28
_buf$ = -80
_w$ = -84
_i$ = -88
_status$ = -92
_bp$66329 = -96
_bp$66342 = -100
_bp$66354 = -104
_bp$66364 = -108
_bp$66374 = -112
_bp$66383 = -116
_bp$66393 = -120
_TIFFWriteAnyArray PROC NEAR

; 780  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 124				; 0000007cH

; 781  : 	char buf[10 * sizeof(double)];
; 782  : 	char* w = buf;

	lea	eax, DWORD PTR _buf$[ebp]
	mov	DWORD PTR _w$[ebp], eax

; 783  : 	int i, status = 0;

	mov	DWORD PTR _status$[ebp], 0

; 784  : 
; 785  : 	if (n * tiffDataWidth[type] > sizeof buf)

	mov	ecx, DWORD PTR _type$[ebp]
	mov	edx, DWORD PTR _n$[ebp]
	imul	edx, DWORD PTR _tiffDataWidth[ecx*4]
	cmp	edx, 80					; 00000050H
	jbe	SHORT $L66322

; 786  : 		w = (char*) _TIFFmalloc(n * tiffDataWidth[type]);

	mov	eax, DWORD PTR _type$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	imul	ecx, DWORD PTR _tiffDataWidth[eax*4]
	push	ecx
	call	__TIFFmalloc
	add	esp, 4
	mov	DWORD PTR _w$[ebp], eax
$L66322:

; 787  : 	switch (type) {

	mov	edx, DWORD PTR _type$[ebp]
	mov	DWORD PTR -124+[ebp], edx
	mov	eax, DWORD PTR -124+[ebp]
	sub	eax, 1
	mov	DWORD PTR -124+[ebp], eax
	cmp	DWORD PTR -124+[ebp], 11		; 0000000bH
	ja	$L66402
	mov	ecx, DWORD PTR -124+[ebp]
	jmp	DWORD PTR $L66607[ecx*4]
$L66328:

; 788  : 	case TIFF_BYTE:
; 789  : 		{ uint8* bp = (uint8*) w;

	mov	edx, DWORD PTR _w$[ebp]
	mov	DWORD PTR _bp$66329[ebp], edx

; 790  : 		  for (i = 0; i < (int) n; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L66332
$L66333:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L66332:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _n$[ebp]
	jge	SHORT $L66334

; 791  : 			bp[i] = (uint8) v[i];

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _v$[ebp]
	fld	QWORD PTR [eax+edx*8]
	call	__ftol
	mov	ecx, DWORD PTR _bp$66329[ebp]
	add	ecx, DWORD PTR _i$[ebp]
	mov	BYTE PTR [ecx], al
	jmp	SHORT $L66333
$L66334:

; 792  : 		  dir->tdir_tag = (uint16) tag;

	mov	edx, DWORD PTR _dir$[ebp]
	mov	ax, WORD PTR _tag$[ebp]
	mov	WORD PTR [edx], ax

; 793  : 		  dir->tdir_type = (short) type;

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	dx, WORD PTR _type$[ebp]
	mov	WORD PTR [ecx+2], dx

; 794  : 		  dir->tdir_count = n;

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	mov	DWORD PTR [eax+4], ecx

; 795  : 		  if (!TIFFWriteByteArray(tif, dir, (char*) bp))

	mov	edx, DWORD PTR _bp$66329[ebp]
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFWriteByteArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66339

; 796  : 			goto out;

	jmp	$out$66340
$L66339:

; 798  : 		break;

	jmp	$L66325
$L66341:

; 799  : 	case TIFF_SBYTE:
; 800  : 		{ int8* bp = (int8*) w;

	mov	edx, DWORD PTR _w$[ebp]
	mov	DWORD PTR _bp$66342[ebp], edx

; 801  : 		  for (i = 0; i < (int) n; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L66345
$L66346:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L66345:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _n$[ebp]
	jge	SHORT $L66347

; 802  : 			bp[i] = (int8) v[i];

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _v$[ebp]
	fld	QWORD PTR [eax+edx*8]
	call	__ftol
	mov	ecx, DWORD PTR _bp$66342[ebp]
	add	ecx, DWORD PTR _i$[ebp]
	mov	BYTE PTR [ecx], al
	jmp	SHORT $L66346
$L66347:

; 803  : 		  dir->tdir_tag = (uint16) tag;

	mov	edx, DWORD PTR _dir$[ebp]
	mov	ax, WORD PTR _tag$[ebp]
	mov	WORD PTR [edx], ax

; 804  : 		  dir->tdir_type = (short) type;

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	dx, WORD PTR _type$[ebp]
	mov	WORD PTR [ecx+2], dx

; 805  : 		  dir->tdir_count = n;

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	mov	DWORD PTR [eax+4], ecx

; 806  : 		  if (!TIFFWriteByteArray(tif, dir, (char*) bp))

	mov	edx, DWORD PTR _bp$66342[ebp]
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFWriteByteArray
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66352

; 807  : 			goto out;

	jmp	$out$66340
$L66352:

; 809  : 		break;

	jmp	$L66325
$L66353:

; 810  : 	case TIFF_SHORT:
; 811  : 		{ uint16* bp = (uint16*) w;

	mov	edx, DWORD PTR _w$[ebp]
	mov	DWORD PTR _bp$66354[ebp], edx

; 812  : 		  for (i = 0; i < (int) n; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L66357
$L66358:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L66357:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _n$[ebp]
	jge	SHORT $L66359

; 813  : 			bp[i] = (uint16) v[i];

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _v$[ebp]
	fld	QWORD PTR [eax+edx*8]
	call	__ftol
	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _bp$66354[ebp]
	mov	WORD PTR [edx+ecx*2], ax
	jmp	SHORT $L66358
$L66359:

; 814  : 		  if (!TIFFWriteShortArray(tif, type, tag, dir, n, (uint16*)bp))

	mov	eax, DWORD PTR _bp$66354[ebp]
	push	eax
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	mov	ecx, DWORD PTR _type$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteShortArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L66362

; 815  : 				goto out;

	jmp	$out$66340
$L66362:

; 817  : 		break;

	jmp	$L66325
$L66363:

; 818  : 	case TIFF_SSHORT:
; 819  : 		{ int16* bp = (int16*) w;

	mov	eax, DWORD PTR _w$[ebp]
	mov	DWORD PTR _bp$66364[ebp], eax

; 820  : 		  for (i = 0; i < (int) n; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L66367
$L66368:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L66367:
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR _n$[ebp]
	jge	SHORT $L66369

; 821  : 			bp[i] = (int16) v[i];

	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _v$[ebp]
	fld	QWORD PTR [ecx+eax*8]
	call	__ftol
	mov	edx, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _bp$66364[ebp]
	mov	WORD PTR [ecx+edx*2], ax
	jmp	SHORT $L66368
$L66369:

; 822  : 		  if (!TIFFWriteShortArray(tif, type, tag, dir, n, (uint16*)bp))

	mov	edx, DWORD PTR _bp$66364[ebp]
	push	edx
	mov	eax, DWORD PTR _n$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tag$[ebp]
	push	edx
	mov	eax, DWORD PTR _type$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFWriteShortArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L66372

; 823  : 			goto out;

	jmp	$out$66340
$L66372:

; 825  : 		break;

	jmp	$L66325
$L66373:

; 826  : 	case TIFF_LONG:
; 827  : 		{ uint32* bp = (uint32*) w;

	mov	edx, DWORD PTR _w$[ebp]
	mov	DWORD PTR _bp$66374[ebp], edx

; 828  : 		  for (i = 0; i < (int) n; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L66377
$L66378:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L66377:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _n$[ebp]
	jge	SHORT $L66379

; 829  : 			bp[i] = (uint32) v[i];

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _v$[ebp]
	fld	QWORD PTR [eax+edx*8]
	call	__ftol
	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _bp$66374[ebp]
	mov	DWORD PTR [edx+ecx*4], eax
	jmp	SHORT $L66378
$L66379:

; 830  : 		  if (!TIFFWriteLongArray(tif, type, tag, dir, n, bp))

	mov	eax, DWORD PTR _bp$66374[ebp]
	push	eax
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	mov	ecx, DWORD PTR _type$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteLongArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L66381

; 831  : 			goto out;

	jmp	$out$66340
$L66381:

; 833  : 		break;

	jmp	$L66325
$L66382:

; 834  : 	case TIFF_SLONG:
; 835  : 		{ int32* bp = (int32*) w;

	mov	eax, DWORD PTR _w$[ebp]
	mov	DWORD PTR _bp$66383[ebp], eax

; 836  : 		  for (i = 0; i < (int) n; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L66386
$L66387:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L66386:
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR _n$[ebp]
	jge	SHORT $L66388

; 837  : 			bp[i] = (int32) v[i];

	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _v$[ebp]
	fld	QWORD PTR [ecx+eax*8]
	call	__ftol
	mov	edx, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _bp$66383[ebp]
	mov	DWORD PTR [ecx+edx*4], eax
	jmp	SHORT $L66387
$L66388:

; 838  : 		  if (!TIFFWriteLongArray(tif, type, tag, dir, n, (uint32*) bp))

	mov	edx, DWORD PTR _bp$66383[ebp]
	push	edx
	mov	eax, DWORD PTR _n$[ebp]
	push	eax
	mov	ecx, DWORD PTR _dir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tag$[ebp]
	push	edx
	mov	eax, DWORD PTR _type$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFWriteLongArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L66391

; 839  : 			goto out;

	jmp	$out$66340
$L66391:

; 841  : 		break;

	jmp	$L66325
$L66392:

; 842  : 	case TIFF_FLOAT:
; 843  : 		{ float* bp = (float*) w;

	mov	edx, DWORD PTR _w$[ebp]
	mov	DWORD PTR _bp$66393[ebp], edx

; 844  : 		  for (i = 0; i < (int) n; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L66396
$L66397:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L66396:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _n$[ebp]
	jge	SHORT $L66398

; 845  : 			bp[i] = (float) v[i];

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _v$[ebp]
	fld	QWORD PTR [eax+edx*8]
	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _bp$66393[ebp]
	fstp	DWORD PTR [edx+ecx*4]
	jmp	SHORT $L66397
$L66398:

; 846  : 		  if (!TIFFWriteFloatArray(tif, type, tag, dir, n, bp))

	mov	eax, DWORD PTR _bp$66393[ebp]
	push	eax
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	mov	ecx, DWORD PTR _type$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteFloatArray
	add	esp, 24					; 00000018H
	test	eax, eax
	jne	SHORT $L66400

; 847  : 			goto out;

	jmp	SHORT $out$66340
$L66400:

; 849  : 		break;

	jmp	SHORT $L66325
$L66401:

; 850  : 	case TIFF_DOUBLE:
; 851  : 		return (TIFFWriteDoubleArray(tif, type, tag, dir, n, v));

	mov	eax, DWORD PTR _v$[ebp]
	push	eax
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	mov	ecx, DWORD PTR _type$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteDoubleArray
	add	esp, 24					; 00000018H
	jmp	SHORT $L66316
$L66402:

; 852  : 	default:
; 853  : 		/* TIFF_NOTYPE */
; 854  : 		/* TIFF_ASCII */
; 855  : 		/* TIFF_UNDEFINED */
; 856  : 		/* TIFF_RATIONAL */
; 857  : 		/* TIFF_SRATIONAL */
; 858  : 		goto out;

	jmp	SHORT $out$66340
$L66325:

; 860  : 	status = 1;

	mov	DWORD PTR _status$[ebp], 1
$out$66340:

; 861  :  out:
; 862  : 	if (w != buf)

	mov	eax, DWORD PTR _w$[ebp]
	lea	ecx, DWORD PTR _buf$[ebp]
	cmp	eax, ecx
	je	SHORT $L66403

; 863  : 		_TIFFfree(w);

	mov	edx, DWORD PTR _w$[ebp]
	push	edx
	call	__TIFFfree
	add	esp, 4
$L66403:

; 864  : 	return (status);

	mov	eax, DWORD PTR _status$[ebp]
$L66316:

; 865  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L66607:
	DD	$L66328
	DD	$L66402
	DD	$L66353
	DD	$L66373
	DD	$L66402
	DD	$L66341
	DD	$L66402
	DD	$L66363
	DD	$L66382
	DD	$L66402
	DD	$L66392
	DD	$L66401
_TIFFWriteAnyArray ENDP
_TEXT	ENDS
EXTRN	__TIFFmemcmp:NEAR
_TEXT	SEGMENT
_tif$ = 8
_dir$ = 12
_td$ = -4
_n$ = -16
_tf$ = -12
_ncols$ = -8
_TIFFWriteTransferFunction PROC NEAR

; 870  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 20					; 00000014H

; 871  : 	TIFFDirectory* td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 872  : 	tsize_t n = (1L<<td->td_bitspersample) * sizeof (uint16);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+40]
	mov	ecx, edx
	mov	eax, 1
	shl	eax, cl
	shl	eax, 1
	mov	DWORD PTR _n$[ebp], eax

; 873  : 	uint16** tf = td->td_transferfunction;

	mov	ecx, DWORD PTR _td$[ebp]
	add	ecx, 224				; 000000e0H
	mov	DWORD PTR _tf$[ebp], ecx

; 874  : 	int ncols;
; 875  : 
; 876  : 	/*
; 877  : 	 * Check if the table can be written as a single column,
; 878  : 	 * or if it must be written as 3 columns.  Note that we
; 879  : 	 * write a 3-column tag if there are 2 samples/pixel and
; 880  : 	 * a single column of data won't suffice--hmm.
; 881  : 	 */
; 882  : 	switch (td->td_samplesperpixel - td->td_extrasamples) {

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+54]
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+120]
	sub	eax, edx
	mov	DWORD PTR -20+[ebp], eax
	cmp	DWORD PTR -20+[ebp], 0
	jl	SHORT $L66418
	cmp	DWORD PTR -20+[ebp], 1
	jle	SHORT $L66421
	cmp	DWORD PTR -20+[ebp], 2
	je	SHORT $L66419
$L66418:

; 883  : 	default:	if (_TIFFmemcmp(tf[0], tf[2], n)) { ncols = 3; break; }

	mov	eax, DWORD PTR _n$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tf$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	push	edx
	mov	eax, DWORD PTR _tf$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	__TIFFmemcmp
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L66419
	mov	DWORD PTR _ncols$[ebp], 3
	jmp	SHORT $L66415
$L66419:

; 884  : 	case 2:		if (_TIFFmemcmp(tf[0], tf[1], n)) { ncols = 3; break; }

	mov	edx, DWORD PTR _n$[ebp]
	push	edx
	mov	eax, DWORD PTR _tf$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR _tf$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	__TIFFmemcmp
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L66421
	mov	DWORD PTR _ncols$[ebp], 3
	jmp	SHORT $L66415
$L66421:

; 885  : 	case 1: case 0:	ncols = 1;

	mov	DWORD PTR _ncols$[ebp], 1
$L66415:

; 887  : 	return (TIFFWriteShortTable(tif,
; 888  : 	    TIFFTAG_TRANSFERFUNCTION, dir, ncols, tf));

	mov	ecx, DWORD PTR _tf$[ebp]
	push	ecx
	mov	edx, DWORD PTR _ncols$[ebp]
	push	edx
	mov	eax, DWORD PTR _dir$[ebp]
	push	eax
	push	301					; 0000012dH
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFWriteShortTable
	add	esp, 20					; 00000014H

; 889  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFWriteTransferFunction ENDP
_tif$ = 8
_dir$ = 12
_td$ = -4
_TIFFWriteInkNames PROC NEAR

; 895  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 896  : 	TIFFDirectory* td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 897  : 
; 898  : 	dir->tdir_tag = TIFFTAG_INKNAMES;

	mov	ecx, DWORD PTR _dir$[ebp]
	mov	WORD PTR [ecx], 333			; 0000014dH

; 899  : 	dir->tdir_type = (short) TIFF_ASCII;

	mov	edx, DWORD PTR _dir$[ebp]
	mov	WORD PTR [edx+2], 2

; 900  : 	dir->tdir_count = td->td_inknameslen;

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+244]
	mov	DWORD PTR [eax+4], edx

; 901  : 	return (TIFFWriteByteArray(tif, dir, td->td_inknames));

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+248]
	push	ecx
	mov	edx, DWORD PTR _dir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFWriteByteArray
	add	esp, 12					; 0000000cH

; 902  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFWriteInkNames ENDP
_TEXT	ENDS
EXTRN	_TIFFSwabArrayOfDouble:NEAR
_DATA	SEGMENT
	ORG $+3
$SG66458 DB	'Error writing data for field "%s"', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_dir$ = 12
_cp$ = 16
_cc$ = -4
_TIFFWriteData PROC NEAR

; 910  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 911  : 	tsize_t cc;
; 912  : 
; 913  : 	if (tif->tif_flags & TIFF_SWAB) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 128				; 00000080H
	test	ecx, ecx
	je	SHORT $L66440

; 914  : 		switch (dir->tdir_type) {

	mov	edx, DWORD PTR _dir$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+2]
	mov	DWORD PTR -8+[ebp], eax
	mov	ecx, DWORD PTR -8+[ebp]
	sub	ecx, 3
	mov	DWORD PTR -8+[ebp], ecx
	cmp	DWORD PTR -8+[ebp], 9
	ja	SHORT $L66440
	mov	edx, DWORD PTR -8+[ebp]
	jmp	DWORD PTR $L66611[edx*4]
$L66443:

; 915  : 		case TIFF_SHORT:
; 916  : 		case TIFF_SSHORT:
; 917  : 			TIFFSwabArrayOfShort((uint16*) cp, dir->tdir_count);

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR _cp$[ebp]
	push	edx
	call	_TIFFSwabArrayOfShort
	add	esp, 8

; 918  : 			break;

	jmp	SHORT $L66440
$L66445:

; 919  : 		case TIFF_LONG:
; 920  : 		case TIFF_SLONG:
; 921  : 		case TIFF_FLOAT:
; 922  : 			TIFFSwabArrayOfLong((uint32*) cp, dir->tdir_count);

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR _cp$[ebp]
	push	edx
	call	_TIFFSwabArrayOfLong
	add	esp, 8

; 923  : 			break;

	jmp	SHORT $L66440
$L66447:

; 924  : 		case TIFF_RATIONAL:
; 925  : 		case TIFF_SRATIONAL:
; 926  : 			TIFFSwabArrayOfLong((uint32*) cp, 2*dir->tdir_count);

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	shl	ecx, 1
	push	ecx
	mov	edx, DWORD PTR _cp$[ebp]
	push	edx
	call	_TIFFSwabArrayOfLong
	add	esp, 8

; 927  : 			break;

	jmp	SHORT $L66440
$L66449:

; 928  : 		case TIFF_DOUBLE:
; 929  : 			TIFFSwabArrayOfDouble((double*) cp, dir->tdir_count);

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR _cp$[ebp]
	push	edx
	call	_TIFFSwabArrayOfDouble
	add	esp, 8
$L66440:

; 933  : 	dir->tdir_offset = tif->tif_dataoff;

	mov	eax, DWORD PTR _dir$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+372]
	mov	DWORD PTR [eax+8], edx

; 934  : 	cc = dir->tdir_count * tiffDataWidth[dir->tdir_type];

	mov	eax, DWORD PTR _dir$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+2]
	mov	edx, DWORD PTR _dir$[ebp]
	mov	eax, DWORD PTR [edx+4]
	imul	eax, DWORD PTR _tiffDataWidth[ecx*4]
	mov	DWORD PTR _cc$[ebp], eax

; 935  : 	if (SeekOK(tif, dir->tdir_offset) &&
; 936  : 	    WriteOK(tif, cp, cc)) {

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
	jne	SHORT $L66457
	mov	edx, DWORD PTR _cc$[ebp]
	push	edx
	mov	eax, DWORD PTR _cp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+512]
	add	esp, 12					; 0000000cH
	cmp	eax, DWORD PTR _cc$[ebp]
	jne	SHORT $L66457

; 937  : 		tif->tif_dataoff += (cc + 1) & ~1;

	mov	ecx, DWORD PTR _cc$[ebp]
	add	ecx, 1
	and	ecx, -2					; fffffffeH
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+372]
	add	eax, ecx
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+372], eax

; 938  : 		return (1);

	mov	eax, 1
	jmp	SHORT $L66436
$L66457:

; 940  : 	TIFFError(tif->tif_name, "Error writing data for field \"%s\"",
; 941  : 	    _TIFFFieldWithTag(tif, dir->tdir_tag)->field_name);

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
	push	OFFSET FLAT:$SG66458
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 942  : 	return (0);

	xor	eax, eax
$L66436:

; 943  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L66611:
	DD	$L66443
	DD	$L66445
	DD	$L66447
	DD	$L66440
	DD	$L66440
	DD	$L66443
	DD	$L66445
	DD	$L66447
	DD	$L66445
	DD	$L66449
_TIFFWriteData ENDP
_TEXT	ENDS
PUBLIC	_TIFFRewriteDirectory
_DATA	SEGMENT
	ORG $+2
$SG66474 DB	'Error updating TIFF header', 00H
	ORG $+1
$SG66490 DB	'Error fetching directory count', 00H
	ORG $+1
$SG66499 DB	'Error fetching directory link', 00H
	ORG $+2
$SG66510 DB	'Error writing directory link', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_nextdir$66476 = -4
_off$66477 = -8
_dircount$66481 = -12
_TIFFRewriteDirectory PROC NEAR

; 954  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 955  :     static const char module[] = "TIFFRewriteDirectory";
; 956  : 
; 957  :     /* We don't need to do anything special if it hasn't been written. */
; 958  :     if( tif->tif_diroff == 0 )

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+16], 0
	jne	SHORT $L66464

; 959  :         return TIFFWriteDirectory( tif );

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFWriteDirectory
	add	esp, 4
	jmp	$L66461
$L66464:

; 960  : 
; 961  :     /*
; 962  :     ** Find and zero the pointer to this directory, so that TIFFLinkDirectory
; 963  :     ** will cause it to be added after this directories current pre-link.
; 964  :     */
; 965  :     
; 966  :     /* Is it the first directory in the file? */
; 967  :     if (tif->tif_header.tiff_diroff == tif->tif_diroff) 

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [edx+340]
	cmp	ecx, DWORD PTR [eax+16]
	jne	SHORT $L66465

; 969  :         tif->tif_header.tiff_diroff = 0;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+340], 0

; 970  :         tif->tif_diroff = 0;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+16], 0

; 971  : 
; 972  : #define	HDROFF(f)	((toff_t) &(((TIFFHeader*) 0)->f))
; 973  :         TIFFSeekFile(tif, HDROFF(tiff_diroff), SEEK_SET);

	push	0
	push	4
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+516]
	add	esp, 12					; 0000000cH

; 974  :         if (!WriteOK(tif, &(tif->tif_header.tiff_diroff), 
; 975  :                      sizeof (tif->tif_diroff))) 

	push	4
	mov	ecx, DWORD PTR _tif$[ebp]
	add	ecx, 340				; 00000154H
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+504]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+512]
	add	esp, 12					; 0000000cH
	cmp	eax, 4
	je	SHORT $L66473

; 977  :             TIFFError(tif->tif_name, "Error updating TIFF header");

	push	OFFSET FLAT:$SG66474
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 8

; 978  :             return (0);

	xor	eax, eax
	jmp	$L66461
$L66473:

; 981  :     else

	jmp	$L66509
$L66465:

; 983  :         toff_t  nextdir, off;
; 984  : 
; 985  : 	nextdir = tif->tif_header.tiff_diroff;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+340]
	mov	DWORD PTR _nextdir$66476[ebp], edx
$L66478:

; 987  : 		uint16 dircount;
; 988  : 
; 989  : 		if (!SeekOK(tif, nextdir) ||
; 990  : 		    !ReadOK(tif, &dircount, sizeof (dircount))) {

	push	0
	mov	eax, DWORD PTR _nextdir$66476[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+516]
	add	esp, 12					; 0000000cH
	cmp	eax, DWORD PTR _nextdir$66476[ebp]
	jne	SHORT $L66489
	push	2
	lea	ecx, DWORD PTR _dircount$66481[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+504]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+508]
	add	esp, 12					; 0000000cH
	cmp	eax, 2
	je	SHORT $L66488
$L66489:

; 991  : 			TIFFError(module, "Error fetching directory count");

	push	OFFSET FLAT:$SG66490
	push	OFFSET FLAT:_?module@?1??TIFFRewriteDirectory@@9@9
	call	_TIFFError
	add	esp, 8

; 992  : 			return (0);

	xor	eax, eax
	jmp	$L66461
$L66488:

; 994  : 		if (tif->tif_flags & TIFF_SWAB)

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 128				; 00000080H
	test	eax, eax
	je	SHORT $L66491

; 995  : 			TIFFSwabShort(&dircount);

	lea	ecx, DWORD PTR _dircount$66481[ebp]
	push	ecx
	call	_TIFFSwabShort
	add	esp, 4
$L66491:

; 996  : 		(void) TIFFSeekFile(tif,
; 997  : 		    dircount * sizeof (TIFFDirEntry), SEEK_CUR);

	push	1
	mov	edx, DWORD PTR _dircount$66481[ebp]
	and	edx, 65535				; 0000ffffH
	imul	edx, 12					; 0000000cH
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+516]
	add	esp, 12					; 0000000cH

; 998  : 		if (!ReadOK(tif, &nextdir, sizeof (nextdir))) {

	push	4
	lea	eax, DWORD PTR _nextdir$66476[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+508]
	add	esp, 12					; 0000000cH
	cmp	eax, 4
	je	SHORT $L66498

; 999  : 			TIFFError(module, "Error fetching directory link");

	push	OFFSET FLAT:$SG66499
	push	OFFSET FLAT:_?module@?1??TIFFRewriteDirectory@@9@9
	call	_TIFFError
	add	esp, 8

; 1000 : 			return (0);

	xor	eax, eax
	jmp	$L66461
$L66498:

; 1002 : 		if (tif->tif_flags & TIFF_SWAB)

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 128				; 00000080H
	test	edx, edx
	je	SHORT $L66500

; 1003 : 			TIFFSwabLong(&nextdir);

	lea	eax, DWORD PTR _nextdir$66476[ebp]
	push	eax
	call	_TIFFSwabLong
	add	esp, 4
$L66500:

; 1004 : 	} while (nextdir != tif->tif_diroff && nextdir != 0);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _nextdir$66476[ebp]
	cmp	edx, DWORD PTR [ecx+16]
	je	SHORT $L66501
	cmp	DWORD PTR _nextdir$66476[ebp], 0
	jne	$L66478
$L66501:

; 1005 :         off = TIFFSeekFile(tif, 0, SEEK_CUR); /* get current offset */

	push	1
	push	0
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+516]
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _off$66477[ebp], eax

; 1006 :         (void) TIFFSeekFile(tif, off - (toff_t)sizeof(nextdir), SEEK_SET);

	push	0
	mov	eax, DWORD PTR _off$66477[ebp]
	sub	eax, 4
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+516]
	add	esp, 12					; 0000000cH

; 1007 :         tif->tif_diroff = 0;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+16], 0

; 1008 : 	if (!WriteOK(tif, &(tif->tif_diroff), sizeof (nextdir))) {

	push	4
	mov	edx, DWORD PTR _tif$[ebp]
	add	edx, 16					; 00000010H
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+512]
	add	esp, 12					; 0000000cH
	cmp	eax, 4
	je	SHORT $L66509

; 1009 : 		TIFFError(module, "Error writing directory link");

	push	OFFSET FLAT:$SG66510
	push	OFFSET FLAT:_?module@?1??TIFFRewriteDirectory@@9@9
	call	_TIFFError
	add	esp, 8

; 1010 : 		return (0);

	xor	eax, eax
	jmp	SHORT $L66461
$L66509:

; 1013 : 
; 1014 :     /*
; 1015 :     ** Now use TIFFWriteDirectory() normally.
; 1016 :     */
; 1017 : 
; 1018 :     return TIFFWriteDirectory( tif );

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFWriteDirectory
	add	esp, 4
$L66461:

; 1019 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFRewriteDirectory ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+3
$SG66529 DB	'%s: Error writing SubIFD directory link', 00H
$SG66541 DB	'Error writing TIFF header', 00H
	ORG $+2
$SG66554 DB	'Error fetching directory count', 00H
	ORG $+1
$SG66563 DB	'Error fetching directory link', 00H
	ORG $+2
$SG66573 DB	'Error writing directory link', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_nextdir$ = -4
_diroff$ = -12
_off$ = -8
_dircount$66545 = -16
_TIFFLinkDirectory PROC NEAR

; 1028 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 1029 : 	static const char module[] = "TIFFLinkDirectory";
; 1030 : 	toff_t nextdir;
; 1031 : 	toff_t diroff, off;
; 1032 : 
; 1033 : 	tif->tif_diroff = (TIFFSeekFile(tif, (toff_t) 0, SEEK_END)+1) &~ 1;

	push	2
	push	0
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+516]
	add	esp, 12					; 0000000cH
	add	eax, 1
	and	al, -2					; fffffffeH
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+16], eax

; 1034 : 	diroff = tif->tif_diroff;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+16]
	mov	DWORD PTR _diroff$[ebp], eax

; 1035 : 	if (tif->tif_flags & TIFF_SWAB)

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 128				; 00000080H
	test	edx, edx
	je	SHORT $L66521

; 1036 : 		TIFFSwabLong(&diroff);

	lea	eax, DWORD PTR _diroff$[ebp]
	push	eax
	call	_TIFFSwabLong
	add	esp, 4
$L66521:

; 1037 : #if SUBIFD_SUPPORT
; 1038 : 	if (tif->tif_flags & TIFF_INSUBIFD) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 8192				; 00002000H
	test	edx, edx
	je	$L66522

; 1039 : 		(void) TIFFSeekFile(tif, tif->tif_subifdoff, SEEK_SET);

	push	0
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+380]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+504]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+516]
	add	esp, 12					; 0000000cH

; 1040 : 		if (!WriteOK(tif, &diroff, sizeof (diroff))) {

	push	4
	lea	edx, DWORD PTR _diroff$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+512]
	add	esp, 12					; 0000000cH
	cmp	eax, 4
	je	SHORT $L66528

; 1041 : 			TIFFError(module,
; 1042 : 			    "%s: Error writing SubIFD directory link",
; 1043 : 			    tif->tif_name);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG66529
	push	OFFSET FLAT:_?module@?1??TIFFLinkDirectory@@9@9
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 1044 : 			return (0);

	xor	eax, eax
	jmp	$L66513
$L66528:

; 1046 : 		/*
; 1047 : 		 * Advance to the next SubIFD or, if this is
; 1048 : 		 * the last one configured, revert back to the
; 1049 : 		 * normal directory linkage.
; 1050 : 		 */
; 1051 : 		if (--tif->tif_nsubifd)

	mov	edx, DWORD PTR _tif$[ebp]
	mov	ax, WORD PTR [edx+376]
	sub	ax, 1
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	WORD PTR [ecx+376], ax
	mov	edx, DWORD PTR _tif$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+376]
	test	eax, eax
	je	SHORT $L66530

; 1052 : 			tif->tif_subifdoff += sizeof (diroff);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+380]
	add	edx, 4
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+380], edx

; 1053 : 		else

	jmp	SHORT $L66531
$L66530:

; 1054 : 			tif->tif_flags &= ~TIFF_INSUBIFD;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	dh, -33					; ffffffdfH
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+12], edx
$L66531:

; 1055 : 		return (1);

	mov	eax, 1
	jmp	$L66513
$L66522:

; 1057 : #endif
; 1058 : 	if (tif->tif_header.tiff_diroff == 0) {

	mov	ecx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [ecx+340], 0
	jne	SHORT $L66532

; 1059 : 		/*
; 1060 : 		 * First directory, overwrite offset in header.
; 1061 : 		 */
; 1062 : 		tif->tif_header.tiff_diroff = tif->tif_diroff;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	mov	DWORD PTR [edx+340], ecx

; 1063 : #define	HDROFF(f)	((toff_t) &(((TIFFHeader*) 0)->f))
; 1064 : 		(void) TIFFSeekFile(tif, HDROFF(tiff_diroff), SEEK_SET);

	push	0
	push	4
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+504]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+516]
	add	esp, 12					; 0000000cH

; 1065 : 		if (!WriteOK(tif, &diroff, sizeof (diroff))) {

	push	4
	lea	edx, DWORD PTR _diroff$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+512]
	add	esp, 12					; 0000000cH
	cmp	eax, 4
	je	SHORT $L66540

; 1066 : 			TIFFError(tif->tif_name, "Error writing TIFF header");

	push	OFFSET FLAT:$SG66541
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 8

; 1067 : 			return (0);

	xor	eax, eax
	jmp	$L66513
$L66540:

; 1069 : 		return (1);

	mov	eax, 1
	jmp	$L66513
$L66532:

; 1071 : 	/*
; 1072 : 	 * Not the first directory, search to the last and append.
; 1073 : 	 */
; 1074 : 	nextdir = tif->tif_header.tiff_diroff;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+340]
	mov	DWORD PTR _nextdir$[ebp], eax
$L66542:

; 1076 : 		uint16 dircount;
; 1077 : 
; 1078 : 		if (!SeekOK(tif, nextdir) ||
; 1079 : 		    !ReadOK(tif, &dircount, sizeof (dircount))) {

	push	0
	mov	ecx, DWORD PTR _nextdir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+504]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+516]
	add	esp, 12					; 0000000cH
	cmp	eax, DWORD PTR _nextdir$[ebp]
	jne	SHORT $L66553
	push	2
	lea	edx, DWORD PTR _dircount$66545[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+508]
	add	esp, 12					; 0000000cH
	cmp	eax, 2
	je	SHORT $L66552
$L66553:

; 1080 : 			TIFFError(module, "Error fetching directory count");

	push	OFFSET FLAT:$SG66554
	push	OFFSET FLAT:_?module@?1??TIFFLinkDirectory@@9@9
	call	_TIFFError
	add	esp, 8

; 1081 : 			return (0);

	xor	eax, eax
	jmp	$L66513
$L66552:

; 1083 : 		if (tif->tif_flags & TIFF_SWAB)

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 128				; 00000080H
	test	ecx, ecx
	je	SHORT $L66555

; 1084 : 			TIFFSwabShort(&dircount);

	lea	edx, DWORD PTR _dircount$66545[ebp]
	push	edx
	call	_TIFFSwabShort
	add	esp, 4
$L66555:

; 1085 : 		(void) TIFFSeekFile(tif,
; 1086 : 		    dircount * sizeof (TIFFDirEntry), SEEK_CUR);

	push	1
	mov	eax, DWORD PTR _dircount$66545[ebp]
	and	eax, 65535				; 0000ffffH
	imul	eax, 12					; 0000000cH
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+516]
	add	esp, 12					; 0000000cH

; 1087 : 		if (!ReadOK(tif, &nextdir, sizeof (nextdir))) {

	push	4
	lea	ecx, DWORD PTR _nextdir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+504]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+508]
	add	esp, 12					; 0000000cH
	cmp	eax, 4
	je	SHORT $L66562

; 1088 : 			TIFFError(module, "Error fetching directory link");

	push	OFFSET FLAT:$SG66563
	push	OFFSET FLAT:_?module@?1??TIFFLinkDirectory@@9@9
	call	_TIFFError
	add	esp, 8

; 1089 : 			return (0);

	xor	eax, eax
	jmp	$L66513
$L66562:

; 1091 : 		if (tif->tif_flags & TIFF_SWAB)

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 128				; 00000080H
	test	eax, eax
	je	SHORT $L66564

; 1092 : 			TIFFSwabLong(&nextdir);

	lea	ecx, DWORD PTR _nextdir$[ebp]
	push	ecx
	call	_TIFFSwabLong
	add	esp, 4
$L66564:

; 1093 : 	} while (nextdir != 0);

	cmp	DWORD PTR _nextdir$[ebp], 0
	jne	$L66542

; 1094 :         off = TIFFSeekFile(tif, 0, SEEK_CUR); /* get current offset */

	push	1
	push	0
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+504]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+516]
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _off$[ebp], eax

; 1095 :         (void) TIFFSeekFile(tif, off - (toff_t)sizeof(nextdir), SEEK_SET);

	push	0
	mov	edx, DWORD PTR _off$[ebp]
	sub	edx, 4
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+516]
	add	esp, 12					; 0000000cH

; 1096 : 	if (!WriteOK(tif, &diroff, sizeof (diroff))) {

	push	4
	lea	eax, DWORD PTR _diroff$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+512]
	add	esp, 12					; 0000000cH
	cmp	eax, 4
	je	SHORT $L66572

; 1097 : 		TIFFError(module, "Error writing directory link");

	push	OFFSET FLAT:$SG66573
	push	OFFSET FLAT:_?module@?1??TIFFLinkDirectory@@9@9
	call	_TIFFError
	add	esp, 8

; 1098 : 		return (0);

	xor	eax, eax
	jmp	SHORT $L66513
$L66572:

; 1100 : 	return (1);

	mov	eax, 1
$L66513:

; 1101 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFLinkDirectory ENDP
_TEXT	ENDS
END
