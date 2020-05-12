	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_swab.c
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
_TIFFBitRevTable DB 00H
	DB	080H
	DB	040H
	DB	0c0H
	DB	020H
	DB	0a0H
	DB	060H
	DB	0e0H
	DB	010H
	DB	090H
	DB	050H
	DB	0d0H
	DB	030H
	DB	0b0H
	DB	070H
	DB	0f0H
	DB	08H
	DB	088H
	DB	048H
	DB	0c8H
	DB	028H
	DB	0a8H
	DB	068H
	DB	0e8H
	DB	018H
	DB	098H
	DB	058H
	DB	0d8H
	DB	038H
	DB	0b8H
	DB	078H
	DB	0f8H
	DB	04H
	DB	084H
	DB	044H
	DB	0c4H
	DB	024H
	DB	0a4H
	DB	064H
	DB	0e4H
	DB	014H
	DB	094H
	DB	054H
	DB	0d4H
	DB	034H
	DB	0b4H
	DB	074H
	DB	0f4H
	DB	0cH
	DB	08cH
	DB	04cH
	DB	0ccH
	DB	02cH
	DB	0acH
	DB	06cH
	DB	0ecH
	DB	01cH
	DB	09cH
	DB	05cH
	DB	0dcH
	DB	03cH
	DB	0bcH
	DB	07cH
	DB	0fcH
	DB	02H
	DB	082H
	DB	042H
	DB	0c2H
	DB	022H
	DB	0a2H
	DB	062H
	DB	0e2H
	DB	012H
	DB	092H
	DB	052H
	DB	0d2H
	DB	032H
	DB	0b2H
	DB	072H
	DB	0f2H
	DB	0aH
	DB	08aH
	DB	04aH
	DB	0caH
	DB	02aH
	DB	0aaH
	DB	06aH
	DB	0eaH
	DB	01aH
	DB	09aH
	DB	05aH
	DB	0daH
	DB	03aH
	DB	0baH
	DB	07aH
	DB	0faH
	DB	06H
	DB	086H
	DB	046H
	DB	0c6H
	DB	026H
	DB	0a6H
	DB	066H
	DB	0e6H
	DB	016H
	DB	096H
	DB	056H
	DB	0d6H
	DB	036H
	DB	0b6H
	DB	076H
	DB	0f6H
	DB	0eH
	DB	08eH
	DB	04eH
	DB	0ceH
	DB	02eH
	DB	0aeH
	DB	06eH
	DB	0eeH
	DB	01eH
	DB	09eH
	DB	05eH
	DB	0deH
	DB	03eH
	DB	0beH
	DB	07eH
	DB	0feH
	DB	01H
	DB	081H
	DB	041H
	DB	0c1H
	DB	021H
	DB	0a1H
	DB	061H
	DB	0e1H
	DB	011H
	DB	091H
	DB	051H
	DB	0d1H
	DB	031H
	DB	0b1H
	DB	071H
	DB	0f1H
	DB	09H
	DB	089H
	DB	049H
	DB	0c9H
	DB	029H
	DB	0a9H
	DB	069H
	DB	0e9H
	DB	019H
	DB	099H
	DB	059H
	DB	0d9H
	DB	039H
	DB	0b9H
	DB	079H
	DB	0f9H
	DB	05H
	DB	085H
	DB	045H
	DB	0c5H
	DB	025H
	DB	0a5H
	DB	065H
	DB	0e5H
	DB	015H
	DB	095H
	DB	055H
	DB	0d5H
	DB	035H
	DB	0b5H
	DB	075H
	DB	0f5H
	DB	0dH
	DB	08dH
	DB	04dH
	DB	0cdH
	DB	02dH
	DB	0adH
	DB	06dH
	DB	0edH
	DB	01dH
	DB	09dH
	DB	05dH
	DB	0ddH
	DB	03dH
	DB	0bdH
	DB	07dH
	DB	0fdH
	DB	03H
	DB	083H
	DB	043H
	DB	0c3H
	DB	023H
	DB	0a3H
	DB	063H
	DB	0e3H
	DB	013H
	DB	093H
	DB	053H
	DB	0d3H
	DB	033H
	DB	0b3H
	DB	073H
	DB	0f3H
	DB	0bH
	DB	08bH
	DB	04bH
	DB	0cbH
	DB	02bH
	DB	0abH
	DB	06bH
	DB	0ebH
	DB	01bH
	DB	09bH
	DB	05bH
	DB	0dbH
	DB	03bH
	DB	0bbH
	DB	07bH
	DB	0fbH
	DB	07H
	DB	087H
	DB	047H
	DB	0c7H
	DB	027H
	DB	0a7H
	DB	067H
	DB	0e7H
	DB	017H
	DB	097H
	DB	057H
	DB	0d7H
	DB	037H
	DB	0b7H
	DB	077H
	DB	0f7H
	DB	0fH
	DB	08fH
	DB	04fH
	DB	0cfH
	DB	02fH
	DB	0afH
	DB	06fH
	DB	0efH
	DB	01fH
	DB	09fH
	DB	05fH
	DB	0dfH
	DB	03fH
	DB	0bfH
	DB	07fH
	DB	0ffH
