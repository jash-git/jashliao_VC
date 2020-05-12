	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\mkg3states.c
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
_DATA	SEGMENT
COMM	_MainTable:QWORD:080H
COMM	_WhiteTable:QWORD:01000H
COMM	_BlackTable:QWORD:02004H
_DATA	ENDS
_BSS	SEGMENT
$SG1388	DB	01H DUP (?)
	ALIGN	4

$SG1390	DB	01H DUP (?)
	ALIGN	4

$SG1393	DB	01H DUP (?)
	ALIGN	4

$SG1395	DB	01H DUP (?)
_BSS	ENDS
_DATA	SEGMENT
_Pass	DW	08H
	DW	04H
	DW	00H
	DW	00H
_Horiz	DW	04H
	DW	03H
	DW	00H
	DW	00H
_V0	DW	01H
	DW	01H
	DW	00H
	DW	00H
_VR	DW	06H
	DW	013H
	DW	030H
	DW	026H
	DW	060H
	DW	037H
	DW	00H
	DW	00H
_VL	DW	02H
	DW	013H
	DW	010H
	DW	026H
	DW	020H
	DW	037H
	DW	00H
	DW	00H
_Ext	DW	040H
	DW	07H
	DW	00H
	DW	00H
_EOLV	DW	00H
	DW	07H
	DW	00H
	DW	00H
_MakeUpW DW	01bH
	DW	0405H
	DW	09H
	DW	0805H
	DW	03aH
	DW	0c06H
	DW	076H
	DW	01007H
	DW	06cH
	DW	01408H
	DW	0ecH
	DW	01808H
	DW	026H
	DW	01c08H
	DW	0a6H
	DW	02008H
	DW	016H
	DW	02408H
	DW	0e6H
	DW	02808H
	DW	066H
	DW	02c09H
	DW	0166H
	DW	03009H
	DW	096H
	DW	03409H
	DW	0196H
	DW	03809H
	DW	056H
	DW	03c09H
	DW	0156H
	DW	04009H
	DW	0d6H
	DW	04409H
	DW	01d6H
	DW	04809H
	DW	036H
	DW	04c09H
	DW	0136H
	DW	05009H
	DW	0b6H
	DW	05409H
	DW	01b6H
	DW	05809H
	DW	032H
	DW	05c09H
	DW	0132H
	DW	06009H
	DW	0b2H
	DW	06409H
	DW	06H
	DW	06806H
	DW	01b2H
	DW	06c09H
	DW	00H
	DW	00H
_MakeUpB DW	03c0H
	DW	040aH
	DW	0130H
	DW	080cH
	DW	0930H
	DW	0c0cH
	DW	0da0H
	DW	0100cH
	DW	0cc0H
	DW	0140cH
	DW	02c0H
	DW	0180cH
	DW	0ac0H
	DW	01c0cH
	DW	06c0H
	DW	0200dH
	DW	016c0H
	DW	0240dH
	DW	0a40H
	DW	0280dH
	DW	01a40H
	DW	02c0dH
	DW	0640H
	DW	0300dH
	DW	01640H
	DW	0340dH
	DW	09c0H
	DW	0380dH
	DW	019c0H
	DW	03c0dH
	DW	05c0H
	DW	0400dH
	DW	015c0H
	DW	0440dH
	DW	0dc0H
	DW	0480dH
	DW	01dc0H
	DW	04c0dH
	DW	0940H
	DW	0500dH
	DW	01940H
	DW	0540dH
	DW	0540H
	DW	0580dH
	DW	01540H
	DW	05c0dH
	DW	0b40H
	DW	0600dH
	DW	01b40H
	DW	0640dH
	DW	04c0H
	DW	0680dH
	DW	014c0H
	DW	06c0dH
	DW	00H
	DW	00H
