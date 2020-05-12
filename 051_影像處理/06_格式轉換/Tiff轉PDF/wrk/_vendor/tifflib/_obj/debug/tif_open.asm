	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_open.c
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
_typemask DD	00H
	DD	0ffH
	DD	0ffffffffH
	DD	0ffffH
	DD	0ffffffffH
	DD	0ffffffffH
	DD	0ffH
	DD	0ffH
	DD	0ffffH
	DD	0ffffffffH
	DD	0ffffffffH
	DD	0ffffffffH
	DD	0ffffffffH
_bigTypeshift DD 00H
	DD	018H
	DD	00H
	DD	010H
	DD	00H
	DD	00H
	DD	018H
	DD	018H
	DD	010H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
_litTypeshift DD 00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
_?module@?1??TIFFClientOpen@@9@9 DB 'TIFFClientOpen', 00H
CONST	ENDS
PUBLIC	__TIFFgetMode
EXTRN	_TIFFError:NEAR
_DATA	SEGMENT
$SG65816 DB	'"%s": Bad mode', 00H
_DATA	ENDS
_TEXT	SEGMENT
_mode$ = 8
_module$ = 12
_m$ = -4
__TIFFgetMode PROC NEAR

; 102  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 103  : 	int m = -1;

	mov	DWORD PTR _m$[ebp], -1

; 104  : 
; 105  : 	switch (mode[0]) {

	mov	eax, DWORD PTR _mode$[ebp]
	mov	cl, BYTE PTR [eax]
	mov	BYTE PTR -8+[ebp], cl
	cmp	BYTE PTR -8+[ebp], 97			; 00000061H
	je	SHORT $L65813
	cmp	BYTE PTR -8+[ebp], 114			; 00000072H
	je	SHORT $L65811
	cmp	BYTE PTR -8+[ebp], 119			; 00000077H
	je	SHORT $L65813
	jmp	SHORT $L65815
$L65811:

; 106  : 	case 'r':
; 107  : 		m = O_RDONLY;

	mov	DWORD PTR _m$[ebp], 0

; 108  : 		if (mode[1] == '+')

	mov	edx, DWORD PTR _mode$[ebp]
	movsx	eax, BYTE PTR [edx+1]
	cmp	eax, 43					; 0000002bH
	jne	SHORT $L65812

; 109  : 			m = O_RDWR;

	mov	DWORD PTR _m$[ebp], 2
$L65812:

; 110  : 		break;

	jmp	SHORT $L65808
$L65813:

; 111  : 	case 'w':
; 112  : 	case 'a':
; 113  : 		m = O_RDWR|O_CREAT;

	mov	DWORD PTR _m$[ebp], 258			; 00000102H

; 114  : 		if (mode[0] == 'w')

	mov	ecx, DWORD PTR _mode$[ebp]
	movsx	edx, BYTE PTR [ecx]
	cmp	edx, 119				; 00000077H
	jne	SHORT $L65814

; 115  : 			m |= O_TRUNC;

	mov	eax, DWORD PTR _m$[ebp]
	or	ah, 2
	mov	DWORD PTR _m$[ebp], eax
$L65814:

; 116  : 		break;

	jmp	SHORT $L65808
$L65815:

; 117  : 	default:
; 118  : 		TIFFError(module, "\"%s\": Bad mode", mode);

	mov	ecx, DWORD PTR _mode$[ebp]
	push	ecx
	push	OFFSET FLAT:$SG65816
	mov	edx, DWORD PTR _module$[ebp]
	push	edx
	call	_TIFFError
	add	esp, 12					; 0000000cH
$L65808:

; 121  : 	return (m);

	mov	eax, DWORD PTR _m$[ebp]

; 122  : }

	mov	esp, ebp
	pop	ebp
	ret	0
__TIFFgetMode ENDP
_TEXT	ENDS
PUBLIC	_TIFFClientOpen
EXTRN	_TIFFDefaultDirectory:NEAR
EXTRN	__TIFFSetDefaultCompressionState:NEAR
EXTRN	_strcpy:NEAR
EXTRN	__TIFFmalloc:NEAR
EXTRN	__TIFFmemset:NEAR
EXTRN	_strlen:NEAR
EXTRN	_TIFFClose:NEAR
EXTRN	_TIFFReadDirectory:NEAR
EXTRN	_TIFFSwabShort:NEAR
EXTRN	_TIFFSwabLong:NEAR
_DATA	SEGMENT
	ORG $+1
$SG65850 DB	'%s: Out of memory (TIFF structure)', 00H
	ORG $+1
$SG65892 DB	'Cannot read TIFF header', 00H
$SG65902 DB	'Error writing TIFF header', 00H
	ORG $+2
$SG65905 DB	'Not a TIFF file, bad magic number %d (0x%x)', 00H
$SG65908 DB	'Not a TIFF file, bad version number %d (0x%x)', 00H
	ORG $+2
