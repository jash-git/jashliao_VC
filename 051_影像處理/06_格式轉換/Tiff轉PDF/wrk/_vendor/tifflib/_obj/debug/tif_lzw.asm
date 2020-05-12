	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_lzw.c
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
_?module@?1??LZWSetupDecode@@9@9 DB ' LZWSetupDecode', 00H
CONST	ENDS
PUBLIC	_TIFFInitLZW
EXTRN	_TIFFPredictorInit:NEAR
EXTRN	__assert:NEAR
EXTRN	__TIFFmalloc:NEAR
EXTRN	_TIFFError:NEAR
_DATA	SEGMENT
$SG66144 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_lzw.c', 00H
$SG66145 DB	'scheme == COMPRESSION_LZW', 00H
	ORG $+2
$SG66160 DB	'No space for LZW state block', 00H
	ORG $+3
$SG66161 DB	'TIFFInitLZW', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_scheme$ = 12
_TIFFInitLZW PROC NEAR

; 665  : {

	push	ebp
	mov	ebp, esp

; 666  : 	assert(scheme == COMPRESSION_LZW);

	cmp	DWORD PTR _scheme$[ebp], 5
	je	SHORT $L66165
	push	666					; 0000029aH
	push	OFFSET FLAT:$SG66144
	push	OFFSET FLAT:$SG66145
	call	__assert
	add	esp, 12					; 0000000cH
$L66165:

; 667  : 	/*
; 668  : 	 * Allocate state block so tag methods have storage to record values.
; 669  : 	 */
; 670  : 	if (tif->tif_mode == O_RDONLY) 

	mov	ecx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [ecx+8], 0
	jne	SHORT $L66146

; 672  :             tif->tif_data = (tidata_t) _TIFFmalloc(sizeof (LZWDecodeState));

	push	100					; 00000064H
	call	__TIFFmalloc
	add	esp, 4
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+460], eax

; 673  :             if (tif->tif_data == NULL)

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+460], 0
	jne	SHORT $L66150

; 674  :                 goto bad;

	jmp	$bad$66151
$L66150:

; 675  :             DecoderState(tif)->dec_codetab = NULL;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+460]
	mov	DWORD PTR [edx+96], 0

; 676  :             DecoderState(tif)->dec_decode = NULL;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR [ecx+76], 0
$L66146:

; 678  : 
; 679  : 	/*
; 680  : 	 * Install codec methods.
; 681  : 	 */
; 682  : 	tif->tif_setupencode = LZWSetupEncode;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+404], OFFSET FLAT:_LZWSetupEncode

; 683  : 	tif->tif_setupdecode = LZWSetupDecode;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+396], OFFSET FLAT:_LZWSetupDecode

; 684  : 	tif->tif_predecode = LZWPreDecode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+400], OFFSET FLAT:_LZWPreDecode

; 685  : 	tif->tif_decoderow = LZWDecode;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+416], OFFSET FLAT:_LZWDecode

; 686  : 	tif->tif_decodestrip = LZWDecode;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+424], OFFSET FLAT:_LZWDecode

; 687  : 	tif->tif_decodetile = LZWDecode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+432], OFFSET FLAT:_LZWDecode

; 688  : 	tif->tif_cleanup = LZWCleanup;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+448], OFFSET FLAT:_LZWCleanup

; 689  : 
; 690  : 	/*
; 691  : 	 * Setup predictor setup.
; 692  : 	 */
; 693  :         if( tif->tif_mode == O_RDONLY )

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+8], 0
	jne	SHORT $L66158

; 694  :             (void) TIFFPredictorInit(tif);

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFPredictorInit
	add	esp, 4
$L66158:

; 695  : 
; 696  :         return (1);

	mov	eax, 1
	jmp	SHORT $L66142
$bad$66151:

; 697  : 
; 698  : bad:
; 699  : 	TIFFError("TIFFInitLZW", "No space for LZW state block");

	push	OFFSET FLAT:$SG66160
	push	OFFSET FLAT:$SG66161
	call	_TIFFError
	add	esp, 8

; 700  : 	return (0);

	xor	eax, eax
$L66142:

; 701  : }

	pop	ebp
	ret	0
_TIFFInitLZW ENDP
_TEXT	ENDS
_DATA	SEGMENT
$SG65899 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_lzw.c', 00H
$SG65900 DB	'sp != NULL', 00H
	ORG $+1
$SG65907 DB	'No space for LZW code table', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_sp$ = -4
_code$ = -8
_LZWSetupDecode PROC NEAR

; 192  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 193  : 	LZWDecodeState* sp = DecoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 194  : 	static const char module[] = " LZWSetupDecode";
; 195  : 	int code;
; 196  : 
; 197  : 	assert(sp != NULL);

	cmp	DWORD PTR _sp$[ebp], 0
	jne	SHORT $L66167
	push	197					; 000000c5H
	push	OFFSET FLAT:$SG65899
	push	OFFSET FLAT:$SG65900
	call	__assert
	add	esp, 12					; 0000000cH
$L66167:

; 198  : 	if (sp->dec_codetab == NULL) {

	mov	eax, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [eax+96], 0
	jne	$L65910

; 199  : 		sp->dec_codetab = (code_t*)_TIFFmalloc(CSIZE*sizeof (code_t));

	push	40952					; 00009ff8H
	call	__TIFFmalloc
	add	esp, 4
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+96], eax

; 200  : 		if (sp->dec_codetab == NULL) {

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx+96], 0
	jne	SHORT $L65906

; 201  : 			TIFFError(module, "No space for LZW code table");

	push	OFFSET FLAT:$SG65907
	push	OFFSET FLAT:_?module@?1??LZWSetupDecode@@9@9
	call	_TIFFError
	add	esp, 8

; 202  : 			return (0);

	xor	eax, eax
	jmp	SHORT $L65890
$L65906:

; 204  : 		/*
; 205  : 		 * Pre-load the table.
; 206  : 		 */
; 207  :                 code = 255;

	mov	DWORD PTR _code$[ebp], 255		; 000000ffH
$L65908:

; 209  :                     sp->dec_codetab[code].value = code;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+96]
	mov	edx, DWORD PTR _code$[ebp]
	mov	al, BYTE PTR _code$[ebp]
	mov	BYTE PTR [ecx+edx*8+6], al

; 210  :                     sp->dec_codetab[code].firstchar = code;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+96]
	mov	eax, DWORD PTR _code$[ebp]
	mov	cl, BYTE PTR _code$[ebp]
	mov	BYTE PTR [edx+eax*8+7], cl

; 211  :                     sp->dec_codetab[code].length = 1;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+96]
	mov	ecx, DWORD PTR _code$[ebp]
	mov	WORD PTR [eax+ecx*8+4], 1

; 212  :                     sp->dec_codetab[code].next = NULL;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+96]
	mov	ecx, DWORD PTR _code$[ebp]
	mov	DWORD PTR [eax+ecx*8], 0

; 213  :                 } while (code--);

	mov	edx, DWORD PTR _code$[ebp]
	mov	eax, DWORD PTR _code$[ebp]
	sub	eax, 1
	mov	DWORD PTR _code$[ebp], eax
	test	edx, edx
	jne	SHORT $L65908
$L65910:

; 215  : 	return (1);

	mov	eax, 1
$L65890:

; 216  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LZWSetupDecode ENDP
_TEXT	ENDS
EXTRN	__TIFFmemset:NEAR
EXTRN	_TIFFWarning:NEAR
_DATA	SEGMENT
$SG65924 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_lzw.c', 00H
$SG65925 DB	'sp != NULL', 00H
	ORG $+1
$SG65928 DB	'Old-style LZW codes, convert file', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_sp$ = -4
_LZWPreDecode PROC NEAR

; 223  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 224  : 	LZWDecodeState *sp = DecoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 225  : 
; 226  : 	(void) s;
; 227  : 	assert(sp != NULL);

	cmp	DWORD PTR _sp$[ebp], 0
	jne	SHORT $L66169
	push	227					; 000000e3H
	push	OFFSET FLAT:$SG65924
	push	OFFSET FLAT:$SG65925
	call	__assert
	add	esp, 12					; 0000000cH
$L66169:

; 228  : 	/*
; 229  : 	 * Check for old bit-reversed codes.
; 230  : 	 */
; 231  : 	if (tif->tif_rawdata[0] == 0 && (tif->tif_rawdata[1] & 0x1)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+472]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	test	edx, edx
	jne	SHORT $L65926
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+472]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	and	edx, 1
	test	edx, edx
	je	SHORT $L65926

; 232  : #ifdef LZW_COMPAT
; 233  : 		if (!sp->dec_decode) {

	mov	eax, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [eax+76], 0
	jne	SHORT $L65927

; 234  : 			TIFFWarning(tif->tif_name,
; 235  : 			    "Old-style LZW codes, convert file");

	push	OFFSET FLAT:$SG65928
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFWarning
	add	esp, 8

; 236  : 			/*
; 237  : 			 * Override default decoding methods with
; 238  : 			 * ones that deal with the old coding.
; 239  : 			 * Otherwise the predictor versions set
; 240  : 			 * above will call the compatibility routines
; 241  : 			 * through the dec_decode method.
; 242  : 			 */
; 243  : 			tif->tif_decoderow = LZWDecodeCompat;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+416], OFFSET FLAT:_LZWDecodeCompat

; 244  : 			tif->tif_decodestrip = LZWDecodeCompat;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+424], OFFSET FLAT:_LZWDecodeCompat

; 245  : 			tif->tif_decodetile = LZWDecodeCompat;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+432], OFFSET FLAT:_LZWDecodeCompat

; 246  : 			/*
; 247  : 			 * If doing horizontal differencing, must
; 248  : 			 * re-setup the predictor logic since we
; 249  : 			 * switched the basic decoder methods...
; 250  : 			 */
; 251  : 			(*tif->tif_setupdecode)(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+396]
	add	esp, 4

; 252  : 			sp->dec_decode = LZWDecodeCompat;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+76], OFFSET FLAT:_LZWDecodeCompat
$L65927:

; 254  : 		sp->lzw_maxcode = MAXCODE(BITS_MIN);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	WORD PTR [eax+50], 511			; 000001ffH

; 255  : #else /* !LZW_COMPAT */
; 256  : 		if (!sp->dec_decode) {
; 257  : 			TIFFError(tif->tif_name,
; 258  : 			    "Old-style LZW codes not supported");
; 259  : 			sp->dec_decode = LZWDecode;
; 260  : 		}
; 261  : 		return (0);
; 262  : #endif/* !LZW_COMPAT */
; 263  : 	} else {

	jmp	SHORT $L65929
$L65926:

; 264  : 		sp->lzw_maxcode = MAXCODE(BITS_MIN)-1;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	WORD PTR [ecx+50], 510			; 000001feH

; 265  : 		sp->dec_decode = LZWDecode;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+76], OFFSET FLAT:_LZWDecode
$L65929:

; 267  : 	sp->lzw_nbits = BITS_MIN;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	WORD PTR [eax+48], 9

; 268  : 	sp->lzw_nextbits = 0;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+60], 0

; 269  : 	sp->lzw_nextdata = 0;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+56], 0

; 270  : 
; 271  : 	sp->dec_restart = 0;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+68], 0

; 272  : 	sp->dec_nbitsmask = MAXCODE(BITS_MIN);

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+64], 511			; 000001ffH

; 273  : #ifdef LZW_CHECKEOS
; 274  : 	sp->dec_bitsleft = tif->tif_rawcc << 3;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+484]
	shl	eax, 3
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+72], eax

; 275  : #endif
; 276  : 	sp->dec_free_entp = sp->dec_codetab + CODE_FIRST;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+96]
	add	eax, 2064				; 00000810H
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+88], eax

; 277  : 	/*
; 278  : 	 * Zero entries that are not yet filled in.  We do
; 279  : 	 * this to guard against bogus input data that causes
; 280  : 	 * us to index into undefined entries.  If you can
; 281  : 	 * come up with a way to safely bounds-check input codes
; 282  : 	 * while decoding then you can remove this operation.
; 283  : 	 */
; 284  : 	_TIFFmemset(sp->dec_free_entp, 0, (CSIZE-CODE_FIRST)*sizeof (code_t));

	push	38888					; 000097e8H
	push	0
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+88]
	push	eax
	call	__TIFFmemset
	add	esp, 12					; 0000000cH

; 285  : 	sp->dec_oldcodep = &sp->dec_codetab[-1];

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+96]
	sub	edx, 8
	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+84], edx

; 286  : 	sp->dec_maxcodep = &sp->dec_codetab[sp->dec_nbitsmask-1];

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+64]
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+96]
	lea	edx, DWORD PTR [ecx+edx*8-8]
	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+92], edx

; 287  : 	return (1);

	mov	eax, 1

; 288  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LZWPreDecode ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+2
$SG65968 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_lzw.c', 00H
$SG65969 DB	'sp != NULL', 00H
	ORG $+1
$SG65992 DB	'LZWDecode: Strip %d not terminated with EOI code', 00H
	ORG $+3
$SG65999 DB	'LZWDecode: Strip %d not terminated with EOI code', 00H
	ORG $+3
$SG66006 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_lzw.c', 00H
$SG66007 DB	'&sp->dec_codetab[0] <= free_entp && free_entp < &sp->dec'
	DB	'_codetab[CSIZE]', 00H
$SG66033 DB	'LZWDecode: Not enough data at scanline %d (short %d byte'
	DB	's)', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_op0$ = 12
_occ0$ = 16
_sp$ = -16
_op$ = -8
_occ$ = -36
_tp$ = -32
_bp$ = -56
_code$ = -48
_len$ = -40
_nbits$ = -28
_nextbits$ = -12
_nextdata$ = -4
_nbitsmask$ = -60
_codep$ = -20
_free_entp$ = -52
_maxcodep$ = -44
_oldcodep$ = -24
_residue$65971 = -64
_t$65985 = -68
_t$66025 = -72
_LZWDecode PROC NEAR

; 314  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 76					; 0000004cH

; 315  : 	LZWDecodeState *sp = DecoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 316  : 	char *op = (char*) op0;

	mov	edx, DWORD PTR _op0$[ebp]
	mov	DWORD PTR _op$[ebp], edx

; 317  : 	long occ = (long) occ0;

	mov	eax, DWORD PTR _occ0$[ebp]
	mov	DWORD PTR _occ$[ebp], eax

; 318  : 	char *tp;
; 319  : 	u_char *bp;
; 320  : 	hcode_t code;
; 321  : 	int len;
; 322  : 	long nbits, nextbits, nextdata, nbitsmask;
; 323  : 	code_t *codep, *free_entp, *maxcodep, *oldcodep;
; 324  : 
; 325  : 	(void) s;
; 326  : 	assert(sp != NULL);

	cmp	DWORD PTR _sp$[ebp], 0
	jne	SHORT $L66171
	push	326					; 00000146H
	push	OFFSET FLAT:$SG65968
	push	OFFSET FLAT:$SG65969
	call	__assert
	add	esp, 12					; 0000000cH
$L66171:

; 327  : 	/*
; 328  : 	 * Restart interrupted output operation.
; 329  : 	 */
; 330  : 	if (sp->dec_restart) {

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx+68], 0
	je	$L65970

; 331  : 		long residue;
; 332  : 
; 333  : 		codep = sp->dec_codep;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+80]
	mov	DWORD PTR _codep$[ebp], ecx

; 334  : 		residue = codep->length - sp->dec_restart;

	mov	edx, DWORD PTR _codep$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+4]
	mov	ecx, DWORD PTR _sp$[ebp]
	sub	eax, DWORD PTR [ecx+68]
	mov	DWORD PTR _residue$65971[ebp], eax

; 335  : 		if (residue > occ) {

	mov	edx, DWORD PTR _residue$65971[ebp]
	cmp	edx, DWORD PTR _occ$[ebp]
	jle	SHORT $L65972

; 336  : 			/*
; 337  : 			 * Residue from previous decode is sufficient
; 338  : 			 * to satisfy decode request.  Skip to the
; 339  : 			 * start of the decoded string, place decoded
; 340  : 			 * values in the output buffer, and return.
; 341  : 			 */
; 342  : 			sp->dec_restart += occ;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+68]
	add	ecx, DWORD PTR _occ$[ebp]
	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+68], ecx