_TIFFNoBitRevTable DB 00H
	DB	01H
	DB	02H
	DB	03H
	DB	04H
	DB	05H
	DB	06H
	DB	07H
	DB	08H
	DB	09H
	DB	0aH
	DB	0bH
	DB	0cH
	DB	0dH
	DB	0eH
	DB	0fH
	DB	010H
	DB	011H
	DB	012H
	DB	013H
	DB	014H
	DB	015H
	DB	016H
	DB	017H
	DB	018H
	DB	019H
	DB	01aH
	DB	01bH
	DB	01cH
	DB	01dH
	DB	01eH
	DB	01fH
	DB	020H
	DB	021H
	DB	022H
	DB	023H
	DB	024H
	DB	025H
	DB	026H
	DB	027H
	DB	028H
	DB	029H
	DB	02aH
	DB	02bH
	DB	02cH
	DB	02dH
	DB	02eH
	DB	02fH
	DB	030H
	DB	031H
	DB	032H
	DB	033H
	DB	034H
	DB	035H
	DB	036H
	DB	037H
	DB	038H
	DB	039H
	DB	03aH
	DB	03bH
	DB	03cH
	DB	03dH
	DB	03eH
	DB	03fH
	DB	040H
	DB	041H
	DB	042H
	DB	043H
	DB	044H
	DB	045H
	DB	046H
	DB	047H
	DB	048H
	DB	049H
	DB	04aH
	DB	04bH
	DB	04cH
	DB	04dH
	DB	04eH
	DB	04fH
	DB	050H
	DB	051H
	DB	052H
	DB	053H
	DB	054H
	DB	055H
	DB	056H
	DB	057H
	DB	058H
	DB	059H
	DB	05aH
	DB	05bH
	DB	05cH
	DB	05dH
	DB	05eH
	DB	05fH
	DB	060H
	DB	061H
	DB	062H
	DB	063H
	DB	064H
	DB	065H
	DB	066H
	DB	067H
	DB	068H
	DB	069H
	DB	06aH
	DB	06bH
	DB	06cH
	DB	06dH
	DB	06eH
	DB	06fH
	DB	070H
	DB	071H
	DB	072H
	DB	073H
	DB	074H
	DB	075H
	DB	076H
	DB	077H
	DB	078H
	DB	079H
	DB	07aH
	DB	07bH
	DB	07cH
	DB	07dH
	DB	07eH
	DB	07fH
	DB	080H
	DB	081H
	DB	082H
	DB	083H
	DB	084H
	DB	085H
	DB	086H
	DB	087H
	DB	088H
	DB	089H
	DB	08aH
	DB	08bH
	DB	08cH
	DB	08dH
	DB	08eH
	DB	08fH
	DB	090H
	DB	091H
	DB	092H
	DB	093H
	DB	094H
	DB	095H
	DB	096H
	DB	097H
	DB	098H
	DB	099H
	DB	09aH
	DB	09bH
	DB	09cH
	DB	09dH
	DB	09eH
	DB	09fH
	DB	0a0H
	DB	0a1H
	DB	0a2H
	DB	0a3H
	DB	0a4H
	DB	0a5H
	DB	0a6H
	DB	0a7H
	DB	0a8H
	DB	0a9H
	DB	0aaH
	DB	0abH
	DB	0acH
	DB	0adH
	DB	0aeH
	DB	0afH
	DB	0b0H
	DB	0b1H
	DB	0b2H
	DB	0b3H
	DB	0b4H
	DB	0b5H
	DB	0b6H
	DB	0b7H
	DB	0b8H
	DB	0b9H
	DB	0baH
	DB	0bbH
	DB	0bcH
	DB	0bdH
	DB	0beH
	DB	0bfH
	DB	0c0H
	DB	0c1H
	DB	0c2H
	DB	0c3H
	DB	0c4H
	DB	0c5H
	DB	0c6H
	DB	0c7H
	DB	0c8H
	DB	0c9H
	DB	0caH
	DB	0cbH
	DB	0ccH
	DB	0cdH
	DB	0ceH
	DB	0cfH
	DB	0d0H
	DB	0d1H
	DB	0d2H
	DB	0d3H
	DB	0d4H
	DB	0d5H
	DB	0d6H
	DB	0d7H
	DB	0d8H
	DB	0d9H
	DB	0daH
	DB	0dbH
	DB	0dcH
	DB	0ddH
	DB	0deH
	DB	0dfH
	DB	0e0H
	DB	0e1H
	DB	0e2H
	DB	0e3H
	DB	0e4H
	DB	0e5H
	DB	0e6H
	DB	0e7H
	DB	0e8H
	DB	0e9H
	DB	0eaH
	DB	0ebH
	DB	0ecH
	DB	0edH
	DB	0eeH
	DB	0efH
	DB	0f0H
	DB	0f1H
	DB	0f2H
	DB	0f3H
	DB	0f4H
	DB	0f5H
	DB	0f6H
	DB	0f7H
	DB	0f8H
	DB	0f9H
	DB	0faH
	DB	0fbH
	DB	0fcH
	DB	0fdH
	DB	0feH
	DB	0ffH