$SG65918 DB	'Can''t open a compressed TIFF file with compression for '
	DB	'update.', 00H
_DATA	ENDS
_TEXT	SEGMENT
_name$ = 8
_mode$ = 12
_clientdata$ = 16
_readproc$ = 20
_writeproc$ = 24
_seekproc$ = 28
_closeproc$ = 32
_sizeproc$ = 36
_mapproc$ = 40
_unmapproc$ = 44
_tif$ = -8
_m$ = -16
_bigendian$ = -12
_cp$ = -4
_u$65862 = -20
_TIFFClientOpen PROC NEAR

; 136  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 32					; 00000020H

; 137  : 	static const char module[] = "TIFFClientOpen";
; 138  : 	TIFF *tif;
; 139  : 	int m, bigendian;
; 140  : 	const char* cp;
; 141  : 
; 142  : 	m = _TIFFgetMode(mode, module);

	push	OFFSET FLAT:_?module@?1??TIFFClientOpen@@9@9
	mov	eax, DWORD PTR _mode$[ebp]
	push	eax
	call	__TIFFgetMode
	add	esp, 8
	mov	DWORD PTR _m$[ebp], eax

; 143  : 	if (m == -1)

	cmp	DWORD PTR _m$[ebp], -1
	jne	SHORT $L65844

; 144  : 		goto bad2;

	jmp	$bad2$65845
$L65844:

; 145  : 	tif = (TIFF *)_TIFFmalloc(sizeof (TIFF) + strlen(name) + 1);

	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	call	_strlen
	add	esp, 4
	add	eax, 553				; 00000229H
	push	eax
	call	__TIFFmalloc
	add	esp, 4
	mov	DWORD PTR _tif$[ebp], eax

; 146  : 	if (tif == NULL) {

	cmp	DWORD PTR _tif$[ebp], 0
	jne	SHORT $L65849

; 147  : 		TIFFError(module, "%s: Out of memory (TIFF structure)", name);

	mov	edx, DWORD PTR _name$[ebp]
	push	edx
	push	OFFSET FLAT:$SG65850
	push	OFFSET FLAT:_?module@?1??TIFFClientOpen@@9@9
	call	_TIFFError
	add	esp, 12					; 0000000cH

; 148  : 		goto bad2;

	jmp	$bad2$65845
$L65849:

; 150  : 	_TIFFmemset(tif, 0, sizeof (*tif));

	push	552					; 00000228H
	push	0
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	__TIFFmemset
	add	esp, 12					; 0000000cH

; 151  : 	tif->tif_name = (char *)tif + sizeof (TIFF);

	mov	ecx, DWORD PTR _tif$[ebp]
	add	ecx, 552				; 00000228H
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx], ecx

; 152  : 	strcpy(tif->tif_name, name);

	mov	eax, DWORD PTR _name$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_strcpy
	add	esp, 8

; 153  : 	tif->tif_mode = m &~ (O_CREAT|O_TRUNC);

	mov	eax, DWORD PTR _m$[ebp]
	and	ah, -4					; fffffffcH
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+8], eax

; 154  : 	tif->tif_curdir = (tdir_t) -1;		/* non-existent directory */

	mov	edx, DWORD PTR _tif$[ebp]
	mov	WORD PTR [edx+360], 65535		; 0000ffffH

; 155  : 	tif->tif_curoff = 0;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+368], 0

; 156  : 	tif->tif_curstrip = (tstrip_t) -1;	/* invalid strip */

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+364], -1

; 157  : 	tif->tif_row = (uint32) -1;		/* read/write pre-increment */

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+356], -1

; 158  : 	tif->tif_clientdata = clientdata;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _clientdata$[ebp]
	mov	DWORD PTR [eax+504], ecx

; 159  : 	tif->tif_readproc = readproc;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _readproc$[ebp]
	mov	DWORD PTR [edx+508], eax

; 160  : 	tif->tif_writeproc = writeproc;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _writeproc$[ebp]
	mov	DWORD PTR [ecx+512], edx

; 161  : 	tif->tif_seekproc = seekproc;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _seekproc$[ebp]
	mov	DWORD PTR [eax+516], ecx

; 162  : 	tif->tif_closeproc = closeproc;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _closeproc$[ebp]
	mov	DWORD PTR [edx+520], eax

; 163  : 	tif->tif_sizeproc = sizeproc;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR _sizeproc$[ebp]
	mov	DWORD PTR [ecx+524], edx

; 164  : 	tif->tif_mapproc = mapproc;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _mapproc$[ebp]
	mov	DWORD PTR [eax+496], ecx

; 165  : 	tif->tif_unmapproc = unmapproc;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR _unmapproc$[ebp]
	mov	DWORD PTR [edx+500], eax

; 166  : 	_TIFFSetDefaultCompressionState(tif);	/* setup default state */

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	__TIFFSetDefaultCompressionState
	add	esp, 4