$L65973:

; 344  : 				codep = codep->next;

	mov	eax, DWORD PTR _codep$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _codep$[ebp], ecx

; 345  : 			} while (--residue > occ && codep);

	mov	edx, DWORD PTR _residue$65971[ebp]
	sub	edx, 1
	mov	DWORD PTR _residue$65971[ebp], edx
	mov	eax, DWORD PTR _residue$65971[ebp]
	cmp	eax, DWORD PTR _occ$[ebp]
	jle	SHORT $L65976
	cmp	DWORD PTR _codep$[ebp], 0
	jne	SHORT $L65973
$L65976:

; 346  : 			if (codep) {

	cmp	DWORD PTR _codep$[ebp], 0
	je	SHORT $L65981

; 347  : 				tp = op + occ;

	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, DWORD PTR _occ$[ebp]
	mov	DWORD PTR _tp$[ebp], ecx
$L65978:

; 349  : 					*--tp = codep->value;

	mov	edx, DWORD PTR _tp$[ebp]
	sub	edx, 1
	mov	DWORD PTR _tp$[ebp], edx
	mov	eax, DWORD PTR _tp$[ebp]
	mov	ecx, DWORD PTR _codep$[ebp]
	mov	dl, BYTE PTR [ecx+6]
	mov	BYTE PTR [eax], dl

; 350  : 					codep = codep->next;

	mov	eax, DWORD PTR _codep$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _codep$[ebp], ecx

; 351  : 				} while (--occ && codep);

	mov	edx, DWORD PTR _occ$[ebp]
	sub	edx, 1
	mov	DWORD PTR _occ$[ebp], edx
	cmp	DWORD PTR _occ$[ebp], 0
	je	SHORT $L65981
	cmp	DWORD PTR _codep$[ebp], 0
	jne	SHORT $L65978
$L65981:

; 353  : 			return (1);

	mov	eax, 1
	jmp	$L65945
$L65972:

; 355  : 		/*
; 356  : 		 * Residue satisfies only part of the decode request.
; 357  : 		 */
; 358  : 		op += residue, occ -= residue;

	mov	eax, DWORD PTR _op$[ebp]
	add	eax, DWORD PTR _residue$65971[ebp]
	mov	DWORD PTR _op$[ebp], eax
	mov	ecx, DWORD PTR _occ$[ebp]
	sub	ecx, DWORD PTR _residue$65971[ebp]
	mov	DWORD PTR _occ$[ebp], ecx

; 359  : 		tp = op;

	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR _tp$[ebp], edx
$L65982:

; 361  : 			int t;
; 362  : 			--tp;

	mov	eax, DWORD PTR _tp$[ebp]
	sub	eax, 1
	mov	DWORD PTR _tp$[ebp], eax

; 363  : 			t = codep->value;

	mov	ecx, DWORD PTR _codep$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+6]
	mov	DWORD PTR _t$65985[ebp], edx

; 364  : 			codep = codep->next;

	mov	eax, DWORD PTR _codep$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _codep$[ebp], ecx

; 365  : 			*tp = t;

	mov	edx, DWORD PTR _tp$[ebp]
	mov	al, BYTE PTR _t$65985[ebp]
	mov	BYTE PTR [edx], al

; 366  : 		} while (--residue && codep);

	mov	ecx, DWORD PTR _residue$65971[ebp]
	sub	ecx, 1
	mov	DWORD PTR _residue$65971[ebp], ecx
	cmp	DWORD PTR _residue$65971[ebp], 0
	je	SHORT $L65986
	cmp	DWORD PTR _codep$[ebp], 0
	jne	SHORT $L65982
$L65986:

; 367  : 		sp->dec_restart = 0;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+68], 0
$L65970:

; 369  : 
; 370  : 	bp = (u_char *)tif->tif_rawcp;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	DWORD PTR _bp$[ebp], ecx

; 371  : 	nbits = sp->lzw_nbits;

	mov	edx, DWORD PTR _sp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+48]
	mov	DWORD PTR _nbits$[ebp], eax

; 372  : 	nextdata = sp->lzw_nextdata;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	mov	DWORD PTR _nextdata$[ebp], edx

; 373  : 	nextbits = sp->lzw_nextbits;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	mov	DWORD PTR _nextbits$[ebp], ecx

; 374  : 	nbitsmask = sp->dec_nbitsmask;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+64]
	mov	DWORD PTR _nbitsmask$[ebp], eax

; 375  : 	oldcodep = sp->dec_oldcodep;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+84]
	mov	DWORD PTR _oldcodep$[ebp], edx

; 376  : 	free_entp = sp->dec_free_entp;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+88]
	mov	DWORD PTR _free_entp$[ebp], ecx

; 377  : 	maxcodep = sp->dec_maxcodep;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+92]
	mov	DWORD PTR _maxcodep$[ebp], eax
$L65989:

; 378  : 
; 379  : 	while (occ > 0) {

	cmp	DWORD PTR _occ$[ebp], 0
	jle	$L65990

; 380  : 		NextCode(tif, sp, bp, code, GetNextCode);

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+72]
	cmp	edx, DWORD PTR _nbits$[ebp]
	jge	SHORT $L65991
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	push	ecx
	push	OFFSET FLAT:$SG65992
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFWarning
	add	esp, 12					; 0000000cH
	mov	WORD PTR _code$[ebp], 257		; 00000101H
	jmp	SHORT $L65993
$L65991:
	mov	ecx, DWORD PTR _nextdata$[ebp]
	shl	ecx, 8
	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	or	ecx, eax
	mov	DWORD PTR _nextdata$[ebp], ecx
	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _bp$[ebp], ecx
	mov	edx, DWORD PTR _nextbits$[ebp]
	add	edx, 8
	mov	DWORD PTR _nextbits$[ebp], edx
	mov	eax, DWORD PTR _nextbits$[ebp]
	cmp	eax, DWORD PTR _nbits$[ebp]
	jge	SHORT $L65994
	mov	ecx, DWORD PTR _nextdata$[ebp]
	shl	ecx, 8
	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	or	ecx, eax
	mov	DWORD PTR _nextdata$[ebp], ecx
	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _bp$[ebp], ecx
	mov	edx, DWORD PTR _nextbits$[ebp]
	add	edx, 8
	mov	DWORD PTR _nextbits$[ebp], edx
$L65994:
	mov	ecx, DWORD PTR _nextbits$[ebp]
	sub	ecx, DWORD PTR _nbits$[ebp]
	mov	eax, DWORD PTR _nextdata$[ebp]
	sar	eax, cl
	and	eax, DWORD PTR _nbitsmask$[ebp]
	mov	WORD PTR _code$[ebp], ax
	mov	ecx, DWORD PTR _nextbits$[ebp]
	sub	ecx, DWORD PTR _nbits$[ebp]
	mov	DWORD PTR _nextbits$[ebp], ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+72]
	sub	eax, DWORD PTR _nbits$[ebp]
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+72], eax
$L65993:

; 381  : 		if (code == CODE_EOI)

	mov	edx, DWORD PTR _code$[ebp]
	and	edx, 65535				; 0000ffffH
	cmp	edx, 257				; 00000101H
	jne	SHORT $L65996

; 382  : 			break;

	jmp	$L65990
$L65996:

; 383  : 		if (code == CODE_CLEAR) {

	mov	eax, DWORD PTR _code$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 256				; 00000100H
	jne	$L65997

; 384  : 			free_entp = sp->dec_codetab + CODE_FIRST;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+96]
	add	edx, 2064				; 00000810H
	mov	DWORD PTR _free_entp$[ebp], edx

; 385  : 			nbits = BITS_MIN;

	mov	DWORD PTR _nbits$[ebp], 9

; 386  : 			nbitsmask = MAXCODE(BITS_MIN);

	mov	DWORD PTR _nbitsmask$[ebp], 511		; 000001ffH

; 387  : 			maxcodep = sp->dec_codetab + nbitsmask-1;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+96]
	mov	edx, DWORD PTR _nbitsmask$[ebp]
	lea	eax, DWORD PTR [ecx+edx*8-8]
	mov	DWORD PTR _maxcodep$[ebp], eax

