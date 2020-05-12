	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_read.c
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
_?module@?1??TIFFReadRawStrip@@9@9 DB 'TIFFReadRawStrip', 00H
	ORG $+3
_?module@?1??TIFFFillStrip@@9@9 DB 'TIFFFillStrip', 00H
	ORG $+2
_?module@?1??TIFFReadRawTile@@9@9 DB 'TIFFReadRawTile', 00H
_?module@?1??TIFFFillTile@@9@9 DB 'TIFFFillTile', 00H
	ORG $+3
_?module@?1??TIFFReadBufferSetup@@9@9 DB 'TIFFReadBufferSetup', 00H
CONST	ENDS
PUBLIC	_TIFFReadScanline
_TEXT	SEGMENT
_tif$ = 8
_buf$ = 12
_row$ = 16
_sample$ = 20
_e$ = -4
_TIFFReadScanline PROC NEAR

; 96   : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 97   : 	int e;
; 98   : 
; 99   : 	if (!TIFFCheckRead(tif, 0))

	push	0
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFCheckRead
	add	esp, 8
	test	eax, eax
	jne	SHORT $L65843

; 100  : 		return (-1);

	or	eax, -1
	jmp	$L65841
$L65843:

; 101  : 	if( (e = TIFFSeek(tif, row, sample)) != 0) {

	mov	cx, WORD PTR _sample$[ebp]
	push	ecx
	mov	edx, DWORD PTR _row$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFSeek
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _e$[ebp], eax
	cmp	DWORD PTR _e$[ebp], 0
	je	SHORT $L65846

; 102  : 		/*
; 103  : 		 * Decompress desired row into user buffer.
; 104  : 		 */
; 105  : 		e = (*tif->tif_decoderow)
; 106  : 		    (tif, (tidata_t) buf, tif->tif_scanlinesize, sample);

	mov	cx, WORD PTR _sample$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+464]
	push	eax
	mov	ecx, DWORD PTR _buf$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+416]
	add	esp, 16					; 00000010H
	mov	DWORD PTR _e$[ebp], eax

; 107  : 		tif->tif_row++;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	add	edx, 1
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+356], edx

; 108  : 		if (e)

	cmp	DWORD PTR _e$[ebp], 0
	je	SHORT $L65846

; 109  : 			(*tif->tif_postdecode)(tif, (tidata_t) buf,
; 110  : 			    tif->tif_scanlinesize);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+464]
	push	edx
	mov	eax, DWORD PTR _buf$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+528]
	add	esp, 12					; 0000000cH
$L65846:

; 112  : 	return (e > 0 ? 1 : -1);

	xor	eax, eax
	cmp	DWORD PTR _e$[ebp], 0
	setle	al
	dec	eax
	and	eax, 2
	add	eax, -1
$L65841:

; 113  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFReadScanline ENDP
_TEXT	ENDS
EXTRN	_TIFFError:NEAR
_DATA	SEGMENT
$SG65819 DB	'%lu: Row out of range, max %lu', 00H
	ORG $+1
$SG65824 DB	'%lu: Sample out of range, max %lu', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_row$ = 12
_sample$ = 16
_td$ = -4
_strip$ = -8
_TIFFSeek PROC NEAR

; 49   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8
	push	esi

; 50   : 	register TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 51   : 	tstrip_t strip;
; 52   : 
; 53   : 	if (row >= td->td_imagelength) {	/* out of range */

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _row$[ebp]
	cmp	edx, DWORD PTR [ecx+16]
	jb	SHORT $L65816

; 54   : 		TIFFError(tif->tif_name, "%lu: Row out of range, max %lu",
; 55   : 		    (u_long) row, (u_long) td->td_imagelength);

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	mov	edx, DWORD PTR _row$[ebp]
	push	edx
	push	OFFSET FLAT:$SG65819
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 16					; 00000010H

; 56   : 		return (0);

	xor	eax, eax
	jmp	$L65813
$L65816:

; 58   : 	if (td->td_planarconfig == PLANARCONFIG_SEPARATE) {

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+90]
	cmp	eax, 2
	jne	SHORT $L65820

; 59   : 		if (sample >= td->td_samplesperpixel) {

	mov	ecx, DWORD PTR _sample$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+54]
	cmp	ecx, eax
	jl	SHORT $L65821

; 60   : 			TIFFError(tif->tif_name,
; 61   : 			    "%lu: Sample out of range, max %lu",
; 62   : 			    (u_long) sample, (u_long) td->td_samplesperpixel);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+54]
	push	edx
	mov	eax, DWORD PTR _sample$[ebp]
	and	eax, 65535				; 0000ffffH
	push	eax
	push	OFFSET FLAT:$SG65824
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 16					; 00000010H

; 63   : 			return (0);

	xor	eax, eax
	jmp	$L65813
$L65821:

; 65   : 		strip = sample*td->td_stripsperimage + row/td->td_rowsperstrip;

	mov	ecx, DWORD PTR _sample$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _td$[ebp]
	imul	ecx, DWORD PTR [edx+176]
	mov	esi, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	xor	edx, edx
	div	DWORD PTR [esi+56]
	add	ecx, eax
	mov	DWORD PTR _strip$[ebp], ecx

; 66   : 	} else

	jmp	SHORT $L65825
$L65820:

; 67   : 		strip = row / td->td_rowsperstrip;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+56]
	mov	DWORD PTR _strip$[ebp], eax
$L65825:

; 68   : 	if (strip != tif->tif_curstrip) { 	/* different strip, refill */

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _strip$[ebp]
	cmp	eax, DWORD PTR [edx+364]
	je	SHORT $L65826

; 69   : 		if (!TIFFFillStrip(tif, strip))

	mov	ecx, DWORD PTR _strip$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFillStrip
	add	esp, 8
	test	eax, eax
	jne	SHORT $L65827

; 70   : 			return (0);

	xor	eax, eax
	jmp	SHORT $L65813
$L65827:

; 71   : 	} else if (row < tif->tif_row) {

	jmp	SHORT $L65830
$L65826:
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _row$[ebp]
	cmp	ecx, DWORD PTR [eax+356]
	jae	SHORT $L65830

; 72   : 		/*
; 73   : 		 * Moving backwards within the same strip: backup
; 74   : 		 * to the start and then decode forward (below).
; 75   : 		 *
; 76   : 		 * NB: If you're planning on lots of random access within a
; 77   : 		 * strip, it's better to just read and decode the entire
; 78   : 		 * strip, and then access the decoded data in a random fashion.
; 79   : 		 */
; 80   : 		if (!TIFFStartStrip(tif, strip))

	mov	edx, DWORD PTR _strip$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFStartStrip
	add	esp, 8
	test	eax, eax
	jne	SHORT $L65830

; 81   : 			return (0);

	xor	eax, eax
	jmp	SHORT $L65813
$L65830:

; 83   : 	if (row != tif->tif_row) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _row$[ebp]
	cmp	edx, DWORD PTR [ecx+356]
	je	SHORT $L65831

; 84   : 		/*
; 85   : 		 * Seek forward to the desired row.
; 86   : 		 */
; 87   : 		if (!(*tif->tif_seek)(tif, row - tif->tif_row))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _row$[ebp]
	sub	ecx, DWORD PTR [eax+356]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+444]
	add	esp, 8
	test	eax, eax
	jne	SHORT $L65832

; 88   : 			return (0);

	xor	eax, eax
	jmp	SHORT $L65813
$L65832:

; 89   : 		tif->tif_row = row;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _row$[ebp]
	mov	DWORD PTR [ecx+356], edx
$L65831:

; 91   : 	return (1);

	mov	eax, 1
$L65813:

; 92   : }

	pop	esi
	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFSeek ENDP
_TEXT	ENDS
PUBLIC	_TIFFReadEncodedStrip
EXTRN	_TIFFVStripSize:NEAR
_DATA	SEGMENT
	ORG $+2
