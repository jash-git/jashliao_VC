	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_thunder.c
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
_twobitdeltas DD 00H
	DD	01H
	DD	00H
	DD	0ffffffffH
_threebitdeltas DD 00H
	DD	01H
	DD	02H
	DD	03H
	DD	00H
	DD	0fffffffdH
	DD	0fffffffeH
	DD	0ffffffffH
CONST	ENDS
PUBLIC	_TIFFInitThunderScan
_TEXT	SEGMENT
_tif$ = 8
_TIFFInitThunderScan PROC NEAR

; 148  : {

	push	ebp
	mov	ebp, esp

; 149  : 	(void) scheme;
; 150  : 	tif->tif_decoderow = ThunderDecodeRow;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+416], OFFSET FLAT:_ThunderDecodeRow

; 151  : 	tif->tif_decodestrip = ThunderDecodeRow;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+424], OFFSET FLAT:_ThunderDecodeRow

; 152  : 	return (1);

	mov	eax, 1

; 153  : }

	pop	ebp
	ret	0
_TIFFInitThunderScan ENDP
_tif$ = 8
_buf$ = 12
_occ$ = 16
_row$ = -4
_ThunderDecodeRow PROC NEAR

; 133  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 134  : 	tidata_t row = buf;

	mov	eax, DWORD PTR _buf$[ebp]
	mov	DWORD PTR _row$[ebp], eax
$L65865:

; 135  : 	
; 136  : 	(void) s;
; 137  : 	while ((long)occ > 0) {

	cmp	DWORD PTR _occ$[ebp], 0
	jle	SHORT $L65866

; 138  : 		if (!ThunderDecode(tif, row, tif->tif_dir.td_imagewidth))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+36]
	push	edx
	mov	eax, DWORD PTR _row$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_ThunderDecode
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65867

; 139  : 			return (0);

	xor	eax, eax
	jmp	SHORT $L65860
$L65867:

; 140  : 		occ -= tif->tif_scanlinesize;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _occ$[ebp]
	sub	eax, DWORD PTR [edx+464]
	mov	DWORD PTR _occ$[ebp], eax

; 141  : 		row += tif->tif_scanlinesize;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _row$[ebp]
	add	edx, DWORD PTR [ecx+464]
	mov	DWORD PTR _row$[ebp], edx

; 142  : 	}

	jmp	SHORT $L65865
$L65866:

; 143  : 	return (1);

	mov	eax, 1
$L65860:

; 144  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_ThunderDecodeRow ENDP
_TEXT	ENDS
EXTRN	_TIFFError:NEAR
_DATA	SEGMENT
$SG65848 DB	'Not enough', 00H
	ORG $+1
$SG65849 DB	'Too much', 00H
	ORG $+3
$SG65850 DB	'ThunderDecode: %s data at scanline %ld (%lu != %lu)', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_op$ = 12
_maxpixels$ = 16
_bp$ = -16
_cc$ = -8
_lastpixel$ = -4
_npixels$ = -12
_n$65810 = -24
_delta$65811 = -20
_ThunderDecode PROC NEAR

; 68   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 32					; 00000020H

; 69   : 	register u_char *bp;
; 70   : 	register tsize_t cc;
; 71   : 	u_int lastpixel;
; 72   : 	tsize_t npixels;
; 73   : 
; 74   : 	bp = (u_char *)tif->tif_rawcp;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	DWORD PTR _bp$[ebp], ecx

; 75   : 	cc = tif->tif_rawcc;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+484]
	mov	DWORD PTR _cc$[ebp], eax

; 76   : 	lastpixel = 0;

	mov	DWORD PTR _lastpixel$[ebp], 0

; 77   : 	npixels = 0;

	mov	DWORD PTR _npixels$[ebp], 0
$L65808:

; 78   : 	while (cc > 0 && npixels < maxpixels) {

	cmp	DWORD PTR _cc$[ebp], 0
	jle	$L65809
	mov	ecx, DWORD PTR _npixels$[ebp]
	cmp	ecx, DWORD PTR _maxpixels$[ebp]
	jge	$L65809

; 79   : 		int n, delta;
; 80   : 
; 81   : 		n = *bp++, cc--;

	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	DWORD PTR _n$65810[ebp], eax
	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _bp$[ebp], ecx
	mov	edx, DWORD PTR _cc$[ebp]
	sub	edx, 1
	mov	DWORD PTR _cc$[ebp], edx

; 82   : 		switch (n & THUNDER_CODE) {

	mov	eax, DWORD PTR _n$65810[ebp]
	and	eax, 192				; 000000c0H
	mov	DWORD PTR -28+[ebp], eax
	cmp	DWORD PTR -28+[ebp], 192		; 000000c0H
	ja	$L65813
	mov	edx, DWORD PTR -28+[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR $L65881[edx]
	jmp	DWORD PTR $L65882[ecx*4]
$L65816:

; 83   : 		case THUNDER_RUN:		/* pixel run */
; 84   : 			/*
; 85   : 			 * Replicate the last pixel n times,
; 86   : 			 * where n is the lower-order 6 bits.
; 87   : 			 */
; 88   : 			if (npixels & 1) {

	mov	eax, DWORD PTR _npixels$[ebp]
	and	eax, 1
	test	eax, eax
	je	SHORT $L65817

; 89   : 				op[0] |= lastpixel;

	mov	ecx, DWORD PTR _op$[ebp]
	mov	dl, BYTE PTR [ecx]
	or	dl, BYTE PTR _lastpixel$[ebp]
	mov	eax, DWORD PTR _op$[ebp]
	mov	BYTE PTR [eax], dl

; 90   : 				lastpixel = *op++; npixels++; n--;

	mov	ecx, DWORD PTR _op$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	DWORD PTR _lastpixel$[ebp], edx
	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 1
	mov	DWORD PTR _op$[ebp], eax
	mov	ecx, DWORD PTR _npixels$[ebp]
	add	ecx, 1
	mov	DWORD PTR _npixels$[ebp], ecx
	mov	edx, DWORD PTR _n$65810[ebp]
	sub	edx, 1
	mov	DWORD PTR _n$65810[ebp], edx

; 91   : 			} else

	jmp	SHORT $L65818
$L65817:

; 92   : 				lastpixel |= lastpixel << 4;

	mov	eax, DWORD PTR _lastpixel$[ebp]
	shl	eax, 4
	mov	ecx, DWORD PTR _lastpixel$[ebp]
	or	ecx, eax
	mov	DWORD PTR _lastpixel$[ebp], ecx
$L65818:

; 93   : 			npixels += n;

	mov	edx, DWORD PTR _npixels$[ebp]
	add	edx, DWORD PTR _n$65810[ebp]
	mov	DWORD PTR _npixels$[ebp], edx

; 94   : 			for (; n > 0; n -= 2)

	jmp	SHORT $L65819
$L65820:
	mov	eax, DWORD PTR _n$65810[ebp]
	sub	eax, 2
	mov	DWORD PTR _n$65810[ebp], eax
$L65819:
	cmp	DWORD PTR _n$65810[ebp], 0
	jle	SHORT $L65821

; 95   : 				*op++ = lastpixel;

	mov	ecx, DWORD PTR _op$[ebp]
	mov	dl, BYTE PTR _lastpixel$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 1
	mov	DWORD PTR _op$[ebp], eax
	jmp	SHORT $L65820
$L65821:

; 96   : 			if (n == -1)

	cmp	DWORD PTR _n$65810[ebp], -1
	jne	SHORT $L65822

; 97   : 				*--op &= 0xf0;

	mov	ecx, DWORD PTR _op$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _op$[ebp], ecx
	mov	edx, DWORD PTR _op$[ebp]
	mov	al, BYTE PTR [edx]
	and	al, 240					; 000000f0H
	mov	ecx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [ecx], al
$L65822:

; 98   : 			lastpixel &= 0xf;

	mov	edx, DWORD PTR _lastpixel$[ebp]
	and	edx, 15					; 0000000fH
	mov	DWORD PTR _lastpixel$[ebp], edx

; 99   : 			break;

	jmp	$L65813
$L65823:

; 100  : 		case THUNDER_2BITDELTAS:	/* 2-bit deltas */
; 101  : 			if ((delta = ((n >> 4) & 3)) != DELTA2_SKIP)

	mov	eax, DWORD PTR _n$65810[ebp]
	sar	eax, 4
	and	eax, 3
	mov	DWORD PTR _delta$65811[ebp], eax
	cmp	DWORD PTR _delta$65811[ebp], 2
	je	SHORT $L65826

; 102  : 				SETPIXEL(op, lastpixel + twobitdeltas[delta]);

	mov	ecx, DWORD PTR _delta$65811[ebp]
	mov	edx, DWORD PTR _lastpixel$[ebp]
	add	edx, DWORD PTR _twobitdeltas[ecx*4]
	and	edx, 15					; 0000000fH
	mov	DWORD PTR _lastpixel$[ebp], edx
	mov	eax, DWORD PTR _npixels$[ebp]
	and	eax, 1
	mov	ecx, DWORD PTR _npixels$[ebp]
	add	ecx, 1
	mov	DWORD PTR _npixels$[ebp], ecx
	test	eax, eax
	je	SHORT $L65825
	mov	edx, DWORD PTR _op$[ebp]
	mov	al, BYTE PTR [edx]
	or	al, BYTE PTR _lastpixel$[ebp]
	mov	ecx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [ecx], al
	mov	edx, DWORD PTR _op$[ebp]
	add	edx, 1
	mov	DWORD PTR _op$[ebp], edx
	jmp	SHORT $L65826
$L65825:
	mov	eax, DWORD PTR _lastpixel$[ebp]
	shl	eax, 4
	mov	ecx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [ecx], al
$L65826:

; 103  : 			if ((delta = ((n >> 2) & 3)) != DELTA2_SKIP)

	mov	edx, DWORD PTR _n$65810[ebp]
	sar	edx, 2
	and	edx, 3
	mov	DWORD PTR _delta$65811[ebp], edx
	cmp	DWORD PTR _delta$65811[ebp], 2
	je	SHORT $L65829

; 104  : 				SETPIXEL(op, lastpixel + twobitdeltas[delta]);

	mov	eax, DWORD PTR _delta$65811[ebp]
	mov	ecx, DWORD PTR _lastpixel$[ebp]
	add	ecx, DWORD PTR _twobitdeltas[eax*4]
	and	ecx, 15					; 0000000fH
	mov	DWORD PTR _lastpixel$[ebp], ecx
	mov	edx, DWORD PTR _npixels$[ebp]
	and	edx, 1
	mov	eax, DWORD PTR _npixels$[ebp]
	add	eax, 1
	mov	DWORD PTR _npixels$[ebp], eax
	test	edx, edx
	je	SHORT $L65828
	mov	ecx, DWORD PTR _op$[ebp]
	mov	dl, BYTE PTR [ecx]
	or	dl, BYTE PTR _lastpixel$[ebp]
	mov	eax, DWORD PTR _op$[ebp]
	mov	BYTE PTR [eax], dl
	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, 1
	mov	DWORD PTR _op$[ebp], ecx
	jmp	SHORT $L65829
$L65828:
	mov	edx, DWORD PTR _lastpixel$[ebp]
	shl	edx, 4
	mov	eax, DWORD PTR _op$[ebp]
	mov	BYTE PTR [eax], dl
$L65829:

; 105  : 			if ((delta = (n & 3)) != DELTA2_SKIP)

	mov	ecx, DWORD PTR _n$65810[ebp]
	and	ecx, 3
	mov	DWORD PTR _delta$65811[ebp], ecx
	cmp	DWORD PTR _delta$65811[ebp], 2
	je	SHORT $L65832

; 106  : 				SETPIXEL(op, lastpixel + twobitdeltas[delta]);

	mov	edx, DWORD PTR _delta$65811[ebp]
	mov	eax, DWORD PTR _lastpixel$[ebp]
	add	eax, DWORD PTR _twobitdeltas[edx*4]
	and	eax, 15					; 0000000fH
	mov	DWORD PTR _lastpixel$[ebp], eax
	mov	ecx, DWORD PTR _npixels$[ebp]
	and	ecx, 1
	mov	edx, DWORD PTR _npixels$[ebp]
	add	edx, 1
	mov	DWORD PTR _npixels$[ebp], edx
	test	ecx, ecx
	je	SHORT $L65831
	mov	eax, DWORD PTR _op$[ebp]
	mov	cl, BYTE PTR [eax]
	or	cl, BYTE PTR _lastpixel$[ebp]
	mov	edx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [edx], cl
	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 1
	mov	DWORD PTR _op$[ebp], eax
	jmp	SHORT $L65832
$L65831:
	mov	ecx, DWORD PTR _lastpixel$[ebp]
	shl	ecx, 4
	mov	edx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [edx], cl
$L65832:

; 107  : 			break;

	jmp	$L65813
$L65833:

; 108  : 		case THUNDER_3BITDELTAS:	/* 3-bit deltas */
; 109  : 			if ((delta = ((n >> 3) & 7)) != DELTA3_SKIP)

	mov	eax, DWORD PTR _n$65810[ebp]
	sar	eax, 3
	and	eax, 7
	mov	DWORD PTR _delta$65811[ebp], eax
	cmp	DWORD PTR _delta$65811[ebp], 4
	je	SHORT $L65836

; 110  : 				SETPIXEL(op, lastpixel + threebitdeltas[delta]);

	mov	ecx, DWORD PTR _delta$65811[ebp]
	mov	edx, DWORD PTR _lastpixel$[ebp]
	add	edx, DWORD PTR _threebitdeltas[ecx*4]
	and	edx, 15					; 0000000fH
	mov	DWORD PTR _lastpixel$[ebp], edx
	mov	eax, DWORD PTR _npixels$[ebp]
	and	eax, 1
	mov	ecx, DWORD PTR _npixels$[ebp]
	add	ecx, 1
	mov	DWORD PTR _npixels$[ebp], ecx
	test	eax, eax
	je	SHORT $L65835
	mov	edx, DWORD PTR _op$[ebp]
	mov	al, BYTE PTR [edx]
	or	al, BYTE PTR _lastpixel$[ebp]
	mov	ecx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [ecx], al
	mov	edx, DWORD PTR _op$[ebp]
	add	edx, 1
	mov	DWORD PTR _op$[ebp], edx
	jmp	SHORT $L65836
$L65835:
	mov	eax, DWORD PTR _lastpixel$[ebp]
	shl	eax, 4
	mov	ecx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [ecx], al
$L65836:

; 111  : 			if ((delta = (n & 7)) != DELTA3_SKIP)

	mov	edx, DWORD PTR _n$65810[ebp]
	and	edx, 7
	mov	DWORD PTR _delta$65811[ebp], edx
	cmp	DWORD PTR _delta$65811[ebp], 4
	je	SHORT $L65839

; 112  : 				SETPIXEL(op, lastpixel + threebitdeltas[delta]);

	mov	eax, DWORD PTR _delta$65811[ebp]
	mov	ecx, DWORD PTR _lastpixel$[ebp]
	add	ecx, DWORD PTR _threebitdeltas[eax*4]
	and	ecx, 15					; 0000000fH
	mov	DWORD PTR _lastpixel$[ebp], ecx
	mov	edx, DWORD PTR _npixels$[ebp]
	and	edx, 1
	mov	eax, DWORD PTR _npixels$[ebp]
	add	eax, 1
	mov	DWORD PTR _npixels$[ebp], eax
	test	edx, edx
	je	SHORT $L65838
	mov	ecx, DWORD PTR _op$[ebp]
	mov	dl, BYTE PTR [ecx]
	or	dl, BYTE PTR _lastpixel$[ebp]
	mov	eax, DWORD PTR _op$[ebp]
	mov	BYTE PTR [eax], dl
	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, 1
	mov	DWORD PTR _op$[ebp], ecx
	jmp	SHORT $L65839
$L65838:
	mov	edx, DWORD PTR _lastpixel$[ebp]
	shl	edx, 4
	mov	eax, DWORD PTR _op$[ebp]
	mov	BYTE PTR [eax], dl
$L65839:

; 113  : 			break;

	jmp	SHORT $L65813
$L65840:

; 114  : 		case THUNDER_RAW:		/* raw data */
; 115  : 			SETPIXEL(op, n);

	mov	ecx, DWORD PTR _n$65810[ebp]
	and	ecx, 15					; 0000000fH
	mov	DWORD PTR _lastpixel$[ebp], ecx
	mov	edx, DWORD PTR _npixels$[ebp]
	and	edx, 1
	mov	eax, DWORD PTR _npixels$[ebp]
	add	eax, 1
	mov	DWORD PTR _npixels$[ebp], eax
	test	edx, edx
	je	SHORT $L65841
	mov	ecx, DWORD PTR _op$[ebp]
	mov	dl, BYTE PTR [ecx]
	or	dl, BYTE PTR _lastpixel$[ebp]
	mov	eax, DWORD PTR _op$[ebp]
	mov	BYTE PTR [eax], dl
	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, 1
	mov	DWORD PTR _op$[ebp], ecx
	jmp	SHORT $L65842
$L65841:
	mov	edx, DWORD PTR _lastpixel$[ebp]
	shl	edx, 4
	mov	eax, DWORD PTR _op$[ebp]
	mov	BYTE PTR [eax], dl
$L65842:
$L65813:

; 118  : 	}

	jmp	$L65808
$L65809:

; 119  : 	tif->tif_rawcp = (tidata_t) bp;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _bp$[ebp]
	mov	DWORD PTR [ecx+480], edx

; 120  : 	tif->tif_rawcc = cc;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _cc$[ebp]
	mov	DWORD PTR [eax+484], ecx

; 121  : 	if (npixels != maxpixels) {

	mov	edx, DWORD PTR _npixels$[ebp]
	cmp	edx, DWORD PTR _maxpixels$[ebp]
	je	SHORT $L65844

; 122  : 		TIFFError(tif->tif_name,
; 123  : 		    "ThunderDecode: %s data at scanline %ld (%lu != %lu)",
; 124  : 		    npixels < maxpixels ? "Not enough" : "Too much",
; 125  : 		    (long) tif->tif_row, (long) npixels, (long) maxpixels);

	mov	eax, DWORD PTR _npixels$[ebp]
	cmp	eax, DWORD PTR _maxpixels$[ebp]
	jge	SHORT $L65879
	mov	DWORD PTR -32+[ebp], OFFSET FLAT:$SG65848
	jmp	SHORT $L65880
$L65879:
	mov	DWORD PTR -32+[ebp], OFFSET FLAT:$SG65849
$L65880:
	mov	ecx, DWORD PTR _maxpixels$[ebp]
	push	ecx
	mov	edx, DWORD PTR _npixels$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+356]
	push	ecx
	mov	edx, DWORD PTR -32+[ebp]
	push	edx
	push	OFFSET FLAT:$SG65850
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 24					; 00000018H

; 126  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L65801
$L65844:

; 128  : 	return (1);

	mov	eax, 1
$L65801:

; 129  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L65882:
	DD	$L65816
	DD	$L65823
	DD	$L65833
	DD	$L65840
	DD	$L65813
$L65881:
	DB	0
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
	DB	4
	DB	4
	DB	4
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
	DB	4
	DB	4
	DB	4
	DB	2
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
	DB	4
	DB	4
	DB	4
	DB	3
_ThunderDecode ENDP
_TEXT	ENDS
END
