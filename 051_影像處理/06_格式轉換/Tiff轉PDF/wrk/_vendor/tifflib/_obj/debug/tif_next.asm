	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_next.c
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
PUBLIC	_TIFFInitNeXT
_TEXT	SEGMENT
_tif$ = 8
_TIFFInitNeXT PROC NEAR

; 135  : {

	push	ebp
	mov	ebp, esp

; 136  : 	(void) scheme;
; 137  : 	tif->tif_decoderow = NeXTDecode;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+416], OFFSET FLAT:_NeXTDecode

; 138  : 	tif->tif_decodestrip = NeXTDecode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+424], OFFSET FLAT:_NeXTDecode

; 139  : 	tif->tif_decodetile = NeXTDecode;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+432], OFFSET FLAT:_NeXTDecode

; 140  : 	return (1);

	mov	eax, 1

; 141  : }

	pop	ebp
	ret	0
_TIFFInitNeXT ENDP
_TEXT	ENDS
EXTRN	__TIFFmemcpy:NEAR
EXTRN	_TIFFError:NEAR
_DATA	SEGMENT
$SG65845 DB	'NeXTDecode: Not enough data for scanline %ld', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_buf$ = 12
_occ$ = 16
_bp$ = -24
_op$ = -8
_cc$ = -12
_n$ = -20
_row$ = -4
_scanline$ = -16
_off$65820 = -28
_npixels$65823 = -32
_grey$65824 = -36
_imagewidth$65825 = -40
_NeXTDecode PROC NEAR

; 50   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 52					; 00000034H

; 51   : 	register u_char *bp, *op;
; 52   : 	register tsize_t cc;
; 53   : 	register int n;
; 54   : 	tidata_t row;
; 55   : 	tsize_t scanline;
; 56   : 
; 57   : 	(void) s;
; 58   : 	/*
; 59   : 	 * Each scanline is assumed to start off as all
; 60   : 	 * white (we assume a PhotometricInterpretation
; 61   : 	 * of ``min-is-black'').
; 62   : 	 */
; 63   : 	for (op = buf, cc = occ; cc-- > 0;)

	mov	eax, DWORD PTR _buf$[ebp]
	mov	DWORD PTR _op$[ebp], eax
	mov	ecx, DWORD PTR _occ$[ebp]
	mov	DWORD PTR _cc$[ebp], ecx
$L65805:
	mov	edx, DWORD PTR _cc$[ebp]
	mov	eax, DWORD PTR _cc$[ebp]
	sub	eax, 1
	mov	DWORD PTR _cc$[ebp], eax
	test	edx, edx
	jle	SHORT $L65806

; 64   : 		*op++ = 0xff;

	mov	ecx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [ecx], 255			; 000000ffH
	mov	edx, DWORD PTR _op$[ebp]
	add	edx, 1
	mov	DWORD PTR _op$[ebp], edx
	jmp	SHORT $L65805
$L65806:

; 65   : 
; 66   : 	bp = (u_char *)tif->tif_rawcp;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	DWORD PTR _bp$[ebp], ecx

; 67   : 	cc = tif->tif_rawcc;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+484]
	mov	DWORD PTR _cc$[ebp], eax

; 68   : 	scanline = tif->tif_scanlinesize;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+464]
	mov	DWORD PTR _scanline$[ebp], edx