_MakeUp	DW	080H
	DW	0700bH
	DW	0180H
	DW	0740bH
	DW	0580H
	DW	0780bH
	DW	0480H
	DW	07c0cH
	DW	0c80H
	DW	0800cH
	DW	0280H
	DW	0840cH
	DW	0a80H
	DW	0880cH
	DW	0680H
	DW	08c0cH
	DW	0e80H
	DW	0900cH
	DW	0380H
	DW	0940cH
	DW	0b80H
	DW	0980cH
	DW	0780H
	DW	09c0cH
	DW	0f80H
	DW	0a00cH
	DW	00H
	DW	00H
_TermW	DW	0acH
	DW	08H
	DW	038H
	DW	016H
	DW	0eH
	DW	024H
	DW	01H
	DW	034H
	DW	0dH
	DW	044H
	DW	03H
	DW	054H
	DW	07H
	DW	064H
	DW	0fH
	DW	074H
	DW	019H
	DW	085H
	DW	05H
	DW	095H
	DW	01cH
	DW	0a5H
	DW	02H
	DW	0b5H
	DW	04H
	DW	0c6H
	DW	030H
	DW	0d6H
	DW	0bH
	DW	0e6H
	DW	02bH
	DW	0f6H
	DW	015H
	DW	0106H
	DW	035H
	DW	0116H
	DW	072H
	DW	0127H
	DW	018H
	DW	0137H
	DW	08H
	DW	0147H
	DW	074H
	DW	0157H
	DW	060H
	DW	0167H
	DW	010H
	DW	0177H
	DW	0aH
	DW	0187H
	DW	06aH
	DW	0197H
	DW	064H
	DW	01a7H
	DW	012H
	DW	01b7H
	DW	0cH
	DW	01c7H
	DW	040H
	DW	01d8H
	DW	0c0H
	DW	01e8H
	DW	058H
	DW	01f8H
	DW	0d8H
	DW	0208H
	DW	048H
	DW	0218H
	DW	0c8H
	DW	0228H
	DW	028H
	DW	0238H
	DW	0a8H
	DW	0248H
	DW	068H
	DW	0258H
	DW	0e8H
	DW	0268H
	DW	014H
	DW	0278H
	DW	094H
	DW	0288H
	DW	054H
	DW	0298H
	DW	0d4H
	DW	02a8H
	DW	034H
	DW	02b8H
	DW	0b4H
	DW	02c8H
	DW	020H
	DW	02d8H
	DW	0a0H
	DW	02e8H
	DW	050H
	DW	02f8H
	DW	0d0H
	DW	0308H
	DW	04aH
	DW	0318H
	DW	0caH
	DW	0328H
	DW	02aH
	DW	0338H
	DW	0aaH
	DW	0348H
	DW	024H
	DW	0358H
	DW	0a4H
	DW	0368H
	DW	01aH
	DW	0378H
	DW	09aH
	DW	0388H
	DW	05aH
	DW	0398H
	DW	0daH
	DW	03a8H
	DW	052H
	DW	03b8H
	DW	0d2H
	DW	03c8H
	DW	04cH
	DW	03d8H
	DW	0ccH
	DW	03e8H
	DW	02cH
	DW	03f8H
	DW	00H
	DW	00H
