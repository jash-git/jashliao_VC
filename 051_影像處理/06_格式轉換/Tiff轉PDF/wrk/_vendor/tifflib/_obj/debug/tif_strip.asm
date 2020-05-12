	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_strip.c
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
PUBLIC	_TIFFComputeStrip
EXTRN	_TIFFError:NEAR
_DATA	SEGMENT
$SG65794 DB	'%u: Sample out of range, max %u', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_row$ = 12
_sample$ = 16
_td$ = -4
_strip$ = -8
_TIFFComputeStrip PROC NEAR

; 39   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 40   : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 41   : 	tstrip_t strip;
; 42   : 
; 43   : 	strip = row / td->td_rowsperstrip;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+56]
	mov	DWORD PTR _strip$[ebp], eax

; 44   : 	if (td->td_planarconfig == PLANARCONFIG_SEPARATE) {

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+90]
	cmp	eax, 2
	jne	SHORT $L65792

; 45   : 		if (sample >= td->td_samplesperpixel) {

	mov	ecx, DWORD PTR _sample$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+54]
	cmp	ecx, eax
	jl	SHORT $L65793

; 46   : 			TIFFError(tif->tif_name,
; 47   : 			    "%u: Sample out of range, max %u",
; 48   : 			    sample, td->td_samplesperpixel);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+54]
	push	edx
	mov	eax, DWORD PTR _sample$[ebp]
	and	eax, 65535				; 0000ffffH
	push	eax
	push	OFFSET FLAT:$SG65794
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 16					; 00000010H

; 49   : 			return ((tstrip_t) 0);

	xor	eax, eax
	jmp	SHORT $L65789
$L65793:

; 51   : 		strip += sample*td->td_stripsperimage;

	mov	eax, DWORD PTR _sample$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _td$[ebp]
	imul	eax, DWORD PTR [ecx+176]
	mov	edx, DWORD PTR _strip$[ebp]
	add	edx, eax
	mov	DWORD PTR _strip$[ebp], edx
$L65792:

; 53   : 	return (strip);

	mov	eax, DWORD PTR _strip$[ebp]
$L65789:

; 54   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFComputeStrip ENDP
_TEXT	ENDS
PUBLIC	_TIFFNumberOfStrips
_TEXT	SEGMENT
_tif$ = 8
_td$ = -8
_nstrips$ = -4
_TIFFNumberOfStrips PROC NEAR

; 61   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 62   : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 63   : 	tstrip_t nstrips;
; 64   : 
; 65   : 	nstrips = (td->td_rowsperstrip == (uint32) -1 ?
; 66   : 	     (td->td_imagelength != 0 ? 1 : 0) :
; 67   : 	     TIFFhowmany(td->td_imagelength, td->td_rowsperstrip));

	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+56], -1
	jne	SHORT $L65882
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	cmp	DWORD PTR [edx+16], 0
	setne	al
	mov	DWORD PTR -12+[ebp], eax
	jmp	SHORT $L65883
$L65882:
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	lea	eax, DWORD PTR [ecx+edx-1]
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	div	DWORD PTR [ecx+56]
	mov	DWORD PTR -12+[ebp], eax
$L65883:
	mov	edx, DWORD PTR -12+[ebp]
	mov	DWORD PTR _nstrips$[ebp], edx

; 68   : 	if (td->td_planarconfig == PLANARCONFIG_SEPARATE)

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+90]
	cmp	ecx, 2
	jne	SHORT $L65805

; 69   : 		nstrips *= td->td_samplesperpixel;

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+54]
	mov	ecx, DWORD PTR _nstrips$[ebp]
	imul	ecx, eax
	mov	DWORD PTR _nstrips$[ebp], ecx
$L65805:

; 70   : 	return (nstrips);

	mov	eax, DWORD PTR _nstrips$[ebp]

; 71   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFNumberOfStrips ENDP
_TEXT	ENDS
PUBLIC	_TIFFScanlineSize
PUBLIC	_TIFFVStripSize
_TEXT	SEGMENT
_tif$ = 8
_nrows$ = 12
_td$ = -4
_w$65815 = -8
_scanline$65820 = -16
_samplingarea$65824 = -12
_TIFFVStripSize PROC NEAR

; 78   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 79   : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 80   : 
; 81   : 	if (nrows == (uint32) -1)

	cmp	DWORD PTR _nrows$[ebp], -1
	jne	SHORT $L65813

; 82   : 		nrows = td->td_imagelength;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	mov	DWORD PTR _nrows$[ebp], edx
$L65813:

; 83   : #ifdef YCBCR_SUPPORT
; 84   : 	if (td->td_planarconfig == PLANARCONFIG_CONTIG &&
; 85   : 	    td->td_photometric == PHOTOMETRIC_YCBCR &&
; 86   : 	    !isUpSampled(tif)) {

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+90]
	cmp	ecx, 1
	jne	$L65814
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+46]
	cmp	eax, 6
	jne	$L65814
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 16384				; 00004000H
	test	edx, edx
	jne	$L65814

; 87   : 		/*
; 88   : 		 * Packed YCbCr data contain one Cb+Cr for every
; 89   : 		 * HorizontalSampling*VerticalSampling Y values.
; 90   : 		 * Must also roundup width and height when calculating
; 91   : 		 * since images that are not a multiple of the
; 92   : 		 * horizontal/vertical subsampling area include
; 93   : 		 * YCbCr data for the extended image.
; 94   : 		 */
; 95   : 		tsize_t w =
; 96   : 		    TIFFroundup(td->td_imagewidth, td->td_ycbcrsubsampling[0]);

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+204]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+12]
	lea	eax, DWORD PTR [eax+ecx-1]
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+204]
	mov	ecx, edx
	xor	edx, edx
	div	ecx
	mov	edx, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+204]
	imul	eax, ecx
	mov	DWORD PTR _w$65815[ebp], eax

; 97   : 		tsize_t scanline = TIFFhowmany(w*td->td_bitspersample, 8);

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+40]
	mov	ecx, DWORD PTR _w$65815[ebp]
	imul	ecx, eax
	add	ecx, 7
	shr	ecx, 3
	mov	DWORD PTR _scanline$65820[ebp], ecx

; 98   : 		tsize_t samplingarea =
; 99   : 		    td->td_ycbcrsubsampling[0]*td->td_ycbcrsubsampling[1];

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+204]
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+206]
	imul	eax, edx
	mov	DWORD PTR _samplingarea$65824[ebp], eax

; 100  : 		nrows = TIFFroundup(nrows, td->td_ycbcrsubsampling[1]);

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+206]
	mov	edx, DWORD PTR _nrows$[ebp]
	lea	eax, DWORD PTR [edx+ecx-1]
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+206]
	mov	ecx, edx
	xor	edx, edx
	div	ecx
	mov	edx, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+206]
	imul	eax, ecx
	mov	DWORD PTR _nrows$[ebp], eax

; 101  : 		/* NB: don't need TIFFhowmany here 'cuz everything is rounded */
; 102  : 		return ((tsize_t)
; 103  : 		    (nrows*scanline + 2*(nrows*scanline / samplingarea)));

	mov	ecx, DWORD PTR _nrows$[ebp]
	imul	ecx, DWORD PTR _scanline$65820[ebp]
	mov	eax, DWORD PTR _nrows$[ebp]
	imul	eax, DWORD PTR _scanline$65820[ebp]
	xor	edx, edx
	div	DWORD PTR _samplingarea$65824[ebp]
	lea	eax, DWORD PTR [ecx+eax*2]
	jmp	SHORT $L65830
$L65814:

; 105  : #endif
; 106  : 		return ((tsize_t)(nrows * TIFFScanlineSize(tif)));

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFScanlineSize
	add	esp, 4
	mov	ecx, DWORD PTR _nrows$[ebp]
	imul	eax, ecx
$L65830:

; 107  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFVStripSize ENDP
_TEXT	ENDS
PUBLIC	_TIFFStripSize
_TEXT	SEGMENT
_tif$ = 8
_td$ = -8
_rps$ = -4
_TIFFStripSize PROC NEAR

; 119  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 120  : 	TIFFDirectory* td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 121  : 	uint32 rps = td->td_rowsperstrip;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	DWORD PTR _rps$[ebp], edx

; 122  : 	if (rps > td->td_imagelength)

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _rps$[ebp]
	cmp	ecx, DWORD PTR [eax+16]
	jbe	SHORT $L65837

; 123  : 		rps = td->td_imagelength;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+16]
	mov	DWORD PTR _rps$[ebp], eax
$L65837:

; 124  : 	return (TIFFVStripSize(tif, rps));

	mov	ecx, DWORD PTR _rps$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFVStripSize
	add	esp, 8

; 125  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFStripSize ENDP
_TEXT	ENDS
PUBLIC	_TIFFDefaultStripSize
_TEXT	SEGMENT
_tif$ = 8
_request$ = 12
_TIFFDefaultStripSize PROC NEAR

; 135  : {

	push	ebp
	mov	ebp, esp

; 136  : 	return (*tif->tif_defstripsize)(tif, request);

	mov	eax, DWORD PTR _request$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+452]
	add	esp, 8

