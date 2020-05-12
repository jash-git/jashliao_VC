	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_aux.c
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
PUBLIC	_TIFFVGetFieldDefaulted
EXTRN	__TIFFmalloc:NEAR
EXTRN	_TIFFVGetField:NEAR
EXTRN	__fltused:NEAR
_TEXT	SEGMENT
_tif$ = 8
_tag$ = 12
_ap$ = 16
_td$ = -4
_TIFFVGetFieldDefaulted PROC NEAR

; 80   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 81   : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 82   : 
; 83   : 	if (TIFFVGetField(tif, tag, ap))

	mov	ecx, DWORD PTR _ap$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tag$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFVGetField
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L65975

; 84   : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L65975:

; 85   : 	switch (tag) {

	mov	ecx, DWORD PTR _tag$[ebp]
	mov	DWORD PTR -8+[ebp], ecx
	cmp	DWORD PTR -8+[ebp], 332			; 0000014cH
	ja	SHORT $L66238
	cmp	DWORD PTR -8+[ebp], 332			; 0000014cH
	je	$L66083
	mov	edx, DWORD PTR -8+[ebp]
	sub	edx, 254				; 000000feH
	mov	DWORD PTR -8+[ebp], edx
	cmp	DWORD PTR -8+[ebp], 47			; 0000002fH
	ja	$L65977
	mov	ecx, DWORD PTR -8+[ebp]
	xor	eax, eax
	mov	al, BYTE PTR $L66241[ecx]
	jmp	DWORD PTR $L66242[eax*4]
$L66238:
	cmp	DWORD PTR -8+[ebp], 531			; 00000213H
	ja	SHORT $L66239
	cmp	DWORD PTR -8+[ebp], 531			; 00000213H
	je	$L66180
	mov	edx, DWORD PTR -8+[ebp]
	sub	edx, 334				; 0000014eH
	mov	DWORD PTR -8+[ebp], edx
	cmp	DWORD PTR -8+[ebp], 196			; 000000c4H
	ja	$L65977
	mov	ecx, DWORD PTR -8+[ebp]
	xor	eax, eax
	mov	al, BYTE PTR $L66243[ecx]
	jmp	DWORD PTR $L66244[eax*4]
$L66239:
	cmp	DWORD PTR -8+[ebp], 32996		; 000080e4H
	ja	SHORT $L66240
	cmp	DWORD PTR -8+[ebp], 32996		; 000080e4H
	je	$L66130
	cmp	DWORD PTR -8+[ebp], 532			; 00000214H
	je	$L66212
	cmp	DWORD PTR -8+[ebp], 32995		; 000080e3H
	je	$L66114
	jmp	$L65977
$L66240:
	cmp	DWORD PTR -8+[ebp], 32997		; 000080e5H
	je	$L66146
	cmp	DWORD PTR -8+[ebp], 32998		; 000080e6H
	je	$L66122
	jmp	$L65977
$L65980:

; 86   : 	case TIFFTAG_SUBFILETYPE:
; 87   : 		*va_arg(ap, uint32 *) = td->td_subfiletype;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+36]
	mov	DWORD PTR [ecx], eax

; 88   : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L65988:

; 89   : 	case TIFFTAG_BITSPERSAMPLE:
; 90   : 		*va_arg(ap, uint16 *) = td->td_bitspersample;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	dx, WORD PTR [ecx+40]
	mov	WORD PTR [eax], dx

; 91   : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L65996:

; 92   : 	case TIFFTAG_THRESHHOLDING:
; 93   : 		*va_arg(ap, uint16 *) = td->td_threshholding;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	cx, WORD PTR [eax+48]
	mov	WORD PTR [edx], cx

; 94   : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66004:

; 95   : 	case TIFFTAG_FILLORDER:
; 96   : 		*va_arg(ap, uint16 *) = td->td_fillorder;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	ax, WORD PTR [edx+50]
	mov	WORD PTR [ecx], ax

; 97   : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66012:

; 98   : 	case TIFFTAG_ORIENTATION:
; 99   : 		*va_arg(ap, uint16 *) = td->td_orientation;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	dx, WORD PTR [ecx+52]
	mov	WORD PTR [eax], dx

; 100  : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66020:

; 101  : 	case TIFFTAG_SAMPLESPERPIXEL:
; 102  : 		*va_arg(ap, uint16 *) = td->td_samplesperpixel;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	cx, WORD PTR [eax+54]
	mov	WORD PTR [edx], cx

