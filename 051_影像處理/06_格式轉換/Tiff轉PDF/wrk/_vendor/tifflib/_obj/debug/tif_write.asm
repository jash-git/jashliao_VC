	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_write.c
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
_?module@?1??TIFFWriteScanline@@9@9 DB 'TIFFWriteScanline', 00H
	ORG $+2
_?module@?1??TIFFWriteEncodedStrip@@9@9 DB 'TIFFWriteEncodedStrip', 00H
	ORG $+2
_?module@?1??TIFFWriteRawStrip@@9@9 DB 'TIFFWriteRawStrip', 00H
	ORG $+2
_?module@?1??TIFFWriteEncodedTile@@9@9 DB 'TIFFWriteEncodedTile', 00H
	ORG $+3
_?module@?1??TIFFWriteRawTile@@9@9 DB 'TIFFWriteRawTile', 00H
	ORG $+3
_?module@?1??TIFFWriteBufferSetup@@9@9 DB 'TIFFWriteBufferSetup', 00H
	ORG $+3
_?module@?1??TIFFAppendToStrip@@9@9 DB 'TIFFAppendToStrip', 00H
CONST	ENDS
PUBLIC	_TIFFWriteBufferSetup
PUBLIC	_TIFFWriteCheck
PUBLIC	_TIFFWriteScanline
EXTRN	_TIFFFlushData:NEAR
EXTRN	_TIFFError:NEAR
_DATA	SEGMENT
$SG65826 DB	'Can not change "ImageLength" when using separate planes', 00H
$SG65829 DB	'%d: Sample out of range, max %d', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_buf$ = 12
_row$ = 16
_sample$ = 20
_td$ = -8
_status$ = -16
_imagegrew$ = -4
_strip$ = -12
_TIFFWriteScanline PROC NEAR

; 54   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H
	push	esi

; 55   : 	static const char module[] = "TIFFWriteScanline";
; 56   : 	register TIFFDirectory *td;
; 57   : 	int status, imagegrew = 0;

	mov	DWORD PTR _imagegrew$[ebp], 0

; 58   : 	tstrip_t strip;
; 59   : 
; 60   : 	if (!WRITECHECKSTRIPS(tif, module))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 64					; 00000040H
	test	ecx, ecx
	jne	SHORT $L65819
	push	OFFSET FLAT:_?module@?1??TIFFWriteScanline@@9@9
	push	0
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteCheck
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65819

; 61   : 		return (-1);

	or	eax, -1
	jmp	$L65812
$L65819:

; 62   : 	/*
; 63   : 	 * Handle delayed allocation of data buffer.  This
; 64   : 	 * permits it to be sized more intelligently (using
; 65   : 	 * directory information).
; 66   : 	 */
; 67   : 	if (!BUFFERCHECK(tif))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 16					; 00000010H
	test	ecx, ecx
	je	SHORT $L65823
	mov	edx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [edx+472], 0
	jne	SHORT $L65822
$L65823:
	push	-1
	push	0
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFWriteBufferSetup
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65822

; 68   : 		return (-1);

	or	eax, -1
	jmp	$L65812
$L65822:

; 69   : 	td = &tif->tif_dir;

	mov	ecx, DWORD PTR _tif$[ebp]
	add	ecx, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], ecx

; 70   : 	/*
; 71   : 	 * Extend image length if needed
; 72   : 	 * (but only for PlanarConfig=1).
; 73   : 	 */
; 74   : 	if (row >= td->td_imagelength) {	/* extend image */

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	cmp	eax, DWORD PTR [edx+16]
	jb	SHORT $L65824

; 75   : 		if (td->td_planarconfig == PLANARCONFIG_SEPARATE) {

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+90]
	cmp	edx, 2
	jne	SHORT $L65825

; 76   : 			TIFFError(tif->tif_name,
; 77   : 		"Can not change \"ImageLength\" when using separate planes");

	push	OFFSET FLAT:$SG65826
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 8

; 78   : 			return (-1);

	or	eax, -1
	jmp	$L65812
$L65825:

; 80   : 		td->td_imagelength = row+1;

	mov	edx, DWORD PTR _row$[ebp]
	add	edx, 1
	mov	eax, DWORD PTR _td$[ebp]
	mov	DWORD PTR [eax+16], edx

; 81   : 		imagegrew = 1;

	mov	DWORD PTR _imagegrew$[ebp], 1
$L65824:

; 83   : 	/*
; 84   : 	 * Calculate strip and check for crossings.
; 85   : 	 */
; 86   : 	if (td->td_planarconfig == PLANARCONFIG_SEPARATE) {

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+90]
	cmp	edx, 2
	jne	SHORT $L65827

; 87   : 		if (sample >= td->td_samplesperpixel) {

	mov	eax, DWORD PTR _sample$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+54]
	cmp	eax, edx
	jl	SHORT $L65828

; 88   : 			TIFFError(tif->tif_name,
; 89   : 			    "%d: Sample out of range, max %d",
; 90   : 			    sample, td->td_samplesperpixel);

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+54]
	push	ecx
	mov	edx, DWORD PTR _sample$[ebp]
	and	edx, 65535				; 0000ffffH
	push	edx
	push	OFFSET FLAT:$SG65829
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 16					; 00000010H

; 91   : 			return (-1);

	or	eax, -1
	jmp	$L65812
$L65828:

; 93   : 		strip = sample*td->td_stripsperimage + row/td->td_rowsperstrip;

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

; 94   : 	} else

	jmp	SHORT $L65830
$L65827:

; 95   : 		strip = row / td->td_rowsperstrip;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+56]
	mov	DWORD PTR _strip$[ebp], eax
$L65830:

; 96   : 	if (strip != tif->tif_curstrip) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _strip$[ebp]
	cmp	eax, DWORD PTR [edx+364]
	je	$L65831

; 97   : 		/*
; 98   : 		 * Changing strips -- flush any data present.
; 99   : 		 */
; 100  : 		if (!TIFFFlushData(tif))

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFlushData
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65832

; 101  : 			return (-1);

	or	eax, -1
	jmp	$L65812
$L65832:

; 102  : 		tif->tif_curstrip = strip;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _strip$[ebp]
	mov	DWORD PTR [edx+364], eax

; 103  : 		/*
; 104  : 		 * Watch out for a growing image.  The value of
; 105  : 		 * strips/image will initially be 1 (since it
; 106  : 		 * can't be deduced until the imagelength is known).
; 107  : 		 */
; 108  : 		if (strip >= td->td_stripsperimage && imagegrew)

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _strip$[ebp]
	cmp	edx, DWORD PTR [ecx+176]
	jb	SHORT $L65833
	cmp	DWORD PTR _imagegrew$[ebp], 0
	je	SHORT $L65833

; 109  : 			td->td_stripsperimage =
; 110  : 			    TIFFhowmany(td->td_imagelength,td->td_rowsperstrip);

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+16]
	lea	eax, DWORD PTR [eax+ecx-1]
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+56]
	mov	edx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [edx+176], eax
$L65833:

; 111  : 		tif->tif_row =
; 112  : 		    (strip % td->td_stripsperimage) * td->td_rowsperstrip;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _strip$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+176]
	mov	eax, DWORD PTR _td$[ebp]
	imul	edx, DWORD PTR [eax+56]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+356], edx

; 113  : 		if ((tif->tif_flags & TIFF_CODERSETUP) == 0) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 32					; 00000020H
	test	eax, eax
	jne	SHORT $L65837

; 114  : 			if (!(*tif->tif_setupencode)(tif))

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+404]
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65838

