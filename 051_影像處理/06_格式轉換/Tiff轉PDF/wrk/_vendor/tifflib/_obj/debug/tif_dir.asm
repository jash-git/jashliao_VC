	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_dir.c
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
__TIFFextender DD 01H DUP (?)
_?tagcount@?1??TIFFReassignTagToIgnore@@9@9 DD 01H DUP (?)
_BSS	ENDS
CONST	SEGMENT
_?module@?1??TIFFAdvanceDirectory@@9@9 DB 'TIFFAdvanceDirectory', 00H
	ORG $+3
_?module@?1??TIFFUnlinkDirectory@@9@9 DB 'TIFFUnlinkDirectory', 00H
CONST	ENDS
PUBLIC	__TIFFsetByteArray
EXTRN	__TIFFmalloc:NEAR
EXTRN	__TIFFmemcpy:NEAR
EXTRN	__TIFFfree:NEAR
_TEXT	SEGMENT
_vpp$ = 8
_vp$ = 12
_n$ = 16
__TIFFsetByteArray PROC NEAR

; 45   : {

	push	ebp
	mov	ebp, esp

; 46   : 	if (*vpp)

	mov	eax, DWORD PTR _vpp$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L65794

; 47   : 		_TIFFfree(*vpp), *vpp = 0;

	mov	ecx, DWORD PTR _vpp$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	__TIFFfree
	add	esp, 4
	mov	eax, DWORD PTR _vpp$[ebp]
	mov	DWORD PTR [eax], 0
$L65794:

; 48   : 	if (vp && (*vpp = (void*) _TIFFmalloc(n)))

	cmp	DWORD PTR _vp$[ebp], 0
	je	SHORT $L65796
	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	call	__TIFFmalloc
	add	esp, 4
	mov	edx, DWORD PTR _vpp$[ebp]
	mov	DWORD PTR [edx], eax
	mov	eax, DWORD PTR _vpp$[ebp]
	cmp	DWORD PTR [eax], 0
	je	SHORT $L65796

; 49   : 		_TIFFmemcpy(*vpp, vp, n);

	mov	ecx, DWORD PTR _n$[ebp]
	push	ecx
	mov	edx, DWORD PTR _vp$[ebp]
	push	edx
	mov	eax, DWORD PTR _vpp$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH
$L65796:

; 50   : }

	pop	ebp
	ret	0
__TIFFsetByteArray ENDP
_TEXT	ENDS
PUBLIC	__TIFFsetString
EXTRN	_strlen:NEAR
_TEXT	SEGMENT
_cpp$ = 8
_cp$ = 12
__TIFFsetString PROC NEAR

; 52   :     { _TIFFsetByteArray((void**) cpp, (void*) cp, (long) (strlen(cp)+1)); }

	push	ebp
	mov	ebp, esp
	mov	eax, DWORD PTR _cp$[ebp]
	push	eax
	call	_strlen
	add	esp, 4
	add	eax, 1
	push	eax
	mov	ecx, DWORD PTR _cp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _cpp$[ebp]
	push	edx
	call	__TIFFsetByteArray
	add	esp, 12					; 0000000cH
	pop	ebp
	ret	0
__TIFFsetString ENDP
_TEXT	ENDS
PUBLIC	__TIFFsetNString
_TEXT	SEGMENT
_cpp$ = 8
_cp$ = 12
_n$ = 16
__TIFFsetNString PROC NEAR

; 54   :     { _TIFFsetByteArray((void**) cpp, (void*) cp, n); }

	push	ebp
	mov	ebp, esp
	mov	eax, DWORD PTR _n$[ebp]
	push	eax
	mov	ecx, DWORD PTR _cp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _cpp$[ebp]
	push	edx
	call	__TIFFsetByteArray
	add	esp, 12					; 0000000cH
	pop	ebp
	ret	0
__TIFFsetNString ENDP
_TEXT	ENDS
PUBLIC	__TIFFsetShortArray
_TEXT	SEGMENT
_wpp$ = 8
_wp$ = 12
_n$ = 16
__TIFFsetShortArray PROC NEAR

; 56   :     { _TIFFsetByteArray((void**) wpp, (void*) wp, n*sizeof (uint16)); }

	push	ebp
	mov	ebp, esp
	mov	eax, DWORD PTR _n$[ebp]
	shl	eax, 1
	push	eax
	mov	ecx, DWORD PTR _wp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _wpp$[ebp]
	push	edx
	call	__TIFFsetByteArray
	add	esp, 12					; 0000000cH
	pop	ebp
	ret	0
__TIFFsetShortArray ENDP
_TEXT	ENDS
PUBLIC	__TIFFsetLongArray
_TEXT	SEGMENT
_lpp$ = 8
_lp$ = 12
_n$ = 16
__TIFFsetLongArray PROC NEAR

; 58   :     { _TIFFsetByteArray((void**) lpp, (void*) lp, n*sizeof (uint32)); }

	push	ebp
	mov	ebp, esp
	mov	eax, DWORD PTR _n$[ebp]
	shl	eax, 2
	push	eax
	mov	ecx, DWORD PTR _lp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _lpp$[ebp]
	push	edx
	call	__TIFFsetByteArray
	add	esp, 12					; 0000000cH
	pop	ebp
	ret	0
__TIFFsetLongArray ENDP
_TEXT	ENDS
PUBLIC	__TIFFsetFloatArray
_TEXT	SEGMENT
_fpp$ = 8
_fp$ = 12
_n$ = 16
__TIFFsetFloatArray PROC NEAR

; 60   :     { _TIFFsetByteArray((void**) fpp, (void*) fp, n*sizeof (float)); }

	push	ebp
	mov	ebp, esp
	mov	eax, DWORD PTR _n$[ebp]
	shl	eax, 2
	push	eax
	mov	ecx, DWORD PTR _fp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _fpp$[ebp]
	push	edx
	call	__TIFFsetByteArray
	add	esp, 12					; 0000000cH
	pop	ebp
	ret	0
__TIFFsetFloatArray ENDP
_TEXT	ENDS
PUBLIC	__TIFFsetDoubleArray
_TEXT	SEGMENT
_dpp$ = 8
_dp$ = 12
_n$ = 16
__TIFFsetDoubleArray PROC NEAR

; 62   :     { _TIFFsetByteArray((void**) dpp, (void*) dp, n*sizeof (double)); }

	push	ebp
	mov	ebp, esp
	mov	eax, DWORD PTR _n$[ebp]
	shl	eax, 3
	push	eax
	mov	ecx, DWORD PTR _dp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _dpp$[ebp]
	push	edx
	call	__TIFFsetByteArray
	add	esp, 12					; 0000000cH
	pop	ebp
	ret	0
__TIFFsetDoubleArray ENDP
_TEXT	ENDS
PUBLIC	_TIFFSetField
PUBLIC	_TIFFVSetField
_TEXT	SEGMENT
_tif$ = 8
_tag$ = 12
_ap$ = -4
_status$ = -8
_TIFFSetField PROC NEAR

; 564  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 565  : 	va_list ap;
; 566  : 	int status;
; 567  : 
; 568  : 	va_start(ap, tag);

	lea	eax, DWORD PTR _tag$[ebp+4]
	mov	DWORD PTR _ap$[ebp], eax

; 569  : 	status = TIFFVSetField(tif, tag, ap);

	mov	ecx, DWORD PTR _ap$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tag$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFVSetField
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _status$[ebp], eax

; 570  : 	va_end(ap);

	mov	DWORD PTR _ap$[ebp], 0

; 571  : 	return (status);

	mov	eax, DWORD PTR _status$[ebp]

; 572  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFSetField ENDP
_tif$ = 8
_tag$ = 12
_ap$ = 16
_TIFFVSetField PROC NEAR

; 582  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 583  : 	return OkToChangeTag(tif, tag) ?
; 584  : 	    (*tif->tif_vsetfield)(tif, tag, ap) : 0;

	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_OkToChangeTag
	add	esp, 8
	test	eax, eax
	je	SHORT $L67597
	mov	edx, DWORD PTR _ap$[ebp]
	push	edx
	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+540]
	add	esp, 12					; 0000000cH
	mov	DWORD PTR -4+[ebp], eax
	jmp	SHORT $L67598
$L67597:
	mov	DWORD PTR -4+[ebp], 0
$L67598:
	mov	eax, DWORD PTR -4+[ebp]

; 585  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFVSetField ENDP
_TEXT	ENDS
EXTRN	_TIFFError:NEAR
EXTRN	__TIFFFindFieldInfo:NEAR
_BSS	SEGMENT
$SG66644 DB	01H DUP (?)
_BSS	ENDS
_DATA	SEGMENT
$SG66643 DB	'pseudo-', 00H
$SG66645 DB	'%s: Unknown %stag %u', 00H
	ORG $+3
$SG66646 DB	'TIFFSetField', 00H
	ORG $+3
$SG66648 DB	'%s: Cannot modify tag "%s" while writing', 00H
	ORG $+3
$SG66649 DB	'TIFFSetField', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_tag$ = 12
_fip$ = -4
_OkToChangeTag PROC NEAR

; 532  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 533  : 	const TIFFFieldInfo* fip = _TIFFFindFieldInfo(tif, tag, TIFF_ANY);

	push	0
	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	__TIFFFindFieldInfo
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _fip$[ebp], eax

; 534  : 	if (!fip) {			/* unknown tag */

	cmp	DWORD PTR _fip$[ebp], 0
	jne	SHORT $L66642

; 535  : 		TIFFError("TIFFSetField", "%s: Unknown %stag %u",
; 536  : 		    tif->tif_name, isPseudoTag(tag) ? "pseudo-" : "", tag);

	cmp	DWORD PTR _tag$[ebp], 65535		; 0000ffffH
	jbe	SHORT $L67600
	mov	DWORD PTR -8+[ebp], OFFSET FLAT:$SG66643
	jmp	SHORT $L67601
$L67600:
	mov	DWORD PTR -8+[ebp], OFFSET FLAT:$SG66644
$L67601:
	mov	edx, DWORD PTR _tag$[ebp]
	push	edx
	mov	eax, DWORD PTR -8+[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	push	OFFSET FLAT:$SG66645
	push	OFFSET FLAT:$SG66646
	call	_TIFFError
	add	esp, 20					; 00000014H

; 537  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L66640
$L66642:

; 539  : 	if (tag != TIFFTAG_IMAGELENGTH && (tif->tif_flags & TIFF_BEENWRITING) &&
; 540  : 	    !fip->field_oktochange) {

	cmp	DWORD PTR _tag$[ebp], 257		; 00000101H
	je	SHORT $L66647
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 64					; 00000040H
	test	ecx, ecx
	je	SHORT $L66647
	mov	edx, DWORD PTR _fip$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+14]
	test	eax, eax
	jne	SHORT $L66647

; 541  : 		/*
; 542  : 		 * Consult info table to see if tag can be changed
; 543  : 		 * after we've started writing.  We only allow changes
; 544  : 		 * to those tags that don't/shouldn't affect the
; 545  : 		 * compression and/or format of the data.
; 546  : 		 */
; 547  : 		TIFFError("TIFFSetField",
; 548  : 		    "%s: Cannot modify tag \"%s\" while writing",
; 549  : 		    tif->tif_name, fip->field_name);

	mov	ecx, DWORD PTR _fip$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG66648
	push	OFFSET FLAT:$SG66649
	call	_TIFFError
	add	esp, 16					; 00000010H

; 550  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L66640
$L66647:

; 552  : 	return (1);

	mov	eax, 1
$L66640:

; 553  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_OkToChangeTag ENDP
_TEXT	ENDS
PUBLIC	_TIFFGetField
PUBLIC	_TIFFVGetField
_TEXT	SEGMENT
_tif$ = 8
_tag$ = 12
_status$ = -8
_ap$ = -4
_TIFFGetField PROC NEAR

; 870  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 871  : 	int status;
; 872  : 	va_list ap;
; 873  : 
; 874  : 	va_start(ap, tag);

	lea	eax, DWORD PTR _tag$[ebp+4]
	mov	DWORD PTR _ap$[ebp], eax

; 875  : 	status = TIFFVGetField(tif, tag, ap);

	mov	ecx, DWORD PTR _ap$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tag$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFVGetField
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _status$[ebp], eax

; 876  : 	va_end(ap);

	mov	DWORD PTR _ap$[ebp], 0

; 877  : 	return (status);

	mov	eax, DWORD PTR _status$[ebp]

; 878  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFGetField ENDP
_tif$ = 8
_tag$ = 12
_ap$ = 16
_fip$ = -4
_TIFFVGetField PROC NEAR

; 888  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 889  : 	const TIFFFieldInfo* fip = _TIFFFindFieldInfo(tif, tag, TIFF_ANY);

	push	0
	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	__TIFFFindFieldInfo
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _fip$[ebp], eax

; 890  : 	return (fip && (isPseudoTag(tag) || TIFFFieldSet(tif, fip->field_bit)) ?
; 891  : 	    (*tif->tif_vgetfield)(tif, tag, ap) : 0);

	cmp	DWORD PTR _fip$[ebp], 0
	je	SHORT $L67605
	cmp	DWORD PTR _tag$[ebp], 65535		; 0000ffffH
	ja	SHORT $L67604
	mov	edx, DWORD PTR _fip$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+12]
	cdq
	and	edx, 31					; 0000001fH
	add	eax, edx
	sar	eax, 5
	mov	ecx, DWORD PTR _fip$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+12]
	mov	ecx, edx
	and	ecx, 31					; 0000001fH
	mov	edx, 1
	shl	edx, cl
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4+24]
	and	eax, edx
	test	eax, eax
	je	SHORT $L67605
$L67604:
	mov	ecx, DWORD PTR _ap$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tag$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+544]
	add	esp, 12					; 0000000cH
	mov	DWORD PTR -8+[ebp], eax
	jmp	SHORT $L67606
$L67605:
	mov	DWORD PTR -8+[ebp], 0
$L67606:
	mov	eax, DWORD PTR -8+[ebp]

; 892  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFVGetField ENDP
_TEXT	ENDS
PUBLIC	_TIFFFreeDirectory
_TEXT	SEGMENT
_tif$ = 8
_td$ = -4
_TIFFFreeDirectory PROC NEAR

; 906  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 907  : 	register TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 908  : 
; 909  : 	CleanupField(td_colormap[0]);

	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+104], 0
	je	SHORT $L67378
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+104]
	push	eax
	call	__TIFFfree
	add	esp, 4
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+104], 0
$L67378:

; 910  : 	CleanupField(td_colormap[1]);

	mov	edx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [edx+108], 0
	je	SHORT $L67379
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+108]
	push	ecx
	call	__TIFFfree
	add	esp, 4
	mov	edx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [edx+108], 0
$L67379:

; 911  : 	CleanupField(td_colormap[2]);

	mov	eax, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [eax+112], 0
	je	SHORT $L67380
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+112]
	push	edx
	call	__TIFFfree
	add	esp, 4
	mov	eax, DWORD PTR _td$[ebp]
	mov	DWORD PTR [eax+112], 0
$L67380:

; 912  : 	CleanupField(td_documentname);

	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+136], 0
	je	SHORT $L67381
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+136]
	push	eax
	call	__TIFFfree
	add	esp, 4
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+136], 0
$L67381:

; 913  : 	CleanupField(td_artist);

	mov	edx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [edx+140], 0
	je	SHORT $L67382
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+140]
	push	ecx
	call	__TIFFfree
	add	esp, 4
	mov	edx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [edx+140], 0
$L67382:

; 914  : 	CleanupField(td_datetime);

	mov	eax, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [eax+144], 0
	je	SHORT $L67383
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+144]
	push	edx
	call	__TIFFfree
	add	esp, 4
	mov	eax, DWORD PTR _td$[ebp]
	mov	DWORD PTR [eax+144], 0
$L67383:

; 915  : 	CleanupField(td_hostcomputer);

	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+148], 0
	je	SHORT $L67384
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+148]
	push	eax
	call	__TIFFfree
	add	esp, 4
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+148], 0
$L67384:

; 916  : 	CleanupField(td_imagedescription);

	mov	edx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [edx+152], 0
	je	SHORT $L67385
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+152]
	push	ecx
	call	__TIFFfree
	add	esp, 4
	mov	edx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [edx+152], 0
$L67385:

; 917  : 	CleanupField(td_make);

	mov	eax, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [eax+156], 0
	je	SHORT $L67386
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+156]
	push	edx
	call	__TIFFfree
	add	esp, 4
	mov	eax, DWORD PTR _td$[ebp]
	mov	DWORD PTR [eax+156], 0
$L67386:

; 918  : 	CleanupField(td_model);

	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+160], 0
	je	SHORT $L67387
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+160]
	push	eax
	call	__TIFFfree
	add	esp, 4
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+160], 0
$L67387:

; 919  : 	CleanupField(td_software);

	mov	edx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [edx+164], 0
	je	SHORT $L67388
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+164]
	push	ecx
	call	__TIFFfree
	add	esp, 4
	mov	edx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [edx+164], 0
$L67388:

; 920  : 	CleanupField(td_copyright);

	mov	eax, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [eax+168], 0
	je	SHORT $L67389
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+168]
	push	edx
	call	__TIFFfree
	add	esp, 4
	mov	eax, DWORD PTR _td$[ebp]
	mov	DWORD PTR [eax+168], 0
$L67389:

; 921  : 	CleanupField(td_pagename);

	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+172], 0
	je	SHORT $L67390
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+172]
	push	eax
	call	__TIFFfree
	add	esp, 4
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+172], 0
$L67390:

; 922  : 	CleanupField(td_sampleinfo);

	mov	edx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [edx+124], 0
	je	SHORT $L67391
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+124]
	push	ecx
	call	__TIFFfree
	add	esp, 4
	mov	edx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [edx+124], 0
$L67391:

; 923  : #if SUBIFD_SUPPORT
; 924  : 	CleanupField(td_subifd);

	mov	eax, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [eax+196], 0
	je	SHORT $L67392
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+196]
	push	edx
	call	__TIFFfree
	add	esp, 4
	mov	eax, DWORD PTR _td$[ebp]
	mov	DWORD PTR [eax+196], 0
$L67392:

; 925  : #endif
; 926  : #ifdef YCBCR_SUPPORT
; 927  : 	CleanupField(td_ycbcrcoeffs);

	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+200], 0
	je	SHORT $L67393
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+200]
	push	eax
	call	__TIFFfree
	add	esp, 4
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+200], 0
$L67393:

; 928  : #endif
; 929  : #ifdef CMYK_SUPPORT
; 930  : 	CleanupField(td_inknames);

	mov	edx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [edx+248], 0
	je	SHORT $L67394
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+248]
	push	ecx
	call	__TIFFfree
	add	esp, 4
	mov	edx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [edx+248], 0
$L67394:

; 931  : 	CleanupField(td_targetprinter);

	mov	eax, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [eax+252], 0
	je	SHORT $L67395
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+252]
	push	edx
	call	__TIFFfree
	add	esp, 4
	mov	eax, DWORD PTR _td$[ebp]
	mov	DWORD PTR [eax+252], 0