; 69   : 	for (row = buf; (long)occ > 0; occ -= scanline, row += scanline) {

	mov	eax, DWORD PTR _buf$[ebp]
	mov	DWORD PTR _row$[ebp], eax
	jmp	SHORT $L65809
$L65810:
	mov	ecx, DWORD PTR _occ$[ebp]
	sub	ecx, DWORD PTR _scanline$[ebp]
	mov	DWORD PTR _occ$[ebp], ecx
	mov	edx, DWORD PTR _row$[ebp]
	add	edx, DWORD PTR _scanline$[ebp]
	mov	DWORD PTR _row$[ebp], edx
$L65809:
	cmp	DWORD PTR _occ$[ebp], 0
	jle	$L65811

; 70   : 		n = *bp++, cc--;

	mov	eax, DWORD PTR _bp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	DWORD PTR _n$[ebp], ecx
	mov	edx, DWORD PTR _bp$[ebp]
	add	edx, 1
	mov	DWORD PTR _bp$[ebp], edx
	mov	eax, DWORD PTR _cc$[ebp]
	sub	eax, 1
	mov	DWORD PTR _cc$[ebp], eax

; 71   : 		switch (n) {

	mov	ecx, DWORD PTR _n$[ebp]
	mov	DWORD PTR -44+[ebp], ecx
	cmp	DWORD PTR -44+[ebp], 0
	je	SHORT $L65816
	cmp	DWORD PTR -44+[ebp], 64			; 00000040H
	je	SHORT $L65819
	jmp	$L65822
$L65816:

; 72   : 		case LITERALROW:
; 73   : 			/*
; 74   : 			 * The entire scanline is given as literal values.
; 75   : 			 */
; 76   : 			if (cc < scanline)

	mov	edx, DWORD PTR _cc$[ebp]
	cmp	edx, DWORD PTR _scanline$[ebp]
	jge	SHORT $L65817

; 77   : 				goto bad;

	jmp	$bad$65818
$L65817:

; 78   : 			_TIFFmemcpy(row, bp, scanline);

	mov	eax, DWORD PTR _scanline$[ebp]
	push	eax
	mov	ecx, DWORD PTR _bp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _row$[ebp]
	push	edx
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH

; 79   : 			bp += scanline;

	mov	eax, DWORD PTR _bp$[ebp]
	add	eax, DWORD PTR _scanline$[ebp]
	mov	DWORD PTR _bp$[ebp], eax

; 80   : 			cc -= scanline;

	mov	ecx, DWORD PTR _cc$[ebp]
	sub	ecx, DWORD PTR _scanline$[ebp]
	mov	DWORD PTR _cc$[ebp], ecx

; 81   : 			break;

	jmp	$L65813
$L65819:

; 83   : 			int off;
; 84   : 			/*
; 85   : 			 * The scanline has a literal span
; 86   : 			 * that begins at some offset.
; 87   : 			 */
; 88   : 			off = (bp[0] * 256) + bp[1];

	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	shl	eax, 8
	mov	ecx, DWORD PTR _bp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	add	eax, edx
	mov	DWORD PTR _off$65820[ebp], eax

; 89   : 			n = (bp[2] * 256) + bp[3];

	mov	eax, DWORD PTR _bp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+2]
	shl	ecx, 8
	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+3]
	add	ecx, eax
	mov	DWORD PTR _n$[ebp], ecx

; 90   : 			if (cc < 4+n)

	mov	ecx, DWORD PTR _n$[ebp]
	add	ecx, 4
	cmp	DWORD PTR _cc$[ebp], ecx
	jge	SHORT $L65821

; 91   : 				goto bad;

	jmp	$bad$65818
$L65821:

; 92   : 			_TIFFmemcpy(row+off, bp+4, n);

	mov	edx, DWORD PTR _n$[ebp]
	push	edx
	mov	eax, DWORD PTR _bp$[ebp]
	add	eax, 4
	push	eax
	mov	ecx, DWORD PTR _row$[ebp]
	add	ecx, DWORD PTR _off$65820[ebp]
	push	ecx
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH

; 93   : 			bp += 4+n;

	mov	edx, DWORD PTR _n$[ebp]
	mov	eax, DWORD PTR _bp$[ebp]
	lea	ecx, DWORD PTR [eax+edx+4]
	mov	DWORD PTR _bp$[ebp], ecx

; 94   : 			cc -= 4+n;

	mov	edx, DWORD PTR _n$[ebp]
	add	edx, 4
	mov	eax, DWORD PTR _cc$[ebp]
	sub	eax, edx
	mov	DWORD PTR _cc$[ebp], eax

; 95   : 			break;

	jmp	$L65813
$L65822:

; 98   : 			register int npixels = 0, grey;

	mov	DWORD PTR _npixels$65823[ebp], 0

; 99   : 			u_long imagewidth = tif->tif_dir.td_imagewidth;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+36]
	mov	DWORD PTR _imagewidth$65825[ebp], edx

; 100  : 
; 101  : 			/*
; 102  : 			 * The scanline is composed of a sequence
; 103  : 			 * of constant color ``runs''.  We shift
; 104  : 			 * into ``run mode'' and interpret bytes
; 105  : 			 * as codes of the form <color><npixels>
; 106  : 			 * until we've filled the scanline.
; 107  : 			 */
; 108  : 			op = row;

	mov	eax, DWORD PTR _row$[ebp]
	mov	DWORD PTR _op$[ebp], eax
$L65827:

; 110  : 				grey = (n>>6) & 0x3;

	mov	ecx, DWORD PTR _n$[ebp]
	sar	ecx, 6
	and	ecx, 3
	mov	DWORD PTR _grey$65824[ebp], ecx

; 111  : 				n &= 0x3f;

	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 63					; 0000003fH
	mov	DWORD PTR _n$[ebp], edx
$L65830:

; 112  : 				while (n-- > 0)

	mov	eax, DWORD PTR _n$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	test	eax, eax
	jle	SHORT $L65831

; 113  : 					SETPIXEL(op, grey);

	mov	edx, DWORD PTR _npixels$65823[ebp]
	and	edx, 3
	mov	DWORD PTR -48+[ebp], edx
	mov	eax, DWORD PTR _npixels$65823[ebp]
	add	eax, 1
	mov	DWORD PTR _npixels$65823[ebp], eax
	mov	ecx, DWORD PTR -48+[ebp]
	mov	DWORD PTR -52+[ebp], ecx
	cmp	DWORD PTR -52+[ebp], 3
	ja	SHORT $L65833
	mov	edx, DWORD PTR -52+[ebp]
	jmp	DWORD PTR $L65856[edx*4]
$L65836:
	mov	eax, DWORD PTR _grey$65824[ebp]
	shl	eax, 6
	mov	ecx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [ecx], al
	jmp	SHORT $L65833
$L65837:
	mov	edx, DWORD PTR _grey$65824[ebp]
	shl	edx, 4
	mov	eax, DWORD PTR _op$[ebp]
	mov	cl, BYTE PTR [eax]
	or	cl, dl
	mov	edx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [edx], cl
	jmp	SHORT $L65833
$L65838:
	mov	eax, DWORD PTR _grey$65824[ebp]
	shl	eax, 2
	mov	ecx, DWORD PTR _op$[ebp]
	mov	dl, BYTE PTR [ecx]
	or	dl, al
	mov	eax, DWORD PTR _op$[ebp]
	mov	BYTE PTR [eax], dl
	jmp	SHORT $L65833
$L65839:
	mov	ecx, DWORD PTR _op$[ebp]
	mov	dl, BYTE PTR [ecx]
	or	dl, BYTE PTR _grey$65824[ebp]
	mov	eax, DWORD PTR _op$[ebp]
	mov	BYTE PTR [eax], dl
	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, 1
	mov	DWORD PTR _op$[ebp], ecx
$L65833:
	jmp	$L65830
$L65831:

; 114  : 				if (npixels >= (int) imagewidth)

	mov	edx, DWORD PTR _npixels$65823[ebp]
	cmp	edx, DWORD PTR _imagewidth$65825[ebp]
	jl	SHORT $L65841

; 115  : 					break;

	jmp	SHORT $L65828
$L65841:

; 116  : 				if (cc == 0)

	cmp	DWORD PTR _cc$[ebp], 0
	jne	SHORT $L65842

; 117  : 					goto bad;

	jmp	SHORT $bad$65818
$L65842:

; 118  : 				n = *bp++, cc--;

	mov	eax, DWORD PTR _bp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	DWORD PTR _n$[ebp], ecx
	mov	edx, DWORD PTR _bp$[ebp]
	add	edx, 1
	mov	DWORD PTR _bp$[ebp], edx
	mov	eax, DWORD PTR _cc$[ebp]
	sub	eax, 1
	mov	DWORD PTR _cc$[ebp], eax

; 119  : 			}

	jmp	$L65827
$L65828:
$L65813:

; 123  : 	}

	jmp	$L65810
$L65811:

; 124  : 	tif->tif_rawcp = (tidata_t) bp;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _bp$[ebp]
	mov	DWORD PTR [ecx+480], edx

; 125  : 	tif->tif_rawcc = cc;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _cc$[ebp]
	mov	DWORD PTR [eax+484], ecx

; 126  : 	return (1);

	mov	eax, 1
	jmp	SHORT $L65796
$bad$65818:

; 127  : bad:
; 128  : 	TIFFError(tif->tif_name, "NeXTDecode: Not enough data for scanline %ld",
; 129  : 	    (long) tif->tif_row);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+356]
	push	eax
	push	OFFSET FLAT:$SG65845
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 130  : 	return (0);

	xor	eax, eax
$L65796:

; 131  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L65856:
	DD	$L65836
	DD	$L65837
	DD	$L65838
	DD	$L65839
_NeXTDecode ENDP
_TEXT	ENDS
END
