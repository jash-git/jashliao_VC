	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_tile.c
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
PUBLIC	_TIFFComputeTile
_TEXT	SEGMENT
_tif$ = 8
_x$ = 12
_y$ = 16
_z$ = 20
_s$ = 24
_td$ = -8
_dx$ = -16
_dy$ = -20
_dz$ = -4
_tile$ = -12
_xpt$65807 = -32
_ypt$65811 = -28
_zpt$65815 = -24
_TIFFComputeTile PROC NEAR

; 39   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 32					; 00000020H
	push	esi

; 40   : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 41   : 	uint32 dx = td->td_tilewidth;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	mov	DWORD PTR _dx$[ebp], edx

; 42   : 	uint32 dy = td->td_tilelength;

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	mov	DWORD PTR _dy$[ebp], ecx

; 43   : 	uint32 dz = td->td_tiledepth;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+32]
	mov	DWORD PTR _dz$[ebp], eax

; 44   : 	ttile_t tile = 1;

	mov	DWORD PTR _tile$[ebp], 1

; 45   : 
; 46   : 	if (td->td_imagedepth == 1)

	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+20], 1
	jne	SHORT $L65799

; 47   : 		z = 0;

	mov	DWORD PTR _z$[ebp], 0
$L65799:

; 48   : 	if (dx == (uint32) -1)

	cmp	DWORD PTR _dx$[ebp], -1
	jne	SHORT $L65801

; 49   : 		dx = td->td_imagewidth;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR _dx$[ebp], eax
$L65801:

; 50   : 	if (dy == (uint32) -1)

	cmp	DWORD PTR _dy$[ebp], -1
	jne	SHORT $L65803

; 51   : 		dy = td->td_imagelength;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	mov	DWORD PTR _dy$[ebp], edx
$L65803:

; 52   : 	if (dz == (uint32) -1)

	cmp	DWORD PTR _dz$[ebp], -1
	jne	SHORT $L65805

; 53   : 		dz = td->td_imagedepth;

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+20]
	mov	DWORD PTR _dz$[ebp], ecx
$L65805:

; 54   : 	if (dx != 0 && dy != 0 && dz != 0) {

	cmp	DWORD PTR _dx$[ebp], 0
	je	$L65820
	cmp	DWORD PTR _dy$[ebp], 0
	je	$L65820
	cmp	DWORD PTR _dz$[ebp], 0
	je	$L65820

; 55   : 		uint32 xpt = TIFFhowmany(td->td_imagewidth, dx); 

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	ecx, DWORD PTR _dx$[ebp]
	lea	eax, DWORD PTR [eax+ecx-1]
	xor	edx, edx
	div	DWORD PTR _dx$[ebp]
	mov	DWORD PTR _xpt$65807[ebp], eax

; 56   : 		uint32 ypt = TIFFhowmany(td->td_imagelength, dy); 

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+16]
	mov	ecx, DWORD PTR _dy$[ebp]
	lea	eax, DWORD PTR [eax+ecx-1]
	xor	edx, edx
	div	DWORD PTR _dy$[ebp]
	mov	DWORD PTR _ypt$65811[ebp], eax

; 57   : 		uint32 zpt = TIFFhowmany(td->td_imagedepth, dz); 

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+20]
	mov	ecx, DWORD PTR _dz$[ebp]
	lea	eax, DWORD PTR [eax+ecx-1]
	xor	edx, edx
	div	DWORD PTR _dz$[ebp]
	mov	DWORD PTR _zpt$65815[ebp], eax

; 58   : 
; 59   : 		if (td->td_planarconfig == PLANARCONFIG_SEPARATE) 

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+90]
	cmp	eax, 2
	jne	SHORT $L65819

