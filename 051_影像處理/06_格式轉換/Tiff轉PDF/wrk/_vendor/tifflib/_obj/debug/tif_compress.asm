	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_compress.c
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
_BSS	SEGMENT
_registeredCODECS DD 01H DUP (?)
_BSS	ENDS
PUBLIC	__TIFFNoRowEncode
_DATA	SEGMENT
$SG65810 DB	'scanline', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
__TIFFNoRowEncode PROC NEAR

; 59   : {

	push	ebp
	mov	ebp, esp

; 60   : 	(void) pp; (void) cc; (void) s;
; 61   : 	return (TIFFNoEncode(tif, "scanline"));

	push	OFFSET FLAT:$SG65810
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFNoEncode
	add	esp, 8

; 62   : }

	pop	ebp
	ret	0
__TIFFNoRowEncode ENDP
_TEXT	ENDS
PUBLIC	_TIFFFindCODEC
EXTRN	_strncmp:NEAR
EXTRN	_TIFFError:NEAR
_DATA	SEGMENT
	ORG $+3
$SG65792 DB	'LZW', 00H
$SG65793 DB	'%s %s encoding is no longer implemented due to Unisys pa'
	DB	'tent enforcement', 00H
	ORG $+3
$SG65795 DB	'%s %s encoding is not implemented', 00H
	ORG $+2
$SG65797 DB	'Compression scheme %u %s encoding is not implemented', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_method$ = 12
_c$ = -4
_TIFFNoEncode PROC NEAR

; 36   : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 37   : 	const TIFFCodec* c = TIFFFindCODEC(tif->tif_dir.td_compression);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	cx, WORD PTR [eax+68]
	push	ecx
	call	_TIFFFindCODEC
	add	esp, 4
	mov	DWORD PTR _c$[ebp], eax

