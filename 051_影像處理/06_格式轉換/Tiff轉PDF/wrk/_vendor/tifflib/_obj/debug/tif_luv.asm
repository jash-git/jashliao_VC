	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_luv.c
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
_?initialized@?1??oog_encode@@9@9 DD 01H DUP (?)
_BSS	ENDS
_DATA	SEGMENT
_uv_row	DD	03e7d9b5fr			; 0.247663
	DW	04H
	DW	00H
	DD	03e79a134r			; 0.243779
	DW	06H
	DW	04H
	DD	03e777c03r			; 0.241684
	DW	07H
	DW	0aH
	DD	03e73953er			; 0.237874
	DW	09H
	DW	011H
	DD	03e719158r			; 0.235906
	DW	0aH
	DW	01aH
	DD	03e6db984r			; 0.232153
	DW	0cH
	DW	024H
	DD	03e69d51br			; 0.228352
	DW	0eH
	DW	030H
	DD	03e67b070r			; 0.226259
	DW	0fH
	DW	03eH
	DD	03e63b539r			; 0.222371
	DW	011H
	DW	04dH
	DD	03e61b329r			; 0.22041
	DW	012H
	DW	05eH
	DD	03e5bdcf0r			; 0.21471
	DW	015H
	DW	070H
	DD	03e59d1b3r			; 0.212714
	DW	016H
	DW	085H
	DD	03e57c73fr			; 0.210721
	DW	017H
	DW	09bH
	DD	03e51e53br			; 0.204976
	DW	01aH
	DW	0b2H
	DD	03e4fdb90r			; 0.202986
	DW	01bH
	DW	0ccH
	DD	03e4c06e2r			; 0.199245
	DW	01dH
	DW	0e7H
	DD	03e4837b5r			; 0.195525
	DW	01fH
	DW	0104H
	DD	03e463498r			; 0.19356
	DW	020H
	DW	0123H
	DD	03e426f61r			; 0.189878
	DW	022H
	DW	0143H
	DD	03e3eaf68r			; 0.186216
	DW	024H
	DW	0165H
	DD	03e3eaf68r			; 0.186216
	DW	024H
	DW	0189H
	DD	03e3af966r			; 0.182592
	DW	026H
	DW	01adH
	DD	03e374c90r			; 0.179003
	DW	028H
	DW	01d3H
	DD	03e33ad5cr			; 0.175466
	DW	02aH
	DW	01fbH
	DD	03e302108r			; 0.172001
	DW	02cH
	DW	0225H
	DD	03e302108r			; 0.172001
	DW	02cH
	DW	0251H
	DD	03e2ca8a0r			; 0.168612
	DW	02eH
	DW	027dH
	DD	03e2ca8a0r			; 0.168612
	DW	02eH
	DW	02abH
	DD	03e278034r			; 0.163575
	DW	031H
	DW	02d9H
	DD	03e22730cr			; 0.158642
	DW	034H
	DW	030aH
	DD	03e22730cr			; 0.158642
	DW	034H
	DW	033eH
	DD	03e22730cr			; 0.158642
	DW	034H
	DW	0372H
	DD	03e1d81aer			; 0.153815
	DW	037H
	DW	03a6H
	DD	03e1d81aer			; 0.153815
	DW	037H
	DW	03ddH
	DD	03e18ace2r			; 0.149097
	DW	03aH
	DW	0414H
	DD	03e18ace2r			; 0.149097
	DW	03aH
	DW	044eH
	DD	03e122c02r			; 0.142746
	DW	03eH
	DW	0488H
	DD	03e122c02r			; 0.142746
	DW	03eH
	DW	04c6H
	DD	03e122c02r			; 0.142746
	DW	03eH
	DW	0504H
	DD	03e0d96a7r			; 0.13827
	DW	041H
	DW	0542H
	DD	03e0d96a7r			; 0.13827
	DW	041H
	DW	0583H
	DD	03e0d96a7r			; 0.13827
	DW	041H
	DW	05c4H
	DD	03e075686r			; 0.132166
	DW	045H
	DW	0605H
	DD	03e075686r			; 0.132166
	DW	045H
	DW	064aH
	DD	03e013b9fr			; 0.126204
	DW	049H
	DW	068fH
	DD	03e013b9fr			; 0.126204
	DW	049H
	DW	06d8H
	DD	03e013b9fr			; 0.126204
	DW	049H
	DW	0721H
	DD	03df68a50r			; 0.120381
	DW	04dH
	DW	076aH
	DD	03df68a50r			; 0.120381
	DW	04dH
	DW	07b7H
	DD	03df68a50r			; 0.120381
	DW	04dH
	DW	0804H
	DD	03df68a50r			; 0.120381
	DW	04dH
	DW	0851H
	DD	03de7589fr			; 0.112962
	DW	052H
	DW	089eH
	DD	03de7589fr			; 0.112962
	DW	052H
	DW	08f0H
	DD	03de7589fr			; 0.112962
	DW	052H
	DW	0942H
	DD	03ddc0ebfr			; 0.10745
	DW	056H
	DW	0994H
	DD	03ddc0ebfr			; 0.10745
	DW	056H
	DW	09eaH
	DD	03ddc0ebfr			; 0.10745
	DW	056H
	DW	0a40H
	DD	03ddc0ebfr			; 0.10745
	DW	056H
	DW	0a96H
	DD	03dcd80a1r			; 0.100343
	DW	05bH
	DW	0aecH
	DD	03dcd80a1r			; 0.100343
	DW	05bH
	DW	0b47H
	DD	03dcd80a1r			; 0.100343
	DW	05bH
	DW	0ba2H
	DD	03dc2d16cr			; 0.095126
	DW	05fH
	DW	0bfdH
	DD	03dc2d16cr			; 0.095126
	DW	05fH
	DW	0c5cH
	DD	03dc2d16cr			; 0.095126
	DW	05fH
	DW	0cbbH
	DD	03dc2d16cr			; 0.095126
	DW	05fH
	DW	0d1aH
	DD	03db4ca0cr			; 0.088276
	DW	064H
	DW	0d79H
	DD	03db4ca0cr			; 0.088276
	DW	064H
	DW	0dddH
	DD	03db4ca0cr			; 0.088276
	DW	064H
	DW	0e41H
	DD	03db4ca0cr			; 0.088276
	DW	064H
	DW	0ea5H
	DD	03da6f588r			; 0.081523
	DW	069H
	DW	0f09H
	DD	03da6f588r			; 0.081523
	DW	069H
	DW	0f72H
	DD	03da6f588r			; 0.081523
	DW	069H
	DW	0fdbH
	DD	03da6f588r			; 0.081523
	DW	069H
	DW	01044H
	DD	03d9950b9r			; 0.074861
	DW	06eH
	DW	010adH
	DD	03d9950b9r			; 0.074861
	DW	06eH
	DW	0111bH
	DD	03d9950b9r			; 0.074861
	DW	06eH
	DW	01189H
	DD	03d9950b9r			; 0.074861
	DW	06eH
	DW	011f7H
	DD	03d8bdba1r			; 0.06829
	DW	073H
	DW	01265H
	DD	03d8bdba1r			; 0.06829
	DW	073H
	DW	012d8H
	DD	03d8bdba1r			; 0.06829
	DW	073H
	DW	0134bH
	DD	03d8bdba1r			; 0.06829
	DW	073H
	DW	013beH
	DD	03d823290r			; 0.063573
	DW	077H
	DW	01431H
	DD	03d823290r			; 0.063573
	DW	077H
	DW	014a8H
	DD	03d823290r			; 0.063573
	DW	077H
	DW	0151fH
	DD	03d823290r			; 0.063573
	DW	077H
	DW	01596H
	DD	03d6a5e78r			; 0.057219
	DW	07cH
	DW	0160dH
	DD	03d6a5e78r			; 0.057219
	DW	07cH
	DW	01689H
	DD	03d6a5e78r			; 0.057219
	DW	07cH
	DW	01705H
	DD	03d6a5e78r			; 0.057219
	DW	07cH
	DW	01781H
	DD	03d50d5a6r			; 0.050985
	DW	081H
	DW	017fdH
	DD	03d50d5a6r			; 0.050985
	DW	081H
	DW	0187eH
	DD	03d50d5a6r			; 0.050985
	DW	081H
	DW	018ffH
	DD	03d50d5a6r			; 0.050985
	DW	081H
	DW	01980H
	DD	03d50d5a6r			; 0.050985
	DW	081H
	DW	01a01H
	DD	03d37be12r			; 0.044859
	DW	086H
	DW	01a82H
	DD	03d37be12r			; 0.044859
	DW	086H
	DW	01b08H
	DD	03d37be12r			; 0.044859
	DW	086H
	DW	01b8eH
	DD	03d37be12r			; 0.044859
	DW	086H
	DW	01c14H
	DD	03d262dc7r			; 0.040571
	DW	08aH
	DW	01c9aH
	DD	03d262dc7r			; 0.040571
	DW	08aH
	DW	01d24H
	DD	03d262dc7r			; 0.040571
	DW	08aH
	DW	01daeH
	DD	03d262dc7r			; 0.040571
	DW	08aH
	DW	01e38H
	DD	03d14d834r			; 0.036339
	DW	08eH
	DW	01ec2H
	DD	03d14d834r			; 0.036339
	DW	08eH
	DW	01f50H
	DD	03d14d834r			; 0.036339
	DW	08eH
	DW	01fdeH
	DD	03d14d834r			; 0.036339
	DW	08eH
	DW	0206cH
	DD	03d03a42fr			; 0.032139
	DW	092H
	DW	020faH
	DD	03d03a42fr			; 0.032139
	DW	092H
	DW	0218cH
	DD	03d03a42fr			; 0.032139
	DW	092H
	DW	0221eH
	DD	03d03a42fr			; 0.032139
	DW	092H
	DW	022b0H
	DD	03ce4f11br			; 0.027947
	DW	096H
	DW	02342H
	DD	03ce4f11br			; 0.027947
	DW	096H
	DW	023d8H
	DD	03ce4f11br			; 0.027947
	DW	096H
	DW	0246eH
	DD	03cc2784br			; 0.023739
	DW	09aH
	DW	02504H
	DD	03cc2784br			; 0.023739
	DW	09aH
	DW	0259eH
	DD	03cc2784br			; 0.023739
	DW	09aH
	DW	02638H
	DD	03cc2784br			; 0.023739
	DW	09aH
	DW	026d2H
	DD	03c9fc6dar			; 0.019504
	DW	09eH
	DW	0276cH
	DD	03c9fc6dar			; 0.019504
	DW	09eH
	DW	0280aH
	DD	03c9fc6dar			; 0.019504
	DW	09eH
	DW	028a8H
	DD	03c8b1141r			; 0.016976
	DW	0a1H
	DW	02946H
	DD	03c8b1141r			; 0.016976
	DW	0a1H
	DW	029e7H
	DD	03c8b1141r			; 0.016976
	DW	0a1H
	DW	02a88H
	DD	03c8b1141r			; 0.016976
	DW	0a1H
	DW	02b29H
	DD	03c4f13cfr			; 0.012639
	DW	0a5H
	DW	02bcaH
	DD	03c4f13cfr			; 0.012639
	DW	0a5H
	DW	02c6fH
	DD	03c4f13cfr			; 0.012639
	DW	0a5H
	DW	02d14H
	DD	03c23b14br			; 0.009991
	DW	0a8H
	DW	02db9H
	DD	03c23b14br			; 0.009991
	DW	0a8H
	DW	02e61H
	DD	03c23b14br			; 0.009991
	DW	0a8H
	DW	02f09H
	DD	03c13b7d8r			; 0.009016
	DW	0aaH
	DW	02fb1H
	DD	03c13b7d8r			; 0.009016
	DW	0aaH
	DW	0305bH
	DD	03c13b7d8r			; 0.009016
	DW	0aaH
	DW	03105H
	DD	03bcbb7far			; 0.006217
	DW	0adH
	DW	031afH
	DD	03bcbb7far			; 0.006217
	DW	0adH
	DW	0325cH
	DD	03ba704bcr			; 0.005097
	DW	0afH
	DW	03309H
	DD	03ba704bcr			; 0.005097
	DW	0afH
	DW	033b8H
	DD	03ba704bcr			; 0.005097
	DW	0afH
	DW	03467H
	DD	03b801712r			; 0.003909
	DW	0b1H
	DW	03516H
	DD	03b801712r			; 0.003909
	DW	0b1H
	DW	035c7H
	DD	03b195aafr			; 0.00234
	DW	0b1H
	DW	03678H
	DD	03b1c90c5r			; 0.002389
	DW	0aaH
	DW	03729H
	DD	03a8bfc22r			; 0.001068
	DW	0a4H
	DW	037d3H
	DD	03ad8a97ar			; 0.001653
	DW	09dH
	DW	03877H
	DD	03a3bf50er			; 0.000717
	DW	096H
	DW	03914H
	DD	03ad38cdar			; 0.001614
	DW	08fH
	DW	039aaH
	DD	0398d8ec9r			; 0.00027
	DW	088H
	DW	03a39H
	DD	039fdc161r			; 0.000484
	DW	081H
	DW	03ac1H
	DD	03a90928ar			; 0.001103
	DW	07bH
	DW	03b42H
	DD	03aa2ca9br			; 0.001242
	DW	073H
	DW	03bbdH
	DD	03a9bb6aar			; 0.001188
	DW	06dH
	DW	03c30H
	DD	03a848388r			; 0.001011
	DW	067H
	DW	03c9dH
	DD	03a39dc2fr			; 0.000709
	DW	061H
	DW	03d04H
	DD	0399dcf89r			; 0.000301
	DW	059H
	DW	03d65H
	DD	03b1e55c1r			; 0.002416
	DW	052H
	DW	03dbeH
	DD	03b550ebbr			; 0.003251
	DW	04cH
	DW	03e10H
	DD	03b54bad8r			; 0.003246
	DW	045H
	DW	03e5cH
	DD	03b87b13ar			; 0.004141
	DW	03eH
	DW	03ea1H
	DD	03bc36545r			; 0.005963
	DW	037H
	DW	03edfH
	DD	03c10d174r			; 0.008839
	DW	02fH
	DW	03f16H
	DD	03c2bde40r			; 0.01049
	DW	028H
	DW	03f45H
	DD	03c8b3700r			; 0.016994
	DW	01fH
	DW	03f6dH
	DD	03cc1d085r			; 0.023659
	DW	015H
	DW	03f8cH
_DATA	ENDS
CONST	SEGMENT
_?module@?1??LogL16InitState@@9@9 DB 'LogL16InitState', 00H
_?module@?1??LogLuvInitState@@9@9 DB 'LogLuvInitState', 00H
_LogLuvFieldInfo DD 010018H
	DW	00H
	DW	00H
	DD	03H
	DW	00H
	DB	01H
	DB	00H
	DD	FLAT:$SG67276
	DD	010019H
	DW	00H
	DW	00H
	DD	03H
	DW	00H
	DB	01H
	DB	00H
	DD	FLAT:$SG67277
_?module@?1??TIFFInitSGILog@@9@9 DB 'TIFFInitSGILog', 00H
CONST	ENDS
_DATA	SEGMENT
$SG67276 DB	'SGILogDataFmt', 00H
	ORG $+2
$SG67277 DB	'SGILogEncode', 00H
_DATA	ENDS
PUBLIC	__real@8@00000000000000000000
PUBLIC	__real@8@3ffe8000000000000000
PUBLIC	__real@8@3ff6b17217f7d1cf7800
PUBLIC	__real@8@4004b17217f7d1cf7800
PUBLIC	_LogL16toY
EXTRN	_exp:NEAR
EXTRN	__fltused:NEAR
;	COMDAT __real@8@00000000000000000000
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_luv.c
CONST	SEGMENT
__real@8@00000000000000000000 DQ 00000000000000000r ; 0
CONST	ENDS
;	COMDAT __real@8@3ffe8000000000000000
CONST	SEGMENT
__real@8@3ffe8000000000000000 DQ 03fe0000000000000r ; 0.5
CONST	ENDS
;	COMDAT __real@8@3ff6b17217f7d1cf7800
CONST	SEGMENT
__real@8@3ff6b17217f7d1cf7800 DQ 03f662e42fefa39efr ; 0.00270761
CONST	ENDS
;	COMDAT __real@8@4004b17217f7d1cf7800
CONST	SEGMENT
__real@8@4004b17217f7d1cf7800 DQ 040462e42fefa39efr ; 44.3614
CONST	ENDS
_TEXT	SEGMENT
_p16$ = 8
_Le$ = -12
_Y$ = -8
_LogL16toY PROC NEAR

; 651  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 20					; 00000014H

; 652  : 	int	Le = p16 & 0x7fff;

	mov	eax, DWORD PTR _p16$[ebp]
	and	eax, 32767				; 00007fffH
	mov	DWORD PTR _Le$[ebp], eax

; 653  : 	double	Y;
; 654  : 
; 655  : 	if (!Le)

	cmp	DWORD PTR _Le$[ebp], 0
	jne	SHORT $L66538

; 656  : 		return (0.);

	fld	QWORD PTR __real@8@00000000000000000000
	jmp	SHORT $L66535
$L66538:

; 657  : 	Y = exp(M_LN2/256.*(Le+.5) - M_LN2*64.);

	fild	DWORD PTR _Le$[ebp]
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	fmul	QWORD PTR __real@8@3ff6b17217f7d1cf7800
	fsub	QWORD PTR __real@8@4004b17217f7d1cf7800
	sub	esp, 8
	fstp	QWORD PTR [esp]
	call	_exp
	add	esp, 8
	fstp	QWORD PTR _Y$[ebp]

; 658  : 	return (!(p16 & 0x8000) ? Y : -Y);

	mov	ecx, DWORD PTR _p16$[ebp]
	and	ecx, 32768				; 00008000H
	test	ecx, ecx
	jne	SHORT $L67300
	mov	edx, DWORD PTR _Y$[ebp]
	mov	DWORD PTR -20+[ebp], edx
	mov	eax, DWORD PTR _Y$[ebp+4]
	mov	DWORD PTR -20+[ebp+4], eax
	jmp	SHORT $L67301
$L67300:
	fld	QWORD PTR _Y$[ebp]
	fchs
	fstp	QWORD PTR -20+[ebp]
$L67301:
	fld	QWORD PTR -20+[ebp]
$L66535:

; 659  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogL16toY ENDP
_TEXT	ENDS
PUBLIC	__real@8@403efef65ed546008000
PUBLIC	__real@8@c03efef65ed546008000
PUBLIC	__real@8@3fbeffa7567c5445a800
PUBLIC	__real@8@3fffb8aa3b295c17f000
PUBLIC	__real@8@40058000000000000000
PUBLIC	__real@8@40078000000000000000
PUBLIC	__real@8@3ff08001000200040000
PUBLIC	__real@8@bfbeffa7567c5445a800
PUBLIC	_LogL16fromY
EXTRN	_log:NEAR
EXTRN	_rand:NEAR
EXTRN	__ftol:NEAR
;	COMDAT __real@8@403efef65ed546008000
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_luv.c
CONST	SEGMENT
__real@8@403efef65ed546008000 DQ 043efdecbdaa8c010r ; 1.8372e+019
CONST	ENDS
;	COMDAT __real@8@c03efef65ed546008000
CONST	SEGMENT
__real@8@c03efef65ed546008000 DQ 0c3efdecbdaa8c010r ; -1.8372e+019
CONST	ENDS
;	COMDAT __real@8@3fbeffa7567c5445a800
CONST	SEGMENT
__real@8@3fbeffa7567c5445a800 DQ 03beff4eacf8a88b5r ; 5.41368e-020
CONST	ENDS
;	COMDAT __real@8@3fffb8aa3b295c17f000
CONST	SEGMENT
__real@8@3fffb8aa3b295c17f000 DQ 03ff71547652b82fer ; 1.4427
CONST	ENDS
;	COMDAT __real@8@40058000000000000000
CONST	SEGMENT
__real@8@40058000000000000000 DQ 04050000000000000r ; 64
CONST	ENDS
;	COMDAT __real@8@40078000000000000000
CONST	SEGMENT
__real@8@40078000000000000000 DQ 04070000000000000r ; 256
CONST	ENDS
;	COMDAT __real@8@3ff08001000200040000
CONST	SEGMENT
__real@8@3ff08001000200040000 DQ 03f00002000400080r ; 3.05185e-005
CONST	ENDS
;	COMDAT __real@8@bfbeffa7567c5445a800
CONST	SEGMENT
__real@8@bfbeffa7567c5445a800 DQ 0bbeff4eacf8a88b5r ; -5.41368e-020
CONST	ENDS
_TEXT	SEGMENT
_Y$ = 8
_em$ = 16
_LogL16fromY PROC NEAR

; 666  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 32					; 00000020H

; 667  : 	if (Y >= 1.8371976e19)

	fld	QWORD PTR _Y$[ebp]
	fcomp	QWORD PTR __real@8@403efef65ed546008000
	fnstsw	ax
	test	ah, 1
	jne	SHORT $L66544

; 668  : 		return (0x7fff);

	mov	eax, 32767				; 00007fffH
	jmp	$L66543
$L66544:

; 669  : 	if (Y <= -1.8371976e19)

	fld	QWORD PTR _Y$[ebp]
	fcomp	QWORD PTR __real@8@c03efef65ed546008000
	fnstsw	ax
	test	ah, 65					; 00000041H
	je	SHORT $L66545

; 670  : 		return (0xffff);

	mov	eax, 65535				; 0000ffffH
	jmp	$L66543
$L66545:

; 671  : 	if (Y > 5.4136769e-20)

	fld	QWORD PTR _Y$[ebp]
	fcomp	QWORD PTR __real@8@3fbeffa7567c5445a800
	fnstsw	ax
	test	ah, 65					; 00000041H
	jne	$L66546

; 672  : 		return itrunc(256.*(log2(Y) + 64.), em);

	cmp	DWORD PTR _em$[ebp], 0
	jne	SHORT $L67312
	mov	eax, DWORD PTR _Y$[ebp+4]
	push	eax
	mov	ecx, DWORD PTR _Y$[ebp]
	push	ecx
	call	_log
	add	esp, 8
	fmul	QWORD PTR __real@8@3fffb8aa3b295c17f000
	fadd	QWORD PTR __real@8@40058000000000000000
	fmul	QWORD PTR __real@8@40078000000000000000
	call	__ftol
	mov	DWORD PTR -4+[ebp], eax
	jmp	SHORT $L67313
$L67312:
	mov	edx, DWORD PTR _Y$[ebp+4]
	push	edx
	mov	eax, DWORD PTR _Y$[ebp]
	push	eax
	call	_log
	add	esp, 8
	fmul	QWORD PTR __real@8@3fffb8aa3b295c17f000
	fadd	QWORD PTR __real@8@40058000000000000000
	fmul	QWORD PTR __real@8@40078000000000000000
	fstp	QWORD PTR -12+[ebp]
	call	_rand
	mov	DWORD PTR -16+[ebp], eax
	fild	DWORD PTR -16+[ebp]
	fmul	QWORD PTR __real@8@3ff08001000200040000
	fadd	QWORD PTR -12+[ebp]
	fsub	QWORD PTR __real@8@3ffe8000000000000000
	call	__ftol
	mov	DWORD PTR -4+[ebp], eax
$L67313:
	mov	eax, DWORD PTR -4+[ebp]
	jmp	$L66543
$L66546:

; 673  : 	if (Y < -5.4136769e-20)

	fld	QWORD PTR _Y$[ebp]
	fcomp	QWORD PTR __real@8@bfbeffa7567c5445a800
	fnstsw	ax
	test	ah, 1
	je	$L66549

; 674  : 		return (~0x7fff | itrunc(256.*(log2(-Y) + 64.), em));

	cmp	DWORD PTR _em$[ebp], 0
	jne	SHORT $L67314
	fld	QWORD PTR _Y$[ebp]
	fchs
	sub	esp, 8
	fstp	QWORD PTR [esp]
	call	_log
	add	esp, 8
	fmul	QWORD PTR __real@8@3fffb8aa3b295c17f000
	fadd	QWORD PTR __real@8@40058000000000000000
	fmul	QWORD PTR __real@8@40078000000000000000
	call	__ftol
	mov	DWORD PTR -20+[ebp], eax
	jmp	SHORT $L67315
$L67314:
	fld	QWORD PTR _Y$[ebp]
	fchs
	sub	esp, 8
	fstp	QWORD PTR [esp]
	call	_log
	add	esp, 8
	fmul	QWORD PTR __real@8@3fffb8aa3b295c17f000
	fadd	QWORD PTR __real@8@40058000000000000000
	fmul	QWORD PTR __real@8@40078000000000000000
	fstp	QWORD PTR -28+[ebp]
	call	_rand
	mov	DWORD PTR -32+[ebp], eax
	fild	DWORD PTR -32+[ebp]
	fmul	QWORD PTR __real@8@3ff08001000200040000
	fadd	QWORD PTR -28+[ebp]
	fsub	QWORD PTR __real@8@3ffe8000000000000000
	call	__ftol
	mov	DWORD PTR -20+[ebp], eax
$L67315:
	mov	eax, DWORD PTR -20+[ebp]
	or	eax, -32768				; ffff8000H
	jmp	SHORT $L66543
$L66549:

; 675  : 	return (0);

	xor	eax, eax
$L66543:

; 676  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogL16fromY ENDP
_TEXT	ENDS
PUBLIC	__real@8@4000ac28f5c28f5c2800
PUBLIC	_XYZtoRGB24
PUBLIC	__real@8@bfffa353f7ced9168800
PUBLIC	__real@8@bffdd3f7ced916872800
PUBLIC	__real@8@bfff82d0e56041893800
PUBLIC	__real@8@3ffffd2f1a9fbe76c800
PUBLIC	__real@8@3ffab4395810624dd000
PUBLIC	__real@8@3ffaf9db22d0e5604000
PUBLIC	__real@8@bffce5604189374bc800
PUBLIC	__real@8@3fff94dd2f1a9fbe7800
PUBLIC	__real@8@3fff8000000000000000
EXTRN	_sqrt:NEAR
;	COMDAT __real@8@4000ac28f5c28f5c2800
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_luv.c
CONST	SEGMENT
__real@8@4000ac28f5c28f5c2800 DQ 04005851eb851eb85r ; 2.69
CONST	ENDS
;	COMDAT __real@8@bfffa353f7ced9168800
CONST	SEGMENT
__real@8@bfffa353f7ced9168800 DQ 0bff46a7ef9db22d1r ; -1.276
CONST	ENDS
;	COMDAT __real@8@bffdd3f7ced916872800
CONST	SEGMENT
__real@8@bffdd3f7ced916872800 DQ 0bfda7ef9db22d0e5r ; -0.414
CONST	ENDS
;	COMDAT __real@8@bfff82d0e56041893800
CONST	SEGMENT
__real@8@bfff82d0e56041893800 DQ 0bff05a1cac083127r ; -1.022
CONST	ENDS
;	COMDAT __real@8@3ffffd2f1a9fbe76c800
CONST	SEGMENT
__real@8@3ffffd2f1a9fbe76c800 DQ 03fffa5e353f7ced9r ; 1.978
CONST	ENDS
;	COMDAT __real@8@3ffab4395810624dd000
CONST	SEGMENT
__real@8@3ffab4395810624dd000 DQ 03fa6872b020c49bar ; 0.044
CONST	ENDS
;	COMDAT __real@8@3ffaf9db22d0e5604000
CONST	SEGMENT
__real@8@3ffaf9db22d0e5604000 DQ 03faf3b645a1cac08r ; 0.061
CONST	ENDS
;	COMDAT __real@8@bffce5604189374bc800
CONST	SEGMENT
__real@8@bffce5604189374bc800 DQ 0bfccac083126e979r ; -0.224
CONST	ENDS
;	COMDAT __real@8@3fff94dd2f1a9fbe7800
CONST	SEGMENT
__real@8@3fff94dd2f1a9fbe7800 DQ 03ff29ba5e353f7cfr ; 1.163
CONST	ENDS
;	COMDAT __real@8@3fff8000000000000000
CONST	SEGMENT
__real@8@3fff8000000000000000 DQ 03ff0000000000000r ; 1
CONST	ENDS
_TEXT	SEGMENT
_xyz$ = 8
_rgb$ = 12
_r$ = -16
_g$ = -24
_b$ = -8
_XYZtoRGB24 PROC NEAR

; 715  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 48					; 00000030H

; 716  : 	double	r, g, b;
; 717  : 					/* assume CCIR-709 primaries */
; 718  : 	r =  2.690*xyz[0] + -1.276*xyz[1] + -0.414*xyz[2];

	mov	eax, DWORD PTR _xyz$[ebp]
	fld	DWORD PTR [eax]
	fmul	QWORD PTR __real@8@4000ac28f5c28f5c2800
	mov	ecx, DWORD PTR _xyz$[ebp]
	fld	DWORD PTR [ecx+4]
	fmul	QWORD PTR __real@8@bfffa353f7ced9168800
	faddp	ST(1), ST(0)
	mov	edx, DWORD PTR _xyz$[ebp]
	fld	DWORD PTR [edx+8]
	fmul	QWORD PTR __real@8@bffdd3f7ced916872800
	faddp	ST(1), ST(0)
	fstp	QWORD PTR _r$[ebp]