; 60   : 			tile = (xpt*ypt*zpt)*s +
; 61   : 			     (xpt*ypt)*(z/dz) +
; 62   : 			     xpt*(y/dy) +
; 63   : 			     x/dx;

	mov	ecx, DWORD PTR _xpt$65807[ebp]
	imul	ecx, DWORD PTR _ypt$65811[ebp]
	imul	ecx, DWORD PTR _zpt$65815[ebp]
	mov	edx, DWORD PTR _s$[ebp]
	and	edx, 65535				; 0000ffffH
	imul	ecx, edx
	mov	esi, DWORD PTR _xpt$65807[ebp]
	imul	esi, DWORD PTR _ypt$65811[ebp]
	mov	eax, DWORD PTR _z$[ebp]
	xor	edx, edx
	div	DWORD PTR _dz$[ebp]
	imul	esi, eax
	add	ecx, esi
	mov	eax, DWORD PTR _y$[ebp]
	xor	edx, edx
	div	DWORD PTR _dy$[ebp]
	mov	edx, DWORD PTR _xpt$65807[ebp]
	imul	edx, eax
	add	ecx, edx
	mov	eax, DWORD PTR _x$[ebp]
	xor	edx, edx
	div	DWORD PTR _dx$[ebp]
	add	ecx, eax
	mov	DWORD PTR _tile$[ebp], ecx

; 64   : 		else

	jmp	SHORT $L65820
$L65819:

; 65   : 			tile = (xpt*ypt)*(z/dz) + xpt*(y/dy) + x/dx + s;

	mov	ecx, DWORD PTR _xpt$65807[ebp]
	imul	ecx, DWORD PTR _ypt$65811[ebp]
	mov	eax, DWORD PTR _z$[ebp]
	xor	edx, edx
	div	DWORD PTR _dz$[ebp]
	imul	ecx, eax
	mov	eax, DWORD PTR _y$[ebp]
	xor	edx, edx
	div	DWORD PTR _dy$[ebp]
	mov	edx, DWORD PTR _xpt$65807[ebp]
	imul	edx, eax
	add	ecx, edx
	mov	eax, DWORD PTR _x$[ebp]
	xor	edx, edx
	div	DWORD PTR _dx$[ebp]
	add	ecx, eax
	mov	eax, DWORD PTR _s$[ebp]
	and	eax, 65535				; 0000ffffH
	add	ecx, eax
	mov	DWORD PTR _tile$[ebp], ecx
$L65820:

; 67   : 	return (tile);

	mov	eax, DWORD PTR _tile$[ebp]

; 68   : }

	pop	esi
	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFComputeTile ENDP
_TEXT	ENDS
PUBLIC	_TIFFCheckTile
EXTRN	_TIFFError:NEAR
_DATA	SEGMENT
$SG65836 DB	'Col %ld out of range, max %lu', 00H
	ORG $+2
$SG65840 DB	'Row %ld out of range, max %lu', 00H
	ORG $+2
$SG65844 DB	'Depth %ld out of range, max %lu', 00H
$SG65847 DB	'Sample %d out of range, max %u', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_x$ = 12
_y$ = 16
_z$ = 20
_s$ = 24
_td$ = -4
_TIFFCheckTile PROC NEAR

