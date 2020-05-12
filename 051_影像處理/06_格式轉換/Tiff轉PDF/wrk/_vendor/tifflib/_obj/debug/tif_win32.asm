	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_win32.c
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
PUBLIC	__TIFFwarningHandler
PUBLIC	__TIFFerrorHandler
CONST	SEGMENT
_?module@?1??TIFFOpen@@9@9 DB 'TIFFOpen', 00H
CONST	ENDS
_DATA	SEGMENT
__TIFFwarningHandler DD FLAT:_Win32WarningHandler
__TIFFerrorHandler DD FLAT:_Win32ErrorHandler
_DATA	ENDS
PUBLIC	_TIFFFdOpen
EXTRN	_TIFFClientOpen:NEAR
_TEXT	SEGMENT
_ifd$ = 8
_name$ = 12
_mode$ = 16
_tif$ = -8
_fSuppressMap$ = -4
_TIFFFdOpen PROC NEAR

; 153  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 20					; 00000014H

; 154  : 	TIFF* tif;
; 155  : 	BOOL fSuppressMap = (mode[1] == 'u' || (mode[1]!=0 && mode[2] == 'u'));

	mov	eax, DWORD PTR _mode$[ebp]
	movsx	ecx, BYTE PTR [eax+1]
	cmp	ecx, 117				; 00000075H
	je	SHORT $L66040
	mov	edx, DWORD PTR _mode$[ebp]
	movsx	eax, BYTE PTR [edx+1]
	test	eax, eax
	je	SHORT $L66039
	mov	ecx, DWORD PTR _mode$[ebp]
	movsx	edx, BYTE PTR [ecx+2]
	cmp	edx, 117				; 00000075H
	je	SHORT $L66040
$L66039:
	mov	DWORD PTR -12+[ebp], 0
	jmp	SHORT $L66041
$L66040:
	mov	DWORD PTR -12+[ebp], 1
$L66041:
	mov	eax, DWORD PTR -12+[ebp]
	mov	DWORD PTR _fSuppressMap$[ebp], eax

; 156  : 
; 157  : 	tif = TIFFClientOpen(name, mode,
; 158  : 		 (thandle_t)ifd,
; 159  : 	    _tiffReadProc, _tiffWriteProc,
; 160  : 	    _tiffSeekProc, _tiffCloseProc, _tiffSizeProc,
; 161  : 		 fSuppressMap ? _tiffDummyMapProc : _tiffMapProc,
; 162  : 		 fSuppressMap ? _tiffDummyUnmapProc : _tiffUnmapProc);

	cmp	DWORD PTR _fSuppressMap$[ebp], 0
	je	SHORT $L66042
	mov	DWORD PTR -16+[ebp], OFFSET FLAT:__tiffDummyUnmapProc
	jmp	SHORT $L66043
$L66042:
	mov	DWORD PTR -16+[ebp], OFFSET FLAT:__tiffUnmapProc
$L66043:
	cmp	DWORD PTR _fSuppressMap$[ebp], 0
	je	SHORT $L66044
	mov	DWORD PTR -20+[ebp], OFFSET FLAT:__tiffDummyMapProc
	jmp	SHORT $L66045
$L66044:
	mov	DWORD PTR -20+[ebp], OFFSET FLAT:__tiffMapProc
$L66045:
	mov	ecx, DWORD PTR -16+[ebp]
	push	ecx
	mov	edx, DWORD PTR -20+[ebp]
	push	edx
	push	OFFSET FLAT:__tiffSizeProc
	push	OFFSET FLAT:__tiffCloseProc
	push	OFFSET FLAT:__tiffSeekProc
	push	OFFSET FLAT:__tiffWriteProc
	push	OFFSET FLAT:__tiffReadProc
	mov	eax, DWORD PTR _ifd$[ebp]
	push	eax
	mov	ecx, DWORD PTR _mode$[ebp]
	push	ecx
	mov	edx, DWORD PTR _name$[ebp]
	push	edx
	call	_TIFFClientOpen
	add	esp, 40					; 00000028H
	mov	DWORD PTR _tif$[ebp], eax

; 163  : 	if (tif)

	cmp	DWORD PTR _tif$[ebp], 0
	je	SHORT $L65889

; 164  : 		tif->tif_fd = ifd;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _ifd$[ebp]
	mov	DWORD PTR [eax+4], ecx
$L65889:

; 165  : 	return (tif);

	mov	eax, DWORD PTR _tif$[ebp]

; 166  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFFdOpen ENDP
_TEXT	ENDS
EXTRN	__imp__ReadFile@20:NEAR
_TEXT	SEGMENT
_fd$ = 8
_buf$ = 12
_size$ = 16
_dwSizeRead$ = -4
__tiffReadProc PROC NEAR

