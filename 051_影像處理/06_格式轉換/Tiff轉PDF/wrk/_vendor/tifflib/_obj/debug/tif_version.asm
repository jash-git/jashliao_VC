	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_version.c
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
_TIFFVersion DB	'LIBTIFF, Version 3.5.7', 0aH, 'Copyright (c) 1988-1996 S'
	DB	'am Leffler', 0aH, 'Copyright (c) 1991-1996 Silicon Graphics, '
	DB	'Inc.', 00H
CONST	ENDS
PUBLIC	_TIFFGetVersion
_TEXT	SEGMENT
_TIFFGetVersion PROC NEAR

; 31   : {

	push	ebp
	mov	ebp, esp

; 32   : 	return (TIFFVersion);

	mov	eax, OFFSET FLAT:_TIFFVersion

; 33   : }

	pop	ebp
	ret	0
_TIFFGetVersion ENDP
_TEXT	ENDS
END