; 103  : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66028:

; 104  : 	case TIFFTAG_ROWSPERSTRIP:
; 105  : 		*va_arg(ap, uint32 *) = td->td_rowsperstrip;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	DWORD PTR [ecx], eax

; 106  : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66036:

; 107  : 	case TIFFTAG_MINSAMPLEVALUE:
; 108  : 		*va_arg(ap, uint16 *) = td->td_minsamplevalue;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	dx, WORD PTR [ecx+60]
	mov	WORD PTR [eax], dx

; 109  : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66044:

; 110  : 	case TIFFTAG_MAXSAMPLEVALUE:
; 111  : 		*va_arg(ap, uint16 *) = td->td_maxsamplevalue;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	cx, WORD PTR [eax+62]
	mov	WORD PTR [edx], cx

; 112  : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66052:

; 113  : 	case TIFFTAG_PLANARCONFIG:
; 114  : 		*va_arg(ap, uint16 *) = td->td_planarconfig;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	ax, WORD PTR [edx+90]
	mov	WORD PTR [ecx], ax

; 115  : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66060:

; 116  : 	case TIFFTAG_RESOLUTIONUNIT:
; 117  : 		*va_arg(ap, uint16 *) = td->td_resolutionunit;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	dx, WORD PTR [ecx+88]
	mov	WORD PTR [eax], dx

; 118  : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66068:

; 119  : #ifdef CMYK_SUPPORT
; 120  : 	case TIFFTAG_DOTRANGE:
; 121  : 		*va_arg(ap, uint16 *) = 0;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	WORD PTR [edx], 0

; 122  : 		*va_arg(ap, uint16 *) = (1<<td->td_bitspersample)-1;

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+40]
	mov	edx, 1
	shl	edx, cl
	sub	edx, 1
	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [ecx-4]
	mov	WORD PTR [eax], dx

; 123  : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66083:

; 124  : 	case TIFFTAG_INKSET:
; 125  : 		*va_arg(ap, uint16 *) = td->td_inkset;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	dx, WORD PTR [ecx+236]
	mov	WORD PTR [eax], dx

; 126  : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66091:

; 127  : 	case TIFFTAG_NUMBEROFINKS:
; 128  : 		*va_arg(ap, uint16 *) = td->td_ninks;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	cx, WORD PTR [eax+238]
	mov	WORD PTR [edx], cx

; 129  : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66099:

; 130  : #endif
; 131  : 	case TIFFTAG_EXTRASAMPLES:
; 132  : 		*va_arg(ap, uint16 *) = td->td_extrasamples;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	ax, WORD PTR [edx+120]
	mov	WORD PTR [ecx], ax

; 133  : 		*va_arg(ap, uint16 **) = td->td_sampleinfo;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+124]
	mov	DWORD PTR [eax], edx

; 134  : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66114:

; 135  : 	case TIFFTAG_MATTEING:
; 136  : 		*va_arg(ap, uint16 *) =
; 137  : 		    (td->td_extrasamples == 1 &&
; 138  : 		     td->td_sampleinfo[0] == EXTRASAMPLE_ASSOCALPHA);

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+120]
	cmp	ecx, 1
	jne	SHORT $L66236
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+124]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	cmp	ecx, 1
	jne	SHORT $L66236
	mov	DWORD PTR -12+[ebp], 1
	jmp	SHORT $L66237
$L66236:
	mov	DWORD PTR -12+[ebp], 0
$L66237:
	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	dx, WORD PTR -12+[ebp]
	mov	WORD PTR [ecx], dx

; 139  : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66122:

; 140  : 	case TIFFTAG_TILEDEPTH:
; 141  : 		*va_arg(ap, uint32 *) = td->td_tiledepth;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+32]
	mov	DWORD PTR [edx], ecx

; 142  : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66130:

; 143  : 	case TIFFTAG_DATATYPE:
; 144  : 		*va_arg(ap, uint16 *) = td->td_sampleformat-1;

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+42]
	sub	eax, 1
	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [edx-4]
	mov	WORD PTR [ecx], ax

; 145  : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66138:

; 146  : 	case TIFFTAG_SAMPLEFORMAT:
; 147  : 		*va_arg(ap, uint16 *) = td->td_sampleformat;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	ax, WORD PTR [edx+42]
	mov	WORD PTR [ecx], ax