_TermB	DW	03b0H
	DW	0aH
	DW	02H
	DW	013H
	DW	03H
	DW	022H
	DW	01H
	DW	032H
	DW	06H
	DW	043H
	DW	0cH
	DW	054H
	DW	04H
	DW	064H
	DW	018H
	DW	075H
	DW	028H
	DW	086H
	DW	08H
	DW	096H
	DW	010H
	DW	0a7H
	DW	050H
	DW	0b7H
	DW	070H
	DW	0c7H
	DW	020H
	DW	0d8H
	DW	0e0H
	DW	0e8H
	DW	030H
	DW	0f9H
	DW	03a0H
	DW	010aH
	DW	060H
	DW	011aH
	DW	040H
	DW	012aH
	DW	0730H
	DW	013bH
	DW	0b0H
	DW	014bH
	DW	01b0H
	DW	015bH
	DW	0760H
	DW	016bH
	DW	0a0H
	DW	017bH
	DW	0740H
	DW	018bH
	DW	0c0H
	DW	019bH
	DW	0530H
	DW	01acH
	DW	0d30H
	DW	01bcH
	DW	0330H
	DW	01ccH
	DW	0b30H
	DW	01dcH
	DW	0160H
	DW	01ecH
	DW	0960H
	DW	01fcH
	DW	0560H
	DW	020cH
	DW	0d60H
	DW	021cH
	DW	04b0H
	DW	022cH
	DW	0cb0H
	DW	023cH
	DW	02b0H
	DW	024cH
	DW	0ab0H
	DW	025cH
	DW	06b0H
	DW	026cH
	DW	0eb0H
	DW	027cH
	DW	0360H
	DW	028cH
	DW	0b60H
	DW	029cH
	DW	05b0H
	DW	02acH
	DW	0db0H
	DW	02bcH
	DW	02a0H
	DW	02ccH
	DW	0aa0H
	DW	02dcH
	DW	06a0H
	DW	02ecH
	DW	0ea0H
	DW	02fcH
	DW	0260H
	DW	030cH
	DW	0a60H
	DW	031cH
	DW	04a0H
	DW	032cH
	DW	0ca0H
	DW	033cH
	DW	0240H
	DW	034cH
	DW	0ec0H
	DW	035cH
	DW	01c0H
	DW	036cH
	DW	0e40H
	DW	037cH
	DW	0140H
	DW	038cH
	DW	01a0H
	DW	039cH
	DW	09a0H
	DW	03acH
	DW	0d40H
	DW	03bcH
	DW	0340H
	DW	03ccH
	DW	05a0H
	DW	03dcH
	DW	0660H
	DW	03ecH
	DW	0e60H
	DW	03fcH
	DW	00H
	DW	00H
_EOLH	DW	00H
	DW	0bH
	DW	00H
	DW	00H
_storage_class DD FLAT:$SG1388
_const_class DD	FLAT:$SG1390
_packoutput DD	01H
_prebrace DD	FLAT:$SG1393
_postbrace DD	FLAT:$SG1395
_DATA	ENDS
PUBLIC	_WriteTable
EXTRN	_fprintf:NEAR
_DATA	SEGMENT
$SG1408	DB	'%s %s TIFFFaxTabEnt %s[%d] = {', 00H
	ORG $+1
$SG1410	DB	0aH, 00H
	ORG $+2
$SG1415	DB	'%s%s%d,%d,%d%s', 00H
	ORG $+1
$SG1417	DB	',', 0aH, 00H
	ORG $+1
$SG1419	DB	',', 00H
	ORG $+2
$SG1421	DB	0aH, ' ', 00H
	ORG $+1
$SG1426	DB	'%s%s%3d,%3d,%4d%s', 00H
	ORG $+2
$SG1428	DB	',', 0aH, ' ', 00H
$SG1430	DB	',', 00H
	ORG $+2
$SG1431	DB	0aH, '};', 0aH, 00H
_DATA	ENDS
_TEXT	SEGMENT
_fd$ = 8
_T$ = 12
_Size$ = 16
_name$ = 20
_i$ = -8
_sep$ = -4
_WriteTable PROC NEAR

; 341  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 342  :     int i;
; 343  :     char* sep;
; 344  : 
; 345  :     fprintf(fd, "%s %s TIFFFaxTabEnt %s[%d] = {",
; 346  : 	storage_class, const_class, name, Size);

	mov	eax, DWORD PTR _Size$[ebp]
	push	eax
	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	mov	edx, DWORD PTR _const_class
	push	edx
	mov	eax, DWORD PTR _storage_class
	push	eax
	push	OFFSET FLAT:$SG1408
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 24					; 00000018H