; 388  : 			NextCode(tif, sp, bp, code, GetNextCode);

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+72]
	cmp	edx, DWORD PTR _nbits$[ebp]
	jge	SHORT $L65998
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	push	ecx
	push	OFFSET FLAT:$SG65999
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFWarning
	add	esp, 12					; 0000000cH
	mov	WORD PTR _code$[ebp], 257		; 00000101H
	jmp	SHORT $L66000
$L65998:
	mov	ecx, DWORD PTR _nextdata$[ebp]
	shl	ecx, 8
	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	or	ecx, eax
	mov	DWORD PTR _nextdata$[ebp], ecx
	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _bp$[ebp], ecx
	mov	edx, DWORD PTR _nextbits$[ebp]
	add	edx, 8
	mov	DWORD PTR _nextbits$[ebp], edx
	mov	eax, DWORD PTR _nextbits$[ebp]
	cmp	eax, DWORD PTR _nbits$[ebp]
	jge	SHORT $L66001
	mov	ecx, DWORD PTR _nextdata$[ebp]
	shl	ecx, 8
	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	or	ecx, eax
	mov	DWORD PTR _nextdata$[ebp], ecx
	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _bp$[ebp], ecx
	mov	edx, DWORD PTR _nextbits$[ebp]
	add	edx, 8
	mov	DWORD PTR _nextbits$[ebp], edx
$L66001:
	mov	ecx, DWORD PTR _nextbits$[ebp]
	sub	ecx, DWORD PTR _nbits$[ebp]
	mov	eax, DWORD PTR _nextdata$[ebp]
	sar	eax, cl
	and	eax, DWORD PTR _nbitsmask$[ebp]
	mov	WORD PTR _code$[ebp], ax
	mov	ecx, DWORD PTR _nextbits$[ebp]
	sub	ecx, DWORD PTR _nbits$[ebp]
	mov	DWORD PTR _nextbits$[ebp], ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+72]
	sub	eax, DWORD PTR _nbits$[ebp]
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+72], eax
$L66000:

; 389  : 			if (code == CODE_EOI)

	mov	edx, DWORD PTR _code$[ebp]
	and	edx, 65535				; 0000ffffH
	cmp	edx, 257				; 00000101H
	jne	SHORT $L66003

; 390  : 				break;

	jmp	$L65990
$L66003:

; 391  : 			*op++ = (char)code, occ--;

	mov	eax, DWORD PTR _op$[ebp]
	mov	cl, BYTE PTR _code$[ebp]
	mov	BYTE PTR [eax], cl
	mov	edx, DWORD PTR _op$[ebp]
	add	edx, 1
	mov	DWORD PTR _op$[ebp], edx
	mov	eax, DWORD PTR _occ$[ebp]
	sub	eax, 1
	mov	DWORD PTR _occ$[ebp], eax

; 392  : 			oldcodep = sp->dec_codetab + code;

	mov	ecx, DWORD PTR _code$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+96]
	lea	ecx, DWORD PTR [eax+ecx*8]
	mov	DWORD PTR _oldcodep$[ebp], ecx

; 393  : 			continue;

	jmp	$L65989
$L65997:

; 395  : 		codep = sp->dec_codetab + code;

	mov	edx, DWORD PTR _code$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+96]
	lea	edx, DWORD PTR [ecx+edx*8]
	mov	DWORD PTR _codep$[ebp], edx

; 396  : 
; 397  : 		/*
; 398  : 	 	 * Add the new entry to the code table.
; 399  : 	 	 */
; 400  : 		assert(&sp->dec_codetab[0] <= free_entp && free_entp < &sp->dec_codetab[CSIZE]);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+96]
	cmp	ecx, DWORD PTR _free_entp$[ebp]
	ja	SHORT $L66172
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+96]
	add	eax, 40952				; 00009ff8H
	cmp	DWORD PTR _free_entp$[ebp], eax
	jb	SHORT $L66173
$L66172:
	push	400					; 00000190H
	push	OFFSET FLAT:$SG66006
	push	OFFSET FLAT:$SG66007
	call	__assert
	add	esp, 12					; 0000000cH
$L66173:

; 401  : 		free_entp->next = oldcodep;

	mov	edx, DWORD PTR _free_entp$[ebp]
	mov	eax, DWORD PTR _oldcodep$[ebp]
	mov	DWORD PTR [edx], eax

; 402  : 		free_entp->firstchar = free_entp->next->firstchar;

	mov	ecx, DWORD PTR _free_entp$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	eax, DWORD PTR _free_entp$[ebp]
	mov	cl, BYTE PTR [edx+7]
	mov	BYTE PTR [eax+7], cl

; 403  : 		free_entp->length = free_entp->next->length+1;

	mov	edx, DWORD PTR _free_entp$[ebp]
	mov	eax, DWORD PTR [edx]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+4]
	add	ecx, 1
	mov	edx, DWORD PTR _free_entp$[ebp]
	mov	WORD PTR [edx+4], cx

; 404  : 		free_entp->value = (codep < free_entp) ?
; 405  : 		    codep->firstchar : free_entp->firstchar;

	mov	eax, DWORD PTR _codep$[ebp]
	cmp	eax, DWORD PTR _free_entp$[ebp]
	jae	SHORT $L66174
	mov	ecx, DWORD PTR _codep$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+7]
	mov	DWORD PTR -76+[ebp], edx
	jmp	SHORT $L66175
$L66174:
	mov	eax, DWORD PTR _free_entp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+7]
	mov	DWORD PTR -76+[ebp], ecx
$L66175:
	mov	edx, DWORD PTR _free_entp$[ebp]
	mov	al, BYTE PTR -76+[ebp]
	mov	BYTE PTR [edx+6], al

; 406  : 		if (++free_entp > maxcodep) {

	mov	ecx, DWORD PTR _free_entp$[ebp]
	add	ecx, 8
	mov	DWORD PTR _free_entp$[ebp], ecx
	mov	edx, DWORD PTR _free_entp$[ebp]
	cmp	edx, DWORD PTR _maxcodep$[ebp]
	jbe	SHORT $L66008

; 407  : 			if (++nbits > BITS_MAX)		/* should not happen */

	mov	eax, DWORD PTR _nbits$[ebp]
	add	eax, 1
	mov	DWORD PTR _nbits$[ebp], eax
	cmp	DWORD PTR _nbits$[ebp], 12		; 0000000cH
	jle	SHORT $L66009

; 408  : 				nbits = BITS_MAX;

	mov	DWORD PTR _nbits$[ebp], 12		; 0000000cH
$L66009:

; 409  : 			nbitsmask = MAXCODE(nbits);

	mov	edx, 1
	mov	ecx, DWORD PTR _nbits$[ebp]
	shl	edx, cl
	sub	edx, 1
	mov	DWORD PTR _nbitsmask$[ebp], edx

; 410  : 			maxcodep = sp->dec_codetab + nbitsmask-1;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+96]
	mov	edx, DWORD PTR _nbitsmask$[ebp]
	lea	eax, DWORD PTR [ecx+edx*8-8]
	mov	DWORD PTR _maxcodep$[ebp], eax
$L66008:

; 412  : 		oldcodep = codep;

	mov	ecx, DWORD PTR _codep$[ebp]
	mov	DWORD PTR _oldcodep$[ebp], ecx

; 413  : 		if (code >= 256) {

	mov	edx, DWORD PTR _code$[ebp]
	and	edx, 65535				; 0000ffffH
	cmp	edx, 256				; 00000100H
	jl	$L66010

; 414  : 			/*
; 415  : 		 	 * Code maps to a string, copy string
; 416  : 			 * value to output (written in reverse).
; 417  : 		 	 */
; 418  : 			if (codep->length > occ) {

	mov	eax, DWORD PTR _codep$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+4]
	cmp	ecx, DWORD PTR _occ$[ebp]
	jle	$L66011

; 419  : 				/*
; 420  : 				 * String is too long for decode buffer,
; 421  : 				 * locate portion that will fit, copy to
; 422  : 				 * the decode buffer, and setup restart
; 423  : 				 * logic for the next decoding call.
; 424  : 				 */
; 425  : 				sp->dec_codep = codep;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _codep$[ebp]
	mov	DWORD PTR [edx+80], eax
$L66012:

; 427  : 					codep = codep->next;

	mov	ecx, DWORD PTR _codep$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR _codep$[ebp], edx

; 428  : 				} while (codep && codep->length > occ);

	cmp	DWORD PTR _codep$[ebp], 0
	je	SHORT $L66015
	mov	eax, DWORD PTR _codep$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+4]
	cmp	ecx, DWORD PTR _occ$[ebp]
	jg	SHORT $L66012