$SG65866 DB	'%ld: Strip out of range, max %ld', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_strip$ = 12
_buf$ = 16
_size$ = 20
_td$ = -20
_nrows$ = -12
_stripsize$ = -4
_sep_strip$ = -8
_strips_per_sep$ = -16
_TIFFReadEncodedStrip PROC NEAR

; 121  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 20					; 00000014H

; 122  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 123  : 	uint32 nrows;
; 124  : 	tsize_t stripsize;
; 125  :         tstrip_t sep_strip, strips_per_sep;
; 126  : 
; 127  : 	if (!TIFFCheckRead(tif, 0))

	push	0
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFCheckRead
	add	esp, 8
	test	eax, eax
	jne	SHORT $L65862

; 128  : 		return (-1);

	or	eax, -1
	jmp	$L65879
$L65862:

; 129  : 	if (strip >= td->td_nstrips) {

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _strip$[ebp]
	cmp	eax, DWORD PTR [edx+180]
	jb	SHORT $L65863

; 130  : 		TIFFError(tif->tif_name, "%ld: Strip out of range, max %ld",
; 131  : 		    (long) strip, (long) td->td_nstrips);

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+180]
	push	edx
	mov	eax, DWORD PTR _strip$[ebp]
	push	eax
	push	OFFSET FLAT:$SG65866
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 16					; 00000010H

; 132  : 		return (-1);

	or	eax, -1
	jmp	$L65879
$L65863:

; 134  : 	/*
; 135  : 	 * Calculate the strip size according to the number of
; 136  : 	 * rows in the strip (check for truncated last strip on any
; 137  :          * of the separations).
; 138  : 	 */
; 139  :         if( td->td_rowsperstrip >= td->td_imagelength )

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [eax+56]
	cmp	edx, DWORD PTR [ecx+16]
	jb	SHORT $L65867

; 140  :             strips_per_sep = 1;

	mov	DWORD PTR _strips_per_sep$[ebp], 1

; 141  :         else

	jmp	SHORT $L65868
$L65867:

; 142  :             strips_per_sep = (td->td_imagelength+td->td_rowsperstrip-1)
; 143  :                 / td->td_rowsperstrip;

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+56]
	lea	eax, DWORD PTR [ecx+eax-1]
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+56]
	mov	DWORD PTR _strips_per_sep$[ebp], eax
$L65868:

; 144  : 
; 145  :         sep_strip = strip % strips_per_sep;

	mov	eax, DWORD PTR _strip$[ebp]
	xor	edx, edx
	div	DWORD PTR _strips_per_sep$[ebp]
	mov	DWORD PTR _sep_strip$[ebp], edx

; 146  : 
; 147  : 	if (sep_strip != strips_per_sep-1 ||
; 148  : 	    (nrows = td->td_imagelength % td->td_rowsperstrip) == 0)

	mov	edx, DWORD PTR _strips_per_sep$[ebp]
	sub	edx, 1
	cmp	DWORD PTR _sep_strip$[ebp], edx
	jne	SHORT $L65870
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [eax+16]
	xor	edx, edx
	div	DWORD PTR [ecx+56]
	mov	DWORD PTR _nrows$[ebp], edx
	cmp	DWORD PTR _nrows$[ebp], 0
	jne	SHORT $L65869
$L65870:

; 149  : 		nrows = td->td_rowsperstrip;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	DWORD PTR _nrows$[ebp], eax
$L65869:

; 150  : 
; 151  : 	stripsize = TIFFVStripSize(tif, nrows);

	mov	ecx, DWORD PTR _nrows$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFVStripSize
	add	esp, 8
	mov	DWORD PTR _stripsize$[ebp], eax

; 152  : 	if (size == (tsize_t) -1)

	cmp	DWORD PTR _size$[ebp], -1
	jne	SHORT $L65872

; 153  : 		size = stripsize;

	mov	eax, DWORD PTR _stripsize$[ebp]
	mov	DWORD PTR _size$[ebp], eax

; 154  : 	else if (size > stripsize)

	jmp	SHORT $L65874
$L65872:
	mov	ecx, DWORD PTR _size$[ebp]
	cmp	ecx, DWORD PTR _stripsize$[ebp]
	jle	SHORT $L65874

; 155  : 		size = stripsize;

	mov	edx, DWORD PTR _stripsize$[ebp]
	mov	DWORD PTR _size$[ebp], edx
$L65874:

; 156  : 	if (TIFFFillStrip(tif, strip) && (*tif->tif_decodestrip)(tif,
; 157  : 	    (tidata_t) buf, size, (tsample_t)(strip / td->td_stripsperimage))) {

	mov	eax, DWORD PTR _strip$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFillStrip
	add	esp, 8
	test	eax, eax
	je	SHORT $L65877
	mov	ecx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _strip$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+176]
	push	eax
	mov	edx, DWORD PTR _size$[ebp]
	push	edx
	mov	eax, DWORD PTR _buf$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+424]
	add	esp, 16					; 00000010H
	test	eax, eax
	je	SHORT $L65877

; 158  : 		(*tif->tif_postdecode)(tif, (tidata_t) buf, size);

	mov	eax, DWORD PTR _size$[ebp]
	push	eax
	mov	ecx, DWORD PTR _buf$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+528]
	add	esp, 12					; 0000000cH

; 159  : 		return (size);

	mov	eax, DWORD PTR _size$[ebp]
	jmp	SHORT $L65879
$L65877:

; 161  : 		return ((tsize_t) -1);

	or	eax, -1
$L65879:

; 162  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFReadEncodedStrip ENDP
_TEXT	ENDS
PUBLIC	_TIFFReadRawStrip
_DATA	SEGMENT
	ORG $+3
$SG65933 DB	'%lu: Strip out of range, max %lu', 00H
	ORG $+3
$SG65938 DB	'%lu: Invalid strip byte count, strip %lu', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_strip$ = 12
_buf$ = 16
_size$ = 20
_td$ = -8
_bytecount$ = -4
_TIFFReadRawStrip PROC NEAR

; 211  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 212  : 	static const char module[] = "TIFFReadRawStrip";
; 213  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 214  : 	tsize_t bytecount;
; 215  : 
; 216  : 	if (!TIFFCheckRead(tif, 0))

	push	0
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFCheckRead
	add	esp, 8
	test	eax, eax
	jne	SHORT $L65928

; 217  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	$L65923
$L65928:

; 218  : 	if (strip >= td->td_nstrips) {

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _strip$[ebp]
	cmp	eax, DWORD PTR [edx+180]
	jb	SHORT $L65930

; 219  : 		TIFFError(tif->tif_name, "%lu: Strip out of range, max %lu",
; 220  : 		    (u_long) strip, (u_long) td->td_nstrips);

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+180]
	push	edx
	mov	eax, DWORD PTR _strip$[ebp]
	push	eax
	push	OFFSET FLAT:$SG65933
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 16					; 00000010H

; 221  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	SHORT $L65923
$L65930:

; 223  : 	bytecount = td->td_stripbytecount[strip];

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+188]
	mov	edx, DWORD PTR _strip$[ebp]
	mov	eax, DWORD PTR [ecx+edx*4]
	mov	DWORD PTR _bytecount$[ebp], eax