; 347  :     if (packoutput) {

	cmp	DWORD PTR _packoutput, 0
	je	$L1409

; 348  : 	sep = "\n";

	mov	DWORD PTR _sep$[ebp], OFFSET FLAT:$SG1410

; 349  : 	for (i = 0; i < Size; i++) {

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L1411
$L1412:
	mov	edx, DWORD PTR _i$[ebp]
	add	edx, 1
	mov	DWORD PTR _i$[ebp], edx
$L1411:
	mov	eax, DWORD PTR _i$[ebp]
	cmp	eax, DWORD PTR _Size$[ebp]
	jge	SHORT $L1413

; 350  : 	    fprintf(fd, "%s%s%d,%d,%d%s",
; 351  : 		sep, prebrace, T->State, T->Width, (int) T->Param, postbrace);

	mov	ecx, DWORD PTR _postbrace
	push	ecx
	mov	edx, DWORD PTR _T$[ebp]
	mov	eax, DWORD PTR [edx+4]
	push	eax
	mov	ecx, DWORD PTR _T$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	push	edx
	mov	eax, DWORD PTR _T$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	push	ecx
	mov	edx, DWORD PTR _prebrace
	push	edx
	mov	eax, DWORD PTR _sep$[ebp]
	push	eax
	push	OFFSET FLAT:$SG1415
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 32					; 00000020H

; 352  : 	    if (((i+1) % 12) == 0)

	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	cdq
	mov	ecx, 12					; 0000000cH
	idiv	ecx
	test	edx, edx
	jne	SHORT $L1416

; 353  : 		    sep = ",\n";

	mov	DWORD PTR _sep$[ebp], OFFSET FLAT:$SG1417

; 354  : 	    else

	jmp	SHORT $L1418
$L1416:

; 355  : 		    sep = ",";

	mov	DWORD PTR _sep$[ebp], OFFSET FLAT:$SG1419
$L1418:

; 356  : 	    T++;

	mov	edx, DWORD PTR _T$[ebp]
	add	edx, 8
	mov	DWORD PTR _T$[ebp], edx

; 357  : 	}

	jmp	SHORT $L1412
$L1413:

; 358  :     } else {

	jmp	$L1424
$L1409:

; 359  : 	sep = "\n ";

	mov	DWORD PTR _sep$[ebp], OFFSET FLAT:$SG1421

; 360  : 	for (i = 0; i < Size; i++) {

	mov	DWORD PTR _i$[ebp], 0
	jmp	SHORT $L1422
$L1423:
	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	mov	DWORD PTR _i$[ebp], eax
$L1422:
	mov	ecx, DWORD PTR _i$[ebp]
	cmp	ecx, DWORD PTR _Size$[ebp]
	jge	SHORT $L1424

; 361  : 	    fprintf(fd, "%s%s%3d,%3d,%4d%s",
; 362  : 		sep, prebrace, T->State, T->Width, (int) T->Param, postbrace);

	mov	edx, DWORD PTR _postbrace
	push	edx
	mov	eax, DWORD PTR _T$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR _T$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+1]
	push	eax
	mov	ecx, DWORD PTR _T$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	push	edx
	mov	eax, DWORD PTR _prebrace
	push	eax
	mov	ecx, DWORD PTR _sep$[ebp]
	push	ecx
	push	OFFSET FLAT:$SG1426
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 32					; 00000020H

; 363  : 	    if (((i+1) % 6) == 0)

	mov	eax, DWORD PTR _i$[ebp]
	add	eax, 1
	cdq
	mov	ecx, 6
	idiv	ecx
	test	edx, edx
	jne	SHORT $L1427

; 364  : 		    sep = ",\n ";

	mov	DWORD PTR _sep$[ebp], OFFSET FLAT:$SG1428

; 365  : 	    else

	jmp	SHORT $L1429
$L1427:

; 366  : 		    sep = ",";

	mov	DWORD PTR _sep$[ebp], OFFSET FLAT:$SG1430
$L1429:

; 367  : 	    T++;

	mov	edx, DWORD PTR _T$[ebp]
	add	edx, 8
	mov	DWORD PTR _T$[ebp], edx

; 368  : 	}

	jmp	SHORT $L1423