; 115  : 				return (-1);

	or	eax, -1
	jmp	$L65812
$L65838:

; 116  : 			tif->tif_flags |= TIFF_CODERSETUP;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	or	ecx, 32					; 00000020H
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx
$L65837:

; 118  : 		if (!(*tif->tif_preencode)(tif, sample))

	mov	ax, WORD PTR _sample$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+408]
	add	esp, 8
	test	eax, eax
	jne	SHORT $L65839

; 119  : 			return (-1);

	or	eax, -1
	jmp	$L65812
$L65839:

; 120  : 		tif->tif_flags |= TIFF_POSTENCODE;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	or	ch, 16					; 00000010H
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx
$L65831:

; 122  : 	/*
; 123  : 	 * Check strip array to make sure there's space.
; 124  : 	 * We don't support dynamically growing files that
; 125  : 	 * have data organized in separate bitplanes because
; 126  : 	 * it's too painful.  In that case we require that
; 127  : 	 * the imagelength be set properly before the first
; 128  : 	 * write (so that the strips array will be fully
; 129  : 	 * allocated above).
; 130  : 	 */
; 131  : 	if (strip >= td->td_nstrips && !TIFFGrowStrips(tif, 1, module))

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _strip$[ebp]
	cmp	ecx, DWORD PTR [eax+180]
	jb	SHORT $L65840
	push	OFFSET FLAT:_?module@?1??TIFFWriteScanline@@9@9
	push	1
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFGrowStrips
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65840

; 132  : 		return (-1);

	or	eax, -1
	jmp	$L65812
$L65840:

; 133  : 	/*
; 134  : 	 * Ensure the write is either sequential or at the
; 135  : 	 * beginning of a strip (or that we can randomly
; 136  : 	 * access the data -- i.e. no encoding).
; 137  : 	 */
; 138  : 	if (row != tif->tif_row) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _row$[ebp]
	cmp	ecx, DWORD PTR [eax+356]
	je	SHORT $L65841

; 139  : 		if (row < tif->tif_row) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	cmp	eax, DWORD PTR [edx+356]
	jae	SHORT $L65842

; 140  : 			/*
; 141  : 			 * Moving backwards within the same strip:
; 142  : 			 * backup to the start and then decode
; 143  : 			 * forward (below).
; 144  : 			 */
; 145  : 			tif->tif_row = (strip % td->td_stripsperimage) *
; 146  : 			    td->td_rowsperstrip;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _strip$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+176]
	mov	eax, DWORD PTR _td$[ebp]
	imul	edx, DWORD PTR [eax+56]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+356], edx

; 147  : 			tif->tif_rawcp = tif->tif_rawdata;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+472]
	mov	DWORD PTR [edx+480], ecx
$L65842:

; 149  : 		/*
; 150  : 		 * Seek forward to the desired row.
; 151  : 		 */
; 152  : 		if (!(*tif->tif_seek)(tif, row - tif->tif_row))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	sub	eax, DWORD PTR [edx+356]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+444]
	add	esp, 8
	test	eax, eax
	jne	SHORT $L65843

; 153  : 			return (-1);

	or	eax, -1
	jmp	SHORT $L65812
$L65843:

; 154  : 		tif->tif_row = row;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _row$[ebp]
	mov	DWORD PTR [eax+356], ecx
$L65841:

; 156  : 	status = (*tif->tif_encoderow)(tif, (tidata_t) buf,
; 157  : 	    tif->tif_scanlinesize, sample);

	mov	dx, WORD PTR _sample$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+464]
	push	ecx
	mov	edx, DWORD PTR _buf$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+420]
	add	esp, 16					; 00000010H
	mov	DWORD PTR _status$[ebp], eax

; 158  : 	tif->tif_row++;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+356]
	add	eax, 1
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+356], eax

; 159  : 	return (status);

	mov	eax, DWORD PTR _status$[ebp]
$L65812:

; 160  : }

	pop	esi
	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFWriteScanline ENDP
_TEXT	ENDS
PUBLIC	_TIFFWriteEncodedStrip
EXTRN	_TIFFReverseBits:NEAR
_DATA	SEGMENT
$SG65862 DB	'Can not grow image by strips when using separate planes', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_strip$ = 12
_data$ = 16
_cc$ = 20
_td$ = -8
_sample$ = -4
_TIFFWriteEncodedStrip PROC NEAR

; 171  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 172  : 	static const char module[] = "TIFFWriteEncodedStrip";
; 173  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 174  : 	tsample_t sample;
; 175  : 
; 176  : 	if (!WRITECHECKSTRIPS(tif, module))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 64					; 00000040H
	test	edx, edx
	jne	SHORT $L65858
	push	OFFSET FLAT:_?module@?1??TIFFWriteEncodedStrip@@9@9
	push	0
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFWriteCheck
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65858

; 177  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	$L65853
$L65858:

; 178  : 	/*
; 179  : 	 * Check strip array to make sure there's space.
; 180  : 	 * We don't support dynamically growing files that
; 181  : 	 * have data organized in separate bitplanes because
; 182  : 	 * it's too painful.  In that case we require that
; 183  : 	 * the imagelength be set properly before the first
; 184  : 	 * write (so that the strips array will be fully
; 185  : 	 * allocated above).
; 186  : 	 */
; 187  : 	if (strip >= td->td_nstrips) {

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _strip$[ebp]
	cmp	edx, DWORD PTR [ecx+180]
	jb	SHORT $L65860

; 188  : 		if (td->td_planarconfig == PLANARCONFIG_SEPARATE) {

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+90]
	cmp	ecx, 2
	jne	SHORT $L65861

; 189  : 			TIFFError(tif->tif_name,
; 190  : 		"Can not grow image by strips when using separate planes");

	push	OFFSET FLAT:$SG65862
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 8

; 191  : 			return ((tsize_t) -1);

	or	eax, -1
	jmp	$L65853
$L65861:

; 193  : 		if (!TIFFGrowStrips(tif, 1, module))

	push	OFFSET FLAT:_?module@?1??TIFFWriteEncodedStrip@@9@9
	push	1
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFGrowStrips
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65864

; 194  : 			return ((tsize_t) -1);

	or	eax, -1
	jmp	$L65853
$L65864:

; 195  : 		td->td_stripsperimage =
; 196  : 		    TIFFhowmany(td->td_imagelength, td->td_rowsperstrip);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	lea	eax, DWORD PTR [edx+eax-1]
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+56]
	mov	edx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [edx+176], eax
$L65860:

; 198  : 	/*
; 199  : 	 * Handle delayed allocation of data buffer.  This
; 200  : 	 * permits it to be sized according to the directory
; 201  : 	 * info.
; 202  : 	 */
; 203  : 	if (!BUFFERCHECK(tif))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 16					; 00000010H
	test	ecx, ecx
	je	SHORT $L65872
	mov	edx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [edx+472], 0
	jne	SHORT $L65871
$L65872:
	push	-1
	push	0
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFWriteBufferSetup
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65871

; 204  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	$L65853
$L65871:

; 205  : 	tif->tif_curstrip = strip;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _strip$[ebp]
	mov	DWORD PTR [ecx+364], edx

; 206  : 	tif->tif_row = (strip % td->td_stripsperimage) * td->td_rowsperstrip;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _strip$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+176]
	mov	eax, DWORD PTR _td$[ebp]
	imul	edx, DWORD PTR [eax+56]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+356], edx

; 207  : 	if ((tif->tif_flags & TIFF_CODERSETUP) == 0) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 32					; 00000020H
	test	eax, eax
	jne	SHORT $L65874

