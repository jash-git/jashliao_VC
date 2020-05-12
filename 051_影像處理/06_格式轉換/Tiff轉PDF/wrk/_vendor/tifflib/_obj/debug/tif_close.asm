	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_close.c
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
PUBLIC	_TIFFClose
EXTRN	_TIFFFreeDirectory:NEAR
EXTRN	__TIFFfree:NEAR
EXTRN	_TIFFFlush:NEAR
_TEXT	SEGMENT
_tif$ = 8
_TIFFClose PROC NEAR

; 34   : {

	push	ebp
	mov	ebp, esp

; 35   : 	if (tif->tif_mode != O_RDONLY)

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+8], 0
	je	SHORT $L65785

; 36   : 		/*
; 37   : 		 * Flush buffered data and directory (if dirty).
; 38   : 		 */
; 39   : 		TIFFFlush(tif);

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFlush
	add	esp, 4
$L65785:

; 40   : 	(*tif->tif_cleanup)(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+448]
	add	esp, 4

; 41   : 	TIFFFreeDirectory(tif);

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFreeDirectory
	add	esp, 4

; 42   : 	if (tif->tif_rawdata && (tif->tif_flags&TIFF_MYBUFFER))

	mov	edx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [edx+472], 0
	je	SHORT $L65786
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 512				; 00000200H
	test	ecx, ecx
	je	SHORT $L65786

; 43   : 		_TIFFfree(tif->tif_rawdata);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+472]
	push	eax
	call	__TIFFfree
	add	esp, 4
$L65786:

; 44   : 	if (isMapped(tif))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 2048				; 00000800H
	test	edx, edx
	je	SHORT $L65787

; 45   : 		TIFFUnmapFileContents(tif, tif->tif_base, tif->tif_size);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+492]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+488]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+500]
	add	esp, 12					; 0000000cH
$L65787:

; 46   : 	(void) TIFFCloseFile(tif);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+520]
	add	esp, 4

; 47   : 	if (tif->tif_fieldinfo)

	mov	ecx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [ecx+532], 0
	je	SHORT $L65789

; 48   : 		_TIFFfree(tif->tif_fieldinfo);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+532]
	push	eax
	call	__TIFFfree
	add	esp, 4
$L65789:

; 49   : 	_TIFFfree(tif);

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	__TIFFfree
	add	esp, 4

; 50   : }

	pop	ebp
	ret	0
_TIFFClose ENDP
_TEXT	ENDS
END