; 167  : 	/*
; 168  : 	 * Default is to return data MSB2LSB and enable the
; 169  : 	 * use of memory-mapped files and strip chopping when
; 170  : 	 * a file is opened read-only.
; 171  : 	 */
; 172  : 	tif->tif_flags = FILLORDER_MSB2LSB;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], 1

; 173  : 	if (m == O_RDONLY )

	cmp	DWORD PTR _m$[ebp], 0
	jne	SHORT $L65856

; 174  :             tif->tif_flags |= TIFF_MAPPED;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	or	ch, 8
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx
$L65856:

; 175  : 
; 176  : #ifdef STRIPCHOP_DEFAULT
; 177  : 	if (m == O_RDONLY || m == O_RDWR)

	cmp	DWORD PTR _m$[ebp], 0
	je	SHORT $L65858
	cmp	DWORD PTR _m$[ebp], 2
	jne	SHORT $L65857
$L65858:

; 178  : 		tif->tif_flags |= STRIPCHOP_DEFAULT;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	or	ch, -128				; ffffff80H
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx
$L65857:

; 179  : #endif
; 180  : 
; 181  : 	{ union { int32 i; char c[4]; } u; u.i = 1; bigendian = u.c[0] == 0; }

	mov	DWORD PTR _u$65862[ebp], 1
	movsx	eax, BYTE PTR _u$65862[ebp]
	neg	eax
	sbb	eax, eax
	inc	eax
	mov	DWORD PTR _bigendian$[ebp], eax

; 182  : 	/*
; 183  : 	 * Process library-specific flags in the open mode string.
; 184  : 	 * The following flags may be used to control intrinsic library
; 185  : 	 * behaviour that may or may not be desirable (usually for
; 186  : 	 * compatibility with some application that claims to support
; 187  : 	 * TIFF but only supports some braindead idea of what the
; 188  : 	 * vendor thinks TIFF is):
; 189  : 	 *
; 190  : 	 * 'l'		use little-endian byte order for creating a file
; 191  : 	 * 'b'		use big-endian byte order for creating a file
; 192  : 	 * 'L'		read/write information using LSB2MSB bit order
; 193  : 	 * 'B'		read/write information using MSB2LSB bit order
; 194  : 	 * 'H'		read/write information using host bit order
; 195  : 	 * 'M'		enable use of memory-mapped files when supported
; 196  : 	 * 'm'		disable use of memory-mapped files
; 197  : 	 * 'C'		enable strip chopping support when reading
; 198  : 	 * 'c'		disable strip chopping support
; 199  : 	 *
; 200  : 	 * The use of the 'l' and 'b' flags is strongly discouraged.
; 201  : 	 * These flags are provided solely because numerous vendors,
; 202  : 	 * typically on the PC, do not correctly support TIFF; they
; 203  : 	 * only support the Intel little-endian byte order.  This
; 204  : 	 * support is not configured by default because it supports
; 205  : 	 * the violation of the TIFF spec that says that readers *MUST*
; 206  : 	 * support both byte orders.  It is strongly recommended that
; 207  : 	 * you not use this feature except to deal with busted apps
; 208  : 	 * that write invalid TIFF.  And even in those cases you should
; 209  : 	 * bang on the vendors to fix their software.
; 210  : 	 *
; 211  : 	 * The 'L', 'B', and 'H' flags are intended for applications
; 212  : 	 * that can optimize operations on data by using a particular
; 213  : 	 * bit order.  By default the library returns data in MSB2LSB
; 214  : 	 * bit order for compatibiltiy with older versions of this
; 215  : 	 * library.  Returning data in the bit order of the native cpu
; 216  : 	 * makes the most sense but also requires applications to check
; 217  : 	 * the value of the FillOrder tag; something they probabyl do
; 218  : 	 * not do right now.
; 219  : 	 *
; 220  : 	 * The 'M' and 'm' flags are provided because some virtual memory
; 221  : 	 * systems exhibit poor behaviour when large images are mapped.
; 222  : 	 * These options permit clients to control the use of memory-mapped
; 223  : 	 * files on a per-file basis.
; 224  : 	 *
; 225  : 	 * The 'C' and 'c' flags are provided because the library support
; 226  : 	 * for chopping up large strips into multiple smaller strips is not
; 227  : 	 * application-transparent and as such can cause problems.  The 'c'
; 228  : 	 * option permits applications that only want to look at the tags,
; 229  : 	 * for example, to get the unadulterated TIFF tag information.
; 230  : 	 */
; 231  : 	for (cp = mode; *cp; cp++)

	mov	ecx, DWORD PTR _mode$[ebp]
	mov	DWORD PTR _cp$[ebp], ecx
	jmp	SHORT $L65863