; 208  : 		if (!(*tif->tif_setupencode)(tif))

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+404]
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65875

; 209  : 			return ((tsize_t) -1);

	or	eax, -1
	jmp	$L65853
$L65875:

; 210  : 		tif->tif_flags |= TIFF_CODERSETUP;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	or	ecx, 32					; 00000020H
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx
$L65874:

; 212  :         
; 213  : #ifdef REWRITE_HACK        
; 214  : 	tif->tif_rawcc = 0;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+484], 0

; 215  : 	tif->tif_rawcp = tif->tif_rawdata;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+472]
	mov	DWORD PTR [ecx+480], eax

; 216  : 
; 217  :         if( td->td_stripbytecount[strip] > 0 )

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+188]
	mov	eax, DWORD PTR _strip$[ebp]
	cmp	DWORD PTR [edx+eax*4], 0
	jbe	SHORT $L65877

; 219  :             /* if we are writing over existing tiles, zero length. */
; 220  :             td->td_stripbytecount[strip] = 0;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+188]
	mov	eax, DWORD PTR _strip$[ebp]
	mov	DWORD PTR [edx+eax*4], 0

; 221  : 
; 222  :             /* this forces TIFFAppendToStrip() to do a seek */
; 223  :             tif->tif_curoff = 0;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+368], 0
$L65877:

; 225  : #endif
; 226  :         
; 227  : 	tif->tif_flags &= ~TIFF_POSTENCODE;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	ah, -17					; ffffffefH
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+12], eax

; 228  : 	sample = (tsample_t)(strip / td->td_stripsperimage);

	mov	ecx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _strip$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+176]
	mov	WORD PTR _sample$[ebp], ax

; 229  : 	if (!(*tif->tif_preencode)(tif, sample))

	mov	dx, WORD PTR _sample$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+408]
	add	esp, 8
	test	eax, eax
	jne	SHORT $L65879

; 230  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	$L65853
$L65879:

; 231  : 	if (!(*tif->tif_encodestrip)(tif, (tidata_t) data, cc, sample))

	mov	dx, WORD PTR _sample$[ebp]
	push	edx
	mov	eax, DWORD PTR _cc$[ebp]
	push	eax
	mov	ecx, DWORD PTR _data$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+428]
	add	esp, 16					; 00000010H
	test	eax, eax
	jne	SHORT $L65882

; 232  : 		return ((tsize_t) 0);

	xor	eax, eax
	jmp	$L65853
$L65882:

; 233  : 	if (!(*tif->tif_postencode)(tif))

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+412]
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65884

; 234  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	$L65853
$L65884:

; 235  : 	if (!isFillOrder(tif, td->td_fillorder) &&
; 236  : 	    (tif->tif_flags & TIFF_NOBITREV) == 0)

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+50]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, ecx
	test	eax, eax
	jne	SHORT $L65886
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 256				; 00000100H
	test	edx, edx
	jne	SHORT $L65886

; 237  : 		TIFFReverseBits(tif->tif_rawdata, tif->tif_rawcc);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+484]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+472]
	push	eax
	call	_TIFFReverseBits
	add	esp, 8
$L65886:

; 238  : 	if (tif->tif_rawcc > 0 &&
; 239  : 	    !TIFFAppendToStrip(tif, strip, tif->tif_rawdata, tif->tif_rawcc))

	mov	ecx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [ecx+484], 0
	jle	SHORT $L65887
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+484]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+472]
	push	edx
	mov	eax, DWORD PTR _strip$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFAppendToStrip
	add	esp, 16					; 00000010H
	test	eax, eax
	jne	SHORT $L65887

; 240  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	SHORT $L65853
$L65887:

; 241  : 	tif->tif_rawcc = 0;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], 0

; 242  : 	tif->tif_rawcp = tif->tif_rawdata;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+472]
	mov	DWORD PTR [eax+480], edx

; 243  : 	return (cc);

	mov	eax, DWORD PTR _cc$[ebp]
$L65853:

; 244  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFWriteEncodedStrip ENDP
_TEXT	ENDS
PUBLIC	_TIFFWriteRawStrip
_DATA	SEGMENT
$SG65905 DB	'Can not grow image by strips when using separate planes', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_strip$ = 12
_data$ = 16
_cc$ = 20
_td$ = -4
_TIFFWriteRawStrip PROC NEAR

; 255  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 256  : 	static const char module[] = "TIFFWriteRawStrip";
; 257  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 258  : 
; 259  : 	if (!WRITECHECKSTRIPS(tif, module))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 64					; 00000040H
	test	edx, edx
	jne	SHORT $L65901
	push	OFFSET FLAT:_?module@?1??TIFFWriteRawStrip@@9@9
	push	0
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFWriteCheck
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65901

; 260  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	$L65897
$L65901:

; 261  : 	/*
; 262  : 	 * Check strip array to make sure there's space.
; 263  : 	 * We don't support dynamically growing files that
; 264  : 	 * have data organized in separate bitplanes because
; 265  : 	 * it's too painful.  In that case we require that
; 266  : 	 * the imagelength be set properly before the first
; 267  : 	 * write (so that the strips array will be fully
; 268  : 	 * allocated above).
; 269  : 	 */
; 270  : 	if (strip >= td->td_nstrips) {

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _strip$[ebp]
	cmp	edx, DWORD PTR [ecx+180]
	jb	SHORT $L65911

; 271  : 		if (td->td_planarconfig == PLANARCONFIG_SEPARATE) {

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+90]
	cmp	ecx, 2
	jne	SHORT $L65904

; 272  : 			TIFFError(tif->tif_name,
; 273  : 		"Can not grow image by strips when using separate planes");

	push	OFFSET FLAT:$SG65905
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 8

; 274  : 			return ((tsize_t) -1);

	or	eax, -1
	jmp	$L65897
$L65904:

; 276  : 		/*
; 277  : 		 * Watch out for a growing image.  The value of
; 278  : 		 * strips/image will initially be 1 (since it
; 279  : 		 * can't be deduced until the imagelength is known).
; 280  : 		 */
; 281  : 		if (strip >= td->td_stripsperimage)

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _strip$[ebp]
	cmp	edx, DWORD PTR [ecx+176]
	jb	SHORT $L65907

; 282  : 			td->td_stripsperimage =
; 283  : 			    TIFFhowmany(td->td_imagelength,td->td_rowsperstrip);

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+16]
	lea	eax, DWORD PTR [eax+ecx-1]
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+56]
	mov	edx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [edx+176], eax
$L65907:

; 284  : 		if (!TIFFGrowStrips(tif, 1, module))

	push	OFFSET FLAT:_?module@?1??TIFFWriteRawStrip@@9@9
	push	1
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGrowStrips
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65911

; 285  : 			return ((tsize_t) -1);

	or	eax, -1
	jmp	SHORT $L65897
$L65911:

; 287  : 	tif->tif_curstrip = strip;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _strip$[ebp]
	mov	DWORD PTR [ecx+364], edx

; 288  : 	tif->tif_row = (strip % td->td_stripsperimage) * td->td_rowsperstrip;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _strip$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+176]
	mov	eax, DWORD PTR _td$[ebp]
	imul	edx, DWORD PTR [eax+56]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+356], edx