$L66015:

; 429  : 				if (codep) {

	cmp	DWORD PTR _codep$[ebp], 0
	je	SHORT $L66021

; 430  : 					sp->dec_restart = occ;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _occ$[ebp]
	mov	DWORD PTR [edx+68], eax

; 431  : 					tp = op + occ;

	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, DWORD PTR _occ$[ebp]
	mov	DWORD PTR _tp$[ebp], ecx
$L66017:

; 433  : 						*--tp = codep->value;

	mov	edx, DWORD PTR _tp$[ebp]
	sub	edx, 1
	mov	DWORD PTR _tp$[ebp], edx
	mov	eax, DWORD PTR _tp$[ebp]
	mov	ecx, DWORD PTR _codep$[ebp]
	mov	dl, BYTE PTR [ecx+6]
	mov	BYTE PTR [eax], dl

; 434  : 						codep = codep->next;

	mov	eax, DWORD PTR _codep$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _codep$[ebp], ecx

; 435  : 					}  while (--occ && codep);

	mov	edx, DWORD PTR _occ$[ebp]
	sub	edx, 1
	mov	DWORD PTR _occ$[ebp], edx
	cmp	DWORD PTR _occ$[ebp], 0
	je	SHORT $L66020
	cmp	DWORD PTR _codep$[ebp], 0
	jne	SHORT $L66017
$L66020:

; 436  : 					if (codep)

	cmp	DWORD PTR _codep$[ebp], 0
	je	SHORT $L66021

; 437  : 						codeLoop(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_codeLoop
	add	esp, 4
$L66021:

; 439  : 				break;

	jmp	$L65990
$L66011:

; 441  : 			len = codep->length;

	mov	ecx, DWORD PTR _codep$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+4]
	mov	DWORD PTR _len$[ebp], edx

; 442  : 			tp = op + len;

	mov	eax, DWORD PTR _op$[ebp]
	add	eax, DWORD PTR _len$[ebp]
	mov	DWORD PTR _tp$[ebp], eax
$L66022:

; 444  : 				int t;
; 445  : 				--tp;

	mov	ecx, DWORD PTR _tp$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _tp$[ebp], ecx

; 446  : 				t = codep->value;

	mov	edx, DWORD PTR _codep$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+6]
	mov	DWORD PTR _t$66025[ebp], eax

; 447  : 				codep = codep->next;

	mov	ecx, DWORD PTR _codep$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR _codep$[ebp], edx

; 448  : 				*tp = t;

	mov	eax, DWORD PTR _tp$[ebp]
	mov	cl, BYTE PTR _t$66025[ebp]
	mov	BYTE PTR [eax], cl

; 449  : 			} while (codep && tp > op);

	cmp	DWORD PTR _codep$[ebp], 0
	je	SHORT $L66026
	mov	edx, DWORD PTR _tp$[ebp]
	cmp	edx, DWORD PTR _op$[ebp]
	ja	SHORT $L66022
$L66026:

; 450  : 			if (codep) {

	cmp	DWORD PTR _codep$[ebp], 0
	je	SHORT $L66027

; 451  : 			    codeLoop(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_codeLoop
	add	esp, 4

; 452  : 			    break;

	jmp	SHORT $L65990
$L66027:

; 454  : 			op += len, occ -= len;

	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, DWORD PTR _len$[ebp]
	mov	DWORD PTR _op$[ebp], ecx
	mov	edx, DWORD PTR _occ$[ebp]
	sub	edx, DWORD PTR _len$[ebp]
	mov	DWORD PTR _occ$[ebp], edx

; 455  : 		} else

	jmp	SHORT $L66028
$L66010:

; 456  : 			*op++ = (char)code, occ--;

	mov	eax, DWORD PTR _op$[ebp]
	mov	cl, BYTE PTR _code$[ebp]
	mov	BYTE PTR [eax], cl
	mov	edx, DWORD PTR _op$[ebp]
	add	edx, 1
	mov	DWORD PTR _op$[ebp], edx
	mov	eax, DWORD PTR _occ$[ebp]
	sub	eax, 1
	mov	DWORD PTR _occ$[ebp], eax
$L66028:

; 457  : 	}

	jmp	$L65989
$L65990:

; 458  : 
; 459  : 	tif->tif_rawcp = (tidata_t) bp;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _bp$[ebp]
	mov	DWORD PTR [ecx+480], edx

; 460  : 	sp->lzw_nbits = (u_short) nbits;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	cx, WORD PTR _nbits$[ebp]
	mov	WORD PTR [eax+48], cx

; 461  : 	sp->lzw_nextdata = nextdata;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _nextdata$[ebp]
	mov	DWORD PTR [edx+56], eax

; 462  : 	sp->lzw_nextbits = nextbits;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _nextbits$[ebp]
	mov	DWORD PTR [ecx+60], edx

; 463  : 	sp->dec_nbitsmask = nbitsmask;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _nbitsmask$[ebp]
	mov	DWORD PTR [eax+64], ecx

; 464  : 	sp->dec_oldcodep = oldcodep;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _oldcodep$[ebp]
	mov	DWORD PTR [edx+84], eax

; 465  : 	sp->dec_free_entp = free_entp;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _free_entp$[ebp]
	mov	DWORD PTR [ecx+88], edx

; 466  : 	sp->dec_maxcodep = maxcodep;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _maxcodep$[ebp]
	mov	DWORD PTR [eax+92], ecx

; 467  : 
; 468  : 	if (occ > 0) {

	cmp	DWORD PTR _occ$[ebp], 0
	jle	SHORT $L66032

; 469  : 		TIFFError(tif->tif_name,
; 470  : 		"LZWDecode: Not enough data at scanline %d (short %d bytes)",
; 471  : 		    tif->tif_row, occ);

	mov	edx, DWORD PTR _occ$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+356]
	push	ecx
	push	OFFSET FLAT:$SG66033
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 16					; 00000010H

; 472  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L65945
$L66032:

; 474  : 	return (1);

	mov	eax, 1
$L65945:

; 475  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LZWDecode ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+1
$SG65936 DB	'LZWDecode: Bogus encoding, loop in the code table; scanl'
	DB	'ine %d', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_codeLoop PROC NEAR

; 306  : {

	push	ebp
	mov	ebp, esp

; 307  : 	TIFFError(tif->tif_name,
; 308  : 	    "LZWDecode: Bogus encoding, loop in the code table; scanline %d",
; 309  : 	    tif->tif_row);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+356]
	push	ecx
	push	OFFSET FLAT:$SG65936
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 310  : }

	pop	ebp
	ret	0
_codeLoop ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+1
$SG66065 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_lzw.c', 00H
$SG66066 DB	'sp != NULL', 00H
	ORG $+1
$SG66084 DB	'LZWDecode: Strip %d not terminated with EOI code', 00H
	ORG $+3
$SG66093 DB	'LZWDecode: Strip %d not terminated with EOI code', 00H
	ORG $+3
$SG66101 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_lzw.c', 00H
$SG66102 DB	'&sp->dec_codetab[0] <= free_entp && free_entp < &sp->dec'
	DB	'_codetab[CSIZE]', 00H
$SG66120 DB	'LZWDecodeCompat: Not enough data at scanline %d (short %'
	DB	'd bytes)', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_op0$ = 12
_occ0$ = 16
_sp$ = -16
_op$ = -8
_occ$ = -36
_tp$ = -32
_bp$ = -52
_code$ = -44
_nbits$ = -28
_nextbits$ = -12
_nextdata$ = -4
_nbitsmask$ = -56
_codep$ = -20
_free_entp$ = -48
_maxcodep$ = -40
_oldcodep$ = -24
_residue$66068 = -60
_LZWDecodeCompat PROC NEAR

