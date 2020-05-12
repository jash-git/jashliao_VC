	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_fax3.c
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
PUBLIC	_TIFFFaxWhiteCodes
PUBLIC	_TIFFFaxBlackCodes
CONST	SEGMENT
_TIFFFaxWhiteCodes DW 08H
	DW	035H
	DW	00H
	DW	06H
	DW	07H
	DW	01H
	DW	04H
	DW	07H
	DW	02H
	DW	04H
	DW	08H
	DW	03H
	DW	04H
	DW	0bH
	DW	04H
	DW	04H
	DW	0cH
	DW	05H
	DW	04H
	DW	0eH
	DW	06H
	DW	04H
	DW	0fH
	DW	07H
	DW	05H
	DW	013H
	DW	08H
	DW	05H
	DW	014H
	DW	09H
	DW	05H
	DW	07H
	DW	0aH
	DW	05H
	DW	08H
	DW	0bH
	DW	06H
	DW	08H
	DW	0cH
	DW	06H
	DW	03H
	DW	0dH
	DW	06H
	DW	034H
	DW	0eH
	DW	06H
	DW	035H
	DW	0fH
	DW	06H
	DW	02aH
	DW	010H
	DW	06H
	DW	02bH
	DW	011H
	DW	07H
	DW	027H
	DW	012H
	DW	07H
	DW	0cH
	DW	013H
	DW	07H
	DW	08H
	DW	014H
	DW	07H
	DW	017H
	DW	015H
	DW	07H
	DW	03H
	DW	016H
	DW	07H
	DW	04H
	DW	017H
	DW	07H
	DW	028H
	DW	018H
	DW	07H
	DW	02bH
	DW	019H
	DW	07H
	DW	013H
	DW	01aH
	DW	07H
	DW	024H
	DW	01bH
	DW	07H
	DW	018H
	DW	01cH
	DW	08H
	DW	02H
	DW	01dH
	DW	08H
	DW	03H
	DW	01eH
	DW	08H
	DW	01aH
	DW	01fH
	DW	08H
	DW	01bH
	DW	020H
	DW	08H
	DW	012H
	DW	021H
	DW	08H
	DW	013H
	DW	022H
	DW	08H
	DW	014H
	DW	023H
	DW	08H
	DW	015H
	DW	024H
	DW	08H
	DW	016H
	DW	025H
	DW	08H
	DW	017H
	DW	026H
	DW	08H
	DW	028H
	DW	027H
	DW	08H
	DW	029H
	DW	028H
	DW	08H
	DW	02aH
	DW	029H
	DW	08H
	DW	02bH
	DW	02aH
	DW	08H
	DW	02cH
	DW	02bH
	DW	08H
	DW	02dH
	DW	02cH
	DW	08H
	DW	04H
	DW	02dH
	DW	08H
	DW	05H
	DW	02eH
	DW	08H
	DW	0aH
	DW	02fH
	DW	08H
	DW	0bH
	DW	030H
	DW	08H
	DW	052H
	DW	031H
	DW	08H
	DW	053H
	DW	032H
	DW	08H
	DW	054H
	DW	033H
	DW	08H
	DW	055H
	DW	034H
	DW	08H
	DW	024H
	DW	035H
	DW	08H
	DW	025H
	DW	036H
	DW	08H
	DW	058H
	DW	037H
	DW	08H
	DW	059H
	DW	038H
	DW	08H
	DW	05aH
	DW	039H
	DW	08H
	DW	05bH
	DW	03aH
	DW	08H
	DW	04aH
	DW	03bH
	DW	08H
	DW	04bH
	DW	03cH
	DW	08H
	DW	032H
	DW	03dH
	DW	08H
	DW	033H
	DW	03eH
	DW	08H
	DW	034H
	DW	03fH
	DW	05H
	DW	01bH
	DW	040H
	DW	05H
	DW	012H
	DW	080H
	DW	06H
	DW	017H
	DW	0c0H
	DW	07H
	DW	037H
	DW	0100H
	DW	08H
	DW	036H
	DW	0140H
	DW	08H
	DW	037H
	DW	0180H
	DW	08H
	DW	064H
	DW	01c0H
	DW	08H
	DW	065H
	DW	0200H
	DW	08H
	DW	068H
	DW	0240H
	DW	08H
	DW	067H
	DW	0280H
	DW	09H
	DW	0ccH
	DW	02c0H
	DW	09H
	DW	0cdH
	DW	0300H
	DW	09H
	DW	0d2H
	DW	0340H
	DW	09H
	DW	0d3H
	DW	0380H
	DW	09H
	DW	0d4H
	DW	03c0H
	DW	09H
	DW	0d5H
	DW	0400H
	DW	09H
	DW	0d6H
	DW	0440H
	DW	09H
	DW	0d7H
	DW	0480H
	DW	09H
	DW	0d8H
	DW	04c0H
	DW	09H
	DW	0d9H
	DW	0500H
	DW	09H
	DW	0daH
	DW	0540H
	DW	09H
	DW	0dbH
	DW	0580H
	DW	09H
	DW	098H
	DW	05c0H
	DW	09H
	DW	099H
	DW	0600H
	DW	09H
	DW	09aH
	DW	0640H
	DW	06H
	DW	018H
	DW	0680H
	DW	09H
	DW	09bH
	DW	06c0H
	DW	0bH
	DW	08H
	DW	0700H
	DW	0bH
	DW	0cH
	DW	0740H
	DW	0bH
	DW	0dH
	DW	0780H
	DW	0cH
	DW	012H
	DW	07c0H
	DW	0cH
	DW	013H
	DW	0800H
	DW	0cH
	DW	014H
	DW	0840H
	DW	0cH
	DW	015H
	DW	0880H
	DW	0cH
	DW	016H
	DW	08c0H
	DW	0cH
	DW	017H
	DW	0900H
	DW	0cH
	DW	01cH
	DW	0940H
	DW	0cH
	DW	01dH
	DW	0980H
	DW	0cH
	DW	01eH
	DW	09c0H
	DW	0cH
	DW	01fH
	DW	0a00H
	DW	0cH
	DW	01H
	DW	0ffffH
	DW	09H
	DW	01H
	DW	0fffeH
	DW	0aH
	DW	01H
	DW	0fffeH
	DW	0bH
	DW	01H
	DW	0fffeH
	DW	0cH
	DW	00H
	DW	0fffeH
	ORG $+2
_TIFFFaxBlackCodes DW 0aH
	DW	037H
	DW	00H
	DW	03H
	DW	02H
	DW	01H
	DW	02H
	DW	03H
	DW	02H
	DW	02H
	DW	02H
	DW	03H
	DW	03H
	DW	03H
	DW	04H
	DW	04H
	DW	03H
	DW	05H
	DW	04H
	DW	02H
	DW	06H
	DW	05H
	DW	03H
	DW	07H
	DW	06H
	DW	05H
	DW	08H
	DW	06H
	DW	04H
	DW	09H
	DW	07H
	DW	04H
	DW	0aH
	DW	07H
	DW	05H
	DW	0bH
	DW	07H
	DW	07H
	DW	0cH
	DW	08H
	DW	04H
	DW	0dH
	DW	08H
	DW	07H
	DW	0eH
	DW	09H
	DW	018H
	DW	0fH
	DW	0aH
	DW	017H
	DW	010H
	DW	0aH
	DW	018H
	DW	011H
	DW	0aH
	DW	08H
	DW	012H
	DW	0bH
	DW	067H
	DW	013H
	DW	0bH
	DW	068H
	DW	014H
	DW	0bH
	DW	06cH
	DW	015H
	DW	0bH
	DW	037H
	DW	016H
	DW	0bH
	DW	028H
	DW	017H
	DW	0bH
	DW	017H
	DW	018H
	DW	0bH
	DW	018H
	DW	019H
	DW	0cH
	DW	0caH
	DW	01aH
	DW	0cH
	DW	0cbH
	DW	01bH
	DW	0cH
	DW	0ccH
	DW	01cH
	DW	0cH
	DW	0cdH
	DW	01dH
	DW	0cH
	DW	068H
	DW	01eH
	DW	0cH
	DW	069H
	DW	01fH
	DW	0cH
	DW	06aH
	DW	020H
	DW	0cH
	DW	06bH
	DW	021H
	DW	0cH
	DW	0d2H
	DW	022H
	DW	0cH
	DW	0d3H
	DW	023H
	DW	0cH
	DW	0d4H
	DW	024H
	DW	0cH
	DW	0d5H
	DW	025H
	DW	0cH
	DW	0d6H
	DW	026H
	DW	0cH
	DW	0d7H
	DW	027H
	DW	0cH
	DW	06cH
	DW	028H
	DW	0cH
	DW	06dH
	DW	029H
	DW	0cH
	DW	0daH
	DW	02aH
	DW	0cH
	DW	0dbH
	DW	02bH
	DW	0cH
	DW	054H
	DW	02cH
	DW	0cH
	DW	055H
	DW	02dH
	DW	0cH
	DW	056H
	DW	02eH
	DW	0cH
	DW	057H
	DW	02fH
	DW	0cH
	DW	064H
	DW	030H
	DW	0cH
	DW	065H
	DW	031H
	DW	0cH
	DW	052H
	DW	032H
	DW	0cH
	DW	053H
	DW	033H
	DW	0cH
	DW	024H
	DW	034H
	DW	0cH
	DW	037H
	DW	035H
	DW	0cH
	DW	038H
	DW	036H
	DW	0cH
	DW	027H
	DW	037H
	DW	0cH
	DW	028H
	DW	038H
	DW	0cH
	DW	058H
	DW	039H
	DW	0cH
	DW	059H
	DW	03aH
	DW	0cH
	DW	02bH
	DW	03bH
	DW	0cH
	DW	02cH
	DW	03cH
	DW	0cH
	DW	05aH
	DW	03dH
	DW	0cH
	DW	066H
	DW	03eH
	DW	0cH
	DW	067H
	DW	03fH
	DW	0aH
	DW	0fH
	DW	040H
	DW	0cH
	DW	0c8H
	DW	080H
	DW	0cH
	DW	0c9H
	DW	0c0H
	DW	0cH
	DW	05bH
	DW	0100H
	DW	0cH
	DW	033H
	DW	0140H
	DW	0cH
	DW	034H
	DW	0180H
	DW	0cH
	DW	035H
	DW	01c0H
	DW	0dH
	DW	06cH
	DW	0200H
	DW	0dH
	DW	06dH
	DW	0240H
	DW	0dH
	DW	04aH
	DW	0280H
	DW	0dH
	DW	04bH
	DW	02c0H
	DW	0dH
	DW	04cH
	DW	0300H
	DW	0dH
	DW	04dH
	DW	0340H
	DW	0dH
	DW	072H
	DW	0380H
	DW	0dH
	DW	073H
	DW	03c0H
	DW	0dH
	DW	074H
	DW	0400H
	DW	0dH
	DW	075H
	DW	0440H
	DW	0dH
	DW	076H
	DW	0480H
	DW	0dH
	DW	077H
	DW	04c0H
	DW	0dH
	DW	052H
	DW	0500H
	DW	0dH
	DW	053H
	DW	0540H
	DW	0dH
	DW	054H
	DW	0580H
	DW	0dH
	DW	055H
	DW	05c0H
	DW	0dH
	DW	05aH
	DW	0600H
	DW	0dH
	DW	05bH
	DW	0640H
	DW	0dH
	DW	064H
	DW	0680H
	DW	0dH
	DW	065H
	DW	06c0H
	DW	0bH
	DW	08H
	DW	0700H
	DW	0bH
	DW	0cH
	DW	0740H
	DW	0bH
	DW	0dH
	DW	0780H
	DW	0cH
	DW	012H
	DW	07c0H
	DW	0cH
	DW	013H
	DW	0800H
	DW	0cH
	DW	014H
	DW	0840H
	DW	0cH
	DW	015H
	DW	0880H
	DW	0cH
	DW	016H
	DW	08c0H
	DW	0cH
	DW	017H
	DW	0900H
	DW	0cH
	DW	01cH
	DW	0940H
	DW	0cH
	DW	01dH
	DW	0980H
	DW	0cH
	DW	01eH
	DW	09c0H
	DW	0cH
	DW	01fH
	DW	0a00H
	DW	0cH
	DW	01H
	DW	0ffffH
	DW	09H
	DW	01H
	DW	0fffeH
	DW	0aH
	DW	01H
	DW	0fffeH
	DW	0bH
	DW	01H
	DW	0fffeH
	DW	0cH
	DW	00H
	DW	0fffeH
	ORG $+2
_?module@?1??Fax3Decode1D@@9@9 DB 'Fax3Decode1D', 00H
	ORG $+3
_?module@?1??Fax3Decode2D@@9@9 DB 'Fax3Decode2D', 00H
	ORG $+3
_?_fillmasks@?1??_TIFFFax3fillruns@@9@9 DB 00H
	DB	080H
	DB	0c0H
	DB	0e0H
	DB	0f0H
	DB	0f8H
	DB	0fcH
	DB	0feH
	DB	0ffH
	ORG $+3
__msbmask DD	00H
	DD	01H
	DD	03H
	DD	07H
	DD	0fH
	DD	01fH
	DD	03fH
	DD	07fH
	DD	0ffH
_zeroruns DB	08H
	DB	07H
	DB	06H
	DB	06H
	DB	05H
	DB	05H
	DB	05H
	DB	05H
	DB	04H
	DB	04H
	DB	04H
	DB	04H
	DB	04H
	DB	04H
	DB	04H
	DB	04H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
_oneruns DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	00H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	01H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	02H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	03H
	DB	04H
	DB	04H
	DB	04H
	DB	04H
	DB	04H
	DB	04H
	DB	04H
	DB	04H
	DB	05H
	DB	05H
	DB	05H
	DB	05H
	DB	06H
	DB	06H
	DB	07H
	DB	08H
_horizcode DW	03H
	DW	01H
	ORG $+2
	ORG $+2
_passcode DW	04H
	DW	01H
	ORG $+2
	ORG $+2
_vcodes	DW	07H
	DW	03H
	ORG $+2
	DW	06H
	DW	03H
	ORG $+2
	DW	03H
	DW	03H
	ORG $+2
	DW	01H
	DW	01H
	ORG $+2
	DW	03H
	DW	02H
	ORG $+2
	DW	06H
	DW	02H
	ORG $+2
	DW	07H
	DW	02H
	ORG $+2
	ORG $+6
_faxFieldInfo DD 010000H
	DW	00H
	DW	00H
	DD	00H
	DW	00H
	DB	00H
	DB	00H
	DD	FLAT:$SG67293
	DD	010004H
	DW	00H
	DW	00H
	DD	00H
	DW	00H
	DB	00H
	DB	00H
	DD	FLAT:$SG67294
	DD	0146H
	DW	01H
	DW	01H
	DD	04H
	DW	03fH
	DB	01H
	DB	00H
	DD	FLAT:$SG67295
	DD	0146H
	DW	01H
	DW	01H
	DD	03H
	DW	03fH
	DB	01H
	DB	00H
	DD	FLAT:$SG67296
	DD	0147H
	DW	01H
	DW	01H
	DD	03H
	DW	040H
	DB	01H
	DB	00H
	DD	FLAT:$SG67297
	DD	0148H
	DW	01H
	DW	01H
	DD	04H
	DW	041H
	DB	01H
	DB	00H
	DD	FLAT:$SG67298
	DD	0148H
	DW	01H
	DW	01H
	DD	03H
	DW	041H
	DB	01H
	DB	00H
	DD	FLAT:$SG67299
	DD	0885cH
	DW	01H
	DW	01H
	DD	04H
	DW	042H
	DB	01H
	DB	00H
	DD	FLAT:$SG67300
	DD	0885dH
	DW	0ffffH
	DW	0ffffH
	DD	02H
	DW	043H
	DB	01H
	DB	00H
	DD	FLAT:$SG67301
	DD	0885eH
	DW	01H
	DW	01H
	DD	04H
	DW	044H
	DB	01H
	DB	00H
	DD	FLAT:$SG67302
_fax3FieldInfo DD 0124H
	DW	01H
	DW	01H
	DD	04H
	DW	045H
	DB	00H
	DB	00H
	DD	FLAT:$SG67304
	ORG $+4
_fax4FieldInfo DD 0125H
	DW	01H
	DW	01H
	DD	04H
	DW	045H
	DB	00H
	DB	00H
	DD	FLAT:$SG67306
_?module@?1??Fax4Decode@@9@9 DB 'Fax4Decode', 00H
	ORG $+1
_?module@?1??Fax3DecodeRLE@@9@9 DB 'Fax3DecodeRLE', 00H
CONST	ENDS
_DATA	SEGMENT
$SG67293 DB	'FaxMode', 00H
$SG67294 DB	'FaxFillFunc', 00H
$SG67295 DB	'BadFaxLines', 00H
$SG67296 DB	'BadFaxLines', 00H
$SG67297 DB	'CleanFaxData', 00H
	ORG $+3
$SG67298 DB	'ConsecutiveBadFaxLines', 00H
	ORG $+1
$SG67299 DB	'ConsecutiveBadFaxLines', 00H
	ORG $+1
$SG67300 DB	'FaxRecvParams', 00H
	ORG $+2
$SG67301 DB	'FaxSubAddress', 00H
	ORG $+2
$SG67302 DB	'FaxRecvTime', 00H
$SG67304 DB	'Group3Options', 00H
	ORG $+2
$SG67306 DB	'Group4Options', 00H
_DATA	ENDS
PUBLIC	__TIFFFax3fillruns
EXTRN	__assert:NEAR
_DATA	SEGMENT
	ORG $+2
$SG66891 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_fax3.c', 00H
	ORG $+3
$SG66892 DB	'x == lastx', 00H
_DATA	ENDS
_TEXT	SEGMENT
_buf$ = 8
_runs$ = 12
_erun$ = 16
_lastx$ = 20
_cp$ = -8
_x$ = -24
_bx$ = -20
_run$ = -4
_n$ = -28
_nw$ = -12
_lp$ = -16
__TIFFFax3fillruns PROC NEAR

; 358  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 36					; 00000024H

; 359  : 	static const unsigned char _fillmasks[] =
; 360  : 	    { 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff };
; 361  : 	u_char* cp;
; 362  : 	uint32 x, bx, run;
; 363  : 	int32 n, nw;
; 364  : 	long* lp;
; 365  : 
; 366  : 	if ((erun-runs)&1)

	mov	eax, DWORD PTR _erun$[ebp]
	sub	eax, DWORD PTR _runs$[ebp]
	sar	eax, 2
	and	eax, 1
	test	eax, eax
	je	SHORT $L66815

; 367  : 	    *erun++ = 0;

	mov	ecx, DWORD PTR _erun$[ebp]
	mov	DWORD PTR [ecx], 0
	mov	edx, DWORD PTR _erun$[ebp]
	add	edx, 4
	mov	DWORD PTR _erun$[ebp], edx
$L66815:

; 368  : 	x = 0;

	mov	DWORD PTR _x$[ebp], 0

; 369  : 	for (; runs < erun; runs += 2) {

	jmp	SHORT $L66816
$L66817:
	mov	eax, DWORD PTR _runs$[ebp]
	add	eax, 8
	mov	DWORD PTR _runs$[ebp], eax
$L66816:
	mov	ecx, DWORD PTR _runs$[ebp]
	cmp	ecx, DWORD PTR _erun$[ebp]
	jae	$L66818

; 370  : 	    run = runs[0];

	mov	edx, DWORD PTR _runs$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR _run$[ebp], eax

; 371  : 	    if (x+run > lastx || run > lastx )

	mov	ecx, DWORD PTR _x$[ebp]
	add	ecx, DWORD PTR _run$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	ja	SHORT $L66820
	mov	edx, DWORD PTR _run$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	jbe	SHORT $L66819
$L66820:

; 372  : 		run = runs[0] = (uint32) (lastx - x);

	mov	eax, DWORD PTR _lastx$[ebp]
	sub	eax, DWORD PTR _x$[ebp]
	mov	ecx, DWORD PTR _runs$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _runs$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR _run$[ebp], eax
$L66819:

; 373  : 	    if (run) {

	cmp	DWORD PTR _run$[ebp], 0
	je	$L66822

; 374  : 		cp = buf + (x>>3);

	mov	ecx, DWORD PTR _x$[ebp]
	shr	ecx, 3
	mov	edx, DWORD PTR _buf$[ebp]
	add	edx, ecx
	mov	DWORD PTR _cp$[ebp], edx

; 375  : 		bx = x&7;

	mov	eax, DWORD PTR _x$[ebp]
	and	eax, 7
	mov	DWORD PTR _bx$[ebp], eax

; 376  : 		if (run > 8-bx) {

	mov	ecx, 8
	sub	ecx, DWORD PTR _bx$[ebp]
	cmp	DWORD PTR _run$[ebp], ecx
	jbe	$L66823

; 377  : 		    if (bx) {			/* align to byte boundary */

	cmp	DWORD PTR _bx$[ebp], 0
	je	SHORT $L66824

; 378  : 			*cp++ &= 0xff << (8-bx);

	mov	ecx, 8
	sub	ecx, DWORD PTR _bx$[ebp]
	mov	edx, 255				; 000000ffH
	shl	edx, cl
	mov	eax, DWORD PTR _cp$[ebp]
	mov	cl, BYTE PTR [eax]
	and	cl, dl
	mov	edx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [edx], cl
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 1
	mov	DWORD PTR _cp$[ebp], eax

; 379  : 			run -= 8-bx;

	mov	ecx, 8
	sub	ecx, DWORD PTR _bx$[ebp]
	mov	edx, DWORD PTR _run$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _run$[ebp], edx
$L66824:

; 381  : 		    if( (n = run >> 3) != 0 ) {	/* multiple bytes to fill */

	mov	eax, DWORD PTR _run$[ebp]
	shr	eax, 3
	mov	DWORD PTR _n$[ebp], eax
	cmp	DWORD PTR _n$[ebp], 0
	je	$L66825

; 382  : 			if ((n/sizeof (long)) > 1) {

	mov	ecx, DWORD PTR _n$[ebp]
	shr	ecx, 2
	cmp	ecx, 1
	jbe	SHORT $L66827

; 383  : 			    /*
; 384  : 			     * Align to longword boundary and fill.
; 385  : 			     */
; 386  : 			    for (; n && !isAligned(cp, long); n--)

	jmp	SHORT $L66830
$L66831:
	mov	edx, DWORD PTR _n$[ebp]
	sub	edx, 1
	mov	DWORD PTR _n$[ebp], edx
$L66830:
	cmp	DWORD PTR _n$[ebp], 0
	je	SHORT $L66832
	mov	eax, DWORD PTR _cp$[ebp]
	and	eax, 3
	test	eax, eax
	je	SHORT $L66832

; 387  : 				    *cp++ = 0x00;

	mov	ecx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [ecx], 0
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	jmp	SHORT $L66831
$L66832:

; 388  : 			    lp = (long*) cp;

	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR _lp$[ebp], eax

; 389  : 			    nw = (int32)(n / sizeof (long));

	mov	ecx, DWORD PTR _n$[ebp]
	shr	ecx, 2
	mov	DWORD PTR _nw$[ebp], ecx

; 390  : 			    n -= nw * sizeof (long);

	mov	edx, DWORD PTR _nw$[ebp]
	shl	edx, 2
	mov	eax, DWORD PTR _n$[ebp]
	sub	eax, edx
	mov	DWORD PTR _n$[ebp], eax
$L66837:

; 392  : 				    *lp++ = 0L;

	mov	ecx, DWORD PTR _lp$[ebp]
	mov	DWORD PTR [ecx], 0
	mov	edx, DWORD PTR _lp$[ebp]
	add	edx, 4
	mov	DWORD PTR _lp$[ebp], edx

; 393  : 			    } while (--nw);

	mov	eax, DWORD PTR _nw$[ebp]
	sub	eax, 1
	mov	DWORD PTR _nw$[ebp], eax
	cmp	DWORD PTR _nw$[ebp], 0
	jne	SHORT $L66837

; 394  : 			    cp = (u_char*) lp;

	mov	ecx, DWORD PTR _lp$[ebp]
	mov	DWORD PTR _cp$[ebp], ecx
$L66827:

; 396  : 			ZERO(n, cp);

	mov	edx, DWORD PTR _n$[ebp]
	mov	DWORD PTR -32+[ebp], edx
	mov	eax, DWORD PTR -32+[ebp]
	sub	eax, 1
	mov	DWORD PTR -32+[ebp], eax
	cmp	DWORD PTR -32+[ebp], 6
	ja	SHORT $L66842
	mov	ecx, DWORD PTR -32+[ebp]
	jmp	DWORD PTR $L68206[ecx*4]
$L66845:
	mov	edx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [edx+6], 0
$L66846:
	mov	eax, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [eax+5], 0
$L66847:
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [ecx+4], 0
$L66848:
	mov	edx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [edx+3], 0
$L66849:
	mov	eax, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [eax+2], 0
$L66850:
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [ecx+1], 0
$L66851:
	mov	edx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [edx], 0
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, DWORD PTR _n$[ebp]
	mov	DWORD PTR _cp$[ebp], eax
$L66842:

; 397  : 			run &= 7;

	mov	ecx, DWORD PTR _run$[ebp]
	and	ecx, 7
	mov	DWORD PTR _run$[ebp], ecx
$L66825:

; 399  : 		    if (run)

	cmp	DWORD PTR _run$[ebp], 0
	je	SHORT $L66853

; 400  : 			cp[0] &= 0xff >> run;

	mov	edx, 255				; 000000ffH
	mov	ecx, DWORD PTR _run$[ebp]
	sar	edx, cl
	mov	eax, DWORD PTR _cp$[ebp]
	mov	cl, BYTE PTR [eax]
	and	cl, dl
	mov	edx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [edx], cl
$L66853:

; 401  : 		} else

	jmp	SHORT $L66854
$L66823:

; 402  : 		    cp[0] &= ~(_fillmasks[run]>>bx);

	mov	eax, DWORD PTR _run$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR _?_fillmasks@?1??_TIFFFax3fillruns@@9@9[eax]
	mov	edx, ecx
	mov	ecx, DWORD PTR _bx$[ebp]
	sar	edx, cl
	not	edx
	mov	eax, DWORD PTR _cp$[ebp]
	mov	cl, BYTE PTR [eax]
	and	cl, dl
	mov	edx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [edx], cl
$L66854:

; 403  : 		x += runs[0];

	mov	eax, DWORD PTR _runs$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	add	ecx, DWORD PTR [eax]
	mov	DWORD PTR _x$[ebp], ecx
$L66822:

; 405  : 	    run = runs[1];

	mov	edx, DWORD PTR _runs$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _run$[ebp], eax

; 406  : 	    if (x+run > lastx || run > lastx )

	mov	ecx, DWORD PTR _x$[ebp]
	add	ecx, DWORD PTR _run$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	ja	SHORT $L66856
	mov	edx, DWORD PTR _run$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	jbe	SHORT $L66855
$L66856:

; 407  : 		run = runs[1] = lastx - x;

	mov	eax, DWORD PTR _lastx$[ebp]
	sub	eax, DWORD PTR _x$[ebp]
	mov	ecx, DWORD PTR _runs$[ebp]
	mov	DWORD PTR [ecx+4], eax
	mov	edx, DWORD PTR _runs$[ebp]
	mov	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _run$[ebp], eax
$L66855:

; 408  : 	    if (run) {

	cmp	DWORD PTR _run$[ebp], 0
	je	$L66857

; 409  : 		cp = buf + (x>>3);

	mov	ecx, DWORD PTR _x$[ebp]
	shr	ecx, 3
	mov	edx, DWORD PTR _buf$[ebp]
	add	edx, ecx
	mov	DWORD PTR _cp$[ebp], edx

; 410  : 		bx = x&7;

	mov	eax, DWORD PTR _x$[ebp]
	and	eax, 7
	mov	DWORD PTR _bx$[ebp], eax

; 411  : 		if (run > 8-bx) {

	mov	ecx, 8
	sub	ecx, DWORD PTR _bx$[ebp]
	cmp	DWORD PTR _run$[ebp], ecx
	jbe	$L66858

; 412  : 		    if (bx) {			/* align to byte boundary */

	cmp	DWORD PTR _bx$[ebp], 0
	je	SHORT $L66859

; 413  : 			*cp++ |= 0xff >> bx;

	mov	edx, 255				; 000000ffH
	mov	ecx, DWORD PTR _bx$[ebp]
	sar	edx, cl
	mov	eax, DWORD PTR _cp$[ebp]
	mov	cl, BYTE PTR [eax]
	or	cl, dl
	mov	edx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [edx], cl
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 1
	mov	DWORD PTR _cp$[ebp], eax

; 414  : 			run -= 8-bx;

	mov	ecx, 8
	sub	ecx, DWORD PTR _bx$[ebp]
	mov	edx, DWORD PTR _run$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _run$[ebp], edx
$L66859:

; 416  : 		    if( (n = run>>3) != 0 ) {	/* multiple bytes to fill */

	mov	eax, DWORD PTR _run$[ebp]
	shr	eax, 3
	mov	DWORD PTR _n$[ebp], eax
	cmp	DWORD PTR _n$[ebp], 0
	je	$L66860

; 417  : 			if ((n/sizeof (long)) > 1) {

	mov	ecx, DWORD PTR _n$[ebp]
	shr	ecx, 2
	cmp	ecx, 1
	jbe	SHORT $L66862

; 418  : 			    /*
; 419  : 			     * Align to longword boundary and fill.
; 420  : 			     */
; 421  : 			    for (; n && !isAligned(cp, long); n--)

	jmp	SHORT $L66865
$L66866:
	mov	edx, DWORD PTR _n$[ebp]
	sub	edx, 1
	mov	DWORD PTR _n$[ebp], edx
$L66865:
	cmp	DWORD PTR _n$[ebp], 0
	je	SHORT $L66867
	mov	eax, DWORD PTR _cp$[ebp]
	and	eax, 3
	test	eax, eax
	je	SHORT $L66867

; 422  : 				*cp++ = 0xff;

	mov	ecx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [ecx], 255			; 000000ffH
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	jmp	SHORT $L66866
$L66867:

; 423  : 			    lp = (long*) cp;

	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR _lp$[ebp], eax

; 424  : 			    nw = (int32)(n / sizeof (long));

	mov	ecx, DWORD PTR _n$[ebp]
	shr	ecx, 2
	mov	DWORD PTR _nw$[ebp], ecx

; 425  : 			    n -= nw * sizeof (long);

	mov	edx, DWORD PTR _nw$[ebp]
	shl	edx, 2
	mov	eax, DWORD PTR _n$[ebp]
	sub	eax, edx
	mov	DWORD PTR _n$[ebp], eax
$L66872:

; 427  : 				*lp++ = -1L;

	mov	ecx, DWORD PTR _lp$[ebp]
	mov	DWORD PTR [ecx], -1
	mov	edx, DWORD PTR _lp$[ebp]
	add	edx, 4
	mov	DWORD PTR _lp$[ebp], edx

; 428  : 			    } while (--nw);

	mov	eax, DWORD PTR _nw$[ebp]
	sub	eax, 1
	mov	DWORD PTR _nw$[ebp], eax
	cmp	DWORD PTR _nw$[ebp], 0
	jne	SHORT $L66872

; 429  : 			    cp = (u_char*) lp;

	mov	ecx, DWORD PTR _lp$[ebp]
	mov	DWORD PTR _cp$[ebp], ecx
$L66862:

; 431  : 			FILL(n, cp);

	mov	edx, DWORD PTR _n$[ebp]
	mov	DWORD PTR -36+[ebp], edx
	mov	eax, DWORD PTR -36+[ebp]
	sub	eax, 1
	mov	DWORD PTR -36+[ebp], eax
	cmp	DWORD PTR -36+[ebp], 6
	ja	SHORT $L66877
	mov	ecx, DWORD PTR -36+[ebp]
	jmp	DWORD PTR $L68207[ecx*4]
$L66880:
	mov	edx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [edx+6], 255			; 000000ffH
$L66881:
	mov	eax, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [eax+5], 255			; 000000ffH
$L66882:
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [ecx+4], 255			; 000000ffH
$L66883:
	mov	edx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [edx+3], 255			; 000000ffH
$L66884:
	mov	eax, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [eax+2], 255			; 000000ffH
$L66885:
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [ecx+1], 255			; 000000ffH
$L66886:
	mov	edx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [edx], 255			; 000000ffH
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, DWORD PTR _n$[ebp]
	mov	DWORD PTR _cp$[ebp], eax
$L66877:

; 432  : 			run &= 7;

	mov	ecx, DWORD PTR _run$[ebp]
	and	ecx, 7
	mov	DWORD PTR _run$[ebp], ecx
$L66860:

; 434  : 		    if (run)

	cmp	DWORD PTR _run$[ebp], 0
	je	SHORT $L66888

; 435  : 			cp[0] |= 0xff00 >> run;

	mov	edx, 65280				; 0000ff00H
	mov	ecx, DWORD PTR _run$[ebp]
	sar	edx, cl
	mov	eax, DWORD PTR _cp$[ebp]
	mov	cl, BYTE PTR [eax]
	or	cl, dl
	mov	edx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [edx], cl
$L66888:

; 436  : 		} else

	jmp	SHORT $L66889
$L66858:

; 437  : 		    cp[0] |= _fillmasks[run]>>bx;

	mov	eax, DWORD PTR _run$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR _?_fillmasks@?1??_TIFFFax3fillruns@@9@9[eax]
	mov	edx, ecx
	mov	ecx, DWORD PTR _bx$[ebp]
	sar	edx, cl
	mov	eax, DWORD PTR _cp$[ebp]
	mov	cl, BYTE PTR [eax]
	or	cl, dl
	mov	edx, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [edx], cl
$L66889:

; 438  : 		x += runs[1];

	mov	eax, DWORD PTR _runs$[ebp]
	mov	ecx, DWORD PTR _x$[ebp]
	add	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR _x$[ebp], ecx
$L66857:

; 440  : 	}

	jmp	$L66817
$L66818:

; 441  : 	assert(x == lastx);

	mov	edx, DWORD PTR _x$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	je	SHORT $L68205
	push	441					; 000001b9H
	push	OFFSET FLAT:$SG66891
	push	OFFSET FLAT:$SG66892
	call	__assert
	add	esp, 12					; 0000000cH
$L68205:

; 442  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68206:
	DD	$L66851
	DD	$L66850
	DD	$L66849
	DD	$L66848
	DD	$L66847
	DD	$L66846
	DD	$L66845
$L68207:
	DD	$L66886
	DD	$L66885
	DD	$L66884
	DD	$L66883
	DD	$L66882
	DD	$L66881
	DD	$L66880
__TIFFFax3fillruns ENDP
_TEXT	ENDS
PUBLIC	_TIFFInitCCITTFax3
EXTRN	_TIFFSetField:NEAR
EXTRN	__TIFFMergeFieldInfo:NEAR
_TEXT	SEGMENT
_tif$ = 8
_TIFFInitCCITTFax3 PROC NEAR

; 1331 : {

	push	ebp
	mov	ebp, esp

; 1332 : 	if (InitCCITTFax3(tif)) {

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_InitCCITTFax3
	add	esp, 4
	test	eax, eax
	je	SHORT $L67585

; 1333 : 		_TIFFMergeFieldInfo(tif, fax3FieldInfo, N(fax3FieldInfo));

	push	1
	push	OFFSET FLAT:_fax3FieldInfo
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	__TIFFMergeFieldInfo
	add	esp, 12					; 0000000cH

; 1334 : 
; 1335 : 		/*
; 1336 : 		 * The default format is Class/F-style w/o RTC.
; 1337 : 		 */
; 1338 : 		return TIFFSetField(tif, TIFFTAG_FAXMODE, FAXMODE_CLASSF);

	push	1
	push	65536					; 00010000H
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFSetField
	add	esp, 12					; 0000000cH
	jmp	SHORT $L67586
$L67585:

; 1340 : 		return (0);

	xor	eax, eax
$L67586:

; 1341 : }

	pop	ebp
	ret	0
_TIFFInitCCITTFax3 ENDP
_TEXT	ENDS
EXTRN	__TIFFmalloc:NEAR
EXTRN	_TIFFError:NEAR
_DATA	SEGMENT
	ORG $+1
$SG67568 DB	'%s: No space for state block', 00H
	ORG $+3
$SG67569 DB	'TIFFInitCCITTFax3', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_sp$ = -4
_InitCCITTFax3 PROC NEAR

; 1266 : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 1267 : 	Fax3BaseState* sp;
; 1268 : 
; 1269 : 	/*
; 1270 : 	 * Allocate state block so tag methods have storage to record values.
; 1271 : 	 */
; 1272 : 	if (tif->tif_mode == O_RDONLY)

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+8], 0
	jne	SHORT $L67560

; 1273 : 		tif->tif_data = (tidata_t)
; 1274 :                     _TIFFmalloc(sizeof (Fax3DecodeState));

	push	84					; 00000054H
	call	__TIFFmalloc
	add	esp, 4
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+460], eax

; 1275 : 	else

	jmp	SHORT $L67563
$L67560:

; 1276 : 		tif->tif_data = (tidata_t)
; 1277 :                     _TIFFmalloc(sizeof (Fax3EncodeState));

	push	76					; 0000004cH
	call	__TIFFmalloc
	add	esp, 4
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+460], eax
$L67563:

; 1278 : 
; 1279 : 	if (tif->tif_data == NULL) {

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+460], 0
	jne	SHORT $L67567

; 1280 : 		TIFFError("TIFFInitCCITTFax3",
; 1281 : 		    "%s: No space for state block", tif->tif_name);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	push	OFFSET FLAT:$SG67568
	push	OFFSET FLAT:$SG67569
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 1282 : 		return (0);

	xor	eax, eax
	jmp	$L67558
$L67567:

; 1284 : 
; 1285 : 	sp = Fax3State(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 1286 :         sp->rw_mode = tif->tif_mode;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR [edx], ecx

; 1287 : 
; 1288 : 	/*
; 1289 : 	 * Merge codec-specific tag information and
; 1290 : 	 * override parent get/set field methods.
; 1291 : 	 */
; 1292 : 	_TIFFMergeFieldInfo(tif, faxFieldInfo, N(faxFieldInfo));

	push	10					; 0000000aH
	push	OFFSET FLAT:_faxFieldInfo
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	__TIFFMergeFieldInfo
	add	esp, 12					; 0000000cH

; 1293 : 	sp->vgetparent = tif->tif_vgetfield;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+544]
	mov	DWORD PTR [eax+44], edx

; 1294 : 	tif->tif_vgetfield = Fax3VGetField;	/* hook for codec tags */

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+544], OFFSET FLAT:_Fax3VGetField

; 1295 : 	sp->vsetparent = tif->tif_vsetfield;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+540]
	mov	DWORD PTR [ecx+48], eax

; 1296 : 	tif->tif_vsetfield = Fax3VSetField;	/* hook for codec tags */

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+540], OFFSET FLAT:_Fax3VSetField

; 1297 : 	tif->tif_printdir = Fax3PrintDir;	/* hook for codec tags */

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+548], OFFSET FLAT:_Fax3PrintDir