; 289  : 	return (TIFFAppendToStrip(tif, strip, (tidata_t) data, cc) ?
; 290  : 	    cc : (tsize_t) -1);

	mov	edx, DWORD PTR _cc$[ebp]
	push	edx
	mov	eax, DWORD PTR _data$[ebp]
	push	eax
	mov	ecx, DWORD PTR _strip$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFAppendToStrip
	add	esp, 16					; 00000010H
	test	eax, eax
	je	SHORT $L66136
	mov	eax, DWORD PTR _cc$[ebp]
	mov	DWORD PTR -8+[ebp], eax
	jmp	SHORT $L66137
$L66136:
	mov	DWORD PTR -8+[ebp], -1
$L66137:
	mov	eax, DWORD PTR -8+[ebp]
$L65897:

; 291  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFWriteRawStrip ENDP
_TEXT	ENDS
PUBLIC	_TIFFWriteTile
PUBLIC	_TIFFWriteEncodedTile
EXTRN	_TIFFComputeTile:NEAR
EXTRN	_TIFFCheckTile:NEAR
_TEXT	SEGMENT
_tif$ = 8
_buf$ = 12
_x$ = 16
_y$ = 20
_z$ = 24
_s$ = 28
_TIFFWriteTile PROC NEAR

; 300  : {

	push	ebp
	mov	ebp, esp

; 301  : 	if (!TIFFCheckTile(tif, x, y, z, s))

	mov	ax, WORD PTR _s$[ebp]
	push	eax
	mov	ecx, DWORD PTR _z$[ebp]
	push	ecx
	mov	edx, DWORD PTR _y$[ebp]
	push	edx
	mov	eax, DWORD PTR _x$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFCheckTile
	add	esp, 20					; 00000014H
	test	eax, eax
	jne	SHORT $L65928

; 302  : 		return (-1);

	or	eax, -1
	jmp	SHORT $L65927
$L65928:

; 303  : 	/*
; 304  : 	 * NB: A tile size of -1 is used instead of tif_tilesize knowing
; 305  : 	 *     that TIFFWriteEncodedTile will clamp this to the tile size.
; 306  : 	 *     This is done because the tile size may not be defined until
; 307  : 	 *     after the output buffer is setup in TIFFWriteBufferSetup.
; 308  : 	 */
; 309  : 	return (TIFFWriteEncodedTile(tif,
; 310  : 	    TIFFComputeTile(tif, x, y, z, s), buf, (tsize_t) -1));

	push	-1
	mov	edx, DWORD PTR _buf$[ebp]
	push	edx
	mov	ax, WORD PTR _s$[ebp]
	push	eax
	mov	ecx, DWORD PTR _z$[ebp]
	push	ecx
	mov	edx, DWORD PTR _y$[ebp]
	push	edx
	mov	eax, DWORD PTR _x$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFComputeTile
	add	esp, 20					; 00000014H
	push	eax
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteEncodedTile
	add	esp, 16					; 00000010H
$L65927:

; 311  : }

	pop	ebp
	ret	0
_TIFFWriteTile ENDP
_TEXT	ENDS
_DATA	SEGMENT
$SG65948 DB	'%s: Tile %lu out of range, max %lu', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_tile$ = 12
_data$ = 16
_cc$ = 20
_td$ = -8
_sample$ = -4
_TIFFWriteEncodedTile PROC NEAR

; 327  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 328  : 	static const char module[] = "TIFFWriteEncodedTile";
; 329  : 	TIFFDirectory *td;
; 330  : 	tsample_t sample;
; 331  : 
; 332  : 	if (!WRITECHECKTILES(tif, module))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 64					; 00000040H
	test	ecx, ecx
	jne	SHORT $L65943
	push	OFFSET FLAT:_?module@?1??TIFFWriteEncodedTile@@9@9
	push	1
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteCheck
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65943

; 333  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	$L65938
$L65943:

; 334  : 	td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 335  : 	if (tile >= td->td_nstrips) {

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _tile$[ebp]
	cmp	edx, DWORD PTR [ecx+180]
	jb	SHORT $L65945

; 336  : 		TIFFError(module, "%s: Tile %lu out of range, max %lu",
; 337  : 		    tif->tif_name, (u_long) tile, (u_long) td->td_nstrips);

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+180]
	push	ecx
	mov	edx, DWORD PTR _tile$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG65948
	push	OFFSET FLAT:_?module@?1??TIFFWriteEncodedTile@@9@9
	call	_TIFFError
	add	esp, 20					; 00000014H

; 338  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	$L65938
$L65945:

; 340  : 	/*
; 341  : 	 * Handle delayed allocation of data buffer.  This
; 342  : 	 * permits it to be sized more intelligently (using
; 343  : 	 * directory information).
; 344  : 	 */
; 345  : 	if (!BUFFERCHECK(tif))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 16					; 00000010H
	test	eax, eax
	je	SHORT $L65953
	mov	ecx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [ecx+472], 0
	jne	SHORT $L65952
$L65953:
	push	-1
	push	0
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteBufferSetup
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65952

; 346  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	$L65938
$L65952:

; 347  : 	tif->tif_curtile = tile;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _tile$[ebp]
	mov	DWORD PTR [eax+388], ecx

; 348  : 
; 349  : #ifdef REWRITE_HACK        
; 350  : 	tif->tif_rawcc = 0;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], 0

; 351  : 	tif->tif_rawcp = tif->tif_rawdata;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+472]
	mov	DWORD PTR [eax+480], edx

; 352  : 
; 353  :         if( td->td_stripbytecount[tile] > 0 )

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+188]
	mov	edx, DWORD PTR _tile$[ebp]
	cmp	DWORD PTR [ecx+edx*4], 0
	jbe	SHORT $L65955

; 355  :             /* if we are writing over existing tiles, zero length. */
; 356  :             td->td_stripbytecount[tile] = 0;

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+188]
	mov	edx, DWORD PTR _tile$[ebp]
	mov	DWORD PTR [ecx+edx*4], 0

; 357  : 
; 358  :             /* this forces TIFFAppendToStrip() to do a seek */
; 359  :             tif->tif_curoff = 0;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+368], 0
$L65955:

; 361  : #endif
; 362  :         
; 363  : 	/* 
; 364  : 	 * Compute tiles per row & per column to compute
; 365  : 	 * current row and column
; 366  : 	 */
; 367  : 	tif->tif_row = (tile % TIFFhowmany(td->td_imagelength, td->td_tilelength))
; 368  : 		* td->td_tilelength;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	lea	eax, DWORD PTR [ecx+edx-1]
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+28]
	mov	ecx, eax
	mov	eax, DWORD PTR _tile$[ebp]
	xor	edx, edx
	div	ecx
	mov	eax, DWORD PTR _td$[ebp]
	imul	edx, DWORD PTR [eax+28]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+356], edx

; 369  : 	tif->tif_col = (tile % TIFFhowmany(td->td_imagewidth, td->td_tilewidth))
; 370  : 		* td->td_tilewidth;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+24]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	lea	eax, DWORD PTR [edx+eax-1]
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+24]
	mov	ecx, eax
	mov	eax, DWORD PTR _tile$[ebp]
	xor	edx, edx
	div	ecx
	mov	eax, DWORD PTR _td$[ebp]
	imul	edx, DWORD PTR [eax+24]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+384], edx

; 371  : 
; 372  : 	if ((tif->tif_flags & TIFF_CODERSETUP) == 0) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 32					; 00000020H
	test	eax, eax
	jne	SHORT $L65962

; 373  : 		if (!(*tif->tif_setupencode)(tif))

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+404]
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65963

; 374  : 			return ((tsize_t) -1);

	or	eax, -1
	jmp	$L65938
$L65963:

; 375  : 		tif->tif_flags |= TIFF_CODERSETUP;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	or	ecx, 32					; 00000020H
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx
$L65962:

; 377  : 	tif->tif_flags &= ~TIFF_POSTENCODE;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ch, -17					; ffffffefH
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx

; 378  : 	sample = (tsample_t)(tile/td->td_stripsperimage);

	mov	ecx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _tile$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+176]
	mov	WORD PTR _sample$[ebp], ax

; 379  : 	if (!(*tif->tif_preencode)(tif, sample))

	mov	dx, WORD PTR _sample$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+408]
	add	esp, 8
	test	eax, eax
	jne	SHORT $L65966

; 380  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	$L65938
$L65966:

; 381  : 	/*
; 382  : 	 * Clamp write amount to the tile size.  This is mostly
; 383  : 	 * done so that callers can pass in some large number
; 384  : 	 * (e.g. -1) and have the tile size used instead.
; 385  : 	 */
; 386  : 	if ( cc < 1 || cc > tif->tif_tilesize)

	cmp	DWORD PTR _cc$[ebp], 1
	jl	SHORT $L65969
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _cc$[ebp]
	cmp	eax, DWORD PTR [edx+392]
	jle	SHORT $L65968
$L65969:

; 387  : 		cc = tif->tif_tilesize;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+392]
	mov	DWORD PTR _cc$[ebp], edx
$L65968:

; 388  : 	if (!(*tif->tif_encodetile)(tif, (tidata_t) data, cc, sample))

	mov	ax, WORD PTR _sample$[ebp]
	push	eax
	mov	ecx, DWORD PTR _cc$[ebp]
	push	ecx
	mov	edx, DWORD PTR _data$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+436]
	add	esp, 16					; 00000010H
	test	eax, eax
	jne	SHORT $L65971

; 389  : 		return ((tsize_t) 0);

	xor	eax, eax
	jmp	$L65938
$L65971:

; 390  : 	if (!(*tif->tif_postencode)(tif))

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+412]
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65973

; 391  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	$L65938
$L65973:

; 392  : 	if (!isFillOrder(tif, td->td_fillorder) &&
; 393  : 	    (tif->tif_flags & TIFF_NOBITREV) == 0)

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+50]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, edx
	test	ecx, ecx
	jne	SHORT $L65975
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 256				; 00000100H
	test	eax, eax
	jne	SHORT $L65975

; 394  : 		TIFFReverseBits((u_char *)tif->tif_rawdata, tif->tif_rawcc);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+484]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+472]
	push	ecx
	call	_TIFFReverseBits
	add	esp, 8
$L65975:

; 395  : 	if (tif->tif_rawcc > 0 && !TIFFAppendToStrip(tif, tile,
; 396  : 	    tif->tif_rawdata, tif->tif_rawcc))

	mov	edx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [edx+484], 0
	jle	SHORT $L65977
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+484]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+472]
	push	eax
	mov	ecx, DWORD PTR _tile$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFAppendToStrip
	add	esp, 16					; 00000010H
	test	eax, eax
	jne	SHORT $L65977

; 397  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	SHORT $L65938
$L65977:

; 398  : 	tif->tif_rawcc = 0;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+484], 0

; 399  : 	tif->tif_rawcp = tif->tif_rawdata;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+472]
	mov	DWORD PTR [ecx+480], eax

; 400  : 	return (cc);

	mov	eax, DWORD PTR _cc$[ebp]
$L65938:

; 401  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFWriteEncodedTile ENDP
_TEXT	ENDS
PUBLIC	_TIFFWriteRawTile
_DATA	SEGMENT
	ORG $+1
$SG65995 DB	'%s: Tile %lu out of range, max %lu', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_tile$ = 12
_data$ = 16
_cc$ = 20
_TIFFWriteRawTile PROC NEAR

; 414  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 415  : 	static const char module[] = "TIFFWriteRawTile";
; 416  : 
; 417  : 	if (!WRITECHECKTILES(tif, module))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 64					; 00000040H
	test	ecx, ecx
	jne	SHORT $L65990
	push	OFFSET FLAT:_?module@?1??TIFFWriteRawTile@@9@9
	push	1
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFWriteCheck
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65990

; 418  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	SHORT $L65987
$L65990:

; 419  : 	if (tile >= tif->tif_dir.td_nstrips) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _tile$[ebp]
	cmp	ecx, DWORD PTR [eax+204]
	jb	SHORT $L65992

; 420  : 		TIFFError(module, "%s: Tile %lu out of range, max %lu",
; 421  : 		    tif->tif_name, (u_long) tile,
; 422  : 		    (u_long) tif->tif_dir.td_nstrips);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+204]
	push	eax
	mov	ecx, DWORD PTR _tile$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	push	OFFSET FLAT:$SG65995
	push	OFFSET FLAT:_?module@?1??TIFFWriteRawTile@@9@9
	call	_TIFFError
	add	esp, 20					; 00000014H

; 423  : 		return ((tsize_t) -1);

	or	eax, -1
	jmp	SHORT $L65987
$L65992:

; 425  : 	return (TIFFAppendToStrip(tif, tile, (tidata_t) data, cc) ?
; 426  : 	    cc : (tsize_t) -1);

	mov	ecx, DWORD PTR _cc$[ebp]
	push	ecx
	mov	edx, DWORD PTR _data$[ebp]
	push	edx
	mov	eax, DWORD PTR _tile$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFAppendToStrip
	add	esp, 16					; 00000010H
	test	eax, eax
	je	SHORT $L66141
	mov	edx, DWORD PTR _cc$[ebp]
	mov	DWORD PTR -4+[ebp], edx
	jmp	SHORT $L66142
$L66141:
	mov	DWORD PTR -4+[ebp], -1
$L66142:
	mov	eax, DWORD PTR -4+[ebp]
$L65987:

; 427  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFWriteRawTile ENDP
_TEXT	ENDS
EXTRN	_TIFFScanlineSize:NEAR
EXTRN	_TIFFTileSize:NEAR
_DATA	SEGMENT
	ORG $+1
$SG66029 DB	'%s: File not open for writing', 00H
	ORG $+2
$SG66031 DB	'Can not write tiles to a stripped image', 00H
$SG66032 DB	'Can not write scanlines to a tiled image', 00H
	ORG $+3
$SG66035 DB	'%s: Must set "ImageWidth" before writing data', 00H
	ORG $+2
$SG66038 DB	'%s: Must set "PlanarConfiguration" before writing data', 00H
	ORG $+1
$SG66041 DB	'tile', 00H
	ORG $+3
$SG66042 DB	'strip', 00H
	ORG $+2
$SG66043 DB	'%s: No space for %s arrays', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_tiles$ = 12
_module$ = 16
_TIFFWriteCheck PROC NEAR

; 474  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 475  : 	if (tif->tif_mode == O_RDONLY) {

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+8], 0
	jne	SHORT $L66028

; 476  : 		TIFFError(module, "%s: File not open for writing",
; 477  : 		    tif->tif_name);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	push	OFFSET FLAT:$SG66029
	mov	eax, DWORD PTR _module$[ebp]
	push	eax
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 478  : 		return (0);

	xor	eax, eax
	jmp	$L66027
$L66028:

; 480  : 	if (tiles ^ isTiled(tif)) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 1024				; 00000400H
	neg	edx
	sbb	edx, edx
	neg	edx
	mov	eax, DWORD PTR _tiles$[ebp]
	xor	eax, edx
	test	eax, eax
	je	SHORT $L66030