; 495  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H

; 496  : 	LZWDecodeState *sp = DecoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 497  : 	char *op = (char*) op0;

	mov	edx, DWORD PTR _op0$[ebp]
	mov	DWORD PTR _op$[ebp], edx

; 498  : 	long occ = (long) occ0;

	mov	eax, DWORD PTR _occ0$[ebp]
	mov	DWORD PTR _occ$[ebp], eax

; 499  : 	char *tp;
; 500  : 	u_char *bp;
; 501  : 	int code, nbits;
; 502  : 	long nextbits, nextdata, nbitsmask;
; 503  : 	code_t *codep, *free_entp, *maxcodep, *oldcodep;
; 504  : 
; 505  : 	(void) s;
; 506  : 	assert(sp != NULL);

	cmp	DWORD PTR _sp$[ebp], 0
	jne	SHORT $L66178
	push	506					; 000001faH
	push	OFFSET FLAT:$SG66065
	push	OFFSET FLAT:$SG66066
	call	__assert
	add	esp, 12					; 0000000cH
$L66178:

; 507  : 	/*
; 508  : 	 * Restart interrupted output operation.
; 509  : 	 */
; 510  : 	if (sp->dec_restart) {

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx+68], 0
	je	$L66067

; 511  : 		long residue;
; 512  : 
; 513  : 		codep = sp->dec_codep;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+80]
	mov	DWORD PTR _codep$[ebp], ecx

; 514  : 		residue = codep->length - sp->dec_restart;

	mov	edx, DWORD PTR _codep$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+4]
	mov	ecx, DWORD PTR _sp$[ebp]
	sub	eax, DWORD PTR [ecx+68]
	mov	DWORD PTR _residue$66068[ebp], eax

; 515  : 		if (residue > occ) {

	mov	edx, DWORD PTR _residue$66068[ebp]
	cmp	edx, DWORD PTR _occ$[ebp]
	jle	SHORT $L66069

; 516  : 			/*
; 517  : 			 * Residue from previous decode is sufficient
; 518  : 			 * to satisfy decode request.  Skip to the
; 519  : 			 * start of the decoded string, place decoded
; 520  : 			 * values in the output buffer, and return.
; 521  : 			 */
; 522  : 			sp->dec_restart += occ;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+68]
	add	ecx, DWORD PTR _occ$[ebp]
	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+68], ecx
$L66070:

; 524  : 				codep = codep->next;

	mov	eax, DWORD PTR _codep$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _codep$[ebp], ecx

; 525  : 			} while (--residue > occ);

	mov	edx, DWORD PTR _residue$66068[ebp]
	sub	edx, 1
	mov	DWORD PTR _residue$66068[ebp], edx
	mov	eax, DWORD PTR _residue$66068[ebp]
	cmp	eax, DWORD PTR _occ$[ebp]
	jg	SHORT $L66070

; 526  : 			tp = op + occ;

	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, DWORD PTR _occ$[ebp]
	mov	DWORD PTR _tp$[ebp], ecx
$L66073:

; 528  : 				*--tp = codep->value;

	mov	edx, DWORD PTR _tp$[ebp]
	sub	edx, 1
	mov	DWORD PTR _tp$[ebp], edx
	mov	eax, DWORD PTR _tp$[ebp]
	mov	ecx, DWORD PTR _codep$[ebp]
	mov	dl, BYTE PTR [ecx+6]
	mov	BYTE PTR [eax], dl

; 529  : 				codep = codep->next;

	mov	eax, DWORD PTR _codep$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _codep$[ebp], ecx

; 530  : 			} while (--occ);

	mov	edx, DWORD PTR _occ$[ebp]
	sub	edx, 1
	mov	DWORD PTR _occ$[ebp], edx
	cmp	DWORD PTR _occ$[ebp], 0
	jne	SHORT $L66073

; 531  : 			return (1);

	mov	eax, 1
	jmp	$L66043
$L66069:

; 533  : 		/*
; 534  : 		 * Residue satisfies only part of the decode request.
; 535  : 		 */
; 536  : 		op += residue, occ -= residue;

	mov	eax, DWORD PTR _op$[ebp]
	add	eax, DWORD PTR _residue$66068[ebp]
	mov	DWORD PTR _op$[ebp], eax
	mov	ecx, DWORD PTR _occ$[ebp]
	sub	ecx, DWORD PTR _residue$66068[ebp]
	mov	DWORD PTR _occ$[ebp], ecx

; 537  : 		tp = op;

	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR _tp$[ebp], edx
$L66076:

; 539  : 			*--tp = codep->value;

	mov	eax, DWORD PTR _tp$[ebp]
	sub	eax, 1
	mov	DWORD PTR _tp$[ebp], eax
	mov	ecx, DWORD PTR _tp$[ebp]
	mov	edx, DWORD PTR _codep$[ebp]
	mov	al, BYTE PTR [edx+6]
	mov	BYTE PTR [ecx], al

; 540  : 			codep = codep->next;

	mov	ecx, DWORD PTR _codep$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR _codep$[ebp], edx

; 541  : 		} while (--residue);

	mov	eax, DWORD PTR _residue$66068[ebp]
	sub	eax, 1
	mov	DWORD PTR _residue$66068[ebp], eax
	cmp	DWORD PTR _residue$66068[ebp], 0
	jne	SHORT $L66076

; 542  : 		sp->dec_restart = 0;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+68], 0
$L66067:

; 544  : 
; 545  : 	bp = (u_char *)tif->tif_rawcp;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+480]
	mov	DWORD PTR _bp$[ebp], eax

; 546  : 	nbits = sp->lzw_nbits;

	mov	ecx, DWORD PTR _sp$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+48]
	mov	DWORD PTR _nbits$[ebp], edx

; 547  : 	nextdata = sp->lzw_nextdata;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	DWORD PTR _nextdata$[ebp], ecx

; 548  : 	nextbits = sp->lzw_nextbits;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+60]
	mov	DWORD PTR _nextbits$[ebp], eax

; 549  : 	nbitsmask = sp->dec_nbitsmask;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+64]
	mov	DWORD PTR _nbitsmask$[ebp], edx

; 550  : 	oldcodep = sp->dec_oldcodep;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+84]
	mov	DWORD PTR _oldcodep$[ebp], ecx

; 551  : 	free_entp = sp->dec_free_entp;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+88]
	mov	DWORD PTR _free_entp$[ebp], eax

; 552  : 	maxcodep = sp->dec_maxcodep;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+92]
	mov	DWORD PTR _maxcodep$[ebp], edx
$L66081:

; 553  : 
; 554  : 	while (occ > 0) {

	cmp	DWORD PTR _occ$[ebp], 0
	jle	$L66082

; 555  : 		NextCode(tif, sp, bp, code, GetNextCodeCompat);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+72]
	cmp	ecx, DWORD PTR _nbits$[ebp]
	jge	SHORT $L66083
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+364]
	push	eax
	push	OFFSET FLAT:$SG66084
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFWarning
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _code$[ebp], 257		; 00000101H
	jmp	$L66085
$L66083:
	mov	eax, DWORD PTR _bp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, ecx
	mov	ecx, DWORD PTR _nextbits$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _nextdata$[ebp]
	or	eax, edx
	mov	DWORD PTR _nextdata$[ebp], eax
	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _bp$[ebp], ecx
	mov	edx, DWORD PTR _nextbits$[ebp]
	add	edx, 8
	mov	DWORD PTR _nextbits$[ebp], edx
	mov	eax, DWORD PTR _nextbits$[ebp]
	cmp	eax, DWORD PTR _nbits$[ebp]
	jge	SHORT $L66087
	mov	ecx, DWORD PTR _bp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, DWORD PTR _nextbits$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _nextdata$[ebp]
	or	eax, edx
	mov	DWORD PTR _nextdata$[ebp], eax
	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _bp$[ebp], ecx
	mov	edx, DWORD PTR _nextbits$[ebp]
	add	edx, 8
	mov	DWORD PTR _nextbits$[ebp], edx