; 1298 : 	sp->groupoptions = 0;	

	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+28], 0

; 1299 : 	sp->recvparams = 0;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+32], 0

; 1300 : 	sp->subaddress = NULL;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+36], 0

; 1301 : 
; 1302 : 	if (sp->rw_mode == O_RDONLY) {

	mov	eax, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [eax], 0
	jne	SHORT $L67572

; 1303 : 		tif->tif_flags |= TIFF_NOBITREV;/* decoder does bit reversal */

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	or	dh, 1
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+12], edx

; 1304 : 		DecoderState(tif)->runs = NULL;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+460]
	mov	DWORD PTR [edx+72], 0

; 1305 : 		TIFFSetField(tif, TIFFTAG_FAXFILLFUNC, _TIFFFax3fillruns);

	push	OFFSET FLAT:__TIFFFax3fillruns
	push	65540					; 00010004H
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFSetField
	add	esp, 12					; 0000000cH

; 1306 : 	} else

	jmp	SHORT $L67576
$L67572:

; 1307 : 		EncoderState(tif)->refline = NULL;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+460]
	mov	DWORD PTR [edx+64], 0
$L67576:

; 1308 : 
; 1309 : 	/*
; 1310 : 	 * Install codec methods.
; 1311 : 	 */
; 1312 : 	tif->tif_setupdecode = Fax3SetupState;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+396], OFFSET FLAT:_Fax3SetupState

; 1313 : 	tif->tif_predecode = Fax3PreDecode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+400], OFFSET FLAT:_Fax3PreDecode

; 1314 : 	tif->tif_decoderow = Fax3Decode1D;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+416], OFFSET FLAT:_Fax3Decode1D

; 1315 : 	tif->tif_decodestrip = Fax3Decode1D;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+424], OFFSET FLAT:_Fax3Decode1D

; 1316 : 	tif->tif_decodetile = Fax3Decode1D;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+432], OFFSET FLAT:_Fax3Decode1D

; 1317 : 	tif->tif_setupencode = Fax3SetupState;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+404], OFFSET FLAT:_Fax3SetupState

; 1318 : 	tif->tif_preencode = Fax3PreEncode;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+408], OFFSET FLAT:_Fax3PreEncode

; 1319 : 	tif->tif_postencode = Fax3PostEncode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+412], OFFSET FLAT:_Fax3PostEncode

; 1320 : 	tif->tif_encoderow = Fax3Encode;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+420], OFFSET FLAT:_Fax3Encode

; 1321 : 	tif->tif_encodestrip = Fax3Encode;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+428], OFFSET FLAT:_Fax3Encode

; 1322 : 	tif->tif_encodetile = Fax3Encode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+436], OFFSET FLAT:_Fax3Encode

; 1323 : 	tif->tif_close = Fax3Close;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+440], OFFSET FLAT:_Fax3Close

; 1324 : 	tif->tif_cleanup = Fax3Cleanup;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+448], OFFSET FLAT:_Fax3Cleanup

; 1325 : 
; 1326 : 	return (1);

	mov	eax, 1
$L67558:

; 1327 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_InitCCITTFax3 ENDP
_TEXT	ENDS
EXTRN	_TIFFGetBitRevTable:NEAR
_DATA	SEGMENT
	ORG $+2
$SG65910 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_fax3.c', 00H
	ORG $+3
$SG65911 DB	'sp != NULL', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_sp$ = -4
_Fax3PreDecode PROC NEAR

; 151  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 152  : 	Fax3DecodeState* sp = DecoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 153  : 
; 154  : 	(void) s;
; 155  : 	assert(sp != NULL);

	cmp	DWORD PTR _sp$[ebp], 0
	jne	SHORT $L68211
	push	155					; 0000009bH
	push	OFFSET FLAT:$SG65910
	push	OFFSET FLAT:$SG65911
	call	__assert
	add	esp, 12					; 0000000cH
$L68211:

; 156  : 	sp->bit = 0;			/* force initial read */

	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+60], 0

; 157  : 	sp->data = 0;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+56], 0

; 158  : 	sp->EOLcnt = 0;			/* force initial scan for EOL */

	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+64], 0

; 159  : 	/*
; 160  : 	 * Decoder assumes lsb-to-msb bit order.  Note that we select
; 161  : 	 * this here rather than in Fax3SetupState so that viewers can
; 162  : 	 * hold the image open, fiddle with the FillOrder tag value,
; 163  : 	 * and then re-decode the image.  Otherwise they'd need to close
; 164  : 	 * and open the image to get the state reset.
; 165  : 	 */
; 166  : 	sp->bitmap =
; 167  : 	    TIFFGetBitRevTable(tif->tif_dir.td_fillorder != FILLORDER_LSB2MSB);

	mov	eax, DWORD PTR _tif$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+74]
	xor	edx, edx
	cmp	ecx, 2
	setne	dl
	push	edx
	call	_TIFFGetBitRevTable
	add	esp, 4
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+52], eax

; 168  : 	if (sp->refruns) {		/* init reference line to white */

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx+76], 0
	je	SHORT $L65912

; 169  : 		sp->refruns[0] = (uint32) sp->b.rowpixels;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+76]
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR [ecx], eax

; 170  : 		sp->refruns[1] = 0;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+76]
	mov	DWORD PTR [edx+4], 0
$L65912:

; 172  : 	return (1);

	mov	eax, 1

; 173  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Fax3PreDecode ENDP
_TEXT	ENDS
EXTRN	_TIFFFaxWhiteTable:BYTE
EXTRN	_TIFFFaxBlackTable:BYTE
_TEXT	SEGMENT
_tif$ = 8
_buf$ = 12
_occ$ = 16
_sp$ = -20
_a0$ = -48
_lastx$ = -4
_BitAcc$ = -52
_BitsAvail$ = -8
_RunLength$ = -28
_cp$ = -16
_ep$ = -44
_pa$ = -36
_thisrun$ = -40
_EOLcnt$ = -32
_bitmap$ = -12
_TabEnt$ = -24
_Fax3Decode1D PROC NEAR

; 223  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 60					; 0000003cH

; 224  : 	DECLARE_STATE(tif, sp, "Fax3Decode1D");

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR _lastx$[ebp], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+52]
	mov	DWORD PTR _bitmap$[ebp], edx
$L65992:

; 225  : 
; 226  : 	(void) s;
; 227  : 	CACHE_STATE(tif, sp);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+60]
	mov	DWORD PTR _BitsAvail$[ebp], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+64]
	mov	DWORD PTR _EOLcnt$[ebp], edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, DWORD PTR [edx+484]
	mov	DWORD PTR _ep$[ebp], eax
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L65992

; 228  : 	thisrun = sp->curruns;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+80]
	mov	DWORD PTR _thisrun$[ebp], eax
$L65998:

; 229  : 	while ((long)occ > 0) {

	cmp	DWORD PTR _occ$[ebp], 0
	jle	$L65999

; 230  : 		a0 = 0;

	mov	DWORD PTR _a0$[ebp], 0

; 231  : 		RunLength = 0;

	mov	DWORD PTR _RunLength$[ebp], 0

; 232  : 		pa = thisrun;

	mov	ecx, DWORD PTR _thisrun$[ebp]
	mov	DWORD PTR _pa$[ebp], ecx
$L66000:

; 233  : #ifdef FAX3_DEBUG
; 234  : 		printf("\nBitAcc=%08X, BitsAvail = %d\n", BitAcc, BitsAvail);
; 235  : 		printf("-------------------- %d\n", tif->tif_row);
; 236  : 		fflush(stdout);
; 237  : #endif
; 238  : 		SYNC_EOL(EOF1D);

	cmp	DWORD PTR _EOLcnt$[ebp], 0
	jne	$L66006
$L66005:
	cmp	DWORD PTR _BitsAvail$[ebp], 11		; 0000000bH
	jge	$L66018
	mov	edx, DWORD PTR _cp$[ebp]
	cmp	edx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66011
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L66012
	jmp	$EOF1D$66013
$L66012:
	mov	DWORD PTR _BitsAvail$[ebp], 11		; 0000000bH
	jmp	SHORT $L66018
$L66011:
	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _bitmap$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	eax, cl
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	or	ecx, eax
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	add	eax, 8
	mov	DWORD PTR _BitsAvail$[ebp], eax
	cmp	DWORD PTR _BitsAvail$[ebp], 11		; 0000000bH
	jge	SHORT $L66018
	mov	ecx, DWORD PTR _cp$[ebp]
	cmp	ecx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66017
	mov	DWORD PTR _BitsAvail$[ebp], 11		; 0000000bH
	jmp	SHORT $L66018
$L66017:
	mov	edx, DWORD PTR _cp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _bitmap$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L66018:
	xor	eax, eax
	test	eax, eax
	jne	$L66005
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	and	ecx, 2047				; 000007ffH
	test	ecx, ecx
	jne	SHORT $L66020
	jmp	SHORT $L66006
$L66020:
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	sub	edx, 1
	mov	DWORD PTR _BitsAvail$[ebp], edx
	mov	eax, DWORD PTR _BitAcc$[ebp]
	shr	eax, 1
	mov	DWORD PTR _BitAcc$[ebp], eax
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66020
	jmp	$L66005
$L66006:
	cmp	DWORD PTR _BitsAvail$[ebp], 8
	jge	SHORT $L66033
	mov	edx, DWORD PTR _cp$[ebp]
	cmp	edx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66031
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L66032
	jmp	$EOF1D$66013
$L66032:
	mov	DWORD PTR _BitsAvail$[ebp], 8
	jmp	SHORT $L66033
$L66031:
	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _bitmap$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	eax, cl
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	or	ecx, eax
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	add	eax, 8
	mov	DWORD PTR _BitsAvail$[ebp], eax
$L66033:
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66006
	mov	edx, DWORD PTR _BitAcc$[ebp]
	and	edx, 255				; 000000ffH
	test	edx, edx
	je	SHORT $L66035
	jmp	SHORT $L66026
$L66035:
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	sub	eax, 8
	mov	DWORD PTR _BitsAvail$[ebp], eax
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	shr	ecx, 8
	mov	DWORD PTR _BitAcc$[ebp], ecx
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66035
	jmp	SHORT $L66006
$L66026:
	mov	eax, DWORD PTR _BitAcc$[ebp]
	and	eax, 1
	test	eax, eax
	jne	SHORT $L66041
$L66042:
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _BitsAvail$[ebp], ecx
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, 1
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66042
	jmp	SHORT $L66026
$L66041:
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _BitsAvail$[ebp], ecx
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, 1
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66041
	mov	DWORD PTR _EOLcnt$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	$L66000
$L66002:

; 239  : 		EXPAND1D(EOF1Da);

	cmp	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jge	$L66071
	mov	edx, DWORD PTR _cp$[ebp]
	cmp	edx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66064
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L66065
	jmp	$eof1d$66066
$L66065:
	mov	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jmp	SHORT $L66071
$L66064:
	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _bitmap$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	eax, cl
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	or	ecx, eax
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	add	eax, 8
	mov	DWORD PTR _BitsAvail$[ebp], eax
	cmp	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jge	SHORT $L66071
	mov	ecx, DWORD PTR _cp$[ebp]
	cmp	ecx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66070
	mov	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jmp	SHORT $L66071
$L66070:
	mov	edx, DWORD PTR _cp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _bitmap$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L66071:
	xor	eax, eax
	test	eax, eax
	jne	$L66002
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	and	ecx, 4095				; 00000fffH
	lea	edx, DWORD PTR _TIFFFaxWhiteTable[ecx*8]
	mov	DWORD PTR _TabEnt$[ebp], edx
$L66073:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _BitsAvail$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, cl
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66073
	xor	ecx, ecx
	test	ecx, ecx
	jne	$L66002
	mov	edx, DWORD PTR _TabEnt$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	DWORD PTR -56+[ebp], eax
	mov	ecx, DWORD PTR -56+[ebp]
	sub	ecx, 7
	mov	DWORD PTR -56+[ebp], ecx
	cmp	DWORD PTR -56+[ebp], 5
	ja	SHORT $L66088
	mov	edx, DWORD PTR -56+[ebp]
	jmp	DWORD PTR $L68213[edx*4]
$L66080:
	mov	DWORD PTR _EOLcnt$[ebp], 1
	jmp	$done1d$66081
$L66082:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR [eax+4]
	mov	edx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66082
	jmp	SHORT $doneWhite1d$66086
$L66087:
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _a0$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR _RunLength$[ebp], ecx
	jmp	SHORT $L66077
$L66088:
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	push	OFFSET FLAT:_?module@?1??Fax3Decode1D@@9@9
	call	_Fax3Unexpected
	add	esp, 12					; 0000000cH
	jmp	$done1d$66081
$L66077:
	jmp	$L66002
$doneWhite1d$66086:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jl	SHORT $L66089
	jmp	$done1d$66081
$L66089:
	cmp	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jge	$L66106
	mov	edx, DWORD PTR _cp$[ebp]
	cmp	edx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66100
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L66101
	jmp	$eof1d$66066
$L66101:
	mov	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jmp	SHORT $L66106
$L66100:
	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _bitmap$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	eax, cl
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	or	ecx, eax
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	add	eax, 8
	mov	DWORD PTR _BitsAvail$[ebp], eax
	cmp	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jge	SHORT $L66106
	mov	ecx, DWORD PTR _cp$[ebp]
	cmp	ecx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66105
	mov	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jmp	SHORT $L66106
$L66105:
	mov	edx, DWORD PTR _cp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _bitmap$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L66106:
	xor	eax, eax
	test	eax, eax
	jne	$L66089
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	and	ecx, 8191				; 00001fffH
	lea	edx, DWORD PTR _TIFFFaxBlackTable[ecx*8]
	mov	DWORD PTR _TabEnt$[ebp], edx
$L66108:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _BitsAvail$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, cl
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66108
	xor	ecx, ecx
	test	ecx, ecx
	jne	$L66089
	mov	edx, DWORD PTR _TabEnt$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	DWORD PTR -60+[ebp], eax
	mov	ecx, DWORD PTR -60+[ebp]
	sub	ecx, 8
	mov	DWORD PTR -60+[ebp], ecx
	cmp	DWORD PTR -60+[ebp], 4
	ja	SHORT $L66122
	mov	edx, DWORD PTR -60+[ebp]
	jmp	DWORD PTR $L68214[edx*4]
$L66115:
	mov	DWORD PTR _EOLcnt$[ebp], 1
	jmp	$done1d$66081
$L66116:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR [eax+4]
	mov	edx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66116
	jmp	SHORT $doneBlack1d$66120
$L66121:
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _a0$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR _RunLength$[ebp], ecx
	jmp	SHORT $L66112
$L66122:
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	push	OFFSET FLAT:_?module@?1??Fax3Decode1D@@9@9
	call	_Fax3Unexpected
	add	esp, 12					; 0000000cH
	jmp	$done1d$66081
$L66112:
	jmp	$L66089
$doneBlack1d$66120:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jl	SHORT $L66123
	jmp	$done1d$66081
$L66123:
	mov	edx, DWORD PTR _pa$[ebp]
	cmp	DWORD PTR [edx-4], 0
	jne	SHORT $L66124
	mov	eax, DWORD PTR _pa$[ebp]
	cmp	DWORD PTR [eax-8], 0
	jne	SHORT $L66124
	mov	ecx, DWORD PTR _pa$[ebp]
	sub	ecx, 8
	mov	DWORD PTR _pa$[ebp], ecx
$L66124:
	jmp	$L66002
$eof1d$66066:
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	push	OFFSET FLAT:_?module@?1??Fax3Decode1D@@9@9
	call	_Fax3PrematureEOF
	add	esp, 12					; 0000000cH
$L66125:
	cmp	DWORD PTR _RunLength$[ebp], 0
	je	SHORT $L66131
$L66129:
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [ecx], edx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66129
$L66131:
	mov	eax, DWORD PTR _a0$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	je	$L66152
	mov	ecx, DWORD PTR _lastx$[ebp]
	push	ecx
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	push	OFFSET FLAT:_?module@?1??Fax3Decode1D@@9@9
	call	_Fax3BadLength
	add	esp, 16					; 00000010H
$L66134:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jle	SHORT $L66135
	mov	edx, DWORD PTR _pa$[ebp]
	cmp	edx, DWORD PTR _thisrun$[ebp]
	jbe	SHORT $L66135
	mov	eax, DWORD PTR _pa$[ebp]
	sub	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	sub	edx, DWORD PTR [ecx]
	mov	DWORD PTR _a0$[ebp], edx
	jmp	SHORT $L66134
$L66135:
	mov	eax, DWORD PTR _a0$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jge	SHORT $L66136
	cmp	DWORD PTR _a0$[ebp], 0
	jge	SHORT $L66137
	mov	DWORD PTR _a0$[ebp], 0
$L66137:
	mov	ecx, DWORD PTR _pa$[ebp]
	sub	ecx, DWORD PTR _thisrun$[ebp]
	sar	ecx, 2
	and	ecx, 1
	test	ecx, ecx
	je	SHORT $L66141
$L66139:
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66139
$L66141:
	mov	ecx, DWORD PTR _lastx$[ebp]
	sub	ecx, DWORD PTR _a0$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, ecx
	mov	eax, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _lastx$[ebp]
	sub	edx, DWORD PTR _a0$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, edx
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66141
	jmp	SHORT $L66152
$L66136:
	mov	edx, DWORD PTR _a0$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	jle	SHORT $L66152
$L66147:
	mov	eax, DWORD PTR _RunLength$[ebp]
	add	eax, DWORD PTR _lastx$[ebp]
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR _lastx$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66147
$L66149:
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66149
$L66152:
	xor	ecx, ecx
	test	ecx, ecx
	jne	$L66125
	jmp	$EOF1Da$66153
$done1d$66081:
	cmp	DWORD PTR _RunLength$[ebp], 0
	je	SHORT $L66160
$L66158:
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66158
$L66160:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	je	$L66181
	mov	edx, DWORD PTR _lastx$[ebp]
	push	edx
	mov	eax, DWORD PTR _a0$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	push	OFFSET FLAT:_?module@?1??Fax3Decode1D@@9@9
	call	_Fax3BadLength
	add	esp, 16					; 00000010H
$L66163:
	mov	edx, DWORD PTR _a0$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	jle	SHORT $L66164
	mov	eax, DWORD PTR _pa$[ebp]
	cmp	eax, DWORD PTR _thisrun$[ebp]
	jbe	SHORT $L66164
	mov	ecx, DWORD PTR _pa$[ebp]
	sub	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	sub	eax, DWORD PTR [edx]
	mov	DWORD PTR _a0$[ebp], eax
	jmp	SHORT $L66163
$L66164:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jge	SHORT $L66165
	cmp	DWORD PTR _a0$[ebp], 0
	jge	SHORT $L66166
	mov	DWORD PTR _a0$[ebp], 0
$L66166:
	mov	edx, DWORD PTR _pa$[ebp]
	sub	edx, DWORD PTR _thisrun$[ebp]
	sar	edx, 2
	and	edx, 1
	test	edx, edx
	je	SHORT $L66170
$L66168:
	mov	eax, DWORD PTR _pa$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66168
$L66170:
	mov	edx, DWORD PTR _lastx$[ebp]
	sub	edx, DWORD PTR _a0$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	add	eax, edx
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _lastx$[ebp]
	sub	eax, DWORD PTR _a0$[ebp]
	mov	ecx, DWORD PTR _a0$[ebp]
	add	ecx, eax
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66170
	jmp	SHORT $L66181
$L66165:
	mov	eax, DWORD PTR _a0$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jle	SHORT $L66181
$L66176:
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR _lastx$[ebp]
	mov	edx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _a0$[ebp]
	add	ecx, DWORD PTR _lastx$[ebp]
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66176
$L66178:
	mov	eax, DWORD PTR _pa$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66178
$L66181:
	xor	edx, edx
	test	edx, edx
	jne	$done1d$66081
	xor	eax, eax
	test	eax, eax
	jne	$L66002

; 240  : 		(*sp->fill)(buf, thisrun, pa, lastx);

	mov	ecx, DWORD PTR _lastx$[ebp]
	push	ecx
	mov	edx, DWORD PTR _pa$[ebp]
	push	edx
	mov	eax, DWORD PTR _thisrun$[ebp]
	push	eax
	mov	ecx, DWORD PTR _buf$[ebp]
	push	ecx
	mov	edx, DWORD PTR _sp$[ebp]
	call	DWORD PTR [edx+68]
	add	esp, 16					; 00000010H

; 241  : 		buf += sp->b.rowbytes;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _buf$[ebp]
	add	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR _buf$[ebp], ecx

; 242  : 		occ -= sp->b.rowbytes;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _occ$[ebp]
	sub	eax, DWORD PTR [edx+8]
	mov	DWORD PTR _occ$[ebp], eax

; 243  : 		if (occ != 0)

	cmp	DWORD PTR _occ$[ebp], 0
	je	SHORT $L66182

; 244  : 			tif->tif_row++;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	add	edx, 1
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+356], edx
$L66182:

; 245  : 		continue;

	jmp	$L65998
$EOF1D$66013:

; 246  : 	EOF1D:				/* premature EOF */
; 247  : 		CLEANUP_RUNS();

	cmp	DWORD PTR _RunLength$[ebp], 0
	je	SHORT $L66189
$L66187:
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [ecx], edx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66187
$L66189:
	mov	eax, DWORD PTR _a0$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	je	$L66210
	mov	ecx, DWORD PTR _lastx$[ebp]
	push	ecx
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	push	OFFSET FLAT:_?module@?1??Fax3Decode1D@@9@9
	call	_Fax3BadLength
	add	esp, 16					; 00000010H
$L66192:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jle	SHORT $L66193
	mov	edx, DWORD PTR _pa$[ebp]
	cmp	edx, DWORD PTR _thisrun$[ebp]
	jbe	SHORT $L66193
	mov	eax, DWORD PTR _pa$[ebp]
	sub	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	sub	edx, DWORD PTR [ecx]
	mov	DWORD PTR _a0$[ebp], edx
	jmp	SHORT $L66192
$L66193:
	mov	eax, DWORD PTR _a0$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jge	SHORT $L66194
	cmp	DWORD PTR _a0$[ebp], 0
	jge	SHORT $L66195
	mov	DWORD PTR _a0$[ebp], 0
$L66195:
	mov	ecx, DWORD PTR _pa$[ebp]
	sub	ecx, DWORD PTR _thisrun$[ebp]
	sar	ecx, 2
	and	ecx, 1
	test	ecx, ecx
	je	SHORT $L66199
$L66197:
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66197
$L66199:
	mov	ecx, DWORD PTR _lastx$[ebp]
	sub	ecx, DWORD PTR _a0$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, ecx
	mov	eax, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _lastx$[ebp]
	sub	edx, DWORD PTR _a0$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, edx
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66199
	jmp	SHORT $L66210
$L66194:
	mov	edx, DWORD PTR _a0$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	jle	SHORT $L66210
$L66205:
	mov	eax, DWORD PTR _RunLength$[ebp]
	add	eax, DWORD PTR _lastx$[ebp]
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR _lastx$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66205
$L66207:
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66207
$L66210:
	xor	ecx, ecx
	test	ecx, ecx
	jne	$EOF1D$66013
$EOF1Da$66153:

; 248  : 	EOF1Da:				/* premature EOF */
; 249  : 		(*sp->fill)(buf, thisrun, pa, lastx);

	mov	edx, DWORD PTR _lastx$[ebp]
	push	edx
	mov	eax, DWORD PTR _pa$[ebp]
	push	eax
	mov	ecx, DWORD PTR _thisrun$[ebp]
	push	ecx
	mov	edx, DWORD PTR _buf$[ebp]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	call	DWORD PTR [eax+68]
	add	esp, 16					; 00000010H
$L66211:

; 250  : 		UNCACHE_STATE(tif, sp);

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	mov	DWORD PTR [ecx+60], edx
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	mov	DWORD PTR [eax+56], ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _EOLcnt$[ebp]
	mov	DWORD PTR [edx+64], eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	sub	edx, DWORD PTR [ecx+480]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+484]
	sub	ecx, edx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], ecx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax+480], ecx
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66211

; 251  : 		return (-1);

	or	eax, -1
	jmp	SHORT $L65973
$L65999:

; 253  : 	UNCACHE_STATE(tif, sp);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	mov	DWORD PTR [eax+60], ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _BitAcc$[ebp]
	mov	DWORD PTR [edx+56], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _EOLcnt$[ebp]
	mov	DWORD PTR [ecx+64], edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	sub	ecx, DWORD PTR [eax+480]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+484]
	sub	eax, ecx
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+484], eax
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx+480], eax
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L65999

; 254  : 	return (1);

	mov	eax, 1
$L65973:

; 255  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68213:
	DD	$L66082
	DD	$L66088
	DD	$L66087
	DD	$L66088
	DD	$L66087
	DD	$L66080
$L68214:
	DD	$L66116
	DD	$L66122
	DD	$L66121
	DD	$L66121
	DD	$L66115
_Fax3Decode1D ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+1
$SG65923 DB	'%s: Bad code word at scanline %d (x %lu)', 00H
_DATA	ENDS
_TEXT	SEGMENT
_module$ = 8
_tif$ = 12
_a0$ = 16
_Fax3Unexpected PROC NEAR

; 183  : {

	push	ebp
	mov	ebp, esp

; 184  : 	TIFFError(module, "%s: Bad code word at scanline %d (x %lu)",
; 185  : 	    tif->tif_name, tif->tif_row, (u_long) a0);

	mov	eax, DWORD PTR _a0$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG65923
	mov	edx, DWORD PTR _module$[ebp]
	push	edx
	call	_TIFFError
	add	esp, 20					; 00000014H

; 186  : }

	pop	ebp
	ret	0
_Fax3Unexpected ENDP
_TEXT	ENDS
EXTRN	_TIFFWarning:NEAR
_DATA	SEGMENT
	ORG $+3
$SG65948 DB	'Premature EOL', 00H
	ORG $+2
$SG65949 DB	'Line length mismatch', 00H
	ORG $+3
$SG65950 DB	'%s: %s at scanline %d (got %lu, expected %lu)', 00H
_DATA	ENDS
_TEXT	SEGMENT
_module$ = 8
_tif$ = 12
_a0$ = 16
_lastx$ = 20
_Fax3BadLength PROC NEAR

; 200  : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 201  : 	TIFFWarning(module, "%s: %s at scanline %d (got %lu, expected %lu)",
; 202  : 	    tif->tif_name,
; 203  : 	    a0 < lastx ? "Premature EOL" : "Line length mismatch",
; 204  : 	    tif->tif_row, (u_long) a0, (u_long) lastx);

	mov	eax, DWORD PTR _a0$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jae	SHORT $L68217
	mov	DWORD PTR -4+[ebp], OFFSET FLAT:$SG65948
	jmp	SHORT $L68218
$L68217:
	mov	DWORD PTR -4+[ebp], OFFSET FLAT:$SG65949
$L68218:
	mov	ecx, DWORD PTR _lastx$[ebp]
	push	ecx
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+356]
	push	ecx
	mov	edx, DWORD PTR -4+[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG65950
	mov	edx, DWORD PTR _module$[ebp]
	push	edx
	call	_TIFFWarning
	add	esp, 28					; 0000001cH

; 205  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Fax3BadLength ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+2
$SG65961 DB	'%s: Premature EOF at scanline %d (x %lu)', 00H
_DATA	ENDS
_TEXT	SEGMENT
_module$ = 8
_tif$ = 12
_a0$ = 16
_Fax3PrematureEOF PROC NEAR

; 210  : {

	push	ebp
	mov	ebp, esp

; 211  : 	TIFFWarning(module, "%s: Premature EOF at scanline %d (x %lu)",
; 212  : 	    tif->tif_name, tif->tif_row, (u_long) a0);

	mov	eax, DWORD PTR _a0$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG65961
	mov	edx, DWORD PTR _module$[ebp]
	push	edx
	call	_TIFFWarning
	add	esp, 20					; 00000014H

; 213  : }

	pop	ebp
	ret	0
_Fax3PrematureEOF ENDP
_TEXT	ENDS
EXTRN	_TIFFScanlineSize:NEAR
EXTRN	_TIFFTileRowSize:NEAR
_DATA	SEGMENT
	ORG $+3
$SG66904 DB	'Bits/sample must be 1 for Group 3/4 encoding/decoding', 00H
	ORG $+2
$SG66922 DB	'%s: No space for Group 3/4 run arrays', 00H
	ORG $+2
$SG66923 DB	'Fax3SetupState', 00H
	ORG $+1
$SG66936 DB	'%s: No space for Group 3/4 reference line', 00H
	ORG $+2
$SG66937 DB	'Fax3SetupState', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_td$ = -20
_sp$ = -8
_rowbytes$ = -16
_rowpixels$ = -4
_needsRefLine$ = -12
_dsp$66910 = -24
_nruns$66913 = -28
_esp$66930 = -32
_Fax3SetupState PROC NEAR

; 455  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 40					; 00000028H

; 456  : 	TIFFDirectory* td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 457  : 	Fax3BaseState* sp = Fax3State(tif);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+460]
	mov	DWORD PTR _sp$[ebp], edx

; 458  : 	long rowbytes, rowpixels;
; 459  : 	int needsRefLine;
; 460  : 
; 461  : 	if (td->td_bitspersample != 1) {

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+40]
	cmp	ecx, 1
	je	SHORT $L66903

; 462  : 		TIFFError(tif->tif_name,
; 463  : 		    "Bits/sample must be 1 for Group 3/4 encoding/decoding");

	push	OFFSET FLAT:$SG66904
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_TIFFError
	add	esp, 8

; 464  : 		return (0);

	xor	eax, eax
	jmp	$L66896
$L66903:

; 466  : 	/*
; 467  : 	 * Calculate the scanline/tile widths.
; 468  : 	 */
; 469  : 	if (isTiled(tif)) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 1024				; 00000400H
	test	edx, edx
	je	SHORT $L66905