$L1424:

; 370  :     fprintf(fd, "\n};\n");

	push	OFFSET FLAT:$SG1431
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8

; 371  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_WriteTable ENDP
_TEXT	ENDS
PUBLIC	_main
EXTRN	__iob:BYTE
EXTRN	_fclose:NEAR
EXTRN	_fopen:NEAR
EXTRN	_getopt:NEAR
EXTRN	_optind:DWORD
EXTRN	_optarg:DWORD
_DATA	SEGMENT
	ORG $+3
$SG1447	DB	'c:s:bp', 00H
	ORG $+1
$SG1456	DB	'{', 00H
	ORG $+2
$SG1457	DB	'}', 00H
	ORG $+2
$SG1459	DB	'usage: %s [-c const] [-s storage] [-p] [-b] file', 0aH, 00H
	ORG $+2
$SG1460	DB	'g3states.h', 00H
	ORG $+1
$SG1461	DB	'w', 00H
	ORG $+2
$SG1464	DB	'%s: %s: Cannot create output file.', 0aH, 00H
$SG1465	DB	'/* WARNING, this file was automatically generated by the'
	DB	0aH, 00H
	ORG $+2
$SG1466	DB	'    mkg3states program */', 0aH, 00H
	ORG $+1
$SG1467	DB	'#include "tiff.h"', 0aH, 00H
	ORG $+1
$SG1468	DB	'#include "tif_fax3.h"', 0aH, 00H
	ORG $+1
$SG1469	DB	'TIFFFaxMainTable', 00H
	ORG $+3
$SG1470	DB	'TIFFFaxWhiteTable', 00H
	ORG $+2
$SG1471	DB	'TIFFFaxBlackTable', 00H
_DATA	ENDS
_TEXT	SEGMENT
_argc$ = 8
_argv$ = 12
_fd$ = -4
_outputfile$ = -12
_c$ = -8
_main	PROC NEAR

; 376  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 20					; 00000014H
$L1445:

; 377  :     FILE* fd;
; 378  :     char* outputfile;
; 379  :     int c;
; 380  :     extern int optind;
; 381  :     extern char* optarg;
; 382  : 
; 383  :     while ((c = getopt(argc, argv, "c:s:bp")) != -1)

	push	OFFSET FLAT:$SG1447
	mov	eax, DWORD PTR _argv$[ebp]
	push	eax
	mov	ecx, DWORD PTR _argc$[ebp]
	push	ecx
	call	_getopt
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _c$[ebp], eax
	cmp	DWORD PTR _c$[ebp], -1
	je	$L1446