$L67395:

; 932  : #endif
; 933  : #ifdef COLORIMETRY_SUPPORT
; 934  : 	CleanupField(td_whitepoint);

	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+212], 0
	je	SHORT $L67396
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+212]
	push	eax
	call	__TIFFfree
	add	esp, 4
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+212], 0
$L67396:

; 935  : 	CleanupField(td_primarychromas);

	mov	edx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [edx+216], 0
	je	SHORT $L67397
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+216]
	push	ecx
	call	__TIFFfree
	add	esp, 4
	mov	edx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [edx+216], 0
$L67397:

; 936  : 	CleanupField(td_refblackwhite);

	mov	eax, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [eax+220], 0
	je	SHORT $L67398
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+220]
	push	edx
	call	__TIFFfree
	add	esp, 4
	mov	eax, DWORD PTR _td$[ebp]
	mov	DWORD PTR [eax+220], 0
$L67398:

; 937  : 	CleanupField(td_transferfunction[0]);

	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+224], 0
	je	SHORT $L67399
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+224]
	push	eax
	call	__TIFFfree
	add	esp, 4
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+224], 0
$L67399:

; 938  : 	CleanupField(td_transferfunction[1]);

	mov	edx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [edx+228], 0
	je	SHORT $L67400
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+228]
	push	ecx
	call	__TIFFfree
	add	esp, 4
	mov	edx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [edx+228], 0
$L67400:

; 939  : 	CleanupField(td_transferfunction[2]);

	mov	eax, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [eax+232], 0
	je	SHORT $L67401
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+232]
	push	edx
	call	__TIFFfree
	add	esp, 4
	mov	eax, DWORD PTR _td$[ebp]
	mov	DWORD PTR [eax+232], 0
$L67401:

; 940  : #endif
; 941  : #ifdef ICC_SUPPORT
; 942  : 	CleanupField(td_profileData);

	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+260], 0
	je	SHORT $L67402
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+260]
	push	eax
	call	__TIFFfree
	add	esp, 4
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+260], 0
$L67402:

; 943  : #endif
; 944  : #ifdef PHOTOSHOP_SUPPORT
; 945  : 	CleanupField(td_photoshopData);

	mov	edx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [edx+268], 0
	je	SHORT $L67403
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+268]
	push	ecx
	call	__TIFFfree
	add	esp, 4
	mov	edx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [edx+268], 0
$L67403:

; 946  : #endif
; 947  : #ifdef IPTC_SUPPORT
; 948  : 	CleanupField(td_richtiffiptcData);

	mov	eax, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [eax+276], 0
	je	SHORT $L67404
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+276]
	push	edx
	call	__TIFFfree
	add	esp, 4
	mov	eax, DWORD PTR _td$[ebp]
	mov	DWORD PTR [eax+276], 0
$L67404:

; 949  : #endif
; 950  : 	CleanupField(td_stripoffset);

	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+184], 0
	je	SHORT $L67405
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+184]
	push	eax
	call	__TIFFfree
	add	esp, 4
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+184], 0
$L67405:

; 951  : 	CleanupField(td_stripbytecount);

	mov	edx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [edx+188], 0
	je	SHORT $L67406
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+188]
	push	ecx
	call	__TIFFfree
	add	esp, 4
	mov	edx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [edx+188], 0
$L67406:

; 952  :  	/* Begin Pixar Tags */
; 953  :  	CleanupField(td_textureformat);

	mov	eax, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [eax+288], 0
	je	SHORT $L67407
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+288]
	push	edx
	call	__TIFFfree
	add	esp, 4
	mov	eax, DWORD PTR _td$[ebp]
	mov	DWORD PTR [eax+288], 0
$L67407:

; 954  :  	CleanupField(td_wrapmodes);

	mov	ecx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [ecx+292], 0
	je	SHORT $L67408
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+292]
	push	eax
	call	__TIFFfree
	add	esp, 4
	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+292], 0
$L67408:

; 955  :  	CleanupField(td_matrixWorldToScreen);

	mov	edx, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [edx+300], 0
	je	SHORT $L67409
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+300]
	push	ecx
	call	__TIFFfree
	add	esp, 4
	mov	edx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [edx+300], 0
$L67409:

; 956  :  	CleanupField(td_matrixWorldToCamera);

	mov	eax, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [eax+304], 0
	je	SHORT $L67410
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+304]
	push	edx
	call	__TIFFfree
	add	esp, 4
	mov	eax, DWORD PTR _td$[ebp]
	mov	DWORD PTR [eax+304], 0
$L67410:

; 957  :  	/* End Pixar Tags */
; 958  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFFreeDirectory ENDP
_TEXT	ENDS
PUBLIC	_TIFFSetTagExtender
_TEXT	SEGMENT
_extender$ = 8
_prev$ = -4
_TIFFSetTagExtender PROC NEAR

; 968  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 969  : 	TIFFExtendProc prev = _TIFFextender;

	mov	eax, DWORD PTR __TIFFextender
	mov	DWORD PTR _prev$[ebp], eax

; 970  : 	_TIFFextender = extender;

	mov	ecx, DWORD PTR _extender$[ebp]
	mov	DWORD PTR __TIFFextender, ecx

; 971  : 	return (prev);

	mov	eax, DWORD PTR _prev$[ebp]

; 972  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFSetTagExtender ENDP
_TEXT	ENDS
PUBLIC	_TIFFDefaultDirectory
PUBLIC	_TIFFCreateDirectory
_TEXT	SEGMENT
_tif$ = 8
_TIFFCreateDirectory PROC NEAR

; 983  : {

	push	ebp
	mov	ebp, esp

; 984  :     TIFFDefaultDirectory(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFDefaultDirectory
	add	esp, 4

; 985  :     tif->tif_diroff = 0;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+16], 0

; 986  :     tif->tif_nextdiroff = 0;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+20], 0

; 987  :     tif->tif_curoff = 0;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+368], 0

; 988  :     tif->tif_row = (uint32) -1;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+356], -1

; 989  :     tif->tif_curstrip = (tstrip_t) -1;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+364], -1

; 990  : 
; 991  :     return 0;

	xor	eax, eax

; 992  : }

	pop	ebp
	ret	0
_TIFFCreateDirectory ENDP
_TEXT	ENDS
EXTRN	__TIFFNoPostDecode:NEAR
EXTRN	__TIFFmemset:NEAR
EXTRN	__TIFFSetupFieldInfo:NEAR
_TEXT	SEGMENT
_tif$ = 8
_td$ = -4
_TIFFDefaultDirectory PROC NEAR

; 999  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 1000 : 	register TIFFDirectory* td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 1001 : 
; 1002 : 	_TIFFSetupFieldInfo(tif);

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	__TIFFSetupFieldInfo
	add	esp, 4

; 1003 : 	_TIFFmemset(td, 0, sizeof (*td));

	push	312					; 00000138H
	push	0
	mov	edx, DWORD PTR _td$[ebp]
	push	edx
	call	__TIFFmemset
	add	esp, 12					; 0000000cH

; 1004 : 	td->td_fillorder = FILLORDER_MSB2LSB;

	mov	eax, DWORD PTR _td$[ebp]
	mov	WORD PTR [eax+50], 1

; 1005 : 	td->td_bitspersample = 1;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	WORD PTR [ecx+40], 1

; 1006 : 	td->td_threshholding = THRESHHOLD_BILEVEL;

	mov	edx, DWORD PTR _td$[ebp]
	mov	WORD PTR [edx+48], 1

; 1007 : 	td->td_orientation = ORIENTATION_TOPLEFT;

	mov	eax, DWORD PTR _td$[ebp]
	mov	WORD PTR [eax+52], 1

; 1008 : 	td->td_samplesperpixel = 1;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	WORD PTR [ecx+54], 1

; 1009 : 	td->td_rowsperstrip = (uint32) -1;

	mov	edx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [edx+56], -1

; 1010 : 	td->td_tilewidth = (uint32) -1;

	mov	eax, DWORD PTR _td$[ebp]
	mov	DWORD PTR [eax+24], -1

; 1011 : 	td->td_tilelength = (uint32) -1;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [ecx+28], -1

; 1012 : 	td->td_tiledepth = 1;

	mov	edx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [edx+32], 1

; 1013 : 	td->td_resolutionunit = RESUNIT_INCH;

	mov	eax, DWORD PTR _td$[ebp]
	mov	WORD PTR [eax+88], 2

; 1014 : 	td->td_sampleformat = SAMPLEFORMAT_UINT;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	WORD PTR [ecx+42], 1

; 1015 : 	td->td_imagedepth = 1;

	mov	edx, DWORD PTR _td$[ebp]
	mov	DWORD PTR [edx+20], 1

; 1016 : #ifdef YCBCR_SUPPORT
; 1017 : 	td->td_ycbcrsubsampling[0] = 2;

	mov	eax, DWORD PTR _td$[ebp]
	mov	WORD PTR [eax+204], 2

; 1018 : 	td->td_ycbcrsubsampling[1] = 2;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	WORD PTR [ecx+206], 2

; 1019 : 	td->td_ycbcrpositioning = YCBCRPOSITION_CENTERED;

	mov	edx, DWORD PTR _td$[ebp]
	mov	WORD PTR [edx+208], 1

; 1020 : #endif
; 1021 : #ifdef CMYK_SUPPORT
; 1022 : 	td->td_inkset = INKSET_CMYK;

	mov	eax, DWORD PTR _td$[ebp]
	mov	WORD PTR [eax+236], 1

; 1023 : 	td->td_ninks = 4;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	WORD PTR [ecx+238], 4

; 1024 : #endif
; 1025 : 	tif->tif_postdecode = _TIFFNoPostDecode;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+528], OFFSET FLAT:__TIFFNoPostDecode

; 1026 : 	tif->tif_vsetfield = _TIFFVSetField;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+540], OFFSET FLAT:__TIFFVSetField

; 1027 : 	tif->tif_vgetfield = _TIFFVGetField;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+544], OFFSET FLAT:__TIFFVGetField

; 1028 : 	tif->tif_printdir = NULL;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+548], 0

; 1029 : 	/*
; 1030 : 	 *  Give client code a chance to install their own
; 1031 : 	 *  tag extensions & methods, prior to compression overloads.
; 1032 : 	 */
; 1033 : 	if (_TIFFextender)

	cmp	DWORD PTR __TIFFextender, 0
	je	SHORT $L67431

; 1034 : 		(*_TIFFextender)(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	DWORD PTR __TIFFextender
	add	esp, 4
$L67431:

; 1035 : 	(void) TIFFSetField(tif, TIFFTAG_COMPRESSION, COMPRESSION_NONE);

	push	1
	push	259					; 00000103H
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFSetField
	add	esp, 12					; 0000000cH

; 1036 : 	/*
; 1037 : 	 * NB: The directory is marked dirty as a result of setting
; 1038 : 	 * up the default compression scheme.  However, this really
; 1039 : 	 * isn't correct -- we want TIFF_DIRTYDIRECT to be set only
; 1040 : 	 * if the user does something.  We could just do the setup
; 1041 : 	 * by hand, but it seems better to use the normal mechanism
; 1042 : 	 * (i.e. TIFFSetField).
; 1043 : 	 */
; 1044 : 	tif->tif_flags &= ~TIFF_DIRTYDIRECT;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	al, -9					; fffffff7H
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+12], eax

; 1045 : 
; 1046 :         /*
; 1047 :          * As per http://bugzilla.remotesensing.org/show_bug.cgi?id=19
; 1048 :          * we clear the ISTILED flag when setting up a new directory.
; 1049 :          * Should we also be clearing stuff like INSUBIFD?
; 1050 :          */
; 1051 :         tif->tif_flags &= ~TIFF_ISTILED;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	ah, -5					; fffffffbH
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+12], eax

; 1052 : 
; 1053 : 	return (1);

	mov	eax, 1

; 1054 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFDefaultDirectory ENDP
_TEXT	ENDS
PUBLIC	__real@8@00000000000000000000
EXTRN	__fltused:NEAR
EXTRN	__TIFFSwab16BitData:NEAR
EXTRN	__TIFFSwab32BitData:NEAR
EXTRN	__TIFFSwab64BitData:NEAR
EXTRN	_TIFFSetCompressionScheme:NEAR
EXTRN	_TIFFWarning:NEAR
EXTRN	__TIFFFieldWithTag:NEAR
_BSS	SEGMENT
	ALIGN	4

$SG66623 DB	01H DUP (?)
_BSS	ENDS
_DATA	SEGMENT
	ORG $+3
$SG66093 DB	'Bad value %ld for "%s" tag ignored', 00H
	ORG $+1
$SG66299 DB	'Nonstandard tile width %d, convert file', 00H
$SG66310 DB	'Nonstandard tile length %d, convert file', 00H
	ORG $+3
$SG66443 DB	'Sorry, cannot nest SubIFDs', 00H
	ORG $+1
$SG66622 DB	'pseduo-', 00H
$SG66624 DB	'%s: Invalid %stag "%s" (not supported by codec)', 00H
$SG66625 DB	'TIFFSetField', 00H
	ORG $+3
$SG66629 DB	'%d: Bad value for "%s"', 00H
	ORG $+1
$SG66631 DB	'%ld: Bad value for "%s"', 00H
$SG66633 DB	'%f: Bad value for "%s"', 00H
_DATA	ENDS
;	COMDAT __real@8@00000000000000000000
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_dir.c
CONST	SEGMENT
__real@8@00000000000000000000 DQ 00000000000000000r ; 0
CONST	ENDS
_TEXT	SEGMENT
_tif$ = 8
_tag$ = 12
_ap$ = 16
_td$ = -28
_status$ = -32
_v32$ = -24
_i$ = -20
_v$ = -16
_d$ = -12
_s$ = -4
_sv$66288 = -36
__TIFFVSetField PROC NEAR

; 117  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 52					; 00000034H

; 118  : 	TIFFDirectory* td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 119  : 	int status = 1;

	mov	DWORD PTR _status$[ebp], 1

; 120  : 	uint32 v32;
; 121  : 	int i, v;
; 122  : 	double d;
; 123  : 	char* s;
; 124  : 
; 125  : 	switch (tag) {

	mov	ecx, DWORD PTR _tag$[ebp]
	mov	DWORD PTR -40+[ebp], ecx
	cmp	DWORD PTR -40+[ebp], 301		; 0000012dH
	ja	SHORT $L67614
	cmp	DWORD PTR -40+[ebp], 301		; 0000012dH
	je	$L66494
	mov	edx, DWORD PTR -40+[ebp]
	sub	edx, 254				; 000000feH
	mov	DWORD PTR -40+[ebp], edx
	cmp	DWORD PTR -40+[ebp], 43			; 0000002bH
	ja	$L66621
	mov	ecx, DWORD PTR -40+[ebp]
	xor	eax, eax
	mov	al, BYTE PTR $L67624[ecx]
	jmp	DWORD PTR $L67625[eax*4]
$L67614:
	cmp	DWORD PTR -40+[ebp], 529		; 00000211H
	ja	SHORT $L67615
	cmp	DWORD PTR -40+[ebp], 529		; 00000211H
	je	$L66444
	mov	edx, DWORD PTR -40+[ebp]
	sub	edx, 305				; 00000131H
	mov	DWORD PTR -40+[ebp], edx
	cmp	DWORD PTR -40+[ebp], 36			; 00000024H
	ja	$L66621
	mov	ecx, DWORD PTR -40+[ebp]
	xor	eax, eax
	mov	al, BYTE PTR $L67626[ecx]
	jmp	DWORD PTR $L67627[eax*4]
$L67615:
	cmp	DWORD PTR -40+[ebp], 33302		; 00008216H
	ja	$L67616
	cmp	DWORD PTR -40+[ebp], 33302		; 00008216H
	je	$L66383
	cmp	DWORD PTR -40+[ebp], 32996		; 000080e4H
	ja	SHORT $L67617
	cmp	DWORD PTR -40+[ebp], 32996		; 000080e4H
	je	$L66320
	cmp	DWORD PTR -40+[ebp], 532		; 00000214H
	ja	SHORT $L67618
	cmp	DWORD PTR -40+[ebp], 532		; 00000214H
	je	$L66505
	cmp	DWORD PTR -40+[ebp], 530		; 00000212H
	je	$L66461
	cmp	DWORD PTR -40+[ebp], 531		; 00000213H
	je	$L66452
	jmp	$L66621
$L67618:
	cmp	DWORD PTR -40+[ebp], 32995		; 000080e3H
	je	$L66278
	jmp	$L66621
$L67617:
	cmp	DWORD PTR -40+[ebp], 33300		; 00008214H
	ja	SHORT $L67619
	cmp	DWORD PTR -40+[ebp], 33300		; 00008214H
	je	$L66367
	cmp	DWORD PTR -40+[ebp], 32997		; 000080e5H
	je	$L66349
	cmp	DWORD PTR -40+[ebp], 32998		; 000080e6H
	je	$L66311
	jmp	$L66621
$L67619:
	cmp	DWORD PTR -40+[ebp], 33301		; 00008215H
	je	$L66375
	jmp	$L66621
$L67616:
	cmp	DWORD PTR -40+[ebp], 33432		; 00008298H
	ja	SHORT $L67620
	cmp	DWORD PTR -40+[ebp], 33432		; 00008298H
	je	$L66075
	mov	edx, DWORD PTR -40+[ebp]
	sub	edx, 33303				; 00008217H
	mov	DWORD PTR -40+[ebp], edx
	cmp	DWORD PTR -40+[ebp], 3
	ja	$L66621
	mov	eax, DWORD PTR -40+[ebp]
	jmp	DWORD PTR $L67628[eax*4]
$L67620:
	cmp	DWORD PTR -40+[ebp], 34675		; 00008773H
	ja	SHORT $L67621
	cmp	DWORD PTR -40+[ebp], 34675		; 00008773H
	je	$L66572
	cmp	DWORD PTR -40+[ebp], 33723		; 000083bbH
	je	$L66604
	cmp	DWORD PTR -40+[ebp], 34377		; 00008649H
	je	$L66588
	jmp	$L66621
$L67621:
	cmp	DWORD PTR -40+[ebp], 37439		; 0000923fH
	je	$L66357
	jmp	$L66621
$L65930:

; 126  : 	case TIFFTAG_SUBFILETYPE:
; 127  : 		td->td_subfiletype = va_arg(ap, uint32);

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	DWORD PTR [edx+36], ecx

; 128  : 		break;

	jmp	$L65927
$L65938:

; 129  : 	case TIFFTAG_IMAGEWIDTH:
; 130  : 		td->td_imagewidth = va_arg(ap, uint32);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	DWORD PTR [eax+12], edx

; 131  : 		break;

	jmp	$L65927
$L65946:

; 132  : 	case TIFFTAG_IMAGELENGTH:
; 133  : 		td->td_imagelength = va_arg(ap, uint32);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	DWORD PTR [ecx+16], eax

; 134  : 		break;

	jmp	$L65927
$L65954:

; 135  : 	case TIFFTAG_BITSPERSAMPLE:
; 136  : 		td->td_bitspersample = (uint16) va_arg(ap, int);

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _ap$[ebp]
	mov	cx, WORD PTR [eax-4]
	mov	WORD PTR [edx+40], cx

; 137  : 		/*
; 138  : 		 * If the data require post-decoding processing
; 139  : 		 * to byte-swap samples, set it up here.  Note
; 140  : 		 * that since tags are required to be ordered,
; 141  : 		 * compression code can override this behaviour
; 142  : 		 * in the setup method if it wants to roll the
; 143  : 		 * post decoding work in with its normal work.
; 144  : 		 */
; 145  : 		if (tif->tif_flags & TIFF_SWAB) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 128				; 00000080H
	test	eax, eax
	je	SHORT $L65968

; 146  : 			if (td->td_bitspersample == 16)

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+40]
	cmp	edx, 16					; 00000010H
	jne	SHORT $L65964