; 470  : 		rowbytes = TIFFTileRowSize(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFTileRowSize
	add	esp, 4
	mov	DWORD PTR _rowbytes$[ebp], eax

; 471  : 		rowpixels = td->td_tilewidth;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	mov	DWORD PTR _rowpixels$[ebp], edx

; 472  : 	} else {

	jmp	SHORT $L66906
$L66905:

; 473  : 		rowbytes = TIFFScanlineSize(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFScanlineSize
	add	esp, 4
	mov	DWORD PTR _rowbytes$[ebp], eax

; 474  : 		rowpixels = td->td_imagewidth;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	mov	DWORD PTR _rowpixels$[ebp], edx
$L66906:

; 476  : 	sp->rowbytes = (uint32) rowbytes;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _rowbytes$[ebp]
	mov	DWORD PTR [eax+8], ecx

; 477  : 	sp->rowpixels = (uint32) rowpixels;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _rowpixels$[ebp]
	mov	DWORD PTR [edx+12], eax

; 478  : 	/*
; 479  : 	 * Allocate any additional space required for decoding/encoding.
; 480  : 	 */
; 481  : 	needsRefLine = (
; 482  : 	    (sp->groupoptions & GROUP3OPT_2DENCODING) ||
; 483  : 	    td->td_compression == COMPRESSION_CCITTFAX4
; 484  : 	);

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	and	edx, 1
	test	edx, edx
	jne	SHORT $L68221
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+44]
	cmp	ecx, 4
	je	SHORT $L68221
	mov	DWORD PTR -36+[ebp], 0
	jmp	SHORT $L68222
$L68221:
	mov	DWORD PTR -36+[ebp], 1
$L68222:
	mov	edx, DWORD PTR -36+[ebp]
	mov	DWORD PTR _needsRefLine$[ebp], edx

; 485  : 	if (sp->rw_mode == O_RDONLY) {	/* 1d/2d decoding */

	mov	eax, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [eax], 0
	jne	$L66909

; 486  : 		Fax3DecodeState* dsp = DecoderState(tif);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+460]
	mov	DWORD PTR _dsp$66910[ebp], edx

; 487  : 		uint32 nruns = needsRefLine ?
; 488  : 		     2*TIFFroundup(rowpixels,32) : rowpixels;

	cmp	DWORD PTR _needsRefLine$[ebp], 0
	je	SHORT $L68223
	mov	eax, DWORD PTR _rowpixels$[ebp]
	add	eax, 31					; 0000001fH
	shr	eax, 5
	shl	eax, 5
	shl	eax, 1
	mov	DWORD PTR -40+[ebp], eax
	jmp	SHORT $L68224
$L68223:
	mov	ecx, DWORD PTR _rowpixels$[ebp]
	mov	DWORD PTR -40+[ebp], ecx
$L68224:
	mov	edx, DWORD PTR -40+[ebp]
	mov	DWORD PTR _nruns$66913[ebp], edx

; 489  : 
; 490  : 		dsp->runs = (uint32*) _TIFFmalloc((2*nruns+3)*sizeof (uint32));

	mov	eax, DWORD PTR _nruns$66913[ebp]
	shl	eax, 1
	lea	ecx, DWORD PTR [eax*4+12]
	push	ecx
	call	__TIFFmalloc
	add	esp, 4
	mov	edx, DWORD PTR _dsp$66910[ebp]
	mov	DWORD PTR [edx+72], eax

; 491  : 		if (dsp->runs == NULL) {

	mov	eax, DWORD PTR _dsp$66910[ebp]
	cmp	DWORD PTR [eax+72], 0
	jne	SHORT $L66921

; 492  : 			TIFFError("Fax3SetupState",
; 493  : 			    "%s: No space for Group 3/4 run arrays",
; 494  : 			    tif->tif_name);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	push	OFFSET FLAT:$SG66922
	push	OFFSET FLAT:$SG66923
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 495  : 			return (0);

	xor	eax, eax
	jmp	$L66896
$L66921:

; 497  : 		dsp->curruns = dsp->runs;

	mov	eax, DWORD PTR _dsp$66910[ebp]
	mov	ecx, DWORD PTR _dsp$66910[ebp]
	mov	edx, DWORD PTR [ecx+72]
	mov	DWORD PTR [eax+80], edx

; 498  : 		if (needsRefLine)

	cmp	DWORD PTR _needsRefLine$[ebp], 0
	je	SHORT $L66924

; 499  : 			dsp->refruns = dsp->runs + (nruns>>1);

	mov	eax, DWORD PTR _nruns$66913[ebp]
	shr	eax, 1
	mov	ecx, DWORD PTR _dsp$66910[ebp]
	mov	edx, DWORD PTR [ecx+72]
	lea	eax, DWORD PTR [edx+eax*4]
	mov	ecx, DWORD PTR _dsp$66910[ebp]
	mov	DWORD PTR [ecx+76], eax

; 500  : 		else

	jmp	SHORT $L66925
$L66924:

; 501  : 			dsp->refruns = NULL;

	mov	edx, DWORD PTR _dsp$66910[ebp]
	mov	DWORD PTR [edx+76], 0
$L66925:

; 502  : 		if (is2DEncoding(dsp)) {	/* NB: default is 1D routine */

	mov	eax, DWORD PTR _dsp$66910[ebp]
	mov	ecx, DWORD PTR [eax+28]
	and	ecx, 1
	test	ecx, ecx
	je	SHORT $L66927

; 503  : 			tif->tif_decoderow = Fax3Decode2D;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+416], OFFSET FLAT:_Fax3Decode2D

; 504  : 			tif->tif_decodestrip = Fax3Decode2D;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+424], OFFSET FLAT:_Fax3Decode2D

; 505  : 			tif->tif_decodetile = Fax3Decode2D;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+432], OFFSET FLAT:_Fax3Decode2D
$L66927:

; 507  : 	} else if (needsRefLine) {		/* 2d encoding */

	jmp	SHORT $L66938
$L66909:
	cmp	DWORD PTR _needsRefLine$[ebp], 0
	je	SHORT $L66929

; 508  : 		Fax3EncodeState* esp = EncoderState(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+460]
	mov	DWORD PTR _esp$66930[ebp], eax

; 509  : 		/*
; 510  : 		 * 2d encoding requires a scanline
; 511  : 		 * buffer for the ``reference line''; the
; 512  : 		 * scanline against which delta encoding
; 513  : 		 * is referenced.  The reference line must
; 514  : 		 * be initialized to be ``white'' (done elsewhere).
; 515  : 		 */
; 516  : 		esp->refline = (u_char*) _TIFFmalloc(rowbytes);

	mov	ecx, DWORD PTR _rowbytes$[ebp]
	push	ecx
	call	__TIFFmalloc
	add	esp, 4
	mov	edx, DWORD PTR _esp$66930[ebp]
	mov	DWORD PTR [edx+64], eax

; 517  : 		if (esp->refline == NULL) {

	mov	eax, DWORD PTR _esp$66930[ebp]
	cmp	DWORD PTR [eax+64], 0
	jne	SHORT $L66935

; 518  : 			TIFFError("Fax3SetupState",
; 519  : 			    "%s: No space for Group 3/4 reference line",
; 520  : 			    tif->tif_name);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	push	OFFSET FLAT:$SG66936
	push	OFFSET FLAT:$SG66937
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 521  : 			return (0);

	xor	eax, eax
	jmp	SHORT $L66896
$L66935:

; 523  : 	} else					/* 1d encoding */

	jmp	SHORT $L66938
$L66929:

; 524  : 		EncoderState(tif)->refline = NULL;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR [ecx+64], 0
$L66938:

; 525  : 	return (1);

	mov	eax, 1
$L66896:

; 526  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Fax3SetupState ENDP
_TEXT	ENDS
EXTRN	_TIFFFaxMainTable:BYTE
_TEXT	SEGMENT
_x$66755 = -68
_tif$ = 8
_buf$ = 12
_occ$ = 16
_sp$ = -20
_a0$ = -56
_lastx$ = -4
_BitAcc$ = -60
_BitsAvail$ = -8
_RunLength$ = -28
_cp$ = -16
_ep$ = -52
_pa$ = -40
_thisrun$ = -48
_EOLcnt$ = -32
_bitmap$ = -12
_TabEnt$ = -24
_b1$ = -64
_pb$ = -44
_is1D$ = -36
_Fax3Decode2D PROC NEAR

; 263  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 96					; 00000060H

; 264  : 	DECLARE_STATE_2D(tif, sp, "Fax3Decode2D");

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR _lastx$[ebp], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+52]
	mov	DWORD PTR _bitmap$[ebp], edx
$L66253:

; 265  : 	int is1D;			/* current line is 1d/2d-encoded */
; 266  : 
; 267  : 	(void) s;
; 268  : 	CACHE_STATE(tif, sp);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+60]
	mov	DWORD PTR _BitsAvail$[ebp], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+64]
	mov	DWORD PTR _EOLcnt$[ebp], edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, DWORD PTR [edx+484]
	mov	DWORD PTR _ep$[ebp], eax
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66253
$L66255:

; 269  : 	while ((long)occ > 0) {

	cmp	DWORD PTR _occ$[ebp], 0
	jle	$L66260

; 270  : 		a0 = 0;

	mov	DWORD PTR _a0$[ebp], 0

; 271  : 		RunLength = 0;

	mov	DWORD PTR _RunLength$[ebp], 0

; 272  : 		pa = thisrun = sp->curruns;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+80]
	mov	DWORD PTR _thisrun$[ebp], eax
	mov	ecx, DWORD PTR _thisrun$[ebp]
	mov	DWORD PTR _pa$[ebp], ecx
$L66261:

; 273  : #ifdef FAX3_DEBUG
; 274  : 		printf("\nBitAcc=%08X, BitsAvail = %d EOLcnt = %d",
; 275  : 		    BitAcc, BitsAvail, EOLcnt);
; 276  : #endif
; 277  : 		SYNC_EOL(EOF2D);

	cmp	DWORD PTR _EOLcnt$[ebp], 0
	jne	$L66267
$L66266:
	cmp	DWORD PTR _BitsAvail$[ebp], 11		; 0000000bH
	jge	$L66279
	mov	edx, DWORD PTR _cp$[ebp]
	cmp	edx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66272
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L66273
	jmp	$EOF2D$66274
$L66273:
	mov	DWORD PTR _BitsAvail$[ebp], 11		; 0000000bH
	jmp	SHORT $L66279
$L66272:
	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _bitmap$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	eax, cl
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	or	ecx, eax
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	add	eax, 8
	mov	DWORD PTR _BitsAvail$[ebp], eax
	cmp	DWORD PTR _BitsAvail$[ebp], 11		; 0000000bH
	jge	SHORT $L66279
	mov	ecx, DWORD PTR _cp$[ebp]
	cmp	ecx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66278
	mov	DWORD PTR _BitsAvail$[ebp], 11		; 0000000bH
	jmp	SHORT $L66279
$L66278:
	mov	edx, DWORD PTR _cp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _bitmap$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L66279:
	xor	eax, eax
	test	eax, eax
	jne	$L66266
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	and	ecx, 2047				; 000007ffH
	test	ecx, ecx
	jne	SHORT $L66281
	jmp	SHORT $L66267
$L66281:
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	sub	edx, 1
	mov	DWORD PTR _BitsAvail$[ebp], edx
	mov	eax, DWORD PTR _BitAcc$[ebp]
	shr	eax, 1
	mov	DWORD PTR _BitAcc$[ebp], eax
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66281
	jmp	$L66266
$L66267:
	cmp	DWORD PTR _BitsAvail$[ebp], 8
	jge	SHORT $L66294
	mov	edx, DWORD PTR _cp$[ebp]
	cmp	edx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66292
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L66293
	jmp	$EOF2D$66274
$L66293:
	mov	DWORD PTR _BitsAvail$[ebp], 8
	jmp	SHORT $L66294
$L66292:
	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _bitmap$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	eax, cl
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	or	ecx, eax
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	add	eax, 8
	mov	DWORD PTR _BitsAvail$[ebp], eax
$L66294:
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66267
	mov	edx, DWORD PTR _BitAcc$[ebp]
	and	edx, 255				; 000000ffH
	test	edx, edx
	je	SHORT $L66296
	jmp	SHORT $L66287
$L66296:
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	sub	eax, 8
	mov	DWORD PTR _BitsAvail$[ebp], eax
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	shr	ecx, 8
	mov	DWORD PTR _BitAcc$[ebp], ecx
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66296
	jmp	SHORT $L66267
$L66287:
	mov	eax, DWORD PTR _BitAcc$[ebp]
	and	eax, 1
	test	eax, eax
	jne	SHORT $L66302
$L66303:
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _BitsAvail$[ebp], ecx
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, 1
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66303
	jmp	SHORT $L66287
$L66302:
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _BitsAvail$[ebp], ecx
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, 1
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66302
	mov	DWORD PTR _EOLcnt$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	$L66261
$L66263:

; 278  : 		NeedBits8(1, EOF2D);

	cmp	DWORD PTR _BitsAvail$[ebp], 1
	jge	SHORT $L66315
	mov	edx, DWORD PTR _cp$[ebp]
	cmp	edx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66313
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L66314
	jmp	$EOF2D$66274
$L66314:
	mov	DWORD PTR _BitsAvail$[ebp], 1
	jmp	SHORT $L66315
$L66313:
	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _bitmap$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	eax, cl
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	or	ecx, eax
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	add	eax, 8
	mov	DWORD PTR _BitsAvail$[ebp], eax
$L66315:
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66263

; 279  : 		is1D = GetBits(1);	/* 1D/2D-encoding tag bit */

	mov	edx, DWORD PTR _BitAcc$[ebp]
	and	edx, 1
	mov	DWORD PTR _is1D$[ebp], edx
$L66317:

; 280  : 		ClrBits(1);

	mov	eax, DWORD PTR _BitsAvail$[ebp]
	sub	eax, 1
	mov	DWORD PTR _BitsAvail$[ebp], eax
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	shr	ecx, 1
	mov	DWORD PTR _BitAcc$[ebp], ecx
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66317

; 281  : #ifdef FAX3_DEBUG
; 282  : 		printf(" %s\n-------------------- %d\n",
; 283  : 		    is1D ? "1D" : "2D", tif->tif_row);
; 284  : 		fflush(stdout);
; 285  : #endif
; 286  : 		pb = sp->refruns;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+76]
	mov	DWORD PTR _pb$[ebp], ecx

; 287  : 		b1 = *pb++;

	mov	edx, DWORD PTR _pb$[ebp]
	mov	eax, DWORD PTR [edx]
	mov	DWORD PTR _b1$[ebp], eax
	mov	ecx, DWORD PTR _pb$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pb$[ebp], ecx

; 288  : 		if (is1D)

	cmp	DWORD PTR _is1D$[ebp], 0
	je	$L66320
$L66321:

; 289  : 			EXPAND1D(EOF2Da);

	cmp	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jge	$L66344
	mov	edx, DWORD PTR _cp$[ebp]
	cmp	edx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66337
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L66338
	jmp	$eof1d$66339
$L66338:
	mov	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jmp	SHORT $L66344
$L66337:
	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _bitmap$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	eax, cl
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	or	ecx, eax
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	add	eax, 8
	mov	DWORD PTR _BitsAvail$[ebp], eax
	cmp	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jge	SHORT $L66344
	mov	ecx, DWORD PTR _cp$[ebp]
	cmp	ecx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66343
	mov	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jmp	SHORT $L66344
$L66343:
	mov	edx, DWORD PTR _cp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _bitmap$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L66344:
	xor	eax, eax
	test	eax, eax
	jne	$L66321
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	and	ecx, 4095				; 00000fffH
	lea	edx, DWORD PTR _TIFFFaxWhiteTable[ecx*8]
	mov	DWORD PTR _TabEnt$[ebp], edx
$L66346:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _BitsAvail$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, cl
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66346
	xor	ecx, ecx
	test	ecx, ecx
	jne	$L66321
	mov	edx, DWORD PTR _TabEnt$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	DWORD PTR -72+[ebp], eax
	mov	ecx, DWORD PTR -72+[ebp]
	sub	ecx, 7
	mov	DWORD PTR -72+[ebp], ecx
	cmp	DWORD PTR -72+[ebp], 5
	ja	SHORT $L66361
	mov	edx, DWORD PTR -72+[ebp]
	jmp	DWORD PTR $L68226[edx*4]
$L66353:
	mov	DWORD PTR _EOLcnt$[ebp], 1
	jmp	$done1d$66354
$L66355:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR [eax+4]
	mov	edx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66355
	jmp	SHORT $doneWhite1d$66359
$L66360:
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _a0$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR _RunLength$[ebp], ecx
	jmp	SHORT $L66350
$L66361:
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	push	OFFSET FLAT:_?module@?1??Fax3Decode2D@@9@9
	call	_Fax3Unexpected
	add	esp, 12					; 0000000cH
	jmp	$done1d$66354
$L66350:
	jmp	$L66321
$doneWhite1d$66359:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jl	SHORT $L66362
	jmp	$done1d$66354
$L66362:
	cmp	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jge	$L66379
	mov	edx, DWORD PTR _cp$[ebp]
	cmp	edx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66373
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L66374
	jmp	$eof1d$66339
$L66374:
	mov	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jmp	SHORT $L66379
$L66373:
	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _bitmap$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	eax, cl
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	or	ecx, eax
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	add	eax, 8
	mov	DWORD PTR _BitsAvail$[ebp], eax
	cmp	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jge	SHORT $L66379
	mov	ecx, DWORD PTR _cp$[ebp]
	cmp	ecx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66378
	mov	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jmp	SHORT $L66379
$L66378:
	mov	edx, DWORD PTR _cp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _bitmap$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L66379:
	xor	eax, eax
	test	eax, eax
	jne	$L66362
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	and	ecx, 8191				; 00001fffH
	lea	edx, DWORD PTR _TIFFFaxBlackTable[ecx*8]
	mov	DWORD PTR _TabEnt$[ebp], edx
$L66381:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _BitsAvail$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, cl
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66381
	xor	ecx, ecx
	test	ecx, ecx
	jne	$L66362
	mov	edx, DWORD PTR _TabEnt$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	DWORD PTR -76+[ebp], eax
	mov	ecx, DWORD PTR -76+[ebp]
	sub	ecx, 8
	mov	DWORD PTR -76+[ebp], ecx
	cmp	DWORD PTR -76+[ebp], 4
	ja	SHORT $L66395
	mov	edx, DWORD PTR -76+[ebp]
	jmp	DWORD PTR $L68227[edx*4]
$L66388:
	mov	DWORD PTR _EOLcnt$[ebp], 1
	jmp	$done1d$66354
$L66389:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR [eax+4]
	mov	edx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66389
	jmp	SHORT $doneBlack1d$66393
$L66394:
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _a0$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR _RunLength$[ebp], ecx
	jmp	SHORT $L66385
$L66395:
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	push	OFFSET FLAT:_?module@?1??Fax3Decode2D@@9@9
	call	_Fax3Unexpected
	add	esp, 12					; 0000000cH
	jmp	$done1d$66354
$L66385:
	jmp	$L66362
$doneBlack1d$66393:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jl	SHORT $L66396
	jmp	$done1d$66354
$L66396:
	mov	edx, DWORD PTR _pa$[ebp]
	cmp	DWORD PTR [edx-4], 0
	jne	SHORT $L66397
	mov	eax, DWORD PTR _pa$[ebp]
	cmp	DWORD PTR [eax-8], 0
	jne	SHORT $L66397
	mov	ecx, DWORD PTR _pa$[ebp]
	sub	ecx, 8
	mov	DWORD PTR _pa$[ebp], ecx
$L66397:
	jmp	$L66321
$eof1d$66339:
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	push	OFFSET FLAT:_?module@?1??Fax3Decode2D@@9@9
	call	_Fax3PrematureEOF
	add	esp, 12					; 0000000cH
$L66398:
	cmp	DWORD PTR _RunLength$[ebp], 0
	je	SHORT $L66404
$L66402:
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [ecx], edx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66402
$L66404:
	mov	eax, DWORD PTR _a0$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	je	$L66425
	mov	ecx, DWORD PTR _lastx$[ebp]
	push	ecx
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	push	OFFSET FLAT:_?module@?1??Fax3Decode2D@@9@9
	call	_Fax3BadLength
	add	esp, 16					; 00000010H
$L66407:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jle	SHORT $L66408
	mov	edx, DWORD PTR _pa$[ebp]
	cmp	edx, DWORD PTR _thisrun$[ebp]
	jbe	SHORT $L66408
	mov	eax, DWORD PTR _pa$[ebp]
	sub	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	sub	edx, DWORD PTR [ecx]
	mov	DWORD PTR _a0$[ebp], edx
	jmp	SHORT $L66407
$L66408:
	mov	eax, DWORD PTR _a0$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jge	SHORT $L66409
	cmp	DWORD PTR _a0$[ebp], 0
	jge	SHORT $L66410
	mov	DWORD PTR _a0$[ebp], 0
$L66410:
	mov	ecx, DWORD PTR _pa$[ebp]
	sub	ecx, DWORD PTR _thisrun$[ebp]
	sar	ecx, 2
	and	ecx, 1
	test	ecx, ecx
	je	SHORT $L66414
$L66412:
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66412
$L66414:
	mov	ecx, DWORD PTR _lastx$[ebp]
	sub	ecx, DWORD PTR _a0$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, ecx
	mov	eax, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _lastx$[ebp]
	sub	edx, DWORD PTR _a0$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, edx
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66414
	jmp	SHORT $L66425
$L66409:
	mov	edx, DWORD PTR _a0$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	jle	SHORT $L66425
$L66420:
	mov	eax, DWORD PTR _RunLength$[ebp]
	add	eax, DWORD PTR _lastx$[ebp]
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR _lastx$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66420
$L66422:
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66422
$L66425:
	xor	ecx, ecx
	test	ecx, ecx
	jne	$L66398
	jmp	$EOF2Da$66426
$done1d$66354:
	cmp	DWORD PTR _RunLength$[ebp], 0
	je	SHORT $L66433
$L66431:
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66431
$L66433:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	je	$L66454
	mov	edx, DWORD PTR _lastx$[ebp]
	push	edx
	mov	eax, DWORD PTR _a0$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	push	OFFSET FLAT:_?module@?1??Fax3Decode2D@@9@9
	call	_Fax3BadLength
	add	esp, 16					; 00000010H
$L66436:
	mov	edx, DWORD PTR _a0$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	jle	SHORT $L66437
	mov	eax, DWORD PTR _pa$[ebp]
	cmp	eax, DWORD PTR _thisrun$[ebp]
	jbe	SHORT $L66437
	mov	ecx, DWORD PTR _pa$[ebp]
	sub	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	sub	eax, DWORD PTR [edx]
	mov	DWORD PTR _a0$[ebp], eax
	jmp	SHORT $L66436
$L66437:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jge	SHORT $L66438
	cmp	DWORD PTR _a0$[ebp], 0
	jge	SHORT $L66439
	mov	DWORD PTR _a0$[ebp], 0
$L66439:
	mov	edx, DWORD PTR _pa$[ebp]
	sub	edx, DWORD PTR _thisrun$[ebp]
	sar	edx, 2
	and	edx, 1
	test	edx, edx
	je	SHORT $L66443
$L66441:
	mov	eax, DWORD PTR _pa$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66441
$L66443:
	mov	edx, DWORD PTR _lastx$[ebp]
	sub	edx, DWORD PTR _a0$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	add	eax, edx
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _lastx$[ebp]
	sub	eax, DWORD PTR _a0$[ebp]
	mov	ecx, DWORD PTR _a0$[ebp]
	add	ecx, eax
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66443
	jmp	SHORT $L66454
$L66438:
	mov	eax, DWORD PTR _a0$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jle	SHORT $L66454
$L66449:
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR _lastx$[ebp]
	mov	edx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _a0$[ebp]
	add	ecx, DWORD PTR _lastx$[ebp]
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66449
$L66451:
	mov	eax, DWORD PTR _pa$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66451
$L66454:
	xor	edx, edx
	test	edx, edx
	jne	$done1d$66354
	xor	eax, eax
	test	eax, eax
	jne	$L66321

; 290  : 		else

	jmp	$L66458
$L66320:

; 291  : 			EXPAND2D(EOF2Da);

	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jge	$L66461
$L66462:
	cmp	DWORD PTR _BitsAvail$[ebp], 7
	jge	SHORT $L66472
	mov	edx, DWORD PTR _cp$[ebp]
	cmp	edx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66469
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L66470
	jmp	$eof2d$66471
$L66470:
	mov	DWORD PTR _BitsAvail$[ebp], 7
	jmp	SHORT $L66472
$L66469:
	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _bitmap$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	eax, cl
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	or	ecx, eax
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	add	eax, 8
	mov	DWORD PTR _BitsAvail$[ebp], eax
$L66472:
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66462
	mov	edx, DWORD PTR _BitAcc$[ebp]
	and	edx, 127				; 0000007fH
	lea	eax, DWORD PTR _TIFFFaxMainTable[edx*8]
	mov	DWORD PTR _TabEnt$[ebp], eax
$L66474:
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	sub	eax, edx
	mov	DWORD PTR _BitsAvail$[ebp], eax
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	mov	ecx, edx
	mov	eax, DWORD PTR _BitAcc$[ebp]
	shr	eax, cl
	mov	DWORD PTR _BitAcc$[ebp], eax
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66474
	xor	edx, edx
	test	edx, edx
	jne	$L66462
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	DWORD PTR -80+[ebp], ecx
	mov	edx, DWORD PTR -80+[ebp]
	sub	edx, 1
	mov	DWORD PTR -80+[ebp], edx
	cmp	DWORD PTR -80+[ebp], 11			; 0000000bH
	ja	$badMain2d$66678
	mov	eax, DWORD PTR -80+[ebp]
	jmp	DWORD PTR $L68228[eax*4]
$L66481:
	mov	ecx, DWORD PTR _pa$[ebp]
	cmp	ecx, DWORD PTR _thisrun$[ebp]
	je	SHORT $L66488
$L66487:
	mov	edx, DWORD PTR _b1$[ebp]
	cmp	edx, DWORD PTR _a0$[ebp]
	jg	SHORT $L66488
	mov	eax, DWORD PTR _b1$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jge	SHORT $L66488
	mov	ecx, DWORD PTR _pb$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	eax, DWORD PTR _pb$[ebp]
	add	edx, DWORD PTR [eax+4]
	mov	ecx, DWORD PTR _b1$[ebp]
	add	ecx, edx
	mov	DWORD PTR _b1$[ebp], ecx
	mov	edx, DWORD PTR _pb$[ebp]
	add	edx, 8
	mov	DWORD PTR _pb$[ebp], edx
	jmp	SHORT $L66487
$L66488:
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66481
	mov	ecx, DWORD PTR _pb$[ebp]
	mov	edx, DWORD PTR _b1$[ebp]
	add	edx, DWORD PTR [ecx]
	mov	DWORD PTR _b1$[ebp], edx
	mov	eax, DWORD PTR _pb$[ebp]
	add	eax, 4
	mov	DWORD PTR _pb$[ebp], eax
	mov	ecx, DWORD PTR _b1$[ebp]
	sub	ecx, DWORD PTR _a0$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, ecx
	mov	DWORD PTR _RunLength$[ebp], edx
	mov	eax, DWORD PTR _b1$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	ecx, DWORD PTR _pb$[ebp]
	mov	edx, DWORD PTR _b1$[ebp]
	add	edx, DWORD PTR [ecx]
	mov	DWORD PTR _b1$[ebp], edx
	mov	eax, DWORD PTR _pb$[ebp]
	add	eax, 4
	mov	DWORD PTR _pb$[ebp], eax
	jmp	$L66478
$L66489:
	mov	ecx, DWORD PTR _pa$[ebp]
	sub	ecx, DWORD PTR _thisrun$[ebp]
	sar	ecx, 2
	and	ecx, 1
	test	ecx, ecx
	je	$L66490
$L66492:
	cmp	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jge	$L66507
	mov	edx, DWORD PTR _cp$[ebp]
	cmp	edx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66501
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L66502
	jmp	$eof2d$66471
$L66502:
	mov	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jmp	SHORT $L66507
$L66501:
	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _bitmap$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	eax, cl
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	or	ecx, eax
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	add	eax, 8
	mov	DWORD PTR _BitsAvail$[ebp], eax
	cmp	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jge	SHORT $L66507
	mov	ecx, DWORD PTR _cp$[ebp]
	cmp	ecx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66506
	mov	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jmp	SHORT $L66507
$L66506:
	mov	edx, DWORD PTR _cp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _bitmap$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L66507:
	xor	eax, eax
	test	eax, eax
	jne	$L66492
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	and	ecx, 8191				; 00001fffH
	lea	edx, DWORD PTR _TIFFFaxBlackTable[ecx*8]
	mov	DWORD PTR _TabEnt$[ebp], edx
$L66509:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _BitsAvail$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, cl
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66509
	xor	ecx, ecx
	test	ecx, ecx
	jne	$L66492
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	al, BYTE PTR [edx]
	mov	BYTE PTR -84+[ebp], al
	cmp	BYTE PTR -84+[ebp], 8
	je	SHORT $L66516
	cmp	BYTE PTR -84+[ebp], 9
	jbe	SHORT $L66522
	cmp	BYTE PTR -84+[ebp], 11			; 0000000bH
	jbe	SHORT $L66521
	jmp	SHORT $L66522
$L66516:
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	eax, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66516
	jmp	SHORT $doneWhite2da$66520
$L66521:
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _a0$[ebp], eax
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _RunLength$[ebp], edx
	jmp	SHORT $L66513
$L66522:
	jmp	$badBlack2d$66523
$L66513:
	jmp	$L66492
$doneWhite2da$66520:
	cmp	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jge	$L66540
	mov	eax, DWORD PTR _cp$[ebp]
	cmp	eax, DWORD PTR _ep$[ebp]
	jb	SHORT $L66534
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L66535
	jmp	$eof2d$66471
$L66535:
	mov	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jmp	SHORT $L66540
$L66534:
	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _bitmap$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
	cmp	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jge	SHORT $L66540
	mov	eax, DWORD PTR _cp$[ebp]
	cmp	eax, DWORD PTR _ep$[ebp]
	jb	SHORT $L66539
	mov	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jmp	SHORT $L66540
$L66539:
	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _bitmap$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L66540:
	xor	eax, eax
	test	eax, eax
	jne	$doneWhite2da$66520
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	and	ecx, 4095				; 00000fffH
	lea	edx, DWORD PTR _TIFFFaxWhiteTable[ecx*8]
	mov	DWORD PTR _TabEnt$[ebp], edx
$L66542:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _BitsAvail$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, cl
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66542
	xor	ecx, ecx
	test	ecx, ecx
	jne	$doneWhite2da$66520
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	al, BYTE PTR [edx]
	mov	BYTE PTR -88+[ebp], al
	cmp	BYTE PTR -88+[ebp], 7
	je	SHORT $L66549
	cmp	BYTE PTR -88+[ebp], 9
	je	SHORT $L66554
	cmp	BYTE PTR -88+[ebp], 11			; 0000000bH
	je	SHORT $L66554
	jmp	SHORT $L66555
$L66549:
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	eax, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66549
	jmp	SHORT $doneBlack2da$66553
$L66554:
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _a0$[ebp], eax
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _RunLength$[ebp], edx
	jmp	SHORT $L66546
$L66555:
	jmp	$badWhite2d$66556
$L66546:
	jmp	$doneWhite2da$66520
$doneBlack2da$66553:
	jmp	$doneBlack2db$66619
$L66490:
	cmp	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jge	$L66574
	mov	eax, DWORD PTR _cp$[ebp]
	cmp	eax, DWORD PTR _ep$[ebp]
	jb	SHORT $L66568
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L66569
	jmp	$eof2d$66471
$L66569:
	mov	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jmp	SHORT $L66574
$L66568:
	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _bitmap$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
	cmp	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jge	SHORT $L66574
	mov	eax, DWORD PTR _cp$[ebp]
	cmp	eax, DWORD PTR _ep$[ebp]
	jb	SHORT $L66573
	mov	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jmp	SHORT $L66574
$L66573:
	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _bitmap$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L66574:
	xor	eax, eax
	test	eax, eax
	jne	$L66490
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	and	ecx, 4095				; 00000fffH
	lea	edx, DWORD PTR _TIFFFaxWhiteTable[ecx*8]
	mov	DWORD PTR _TabEnt$[ebp], edx
$L66576:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _BitsAvail$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, cl
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66576
	xor	ecx, ecx
	test	ecx, ecx
	jne	$L66490
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	al, BYTE PTR [edx]
	mov	BYTE PTR -92+[ebp], al
	cmp	BYTE PTR -92+[ebp], 7
	je	SHORT $L66583
	cmp	BYTE PTR -92+[ebp], 9
	je	SHORT $L66588
	cmp	BYTE PTR -92+[ebp], 11			; 0000000bH
	je	SHORT $L66588
	jmp	SHORT $L66589
$L66583:
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	eax, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66583
	jmp	SHORT $doneWhite2db$66587
$L66588:
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _a0$[ebp], eax
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _RunLength$[ebp], edx
	jmp	SHORT $L66580
$L66589:
	jmp	$badWhite2d$66556
$L66580:
	jmp	$L66490
$doneWhite2db$66587:
	cmp	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jge	$L66606
	mov	eax, DWORD PTR _cp$[ebp]
	cmp	eax, DWORD PTR _ep$[ebp]
	jb	SHORT $L66600
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L66601
	jmp	$eof2d$66471
$L66601:
	mov	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jmp	SHORT $L66606
$L66600:
	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _bitmap$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
	cmp	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jge	SHORT $L66606
	mov	eax, DWORD PTR _cp$[ebp]
	cmp	eax, DWORD PTR _ep$[ebp]
	jb	SHORT $L66605
	mov	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jmp	SHORT $L66606
$L66605:
	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _bitmap$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L66606:
	xor	eax, eax
	test	eax, eax
	jne	$doneWhite2db$66587
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	and	ecx, 8191				; 00001fffH
	lea	edx, DWORD PTR _TIFFFaxBlackTable[ecx*8]
	mov	DWORD PTR _TabEnt$[ebp], edx
$L66608:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _BitsAvail$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, cl
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66608
	xor	ecx, ecx
	test	ecx, ecx
	jne	$doneWhite2db$66587
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	al, BYTE PTR [edx]
	mov	BYTE PTR -96+[ebp], al
	cmp	BYTE PTR -96+[ebp], 8
	je	SHORT $L66615
	cmp	BYTE PTR -96+[ebp], 9
	jbe	SHORT $L66621
	cmp	BYTE PTR -96+[ebp], 11			; 0000000bH
	jbe	SHORT $L66620
	jmp	SHORT $L66621
$L66615:
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	eax, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66615
	jmp	SHORT $doneBlack2db$66619
$L66620:
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _a0$[ebp], eax
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _RunLength$[ebp], edx
	jmp	SHORT $L66612
$L66621:
	jmp	$badBlack2d$66523
$L66612:
	jmp	$doneWhite2db$66587
$doneBlack2db$66619:
	mov	eax, DWORD PTR _pa$[ebp]
	cmp	eax, DWORD PTR _thisrun$[ebp]
	je	SHORT $L66628
$L66627:
	mov	ecx, DWORD PTR _b1$[ebp]
	cmp	ecx, DWORD PTR _a0$[ebp]
	jg	SHORT $L66628
	mov	edx, DWORD PTR _b1$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	jge	SHORT $L66628
	mov	eax, DWORD PTR _pb$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _pb$[ebp]
	add	ecx, DWORD PTR [edx+4]
	mov	eax, DWORD PTR _b1$[ebp]
	add	eax, ecx
	mov	DWORD PTR _b1$[ebp], eax
	mov	ecx, DWORD PTR _pb$[ebp]
	add	ecx, 8
	mov	DWORD PTR _pb$[ebp], ecx
	jmp	SHORT $L66627