$L65864:
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	mov	DWORD PTR _cp$[ebp], edx
$L65863:
	mov	eax, DWORD PTR _cp$[ebp]
	movsx	ecx, BYTE PTR [eax]
	test	ecx, ecx
	je	$L65865

; 232  : 		switch (*cp) {

	mov	edx, DWORD PTR _cp$[ebp]
	movsx	eax, BYTE PTR [edx]
	mov	DWORD PTR -24+[ebp], eax
	mov	ecx, DWORD PTR -24+[ebp]
	sub	ecx, 66					; 00000042H
	mov	DWORD PTR -24+[ebp], ecx
	cmp	DWORD PTR -24+[ebp], 43			; 0000002bH
	ja	$L65867
	mov	eax, DWORD PTR -24+[ebp]
	xor	edx, edx
	mov	dl, BYTE PTR $L65963[eax]
	jmp	DWORD PTR $L65964[edx*4]
$L65870:

; 233  : 		case 'b':
; 234  : 			if ((m&O_CREAT) && !bigendian)

	mov	ecx, DWORD PTR _m$[ebp]
	and	ecx, 256				; 00000100H
	test	ecx, ecx
	je	SHORT $L65871
	cmp	DWORD PTR _bigendian$[ebp], 0
	jne	SHORT $L65871

; 235  : 				tif->tif_flags |= TIFF_SWAB;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	or	al, -128				; ffffff80H
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+12], eax
$L65871:

; 236  : 			break;

	jmp	$L65867
$L65872:

; 237  : 		case 'l':
; 238  : 			if ((m&O_CREAT) && bigendian)

	mov	edx, DWORD PTR _m$[ebp]
	and	edx, 256				; 00000100H
	test	edx, edx
	je	SHORT $L65873
	cmp	DWORD PTR _bigendian$[ebp], 0
	je	SHORT $L65873

; 239  : 				tif->tif_flags |= TIFF_SWAB;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	or	cl, -128				; ffffff80H
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx
$L65873:

; 240  : 			break;

	jmp	$L65867
$L65874:

; 241  : 		case 'B':
; 242  : 			tif->tif_flags = (tif->tif_flags &~ TIFF_FILLORDER) |
; 243  : 			    FILLORDER_MSB2LSB;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, -4					; fffffffcH
	or	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx

; 244  : 			break;

	jmp	$L65867
$L65875:

; 245  : 		case 'L':
; 246  : 			tif->tif_flags = (tif->tif_flags &~ TIFF_FILLORDER) |
; 247  : 			    FILLORDER_LSB2MSB;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, -4					; fffffffcH
	or	ecx, 2
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx

; 248  : 			break;

	jmp	SHORT $L65867
$L65876:

; 249  : 		case 'H':
; 250  : 			tif->tif_flags = (tif->tif_flags &~ TIFF_FILLORDER) |
; 251  : 			    HOST_FILLORDER;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, -4					; fffffffcH
	or	ecx, 1
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx

; 252  : 			break;

	jmp	SHORT $L65867
$L65877:

; 253  : 		case 'M':
; 254  : 			if (m == O_RDONLY)

	cmp	DWORD PTR _m$[ebp], 0
	jne	SHORT $L65878

; 255  : 				tif->tif_flags |= TIFF_MAPPED;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	or	ch, 8
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx
$L65878:

; 256  : 			break;

	jmp	SHORT $L65867
$L65879:

; 257  : 		case 'm':
; 258  : 			if (m == O_RDONLY)

	cmp	DWORD PTR _m$[ebp], 0
	jne	SHORT $L65880

; 259  : 				tif->tif_flags &= ~TIFF_MAPPED;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ch, -9					; fffffff7H
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx
$L65880:

; 260  : 			break;

	jmp	SHORT $L65867
$L65881:

; 261  : 		case 'C':
; 262  : 			if (m == O_RDONLY)

	cmp	DWORD PTR _m$[ebp], 0
	jne	SHORT $L65882

; 263  : 				tif->tif_flags |= TIFF_STRIPCHOP;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	or	ch, -128				; ffffff80H
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx
$L65882:

; 264  : 			break;

	jmp	SHORT $L65867
$L65883:

; 265  : 		case 'c':
; 266  : 			if (m == O_RDONLY)

	cmp	DWORD PTR _m$[ebp], 0
	jne	SHORT $L65884

; 267  : 				tif->tif_flags &= ~TIFF_STRIPCHOP;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ch, 127					; 0000007fH
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx
$L65884:
$L65867:

; 268  : 			break;
; 269  : 		}

	jmp	$L65864
$L65865:

; 270  : 	/*
; 271  : 	 * Read in TIFF header.
; 272  : 	 */
; 273  : 	if (!ReadOK(tif, &tif->tif_header, sizeof (TIFFHeader))) {

	push	8
	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 336				; 00000150H
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+508]
	add	esp, 12					; 0000000cH
	cmp	eax, 8
	je	$L65890

