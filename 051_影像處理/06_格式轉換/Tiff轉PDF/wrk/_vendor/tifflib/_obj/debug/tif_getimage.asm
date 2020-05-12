	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_getimage.c
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
_photoTag DB	'PhotometricInterpretation', 00H
CONST	ENDS
PUBLIC	_TIFFRGBAImageOK
EXTRN	_sprintf:NEAR
EXTRN	_TIFFGetField:NEAR
_DATA	SEGMENT
$SG65828 DB	'Sorry, can not handle images with %d-bit samples', 00H
	ORG $+3
$SG65837 DB	'Missing needed %s tag', 00H
	ORG $+2
$SG65844 DB	'Samples/pixel', 00H
	ORG $+2
$SG65845 DB	'Sorry, can not handle contiguous data with %s=%d, and %s'
	DB	'=%d and Bits/Sample=%d', 00H
	ORG $+1
$SG65848 DB	'Planarconfiguration', 00H
$SG65849 DB	'Sorry, can not handle YCbCr images with %s=%d', 00H
	ORG $+2
$SG65852 DB	'Color channels', 00H
	ORG $+1
$SG65853 DB	'Sorry, can not handle RGB image with %s=%d', 00H
	ORG $+1
$SG65856 DB	'InkSet', 00H
	ORG $+1
$SG65857 DB	'Sorry, can not handle separated image with %s=%d', 00H
	ORG $+3
$SG65859 DB	'Samples/pixel', 00H
	ORG $+2
$SG65860 DB	'Sorry, can not handle separated image with %s=%d', 00H
	ORG $+3
$SG65863 DB	'Compression', 00H
$SG65864 DB	'Sorry, LogL data must have %s=%d', 00H
	ORG $+3
$SG65867 DB	'Compression', 00H
$SG65868 DB	'Sorry, LogLuv data must have %s=%d or %d', 00H
	ORG $+3
$SG65870 DB	'Planarconfiguration', 00H
$SG65871 DB	'Sorry, can not handle LogLuv images with %s=%d', 00H
	ORG $+1
$SG65873 DB	'Sorry, can not handle image with %s=%d', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_emsg$ = 12
_td$ = -12
_photometric$ = -8
_colorchannels$ = -4
_TIFFRGBAImageOK PROC NEAR

; 53   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 24					; 00000018H

; 54   :     TIFFDirectory* td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 55   :     uint16 photometric;
; 56   :     int colorchannels;
; 57   : 
; 58   :     switch (td->td_bitspersample) {

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+40]
	mov	DWORD PTR -16+[ebp], edx
	mov	eax, DWORD PTR -16+[ebp]
	sub	eax, 1
	mov	DWORD PTR -16+[ebp], eax
	cmp	DWORD PTR -16+[ebp], 15			; 0000000fH
	ja	SHORT $L65827
	mov	edx, DWORD PTR -16+[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR $L68763[edx]
	jmp	DWORD PTR $L68764[ecx*4]
$L65826:

; 59   :     case 1: case 2: case 4:
; 60   :     case 8: case 16:
; 61   : 	break;

	jmp	SHORT $L65823
$L65827:

; 62   :     default:
; 63   : 	sprintf(emsg, "Sorry, can not handle images with %d-bit samples",
; 64   : 	    td->td_bitspersample);

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+40]
	push	ecx
	push	OFFSET FLAT:$SG65828
	mov	edx, DWORD PTR _emsg$[ebp]
	push	edx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 65   : 	return (0);

	xor	eax, eax
	jmp	$L65818
$L65823:

; 67   :     colorchannels = td->td_samplesperpixel - td->td_extrasamples;

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+54]
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+120]
	sub	ecx, eax
	mov	DWORD PTR _colorchannels$[ebp], ecx

; 68   :     if (!TIFFGetField(tif, TIFFTAG_PHOTOMETRIC, &photometric)) {

	lea	ecx, DWORD PTR _photometric$[ebp]
	push	ecx
	push	262					; 00000106H
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFGetField
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65831

; 69   : 	switch (colorchannels) {

	mov	eax, DWORD PTR _colorchannels$[ebp]
	mov	DWORD PTR -20+[ebp], eax
	cmp	DWORD PTR -20+[ebp], 1
	je	SHORT $L65834
	cmp	DWORD PTR -20+[ebp], 3
	je	SHORT $L65835
	jmp	SHORT $L65836
$L65834:

; 70   : 	case 1:
; 71   : 	    photometric = PHOTOMETRIC_MINISBLACK;

	mov	WORD PTR _photometric$[ebp], 1

; 72   : 	    break;

	jmp	SHORT $L65831
$L65835:

; 73   : 	case 3:
; 74   : 	    photometric = PHOTOMETRIC_RGB;

	mov	WORD PTR _photometric$[ebp], 2

; 75   : 	    break;

	jmp	SHORT $L65831
$L65836:

; 76   : 	default:
; 77   : 	    sprintf(emsg, "Missing needed %s tag", photoTag);

	push	OFFSET FLAT:_photoTag
	push	OFFSET FLAT:$SG65837
	mov	ecx, DWORD PTR _emsg$[ebp]
	push	ecx
	call	_sprintf
	add	esp, 12					; 0000000cH

; 78   : 	    return (0);

	xor	eax, eax
	jmp	$L65818
$L65831:

; 81   :     switch (photometric) {

	mov	edx, DWORD PTR _photometric$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	DWORD PTR -24+[ebp], edx
	cmp	DWORD PTR -24+[ebp], 32844		; 0000804cH
	jg	SHORT $L68762
	cmp	DWORD PTR -24+[ebp], 32844		; 0000804cH
	je	$L65861
	cmp	DWORD PTR -24+[ebp], 6
	ja	$L65872
	mov	eax, DWORD PTR -24+[ebp]
	jmp	DWORD PTR $L68765[eax*4]
$L68762:
	cmp	DWORD PTR -24+[ebp], 32845		; 0000804dH
	je	$L65865
	jmp	$L65872
$L65842:

; 82   :     case PHOTOMETRIC_MINISWHITE:
; 83   :     case PHOTOMETRIC_MINISBLACK:
; 84   :     case PHOTOMETRIC_PALETTE:
; 85   : 	if (td->td_planarconfig == PLANARCONFIG_CONTIG 
; 86   :             && td->td_samplesperpixel != 1
; 87   :             && td->td_bitspersample < 8 ) {

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+90]
	cmp	edx, 1
	jne	SHORT $L65843
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+54]
	cmp	ecx, 1
	je	SHORT $L65843
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+40]
	cmp	eax, 8
	jge	SHORT $L65843

; 88   : 	    sprintf(emsg,
; 89   :                     "Sorry, can not handle contiguous data with %s=%d, "
; 90   :                     "and %s=%d and Bits/Sample=%d",
; 91   :                     photoTag, photometric,
; 92   :                     "Samples/pixel", td->td_samplesperpixel,
; 93   :                     td->td_bitspersample);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+40]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+54]
	push	ecx
	push	OFFSET FLAT:$SG65844
	mov	edx, DWORD PTR _photometric$[ebp]
	and	edx, 65535				; 0000ffffH
	push	edx
	push	OFFSET FLAT:_photoTag
	push	OFFSET FLAT:$SG65845
	mov	eax, DWORD PTR _emsg$[ebp]
	push	eax
	call	_sprintf
	add	esp, 28					; 0000001cH

; 94   : 	    return (0);

	xor	eax, eax
	jmp	$L65818
$L65843:

; 96   :         /*
; 97   :         ** We should likely validate that any extra samples are either
; 98   :         ** to be ignored, or are alpha, and if alpha we should try to use
; 99   :         ** them.  But for now we won't bother with this. 
; 100  :         */
; 101  : 	break;

	jmp	$L65839
$L65846:

; 102  :     case PHOTOMETRIC_YCBCR:
; 103  : 	if (td->td_planarconfig != PLANARCONFIG_CONTIG) {

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+90]
	cmp	edx, 1
	je	SHORT $L65847

; 104  : 	    sprintf(emsg, "Sorry, can not handle YCbCr images with %s=%d",
; 105  : 		"Planarconfiguration", td->td_planarconfig);

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+90]
	push	ecx
	push	OFFSET FLAT:$SG65848
	push	OFFSET FLAT:$SG65849
	mov	edx, DWORD PTR _emsg$[ebp]
	push	edx
	call	_sprintf
	add	esp, 16					; 00000010H

; 106  : 	    return (0);

	xor	eax, eax
	jmp	$L65818
$L65847:

; 108  : 	break;

	jmp	$L65839
$L65850:

; 109  :     case PHOTOMETRIC_RGB: 
; 110  : 	if (colorchannels < 3) {

	cmp	DWORD PTR _colorchannels$[ebp], 3
	jge	SHORT $L65851

; 111  : 	    sprintf(emsg, "Sorry, can not handle RGB image with %s=%d",
; 112  : 		"Color channels", colorchannels);

	mov	eax, DWORD PTR _colorchannels$[ebp]
	push	eax
	push	OFFSET FLAT:$SG65852
	push	OFFSET FLAT:$SG65853
	mov	ecx, DWORD PTR _emsg$[ebp]
	push	ecx
	call	_sprintf
	add	esp, 16					; 00000010H

; 113  : 	    return (0);

	xor	eax, eax
	jmp	$L65818
$L65851:

; 115  : 	break;

	jmp	$L65839
$L65854:

; 116  : #ifdef CMYK_SUPPORT
; 117  :     case PHOTOMETRIC_SEPARATED:
; 118  : 	if (td->td_inkset != INKSET_CMYK) {

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+236]
	cmp	eax, 1
	je	SHORT $L65855

; 119  : 	    sprintf(emsg, "Sorry, can not handle separated image with %s=%d",
; 120  : 		"InkSet", td->td_inkset);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+236]
	push	edx
	push	OFFSET FLAT:$SG65856
	push	OFFSET FLAT:$SG65857
	mov	eax, DWORD PTR _emsg$[ebp]
	push	eax
	call	_sprintf
	add	esp, 16					; 00000010H

; 121  : 	    return (0);

	xor	eax, eax
	jmp	$L65818
$L65855:

; 123  : 	if (td->td_samplesperpixel < 4) {

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+54]
	cmp	edx, 4
	jge	SHORT $L65858

; 124  : 	    sprintf(emsg, "Sorry, can not handle separated image with %s=%d",
; 125  : 		"Samples/pixel", td->td_samplesperpixel);

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+54]
	push	ecx
	push	OFFSET FLAT:$SG65859
	push	OFFSET FLAT:$SG65860
	mov	edx, DWORD PTR _emsg$[ebp]
	push	edx
	call	_sprintf
	add	esp, 16					; 00000010H

; 126  : 	    return (0);

	xor	eax, eax
	jmp	$L65818
$L65858:

; 128  : 	break;

	jmp	$L65839
$L65861:

; 129  : #endif
; 130  :     case PHOTOMETRIC_LOGL:
; 131  : 	if (td->td_compression != COMPRESSION_SGILOG) {

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+44]
	cmp	ecx, 34676				; 00008774H
	je	SHORT $L65862

; 132  : 	    sprintf(emsg, "Sorry, LogL data must have %s=%d",
; 133  : 		"Compression", COMPRESSION_SGILOG);

	push	34676					; 00008774H
	push	OFFSET FLAT:$SG65863
	push	OFFSET FLAT:$SG65864
	mov	edx, DWORD PTR _emsg$[ebp]
	push	edx
	call	_sprintf
	add	esp, 16					; 00000010H

; 134  : 	    return (0);

	xor	eax, eax
	jmp	$L65818
$L65862:

; 136  : 	break;

	jmp	$L65839
$L65865:

; 137  :     case PHOTOMETRIC_LOGLUV:
; 138  : 	if (td->td_compression != COMPRESSION_SGILOG &&
; 139  : 		td->td_compression != COMPRESSION_SGILOG24) {

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+44]
	cmp	ecx, 34676				; 00008774H
	je	SHORT $L65866
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+44]
	cmp	eax, 34677				; 00008775H
	je	SHORT $L65866

; 140  : 	    sprintf(emsg, "Sorry, LogLuv data must have %s=%d or %d",
; 141  : 		"Compression", COMPRESSION_SGILOG, COMPRESSION_SGILOG24);

	push	34677					; 00008775H
	push	34676					; 00008774H
	push	OFFSET FLAT:$SG65867
	push	OFFSET FLAT:$SG65868
	mov	ecx, DWORD PTR _emsg$[ebp]
	push	ecx
	call	_sprintf
	add	esp, 20					; 00000014H

; 142  : 	    return (0);

	xor	eax, eax
	jmp	SHORT $L65818
$L65866:

; 144  : 	if (td->td_planarconfig != PLANARCONFIG_CONTIG) {

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+90]
	cmp	eax, 1
	je	SHORT $L65869

; 145  : 	    sprintf(emsg, "Sorry, can not handle LogLuv images with %s=%d",
; 146  : 		"Planarconfiguration", td->td_planarconfig);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+90]
	push	edx
	push	OFFSET FLAT:$SG65870
	push	OFFSET FLAT:$SG65871
	mov	eax, DWORD PTR _emsg$[ebp]
	push	eax
	call	_sprintf
	add	esp, 16					; 00000010H

; 147  : 	    return (0);

	xor	eax, eax
	jmp	SHORT $L65818
$L65869:

; 149  : 	break;

	jmp	SHORT $L65839
$L65872:

; 150  :     default:
; 151  : 	sprintf(emsg, "Sorry, can not handle image with %s=%d",
; 152  : 	    photoTag, photometric);

	mov	ecx, DWORD PTR _photometric$[ebp]
	and	ecx, 65535				; 0000ffffH
	push	ecx
	push	OFFSET FLAT:_photoTag
	push	OFFSET FLAT:$SG65873
	mov	edx, DWORD PTR _emsg$[ebp]
	push	edx
	call	_sprintf
	add	esp, 16					; 00000010H

; 153  : 	return (0);

	xor	eax, eax
	jmp	SHORT $L65818
$L65839:

; 155  :     return (1);

	mov	eax, 1
$L65818:

; 156  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68764:
	DD	$L65826
	DD	$L65827
$L68763:
	DB	0
	DB	0
	DB	1
	DB	0
	DB	1
	DB	1
	DB	1
	DB	0
	DB	1
	DB	1
	DB	1
	DB	1
	DB	1
	DB	1
	DB	1
	DB	0
$L68765:
	DD	$L65842
	DD	$L65842
	DD	$L65850
	DD	$L65842
	DD	$L65872
	DD	$L65854
	DD	$L65846
_TIFFRGBAImageOK ENDP
_TEXT	ENDS
PUBLIC	_TIFFRGBAImageEnd
EXTRN	__TIFFfree:NEAR
_TEXT	SEGMENT
_img$ = 8
_TIFFRGBAImageEnd PROC NEAR

; 160  : {

	push	ebp
	mov	ebp, esp

; 161  :     if (img->Map)

	mov	eax, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [eax+52], 0
	je	SHORT $L65877

; 162  : 	_TIFFfree(img->Map), img->Map = NULL;

	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR [ecx+52]
	push	edx
	call	__TIFFfree
	add	esp, 4
	mov	eax, DWORD PTR _img$[ebp]
	mov	DWORD PTR [eax+52], 0
$L65877:

; 163  :     if (img->BWmap)

	mov	ecx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [ecx+56], 0
	je	SHORT $L65879

; 164  : 	_TIFFfree(img->BWmap), img->BWmap = NULL;

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx+56]
	push	eax
	call	__TIFFfree
	add	esp, 4
	mov	ecx, DWORD PTR _img$[ebp]
	mov	DWORD PTR [ecx+56], 0
$L65879:

; 165  :     if (img->PALmap)

	mov	edx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [edx+60], 0
	je	SHORT $L65881

; 166  : 	_TIFFfree(img->PALmap), img->PALmap = NULL;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	push	ecx
	call	__TIFFfree
	add	esp, 4
	mov	edx, DWORD PTR _img$[ebp]
	mov	DWORD PTR [edx+60], 0
$L65881:

; 167  :     if (img->ycbcr)

	mov	eax, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [eax+64], 0
	je	SHORT $L65883

; 168  : 	_TIFFfree(img->ycbcr), img->ycbcr = NULL;

	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR [ecx+64]
	push	edx
	call	__TIFFfree
	add	esp, 4
	mov	eax, DWORD PTR _img$[ebp]
	mov	DWORD PTR [eax+64], 0
$L65883:

; 169  : 
; 170  :     if( img->redcmap ) {

	mov	ecx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [ecx+32], 0
	je	SHORT $L65885

; 171  :         _TIFFfree( img->redcmap );

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx+32]
	push	eax
	call	__TIFFfree
	add	esp, 4

; 172  :         _TIFFfree( img->greencmap );

	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR [ecx+36]
	push	edx
	call	__TIFFfree
	add	esp, 4

; 173  :         _TIFFfree( img->bluecmap );

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	push	ecx
	call	__TIFFfree
	add	esp, 4
$L65885:

; 175  : }

	pop	ebp
	ret	0
_TIFFRGBAImageEnd ENDP
_TEXT	ENDS
PUBLIC	_TIFFRGBAImageBegin
EXTRN	_memcpy:NEAR
EXTRN	__TIFFmalloc:NEAR
EXTRN	_TIFFGetFieldDefaulted:NEAR
EXTRN	_TIFFIsTiled:NEAR
EXTRN	_TIFFSetField:NEAR
EXTRN	_TIFFFileName:NEAR
EXTRN	_TIFFError:NEAR
_DATA	SEGMENT
	ORG $+1
$SG65918 DB	'Sorry, can not image with %d-bit samples', 00H
	ORG $+3
$SG65935 DB	'Missing needed %s tag', 00H
	ORG $+2
$SG65942 DB	'Missing required "Colormap" tag', 00H
$SG65951 DB	'Out of memory for colormap copy', 00H
$SG65954 DB	'Samples/pixel', 00H
	ORG $+2
$SG65955 DB	'Sorry, can not handle contiguous data with %s=%d, and %s'
	DB	'=%d and Bits/Sample=%d', 00H
	ORG $+1
$SG65958 DB	'Planarconfiguration', 00H
$SG65959 DB	'Sorry, can not handle YCbCr images with %s=%d', 00H
	ORG $+2
$SG65969 DB	'Color channels', 00H
	ORG $+1
$SG65970 DB	'Sorry, can not handle RGB image with %s=%d', 00H
	ORG $+1
$SG65974 DB	'InkSet', 00H
	ORG $+1
$SG65975 DB	'Sorry, can not handle separated image with %s=%d', 00H
	ORG $+3
$SG65977 DB	'Samples/pixel', 00H
	ORG $+2
$SG65978 DB	'Sorry, can not handle separated image with %s=%d', 00H
	ORG $+3
$SG65981 DB	'Compression', 00H
$SG65982 DB	'Sorry, LogL data must have %s=%d', 00H
	ORG $+3
$SG65985 DB	'Compression', 00H
$SG65986 DB	'Sorry, LogLuv data must have %s=%d or %d', 00H
	ORG $+3
$SG65988 DB	'Planarconfiguration', 00H
$SG65989 DB	'Sorry, can not handle LogLuv images with %s=%d', 00H
	ORG $+1
$SG65991 DB	'Sorry, can not handle image with %s=%d', 00H
_DATA	ENDS
_TEXT	SEGMENT
_img$ = 8
_tif$ = 12
_stop$ = 16
_emsg$ = 20
_sampleinfo$ = -32
_extrasamples$ = -4
_planarconfig$ = -36
_compress$ = -28
_colorchannels$ = -12
_red_orig$ = -16
_green_orig$ = -20
_blue_orig$ = -8
_n_color$ = -24
_inkset$65972 = -40
_TIFFRGBAImageBegin PROC NEAR

; 190  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H

; 191  :     uint16* sampleinfo;
; 192  :     uint16 extrasamples;
; 193  :     uint16 planarconfig;
; 194  :     uint16 compress;
; 195  :     int colorchannels;
; 196  :     uint16	*red_orig, *green_orig, *blue_orig;
; 197  :     int		n_color;
; 198  : 
; 199  :     /* Initialize to normal values */
; 200  :     img->row_offset = 0;

	mov	eax, DWORD PTR _img$[ebp]
	mov	DWORD PTR [eax+68], 0

; 201  :     img->col_offset = 0;

	mov	ecx, DWORD PTR _img$[ebp]
	mov	DWORD PTR [ecx+72], 0

; 202  :     img->redcmap = NULL;

	mov	edx, DWORD PTR _img$[ebp]
	mov	DWORD PTR [edx+32], 0

; 203  :     img->greencmap = NULL;

	mov	eax, DWORD PTR _img$[ebp]
	mov	DWORD PTR [eax+36], 0

; 204  :     img->bluecmap = NULL;

	mov	ecx, DWORD PTR _img$[ebp]
	mov	DWORD PTR [ecx+40], 0

; 205  :     
; 206  :     img->tif = tif;

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx], eax

; 207  :     img->stoponerr = stop;

	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR _stop$[ebp]
	mov	DWORD PTR [ecx+4], edx

; 208  :     TIFFGetFieldDefaulted(tif, TIFFTAG_BITSPERSAMPLE, &img->bitspersample);

	mov	eax, DWORD PTR _img$[ebp]
	add	eax, 24					; 00000018H
	push	eax
	push	258					; 00000102H
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFGetFieldDefaulted
	add	esp, 12					; 0000000cH

; 209  :     switch (img->bitspersample) {

	mov	edx, DWORD PTR _img$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+24]
	mov	DWORD PTR -44+[ebp], eax
	mov	ecx, DWORD PTR -44+[ebp]
	sub	ecx, 1
	mov	DWORD PTR -44+[ebp], ecx
	cmp	DWORD PTR -44+[ebp], 15			; 0000000fH
	ja	SHORT $L65917
	mov	eax, DWORD PTR -44+[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR $L68775[eax]
	jmp	DWORD PTR $L68776[edx*4]
$L65916:

; 210  :     case 1: case 2: case 4:
; 211  :     case 8: case 16:
; 212  : 	break;

	jmp	SHORT $L65913
$L65917:

; 213  :     default:
; 214  : 	sprintf(emsg, "Sorry, can not image with %d-bit samples",
; 215  : 	    img->bitspersample);

	mov	ecx, DWORD PTR _img$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+24]
	push	edx
	push	OFFSET FLAT:$SG65918
	mov	eax, DWORD PTR _emsg$[ebp]
	push	eax
	call	_sprintf
	add	esp, 12					; 0000000cH

; 216  : 	return (0);

	xor	eax, eax
	jmp	$L65899
$L65913:

; 218  :     img->alpha = 0;

	mov	ecx, DWORD PTR _img$[ebp]
	mov	DWORD PTR [ecx+12], 0

; 219  :     TIFFGetFieldDefaulted(tif, TIFFTAG_SAMPLESPERPIXEL, &img->samplesperpixel);

	mov	edx, DWORD PTR _img$[ebp]
	add	edx, 26					; 0000001aH
	push	edx
	push	277					; 00000115H
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetFieldDefaulted
	add	esp, 12					; 0000000cH

; 220  :     TIFFGetFieldDefaulted(tif, TIFFTAG_EXTRASAMPLES,
; 221  : 	&extrasamples, &sampleinfo);

	lea	ecx, DWORD PTR _sampleinfo$[ebp]
	push	ecx
	lea	edx, DWORD PTR _extrasamples$[ebp]
	push	edx
	push	338					; 00000152H
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetFieldDefaulted
	add	esp, 16					; 00000010H

; 222  :     if (extrasamples == 1)

	mov	ecx, DWORD PTR _extrasamples$[ebp]
	and	ecx, 65535				; 0000ffffH
	cmp	ecx, 1
	jne	SHORT $L65921

; 223  : 	switch (sampleinfo[0]) {

	mov	edx, DWORD PTR _sampleinfo$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	mov	DWORD PTR -48+[ebp], eax
	cmp	DWORD PTR -48+[ebp], 0
	jle	SHORT $L65921
	cmp	DWORD PTR -48+[ebp], 2
	jle	SHORT $L65924
	jmp	SHORT $L65921
$L65924:

; 224  : 	case EXTRASAMPLE_ASSOCALPHA:	/* data is pre-multiplied */
; 225  : 	case EXTRASAMPLE_UNASSALPHA:	/* data is not pre-multiplied */
; 226  : 	    img->alpha = sampleinfo[0];

	mov	ecx, DWORD PTR _sampleinfo$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx]
	mov	eax, DWORD PTR _img$[ebp]
	mov	DWORD PTR [eax+12], edx
$L65921:

; 229  :     colorchannels = img->samplesperpixel - extrasamples;

	mov	ecx, DWORD PTR _img$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+26]
	mov	eax, DWORD PTR _extrasamples$[ebp]
	and	eax, 65535				; 0000ffffH
	sub	edx, eax
	mov	DWORD PTR _colorchannels$[ebp], edx

; 230  :     TIFFGetFieldDefaulted(tif, TIFFTAG_COMPRESSION, &compress);

	lea	ecx, DWORD PTR _compress$[ebp]
	push	ecx
	push	259					; 00000103H
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFGetFieldDefaulted
	add	esp, 12					; 0000000cH

; 231  :     TIFFGetFieldDefaulted(tif, TIFFTAG_PLANARCONFIG, &planarconfig);

	lea	eax, DWORD PTR _planarconfig$[ebp]
	push	eax
	push	284					; 0000011cH
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFGetFieldDefaulted
	add	esp, 12					; 0000000cH

; 232  :     if (!TIFFGetField(tif, TIFFTAG_PHOTOMETRIC, &img->photometric)) {

	mov	edx, DWORD PTR _img$[ebp]
	add	edx, 30					; 0000001eH
	push	edx
	push	262					; 00000106H
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetField
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65927

; 233  : 	switch (colorchannels) {

	mov	ecx, DWORD PTR _colorchannels$[ebp]
	mov	DWORD PTR -52+[ebp], ecx
	cmp	DWORD PTR -52+[ebp], 1
	je	SHORT $L65930
	cmp	DWORD PTR -52+[ebp], 3
	je	SHORT $L65933
	jmp	SHORT $L65934
$L65930:

; 234  : 	case 1:
; 235  : 	    if (isCCITTCompression(tif))

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_isCCITTCompression
	add	esp, 4
	test	eax, eax
	je	SHORT $L65931

; 236  : 		img->photometric = PHOTOMETRIC_MINISWHITE;

	mov	eax, DWORD PTR _img$[ebp]
	mov	WORD PTR [eax+30], 0

; 237  : 	    else

	jmp	SHORT $L65932
$L65931:

; 238  : 		img->photometric = PHOTOMETRIC_MINISBLACK;

	mov	ecx, DWORD PTR _img$[ebp]
	mov	WORD PTR [ecx+30], 1
$L65932:

; 239  : 	    break;

	jmp	SHORT $L65927
$L65933:

; 240  : 	case 3:
; 241  : 	    img->photometric = PHOTOMETRIC_RGB;

	mov	edx, DWORD PTR _img$[ebp]
	mov	WORD PTR [edx+30], 2

; 242  : 	    break;

	jmp	SHORT $L65927
$L65934:

; 243  : 	default:
; 244  : 	    sprintf(emsg, "Missing needed %s tag", photoTag);

	push	OFFSET FLAT:_photoTag
	push	OFFSET FLAT:$SG65935
	mov	eax, DWORD PTR _emsg$[ebp]
	push	eax
	call	_sprintf
	add	esp, 12					; 0000000cH

; 245  : 	    return (0);

	xor	eax, eax
	jmp	$L65899
$L65927:

; 248  :     switch (img->photometric) {

	mov	ecx, DWORD PTR _img$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+30]
	mov	DWORD PTR -56+[ebp], edx
	cmp	DWORD PTR -56+[ebp], 32844		; 0000804cH
	jg	SHORT $L68768
	cmp	DWORD PTR -56+[ebp], 32844		; 0000804cH
	je	$L65979
	cmp	DWORD PTR -56+[ebp], 6
	ja	$L65990
	mov	eax, DWORD PTR -56+[ebp]
	jmp	DWORD PTR $L68777[eax*4]
$L68768:
	cmp	DWORD PTR -56+[ebp], 32845		; 0000804dH
	je	$L65983
	jmp	$L65990
$L65940:

; 249  :     case PHOTOMETRIC_PALETTE:
; 250  : 	if (!TIFFGetField(tif, TIFFTAG_COLORMAP,
; 251  : 	    &red_orig, &green_orig, &blue_orig)) {

	lea	ecx, DWORD PTR _blue_orig$[ebp]
	push	ecx
	lea	edx, DWORD PTR _green_orig$[ebp]
	push	edx
	lea	eax, DWORD PTR _red_orig$[ebp]
	push	eax
	push	320					; 00000140H
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFGetField
	add	esp, 20					; 00000014H
	test	eax, eax
	jne	SHORT $L65941

; 252  : 	    TIFFError(TIFFFileName(tif), "Missing required \"Colormap\" tag");

	push	OFFSET FLAT:$SG65942
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 253  : 	    return (0);

	xor	eax, eax
	jmp	$L65899
$L65941:

; 255  : 
; 256  :         /* copy the colormaps so we can modify them */
; 257  :         n_color = (1L << img->bitspersample);

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+24]
	mov	edx, 1
	shl	edx, cl
	mov	DWORD PTR _n_color$[ebp], edx

; 258  :         img->redcmap = (uint16 *) _TIFFmalloc(sizeof(uint16)*n_color);

	mov	eax, DWORD PTR _n_color$[ebp]
	shl	eax, 1
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	ecx, DWORD PTR _img$[ebp]
	mov	DWORD PTR [ecx+32], eax

; 259  :         img->greencmap = (uint16 *) _TIFFmalloc(sizeof(uint16)*n_color);

	mov	edx, DWORD PTR _n_color$[ebp]
	shl	edx, 1
	push	edx
	call	__TIFFmalloc
	add	esp, 4
	mov	ecx, DWORD PTR _img$[ebp]
	mov	DWORD PTR [ecx+36], eax

; 260  :         img->bluecmap = (uint16 *) _TIFFmalloc(sizeof(uint16)*n_color);

	mov	edx, DWORD PTR _n_color$[ebp]
	shl	edx, 1
	push	edx
	call	__TIFFmalloc
	add	esp, 4
	mov	ecx, DWORD PTR _img$[ebp]
	mov	DWORD PTR [ecx+40], eax

; 261  :         if( !img->redcmap || !img->greencmap || !img->bluecmap ) {

	mov	edx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [edx+32], 0
	je	SHORT $L65950
	mov	eax, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [eax+36], 0
	je	SHORT $L65950
	mov	ecx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [ecx+40], 0
	jne	SHORT $L65949
$L65950:

; 262  : 	    TIFFError(TIFFFileName(tif), "Out of memory for colormap copy");

	push	OFFSET FLAT:$SG65951
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 263  : 	    return (0);

	xor	eax, eax
	jmp	$L65899
$L65949:

; 265  : 
; 266  :         memcpy( img->redcmap, red_orig, n_color * 2 );

	mov	eax, DWORD PTR _n_color$[ebp]
	shl	eax, 1
	push	eax
	mov	ecx, DWORD PTR _red_orig$[ebp]
	push	ecx
	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx+32]
	push	eax
	call	_memcpy
	add	esp, 12					; 0000000cH

; 267  :         memcpy( img->greencmap, green_orig, n_color * 2 );

	mov	ecx, DWORD PTR _n_color$[ebp]
	shl	ecx, 1
	push	ecx
	mov	edx, DWORD PTR _green_orig$[ebp]
	push	edx
	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+36]
	push	ecx
	call	_memcpy
	add	esp, 12					; 0000000cH

; 268  :         memcpy( img->bluecmap, blue_orig, n_color * 2 );

	mov	edx, DWORD PTR _n_color$[ebp]
	shl	edx, 1
	push	edx
	mov	eax, DWORD PTR _blue_orig$[ebp]
	push	eax
	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	push	edx
	call	_memcpy
	add	esp, 12					; 0000000cH
$L65952:

; 269  :         
; 270  : 	/* fall thru... */
; 271  :     case PHOTOMETRIC_MINISWHITE:
; 272  :     case PHOTOMETRIC_MINISBLACK:
; 273  : 	if (planarconfig == PLANARCONFIG_CONTIG 
; 274  :             && img->samplesperpixel != 1
; 275  :             && img->bitspersample < 8 ) {

	mov	eax, DWORD PTR _planarconfig$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 1
	jne	SHORT $L65953
	mov	ecx, DWORD PTR _img$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+26]
	cmp	edx, 1
	je	SHORT $L65953
	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+24]
	cmp	ecx, 8
	jge	SHORT $L65953

; 276  : 	    sprintf(emsg,
; 277  :                     "Sorry, can not handle contiguous data with %s=%d, "
; 278  :                     "and %s=%d and Bits/Sample=%d",
; 279  :                     photoTag, img->photometric,
; 280  :                     "Samples/pixel", img->samplesperpixel,
; 281  :                     img->bitspersample);

	mov	edx, DWORD PTR _img$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+24]
	push	eax
	mov	ecx, DWORD PTR _img$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+26]
	push	edx
	push	OFFSET FLAT:$SG65954
	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+30]
	push	ecx
	push	OFFSET FLAT:_photoTag
	push	OFFSET FLAT:$SG65955
	mov	edx, DWORD PTR _emsg$[ebp]
	push	edx
	call	_sprintf
	add	esp, 28					; 0000001cH

; 282  : 	    return (0);

	xor	eax, eax
	jmp	$L65899
$L65953:

; 284  : 	break;

	jmp	$L65937
$L65956:

; 285  :     case PHOTOMETRIC_YCBCR:
; 286  : 	if (planarconfig != PLANARCONFIG_CONTIG) {

	mov	eax, DWORD PTR _planarconfig$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 1
	je	SHORT $L65957

; 287  : 	    sprintf(emsg, "Sorry, can not handle YCbCr images with %s=%d",
; 288  : 		"Planarconfiguration", planarconfig);

	mov	ecx, DWORD PTR _planarconfig$[ebp]
	and	ecx, 65535				; 0000ffffH
	push	ecx
	push	OFFSET FLAT:$SG65958
	push	OFFSET FLAT:$SG65959
	mov	edx, DWORD PTR _emsg$[ebp]
	push	edx
	call	_sprintf
	add	esp, 16					; 00000010H

; 289  : 	    return (0);

	xor	eax, eax
	jmp	$L65899
$L65957:

; 291  : 	/* It would probably be nice to have a reality check here. */
; 292  : 	if (planarconfig == PLANARCONFIG_CONTIG)

	mov	eax, DWORD PTR _planarconfig$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 1
	jne	SHORT $L65962

; 293  : 	    /* can rely on libjpeg to convert to RGB */
; 294  : 	    /* XXX should restore current state on exit */
; 295  : 	    switch (compress) {

	mov	ecx, DWORD PTR _compress$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	DWORD PTR -60+[ebp], ecx
	cmp	DWORD PTR -60+[ebp], 6
	jl	SHORT $L65966
	cmp	DWORD PTR -60+[ebp], 7
	jle	SHORT $L65965
	jmp	SHORT $L65966
$L65965:

; 296  : 		case COMPRESSION_OJPEG:
; 297  : 		case COMPRESSION_JPEG:
; 298  : 		    TIFFSetField(tif, TIFFTAG_JPEGCOLORMODE, JPEGCOLORMODE_RGB);

	push	1
	push	65538					; 00010002H
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFSetField
	add	esp, 12					; 0000000cH

; 299  : 		    img->photometric = PHOTOMETRIC_RGB;

	mov	eax, DWORD PTR _img$[ebp]
	mov	WORD PTR [eax+30], 2
$L65966:
$L65962:

; 306  : 	break;

	jmp	$L65937
$L65967:

; 307  :     case PHOTOMETRIC_RGB: 
; 308  : 	if (colorchannels < 3) {

	cmp	DWORD PTR _colorchannels$[ebp], 3
	jge	SHORT $L65968

; 309  : 	    sprintf(emsg, "Sorry, can not handle RGB image with %s=%d",
; 310  : 		"Color channels", colorchannels);

	mov	ecx, DWORD PTR _colorchannels$[ebp]
	push	ecx
	push	OFFSET FLAT:$SG65969
	push	OFFSET FLAT:$SG65970
	mov	edx, DWORD PTR _emsg$[ebp]
	push	edx
	call	_sprintf
	add	esp, 16					; 00000010H

; 311  : 	    return (0);

	xor	eax, eax
	jmp	$L65899
$L65968:

; 313  : 	break;

	jmp	$L65937
$L65971:

; 315  : 	uint16 inkset;
; 316  : 	TIFFGetFieldDefaulted(tif, TIFFTAG_INKSET, &inkset);

	lea	eax, DWORD PTR _inkset$65972[ebp]
	push	eax
	push	332					; 0000014cH
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFGetFieldDefaulted
	add	esp, 12					; 0000000cH

; 317  : 	if (inkset != INKSET_CMYK) {

	mov	edx, DWORD PTR _inkset$65972[ebp]
	and	edx, 65535				; 0000ffffH
	cmp	edx, 1
	je	SHORT $L65973

; 318  : 	    sprintf(emsg, "Sorry, can not handle separated image with %s=%d",
; 319  : 		"InkSet", inkset);

	mov	eax, DWORD PTR _inkset$65972[ebp]
	and	eax, 65535				; 0000ffffH
	push	eax
	push	OFFSET FLAT:$SG65974
	push	OFFSET FLAT:$SG65975
	mov	ecx, DWORD PTR _emsg$[ebp]
	push	ecx
	call	_sprintf
	add	esp, 16					; 00000010H

; 320  : 	    return (0);

	xor	eax, eax
	jmp	$L65899
$L65973:

; 322  : 	if (img->samplesperpixel < 4) {

	mov	edx, DWORD PTR _img$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+26]
	cmp	eax, 4
	jge	SHORT $L65976

; 323  : 	    sprintf(emsg, "Sorry, can not handle separated image with %s=%d",
; 324  : 		"Samples/pixel", img->samplesperpixel);

	mov	ecx, DWORD PTR _img$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+26]
	push	edx
	push	OFFSET FLAT:$SG65977
	push	OFFSET FLAT:$SG65978
	mov	eax, DWORD PTR _emsg$[ebp]
	push	eax
	call	_sprintf
	add	esp, 16					; 00000010H

; 325  : 	    return (0);

	xor	eax, eax
	jmp	$L65899
$L65976:

; 327  : 	break;

	jmp	$L65937
$L65979:

; 329  :     case PHOTOMETRIC_LOGL:
; 330  : 	if (compress != COMPRESSION_SGILOG) {

	mov	ecx, DWORD PTR _compress$[ebp]
	and	ecx, 65535				; 0000ffffH
	cmp	ecx, 34676				; 00008774H
	je	SHORT $L65980

; 331  : 	    sprintf(emsg, "Sorry, LogL data must have %s=%d",
; 332  : 		"Compression", COMPRESSION_SGILOG);

	push	34676					; 00008774H
	push	OFFSET FLAT:$SG65981
	push	OFFSET FLAT:$SG65982
	mov	edx, DWORD PTR _emsg$[ebp]
	push	edx
	call	_sprintf
	add	esp, 16					; 00000010H

; 333  : 	    return (0);

	xor	eax, eax
	jmp	$L65899
$L65980:

; 335  : 	TIFFSetField(tif, TIFFTAG_SGILOGDATAFMT, SGILOGDATAFMT_8BIT);

	push	3
	push	65560					; 00010018H
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFSetField
	add	esp, 12					; 0000000cH

; 336  : 	img->photometric = PHOTOMETRIC_MINISBLACK;	/* little white lie */

	mov	ecx, DWORD PTR _img$[ebp]
	mov	WORD PTR [ecx+30], 1

; 337  : 	img->bitspersample = 8;

	mov	edx, DWORD PTR _img$[ebp]
	mov	WORD PTR [edx+24], 8

; 338  : 	break;

	jmp	$L65937
$L65983:

; 339  :     case PHOTOMETRIC_LOGLUV:
; 340  : 	if (compress != COMPRESSION_SGILOG && compress != COMPRESSION_SGILOG24) {

	mov	eax, DWORD PTR _compress$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 34676				; 00008774H
	je	SHORT $L65984
	mov	ecx, DWORD PTR _compress$[ebp]
	and	ecx, 65535				; 0000ffffH
	cmp	ecx, 34677				; 00008775H
	je	SHORT $L65984

; 341  : 	    sprintf(emsg, "Sorry, LogLuv data must have %s=%d or %d",
; 342  : 		"Compression", COMPRESSION_SGILOG, COMPRESSION_SGILOG24);

	push	34677					; 00008775H
	push	34676					; 00008774H
	push	OFFSET FLAT:$SG65985
	push	OFFSET FLAT:$SG65986
	mov	edx, DWORD PTR _emsg$[ebp]
	push	edx
	call	_sprintf
	add	esp, 20					; 00000014H

; 343  : 	    return (0);

	xor	eax, eax
	jmp	$L65899
$L65984:

; 345  : 	if (planarconfig != PLANARCONFIG_CONTIG) {

	mov	eax, DWORD PTR _planarconfig$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 1
	je	SHORT $L65987

; 346  : 	    sprintf(emsg, "Sorry, can not handle LogLuv images with %s=%d",
; 347  : 		"Planarconfiguration", planarconfig);

	mov	ecx, DWORD PTR _planarconfig$[ebp]
	and	ecx, 65535				; 0000ffffH
	push	ecx
	push	OFFSET FLAT:$SG65988
	push	OFFSET FLAT:$SG65989
	mov	edx, DWORD PTR _emsg$[ebp]
	push	edx
	call	_sprintf
	add	esp, 16					; 00000010H

; 348  : 	    return (0);

	xor	eax, eax
	jmp	$L65899
$L65987:

; 350  : 	TIFFSetField(tif, TIFFTAG_SGILOGDATAFMT, SGILOGDATAFMT_8BIT);

	push	3
	push	65560					; 00010018H
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFSetField
	add	esp, 12					; 0000000cH

; 351  : 	img->photometric = PHOTOMETRIC_RGB;		/* little white lie */

	mov	ecx, DWORD PTR _img$[ebp]
	mov	WORD PTR [ecx+30], 2

; 352  : 	img->bitspersample = 8;

	mov	edx, DWORD PTR _img$[ebp]
	mov	WORD PTR [edx+24], 8

; 353  : 	break;

	jmp	SHORT $L65937
$L65990:

; 354  :     default:
; 355  : 	sprintf(emsg, "Sorry, can not handle image with %s=%d",
; 356  : 	    photoTag, img->photometric);

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+30]
	push	ecx
	push	OFFSET FLAT:_photoTag
	push	OFFSET FLAT:$SG65991
	mov	edx, DWORD PTR _emsg$[ebp]
	push	edx
	call	_sprintf
	add	esp, 16					; 00000010H

; 357  : 	return (0);

	xor	eax, eax
	jmp	$L65899
$L65937:

; 359  :     img->Map = NULL;

	mov	eax, DWORD PTR _img$[ebp]
	mov	DWORD PTR [eax+52], 0

; 360  :     img->BWmap = NULL;

	mov	ecx, DWORD PTR _img$[ebp]
	mov	DWORD PTR [ecx+56], 0

; 361  :     img->PALmap = NULL;

	mov	edx, DWORD PTR _img$[ebp]
	mov	DWORD PTR [edx+60], 0

; 362  :     img->ycbcr = NULL;

	mov	eax, DWORD PTR _img$[ebp]
	mov	DWORD PTR [eax+64], 0

; 363  :     TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &img->width);

	mov	ecx, DWORD PTR _img$[ebp]
	add	ecx, 16					; 00000010H
	push	ecx
	push	256					; 00000100H
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFGetField
	add	esp, 12					; 0000000cH

; 364  :     TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &img->height);

	mov	eax, DWORD PTR _img$[ebp]
	add	eax, 20					; 00000014H
	push	eax
	push	257					; 00000101H
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFGetField
	add	esp, 12					; 0000000cH

; 365  :     TIFFGetFieldDefaulted(tif, TIFFTAG_ORIENTATION, &img->orientation);

	mov	edx, DWORD PTR _img$[ebp]
	add	edx, 28					; 0000001cH
	push	edx
	push	274					; 00000112H
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetFieldDefaulted
	add	esp, 12					; 0000000cH

; 366  :     img->isContig =
; 367  : 	!(planarconfig == PLANARCONFIG_SEPARATE && colorchannels > 1);

	mov	ecx, DWORD PTR _planarconfig$[ebp]
	and	ecx, 65535				; 0000ffffH
	cmp	ecx, 2
	jne	SHORT $L68769
	cmp	DWORD PTR _colorchannels$[ebp], 1
	jle	SHORT $L68769
	mov	DWORD PTR -64+[ebp], 0
	jmp	SHORT $L68770
$L68769:
	mov	DWORD PTR -64+[ebp], 1
$L68770:
	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR -64+[ebp]
	mov	DWORD PTR [edx+8], eax

; 368  :     if (img->isContig) {

	mov	ecx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [ecx+8], 0
	je	SHORT $L65996

; 369  : 	img->get = TIFFIsTiled(tif) ? gtTileContig : gtStripContig;

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFIsTiled
	add	esp, 4
	test	eax, eax
	je	SHORT $L68771
	mov	DWORD PTR -68+[ebp], OFFSET FLAT:_gtTileContig
	jmp	SHORT $L68772
$L68771:
	mov	DWORD PTR -68+[ebp], OFFSET FLAT:_gtStripContig
$L68772:
	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR -68+[ebp]
	mov	DWORD PTR [eax+44], ecx

; 370  : 	(void) pickTileContigCase(img);

	mov	edx, DWORD PTR _img$[ebp]
	push	edx
	call	_pickTileContigCase
	add	esp, 4

; 371  :     } else {

	jmp	SHORT $L65998
$L65996:

; 372  : 	img->get = TIFFIsTiled(tif) ? gtTileSeparate : gtStripSeparate;

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFIsTiled
	add	esp, 4
	test	eax, eax
	je	SHORT $L68773
	mov	DWORD PTR -72+[ebp], OFFSET FLAT:_gtTileSeparate
	jmp	SHORT $L68774
$L68773:
	mov	DWORD PTR -72+[ebp], OFFSET FLAT:_gtStripSeparate
$L68774:
	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR -72+[ebp]
	mov	DWORD PTR [ecx+44], edx

; 373  : 	(void) pickTileSeparateCase(img);

	mov	eax, DWORD PTR _img$[ebp]
	push	eax
	call	_pickTileSeparateCase
	add	esp, 4
$L65998:

; 375  :     return (1);

	mov	eax, 1
$L65899:

; 376  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68776:
	DD	$L65916
	DD	$L65917
$L68775:
	DB	0
	DB	0
	DB	1
	DB	0
	DB	1
	DB	1
	DB	1
	DB	0
	DB	1
	DB	1
	DB	1
	DB	1
	DB	1
	DB	1
	DB	1
	DB	0
$L68777:
	DD	$L65952
	DD	$L65952
	DD	$L65967
	DD	$L65940
	DD	$L65990
	DD	$L65971
	DD	$L65956
_TIFFRGBAImageBegin ENDP
_tif$ = 8
_compress$ = -4
_isCCITTCompression PROC NEAR

; 179  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 180  :     uint16 compress;
; 181  :     TIFFGetField(tif, TIFFTAG_COMPRESSION, &compress);

	lea	eax, DWORD PTR _compress$[ebp]
	push	eax
	push	259					; 00000103H
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFGetField
	add	esp, 12					; 0000000cH

; 182  :     return (compress == COMPRESSION_CCITTFAX3 ||
; 183  : 	    compress == COMPRESSION_CCITTFAX4 ||
; 184  : 	    compress == COMPRESSION_CCITTRLE ||
; 185  : 	    compress == COMPRESSION_CCITTRLEW);

	mov	edx, DWORD PTR _compress$[ebp]
	and	edx, 65535				; 0000ffffH
	cmp	edx, 3
	je	SHORT $L68779
	mov	eax, DWORD PTR _compress$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 4
	je	SHORT $L68779
	mov	ecx, DWORD PTR _compress$[ebp]
	and	ecx, 65535				; 0000ffffH
	cmp	ecx, 2
	je	SHORT $L68779
	mov	edx, DWORD PTR _compress$[ebp]
	and	edx, 65535				; 0000ffffH
	cmp	edx, 32771				; 00008003H
	je	SHORT $L68779
	mov	DWORD PTR -8+[ebp], 0
	jmp	SHORT $L68780
$L68779:
	mov	DWORD PTR -8+[ebp], 1
$L68780:
	mov	eax, DWORD PTR -8+[ebp]

; 186  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_isCCITTCompression ENDP
_TEXT	ENDS
PUBLIC	_TIFFRGBAImageGet
_DATA	SEGMENT
	ORG $+1
$SG66011 DB	'No "get" routine setup', 00H
	ORG $+1
$SG66014 DB	'No "put" routine setupl; probably can not handle image f'
	DB	'ormat', 00H
_DATA	ENDS
_TEXT	SEGMENT
_img$ = 8
_raster$ = 12
_w$ = 16
_h$ = 20
_TIFFRGBAImageGet PROC NEAR

; 380  : {

	push	ebp
	mov	ebp, esp

; 381  :     if (img->get == NULL) {

	mov	eax, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [eax+44], 0
	jne	SHORT $L66010

; 382  : 	TIFFError(TIFFFileName(img->tif), "No \"get\" routine setup");

	push	OFFSET FLAT:$SG66011
	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 383  : 	return (0);

	xor	eax, eax
	jmp	SHORT $L66008
$L66010:

; 385  :     if (img->put.any == NULL) {

	mov	eax, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [eax+48], 0
	jne	SHORT $L66013

; 386  : 	TIFFError(TIFFFileName(img->tif),
; 387  : 	    "No \"put\" routine setupl; probably can not handle image format");

	push	OFFSET FLAT:$SG66014
	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 388  : 	return (0);

	xor	eax, eax
	jmp	SHORT $L66008
$L66013:

; 390  :     return (*img->get)(img, raster, w, h);

	mov	eax, DWORD PTR _h$[ebp]
	push	eax
	mov	ecx, DWORD PTR _w$[ebp]
	push	ecx
	mov	edx, DWORD PTR _raster$[ebp]
	push	edx
	mov	eax, DWORD PTR _img$[ebp]
	push	eax
	mov	ecx, DWORD PTR _img$[ebp]
	call	DWORD PTR [ecx+44]
	add	esp, 16					; 00000010H
$L66008:

; 391  : }

	pop	ebp
	ret	0
_TIFFRGBAImageGet ENDP
_TEXT	ENDS
PUBLIC	_TIFFReadRGBAImage
_TEXT	SEGMENT
_tif$ = 8
_rwidth$ = 12
_rheight$ = 16
_raster$ = 20
_stop$ = 24
_emsg$ = -1104
_img$ = -76
_ok$ = -80
_TIFFReadRGBAImage PROC NEAR

; 399  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 1104				; 00000450H

; 400  :     char emsg[1024];
; 401  :     TIFFRGBAImage img;
; 402  :     int ok;
; 403  : 
; 404  :     if (TIFFRGBAImageBegin(&img, tif, stop, emsg)) {

	lea	eax, DWORD PTR _emsg$[ebp]
	push	eax
	mov	ecx, DWORD PTR _stop$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	lea	eax, DWORD PTR _img$[ebp]
	push	eax
	call	_TIFFRGBAImageBegin
	add	esp, 16					; 00000010H
	test	eax, eax
	je	SHORT $L66029

; 405  : 	/* XXX verify rwidth and rheight against width and height */
; 406  : 	ok = TIFFRGBAImageGet(&img, raster+(rheight-img.height)*rwidth,
; 407  : 	    rwidth, img.height);

	mov	ecx, DWORD PTR _img$[ebp+20]
	push	ecx
	mov	edx, DWORD PTR _rwidth$[ebp]
	push	edx
	mov	eax, DWORD PTR _rheight$[ebp]
	sub	eax, DWORD PTR _img$[ebp+20]
	imul	eax, DWORD PTR _rwidth$[ebp]
	mov	ecx, DWORD PTR _raster$[ebp]
	lea	edx, DWORD PTR [ecx+eax*4]
	push	edx
	lea	eax, DWORD PTR _img$[ebp]
	push	eax
	call	_TIFFRGBAImageGet
	add	esp, 16					; 00000010H
	mov	DWORD PTR _ok$[ebp], eax

; 408  : 	TIFFRGBAImageEnd(&img);

	lea	ecx, DWORD PTR _img$[ebp]
	push	ecx
	call	_TIFFRGBAImageEnd
	add	esp, 4

; 409  :     } else {

	jmp	SHORT $L66030
$L66029:

; 410  : 	TIFFError(TIFFFileName(tif), emsg);

	lea	edx, DWORD PTR _emsg$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 411  : 	ok = 0;

	mov	DWORD PTR _ok$[ebp], 0
$L66030:

; 413  :     return (ok);

	mov	eax, DWORD PTR _ok$[ebp]

; 414  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFReadRGBAImage ENDP
_TEXT	ENDS
EXTRN	_TIFFTileRowSize:NEAR
EXTRN	_TIFFTileSize:NEAR
EXTRN	_TIFFReadTile:NEAR
_DATA	SEGMENT
	ORG $+2
$SG66075 DB	'No space for tile buffer', 00H
_DATA	ENDS
_TEXT	SEGMENT
_img$ = 8
_raster$ = 12
_w$ = 16
_h$ = 20
_tif$ = -44
_put$ = -32
_orientation$ = -28
_col$ = -4
_row$ = -16
_y$ = -36
_rowstoread$ = -40
_ret$ = -24
_pos$ = -56
_tw$ = -52
_th$ = -60
_buf$ = -12
_fromskew$ = -8
_toskew$ = -48
_nrow$ = -20
_npix$66085 = -64
_gtTileContig PROC NEAR

; 454  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 76					; 0000004cH
	push	esi

; 455  :     TIFF* tif = img->tif;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _tif$[ebp], ecx

; 456  :     tileContigRoutine put = img->put.contig;

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx+48]
	mov	DWORD PTR _put$[ebp], eax

; 457  :     uint16 orientation;
; 458  :     uint32 col, row, y, rowstoread, ret = 1;

	mov	DWORD PTR _ret$[ebp], 1

; 459  :     uint32 pos;
; 460  :     uint32 tw, th;
; 461  :     u_char* buf;
; 462  :     int32 fromskew, toskew;
; 463  :     uint32 nrow;
; 464  :  
; 465  :     buf = (u_char*) _TIFFmalloc(TIFFTileSize(tif));

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFTileSize
	add	esp, 4
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	DWORD PTR _buf$[ebp], eax

; 466  :     if (buf == 0) {

	cmp	DWORD PTR _buf$[ebp], 0
	jne	SHORT $L66074

; 467  : 	TIFFError(TIFFFileName(tif), "No space for tile buffer");

	push	OFFSET FLAT:$SG66075
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 468  : 	return (0);

	xor	eax, eax
	jmp	$L66057
$L66074:

; 470  :     TIFFGetField(tif, TIFFTAG_TILEWIDTH, &tw);

	lea	eax, DWORD PTR _tw$[ebp]
	push	eax
	push	322					; 00000142H
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFGetField
	add	esp, 12					; 0000000cH

; 471  :     TIFFGetField(tif, TIFFTAG_TILELENGTH, &th);

	lea	edx, DWORD PTR _th$[ebp]
	push	edx
	push	323					; 00000143H
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetField
	add	esp, 12					; 0000000cH

; 472  :     y = setorientation(img, h);

	mov	ecx, DWORD PTR _h$[ebp]
	push	ecx
	mov	edx, DWORD PTR _img$[ebp]
	push	edx
	call	_setorientation
	add	esp, 8
	mov	DWORD PTR _y$[ebp], eax

; 473  :     orientation = img->orientation;

	mov	eax, DWORD PTR _img$[ebp]
	mov	cx, WORD PTR [eax+28]
	mov	WORD PTR _orientation$[ebp], cx

; 474  :     toskew = -(int32) (orientation == ORIENTATION_TOPLEFT ? tw+w : tw-w);

	mov	edx, DWORD PTR _orientation$[ebp]
	and	edx, 65535				; 0000ffffH
	cmp	edx, 1
	jne	SHORT $L68784
	mov	eax, DWORD PTR _tw$[ebp]
	add	eax, DWORD PTR _w$[ebp]
	mov	DWORD PTR -68+[ebp], eax
	jmp	SHORT $L68785
$L68784:
	mov	ecx, DWORD PTR _tw$[ebp]
	sub	ecx, DWORD PTR _w$[ebp]
	mov	DWORD PTR -68+[ebp], ecx
$L68785:
	mov	edx, DWORD PTR -68+[ebp]
	neg	edx
	mov	DWORD PTR _toskew$[ebp], edx

; 475  :     for (row = 0; row < h; row += nrow) 

	mov	DWORD PTR _row$[ebp], 0
	jmp	SHORT $L66077
$L66078:
	mov	eax, DWORD PTR _row$[ebp]
	add	eax, DWORD PTR _nrow$[ebp]
	mov	DWORD PTR _row$[ebp], eax
$L66077:
	mov	ecx, DWORD PTR _row$[ebp]
	cmp	ecx, DWORD PTR _h$[ebp]
	jae	$L66079

; 477  :         rowstoread = th - (row + img->row_offset) % th;

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	add	eax, DWORD PTR [edx+68]
	xor	edx, edx
	div	DWORD PTR _th$[ebp]
	mov	eax, DWORD PTR _th$[ebp]
	sub	eax, edx
	mov	DWORD PTR _rowstoread$[ebp], eax

; 478  :     	nrow = (row + rowstoread > h ? h - row : rowstoread);

	mov	ecx, DWORD PTR _row$[ebp]
	add	ecx, DWORD PTR _rowstoread$[ebp]
	cmp	ecx, DWORD PTR _h$[ebp]
	jbe	SHORT $L68786
	mov	edx, DWORD PTR _h$[ebp]
	sub	edx, DWORD PTR _row$[ebp]
	mov	DWORD PTR -72+[ebp], edx
	jmp	SHORT $L68787
$L68786:
	mov	eax, DWORD PTR _rowstoread$[ebp]
	mov	DWORD PTR -72+[ebp], eax
$L68787:
	mov	ecx, DWORD PTR -72+[ebp]
	mov	DWORD PTR _nrow$[ebp], ecx

; 479  : 	for (col = 0; col < w; col += tw) 

	mov	DWORD PTR _col$[ebp], 0
	jmp	SHORT $L66080
$L66081:
	mov	edx, DWORD PTR _col$[ebp]
	add	edx, DWORD PTR _tw$[ebp]
	mov	DWORD PTR _col$[ebp], edx
$L66080:
	mov	eax, DWORD PTR _col$[ebp]
	cmp	eax, DWORD PTR _w$[ebp]
	jae	$L66082

; 481  :             if (TIFFReadTile(tif, buf, col+img->col_offset,
; 482  :                              row+img->row_offset, 0, 0) < 0 && img->stoponerr)

	push	0
	push	0
	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR _row$[ebp]
	add	edx, DWORD PTR [ecx+68]
	push	edx
	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR _col$[ebp]
	add	ecx, DWORD PTR [eax+72]
	push	ecx
	mov	edx, DWORD PTR _buf$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFReadTile
	add	esp, 24					; 00000018H
	test	eax, eax
	jge	SHORT $L66083
	mov	ecx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [ecx+4], 0
	je	SHORT $L66083

; 484  :                 ret = 0;

	mov	DWORD PTR _ret$[ebp], 0

; 485  :                 break;

	jmp	$L66082
$L66083:

; 487  : 
; 488  :             pos = ((row+img->row_offset) % th) * TIFFTileRowSize(tif);

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	add	eax, DWORD PTR [edx+68]
	xor	edx, edx
	div	DWORD PTR _th$[ebp]
	mov	esi, edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFTileRowSize
	add	esp, 4
	imul	esi, eax
	mov	DWORD PTR _pos$[ebp], esi

; 489  : 
; 490  :     	    if (col + tw > w) 

	mov	ecx, DWORD PTR _col$[ebp]
	add	ecx, DWORD PTR _tw$[ebp]
	cmp	ecx, DWORD PTR _w$[ebp]
	jbe	SHORT $L66084

; 492  :                 /*
; 493  :                  * Tile is clipped horizontally.  Calculate
; 494  :                  * visible portion and skewing factors.
; 495  :                  */
; 496  :                 uint32 npix = w - col;

	mov	edx, DWORD PTR _w$[ebp]
	sub	edx, DWORD PTR _col$[ebp]
	mov	DWORD PTR _npix$66085[ebp], edx

; 497  :                 fromskew = tw - npix;

	mov	eax, DWORD PTR _tw$[ebp]
	sub	eax, DWORD PTR _npix$66085[ebp]
	mov	DWORD PTR _fromskew$[ebp], eax

; 498  :                 (*put)(img, raster+y*w+col, col, y,
; 499  :                        npix, nrow, fromskew, toskew + fromskew, buf + pos);

	mov	ecx, DWORD PTR _buf$[ebp]
	add	ecx, DWORD PTR _pos$[ebp]
	push	ecx
	mov	edx, DWORD PTR _toskew$[ebp]
	add	edx, DWORD PTR _fromskew$[ebp]
	push	edx
	mov	eax, DWORD PTR _fromskew$[ebp]
	push	eax
	mov	ecx, DWORD PTR _nrow$[ebp]
	push	ecx
	mov	edx, DWORD PTR _npix$66085[ebp]
	push	edx
	mov	eax, DWORD PTR _y$[ebp]
	push	eax
	mov	ecx, DWORD PTR _col$[ebp]
	push	ecx
	mov	edx, DWORD PTR _y$[ebp]
	imul	edx, DWORD PTR _w$[ebp]
	mov	eax, DWORD PTR _raster$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	edx, DWORD PTR _col$[ebp]
	lea	eax, DWORD PTR [ecx+edx*4]
	push	eax
	mov	ecx, DWORD PTR _img$[ebp]
	push	ecx
	call	DWORD PTR _put$[ebp]
	add	esp, 36					; 00000024H

; 501  :             else 

	jmp	SHORT $L66086
$L66084:

; 503  :                 (*put)(img, raster+y*w+col, col, y, tw, nrow, 0, toskew, buf + pos);

	mov	edx, DWORD PTR _buf$[ebp]
	add	edx, DWORD PTR _pos$[ebp]
	push	edx
	mov	eax, DWORD PTR _toskew$[ebp]
	push	eax
	push	0
	mov	ecx, DWORD PTR _nrow$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tw$[ebp]
	push	edx
	mov	eax, DWORD PTR _y$[ebp]
	push	eax
	mov	ecx, DWORD PTR _col$[ebp]
	push	ecx
	mov	edx, DWORD PTR _y$[ebp]
	imul	edx, DWORD PTR _w$[ebp]
	mov	eax, DWORD PTR _raster$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	edx, DWORD PTR _col$[ebp]
	lea	eax, DWORD PTR [ecx+edx*4]
	push	eax
	mov	ecx, DWORD PTR _img$[ebp]
	push	ecx
	call	DWORD PTR _put$[ebp]
	add	esp, 36					; 00000024H
$L66086:

; 505  :         }

	jmp	$L66081
$L66082:

; 506  : 
; 507  :         y += (orientation == ORIENTATION_TOPLEFT ? -(int32) nrow : (int32) nrow);

	mov	edx, DWORD PTR _orientation$[ebp]
	and	edx, 65535				; 0000ffffH
	cmp	edx, 1
	jne	SHORT $L68788
	mov	eax, DWORD PTR _nrow$[ebp]
	neg	eax
	mov	DWORD PTR -76+[ebp], eax
	jmp	SHORT $L68789
$L68788:
	mov	ecx, DWORD PTR _nrow$[ebp]
	mov	DWORD PTR -76+[ebp], ecx
$L68789:
	mov	edx, DWORD PTR _y$[ebp]
	add	edx, DWORD PTR -76+[ebp]
	mov	DWORD PTR _y$[ebp], edx

; 508  :     }

	jmp	$L66078
$L66079:

; 509  :     _TIFFfree(buf);

	mov	eax, DWORD PTR _buf$[ebp]
	push	eax
	call	__TIFFfree
	add	esp, 4

; 510  :     return (ret);

	mov	eax, DWORD PTR _ret$[ebp]
$L66057:

; 511  : }

	pop	esi
	mov	esp, ebp
	pop	ebp
	ret	0
_gtTileContig ENDP
_TEXT	ENDS
EXTRN	_TIFFWarning:NEAR
_DATA	SEGMENT
	ORG $+3
$SG66044 DB	'using bottom-left orientation', 00H
	ORG $+2
$SG66047 DB	'using top-left orientation', 00H
_DATA	ENDS
_TEXT	SEGMENT
_img$ = 8
_h$ = 12
_tif$ = -8
_y$ = -4
_setorientation PROC NEAR

; 418  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 419  :     TIFF* tif = img->tif;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _tif$[ebp], ecx

; 420  :     uint32 y;
; 421  : 
; 422  :     switch (img->orientation) {

	mov	edx, DWORD PTR _img$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+28]
	mov	DWORD PTR -12+[ebp], eax
	mov	ecx, DWORD PTR -12+[ebp]
	sub	ecx, 1
	mov	DWORD PTR -12+[ebp], ecx
	cmp	DWORD PTR -12+[ebp], 7
	ja	SHORT $L66046
	mov	edx, DWORD PTR -12+[ebp]
	jmp	DWORD PTR $L68791[edx*4]
$L66043:

; 423  :     case ORIENTATION_BOTRIGHT:
; 424  :     case ORIENTATION_RIGHTBOT:	/* XXX */
; 425  :     case ORIENTATION_LEFTBOT:	/* XXX */
; 426  : 	TIFFWarning(TIFFFileName(tif), "using bottom-left orientation");

	push	OFFSET FLAT:$SG66044
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFWarning
	add	esp, 8

; 427  : 	img->orientation = ORIENTATION_BOTLEFT;

	mov	ecx, DWORD PTR _img$[ebp]
	mov	WORD PTR [ecx+28], 4
$L66045:

; 428  : 	/* fall thru... */
; 429  :     case ORIENTATION_BOTLEFT:
; 430  : 	y = 0;

	mov	DWORD PTR _y$[ebp], 0

; 431  : 	break;

	jmp	SHORT $L66040
$L66046:

; 432  :     case ORIENTATION_TOPRIGHT:
; 433  :     case ORIENTATION_RIGHTTOP:	/* XXX */
; 434  :     case ORIENTATION_LEFTTOP:	/* XXX */
; 435  :     default:
; 436  : 	TIFFWarning(TIFFFileName(tif), "using top-left orientation");

	push	OFFSET FLAT:$SG66047
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFWarning
	add	esp, 8

; 437  : 	img->orientation = ORIENTATION_TOPLEFT;

	mov	eax, DWORD PTR _img$[ebp]
	mov	WORD PTR [eax+28], 1
$L66048:

; 438  : 	/* fall thru... */
; 439  :     case ORIENTATION_TOPLEFT:
; 440  : 	y = h-1;

	mov	ecx, DWORD PTR _h$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _y$[ebp], ecx
$L66040:

; 443  :     return (y);

	mov	eax, DWORD PTR _y$[ebp]

; 444  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68791:
	DD	$L66048
	DD	$L66046
	DD	$L66043
	DD	$L66045
	DD	$L66046
	DD	$L66046
	DD	$L66043
	DD	$L66043
_setorientation ENDP
_TEXT	ENDS
EXTRN	_memset:NEAR
_DATA	SEGMENT
	ORG $+1
$SG66121 DB	'No space for tile buffer', 00H
_DATA	ENDS
_TEXT	SEGMENT
_img$ = 8
_raster$ = 12
_w$ = 16
_h$ = 20
_tif$ = -68
_put$ = -56
_orientation$ = -52
_col$ = -8
_row$ = -36
_y$ = -60
_rowstoread$ = -64
_pos$ = -80
_tw$ = -76
_th$ = -84
_buf$ = -32
_r$ = -28
_g$ = -48
_b$ = -24
_a$ = -16
_tilesize$ = -4
_fromskew$ = -20
_toskew$ = -72
_alpha$ = -12
_nrow$ = -40
_ret$ = -44
_npix$66135 = -88
_gtTileSeparate PROC NEAR

; 521  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 100				; 00000064H
	push	esi

; 522  :     TIFF* tif = img->tif;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _tif$[ebp], ecx

; 523  :     tileSeparateRoutine put = img->put.separate;

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx+48]
	mov	DWORD PTR _put$[ebp], eax

; 524  :     uint16 orientation;
; 525  :     uint32 col, row, y, rowstoread;
; 526  :     uint32 pos;
; 527  :     uint32 tw, th;
; 528  :     u_char* buf;
; 529  :     u_char* r;
; 530  :     u_char* g;
; 531  :     u_char* b;
; 532  :     u_char* a;
; 533  :     tsize_t tilesize;
; 534  :     int32 fromskew, toskew;
; 535  :     int alpha = img->alpha;

	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR _alpha$[ebp], edx

; 536  :     uint32 nrow;
; 537  :     int ret = 1;

	mov	DWORD PTR _ret$[ebp], 1

; 538  : 
; 539  :     tilesize = TIFFTileSize(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFTileSize
	add	esp, 4
	mov	DWORD PTR _tilesize$[ebp], eax

; 540  :     buf = (u_char*) _TIFFmalloc(4*tilesize);

	mov	ecx, DWORD PTR _tilesize$[ebp]
	shl	ecx, 2
	push	ecx
	call	__TIFFmalloc
	add	esp, 4
	mov	DWORD PTR _buf$[ebp], eax

; 541  :     if (buf == 0) {

	cmp	DWORD PTR _buf$[ebp], 0
	jne	SHORT $L66120

; 542  : 	TIFFError(TIFFFileName(tif), "No space for tile buffer");

	push	OFFSET FLAT:$SG66121
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 543  : 	return (0);

	xor	eax, eax
	jmp	$L66097
$L66120:

; 545  :     r = buf;

	mov	eax, DWORD PTR _buf$[ebp]
	mov	DWORD PTR _r$[ebp], eax

; 546  :     g = r + tilesize;

	mov	ecx, DWORD PTR _r$[ebp]
	add	ecx, DWORD PTR _tilesize$[ebp]
	mov	DWORD PTR _g$[ebp], ecx

; 547  :     b = g + tilesize;

	mov	edx, DWORD PTR _g$[ebp]
	add	edx, DWORD PTR _tilesize$[ebp]
	mov	DWORD PTR _b$[ebp], edx

; 548  :     a = b + tilesize;

	mov	eax, DWORD PTR _b$[ebp]
	add	eax, DWORD PTR _tilesize$[ebp]
	mov	DWORD PTR _a$[ebp], eax

; 549  :     if (!alpha)

	cmp	DWORD PTR _alpha$[ebp], 0
	jne	SHORT $L66122

; 550  : 	memset(a, 0xff, tilesize);

	mov	ecx, DWORD PTR _tilesize$[ebp]
	push	ecx
	push	255					; 000000ffH
	mov	edx, DWORD PTR _a$[ebp]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH
$L66122:

; 551  :     TIFFGetField(tif, TIFFTAG_TILEWIDTH, &tw);

	lea	eax, DWORD PTR _tw$[ebp]
	push	eax
	push	322					; 00000142H
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFGetField
	add	esp, 12					; 0000000cH

; 552  :     TIFFGetField(tif, TIFFTAG_TILELENGTH, &th);

	lea	edx, DWORD PTR _th$[ebp]
	push	edx
	push	323					; 00000143H
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetField
	add	esp, 12					; 0000000cH

; 553  :     y = setorientation(img, h);

	mov	ecx, DWORD PTR _h$[ebp]
	push	ecx
	mov	edx, DWORD PTR _img$[ebp]
	push	edx
	call	_setorientation
	add	esp, 8
	mov	DWORD PTR _y$[ebp], eax

; 554  :     orientation = img->orientation;

	mov	eax, DWORD PTR _img$[ebp]
	mov	cx, WORD PTR [eax+28]
	mov	WORD PTR _orientation$[ebp], cx

; 555  :     toskew = -(int32) (orientation == ORIENTATION_TOPLEFT ? tw+w : tw-w);

	mov	edx, DWORD PTR _orientation$[ebp]
	and	edx, 65535				; 0000ffffH
	cmp	edx, 1
	jne	SHORT $L68793
	mov	eax, DWORD PTR _tw$[ebp]
	add	eax, DWORD PTR _w$[ebp]
	mov	DWORD PTR -92+[ebp], eax
	jmp	SHORT $L68794
$L68793:
	mov	ecx, DWORD PTR _tw$[ebp]
	sub	ecx, DWORD PTR _w$[ebp]
	mov	DWORD PTR -92+[ebp], ecx
$L68794:
	mov	edx, DWORD PTR -92+[ebp]
	neg	edx
	mov	DWORD PTR _toskew$[ebp], edx

; 556  :     for (row = 0; row < h; row += nrow) 

	mov	DWORD PTR _row$[ebp], 0
	jmp	SHORT $L66124
$L66125:
	mov	eax, DWORD PTR _row$[ebp]
	add	eax, DWORD PTR _nrow$[ebp]
	mov	DWORD PTR _row$[ebp], eax
$L66124:
	mov	ecx, DWORD PTR _row$[ebp]
	cmp	ecx, DWORD PTR _h$[ebp]
	jae	$L66126

; 558  :         rowstoread = th - (row + img->row_offset) % th;

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	add	eax, DWORD PTR [edx+68]
	xor	edx, edx
	div	DWORD PTR _th$[ebp]
	mov	eax, DWORD PTR _th$[ebp]
	sub	eax, edx
	mov	DWORD PTR _rowstoread$[ebp], eax

; 559  :     	nrow = (row + rowstoread > h ? h - row : rowstoread);

	mov	ecx, DWORD PTR _row$[ebp]
	add	ecx, DWORD PTR _rowstoread$[ebp]
	cmp	ecx, DWORD PTR _h$[ebp]
	jbe	SHORT $L68795
	mov	edx, DWORD PTR _h$[ebp]
	sub	edx, DWORD PTR _row$[ebp]
	mov	DWORD PTR -96+[ebp], edx
	jmp	SHORT $L68796
$L68795:
	mov	eax, DWORD PTR _rowstoread$[ebp]
	mov	DWORD PTR -96+[ebp], eax
$L68796:
	mov	ecx, DWORD PTR -96+[ebp]
	mov	DWORD PTR _nrow$[ebp], ecx

; 560  :         for (col = 0; col < w; col += tw) 

	mov	DWORD PTR _col$[ebp], 0
	jmp	SHORT $L66127
$L66128:
	mov	edx, DWORD PTR _col$[ebp]
	add	edx, DWORD PTR _tw$[ebp]
	mov	DWORD PTR _col$[ebp], edx
$L66127:
	mov	eax, DWORD PTR _col$[ebp]
	cmp	eax, DWORD PTR _w$[ebp]
	jae	$L66129

; 562  :             if (TIFFReadTile(tif, r, col+img->col_offset,
; 563  :                              row+img->row_offset,0,0) < 0 && img->stoponerr)

	push	0
	push	0
	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR _row$[ebp]
	add	edx, DWORD PTR [ecx+68]
	push	edx
	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR _col$[ebp]
	add	ecx, DWORD PTR [eax+72]
	push	ecx
	mov	edx, DWORD PTR _r$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFReadTile
	add	esp, 24					; 00000018H
	test	eax, eax
	jge	SHORT $L66130
	mov	ecx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [ecx+4], 0
	je	SHORT $L66130

; 565  :                 ret = 0;

	mov	DWORD PTR _ret$[ebp], 0

; 566  :                 break;

	jmp	$L66129
$L66130:

; 568  :             if (TIFFReadTile(tif, g, col+img->col_offset,
; 569  :                              row+img->row_offset,0,1) < 0 && img->stoponerr)

	push	1
	push	0
	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	add	eax, DWORD PTR [edx+68]
	push	eax
	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR _col$[ebp]
	add	edx, DWORD PTR [ecx+72]
	push	edx
	mov	eax, DWORD PTR _g$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFReadTile
	add	esp, 24					; 00000018H
	test	eax, eax
	jge	SHORT $L66131
	mov	edx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [edx+4], 0
	je	SHORT $L66131

; 571  :                 ret = 0;

	mov	DWORD PTR _ret$[ebp], 0

; 572  :                 break;

	jmp	$L66129
$L66131:

; 574  :             if (TIFFReadTile(tif, b, col+img->col_offset,
; 575  :                              row+img->row_offset,0,2) < 0 && img->stoponerr)

	push	2
	push	0
	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR _row$[ebp]
	add	ecx, DWORD PTR [eax+68]
	push	ecx
	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR _col$[ebp]
	add	eax, DWORD PTR [edx+72]
	push	eax
	mov	ecx, DWORD PTR _b$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFReadTile
	add	esp, 24					; 00000018H
	test	eax, eax
	jge	SHORT $L66132
	mov	eax, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [eax+4], 0
	je	SHORT $L66132

; 577  :                 ret = 0;

	mov	DWORD PTR _ret$[ebp], 0

; 578  :                 break;

	jmp	$L66129
$L66132:

; 580  :             if (alpha && TIFFReadTile(tif,a,col+img->col_offset,
; 581  :                                       row+img->row_offset,0,3) < 0 && img->stoponerr)

	cmp	DWORD PTR _alpha$[ebp], 0
	je	SHORT $L66133
	push	3
	push	0
	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR _row$[ebp]
	add	edx, DWORD PTR [ecx+68]
	push	edx
	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR _col$[ebp]
	add	ecx, DWORD PTR [eax+72]
	push	ecx
	mov	edx, DWORD PTR _a$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFReadTile
	add	esp, 24					; 00000018H
	test	eax, eax
	jge	SHORT $L66133
	mov	ecx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [ecx+4], 0
	je	SHORT $L66133

; 583  :                 ret = 0;

	mov	DWORD PTR _ret$[ebp], 0

; 584  :                 break;

	jmp	$L66129
$L66133:

; 586  : 
; 587  :             pos = ((row+img->row_offset) % th) * TIFFTileRowSize(tif);

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	add	eax, DWORD PTR [edx+68]
	xor	edx, edx
	div	DWORD PTR _th$[ebp]
	mov	esi, edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFTileRowSize
	add	esp, 4
	imul	esi, eax
	mov	DWORD PTR _pos$[ebp], esi

; 588  : 
; 589  :             if (col + tw > w) 

	mov	ecx, DWORD PTR _col$[ebp]
	add	ecx, DWORD PTR _tw$[ebp]
	cmp	ecx, DWORD PTR _w$[ebp]
	jbe	SHORT $L66134

; 591  :                 /*
; 592  :                  * Tile is clipped horizontally.  Calculate
; 593  :                  * visible portion and skewing factors.
; 594  :                  */
; 595  :                 uint32 npix = w - col;

	mov	edx, DWORD PTR _w$[ebp]
	sub	edx, DWORD PTR _col$[ebp]
	mov	DWORD PTR _npix$66135[ebp], edx

; 596  :                 fromskew = tw - npix;

	mov	eax, DWORD PTR _tw$[ebp]
	sub	eax, DWORD PTR _npix$66135[ebp]
	mov	DWORD PTR _fromskew$[ebp], eax

; 597  :                 (*put)(img, raster+y*w+col, col, y,
; 598  :                        npix, nrow, fromskew, toskew + fromskew, 
; 599  :                        r + pos, g + pos, b + pos, a + pos);

	mov	ecx, DWORD PTR _a$[ebp]
	add	ecx, DWORD PTR _pos$[ebp]
	push	ecx
	mov	edx, DWORD PTR _b$[ebp]
	add	edx, DWORD PTR _pos$[ebp]
	push	edx
	mov	eax, DWORD PTR _g$[ebp]
	add	eax, DWORD PTR _pos$[ebp]
	push	eax
	mov	ecx, DWORD PTR _r$[ebp]
	add	ecx, DWORD PTR _pos$[ebp]
	push	ecx
	mov	edx, DWORD PTR _toskew$[ebp]
	add	edx, DWORD PTR _fromskew$[ebp]
	push	edx
	mov	eax, DWORD PTR _fromskew$[ebp]
	push	eax
	mov	ecx, DWORD PTR _nrow$[ebp]
	push	ecx
	mov	edx, DWORD PTR _npix$66135[ebp]
	push	edx
	mov	eax, DWORD PTR _y$[ebp]
	push	eax
	mov	ecx, DWORD PTR _col$[ebp]
	push	ecx
	mov	edx, DWORD PTR _y$[ebp]
	imul	edx, DWORD PTR _w$[ebp]
	mov	eax, DWORD PTR _raster$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	edx, DWORD PTR _col$[ebp]
	lea	eax, DWORD PTR [ecx+edx*4]
	push	eax
	mov	ecx, DWORD PTR _img$[ebp]
	push	ecx
	call	DWORD PTR _put$[ebp]
	add	esp, 48					; 00000030H

; 601  :             else 

	jmp	SHORT $L66136
$L66134:

; 603  :                 (*put)(img, raster+y*w+col, col, y,
; 604  :                        tw, nrow, 0, toskew, r + pos, g + pos, b + pos, a + pos);

	mov	edx, DWORD PTR _a$[ebp]
	add	edx, DWORD PTR _pos$[ebp]
	push	edx
	mov	eax, DWORD PTR _b$[ebp]
	add	eax, DWORD PTR _pos$[ebp]
	push	eax
	mov	ecx, DWORD PTR _g$[ebp]
	add	ecx, DWORD PTR _pos$[ebp]
	push	ecx
	mov	edx, DWORD PTR _r$[ebp]
	add	edx, DWORD PTR _pos$[ebp]
	push	edx
	mov	eax, DWORD PTR _toskew$[ebp]
	push	eax
	push	0
	mov	ecx, DWORD PTR _nrow$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tw$[ebp]
	push	edx
	mov	eax, DWORD PTR _y$[ebp]
	push	eax
	mov	ecx, DWORD PTR _col$[ebp]
	push	ecx
	mov	edx, DWORD PTR _y$[ebp]
	imul	edx, DWORD PTR _w$[ebp]
	mov	eax, DWORD PTR _raster$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	edx, DWORD PTR _col$[ebp]
	lea	eax, DWORD PTR [ecx+edx*4]
	push	eax
	mov	ecx, DWORD PTR _img$[ebp]
	push	ecx
	call	DWORD PTR _put$[ebp]
	add	esp, 48					; 00000030H
$L66136:

; 606  :         }

	jmp	$L66128
$L66129:

; 607  : 
; 608  :         y += (orientation == ORIENTATION_TOPLEFT ?-(int32) nrow : (int32) nrow);

	mov	edx, DWORD PTR _orientation$[ebp]
	and	edx, 65535				; 0000ffffH
	cmp	edx, 1
	jne	SHORT $L68797
	mov	eax, DWORD PTR _nrow$[ebp]
	neg	eax
	mov	DWORD PTR -100+[ebp], eax
	jmp	SHORT $L68798
$L68797:
	mov	ecx, DWORD PTR _nrow$[ebp]
	mov	DWORD PTR -100+[ebp], ecx
$L68798:
	mov	edx, DWORD PTR _y$[ebp]
	add	edx, DWORD PTR -100+[ebp]
	mov	DWORD PTR _y$[ebp], edx

; 609  :     }

	jmp	$L66125
$L66126:

; 610  :     _TIFFfree(buf);

	mov	eax, DWORD PTR _buf$[ebp]
	push	eax
	call	__TIFFfree
	add	esp, 4

; 611  :     return (ret);

	mov	eax, DWORD PTR _ret$[ebp]
$L66097:

; 612  : }

	pop	esi
	mov	esp, ebp
	pop	ebp
	ret	0
_gtTileSeparate ENDP
_TEXT	ENDS
EXTRN	_TIFFScanlineSize:NEAR
EXTRN	_TIFFStripSize:NEAR
EXTRN	_TIFFComputeStrip:NEAR
EXTRN	_TIFFReadEncodedStrip:NEAR
_DATA	SEGMENT
	ORG $+3
$SG66165 DB	'No space for strip buffer', 00H
_DATA	ENDS
_TEXT	SEGMENT
_img$ = 8
_raster$ = 12
_w$ = 16
_h$ = 20
_tif$ = -40
_put$ = -28
_orientation$ = -24
_row$ = -12
_y$ = -32
_nrow$ = -16
_rowstoread$ = -36
_pos$ = -56
_buf$ = -8
_rowsperstrip$ = -48
_imagewidth$ = -60
_scanline$ = -52
_fromskew$ = -4
_toskew$ = -44
_ret$ = -20
_gtStripContig PROC NEAR

; 622  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 76					; 0000004cH

; 623  :     TIFF* tif = img->tif;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _tif$[ebp], ecx

; 624  :     tileContigRoutine put = img->put.contig;

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx+48]
	mov	DWORD PTR _put$[ebp], eax

; 625  :     uint16 orientation;
; 626  :     uint32 row, y, nrow, rowstoread;
; 627  :     uint32 pos;
; 628  :     u_char* buf;
; 629  :     uint32 rowsperstrip;
; 630  :     uint32 imagewidth = img->width;

	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	mov	DWORD PTR _imagewidth$[ebp], edx

; 631  :     tsize_t scanline;
; 632  :     int32 fromskew, toskew;
; 633  :     int ret = 1;

	mov	DWORD PTR _ret$[ebp], 1

; 634  : 
; 635  :     buf = (u_char*) _TIFFmalloc(TIFFStripSize(tif));

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFStripSize
	add	esp, 4
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	DWORD PTR _buf$[ebp], eax

; 636  :     if (buf == 0) {

	cmp	DWORD PTR _buf$[ebp], 0
	jne	SHORT $L66164

; 637  : 	TIFFError(TIFFFileName(tif), "No space for strip buffer");

	push	OFFSET FLAT:$SG66165
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 638  : 	return (0);

	xor	eax, eax
	jmp	$L66147
$L66164:

; 640  :     y = setorientation(img, h);

	mov	edx, DWORD PTR _h$[ebp]
	push	edx
	mov	eax, DWORD PTR _img$[ebp]
	push	eax
	call	_setorientation
	add	esp, 8
	mov	DWORD PTR _y$[ebp], eax

; 641  :     orientation = img->orientation;

	mov	ecx, DWORD PTR _img$[ebp]
	mov	dx, WORD PTR [ecx+28]
	mov	WORD PTR _orientation$[ebp], dx

; 642  :     toskew = -(int32) (orientation == ORIENTATION_TOPLEFT ? w+w : w-w);

	mov	eax, DWORD PTR _orientation$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 1
	jne	SHORT $L68800
	mov	ecx, DWORD PTR _w$[ebp]
	add	ecx, DWORD PTR _w$[ebp]
	mov	DWORD PTR -64+[ebp], ecx
	jmp	SHORT $L68801
$L68800:
	mov	edx, DWORD PTR _w$[ebp]
	sub	edx, DWORD PTR _w$[ebp]
	mov	DWORD PTR -64+[ebp], edx
$L68801:
	mov	eax, DWORD PTR -64+[ebp]
	neg	eax
	mov	DWORD PTR _toskew$[ebp], eax

; 643  :     TIFFGetFieldDefaulted(tif, TIFFTAG_ROWSPERSTRIP, &rowsperstrip);

	lea	ecx, DWORD PTR _rowsperstrip$[ebp]
	push	ecx
	push	278					; 00000116H
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFGetFieldDefaulted
	add	esp, 12					; 0000000cH

; 644  :     scanline = TIFFScanlineSize(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFScanlineSize
	add	esp, 4
	mov	DWORD PTR _scanline$[ebp], eax

; 645  :     fromskew = (w < imagewidth ? imagewidth - w : 0);

	mov	ecx, DWORD PTR _w$[ebp]
	cmp	ecx, DWORD PTR _imagewidth$[ebp]
	jae	SHORT $L68802
	mov	edx, DWORD PTR _imagewidth$[ebp]
	sub	edx, DWORD PTR _w$[ebp]
	mov	DWORD PTR -68+[ebp], edx
	jmp	SHORT $L68803
$L68802:
	mov	DWORD PTR -68+[ebp], 0
$L68803:
	mov	eax, DWORD PTR -68+[ebp]
	mov	DWORD PTR _fromskew$[ebp], eax

; 646  :     for (row = 0; row < h; row += nrow) 

	mov	DWORD PTR _row$[ebp], 0
	jmp	SHORT $L66167
$L66168:
	mov	ecx, DWORD PTR _row$[ebp]
	add	ecx, DWORD PTR _nrow$[ebp]
	mov	DWORD PTR _row$[ebp], ecx
$L66167:
	mov	edx, DWORD PTR _row$[ebp]
	cmp	edx, DWORD PTR _h$[ebp]
	jae	$L66169

; 648  :         rowstoread = rowsperstrip - (row + img->row_offset) % rowsperstrip;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR _row$[ebp]
	add	ecx, DWORD PTR [eax+68]
	mov	eax, ecx
	xor	edx, edx
	div	DWORD PTR _rowsperstrip$[ebp]
	mov	eax, DWORD PTR _rowsperstrip$[ebp]
	sub	eax, edx
	mov	DWORD PTR _rowstoread$[ebp], eax

; 649  :         nrow = (row + rowstoread > h ? h - row : rowstoread);

	mov	ecx, DWORD PTR _row$[ebp]
	add	ecx, DWORD PTR _rowstoread$[ebp]
	cmp	ecx, DWORD PTR _h$[ebp]
	jbe	SHORT $L68804
	mov	edx, DWORD PTR _h$[ebp]
	sub	edx, DWORD PTR _row$[ebp]
	mov	DWORD PTR -72+[ebp], edx
	jmp	SHORT $L68805
$L68804:
	mov	eax, DWORD PTR _rowstoread$[ebp]
	mov	DWORD PTR -72+[ebp], eax
$L68805:
	mov	ecx, DWORD PTR -72+[ebp]
	mov	DWORD PTR _nrow$[ebp], ecx

; 650  :         if (TIFFReadEncodedStrip(tif,
; 651  :                                  TIFFComputeStrip(tif,row+img->row_offset, 0),
; 652  :                                  buf, 
; 653  :                                  ((row + img->row_offset)%rowsperstrip + nrow) * scanline) < 0
; 654  :             && img->stoponerr)

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	add	eax, DWORD PTR [edx+68]
	xor	edx, edx
	div	DWORD PTR _rowsperstrip$[ebp]
	add	edx, DWORD PTR _nrow$[ebp]
	imul	edx, DWORD PTR _scanline$[ebp]
	push	edx
	mov	eax, DWORD PTR _buf$[ebp]
	push	eax
	push	0
	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR _row$[ebp]
	add	edx, DWORD PTR [ecx+68]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFComputeStrip
	add	esp, 12					; 0000000cH
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFReadEncodedStrip
	add	esp, 16					; 00000010H
	test	eax, eax
	jge	SHORT $L66170
	mov	edx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [edx+4], 0
	je	SHORT $L66170

; 656  :             ret = 0;

	mov	DWORD PTR _ret$[ebp], 0

; 657  :             break;

	jmp	SHORT $L66169
$L66170:

; 659  : 
; 660  :         pos = ((row + img->row_offset) % rowsperstrip) * scanline;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR _row$[ebp]
	add	ecx, DWORD PTR [eax+68]
	mov	eax, ecx
	xor	edx, edx
	div	DWORD PTR _rowsperstrip$[ebp]
	imul	edx, DWORD PTR _scanline$[ebp]
	mov	DWORD PTR _pos$[ebp], edx

; 661  :         (*put)(img, raster+y*w, 0, y, w, nrow, fromskew, toskew, buf + pos);

	mov	edx, DWORD PTR _buf$[ebp]
	add	edx, DWORD PTR _pos$[ebp]
	push	edx
	mov	eax, DWORD PTR _toskew$[ebp]
	push	eax
	mov	ecx, DWORD PTR _fromskew$[ebp]
	push	ecx
	mov	edx, DWORD PTR _nrow$[ebp]
	push	edx
	mov	eax, DWORD PTR _w$[ebp]
	push	eax
	mov	ecx, DWORD PTR _y$[ebp]
	push	ecx
	push	0
	mov	edx, DWORD PTR _y$[ebp]
	imul	edx, DWORD PTR _w$[ebp]
	mov	eax, DWORD PTR _raster$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	push	ecx
	mov	edx, DWORD PTR _img$[ebp]
	push	edx
	call	DWORD PTR _put$[ebp]
	add	esp, 36					; 00000024H

; 662  :         y += (orientation == ORIENTATION_TOPLEFT ?-(int32) nrow : (int32) nrow);

	mov	eax, DWORD PTR _orientation$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 1
	jne	SHORT $L68806
	mov	ecx, DWORD PTR _nrow$[ebp]
	neg	ecx
	mov	DWORD PTR -76+[ebp], ecx
	jmp	SHORT $L68807
$L68806:
	mov	edx, DWORD PTR _nrow$[ebp]
	mov	DWORD PTR -76+[ebp], edx
$L68807:
	mov	eax, DWORD PTR _y$[ebp]
	add	eax, DWORD PTR -76+[ebp]
	mov	DWORD PTR _y$[ebp], eax

; 663  :     }

	jmp	$L66168
$L66169:

; 664  :     _TIFFfree(buf);

	mov	ecx, DWORD PTR _buf$[ebp]
	push	ecx
	call	__TIFFfree
	add	esp, 4

; 665  :     return (ret);

	mov	eax, DWORD PTR _ret$[ebp]
$L66147:

; 666  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_gtStripContig ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+2
$SG66206 DB	'No space for tile buffer', 00H
_DATA	ENDS
_TEXT	SEGMENT
_img$ = 8
_raster$ = 12
_w$ = 16
_h$ = 20
_tif$ = -68
_put$ = -56
_orientation$ = -52
_buf$ = -36
_r$ = -32
_g$ = -48
_b$ = -28
_a$ = -16
_row$ = -24
_y$ = -60
_nrow$ = -40
_rowstoread$ = -64
_pos$ = -84
_scanline$ = -80
_rowsperstrip$ = -76
_offset_row$ = -12
_imagewidth$ = -88
_stripsize$ = -4
_fromskew$ = -20
_toskew$ = -72
_alpha$ = -8
_ret$ = -44
_gtStripSeparate PROC NEAR

; 676  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 104				; 00000068H

; 677  :     TIFF* tif = img->tif;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _tif$[ebp], ecx

; 678  :     tileSeparateRoutine put = img->put.separate;

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx+48]
	mov	DWORD PTR _put$[ebp], eax

; 679  :     uint16 orientation;
; 680  :     u_char *buf;
; 681  :     u_char *r, *g, *b, *a;
; 682  :     uint32 row, y, nrow, rowstoread;
; 683  :     uint32 pos;
; 684  :     tsize_t scanline;
; 685  :     uint32 rowsperstrip, offset_row;
; 686  :     uint32 imagewidth = img->width;

	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	mov	DWORD PTR _imagewidth$[ebp], edx

; 687  :     tsize_t stripsize;
; 688  :     int32 fromskew, toskew;
; 689  :     int alpha = img->alpha;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _alpha$[ebp], ecx

; 690  :     int	ret = 1;

	mov	DWORD PTR _ret$[ebp], 1

; 691  : 
; 692  :     stripsize = TIFFStripSize(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFStripSize
	add	esp, 4
	mov	DWORD PTR _stripsize$[ebp], eax

; 693  :     r = buf = (u_char *)_TIFFmalloc(4*stripsize);

	mov	eax, DWORD PTR _stripsize$[ebp]
	shl	eax, 2
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	DWORD PTR _buf$[ebp], eax
	mov	ecx, DWORD PTR _buf$[ebp]
	mov	DWORD PTR _r$[ebp], ecx

; 694  :     if (buf == 0) {

	cmp	DWORD PTR _buf$[ebp], 0
	jne	SHORT $L66205

; 695  : 	TIFFError(TIFFFileName(tif), "No space for tile buffer");

	push	OFFSET FLAT:$SG66206
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 696  : 	return (0);

	xor	eax, eax
	jmp	$L66181
$L66205:

; 698  :     g = r + stripsize;

	mov	eax, DWORD PTR _r$[ebp]
	add	eax, DWORD PTR _stripsize$[ebp]
	mov	DWORD PTR _g$[ebp], eax

; 699  :     b = g + stripsize;

	mov	ecx, DWORD PTR _g$[ebp]
	add	ecx, DWORD PTR _stripsize$[ebp]
	mov	DWORD PTR _b$[ebp], ecx

; 700  :     a = b + stripsize;

	mov	edx, DWORD PTR _b$[ebp]
	add	edx, DWORD PTR _stripsize$[ebp]
	mov	DWORD PTR _a$[ebp], edx

; 701  :     if (!alpha)

	cmp	DWORD PTR _alpha$[ebp], 0
	jne	SHORT $L66207

; 702  : 	memset(a, 0xff, stripsize);

	mov	eax, DWORD PTR _stripsize$[ebp]
	push	eax
	push	255					; 000000ffH
	mov	ecx, DWORD PTR _a$[ebp]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH
$L66207:

; 703  :     y = setorientation(img, h);

	mov	edx, DWORD PTR _h$[ebp]
	push	edx
	mov	eax, DWORD PTR _img$[ebp]
	push	eax
	call	_setorientation
	add	esp, 8
	mov	DWORD PTR _y$[ebp], eax

; 704  :     orientation = img->orientation;

	mov	ecx, DWORD PTR _img$[ebp]
	mov	dx, WORD PTR [ecx+28]
	mov	WORD PTR _orientation$[ebp], dx

; 705  :     toskew = -(int32) (orientation == ORIENTATION_TOPLEFT ? w+w : w-w);

	mov	eax, DWORD PTR _orientation$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 1
	jne	SHORT $L68809
	mov	ecx, DWORD PTR _w$[ebp]
	add	ecx, DWORD PTR _w$[ebp]
	mov	DWORD PTR -92+[ebp], ecx
	jmp	SHORT $L68810
$L68809:
	mov	edx, DWORD PTR _w$[ebp]
	sub	edx, DWORD PTR _w$[ebp]
	mov	DWORD PTR -92+[ebp], edx
$L68810:
	mov	eax, DWORD PTR -92+[ebp]
	neg	eax
	mov	DWORD PTR _toskew$[ebp], eax

; 706  :     TIFFGetFieldDefaulted(tif, TIFFTAG_ROWSPERSTRIP, &rowsperstrip);

	lea	ecx, DWORD PTR _rowsperstrip$[ebp]
	push	ecx
	push	278					; 00000116H
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFGetFieldDefaulted
	add	esp, 12					; 0000000cH

; 707  :     scanline = TIFFScanlineSize(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFScanlineSize
	add	esp, 4
	mov	DWORD PTR _scanline$[ebp], eax

; 708  :     fromskew = (w < imagewidth ? imagewidth - w : 0);

	mov	ecx, DWORD PTR _w$[ebp]
	cmp	ecx, DWORD PTR _imagewidth$[ebp]
	jae	SHORT $L68811
	mov	edx, DWORD PTR _imagewidth$[ebp]
	sub	edx, DWORD PTR _w$[ebp]
	mov	DWORD PTR -96+[ebp], edx
	jmp	SHORT $L68812
$L68811:
	mov	DWORD PTR -96+[ebp], 0
$L68812:
	mov	eax, DWORD PTR -96+[ebp]
	mov	DWORD PTR _fromskew$[ebp], eax

; 709  :     for (row = 0; row < h; row += nrow) 

	mov	DWORD PTR _row$[ebp], 0
	jmp	SHORT $L66209
$L66210:
	mov	ecx, DWORD PTR _row$[ebp]
	add	ecx, DWORD PTR _nrow$[ebp]
	mov	DWORD PTR _row$[ebp], ecx
$L66209:
	mov	edx, DWORD PTR _row$[ebp]
	cmp	edx, DWORD PTR _h$[ebp]
	jae	$L66211

; 711  :         rowstoread = rowsperstrip - (row + img->row_offset) % rowsperstrip;    	

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR _row$[ebp]
	add	ecx, DWORD PTR [eax+68]
	mov	eax, ecx
	xor	edx, edx
	div	DWORD PTR _rowsperstrip$[ebp]
	mov	eax, DWORD PTR _rowsperstrip$[ebp]
	sub	eax, edx
	mov	DWORD PTR _rowstoread$[ebp], eax

; 712  :         nrow = (row + rowstoread > h ? h - row : rowstoread);

	mov	ecx, DWORD PTR _row$[ebp]
	add	ecx, DWORD PTR _rowstoread$[ebp]
	cmp	ecx, DWORD PTR _h$[ebp]
	jbe	SHORT $L68813
	mov	edx, DWORD PTR _h$[ebp]
	sub	edx, DWORD PTR _row$[ebp]
	mov	DWORD PTR -100+[ebp], edx
	jmp	SHORT $L68814
$L68813:
	mov	eax, DWORD PTR _rowstoread$[ebp]
	mov	DWORD PTR -100+[ebp], eax
$L68814:
	mov	ecx, DWORD PTR -100+[ebp]
	mov	DWORD PTR _nrow$[ebp], ecx

; 713  :         offset_row = row + img->row_offset;

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	add	eax, DWORD PTR [edx+68]
	mov	DWORD PTR _offset_row$[ebp], eax

; 714  :     	if (TIFFReadEncodedStrip(tif, TIFFComputeStrip(tif, offset_row, 0),
; 715  :                                  r, ((row + img->row_offset)%rowsperstrip + nrow) * scanline) < 0 
; 716  :             && img->stoponerr)

	mov	ecx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	add	eax, DWORD PTR [ecx+68]
	xor	edx, edx
	div	DWORD PTR _rowsperstrip$[ebp]
	add	edx, DWORD PTR _nrow$[ebp]
	imul	edx, DWORD PTR _scanline$[ebp]
	push	edx
	mov	edx, DWORD PTR _r$[ebp]
	push	edx
	push	0
	mov	eax, DWORD PTR _offset_row$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFComputeStrip
	add	esp, 12					; 0000000cH
	push	eax
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFReadEncodedStrip
	add	esp, 16					; 00000010H
	test	eax, eax
	jge	SHORT $L66212
	mov	eax, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [eax+4], 0
	je	SHORT $L66212

; 718  :             ret = 0;

	mov	DWORD PTR _ret$[ebp], 0

; 719  :             break;

	jmp	$L66211
$L66212:

; 721  :         if (TIFFReadEncodedStrip(tif, TIFFComputeStrip(tif, offset_row, 1),
; 722  :                                  g, ((row + img->row_offset)%rowsperstrip + nrow) * scanline) < 0 
; 723  :             && img->stoponerr)

	mov	ecx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	add	eax, DWORD PTR [ecx+68]
	xor	edx, edx
	div	DWORD PTR _rowsperstrip$[ebp]
	add	edx, DWORD PTR _nrow$[ebp]
	imul	edx, DWORD PTR _scanline$[ebp]
	push	edx
	mov	edx, DWORD PTR _g$[ebp]
	push	edx
	push	1
	mov	eax, DWORD PTR _offset_row$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFComputeStrip
	add	esp, 12					; 0000000cH
	push	eax
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFReadEncodedStrip
	add	esp, 16					; 00000010H
	test	eax, eax
	jge	SHORT $L66213
	mov	eax, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [eax+4], 0
	je	SHORT $L66213

; 725  :             ret = 0;

	mov	DWORD PTR _ret$[ebp], 0

; 726  :             break;

	jmp	$L66211
$L66213:

; 728  :         if (TIFFReadEncodedStrip(tif, TIFFComputeStrip(tif, offset_row, 2),
; 729  :                                  b, ((row + img->row_offset)%rowsperstrip + nrow) * scanline) < 0 
; 730  :             && img->stoponerr)

	mov	ecx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	add	eax, DWORD PTR [ecx+68]
	xor	edx, edx
	div	DWORD PTR _rowsperstrip$[ebp]
	add	edx, DWORD PTR _nrow$[ebp]
	imul	edx, DWORD PTR _scanline$[ebp]
	push	edx
	mov	edx, DWORD PTR _b$[ebp]
	push	edx
	push	2
	mov	eax, DWORD PTR _offset_row$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFComputeStrip
	add	esp, 12					; 0000000cH
	push	eax
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFReadEncodedStrip
	add	esp, 16					; 00000010H
	test	eax, eax
	jge	SHORT $L66214
	mov	eax, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [eax+4], 0
	je	SHORT $L66214

; 732  :             ret = 0;

	mov	DWORD PTR _ret$[ebp], 0

; 733  :             break;

	jmp	$L66211
$L66214:

; 735  :         if (alpha &&
; 736  :             (TIFFReadEncodedStrip(tif, TIFFComputeStrip(tif, offset_row, 3),
; 737  :                                   a, ((row + img->row_offset)%rowsperstrip + nrow) * scanline) < 0 
; 738  :              && img->stoponerr))

	cmp	DWORD PTR _alpha$[ebp], 0
	je	SHORT $L66215
	mov	ecx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	add	eax, DWORD PTR [ecx+68]
	xor	edx, edx
	div	DWORD PTR _rowsperstrip$[ebp]
	add	edx, DWORD PTR _nrow$[ebp]
	imul	edx, DWORD PTR _scanline$[ebp]
	push	edx
	mov	edx, DWORD PTR _a$[ebp]
	push	edx
	push	3
	mov	eax, DWORD PTR _offset_row$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFComputeStrip
	add	esp, 12					; 0000000cH
	push	eax
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFReadEncodedStrip
	add	esp, 16					; 00000010H
	test	eax, eax
	jge	SHORT $L66215
	mov	eax, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [eax+4], 0
	je	SHORT $L66215

; 740  :             ret = 0;

	mov	DWORD PTR _ret$[ebp], 0

; 741  :             break;

	jmp	$L66211
$L66215:

; 743  : 
; 744  :         pos = ((row + img->row_offset) % rowsperstrip) * scanline;

	mov	ecx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR _row$[ebp]
	add	eax, DWORD PTR [ecx+68]
	xor	edx, edx
	div	DWORD PTR _rowsperstrip$[ebp]
	imul	edx, DWORD PTR _scanline$[ebp]
	mov	DWORD PTR _pos$[ebp], edx

; 745  :         (*put)(img, raster+y*w, 0, y, w, nrow, fromskew, toskew, r + pos, g + pos, 
; 746  :                b + pos, a + pos);

	mov	edx, DWORD PTR _a$[ebp]
	add	edx, DWORD PTR _pos$[ebp]
	push	edx
	mov	eax, DWORD PTR _b$[ebp]
	add	eax, DWORD PTR _pos$[ebp]
	push	eax
	mov	ecx, DWORD PTR _g$[ebp]
	add	ecx, DWORD PTR _pos$[ebp]
	push	ecx
	mov	edx, DWORD PTR _r$[ebp]
	add	edx, DWORD PTR _pos$[ebp]
	push	edx
	mov	eax, DWORD PTR _toskew$[ebp]
	push	eax
	mov	ecx, DWORD PTR _fromskew$[ebp]
	push	ecx
	mov	edx, DWORD PTR _nrow$[ebp]
	push	edx
	mov	eax, DWORD PTR _w$[ebp]
	push	eax
	mov	ecx, DWORD PTR _y$[ebp]
	push	ecx
	push	0
	mov	edx, DWORD PTR _y$[ebp]
	imul	edx, DWORD PTR _w$[ebp]
	mov	eax, DWORD PTR _raster$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	push	ecx
	mov	edx, DWORD PTR _img$[ebp]
	push	edx
	call	DWORD PTR _put$[ebp]
	add	esp, 48					; 00000030H

; 747  :         y += (orientation == ORIENTATION_TOPLEFT ? -(int32) nrow : (int32) nrow);

	mov	eax, DWORD PTR _orientation$[ebp]
	and	eax, 65535				; 0000ffffH
	cmp	eax, 1
	jne	SHORT $L68815
	mov	ecx, DWORD PTR _nrow$[ebp]
	neg	ecx
	mov	DWORD PTR -104+[ebp], ecx
	jmp	SHORT $L68816
$L68815:
	mov	edx, DWORD PTR _nrow$[ebp]
	mov	DWORD PTR -104+[ebp], edx
$L68816:
	mov	eax, DWORD PTR _y$[ebp]
	add	eax, DWORD PTR -104+[ebp]
	mov	DWORD PTR _y$[ebp], eax

; 748  :     }

	jmp	$L66210
$L66211:

; 749  :     _TIFFfree(buf);

	mov	ecx, DWORD PTR _buf$[ebp]
	push	ecx
	call	__TIFFfree
	add	esp, 4

; 750  :     return (ret);

	mov	eax, DWORD PTR _ret$[ebp]
$L66181:

; 751  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_gtStripSeparate ENDP
_img$ = 8
_put$ = -4
_pickTileContigCase PROC NEAR

; 2159 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 20					; 00000014H

; 2160 :     tileContigRoutine put = 0;

	mov	DWORD PTR _put$[ebp], 0

; 2161 : 
; 2162 :     if (buildMap(img)) {

	mov	eax, DWORD PTR _img$[ebp]
	push	eax
	call	_buildMap
	add	esp, 4
	test	eax, eax
	je	$L68631

; 2163 : 	switch (img->photometric) {

	mov	ecx, DWORD PTR _img$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+30]
	mov	DWORD PTR -8+[ebp], edx
	cmp	DWORD PTR -8+[ebp], 6
	ja	$L68631
	mov	eax, DWORD PTR -8+[ebp]
	jmp	DWORD PTR $L68818[eax*4]
$L68634:

; 2164 : 	case PHOTOMETRIC_RGB:
; 2165 : 	    switch (img->bitspersample) {

	mov	ecx, DWORD PTR _img$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+24]
	mov	DWORD PTR -12+[ebp], edx
	cmp	DWORD PTR -12+[ebp], 8
	je	SHORT $L68639
	cmp	DWORD PTR -12+[ebp], 16			; 00000010H
	je	SHORT $L68646
	jmp	SHORT $L68636
$L68639:

; 2166 : 	    case 8:
; 2167 : 		if (!img->Map) {

	mov	eax, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [eax+52], 0
	jne	SHORT $L68640

; 2168 : 		    if (img->alpha == EXTRASAMPLE_ASSOCALPHA)

	mov	ecx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [ecx+12], 1
	jne	SHORT $L68641

; 2169 : 			put = putRGBAAcontig8bittile;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_putRGBAAcontig8bittile

; 2170 : 		    else if (img->alpha == EXTRASAMPLE_UNASSALPHA)

	jmp	SHORT $L68644
$L68641:
	mov	edx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [edx+12], 2
	jne	SHORT $L68643

; 2171 : 			put = putRGBUAcontig8bittile;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_putRGBUAcontig8bittile

; 2172 : 		    else

	jmp	SHORT $L68644
$L68643:

; 2173 : 			put = putRGBcontig8bittile;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_putRGBcontig8bittile
$L68644:

; 2174 : 		} else

	jmp	SHORT $L68645
$L68640:

; 2175 : 		    put = putRGBcontig8bitMaptile;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_putRGBcontig8bitMaptile
$L68645:

; 2176 : 		break;

	jmp	SHORT $L68636
$L68646:

; 2177 : 	    case 16:
; 2178 : 		put = putRGBcontig16bittile;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_putRGBcontig16bittile

; 2179 : 		if (!img->Map) {

	mov	eax, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [eax+52], 0
	jne	SHORT $L68650

; 2180 : 		    if (img->alpha == EXTRASAMPLE_ASSOCALPHA)

	mov	ecx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [ecx+12], 1
	jne	SHORT $L68648

; 2181 : 			put = putRGBAAcontig16bittile;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_putRGBAAcontig16bittile

; 2182 : 		    else if (img->alpha == EXTRASAMPLE_UNASSALPHA)

	jmp	SHORT $L68650
$L68648:
	mov	edx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [edx+12], 2
	jne	SHORT $L68650

; 2183 : 			put = putRGBUAcontig16bittile;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_putRGBUAcontig16bittile
$L68650:
$L68636:

; 2187 : 	    break;

	jmp	$L68631
$L68651:

; 2188 : 	case PHOTOMETRIC_SEPARATED:
; 2189 : 	    if (img->bitspersample == 8) {

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+24]
	cmp	ecx, 8
	jne	SHORT $L68654

; 2190 : 		if (!img->Map)

	mov	edx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [edx+52], 0
	jne	SHORT $L68653

; 2191 : 		    put = putRGBcontig8bitCMYKtile;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_putRGBcontig8bitCMYKtile

; 2192 : 		else

	jmp	SHORT $L68654
$L68653:

; 2193 : 		    put = putRGBcontig8bitCMYKMaptile;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_putRGBcontig8bitCMYKMaptile
$L68654:

; 2195 : 	    break;

	jmp	$L68631
$L68655:

; 2196 : 	case PHOTOMETRIC_PALETTE:
; 2197 : 	    switch (img->bitspersample) {

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+24]
	mov	DWORD PTR -16+[ebp], ecx
	mov	edx, DWORD PTR -16+[ebp]
	sub	edx, 1
	mov	DWORD PTR -16+[ebp], edx
	cmp	DWORD PTR -16+[ebp], 7
	ja	SHORT $L68657
	mov	eax, DWORD PTR -16+[ebp]
	jmp	DWORD PTR $L68819[eax*4]
$L68660:

; 2198 : 	    case 8:	put = put8bitcmaptile; break;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_put8bitcmaptile
	jmp	SHORT $L68657
$L68661:

; 2199 : 	    case 4: put = put4bitcmaptile; break;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_put4bitcmaptile
	jmp	SHORT $L68657
$L68662:

; 2200 : 	    case 2: put = put2bitcmaptile; break;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_put2bitcmaptile
	jmp	SHORT $L68657
$L68663:

; 2201 : 	    case 1: put = put1bitcmaptile; break;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_put1bitcmaptile
$L68657:

; 2203 : 	    break;

	jmp	SHORT $L68631
$L68664:

; 2204 : 	case PHOTOMETRIC_MINISWHITE:
; 2205 : 	case PHOTOMETRIC_MINISBLACK:
; 2206 : 	    switch (img->bitspersample) {

	mov	ecx, DWORD PTR _img$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+24]
	mov	DWORD PTR -20+[ebp], edx
	mov	eax, DWORD PTR -20+[ebp]
	sub	eax, 1
	mov	DWORD PTR -20+[ebp], eax
	cmp	DWORD PTR -20+[ebp], 15			; 0000000fH
	ja	SHORT $L68666
	mov	edx, DWORD PTR -20+[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR $L68820[edx]
	jmp	DWORD PTR $L68821[ecx*4]
$L68669:

; 2207 :             case 16: put = put16bitbwtile; break;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_put16bitbwtile
	jmp	SHORT $L68666
$L68670:

; 2208 : 	    case 8:  put = putgreytile; break;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_putgreytile
	jmp	SHORT $L68666
$L68671:

; 2209 : 	    case 4:  put = put4bitbwtile; break;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_put4bitbwtile
	jmp	SHORT $L68666
$L68672:

; 2210 : 	    case 2:  put = put2bitbwtile; break;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_put2bitbwtile
	jmp	SHORT $L68666
$L68673:

; 2211 : 	    case 1:  put = put1bitbwtile; break;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_put1bitbwtile
$L68666:

; 2213 : 	    break;

	jmp	SHORT $L68631
$L68674:

; 2214 : 	case PHOTOMETRIC_YCBCR:
; 2215 : 	    if (img->bitspersample == 8)

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+24]
	cmp	ecx, 8
	jne	SHORT $L68675

; 2216 : 		put = initYCbCrConversion(img);

	mov	edx, DWORD PTR _img$[ebp]
	push	edx
	call	_initYCbCrConversion
	add	esp, 4
	mov	DWORD PTR _put$[ebp], eax
$L68675:
$L68631:

; 2220 :     return ((img->put.contig = put) != 0);

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR _put$[ebp]
	mov	DWORD PTR [eax+48], ecx
	xor	eax, eax
	cmp	DWORD PTR _put$[ebp], 0
	setne	al

; 2221 : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68818:
	DD	$L68664
	DD	$L68664
	DD	$L68634
	DD	$L68655
	DD	$L68631
	DD	$L68651
	DD	$L68674
$L68819:
	DD	$L68663
	DD	$L68662
	DD	$L68657
	DD	$L68661
	DD	$L68657
	DD	$L68657
	DD	$L68657
	DD	$L68660
$L68821:
	DD	$L68673
	DD	$L68672
	DD	$L68671
	DD	$L68670
	DD	$L68669
	DD	$L68666
$L68820:
	DB	0
	DB	1
	DB	5
	DB	2
	DB	5
	DB	5
	DB	5
	DB	3
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	4
_pickTileContigCase ENDP
_img$ = 8
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_PALmap$ = -4
_samplesperpixel$ = -8
_put8bitcmaptile PROC NEAR

; 837  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 838  :     uint32** PALmap = img->PALmap;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	mov	DWORD PTR _PALmap$[ebp], ecx

; 839  :     int samplesperpixel = img->samplesperpixel;

	mov	edx, DWORD PTR _img$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+26]
	mov	DWORD PTR _samplesperpixel$[ebp], eax
$L66260:

; 840  : 
; 841  :     (void) y;
; 842  :     while (h-- > 0) {

	mov	ecx, DWORD PTR _h$[ebp]
	mov	edx, DWORD PTR _h$[ebp]
	sub	edx, 1
	mov	DWORD PTR _h$[ebp], edx
	test	ecx, ecx
	jbe	SHORT $L66261

; 843  : 	for (x = w; x-- > 0;)

	mov	eax, DWORD PTR _w$[ebp]
	mov	DWORD PTR _x$[ebp], eax
$L66263:
	mov	ecx, DWORD PTR _x$[ebp]
	mov	edx, DWORD PTR _x$[ebp]
	sub	edx, 1
	mov	DWORD PTR _x$[ebp], edx
	test	ecx, ecx
	jbe	SHORT $L66264

; 845  : 	    *cp++ = PALmap[*pp][0];

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _PALmap$[ebp]
	mov	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR [eax]
	mov	DWORD PTR [ecx], edx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax

; 846  :             pp += samplesperpixel;

	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx

; 847  :         }

	jmp	SHORT $L66263
$L66264:

; 848  : 	cp += toskew;

	mov	edx, DWORD PTR _toskew$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp$[ebp], ecx

; 849  : 	pp += fromskew;

	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], edx

; 850  :     }

	jmp	SHORT $L66260
$L66261:

; 851  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_put8bitcmaptile ENDP
_img$ = 8
_cp$ = 12
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_PALmap$ = -4
_bw$66291 = -8
__x$66292 = -12
_put4bitcmaptile PROC NEAR

; 857  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 858  :     uint32** PALmap = img->PALmap;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	mov	DWORD PTR _PALmap$[ebp], ecx

; 859  : 
; 860  :     (void) x; (void) y;
; 861  :     fromskew /= 2;

	mov	eax, DWORD PTR _fromskew$[ebp]
	cdq
	sub	eax, edx
	sar	eax, 1
	mov	DWORD PTR _fromskew$[ebp], eax
$L66289:

; 862  :     while (h-- > 0) {

	mov	edx, DWORD PTR _h$[ebp]
	mov	eax, DWORD PTR _h$[ebp]
	sub	eax, 1
	mov	DWORD PTR _h$[ebp], eax
	test	edx, edx
	jbe	$L66290

; 863  : 	uint32* bw;
; 864  : 	UNROLL2(w, bw = PALmap[*pp++], *cp++ = *bw++);

	mov	ecx, DWORD PTR _w$[ebp]
	mov	DWORD PTR __x$66292[ebp], ecx
	jmp	SHORT $L66293
$L66294:
	mov	edx, DWORD PTR __x$66292[ebp]
	sub	edx, 2
	mov	DWORD PTR __x$66292[ebp], edx
$L66293:
	cmp	DWORD PTR __x$66292[ebp], 2
	jb	SHORT $L66295
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _PALmap$[ebp]
	mov	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _bw$66291[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _pp$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66291[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66291[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66291[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR _bw$66291[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _bw$66291[ebp]
	add	edx, 4
	mov	DWORD PTR _bw$66291[ebp], edx
	jmp	SHORT $L66294
$L66295:
	cmp	DWORD PTR __x$66292[ebp], 0
	je	SHORT $L66296
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _PALmap$[ebp]
	mov	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _bw$66291[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _pp$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66291[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66291[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66291[ebp], eax
$L66296:

; 865  : 	cp += toskew;

	mov	ecx, DWORD PTR _toskew$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp$[ebp], eax

; 866  : 	pp += fromskew;

	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx

; 867  :     }

	jmp	$L66289
$L66290:

; 868  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_put4bitcmaptile ENDP
_img$ = 8
_cp$ = 12
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_PALmap$ = -4
_bw$66323 = -8
__x$66324 = -12
_put2bitcmaptile PROC NEAR

; 874  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 875  :     uint32** PALmap = img->PALmap;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	mov	DWORD PTR _PALmap$[ebp], ecx

; 876  : 
; 877  :     (void) x; (void) y;
; 878  :     fromskew /= 4;

	mov	eax, DWORD PTR _fromskew$[ebp]
	cdq
	and	edx, 3
	add	eax, edx
	sar	eax, 2
	mov	DWORD PTR _fromskew$[ebp], eax
$L66321:

; 879  :     while (h-- > 0) {

	mov	edx, DWORD PTR _h$[ebp]
	mov	eax, DWORD PTR _h$[ebp]
	sub	eax, 1
	mov	DWORD PTR _h$[ebp], eax
	test	edx, edx
	jbe	$L66322

; 880  : 	uint32* bw;
; 881  : 	UNROLL4(w, bw = PALmap[*pp++], *cp++ = *bw++);

	mov	ecx, DWORD PTR _w$[ebp]
	mov	DWORD PTR __x$66324[ebp], ecx
	jmp	SHORT $L66325
$L66326:
	mov	edx, DWORD PTR __x$66324[ebp]
	sub	edx, 4
	mov	DWORD PTR __x$66324[ebp], edx
$L66325:
	cmp	DWORD PTR __x$66324[ebp], 4
	jb	$L66327
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _PALmap$[ebp]
	mov	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _bw$66323[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _pp$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66323[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66323[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66323[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR _bw$66323[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _bw$66323[ebp]
	add	edx, 4
	mov	DWORD PTR _bw$66323[ebp], edx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	ecx, DWORD PTR _bw$66323[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _bw$66323[ebp]
	add	ecx, 4
	mov	DWORD PTR _bw$66323[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66323[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66323[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66323[ebp], eax
	jmp	$L66326
$L66327:
	cmp	DWORD PTR __x$66324[ebp], 0
	jbe	$L66330
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _PALmap$[ebp]
	mov	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _bw$66323[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, 1
	mov	DWORD PTR _pp$[ebp], edx
	mov	eax, DWORD PTR __x$66324[ebp]
	mov	DWORD PTR -16+[ebp], eax
	cmp	DWORD PTR -16+[ebp], 1
	je	SHORT $L66335
	cmp	DWORD PTR -16+[ebp], 2
	je	SHORT $L66334
	cmp	DWORD PTR -16+[ebp], 3
	je	SHORT $L66333
	jmp	SHORT $L66330
$L66333:
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR _bw$66323[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _bw$66323[ebp]
	add	edx, 4
	mov	DWORD PTR _bw$66323[ebp], edx
$L66334:
	mov	eax, DWORD PTR _cp$[ebp]
	mov	ecx, DWORD PTR _bw$66323[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _bw$66323[ebp]
	add	ecx, 4
	mov	DWORD PTR _bw$66323[ebp], ecx
$L66335:
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66323[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66323[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66323[ebp], eax
$L66330:

; 882  : 	cp += toskew;

	mov	ecx, DWORD PTR _toskew$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp$[ebp], eax

; 883  : 	pp += fromskew;

	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx

; 884  :     }

	jmp	$L66321
$L66322:

; 885  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_put2bitcmaptile ENDP
_img$ = 8
_cp$ = 12
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_PALmap$ = -4
_bw$66362 = -8
__x$66363 = -12
_put1bitcmaptile PROC NEAR

; 891  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 892  :     uint32** PALmap = img->PALmap;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+60]
	mov	DWORD PTR _PALmap$[ebp], ecx

; 893  : 
; 894  :     (void) x; (void) y;
; 895  :     fromskew /= 8;

	mov	eax, DWORD PTR _fromskew$[ebp]
	cdq
	and	edx, 7
	add	eax, edx
	sar	eax, 3
	mov	DWORD PTR _fromskew$[ebp], eax
$L66360:

; 896  :     while (h-- > 0) {

	mov	edx, DWORD PTR _h$[ebp]
	mov	eax, DWORD PTR _h$[ebp]
	sub	eax, 1
	mov	DWORD PTR _h$[ebp], eax
	test	edx, edx
	jbe	$L66361

; 897  : 	uint32* bw;
; 898  : 	UNROLL8(w, bw = PALmap[*pp++], *cp++ = *bw++);

	mov	ecx, DWORD PTR _w$[ebp]
	mov	DWORD PTR __x$66363[ebp], ecx
	jmp	SHORT $L66364
$L66365:
	mov	edx, DWORD PTR __x$66363[ebp]
	sub	edx, 8
	mov	DWORD PTR __x$66363[ebp], edx
$L66364:
	cmp	DWORD PTR __x$66363[ebp], 8
	jb	$L66366
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _PALmap$[ebp]
	mov	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _bw$66362[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _pp$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66362[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66362[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66362[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR _bw$66362[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _bw$66362[ebp]
	add	edx, 4
	mov	DWORD PTR _bw$66362[ebp], edx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	ecx, DWORD PTR _bw$66362[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _bw$66362[ebp]
	add	ecx, 4
	mov	DWORD PTR _bw$66362[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66362[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66362[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66362[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR _bw$66362[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _bw$66362[ebp]
	add	edx, 4
	mov	DWORD PTR _bw$66362[ebp], edx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	ecx, DWORD PTR _bw$66362[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _bw$66362[ebp]
	add	ecx, 4
	mov	DWORD PTR _bw$66362[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66362[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66362[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66362[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR _bw$66362[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _bw$66362[ebp]
	add	edx, 4
	mov	DWORD PTR _bw$66362[ebp], edx
	jmp	$L66365
$L66366:
	cmp	DWORD PTR __x$66363[ebp], 0
	jbe	$L66369
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _PALmap$[ebp]
	mov	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _bw$66362[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _pp$[ebp], ecx
	mov	edx, DWORD PTR __x$66363[ebp]
	mov	DWORD PTR -16+[ebp], edx
	mov	eax, DWORD PTR -16+[ebp]
	sub	eax, 1
	mov	DWORD PTR -16+[ebp], eax
	cmp	DWORD PTR -16+[ebp], 6
	ja	$L66369
	mov	ecx, DWORD PTR -16+[ebp]
	jmp	DWORD PTR $L68826[ecx*4]
$L66372:
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66362[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66362[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66362[ebp], eax
$L66373:
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR _bw$66362[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _bw$66362[ebp]
	add	edx, 4
	mov	DWORD PTR _bw$66362[ebp], edx
$L66374:
	mov	eax, DWORD PTR _cp$[ebp]
	mov	ecx, DWORD PTR _bw$66362[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _bw$66362[ebp]
	add	ecx, 4
	mov	DWORD PTR _bw$66362[ebp], ecx
$L66375:
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66362[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66362[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66362[ebp], eax
$L66376:
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR _bw$66362[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _bw$66362[ebp]
	add	edx, 4
	mov	DWORD PTR _bw$66362[ebp], edx
$L66377:
	mov	eax, DWORD PTR _cp$[ebp]
	mov	ecx, DWORD PTR _bw$66362[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _bw$66362[ebp]
	add	ecx, 4
	mov	DWORD PTR _bw$66362[ebp], ecx
$L66378:
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66362[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66362[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66362[ebp], eax
$L66369:

; 899  : 	cp += toskew;

	mov	ecx, DWORD PTR _toskew$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp$[ebp], eax

; 900  : 	pp += fromskew;

	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx

; 901  :     }

	jmp	$L66360
$L66361:

; 902  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68826:
	DD	$L66378
	DD	$L66377
	DD	$L66376
	DD	$L66375
	DD	$L66374
	DD	$L66373
	DD	$L66372
_put1bitcmaptile ENDP
_img$ = 8
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_samplesperpixel$ = -8
_BWmap$ = -4
_putgreytile PROC NEAR

; 908  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 909  :     int samplesperpixel = img->samplesperpixel;

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+26]
	mov	DWORD PTR _samplesperpixel$[ebp], ecx

; 910  :     uint32** BWmap = img->BWmap;

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	DWORD PTR _BWmap$[ebp], eax
$L66403:

; 911  : 
; 912  :     (void) y;
; 913  :     while (h-- > 0) {

	mov	ecx, DWORD PTR _h$[ebp]
	mov	edx, DWORD PTR _h$[ebp]
	sub	edx, 1
	mov	DWORD PTR _h$[ebp], edx
	test	ecx, ecx
	jbe	SHORT $L66404

; 914  : 	for (x = w; x-- > 0;)

	mov	eax, DWORD PTR _w$[ebp]
	mov	DWORD PTR _x$[ebp], eax
$L66406:
	mov	ecx, DWORD PTR _x$[ebp]
	mov	edx, DWORD PTR _x$[ebp]
	sub	edx, 1
	mov	DWORD PTR _x$[ebp], edx
	test	ecx, ecx
	jbe	SHORT $L66407

; 916  : 	    *cp++ = BWmap[*pp][0];

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _BWmap$[ebp]
	mov	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR [eax]
	mov	DWORD PTR [ecx], edx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax

; 917  :             pp += samplesperpixel;

	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx

; 918  :         }

	jmp	SHORT $L66406
$L66407:

; 919  : 	cp += toskew;

	mov	edx, DWORD PTR _toskew$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp$[ebp], ecx

; 920  : 	pp += fromskew;

	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], edx

; 921  :     }

	jmp	SHORT $L66403
$L66404:

; 922  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_putgreytile ENDP
_img$ = 8
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_samplesperpixel$ = -8
_BWmap$ = -4
_wp$66434 = -12
_put16bitbwtile PROC NEAR

; 928  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 929  :     int samplesperpixel = img->samplesperpixel;

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+26]
	mov	DWORD PTR _samplesperpixel$[ebp], ecx

; 930  :     uint32** BWmap = img->BWmap;

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	DWORD PTR _BWmap$[ebp], eax
$L66432:

; 931  : 
; 932  :     (void) y;
; 933  :     while (h-- > 0) {

	mov	ecx, DWORD PTR _h$[ebp]
	mov	edx, DWORD PTR _h$[ebp]
	sub	edx, 1
	mov	DWORD PTR _h$[ebp], edx
	test	ecx, ecx
	jbe	SHORT $L66433

; 934  :         uint16 *wp = (uint16 *) pp;

	mov	eax, DWORD PTR _pp$[ebp]
	mov	DWORD PTR _wp$66434[ebp], eax

; 935  : 
; 936  : 	for (x = w; x-- > 0;)

	mov	ecx, DWORD PTR _w$[ebp]
	mov	DWORD PTR _x$[ebp], ecx
$L66437:
	mov	edx, DWORD PTR _x$[ebp]
	mov	eax, DWORD PTR _x$[ebp]
	sub	eax, 1
	mov	DWORD PTR _x$[ebp], eax
	test	edx, edx
	jbe	SHORT $L66438

; 938  :             /* use high order byte of 16bit value */
; 939  : 
; 940  : 	    *cp++ = BWmap[*wp >> 8][0];

	mov	ecx, DWORD PTR _wp$66434[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx]
	sar	edx, 8
	mov	eax, DWORD PTR _BWmap$[ebp]
	mov	ecx, DWORD PTR [eax+edx*4]
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR [ecx]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx

; 941  :             pp += 2 * samplesperpixel;

	mov	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	eax, DWORD PTR _pp$[ebp]
	lea	ecx, DWORD PTR [eax+edx*2]
	mov	DWORD PTR _pp$[ebp], ecx

; 942  :             wp += samplesperpixel;

	mov	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	eax, DWORD PTR _wp$66434[ebp]
	lea	ecx, DWORD PTR [eax+edx*2]
	mov	DWORD PTR _wp$66434[ebp], ecx

; 943  :         }

	jmp	SHORT $L66437
$L66438:

; 944  : 	cp += toskew;

	mov	edx, DWORD PTR _toskew$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp$[ebp], ecx

; 945  : 	pp += fromskew;

	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], edx

; 946  :     }

	jmp	SHORT $L66432
$L66433:

; 947  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_put16bitbwtile ENDP
_img$ = 8
_cp$ = 12
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_BWmap$ = -4
_bw$66465 = -8
__x$66466 = -12
_put1bitbwtile PROC NEAR

; 953  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 954  :     uint32** BWmap = img->BWmap;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	DWORD PTR _BWmap$[ebp], ecx

; 955  : 
; 956  :     (void) x; (void) y;
; 957  :     fromskew /= 8;

	mov	eax, DWORD PTR _fromskew$[ebp]
	cdq
	and	edx, 7
	add	eax, edx
	sar	eax, 3
	mov	DWORD PTR _fromskew$[ebp], eax
$L66463:

; 958  :     while (h-- > 0) {

	mov	edx, DWORD PTR _h$[ebp]
	mov	eax, DWORD PTR _h$[ebp]
	sub	eax, 1
	mov	DWORD PTR _h$[ebp], eax
	test	edx, edx
	jbe	$L66464

; 959  : 	uint32* bw;
; 960  : 	UNROLL8(w, bw = BWmap[*pp++], *cp++ = *bw++);

	mov	ecx, DWORD PTR _w$[ebp]
	mov	DWORD PTR __x$66466[ebp], ecx
	jmp	SHORT $L66467
$L66468:
	mov	edx, DWORD PTR __x$66466[ebp]
	sub	edx, 8
	mov	DWORD PTR __x$66466[ebp], edx
$L66467:
	cmp	DWORD PTR __x$66466[ebp], 8
	jb	$L66469
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _BWmap$[ebp]
	mov	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _bw$66465[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _pp$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66465[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66465[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66465[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR _bw$66465[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _bw$66465[ebp]
	add	edx, 4
	mov	DWORD PTR _bw$66465[ebp], edx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	ecx, DWORD PTR _bw$66465[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _bw$66465[ebp]
	add	ecx, 4
	mov	DWORD PTR _bw$66465[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66465[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66465[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66465[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR _bw$66465[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _bw$66465[ebp]
	add	edx, 4
	mov	DWORD PTR _bw$66465[ebp], edx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	ecx, DWORD PTR _bw$66465[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _bw$66465[ebp]
	add	ecx, 4
	mov	DWORD PTR _bw$66465[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66465[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66465[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66465[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR _bw$66465[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _bw$66465[ebp]
	add	edx, 4
	mov	DWORD PTR _bw$66465[ebp], edx
	jmp	$L66468
$L66469:
	cmp	DWORD PTR __x$66466[ebp], 0
	jbe	$L66472
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _BWmap$[ebp]
	mov	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _bw$66465[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _pp$[ebp], ecx
	mov	edx, DWORD PTR __x$66466[ebp]
	mov	DWORD PTR -16+[ebp], edx
	mov	eax, DWORD PTR -16+[ebp]
	sub	eax, 1
	mov	DWORD PTR -16+[ebp], eax
	cmp	DWORD PTR -16+[ebp], 6
	ja	$L66472
	mov	ecx, DWORD PTR -16+[ebp]
	jmp	DWORD PTR $L68830[ecx*4]
$L66475:
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66465[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66465[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66465[ebp], eax
$L66476:
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR _bw$66465[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _bw$66465[ebp]
	add	edx, 4
	mov	DWORD PTR _bw$66465[ebp], edx
$L66477:
	mov	eax, DWORD PTR _cp$[ebp]
	mov	ecx, DWORD PTR _bw$66465[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _bw$66465[ebp]
	add	ecx, 4
	mov	DWORD PTR _bw$66465[ebp], ecx
$L66478:
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66465[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66465[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66465[ebp], eax
$L66479:
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR _bw$66465[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _bw$66465[ebp]
	add	edx, 4
	mov	DWORD PTR _bw$66465[ebp], edx
$L66480:
	mov	eax, DWORD PTR _cp$[ebp]
	mov	ecx, DWORD PTR _bw$66465[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _bw$66465[ebp]
	add	ecx, 4
	mov	DWORD PTR _bw$66465[ebp], ecx
$L66481:
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66465[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66465[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66465[ebp], eax
$L66472:

; 961  : 	cp += toskew;

	mov	ecx, DWORD PTR _toskew$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp$[ebp], eax

; 962  : 	pp += fromskew;

	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx

; 963  :     }

	jmp	$L66463
$L66464:

; 964  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68830:
	DD	$L66481
	DD	$L66480
	DD	$L66479
	DD	$L66478
	DD	$L66477
	DD	$L66476
	DD	$L66475
_put1bitbwtile ENDP
_img$ = 8
_cp$ = 12
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_BWmap$ = -4
_bw$66508 = -8
__x$66509 = -12
_put2bitbwtile PROC NEAR

; 970  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 971  :     uint32** BWmap = img->BWmap;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	DWORD PTR _BWmap$[ebp], ecx

; 972  : 
; 973  :     (void) x; (void) y;
; 974  :     fromskew /= 4;

	mov	eax, DWORD PTR _fromskew$[ebp]
	cdq
	and	edx, 3
	add	eax, edx
	sar	eax, 2
	mov	DWORD PTR _fromskew$[ebp], eax
$L66506:

; 975  :     while (h-- > 0) {

	mov	edx, DWORD PTR _h$[ebp]
	mov	eax, DWORD PTR _h$[ebp]
	sub	eax, 1
	mov	DWORD PTR _h$[ebp], eax
	test	edx, edx
	jbe	$L66507

; 976  : 	uint32* bw;
; 977  : 	UNROLL4(w, bw = BWmap[*pp++], *cp++ = *bw++);

	mov	ecx, DWORD PTR _w$[ebp]
	mov	DWORD PTR __x$66509[ebp], ecx
	jmp	SHORT $L66510
$L66511:
	mov	edx, DWORD PTR __x$66509[ebp]
	sub	edx, 4
	mov	DWORD PTR __x$66509[ebp], edx
$L66510:
	cmp	DWORD PTR __x$66509[ebp], 4
	jb	$L66512
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _BWmap$[ebp]
	mov	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _bw$66508[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _pp$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66508[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66508[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66508[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR _bw$66508[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _bw$66508[ebp]
	add	edx, 4
	mov	DWORD PTR _bw$66508[ebp], edx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	ecx, DWORD PTR _bw$66508[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _bw$66508[ebp]
	add	ecx, 4
	mov	DWORD PTR _bw$66508[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66508[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66508[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66508[ebp], eax
	jmp	$L66511
$L66512:
	cmp	DWORD PTR __x$66509[ebp], 0
	jbe	$L66515
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _BWmap$[ebp]
	mov	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _bw$66508[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, 1
	mov	DWORD PTR _pp$[ebp], edx
	mov	eax, DWORD PTR __x$66509[ebp]
	mov	DWORD PTR -16+[ebp], eax
	cmp	DWORD PTR -16+[ebp], 1
	je	SHORT $L66520
	cmp	DWORD PTR -16+[ebp], 2
	je	SHORT $L66519
	cmp	DWORD PTR -16+[ebp], 3
	je	SHORT $L66518
	jmp	SHORT $L66515
$L66518:
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR _bw$66508[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _bw$66508[ebp]
	add	edx, 4
	mov	DWORD PTR _bw$66508[ebp], edx
$L66519:
	mov	eax, DWORD PTR _cp$[ebp]
	mov	ecx, DWORD PTR _bw$66508[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _bw$66508[ebp]
	add	ecx, 4
	mov	DWORD PTR _bw$66508[ebp], ecx
$L66520:
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66508[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66508[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66508[ebp], eax
$L66515:

; 978  : 	cp += toskew;

	mov	ecx, DWORD PTR _toskew$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp$[ebp], eax

; 979  : 	pp += fromskew;

	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx

; 980  :     }

	jmp	$L66506
$L66507:

; 981  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_put2bitbwtile ENDP
_img$ = 8
_cp$ = 12
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_BWmap$ = -4
_bw$66547 = -8
__x$66548 = -12
_put4bitbwtile PROC NEAR

; 987  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 988  :     uint32** BWmap = img->BWmap;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	DWORD PTR _BWmap$[ebp], ecx

; 989  : 
; 990  :     (void) x; (void) y;
; 991  :     fromskew /= 2;

	mov	eax, DWORD PTR _fromskew$[ebp]
	cdq
	sub	eax, edx
	sar	eax, 1
	mov	DWORD PTR _fromskew$[ebp], eax
$L66545:

; 992  :     while (h-- > 0) {

	mov	edx, DWORD PTR _h$[ebp]
	mov	eax, DWORD PTR _h$[ebp]
	sub	eax, 1
	mov	DWORD PTR _h$[ebp], eax
	test	edx, edx
	jbe	$L66546

; 993  : 	uint32* bw;
; 994  : 	UNROLL2(w, bw = BWmap[*pp++], *cp++ = *bw++);

	mov	ecx, DWORD PTR _w$[ebp]
	mov	DWORD PTR __x$66548[ebp], ecx
	jmp	SHORT $L66549
$L66550:
	mov	edx, DWORD PTR __x$66548[ebp]
	sub	edx, 2
	mov	DWORD PTR __x$66548[ebp], edx
$L66549:
	cmp	DWORD PTR __x$66548[ebp], 2
	jb	SHORT $L66551
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _BWmap$[ebp]
	mov	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _bw$66547[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _pp$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66547[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66547[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66547[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR _bw$66547[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR [ecx], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _bw$66547[ebp]
	add	edx, 4
	mov	DWORD PTR _bw$66547[ebp], edx
	jmp	SHORT $L66550
$L66551:
	cmp	DWORD PTR __x$66548[ebp], 0
	je	SHORT $L66552
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _BWmap$[ebp]
	mov	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _bw$66547[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _pp$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _bw$66547[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _bw$66547[ebp]
	add	eax, 4
	mov	DWORD PTR _bw$66547[ebp], eax
$L66552:

; 995  : 	cp += toskew;

	mov	ecx, DWORD PTR _toskew$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp$[ebp], eax

; 996  : 	pp += fromskew;

	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx

; 997  :     }

	jmp	$L66545
$L66546:

; 998  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_put4bitbwtile ENDP
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_samplesperpixel$ = -4
__x$66579 = -8
_img$ = 8
_cp$ = 12
_putRGBcontig8bittile PROC NEAR

; 1004 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 1005 :     int samplesperpixel = img->samplesperpixel;

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+26]
	mov	DWORD PTR _samplesperpixel$[ebp], ecx

; 1006 : 
; 1007 :     (void) x; (void) y;
; 1008 :     fromskew *= samplesperpixel;

	mov	edx, DWORD PTR _fromskew$[ebp]
	imul	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _fromskew$[ebp], edx
$L66577:

; 1009 :     while (h-- > 0) {

	mov	eax, DWORD PTR _h$[ebp]
	mov	ecx, DWORD PTR _h$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _h$[ebp], ecx
	test	eax, eax
	jbe	$L66578

; 1011 : 	    *cp++ = PACK(pp[0], pp[1], pp[2]);
; 1012 : 	    pp += samplesperpixel);

	mov	edx, DWORD PTR _w$[ebp]
	mov	DWORD PTR __x$66579[ebp], edx
	jmp	SHORT $L66580
$L66581:
	mov	eax, DWORD PTR __x$66579[ebp]
	sub	eax, 8
	mov	DWORD PTR __x$66579[ebp], eax
$L66580:
	cmp	DWORD PTR __x$66579[ebp], 8
	jb	$L66582
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+2]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+2]
	shl	edx, 16					; 00000010H
	or	eax, edx
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+2]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+2]
	shl	edx, 16					; 00000010H
	or	eax, edx
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+2]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx
	jmp	$L66581
$L66582:
	cmp	DWORD PTR __x$66579[ebp], 0
	jbe	$L66617
	mov	edx, DWORD PTR __x$66579[ebp]
	mov	DWORD PTR -12+[ebp], edx
	mov	eax, DWORD PTR -12+[ebp]
	sub	eax, 1
	mov	DWORD PTR -12+[ebp], eax
	cmp	DWORD PTR -12+[ebp], 6
	ja	$L66617
	mov	ecx, DWORD PTR -12+[ebp]
	jmp	DWORD PTR $L68834[ecx*4]
$L66620:
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+2]
	shl	edx, 16					; 00000010H
	or	eax, edx
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], eax
$L66625:
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+2]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
$L66630:
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx
$L66635:
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+2]
	shl	edx, 16					; 00000010H
	or	eax, edx
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], eax
$L66640:
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+2]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
$L66645:
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx
$L66650:
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+2]
	shl	edx, 16					; 00000010H
	or	eax, edx
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], eax
$L66617:

; 1013 : 	cp += toskew;

	mov	ecx, DWORD PTR _toskew$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp$[ebp], eax

; 1014 : 	pp += fromskew;

	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx

; 1015 :     }

	jmp	$L66577
$L66578:

; 1016 : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68834:
	DD	$L66650
	DD	$L66645
	DD	$L66640
	DD	$L66635
	DD	$L66630
	DD	$L66625
	DD	$L66620
_putRGBcontig8bittile ENDP
_img$ = 8
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_Map$ = -8
_samplesperpixel$ = -4
_putRGBcontig8bitMaptile PROC NEAR

; 1022 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8
	push	ebx

; 1023 :     TIFFRGBValue* Map = img->Map;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+52]
	mov	DWORD PTR _Map$[ebp], ecx

; 1024 :     int samplesperpixel = img->samplesperpixel;

	mov	edx, DWORD PTR _img$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+26]
	mov	DWORD PTR _samplesperpixel$[ebp], eax

; 1025 : 
; 1026 :     (void) y;
; 1027 :     fromskew *= samplesperpixel;

	mov	ecx, DWORD PTR _fromskew$[ebp]
	imul	ecx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _fromskew$[ebp], ecx
$L66679:

; 1028 :     while (h-- > 0) {

	mov	edx, DWORD PTR _h$[ebp]
	mov	eax, DWORD PTR _h$[ebp]
	sub	eax, 1
	mov	DWORD PTR _h$[ebp], eax
	test	edx, edx
	jbe	$L66680

; 1029 : 	for (x = w; x-- > 0;) {

	mov	ecx, DWORD PTR _w$[ebp]
	mov	DWORD PTR _x$[ebp], ecx
$L66682:
	mov	edx, DWORD PTR _x$[ebp]
	mov	eax, DWORD PTR _x$[ebp]
	sub	eax, 1
	mov	DWORD PTR _x$[ebp], eax
	test	edx, edx
	jbe	SHORT $L66683

; 1030 : 	    *cp++ = PACK(Map[pp[0]], Map[pp[1]], Map[pp[2]]);

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _Map$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	mov	edx, DWORD PTR _Map$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+2]
	mov	eax, DWORD PTR _Map$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+edx]
	shl	ebx, 16					; 00000010H
	or	ecx, ebx
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax

; 1031 : 	    pp += samplesperpixel;

	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx

; 1032 : 	}

	jmp	SHORT $L66682
$L66683:

; 1033 : 	pp += fromskew;

	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], edx

; 1034 : 	cp += toskew;

	mov	eax, DWORD PTR _toskew$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	lea	edx, DWORD PTR [ecx+eax*4]
	mov	DWORD PTR _cp$[ebp], edx

; 1035 :     }

	jmp	$L66679
$L66680:

; 1036 : }

	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_putRGBcontig8bitMaptile ENDP
_img$ = 8
_cp$ = 12
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_samplesperpixel$ = -4
__x$66714 = -8
_putRGBAAcontig8bittile PROC NEAR

; 1043 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 1044 :     int samplesperpixel = img->samplesperpixel;

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+26]
	mov	DWORD PTR _samplesperpixel$[ebp], ecx

; 1045 : 
; 1046 :     (void) x; (void) y;
; 1047 :     fromskew *= samplesperpixel;

	mov	edx, DWORD PTR _fromskew$[ebp]
	imul	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _fromskew$[ebp], edx
$L66712:

; 1048 :     while (h-- > 0) {

	mov	eax, DWORD PTR _h$[ebp]
	mov	ecx, DWORD PTR _h$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _h$[ebp], ecx
	test	eax, eax
	jbe	$L66713

; 1050 : 	    *cp++ = PACK4(pp[0], pp[1], pp[2], pp[3]);
; 1051 : 	    pp += samplesperpixel);

	mov	edx, DWORD PTR _w$[ebp]
	mov	DWORD PTR __x$66714[ebp], edx
	jmp	SHORT $L66715
$L66716:
	mov	eax, DWORD PTR __x$66714[ebp]
	sub	eax, 8
	mov	DWORD PTR __x$66714[ebp], eax
$L66715:
	cmp	DWORD PTR __x$66714[ebp], 8
	jb	$L66717
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+2]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	shl	ecx, 24					; 00000018H
	or	edx, ecx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+3]
	shl	eax, 24					; 00000018H
	or	ecx, eax
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+2]
	shl	edx, 16					; 00000010H
	or	eax, edx
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+3]
	shl	edx, 24					; 00000018H
	or	eax, edx
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+2]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	shl	ecx, 24					; 00000018H
	or	edx, ecx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+3]
	shl	eax, 24					; 00000018H
	or	ecx, eax
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+2]
	shl	edx, 16					; 00000010H
	or	eax, edx
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+3]
	shl	edx, 24					; 00000018H
	or	eax, edx
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+2]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	shl	ecx, 24					; 00000018H
	or	edx, ecx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+3]
	shl	eax, 24					; 00000018H
	or	ecx, eax
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx
	jmp	$L66716
$L66717:
	cmp	DWORD PTR __x$66714[ebp], 0
	jbe	$L66752
	mov	edx, DWORD PTR __x$66714[ebp]
	mov	DWORD PTR -12+[ebp], edx
	mov	eax, DWORD PTR -12+[ebp]
	sub	eax, 1
	mov	DWORD PTR -12+[ebp], eax
	cmp	DWORD PTR -12+[ebp], 6
	ja	$L66752
	mov	ecx, DWORD PTR -12+[ebp]
	jmp	DWORD PTR $L68837[ecx*4]
$L66755:
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+2]
	shl	edx, 16					; 00000010H
	or	eax, edx
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+3]
	shl	edx, 24					; 00000018H
	or	eax, edx
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], eax
$L66760:
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+2]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	shl	ecx, 24					; 00000018H
	or	edx, ecx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
$L66765:
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+3]
	shl	eax, 24					; 00000018H
	or	ecx, eax
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx
$L66770:
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+2]
	shl	edx, 16					; 00000010H
	or	eax, edx
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+3]
	shl	edx, 24					; 00000018H
	or	eax, edx
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], eax
$L66775:
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+2]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	shl	ecx, 24					; 00000018H
	or	edx, ecx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
$L66780:
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+3]
	shl	eax, 24					; 00000018H
	or	ecx, eax
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx
$L66785:
	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+2]
	shl	edx, 16					; 00000010H
	or	eax, edx
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+3]
	shl	edx, 24					; 00000018H
	or	eax, edx
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], eax
$L66752:

; 1052 : 	cp += toskew;

	mov	ecx, DWORD PTR _toskew$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp$[ebp], eax

; 1053 : 	pp += fromskew;

	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx

; 1054 :     }

	jmp	$L66712
$L66713:

; 1055 : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68837:
	DD	$L66785
	DD	$L66780
	DD	$L66775
	DD	$L66770
	DD	$L66765
	DD	$L66760
	DD	$L66755
_putRGBAAcontig8bittile ENDP
_img$ = 8
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_samplesperpixel$ = -4
_r$66815 = -16
_g$66816 = -20
_b$66817 = -12
_a$66818 = -8
_putRGBUAcontig8bittile PROC NEAR

; 1062 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 20					; 00000014H

; 1063 :     int samplesperpixel = img->samplesperpixel;

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+26]
	mov	DWORD PTR _samplesperpixel$[ebp], ecx

; 1064 : 
; 1065 :     (void) y;
; 1066 :     fromskew *= samplesperpixel;

	mov	edx, DWORD PTR _fromskew$[ebp]
	imul	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _fromskew$[ebp], edx
$L66813:

; 1067 :     while (h-- > 0) {

	mov	eax, DWORD PTR _h$[ebp]
	mov	ecx, DWORD PTR _h$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _h$[ebp], ecx
	test	eax, eax
	jbe	$L66814

; 1068 : 	uint32 r, g, b, a;
; 1069 : 	for (x = w; x-- > 0;) {

	mov	edx, DWORD PTR _w$[ebp]
	mov	DWORD PTR _x$[ebp], edx
$L66820:
	mov	eax, DWORD PTR _x$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _x$[ebp], ecx
	test	eax, eax
	jbe	$L66821

; 1070 : 	    a = pp[3];

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+3]
	mov	DWORD PTR _a$66818[ebp], eax

; 1071 : 	    r = (pp[0] * a) / 255;

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, edx
	imul	eax, DWORD PTR _a$66818[ebp]
	xor	edx, edx
	mov	ecx, 255				; 000000ffH
	div	ecx
	mov	DWORD PTR _r$66815[ebp], eax

; 1072 : 	    g = (pp[1] * a) / 255;

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	imul	eax, DWORD PTR _a$66818[ebp]
	xor	edx, edx
	mov	ecx, 255				; 000000ffH
	div	ecx
	mov	DWORD PTR _g$66816[ebp], eax

; 1073 : 	    b = (pp[2] * a) / 255;

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	imul	eax, DWORD PTR _a$66818[ebp]
	xor	edx, edx
	mov	ecx, 255				; 000000ffH
	div	ecx
	mov	DWORD PTR _b$66817[ebp], eax

; 1074 : 	    *cp++ = PACK4(r,g,b,a);

	mov	edx, DWORD PTR _g$66816[ebp]
	shl	edx, 8
	mov	eax, DWORD PTR _r$66815[ebp]
	or	eax, edx
	mov	ecx, DWORD PTR _b$66817[ebp]
	shl	ecx, 16					; 00000010H
	or	eax, ecx
	mov	edx, DWORD PTR _a$66818[ebp]
	shl	edx, 24					; 00000018H
	or	eax, edx
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx

; 1075 : 	    pp += samplesperpixel;

	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], eax

; 1076 : 	}

	jmp	$L66820
$L66821:

; 1077 : 	cp += toskew;

	mov	ecx, DWORD PTR _toskew$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp$[ebp], eax

; 1078 : 	pp += fromskew;

	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx

; 1079 :     }

	jmp	$L66813
$L66814:

; 1080 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_putRGBUAcontig8bittile ENDP
_img$ = 8
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_samplesperpixel$ = -8
_wp$ = -4
_putRGBcontig16bittile PROC NEAR

; 1086 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 1087 :     int samplesperpixel = img->samplesperpixel;

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+26]
	mov	DWORD PTR _samplesperpixel$[ebp], ecx

; 1088 :     uint16 *wp = (uint16 *)pp;

	mov	edx, DWORD PTR _pp$[ebp]
	mov	DWORD PTR _wp$[ebp], edx

; 1089 : 
; 1090 :     (void) y;
; 1091 :     fromskew *= samplesperpixel;

	mov	eax, DWORD PTR _fromskew$[ebp]
	imul	eax, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _fromskew$[ebp], eax
$L66851:

; 1092 :     while (h-- > 0) {

	mov	ecx, DWORD PTR _h$[ebp]
	mov	edx, DWORD PTR _h$[ebp]
	sub	edx, 1
	mov	DWORD PTR _h$[ebp], edx
	test	ecx, ecx
	jbe	$L66852

; 1093 : 	for (x = w; x-- > 0;) {

	mov	eax, DWORD PTR _w$[ebp]
	mov	DWORD PTR _x$[ebp], eax
$L66854:
	mov	ecx, DWORD PTR _x$[ebp]
	mov	edx, DWORD PTR _x$[ebp]
	sub	edx, 1
	mov	DWORD PTR _x$[ebp], edx
	test	ecx, ecx
	jbe	SHORT $L66855

; 1094 : 	    *cp++ = PACKW(wp[0], wp[1], wp[2]);

	mov	eax, DWORD PTR _wp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	sar	ecx, 8
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _wp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+2]
	sar	eax, 8
	and	eax, 255				; 000000ffH
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _wp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+4]
	sar	eax, 8
	and	eax, 255				; 000000ffH
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax

; 1095 : 	    wp += samplesperpixel;

	mov	ecx, DWORD PTR _samplesperpixel$[ebp]
	mov	edx, DWORD PTR _wp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*2]
	mov	DWORD PTR _wp$[ebp], eax

; 1096 : 	}

	jmp	SHORT $L66854
$L66855:

; 1097 : 	cp += toskew;

	mov	ecx, DWORD PTR _toskew$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp$[ebp], eax

; 1098 : 	wp += fromskew;

	mov	ecx, DWORD PTR _fromskew$[ebp]
	mov	edx, DWORD PTR _wp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*2]
	mov	DWORD PTR _wp$[ebp], eax

; 1099 :     }

	jmp	$L66851
$L66852:

; 1100 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_putRGBcontig16bittile ENDP
_img$ = 8
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_samplesperpixel$ = -8
_wp$ = -4
_putRGBAAcontig16bittile PROC NEAR

; 1107 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 1108 :     int samplesperpixel = img->samplesperpixel;

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+26]
	mov	DWORD PTR _samplesperpixel$[ebp], ecx

; 1109 :     uint16 *wp = (uint16 *)pp;

	mov	edx, DWORD PTR _pp$[ebp]
	mov	DWORD PTR _wp$[ebp], edx

; 1110 : 
; 1111 :     (void) y;
; 1112 :     fromskew *= samplesperpixel;

	mov	eax, DWORD PTR _fromskew$[ebp]
	imul	eax, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _fromskew$[ebp], eax
$L66885:

; 1113 :     while (h-- > 0) {

	mov	ecx, DWORD PTR _h$[ebp]
	mov	edx, DWORD PTR _h$[ebp]
	sub	edx, 1
	mov	DWORD PTR _h$[ebp], edx
	test	ecx, ecx
	jbe	$L66886

; 1114 : 	for (x = w; x-- > 0;) {

	mov	eax, DWORD PTR _w$[ebp]
	mov	DWORD PTR _x$[ebp], eax
$L66888:
	mov	ecx, DWORD PTR _x$[ebp]
	mov	edx, DWORD PTR _x$[ebp]
	sub	edx, 1
	mov	DWORD PTR _x$[ebp], edx
	test	ecx, ecx
	jbe	SHORT $L66889

; 1115 : 	    *cp++ = PACKW4(wp[0], wp[1], wp[2], wp[3]);

	mov	eax, DWORD PTR _wp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	sar	ecx, 8
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _wp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+2]
	sar	eax, 8
	and	eax, 255				; 000000ffH
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _wp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+4]
	sar	eax, 8
	and	eax, 255				; 000000ffH
	shl	eax, 16					; 00000010H
	or	ecx, eax
	mov	edx, DWORD PTR _wp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+6]
	sar	eax, 8
	and	eax, 255				; 000000ffH
	shl	eax, 24					; 00000018H
	or	ecx, eax
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax

; 1116 : 	    wp += samplesperpixel;

	mov	ecx, DWORD PTR _samplesperpixel$[ebp]
	mov	edx, DWORD PTR _wp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*2]
	mov	DWORD PTR _wp$[ebp], eax

; 1117 : 	}

	jmp	SHORT $L66888
$L66889:

; 1118 : 	cp += toskew;

	mov	ecx, DWORD PTR _toskew$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp$[ebp], eax

; 1119 : 	wp += fromskew;

	mov	ecx, DWORD PTR _fromskew$[ebp]
	mov	edx, DWORD PTR _wp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*2]
	mov	DWORD PTR _wp$[ebp], eax

; 1120 :     }

	jmp	$L66885
$L66886:

; 1121 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_putRGBAAcontig16bittile ENDP
_img$ = 8
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_samplesperpixel$ = -8
_wp$ = -4
_r$66921 = -20
_g$66922 = -24
_b$66923 = -16
_a$66924 = -12
_putRGBUAcontig16bittile PROC NEAR

; 1128 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 24					; 00000018H

; 1129 :     int samplesperpixel = img->samplesperpixel;

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+26]
	mov	DWORD PTR _samplesperpixel$[ebp], ecx

; 1130 :     uint16 *wp = (uint16 *)pp;

	mov	edx, DWORD PTR _pp$[ebp]
	mov	DWORD PTR _wp$[ebp], edx

; 1131 : 
; 1132 :     (void) y;
; 1133 :     fromskew *= samplesperpixel;

	mov	eax, DWORD PTR _fromskew$[ebp]
	imul	eax, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _fromskew$[ebp], eax
$L66919:

; 1134 :     while (h-- > 0) {

	mov	ecx, DWORD PTR _h$[ebp]
	mov	edx, DWORD PTR _h$[ebp]
	sub	edx, 1
	mov	DWORD PTR _h$[ebp], edx
	test	ecx, ecx
	jbe	$L66920

; 1135 : 	uint32 r,g,b,a;
; 1136 : 	/*
; 1137 : 	 * We shift alpha down four bits just in case unsigned
; 1138 : 	 * arithmetic doesn't handle the full range.
; 1139 : 	 * We still have plenty of accuracy, since the output is 8 bits.
; 1140 : 	 * So we have (r * 0xffff) * (a * 0xfff)) = r*a * (0xffff*0xfff)
; 1141 : 	 * Since we want r*a * 0xff for eight bit output,
; 1142 : 	 * we divide by (0xffff * 0xfff) / 0xff == 0x10eff.
; 1143 : 	 */
; 1144 : 	for (x = w; x-- > 0;) {

	mov	eax, DWORD PTR _w$[ebp]
	mov	DWORD PTR _x$[ebp], eax
$L66926:
	mov	ecx, DWORD PTR _x$[ebp]
	mov	edx, DWORD PTR _x$[ebp]
	sub	edx, 1
	mov	DWORD PTR _x$[ebp], edx
	test	ecx, ecx
	jbe	$L66927

; 1145 : 	    a = wp[3] >> 4; 

	mov	eax, DWORD PTR _wp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+6]
	sar	ecx, 4
	mov	DWORD PTR _a$66924[ebp], ecx

; 1146 : 	    r = (wp[0] * a) / 0x10eff;

	mov	edx, DWORD PTR _wp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	imul	eax, DWORD PTR _a$66924[ebp]
	xor	edx, edx
	mov	ecx, 69375				; 00010effH
	div	ecx
	mov	DWORD PTR _r$66921[ebp], eax

; 1147 : 	    g = (wp[1] * a) / 0x10eff;

	mov	edx, DWORD PTR _wp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+2]
	imul	eax, DWORD PTR _a$66924[ebp]
	xor	edx, edx
	mov	ecx, 69375				; 00010effH
	div	ecx
	mov	DWORD PTR _g$66922[ebp], eax

; 1148 : 	    b = (wp[2] * a) / 0x10eff;

	mov	edx, DWORD PTR _wp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+4]
	imul	eax, DWORD PTR _a$66924[ebp]
	xor	edx, edx
	mov	ecx, 69375				; 00010effH
	div	ecx
	mov	DWORD PTR _b$66923[ebp], eax

; 1149 : 	    *cp++ = PACK4(r,g,b,a);

	mov	edx, DWORD PTR _g$66922[ebp]
	shl	edx, 8
	mov	eax, DWORD PTR _r$66921[ebp]
	or	eax, edx
	mov	ecx, DWORD PTR _b$66923[ebp]
	shl	ecx, 16					; 00000010H
	or	eax, ecx
	mov	edx, DWORD PTR _a$66924[ebp]
	shl	edx, 24					; 00000018H
	or	eax, edx
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx

; 1150 : 	    wp += samplesperpixel;

	mov	eax, DWORD PTR _samplesperpixel$[ebp]
	mov	ecx, DWORD PTR _wp$[ebp]
	lea	edx, DWORD PTR [ecx+eax*2]
	mov	DWORD PTR _wp$[ebp], edx

; 1151 : 	}

	jmp	$L66926
$L66927:

; 1152 : 	cp += toskew;

	mov	eax, DWORD PTR _toskew$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	lea	edx, DWORD PTR [ecx+eax*4]
	mov	DWORD PTR _cp$[ebp], edx

; 1153 : 	wp += fromskew;

	mov	eax, DWORD PTR _fromskew$[ebp]
	mov	ecx, DWORD PTR _wp$[ebp]
	lea	edx, DWORD PTR [ecx+eax*2]
	mov	DWORD PTR _wp$[ebp], edx

; 1154 :     }

	jmp	$L66919
$L66920:

; 1155 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_putRGBUAcontig16bittile ENDP
_img$ = 8
_cp$ = 12
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_samplesperpixel$ = -16
_r$ = -8
_g$ = -12
_b$ = -4
_k$ = -20
__x$66962 = -24
_putRGBcontig8bitCMYKtile PROC NEAR

; 1163 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 28					; 0000001cH

; 1164 :     int samplesperpixel = img->samplesperpixel;

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+26]
	mov	DWORD PTR _samplesperpixel$[ebp], ecx

; 1165 :     uint16 r, g, b, k;
; 1166 : 
; 1167 :     (void) x; (void) y;
; 1168 :     fromskew *= samplesperpixel;

	mov	edx, DWORD PTR _fromskew$[ebp]
	imul	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _fromskew$[ebp], edx
$L66960:

; 1169 :     while (h-- > 0) {

	mov	eax, DWORD PTR _h$[ebp]
	mov	ecx, DWORD PTR _h$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _h$[ebp], ecx
	test	eax, eax
	jbe	$L66961

; 1171 : 	    k = 255 - pp[3];
; 1172 : 	    r = (k*(255-pp[0]))/255;
; 1173 : 	    g = (k*(255-pp[1]))/255;
; 1174 : 	    b = (k*(255-pp[2]))/255;
; 1175 : 	    *cp++ = PACK(r, g, b);
; 1176 : 	    pp += samplesperpixel);

	mov	edx, DWORD PTR _w$[ebp]
	mov	DWORD PTR __x$66962[ebp], edx
	jmp	SHORT $L66963
$L66964:
	mov	eax, DWORD PTR __x$66962[ebp]
	sub	eax, 8
	mov	DWORD PTR __x$66962[ebp], eax
$L66963:
	cmp	DWORD PTR __x$66962[ebp], 8
	jb	$L66965
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+3]
	mov	eax, 255				; 000000ffH
	sub	eax, edx
	mov	WORD PTR _k$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, 255				; 000000ffH
	sub	ecx, edx
	imul	eax, ecx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _r$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+1]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _g$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+2]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _b$[ebp], ax
	mov	edx, DWORD PTR _r$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _g$[ebp]
	and	eax, 65535				; 0000ffffH
	shl	eax, 8
	or	edx, eax
	mov	ecx, DWORD PTR _b$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	mov	WORD PTR _k$[ebp], dx
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, 255				; 000000ffH
	sub	ecx, edx
	imul	eax, ecx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _r$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+1]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _g$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+2]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _b$[ebp], ax
	mov	edx, DWORD PTR _r$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _g$[ebp]
	and	eax, 65535				; 0000ffffH
	shl	eax, 8
	or	edx, eax
	mov	ecx, DWORD PTR _b$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	mov	WORD PTR _k$[ebp], dx
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, 255				; 000000ffH
	sub	ecx, edx
	imul	eax, ecx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _r$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+1]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _g$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+2]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _b$[ebp], ax
	mov	edx, DWORD PTR _r$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _g$[ebp]
	and	eax, 65535				; 0000ffffH
	shl	eax, 8
	or	edx, eax
	mov	ecx, DWORD PTR _b$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	mov	WORD PTR _k$[ebp], dx
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, 255				; 000000ffH
	sub	ecx, edx
	imul	eax, ecx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _r$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+1]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _g$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+2]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _b$[ebp], ax
	mov	edx, DWORD PTR _r$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _g$[ebp]
	and	eax, 65535				; 0000ffffH
	shl	eax, 8
	or	edx, eax
	mov	ecx, DWORD PTR _b$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	mov	WORD PTR _k$[ebp], dx
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, 255				; 000000ffH
	sub	ecx, edx
	imul	eax, ecx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _r$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+1]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _g$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+2]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _b$[ebp], ax
	mov	edx, DWORD PTR _r$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _g$[ebp]
	and	eax, 65535				; 0000ffffH
	shl	eax, 8
	or	edx, eax
	mov	ecx, DWORD PTR _b$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	mov	WORD PTR _k$[ebp], dx
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, 255				; 000000ffH
	sub	ecx, edx
	imul	eax, ecx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _r$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+1]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _g$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+2]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _b$[ebp], ax
	mov	edx, DWORD PTR _r$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _g$[ebp]
	and	eax, 65535				; 0000ffffH
	shl	eax, 8
	or	edx, eax
	mov	ecx, DWORD PTR _b$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	mov	WORD PTR _k$[ebp], dx
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, 255				; 000000ffH
	sub	ecx, edx
	imul	eax, ecx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _r$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+1]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _g$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+2]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _b$[ebp], ax
	mov	edx, DWORD PTR _r$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _g$[ebp]
	and	eax, 65535				; 0000ffffH
	shl	eax, 8
	or	edx, eax
	mov	ecx, DWORD PTR _b$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	mov	WORD PTR _k$[ebp], dx
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, 255				; 000000ffH
	sub	ecx, edx
	imul	eax, ecx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _r$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+1]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _g$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+2]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _b$[ebp], ax
	mov	edx, DWORD PTR _r$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _g$[ebp]
	and	eax, 65535				; 0000ffffH
	shl	eax, 8
	or	edx, eax
	mov	ecx, DWORD PTR _b$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
	jmp	$L66964
$L66965:
	cmp	DWORD PTR __x$66962[ebp], 0
	jbe	$L67000
	mov	eax, DWORD PTR __x$66962[ebp]
	mov	DWORD PTR -28+[ebp], eax
	mov	ecx, DWORD PTR -28+[ebp]
	sub	ecx, 1
	mov	DWORD PTR -28+[ebp], ecx
	cmp	DWORD PTR -28+[ebp], 6
	ja	$L67000
	mov	edx, DWORD PTR -28+[ebp]
	jmp	DWORD PTR $L68843[edx*4]
$L67003:
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	mov	WORD PTR _k$[ebp], dx
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, 255				; 000000ffH
	sub	ecx, edx
	imul	eax, ecx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _r$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+1]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _g$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+2]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _b$[ebp], ax
	mov	edx, DWORD PTR _r$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _g$[ebp]
	and	eax, 65535				; 0000ffffH
	shl	eax, 8
	or	edx, eax
	mov	ecx, DWORD PTR _b$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
$L67008:
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	mov	WORD PTR _k$[ebp], dx
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, 255				; 000000ffH
	sub	ecx, edx
	imul	eax, ecx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _r$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+1]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _g$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+2]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _b$[ebp], ax
	mov	edx, DWORD PTR _r$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _g$[ebp]
	and	eax, 65535				; 0000ffffH
	shl	eax, 8
	or	edx, eax
	mov	ecx, DWORD PTR _b$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
$L67013:
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	mov	WORD PTR _k$[ebp], dx
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, 255				; 000000ffH
	sub	ecx, edx
	imul	eax, ecx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _r$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+1]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _g$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+2]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _b$[ebp], ax
	mov	edx, DWORD PTR _r$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _g$[ebp]
	and	eax, 65535				; 0000ffffH
	shl	eax, 8
	or	edx, eax
	mov	ecx, DWORD PTR _b$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
$L67018:
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	mov	WORD PTR _k$[ebp], dx
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, 255				; 000000ffH
	sub	ecx, edx
	imul	eax, ecx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _r$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+1]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _g$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+2]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _b$[ebp], ax
	mov	edx, DWORD PTR _r$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _g$[ebp]
	and	eax, 65535				; 0000ffffH
	shl	eax, 8
	or	edx, eax
	mov	ecx, DWORD PTR _b$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
$L67023:
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	mov	WORD PTR _k$[ebp], dx
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, 255				; 000000ffH
	sub	ecx, edx
	imul	eax, ecx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _r$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+1]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _g$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+2]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _b$[ebp], ax
	mov	edx, DWORD PTR _r$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _g$[ebp]
	and	eax, 65535				; 0000ffffH
	shl	eax, 8
	or	edx, eax
	mov	ecx, DWORD PTR _b$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
$L67028:
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	mov	WORD PTR _k$[ebp], dx
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, 255				; 000000ffH
	sub	ecx, edx
	imul	eax, ecx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _r$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+1]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _g$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+2]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _b$[ebp], ax
	mov	edx, DWORD PTR _r$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _g$[ebp]
	and	eax, 65535				; 0000ffffH
	shl	eax, 8
	or	edx, eax
	mov	ecx, DWORD PTR _b$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
$L67033:
	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	mov	WORD PTR _k$[ebp], dx
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, 255				; 000000ffH
	sub	ecx, edx
	imul	eax, ecx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _r$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+1]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _g$[ebp], ax
	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+2]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _b$[ebp], ax
	mov	edx, DWORD PTR _r$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _g$[ebp]
	and	eax, 65535				; 0000ffffH
	shl	eax, 8
	or	edx, eax
	mov	ecx, DWORD PTR _b$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], edx
$L67000:

; 1177 : 	cp += toskew;

	mov	eax, DWORD PTR _toskew$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	lea	edx, DWORD PTR [ecx+eax*4]
	mov	DWORD PTR _cp$[ebp], edx

; 1178 : 	pp += fromskew;

	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], eax

; 1179 :     }

	jmp	$L66960
$L66961:

; 1180 : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68843:
	DD	$L67033
	DD	$L67028
	DD	$L67023
	DD	$L67018
	DD	$L67013
	DD	$L67008
	DD	$L67003
_putRGBcontig8bitCMYKtile ENDP
_img$ = 8
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_samplesperpixel$ = -16
_Map$ = -24
_r$ = -8
_g$ = -12
_b$ = -4
_k$ = -20
_putRGBcontig8bitCMYKMaptile PROC NEAR

; 1188 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 24					; 00000018H
	push	ebx

; 1189 :     int samplesperpixel = img->samplesperpixel;

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+26]
	mov	DWORD PTR _samplesperpixel$[ebp], ecx

; 1190 :     TIFFRGBValue* Map = img->Map;

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx+52]
	mov	DWORD PTR _Map$[ebp], eax

; 1191 :     uint16 r, g, b, k;
; 1192 : 
; 1193 :     (void) y;
; 1194 :     fromskew *= samplesperpixel;

	mov	ecx, DWORD PTR _fromskew$[ebp]
	imul	ecx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _fromskew$[ebp], ecx
$L67066:

; 1195 :     while (h-- > 0) {

	mov	edx, DWORD PTR _h$[ebp]
	mov	eax, DWORD PTR _h$[ebp]
	sub	eax, 1
	mov	DWORD PTR _h$[ebp], eax
	test	edx, edx
	jbe	$L67067

; 1196 : 	for (x = w; x-- > 0;) {

	mov	ecx, DWORD PTR _w$[ebp]
	mov	DWORD PTR _x$[ebp], ecx
$L67069:
	mov	edx, DWORD PTR _x$[ebp]
	mov	eax, DWORD PTR _x$[ebp]
	sub	eax, 1
	mov	DWORD PTR _x$[ebp], eax
	test	edx, edx
	jbe	$L67070

; 1197 : 	    k = 255 - pp[3];

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+3]
	mov	eax, 255				; 000000ffH
	sub	eax, edx
	mov	WORD PTR _k$[ebp], ax

; 1198 : 	    r = (k*(255-pp[0]))/255;

	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, 255				; 000000ffH
	sub	ecx, edx
	imul	eax, ecx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _r$[ebp], ax

; 1199 : 	    g = (k*(255-pp[1]))/255;

	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+1]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _g$[ebp], ax

; 1200 : 	    b = (k*(255-pp[2]))/255;

	mov	eax, DWORD PTR _k$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	edx, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+2]
	mov	edx, 255				; 000000ffH
	sub	edx, ecx
	imul	eax, edx
	cdq
	mov	ecx, 255				; 000000ffH
	idiv	ecx
	mov	WORD PTR _b$[ebp], ax

; 1201 : 	    *cp++ = PACK(Map[r], Map[g], Map[b]);

	mov	edx, DWORD PTR _r$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _Map$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _g$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _Map$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+edx]
	shl	ebx, 8
	or	ecx, ebx
	mov	edx, DWORD PTR _b$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _Map$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+edx]
	shl	ebx, 16					; 00000010H
	or	ecx, ebx
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax

; 1202 : 	    pp += samplesperpixel;

	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _samplesperpixel$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx

; 1203 : 	}

	jmp	$L67069
$L67070:

; 1204 : 	pp += fromskew;

	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], edx

; 1205 : 	cp += toskew;

	mov	eax, DWORD PTR _toskew$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	lea	edx, DWORD PTR [ecx+eax*4]
	mov	DWORD PTR _cp$[ebp], edx

; 1206 :     }

	jmp	$L67066
$L67067:

; 1207 : }

	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_putRGBcontig8bitCMYKMaptile ENDP
_TEXT	ENDS
EXTRN	__TIFFmemcmp:NEAR
_DATA	SEGMENT
	ORG $+3
$SG68354 DB	'No space for YCbCr->RGB conversion state', 00H
_DATA	ENDS
_TEXT	SEGMENT
_img$ = 8
_hs$ = -8
_vs$ = -4
_coeffs$68357 = -12
_initYCbCrConversion PROC NEAR

; 1878 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 1879 :     uint16 hs, vs;
; 1880 : 
; 1881 :     if (img->ycbcr == NULL) {

	mov	eax, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [eax+64], 0
	jne	SHORT $L68339

; 1882 : 	img->ycbcr = (TIFFYCbCrToRGB*) _TIFFmalloc(
; 1883 : 	      TIFFroundup(sizeof (TIFFYCbCrToRGB), sizeof (long))
; 1884 : 	    + 4*256*sizeof (TIFFRGBValue)
; 1885 : 	    + 2*256*sizeof (int)
; 1886 : 	    + 2*256*sizeof (int32)
; 1887 : 	);

	push	5152					; 00001420H
	call	__TIFFmalloc
	add	esp, 4
	mov	ecx, DWORD PTR _img$[ebp]
	mov	DWORD PTR [ecx+64], eax

; 1888 : 	if (img->ycbcr == NULL) {

	mov	edx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [edx+64], 0
	jne	SHORT $L68353

; 1889 : 	    TIFFError(TIFFFileName(img->tif),
; 1890 : 		"No space for YCbCr->RGB conversion state");

	push	OFFSET FLAT:$SG68354
	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 1891 : 	    return (NULL);

	xor	eax, eax
	jmp	$L68335
$L68353:

; 1893 : 	TIFFYCbCrToRGBInit(img->ycbcr, img->tif);

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR [ecx+64]
	push	edx
	call	_TIFFYCbCrToRGBInit
	add	esp, 8

; 1894 :     } else {

	jmp	SHORT $L68359
$L68339:

; 1895 : 	float* coeffs;
; 1896 : 
; 1897 : 	TIFFGetFieldDefaulted(img->tif, TIFFTAG_YCBCRCOEFFICIENTS, &coeffs);

	lea	eax, DWORD PTR _coeffs$68357[ebp]
	push	eax
	push	529					; 00000211H
	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFGetFieldDefaulted
	add	esp, 12					; 0000000cH

; 1898 : 	if (_TIFFmemcmp(coeffs, img->ycbcr->coeffs, 3*sizeof (float)) != 0)

	push	12					; 0000000cH
	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+64]
	add	ecx, 20					; 00000014H
	push	ecx
	mov	edx, DWORD PTR _coeffs$68357[ebp]
	push	edx
	call	__TIFFmemcmp
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L68359

; 1899 : 	    TIFFYCbCrToRGBInit(img->ycbcr, img->tif);

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx+64]
	push	eax
	call	_TIFFYCbCrToRGBInit
	add	esp, 8
$L68359:

; 1901 :     /*
; 1902 :      * The 6.0 spec says that subsampling must be
; 1903 :      * one of 1, 2, or 4, and that vertical subsampling
; 1904 :      * must always be <= horizontal subsampling; so
; 1905 :      * there are only a few possibilities and we just
; 1906 :      * enumerate the cases.
; 1907 :      */
; 1908 :     TIFFGetFieldDefaulted(img->tif, TIFFTAG_YCBCRSUBSAMPLING, &hs, &vs);

	lea	ecx, DWORD PTR _vs$[ebp]
	push	ecx
	lea	edx, DWORD PTR _hs$[ebp]
	push	edx
	push	530					; 00000212H
	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFGetFieldDefaulted
	add	esp, 16					; 00000010H

; 1909 :     switch ((hs<<4)|vs) {

	mov	edx, DWORD PTR _hs$[ebp]
	and	edx, 65535				; 0000ffffH
	shl	edx, 4
	mov	eax, DWORD PTR _vs$[ebp]
	and	eax, 65535				; 0000ffffH
	or	edx, eax
	mov	DWORD PTR -16+[ebp], edx
	mov	ecx, DWORD PTR -16+[ebp]
	sub	ecx, 17					; 00000011H
	mov	DWORD PTR -16+[ebp], ecx
	cmp	DWORD PTR -16+[ebp], 51			; 00000033H
	ja	SHORT $L68361
	mov	eax, DWORD PTR -16+[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR $L68846[eax]
	jmp	DWORD PTR $L68847[edx*4]
$L68364:

; 1910 :     case 0x44: return (putcontig8bitYCbCr44tile);

	mov	eax, OFFSET FLAT:_putcontig8bitYCbCr44tile
	jmp	SHORT $L68335
$L68365:

; 1911 :     case 0x42: return (putcontig8bitYCbCr42tile);

	mov	eax, OFFSET FLAT:_putcontig8bitYCbCr42tile
	jmp	SHORT $L68335
$L68366:

; 1912 :     case 0x41: return (putcontig8bitYCbCr41tile);

	mov	eax, OFFSET FLAT:_putcontig8bitYCbCr41tile
	jmp	SHORT $L68335
$L68367:

; 1913 :     case 0x22: return (putcontig8bitYCbCr22tile);

	mov	eax, OFFSET FLAT:_putcontig8bitYCbCr22tile
	jmp	SHORT $L68335
$L68368:

; 1914 :     case 0x21: return (putcontig8bitYCbCr21tile);

	mov	eax, OFFSET FLAT:_putcontig8bitYCbCr21tile
	jmp	SHORT $L68335
$L68369:

; 1915 :     case 0x11: return (putcontig8bitYCbCr11tile);

	mov	eax, OFFSET FLAT:_putcontig8bitYCbCr11tile
	jmp	SHORT $L68335
$L68361:

; 1917 :     return (NULL);

	xor	eax, eax
$L68335:

; 1918 : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68847:
	DD	$L68369
	DD	$L68368
	DD	$L68367
	DD	$L68366
	DD	$L68365
	DD	$L68364
	DD	$L68361
$L68846:
	DB	0
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	1
	DB	2
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	3
	DB	4
	DB	6
	DB	5
_initYCbCrConversion ENDP
_Y$67587 = -72
_Y$67593 = -76
_Y$67599 = -80
_Y$67605 = -84
_Y$67611 = -88
_Y$67617 = -92
_Y$67623 = -96
_Y$67629 = -100
_Y$67635 = -104
_Y$67641 = -108
_Y$67647 = -112
_Cb$67660 = -120
_Cr$67661 = -116
_Y$67672 = -124
_Y$67679 = -128
_Y$67686 = -132
_Y$67693 = -136
_Y$67705 = -140
_Y$67712 = -144
_Y$67719 = -148
_Y$67726 = -152
_Y$67738 = -156
_Y$67745 = -160
_Y$67752 = -164
_Y$67759 = -168
_Y$67771 = -172
_Y$67778 = -176
_Y$67785 = -180
_Y$67792 = -184
_img$ = 8
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_ycbcr$ = -24
_Crrtab$ = -20
_Cbbtab$ = -12
_Crgtab$ = -8
_Cbgtab$ = -40
_clamptab$ = -36
_cp1$ = -16
_cp2$ = -28
_cp3$ = -32
_incr$ = -4
_Cb$67555 = -48
_Cr$67556 = -44
_Y$67557 = -52
_Y$67563 = -56
_Y$67569 = -60
_Y$67575 = -64
_Y$67581 = -68
_putcontig8bitYCbCr44tile PROC NEAR

; 1454 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 204				; 000000ccH
	push	ebx
	push	esi

; 1455 :     YCbCrSetup;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+64]
	mov	DWORD PTR _ycbcr$[ebp], ecx
	mov	edx, DWORD PTR _ycbcr$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _Crrtab$[ebp], eax
	mov	ecx, DWORD PTR _ycbcr$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR _Cbbtab$[ebp], edx
	mov	eax, DWORD PTR _ycbcr$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _Crgtab$[ebp], ecx
	mov	edx, DWORD PTR _ycbcr$[ebp]
	mov	eax, DWORD PTR [edx+16]
	mov	DWORD PTR _Cbgtab$[ebp], eax
	mov	ecx, DWORD PTR _ycbcr$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR _clamptab$[ebp], edx

; 1456 :     uint32* cp1 = cp+w+toskew;

	mov	eax, DWORD PTR _w$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	lea	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _toskew$[ebp]
	lea	ecx, DWORD PTR [edx+eax*4]
	mov	DWORD PTR _cp1$[ebp], ecx

; 1457 :     uint32* cp2 = cp1+w+toskew;

	mov	edx, DWORD PTR _w$[ebp]
	mov	eax, DWORD PTR _cp1$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	edx, DWORD PTR _toskew$[ebp]
	lea	eax, DWORD PTR [ecx+edx*4]
	mov	DWORD PTR _cp2$[ebp], eax

; 1458 :     uint32* cp3 = cp2+w+toskew;

	mov	ecx, DWORD PTR _w$[ebp]
	mov	edx, DWORD PTR _cp2$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _toskew$[ebp]
	lea	edx, DWORD PTR [eax+ecx*4]
	mov	DWORD PTR _cp3$[ebp], edx

; 1459 :     int32 incr = 3*w+4*toskew;

	mov	eax, DWORD PTR _w$[ebp]
	imul	eax, 3
	mov	ecx, DWORD PTR _toskew$[ebp]
	lea	edx, DWORD PTR [eax+ecx*4]
	mov	DWORD PTR _incr$[ebp], edx

; 1460 : 
; 1461 :     (void) y;
; 1462 :     /* adjust fromskew */
; 1463 :     fromskew = (fromskew * 18) / 4;

	mov	eax, DWORD PTR _fromskew$[ebp]
	imul	eax, 18					; 00000012H
	cdq
	and	edx, 3
	add	eax, edx
	sar	eax, 2
	mov	DWORD PTR _fromskew$[ebp], eax

; 1464 :     if ((h & 3) == 0 && (w & 3) == 0) {				        

	mov	eax, DWORD PTR _h$[ebp]
	and	eax, 3
	test	eax, eax
	jne	$L67548
	mov	ecx, DWORD PTR _w$[ebp]
	and	ecx, 3
	test	ecx, ecx
	jne	$L67548

; 1465 :         for (; h >= 4; h -= 4) {

	jmp	SHORT $L67549
$L67550:
	mov	edx, DWORD PTR _h$[ebp]
	sub	edx, 4
	mov	DWORD PTR _h$[ebp], edx
$L67549:
	cmp	DWORD PTR _h$[ebp], 4
	jb	$L67551

; 1466 :             x = w>>2;

	mov	eax, DWORD PTR _w$[ebp]
	shr	eax, 2
	mov	DWORD PTR _x$[ebp], eax
$L67552:

; 1468 :                 int Cb = pp[16];

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+16]
	mov	DWORD PTR _Cb$67555[ebp], edx

; 1469 :                 int Cr = pp[17];

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+17]
	mov	DWORD PTR _Cr$67556[ebp], ecx

; 1470 : 
; 1471 :                 YCbCrtoRGB(cp [0], pp[ 0]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	DWORD PTR _Y$67557[ebp], eax
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67557[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67555[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67557[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67555[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67557[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], edx

; 1472 :                 YCbCrtoRGB(cp [1], pp[ 1]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	mov	DWORD PTR _Y$67563[ebp], eax
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67563[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67555[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67563[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67555[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67563[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx+4], edx

; 1473 :                 YCbCrtoRGB(cp [2], pp[ 2]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	mov	DWORD PTR _Y$67569[ebp], eax
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67569[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67555[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67569[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67555[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67569[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx+8], edx

; 1474 :                 YCbCrtoRGB(cp [3], pp[ 3]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+3]
	mov	DWORD PTR _Y$67575[ebp], eax
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67575[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67555[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67575[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67555[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67575[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx+12], edx

; 1475 :                 YCbCrtoRGB(cp1[0], pp[ 4]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+4]
	mov	DWORD PTR _Y$67581[ebp], eax
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67581[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67555[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67581[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67555[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67581[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [ecx], edx

; 1476 :                 YCbCrtoRGB(cp1[1], pp[ 5]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+5]
	mov	DWORD PTR _Y$67587[ebp], eax
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67587[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67555[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67587[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67555[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67587[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [ecx+4], edx

; 1477 :                 YCbCrtoRGB(cp1[2], pp[ 6]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+6]
	mov	DWORD PTR _Y$67593[ebp], eax
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67593[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67555[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67593[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67555[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67593[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [ecx+8], edx

; 1478 :                 YCbCrtoRGB(cp1[3], pp[ 7]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+7]
	mov	DWORD PTR _Y$67599[ebp], eax
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67599[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67555[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67599[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67555[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67599[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [ecx+12], edx

; 1479 :                 YCbCrtoRGB(cp2[0], pp[ 8]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+8]
	mov	DWORD PTR _Y$67605[ebp], eax
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67605[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67555[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67605[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67555[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67605[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp2$[ebp]
	mov	DWORD PTR [ecx], edx

; 1480 :                 YCbCrtoRGB(cp2[1], pp[ 9]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+9]
	mov	DWORD PTR _Y$67611[ebp], eax
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67611[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67555[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67611[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67555[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67611[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp2$[ebp]
	mov	DWORD PTR [ecx+4], edx

; 1481 :                 YCbCrtoRGB(cp2[2], pp[10]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+10]
	mov	DWORD PTR _Y$67617[ebp], eax
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67617[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67555[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67617[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67555[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67617[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp2$[ebp]
	mov	DWORD PTR [ecx+8], edx

; 1482 :                 YCbCrtoRGB(cp2[3], pp[11]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+11]
	mov	DWORD PTR _Y$67623[ebp], eax
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67623[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67555[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67623[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67555[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67623[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp2$[ebp]
	mov	DWORD PTR [ecx+12], edx

; 1483 :                 YCbCrtoRGB(cp3[0], pp[12]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+12]
	mov	DWORD PTR _Y$67629[ebp], eax
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67629[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67555[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67629[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67555[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67629[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp3$[ebp]
	mov	DWORD PTR [ecx], edx

; 1484 :                 YCbCrtoRGB(cp3[1], pp[13]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+13]
	mov	DWORD PTR _Y$67635[ebp], eax
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67635[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67555[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67635[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67555[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67635[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp3$[ebp]
	mov	DWORD PTR [ecx+4], edx

; 1485 :                 YCbCrtoRGB(cp3[2], pp[14]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+14]
	mov	DWORD PTR _Y$67641[ebp], eax
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67641[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67555[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67641[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67555[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67641[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp3$[ebp]
	mov	DWORD PTR [ecx+8], edx

; 1486 :                 YCbCrtoRGB(cp3[3], pp[15]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+15]
	mov	DWORD PTR _Y$67647[ebp], eax
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67647[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67555[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67556[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67647[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67555[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67647[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp3$[ebp]
	mov	DWORD PTR [ecx+12], edx

; 1487 : 
; 1488 :                 cp += 4, cp1 += 4, cp2 += 4, cp3 += 4;

	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 16					; 00000010H
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _cp1$[ebp]
	add	eax, 16					; 00000010H
	mov	DWORD PTR _cp1$[ebp], eax
	mov	ecx, DWORD PTR _cp2$[ebp]
	add	ecx, 16					; 00000010H
	mov	DWORD PTR _cp2$[ebp], ecx
	mov	edx, DWORD PTR _cp3$[ebp]
	add	edx, 16					; 00000010H
	mov	DWORD PTR _cp3$[ebp], edx

; 1489 :                 pp += 18;

	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, 18					; 00000012H
	mov	DWORD PTR _pp$[ebp], eax

; 1490 :             } while (--x);

	mov	ecx, DWORD PTR _x$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _x$[ebp], ecx
	cmp	DWORD PTR _x$[ebp], 0
	jne	$L67552

; 1491 :             cp += incr, cp1 += incr, cp2 += incr, cp3 += incr;

	mov	edx, DWORD PTR _incr$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _incr$[ebp]
	mov	eax, DWORD PTR _cp1$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp1$[ebp], ecx
	mov	edx, DWORD PTR _incr$[ebp]
	mov	eax, DWORD PTR _cp2$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp2$[ebp], ecx
	mov	edx, DWORD PTR _incr$[ebp]
	mov	eax, DWORD PTR _cp3$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp3$[ebp], ecx

; 1492 :             pp += fromskew;

	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], edx

; 1493 :         }

	jmp	$L67550
$L67551:

; 1494 :     } else {

	jmp	$L67656
$L67548:

; 1495 :         while (h > 0) {

	cmp	DWORD PTR _h$[ebp], 0
	jbe	$L67656

; 1496 :             for (x = w; x > 0;) {

	mov	eax, DWORD PTR _w$[ebp]
	mov	DWORD PTR _x$[ebp], eax
$L67658:
	cmp	DWORD PTR _x$[ebp], 0
	jbe	$L67659

; 1497 :                 int Cb = pp[16];

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+16]
	mov	DWORD PTR _Cb$67660[ebp], edx

; 1498 :                 int Cr = pp[17];

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+17]
	mov	DWORD PTR _Cr$67661[ebp], ecx

; 1499 :                 switch (x) {

	mov	edx, DWORD PTR _x$[ebp]
	mov	DWORD PTR -188+[ebp], edx
	cmp	DWORD PTR -188+[ebp], 1
	je	$L67734
	cmp	DWORD PTR -188+[ebp], 2
	je	$L67701
	cmp	DWORD PTR -188+[ebp], 3
	je	$L67668

; 1500 :                 default:
; 1501 :                     switch (h) {

	mov	eax, DWORD PTR _h$[ebp]
	mov	DWORD PTR -192+[ebp], eax
	cmp	DWORD PTR -192+[ebp], 1
	je	$L67692
	cmp	DWORD PTR -192+[ebp], 2
	je	$L67685
	cmp	DWORD PTR -192+[ebp], 3
	je	SHORT $L67678

; 1502 :                     default: YCbCrtoRGB(cp3[3], pp[15]); /* FALLTHROUGH */

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+15]
	mov	DWORD PTR _Y$67672[ebp], edx
	mov	eax, DWORD PTR _Cr$67661[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67672[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67660[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67661[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67672[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67660[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67672[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp3$[ebp]
	mov	DWORD PTR [eax+12], ecx
$L67678:

; 1503 :                     case 3:  YCbCrtoRGB(cp2[3], pp[11]); /* FALLTHROUGH */

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+11]
	mov	DWORD PTR _Y$67679[ebp], edx
	mov	eax, DWORD PTR _Cr$67661[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67679[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67660[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67661[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67679[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67660[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67679[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp2$[ebp]
	mov	DWORD PTR [eax+12], ecx
$L67685:

; 1504 :                     case 2:  YCbCrtoRGB(cp1[3], pp[ 7]); /* FALLTHROUGH */

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+7]
	mov	DWORD PTR _Y$67686[ebp], edx
	mov	eax, DWORD PTR _Cr$67661[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67686[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67660[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67661[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67686[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67660[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67686[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [eax+12], ecx
$L67692:

; 1505 :                     case 1:  YCbCrtoRGB(cp [3], pp[ 3]); /* FALLTHROUGH */

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+3]
	mov	DWORD PTR _Y$67693[ebp], edx
	mov	eax, DWORD PTR _Cr$67661[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67693[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67660[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67661[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67693[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67660[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67693[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax+12], ecx
$L67668:

; 1507 :                 case 3:
; 1508 :                     switch (h) {

	mov	ecx, DWORD PTR _h$[ebp]
	mov	DWORD PTR -196+[ebp], ecx
	cmp	DWORD PTR -196+[ebp], 1
	je	$L67725
	cmp	DWORD PTR -196+[ebp], 2
	je	$L67718
	cmp	DWORD PTR -196+[ebp], 3
	je	SHORT $L67711

; 1509 :                     default: YCbCrtoRGB(cp3[2], pp[14]); /* FALLTHROUGH */

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+14]
	mov	DWORD PTR _Y$67705[ebp], eax
	mov	ecx, DWORD PTR _Cr$67661[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67705[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67660[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67661[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67705[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67660[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67705[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp3$[ebp]
	mov	DWORD PTR [ecx+8], edx
$L67711:

; 1510 :                     case 3:  YCbCrtoRGB(cp2[2], pp[10]); /* FALLTHROUGH */

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+10]
	mov	DWORD PTR _Y$67712[ebp], eax
	mov	ecx, DWORD PTR _Cr$67661[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67712[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67660[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67661[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67712[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67660[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67712[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp2$[ebp]
	mov	DWORD PTR [ecx+8], edx
$L67718:

; 1511 :                     case 2:  YCbCrtoRGB(cp1[2], pp[ 6]); /* FALLTHROUGH */

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+6]
	mov	DWORD PTR _Y$67719[ebp], eax
	mov	ecx, DWORD PTR _Cr$67661[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67719[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67660[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67661[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67719[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67660[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67719[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [ecx+8], edx
$L67725:

; 1512 :                     case 1:  YCbCrtoRGB(cp [2], pp[ 2]); /* FALLTHROUGH */

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	mov	DWORD PTR _Y$67726[ebp], eax
	mov	ecx, DWORD PTR _Cr$67661[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67726[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67660[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67661[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67726[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67660[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67726[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx+8], edx
$L67701:

; 1514 :                 case 2:
; 1515 :                     switch (h) {

	mov	edx, DWORD PTR _h$[ebp]
	mov	DWORD PTR -200+[ebp], edx
	cmp	DWORD PTR -200+[ebp], 1
	je	$L67758
	cmp	DWORD PTR -200+[ebp], 2
	je	$L67751
	cmp	DWORD PTR -200+[ebp], 3
	je	SHORT $L67744

; 1516 :                     default: YCbCrtoRGB(cp3[1], pp[13]); /* FALLTHROUGH */

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+13]
	mov	DWORD PTR _Y$67738[ebp], ecx
	mov	edx, DWORD PTR _Cr$67661[ebp]
	mov	eax, DWORD PTR _Crrtab$[ebp]
	mov	ecx, DWORD PTR _Y$67738[ebp]
	add	ecx, DWORD PTR [eax+edx*4]
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _Cb$67660[ebp]
	mov	edx, DWORD PTR _Cbgtab$[ebp]
	mov	ecx, DWORD PTR [edx+ecx*4]
	mov	edx, DWORD PTR _Cr$67661[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	ecx, DWORD PTR [esi+edx*4]
	sar	ecx, 16					; 00000010H
	mov	edx, DWORD PTR _Y$67738[ebp]
	add	edx, ecx
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [ecx+edx]
	shl	ebx, 8
	or	eax, ebx
	mov	edx, DWORD PTR _Cb$67660[ebp]
	mov	ecx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67738[ebp]
	add	esi, DWORD PTR [ecx+edx*4]
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+esi]
	shl	ecx, 16					; 00000010H
	or	eax, ecx
	or	eax, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp3$[ebp]
	mov	DWORD PTR [edx+4], eax
$L67744:

; 1517 :                     case 3:  YCbCrtoRGB(cp2[1], pp[ 9]); /* FALLTHROUGH */

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+9]
	mov	DWORD PTR _Y$67745[ebp], ecx
	mov	edx, DWORD PTR _Cr$67661[ebp]
	mov	eax, DWORD PTR _Crrtab$[ebp]
	mov	ecx, DWORD PTR _Y$67745[ebp]
	add	ecx, DWORD PTR [eax+edx*4]
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _Cb$67660[ebp]
	mov	edx, DWORD PTR _Cbgtab$[ebp]
	mov	ecx, DWORD PTR [edx+ecx*4]
	mov	edx, DWORD PTR _Cr$67661[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	ecx, DWORD PTR [esi+edx*4]
	sar	ecx, 16					; 00000010H
	mov	edx, DWORD PTR _Y$67745[ebp]
	add	edx, ecx
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [ecx+edx]
	shl	ebx, 8
	or	eax, ebx
	mov	edx, DWORD PTR _Cb$67660[ebp]
	mov	ecx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67745[ebp]
	add	esi, DWORD PTR [ecx+edx*4]
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+esi]
	shl	ecx, 16					; 00000010H
	or	eax, ecx
	or	eax, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp2$[ebp]
	mov	DWORD PTR [edx+4], eax
$L67751:

; 1518 :                     case 2:  YCbCrtoRGB(cp1[1], pp[ 5]); /* FALLTHROUGH */

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+5]
	mov	DWORD PTR _Y$67752[ebp], ecx
	mov	edx, DWORD PTR _Cr$67661[ebp]
	mov	eax, DWORD PTR _Crrtab$[ebp]
	mov	ecx, DWORD PTR _Y$67752[ebp]
	add	ecx, DWORD PTR [eax+edx*4]
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _Cb$67660[ebp]
	mov	edx, DWORD PTR _Cbgtab$[ebp]
	mov	ecx, DWORD PTR [edx+ecx*4]
	mov	edx, DWORD PTR _Cr$67661[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	ecx, DWORD PTR [esi+edx*4]
	sar	ecx, 16					; 00000010H
	mov	edx, DWORD PTR _Y$67752[ebp]
	add	edx, ecx
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [ecx+edx]
	shl	ebx, 8
	or	eax, ebx
	mov	edx, DWORD PTR _Cb$67660[ebp]
	mov	ecx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67752[ebp]
	add	esi, DWORD PTR [ecx+edx*4]
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+esi]
	shl	ecx, 16					; 00000010H
	or	eax, ecx
	or	eax, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [edx+4], eax
$L67758:

; 1519 :                     case 1:  YCbCrtoRGB(cp [1], pp[ 1]); /* FALLTHROUGH */

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	DWORD PTR _Y$67759[ebp], ecx
	mov	edx, DWORD PTR _Cr$67661[ebp]
	mov	eax, DWORD PTR _Crrtab$[ebp]
	mov	ecx, DWORD PTR _Y$67759[ebp]
	add	ecx, DWORD PTR [eax+edx*4]
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _Cb$67660[ebp]
	mov	edx, DWORD PTR _Cbgtab$[ebp]
	mov	ecx, DWORD PTR [edx+ecx*4]
	mov	edx, DWORD PTR _Cr$67661[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	ecx, DWORD PTR [esi+edx*4]
	sar	ecx, 16					; 00000010H
	mov	edx, DWORD PTR _Y$67759[ebp]
	add	edx, ecx
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [ecx+edx]
	shl	ebx, 8
	or	eax, ebx
	mov	edx, DWORD PTR _Cb$67660[ebp]
	mov	ecx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67759[ebp]
	add	esi, DWORD PTR [ecx+edx*4]
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+esi]
	shl	ecx, 16					; 00000010H
	or	eax, ecx
	or	eax, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx+4], eax
$L67734:

; 1521 :                 case 1:
; 1522 :                     switch (h) {

	mov	eax, DWORD PTR _h$[ebp]
	mov	DWORD PTR -204+[ebp], eax
	cmp	DWORD PTR -204+[ebp], 1
	je	$L67791
	cmp	DWORD PTR -204+[ebp], 2
	je	$L67784
	cmp	DWORD PTR -204+[ebp], 3
	je	SHORT $L67777

; 1523 :                     default: YCbCrtoRGB(cp3[0], pp[12]); /* FALLTHROUGH */

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+12]
	mov	DWORD PTR _Y$67771[ebp], edx
	mov	eax, DWORD PTR _Cr$67661[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67771[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67660[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67661[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67771[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67660[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67771[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp3$[ebp]
	mov	DWORD PTR [eax], ecx
$L67777:

; 1524 :                     case 3:  YCbCrtoRGB(cp2[0], pp[ 8]); /* FALLTHROUGH */

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+8]
	mov	DWORD PTR _Y$67778[ebp], edx
	mov	eax, DWORD PTR _Cr$67661[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67778[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67660[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67661[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67778[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67660[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67778[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp2$[ebp]
	mov	DWORD PTR [eax], ecx
$L67784:

; 1525 :                     case 2:  YCbCrtoRGB(cp1[0], pp[ 4]); /* FALLTHROUGH */

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+4]
	mov	DWORD PTR _Y$67785[ebp], edx
	mov	eax, DWORD PTR _Cr$67661[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67785[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67660[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67661[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67785[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67660[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67785[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [eax], ecx
$L67791:

; 1526 :                     case 1:  YCbCrtoRGB(cp [0], pp[ 0]); /* FALLTHROUGH */

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	DWORD PTR _Y$67792[ebp], edx
	mov	eax, DWORD PTR _Cr$67661[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67792[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67660[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67661[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67792[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67660[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67792[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], ecx

; 1529 :                 if (x < 4) {

	cmp	DWORD PTR _x$[ebp], 4
	jae	SHORT $L67798

; 1530 :                     cp += x; cp1 += x; cp2 += x; cp3 += x;

	mov	ecx, DWORD PTR _x$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _x$[ebp]
	mov	edx, DWORD PTR _cp1$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp1$[ebp], eax
	mov	ecx, DWORD PTR _x$[ebp]
	mov	edx, DWORD PTR _cp2$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp2$[ebp], eax
	mov	ecx, DWORD PTR _x$[ebp]
	mov	edx, DWORD PTR _cp3$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp3$[ebp], eax

; 1531 :                     x = 0;

	mov	DWORD PTR _x$[ebp], 0

; 1533 :                 else {

	jmp	SHORT $L67799
$L67798:

; 1534 :                     cp += 4; cp1 += 4; cp2 += 4; cp3 += 4;

	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 16					; 00000010H
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _cp1$[ebp]
	add	edx, 16					; 00000010H
	mov	DWORD PTR _cp1$[ebp], edx
	mov	eax, DWORD PTR _cp2$[ebp]
	add	eax, 16					; 00000010H
	mov	DWORD PTR _cp2$[ebp], eax
	mov	ecx, DWORD PTR _cp3$[ebp]
	add	ecx, 16					; 00000010H
	mov	DWORD PTR _cp3$[ebp], ecx

; 1535 :                     x -= 4;

	mov	edx, DWORD PTR _x$[ebp]
	sub	edx, 4
	mov	DWORD PTR _x$[ebp], edx
$L67799:

; 1537 :                 pp += 18;

	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, 18					; 00000012H
	mov	DWORD PTR _pp$[ebp], eax

; 1538 :             }

	jmp	$L67658
$L67659:

; 1539 :             if (h <= 4)

	cmp	DWORD PTR _h$[ebp], 4
	ja	SHORT $L67800

; 1540 :                 break;

	jmp	SHORT $L67656
$L67800:

; 1541 :             h -= 4;

	mov	ecx, DWORD PTR _h$[ebp]
	sub	ecx, 4
	mov	DWORD PTR _h$[ebp], ecx

; 1542 :             cp += incr, cp1 += incr, cp2 += incr, cp3 += incr;

	mov	edx, DWORD PTR _incr$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _incr$[ebp]
	mov	eax, DWORD PTR _cp1$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp1$[ebp], ecx
	mov	edx, DWORD PTR _incr$[ebp]
	mov	eax, DWORD PTR _cp2$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp2$[ebp], ecx
	mov	edx, DWORD PTR _incr$[ebp]
	mov	eax, DWORD PTR _cp3$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp3$[ebp], ecx

; 1543 :             pp += fromskew;

	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], edx

; 1544 :         }

	jmp	$L67548
$L67656:

; 1546 : }

	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_putcontig8bitYCbCr44tile ENDP
_img$ = 8
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_ycbcr$ = -24
_Crrtab$ = -20
_Cbbtab$ = -12
_Crgtab$ = -8
_Cbgtab$ = -32
_clamptab$ = -28
_cp1$ = -16
_incr$ = -4
_Cb$67837 = -40
_Cr$67838 = -36
_Y$67839 = -44
_Y$67845 = -48
_Y$67851 = -52
_Y$67857 = -56
_Y$67863 = -60
_Y$67869 = -64
_Y$67875 = -68
_Y$67881 = -72
_Cb$67894 = -80
_Cr$67895 = -76
_Y$67906 = -84
_Y$67913 = -88
_Y$67925 = -92
_Y$67932 = -96
_Y$67944 = -100
_Y$67951 = -104
_Y$67963 = -108
_Y$67970 = -112
_putcontig8bitYCbCr42tile PROC NEAR

; 1552 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 132				; 00000084H
	push	ebx
	push	esi

; 1553 :     YCbCrSetup;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+64]
	mov	DWORD PTR _ycbcr$[ebp], ecx
	mov	edx, DWORD PTR _ycbcr$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _Crrtab$[ebp], eax
	mov	ecx, DWORD PTR _ycbcr$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR _Cbbtab$[ebp], edx
	mov	eax, DWORD PTR _ycbcr$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _Crgtab$[ebp], ecx
	mov	edx, DWORD PTR _ycbcr$[ebp]
	mov	eax, DWORD PTR [edx+16]
	mov	DWORD PTR _Cbgtab$[ebp], eax
	mov	ecx, DWORD PTR _ycbcr$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR _clamptab$[ebp], edx

; 1554 :     uint32* cp1 = cp+w+toskew;

	mov	eax, DWORD PTR _w$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	lea	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _toskew$[ebp]
	lea	ecx, DWORD PTR [edx+eax*4]
	mov	DWORD PTR _cp1$[ebp], ecx

; 1555 :     int32 incr = 2*toskew+w;

	mov	edx, DWORD PTR _toskew$[ebp]
	mov	eax, DWORD PTR _w$[ebp]
	lea	ecx, DWORD PTR [eax+edx*2]
	mov	DWORD PTR _incr$[ebp], ecx

; 1556 : 
; 1557 :     (void) y;
; 1558 :     fromskew = (fromskew * 10) / 4;

	mov	eax, DWORD PTR _fromskew$[ebp]
	imul	eax, 10					; 0000000aH
	cdq
	and	edx, 3
	add	eax, edx
	sar	eax, 2
	mov	DWORD PTR _fromskew$[ebp], eax

; 1559 :     if ((h & 3) == 0 && (w & 1) == 0) {

	mov	edx, DWORD PTR _h$[ebp]
	and	edx, 3
	test	edx, edx
	jne	$L67830
	mov	eax, DWORD PTR _w$[ebp]
	and	eax, 1
	test	eax, eax
	jne	$L67830

; 1560 :         for (; h >= 2; h -= 2) {

	jmp	SHORT $L67831
$L67832:
	mov	ecx, DWORD PTR _h$[ebp]
	sub	ecx, 2
	mov	DWORD PTR _h$[ebp], ecx
$L67831:
	cmp	DWORD PTR _h$[ebp], 2
	jb	$L67833

; 1561 :             x = w>>2;

	mov	edx, DWORD PTR _w$[ebp]
	shr	edx, 2
	mov	DWORD PTR _x$[ebp], edx
$L67834:

; 1563 :                 int Cb = pp[8];

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+8]
	mov	DWORD PTR _Cb$67837[ebp], ecx

; 1564 :                 int Cr = pp[9];

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+9]
	mov	DWORD PTR _Cr$67838[ebp], eax

; 1565 :                 
; 1566 :                 YCbCrtoRGB(cp [0], pp[0]);

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	DWORD PTR _Y$67839[ebp], edx
	mov	eax, DWORD PTR _Cr$67838[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67839[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67837[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67838[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67839[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67837[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67839[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], ecx

; 1567 :                 YCbCrtoRGB(cp [1], pp[1]);

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	mov	DWORD PTR _Y$67845[ebp], edx
	mov	eax, DWORD PTR _Cr$67838[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67845[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67837[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67838[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67845[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67837[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67845[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax+4], ecx

; 1568 :                 YCbCrtoRGB(cp [2], pp[2]);

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+2]
	mov	DWORD PTR _Y$67851[ebp], edx
	mov	eax, DWORD PTR _Cr$67838[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67851[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67837[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67838[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67851[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67837[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67851[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax+8], ecx

; 1569 :                 YCbCrtoRGB(cp [3], pp[3]);

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+3]
	mov	DWORD PTR _Y$67857[ebp], edx
	mov	eax, DWORD PTR _Cr$67838[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67857[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67837[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67838[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67857[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67837[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67857[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax+12], ecx

; 1570 :                 YCbCrtoRGB(cp1[0], pp[4]);

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+4]
	mov	DWORD PTR _Y$67863[ebp], edx
	mov	eax, DWORD PTR _Cr$67838[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67863[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67837[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67838[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67863[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67837[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67863[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [eax], ecx

; 1571 :                 YCbCrtoRGB(cp1[1], pp[5]);

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+5]
	mov	DWORD PTR _Y$67869[ebp], edx
	mov	eax, DWORD PTR _Cr$67838[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67869[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67837[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67838[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67869[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67837[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67869[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [eax+4], ecx

; 1572 :                 YCbCrtoRGB(cp1[2], pp[6]);

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+6]
	mov	DWORD PTR _Y$67875[ebp], edx
	mov	eax, DWORD PTR _Cr$67838[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67875[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67837[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67838[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67875[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67837[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67875[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [eax+8], ecx

; 1573 :                 YCbCrtoRGB(cp1[3], pp[7]);

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+7]
	mov	DWORD PTR _Y$67881[ebp], edx
	mov	eax, DWORD PTR _Cr$67838[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67881[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67837[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67838[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67881[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67837[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67881[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [eax+12], ecx

; 1574 :                 
; 1575 :                 cp += 4, cp1 += 4;

	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 16					; 00000010H
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _cp1$[ebp]
	add	edx, 16					; 00000010H
	mov	DWORD PTR _cp1$[ebp], edx

; 1576 :                 pp += 10;

	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, 10					; 0000000aH
	mov	DWORD PTR _pp$[ebp], eax

; 1577 :             } while (--x);

	mov	ecx, DWORD PTR _x$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _x$[ebp], ecx
	cmp	DWORD PTR _x$[ebp], 0
	jne	$L67834

; 1578 :             cp += incr, cp1 += incr;

	mov	edx, DWORD PTR _incr$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _incr$[ebp]
	mov	eax, DWORD PTR _cp1$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp1$[ebp], ecx

; 1579 :             pp += fromskew;

	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], edx

; 1580 :         }

	jmp	$L67832
$L67833:

; 1581 :     } else {

	jmp	$L67890
$L67830:

; 1582 :         while (h > 0) {

	cmp	DWORD PTR _h$[ebp], 0
	jbe	$L67890

; 1583 :             for (x = w; x > 0;) {

	mov	eax, DWORD PTR _w$[ebp]
	mov	DWORD PTR _x$[ebp], eax
$L67892:
	cmp	DWORD PTR _x$[ebp], 0
	jbe	$L67893

; 1584 :                 int Cb = pp[8];

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+8]
	mov	DWORD PTR _Cb$67894[ebp], edx

; 1585 :                 int Cr = pp[9];

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+9]
	mov	DWORD PTR _Cr$67895[ebp], ecx

; 1586 :                 switch (x) {

	mov	edx, DWORD PTR _x$[ebp]
	mov	DWORD PTR -116+[ebp], edx
	cmp	DWORD PTR -116+[ebp], 1
	je	$L67940
	cmp	DWORD PTR -116+[ebp], 2
	je	$L67921
	cmp	DWORD PTR -116+[ebp], 3
	je	$L67902

; 1587 :                 default:
; 1588 :                     switch (h) {

	mov	eax, DWORD PTR _h$[ebp]
	mov	DWORD PTR -120+[ebp], eax
	cmp	DWORD PTR -120+[ebp], 1
	je	SHORT $L67912

; 1589 :                     default: YCbCrtoRGB(cp1[3], pp[ 7]); /* FALLTHROUGH */

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+7]
	mov	DWORD PTR _Y$67906[ebp], edx
	mov	eax, DWORD PTR _Cr$67895[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67906[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67894[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67895[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67906[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67894[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67906[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [eax+12], ecx
$L67912:

; 1590 :                     case 1:  YCbCrtoRGB(cp [3], pp[ 3]); /* FALLTHROUGH */

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+3]
	mov	DWORD PTR _Y$67913[ebp], edx
	mov	eax, DWORD PTR _Cr$67895[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67913[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67894[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67895[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67913[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67894[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67913[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax+12], ecx
$L67902:

; 1592 :                 case 3:
; 1593 :                     switch (h) {

	mov	ecx, DWORD PTR _h$[ebp]
	mov	DWORD PTR -124+[ebp], ecx
	cmp	DWORD PTR -124+[ebp], 1
	je	SHORT $L67931

; 1594 :                     default: YCbCrtoRGB(cp1[2], pp[ 6]); /* FALLTHROUGH */

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+6]
	mov	DWORD PTR _Y$67925[ebp], eax
	mov	ecx, DWORD PTR _Cr$67895[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67925[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67894[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67895[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67925[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67894[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67925[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [ecx+8], edx
$L67931:

; 1595 :                     case 1:  YCbCrtoRGB(cp [2], pp[ 2]); /* FALLTHROUGH */

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	mov	DWORD PTR _Y$67932[ebp], eax
	mov	ecx, DWORD PTR _Cr$67895[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$67932[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$67894[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$67895[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$67932[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$67894[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67932[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx+8], edx
$L67921:

; 1597 :                 case 2:
; 1598 :                     switch (h) {

	mov	edx, DWORD PTR _h$[ebp]
	mov	DWORD PTR -128+[ebp], edx
	cmp	DWORD PTR -128+[ebp], 1
	je	SHORT $L67950

; 1599 :                     default: YCbCrtoRGB(cp1[1], pp[ 5]); /* FALLTHROUGH */

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+5]
	mov	DWORD PTR _Y$67944[ebp], ecx
	mov	edx, DWORD PTR _Cr$67895[ebp]
	mov	eax, DWORD PTR _Crrtab$[ebp]
	mov	ecx, DWORD PTR _Y$67944[ebp]
	add	ecx, DWORD PTR [eax+edx*4]
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _Cb$67894[ebp]
	mov	edx, DWORD PTR _Cbgtab$[ebp]
	mov	ecx, DWORD PTR [edx+ecx*4]
	mov	edx, DWORD PTR _Cr$67895[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	ecx, DWORD PTR [esi+edx*4]
	sar	ecx, 16					; 00000010H
	mov	edx, DWORD PTR _Y$67944[ebp]
	add	edx, ecx
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [ecx+edx]
	shl	ebx, 8
	or	eax, ebx
	mov	edx, DWORD PTR _Cb$67894[ebp]
	mov	ecx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67944[ebp]
	add	esi, DWORD PTR [ecx+edx*4]
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+esi]
	shl	ecx, 16					; 00000010H
	or	eax, ecx
	or	eax, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [edx+4], eax
$L67950:

; 1600 :                     case 1:  YCbCrtoRGB(cp [1], pp[ 1]); /* FALLTHROUGH */

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	DWORD PTR _Y$67951[ebp], ecx
	mov	edx, DWORD PTR _Cr$67895[ebp]
	mov	eax, DWORD PTR _Crrtab$[ebp]
	mov	ecx, DWORD PTR _Y$67951[ebp]
	add	ecx, DWORD PTR [eax+edx*4]
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _Cb$67894[ebp]
	mov	edx, DWORD PTR _Cbgtab$[ebp]
	mov	ecx, DWORD PTR [edx+ecx*4]
	mov	edx, DWORD PTR _Cr$67895[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	ecx, DWORD PTR [esi+edx*4]
	sar	ecx, 16					; 00000010H
	mov	edx, DWORD PTR _Y$67951[ebp]
	add	edx, ecx
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [ecx+edx]
	shl	ebx, 8
	or	eax, ebx
	mov	edx, DWORD PTR _Cb$67894[ebp]
	mov	ecx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67951[ebp]
	add	esi, DWORD PTR [ecx+edx*4]
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+esi]
	shl	ecx, 16					; 00000010H
	or	eax, ecx
	or	eax, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx+4], eax
$L67940:

; 1602 :                 case 1:
; 1603 :                     switch (h) {

	mov	eax, DWORD PTR _h$[ebp]
	mov	DWORD PTR -132+[ebp], eax
	cmp	DWORD PTR -132+[ebp], 1
	je	SHORT $L67969

; 1604 :                     default: YCbCrtoRGB(cp1[0], pp[ 4]); /* FALLTHROUGH */

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+4]
	mov	DWORD PTR _Y$67963[ebp], edx
	mov	eax, DWORD PTR _Cr$67895[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67963[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67894[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67895[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67963[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67894[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67963[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [eax], ecx
$L67969:

; 1605 :                     case 1:  YCbCrtoRGB(cp [0], pp[ 0]); /* FALLTHROUGH */

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	DWORD PTR _Y$67970[ebp], edx
	mov	eax, DWORD PTR _Cr$67895[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$67970[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$67894[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$67895[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$67970[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$67894[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$67970[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], ecx

; 1608 :                 if (x < 4) {

	cmp	DWORD PTR _x$[ebp], 4
	jae	SHORT $L67976

; 1609 :                     cp += x; cp1 += x;

	mov	ecx, DWORD PTR _x$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _x$[ebp]
	mov	edx, DWORD PTR _cp1$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp1$[ebp], eax

; 1610 :                     x = 0;

	mov	DWORD PTR _x$[ebp], 0

; 1612 :                 else {

	jmp	SHORT $L67977
$L67976:

; 1613 :                     cp += 4; cp1 += 4;

	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 16					; 00000010H
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _cp1$[ebp]
	add	edx, 16					; 00000010H
	mov	DWORD PTR _cp1$[ebp], edx

; 1614 :                     x -= 4;

	mov	eax, DWORD PTR _x$[ebp]
	sub	eax, 4
	mov	DWORD PTR _x$[ebp], eax
$L67977:

; 1616 :                 pp += 10;

	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, 10					; 0000000aH
	mov	DWORD PTR _pp$[ebp], ecx

; 1617 :             }

	jmp	$L67892
$L67893:

; 1618 :             if (h <= 2)

	cmp	DWORD PTR _h$[ebp], 2
	ja	SHORT $L67978

; 1619 :                 break;

	jmp	SHORT $L67890
$L67978:

; 1620 :             h -= 2;

	mov	edx, DWORD PTR _h$[ebp]
	sub	edx, 2
	mov	DWORD PTR _h$[ebp], edx

; 1621 :             cp += incr, cp1 += incr;

	mov	eax, DWORD PTR _incr$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	lea	edx, DWORD PTR [ecx+eax*4]
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _incr$[ebp]
	mov	ecx, DWORD PTR _cp1$[ebp]
	lea	edx, DWORD PTR [ecx+eax*4]
	mov	DWORD PTR _cp1$[ebp], edx

; 1622 :             pp += fromskew;

	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], eax

; 1623 :         }

	jmp	$L67830
$L67890:

; 1625 : }

	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_putcontig8bitYCbCr42tile ENDP
_img$ = 8
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_ycbcr$ = -16
_Crrtab$ = -12
_Cbbtab$ = -8
_Crgtab$ = -4
_Cbgtab$ = -24
_clamptab$ = -20
_Cb$68012 = -32
_Cr$68013 = -28
_Y$68014 = -36
_Y$68020 = -40
_Y$68026 = -44
_Y$68032 = -48
_Cb$68039 = -56
_Cr$68040 = -52
_Y$68046 = -60
_Y$68053 = -64
_Y$68060 = -68
_putcontig8bitYCbCr41tile PROC NEAR

; 1631 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H
	push	ebx
	push	esi

; 1632 :     YCbCrSetup;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+64]
	mov	DWORD PTR _ycbcr$[ebp], ecx
	mov	edx, DWORD PTR _ycbcr$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _Crrtab$[ebp], eax
	mov	ecx, DWORD PTR _ycbcr$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR _Cbbtab$[ebp], edx
	mov	eax, DWORD PTR _ycbcr$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _Crgtab$[ebp], ecx
	mov	edx, DWORD PTR _ycbcr$[ebp]
	mov	eax, DWORD PTR [edx+16]
	mov	DWORD PTR _Cbgtab$[ebp], eax
	mov	ecx, DWORD PTR _ycbcr$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR _clamptab$[ebp], edx
$L68006:

; 1637 : 	x = w>>2;

	mov	eax, DWORD PTR _w$[ebp]
	shr	eax, 2
	mov	DWORD PTR _x$[ebp], eax
$L68009:

; 1639 : 	    int Cb = pp[4];

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+4]
	mov	DWORD PTR _Cb$68012[ebp], edx

; 1640 : 	    int Cr = pp[5];

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+5]
	mov	DWORD PTR _Cr$68013[ebp], ecx

; 1641 : 
; 1642 : 	    YCbCrtoRGB(cp [0], pp[0]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	DWORD PTR _Y$68014[ebp], eax
	mov	ecx, DWORD PTR _Cr$68013[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$68014[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$68012[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$68013[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$68014[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$68012[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68014[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], edx

; 1643 : 	    YCbCrtoRGB(cp [1], pp[1]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	mov	DWORD PTR _Y$68020[ebp], eax
	mov	ecx, DWORD PTR _Cr$68013[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$68020[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$68012[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$68013[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$68020[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$68012[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68020[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx+4], edx

; 1644 : 	    YCbCrtoRGB(cp [2], pp[2]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	mov	DWORD PTR _Y$68026[ebp], eax
	mov	ecx, DWORD PTR _Cr$68013[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$68026[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$68012[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$68013[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$68026[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$68012[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68026[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx+8], edx

; 1645 : 	    YCbCrtoRGB(cp [3], pp[3]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+3]
	mov	DWORD PTR _Y$68032[ebp], eax
	mov	ecx, DWORD PTR _Cr$68013[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$68032[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$68012[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$68013[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$68032[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$68012[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68032[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx+12], edx

; 1646 : 
; 1647 : 	    cp += 4;

	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 16					; 00000010H
	mov	DWORD PTR _cp$[ebp], edx

; 1648 : 	    pp += 6;

	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, 6
	mov	DWORD PTR _pp$[ebp], eax

; 1649 : 	} while (--x);

	mov	ecx, DWORD PTR _x$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _x$[ebp], ecx
	cmp	DWORD PTR _x$[ebp], 0
	jne	$L68009

; 1650 : 
; 1651 :         if( (w&3) != 0 )

	mov	edx, DWORD PTR _w$[ebp]
	and	edx, 3
	test	edx, edx
	je	$L68038

; 1653 : 	    int Cb = pp[4];

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+4]
	mov	DWORD PTR _Cb$68039[ebp], ecx

; 1654 : 	    int Cr = pp[5];

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+5]
	mov	DWORD PTR _Cr$68040[ebp], eax

; 1655 : 
; 1656 :             switch( (w&3) ) {

	mov	ecx, DWORD PTR _w$[ebp]
	and	ecx, 3
	mov	DWORD PTR -72+[ebp], ecx
	cmp	DWORD PTR -72+[ebp], 1
	je	$L68059
	cmp	DWORD PTR -72+[ebp], 2
	je	SHORT $L68052
	cmp	DWORD PTR -72+[ebp], 3
	je	SHORT $L68045
	jmp	$L68042
$L68045:

; 1657 :               case 3: YCbCrtoRGB(cp [2], pp[2]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	mov	DWORD PTR _Y$68046[ebp], eax
	mov	ecx, DWORD PTR _Cr$68040[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$68046[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$68039[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$68040[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$68046[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$68039[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68046[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx+8], edx
$L68052:

; 1658 :               case 2: YCbCrtoRGB(cp [1], pp[1]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	mov	DWORD PTR _Y$68053[ebp], eax
	mov	ecx, DWORD PTR _Cr$68040[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$68053[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$68039[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$68040[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$68053[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$68039[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68053[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx+4], edx
$L68059:

; 1659 :               case 1: YCbCrtoRGB(cp [0], pp[0]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	DWORD PTR _Y$68060[ebp], eax
	mov	ecx, DWORD PTR _Cr$68040[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$68060[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$68039[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$68040[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$68060[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$68039[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68060[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], edx
$L68042:

; 1662 : 
; 1663 :             cp += (w&3);

	mov	edx, DWORD PTR _w$[ebp]
	and	edx, 3
	mov	eax, DWORD PTR _cp$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp$[ebp], ecx

; 1664 :             pp += 6;

	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, 6
	mov	DWORD PTR _pp$[ebp], edx
$L68038:

; 1666 : 
; 1667 : 	cp += toskew;

	mov	eax, DWORD PTR _toskew$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	lea	edx, DWORD PTR [ecx+eax*4]
	mov	DWORD PTR _cp$[ebp], edx

; 1668 : 	pp += fromskew;

	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], eax

; 1669 :     } while (--h);

	mov	ecx, DWORD PTR _h$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _h$[ebp], ecx
	cmp	DWORD PTR _h$[ebp], 0
	jne	$L68006

; 1670 : 
; 1671 : }

	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_putcontig8bitYCbCr41tile ENDP
_img$ = 8
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_ycbcr$ = -24
_Crrtab$ = -20
_Cbbtab$ = -12
_Crgtab$ = -8
_Cbgtab$ = -32
_clamptab$ = -28
_cp1$ = -16
_incr$ = -4
_Cb$68103 = -40
_Cr$68104 = -36
_Y$68105 = -44
_Y$68111 = -48
_Y$68117 = -52
_Y$68123 = -56
_Cb$68136 = -64
_Cr$68137 = -60
_Y$68148 = -68
_Y$68155 = -72
_Y$68167 = -76
_Y$68174 = -80
_putcontig8bitYCbCr22tile PROC NEAR

; 1677 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 92					; 0000005cH
	push	ebx
	push	esi

; 1678 :     YCbCrSetup;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+64]
	mov	DWORD PTR _ycbcr$[ebp], ecx
	mov	edx, DWORD PTR _ycbcr$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _Crrtab$[ebp], eax
	mov	ecx, DWORD PTR _ycbcr$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR _Cbbtab$[ebp], edx
	mov	eax, DWORD PTR _ycbcr$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _Crgtab$[ebp], ecx
	mov	edx, DWORD PTR _ycbcr$[ebp]
	mov	eax, DWORD PTR [edx+16]
	mov	DWORD PTR _Cbgtab$[ebp], eax
	mov	ecx, DWORD PTR _ycbcr$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR _clamptab$[ebp], edx

; 1679 :     uint32* cp1 = cp+w+toskew;

	mov	eax, DWORD PTR _w$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	lea	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _toskew$[ebp]
	lea	ecx, DWORD PTR [edx+eax*4]
	mov	DWORD PTR _cp1$[ebp], ecx

; 1680 :     int32 incr = 2*toskew+w;

	mov	edx, DWORD PTR _toskew$[ebp]
	mov	eax, DWORD PTR _w$[ebp]
	lea	ecx, DWORD PTR [eax+edx*2]
	mov	DWORD PTR _incr$[ebp], ecx

; 1681 : 
; 1682 :     (void) y;
; 1683 :     fromskew = (fromskew * 6) / 2;

	mov	eax, DWORD PTR _fromskew$[ebp]
	imul	eax, 6
	cdq
	sub	eax, edx
	sar	eax, 1
	mov	DWORD PTR _fromskew$[ebp], eax

; 1684 :     if ((h & 1) == 0 && (w & 1) == 0) {

	mov	edx, DWORD PTR _h$[ebp]
	and	edx, 1
	test	edx, edx
	jne	$L68096
	mov	eax, DWORD PTR _w$[ebp]
	and	eax, 1
	test	eax, eax
	jne	$L68096

; 1685 :         for (; h >= 2; h -= 2) {

	jmp	SHORT $L68097
$L68098:
	mov	ecx, DWORD PTR _h$[ebp]
	sub	ecx, 2
	mov	DWORD PTR _h$[ebp], ecx
$L68097:
	cmp	DWORD PTR _h$[ebp], 2
	jb	$L68099

; 1686 :             x = w>>1;

	mov	edx, DWORD PTR _w$[ebp]
	shr	edx, 1
	mov	DWORD PTR _x$[ebp], edx
$L68100:

; 1688 :                 int Cb = pp[4];

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+4]
	mov	DWORD PTR _Cb$68103[ebp], ecx

; 1689 :                 int Cr = pp[5];

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+5]
	mov	DWORD PTR _Cr$68104[ebp], eax

; 1690 : 
; 1691 :                 YCbCrtoRGB(cp [0], pp[0]);

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	DWORD PTR _Y$68105[ebp], edx
	mov	eax, DWORD PTR _Cr$68104[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$68105[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$68103[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$68104[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$68105[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$68103[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68105[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], ecx

; 1692 :                 YCbCrtoRGB(cp [1], pp[1]);

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	mov	DWORD PTR _Y$68111[ebp], edx
	mov	eax, DWORD PTR _Cr$68104[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$68111[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$68103[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$68104[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$68111[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$68103[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68111[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax+4], ecx

; 1693 :                 YCbCrtoRGB(cp1[0], pp[2]);

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+2]
	mov	DWORD PTR _Y$68117[ebp], edx
	mov	eax, DWORD PTR _Cr$68104[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$68117[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$68103[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$68104[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$68117[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$68103[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68117[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [eax], ecx

; 1694 :                 YCbCrtoRGB(cp1[1], pp[3]);

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+3]
	mov	DWORD PTR _Y$68123[ebp], edx
	mov	eax, DWORD PTR _Cr$68104[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$68123[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$68103[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$68104[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$68123[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$68103[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68123[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [eax+4], ecx

; 1695 : 
; 1696 :                 cp += 2, cp1 += 2;

	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 8
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _cp1$[ebp]
	add	edx, 8
	mov	DWORD PTR _cp1$[ebp], edx

; 1697 :                 pp += 6;

	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, 6
	mov	DWORD PTR _pp$[ebp], eax

; 1698 :             } while (--x);

	mov	ecx, DWORD PTR _x$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _x$[ebp], ecx
	cmp	DWORD PTR _x$[ebp], 0
	jne	$L68100

; 1699 :             cp += incr, cp1 += incr;

	mov	edx, DWORD PTR _incr$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _incr$[ebp]
	mov	eax, DWORD PTR _cp1$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp1$[ebp], ecx

; 1700 :             pp += fromskew;

	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], edx

; 1701 :         }

	jmp	$L68098
$L68099:

; 1702 :     } else {

	jmp	$L68132
$L68096:

; 1703 :         while (h > 0) {

	cmp	DWORD PTR _h$[ebp], 0
	jbe	$L68132

; 1704 :             for (x = w; x > 0;) {

	mov	eax, DWORD PTR _w$[ebp]
	mov	DWORD PTR _x$[ebp], eax
$L68134:
	cmp	DWORD PTR _x$[ebp], 0
	jbe	$L68135

; 1705 :                 int Cb = pp[4];

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+4]
	mov	DWORD PTR _Cb$68136[ebp], edx

; 1706 :                 int Cr = pp[5];

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+5]
	mov	DWORD PTR _Cr$68137[ebp], ecx

; 1707 :                 switch (x) {

	mov	edx, DWORD PTR _x$[ebp]
	mov	DWORD PTR -84+[ebp], edx
	cmp	DWORD PTR -84+[ebp], 1
	je	$L68144

; 1708 :                 default:
; 1709 :                     switch (h) {

	mov	eax, DWORD PTR _h$[ebp]
	mov	DWORD PTR -88+[ebp], eax
	cmp	DWORD PTR -88+[ebp], 1
	je	SHORT $L68154

; 1710 :                     default: YCbCrtoRGB(cp1[1], pp[ 3]); /* FALLTHROUGH */

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+3]
	mov	DWORD PTR _Y$68148[ebp], edx
	mov	eax, DWORD PTR _Cr$68137[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$68148[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$68136[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$68137[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$68148[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$68136[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68148[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [eax+4], ecx
$L68154:

; 1711 :                     case 1:  YCbCrtoRGB(cp [1], pp[ 1]); /* FALLTHROUGH */

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	mov	DWORD PTR _Y$68155[ebp], edx
	mov	eax, DWORD PTR _Cr$68137[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$68155[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$68136[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$68137[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$68155[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$68136[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68155[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax+4], ecx
$L68144:

; 1713 :                 case 1:
; 1714 :                     switch (h) {

	mov	ecx, DWORD PTR _h$[ebp]
	mov	DWORD PTR -92+[ebp], ecx
	cmp	DWORD PTR -92+[ebp], 1
	je	SHORT $L68173

; 1715 :                     default: YCbCrtoRGB(cp1[0], pp[ 2]); /* FALLTHROUGH */

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	mov	DWORD PTR _Y$68167[ebp], eax
	mov	ecx, DWORD PTR _Cr$68137[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$68167[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$68136[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$68137[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$68167[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$68136[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68167[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp1$[ebp]
	mov	DWORD PTR [ecx], edx
$L68173:

; 1716 :                     case 1:  YCbCrtoRGB(cp [0], pp[ 0]); /* FALLTHROUGH */

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	DWORD PTR _Y$68174[ebp], eax
	mov	ecx, DWORD PTR _Cr$68137[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$68174[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$68136[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$68137[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$68174[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$68136[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68174[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], edx

; 1719 :                 if (x < 2) {

	cmp	DWORD PTR _x$[ebp], 2
	jae	SHORT $L68180

; 1720 :                     cp += x; cp1 += x;

	mov	edx, DWORD PTR _x$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _x$[ebp]
	mov	eax, DWORD PTR _cp1$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp1$[ebp], ecx

; 1721 :                     x = 0;

	mov	DWORD PTR _x$[ebp], 0

; 1723 :                 else {

	jmp	SHORT $L68181
$L68180:

; 1724 :                     cp += 2; cp1 += 2;

	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 8
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _cp1$[ebp]
	add	eax, 8
	mov	DWORD PTR _cp1$[ebp], eax

; 1725 :                     x -= 2;

	mov	ecx, DWORD PTR _x$[ebp]
	sub	ecx, 2
	mov	DWORD PTR _x$[ebp], ecx
$L68181:

; 1727 :                 pp += 6;

	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, 6
	mov	DWORD PTR _pp$[ebp], edx

; 1728 :             }

	jmp	$L68134
$L68135:

; 1729 :             if (h <= 2)

	cmp	DWORD PTR _h$[ebp], 2
	ja	SHORT $L68182

; 1730 :                 break;

	jmp	SHORT $L68132
$L68182:

; 1731 :             h -= 2;

	mov	eax, DWORD PTR _h$[ebp]
	sub	eax, 2
	mov	DWORD PTR _h$[ebp], eax

; 1732 :             cp += incr, cp1 += incr;

	mov	ecx, DWORD PTR _incr$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _incr$[ebp]
	mov	edx, DWORD PTR _cp1$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp1$[ebp], eax

; 1733 :             pp += fromskew;

	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], ecx

; 1734 :         }

	jmp	$L68096
$L68132:

; 1736 : }

	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_putcontig8bitYCbCr22tile ENDP
_img$ = 8
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_ycbcr$ = -16
_Crrtab$ = -12
_Cbbtab$ = -8
_Crgtab$ = -4
_Cbgtab$ = -24
_clamptab$ = -20
_Cb$68216 = -32
_Cr$68217 = -28
_Y$68218 = -36
_Y$68224 = -40
_Cb$68231 = -48
_Cr$68232 = -44
_Y$68233 = -52
_putcontig8bitYCbCr21tile PROC NEAR

; 1742 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 52					; 00000034H
	push	ebx
	push	esi

; 1743 :     YCbCrSetup;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+64]
	mov	DWORD PTR _ycbcr$[ebp], ecx
	mov	edx, DWORD PTR _ycbcr$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _Crrtab$[ebp], eax
	mov	ecx, DWORD PTR _ycbcr$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR _Cbbtab$[ebp], edx
	mov	eax, DWORD PTR _ycbcr$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _Crgtab$[ebp], ecx
	mov	edx, DWORD PTR _ycbcr$[ebp]
	mov	eax, DWORD PTR [edx+16]
	mov	DWORD PTR _Cbgtab$[ebp], eax
	mov	ecx, DWORD PTR _ycbcr$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR _clamptab$[ebp], edx

; 1744 : 
; 1745 :     (void) y;
; 1746 :     fromskew = (fromskew * 4) / 2;

	mov	eax, DWORD PTR _fromskew$[ebp]
	shl	eax, 2
	cdq
	sub	eax, edx
	sar	eax, 1
	mov	DWORD PTR _fromskew$[ebp], eax
$L68210:

; 1748 : 	x = w>>1;

	mov	eax, DWORD PTR _w$[ebp]
	shr	eax, 1
	mov	DWORD PTR _x$[ebp], eax
$L68213:

; 1750 : 	    int Cb = pp[2];

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+2]
	mov	DWORD PTR _Cb$68216[ebp], edx

; 1751 : 	    int Cr = pp[3];

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	mov	DWORD PTR _Cr$68217[ebp], ecx

; 1752 : 
; 1753 : 	    YCbCrtoRGB(cp[0], pp[0]); 

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	DWORD PTR _Y$68218[ebp], eax
	mov	ecx, DWORD PTR _Cr$68217[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$68218[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$68216[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$68217[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$68218[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$68216[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68218[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], edx

; 1754 : 	    YCbCrtoRGB(cp[1], pp[1]);

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	mov	DWORD PTR _Y$68224[ebp], eax
	mov	ecx, DWORD PTR _Cr$68217[ebp]
	mov	edx, DWORD PTR _Crrtab$[ebp]
	mov	eax, DWORD PTR _Y$68224[ebp]
	add	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	eax, DWORD PTR _Cb$68216[ebp]
	mov	ecx, DWORD PTR _Cbgtab$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _Cr$68217[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	eax, DWORD PTR [esi+ecx*4]
	sar	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _Y$68224[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [eax+ecx]
	shl	ebx, 8
	or	edx, ebx
	mov	ecx, DWORD PTR _Cb$68216[ebp]
	mov	eax, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68224[ebp]
	add	esi, DWORD PTR [eax+ecx*4]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [ecx+esi]
	shl	eax, 16					; 00000010H
	or	edx, eax
	or	edx, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx+4], edx

; 1755 : 
; 1756 : 	    cp += 2;

	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 8
	mov	DWORD PTR _cp$[ebp], edx

; 1757 : 	    pp += 4;

	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, 4
	mov	DWORD PTR _pp$[ebp], eax

; 1758 : 	} while (--x);

	mov	ecx, DWORD PTR _x$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _x$[ebp], ecx
	cmp	DWORD PTR _x$[ebp], 0
	jne	$L68213

; 1759 : 
; 1760 :         if( (w&1) != 0 )

	mov	edx, DWORD PTR _w$[ebp]
	and	edx, 1
	test	edx, edx
	je	$L68230

; 1762 : 	    int Cb = pp[2];

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+2]
	mov	DWORD PTR _Cb$68231[ebp], ecx

; 1763 : 	    int Cr = pp[3];

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+3]
	mov	DWORD PTR _Cr$68232[ebp], eax

; 1764 :             
; 1765 :             YCbCrtoRGB(cp [0], pp[0]);

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	DWORD PTR _Y$68233[ebp], edx
	mov	eax, DWORD PTR _Cr$68232[ebp]
	mov	ecx, DWORD PTR _Crrtab$[ebp]
	mov	edx, DWORD PTR _Y$68233[ebp]
	add	edx, DWORD PTR [ecx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, DWORD PTR _Cb$68231[ebp]
	mov	eax, DWORD PTR _Cbgtab$[ebp]
	mov	edx, DWORD PTR [eax+edx*4]
	mov	eax, DWORD PTR _Cr$68232[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	edx, DWORD PTR [esi+eax*4]
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _Y$68233[ebp]
	add	eax, edx
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+eax]
	shl	ebx, 8
	or	ecx, ebx
	mov	eax, DWORD PTR _Cb$68231[ebp]
	mov	edx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68233[ebp]
	add	esi, DWORD PTR [edx+eax*4]
	mov	eax, DWORD PTR _clamptab$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [eax+esi]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	or	ecx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], ecx

; 1766 : 
; 1767 : 	    cp += 1;

	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx

; 1768 : 	    pp += 4;

	mov	edx, DWORD PTR _pp$[ebp]
	add	edx, 4
	mov	DWORD PTR _pp$[ebp], edx
$L68230:

; 1770 : 
; 1771 : 	cp += toskew;

	mov	eax, DWORD PTR _toskew$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	lea	edx, DWORD PTR [ecx+eax*4]
	mov	DWORD PTR _cp$[ebp], edx

; 1772 : 	pp += fromskew;

	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], eax

; 1773 :     } while (--h);

	mov	ecx, DWORD PTR _h$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _h$[ebp], ecx
	cmp	DWORD PTR _h$[ebp], 0
	jne	$L68210

; 1774 : }

	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_putcontig8bitYCbCr21tile ENDP
_img$ = 8
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_pp$ = 40
_ycbcr$ = -16
_Crrtab$ = -12
_Cbbtab$ = -8
_Crgtab$ = -4
_Cbgtab$ = -24
_clamptab$ = -20
_Cb$68272 = -32
_Cr$68273 = -28
_Y$68274 = -36
_putcontig8bitYCbCr11tile PROC NEAR

; 1780 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 36					; 00000024H
	push	ebx
	push	esi

; 1781 :     YCbCrSetup;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+64]
	mov	DWORD PTR _ycbcr$[ebp], ecx
	mov	edx, DWORD PTR _ycbcr$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _Crrtab$[ebp], eax
	mov	ecx, DWORD PTR _ycbcr$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR _Cbbtab$[ebp], edx
	mov	eax, DWORD PTR _ycbcr$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _Crgtab$[ebp], ecx
	mov	edx, DWORD PTR _ycbcr$[ebp]
	mov	eax, DWORD PTR [edx+16]
	mov	DWORD PTR _Cbgtab$[ebp], eax
	mov	ecx, DWORD PTR _ycbcr$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR _clamptab$[ebp], edx

; 1782 : 
; 1783 :     (void) y;
; 1784 :     fromskew *= 3;

	mov	eax, DWORD PTR _fromskew$[ebp]
	imul	eax, 3
	mov	DWORD PTR _fromskew$[ebp], eax
$L68266:

; 1786 :         x = w; /* was x = w>>1; patched 2000/09/25 warmerda@home.com */ 

	mov	ecx, DWORD PTR _w$[ebp]
	mov	DWORD PTR _x$[ebp], ecx
$L68269:

; 1788 : 	    int Cb = pp[1];

	mov	edx, DWORD PTR _pp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	mov	DWORD PTR _Cb$68272[ebp], eax

; 1789 : 	    int Cr = pp[2];

	mov	ecx, DWORD PTR _pp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+2]
	mov	DWORD PTR _Cr$68273[ebp], edx

; 1790 : 
; 1791 : 	    YCbCrtoRGB(*cp++, pp[0]);

	mov	eax, DWORD PTR _pp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	DWORD PTR _Y$68274[ebp], ecx
	mov	edx, DWORD PTR _Cr$68273[ebp]
	mov	eax, DWORD PTR _Crrtab$[ebp]
	mov	ecx, DWORD PTR _Y$68274[ebp]
	add	ecx, DWORD PTR [eax+edx*4]
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _Cb$68272[ebp]
	mov	edx, DWORD PTR _Cbgtab$[ebp]
	mov	ecx, DWORD PTR [edx+ecx*4]
	mov	edx, DWORD PTR _Cr$68273[ebp]
	mov	esi, DWORD PTR _Crgtab$[ebp]
	add	ecx, DWORD PTR [esi+edx*4]
	sar	ecx, 16					; 00000010H
	mov	edx, DWORD PTR _Y$68274[ebp]
	add	edx, ecx
	mov	ecx, DWORD PTR _clamptab$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [ecx+edx]
	shl	ebx, 8
	or	eax, ebx
	mov	edx, DWORD PTR _Cb$68272[ebp]
	mov	ecx, DWORD PTR _Cbbtab$[ebp]
	mov	esi, DWORD PTR _Y$68274[ebp]
	add	esi, DWORD PTR [ecx+edx*4]
	mov	edx, DWORD PTR _clamptab$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx+esi]
	shl	ecx, 16					; 00000010H
	or	eax, ecx
	or	eax, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], eax
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax

; 1792 : 
; 1793 : 	    pp += 3;

	mov	ecx, DWORD PTR _pp$[ebp]
	add	ecx, 3
	mov	DWORD PTR _pp$[ebp], ecx

; 1794 : 	} while (--x);

	mov	edx, DWORD PTR _x$[ebp]
	sub	edx, 1
	mov	DWORD PTR _x$[ebp], edx
	cmp	DWORD PTR _x$[ebp], 0
	jne	$L68269

; 1795 : 	cp += toskew;

	mov	eax, DWORD PTR _toskew$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	lea	edx, DWORD PTR [ecx+eax*4]
	mov	DWORD PTR _cp$[ebp], edx

; 1796 : 	pp += fromskew;

	mov	eax, DWORD PTR _pp$[ebp]
	add	eax, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _pp$[ebp], eax

; 1797 :     } while (--h);

	mov	ecx, DWORD PTR _h$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _h$[ebp], ecx
	cmp	DWORD PTR _h$[ebp], 0
	jne	$L68266

; 1798 : }

	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_putcontig8bitYCbCr11tile ENDP
_TEXT	ENDS
PUBLIC	__real@4@40008000000000000000
PUBLIC	__real@4@400f8000000000000000
PUBLIC	__real@8@3ffe8000000000000000
EXTRN	__ftol:NEAR
EXTRN	__fltused:NEAR
EXTRN	__TIFFmemset:NEAR
EXTRN	__TIFFmemcpy:NEAR
;	COMDAT __real@4@40008000000000000000
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_getimage.c
CONST	SEGMENT
__real@4@40008000000000000000 DD 040000000r	; 2
CONST	ENDS
;	COMDAT __real@4@400f8000000000000000
CONST	SEGMENT
__real@4@400f8000000000000000 DD 047800000r	; 65536
CONST	ENDS
;	COMDAT __real@8@3ffe8000000000000000
CONST	SEGMENT
__real@8@3ffe8000000000000000 DQ 03fe0000000000000r ; 0.5
CONST	ENDS
_TEXT	SEGMENT
_ycbcr$ = 8
_tif$ = 12
_clamptab$ = -8
_coeffs$ = -12
_i$ = -4
_f1$68309 = -48
_D1$68310 = -28
_f2$68312 = -16
_D2$68313 = -32
_f3$68315 = -20
_D3$68316 = -36
_f4$68318 = -24
_D4$68319 = -44
_x$68321 = -40
_TIFFYCbCrToRGBInit PROC NEAR

; 1827 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 48					; 00000030H

; 1828 :     TIFFRGBValue* clamptab;
; 1829 :     float* coeffs;
; 1830 :     int i;
; 1831 : 
; 1832 :     clamptab = (TIFFRGBValue*)(
; 1833 : 	(tidata_t) ycbcr+TIFFroundup(sizeof (TIFFYCbCrToRGB), sizeof (long)));

	mov	eax, DWORD PTR _ycbcr$[ebp]
	add	eax, 32					; 00000020H
	mov	DWORD PTR _clamptab$[ebp], eax

; 1834 :     _TIFFmemset(clamptab, 0, 256);		/* v < 0 => 0 */

	push	256					; 00000100H
	push	0
	mov	ecx, DWORD PTR _clamptab$[ebp]
	push	ecx
	call	__TIFFmemset
	add	esp, 12					; 0000000cH

; 1835 :     ycbcr->clamptab = (clamptab += 256);

	mov	edx, DWORD PTR _clamptab$[ebp]
	add	edx, 256				; 00000100H
	mov	DWORD PTR _clamptab$[ebp], edx
	mov	eax, DWORD PTR _ycbcr$[ebp]
	mov	ecx, DWORD PTR _clamptab$[ebp]
	mov	DWORD PTR [eax], ecx

; 1836 :     for (i = 0; i < 256; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L68305
$L68306:
	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	mov	DWORD PTR _i$[ebp], edx
$L68305:
	cmp	DWORD PTR _i$[ebp], 256			; 00000100H
	jge	SHORT $L68307

; 1837 : 	clamptab[i] = i;

	mov	eax, DWORD PTR _clamptab$[ebp]
	add	eax, DWORD PTR _i$[ebp]
	mov	cl, BYTE PTR _i$[ebp]
	mov	BYTE PTR [eax], cl
	jmp	SHORT $L68306
$L68307:

; 1838 :     _TIFFmemset(clamptab+256, 255, 2*256);	/* v > 255 => 255 */

	push	512					; 00000200H
	push	255					; 000000ffH
	mov	edx, DWORD PTR _clamptab$[ebp]
	add	edx, 256				; 00000100H
	push	edx
	call	__TIFFmemset
	add	esp, 12					; 0000000cH

; 1839 :     TIFFGetFieldDefaulted(tif, TIFFTAG_YCBCRCOEFFICIENTS, &coeffs);

	lea	eax, DWORD PTR _coeffs$[ebp]
	push	eax
	push	529					; 00000211H
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFGetFieldDefaulted
	add	esp, 12					; 0000000cH

; 1840 :     _TIFFmemcpy(ycbcr->coeffs, coeffs, 3*sizeof (float));

	push	12					; 0000000cH
	mov	edx, DWORD PTR _coeffs$[ebp]
	push	edx
	mov	eax, DWORD PTR _ycbcr$[ebp]
	add	eax, 20					; 00000014H
	push	eax
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH

; 1841 :     { float f1 = 2-2*LumaRed;		int32 D1 = FIX(f1);

	mov	ecx, DWORD PTR _coeffs$[ebp]
	fld	DWORD PTR __real@4@40008000000000000000
	fmul	DWORD PTR [ecx]
	fsubr	DWORD PTR __real@4@40008000000000000000
	fst	DWORD PTR _f1$68309[ebp]
	fmul	DWORD PTR __real@4@400f8000000000000000
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	call	__ftol
	mov	DWORD PTR _D1$68310[ebp], eax

; 1842 :       float f2 = LumaRed*f1/LumaGreen;	int32 D2 = -FIX(f2);

	mov	edx, DWORD PTR _coeffs$[ebp]
	fld	DWORD PTR _f1$68309[ebp]
	fmul	DWORD PTR [edx]
	mov	eax, DWORD PTR _coeffs$[ebp]
	fdiv	DWORD PTR [eax+4]
	fst	DWORD PTR _f2$68312[ebp]
	fmul	DWORD PTR __real@4@400f8000000000000000
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	call	__ftol
	neg	eax
	mov	DWORD PTR _D2$68313[ebp], eax

; 1843 :       float f3 = 2-2*LumaBlue;		int32 D3 = FIX(f3);

	mov	ecx, DWORD PTR _coeffs$[ebp]
	fld	DWORD PTR __real@4@40008000000000000000
	fmul	DWORD PTR [ecx+8]
	fsubr	DWORD PTR __real@4@40008000000000000000
	fst	DWORD PTR _f3$68315[ebp]
	fmul	DWORD PTR __real@4@400f8000000000000000
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	call	__ftol
	mov	DWORD PTR _D3$68316[ebp], eax

; 1844 :       float f4 = LumaBlue*f3/LumaGreen;	int32 D4 = -FIX(f4);

	mov	edx, DWORD PTR _coeffs$[ebp]
	fld	DWORD PTR _f3$68315[ebp]
	fmul	DWORD PTR [edx+8]
	mov	eax, DWORD PTR _coeffs$[ebp]
	fdiv	DWORD PTR [eax+4]
	fst	DWORD PTR _f4$68318[ebp]
	fmul	DWORD PTR __real@4@400f8000000000000000
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	call	__ftol
	neg	eax
	mov	DWORD PTR _D4$68319[ebp], eax

; 1845 :       int x;
; 1846 : 
; 1847 :       ycbcr->Cr_r_tab = (int*) (clamptab + 3*256);

	mov	ecx, DWORD PTR _clamptab$[ebp]
	add	ecx, 768				; 00000300H
	mov	edx, DWORD PTR _ycbcr$[ebp]
	mov	DWORD PTR [edx+4], ecx

; 1848 :       ycbcr->Cb_b_tab = ycbcr->Cr_r_tab + 256;

	mov	eax, DWORD PTR _ycbcr$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	add	ecx, 1024				; 00000400H
	mov	edx, DWORD PTR _ycbcr$[ebp]
	mov	DWORD PTR [edx+8], ecx

; 1849 :       ycbcr->Cr_g_tab = (int32*) (ycbcr->Cb_b_tab + 256);

	mov	eax, DWORD PTR _ycbcr$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	add	ecx, 1024				; 00000400H
	mov	edx, DWORD PTR _ycbcr$[ebp]
	mov	DWORD PTR [edx+12], ecx

; 1850 :       ycbcr->Cb_g_tab = ycbcr->Cr_g_tab + 256;

	mov	eax, DWORD PTR _ycbcr$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	add	ecx, 1024				; 00000400H
	mov	edx, DWORD PTR _ycbcr$[ebp]
	mov	DWORD PTR [edx+16], ecx

; 1851 :       /*
; 1852 :        * i is the actual input pixel value in the range 0..255
; 1853 :        * Cb and Cr values are in the range -128..127 (actually
; 1854 :        * they are in a range defined by the ReferenceBlackWhite
; 1855 :        * tag) so there is some range shifting to do here when
; 1856 :        * constructing tables indexed by the raw pixel data.
; 1857 :        *
; 1858 :        * XXX handle ReferenceBlackWhite correctly to calculate
; 1859 :        *     Cb/Cr values to use in constructing the tables.
; 1860 :        */
; 1861 :       for (i = 0, x = -128; i < 256; i++, x++) {

	mov	DWORD PTR _i$[ebp], 0
	mov	DWORD PTR _x$68321[ebp], -128		; ffffff80H
	jmp	SHORT $L68324
$L68325:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
	mov	ecx, DWORD PTR _x$68321[ebp]
	add	ecx, 1
	mov	DWORD PTR _x$68321[ebp], ecx
$L68324:
	cmp	DWORD PTR _i$[ebp], 256			; 00000100H
	jge	SHORT $L68326

; 1862 : 	  ycbcr->Cr_r_tab[i] = (int)((D1*x + ONE_HALF)>>SHIFT);

	mov	edx, DWORD PTR _D1$68310[ebp]
	imul	edx, DWORD PTR _x$68321[ebp]
	add	edx, 32768				; 00008000H
	sar	edx, 16					; 00000010H
	mov	eax, DWORD PTR _ycbcr$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	mov	eax, DWORD PTR _i$[ebp]
	mov	DWORD PTR [ecx+eax*4], edx

; 1863 : 	  ycbcr->Cb_b_tab[i] = (int)((D3*x + ONE_HALF)>>SHIFT);

	mov	ecx, DWORD PTR _D3$68316[ebp]
	imul	ecx, DWORD PTR _x$68321[ebp]
	add	ecx, 32768				; 00008000H
	sar	ecx, 16					; 00000010H
	mov	edx, DWORD PTR _ycbcr$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	edx, DWORD PTR _i$[ebp]
	mov	DWORD PTR [eax+edx*4], ecx

; 1864 : 	  ycbcr->Cr_g_tab[i] = D2*x;

	mov	eax, DWORD PTR _D2$68313[ebp]
	imul	eax, DWORD PTR _x$68321[ebp]
	mov	ecx, DWORD PTR _ycbcr$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	ecx, DWORD PTR _i$[ebp]
	mov	DWORD PTR [edx+ecx*4], eax

; 1865 : 	  ycbcr->Cb_g_tab[i] = D4*x + ONE_HALF;

	mov	edx, DWORD PTR _D4$68319[ebp]
	imul	edx, DWORD PTR _x$68321[ebp]
	add	edx, 32768				; 00008000H
	mov	eax, DWORD PTR _ycbcr$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	mov	eax, DWORD PTR _i$[ebp]
	mov	DWORD PTR [ecx+eax*4], edx

; 1866 :       }

	jmp	$L68325
$L68326:

; 1868 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFYCbCrToRGBInit ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+3
$SG68623 DB	'Assuming 8-bit colormap', 00H
_DATA	ENDS
_TEXT	SEGMENT
_img$ = 8
_buildMap PROC NEAR

; 2121 : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 2122 :     switch (img->photometric) {

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+30]
	mov	DWORD PTR -4+[ebp], ecx
	cmp	DWORD PTR -4+[ebp], 6
	ja	$L68613
	mov	edx, DWORD PTR -4+[ebp]
	jmp	DWORD PTR $L68864[edx*4]
$L68616:

; 2123 :     case PHOTOMETRIC_RGB:
; 2124 :     case PHOTOMETRIC_YCBCR:
; 2125 :     case PHOTOMETRIC_SEPARATED:
; 2126 : 	if (img->bitspersample == 8)

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+24]
	cmp	ecx, 8
	jne	SHORT $L68617

; 2127 : 	    break;

	jmp	SHORT $L68613
$L68617:

; 2128 : 	/* fall thru... */
; 2129 :     case PHOTOMETRIC_MINISBLACK:
; 2130 :     case PHOTOMETRIC_MINISWHITE:
; 2131 : 	if (!setupMap(img))

	mov	edx, DWORD PTR _img$[ebp]
	push	edx
	call	_setupMap
	add	esp, 4
	test	eax, eax
	jne	SHORT $L68619

; 2132 : 	    return (0);

	xor	eax, eax
	jmp	SHORT $L68611
$L68619:

; 2133 : 	break;

	jmp	SHORT $L68613
$L68620:

; 2134 :     case PHOTOMETRIC_PALETTE:
; 2135 : 	/*
; 2136 : 	 * Convert 16-bit colormap to 8-bit (unless it looks
; 2137 : 	 * like an old-style 8-bit colormap).
; 2138 : 	 */
; 2139 : 	if (checkcmap(img) == 16)

	mov	eax, DWORD PTR _img$[ebp]
	push	eax
	call	_checkcmap
	add	esp, 4
	cmp	eax, 16					; 00000010H
	jne	SHORT $L68621

; 2140 : 	    cvtcmap(img);

	mov	ecx, DWORD PTR _img$[ebp]
	push	ecx
	call	_cvtcmap
	add	esp, 4

; 2141 : 	else

	jmp	SHORT $L68622
$L68621:

; 2142 : 	    TIFFWarning(TIFFFileName(img->tif), "Assuming 8-bit colormap");

	push	OFFSET FLAT:$SG68623
	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFWarning
	add	esp, 8
$L68622:

; 2143 : 	/*
; 2144 : 	 * Use mapping table and colormap to construct
; 2145 : 	 * unpacking tables for samples < 8 bits.
; 2146 : 	 */
; 2147 : 	if (img->bitspersample <= 8 && !makecmap(img))

	mov	ecx, DWORD PTR _img$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+24]
	cmp	edx, 8
	jg	SHORT $L68624
	mov	eax, DWORD PTR _img$[ebp]
	push	eax
	call	_makecmap
	add	esp, 4
	test	eax, eax
	jne	SHORT $L68624

; 2148 : 	    return (0);

	xor	eax, eax
	jmp	SHORT $L68611
$L68624:
$L68613:

; 2151 :     return (1);

	mov	eax, 1
$L68611:

; 2152 : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68864:
	DD	$L68617
	DD	$L68617
	DD	$L68616
	DD	$L68620
	DD	$L68613
	DD	$L68616
	DD	$L68616
_buildMap ENDP
_TEXT	ENDS
_DATA	SEGMENT
$SG68474 DB	'No space for photometric conversion table', 00H
_DATA	ENDS
_TEXT	SEGMENT
_img$ = 8
_x$ = -4
_range$ = -8
_setupMap PROC NEAR

; 1988 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 1989 :     int32 x, range;
; 1990 : 
; 1991 :     range = (int32)((1L<<img->bitspersample)-1);

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+24]
	mov	edx, 1
	shl	edx, cl
	sub	edx, 1
	mov	DWORD PTR _range$[ebp], edx

; 1992 :     
; 1993 :     /* treat 16 bit the same as eight bit */
; 1994 :     if( img->bitspersample == 16 )

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+24]
	cmp	ecx, 16					; 00000010H
	jne	SHORT $L68468

; 1995 :         range = (int32) 255;

	mov	DWORD PTR _range$[ebp], 255		; 000000ffH
$L68468:

; 1996 : 
; 1997 :     img->Map = (TIFFRGBValue*) _TIFFmalloc((range+1) * sizeof (TIFFRGBValue));

	mov	edx, DWORD PTR _range$[ebp]
	add	edx, 1
	push	edx
	call	__TIFFmalloc
	add	esp, 4
	mov	ecx, DWORD PTR _img$[ebp]
	mov	DWORD PTR [ecx+52], eax

; 1998 :     if (img->Map == NULL) {

	mov	edx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [edx+52], 0
	jne	SHORT $L68473

; 1999 : 	TIFFError(TIFFFileName(img->tif),
; 2000 : 	    "No space for photometric conversion table");

	push	OFFSET FLAT:$SG68474
	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 2001 : 	return (0);

	xor	eax, eax
	jmp	$L68464
$L68473:

; 2003 :     if (img->photometric == PHOTOMETRIC_MINISWHITE) {

	mov	edx, DWORD PTR _img$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+30]
	test	eax, eax
	jne	SHORT $L68475

; 2004 : 	for (x = 0; x <= range; x++)

	mov	DWORD PTR _x$[ebp], 0
	jmp	SHORT $L68476
$L68477:
	mov	ecx, DWORD PTR _x$[ebp]
	add	ecx, 1
	mov	DWORD PTR _x$[ebp], ecx
$L68476:
	mov	edx, DWORD PTR _x$[ebp]
	cmp	edx, DWORD PTR _range$[ebp]
	jg	SHORT $L68478

; 2005 : 	    img->Map[x] = (TIFFRGBValue) (((range - x) * 255) / range);

	mov	eax, DWORD PTR _range$[ebp]
	sub	eax, DWORD PTR _x$[ebp]
	imul	eax, 255				; 000000ffH
	cdq
	idiv	DWORD PTR _range$[ebp]
	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR [ecx+52]
	mov	ecx, DWORD PTR _x$[ebp]
	mov	BYTE PTR [edx+ecx], al
	jmp	SHORT $L68477
$L68478:

; 2006 :     } else {

	jmp	SHORT $L68483
$L68475:

; 2007 : 	for (x = 0; x <= range; x++)

	mov	DWORD PTR _x$[ebp], 0
	jmp	SHORT $L68481
$L68482:
	mov	edx, DWORD PTR _x$[ebp]
	add	edx, 1
	mov	DWORD PTR _x$[ebp], edx
$L68481:
	mov	eax, DWORD PTR _x$[ebp]
	cmp	eax, DWORD PTR _range$[ebp]
	jg	SHORT $L68483

; 2008 : 	    img->Map[x] = (TIFFRGBValue) ((x * 255) / range);

	mov	eax, DWORD PTR _x$[ebp]
	imul	eax, 255				; 000000ffH
	cdq
	idiv	DWORD PTR _range$[ebp]
	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR [ecx+52]
	mov	ecx, DWORD PTR _x$[ebp]
	mov	BYTE PTR [edx+ecx], al
	jmp	SHORT $L68482
$L68483:

; 2010 :     if (img->bitspersample <= 16 &&
; 2011 : 	(img->photometric == PHOTOMETRIC_MINISBLACK ||
; 2012 : 	 img->photometric == PHOTOMETRIC_MINISWHITE)) {

	mov	edx, DWORD PTR _img$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+24]
	cmp	eax, 16					; 00000010H
	jg	SHORT $L68485
	mov	ecx, DWORD PTR _img$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+30]
	cmp	edx, 1
	je	SHORT $L68486
	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+30]
	test	ecx, ecx
	jne	SHORT $L68485
$L68486:

; 2013 : 	/*
; 2014 : 	 * Use photometric mapping table to construct
; 2015 : 	 * unpacking tables for samples <= 8 bits.
; 2016 : 	 */
; 2017 : 	if (!makebwmap(img))

	mov	edx, DWORD PTR _img$[ebp]
	push	edx
	call	_makebwmap
	add	esp, 4
	test	eax, eax
	jne	SHORT $L68487

; 2018 : 	    return (0);

	xor	eax, eax
	jmp	SHORT $L68464
$L68487:

; 2019 : 	/* no longer need Map, free it */
; 2020 : 	_TIFFfree(img->Map), img->Map = NULL;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+52]
	push	ecx
	call	__TIFFfree
	add	esp, 4
	mov	edx, DWORD PTR _img$[ebp]
	mov	DWORD PTR [edx+52], 0
$L68485:

; 2022 :     return (1);

	mov	eax, 1
$L68464:

; 2023 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_setupMap ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+2
$SG68386 DB	'No space for B&W mapping table', 00H
_DATA	ENDS
_TEXT	SEGMENT
_img$ = 8
_Map$ = -20
_bitspersample$ = -8
_nsamples$ = -12
_i$ = -16
_p$ = -4
_c$68391 = -24
_makebwmap PROC NEAR

; 1929 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 28					; 0000001cH

; 1930 :     TIFFRGBValue* Map = img->Map;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+52]
	mov	DWORD PTR _Map$[ebp], ecx

; 1931 :     int bitspersample = img->bitspersample;

	mov	edx, DWORD PTR _img$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+24]
	mov	DWORD PTR _bitspersample$[ebp], eax

; 1932 :     int nsamples = 8 / bitspersample;

	mov	eax, 8
	cdq
	idiv	DWORD PTR _bitspersample$[ebp]
	mov	DWORD PTR _nsamples$[ebp], eax

; 1933 :     int i;
; 1934 :     uint32* p;
; 1935 : 
; 1936 :     if( nsamples == 0 )

	cmp	DWORD PTR _nsamples$[ebp], 0
	jne	SHORT $L68380

; 1937 :         nsamples = 1;

	mov	DWORD PTR _nsamples$[ebp], 1
$L68380:

; 1938 : 
; 1939 :     img->BWmap = (uint32**) _TIFFmalloc(
; 1940 : 	256*sizeof (uint32 *)+(256*nsamples*sizeof(uint32)));

	mov	ecx, DWORD PTR _nsamples$[ebp]
	shl	ecx, 8
	lea	edx, DWORD PTR [ecx*4+1024]
	push	edx
	call	__TIFFmalloc
	add	esp, 4
	mov	ecx, DWORD PTR _img$[ebp]
	mov	DWORD PTR [ecx+56], eax

; 1941 :     if (img->BWmap == NULL) {

	mov	edx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [edx+56], 0
	jne	SHORT $L68385

; 1942 : 	TIFFError(TIFFFileName(img->tif), "No space for B&W mapping table");

	push	OFFSET FLAT:$SG68386
	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 1943 : 	return (0);

	xor	eax, eax
	jmp	$L68374
$L68385:

; 1945 :     p = (uint32*)(img->BWmap + 256);

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx+56]
	add	eax, 1024				; 00000400H
	mov	DWORD PTR _p$[ebp], eax

; 1946 :     for (i = 0; i < 256; i++) {

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L68388
$L68389:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L68388:
	cmp	DWORD PTR _i$[ebp], 256			; 00000100H
	jge	$L68390

; 1947 : 	TIFFRGBValue c;
; 1948 : 	img->BWmap[i] = p;

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [eax+ecx*4], edx

; 1949 : 	switch (bitspersample) {

	mov	eax, DWORD PTR _bitspersample$[ebp]
	mov	DWORD PTR -28+[ebp], eax
	mov	ecx, DWORD PTR -28+[ebp]
	sub	ecx, 1
	mov	DWORD PTR -28+[ebp], ecx
	cmp	DWORD PTR -28+[ebp], 15			; 0000000fH
	ja	$L68393
	mov	eax, DWORD PTR -28+[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR $L68867[eax]
	jmp	DWORD PTR $L68868[edx*4]
$L68397:

; 1950 : #define	GREY(x)	c = Map[x]; *p++ = PACK(c,c,c);
; 1951 : 	case 1:
; 1952 : 	    GREY(i>>7);

	mov	ecx, DWORD PTR _i$[ebp]
	sar	ecx, 7
	mov	edx, DWORD PTR _Map$[ebp]
	mov	al, BYTE PTR [edx+ecx]
	mov	BYTE PTR _c$68391[ebp], al
	mov	ecx, DWORD PTR _c$68391[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _c$68391[ebp]
	and	edx, 255				; 000000ffH
	shl	edx, 8
	or	ecx, edx
	mov	eax, DWORD PTR _c$68391[ebp]
	and	eax, 255				; 000000ffH
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _p$[ebp]
	add	eax, 4
	mov	DWORD PTR _p$[ebp], eax

; 1953 : 	    GREY((i>>6)&1);

	mov	ecx, DWORD PTR _i$[ebp]
	sar	ecx, 6
	and	ecx, 1
	mov	edx, DWORD PTR _Map$[ebp]
	mov	al, BYTE PTR [edx+ecx]
	mov	BYTE PTR _c$68391[ebp], al
	mov	ecx, DWORD PTR _c$68391[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _c$68391[ebp]
	and	edx, 255				; 000000ffH
	shl	edx, 8
	or	ecx, edx
	mov	eax, DWORD PTR _c$68391[ebp]
	and	eax, 255				; 000000ffH
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _p$[ebp]
	add	eax, 4
	mov	DWORD PTR _p$[ebp], eax

; 1954 : 	    GREY((i>>5)&1);

	mov	ecx, DWORD PTR _i$[ebp]
	sar	ecx, 5
	and	ecx, 1
	mov	edx, DWORD PTR _Map$[ebp]
	mov	al, BYTE PTR [edx+ecx]
	mov	BYTE PTR _c$68391[ebp], al
	mov	ecx, DWORD PTR _c$68391[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _c$68391[ebp]
	and	edx, 255				; 000000ffH
	shl	edx, 8
	or	ecx, edx
	mov	eax, DWORD PTR _c$68391[ebp]
	and	eax, 255				; 000000ffH
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _p$[ebp]
	add	eax, 4
	mov	DWORD PTR _p$[ebp], eax

; 1955 : 	    GREY((i>>4)&1);

	mov	ecx, DWORD PTR _i$[ebp]
	sar	ecx, 4
	and	ecx, 1
	mov	edx, DWORD PTR _Map$[ebp]
	mov	al, BYTE PTR [edx+ecx]
	mov	BYTE PTR _c$68391[ebp], al
	mov	ecx, DWORD PTR _c$68391[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _c$68391[ebp]
	and	edx, 255				; 000000ffH
	shl	edx, 8
	or	ecx, edx
	mov	eax, DWORD PTR _c$68391[ebp]
	and	eax, 255				; 000000ffH
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _p$[ebp]
	add	eax, 4
	mov	DWORD PTR _p$[ebp], eax

; 1956 : 	    GREY((i>>3)&1);

	mov	ecx, DWORD PTR _i$[ebp]
	sar	ecx, 3
	and	ecx, 1
	mov	edx, DWORD PTR _Map$[ebp]
	mov	al, BYTE PTR [edx+ecx]
	mov	BYTE PTR _c$68391[ebp], al
	mov	ecx, DWORD PTR _c$68391[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _c$68391[ebp]
	and	edx, 255				; 000000ffH
	shl	edx, 8
	or	ecx, edx
	mov	eax, DWORD PTR _c$68391[ebp]
	and	eax, 255				; 000000ffH
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _p$[ebp]
	add	eax, 4
	mov	DWORD PTR _p$[ebp], eax

; 1957 : 	    GREY((i>>2)&1);

	mov	ecx, DWORD PTR _i$[ebp]
	sar	ecx, 2
	and	ecx, 1
	mov	edx, DWORD PTR _Map$[ebp]
	mov	al, BYTE PTR [edx+ecx]
	mov	BYTE PTR _c$68391[ebp], al
	mov	ecx, DWORD PTR _c$68391[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _c$68391[ebp]
	and	edx, 255				; 000000ffH
	shl	edx, 8
	or	ecx, edx
	mov	eax, DWORD PTR _c$68391[ebp]
	and	eax, 255				; 000000ffH
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _p$[ebp]
	add	eax, 4
	mov	DWORD PTR _p$[ebp], eax

; 1958 : 	    GREY((i>>1)&1);

	mov	ecx, DWORD PTR _i$[ebp]
	sar	ecx, 1
	and	ecx, 1
	mov	edx, DWORD PTR _Map$[ebp]
	mov	al, BYTE PTR [edx+ecx]
	mov	BYTE PTR _c$68391[ebp], al
	mov	ecx, DWORD PTR _c$68391[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _c$68391[ebp]
	and	edx, 255				; 000000ffH
	shl	edx, 8
	or	ecx, edx
	mov	eax, DWORD PTR _c$68391[ebp]
	and	eax, 255				; 000000ffH
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _p$[ebp]
	add	eax, 4
	mov	DWORD PTR _p$[ebp], eax

; 1959 : 	    GREY(i&1);

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 1
	mov	edx, DWORD PTR _Map$[ebp]
	mov	al, BYTE PTR [edx+ecx]
	mov	BYTE PTR _c$68391[ebp], al
	mov	ecx, DWORD PTR _c$68391[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _c$68391[ebp]
	and	edx, 255				; 000000ffH
	shl	edx, 8
	or	ecx, edx
	mov	eax, DWORD PTR _c$68391[ebp]
	and	eax, 255				; 000000ffH
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _p$[ebp]
	add	eax, 4
	mov	DWORD PTR _p$[ebp], eax

; 1960 : 	    break;

	jmp	$L68393
$L68430:

; 1961 : 	case 2:
; 1962 : 	    GREY(i>>6);

	mov	ecx, DWORD PTR _i$[ebp]
	sar	ecx, 6
	mov	edx, DWORD PTR _Map$[ebp]
	mov	al, BYTE PTR [edx+ecx]
	mov	BYTE PTR _c$68391[ebp], al
	mov	ecx, DWORD PTR _c$68391[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _c$68391[ebp]
	and	edx, 255				; 000000ffH
	shl	edx, 8
	or	ecx, edx
	mov	eax, DWORD PTR _c$68391[ebp]
	and	eax, 255				; 000000ffH
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _p$[ebp]
	add	eax, 4
	mov	DWORD PTR _p$[ebp], eax

; 1963 : 	    GREY((i>>4)&3);

	mov	ecx, DWORD PTR _i$[ebp]
	sar	ecx, 4
	and	ecx, 3
	mov	edx, DWORD PTR _Map$[ebp]
	mov	al, BYTE PTR [edx+ecx]
	mov	BYTE PTR _c$68391[ebp], al
	mov	ecx, DWORD PTR _c$68391[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _c$68391[ebp]
	and	edx, 255				; 000000ffH
	shl	edx, 8
	or	ecx, edx
	mov	eax, DWORD PTR _c$68391[ebp]
	and	eax, 255				; 000000ffH
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _p$[ebp]
	add	eax, 4
	mov	DWORD PTR _p$[ebp], eax

; 1964 : 	    GREY((i>>2)&3);

	mov	ecx, DWORD PTR _i$[ebp]
	sar	ecx, 2
	and	ecx, 3
	mov	edx, DWORD PTR _Map$[ebp]
	mov	al, BYTE PTR [edx+ecx]
	mov	BYTE PTR _c$68391[ebp], al
	mov	ecx, DWORD PTR _c$68391[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _c$68391[ebp]
	and	edx, 255				; 000000ffH
	shl	edx, 8
	or	ecx, edx
	mov	eax, DWORD PTR _c$68391[ebp]
	and	eax, 255				; 000000ffH
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _p$[ebp]
	add	eax, 4
	mov	DWORD PTR _p$[ebp], eax

; 1965 : 	    GREY(i&3);

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 3
	mov	edx, DWORD PTR _Map$[ebp]
	mov	al, BYTE PTR [edx+ecx]
	mov	BYTE PTR _c$68391[ebp], al
	mov	ecx, DWORD PTR _c$68391[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _c$68391[ebp]
	and	edx, 255				; 000000ffH
	shl	edx, 8
	or	ecx, edx
	mov	eax, DWORD PTR _c$68391[ebp]
	and	eax, 255				; 000000ffH
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _p$[ebp]
	add	eax, 4
	mov	DWORD PTR _p$[ebp], eax

; 1966 : 	    break;

	jmp	$L68393
$L68447:

; 1967 : 	case 4:
; 1968 : 	    GREY(i>>4);

	mov	ecx, DWORD PTR _i$[ebp]
	sar	ecx, 4
	mov	edx, DWORD PTR _Map$[ebp]
	mov	al, BYTE PTR [edx+ecx]
	mov	BYTE PTR _c$68391[ebp], al
	mov	ecx, DWORD PTR _c$68391[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _c$68391[ebp]
	and	edx, 255				; 000000ffH
	shl	edx, 8
	or	ecx, edx
	mov	eax, DWORD PTR _c$68391[ebp]
	and	eax, 255				; 000000ffH
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _p$[ebp]
	add	eax, 4
	mov	DWORD PTR _p$[ebp], eax

; 1969 : 	    GREY(i&0xf);

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 15					; 0000000fH
	mov	edx, DWORD PTR _Map$[ebp]
	mov	al, BYTE PTR [edx+ecx]
	mov	BYTE PTR _c$68391[ebp], al
	mov	ecx, DWORD PTR _c$68391[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _c$68391[ebp]
	and	edx, 255				; 000000ffH
	shl	edx, 8
	or	ecx, edx
	mov	eax, DWORD PTR _c$68391[ebp]
	and	eax, 255				; 000000ffH
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _p$[ebp]
	add	eax, 4
	mov	DWORD PTR _p$[ebp], eax

; 1970 : 	    break;

	jmp	SHORT $L68393
$L68456:

; 1971 : 	case 8:
; 1972 :         case 16:
; 1973 : 	    GREY(i);

	mov	ecx, DWORD PTR _Map$[ebp]
	add	ecx, DWORD PTR _i$[ebp]
	mov	dl, BYTE PTR [ecx]
	mov	BYTE PTR _c$68391[ebp], dl
	mov	eax, DWORD PTR _c$68391[ebp]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _c$68391[ebp]
	and	ecx, 255				; 000000ffH
	shl	ecx, 8
	or	eax, ecx
	mov	edx, DWORD PTR _c$68391[ebp]
	and	edx, 255				; 000000ffH
	shl	edx, 16					; 00000010H
	or	eax, edx
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _p$[ebp]
	add	edx, 4
	mov	DWORD PTR _p$[ebp], edx
$L68393:

; 1976 : #undef	GREY
; 1977 :     }

	jmp	$L68389
$L68390:

; 1978 :     return (1);

	mov	eax, 1
$L68374:

; 1979 : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68868:
	DD	$L68397
	DD	$L68430
	DD	$L68447
	DD	$L68456
	DD	$L68393
$L68867:
	DB	0
	DB	1
	DB	4
	DB	2
	DB	4
	DB	4
	DB	4
	DB	3
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	3
_makebwmap ENDP
_img$ = 8
_r$ = -8
_g$ = -12
_b$ = -4
_n$ = -16
_checkcmap PROC NEAR

; 2027 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 2028 :     uint16* r = img->redcmap;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+32]
	mov	DWORD PTR _r$[ebp], ecx

; 2029 :     uint16* g = img->greencmap;

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx+36]
	mov	DWORD PTR _g$[ebp], eax

; 2030 :     uint16* b = img->bluecmap;

	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	DWORD PTR _b$[ebp], edx

; 2031 :     long n = 1L<<img->bitspersample;

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+24]
	mov	edx, 1
	shl	edx, cl
	mov	DWORD PTR _n$[ebp], edx
$L68498:

; 2032 : 
; 2033 :     while (n-- > 0)

	mov	eax, DWORD PTR _n$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	test	eax, eax
	jle	SHORT $L68499

; 2034 : 	if (*r++ >= 256 || *g++ >= 256 || *b++ >= 256)

	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	mov	ecx, DWORD PTR _r$[ebp]
	add	ecx, 2
	mov	DWORD PTR _r$[ebp], ecx
	cmp	eax, 256				; 00000100H
	jge	SHORT $L68501
	mov	edx, DWORD PTR _g$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	mov	ecx, DWORD PTR _g$[ebp]
	add	ecx, 2
	mov	DWORD PTR _g$[ebp], ecx
	cmp	eax, 256				; 00000100H
	jge	SHORT $L68501
	mov	edx, DWORD PTR _b$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	mov	ecx, DWORD PTR _b$[ebp]
	add	ecx, 2
	mov	DWORD PTR _b$[ebp], ecx
	cmp	eax, 256				; 00000100H
	jl	SHORT $L68500
$L68501:

; 2035 : 	    return (16);

	mov	eax, 16					; 00000010H
	jmp	SHORT $L68492
$L68500:

; 2036 :     return (8);

	jmp	SHORT $L68498
$L68499:
	mov	eax, 8
$L68492:

; 2037 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_checkcmap ENDP
_img$ = 8
_r$ = -8
_g$ = -12
_b$ = -4
_i$ = -16
_cvtcmap PROC NEAR

; 2041 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 2042 :     uint16* r = img->redcmap;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+32]
	mov	DWORD PTR _r$[ebp], ecx

; 2043 :     uint16* g = img->greencmap;

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx+36]
	mov	DWORD PTR _g$[ebp], eax

; 2044 :     uint16* b = img->bluecmap;

	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	DWORD PTR _b$[ebp], edx

; 2045 :     long i;
; 2046 : 
; 2047 :     for (i = (1L<<img->bitspersample)-1; i >= 0; i--) {

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+24]
	mov	edx, 1
	shl	edx, cl
	sub	edx, 1
	mov	DWORD PTR _i$[ebp], edx
	jmp	SHORT $L68510
$L68511:
	mov	eax, DWORD PTR _i$[ebp]
	sub	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L68510:
	cmp	DWORD PTR _i$[ebp], 0
	jl	SHORT $L68512

; 2048 : #define	CVT(x)		((uint16)((x)>>8))
; 2049 : 	r[i] = CVT(r[i]);

	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+ecx*2]
	sar	eax, 8
	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _r$[ebp]
	mov	WORD PTR [edx+ecx*2], ax

; 2050 : 	g[i] = CVT(g[i]);

	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _g$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+eax*2]
	sar	edx, 8
	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _g$[ebp]
	mov	WORD PTR [ecx+eax*2], dx

; 2051 : 	b[i] = CVT(b[i]);

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _b$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+edx*2]
	sar	ecx, 8
	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _b$[ebp]
	mov	WORD PTR [eax+edx*2], cx

; 2052 : #undef	CVT
; 2053 :     }

	jmp	SHORT $L68511
$L68512:

; 2054 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_cvtcmap ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+1
$SG68533 DB	'No space for Palette mapping table', 00H
_DATA	ENDS
_TEXT	SEGMENT
_img$ = 8
_bitspersample$ = -16
_nsamples$ = -24
_r$ = -12
_g$ = -20
_b$ = -8
_p$ = -4
_i$ = -28
_c$68538 = -32
_makecmap PROC NEAR

; 2065 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 36					; 00000024H
	push	esi

; 2066 :     int bitspersample = img->bitspersample;

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+24]
	mov	DWORD PTR _bitspersample$[ebp], ecx

; 2067 :     int nsamples = 8 / bitspersample;

	mov	eax, 8
	cdq
	idiv	DWORD PTR _bitspersample$[ebp]
	mov	DWORD PTR _nsamples$[ebp], eax

; 2068 :     uint16* r = img->redcmap;

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx+32]
	mov	DWORD PTR _r$[ebp], eax

; 2069 :     uint16* g = img->greencmap;

	mov	ecx, DWORD PTR _img$[ebp]
	mov	edx, DWORD PTR [ecx+36]
	mov	DWORD PTR _g$[ebp], edx

; 2070 :     uint16* b = img->bluecmap;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+40]
	mov	DWORD PTR _b$[ebp], ecx

; 2071 :     uint32 *p;
; 2072 :     int i;
; 2073 : 
; 2074 :     img->PALmap = (uint32**) _TIFFmalloc(
; 2075 : 	256*sizeof (uint32 *)+(256*nsamples*sizeof(uint32)));

	mov	edx, DWORD PTR _nsamples$[ebp]
	shl	edx, 8
	lea	eax, DWORD PTR [edx*4+1024]
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	ecx, DWORD PTR _img$[ebp]
	mov	DWORD PTR [ecx+60], eax

; 2076 :     if (img->PALmap == NULL) {

	mov	edx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [edx+60], 0
	jne	SHORT $L68532

; 2077 : 	TIFFError(TIFFFileName(img->tif), "No space for Palette mapping table");

	push	OFFSET FLAT:$SG68533
	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 2078 : 	return (0);

	xor	eax, eax
	jmp	$L68520
$L68532:

; 2080 :     p = (uint32*)(img->PALmap + 256);

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx+60]
	add	eax, 1024				; 00000400H
	mov	DWORD PTR _p$[ebp], eax

; 2081 :     for (i = 0; i < 256; i++) {

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L68535
$L68536:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L68535:
	cmp	DWORD PTR _i$[ebp], 256			; 00000100H
	jge	$L68537

; 2082 : 	TIFFRGBValue c;
; 2083 : 	img->PALmap[i] = p;

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR [edx+60]
	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [eax+ecx*4], edx

; 2084 : #define	CMAP(x)	c = x; *p++ = PACK(r[c]&0xff, g[c]&0xff, b[c]&0xff);
; 2085 : 	switch (bitspersample) {

	mov	eax, DWORD PTR _bitspersample$[ebp]
	mov	DWORD PTR -36+[ebp], eax
	mov	ecx, DWORD PTR -36+[ebp]
	sub	ecx, 1
	mov	DWORD PTR -36+[ebp], ecx
	cmp	DWORD PTR -36+[ebp], 7
	ja	$L68541
	mov	edx, DWORD PTR -36+[ebp]
	jmp	DWORD PTR $L68872[edx*4]
$L68544:

; 2086 : 	case 1:
; 2087 : 	    CMAP(i>>7);

	mov	eax, DWORD PTR _i$[ebp]
	sar	eax, 7
	mov	BYTE PTR _c$68538[ebp], al
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+ecx*2]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _g$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 8
	or	eax, esi
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _b$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 16					; 00000010H
	or	eax, esi
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _p$[ebp]
	add	edx, 4
	mov	DWORD PTR _p$[ebp], edx

; 2088 : 	    CMAP((i>>6)&1);

	mov	eax, DWORD PTR _i$[ebp]
	sar	eax, 6
	and	eax, 1
	mov	BYTE PTR _c$68538[ebp], al
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+ecx*2]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _g$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 8
	or	eax, esi
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _b$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 16					; 00000010H
	or	eax, esi
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _p$[ebp]
	add	edx, 4
	mov	DWORD PTR _p$[ebp], edx

; 2089 : 	    CMAP((i>>5)&1);

	mov	eax, DWORD PTR _i$[ebp]
	sar	eax, 5
	and	eax, 1
	mov	BYTE PTR _c$68538[ebp], al
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+ecx*2]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _g$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 8
	or	eax, esi
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _b$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 16					; 00000010H
	or	eax, esi
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _p$[ebp]
	add	edx, 4
	mov	DWORD PTR _p$[ebp], edx

; 2090 : 	    CMAP((i>>4)&1);

	mov	eax, DWORD PTR _i$[ebp]
	sar	eax, 4
	and	eax, 1
	mov	BYTE PTR _c$68538[ebp], al
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+ecx*2]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _g$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 8
	or	eax, esi
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _b$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 16					; 00000010H
	or	eax, esi
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _p$[ebp]
	add	edx, 4
	mov	DWORD PTR _p$[ebp], edx

; 2091 : 	    CMAP((i>>3)&1);

	mov	eax, DWORD PTR _i$[ebp]
	sar	eax, 3
	and	eax, 1
	mov	BYTE PTR _c$68538[ebp], al
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+ecx*2]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _g$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 8
	or	eax, esi
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _b$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 16					; 00000010H
	or	eax, esi
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _p$[ebp]
	add	edx, 4
	mov	DWORD PTR _p$[ebp], edx

; 2092 : 	    CMAP((i>>2)&1);

	mov	eax, DWORD PTR _i$[ebp]
	sar	eax, 2
	and	eax, 1
	mov	BYTE PTR _c$68538[ebp], al
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+ecx*2]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _g$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 8
	or	eax, esi
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _b$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 16					; 00000010H
	or	eax, esi
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _p$[ebp]
	add	edx, 4
	mov	DWORD PTR _p$[ebp], edx

; 2093 : 	    CMAP((i>>1)&1);

	mov	eax, DWORD PTR _i$[ebp]
	sar	eax, 1
	and	eax, 1
	mov	BYTE PTR _c$68538[ebp], al
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+ecx*2]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _g$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 8
	or	eax, esi
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _b$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 16					; 00000010H
	or	eax, esi
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _p$[ebp]
	add	edx, 4
	mov	DWORD PTR _p$[ebp], edx

; 2094 : 	    CMAP(i&1);

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 1
	mov	BYTE PTR _c$68538[ebp], al
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+ecx*2]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _g$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 8
	or	eax, esi
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _b$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 16					; 00000010H
	or	eax, esi
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _p$[ebp]
	add	edx, 4
	mov	DWORD PTR _p$[ebp], edx

; 2095 : 	    break;

	jmp	$L68541
$L68577:

; 2096 : 	case 2:
; 2097 : 	    CMAP(i>>6);

	mov	eax, DWORD PTR _i$[ebp]
	sar	eax, 6
	mov	BYTE PTR _c$68538[ebp], al
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+ecx*2]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _g$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 8
	or	eax, esi
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _b$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 16					; 00000010H
	or	eax, esi
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _p$[ebp]
	add	edx, 4
	mov	DWORD PTR _p$[ebp], edx

; 2098 : 	    CMAP((i>>4)&3);

	mov	eax, DWORD PTR _i$[ebp]
	sar	eax, 4
	and	eax, 3
	mov	BYTE PTR _c$68538[ebp], al
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+ecx*2]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _g$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 8
	or	eax, esi
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _b$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 16					; 00000010H
	or	eax, esi
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _p$[ebp]
	add	edx, 4
	mov	DWORD PTR _p$[ebp], edx

; 2099 : 	    CMAP((i>>2)&3);

	mov	eax, DWORD PTR _i$[ebp]
	sar	eax, 2
	and	eax, 3
	mov	BYTE PTR _c$68538[ebp], al
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+ecx*2]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _g$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 8
	or	eax, esi
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _b$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 16					; 00000010H
	or	eax, esi
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _p$[ebp]
	add	edx, 4
	mov	DWORD PTR _p$[ebp], edx

; 2100 : 	    CMAP(i&3);

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 3
	mov	BYTE PTR _c$68538[ebp], al
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+ecx*2]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _g$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 8
	or	eax, esi
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _b$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 16					; 00000010H
	or	eax, esi
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _p$[ebp]
	add	edx, 4
	mov	DWORD PTR _p$[ebp], edx

; 2101 : 	    break;

	jmp	$L68541
$L68594:

; 2102 : 	case 4:
; 2103 : 	    CMAP(i>>4);

	mov	eax, DWORD PTR _i$[ebp]
	sar	eax, 4
	mov	BYTE PTR _c$68538[ebp], al
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+ecx*2]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _g$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 8
	or	eax, esi
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _b$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 16					; 00000010H
	or	eax, esi
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _p$[ebp]
	add	edx, 4
	mov	DWORD PTR _p$[ebp], edx

; 2104 : 	    CMAP(i&0xf);

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 15					; 0000000fH
	mov	BYTE PTR _c$68538[ebp], al
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+ecx*2]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _g$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 8
	or	eax, esi
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _b$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 16					; 00000010H
	or	eax, esi
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _p$[ebp]
	add	edx, 4
	mov	DWORD PTR _p$[ebp], edx

; 2105 : 	    break;

	jmp	SHORT $L68541
$L68603:

; 2106 : 	case 8:
; 2107 : 	    CMAP(i);

	mov	al, BYTE PTR _i$[ebp]
	mov	BYTE PTR _c$68538[ebp], al
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+ecx*2]
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _g$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 8
	or	eax, esi
	mov	ecx, DWORD PTR _c$68538[ebp]
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _b$[ebp]
	xor	esi, esi
	mov	si, WORD PTR [edx+ecx*2]
	and	esi, 255				; 000000ffH
	shl	esi, 16					; 00000010H
	or	eax, esi
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _p$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _p$[ebp]
	add	edx, 4
	mov	DWORD PTR _p$[ebp], edx
$L68541:

; 2110 : #undef CMAP
; 2111 :     }

	jmp	$L68536
$L68537:

; 2112 :     return (1);

	mov	eax, 1
$L68520:

; 2113 : }

	pop	esi
	mov	esp, ebp
	pop	ebp
	ret	0
$L68872:
	DD	$L68544
	DD	$L68577
	DD	$L68541
	DD	$L68594
	DD	$L68541
	DD	$L68541
	DD	$L68541
	DD	$L68603
_makecmap ENDP
_img$ = 8
_put$ = -4
_pickTileSeparateCase PROC NEAR

; 2231 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 2232 :     tileSeparateRoutine put = 0;

	mov	DWORD PTR _put$[ebp], 0

; 2233 : 
; 2234 :     if (buildMap(img)) {

	mov	eax, DWORD PTR _img$[ebp]
	push	eax
	call	_buildMap
	add	esp, 4
	test	eax, eax
	je	$L68682

; 2235 : 	switch (img->photometric) {

	mov	ecx, DWORD PTR _img$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+30]
	mov	DWORD PTR -8+[ebp], edx
	cmp	DWORD PTR -8+[ebp], 2
	je	SHORT $L68685
	jmp	$L68682
$L68685:

; 2236 : 	case PHOTOMETRIC_RGB:
; 2237 : 	    switch (img->bitspersample) {

	mov	eax, DWORD PTR _img$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+24]
	mov	DWORD PTR -12+[ebp], ecx
	cmp	DWORD PTR -12+[ebp], 8
	je	SHORT $L68690
	cmp	DWORD PTR -12+[ebp], 16			; 00000010H
	je	SHORT $L68697
	jmp	SHORT $L68687
$L68690:

; 2238 : 	    case 8:
; 2239 : 		if (!img->Map) {

	mov	edx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [edx+52], 0
	jne	SHORT $L68691

; 2240 : 		    if (img->alpha == EXTRASAMPLE_ASSOCALPHA)

	mov	eax, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [eax+12], 1
	jne	SHORT $L68692

; 2241 : 			put = putRGBAAseparate8bittile;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_putRGBAAseparate8bittile

; 2242 : 		    else if (img->alpha == EXTRASAMPLE_UNASSALPHA)

	jmp	SHORT $L68695
$L68692:
	mov	ecx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [ecx+12], 2
	jne	SHORT $L68694

; 2243 : 			put = putRGBUAseparate8bittile;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_putRGBUAseparate8bittile

; 2244 : 		    else

	jmp	SHORT $L68695
$L68694:

; 2245 : 			put = putRGBseparate8bittile;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_putRGBseparate8bittile
$L68695:

; 2246 : 		} else

	jmp	SHORT $L68696
$L68691:

; 2247 : 		    put = putRGBseparate8bitMaptile;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_putRGBseparate8bitMaptile
$L68696:

; 2248 : 		break;

	jmp	SHORT $L68687
$L68697:

; 2249 : 	    case 16:
; 2250 : 		put = putRGBseparate16bittile;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_putRGBseparate16bittile

; 2251 : 		if (!img->Map) {

	mov	edx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [edx+52], 0
	jne	SHORT $L68701

; 2252 : 		    if (img->alpha == EXTRASAMPLE_ASSOCALPHA)

	mov	eax, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [eax+12], 1
	jne	SHORT $L68699

; 2253 : 			put = putRGBAAseparate16bittile;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_putRGBAAseparate16bittile

; 2254 : 		    else if (img->alpha == EXTRASAMPLE_UNASSALPHA)

	jmp	SHORT $L68701
$L68699:
	mov	ecx, DWORD PTR _img$[ebp]
	cmp	DWORD PTR [ecx+12], 2
	jne	SHORT $L68701

; 2255 : 			put = putRGBUAseparate16bittile;

	mov	DWORD PTR _put$[ebp], OFFSET FLAT:_putRGBUAseparate16bittile
$L68701:
$L68687:
$L68682:

; 2262 :     return ((img->put.separate = put) != 0);

	mov	edx, DWORD PTR _img$[ebp]
	mov	eax, DWORD PTR _put$[ebp]
	mov	DWORD PTR [edx+48], eax
	xor	eax, eax
	cmp	DWORD PTR _put$[ebp], 0
	setne	al

; 2263 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_pickTileSeparateCase ENDP
_cp$ = 12
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_r$ = 40
_g$ = 44
_b$ = 48
__x$67109 = -4
_putRGBseparate8bittile PROC NEAR

; 1223 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8
$L67107:

; 1224 :     (void) img; (void) x; (void) y; (void) a;
; 1225 :     while (h-- > 0) {

	mov	eax, DWORD PTR _h$[ebp]
	mov	ecx, DWORD PTR _h$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _h$[ebp], ecx
	test	eax, eax
	jbe	$L67108

; 1226 : 	UNROLL8(w, NOP, *cp++ = PACK(*r++, *g++, *b++));

	mov	edx, DWORD PTR _w$[ebp]
	mov	DWORD PTR __x$67109[ebp], edx
	jmp	SHORT $L67110
$L67111:
	mov	eax, DWORD PTR __x$67109[ebp]
	sub	eax, 8
	mov	DWORD PTR __x$67109[ebp], eax
$L67110:
	cmp	DWORD PTR __x$67109[ebp], 8
	jb	$L67112
	mov	ecx, DWORD PTR _r$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _g$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _b$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _b$[ebp]
	add	edx, 1
	mov	DWORD PTR _b$[ebp], edx
	mov	eax, DWORD PTR _g$[ebp]
	add	eax, 1
	mov	DWORD PTR _g$[ebp], eax
	mov	ecx, DWORD PTR _r$[ebp]
	add	ecx, 1
	mov	DWORD PTR _r$[ebp], ecx
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _g$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _b$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 16					; 00000010H
	or	eax, edx
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _b$[ebp]
	add	eax, 1
	mov	DWORD PTR _b$[ebp], eax
	mov	ecx, DWORD PTR _g$[ebp]
	add	ecx, 1
	mov	DWORD PTR _g$[ebp], ecx
	mov	edx, DWORD PTR _r$[ebp]
	add	edx, 1
	mov	DWORD PTR _r$[ebp], edx
	mov	eax, DWORD PTR _r$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _g$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _b$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _b$[ebp]
	add	ecx, 1
	mov	DWORD PTR _b$[ebp], ecx
	mov	edx, DWORD PTR _g$[ebp]
	add	edx, 1
	mov	DWORD PTR _g$[ebp], edx
	mov	eax, DWORD PTR _r$[ebp]
	add	eax, 1
	mov	DWORD PTR _r$[ebp], eax
	mov	ecx, DWORD PTR _r$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _g$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _b$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _b$[ebp]
	add	edx, 1
	mov	DWORD PTR _b$[ebp], edx
	mov	eax, DWORD PTR _g$[ebp]
	add	eax, 1
	mov	DWORD PTR _g$[ebp], eax
	mov	ecx, DWORD PTR _r$[ebp]
	add	ecx, 1
	mov	DWORD PTR _r$[ebp], ecx
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _g$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _b$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 16					; 00000010H
	or	eax, edx
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _b$[ebp]
	add	eax, 1
	mov	DWORD PTR _b$[ebp], eax
	mov	ecx, DWORD PTR _g$[ebp]
	add	ecx, 1
	mov	DWORD PTR _g$[ebp], ecx
	mov	edx, DWORD PTR _r$[ebp]
	add	edx, 1
	mov	DWORD PTR _r$[ebp], edx
	mov	eax, DWORD PTR _r$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _g$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _b$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _b$[ebp]
	add	ecx, 1
	mov	DWORD PTR _b$[ebp], ecx
	mov	edx, DWORD PTR _g$[ebp]
	add	edx, 1
	mov	DWORD PTR _g$[ebp], edx
	mov	eax, DWORD PTR _r$[ebp]
	add	eax, 1
	mov	DWORD PTR _r$[ebp], eax
	mov	ecx, DWORD PTR _r$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _g$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _b$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _b$[ebp]
	add	edx, 1
	mov	DWORD PTR _b$[ebp], edx
	mov	eax, DWORD PTR _g$[ebp]
	add	eax, 1
	mov	DWORD PTR _g$[ebp], eax
	mov	ecx, DWORD PTR _r$[ebp]
	add	ecx, 1
	mov	DWORD PTR _r$[ebp], ecx
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _g$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _b$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 16					; 00000010H
	or	eax, edx
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _b$[ebp]
	add	eax, 1
	mov	DWORD PTR _b$[ebp], eax
	mov	ecx, DWORD PTR _g$[ebp]
	add	ecx, 1
	mov	DWORD PTR _g$[ebp], ecx
	mov	edx, DWORD PTR _r$[ebp]
	add	edx, 1
	mov	DWORD PTR _r$[ebp], edx
	jmp	$L67111
$L67112:
	cmp	DWORD PTR __x$67109[ebp], 0
	jbe	$L67147
	mov	eax, DWORD PTR __x$67109[ebp]
	mov	DWORD PTR -8+[ebp], eax
	mov	ecx, DWORD PTR -8+[ebp]
	sub	ecx, 1
	mov	DWORD PTR -8+[ebp], ecx
	cmp	DWORD PTR -8+[ebp], 6
	ja	$L67147
	mov	edx, DWORD PTR -8+[ebp]
	jmp	DWORD PTR $L68875[edx*4]
$L67150:
	mov	eax, DWORD PTR _r$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _g$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _b$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _b$[ebp]
	add	ecx, 1
	mov	DWORD PTR _b$[ebp], ecx
	mov	edx, DWORD PTR _g$[ebp]
	add	edx, 1
	mov	DWORD PTR _g$[ebp], edx
	mov	eax, DWORD PTR _r$[ebp]
	add	eax, 1
	mov	DWORD PTR _r$[ebp], eax
$L67155:
	mov	ecx, DWORD PTR _r$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _g$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _b$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _b$[ebp]
	add	edx, 1
	mov	DWORD PTR _b$[ebp], edx
	mov	eax, DWORD PTR _g$[ebp]
	add	eax, 1
	mov	DWORD PTR _g$[ebp], eax
	mov	ecx, DWORD PTR _r$[ebp]
	add	ecx, 1
	mov	DWORD PTR _r$[ebp], ecx
$L67160:
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _g$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _b$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 16					; 00000010H
	or	eax, edx
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _b$[ebp]
	add	eax, 1
	mov	DWORD PTR _b$[ebp], eax
	mov	ecx, DWORD PTR _g$[ebp]
	add	ecx, 1
	mov	DWORD PTR _g$[ebp], ecx
	mov	edx, DWORD PTR _r$[ebp]
	add	edx, 1
	mov	DWORD PTR _r$[ebp], edx
$L67165:
	mov	eax, DWORD PTR _r$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _g$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _b$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _b$[ebp]
	add	ecx, 1
	mov	DWORD PTR _b$[ebp], ecx
	mov	edx, DWORD PTR _g$[ebp]
	add	edx, 1
	mov	DWORD PTR _g$[ebp], edx
	mov	eax, DWORD PTR _r$[ebp]
	add	eax, 1
	mov	DWORD PTR _r$[ebp], eax
$L67170:
	mov	ecx, DWORD PTR _r$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _g$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _b$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _b$[ebp]
	add	edx, 1
	mov	DWORD PTR _b$[ebp], edx
	mov	eax, DWORD PTR _g$[ebp]
	add	eax, 1
	mov	DWORD PTR _g$[ebp], eax
	mov	ecx, DWORD PTR _r$[ebp]
	add	ecx, 1
	mov	DWORD PTR _r$[ebp], ecx
$L67175:
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _g$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _b$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 16					; 00000010H
	or	eax, edx
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _b$[ebp]
	add	eax, 1
	mov	DWORD PTR _b$[ebp], eax
	mov	ecx, DWORD PTR _g$[ebp]
	add	ecx, 1
	mov	DWORD PTR _g$[ebp], ecx
	mov	edx, DWORD PTR _r$[ebp]
	add	edx, 1
	mov	DWORD PTR _r$[ebp], edx
$L67180:
	mov	eax, DWORD PTR _r$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _g$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _b$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	or	ecx, -16777216				; ff000000H
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _b$[ebp]
	add	ecx, 1
	mov	DWORD PTR _b$[ebp], ecx
	mov	edx, DWORD PTR _g$[ebp]
	add	edx, 1
	mov	DWORD PTR _g$[ebp], edx
	mov	eax, DWORD PTR _r$[ebp]
	add	eax, 1
	mov	DWORD PTR _r$[ebp], eax
$L67147:

; 1227 : 	SKEW(r, g, b, fromskew);

	mov	ecx, DWORD PTR _r$[ebp]
	add	ecx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _r$[ebp], ecx
	mov	edx, DWORD PTR _g$[ebp]
	add	edx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _g$[ebp], edx
	mov	eax, DWORD PTR _b$[ebp]
	add	eax, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _b$[ebp], eax

; 1228 : 	cp += toskew;

	mov	ecx, DWORD PTR _toskew$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp$[ebp], eax

; 1229 :     }

	jmp	$L67107
$L67108:

; 1230 : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68875:
	DD	$L67180
	DD	$L67175
	DD	$L67170
	DD	$L67165
	DD	$L67160
	DD	$L67155
	DD	$L67150
_putRGBseparate8bittile ENDP
_img$ = 8
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_r$ = 40
_g$ = 44
_b$ = 48
_Map$ = -4
_putRGBseparate8bitMaptile PROC NEAR

; 1236 : {

	push	ebp
	mov	ebp, esp
	push	ecx
	push	ebx

; 1237 :     TIFFRGBValue* Map = img->Map;

	mov	eax, DWORD PTR _img$[ebp]
	mov	ecx, DWORD PTR [eax+52]
	mov	DWORD PTR _Map$[ebp], ecx
$L67215:

; 1238 : 
; 1239 :     (void) y; (void) a;
; 1240 :     while (h-- > 0) {

	mov	edx, DWORD PTR _h$[ebp]
	mov	eax, DWORD PTR _h$[ebp]
	sub	eax, 1
	mov	DWORD PTR _h$[ebp], eax
	test	edx, edx
	jbe	$L67216

; 1241 : 	for (x = w; x > 0; x--)

	mov	ecx, DWORD PTR _w$[ebp]
	mov	DWORD PTR _x$[ebp], ecx
	jmp	SHORT $L67217
$L67218:
	mov	edx, DWORD PTR _x$[ebp]
	sub	edx, 1
	mov	DWORD PTR _x$[ebp], edx
$L67217:
	cmp	DWORD PTR _x$[ebp], 0
	jbe	SHORT $L67219

; 1242 : 	    *cp++ = PACK(Map[*r++], Map[*g++], Map[*b++]);

	mov	eax, DWORD PTR _r$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _Map$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _g$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, DWORD PTR _Map$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [ecx+edx]
	shl	ebx, 8
	or	eax, ebx
	mov	edx, DWORD PTR _b$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [edx]
	mov	edx, DWORD PTR _Map$[ebp]
	xor	ebx, ebx
	mov	bl, BYTE PTR [edx+ecx]
	shl	ebx, 16					; 00000010H
	or	eax, ebx
	or	eax, -16777216				; ff000000H
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _b$[ebp]
	add	eax, 1
	mov	DWORD PTR _b$[ebp], eax
	mov	ecx, DWORD PTR _g$[ebp]
	add	ecx, 1
	mov	DWORD PTR _g$[ebp], ecx
	mov	edx, DWORD PTR _r$[ebp]
	add	edx, 1
	mov	DWORD PTR _r$[ebp], edx
	jmp	SHORT $L67218
$L67219:

; 1243 : 	SKEW(r, g, b, fromskew);

	mov	eax, DWORD PTR _r$[ebp]
	add	eax, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _r$[ebp], eax
	mov	ecx, DWORD PTR _g$[ebp]
	add	ecx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _g$[ebp], ecx
	mov	edx, DWORD PTR _b$[ebp]
	add	edx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _b$[ebp], edx

; 1244 : 	cp += toskew;

	mov	eax, DWORD PTR _toskew$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	lea	edx, DWORD PTR [ecx+eax*4]
	mov	DWORD PTR _cp$[ebp], edx

; 1245 :     }

	jmp	$L67215
$L67216:

; 1246 : }

	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_putRGBseparate8bitMaptile ENDP
_cp$ = 12
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_r$ = 40
_g$ = 44
_b$ = 48
_a$ = 52
__x$67256 = -4
_putRGBAAseparate8bittile PROC NEAR

; 1252 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8
$L67254:

; 1253 :     (void) img; (void) x; (void) y;
; 1254 :     while (h-- > 0) {

	mov	eax, DWORD PTR _h$[ebp]
	mov	ecx, DWORD PTR _h$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _h$[ebp], ecx
	test	eax, eax
	jbe	$L67255

; 1255 : 	UNROLL8(w, NOP, *cp++ = PACK4(*r++, *g++, *b++, *a++));

	mov	edx, DWORD PTR _w$[ebp]
	mov	DWORD PTR __x$67256[ebp], edx
	jmp	SHORT $L67257
$L67258:
	mov	eax, DWORD PTR __x$67256[ebp]
	sub	eax, 8
	mov	DWORD PTR __x$67256[ebp], eax
$L67257:
	cmp	DWORD PTR __x$67256[ebp], 8
	jb	$L67259
	mov	ecx, DWORD PTR _r$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _g$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _b$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	mov	eax, DWORD PTR _a$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 24					; 00000018H
	or	edx, ecx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _a$[ebp]
	add	edx, 1
	mov	DWORD PTR _a$[ebp], edx
	mov	eax, DWORD PTR _b$[ebp]
	add	eax, 1
	mov	DWORD PTR _b$[ebp], eax
	mov	ecx, DWORD PTR _g$[ebp]
	add	ecx, 1
	mov	DWORD PTR _g$[ebp], ecx
	mov	edx, DWORD PTR _r$[ebp]
	add	edx, 1
	mov	DWORD PTR _r$[ebp], edx
	mov	eax, DWORD PTR _r$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _g$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _b$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	mov	edx, DWORD PTR _a$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 24					; 00000018H
	or	ecx, eax
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _a$[ebp]
	add	ecx, 1
	mov	DWORD PTR _a$[ebp], ecx
	mov	edx, DWORD PTR _b$[ebp]
	add	edx, 1
	mov	DWORD PTR _b$[ebp], edx
	mov	eax, DWORD PTR _g$[ebp]
	add	eax, 1
	mov	DWORD PTR _g$[ebp], eax
	mov	ecx, DWORD PTR _r$[ebp]
	add	ecx, 1
	mov	DWORD PTR _r$[ebp], ecx
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _g$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _b$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 16					; 00000010H
	or	eax, edx
	mov	ecx, DWORD PTR _a$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 24					; 00000018H
	or	eax, edx
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _a$[ebp]
	add	eax, 1
	mov	DWORD PTR _a$[ebp], eax
	mov	ecx, DWORD PTR _b$[ebp]
	add	ecx, 1
	mov	DWORD PTR _b$[ebp], ecx
	mov	edx, DWORD PTR _g$[ebp]
	add	edx, 1
	mov	DWORD PTR _g$[ebp], edx
	mov	eax, DWORD PTR _r$[ebp]
	add	eax, 1
	mov	DWORD PTR _r$[ebp], eax
	mov	ecx, DWORD PTR _r$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _g$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _b$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	mov	eax, DWORD PTR _a$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 24					; 00000018H
	or	edx, ecx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _a$[ebp]
	add	edx, 1
	mov	DWORD PTR _a$[ebp], edx
	mov	eax, DWORD PTR _b$[ebp]
	add	eax, 1
	mov	DWORD PTR _b$[ebp], eax
	mov	ecx, DWORD PTR _g$[ebp]
	add	ecx, 1
	mov	DWORD PTR _g$[ebp], ecx
	mov	edx, DWORD PTR _r$[ebp]
	add	edx, 1
	mov	DWORD PTR _r$[ebp], edx
	mov	eax, DWORD PTR _r$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _g$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _b$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	mov	edx, DWORD PTR _a$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 24					; 00000018H
	or	ecx, eax
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _a$[ebp]
	add	ecx, 1
	mov	DWORD PTR _a$[ebp], ecx
	mov	edx, DWORD PTR _b$[ebp]
	add	edx, 1
	mov	DWORD PTR _b$[ebp], edx
	mov	eax, DWORD PTR _g$[ebp]
	add	eax, 1
	mov	DWORD PTR _g$[ebp], eax
	mov	ecx, DWORD PTR _r$[ebp]
	add	ecx, 1
	mov	DWORD PTR _r$[ebp], ecx
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _g$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _b$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 16					; 00000010H
	or	eax, edx
	mov	ecx, DWORD PTR _a$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 24					; 00000018H
	or	eax, edx
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _a$[ebp]
	add	eax, 1
	mov	DWORD PTR _a$[ebp], eax
	mov	ecx, DWORD PTR _b$[ebp]
	add	ecx, 1
	mov	DWORD PTR _b$[ebp], ecx
	mov	edx, DWORD PTR _g$[ebp]
	add	edx, 1
	mov	DWORD PTR _g$[ebp], edx
	mov	eax, DWORD PTR _r$[ebp]
	add	eax, 1
	mov	DWORD PTR _r$[ebp], eax
	mov	ecx, DWORD PTR _r$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _g$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _b$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	mov	eax, DWORD PTR _a$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 24					; 00000018H
	or	edx, ecx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _a$[ebp]
	add	edx, 1
	mov	DWORD PTR _a$[ebp], edx
	mov	eax, DWORD PTR _b$[ebp]
	add	eax, 1
	mov	DWORD PTR _b$[ebp], eax
	mov	ecx, DWORD PTR _g$[ebp]
	add	ecx, 1
	mov	DWORD PTR _g$[ebp], ecx
	mov	edx, DWORD PTR _r$[ebp]
	add	edx, 1
	mov	DWORD PTR _r$[ebp], edx
	mov	eax, DWORD PTR _r$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _g$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _b$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	mov	edx, DWORD PTR _a$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 24					; 00000018H
	or	ecx, eax
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _a$[ebp]
	add	ecx, 1
	mov	DWORD PTR _a$[ebp], ecx
	mov	edx, DWORD PTR _b$[ebp]
	add	edx, 1
	mov	DWORD PTR _b$[ebp], edx
	mov	eax, DWORD PTR _g$[ebp]
	add	eax, 1
	mov	DWORD PTR _g$[ebp], eax
	mov	ecx, DWORD PTR _r$[ebp]
	add	ecx, 1
	mov	DWORD PTR _r$[ebp], ecx
	jmp	$L67258
$L67259:
	cmp	DWORD PTR __x$67256[ebp], 0
	jbe	$L67294
	mov	edx, DWORD PTR __x$67256[ebp]
	mov	DWORD PTR -8+[ebp], edx
	mov	eax, DWORD PTR -8+[ebp]
	sub	eax, 1
	mov	DWORD PTR -8+[ebp], eax
	cmp	DWORD PTR -8+[ebp], 6
	ja	$L67294
	mov	ecx, DWORD PTR -8+[ebp]
	jmp	DWORD PTR $L68878[ecx*4]
$L67297:
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _g$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _b$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 16					; 00000010H
	or	eax, edx
	mov	ecx, DWORD PTR _a$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 24					; 00000018H
	or	eax, edx
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _a$[ebp]
	add	eax, 1
	mov	DWORD PTR _a$[ebp], eax
	mov	ecx, DWORD PTR _b$[ebp]
	add	ecx, 1
	mov	DWORD PTR _b$[ebp], ecx
	mov	edx, DWORD PTR _g$[ebp]
	add	edx, 1
	mov	DWORD PTR _g$[ebp], edx
	mov	eax, DWORD PTR _r$[ebp]
	add	eax, 1
	mov	DWORD PTR _r$[ebp], eax
$L67302:
	mov	ecx, DWORD PTR _r$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _g$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _b$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	mov	eax, DWORD PTR _a$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 24					; 00000018H
	or	edx, ecx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _a$[ebp]
	add	edx, 1
	mov	DWORD PTR _a$[ebp], edx
	mov	eax, DWORD PTR _b$[ebp]
	add	eax, 1
	mov	DWORD PTR _b$[ebp], eax
	mov	ecx, DWORD PTR _g$[ebp]
	add	ecx, 1
	mov	DWORD PTR _g$[ebp], ecx
	mov	edx, DWORD PTR _r$[ebp]
	add	edx, 1
	mov	DWORD PTR _r$[ebp], edx
$L67307:
	mov	eax, DWORD PTR _r$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _g$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _b$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	mov	edx, DWORD PTR _a$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 24					; 00000018H
	or	ecx, eax
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _a$[ebp]
	add	ecx, 1
	mov	DWORD PTR _a$[ebp], ecx
	mov	edx, DWORD PTR _b$[ebp]
	add	edx, 1
	mov	DWORD PTR _b$[ebp], edx
	mov	eax, DWORD PTR _g$[ebp]
	add	eax, 1
	mov	DWORD PTR _g$[ebp], eax
	mov	ecx, DWORD PTR _r$[ebp]
	add	ecx, 1
	mov	DWORD PTR _r$[ebp], ecx
$L67312:
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _g$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _b$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 16					; 00000010H
	or	eax, edx
	mov	ecx, DWORD PTR _a$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 24					; 00000018H
	or	eax, edx
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _a$[ebp]
	add	eax, 1
	mov	DWORD PTR _a$[ebp], eax
	mov	ecx, DWORD PTR _b$[ebp]
	add	ecx, 1
	mov	DWORD PTR _b$[ebp], ecx
	mov	edx, DWORD PTR _g$[ebp]
	add	edx, 1
	mov	DWORD PTR _g$[ebp], edx
	mov	eax, DWORD PTR _r$[ebp]
	add	eax, 1
	mov	DWORD PTR _r$[ebp], eax
$L67317:
	mov	ecx, DWORD PTR _r$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _g$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _b$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	mov	eax, DWORD PTR _a$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 24					; 00000018H
	or	edx, ecx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _a$[ebp]
	add	edx, 1
	mov	DWORD PTR _a$[ebp], edx
	mov	eax, DWORD PTR _b$[ebp]
	add	eax, 1
	mov	DWORD PTR _b$[ebp], eax
	mov	ecx, DWORD PTR _g$[ebp]
	add	ecx, 1
	mov	DWORD PTR _g$[ebp], ecx
	mov	edx, DWORD PTR _r$[ebp]
	add	edx, 1
	mov	DWORD PTR _r$[ebp], edx
$L67322:
	mov	eax, DWORD PTR _r$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _g$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _b$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 16					; 00000010H
	or	ecx, eax
	mov	edx, DWORD PTR _a$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 24					; 00000018H
	or	ecx, eax
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _a$[ebp]
	add	ecx, 1
	mov	DWORD PTR _a$[ebp], ecx
	mov	edx, DWORD PTR _b$[ebp]
	add	edx, 1
	mov	DWORD PTR _b$[ebp], edx
	mov	eax, DWORD PTR _g$[ebp]
	add	eax, 1
	mov	DWORD PTR _g$[ebp], eax
	mov	ecx, DWORD PTR _r$[ebp]
	add	ecx, 1
	mov	DWORD PTR _r$[ebp], ecx
$L67327:
	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _g$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _b$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 16					; 00000010H
	or	eax, edx
	mov	ecx, DWORD PTR _a$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	shl	edx, 24					; 00000018H
	or	eax, edx
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _a$[ebp]
	add	eax, 1
	mov	DWORD PTR _a$[ebp], eax
	mov	ecx, DWORD PTR _b$[ebp]
	add	ecx, 1
	mov	DWORD PTR _b$[ebp], ecx
	mov	edx, DWORD PTR _g$[ebp]
	add	edx, 1
	mov	DWORD PTR _g$[ebp], edx
	mov	eax, DWORD PTR _r$[ebp]
	add	eax, 1
	mov	DWORD PTR _r$[ebp], eax
$L67294:

; 1256 : 	SKEW4(r, g, b, a, fromskew);

	mov	ecx, DWORD PTR _r$[ebp]
	add	ecx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _r$[ebp], ecx
	mov	edx, DWORD PTR _g$[ebp]
	add	edx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _g$[ebp], edx
	mov	eax, DWORD PTR _b$[ebp]
	add	eax, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _b$[ebp], eax
	mov	ecx, DWORD PTR _a$[ebp]
	add	ecx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _a$[ebp], ecx

; 1257 : 	cp += toskew;

	mov	edx, DWORD PTR _toskew$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp$[ebp], ecx

; 1258 :     }

	jmp	$L67254
$L67255:

; 1259 : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68878:
	DD	$L67327
	DD	$L67322
	DD	$L67317
	DD	$L67312
	DD	$L67307
	DD	$L67302
	DD	$L67297
_putRGBAAseparate8bittile ENDP
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_r$ = 40
_g$ = 44
_b$ = 48
_a$ = 52
_rv$67363 = -12
_gv$67364 = -16
_bv$67365 = -8
_av$67366 = -4
_putRGBUAseparate8bittile PROC NEAR

; 1265 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H
$L67361:

; 1266 :     (void) img; (void) y;
; 1267 :     while (h-- > 0) {

	mov	eax, DWORD PTR _h$[ebp]
	mov	ecx, DWORD PTR _h$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _h$[ebp], ecx
	test	eax, eax
	jbe	$L67362

; 1268 : 	uint32 rv, gv, bv, av;
; 1269 : 	for (x = w; x-- > 0;) {

	mov	edx, DWORD PTR _w$[ebp]
	mov	DWORD PTR _x$[ebp], edx
$L67368:
	mov	eax, DWORD PTR _x$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _x$[ebp], ecx
	test	eax, eax
	jbe	$L67369

; 1270 : 	    av = *a++;

	mov	edx, DWORD PTR _a$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	DWORD PTR _av$67366[ebp], eax
	mov	ecx, DWORD PTR _a$[ebp]
	add	ecx, 1
	mov	DWORD PTR _a$[ebp], ecx

; 1271 : 	    rv = (*r++ * av) / 255;

	mov	edx, DWORD PTR _r$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	imul	eax, DWORD PTR _av$67366[ebp]
	xor	edx, edx
	mov	ecx, 255				; 000000ffH
	div	ecx
	mov	DWORD PTR _rv$67363[ebp], eax
	mov	edx, DWORD PTR _r$[ebp]
	add	edx, 1
	mov	DWORD PTR _r$[ebp], edx

; 1272 : 	    gv = (*g++ * av) / 255;

	mov	eax, DWORD PTR _g$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	eax, ecx
	imul	eax, DWORD PTR _av$67366[ebp]
	xor	edx, edx
	mov	ecx, 255				; 000000ffH
	div	ecx
	mov	DWORD PTR _gv$67364[ebp], eax
	mov	edx, DWORD PTR _g$[ebp]
	add	edx, 1
	mov	DWORD PTR _g$[ebp], edx

; 1273 : 	    bv = (*b++ * av) / 255;

	mov	eax, DWORD PTR _b$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	eax, ecx
	imul	eax, DWORD PTR _av$67366[ebp]
	xor	edx, edx
	mov	ecx, 255				; 000000ffH
	div	ecx
	mov	DWORD PTR _bv$67365[ebp], eax
	mov	edx, DWORD PTR _b$[ebp]
	add	edx, 1
	mov	DWORD PTR _b$[ebp], edx

; 1274 : 	    *cp++ = PACK4(rv,gv,bv,av);

	mov	eax, DWORD PTR _gv$67364[ebp]
	shl	eax, 8
	mov	ecx, DWORD PTR _rv$67363[ebp]
	or	ecx, eax
	mov	edx, DWORD PTR _bv$67365[ebp]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	mov	eax, DWORD PTR _av$67366[ebp]
	shl	eax, 24					; 00000018H
	or	ecx, eax
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax

; 1275 : 	}

	jmp	$L67368
$L67369:

; 1276 : 	SKEW4(r, g, b, a, fromskew);

	mov	ecx, DWORD PTR _r$[ebp]
	add	ecx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _r$[ebp], ecx
	mov	edx, DWORD PTR _g$[ebp]
	add	edx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _g$[ebp], edx
	mov	eax, DWORD PTR _b$[ebp]
	add	eax, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _b$[ebp], eax
	mov	ecx, DWORD PTR _a$[ebp]
	add	ecx, DWORD PTR _fromskew$[ebp]
	mov	DWORD PTR _a$[ebp], ecx

; 1277 : 	cp += toskew;

	mov	edx, DWORD PTR _toskew$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp$[ebp], ecx

; 1278 :     }

	jmp	$L67361
$L67362:

; 1279 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_putRGBUAseparate8bittile ENDP
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_r$ = 40
_g$ = 44
_b$ = 48
_wr$ = -8
_wg$ = -12
_wb$ = -4
_putRGBseparate16bittile PROC NEAR

; 1285 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 1286 :     uint16 *wr = (uint16*) r;

	mov	eax, DWORD PTR _r$[ebp]
	mov	DWORD PTR _wr$[ebp], eax

; 1287 :     uint16 *wg = (uint16*) g;

	mov	ecx, DWORD PTR _g$[ebp]
	mov	DWORD PTR _wg$[ebp], ecx

; 1288 :     uint16 *wb = (uint16*) b;

	mov	edx, DWORD PTR _b$[ebp]
	mov	DWORD PTR _wb$[ebp], edx
$L67410:

; 1289 : 
; 1290 :     (void) img; (void) y; (void) a;
; 1291 :     while (h-- > 0) {

	mov	eax, DWORD PTR _h$[ebp]
	mov	ecx, DWORD PTR _h$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _h$[ebp], ecx
	test	eax, eax
	jbe	$L67411

; 1292 : 	for (x = 0; x < w; x++)

	mov	DWORD PTR _x$[ebp], 0
	jmp	SHORT $L67412
$L67413:
	mov	edx, DWORD PTR _x$[ebp]
	add	edx, 1
	mov	DWORD PTR _x$[ebp], edx
$L67412:
	mov	eax, DWORD PTR _x$[ebp]
	cmp	eax, DWORD PTR _w$[ebp]
	jae	SHORT $L67414

; 1293 : 	    *cp++ = PACKW(*wr++, *wg++, *wb++);

	mov	ecx, DWORD PTR _wr$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx]
	sar	edx, 8
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _wg$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	sar	ecx, 8
	and	ecx, 255				; 000000ffH
	shl	ecx, 8
	or	edx, ecx
	mov	eax, DWORD PTR _wb$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	sar	ecx, 8
	and	ecx, 255				; 000000ffH
	shl	ecx, 16					; 00000010H
	or	edx, ecx
	or	edx, -16777216				; ff000000H
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _wb$[ebp]
	add	edx, 2
	mov	DWORD PTR _wb$[ebp], edx
	mov	eax, DWORD PTR _wg$[ebp]
	add	eax, 2
	mov	DWORD PTR _wg$[ebp], eax
	mov	ecx, DWORD PTR _wr$[ebp]
	add	ecx, 2
	mov	DWORD PTR _wr$[ebp], ecx
	jmp	SHORT $L67413
$L67414:

; 1294 : 	SKEW(wr, wg, wb, fromskew);

	mov	edx, DWORD PTR _fromskew$[ebp]
	mov	eax, DWORD PTR _wr$[ebp]
	lea	ecx, DWORD PTR [eax+edx*2]
	mov	DWORD PTR _wr$[ebp], ecx
	mov	edx, DWORD PTR _fromskew$[ebp]
	mov	eax, DWORD PTR _wg$[ebp]
	lea	ecx, DWORD PTR [eax+edx*2]
	mov	DWORD PTR _wg$[ebp], ecx
	mov	edx, DWORD PTR _fromskew$[ebp]
	mov	eax, DWORD PTR _wb$[ebp]
	lea	ecx, DWORD PTR [eax+edx*2]
	mov	DWORD PTR _wb$[ebp], ecx

; 1295 : 	cp += toskew;

	mov	edx, DWORD PTR _toskew$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	lea	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR _cp$[ebp], ecx

; 1296 :     }

	jmp	$L67410
$L67411:

; 1297 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_putRGBseparate16bittile ENDP
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_r$ = 40
_g$ = 44
_b$ = 48
_a$ = 52
_wr$ = -12
_wg$ = -16
_wb$ = -8
_wa$ = -4
_putRGBAAseparate16bittile PROC NEAR

; 1303 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 1304 :     uint16 *wr = (uint16*) r;

	mov	eax, DWORD PTR _r$[ebp]
	mov	DWORD PTR _wr$[ebp], eax

; 1305 :     uint16 *wg = (uint16*) g;

	mov	ecx, DWORD PTR _g$[ebp]
	mov	DWORD PTR _wg$[ebp], ecx

; 1306 :     uint16 *wb = (uint16*) b;

	mov	edx, DWORD PTR _b$[ebp]
	mov	DWORD PTR _wb$[ebp], edx

; 1307 :     uint16 *wa = (uint16*) a;

	mov	eax, DWORD PTR _a$[ebp]
	mov	DWORD PTR _wa$[ebp], eax
$L67456:

; 1308 : 
; 1309 :     (void) img; (void) y;
; 1310 :     while (h-- > 0) {

	mov	ecx, DWORD PTR _h$[ebp]
	mov	edx, DWORD PTR _h$[ebp]
	sub	edx, 1
	mov	DWORD PTR _h$[ebp], edx
	test	ecx, ecx
	jbe	$L67457

; 1311 : 	for (x = 0; x < w; x++)

	mov	DWORD PTR _x$[ebp], 0
	jmp	SHORT $L67458
$L67459:
	mov	eax, DWORD PTR _x$[ebp]
	add	eax, 1
	mov	DWORD PTR _x$[ebp], eax
$L67458:
	mov	ecx, DWORD PTR _x$[ebp]
	cmp	ecx, DWORD PTR _w$[ebp]
	jae	$L67460

; 1312 : 	    *cp++ = PACKW4(*wr++, *wg++, *wb++, *wa++);

	mov	edx, DWORD PTR _wr$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	sar	eax, 8
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _wg$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx]
	sar	edx, 8
	and	edx, 255				; 000000ffH
	shl	edx, 8
	or	eax, edx
	mov	ecx, DWORD PTR _wb$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx]
	sar	edx, 8
	and	edx, 255				; 000000ffH
	shl	edx, 16					; 00000010H
	or	eax, edx
	mov	ecx, DWORD PTR _wa$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx]
	sar	edx, 8
	and	edx, 255				; 000000ffH
	shl	edx, 24					; 00000018H
	or	eax, edx
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 4
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _wa$[ebp]
	add	eax, 2
	mov	DWORD PTR _wa$[ebp], eax
	mov	ecx, DWORD PTR _wb$[ebp]
	add	ecx, 2
	mov	DWORD PTR _wb$[ebp], ecx
	mov	edx, DWORD PTR _wg$[ebp]
	add	edx, 2
	mov	DWORD PTR _wg$[ebp], edx
	mov	eax, DWORD PTR _wr$[ebp]
	add	eax, 2
	mov	DWORD PTR _wr$[ebp], eax
	jmp	$L67459
$L67460:

; 1313 : 	SKEW4(wr, wg, wb, wa, fromskew);

	mov	ecx, DWORD PTR _fromskew$[ebp]
	mov	edx, DWORD PTR _wr$[ebp]
	lea	eax, DWORD PTR [edx+ecx*2]
	mov	DWORD PTR _wr$[ebp], eax
	mov	ecx, DWORD PTR _fromskew$[ebp]
	mov	edx, DWORD PTR _wg$[ebp]
	lea	eax, DWORD PTR [edx+ecx*2]
	mov	DWORD PTR _wg$[ebp], eax
	mov	ecx, DWORD PTR _fromskew$[ebp]
	mov	edx, DWORD PTR _wb$[ebp]
	lea	eax, DWORD PTR [edx+ecx*2]
	mov	DWORD PTR _wb$[ebp], eax
	mov	ecx, DWORD PTR _fromskew$[ebp]
	mov	edx, DWORD PTR _wa$[ebp]
	lea	eax, DWORD PTR [edx+ecx*2]
	mov	DWORD PTR _wa$[ebp], eax

; 1314 : 	cp += toskew;

	mov	ecx, DWORD PTR _toskew$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp$[ebp], eax

; 1315 :     }

	jmp	$L67456
$L67457:

; 1316 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_putRGBAAseparate16bittile ENDP
_cp$ = 12
_x$ = 16
_w$ = 24
_h$ = 28
_fromskew$ = 32
_toskew$ = 36
_r$ = 40
_g$ = 44
_b$ = 48
_a$ = 52
_wr$ = -12
_wg$ = -16
_wb$ = -8
_wa$ = -4
_r$67504 = -28
_g$67505 = -32
_b$67506 = -24
_a$67507 = -20
_putRGBUAseparate16bittile PROC NEAR

; 1322 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 32					; 00000020H

; 1323 :     uint16 *wr = (uint16*) r;

	mov	eax, DWORD PTR _r$[ebp]
	mov	DWORD PTR _wr$[ebp], eax

; 1324 :     uint16 *wg = (uint16*) g;

	mov	ecx, DWORD PTR _g$[ebp]
	mov	DWORD PTR _wg$[ebp], ecx

; 1325 :     uint16 *wb = (uint16*) b;

	mov	edx, DWORD PTR _b$[ebp]
	mov	DWORD PTR _wb$[ebp], edx

; 1326 :     uint16 *wa = (uint16*) a;

	mov	eax, DWORD PTR _a$[ebp]
	mov	DWORD PTR _wa$[ebp], eax
$L67502:

; 1327 : 
; 1328 :     (void) img; (void) y;
; 1329 :     while (h-- > 0) {

	mov	ecx, DWORD PTR _h$[ebp]
	mov	edx, DWORD PTR _h$[ebp]
	sub	edx, 1
	mov	DWORD PTR _h$[ebp], edx
	test	ecx, ecx
	jbe	$L67503

; 1330 : 	uint32 r,g,b,a;
; 1331 : 	/*
; 1332 : 	 * We shift alpha down four bits just in case unsigned
; 1333 : 	 * arithmetic doesn't handle the full range.
; 1334 : 	 * We still have plenty of accuracy, since the output is 8 bits.
; 1335 : 	 * So we have (r * 0xffff) * (a * 0xfff)) = r*a * (0xffff*0xfff)
; 1336 : 	 * Since we want r*a * 0xff for eight bit output,
; 1337 : 	 * we divide by (0xffff * 0xfff) / 0xff == 0x10eff.
; 1338 : 	 */
; 1339 : 	for (x = w; x-- > 0;) {

	mov	eax, DWORD PTR _w$[ebp]
	mov	DWORD PTR _x$[ebp], eax
$L67509:
	mov	ecx, DWORD PTR _x$[ebp]
	mov	edx, DWORD PTR _x$[ebp]
	sub	edx, 1
	mov	DWORD PTR _x$[ebp], edx
	test	ecx, ecx
	jbe	$L67510

; 1340 : 	    a = *wa++ >> 4; 

	mov	eax, DWORD PTR _wa$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	sar	ecx, 4
	mov	DWORD PTR _a$67507[ebp], ecx
	mov	edx, DWORD PTR _wa$[ebp]
	add	edx, 2
	mov	DWORD PTR _wa$[ebp], edx

; 1341 : 	    r = (*wr++ * a) / 0x10eff;

	mov	eax, DWORD PTR _wr$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	mov	eax, ecx
	imul	eax, DWORD PTR _a$67507[ebp]
	xor	edx, edx
	mov	ecx, 69375				; 00010effH
	div	ecx
	mov	DWORD PTR _r$67504[ebp], eax
	mov	edx, DWORD PTR _wr$[ebp]
	add	edx, 2
	mov	DWORD PTR _wr$[ebp], edx

; 1342 : 	    g = (*wg++ * a) / 0x10eff;

	mov	eax, DWORD PTR _wg$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	mov	eax, ecx
	imul	eax, DWORD PTR _a$67507[ebp]
	xor	edx, edx
	mov	ecx, 69375				; 00010effH
	div	ecx
	mov	DWORD PTR _g$67505[ebp], eax
	mov	edx, DWORD PTR _wg$[ebp]
	add	edx, 2
	mov	DWORD PTR _wg$[ebp], edx

; 1343 : 	    b = (*wb++ * a) / 0x10eff;

	mov	eax, DWORD PTR _wb$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	mov	eax, ecx
	imul	eax, DWORD PTR _a$67507[ebp]
	xor	edx, edx
	mov	ecx, 69375				; 00010effH
	div	ecx
	mov	DWORD PTR _b$67506[ebp], eax
	mov	edx, DWORD PTR _wb$[ebp]
	add	edx, 2
	mov	DWORD PTR _wb$[ebp], edx

; 1344 : 	    *cp++ = PACK4(r,g,b,a);

	mov	eax, DWORD PTR _g$67505[ebp]
	shl	eax, 8
	mov	ecx, DWORD PTR _r$67504[ebp]
	or	ecx, eax
	mov	edx, DWORD PTR _b$67506[ebp]
	shl	edx, 16					; 00000010H
	or	ecx, edx
	mov	eax, DWORD PTR _a$67507[ebp]
	shl	eax, 24					; 00000018H
	or	ecx, eax
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 4
	mov	DWORD PTR _cp$[ebp], eax

; 1345 : 	}

	jmp	$L67509
$L67510:

; 1346 : 	SKEW4(wr, wg, wb, wa, fromskew);

	mov	ecx, DWORD PTR _fromskew$[ebp]
	mov	edx, DWORD PTR _wr$[ebp]
	lea	eax, DWORD PTR [edx+ecx*2]
	mov	DWORD PTR _wr$[ebp], eax
	mov	ecx, DWORD PTR _fromskew$[ebp]
	mov	edx, DWORD PTR _wg$[ebp]
	lea	eax, DWORD PTR [edx+ecx*2]
	mov	DWORD PTR _wg$[ebp], eax
	mov	ecx, DWORD PTR _fromskew$[ebp]
	mov	edx, DWORD PTR _wb$[ebp]
	lea	eax, DWORD PTR [edx+ecx*2]
	mov	DWORD PTR _wb$[ebp], eax
	mov	ecx, DWORD PTR _fromskew$[ebp]
	mov	edx, DWORD PTR _wa$[ebp]
	lea	eax, DWORD PTR [edx+ecx*2]
	mov	DWORD PTR _wa$[ebp], eax

; 1347 : 	cp += toskew;

	mov	ecx, DWORD PTR _toskew$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR _cp$[ebp], eax

; 1348 :     }

	jmp	$L67502
$L67503:

; 1349 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_putRGBUAseparate16bittile ENDP
_TEXT	ENDS
PUBLIC	_TIFFReadRGBAStrip
_DATA	SEGMENT
	ORG $+1
$SG68715 DB	'Can''t use TIFFReadRGBAStrip() with tiled file.', 00H
	ORG $+1
$SG68717 DB	'Row passed to TIFFReadRGBAStrip() must be first in a str'
	DB	'ip.', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_row$ = 12
_raster$ = 16
_emsg$ = -1112
_img$ = -80
_ok$ = -88
_rowsperstrip$ = -84
_rows_to_read$ = -4
_TIFFReadRGBAStrip PROC NEAR

; 2276 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 1112				; 00000458H

; 2277 :     char 	emsg[1024];
; 2278 :     TIFFRGBAImage img;
; 2279 :     int 	ok;
; 2280 :     uint32	rowsperstrip, rows_to_read;
; 2281 : 
; 2282 :     if( TIFFIsTiled( tif ) )

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFIsTiled
	add	esp, 4
	test	eax, eax
	je	SHORT $L68714

; 2284 :         TIFFError(TIFFFileName(tif),
; 2285 :                   "Can't use TIFFReadRGBAStrip() with tiled file.");

	push	OFFSET FLAT:$SG68715
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 2286 : 	return (0);

	xor	eax, eax
	jmp	$L68708
$L68714:

; 2288 :     
; 2289 :     TIFFGetFieldDefaulted(tif, TIFFTAG_ROWSPERSTRIP, &rowsperstrip);

	lea	edx, DWORD PTR _rowsperstrip$[ebp]
	push	edx
	push	278					; 00000116H
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetFieldDefaulted
	add	esp, 12					; 0000000cH

; 2290 :     if( (row % rowsperstrip) != 0 )

	mov	eax, DWORD PTR _row$[ebp]
	xor	edx, edx
	div	DWORD PTR _rowsperstrip$[ebp]
	test	edx, edx
	je	SHORT $L68716

; 2292 :         TIFFError(TIFFFileName(tif),
; 2293 :                 "Row passed to TIFFReadRGBAStrip() must be first in a strip.");

	push	OFFSET FLAT:$SG68717
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 2294 : 	return (0);

	xor	eax, eax
	jmp	$L68708
$L68716:

; 2296 : 
; 2297 :     if (TIFFRGBAImageBegin(&img, tif, 0, emsg)) {

	lea	edx, DWORD PTR _emsg$[ebp]
	push	edx
	push	0
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	lea	ecx, DWORD PTR _img$[ebp]
	push	ecx
	call	_TIFFRGBAImageBegin
	add	esp, 16					; 00000010H
	test	eax, eax
	je	SHORT $L68718

; 2298 : 
; 2299 :         img.row_offset = row;

	mov	edx, DWORD PTR _row$[ebp]
	mov	DWORD PTR _img$[ebp+68], edx

; 2300 :         img.col_offset = 0;

	mov	DWORD PTR _img$[ebp+72], 0

; 2301 : 
; 2302 :         if( row + rowsperstrip > img.height )

	mov	eax, DWORD PTR _row$[ebp]
	add	eax, DWORD PTR _rowsperstrip$[ebp]
	cmp	eax, DWORD PTR _img$[ebp+20]
	jbe	SHORT $L68719

; 2303 :             rows_to_read = img.height - row;

	mov	ecx, DWORD PTR _img$[ebp+20]
	sub	ecx, DWORD PTR _row$[ebp]
	mov	DWORD PTR _rows_to_read$[ebp], ecx

; 2304 :         else

	jmp	SHORT $L68720
$L68719:

; 2305 :             rows_to_read = rowsperstrip;

	mov	edx, DWORD PTR _rowsperstrip$[ebp]
	mov	DWORD PTR _rows_to_read$[ebp], edx
$L68720:

; 2306 :         
; 2307 : 	ok = TIFFRGBAImageGet(&img, raster, img.width, rows_to_read );

	mov	eax, DWORD PTR _rows_to_read$[ebp]
	push	eax
	mov	ecx, DWORD PTR _img$[ebp+16]
	push	ecx
	mov	edx, DWORD PTR _raster$[ebp]
	push	edx
	lea	eax, DWORD PTR _img$[ebp]
	push	eax
	call	_TIFFRGBAImageGet
	add	esp, 16					; 00000010H
	mov	DWORD PTR _ok$[ebp], eax

; 2308 :         
; 2309 : 	TIFFRGBAImageEnd(&img);

	lea	ecx, DWORD PTR _img$[ebp]
	push	ecx
	call	_TIFFRGBAImageEnd
	add	esp, 4

; 2310 :     } else {

	jmp	SHORT $L68721
$L68718:

; 2311 : 	TIFFError(TIFFFileName(tif), emsg);

	lea	edx, DWORD PTR _emsg$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 2312 : 	ok = 0;

	mov	DWORD PTR _ok$[ebp], 0
$L68721:

; 2314 :     
; 2315 :     return (ok);

	mov	eax, DWORD PTR _ok$[ebp]
$L68708:

; 2316 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFReadRGBAStrip ENDP
_TEXT	ENDS
PUBLIC	_TIFFReadRGBATile
EXTRN	_memmove:NEAR
_DATA	SEGMENT
$SG68740 DB	'Can''t use TIFFReadRGBATile() with stripped file.', 00H
	ORG $+3
$SG68743 DB	'Row/col passed to TIFFReadRGBATile() must be topleft cor'
	DB	'ner of a tile.', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_col$ = 12
_row$ = 16
_raster$ = 20
_emsg$ = -1124
_img$ = -80
_ok$ = -100
_tile_xsize$ = -96
_tile_ysize$ = -84
_read_xsize$ = -92
_read_ysize$ = -4
_i_row$ = -88
_TIFFReadRGBATile PROC NEAR

; 2327 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 1124				; 00000464H

; 2328 :     char 	emsg[1024];
; 2329 :     TIFFRGBAImage img;
; 2330 :     int 	ok;
; 2331 :     uint32	tile_xsize, tile_ysize;
; 2332 :     uint32	read_xsize, read_ysize;
; 2333 :     uint32	i_row;
; 2334 : 
; 2335 :     /*
; 2336 :      * Verify that our request is legal - on a tile file, and on a
; 2337 :      * tile boundary.
; 2338 :      */
; 2339 :     
; 2340 :     if( !TIFFIsTiled( tif ) )

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFIsTiled
	add	esp, 4
	test	eax, eax
	jne	SHORT $L68739

; 2342 :         TIFFError(TIFFFileName(tif),
; 2343 :                   "Can't use TIFFReadRGBATile() with stripped file.");

	push	OFFSET FLAT:$SG68740
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 2344 : 	return (0);

	xor	eax, eax
	jmp	$L68730
$L68739:

; 2346 :     
; 2347 :     TIFFGetFieldDefaulted(tif, TIFFTAG_TILEWIDTH, &tile_xsize);

	lea	edx, DWORD PTR _tile_xsize$[ebp]
	push	edx
	push	322					; 00000142H
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFGetFieldDefaulted
	add	esp, 12					; 0000000cH

; 2348 :     TIFFGetFieldDefaulted(tif, TIFFTAG_TILELENGTH, &tile_ysize);

	lea	ecx, DWORD PTR _tile_ysize$[ebp]
	push	ecx
	push	323					; 00000143H
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFGetFieldDefaulted
	add	esp, 12					; 0000000cH

; 2349 :     if( (col % tile_xsize) != 0 || (row % tile_ysize) != 0 )

	mov	eax, DWORD PTR _col$[ebp]
	xor	edx, edx
	div	DWORD PTR _tile_xsize$[ebp]
	test	edx, edx
	jne	SHORT $L68742
	mov	eax, DWORD PTR _row$[ebp]
	xor	edx, edx
	div	DWORD PTR _tile_ysize$[ebp]
	test	edx, edx
	je	SHORT $L68741
$L68742:

; 2351 :         TIFFError(TIFFFileName(tif),
; 2352 :                   "Row/col passed to TIFFReadRGBATile() must be top"
; 2353 :                   "left corner of a tile.");

	push	OFFSET FLAT:$SG68743
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 2354 : 	return (0);

	xor	eax, eax
	jmp	$L68730
$L68741:

; 2356 : 
; 2357 :     /*
; 2358 :      * Setup the RGBA reader.
; 2359 :      */
; 2360 :     
; 2361 :     if ( !TIFFRGBAImageBegin(&img, tif, 0, emsg)) {

	lea	ecx, DWORD PTR _emsg$[ebp]
	push	ecx
	push	0
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	lea	eax, DWORD PTR _img$[ebp]
	push	eax
	call	_TIFFRGBAImageBegin
	add	esp, 16					; 00000010H
	test	eax, eax
	jne	SHORT $L68744

; 2362 : 	TIFFError(TIFFFileName(tif), emsg);

	lea	ecx, DWORD PTR _emsg$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFileName
	add	esp, 4
	push	eax
	call	_TIFFError
	add	esp, 8

; 2363 :         return( 0 );

	xor	eax, eax
	jmp	$L68730
$L68744:

; 2365 : 
; 2366 :     /*
; 2367 :      * The TIFFRGBAImageGet() function doesn't allow us to get off the
; 2368 :      * edge of the image, even to fill an otherwise valid tile.  So we
; 2369 :      * figure out how much we can read, and fix up the tile buffer to
; 2370 :      * a full tile configuration afterwards.
; 2371 :      */
; 2372 : 
; 2373 :     if( row + tile_ysize > img.height )

	mov	eax, DWORD PTR _row$[ebp]
	add	eax, DWORD PTR _tile_ysize$[ebp]
	cmp	eax, DWORD PTR _img$[ebp+20]
	jbe	SHORT $L68745

; 2374 :         read_ysize = img.height - row;

	mov	ecx, DWORD PTR _img$[ebp+20]
	sub	ecx, DWORD PTR _row$[ebp]
	mov	DWORD PTR _read_ysize$[ebp], ecx

; 2375 :     else

	jmp	SHORT $L68746
$L68745:

; 2376 :         read_ysize = tile_ysize;

	mov	edx, DWORD PTR _tile_ysize$[ebp]
	mov	DWORD PTR _read_ysize$[ebp], edx
$L68746:

; 2377 :     
; 2378 :     if( col + tile_xsize > img.width )

	mov	eax, DWORD PTR _col$[ebp]
	add	eax, DWORD PTR _tile_xsize$[ebp]
	cmp	eax, DWORD PTR _img$[ebp+16]
	jbe	SHORT $L68747

; 2379 :         read_xsize = img.width - col;

	mov	ecx, DWORD PTR _img$[ebp+16]
	sub	ecx, DWORD PTR _col$[ebp]
	mov	DWORD PTR _read_xsize$[ebp], ecx

; 2380 :     else

	jmp	SHORT $L68748
$L68747:

; 2381 :         read_xsize = tile_xsize;

	mov	edx, DWORD PTR _tile_xsize$[ebp]
	mov	DWORD PTR _read_xsize$[ebp], edx
$L68748:

; 2382 : 
; 2383 :     /*
; 2384 :      * Read the chunk of imagery.
; 2385 :      */
; 2386 :     
; 2387 :     img.row_offset = row;

	mov	eax, DWORD PTR _row$[ebp]
	mov	DWORD PTR _img$[ebp+68], eax

; 2388 :     img.col_offset = col;

	mov	ecx, DWORD PTR _col$[ebp]
	mov	DWORD PTR _img$[ebp+72], ecx

; 2389 : 
; 2390 :     ok = TIFFRGBAImageGet(&img, raster, read_xsize, read_ysize );

	mov	edx, DWORD PTR _read_ysize$[ebp]
	push	edx
	mov	eax, DWORD PTR _read_xsize$[ebp]
	push	eax
	mov	ecx, DWORD PTR _raster$[ebp]
	push	ecx
	lea	edx, DWORD PTR _img$[ebp]
	push	edx
	call	_TIFFRGBAImageGet
	add	esp, 16					; 00000010H
	mov	DWORD PTR _ok$[ebp], eax

; 2391 :         
; 2392 :     TIFFRGBAImageEnd(&img);

	lea	eax, DWORD PTR _img$[ebp]
	push	eax
	call	_TIFFRGBAImageEnd
	add	esp, 4

; 2393 : 
; 2394 :     /*
; 2395 :      * If our read was incomplete we will need to fix up the tile by
; 2396 :      * shifting the data around as if a full tile of data is being returned.
; 2397 :      *
; 2398 :      * This is all the more complicated because the image is organized in
; 2399 :      * bottom to top format. 
; 2400 :      */
; 2401 : 
; 2402 :     if( read_xsize == tile_xsize && read_ysize == tile_ysize )

	mov	ecx, DWORD PTR _read_xsize$[ebp]
	cmp	ecx, DWORD PTR _tile_xsize$[ebp]
	jne	SHORT $L68749
	mov	edx, DWORD PTR _read_ysize$[ebp]
	cmp	edx, DWORD PTR _tile_ysize$[ebp]
	jne	SHORT $L68749

; 2403 :         return( ok );

	mov	eax, DWORD PTR _ok$[ebp]
	jmp	$L68730
$L68749:

; 2404 : 
; 2405 :     for( i_row = 0; i_row < read_ysize; i_row++ )

	mov	DWORD PTR _i_row$[ebp], 0
	jmp	SHORT $L68750
$L68751:
	mov	eax, DWORD PTR _i_row$[ebp]
	add	eax, 1
	mov	DWORD PTR _i_row$[ebp], eax
$L68750:
	mov	ecx, DWORD PTR _i_row$[ebp]
	cmp	ecx, DWORD PTR _read_ysize$[ebp]
	jae	SHORT $L68752

; 2407 :         memmove( raster + (tile_ysize - i_row - 1) * tile_xsize,
; 2408 :                  raster + (read_ysize - i_row - 1) * read_xsize,
; 2409 :                  read_xsize * sizeof(uint32) );

	mov	edx, DWORD PTR _read_xsize$[ebp]
	shl	edx, 2
	push	edx
	mov	eax, DWORD PTR _read_ysize$[ebp]
	sub	eax, DWORD PTR _i_row$[ebp]
	sub	eax, 1
	imul	eax, DWORD PTR _read_xsize$[ebp]
	mov	ecx, DWORD PTR _raster$[ebp]
	lea	edx, DWORD PTR [ecx+eax*4]
	push	edx
	mov	eax, DWORD PTR _tile_ysize$[ebp]
	sub	eax, DWORD PTR _i_row$[ebp]
	sub	eax, 1
	imul	eax, DWORD PTR _tile_xsize$[ebp]
	mov	ecx, DWORD PTR _raster$[ebp]
	lea	edx, DWORD PTR [ecx+eax*4]
	push	edx
	call	_memmove
	add	esp, 12					; 0000000cH

; 2410 :         _TIFFmemset( raster + (tile_ysize - i_row - 1) * tile_xsize+read_xsize,
; 2411 :                      0, sizeof(uint32) * (tile_xsize - read_xsize) );

	mov	eax, DWORD PTR _tile_xsize$[ebp]
	sub	eax, DWORD PTR _read_xsize$[ebp]
	shl	eax, 2
	push	eax
	push	0
	mov	ecx, DWORD PTR _tile_ysize$[ebp]
	sub	ecx, DWORD PTR _i_row$[ebp]
	sub	ecx, 1
	imul	ecx, DWORD PTR _tile_xsize$[ebp]
	mov	edx, DWORD PTR _raster$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _read_xsize$[ebp]
	lea	edx, DWORD PTR [eax+ecx*4]
	push	edx
	call	__TIFFmemset
	add	esp, 12					; 0000000cH

; 2412 :     }

	jmp	SHORT $L68751
$L68752:

; 2413 : 
; 2414 :     for( i_row = read_ysize; i_row < tile_ysize; i_row++ )

	mov	eax, DWORD PTR _read_ysize$[ebp]
	mov	DWORD PTR _i_row$[ebp], eax
	jmp	SHORT $L68755
$L68756:
	mov	ecx, DWORD PTR _i_row$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i_row$[ebp], ecx
$L68755:
	mov	edx, DWORD PTR _i_row$[ebp]
	cmp	edx, DWORD PTR _tile_ysize$[ebp]
	jae	SHORT $L68757

; 2416 :         _TIFFmemset( raster + (tile_ysize - i_row - 1) * tile_xsize,
; 2417 :                      0, sizeof(uint32) * tile_xsize );

	mov	eax, DWORD PTR _tile_xsize$[ebp]
	shl	eax, 2
	push	eax
	push	0
	mov	ecx, DWORD PTR _tile_ysize$[ebp]
	sub	ecx, DWORD PTR _i_row$[ebp]
	sub	ecx, 1
	imul	ecx, DWORD PTR _tile_xsize$[ebp]
	mov	edx, DWORD PTR _raster$[ebp]
	lea	eax, DWORD PTR [edx+ecx*4]
	push	eax
	call	__TIFFmemset
	add	esp, 12					; 0000000cH

; 2418 :     }

	jmp	SHORT $L68756
$L68757:

; 2419 : 
; 2420 :     return (ok);

	mov	eax, DWORD PTR _ok$[ebp]
$L68730:

; 2421 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFReadRGBATile ENDP
_TEXT	ENDS
END