; 76   : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 77   : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 78   : 
; 79   : 	if (x >= td->td_imagewidth) {

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _x$[ebp]
	cmp	edx, DWORD PTR [ecx+12]
	jb	SHORT $L65833

; 80   : 		TIFFError(tif->tif_name, "Col %ld out of range, max %lu",
; 81   : 		    (long) x, (u_long) td->td_imagewidth);

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	push	ecx
	mov	edx, DWORD PTR _x$[ebp]
	push	edx
	push	OFFSET FLAT:$SG65836
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 16					; 00000010H

; 82   : 		return (0);

	xor	eax, eax
	jmp	$L65831
$L65833:

; 84   : 	if (y >= td->td_imagelength) {

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _y$[ebp]
	cmp	eax, DWORD PTR [edx+16]
	jb	SHORT $L65837

; 85   : 		TIFFError(tif->tif_name, "Row %ld out of range, max %lu",
; 86   : 		    (long) y, (u_long) td->td_imagelength);

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	mov	eax, DWORD PTR _y$[ebp]
	push	eax
	push	OFFSET FLAT:$SG65840
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 16					; 00000010H

; 87   : 		return (0);

	xor	eax, eax
	jmp	$L65831
$L65837:

; 89   : 	if (z >= td->td_imagedepth) {

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _z$[ebp]
	cmp	ecx, DWORD PTR [eax+20]
	jb	SHORT $L65841

; 90   : 		TIFFError(tif->tif_name, "Depth %ld out of range, max %lu",
; 91   : 		    (long) z, (u_long) td->td_imagedepth);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+20]
	push	eax
	mov	ecx, DWORD PTR _z$[ebp]
	push	ecx
	push	OFFSET FLAT:$SG65844
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 16					; 00000010H

; 92   : 		return (0);

	xor	eax, eax
	jmp	SHORT $L65831
$L65841:

; 94   : 	if (td->td_planarconfig == PLANARCONFIG_SEPARATE &&
; 95   : 	    s >= td->td_samplesperpixel) {

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+90]
	cmp	edx, 2
	jne	SHORT $L65845
	mov	eax, DWORD PTR _s$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+54]
	cmp	eax, edx
	jl	SHORT $L65845

; 96   : 		TIFFError(tif->tif_name, "Sample %d out of range, max %u",
; 97   : 		    (int) s, td->td_samplesperpixel);

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+54]
	push	ecx
	mov	edx, DWORD PTR _s$[ebp]
	and	edx, 65535				; 0000ffffH
	push	edx
	push	OFFSET FLAT:$SG65847
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 16					; 00000010H

; 98   : 		return (0);

	xor	eax, eax
	jmp	SHORT $L65831
$L65845:

; 100  : 	return (1);

	mov	eax, 1
$L65831:

; 101  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFCheckTile ENDP
_TEXT	ENDS
PUBLIC	_TIFFNumberOfTiles
_TEXT	SEGMENT
_tif$ = 8
_td$ = -12
_dx$ = -16
_dy$ = -20
_dz$ = -4
_ntiles$ = -8
_TIFFNumberOfTiles PROC NEAR

; 108  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 24					; 00000018H

; 109  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 110  : 	uint32 dx = td->td_tilewidth;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	mov	DWORD PTR _dx$[ebp], edx

; 111  : 	uint32 dy = td->td_tilelength;

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	mov	DWORD PTR _dy$[ebp], ecx

; 112  : 	uint32 dz = td->td_tiledepth;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+32]
	mov	DWORD PTR _dz$[ebp], eax

; 113  : 	ttile_t ntiles;
; 114  : 
; 115  : 	if (dx == (uint32) -1)

	cmp	DWORD PTR _dx$[ebp], -1
	jne	SHORT $L65857

; 116  : 		dx = td->td_imagewidth;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR _dx$[ebp], edx
$L65857:

; 117  : 	if (dy == (uint32) -1)

	cmp	DWORD PTR _dy$[ebp], -1
	jne	SHORT $L65859

; 118  : 		dy = td->td_imagelength;

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	mov	DWORD PTR _dy$[ebp], ecx
$L65859:

; 119  : 	if (dz == (uint32) -1)

	cmp	DWORD PTR _dz$[ebp], -1
	jne	SHORT $L65861

; 120  : 		dz = td->td_imagedepth;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+20]
	mov	DWORD PTR _dz$[ebp], eax
$L65861:

; 121  : 	ntiles = (dx == 0 || dy == 0 || dz == 0) ? 0 :
; 122  : 	    (TIFFhowmany(td->td_imagewidth, dx) *
; 123  : 	     TIFFhowmany(td->td_imagelength, dy) *
; 124  : 	     TIFFhowmany(td->td_imagedepth, dz));

	cmp	DWORD PTR _dx$[ebp], 0
	je	SHORT $L65949
	cmp	DWORD PTR _dy$[ebp], 0
	je	SHORT $L65949
	cmp	DWORD PTR _dz$[ebp], 0
	je	SHORT $L65949
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	eax, DWORD PTR _dx$[ebp]
	lea	eax, DWORD PTR [edx+eax-1]
	xor	edx, edx
	div	DWORD PTR _dx$[ebp]
	mov	ecx, eax
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+16]
	mov	edx, DWORD PTR _dy$[ebp]
	lea	eax, DWORD PTR [eax+edx-1]
	xor	edx, edx
	div	DWORD PTR _dy$[ebp]
	imul	ecx, eax
	mov	eax, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [eax+20]
	mov	eax, DWORD PTR _dz$[ebp]
	lea	eax, DWORD PTR [edx+eax-1]
	xor	edx, edx
	div	DWORD PTR _dz$[ebp]
	imul	ecx, eax
	mov	DWORD PTR -24+[ebp], ecx
	jmp	SHORT $L65950
$L65949:
	mov	DWORD PTR -24+[ebp], 0
$L65950:
	mov	ecx, DWORD PTR -24+[ebp]
	mov	DWORD PTR _ntiles$[ebp], ecx

; 125  : 	if (td->td_planarconfig == PLANARCONFIG_SEPARATE)

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+90]
	cmp	eax, 2
	jne	SHORT $L65871

; 126  : 		ntiles *= td->td_samplesperpixel;

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+54]
	mov	eax, DWORD PTR _ntiles$[ebp]
	imul	eax, edx
	mov	DWORD PTR _ntiles$[ebp], eax
$L65871:

; 127  : 	return (ntiles);

	mov	eax, DWORD PTR _ntiles$[ebp]

; 128  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFNumberOfTiles ENDP
_TEXT	ENDS
PUBLIC	_TIFFTileRowSize
_TEXT	SEGMENT
_tif$ = 8
_td$ = -8
_rowsize$ = -4
_TIFFTileRowSize PROC NEAR

; 135  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 136  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 137  : 	tsize_t rowsize;
; 138  : 	
; 139  : 	if (td->td_tilelength == 0 || td->td_tilewidth == 0)

	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+28], 0
	je	SHORT $L65878
	mov	edx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [edx+24], 0
	jne	SHORT $L65877
$L65878:

; 140  : 		return ((tsize_t) 0);

	xor	eax, eax
	jmp	SHORT $L65874
$L65877:

; 141  : 	rowsize = td->td_bitspersample * td->td_tilewidth;

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+40]
	mov	edx, DWORD PTR _td$[ebp]
	imul	ecx, DWORD PTR [edx+24]
	mov	DWORD PTR _rowsize$[ebp], ecx

; 142  : 	if (td->td_planarconfig == PLANARCONFIG_CONTIG)

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+90]
	cmp	ecx, 1
	jne	SHORT $L65880

; 143  : 		rowsize *= td->td_samplesperpixel;

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+54]
	mov	ecx, DWORD PTR _rowsize$[ebp]
	imul	ecx, eax
	mov	DWORD PTR _rowsize$[ebp], ecx
$L65880:

; 144  : 	return ((tsize_t) TIFFhowmany(rowsize, 8));

	mov	eax, DWORD PTR _rowsize$[ebp]
	add	eax, 7
	shr	eax, 3
$L65874:

; 145  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFTileRowSize ENDP
_TEXT	ENDS
PUBLIC	_TIFFVTileSize
_TEXT	SEGMENT
_tif$ = 8
_nrows$ = 12
_td$ = -8
_tilesize$ = -4
_w$65896 = -16
_rowsize$65901 = -12
_samplingarea$65905 = -20
_TIFFVTileSize PROC NEAR

; 152  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 20					; 00000014H