; 147  : 				tif->tif_postdecode = _TIFFSwab16BitData;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+528], OFFSET FLAT:__TIFFSwab16BitData

; 148  : 			else if (td->td_bitspersample == 32)

	jmp	SHORT $L65968
$L65964:
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+40]
	cmp	edx, 32					; 00000020H
	jne	SHORT $L65966

; 149  : 				tif->tif_postdecode = _TIFFSwab32BitData;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+528], OFFSET FLAT:__TIFFSwab32BitData

; 150  : 			else if (td->td_bitspersample == 64)

	jmp	SHORT $L65968
$L65966:
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+40]
	cmp	edx, 64					; 00000040H
	jne	SHORT $L65968

; 151  : 				tif->tif_postdecode = _TIFFSwab64BitData;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+528], OFFSET FLAT:__TIFFSwab64BitData
$L65968:

; 153  : 		break;

	jmp	$L65927
$L65969:

; 154  : 	case TIFFTAG_COMPRESSION:
; 155  : 		v = va_arg(ap, int) & 0xffff;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	and	eax, 65535				; 0000ffffH
	mov	DWORD PTR _v$[ebp], eax

; 156  : 		/*
; 157  : 		 * If we're changing the compression scheme,
; 158  : 		 * the notify the previous module so that it
; 159  : 		 * can cleanup any state it's setup.
; 160  : 		 */
; 161  : 		if (TIFFFieldSet(tif, FIELD_COMPRESSION)) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	and	edx, 128				; 00000080H
	test	edx, edx
	je	SHORT $L65978

; 162  : 			if (td->td_compression == v)

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+44]
	cmp	ecx, DWORD PTR _v$[ebp]
	jne	SHORT $L65979

; 163  : 				break;

	jmp	$L65927
$L65979:

; 164  : 			(*tif->tif_cleanup)(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+448]
	add	esp, 4

; 165  : 			tif->tif_flags &= ~TIFF_CODERSETUP;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, -33				; ffffffdfH
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+12], edx
$L65978:

; 167  : 		/*
; 168  : 		 * Setup new compression routine state.
; 169  : 		 */
; 170  : 		if( (status = TIFFSetCompressionScheme(tif, v)) != 0 )

	mov	ecx, DWORD PTR _v$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFSetCompressionScheme
	add	esp, 8
	mov	DWORD PTR _status$[ebp], eax
	cmp	DWORD PTR _status$[ebp], 0
	je	SHORT $L65980

; 171  :                     td->td_compression = v;

	mov	eax, DWORD PTR _td$[ebp]
	mov	cx, WORD PTR _v$[ebp]
	mov	WORD PTR [eax+44], cx

; 172  :                 else

	jmp	SHORT $L65981
$L65980:

; 173  :                     status = 0;

	mov	DWORD PTR _status$[ebp], 0
$L65981:

; 174  : 		break;

	jmp	$L65927
$L65982:

; 175  : 	case TIFFTAG_PHOTOMETRIC:
; 176  : 		td->td_photometric = (uint16) va_arg(ap, int);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	dx, WORD PTR [ecx-4]
	mov	WORD PTR [eax+46], dx

; 177  : 		break;

	jmp	$L65927
$L65991:

; 178  : 	case TIFFTAG_THRESHHOLDING:
; 179  : 		td->td_threshholding = (uint16) va_arg(ap, int);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _ap$[ebp]
	mov	ax, WORD PTR [edx-4]
	mov	WORD PTR [ecx+48], ax

; 180  : 		break;

	jmp	$L65927
$L66000:

; 181  : 	case TIFFTAG_FILLORDER:
; 182  : 		v = va_arg(ap, int);

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	DWORD PTR _v$[ebp], eax

; 183  : 		if (v != FILLORDER_LSB2MSB && v != FILLORDER_MSB2LSB)

	cmp	DWORD PTR _v$[ebp], 2
	je	SHORT $L66008
	cmp	DWORD PTR _v$[ebp], 1
	je	SHORT $L66008

; 184  : 			goto badvalue;

	jmp	$badvalue$66009
$L66008:

; 185  : 		td->td_fillorder = (uint16) v;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	dx, WORD PTR _v$[ebp]
	mov	WORD PTR [ecx+50], dx

; 186  : 		break;

	jmp	$L65927
$L66011:

; 187  : 	case TIFFTAG_DOCUMENTNAME:
; 188  : 		_TIFFsetString(&td->td_documentname, va_arg(ap, char*));

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	add	eax, 136				; 00000088H
	push	eax
	call	__TIFFsetString
	add	esp, 8

; 189  : 		break;

	jmp	$L65927
$L66019:

; 190  : 	case TIFFTAG_ARTIST:
; 191  : 		_TIFFsetString(&td->td_artist, va_arg(ap, char*));

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	add	ecx, 140				; 0000008cH
	push	ecx
	call	__TIFFsetString
	add	esp, 8

; 192  : 		break;

	jmp	$L65927
$L66027:

; 193  : 	case TIFFTAG_DATETIME:
; 194  : 		_TIFFsetString(&td->td_datetime, va_arg(ap, char*));

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	push	ecx
	mov	edx, DWORD PTR _td$[ebp]
	add	edx, 144				; 00000090H
	push	edx
	call	__TIFFsetString
	add	esp, 8

; 195  : 		break;

	jmp	$L65927
$L66035:

; 196  : 	case TIFFTAG_HOSTCOMPUTER:
; 197  : 		_TIFFsetString(&td->td_hostcomputer, va_arg(ap, char*));

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	add	eax, 148				; 00000094H
	push	eax
	call	__TIFFsetString
	add	esp, 8

; 198  : 		break;

	jmp	$L65927
$L66043:

; 199  : 	case TIFFTAG_IMAGEDESCRIPTION:
; 200  : 		_TIFFsetString(&td->td_imagedescription, va_arg(ap, char*));

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	add	ecx, 152				; 00000098H
	push	ecx
	call	__TIFFsetString
	add	esp, 8

; 201  : 		break;

	jmp	$L65927
$L66051:

; 202  : 	case TIFFTAG_MAKE:
; 203  : 		_TIFFsetString(&td->td_make, va_arg(ap, char*));

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	push	ecx
	mov	edx, DWORD PTR _td$[ebp]
	add	edx, 156				; 0000009cH
	push	edx
	call	__TIFFsetString
	add	esp, 8

; 204  : 		break;

	jmp	$L65927
$L66059:

; 205  : 	case TIFFTAG_MODEL:
; 206  : 		_TIFFsetString(&td->td_model, va_arg(ap, char*));

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	add	eax, 160				; 000000a0H
	push	eax
	call	__TIFFsetString
	add	esp, 8

; 207  : 		break;

	jmp	$L65927
$L66067:

; 208  : 	case TIFFTAG_SOFTWARE:
; 209  : 		_TIFFsetString(&td->td_software, va_arg(ap, char*));

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	add	ecx, 164				; 000000a4H
	push	ecx
	call	__TIFFsetString
	add	esp, 8

; 210  : 		break;

	jmp	$L65927
$L66075:

; 211  : 	case TIFFTAG_COPYRIGHT:
; 212  : 		_TIFFsetString(&td->td_copyright, va_arg(ap, char*));

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	push	ecx
	mov	edx, DWORD PTR _td$[ebp]
	add	edx, 168				; 000000a8H
	push	edx
	call	__TIFFsetString
	add	esp, 8

; 213  : 		break;

	jmp	$L65927
$L66083:

; 214  : 	case TIFFTAG_ORIENTATION:
; 215  : 		v = va_arg(ap, int);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	DWORD PTR _v$[ebp], edx

; 216  : 		if (v < ORIENTATION_TOPLEFT || ORIENTATION_LEFTBOT < v) {

	cmp	DWORD PTR _v$[ebp], 1
	jl	SHORT $L66092
	cmp	DWORD PTR _v$[ebp], 8
	jle	SHORT $L66091
$L66092:

; 217  : 			TIFFWarning(tif->tif_name,
; 218  : 			    "Bad value %ld for \"%s\" tag ignored",
; 219  : 			    v, _TIFFFieldWithTag(tif, tag)->field_name);

	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	__TIFFFieldWithTag
	add	esp, 8
	mov	edx, DWORD PTR [eax+16]
	push	edx
	mov	eax, DWORD PTR _v$[ebp]
	push	eax
	push	OFFSET FLAT:$SG66093
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFWarning
	add	esp, 16					; 00000010H

; 220  : 		} else

	jmp	SHORT $L66094
$L66091:

; 221  : 			td->td_orientation = (uint16) v;

	mov	eax, DWORD PTR _td$[ebp]
	mov	cx, WORD PTR _v$[ebp]
	mov	WORD PTR [eax+52], cx
$L66094:

; 222  : 		break;

	jmp	$L65927
$L66096:

; 223  : 	case TIFFTAG_SAMPLESPERPIXEL:
; 224  : 		/* XXX should cross check -- e.g. if pallette, then 1 */
; 225  : 		v = va_arg(ap, int);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	DWORD PTR _v$[ebp], ecx

; 226  : 		if (v == 0)

	cmp	DWORD PTR _v$[ebp], 0
	jne	SHORT $L66104

; 227  : 			goto badvalue;

	jmp	$badvalue$66009
$L66104:

; 228  : 		td->td_samplesperpixel = (uint16) v;

	mov	edx, DWORD PTR _td$[ebp]
	mov	ax, WORD PTR _v$[ebp]
	mov	WORD PTR [edx+54], ax

; 229  : 		break;

	jmp	$L65927
$L66106:

; 230  : 	case TIFFTAG_ROWSPERSTRIP:
; 231  : 		v32 = va_arg(ap, uint32);

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	DWORD PTR _v32$[ebp], eax

; 232  : 		if (v32 == 0)

	cmp	DWORD PTR _v32$[ebp], 0
	jne	SHORT $L66114

; 233  : 			goto badvalue32;

	jmp	$badvalue32$66115
$L66114:

; 234  : 		td->td_rowsperstrip = v32;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _v32$[ebp]
	mov	DWORD PTR [ecx+56], edx

; 235  : 		if (!TIFFFieldSet(tif, FIELD_TILEDIMENSIONS)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 4
	test	ecx, ecx
	jne	SHORT $L66117

; 236  : 			td->td_tilelength = v32;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _v32$[ebp]
	mov	DWORD PTR [edx+28], eax

; 237  : 			td->td_tilewidth = td->td_imagewidth;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR [ecx+24], eax
$L66117:

; 239  : 		break;

	jmp	$L65927
$L66118:

; 240  : 	case TIFFTAG_MINSAMPLEVALUE:
; 241  : 		td->td_minsamplevalue = (uint16) va_arg(ap, int);

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _ap$[ebp]
	mov	cx, WORD PTR [eax-4]
	mov	WORD PTR [edx+60], cx

; 242  : 		break;

	jmp	$L65927
$L66127:

; 243  : 	case TIFFTAG_MAXSAMPLEVALUE:
; 244  : 		td->td_maxsamplevalue = (uint16) va_arg(ap, int);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	dx, WORD PTR [ecx-4]
	mov	WORD PTR [eax+62], dx

; 245  : 		break;

	jmp	$L65927
$L66136:

; 246  : 	case TIFFTAG_SMINSAMPLEVALUE:
; 247  : 		td->td_sminsamplevalue = (double) va_arg(ap, dblparam_t);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 8
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	sub	ecx, 8
	fld	QWORD PTR [ecx]
	mov	edx, DWORD PTR _td$[ebp]
	fstp	QWORD PTR [edx+64]

; 248  : 		break;

	jmp	$L65927
$L66145:

; 249  : 	case TIFFTAG_SMAXSAMPLEVALUE:
; 250  : 		td->td_smaxsamplevalue = (double) va_arg(ap, dblparam_t);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 8
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	sub	ecx, 8
	fld	QWORD PTR [ecx]
	mov	edx, DWORD PTR _td$[ebp]
	fstp	QWORD PTR [edx+72]

; 251  : 		break;

	jmp	$L65927
$L66154:

; 252  : 	case TIFFTAG_XRESOLUTION:
; 253  : 		td->td_xresolution = (float) va_arg(ap, dblparam_t);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 8
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	sub	ecx, 8
	fld	QWORD PTR [ecx]
	mov	edx, DWORD PTR _td$[ebp]
	fstp	DWORD PTR [edx+80]

; 254  : 		break;

	jmp	$L65927
$L66163:

; 255  : 	case TIFFTAG_YRESOLUTION:
; 256  : 		td->td_yresolution = (float) va_arg(ap, dblparam_t);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 8
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	sub	ecx, 8
	fld	QWORD PTR [ecx]
	mov	edx, DWORD PTR _td$[ebp]
	fstp	DWORD PTR [edx+84]

; 257  : 		break;

	jmp	$L65927
$L66172:

; 258  : 	case TIFFTAG_PLANARCONFIG:
; 259  : 		v = va_arg(ap, int);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	DWORD PTR _v$[ebp], edx

; 260  : 		if (v != PLANARCONFIG_CONTIG && v != PLANARCONFIG_SEPARATE)

	cmp	DWORD PTR _v$[ebp], 1
	je	SHORT $L66180
	cmp	DWORD PTR _v$[ebp], 2
	je	SHORT $L66180

; 261  : 			goto badvalue;

	jmp	$badvalue$66009
$L66180:

; 262  : 		td->td_planarconfig = (uint16) v;

	mov	eax, DWORD PTR _td$[ebp]
	mov	cx, WORD PTR _v$[ebp]
	mov	WORD PTR [eax+90], cx

; 263  : 		break;

	jmp	$L65927
$L66182:

; 264  : 	case TIFFTAG_PAGENAME:
; 265  : 		_TIFFsetString(&td->td_pagename, va_arg(ap, char*));

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	push	ecx
	mov	edx, DWORD PTR _td$[ebp]
	add	edx, 172				; 000000acH
	push	edx
	call	__TIFFsetString
	add	esp, 8

; 266  : 		break;

	jmp	$L65927
$L66190:

; 267  : 	case TIFFTAG_XPOSITION:
; 268  : 		td->td_xposition = (float) va_arg(ap, dblparam_t);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 8
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	sub	ecx, 8
	fld	QWORD PTR [ecx]
	mov	edx, DWORD PTR _td$[ebp]
	fstp	DWORD PTR [edx+92]

; 269  : 		break;

	jmp	$L65927
$L66199:

; 270  : 	case TIFFTAG_YPOSITION:
; 271  : 		td->td_yposition = (float) va_arg(ap, dblparam_t);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 8
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	sub	ecx, 8
	fld	QWORD PTR [ecx]
	mov	edx, DWORD PTR _td$[ebp]
	fstp	DWORD PTR [edx+96]

; 272  : 		break;

	jmp	$L65927
$L66208:

; 273  : 	case TIFFTAG_RESOLUTIONUNIT:
; 274  : 		v = va_arg(ap, int);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	DWORD PTR _v$[ebp], edx

; 275  : 		if (v < RESUNIT_NONE || RESUNIT_CENTIMETER < v)

	cmp	DWORD PTR _v$[ebp], 1
	jl	SHORT $L66217
	cmp	DWORD PTR _v$[ebp], 3
	jle	SHORT $L66216
$L66217:

; 276  : 			goto badvalue;

	jmp	$badvalue$66009
$L66216:

; 277  : 		td->td_resolutionunit = (uint16) v;

	mov	eax, DWORD PTR _td$[ebp]
	mov	cx, WORD PTR _v$[ebp]
	mov	WORD PTR [eax+88], cx

; 278  : 		break;

	jmp	$L65927
$L66219:

; 279  : 	case TIFFTAG_PAGENUMBER:
; 280  : 		td->td_pagenumber[0] = (uint16) va_arg(ap, int);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	dx, WORD PTR [ecx-4]
	mov	WORD PTR [eax+100], dx

; 281  : 		td->td_pagenumber[1] = (uint16) va_arg(ap, int);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _ap$[ebp]
	mov	ax, WORD PTR [edx-4]
	mov	WORD PTR [ecx+102], ax

; 282  : 		break;

	jmp	$L65927
$L66236:

; 283  : 	case TIFFTAG_HALFTONEHINTS:
; 284  : 		td->td_halftonehints[0] = (uint16) va_arg(ap, int);

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _ap$[ebp]
	mov	cx, WORD PTR [eax-4]
	mov	WORD PTR [edx+116], cx

; 285  : 		td->td_halftonehints[1] = (uint16) va_arg(ap, int);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	dx, WORD PTR [ecx-4]
	mov	WORD PTR [eax+118], dx

; 286  : 		break;

	jmp	$L65927
$L66253:

; 287  : 	case TIFFTAG_COLORMAP:
; 288  : 		v32 = (uint32)(1L<<td->td_bitspersample);

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+40]
	mov	edx, 1
	shl	edx, cl
	mov	DWORD PTR _v32$[ebp], edx

; 289  : 		_TIFFsetShortArray(&td->td_colormap[0], va_arg(ap, uint16*), v32);

	mov	eax, DWORD PTR _v32$[ebp]
	push	eax
	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	add	ecx, 104				; 00000068H
	push	ecx
	call	__TIFFsetShortArray
	add	esp, 12					; 0000000cH

; 290  : 		_TIFFsetShortArray(&td->td_colormap[1], va_arg(ap, uint16*), v32);

	mov	edx, DWORD PTR _v32$[ebp]
	push	edx
	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	add	eax, 108				; 0000006cH
	push	eax
	call	__TIFFsetShortArray
	add	esp, 12					; 0000000cH

; 291  : 		_TIFFsetShortArray(&td->td_colormap[2], va_arg(ap, uint16*), v32);

	mov	ecx, DWORD PTR _v32$[ebp]
	push	ecx
	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	push	ecx
	mov	edx, DWORD PTR _td$[ebp]
	add	edx, 112				; 00000070H
	push	edx
	call	__TIFFsetShortArray
	add	esp, 12					; 0000000cH

; 292  : 		break;

	jmp	$L65927
$L66276:

; 293  : 	case TIFFTAG_EXTRASAMPLES:
; 294  : 		if (!setExtraSamples(td, ap, &v))

	lea	eax, DWORD PTR _v$[ebp]
	push	eax
	mov	ecx, DWORD PTR _ap$[ebp]
	push	ecx
	mov	edx, DWORD PTR _td$[ebp]
	push	edx
	call	_setExtraSamples
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L66277

; 295  : 			goto badvalue;

	jmp	$badvalue$66009
$L66277:

; 296  : 		break;

	jmp	$L65927
$L66278:

; 297  : 	case TIFFTAG_MATTEING:
; 298  : 		td->td_extrasamples = (uint16) (va_arg(ap, int) != 0);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	xor	edx, edx
	cmp	DWORD PTR [ecx-4], 0
	setne	dl
	mov	eax, DWORD PTR _td$[ebp]
	mov	WORD PTR [eax+120], dx

; 299  : 		if (td->td_extrasamples) {

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+120]
	test	edx, edx
	je	SHORT $L66287

; 300  : 			uint16 sv = EXTRASAMPLE_ASSOCALPHA;

	mov	WORD PTR _sv$66288[ebp], 1

; 301  : 			_TIFFsetShortArray(&td->td_sampleinfo, &sv, 1);

	push	1
	lea	eax, DWORD PTR _sv$66288[ebp]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	add	ecx, 124				; 0000007cH
	push	ecx
	call	__TIFFsetShortArray
	add	esp, 12					; 0000000cH
$L66287:

; 303  : 		break;

	jmp	$L65927
$L66289:

; 304  : 	case TIFFTAG_TILEWIDTH:
; 305  : 		v32 = va_arg(ap, uint32);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	DWORD PTR _v32$[ebp], ecx

; 306  : 		if (v32 % 16) {

	mov	eax, DWORD PTR _v32$[ebp]
	xor	edx, edx
	mov	ecx, 16					; 00000010H
	div	ecx
	test	edx, edx
	je	SHORT $L66297

; 307  : 			if (tif->tif_mode != O_RDONLY)

	mov	edx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [edx+8], 0
	je	SHORT $L66298

; 308  : 				goto badvalue32;

	jmp	$badvalue32$66115
$L66298:

; 309  : 			TIFFWarning(tif->tif_name,
; 310  : 			    "Nonstandard tile width %d, convert file", v32);

	mov	eax, DWORD PTR _v32$[ebp]
	push	eax
	push	OFFSET FLAT:$SG66299
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFWarning
	add	esp, 12					; 0000000cH
$L66297:

; 312  : 		td->td_tilewidth = v32;

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _v32$[ebp]
	mov	DWORD PTR [eax+24], ecx

; 313  : 		tif->tif_flags |= TIFF_ISTILED;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	or	ah, 4
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+12], eax

; 314  : 		break;

	jmp	$L65927
$L66300:

; 315  : 	case TIFFTAG_TILELENGTH:
; 316  : 		v32 = va_arg(ap, uint32);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	DWORD PTR _v32$[ebp], ecx

; 317  : 		if (v32 % 16) {

	mov	eax, DWORD PTR _v32$[ebp]
	xor	edx, edx
	mov	ecx, 16					; 00000010H
	div	ecx
	test	edx, edx
	je	SHORT $L66308

; 318  : 			if (tif->tif_mode != O_RDONLY)

	mov	edx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [edx+8], 0
	je	SHORT $L66309

; 319  : 				goto badvalue32;

	jmp	$badvalue32$66115
$L66309:

; 320  : 			TIFFWarning(tif->tif_name,
; 321  : 			    "Nonstandard tile length %d, convert file", v32);

	mov	eax, DWORD PTR _v32$[ebp]
	push	eax
	push	OFFSET FLAT:$SG66310
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFWarning
	add	esp, 12					; 0000000cH
$L66308:

; 323  : 		td->td_tilelength = v32;

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _v32$[ebp]
	mov	DWORD PTR [eax+28], ecx

; 324  : 		tif->tif_flags |= TIFF_ISTILED;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	or	ah, 4
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+12], eax

; 325  : 		break;

	jmp	$L65927
$L66311:

; 326  : 	case TIFFTAG_TILEDEPTH:
; 327  : 		v32 = va_arg(ap, uint32);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	DWORD PTR _v32$[ebp], ecx

; 328  : 		if (v32 == 0)

	cmp	DWORD PTR _v32$[ebp], 0
	jne	SHORT $L66319

; 329  : 			goto badvalue32;

	jmp	$badvalue32$66115
$L66319:

; 330  : 		td->td_tiledepth = v32;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _v32$[ebp]
	mov	DWORD PTR [edx+32], eax

; 331  : 		break;

	jmp	$L65927
$L66320:

; 332  : 	case TIFFTAG_DATATYPE:
; 333  : 		v = va_arg(ap, int);

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	DWORD PTR _v$[ebp], eax

; 334  : 		switch (v) {

	mov	ecx, DWORD PTR _v$[ebp]
	mov	DWORD PTR -44+[ebp], ecx
	cmp	DWORD PTR -44+[ebp], 3
	ja	SHORT $L66336
	mov	edx, DWORD PTR -44+[ebp]
	jmp	DWORD PTR $L67629[edx*4]
$L66332:

; 335  : 		case DATATYPE_VOID:	v = SAMPLEFORMAT_VOID;	break;

	mov	DWORD PTR _v$[ebp], 4
	jmp	SHORT $L66329
$L66333:

; 336  : 		case DATATYPE_INT:	v = SAMPLEFORMAT_INT;	break;

	mov	DWORD PTR _v$[ebp], 2
	jmp	SHORT $L66329
$L66334:

; 337  : 		case DATATYPE_UINT:	v = SAMPLEFORMAT_UINT;	break;

	mov	DWORD PTR _v$[ebp], 1
	jmp	SHORT $L66329
$L66335:

; 338  : 		case DATATYPE_IEEEFP:	v = SAMPLEFORMAT_IEEEFP;break;

	mov	DWORD PTR _v$[ebp], 3
	jmp	SHORT $L66329
$L66336:

; 339  : 		default:		goto badvalue;

	jmp	$badvalue$66009
$L66329:

; 341  : 		td->td_sampleformat = (uint16) v;

	mov	eax, DWORD PTR _td$[ebp]
	mov	cx, WORD PTR _v$[ebp]
	mov	WORD PTR [eax+42], cx

; 342  : 		break;

	jmp	$L65927
$L66338:

; 343  : 	case TIFFTAG_SAMPLEFORMAT:
; 344  : 		v = va_arg(ap, int);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	DWORD PTR _v$[ebp], ecx

; 345  : 		if (v < SAMPLEFORMAT_UINT || SAMPLEFORMAT_COMPLEXIEEEFP < v)

	cmp	DWORD PTR _v$[ebp], 1
	jl	SHORT $L66347
	cmp	DWORD PTR _v$[ebp], 6
	jle	SHORT $L66346
$L66347:

; 346  : 			goto badvalue;

	jmp	$badvalue$66009
$L66346:

; 347  : 		td->td_sampleformat = (uint16) v;

	mov	edx, DWORD PTR _td$[ebp]
	mov	ax, WORD PTR _v$[ebp]
	mov	WORD PTR [edx+42], ax

; 348  : 		break;

	jmp	$L65927
$L66349:

; 349  : 	case TIFFTAG_IMAGEDEPTH:
; 350  : 		td->td_imagedepth = va_arg(ap, uint32);

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	DWORD PTR [edx+20], ecx

; 351  : 		break;

	jmp	$L65927
$L66357:

; 352  : 	case TIFFTAG_STONITS:
; 353  : 		d = va_arg(ap, dblparam_t);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 8
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	sub	eax, 8
	fld	QWORD PTR [eax]
	fst	QWORD PTR _d$[ebp]

; 354  : 		if (d <= 0.)

	fcomp	QWORD PTR __real@8@00000000000000000000
	fnstsw	ax
	test	ah, 65					; 00000041H
	je	SHORT $L66365

; 355  : 			goto badvaluedbl;

	jmp	$badvaluedbl$66366
$L66365:

; 356  : 		td->td_stonits = d;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _d$[ebp]
	mov	DWORD PTR [ecx+128], edx
	mov	eax, DWORD PTR _d$[ebp+4]
	mov	DWORD PTR [ecx+132], eax

; 357  : 		break;

	jmp	$L65927
$L66367:

; 358  : 
; 359  : 	/* Begin Pixar Tags */
; 360  :  	case TIFFTAG_PIXAR_IMAGEFULLWIDTH:
; 361  :  		td->td_imagefullwidth = va_arg(ap, uint32);

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	DWORD PTR [edx+280], ecx

; 362  :  		break;

	jmp	$L65927
$L66375:

; 363  :  	case TIFFTAG_PIXAR_IMAGEFULLLENGTH:
; 364  :  		td->td_imagefulllength = va_arg(ap, uint32);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	DWORD PTR [eax+284], edx

; 365  :  		break;

	jmp	$L65927
$L66383:

; 366  :  	case TIFFTAG_PIXAR_TEXTUREFORMAT:
; 367  :  		_TIFFsetString(&td->td_textureformat, va_arg(ap, char*));

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	add	eax, 288				; 00000120H
	push	eax
	call	__TIFFsetString
	add	esp, 8

; 368  :  		break;

	jmp	$L65927
$L66391:

; 369  :  	case TIFFTAG_PIXAR_WRAPMODES:
; 370  :  		_TIFFsetString(&td->td_wrapmodes, va_arg(ap, char*));

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	add	ecx, 292				; 00000124H
	push	ecx
	call	__TIFFsetString
	add	esp, 8

; 371  :  		break;

	jmp	$L65927
$L66399:

; 372  :  	case TIFFTAG_PIXAR_FOVCOT:
; 373  :  		td->td_fovcot = (float) va_arg(ap, dblparam_t);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 8
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	sub	eax, 8
	fld	QWORD PTR [eax]
	mov	ecx, DWORD PTR _td$[ebp]
	fstp	DWORD PTR [ecx+296]

; 374  :  		break;

	jmp	$L65927
$L66408:

; 375  :  	case TIFFTAG_PIXAR_MATRIX_WORLDTOSCREEN:
; 376  :  		_TIFFsetFloatArray(&td->td_matrixWorldToScreen,
; 377  :  			va_arg(ap, float*), 16);

	push	16					; 00000010H
	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	push	ecx
	mov	edx, DWORD PTR _td$[ebp]
	add	edx, 300				; 0000012cH
	push	edx
	call	__TIFFsetFloatArray
	add	esp, 12					; 0000000cH

; 378  :  		break;

	jmp	$L65927
$L66416:

; 379  :  	case TIFFTAG_PIXAR_MATRIX_WORLDTOCAMERA:
; 380  :  		_TIFFsetFloatArray(&td->td_matrixWorldToCamera,
; 381  :  			va_arg(ap, float*), 16);

	push	16					; 00000010H
	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	add	eax, 304				; 00000130H
	push	eax
	call	__TIFFsetFloatArray
	add	esp, 12					; 0000000cH

; 382  :  		break;

	jmp	$L65927
$L66424:

; 383  :  	/* End Pixar Tags */	       
; 384  : 
; 385  : #if SUBIFD_SUPPORT
; 386  : 	case TIFFTAG_SUBIFD:
; 387  : 		if ((tif->tif_flags & TIFF_INSUBIFD) == 0) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 8192				; 00002000H
	test	edx, edx
	jne	SHORT $L66425

; 388  : 			td->td_nsubifd = (uint16) va_arg(ap, int);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _ap$[ebp]
	mov	ax, WORD PTR [edx-4]
	mov	WORD PTR [ecx+192], ax

; 389  : 			_TIFFsetLongArray(&td->td_subifd, va_arg(ap, uint32*),
; 390  : 			    (long) td->td_nsubifd);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+192]
	push	edx
	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	add	eax, 196				; 000000c4H
	push	eax
	call	__TIFFsetLongArray
	add	esp, 12					; 0000000cH

; 391  : 		} else {

	jmp	SHORT $L66442
$L66425:

; 392  : 			TIFFError(tif->tif_name, "Sorry, cannot nest SubIFDs");

	push	OFFSET FLAT:$SG66443
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 8

; 393  : 			status = 0;

	mov	DWORD PTR _status$[ebp], 0
$L66442:

; 395  : 		break;

	jmp	$L65927
$L66444:

; 396  : #endif
; 397  : #ifdef YCBCR_SUPPORT
; 398  : 	case TIFFTAG_YCBCRCOEFFICIENTS:
; 399  : 		_TIFFsetFloatArray(&td->td_ycbcrcoeffs, va_arg(ap, float*), 3);

	push	3
	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	add	eax, 200				; 000000c8H
	push	eax
	call	__TIFFsetFloatArray
	add	esp, 12					; 0000000cH

; 400  : 		break;

	jmp	$L65927
$L66452:

; 401  : 	case TIFFTAG_YCBCRPOSITIONING:
; 402  : 		td->td_ycbcrpositioning = (uint16) va_arg(ap, int);

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _ap$[ebp]
	mov	cx, WORD PTR [eax-4]
	mov	WORD PTR [edx+208], cx

; 403  : 		break;

	jmp	$L65927
$L66461:

; 404  : 	case TIFFTAG_YCBCRSUBSAMPLING:
; 405  : 		td->td_ycbcrsubsampling[0] = (uint16) va_arg(ap, int);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	dx, WORD PTR [ecx-4]
	mov	WORD PTR [eax+204], dx

; 406  : 		td->td_ycbcrsubsampling[1] = (uint16) va_arg(ap, int);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _ap$[ebp]
	mov	ax, WORD PTR [edx-4]
	mov	WORD PTR [ecx+206], ax

; 407  : 		break;

	jmp	$L65927
$L66478:

; 408  : #endif
; 409  : #ifdef COLORIMETRY_SUPPORT
; 410  : 	case TIFFTAG_WHITEPOINT:
; 411  : 		_TIFFsetFloatArray(&td->td_whitepoint, va_arg(ap, float*), 2);

	push	2
	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	add	ecx, 212				; 000000d4H
	push	ecx
	call	__TIFFsetFloatArray
	add	esp, 12					; 0000000cH

; 412  : 		break;

	jmp	$L65927
$L66486:

; 413  : 	case TIFFTAG_PRIMARYCHROMATICITIES:
; 414  : 		_TIFFsetFloatArray(&td->td_primarychromas, va_arg(ap, float*), 6);

	push	6
	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	push	ecx
	mov	edx, DWORD PTR _td$[ebp]
	add	edx, 216				; 000000d8H
	push	edx
	call	__TIFFsetFloatArray
	add	esp, 12					; 0000000cH

; 415  : 		break;

	jmp	$L65927
$L66494:

; 416  : 	case TIFFTAG_TRANSFERFUNCTION:
; 417  : 		v = (td->td_samplesperpixel - td->td_extrasamples) > 1 ? 3 : 1;

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+54]
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+120]
	sub	ecx, eax
	xor	edx, edx
	cmp	ecx, 1
	setle	dl
	dec	edx
	and	edx, 2
	add	edx, 1
	mov	DWORD PTR _v$[ebp], edx

; 418  : 		for (i = 0; i < v; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L66495
$L66496:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L66495:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _v$[ebp]
	jge	SHORT $L66497

; 419  : 			_TIFFsetShortArray(&td->td_transferfunction[i],
; 420  : 			    va_arg(ap, uint16*), 1L<<td->td_bitspersample);

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+40]
	mov	ecx, eax
	mov	edx, 1
	shl	edx, cl
	push	edx
	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	push	edx
	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _td$[ebp]
	lea	edx, DWORD PTR [ecx+eax*4+224]
	push	edx
	call	__TIFFsetShortArray
	add	esp, 12					; 0000000cH
	jmp	SHORT $L66496
$L66497:

; 421  : 		break;

	jmp	$L65927
$L66505:

; 422  : 	case TIFFTAG_REFERENCEBLACKWHITE:
; 423  : 		/* XXX should check for null range */
; 424  : 		_TIFFsetFloatArray(&td->td_refblackwhite, va_arg(ap, float*), 6);

	push	6
	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	add	eax, 220				; 000000dcH
	push	eax
	call	__TIFFsetFloatArray
	add	esp, 12					; 0000000cH

; 425  : 		break;

	jmp	$L65927
$L66513:

; 426  : #endif
; 427  : #ifdef CMYK_SUPPORT
; 428  : 	case TIFFTAG_INKSET:
; 429  : 		td->td_inkset = (uint16) va_arg(ap, int);

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _ap$[ebp]
	mov	cx, WORD PTR [eax-4]
	mov	WORD PTR [edx+236], cx

; 430  : 		break;

	jmp	$L65927
$L66522:

; 431  : 	case TIFFTAG_DOTRANGE:
; 432  : 		/* XXX should check for null range */
; 433  : 		td->td_dotrange[0] = (uint16) va_arg(ap, int);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	dx, WORD PTR [ecx-4]
	mov	WORD PTR [eax+240], dx

; 434  : 		td->td_dotrange[1] = (uint16) va_arg(ap, int);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _ap$[ebp]
	mov	ax, WORD PTR [edx-4]
	mov	WORD PTR [ecx+242], ax

; 435  : 		break;

	jmp	$L65927
$L66539:

; 436  : 	case TIFFTAG_INKNAMES:
; 437  : 		i = va_arg(ap, int);

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	DWORD PTR _i$[ebp], eax

; 438  : 		s = va_arg(ap, char*);

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	DWORD PTR _s$[ebp], eax

; 439  : 		i = checkInkNamesString(tif, i, s);

	mov	ecx, DWORD PTR _s$[ebp]
	push	ecx
	mov	edx, DWORD PTR _i$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_checkInkNamesString
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _i$[ebp], eax

; 440  :                 status = i > 0;

	xor	ecx, ecx
	cmp	DWORD PTR _i$[ebp], 0
	setg	cl
	mov	DWORD PTR _status$[ebp], ecx

; 441  : 		if( i > 0 ) {

	cmp	DWORD PTR _i$[ebp], 0
	jle	SHORT $L66554

; 442  : 			_TIFFsetNString(&td->td_inknames, s, i);

	mov	edx, DWORD PTR _i$[ebp]
	push	edx
	mov	eax, DWORD PTR _s$[ebp]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	add	ecx, 248				; 000000f8H
	push	ecx
	call	__TIFFsetNString
	add	esp, 12					; 0000000cH

; 443  : 			td->td_inknameslen = i;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _i$[ebp]
	mov	DWORD PTR [edx+244], eax
$L66554:

; 445  : 		break;

	jmp	$L65927
$L66555:

; 446  : 	case TIFFTAG_NUMBEROFINKS:
; 447  : 		td->td_ninks = (uint16) va_arg(ap, int);

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _ap$[ebp]
	mov	cx, WORD PTR [eax-4]
	mov	WORD PTR [edx+238], cx

; 448  : 		break;

	jmp	$L65927
$L66564:

; 449  : 	case TIFFTAG_TARGETPRINTER:
; 450  : 		_TIFFsetString(&td->td_targetprinter, va_arg(ap, char*));

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	push	ecx
	mov	edx, DWORD PTR _td$[ebp]
	add	edx, 252				; 000000fcH
	push	edx
	call	__TIFFsetString
	add	esp, 8

; 451  : 		break;

	jmp	$L65927
$L66572:

; 452  : #endif
; 453  : #ifdef ICC_SUPPORT
; 454  : 	case TIFFTAG_ICCPROFILE:
; 455  : 		td->td_profileLength = (uint32) va_arg(ap, uint32);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	DWORD PTR [ecx+256], eax

; 456  : 		_TIFFsetByteArray(&td->td_profileData, va_arg(ap, void*),
; 457  : 		    td->td_profileLength);

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+256]
	push	edx
	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	add	eax, 260				; 00000104H
	push	eax
	call	__TIFFsetByteArray
	add	esp, 12					; 0000000cH