; 224  : 	if (bytecount <= 0) {

	cmp	DWORD PTR _bytecount$[ebp], 0
	jg	SHORT $L65935

; 225  : 		TIFFError(tif->tif_name,
; 226  : 		    "%lu: Invalid strip byte count, strip %lu",
; 227  : 		    (u_long) bytecount, (u_long) strip);

	mov	ecx, DWORD PTR _strip$[ebp]
	push	ecx
	mov	edx, DWORD PTR _bytecount$[ebp]
	push	edx
	push	OFFSET FLAT:$SG65938
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 16					; 00000010H

; 228  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	SHORT $L65923
$L65935:

; 230  : 	if (size != (tsize_t)-1 && size < bytecount)

	cmp	DWORD PTR _size$[ebp], -1
	je	SHORT $L65941
	mov	edx, DWORD PTR _size$[ebp]
	cmp	edx, DWORD PTR _bytecount$[ebp]
	jge	SHORT $L65941

; 231  : 		bytecount = size;

	mov	eax, DWORD PTR _size$[ebp]
	mov	DWORD PTR _bytecount$[ebp], eax
$L65941:

; 232  : 	return (TIFFReadRawStrip1(tif, strip, buf, bytecount, module));

	push	OFFSET FLAT:_?module@?1??TIFFReadRawStrip@@9@9
	mov	ecx, DWORD PTR _bytecount$[ebp]
	push	ecx
	mov	edx, DWORD PTR _buf$[ebp]
	push	edx
	mov	eax, DWORD PTR _strip$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFReadRawStrip1
	add	esp, 20					; 00000014H
$L65923:

; 233  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFReadRawStrip ENDP
_TEXT	ENDS
EXTRN	__TIFFmemcpy:NEAR
_DATA	SEGMENT
	ORG $+3
$SG65902 DB	'%s: Seek error at scanline %lu, strip %lu', 00H
	ORG $+2
$SG65907 DB	'%s: Read error at scanline %lu; got %lu bytes, expected '
	DB	'%lu', 00H
$SG65914 DB	'%s: Read error at scanline %lu, strip %lu; got %lu bytes'
	DB	', expected %lu', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_strip$ = 12
_buf$ = 16
_size$ = 20
_module$ = 24
_td$ = -4
_cc$65895 = -8
_TIFFReadRawStrip1 PROC NEAR

; 167  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 168  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 169  : 
; 170  : 	if (!isMapped(tif)) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 2048				; 00000800H
	test	edx, edx
	jne	$L65894

; 171  : 		tsize_t cc;
; 172  : 
; 173  : 		if (!SeekOK(tif, td->td_stripoffset[strip])) {

	push	0
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+184]
	mov	edx, DWORD PTR _strip$[ebp]
	mov	eax, DWORD PTR [ecx+edx*4]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+516]
	add	esp, 12					; 0000000cH
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	mov	ecx, DWORD PTR _strip$[ebp]
	cmp	eax, DWORD PTR [edx+ecx*4]
	je	SHORT $L65899

; 174  : 			TIFFError(module,
; 175  : 			    "%s: Seek error at scanline %lu, strip %lu",
; 176  : 			    tif->tif_name,
; 177  : 			    (u_long) tif->tif_row, (u_long) strip);

	mov	edx, DWORD PTR _strip$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+356]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	push	OFFSET FLAT:$SG65902
	mov	ecx, DWORD PTR _module$[ebp]
	push	ecx
	call	_TIFFError
	add	esp, 20					; 00000014H

; 178  : 			return (-1);

	or	eax, -1
	jmp	$L65892
$L65899:

; 180  : 		cc = TIFFReadFile(tif, buf, size);

	mov	edx, DWORD PTR _size$[ebp]
	push	edx
	mov	eax, DWORD PTR _buf$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+508]
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _cc$65895[ebp], eax

; 181  : 		if (cc != size) {

	mov	ecx, DWORD PTR _cc$65895[ebp]
	cmp	ecx, DWORD PTR _size$[ebp]
	je	SHORT $L65903

; 182  : 			TIFFError(module,
; 183  : 		"%s: Read error at scanline %lu; got %lu bytes, expected %lu",
; 184  : 			    tif->tif_name,
; 185  : 			    (u_long) tif->tif_row,
; 186  : 			    (u_long) cc,
; 187  : 			    (u_long) size);

	mov	edx, DWORD PTR _size$[ebp]
	push	edx
	mov	eax, DWORD PTR _cc$65895[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG65907
	mov	edx, DWORD PTR _module$[ebp]
	push	edx
	call	_TIFFError
	add	esp, 24					; 00000018H

; 188  : 			return (-1);

	or	eax, -1
	jmp	$L65892
$L65903:

; 190  : 	} else {

	jmp	$L65908
$L65894:

; 191  : 		if (td->td_stripoffset[strip] + size > tif->tif_size) {

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+184]
	mov	edx, DWORD PTR _strip$[ebp]
	mov	eax, DWORD PTR [ecx+edx*4]
	add	eax, DWORD PTR _size$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	cmp	eax, DWORD PTR [ecx+492]
	jbe	SHORT $L65909

; 192  : 			TIFFError(module,
; 193  :     "%s: Read error at scanline %lu, strip %lu; got %lu bytes, expected %lu",
; 194  : 			    tif->tif_name,
; 195  : 			    (u_long) tif->tif_row,
; 196  : 			    (u_long) strip,
; 197  : 			    (u_long) tif->tif_size - td->td_stripoffset[strip],
; 198  : 			    (u_long) size);

	mov	edx, DWORD PTR _size$[ebp]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+184]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _strip$[ebp]
	mov	edx, DWORD PTR [edx+492]
	sub	edx, DWORD PTR [ecx+eax*4]
	push	edx
	mov	eax, DWORD PTR _strip$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG65914
	mov	edx, DWORD PTR _module$[ebp]
	push	edx
	call	_TIFFError
	add	esp, 28					; 0000001cH

; 199  : 			return (-1);

	or	eax, -1
	jmp	SHORT $L65892
$L65909:

; 201  : 		_TIFFmemcpy(buf, tif->tif_base + td->td_stripoffset[strip], size);

	mov	eax, DWORD PTR _size$[ebp]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+488]
	mov	eax, DWORD PTR _strip$[ebp]
	add	ecx, DWORD PTR [edx+eax*4]
	push	ecx
	mov	ecx, DWORD PTR _buf$[ebp]
	push	ecx
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH
$L65908:

; 203  : 	return (size);

	mov	eax, DWORD PTR _size$[ebp]
$L65892:

; 204  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFReadRawStrip1 ENDP
_TEXT	ENDS
PUBLIC	_TIFFReadBufferSetup
EXTRN	__TIFFfree:NEAR
EXTRN	_TIFFReverseBits:NEAR
_DATA	SEGMENT
	ORG $+1
$SG65954 DB	'%lu: Invalid strip byte count, strip %lu', 00H
	ORG $+3
$SG65962 DB	'%s: Read error on strip %lu; got %lu bytes, expected %lu'
	DB	00H
	ORG $+3
$SG65969 DB	'%s: Data buffer too small to hold strip %lu', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_strip$ = 12
_td$ = -8
_bytecount$ = -4
_TIFFFillStrip PROC NEAR

; 242  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 243  : 	static const char module[] = "TIFFFillStrip";
; 244  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 245  : 	tsize_t bytecount;
; 246  : 
; 247  : 	bytecount = td->td_stripbytecount[strip];

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+188]
	mov	eax, DWORD PTR _strip$[ebp]
	mov	ecx, DWORD PTR [edx+eax*4]
	mov	DWORD PTR _bytecount$[ebp], ecx

; 248  : 	if (bytecount <= 0) {

	cmp	DWORD PTR _bytecount$[ebp], 0
	jg	SHORT $L65951

; 249  : 		TIFFError(tif->tif_name,
; 250  : 		    "%lu: Invalid strip byte count, strip %lu",
; 251  : 		    (u_long) bytecount, (u_long) strip);

	mov	edx, DWORD PTR _strip$[ebp]
	push	edx
	mov	eax, DWORD PTR _bytecount$[ebp]
	push	eax
	push	OFFSET FLAT:$SG65954
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 16					; 00000010H

; 252  : 		return (0);

	xor	eax, eax
	jmp	$L65946
$L65951:

; 254  : 	if (isMapped(tif) &&
; 255  : 	    (isFillOrder(tif, td->td_fillorder) || (tif->tif_flags & TIFF_NOBITREV))) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 2048				; 00000800H
	test	ecx, ecx
	je	$L65955
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+50]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, eax
	test	edx, edx
	jne	SHORT $L65956
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 256				; 00000100H
	test	ecx, ecx
	je	$L65955
$L65956:

; 256  : 		/*
; 257  : 		 * The image is mapped into memory and we either don't
; 258  : 		 * need to flip bits or the compression routine is going
; 259  : 		 * to handle this operation itself.  In this case, avoid
; 260  : 		 * copying the raw data and instead just reference the
; 261  : 		 * data from the memory mapped file image.  This assumes
; 262  : 		 * that the decompression routines do not modify the
; 263  : 		 * contents of the raw data buffer (if they try to,
; 264  : 		 * the application will get a fault since the file is
; 265  : 		 * mapped read-only).
; 266  : 		 */
; 267  : 		if ((tif->tif_flags & TIFF_MYBUFFER) && tif->tif_rawdata)

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 512				; 00000200H
	test	eax, eax
	je	SHORT $L65957
	mov	ecx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [ecx+472], 0
	je	SHORT $L65957

; 268  : 			_TIFFfree(tif->tif_rawdata);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+472]
	push	eax
	call	__TIFFfree
	add	esp, 4
$L65957:

; 269  : 		tif->tif_flags &= ~TIFF_MYBUFFER;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	dh, -3					; fffffffdH
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+12], edx

; 270  : 		if ( td->td_stripoffset[strip] + bytecount > tif->tif_size) {

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	mov	eax, DWORD PTR _strip$[ebp]
	mov	ecx, DWORD PTR [edx+eax*4]
	add	ecx, DWORD PTR _bytecount$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	cmp	ecx, DWORD PTR [edx+492]
	jbe	SHORT $L65958

; 271  : 			/*
; 272  : 			 * This error message might seem strange, but it's
; 273  : 			 * what would happen if a read were done instead.
; 274  : 			 */
; 275  : 			TIFFError(module,
; 276  : 		    "%s: Read error on strip %lu; got %lu bytes, expected %lu",
; 277  : 			    tif->tif_name,
; 278  : 			    (u_long) strip,
; 279  : 			    (u_long) tif->tif_size - td->td_stripoffset[strip],
; 280  : 			    (u_long) bytecount);

	mov	eax, DWORD PTR _bytecount$[ebp]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _strip$[ebp]
	mov	eax, DWORD PTR [eax+492]
	sub	eax, DWORD PTR [edx+ecx*4]
	push	eax
	mov	ecx, DWORD PTR _strip$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	push	OFFSET FLAT:$SG65962
	push	OFFSET FLAT:_?module@?1??TIFFFillStrip@@9@9
	call	_TIFFError
	add	esp, 24					; 00000018H

; 281  : 			tif->tif_curstrip = NOSTRIP;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+364], -1

; 282  : 			return (0);

	xor	eax, eax
	jmp	$L65946
$L65958:

; 284  : 		tif->tif_rawdatasize = bytecount;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _bytecount$[ebp]
	mov	DWORD PTR [edx+476], eax

; 285  : 		tif->tif_rawdata = tif->tif_base + td->td_stripoffset[strip];

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+488]
	mov	eax, DWORD PTR _strip$[ebp]
	add	ecx, DWORD PTR [edx+eax*4]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+472], ecx

; 286  : 	} else {

	jmp	$L65977
$L65955:

; 287  : 		/*
; 288  : 		 * Expand raw data buffer, if needed, to
; 289  : 		 * hold data strip coming from file
; 290  : 		 * (perhaps should set upper bound on
; 291  : 		 *  the size of a buffer we'll use?).
; 292  : 		 */
; 293  : 		if (bytecount > tif->tif_rawdatasize) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _bytecount$[ebp]
	cmp	ecx, DWORD PTR [eax+476]
	jle	SHORT $L65974

; 294  : 			tif->tif_curstrip = NOSTRIP;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+364], -1

; 295  : 			if ((tif->tif_flags & TIFF_MYBUFFER) == 0) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 512				; 00000200H
	test	ecx, ecx
	jne	SHORT $L65967

; 296  : 				TIFFError(module,
; 297  : 				"%s: Data buffer too small to hold strip %lu",
; 298  : 				    tif->tif_name, (u_long) strip);

	mov	edx, DWORD PTR _strip$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG65969
	push	OFFSET FLAT:_?module@?1??TIFFFillStrip@@9@9
	call	_TIFFError
	add	esp, 16					; 00000010H

; 299  : 				return (0);

	xor	eax, eax
	jmp	$L65946
$L65967:

; 301  : 			if (!TIFFReadBufferSetup(tif, 0,
; 302  : 			    TIFFroundup(bytecount, 1024)))

	mov	edx, DWORD PTR _bytecount$[ebp]
	add	edx, 1023				; 000003ffH
	shr	edx, 10					; 0000000aH
	shl	edx, 10					; 0000000aH
	push	edx
	push	0
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFReadBufferSetup
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65974

; 303  : 				return (0);

	xor	eax, eax
	jmp	SHORT $L65946
$L65974:

; 305  : 		if (TIFFReadRawStrip1(tif, strip, (u_char *)tif->tif_rawdata,
; 306  : 		    bytecount, module) != bytecount)

	push	OFFSET FLAT:_?module@?1??TIFFFillStrip@@9@9
	mov	ecx, DWORD PTR _bytecount$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+472]
	push	eax
	mov	ecx, DWORD PTR _strip$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFReadRawStrip1
	add	esp, 20					; 00000014H
	cmp	eax, DWORD PTR _bytecount$[ebp]
	je	SHORT $L65976

; 307  : 			return (0);

	xor	eax, eax
	jmp	SHORT $L65946
$L65976:

; 308  : 		if (!isFillOrder(tif, td->td_fillorder) &&
; 309  : 		    (tif->tif_flags & TIFF_NOBITREV) == 0)

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+50]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, ecx
	test	eax, eax
	jne	SHORT $L65977
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 256				; 00000100H
	test	edx, edx
	jne	SHORT $L65977

; 310  : 			TIFFReverseBits(tif->tif_rawdata, bytecount);

	mov	eax, DWORD PTR _bytecount$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+472]
	push	edx
	call	_TIFFReverseBits
	add	esp, 8
$L65977:

; 312  : 	return (TIFFStartStrip(tif, strip));

	mov	eax, DWORD PTR _strip$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFStartStrip
	add	esp, 8
$L65946:

; 313  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFFillStrip ENDP
_TEXT	ENDS
PUBLIC	_TIFFReadTile
PUBLIC	_TIFFReadEncodedTile
EXTRN	_TIFFComputeTile:NEAR
EXTRN	_TIFFCheckTile:NEAR
_TEXT	SEGMENT
_tif$ = 8
_buf$ = 12
_x$ = 16
_y$ = 20
_z$ = 24
_s$ = 28
_TIFFReadTile PROC NEAR

; 327  : {

	push	ebp
	mov	ebp, esp

; 328  : 	if (!TIFFCheckRead(tif, 1) || !TIFFCheckTile(tif, x, y, z, s))

	push	1
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFCheckRead
	add	esp, 8
	test	eax, eax
	je	SHORT $L65992
	mov	cx, WORD PTR _s$[ebp]
	push	ecx
	mov	edx, DWORD PTR _z$[ebp]
	push	edx
	mov	eax, DWORD PTR _y$[ebp]
	push	eax
	mov	ecx, DWORD PTR _x$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFCheckTile
	add	esp, 20					; 00000014H
	test	eax, eax
	jne	SHORT $L65991
$L65992:

; 329  : 		return (-1);

	or	eax, -1
	jmp	SHORT $L65990
$L65991:

; 330  : 	return (TIFFReadEncodedTile(tif,
; 331  : 	    TIFFComputeTile(tif, x, y, z, s), buf, (tsize_t) -1));

	push	-1
	mov	eax, DWORD PTR _buf$[ebp]
	push	eax
	mov	cx, WORD PTR _s$[ebp]
	push	ecx
	mov	edx, DWORD PTR _z$[ebp]
	push	edx
	mov	eax, DWORD PTR _y$[ebp]
	push	eax
	mov	ecx, DWORD PTR _x$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFComputeTile
	add	esp, 20					; 00000014H
	push	eax
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFReadEncodedTile
	add	esp, 16					; 00000010H
$L65990:

; 332  : }

	pop	ebp
	ret	0