; 153  : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 154  : 	tsize_t tilesize;
; 155  : 
; 156  : 	if (td->td_tilelength == 0 || td->td_tilewidth == 0 ||
; 157  : 	    td->td_tiledepth == 0)

	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+28], 0
	je	SHORT $L65893
	mov	edx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [edx+24], 0
	je	SHORT $L65893
	mov	eax, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [eax+32], 0
	jne	SHORT $L65892
$L65893:

; 158  : 		return ((tsize_t) 0);

	xor	eax, eax
	jmp	$L65889
$L65892:

; 159  : #ifdef YCBCR_SUPPORT
; 160  : 	if (td->td_planarconfig == PLANARCONFIG_CONTIG &&
; 161  : 	    td->td_photometric == PHOTOMETRIC_YCBCR &&
; 162  : 	    !isUpSampled(tif)) {

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+90]
	cmp	edx, 1
	jne	$L65895
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+46]
	cmp	ecx, 6
	jne	$L65895
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 16384				; 00004000H
	test	eax, eax
	jne	$L65895

; 163  : 		/*
; 164  : 		 * Packed YCbCr data contain one Cb+Cr for every
; 165  : 		 * HorizontalSampling*VerticalSampling Y values.
; 166  : 		 * Must also roundup width and height when calculating
; 167  : 		 * since images that are not a multiple of the
; 168  : 		 * horizontal/vertical subsampling area include
; 169  : 		 * YCbCr data for the extended image.
; 170  : 		 */
; 171  : 		tsize_t w =
; 172  : 		    TIFFroundup(td->td_tilewidth, td->td_ycbcrsubsampling[0]);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+204]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	lea	eax, DWORD PTR [ecx+edx-1]
	mov	edx, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+204]
	xor	edx, edx
	div	ecx
	mov	edx, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+204]
	imul	eax, ecx
	mov	DWORD PTR _w$65896[ebp], eax

; 173  : 		tsize_t rowsize = TIFFhowmany(w*td->td_bitspersample, 8);

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+40]
	mov	ecx, DWORD PTR _w$65896[ebp]
	imul	ecx, eax
	add	ecx, 7
	shr	ecx, 3
	mov	DWORD PTR _rowsize$65901[ebp], ecx

; 174  : 		tsize_t samplingarea =
; 175  : 		    td->td_ycbcrsubsampling[0]*td->td_ycbcrsubsampling[1];

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+204]
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+206]
	imul	eax, edx
	mov	DWORD PTR _samplingarea$65905[ebp], eax

; 176  : 		nrows = TIFFroundup(nrows, td->td_ycbcrsubsampling[1]);

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+206]
	mov	edx, DWORD PTR _nrows$[ebp]
	lea	eax, DWORD PTR [edx+ecx-1]
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+206]
	mov	ecx, edx
	xor	edx, edx
	div	ecx
	mov	edx, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+206]
	imul	eax, ecx
	mov	DWORD PTR _nrows$[ebp], eax

; 177  : 		/* NB: don't need TIFFhowmany here 'cuz everything is rounded */
; 178  : 		tilesize = nrows*rowsize + 2*(nrows*rowsize / samplingarea);

	mov	ecx, DWORD PTR _nrows$[ebp]
	imul	ecx, DWORD PTR _rowsize$65901[ebp]
	mov	eax, DWORD PTR _nrows$[ebp]
	imul	eax, DWORD PTR _rowsize$65901[ebp]
	xor	edx, edx
	div	DWORD PTR _samplingarea$65905[ebp]
	lea	edx, DWORD PTR [ecx+eax*2]
	mov	DWORD PTR _tilesize$[ebp], edx

; 179  : 	} else

	jmp	SHORT $L65910
$L65895:

; 180  : #endif
; 181  : 		tilesize = nrows * TIFFTileRowSize(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFTileRowSize
	add	esp, 4
	mov	ecx, DWORD PTR _nrows$[ebp]
	imul	ecx, eax
	mov	DWORD PTR _tilesize$[ebp], ecx
$L65910:

; 182  : 	return ((tsize_t)(tilesize * td->td_tiledepth));

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _tilesize$[ebp]
	imul	eax, DWORD PTR [edx+32]
$L65889:

; 183  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFVTileSize ENDP
_TEXT	ENDS
PUBLIC	_TIFFTileSize
_TEXT	SEGMENT
_tif$ = 8
_TIFFTileSize PROC NEAR

; 190  : {

	push	ebp
	mov	ebp, esp

; 191  : 	return (TIFFVTileSize(tif, tif->tif_dir.td_tilelength));

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+52]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFVTileSize
	add	esp, 8

; 192  : }

	pop	ebp
	ret	0
_TIFFTileSize ENDP
_TEXT	ENDS
PUBLIC	_TIFFDefaultTileSize
_TEXT	SEGMENT
_tif$ = 8
_tw$ = 12
_th$ = 16
_TIFFDefaultTileSize PROC NEAR

; 202  : {

	push	ebp
	mov	ebp, esp

; 203  : 	(*tif->tif_deftilesize)(tif, tw, th);

	mov	eax, DWORD PTR _th$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tw$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+456]
	add	esp, 12					; 0000000cH

; 204  : }

	pop	ebp
	ret	0
_TIFFDefaultTileSize ENDP
_TEXT	ENDS
PUBLIC	__TIFFDefaultTileSize
_TEXT	SEGMENT
_tw$ = 12
_th$ = 16
__TIFFDefaultTileSize PROC NEAR

; 208  : {

	push	ebp
	mov	ebp, esp

; 209  : 	(void) tif;
; 210  : 	if (*(int32*) tw < 1)

	mov	eax, DWORD PTR _tw$[ebp]
	cmp	DWORD PTR [eax], 1
	jge	SHORT $L65931

; 211  : 		*tw = 256;

	mov	ecx, DWORD PTR _tw$[ebp]
	mov	DWORD PTR [ecx], 256			; 00000100H
$L65931:

; 212  : 	if (*(int32*) th < 1)

	mov	edx, DWORD PTR _th$[ebp]
	cmp	DWORD PTR [edx], 1
	jge	SHORT $L65933

; 213  : 		*th = 256;

	mov	eax, DWORD PTR _th$[ebp]
	mov	DWORD PTR [eax], 256			; 00000100H
$L65933:

; 214  : 	/* roundup to a multiple of 16 per the spec */
; 215  : 	if (*tw & 0xf)

	mov	ecx, DWORD PTR _tw$[ebp]
	mov	edx, DWORD PTR [ecx]
	and	edx, 15					; 0000000fH
	test	edx, edx
	je	SHORT $L65934

; 216  : 		*tw = TIFFroundup(*tw, 16);

	mov	eax, DWORD PTR _tw$[ebp]
	mov	ecx, DWORD PTR [eax]
	add	ecx, 15					; 0000000fH
	shr	ecx, 4
	shl	ecx, 4
	mov	edx, DWORD PTR _tw$[ebp]
	mov	DWORD PTR [edx], ecx
$L65934:

; 217  : 	if (*th & 0xf)

	mov	eax, DWORD PTR _th$[ebp]
	mov	ecx, DWORD PTR [eax]
	and	ecx, 15					; 0000000fH
	test	ecx, ecx
	je	SHORT $L65939

; 218  : 		*th = TIFFroundup(*th, 16);

	mov	edx, DWORD PTR _th$[ebp]
	mov	eax, DWORD PTR [edx]
	add	eax, 15					; 0000000fH
	shr	eax, 4
	shl	eax, 4
	mov	ecx, DWORD PTR _th$[ebp]
	mov	DWORD PTR [ecx], eax
$L65939:

; 219  : }

	pop	ebp
	ret	0
__TIFFDefaultTileSize ENDP
_TEXT	ENDS
END