; 458  : 		break;

	jmp	$L65927
$L66588:

; 459  : #endif
; 460  : #ifdef PHOTOSHOP_SUPPORT
; 461  :  	case TIFFTAG_PHOTOSHOP:
; 462  :   		td->td_photoshopLength = (uint32) va_arg(ap, uint32);

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	DWORD PTR [edx+264], ecx

; 463  :   		_TIFFsetByteArray (&td->td_photoshopData, va_arg(ap, void*),
; 464  :  			td->td_photoshopLength);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+264]
	push	eax
	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	add	ecx, 268				; 0000010cH
	push	ecx
	call	__TIFFsetByteArray
	add	esp, 12					; 0000000cH

; 465  :  		break;

	jmp	$L65927
$L66604:

; 466  : #endif
; 467  : #ifdef IPTC_SUPPORT
; 468  :     case TIFFTAG_RICHTIFFIPTC: 
; 469  :   		td->td_richtiffiptcLength = (uint32) va_arg(ap, uint32);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	DWORD PTR [eax+272], edx

; 470  : #ifdef PHOTOSHOP_SUPPORT
; 471  :   		_TIFFsetLongArray ((uint32**)&td->td_richtiffiptcData, va_arg(ap, uint32*),
; 472  :  			td->td_richtiffiptcLength);

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+272]
	push	ecx
	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	push	ecx
	mov	edx, DWORD PTR _td$[ebp]
	add	edx, 276				; 00000114H
	push	edx
	call	__TIFFsetLongArray
	add	esp, 12					; 0000000cH

; 473  : #else
; 474  :   		_TIFFsetByteArray (&td->td_photoshopData, va_arg(ap, void*),
; 475  :  			td->td_photoshopLength);
; 476  : #endif
; 477  :  		break;

	jmp	SHORT $L65927
$L66621:

; 478  : #endif
; 479  : 	default:
; 480  : 		/*
; 481  : 		 * This can happen if multiple images are open with
; 482  : 		 * different codecs which have private tags.  The
; 483  : 		 * global tag information table may then have tags
; 484  : 		 * that are valid for one file but not the other. 
; 485  : 		 * If the client tries to set a tag that is not valid
; 486  : 		 * for the image's codec then we'll arrive here.  This
; 487  : 		 * happens, for example, when tiffcp is used to convert
; 488  : 		 * between compression schemes and codec-specific tags
; 489  : 		 * are blindly copied.
; 490  : 		 */
; 491  : 		TIFFError("TIFFSetField",
; 492  : 		    "%s: Invalid %stag \"%s\" (not supported by codec)",
; 493  : 		    tif->tif_name, isPseudoTag(tag) ? "pseduo-" : "",
; 494  : 		    _TIFFFieldWithTag(tif, tag)->field_name);

	cmp	DWORD PTR _tag$[ebp], 65535		; 0000ffffH
	jbe	SHORT $L67612
	mov	DWORD PTR -48+[ebp], OFFSET FLAT:$SG66622
	jmp	SHORT $L67613
$L67612:
	mov	DWORD PTR -48+[ebp], OFFSET FLAT:$SG66623
$L67613:
	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	__TIFFFieldWithTag
	add	esp, 8
	mov	edx, DWORD PTR [eax+16]
	push	edx
	mov	eax, DWORD PTR -48+[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	push	OFFSET FLAT:$SG66624
	push	OFFSET FLAT:$SG66625
	call	_TIFFError
	add	esp, 20					; 00000014H

; 495  : 		status = 0;

	mov	DWORD PTR _status$[ebp], 0
$L65927:

; 498  : 	if (status) {

	cmp	DWORD PTR _status$[ebp], 0
	je	SHORT $L66626

; 499  : 		TIFFSetFieldBit(tif, _TIFFFieldWithTag(tif, tag)->field_bit);

	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	__TIFFFieldWithTag
	add	esp, 8
	xor	edx, edx
	mov	dx, WORD PTR [eax+12]
	mov	eax, edx
	cdq
	and	edx, 31					; 0000001fH
	add	eax, edx
	sar	eax, 5
	mov	ecx, DWORD PTR _tif$[ebp]
	lea	edx, DWORD PTR [ecx+eax*4+24]
	mov	DWORD PTR -52+[ebp], edx
	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	__TIFFFieldWithTag
	add	esp, 8
	xor	edx, edx
	mov	dx, WORD PTR [eax+12]
	mov	ecx, edx
	and	ecx, 31					; 0000001fH
	mov	eax, 1
	shl	eax, cl
	mov	ecx, DWORD PTR -52+[ebp]
	mov	edx, DWORD PTR [ecx]
	or	edx, eax
	mov	eax, DWORD PTR -52+[ebp]
	mov	DWORD PTR [eax], edx

; 500  : 		tif->tif_flags |= TIFF_DIRTYDIRECT;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	or	edx, 8
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+12], edx
$L66626:

; 502  : 	va_end(ap);

	mov	DWORD PTR _ap$[ebp], 0

; 503  : 	return (status);

	mov	eax, DWORD PTR _status$[ebp]
	jmp	$L65918
$badvalue$66009:

; 504  : badvalue:
; 505  : 	TIFFError(tif->tif_name, "%d: Bad value for \"%s\"", v,
; 506  : 	    _TIFFFieldWithTag(tif, tag)->field_name);

	mov	ecx, DWORD PTR _tag$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	__TIFFFieldWithTag
	add	esp, 8
	mov	eax, DWORD PTR [eax+16]
	push	eax
	mov	ecx, DWORD PTR _v$[ebp]
	push	ecx
	push	OFFSET FLAT:$SG66629
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 16					; 00000010H

; 507  : 	va_end(ap);

	mov	DWORD PTR _ap$[ebp], 0

; 508  : 	return (0);

	xor	eax, eax
	jmp	SHORT $L65918
$badvalue32$66115:

; 509  : badvalue32:
; 510  : 	TIFFError(tif->tif_name, "%ld: Bad value for \"%s\"", v32,
; 511  : 	    _TIFFFieldWithTag(tif, tag)->field_name);

	mov	ecx, DWORD PTR _tag$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	__TIFFFieldWithTag
	add	esp, 8
	mov	eax, DWORD PTR [eax+16]
	push	eax
	mov	ecx, DWORD PTR _v32$[ebp]
	push	ecx
	push	OFFSET FLAT:$SG66631
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 16					; 00000010H

; 512  : 	va_end(ap);

	mov	DWORD PTR _ap$[ebp], 0

; 513  : 	return (0);

	xor	eax, eax
	jmp	SHORT $L65918
$badvaluedbl$66366:

; 514  : badvaluedbl:
; 515  : 	TIFFError(tif->tif_name, "%f: Bad value for \"%s\"", d,
; 516  : 	    _TIFFFieldWithTag(tif, tag)->field_name);

	mov	ecx, DWORD PTR _tag$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	__TIFFFieldWithTag
	add	esp, 8
	mov	eax, DWORD PTR [eax+16]
	push	eax
	mov	ecx, DWORD PTR _d$[ebp+4]
	push	ecx
	mov	edx, DWORD PTR _d$[ebp]
	push	edx
	push	OFFSET FLAT:$SG66633
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 20					; 00000014H

; 517  : 	va_end(ap);

	mov	DWORD PTR _ap$[ebp], 0

; 518  : 	return (0);

	xor	eax, eax
$L65918:

; 519  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L67625:
	DD	$L65930
	DD	$L65938
	DD	$L65946
	DD	$L65954
	DD	$L65969
	DD	$L65982
	DD	$L65991
	DD	$L66000
	DD	$L66011
	DD	$L66043
	DD	$L66051
	DD	$L66059
	DD	$L66083
	DD	$L66096
	DD	$L66106
	DD	$L66118
	DD	$L66127
	DD	$L66154
	DD	$L66163
	DD	$L66172
	DD	$L66182
	DD	$L66190
	DD	$L66199
	DD	$L66208
	DD	$L66219
	DD	$L66621
$L67624:
	DB	0
	DB	25					; 00000019H
	DB	1
	DB	2
	DB	3
	DB	4
	DB	25					; 00000019H
	DB	25					; 00000019H
	DB	5
	DB	6
	DB	25					; 00000019H
	DB	25					; 00000019H
	DB	7
	DB	25					; 00000019H
	DB	25					; 00000019H
	DB	8
	DB	9
	DB	10					; 0000000aH
	DB	11					; 0000000bH
	DB	25					; 00000019H
	DB	12					; 0000000cH
	DB	25					; 00000019H
	DB	25					; 00000019H
	DB	13					; 0000000dH
	DB	14					; 0000000eH
	DB	25					; 00000019H
	DB	15					; 0000000fH
	DB	16					; 00000010H
	DB	17					; 00000011H
	DB	18					; 00000012H
	DB	19					; 00000013H
	DB	20					; 00000014H
	DB	21					; 00000015H
	DB	22					; 00000016H
	DB	25					; 00000019H
	DB	25					; 00000019H
	DB	25					; 00000019H
	DB	25					; 00000019H
	DB	25					; 00000019H
	DB	25					; 00000019H
	DB	25					; 00000019H
	DB	25					; 00000019H
	DB	23					; 00000017H
	DB	24					; 00000018H
$L67627:
	DD	$L66067
	DD	$L66027
	DD	$L66019
	DD	$L66035
	DD	$L66478
	DD	$L66486
	DD	$L66253
	DD	$L66236
	DD	$L66289
	DD	$L66300
	DD	$L66424
	DD	$L66513
	DD	$L66539
	DD	$L66555
	DD	$L66522
	DD	$L66564
	DD	$L66276
	DD	$L66338
	DD	$L66136
	DD	$L66145
	DD	$L66621
$L67626:
	DB	0
	DB	1
	DB	20					; 00000014H
	DB	20					; 00000014H
	DB	20					; 00000014H
	DB	20					; 00000014H
	DB	20					; 00000014H
	DB	20					; 00000014H
	DB	20					; 00000014H
	DB	20					; 00000014H
	DB	2
	DB	3
	DB	20					; 00000014H
	DB	4
	DB	5
	DB	6
	DB	7
	DB	8
	DB	9
	DB	20					; 00000014H
	DB	20					; 00000014H
	DB	20					; 00000014H
	DB	20					; 00000014H
	DB	20					; 00000014H
	DB	20					; 00000014H
	DB	10					; 0000000aH
	DB	20					; 00000014H
	DB	11					; 0000000bH
	DB	12					; 0000000cH
	DB	13					; 0000000dH
	DB	20					; 00000014H
	DB	14					; 0000000eH
	DB	15					; 0000000fH
	DB	16					; 00000010H
	DB	17					; 00000011H
	DB	18					; 00000012H
	DB	19					; 00000013H
$L67628:
	DD	$L66391
	DD	$L66399
	DD	$L66408
	DD	$L66416
$L67629:
	DD	$L66332
	DD	$L66333
	DD	$L66334
	DD	$L66335
__TIFFVSetField ENDP
_td$ = 8
_ap$ = 12
_v$ = 16
_va$ = -4
_i$ = -8
_setExtraSamples PROC NEAR

; 69   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 70   : 	uint16* va;
; 71   : 	int i;
; 72   : 
; 73   : 	*v = va_arg(ap, int);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _v$[ebp]
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	DWORD PTR [ecx], eax

; 74   : 	if ((uint16) *v > td->td_samplesperpixel)

	mov	ecx, DWORD PTR _v$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx]
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+54]
	cmp	edx, ecx
	jle	SHORT $L65873

; 75   : 		return (0);

	xor	eax, eax
	jmp	$L65862
$L65873:

; 76   : 	va = va_arg(ap, uint16*);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	DWORD PTR _va$[ebp], ecx

; 77   : 	if (*v > 0 && va == NULL)		/* typically missing param */

	mov	edx, DWORD PTR _v$[ebp]
	cmp	DWORD PTR [edx], 0
	jle	SHORT $L65882
	cmp	DWORD PTR _va$[ebp], 0
	jne	SHORT $L65882

; 78   : 		return (0);

	xor	eax, eax
	jmp	SHORT $L65862
$L65882:

; 79   : 	for (i = 0; i < *v; i++)

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L65883
$L65884:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L65883:
	mov	ecx, DWORD PTR _v$[ebp]
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR [ecx]
	jge	SHORT $L65885

; 80   : 		if (va[i] > EXTRASAMPLE_UNASSALPHA)

	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _va$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+eax*2]
	cmp	edx, 2
	jle	SHORT $L65886

; 81   : 			return (0);

	xor	eax, eax
	jmp	SHORT $L65862
$L65886:

; 82   : 	td->td_extrasamples = (uint16) *v;

	jmp	SHORT $L65884
$L65885:
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _v$[ebp]
	mov	dx, WORD PTR [ecx]
	mov	WORD PTR [eax+120], dx

; 83   : 	_TIFFsetShortArray(&td->td_sampleinfo, va, td->td_extrasamples);

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+120]
	push	ecx
	mov	edx, DWORD PTR _va$[ebp]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	add	eax, 124				; 0000007cH
	push	eax
	call	__TIFFsetShortArray
	add	esp, 12					; 0000000cH

; 84   : 	return (1);

	mov	eax, 1
$L65862:

; 85   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_setExtraSamples ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+1
$SG65909 DB	'%s: Invalid InkNames value; expecting %d names, found %d'
	DB	00H
	ORG $+3
$SG65910 DB	'TIFFSetField', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_slen$ = 12
_s$ = 16
_td$ = -8
_i$ = -4
_ep$65899 = -16
_cp$65900 = -12
_checkInkNamesString PROC NEAR

; 90   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 91   : 	TIFFDirectory* td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 92   : 	int i = td->td_samplesperpixel;

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+54]
	mov	DWORD PTR _i$[ebp], edx

; 93   : 
; 94   : 	if (slen > 0) {

	cmp	DWORD PTR _slen$[ebp], 0
	jle	SHORT $bad$65908

; 95   : 		const char* ep = s+slen;

	mov	eax, DWORD PTR _s$[ebp]
	add	eax, DWORD PTR _slen$[ebp]
	mov	DWORD PTR _ep$65899[ebp], eax

; 96   : 		const char* cp = s;

	mov	ecx, DWORD PTR _s$[ebp]
	mov	DWORD PTR _cp$65900[ebp], ecx

; 97   : 		for (; i > 0; i--) {

	jmp	SHORT $L65901
$L65902:
	mov	edx, DWORD PTR _i$[ebp]
	sub	edx, 1
	mov	DWORD PTR _i$[ebp], edx
$L65901:
	cmp	DWORD PTR _i$[ebp], 0
	jle	SHORT $L65903

; 98   : 			for (; *cp != '\0'; cp++)

	jmp	SHORT $L65904
$L65905:
	mov	eax, DWORD PTR _cp$65900[ebp]
	add	eax, 1
	mov	DWORD PTR _cp$65900[ebp], eax
$L65904:
	mov	ecx, DWORD PTR _cp$65900[ebp]
	movsx	edx, BYTE PTR [ecx]
	test	edx, edx
	je	SHORT $L65906

; 99   : 				if (cp >= ep)

	mov	eax, DWORD PTR _cp$65900[ebp]
	cmp	eax, DWORD PTR _ep$65899[ebp]
	jb	SHORT $L65907

; 100  : 					goto bad;

	jmp	SHORT $bad$65908
$L65907:

; 101  : 			cp++;				/* skip \0 */

	jmp	SHORT $L65905
$L65906:
	mov	ecx, DWORD PTR _cp$65900[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$65900[ebp], ecx

; 102  : 		}

	jmp	SHORT $L65902
$L65903:

; 103  : 		return (cp-s);

	mov	eax, DWORD PTR _cp$65900[ebp]
	sub	eax, DWORD PTR _s$[ebp]
	jmp	SHORT $L65895
$bad$65908:

; 105  : bad:
; 106  : 	TIFFError("TIFFSetField",
; 107  : 	    "%s: Invalid InkNames value; expecting %d names, found %d",
; 108  : 	    tif->tif_name,
; 109  : 	    td->td_samplesperpixel,
; 110  : 	    td->td_samplesperpixel-i);

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+54]
	sub	eax, DWORD PTR _i$[ebp]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+54]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG65909
	push	OFFSET FLAT:$SG65910
	call	_TIFFError
	add	esp, 20					; 00000014H

; 111  : 	return (0);

	xor	eax, eax
$L65895:

; 112  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_checkInkNamesString ENDP
_TEXT	ENDS
_BSS	SEGMENT
	ALIGN	4

$SG67349 DB	01H DUP (?)
_BSS	ENDS
_DATA	SEGMENT
	ORG $+3
$SG67348 DB	'pseudo-', 00H
$SG67350 DB	'%s: Invalid %stag "%s" (not supported by codec)', 00H
$SG67351 DB	'TIFFGetField', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_tag$ = 12
_ap$ = 16
_td$ = -4
__TIFFVGetField PROC NEAR

; 589  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 20					; 00000014H