_TIFFReadTile ENDP
_TEXT	ENDS
_DATA	SEGMENT
$SG66009 DB	'%ld: Tile out of range, max %ld', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_tile$ = 12
_buf$ = 16
_size$ = 20
_td$ = -8
_tilesize$ = -4
_TIFFReadEncodedTile PROC NEAR

; 340  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 341  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 342  : 	tsize_t tilesize = tif->tif_tilesize;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+392]
	mov	DWORD PTR _tilesize$[ebp], edx

; 343  : 
; 344  : 	if (!TIFFCheckRead(tif, 1))

	push	1
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFCheckRead
	add	esp, 8
	test	eax, eax
	jne	SHORT $L66005

; 345  : 		return (-1);

	or	eax, -1
	jmp	$L66018
$L66005:

; 346  : 	if (tile >= td->td_nstrips) {

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _tile$[ebp]
	cmp	edx, DWORD PTR [ecx+180]
	jb	SHORT $L66006

; 347  : 		TIFFError(tif->tif_name, "%ld: Tile out of range, max %ld",
; 348  : 		    (long) tile, (u_long) td->td_nstrips);

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+180]
	push	ecx
	mov	edx, DWORD PTR _tile$[ebp]
	push	edx
	push	OFFSET FLAT:$SG66009
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 16					; 00000010H

; 349  : 		return (-1);

	or	eax, -1
	jmp	SHORT $L66018
$L66006:

; 351  : 	if (size == (tsize_t) -1)

	cmp	DWORD PTR _size$[ebp], -1
	jne	SHORT $L66011

; 352  : 		size = tilesize;

	mov	edx, DWORD PTR _tilesize$[ebp]
	mov	DWORD PTR _size$[ebp], edx

; 353  : 	else if (size > tilesize)

	jmp	SHORT $L66013
$L66011:
	mov	eax, DWORD PTR _size$[ebp]
	cmp	eax, DWORD PTR _tilesize$[ebp]
	jle	SHORT $L66013

; 354  : 		size = tilesize;

	mov	ecx, DWORD PTR _tilesize$[ebp]
	mov	DWORD PTR _size$[ebp], ecx
$L66013:

; 355  : 	if (TIFFFillTile(tif, tile) && (*tif->tif_decodetile)(tif,
; 356  : 	    (tidata_t) buf, size, (tsample_t)(tile/td->td_stripsperimage))) {

	mov	edx, DWORD PTR _tile$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFillTile
	add	esp, 8
	test	eax, eax
	je	SHORT $L66016
	mov	ecx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _tile$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+176]
	push	eax
	mov	edx, DWORD PTR _size$[ebp]
	push	edx
	mov	eax, DWORD PTR _buf$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+432]
	add	esp, 16					; 00000010H
	test	eax, eax
	je	SHORT $L66016

; 357  : 		(*tif->tif_postdecode)(tif, (tidata_t) buf, size);

	mov	eax, DWORD PTR _size$[ebp]
	push	eax
	mov	ecx, DWORD PTR _buf$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+528]
	add	esp, 12					; 0000000cH

; 358  : 		return (size);

	mov	eax, DWORD PTR _size$[ebp]
	jmp	SHORT $L66018
$L66016:

; 360  : 		return (-1);

	or	eax, -1
$L66018:

; 361  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFReadEncodedTile ENDP
_TEXT	ENDS
PUBLIC	_TIFFReadRawTile
_DATA	SEGMENT
$SG66077 DB	'%lu: Tile out of range, max %lu', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_tile$ = 12
_buf$ = 16
_size$ = 20
_td$ = -8
_bytecount$ = -4
_TIFFReadRawTile PROC NEAR

; 414  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 415  : 	static const char module[] = "TIFFReadRawTile";
; 416  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 417  : 	tsize_t bytecount;
; 418  : 
; 419  : 	if (!TIFFCheckRead(tif, 1))

	push	1
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFCheckRead
	add	esp, 8
	test	eax, eax
	jne	SHORT $L66072

; 420  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	SHORT $L66067
$L66072:

; 421  : 	if (tile >= td->td_nstrips) {

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _tile$[ebp]
	cmp	eax, DWORD PTR [edx+180]
	jb	SHORT $L66074

; 422  : 		TIFFError(tif->tif_name, "%lu: Tile out of range, max %lu",
; 423  : 		    (u_long) tile, (u_long) td->td_nstrips);

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+180]
	push	edx
	mov	eax, DWORD PTR _tile$[ebp]
	push	eax
	push	OFFSET FLAT:$SG66077
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 16					; 00000010H

; 424  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	SHORT $L66067
$L66074:

; 426  : 	bytecount = td->td_stripbytecount[tile];

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+188]
	mov	edx, DWORD PTR _tile$[ebp]
	mov	eax, DWORD PTR [ecx+edx*4]
	mov	DWORD PTR _bytecount$[ebp], eax

; 427  : 	if (size != (tsize_t) -1 && size < bytecount)

	cmp	DWORD PTR _size$[ebp], -1
	je	SHORT $L66080
	mov	ecx, DWORD PTR _size$[ebp]
	cmp	ecx, DWORD PTR _bytecount$[ebp]
	jge	SHORT $L66080

; 428  : 		bytecount = size;

	mov	edx, DWORD PTR _size$[ebp]
	mov	DWORD PTR _bytecount$[ebp], edx
$L66080:

; 429  : 	return (TIFFReadRawTile1(tif, tile, buf, bytecount, module));

	push	OFFSET FLAT:_?module@?1??TIFFReadRawTile@@9@9
	mov	eax, DWORD PTR _bytecount$[ebp]
	push	eax
	mov	ecx, DWORD PTR _buf$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tile$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFReadRawTile1
	add	esp, 20					; 00000014H
$L66067:

; 430  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFReadRawTile ENDP
_TEXT	ENDS
_DATA	SEGMENT
$SG66041 DB	'%s: Seek error at row %ld, col %ld, tile %ld', 00H
	ORG $+3
$SG66048 DB	'%s: Read error at row %ld, col %ld; got %lu bytes, expec'
	DB	'ted %lu', 00H
$SG66057 DB	'%s: Read error at row %ld, col %ld, tile %ld; got %lu by'
	DB	'tes, expected %lu', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_tile$ = 12
_buf$ = 16
_size$ = 20
_module$ = 24
_td$ = -4
_cc$66033 = -8
_TIFFReadRawTile1 PROC NEAR

; 366  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 367  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 368  : 
; 369  : 	if (!isMapped(tif)) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 2048				; 00000800H
	test	edx, edx
	jne	$L66032

; 370  : 		tsize_t cc;
; 371  : 
; 372  : 		if (!SeekOK(tif, td->td_stripoffset[tile])) {

	push	0
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+184]
	mov	edx, DWORD PTR _tile$[ebp]
	mov	eax, DWORD PTR [ecx+edx*4]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+516]
	add	esp, 12					; 0000000cH
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	mov	ecx, DWORD PTR _tile$[ebp]
	cmp	eax, DWORD PTR [edx+ecx*4]
	je	SHORT $L66037

; 373  : 			TIFFError(module,
; 374  : 			    "%s: Seek error at row %ld, col %ld, tile %ld",
; 375  : 			    tif->tif_name,
; 376  : 			    (long) tif->tif_row,
; 377  : 			    (long) tif->tif_col,
; 378  : 			    (long) tile);

	mov	edx, DWORD PTR _tile$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+384]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+356]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	push	OFFSET FLAT:$SG66041
	mov	eax, DWORD PTR _module$[ebp]
	push	eax
	call	_TIFFError
	add	esp, 24					; 00000018H

; 379  : 			return ((tsize_t) -1);

	or	eax, -1
	jmp	$L66030
$L66037:

; 381  : 		cc = TIFFReadFile(tif, buf, size);

	mov	ecx, DWORD PTR _size$[ebp]
	push	ecx
	mov	edx, DWORD PTR _buf$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+508]
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _cc$66033[ebp], eax

; 382  : 		if (cc != size) {

	mov	eax, DWORD PTR _cc$66033[ebp]
	cmp	eax, DWORD PTR _size$[ebp]
	je	SHORT $L66043

; 383  : 			TIFFError(module,
; 384  : 	    "%s: Read error at row %ld, col %ld; got %lu bytes, expected %lu",
; 385  : 			    tif->tif_name,
; 386  : 			    (long) tif->tif_row,
; 387  : 			    (long) tif->tif_col,
; 388  : 			    (u_long) cc,
; 389  : 			    (u_long) size);

	mov	ecx, DWORD PTR _size$[ebp]
	push	ecx
	mov	edx, DWORD PTR _cc$66033[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+384]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+356]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	push	OFFSET FLAT:$SG66048
	mov	eax, DWORD PTR _module$[ebp]
	push	eax
	call	_TIFFError
	add	esp, 28					; 0000001cH

; 390  : 			return ((tsize_t) -1);

	or	eax, -1
	jmp	$L66030
$L66043:

; 392  : 	} else {

	jmp	$L66050
$L66032:

; 393  : 		if (td->td_stripoffset[tile] + size > tif->tif_size) {

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	mov	eax, DWORD PTR _tile$[ebp]
	mov	ecx, DWORD PTR [edx+eax*4]
	add	ecx, DWORD PTR _size$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	cmp	ecx, DWORD PTR [edx+492]
	jbe	SHORT $L66051

; 394  : 			TIFFError(module,
; 395  :     "%s: Read error at row %ld, col %ld, tile %ld; got %lu bytes, expected %lu",
; 396  : 			    tif->tif_name,
; 397  : 			    (long) tif->tif_row,
; 398  : 			    (long) tif->tif_col,
; 399  : 			    (long) tile,
; 400  : 			    (u_long) tif->tif_size - td->td_stripoffset[tile],
; 401  : 			    (u_long) size);

	mov	eax, DWORD PTR _size$[ebp]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _tile$[ebp]
	mov	eax, DWORD PTR [eax+492]
	sub	eax, DWORD PTR [edx+ecx*4]
	push	eax
	mov	ecx, DWORD PTR _tile$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+384]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG66057
	mov	edx, DWORD PTR _module$[ebp]
	push	edx
	call	_TIFFError
	add	esp, 32					; 00000020H

; 402  : 			return ((tsize_t) -1);

	or	eax, -1
	jmp	SHORT $L66030
$L66051:

; 404  : 		_TIFFmemcpy(buf, tif->tif_base + td->td_stripoffset[tile], size);

	mov	eax, DWORD PTR _size$[ebp]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+488]
	mov	eax, DWORD PTR _tile$[ebp]
	add	ecx, DWORD PTR [edx+eax*4]
	push	ecx
	mov	ecx, DWORD PTR _buf$[ebp]
	push	ecx
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH
$L66050:

; 406  : 	return (size);

	mov	eax, DWORD PTR _size$[ebp]
$L66030:

; 407  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFReadRawTile1 ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+2
$SG66093 DB	'%lu: Invalid tile byte count, tile %lu', 00H
	ORG $+1
$SG66104 DB	'%s: Data buffer too small to hold tile %ld', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_tile$ = 12
_td$ = -8
_bytecount$ = -4
_TIFFFillTile PROC NEAR

; 439  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 440  : 	static const char module[] = "TIFFFillTile";
; 441  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 442  : 	tsize_t bytecount;
; 443  : 
; 444  : 	bytecount = td->td_stripbytecount[tile];

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+188]
	mov	eax, DWORD PTR _tile$[ebp]
	mov	ecx, DWORD PTR [edx+eax*4]
	mov	DWORD PTR _bytecount$[ebp], ecx

; 445  : 	if (bytecount <= 0) {

	cmp	DWORD PTR _bytecount$[ebp], 0
	jg	SHORT $L66090

; 446  : 		TIFFError(tif->tif_name,
; 447  : 		    "%lu: Invalid tile byte count, tile %lu",
; 448  : 		    (u_long) bytecount, (u_long) tile);

	mov	edx, DWORD PTR _tile$[ebp]
	push	edx
	mov	eax, DWORD PTR _bytecount$[ebp]
	push	eax
	push	OFFSET FLAT:$SG66093
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 16					; 00000010H

; 449  : 		return (0);

	xor	eax, eax
	jmp	$L66085
$L66090:

; 451  : 	if (isMapped(tif) &&
; 452  : 	    (isFillOrder(tif, td->td_fillorder) || (tif->tif_flags & TIFF_NOBITREV))) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 2048				; 00000800H
	test	ecx, ecx
	je	$L66094
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+50]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, eax
	test	edx, edx
	jne	SHORT $L66095
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 256				; 00000100H
	test	ecx, ecx
	je	$L66094
$L66095:

; 453  : 		/*
; 454  : 		 * The image is mapped into memory and we either don't
; 455  : 		 * need to flip bits or the compression routine is going
; 456  : 		 * to handle this operation itself.  In this case, avoid
; 457  : 		 * copying the raw data and instead just reference the
; 458  : 		 * data from the memory mapped file image.  This assumes
; 459  : 		 * that the decompression routines do not modify the
; 460  : 		 * contents of the raw data buffer (if they try to,
; 461  : 		 * the application will get a fault since the file is
; 462  : 		 * mapped read-only).
; 463  : 		 */
; 464  : 		if ((tif->tif_flags & TIFF_MYBUFFER) && tif->tif_rawdata)

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 512				; 00000200H
	test	eax, eax
	je	SHORT $L66096
	mov	ecx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [ecx+472], 0
	je	SHORT $L66096

; 465  : 			_TIFFfree(tif->tif_rawdata);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+472]
	push	eax
	call	__TIFFfree
	add	esp, 4
$L66096:

; 466  : 		tif->tif_flags &= ~TIFF_MYBUFFER;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	dh, -3					; fffffffdH
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+12], edx

; 467  : 		if ( td->td_stripoffset[tile] + bytecount > tif->tif_size) {

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	mov	eax, DWORD PTR _tile$[ebp]
	mov	ecx, DWORD PTR [edx+eax*4]
	add	ecx, DWORD PTR _bytecount$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	cmp	ecx, DWORD PTR [edx+492]
	jbe	SHORT $L66097

; 468  : 			tif->tif_curtile = NOTILE;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+388], -1

; 469  : 			return (0);

	xor	eax, eax
	jmp	$L66085
$L66097:

; 471  : 		tif->tif_rawdatasize = bytecount;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _bytecount$[ebp]
	mov	DWORD PTR [ecx+476], edx

; 472  : 		tif->tif_rawdata = tif->tif_base + td->td_stripoffset[tile];

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+184]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+488]
	mov	edx, DWORD PTR _tile$[ebp]
	add	eax, DWORD PTR [ecx+edx*4]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+472], eax

; 473  : 	} else {

	jmp	$L66112
$L66094:

; 474  : 		/*
; 475  : 		 * Expand raw data buffer, if needed, to
; 476  : 		 * hold data tile coming from file
; 477  : 		 * (perhaps should set upper bound on
; 478  : 		 *  the size of a buffer we'll use?).
; 479  : 		 */
; 480  : 		if (bytecount > tif->tif_rawdatasize) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _bytecount$[ebp]
	cmp	eax, DWORD PTR [edx+476]
	jle	SHORT $L66109

; 481  : 			tif->tif_curtile = NOTILE;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+388], -1

; 482  : 			if ((tif->tif_flags & TIFF_MYBUFFER) == 0) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 512				; 00000200H
	test	eax, eax
	jne	SHORT $L66102