; 481  : 		TIFFError(tif->tif_name, tiles ?
; 482  : 		    "Can not write tiles to a stripped image" :
; 483  : 		    "Can not write scanlines to a tiled image");

	cmp	DWORD PTR _tiles$[ebp], 0
	je	SHORT $L66144
	mov	DWORD PTR -4+[ebp], OFFSET FLAT:$SG66031
	jmp	SHORT $L66145
$L66144:
	mov	DWORD PTR -4+[ebp], OFFSET FLAT:$SG66032
$L66145:
	mov	ecx, DWORD PTR -4+[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 8

; 484  : 		return (0);

	xor	eax, eax
	jmp	$L66027
$L66030:

; 486  : 	/*
; 487  : 	 * On the first write verify all the required information
; 488  : 	 * has been setup and initialize any data structures that
; 489  : 	 * had to wait until directory information was set.
; 490  : 	 * Note that a lot of our work is assumed to remain valid
; 491  : 	 * because we disallow any of the important parameters
; 492  : 	 * from changing after we start writing (i.e. once
; 493  : 	 * TIFF_BEENWRITING is set, TIFFSetField will only allow
; 494  : 	 * the image's length to be changed).
; 495  : 	 */
; 496  : 	if (!TIFFFieldSet(tif, FIELD_IMAGEDIMENSIONS)) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	and	edx, 2
	test	edx, edx
	jne	SHORT $L66034

; 497  : 		TIFFError(module,
; 498  : 		    "%s: Must set \"ImageWidth\" before writing data",
; 499  : 		    tif->tif_name);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG66035
	mov	edx, DWORD PTR _module$[ebp]
	push	edx
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 500  : 		return (0);

	xor	eax, eax
	jmp	$L66027
$L66034:

; 502  : 	if (!TIFFFieldSet(tif, FIELD_PLANARCONFIG)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 1048576				; 00100000H
	test	ecx, ecx
	jne	SHORT $L66037

; 503  : 		TIFFError(module,
; 504  : 	    "%s: Must set \"PlanarConfiguration\" before writing data",
; 505  : 		    tif->tif_name);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	push	OFFSET FLAT:$SG66038
	mov	ecx, DWORD PTR _module$[ebp]
	push	ecx
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 506  : 		return (0);

	xor	eax, eax
	jmp	$L66027
$L66037:

; 508  : 	if (tif->tif_dir.td_stripoffset == NULL && !TIFFSetupStrips(tif)) {

	mov	edx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [edx+208], 0
	jne	SHORT $L66040
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFSetupStrips
	add	esp, 4
	test	eax, eax
	jne	SHORT $L66040

; 509  : 		tif->tif_dir.td_nstrips = 0;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+204], 0

; 510  : 		TIFFError(module, "%s: No space for %s arrays",
; 511  : 		    tif->tif_name, isTiled(tif) ? "tile" : "strip");

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 1024				; 00000400H
	test	eax, eax
	je	SHORT $L66146
	mov	DWORD PTR -8+[ebp], OFFSET FLAT:$SG66041
	jmp	SHORT $L66147
$L66146:
	mov	DWORD PTR -8+[ebp], OFFSET FLAT:$SG66042
$L66147:
	mov	ecx, DWORD PTR -8+[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	push	OFFSET FLAT:$SG66043
	mov	ecx, DWORD PTR _module$[ebp]
	push	ecx
	call	_TIFFError
	add	esp, 16					; 00000010H

; 512  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L66027
$L66040:

; 514  : 	tif->tif_tilesize = TIFFTileSize(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFTileSize
	add	esp, 4
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+392], eax

; 515  : 	tif->tif_scanlinesize = TIFFScanlineSize(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFScanlineSize
	add	esp, 4
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+464], eax

; 516  : 	tif->tif_flags |= TIFF_BEENWRITING;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	or	al, 64					; 00000040H
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+12], eax

; 517  : 	return (1);

	mov	eax, 1
$L66027:

; 518  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFWriteCheck ENDP
_TEXT	ENDS
EXTRN	__TIFFmalloc:NEAR
EXTRN	__TIFFmemset:NEAR
EXTRN	_TIFFNumberOfTiles:NEAR
EXTRN	_TIFFNumberOfStrips:NEAR
_TEXT	SEGMENT
_tif$ = 8
_td$ = -4
_TIFFSetupStrips PROC NEAR

; 434  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 435  : 	TIFFDirectory* td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 436  : 
; 437  : 	if (isTiled(tif))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 1024				; 00000400H
	test	edx, edx
	je	SHORT $L66004

; 438  : 		td->td_stripsperimage =
; 439  : 		    isUnspecified(tif, FIELD_TILEDIMENSIONS) ?
; 440  : 			td->td_samplesperpixel : TIFFNumberOfTiles(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 4
	test	ecx, ecx
	je	SHORT $L66149
	mov	edx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [edx+40], 0
	jne	SHORT $L66149
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+54]
	mov	DWORD PTR -8+[ebp], ecx
	jmp	SHORT $L66150
$L66149:
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFNumberOfTiles
	add	esp, 4
	mov	DWORD PTR -8+[ebp], eax
$L66150:
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR -8+[ebp]
	mov	DWORD PTR [eax+176], ecx

; 441  : 	else

	jmp	SHORT $L66006
$L66004:

; 442  : 		td->td_stripsperimage =
; 443  : 		    isUnspecified(tif, FIELD_ROWSPERSTRIP) ?
; 444  : 			td->td_samplesperpixel : TIFFNumberOfStrips(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+24]
	and	eax, 131072				; 00020000H
	test	eax, eax
	je	SHORT $L66151
	mov	ecx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [ecx+40], 0
	jne	SHORT $L66151
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+54]
	mov	DWORD PTR -12+[ebp], eax
	jmp	SHORT $L66152
$L66151:
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFNumberOfStrips
	add	esp, 4
	mov	DWORD PTR -12+[ebp], eax
$L66152:
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR -12+[ebp]
	mov	DWORD PTR [edx+176], eax
$L66006:

; 445  : 	td->td_nstrips = td->td_stripsperimage;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+176]
	mov	DWORD PTR [ecx+180], eax

; 446  : 	if (td->td_planarconfig == PLANARCONFIG_SEPARATE)

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+90]
	cmp	edx, 2
	jne	SHORT $L66008

; 447  : 		td->td_stripsperimage /= td->td_samplesperpixel;

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+54]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+176]
	xor	edx, edx
	div	ecx
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+176], eax
$L66008:

; 448  : 	td->td_stripoffset = (uint32 *)
; 449  : 	    _TIFFmalloc(td->td_nstrips * sizeof (uint32));

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+180]
	shl	eax, 2
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+184], eax

; 450  : 	td->td_stripbytecount = (uint32 *)
; 451  : 	    _TIFFmalloc(td->td_nstrips * sizeof (uint32));

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+180]
	shl	eax, 2
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+188], eax

; 452  : 	if (td->td_stripoffset == NULL || td->td_stripbytecount == NULL)

	mov	edx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [edx+184], 0
	je	SHORT $L66016
	mov	eax, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [eax+188], 0
	jne	SHORT $L66015
$L66016:

; 453  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L66002
$L66015:

; 454  : 	/*
; 455  : 	 * Place data at the end-of-file
; 456  : 	 * (by setting offsets to zero).
; 457  : 	 */
; 458  : 	_TIFFmemset(td->td_stripoffset, 0, td->td_nstrips*sizeof (uint32));

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+180]
	shl	edx, 2
	push	edx
	push	0
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+184]
	push	ecx
	call	__TIFFmemset
	add	esp, 12					; 0000000cH