; 590  : 	TIFFDirectory* td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 591  : 
; 592  : 	switch (tag) {

	mov	ecx, DWORD PTR _tag$[ebp]
	mov	DWORD PTR -8+[ebp], ecx
	cmp	DWORD PTR -8+[ebp], 301			; 0000012dH
	ja	SHORT $L67638
	cmp	DWORD PTR -8+[ebp], 301			; 0000012dH
	je	$L67168
	mov	edx, DWORD PTR -8+[ebp]
	sub	edx, 254				; 000000feH
	mov	DWORD PTR -8+[ebp], edx
	cmp	DWORD PTR -8+[ebp], 43			; 0000002bH
	ja	$L67347
	mov	ecx, DWORD PTR -8+[ebp]
	xor	eax, eax
	mov	al, BYTE PTR $L67646[ecx]
	jmp	DWORD PTR $L67647[eax*4]
$L67638:
	cmp	DWORD PTR -8+[ebp], 341			; 00000155H
	ja	SHORT $L67639
	cmp	DWORD PTR -8+[ebp], 341			; 00000155H
	je	$L66866
	mov	edx, DWORD PTR -8+[ebp]
	sub	edx, 305				; 00000131H
	mov	DWORD PTR -8+[ebp], edx
	cmp	DWORD PTR -8+[ebp], 35			; 00000023H
	ja	$L67347
	mov	ecx, DWORD PTR -8+[ebp]
	xor	eax, eax
	mov	al, BYTE PTR $L67648[ecx]
	jmp	DWORD PTR $L67649[eax*4]
$L67639:
	cmp	DWORD PTR -8+[ebp], 33302		; 00008216H
	ja	$L67640
	cmp	DWORD PTR -8+[ebp], 33302		; 00008216H
	je	$L67307
	cmp	DWORD PTR -8+[ebp], 32996		; 000080e4H
	ja	SHORT $L67641
	cmp	DWORD PTR -8+[ebp], 32996		; 000080e4H
	je	$L67045
	cmp	DWORD PTR -8+[ebp], 531			; 00000213H
	ja	SHORT $L67642
	cmp	DWORD PTR -8+[ebp], 531			; 00000213H
	je	$L67129
	cmp	DWORD PTR -8+[ebp], 529			; 00000211H
	je	$L67121
	cmp	DWORD PTR -8+[ebp], 530			; 00000212H
	je	$L67137
	jmp	$L67347
$L67642:
	cmp	DWORD PTR -8+[ebp], 532			; 00000214H
	je	$L67191
	cmp	DWORD PTR -8+[ebp], 32995		; 000080e3H
	je	$L66998
	jmp	$L67347
$L67641:
	cmp	DWORD PTR -8+[ebp], 33300		; 00008214H
	ja	SHORT $L67643
	cmp	DWORD PTR -8+[ebp], 33300		; 00008214H
	je	$L67291
	cmp	DWORD PTR -8+[ebp], 32997		; 000080e5H
	je	$L67090
	cmp	DWORD PTR -8+[ebp], 32998		; 000080e6H
	je	$L67037
	jmp	$L67347
$L67643:
	cmp	DWORD PTR -8+[ebp], 33301		; 00008215H
	je	$L67299
	jmp	$L67347
$L67640:
	cmp	DWORD PTR -8+[ebp], 33432		; 00008298H
	ja	SHORT $L67644
	cmp	DWORD PTR -8+[ebp], 33432		; 00008298H
	je	$L66810
	mov	edx, DWORD PTR -8+[ebp]
	sub	edx, 33303				; 00008217H
	mov	DWORD PTR -8+[ebp], edx
	cmp	DWORD PTR -8+[ebp], 3
	ja	$L67347
	mov	eax, DWORD PTR -8+[ebp]
	jmp	DWORD PTR $L67650[eax*4]
$L67644:
	cmp	DWORD PTR -8+[ebp], 34675		; 00008773H
	ja	SHORT $L67645
	cmp	DWORD PTR -8+[ebp], 34675		; 00008773H
	je	$L67246
	cmp	DWORD PTR -8+[ebp], 33723		; 000083bbH
	je	$L67276
	cmp	DWORD PTR -8+[ebp], 34377		; 00008649H
	je	$L67261
	jmp	$L67347
$L67645:
	cmp	DWORD PTR -8+[ebp], 37439		; 0000923fH
	je	$L67098
	jmp	$L67347
$L66682:

; 593  : 	case TIFFTAG_SUBFILETYPE:
; 594  : 		*va_arg(ap, uint32*) = td->td_subfiletype;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+36]
	mov	DWORD PTR [eax], edx

; 595  : 		break;

	jmp	$L66679
$L66690:

; 596  : 	case TIFFTAG_IMAGEWIDTH:
; 597  : 		*va_arg(ap, uint32*) = td->td_imagewidth;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR [edx], ecx

; 598  : 		break;

	jmp	$L66679
$L66698:

; 599  : 	case TIFFTAG_IMAGELENGTH:
; 600  : 		*va_arg(ap, uint32*) = td->td_imagelength;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+16]
	mov	DWORD PTR [ecx], eax

; 601  : 		break;

	jmp	$L66679
$L66706:

; 602  : 	case TIFFTAG_BITSPERSAMPLE:
; 603  : 		*va_arg(ap, uint16*) = td->td_bitspersample;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	dx, WORD PTR [ecx+40]
	mov	WORD PTR [eax], dx

; 604  : 		break;

	jmp	$L66679
$L66714:

; 605  : 	case TIFFTAG_COMPRESSION:
; 606  : 		*va_arg(ap, uint16*) = td->td_compression;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	cx, WORD PTR [eax+44]
	mov	WORD PTR [edx], cx

; 607  : 		break;

	jmp	$L66679
$L66722:

; 608  : 	case TIFFTAG_PHOTOMETRIC:
; 609  : 		*va_arg(ap, uint16*) = td->td_photometric;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	ax, WORD PTR [edx+46]
	mov	WORD PTR [ecx], ax

; 610  : 		break;

	jmp	$L66679
$L66730:

; 611  : 	case TIFFTAG_THRESHHOLDING:
; 612  : 		*va_arg(ap, uint16*) = td->td_threshholding;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	dx, WORD PTR [ecx+48]
	mov	WORD PTR [eax], dx

; 613  : 		break;

	jmp	$L66679
$L66738:

; 614  : 	case TIFFTAG_FILLORDER:
; 615  : 		*va_arg(ap, uint16*) = td->td_fillorder;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	cx, WORD PTR [eax+50]
	mov	WORD PTR [edx], cx

; 616  : 		break;

	jmp	$L66679
$L66746:

; 617  : 	case TIFFTAG_DOCUMENTNAME:
; 618  : 		*va_arg(ap, char**) = td->td_documentname;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+136]
	mov	DWORD PTR [ecx], eax

; 619  : 		break;

	jmp	$L66679
$L66754:

; 620  : 	case TIFFTAG_ARTIST:
; 621  : 		*va_arg(ap, char**) = td->td_artist;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+140]
	mov	DWORD PTR [eax], edx

; 622  : 		break;

	jmp	$L66679
$L66762:

; 623  : 	case TIFFTAG_DATETIME:
; 624  : 		*va_arg(ap, char**) = td->td_datetime;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+144]
	mov	DWORD PTR [edx], ecx

; 625  : 		break;

	jmp	$L66679
$L66770:

; 626  : 	case TIFFTAG_HOSTCOMPUTER:
; 627  : 		*va_arg(ap, char**) = td->td_hostcomputer;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+148]
	mov	DWORD PTR [ecx], eax

; 628  : 		break;

	jmp	$L66679
$L66778:

; 629  : 	case TIFFTAG_IMAGEDESCRIPTION:
; 630  : 		*va_arg(ap, char**) = td->td_imagedescription;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+152]
	mov	DWORD PTR [eax], edx

; 631  : 		break;

	jmp	$L66679
$L66786:

; 632  : 	case TIFFTAG_MAKE:
; 633  : 		*va_arg(ap, char**) = td->td_make;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+156]
	mov	DWORD PTR [edx], ecx

; 634  : 		break;

	jmp	$L66679
$L66794:

; 635  : 	case TIFFTAG_MODEL:
; 636  : 		*va_arg(ap, char**) = td->td_model;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+160]
	mov	DWORD PTR [ecx], eax

; 637  : 		break;

	jmp	$L66679
$L66802:

; 638  : 	case TIFFTAG_SOFTWARE:
; 639  : 		*va_arg(ap, char**) = td->td_software;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+164]
	mov	DWORD PTR [eax], edx

; 640  : 		break;

	jmp	$L66679
$L66810:

; 641  : 	case TIFFTAG_COPYRIGHT:
; 642  : 		*va_arg(ap, char**) = td->td_copyright;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+168]
	mov	DWORD PTR [edx], ecx

; 643  : 		break;

	jmp	$L66679
$L66818:

; 644  : 	case TIFFTAG_ORIENTATION:
; 645  : 		*va_arg(ap, uint16*) = td->td_orientation;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	ax, WORD PTR [edx+52]
	mov	WORD PTR [ecx], ax

; 646  : 		break;

	jmp	$L66679
$L66826:

; 647  : 	case TIFFTAG_SAMPLESPERPIXEL:
; 648  : 		*va_arg(ap, uint16*) = td->td_samplesperpixel;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	dx, WORD PTR [ecx+54]
	mov	WORD PTR [eax], dx

; 649  : 		break;

	jmp	$L66679
$L66834:

; 650  : 	case TIFFTAG_ROWSPERSTRIP:
; 651  : 		*va_arg(ap, uint32*) = td->td_rowsperstrip;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	DWORD PTR [edx], ecx

; 652  : 		break;

	jmp	$L66679
$L66842:

; 653  : 	case TIFFTAG_MINSAMPLEVALUE:
; 654  : 		*va_arg(ap, uint16*) = td->td_minsamplevalue;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	ax, WORD PTR [edx+60]
	mov	WORD PTR [ecx], ax

; 655  : 		break;

	jmp	$L66679
$L66850:

; 656  : 	case TIFFTAG_MAXSAMPLEVALUE:
; 657  : 		*va_arg(ap, uint16*) = td->td_maxsamplevalue;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	dx, WORD PTR [ecx+62]
	mov	WORD PTR [eax], dx

; 658  : 		break;

	jmp	$L66679
$L66858:

; 659  : 	case TIFFTAG_SMINSAMPLEVALUE:
; 660  : 		*va_arg(ap, double*) = td->td_sminsamplevalue;

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [edx-4]
	mov	edx, DWORD PTR [eax+64]
	mov	DWORD PTR [ecx], edx
	mov	eax, DWORD PTR [eax+68]
	mov	DWORD PTR [ecx+4], eax

; 661  : 		break;

	jmp	$L66679
$L66866:

; 662  : 	case TIFFTAG_SMAXSAMPLEVALUE:
; 663  : 		*va_arg(ap, double*) = td->td_smaxsamplevalue;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [eax-4]
	mov	eax, DWORD PTR [ecx+72]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR [ecx+76]
	mov	DWORD PTR [edx+4], ecx

; 664  : 		break;

	jmp	$L66679
$L66874:

; 665  : 	case TIFFTAG_XRESOLUTION:
; 666  : 		*va_arg(ap, float*) = td->td_xresolution;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+80]
	mov	DWORD PTR [ecx], eax

; 667  : 		break;

	jmp	$L66679
$L66882:

; 668  : 	case TIFFTAG_YRESOLUTION:
; 669  : 		*va_arg(ap, float*) = td->td_yresolution;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+84]
	mov	DWORD PTR [eax], edx

; 670  : 		break;

	jmp	$L66679
$L66890:

; 671  : 	case TIFFTAG_PLANARCONFIG:
; 672  : 		*va_arg(ap, uint16*) = td->td_planarconfig;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	cx, WORD PTR [eax+90]
	mov	WORD PTR [edx], cx

; 673  : 		break;

	jmp	$L66679
$L66898:

; 674  : 	case TIFFTAG_XPOSITION:
; 675  : 		*va_arg(ap, float*) = td->td_xposition;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+92]
	mov	DWORD PTR [ecx], eax

; 676  : 		break;

	jmp	$L66679
$L66906:

; 677  : 	case TIFFTAG_YPOSITION:
; 678  : 		*va_arg(ap, float*) = td->td_yposition;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+96]
	mov	DWORD PTR [eax], edx

; 679  : 		break;

	jmp	$L66679
$L66914:

; 680  : 	case TIFFTAG_PAGENAME:
; 681  : 		*va_arg(ap, char**) = td->td_pagename;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+172]
	mov	DWORD PTR [edx], ecx

; 682  : 		break;

	jmp	$L66679
$L66922:

; 683  : 	case TIFFTAG_RESOLUTIONUNIT:
; 684  : 		*va_arg(ap, uint16*) = td->td_resolutionunit;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	ax, WORD PTR [edx+88]
	mov	WORD PTR [ecx], ax

; 685  : 		break;

	jmp	$L66679
$L66930:

; 686  : 	case TIFFTAG_PAGENUMBER:
; 687  : 		*va_arg(ap, uint16*) = td->td_pagenumber[0];

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	dx, WORD PTR [ecx+100]
	mov	WORD PTR [eax], dx

; 688  : 		*va_arg(ap, uint16*) = td->td_pagenumber[1];

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	cx, WORD PTR [eax+102]
	mov	WORD PTR [edx], cx

; 689  : 		break;

	jmp	$L66679
$L66945:

; 690  : 	case TIFFTAG_HALFTONEHINTS:
; 691  : 		*va_arg(ap, uint16*) = td->td_halftonehints[0];

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	ax, WORD PTR [edx+116]
	mov	WORD PTR [ecx], ax

; 692  : 		*va_arg(ap, uint16*) = td->td_halftonehints[1];

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	dx, WORD PTR [ecx+118]
	mov	WORD PTR [eax], dx

; 693  : 		break;

	jmp	$L66679
$L66960:

; 694  : 	case TIFFTAG_COLORMAP:
; 695  : 		*va_arg(ap, uint16**) = td->td_colormap[0];

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+104]
	mov	DWORD PTR [edx], ecx

; 696  : 		*va_arg(ap, uint16**) = td->td_colormap[1];

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+108]
	mov	DWORD PTR [ecx], eax

; 697  : 		*va_arg(ap, uint16**) = td->td_colormap[2];

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+112]
	mov	DWORD PTR [eax], edx

; 698  : 		break;

	jmp	$L66679
$L66982:

; 699  : 	case TIFFTAG_STRIPOFFSETS:
; 700  : 	case TIFFTAG_TILEOFFSETS:
; 701  : 		*va_arg(ap, uint32**) = td->td_stripoffset;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+184]
	mov	DWORD PTR [edx], ecx

; 702  : 		break;

	jmp	$L66679
$L66990:

; 703  : 	case TIFFTAG_STRIPBYTECOUNTS:
; 704  : 	case TIFFTAG_TILEBYTECOUNTS:
; 705  : 		*va_arg(ap, uint32**) = td->td_stripbytecount;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+188]
	mov	DWORD PTR [ecx], eax

; 706  : 		break;

	jmp	$L66679
$L66998:

; 707  : 	case TIFFTAG_MATTEING:
; 708  : 		*va_arg(ap, uint16*) =
; 709  : 		    (td->td_extrasamples == 1 &&
; 710  : 		     td->td_sampleinfo[0] == EXTRASAMPLE_ASSOCALPHA);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+120]
	cmp	edx, 1
	jne	SHORT $L67634
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+124]
	xor	edx, edx
	mov	dx, WORD PTR [ecx]
	cmp	edx, 1
	jne	SHORT $L67634
	mov	DWORD PTR -12+[ebp], 1
	jmp	SHORT $L67635
$L67634:
	mov	DWORD PTR -12+[ebp], 0
$L67635:
	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	ax, WORD PTR -12+[ebp]
	mov	WORD PTR [edx], ax

; 711  : 		break;

	jmp	$L66679
$L67006:

; 712  : 	case TIFFTAG_EXTRASAMPLES:
; 713  : 		*va_arg(ap, uint16*) = td->td_extrasamples;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	dx, WORD PTR [ecx+120]
	mov	WORD PTR [eax], dx

; 714  : 		*va_arg(ap, uint16**) = td->td_sampleinfo;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+124]
	mov	DWORD PTR [edx], ecx

; 715  : 		break;

	jmp	$L66679
$L67021:

; 716  : 	case TIFFTAG_TILEWIDTH:
; 717  : 		*va_arg(ap, uint32*) = td->td_tilewidth;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+24]
	mov	DWORD PTR [ecx], eax

; 718  : 		break;

	jmp	$L66679
$L67029:

; 719  : 	case TIFFTAG_TILELENGTH:
; 720  : 		*va_arg(ap, uint32*) = td->td_tilelength;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	mov	DWORD PTR [eax], edx

; 721  : 		break;

	jmp	$L66679
$L67037:

; 722  : 	case TIFFTAG_TILEDEPTH:
; 723  : 		*va_arg(ap, uint32*) = td->td_tiledepth;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+32]
	mov	DWORD PTR [edx], ecx

; 724  : 		break;

	jmp	$L66679
$L67045:

; 725  : 	case TIFFTAG_DATATYPE:
; 726  : 		switch (td->td_sampleformat) {

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+42]
	mov	DWORD PTR -16+[ebp], eax
	mov	ecx, DWORD PTR -16+[ebp]
	sub	ecx, 1
	mov	DWORD PTR -16+[ebp], ecx
	cmp	DWORD PTR -16+[ebp], 3
	ja	SHORT $L67047
	mov	edx, DWORD PTR -16+[ebp]
	jmp	DWORD PTR $L67651[edx*4]
$L67050:

; 727  : 		case SAMPLEFORMAT_UINT:
; 728  : 			*va_arg(ap, uint16*) = DATATYPE_UINT;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	WORD PTR [edx], 2

; 729  : 			break;

	jmp	SHORT $L67047
$L67058:

; 730  : 		case SAMPLEFORMAT_INT:
; 731  : 			*va_arg(ap, uint16*) = DATATYPE_INT;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	WORD PTR [edx], 1

; 732  : 			break;

	jmp	SHORT $L67047
$L67066:

; 733  : 		case SAMPLEFORMAT_IEEEFP:
; 734  : 			*va_arg(ap, uint16*) = DATATYPE_IEEEFP;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	WORD PTR [edx], 3

; 735  : 			break;

	jmp	SHORT $L67047
$L67074:

; 736  : 		case SAMPLEFORMAT_VOID:
; 737  : 			*va_arg(ap, uint16*) = DATATYPE_VOID;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	WORD PTR [edx], 0
$L67047:

; 740  : 		break;

	jmp	$L66679
$L67082:

; 741  : 	case TIFFTAG_SAMPLEFORMAT:
; 742  : 		*va_arg(ap, uint16*) = td->td_sampleformat;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	cx, WORD PTR [eax+42]
	mov	WORD PTR [edx], cx

; 743  : 		break;

	jmp	$L66679
$L67090:

; 744  : 	case TIFFTAG_IMAGEDEPTH:
; 745  : 		*va_arg(ap, uint32*) = td->td_imagedepth;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+20]
	mov	DWORD PTR [ecx], eax

; 746  : 		break;

	jmp	$L66679
$L67098:

; 747  : 	case TIFFTAG_STONITS:
; 748  : 		*va_arg(ap, double*) = td->td_stonits;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [eax-4]
	mov	eax, DWORD PTR [ecx+128]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR [ecx+132]
	mov	DWORD PTR [edx+4], ecx

; 749  : 		break;

	jmp	$L66679
$L67106:

; 750  : #if SUBIFD_SUPPORT
; 751  : 	case TIFFTAG_SUBIFD:
; 752  : 		*va_arg(ap, uint16*) = td->td_nsubifd;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	ax, WORD PTR [edx+192]
	mov	WORD PTR [ecx], ax

; 753  : 		*va_arg(ap, uint32**) = td->td_subifd;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+196]
	mov	DWORD PTR [eax], edx

; 754  : 		break;

	jmp	$L66679
$L67121:

; 755  : #endif
; 756  : #ifdef YCBCR_SUPPORT
; 757  : 	case TIFFTAG_YCBCRCOEFFICIENTS:
; 758  : 		*va_arg(ap, float**) = td->td_ycbcrcoeffs;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+200]
	mov	DWORD PTR [edx], ecx