; 384  : 	switch (c) {

	mov	edx, DWORD PTR _c$[ebp]
	mov	DWORD PTR -16+[ebp], edx
	mov	eax, DWORD PTR -16+[ebp]
	sub	eax, 63					; 0000003fH
	mov	DWORD PTR -16+[ebp], eax
	cmp	DWORD PTR -16+[ebp], 52			; 00000034H
	ja	SHORT $L1449
	mov	edx, DWORD PTR -16+[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR $L1478[edx]
	jmp	DWORD PTR $L1479[ecx*4]
$L1452:

; 385  : 	case 'c':
; 386  : 	    const_class = optarg;

	mov	eax, DWORD PTR _optarg
	mov	DWORD PTR _const_class, eax

; 387  : 	    break;

	jmp	SHORT $L1449
$L1453:

; 388  : 	case 's':
; 389  : 	    storage_class = optarg;

	mov	ecx, DWORD PTR _optarg
	mov	DWORD PTR _storage_class, ecx

; 390  : 	    break;

	jmp	SHORT $L1449
$L1454:

; 391  : 	case 'p':
; 392  : 	    packoutput = 0;

	mov	DWORD PTR _packoutput, 0

; 393  : 	    break;

	jmp	SHORT $L1449
$L1455:

; 394  : 	case 'b':
; 395  : 	    prebrace = "{";

	mov	DWORD PTR _prebrace, OFFSET FLAT:$SG1456

; 396  : 	    postbrace = "}";

	mov	DWORD PTR _postbrace, OFFSET FLAT:$SG1457

; 397  : 	    break;

	jmp	SHORT $L1449
$L1458:

; 398  : 	case '?':
; 399  : 	    fprintf(stderr,
; 400  : 		"usage: %s [-c const] [-s storage] [-p] [-b] file\n",
; 401  : 		argv[0]);

	mov	edx, DWORD PTR _argv$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	push	OFFSET FLAT:$SG1459
	push	OFFSET FLAT:__iob+64
	call	_fprintf
	add	esp, 12					; 0000000cH

; 402  : 	    return (-1);

	or	eax, -1
	jmp	$L1437
$L1449:

; 403  : 	}

	jmp	$L1445
$L1446:

; 404  :     outputfile = optind < argc ? argv[optind] : "g3states.h";

	mov	ecx, DWORD PTR _optind
	cmp	ecx, DWORD PTR _argc$[ebp]
	jge	SHORT $L1476
	mov	edx, DWORD PTR _optind
	mov	eax, DWORD PTR _argv$[ebp]
	mov	ecx, DWORD PTR [eax+edx*4]
	mov	DWORD PTR -20+[ebp], ecx
	jmp	SHORT $L1477
$L1476:
	mov	DWORD PTR -20+[ebp], OFFSET FLAT:$SG1460
$L1477:
	mov	edx, DWORD PTR -20+[ebp]
	mov	DWORD PTR _outputfile$[ebp], edx

; 405  :     fd = fopen(outputfile, "w");

	push	OFFSET FLAT:$SG1461
	mov	eax, DWORD PTR _outputfile$[ebp]
	push	eax
	call	_fopen
	add	esp, 8
	mov	DWORD PTR _fd$[ebp], eax

; 406  :     if (fd == NULL) {

	cmp	DWORD PTR _fd$[ebp], 0
	jne	SHORT $L1463

; 407  : 	fprintf(stderr, "%s: %s: Cannot create output file.\n",
; 408  : 	    argv[0], outputfile);

	mov	ecx, DWORD PTR _outputfile$[ebp]
	push	ecx
	mov	edx, DWORD PTR _argv$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	push	OFFSET FLAT:$SG1464
	push	OFFSET FLAT:__iob+64
	call	_fprintf
	add	esp, 16					; 00000010H

; 409  : 	return (-2);

	mov	eax, -2					; fffffffeH
	jmp	$L1437
$L1463:

; 411  :     FillTable(MainTable, 7, Pass, S_Pass);

	push	1
	push	OFFSET FLAT:_Pass
	push	7
	push	OFFSET FLAT:_MainTable
	call	_FillTable
	add	esp, 16					; 00000010H

; 412  :     FillTable(MainTable, 7, Horiz, S_Horiz);

	push	2
	push	OFFSET FLAT:_Horiz
	push	7
	push	OFFSET FLAT:_MainTable
	call	_FillTable
	add	esp, 16					; 00000010H

; 413  :     FillTable(MainTable, 7, V0, S_V0);

	push	3
	push	OFFSET FLAT:_V0
	push	7
	push	OFFSET FLAT:_MainTable
	call	_FillTable
	add	esp, 16					; 00000010H

; 414  :     FillTable(MainTable, 7, VR, S_VR);

	push	4
	push	OFFSET FLAT:_VR
	push	7
	push	OFFSET FLAT:_MainTable
	call	_FillTable
	add	esp, 16					; 00000010H

; 415  :     FillTable(MainTable, 7, VL, S_VL);

	push	5
	push	OFFSET FLAT:_VL
	push	7
	push	OFFSET FLAT:_MainTable
	call	_FillTable
	add	esp, 16					; 00000010H

; 416  :     FillTable(MainTable, 7, Ext, S_Ext);

	push	6
	push	OFFSET FLAT:_Ext
	push	7
	push	OFFSET FLAT:_MainTable
	call	_FillTable
	add	esp, 16					; 00000010H

; 417  :     FillTable(MainTable, 7, EOLV, S_EOL);

	push	12					; 0000000cH
	push	OFFSET FLAT:_EOLV
	push	7
	push	OFFSET FLAT:_MainTable
	call	_FillTable
	add	esp, 16					; 00000010H

; 418  :     FillTable(WhiteTable, 12, MakeUpW, S_MakeUpW);

	push	9
	push	OFFSET FLAT:_MakeUpW
	push	12					; 0000000cH
	push	OFFSET FLAT:_WhiteTable
	call	_FillTable
	add	esp, 16					; 00000010H

; 419  :     FillTable(WhiteTable, 12, MakeUp, S_MakeUp);

	push	11					; 0000000bH
	push	OFFSET FLAT:_MakeUp
	push	12					; 0000000cH
	push	OFFSET FLAT:_WhiteTable
	call	_FillTable
	add	esp, 16					; 00000010H

; 420  :     FillTable(WhiteTable, 12, TermW, S_TermW);

	push	7
	push	OFFSET FLAT:_TermW
	push	12					; 0000000cH
	push	OFFSET FLAT:_WhiteTable
	call	_FillTable
	add	esp, 16					; 00000010H

; 421  :     FillTable(WhiteTable, 12, EOLH, S_EOL);

	push	12					; 0000000cH
	push	OFFSET FLAT:_EOLH
	push	12					; 0000000cH
	push	OFFSET FLAT:_WhiteTable
	call	_FillTable
	add	esp, 16					; 00000010H

; 422  :     FillTable(BlackTable, 13, MakeUpB, S_MakeUpB);

	push	10					; 0000000aH
	push	OFFSET FLAT:_MakeUpB
	push	13					; 0000000dH
	push	OFFSET FLAT:_BlackTable
	call	_FillTable
	add	esp, 16					; 00000010H

; 423  :     FillTable(BlackTable, 13, MakeUp, S_MakeUp);

	push	11					; 0000000bH
	push	OFFSET FLAT:_MakeUp
	push	13					; 0000000dH
	push	OFFSET FLAT:_BlackTable
	call	_FillTable
	add	esp, 16					; 00000010H

; 424  :     FillTable(BlackTable, 13, TermB, S_TermB);

	push	8
	push	OFFSET FLAT:_TermB
	push	13					; 0000000dH
	push	OFFSET FLAT:_BlackTable
	call	_FillTable
	add	esp, 16					; 00000010H

; 425  :     FillTable(BlackTable, 13, EOLH, S_EOL);

	push	12					; 0000000cH
	push	OFFSET FLAT:_EOLH
	push	13					; 0000000dH
	push	OFFSET FLAT:_BlackTable
	call	_FillTable
	add	esp, 16					; 00000010H

; 426  : 
; 427  :     fprintf(fd, "/* WARNING, this file was automatically generated by the\n");

	push	OFFSET FLAT:$SG1465
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 428  :     fprintf(fd, "    mkg3states program */\n");

	push	OFFSET FLAT:$SG1466
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8

; 429  :     fprintf(fd, "#include \"tiff.h\"\n");

	push	OFFSET FLAT:$SG1467
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8

; 430  :     fprintf(fd, "#include \"tif_fax3.h\"\n");

	push	OFFSET FLAT:$SG1468
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 431  :     WriteTable(fd, MainTable, 128, "TIFFFaxMainTable");

	push	OFFSET FLAT:$SG1469
	push	128					; 00000080H
	push	OFFSET FLAT:_MainTable
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_WriteTable
	add	esp, 16					; 00000010H

; 432  :     WriteTable(fd, WhiteTable, 4096, "TIFFFaxWhiteTable");

	push	OFFSET FLAT:$SG1470
	push	4096					; 00001000H
	push	OFFSET FLAT:_WhiteTable
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_WriteTable
	add	esp, 16					; 00000010H

; 433  :     WriteTable(fd, BlackTable, 8192, "TIFFFaxBlackTable");

	push	OFFSET FLAT:$SG1471
	push	8192					; 00002000H
	push	OFFSET FLAT:_BlackTable
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_WriteTable
	add	esp, 16					; 00000010H

; 434  :     fclose(fd);

	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fclose
	add	esp, 4

; 435  :     return (0);

	xor	eax, eax
$L1437:

; 436  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L1479:
	DD	$L1458
	DD	$L1455
	DD	$L1452
	DD	$L1454
	DD	$L1453
	DD	$L1449
$L1478:
	DB	0
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	1
	DB	2
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	5
	DB	3
	DB	5
	DB	5
	DB	4
_main	ENDP
_T$ = 8
_Size$ = 12
_P$ = 16
_State$ = 20
_limit$ = -4
_width$1379 = -12
_param$1380 = -16
_incr$1381 = -8
_code$1382 = -20
_E$1386 = -24
_FillTable PROC NEAR

; 315  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 24					; 00000018H

; 316  :     int limit = 1 << Size;

	mov	eax, 1
	mov	ecx, DWORD PTR _Size$[ebp]
	shl	eax, cl
	mov	DWORD PTR _limit$[ebp], eax
$L1377:

; 317  : 
; 318  :     while (P->val) {

	mov	ecx, DWORD PTR _P$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+2]
	test	edx, edx
	je	SHORT $L1378

; 319  : 	int width = P->val & 15;

	mov	eax, DWORD PTR _P$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+2]
	and	ecx, 15					; 0000000fH
	mov	DWORD PTR _width$1379[ebp], ecx

; 320  : 	int param = P->val >> 4;

	mov	edx, DWORD PTR _P$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+2]
	sar	eax, 4
	mov	DWORD PTR _param$1380[ebp], eax