$L66628:
	xor	edx, edx
	test	edx, edx
	jne	SHORT $doneBlack2db$66619
	jmp	$L66478
$L66629:
	mov	eax, DWORD PTR _pa$[ebp]
	cmp	eax, DWORD PTR _thisrun$[ebp]
	je	SHORT $L66636
$L66635:
	mov	ecx, DWORD PTR _b1$[ebp]
	cmp	ecx, DWORD PTR _a0$[ebp]
	jg	SHORT $L66636
	mov	edx, DWORD PTR _b1$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	jge	SHORT $L66636
	mov	eax, DWORD PTR _pb$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _pb$[ebp]
	add	ecx, DWORD PTR [edx+4]
	mov	eax, DWORD PTR _b1$[ebp]
	add	eax, ecx
	mov	DWORD PTR _b1$[ebp], eax
	mov	ecx, DWORD PTR _pb$[ebp]
	add	ecx, 8
	mov	DWORD PTR _pb$[ebp], ecx
	jmp	SHORT $L66635
$L66636:
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66629
$L66632:
	mov	eax, DWORD PTR _b1$[ebp]
	sub	eax, DWORD PTR _a0$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, eax
	mov	edx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _b1$[ebp]
	sub	ecx, DWORD PTR _a0$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, ecx
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66632
	mov	ecx, DWORD PTR _pb$[ebp]
	mov	edx, DWORD PTR _b1$[ebp]
	add	edx, DWORD PTR [ecx]
	mov	DWORD PTR _b1$[ebp], edx
	mov	eax, DWORD PTR _pb$[ebp]
	add	eax, 4
	mov	DWORD PTR _pb$[ebp], eax
	jmp	$L66478
$L66640:
	mov	ecx, DWORD PTR _pa$[ebp]
	cmp	ecx, DWORD PTR _thisrun$[ebp]
	je	SHORT $L66647
$L66646:
	mov	edx, DWORD PTR _b1$[ebp]
	cmp	edx, DWORD PTR _a0$[ebp]
	jg	SHORT $L66647
	mov	eax, DWORD PTR _b1$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jge	SHORT $L66647
	mov	ecx, DWORD PTR _pb$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	eax, DWORD PTR _pb$[ebp]
	add	edx, DWORD PTR [eax+4]
	mov	ecx, DWORD PTR _b1$[ebp]
	add	ecx, edx
	mov	DWORD PTR _b1$[ebp], ecx
	mov	edx, DWORD PTR _pb$[ebp]
	add	edx, 8
	mov	DWORD PTR _pb$[ebp], edx
	jmp	SHORT $L66646
$L66647:
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66640
$L66643:
	mov	ecx, DWORD PTR _b1$[ebp]
	sub	ecx, DWORD PTR _a0$[ebp]
	mov	edx, DWORD PTR _TabEnt$[ebp]
	add	ecx, DWORD PTR [edx+4]
	mov	eax, DWORD PTR _RunLength$[ebp]
	add	eax, ecx
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _b1$[ebp]
	sub	eax, DWORD PTR _a0$[ebp]
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	add	eax, DWORD PTR [ecx+4]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, eax
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66643
	mov	ecx, DWORD PTR _pb$[ebp]
	mov	edx, DWORD PTR _b1$[ebp]
	add	edx, DWORD PTR [ecx]
	mov	DWORD PTR _b1$[ebp], edx
	mov	eax, DWORD PTR _pb$[ebp]
	add	eax, 4
	mov	DWORD PTR _pb$[ebp], eax
	jmp	$L66478
$L66651:
	mov	ecx, DWORD PTR _pa$[ebp]
	cmp	ecx, DWORD PTR _thisrun$[ebp]
	je	SHORT $L66658
$L66657:
	mov	edx, DWORD PTR _b1$[ebp]
	cmp	edx, DWORD PTR _a0$[ebp]
	jg	SHORT $L66658
	mov	eax, DWORD PTR _b1$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jge	SHORT $L66658
	mov	ecx, DWORD PTR _pb$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	eax, DWORD PTR _pb$[ebp]
	add	edx, DWORD PTR [eax+4]
	mov	ecx, DWORD PTR _b1$[ebp]
	add	ecx, edx
	mov	DWORD PTR _b1$[ebp], ecx
	mov	edx, DWORD PTR _pb$[ebp]
	add	edx, 8
	mov	DWORD PTR _pb$[ebp], edx
	jmp	SHORT $L66657
$L66658:
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66651
$L66654:
	mov	ecx, DWORD PTR _b1$[ebp]
	sub	ecx, DWORD PTR _a0$[ebp]
	mov	edx, DWORD PTR _TabEnt$[ebp]
	sub	ecx, DWORD PTR [edx+4]
	mov	eax, DWORD PTR _RunLength$[ebp]
	add	eax, ecx
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _b1$[ebp]
	sub	eax, DWORD PTR _a0$[ebp]
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	sub	eax, DWORD PTR [ecx+4]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, eax
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66654
	mov	ecx, DWORD PTR _pb$[ebp]
	sub	ecx, 4
	mov	DWORD PTR _pb$[ebp], ecx
	mov	edx, DWORD PTR _pb$[ebp]
	mov	eax, DWORD PTR _b1$[ebp]
	sub	eax, DWORD PTR [edx]
	mov	DWORD PTR _b1$[ebp], eax
	jmp	$L66478
$L66662:
	mov	ecx, DWORD PTR _lastx$[ebp]
	sub	ecx, DWORD PTR _a0$[ebp]
	mov	edx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _a0$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	push	OFFSET FLAT:_?module@?1??Fax3Decode2D@@9@9
	call	_Fax3Extension
	add	esp, 12					; 0000000cH
	jmp	$eol2d$66663
$L66664:
	mov	eax, DWORD PTR _lastx$[ebp]
	sub	eax, DWORD PTR _a0$[ebp]
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
$L66665:
	cmp	DWORD PTR _BitsAvail$[ebp], 4
	jge	SHORT $L66671
	mov	eax, DWORD PTR _cp$[ebp]
	cmp	eax, DWORD PTR _ep$[ebp]
	jb	SHORT $L66669
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L66670
	jmp	$eof2d$66471
$L66670:
	mov	DWORD PTR _BitsAvail$[ebp], 4
	jmp	SHORT $L66671
$L66669:
	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _bitmap$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L66671:
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66665
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	and	ecx, 15					; 0000000fH
	test	ecx, ecx
	je	SHORT $L66673
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	push	OFFSET FLAT:_?module@?1??Fax3Decode2D@@9@9
	call	_Fax3Unexpected
	add	esp, 12					; 0000000cH
$L66673:
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	sub	ecx, 4
	mov	DWORD PTR _BitsAvail$[ebp], ecx
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, 4
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66673
	mov	DWORD PTR _EOLcnt$[ebp], 1
	jmp	$eol2d$66663
$badMain2d$66678:
	mov	ecx, DWORD PTR _a0$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	push	OFFSET FLAT:_?module@?1??Fax3Decode2D@@9@9
	call	_Fax3Unexpected
	add	esp, 12					; 0000000cH
	jmp	$eol2d$66663
$badBlack2d$66523:
	mov	eax, DWORD PTR _a0$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	push	OFFSET FLAT:_?module@?1??Fax3Decode2D@@9@9
	call	_Fax3Unexpected
	add	esp, 12					; 0000000cH
	jmp	$eol2d$66663
$badWhite2d$66556:
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	push	OFFSET FLAT:_?module@?1??Fax3Decode2D@@9@9
	call	_Fax3Unexpected
	add	esp, 12					; 0000000cH
	jmp	$eol2d$66663
$eof2d$66471:
	mov	ecx, DWORD PTR _a0$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	push	OFFSET FLAT:_?module@?1??Fax3Decode2D@@9@9
	call	_Fax3PrematureEOF
	add	esp, 12					; 0000000cH
$L66679:
	cmp	DWORD PTR _RunLength$[ebp], 0
	je	SHORT $L66685
$L66683:
	mov	eax, DWORD PTR _pa$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66683
$L66685:
	mov	edx, DWORD PTR _a0$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	je	$L66706
	mov	eax, DWORD PTR _lastx$[ebp]
	push	eax
	mov	ecx, DWORD PTR _a0$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	push	OFFSET FLAT:_?module@?1??Fax3Decode2D@@9@9
	call	_Fax3BadLength
	add	esp, 16					; 00000010H
$L66688:
	mov	eax, DWORD PTR _a0$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jle	SHORT $L66689
	mov	ecx, DWORD PTR _pa$[ebp]
	cmp	ecx, DWORD PTR _thisrun$[ebp]
	jbe	SHORT $L66689
	mov	edx, DWORD PTR _pa$[ebp]
	sub	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _pa$[ebp]
	mov	ecx, DWORD PTR _a0$[ebp]
	sub	ecx, DWORD PTR [eax]
	mov	DWORD PTR _a0$[ebp], ecx
	jmp	SHORT $L66688
$L66689:
	mov	edx, DWORD PTR _a0$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	jge	SHORT $L66690
	cmp	DWORD PTR _a0$[ebp], 0
	jge	SHORT $L66691
	mov	DWORD PTR _a0$[ebp], 0
$L66691:
	mov	eax, DWORD PTR _pa$[ebp]
	sub	eax, DWORD PTR _thisrun$[ebp]
	sar	eax, 2
	and	eax, 1
	test	eax, eax
	je	SHORT $L66695
$L66693:
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [ecx], edx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66693
$L66695:
	mov	eax, DWORD PTR _lastx$[ebp]
	sub	eax, DWORD PTR _a0$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, eax
	mov	edx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _lastx$[ebp]
	sub	ecx, DWORD PTR _a0$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, ecx
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66695
	jmp	SHORT $L66706
$L66690:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jle	SHORT $L66706
$L66701:
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, DWORD PTR _lastx$[ebp]
	mov	eax, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, DWORD PTR _lastx$[ebp]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66701
$L66703:
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [ecx], edx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66703
$L66706:
	xor	eax, eax
	test	eax, eax
	jne	$L66679
	jmp	$EOF2Da$66426
$L66478:
	jmp	$L66320
$L66461:
	cmp	DWORD PTR _RunLength$[ebp], 0
	je	$eol2d$66663
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jge	SHORT $L66720
$L66709:
	cmp	DWORD PTR _BitsAvail$[ebp], 1
	jge	SHORT $L66715
	mov	edx, DWORD PTR _cp$[ebp]
	cmp	edx, DWORD PTR _ep$[ebp]
	jb	SHORT $L66713
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L66714
	jmp	$eof2d$66471
$L66714:
	mov	DWORD PTR _BitsAvail$[ebp], 1
	jmp	SHORT $L66715
$L66713:
	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _bitmap$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	eax, cl
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	or	ecx, eax
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	add	eax, 8
	mov	DWORD PTR _BitsAvail$[ebp], eax
$L66715:
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66709
	mov	edx, DWORD PTR _BitAcc$[ebp]
	and	edx, 1
	test	edx, edx
	jne	SHORT $L66717
	jmp	$badMain2d$66678
$L66717:
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	sub	eax, 1
	mov	DWORD PTR _BitsAvail$[ebp], eax
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	shr	ecx, 1
	mov	DWORD PTR _BitAcc$[ebp], ecx
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66717
$L66720:
	mov	eax, DWORD PTR _pa$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66720
$eol2d$66663:
	cmp	DWORD PTR _RunLength$[ebp], 0
	je	SHORT $L66730
$L66728:
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66728
$L66730:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	je	$L66751
	mov	edx, DWORD PTR _lastx$[ebp]
	push	edx
	mov	eax, DWORD PTR _a0$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	push	OFFSET FLAT:_?module@?1??Fax3Decode2D@@9@9
	call	_Fax3BadLength
	add	esp, 16					; 00000010H
$L66733:
	mov	edx, DWORD PTR _a0$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	jle	SHORT $L66734
	mov	eax, DWORD PTR _pa$[ebp]
	cmp	eax, DWORD PTR _thisrun$[ebp]
	jbe	SHORT $L66734
	mov	ecx, DWORD PTR _pa$[ebp]
	sub	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	sub	eax, DWORD PTR [edx]
	mov	DWORD PTR _a0$[ebp], eax
	jmp	SHORT $L66733
$L66734:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jge	SHORT $L66735
	cmp	DWORD PTR _a0$[ebp], 0
	jge	SHORT $L66736
	mov	DWORD PTR _a0$[ebp], 0
$L66736:
	mov	edx, DWORD PTR _pa$[ebp]
	sub	edx, DWORD PTR _thisrun$[ebp]
	sar	edx, 2
	and	edx, 1
	test	edx, edx
	je	SHORT $L66740
$L66738:
	mov	eax, DWORD PTR _pa$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66738
$L66740:
	mov	edx, DWORD PTR _lastx$[ebp]
	sub	edx, DWORD PTR _a0$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	add	eax, edx
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _lastx$[ebp]
	sub	eax, DWORD PTR _a0$[ebp]
	mov	ecx, DWORD PTR _a0$[ebp]
	add	ecx, eax
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66740
	jmp	SHORT $L66751
$L66735:
	mov	eax, DWORD PTR _a0$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jle	SHORT $L66751
$L66746:
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR _lastx$[ebp]
	mov	edx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _a0$[ebp]
	add	ecx, DWORD PTR _lastx$[ebp]
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66746
$L66748:
	mov	eax, DWORD PTR _pa$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66748
$L66751:
	xor	edx, edx
	test	edx, edx
	jne	$eol2d$66663
	xor	eax, eax
	test	eax, eax
	jne	$L66320
$L66458:

; 292  : 		(*sp->fill)(buf, thisrun, pa, lastx);

	mov	ecx, DWORD PTR _lastx$[ebp]
	push	ecx
	mov	edx, DWORD PTR _pa$[ebp]
	push	edx
	mov	eax, DWORD PTR _thisrun$[ebp]
	push	eax
	mov	ecx, DWORD PTR _buf$[ebp]
	push	ecx
	mov	edx, DWORD PTR _sp$[ebp]
	call	DWORD PTR [edx+68]
	add	esp, 16					; 00000010H
$L66752:

; 293  : 		SETVAL(0);		/* imaginary change for reference */

	mov	eax, DWORD PTR _pa$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66752

; 294  : 		SWAP(uint32*, sp->curruns, sp->refruns);

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+80]
	mov	DWORD PTR _x$66755[ebp], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+76]
	mov	DWORD PTR [ecx+80], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _x$66755[ebp]
	mov	DWORD PTR [ecx+76], edx

; 295  : 		buf += sp->b.rowbytes;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _buf$[ebp]
	add	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR _buf$[ebp], ecx

; 296  : 		occ -= sp->b.rowbytes;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _occ$[ebp]
	sub	eax, DWORD PTR [edx+8]
	mov	DWORD PTR _occ$[ebp], eax

; 297  : 		if (occ != 0)

	cmp	DWORD PTR _occ$[ebp], 0
	je	SHORT $L66756

; 298  : 			tif->tif_row++;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	add	edx, 1
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+356], edx
$L66756:

; 299  : 		continue;

	jmp	$L66255
$EOF2D$66274:

; 300  : 	EOF2D:				/* premature EOF */
; 301  : 		CLEANUP_RUNS();

	cmp	DWORD PTR _RunLength$[ebp], 0
	je	SHORT $L66763
$L66761:
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [ecx], edx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66761
$L66763:
	mov	eax, DWORD PTR _a0$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	je	$L66784
	mov	ecx, DWORD PTR _lastx$[ebp]
	push	ecx
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	push	OFFSET FLAT:_?module@?1??Fax3Decode2D@@9@9
	call	_Fax3BadLength
	add	esp, 16					; 00000010H
$L66766:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jle	SHORT $L66767
	mov	edx, DWORD PTR _pa$[ebp]
	cmp	edx, DWORD PTR _thisrun$[ebp]
	jbe	SHORT $L66767
	mov	eax, DWORD PTR _pa$[ebp]
	sub	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	sub	edx, DWORD PTR [ecx]
	mov	DWORD PTR _a0$[ebp], edx
	jmp	SHORT $L66766
$L66767:
	mov	eax, DWORD PTR _a0$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jge	SHORT $L66768
	cmp	DWORD PTR _a0$[ebp], 0
	jge	SHORT $L66769
	mov	DWORD PTR _a0$[ebp], 0
$L66769:
	mov	ecx, DWORD PTR _pa$[ebp]
	sub	ecx, DWORD PTR _thisrun$[ebp]
	sar	ecx, 2
	and	ecx, 1
	test	ecx, ecx
	je	SHORT $L66773
$L66771:
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66771
$L66773:
	mov	ecx, DWORD PTR _lastx$[ebp]
	sub	ecx, DWORD PTR _a0$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, ecx
	mov	eax, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _lastx$[ebp]
	sub	edx, DWORD PTR _a0$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, edx
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66773
	jmp	SHORT $L66784
$L66768:
	mov	edx, DWORD PTR _a0$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	jle	SHORT $L66784
$L66779:
	mov	eax, DWORD PTR _RunLength$[ebp]
	add	eax, DWORD PTR _lastx$[ebp]
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR _lastx$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66779
$L66781:
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L66781
$L66784:
	xor	ecx, ecx
	test	ecx, ecx
	jne	$EOF2D$66274
$EOF2Da$66426:

; 302  : 	EOF2Da:				/* premature EOF */
; 303  : 		(*sp->fill)(buf, thisrun, pa, lastx);

	mov	edx, DWORD PTR _lastx$[ebp]
	push	edx
	mov	eax, DWORD PTR _pa$[ebp]
	push	eax
	mov	ecx, DWORD PTR _thisrun$[ebp]
	push	ecx
	mov	edx, DWORD PTR _buf$[ebp]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	call	DWORD PTR [eax+68]
	add	esp, 16					; 00000010H
$L66785:

; 304  : 		UNCACHE_STATE(tif, sp);

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	mov	DWORD PTR [ecx+60], edx
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	mov	DWORD PTR [eax+56], ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _EOLcnt$[ebp]
	mov	DWORD PTR [edx+64], eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	sub	edx, DWORD PTR [ecx+480]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+484]
	sub	ecx, edx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], ecx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [eax+480], ecx
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L66785

; 305  : 		return (-1);

	or	eax, -1
	jmp	SHORT $L66231
$L66260:

; 307  : 	UNCACHE_STATE(tif, sp);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	mov	DWORD PTR [eax+60], ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _BitAcc$[ebp]
	mov	DWORD PTR [edx+56], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _EOLcnt$[ebp]
	mov	DWORD PTR [ecx+64], edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	sub	ecx, DWORD PTR [eax+480]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+484]
	sub	eax, ecx
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+484], eax
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx+480], eax
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L66260

; 308  : 	return (1);

	mov	eax, 1
$L66231:

; 309  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68226:
	DD	$L66355
	DD	$L66361
	DD	$L66360
	DD	$L66361
	DD	$L66360
	DD	$L66353
$L68227:
	DD	$L66389
	DD	$L66395
	DD	$L66394
	DD	$L66394
	DD	$L66388
$L68228:
	DD	$L66481
	DD	$L66489
	DD	$L66629
	DD	$L66640
	DD	$L66651
	DD	$L66662
	DD	$badMain2d$66678
	DD	$badMain2d$66678
	DD	$badMain2d$66678
	DD	$badMain2d$66678
	DD	$badMain2d$66678
	DD	$L66664
_Fax3Decode2D ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+1
$SG65934 DB	'%s: Uncompressed data (not supported) at scanline %d (x '
	DB	'%lu)', 00H
_DATA	ENDS
_TEXT	SEGMENT
_module$ = 8
_tif$ = 12
_a0$ = 16
_Fax3Extension PROC NEAR

; 191  : {

	push	ebp
	mov	ebp, esp

; 192  : 	TIFFError(module,
; 193  : 	    "%s: Uncompressed data (not supported) at scanline %d (x %lu)",
; 194  : 	    tif->tif_name, tif->tif_row, (u_long) a0);

	mov	eax, DWORD PTR _a0$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG65934
	mov	edx, DWORD PTR _module$[ebp]
	push	edx
	call	_TIFFError
	add	esp, 20					; 00000014H

; 195  : }

	pop	ebp
	ret	0
_Fax3Extension ENDP
_TEXT	ENDS
PUBLIC	__real@4@4000a28f5c0000000000
PUBLIC	__real@4@40069600000000000000
EXTRN	__TIFFmemset:NEAR
EXTRN	__fltused:NEAR
_DATA	SEGMENT
	ORG $+3
$SG67062 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_fax3.c', 00H
	ORG $+3
$SG67063 DB	'sp != NULL', 00H
_DATA	ENDS
;	COMDAT __real@4@4000a28f5c0000000000
; File C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_fax3.c
CONST	SEGMENT
__real@4@4000a28f5c0000000000 DD 040228f5cr	; 2.54
CONST	ENDS
;	COMDAT __real@4@40069600000000000000
CONST	SEGMENT
__real@4@40069600000000000000 DD 043160000r	; 150
CONST	ENDS
_TEXT	SEGMENT
_tif$ = 8
_sp$ = -4
_res$67066 = -8
_Fax3PreEncode PROC NEAR

; 682  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 683  : 	Fax3EncodeState* sp = EncoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 684  : 
; 685  : 	(void) s;
; 686  : 	assert(sp != NULL);

	cmp	DWORD PTR _sp$[ebp], 0
	jne	SHORT $L68231
	push	686					; 000002aeH
	push	OFFSET FLAT:$SG67062
	push	OFFSET FLAT:$SG67063
	call	__assert
	add	esp, 12					; 0000000cH
$L68231:

; 687  : 	sp->bit = 8;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+56], 8

; 688  : 	sp->data = 0;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+52], 0

; 689  : 	sp->tag = G3_1D;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+60], 0

; 690  : 	/*
; 691  : 	 * This is necessary for Group 4; otherwise it isn't
; 692  : 	 * needed because the first scanline of each strip ends
; 693  : 	 * up being copied into the refline.
; 694  : 	 */
; 695  : 	if (sp->refline)

	mov	eax, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [eax+64], 0
	je	SHORT $L67064

; 696  : 		_TIFFmemset(sp->refline, 0x00, sp->b.rowbytes);

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+8]
	push	edx
	push	0
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+64]
	push	ecx
	call	__TIFFmemset
	add	esp, 12					; 0000000cH
$L67064:

; 697  : 	if (is2DEncoding(sp)) {

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+28]
	and	eax, 1
	test	eax, eax
	je	SHORT $L67065

; 698  : 		float res = tif->tif_dir.td_yresolution;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+108]
	mov	DWORD PTR _res$67066[ebp], edx

; 699  : 		/*
; 700  : 		 * The CCITT spec says that when doing 2d encoding, you
; 701  : 		 * should only do it on K consecutive scanlines, where K
; 702  : 		 * depends on the resolution of the image being encoded
; 703  : 		 * (2 for <= 200 lpi, 4 for > 200 lpi).  Since the directory
; 704  : 		 * code initializes td_yresolution to 0, this code will
; 705  : 		 * select a K of 2 unless the YResolution tag is set
; 706  : 		 * appropriately.  (Note also that we fudge a little here
; 707  : 		 * and use 150 lpi to avoid problems with units conversion.)
; 708  : 		 */
; 709  : 		if (tif->tif_dir.td_resolutionunit == RESUNIT_CENTIMETER)

	mov	eax, DWORD PTR _tif$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+112]
	cmp	ecx, 3
	jne	SHORT $L67067

; 710  : 			res *= 2.54f;		/* convert to inches */

	fld	DWORD PTR _res$67066[ebp]
	fmul	DWORD PTR __real@4@4000a28f5c0000000000
	fstp	DWORD PTR _res$67066[ebp]
$L67067:

; 711  : 		sp->maxk = (res > 150 ? 4 : 2);

	fld	DWORD PTR _res$67066[ebp]
	fcomp	DWORD PTR __real@4@40069600000000000000
	fnstsw	ax
	test	ah, 65					; 00000041H
	jne	SHORT $L68232
	mov	DWORD PTR -12+[ebp], 4
	jmp	SHORT $L68233
$L68232:
	mov	DWORD PTR -12+[ebp], 2
$L68233:
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR -12+[ebp]
	mov	DWORD PTR [edx+72], eax

; 712  : 		sp->k = sp->maxk-1;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+72]
	sub	edx, 1
	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+68], edx

; 713  : 	} else

	jmp	SHORT $L67068
$L67065:

; 714  : 		sp->k = sp->maxk = 0;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+72], 0
	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+68], 0
$L67068:

; 715  : 	return (1);

	mov	eax, 1

; 716  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Fax3PreEncode ENDP
_TEXT	ENDS
EXTRN	__TIFFmemcpy:NEAR
_TEXT	SEGMENT
_tif$ = 8
_bp$ = 12
_cc$ = 16
_sp$ = -4
_Fax3Encode PROC NEAR

; 1002 : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 1003 : 	Fax3EncodeState* sp = EncoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx
$L67224:

; 1004 : 
; 1005 : 	(void) s;
; 1006 : 	while ((long)cc > 0) {

	cmp	DWORD PTR _cc$[ebp], 0
	jle	$L67225

; 1007 : 		if ((sp->b.mode & FAXMODE_NOEOL) == 0)

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+4]
	and	eax, 2
	test	eax, eax
	jne	SHORT $L67226

; 1008 : 			Fax3PutEOL(tif);

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_Fax3PutEOL
	add	esp, 4
$L67226:

; 1009 : 		if (is2DEncoding(sp)) {

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+28]
	and	eax, 1
	test	eax, eax
	je	$L67227

; 1010 : 			if (sp->tag == G3_1D) {

	mov	ecx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [ecx+60], 0
	jne	SHORT $L67228

; 1011 : 				if (!Fax3Encode1DRow(tif, bp, sp->b.rowpixels))

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+12]
	push	eax
	mov	ecx, DWORD PTR _bp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_Fax3Encode1DRow
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L67229

; 1012 : 					return (0);

	xor	eax, eax
	jmp	$L67217
$L67229:

; 1013 : 				sp->tag = G3_2D;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+60], 1

; 1014 : 			} else {

	jmp	SHORT $L67230
$L67228:

; 1015 : 				if (!Fax3Encode2DRow(tif, bp, sp->refline, sp->b.rowpixels))

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+64]
	push	ecx
	mov	edx, DWORD PTR _bp$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_Fax3Encode2DRow
	add	esp, 16					; 00000010H
	test	eax, eax
	jne	SHORT $L67231

; 1016 : 					return (0);

	xor	eax, eax
	jmp	$L67217
$L67231:

; 1017 : 				sp->k--;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+68]
	sub	edx, 1
	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+68], edx
$L67230:

; 1019 : 			if (sp->k == 0) {

	mov	ecx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [ecx+68], 0
	jne	SHORT $L67232

; 1020 : 				sp->tag = G3_1D;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+60], 0

; 1021 : 				sp->k = sp->maxk-1;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+72]
	sub	ecx, 1
	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+68], ecx

; 1022 : 			} else

	jmp	SHORT $L67233
$L67232:

; 1023 : 				_TIFFmemcpy(sp->refline, bp, sp->b.rowbytes);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+8]
	push	ecx
	mov	edx, DWORD PTR _bp$[ebp]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+64]
	push	ecx
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH
$L67233:

; 1024 : 		} else {

	jmp	SHORT $L67235
$L67227:

; 1025 : 			if (!Fax3Encode1DRow(tif, bp, sp->b.rowpixels))

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+12]
	push	eax
	mov	ecx, DWORD PTR _bp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_Fax3Encode1DRow
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L67235

; 1026 : 				return (0);

	xor	eax, eax
	jmp	SHORT $L67217
$L67235:

; 1028 : 		bp += sp->b.rowbytes;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR _bp$[ebp], ecx

; 1029 : 		cc -= sp->b.rowbytes;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _cc$[ebp]
	sub	eax, DWORD PTR [edx+8]
	mov	DWORD PTR _cc$[ebp], eax

; 1030 : 		if (cc != 0)

	cmp	DWORD PTR _cc$[ebp], 0
	je	SHORT $L67236

; 1031 : 			tif->tif_row++;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	add	edx, 1
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+356], edx
$L67236:

; 1032 : 	}

	jmp	$L67224
$L67225:

; 1033 : 	return (1);

	mov	eax, 1
$L67217:

; 1034 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Fax3Encode ENDP
_TEXT	ENDS
EXTRN	_TIFFFlushData1:NEAR
_TEXT	SEGMENT
_tif$ = 8
_sp$ = -8
_bit$ = -24
_data$ = -4
_code$ = -20
_length$ = -16
_tparm$ = -12
_align$67029 = -28
_Fax3PutEOL PROC NEAR

; 645  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 28					; 0000001cH

; 646  : 	Fax3EncodeState* sp = EncoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 647  : 	u_int bit = sp->bit;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	DWORD PTR _bit$[ebp], eax

; 648  : 	int data = sp->data;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+52]
	mov	DWORD PTR _data$[ebp], edx

; 649  : 	u_int code, length, tparm;
; 650  : 
; 651  : 	if (sp->b.groupoptions & GROUP3OPT_FILLBITS) {

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	and	ecx, 4
	test	ecx, ecx
	je	$L67038

; 652  : 		/*
; 653  : 		 * Force bit alignment so EOL will terminate on
; 654  : 		 * a byte boundary.  That is, force the bit alignment
; 655  : 		 * to 16-12 = 4 before putting out the EOL code.
; 656  : 		 */
; 657  : 		int align = 8 - 4;

	mov	DWORD PTR _align$67029[ebp], 4

; 658  : 		if (align != sp->bit) {

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _align$67029[ebp]
	cmp	eax, DWORD PTR [edx+56]
	je	$L67038

; 659  : 			if (align > sp->bit)

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _align$67029[ebp]
	cmp	edx, DWORD PTR [ecx+56]
	jle	SHORT $L67031

; 660  : 				align = sp->bit + (8 - align);

	mov	eax, 8
	sub	eax, DWORD PTR _align$67029[ebp]
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+56]
	add	edx, eax
	mov	DWORD PTR _align$67029[ebp], edx

; 661  : 			else

	jmp	SHORT $L67032
$L67031:

; 662  : 				align = sp->bit - align;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	sub	ecx, DWORD PTR _align$67029[ebp]
	mov	DWORD PTR _align$67029[ebp], ecx
$L67032:

; 663  : 			code = 0;

	mov	DWORD PTR _code$[ebp], 0

; 664  : 			tparm=align; 

	mov	edx, DWORD PTR _align$67029[ebp]
	mov	DWORD PTR _tparm$[ebp], edx
$L67034:

; 665  : 			_PutBits(tif, 0, tparm);

	mov	eax, DWORD PTR _tparm$[ebp]
	cmp	eax, DWORD PTR _bit$[ebp]
	jbe	$L67035
	mov	ecx, DWORD PTR _tparm$[ebp]
	sub	ecx, DWORD PTR _bit$[ebp]
	xor	edx, edx
	sar	edx, cl
	mov	eax, DWORD PTR _data$[ebp]
	or	eax, edx
	mov	DWORD PTR _data$[ebp], eax
	mov	ecx, DWORD PTR _tparm$[ebp]
	sub	ecx, DWORD PTR _bit$[ebp]
	mov	DWORD PTR _tparm$[ebp], ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [edx+484]
	cmp	ecx, DWORD PTR [eax+476]
	jl	SHORT $L67036
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFlushData1
	add	esp, 4
$L67036:
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	dl, BYTE PTR _data$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+480], ecx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+484]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], ecx
	mov	DWORD PTR _data$[ebp], 0
	mov	DWORD PTR _bit$[ebp], 8
	jmp	$L67034
$L67035:
	mov	ecx, DWORD PTR _bit$[ebp]
	sub	ecx, DWORD PTR _tparm$[ebp]
	xor	eax, eax
	shl	eax, cl
	mov	ecx, DWORD PTR _data$[ebp]
	or	ecx, eax
	mov	DWORD PTR _data$[ebp], ecx
	mov	edx, DWORD PTR _bit$[ebp]
	sub	edx, DWORD PTR _tparm$[ebp]
	mov	DWORD PTR _bit$[ebp], edx
	cmp	DWORD PTR _bit$[ebp], 0
	jne	SHORT $L67038
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [eax+484]
	cmp	edx, DWORD PTR [ecx+476]
	jl	SHORT $L67039
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFlushData1
	add	esp, 4
$L67039:
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+480]
	mov	al, BYTE PTR _data$[ebp]
	mov	BYTE PTR [edx], al
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+480]
	add	edx, 1
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+480], edx
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+484]
	add	edx, 1
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+484], edx
	mov	DWORD PTR _data$[ebp], 0
	mov	DWORD PTR _bit$[ebp], 8
$L67038:

; 668  : 	code = EOL, length = 12;

	mov	DWORD PTR _code$[ebp], 1
	mov	DWORD PTR _length$[ebp], 12		; 0000000cH

; 669  : 	if (is2DEncoding(sp))

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	and	edx, 1
	test	edx, edx
	je	SHORT $L67041

; 670  : 		code = (code<<1) | (sp->tag == G3_1D), length++;

	mov	eax, DWORD PTR _code$[ebp]
	shl	eax, 1
	mov	ecx, DWORD PTR _sp$[ebp]
	xor	edx, edx
	cmp	DWORD PTR [ecx+60], 0
	sete	dl
	or	eax, edx
	mov	DWORD PTR _code$[ebp], eax
	mov	eax, DWORD PTR _length$[ebp]
	add	eax, 1
	mov	DWORD PTR _length$[ebp], eax
$L67041:

; 671  : 	_PutBits(tif, code, length);

	mov	ecx, DWORD PTR _length$[ebp]
	cmp	ecx, DWORD PTR _bit$[ebp]
	jbe	$L67044
	mov	ecx, DWORD PTR _length$[ebp]
	sub	ecx, DWORD PTR _bit$[ebp]
	mov	edx, DWORD PTR _code$[ebp]
	shr	edx, cl
	mov	eax, DWORD PTR _data$[ebp]
	or	eax, edx
	mov	DWORD PTR _data$[ebp], eax
	mov	ecx, DWORD PTR _length$[ebp]
	sub	ecx, DWORD PTR _bit$[ebp]
	mov	DWORD PTR _length$[ebp], ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [edx+484]
	cmp	ecx, DWORD PTR [eax+476]
	jl	SHORT $L67045
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFlushData1
	add	esp, 4
$L67045:
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	dl, BYTE PTR _data$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+480], ecx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+484]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], ecx
	mov	DWORD PTR _data$[ebp], 0
	mov	DWORD PTR _bit$[ebp], 8
	jmp	$L67041