$L66087:
	mov	eax, DWORD PTR _nextdata$[ebp]
	and	eax, DWORD PTR _nbitsmask$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	DWORD PTR _code$[ebp], eax
	mov	edx, DWORD PTR _nextdata$[ebp]
	mov	ecx, DWORD PTR _nbits$[ebp]
	sar	edx, cl
	mov	DWORD PTR _nextdata$[ebp], edx
	mov	eax, DWORD PTR _nextbits$[ebp]
	sub	eax, DWORD PTR _nbits$[ebp]
	mov	DWORD PTR _nextbits$[ebp], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+72]
	sub	edx, DWORD PTR _nbits$[ebp]
	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+72], edx
$L66085:

; 556  : 		if (code == CODE_EOI)

	cmp	DWORD PTR _code$[ebp], 257		; 00000101H
	jne	SHORT $L66090

; 557  : 			break;

	jmp	$L66082
$L66090:

; 558  : 		if (code == CODE_CLEAR) {

	cmp	DWORD PTR _code$[ebp], 256		; 00000100H
	jne	$L66091

; 559  : 			free_entp = sp->dec_codetab + CODE_FIRST;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+96]
	add	edx, 2064				; 00000810H
	mov	DWORD PTR _free_entp$[ebp], edx

; 560  : 			nbits = BITS_MIN;

	mov	DWORD PTR _nbits$[ebp], 9

; 561  : 			nbitsmask = MAXCODE(BITS_MIN);

	mov	DWORD PTR _nbitsmask$[ebp], 511		; 000001ffH

; 562  : 			maxcodep = sp->dec_codetab + nbitsmask;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+96]
	mov	edx, DWORD PTR _nbitsmask$[ebp]
	lea	eax, DWORD PTR [ecx+edx*8]
	mov	DWORD PTR _maxcodep$[ebp], eax

; 563  : 			NextCode(tif, sp, bp, code, GetNextCodeCompat);

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+72]
	cmp	edx, DWORD PTR _nbits$[ebp]
	jge	SHORT $L66092
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+364]
	push	ecx
	push	OFFSET FLAT:$SG66093
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFWarning
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _code$[ebp], 257		; 00000101H
	jmp	$L66094
$L66092:
	mov	ecx, DWORD PTR _bp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, DWORD PTR _nextbits$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _nextdata$[ebp]
	or	eax, edx
	mov	DWORD PTR _nextdata$[ebp], eax
	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _bp$[ebp], ecx
	mov	edx, DWORD PTR _nextbits$[ebp]
	add	edx, 8
	mov	DWORD PTR _nextbits$[ebp], edx
	mov	eax, DWORD PTR _nextbits$[ebp]
	cmp	eax, DWORD PTR _nbits$[ebp]
	jge	SHORT $L66096
	mov	ecx, DWORD PTR _bp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, DWORD PTR _nextbits$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _nextdata$[ebp]
	or	eax, edx
	mov	DWORD PTR _nextdata$[ebp], eax
	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _bp$[ebp], ecx
	mov	edx, DWORD PTR _nextbits$[ebp]
	add	edx, 8
	mov	DWORD PTR _nextbits$[ebp], edx
$L66096:
	mov	eax, DWORD PTR _nextdata$[ebp]
	and	eax, DWORD PTR _nbitsmask$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	DWORD PTR _code$[ebp], eax
	mov	edx, DWORD PTR _nextdata$[ebp]
	mov	ecx, DWORD PTR _nbits$[ebp]
	sar	edx, cl
	mov	DWORD PTR _nextdata$[ebp], edx
	mov	eax, DWORD PTR _nextbits$[ebp]
	sub	eax, DWORD PTR _nbits$[ebp]
	mov	DWORD PTR _nextbits$[ebp], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+72]
	sub	edx, DWORD PTR _nbits$[ebp]
	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+72], edx
$L66094:

; 564  : 			if (code == CODE_EOI)

	cmp	DWORD PTR _code$[ebp], 257		; 00000101H
	jne	SHORT $L66099

; 565  : 				break;

	jmp	$L66082
$L66099:

; 566  : 			*op++ = code, occ--;

	mov	ecx, DWORD PTR _op$[ebp]
	mov	dl, BYTE PTR _code$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 1
	mov	DWORD PTR _op$[ebp], eax
	mov	ecx, DWORD PTR _occ$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _occ$[ebp], ecx

; 567  : 			oldcodep = sp->dec_codetab + code;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+96]
	mov	ecx, DWORD PTR _code$[ebp]
	lea	edx, DWORD PTR [eax+ecx*8]
	mov	DWORD PTR _oldcodep$[ebp], edx

; 568  : 			continue;

	jmp	$L66081
$L66091:

; 570  : 		codep = sp->dec_codetab + code;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+96]
	mov	edx, DWORD PTR _code$[ebp]
	lea	eax, DWORD PTR [ecx+edx*8]
	mov	DWORD PTR _codep$[ebp], eax

; 571  : 
; 572  : 		/*
; 573  : 	 	 * Add the new entry to the code table.
; 574  : 	 	 */
; 575  : 		assert(&sp->dec_codetab[0] <= free_entp && free_entp < &sp->dec_codetab[CSIZE]);

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+96]
	cmp	edx, DWORD PTR _free_entp$[ebp]
	ja	SHORT $L66179
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+96]
	add	ecx, 40952				; 00009ff8H
	cmp	DWORD PTR _free_entp$[ebp], ecx
	jb	SHORT $L66180
$L66179:
	push	575					; 0000023fH
	push	OFFSET FLAT:$SG66101
	push	OFFSET FLAT:$SG66102
	call	__assert
	add	esp, 12					; 0000000cH
$L66180:

; 576  : 		free_entp->next = oldcodep;

	mov	eax, DWORD PTR _free_entp$[ebp]
	mov	ecx, DWORD PTR _oldcodep$[ebp]
	mov	DWORD PTR [eax], ecx

; 577  : 		free_entp->firstchar = free_entp->next->firstchar;

	mov	edx, DWORD PTR _free_entp$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	ecx, DWORD PTR _free_entp$[ebp]
	mov	dl, BYTE PTR [eax+7]
	mov	BYTE PTR [ecx+7], dl

; 578  : 		free_entp->length = free_entp->next->length+1;

	mov	eax, DWORD PTR _free_entp$[ebp]
	mov	ecx, DWORD PTR [eax]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+4]
	add	edx, 1
	mov	eax, DWORD PTR _free_entp$[ebp]
	mov	WORD PTR [eax+4], dx

; 579  : 		free_entp->value = (codep < free_entp) ?
; 580  : 		    codep->firstchar : free_entp->firstchar;

	mov	ecx, DWORD PTR _codep$[ebp]
	cmp	ecx, DWORD PTR _free_entp$[ebp]
	jae	SHORT $L66181
	mov	edx, DWORD PTR _codep$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+7]
	mov	DWORD PTR -64+[ebp], eax
	jmp	SHORT $L66182
$L66181:
	mov	ecx, DWORD PTR _free_entp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+7]
	mov	DWORD PTR -64+[ebp], edx
$L66182:
	mov	eax, DWORD PTR _free_entp$[ebp]
	mov	cl, BYTE PTR -64+[ebp]
	mov	BYTE PTR [eax+6], cl

; 581  : 		if (++free_entp > maxcodep) {

	mov	edx, DWORD PTR _free_entp$[ebp]
	add	edx, 8
	mov	DWORD PTR _free_entp$[ebp], edx
	mov	eax, DWORD PTR _free_entp$[ebp]
	cmp	eax, DWORD PTR _maxcodep$[ebp]
	jbe	SHORT $L66103

; 582  : 			if (++nbits > BITS_MAX)		/* should not happen */

	mov	ecx, DWORD PTR _nbits$[ebp]
	add	ecx, 1
	mov	DWORD PTR _nbits$[ebp], ecx
	cmp	DWORD PTR _nbits$[ebp], 12		; 0000000cH
	jle	SHORT $L66104

; 583  : 				nbits = BITS_MAX;

	mov	DWORD PTR _nbits$[ebp], 12		; 0000000cH
$L66104:

; 584  : 			nbitsmask = MAXCODE(nbits);

	mov	edx, 1
	mov	ecx, DWORD PTR _nbits$[ebp]
	shl	edx, cl
	sub	edx, 1
	mov	DWORD PTR _nbitsmask$[ebp], edx

; 585  : 			maxcodep = sp->dec_codetab + nbitsmask;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+96]
	mov	edx, DWORD PTR _nbitsmask$[ebp]
	lea	eax, DWORD PTR [ecx+edx*8]
	mov	DWORD PTR _maxcodep$[ebp], eax