; 274  : 		if (tif->tif_mode == O_RDONLY) {

	mov	ecx, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [ecx+8], 0
	jne	SHORT $L65891

; 275  : 			TIFFError(name, "Cannot read TIFF header");

	push	OFFSET FLAT:$SG65892
	mov	edx, DWORD PTR _name$[ebp]
	push	edx
	call	_TIFFError
	add	esp, 8

; 276  : 			goto bad;

	jmp	$bad$65893
$L65891:

; 278  : 		/*
; 279  : 		 * Setup header and write.
; 280  : 		 */
; 281  : 		tif->tif_header.tiff_magic = tif->tif_flags & TIFF_SWAB
; 282  : 		    ? (bigendian ? TIFF_LITTLEENDIAN : TIFF_BIGENDIAN)
; 283  : 		    : (bigendian ? TIFF_BIGENDIAN : TIFF_LITTLEENDIAN);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 128				; 00000080H
	test	ecx, ecx
	je	SHORT $L65961
	mov	edx, DWORD PTR _bigendian$[ebp]
	neg	edx
	sbb	edx, edx
	and	edx, -1028				; fffffbfcH
	add	edx, 19789				; 00004d4dH
	mov	DWORD PTR -28+[ebp], edx
	jmp	SHORT $L65962
$L65961:
	mov	eax, DWORD PTR _bigendian$[ebp]
	neg	eax
	sbb	eax, eax
	and	eax, 1028				; 00000404H
	add	eax, 18761				; 00004949H
	mov	DWORD PTR -28+[ebp], eax
$L65962:
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	dx, WORD PTR -28+[ebp]
	mov	WORD PTR [ecx+336], dx

; 284  : 		tif->tif_header.tiff_version = TIFF_VERSION;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	WORD PTR [eax+338], 42			; 0000002aH

; 285  : 		if (tif->tif_flags & TIFF_SWAB)

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	edx, 128				; 00000080H
	test	edx, edx
	je	SHORT $L65894

; 286  : 			TIFFSwabShort(&tif->tif_header.tiff_version);

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 338				; 00000152H
	push	eax
	call	_TIFFSwabShort
	add	esp, 4
$L65894:

; 287  : 		tif->tif_header.tiff_diroff = 0;	/* filled in later */

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+340], 0

; 288  : 
; 289  :                 /*
; 290  :                  * This seek shouldn't be necessary, but I have had some
; 291  :                  * crazy problems with a failed fseek() on Solaris leaving
; 292  :                  * the current file pointer out of whack when an fwrite()
; 293  :                  * is done. 
; 294  :                  */
; 295  :                 TIFFSeekFile( tif, 0, SEEK_SET );

	push	0
	push	0
	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+504]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+516]
	add	esp, 12					; 0000000cH

; 296  : 
; 297  : 		if (!WriteOK(tif, &tif->tif_header, sizeof (TIFFHeader))) {

	push	8
	mov	edx, DWORD PTR _tif$[ebp]
	add	edx, 336				; 00000150H
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+504]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [edx+512]
	add	esp, 12					; 0000000cH
	cmp	eax, 8
	je	SHORT $L65901

; 298  : 			TIFFError(name, "Error writing TIFF header");

	push	OFFSET FLAT:$SG65902
	mov	eax, DWORD PTR _name$[ebp]
	push	eax
	call	_TIFFError
	add	esp, 8

; 299  : 			goto bad;

	jmp	$bad$65893
$L65901:

; 301  : 		/*
; 302  : 		 * Setup the byte order handling.
; 303  : 		 */
; 304  : 		TIFFInitOrder(tif, tif->tif_header.tiff_magic, bigendian);

	mov	ecx, DWORD PTR _bigendian$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+336]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFInitOrder
	add	esp, 12					; 0000000cH

; 305  : 		/*
; 306  : 		 * Setup default directory.
; 307  : 		 */
; 308  : 		if (!TIFFDefaultDirectory(tif))

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFDefaultDirectory
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65903

; 309  : 			goto bad;

	jmp	$bad$65893
$L65903:

; 310  : 		tif->tif_diroff = 0;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+16], 0

; 311  : 		return (tif);

	mov	eax, DWORD PTR _tif$[ebp]
	jmp	$L65837
$L65890:

; 313  : 	/*
; 314  : 	 * Setup the byte order handling.
; 315  : 	 */
; 316  : 	if (tif->tif_header.tiff_magic != TIFF_BIGENDIAN &&
; 317  : 	    tif->tif_header.tiff_magic != TIFF_LITTLEENDIAN) {

	mov	ecx, DWORD PTR _tif$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+336]
	cmp	edx, 19789				; 00004d4dH
	je	SHORT $L65904
	mov	eax, DWORD PTR _tif$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+336]
	cmp	ecx, 18761				; 00004949H
	je	SHORT $L65904