; 719  : 	g = -1.022*xyz[0] +  1.978*xyz[1] +  0.044*xyz[2];

	mov	eax, DWORD PTR _xyz$[ebp]
	fld	DWORD PTR [eax]
	fmul	QWORD PTR __real@8@bfff82d0e56041893800
	mov	ecx, DWORD PTR _xyz$[ebp]
	fld	DWORD PTR [ecx+4]
	fmul	QWORD PTR __real@8@3ffffd2f1a9fbe76c800
	faddp	ST(1), ST(0)
	mov	edx, DWORD PTR _xyz$[ebp]
	fld	DWORD PTR [edx+8]
	fmul	QWORD PTR __real@8@3ffab4395810624dd000
	faddp	ST(1), ST(0)
	fstp	QWORD PTR _g$[ebp]

; 720  : 	b =  0.061*xyz[0] + -0.224*xyz[1] +  1.163*xyz[2];

	mov	eax, DWORD PTR _xyz$[ebp]
	fld	DWORD PTR [eax]
	fmul	QWORD PTR __real@8@3ffaf9db22d0e5604000
	mov	ecx, DWORD PTR _xyz$[ebp]
	fld	DWORD PTR [ecx+4]
	fmul	QWORD PTR __real@8@bffce5604189374bc800
	faddp	ST(1), ST(0)
	mov	edx, DWORD PTR _xyz$[ebp]
	fld	DWORD PTR [edx+8]
	fmul	QWORD PTR __real@8@3fff94dd2f1a9fbe7800
	faddp	ST(1), ST(0)
	fstp	QWORD PTR _b$[ebp]

; 721  : 					/* assume 2.0 gamma for speed */
; 722  : 	/* could use integer sqrt approx., but this is probably faster */
; 723  : 	rgb[0] = (r <= 0.) ? 0 : (r >= 1.) ? 255 : (int)(256.*sqrt(r));

	fld	QWORD PTR _r$[ebp]
	fcomp	QWORD PTR __real@8@00000000000000000000
	fnstsw	ax
	test	ah, 65					; 00000041H
	je	SHORT $L67336
	mov	DWORD PTR -28+[ebp], 0
	jmp	SHORT $L67337
$L67336:
	fld	QWORD PTR _r$[ebp]
	fcomp	QWORD PTR __real@8@3fff8000000000000000
	fnstsw	ax
	test	ah, 1
	jne	SHORT $L67334
	mov	DWORD PTR -32+[ebp], 255		; 000000ffH
	jmp	SHORT $L67335
$L67334:
	mov	eax, DWORD PTR _r$[ebp+4]
	push	eax
	mov	ecx, DWORD PTR _r$[ebp]
	push	ecx
	call	_sqrt
	add	esp, 8
	fmul	QWORD PTR __real@8@40078000000000000000
	call	__ftol
	mov	DWORD PTR -32+[ebp], eax
$L67335:
	mov	edx, DWORD PTR -32+[ebp]
	mov	DWORD PTR -28+[ebp], edx
$L67337:
	mov	eax, DWORD PTR _rgb$[ebp]
	mov	cl, BYTE PTR -28+[ebp]
	mov	BYTE PTR [eax], cl

; 724  : 	rgb[1] = (g <= 0.) ? 0 : (g >= 1.) ? 255 : (int)(256.*sqrt(g));

	fld	QWORD PTR _g$[ebp]
	fcomp	QWORD PTR __real@8@00000000000000000000
	fnstsw	ax
	test	ah, 65					; 00000041H
	je	SHORT $L67340
	mov	DWORD PTR -36+[ebp], 0
	jmp	SHORT $L67341
$L67340:
	fld	QWORD PTR _g$[ebp]
	fcomp	QWORD PTR __real@8@3fff8000000000000000
	fnstsw	ax
	test	ah, 1
	jne	SHORT $L67338
	mov	DWORD PTR -40+[ebp], 255		; 000000ffH
	jmp	SHORT $L67339
$L67338:
	mov	edx, DWORD PTR _g$[ebp+4]
	push	edx
	mov	eax, DWORD PTR _g$[ebp]
	push	eax
	call	_sqrt
	add	esp, 8
	fmul	QWORD PTR __real@8@40078000000000000000
	call	__ftol
	mov	DWORD PTR -40+[ebp], eax
$L67339:
	mov	ecx, DWORD PTR -40+[ebp]
	mov	DWORD PTR -36+[ebp], ecx
$L67341:
	mov	edx, DWORD PTR _rgb$[ebp]
	mov	al, BYTE PTR -36+[ebp]
	mov	BYTE PTR [edx+1], al

; 725  : 	rgb[2] = (b <= 0.) ? 0 : (b >= 1.) ? 255 : (int)(256.*sqrt(b));

	fld	QWORD PTR _b$[ebp]
	fcomp	QWORD PTR __real@8@00000000000000000000
	fnstsw	ax
	test	ah, 65					; 00000041H
	je	SHORT $L67344
	mov	DWORD PTR -44+[ebp], 0
	jmp	SHORT $L67345
$L67344:
	fld	QWORD PTR _b$[ebp]
	fcomp	QWORD PTR __real@8@3fff8000000000000000
	fnstsw	ax
	test	ah, 1
	jne	SHORT $L67342
	mov	DWORD PTR -48+[ebp], 255		; 000000ffH
	jmp	SHORT $L67343
$L67342:
	mov	ecx, DWORD PTR _b$[ebp+4]
	push	ecx
	mov	edx, DWORD PTR _b$[ebp]
	push	edx
	call	_sqrt
	add	esp, 8
	fmul	QWORD PTR __real@8@40078000000000000000
	call	__ftol
	mov	DWORD PTR -48+[ebp], eax
$L67343:
	mov	eax, DWORD PTR -48+[ebp]
	mov	DWORD PTR -44+[ebp], eax
$L67345:
	mov	ecx, DWORD PTR _rgb$[ebp]
	mov	dl, BYTE PTR -44+[ebp]
	mov	BYTE PTR [ecx+2], dl

; 726  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_XYZtoRGB24 ENDP
_TEXT	ENDS
PUBLIC	_LogL10toY
PUBLIC	__real@8@3ff8b17217f7d1cf7800
PUBLIC	__real@8@4002851591f9dd5b9800
;	COMDAT __real@8@3ff8b17217f7d1cf7800
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_luv.c
CONST	SEGMENT
__real@8@3ff8b17217f7d1cf7800 DQ 03f862e42fefa39efr ; 0.0108304
CONST	ENDS
;	COMDAT __real@8@4002851591f9dd5b9800
CONST	SEGMENT
__real@8@4002851591f9dd5b9800 DQ 04020a2b23f3bab73r ; 8.31777
CONST	ENDS
_TEXT	SEGMENT
_p10$ = 8
_LogL10toY PROC NEAR

; 733  : {

	push	ebp
	mov	ebp, esp

; 734  : 	if (p10 == 0)

	cmp	DWORD PTR _p10$[ebp], 0
	jne	SHORT $L66614

; 735  : 		return (0.);

	fld	QWORD PTR __real@8@00000000000000000000
	jmp	SHORT $L66613
$L66614:

; 736  : 	return (exp(M_LN2/64.*(p10+.5) - M_LN2*12.));

	fild	DWORD PTR _p10$[ebp]
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	fmul	QWORD PTR __real@8@3ff8b17217f7d1cf7800
	fsub	QWORD PTR __real@8@4002851591f9dd5b9800
	sub	esp, 8
	fstp	QWORD PTR [esp]
	call	_exp
	add	esp, 8
$L66613:

; 737  : }

	pop	ebp
	ret	0
_LogL10toY ENDP
_TEXT	ENDS
PUBLIC	_LogL10fromY
PUBLIC	__real@8@4002fbdf3b645a1cb000
PUBLIC	__real@8@3ff2fea02e892a60a800
PUBLIC	__real@8@4002c000000000000000
;	COMDAT __real@8@4002fbdf3b645a1cb000
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_luv.c
CONST	SEGMENT
__real@8@4002fbdf3b645a1cb000 DQ 0402f7be76c8b4396r ; 15.742
CONST	ENDS
;	COMDAT __real@8@3ff2fea02e892a60a800
CONST	SEGMENT
__real@8@3ff2fea02e892a60a800 DQ 03f2fd405d1254c15r ; 0.00024283
CONST	ENDS
;	COMDAT __real@8@4002c000000000000000
CONST	SEGMENT
__real@8@4002c000000000000000 DQ 04028000000000000r ; 12
CONST	ENDS
_TEXT	SEGMENT
_Y$ = 8
_em$ = 16
_LogL10fromY PROC NEAR

; 744  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 745  : 	if (Y >= 15.742)

	fld	QWORD PTR _Y$[ebp]
	fcomp	QWORD PTR __real@8@4002fbdf3b645a1cb000
	fnstsw	ax
	test	ah, 1
	jne	SHORT $L66620

; 746  : 		return (0x3ff);

	mov	eax, 1023				; 000003ffH
	jmp	$L66623
$L66620:

; 747  : 	else if (Y <= .00024283)

	fld	QWORD PTR _Y$[ebp]
	fcomp	QWORD PTR __real@8@3ff2fea02e892a60a800
	fnstsw	ax
	test	ah, 65					; 00000041H
	je	SHORT $L66622

; 748  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L66623
$L66622:

; 749  : 	else
; 750  : 		return itrunc(64.*(log2(Y) + 12.), em);

	cmp	DWORD PTR _em$[ebp], 0
	jne	SHORT $L67372
	mov	eax, DWORD PTR _Y$[ebp+4]
	push	eax
	mov	ecx, DWORD PTR _Y$[ebp]
	push	ecx
	call	_log
	add	esp, 8
	fmul	QWORD PTR __real@8@3fffb8aa3b295c17f000
	fadd	QWORD PTR __real@8@4002c000000000000000
	fmul	QWORD PTR __real@8@40058000000000000000
	call	__ftol
	mov	DWORD PTR -4+[ebp], eax
	jmp	SHORT $L67373
$L67372:
	mov	edx, DWORD PTR _Y$[ebp+4]
	push	edx
	mov	eax, DWORD PTR _Y$[ebp]
	push	eax
	call	_log
	add	esp, 8
	fmul	QWORD PTR __real@8@3fffb8aa3b295c17f000
	fadd	QWORD PTR __real@8@4002c000000000000000
	fmul	QWORD PTR __real@8@40058000000000000000
	fstp	QWORD PTR -12+[ebp]
	call	_rand
	mov	DWORD PTR -16+[ebp], eax
	fild	DWORD PTR -16+[ebp]
	fmul	QWORD PTR __real@8@3ff08001000200040000
	fadd	QWORD PTR -12+[ebp]
	fsub	QWORD PTR __real@8@3ffe8000000000000000
	call	__ftol
	mov	DWORD PTR -4+[ebp], eax
$L67373:
	mov	eax, DWORD PTR -4+[ebp]
$L66623:

; 751  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogL10fromY ENDP
_TEXT	ENDS
PUBLIC	_uv_encode
PUBLIC	__real@8@3ff98ac5c13fd0d06800
PUBLIC	__real@8@40078edb6db6db6db800
;	COMDAT __real@8@3ff98ac5c13fd0d06800
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_luv.c
CONST	SEGMENT
__real@8@3ff98ac5c13fd0d06800 DQ 03f9158b827fa1a0dr ; 0.01694
CONST	ENDS
;	COMDAT __real@8@40078edb6db6db6db800
CONST	SEGMENT
__real@8@40078edb6db6db6db800 DQ 04071db6db6db6db7r ; 285.714
CONST	ENDS
_TEXT	SEGMENT
_u$ = 8
_v$ = 16
_em$ = 24
_vi$ = -8
_ui$ = -4
_uv_encode PROC NEAR

; 815  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 40					; 00000028H

; 816  : 	register int	vi, ui;
; 817  : 
; 818  : 	if (v < UV_VSTART)

	fld	QWORD PTR _v$[ebp]
	fcomp	QWORD PTR __real@8@3ff98ac5c13fd0d06800
	fnstsw	ax
	test	ah, 1
	je	SHORT $L66691

; 819  : 		return oog_encode(u, v);

	mov	eax, DWORD PTR _v$[ebp+4]
	push	eax
	mov	ecx, DWORD PTR _v$[ebp]
	push	ecx
	mov	edx, DWORD PTR _u$[ebp+4]
	push	edx
	mov	eax, DWORD PTR _u$[ebp]
	push	eax
	call	_oog_encode
	add	esp, 16					; 00000010H
	jmp	$L66687
$L66691:

; 820  : 	vi = itrunc((v - UV_VSTART)*(1./UV_SQSIZ), em);

	cmp	DWORD PTR _em$[ebp], 0
	jne	SHORT $L67381
	fld	QWORD PTR _v$[ebp]
	fsub	QWORD PTR __real@8@3ff98ac5c13fd0d06800
	fmul	QWORD PTR __real@8@40078edb6db6db6db800
	call	__ftol
	mov	DWORD PTR -12+[ebp], eax
	jmp	SHORT $L67382
$L67381:
	fld	QWORD PTR _v$[ebp]
	fsub	QWORD PTR __real@8@3ff98ac5c13fd0d06800
	fmul	QWORD PTR __real@8@40078edb6db6db6db800
	fstp	QWORD PTR -20+[ebp]
	call	_rand
	mov	DWORD PTR -24+[ebp], eax
	fild	DWORD PTR -24+[ebp]
	fmul	QWORD PTR __real@8@3ff08001000200040000
	fadd	QWORD PTR -20+[ebp]
	fsub	QWORD PTR __real@8@3ffe8000000000000000
	call	__ftol
	mov	DWORD PTR -12+[ebp], eax
$L67382:
	mov	ecx, DWORD PTR -12+[ebp]
	mov	DWORD PTR _vi$[ebp], ecx

; 821  : 	if (vi >= UV_NVS)

	cmp	DWORD PTR _vi$[ebp], 163		; 000000a3H
	jl	SHORT $L66698

; 822  : 		return oog_encode(u, v);

	mov	edx, DWORD PTR _v$[ebp+4]
	push	edx
	mov	eax, DWORD PTR _v$[ebp]
	push	eax
	mov	ecx, DWORD PTR _u$[ebp+4]
	push	ecx
	mov	edx, DWORD PTR _u$[ebp]
	push	edx
	call	_oog_encode
	add	esp, 16					; 00000010H
	jmp	$L66687
$L66698:

; 823  : 	if (u < uv_row[vi].ustart)

	mov	eax, DWORD PTR _vi$[ebp]
	fld	DWORD PTR _uv_row[eax*8]
	fcomp	QWORD PTR _u$[ebp]
	fnstsw	ax
	test	ah, 65					; 00000041H
	jne	SHORT $L66699

; 824  : 		return oog_encode(u, v);

	mov	ecx, DWORD PTR _v$[ebp+4]
	push	ecx
	mov	edx, DWORD PTR _v$[ebp]
	push	edx
	mov	eax, DWORD PTR _u$[ebp+4]
	push	eax
	mov	ecx, DWORD PTR _u$[ebp]
	push	ecx
	call	_oog_encode
	add	esp, 16					; 00000010H
	jmp	$L66687
$L66699:

; 825  : 	ui = itrunc((u - uv_row[vi].ustart)*(1./UV_SQSIZ), em);

	cmp	DWORD PTR _em$[ebp], 0
	jne	SHORT $L67383
	mov	edx, DWORD PTR _vi$[ebp]
	fld	DWORD PTR _uv_row[edx*8]
	fsubr	QWORD PTR _u$[ebp]
	fmul	QWORD PTR __real@8@40078edb6db6db6db800
	call	__ftol
	mov	DWORD PTR -28+[ebp], eax
	jmp	SHORT $L67384
$L67383:
	mov	eax, DWORD PTR _vi$[ebp]
	fld	DWORD PTR _uv_row[eax*8]
	fsubr	QWORD PTR _u$[ebp]
	fmul	QWORD PTR __real@8@40078edb6db6db6db800
	fstp	QWORD PTR -36+[ebp]
	call	_rand
	mov	DWORD PTR -40+[ebp], eax
	fild	DWORD PTR -40+[ebp]
	fmul	QWORD PTR __real@8@3ff08001000200040000
	fadd	QWORD PTR -36+[ebp]
	fsub	QWORD PTR __real@8@3ffe8000000000000000
	call	__ftol
	mov	DWORD PTR -28+[ebp], eax
$L67384:
	mov	ecx, DWORD PTR -28+[ebp]
	mov	DWORD PTR _ui$[ebp], ecx

; 826  : 	if (ui >= uv_row[vi].nus)

	mov	edx, DWORD PTR _vi$[ebp]
	movsx	eax, WORD PTR _uv_row[edx*8+4]
	cmp	DWORD PTR _ui$[ebp], eax
	jl	SHORT $L66704

; 827  : 		return oog_encode(u, v);

	mov	ecx, DWORD PTR _v$[ebp+4]
	push	ecx
	mov	edx, DWORD PTR _v$[ebp]
	push	edx
	mov	eax, DWORD PTR _u$[ebp+4]
	push	eax
	mov	ecx, DWORD PTR _u$[ebp]
	push	ecx
	call	_oog_encode
	add	esp, 16					; 00000010H
	jmp	SHORT $L66687
$L66704:

; 828  : 
; 829  : 	return (uv_row[vi].ncum + ui);

	mov	edx, DWORD PTR _vi$[ebp]
	movsx	eax, WORD PTR _uv_row[edx*8+6]
	add	eax, DWORD PTR _ui$[ebp]
$L66687:

; 830  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_uv_encode ENDP
_TEXT	ENDS
PUBLIC	__real@8@3ff6e5604189374bc800
PUBLIC	__real@8@3ffcd79435e8ab60d000
PUBLIC	__real@8@3ffdf286bca5c0ccf000
PUBLIC	__real@8@4002fea5dd53cee1b800
PUBLIC	__real@8@4004c800000000000000
PUBLIC	__real@8@3fffc000000000000000
EXTRN	_atan2:NEAR
EXTRN	_fabs:NEAR
_BSS	SEGMENT
_?oog_table@?1??oog_encode@@9@9 DD 064H DUP (?)
_BSS	ENDS
;	COMDAT __real@8@3ff6e5604189374bc800
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_luv.c
CONST	SEGMENT
__real@8@3ff6e5604189374bc800 DQ 03f6cac083126e979r ; 0.0035
CONST	ENDS
;	COMDAT __real@8@3ffcd79435e8ab60d000
CONST	SEGMENT
__real@8@3ffcd79435e8ab60d000 DQ 03fcaf286bd156c1ar ; 0.210526
CONST	ENDS
;	COMDAT __real@8@3ffdf286bca5c0ccf000
CONST	SEGMENT
__real@8@3ffdf286bca5c0ccf000 DQ 03fde50d794b8199er ; 0.473684
CONST	ENDS
;	COMDAT __real@8@4002fea5dd53cee1b800
CONST	SEGMENT
__real@8@4002fea5dd53cee1b800 DQ 0402fd4bbaa79dc37r ; 15.9155
CONST	ENDS
;	COMDAT __real@8@4004c800000000000000
CONST	SEGMENT
__real@8@4004c800000000000000 DQ 04049000000000000r ; 50
CONST	ENDS
;	COMDAT __real@8@3fffc000000000000000
CONST	SEGMENT
__real@8@3fffc000000000000000 DQ 03ff8000000000000r ; 1.5
CONST	ENDS
_TEXT	SEGMENT
_u$ = 8
_v$ = 16
_i$ = -4
_eps$66640 = -836
_ua$66641 = -848
_va$66642 = -12
_ang$66643 = -24
_epsa$66644 = -36
_ui$66645 = -16
_vi$66646 = -28
_ustep$66647 = -840
_i1$66668 = -852
_i2$66669 = -856
_oog_encode PROC NEAR

; 759  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 856				; 00000358H