; 148  :                 return(1);

	mov	eax, 1
	jmp	$L65973
$L66146:

; 149  : 	case TIFFTAG_IMAGEDEPTH:
; 150  : 		*va_arg(ap, uint32 *) = td->td_imagedepth;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+20]
	mov	DWORD PTR [eax], edx

; 151  : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66154:

; 152  : #ifdef YCBCR_SUPPORT
; 153  : 	case TIFFTAG_YCBCRCOEFFICIENTS:
; 154  : 		if (!td->td_ycbcrcoeffs) {

	mov	eax, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [eax+200], 0
	jne	SHORT $L66155

; 155  : 			td->td_ycbcrcoeffs = (float *)
; 156  : 			    _TIFFmalloc(3*sizeof (float));

	push	12					; 0000000cH
	call	__TIFFmalloc
	add	esp, 4
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+200], eax

; 157  : 			/* defaults are from CCIR Recommendation 601-1 */
; 158  : 			td->td_ycbcrcoeffs[0] = 0.299f;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+200]
	mov	DWORD PTR [eax], 1050220167		; 3e991687H

; 159  : 			td->td_ycbcrcoeffs[1] = 0.587f;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+200]
	mov	DWORD PTR [edx+4], 1058424226		; 3f1645a2H

; 160  : 			td->td_ycbcrcoeffs[2] = 0.114f;

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+200]
	mov	DWORD PTR [ecx+8], 1038710997		; 3de978d5H
$L66155:

; 162  : 		*va_arg(ap, float **) = td->td_ycbcrcoeffs;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+200]
	mov	DWORD PTR [ecx], eax

; 163  : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66165:

; 164  : 	case TIFFTAG_YCBCRSUBSAMPLING:
; 165  : 		*va_arg(ap, uint16 *) = td->td_ycbcrsubsampling[0];

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	dx, WORD PTR [ecx+204]
	mov	WORD PTR [eax], dx

; 166  : 		*va_arg(ap, uint16 *) = td->td_ycbcrsubsampling[1];

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	cx, WORD PTR [eax+206]
	mov	WORD PTR [edx], cx

; 167  : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66180:

; 168  : 	case TIFFTAG_YCBCRPOSITIONING:
; 169  : 		*va_arg(ap, uint16 *) = td->td_ycbcrpositioning;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	ax, WORD PTR [edx+208]
	mov	WORD PTR [ecx], ax

; 170  : 		return (1);

	mov	eax, 1
	jmp	$L65973
$L66188:

; 171  : #endif
; 172  : #ifdef COLORIMETRY_SUPPORT
; 173  : 	case TIFFTAG_TRANSFERFUNCTION:
; 174  : 		if (!td->td_transferfunction[0])

	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+224], 0
	jne	SHORT $L66189

; 175  : 			TIFFDefaultTransferFunction(td);

	mov	edx, DWORD PTR _td$[ebp]
	push	edx
	call	_TIFFDefaultTransferFunction
	add	esp, 4
$L66189:

; 176  : 		*va_arg(ap, uint16 **) = td->td_transferfunction[0];

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+224]
	mov	DWORD PTR [edx], ecx

; 177  : 		if (td->td_samplesperpixel - td->td_extrasamples > 1) {

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+54]
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+120]
	sub	eax, edx
	cmp	eax, 1
	jle	SHORT $L66197

; 178  : 			*va_arg(ap, uint16 **) = td->td_transferfunction[1];

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+228]
	mov	DWORD PTR [edx], ecx

; 179  : 			*va_arg(ap, uint16 **) = td->td_transferfunction[2];

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+232]
	mov	DWORD PTR [ecx], eax
$L66197:

; 181  : 		return (1);

	mov	eax, 1
	jmp	SHORT $L65973
$L66212:

; 182  : 	case TIFFTAG_REFERENCEBLACKWHITE:
; 183  : 		if (!td->td_refblackwhite)

	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+220], 0
	jne	SHORT $L66213

; 184  : 			TIFFDefaultRefBlackWhite(td);

	mov	edx, DWORD PTR _td$[ebp]
	push	edx
	call	_TIFFDefaultRefBlackWhite
	add	esp, 4
$L66213:

; 185  : 		*va_arg(ap, float **) = td->td_refblackwhite;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+220]
	mov	DWORD PTR [edx], ecx

; 186  : 		return (1);

	mov	eax, 1
	jmp	SHORT $L65973
$L65977:

; 189  : 	return (0);

	xor	eax, eax
$L65973:

; 190  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L66242:
	DD	$L65980
	DD	$L65988
	DD	$L65996
	DD	$L66004
	DD	$L66012
	DD	$L66020
	DD	$L66028
	DD	$L66036
	DD	$L66044
	DD	$L66052
	DD	$L66060
	DD	$L66188
	DD	$L65977
$L66241:
	DB	0
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	1
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	2
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	3
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	4
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	5
	DB	6
	DB	12					; 0000000cH
	DB	7
	DB	8
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	9
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	10					; 0000000aH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	12					; 0000000cH
	DB	11					; 0000000bH
$L66244:
	DD	$L66091
	DD	$L66068
	DD	$L66099
	DD	$L66138
	DD	$L66154
	DD	$L66165
	DD	$L65977
$L66243:
	DB	0
	DB	6
	DB	1
	DB	6
	DB	2
	DB	3
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
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	6
	DB	4
	DB	5
_TIFFVGetFieldDefaulted ENDP
_TEXT	ENDS
PUBLIC	__real@8@3fff8000000000000000
PUBLIC	__real@8@400effff000000000000
PUBLIC	__real@8@3ffe8000000000000000
EXTRN	_pow:NEAR
EXTRN	_floor:NEAR
EXTRN	__TIFFmemcpy:NEAR
EXTRN	__ftol:NEAR
;	COMDAT __real@8@3fff8000000000000000
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_aux.c
CONST	SEGMENT
__real@8@3fff8000000000000000 DQ 03ff0000000000000r ; 1
CONST	ENDS
;	COMDAT __real@8@400effff000000000000
CONST	SEGMENT
__real@8@400effff000000000000 DQ 040efffe000000000r ; 65535
CONST	ENDS
;	COMDAT __real@8@3ffe8000000000000000
CONST	SEGMENT
__real@8@3ffe8000000000000000 DQ 03fe0000000000000r ; 0.5
CONST	ENDS
_TEXT	SEGMENT
_td$ = 8
_tf$ = -8
_i$ = -4
_n$ = -12
_t$65945 = -20
_TIFFDefaultTransferFunction PROC NEAR

; 39   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 20					; 00000014H

; 40   : 	uint16 **tf = td->td_transferfunction;

	mov	eax, DWORD PTR _td$[ebp]
	add	eax, 224				; 000000e0H
	mov	DWORD PTR _tf$[ebp], eax

; 41   : 	long i, n = 1<<td->td_bitspersample;

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+40]
	mov	ecx, edx
	mov	eax, 1
	shl	eax, cl
	mov	DWORD PTR _n$[ebp], eax

; 42   : 
; 43   : 	tf[0] = (uint16 *)_TIFFmalloc(n * sizeof (uint16));

	mov	ecx, DWORD PTR _n$[ebp]
	shl	ecx, 1
	push	ecx
	call	__TIFFmalloc
	add	esp, 4
	mov	edx, DWORD PTR _tf$[ebp]
	mov	DWORD PTR [edx], eax

; 44   : 	tf[0][0] = 0;

	mov	eax, DWORD PTR _tf$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	WORD PTR [ecx], 0

; 45   : 	for (i = 1; i < n; i++) {

	mov	DWORD PTR _i$[ebp], 1
	jmp	SHORT $L65942
$L65943:
	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	mov	DWORD PTR _i$[ebp], edx
$L65942:
	mov	eax, DWORD PTR _i$[ebp]
	cmp	eax, DWORD PTR _n$[ebp]
	jge	SHORT $L65944

; 46   : 		double t = (double)i/((double) n-1.);

	fild	DWORD PTR _i$[ebp]
	fild	DWORD PTR _n$[ebp]
	fsub	QWORD PTR __real@8@3fff8000000000000000
	fdivp	ST(1), ST(0)
	fstp	QWORD PTR _t$65945[ebp]

; 47   : 		tf[0][i] = (uint16)floor(65535.*pow(t, 2.2) + .5);

	push	1073846681				; 40019999H
	push	-1717986918				; 9999999aH
	mov	ecx, DWORD PTR _t$65945[ebp+4]
	push	ecx
	mov	edx, DWORD PTR _t$65945[ebp]
	push	edx
	call	_pow
	add	esp, 16					; 00000010H
	fmul	QWORD PTR __real@8@400effff000000000000
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	sub	esp, 8
	fstp	QWORD PTR [esp]
	call	_floor
	add	esp, 8
	call	__ftol
	mov	ecx, DWORD PTR _tf$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	ecx, DWORD PTR _i$[ebp]
	mov	WORD PTR [edx+ecx*2], ax

; 48   : 	}

	jmp	SHORT $L65943