; 459  : 	_TIFFmemset(td->td_stripbytecount, 0, td->td_nstrips*sizeof (uint32));

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+180]
	shl	eax, 2
	push	eax
	push	0
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+188]
	push	edx
	call	__TIFFmemset
	add	esp, 12					; 0000000cH

; 460  : 	TIFFSetFieldBit(tif, FIELD_STRIPOFFSETS);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	or	ecx, 33554432				; 02000000H
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+24], ecx

; 461  : 	TIFFSetFieldBit(tif, FIELD_STRIPBYTECOUNTS);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	or	ecx, 16777216				; 01000000H
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+24], ecx

; 462  : 	return (1);

	mov	eax, 1
$L66002:

; 463  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFSetupStrips ENDP
_TEXT	ENDS
EXTRN	__TIFFfree:NEAR
_DATA	SEGMENT
	ORG $+1
$SG66064 DB	'%s: No space for output buffer', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_bp$ = 12
_size$ = 16
_TIFFWriteBufferSetup PROC NEAR

; 525  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 526  : 	static const char module[] = "TIFFWriteBufferSetup";
; 527  : 
; 528  : 	if (tif->tif_rawdata) {

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+472], 0
	je	SHORT $L66053

; 529  : 		if (tif->tif_flags & TIFF_MYBUFFER) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 512				; 00000200H
	test	edx, edx
	je	SHORT $L66054

; 530  : 			_TIFFfree(tif->tif_rawdata);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+472]
	push	ecx
	call	__TIFFfree
	add	esp, 4

; 531  : 			tif->tif_flags &= ~TIFF_MYBUFFER;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	ah, -3					; fffffffdH
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+12], eax
$L66054:

; 533  : 		tif->tif_rawdata = NULL;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+472], 0
$L66053:

; 535  : 	if (size == (tsize_t) -1) {

	cmp	DWORD PTR _size$[ebp], -1
	jne	SHORT $L66057

; 536  : 		size = (isTiled(tif) ?
; 537  : 		    tif->tif_tilesize : tif->tif_scanlinesize);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 1024				; 00000400H
	test	ecx, ecx
	je	SHORT $L66154
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+392]
	mov	DWORD PTR -4+[ebp], eax
	jmp	SHORT $L66155
$L66154:
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+464]
	mov	DWORD PTR -4+[ebp], edx
$L66155:
	mov	eax, DWORD PTR -4+[ebp]
	mov	DWORD PTR _size$[ebp], eax

; 538  : 		/*
; 539  : 		 * Make raw data buffer at least 8K
; 540  : 		 */
; 541  : 		if (size < 8*1024)

	cmp	DWORD PTR _size$[ebp], 8192		; 00002000H
	jge	SHORT $L66058

; 542  : 			size = 8*1024;

	mov	DWORD PTR _size$[ebp], 8192		; 00002000H
$L66058:

; 543  : 		bp = NULL;			/* NB: force malloc */

	mov	DWORD PTR _bp$[ebp], 0
$L66057:

; 545  : 	if (bp == NULL) {

	cmp	DWORD PTR _bp$[ebp], 0
	jne	SHORT $L66061

; 546  : 		bp = _TIFFmalloc(size);

	mov	ecx, DWORD PTR _size$[ebp]
	push	ecx
	call	__TIFFmalloc
	add	esp, 4
	mov	DWORD PTR _bp$[ebp], eax

; 547  : 		if (bp == NULL) {

	cmp	DWORD PTR _bp$[ebp], 0
	jne	SHORT $L66063

; 548  : 			TIFFError(module, "%s: No space for output buffer",
; 549  : 			    tif->tif_name);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	push	OFFSET FLAT:$SG66064
	push	OFFSET FLAT:_?module@?1??TIFFWriteBufferSetup@@9@9
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 550  : 			return (0);

	xor	eax, eax
	jmp	SHORT $L66050
$L66063:

; 552  : 		tif->tif_flags |= TIFF_MYBUFFER;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	or	dh, 2
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+12], edx

; 553  : 	} else

	jmp	SHORT $L66065
$L66061:

; 554  : 		tif->tif_flags &= ~TIFF_MYBUFFER;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	dh, -3					; fffffffdH
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+12], edx
$L66065:

; 555  : 	tif->tif_rawdata = (tidata_t) bp;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _bp$[ebp]
	mov	DWORD PTR [ecx+472], edx

; 556  : 	tif->tif_rawdatasize = size;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _size$[ebp]
	mov	DWORD PTR [eax+476], ecx

; 557  : 	tif->tif_rawcc = 0;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], 0

; 558  : 	tif->tif_rawcp = tif->tif_rawdata;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+472]
	mov	DWORD PTR [eax+480], edx

; 559  : 	tif->tif_flags |= TIFF_BUFFERSETUP;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	or	ecx, 16					; 00000010H
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx

; 560  : 	return (1);

	mov	eax, 1
$L66050:

; 561  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFWriteBufferSetup ENDP
_TEXT	ENDS
EXTRN	__assert:NEAR
EXTRN	__TIFFrealloc:NEAR
_DATA	SEGMENT
	ORG $+1
$SG66076 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_write.c', 00H
	ORG $+2
$SG66077 DB	'td->td_planarconfig == PLANARCONFIG_CONTIG', 00H
	ORG $+1
$SG66086 DB	'%s: No space to expand strip arrays', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_delta$ = 12
_module$ = 16
_td$ = -4
_TIFFGrowStrips PROC NEAR

; 568  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 569  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 570  : 
; 571  : 	assert(td->td_planarconfig == PLANARCONFIG_CONTIG);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+90]
	cmp	edx, 1
	je	SHORT $L66157
	push	571					; 0000023bH
	push	OFFSET FLAT:$SG66076
	push	OFFSET FLAT:$SG66077
	call	__assert
	add	esp, 12					; 0000000cH
$L66157:

; 572  : 	td->td_stripoffset = (uint32*)_TIFFrealloc(td->td_stripoffset,
; 573  : 	    (td->td_nstrips + delta) * sizeof (uint32));

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+180]
	add	edx, DWORD PTR _delta$[ebp]
	shl	edx, 2
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+184]
	push	ecx
	call	__TIFFrealloc
	add	esp, 8
	mov	edx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [edx+184], eax

; 574  : 	td->td_stripbytecount = (uint32*)_TIFFrealloc(td->td_stripbytecount,
; 575  : 	    (td->td_nstrips + delta) * sizeof (uint32));

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+180]
	add	ecx, DWORD PTR _delta$[ebp]
	shl	ecx, 2
	push	ecx
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+188]
	push	eax
	call	__TIFFrealloc
	add	esp, 8
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+188], eax

; 576  : 	if (td->td_stripoffset == NULL || td->td_stripbytecount == NULL) {

	mov	edx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [edx+184], 0
	je	SHORT $L66085
	mov	eax, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [eax+188], 0
	jne	SHORT $L66084
$L66085:

; 577  : 		td->td_nstrips = 0;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+180], 0

; 578  : 		TIFFError(module, "%s: No space to expand strip arrays",
; 579  : 		    tif->tif_name);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	push	OFFSET FLAT:$SG66086
	mov	ecx, DWORD PTR _module$[ebp]
	push	ecx
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 580  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L66073
$L66084:

; 582  : 	_TIFFmemset(td->td_stripoffset+td->td_nstrips, 0, delta*sizeof (uint32));

	mov	edx, DWORD PTR _delta$[ebp]
	shl	edx, 2
	push	edx
	push	0
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+180]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+184]
	lea	ecx, DWORD PTR [eax+ecx*4]
	push	ecx
	call	__TIFFmemset
	add	esp, 12					; 0000000cH

