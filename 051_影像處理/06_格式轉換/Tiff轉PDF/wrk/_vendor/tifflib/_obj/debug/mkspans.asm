	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\mkspans.c
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
PUBLIC	_dumparray
EXTRN	_printf:NEAR
_DATA	SEGMENT
$SG719	DB	'static u_char %s[256] = {', 0aH, 00H
	ORG $+1
$SG720	DB	'    ', 00H
	ORG $+3
$SG724	DB	'%s%d', 00H
	ORG $+3
$SG726	DB	',', 09H, '/* 0x%02x - 0x%02x */', 0aH, 00H
	ORG $+3
$SG727	DB	'    ', 00H
	ORG $+3
$SG729	DB	', ', 00H
	ORG $+1
$SG730	DB	0aH, '};', 0aH, 00H
_DATA	ENDS
_TEXT	SEGMENT
_name$ = 8
_runs$ = 12
_i$ = -8
_sep$ = -4
_dumparray PROC NEAR

; 37   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 38   : 	register int i;
; 39   : 	register char *sep;
; 40   : 	printf("static u_char %s[256] = {\n", name);

	mov	eax, DWORD PTR _name$[ebp]
	push	eax
	push	OFFSET FLAT:$SG719
	call	_printf
	add	esp, 8

; 41   : 	sep = "    ";

	mov	DWORD PTR _sep$[ebp], OFFSET FLAT:$SG720

; 42   : 	for (i = 0; i < 256; i++) {

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L721
$L722:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L721:
	cmp	DWORD PTR _i$[ebp], 256			; 00000100H
	jge	SHORT $L723

; 43   : 		printf("%s%d", sep, runs[i]);

	mov	edx, DWORD PTR _runs$[ebp]
	add	edx, DWORD PTR _i$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	push	eax
	mov	ecx, DWORD PTR _sep$[ebp]
	push	ecx
	push	OFFSET FLAT:$SG724
	call	_printf
	add	esp, 12					; 0000000cH

; 44   : 		if (((i + 1) % 16) == 0) {

	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	and	edx, -2147483633			; 8000000fH
	jns	SHORT $L750
	dec	edx
	or	edx, -16				; fffffff0H
	inc	edx
$L750:
	test	edx, edx
	jne	SHORT $L725

; 45   : 			printf(",	/* 0x%02x - 0x%02x */\n", i-15, i);

	mov	eax, DWORD PTR _i$[ebp]
	push	eax
	mov	ecx, DWORD PTR _i$[ebp]
	sub	ecx, 15					; 0000000fH
	push	ecx
	push	OFFSET FLAT:$SG726
	call	_printf
	add	esp, 12					; 0000000cH

; 46   : 			sep = "    ";

	mov	DWORD PTR _sep$[ebp], OFFSET FLAT:$SG727

; 47   : 		} else

	jmp	SHORT $L728
$L725:

; 48   : 			sep = ", ";

	mov	DWORD PTR _sep$[ebp], OFFSET FLAT:$SG729
$L728:

; 49   : 	}

	jmp	SHORT $L722
$L723:

; 50   : 	printf("\n};\n");

	push	OFFSET FLAT:$SG730
	call	_printf
	add	esp, 4

; 51   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_dumparray ENDP
_TEXT	ENDS
PUBLIC	_main
EXTRN	_memset:NEAR
_DATA	SEGMENT
	ORG $+3
$SG745	DB	'bruns', 00H
	ORG $+2
$SG746	DB	'wruns', 00H
_DATA	ENDS
_TEXT	SEGMENT
_runs$ = -512
_run$736 = -520
_runlen$737 = -516
_i$738 = -524
_main	PROC NEAR

; 54   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 524				; 0000020cH

; 55   : 	unsigned char runs[2][256];
; 56   : 
; 57   : 	memset(runs[0], 0, 256*sizeof (char));

	push	256					; 00000100H
	push	0
	lea	eax, DWORD PTR _runs$[ebp]
	push	eax
	call	_memset
	add	esp, 12					; 0000000cH

; 58   : 	memset(runs[1], 0, 256*sizeof (char));

	push	256					; 00000100H
	push	0
	lea	ecx, DWORD PTR _runs$[ebp+256]
	push	ecx
	call	_memset
	add	esp, 12					; 0000000cH

; 60   : 	  runlen = 1;

	mov	DWORD PTR _runlen$737[ebp], 1

; 61   : 	  for (run = 0x80; run != 0xff; run = (run>>1)|0x80) {

	mov	DWORD PTR _run$736[ebp], 128		; 00000080H
	jmp	SHORT $L739
$L740:
	mov	edx, DWORD PTR _run$736[ebp]
	sar	edx, 1
	or	dl, -128				; ffffff80H
	mov	DWORD PTR _run$736[ebp], edx
$L739:
	cmp	DWORD PTR _run$736[ebp], 255		; 000000ffH
	je	SHORT $L741

; 62   : 		for (i = run-1; i >= 0; i--) {

	mov	eax, DWORD PTR _run$736[ebp]
	sub	eax, 1
	mov	DWORD PTR _i$738[ebp], eax
	jmp	SHORT $L742
$L743:
	mov	ecx, DWORD PTR _i$738[ebp]
	sub	ecx, 1
	mov	DWORD PTR _i$738[ebp], ecx
$L742:
	cmp	DWORD PTR _i$738[ebp], 0
	jl	SHORT $L744

; 63   : 			runs[1][run|i] = runlen;

	mov	edx, DWORD PTR _run$736[ebp]
	or	edx, DWORD PTR _i$738[ebp]
	mov	al, BYTE PTR _runlen$737[ebp]
	mov	BYTE PTR _runs$[ebp+edx+256], al

; 64   : 			runs[0][(~(run|i)) & 0xff] = runlen;

	mov	ecx, DWORD PTR _run$736[ebp]
	or	ecx, DWORD PTR _i$738[ebp]
	not	ecx
	and	ecx, 255				; 000000ffH
	mov	dl, BYTE PTR _runlen$737[ebp]
	mov	BYTE PTR _runs$[ebp+ecx], dl

; 65   : 		}

	jmp	SHORT $L743
$L744:

; 66   : 		runlen++;

	mov	eax, DWORD PTR _runlen$737[ebp]
	add	eax, 1
	mov	DWORD PTR _runlen$737[ebp], eax

; 67   : 	  }

	jmp	$L740
$L741:

; 68   : 	  runs[1][0xff] = runs[0][0] = 8;

	mov	BYTE PTR _runs$[ebp], 8
	mov	cl, BYTE PTR _runs$[ebp]
	mov	BYTE PTR _runs$[ebp+511], cl

; 70   : 	dumparray("bruns", runs[0]);

	lea	edx, DWORD PTR _runs$[ebp]
	push	edx
	push	OFFSET FLAT:$SG745
	call	_dumparray
	add	esp, 8

; 71   : 	dumparray("wruns", runs[1]);

	lea	eax, DWORD PTR _runs$[ebp+256]
	push	eax
	push	OFFSET FLAT:$SG746
	call	_dumparray
	add	esp, 8

; 72   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_main	ENDP
_TEXT	ENDS
END