$L65944:

; 49   : 	if (td->td_samplesperpixel - td->td_extrasamples > 1) {

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+54]
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+120]
	sub	eax, edx
	cmp	eax, 1
	jle	SHORT $L65949

; 50   : 		tf[1] = (uint16 *)_TIFFmalloc(n * sizeof (uint16));

	mov	eax, DWORD PTR _n$[ebp]
	shl	eax, 1
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	ecx, DWORD PTR _tf$[ebp]
	mov	DWORD PTR [ecx+4], eax

; 51   : 		_TIFFmemcpy(tf[1], tf[0], n * sizeof (uint16));

	mov	edx, DWORD PTR _n$[ebp]
	shl	edx, 1
	push	edx
	mov	eax, DWORD PTR _tf$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _tf$[ebp]
	mov	eax, DWORD PTR [edx+4]
	push	eax
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH

; 52   : 		tf[2] = (uint16 *)_TIFFmalloc(n * sizeof (uint16));

	mov	ecx, DWORD PTR _n$[ebp]
	shl	ecx, 1
	push	ecx
	call	__TIFFmalloc
	add	esp, 4
	mov	edx, DWORD PTR _tf$[ebp]
	mov	DWORD PTR [edx+8], eax

; 53   : 		_TIFFmemcpy(tf[2], tf[0], n * sizeof (uint16));

	mov	eax, DWORD PTR _n$[ebp]
	shl	eax, 1
	push	eax
	mov	ecx, DWORD PTR _tf$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _tf$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	push	ecx
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH
$L65949:

; 55   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFDefaultTransferFunction ENDP
_td$ = 8
_i$ = -4
_TIFFDefaultRefBlackWhite PROC NEAR

; 59   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 60   : 	int i;
; 61   : 
; 62   : 	td->td_refblackwhite = (float *)_TIFFmalloc(6*sizeof (float));

	push	24					; 00000018H
	call	__TIFFmalloc
	add	esp, 4
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+220], eax

; 63   : 	for (i = 0; i < 3; i++) {

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L65963
$L65964:
	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	mov	DWORD PTR _i$[ebp], edx
$L65963:
	cmp	DWORD PTR _i$[ebp], 3
	jge	SHORT $L65965

; 64   : 	    td->td_refblackwhite[2*i+0] = 0;

	mov	eax, DWORD PTR _i$[ebp]
	shl	eax, 1
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+220]
	mov	DWORD PTR [edx+eax*4], 0

; 65   : 	    td->td_refblackwhite[2*i+1] = (float)((1L<<td->td_bitspersample)-1L);

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+40]
	mov	edx, 1
	shl	edx, cl
	sub	edx, 1
	mov	DWORD PTR -8+[ebp], edx
	fild	DWORD PTR -8+[ebp]
	mov	eax, DWORD PTR _i$[ebp]
	shl	eax, 1
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+220]
	fstp	DWORD PTR [edx+eax*4+4]

; 66   : 	}

	jmp	SHORT $L65964
$L65965:

; 67   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFDefaultRefBlackWhite ENDP
_TEXT	ENDS
PUBLIC	_TIFFGetFieldDefaulted
_TEXT	SEGMENT
_tif$ = 8
_tag$ = 12
_ok$ = -8
_ap$ = -4
_TIFFGetFieldDefaulted PROC NEAR

; 198  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 199  : 	int ok;
; 200  : 	va_list ap;
; 201  : 
; 202  : 	va_start(ap, tag);

	lea	eax, DWORD PTR _tag$[ebp+4]
	mov	DWORD PTR _ap$[ebp], eax

; 203  : 	ok =  TIFFVGetFieldDefaulted(tif, tag, ap);

	mov	ecx, DWORD PTR _ap$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tag$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFVGetFieldDefaulted
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _ok$[ebp], eax

; 204  : 	va_end(ap);

	mov	DWORD PTR _ap$[ebp], 0

; 205  : 	return (ok);

	mov	eax, DWORD PTR _ok$[ebp]

; 206  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFGetFieldDefaulted ENDP
_TEXT	ENDS
END