; 583  : 	_TIFFmemset(td->td_stripbytecount+td->td_nstrips, 0, delta*sizeof (uint32));

	mov	edx, DWORD PTR _delta$[ebp]
	shl	edx, 2
	push	edx
	push	0
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+180]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+188]
	lea	ecx, DWORD PTR [eax+ecx*4]
	push	ecx
	call	__TIFFmemset
	add	esp, 12					; 0000000cH

; 584  : 	td->td_nstrips += delta;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+180]
	add	eax, DWORD PTR _delta$[ebp]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+180], eax

; 585  : 	return (1);

	mov	eax, 1
$L66073:

; 586  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFGrowStrips ENDP
_TEXT	ENDS
_DATA	SEGMENT
$SG66109 DB	'%s: Seek error at scanline %lu', 00H
	ORG $+1
$SG66118 DB	'%s: Write error at scanline %lu', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_strip$ = 12
_data$ = 16
_cc$ = 20
_td$ = -4
_TIFFAppendToStrip PROC NEAR

; 596  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 597  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 598  : 	static const char module[] = "TIFFAppendToStrip";
; 599  : 
; 600  : 	if (td->td_stripoffset[strip] == 0 || tif->tif_curoff == 0) {

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	mov	eax, DWORD PTR _strip$[ebp]
	cmp	DWORD PTR [edx+eax*4], 0
	je	SHORT $L66102
	mov	ecx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [ecx+368], 0
	jne	$L66101
$L66102:

; 601  : 		/*
; 602  : 		 * No current offset, set the current strip.
; 603  : 		 */
; 604  : 		if (td->td_stripoffset[strip] != 0) {

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+184]
	mov	ecx, DWORD PTR _strip$[ebp]
	cmp	DWORD PTR [eax+ecx*4], 0
	je	SHORT $L66103

; 605  : 			if (!SeekOK(tif, td->td_stripoffset[strip])) {

	push	0
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+184]
	mov	ecx, DWORD PTR _strip$[ebp]
	mov	edx, DWORD PTR [eax+ecx*4]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+516]
	add	esp, 12					; 0000000cH
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	mov	ecx, DWORD PTR _strip$[ebp]
	cmp	eax, DWORD PTR [edx+ecx*4]
	je	SHORT $L66107

; 606  : 				TIFFError(module,
; 607  : 				    "%s: Seek error at scanline %lu",
; 608  : 				    tif->tif_name, (u_long) tif->tif_row);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+356]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	push	OFFSET FLAT:$SG66109
	push	OFFSET FLAT:_?module@?1??TIFFAppendToStrip@@9@9
	call	_TIFFError
	add	esp, 16					; 00000010H

; 609  : 				return (0);

	xor	eax, eax
	jmp	$L66097
$L66107:

; 611  : 		} else

	jmp	SHORT $L66110
$L66103:

; 612  : 			td->td_stripoffset[strip] =
; 613  : 			    TIFFSeekFile(tif, (toff_t) 0, SEEK_END);

	push	2
	push	0
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+516]
	add	esp, 12					; 0000000cH
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+184]
	mov	ecx, DWORD PTR _strip$[ebp]
	mov	DWORD PTR [edx+ecx*4], eax
$L66110:

; 614  : 		tif->tif_curoff = td->td_stripoffset[strip];

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+184]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _strip$[ebp]
	mov	eax, DWORD PTR [eax+edx*4]
	mov	DWORD PTR [ecx+368], eax
$L66101:

; 616  : 	if (!WriteOK(tif, data, cc)) {

	mov	ecx, DWORD PTR _cc$[ebp]
	push	ecx
	mov	edx, DWORD PTR _data$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+512]
	add	esp, 12					; 0000000cH
	cmp	eax, DWORD PTR _cc$[ebp]
	je	SHORT $L66116

; 617  : 		TIFFError(module, "%s: Write error at scanline %lu",
; 618  : 		    tif->tif_name, (u_long) tif->tif_row);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+356]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	push	OFFSET FLAT:$SG66118
	push	OFFSET FLAT:_?module@?1??TIFFAppendToStrip@@9@9
	call	_TIFFError
	add	esp, 16					; 00000010H

; 619  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L66097
$L66116:

; 621  : 	tif->tif_curoff += cc;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+368]
	add	edx, DWORD PTR _cc$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+368], edx

; 622  : 	td->td_stripbytecount[strip] += cc;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+188]
	mov	eax, DWORD PTR _strip$[ebp]
	mov	ecx, DWORD PTR [edx+eax*4]
	add	ecx, DWORD PTR _cc$[ebp]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+188]
	mov	edx, DWORD PTR _strip$[ebp]
	mov	DWORD PTR [eax+edx*4], ecx

; 623  : 	return (1);

	mov	eax, 1
$L66097:

; 624  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFAppendToStrip ENDP
_TEXT	ENDS
PUBLIC	_TIFFFlushData1
_TEXT	SEGMENT
_tif$ = 8
_TIFFFlushData1 PROC NEAR

; 633  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 634  : 	if (tif->tif_rawcc > 0) {

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+484], 0
	jle	$L66122

; 635  : 		if (!isFillOrder(tif, tif->tif_dir.td_fillorder) &&
; 636  : 		    (tif->tif_flags & TIFF_NOBITREV) == 0)

	mov	ecx, DWORD PTR _tif$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+74]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, edx
	test	ecx, ecx
	jne	SHORT $L66123
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 256				; 00000100H
	test	eax, eax
	jne	SHORT $L66123

; 637  : 			TIFFReverseBits((u_char *)tif->tif_rawdata,
; 638  : 			    tif->tif_rawcc);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+484]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+472]
	push	ecx
	call	_TIFFReverseBits
	add	esp, 8
$L66123:

; 639  : 		if (!TIFFAppendToStrip(tif,
; 640  : 		    isTiled(tif) ? tif->tif_curtile : tif->tif_curstrip,
; 641  : 		    tif->tif_rawdata, tif->tif_rawcc))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 1024				; 00000400H
	test	eax, eax
	je	SHORT $L66160
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+388]
	mov	DWORD PTR -4+[ebp], edx
	jmp	SHORT $L66161
$L66160:
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	mov	DWORD PTR -4+[ebp], ecx
$L66161:
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+484]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+472]
	push	edx
	mov	eax, DWORD PTR -4+[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFAppendToStrip
	add	esp, 16					; 00000010H
	test	eax, eax
	jne	SHORT $L66125

; 642  : 			return (0);

	xor	eax, eax
	jmp	SHORT $L66121
$L66125:

; 643  : 		tif->tif_rawcc = 0;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], 0

; 644  : 		tif->tif_rawcp = tif->tif_rawdata;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+472]
	mov	DWORD PTR [eax+480], edx
$L66122:

; 646  : 	return (1);

	mov	eax, 1
$L66121:

; 647  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFFlushData1 ENDP
_TEXT	ENDS
PUBLIC	_TIFFSetWriteOffset
_TEXT	SEGMENT
_tif$ = 8
_off$ = 12
_TIFFSetWriteOffset PROC NEAR

; 657  : {

	push	ebp
	mov	ebp, esp

; 658  : 	tif->tif_curoff = off;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _off$[ebp]
	mov	DWORD PTR [eax+368], ecx

; 659  : }

	pop	ebp
	ret	0
_TIFFSetWriteOffset ENDP
_TEXT	ENDS
END