$L66103:

; 587  : 		oldcodep = codep;

	mov	ecx, DWORD PTR _codep$[ebp]
	mov	DWORD PTR _oldcodep$[ebp], ecx

; 588  : 		if (code >= 256) {

	cmp	DWORD PTR _code$[ebp], 256		; 00000100H
	jl	$L66105

; 589  : 			/*
; 590  : 		 	 * Code maps to a string, copy string
; 591  : 			 * value to output (written in reverse).
; 592  : 		 	 */
; 593  : 			if (codep->length > occ) {

	mov	edx, DWORD PTR _codep$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+4]
	cmp	eax, DWORD PTR _occ$[ebp]
	jle	SHORT $L66106

; 594  : 				/*
; 595  : 				 * String is too long for decode buffer,
; 596  : 				 * locate portion that will fit, copy to
; 597  : 				 * the decode buffer, and setup restart
; 598  : 				 * logic for the next decoding call.
; 599  : 				 */
; 600  : 				sp->dec_codep = codep;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _codep$[ebp]
	mov	DWORD PTR [ecx+80], edx
$L66107:

; 602  : 					codep = codep->next;

	mov	eax, DWORD PTR _codep$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _codep$[ebp], ecx

; 603  : 				} while (codep->length > occ);

	mov	edx, DWORD PTR _codep$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+4]
	cmp	eax, DWORD PTR _occ$[ebp]
	jg	SHORT $L66107

; 604  : 				sp->dec_restart = occ;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _occ$[ebp]
	mov	DWORD PTR [ecx+68], edx

; 605  : 				tp = op + occ;

	mov	eax, DWORD PTR _op$[ebp]
	add	eax, DWORD PTR _occ$[ebp]
	mov	DWORD PTR _tp$[ebp], eax
$L66110:

; 607  : 					*--tp = codep->value;

	mov	ecx, DWORD PTR _tp$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _tp$[ebp], ecx
	mov	edx, DWORD PTR _tp$[ebp]
	mov	eax, DWORD PTR _codep$[ebp]
	mov	cl, BYTE PTR [eax+6]
	mov	BYTE PTR [edx], cl

; 608  : 					codep = codep->next;

	mov	edx, DWORD PTR _codep$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR _codep$[ebp], eax

; 609  : 				}  while (--occ);

	mov	ecx, DWORD PTR _occ$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _occ$[ebp], ecx
	cmp	DWORD PTR _occ$[ebp], 0
	jne	SHORT $L66110

; 610  : 				break;

	jmp	SHORT $L66082
$L66106:

; 612  : 			op += codep->length, occ -= codep->length;

	mov	edx, DWORD PTR _codep$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+4]
	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, eax
	mov	DWORD PTR _op$[ebp], ecx
	mov	edx, DWORD PTR _codep$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+4]
	mov	ecx, DWORD PTR _occ$[ebp]
	sub	ecx, eax
	mov	DWORD PTR _occ$[ebp], ecx

; 613  : 			tp = op;

	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR _tp$[ebp], edx
$L66113:

; 615  : 				*--tp = codep->value;

	mov	eax, DWORD PTR _tp$[ebp]
	sub	eax, 1
	mov	DWORD PTR _tp$[ebp], eax
	mov	ecx, DWORD PTR _tp$[ebp]
	mov	edx, DWORD PTR _codep$[ebp]
	mov	al, BYTE PTR [edx+6]
	mov	BYTE PTR [ecx], al

; 616  : 			} while( (codep = codep->next) != NULL);

	mov	ecx, DWORD PTR _codep$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR _codep$[ebp], edx
	cmp	DWORD PTR _codep$[ebp], 0
	jne	SHORT $L66113

; 617  : 		} else

	jmp	SHORT $L66117
$L66105:

; 618  : 			*op++ = code, occ--;

	mov	eax, DWORD PTR _op$[ebp]
	mov	cl, BYTE PTR _code$[ebp]
	mov	BYTE PTR [eax], cl
	mov	edx, DWORD PTR _op$[ebp]
	add	edx, 1
	mov	DWORD PTR _op$[ebp], edx
	mov	eax, DWORD PTR _occ$[ebp]
	sub	eax, 1
	mov	DWORD PTR _occ$[ebp], eax
$L66117:

; 619  : 	}

	jmp	$L66081
$L66082:

; 620  : 
; 621  : 	tif->tif_rawcp = (tidata_t) bp;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _bp$[ebp]
	mov	DWORD PTR [ecx+480], edx

; 622  : 	sp->lzw_nbits = nbits;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	cx, WORD PTR _nbits$[ebp]
	mov	WORD PTR [eax+48], cx

; 623  : 	sp->lzw_nextdata = nextdata;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _nextdata$[ebp]
	mov	DWORD PTR [edx+56], eax

; 624  : 	sp->lzw_nextbits = nextbits;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _nextbits$[ebp]
	mov	DWORD PTR [ecx+60], edx

; 625  : 	sp->dec_nbitsmask = nbitsmask;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _nbitsmask$[ebp]
	mov	DWORD PTR [eax+64], ecx

; 626  : 	sp->dec_oldcodep = oldcodep;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _oldcodep$[ebp]
	mov	DWORD PTR [edx+84], eax

; 627  : 	sp->dec_free_entp = free_entp;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _free_entp$[ebp]
	mov	DWORD PTR [ecx+88], edx

; 628  : 	sp->dec_maxcodep = maxcodep;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _maxcodep$[ebp]
	mov	DWORD PTR [eax+92], ecx

; 629  : 
; 630  : 	if (occ > 0) {

	cmp	DWORD PTR _occ$[ebp], 0
	jle	SHORT $L66119

; 631  : 		TIFFError(tif->tif_name,
; 632  : 	    "LZWDecodeCompat: Not enough data at scanline %d (short %d bytes)",
; 633  : 		    tif->tif_row, occ);

	mov	edx, DWORD PTR _occ$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+356]
	push	ecx
	push	OFFSET FLAT:$SG66120
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 16					; 00000010H

; 634  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L66043
$L66119:

; 636  : 	return (1);

	mov	eax, 1
$L66043:

; 637  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LZWDecodeCompat ENDP
_TEXT	ENDS
EXTRN	__TIFFfree:NEAR
_TEXT	SEGMENT
_tif$ = 8
_LZWCleanup PROC NEAR

; 644  : {

	push	ebp
	mov	ebp, esp

; 645  : 	if (tif->tif_data) {

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+460], 0
	je	SHORT $L66125

; 646  : 		if (tif->tif_mode == O_RDONLY) {

	mov	ecx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [ecx+8], 0
	jne	SHORT $L66129

; 647  : 			if (DecoderState(tif)->dec_codetab)

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+460]
	cmp	DWORD PTR [eax+96], 0
	je	SHORT $L66129

; 648  : 				_TIFFfree(DecoderState(tif)->dec_codetab);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+460]
	mov	eax, DWORD PTR [edx+96]
	push	eax
	call	__TIFFfree
	add	esp, 4
$L66129:

; 650  : 		_TIFFfree(tif->tif_data);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+460]
	push	edx
	call	__TIFFfree
	add	esp, 4

; 651  : 		tif->tif_data = NULL;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+460], 0
$L66125:

; 653  : }

	pop	ebp
	ret	0
_LZWCleanup ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+3
$SG66137 DB	'LZW compression is not available to due to Unisys patent'
	DB	' enforcement', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_LZWSetupEncode PROC NEAR

; 657  : {

	push	ebp
	mov	ebp, esp

; 658  :     TIFFError(tif->tif_name,
; 659  :               "LZW compression is not available to due to Unisys patent enforcement");

	push	OFFSET FLAT:$SG66137
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 8

; 660  :     return (0);

	xor	eax, eax

; 661  : }

	pop	ebp
	ret	0
_LZWSetupEncode ENDP
_TEXT	ENDS
END