; 137  : }

	pop	ebp
	ret	0
_TIFFDefaultStripSize ENDP
_TEXT	ENDS
PUBLIC	__TIFFDefaultStripSize
_TEXT	SEGMENT
_tif$ = 8
_s$ = 12
_scanline$65850 = -4
__TIFFDefaultStripSize PROC NEAR

; 141  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 142  : 	if ((int32) s < 1) {

	cmp	DWORD PTR _s$[ebp], 1
	jge	SHORT $L65852

; 143  : 		/*
; 144  : 		 * If RowsPerStrip is unspecified, try to break the
; 145  : 		 * image up into strips that are approximately 8Kbytes.
; 146  : 		 */
; 147  : 		tsize_t scanline = TIFFScanlineSize(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFScanlineSize
	add	esp, 4
	mov	DWORD PTR _scanline$65850[ebp], eax

; 148  : 		s = (uint32)(8*1024) / (scanline == 0 ? 1 : scanline);

	cmp	DWORD PTR _scanline$65850[ebp], 0
	jne	SHORT $L65888
	mov	DWORD PTR -8+[ebp], 1
	jmp	SHORT $L65889
$L65888:
	mov	ecx, DWORD PTR _scanline$65850[ebp]
	mov	DWORD PTR -8+[ebp], ecx
$L65889:
	mov	eax, 8192				; 00002000H
	xor	edx, edx
	div	DWORD PTR -8+[ebp]
	mov	DWORD PTR _s$[ebp], eax

; 149  : 		if (s == 0)		/* very wide images */

	cmp	DWORD PTR _s$[ebp], 0
	jne	SHORT $L65852

; 150  : 			s = 1;

	mov	DWORD PTR _s$[ebp], 1
$L65852:

; 152  : 	return (s);

	mov	eax, DWORD PTR _s$[ebp]

; 153  : }

	mov	esp, ebp
	pop	ebp
	ret	0
__TIFFDefaultStripSize ENDP
_tif$ = 8
_td$ = -4
_scanline$ = -8
_TIFFScanlineSize PROC NEAR

; 163  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 164  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 165  : 	tsize_t scanline;
; 166  : 	
; 167  : 	scanline = td->td_bitspersample * td->td_imagewidth;

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+40]
	mov	eax, DWORD PTR _td$[ebp]
	imul	edx, DWORD PTR [eax+12]
	mov	DWORD PTR _scanline$[ebp], edx

; 168  : 	if (td->td_planarconfig == PLANARCONFIG_CONTIG)

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+90]
	cmp	edx, 1
	jne	SHORT $L65858

; 169  : 		scanline *= td->td_samplesperpixel;

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+54]
	mov	edx, DWORD PTR _scanline$[ebp]
	imul	edx, ecx
	mov	DWORD PTR _scanline$[ebp], edx
$L65858:

; 170  : 	return ((tsize_t) TIFFhowmany(scanline, 8));

	mov	eax, DWORD PTR _scanline$[ebp]
	add	eax, 7
	shr	eax, 3

; 171  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFScanlineSize ENDP
_TEXT	ENDS
PUBLIC	_TIFFRasterScanlineSize
_TEXT	SEGMENT
_tif$ = 8
_td$ = -4
_scanline$ = -8
_TIFFRasterScanlineSize PROC NEAR

; 181  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 182  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 183  : 	tsize_t scanline;
; 184  : 	
; 185  : 	scanline = td->td_bitspersample * td->td_imagewidth;

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+40]
	mov	eax, DWORD PTR _td$[ebp]
	imul	edx, DWORD PTR [eax+12]
	mov	DWORD PTR _scanline$[ebp], edx

; 186  : 	if (td->td_planarconfig == PLANARCONFIG_CONTIG) {

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+90]
	cmp	edx, 1
	jne	SHORT $L65868

; 187  : 		scanline *= td->td_samplesperpixel;

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+54]
	mov	edx, DWORD PTR _scanline$[ebp]
	imul	edx, ecx
	mov	DWORD PTR _scanline$[ebp], edx

; 188  : 		return ((tsize_t) TIFFhowmany(scanline, 8));

	mov	eax, DWORD PTR _scanline$[ebp]
	add	eax, 7
	shr	eax, 3
	jmp	SHORT $L65873
$L65868:

; 190  : 		return ((tsize_t)
; 191  : 		    TIFFhowmany(scanline, 8)*td->td_samplesperpixel);

	mov	eax, DWORD PTR _scanline$[ebp]
	add	eax, 7
	shr	eax, 3
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+54]
	imul	eax, edx
$L65873:

; 192  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFRasterScanlineSize ENDP
_TEXT	ENDS
END