; 318  : 		TIFFError(name,  "Not a TIFF file, bad magic number %d (0x%x)",
; 319  : 		    tif->tif_header.tiff_magic,
; 320  : 		    tif->tif_header.tiff_magic);

	mov	edx, DWORD PTR _tif$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+336]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+336]
	push	edx
	push	OFFSET FLAT:$SG65905
	mov	eax, DWORD PTR _name$[ebp]
	push	eax
	call	_TIFFError
	add	esp, 16					; 00000010H

; 321  : 		goto bad;

	jmp	$bad$65893
$L65904:

; 323  : 	TIFFInitOrder(tif, tif->tif_header.tiff_magic, bigendian);

	mov	ecx, DWORD PTR _bigendian$[ebp]
	push	ecx
	mov	edx, DWORD PTR _tif$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+336]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFInitOrder
	add	esp, 12					; 0000000cH

; 324  : 	/*
; 325  : 	 * Swap header if required.
; 326  : 	 */
; 327  : 	if (tif->tif_flags & TIFF_SWAB) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 128				; 00000080H
	test	eax, eax
	je	SHORT $L65906

; 328  : 		TIFFSwabShort(&tif->tif_header.tiff_version);

	mov	ecx, DWORD PTR _tif$[ebp]
	add	ecx, 338				; 00000152H
	push	ecx
	call	_TIFFSwabShort
	add	esp, 4

; 329  : 		TIFFSwabLong(&tif->tif_header.tiff_diroff);

	mov	edx, DWORD PTR _tif$[ebp]
	add	edx, 340				; 00000154H
	push	edx
	call	_TIFFSwabLong
	add	esp, 4
$L65906:

; 331  : 	/*
; 332  : 	 * Now check version (if needed, it's been byte-swapped).
; 333  : 	 * Note that this isn't actually a version number, it's a
; 334  : 	 * magic number that doesn't change (stupid).
; 335  : 	 */
; 336  : 	if (tif->tif_header.tiff_version != TIFF_VERSION) {

	mov	eax, DWORD PTR _tif$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+338]
	cmp	ecx, 42					; 0000002aH
	je	SHORT $L65907

; 337  : 		TIFFError(name,
; 338  : 		    "Not a TIFF file, bad version number %d (0x%x)",
; 339  : 		    tif->tif_header.tiff_version,
; 340  : 		    tif->tif_header.tiff_version); 

	mov	edx, DWORD PTR _tif$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+338]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+338]
	push	edx
	push	OFFSET FLAT:$SG65908
	mov	eax, DWORD PTR _name$[ebp]
	push	eax
	call	_TIFFError
	add	esp, 16					; 00000010H

; 341  : 		goto bad;

	jmp	$bad$65893
$L65907:

; 343  : 	tif->tif_flags |= TIFF_MYBUFFER;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	or	dh, 2
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+12], edx

; 344  : 	tif->tif_rawcp = tif->tif_rawdata = 0;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+472], 0
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+480], 0

; 345  : 	tif->tif_rawdatasize = 0;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+476], 0

; 346  : 	/*
; 347  : 	 * Setup initial directory.
; 348  : 	 */
; 349  : 	switch (mode[0]) {

	mov	ecx, DWORD PTR _mode$[ebp]
	mov	dl, BYTE PTR [ecx]
	mov	BYTE PTR -32+[ebp], dl
	cmp	BYTE PTR -32+[ebp], 97			; 00000061H
	je	$L65919
	cmp	BYTE PTR -32+[ebp], 114			; 00000072H
	je	SHORT $L65913
	jmp	$bad$65893
$L65913:

; 350  : 	case 'r':
; 351  : 		tif->tif_nextdiroff = tif->tif_header.tiff_diroff;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+340]
	mov	DWORD PTR [eax+20], edx

; 352  : 		/*
; 353  : 		 * Try to use a memory-mapped file if the client
; 354  : 		 * has not explicitly suppressed usage with the
; 355  : 		 * 'm' flag in the open mode (see above).
; 356  : 		 */
; 357  : 		if ((tif->tif_flags & TIFF_MAPPED) &&
; 358  : 	!TIFFMapFileContents(tif, (tdata_t*) &tif->tif_base, &tif->tif_size))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	and	ecx, 2048				; 00000800H
	test	ecx, ecx
	je	SHORT $L65915
	mov	edx, DWORD PTR _tif$[ebp]
	add	edx, 492				; 000001ecH
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 488				; 000001e8H
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+504]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	call	DWORD PTR [eax+496]
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L65915

; 359  : 			tif->tif_flags &= ~TIFF_MAPPED;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	and	dh, -9					; fffffff7H
	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+12], edx
$L65915:

; 360  : 		if (TIFFReadDirectory(tif)) {

	mov	ecx, DWORD PTR _tif$[ebp]
	push	ecx
	call	_TIFFReadDirectory
	add	esp, 4
	test	eax, eax
	je	SHORT $L65916

; 361  :                         if( m != O_RDONLY 
; 362  :                           && tif->tif_dir.td_compression != COMPRESSION_NONE )

	cmp	DWORD PTR _m$[ebp], 0
	je	SHORT $L65917
	mov	edx, DWORD PTR _tif$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+68]
	cmp	eax, 1
	je	SHORT $L65917

; 364  :                             TIFFError( name, 
; 365  :                                        "Can't open a compressed TIFF file"
; 366  :                                        " with compression for update." );

	push	OFFSET FLAT:$SG65918
	mov	ecx, DWORD PTR _name$[ebp]
	push	ecx
	call	_TIFFError
	add	esp, 8

; 367  :                             goto bad;

	jmp	SHORT $bad$65893
$L65917:

; 369  : 			tif->tif_rawcc = -1;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+484], -1

; 370  : 			tif->tif_flags |= TIFF_BUFFERSETUP;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	or	ecx, 16					; 00000010H
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx

; 371  : 			return (tif);

	mov	eax, DWORD PTR _tif$[ebp]
	jmp	SHORT $L65837
$L65916:

; 373  : 		break;

	jmp	SHORT $bad$65893
$L65919:

; 374  : 	case 'a':
; 375  : 		/*
; 376  : 		 * New directories are automatically append
; 377  : 		 * to the end of the directory chain when they
; 378  : 		 * are written out (see TIFFWriteDirectory).
; 379  : 		 */
; 380  : 		if (!TIFFDefaultDirectory(tif))

	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	call	_TIFFDefaultDirectory
	add	esp, 4
	test	eax, eax
	jne	SHORT $L65920

; 381  : 			goto bad;

	jmp	SHORT $bad$65893
$L65920:

; 382  : 		return (tif);

	mov	eax, DWORD PTR _tif$[ebp]
	jmp	SHORT $L65837
$bad$65893:

; 384  : bad:
; 385  : 	tif->tif_mode = O_RDONLY;	/* XXX avoid flush */

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+8], 0

; 386  : 	TIFFClose(tif);

	mov	edx, DWORD PTR _tif$[ebp]
	push	edx
	call	_TIFFClose
	add	esp, 4

; 387  : 	return ((TIFF*)0);

	xor	eax, eax
	jmp	SHORT $L65837
$bad2$65845:

; 388  : bad2:
; 389  : 	(void) (*closeproc)(clientdata);

	mov	eax, DWORD PTR _clientdata$[ebp]
	push	eax
	call	DWORD PTR _closeproc$[ebp]
	add	esp, 4

; 390  : 	return ((TIFF*)0);

	xor	eax, eax
$L65837:

; 391  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L65964:
	DD	$L65874
	DD	$L65881
	DD	$L65876
	DD	$L65875
	DD	$L65877
	DD	$L65870
	DD	$L65883
	DD	$L65872
	DD	$L65879
	DD	$L65867
$L65963:
	DB	0
	DB	1
	DB	9
	DB	9
	DB	9
	DB	9
	DB	2
	DB	9
	DB	9
	DB	9
	DB	3
	DB	4
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	5
	DB	6
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	9
	DB	7
	DB	8
_TIFFClientOpen ENDP
_tif$ = 8
_magic$ = 12
_bigendian$ = 16
_TIFFInitOrder PROC NEAR

; 87   : {

	push	ebp
	mov	ebp, esp

; 88   : 	tif->tif_typemask = typemask;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [eax+352], OFFSET FLAT:_typemask

; 89   : 	if (magic == TIFF_BIGENDIAN) {

	cmp	DWORD PTR _magic$[ebp], 19789		; 00004d4dH
	jne	SHORT $L65797

; 90   : 		tif->tif_typeshift = bigTypeshift;

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+348], OFFSET FLAT:_bigTypeshift

; 91   : 		if (!bigendian)

	cmp	DWORD PTR _bigendian$[ebp], 0
	jne	SHORT $L65798

; 92   : 			tif->tif_flags |= TIFF_SWAB;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	or	al, -128				; ffffff80H
	mov	ecx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [ecx+12], eax
$L65798:

; 93   : 	} else {

	jmp	SHORT $L65800
$L65797:

; 94   : 		tif->tif_typeshift = litTypeshift;

	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+348], OFFSET FLAT:_litTypeshift

; 95   : 		if (bigendian)

	cmp	DWORD PTR _bigendian$[ebp], 0
	je	SHORT $L65800

; 96   : 			tif->tif_flags |= TIFF_SWAB;

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+12]
	or	cl, -128				; ffffff80H
	mov	edx, DWORD PTR _tif$[ebp]
	mov	DWORD PTR [edx+12], ecx
$L65800:

; 98   : }

	pop	ebp
	ret	0
_TIFFInitOrder ENDP
_TEXT	ENDS
PUBLIC	_TIFFFileName
_TEXT	SEGMENT
_tif$ = 8
_TIFFFileName PROC NEAR