; 760  : 	static int	oog_table[NANGLES];
; 761  : 	static int	initialized = 0;
; 762  : 	register int	i;
; 763  : 	
; 764  : 	if (!initialized) {		/* set up perimeter table */

	cmp	DWORD PTR _?initialized@?1??oog_encode@@9@9, 0
	jne	$L66639

; 765  : 		double	eps[NANGLES], ua, va, ang, epsa;
; 766  : 		int	ui, vi, ustep;
; 767  : 		for (i = NANGLES; i--; )

	mov	DWORD PTR _i$[ebp], 100			; 00000064H
$L66649:
	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _i$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
	test	eax, eax
	je	SHORT $L66650

; 768  : 			eps[i] = 2.;

	mov	edx, DWORD PTR _i$[ebp]
	mov	DWORD PTR _eps$66640[ebp+edx*8], 0
	mov	DWORD PTR _eps$66640[ebp+edx*8+4], 1073741824 ; 40000000H
	jmp	SHORT $L66649
$L66650:

; 769  : 		for (vi = UV_NVS; vi--; ) {

	mov	DWORD PTR _vi$66646[ebp], 163		; 000000a3H
$L66652:
	mov	eax, DWORD PTR _vi$66646[ebp]
	mov	ecx, DWORD PTR _vi$66646[ebp]
	sub	ecx, 1
	mov	DWORD PTR _vi$66646[ebp], ecx
	test	eax, eax
	je	$L66653

; 770  : 			va = UV_VSTART + (vi+.5)*UV_SQSIZ;

	fild	DWORD PTR _vi$66646[ebp]
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	fmul	QWORD PTR __real@8@3ff6e5604189374bc800
	fadd	QWORD PTR __real@8@3ff98ac5c13fd0d06800
	fstp	QWORD PTR _va$66642[ebp]

; 771  : 			ustep = uv_row[vi].nus-1;

	mov	edx, DWORD PTR _vi$66646[ebp]
	movsx	eax, WORD PTR _uv_row[edx*8+4]
	sub	eax, 1
	mov	DWORD PTR _ustep$66647[ebp], eax

; 772  : 			if (vi == UV_NVS-1 || vi == 0 || ustep <= 0)

	cmp	DWORD PTR _vi$66646[ebp], 162		; 000000a2H
	je	SHORT $L66657
	cmp	DWORD PTR _vi$66646[ebp], 0
	je	SHORT $L66657
	cmp	DWORD PTR _ustep$66647[ebp], 0
	jg	SHORT $L66656
$L66657:

; 773  : 				ustep = 1;

	mov	DWORD PTR _ustep$66647[ebp], 1
$L66656:

; 774  : 			for (ui = uv_row[vi].nus-1; ui >= 0; ui -= ustep) {

	mov	ecx, DWORD PTR _vi$66646[ebp]
	movsx	edx, WORD PTR _uv_row[ecx*8+4]
	sub	edx, 1
	mov	DWORD PTR _ui$66645[ebp], edx
	jmp	SHORT $L66658
$L66659:
	mov	eax, DWORD PTR _ui$66645[ebp]
	sub	eax, DWORD PTR _ustep$66647[ebp]
	mov	DWORD PTR _ui$66645[ebp], eax
$L66658:
	cmp	DWORD PTR _ui$66645[ebp], 0
	jl	$L66660

; 775  : 				ua = uv_row[vi].ustart + (ui+.5)*UV_SQSIZ;

	mov	ecx, DWORD PTR _vi$66646[ebp]
	fld	DWORD PTR _uv_row[ecx*8]
	fild	DWORD PTR _ui$66645[ebp]
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	fmul	QWORD PTR __real@8@3ff6e5604189374bc800
	faddp	ST(1), ST(0)
	fst	QWORD PTR _ua$66641[ebp]

; 776  : 				ang = uv2ang(ua, va);

	fsub	QWORD PTR __real@8@3ffcd79435e8ab60d000
	sub	esp, 8
	fstp	QWORD PTR [esp]
	fld	QWORD PTR _va$66642[ebp]
	fsub	QWORD PTR __real@8@3ffdf286bca5c0ccf000
	sub	esp, 8
	fstp	QWORD PTR [esp]
	call	_atan2
	add	esp, 16					; 00000010H
	fmul	QWORD PTR __real@8@4002fea5dd53cee1b800
	fadd	QWORD PTR __real@8@4004c800000000000000
	fst	QWORD PTR _ang$66643[ebp]

; 777  :                                 i = (int) ang;

	call	__ftol
	mov	DWORD PTR _i$[ebp], eax

; 778  : 				epsa = fabs(ang - (i+.5));

	fild	DWORD PTR _i$[ebp]
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	fsubr	QWORD PTR _ang$66643[ebp]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	call	_fabs
	add	esp, 8
	fstp	QWORD PTR _epsa$66644[ebp]

; 779  : 				if (epsa < eps[i]) {

	mov	edx, DWORD PTR _i$[ebp]
	fld	QWORD PTR _epsa$66644[ebp]
	fcomp	QWORD PTR _eps$66640[ebp+edx*8]
	fnstsw	ax
	test	ah, 1
	je	SHORT $L66663

; 780  : 					oog_table[i] = uv_row[vi].ncum + ui;

	mov	eax, DWORD PTR _vi$66646[ebp]
	movsx	ecx, WORD PTR _uv_row[eax*8+6]
	add	ecx, DWORD PTR _ui$66645[ebp]
	mov	edx, DWORD PTR _i$[ebp]
	mov	DWORD PTR _?oog_table@?1??oog_encode@@9@9[edx*4], ecx

; 781  : 					eps[i] = epsa;

	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _epsa$66644[ebp]
	mov	DWORD PTR _eps$66640[ebp+eax*8], ecx
	mov	edx, DWORD PTR _epsa$66644[ebp+4]
	mov	DWORD PTR _eps$66640[ebp+eax*8+4], edx
$L66663:

; 783  : 			}

	jmp	$L66659
$L66660:

; 784  : 		}

	jmp	$L66652
$L66653:

; 785  : 		for (i = NANGLES; i--; )	/* fill any holes */

	mov	DWORD PTR _i$[ebp], 100			; 00000064H
$L66665:
	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _i$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
	test	eax, eax
	je	$L66666

; 786  : 			if (eps[i] > 1.5) {

	mov	edx, DWORD PTR _i$[ebp]
	fld	QWORD PTR _eps$66640[ebp+edx*8]
	fcomp	QWORD PTR __real@8@3fffc000000000000000
	fnstsw	ax
	test	ah, 65					; 00000041H
	jne	$L66679

; 787  : 				int	i1, i2;
; 788  : 				for (i1 = 1; i1 < NANGLES/2; i1++)

	mov	DWORD PTR _i1$66668[ebp], 1
	jmp	SHORT $L66670
$L66671:
	mov	eax, DWORD PTR _i1$66668[ebp]
	add	eax, 1
	mov	DWORD PTR _i1$66668[ebp], eax
$L66670:
	cmp	DWORD PTR _i1$66668[ebp], 50		; 00000032H
	jge	SHORT $L66672

; 789  : 					if (eps[(i+i1)%NANGLES] < 1.5)

	mov	eax, DWORD PTR _i$[ebp]
	add	eax, DWORD PTR _i1$66668[ebp]
	cdq
	mov	ecx, 100				; 00000064H
	idiv	ecx
	fld	QWORD PTR _eps$66640[ebp+edx*8]
	fcomp	QWORD PTR __real@8@3fffc000000000000000
	fnstsw	ax
	test	ah, 1
	je	SHORT $L66673

; 790  : 						break;

	jmp	SHORT $L66672
$L66673:

; 791  : 				for (i2 = 1; i2 < NANGLES/2; i2++)

	jmp	SHORT $L66671
$L66672:
	mov	DWORD PTR _i2$66669[ebp], 1
	jmp	SHORT $L66674
$L66675:
	mov	edx, DWORD PTR _i2$66669[ebp]
	add	edx, 1
	mov	DWORD PTR _i2$66669[ebp], edx
$L66674:
	cmp	DWORD PTR _i2$66669[ebp], 50		; 00000032H
	jge	SHORT $L66676

; 792  : 					if (eps[(i+NANGLES-i2)%NANGLES] < 1.5)

	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 100				; 00000064H
	sub	eax, DWORD PTR _i2$66669[ebp]
	cdq
	mov	ecx, 100				; 00000064H
	idiv	ecx
	fld	QWORD PTR _eps$66640[ebp+edx*8]
	fcomp	QWORD PTR __real@8@3fffc000000000000000
	fnstsw	ax
	test	ah, 1
	je	SHORT $L66677

; 793  : 						break;

	jmp	SHORT $L66676
$L66677:

; 794  : 				if (i1 < i2)

	jmp	SHORT $L66675
$L66676:
	mov	edx, DWORD PTR _i1$66668[ebp]
	cmp	edx, DWORD PTR _i2$66669[ebp]
	jge	SHORT $L66678

; 795  : 					oog_table[i] =
; 796  : 						oog_table[(i+i1)%NANGLES];

	mov	eax, DWORD PTR _i$[ebp]
	add	eax, DWORD PTR _i1$66668[ebp]
	cdq
	mov	ecx, 100				; 00000064H
	idiv	ecx
	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _?oog_table@?1??oog_encode@@9@9[edx*4]
	mov	DWORD PTR _?oog_table@?1??oog_encode@@9@9[eax*4], ecx

; 797  : 				else

	jmp	SHORT $L66679
$L66678:

; 798  : 					oog_table[i] =
; 799  : 						oog_table[(i+NANGLES-i2)%NANGLES];

	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 100				; 00000064H
	sub	eax, DWORD PTR _i2$66669[ebp]
	cdq
	mov	ecx, 100				; 00000064H
	idiv	ecx
	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _?oog_table@?1??oog_encode@@9@9[edx*4]
	mov	DWORD PTR _?oog_table@?1??oog_encode@@9@9[eax*4], ecx
$L66679:

; 801  : 		initialized = 1;

	jmp	$L66665
$L66666:
	mov	DWORD PTR _?initialized@?1??oog_encode@@9@9, 1
$L66639:

; 803  : 	i = (int) uv2ang(u, v);		/* look up hue angle */

	fld	QWORD PTR _u$[ebp]
	fsub	QWORD PTR __real@8@3ffcd79435e8ab60d000
	sub	esp, 8
	fstp	QWORD PTR [esp]
	fld	QWORD PTR _v$[ebp]
	fsub	QWORD PTR __real@8@3ffdf286bca5c0ccf000
	sub	esp, 8
	fstp	QWORD PTR [esp]
	call	_atan2
	add	esp, 16					; 00000010H
	fmul	QWORD PTR __real@8@4002fea5dd53cee1b800
	fadd	QWORD PTR __real@8@4004c800000000000000
	call	__ftol
	mov	DWORD PTR _i$[ebp], eax

; 804  : 	return (oog_table[i]);

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _?oog_table@?1??oog_encode@@9@9[edx*4]

; 805  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_oog_encode ENDP
_TEXT	ENDS
PUBLIC	_uv_decode
_TEXT	SEGMENT
_up$ = 8
_vp$ = 12
_c$ = 16
_upper$ = -8
_lower$ = -16
_ui$ = -4
_vi$ = -12
_uv_decode PROC NEAR

; 837  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 838  : 	int	upper, lower;
; 839  : 	register int	ui, vi;
; 840  : 
; 841  : 	if (c < 0 || c >= UV_NDIVS)

	cmp	DWORD PTR _c$[ebp], 0
	jl	SHORT $L66717
	cmp	DWORD PTR _c$[ebp], 16289		; 00003fa1H
	jl	SHORT $L66716
$L66717:

; 842  : 		return (-1);

	or	eax, -1
	jmp	$L66711
$L66716:

; 843  : 	lower = 0;				/* binary search */

	mov	DWORD PTR _lower$[ebp], 0

; 844  : 	upper = UV_NVS;

	mov	DWORD PTR _upper$[ebp], 163		; 000000a3H
$L66719:

; 845  : 	while (upper - lower > 1) {

	mov	eax, DWORD PTR _upper$[ebp]
	sub	eax, DWORD PTR _lower$[ebp]
	cmp	eax, 1
	jle	SHORT $L66720

; 846  : 		vi = (lower + upper) >> 1;

	mov	ecx, DWORD PTR _lower$[ebp]
	add	ecx, DWORD PTR _upper$[ebp]
	sar	ecx, 1
	mov	DWORD PTR _vi$[ebp], ecx

; 847  : 		ui = c - uv_row[vi].ncum;

	mov	edx, DWORD PTR _vi$[ebp]
	movsx	eax, WORD PTR _uv_row[edx*8+6]
	mov	ecx, DWORD PTR _c$[ebp]
	sub	ecx, eax
	mov	DWORD PTR _ui$[ebp], ecx

; 848  : 		if (ui > 0)

	cmp	DWORD PTR _ui$[ebp], 0
	jle	SHORT $L66721

; 849  : 			lower = vi;

	mov	edx, DWORD PTR _vi$[ebp]
	mov	DWORD PTR _lower$[ebp], edx

; 850  : 		else if (ui < 0)

	jmp	SHORT $L66724
$L66721:
	cmp	DWORD PTR _ui$[ebp], 0
	jge	SHORT $L66723

; 851  : 			upper = vi;

	mov	eax, DWORD PTR _vi$[ebp]
	mov	DWORD PTR _upper$[ebp], eax

; 852  : 		else {

	jmp	SHORT $L66724
$L66723:

; 853  : 			lower = vi;

	mov	ecx, DWORD PTR _vi$[ebp]
	mov	DWORD PTR _lower$[ebp], ecx

; 854  : 			break;

	jmp	SHORT $L66720
$L66724:

; 856  : 	}

	jmp	SHORT $L66719
$L66720:

; 857  : 	vi = lower;

	mov	edx, DWORD PTR _lower$[ebp]
	mov	DWORD PTR _vi$[ebp], edx

; 858  : 	ui = c - uv_row[vi].ncum;

	mov	eax, DWORD PTR _vi$[ebp]
	movsx	ecx, WORD PTR _uv_row[eax*8+6]
	mov	edx, DWORD PTR _c$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _ui$[ebp], edx

; 859  : 	*up = uv_row[vi].ustart + (ui+.5)*UV_SQSIZ;

	mov	eax, DWORD PTR _vi$[ebp]
	fld	DWORD PTR _uv_row[eax*8]
	fild	DWORD PTR _ui$[ebp]
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	fmul	QWORD PTR __real@8@3ff6e5604189374bc800
	faddp	ST(1), ST(0)
	mov	ecx, DWORD PTR _up$[ebp]
	fstp	QWORD PTR [ecx]

; 860  : 	*vp = UV_VSTART + (vi+.5)*UV_SQSIZ;

	fild	DWORD PTR _vi$[ebp]
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	fmul	QWORD PTR __real@8@3ff6e5604189374bc800
	fadd	QWORD PTR __real@8@3ff98ac5c13fd0d06800
	mov	edx, DWORD PTR _vp$[ebp]
	fstp	QWORD PTR [edx]

; 861  : 	return (0);

	xor	eax, eax
$L66711:

; 862  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_uv_decode ENDP
_TEXT	ENDS
PUBLIC	_LogLuv24toXYZ
PUBLIC	__real@8@4001c000000000000000
PUBLIC	__real@8@40038000000000000000
PUBLIC	__real@8@40029000000000000000
PUBLIC	__real@8@40018000000000000000
;	COMDAT __real@8@4001c000000000000000
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_luv.c
CONST	SEGMENT
__real@8@4001c000000000000000 DQ 04018000000000000r ; 6
CONST	ENDS
;	COMDAT __real@8@40038000000000000000
CONST	SEGMENT
__real@8@40038000000000000000 DQ 04030000000000000r ; 16
CONST	ENDS
;	COMDAT __real@8@40029000000000000000
CONST	SEGMENT
__real@8@40029000000000000000 DQ 04022000000000000r ; 9
CONST	ENDS
;	COMDAT __real@8@40018000000000000000
CONST	SEGMENT
__real@8@40018000000000000000 DQ 04010000000000000r ; 4
CONST	ENDS
_TEXT	SEGMENT
_p$ = 8
_XYZ$ = 12
_Ce$ = -20
_L$ = -52
_u$ = -16
_v$ = -28
_s$ = -8
_x$ = -36
_y$ = -44
_LogLuv24toXYZ PROC NEAR

; 869  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 52					; 00000034H

; 870  : 	int	Ce;
; 871  : 	double	L, u, v, s, x, y;
; 872  : 					/* decode luminance */
; 873  : 	L = LogL10toY(p>>14 & 0x3ff);

	mov	eax, DWORD PTR _p$[ebp]
	shr	eax, 14					; 0000000eH
	and	eax, 1023				; 000003ffH
	push	eax
	call	_LogL10toY
	add	esp, 4
	fst	QWORD PTR _L$[ebp]

; 874  : 	if (L <= 0.) {

	fcomp	QWORD PTR __real@8@00000000000000000000
	fnstsw	ax
	test	ah, 65					; 00000041H
	je	SHORT $L66740

; 875  : 		XYZ[0] = XYZ[1] = XYZ[2] = 0.;

	mov	ecx, DWORD PTR _XYZ$[ebp]
	mov	DWORD PTR [ecx+8], 0
	mov	edx, DWORD PTR _XYZ$[ebp]
	mov	DWORD PTR [edx+4], 0
	mov	eax, DWORD PTR _XYZ$[ebp]
	mov	DWORD PTR [eax], 0

; 876  : 		return;

	jmp	$L66732
$L66740:

; 878  : 					/* decode color */
; 879  : 	Ce = p & 0x3fff;

	mov	ecx, DWORD PTR _p$[ebp]
	and	ecx, 16383				; 00003fffH
	mov	DWORD PTR _Ce$[ebp], ecx

; 880  : 	if (uv_decode(&u, &v, Ce) < 0) {

	mov	edx, DWORD PTR _Ce$[ebp]
	push	edx
	lea	eax, DWORD PTR _v$[ebp]
	push	eax
	lea	ecx, DWORD PTR _u$[ebp]
	push	ecx
	call	_uv_decode
	add	esp, 12					; 0000000cH
	test	eax, eax
	jge	SHORT $L66741

; 881  : 		u = U_NEU; v = V_NEU;

	mov	DWORD PTR _u$[ebp], -1122669542		; bd156c1aH
	mov	DWORD PTR _u$[ebp+4], 1070264966	; 3fcaf286H
	mov	DWORD PTR _v$[ebp], -1799874146		; 94b8199eH
	mov	DWORD PTR _v$[ebp+4], 1071534295	; 3fde50d7H
$L66741:

; 883  : 	s = 1./(6.*u - 16.*v + 12.);

	fld	QWORD PTR __real@8@4001c000000000000000
	fmul	QWORD PTR _u$[ebp]
	fld	QWORD PTR __real@8@40038000000000000000
	fmul	QWORD PTR _v$[ebp]
	fsubp	ST(1), ST(0)
	fadd	QWORD PTR __real@8@4002c000000000000000
	fdivr	QWORD PTR __real@8@3fff8000000000000000
	fstp	QWORD PTR _s$[ebp]

; 884  : 	x = 9.*u * s;

	fld	QWORD PTR __real@8@40029000000000000000
	fmul	QWORD PTR _u$[ebp]
	fmul	QWORD PTR _s$[ebp]
	fstp	QWORD PTR _x$[ebp]

; 885  : 	y = 4.*v * s;

	fld	QWORD PTR __real@8@40018000000000000000
	fmul	QWORD PTR _v$[ebp]
	fmul	QWORD PTR _s$[ebp]
	fstp	QWORD PTR _y$[ebp]

; 886  : 					/* convert to XYZ */
; 887  : 	XYZ[0] = (float)(x/y * L);

	fld	QWORD PTR _x$[ebp]
	fdiv	QWORD PTR _y$[ebp]
	fmul	QWORD PTR _L$[ebp]
	mov	edx, DWORD PTR _XYZ$[ebp]
	fstp	DWORD PTR [edx]

; 888  : 	XYZ[1] = (float)L;

	fld	QWORD PTR _L$[ebp]
	mov	eax, DWORD PTR _XYZ$[ebp]
	fstp	DWORD PTR [eax+4]

; 889  : 	XYZ[2] = (float)((1.-x-y)/y * L);

	fld	QWORD PTR __real@8@3fff8000000000000000
	fsub	QWORD PTR _x$[ebp]
	fsub	QWORD PTR _y$[ebp]
	fdiv	QWORD PTR _y$[ebp]
	fmul	QWORD PTR _L$[ebp]
	mov	ecx, DWORD PTR _XYZ$[ebp]
	fstp	DWORD PTR [ecx+8]
$L66732:

; 890  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogLuv24toXYZ ENDP
_TEXT	ENDS
PUBLIC	_LogLuv24fromXYZ
PUBLIC	__real@8@4002f000000000000000
PUBLIC	__real@8@4000c000000000000000
;	COMDAT __real@8@4002f000000000000000
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_luv.c
CONST	SEGMENT
__real@8@4002f000000000000000 DQ 0402e000000000000r ; 15
CONST	ENDS
;	COMDAT __real@8@4000c000000000000000
CONST	SEGMENT
__real@8@4000c000000000000000 DQ 04008000000000000r ; 3
CONST	ENDS
_TEXT	SEGMENT
_XYZ$ = 8
_em$ = 12
_Le$ = -32
_Ce$ = -20
_u$ = -16
_v$ = -28
_s$ = -8
_LogLuv24fromXYZ PROC NEAR

; 897  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 32					; 00000020H

; 898  : 	int	Le, Ce;
; 899  : 	double	u, v, s;
; 900  : 					/* encode luminance */
; 901  : 	Le = LogL10fromY(XYZ[1], em);

	mov	eax, DWORD PTR _em$[ebp]
	push	eax
	mov	ecx, DWORD PTR _XYZ$[ebp]
	fld	DWORD PTR [ecx+4]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	call	_LogL10fromY
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _Le$[ebp], eax

; 902  : 					/* encode color */
; 903  : 	s = XYZ[0] + 15.*XYZ[1] + 3.*XYZ[2];

	mov	edx, DWORD PTR _XYZ$[ebp]
	fld	DWORD PTR [edx]
	mov	eax, DWORD PTR _XYZ$[ebp]
	fld	DWORD PTR [eax+4]
	fmul	QWORD PTR __real@8@4002f000000000000000
	faddp	ST(1), ST(0)
	mov	ecx, DWORD PTR _XYZ$[ebp]
	fld	DWORD PTR [ecx+8]
	fmul	QWORD PTR __real@8@4000c000000000000000
	faddp	ST(1), ST(0)
	fstp	QWORD PTR _s$[ebp]

; 904  : 	if (!Le || s <= 0.) {

	cmp	DWORD PTR _Le$[ebp], 0
	je	SHORT $L66756
	fld	QWORD PTR _s$[ebp]
	fcomp	QWORD PTR __real@8@00000000000000000000
	fnstsw	ax
	test	ah, 65					; 00000041H
	je	SHORT $L66755
$L66756:

; 905  : 		u = U_NEU;

	mov	DWORD PTR _u$[ebp], -1122669542		; bd156c1aH
	mov	DWORD PTR _u$[ebp+4], 1070264966	; 3fcaf286H

; 906  : 		v = V_NEU;

	mov	DWORD PTR _v$[ebp], -1799874146		; 94b8199eH
	mov	DWORD PTR _v$[ebp+4], 1071534295	; 3fde50d7H

; 907  : 	} else {

	jmp	SHORT $L66757
$L66755:

; 908  : 		u = 4.*XYZ[0] / s;

	mov	edx, DWORD PTR _XYZ$[ebp]
	fld	DWORD PTR [edx]
	fmul	QWORD PTR __real@8@40018000000000000000
	fdiv	QWORD PTR _s$[ebp]
	fstp	QWORD PTR _u$[ebp]

; 909  : 		v = 9.*XYZ[1] / s;

	mov	eax, DWORD PTR _XYZ$[ebp]
	fld	DWORD PTR [eax+4]
	fmul	QWORD PTR __real@8@40029000000000000000
	fdiv	QWORD PTR _s$[ebp]
	fstp	QWORD PTR _v$[ebp]
$L66757:

; 911  : 	Ce = uv_encode(u, v, em);

	mov	ecx, DWORD PTR _em$[ebp]
	push	ecx
	mov	edx, DWORD PTR _v$[ebp+4]
	push	edx
	mov	eax, DWORD PTR _v$[ebp]
	push	eax
	mov	ecx, DWORD PTR _u$[ebp+4]
	push	ecx
	mov	edx, DWORD PTR _u$[ebp]
	push	edx
	call	_uv_encode
	add	esp, 20					; 00000014H
	mov	DWORD PTR _Ce$[ebp], eax

; 912  : 	if (Ce < 0)			/* never happens */

	cmp	DWORD PTR _Ce$[ebp], 0
	jge	SHORT $L66758

; 913  : 		Ce = uv_encode(U_NEU, V_NEU, SGILOGENCODE_NODITHER);

	push	0
	push	1071534295				; 3fde50d7H
	push	-1799874146				; 94b8199eH
	push	1070264966				; 3fcaf286H
	push	-1122669542				; bd156c1aH
	call	_uv_encode
	add	esp, 20					; 00000014H
	mov	DWORD PTR _Ce$[ebp], eax
$L66758:

; 914  : 					/* combine encodings */
; 915  : 	return (Le << 14 | Ce);

	mov	eax, DWORD PTR _Le$[ebp]
	shl	eax, 14					; 0000000eH
	or	eax, DWORD PTR _Ce$[ebp]

; 916  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogLuv24fromXYZ ENDP
_TEXT	ENDS
PUBLIC	_LogLuv32toXYZ
PUBLIC	__real@8@3ff69fd809fd809fd800
;	COMDAT __real@8@3ff69fd809fd809fd800
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_luv.c
CONST	SEGMENT
__real@8@3ff69fd809fd809fd800 DQ 03f63fb013fb013fbr ; 0.00243902
CONST	ENDS
_TEXT	SEGMENT
_p$ = 8
_XYZ$ = 12
_L$ = -48
_u$ = -16
_v$ = -24
_s$ = -8
_x$ = -32
_y$ = -40
_LogLuv32toXYZ PROC NEAR

; 1010 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 64					; 00000040H

; 1011 : 	double	L, u, v, s, x, y;
; 1012 : 					/* decode luminance */
; 1013 : 	L = LogL16toY((int)p >> 16);

	mov	eax, DWORD PTR _p$[ebp]
	sar	eax, 16					; 00000010H
	push	eax
	call	_LogL16toY
	add	esp, 4
	fst	QWORD PTR _L$[ebp]

; 1014 : 	if (L <= 0.) {

	fcomp	QWORD PTR __real@8@00000000000000000000
	fnstsw	ax
	test	ah, 65					; 00000041H
	je	SHORT $L66865

; 1015 : 		XYZ[0] = XYZ[1] = XYZ[2] = 0.;

	mov	ecx, DWORD PTR _XYZ$[ebp]
	mov	DWORD PTR [ecx+8], 0
	mov	edx, DWORD PTR _XYZ$[ebp]
	mov	DWORD PTR [edx+4], 0
	mov	eax, DWORD PTR _XYZ$[ebp]
	mov	DWORD PTR [eax], 0

; 1016 : 		return;

	jmp	$L66857
$L66865:

; 1018 : 					/* decode color */
; 1019 : 	u = 1./UVSCALE * ((p>>8 & 0xff) + .5);

	mov	ecx, DWORD PTR _p$[ebp]
	shr	ecx, 8
	and	ecx, 255				; 000000ffH
	mov	DWORD PTR -56+[ebp], ecx
	mov	DWORD PTR -56+[ebp+4], 0
	fild	QWORD PTR -56+[ebp]
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	fmul	QWORD PTR __real@8@3ff69fd809fd809fd800
	fstp	QWORD PTR _u$[ebp]

; 1020 : 	v = 1./UVSCALE * ((p & 0xff) + .5);

	mov	edx, DWORD PTR _p$[ebp]
	and	edx, 255				; 000000ffH
	mov	DWORD PTR -64+[ebp], edx
	mov	DWORD PTR -64+[ebp+4], 0
	fild	QWORD PTR -64+[ebp]
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	fmul	QWORD PTR __real@8@3ff69fd809fd809fd800
	fstp	QWORD PTR _v$[ebp]

; 1021 : 	s = 1./(6.*u - 16.*v + 12.);

	fld	QWORD PTR __real@8@4001c000000000000000
	fmul	QWORD PTR _u$[ebp]
	fld	QWORD PTR __real@8@40038000000000000000
	fmul	QWORD PTR _v$[ebp]
	fsubp	ST(1), ST(0)
	fadd	QWORD PTR __real@8@4002c000000000000000
	fdivr	QWORD PTR __real@8@3fff8000000000000000
	fstp	QWORD PTR _s$[ebp]

; 1022 : 	x = 9.*u * s;

	fld	QWORD PTR __real@8@40029000000000000000
	fmul	QWORD PTR _u$[ebp]
	fmul	QWORD PTR _s$[ebp]
	fstp	QWORD PTR _x$[ebp]

; 1023 : 	y = 4.*v * s;

	fld	QWORD PTR __real@8@40018000000000000000
	fmul	QWORD PTR _v$[ebp]
	fmul	QWORD PTR _s$[ebp]
	fstp	QWORD PTR _y$[ebp]

; 1024 : 					/* convert to XYZ */
; 1025 : 	XYZ[0] = (float)(x/y * L);

	fld	QWORD PTR _x$[ebp]
	fdiv	QWORD PTR _y$[ebp]
	fmul	QWORD PTR _L$[ebp]
	mov	eax, DWORD PTR _XYZ$[ebp]
	fstp	DWORD PTR [eax]

; 1026 : 	XYZ[1] = (float)L;

	fld	QWORD PTR _L$[ebp]
	mov	ecx, DWORD PTR _XYZ$[ebp]
	fstp	DWORD PTR [ecx+4]

; 1027 : 	XYZ[2] = (float)((1.-x-y)/y * L);

	fld	QWORD PTR __real@8@3fff8000000000000000
	fsub	QWORD PTR _x$[ebp]
	fsub	QWORD PTR _y$[ebp]
	fdiv	QWORD PTR _y$[ebp]
	fmul	QWORD PTR _L$[ebp]
	mov	edx, DWORD PTR _XYZ$[ebp]
	fstp	DWORD PTR [edx+8]
$L66857:

; 1028 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogLuv32toXYZ ENDP
_TEXT	ENDS
PUBLIC	_LogLuv32fromXYZ
PUBLIC	__real@8@4007cd00000000000000
;	COMDAT __real@8@4007cd00000000000000
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_luv.c
CONST	SEGMENT
__real@8@4007cd00000000000000 DQ 04079a00000000000r ; 410
CONST	ENDS
_TEXT	SEGMENT
_XYZ$ = 8
_em$ = 12
_Le$ = -36
_ue$ = -4
_ve$ = -16
_u$ = -24
_v$ = -32
_s$ = -12
_LogLuv32fromXYZ PROC NEAR

; 1035 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 68					; 00000044H

; 1036 : 	unsigned int	Le, ue, ve;
; 1037 : 	double	u, v, s;
; 1038 : 					/* encode luminance */
; 1039 : 	Le = (unsigned int)LogL16fromY(XYZ[1], em);

	mov	eax, DWORD PTR _em$[ebp]
	push	eax
	mov	ecx, DWORD PTR _XYZ$[ebp]
	fld	DWORD PTR [ecx+4]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	call	_LogL16fromY
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _Le$[ebp], eax

; 1040 : 					/* encode color */
; 1041 : 	s = XYZ[0] + 15.*XYZ[1] + 3.*XYZ[2];

	mov	edx, DWORD PTR _XYZ$[ebp]
	fld	DWORD PTR [edx]
	mov	eax, DWORD PTR _XYZ$[ebp]
	fld	DWORD PTR [eax+4]
	fmul	QWORD PTR __real@8@4002f000000000000000
	faddp	ST(1), ST(0)
	mov	ecx, DWORD PTR _XYZ$[ebp]
	fld	DWORD PTR [ecx+8]
	fmul	QWORD PTR __real@8@4000c000000000000000
	faddp	ST(1), ST(0)
	fstp	QWORD PTR _s$[ebp]

; 1042 : 	if (!Le || s <= 0.) {

	cmp	DWORD PTR _Le$[ebp], 0
	je	SHORT $L66882
	fld	QWORD PTR _s$[ebp]
	fcomp	QWORD PTR __real@8@00000000000000000000
	fnstsw	ax
	test	ah, 65					; 00000041H
	je	SHORT $L66881
$L66882:

; 1043 : 		u = U_NEU;

	mov	DWORD PTR _u$[ebp], -1122669542		; bd156c1aH
	mov	DWORD PTR _u$[ebp+4], 1070264966	; 3fcaf286H

; 1044 : 		v = V_NEU;

	mov	DWORD PTR _v$[ebp], -1799874146		; 94b8199eH
	mov	DWORD PTR _v$[ebp+4], 1071534295	; 3fde50d7H

; 1045 : 	} else {

	jmp	SHORT $L66883
$L66881:

; 1046 : 		u = 4.*XYZ[0] / s;

	mov	edx, DWORD PTR _XYZ$[ebp]
	fld	DWORD PTR [edx]
	fmul	QWORD PTR __real@8@40018000000000000000
	fdiv	QWORD PTR _s$[ebp]
	fstp	QWORD PTR _u$[ebp]

; 1047 : 		v = 9.*XYZ[1] / s;

	mov	eax, DWORD PTR _XYZ$[ebp]
	fld	DWORD PTR [eax+4]
	fmul	QWORD PTR __real@8@40029000000000000000
	fdiv	QWORD PTR _s$[ebp]
	fstp	QWORD PTR _v$[ebp]
$L66883:

; 1049 : 	if (u <= 0.) ue = 0;

	fld	QWORD PTR _u$[ebp]
	fcomp	QWORD PTR __real@8@00000000000000000000
	fnstsw	ax
	test	ah, 65					; 00000041H
	je	SHORT $L66884
	mov	DWORD PTR _ue$[ebp], 0

; 1050 : 	else ue = itrunc(UVSCALE*u, em);

	jmp	SHORT $L66885
$L66884:
	cmp	DWORD PTR _em$[ebp], 0
	jne	SHORT $L67421
	fld	QWORD PTR __real@8@4007cd00000000000000
	fmul	QWORD PTR _u$[ebp]
	call	__ftol
	mov	DWORD PTR -40+[ebp], eax
	jmp	SHORT $L67422
$L67421:
	fld	QWORD PTR __real@8@4007cd00000000000000
	fmul	QWORD PTR _u$[ebp]
	fstp	QWORD PTR -48+[ebp]
	call	_rand
	mov	DWORD PTR -52+[ebp], eax
	fild	DWORD PTR -52+[ebp]
	fmul	QWORD PTR __real@8@3ff08001000200040000
	fadd	QWORD PTR -48+[ebp]
	fsub	QWORD PTR __real@8@3ffe8000000000000000
	call	__ftol
	mov	DWORD PTR -40+[ebp], eax
$L67422:
	mov	ecx, DWORD PTR -40+[ebp]
	mov	DWORD PTR _ue$[ebp], ecx
$L66885:

; 1051 : 	if (ue > 255) ue = 255;

	cmp	DWORD PTR _ue$[ebp], 255		; 000000ffH
	jbe	SHORT $L66888
	mov	DWORD PTR _ue$[ebp], 255		; 000000ffH
$L66888:

; 1052 : 	if (v <= 0.) ve = 0;

	fld	QWORD PTR _v$[ebp]
	fcomp	QWORD PTR __real@8@00000000000000000000
	fnstsw	ax
	test	ah, 65					; 00000041H
	je	SHORT $L66889
	mov	DWORD PTR _ve$[ebp], 0

; 1053 : 	else ve = itrunc(UVSCALE*v, em);

	jmp	SHORT $L66890
$L66889:
	cmp	DWORD PTR _em$[ebp], 0
	jne	SHORT $L67423
	fld	QWORD PTR __real@8@4007cd00000000000000
	fmul	QWORD PTR _v$[ebp]
	call	__ftol
	mov	DWORD PTR -56+[ebp], eax
	jmp	SHORT $L67424
$L67423:
	fld	QWORD PTR __real@8@4007cd00000000000000
	fmul	QWORD PTR _v$[ebp]
	fstp	QWORD PTR -64+[ebp]
	call	_rand
	mov	DWORD PTR -68+[ebp], eax
	fild	DWORD PTR -68+[ebp]
	fmul	QWORD PTR __real@8@3ff08001000200040000
	fadd	QWORD PTR -64+[ebp]
	fsub	QWORD PTR __real@8@3ffe8000000000000000
	call	__ftol
	mov	DWORD PTR -56+[ebp], eax
$L67424:
	mov	edx, DWORD PTR -56+[ebp]
	mov	DWORD PTR _ve$[ebp], edx
$L66890:

; 1054 : 	if (ve > 255) ve = 255;

	cmp	DWORD PTR _ve$[ebp], 255		; 000000ffH
	jbe	SHORT $L66893
	mov	DWORD PTR _ve$[ebp], 255		; 000000ffH
$L66893:

; 1055 : 					/* combine encodings */
; 1056 : 	return (Le << 16 | ue << 8 | ve);

	mov	eax, DWORD PTR _Le$[ebp]
	shl	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _ue$[ebp]
	shl	ecx, 8
	or	eax, ecx
	or	eax, DWORD PTR _ve$[ebp]

; 1057 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogLuv32fromXYZ ENDP
_TEXT	ENDS
PUBLIC	_TIFFInitSGILog
EXTRN	__assert:NEAR
EXTRN	__TIFFmalloc:NEAR
EXTRN	__TIFFmemset:NEAR
EXTRN	_TIFFError:NEAR
EXTRN	__TIFFMergeFieldInfo:NEAR
_DATA	SEGMENT
	ORG $+3
$SG67287 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG67288 DB	'scheme == COMPRESSION_SGILOG24 || scheme == COMPRESSION_'
	DB	'SGILOG', 00H
	ORG $+1
$SG67296 DB	'%s: No space for LogLuv state block', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_scheme$ = 12
_sp$ = -4
_TIFFInitSGILog PROC NEAR

; 1541 : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 1542 : 	static const char module[] = "TIFFInitSGILog";
; 1543 : 	LogLuvState* sp;
; 1544 : 
; 1545 : 	assert(scheme == COMPRESSION_SGILOG24 || scheme == COMPRESSION_SGILOG);

	cmp	DWORD PTR _scheme$[ebp], 34677		; 00008775H
	je	SHORT $L67428
	cmp	DWORD PTR _scheme$[ebp], 34676		; 00008774H
	je	SHORT $L67428
	push	1545					; 00000609H
	push	OFFSET FLAT:$SG67287
	push	OFFSET FLAT:$SG67288
	call	__assert
	add	esp, 12					; 0000000cH
$L67428:

; 1546 : 
; 1547 : 	/*
; 1548 : 	 * Allocate state block so tag methods have storage to record values.
; 1549 : 	 */
; 1550 : 	tif->tif_data = (tidata_t) _TIFFmalloc(sizeof (LogLuvState));

	push	32					; 00000020H
	call	__TIFFmalloc
	add	esp, 4
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+460], eax

; 1551 : 	if (tif->tif_data == NULL)

	mov	edx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [edx+460], 0
	jne	SHORT $L67292

; 1552 : 		goto bad;

	jmp	$bad$67293
$L67292:

; 1553 : 	sp = (LogLuvState*) tif->tif_data;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 1554 : 	_TIFFmemset((tdata_t)sp, 0, sizeof (*sp));

	push	32					; 00000020H
	push	0
	mov	edx, DWORD PTR _sp$[ebp]
	push	edx
	call	__TIFFmemset
	add	esp, 12					; 0000000cH

; 1555 : 	sp->user_datafmt = SGILOGDATAFMT_UNKNOWN;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax], -1

; 1556 : 	sp->encode_meth = (scheme == COMPRESSION_SGILOG24) ?
; 1557 : 				SGILOGENCODE_RANDITHER : SGILOGENCODE_NODITHER;

	xor	ecx, ecx
	cmp	DWORD PTR _scheme$[ebp], 34677		; 00008775H
	sete	cl
	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+4], ecx

; 1558 : 	sp->tfunc = _logLuvNop;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+20], OFFSET FLAT:__logLuvNop

; 1559 : 
; 1560 : 	/*
; 1561 : 	 * Install codec methods.
; 1562 : 	 * NB: tif_decoderow & tif_encoderow are filled
; 1563 : 	 *     in at setup time.
; 1564 : 	 */
; 1565 : 	tif->tif_setupdecode = LogLuvSetupDecode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+396], OFFSET FLAT:_LogLuvSetupDecode

; 1566 : 	tif->tif_decodestrip = LogLuvDecodeStrip;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+424], OFFSET FLAT:_LogLuvDecodeStrip

; 1567 : 	tif->tif_decodetile = LogLuvDecodeTile;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+432], OFFSET FLAT:_LogLuvDecodeTile

; 1568 : 	tif->tif_setupencode = LogLuvSetupEncode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+404], OFFSET FLAT:_LogLuvSetupEncode

; 1569 : 	tif->tif_encodestrip = LogLuvEncodeStrip;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+428], OFFSET FLAT:_LogLuvEncodeStrip