; 38   : 
; 39   : 	if (c) { 

	cmp	DWORD PTR _c$[ebp], 0
	je	SHORT $L65790

; 40   : 	  if (! strncmp(c->name, "LZW", 3) ){ 

	push	3
	push	OFFSET FLAT:$SG65792
	mov	edx, DWORD PTR _c$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_strncmp
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65791

; 41   : 	    TIFFError(tif->tif_name, 
; 42   : 		      "%s %s encoding is no longer implemented due to Unisys patent enforcement", 
; 43   : 		      c->name, method); 

	mov	ecx, DWORD PTR _method$[ebp]
	push	ecx
	mov	edx, DWORD PTR _c$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	push	OFFSET FLAT:$SG65793
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 16					; 00000010H

; 44   : 	  } else { 

	jmp	SHORT $L65794
$L65791:

; 45   : 	    TIFFError(tif->tif_name, "%s %s encoding is not implemented",
; 46   : 		      c->name, method);

	mov	eax, DWORD PTR _method$[ebp]
	push	eax
	mov	ecx, DWORD PTR _c$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	push	OFFSET FLAT:$SG65795
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 16					; 00000010H
$L65794:

; 49   : 	else { 

	jmp	SHORT $L65796
$L65790:

; 50   : 		TIFFError(tif->tif_name,
; 51   : 			  "Compression scheme %u %s encoding is not implemented",
; 52   : 		    tif->tif_dir.td_compression, method);

	mov	edx, DWORD PTR _method$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+68]
	push	ecx
	push	OFFSET FLAT:$SG65797
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 16					; 00000010H
$L65796:

; 54   : 	return (-1);

	or	eax, -1

; 55   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFNoEncode ENDP
_TEXT	ENDS
PUBLIC	__TIFFNoStripEncode
_DATA	SEGMENT
	ORG $+3
$SG65823 DB	'strip', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
__TIFFNoStripEncode PROC NEAR

; 66   : {

	push	ebp
	mov	ebp, esp

; 67   : 	(void) pp; (void) cc; (void) s;
; 68   : 	return (TIFFNoEncode(tif, "strip"));

	push	OFFSET FLAT:$SG65823
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFNoEncode
	add	esp, 8

; 69   : }

	pop	ebp
	ret	0
__TIFFNoStripEncode ENDP
_TEXT	ENDS
PUBLIC	__TIFFNoTileEncode
_DATA	SEGMENT
	ORG $+2
$SG65836 DB	'tile', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
__TIFFNoTileEncode PROC NEAR

; 73   : {

	push	ebp
	mov	ebp, esp

; 74   : 	(void) pp; (void) cc; (void) s;
; 75   : 	return (TIFFNoEncode(tif, "tile"));

	push	OFFSET FLAT:$SG65836
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFNoEncode
	add	esp, 8

; 76   : }

	pop	ebp
	ret	0
__TIFFNoTileEncode ENDP
_TEXT	ENDS
PUBLIC	__TIFFNoRowDecode
_DATA	SEGMENT
	ORG $+3
$SG65860 DB	'scanline', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
__TIFFNoRowDecode PROC NEAR

; 95   : {

	push	ebp
	mov	ebp, esp

; 96   : 	(void) pp; (void) cc; (void) s;
; 97   : 	return (TIFFNoDecode(tif, "scanline"));

	push	OFFSET FLAT:$SG65860
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFNoDecode
	add	esp, 8

; 98   : }

	pop	ebp
	ret	0
__TIFFNoRowDecode ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+3
$SG65845 DB	'%s %s decoding is not implemented', 00H
	ORG $+2
$SG65847 DB	'Compression scheme %u %s decoding is not implemented', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_method$ = 12
_c$ = -4
_TIFFNoDecode PROC NEAR

; 80   : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 81   : 	const TIFFCodec* c = TIFFFindCODEC(tif->tif_dir.td_compression);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	cx, WORD PTR [eax+68]
	push	ecx
	call	_TIFFFindCODEC
	add	esp, 4
	mov	DWORD PTR _c$[ebp], eax

; 82   : 
; 83   : 	if (c)

	cmp	DWORD PTR _c$[ebp], 0
	je	SHORT $L65844

; 84   : 		TIFFError(tif->tif_name, "%s %s decoding is not implemented",
; 85   : 		    c->name, method);

	mov	edx, DWORD PTR _method$[ebp]
	push	edx
	mov	eax, DWORD PTR _c$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG65845
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 16					; 00000010H

; 86   : 	else

	jmp	SHORT $L65846
$L65844:

; 87   : 		TIFFError(tif->tif_name,
; 88   : 		    "Compression scheme %u %s decoding is not implemented",
; 89   : 		    tif->tif_dir.td_compression, method);

	mov	ecx, DWORD PTR _method$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+68]
	push	eax
	push	OFFSET FLAT:$SG65847
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 16					; 00000010H
$L65846:

; 90   : 	return (-1);

	or	eax, -1

; 91   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFNoDecode ENDP
_TEXT	ENDS
PUBLIC	__TIFFNoStripDecode
_DATA	SEGMENT
	ORG $+3
$SG65873 DB	'strip', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
__TIFFNoStripDecode PROC NEAR

; 102  : {

	push	ebp
	mov	ebp, esp

; 103  : 	(void) pp; (void) cc; (void) s;
; 104  : 	return (TIFFNoDecode(tif, "strip"));

	push	OFFSET FLAT:$SG65873
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFNoDecode
	add	esp, 8

; 105  : }

	pop	ebp
	ret	0
__TIFFNoStripDecode ENDP
_TEXT	ENDS
PUBLIC	__TIFFNoTileDecode
_DATA	SEGMENT
	ORG $+2
$SG65886 DB	'tile', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
__TIFFNoTileDecode PROC NEAR

; 109  : {

	push	ebp
	mov	ebp, esp

; 110  : 	(void) pp; (void) cc; (void) s;
; 111  : 	return (TIFFNoDecode(tif, "tile"));

	push	OFFSET FLAT:$SG65886
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFNoDecode
	add	esp, 8

; 112  : }

	pop	ebp
	ret	0
__TIFFNoTileDecode ENDP
_TEXT	ENDS
PUBLIC	__TIFFNoSeek
_DATA	SEGMENT
	ORG $+3
$SG65893 DB	'Compression algorithm does not support random access', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
__TIFFNoSeek PROC NEAR

; 116  : {

	push	ebp
	mov	ebp, esp

; 117  : 	(void) off;
; 118  : 	TIFFError(tif->tif_name,
; 119  : 	    "Compression algorithm does not support random access");

	push	OFFSET FLAT:$SG65893
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 8

; 120  : 	return (0);

	xor	eax, eax

; 121  : }

	pop	ebp
	ret	0
__TIFFNoSeek ENDP
_TEXT	ENDS
PUBLIC	__TIFFNoPreCode
_TEXT	SEGMENT
__TIFFNoPreCode PROC NEAR

; 125  : {

	push	ebp
	mov	ebp, esp

; 126  : 	(void) tif; (void) s;
; 127  : 	return (1);

	mov	eax, 1

; 128  : }

	pop	ebp
	ret	0
__TIFFNoPreCode ENDP
_TEXT	ENDS
PUBLIC	__TIFFSetDefaultCompressionState
EXTRN	__TIFFDefaultStripSize:NEAR
EXTRN	__TIFFDefaultTileSize:NEAR
_TEXT	SEGMENT
_tif$ = 8
__TIFFSetDefaultCompressionState PROC NEAR

; 135  : {

	push	ebp
	mov	ebp, esp

; 136  : 	tif->tif_setupdecode = _TIFFtrue;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+396], OFFSET FLAT:__TIFFtrue

; 137  : 	tif->tif_predecode = _TIFFNoPreCode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+400], OFFSET FLAT:__TIFFNoPreCode

