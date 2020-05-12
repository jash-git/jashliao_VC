	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_flush.c
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
PUBLIC	_TIFFFlush
PUBLIC	_TIFFFlushData
EXTRN	_TIFFWriteDirectory:NEAR
_TEXT	SEGMENT
_tif$ = 8
_TIFFFlush PROC NEAR

; 34   : {

	push	ebp
	mov	ebp, esp

; 35   : 
; 36   : 	if (tif->tif_mode != O_RDONLY) {

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+8], 0
	je	SHORT $L65788

; 37   : 		if (!TIFFFlushData(tif))

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFlushData
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65787

; 38   : 			return (0);

	xor	eax, eax
	jmp	SHORT $L65785
$L65787:

; 39   : 		if ((tif->tif_flags & TIFF_DIRTYDIRECT) &&
; 40   : 		    !TIFFWriteDirectory(tif))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 8
	test	eax, eax
	je	SHORT $L65788
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFWriteDirectory
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65788

; 41   : 			return (0);

	xor	eax, eax
	jmp	SHORT $L65785
$L65788:

; 43   : 	return (1);

	mov	eax, 1
$L65785:

; 44   : }

	pop	ebp
	ret	0
_TIFFFlush ENDP
_TEXT	ENDS
EXTRN	_TIFFFlushData1:NEAR
_TEXT	SEGMENT
_tif$ = 8
_TIFFFlushData PROC NEAR

; 57   : {

	push	ebp
	mov	ebp, esp

; 58   : 	if ((tif->tif_flags & TIFF_BEENWRITING) == 0)

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 64					; 00000040H
	test	ecx, ecx
	jne	SHORT $L65792

; 59   : 		return (0);

	xor	eax, eax
	jmp	SHORT $L65791
$L65792:

; 60   : 	if (tif->tif_flags & TIFF_POSTENCODE) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 4096				; 00001000H
	test	eax, eax
	je	SHORT $L65794

; 61   : 		tif->tif_flags &= ~TIFF_POSTENCODE;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	dh, -17					; ffffffefH
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+12], edx

; 62   : 		if (!(*tif->tif_postencode)(tif))

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+412]
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65794

; 63   : 			return (0);

	xor	eax, eax
	jmp	SHORT $L65791
$L65794:

; 65   : 	return (TIFFFlushData1(tif));

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFlushData1
	add	esp, 4
$L65791:

; 66   : }

	pop	ebp
	ret	0
_TIFFFlushData ENDP
_TEXT	ENDS
END
