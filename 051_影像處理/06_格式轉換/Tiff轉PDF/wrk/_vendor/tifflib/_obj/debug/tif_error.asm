	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_error.c
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
PUBLIC	_TIFFSetErrorHandler
EXTRN	__TIFFerrorHandler:DWORD
_TEXT	SEGMENT
_handler$ = 8
_prev$ = -4
_TIFFSetErrorHandler PROC NEAR

; 34   : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 35   : 	TIFFErrorHandler prev = _TIFFerrorHandler;

	mov	eax, DWORD PTR __TIFFerrorHandler
	mov	DWORD PTR _prev$[ebp], eax

; 36   : 	_TIFFerrorHandler = handler;

	mov	ecx, DWORD PTR _handler$[ebp]
	mov	DWORD PTR __TIFFerrorHandler, ecx

; 37   : 	return (prev);

	mov	eax, DWORD PTR _prev$[ebp]

; 38   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFSetErrorHandler ENDP
_TEXT	ENDS
PUBLIC	_TIFFError
_TEXT	SEGMENT
_module$ = 8
_fmt$ = 12
_ap$65794 = -4
_TIFFError PROC NEAR

; 42   : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 43   : 	if (_TIFFerrorHandler) {

	cmp	DWORD PTR __TIFFerrorHandler, 0
	je	SHORT $L65793

; 44   : 		va_list ap;
; 45   : 		va_start(ap, fmt);

	lea	eax, DWORD PTR _fmt$[ebp+4]
	mov	DWORD PTR _ap$65794[ebp], eax

; 46   : 		(*_TIFFerrorHandler)(module, fmt, ap);

	mov	ecx, DWORD PTR _ap$65794[ebp]
	push	ecx
	mov	edx, DWORD PTR _fmt$[ebp]
	push	edx
	mov	eax, DWORD PTR _module$[ebp]
	push	eax
	call	DWORD PTR __TIFFerrorHandler
	add	esp, 12					; 0000000cH

; 47   : 		va_end(ap);

	mov	DWORD PTR _ap$65794[ebp], 0
$L65793:

; 49   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFError ENDP
_TEXT	ENDS
END