; 1570 : 	tif->tif_encodetile = LogLuvEncodeTile;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+436], OFFSET FLAT:_LogLuvEncodeTile

; 1571 : 	tif->tif_close = LogLuvClose;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+440], OFFSET FLAT:_LogLuvClose

; 1572 : 	tif->tif_cleanup = LogLuvCleanup;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+448], OFFSET FLAT:_LogLuvCleanup

; 1573 : 
; 1574 : 	/* override SetField so we can handle our private pseudo-tag */
; 1575 : 	_TIFFMergeFieldInfo(tif, LogLuvFieldInfo, N(LogLuvFieldInfo));

	push	2
	push	OFFSET FLAT:_LogLuvFieldInfo
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	__TIFFMergeFieldInfo
	add	esp, 12					; 0000000cH

; 1576 : 	sp->vgetparent = tif->tif_vgetfield;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+544]
	mov	DWORD PTR [ecx+24], eax

; 1577 : 	tif->tif_vgetfield = LogLuvVGetField;   /* hook for codec tags */

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+544], OFFSET FLAT:_LogLuvVGetField

; 1578 : 	sp->vsetparent = tif->tif_vsetfield;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+540]
	mov	DWORD PTR [edx+28], ecx

; 1579 : 	tif->tif_vsetfield = LogLuvVSetField;   /* hook for codec tags */

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+540], OFFSET FLAT:_LogLuvVSetField

; 1580 : 
; 1581 : 	return (1);

	mov	eax, 1
	jmp	SHORT $L67282
$bad$67293:

; 1582 : bad:
; 1583 : 	TIFFError(module, "%s: No space for LogLuv state block", tif->tif_name);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG67296
	push	OFFSET FLAT:_?module@?1??TIFFInitSGILog@@9@9
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 1584 : 	return (0);

	xor	eax, eax
$L67282:

; 1585 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFInitSGILog ENDP
_TEXT	ENDS
EXTRN	_TIFFScanlineSize:NEAR
_DATA	SEGMENT
$SG66120 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66121 DB	'cc%rowlen == 0', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_bp$ = 12
_cc$ = 16
_s$ = 20
_rowlen$ = -4
_LogLuvDecodeStrip PROC NEAR

; 344  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 345  : 	tsize_t rowlen = TIFFScanlineSize(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFScanlineSize
	add	esp, 4
	mov	DWORD PTR _rowlen$[ebp], eax

; 346  : 
; 347  : 	assert(cc%rowlen == 0);

	mov	eax, DWORD PTR _cc$[ebp]
	cdq
	idiv	DWORD PTR _rowlen$[ebp]
	test	edx, edx
	je	SHORT $L67430
	push	347					; 0000015bH
	push	OFFSET FLAT:$SG66120
	push	OFFSET FLAT:$SG66121
	call	__assert
	add	esp, 12					; 0000000cH
$L67430:

; 348  : 	while (cc && (*tif->tif_decoderow)(tif, bp, rowlen, s))

	cmp	DWORD PTR _cc$[ebp], 0
	je	SHORT $L66124
	mov	dx, WORD PTR _s$[ebp]
	push	edx
	mov	eax, DWORD PTR _rowlen$[ebp]
	push	eax
	mov	ecx, DWORD PTR _bp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+416]
	add	esp, 16					; 00000010H
	test	eax, eax
	je	SHORT $L66124

; 349  : 		bp += rowlen, cc -= rowlen;

	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, DWORD PTR _rowlen$[ebp]
	mov	DWORD PTR _bp$[ebp], ecx
	mov	edx, DWORD PTR _cc$[ebp]
	sub	edx, DWORD PTR _rowlen$[ebp]
	mov	DWORD PTR _cc$[ebp], edx
	jmp	SHORT $L67430
$L66124:

; 350  : 	return (cc == 0);

	xor	eax, eax
	cmp	DWORD PTR _cc$[ebp], 0
	sete	al

; 351  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogLuvDecodeStrip ENDP
_TEXT	ENDS
EXTRN	_TIFFTileRowSize:NEAR
_DATA	SEGMENT
	ORG $+1
$SG66137 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66138 DB	'cc%rowlen == 0', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_bp$ = 12
_cc$ = 16
_s$ = 20
_rowlen$ = -4
_LogLuvDecodeTile PROC NEAR

; 360  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 361  : 	tsize_t rowlen = TIFFTileRowSize(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFTileRowSize
	add	esp, 4
	mov	DWORD PTR _rowlen$[ebp], eax

; 362  : 
; 363  : 	assert(cc%rowlen == 0);

	mov	eax, DWORD PTR _cc$[ebp]
	cdq
	idiv	DWORD PTR _rowlen$[ebp]
	test	edx, edx
	je	SHORT $L67432
	push	363					; 0000016bH
	push	OFFSET FLAT:$SG66137
	push	OFFSET FLAT:$SG66138
	call	__assert
	add	esp, 12					; 0000000cH
$L67432:

; 364  : 	while (cc && (*tif->tif_decoderow)(tif, bp, rowlen, s))

	cmp	DWORD PTR _cc$[ebp], 0
	je	SHORT $L66141
	mov	dx, WORD PTR _s$[ebp]
	push	edx
	mov	eax, DWORD PTR _rowlen$[ebp]
	push	eax
	mov	ecx, DWORD PTR _bp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+416]
	add	esp, 16					; 00000010H
	test	eax, eax
	je	SHORT $L66141

; 365  : 		bp += rowlen, cc -= rowlen;

	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, DWORD PTR _rowlen$[ebp]
	mov	DWORD PTR _bp$[ebp], ecx
	mov	edx, DWORD PTR _cc$[ebp]
	sub	edx, DWORD PTR _rowlen$[ebp]
	mov	DWORD PTR _cc$[ebp], edx
	jmp	SHORT $L67432
$L66141:

; 366  : 	return (cc == 0);

	xor	eax, eax
	cmp	DWORD PTR _cc$[ebp], 0
	sete	al

; 367  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogLuvDecodeTile ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+1
$SG66333 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66334 DB	'cc%rowlen == 0', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_bp$ = 12
_cc$ = 16
_s$ = 20
_rowlen$ = -4
_LogLuvEncodeStrip PROC NEAR

; 597  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 598  : 	tsize_t rowlen = TIFFScanlineSize(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFScanlineSize
	add	esp, 4
	mov	DWORD PTR _rowlen$[ebp], eax

; 599  : 
; 600  : 	assert(cc%rowlen == 0);

	mov	eax, DWORD PTR _cc$[ebp]
	cdq
	idiv	DWORD PTR _rowlen$[ebp]
	test	edx, edx
	je	SHORT $L67434
	push	600					; 00000258H
	push	OFFSET FLAT:$SG66333
	push	OFFSET FLAT:$SG66334
	call	__assert
	add	esp, 12					; 0000000cH
$L67434:

; 601  : 	while (cc && (*tif->tif_encoderow)(tif, bp, rowlen, s) == 0)

	cmp	DWORD PTR _cc$[ebp], 0
	je	SHORT $L66337
	mov	dx, WORD PTR _s$[ebp]
	push	edx
	mov	eax, DWORD PTR _rowlen$[ebp]
	push	eax
	mov	ecx, DWORD PTR _bp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+420]
	add	esp, 16					; 00000010H
	test	eax, eax
	jne	SHORT $L66337

; 602  : 		bp += rowlen, cc -= rowlen;

	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, DWORD PTR _rowlen$[ebp]
	mov	DWORD PTR _bp$[ebp], ecx
	mov	edx, DWORD PTR _cc$[ebp]
	sub	edx, DWORD PTR _rowlen$[ebp]
	mov	DWORD PTR _cc$[ebp], edx
	jmp	SHORT $L67434
$L66337:

; 603  : 	return (cc == 0);

	xor	eax, eax
	cmp	DWORD PTR _cc$[ebp], 0
	sete	al

; 604  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogLuvEncodeStrip ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+1
$SG66350 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66351 DB	'cc%rowlen == 0', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_bp$ = 12
_cc$ = 16
_s$ = 20
_rowlen$ = -4
_LogLuvEncodeTile PROC NEAR

; 612  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 613  : 	tsize_t rowlen = TIFFTileRowSize(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFTileRowSize
	add	esp, 4
	mov	DWORD PTR _rowlen$[ebp], eax

; 614  : 
; 615  : 	assert(cc%rowlen == 0);

	mov	eax, DWORD PTR _cc$[ebp]
	cdq
	idiv	DWORD PTR _rowlen$[ebp]
	test	edx, edx
	je	SHORT $L67436
	push	615					; 00000267H
	push	OFFSET FLAT:$SG66350
	push	OFFSET FLAT:$SG66351
	call	__assert
	add	esp, 12					; 0000000cH
$L67436:

; 616  : 	while (cc && (*tif->tif_encoderow)(tif, bp, rowlen, s) == 0)

	cmp	DWORD PTR _cc$[ebp], 0
	je	SHORT $L66354
	mov	dx, WORD PTR _s$[ebp]
	push	edx
	mov	eax, DWORD PTR _rowlen$[ebp]
	push	eax
	mov	ecx, DWORD PTR _bp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+420]
	add	esp, 16					; 00000010H
	test	eax, eax
	jne	SHORT $L66354

; 617  : 		bp += rowlen, cc -= rowlen;

	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, DWORD PTR _rowlen$[ebp]
	mov	DWORD PTR _bp$[ebp], ecx
	mov	edx, DWORD PTR _cc$[ebp]
	sub	edx, DWORD PTR _rowlen$[ebp]
	mov	DWORD PTR _cc$[ebp], edx
	jmp	SHORT $L67436
$L66354:

; 618  : 	return (cc == 0);

	xor	eax, eax
	cmp	DWORD PTR _cc$[ebp], 0
	sete	al

; 619  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogLuvEncodeTile ENDP
__logLuvNop PROC NEAR

; 1141 : {

	push	ebp
	mov	ebp, esp

; 1142 : 	(void) sp; (void) op; (void) n;
; 1143 : }

	pop	ebp
	ret	0
__logLuvNop ENDP
_TEXT	ENDS
EXTRN	__TIFFNoPostDecode:NEAR
_DATA	SEGMENT
	ORG $+1
$SG67144 DB	'must be either LogLUV or LogL', 00H
	ORG $+2
$SG67145 DB	'Inappropriate photometric interpretation %d for SGILog c'
	DB	'ompression; %s', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_sp$ = -4
_td$ = -8
_LogLuvSetupDecode PROC NEAR

; 1302 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 24					; 00000018H

; 1303 : 	LogLuvState* sp = DecoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 1304 : 	TIFFDirectory* td = &tif->tif_dir;

	mov	edx, DWORD PTR _tif$[ebp]
	add	edx, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], edx

; 1305 : 
; 1306 : 	tif->tif_postdecode = _TIFFNoPostDecode;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+528], OFFSET FLAT:__TIFFNoPostDecode

; 1307 : 	switch (td->td_photometric) {

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+46]
	mov	DWORD PTR -12+[ebp], edx
	cmp	DWORD PTR -12+[ebp], 32844		; 0000804cH
	je	$L67135
	cmp	DWORD PTR -12+[ebp], 32845		; 0000804dH
	je	SHORT $L67117
	jmp	$L67143
$L67117:

; 1308 : 	case PHOTOMETRIC_LOGLUV:
; 1309 : 		if (!LogLuvInitState(tif))

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_LogLuvInitState
	add	esp, 4
	test	eax, eax
	jne	SHORT $L67118

; 1310 : 			break;

	jmp	$L67114
$L67118:

; 1311 : 		if (td->td_compression == COMPRESSION_SGILOG24) {

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+44]
	cmp	edx, 34677				; 00008775H
	jne	SHORT $L67119

; 1312 : 			tif->tif_decoderow = LogLuvDecode24;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+416], OFFSET FLAT:_LogLuvDecode24

; 1313 : 			switch (sp->user_datafmt) {

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR -16+[ebp], edx
	cmp	DWORD PTR -16+[ebp], 0
	je	SHORT $L67124
	cmp	DWORD PTR -16+[ebp], 1
	je	SHORT $L67125
	cmp	DWORD PTR -16+[ebp], 3
	je	SHORT $L67126
	jmp	SHORT $L67121
$L67124:

; 1314 : 			case SGILOGDATAFMT_FLOAT:
; 1315 : 				sp->tfunc = Luv24toXYZ;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+20], OFFSET FLAT:_Luv24toXYZ

; 1316 : 				break;

	jmp	SHORT $L67121
$L67125:

; 1317 : 			case SGILOGDATAFMT_16BIT:
; 1318 : 				sp->tfunc = Luv24toLuv48;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+20], OFFSET FLAT:_Luv24toLuv48

; 1319 : 				break;

	jmp	SHORT $L67121
$L67126:

; 1320 : 			case SGILOGDATAFMT_8BIT:
; 1321 : 				sp->tfunc = Luv24toRGB;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+20], OFFSET FLAT:_Luv24toRGB
$L67121:

; 1324 : 		} else {

	jmp	SHORT $L67129
$L67119:

; 1325 : 			tif->tif_decoderow = LogLuvDecode32;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+416], OFFSET FLAT:_LogLuvDecode32

; 1326 : 			switch (sp->user_datafmt) {

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR -20+[ebp], edx
	cmp	DWORD PTR -20+[ebp], 0
	je	SHORT $L67132
	cmp	DWORD PTR -20+[ebp], 1
	je	SHORT $L67133
	cmp	DWORD PTR -20+[ebp], 3
	je	SHORT $L67134
	jmp	SHORT $L67129
$L67132:

; 1327 : 			case SGILOGDATAFMT_FLOAT:
; 1328 : 				sp->tfunc = Luv32toXYZ;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+20], OFFSET FLAT:_Luv32toXYZ

; 1329 : 				break;

	jmp	SHORT $L67129
$L67133:

; 1330 : 			case SGILOGDATAFMT_16BIT:
; 1331 : 				sp->tfunc = Luv32toLuv48;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+20], OFFSET FLAT:_Luv32toLuv48

; 1332 : 				break;

	jmp	SHORT $L67129
$L67134:

; 1333 : 			case SGILOGDATAFMT_8BIT:
; 1334 : 				sp->tfunc = Luv32toRGB;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+20], OFFSET FLAT:_Luv32toRGB
$L67129:

; 1338 : 		return (1);

	mov	eax, 1
	jmp	SHORT $L67109
$L67135:

; 1339 : 	case PHOTOMETRIC_LOGL:
; 1340 : 		if (!LogL16InitState(tif))

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_LogL16InitState
	add	esp, 4
	test	eax, eax
	jne	SHORT $L67136

; 1341 : 			break;

	jmp	SHORT $L67114
$L67136:

; 1342 : 		tif->tif_decoderow = LogL16Decode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+416], OFFSET FLAT:_LogL16Decode

; 1343 : 		switch (sp->user_datafmt) {

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR -24+[ebp], eax
	cmp	DWORD PTR -24+[ebp], 0
	je	SHORT $L67141
	cmp	DWORD PTR -24+[ebp], 3
	je	SHORT $L67142
	jmp	SHORT $L67138
$L67141:

; 1344 : 		case SGILOGDATAFMT_FLOAT:
; 1345 : 			sp->tfunc = L16toY;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+20], OFFSET FLAT:_L16toY

; 1346 : 			break;

	jmp	SHORT $L67138
$L67142:

; 1347 : 		case SGILOGDATAFMT_8BIT:
; 1348 : 			sp->tfunc = L16toGry;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+20], OFFSET FLAT:_L16toGry
$L67138:

; 1351 : 		return (1);

	mov	eax, 1
	jmp	SHORT $L67109
$L67143:

; 1352 : 	default:
; 1353 : 		TIFFError(tif->tif_name,
; 1354 :     "Inappropriate photometric interpretation %d for SGILog compression; %s",
; 1355 : 		    td->td_photometric, "must be either LogLUV or LogL");

	push	OFFSET FLAT:$SG67144
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+46]
	push	ecx
	push	OFFSET FLAT:$SG67145
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 16					; 00000010H
$L67114:

; 1358 : 	return (0);

	xor	eax, eax
$L67109:

; 1359 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogLuvSetupDecode ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+1
$SG65979 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG65980 DB	's == 0', 00H
	ORG $+1
$SG65983 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG65984 DB	'sp != NULL', 00H
	ORG $+1
$SG65989 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG65990 DB	'sp->tbuflen >= npixels', 00H
	ORG $+1
$SG66011 DB	'LogL16Decode: Not enough data at row %d (short %d pixels'
	DB	')', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_op$ = 12
_occ$ = 16
_s$ = 20
_sp$ = -12
_shft$ = -36
_i$ = -24
_npixels$ = -28
_bp$ = -32
_tp$ = -20
_b$ = -8
_cc$ = -16
_rc$ = -4
_LogL16Decode PROC NEAR

; 185  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 36					; 00000024H

; 186  : 	LogLuvState* sp = DecoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 187  : 	int shft, i, npixels;
; 188  : 	u_char* bp;
; 189  : 	int16* tp;
; 190  : 	int16 b;
; 191  : 	int cc, rc;
; 192  : 
; 193  : 	assert(s == 0);

	mov	edx, DWORD PTR _s$[ebp]
	and	edx, 65535				; 0000ffffH
	test	edx, edx
	je	SHORT $L67440
	push	193					; 000000c1H
	push	OFFSET FLAT:$SG65979
	push	OFFSET FLAT:$SG65980
	call	__assert
	add	esp, 12					; 0000000cH
$L67440:

; 194  : 	assert(sp != NULL);

	cmp	DWORD PTR _sp$[ebp], 0
	jne	SHORT $L67441
	push	194					; 000000c2H
	push	OFFSET FLAT:$SG65983
	push	OFFSET FLAT:$SG65984
	call	__assert
	add	esp, 12					; 0000000cH
$L67441:

; 195  : 
; 196  : 	npixels = occ / sp->pixel_size;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _occ$[ebp]
	cdq
	idiv	DWORD PTR [ecx+8]
	mov	DWORD PTR _npixels$[ebp], eax

; 197  : 
; 198  : 	if (sp->user_datafmt == SGILOGDATAFMT_16BIT)

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx], 1
	jne	SHORT $L65985

; 199  : 		tp = (int16*) op;

	mov	eax, DWORD PTR _op$[ebp]
	mov	DWORD PTR _tp$[ebp], eax

; 200  : 	else {

	jmp	SHORT $L65987
$L65985:

; 201  : 		assert(sp->tbuflen >= npixels);

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	cmp	edx, DWORD PTR _npixels$[ebp]
	jge	SHORT $L67442
	push	201					; 000000c9H
	push	OFFSET FLAT:$SG65989
	push	OFFSET FLAT:$SG65990
	call	__assert
	add	esp, 12					; 0000000cH
$L67442:

; 202  : 		tp = (int16*) sp->tbuf;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR _tp$[ebp], edx
$L65987:

; 204  : 	_TIFFmemset((tdata_t) tp, 0, npixels*sizeof (tp[0]));

	mov	eax, DWORD PTR _npixels$[ebp]
	shl	eax, 1
	push	eax
	push	0
	mov	ecx, DWORD PTR _tp$[ebp]
	push	ecx
	call	__TIFFmemset
	add	esp, 12					; 0000000cH

; 205  : 
; 206  : 	bp = (u_char*) tif->tif_rawcp;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+480]
	mov	DWORD PTR _bp$[ebp], eax

; 207  : 	cc = tif->tif_rawcc;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+484]
	mov	DWORD PTR _cc$[ebp], edx

; 208  : 					/* get each byte string */
; 209  : 	for (shft = 2*8; (shft -= 8) >= 0; ) {

	mov	DWORD PTR _shft$[ebp], 16		; 00000010H
$L65995:
	mov	eax, DWORD PTR _shft$[ebp]
	sub	eax, 8
	mov	DWORD PTR _shft$[ebp], eax
	cmp	DWORD PTR _shft$[ebp], 0
	jl	$L65996

; 210  : 		for (i = 0; i < npixels && cc > 0; )

	mov	DWORD PTR _i$[ebp], 0
$L65998:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _npixels$[ebp]
	jge	$L65999
	cmp	DWORD PTR _cc$[ebp], 0
	jle	$L65999

; 211  : 			if (*bp >= 128) {		/* run */

	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	cmp	eax, 128				; 00000080H
	jl	SHORT $L66000

; 212  : 				rc = *bp++ + (2-128);

	mov	ecx, DWORD PTR _bp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	sub	edx, 126				; 0000007eH
	mov	DWORD PTR _rc$[ebp], edx
	mov	eax, DWORD PTR _bp$[ebp]
	add	eax, 1
	mov	DWORD PTR _bp$[ebp], eax

; 213  : 				b = (int16)*bp++ << shft;

	mov	ecx, DWORD PTR _bp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, DWORD PTR _shft$[ebp]
	shl	edx, cl
	mov	WORD PTR _b$[ebp], dx
	mov	eax, DWORD PTR _bp$[ebp]
	add	eax, 1
	mov	DWORD PTR _bp$[ebp], eax

; 214  : 				cc -= 2;

	mov	ecx, DWORD PTR _cc$[ebp]
	sub	ecx, 2
	mov	DWORD PTR _cc$[ebp], ecx
$L66003:

; 215  : 				while (rc--)

	mov	edx, DWORD PTR _rc$[ebp]
	mov	eax, DWORD PTR _rc$[ebp]
	sub	eax, 1
	mov	DWORD PTR _rc$[ebp], eax
	test	edx, edx
	je	SHORT $L66004

; 216  : 					tp[i++] |= b;

	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _tp$[ebp]
	mov	ax, WORD PTR [edx+ecx*2]
	or	ax, WORD PTR _b$[ebp]
	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _tp$[ebp]
	mov	WORD PTR [edx+ecx*2], ax
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
	jmp	SHORT $L66003
$L66004:

; 217  : 			} else {			/* non-run */

	jmp	SHORT $L66008
$L66000:

; 218  : 				rc = *bp++;		/* nul is noop */

	mov	ecx, DWORD PTR _bp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	DWORD PTR _rc$[ebp], edx
	mov	eax, DWORD PTR _bp$[ebp]
	add	eax, 1
	mov	DWORD PTR _bp$[ebp], eax
$L66007:

; 219  : 				while (--cc && rc--)

	mov	ecx, DWORD PTR _cc$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _cc$[ebp], ecx
	cmp	DWORD PTR _cc$[ebp], 0
	je	SHORT $L66008
	mov	edx, DWORD PTR _rc$[ebp]
	mov	eax, DWORD PTR _rc$[ebp]
	sub	eax, 1
	mov	DWORD PTR _rc$[ebp], eax
	test	edx, edx
	je	SHORT $L66008

; 220  : 					tp[i++] |= (int16)*bp++ << shft;

	mov	ecx, DWORD PTR _bp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, DWORD PTR _shft$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _tp$[ebp]
	mov	ax, WORD PTR [ecx+eax*2]
	or	ax, dx
	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _tp$[ebp]
	mov	WORD PTR [edx+ecx*2], ax
	mov	eax, DWORD PTR _bp$[ebp]
	add	eax, 1
	mov	DWORD PTR _bp$[ebp], eax
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
	jmp	SHORT $L66007
$L66008:

; 221  : 			}

	jmp	$L65998
$L65999:

; 222  : 		if (i != npixels) {

	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR _npixels$[ebp]
	je	SHORT $L66010

; 223  : 			TIFFError(tif->tif_name,
; 224  : 		"LogL16Decode: Not enough data at row %d (short %d pixels)",
; 225  : 			    tif->tif_row, npixels - i);

	mov	eax, DWORD PTR _npixels$[ebp]
	sub	eax, DWORD PTR _i$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	push	edx
	push	OFFSET FLAT:$SG66011
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 16					; 00000010H

; 226  : 			tif->tif_rawcp = (tidata_t) bp;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _bp$[ebp]
	mov	DWORD PTR [edx+480], eax

; 227  : 			tif->tif_rawcc = cc;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _cc$[ebp]
	mov	DWORD PTR [ecx+484], edx

; 228  : 			return (0);

	xor	eax, eax
	jmp	SHORT $L65967
$L66010:

; 230  : 	}

	jmp	$L65995
$L65996:

; 231  : 	(*sp->tfunc)(sp, op, npixels);

	mov	eax, DWORD PTR _npixels$[ebp]
	push	eax
	mov	ecx, DWORD PTR _op$[ebp]
	push	ecx
	mov	edx, DWORD PTR _sp$[ebp]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	call	DWORD PTR [eax+20]
	add	esp, 12					; 0000000cH

; 232  : 	tif->tif_rawcp = (tidata_t) bp;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _bp$[ebp]
	mov	DWORD PTR [ecx+480], edx

; 233  : 	tif->tif_rawcc = cc;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _cc$[ebp]
	mov	DWORD PTR [eax+484], ecx

; 234  : 	return (1);

	mov	eax, 1
$L65967:

; 235  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogL16Decode ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+2
$SG66032 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66033 DB	's == 0', 00H
	ORG $+1
$SG66036 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66037 DB	'sp != NULL', 00H
	ORG $+1
$SG66042 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66043 DB	'sp->tbuflen >= npixels', 00H
	ORG $+1
$SG66051 DB	'LogLuvDecode24: Not enough data at row %d (short %d pixe'
	DB	'ls)', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_op$ = 12
_occ$ = 16
_s$ = 20
_sp$ = -4
_cc$ = -8
_i$ = -16
_npixels$ = -20
_bp$ = -24
_tp$ = -12
_LogLuvDecode24 PROC NEAR

; 242  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 24					; 00000018H

; 243  : 	LogLuvState* sp = DecoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 244  : 	int cc, i, npixels;
; 245  : 	u_char* bp;
; 246  : 	uint32* tp;
; 247  : 
; 248  : 	assert(s == 0);

	mov	edx, DWORD PTR _s$[ebp]
	and	edx, 65535				; 0000ffffH
	test	edx, edx
	je	SHORT $L67444
	push	248					; 000000f8H
	push	OFFSET FLAT:$SG66032
	push	OFFSET FLAT:$SG66033
	call	__assert
	add	esp, 12					; 0000000cH
$L67444:

; 249  : 	assert(sp != NULL);

	cmp	DWORD PTR _sp$[ebp], 0
	jne	SHORT $L67445
	push	249					; 000000f9H
	push	OFFSET FLAT:$SG66036
	push	OFFSET FLAT:$SG66037
	call	__assert
	add	esp, 12					; 0000000cH
$L67445:

; 250  : 
; 251  : 	npixels = occ / sp->pixel_size;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _occ$[ebp]
	cdq
	idiv	DWORD PTR [ecx+8]
	mov	DWORD PTR _npixels$[ebp], eax

; 252  : 
; 253  : 	if (sp->user_datafmt == SGILOGDATAFMT_RAW)

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx], 2
	jne	SHORT $L66038