; 36   : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 37   : 	DWORD dwSizeRead;
; 38   : 	if (!ReadFile(fd, buf, size, &dwSizeRead, NULL))

	push	0
	lea	eax, DWORD PTR _dwSizeRead$[ebp]
	push	eax
	mov	ecx, DWORD PTR _size$[ebp]
	push	ecx
	mov	edx, DWORD PTR _buf$[ebp]
	push	edx
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	DWORD PTR __imp__ReadFile@20
	test	eax, eax
	jne	SHORT $L65792

; 39   : 		return(0);

	xor	eax, eax
	jmp	SHORT $L65789
$L65792:

; 40   : 	return ((tsize_t) dwSizeRead);

	mov	eax, DWORD PTR _dwSizeRead$[ebp]
$L65789:

; 41   : }

	mov	esp, ebp
	pop	ebp
	ret	0
__tiffReadProc ENDP
_TEXT	ENDS
EXTRN	__imp__WriteFile@20:NEAR
_TEXT	SEGMENT
_fd$ = 8
_buf$ = 12
_size$ = 16
_dwSizeWritten$ = -4
__tiffWriteProc PROC NEAR

; 45   : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 46   : 	DWORD dwSizeWritten;
; 47   : 	if (!WriteFile(fd, buf, size, &dwSizeWritten, NULL))

	push	0
	lea	eax, DWORD PTR _dwSizeWritten$[ebp]
	push	eax
	mov	ecx, DWORD PTR _size$[ebp]
	push	ecx
	mov	edx, DWORD PTR _buf$[ebp]
	push	edx
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	DWORD PTR __imp__WriteFile@20
	test	eax, eax
	jne	SHORT $L65804

; 48   : 		return(0);

	xor	eax, eax
	jmp	SHORT $L65801
$L65804:

; 49   : 	return ((tsize_t) dwSizeWritten);

	mov	eax, DWORD PTR _dwSizeWritten$[ebp]
$L65801:

; 50   : }

	mov	esp, ebp
	pop	ebp
	ret	0
__tiffWriteProc ENDP
_TEXT	ENDS
EXTRN	__imp__SetFilePointer@16:NEAR
_TEXT	SEGMENT
_fd$ = 8
_off$ = 12
_whence$ = 16
_dwMoveMethod$ = -8
_dwMoveHigh$ = -4
__tiffSeekProc PROC NEAR

; 54   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 55   : 	DWORD dwMoveMethod, dwMoveHigh;
; 56   : 
; 57   :         /* we use this as a special code, so avoid accepting it */
; 58   :         if( off == 0xFFFFFFFF )

	cmp	DWORD PTR _off$[ebp], -1
	jne	SHORT $L65816

; 59   :             return 0xFFFFFFFF;

	or	eax, -1
	jmp	SHORT $L65813
$L65816:

; 60   :         
; 61   : 	switch(whence)
; 62   : 	{

	mov	eax, DWORD PTR _whence$[ebp]
	mov	DWORD PTR -12+[ebp], eax
	cmp	DWORD PTR -12+[ebp], 0
	je	SHORT $L65821
	cmp	DWORD PTR -12+[ebp], 1
	je	SHORT $L65822
	cmp	DWORD PTR -12+[ebp], 2
	je	SHORT $L65823
	jmp	SHORT $L65824
$L65821:

; 63   : 	case SEEK_SET:
; 64   : 		dwMoveMethod = FILE_BEGIN;

	mov	DWORD PTR _dwMoveMethod$[ebp], 0

; 65   : 		break;

	jmp	SHORT $L65818
$L65822:

; 66   : 	case SEEK_CUR:
; 67   : 		dwMoveMethod = FILE_CURRENT;

	mov	DWORD PTR _dwMoveMethod$[ebp], 1

; 68   : 		break;

	jmp	SHORT $L65818
$L65823:

; 69   : 	case SEEK_END:
; 70   : 		dwMoveMethod = FILE_END;

	mov	DWORD PTR _dwMoveMethod$[ebp], 2

; 71   : 		break;

	jmp	SHORT $L65818
$L65824:

; 72   : 	default:
; 73   : 		dwMoveMethod = FILE_BEGIN;

	mov	DWORD PTR _dwMoveMethod$[ebp], 0
$L65818:

; 76   :         dwMoveHigh = 0;

	mov	DWORD PTR _dwMoveHigh$[ebp], 0

; 77   : 	return ((toff_t)SetFilePointer(fd, (LONG) off, (PLONG)&dwMoveHigh,
; 78   :                                        dwMoveMethod));

	mov	ecx, DWORD PTR _dwMoveMethod$[ebp]
	push	ecx
	lea	edx, DWORD PTR _dwMoveHigh$[ebp]
	push	edx
	mov	eax, DWORD PTR _off$[ebp]
	push	eax
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	DWORD PTR __imp__SetFilePointer@16
$L65813:

; 79   : }

	mov	esp, ebp
	pop	ebp
	ret	0