CONST	ENDS
PUBLIC	_TIFFSwabShort
_TEXT	SEGMENT
_wp$ = 8
_cp$ = -4
_t$ = -8
_TIFFSwabShort PROC NEAR

; 37   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 38   : 	register u_char* cp = (u_char*) wp;

	mov	eax, DWORD PTR _wp$[ebp]
	mov	DWORD PTR _cp$[ebp], eax

; 39   : 	int t;
; 40   : 
; 41   : 	t = cp[1]; cp[1] = cp[0]; cp[0] = t;

	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	mov	DWORD PTR _t$[ebp], edx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	dl, BYTE PTR [ecx]
	mov	BYTE PTR [eax+1], dl
	mov	eax, DWORD PTR _cp$[ebp]
	mov	cl, BYTE PTR _t$[ebp]
	mov	BYTE PTR [eax], cl

; 42   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFSwabShort ENDP
_TEXT	ENDS
PUBLIC	_TIFFSwabLong
_TEXT	SEGMENT
_lp$ = 8
_cp$ = -4
_t$ = -8
_TIFFSwabLong PROC NEAR

; 48   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 49   : 	register u_char* cp = (u_char*) lp;

	mov	eax, DWORD PTR _lp$[ebp]
	mov	DWORD PTR _cp$[ebp], eax