; 254  : 		tp = (uint32 *)op;

	mov	eax, DWORD PTR _op$[ebp]
	mov	DWORD PTR _tp$[ebp], eax

; 255  : 	else {

	jmp	SHORT $L66040
$L66038:

; 256  : 		assert(sp->tbuflen >= npixels);

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	cmp	edx, DWORD PTR _npixels$[ebp]
	jge	SHORT $L67446
	push	256					; 00000100H
	push	OFFSET FLAT:$SG66042
	push	OFFSET FLAT:$SG66043
	call	__assert
	add	esp, 12					; 0000000cH
$L67446:

; 257  : 		tp = (uint32 *) sp->tbuf;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR _tp$[ebp], edx
$L66040:

; 259  : 					/* copy to array of uint32 */
; 260  : 	bp = (u_char*) tif->tif_rawcp;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	DWORD PTR _bp$[ebp], ecx

; 261  : 	cc = tif->tif_rawcc;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+484]
	mov	DWORD PTR _cc$[ebp], eax

; 262  : 	for (i = 0; i < npixels && cc > 0; i++) {

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L66046
$L66047:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
$L66046:
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR _npixels$[ebp]
	jge	SHORT $L66048
	cmp	DWORD PTR _cc$[ebp], 0
	jle	SHORT $L66048

; 263  : 		tp[i] = bp[0] << 16 | bp[1] << 8 | bp[2];

	mov	eax, DWORD PTR _bp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	shl	ecx, 16					; 00000010H
	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	shl	eax, 8
	or	ecx, eax
	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+2]
	or	ecx, eax
	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _tp$[ebp]
	mov	DWORD PTR [eax+edx*4], ecx

; 264  : 		bp += 3;

	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, 3
	mov	DWORD PTR _bp$[ebp], ecx

; 265  : 		cc -= 3;

	mov	edx, DWORD PTR _cc$[ebp]
	sub	edx, 3
	mov	DWORD PTR _cc$[ebp], edx

; 266  : 	}

	jmp	SHORT $L66047
$L66048:

; 267  : 	tif->tif_rawcp = (tidata_t) bp;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _bp$[ebp]
	mov	DWORD PTR [eax+480], ecx

; 268  : 	tif->tif_rawcc = cc;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _cc$[ebp]
	mov	DWORD PTR [edx+484], eax

; 269  : 	if (i != npixels) {

	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _npixels$[ebp]
	je	SHORT $L66050

; 270  : 		TIFFError(tif->tif_name,
; 271  : 	    "LogLuvDecode24: Not enough data at row %d (short %d pixels)",
; 272  : 		    tif->tif_row, npixels - i);

	mov	edx, DWORD PTR _npixels$[ebp]
	sub	edx, DWORD PTR _i$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+356]
	push	ecx
	push	OFFSET FLAT:$SG66051
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 16					; 00000010H

; 273  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L66023
$L66050:

; 275  : 	(*sp->tfunc)(sp, op, npixels);

	mov	ecx, DWORD PTR _npixels$[ebp]
	push	ecx
	mov	edx, DWORD PTR _op$[ebp]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _sp$[ebp]
	call	DWORD PTR [ecx+20]
	add	esp, 12					; 0000000cH

; 276  : 	return (1);

	mov	eax, 1
$L66023:

; 277  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogLuvDecode24 ENDP
_TEXT	ENDS
_DATA	SEGMENT
$SG66072 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66073 DB	's == 0', 00H
	ORG $+1
$SG66077 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66078 DB	'sp != NULL', 00H
	ORG $+1
$SG66083 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66084 DB	'sp->tbuflen >= npixels', 00H
	ORG $+1
$SG66105 DB	'LogLuvDecode32: Not enough data at row %d (short %d pixe'
	DB	'ls)', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_op$ = 12
_occ$ = 16
_s$ = 20
_sp$ = -12
_shft$ = -36
_i$ = -24
_npixels$ = -28
_bp$ = -32
_tp$ = -20
_b$ = -8
_cc$ = -16
_rc$ = -4
_LogLuvDecode32 PROC NEAR

; 284  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 36					; 00000024H

; 285  : 	LogLuvState* sp;
; 286  : 	int shft, i, npixels;
; 287  : 	u_char* bp;
; 288  : 	uint32* tp;
; 289  : 	uint32 b;
; 290  : 	int cc, rc;
; 291  : 
; 292  : 	assert(s == 0);

	mov	eax, DWORD PTR _s$[ebp]
	and	eax, 65535				; 0000ffffH
	test	eax, eax
	je	SHORT $L67448
	push	292					; 00000124H
	push	OFFSET FLAT:$SG66072
	push	OFFSET FLAT:$SG66073
	call	__assert
	add	esp, 12					; 0000000cH
$L67448:

; 293  : 	sp = DecoderState(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+460]
	mov	DWORD PTR _sp$[ebp], eax

; 294  : 	assert(sp != NULL);

	cmp	DWORD PTR _sp$[ebp], 0
	jne	SHORT $L67449
	push	294					; 00000126H
	push	OFFSET FLAT:$SG66077
	push	OFFSET FLAT:$SG66078
	call	__assert
	add	esp, 12					; 0000000cH
$L67449:

; 295  : 
; 296  : 	npixels = occ / sp->pixel_size;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _occ$[ebp]
	cdq
	idiv	DWORD PTR [ecx+8]
	mov	DWORD PTR _npixels$[ebp], eax

; 297  : 
; 298  : 	if (sp->user_datafmt == SGILOGDATAFMT_RAW)

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx], 2
	jne	SHORT $L66079

; 299  : 		tp = (uint32*) op;

	mov	eax, DWORD PTR _op$[ebp]
	mov	DWORD PTR _tp$[ebp], eax

; 300  : 	else {

	jmp	SHORT $L66081
$L66079:

; 301  : 		assert(sp->tbuflen >= npixels);

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	cmp	edx, DWORD PTR _npixels$[ebp]
	jge	SHORT $L67450
	push	301					; 0000012dH
	push	OFFSET FLAT:$SG66083
	push	OFFSET FLAT:$SG66084
	call	__assert
	add	esp, 12					; 0000000cH
$L67450:

; 302  : 		tp = (uint32*) sp->tbuf;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR _tp$[ebp], edx
$L66081:

; 304  : 	_TIFFmemset((tdata_t) tp, 0, npixels*sizeof (tp[0]));

	mov	eax, DWORD PTR _npixels$[ebp]
	shl	eax, 2
	push	eax
	push	0
	mov	ecx, DWORD PTR _tp$[ebp]
	push	ecx
	call	__TIFFmemset
	add	esp, 12					; 0000000cH

; 305  : 
; 306  : 	bp = (u_char*) tif->tif_rawcp;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+480]
	mov	DWORD PTR _bp$[ebp], eax

; 307  : 	cc = tif->tif_rawcc;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+484]
	mov	DWORD PTR _cc$[ebp], edx

; 308  : 					/* get each byte string */
; 309  : 	for (shft = 4*8; (shft -= 8) >= 0; ) {

	mov	DWORD PTR _shft$[ebp], 32		; 00000020H
$L66089:
	mov	eax, DWORD PTR _shft$[ebp]
	sub	eax, 8
	mov	DWORD PTR _shft$[ebp], eax
	cmp	DWORD PTR _shft$[ebp], 0
	jl	$L66090

; 310  : 		for (i = 0; i < npixels && cc > 0; )

	mov	DWORD PTR _i$[ebp], 0
$L66092:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _npixels$[ebp]
	jge	$L66093
	cmp	DWORD PTR _cc$[ebp], 0
	jle	$L66093

; 311  : 			if (*bp >= 128) {		/* run */

	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	cmp	eax, 128				; 00000080H
	jl	SHORT $L66094

; 312  : 				rc = *bp++ + (2-128);

	mov	ecx, DWORD PTR _bp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	sub	edx, 126				; 0000007eH
	mov	DWORD PTR _rc$[ebp], edx
	mov	eax, DWORD PTR _bp$[ebp]
	add	eax, 1
	mov	DWORD PTR _bp$[ebp], eax

; 313  : 				b = (uint32)*bp++ << shft;

	mov	ecx, DWORD PTR _bp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, DWORD PTR _shft$[ebp]
	shl	edx, cl
	mov	DWORD PTR _b$[ebp], edx
	mov	eax, DWORD PTR _bp$[ebp]
	add	eax, 1
	mov	DWORD PTR _bp$[ebp], eax

; 314  : 				cc -= 2;

	mov	ecx, DWORD PTR _cc$[ebp]
	sub	ecx, 2
	mov	DWORD PTR _cc$[ebp], ecx
$L66097:

; 315  : 				while (rc--)

	mov	edx, DWORD PTR _rc$[ebp]
	mov	eax, DWORD PTR _rc$[ebp]
	sub	eax, 1
	mov	DWORD PTR _rc$[ebp], eax
	test	edx, edx
	je	SHORT $L66098

; 316  : 					tp[i++] |= b;

	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _tp$[ebp]
	mov	eax, DWORD PTR [edx+ecx*4]
	or	eax, DWORD PTR _b$[ebp]
	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _tp$[ebp]
	mov	DWORD PTR [edx+ecx*4], eax
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
	jmp	SHORT $L66097
$L66098:

; 317  : 			} else {			/* non-run */

	jmp	SHORT $L66102
$L66094:

; 318  : 				rc = *bp++;		/* nul is noop */

	mov	ecx, DWORD PTR _bp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	DWORD PTR _rc$[ebp], edx
	mov	eax, DWORD PTR _bp$[ebp]
	add	eax, 1
	mov	DWORD PTR _bp$[ebp], eax
$L66101:

; 319  : 				while (--cc && rc--)

	mov	ecx, DWORD PTR _cc$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _cc$[ebp], ecx
	cmp	DWORD PTR _cc$[ebp], 0
	je	SHORT $L66102
	mov	edx, DWORD PTR _rc$[ebp]
	mov	eax, DWORD PTR _rc$[ebp]
	sub	eax, 1
	mov	DWORD PTR _rc$[ebp], eax
	test	edx, edx
	je	SHORT $L66102

; 320  : 					tp[i++] |= (uint32)*bp++ << shft;

	mov	ecx, DWORD PTR _bp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, DWORD PTR _shft$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _tp$[ebp]
	mov	eax, DWORD PTR [ecx+eax*4]
	or	eax, edx
	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _tp$[ebp]
	mov	DWORD PTR [edx+ecx*4], eax
	mov	eax, DWORD PTR _bp$[ebp]
	add	eax, 1
	mov	DWORD PTR _bp$[ebp], eax
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _i$[ebp], ecx
	jmp	SHORT $L66101
$L66102:

; 321  : 			}

	jmp	$L66092
$L66093:

; 322  : 		if (i != npixels) {

	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR _npixels$[ebp]
	je	SHORT $L66104

; 323  : 			TIFFError(tif->tif_name,
; 324  : 		"LogLuvDecode32: Not enough data at row %d (short %d pixels)",
; 325  : 			    tif->tif_row, npixels - i);

	mov	eax, DWORD PTR _npixels$[ebp]
	sub	eax, DWORD PTR _i$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	push	edx
	push	OFFSET FLAT:$SG66105
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 16					; 00000010H

; 326  : 			tif->tif_rawcp = (tidata_t) bp;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _bp$[ebp]
	mov	DWORD PTR [edx+480], eax

; 327  : 			tif->tif_rawcc = cc;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _cc$[ebp]
	mov	DWORD PTR [ecx+484], edx

; 328  : 			return (0);

	xor	eax, eax
	jmp	SHORT $L66061
$L66104:

; 330  : 	}

	jmp	$L66089
$L66090:

; 331  : 	(*sp->tfunc)(sp, op, npixels);

	mov	eax, DWORD PTR _npixels$[ebp]
	push	eax
	mov	ecx, DWORD PTR _op$[ebp]
	push	ecx
	mov	edx, DWORD PTR _sp$[ebp]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	call	DWORD PTR [eax+20]
	add	esp, 12					; 0000000cH

; 332  : 	tif->tif_rawcp = (tidata_t) bp;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _bp$[ebp]
	mov	DWORD PTR [ecx+480], edx

; 333  : 	tif->tif_rawcc = cc;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _cc$[ebp]
	mov	DWORD PTR [eax+484], ecx

; 334  : 	return (1);

	mov	eax, 1
$L66061:

; 335  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogLuvDecode32 ENDP
_l16$ = -4
_yp$ = -8
_sp$ = 8
_op$ = 12
_n$ = 16
_L16toY	PROC NEAR

; 680  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 681  : 	int16* l16 = (int16*) sp->tbuf;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _l16$[ebp], ecx

; 682  : 	float* yp = (float*) op;

	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR _yp$[ebp], edx
$L66565:

; 683  : 
; 684  : 	while (n-- > 0)

	mov	eax, DWORD PTR _n$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	test	eax, eax
	jle	SHORT $L66566

; 685  : 		*yp++ = (float)LogL16toY(*l16++);

	mov	edx, DWORD PTR _l16$[ebp]
	movsx	eax, WORD PTR [edx]
	mov	DWORD PTR -12+[ebp], eax
	mov	ecx, DWORD PTR -12+[ebp]
	push	ecx
	mov	edx, DWORD PTR _l16$[ebp]
	add	edx, 2
	mov	DWORD PTR _l16$[ebp], edx
	call	_LogL16toY
	add	esp, 4
	mov	eax, DWORD PTR _yp$[ebp]
	fstp	DWORD PTR [eax]
	mov	ecx, DWORD PTR _yp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _yp$[ebp], ecx
	jmp	SHORT $L66565
$L66566:

; 686  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_L16toY	ENDP
_sp$ = 8
_op$ = 12
_n$ = 16
_l16$ = -4
_gp$ = -8
_Y$66583 = -16
_L16toGry PROC NEAR

; 690  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 28					; 0000001cH

; 691  : 	int16* l16 = (int16*) sp->tbuf;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _l16$[ebp], ecx

; 692  : 	uint8* gp = (uint8*) op;

	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR _gp$[ebp], edx
$L66581:

; 693  : 
; 694  : 	while (n-- > 0) {

	mov	eax, DWORD PTR _n$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	test	eax, eax
	jle	$L66582

; 695  : 		double Y = LogL16toY(*l16++);

	mov	edx, DWORD PTR _l16$[ebp]
	movsx	eax, WORD PTR [edx]
	mov	DWORD PTR -20+[ebp], eax
	mov	ecx, DWORD PTR -20+[ebp]
	push	ecx
	mov	edx, DWORD PTR _l16$[ebp]
	add	edx, 2
	mov	DWORD PTR _l16$[ebp], edx
	call	_LogL16toY
	add	esp, 4
	fst	QWORD PTR _Y$66583[ebp]

; 696  : 		*gp++ = (Y <= 0.) ? 0 : (Y >= 1.) ? 255 : (int)(256.*sqrt(Y));

	fcomp	QWORD PTR __real@8@00000000000000000000
	fnstsw	ax
	test	ah, 65					; 00000041H
	je	SHORT $L67455
	mov	DWORD PTR -24+[ebp], 0
	jmp	SHORT $L67456
$L67455:
	fld	QWORD PTR _Y$66583[ebp]
	fcomp	QWORD PTR __real@8@3fff8000000000000000
	fnstsw	ax
	test	ah, 1
	jne	SHORT $L67453
	mov	DWORD PTR -28+[ebp], 255		; 000000ffH
	jmp	SHORT $L67454
$L67453:
	mov	eax, DWORD PTR _Y$66583[ebp+4]
	push	eax
	mov	ecx, DWORD PTR _Y$66583[ebp]
	push	ecx
	call	_sqrt
	add	esp, 8
	fmul	QWORD PTR __real@8@40078000000000000000
	call	__ftol
	mov	DWORD PTR -28+[ebp], eax
$L67454:
	mov	edx, DWORD PTR -28+[ebp]
	mov	DWORD PTR -24+[ebp], edx
$L67456:
	mov	eax, DWORD PTR _gp$[ebp]
	mov	cl, BYTE PTR -24+[ebp]
	mov	BYTE PTR [eax], cl
	mov	edx, DWORD PTR _gp$[ebp]
	add	edx, 1
	mov	DWORD PTR _gp$[ebp], edx

; 697  : 	}

	jmp	$L66581
$L66582:

; 698  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_L16toGry ENDP
_sp$ = 8
_op$ = 12
_n$ = 16
_luv$ = -8
_xyz$ = -4
_Luv24toXYZ PROC NEAR

; 920  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 921  : 	uint32* luv = (uint32*) sp->tbuf;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _luv$[ebp], ecx

; 922  : 	float* xyz = (float*) op;

	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR _xyz$[ebp], edx
$L66772:

; 923  : 
; 924  : 	while (n-- > 0) {

	mov	eax, DWORD PTR _n$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	test	eax, eax
	jle	SHORT $L66773

; 925  : 		LogLuv24toXYZ(*luv, xyz);

	mov	edx, DWORD PTR _xyz$[ebp]
	push	edx
	mov	eax, DWORD PTR _luv$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_LogLuv24toXYZ
	add	esp, 8

; 926  : 		xyz += 3;

	mov	edx, DWORD PTR _xyz$[ebp]
	add	edx, 12					; 0000000cH
	mov	DWORD PTR _xyz$[ebp], edx

; 927  : 		luv++;

	mov	eax, DWORD PTR _luv$[ebp]
	add	eax, 4
	mov	DWORD PTR _luv$[ebp], eax

; 928  : 	}

	jmp	SHORT $L66772
$L66773:

; 929  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Luv24toXYZ ENDP
_TEXT	ENDS
PUBLIC	__real@8@400e8000000000000000
;	COMDAT __real@8@400e8000000000000000
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_luv.c
CONST	SEGMENT
__real@8@400e8000000000000000 DQ 040e0000000000000r ; 32768
CONST	ENDS
_TEXT	SEGMENT
_sp$ = 8
_op$ = 12
_n$ = 16
_luv$ = -4
_luv3$ = -8
_u$66789 = -16
_v$66790 = -24
_Luv24toLuv48 PROC NEAR

; 933  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 24					; 00000018H

; 934  : 	uint32* luv = (uint32*) sp->tbuf;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _luv$[ebp], ecx

; 935  : 	int16* luv3 = (int16*) op;

	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR _luv3$[ebp], edx
$L66787:

; 936  : 
; 937  : 	while (n-- > 0) {

	mov	eax, DWORD PTR _n$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	test	eax, eax
	jle	$L66788

; 938  : 		double u, v;
; 939  : 
; 940  : 		*luv3++ = (int16)((*luv >> 12 & 0xffd) + 13314);

	mov	edx, DWORD PTR _luv$[ebp]
	mov	eax, DWORD PTR [edx]
	shr	eax, 12					; 0000000cH
	and	eax, 4093				; 00000ffdH
	add	eax, 13314				; 00003402H
	mov	ecx, DWORD PTR _luv3$[ebp]
	mov	WORD PTR [ecx], ax
	mov	edx, DWORD PTR _luv3$[ebp]
	add	edx, 2
	mov	DWORD PTR _luv3$[ebp], edx

; 941  : 		if (uv_decode(&u, &v, *luv&0x3fff) < 0) {

	mov	eax, DWORD PTR _luv$[ebp]
	mov	ecx, DWORD PTR [eax]
	and	ecx, 16383				; 00003fffH
	push	ecx
	lea	edx, DWORD PTR _v$66790[ebp]
	push	edx
	lea	eax, DWORD PTR _u$66789[ebp]
	push	eax
	call	_uv_decode
	add	esp, 12					; 0000000cH
	test	eax, eax
	jge	SHORT $L66792

; 942  : 			u = U_NEU;

	mov	DWORD PTR _u$66789[ebp], -1122669542	; bd156c1aH
	mov	DWORD PTR _u$66789[ebp+4], 1070264966	; 3fcaf286H

; 943  : 			v = V_NEU;

	mov	DWORD PTR _v$66790[ebp], -1799874146	; 94b8199eH
	mov	DWORD PTR _v$66790[ebp+4], 1071534295	; 3fde50d7H
$L66792:

; 945  : 		*luv3++ = (int16)(u * (1L<<15));

	fld	QWORD PTR _u$66789[ebp]
	fmul	QWORD PTR __real@8@400e8000000000000000
	call	__ftol
	mov	ecx, DWORD PTR _luv3$[ebp]
	mov	WORD PTR [ecx], ax
	mov	edx, DWORD PTR _luv3$[ebp]
	add	edx, 2
	mov	DWORD PTR _luv3$[ebp], edx

; 946  : 		*luv3++ = (int16)(v * (1L<<15));

	fld	QWORD PTR _v$66790[ebp]
	fmul	QWORD PTR __real@8@400e8000000000000000
	call	__ftol
	mov	ecx, DWORD PTR _luv3$[ebp]
	mov	WORD PTR [ecx], ax
	mov	edx, DWORD PTR _luv3$[ebp]
	add	edx, 2
	mov	DWORD PTR _luv3$[ebp], edx

; 947  : 		luv++;

	mov	eax, DWORD PTR _luv$[ebp]
	add	eax, 4
	mov	DWORD PTR _luv$[ebp], eax

; 948  : 	}

	jmp	$L66787
$L66788:

; 949  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Luv24toLuv48 ENDP
_sp$ = 8
_op$ = 12
_n$ = 16
_luv$ = -4
_rgb$ = -8
_xyz$66810 = -20
_Luv24toRGB PROC NEAR

; 953  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 24					; 00000018H

; 954  : 	uint32* luv = (uint32*) sp->tbuf;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _luv$[ebp], ecx

; 955  : 	uint8* rgb = (uint8*) op;

	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR _rgb$[ebp], edx
$L66808:

; 956  : 
; 957  : 	while (n-- > 0) {

	mov	eax, DWORD PTR _n$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	test	eax, eax
	jle	SHORT $L66809

; 958  : 		float xyz[3];
; 959  : 
; 960  : 		LogLuv24toXYZ(*luv++, xyz);

	lea	edx, DWORD PTR _xyz$66810[ebp]
	push	edx
	mov	eax, DWORD PTR _luv$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR -24+[ebp], ecx
	mov	edx, DWORD PTR -24+[ebp]
	push	edx
	mov	eax, DWORD PTR _luv$[ebp]
	add	eax, 4
	mov	DWORD PTR _luv$[ebp], eax
	call	_LogLuv24toXYZ
	add	esp, 8

; 961  : 		XYZtoRGB24(xyz, rgb);

	mov	ecx, DWORD PTR _rgb$[ebp]
	push	ecx
	lea	edx, DWORD PTR _xyz$66810[ebp]
	push	edx
	call	_XYZtoRGB24
	add	esp, 8

; 962  : 		rgb += 3;

	mov	eax, DWORD PTR _rgb$[ebp]
	add	eax, 3
	mov	DWORD PTR _rgb$[ebp], eax

; 963  : 	}

	jmp	SHORT $L66808
$L66809:

; 964  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Luv24toRGB ENDP
_sp$ = 8
_op$ = 12
_n$ = 16
_luv$ = -8
_xyz$ = -4
_Luv32toXYZ PROC NEAR

; 1061 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 1062 : 	uint32* luv = (uint32*) sp->tbuf;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _luv$[ebp], ecx

; 1063 : 	float* xyz = (float*) op;

	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR _xyz$[ebp], edx
$L66907:

; 1064 : 
; 1065 : 	while (n-- > 0) {

	mov	eax, DWORD PTR _n$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	test	eax, eax
	jle	SHORT $L66908

; 1066 : 		LogLuv32toXYZ(*luv++, xyz);

	mov	edx, DWORD PTR _xyz$[ebp]
	push	edx
	mov	eax, DWORD PTR _luv$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR -12+[ebp], ecx
	mov	edx, DWORD PTR -12+[ebp]
	push	edx
	mov	eax, DWORD PTR _luv$[ebp]
	add	eax, 4
	mov	DWORD PTR _luv$[ebp], eax
	call	_LogLuv32toXYZ
	add	esp, 8

; 1067 : 		xyz += 3;

	mov	ecx, DWORD PTR _xyz$[ebp]
	add	ecx, 12					; 0000000cH
	mov	DWORD PTR _xyz$[ebp], ecx

; 1068 : 	}

	jmp	SHORT $L66907
$L66908:

; 1069 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Luv32toXYZ ENDP
_sp$ = 8
_op$ = 12
_n$ = 16
_luv$ = -4
_luv3$ = -8
_u$66924 = -16
_v$66925 = -24
_Luv32toLuv48 PROC NEAR

; 1073 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 40					; 00000028H

; 1074 : 	uint32* luv = (uint32*) sp->tbuf;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _luv$[ebp], ecx

; 1075 : 	int16* luv3 = (int16*) op;

	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR _luv3$[ebp], edx
$L66922:

; 1076 : 
; 1077 : 	while (n-- > 0) {

	mov	eax, DWORD PTR _n$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	test	eax, eax
	jle	$L66923

; 1078 : 		double u, v;
; 1079 : 
; 1080 : 		*luv3++ = (int16)(*luv >> 16);

	mov	edx, DWORD PTR _luv$[ebp]
	mov	eax, DWORD PTR [edx]
	shr	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _luv3$[ebp]
	mov	WORD PTR [ecx], ax
	mov	edx, DWORD PTR _luv3$[ebp]
	add	edx, 2
	mov	DWORD PTR _luv3$[ebp], edx

; 1081 : 		u = 1./UVSCALE * ((*luv>>8 & 0xff) + .5);

	mov	eax, DWORD PTR _luv$[ebp]
	mov	ecx, DWORD PTR [eax]
	shr	ecx, 8
	and	ecx, 255				; 000000ffH
	mov	DWORD PTR -32+[ebp], ecx
	mov	DWORD PTR -32+[ebp+4], 0
	fild	QWORD PTR -32+[ebp]
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	fmul	QWORD PTR __real@8@3ff69fd809fd809fd800
	fstp	QWORD PTR _u$66924[ebp]

; 1082 : 		v = 1./UVSCALE * ((*luv & 0xff) + .5);

	mov	edx, DWORD PTR _luv$[ebp]
	mov	eax, DWORD PTR [edx]
	and	eax, 255				; 000000ffH
	mov	DWORD PTR -40+[ebp], eax
	mov	DWORD PTR -40+[ebp+4], 0
	fild	QWORD PTR -40+[ebp]
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	fmul	QWORD PTR __real@8@3ff69fd809fd809fd800
	fstp	QWORD PTR _v$66925[ebp]

; 1083 : 		*luv3++ = (int16)(u * (1L<<15));

	fld	QWORD PTR _u$66924[ebp]
	fmul	QWORD PTR __real@8@400e8000000000000000
	call	__ftol
	mov	ecx, DWORD PTR _luv3$[ebp]
	mov	WORD PTR [ecx], ax
	mov	edx, DWORD PTR _luv3$[ebp]
	add	edx, 2
	mov	DWORD PTR _luv3$[ebp], edx

; 1084 : 		*luv3++ = (int16)(v * (1L<<15));

	fld	QWORD PTR _v$66925[ebp]
	fmul	QWORD PTR __real@8@400e8000000000000000
	call	__ftol
	mov	ecx, DWORD PTR _luv3$[ebp]
	mov	WORD PTR [ecx], ax
	mov	edx, DWORD PTR _luv3$[ebp]
	add	edx, 2
	mov	DWORD PTR _luv3$[ebp], edx

; 1085 : 		luv++;

	mov	eax, DWORD PTR _luv$[ebp]
	add	eax, 4
	mov	DWORD PTR _luv$[ebp], eax

; 1086 : 	}

	jmp	$L66922
$L66923:

; 1087 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Luv32toLuv48 ENDP
_sp$ = 8
_op$ = 12
_n$ = 16
_luv$ = -4
_rgb$ = -8
_xyz$66944 = -20
_Luv32toRGB PROC NEAR

; 1091 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 24					; 00000018H

; 1092 : 	uint32* luv = (uint32*) sp->tbuf;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _luv$[ebp], ecx

; 1093 : 	uint8* rgb = (uint8*) op;

	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR _rgb$[ebp], edx
$L66942:

; 1094 : 
; 1095 : 	while (n-- > 0) {

	mov	eax, DWORD PTR _n$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	test	eax, eax
	jle	SHORT $L66943

; 1096 : 		float xyz[3];
; 1097 : 
; 1098 : 		LogLuv32toXYZ(*luv++, xyz);

	lea	edx, DWORD PTR _xyz$66944[ebp]
	push	edx
	mov	eax, DWORD PTR _luv$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR -24+[ebp], ecx
	mov	edx, DWORD PTR -24+[ebp]
	push	edx
	mov	eax, DWORD PTR _luv$[ebp]
	add	eax, 4
	mov	DWORD PTR _luv$[ebp], eax
	call	_LogLuv32toXYZ
	add	esp, 8

; 1099 : 		XYZtoRGB24(xyz, rgb);

	mov	ecx, DWORD PTR _rgb$[ebp]
	push	ecx
	lea	edx, DWORD PTR _xyz$66944[ebp]
	push	edx
	call	_XYZtoRGB24
	add	esp, 8

; 1100 : 		rgb += 3;

	mov	eax, DWORD PTR _rgb$[ebp]
	add	eax, 3
	mov	DWORD PTR _rgb$[ebp], eax

; 1101 : 	}

	jmp	SHORT $L66942
$L66943:

; 1102 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Luv32toRGB ENDP
_TEXT	ENDS
_DATA	SEGMENT
$SG67021 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG67022 DB	'sp != NULL', 00H
	ORG $+1
$SG67024 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG67025 DB	'td->td_photometric == PHOTOMETRIC_LOGL', 00H
	ORG $+1
$SG67038 DB	'No support for converting user data format to LogL', 00H
	ORG $+1
$SG67043 DB	'%s: No space for SGILog translation buffer', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_td$ = -8
_sp$ = -4
_LogL16InitState PROC NEAR

; 1166 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 1167 : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 1168 : 	LogLuvState* sp = DecoderState(tif);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+460]
	mov	DWORD PTR _sp$[ebp], edx

; 1169 : 	static const char module[] = "LogL16InitState";
; 1170 : 
; 1171 : 	assert(sp != NULL);

	cmp	DWORD PTR _sp$[ebp], 0
	jne	SHORT $L67466
	push	1171					; 00000493H
	push	OFFSET FLAT:$SG67021
	push	OFFSET FLAT:$SG67022
	call	__assert
	add	esp, 12					; 0000000cH
$L67466:

; 1172 : 	assert(td->td_photometric == PHOTOMETRIC_LOGL);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+46]
	cmp	edx, 32844				; 0000804cH
	je	SHORT $L67467
	push	1172					; 00000494H
	push	OFFSET FLAT:$SG67024
	push	OFFSET FLAT:$SG67025
	call	__assert
	add	esp, 12					; 0000000cH
