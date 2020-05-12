	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_predict.c
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
_predictFieldInfo DD 013dH
	DW	01H
	DW	01H
	DD	03H
	DW	03fH
	DB	00H
	DB	00H
	DD	FLAT:$SG66217
CONST	ENDS
_DATA	SEGMENT
$SG66217 DB	'Predictor', 00H
_DATA	ENDS
PUBLIC	_TIFFPredictorInit
EXTRN	__TIFFMergeFieldInfo:NEAR
_TEXT	SEGMENT
_tif$ = 8
_sp$ = -4
_TIFFPredictorInit PROC NEAR

; 438  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 439  : 	TIFFPredictorState* sp = PredictorState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 440  : 
; 441  : 	/*
; 442  : 	 * Merge codec-specific tag information and
; 443  : 	 * override parent get/set field methods.
; 444  : 	 */
; 445  : 	_TIFFMergeFieldInfo(tif, predictFieldInfo, N(predictFieldInfo));

	push	1
	push	OFFSET FLAT:_predictFieldInfo
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	__TIFFMergeFieldInfo
	add	esp, 12					; 0000000cH

; 446  : 	sp->vgetparent = tif->tif_vgetfield;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+544]
	mov	DWORD PTR [eax+28], edx

; 447  : 	tif->tif_vgetfield = PredictorVGetField;/* hook for predictor tag */

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+544], OFFSET FLAT:_PredictorVGetField

; 448  : 	sp->vsetparent = tif->tif_vsetfield;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+540]
	mov	DWORD PTR [ecx+32], eax

; 449  : 	tif->tif_vsetfield = PredictorVSetField;/* hook for predictor tag */

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+540], OFFSET FLAT:_PredictorVSetField

; 450  : 	sp->printdir = tif->tif_printdir;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+548]
	mov	DWORD PTR [edx+36], ecx

; 451  : 	tif->tif_printdir = PredictorPrintDir;	/* hook for predictor tag */

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+548], OFFSET FLAT:_PredictorPrintDir

; 452  : 
; 453  : 	sp->setupdecode = tif->tif_setupdecode;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+396]
	mov	DWORD PTR [eax+40], edx

; 454  : 	tif->tif_setupdecode = PredictorSetupDecode;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+396], OFFSET FLAT:_PredictorSetupDecode

; 455  : 	sp->setupencode = tif->tif_setupencode;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+404]
	mov	DWORD PTR [ecx+44], eax

; 456  : 	tif->tif_setupencode = PredictorSetupEncode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+404], OFFSET FLAT:_PredictorSetupEncode

; 457  : 
; 458  : 	sp->predictor = 1;			/* default value */

	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx], 1

; 459  : 	sp->pfunc = NULL;			/* no predictor routine */

	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+12], 0

; 460  : 	return (1);

	mov	eax, 1

; 461  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFPredictorInit ENDP
_TEXT	ENDS
EXTRN	__TIFFNoPostDecode:NEAR
_TEXT	SEGMENT
_tif$ = 8
_sp$ = -4
_td$ = -8
_PredictorSetupDecode PROC NEAR

; 82   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 83   : 	TIFFPredictorState* sp = PredictorState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 84   : 	TIFFDirectory* td = &tif->tif_dir;

	mov	edx, DWORD PTR _tif$[ebp]
	add	edx, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], edx

; 85   : 
; 86   : 	if (!(*sp->setupdecode)(tif) || !PredictorSetup(tif))

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	mov	ecx, DWORD PTR _sp$[ebp]
	call	DWORD PTR [ecx+40]
	add	esp, 4
	test	eax, eax
	je	SHORT $L65870
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_PredictorSetup
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65869
$L65870:

; 87   : 		return (0);

	xor	eax, eax
	jmp	$L65865
$L65869:

; 88   : 	if (sp->predictor == 2) {

	mov	eax, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [eax], 2
	jne	$L65879

; 89   : 		switch (td->td_bitspersample) {

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+40]
	mov	DWORD PTR -12+[ebp], edx
	cmp	DWORD PTR -12+[ebp], 8
	je	SHORT $L65876
	cmp	DWORD PTR -12+[ebp], 16			; 00000010H
	je	SHORT $L65877
	jmp	SHORT $L65873
$L65876:

; 90   : 		case 8:  sp->pfunc = horAcc8; break;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+12], OFFSET FLAT:_horAcc8
	jmp	SHORT $L65873
$L65877:

; 91   : 		case 16: sp->pfunc = horAcc16; break;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+12], OFFSET FLAT:_horAcc16
$L65873:

; 93   : 		/*
; 94   : 		 * Override default decoding method with
; 95   : 		 * one that does the predictor stuff.
; 96   : 		 */
; 97   : 		sp->coderow = tif->tif_decoderow;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+416]
	mov	DWORD PTR [edx+16], ecx

; 98   : 		tif->tif_decoderow = PredictorDecodeRow;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+416], OFFSET FLAT:_PredictorDecodeRow

; 99   : 		sp->codestrip = tif->tif_decodestrip;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+424]
	mov	DWORD PTR [eax+20], edx

; 100  : 		tif->tif_decodestrip = PredictorDecodeTile;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+424], OFFSET FLAT:_PredictorDecodeTile

; 101  : 		sp->codetile = tif->tif_decodetile;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+432]
	mov	DWORD PTR [ecx+24], eax

; 102  : 		tif->tif_decodetile = PredictorDecodeTile;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+432], OFFSET FLAT:_PredictorDecodeTile

; 103  : 		/*
; 104  : 		 * If the data is horizontally differenced
; 105  : 		 * 16-bit data that requires byte-swapping,
; 106  : 		 * then it must be byte swapped before the
; 107  : 		 * accumulation step.  We do this with a
; 108  : 		 * special-purpose routine and override the
; 109  : 		 * normal post decoding logic that the library
; 110  : 		 * setup when the directory was read.
; 111  : 		 */
; 112  : 		if (tif->tif_flags&TIFF_SWAB) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 128				; 00000080H
	test	eax, eax
	je	SHORT $L65879

; 113  : 			if (sp->pfunc == horAcc16) {

	mov	ecx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [ecx+12], OFFSET FLAT:_horAcc16
	jne	SHORT $L65879

; 114  : 				sp->pfunc = swabHorAcc16;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+12], OFFSET FLAT:_swabHorAcc16

; 115  : 				tif->tif_postdecode = _TIFFNoPostDecode;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+528], OFFSET FLAT:__TIFFNoPostDecode
$L65879:

; 119  : 	return (1);

	mov	eax, 1
$L65865:

; 120  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_PredictorSetupDecode ENDP
_TEXT	ENDS
EXTRN	_TIFFScanlineSize:NEAR
EXTRN	_TIFFTileRowSize:NEAR
EXTRN	_TIFFError:NEAR
_DATA	SEGMENT
	ORG $+2
$SG65857 DB	'"Predictor" value %d not supported', 00H
	ORG $+1
$SG65859 DB	'Horizontal differencing "Predictor" not supported with %'
	DB	'd-bit samples', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_sp$ = -4
_td$ = -8
_PredictorSetup PROC NEAR

; 51   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 52   : 	TIFFPredictorState* sp = PredictorState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 53   : 	TIFFDirectory* td = &tif->tif_dir;

	mov	edx, DWORD PTR _tif$[ebp]
	add	edx, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], edx

; 54   : 
; 55   : 	if (sp->predictor == 1)		/* no differencing */

	mov	eax, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [eax], 1
	jne	SHORT $L65855

; 56   : 		return (1);

	mov	eax, 1
	jmp	$L65851
$L65855:

; 57   : 	if (sp->predictor != 2) {

	mov	ecx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [ecx], 2
	je	SHORT $L65856

; 58   : 		TIFFError(tif->tif_name, "\"Predictor\" value %d not supported",
; 59   : 		    sp->predictor);

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	push	OFFSET FLAT:$SG65857
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 60   : 		return (0);

	xor	eax, eax
	jmp	$L65851
$L65856:

; 62   : 	if (td->td_bitspersample != 8 && td->td_bitspersample != 16) {

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+40]
	cmp	ecx, 8
	je	SHORT $L65858
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+40]
	cmp	eax, 16					; 00000010H
	je	SHORT $L65858

; 63   : 		TIFFError(tif->tif_name,
; 64   :     "Horizontal differencing \"Predictor\" not supported with %d-bit samples",
; 65   : 		    td->td_bitspersample);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+40]
	push	edx
	push	OFFSET FLAT:$SG65859
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 66   : 		return (0);

	xor	eax, eax
	jmp	SHORT $L65851