; 50   : 	int t;
; 51   : 
; 52   : 	t = cp[3]; cp[3] = cp[0]; cp[0] = t;

	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+3]
	mov	DWORD PTR _t$[ebp], edx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	dl, BYTE PTR [ecx]
	mov	BYTE PTR [eax+3], dl
	mov	eax, DWORD PTR _cp$[ebp]
	mov	cl, BYTE PTR _t$[ebp]
	mov	BYTE PTR [eax], cl

; 53   : 	t = cp[2]; cp[2] = cp[1]; cp[1] = t;

	mov	edx, DWORD PTR _cp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	mov	DWORD PTR _t$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	mov	al, BYTE PTR [edx+1]
	mov	BYTE PTR [ecx+2], al
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	dl, BYTE PTR _t$[ebp]
	mov	BYTE PTR [ecx+1], dl

; 54   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFSwabLong ENDP
_TEXT	ENDS
PUBLIC	_TIFFSwabArrayOfShort
_TEXT	SEGMENT
_wp$ = 8
_n$ = 12
_cp$ = -4
_t$ = -8
_TIFFSwabArrayOfShort PROC NEAR

; 60   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8
$L65803:

; 61   : 	register u_char* cp;
; 62   : 	register int t;
; 63   : 
; 64   : 	/* XXX unroll loop some */
; 65   : 	while (n-- > 0) {

	mov	eax, DWORD PTR _n$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	test	eax, eax
	jbe	SHORT $L65804

; 66   : 		cp = (u_char*) wp;

	mov	edx, DWORD PTR _wp$[ebp]
	mov	DWORD PTR _cp$[ebp], edx

; 67   : 		t = cp[1]; cp[1] = cp[0]; cp[0] = t;

	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	DWORD PTR _t$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	mov	cl, BYTE PTR [eax]
	mov	BYTE PTR [edx+1], cl
	mov	edx, DWORD PTR _cp$[ebp]
	mov	al, BYTE PTR _t$[ebp]
	mov	BYTE PTR [edx], al

; 68   : 		wp++;

	mov	ecx, DWORD PTR _wp$[ebp]
	add	ecx, 2
	mov	DWORD PTR _wp$[ebp], ecx

; 69   : 	}

	jmp	SHORT $L65803
$L65804:

; 70   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFSwabArrayOfShort ENDP
_TEXT	ENDS
PUBLIC	_TIFFSwabArrayOfLong
_TEXT	SEGMENT
_lp$ = 8
_n$ = 12
_cp$ = -4
_t$ = -8
_TIFFSwabArrayOfLong PROC NEAR

; 76   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8
$L65814:

; 77   : 	register unsigned char *cp;
; 78   : 	register int t;
; 79   : 
; 80   : 	/* XXX unroll loop some */
; 81   : 	while (n-- > 0) {

	mov	eax, DWORD PTR _n$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	test	eax, eax
	jbe	SHORT $L65815

; 82   : 		cp = (unsigned char *)lp;

	mov	edx, DWORD PTR _lp$[ebp]
	mov	DWORD PTR _cp$[ebp], edx

; 83   : 		t = cp[3]; cp[3] = cp[0]; cp[0] = t;

	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+3]
	mov	DWORD PTR _t$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	mov	cl, BYTE PTR [eax]
	mov	BYTE PTR [edx+3], cl
	mov	edx, DWORD PTR _cp$[ebp]
	mov	al, BYTE PTR _t$[ebp]
	mov	BYTE PTR [edx], al

; 84   : 		t = cp[2]; cp[2] = cp[1]; cp[1] = t;

	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+2]
	mov	DWORD PTR _t$[ebp], edx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	dl, BYTE PTR [ecx+1]
	mov	BYTE PTR [eax+2], dl
	mov	eax, DWORD PTR _cp$[ebp]
	mov	cl, BYTE PTR _t$[ebp]
	mov	BYTE PTR [eax+1], cl