$L67467:

; 1173 : 
; 1174 : 	/* for some reason, we can't do this in TIFFInitLogL16 */
; 1175 : 	if (sp->user_datafmt == SGILOGDATAFMT_UNKNOWN)

	mov	ecx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [ecx], -1
	jne	SHORT $L67026

; 1176 : 		sp->user_datafmt = LogL16GuessDataFmt(td);

	mov	edx, DWORD PTR _td$[ebp]
	push	edx
	call	_LogL16GuessDataFmt
	add	esp, 4
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx], eax
$L67026:

; 1177 : 	switch (sp->user_datafmt) {

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR -12+[ebp], eax
	cmp	DWORD PTR -12+[ebp], 0
	je	SHORT $L67031
	cmp	DWORD PTR -12+[ebp], 1
	je	SHORT $L67033
	cmp	DWORD PTR -12+[ebp], 3
	je	SHORT $L67035
	jmp	SHORT $L67037
$L67031:

; 1178 : 	case SGILOGDATAFMT_FLOAT:
; 1179 : 		sp->pixel_size = sizeof (float);

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+8], 4

; 1180 : 		break;

	jmp	SHORT $L67028
$L67033:

; 1181 : 	case SGILOGDATAFMT_16BIT:
; 1182 : 		sp->pixel_size = sizeof (int16);

	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+8], 2

; 1183 : 		break;

	jmp	SHORT $L67028
$L67035:

; 1184 : 	case SGILOGDATAFMT_8BIT:
; 1185 : 		sp->pixel_size = sizeof (uint8);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+8], 1

; 1186 : 		break;

	jmp	SHORT $L67028
$L67037:

; 1187 : 	default:
; 1188 : 		TIFFError(tif->tif_name,
; 1189 : 		    "No support for converting user data format to LogL");

	push	OFFSET FLAT:$SG67038
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 8

; 1190 : 		return (0);

	xor	eax, eax
	jmp	SHORT $L67013
$L67028:

; 1192 : 	sp->tbuflen = td->td_imagewidth * td->td_rowsperstrip;

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [eax+12]
	imul	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+16], edx

; 1193 : 	sp->tbuf = (tidata_t*) _TIFFmalloc(sp->tbuflen * sizeof (int16));

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	shl	edx, 1
	push	edx
	call	__TIFFmalloc
	add	esp, 4
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+12], eax

; 1194 : 	if (sp->tbuf == NULL) {

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx+12], 0
	jne	SHORT $L67042

; 1195 : 		TIFFError(module, "%s: No space for SGILog translation buffer",
; 1196 : 		    tif->tif_name);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG67043
	push	OFFSET FLAT:_?module@?1??LogL16InitState@@9@9
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 1197 : 		return (0);

	xor	eax, eax
	jmp	SHORT $L67013
$L67042:

; 1199 : 	return (1);

	mov	eax, 1
$L67013:

; 1200 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogL16InitState ENDP
_td$ = 8
_LogL16GuessDataFmt PROC NEAR

; 1147 : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 1148 : #define	PACK(s,b,f)	(((b)<<6)|((s)<<3)|(f))
; 1149 : 	switch (PACK(td->td_samplesperpixel, td->td_bitspersample, td->td_sampleformat)) {

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+40]
	shl	ecx, 6
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+54]
	shl	eax, 3
	or	ecx, eax
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+42]
	or	ecx, eax
	mov	DWORD PTR -4+[ebp], ecx
	cmp	DWORD PTR -4+[ebp], 1034		; 0000040aH
	jg	SHORT $L67469
	cmp	DWORD PTR -4+[ebp], 1033		; 00000409H
	jge	SHORT $L67008
	cmp	DWORD PTR -4+[ebp], 521			; 00000209H
	je	SHORT $L67009
	cmp	DWORD PTR -4+[ebp], 524			; 0000020cH
	je	SHORT $L67009
	jmp	SHORT $L67004
$L67469:
	cmp	DWORD PTR -4+[ebp], 1036		; 0000040cH
	je	SHORT $L67008
	cmp	DWORD PTR -4+[ebp], 2059		; 0000080bH
	je	SHORT $L67007
	jmp	SHORT $L67004
$L67007:

; 1150 : 	case PACK(1, 32, SAMPLEFORMAT_IEEEFP):
; 1151 : 		return (SGILOGDATAFMT_FLOAT);

	xor	eax, eax
	jmp	SHORT $L67001
$L67008:

; 1152 : 	case PACK(1, 16, SAMPLEFORMAT_VOID):
; 1153 : 	case PACK(1, 16, SAMPLEFORMAT_INT):
; 1154 : 	case PACK(1, 16, SAMPLEFORMAT_UINT):
; 1155 : 		return (SGILOGDATAFMT_16BIT);

	mov	eax, 1
	jmp	SHORT $L67001
$L67009:

; 1156 : 	case PACK(1,  8, SAMPLEFORMAT_VOID):
; 1157 : 	case PACK(1,  8, SAMPLEFORMAT_UINT):
; 1158 : 		return (SGILOGDATAFMT_8BIT);

	mov	eax, 3
	jmp	SHORT $L67001
$L67004:

; 1160 : #undef PACK
; 1161 : 	return (SGILOGDATAFMT_UNKNOWN);

	or	eax, -1
$L67001:

; 1162 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogL16GuessDataFmt ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+1
$SG67079 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG67080 DB	'sp != NULL', 00H
	ORG $+1
$SG67082 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG67083 DB	'td->td_photometric == PHOTOMETRIC_LOGLUV', 00H
	ORG $+3
$SG67085 DB	'SGILog compression cannot handle non-contiguous data', 00H
	ORG $+3
$SG67100 DB	'No support for converting user data format to LogLuv', 00H
	ORG $+3
$SG67105 DB	'%s: No space for SGILog translation buffer', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_td$ = -8
_sp$ = -4
_LogLuvInitState PROC NEAR

; 1256 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 1257 : 	TIFFDirectory* td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 1258 : 	LogLuvState* sp = DecoderState(tif);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+460]
	mov	DWORD PTR _sp$[ebp], edx

; 1259 : 	static const char module[] = "LogLuvInitState";
; 1260 : 
; 1261 : 	assert(sp != NULL);

	cmp	DWORD PTR _sp$[ebp], 0
	jne	SHORT $L67471
	push	1261					; 000004edH
	push	OFFSET FLAT:$SG67079
	push	OFFSET FLAT:$SG67080
	call	__assert
	add	esp, 12					; 0000000cH
$L67471:

; 1262 : 	assert(td->td_photometric == PHOTOMETRIC_LOGLUV);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+46]
	cmp	edx, 32845				; 0000804dH
	je	SHORT $L67472
	push	1262					; 000004eeH
	push	OFFSET FLAT:$SG67082
	push	OFFSET FLAT:$SG67083
	call	__assert
	add	esp, 12					; 0000000cH
$L67472:

; 1263 : 
; 1264 : 	/* for some reason, we can't do this in TIFFInitLogLuv */
; 1265 : 	if (td->td_planarconfig != PLANARCONFIG_CONTIG) {

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+90]
	cmp	edx, 1
	je	SHORT $L67084

; 1266 : 		TIFFError(module,
; 1267 : 		    "SGILog compression cannot handle non-contiguous data");

	push	OFFSET FLAT:$SG67085
	push	OFFSET FLAT:_?module@?1??LogLuvInitState@@9@9
	call	_TIFFError
	add	esp, 8

; 1268 : 		return (0);

	xor	eax, eax
	jmp	$L67071
$L67084:

; 1270 : 	if (sp->user_datafmt == SGILOGDATAFMT_UNKNOWN)

	mov	eax, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [eax], -1
	jne	SHORT $L67086

; 1271 : 		sp->user_datafmt = LogLuvGuessDataFmt(td);

	mov	ecx, DWORD PTR _td$[ebp]
	push	ecx
	call	_LogLuvGuessDataFmt
	add	esp, 4
	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx], eax
$L67086:

; 1272 : 	switch (sp->user_datafmt) {

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR -12+[ebp], ecx
	cmp	DWORD PTR -12+[ebp], 3
	ja	SHORT $L67099
	mov	edx, DWORD PTR -12+[ebp]
	jmp	DWORD PTR $L67473[edx*4]
$L67091:

; 1273 : 	case SGILOGDATAFMT_FLOAT:
; 1274 : 		sp->pixel_size = 3*sizeof (float);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+8], 12			; 0000000cH

; 1275 : 		break;

	jmp	SHORT $L67088
$L67093:

; 1276 : 	case SGILOGDATAFMT_16BIT:
; 1277 : 		sp->pixel_size = 3*sizeof (int16);

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+8], 6

; 1278 : 		break;

	jmp	SHORT $L67088
$L67095:

; 1279 : 	case SGILOGDATAFMT_RAW:
; 1280 : 		sp->pixel_size = sizeof (uint32);

	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+8], 4

; 1281 : 		break;

	jmp	SHORT $L67088
$L67097:

; 1282 : 	case SGILOGDATAFMT_8BIT:
; 1283 : 		sp->pixel_size = 3*sizeof (uint8);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+8], 3

; 1284 : 		break;

	jmp	SHORT $L67088
$L67099:

; 1285 : 	default:
; 1286 : 		TIFFError(tif->tif_name,
; 1287 : 		    "No support for converting user data format to LogLuv");

	push	OFFSET FLAT:$SG67100
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 8

; 1288 : 		return (0);

	xor	eax, eax
	jmp	SHORT $L67071
$L67088:

; 1290 : 	sp->tbuflen = td->td_imagewidth * td->td_rowsperstrip;

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [eax+12]
	imul	edx, DWORD PTR [ecx+56]
	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+16], edx

; 1291 : 	sp->tbuf = (tidata_t*) _TIFFmalloc(sp->tbuflen * sizeof (uint32));

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+16]
	shl	edx, 2
	push	edx
	call	__TIFFmalloc
	add	esp, 4
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+12], eax

; 1292 : 	if (sp->tbuf == NULL) {

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx+12], 0
	jne	SHORT $L67104

; 1293 : 		TIFFError(module, "%s: No space for SGILog translation buffer",
; 1294 : 		    tif->tif_name);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG67105
	push	OFFSET FLAT:_?module@?1??LogLuvInitState@@9@9
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 1295 : 		return (0);

	xor	eax, eax
	jmp	SHORT $L67071
$L67104:

; 1297 : 	return (1);

	mov	eax, 1
$L67071:

; 1298 : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L67473:
	DD	$L67091
	DD	$L67093
	DD	$L67095
	DD	$L67097
_LogLuvInitState ENDP
_td$ = 8
_guess$ = -4
_LogLuvGuessDataFmt PROC NEAR

; 1204 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 1205 : 	int guess;
; 1206 : 
; 1207 : 	/*
; 1208 : 	 * If the user didn't tell us their datafmt,
; 1209 : 	 * take our best guess from the bitspersample.
; 1210 : 	 */
; 1211 : #define	PACK(a,b)	(((a)<<3)|(b))
; 1212 : 	switch (PACK(td->td_bitspersample, td->td_sampleformat)) {

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+40]
	shl	ecx, 3
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+42]
	or	ecx, eax
	mov	DWORD PTR -8+[ebp], ecx
	mov	ecx, DWORD PTR -8+[ebp]
	sub	ecx, 65					; 00000041H
	mov	DWORD PTR -8+[ebp], ecx
	cmp	DWORD PTR -8+[ebp], 195			; 000000c3H
	ja	SHORT $L67058
	mov	eax, DWORD PTR -8+[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR $L67475[eax]
	jmp	DWORD PTR $L67476[edx*4]
$L67054:

; 1213 : 	case PACK(32, SAMPLEFORMAT_IEEEFP):
; 1214 : 		guess = SGILOGDATAFMT_FLOAT;

	mov	DWORD PTR _guess$[ebp], 0

; 1215 : 		break;

	jmp	SHORT $L67051
$L67055:

; 1216 : 	case PACK(32, SAMPLEFORMAT_VOID):
; 1217 : 	case PACK(32, SAMPLEFORMAT_UINT):
; 1218 : 	case PACK(32, SAMPLEFORMAT_INT):
; 1219 : 		guess = SGILOGDATAFMT_RAW;

	mov	DWORD PTR _guess$[ebp], 2

; 1220 : 		break;

	jmp	SHORT $L67051
$L67056:

; 1221 : 	case PACK(16, SAMPLEFORMAT_VOID):
; 1222 : 	case PACK(16, SAMPLEFORMAT_INT):
; 1223 : 	case PACK(16, SAMPLEFORMAT_UINT):
; 1224 : 		guess = SGILOGDATAFMT_16BIT;

	mov	DWORD PTR _guess$[ebp], 1

; 1225 : 		break;

	jmp	SHORT $L67051
$L67057:

; 1226 : 	case PACK( 8, SAMPLEFORMAT_VOID):
; 1227 : 	case PACK( 8, SAMPLEFORMAT_UINT):
; 1228 : 		guess = SGILOGDATAFMT_8BIT;

	mov	DWORD PTR _guess$[ebp], 3

; 1229 : 		break;

	jmp	SHORT $L67051
$L67058:

; 1230 : 	default:
; 1231 : 		guess = SGILOGDATAFMT_UNKNOWN;

	mov	DWORD PTR _guess$[ebp], -1
$L67051:

; 1235 : 	/*
; 1236 : 	 * Double-check samples per pixel.
; 1237 : 	 */
; 1238 : 	switch (td->td_samplesperpixel) {

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+54]
	mov	DWORD PTR -12+[ebp], edx
	cmp	DWORD PTR -12+[ebp], 1
	je	SHORT $L67063
	cmp	DWORD PTR -12+[ebp], 3
	je	SHORT $L67065
	jmp	SHORT $L67067
$L67063:

; 1239 : 	case 1:
; 1240 : 		if (guess != SGILOGDATAFMT_RAW)

	cmp	DWORD PTR _guess$[ebp], 2
	je	SHORT $L67064

; 1241 : 			guess = SGILOGDATAFMT_UNKNOWN;

	mov	DWORD PTR _guess$[ebp], -1
$L67064:

; 1242 : 		break;

	jmp	SHORT $L67060
$L67065:

; 1243 : 	case 3:
; 1244 : 		if (guess == SGILOGDATAFMT_RAW)

	cmp	DWORD PTR _guess$[ebp], 2
	jne	SHORT $L67066

; 1245 : 			guess = SGILOGDATAFMT_UNKNOWN;

	mov	DWORD PTR _guess$[ebp], -1
$L67066:

; 1246 : 		break;

	jmp	SHORT $L67060
$L67067:

; 1247 : 	default:
; 1248 : 		guess = SGILOGDATAFMT_UNKNOWN;

	mov	DWORD PTR _guess$[ebp], -1
$L67060:

; 1251 : 	return (guess);

	mov	eax, DWORD PTR _guess$[ebp]

; 1252 : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L67476:
	DD	$L67057
	DD	$L67056
	DD	$L67055
	DD	$L67054
	DD	$L67058
$L67475:
	DB	0
	DB	4
	DB	4
	DB	0
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	1
	DB	1
	DB	4
	DB	1
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	4
	DB	2
	DB	2
	DB	3
	DB	2
_LogLuvGuessDataFmt ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+1
$SG67188 DB	'must be either LogLUV or LogL', 00H
	ORG $+2
$SG67189 DB	'Inappropriate photometric interpretation %d for SGILog c'
	DB	'ompression; %s', 00H
	ORG $+1
$SG67190 DB	'Y, L', 00H
	ORG $+3
$SG67191 DB	'XYZ, Luv', 00H
	ORG $+3
$SG67192 DB	'SGILog compression supported only for %s, or raw data', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_sp$ = -4
_td$ = -8
_LogLuvSetupEncode PROC NEAR

; 1363 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 28					; 0000001cH

; 1364 : 	LogLuvState* sp = EncoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 1365 : 	TIFFDirectory* td = &tif->tif_dir;

	mov	edx, DWORD PTR _tif$[ebp]
	add	edx, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], edx

; 1366 : 
; 1367 : 	switch (td->td_photometric) {

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+46]
	mov	DWORD PTR -12+[ebp], ecx
	cmp	DWORD PTR -12+[ebp], 32844		; 0000804cH
	je	$L67178
	cmp	DWORD PTR -12+[ebp], 32845		; 0000804dH
	je	SHORT $L67157
	jmp	$L67187
$L67157:

; 1368 : 	case PHOTOMETRIC_LOGLUV:
; 1369 : 		if (!LogLuvInitState(tif))

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_LogLuvInitState
	add	esp, 4
	test	eax, eax
	jne	SHORT $L67158

; 1370 : 			break;

	jmp	$L67154
$L67158:

; 1371 : 		if (td->td_compression == COMPRESSION_SGILOG24) {

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+44]
	cmp	ecx, 34677				; 00008775H
	jne	SHORT $L67159

; 1372 : 			tif->tif_encoderow = LogLuvEncode24;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+420], OFFSET FLAT:_LogLuvEncode24

; 1373 : 			switch (sp->user_datafmt) {

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR -16+[ebp], ecx
	cmp	DWORD PTR -16+[ebp], 0
	je	SHORT $L67164
	cmp	DWORD PTR -16+[ebp], 1
	je	SHORT $L67165
	cmp	DWORD PTR -16+[ebp], 2
	je	SHORT $L67166
	jmp	SHORT $L67167
$L67164:

; 1374 : 			case SGILOGDATAFMT_FLOAT:
; 1375 : 				sp->tfunc = Luv24fromXYZ;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+20], OFFSET FLAT:_Luv24fromXYZ

; 1376 : 				break;

	jmp	SHORT $L67161
$L67165:

; 1377 : 			case SGILOGDATAFMT_16BIT:
; 1378 : 				sp->tfunc = Luv24fromLuv48;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+20], OFFSET FLAT:_Luv24fromLuv48

; 1379 : 				break;

	jmp	SHORT $L67161
$L67166:

; 1380 : 			case SGILOGDATAFMT_RAW:
; 1381 : 				break;

	jmp	SHORT $L67161
$L67167:

; 1382 : 			default:
; 1383 : 				goto notsupported;

	jmp	$notsupported$67168
$L67161:

; 1385 : 		} else {

	jmp	SHORT $L67171
$L67159:

; 1386 : 			tif->tif_encoderow = LogLuvEncode32;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+420], OFFSET FLAT:_LogLuvEncode32

; 1387 : 			switch (sp->user_datafmt) {

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR -20+[ebp], eax
	cmp	DWORD PTR -20+[ebp], 0
	je	SHORT $L67174
	cmp	DWORD PTR -20+[ebp], 1
	je	SHORT $L67175
	cmp	DWORD PTR -20+[ebp], 2
	je	SHORT $L67176
	jmp	SHORT $L67177
$L67174:

; 1388 : 			case SGILOGDATAFMT_FLOAT:
; 1389 : 				sp->tfunc = Luv32fromXYZ;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+20], OFFSET FLAT:_Luv32fromXYZ

; 1390 : 				break;

	jmp	SHORT $L67171
$L67175:

; 1391 : 			case SGILOGDATAFMT_16BIT:
; 1392 : 				sp->tfunc = Luv32fromLuv48;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+20], OFFSET FLAT:_Luv32fromLuv48

; 1393 : 				break;

	jmp	SHORT $L67171
$L67176:

; 1394 : 			case SGILOGDATAFMT_RAW:
; 1395 : 				break;

	jmp	SHORT $L67171
$L67177:

; 1396 : 			default:
; 1397 : 				goto notsupported;

	jmp	SHORT $notsupported$67168
$L67171:

; 1400 : 		break;

	jmp	SHORT $L67154
$L67178:

; 1401 : 	case PHOTOMETRIC_LOGL:
; 1402 : 		if (!LogL16InitState(tif))

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_LogL16InitState
	add	esp, 4
	test	eax, eax
	jne	SHORT $L67179

; 1403 : 			break;

	jmp	SHORT $L67154
$L67179:

; 1404 : 		tif->tif_encoderow = LogL16Encode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+420], OFFSET FLAT:_LogL16Encode

; 1405 : 		switch (sp->user_datafmt) {

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR -24+[ebp], eax
	cmp	DWORD PTR -24+[ebp], 0
	je	SHORT $L67184
	cmp	DWORD PTR -24+[ebp], 1
	je	SHORT $L67185
	jmp	SHORT $L67186
$L67184:

; 1406 : 		case SGILOGDATAFMT_FLOAT:
; 1407 : 			sp->tfunc = L16fromY;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+20], OFFSET FLAT:_L16fromY

; 1408 : 			break;

	jmp	SHORT $L67181
$L67185:

; 1409 : 		case SGILOGDATAFMT_16BIT:
; 1410 : 			break;

	jmp	SHORT $L67181
$L67186:

; 1411 : 		default:
; 1412 : 			goto notsupported;

	jmp	SHORT $notsupported$67168
$L67181:

; 1414 : 		break;

	jmp	SHORT $L67154
$L67187:

; 1415 : 	default:
; 1416 : 		TIFFError(tif->tif_name,
; 1417 :     "Inappropriate photometric interpretation %d for SGILog compression; %s",
; 1418 :     		    td->td_photometric, "must be either LogLUV or LogL");

	push	OFFSET FLAT:$SG67188
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+46]
	push	eax
	push	OFFSET FLAT:$SG67189
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 16					; 00000010H
$L67154:

; 1421 : 	return (1);

	mov	eax, 1
	jmp	SHORT $L67149
$notsupported$67168:

; 1422 : notsupported:
; 1423 : 	TIFFError(tif->tif_name,
; 1424 : 	    "SGILog compression supported only for %s, or raw data",
; 1425 : 	    td->td_photometric == PHOTOMETRIC_LOGL ? "Y, L" : "XYZ, Luv");

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+46]
	cmp	ecx, 32844				; 0000804cH
	jne	SHORT $L67478
	mov	DWORD PTR -28+[ebp], OFFSET FLAT:$SG67190
	jmp	SHORT $L67479
$L67478:
	mov	DWORD PTR -28+[ebp], OFFSET FLAT:$SG67191
$L67479:
	mov	edx, DWORD PTR -28+[ebp]
	push	edx
	push	OFFSET FLAT:$SG67192
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 1426 : 	return (0);

	xor	eax, eax
$L67149:

; 1427 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogLuvSetupEncode ENDP
_TEXT	ENDS
EXTRN	_TIFFFlushData1:NEAR
_DATA	SEGMENT
	ORG $+2
$SG66166 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66167 DB	's == 0', 00H
	ORG $+1
$SG66170 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66171 DB	'sp != NULL', 00H
	ORG $+1
$SG66177 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66178 DB	'sp->tbuflen >= npixels', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_bp$ = 12
_cc$ = 16
_s$ = 20
_sp$ = -20
_shft$ = -48
_i$ = -32
_j$ = -36
_npixels$ = -44
_op$ = -16
_tp$ = -24
_b$ = -12
_occ$ = -28
_rc$ = -8
_mask$ = -40
_beg$ = -4
_LogL16Encode PROC NEAR

; 374  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 48					; 00000030H

; 375  : 	LogLuvState* sp = EncoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 376  : 	int shft, i, j, npixels;
; 377  : 	tidata_t op;
; 378  : 	int16* tp;
; 379  : 	int16 b;
; 380  : 	int occ, rc=0, mask, beg;

	mov	DWORD PTR _rc$[ebp], 0

; 381  : 
; 382  : 	assert(s == 0);

	mov	edx, DWORD PTR _s$[ebp]
	and	edx, 65535				; 0000ffffH
	test	edx, edx
	je	SHORT $L67481
	push	382					; 0000017eH
	push	OFFSET FLAT:$SG66166
	push	OFFSET FLAT:$SG66167
	call	__assert
	add	esp, 12					; 0000000cH
$L67481:

; 383  : 	assert(sp != NULL);

	cmp	DWORD PTR _sp$[ebp], 0
	jne	SHORT $L67482
	push	383					; 0000017fH
	push	OFFSET FLAT:$SG66170
	push	OFFSET FLAT:$SG66171
	call	__assert
	add	esp, 12					; 0000000cH
$L67482:

; 384  : 	npixels = cc / sp->pixel_size;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _cc$[ebp]
	cdq
	idiv	DWORD PTR [ecx+8]
	mov	DWORD PTR _npixels$[ebp], eax

; 385  : 
; 386  : 	if (sp->user_datafmt == SGILOGDATAFMT_16BIT)

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx], 1
	jne	SHORT $L66172

; 387  : 		tp = (int16*) bp;

	mov	eax, DWORD PTR _bp$[ebp]
	mov	DWORD PTR _tp$[ebp], eax

; 388  : 	else {

	jmp	SHORT $L66174
$L66172:

; 389  : 		tp = (int16*) sp->tbuf;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR _tp$[ebp], edx

; 390  : 		assert(sp->tbuflen >= npixels);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	cmp	ecx, DWORD PTR _npixels$[ebp]
	jge	SHORT $L67483
	push	390					; 00000186H
	push	OFFSET FLAT:$SG66177
	push	OFFSET FLAT:$SG66178
	call	__assert
	add	esp, 12					; 0000000cH
$L67483:

; 391  : 		(*sp->tfunc)(sp, bp, npixels);

	mov	eax, DWORD PTR _npixels$[ebp]
	push	eax
	mov	ecx, DWORD PTR _bp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _sp$[ebp]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	call	DWORD PTR [eax+20]
	add	esp, 12					; 0000000cH
$L66174:

; 393  : 					/* compress each byte string */
; 394  : 	op = tif->tif_rawcp;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+480]
	mov	DWORD PTR _op$[ebp], edx

; 395  : 	occ = tif->tif_rawdatasize - tif->tif_rawcc;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [eax+476]
	sub	edx, DWORD PTR [ecx+484]
	mov	DWORD PTR _occ$[ebp], edx

; 396  : 	for (shft = 2*8; (shft -= 8) >= 0; )

	mov	DWORD PTR _shft$[ebp], 16		; 00000010H
$L66180:
	mov	eax, DWORD PTR _shft$[ebp]
	sub	eax, 8
	mov	DWORD PTR _shft$[ebp], eax
	cmp	DWORD PTR _shft$[ebp], 0
	jl	$L66181

; 397  : 		for (i = 0; i < npixels; i += rc) {

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L66182
$L66183:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, DWORD PTR _rc$[ebp]
	mov	DWORD PTR _i$[ebp], ecx
$L66182:
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR _npixels$[ebp]
	jge	$L66184

; 398  : 			if (occ < 4) {

	cmp	DWORD PTR _occ$[ebp], 4
	jge	SHORT $L66185

; 399  : 				tif->tif_rawcp = op;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _op$[ebp]
	mov	DWORD PTR [eax+480], ecx

; 400  : 				tif->tif_rawcc = tif->tif_rawdatasize - occ;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+476]
	sub	eax, DWORD PTR _occ$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+484], eax

; 401  : 				if (!TIFFFlushData1(tif))

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFlushData1
	add	esp, 4
	test	eax, eax
	jne	SHORT $L66186

; 402  : 					return (-1);

	or	eax, -1
	jmp	$L66151
$L66186:

; 403  : 				op = tif->tif_rawcp;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	DWORD PTR _op$[ebp], ecx

; 404  : 				occ = tif->tif_rawdatasize - tif->tif_rawcc;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [edx+476]
	sub	ecx, DWORD PTR [eax+484]
	mov	DWORD PTR _occ$[ebp], ecx
$L66185:

; 406  : 			mask = 0xff << shft;		/* find next run */

	mov	edx, 255				; 000000ffH
	mov	ecx, DWORD PTR _shft$[ebp]
	shl	edx, cl
	mov	DWORD PTR _mask$[ebp], edx