__tiffSeekProc ENDP
_TEXT	ENDS
EXTRN	__imp__CloseHandle@4:NEAR
_TEXT	SEGMENT
_fd$ = 8
__tiffCloseProc PROC NEAR

; 83   : {

	push	ebp
	mov	ebp, esp

; 84   : 	return (CloseHandle(fd) ? 0 : -1);

	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	DWORD PTR __imp__CloseHandle@4
	neg	eax
	sbb	eax, eax
	neg	eax
	dec	eax

; 85   : }

	pop	ebp
	ret	0
__tiffCloseProc ENDP
_TEXT	ENDS
EXTRN	__imp__GetFileSize@8:NEAR
_TEXT	SEGMENT
_fd$ = 8
__tiffSizeProc PROC NEAR

; 89   : {

	push	ebp
	mov	ebp, esp

; 90   : 	return ((toff_t)GetFileSize(fd, NULL));

	push	0
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	DWORD PTR __imp__GetFileSize@8

; 91   : }

	pop	ebp
	ret	0
__tiffSizeProc ENDP
__tiffDummyMapProc PROC NEAR

; 98   : {

	push	ebp
	mov	ebp, esp

; 99   : 	return (0);

	xor	eax, eax

; 100  : }

	pop	ebp
	ret	0
__tiffDummyMapProc ENDP
_TEXT	ENDS
EXTRN	__imp__CreateFileMappingA@24:NEAR
EXTRN	__imp__MapViewOfFile@20:NEAR
_TEXT	SEGMENT
_fd$ = 8
_pbase$ = 12
_psize$ = 16
_size$ = -4
_hMapFile$ = -8
__tiffMapProc PROC NEAR

; 115  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 116  : 	toff_t size;
; 117  : 	HANDLE hMapFile;
; 118  : 
; 119  : 	if ((size = _tiffSizeProc(fd)) == 0xFFFFFFFF)

	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	__tiffSizeProc
	add	esp, 4
	mov	DWORD PTR _size$[ebp], eax
	cmp	DWORD PTR _size$[ebp], -1
	jne	SHORT $L65856

; 120  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L65853
$L65856:

; 121  : 	hMapFile = CreateFileMapping(fd, NULL, PAGE_READONLY, 0, size, NULL);

	push	0
	mov	ecx, DWORD PTR _size$[ebp]
	push	ecx
	push	0
	push	2
	push	0
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	DWORD PTR __imp__CreateFileMappingA@24
	mov	DWORD PTR _hMapFile$[ebp], eax

; 122  : 	if (hMapFile == NULL)

	cmp	DWORD PTR _hMapFile$[ebp], 0
	jne	SHORT $L65860

; 123  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L65853
$L65860:

; 124  : 	*pbase = MapViewOfFile(hMapFile, FILE_MAP_READ, 0, 0, 0);

	push	0
	push	0
	push	0
	push	4
	mov	eax, DWORD PTR _hMapFile$[ebp]
	push	eax
	call	DWORD PTR __imp__MapViewOfFile@20
	mov	ecx, DWORD PTR _pbase$[ebp]
	mov	DWORD PTR [ecx], eax

; 125  : 	CloseHandle(hMapFile);

	mov	edx, DWORD PTR _hMapFile$[ebp]
	push	edx
	call	DWORD PTR __imp__CloseHandle@4

; 126  : 	if (*pbase == NULL)

	mov	eax, DWORD PTR _pbase$[ebp]
	cmp	DWORD PTR [eax], 0
	jne	SHORT $L65862

; 127  : 		return (0);

	xor	eax, eax
	jmp	SHORT $L65853
$L65862:

; 128  : 	*psize = size;

	mov	ecx, DWORD PTR _psize$[ebp]
	mov	edx, DWORD PTR _size$[ebp]
	mov	DWORD PTR [ecx], edx

; 129  : 	return(1);

	mov	eax, 1
$L65853:

; 130  : }

	mov	esp, ebp
	pop	ebp
	ret	0
__tiffMapProc ENDP
__tiffDummyUnmapProc PROC NEAR

; 137  : {

	push	ebp
	mov	ebp, esp

; 138  : }

	pop	ebp
	ret	0
__tiffDummyUnmapProc ENDP
_TEXT	ENDS
EXTRN	__imp__UnmapViewOfFile@4:NEAR
_TEXT	SEGMENT
_base$ = 12
__tiffUnmapProc PROC NEAR

; 142  : {

	push	ebp
	mov	ebp, esp

; 143  : 	UnmapViewOfFile(base);

	mov	eax, DWORD PTR _base$[ebp]
	push	eax
	call	DWORD PTR __imp__UnmapViewOfFile@4

; 144  : }

	pop	ebp
	ret	0
