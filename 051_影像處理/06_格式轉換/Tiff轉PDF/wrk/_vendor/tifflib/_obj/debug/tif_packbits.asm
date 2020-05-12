	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_packbits.c
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
PUBLIC	_TIFFInitPackBits
_TEXT	SEGMENT
_tif$ = 8
_TIFFInitPackBits PROC NEAR

; 280  : {

	push	ebp
	mov	ebp, esp

; 281  : 	(void) scheme;
; 282  : 	tif->tif_decoderow = PackBitsDecode;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+416], OFFSET FLAT:_PackBitsDecode

; 283  : 	tif->tif_decodestrip = PackBitsDecode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+424], OFFSET FLAT:_PackBitsDecode

; 284  : 	tif->tif_decodetile = PackBitsDecode;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+432], OFFSET FLAT:_PackBitsDecode

; 285  : 	tif->tif_preencode = PackBitsPreEncode;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+408], OFFSET FLAT:_PackBitsPreEncode

; 286  : 	tif->tif_encoderow = PackBitsEncode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+420], OFFSET FLAT:_PackBitsEncode

; 287  : 	tif->tif_encodestrip = PackBitsEncodeChunk;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+428], OFFSET FLAT:_PackBitsEncodeChunk

; 288  : 	tif->tif_encodetile = PackBitsEncodeChunk;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+436], OFFSET FLAT:_PackBitsEncodeChunk

; 289  : 	return (1);

	mov	eax, 1

; 290  : }

	pop	ebp
	ret	0
_TIFFInitPackBits ENDP
_TEXT	ENDS
EXTRN	_TIFFScanlineSize:NEAR
EXTRN	_TIFFTileRowSize:NEAR
_TEXT	SEGMENT
_tif$ = 8
_PackBitsPreEncode PROC NEAR

; 39   : {

	push	ebp
	mov	ebp, esp

; 40   : 	(void) s;
; 41   : 	/*
; 42   : 	 * Calculate the scanline/tile-width size in bytes.
; 43   : 	 */
; 44   : 	if (isTiled(tif))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 1024				; 00000400H
	test	ecx, ecx
	je	SHORT $L65796

; 45   : 		tif->tif_data = (tidata_t) TIFFTileRowSize(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFTileRowSize
	add	esp, 4
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+460], eax

; 46   : 	else

	jmp	SHORT $L65798
$L65796:

; 47   : 		tif->tif_data = (tidata_t) TIFFScanlineSize(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFScanlineSize
	add	esp, 4
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+460], eax
$L65798:

; 48   : 	return (1);

	mov	eax, 1

; 49   : }

	pop	ebp
	ret	0
_PackBitsPreEncode ENDP
_TEXT	ENDS
EXTRN	_TIFFFlushData1:NEAR
_TEXT	SEGMENT
_tif$ = 8
_buf$ = 12
_cc$ = 16
_bp$ = -28
_op$ = -12
_ep$ = -20
_lastliteral$ = -32
_n$ = -24
_slop$ = -4
_b$ = -8
_state$ = -16
_PackBitsEncode PROC NEAR

; 63   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 36					; 00000024H

; 64   : 	u_char* bp = (u_char*) buf;

	mov	eax, DWORD PTR _buf$[ebp]
	mov	DWORD PTR _bp$[ebp], eax

; 65   : 	tidata_t op, ep, lastliteral;
; 66   : 	long n, slop;
; 67   : 	int b;
; 68   : 	enum { BASE, LITERAL, RUN, LITERAL_RUN } state;
; 69   : 
; 70   : 	(void) s;
; 71   : 	op = tif->tif_rawcp;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+480]
	mov	DWORD PTR _op$[ebp], edx

; 72   : 	ep = tif->tif_rawdata + tif->tif_rawdatasize;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+472]
	mov	edx, DWORD PTR _tif$[ebp]
	add	ecx, DWORD PTR [edx+476]
	mov	DWORD PTR _ep$[ebp], ecx

; 73   : 	state = BASE;

	mov	DWORD PTR _state$[ebp], 0

; 74   : 	lastliteral = 0;

	mov	DWORD PTR _lastliteral$[ebp], 0
$L65827:

; 75   : 	while (cc > 0) {

	cmp	DWORD PTR _cc$[ebp], 0
	jle	$L65828

; 76   : 		/*
; 77   : 		 * Find the longest string of identical bytes.
; 78   : 		 */
; 79   : 		b = *bp++, cc--, n = 1;

	mov	eax, DWORD PTR _bp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	DWORD PTR _b$[ebp], ecx
	mov	edx, DWORD PTR _bp$[ebp]
	add	edx, 1
	mov	DWORD PTR _bp$[ebp], edx
	mov	eax, DWORD PTR _cc$[ebp]
	sub	eax, 1
	mov	DWORD PTR _cc$[ebp], eax
	mov	DWORD PTR _n$[ebp], 1

; 80   : 		for (; cc > 0 && b == *bp; cc--, bp++)

	jmp	SHORT $L65829
$L65830:
	mov	ecx, DWORD PTR _cc$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _cc$[ebp], ecx
	mov	edx, DWORD PTR _bp$[ebp]
	add	edx, 1
	mov	DWORD PTR _bp$[ebp], edx
$L65829:
	cmp	DWORD PTR _cc$[ebp], 0
	jle	SHORT $again$65832
	mov	eax, DWORD PTR _bp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	cmp	DWORD PTR _b$[ebp], ecx
	jne	SHORT $again$65832

; 81   : 			n++;

	mov	edx, DWORD PTR _n$[ebp]
	add	edx, 1
	mov	DWORD PTR _n$[ebp], edx
	jmp	SHORT $L65830
$again$65832:

; 82   : 	again:
; 83   : 		if (op + 2 >= ep) {		/* insure space for new data */

	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 2
	cmp	eax, DWORD PTR _ep$[ebp]
	jb	$L65840

; 84   : 			/*
; 85   : 			 * Be careful about writing the last
; 86   : 			 * literal.  Must write up to that point
; 87   : 			 * and then copy the remainder to the
; 88   : 			 * front of the buffer.
; 89   : 			 */
; 90   : 			if (state == LITERAL || state == LITERAL_RUN) {

	cmp	DWORD PTR _state$[ebp], 1
	je	SHORT $L65835
	cmp	DWORD PTR _state$[ebp], 3
	jne	$L65834
$L65835:

; 91   : 				slop = op - lastliteral;

	mov	ecx, DWORD PTR _op$[ebp]
	sub	ecx, DWORD PTR _lastliteral$[ebp]
	mov	DWORD PTR _slop$[ebp], ecx

; 92   : 				tif->tif_rawcc += lastliteral - tif->tif_rawcp;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _lastliteral$[ebp]
	sub	eax, DWORD PTR [edx+480]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+484]
	add	edx, eax
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+484], edx

; 93   : 				if (!TIFFFlushData1(tif))

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFlushData1
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65836

; 94   : 					return (-1);

	or	eax, -1
	jmp	$L65810
$L65836:

; 95   : 				op = tif->tif_rawcp;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+480]
	mov	DWORD PTR _op$[ebp], eax
$L65838:

; 96   : 				while (slop-- > 0)

	mov	ecx, DWORD PTR _slop$[ebp]
	mov	edx, DWORD PTR _slop$[ebp]
	sub	edx, 1
	mov	DWORD PTR _slop$[ebp], edx
	test	ecx, ecx
	jle	SHORT $L65839

; 97   : 					*op++ = *lastliteral++;

	mov	eax, DWORD PTR _op$[ebp]
	mov	ecx, DWORD PTR _lastliteral$[ebp]
	mov	dl, BYTE PTR [ecx]
	mov	BYTE PTR [eax], dl
	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 1
	mov	DWORD PTR _op$[ebp], eax
	mov	ecx, DWORD PTR _lastliteral$[ebp]
	add	ecx, 1
	mov	DWORD PTR _lastliteral$[ebp], ecx
	jmp	SHORT $L65838
$L65839:

; 98   : 				lastliteral = tif->tif_rawcp;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+480]
	mov	DWORD PTR _lastliteral$[ebp], eax

; 99   : 			} else {

	jmp	SHORT $L65840
$L65834:

; 100  : 				tif->tif_rawcc += op - tif->tif_rawcp;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _op$[ebp]
	sub	edx, DWORD PTR [ecx+480]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+484]
	add	ecx, edx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], ecx

; 101  : 				if (!TIFFFlushData1(tif))

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFlushData1
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65841

; 102  : 					return (-1);

	or	eax, -1
	jmp	$L65810
$L65841:

; 103  : 				op = tif->tif_rawcp;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+480]
	mov	DWORD PTR _op$[ebp], edx
$L65840:

; 106  : 		switch (state) {

	mov	eax, DWORD PTR _state$[ebp]
	mov	DWORD PTR -36+[ebp], eax
	cmp	DWORD PTR -36+[ebp], 3
	ja	$L65843
	mov	ecx, DWORD PTR -36+[ebp]
	jmp	DWORD PTR $L65940[ecx*4]
$L65846:

; 107  : 		case BASE:		/* initial state, set run/literal */
; 108  : 			if (n > 1) {

	cmp	DWORD PTR _n$[ebp], 1
	jle	SHORT $L65847

; 109  : 				state = RUN;

	mov	DWORD PTR _state$[ebp], 2

; 110  : 				if (n > 128) {

	cmp	DWORD PTR _n$[ebp], 128			; 00000080H
	jle	SHORT $L65848

; 111  : 					*op++ = (tidata) -127;

	mov	edx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [edx], 129			; 00000081H
	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 1
	mov	DWORD PTR _op$[ebp], eax

; 112  : 					*op++ = b;

	mov	ecx, DWORD PTR _op$[ebp]
	mov	dl, BYTE PTR _b$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 1
	mov	DWORD PTR _op$[ebp], eax

; 113  : 					n -= 128;

	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 128				; 00000080H
	mov	DWORD PTR _n$[ebp], ecx

; 114  : 					goto again;

	jmp	$again$65832
$L65848:

; 116  : 				*op++ = (tidataval_t)(-(n-1));

	mov	edx, DWORD PTR _n$[ebp]
	sub	edx, 1
	neg	edx
	mov	eax, DWORD PTR _op$[ebp]
	mov	BYTE PTR [eax], dl
	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, 1
	mov	DWORD PTR _op$[ebp], ecx

; 117  : 				*op++ = b;

	mov	edx, DWORD PTR _op$[ebp]
	mov	al, BYTE PTR _b$[ebp]
	mov	BYTE PTR [edx], al
	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, 1
	mov	DWORD PTR _op$[ebp], ecx

; 118  : 			} else {

	jmp	SHORT $L65851
$L65847:

; 119  : 				lastliteral = op;

	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR _lastliteral$[ebp], edx

; 120  : 				*op++ = 0;

	mov	eax, DWORD PTR _op$[ebp]
	mov	BYTE PTR [eax], 0
	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, 1
	mov	DWORD PTR _op$[ebp], ecx

; 121  : 				*op++ = b;

	mov	edx, DWORD PTR _op$[ebp]
	mov	al, BYTE PTR _b$[ebp]
	mov	BYTE PTR [edx], al
	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, 1
	mov	DWORD PTR _op$[ebp], ecx

; 122  : 				state = LITERAL;

	mov	DWORD PTR _state$[ebp], 1
$L65851:

; 124  : 			break;

	jmp	$L65843
$L65852:

; 125  : 		case LITERAL:		/* last object was literal string */
; 126  : 			if (n > 1) {

	cmp	DWORD PTR _n$[ebp], 1
	jle	SHORT $L65853

; 127  : 				state = LITERAL_RUN;

	mov	DWORD PTR _state$[ebp], 3

; 128  : 				if (n > 128) {

	cmp	DWORD PTR _n$[ebp], 128			; 00000080H
	jle	SHORT $L65854

; 129  : 					*op++ = (tidata) -127;

	mov	edx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [edx], 129			; 00000081H
	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 1
	mov	DWORD PTR _op$[ebp], eax

; 130  : 					*op++ = b;

	mov	ecx, DWORD PTR _op$[ebp]
	mov	dl, BYTE PTR _b$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 1
	mov	DWORD PTR _op$[ebp], eax

; 131  : 					n -= 128;

	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 128				; 00000080H
	mov	DWORD PTR _n$[ebp], ecx

; 132  : 					goto again;

	jmp	$again$65832
$L65854:

; 134  : 				*op++ = (tidataval_t)(-(n-1));	/* encode run */

	mov	edx, DWORD PTR _n$[ebp]
	sub	edx, 1
	neg	edx
	mov	eax, DWORD PTR _op$[ebp]
	mov	BYTE PTR [eax], dl
	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, 1
	mov	DWORD PTR _op$[ebp], ecx

; 135  : 				*op++ = b;

	mov	edx, DWORD PTR _op$[ebp]
	mov	al, BYTE PTR _b$[ebp]
	mov	BYTE PTR [edx], al
	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, 1
	mov	DWORD PTR _op$[ebp], ecx

; 136  : 			} else {			/* extend literal */

	jmp	SHORT $L65857
$L65853:

; 137  : 				if (++(*lastliteral) == 127)

	mov	edx, DWORD PTR _lastliteral$[ebp]
	mov	al, BYTE PTR [edx]
	add	al, 1
	mov	ecx, DWORD PTR _lastliteral$[ebp]
	mov	BYTE PTR [ecx], al
	mov	edx, DWORD PTR _lastliteral$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	cmp	eax, 127				; 0000007fH
	jne	SHORT $L65858

; 138  : 					state = BASE;

	mov	DWORD PTR _state$[ebp], 0
$L65858:

; 139  : 				*op++ = b;

	mov	ecx, DWORD PTR _op$[ebp]
	mov	dl, BYTE PTR _b$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 1
	mov	DWORD PTR _op$[ebp], eax
$L65857:

; 141  : 			break;

	jmp	$L65843
$L65859:

; 142  : 		case RUN:		/* last object was run */
; 143  : 			if (n > 1) {

	cmp	DWORD PTR _n$[ebp], 1
	jle	SHORT $L65860

; 144  : 				if (n > 128) {

	cmp	DWORD PTR _n$[ebp], 128			; 00000080H
	jle	SHORT $L65861

; 145  : 					*op++ = (tidata) -127;

	mov	ecx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [ecx], 129			; 00000081H
	mov	edx, DWORD PTR _op$[ebp]
	add	edx, 1
	mov	DWORD PTR _op$[ebp], edx

; 146  : 					*op++ = b;

	mov	eax, DWORD PTR _op$[ebp]
	mov	cl, BYTE PTR _b$[ebp]
	mov	BYTE PTR [eax], cl
	mov	edx, DWORD PTR _op$[ebp]
	add	edx, 1
	mov	DWORD PTR _op$[ebp], edx

; 147  : 					n -= 128;

	mov	eax, DWORD PTR _n$[ebp]
	sub	eax, 128				; 00000080H
	mov	DWORD PTR _n$[ebp], eax

; 148  : 					goto again;

	jmp	$again$65832
$L65861:

; 150  : 				*op++ = (tidataval_t)(-(n-1));

	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	neg	ecx
	mov	edx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [edx], cl
	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 1
	mov	DWORD PTR _op$[ebp], eax

; 151  : 				*op++ = b;

	mov	ecx, DWORD PTR _op$[ebp]
	mov	dl, BYTE PTR _b$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 1
	mov	DWORD PTR _op$[ebp], eax

; 152  : 			} else {

	jmp	SHORT $L65864
$L65860:

; 153  : 				lastliteral = op;

	mov	ecx, DWORD PTR _op$[ebp]
	mov	DWORD PTR _lastliteral$[ebp], ecx

; 154  : 				*op++ = 0;

	mov	edx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [edx], 0
	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 1
	mov	DWORD PTR _op$[ebp], eax

; 155  : 				*op++ = b;

	mov	ecx, DWORD PTR _op$[ebp]
	mov	dl, BYTE PTR _b$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 1
	mov	DWORD PTR _op$[ebp], eax

; 156  : 				state = LITERAL;

	mov	DWORD PTR _state$[ebp], 1
$L65864:

; 158  : 			break;

	jmp	SHORT $L65843
$L65865:

; 159  : 		case LITERAL_RUN:	/* literal followed by a run */
; 160  : 			/*
; 161  : 			 * Check to see if previous run should
; 162  : 			 * be converted to a literal, in which
; 163  : 			 * case we convert literal-run-literal
; 164  : 			 * to a single literal.
; 165  : 			 */
; 166  : 			if (n == 1 && op[-2] == (tidata) -1 &&
; 167  : 			    *lastliteral < 126) {

	cmp	DWORD PTR _n$[ebp], 1
	jne	SHORT $L65867
	mov	ecx, DWORD PTR _op$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx-2]
	cmp	edx, 255				; 000000ffH
	jne	SHORT $L65867
	mov	eax, DWORD PTR _lastliteral$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	cmp	ecx, 126				; 0000007eH
	jge	SHORT $L65867

; 168  : 				state = (((*lastliteral) += 2) == 127 ?
; 169  : 				    BASE : LITERAL);

	mov	edx, DWORD PTR _lastliteral$[ebp]
	mov	al, BYTE PTR [edx]
	add	al, 2
	mov	ecx, DWORD PTR _lastliteral$[ebp]
	mov	BYTE PTR [ecx], al
	mov	edx, DWORD PTR _lastliteral$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	xor	ecx, ecx
	cmp	eax, 127				; 0000007fH
	setne	cl
	mov	DWORD PTR _state$[ebp], ecx

; 170  : 				op[-2] = op[-1];	/* replicate */

	mov	edx, DWORD PTR _op$[ebp]
	mov	eax, DWORD PTR _op$[ebp]
	mov	cl, BYTE PTR [eax-1]
	mov	BYTE PTR [edx-2], cl

; 171  : 			} else

	jmp	SHORT $L65868
$L65867:

; 172  : 				state = RUN;

	mov	DWORD PTR _state$[ebp], 2
$L65868:

; 173  : 			goto again;

	jmp	$again$65832
$L65843:

; 175  : 	}

	jmp	$L65827
$L65828:

; 176  : 	tif->tif_rawcc += op - tif->tif_rawcp;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _op$[ebp]
	sub	eax, DWORD PTR [edx+480]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+484]
	add	edx, eax
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+484], edx

; 177  : 	tif->tif_rawcp = op;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR [ecx+480], edx

; 178  : 	return (1);

	mov	eax, 1
$L65810:

; 179  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L65940:
	DD	$L65846
	DD	$L65852
	DD	$L65859
	DD	$L65865
_PackBitsEncode ENDP
_TEXT	ENDS
EXTRN	__assert:NEAR
_DATA	SEGMENT
$SG65882 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_packbits.c', 00H
	ORG $+3
$SG65883 DB	'rowsize > 0', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_bp$ = 12
_cc$ = 16
_s$ = 20
_rowsize$ = -4
_chunk$65890 = -8
_PackBitsEncodeChunk PROC NEAR

; 190  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 191  :     tsize_t rowsize = (tsize_t) tif->tif_data;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _rowsize$[ebp], ecx

; 192  : 
; 193  :     assert(rowsize > 0);

	cmp	DWORD PTR _rowsize$[ebp], 0
	jg	SHORT $L65942
	push	193					; 000000c1H
	push	OFFSET FLAT:$SG65882
	push	OFFSET FLAT:$SG65883
	call	__assert
	add	esp, 12					; 0000000cH
$L65942:

; 194  :     
; 195  : #ifdef YCBCR_SUPPORT
; 196  :     /* 
; 197  :      * YCBCR data isn't really separable into rows, so we
; 198  :      * might as well encode the whole tile/strip as one chunk.
; 199  :      */
; 200  :     if( tif->tif_dir.td_photometric == PHOTOMETRIC_YCBCR )

	mov	eax, DWORD PTR _tif$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+70]
	cmp	ecx, 6
	jne	SHORT $L65884

; 201  :         rowsize = (tsize_t) tif->tif_data;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+460]
	mov	DWORD PTR _rowsize$[ebp], eax
$L65884:

; 202  : #endif
; 203  : 
; 204  :     while ((long)cc > 0) {

	cmp	DWORD PTR _cc$[ebp], 0
	jle	SHORT $L65889

; 205  :         int	chunk = rowsize;

	mov	ecx, DWORD PTR _rowsize$[ebp]
	mov	DWORD PTR _chunk$65890[ebp], ecx

; 206  :         
; 207  :         if( cc < chunk )

	mov	edx, DWORD PTR _cc$[ebp]
	cmp	edx, DWORD PTR _chunk$65890[ebp]
	jge	SHORT $L65891

; 208  :             chunk = cc;

	mov	eax, DWORD PTR _cc$[ebp]
	mov	DWORD PTR _chunk$65890[ebp], eax
$L65891:

; 209  : 
; 210  :         if (PackBitsEncode(tif, bp, chunk, s) < 0)

	mov	cx, WORD PTR _s$[ebp]
	push	ecx
	mov	edx, DWORD PTR _chunk$65890[ebp]
	push	edx
	mov	eax, DWORD PTR _bp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_PackBitsEncode
	add	esp, 16					; 00000010H
	test	eax, eax
	jge	SHORT $L65892

; 211  :             return (-1);

	or	eax, -1
	jmp	SHORT $L65878
$L65892:

; 212  :         bp += chunk;

	mov	edx, DWORD PTR _bp$[ebp]
	add	edx, DWORD PTR _chunk$65890[ebp]
	mov	DWORD PTR _bp$[ebp], edx

; 213  :         cc -= chunk;

	mov	eax, DWORD PTR _cc$[ebp]
	sub	eax, DWORD PTR _chunk$65890[ebp]
	mov	DWORD PTR _cc$[ebp], eax

; 214  :     }

	jmp	SHORT $L65884
$L65889:

; 215  :     return (1);

	mov	eax, 1
$L65878:

; 216  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_PackBitsEncodeChunk ENDP
_TEXT	ENDS
EXTRN	__TIFFmemcpy:NEAR
EXTRN	_TIFFError:NEAR
EXTRN	_TIFFWarning:NEAR
_DATA	SEGMENT
$SG65918 DB	'PackBitsDecode: discarding %d bytes to avoid buffer over'
	DB	'run', 00H
$SG65924 DB	'PackBitsDecode: discarding %d bytes to avoid buffer over'
	DB	'run', 00H
$SG65928 DB	'PackBitsDecode: Not enough data for scanline %ld', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_op$ = 12
_occ$ = 16
_bp$ = -16
_cc$ = -8
_n$ = -12
_b$ = -4
_PackBitsDecode PROC NEAR

; 220  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 221  : 	char *bp;
; 222  : 	tsize_t cc;
; 223  : 	long n;
; 224  : 	int b;
; 225  : 
; 226  : 	(void) s;
; 227  : 	bp = (char*) tif->tif_rawcp;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	DWORD PTR _bp$[ebp], ecx

; 228  : 	cc = tif->tif_rawcc;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+484]
	mov	DWORD PTR _cc$[ebp], eax