; 85   : 		lp++;

	mov	edx, DWORD PTR _lp$[ebp]
	add	edx, 4
	mov	DWORD PTR _lp$[ebp], edx

; 86   : 	}

	jmp	SHORT $L65814
$L65815:

; 87   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFSwabArrayOfLong ENDP
_TEXT	ENDS
PUBLIC	_TIFFSwabDouble
_TEXT	SEGMENT
_dp$ = 8
_lp$ = -8
_t$ = -4
_TIFFSwabDouble PROC NEAR

; 93   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 94   :         register uint32* lp = (uint32*) dp;

	mov	eax, DWORD PTR _dp$[ebp]
	mov	DWORD PTR _lp$[ebp], eax

; 95   :         uint32 t;
; 96   : 
; 97   : 	TIFFSwabArrayOfLong(lp, 2);

	push	2
	mov	ecx, DWORD PTR _lp$[ebp]
	push	ecx
	call	_TIFFSwabArrayOfLong
	add	esp, 8

; 98   : 	t = lp[0]; lp[0] = lp[1]; lp[1] = t;

	mov	edx, DWORD PTR _lp$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR _t$[ebp], eax
	mov	ecx, DWORD PTR _lp$[ebp]
	mov	edx, DWORD PTR _lp$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR [ecx], eax
	mov	ecx, DWORD PTR _lp$[ebp]
	mov	edx, DWORD PTR _t$[ebp]
	mov	DWORD PTR [ecx+4], edx

; 99   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFSwabDouble ENDP
_TEXT	ENDS
PUBLIC	_TIFFSwabArrayOfDouble
_TEXT	SEGMENT
_dp$ = 8
_n$ = 12
_lp$ = -8
_t$ = -4
_TIFFSwabArrayOfDouble PROC NEAR

; 105  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 106  : 	register uint32* lp = (uint32*) dp;

	mov	eax, DWORD PTR _dp$[ebp]
	mov	DWORD PTR _lp$[ebp], eax

; 107  :         register uint32 t;
; 108  : 
; 109  : 	TIFFSwabArrayOfLong(lp, n + n);

	mov	ecx, DWORD PTR _n$[ebp]
	add	ecx, DWORD PTR _n$[ebp]
	push	ecx
	mov	edx, DWORD PTR _lp$[ebp]
	push	edx
	call	_TIFFSwabArrayOfLong
	add	esp, 8
$L65832:

; 110  :         while (n-- > 0) {

	mov	eax, DWORD PTR _n$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	test	eax, eax
	jbe	SHORT $L65833

; 111  : 		t = lp[0]; lp[0] = lp[1]; lp[1] = t;

	mov	edx, DWORD PTR _lp$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR _t$[ebp], eax
	mov	ecx, DWORD PTR _lp$[ebp]
	mov	edx, DWORD PTR _lp$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR [ecx], eax
	mov	ecx, DWORD PTR _lp$[ebp]
	mov	edx, DWORD PTR _t$[ebp]
	mov	DWORD PTR [ecx+4], edx

; 112  :                 lp += 2;

	mov	eax, DWORD PTR _lp$[ebp]
	add	eax, 8
	mov	DWORD PTR _lp$[ebp], eax

; 113  :         }

	jmp	SHORT $L65832
$L65833:

; 114  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFSwabArrayOfDouble ENDP
_TEXT	ENDS
PUBLIC	_TIFFGetBitRevTable
_TEXT	SEGMENT
_reversed$ = 8
_TIFFGetBitRevTable PROC NEAR

; 197  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 198  : 	return (reversed ? TIFFBitRevTable : TIFFNoBitRevTable);

	cmp	DWORD PTR _reversed$[ebp], 0
	je	SHORT $L65859
	mov	DWORD PTR -4+[ebp], OFFSET FLAT:_TIFFBitRevTable
	jmp	SHORT $L65860
