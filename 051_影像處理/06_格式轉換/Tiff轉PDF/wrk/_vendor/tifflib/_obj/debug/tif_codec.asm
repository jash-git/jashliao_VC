	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_codec.c
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
PUBLIC	__TIFFBuiltinCODECS
EXTRN	_TIFFInitDumpMode:NEAR
EXTRN	_TIFFInitPackBits:NEAR
EXTRN	_TIFFInitCCITTRLE:NEAR
EXTRN	_TIFFInitCCITTRLEW:NEAR
EXTRN	_TIFFInitCCITTFax3:NEAR
EXTRN	_TIFFInitCCITTFax4:NEAR
EXTRN	_TIFFInitThunderScan:NEAR
EXTRN	_TIFFInitNeXT:NEAR
EXTRN	_TIFFInitLZW:NEAR
EXTRN	_TIFFInitSGILog:NEAR
_DATA	SEGMENT
__TIFFBuiltinCODECS DD FLAT:$SG65790
	DW	01H
	ORG $+2
	DD	FLAT:_TIFFInitDumpMode
	DD	FLAT:$SG65791
	DW	05H
	ORG $+2
	DD	FLAT:_TIFFInitLZW
	DD	FLAT:$SG65792
	DW	08005H
	ORG $+2
	DD	FLAT:_TIFFInitPackBits
	DD	FLAT:$SG65793
	DW	08029H
	ORG $+2
	DD	FLAT:_TIFFInitThunderScan
	DD	FLAT:$SG65794
	DW	07ffeH
	ORG $+2
	DD	FLAT:_TIFFInitNeXT
	DD	FLAT:$SG65795
	DW	07H
	ORG $+2
	DD	FLAT:_NotConfigured
	DD	FLAT:$SG65796
	DW	06H
	ORG $+2
	DD	FLAT:_NotConfigured
	DD	FLAT:$SG65797
	DW	02H
	ORG $+2
	DD	FLAT:_TIFFInitCCITTRLE
	DD	FLAT:$SG65798
	DW	08003H
	ORG $+2
	DD	FLAT:_TIFFInitCCITTRLEW
	DD	FLAT:$SG65799
	DW	03H
	ORG $+2
	DD	FLAT:_TIFFInitCCITTFax3
	DD	FLAT:$SG65800
	DW	04H
	ORG $+2
	DD	FLAT:_TIFFInitCCITTFax4
	DD	FLAT:$SG65801
	DW	08765H
	ORG $+2
	DD	FLAT:_NotConfigured
	DD	FLAT:$SG65802
	DW	080b2H
	ORG $+2
	DD	FLAT:_NotConfigured
	DD	FLAT:$SG65803
	DW	08H
	ORG $+2
	DD	FLAT:_NotConfigured
	DD	FLAT:$SG65804
	DW	0808dH
	ORG $+2
	DD	FLAT:_NotConfigured
	DD	FLAT:$SG65805
	DW	08774H
	ORG $+2
	DD	FLAT:_TIFFInitSGILog
	DD	FLAT:$SG65806
	DW	08775H
	ORG $+2
	DD	FLAT:_TIFFInitSGILog
	DD	00H
	ORG $+8
$SG65790 DB	'None', 00H
	ORG $+3
$SG65791 DB	'LZW', 00H
$SG65792 DB	'PackBits', 00H
	ORG $+3
$SG65793 DB	'ThunderScan', 00H
$SG65794 DB	'NeXT', 00H
	ORG $+3
$SG65795 DB	'JPEG', 00H
	ORG $+3
$SG65796 DB	'Old-style JPEG', 00H
	ORG $+1
$SG65797 DB	'CCITT RLE', 00H
	ORG $+2
$SG65798 DB	'CCITT RLE/W', 00H
$SG65799 DB	'CCITT Group 3', 00H
	ORG $+2
$SG65800 DB	'CCITT Group 4', 00H
	ORG $+2
$SG65801 DB	'ISO JBIG', 00H
	ORG $+3
$SG65802 DB	'Deflate', 00H
$SG65803 DB	'AdobeDeflate', 00H
	ORG $+3
$SG65804 DB	'PixarLog', 00H
	ORG $+3
$SG65805 DB	'SGILog', 00H
	ORG $+1
$SG65806 DB	'SGILog24', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_NotConfigured PROC NEAR

; 113  : {

	push	ebp
	mov	ebp, esp

; 114  : 	tif->tif_setupdecode = _notConfigured;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+396], OFFSET FLAT:__notConfigured

; 115  : 	tif->tif_setupencode = _notConfigured;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+404], OFFSET FLAT:__notConfigured

; 116  : 	return (1);

	mov	eax, 1

; 117  : }

	pop	ebp
	ret	0
_NotConfigured ENDP
_TEXT	ENDS
EXTRN	_TIFFFindCODEC:NEAR
EXTRN	_TIFFError:NEAR
_DATA	SEGMENT
	ORG $+3
$SG65814 DB	'%s compression support is not configured', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_c$ = -4
__notConfigured PROC NEAR

; 103  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 104  : 	const TIFFCodec* c = TIFFFindCODEC(tif->tif_dir.td_compression);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	cx, WORD PTR [eax+68]
	push	ecx
	call	_TIFFFindCODEC
	add	esp, 4
	mov	DWORD PTR _c$[ebp], eax

; 105  : 
; 106  : 	TIFFError(tif->tif_name,
; 107  : 	    "%s compression support is not configured", c->name);

	mov	edx, DWORD PTR _c$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	push	OFFSET FLAT:$SG65814
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 108  : 	return (0);

	xor	eax, eax

; 109  : }

	mov	esp, ebp
	pop	ebp
	ret	0
__notConfigured ENDP
_TEXT	ENDS
END