$L67044:
	mov	eax, DWORD PTR _length$[ebp]
	mov	edx, DWORD PTR _code$[ebp]
	and	edx, DWORD PTR __msbmask[eax*4]
	mov	ecx, DWORD PTR _bit$[ebp]
	sub	ecx, DWORD PTR _length$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _data$[ebp]
	or	eax, edx
	mov	DWORD PTR _data$[ebp], eax
	mov	ecx, DWORD PTR _bit$[ebp]
	sub	ecx, DWORD PTR _length$[ebp]
	mov	DWORD PTR _bit$[ebp], ecx
	cmp	DWORD PTR _bit$[ebp], 0
	jne	SHORT $L67047
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [edx+484]
	cmp	ecx, DWORD PTR [eax+476]
	jl	SHORT $L67048
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFlushData1
	add	esp, 4
$L67048:
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	dl, BYTE PTR _data$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+480], ecx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+484]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], ecx
	mov	DWORD PTR _data$[ebp], 0
	mov	DWORD PTR _bit$[ebp], 8
$L67047:

; 672  : 
; 673  : 	sp->data = data;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	DWORD PTR [eax+52], ecx

; 674  : 	sp->bit = bit;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _bit$[ebp]
	mov	DWORD PTR [edx+56], eax

; 675  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Fax3PutEOL ENDP
_tif$ = 8
_bp$ = 12
_bits$ = 16
_sp$ = -8
_span$ = -12
_bs$ = -4
_Fax3Encode1DRow PROC NEAR

; 910  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 911  : 	Fax3EncodeState* sp = EncoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 912  : 	int32 span;
; 913  :         uint32 bs = 0;

	mov	DWORD PTR _bs$[ebp], 0
$L67163:

; 916  : 		span = find0span(bp, bs, bits);		/* white span */

	mov	edx, DWORD PTR _bits$[ebp]
	push	edx
	mov	eax, DWORD PTR _bs$[ebp]
	push	eax
	mov	ecx, DWORD PTR _bp$[ebp]
	push	ecx
	call	_find0span
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _span$[ebp], eax

; 917  : 		putspan(tif, span, TIFFFaxWhiteCodes);

	push	OFFSET FLAT:_TIFFFaxWhiteCodes
	mov	edx, DWORD PTR _span$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_putspan
	add	esp, 12					; 0000000cH

; 918  : 		bs += span;

	mov	ecx, DWORD PTR _bs$[ebp]
	add	ecx, DWORD PTR _span$[ebp]
	mov	DWORD PTR _bs$[ebp], ecx

; 919  : 		if (bs >= bits)

	mov	edx, DWORD PTR _bs$[ebp]
	cmp	edx, DWORD PTR _bits$[ebp]
	jb	SHORT $L67165

; 920  : 			break;

	jmp	SHORT $L67164
$L67165:

; 921  : 		span = find1span(bp, bs, bits);		/* black span */

	mov	eax, DWORD PTR _bits$[ebp]
	push	eax
	mov	ecx, DWORD PTR _bs$[ebp]
	push	ecx
	mov	edx, DWORD PTR _bp$[ebp]
	push	edx
	call	_find1span
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _span$[ebp], eax

; 922  : 		putspan(tif, span, TIFFFaxBlackCodes);

	push	OFFSET FLAT:_TIFFFaxBlackCodes
	mov	eax, DWORD PTR _span$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_putspan
	add	esp, 12					; 0000000cH

; 923  : 		bs += span;

	mov	edx, DWORD PTR _bs$[ebp]
	add	edx, DWORD PTR _span$[ebp]
	mov	DWORD PTR _bs$[ebp], edx

; 924  : 		if (bs >= bits)

	mov	eax, DWORD PTR _bs$[ebp]
	cmp	eax, DWORD PTR _bits$[ebp]
	jb	SHORT $L67166

; 925  : 			break;

	jmp	SHORT $L67164
$L67166:

; 926  : 	}

	jmp	SHORT $L67163
$L67164:

; 927  : 	if (sp->b.mode & (FAXMODE_BYTEALIGN|FAXMODE_WORDALIGN)) {

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+4]
	and	edx, 12					; 0000000cH
	test	edx, edx
	je	$L67173

; 928  : 		if (sp->bit != 8)			/* byte-align */

	mov	eax, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [eax+56], 8
	je	SHORT $L67168

; 929  : 			Fax3FlushBits(tif, sp);

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [ecx+484]
	cmp	eax, DWORD PTR [edx+476]
	jl	SHORT $L67169
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFFlushData1
	add	esp, 4
$L67169:
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+480]
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	dl, BYTE PTR [ecx+52]
	mov	BYTE PTR [eax], dl
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+480], ecx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+484]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], ecx
	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+52], 0
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+56], 8
$L67168:

; 930  : 		if ((sp->b.mode&FAXMODE_WORDALIGN) &&
; 931  : 		    !isAligned(tif->tif_rawcp, uint16))

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+4]
	and	eax, 8
	test	eax, eax
	je	SHORT $L67173
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+480]
	and	edx, 1
	test	edx, edx
	je	SHORT $L67173

; 932  : 			Fax3FlushBits(tif, sp);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [eax+484]
	cmp	edx, DWORD PTR [ecx+476]
	jl	SHORT $L67174
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFlushData1
	add	esp, 4
$L67174:
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+480]
	mov	eax, DWORD PTR _sp$[ebp]
	mov	cl, BYTE PTR [eax+52]
	mov	BYTE PTR [edx], cl
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+480]
	add	eax, 1
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+480], eax
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+484]
	add	eax, 1
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+484], eax
	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+52], 0
	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+56], 8
$L67173:

; 934  : 	return (1);

	mov	eax, 1

; 935  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Fax3Encode1DRow ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+1
$SG66998 DB	'C:\Documents and Settings\Administrator\', 0aeH, 0e0H, 0adH
	DB	0b1H, '\', 0bdH, 'd', 0a8H, 0d2H, '\codeproject\wrk\_vendor\ti'
	DB	'fflib\libtiff\tif_fax3.c', 00H
	ORG $+3
$SG66999 DB	'te->runlen == 64*(span>>6)', 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_span$ = 12
_tab$ = 16
_sp$ = -8
_bit$ = -20
_data$ = -4
_code$ = -16
_length$ = -12
_te$66986 = -24
_te$66996 = -28
_putspan PROC NEAR

; 602  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 28					; 0000001cH

; 603  : 	Fax3EncodeState* sp = EncoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 604  : 	u_int bit = sp->bit;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	DWORD PTR _bit$[ebp], eax

; 605  : 	int data = sp->data;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+52]
	mov	DWORD PTR _data$[ebp], edx
$L66984:

; 606  : 	u_int code, length;
; 607  : 
; 608  : 	while (span >= 2624) {

	cmp	DWORD PTR _span$[ebp], 2624		; 00000a40H
	jl	$L66985

; 609  : 		const tableentry* te = &tab[63 + (2560>>6)];

	mov	eax, DWORD PTR _tab$[ebp]
	add	eax, 618				; 0000026aH
	mov	DWORD PTR _te$66986[ebp], eax

; 610  : 		code = te->code, length = te->length;

	mov	ecx, DWORD PTR _te$66986[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+2]
	mov	DWORD PTR _code$[ebp], edx
	mov	eax, DWORD PTR _te$66986[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax]
	mov	DWORD PTR _length$[ebp], ecx
$L66988:

; 611  : #ifdef FAX3_DEBUG
; 612  : 		DEBUG_PRINT("MakeUp", te->runlen);
; 613  : #endif
; 614  : 		_PutBits(tif, code, length);

	mov	edx, DWORD PTR _length$[ebp]
	cmp	edx, DWORD PTR _bit$[ebp]
	jbe	$L66989
	mov	ecx, DWORD PTR _length$[ebp]
	sub	ecx, DWORD PTR _bit$[ebp]
	mov	eax, DWORD PTR _code$[ebp]
	shr	eax, cl
	mov	ecx, DWORD PTR _data$[ebp]
	or	ecx, eax
	mov	DWORD PTR _data$[ebp], ecx
	mov	edx, DWORD PTR _length$[ebp]
	sub	edx, DWORD PTR _bit$[ebp]
	mov	DWORD PTR _length$[ebp], edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [eax+484]
	cmp	edx, DWORD PTR [ecx+476]
	jl	SHORT $L66990
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFlushData1
	add	esp, 4
$L66990:
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+480]
	mov	al, BYTE PTR _data$[ebp]
	mov	BYTE PTR [edx], al
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+480]
	add	edx, 1
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+480], edx
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+484]
	add	edx, 1
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+484], edx
	mov	DWORD PTR _data$[ebp], 0
	mov	DWORD PTR _bit$[ebp], 8
	jmp	$L66988
$L66989:
	mov	ecx, DWORD PTR _length$[ebp]
	mov	edx, DWORD PTR _code$[ebp]
	and	edx, DWORD PTR __msbmask[ecx*4]
	mov	ecx, DWORD PTR _bit$[ebp]
	sub	ecx, DWORD PTR _length$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _data$[ebp]
	or	eax, edx
	mov	DWORD PTR _data$[ebp], eax
	mov	ecx, DWORD PTR _bit$[ebp]
	sub	ecx, DWORD PTR _length$[ebp]
	mov	DWORD PTR _bit$[ebp], ecx
	cmp	DWORD PTR _bit$[ebp], 0
	jne	SHORT $L66992
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [edx+484]
	cmp	ecx, DWORD PTR [eax+476]
	jl	SHORT $L66993
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFlushData1
	add	esp, 4
$L66993:
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	dl, BYTE PTR _data$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+480], ecx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+484]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], ecx
	mov	DWORD PTR _data$[ebp], 0
	mov	DWORD PTR _bit$[ebp], 8
$L66992:

; 615  : 		span -= te->runlen;

	mov	eax, DWORD PTR _te$66986[ebp]
	movsx	ecx, WORD PTR [eax+4]
	mov	edx, DWORD PTR _span$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _span$[ebp], edx

; 616  : 	}

	jmp	$L66984
$L66985:

; 617  : 	if (span >= 64) {

	cmp	DWORD PTR _span$[ebp], 64		; 00000040H
	jl	$L66995

; 618  : 		const tableentry* te = &tab[63 + (span>>6)];

	mov	eax, DWORD PTR _span$[ebp]
	sar	eax, 6
	add	eax, 63					; 0000003fH
	imul	eax, 6
	mov	ecx, DWORD PTR _tab$[ebp]
	add	ecx, eax
	mov	DWORD PTR _te$66996[ebp], ecx

; 619  : 		assert(te->runlen == 64*(span>>6));

	mov	edx, DWORD PTR _te$66996[ebp]
	movsx	eax, WORD PTR [edx+4]
	mov	ecx, DWORD PTR _span$[ebp]
	sar	ecx, 6
	shl	ecx, 6
	cmp	eax, ecx
	je	SHORT $L68243
	push	619					; 0000026bH
	push	OFFSET FLAT:$SG66998
	push	OFFSET FLAT:$SG66999
	call	__assert
	add	esp, 12					; 0000000cH
$L68243:

; 620  : 		code = te->code, length = te->length;

	mov	eax, DWORD PTR _te$66996[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+2]
	mov	DWORD PTR _code$[ebp], ecx
	mov	edx, DWORD PTR _te$66996[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx]
	mov	DWORD PTR _length$[ebp], eax
$L67001:

; 621  : #ifdef FAX3_DEBUG
; 622  : 		DEBUG_PRINT("MakeUp", te->runlen);
; 623  : #endif
; 624  : 		_PutBits(tif, code, length);

	mov	ecx, DWORD PTR _length$[ebp]
	cmp	ecx, DWORD PTR _bit$[ebp]
	jbe	$L67002
	mov	ecx, DWORD PTR _length$[ebp]
	sub	ecx, DWORD PTR _bit$[ebp]
	mov	edx, DWORD PTR _code$[ebp]
	shr	edx, cl
	mov	eax, DWORD PTR _data$[ebp]
	or	eax, edx
	mov	DWORD PTR _data$[ebp], eax
	mov	ecx, DWORD PTR _length$[ebp]
	sub	ecx, DWORD PTR _bit$[ebp]
	mov	DWORD PTR _length$[ebp], ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [edx+484]
	cmp	ecx, DWORD PTR [eax+476]
	jl	SHORT $L67003
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFlushData1
	add	esp, 4
$L67003:
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	dl, BYTE PTR _data$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+480], ecx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+484]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], ecx
	mov	DWORD PTR _data$[ebp], 0
	mov	DWORD PTR _bit$[ebp], 8
	jmp	$L67001
$L67002:
	mov	eax, DWORD PTR _length$[ebp]
	mov	edx, DWORD PTR _code$[ebp]
	and	edx, DWORD PTR __msbmask[eax*4]
	mov	ecx, DWORD PTR _bit$[ebp]
	sub	ecx, DWORD PTR _length$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _data$[ebp]
	or	eax, edx
	mov	DWORD PTR _data$[ebp], eax
	mov	ecx, DWORD PTR _bit$[ebp]
	sub	ecx, DWORD PTR _length$[ebp]
	mov	DWORD PTR _bit$[ebp], ecx
	cmp	DWORD PTR _bit$[ebp], 0
	jne	SHORT $L67005
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [edx+484]
	cmp	ecx, DWORD PTR [eax+476]
	jl	SHORT $L67006
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFlushData1
	add	esp, 4
$L67006:
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	dl, BYTE PTR _data$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+480], ecx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+484]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], ecx
	mov	DWORD PTR _data$[ebp], 0
	mov	DWORD PTR _bit$[ebp], 8
$L67005:

; 625  : 		span -= te->runlen;

	mov	eax, DWORD PTR _te$66996[ebp]
	movsx	ecx, WORD PTR [eax+4]
	mov	edx, DWORD PTR _span$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _span$[ebp], edx
$L66995:

; 627  : 	code = tab[span].code, length = tab[span].length;

	mov	eax, DWORD PTR _span$[ebp]
	imul	eax, 6
	mov	ecx, DWORD PTR _tab$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+eax+2]
	mov	DWORD PTR _code$[ebp], edx
	mov	eax, DWORD PTR _span$[ebp]
	imul	eax, 6
	mov	ecx, DWORD PTR _tab$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+eax]
	mov	DWORD PTR _length$[ebp], edx
$L67009:

; 628  : #ifdef FAX3_DEBUG
; 629  : 	DEBUG_PRINT("  Term", tab[span].runlen);
; 630  : #endif
; 631  : 	_PutBits(tif, code, length);

	mov	eax, DWORD PTR _length$[ebp]
	cmp	eax, DWORD PTR _bit$[ebp]
	jbe	$L67010
	mov	ecx, DWORD PTR _length$[ebp]
	sub	ecx, DWORD PTR _bit$[ebp]
	mov	edx, DWORD PTR _code$[ebp]
	shr	edx, cl
	mov	eax, DWORD PTR _data$[ebp]
	or	eax, edx
	mov	DWORD PTR _data$[ebp], eax
	mov	ecx, DWORD PTR _length$[ebp]
	sub	ecx, DWORD PTR _bit$[ebp]
	mov	DWORD PTR _length$[ebp], ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [edx+484]
	cmp	ecx, DWORD PTR [eax+476]
	jl	SHORT $L67011
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFlushData1
	add	esp, 4
$L67011:
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	dl, BYTE PTR _data$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+480], ecx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+484]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], ecx
	mov	DWORD PTR _data$[ebp], 0
	mov	DWORD PTR _bit$[ebp], 8
	jmp	$L67009
$L67010:
	mov	eax, DWORD PTR _length$[ebp]
	mov	edx, DWORD PTR _code$[ebp]
	and	edx, DWORD PTR __msbmask[eax*4]
	mov	ecx, DWORD PTR _bit$[ebp]
	sub	ecx, DWORD PTR _length$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _data$[ebp]
	or	eax, edx
	mov	DWORD PTR _data$[ebp], eax
	mov	ecx, DWORD PTR _bit$[ebp]
	sub	ecx, DWORD PTR _length$[ebp]
	mov	DWORD PTR _bit$[ebp], ecx
	cmp	DWORD PTR _bit$[ebp], 0
	jne	SHORT $L67013
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [edx+484]
	cmp	ecx, DWORD PTR [eax+476]
	jl	SHORT $L67014
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFlushData1
	add	esp, 4
$L67014:
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	dl, BYTE PTR _data$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+480], ecx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+484]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], ecx
	mov	DWORD PTR _data$[ebp], 0
	mov	DWORD PTR _bit$[ebp], 8
$L67013:

; 632  : 
; 633  : 	sp->data = data;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	DWORD PTR [eax+52], ecx

; 634  : 	sp->bit = bit;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _bit$[ebp]
	mov	DWORD PTR [edx+56], eax

; 635  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_putspan ENDP
_bp$ = 8
_bs$ = 12
_be$ = 16
_bits$ = -4
_n$ = -12
_span$ = -8
_lp$67089 = -16
_find0span PROC NEAR

; 772  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 20					; 00000014H

; 773  : 	int32 bits = be - bs;

	mov	eax, DWORD PTR _be$[ebp]
	sub	eax, DWORD PTR _bs$[ebp]
	mov	DWORD PTR _bits$[ebp], eax

; 774  : 	int32 n, span;
; 775  : 
; 776  : 	bp += bs>>3;

	mov	ecx, DWORD PTR _bs$[ebp]
	sar	ecx, 3
	mov	edx, DWORD PTR _bp$[ebp]
	add	edx, ecx
	mov	DWORD PTR _bp$[ebp], edx

; 777  : 	/*
; 778  : 	 * Check partial byte on lhs.
; 779  : 	 */
; 780  : 	if (bits > 0 && (n = (bs & 7))) {

	cmp	DWORD PTR _bits$[ebp], 0
	jle	SHORT $L67082
	mov	eax, DWORD PTR _bs$[ebp]
	and	eax, 7
	mov	DWORD PTR _n$[ebp], eax
	cmp	DWORD PTR _n$[ebp], 0
	je	SHORT $L67082

; 781  : 		span = zeroruns[(*bp << n) & 0xff];

	mov	ecx, DWORD PTR _bp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, DWORD PTR _n$[ebp]
	shl	edx, cl
	and	edx, 255				; 000000ffH
	xor	eax, eax
	mov	al, BYTE PTR _zeroruns[edx]
	mov	DWORD PTR _span$[ebp], eax

; 782  : 		if (span > 8-n)		/* table value too generous */

	mov	ecx, 8
	sub	ecx, DWORD PTR _n$[ebp]
	cmp	DWORD PTR _span$[ebp], ecx
	jle	SHORT $L67083

; 783  : 			span = 8-n;

	mov	edx, 8
	sub	edx, DWORD PTR _n$[ebp]
	mov	DWORD PTR _span$[ebp], edx
$L67083:

; 784  : 		if (span > bits)	/* constrain span to bit range */

	mov	eax, DWORD PTR _span$[ebp]
	cmp	eax, DWORD PTR _bits$[ebp]
	jle	SHORT $L67084

; 785  : 			span = bits;

	mov	ecx, DWORD PTR _bits$[ebp]
	mov	DWORD PTR _span$[ebp], ecx
$L67084:

; 786  : 		if (n+span < 8)		/* doesn't extend to edge of byte */

	mov	edx, DWORD PTR _n$[ebp]
	add	edx, DWORD PTR _span$[ebp]
	cmp	edx, 8
	jge	SHORT $L67085

; 787  : 			return (span);

	mov	eax, DWORD PTR _span$[ebp]
	jmp	$L67078
$L67085:

; 788  : 		bits -= span;

	mov	eax, DWORD PTR _bits$[ebp]
	sub	eax, DWORD PTR _span$[ebp]
	mov	DWORD PTR _bits$[ebp], eax

; 789  : 		bp++;

	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _bp$[ebp], ecx

; 790  : 	} else

	jmp	SHORT $L67086
$L67082:

; 791  : 		span = 0;

	mov	DWORD PTR _span$[ebp], 0
$L67086:

; 792  : 	if (bits >= 2*8*sizeof (long)) {

	cmp	DWORD PTR _bits$[ebp], 64		; 00000040H
	jb	$L67088
$L67093:

; 793  : 		long* lp;
; 794  : 		/*
; 795  : 		 * Align to longword boundary and check longwords.
; 796  : 		 */
; 797  : 		while (!isAligned(bp, long)) {

	mov	edx, DWORD PTR _bp$[ebp]
	and	edx, 3
	test	edx, edx
	je	SHORT $L67094

; 798  : 			if (*bp != 0x00)

	mov	eax, DWORD PTR _bp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	test	ecx, ecx
	je	SHORT $L67095

; 799  : 				return (span + zeroruns[*bp]);

	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	xor	ecx, ecx
	mov	cl, BYTE PTR _zeroruns[eax]
	mov	eax, DWORD PTR _span$[ebp]
	add	eax, ecx
	jmp	$L67078
$L67095:

; 800  : 			span += 8, bits -= 8;

	mov	edx, DWORD PTR _span$[ebp]
	add	edx, 8
	mov	DWORD PTR _span$[ebp], edx
	mov	eax, DWORD PTR _bits$[ebp]
	sub	eax, 8
	mov	DWORD PTR _bits$[ebp], eax

; 801  : 			bp++;

	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _bp$[ebp], ecx

; 802  : 		}

	jmp	SHORT $L67093
$L67094:

; 803  : 		lp = (long*) bp;

	mov	edx, DWORD PTR _bp$[ebp]
	mov	DWORD PTR _lp$67089[ebp], edx
$L67099:

; 804  : 		while (bits >= 8*sizeof (long) && *lp == 0) {

	cmp	DWORD PTR _bits$[ebp], 32		; 00000020H
	jb	SHORT $L67100
	mov	eax, DWORD PTR _lp$67089[ebp]
	cmp	DWORD PTR [eax], 0
	jne	SHORT $L67100

; 805  : 			span += 8*sizeof (long), bits -= 8*sizeof (long);

	mov	ecx, DWORD PTR _span$[ebp]
	add	ecx, 32					; 00000020H
	mov	DWORD PTR _span$[ebp], ecx
	mov	edx, DWORD PTR _bits$[ebp]
	sub	edx, 32					; 00000020H
	mov	DWORD PTR _bits$[ebp], edx

; 806  : 			lp++;

	mov	eax, DWORD PTR _lp$67089[ebp]
	add	eax, 4
	mov	DWORD PTR _lp$67089[ebp], eax

; 807  : 		}

	jmp	SHORT $L67099
$L67100:

; 808  : 		bp = (u_char*) lp;

	mov	ecx, DWORD PTR _lp$67089[ebp]
	mov	DWORD PTR _bp$[ebp], ecx
$L67088:

; 810  : 	/*
; 811  : 	 * Scan full bytes for all 0's.
; 812  : 	 */
; 813  : 	while (bits >= 8) {

	cmp	DWORD PTR _bits$[ebp], 8
	jl	SHORT $L67106

; 814  : 		if (*bp != 0x00)	/* end of run */

	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	test	eax, eax
	je	SHORT $L67107

; 815  : 			return (span + zeroruns[*bp]);

	mov	ecx, DWORD PTR _bp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	xor	eax, eax
	mov	al, BYTE PTR _zeroruns[edx]
	mov	ecx, DWORD PTR _span$[ebp]
	add	eax, ecx
	jmp	SHORT $L67078
$L67107:

; 816  : 		span += 8, bits -= 8;

	mov	edx, DWORD PTR _span$[ebp]
	add	edx, 8
	mov	DWORD PTR _span$[ebp], edx
	mov	eax, DWORD PTR _bits$[ebp]
	sub	eax, 8
	mov	DWORD PTR _bits$[ebp], eax

; 817  : 		bp++;

	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _bp$[ebp], ecx

; 818  : 	}

	jmp	SHORT $L67088
$L67106:

; 819  : 	/*
; 820  : 	 * Check partial byte on rhs.
; 821  : 	 */
; 822  : 	if (bits > 0) {

	cmp	DWORD PTR _bits$[ebp], 0
	jle	SHORT $L67108

; 823  : 		n = zeroruns[*bp];

	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	xor	ecx, ecx
	mov	cl, BYTE PTR _zeroruns[eax]
	mov	DWORD PTR _n$[ebp], ecx

; 824  : 		span += (n > bits ? bits : n);

	mov	edx, DWORD PTR _n$[ebp]
	cmp	edx, DWORD PTR _bits$[ebp]
	jle	SHORT $L68245
	mov	eax, DWORD PTR _bits$[ebp]
	mov	DWORD PTR -20+[ebp], eax
	jmp	SHORT $L68246
$L68245:
	mov	ecx, DWORD PTR _n$[ebp]
	mov	DWORD PTR -20+[ebp], ecx
$L68246:
	mov	edx, DWORD PTR _span$[ebp]
	add	edx, DWORD PTR -20+[ebp]
	mov	DWORD PTR _span$[ebp], edx
$L67108:

; 826  : 	return (span);

	mov	eax, DWORD PTR _span$[ebp]
$L67078:

; 827  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_find0span ENDP
_bp$ = 8
_bs$ = 12
_be$ = 16
_bits$ = -4
_n$ = -12
_span$ = -8
_lp$67127 = -16
_find1span PROC NEAR

; 831  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 20					; 00000014H

; 832  : 	int32 bits = be - bs;

	mov	eax, DWORD PTR _be$[ebp]
	sub	eax, DWORD PTR _bs$[ebp]
	mov	DWORD PTR _bits$[ebp], eax

; 833  : 	int32 n, span;
; 834  : 
; 835  : 	bp += bs>>3;

	mov	ecx, DWORD PTR _bs$[ebp]
	sar	ecx, 3
	mov	edx, DWORD PTR _bp$[ebp]
	add	edx, ecx
	mov	DWORD PTR _bp$[ebp], edx

; 836  : 	/*
; 837  : 	 * Check partial byte on lhs.
; 838  : 	 */
; 839  : 	if (bits > 0 && (n = (bs & 7))) {

	cmp	DWORD PTR _bits$[ebp], 0
	jle	SHORT $L67120
	mov	eax, DWORD PTR _bs$[ebp]
	and	eax, 7
	mov	DWORD PTR _n$[ebp], eax
	cmp	DWORD PTR _n$[ebp], 0
	je	SHORT $L67120

; 840  : 		span = oneruns[(*bp << n) & 0xff];

	mov	ecx, DWORD PTR _bp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	ecx, DWORD PTR _n$[ebp]
	shl	edx, cl
	and	edx, 255				; 000000ffH
	xor	eax, eax
	mov	al, BYTE PTR _oneruns[edx]
	mov	DWORD PTR _span$[ebp], eax

; 841  : 		if (span > 8-n)		/* table value too generous */

	mov	ecx, 8
	sub	ecx, DWORD PTR _n$[ebp]
	cmp	DWORD PTR _span$[ebp], ecx
	jle	SHORT $L67121

; 842  : 			span = 8-n;

	mov	edx, 8
	sub	edx, DWORD PTR _n$[ebp]
	mov	DWORD PTR _span$[ebp], edx
$L67121:

; 843  : 		if (span > bits)	/* constrain span to bit range */

	mov	eax, DWORD PTR _span$[ebp]
	cmp	eax, DWORD PTR _bits$[ebp]
	jle	SHORT $L67122

; 844  : 			span = bits;

	mov	ecx, DWORD PTR _bits$[ebp]
	mov	DWORD PTR _span$[ebp], ecx
$L67122:

; 845  : 		if (n+span < 8)		/* doesn't extend to edge of byte */

	mov	edx, DWORD PTR _n$[ebp]
	add	edx, DWORD PTR _span$[ebp]
	cmp	edx, 8
	jge	SHORT $L67123

; 846  : 			return (span);

	mov	eax, DWORD PTR _span$[ebp]
	jmp	$L67116
$L67123:

; 847  : 		bits -= span;

	mov	eax, DWORD PTR _bits$[ebp]
	sub	eax, DWORD PTR _span$[ebp]
	mov	DWORD PTR _bits$[ebp], eax

; 848  : 		bp++;

	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _bp$[ebp], ecx

; 849  : 	} else

	jmp	SHORT $L67124
$L67120:

; 850  : 		span = 0;

	mov	DWORD PTR _span$[ebp], 0
$L67124:

; 851  : 	if (bits >= 2*8*sizeof (long)) {

	cmp	DWORD PTR _bits$[ebp], 64		; 00000040H
	jb	$L67126
$L67131:

; 852  : 		long* lp;
; 853  : 		/*
; 854  : 		 * Align to longword boundary and check longwords.
; 855  : 		 */
; 856  : 		while (!isAligned(bp, long)) {

	mov	edx, DWORD PTR _bp$[ebp]
	and	edx, 3
	test	edx, edx
	je	SHORT $L67132

; 857  : 			if (*bp != 0xff)

	mov	eax, DWORD PTR _bp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	cmp	ecx, 255				; 000000ffH
	je	SHORT $L67133

; 858  : 				return (span + oneruns[*bp]);

	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	xor	ecx, ecx
	mov	cl, BYTE PTR _oneruns[eax]
	mov	eax, DWORD PTR _span$[ebp]
	add	eax, ecx
	jmp	$L67116
$L67133:

; 859  : 			span += 8, bits -= 8;

	mov	edx, DWORD PTR _span$[ebp]
	add	edx, 8
	mov	DWORD PTR _span$[ebp], edx
	mov	eax, DWORD PTR _bits$[ebp]
	sub	eax, 8
	mov	DWORD PTR _bits$[ebp], eax

; 860  : 			bp++;

	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _bp$[ebp], ecx

; 861  : 		}

	jmp	SHORT $L67131
$L67132:

; 862  : 		lp = (long*) bp;

	mov	edx, DWORD PTR _bp$[ebp]
	mov	DWORD PTR _lp$67127[ebp], edx
$L67137:

; 863  : 		while (bits >= 8*sizeof (long) && *lp == ~0) {

	cmp	DWORD PTR _bits$[ebp], 32		; 00000020H
	jb	SHORT $L67138
	mov	eax, DWORD PTR _lp$67127[ebp]
	cmp	DWORD PTR [eax], -1
	jne	SHORT $L67138

; 864  : 			span += 8*sizeof (long), bits -= 8*sizeof (long);

	mov	ecx, DWORD PTR _span$[ebp]
	add	ecx, 32					; 00000020H
	mov	DWORD PTR _span$[ebp], ecx
	mov	edx, DWORD PTR _bits$[ebp]
	sub	edx, 32					; 00000020H
	mov	DWORD PTR _bits$[ebp], edx

; 865  : 			lp++;

	mov	eax, DWORD PTR _lp$67127[ebp]
	add	eax, 4
	mov	DWORD PTR _lp$67127[ebp], eax

; 866  : 		}

	jmp	SHORT $L67137
$L67138:

; 867  : 		bp = (u_char*) lp;

	mov	ecx, DWORD PTR _lp$67127[ebp]
	mov	DWORD PTR _bp$[ebp], ecx
$L67126:

; 869  : 	/*
; 870  : 	 * Scan full bytes for all 1's.
; 871  : 	 */
; 872  : 	while (bits >= 8) {

	cmp	DWORD PTR _bits$[ebp], 8
	jl	SHORT $L67144

; 873  : 		if (*bp != 0xff)	/* end of run */

	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	cmp	eax, 255				; 000000ffH
	je	SHORT $L67145

; 874  : 			return (span + oneruns[*bp]);

	mov	ecx, DWORD PTR _bp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	xor	eax, eax
	mov	al, BYTE PTR _oneruns[edx]
	mov	ecx, DWORD PTR _span$[ebp]
	add	eax, ecx
	jmp	SHORT $L67116
$L67145:

; 875  : 		span += 8, bits -= 8;

	mov	edx, DWORD PTR _span$[ebp]
	add	edx, 8
	mov	DWORD PTR _span$[ebp], edx
	mov	eax, DWORD PTR _bits$[ebp]
	sub	eax, 8
	mov	DWORD PTR _bits$[ebp], eax

; 876  : 		bp++;

	mov	ecx, DWORD PTR _bp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _bp$[ebp], ecx

; 877  : 	}

	jmp	SHORT $L67126
$L67144:

; 878  : 	/*
; 879  : 	 * Check partial byte on rhs.
; 880  : 	 */
; 881  : 	if (bits > 0) {

	cmp	DWORD PTR _bits$[ebp], 0
	jle	SHORT $L67146

; 882  : 		n = oneruns[*bp];

	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	xor	ecx, ecx
	mov	cl, BYTE PTR _oneruns[eax]
	mov	DWORD PTR _n$[ebp], ecx

; 883  : 		span += (n > bits ? bits : n);

	mov	edx, DWORD PTR _n$[ebp]
	cmp	edx, DWORD PTR _bits$[ebp]
	jle	SHORT $L68248
	mov	eax, DWORD PTR _bits$[ebp]
	mov	DWORD PTR -20+[ebp], eax
	jmp	SHORT $L68249
$L68248:
	mov	ecx, DWORD PTR _n$[ebp]
	mov	DWORD PTR -20+[ebp], ecx
$L68249:
	mov	edx, DWORD PTR _span$[ebp]
	add	edx, DWORD PTR -20+[ebp]
	mov	DWORD PTR _span$[ebp], edx
$L67146:

; 885  : 	return (span);

	mov	eax, DWORD PTR _span$[ebp]
$L67116:

; 886  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_find1span ENDP
_tif$ = 8
_bp$ = 12
_rp$ = 16
_bits$ = 20
_a0$ = -8
_a1$ = -12
_b1$ = -20
_a2$ = -16
_b2$ = -4
_d$67199 = -24
_Fax3Encode2DRow PROC NEAR

; 957  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 60					; 0000003cH

; 958  : #define	PIXEL(buf,ix)	((((buf)[(ix)>>3]) >> (7-((ix)&7))) & 1)
; 959  :         uint32 a0 = 0;

	mov	DWORD PTR _a0$[ebp], 0

; 960  : 	uint32 a1 = (PIXEL(bp, 0) != 0 ? 0 : finddiff(bp, 0, bits, 0));

	mov	eax, DWORD PTR _bp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	sar	ecx, 7
	and	ecx, 1
	test	ecx, ecx
	je	SHORT $L68251
	mov	DWORD PTR -28+[ebp], 0
	jmp	SHORT $L68252
$L68251:
	mov	edx, DWORD PTR _bits$[ebp]
	push	edx
	push	0
	mov	eax, DWORD PTR _bp$[ebp]
	push	eax
	call	_find0span
	add	esp, 12					; 0000000cH
	mov	DWORD PTR -28+[ebp], eax
$L68252:
	mov	ecx, DWORD PTR -28+[ebp]
	mov	DWORD PTR _a1$[ebp], ecx

; 961  : 	uint32 b1 = (PIXEL(rp, 0) != 0 ? 0 : finddiff(rp, 0, bits, 0));

	mov	edx, DWORD PTR _rp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	sar	eax, 7
	and	eax, 1
	test	eax, eax
	je	SHORT $L68253
	mov	DWORD PTR -32+[ebp], 0
	jmp	SHORT $L68254
$L68253:
	mov	ecx, DWORD PTR _bits$[ebp]
	push	ecx
	push	0
	mov	edx, DWORD PTR _rp$[ebp]
	push	edx
	call	_find0span
	add	esp, 12					; 0000000cH
	mov	DWORD PTR -32+[ebp], eax
$L68254:
	mov	eax, DWORD PTR -32+[ebp]
	mov	DWORD PTR _b1$[ebp], eax
$L67196:

; 965  : 		b2 = finddiff2(rp, b1, bits, PIXEL(rp,b1));

	mov	ecx, DWORD PTR _b1$[ebp]
	cmp	ecx, DWORD PTR _bits$[ebp]
	jae	SHORT $L68257
	mov	edx, DWORD PTR _b1$[ebp]
	shr	edx, 3
	mov	eax, DWORD PTR _rp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	eax, DWORD PTR _b1$[ebp]
	and	eax, 7
	mov	ecx, 7
	sub	ecx, eax
	sar	edx, cl
	and	edx, 1
	test	edx, edx
	je	SHORT $L68255
	mov	ecx, DWORD PTR _bits$[ebp]
	push	ecx
	mov	edx, DWORD PTR _b1$[ebp]
	push	edx
	mov	eax, DWORD PTR _rp$[ebp]
	push	eax
	call	_find1span
	add	esp, 12					; 0000000cH
	mov	DWORD PTR -36+[ebp], eax
	jmp	SHORT $L68256
$L68255:
	mov	ecx, DWORD PTR _bits$[ebp]
	push	ecx
	mov	edx, DWORD PTR _b1$[ebp]
	push	edx
	mov	eax, DWORD PTR _rp$[ebp]
	push	eax
	call	_find0span
	add	esp, 12					; 0000000cH
	mov	DWORD PTR -36+[ebp], eax
$L68256:
	mov	ecx, DWORD PTR _b1$[ebp]
	add	ecx, DWORD PTR -36+[ebp]
	mov	DWORD PTR -40+[ebp], ecx
	jmp	SHORT $L68258
$L68257:
	mov	edx, DWORD PTR _bits$[ebp]
	mov	DWORD PTR -40+[ebp], edx
$L68258:
	mov	eax, DWORD PTR -40+[ebp]
	mov	DWORD PTR _b2$[ebp], eax

; 966  : 		if (b2 >= a1) {

	mov	ecx, DWORD PTR _b2$[ebp]
	cmp	ecx, DWORD PTR _a1$[ebp]
	jb	$L67198

; 967  : 			int32 d = b1 - a1;

	mov	edx, DWORD PTR _b1$[ebp]
	sub	edx, DWORD PTR _a1$[ebp]
	mov	DWORD PTR _d$67199[ebp], edx

; 968  : 			if (!(-3 <= d && d <= 3)) {	/* horizontal mode */

	cmp	DWORD PTR _d$67199[ebp], -3		; fffffffdH
	jl	SHORT $L67201
	cmp	DWORD PTR _d$67199[ebp], 3
	jle	$L67200
$L67201:

; 969  : 				a2 = finddiff2(bp, a1, bits, PIXEL(bp,a1));

	mov	eax, DWORD PTR _a1$[ebp]
	cmp	eax, DWORD PTR _bits$[ebp]
	jae	SHORT $L68261
	mov	ecx, DWORD PTR _a1$[ebp]
	shr	ecx, 3
	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _a1$[ebp]
	and	ecx, 7
	mov	edx, 7
	sub	edx, ecx
	mov	ecx, edx
	sar	eax, cl
	and	eax, 1
	test	eax, eax
	je	SHORT $L68259
	mov	eax, DWORD PTR _bits$[ebp]
	push	eax
	mov	ecx, DWORD PTR _a1$[ebp]
	push	ecx
	mov	edx, DWORD PTR _bp$[ebp]
	push	edx
	call	_find1span
	add	esp, 12					; 0000000cH
	mov	DWORD PTR -44+[ebp], eax
	jmp	SHORT $L68260
$L68259:
	mov	eax, DWORD PTR _bits$[ebp]
	push	eax
	mov	ecx, DWORD PTR _a1$[ebp]
	push	ecx
	mov	edx, DWORD PTR _bp$[ebp]
	push	edx
	call	_find0span
	add	esp, 12					; 0000000cH
	mov	DWORD PTR -44+[ebp], eax
$L68260:
	mov	eax, DWORD PTR _a1$[ebp]
	add	eax, DWORD PTR -44+[ebp]
	mov	DWORD PTR -48+[ebp], eax
	jmp	SHORT $L68262
$L68261:
	mov	ecx, DWORD PTR _bits$[ebp]
	mov	DWORD PTR -48+[ebp], ecx
$L68262:
	mov	edx, DWORD PTR -48+[ebp]
	mov	DWORD PTR _a2$[ebp], edx

; 970  : 				putcode(tif, &horizcode);

	xor	eax, eax
	mov	ax, WORD PTR _horizcode
	push	eax
	xor	ecx, ecx
	mov	cx, WORD PTR _horizcode+2
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_Fax3PutBits
	add	esp, 12					; 0000000cH

; 971  : 				if (a0+a1 == 0 || PIXEL(bp, a0) == 0) {

	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR _a1$[ebp]
	test	eax, eax
	je	SHORT $L67203
	mov	ecx, DWORD PTR _a0$[ebp]
	shr	ecx, 3
	mov	edx, DWORD PTR _bp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _a0$[ebp]
	and	ecx, 7
	mov	edx, 7
	sub	edx, ecx
	mov	ecx, edx
	sar	eax, cl
	and	eax, 1
	test	eax, eax
	jne	SHORT $L67202
$L67203:

; 972  : 					putspan(tif, a1-a0, TIFFFaxWhiteCodes);

	push	OFFSET FLAT:_TIFFFaxWhiteCodes
	mov	eax, DWORD PTR _a1$[ebp]
	sub	eax, DWORD PTR _a0$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_putspan
	add	esp, 12					; 0000000cH

; 973  : 					putspan(tif, a2-a1, TIFFFaxBlackCodes);

	push	OFFSET FLAT:_TIFFFaxBlackCodes
	mov	edx, DWORD PTR _a2$[ebp]
	sub	edx, DWORD PTR _a1$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_putspan
	add	esp, 12					; 0000000cH

; 974  : 				} else {

	jmp	SHORT $L67204
$L67202:

; 975  : 					putspan(tif, a1-a0, TIFFFaxBlackCodes);

	push	OFFSET FLAT:_TIFFFaxBlackCodes
	mov	ecx, DWORD PTR _a1$[ebp]
	sub	ecx, DWORD PTR _a0$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_putspan
	add	esp, 12					; 0000000cH

; 976  : 					putspan(tif, a2-a1, TIFFFaxWhiteCodes);

	push	OFFSET FLAT:_TIFFFaxWhiteCodes
	mov	eax, DWORD PTR _a2$[ebp]
	sub	eax, DWORD PTR _a1$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_putspan
	add	esp, 12					; 0000000cH
$L67204:

; 978  : 				a0 = a2;

	mov	edx, DWORD PTR _a2$[ebp]
	mov	DWORD PTR _a0$[ebp], edx

; 979  : 			} else {			/* vertical mode */

	jmp	SHORT $L67205
$L67200:

; 980  : 				putcode(tif, &vcodes[d+3]);

	mov	eax, DWORD PTR _d$67199[ebp]
	add	eax, 3
	imul	eax, 6
	xor	ecx, ecx
	mov	cx, WORD PTR _vcodes[eax]
	push	ecx
	mov	edx, DWORD PTR _d$67199[ebp]
	add	edx, 3
	imul	edx, 6
	xor	eax, eax
	mov	ax, WORD PTR _vcodes[edx+2]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_Fax3PutBits
	add	esp, 12					; 0000000cH

; 981  : 				a0 = a1;

	mov	edx, DWORD PTR _a1$[ebp]
	mov	DWORD PTR _a0$[ebp], edx
$L67205:

; 983  : 		} else {				/* pass mode */

	jmp	SHORT $L67206
$L67198:

; 984  : 			putcode(tif, &passcode);

	xor	eax, eax
	mov	ax, WORD PTR _passcode
	push	eax
	xor	ecx, ecx
	mov	cx, WORD PTR _passcode+2
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_Fax3PutBits
	add	esp, 12					; 0000000cH

; 985  : 			a0 = b2;

	mov	eax, DWORD PTR _b2$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
$L67206:

; 987  : 		if (a0 >= bits)

	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _bits$[ebp]
	jb	SHORT $L67207

; 988  : 			break;

	jmp	$L67197
$L67207:

; 989  : 		a1 = finddiff(bp, a0, bits, PIXEL(bp,a0));

	mov	edx, DWORD PTR _a0$[ebp]
	shr	edx, 3
	mov	eax, DWORD PTR _bp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	eax, DWORD PTR _a0$[ebp]
	and	eax, 7
	mov	ecx, 7
	sub	ecx, eax
	sar	edx, cl
	and	edx, 1
	test	edx, edx
	je	SHORT $L68263
	mov	ecx, DWORD PTR _bits$[ebp]
	push	ecx
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _bp$[ebp]
	push	eax
	call	_find1span
	add	esp, 12					; 0000000cH
	mov	DWORD PTR -52+[ebp], eax
	jmp	SHORT $L68264
$L68263:
	mov	ecx, DWORD PTR _bits$[ebp]
	push	ecx
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _bp$[ebp]
	push	eax
	call	_find0span
	add	esp, 12					; 0000000cH
	mov	DWORD PTR -52+[ebp], eax
$L68264:
	mov	ecx, DWORD PTR _a0$[ebp]
	add	ecx, DWORD PTR -52+[ebp]
	mov	DWORD PTR _a1$[ebp], ecx

; 990  : 		b1 = finddiff(rp, a0, bits, !PIXEL(bp,a0));

	mov	edx, DWORD PTR _a0$[ebp]
	shr	edx, 3
	mov	eax, DWORD PTR _bp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	eax, DWORD PTR _a0$[ebp]
	and	eax, 7
	mov	ecx, 7
	sub	ecx, eax
	sar	edx, cl
	and	edx, 1
	test	edx, edx
	jne	SHORT $L68265
	mov	ecx, DWORD PTR _bits$[ebp]
	push	ecx
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _rp$[ebp]
	push	eax
	call	_find1span
	add	esp, 12					; 0000000cH
	mov	DWORD PTR -56+[ebp], eax
	jmp	SHORT $L68266
$L68265:
	mov	ecx, DWORD PTR _bits$[ebp]
	push	ecx
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _rp$[ebp]
	push	eax
	call	_find0span
	add	esp, 12					; 0000000cH
	mov	DWORD PTR -56+[ebp], eax
$L68266:
	mov	ecx, DWORD PTR _a0$[ebp]
	add	ecx, DWORD PTR -56+[ebp]
	mov	DWORD PTR _b1$[ebp], ecx

; 991  : 		b1 = finddiff(rp, b1, bits, PIXEL(bp,a0));

	mov	edx, DWORD PTR _a0$[ebp]
	shr	edx, 3
	mov	eax, DWORD PTR _bp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	eax, DWORD PTR _a0$[ebp]
	and	eax, 7
	mov	ecx, 7
	sub	ecx, eax
	sar	edx, cl
	and	edx, 1
	test	edx, edx
	je	SHORT $L68267
	mov	ecx, DWORD PTR _bits$[ebp]
	push	ecx
	mov	edx, DWORD PTR _b1$[ebp]
	push	edx
	mov	eax, DWORD PTR _rp$[ebp]
	push	eax
	call	_find1span
	add	esp, 12					; 0000000cH
	mov	DWORD PTR -60+[ebp], eax
	jmp	SHORT $L68268
$L68267:
	mov	ecx, DWORD PTR _bits$[ebp]
	push	ecx
	mov	edx, DWORD PTR _b1$[ebp]
	push	edx
	mov	eax, DWORD PTR _rp$[ebp]
	push	eax
	call	_find0span
	add	esp, 12					; 0000000cH
	mov	DWORD PTR -60+[ebp], eax
$L68268:
	mov	ecx, DWORD PTR _b1$[ebp]
	add	ecx, DWORD PTR -60+[ebp]
	mov	DWORD PTR _b1$[ebp], ecx

; 992  : 	}

	jmp	$L67196
$L67197:

; 993  : 	return (1);

	mov	eax, 1

; 994  : #undef PIXEL
; 995  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Fax3Encode2DRow ENDP
_tif$ = 8
_bits$ = 12
_length$ = 16
_sp$ = -8
_bit$ = -12
_data$ = -4
_Fax3PutBits PROC NEAR

; 567  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 568  : 	Fax3EncodeState* sp = EncoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 569  : 	u_int bit = sp->bit;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	DWORD PTR _bit$[ebp], eax

; 570  : 	int data = sp->data;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+52]
	mov	DWORD PTR _data$[ebp], edx
$L66960:

; 571  : 
; 572  : 	_PutBits(tif, bits, length);

	mov	eax, DWORD PTR _length$[ebp]
	cmp	eax, DWORD PTR _bit$[ebp]
	jbe	$L66961
	mov	ecx, DWORD PTR _length$[ebp]
	sub	ecx, DWORD PTR _bit$[ebp]
	mov	edx, DWORD PTR _bits$[ebp]
	shr	edx, cl
	mov	eax, DWORD PTR _data$[ebp]
	or	eax, edx
	mov	DWORD PTR _data$[ebp], eax
	mov	ecx, DWORD PTR _length$[ebp]
	sub	ecx, DWORD PTR _bit$[ebp]
	mov	DWORD PTR _length$[ebp], ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [edx+484]
	cmp	ecx, DWORD PTR [eax+476]
	jl	SHORT $L66962
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFlushData1
	add	esp, 4
$L66962:
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	dl, BYTE PTR _data$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+480], ecx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+484]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], ecx
	mov	DWORD PTR _data$[ebp], 0
	mov	DWORD PTR _bit$[ebp], 8
	jmp	$L66960
$L66961:
	mov	eax, DWORD PTR _length$[ebp]
	mov	edx, DWORD PTR _bits$[ebp]
	and	edx, DWORD PTR __msbmask[eax*4]
	mov	ecx, DWORD PTR _bit$[ebp]
	sub	ecx, DWORD PTR _length$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _data$[ebp]
	or	eax, edx
	mov	DWORD PTR _data$[ebp], eax
	mov	ecx, DWORD PTR _bit$[ebp]
	sub	ecx, DWORD PTR _length$[ebp]
	mov	DWORD PTR _bit$[ebp], ecx
	cmp	DWORD PTR _bit$[ebp], 0
	jne	SHORT $L66964
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [edx+484]
	cmp	ecx, DWORD PTR [eax+476]
	jl	SHORT $L66965
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFlushData1
	add	esp, 4
$L66965:
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	dl, BYTE PTR _data$[ebp]
	mov	BYTE PTR [ecx], dl
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+480], ecx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+484]
	add	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], ecx
	mov	DWORD PTR _data$[ebp], 0
	mov	DWORD PTR _bit$[ebp], 8