; 402  : {

	push	ebp
	mov	ebp, esp

; 403  : 	return (tif->tif_name);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [eax]

; 404  : }

	pop	ebp
	ret	0
_TIFFFileName ENDP
_TEXT	ENDS
PUBLIC	_TIFFFileno
_TEXT	SEGMENT
_tif$ = 8
_TIFFFileno PROC NEAR

; 411  : {

	push	ebp
	mov	ebp, esp

; 412  : 	return (tif->tif_fd);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [eax+4]

; 413  : }

	pop	ebp
	ret	0
_TIFFFileno ENDP
_TEXT	ENDS
PUBLIC	_TIFFGetMode
_TEXT	SEGMENT
_tif$ = 8
_TIFFGetMode PROC NEAR

; 420  : {

	push	ebp
	mov	ebp, esp

; 421  : 	return (tif->tif_mode);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [eax+8]

; 422  : }

	pop	ebp
	ret	0
_TIFFGetMode ENDP
_TEXT	ENDS
PUBLIC	_TIFFIsTiled
_TEXT	SEGMENT
_tif$ = 8
_TIFFIsTiled PROC NEAR

; 430  : {

	push	ebp
	mov	ebp, esp

; 431  : 	return (isTiled(tif));

	mov	eax, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [eax+12]
	and	eax, 1024				; 00000400H
	neg	eax
	sbb	eax, eax
	neg	eax

; 432  : }

	pop	ebp
	ret	0
_TIFFIsTiled ENDP
_TEXT	ENDS
PUBLIC	_TIFFCurrentRow
_TEXT	SEGMENT
_tif$ = 8
_TIFFCurrentRow PROC NEAR

; 439  : {

	push	ebp
	mov	ebp, esp

; 440  : 	return (tif->tif_row);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [eax+356]

; 441  : }

	pop	ebp
	ret	0
_TIFFCurrentRow ENDP
_TEXT	ENDS
PUBLIC	_TIFFCurrentDirectory
_TEXT	SEGMENT
_tif$ = 8
_TIFFCurrentDirectory PROC NEAR

; 448  : {

	push	ebp
	mov	ebp, esp

; 449  : 	return (tif->tif_curdir);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ax, WORD PTR [eax+360]

; 450  : }

	pop	ebp
	ret	0
_TIFFCurrentDirectory ENDP
_TEXT	ENDS
PUBLIC	_TIFFCurrentStrip
_TEXT	SEGMENT
_tif$ = 8
_TIFFCurrentStrip PROC NEAR

; 457  : {

	push	ebp
	mov	ebp, esp

; 458  : 	return (tif->tif_curstrip);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [eax+364]

; 459  : }

	pop	ebp
	ret	0
_TIFFCurrentStrip ENDP
_TEXT	ENDS
PUBLIC	_TIFFCurrentTile
_TEXT	SEGMENT
_tif$ = 8
_TIFFCurrentTile PROC NEAR

; 466  : {

	push	ebp
	mov	ebp, esp

; 467  : 	return (tif->tif_curtile);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [eax+388]

; 468  : }

	pop	ebp
	ret	0
_TIFFCurrentTile ENDP
_TEXT	ENDS
PUBLIC	_TIFFIsByteSwapped
_TEXT	SEGMENT
_tif$ = 8
_TIFFIsByteSwapped PROC NEAR

; 475  : {

	push	ebp
	mov	ebp, esp

; 476  : 	return ((tif->tif_flags & TIFF_SWAB) != 0);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [eax+12]
	and	eax, 128				; 00000080H
	neg	eax
	sbb	eax, eax
	neg	eax

; 477  : }

	pop	ebp
	ret	0
_TIFFIsByteSwapped ENDP
_TEXT	ENDS
PUBLIC	_TIFFIsUpSampled
_TEXT	SEGMENT
_tif$ = 8
_TIFFIsUpSampled PROC NEAR

; 484  : {

	push	ebp
	mov	ebp, esp

; 485  : 	return (isUpSampled(tif));

	mov	eax, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [eax+12]
	and	eax, 16384				; 00004000H
	neg	eax
	sbb	eax, eax
	neg	eax

; 486  : }

	pop	ebp
	ret	0
_TIFFIsUpSampled ENDP
_TEXT	ENDS
PUBLIC	_TIFFIsMSB2LSB
_TEXT	SEGMENT
_tif$ = 8
_TIFFIsMSB2LSB PROC NEAR

; 493  : {

	push	ebp
	mov	ebp, esp

; 494  : 	return (isFillOrder(tif, FILLORDER_MSB2LSB));

	mov	eax, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [eax+12]
	and	eax, 1
	neg	eax
	sbb	eax, eax
	neg	eax

; 495  : }

	pop	ebp
	ret	0
_TIFFIsMSB2LSB ENDP
_TEXT	ENDS
END