; 407  : 			for (beg = i; beg < npixels; beg += rc) {

	mov	eax, DWORD PTR _i$[ebp]
	mov	DWORD PTR _beg$[ebp], eax
	jmp	SHORT $L66187
$L66188:
	mov	ecx, DWORD PTR _beg$[ebp]
	add	ecx, DWORD PTR _rc$[ebp]
	mov	DWORD PTR _beg$[ebp], ecx
$L66187:
	mov	edx, DWORD PTR _beg$[ebp]
	cmp	edx, DWORD PTR _npixels$[ebp]
	jge	SHORT $L66189

; 408  : 				b = tp[beg] & mask;

	mov	eax, DWORD PTR _beg$[ebp]
	mov	ecx, DWORD PTR _tp$[ebp]
	movsx	edx, WORD PTR [ecx+eax*2]
	and	edx, DWORD PTR _mask$[ebp]
	mov	WORD PTR _b$[ebp], dx

; 409  : 				rc = 1;

	mov	DWORD PTR _rc$[ebp], 1
$L66191:

; 410  : 				while (rc < 127+2 && beg+rc < npixels &&
; 411  : 						(tp[beg+rc] & mask) == b)

	cmp	DWORD PTR _rc$[ebp], 129		; 00000081H
	jge	SHORT $L66192
	mov	eax, DWORD PTR _beg$[ebp]
	add	eax, DWORD PTR _rc$[ebp]
	cmp	eax, DWORD PTR _npixels$[ebp]
	jge	SHORT $L66192
	mov	ecx, DWORD PTR _beg$[ebp]
	add	ecx, DWORD PTR _rc$[ebp]
	mov	edx, DWORD PTR _tp$[ebp]
	movsx	eax, WORD PTR [edx+ecx*2]
	and	eax, DWORD PTR _mask$[ebp]
	movsx	ecx, WORD PTR _b$[ebp]
	cmp	eax, ecx
	jne	SHORT $L66192

; 412  : 					rc++;

	mov	edx, DWORD PTR _rc$[ebp]
	add	edx, 1
	mov	DWORD PTR _rc$[ebp], edx
	jmp	SHORT $L66191
$L66192:

; 413  : 				if (rc >= MINRUN)

	cmp	DWORD PTR _rc$[ebp], 4
	jl	SHORT $L66193

; 414  : 					break;		/* long enough */

	jmp	SHORT $L66189
$L66193:

; 415  : 			}

	jmp	SHORT $L66188
$L66189:

; 416  : 			if (beg-i > 1 && beg-i < MINRUN) {

	mov	eax, DWORD PTR _beg$[ebp]
	sub	eax, DWORD PTR _i$[ebp]
	cmp	eax, 1
	jle	$L66197
	mov	ecx, DWORD PTR _beg$[ebp]
	sub	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, 4
	jge	$L66197

; 417  : 				b = tp[i] & mask;	/* check short run */

	mov	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _tp$[ebp]
	movsx	ecx, WORD PTR [eax+edx*2]
	and	ecx, DWORD PTR _mask$[ebp]
	mov	WORD PTR _b$[ebp], cx

; 418  : 				j = i+1;

	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	mov	DWORD PTR _j$[ebp], edx
$L66196:

; 419  : 				while ((tp[j++] & mask) == b)

	mov	eax, DWORD PTR _j$[ebp]
	mov	ecx, DWORD PTR _tp$[ebp]
	movsx	edx, WORD PTR [ecx+eax*2]
	and	edx, DWORD PTR _mask$[ebp]
	movsx	eax, WORD PTR _b$[ebp]
	mov	ecx, DWORD PTR _j$[ebp]
	add	ecx, 1
	mov	DWORD PTR _j$[ebp], ecx
	cmp	edx, eax
	jne	SHORT $L66197

; 420  : 					if (j == beg) {

	mov	edx, DWORD PTR _j$[ebp]
	cmp	edx, DWORD PTR _beg$[ebp]
	jne	SHORT $L66198

; 421  : 						*op++ = 128-2+j-i;

	mov	eax, DWORD PTR _j$[ebp]
	add	eax, 126				; 0000007eH
	sub	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [ecx], al
	mov	edx, DWORD PTR _op$[ebp]
	add	edx, 1
	mov	DWORD PTR _op$[ebp], edx

; 422  : 						*op++ = b >> shft;

	movsx	eax, WORD PTR _b$[ebp]
	mov	ecx, DWORD PTR _shft$[ebp]
	sar	eax, cl
	mov	ecx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [ecx], al
	mov	edx, DWORD PTR _op$[ebp]
	add	edx, 1
	mov	DWORD PTR _op$[ebp], edx

; 423  : 						occ -= 2;

	mov	eax, DWORD PTR _occ$[ebp]
	sub	eax, 2
	mov	DWORD PTR _occ$[ebp], eax

; 424  : 						i = beg;

	mov	ecx, DWORD PTR _beg$[ebp]
	mov	DWORD PTR _i$[ebp], ecx

; 425  : 						break;

	jmp	SHORT $L66197
$L66198:

; 427  : 			}

	jmp	SHORT $L66196
$L66197:

; 428  : 			while (i < beg) {		/* write out non-run */

	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR _beg$[ebp]
	jge	$L66201

; 429  : 				if ((j = beg-i) > 127) j = 127;

	mov	eax, DWORD PTR _beg$[ebp]
	sub	eax, DWORD PTR _i$[ebp]
	mov	DWORD PTR _j$[ebp], eax
	cmp	DWORD PTR _j$[ebp], 127			; 0000007fH
	jle	SHORT $L66202
	mov	DWORD PTR _j$[ebp], 127			; 0000007fH
$L66202:

; 430  : 				if (occ < j+3) {

	mov	ecx, DWORD PTR _j$[ebp]
	add	ecx, 3
	cmp	DWORD PTR _occ$[ebp], ecx
	jge	SHORT $L66203

; 431  : 					tif->tif_rawcp = op;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _op$[ebp]
	mov	DWORD PTR [edx+480], eax

; 432  : 					tif->tif_rawcc = tif->tif_rawdatasize - occ;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+476]
	sub	edx, DWORD PTR _occ$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+484], edx

; 433  : 					if (!TIFFFlushData1(tif))

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFlushData1
	add	esp, 4
	test	eax, eax
	jne	SHORT $L66204

; 434  : 						return (-1);

	or	eax, -1
	jmp	$L66151
$L66204:

; 435  : 					op = tif->tif_rawcp;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+480]
	mov	DWORD PTR _op$[ebp], eax

; 436  : 					occ = tif->tif_rawdatasize - tif->tif_rawcc;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [ecx+476]
	sub	eax, DWORD PTR [edx+484]
	mov	DWORD PTR _occ$[ebp], eax
$L66203:

; 438  : 				*op++ = j; occ--;

	mov	ecx, DWORD PTR _op$[ebp]
	mov	dl, BYTE PTR _j$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 1
	mov	DWORD PTR _op$[ebp], eax
	mov	ecx, DWORD PTR _occ$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _occ$[ebp], ecx
$L66206:

; 439  : 				while (j--) {

	mov	edx, DWORD PTR _j$[ebp]
	mov	eax, DWORD PTR _j$[ebp]
	sub	eax, 1
	mov	DWORD PTR _j$[ebp], eax
	test	edx, edx
	je	SHORT $L66207

; 440  : 					*op++ = tp[i++] >> shft & 0xff;

	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _tp$[ebp]
	movsx	eax, WORD PTR [edx+ecx*2]
	mov	ecx, DWORD PTR _shft$[ebp]
	sar	eax, cl
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [ecx], al
	mov	edx, DWORD PTR _op$[ebp]
	add	edx, 1
	mov	DWORD PTR _op$[ebp], edx
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax

; 441  : 					occ--;

	mov	ecx, DWORD PTR _occ$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _occ$[ebp], ecx

; 442  : 				}

	jmp	SHORT $L66206
$L66207:

; 443  : 			}

	jmp	$L66197
$L66201:

; 444  : 			if (rc >= MINRUN) {		/* write out run */

	cmp	DWORD PTR _rc$[ebp], 4
	jl	SHORT $L66208

; 445  : 				*op++ = 128-2+rc;

	mov	edx, DWORD PTR _rc$[ebp]
	add	edx, 126				; 0000007eH
	mov	eax, DWORD PTR _op$[ebp]
	mov	BYTE PTR [eax], dl
	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, 1
	mov	DWORD PTR _op$[ebp], ecx

; 446  : 				*op++ = tp[beg] >> shft & 0xff;

	mov	edx, DWORD PTR _beg$[ebp]
	mov	eax, DWORD PTR _tp$[ebp]
	movsx	edx, WORD PTR [eax+edx*2]
	mov	ecx, DWORD PTR _shft$[ebp]
	sar	edx, cl
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _op$[ebp]
	mov	BYTE PTR [eax], dl
	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, 1
	mov	DWORD PTR _op$[ebp], ecx

; 447  : 				occ -= 2;

	mov	edx, DWORD PTR _occ$[ebp]
	sub	edx, 2
	mov	DWORD PTR _occ$[ebp], edx

; 448  : 			} else

	jmp	SHORT $L66209
$L66208:

; 449  : 				rc = 0;

	mov	DWORD PTR _rc$[ebp], 0
$L66209:

; 450  : 		}

	jmp	$L66183
$L66184:
	jmp	$L66180
$L66181:

; 451  : 	tif->tif_rawcp = op;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _op$[ebp]
	mov	DWORD PTR [eax+480], ecx

; 452  : 	tif->tif_rawcc = tif->tif_rawdatasize - occ;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+476]
	sub	eax, DWORD PTR _occ$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+484], eax

; 453  : 
; 454  : 	return (0);

	xor	eax, eax
$L66151:

; 455  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogL16Encode ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+1
$SG66228 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66229 DB	's == 0', 00H
	ORG $+1
$SG66232 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66233 DB	'sp != NULL', 00H
	ORG $+1
$SG66239 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66240 DB	'sp->tbuflen >= npixels', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_bp$ = 12
_cc$ = 16
_s$ = 20
_sp$ = -8
_i$ = -20
_npixels$ = -24
_occ$ = -16
_op$ = -4
_tp$ = -12
_LogLuvEncode24 PROC NEAR

; 462  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 24					; 00000018H

; 463  : 	LogLuvState* sp = EncoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 464  : 	int i, npixels, occ;
; 465  : 	tidata_t op;
; 466  : 	uint32* tp;
; 467  : 
; 468  : 	assert(s == 0);

	mov	edx, DWORD PTR _s$[ebp]
	and	edx, 65535				; 0000ffffH
	test	edx, edx
	je	SHORT $L67485
	push	468					; 000001d4H
	push	OFFSET FLAT:$SG66228
	push	OFFSET FLAT:$SG66229
	call	__assert
	add	esp, 12					; 0000000cH
$L67485:

; 469  : 	assert(sp != NULL);

	cmp	DWORD PTR _sp$[ebp], 0
	jne	SHORT $L67486
	push	469					; 000001d5H
	push	OFFSET FLAT:$SG66232
	push	OFFSET FLAT:$SG66233
	call	__assert
	add	esp, 12					; 0000000cH
$L67486:

; 470  : 	npixels = cc / sp->pixel_size;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _cc$[ebp]
	cdq
	idiv	DWORD PTR [ecx+8]
	mov	DWORD PTR _npixels$[ebp], eax

; 471  : 
; 472  : 	if (sp->user_datafmt == SGILOGDATAFMT_RAW)

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx], 2
	jne	SHORT $L66234

; 473  : 		tp = (uint32*) bp;

	mov	eax, DWORD PTR _bp$[ebp]
	mov	DWORD PTR _tp$[ebp], eax

; 474  : 	else {

	jmp	SHORT $L66236
$L66234:

; 475  : 		tp = (uint32*) sp->tbuf;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR _tp$[ebp], edx

; 476  : 		assert(sp->tbuflen >= npixels);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	cmp	ecx, DWORD PTR _npixels$[ebp]
	jge	SHORT $L67487
	push	476					; 000001dcH
	push	OFFSET FLAT:$SG66239
	push	OFFSET FLAT:$SG66240
	call	__assert
	add	esp, 12					; 0000000cH
$L67487:

; 477  : 		(*sp->tfunc)(sp, bp, npixels);

	mov	eax, DWORD PTR _npixels$[ebp]
	push	eax
	mov	ecx, DWORD PTR _bp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _sp$[ebp]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	call	DWORD PTR [eax+20]
	add	esp, 12					; 0000000cH
$L66236:

; 479  : 					/* write out encoded pixels */
; 480  : 	op = tif->tif_rawcp;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+480]
	mov	DWORD PTR _op$[ebp], edx

; 481  : 	occ = tif->tif_rawdatasize - tif->tif_rawcc;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [eax+476]
	sub	edx, DWORD PTR [ecx+484]
	mov	DWORD PTR _occ$[ebp], edx

; 482  : 	for (i = npixels; i--; ) {

	mov	eax, DWORD PTR _npixels$[ebp]
	mov	DWORD PTR _i$[ebp], eax
$L66242:
	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _i$[ebp]
	sub	edx, 1
	mov	DWORD PTR _i$[ebp], edx
	test	ecx, ecx
	je	$L66243

; 483  : 		if (occ < 3) {

	cmp	DWORD PTR _occ$[ebp], 3
	jge	SHORT $L66244

; 484  : 			tif->tif_rawcp = op;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _op$[ebp]
	mov	DWORD PTR [eax+480], ecx

; 485  : 			tif->tif_rawcc = tif->tif_rawdatasize - occ;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+476]
	sub	eax, DWORD PTR _occ$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+484], eax

; 486  : 			if (!TIFFFlushData1(tif))

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFlushData1
	add	esp, 4
	test	eax, eax
	jne	SHORT $L66245

; 487  : 				return (-1);

	or	eax, -1
	jmp	$L66219
$L66245:

; 488  : 			op = tif->tif_rawcp;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	DWORD PTR _op$[ebp], ecx

; 489  : 			occ = tif->tif_rawdatasize - tif->tif_rawcc;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [edx+476]
	sub	ecx, DWORD PTR [eax+484]
	mov	DWORD PTR _occ$[ebp], ecx
$L66244:

; 491  : 		*op++ = (tidataval_t)(*tp >> 16);

	mov	edx, DWORD PTR _tp$[ebp]
	mov	eax, DWORD PTR [edx]
	shr	eax, 16					; 00000010H
	mov	ecx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [ecx], al
	mov	edx, DWORD PTR _op$[ebp]
	add	edx, 1
	mov	DWORD PTR _op$[ebp], edx

; 492  : 		*op++ = (tidataval_t)(*tp >> 8 & 0xff);

	mov	eax, DWORD PTR _tp$[ebp]
	mov	ecx, DWORD PTR [eax]
	shr	ecx, 8
	and	ecx, 255				; 000000ffH
	mov	edx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [edx], cl
	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 1
	mov	DWORD PTR _op$[ebp], eax

; 493  : 		*op++ = (tidataval_t)(*tp++ & 0xff);

	mov	ecx, DWORD PTR _tp$[ebp]
	mov	edx, DWORD PTR [ecx]
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _op$[ebp]
	mov	BYTE PTR [eax], dl
	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, 1
	mov	DWORD PTR _op$[ebp], ecx
	mov	edx, DWORD PTR _tp$[ebp]
	add	edx, 4
	mov	DWORD PTR _tp$[ebp], edx

; 494  : 		occ -= 3;

	mov	eax, DWORD PTR _occ$[ebp]
	sub	eax, 3
	mov	DWORD PTR _occ$[ebp], eax

; 495  : 	}

	jmp	$L66242
$L66243:

; 496  : 	tif->tif_rawcp = op;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR [ecx+480], edx

; 497  : 	tif->tif_rawcc = tif->tif_rawdatasize - occ;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+476]
	sub	ecx, DWORD PTR _occ$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], ecx

; 498  : 
; 499  : 	return (0);

	xor	eax, eax
$L66219:

; 500  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogLuvEncode24 ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+1
$SG66273 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66274 DB	's == 0', 00H
	ORG $+1
$SG66277 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66278 DB	'sp != NULL', 00H
	ORG $+1
$SG66284 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_luv.c', 00H
$SG66285 DB	'sp->tbuflen >= npixels', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_bp$ = 12
_cc$ = 16
_s$ = 20
_sp$ = -20
_shft$ = -48
_i$ = -32
_j$ = -36
_npixels$ = -44
_op$ = -16
_tp$ = -24
_b$ = -12
_occ$ = -28
_rc$ = -8
_mask$ = -40
_beg$ = -4
_LogLuvEncode32 PROC NEAR

; 507  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 48					; 00000030H

; 508  : 	LogLuvState* sp = EncoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 509  : 	int shft, i, j, npixels;
; 510  : 	tidata_t op;
; 511  : 	uint32* tp;
; 512  : 	uint32 b;
; 513  : 	int occ, rc=0, mask, beg;

	mov	DWORD PTR _rc$[ebp], 0

; 514  : 
; 515  : 	assert(s == 0);

	mov	edx, DWORD PTR _s$[ebp]
	and	edx, 65535				; 0000ffffH
	test	edx, edx
	je	SHORT $L67489
	push	515					; 00000203H
	push	OFFSET FLAT:$SG66273
	push	OFFSET FLAT:$SG66274
	call	__assert
	add	esp, 12					; 0000000cH
$L67489:

; 516  : 	assert(sp != NULL);

	cmp	DWORD PTR _sp$[ebp], 0
	jne	SHORT $L67490
	push	516					; 00000204H
	push	OFFSET FLAT:$SG66277
	push	OFFSET FLAT:$SG66278
	call	__assert
	add	esp, 12					; 0000000cH
$L67490:

; 517  : 
; 518  : 	npixels = cc / sp->pixel_size;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _cc$[ebp]
	cdq
	idiv	DWORD PTR [ecx+8]
	mov	DWORD PTR _npixels$[ebp], eax

; 519  : 
; 520  : 	if (sp->user_datafmt == SGILOGDATAFMT_RAW)

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx], 2
	jne	SHORT $L66279

; 521  : 		tp = (uint32*) bp;

	mov	eax, DWORD PTR _bp$[ebp]
	mov	DWORD PTR _tp$[ebp], eax

; 522  : 	else {

	jmp	SHORT $L66281
$L66279:

; 523  : 		tp = (uint32*) sp->tbuf;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR _tp$[ebp], edx

; 524  : 		assert(sp->tbuflen >= npixels);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	cmp	ecx, DWORD PTR _npixels$[ebp]
	jge	SHORT $L67491
	push	524					; 0000020cH
	push	OFFSET FLAT:$SG66284
	push	OFFSET FLAT:$SG66285
	call	__assert
	add	esp, 12					; 0000000cH
$L67491:

; 525  : 		(*sp->tfunc)(sp, bp, npixels);

	mov	eax, DWORD PTR _npixels$[ebp]
	push	eax
	mov	ecx, DWORD PTR _bp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _sp$[ebp]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	call	DWORD PTR [eax+20]
	add	esp, 12					; 0000000cH
$L66281:

; 527  : 					/* compress each byte string */
; 528  : 	op = tif->tif_rawcp;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+480]
	mov	DWORD PTR _op$[ebp], edx

; 529  : 	occ = tif->tif_rawdatasize - tif->tif_rawcc;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [eax+476]
	sub	edx, DWORD PTR [ecx+484]
	mov	DWORD PTR _occ$[ebp], edx

; 530  : 	for (shft = 4*8; (shft -= 8) >= 0; )

	mov	DWORD PTR _shft$[ebp], 32		; 00000020H
$L66287:
	mov	eax, DWORD PTR _shft$[ebp]
	sub	eax, 8
	mov	DWORD PTR _shft$[ebp], eax
	cmp	DWORD PTR _shft$[ebp], 0
	jl	$L66288

; 531  : 		for (i = 0; i < npixels; i += rc) {

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L66289
$L66290:
	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, DWORD PTR _rc$[ebp]
	mov	DWORD PTR _i$[ebp], ecx
$L66289:
	mov	edx, DWORD PTR _i$[ebp]
	cmp	edx, DWORD PTR _npixels$[ebp]
	jge	$L66291

; 532  : 			if (occ < 4) {

	cmp	DWORD PTR _occ$[ebp], 4
	jge	SHORT $L66292

; 533  : 				tif->tif_rawcp = op;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _op$[ebp]
	mov	DWORD PTR [eax+480], ecx

; 534  : 				tif->tif_rawcc = tif->tif_rawdatasize - occ;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+476]
	sub	eax, DWORD PTR _occ$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+484], eax

; 535  : 				if (!TIFFFlushData1(tif))

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFlushData1
	add	esp, 4
	test	eax, eax
	jne	SHORT $L66293

; 536  : 					return (-1);

	or	eax, -1
	jmp	$L66258
$L66293:

; 537  : 				op = tif->tif_rawcp;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	DWORD PTR _op$[ebp], ecx

; 538  : 				occ = tif->tif_rawdatasize - tif->tif_rawcc;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [edx+476]
	sub	ecx, DWORD PTR [eax+484]
	mov	DWORD PTR _occ$[ebp], ecx
$L66292:

; 540  : 			mask = 0xff << shft;		/* find next run */

	mov	edx, 255				; 000000ffH
	mov	ecx, DWORD PTR _shft$[ebp]
	shl	edx, cl
	mov	DWORD PTR _mask$[ebp], edx

; 541  : 			for (beg = i; beg < npixels; beg += rc) {

	mov	eax, DWORD PTR _i$[ebp]
	mov	DWORD PTR _beg$[ebp], eax
	jmp	SHORT $L66294
$L66295:
	mov	ecx, DWORD PTR _beg$[ebp]
	add	ecx, DWORD PTR _rc$[ebp]
	mov	DWORD PTR _beg$[ebp], ecx
$L66294:
	mov	edx, DWORD PTR _beg$[ebp]
	cmp	edx, DWORD PTR _npixels$[ebp]
	jge	SHORT $L66296

; 542  : 				b = tp[beg] & mask;

	mov	eax, DWORD PTR _beg$[ebp]
	mov	ecx, DWORD PTR _tp$[ebp]
	mov	edx, DWORD PTR [ecx+eax*4]
	and	edx, DWORD PTR _mask$[ebp]
	mov	DWORD PTR _b$[ebp], edx

; 543  : 				rc = 1;

	mov	DWORD PTR _rc$[ebp], 1
$L66298:

; 544  : 				while (rc < 127+2 && beg+rc < npixels &&
; 545  : 						(tp[beg+rc] & mask) == b)

	cmp	DWORD PTR _rc$[ebp], 129		; 00000081H
	jge	SHORT $L66299
	mov	eax, DWORD PTR _beg$[ebp]
	add	eax, DWORD PTR _rc$[ebp]
	cmp	eax, DWORD PTR _npixels$[ebp]
	jge	SHORT $L66299
	mov	ecx, DWORD PTR _beg$[ebp]
	add	ecx, DWORD PTR _rc$[ebp]
	mov	edx, DWORD PTR _tp$[ebp]
	mov	eax, DWORD PTR [edx+ecx*4]
	and	eax, DWORD PTR _mask$[ebp]
	cmp	eax, DWORD PTR _b$[ebp]
	jne	SHORT $L66299

; 546  : 					rc++;

	mov	ecx, DWORD PTR _rc$[ebp]
	add	ecx, 1
	mov	DWORD PTR _rc$[ebp], ecx
	jmp	SHORT $L66298
$L66299:

; 547  : 				if (rc >= MINRUN)

	cmp	DWORD PTR _rc$[ebp], 4
	jl	SHORT $L66300

; 548  : 					break;		/* long enough */

	jmp	SHORT $L66296
$L66300:

; 549  : 			}

	jmp	SHORT $L66295
$L66296:

; 550  : 			if (beg-i > 1 && beg-i < MINRUN) {

	mov	edx, DWORD PTR _beg$[ebp]
	sub	edx, DWORD PTR _i$[ebp]
	cmp	edx, 1
	jle	$L66304
	mov	eax, DWORD PTR _beg$[ebp]
	sub	eax, DWORD PTR _i$[ebp]
	cmp	eax, 4
	jge	SHORT $L66304

; 551  : 				b = tp[i] & mask;	/* check short run */

	mov	ecx, DWORD PTR _i$[ebp]
	mov	edx, DWORD PTR _tp$[ebp]
	mov	eax, DWORD PTR [edx+ecx*4]
	and	eax, DWORD PTR _mask$[ebp]
	mov	DWORD PTR _b$[ebp], eax

; 552  : 				j = i+1;

	mov	ecx, DWORD PTR _i$[ebp]
	add	ecx, 1
	mov	DWORD PTR _j$[ebp], ecx
$L66303:

; 553  : 				while ((tp[j++] & mask) == b)

	mov	edx, DWORD PTR _j$[ebp]
	mov	eax, DWORD PTR _tp$[ebp]
	mov	ecx, DWORD PTR [eax+edx*4]
	and	ecx, DWORD PTR _mask$[ebp]
	mov	edx, DWORD PTR _b$[ebp]
	mov	eax, DWORD PTR _j$[ebp]
	add	eax, 1
	mov	DWORD PTR _j$[ebp], eax
	cmp	ecx, edx
	jne	SHORT $L66304

; 554  : 					if (j == beg) {

	mov	ecx, DWORD PTR _j$[ebp]
	cmp	ecx, DWORD PTR _beg$[ebp]
	jne	SHORT $L66305

; 555  : 						*op++ = (tidataval_t)(128-2+j-i);

	mov	edx, DWORD PTR _j$[ebp]
	add	edx, 126				; 0000007eH
	sub	edx, DWORD PTR _i$[ebp]
	mov	eax, DWORD PTR _op$[ebp]
	mov	BYTE PTR [eax], dl
	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, 1
	mov	DWORD PTR _op$[ebp], ecx

; 556  : 						*op++ = (tidataval_t)(b >> shft);

	mov	edx, DWORD PTR _b$[ebp]
	mov	ecx, DWORD PTR _shft$[ebp]
	shr	edx, cl
	mov	eax, DWORD PTR _op$[ebp]
	mov	BYTE PTR [eax], dl
	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, 1
	mov	DWORD PTR _op$[ebp], ecx

; 557  : 						occ -= 2;

	mov	edx, DWORD PTR _occ$[ebp]
	sub	edx, 2
	mov	DWORD PTR _occ$[ebp], edx

; 558  : 						i = beg;

	mov	eax, DWORD PTR _beg$[ebp]
	mov	DWORD PTR _i$[ebp], eax

; 559  : 						break;

	jmp	SHORT $L66304
$L66305:

; 561  : 			}

	jmp	SHORT $L66303
$L66304:

; 562  : 			while (i < beg) {		/* write out non-run */

	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _beg$[ebp]
	jge	$L66310

; 563  : 				if ((j = beg-i) > 127) j = 127;

	mov	edx, DWORD PTR _beg$[ebp]
	sub	edx, DWORD PTR _i$[ebp]
	mov	DWORD PTR _j$[ebp], edx
	cmp	DWORD PTR _j$[ebp], 127			; 0000007fH
	jle	SHORT $L66311
	mov	DWORD PTR _j$[ebp], 127			; 0000007fH
$L66311:

; 564  : 				if (occ < j+3) {

	mov	eax, DWORD PTR _j$[ebp]
	add	eax, 3
	cmp	DWORD PTR _occ$[ebp], eax
	jge	SHORT $L66312

; 565  : 					tif->tif_rawcp = op;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR [ecx+480], edx

; 566  : 					tif->tif_rawcc = tif->tif_rawdatasize - occ;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+476]
	sub	ecx, DWORD PTR _occ$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], ecx

; 567  : 					if (!TIFFFlushData1(tif))

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFlushData1
	add	esp, 4
	test	eax, eax
	jne	SHORT $L66313

; 568  : 						return (-1);

	or	eax, -1
	jmp	$L66258
$L66313:

; 569  : 					op = tif->tif_rawcp;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+480]
	mov	DWORD PTR _op$[ebp], edx

; 570  : 					occ = tif->tif_rawdatasize - tif->tif_rawcc;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [eax+476]
	sub	edx, DWORD PTR [ecx+484]
	mov	DWORD PTR _occ$[ebp], edx
$L66312:

; 572  : 				*op++ = j; occ--;

	mov	eax, DWORD PTR _op$[ebp]
	mov	cl, BYTE PTR _j$[ebp]
	mov	BYTE PTR [eax], cl
	mov	edx, DWORD PTR _op$[ebp]
	add	edx, 1
	mov	DWORD PTR _op$[ebp], edx
	mov	eax, DWORD PTR _occ$[ebp]
	sub	eax, 1
	mov	DWORD PTR _occ$[ebp], eax
$L66315:

; 573  : 				while (j--) {

	mov	ecx, DWORD PTR _j$[ebp]
	mov	edx, DWORD PTR _j$[ebp]
	sub	edx, 1
	mov	DWORD PTR _j$[ebp], edx
	test	ecx, ecx
	je	SHORT $L66316

; 574  : 					*op++ = (tidataval_t)(tp[i++] >> shft & 0xff);

	mov	eax, DWORD PTR _i$[ebp]
	mov	ecx, DWORD PTR _tp$[ebp]
	mov	edx, DWORD PTR [ecx+eax*4]
	mov	ecx, DWORD PTR _shft$[ebp]
	shr	edx, cl
	and	edx, 255				; 000000ffH
	mov	eax, DWORD PTR _op$[ebp]
	mov	BYTE PTR [eax], dl
	mov	ecx, DWORD PTR _op$[ebp]
	add	ecx, 1
	mov	DWORD PTR _op$[ebp], ecx
	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	mov	DWORD PTR _i$[ebp], edx

; 575  : 					occ--;

	mov	eax, DWORD PTR _occ$[ebp]
	sub	eax, 1
	mov	DWORD PTR _occ$[ebp], eax

; 576  : 				}

	jmp	SHORT $L66315