; 759  : 		break;

	jmp	$L66679
$L67129:

; 760  : 	case TIFFTAG_YCBCRPOSITIONING:
; 761  : 		*va_arg(ap, uint16*) = td->td_ycbcrpositioning;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	ax, WORD PTR [edx+208]
	mov	WORD PTR [ecx], ax

; 762  : 		break;

	jmp	$L66679
$L67137:

; 763  : 	case TIFFTAG_YCBCRSUBSAMPLING:
; 764  : 		*va_arg(ap, uint16*) = td->td_ycbcrsubsampling[0];

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	dx, WORD PTR [ecx+204]
	mov	WORD PTR [eax], dx

; 765  : 		*va_arg(ap, uint16*) = td->td_ycbcrsubsampling[1];

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	cx, WORD PTR [eax+206]
	mov	WORD PTR [edx], cx

; 766  : 		break;

	jmp	$L66679
$L67152:

; 767  : #endif
; 768  : #ifdef COLORIMETRY_SUPPORT
; 769  : 	case TIFFTAG_WHITEPOINT:
; 770  : 		*va_arg(ap, float**) = td->td_whitepoint;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+212]
	mov	DWORD PTR [ecx], eax

; 771  : 		break;

	jmp	$L66679
$L67160:

; 772  : 	case TIFFTAG_PRIMARYCHROMATICITIES:
; 773  : 		*va_arg(ap, float**) = td->td_primarychromas;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+216]
	mov	DWORD PTR [eax], edx

; 774  : 		break;

	jmp	$L66679
$L67168:

; 775  : 	case TIFFTAG_TRANSFERFUNCTION:
; 776  : 		*va_arg(ap, uint16**) = td->td_transferfunction[0];

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+224]
	mov	DWORD PTR [edx], ecx

; 777  : 		if (td->td_samplesperpixel - td->td_extrasamples > 1) {

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+54]
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+120]
	sub	eax, edx
	cmp	eax, 1
	jle	SHORT $L67176

; 778  : 			*va_arg(ap, uint16**) = td->td_transferfunction[1];

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+228]
	mov	DWORD PTR [edx], ecx

; 779  : 			*va_arg(ap, uint16**) = td->td_transferfunction[2];

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+232]
	mov	DWORD PTR [ecx], eax
$L67176:

; 781  : 		break;

	jmp	$L66679
$L67191:

; 782  : 	case TIFFTAG_REFERENCEBLACKWHITE:
; 783  : 		*va_arg(ap, float**) = td->td_refblackwhite;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+220]
	mov	DWORD PTR [eax], edx

; 784  : 		break;

	jmp	$L66679
$L67199:

; 785  : #endif
; 786  : #ifdef CMYK_SUPPORT
; 787  : 	case TIFFTAG_INKSET:
; 788  : 		*va_arg(ap, uint16*) = td->td_inkset;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	cx, WORD PTR [eax+236]
	mov	WORD PTR [edx], cx

; 789  : 		break;

	jmp	$L66679
$L67207:

; 790  : 	case TIFFTAG_DOTRANGE:
; 791  : 		*va_arg(ap, uint16*) = td->td_dotrange[0];

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	ax, WORD PTR [edx+240]
	mov	WORD PTR [ecx], ax

; 792  : 		*va_arg(ap, uint16*) = td->td_dotrange[1];

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	dx, WORD PTR [ecx+242]
	mov	WORD PTR [eax], dx

; 793  : 		break;

	jmp	$L66679
$L67222:

; 794  : 	case TIFFTAG_INKNAMES:
; 795  : 		*va_arg(ap, char**) = td->td_inknames;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+248]
	mov	DWORD PTR [edx], ecx

; 796  : 		break;

	jmp	$L66679
$L67230:

; 797  : 	case TIFFTAG_NUMBEROFINKS:
; 798  : 		*va_arg(ap, uint16*) = td->td_ninks;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	ax, WORD PTR [edx+238]
	mov	WORD PTR [ecx], ax

; 799  : 		break;

	jmp	$L66679
$L67238:

; 800  : 	case TIFFTAG_TARGETPRINTER:
; 801  : 		*va_arg(ap, char**) = td->td_targetprinter;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+252]
	mov	DWORD PTR [eax], edx

; 802  : 		break;

	jmp	$L66679
$L67246:

; 803  : #endif
; 804  : #ifdef ICC_SUPPORT
; 805  : 	case TIFFTAG_ICCPROFILE:
; 806  : 		*va_arg(ap, uint32*) = td->td_profileLength;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+256]
	mov	DWORD PTR [edx], ecx

; 807  : 		*va_arg(ap, void**) = td->td_profileData;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+260]
	mov	DWORD PTR [ecx], eax

; 808  : 		break;

	jmp	$L66679
$L67261:

; 809  : #endif
; 810  : #ifdef PHOTOSHOP_SUPPORT
; 811  :  	case TIFFTAG_PHOTOSHOP:
; 812  :  		*va_arg(ap, uint32*) = td->td_photoshopLength;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+264]
	mov	DWORD PTR [eax], edx

; 813  :  		*va_arg(ap, void**) = td->td_photoshopData;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+268]
	mov	DWORD PTR [edx], ecx

; 814  :  		break;

	jmp	$L66679
$L67276:

; 815  : #endif
; 816  : #ifdef IPTC_SUPPORT
; 817  :  	case TIFFTAG_RICHTIFFIPTC:
; 818  :  		*va_arg(ap, uint32*) = td->td_richtiffiptcLength;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+272]
	mov	DWORD PTR [ecx], eax

; 819  :  		*va_arg(ap, void**) = td->td_richtiffiptcData;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+276]
	mov	DWORD PTR [eax], edx

; 820  :  		break;

	jmp	$L66679
$L67291:

; 821  : #endif
; 822  :  	/* Begin Pixar Tags */
; 823  :  	case TIFFTAG_PIXAR_IMAGEFULLWIDTH:
; 824  :  		*va_arg(ap, uint32*) = td->td_imagefullwidth;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+280]
	mov	DWORD PTR [edx], ecx

; 825  :  		break;

	jmp	$L66679
$L67299:

; 826  :  	case TIFFTAG_PIXAR_IMAGEFULLLENGTH:
; 827  :  		*va_arg(ap, uint32*) = td->td_imagefulllength;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+284]
	mov	DWORD PTR [ecx], eax

; 828  :  		break;

	jmp	$L66679
$L67307:

; 829  :  	case TIFFTAG_PIXAR_TEXTUREFORMAT:
; 830  :  		*va_arg(ap, char**) = td->td_textureformat;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+288]
	mov	DWORD PTR [eax], edx

; 831  :  		break;

	jmp	$L66679
$L67315:

; 832  :  	case TIFFTAG_PIXAR_WRAPMODES:
; 833  :  		*va_arg(ap, char**) = td->td_wrapmodes;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+292]
	mov	DWORD PTR [edx], ecx

; 834  :  		break;

	jmp	$L66679
$L67323:

; 835  :  	case TIFFTAG_PIXAR_FOVCOT:
; 836  :  		*va_arg(ap, float*) = td->td_fovcot;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+296]
	mov	DWORD PTR [ecx], eax

; 837  :  		break;

	jmp	$L66679
$L67331:

; 838  :  	case TIFFTAG_PIXAR_MATRIX_WORLDTOSCREEN:
; 839  :  		*va_arg(ap, float**) = td->td_matrixWorldToScreen;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+300]
	mov	DWORD PTR [eax], edx

; 840  :  		break;

	jmp	SHORT $L66679
$L67339:

; 841  :  	case TIFFTAG_PIXAR_MATRIX_WORLDTOCAMERA:
; 842  :  		*va_arg(ap, float**) = td->td_matrixWorldToCamera;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+304]
	mov	DWORD PTR [edx], ecx

; 843  :  		break;

	jmp	SHORT $L66679
$L67347:

; 844  :  	/* End Pixar Tags */
; 845  : 
; 846  : 	default:
; 847  : 		/*
; 848  : 		 * This can happen if multiple images are open with
; 849  : 		 * different codecs which have private tags.  The
; 850  : 		 * global tag information table may then have tags
; 851  : 		 * that are valid for one file but not the other. 
; 852  : 		 * If the client tries to get a tag that is not valid
; 853  : 		 * for the image's codec then we'll arrive here.
; 854  : 		 */
; 855  : 		TIFFError("TIFFGetField",
; 856  : 		    "%s: Invalid %stag \"%s\" (not supported by codec)",
; 857  : 		    tif->tif_name, isPseudoTag(tag) ? "pseudo-" : "",
; 858  : 		    _TIFFFieldWithTag(tif, tag)->field_name);

	cmp	DWORD PTR _tag$[ebp], 65535		; 0000ffffH
	jbe	SHORT $L67636
	mov	DWORD PTR -20+[ebp], OFFSET FLAT:$SG67348
	jmp	SHORT $L67637
$L67636:
	mov	DWORD PTR -20+[ebp], OFFSET FLAT:$SG67349
$L67637:
	mov	edx, DWORD PTR _tag$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	__TIFFFieldWithTag
	add	esp, 8
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	mov	edx, DWORD PTR -20+[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG67350
	push	OFFSET FLAT:$SG67351
	call	_TIFFError
	add	esp, 20					; 00000014H
$L66679:

; 861  : 	return (1);

	mov	eax, 1

; 862  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L67647:
	DD	$L66682
	DD	$L66690
	DD	$L66698
	DD	$L66706
	DD	$L66714
	DD	$L66722
	DD	$L66730
	DD	$L66738
	DD	$L66746
	DD	$L66778
	DD	$L66786
	DD	$L66794
	DD	$L66982
	DD	$L66818
	DD	$L66826
	DD	$L66834
	DD	$L66990
	DD	$L66842
	DD	$L66850
	DD	$L66874
	DD	$L66882
	DD	$L66890
	DD	$L66914
	DD	$L66898
	DD	$L66906
	DD	$L66922
	DD	$L66930
	DD	$L67347
$L67646:
	DB	0
	DB	27					; 0000001bH
	DB	1
	DB	2
	DB	3
	DB	4
	DB	27					; 0000001bH
	DB	27					; 0000001bH
	DB	5
	DB	6
	DB	27					; 0000001bH
	DB	27					; 0000001bH
	DB	7
	DB	27					; 0000001bH
	DB	27					; 0000001bH
	DB	8
	DB	9
	DB	10					; 0000000aH
	DB	11					; 0000000bH
	DB	12					; 0000000cH
	DB	13					; 0000000dH
	DB	27					; 0000001bH
	DB	27					; 0000001bH
	DB	14					; 0000000eH
	DB	15					; 0000000fH
	DB	16					; 00000010H
	DB	17					; 00000011H
	DB	18					; 00000012H
	DB	19					; 00000013H
	DB	20					; 00000014H
	DB	21					; 00000015H
	DB	22					; 00000016H
	DB	23					; 00000017H
	DB	24					; 00000018H
	DB	27					; 0000001bH
	DB	27					; 0000001bH
	DB	27					; 0000001bH
	DB	27					; 0000001bH
	DB	27					; 0000001bH
	DB	27					; 0000001bH
	DB	27					; 0000001bH
	DB	27					; 0000001bH
	DB	25					; 00000019H
	DB	26					; 0000001aH
$L67649:
	DD	$L66802
	DD	$L66762
	DD	$L66754
	DD	$L66770
	DD	$L67152
	DD	$L67160
	DD	$L66960
	DD	$L66945
	DD	$L67021
	DD	$L67029
	DD	$L66982
	DD	$L66990
	DD	$L67106
	DD	$L67199
	DD	$L67222
	DD	$L67230
	DD	$L67207
	DD	$L67238
	DD	$L67006
	DD	$L67082
	DD	$L66858
	DD	$L67347
$L67648:
	DB	0
	DB	1
	DB	21					; 00000015H
	DB	21					; 00000015H
	DB	21					; 00000015H
	DB	21					; 00000015H
	DB	21					; 00000015H
	DB	21					; 00000015H
	DB	21					; 00000015H
	DB	21					; 00000015H
	DB	2
	DB	3
	DB	21					; 00000015H
	DB	4
	DB	5
	DB	6
	DB	7
	DB	8
	DB	9
	DB	10					; 0000000aH
	DB	11					; 0000000bH
	DB	21					; 00000015H
	DB	21					; 00000015H
	DB	21					; 00000015H
	DB	21					; 00000015H
	DB	12					; 0000000cH
	DB	21					; 00000015H
	DB	13					; 0000000dH
	DB	14					; 0000000eH
	DB	15					; 0000000fH
	DB	21					; 00000015H
	DB	16					; 00000010H
	DB	17					; 00000011H
	DB	18					; 00000012H
	DB	19					; 00000013H
	DB	20					; 00000014H
$L67650:
	DD	$L67315
	DD	$L67323
	DD	$L67331
	DD	$L67339
$L67651:
	DD	$L67050
	DD	$L67058
	DD	$L67066
	DD	$L67074
__TIFFVGetField ENDP
_TEXT	ENDS
PUBLIC	_TIFFNumberOfDirectories
_TEXT	SEGMENT
_tif$ = 8
_nextdir$ = -4
_n$ = -8
_TIFFNumberOfDirectories PROC NEAR

; 1119 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 1120 :     toff_t nextdir = tif->tif_header.tiff_diroff;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+340]
	mov	DWORD PTR _nextdir$[ebp], ecx

; 1121 :     tdir_t n = 0;

	mov	WORD PTR _n$[ebp], 0
$L67497:

; 1122 :     
; 1123 :     while (nextdir != 0 && TIFFAdvanceDirectory(tif, &nextdir, NULL))

	cmp	DWORD PTR _nextdir$[ebp], 0
	je	SHORT $L67498
	push	0
	lea	edx, DWORD PTR _nextdir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFAdvanceDirectory
	add	esp, 12					; 0000000cH
	test	eax, eax
	je	SHORT $L67498

; 1124 :         n++;

	mov	cx, WORD PTR _n$[ebp]
	add	cx, 1
	mov	WORD PTR _n$[ebp], cx
	jmp	SHORT $L67497
$L67498:

; 1125 :     return (n);

	mov	ax, WORD PTR _n$[ebp]

; 1126 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFNumberOfDirectories ENDP
_TEXT	ENDS
EXTRN	_TIFFSwabShort:NEAR
EXTRN	_TIFFSwabLong:NEAR
_DATA	SEGMENT
	ORG $+3
$SG67448 DB	'%s: Error fetching directory count', 00H
	ORG $+1
$SG67458 DB	'%s: Error fetching directory link', 00H
	ORG $+2
$SG67472 DB	'%s: Error fetching directory count', 00H
	ORG $+1
$SG67488 DB	'%s: Error fetching directory link', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_nextdir$ = 12
_off$ = 16
_dircount$ = -4
_poff$67445 = -8
_TIFFAdvanceDirectory PROC NEAR

; 1058 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 1059 :     static const char module[] = "TIFFAdvanceDirectory";
; 1060 :     uint16 dircount;
; 1061 :     if (isMapped(tif))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 2048				; 00000800H
	test	ecx, ecx
	je	$L67444

; 1063 :         toff_t poff=*nextdir;

	mov	edx, DWORD PTR _nextdir$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR _poff$67445[ebp], eax

; 1064 :         if (poff+sizeof(uint16) > tif->tif_size)

	mov	ecx, DWORD PTR _poff$67445[ebp]
	add	ecx, 2
	mov	edx, DWORD PTR _tif$[ebp]
	cmp	ecx, DWORD PTR [edx+492]
	jbe	SHORT $L67447

; 1066 :             TIFFError(module, "%s: Error fetching directory count",
; 1067 :                       tif->tif_name);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG67448
	push	OFFSET FLAT:_?module@?1??TIFFAdvanceDirectory@@9@9
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 1068 :             return (0);

	xor	eax, eax
	jmp	$L67461
$L67447:

; 1070 :         _TIFFmemcpy(&dircount, tif->tif_base+poff, sizeof (uint16));

	push	2
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+488]
	add	eax, DWORD PTR _poff$67445[ebp]
	push	eax
	lea	ecx, DWORD PTR _dircount$[ebp]
	push	ecx
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH

; 1071 :         if (tif->tif_flags & TIFF_SWAB)

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 128				; 00000080H
	test	eax, eax
	je	SHORT $L67450

; 1072 :             TIFFSwabShort(&dircount);

	lea	ecx, DWORD PTR _dircount$[ebp]
	push	ecx
	call	_TIFFSwabShort
	add	esp, 4
$L67450:

; 1073 :         poff+=sizeof (uint16)+dircount*sizeof (TIFFDirEntry);

	mov	edx, DWORD PTR _dircount$[ebp]
	and	edx, 65535				; 0000ffffH
	imul	edx, 12					; 0000000cH
	mov	eax, DWORD PTR _poff$67445[ebp]
	lea	ecx, DWORD PTR [eax+edx+2]
	mov	DWORD PTR _poff$67445[ebp], ecx

; 1074 :         if (off != NULL)

	cmp	DWORD PTR _off$[ebp], 0
	je	SHORT $L67454

; 1075 :             *off = poff;

	mov	edx, DWORD PTR _off$[ebp]
	mov	eax, DWORD PTR _poff$67445[ebp]
	mov	DWORD PTR [edx], eax
$L67454:

; 1076 :         if (((toff_t) (poff+sizeof (uint32))) > tif->tif_size)

	mov	ecx, DWORD PTR _poff$67445[ebp]
	add	ecx, 4
	mov	edx, DWORD PTR _tif$[ebp]
	cmp	ecx, DWORD PTR [edx+492]
	jbe	SHORT $L67457

; 1078 :             TIFFError(module, "%s: Error fetching directory link",
; 1079 :                       tif->tif_name);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG67458
	push	OFFSET FLAT:_?module@?1??TIFFAdvanceDirectory@@9@9
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 1080 :             return (0);

	xor	eax, eax
	jmp	$L67461
$L67457:

; 1082 :         _TIFFmemcpy(nextdir, tif->tif_base+poff, sizeof (uint32));

	push	4
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+488]
	add	eax, DWORD PTR _poff$67445[ebp]
	push	eax
	mov	ecx, DWORD PTR _nextdir$[ebp]
	push	ecx
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH

; 1083 :         if (tif->tif_flags & TIFF_SWAB)

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 128				; 00000080H
	test	eax, eax
	je	SHORT $L67460

; 1084 :             TIFFSwabLong(nextdir);

	mov	ecx, DWORD PTR _nextdir$[ebp]
	push	ecx
	call	_TIFFSwabLong
	add	esp, 4
$L67460:

; 1085 :         return (1);

	mov	eax, 1
	jmp	$L67461
$L67444:

; 1089 :         if (!SeekOK(tif, *nextdir) ||
; 1090 :             !ReadOK(tif, &dircount, sizeof (uint16))) {

	push	0
	mov	edx, DWORD PTR _nextdir$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+516]
	add	esp, 12					; 0000000cH
	mov	ecx, DWORD PTR _nextdir$[ebp]
	cmp	eax, DWORD PTR [ecx]
	jne	SHORT $L67471
	push	2
	lea	edx, DWORD PTR _dircount$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+508]
	add	esp, 12					; 0000000cH
	cmp	eax, 2
	je	SHORT $L67470