; 138  : 	tif->tif_decoderow = _TIFFNoRowDecode;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+416], OFFSET FLAT:__TIFFNoRowDecode

; 139  : 	tif->tif_decodestrip = _TIFFNoStripDecode;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+424], OFFSET FLAT:__TIFFNoStripDecode

; 140  : 	tif->tif_decodetile = _TIFFNoTileDecode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+432], OFFSET FLAT:__TIFFNoTileDecode

; 141  : 	tif->tif_setupencode = _TIFFtrue;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+404], OFFSET FLAT:__TIFFtrue

; 142  : 	tif->tif_preencode = _TIFFNoPreCode;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+408], OFFSET FLAT:__TIFFNoPreCode

; 143  : 	tif->tif_postencode = _TIFFtrue;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+412], OFFSET FLAT:__TIFFtrue

; 144  : 	tif->tif_encoderow = _TIFFNoRowEncode;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+420], OFFSET FLAT:__TIFFNoRowEncode

; 145  : 	tif->tif_encodestrip = _TIFFNoStripEncode;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+428], OFFSET FLAT:__TIFFNoStripEncode

; 146  : 	tif->tif_encodetile = _TIFFNoTileEncode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+436], OFFSET FLAT:__TIFFNoTileEncode

; 147  : 	tif->tif_close = _TIFFvoid;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+440], OFFSET FLAT:__TIFFvoid

; 148  : 	tif->tif_seek = _TIFFNoSeek;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+444], OFFSET FLAT:__TIFFNoSeek

; 149  : 	tif->tif_cleanup = _TIFFvoid;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+448], OFFSET FLAT:__TIFFvoid

; 150  : 	tif->tif_defstripsize = _TIFFDefaultStripSize;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+452], OFFSET FLAT:__TIFFDefaultStripSize

; 151  : 	tif->tif_deftilesize = _TIFFDefaultTileSize;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+456], OFFSET FLAT:__TIFFDefaultTileSize

; 152  : 	tif->tif_flags &= ~TIFF_NOBITREV;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	dh, -2					; fffffffeH
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+12], edx

; 153  : }

	pop	ebp
	ret	0
__TIFFSetDefaultCompressionState ENDP
__TIFFtrue PROC NEAR

; 130  : static int _TIFFtrue(TIFF* tif) { (void) tif; return (1); }

	push	ebp
	mov	ebp, esp
	mov	eax, 1
	pop	ebp
	ret	0
__TIFFtrue ENDP
__TIFFvoid PROC NEAR

; 131  : static void _TIFFvoid(TIFF* tif) { (void) tif; }

	push	ebp
	mov	ebp, esp
	pop	ebp
	ret	0
__TIFFvoid ENDP
_TEXT	ENDS
PUBLIC	_TIFFSetCompressionScheme
_TEXT	SEGMENT
_tif$ = 8
_scheme$ = 12
_c$ = -4
_TIFFSetCompressionScheme PROC NEAR

; 157  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 158  : 	const TIFFCodec *c = TIFFFindCODEC((uint16) scheme);

	mov	ax, WORD PTR _scheme$[ebp]
	push	eax
	call	_TIFFFindCODEC
	add	esp, 4
	mov	DWORD PTR _c$[ebp], eax

; 159  : 
; 160  : 	_TIFFSetDefaultCompressionState(tif);

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	__TIFFSetDefaultCompressionState
	add	esp, 4