$L66316:

; 577  : 			}

	jmp	$L66304
$L66310:

; 578  : 			if (rc >= MINRUN) {		/* write out run */

	cmp	DWORD PTR _rc$[ebp], 4
	jl	SHORT $L66318

; 579  : 				*op++ = 128-2+rc;

	mov	ecx, DWORD PTR _rc$[ebp]
	add	ecx, 126				; 0000007eH
	mov	edx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [edx], cl
	mov	eax, DWORD PTR _op$[ebp]
	add	eax, 1
	mov	DWORD PTR _op$[ebp], eax

; 580  : 				*op++ = (tidataval_t)(tp[beg] >> shft & 0xff);

	mov	ecx, DWORD PTR _beg$[ebp]
	mov	edx, DWORD PTR _tp$[ebp]
	mov	eax, DWORD PTR [edx+ecx*4]
	mov	ecx, DWORD PTR _shft$[ebp]
	shr	eax, cl
	and	eax, 255				; 000000ffH
	mov	ecx, DWORD PTR _op$[ebp]
	mov	BYTE PTR [ecx], al
	mov	edx, DWORD PTR _op$[ebp]
	add	edx, 1
	mov	DWORD PTR _op$[ebp], edx

; 581  : 				occ -= 2;

	mov	eax, DWORD PTR _occ$[ebp]
	sub	eax, 2
	mov	DWORD PTR _occ$[ebp], eax

; 582  : 			} else

	jmp	SHORT $L66320
$L66318:

; 583  : 				rc = 0;

	mov	DWORD PTR _rc$[ebp], 0
$L66320:

; 584  : 		}

	jmp	$L66290
$L66291:
	jmp	$L66287
$L66288:

; 585  : 	tif->tif_rawcp = op;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR [ecx+480], edx

; 586  : 	tif->tif_rawcc = tif->tif_rawdatasize - occ;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+476]
	sub	ecx, DWORD PTR _occ$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], ecx

; 587  : 
; 588  : 	return (0);

	xor	eax, eax
$L66258:

; 589  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogLuvEncode32 ENDP
_sp$ = 8
_op$ = 12
_n$ = 16
_l16$ = -4
_yp$ = -8
_L16fromY PROC NEAR

; 702  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 703  : 	int16* l16 = (int16*) sp->tbuf;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _l16$[ebp], ecx

; 704  : 	float* yp = (float*) op;

	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR _yp$[ebp], edx
$L66598:

; 705  : 
; 706  : 	while (n-- > 0)

	mov	eax, DWORD PTR _n$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	test	eax, eax
	jle	SHORT $L66599

; 707  : 		*l16++ = LogL16fromY(*yp++, sp->encode_meth);

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+4]
	push	eax
	mov	ecx, DWORD PTR _yp$[ebp]
	fld	DWORD PTR [ecx]
	fstp	QWORD PTR -16+[ebp]
	mov	edx, DWORD PTR -16+[ebp+4]
	push	edx
	mov	eax, DWORD PTR -16+[ebp]
	push	eax
	mov	ecx, DWORD PTR _yp$[ebp]
	add	ecx, 4
	mov	DWORD PTR _yp$[ebp], ecx
	call	_LogL16fromY
	add	esp, 12					; 0000000cH
	mov	edx, DWORD PTR _l16$[ebp]
	mov	WORD PTR [edx], ax
	mov	eax, DWORD PTR _l16$[ebp]
	add	eax, 2
	mov	DWORD PTR _l16$[ebp], eax
	jmp	SHORT $L66598
$L66599:

; 708  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_L16fromY ENDP
_sp$ = 8
_op$ = 12
_n$ = 16
_luv$ = -8
_xyz$ = -4
_Luv24fromXYZ PROC NEAR

; 968  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 969  : 	uint32* luv = (uint32*) sp->tbuf;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _luv$[ebp], ecx

; 970  : 	float* xyz = (float*) op;

	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR _xyz$[ebp], edx
$L66824:

; 971  : 
; 972  : 	while (n-- > 0) {

	mov	eax, DWORD PTR _n$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	test	eax, eax
	jle	SHORT $L66825

; 973  : 		*luv++ = LogLuv24fromXYZ(xyz, sp->encode_meth);

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+4]
	push	eax
	mov	ecx, DWORD PTR _xyz$[ebp]
	push	ecx
	call	_LogLuv24fromXYZ
	add	esp, 8
	mov	edx, DWORD PTR _luv$[ebp]
	mov	DWORD PTR [edx], eax
	mov	eax, DWORD PTR _luv$[ebp]
	add	eax, 4
	mov	DWORD PTR _luv$[ebp], eax

; 974  : 		xyz += 3;

	mov	ecx, DWORD PTR _xyz$[ebp]
	add	ecx, 12					; 0000000cH
	mov	DWORD PTR _xyz$[ebp], ecx

; 975  : 	}

	jmp	SHORT $L66824
$L66825:

; 976  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Luv24fromXYZ ENDP
_TEXT	ENDS
PUBLIC	__real@8@400acf20000000000000
PUBLIC	__real@8@3ffd8000000000000000
;	COMDAT __real@8@400acf20000000000000
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_luv.c
CONST	SEGMENT
__real@8@400acf20000000000000 DQ 040a9e40000000000r ; 3314
CONST	ENDS
;	COMDAT __real@8@3ffd8000000000000000
CONST	SEGMENT
__real@8@3ffd8000000000000000 DQ 03fd0000000000000r ; 0.25
CONST	ENDS
_TEXT	SEGMENT
_sp$ = 8
_op$ = 12
_n$ = 16
_luv$ = -4
_luv3$ = -8
_Le$66841 = -16
_Ce$66842 = -12
_Luv24fromLuv48 PROC NEAR

; 980  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 56					; 00000038H

; 981  : 	uint32* luv = (uint32*) sp->tbuf;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _luv$[ebp], ecx

; 982  : 	int16* luv3 = (int16*) op;

	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR _luv3$[ebp], edx
$L66839:

; 983  : 
; 984  : 	while (n-- > 0) {

	mov	eax, DWORD PTR _n$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	test	eax, eax
	jle	$L66840

; 985  : 		int Le, Ce;
; 986  : 
; 987  : 		if (luv3[0] <= 0)

	mov	edx, DWORD PTR _luv3$[ebp]
	movsx	eax, WORD PTR [edx]
	test	eax, eax
	jg	SHORT $L66843

; 988  : 			Le = 0;

	mov	DWORD PTR _Le$66841[ebp], 0

; 989  : 		else if (luv3[0] >= (1<<12)+3314)

	jmp	$L66848
$L66843:
	mov	ecx, DWORD PTR _luv3$[ebp]
	movsx	edx, WORD PTR [ecx]
	cmp	edx, 7410				; 00001cf2H
	jl	SHORT $L66845

; 990  : 			Le = (1<<10) - 1;

	mov	DWORD PTR _Le$66841[ebp], 1023		; 000003ffH

; 991  : 		else if (sp->encode_meth == SGILOGENCODE_NODITHER)

	jmp	$L66848
$L66845:
	mov	eax, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [eax+4], 0
	jne	SHORT $L66847

; 992  : 			Le = (luv3[0]-3314) >> 2;

	mov	ecx, DWORD PTR _luv3$[ebp]
	movsx	edx, WORD PTR [ecx]
	sub	edx, 3314				; 00000cf2H
	sar	edx, 2
	mov	DWORD PTR _Le$66841[ebp], edx

; 993  : 		else

	jmp	SHORT $L66848
$L66847:

; 994  : 			Le = itrunc(.25*(luv3[0]-3314.), sp->encode_meth);

	mov	eax, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [eax+4], 0
	jne	SHORT $L67495
	mov	ecx, DWORD PTR _luv3$[ebp]
	movsx	edx, WORD PTR [ecx]
	mov	DWORD PTR -20+[ebp], edx
	fild	DWORD PTR -20+[ebp]
	fsub	QWORD PTR __real@8@400acf20000000000000
	fmul	QWORD PTR __real@8@3ffd8000000000000000
	call	__ftol
	mov	DWORD PTR -24+[ebp], eax
	jmp	SHORT $L67496
$L67495:
	mov	eax, DWORD PTR _luv3$[ebp]
	movsx	ecx, WORD PTR [eax]
	mov	DWORD PTR -28+[ebp], ecx
	fild	DWORD PTR -28+[ebp]
	fsub	QWORD PTR __real@8@400acf20000000000000
	fmul	QWORD PTR __real@8@3ffd8000000000000000
	fstp	QWORD PTR -36+[ebp]
	call	_rand
	mov	DWORD PTR -40+[ebp], eax
	fild	DWORD PTR -40+[ebp]
	fmul	QWORD PTR __real@8@3ff08001000200040000
	fadd	QWORD PTR -36+[ebp]
	fsub	QWORD PTR __real@8@3ffe8000000000000000
	call	__ftol
	mov	DWORD PTR -24+[ebp], eax
$L67496:
	mov	edx, DWORD PTR -24+[ebp]
	mov	DWORD PTR _Le$66841[ebp], edx
$L66848:

; 995  : 
; 996  : 		Ce = uv_encode((luv[1]+.5)/(1<<15), (luv[2]+.5)/(1<<15),
; 997  : 					sp->encode_meth);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR _luv$[ebp]
	mov	eax, DWORD PTR [edx+8]
	mov	DWORD PTR -48+[ebp], eax
	mov	DWORD PTR -48+[ebp+4], 0
	fild	QWORD PTR -48+[ebp]
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	fdiv	QWORD PTR __real@8@400e8000000000000000
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	ecx, DWORD PTR _luv$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR -56+[ebp], edx
	mov	DWORD PTR -56+[ebp+4], 0
	fild	QWORD PTR -56+[ebp]
	fadd	QWORD PTR __real@8@3ffe8000000000000000
	fdiv	QWORD PTR __real@8@400e8000000000000000
	sub	esp, 8
	fstp	QWORD PTR [esp]
	call	_uv_encode
	add	esp, 20					; 00000014H
	mov	DWORD PTR _Ce$66842[ebp], eax

; 998  : 		if (Ce < 0)	/* never happens */

	cmp	DWORD PTR _Ce$66842[ebp], 0
	jge	SHORT $L66851

; 999  : 			Ce = uv_encode(U_NEU, V_NEU, SGILOGENCODE_NODITHER);

	push	0
	push	1071534295				; 3fde50d7H
	push	-1799874146				; 94b8199eH
	push	1070264966				; 3fcaf286H
	push	-1122669542				; bd156c1aH
	call	_uv_encode
	add	esp, 20					; 00000014H
	mov	DWORD PTR _Ce$66842[ebp], eax
$L66851:

; 1000 : 		*luv++ = (uint32)Le << 14 | Ce;

	mov	eax, DWORD PTR _Le$66841[ebp]
	shl	eax, 14					; 0000000eH
	or	eax, DWORD PTR _Ce$66842[ebp]
	mov	ecx, DWORD PTR _luv$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _luv$[ebp]
	add	edx, 4
	mov	DWORD PTR _luv$[ebp], edx

; 1001 : 		luv3 += 3;

	mov	eax, DWORD PTR _luv3$[ebp]
	add	eax, 6
	mov	DWORD PTR _luv3$[ebp], eax

; 1002 : 	}

	jmp	$L66839
$L66840:

; 1003 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Luv24fromLuv48 ENDP
_sp$ = 8
_op$ = 12
_n$ = 16
_luv$ = -8
_xyz$ = -4
_Luv32fromXYZ PROC NEAR

; 1106 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 1107 : 	uint32* luv = (uint32*) sp->tbuf;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _luv$[ebp], ecx

; 1108 : 	float* xyz = (float*) op;

	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR _xyz$[ebp], edx
$L66958:

; 1109 : 
; 1110 : 	while (n-- > 0) {

	mov	eax, DWORD PTR _n$[ebp]
	mov	ecx, DWORD PTR _n$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _n$[ebp], ecx
	test	eax, eax
	jle	SHORT $L66959

; 1111 : 		*luv++ = LogLuv32fromXYZ(xyz, sp->encode_meth);

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+4]
	push	eax
	mov	ecx, DWORD PTR _xyz$[ebp]
	push	ecx
	call	_LogLuv32fromXYZ
	add	esp, 8
	mov	edx, DWORD PTR _luv$[ebp]
	mov	DWORD PTR [edx], eax
	mov	eax, DWORD PTR _luv$[ebp]
	add	eax, 4
	mov	DWORD PTR _luv$[ebp], eax

; 1112 : 		xyz += 3;

	mov	ecx, DWORD PTR _xyz$[ebp]
	add	ecx, 12					; 0000000cH
	mov	DWORD PTR _xyz$[ebp], ecx

; 1113 : 	}

	jmp	SHORT $L66958
$L66959:

; 1114 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Luv32fromXYZ ENDP
_TEXT	ENDS
PUBLIC	__real@8@3ff8cd00000000000000
;	COMDAT __real@8@3ff8cd00000000000000
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_luv.c
CONST	SEGMENT
__real@8@3ff8cd00000000000000 DQ 03f89a00000000000r ; 0.0125122
CONST	ENDS
_TEXT	SEGMENT
_sp$ = 8
_op$ = 12
_n$ = 16
_luv$ = -4
_luv3$ = -8
_Luv32fromLuv48 PROC NEAR

; 1118 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 56					; 00000038H

; 1119 : 	uint32* luv = (uint32*) sp->tbuf;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	mov	DWORD PTR _luv$[ebp], ecx

; 1120 : 	int16* luv3 = (int16*) op;

	mov	edx, DWORD PTR _op$[ebp]
	mov	DWORD PTR _luv3$[ebp], edx

; 1121 : 
; 1122 : 	if (sp->encode_meth == SGILOGENCODE_NODITHER) {

	mov	eax, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [eax+4], 0
	jne	SHORT $L66972
$L66974:

; 1123 : 		while (n-- > 0) {

	mov	ecx, DWORD PTR _n$[ebp]
	mov	edx, DWORD PTR _n$[ebp]
	sub	edx, 1
	mov	DWORD PTR _n$[ebp], edx
	test	ecx, ecx
	jle	SHORT $L66975

; 1124 : 			*luv++ = (uint32)luv3[0] << 16 |
; 1125 : 				(luv3[1]*(uint32)(UVSCALE+.5) >> 7 & 0xff00) |
; 1126 : 				(luv3[2]*(uint32)(UVSCALE+.5) >> 15 & 0xff);

	mov	eax, DWORD PTR _luv3$[ebp]
	movsx	ecx, WORD PTR [eax]
	shl	ecx, 16					; 00000010H
	mov	edx, DWORD PTR _luv3$[ebp]
	movsx	eax, WORD PTR [edx+2]
	imul	eax, 410				; 0000019aH
	shr	eax, 7
	and	eax, 65280				; 0000ff00H
	or	ecx, eax
	mov	edx, DWORD PTR _luv3$[ebp]
	movsx	eax, WORD PTR [edx+4]
	imul	eax, 410				; 0000019aH
	shr	eax, 15					; 0000000fH
	and	eax, 255				; 000000ffH
	or	ecx, eax
	mov	edx, DWORD PTR _luv$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _luv$[ebp]
	add	eax, 4
	mov	DWORD PTR _luv$[ebp], eax

; 1127 : 			luv3 += 3;

	mov	ecx, DWORD PTR _luv3$[ebp]
	add	ecx, 6
	mov	DWORD PTR _luv3$[ebp], ecx

; 1128 : 		}

	jmp	SHORT $L66974
$L66975:

; 1129 : 		return;

	jmp	$L66981
$L66972:

; 1131 : 	while (n-- > 0) {

	mov	edx, DWORD PTR _n$[ebp]
	mov	eax, DWORD PTR _n$[ebp]
	sub	eax, 1
	mov	DWORD PTR _n$[ebp], eax
	test	edx, edx
	jle	$L66981

; 1132 : 		*luv++ = (uint32)luv3[0] << 16 |
; 1133 : 	(itrunc(luv3[1]*(UVSCALE/(1<<15)), sp->encode_meth) << 8 & 0xff00) |
; 1134 : 		(itrunc(luv3[2]*(UVSCALE/(1<<15)), sp->encode_meth) & 0xff);

	mov	ecx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [ecx+4], 0
	jne	SHORT $L67503
	mov	edx, DWORD PTR _luv3$[ebp]
	movsx	eax, WORD PTR [edx+2]
	mov	DWORD PTR -12+[ebp], eax
	fild	DWORD PTR -12+[ebp]
	fmul	QWORD PTR __real@8@3ff8cd00000000000000
	call	__ftol
	mov	DWORD PTR -16+[ebp], eax
	jmp	SHORT $L67504
$L67503:
	mov	ecx, DWORD PTR _luv3$[ebp]
	movsx	edx, WORD PTR [ecx+2]
	mov	DWORD PTR -20+[ebp], edx
	fild	DWORD PTR -20+[ebp]
	fmul	QWORD PTR __real@8@3ff8cd00000000000000
	fstp	QWORD PTR -28+[ebp]
	call	_rand
	mov	DWORD PTR -32+[ebp], eax
	fild	DWORD PTR -32+[ebp]
	fmul	QWORD PTR __real@8@3ff08001000200040000
	fadd	QWORD PTR -28+[ebp]
	fsub	QWORD PTR __real@8@3ffe8000000000000000
	call	__ftol
	mov	DWORD PTR -16+[ebp], eax
$L67504:
	mov	eax, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [eax+4], 0
	jne	SHORT $L67505
	mov	ecx, DWORD PTR _luv3$[ebp]
	movsx	edx, WORD PTR [ecx+4]
	mov	DWORD PTR -36+[ebp], edx
	fild	DWORD PTR -36+[ebp]
	fmul	QWORD PTR __real@8@3ff8cd00000000000000
	call	__ftol
	mov	DWORD PTR -40+[ebp], eax
	jmp	SHORT $L67506
$L67505:
	mov	eax, DWORD PTR _luv3$[ebp]
	movsx	ecx, WORD PTR [eax+4]
	mov	DWORD PTR -44+[ebp], ecx
	fild	DWORD PTR -44+[ebp]
	fmul	QWORD PTR __real@8@3ff8cd00000000000000
	fstp	QWORD PTR -52+[ebp]
	call	_rand
	mov	DWORD PTR -56+[ebp], eax
	fild	DWORD PTR -56+[ebp]
	fmul	QWORD PTR __real@8@3ff08001000200040000
	fadd	QWORD PTR -52+[ebp]
	fsub	QWORD PTR __real@8@3ffe8000000000000000
	call	__ftol
	mov	DWORD PTR -40+[ebp], eax
$L67506:
	mov	edx, DWORD PTR _luv3$[ebp]
	movsx	eax, WORD PTR [edx]
	shl	eax, 16					; 00000010H
	mov	ecx, DWORD PTR -16+[ebp]
	shl	ecx, 8
	and	ecx, 65280				; 0000ff00H
	or	eax, ecx
	mov	edx, DWORD PTR -40+[ebp]
	and	edx, 255				; 000000ffH
	or	eax, edx
	mov	ecx, DWORD PTR _luv$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _luv$[ebp]
	add	edx, 4
	mov	DWORD PTR _luv$[ebp], edx

; 1135 : 		luv3 += 3;

	mov	eax, DWORD PTR _luv3$[ebp]
	add	eax, 6
	mov	DWORD PTR _luv3$[ebp], eax

; 1136 : 	}

	jmp	$L66972
$L66981:

; 1137 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Luv32fromLuv48 ENDP
_tif$ = 8
_td$ = -4
_LogLuvClose PROC NEAR

; 1431 : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 1432 : 	TIFFDirectory *td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 1433 : 
; 1434 : 	/*
; 1435 : 	 * For consistency, we always want to write out the same
; 1436 : 	 * bitspersample and sampleformat for our TIFF file,
; 1437 : 	 * regardless of the data format being used by the application.
; 1438 : 	 * Since this routine is called after tags have been set but
; 1439 : 	 * before they have been recorded in the file, we reset them here.
; 1440 : 	 */
; 1441 : 	td->td_samplesperpixel =
; 1442 : 	    (td->td_photometric == PHOTOMETRIC_LOGL) ? 1 : 3;

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+46]
	sub	edx, 32844				; 0000804cH
	neg	edx
	sbb	edx, edx
	and	edx, 2
	add	edx, 1
	mov	eax, DWORD PTR _td$[ebp]
	mov	WORD PTR [eax+54], dx

; 1443 : 	td->td_bitspersample = 16;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	WORD PTR [ecx+40], 16			; 00000010H

; 1444 : 	td->td_sampleformat = SAMPLEFORMAT_INT;

	mov	edx, DWORD PTR _td$[ebp]
	mov	WORD PTR [edx+42], 2

; 1445 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogLuvClose ENDP
_TEXT	ENDS
EXTRN	__TIFFfree:NEAR
_TEXT	SEGMENT
_tif$ = 8
_sp$ = -4
_LogLuvCleanup PROC NEAR

; 1449 : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 1450 : 	LogLuvState* sp = (LogLuvState *)tif->tif_data;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 1451 : 
; 1452 : 	if (sp) {

	cmp	DWORD PTR _sp$[ebp], 0
	je	SHORT $L67204

; 1453 : 		if (sp->tbuf)

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx+12], 0
	je	SHORT $L67205

; 1454 : 			_TIFFfree(sp->tbuf);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	push	ecx
	call	__TIFFfree
	add	esp, 4
$L67205:

; 1455 : 		_TIFFfree(sp);

	mov	edx, DWORD PTR _sp$[ebp]
	push	edx
	call	__TIFFfree
	add	esp, 4

; 1456 : 		tif->tif_data = NULL;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+460], 0
$L67204:

; 1458 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogLuvCleanup ENDP
_TEXT	ENDS
EXTRN	_TIFFTileSize:NEAR
EXTRN	_TIFFSetField:NEAR
_DATA	SEGMENT
	ORG $+1
$SG67240 DB	'Unknown data format %d for LogLuv compression', 00H
	ORG $+2
$SG67250 DB	'Unknown encoding %d for LogLuv compression', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_tag$ = 12
_ap$ = 16
_sp$ = -8
_bps$ = -12
_fmt$ = -4
_LogLuvVSetField PROC NEAR

; 1462 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 20					; 00000014H

; 1463 : 	LogLuvState* sp = DecoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 1464 : 	int bps, fmt;
; 1465 : 
; 1466 : 	switch (tag) {

	mov	edx, DWORD PTR _tag$[ebp]
	mov	DWORD PTR -16+[ebp], edx
	cmp	DWORD PTR -16+[ebp], 65560		; 00010018H
	je	SHORT $L67223
	cmp	DWORD PTR -16+[ebp], 65561		; 00010019H
	je	$L67241
	jmp	$L67251
$L67223:

; 1467 : 	case TIFFTAG_SGILOGDATAFMT:
; 1468 : 		sp->user_datafmt = va_arg(ap, int);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	DWORD PTR [ecx], eax

; 1469 : 		/*
; 1470 : 		 * Tweak the TIFF header so that the rest of libtiff knows what
; 1471 : 		 * size of data will be passed between app and library, and
; 1472 : 		 * assume that the app knows what it is doing and is not
; 1473 : 		 * confused by these header manipulations...
; 1474 : 		 */
; 1475 : 		switch (sp->user_datafmt) {

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR -20+[ebp], edx
	cmp	DWORD PTR -20+[ebp], 3
	ja	SHORT $L67239
	mov	eax, DWORD PTR -20+[ebp]
	jmp	DWORD PTR $L67512[eax*4]
$L67235:

; 1476 : 		case SGILOGDATAFMT_FLOAT:
; 1477 : 			bps = 32, fmt = SAMPLEFORMAT_IEEEFP;

	mov	DWORD PTR _bps$[ebp], 32		; 00000020H
	mov	DWORD PTR _fmt$[ebp], 3

; 1478 : 			break;

	jmp	SHORT $L67232
$L67236:

; 1479 : 		case SGILOGDATAFMT_16BIT:
; 1480 : 			bps = 16, fmt = SAMPLEFORMAT_INT;

	mov	DWORD PTR _bps$[ebp], 16		; 00000010H
	mov	DWORD PTR _fmt$[ebp], 2

; 1481 : 			break;

	jmp	SHORT $L67232
$L67237:

; 1482 : 		case SGILOGDATAFMT_RAW:
; 1483 : 			bps = 32, fmt = SAMPLEFORMAT_UINT;

	mov	DWORD PTR _bps$[ebp], 32		; 00000020H
	mov	DWORD PTR _fmt$[ebp], 1

; 1484 : 			TIFFSetField(tif, TIFFTAG_SAMPLESPERPIXEL, 1);

	push	1
	push	277					; 00000115H
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFSetField
	add	esp, 12					; 0000000cH

; 1485 : 			break;

	jmp	SHORT $L67232
$L67238:

; 1486 : 		case SGILOGDATAFMT_8BIT:
; 1487 : 			bps = 8, fmt = SAMPLEFORMAT_UINT;

	mov	DWORD PTR _bps$[ebp], 8
	mov	DWORD PTR _fmt$[ebp], 1

; 1488 : 			break;

	jmp	SHORT $L67232
$L67239:

; 1489 : 		default:
; 1490 : 			TIFFError(tif->tif_name,
; 1491 : 			    "Unknown data format %d for LogLuv compression",
; 1492 : 			    sp->user_datafmt);

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	push	OFFSET FLAT:$SG67240
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 1493 : 			return (0);

	xor	eax, eax
	jmp	$L67220
$L67232:

; 1495 : 		TIFFSetField(tif, TIFFTAG_BITSPERSAMPLE, bps);

	mov	eax, DWORD PTR _bps$[ebp]
	push	eax
	push	258					; 00000102H
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFSetField
	add	esp, 12					; 0000000cH

; 1496 : 		TIFFSetField(tif, TIFFTAG_SAMPLEFORMAT, fmt);

	mov	edx, DWORD PTR _fmt$[ebp]
	push	edx
	push	339					; 00000153H
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFSetField
	add	esp, 12					; 0000000cH

; 1497 : 		/*
; 1498 : 		 * Must recalculate sizes should bits/sample change.
; 1499 : 		 */
; 1500 : 		tif->tif_tilesize = TIFFTileSize(tif);

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFTileSize
	add	esp, 4
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+392], eax

; 1501 : 		tif->tif_scanlinesize = TIFFScanlineSize(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFScanlineSize
	add	esp, 4
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+464], eax

; 1502 : 		return (1);

	mov	eax, 1
	jmp	SHORT $L67220
$L67241:

; 1503 : 	case TIFFTAG_SGILOGENCODE:
; 1504 : 		sp->encode_meth = va_arg(ap, int);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	DWORD PTR [eax+4], edx

; 1505 : 		if (sp->encode_meth != SGILOGENCODE_NODITHER &&
; 1506 : 				sp->encode_meth != SGILOGENCODE_RANDITHER) {

	mov	eax, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [eax+4], 0
	je	SHORT $L67249
	mov	ecx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [ecx+4], 1
	je	SHORT $L67249

; 1507 : 			TIFFError(tif->tif_name,
; 1508 : 				"Unknown encoding %d for LogLuv compression",
; 1509 : 				sp->encode_meth);

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+4]
	push	eax
	push	OFFSET FLAT:$SG67250
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 1510 : 			return (0);

	xor	eax, eax
	jmp	SHORT $L67220
$L67249:

; 1512 : 		return (1);

	mov	eax, 1
	jmp	SHORT $L67220
$L67251:

; 1513 : 	default:
; 1514 : 		return (*sp->vsetparent)(tif, tag, ap);

	mov	eax, DWORD PTR _ap$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tag$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	call	DWORD PTR [eax+28]
	add	esp, 12					; 0000000cH
$L67220:

; 1516 : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L67512:
	DD	$L67235
	DD	$L67236
	DD	$L67237
	DD	$L67238
_LogLuvVSetField ENDP
_tif$ = 8
_tag$ = 12
_ap$ = 16
_sp$ = -4
_LogLuvVGetField PROC NEAR

; 1520 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 1521 : 	LogLuvState *sp = (LogLuvState *)tif->tif_data;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 1522 : 
; 1523 : 	switch (tag) {

	mov	edx, DWORD PTR _tag$[ebp]
	mov	DWORD PTR -8+[ebp], edx
	cmp	DWORD PTR -8+[ebp], 65560		; 00010018H
	je	SHORT $L67266
	jmp	SHORT $L67274
$L67266:

; 1524 : 	case TIFFTAG_SGILOGDATAFMT:
; 1525 : 		*va_arg(ap, int*) = sp->user_datafmt;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR [edx], ecx

; 1526 : 		return (1);

	mov	eax, 1
	jmp	SHORT $L67263
$L67274:

; 1527 : 	default:
; 1528 : 		return (*sp->vgetparent)(tif, tag, ap);

	mov	edx, DWORD PTR _ap$[ebp]
	push	edx
	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _sp$[ebp]
	call	DWORD PTR [edx+24]
	add	esp, 12					; 0000000cH
$L67263:

; 1530 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_LogLuvVGetField ENDP
_TEXT	ENDS
END