__tiffUnmapProc ENDP
_TEXT	ENDS
PUBLIC	_TIFFOpen
EXTRN	__TIFFgetMode:NEAR
EXTRN	_TIFFError:NEAR
EXTRN	__imp__CreateFileA@28:NEAR
_DATA	SEGMENT
$SG65916 DB	'%s: Cannot open', 00H
_DATA	ENDS
_TEXT	SEGMENT
_name$ = 8
_mode$ = 12
_fd$ = -4
_m$ = -12
_dwMode$ = -8
_TIFFOpen PROC NEAR

; 173  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 174  : 	static const char module[] = "TIFFOpen";
; 175  : 	thandle_t fd;
; 176  : 	int m;
; 177  : 	DWORD dwMode;
; 178  : 
; 179  : 	m = _TIFFgetMode(mode, module);

	push	OFFSET FLAT:_?module@?1??TIFFOpen@@9@9
	mov	eax, DWORD PTR _mode$[ebp]
	push	eax
	call	__TIFFgetMode
	add	esp, 8
	mov	DWORD PTR _m$[ebp], eax

; 180  : 
; 181  : 	switch(m)
; 182  : 	{

	mov	ecx, DWORD PTR _m$[ebp]
	mov	DWORD PTR -16+[ebp], ecx
	cmp	DWORD PTR -16+[ebp], 258		; 00000102H
	jg	SHORT $L66056
	cmp	DWORD PTR -16+[ebp], 258		; 00000102H
	je	SHORT $L65906
	cmp	DWORD PTR -16+[ebp], 0
	je	SHORT $L65904
	cmp	DWORD PTR -16+[ebp], 2
	je	SHORT $L65905
	jmp	SHORT $L65909
$L66056:
	cmp	DWORD PTR -16+[ebp], 514		; 00000202H
	je	SHORT $L65907
	cmp	DWORD PTR -16+[ebp], 770		; 00000302H
	je	SHORT $L65908
	jmp	SHORT $L65909
$L65904:

; 183  : 	case O_RDONLY:
; 184  : 		dwMode = OPEN_EXISTING;

	mov	DWORD PTR _dwMode$[ebp], 3

; 185  : 		break;

	jmp	SHORT $L65901
$L65905:

; 186  : 	case O_RDWR:
; 187  : 		dwMode = OPEN_ALWAYS;

	mov	DWORD PTR _dwMode$[ebp], 4

; 188  : 		break;

	jmp	SHORT $L65901
$L65906:

; 189  : 	case O_RDWR|O_CREAT:
; 190  : 		dwMode = OPEN_ALWAYS;

	mov	DWORD PTR _dwMode$[ebp], 4

; 191  : 		break;

	jmp	SHORT $L65901
$L65907:

; 192  : 	case O_RDWR|O_TRUNC:
; 193  : 		dwMode = CREATE_ALWAYS;

	mov	DWORD PTR _dwMode$[ebp], 2

; 194  : 		break;

	jmp	SHORT $L65901
$L65908:

; 195  : 	case O_RDWR|O_CREAT|O_TRUNC:
; 196  : 		dwMode = CREATE_ALWAYS;

	mov	DWORD PTR _dwMode$[ebp], 2

; 197  : 		break;

	jmp	SHORT $L65901
$L65909:

; 198  : 	default:
; 199  : 		return ((TIFF*)0);

	xor	eax, eax
	jmp	SHORT $L65894
$L65901:

; 201  : 	fd = (thandle_t)CreateFile(name, (m == O_RDONLY) ? GENERIC_READ :
; 202  : 			(GENERIC_READ | GENERIC_WRITE), FILE_SHARE_READ, NULL, dwMode,
; 203  : 			(m == O_RDONLY) ? FILE_ATTRIBUTE_READONLY : FILE_ATTRIBUTE_NORMAL, NULL);

	push	0
	mov	edx, DWORD PTR _m$[ebp]
	neg	edx
	sbb	edx, edx
	and	edx, 127				; 0000007fH
	add	edx, 1
	push	edx
	mov	eax, DWORD PTR _dwMode$[ebp]
	push	eax
	push	0
	push	1
	mov	ecx, DWORD PTR _m$[ebp]
	neg	ecx
	sbb	ecx, ecx
	and	ecx, 1073741824				; 40000000H
	add	ecx, -2147483648			; 80000000H
	push	ecx
	mov	edx, DWORD PTR _name$[ebp]
	push	edx
	call	DWORD PTR __imp__CreateFileA@28
	mov	DWORD PTR _fd$[ebp], eax

; 204  : 	if (fd == INVALID_HANDLE_VALUE) {

	cmp	DWORD PTR _fd$[ebp], -1
	jne	SHORT $L65915

; 205  : 		TIFFError(module, "%s: Cannot open", name);

	mov	eax, DWORD PTR _name$[ebp]
	push	eax
	push	OFFSET FLAT:$SG65916
	push	OFFSET FLAT:_?module@?1??TIFFOpen@@9@9
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 206  : 		return ((TIFF *)0);

	xor	eax, eax
	jmp	SHORT $L65894
$L65915:

; 208  : 	return (TIFFFdOpen((int)fd, name, mode));

	mov	ecx, DWORD PTR _mode$[ebp]
	push	ecx
	mov	edx, DWORD PTR _name$[ebp]
	push	edx
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_TIFFFdOpen
	add	esp, 12					; 0000000cH
$L65894:

; 209  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_TIFFOpen ENDP
_TEXT	ENDS
PUBLIC	__TIFFmalloc
EXTRN	__imp__GlobalAlloc@8:NEAR
_TEXT	SEGMENT
_s$ = 8
__TIFFmalloc PROC NEAR

; 213  : {

	push	ebp
	mov	ebp, esp

; 214  : 	return ((tdata_t)GlobalAlloc(GMEM_FIXED, s));

	mov	eax, DWORD PTR _s$[ebp]
	push	eax
	push	0
	call	DWORD PTR __imp__GlobalAlloc@8

; 215  : }

	pop	ebp
	ret	0
__TIFFmalloc ENDP
_TEXT	ENDS
PUBLIC	__TIFFfree
EXTRN	__imp__GlobalFree@4:NEAR
_TEXT	SEGMENT
_p$ = 8
__TIFFfree PROC NEAR

; 219  : {

	push	ebp
	mov	ebp, esp

; 220  : 	GlobalFree(p);

	mov	eax, DWORD PTR _p$[ebp]
	push	eax
	call	DWORD PTR __imp__GlobalFree@4

; 221  : 	return;
; 222  : }

	pop	ebp
	ret	0
__TIFFfree ENDP
_TEXT	ENDS
PUBLIC	__TIFFrealloc
EXTRN	__imp__GlobalSize@4:NEAR
EXTRN	_memcpy:NEAR
_TEXT	SEGMENT
_p$ = 8
_s$ = 12
_pvTmp$ = -4
_old$ = -8
__TIFFrealloc PROC NEAR

; 226  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 227  :   void* pvTmp;
; 228  :   tsize_t old=GlobalSize(p);

	mov	eax, DWORD PTR _p$[ebp]
	push	eax
	call	DWORD PTR __imp__GlobalSize@4
	mov	DWORD PTR _old$[ebp], eax

; 229  :   if (old>=s)

	mov	ecx, DWORD PTR _old$[ebp]
	cmp	ecx, DWORD PTR _s$[ebp]
	jl	SHORT $L65933

; 231  :       if ((pvTmp = GlobalAlloc(GMEM_FIXED, s)) != NULL) {

	mov	edx, DWORD PTR _s$[ebp]
	push	edx
	push	0
	call	DWORD PTR __imp__GlobalAlloc@8
	mov	DWORD PTR _pvTmp$[ebp], eax
	cmp	DWORD PTR _pvTmp$[ebp], 0
	je	SHORT $L65935

; 232  : 	CopyMemory(pvTmp, p, s);

	mov	eax, DWORD PTR _s$[ebp]
	push	eax
	mov	ecx, DWORD PTR _p$[ebp]
	push	ecx
	mov	edx, DWORD PTR _pvTmp$[ebp]
	push	edx
	call	_memcpy
	add	esp, 12					; 0000000cH

; 233  : 	GlobalFree(p);

	mov	eax, DWORD PTR _p$[ebp]
	push	eax
	call	DWORD PTR __imp__GlobalFree@4
$L65935:

; 236  :   else

	jmp	SHORT $L65938
$L65933:

; 238  :       if ((pvTmp = GlobalAlloc(GMEM_FIXED, s)) != NULL) {

	mov	ecx, DWORD PTR _s$[ebp]
	push	ecx
	push	0
	call	DWORD PTR __imp__GlobalAlloc@8
	mov	DWORD PTR _pvTmp$[ebp], eax
	cmp	DWORD PTR _pvTmp$[ebp], 0
	je	SHORT $L65938

; 239  : 	CopyMemory(pvTmp, p, old);

	mov	edx, DWORD PTR _old$[ebp]
	push	edx
	mov	eax, DWORD PTR _p$[ebp]
	push	eax
	mov	ecx, DWORD PTR _pvTmp$[ebp]
	push	ecx
	call	_memcpy
	add	esp, 12					; 0000000cH

; 240  : 	GlobalFree(p);

	mov	edx, DWORD PTR _p$[ebp]
	push	edx
	call	DWORD PTR __imp__GlobalFree@4
$L65938:

; 243  :   return ((tdata_t)pvTmp);

	mov	eax, DWORD PTR _pvTmp$[ebp]

; 244  : }

	mov	esp, ebp
	pop	ebp
	ret	0
__TIFFrealloc ENDP
_TEXT	ENDS
PUBLIC	__TIFFmemset
EXTRN	_memset:NEAR
_TEXT	SEGMENT
_p$ = 8
_v$ = 12
_c$ = 16
__TIFFmemset PROC NEAR

; 248  : {

	push	ebp
	mov	ebp, esp

; 249  : 	FillMemory(p, c, (BYTE)v);

	mov	eax, DWORD PTR _c$[ebp]
	push	eax
	mov	ecx, DWORD PTR _v$[ebp]
	and	ecx, 255				; 000000ffH
	push	ecx
	mov	edx, DWORD PTR _p$[ebp]
	push	edx
	call	_memset
	add	esp, 12					; 0000000cH

; 250  : }

	pop	ebp
	ret	0
__TIFFmemset ENDP
_TEXT	ENDS
PUBLIC	__TIFFmemcpy
_TEXT	SEGMENT
_d$ = 8
_s$ = 12
_c$ = 16
__TIFFmemcpy PROC NEAR

; 254  : {

	push	ebp
	mov	ebp, esp

; 255  : 	CopyMemory(d, s, c);

	mov	eax, DWORD PTR _c$[ebp]
	push	eax
	mov	ecx, DWORD PTR _s$[ebp]
	push	ecx
	mov	edx, DWORD PTR _d$[ebp]
	push	edx
	call	_memcpy
	add	esp, 12					; 0000000cH

; 256  : }

	pop	ebp
	ret	0
__TIFFmemcpy ENDP
_TEXT	ENDS
PUBLIC	__TIFFmemcmp
_TEXT	SEGMENT
_p1$ = 8
_p2$ = 12
_c$ = 16
_pb1$ = -8
_pb2$ = -16
_dwTmp$ = -4
_iTmp$ = -12
__TIFFmemcmp PROC NEAR

; 260  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 16					; 00000010H

; 261  : 	register const BYTE *pb1 = (const BYTE *) p1;

	mov	eax, DWORD PTR _p1$[ebp]
	mov	DWORD PTR _pb1$[ebp], eax

; 262  : 	register const BYTE *pb2 = (const BYTE *) p2;

	mov	ecx, DWORD PTR _p2$[ebp]
	mov	DWORD PTR _pb2$[ebp], ecx

; 263  : 	register DWORD dwTmp = c;

	mov	edx, DWORD PTR _c$[ebp]
	mov	DWORD PTR _dwTmp$[ebp], edx

; 264  : 	register int iTmp;
; 265  : 	for (iTmp = 0; dwTmp-- && !iTmp; iTmp = (int)*pb1++ - (int)*pb2++)

	mov	DWORD PTR _iTmp$[ebp], 0
	jmp	SHORT $L65970
$L65971:
	mov	eax, DWORD PTR _pb1$[ebp]
	xor	ecx, ecx
	mov	cl, BYTE PTR [eax]
	mov	edx, DWORD PTR _pb2$[ebp]
	xor	eax, eax
	mov	al, BYTE PTR [edx]
	sub	ecx, eax
	mov	DWORD PTR _iTmp$[ebp], ecx
	mov	ecx, DWORD PTR _pb2$[ebp]
	add	ecx, 1
	mov	DWORD PTR _pb2$[ebp], ecx
	mov	edx, DWORD PTR _pb1$[ebp]
	add	edx, 1
	mov	DWORD PTR _pb1$[ebp], edx
$L65970:
	mov	eax, DWORD PTR _dwTmp$[ebp]
	mov	ecx, DWORD PTR _dwTmp$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _dwTmp$[ebp], ecx
	test	eax, eax
	je	SHORT $L65972
	cmp	DWORD PTR _iTmp$[ebp], 0
	jne	SHORT $L65972

; 266  : 		;

	jmp	SHORT $L65971
$L65972:

; 267  : 	return (iTmp);

	mov	eax, DWORD PTR _iTmp$[ebp]

; 268  : }

	mov	esp, ebp
	pop	ebp
	ret	0
__TIFFmemcmp ENDP
_TEXT	ENDS
EXTRN	__imp__MessageBoxA@16:NEAR
EXTRN	__imp__LocalAlloc@8:NEAR
EXTRN	__imp__LocalFree@4:NEAR
EXTRN	__imp__wvsprintfA@12:NEAR
EXTRN	__imp__wsprintfA:NEAR
EXTRN	__imp__lstrlenA@4:NEAR
EXTRN	__imp__GetFocus@0:NEAR
_DATA	SEGMENT
$SG65984 DB	'%s Warning', 00H
	ORG $+1
$SG65986 DB	'TIFFLIB', 00H
_DATA	ENDS
_TEXT	SEGMENT
_module$ = 8
_fmt$ = 12
_ap$ = 16
_szTitle$ = -4
_szTmp$ = -8
_szTitleText$ = -12
_szDefaultModule$ = -16
_Win32WarningHandler PROC NEAR

; 272  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 20					; 00000014H
	push	esi

; 273  : #ifndef TIF_PLATFORM_CONSOLE
; 274  : 	LPTSTR szTitle;
; 275  : 	LPTSTR szTmp;
; 276  : 	LPCTSTR szTitleText = "%s Warning";

	mov	DWORD PTR _szTitleText$[ebp], OFFSET FLAT:$SG65984

; 277  : 	LPCTSTR szDefaultModule = "TIFFLIB";

	mov	DWORD PTR _szDefaultModule$[ebp], OFFSET FLAT:$SG65986

; 278  : 	szTmp = (module == NULL) ? (LPTSTR)szDefaultModule : (LPTSTR)module;

	cmp	DWORD PTR _module$[ebp], 0
	jne	SHORT $L66064
	mov	eax, DWORD PTR _szDefaultModule$[ebp]
	mov	DWORD PTR -20+[ebp], eax
	jmp	SHORT $L66065
$L66064:
	mov	ecx, DWORD PTR _module$[ebp]
	mov	DWORD PTR -20+[ebp], ecx
$L66065:
	mov	edx, DWORD PTR -20+[ebp]
	mov	DWORD PTR _szTmp$[ebp], edx

; 279  : 	if ((szTitle = (LPTSTR)LocalAlloc(LMEM_FIXED, (lstrlen(szTmp) +
; 280  : 			lstrlen(szTitleText) + lstrlen(fmt) + 128)*sizeof(TCHAR))) == NULL)

	mov	eax, DWORD PTR _szTmp$[ebp]
	push	eax
	call	DWORD PTR __imp__lstrlenA@4
	mov	esi, eax
	mov	ecx, DWORD PTR _szTitleText$[ebp]
	push	ecx
	call	DWORD PTR __imp__lstrlenA@4
	add	esi, eax
	mov	edx, DWORD PTR _fmt$[ebp]
	push	edx
	call	DWORD PTR __imp__lstrlenA@4
	lea	eax, DWORD PTR [esi+eax+128]
	push	eax
	push	0
	call	DWORD PTR __imp__LocalAlloc@8
	mov	DWORD PTR _szTitle$[ebp], eax
	cmp	DWORD PTR _szTitle$[ebp], 0
	jne	SHORT $L65993

; 281  : 		return;

	jmp	SHORT $L65980
$L65993:

; 282  : 	wsprintf(szTitle, szTitleText, szTmp);

	mov	ecx, DWORD PTR _szTmp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _szTitleText$[ebp]
	push	edx
	mov	eax, DWORD PTR _szTitle$[ebp]
	push	eax
	call	DWORD PTR __imp__wsprintfA
	add	esp, 12					; 0000000cH

; 283  : 	szTmp = szTitle + (lstrlen(szTitle)+2)*sizeof(TCHAR);

	mov	ecx, DWORD PTR _szTitle$[ebp]
	push	ecx
	call	DWORD PTR __imp__lstrlenA@4
	mov	edx, DWORD PTR _szTitle$[ebp]
	lea	eax, DWORD PTR [edx+eax+2]
	mov	DWORD PTR _szTmp$[ebp], eax

; 284  : 	wvsprintf(szTmp, fmt, ap);

	mov	ecx, DWORD PTR _ap$[ebp]
	push	ecx
	mov	edx, DWORD PTR _fmt$[ebp]
	push	edx
	mov	eax, DWORD PTR _szTmp$[ebp]
	push	eax
	call	DWORD PTR __imp__wvsprintfA@12

; 285  : 	MessageBox(GetFocus(), szTmp, szTitle, MB_OK | MB_ICONINFORMATION);

	push	64					; 00000040H
	mov	ecx, DWORD PTR _szTitle$[ebp]
	push	ecx
	mov	edx, DWORD PTR _szTmp$[ebp]
	push	edx
	call	DWORD PTR __imp__GetFocus@0
	push	eax
	call	DWORD PTR __imp__MessageBoxA@16

; 286  : 	LocalFree(szTitle);

	mov	eax, DWORD PTR _szTitle$[ebp]
	push	eax
	call	DWORD PTR __imp__LocalFree@4
$L65980:

; 287  : 	return;
; 288  : #else
; 289  : 	if (module != NULL)
; 290  : 		fprintf(stderr, "%s: ", module);
; 291  : 	fprintf(stderr, "Warning, ");
; 292  : 	vfprintf(stderr, fmt, ap);
; 293  : 	fprintf(stderr, ".\n");
; 294  : #endif        
; 295  : }

	pop	esi
	mov	esp, ebp
	pop	ebp
	ret	0
_Win32WarningHandler ENDP
_TEXT	ENDS
_DATA	SEGMENT
$SG66006 DB	'%s Error', 00H
	ORG $+3
$SG66008 DB	'TIFFLIB', 00H
_DATA	ENDS
_TEXT	SEGMENT
_module$ = 8
_fmt$ = 12
_ap$ = 16
_szTitle$ = -4
_szTmp$ = -8
_szTitleText$ = -12
_szDefaultModule$ = -16
_Win32ErrorHandler PROC NEAR

; 300  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 20					; 00000014H
	push	esi

; 301  : #ifndef TIF_PLATFORM_CONSOLE
; 302  : 	LPTSTR szTitle;
; 303  : 	LPTSTR szTmp;
; 304  : 	LPCTSTR szTitleText = "%s Error";

	mov	DWORD PTR _szTitleText$[ebp], OFFSET FLAT:$SG66006

; 305  : 	LPCTSTR szDefaultModule = "TIFFLIB";

	mov	DWORD PTR _szDefaultModule$[ebp], OFFSET FLAT:$SG66008

; 306  : 	szTmp = (module == NULL) ? (LPTSTR)szDefaultModule : (LPTSTR)module;

	cmp	DWORD PTR _module$[ebp], 0
	jne	SHORT $L66067
	mov	eax, DWORD PTR _szDefaultModule$[ebp]
	mov	DWORD PTR -20+[ebp], eax
	jmp	SHORT $L66068
$L66067:
	mov	ecx, DWORD PTR _module$[ebp]
	mov	DWORD PTR -20+[ebp], ecx
$L66068:
	mov	edx, DWORD PTR -20+[ebp]
	mov	DWORD PTR _szTmp$[ebp], edx

; 307  : 	if ((szTitle = (LPTSTR)LocalAlloc(LMEM_FIXED, (lstrlen(szTmp) +
; 308  : 			lstrlen(szTitleText) + lstrlen(fmt) + 128)*sizeof(TCHAR))) == NULL)

	mov	eax, DWORD PTR _szTmp$[ebp]
	push	eax
	call	DWORD PTR __imp__lstrlenA@4
	mov	esi, eax
	mov	ecx, DWORD PTR _szTitleText$[ebp]
	push	ecx
	call	DWORD PTR __imp__lstrlenA@4
	add	esi, eax
	mov	edx, DWORD PTR _fmt$[ebp]
	push	edx
	call	DWORD PTR __imp__lstrlenA@4
	lea	eax, DWORD PTR [esi+eax+128]
	push	eax
	push	0
	call	DWORD PTR __imp__LocalAlloc@8
	mov	DWORD PTR _szTitle$[ebp], eax
	cmp	DWORD PTR _szTitle$[ebp], 0
	jne	SHORT $L66015

; 309  : 		return;

	jmp	SHORT $L66002
$L66015:

; 310  : 	wsprintf(szTitle, szTitleText, szTmp);

	mov	ecx, DWORD PTR _szTmp$[ebp]
	push	ecx
	mov	edx, DWORD PTR _szTitleText$[ebp]
	push	edx
	mov	eax, DWORD PTR _szTitle$[ebp]
	push	eax
	call	DWORD PTR __imp__wsprintfA
	add	esp, 12					; 0000000cH

; 311  : 	szTmp = szTitle + (lstrlen(szTitle)+2)*sizeof(TCHAR);

	mov	ecx, DWORD PTR _szTitle$[ebp]
	push	ecx
	call	DWORD PTR __imp__lstrlenA@4
	mov	edx, DWORD PTR _szTitle$[ebp]
	lea	eax, DWORD PTR [edx+eax+2]
	mov	DWORD PTR _szTmp$[ebp], eax

; 312  : 	wvsprintf(szTmp, fmt, ap);

	mov	ecx, DWORD PTR _ap$[ebp]
	push	ecx
	mov	edx, DWORD PTR _fmt$[ebp]
	push	edx
	mov	eax, DWORD PTR _szTmp$[ebp]
	push	eax
	call	DWORD PTR __imp__wvsprintfA@12

; 313  : 	MessageBox(GetFocus(), szTmp, szTitle, MB_OK | MB_ICONEXCLAMATION);

	push	48					; 00000030H
	mov	ecx, DWORD PTR _szTitle$[ebp]
	push	ecx
	mov	edx, DWORD PTR _szTmp$[ebp]
	push	edx
	call	DWORD PTR __imp__GetFocus@0
	push	eax
	call	DWORD PTR __imp__MessageBoxA@16

; 314  : 	LocalFree(szTitle);

	mov	eax, DWORD PTR _szTitle$[ebp]
	push	eax
	call	DWORD PTR __imp__LocalFree@4
$L66002:

; 315  : 	return;
; 316  : #else
; 317  : 	if (module != NULL)
; 318  : 		fprintf(stderr, "%s: ", module);
; 319  : 	vfprintf(stderr, fmt, ap);
; 320  : 	fprintf(stderr, ".\n");
; 321  : #endif        
; 322  : }

	pop	esi
	mov	esp, ebp
	pop	ebp
	ret	0
_Win32ErrorHandler ENDP
_TEXT	ENDS
END