; 161  : 	/*
; 162  : 	 * Don't treat an unknown compression scheme as an error.
; 163  : 	 * This permits applications to open files with data that
; 164  : 	 * the library does not have builtin support for, but which
; 165  : 	 * may still be meaningful.
; 166  : 	 */
; 167  : 	return (c ? (*c->init)(tif, scheme) : 1);

	cmp	DWORD PTR _c$[ebp], 0
	je	SHORT $L65992
	mov	edx, DWORD PTR _scheme$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	mov	ecx, DWORD PTR _c$[ebp]
	call	DWORD PTR [ecx+8]
	add	esp, 8
	mov	DWORD PTR -8+[ebp], eax
	jmp	SHORT $L65993
$L65992:
	mov	DWORD PTR -8+[ebp], 1
$L65993:
	mov	eax, DWORD PTR -8+[ebp]

; 168  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFSetCompressionScheme ENDP
_TEXT	ENDS
EXTRN	__TIFFBuiltinCODECS:BYTE
_TEXT	SEGMENT
_scheme$ = 8
_c$ = -4
_cd$ = -8
_TIFFFindCODEC PROC NEAR

; 183  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 184  : 	const TIFFCodec* c;
; 185  : 	codec_t* cd;
; 186  : 
; 187  : 	for (cd = registeredCODECS; cd; cd = cd->next)

	mov	eax, DWORD PTR _registeredCODECS
	mov	DWORD PTR _cd$[ebp], eax
	jmp	SHORT $L65933
$L65934:
	mov	ecx, DWORD PTR _cd$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR _cd$[ebp], edx
$L65933:
	cmp	DWORD PTR _cd$[ebp], 0
	je	SHORT $L65935

; 188  : 		if (cd->info->scheme == scheme)

	mov	eax, DWORD PTR _cd$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+4]
	mov	eax, DWORD PTR _scheme$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	edx, eax
	jne	SHORT $L65936

; 189  : 			return ((const TIFFCodec*) cd->info);

	mov	ecx, DWORD PTR _cd$[ebp]
	mov	eax, DWORD PTR [ecx+4]
	jmp	SHORT $L65930
$L65936:

; 190  : 	for (c = _TIFFBuiltinCODECS; c->name; c++)

	jmp	SHORT $L65934
$L65935:
	mov	DWORD PTR _c$[ebp], OFFSET FLAT:__TIFFBuiltinCODECS
	jmp	SHORT $L65938
$L65939:
	mov	edx, DWORD PTR _c$[ebp]
	add	edx, 12					; 0000000cH
	mov	DWORD PTR _c$[ebp], edx
$L65938:
	mov	eax, DWORD PTR _c$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L65940

; 191  : 		if (c->scheme == scheme)

	mov	ecx, DWORD PTR _c$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+4]
	mov	eax, DWORD PTR _scheme$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	edx, eax
	jne	SHORT $L65941

; 192  : 			return (c);

	mov	eax, DWORD PTR _c$[ebp]
	jmp	SHORT $L65930
$L65941:

; 193  : 	return ((const TIFFCodec*) 0);

	jmp	SHORT $L65939
$L65940:
	xor	eax, eax
$L65930:

; 194  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFFindCODEC ENDP
_TEXT	ENDS
PUBLIC	_TIFFRegisterCODEC
EXTRN	_strcpy:NEAR
EXTRN	__TIFFmalloc:NEAR
EXTRN	_strlen:NEAR
_DATA	SEGMENT
	ORG $+3
$SG65963 DB	'No space to register compression scheme %s', 00H
	ORG $+1
$SG65964 DB	'TIFFRegisterCODEC', 00H
_DATA	ENDS
_TEXT	SEGMENT
_scheme$ = 8
_name$ = 12
_init$ = 16
_cd$ = -4
_TIFFRegisterCODEC PROC NEAR

; 198  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 199  : 	codec_t* cd = (codec_t*)
; 200  : 	    _TIFFmalloc(sizeof (codec_t) + sizeof (TIFFCodec) + strlen(name)+1);

	mov	eax, DWORD PTR _name$[ebp]
	push	eax
	call	_strlen
	add	esp, 4
	add	eax, 21					; 00000015H
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	DWORD PTR _cd$[ebp], eax