$L67471:

; 1091 :             TIFFError(module, "%s: Error fetching directory count",
; 1092 :                       tif->tif_name);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG67472
	push	OFFSET FLAT:_?module@?1??TIFFAdvanceDirectory@@9@9
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 1093 :             return (0);

	xor	eax, eax
	jmp	$L67461
$L67470:

; 1095 :         if (tif->tif_flags & TIFF_SWAB)

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 128				; 00000080H
	test	eax, eax
	je	SHORT $L67473

; 1096 :             TIFFSwabShort(&dircount);

	lea	ecx, DWORD PTR _dircount$[ebp]
	push	ecx
	call	_TIFFSwabShort
	add	esp, 4
$L67473:

; 1097 :         if (off != NULL)

	cmp	DWORD PTR _off$[ebp], 0
	je	SHORT $L67475

; 1098 :             *off = TIFFSeekFile(tif,
; 1099 :                                 dircount*sizeof (TIFFDirEntry), SEEK_CUR);

	push	1
	mov	edx, DWORD PTR _dircount$[ebp]
	and	edx, 65535				; 0000ffffH
	imul	edx, 12					; 0000000cH
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+516]
	add	esp, 12					; 0000000cH
	mov	ecx, DWORD PTR _off$[ebp]
	mov	DWORD PTR [ecx], eax

; 1100 :         else

	jmp	SHORT $L67478
$L67475:

; 1101 :             (void) TIFFSeekFile(tif,
; 1102 :                                 dircount*sizeof (TIFFDirEntry), SEEK_CUR);

	push	1
	mov	edx, DWORD PTR _dircount$[ebp]
	and	edx, 65535				; 0000ffffH
	imul	edx, 12					; 0000000cH
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+516]
	add	esp, 12					; 0000000cH
$L67478:

; 1103 :         if (!ReadOK(tif, nextdir, sizeof (uint32))) {

	push	4
	mov	eax, DWORD PTR _nextdir$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+508]
	add	esp, 12					; 0000000cH
	cmp	eax, 4
	je	SHORT $L67487

; 1104 :             TIFFError(module, "%s: Error fetching directory link",
; 1105 :                       tif->tif_name);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	push	OFFSET FLAT:$SG67488
	push	OFFSET FLAT:_?module@?1??TIFFAdvanceDirectory@@9@9
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 1106 :             return (0);

	xor	eax, eax
	jmp	SHORT $L67461
$L67487:

; 1108 :         if (tif->tif_flags & TIFF_SWAB)

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 128				; 00000080H
	test	ecx, ecx
	je	SHORT $L67489

; 1109 :             TIFFSwabLong(nextdir);

	mov	edx, DWORD PTR _nextdir$[ebp]
	push	edx
	call	_TIFFSwabLong
	add	esp, 4
$L67489:

; 1110 :         return (1);

	mov	eax, 1
$L67461:

; 1112 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFAdvanceDirectory ENDP
_TEXT	ENDS
PUBLIC	_TIFFSetDirectory
EXTRN	_TIFFReadDirectory:NEAR
_TEXT	SEGMENT
_tif$ = 8
_dirn$ = 12
_nextdir$ = -4
_n$ = -8
_TIFFSetDirectory PROC NEAR

; 1134 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 1135 : 	toff_t nextdir;
; 1136 : 	tdir_t n;
; 1137 : 
; 1138 : 	nextdir = tif->tif_header.tiff_diroff;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+340]
	mov	DWORD PTR _nextdir$[ebp], ecx

; 1139 : 	for (n = dirn; n > 0 && nextdir != 0; n--)

	mov	dx, WORD PTR _dirn$[ebp]
	mov	WORD PTR _n$[ebp], dx
	jmp	SHORT $L67506
$L67507:
	mov	ax, WORD PTR _n$[ebp]
	sub	ax, 1
	mov	WORD PTR _n$[ebp], ax
$L67506:
	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 65535				; 0000ffffH
	test	ecx, ecx
	jle	SHORT $L67508
	cmp	DWORD PTR _nextdir$[ebp], 0
	je	SHORT $L67508

; 1140 : 		if (!TIFFAdvanceDirectory(tif, &nextdir, NULL))

	push	0
	lea	edx, DWORD PTR _nextdir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFAdvanceDirectory
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L67510

; 1141 : 			return (0);

	xor	eax, eax
	jmp	SHORT $L67503
$L67510:

; 1142 : 	tif->tif_nextdiroff = nextdir;

	jmp	SHORT $L67507
$L67508:
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _nextdir$[ebp]
	mov	DWORD PTR [ecx+20], edx

; 1143 : 	/*
; 1144 : 	 * Set curdir to the actual directory index.  The
; 1145 : 	 * -1 is because TIFFReadDirectory will increment
; 1146 : 	 * tif_curdir after successfully reading the directory.
; 1147 : 	 */
; 1148 : 	tif->tif_curdir = (dirn - n) - 1;

	mov	eax, DWORD PTR _dirn$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _n$[ebp]
	and	ecx, 65535				; 0000ffffH
	sub	eax, ecx
	sub	eax, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	WORD PTR [edx+360], ax

; 1149 : 	return (TIFFReadDirectory(tif));

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFReadDirectory
	add	esp, 4
$L67503:

; 1150 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFSetDirectory ENDP
_TEXT	ENDS
PUBLIC	_TIFFSetSubDirectory
_TEXT	SEGMENT
_tif$ = 8
_diroff$ = 12
_TIFFSetSubDirectory PROC NEAR

; 1160 : {

	push	ebp
	mov	ebp, esp

; 1161 : 	tif->tif_nextdiroff = diroff;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _diroff$[ebp]
	mov	DWORD PTR [eax+20], ecx

; 1162 : 	return (TIFFReadDirectory(tif));

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFReadDirectory
	add	esp, 4

; 1163 : }

	pop	ebp
	ret	0
_TIFFSetSubDirectory ENDP
_TEXT	ENDS
PUBLIC	_TIFFCurrentDirOffset
_TEXT	SEGMENT
_tif$ = 8
_TIFFCurrentDirOffset PROC NEAR

; 1170 : {

	push	ebp
	mov	ebp, esp

; 1171 : 	return (tif->tif_diroff);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [eax+16]

; 1172 : }

	pop	ebp
	ret	0
_TIFFCurrentDirOffset ENDP
_TEXT	ENDS
PUBLIC	_TIFFLastDirectory
_TEXT	SEGMENT
_tif$ = 8
_TIFFLastDirectory PROC NEAR

; 1180 : {

	push	ebp
	mov	ebp, esp

; 1181 : 	return (tif->tif_nextdiroff == 0);

	mov	eax, DWORD PTR _tif$[ebp]
	xor	ecx, ecx
	cmp	DWORD PTR [eax+20], 0
	sete	cl
	mov	eax, ecx

; 1182 : }

	pop	ebp
	ret	0
_TIFFLastDirectory ENDP
_TEXT	ENDS
PUBLIC	_TIFFUnlinkDirectory
_DATA	SEGMENT
	ORG $+2
$SG67533 DB	'Can not unlink directory in read-only file', 00H
	ORG $+1
$SG67540 DB	'Directory %d does not exist', 00H
$SG67553 DB	'Error writing directory link', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_dirn$ = 12
_nextdir$ = -4
_off$ = -8
_n$ = -12
_TIFFUnlinkDirectory PROC NEAR

; 1189 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 1190 : 	static const char module[] = "TIFFUnlinkDirectory";
; 1191 : 	toff_t nextdir;
; 1192 : 	toff_t off;
; 1193 : 	tdir_t n;
; 1194 : 
; 1195 : 	if (tif->tif_mode == O_RDONLY) {

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+8], 0
	jne	SHORT $L67532

; 1196 : 		TIFFError(module, "Can not unlink directory in read-only file");

	push	OFFSET FLAT:$SG67533
	push	OFFSET FLAT:_?module@?1??TIFFUnlinkDirectory@@9@9
	call	_TIFFError
	add	esp, 8

; 1197 : 		return (0);

	xor	eax, eax
	jmp	$L67526
$L67532:

; 1199 : 	/*
; 1200 : 	 * Go to the directory before the one we want
; 1201 : 	 * to unlink and nab the offset of the link
; 1202 : 	 * field we'll need to patch.
; 1203 : 	 */
; 1204 : 	nextdir = tif->tif_header.tiff_diroff;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+340]
	mov	DWORD PTR _nextdir$[ebp], edx

; 1205 : 	off = sizeof (uint16) + sizeof (uint16);

	mov	DWORD PTR _off$[ebp], 4

; 1206 : 	for (n = dirn-1; n > 0; n--) {

	mov	eax, DWORD PTR _dirn$[ebp]
	and	eax, 65535				; 0000ffffH
	sub	eax, 1
	mov	WORD PTR _n$[ebp], ax
	jmp	SHORT $L67536
$L67537:
	mov	cx, WORD PTR _n$[ebp]
	sub	cx, 1
	mov	WORD PTR _n$[ebp], cx
$L67536:
	mov	edx, DWORD PTR _n$[ebp]
	and	edx, 65535				; 0000ffffH
	test	edx, edx
	jle	SHORT $L67538

; 1207 : 		if (nextdir == 0) {

	cmp	DWORD PTR _nextdir$[ebp], 0
	jne	SHORT $L67539

; 1208 : 			TIFFError(module, "Directory %d does not exist", dirn);

	mov	eax, DWORD PTR _dirn$[ebp]
	and	eax, 65535				; 0000ffffH
	push	eax
	push	OFFSET FLAT:$SG67540
	push	OFFSET FLAT:_?module@?1??TIFFUnlinkDirectory@@9@9
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 1209 : 			return (0);

	xor	eax, eax
	jmp	$L67526
$L67539:

; 1211 : 		if (!TIFFAdvanceDirectory(tif, &nextdir, &off))

	lea	ecx, DWORD PTR _off$[ebp]
	push	ecx
	lea	edx, DWORD PTR _nextdir$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFAdvanceDirectory
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L67541

; 1212 : 			return (0);

	xor	eax, eax
	jmp	$L67526
$L67541:

; 1213 : 	}

	jmp	SHORT $L67537
$L67538:

; 1214 : 	/*
; 1215 : 	 * Advance to the directory to be unlinked and fetch
; 1216 : 	 * the offset of the directory that follows.
; 1217 : 	 */
; 1218 : 	if (!TIFFAdvanceDirectory(tif, &nextdir, NULL))

	push	0
	lea	ecx, DWORD PTR _nextdir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFAdvanceDirectory
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L67543

; 1219 : 		return (0);

	xor	eax, eax
	jmp	$L67526
$L67543:

; 1220 : 	/*
; 1221 : 	 * Go back and patch the link field of the preceding
; 1222 : 	 * directory to point to the offset of the directory
; 1223 : 	 * that follows.
; 1224 : 	 */
; 1225 : 	(void) TIFFSeekFile(tif, off, SEEK_SET);

	push	0
	mov	eax, DWORD PTR _off$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+516]
	add	esp, 12					; 0000000cH

; 1226 : 	if (tif->tif_flags & TIFF_SWAB)

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 128				; 00000080H
	test	edx, edx
	je	SHORT $L67546

; 1227 : 		TIFFSwabLong(&nextdir);

	lea	eax, DWORD PTR _nextdir$[ebp]
	push	eax
	call	_TIFFSwabLong
	add	esp, 4
$L67546:

; 1228 : 	if (!WriteOK(tif, &nextdir, sizeof (uint32))) {

	push	4
	lea	ecx, DWORD PTR _nextdir$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+504]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+512]
	add	esp, 12					; 0000000cH
	cmp	eax, 4
	je	SHORT $L67552

; 1229 : 		TIFFError(module, "Error writing directory link");

	push	OFFSET FLAT:$SG67553
	push	OFFSET FLAT:_?module@?1??TIFFUnlinkDirectory@@9@9
	call	_TIFFError
	add	esp, 8

; 1230 : 		return (0);

	xor	eax, eax
	jmp	$L67526
$L67552:

; 1232 : 	/*
; 1233 : 	 * Leave directory state setup safely.  We don't have
; 1234 : 	 * facilities for doing inserting and removing directories,
; 1235 : 	 * so it's safest to just invalidate everything.  This
; 1236 : 	 * means that the caller can only append to the directory
; 1237 : 	 * chain.
; 1238 : 	 */
; 1239 : 	(*tif->tif_cleanup)(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+448]
	add	esp, 4

; 1240 : 	if ((tif->tif_flags & TIFF_MYBUFFER) && tif->tif_rawdata) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 512				; 00000200H
	test	edx, edx
	je	SHORT $L67554
	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+472], 0
	je	SHORT $L67554

; 1241 : 		_TIFFfree(tif->tif_rawdata);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+472]
	push	edx
	call	__TIFFfree
	add	esp, 4

; 1242 : 		tif->tif_rawdata = NULL;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+472], 0

; 1243 : 		tif->tif_rawcc = 0;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+484], 0
$L67554:

; 1245 : 	tif->tif_flags &= ~(TIFF_BEENWRITING|TIFF_BUFFERSETUP|TIFF_POSTENCODE);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, -4177				; ffffefafH
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+12], eax

; 1246 : 	TIFFFreeDirectory(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFreeDirectory
	add	esp, 4

; 1247 : 	TIFFDefaultDirectory(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFDefaultDirectory
	add	esp, 4

; 1248 : 	tif->tif_diroff = 0;			/* force link on next write */

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+16], 0

; 1249 : 	tif->tif_nextdiroff = 0;		/* next write must be at end */

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+20], 0

; 1250 : 	tif->tif_curoff = 0;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+368], 0

; 1251 : 	tif->tif_row = (uint32) -1;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+356], -1

; 1252 : 	tif->tif_curstrip = (tstrip_t) -1;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+364], -1

; 1253 : 	return (1);

	mov	eax, 1
$L67526:

; 1254 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFUnlinkDirectory ENDP
_TEXT	ENDS
PUBLIC	_TIFFReassignTagToIgnore
_BSS	SEGMENT
	ALIGN	4

_?TIFFignoretags@?1??TIFFReassignTagToIgnore@@9@9 DD 05fH DUP (?)
_BSS	ENDS
_TEXT	SEGMENT
_task$ = 8
_TIFFtagID$ = 12
_i$ = -4
_j$ = -8
_TIFFReassignTagToIgnore PROC NEAR

; 1266 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 1267 :     static int TIFFignoretags [FIELD_LAST];
; 1268 :     static int tagcount = 0 ;
; 1269 :     int		i;					/* Loop index */
; 1270 :     int		j;					/* Loop index */
; 1271 : 
; 1272 :     switch (task)
; 1273 :     {

	mov	eax, DWORD PTR _task$[ebp]
	mov	DWORD PTR -12+[ebp], eax
	cmp	DWORD PTR -12+[ebp], 0
	je	SHORT $L67573
	cmp	DWORD PTR -12+[ebp], 1
	je	SHORT $L67579
	cmp	DWORD PTR -12+[ebp], 2
	je	$L67584
	jmp	$L67585
$L67573:

; 1274 :       case TIS_STORE:
; 1275 :         if ( tagcount < (FIELD_LAST - 1) )

	cmp	DWORD PTR _?tagcount@?1??TIFFReassignTagToIgnore@@9@9, 94 ; 0000005eH
	jge	SHORT $L67574

; 1277 :             for ( j = 0 ; j < tagcount ; ++j )

	mov	DWORD PTR _j$[ebp], 0
	jmp	SHORT $L67575
$L67576:
	mov	ecx, DWORD PTR _j$[ebp]
	add	ecx, 1
	mov	DWORD PTR _j$[ebp], ecx
$L67575:
	mov	edx, DWORD PTR _j$[ebp]
	cmp	edx, DWORD PTR _?tagcount@?1??TIFFReassignTagToIgnore@@9@9
	jge	SHORT $L67577

; 1279 :                 if ( TIFFignoretags [j] == TIFFtagID )

	mov	eax, DWORD PTR _j$[ebp]
	mov	ecx, DWORD PTR _?TIFFignoretags@?1??TIFFReassignTagToIgnore@@9@9[eax*4]
	cmp	ecx, DWORD PTR _TIFFtagID$[ebp]
	jne	SHORT $L67578

; 1280 :                     return (TRUE) ;

	mov	eax, 1
	jmp	SHORT $L67562
$L67578:

; 1281 :             }

	jmp	SHORT $L67576
$L67577:

; 1282 :             TIFFignoretags [tagcount++] = TIFFtagID ;

	mov	edx, DWORD PTR _?tagcount@?1??TIFFReassignTagToIgnore@@9@9
	mov	eax, DWORD PTR _TIFFtagID$[ebp]
	mov	DWORD PTR _?TIFFignoretags@?1??TIFFReassignTagToIgnore@@9@9[edx*4], eax
	mov	ecx, DWORD PTR _?tagcount@?1??TIFFReassignTagToIgnore@@9@9
	add	ecx, 1
	mov	DWORD PTR _?tagcount@?1??TIFFReassignTagToIgnore@@9@9, ecx

; 1283 :             return (TRUE) ;

	mov	eax, 1
	jmp	SHORT $L67562
$L67574:

; 1285 :         break ;

	jmp	SHORT $L67570
$L67579:

; 1286 :         
; 1287 :       case TIS_EXTRACT:
; 1288 :         for ( i = 0 ; i < tagcount ; ++i )

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L67580
$L67581:
	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	mov	DWORD PTR _i$[ebp], edx
$L67580:
	mov	eax, DWORD PTR _i$[ebp]
	cmp	eax, DWORD PTR _?tagcount@?1??TIFFReassignTagToIgnore@@9@9
	jge	SHORT $L67582

; 1290 :             if ( TIFFignoretags [i] == TIFFtagID )

	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _?TIFFignoretags@?1??TIFFReassignTagToIgnore@@9@9[ecx*4]
	cmp	edx, DWORD PTR _TIFFtagID$[ebp]
	jne	SHORT $L67583

; 1291 :                 return (TRUE) ;

	mov	eax, 1
	jmp	SHORT $L67562
$L67583:

; 1292 :         }

	jmp	SHORT $L67581
$L67582:

; 1293 :         break;

	jmp	SHORT $L67570
$L67584:

; 1294 :         
; 1295 :       case TIS_EMPTY:
; 1296 :         tagcount = 0 ;			/* Clear the list */

	mov	DWORD PTR _?tagcount@?1??TIFFReassignTagToIgnore@@9@9, 0

; 1297 :         return (TRUE) ;

	mov	eax, 1
	jmp	SHORT $L67562
$L67585:
$L67570:

; 1302 :     
; 1303 :     return (FALSE);

	xor	eax, eax
$L67562:

; 1304 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFReassignTagToIgnore ENDP
_TEXT	ENDS
END