; 483  : 				TIFFError(module,
; 484  : 				"%s: Data buffer too small to hold tile %ld",
; 485  : 				    tif->tif_name, (long) tile);

	mov	ecx, DWORD PTR _tile$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	push	OFFSET FLAT:$SG66104
	push	OFFSET FLAT:_?module@?1??TIFFFillTile@@9@9
	call	_TIFFError
	add	esp, 16					; 00000010H

; 486  : 				return (0);

	xor	eax, eax
	jmp	$L66085
$L66102:

; 488  : 			if (!TIFFReadBufferSetup(tif, 0,
; 489  : 			    TIFFroundup(bytecount, 1024)))

	mov	ecx, DWORD PTR _bytecount$[ebp]
	add	ecx, 1023				; 000003ffH
	shr	ecx, 10					; 0000000aH
	shl	ecx, 10					; 0000000aH
	push	ecx
	push	0
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFReadBufferSetup
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66109

; 490  : 				return (0);

	xor	eax, eax
	jmp	SHORT $L66085
$L66109:

; 492  : 		if (TIFFReadRawTile1(tif, tile, (u_char *)tif->tif_rawdata,
; 493  : 		    bytecount, module) != bytecount)

	push	OFFSET FLAT:_?module@?1??TIFFFillTile@@9@9
	mov	eax, DWORD PTR _bytecount$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+472]
	push	edx
	mov	eax, DWORD PTR _tile$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFReadRawTile1
	add	esp, 20					; 00000014H
	cmp	eax, DWORD PTR _bytecount$[ebp]
	je	SHORT $L66111

; 494  : 			return (0);

	xor	eax, eax
	jmp	SHORT $L66085
$L66111:

; 495  : 		if (!isFillOrder(tif, td->td_fillorder) &&
; 496  : 		    (tif->tif_flags & TIFF_NOBITREV) == 0)

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+50]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, eax
	test	edx, edx
	jne	SHORT $L66112
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 256				; 00000100H
	test	ecx, ecx
	jne	SHORT $L66112

; 497  : 			TIFFReverseBits(tif->tif_rawdata, bytecount);

	mov	edx, DWORD PTR _bytecount$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+472]
	push	ecx
	call	_TIFFReverseBits
	add	esp, 8
$L66112:

; 499  : 	return (TIFFStartTile(tif, tile));

	mov	edx, DWORD PTR _tile$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFStartTile
	add	esp, 8
$L66085:

; 500  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFFillTile ENDP
_TEXT	ENDS
EXTRN	__TIFFmalloc:NEAR
_DATA	SEGMENT
	ORG $+1
$SG66136 DB	'%s: No space for data buffer at scanline %ld', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_bp$ = 12
_size$ = 16
_TIFFReadBufferSetup PROC NEAR

; 513  : {

	push	ebp
	mov	ebp, esp

; 514  : 	static const char module[] = "TIFFReadBufferSetup";
; 515  : 
; 516  : 	if (tif->tif_rawdata) {

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+472], 0
	je	SHORT $L66122

; 517  : 		if (tif->tif_flags & TIFF_MYBUFFER)

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 512				; 00000200H
	test	edx, edx
	je	SHORT $L66123

; 518  : 			_TIFFfree(tif->tif_rawdata);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+472]
	push	ecx
	call	__TIFFfree
	add	esp, 4
$L66123:

; 519  : 		tif->tif_rawdata = NULL;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+472], 0
$L66122:

; 521  : 	if (bp) {

	cmp	DWORD PTR _bp$[ebp], 0
	je	SHORT $L66125

; 522  : 		tif->tif_rawdatasize = size;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _size$[ebp]
	mov	DWORD PTR [eax+476], ecx

; 523  : 		tif->tif_rawdata = (tidata_t) bp;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _bp$[ebp]
	mov	DWORD PTR [edx+472], eax

; 524  : 		tif->tif_flags &= ~TIFF_MYBUFFER;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	dh, -3					; fffffffdH
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+12], edx

; 525  : 	} else {

	jmp	SHORT $L66127
$L66125:

; 526  : 		tif->tif_rawdatasize = TIFFroundup(size, 1024);

	mov	ecx, DWORD PTR _size$[ebp]
	add	ecx, 1023				; 000003ffH
	shr	ecx, 10					; 0000000aH
	shl	ecx, 10					; 0000000aH
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+476], ecx

; 527  : 		tif->tif_rawdata = (tidata_t) _TIFFmalloc(tif->tif_rawdatasize);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+476]
	push	ecx
	call	__TIFFmalloc
	add	esp, 4
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+472], eax

; 528  : 		tif->tif_flags |= TIFF_MYBUFFER;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	or	ch, 2
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx
$L66127:

; 530  : 	if (tif->tif_rawdata == NULL) {

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+472], 0
	jne	SHORT $L66134

; 531  : 		TIFFError(module,
; 532  : 		    "%s: No space for data buffer at scanline %ld",
; 533  : 		    tif->tif_name, (long) tif->tif_row);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG66136
	push	OFFSET FLAT:_?module@?1??TIFFReadBufferSetup@@9@9
	call	_TIFFError
	add	esp, 16					; 00000010H

; 534  : 		tif->tif_rawdatasize = 0;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+476], 0

; 535  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L66119
$L66134:

; 537  : 	return (1);

	mov	eax, 1
$L66119:

; 538  : }

	pop	ebp
	ret	0
_TIFFReadBufferSetup ENDP
_tif$ = 8
_strip$ = 12
_td$ = -4
_TIFFStartStrip PROC NEAR

; 546  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 547  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 548  : 
; 549  : 	if ((tif->tif_flags & TIFF_CODERSETUP) == 0) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 32					; 00000020H
	test	edx, edx
	jne	SHORT $L66143

; 550  : 		if (!(*tif->tif_setupdecode)(tif))

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+396]
	add	esp, 4
	test	eax, eax
	jne	SHORT $L66144

; 551  : 			return (0);

	xor	eax, eax
	jmp	$L66141
$L66144:

; 552  : 		tif->tif_flags |= TIFF_CODERSETUP;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	or	al, 32					; 00000020H
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+12], eax
$L66143:

; 554  : 	tif->tif_curstrip = strip;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _strip$[ebp]
	mov	DWORD PTR [edx+364], eax

; 555  : 	tif->tif_row = (strip % td->td_stripsperimage) * td->td_rowsperstrip;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _strip$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+176]
	mov	eax, DWORD PTR _td$[ebp]
	imul	edx, DWORD PTR [eax+56]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+356], edx

; 556  : 	tif->tif_rawcp = tif->tif_rawdata;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+472]
	mov	DWORD PTR [edx+480], ecx

; 557  : 	tif->tif_rawcc = td->td_stripbytecount[strip];

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+188]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _strip$[ebp]
	mov	eax, DWORD PTR [eax+edx*4]
	mov	DWORD PTR [ecx+484], eax

; 558  : 	return ((*tif->tif_predecode)(tif,
; 559  : 			(tsample_t)(strip / td->td_stripsperimage)));

	mov	ecx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _strip$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+176]
	push	eax
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+400]
	add	esp, 8
$L66141:

; 560  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFStartStrip ENDP
_tif$ = 8
_tile$ = 12
_td$ = -4
_TIFFStartTile PROC NEAR

; 568  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 569  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 570  : 
; 571  : 	if ((tif->tif_flags & TIFF_CODERSETUP) == 0) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 32					; 00000020H
	test	edx, edx
	jne	SHORT $L66152

; 572  : 		if (!(*tif->tif_setupdecode)(tif))

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+396]
	add	esp, 4
	test	eax, eax
	jne	SHORT $L66153

; 573  : 			return (0);

	xor	eax, eax
	jmp	$L66150
$L66153:

; 574  : 		tif->tif_flags |= TIFF_CODERSETUP;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	or	al, 32					; 00000020H
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+12], eax
$L66152:

; 576  : 	tif->tif_curtile = tile;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tile$[ebp]
	mov	DWORD PTR [edx+388], eax