$L65859:
	mov	DWORD PTR -4+[ebp], OFFSET FLAT:_TIFFNoBitRevTable
$L65860:
	mov	eax, DWORD PTR -4+[ebp]

; 199  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFGetBitRevTable ENDP
_TEXT	ENDS
PUBLIC	_TIFFReverseBits
_TEXT	SEGMENT
_cp$ = 8
_n$ = 12
_TIFFReverseBits PROC NEAR

; 203  : {

	push	ebp
	mov	ebp, esp

; 204  : 	for (; n > 8; n -= 8) {

	jmp	SHORT $L65844
$L65845:
	mov	eax, DWORD PTR _n$[ebp]
	sub	eax, 8
	mov	DWORD PTR _n$[ebp], eax
$L65844:
	cmp	DWORD PTR _n$[ebp], 8
	jbe	$L65846

; 205  : 		cp[0] = TIFFBitRevTable[cp[0]];

	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _cp$[ebp]
	mov	cl, BYTE PTR _TIFFBitRevTable[edx]
	mov	BYTE PTR [eax], cl

; 206  : 		cp[1] = TIFFBitRevTable[cp[1]];

	mov	edx, DWORD PTR _cp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	dl, BYTE PTR _TIFFBitRevTable[eax]
	mov	BYTE PTR [ecx+1], dl

; 207  : 		cp[2] = TIFFBitRevTable[cp[2]];

	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+2]
	mov	edx, DWORD PTR _cp$[ebp]
	mov	al, BYTE PTR _TIFFBitRevTable[ecx]
	mov	BYTE PTR [edx+2], al

; 208  : 		cp[3] = TIFFBitRevTable[cp[3]];

	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+3]
	mov	eax, DWORD PTR _cp$[ebp]
	mov	cl, BYTE PTR _TIFFBitRevTable[edx]
	mov	BYTE PTR [eax+3], cl

; 209  : 		cp[4] = TIFFBitRevTable[cp[4]];

	mov	edx, DWORD PTR _cp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+4]
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	dl, BYTE PTR _TIFFBitRevTable[eax]
	mov	BYTE PTR [ecx+4], dl

; 210  : 		cp[5] = TIFFBitRevTable[cp[5]];

	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+5]
	mov	edx, DWORD PTR _cp$[ebp]
	mov	al, BYTE PTR _TIFFBitRevTable[ecx]
	mov	BYTE PTR [edx+5], al

; 211  : 		cp[6] = TIFFBitRevTable[cp[6]];

	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+6]
	mov	eax, DWORD PTR _cp$[ebp]
	mov	cl, BYTE PTR _TIFFBitRevTable[edx]
	mov	BYTE PTR [eax+6], cl

; 212  : 		cp[7] = TIFFBitRevTable[cp[7]];

	mov	edx, DWORD PTR _cp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+7]
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	dl, BYTE PTR _TIFFBitRevTable[eax]
	mov	BYTE PTR [ecx+7], dl

; 213  : 		cp += 8;

	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 8
	mov	DWORD PTR _cp$[ebp], eax

; 214  : 	}

	jmp	$L65845
$L65846:

; 215  : 	while (n-- > 0)

	mov	ecx, DWORD PTR _n$[ebp]
	mov	edx, DWORD PTR _n$[ebp]
	sub	edx, 1
	mov	DWORD PTR _n$[ebp], edx
	test	ecx, ecx
	jbe	SHORT $L65849

; 216  : 		*cp = TIFFBitRevTable[*cp], cp++;

	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _cp$[ebp]
	mov	al, BYTE PTR _TIFFBitRevTable[ecx]
	mov	BYTE PTR [edx], al
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	jmp	SHORT $L65846
$L65849:

; 217  : }

	pop	ebp
	ret	0
_TIFFReverseBits ENDP
_TEXT	ENDS
END