$L66964:

; 573  : 
; 574  : 	sp->data = data;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	DWORD PTR [eax+52], ecx

; 575  : 	sp->bit = bit;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _bit$[ebp]
	mov	DWORD PTR [edx+56], eax

; 576  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Fax3PutBits ENDP
_tif$ = 8
_sp$ = -4
_Fax3PostEncode PROC NEAR

; 1038 : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 1039 : 	Fax3EncodeState* sp = EncoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 1040 : 
; 1041 : 	if (sp->bit != 8)

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx+56], 8
	je	SHORT $L67244

; 1042 : 		Fax3FlushBits(tif, sp);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [eax+484]
	cmp	edx, DWORD PTR [ecx+476]
	jl	SHORT $L67245
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFlushData1
	add	esp, 4
$L67245:
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+480]
	mov	eax, DWORD PTR _sp$[ebp]
	mov	cl, BYTE PTR [eax+52]
	mov	BYTE PTR [edx], cl
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+480]
	add	eax, 1
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+480], eax
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+484]
	add	eax, 1
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+484], eax
	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+52], 0
	mov	eax, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [eax+56], 8
$L67244:

; 1043 : 	return (1);

	mov	eax, 1

; 1044 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Fax3PostEncode ENDP
_tif$ = 8
_sp$67253 = -4
_code$67256 = -16
_length$67257 = -8
_i$67258 = -12
_Fax3Close PROC NEAR

; 1048 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 1049 : 	if ((Fax3State(tif)->mode & FAXMODE_NORTC) == 0) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	edx, DWORD PTR [ecx+4]
	and	edx, 1
	test	edx, edx
	jne	$L67252

; 1050 : 		Fax3EncodeState* sp = EncoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$67253[ebp], ecx

; 1051 : 		u_int code = EOL;

	mov	DWORD PTR _code$67256[ebp], 1

; 1052 : 		u_int length = 12;

	mov	DWORD PTR _length$67257[ebp], 12	; 0000000cH

; 1053 : 		int i;
; 1054 : 
; 1055 : 		if (is2DEncoding(sp))

	mov	edx, DWORD PTR _sp$67253[ebp]
	mov	eax, DWORD PTR [edx+28]
	and	eax, 1
	test	eax, eax
	je	SHORT $L67259

; 1056 : 			code = (code<<1) | (sp->tag == G3_1D), length++;

	mov	ecx, DWORD PTR _code$67256[ebp]
	shl	ecx, 1
	mov	edx, DWORD PTR _sp$67253[ebp]
	xor	eax, eax
	cmp	DWORD PTR [edx+60], 0
	sete	al
	or	ecx, eax
	mov	DWORD PTR _code$67256[ebp], ecx
	mov	ecx, DWORD PTR _length$67257[ebp]
	add	ecx, 1
	mov	DWORD PTR _length$67257[ebp], ecx
$L67259:

; 1057 : 		for (i = 0; i < 6; i++)

	mov	DWORD PTR _i$67258[ebp], 0
	jmp	SHORT $L67260
$L67261:
	mov	edx, DWORD PTR _i$67258[ebp]
	add	edx, 1
	mov	DWORD PTR _i$67258[ebp], edx
$L67260:
	cmp	DWORD PTR _i$67258[ebp], 6
	jge	SHORT $L67262

; 1058 : 			Fax3PutBits(tif, code, length);

	mov	eax, DWORD PTR _length$67257[ebp]
	push	eax
	mov	ecx, DWORD PTR _code$67256[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_Fax3PutBits
	add	esp, 12					; 0000000cH
	jmp	SHORT $L67261
$L67262:

; 1059 : 		Fax3FlushBits(tif, sp);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [eax+484]
	cmp	edx, DWORD PTR [ecx+476]
	jl	SHORT $L67263
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFFlushData1
	add	esp, 4
$L67263:
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+480]
	mov	eax, DWORD PTR _sp$67253[ebp]
	mov	cl, BYTE PTR [eax+52]
	mov	BYTE PTR [edx], cl
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+480]
	add	eax, 1
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+480], eax
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+484]
	add	eax, 1
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+484], eax
	mov	edx, DWORD PTR _sp$67253[ebp]
	mov	DWORD PTR [edx+52], 0
	mov	eax, DWORD PTR _sp$67253[ebp]
	mov	DWORD PTR [eax+56], 8
$L67252:

; 1061 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Fax3Close ENDP
_TEXT	ENDS
EXTRN	__TIFFfree:NEAR
_TEXT	SEGMENT
_tif$ = 8
_sp$67272 = -4
_sp$67277 = -8
_Fax3Cleanup PROC NEAR

; 1065 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 1066 : 	if (tif->tif_data) {

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+460], 0
	je	$L67269

; 1067 : 		if (Fax3State(tif)->rw_mode == O_RDONLY) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+460]
	cmp	DWORD PTR [edx], 0
	jne	SHORT $L67271

; 1068 : 			Fax3DecodeState* sp = DecoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$67272[ebp], ecx

; 1069 : 			if (sp->runs)

	mov	edx, DWORD PTR _sp$67272[ebp]
	cmp	DWORD PTR [edx+72], 0
	je	SHORT $L67275

; 1070 : 				_TIFFfree(sp->runs);

	mov	eax, DWORD PTR _sp$67272[ebp]
	mov	ecx, DWORD PTR [eax+72]
	push	ecx
	call	__TIFFfree
	add	esp, 4
$L67275:

; 1071 : 		} else {

	jmp	SHORT $L67280
$L67271:

; 1072 : 			Fax3EncodeState* sp = EncoderState(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+460]
	mov	DWORD PTR _sp$67277[ebp], eax

; 1073 : 			if (sp->refline)

	mov	ecx, DWORD PTR _sp$67277[ebp]
	cmp	DWORD PTR [ecx+64], 0
	je	SHORT $L67280

; 1074 : 				_TIFFfree(sp->refline);

	mov	edx, DWORD PTR _sp$67277[ebp]
	mov	eax, DWORD PTR [edx+64]
	push	eax
	call	__TIFFfree
	add	esp, 4
$L67280:

; 1076 : 		if (Fax3State(tif)->subaddress)

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+460]
	cmp	DWORD PTR [edx+36], 0
	je	SHORT $L67282

; 1077 : 			_TIFFfree(Fax3State(tif)->subaddress);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	edx, DWORD PTR [ecx+36]
	push	edx
	call	__TIFFfree
	add	esp, 4
$L67282:

; 1078 : 		_TIFFfree(tif->tif_data);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	push	ecx
	call	__TIFFfree
	add	esp, 4

; 1079 : 		tif->tif_data = NULL;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+460], 0
$L67269:

; 1081 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Fax3Cleanup ENDP
_TEXT	ENDS
EXTRN	__TIFFsetString:NEAR
EXTRN	__TIFFFieldWithTag:NEAR
_TEXT	SEGMENT
_tif$ = 8
_tag$ = 12
_ap$ = 16
_sp$ = -4
_Fax3VSetField PROC NEAR

; 1126 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 1127 : 	Fax3BaseState* sp = Fax3State(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 1128 : 
; 1129 : 	switch (tag) {

	mov	edx, DWORD PTR _tag$[ebp]
	mov	DWORD PTR -8+[ebp], edx
	cmp	DWORD PTR -8+[ebp], 34908		; 0000885cH
	ja	SHORT $L68274
	cmp	DWORD PTR -8+[ebp], 34908		; 0000885cH
	je	$L67374
	mov	eax, DWORD PTR -8+[ebp]
	sub	eax, 292				; 00000124H
	mov	DWORD PTR -8+[ebp], eax
	cmp	DWORD PTR -8+[ebp], 36			; 00000024H
	ja	$L67398
	mov	edx, DWORD PTR -8+[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR $L68276[edx]
	jmp	DWORD PTR $L68277[ecx*4]
$L68274:
	cmp	DWORD PTR -8+[ebp], 65536		; 00010000H
	ja	SHORT $L68275
	cmp	DWORD PTR -8+[ebp], 65536		; 00010000H
	je	SHORT $L67322
	cmp	DWORD PTR -8+[ebp], 34909		; 0000885dH
	je	$L67382
	cmp	DWORD PTR -8+[ebp], 34910		; 0000885eH
	je	$L67390
	jmp	$L67398
$L68275:
	cmp	DWORD PTR -8+[ebp], 65540		; 00010004H
	je	SHORT $L67330
	jmp	$L67398
$L67322:

; 1130 : 	case TIFFTAG_FAXMODE:
; 1131 : 		sp->mode = va_arg(ap, int);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	DWORD PTR [ecx+4], eax

; 1132 : 		return (1);			/* NB: pseudo tag */

	mov	eax, 1
	jmp	$L67315
$L67330:

; 1133 : 	case TIFFTAG_FAXFILLFUNC:
; 1134 : 		if (sp->rw_mode == O_RDONLY)

	mov	ecx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [ecx], 0
	jne	SHORT $L67331

; 1135 : 			DecoderState(tif)->fill = va_arg(ap, TIFFFaxFillFunc);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	DWORD PTR [ecx+68], eax
$L67331:

; 1136 : 		return (1);			/* NB: pseudo tag */

	mov	eax, 1
	jmp	$L67315
$L67341:

; 1137 : 	case TIFFTAG_GROUP3OPTIONS:
; 1138 : 	case TIFFTAG_GROUP4OPTIONS:
; 1139 : 		sp->groupoptions = va_arg(ap, uint32);

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	DWORD PTR [edx+28], ecx

; 1140 : 		break;

	jmp	$L67319
$L67349:

; 1141 : 	case TIFFTAG_BADFAXLINES:
; 1142 : 		sp->badfaxlines = va_arg(ap, uint32);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	DWORD PTR [eax+24], edx

; 1143 : 		break;

	jmp	$L67319
$L67357:

; 1144 : 	case TIFFTAG_CLEANFAXDATA:
; 1145 : 		sp->cleanfaxdata = (uint16) va_arg(ap, int);

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _ap$[ebp]
	mov	ax, WORD PTR [edx-4]
	mov	WORD PTR [ecx+16], ax

; 1146 : 		break;

	jmp	SHORT $L67319
$L67366:

; 1147 : 	case TIFFTAG_CONSECUTIVEBADFAXLINES:
; 1148 : 		sp->badfaxrun = va_arg(ap, uint32);

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	DWORD PTR [edx+20], ecx

; 1149 : 		break;

	jmp	SHORT $L67319
$L67374:

; 1150 : 	case TIFFTAG_FAXRECVPARAMS:
; 1151 : 		sp->recvparams = va_arg(ap, uint32);

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	DWORD PTR [eax+32], edx

; 1152 : 		break;

	jmp	SHORT $L67319
$L67382:

; 1153 : 	case TIFFTAG_FAXSUBADDRESS:
; 1154 : 		_TIFFsetString(&sp->subaddress, va_arg(ap, char*));

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	add	eax, 36					; 00000024H
	push	eax
	call	__TIFFsetString
	add	esp, 8

; 1155 : 		break;

	jmp	SHORT $L67319
$L67390:

; 1156 : 	case TIFFTAG_FAXRECVTIME:
; 1157 : 		sp->recvtime = va_arg(ap, uint32);

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	DWORD PTR [edx+40], ecx

; 1158 : 		break;

	jmp	SHORT $L67319
$L67398:

; 1159 : 	default:
; 1160 : 		return (*sp->vsetparent)(tif, tag, ap);

	mov	edx, DWORD PTR _ap$[ebp]
	push	edx
	mov	eax, DWORD PTR _tag$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	mov	edx, DWORD PTR _sp$[ebp]
	call	DWORD PTR [edx+48]
	add	esp, 12					; 0000000cH
	jmp	SHORT $L67315
$L67319:

; 1162 : 	TIFFSetFieldBit(tif, _TIFFFieldWithTag(tif, tag)->field_bit);

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
	mov	DWORD PTR -12+[ebp], edx
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
	mov	ecx, DWORD PTR -12+[ebp]
	mov	edx, DWORD PTR [ecx]
	or	edx, eax
	mov	eax, DWORD PTR -12+[ebp]
	mov	DWORD PTR [eax], edx

; 1163 : 	tif->tif_flags |= TIFF_DIRTYDIRECT;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	or	edx, 8
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+12], edx

; 1164 : 	return (1);

	mov	eax, 1
$L67315:

; 1165 : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68277:
	DD	$L67341
	DD	$L67349
	DD	$L67357
	DD	$L67366
	DD	$L67398
$L68276:
	DB	0
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
	DB	1
	DB	2
	DB	3
_Fax3VSetField ENDP
_tif$ = 8
_tag$ = 12
_ap$ = 16
_sp$ = -4
_Fax3VGetField PROC NEAR

; 1169 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 1170 : 	Fax3BaseState* sp = Fax3State(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 1171 : 
; 1172 : 	switch (tag) {

	mov	edx, DWORD PTR _tag$[ebp]
	mov	DWORD PTR -8+[ebp], edx
	cmp	DWORD PTR -8+[ebp], 34908		; 0000885cH
	ja	SHORT $L68279
	cmp	DWORD PTR -8+[ebp], 34908		; 0000885cH
	je	$L67465
	mov	eax, DWORD PTR -8+[ebp]
	sub	eax, 292				; 00000124H
	mov	DWORD PTR -8+[ebp], eax
	cmp	DWORD PTR -8+[ebp], 36			; 00000024H
	ja	$L67489
	mov	edx, DWORD PTR -8+[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR $L68281[edx]
	jmp	DWORD PTR $L68282[ecx*4]
$L68279:
	cmp	DWORD PTR -8+[ebp], 65536		; 00010000H
	ja	SHORT $L68280
	cmp	DWORD PTR -8+[ebp], 65536		; 00010000H
	je	SHORT $L67414
	cmp	DWORD PTR -8+[ebp], 34909		; 0000885dH
	je	$L67473
	cmp	DWORD PTR -8+[ebp], 34910		; 0000885eH
	je	$L67481
	jmp	$L67489
$L68280:
	cmp	DWORD PTR -8+[ebp], 65540		; 00010004H
	je	SHORT $L67422
	jmp	$L67489
$L67414:

; 1173 : 	case TIFFTAG_FAXMODE:
; 1174 : 		*va_arg(ap, int*) = sp->mode;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR [edx], ecx

; 1175 : 		break;

	jmp	$L67411
$L67422:

; 1176 : 	case TIFFTAG_FAXFILLFUNC:
; 1177 : 		if (sp->rw_mode == O_RDONLY)

	mov	edx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [edx], 0
	jne	SHORT $L67423

; 1178 : 			*va_arg(ap, TIFFFaxFillFunc*) = DecoderState(tif)->fill;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [eax-4]
	mov	eax, DWORD PTR [ecx+68]
	mov	DWORD PTR [edx], eax
$L67423:

; 1179 : 		break;

	jmp	$L67411
$L67433:

; 1180 : 	case TIFFTAG_GROUP3OPTIONS:
; 1181 : 	case TIFFTAG_GROUP4OPTIONS:
; 1182 : 		*va_arg(ap, uint32*) = sp->groupoptions;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	mov	DWORD PTR [eax], edx

; 1183 : 		break;

	jmp	$L67411
$L67441:

; 1184 : 	case TIFFTAG_BADFAXLINES:
; 1185 : 		*va_arg(ap, uint32*) = sp->badfaxlines;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	mov	DWORD PTR [edx], ecx

; 1186 : 		break;

	jmp	$L67411
$L67449:

; 1187 : 	case TIFFTAG_CLEANFAXDATA:
; 1188 : 		*va_arg(ap, uint16*) = sp->cleanfaxdata;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _sp$[ebp]
	mov	ax, WORD PTR [edx+16]
	mov	WORD PTR [ecx], ax

; 1189 : 		break;

	jmp	SHORT $L67411
$L67457:

; 1190 : 	case TIFFTAG_CONSECUTIVEBADFAXLINES:
; 1191 : 		*va_arg(ap, uint32*) = sp->badfaxrun;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+20]
	mov	DWORD PTR [eax], edx

; 1192 : 		break;

	jmp	SHORT $L67411
$L67465:

; 1193 : 	case TIFFTAG_FAXRECVPARAMS:
; 1194 : 		*va_arg(ap, uint32*) = sp->recvparams;

	mov	eax, DWORD PTR _ap$[ebp]
	add	eax, 4
	mov	DWORD PTR _ap$[ebp], eax
	mov	ecx, DWORD PTR _ap$[ebp]
	mov	edx, DWORD PTR [ecx-4]
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+32]
	mov	DWORD PTR [edx], ecx

; 1195 : 		break;

	jmp	SHORT $L67411
$L67473:

; 1196 : 	case TIFFTAG_FAXSUBADDRESS:
; 1197 : 		*va_arg(ap, char**) = sp->subaddress;

	mov	edx, DWORD PTR _ap$[ebp]
	add	edx, 4
	mov	DWORD PTR _ap$[ebp], edx
	mov	eax, DWORD PTR _ap$[ebp]
	mov	ecx, DWORD PTR [eax-4]
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+36]
	mov	DWORD PTR [ecx], eax

; 1198 : 		break;

	jmp	SHORT $L67411
$L67481:

; 1199 : 	case TIFFTAG_FAXRECVTIME:
; 1200 : 		*va_arg(ap, uint32*) = sp->recvtime;

	mov	ecx, DWORD PTR _ap$[ebp]
	add	ecx, 4
	mov	DWORD PTR _ap$[ebp], ecx
	mov	edx, DWORD PTR _ap$[ebp]
	mov	eax, DWORD PTR [edx-4]
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	mov	DWORD PTR [eax], edx

; 1201 : 		break;

	jmp	SHORT $L67411
$L67489:

; 1202 : 	default:
; 1203 : 		return (*sp->vgetparent)(tif, tag, ap);

	mov	eax, DWORD PTR _ap$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tag$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	call	DWORD PTR [eax+44]
	add	esp, 12					; 0000000cH
	jmp	SHORT $L67407
$L67411:

; 1205 : 	return (1);

	mov	eax, 1
$L67407:

; 1206 : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68282:
	DD	$L67433
	DD	$L67441
	DD	$L67449
	DD	$L67457
	DD	$L67489
$L68281:
	DB	0
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
	DB	1
	DB	2
	DB	3
_Fax3VGetField ENDP
_TEXT	ENDS
EXTRN	_fprintf:NEAR
_DATA	SEGMENT
	ORG $+1
$SG67504 DB	' ', 00H
	ORG $+2
$SG67506 DB	'  Group 4 Options:', 00H
	ORG $+1
$SG67508 DB	'%suncompressed data', 00H
$SG67510 DB	'  Group 3 Options:', 00H
	ORG $+1
$SG67512 DB	'%s2-d encoding', 00H
	ORG $+1
$SG67513 DB	'+', 00H
	ORG $+2
$SG67515 DB	'%sEOL padding', 00H
	ORG $+2
$SG67516 DB	'+', 00H
	ORG $+2
$SG67518 DB	'%suncompressed data', 00H
$SG67521 DB	' (%lu = 0x%lx)', 0aH, 00H
$SG67524 DB	'  Fax Data:', 00H
$SG67530 DB	' clean', 00H
	ORG $+1
$SG67532 DB	' receiver regenerated', 00H
	ORG $+2
$SG67534 DB	' uncorrected errors', 00H
$SG67535 DB	' (%u = 0x%x)', 0aH, 00H
	ORG $+2
$SG67539 DB	'  Bad Fax Lines: %lu', 0aH, 00H
	ORG $+2
$SG67543 DB	'  Consecutive Bad Fax Lines: %lu', 0aH, 00H
	ORG $+2
$SG67547 DB	'  Fax Receive Parameters: %08lx', 0aH, 00H
	ORG $+3
$SG67550 DB	'  Fax SubAddress: %s', 0aH, 00H
	ORG $+2
$SG67554 DB	'  Fax Receive Time: %lu secs', 0aH, 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_fd$ = 12
_sp$ = -4
_sep$67503 = -8
_Fax3PrintDir PROC NEAR

; 1210 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 1211 : 	Fax3BaseState* sp = Fax3State(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 1212 : 
; 1213 : 	(void) flags;
; 1214 : 	if (TIFFFieldSet(tif,FIELD_OPTIONS)) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+32]
	and	eax, 32					; 00000020H
	test	eax, eax
	je	$L67502

; 1215 : 		const char* sep = " ";

	mov	DWORD PTR _sep$67503[ebp], OFFSET FLAT:$SG67504

; 1216 : 		if (tif->tif_dir.td_compression == COMPRESSION_CCITTFAX4) {

	mov	ecx, DWORD PTR _tif$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+68]
	cmp	edx, 4
	jne	SHORT $L67505

; 1217 : 			fprintf(fd, "  Group 4 Options:");

	push	OFFSET FLAT:$SG67506
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8

; 1218 : 			if (sp->groupoptions & GROUP4OPT_UNCOMPRESSED)

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	and	edx, 2
	test	edx, edx
	je	SHORT $L67507

; 1219 : 				fprintf(fd, "%suncompressed data", sep);

	mov	eax, DWORD PTR _sep$67503[ebp]
	push	eax
	push	OFFSET FLAT:$SG67508
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 12					; 0000000cH
$L67507:

; 1220 : 		} else {

	jmp	$L67517
$L67505:

; 1221 : 
; 1222 : 			fprintf(fd, "  Group 3 Options:");

	push	OFFSET FLAT:$SG67510
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8

; 1223 : 			if (sp->groupoptions & GROUP3OPT_2DENCODING)

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	and	ecx, 1
	test	ecx, ecx
	je	SHORT $L67511

; 1224 : 				fprintf(fd, "%s2-d encoding", sep), sep = "+";

	mov	edx, DWORD PTR _sep$67503[ebp]
	push	edx
	push	OFFSET FLAT:$SG67512
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _sep$67503[ebp], OFFSET FLAT:$SG67513
$L67511:

; 1225 : 			if (sp->groupoptions & GROUP3OPT_FILLBITS)

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	and	edx, 4
	test	edx, edx
	je	SHORT $L67514

; 1226 : 				fprintf(fd, "%sEOL padding", sep), sep = "+";

	mov	eax, DWORD PTR _sep$67503[ebp]
	push	eax
	push	OFFSET FLAT:$SG67515
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 12					; 0000000cH
	mov	DWORD PTR _sep$67503[ebp], OFFSET FLAT:$SG67516
$L67514:

; 1227 : 			if (sp->groupoptions & GROUP3OPT_UNCOMPRESSED)

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+28]
	and	eax, 2
	test	eax, eax
	je	SHORT $L67517

; 1228 : 				fprintf(fd, "%suncompressed data", sep);

	mov	ecx, DWORD PTR _sep$67503[ebp]
	push	ecx
	push	OFFSET FLAT:$SG67518
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 12					; 0000000cH
$L67517:

; 1230 : 		fprintf(fd, " (%lu = 0x%lx)\n",
; 1231 : 		    (u_long) sp->groupoptions, (u_long) sp->groupoptions);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	push	ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+28]
	push	eax
	push	OFFSET FLAT:$SG67521
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 16					; 00000010H
$L67502:

; 1233 : 	if (TIFFFieldSet(tif,FIELD_CLEANFAXDATA)) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+32]
	and	eax, 1
	test	eax, eax
	je	$L67523

; 1234 : 		fprintf(fd, "  Fax Data:");

	push	OFFSET FLAT:$SG67524
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 1235 : 		switch (sp->cleanfaxdata) {

	mov	edx, DWORD PTR _sp$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+16]
	mov	DWORD PTR -12+[ebp], eax
	cmp	DWORD PTR -12+[ebp], 0
	je	SHORT $L67529
	cmp	DWORD PTR -12+[ebp], 1
	je	SHORT $L67531
	cmp	DWORD PTR -12+[ebp], 2
	je	SHORT $L67533
	jmp	SHORT $L67526
$L67529:

; 1236 : 		case CLEANFAXDATA_CLEAN:
; 1237 : 			fprintf(fd, " clean");

	push	OFFSET FLAT:$SG67530
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 1238 : 			break;

	jmp	SHORT $L67526
$L67531:

; 1239 : 		case CLEANFAXDATA_REGENERATED:
; 1240 : 			fprintf(fd, " receiver regenerated");

	push	OFFSET FLAT:$SG67532
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8

; 1241 : 			break;

	jmp	SHORT $L67526
$L67533:

; 1242 : 		case CLEANFAXDATA_UNCLEAN:
; 1243 : 			fprintf(fd, " uncorrected errors");

	push	OFFSET FLAT:$SG67534
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8
$L67526:

; 1246 : 		fprintf(fd, " (%u = 0x%x)\n",
; 1247 : 		    sp->cleanfaxdata, sp->cleanfaxdata);

	mov	ecx, DWORD PTR _sp$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+16]
	push	edx
	mov	eax, DWORD PTR _sp$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:$SG67535
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 16					; 00000010H
$L67523:

; 1249 : 	if (TIFFFieldSet(tif,FIELD_BADFAXLINES))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	and	ecx, -2147483648			; 80000000H
	test	ecx, ecx
	je	SHORT $L67537

; 1250 : 		fprintf(fd, "  Bad Fax Lines: %lu\n", (u_long) sp->badfaxlines);

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+24]
	push	eax
	push	OFFSET FLAT:$SG67539
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 12					; 0000000cH
$L67537:

; 1251 : 	if (TIFFFieldSet(tif,FIELD_BADFAXRUN))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+32]
	and	eax, 2
	test	eax, eax
	je	SHORT $L67541

; 1252 : 		fprintf(fd, "  Consecutive Bad Fax Lines: %lu\n",
; 1253 : 		    (u_long) sp->badfaxrun);

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+20]
	push	edx
	push	OFFSET FLAT:$SG67543
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 12					; 0000000cH
$L67541:

; 1254 : 	if (TIFFFieldSet(tif,FIELD_RECVPARAMS))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+32]
	and	edx, 4
	test	edx, edx
	je	SHORT $L67545

; 1255 : 		fprintf(fd, "  Fax Receive Parameters: %08lx\n",
; 1256 : 		   (u_long) sp->recvparams);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+32]
	push	ecx
	push	OFFSET FLAT:$SG67547
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 12					; 0000000cH
$L67545:

; 1257 : 	if (TIFFFieldSet(tif,FIELD_SUBADDRESS))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+32]
	and	ecx, 8
	test	ecx, ecx
	je	SHORT $L67549

; 1258 : 		fprintf(fd, "  Fax SubAddress: %s\n", sp->subaddress);

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+36]
	push	eax
	push	OFFSET FLAT:$SG67550
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 12					; 0000000cH
$L67549:

; 1259 : 	if (TIFFFieldSet(tif,FIELD_RECVTIME))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+32]
	and	eax, 16					; 00000010H
	test	eax, eax
	je	SHORT $L67552

; 1260 : 		fprintf(fd, "  Fax Receive Time: %lu secs\n",
; 1261 : 		    (u_long) sp->recvtime);

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+40]
	push	edx
	push	OFFSET FLAT:$SG67554
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 12					; 0000000cH
$L67552:

; 1262 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Fax3PrintDir ENDP
_TEXT	ENDS
PUBLIC	_TIFFInitCCITTFax4
_TEXT	SEGMENT
_tif$ = 8
_TIFFInitCCITTFax4 PROC NEAR

; 1434 : {

	push	ebp
	mov	ebp, esp

; 1435 : 	if (InitCCITTFax3(tif)) {		/* reuse G3 support */

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_InitCCITTFax3
	add	esp, 4
	test	eax, eax
	je	$L67990

; 1436 : 		_TIFFMergeFieldInfo(tif, fax4FieldInfo, N(fax4FieldInfo));

	push	1
	push	OFFSET FLAT:_fax4FieldInfo
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	__TIFFMergeFieldInfo
	add	esp, 12					; 0000000cH

; 1437 : 
; 1438 : 		tif->tif_decoderow = Fax4Decode;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+416], OFFSET FLAT:_Fax4Decode

; 1439 : 		tif->tif_decodestrip = Fax4Decode;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+424], OFFSET FLAT:_Fax4Decode

; 1440 : 		tif->tif_decodetile = Fax4Decode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+432], OFFSET FLAT:_Fax4Decode

; 1441 : 		tif->tif_encoderow = Fax4Encode;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+420], OFFSET FLAT:_Fax4Encode

; 1442 : 		tif->tif_encodestrip = Fax4Encode;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+428], OFFSET FLAT:_Fax4Encode

; 1443 : 		tif->tif_encodetile = Fax4Encode;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+436], OFFSET FLAT:_Fax4Encode

; 1444 : 		tif->tif_postencode = Fax4PostEncode;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+412], OFFSET FLAT:_Fax4PostEncode

; 1445 : 		/*
; 1446 : 		 * Suppress RTC at the end of each strip.
; 1447 : 		 */
; 1448 : 		return TIFFSetField(tif, TIFFTAG_FAXMODE, FAXMODE_NORTC);

	push	1
	push	65536					; 00010000H
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFSetField
	add	esp, 12					; 0000000cH
	jmp	SHORT $L67991
$L67990:

; 1450 : 		return (0);

	xor	eax, eax
$L67991:

; 1451 : }

	pop	ebp
	ret	0
_TIFFInitCCITTFax4 ENDP
_tif$ = 8
_buf$ = 12
_occ$ = 16
_sp$ = -20
_a0$ = -52
_lastx$ = -4
_BitAcc$ = -56
_BitsAvail$ = -8
_RunLength$ = -28
_cp$ = -16
_ep$ = -48
_pa$ = -36
_thisrun$ = -44
_EOLcnt$ = -32
_bitmap$ = -12
_TabEnt$ = -24
_b1$ = -60
_pb$ = -40
_x$67927 = -64
_Fax4Decode PROC NEAR

; 1354 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 84					; 00000054H

; 1355 : 	DECLARE_STATE_2D(tif, sp, "Fax4Decode");

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR _lastx$[ebp], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+52]
	mov	DWORD PTR _bitmap$[ebp], edx
$L67618:

; 1356 : 
; 1357 : 	(void) s;
; 1358 : 	CACHE_STATE(tif, sp);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+56]
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+60]
	mov	DWORD PTR _BitsAvail$[ebp], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+64]
	mov	DWORD PTR _EOLcnt$[ebp], edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, DWORD PTR [edx+484]
	mov	DWORD PTR _ep$[ebp], eax
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L67618
$L67620:

; 1359 : 	while ((long)occ > 0) {

	cmp	DWORD PTR _occ$[ebp], 0
	jle	$L67625

; 1360 : 		a0 = 0;

	mov	DWORD PTR _a0$[ebp], 0

; 1361 : 		RunLength = 0;

	mov	DWORD PTR _RunLength$[ebp], 0

; 1362 : 		pa = thisrun = sp->curruns;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+80]
	mov	DWORD PTR _thisrun$[ebp], eax
	mov	ecx, DWORD PTR _thisrun$[ebp]
	mov	DWORD PTR _pa$[ebp], ecx

; 1363 : 		pb = sp->refruns;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+76]
	mov	DWORD PTR _pb$[ebp], eax

; 1364 : 		b1 = *pb++;

	mov	ecx, DWORD PTR _pb$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR _b1$[ebp], edx
	mov	eax, DWORD PTR _pb$[ebp]
	add	eax, 4
	mov	DWORD PTR _pb$[ebp], eax
$L67626:

; 1365 : #ifdef FAX3_DEBUG
; 1366 : 		printf("\nBitAcc=%08X, BitsAvail = %d\n", BitAcc, BitsAvail);
; 1367 : 		printf("-------------------- %d\n", tif->tif_row);
; 1368 : 		fflush(stdout);
; 1369 : #endif
; 1370 : 		EXPAND2D(EOFG4);

	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jge	$L67631
$L67632:
	cmp	DWORD PTR _BitsAvail$[ebp], 7
	jge	SHORT $L67642
	mov	edx, DWORD PTR _cp$[ebp]
	cmp	edx, DWORD PTR _ep$[ebp]
	jb	SHORT $L67639
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L67640
	jmp	$eof2d$67641
$L67640:
	mov	DWORD PTR _BitsAvail$[ebp], 7
	jmp	SHORT $L67642
$L67639:
	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _bitmap$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	eax, cl
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	or	ecx, eax
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	add	eax, 8
	mov	DWORD PTR _BitsAvail$[ebp], eax
$L67642:
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L67632
	mov	edx, DWORD PTR _BitAcc$[ebp]
	and	edx, 127				; 0000007fH
	lea	eax, DWORD PTR _TIFFFaxMainTable[edx*8]
	mov	DWORD PTR _TabEnt$[ebp], eax
$L67644:
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	sub	eax, edx
	mov	DWORD PTR _BitsAvail$[ebp], eax
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+1]
	mov	ecx, edx
	mov	eax, DWORD PTR _BitAcc$[ebp]
	shr	eax, cl
	mov	DWORD PTR _BitAcc$[ebp], eax
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L67644
	xor	edx, edx
	test	edx, edx
	jne	$L67632
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	DWORD PTR -68+[ebp], ecx
	mov	edx, DWORD PTR -68+[ebp]
	sub	edx, 1
	mov	DWORD PTR -68+[ebp], edx
	cmp	DWORD PTR -68+[ebp], 11			; 0000000bH
	ja	$badMain2d$67848
	mov	eax, DWORD PTR -68+[ebp]
	jmp	DWORD PTR $L68286[eax*4]
$L67651:
	mov	ecx, DWORD PTR _pa$[ebp]
	cmp	ecx, DWORD PTR _thisrun$[ebp]
	je	SHORT $L67658
$L67657:
	mov	edx, DWORD PTR _b1$[ebp]
	cmp	edx, DWORD PTR _a0$[ebp]
	jg	SHORT $L67658
	mov	eax, DWORD PTR _b1$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jge	SHORT $L67658
	mov	ecx, DWORD PTR _pb$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	eax, DWORD PTR _pb$[ebp]
	add	edx, DWORD PTR [eax+4]
	mov	ecx, DWORD PTR _b1$[ebp]
	add	ecx, edx
	mov	DWORD PTR _b1$[ebp], ecx
	mov	edx, DWORD PTR _pb$[ebp]
	add	edx, 8
	mov	DWORD PTR _pb$[ebp], edx
	jmp	SHORT $L67657
$L67658:
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L67651
	mov	ecx, DWORD PTR _pb$[ebp]
	mov	edx, DWORD PTR _b1$[ebp]
	add	edx, DWORD PTR [ecx]
	mov	DWORD PTR _b1$[ebp], edx
	mov	eax, DWORD PTR _pb$[ebp]
	add	eax, 4
	mov	DWORD PTR _pb$[ebp], eax
	mov	ecx, DWORD PTR _b1$[ebp]
	sub	ecx, DWORD PTR _a0$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, ecx
	mov	DWORD PTR _RunLength$[ebp], edx
	mov	eax, DWORD PTR _b1$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	ecx, DWORD PTR _pb$[ebp]
	mov	edx, DWORD PTR _b1$[ebp]
	add	edx, DWORD PTR [ecx]
	mov	DWORD PTR _b1$[ebp], edx
	mov	eax, DWORD PTR _pb$[ebp]
	add	eax, 4
	mov	DWORD PTR _pb$[ebp], eax
	jmp	$L67648
$L67659:
	mov	ecx, DWORD PTR _pa$[ebp]
	sub	ecx, DWORD PTR _thisrun$[ebp]
	sar	ecx, 2
	and	ecx, 1
	test	ecx, ecx
	je	$L67660
$L67662:
	cmp	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jge	$L67677
	mov	edx, DWORD PTR _cp$[ebp]
	cmp	edx, DWORD PTR _ep$[ebp]
	jb	SHORT $L67671
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L67672
	jmp	$eof2d$67641
$L67672:
	mov	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jmp	SHORT $L67677
$L67671:
	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _bitmap$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	eax, cl
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	or	ecx, eax
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	add	eax, 8
	mov	DWORD PTR _BitsAvail$[ebp], eax
	cmp	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jge	SHORT $L67677
	mov	ecx, DWORD PTR _cp$[ebp]
	cmp	ecx, DWORD PTR _ep$[ebp]
	jb	SHORT $L67676
	mov	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jmp	SHORT $L67677
$L67676:
	mov	edx, DWORD PTR _cp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _bitmap$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L67677:
	xor	eax, eax
	test	eax, eax
	jne	$L67662
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	and	ecx, 8191				; 00001fffH
	lea	edx, DWORD PTR _TIFFFaxBlackTable[ecx*8]
	mov	DWORD PTR _TabEnt$[ebp], edx
$L67679:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _BitsAvail$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, cl
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L67679
	xor	ecx, ecx
	test	ecx, ecx
	jne	$L67662
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	al, BYTE PTR [edx]
	mov	BYTE PTR -72+[ebp], al
	cmp	BYTE PTR -72+[ebp], 8
	je	SHORT $L67686
	cmp	BYTE PTR -72+[ebp], 9
	jbe	SHORT $L67692
	cmp	BYTE PTR -72+[ebp], 11			; 0000000bH
	jbe	SHORT $L67691
	jmp	SHORT $L67692
$L67686:
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	eax, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L67686
	jmp	SHORT $doneWhite2da$67690
$L67691:
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _a0$[ebp], eax
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _RunLength$[ebp], edx
	jmp	SHORT $L67683
$L67692:
	jmp	$badBlack2d$67693
$L67683:
	jmp	$L67662
$doneWhite2da$67690:
	cmp	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jge	$L67710
	mov	eax, DWORD PTR _cp$[ebp]
	cmp	eax, DWORD PTR _ep$[ebp]
	jb	SHORT $L67704
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L67705
	jmp	$eof2d$67641
$L67705:
	mov	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jmp	SHORT $L67710
$L67704:
	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _bitmap$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
	cmp	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jge	SHORT $L67710
	mov	eax, DWORD PTR _cp$[ebp]
	cmp	eax, DWORD PTR _ep$[ebp]
	jb	SHORT $L67709
	mov	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jmp	SHORT $L67710
$L67709:
	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _bitmap$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L67710:
	xor	eax, eax
	test	eax, eax
	jne	$doneWhite2da$67690
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	and	ecx, 4095				; 00000fffH
	lea	edx, DWORD PTR _TIFFFaxWhiteTable[ecx*8]
	mov	DWORD PTR _TabEnt$[ebp], edx
$L67712:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _BitsAvail$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, cl
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L67712
	xor	ecx, ecx
	test	ecx, ecx
	jne	$doneWhite2da$67690
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	al, BYTE PTR [edx]
	mov	BYTE PTR -76+[ebp], al
	cmp	BYTE PTR -76+[ebp], 7
	je	SHORT $L67719
	cmp	BYTE PTR -76+[ebp], 9
	je	SHORT $L67724
	cmp	BYTE PTR -76+[ebp], 11			; 0000000bH
	je	SHORT $L67724
	jmp	SHORT $L67725
$L67719:
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	eax, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L67719
	jmp	SHORT $doneBlack2da$67723
$L67724:
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _a0$[ebp], eax
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _RunLength$[ebp], edx
	jmp	SHORT $L67716
$L67725:
	jmp	$badWhite2d$67726
$L67716:
	jmp	$doneWhite2da$67690
$doneBlack2da$67723:
	jmp	$doneBlack2db$67789
$L67660:
	cmp	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jge	$L67744
	mov	eax, DWORD PTR _cp$[ebp]
	cmp	eax, DWORD PTR _ep$[ebp]
	jb	SHORT $L67738
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L67739
	jmp	$eof2d$67641
$L67739:
	mov	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jmp	SHORT $L67744
$L67738:
	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _bitmap$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
	cmp	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jge	SHORT $L67744
	mov	eax, DWORD PTR _cp$[ebp]
	cmp	eax, DWORD PTR _ep$[ebp]
	jb	SHORT $L67743
	mov	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jmp	SHORT $L67744
$L67743:
	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _bitmap$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L67744:
	xor	eax, eax
	test	eax, eax
	jne	$L67660
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	and	ecx, 4095				; 00000fffH
	lea	edx, DWORD PTR _TIFFFaxWhiteTable[ecx*8]
	mov	DWORD PTR _TabEnt$[ebp], edx
$L67746:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _BitsAvail$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, cl
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L67746
	xor	ecx, ecx
	test	ecx, ecx
	jne	$L67660
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	al, BYTE PTR [edx]
	mov	BYTE PTR -80+[ebp], al
	cmp	BYTE PTR -80+[ebp], 7
	je	SHORT $L67753
	cmp	BYTE PTR -80+[ebp], 9
	je	SHORT $L67758
	cmp	BYTE PTR -80+[ebp], 11			; 0000000bH
	je	SHORT $L67758
	jmp	SHORT $L67759
$L67753:
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	eax, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L67753
	jmp	SHORT $doneWhite2db$67757
$L67758:
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _a0$[ebp], eax
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _RunLength$[ebp], edx
	jmp	SHORT $L67750
$L67759:
	jmp	$badWhite2d$67726
$L67750:
	jmp	$L67660
$doneWhite2db$67757:
	cmp	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jge	$L67776
	mov	eax, DWORD PTR _cp$[ebp]
	cmp	eax, DWORD PTR _ep$[ebp]
	jb	SHORT $L67770
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L67771
	jmp	$eof2d$67641
$L67771:
	mov	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jmp	SHORT $L67776
$L67770:
	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _bitmap$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
	cmp	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jge	SHORT $L67776
	mov	eax, DWORD PTR _cp$[ebp]
	cmp	eax, DWORD PTR _ep$[ebp]
	jb	SHORT $L67775
	mov	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jmp	SHORT $L67776
$L67775:
	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _bitmap$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L67776:
	xor	eax, eax
	test	eax, eax
	jne	$doneWhite2db$67757
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	and	ecx, 8191				; 00001fffH
	lea	edx, DWORD PTR _TIFFFaxBlackTable[ecx*8]
	mov	DWORD PTR _TabEnt$[ebp], edx
$L67778:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _BitsAvail$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, cl
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L67778
	xor	ecx, ecx
	test	ecx, ecx
	jne	$doneWhite2db$67757
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	al, BYTE PTR [edx]
	mov	BYTE PTR -84+[ebp], al
	cmp	BYTE PTR -84+[ebp], 8
	je	SHORT $L67785
	cmp	BYTE PTR -84+[ebp], 9
	jbe	SHORT $L67791
	cmp	BYTE PTR -84+[ebp], 11			; 0000000bH
	jbe	SHORT $L67790
	jmp	SHORT $L67791
$L67785:
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	eax, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L67785
	jmp	SHORT $doneBlack2db$67789
$L67790:
	mov	edx, DWORD PTR _TabEnt$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR [edx+4]
	mov	DWORD PTR _a0$[ebp], eax
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _RunLength$[ebp], edx
	jmp	SHORT $L67782
$L67791:
	jmp	$badBlack2d$67693
$L67782:
	jmp	$doneWhite2db$67757
$doneBlack2db$67789:
	mov	eax, DWORD PTR _pa$[ebp]
	cmp	eax, DWORD PTR _thisrun$[ebp]
	je	SHORT $L67798
$L67797:
	mov	ecx, DWORD PTR _b1$[ebp]
	cmp	ecx, DWORD PTR _a0$[ebp]
	jg	SHORT $L67798
	mov	edx, DWORD PTR _b1$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	jge	SHORT $L67798
	mov	eax, DWORD PTR _pb$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _pb$[ebp]
	add	ecx, DWORD PTR [edx+4]
	mov	eax, DWORD PTR _b1$[ebp]
	add	eax, ecx
	mov	DWORD PTR _b1$[ebp], eax
	mov	ecx, DWORD PTR _pb$[ebp]
	add	ecx, 8
	mov	DWORD PTR _pb$[ebp], ecx
	jmp	SHORT $L67797
$L67798:
	xor	edx, edx
	test	edx, edx
	jne	SHORT $doneBlack2db$67789
	jmp	$L67648
$L67799:
	mov	eax, DWORD PTR _pa$[ebp]
	cmp	eax, DWORD PTR _thisrun$[ebp]
	je	SHORT $L67806
$L67805:
	mov	ecx, DWORD PTR _b1$[ebp]
	cmp	ecx, DWORD PTR _a0$[ebp]
	jg	SHORT $L67806
	mov	edx, DWORD PTR _b1$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	jge	SHORT $L67806
	mov	eax, DWORD PTR _pb$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	edx, DWORD PTR _pb$[ebp]
	add	ecx, DWORD PTR [edx+4]
	mov	eax, DWORD PTR _b1$[ebp]
	add	eax, ecx
	mov	DWORD PTR _b1$[ebp], eax
	mov	ecx, DWORD PTR _pb$[ebp]
	add	ecx, 8
	mov	DWORD PTR _pb$[ebp], ecx
	jmp	SHORT $L67805
$L67806:
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L67799
$L67802:
	mov	eax, DWORD PTR _b1$[ebp]
	sub	eax, DWORD PTR _a0$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, eax
	mov	edx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _b1$[ebp]
	sub	ecx, DWORD PTR _a0$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, ecx
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L67802
	mov	ecx, DWORD PTR _pb$[ebp]
	mov	edx, DWORD PTR _b1$[ebp]
	add	edx, DWORD PTR [ecx]
	mov	DWORD PTR _b1$[ebp], edx
	mov	eax, DWORD PTR _pb$[ebp]
	add	eax, 4
	mov	DWORD PTR _pb$[ebp], eax
	jmp	$L67648
$L67810:
	mov	ecx, DWORD PTR _pa$[ebp]
	cmp	ecx, DWORD PTR _thisrun$[ebp]
	je	SHORT $L67817
$L67816:
	mov	edx, DWORD PTR _b1$[ebp]
	cmp	edx, DWORD PTR _a0$[ebp]
	jg	SHORT $L67817
	mov	eax, DWORD PTR _b1$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jge	SHORT $L67817
	mov	ecx, DWORD PTR _pb$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	eax, DWORD PTR _pb$[ebp]
	add	edx, DWORD PTR [eax+4]
	mov	ecx, DWORD PTR _b1$[ebp]
	add	ecx, edx
	mov	DWORD PTR _b1$[ebp], ecx
	mov	edx, DWORD PTR _pb$[ebp]
	add	edx, 8
	mov	DWORD PTR _pb$[ebp], edx
	jmp	SHORT $L67816
$L67817:
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L67810
$L67813:
	mov	ecx, DWORD PTR _b1$[ebp]
	sub	ecx, DWORD PTR _a0$[ebp]
	mov	edx, DWORD PTR _TabEnt$[ebp]
	add	ecx, DWORD PTR [edx+4]
	mov	eax, DWORD PTR _RunLength$[ebp]
	add	eax, ecx
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _b1$[ebp]
	sub	eax, DWORD PTR _a0$[ebp]
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	add	eax, DWORD PTR [ecx+4]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, eax
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L67813
	mov	ecx, DWORD PTR _pb$[ebp]
	mov	edx, DWORD PTR _b1$[ebp]
	add	edx, DWORD PTR [ecx]
	mov	DWORD PTR _b1$[ebp], edx
	mov	eax, DWORD PTR _pb$[ebp]
	add	eax, 4
	mov	DWORD PTR _pb$[ebp], eax
	jmp	$L67648
$L67821:
	mov	ecx, DWORD PTR _pa$[ebp]
	cmp	ecx, DWORD PTR _thisrun$[ebp]
	je	SHORT $L67828
$L67827:
	mov	edx, DWORD PTR _b1$[ebp]
	cmp	edx, DWORD PTR _a0$[ebp]
	jg	SHORT $L67828
	mov	eax, DWORD PTR _b1$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jge	SHORT $L67828
	mov	ecx, DWORD PTR _pb$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	eax, DWORD PTR _pb$[ebp]
	add	edx, DWORD PTR [eax+4]
	mov	ecx, DWORD PTR _b1$[ebp]
	add	ecx, edx
	mov	DWORD PTR _b1$[ebp], ecx
	mov	edx, DWORD PTR _pb$[ebp]
	add	edx, 8
	mov	DWORD PTR _pb$[ebp], edx
	jmp	SHORT $L67827
$L67828:
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L67821
$L67824:
	mov	ecx, DWORD PTR _b1$[ebp]
	sub	ecx, DWORD PTR _a0$[ebp]
	mov	edx, DWORD PTR _TabEnt$[ebp]
	sub	ecx, DWORD PTR [edx+4]
	mov	eax, DWORD PTR _RunLength$[ebp]
	add	eax, ecx
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _b1$[ebp]
	sub	eax, DWORD PTR _a0$[ebp]
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	sub	eax, DWORD PTR [ecx+4]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, eax
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L67824
	mov	ecx, DWORD PTR _pb$[ebp]
	sub	ecx, 4
	mov	DWORD PTR _pb$[ebp], ecx
	mov	edx, DWORD PTR _pb$[ebp]
	mov	eax, DWORD PTR _b1$[ebp]
	sub	eax, DWORD PTR [edx]
	mov	DWORD PTR _b1$[ebp], eax
	jmp	$L67648
$L67832:
	mov	ecx, DWORD PTR _lastx$[ebp]
	sub	ecx, DWORD PTR _a0$[ebp]
	mov	edx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _a0$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	push	OFFSET FLAT:_?module@?1??Fax4Decode@@9@9
	call	_Fax3Extension
	add	esp, 12					; 0000000cH
	jmp	$eol2d$67833
$L67834:
	mov	eax, DWORD PTR _lastx$[ebp]
	sub	eax, DWORD PTR _a0$[ebp]
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
$L67835:
	cmp	DWORD PTR _BitsAvail$[ebp], 4
	jge	SHORT $L67841
	mov	eax, DWORD PTR _cp$[ebp]
	cmp	eax, DWORD PTR _ep$[ebp]
	jb	SHORT $L67839
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L67840
	jmp	$eof2d$67641
$L67840:
	mov	DWORD PTR _BitsAvail$[ebp], 4
	jmp	SHORT $L67841
$L67839:
	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _bitmap$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L67841:
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L67835
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	and	ecx, 15					; 0000000fH
	test	ecx, ecx
	je	SHORT $L67843
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	push	OFFSET FLAT:_?module@?1??Fax4Decode@@9@9
	call	_Fax3Unexpected
	add	esp, 12					; 0000000cH
$L67843:
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	sub	ecx, 4
	mov	DWORD PTR _BitsAvail$[ebp], ecx
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, 4
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L67843
	mov	DWORD PTR _EOLcnt$[ebp], 1
	jmp	$eol2d$67833
$badMain2d$67848:
	mov	ecx, DWORD PTR _a0$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	push	OFFSET FLAT:_?module@?1??Fax4Decode@@9@9
	call	_Fax3Unexpected
	add	esp, 12					; 0000000cH
	jmp	$eol2d$67833
$badBlack2d$67693:
	mov	eax, DWORD PTR _a0$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	push	OFFSET FLAT:_?module@?1??Fax4Decode@@9@9
	call	_Fax3Unexpected
	add	esp, 12					; 0000000cH
	jmp	$eol2d$67833
$badWhite2d$67726:
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	push	OFFSET FLAT:_?module@?1??Fax4Decode@@9@9
	call	_Fax3Unexpected
	add	esp, 12					; 0000000cH
	jmp	$eol2d$67833
$eof2d$67641:
	mov	ecx, DWORD PTR _a0$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	push	OFFSET FLAT:_?module@?1??Fax4Decode@@9@9
	call	_Fax3PrematureEOF
	add	esp, 12					; 0000000cH
$L67849:
	cmp	DWORD PTR _RunLength$[ebp], 0
	je	SHORT $L67855
$L67853:
	mov	eax, DWORD PTR _pa$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L67853
$L67855:
	mov	edx, DWORD PTR _a0$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	je	$L67876
	mov	eax, DWORD PTR _lastx$[ebp]
	push	eax
	mov	ecx, DWORD PTR _a0$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	push	OFFSET FLAT:_?module@?1??Fax4Decode@@9@9
	call	_Fax3BadLength
	add	esp, 16					; 00000010H
$L67858:
	mov	eax, DWORD PTR _a0$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jle	SHORT $L67859
	mov	ecx, DWORD PTR _pa$[ebp]
	cmp	ecx, DWORD PTR _thisrun$[ebp]
	jbe	SHORT $L67859
	mov	edx, DWORD PTR _pa$[ebp]
	sub	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _pa$[ebp]
	mov	ecx, DWORD PTR _a0$[ebp]
	sub	ecx, DWORD PTR [eax]
	mov	DWORD PTR _a0$[ebp], ecx
	jmp	SHORT $L67858
$L67859:
	mov	edx, DWORD PTR _a0$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	jge	SHORT $L67860
	cmp	DWORD PTR _a0$[ebp], 0
	jge	SHORT $L67861
	mov	DWORD PTR _a0$[ebp], 0
$L67861:
	mov	eax, DWORD PTR _pa$[ebp]
	sub	eax, DWORD PTR _thisrun$[ebp]
	sar	eax, 2
	and	eax, 1
	test	eax, eax
	je	SHORT $L67865
$L67863:
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [ecx], edx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L67863
$L67865:
	mov	eax, DWORD PTR _lastx$[ebp]
	sub	eax, DWORD PTR _a0$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, eax
	mov	edx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _lastx$[ebp]
	sub	ecx, DWORD PTR _a0$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, ecx
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L67865
	jmp	SHORT $L67876
$L67860:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jle	SHORT $L67876
$L67871:
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, DWORD PTR _lastx$[ebp]
	mov	eax, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, DWORD PTR _lastx$[ebp]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L67871
$L67873:
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [ecx], edx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L67873
$L67876:
	xor	eax, eax
	test	eax, eax
	jne	$L67849
	jmp	$EOFG4$67877
$L67648:
	jmp	$L67626
$L67631:
	cmp	DWORD PTR _RunLength$[ebp], 0
	je	$eol2d$67833
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jge	SHORT $L67891
$L67880:
	cmp	DWORD PTR _BitsAvail$[ebp], 1
	jge	SHORT $L67886
	mov	edx, DWORD PTR _cp$[ebp]
	cmp	edx, DWORD PTR _ep$[ebp]
	jb	SHORT $L67884
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L67885
	jmp	$eof2d$67641
$L67885:
	mov	DWORD PTR _BitsAvail$[ebp], 1
	jmp	SHORT $L67886
$L67884:
	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _bitmap$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	eax, cl
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	or	ecx, eax
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	add	eax, 8
	mov	DWORD PTR _BitsAvail$[ebp], eax
$L67886:
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L67880
	mov	edx, DWORD PTR _BitAcc$[ebp]
	and	edx, 1
	test	edx, edx
	jne	SHORT $L67888
	jmp	$badMain2d$67848
$L67888:
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	sub	eax, 1
	mov	DWORD PTR _BitsAvail$[ebp], eax
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	shr	ecx, 1
	mov	DWORD PTR _BitAcc$[ebp], ecx
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L67888
$L67891:
	mov	eax, DWORD PTR _pa$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L67891