; 321  : 	int incr = 1 << width;

	mov	edx, 1
	mov	ecx, DWORD PTR _width$1379[ebp]
	shl	edx, cl
	mov	DWORD PTR _incr$1381[ebp], edx

; 322  : 	int code;
; 323  : 	for (code = P->code; code < limit; code += incr) {

	mov	eax, DWORD PTR _P$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	mov	DWORD PTR _code$1382[ebp], ecx
	jmp	SHORT $L1383
$L1384:
	mov	edx, DWORD PTR _code$1382[ebp]
	add	edx, DWORD PTR _incr$1381[ebp]
	mov	DWORD PTR _code$1382[ebp], edx
$L1383:
	mov	eax, DWORD PTR _code$1382[ebp]
	cmp	eax, DWORD PTR _limit$[ebp]
	jge	SHORT $L1385

; 324  : 	    TIFFFaxTabEnt *E = T+code;

	mov	ecx, DWORD PTR _code$1382[ebp]
	mov	edx, DWORD PTR _T$[ebp]
	lea	eax, DWORD PTR [edx+ecx*8]
	mov	DWORD PTR _E$1386[ebp], eax

; 325  : 	    E->State = State;

	mov	ecx, DWORD PTR _E$1386[ebp]
	mov	dl, BYTE PTR _State$[ebp]
	mov	BYTE PTR [ecx], dl

; 326  : 	    E->Width = width;

	mov	eax, DWORD PTR _E$1386[ebp]
	mov	cl, BYTE PTR _width$1379[ebp]
	mov	BYTE PTR [eax+1], cl

; 327  : 	    E->Param = param;

	mov	edx, DWORD PTR _E$1386[ebp]
	mov	eax, DWORD PTR _param$1380[ebp]
	mov	DWORD PTR [edx+4], eax

; 328  : 	}

	jmp	SHORT $L1384
$L1385:

; 329  : 	P++;

	mov	ecx, DWORD PTR _P$[ebp]
	add	ecx, 4
	mov	DWORD PTR _P$[ebp], ecx

; 330  :     }

	jmp	$L1377
$L1378:

; 331  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_FillTable ENDP
_TEXT	ENDS
END