; 201  : 
; 202  : 	if (cd != NULL) {

	cmp	DWORD PTR _cd$[ebp], 0
	je	SHORT $L65955

; 203  : 		cd->info = (TIFFCodec*) ((tidata_t) cd + sizeof (codec_t));

	mov	ecx, DWORD PTR _cd$[ebp]
	add	ecx, 8
	mov	edx, DWORD PTR _cd$[ebp]
	mov	DWORD PTR [edx+4], ecx

; 204  : 		cd->info->name = (char*)
; 205  : 		    ((tidata_t) cd->info + sizeof (TIFFCodec));

	mov	eax, DWORD PTR _cd$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	add	ecx, 12					; 0000000cH
	mov	edx, DWORD PTR _cd$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR [eax], ecx

; 206  : 		strcpy(cd->info->name, name);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _cd$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_strcpy
	add	esp, 8

; 207  : 		cd->info->scheme = scheme;

	mov	edx, DWORD PTR _cd$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	cx, WORD PTR _scheme$[ebp]
	mov	WORD PTR [eax+4], cx

; 208  : 		cd->info->init = init;

	mov	edx, DWORD PTR _cd$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	ecx, DWORD PTR _init$[ebp]
	mov	DWORD PTR [eax+8], ecx

; 209  : 		cd->next = registeredCODECS;

	mov	edx, DWORD PTR _cd$[ebp]
	mov	eax, DWORD PTR _registeredCODECS
	mov	DWORD PTR [edx], eax

; 210  : 		registeredCODECS = cd;

	mov	ecx, DWORD PTR _cd$[ebp]
	mov	DWORD PTR _registeredCODECS, ecx

; 211  : 	} else

	jmp	SHORT $L65962
$L65955:

; 212  : 		TIFFError("TIFFRegisterCODEC",
; 213  : 		    "No space to register compression scheme %s", name);

	mov	edx, DWORD PTR _name$[ebp]
	push	edx
	push	OFFSET FLAT:$SG65963
	push	OFFSET FLAT:$SG65964
	call	_TIFFError
	add	esp, 12					; 0000000cH
$L65962:

; 214  : 	return (cd->info);

	mov	eax, DWORD PTR _cd$[ebp]
	mov	eax, DWORD PTR [eax+4]

; 215  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFRegisterCODEC ENDP
_TEXT	ENDS
PUBLIC	_TIFFUnRegisterCODEC
EXTRN	__TIFFfree:NEAR
_DATA	SEGMENT
	ORG $+2
$SG65974 DB	'Cannot remove compression scheme %s; not registered', 00H
$SG65975 DB	'TIFFUnRegisterCODEC', 00H
_DATA	ENDS
_TEXT	SEGMENT
_c$ = 8
_cd$ = -4
_pcd$ = -8
_TIFFUnRegisterCODEC PROC NEAR

; 219  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 220  : 	codec_t* cd;
; 221  : 	codec_t** pcd;
; 222  : 
; 223  : 	for (pcd = &registeredCODECS; (cd = *pcd); pcd = &cd->next)

	mov	DWORD PTR _pcd$[ebp], OFFSET FLAT:_registeredCODECS
	jmp	SHORT $L65970
$L65971:
	mov	eax, DWORD PTR _cd$[ebp]
	mov	DWORD PTR _pcd$[ebp], eax
$L65970:
	mov	ecx, DWORD PTR _pcd$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR _cd$[ebp], edx
	cmp	DWORD PTR _cd$[ebp], 0
	je	SHORT $L65972

; 224  : 		if (cd->info == c) {

	mov	eax, DWORD PTR _cd$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	cmp	ecx, DWORD PTR _c$[ebp]
	jne	SHORT $L65973

; 225  : 			*pcd = cd->next;

	mov	edx, DWORD PTR _pcd$[ebp]
	mov	eax, DWORD PTR _cd$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx

; 226  : 			_TIFFfree(cd);

	mov	edx, DWORD PTR _cd$[ebp]
	push	edx
	call	__TIFFfree
	add	esp, 4

; 227  : 			return;

	jmp	SHORT $L65967
$L65973:

; 229  : 	TIFFError("TIFFUnRegisterCODEC",

	jmp	SHORT $L65971
$L65972:

; 230  : 	    "Cannot remove compression scheme %s; not registered", c->name);

	mov	eax, DWORD PTR _c$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG65974
	push	OFFSET FLAT:$SG65975
	call	_TIFFError
	add	esp, 12					; 0000000cH
$L65967:

; 231  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFUnRegisterCODEC ENDP
_TEXT	ENDS
END