; 577  : 	tif->tif_row =
; 578  : 	    (tile % TIFFhowmany(td->td_imagewidth, td->td_tilewidth)) *
; 579  : 		td->td_tilelength;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	lea	eax, DWORD PTR [ecx+edx-1]
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+24]
	mov	ecx, eax
	mov	eax, DWORD PTR _tile$[ebp]
	xor	edx, edx
	div	ecx
	mov	eax, DWORD PTR _td$[ebp]
	imul	edx, DWORD PTR [eax+28]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+356], edx

; 580  : 	tif->tif_col =
; 581  : 	    (tile % TIFFhowmany(td->td_imagelength, td->td_tilelength)) *
; 582  : 		td->td_tilewidth;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+28]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	lea	eax, DWORD PTR [edx+eax-1]
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+28]
	mov	ecx, eax
	mov	eax, DWORD PTR _tile$[ebp]
	xor	edx, edx
	div	ecx
	mov	eax, DWORD PTR _td$[ebp]
	imul	edx, DWORD PTR [eax+24]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+384], edx

; 583  : 	tif->tif_rawcp = tif->tif_rawdata;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+472]
	mov	DWORD PTR [edx+480], ecx

; 584  : 	tif->tif_rawcc = td->td_stripbytecount[tile];

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+188]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _tile$[ebp]
	mov	eax, DWORD PTR [eax+edx*4]
	mov	DWORD PTR [ecx+484], eax

; 585  : 	return ((*tif->tif_predecode)(tif,
; 586  : 			(tsample_t)(tile/td->td_stripsperimage)));

	mov	ecx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _tile$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+176]
	push	eax
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+400]
	add	esp, 8
$L66150:

; 587  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFStartTile ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+3
$SG66167 DB	'File not open for reading', 00H
	ORG $+2
$SG66169 DB	'Can not read tiles from a stripped image', 00H
	ORG $+3
$SG66170 DB	'Can not read scanlines from a tiled image', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_tiles$ = 12
_TIFFCheckRead PROC NEAR

; 591  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 592  : 	if (tif->tif_mode == O_WRONLY) {

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+8], 1
	jne	SHORT $L66166

; 593  : 		TIFFError(tif->tif_name, "File not open for reading");

	push	OFFSET FLAT:$SG66167
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 8

; 594  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L66165
$L66166:

; 596  : 	if (tiles ^ isTiled(tif)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 1024				; 00000400H
	neg	ecx
	sbb	ecx, ecx
	neg	ecx
	mov	edx, DWORD PTR _tiles$[ebp]
	xor	edx, ecx
	test	edx, edx
	je	SHORT $L66168

; 597  : 		TIFFError(tif->tif_name, tiles ?
; 598  : 		    "Can not read tiles from a stripped image" :
; 599  : 		    "Can not read scanlines from a tiled image");

	cmp	DWORD PTR _tiles$[ebp], 0
	je	SHORT $L66234
	mov	DWORD PTR -4+[ebp], OFFSET FLAT:$SG66169
	jmp	SHORT $L66235
$L66234:
	mov	DWORD PTR -4+[ebp], OFFSET FLAT:$SG66170
$L66235:
	mov	eax, DWORD PTR -4+[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 8

; 600  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L66165
$L66168:

; 602  : 	return (1);

	mov	eax, 1
$L66165:

; 603  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFCheckRead ENDP
_TEXT	ENDS
PUBLIC	__TIFFNoPostDecode
_TEXT	SEGMENT
__TIFFNoPostDecode PROC NEAR

; 607  : {

	push	ebp
	mov	ebp, esp

; 608  :     (void) tif; (void) buf; (void) cc;
; 609  : }

	pop	ebp
	ret	0
__TIFFNoPostDecode ENDP
_TEXT	ENDS
PUBLIC	__TIFFSwab16BitData
EXTRN	__assert:NEAR
EXTRN	_TIFFSwabArrayOfShort:NEAR
_DATA	SEGMENT
	ORG $+2
$SG66190 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_read.c', 00H
	ORG $+3
$SG66191 DB	'(cc & 1) == 0', 00H
_DATA	ENDS
_TEXT	SEGMENT
_buf$ = 12
_cc$ = 16
__TIFFSwab16BitData PROC NEAR

; 613  : {

	push	ebp
	mov	ebp, esp

; 614  :     (void) tif;
; 615  :     assert((cc & 1) == 0);

	mov	eax, DWORD PTR _cc$[ebp]
	and	eax, 1
	test	eax, eax
	je	SHORT $L66238
	push	615					; 00000267H
	push	OFFSET FLAT:$SG66190
	push	OFFSET FLAT:$SG66191
	call	__assert
	add	esp, 12					; 0000000cH
$L66238:

; 616  :     TIFFSwabArrayOfShort((uint16*) buf, cc/2);

	mov	eax, DWORD PTR _cc$[ebp]
	cdq
	sub	eax, edx
	sar	eax, 1
	push	eax
	mov	edx, DWORD PTR _buf$[ebp]
	push	edx
	call	_TIFFSwabArrayOfShort
	add	esp, 8

; 617  : }

	pop	ebp
	ret	0
__TIFFSwab16BitData ENDP
_TEXT	ENDS
PUBLIC	__TIFFSwab32BitData
EXTRN	_TIFFSwabArrayOfLong:NEAR
_DATA	SEGMENT
	ORG $+2
$SG66202 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_read.c', 00H
	ORG $+3
$SG66203 DB	'(cc & 3) == 0', 00H
_DATA	ENDS
_TEXT	SEGMENT
_buf$ = 12
_cc$ = 16
__TIFFSwab32BitData PROC NEAR

; 621  : {

	push	ebp
	mov	ebp, esp

; 622  :     (void) tif;
; 623  :     assert((cc & 3) == 0);

	mov	eax, DWORD PTR _cc$[ebp]
	and	eax, 3
	test	eax, eax
	je	SHORT $L66240
	push	623					; 0000026fH
	push	OFFSET FLAT:$SG66202
	push	OFFSET FLAT:$SG66203
	call	__assert
	add	esp, 12					; 0000000cH
$L66240:

; 624  :     TIFFSwabArrayOfLong((uint32*) buf, cc/4);

	mov	eax, DWORD PTR _cc$[ebp]
	cdq
	and	edx, 3
	add	eax, edx
	sar	eax, 2
	push	eax
	mov	edx, DWORD PTR _buf$[ebp]
	push	edx
	call	_TIFFSwabArrayOfLong
	add	esp, 8

; 625  : }

	pop	ebp
	ret	0
__TIFFSwab32BitData ENDP
_TEXT	ENDS
PUBLIC	__TIFFSwab64BitData
EXTRN	_TIFFSwabArrayOfDouble:NEAR
_DATA	SEGMENT
	ORG $+2
$SG66214 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_read.c', 00H
	ORG $+3
$SG66215 DB	'(cc & 7) == 0', 00H
_DATA	ENDS
_TEXT	SEGMENT
_buf$ = 12
_cc$ = 16
__TIFFSwab64BitData PROC NEAR

; 629  : {

	push	ebp
	mov	ebp, esp

; 630  :     (void) tif;
; 631  :     assert((cc & 7) == 0);

	mov	eax, DWORD PTR _cc$[ebp]
	and	eax, 7
	test	eax, eax
	je	SHORT $L66242
	push	631					; 00000277H
	push	OFFSET FLAT:$SG66214
	push	OFFSET FLAT:$SG66215
	call	__assert
	add	esp, 12					; 0000000cH
$L66242:

; 632  :     TIFFSwabArrayOfDouble((double*) buf, cc/8);

	mov	eax, DWORD PTR _cc$[ebp]
	cdq
	and	edx, 7
	add	eax, edx
	sar	eax, 3
	push	eax
	mov	edx, DWORD PTR _buf$[ebp]
	push	edx
	call	_TIFFSwabArrayOfDouble
	add	esp, 8

; 633  : }

	pop	ebp
	ret	0
__TIFFSwab64BitData ENDP
_TEXT	ENDS
END