$eol2d$67833:
	cmp	DWORD PTR _RunLength$[ebp], 0
	je	SHORT $L67901
$L67899:
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L67899
$L67901:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	je	$L67922
	mov	edx, DWORD PTR _lastx$[ebp]
	push	edx
	mov	eax, DWORD PTR _a0$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	push	OFFSET FLAT:_?module@?1??Fax4Decode@@9@9
	call	_Fax3BadLength
	add	esp, 16					; 00000010H
$L67904:
	mov	edx, DWORD PTR _a0$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	jle	SHORT $L67905
	mov	eax, DWORD PTR _pa$[ebp]
	cmp	eax, DWORD PTR _thisrun$[ebp]
	jbe	SHORT $L67905
	mov	ecx, DWORD PTR _pa$[ebp]
	sub	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	sub	eax, DWORD PTR [edx]
	mov	DWORD PTR _a0$[ebp], eax
	jmp	SHORT $L67904
$L67905:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jge	SHORT $L67906
	cmp	DWORD PTR _a0$[ebp], 0
	jge	SHORT $L67907
	mov	DWORD PTR _a0$[ebp], 0
$L67907:
	mov	edx, DWORD PTR _pa$[ebp]
	sub	edx, DWORD PTR _thisrun$[ebp]
	sar	edx, 2
	and	edx, 1
	test	edx, edx
	je	SHORT $L67911
$L67909:
	mov	eax, DWORD PTR _pa$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L67909
$L67911:
	mov	edx, DWORD PTR _lastx$[ebp]
	sub	edx, DWORD PTR _a0$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	add	eax, edx
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _lastx$[ebp]
	sub	eax, DWORD PTR _a0$[ebp]
	mov	ecx, DWORD PTR _a0$[ebp]
	add	ecx, eax
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L67911
	jmp	SHORT $L67922
$L67906:
	mov	eax, DWORD PTR _a0$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jle	SHORT $L67922
$L67917:
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR _lastx$[ebp]
	mov	edx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _a0$[ebp]
	add	ecx, DWORD PTR _lastx$[ebp]
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L67917
$L67919:
	mov	eax, DWORD PTR _pa$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L67919
$L67922:
	xor	edx, edx
	test	edx, edx
	jne	$eol2d$67833
	xor	eax, eax
	test	eax, eax
	jne	$L67626

; 1371 :                 if (EOLcnt)

	cmp	DWORD PTR _EOLcnt$[ebp], 0
	je	SHORT $L67923

; 1372 :                     goto EOFG4;

	jmp	$EOFG4$67877
$L67923:

; 1373 : 		(*sp->fill)(buf, thisrun, pa, lastx);

	mov	ecx, DWORD PTR _lastx$[ebp]
	push	ecx
	mov	edx, DWORD PTR _pa$[ebp]
	push	edx
	mov	eax, DWORD PTR _thisrun$[ebp]
	push	eax
	mov	ecx, DWORD PTR _buf$[ebp]
	push	ecx
	mov	edx, DWORD PTR _sp$[ebp]
	call	DWORD PTR [edx+68]
	add	esp, 16					; 00000010H
$L67924:

; 1374 : 		SETVAL(0);		/* imaginary change for reference */

	mov	eax, DWORD PTR _pa$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L67924

; 1375 : 		SWAP(uint32*, sp->curruns, sp->refruns);

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+80]
	mov	DWORD PTR _x$67927[ebp], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+76]
	mov	DWORD PTR [ecx+80], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _x$67927[ebp]
	mov	DWORD PTR [ecx+76], edx

; 1376 : 		buf += sp->b.rowbytes;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _buf$[ebp]
	add	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR _buf$[ebp], ecx

; 1377 : 		occ -= sp->b.rowbytes;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _occ$[ebp]
	sub	eax, DWORD PTR [edx+8]
	mov	DWORD PTR _occ$[ebp], eax

; 1378 : 		if (occ != 0)

	cmp	DWORD PTR _occ$[ebp], 0
	je	SHORT $L67928

; 1379 : 			tif->tif_row++;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	add	edx, 1
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+356], edx
$L67928:

; 1380 : 		continue;

	jmp	$L67620
$EOFG4$67877:

; 1381 : 	EOFG4:
; 1382 :                 NeedBits16( 13, BADG4 );

	cmp	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jge	$L67940
	mov	ecx, DWORD PTR _cp$[ebp]
	cmp	ecx, DWORD PTR _ep$[ebp]
	jb	SHORT $L67933
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L67934
	jmp	$BADG4$67935
$L67934:
	mov	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jmp	SHORT $L67940
$L67933:
	mov	edx, DWORD PTR _cp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _bitmap$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
	cmp	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jge	SHORT $L67940
	mov	eax, DWORD PTR _cp$[ebp]
	cmp	eax, DWORD PTR _ep$[ebp]
	jb	SHORT $L67939
	mov	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jmp	SHORT $L67940
$L67939:
	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _bitmap$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L67940:
	xor	eax, eax
	test	eax, eax
	jne	$EOFG4$67877
$BADG4$67935:

; 1383 :         BADG4:
; 1384 : #ifdef FAX3_DEBUG
; 1385 :                 if( GetBits(13) != 0x1001 )
; 1386 :                     fputs( "Bad RTC\n", stderr );
; 1387 : #endif                
; 1388 :                 ClrBits( 13 );

	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	sub	ecx, 13					; 0000000dH
	mov	DWORD PTR _BitsAvail$[ebp], ecx
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, 13					; 0000000dH
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $BADG4$67935

; 1389 : 		(*sp->fill)(buf, thisrun, pa, lastx);

	mov	ecx, DWORD PTR _lastx$[ebp]
	push	ecx
	mov	edx, DWORD PTR _pa$[ebp]
	push	edx
	mov	eax, DWORD PTR _thisrun$[ebp]
	push	eax
	mov	ecx, DWORD PTR _buf$[ebp]
	push	ecx
	mov	edx, DWORD PTR _sp$[ebp]
	call	DWORD PTR [edx+68]
	add	esp, 16					; 00000010H
$L67945:

; 1390 : 		UNCACHE_STATE(tif, sp);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	mov	DWORD PTR [eax+60], ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _BitAcc$[ebp]
	mov	DWORD PTR [edx+56], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _EOLcnt$[ebp]
	mov	DWORD PTR [ecx+64], edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	sub	ecx, DWORD PTR [eax+480]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+484]
	sub	eax, ecx
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+484], eax
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx+480], eax
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L67945

; 1391 : 		return (-1);

	or	eax, -1
	jmp	SHORT $L67597
$L67625:

; 1393 : 	UNCACHE_STATE(tif, sp);

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	mov	DWORD PTR [edx+60], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _BitAcc$[ebp]
	mov	DWORD PTR [ecx+56], edx
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _EOLcnt$[ebp]
	mov	DWORD PTR [eax+64], ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	sub	eax, DWORD PTR [edx+480]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+484]
	sub	edx, eax
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+484], edx
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx+480], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L67625

; 1394 : 	return (1);

	mov	eax, 1
$L67597:

; 1395 : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68286:
	DD	$L67651
	DD	$L67659
	DD	$L67799
	DD	$L67810
	DD	$L67821
	DD	$L67832
	DD	$badMain2d$67848
	DD	$badMain2d$67848
	DD	$badMain2d$67848
	DD	$badMain2d$67848
	DD	$badMain2d$67848
	DD	$L67834
_Fax4Decode ENDP
_tif$ = 8
_bp$ = 12
_cc$ = 16
_sp$ = -4
_Fax4Encode PROC NEAR

; 1403 : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 1404 : 	Fax3EncodeState *sp = EncoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx
$L67971:

; 1405 : 
; 1406 : 	(void) s;
; 1407 : 	while ((long)cc > 0) {

	cmp	DWORD PTR _cc$[ebp], 0
	jle	SHORT $L67972

; 1408 : 		if (!Fax3Encode2DRow(tif, bp, sp->refline, sp->b.rowpixels))

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+12]
	push	eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+64]
	push	edx
	mov	eax, DWORD PTR _bp$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_Fax3Encode2DRow
	add	esp, 16					; 00000010H
	test	eax, eax
	jne	SHORT $L67973

; 1409 : 			return (0);

	xor	eax, eax
	jmp	SHORT $L67964
$L67973:

; 1410 : 		_TIFFmemcpy(sp->refline, bp, sp->b.rowbytes);

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+8]
	push	eax
	mov	ecx, DWORD PTR _bp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+64]
	push	eax
	call	__TIFFmemcpy
	add	esp, 12					; 0000000cH

; 1411 : 		bp += sp->b.rowbytes;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _bp$[ebp]
	add	edx, DWORD PTR [ecx+8]
	mov	DWORD PTR _bp$[ebp], edx

; 1412 : 		cc -= sp->b.rowbytes;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _cc$[ebp]
	sub	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR _cc$[ebp], ecx

; 1413 : 		if (cc != 0)

	cmp	DWORD PTR _cc$[ebp], 0
	je	SHORT $L67974

; 1414 : 			tif->tif_row++;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+356]
	add	eax, 1
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+356], eax
$L67974:

; 1415 : 	}

	jmp	SHORT $L67971
$L67972:

; 1416 : 	return (1);

	mov	eax, 1
$L67964:

; 1417 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Fax4Encode ENDP
_tif$ = 8
_sp$ = -4
_Fax4PostEncode PROC NEAR

; 1421 : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 1422 : 	Fax3EncodeState *sp = EncoderState(tif);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx

; 1423 : 
; 1424 : 	/* terminate strip w/ EOFB */
; 1425 : 	Fax3PutBits(tif, EOL, 12);

	push	12					; 0000000cH
	push	1
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_Fax3PutBits
	add	esp, 12					; 0000000cH

; 1426 : 	Fax3PutBits(tif, EOL, 12);

	push	12					; 0000000cH
	push	1
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_Fax3PutBits
	add	esp, 12					; 0000000cH

; 1427 : 	if (sp->bit != 8)

	mov	ecx, DWORD PTR _sp$[ebp]
	cmp	DWORD PTR [ecx+56], 8
	je	SHORT $L67982

; 1428 : 		Fax3FlushBits(tif, sp);

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [edx+484]
	cmp	ecx, DWORD PTR [eax+476]
	jl	SHORT $L67983
	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFFlushData1
	add	esp, 4
$L67983:
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+480]
	mov	edx, DWORD PTR _sp$[ebp]
	mov	al, BYTE PTR [edx+52]
	mov	BYTE PTR [ecx], al
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+480]
	add	edx, 1
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+480], edx
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+484]
	add	edx, 1
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+484], edx
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [ecx+52], 0
	mov	edx, DWORD PTR _sp$[ebp]
	mov	DWORD PTR [edx+56], 8
$L67982:

; 1429 : 	return (1);

	mov	eax, 1

; 1430 : }

	mov	esp, ebp
	pop	ebp
	ret	0
_Fax4PostEncode ENDP
_TEXT	ENDS
PUBLIC	_TIFFInitCCITTRLE
_TEXT	SEGMENT
_tif$ = 8
_TIFFInitCCITTRLE PROC NEAR

; 1509 : {

	push	ebp
	mov	ebp, esp

; 1510 : 	if (InitCCITTFax3(tif)) {		/* reuse G3 support */

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_InitCCITTFax3
	add	esp, 4
	test	eax, eax
	je	SHORT $L68193

; 1511 : 		tif->tif_decoderow = Fax3DecodeRLE;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+416], OFFSET FLAT:_Fax3DecodeRLE

; 1512 : 		tif->tif_decodestrip = Fax3DecodeRLE;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+424], OFFSET FLAT:_Fax3DecodeRLE

; 1513 : 		tif->tif_decodetile = Fax3DecodeRLE;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+432], OFFSET FLAT:_Fax3DecodeRLE

; 1514 : 		/*
; 1515 : 		 * Suppress RTC+EOLs when encoding and byte-align data.
; 1516 : 		 */
; 1517 : 		return TIFFSetField(tif, TIFFTAG_FAXMODE,
; 1518 : 		    FAXMODE_NORTC|FAXMODE_NOEOL|FAXMODE_BYTEALIGN);

	push	7
	push	65536					; 00010000H
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFSetField
	add	esp, 12					; 0000000cH
	jmp	SHORT $L68194
$L68193:

; 1520 : 		return (0);

	xor	eax, eax
$L68194:

; 1521 : }

	pop	ebp
	ret	0
_TIFFInitCCITTRLE ENDP
_tif$ = 8
_buf$ = 12
_occ$ = 16
_sp$ = -20
_a0$ = -48
_lastx$ = -4
_BitAcc$ = -52
_BitsAvail$ = -8
_RunLength$ = -28
_cp$ = -16
_ep$ = -44
_pa$ = -36
_thisrun$ = -40
_EOLcnt$ = -32
_bitmap$ = -12
_TabEnt$ = -24
_mode$ = -56
_n$68164 = -60
_n$68170 = -64
_Fax3DecodeRLE PROC NEAR

; 1463 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 72					; 00000048H

; 1464 : 	DECLARE_STATE(tif, sp, "Fax3DecodeRLE");

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+460]
	mov	DWORD PTR _sp$[ebp], ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+12]
	mov	DWORD PTR _lastx$[ebp], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+52]
	mov	DWORD PTR _bitmap$[ebp], edx

; 1465 : 	int mode = sp->b.mode;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR _mode$[ebp], ecx
$L68021:

; 1466 : 
; 1467 : 	(void) s;
; 1468 : 	CACHE_STATE(tif, sp);

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR [edx+56]
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+60]
	mov	DWORD PTR _BitsAvail$[ebp], edx
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR [eax+64]
	mov	DWORD PTR _EOLcnt$[ebp], ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+480]
	mov	DWORD PTR _cp$[ebp], eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, DWORD PTR [ecx+484]
	mov	DWORD PTR _ep$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L68021

; 1469 : 	thisrun = sp->curruns;

	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR [ecx+80]
	mov	DWORD PTR _thisrun$[ebp], edx
$L68027:

; 1470 : 	while ((long)occ > 0) {

	cmp	DWORD PTR _occ$[ebp], 0
	jle	$L68028

; 1471 : 		a0 = 0;

	mov	DWORD PTR _a0$[ebp], 0

; 1472 : 		RunLength = 0;

	mov	DWORD PTR _RunLength$[ebp], 0

; 1473 : 		pa = thisrun;

	mov	eax, DWORD PTR _thisrun$[ebp]
	mov	DWORD PTR _pa$[ebp], eax
$L68029:

; 1474 : #ifdef FAX3_DEBUG
; 1475 : 		printf("\nBitAcc=%08X, BitsAvail = %d\n", BitAcc, BitsAvail);
; 1476 : 		printf("-------------------- %d\n", tif->tif_row);
; 1477 : 		fflush(stdout);
; 1478 : #endif
; 1479 : 		EXPAND1D(EOFRLE);

	cmp	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jge	$L68052
	mov	ecx, DWORD PTR _cp$[ebp]
	cmp	ecx, DWORD PTR _ep$[ebp]
	jb	SHORT $L68045
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L68046
	jmp	$eof1d$68047
$L68046:
	mov	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jmp	SHORT $L68052
$L68045:
	mov	edx, DWORD PTR _cp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _bitmap$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
	cmp	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jge	SHORT $L68052
	mov	eax, DWORD PTR _cp$[ebp]
	cmp	eax, DWORD PTR _ep$[ebp]
	jb	SHORT $L68051
	mov	DWORD PTR _BitsAvail$[ebp], 12		; 0000000cH
	jmp	SHORT $L68052
$L68051:
	mov	ecx, DWORD PTR _cp$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx]
	mov	eax, DWORD PTR _bitmap$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+edx]
	mov	edx, ecx
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L68052:
	xor	eax, eax
	test	eax, eax
	jne	$L68029
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	and	ecx, 4095				; 00000fffH
	lea	edx, DWORD PTR _TIFFFaxWhiteTable[ecx*8]
	mov	DWORD PTR _TabEnt$[ebp], edx
$L68054:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _BitsAvail$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, cl
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L68054
	xor	ecx, ecx
	test	ecx, ecx
	jne	$L68029
	mov	edx, DWORD PTR _TabEnt$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	DWORD PTR -68+[ebp], eax
	mov	ecx, DWORD PTR -68+[ebp]
	sub	ecx, 7
	mov	DWORD PTR -68+[ebp], ecx
	cmp	DWORD PTR -68+[ebp], 5
	ja	SHORT $L68069
	mov	edx, DWORD PTR -68+[ebp]
	jmp	DWORD PTR $L68291[edx*4]
$L68061:
	mov	DWORD PTR _EOLcnt$[ebp], 1
	jmp	$done1d$68062
$L68063:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR [eax+4]
	mov	edx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L68063
	jmp	SHORT $doneWhite1d$68067
$L68068:
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _a0$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR _RunLength$[ebp], ecx
	jmp	SHORT $L68058
$L68069:
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	push	OFFSET FLAT:_?module@?1??Fax3DecodeRLE@@9@9
	call	_Fax3Unexpected
	add	esp, 12					; 0000000cH
	jmp	$done1d$68062
$L68058:
	jmp	$L68029
$doneWhite1d$68067:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jl	SHORT $L68070
	jmp	$done1d$68062
$L68070:
	cmp	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jge	$L68087
	mov	edx, DWORD PTR _cp$[ebp]
	cmp	edx, DWORD PTR _ep$[ebp]
	jb	SHORT $L68081
	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L68082
	jmp	$eof1d$68047
$L68082:
	mov	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jmp	SHORT $L68087
$L68081:
	mov	eax, DWORD PTR _cp$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _bitmap$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx+ecx]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	eax, cl
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	or	ecx, eax
	mov	DWORD PTR _BitAcc$[ebp], ecx
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	add	eax, 8
	mov	DWORD PTR _BitsAvail$[ebp], eax
	cmp	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jge	SHORT $L68087
	mov	ecx, DWORD PTR _cp$[ebp]
	cmp	ecx, DWORD PTR _ep$[ebp]
	jb	SHORT $L68086
	mov	DWORD PTR _BitsAvail$[ebp], 13		; 0000000dH
	jmp	SHORT $L68087
$L68086:
	mov	edx, DWORD PTR _cp$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	ecx, DWORD PTR _bitmap$[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR [ecx+eax]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	shl	edx, cl
	mov	eax, DWORD PTR _BitAcc$[ebp]
	or	eax, edx
	mov	DWORD PTR _BitAcc$[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	add	edx, 8
	mov	DWORD PTR _BitsAvail$[ebp], edx
$L68087:
	xor	eax, eax
	test	eax, eax
	jne	$L68070
	mov	ecx, DWORD PTR _BitAcc$[ebp]
	and	ecx, 8191				; 00001fffH
	lea	edx, DWORD PTR _TIFFFaxBlackTable[ecx*8]
	mov	DWORD PTR _TabEnt$[ebp], edx
$L68089:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _BitsAvail$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax+1]
	mov	edx, DWORD PTR _BitAcc$[ebp]
	shr	edx, cl
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L68089
	xor	ecx, ecx
	test	ecx, ecx
	jne	$L68070
	mov	edx, DWORD PTR _TabEnt$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	mov	DWORD PTR -72+[ebp], eax
	mov	ecx, DWORD PTR -72+[ebp]
	sub	ecx, 8
	mov	DWORD PTR -72+[ebp], ecx
	cmp	DWORD PTR -72+[ebp], 4
	ja	SHORT $L68103
	mov	edx, DWORD PTR -72+[ebp]
	jmp	DWORD PTR $L68292[edx*4]
$L68096:
	mov	DWORD PTR _EOLcnt$[ebp], 1
	jmp	$done1d$68062
$L68097:
	mov	eax, DWORD PTR _TabEnt$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR [eax+4]
	mov	edx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L68097
	jmp	SHORT $doneBlack1d$68101
$L68102:
	mov	ecx, DWORD PTR _TabEnt$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	add	edx, DWORD PTR [ecx+4]
	mov	DWORD PTR _a0$[ebp], edx
	mov	eax, DWORD PTR _TabEnt$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR [eax+4]
	mov	DWORD PTR _RunLength$[ebp], ecx
	jmp	SHORT $L68093
$L68103:
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	push	OFFSET FLAT:_?module@?1??Fax3DecodeRLE@@9@9
	call	_Fax3Unexpected
	add	esp, 12					; 0000000cH
	jmp	$done1d$68062
$L68093:
	jmp	$L68070
$doneBlack1d$68101:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jl	SHORT $L68104
	jmp	$done1d$68062
$L68104:
	mov	edx, DWORD PTR _pa$[ebp]
	cmp	DWORD PTR [edx-4], 0
	jne	SHORT $L68105
	mov	eax, DWORD PTR _pa$[ebp]
	cmp	DWORD PTR [eax-8], 0
	jne	SHORT $L68105
	mov	ecx, DWORD PTR _pa$[ebp]
	sub	ecx, 8
	mov	DWORD PTR _pa$[ebp], ecx
$L68105:
	jmp	$L68029
$eof1d$68047:
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	push	OFFSET FLAT:_?module@?1??Fax3DecodeRLE@@9@9
	call	_Fax3PrematureEOF
	add	esp, 12					; 0000000cH
$L68106:
	cmp	DWORD PTR _RunLength$[ebp], 0
	je	SHORT $L68112
$L68110:
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [ecx], edx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L68110
$L68112:
	mov	eax, DWORD PTR _a0$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	je	$L68133
	mov	ecx, DWORD PTR _lastx$[ebp]
	push	ecx
	mov	edx, DWORD PTR _a0$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	push	OFFSET FLAT:_?module@?1??Fax3DecodeRLE@@9@9
	call	_Fax3BadLength
	add	esp, 16					; 00000010H
$L68115:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jle	SHORT $L68116
	mov	edx, DWORD PTR _pa$[ebp]
	cmp	edx, DWORD PTR _thisrun$[ebp]
	jbe	SHORT $L68116
	mov	eax, DWORD PTR _pa$[ebp]
	sub	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	edx, DWORD PTR _a0$[ebp]
	sub	edx, DWORD PTR [ecx]
	mov	DWORD PTR _a0$[ebp], edx
	jmp	SHORT $L68115
$L68116:
	mov	eax, DWORD PTR _a0$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jge	SHORT $L68117
	cmp	DWORD PTR _a0$[ebp], 0
	jge	SHORT $L68118
	mov	DWORD PTR _a0$[ebp], 0
$L68118:
	mov	ecx, DWORD PTR _pa$[ebp]
	sub	ecx, DWORD PTR _thisrun$[ebp]
	sar	ecx, 2
	and	ecx, 1
	test	ecx, ecx
	je	SHORT $L68122
$L68120:
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L68120
$L68122:
	mov	ecx, DWORD PTR _lastx$[ebp]
	sub	ecx, DWORD PTR _a0$[ebp]
	mov	edx, DWORD PTR _RunLength$[ebp]
	add	edx, ecx
	mov	eax, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [eax], edx
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _lastx$[ebp]
	sub	edx, DWORD PTR _a0$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, edx
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L68122
	jmp	SHORT $L68133
$L68117:
	mov	edx, DWORD PTR _a0$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	jle	SHORT $L68133
$L68128:
	mov	eax, DWORD PTR _RunLength$[ebp]
	add	eax, DWORD PTR _lastx$[ebp]
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	add	eax, DWORD PTR _lastx$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L68128
$L68130:
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L68130
$L68133:
	xor	ecx, ecx
	test	ecx, ecx
	jne	$L68106
	jmp	$EOFRLE$68134
$done1d$68062:
	cmp	DWORD PTR _RunLength$[ebp], 0
	je	SHORT $L68141
$L68139:
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [edx], eax
	mov	ecx, DWORD PTR _pa$[ebp]
	add	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], edx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L68139
$L68141:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	je	$L68162
	mov	edx, DWORD PTR _lastx$[ebp]
	push	edx
	mov	eax, DWORD PTR _a0$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	push	OFFSET FLAT:_?module@?1??Fax3DecodeRLE@@9@9
	call	_Fax3BadLength
	add	esp, 16					; 00000010H
$L68144:
	mov	edx, DWORD PTR _a0$[ebp]
	cmp	edx, DWORD PTR _lastx$[ebp]
	jle	SHORT $L68145
	mov	eax, DWORD PTR _pa$[ebp]
	cmp	eax, DWORD PTR _thisrun$[ebp]
	jbe	SHORT $L68145
	mov	ecx, DWORD PTR _pa$[ebp]
	sub	ecx, 4
	mov	DWORD PTR _pa$[ebp], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	mov	eax, DWORD PTR _a0$[ebp]
	sub	eax, DWORD PTR [edx]
	mov	DWORD PTR _a0$[ebp], eax
	jmp	SHORT $L68144
$L68145:
	mov	ecx, DWORD PTR _a0$[ebp]
	cmp	ecx, DWORD PTR _lastx$[ebp]
	jge	SHORT $L68146
	cmp	DWORD PTR _a0$[ebp], 0
	jge	SHORT $L68147
	mov	DWORD PTR _a0$[ebp], 0
$L68147:
	mov	edx, DWORD PTR _pa$[ebp]
	sub	edx, DWORD PTR _thisrun$[ebp]
	sar	edx, 2
	and	edx, 1
	test	edx, edx
	je	SHORT $L68151
$L68149:
	mov	eax, DWORD PTR _pa$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L68149
$L68151:
	mov	edx, DWORD PTR _lastx$[ebp]
	sub	edx, DWORD PTR _a0$[ebp]
	mov	eax, DWORD PTR _RunLength$[ebp]
	add	eax, edx
	mov	ecx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [ecx], eax
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _lastx$[ebp]
	sub	eax, DWORD PTR _a0$[ebp]
	mov	ecx, DWORD PTR _a0$[ebp]
	add	ecx, eax
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L68151
	jmp	SHORT $L68162
$L68146:
	mov	eax, DWORD PTR _a0$[ebp]
	cmp	eax, DWORD PTR _lastx$[ebp]
	jle	SHORT $L68162
$L68157:
	mov	ecx, DWORD PTR _RunLength$[ebp]
	add	ecx, DWORD PTR _lastx$[ebp]
	mov	edx, DWORD PTR _pa$[ebp]
	mov	DWORD PTR [edx], ecx
	mov	eax, DWORD PTR _pa$[ebp]
	add	eax, 4
	mov	DWORD PTR _pa$[ebp], eax
	mov	ecx, DWORD PTR _a0$[ebp]
	add	ecx, DWORD PTR _lastx$[ebp]
	mov	DWORD PTR _a0$[ebp], ecx
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	edx, edx
	test	edx, edx
	jne	SHORT $L68157
$L68159:
	mov	eax, DWORD PTR _pa$[ebp]
	mov	ecx, DWORD PTR _RunLength$[ebp]
	mov	DWORD PTR [eax], ecx
	mov	edx, DWORD PTR _pa$[ebp]
	add	edx, 4
	mov	DWORD PTR _pa$[ebp], edx
	mov	eax, DWORD PTR _a0$[ebp]
	mov	DWORD PTR _a0$[ebp], eax
	mov	DWORD PTR _RunLength$[ebp], 0
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L68159
$L68162:
	xor	edx, edx
	test	edx, edx
	jne	$done1d$68062
	xor	eax, eax
	test	eax, eax
	jne	$L68029

; 1480 : 		(*sp->fill)(buf, thisrun, pa, lastx);

	mov	ecx, DWORD PTR _lastx$[ebp]
	push	ecx
	mov	edx, DWORD PTR _pa$[ebp]
	push	edx
	mov	eax, DWORD PTR _thisrun$[ebp]
	push	eax
	mov	ecx, DWORD PTR _buf$[ebp]
	push	ecx
	mov	edx, DWORD PTR _sp$[ebp]
	call	DWORD PTR [edx+68]
	add	esp, 16					; 00000010H

; 1481 : 		/*
; 1482 : 		 * Cleanup at the end of the row.
; 1483 : 		 */
; 1484 : 		if (mode & FAXMODE_BYTEALIGN) {

	mov	eax, DWORD PTR _mode$[ebp]
	and	eax, 4
	test	eax, eax
	je	SHORT $L68163

; 1485 : 			int n = BitsAvail - (BitsAvail &~ 7);

	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	and	ecx, -8					; fffffff8H
	mov	edx, DWORD PTR _BitsAvail$[ebp]
	sub	edx, ecx
	mov	DWORD PTR _n$68164[ebp], edx
$L68165:

; 1486 : 			ClrBits(n);

	mov	eax, DWORD PTR _BitsAvail$[ebp]
	sub	eax, DWORD PTR _n$68164[ebp]
	mov	DWORD PTR _BitsAvail$[ebp], eax
	mov	edx, DWORD PTR _BitAcc$[ebp]
	mov	ecx, DWORD PTR _n$68164[ebp]
	shr	edx, cl
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L68165

; 1487 : 		} else if (mode & FAXMODE_WORDALIGN) {

	jmp	SHORT $L68176
$L68163:
	mov	ecx, DWORD PTR _mode$[ebp]
	and	ecx, 8
	test	ecx, ecx
	je	SHORT $L68176

; 1488 : 			int n = BitsAvail - (BitsAvail &~ 15);

	mov	edx, DWORD PTR _BitsAvail$[ebp]
	and	edx, -16				; fffffff0H
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	sub	eax, edx
	mov	DWORD PTR _n$68170[ebp], eax
$L68171:

; 1489 : 			ClrBits(n);

	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	sub	ecx, DWORD PTR _n$68170[ebp]
	mov	DWORD PTR _BitsAvail$[ebp], ecx
	mov	edx, DWORD PTR _BitAcc$[ebp]
	mov	ecx, DWORD PTR _n$68170[ebp]
	shr	edx, cl
	mov	DWORD PTR _BitAcc$[ebp], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L68171

; 1490 : 			if (BitsAvail == 0 && !isAligned(cp, uint16))

	cmp	DWORD PTR _BitsAvail$[ebp], 0
	jne	SHORT $L68176
	mov	ecx, DWORD PTR _cp$[ebp]
	and	ecx, 1
	test	ecx, ecx
	je	SHORT $L68176

; 1491 : 			    cp++;

	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
$L68176:

; 1493 : 		buf += sp->b.rowbytes;

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _buf$[ebp]
	add	ecx, DWORD PTR [eax+8]
	mov	DWORD PTR _buf$[ebp], ecx

; 1494 : 		occ -= sp->b.rowbytes;

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _occ$[ebp]
	sub	eax, DWORD PTR [edx+8]
	mov	DWORD PTR _occ$[ebp], eax

; 1495 : 		if (occ != 0)

	cmp	DWORD PTR _occ$[ebp], 0
	je	SHORT $L68177

; 1496 : 			tif->tif_row++;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+356]
	add	edx, 1
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+356], edx
$L68177:

; 1497 : 		continue;

	jmp	$L68027
$EOFRLE$68134:

; 1498 : 	EOFRLE:				/* premature EOF */
; 1499 : 		(*sp->fill)(buf, thisrun, pa, lastx);

	mov	ecx, DWORD PTR _lastx$[ebp]
	push	ecx
	mov	edx, DWORD PTR _pa$[ebp]
	push	edx
	mov	eax, DWORD PTR _thisrun$[ebp]
	push	eax
	mov	ecx, DWORD PTR _buf$[ebp]
	push	ecx
	mov	edx, DWORD PTR _sp$[ebp]
	call	DWORD PTR [edx+68]
	add	esp, 16					; 00000010H
$L68178:

; 1500 : 		UNCACHE_STATE(tif, sp);

	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _BitsAvail$[ebp]
	mov	DWORD PTR [eax+60], ecx
	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _BitAcc$[ebp]
	mov	DWORD PTR [edx+56], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _EOLcnt$[ebp]
	mov	DWORD PTR [ecx+64], edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _cp$[ebp]
	sub	ecx, DWORD PTR [eax+480]
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+484]
	sub	eax, ecx
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+484], eax
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [edx+480], eax
	xor	ecx, ecx
	test	ecx, ecx
	jne	SHORT $L68178

; 1501 : 		return (-1);

	or	eax, -1
	jmp	SHORT $L68001
$L68028:

; 1503 : 	UNCACHE_STATE(tif, sp);

	mov	edx, DWORD PTR _sp$[ebp]
	mov	eax, DWORD PTR _BitsAvail$[ebp]
	mov	DWORD PTR [edx+60], eax
	mov	ecx, DWORD PTR _sp$[ebp]
	mov	edx, DWORD PTR _BitAcc$[ebp]
	mov	DWORD PTR [ecx+56], edx
	mov	eax, DWORD PTR _sp$[ebp]
	mov	ecx, DWORD PTR _EOLcnt$[ebp]
	mov	DWORD PTR [eax+64], ecx
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _cp$[ebp]
	sub	eax, DWORD PTR [edx+480]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+484]
	sub	edx, eax
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+484], edx
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	mov	DWORD PTR [ecx+480], edx
	xor	eax, eax
	test	eax, eax
	jne	SHORT $L68028

; 1504 : 	return (1);

	mov	eax, 1
$L68001:

; 1505 : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L68291:
	DD	$L68063
	DD	$L68069
	DD	$L68068
	DD	$L68069
	DD	$L68068
	DD	$L68061
$L68292:
	DD	$L68097
	DD	$L68103
	DD	$L68102
	DD	$L68102
	DD	$L68096
_Fax3DecodeRLE ENDP
_TEXT	ENDS
PUBLIC	_TIFFInitCCITTRLEW
_TEXT	SEGMENT
_tif$ = 8
_TIFFInitCCITTRLEW PROC NEAR

; 1525 : {

	push	ebp
	mov	ebp, esp

; 1526 : 	if (InitCCITTFax3(tif)) {		/* reuse G3 support */

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_InitCCITTFax3
	add	esp, 4
	test	eax, eax
	je	SHORT $L68200

; 1527 : 		tif->tif_decoderow = Fax3DecodeRLE;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+416], OFFSET FLAT:_Fax3DecodeRLE

; 1528 : 		tif->tif_decodestrip = Fax3DecodeRLE;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+424], OFFSET FLAT:_Fax3DecodeRLE

; 1529 : 		tif->tif_decodetile = Fax3DecodeRLE;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+432], OFFSET FLAT:_Fax3DecodeRLE

; 1530 : 		/*
; 1531 : 		 * Suppress RTC+EOLs when encoding and word-align data.
; 1532 : 		 */
; 1533 : 		return TIFFSetField(tif, TIFFTAG_FAXMODE,
; 1534 : 		    FAXMODE_NORTC|FAXMODE_NOEOL|FAXMODE_WORDALIGN);

	push	11					; 0000000bH
	push	65536					; 00010000H
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFSetField
	add	esp, 12					; 0000000cH
	jmp	SHORT $L68201
$L68200:

; 1536 : 		return (0);

	xor	eax, eax
$L68201:

; 1537 : }

	pop	ebp
	ret	0
_TIFFInitCCITTRLEW ENDP
_TEXT	ENDS
END