$L65911:

; 229  : 	while (cc > 0 && (long)occ > 0) {

	cmp	DWORD PTR _cc$[ebp], 0
	jle	$L65912
	cmp	DWORD PTR _occ$[ebp], 0
	jle	$L65912

; 230  : 		n = (long) *bp++, cc--;

	mov	ecx, DWORD PTR _bp$[ebp]
	movsx	edx, BYTE PTR [ecx]
	mov	DWORD PTR _n$[ebp], edx
	mov	eax, DWORD PTR _bp$[ebp]
	add	eax, 1
	mov	DWORD PTR _bp$[ebp], eax
	mov	ecx, DWORD PTR _cc$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _cc$[ebp], ecx

; 231  : 		/*
; 232  : 		 * Watch out for compilers that
; 233  : 		 * don't sign extend chars...
; 234  : 		 */
; 235  : 		if (n >= 128)

	cmp	DWORD PTR _n$[ebp], 128			; 00000080H
	jl	SHORT $L65914

; 236  : 			n -= 256;

	mov	edx, DWORD PTR _n$[ebp]
	sub	edx, 256				; 00000100H
	mov	DWORD PTR _n$[ebp], edx
$L65914:

; 237  : 		if (n < 0) {		/* replicate next byte -n+1 times */

	cmp	DWORD PTR _n$[ebp], 0
	jge	$L65915

; 238  : 			if (n == -128)	/* nop */

	cmp	DWORD PTR _n$[ebp], -128		; ffffff80H
	jne	SHORT $L65916

; 239  : 				continue;

	jmp	SHORT $L65911
$L65916:

; 240  :                         n = -n + 1;

	mov	eax, DWORD PTR _n$[ebp]
	neg	eax
	add	eax, 1
	mov	DWORD PTR _n$[ebp], eax

; 241  :                         if( occ < n )

	mov	ecx, DWORD PTR _occ$[ebp]
	cmp	ecx, DWORD PTR _n$[ebp]
	jge	SHORT $L65917

; 243  :                             TIFFWarning(tif->tif_name,
; 244  :                                         "PackBitsDecode: discarding %d bytes "
; 245  :                                         "to avoid buffer overrun",
; 246  :                                         n - occ);

	mov	edx, DWORD PTR _n$[ebp]
	sub	edx, DWORD PTR _occ$[ebp]
	push	edx
	push	OFFSET FLAT:$SG65918
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFWarning
	add	esp, 12					; 0000000cH

; 247  :                             n = occ;

	mov	edx, DWORD PTR _occ$[ebp]
	mov	DWORD PTR _n$[ebp], edx
$L65917:

; 249  : 			occ -= n;

	mov	eax, DWORD PTR _occ$[ebp]
	sub	eax, DWORD PTR _n$[ebp]
	mov	DWORD PTR _occ$[ebp], eax

; 250  : 			b = *bp++, cc--;

	mov	ecx, DWORD PTR _bp$[ebp]
	movsx	edx, BYTE PTR [ecx]
	mov	DWORD PTR _b$[ebp], edx
	mov	eax, DWORD PTR _bp$[ebp]
	add	eax, 1
	mov	DWORD PTR _bp$[ebp], eax
	mov	ecx, DWORD PTR _cc$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _cc$[ebp], ecx
$L65920:

; 251  : 			while (n-- > 0)

	mov	edx, DWORD PTR _n$[ebp]
	mov	eax, DWORD PTR _n$[ebp]
	sub	eax, 1
	mov	DWORD PTR _n$[ebp], eax
	test	edx, edx
	jle	SHORT $L65921

; 252  : 				*op++ = b;

	mov	ecx, DWORD PTR _op$[ebp]
	mov	dl, BYTE PTR _b$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 1
	mov	DWORD PTR _op$[ebp], eax
	jmp	SHORT $L65920
$L65921:

; 253  : 		} else {		/* copy next n+1 bytes literally */

	jmp	SHORT $L65922
$L65915:

; 254  : 			if (occ < n + 1)

	mov	ecx, DWORD PTR _n$[ebp]
	add	ecx, 1
	cmp	DWORD PTR _occ$[ebp], ecx
	jge	SHORT $L65923

; 256  :                             TIFFWarning(tif->tif_name,
; 257  :                                         "PackBitsDecode: discarding %d bytes "
; 258  :                                         "to avoid buffer overrun",
; 259  :                                         n - occ + 1);

	mov	edx, DWORD PTR _n$[ebp]
	sub	edx, DWORD PTR _occ$[ebp]
	add	edx, 1
	push	edx
	push	OFFSET FLAT:$SG65924
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFWarning
	add	esp, 12					; 0000000cH

; 260  :                             n = occ - 1;

	mov	edx, DWORD PTR _occ$[ebp]
	sub	edx, 1
	mov	DWORD PTR _n$[ebp], edx
$L65923:

; 262  :                         _TIFFmemcpy(op, bp, ++n);

	mov	eax, DWORD PTR _n$[ebp]
	add	eax, 1
	mov	DWORD PTR _n$[ebp], eax
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	mov	edx, DWORD PTR _bp$[ebp]
	push	edx
	mov	eax, DWORD PTR _op$[ebp]
	push	eax
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH

; 263  : 			op += n; occ -= n;

	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, DWORD PTR _n$[ebp]
	mov	DWORD PTR _op$[ebp], ecx
	mov	edx, DWORD PTR _occ$[ebp]
	sub	edx, DWORD PTR _n$[ebp]
	mov	DWORD PTR _occ$[ebp], edx

; 264  : 			bp += n; cc -= n;

	mov	eax, DWORD PTR _bp$[ebp]
	add	eax, DWORD PTR _n$[ebp]
	mov	DWORD PTR _bp$[ebp], eax
	mov	ecx, DWORD PTR _cc$[ebp]
	sub	ecx, DWORD PTR _n$[ebp]
	mov	DWORD PTR _cc$[ebp], ecx
$L65922:

; 266  : 	}

	jmp	$L65911
$L65912:

; 267  : 	tif->tif_rawcp = (tidata_t) bp;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _bp$[ebp]
	mov	DWORD PTR [edx+480], eax

; 268  : 	tif->tif_rawcc = cc;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _cc$[ebp]
	mov	DWORD PTR [ecx+484], edx

; 269  : 	if (occ > 0) {

	cmp	DWORD PTR _occ$[ebp], 0
	jle	SHORT $L65926

; 270  : 		TIFFError(tif->tif_name,
; 271  : 		    "PackBitsDecode: Not enough data for scanline %ld",
; 272  : 		    (long) tif->tif_row);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+356]
	push	ecx
	push	OFFSET FLAT:$SG65928
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 273  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L65902
$L65926:

; 275  : 	return (1);

	mov	eax, 1
$L65902:

; 276  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_PackBitsDecode ENDP
_TEXT	ENDS
END