$L65858:

; 68   : 	sp->stride = (td->td_planarconfig == PLANARCONFIG_CONTIG ?
; 69   : 	    td->td_samplesperpixel : 1);

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+90]
	cmp	eax, 1
	jne	SHORT $L66302
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+54]
	mov	DWORD PTR -12+[ebp], edx
	jmp	SHORT $L66303
$L66302:
	mov	DWORD PTR -12+[ebp], 1
$L66303:
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR -12+[ebp]
	mov	DWORD PTR [eax+4], ecx

; 70   : 	/*
; 71   : 	 * Calculate the scanline/tile-width size in bytes.
; 72   : 	 */
; 73   : 	if (isTiled(tif))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 1024				; 00000400H
	test	eax, eax
	je	SHORT $L65860

; 74   : 		sp->rowsize = TIFFTileRowSize(tif);

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFTileRowSize
	add	esp, 4
	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+8], eax

; 75   : 	else

	jmp	SHORT $L65861
$L65860:

; 76   : 		sp->rowsize = TIFFScanlineSize(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFScanlineSize
	add	esp, 4
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+8], eax
$L65861:

; 77   : 	return (1);

	mov	eax, 1
$L65851:

; 78   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_PredictorSetup ENDP
_tif$ = 8
_sp$ = -4
_td$ = -8
_PredictorSetupEncode PROC NEAR

; 124  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 125  : 	TIFFPredictorState* sp = PredictorState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 126  : 	TIFFDirectory* td = &tif->tif_dir;

	mov	edx, DWORD PTR _tif$[ebp]
	add	edx, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], edx

; 127  : 
; 128  : 	if (!(*sp->setupencode)(tif) || !PredictorSetup(tif))

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	mov	ecx, DWORD PTR _sp$[ebp]
	call	DWORD PTR [ecx+44]
	add	esp, 4
	test	eax, eax
	je	SHORT $L65888
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_PredictorSetup
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65887
$L65888:

; 129  : 		return (0);

	xor	eax, eax
	jmp	$L65883
$L65887:

; 130  : 	if (sp->predictor == 2) {

	mov	eax, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [eax], 2
	jne	$L65889

; 131  : 		switch (td->td_bitspersample) {

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+40]
	mov	DWORD PTR -12+[ebp], edx
	cmp	DWORD PTR -12+[ebp], 8
	je	SHORT $L65894
	cmp	DWORD PTR -12+[ebp], 16			; 00000010H
	je	SHORT $L65895
	jmp	SHORT $L65891
$L65894:

; 132  : 		case 8:  sp->pfunc = horDiff8; break;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+12], OFFSET FLAT:_horDiff8
	jmp	SHORT $L65891
$L65895:

; 133  : 		case 16: sp->pfunc = horDiff16; break;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+12], OFFSET FLAT:_horDiff16
$L65891:

; 135  : 		/*
; 136  : 		 * Override default encoding method with
; 137  : 		 * one that does the predictor stuff.
; 138  : 		 */
; 139  : 		sp->coderow = tif->tif_encoderow;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+420]
	mov	DWORD PTR [edx+16], ecx

; 140  : 		tif->tif_encoderow = PredictorEncodeRow;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+420], OFFSET FLAT:_PredictorEncodeRow

; 141  : 		sp->codestrip = tif->tif_encodestrip;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+428]
	mov	DWORD PTR [eax+20], edx

; 142  : 		tif->tif_encodestrip = PredictorEncodeTile;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+428], OFFSET FLAT:_PredictorEncodeTile

; 143  : 		sp->codetile = tif->tif_encodetile;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+436]
	mov	DWORD PTR [ecx+24], eax

; 144  : 		tif->tif_encodetile = PredictorEncodeTile;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+436], OFFSET FLAT:_PredictorEncodeTile
$L65889:

; 146  : 	return (1);

	mov	eax, 1
$L65883:

; 147  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_PredictorSetupEncode ENDP
_tif$ = 8
_cp0$ = 12
_cc$ = 16
_sp$ = -8
_stride$ = -12
_cp$ = -4
_cr$65911 = -20
_cg$65912 = -24
_cb$65913 = -16
_cr$65920 = -36
_cg$65921 = -40
_cb$65922 = -32
_ca$65923 = -28
_i$65937 = -44
_horAcc8 PROC NEAR

; 161  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 48					; 00000030H

; 162  : 	TIFFPredictorState* sp = PredictorState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 163  : 	tsize_t stride = sp->stride;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _stride$[ebp], eax

; 164  : 
; 165  : 	char* cp = (char*) cp0;

	mov	ecx, DWORD PTR _cp0$[ebp]
	mov	DWORD PTR _cp$[ebp], ecx

