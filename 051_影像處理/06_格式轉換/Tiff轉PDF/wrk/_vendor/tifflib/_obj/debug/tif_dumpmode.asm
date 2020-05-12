	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_dumpmode.c
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
PUBLIC	_TIFFInitDumpMode
_TEXT	SEGMENT
_tif$ = 8
_TIFFInitDumpMode PROC NEAR

; 108  : {

	push	ebp
	mov	ebp, esp

; 109  : 	(void) scheme;
; 110  : 	tif->tif_decoderow = DumpModeDecode;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+416], OFFSET FLAT:_DumpModeDecode

; 111  : 	tif->tif_decodestrip = DumpModeDecode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+424], OFFSET FLAT:_DumpModeDecode

; 112  : 	tif->tif_decodetile = DumpModeDecode;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+432], OFFSET FLAT:_DumpModeDecode

; 113  : 	tif->tif_encoderow = DumpModeEncode;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+420], OFFSET FLAT:_DumpModeEncode

; 114  : 	tif->tif_encodestrip = DumpModeEncode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+428], OFFSET FLAT:_DumpModeEncode

; 115  : 	tif->tif_encodetile = DumpModeEncode;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+436], OFFSET FLAT:_DumpModeEncode

; 116  : 	tif->tif_seek = DumpModeSeek;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+444], OFFSET FLAT:_DumpModeSeek

; 117  : 	return (1);

	mov	eax, 1

; 118  : }

	pop	ebp
	ret	0
_TIFFInitDumpMode ENDP
_TEXT	ENDS
EXTRN	_TIFFFlushData1:NEAR
EXTRN	__assert:NEAR
EXTRN	__TIFFmemcpy:NEAR
_DATA	SEGMENT
$SG65806 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_dumpmode.c', 00H
	ORG $+3
$SG65807 DB	'n > 0', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_pp$ = 12
_cc$ = 16
_n$65803 = -4
_DumpModeEncode PROC NEAR

; 40   : {

	push	ebp
	mov	ebp, esp
	push	ecx
$L65801:

; 41   : 	(void) s;
; 42   : 	while (cc > 0) {

	cmp	DWORD PTR _cc$[ebp], 0
	jle	$L65802

; 43   : 		tsize_t n;
; 44   : 
; 45   : 		n = cc;

	mov	eax, DWORD PTR _cc$[ebp]
	mov	DWORD PTR _n$65803[ebp], eax

; 46   : 		if (tif->tif_rawcc + n > tif->tif_rawdatasize)

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+484]
	add	edx, DWORD PTR _n$65803[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	cmp	edx, DWORD PTR [eax+476]
	jle	SHORT $L65804

; 47   : 			n = tif->tif_rawdatasize - tif->tif_rawcc;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [ecx+476]
	sub	eax, DWORD PTR [edx+484]
	mov	DWORD PTR _n$65803[ebp], eax
$L65804:

; 48   : 
; 49   :                 assert( n > 0 );

	cmp	DWORD PTR _n$65803[ebp], 0
	jg	SHORT $L65840
	push	49					; 00000031H
	push	OFFSET FLAT:$SG65806
	push	OFFSET FLAT:$SG65807
	call	__assert
	add	esp, 12					; 0000000cH
$L65840:

; 50   :                 
; 51   : 		/*
; 52   : 		 * Avoid copy if client has setup raw
; 53   : 		 * data buffer to avoid extra copy.
; 54   : 		 */
; 55   : 		if (tif->tif_rawcp != pp)

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+480]
	cmp	eax, DWORD PTR _pp$[ebp]
	je	SHORT $L65808

; 56   : 			_TIFFmemcpy(tif->tif_rawcp, pp, n);

	mov	ecx, DWORD PTR _n$65803[ebp]
	push	ecx
	mov	edx, DWORD PTR _pp$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	push	ecx
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH
$L65808:

; 57   : 		tif->tif_rawcp += n;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+480]
	add	eax, DWORD PTR _n$65803[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+480], eax

; 58   : 		tif->tif_rawcc += n;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+484]
	add	eax, DWORD PTR _n$65803[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+484], eax

; 59   : 		pp += n;

	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _n$65803[ebp]
	mov	DWORD PTR _pp$[ebp], edx

; 60   : 		cc -= n;

	mov	eax, DWORD PTR _cc$[ebp]
	sub	eax, DWORD PTR _n$65803[ebp]
	mov	DWORD PTR _cc$[ebp], eax

; 61   : 		if (tif->tif_rawcc >= tif->tif_rawdatasize &&
; 62   : 		    !TIFFFlushData1(tif))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [ecx+484]
	cmp	eax, DWORD PTR [edx+476]
	jl	SHORT $L65809
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFlushData1
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65809

; 63   : 			return (-1);

	or	eax, -1
	jmp	SHORT $L65798
$L65809:

; 64   : 	}

	jmp	$L65801
$L65802:

; 65   : 	return (1);

	mov	eax, 1
$L65798:

; 66   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_DumpModeEncode ENDP
_TEXT	ENDS
EXTRN	_TIFFError:NEAR
_DATA	SEGMENT
	ORG $+2
$SG65822 DB	'DumpModeDecode: Not enough data for scanline %d', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_buf$ = 12
_cc$ = 16
_DumpModeDecode PROC NEAR

; 73   : {

	push	ebp
	mov	ebp, esp

; 74   : 	(void) s;
; 75   : 	if (tif->tif_rawcc < cc) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+484]
	cmp	ecx, DWORD PTR _cc$[ebp]
	jge	SHORT $L65821

; 76   : 		TIFFError(tif->tif_name,
; 77   : 		    "DumpModeDecode: Not enough data for scanline %d",
; 78   : 		    tif->tif_row);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+356]
	push	eax
	push	OFFSET FLAT:$SG65822
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 79   : 		return (0);

	xor	eax, eax
	jmp	SHORT $L65819
$L65821:

; 81   : 	/*
; 82   : 	 * Avoid copy if client has setup raw
; 83   : 	 * data buffer to avoid extra copy.
; 84   : 	 */
; 85   : 	if (tif->tif_rawcp != buf)

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	cmp	ecx, DWORD PTR _buf$[ebp]
	je	SHORT $L65823

; 86   : 		_TIFFmemcpy(buf, tif->tif_rawcp, cc);

	mov	edx, DWORD PTR _cc$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	push	ecx
	mov	edx, DWORD PTR _buf$[ebp]
	push	edx
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH
$L65823:

; 87   : 	tif->tif_rawcp += cc;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	add	ecx, DWORD PTR _cc$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+480], ecx

; 88   : 	tif->tif_rawcc -= cc;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+484]
	sub	ecx, DWORD PTR _cc$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], ecx

; 89   : 	return (1);

	mov	eax, 1
$L65819:

; 90   : }

	pop	ebp
	ret	0
_DumpModeDecode ENDP
_tif$ = 8
_nrows$ = 12
_DumpModeSeek PROC NEAR

; 97   : {

	push	ebp
	mov	ebp, esp

; 98   : 	tif->tif_rawcp += nrows * tif->tif_scanlinesize;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _nrows$[ebp]
	imul	ecx, DWORD PTR [eax+464]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+480]
	add	eax, ecx
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+480], eax

; 99   : 	tif->tif_rawcc -= nrows * tif->tif_scanlinesize;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _nrows$[ebp]
	imul	eax, DWORD PTR [edx+464]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+484]
	sub	edx, eax
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+484], edx

; 100  : 	return (1);

	mov	eax, 1

; 101  : }

	pop	ebp
	ret	0
_DumpModeSeek ENDP
_TEXT	ENDS
END