; 166  : 	if (cc > stride) {

	mov	edx, DWORD PTR _cc$[ebp]
	cmp	edx, DWORD PTR _stride$[ebp]
	jle	$L65931

; 167  : 		cc -= stride;

	mov	eax, DWORD PTR _cc$[ebp]
	sub	eax, DWORD PTR _stride$[ebp]
	mov	DWORD PTR _cc$[ebp], eax

; 168  : 		/*
; 169  : 		 * Pipeline the most common cases.
; 170  : 		 */
; 171  : 		if (stride == 3)  {

	cmp	DWORD PTR _stride$[ebp], 3
	jne	$L65910

; 172  : 			u_int cr = cp[0];

	mov	ecx, DWORD PTR _cp$[ebp]
	movsx	edx, BYTE PTR [ecx]
	mov	DWORD PTR _cr$65911[ebp], edx

; 173  : 			u_int cg = cp[1];

	mov	eax, DWORD PTR _cp$[ebp]
	movsx	ecx, BYTE PTR [eax+1]
	mov	DWORD PTR _cg$65912[ebp], ecx

; 174  : 			u_int cb = cp[2];

	mov	edx, DWORD PTR _cp$[ebp]
	movsx	eax, BYTE PTR [edx+2]
	mov	DWORD PTR _cb$65913[ebp], eax
$L65914:

; 176  : 				cc -= 3, cp += 3;

	mov	ecx, DWORD PTR _cc$[ebp]
	sub	ecx, 3
	mov	DWORD PTR _cc$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 3
	mov	DWORD PTR _cp$[ebp], edx

; 177  : 				cp[0] = (cr += cp[0]);

	mov	eax, DWORD PTR _cp$[ebp]
	movsx	ecx, BYTE PTR [eax]
	mov	edx, DWORD PTR _cr$65911[ebp]
	add	edx, ecx
	mov	DWORD PTR _cr$65911[ebp], edx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	cl, BYTE PTR _cr$65911[ebp]
	mov	BYTE PTR [eax], cl

; 178  : 				cp[1] = (cg += cp[1]);

	mov	edx, DWORD PTR _cp$[ebp]
	movsx	eax, BYTE PTR [edx+1]
	mov	ecx, DWORD PTR _cg$65912[ebp]
	add	ecx, eax
	mov	DWORD PTR _cg$65912[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	mov	al, BYTE PTR _cg$65912[ebp]
	mov	BYTE PTR [edx+1], al

; 179  : 				cp[2] = (cb += cp[2]);

	mov	ecx, DWORD PTR _cp$[ebp]
	movsx	edx, BYTE PTR [ecx+2]
	mov	eax, DWORD PTR _cb$65913[ebp]
	add	eax, edx
	mov	DWORD PTR _cb$65913[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	dl, BYTE PTR _cb$65913[ebp]
	mov	BYTE PTR [ecx+2], dl

; 180  : 			} while ((int32) cc > 0);

	cmp	DWORD PTR _cc$[ebp], 0
	jg	SHORT $L65914

; 181  : 		} else if (stride == 4)  {

	jmp	$L65931
$L65910:
	cmp	DWORD PTR _stride$[ebp], 4
	jne	$L65919

; 182  : 			u_int cr = cp[0];

	mov	eax, DWORD PTR _cp$[ebp]
	movsx	ecx, BYTE PTR [eax]
	mov	DWORD PTR _cr$65920[ebp], ecx

; 183  : 			u_int cg = cp[1];

	mov	edx, DWORD PTR _cp$[ebp]
	movsx	eax, BYTE PTR [edx+1]
	mov	DWORD PTR _cg$65921[ebp], eax

; 184  : 			u_int cb = cp[2];

	mov	ecx, DWORD PTR _cp$[ebp]
	movsx	edx, BYTE PTR [ecx+2]
	mov	DWORD PTR _cb$65922[ebp], edx

; 185  : 			u_int ca = cp[3];

	mov	eax, DWORD PTR _cp$[ebp]
	movsx	ecx, BYTE PTR [eax+3]
	mov	DWORD PTR _ca$65923[ebp], ecx
$L65924:

; 187  : 				cc -= 4, cp += 4;

	mov	edx, DWORD PTR _cc$[ebp]
	sub	edx, 4
	mov	DWORD PTR _cc$[ebp], edx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax

; 188  : 				cp[0] = (cr += cp[0]);

	mov	ecx, DWORD PTR _cp$[ebp]
	movsx	edx, BYTE PTR [ecx]
	mov	eax, DWORD PTR _cr$65920[ebp]
	add	eax, edx
	mov	DWORD PTR _cr$65920[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	dl, BYTE PTR _cr$65920[ebp]
	mov	BYTE PTR [ecx], dl

; 189  : 				cp[1] = (cg += cp[1]);

	mov	eax, DWORD PTR _cp$[ebp]
	movsx	ecx, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _cg$65921[ebp]
	add	edx, ecx
	mov	DWORD PTR _cg$65921[ebp], edx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	cl, BYTE PTR _cg$65921[ebp]
	mov	BYTE PTR [eax+1], cl

; 190  : 				cp[2] = (cb += cp[2]);

	mov	edx, DWORD PTR _cp$[ebp]
	movsx	eax, BYTE PTR [edx+2]
	mov	ecx, DWORD PTR _cb$65922[ebp]
	add	ecx, eax
	mov	DWORD PTR _cb$65922[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	mov	al, BYTE PTR _cb$65922[ebp]
	mov	BYTE PTR [edx+2], al

; 191  : 				cp[3] = (ca += cp[3]);

	mov	ecx, DWORD PTR _cp$[ebp]
	movsx	edx, BYTE PTR [ecx+3]
	mov	eax, DWORD PTR _ca$65923[ebp]
	add	eax, edx
	mov	DWORD PTR _ca$65923[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	dl, BYTE PTR _ca$65923[ebp]
	mov	BYTE PTR [ecx+3], dl

; 192  : 			} while ((int32) cc > 0);

	cmp	DWORD PTR _cc$[ebp], 0
	jg	SHORT $L65924

; 193  : 		} else  {

	jmp	$L65931
$L65919:

; 195  : 				REPEAT4(stride, cp[stride] += *cp; cp++)

	mov	eax, DWORD PTR _stride$[ebp]
	mov	DWORD PTR -48+[ebp], eax
	cmp	DWORD PTR -48+[ebp], 4
	ja	SHORT $L65936
	mov	ecx, DWORD PTR -48+[ebp]
	jmp	DWORD PTR $L66306[ecx*4]
$L65936:
	mov	edx, DWORD PTR _stride$[ebp]
	sub	edx, 4
	mov	DWORD PTR _i$65937[ebp], edx
	jmp	SHORT $L65938
$L65939:
	mov	eax, DWORD PTR _i$65937[ebp]
	sub	eax, 1
	mov	DWORD PTR _i$65937[ebp], eax
$L65938:
	cmp	DWORD PTR _i$65937[ebp], 0
	jle	SHORT $L65940
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, DWORD PTR _stride$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	mov	al, BYTE PTR [ecx]
	add	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, DWORD PTR _stride$[ebp]
	mov	BYTE PTR [ecx], al
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	jmp	SHORT $L65939
$L65940:
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, DWORD PTR _stride$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	dl, BYTE PTR [eax]
	add	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, DWORD PTR _stride$[ebp]
	mov	BYTE PTR [eax], dl
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
$L65942:
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, DWORD PTR _stride$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	mov	cl, BYTE PTR [edx]
	add	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, DWORD PTR _stride$[ebp]
	mov	BYTE PTR [edx], cl
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 1
	mov	DWORD PTR _cp$[ebp], eax
$L65943:
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, DWORD PTR _stride$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	mov	al, BYTE PTR [ecx]
	add	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, DWORD PTR _stride$[ebp]
	mov	BYTE PTR [ecx], al
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
$L65944:
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, DWORD PTR _stride$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	dl, BYTE PTR [eax]
	add	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, DWORD PTR _stride$[ebp]
	mov	BYTE PTR [eax], dl
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
$L65945:

; 196  : 				cc -= stride;

	mov	edx, DWORD PTR _cc$[ebp]
	sub	edx, DWORD PTR _stride$[ebp]
	mov	DWORD PTR _cc$[ebp], edx

; 197  : 			} while ((int32) cc > 0);

	cmp	DWORD PTR _cc$[ebp], 0
	jg	$L65919
$L65931:

; 200  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L66306:
	DD	$L65945
	DD	$L65944
	DD	$L65943
	DD	$L65942
	DD	$L65940
_horAcc8 ENDP
_TEXT	ENDS
EXTRN	_TIFFSwabArrayOfShort:NEAR
_TEXT	SEGMENT
_tif$ = 8
_cp0$ = 12
_cc$ = 16
_sp$ = -8
_stride$ = -12
_wp$ = -4
_wc$ = -16
_i$65969 = -20
_swabHorAcc16 PROC NEAR

; 204  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 24					; 00000018H

; 205  : 	TIFFPredictorState* sp = PredictorState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 206  : 	tsize_t stride = sp->stride;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _stride$[ebp], eax

; 207  : 	uint16* wp = (uint16*) cp0;

	mov	ecx, DWORD PTR _cp0$[ebp]
	mov	DWORD PTR _wp$[ebp], ecx

; 208  : 	tsize_t wc = cc / 2;

	mov	eax, DWORD PTR _cc$[ebp]
	cdq
	sub	eax, edx
	sar	eax, 1
	mov	DWORD PTR _wc$[ebp], eax

; 209  : 
; 210  : 	if (wc > stride) {

	mov	edx, DWORD PTR _wc$[ebp]
	cmp	edx, DWORD PTR _stride$[ebp]
	jle	$L65963

; 211  : 		TIFFSwabArrayOfShort(wp, wc);

	mov	eax, DWORD PTR _wc$[ebp]
	push	eax
	mov	ecx, DWORD PTR _wp$[ebp]
	push	ecx
	call	_TIFFSwabArrayOfShort
	add	esp, 8

; 212  : 		wc -= stride;

	mov	edx, DWORD PTR _wc$[ebp]
	sub	edx, DWORD PTR _stride$[ebp]
	mov	DWORD PTR _wc$[ebp], edx
$L65961:

; 214  : 			REPEAT4(stride, wp[stride] += wp[0]; wp++)

	mov	eax, DWORD PTR _stride$[ebp]
	mov	DWORD PTR -24+[ebp], eax
	cmp	DWORD PTR -24+[ebp], 4
	ja	SHORT $L65968
	mov	ecx, DWORD PTR -24+[ebp]
	jmp	DWORD PTR $L66308[ecx*4]
$L65968:
	mov	edx, DWORD PTR _stride$[ebp]
	sub	edx, 4
	mov	DWORD PTR _i$65969[ebp], edx
	jmp	SHORT $L65970
$L65971:
	mov	eax, DWORD PTR _i$65969[ebp]
	sub	eax, 1
	mov	DWORD PTR _i$65969[ebp], eax
$L65970:
	cmp	DWORD PTR _i$65969[ebp], 0
	jle	SHORT $L65972
	mov	ecx, DWORD PTR _stride$[ebp]
	mov	edx, DWORD PTR _wp$[ebp]
	mov	eax, DWORD PTR _wp$[ebp]
	mov	cx, WORD PTR [edx+ecx*2]
	add	cx, WORD PTR [eax]
	mov	edx, DWORD PTR _stride$[ebp]
	mov	eax, DWORD PTR _wp$[ebp]
	mov	WORD PTR [eax+edx*2], cx
	mov	ecx, DWORD PTR _wp$[ebp]
	add	ecx, 2
	mov	DWORD PTR _wp$[ebp], ecx
	jmp	SHORT $L65971
$L65972:
	mov	edx, DWORD PTR _stride$[ebp]
	mov	eax, DWORD PTR _wp$[ebp]
	mov	ecx, DWORD PTR _wp$[ebp]
	mov	dx, WORD PTR [eax+edx*2]
	add	dx, WORD PTR [ecx]
	mov	eax, DWORD PTR _stride$[ebp]
	mov	ecx, DWORD PTR _wp$[ebp]
	mov	WORD PTR [ecx+eax*2], dx
	mov	edx, DWORD PTR _wp$[ebp]
	add	edx, 2
	mov	DWORD PTR _wp$[ebp], edx
$L65974:
	mov	eax, DWORD PTR _stride$[ebp]
	mov	ecx, DWORD PTR _wp$[ebp]
	mov	edx, DWORD PTR _wp$[ebp]
	mov	ax, WORD PTR [ecx+eax*2]
	add	ax, WORD PTR [edx]
	mov	ecx, DWORD PTR _stride$[ebp]
	mov	edx, DWORD PTR _wp$[ebp]
	mov	WORD PTR [edx+ecx*2], ax
	mov	eax, DWORD PTR _wp$[ebp]
	add	eax, 2
	mov	DWORD PTR _wp$[ebp], eax
$L65975:
	mov	ecx, DWORD PTR _stride$[ebp]
	mov	edx, DWORD PTR _wp$[ebp]
	mov	eax, DWORD PTR _wp$[ebp]
	mov	cx, WORD PTR [edx+ecx*2]
	add	cx, WORD PTR [eax]
	mov	edx, DWORD PTR _stride$[ebp]
	mov	eax, DWORD PTR _wp$[ebp]
	mov	WORD PTR [eax+edx*2], cx
	mov	ecx, DWORD PTR _wp$[ebp]
	add	ecx, 2
	mov	DWORD PTR _wp$[ebp], ecx
$L65976:
	mov	edx, DWORD PTR _stride$[ebp]
	mov	eax, DWORD PTR _wp$[ebp]
	mov	ecx, DWORD PTR _wp$[ebp]
	mov	dx, WORD PTR [eax+edx*2]
	add	dx, WORD PTR [ecx]
	mov	eax, DWORD PTR _stride$[ebp]
	mov	ecx, DWORD PTR _wp$[ebp]
	mov	WORD PTR [ecx+eax*2], dx
	mov	edx, DWORD PTR _wp$[ebp]
	add	edx, 2
	mov	DWORD PTR _wp$[ebp], edx
$L65977:

; 215  : 			wc -= stride;

	mov	eax, DWORD PTR _wc$[ebp]
	sub	eax, DWORD PTR _stride$[ebp]
	mov	DWORD PTR _wc$[ebp], eax

; 216  : 		} while ((int32) wc > 0);

	cmp	DWORD PTR _wc$[ebp], 0
	jg	$L65961
$L65963:

; 218  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L66308:
	DD	$L65977
	DD	$L65976
	DD	$L65975
	DD	$L65974
	DD	$L65972
_swabHorAcc16 ENDP
_tif$ = 8
_cp0$ = 12
_cc$ = 16
_stride$ = -8
_wp$ = -4
_wc$ = -12
_i$66000 = -16
_horAcc16 PROC NEAR

; 222  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 20					; 00000014H

; 223  : 	tsize_t stride = PredictorState(tif)->stride;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _stride$[ebp], edx

; 224  : 	uint16* wp = (uint16*) cp0;

	mov	eax, DWORD PTR _cp0$[ebp]
	mov	DWORD PTR _wp$[ebp], eax

; 225  : 	tsize_t wc = cc / 2;

	mov	eax, DWORD PTR _cc$[ebp]
	cdq
	sub	eax, edx
	sar	eax, 1
	mov	DWORD PTR _wc$[ebp], eax

; 226  : 
; 227  : 	if (wc > stride) {

	mov	ecx, DWORD PTR _wc$[ebp]
	cmp	ecx, DWORD PTR _stride$[ebp]
	jle	$L65994

; 228  : 		wc -= stride;

	mov	edx, DWORD PTR _wc$[ebp]
	sub	edx, DWORD PTR _stride$[ebp]
	mov	DWORD PTR _wc$[ebp], edx
$L65992:

; 230  : 			REPEAT4(stride, wp[stride] += wp[0]; wp++)

	mov	eax, DWORD PTR _stride$[ebp]
	mov	DWORD PTR -20+[ebp], eax
	cmp	DWORD PTR -20+[ebp], 4
	ja	SHORT $L65999
	mov	ecx, DWORD PTR -20+[ebp]
	jmp	DWORD PTR $L66310[ecx*4]
$L65999:
	mov	edx, DWORD PTR _stride$[ebp]
	sub	edx, 4
	mov	DWORD PTR _i$66000[ebp], edx
	jmp	SHORT $L66001
$L66002:
	mov	eax, DWORD PTR _i$66000[ebp]
	sub	eax, 1
	mov	DWORD PTR _i$66000[ebp], eax
$L66001:
	cmp	DWORD PTR _i$66000[ebp], 0
	jle	SHORT $L66003
	mov	ecx, DWORD PTR _stride$[ebp]
	mov	edx, DWORD PTR _wp$[ebp]
	mov	eax, DWORD PTR _wp$[ebp]
	mov	cx, WORD PTR [edx+ecx*2]
	add	cx, WORD PTR [eax]
	mov	edx, DWORD PTR _stride$[ebp]
	mov	eax, DWORD PTR _wp$[ebp]
	mov	WORD PTR [eax+edx*2], cx
	mov	ecx, DWORD PTR _wp$[ebp]
	add	ecx, 2
	mov	DWORD PTR _wp$[ebp], ecx
	jmp	SHORT $L66002
$L66003:
	mov	edx, DWORD PTR _stride$[ebp]
	mov	eax, DWORD PTR _wp$[ebp]
	mov	ecx, DWORD PTR _wp$[ebp]
	mov	dx, WORD PTR [eax+edx*2]
	add	dx, WORD PTR [ecx]
	mov	eax, DWORD PTR _stride$[ebp]
	mov	ecx, DWORD PTR _wp$[ebp]
	mov	WORD PTR [ecx+eax*2], dx
	mov	edx, DWORD PTR _wp$[ebp]
	add	edx, 2
	mov	DWORD PTR _wp$[ebp], edx
$L66005:
	mov	eax, DWORD PTR _stride$[ebp]
	mov	ecx, DWORD PTR _wp$[ebp]
	mov	edx, DWORD PTR _wp$[ebp]
	mov	ax, WORD PTR [ecx+eax*2]
	add	ax, WORD PTR [edx]
	mov	ecx, DWORD PTR _stride$[ebp]
	mov	edx, DWORD PTR _wp$[ebp]
	mov	WORD PTR [edx+ecx*2], ax
	mov	eax, DWORD PTR _wp$[ebp]
	add	eax, 2
	mov	DWORD PTR _wp$[ebp], eax
$L66006:
	mov	ecx, DWORD PTR _stride$[ebp]
	mov	edx, DWORD PTR _wp$[ebp]
	mov	eax, DWORD PTR _wp$[ebp]
	mov	cx, WORD PTR [edx+ecx*2]
	add	cx, WORD PTR [eax]
	mov	edx, DWORD PTR _stride$[ebp]
	mov	eax, DWORD PTR _wp$[ebp]
	mov	WORD PTR [eax+edx*2], cx
	mov	ecx, DWORD PTR _wp$[ebp]
	add	ecx, 2
	mov	DWORD PTR _wp$[ebp], ecx
$L66007:
	mov	edx, DWORD PTR _stride$[ebp]
	mov	eax, DWORD PTR _wp$[ebp]
	mov	ecx, DWORD PTR _wp$[ebp]
	mov	dx, WORD PTR [eax+edx*2]
	add	dx, WORD PTR [ecx]
	mov	eax, DWORD PTR _stride$[ebp]
	mov	ecx, DWORD PTR _wp$[ebp]
	mov	WORD PTR [ecx+eax*2], dx
	mov	edx, DWORD PTR _wp$[ebp]
	add	edx, 2
	mov	DWORD PTR _wp$[ebp], edx
$L66008:

; 231  : 			wc -= stride;

	mov	eax, DWORD PTR _wc$[ebp]
	sub	eax, DWORD PTR _stride$[ebp]
	mov	DWORD PTR _wc$[ebp], eax

; 232  : 		} while ((int32) wc > 0);

	cmp	DWORD PTR _wc$[ebp], 0
	jg	$L65992
$L65994:

; 234  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L66310:
	DD	$L66008
	DD	$L66007
	DD	$L66006
	DD	$L66005
	DD	$L66003
_horAcc16 ENDP
_TEXT	ENDS
EXTRN	__assert:NEAR
_DATA	SEGMENT
	ORG $+2
$SG66023 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_predict.c', 00H
$SG66024 DB	'sp != NULL', 00H
	ORG $+1
$SG66027 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_predict.c', 00H
$SG66028 DB	'sp->coderow != NULL', 00H
$SG66031 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_predict.c', 00H
$SG66032 DB	'sp->pfunc != NULL', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_op0$ = 12
_occ0$ = 16
_s$ = 20
_sp$ = -4
_PredictorDecodeRow PROC NEAR

; 241  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 242  : 	TIFFPredictorState *sp = PredictorState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 243  : 
; 244  : 	assert(sp != NULL);

	cmp	DWORD PTR _sp$[ebp], 0
	jne	SHORT $L66312
	push	244					; 000000f4H
	push	OFFSET FLAT:$SG66023
	push	OFFSET FLAT:$SG66024
	call	__assert
	add	esp, 12					; 0000000cH
$L66312:

; 245  : 	assert(sp->coderow != NULL);

	mov	eax, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [eax+16], 0
	jne	SHORT $L66313
	push	245					; 000000f5H
	push	OFFSET FLAT:$SG66027
	push	OFFSET FLAT:$SG66028
	call	__assert
	add	esp, 12					; 0000000cH
$L66313:

; 246  : 	assert(sp->pfunc != NULL);

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx+12], 0
	jne	SHORT $L66314
	push	246					; 000000f6H
	push	OFFSET FLAT:$SG66031
	push	OFFSET FLAT:$SG66032
	call	__assert
	add	esp, 12					; 0000000cH
$L66314:

; 247  : 	if ((*sp->coderow)(tif, op0, occ0, s)) {

	mov	cx, WORD PTR _s$[ebp]
	push	ecx
	mov	edx, DWORD PTR _occ0$[ebp]
	push	edx
	mov	eax, DWORD PTR _op0$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _sp$[ebp]
	call	DWORD PTR [edx+16]
	add	esp, 16					; 00000010H
	test	eax, eax
	je	SHORT $L66033

; 248  : 		(*sp->pfunc)(tif, op0, occ0);

	mov	eax, DWORD PTR _occ0$[ebp]
	push	eax
	mov	ecx, DWORD PTR _op0$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	call	DWORD PTR [eax+12]
	add	esp, 12					; 0000000cH

; 249  : 		return (1);

	mov	eax, 1
	jmp	SHORT $L66034
$L66033:

; 251  : 		return (0);

	xor	eax, eax
$L66034:

; 252  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_PredictorDecodeRow ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+2
$SG66048 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_predict.c', 00H
$SG66049 DB	'sp != NULL', 00H
	ORG $+1
$SG66052 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_predict.c', 00H
$SG66053 DB	'sp->codetile != NULL', 00H
	ORG $+3
$SG66057 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_predict.c', 00H
$SG66058 DB	'rowsize > 0', 00H
$SG66061 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_predict.c', 00H
$SG66062 DB	'sp->pfunc != NULL', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_op0$ = 12
_occ0$ = 16
_s$ = 20
_sp$ = -4
_rowsize$66055 = -8
_PredictorDecodeTile PROC NEAR

; 263  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 264  : 	TIFFPredictorState *sp = PredictorState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 265  : 
; 266  : 	assert(sp != NULL);

	cmp	DWORD PTR _sp$[ebp], 0
	jne	SHORT $L66316
	push	266					; 0000010aH
	push	OFFSET FLAT:$SG66048
	push	OFFSET FLAT:$SG66049
	call	__assert
	add	esp, 12					; 0000000cH
$L66316:

; 267  : 	assert(sp->codetile != NULL);

	mov	eax, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [eax+24], 0
	jne	SHORT $L66317
	push	267					; 0000010bH
	push	OFFSET FLAT:$SG66052
	push	OFFSET FLAT:$SG66053
	call	__assert
	add	esp, 12					; 0000000cH
$L66317:

; 268  : 	if ((*sp->codetile)(tif, op0, occ0, s)) {

	mov	dx, WORD PTR _s$[ebp]
	push	edx
	mov	eax, DWORD PTR _occ0$[ebp]
	push	eax
	mov	ecx, DWORD PTR _op0$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	call	DWORD PTR [eax+24]
	add	esp, 16					; 00000010H
	test	eax, eax
	je	SHORT $L66054

; 269  : 		tsize_t rowsize = sp->rowsize;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR _rowsize$66055[ebp], edx

; 270  : 		assert(rowsize > 0);

	cmp	DWORD PTR _rowsize$66055[ebp], 0
	jg	SHORT $L66318
	push	270					; 0000010eH
	push	OFFSET FLAT:$SG66057
	push	OFFSET FLAT:$SG66058
	call	__assert
	add	esp, 12					; 0000000cH
$L66318:

; 271  : 		assert(sp->pfunc != NULL);

	mov	ecx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [ecx+12], 0
	jne	SHORT $L66319
	push	271					; 0000010fH
	push	OFFSET FLAT:$SG66061
	push	OFFSET FLAT:$SG66062
	call	__assert
	add	esp, 12					; 0000000cH
$L66319:

; 272  : 		while ((long)occ0 > 0) {

	cmp	DWORD PTR _occ0$[ebp], 0
	jle	SHORT $L66066

; 273  : 			(*sp->pfunc)(tif, op0, (tsize_t) rowsize);

	mov	eax, DWORD PTR _rowsize$66055[ebp]
	push	eax
	mov	ecx, DWORD PTR _op0$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	call	DWORD PTR [eax+12]
	add	esp, 12					; 0000000cH

; 274  : 			occ0 -= rowsize;

	mov	ecx, DWORD PTR _occ0$[ebp]
	sub	ecx, DWORD PTR _rowsize$66055[ebp]
	mov	DWORD PTR _occ0$[ebp], ecx

; 275  : 			op0 += rowsize;

	mov	edx, DWORD PTR _op0$[ebp]
	add	edx, DWORD PTR _rowsize$66055[ebp]
	mov	DWORD PTR _op0$[ebp], edx

; 276  : 		}

	jmp	SHORT $L66319
$L66066:

; 277  : 		return (1);

	mov	eax, 1
	jmp	SHORT $L66068
$L66054:

; 279  : 		return (0);

	xor	eax, eax
$L66068:

; 280  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_PredictorDecodeTile ENDP
_tif$ = 8
_cp0$ = 12
_cc$ = 16
_sp$ = -8
_stride$ = -12
_cp$ = -4
_r1$66083 = -20
_g1$66084 = -28
_b1$66085 = -36
_r2$66086 = -24
_g2$66087 = -32
_b2$66088 = -16
_r1$66095 = -44
_g1$66096 = -52
_b1$66097 = -68
_a1$66098 = -60
_r2$66099 = -48
_g2$66100 = -56
_b2$66101 = -40
_a2$66102 = -64
_i$66116 = -72
_horDiff8 PROC NEAR

; 284  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 76					; 0000004cH

; 285  : 	TIFFPredictorState* sp = PredictorState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 286  : 	tsize_t stride = sp->stride;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _stride$[ebp], eax

; 287  : 	char* cp = (char*) cp0;

	mov	ecx, DWORD PTR _cp0$[ebp]
	mov	DWORD PTR _cp$[ebp], ecx

; 288  : 
; 289  : 	if (cc > stride) {

	mov	edx, DWORD PTR _cc$[ebp]
	cmp	edx, DWORD PTR _stride$[ebp]
	jle	$L66110

; 290  : 		cc -= stride;

	mov	eax, DWORD PTR _cc$[ebp]
	sub	eax, DWORD PTR _stride$[ebp]
	mov	DWORD PTR _cc$[ebp], eax

; 291  : 		/*
; 292  : 		 * Pipeline the most common cases.
; 293  : 		 */
; 294  : 		if (stride == 3) {

	cmp	DWORD PTR _stride$[ebp], 3
	jne	$L66082

; 295  : 			int r1, g1, b1;
; 296  : 			int r2 = cp[0];

	mov	ecx, DWORD PTR _cp$[ebp]
	movsx	edx, BYTE PTR [ecx]
	mov	DWORD PTR _r2$66086[ebp], edx

; 297  : 			int g2 = cp[1];

	mov	eax, DWORD PTR _cp$[ebp]
	movsx	ecx, BYTE PTR [eax+1]
	mov	DWORD PTR _g2$66087[ebp], ecx

; 298  : 			int b2 = cp[2];

	mov	edx, DWORD PTR _cp$[ebp]
	movsx	eax, BYTE PTR [edx+2]
	mov	DWORD PTR _b2$66088[ebp], eax
$L66089:

; 300  : 				r1 = cp[3]; cp[3] = r1-r2; r2 = r1;

	mov	ecx, DWORD PTR _cp$[ebp]
	movsx	edx, BYTE PTR [ecx+3]
	mov	DWORD PTR _r1$66083[ebp], edx
	mov	eax, DWORD PTR _r1$66083[ebp]
	sub	eax, DWORD PTR _r2$66086[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [ecx+3], al
	mov	edx, DWORD PTR _r1$66083[ebp]
	mov	DWORD PTR _r2$66086[ebp], edx

; 301  : 				g1 = cp[4]; cp[4] = g1-g2; g2 = g1;

	mov	eax, DWORD PTR _cp$[ebp]
	movsx	ecx, BYTE PTR [eax+4]
	mov	DWORD PTR _g1$66084[ebp], ecx
	mov	edx, DWORD PTR _g1$66084[ebp]
	sub	edx, DWORD PTR _g2$66087[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [eax+4], dl
	mov	ecx, DWORD PTR _g1$66084[ebp]
	mov	DWORD PTR _g2$66087[ebp], ecx

; 302  : 				b1 = cp[5]; cp[5] = b1-b2; b2 = b1;

	mov	edx, DWORD PTR _cp$[ebp]
	movsx	eax, BYTE PTR [edx+5]
	mov	DWORD PTR _b1$66085[ebp], eax
	mov	ecx, DWORD PTR _b1$66085[ebp]
	sub	ecx, DWORD PTR _b2$66088[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [edx+5], cl
	mov	eax, DWORD PTR _b1$66085[ebp]
	mov	DWORD PTR _b2$66088[ebp], eax

; 303  : 				cp += 3;

	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 3
	mov	DWORD PTR _cp$[ebp], ecx

; 304  : 			} while ((int32)(cc -= 3) > 0);

	mov	edx, DWORD PTR _cc$[ebp]
	sub	edx, 3
	mov	DWORD PTR _cc$[ebp], edx
	cmp	DWORD PTR _cc$[ebp], 0
	jg	SHORT $L66089

; 305  : 		} else if (stride == 4) {

	jmp	$L66110
$L66082:
	cmp	DWORD PTR _stride$[ebp], 4
	jne	$L66094

; 306  : 			int r1, g1, b1, a1;
; 307  : 			int r2 = cp[0];

	mov	eax, DWORD PTR _cp$[ebp]
	movsx	ecx, BYTE PTR [eax]
	mov	DWORD PTR _r2$66099[ebp], ecx

; 308  : 			int g2 = cp[1];

	mov	edx, DWORD PTR _cp$[ebp]
	movsx	eax, BYTE PTR [edx+1]
	mov	DWORD PTR _g2$66100[ebp], eax

; 309  : 			int b2 = cp[2];

	mov	ecx, DWORD PTR _cp$[ebp]
	movsx	edx, BYTE PTR [ecx+2]
	mov	DWORD PTR _b2$66101[ebp], edx

; 310  : 			int a2 = cp[3];

	mov	eax, DWORD PTR _cp$[ebp]
	movsx	ecx, BYTE PTR [eax+3]
	mov	DWORD PTR _a2$66102[ebp], ecx
$L66103:

; 312  : 				r1 = cp[4]; cp[4] = r1-r2; r2 = r1;

	mov	edx, DWORD PTR _cp$[ebp]
	movsx	eax, BYTE PTR [edx+4]
	mov	DWORD PTR _r1$66095[ebp], eax
	mov	ecx, DWORD PTR _r1$66095[ebp]
	sub	ecx, DWORD PTR _r2$66099[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [edx+4], cl
	mov	eax, DWORD PTR _r1$66095[ebp]
	mov	DWORD PTR _r2$66099[ebp], eax

; 313  : 				g1 = cp[5]; cp[5] = g1-g2; g2 = g1;

	mov	ecx, DWORD PTR _cp$[ebp]
	movsx	edx, BYTE PTR [ecx+5]
	mov	DWORD PTR _g1$66096[ebp], edx
	mov	eax, DWORD PTR _g1$66096[ebp]
	sub	eax, DWORD PTR _g2$66100[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [ecx+5], al
	mov	edx, DWORD PTR _g1$66096[ebp]
	mov	DWORD PTR _g2$66100[ebp], edx

; 314  : 				b1 = cp[6]; cp[6] = b1-b2; b2 = b1;

	mov	eax, DWORD PTR _cp$[ebp]
	movsx	ecx, BYTE PTR [eax+6]
	mov	DWORD PTR _b1$66097[ebp], ecx
	mov	edx, DWORD PTR _b1$66097[ebp]
	sub	edx, DWORD PTR _b2$66101[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [eax+6], dl
	mov	ecx, DWORD PTR _b1$66097[ebp]
	mov	DWORD PTR _b2$66101[ebp], ecx

; 315  : 				a1 = cp[7]; cp[7] = a1-a2; a2 = a1;

	mov	edx, DWORD PTR _cp$[ebp]
	movsx	eax, BYTE PTR [edx+7]
	mov	DWORD PTR _a1$66098[ebp], eax
	mov	ecx, DWORD PTR _a1$66098[ebp]
	sub	ecx, DWORD PTR _a2$66102[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [edx+7], cl
	mov	eax, DWORD PTR _a1$66098[ebp]
	mov	DWORD PTR _a2$66102[ebp], eax

; 316  : 				cp += 4;

	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx

; 317  : 			} while ((int32)(cc -= 4) > 0);

	mov	edx, DWORD PTR _cc$[ebp]
	sub	edx, 4
	mov	DWORD PTR _cc$[ebp], edx
	cmp	DWORD PTR _cc$[ebp], 0
	jg	$L66103

; 318  : 		} else {

	jmp	$L66110
$L66094:

; 319  : 			cp += cc - 1;

	mov	eax, DWORD PTR _cc$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	lea	edx, DWORD PTR [ecx+eax-1]
	mov	DWORD PTR _cp$[ebp], edx
$L66108:

; 321  : 				REPEAT4(stride, cp[stride] -= cp[0]; cp--)

	mov	eax, DWORD PTR _stride$[ebp]
	mov	DWORD PTR -76+[ebp], eax
	cmp	DWORD PTR -76+[ebp], 4
	ja	SHORT $L66115
	mov	ecx, DWORD PTR -76+[ebp]
	jmp	DWORD PTR $L66321[ecx*4]
$L66115:
	mov	edx, DWORD PTR _stride$[ebp]
	sub	edx, 4
	mov	DWORD PTR _i$66116[ebp], edx
	jmp	SHORT $L66117
$L66118:
	mov	eax, DWORD PTR _i$66116[ebp]
	sub	eax, 1
	mov	DWORD PTR _i$66116[ebp], eax
$L66117:
	cmp	DWORD PTR _i$66116[ebp], 0
	jle	SHORT $L66119
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, DWORD PTR _stride$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	mov	al, BYTE PTR [ecx]
	sub	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, DWORD PTR _stride$[ebp]
	mov	BYTE PTR [ecx], al
	mov	edx, DWORD PTR _cp$[ebp]
	sub	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	jmp	SHORT $L66118
$L66119:
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, DWORD PTR _stride$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	dl, BYTE PTR [eax]
	sub	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, DWORD PTR _stride$[ebp]
	mov	BYTE PTR [eax], dl
	mov	ecx, DWORD PTR _cp$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
$L66121:
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, DWORD PTR _stride$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	mov	cl, BYTE PTR [edx]
	sub	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, DWORD PTR _stride$[ebp]
	mov	BYTE PTR [edx], cl
	mov	eax, DWORD PTR _cp$[ebp]
	sub	eax, 1
	mov	DWORD PTR _cp$[ebp], eax
$L66122:
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, DWORD PTR _stride$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	mov	al, BYTE PTR [ecx]
	sub	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, DWORD PTR _stride$[ebp]
	mov	BYTE PTR [ecx], al
	mov	edx, DWORD PTR _cp$[ebp]
	sub	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
$L66123:
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, DWORD PTR _stride$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	dl, BYTE PTR [eax]
	sub	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, DWORD PTR _stride$[ebp]
	mov	BYTE PTR [eax], dl
	mov	ecx, DWORD PTR _cp$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
$L66124:

; 322  : 			} while ((int32)(cc -= stride) > 0);

	mov	edx, DWORD PTR _cc$[ebp]
	sub	edx, DWORD PTR _stride$[ebp]
	mov	DWORD PTR _cc$[ebp], edx
	cmp	DWORD PTR _cc$[ebp], 0
	jg	$L66108
$L66110:

; 325  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L66321:
	DD	$L66124
	DD	$L66123
	DD	$L66122
	DD	$L66121
	DD	$L66119
_horDiff8 ENDP
_tif$ = 8
_cp0$ = 12
_cc$ = 16
_sp$ = -8
_stride$ = -12
_wp$ = -4
_wc$ = -16
_i$66148 = -20
_horDiff16 PROC NEAR

; 329  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 24					; 00000018H

; 330  : 	TIFFPredictorState* sp = PredictorState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 331  : 	tsize_t stride = sp->stride;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _stride$[ebp], eax

; 332  : 	int16 *wp = (int16*) cp0;

	mov	ecx, DWORD PTR _cp0$[ebp]
	mov	DWORD PTR _wp$[ebp], ecx

; 333  : 	tsize_t wc = cc/2;

	mov	eax, DWORD PTR _cc$[ebp]
	cdq
	sub	eax, edx
	sar	eax, 1
	mov	DWORD PTR _wc$[ebp], eax

; 334  : 
; 335  : 	if (wc > stride) {

	mov	edx, DWORD PTR _wc$[ebp]
	cmp	edx, DWORD PTR _stride$[ebp]
	jle	$L66142

; 336  : 		wc -= stride;

	mov	eax, DWORD PTR _wc$[ebp]
	sub	eax, DWORD PTR _stride$[ebp]
	mov	DWORD PTR _wc$[ebp], eax

; 337  : 		wp += wc - 1;

	mov	ecx, DWORD PTR _wc$[ebp]
	mov	edx, DWORD PTR _wp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*2-2]
	mov	DWORD PTR _wp$[ebp], eax
$L66140:

; 339  : 			REPEAT4(stride, wp[stride] -= wp[0]; wp--)

	mov	ecx, DWORD PTR _stride$[ebp]
	mov	DWORD PTR -24+[ebp], ecx
	cmp	DWORD PTR -24+[ebp], 4
	ja	SHORT $L66147
	mov	edx, DWORD PTR -24+[ebp]
	jmp	DWORD PTR $L66323[edx*4]
$L66147:
	mov	eax, DWORD PTR _stride$[ebp]
	sub	eax, 4
	mov	DWORD PTR _i$66148[ebp], eax
	jmp	SHORT $L66149
$L66150:
	mov	ecx, DWORD PTR _i$66148[ebp]
	sub	ecx, 1
	mov	DWORD PTR _i$66148[ebp], ecx
$L66149:
	cmp	DWORD PTR _i$66148[ebp], 0
	jle	SHORT $L66151
	mov	edx, DWORD PTR _stride$[ebp]
	mov	eax, DWORD PTR _wp$[ebp]
	mov	ecx, DWORD PTR _wp$[ebp]
	mov	dx, WORD PTR [eax+edx*2]
	sub	dx, WORD PTR [ecx]
	mov	eax, DWORD PTR _stride$[ebp]
	mov	ecx, DWORD PTR _wp$[ebp]
	mov	WORD PTR [ecx+eax*2], dx
	mov	edx, DWORD PTR _wp$[ebp]
	sub	edx, 2
	mov	DWORD PTR _wp$[ebp], edx
	jmp	SHORT $L66150
$L66151:
	mov	eax, DWORD PTR _stride$[ebp]
	mov	ecx, DWORD PTR _wp$[ebp]
	mov	edx, DWORD PTR _wp$[ebp]
	mov	ax, WORD PTR [ecx+eax*2]
	sub	ax, WORD PTR [edx]
	mov	ecx, DWORD PTR _stride$[ebp]
	mov	edx, DWORD PTR _wp$[ebp]
	mov	WORD PTR [edx+ecx*2], ax
	mov	eax, DWORD PTR _wp$[ebp]
	sub	eax, 2
	mov	DWORD PTR _wp$[ebp], eax
$L66153:
	mov	ecx, DWORD PTR _stride$[ebp]
	mov	edx, DWORD PTR _wp$[ebp]
	mov	eax, DWORD PTR _wp$[ebp]
	mov	cx, WORD PTR [edx+ecx*2]
	sub	cx, WORD PTR [eax]
	mov	edx, DWORD PTR _stride$[ebp]
	mov	eax, DWORD PTR _wp$[ebp]
	mov	WORD PTR [eax+edx*2], cx
	mov	ecx, DWORD PTR _wp$[ebp]
	sub	ecx, 2
	mov	DWORD PTR _wp$[ebp], ecx
$L66154:
	mov	edx, DWORD PTR _stride$[ebp]
	mov	eax, DWORD PTR _wp$[ebp]
	mov	ecx, DWORD PTR _wp$[ebp]
	mov	dx, WORD PTR [eax+edx*2]
	sub	dx, WORD PTR [ecx]
	mov	eax, DWORD PTR _stride$[ebp]
	mov	ecx, DWORD PTR _wp$[ebp]
	mov	WORD PTR [ecx+eax*2], dx
	mov	edx, DWORD PTR _wp$[ebp]
	sub	edx, 2
	mov	DWORD PTR _wp$[ebp], edx
$L66155:
	mov	eax, DWORD PTR _stride$[ebp]
	mov	ecx, DWORD PTR _wp$[ebp]
	mov	edx, DWORD PTR _wp$[ebp]
	mov	ax, WORD PTR [ecx+eax*2]
	sub	ax, WORD PTR [edx]
	mov	ecx, DWORD PTR _stride$[ebp]
	mov	edx, DWORD PTR _wp$[ebp]
	mov	WORD PTR [edx+ecx*2], ax
	mov	eax, DWORD PTR _wp$[ebp]
	sub	eax, 2
	mov	DWORD PTR _wp$[ebp], eax
$L66156:

; 340  : 			wc -= stride;

	mov	ecx, DWORD PTR _wc$[ebp]
	sub	ecx, DWORD PTR _stride$[ebp]
	mov	DWORD PTR _wc$[ebp], ecx

; 341  : 		} while ((int32) wc > 0);

	cmp	DWORD PTR _wc$[ebp], 0
	jg	$L66140
$L66142:

; 343  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L66323:
	DD	$L66156
	DD	$L66155
	DD	$L66154
	DD	$L66153
	DD	$L66151
_horDiff16 ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+2
$SG66171 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_predict.c', 00H
$SG66172 DB	'sp != NULL', 00H
	ORG $+1
$SG66175 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_predict.c', 00H
$SG66176 DB	'sp->pfunc != NULL', 00H
	ORG $+2
$SG66179 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_predict.c', 00H
$SG66180 DB	'sp->coderow != NULL', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_bp$ = 12
_cc$ = 16
_s$ = 20
_sp$ = -4
_PredictorEncodeRow PROC NEAR

; 347  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 348  : 	TIFFPredictorState *sp = PredictorState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 349  : 
; 350  : 	assert(sp != NULL);

	cmp	DWORD PTR _sp$[ebp], 0
	jne	SHORT $L66325
	push	350					; 0000015eH
	push	OFFSET FLAT:$SG66171
	push	OFFSET FLAT:$SG66172
	call	__assert
	add	esp, 12					; 0000000cH
$L66325:

; 351  : 	assert(sp->pfunc != NULL);

	mov	eax, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [eax+12], 0
	jne	SHORT $L66326
	push	351					; 0000015fH
	push	OFFSET FLAT:$SG66175
	push	OFFSET FLAT:$SG66176
	call	__assert
	add	esp, 12					; 0000000cH
$L66326:

; 352  : 	assert(sp->coderow != NULL);

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx+16], 0
	jne	SHORT $L66327
	push	352					; 00000160H
	push	OFFSET FLAT:$SG66179
	push	OFFSET FLAT:$SG66180
	call	__assert
	add	esp, 12					; 0000000cH
$L66327:

; 353  : /* XXX horizontal differencing alters user's data XXX */
; 354  : 	(*sp->pfunc)(tif, bp, cc);

	mov	ecx, DWORD PTR _cc$[ebp]
	push	ecx
	mov	edx, DWORD PTR _bp$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	mov	ecx, DWORD PTR _sp$[ebp]
	call	DWORD PTR [ecx+12]
	add	esp, 12					; 0000000cH

; 355  : 	return ((*sp->coderow)(tif, bp, cc, s));

	mov	dx, WORD PTR _s$[ebp]
	push	edx
	mov	eax, DWORD PTR _cc$[ebp]
	push	eax
	mov	ecx, DWORD PTR _bp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	call	DWORD PTR [eax+16]
	add	esp, 16					; 00000010H

; 356  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_PredictorEncodeRow ENDP
_TEXT	ENDS
_DATA	SEGMENT
$SG66197 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_predict.c', 00H
$SG66198 DB	'sp != NULL', 00H
	ORG $+1
$SG66201 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_predict.c', 00H
$SG66202 DB	'sp->pfunc != NULL', 00H
	ORG $+2
$SG66205 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_predict.c', 00H
$SG66206 DB	'sp->codetile != NULL', 00H
	ORG $+3
$SG66208 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_predict.c', 00H
$SG66209 DB	'rowsize > 0', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_bp0$ = 12
_cc0$ = 16
_s$ = 20
_sp$ = -8
_cc$ = -12
_rowsize$ = -4
_bp$ = -16
_PredictorEncodeTile PROC NEAR

; 360  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 361  : 	TIFFPredictorState *sp = PredictorState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 362  : 	tsize_t cc = cc0, rowsize;

	mov	edx, DWORD PTR _cc0$[ebp]
	mov	DWORD PTR _cc$[ebp], edx

; 363  : 	u_char* bp = bp0;

	mov	eax, DWORD PTR _bp0$[ebp]
	mov	DWORD PTR _bp$[ebp], eax

; 364  : 
; 365  : 	assert(sp != NULL);

	cmp	DWORD PTR _sp$[ebp], 0
	jne	SHORT $L66329
	push	365					; 0000016dH
	push	OFFSET FLAT:$SG66197
	push	OFFSET FLAT:$SG66198
	call	__assert
	add	esp, 12					; 0000000cH
$L66329:

; 366  : 	assert(sp->pfunc != NULL);

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx+12], 0
	jne	SHORT $L66330
	push	366					; 0000016eH
	push	OFFSET FLAT:$SG66201
	push	OFFSET FLAT:$SG66202
	call	__assert
	add	esp, 12					; 0000000cH
$L66330:

; 367  : 	assert(sp->codetile != NULL);

	mov	ecx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [ecx+24], 0
	jne	SHORT $L66331
	push	367					; 0000016fH
	push	OFFSET FLAT:$SG66205
	push	OFFSET FLAT:$SG66206
	call	__assert
	add	esp, 12					; 0000000cH
$L66331:

; 368  : 	rowsize = sp->rowsize;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR _rowsize$[ebp], ecx

; 369  : 	assert(rowsize > 0);

	cmp	DWORD PTR _rowsize$[ebp], 0
	jg	SHORT $L66332
	push	369					; 00000171H
	push	OFFSET FLAT:$SG66208
	push	OFFSET FLAT:$SG66209
	call	__assert
	add	esp, 12					; 0000000cH
$L66332:

; 370  : 	while ((long)cc > 0) {

	cmp	DWORD PTR _cc$[ebp], 0
	jle	SHORT $L66213

; 371  : 		(*sp->pfunc)(tif, bp, (tsize_t) rowsize);

	mov	eax, DWORD PTR _rowsize$[ebp]
	push	eax
	mov	ecx, DWORD PTR _bp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	call	DWORD PTR [eax+12]
	add	esp, 12					; 0000000cH

; 372  : 		cc -= rowsize;

	mov	ecx, DWORD PTR _cc$[ebp]
	sub	ecx, DWORD PTR _rowsize$[ebp]
	mov	DWORD PTR _cc$[ebp], ecx

; 373  : 		bp += rowsize;

	mov	edx, DWORD PTR _bp$[ebp]
	add	edx, DWORD PTR _rowsize$[ebp]
	mov	DWORD PTR _bp$[ebp], edx

; 374  : 	}

	jmp	SHORT $L66332
$L66213:

; 375  : 	return ((*sp->codetile)(tif, bp0, cc0, s));

	mov	ax, WORD PTR _s$[ebp]
	push	eax
	mov	ecx, DWORD PTR _cc0$[ebp]
	push	ecx
	mov	edx, DWORD PTR _bp0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	mov	ecx, DWORD PTR _sp$[ebp]
	call	DWORD PTR [ecx+24]
	add	esp, 16					; 00000010H

; 376  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_PredictorEncodeTile ENDP
_tif$ = 8
_tag$ = 12
_ap$ = 16
_sp$ = -4
_PredictorVSetField PROC NEAR

; 388  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 389  : 	TIFFPredictorState *sp = PredictorState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 390  : 
; 391  : 	switch (tag) {

	mov	edx, DWORD PTR _tag$[ebp]
	mov	DWORD PTR -8+[ebp], edx
	cmp	DWORD PTR -8+[ebp], 317			; 0000013dH
	je	SHORT $L66233
	jmp	SHORT $L66243
$L66233:

; 392  : 	case TIFFTAG_PREDICTOR:
; 393  : 		sp->predictor = (uint16) va_arg(ap, int);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx-4]
	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax], edx

; 394  : 		TIFFSetFieldBit(tif, FIELD_PREDICTOR);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	or	edx, -2147483648			; 80000000H
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+28], edx

; 395  : 		break;

	jmp	SHORT $L66230
$L66243:

; 396  : 	default:
; 397  : 		return (*sp->vsetparent)(tif, tag, ap);

	mov	ecx, DWORD PTR _ap$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tag$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	mov	ecx, DWORD PTR _sp$[ebp]
	call	DWORD PTR [ecx+32]
	add	esp, 12					; 0000000cH
	jmp	SHORT $L66226
$L66230:

; 399  : 	tif->tif_flags |= TIFF_DIRTYDIRECT;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	or	al, 8
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+12], eax

; 400  : 	return (1);

	mov	eax, 1
$L66226:

; 401  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_PredictorVSetField ENDP
_tif$ = 8
_tag$ = 12
_ap$ = 16
_sp$ = -4
_PredictorVGetField PROC NEAR

; 405  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 406  : 	TIFFPredictorState *sp = PredictorState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 407  : 
; 408  : 	switch (tag) {

	mov	edx, DWORD PTR _tag$[ebp]
	mov	DWORD PTR -8+[ebp], edx
	cmp	DWORD PTR -8+[ebp], 317			; 0000013dH
	je	SHORT $L66258
	jmp	SHORT $L66266
$L66258:

; 409  : 	case TIFFTAG_PREDICTOR:
; 410  : 		*va_arg(ap, uint16*) = sp->predictor;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _sp$[ebp]
	mov	cx, WORD PTR [eax]
	mov	WORD PTR [edx], cx

; 411  : 		break;

	jmp	SHORT $L66255
$L66266:

; 412  : 	default:
; 413  : 		return (*sp->vgetparent)(tif, tag, ap);

	mov	edx, DWORD PTR _ap$[ebp]
	push	edx
	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _sp$[ebp]
	call	DWORD PTR [edx+28]
	add	esp, 12					; 0000000cH
	jmp	SHORT $L66251
$L66255:

; 415  : 	return (1);

	mov	eax, 1
$L66251:

; 416  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_PredictorVGetField ENDP
_TEXT	ENDS
EXTRN	_fprintf:NEAR
_DATA	SEGMENT
$SG66280 DB	'  Predictor: ', 00H
	ORG $+2
$SG66286 DB	'none ', 00H
	ORG $+2
$SG66288 DB	'horizontal differencing ', 00H
	ORG $+3
$SG66289 DB	'%u (0x%x)', 0aH, 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_fd$ = 12
_flags$ = 16
_sp$ = -4
_PredictorPrintDir PROC NEAR

; 420  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 421  : 	TIFFPredictorState* sp = PredictorState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 422  : 
; 423  : 	(void) flags;
; 424  : 	if (TIFFFieldSet(tif,FIELD_PREDICTOR)) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+28]
	and	eax, -2147483648			; 80000000H
	test	eax, eax
	je	SHORT $L66279

; 425  : 		fprintf(fd, "  Predictor: ");

	push	OFFSET FLAT:$SG66280
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 426  : 		switch (sp->predictor) {

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR -8+[ebp], eax
	cmp	DWORD PTR -8+[ebp], 1
	je	SHORT $L66285
	cmp	DWORD PTR -8+[ebp], 2
	je	SHORT $L66287
	jmp	SHORT $L66282
$L66285:

; 427  : 		case 1: fprintf(fd, "none "); break;

	push	OFFSET FLAT:$SG66286
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8
	jmp	SHORT $L66282
$L66287:

; 428  : 		case 2: fprintf(fd, "horizontal differencing "); break;

	push	OFFSET FLAT:$SG66288
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8
$L66282:

; 430  : 		fprintf(fd, "%u (0x%x)\n", sp->predictor, sp->predictor);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	push	OFFSET FLAT:$SG66289
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 16					; 00000010H
$L66279:

; 432  : 	if (sp->printdir)

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx+36], 0
	je	SHORT $L66290

; 433  : 		(*sp->printdir)(tif, fd, flags);

	mov	eax, DWORD PTR _flags$[ebp]
	push	eax
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	call	DWORD PTR [eax+36]
	add	esp, 12					; 0000000cH
$L66290:

; 434  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_PredictorPrintDir ENDP
_TEXT	ENDS
END
