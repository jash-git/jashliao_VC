	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\mkversion.c
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
PUBLIC	_main
EXTRN	__iob:BYTE
EXTRN	_fclose:NEAR
EXTRN	_fgets:NEAR
EXTRN	_fopen:NEAR
EXTRN	_fprintf:NEAR
EXTRN	_sprintf:NEAR
EXTRN	_exit:NEAR
EXTRN	_strcmp:NEAR
EXTRN	_strchr:NEAR
_DATA	SEGMENT
$SG1015	DB	'../VERSION', 00H
	ORG $+1
$SG1017	DB	'../RELEASE-DATE', 00H
$SG1019	DB	'../dist/tiff.alpha', 00H
	ORG $+1
$SG1030	DB	'-v', 00H
	ORG $+1
$SG1034	DB	'-a', 00H
	ORG $+1
$SG1038	DB	'-r', 00H
	ORG $+1
$SG1043	DB	'mkversion: No version information in %s.', 0aH, 00H
	ORG $+2
$SG1047	DB	'mkversion: No alpha information in %s.', 0aH, 00H
$SG1056	DB	'mkversion: Malformed alpha information in %s.', 0aH, 00H
	ORG $+1
$SG1059	DB	'mkversion: No release date information in %s.', 0aH, 00H
	ORG $+1
$SG1060	DB	'#define TIFFLIB_VERSION %4.4s%2.2s%2.2s', 00H
$SG1062	DB	'w', 00H
	ORG $+2
$SG1065	DB	'mkversion: %s: Could not open for writing.', 0aH, 00H
$SG1067	DB	'#define TIFFLIB_VERSION_STR "LIBTIFF, Version %s\n', 00H
	ORG $+1
$SG1068	DB	'Copyright (c) 1988-1996 Sam Leffler\n', 00H
	ORG $+2
$SG1069	DB	'Copyright (c) 1991-1996 Silicon Graphics, Inc."', 0aH, 00H
	ORG $+3
$SG1070	DB	'/*', 0aH, ' * This define can be used in code that requi'
	DB	'res', 0aH, ' * compilation-related definitions specific to a', 0aH
	DB	' * version or versions of the library.  Runtime', 0aH, ' * ve'
	DB	'rsion checking should be done based on the', 0aH, ' * string '
	DB	'returned by TIFFGetVersion.', 0aH, ' */', 0aH, 00H
$SG1071	DB	'%s', 0aH, 00H
_DATA	ENDS
_TEXT	SEGMENT
_fd$ = -136
_cp$ = -132
_tp$1050 = -536
_argc$ = 8
_argv$ = 12
_versionFile$ = -272
_releaseDateFile$ = -140
_alphaFile$ = -404
_version$ = -268
_rawReleaseDate$ = -532
_tiffLibVersion$ = -400
_alpha$ = -128
_main	PROC NEAR

; 63   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 536				; 00000218H

; 64   :     char* versionFile = "../VERSION";

	mov	DWORD PTR _versionFile$[ebp], OFFSET FLAT:$SG1015

; 65   :     char* releaseDateFile = "../RELEASE-DATE";

	mov	DWORD PTR _releaseDateFile$[ebp], OFFSET FLAT:$SG1017

; 66   :     char* alphaFile = "../dist/tiff.alpha";

	mov	DWORD PTR _alphaFile$[ebp], OFFSET FLAT:$SG1019

; 67   :     char version[128];
; 68   :     char rawReleaseDate[128];
; 69   :     char tiffLibVersion[128];
; 70   :     char alpha[128];
; 71   :     FILE* fd;
; 72   :     char* cp;
; 73   : 
; 74   :     argc--, argv++;

	mov	eax, DWORD PTR _argc$[ebp]
	sub	eax, 1
	mov	DWORD PTR _argc$[ebp], eax
	mov	ecx, DWORD PTR _argv$[ebp]
	add	ecx, 4
	mov	DWORD PTR _argv$[ebp], ecx
$L1027:

; 75   :     while (argc > 0 && argv[0][0] == '-') {

	cmp	DWORD PTR _argc$[ebp], 0
	jle	$L1028
	mov	edx, DWORD PTR _argv$[ebp]
	mov	eax, DWORD PTR [edx]
	movsx	ecx, BYTE PTR [eax]
	cmp	ecx, 45					; 0000002dH
	jne	$L1028

; 76   : 	if (strcmp(argv[0], "-v") == 0) {

	push	OFFSET FLAT:$SG1030
	mov	edx, DWORD PTR _argv$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_strcmp
	add	esp, 8
	test	eax, eax
	jne	SHORT $L1029

; 77   : 	    if (argc < 1)

	cmp	DWORD PTR _argc$[ebp], 1
	jge	SHORT $L1031

; 78   : 		usage();

	call	_usage
$L1031:

; 79   : 	    argc--, argv++;

	mov	ecx, DWORD PTR _argc$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _argc$[ebp], ecx
	mov	edx, DWORD PTR _argv$[ebp]
	add	edx, 4
	mov	DWORD PTR _argv$[ebp], edx

; 80   : 	    versionFile = argv[0];

	mov	eax, DWORD PTR _argv$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _versionFile$[ebp], ecx

; 81   : 	} else if (strcmp(argv[0], "-a") == 0) {

	jmp	$L1040
$L1029:
	push	OFFSET FLAT:$SG1034
	mov	edx, DWORD PTR _argv$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_strcmp
	add	esp, 8
	test	eax, eax
	jne	SHORT $L1033

; 82   : 	    if (argc < 1)

	cmp	DWORD PTR _argc$[ebp], 1
	jge	SHORT $L1035

; 83   : 		usage();

	call	_usage
$L1035:

; 84   : 	    argc--, argv++;

	mov	ecx, DWORD PTR _argc$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _argc$[ebp], ecx
	mov	edx, DWORD PTR _argv$[ebp]
	add	edx, 4
	mov	DWORD PTR _argv$[ebp], edx

; 85   : 	    alphaFile = argv[0];

	mov	eax, DWORD PTR _argv$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _alphaFile$[ebp], ecx

; 86   : 	} else if (strcmp(argv[0], "-r") == 0) {

	jmp	SHORT $L1040
$L1033:
	push	OFFSET FLAT:$SG1038
	mov	edx, DWORD PTR _argv$[ebp]
	mov	eax, DWORD PTR [edx]
	push	eax
	call	_strcmp
	add	esp, 8
	test	eax, eax
	jne	SHORT $L1037

; 87   : 	    if (argc < 1)

	cmp	DWORD PTR _argc$[ebp], 1
	jge	SHORT $L1039

; 88   : 		usage();

	call	_usage
$L1039:

; 89   : 	    argc--, argv++;

	mov	ecx, DWORD PTR _argc$[ebp]
	sub	ecx, 1
	mov	DWORD PTR _argc$[ebp], ecx
	mov	edx, DWORD PTR _argv$[ebp]
	add	edx, 4
	mov	DWORD PTR _argv$[ebp], edx

; 90   : 	    releaseDateFile = argv[0];

	mov	eax, DWORD PTR _argv$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _releaseDateFile$[ebp], ecx

; 91   : 	} else

	jmp	SHORT $L1040
$L1037:

; 92   : 	    usage();

	call	_usage
$L1040:

; 93   : 	argc--, argv++;

	mov	edx, DWORD PTR _argc$[ebp]
	sub	edx, 1
	mov	DWORD PTR _argc$[ebp], edx
	mov	eax, DWORD PTR _argv$[ebp]
	add	eax, 4
	mov	DWORD PTR _argv$[ebp], eax

; 94   :     }

	jmp	$L1027
$L1028:

; 95   : 
; 96   :     /*
; 97   :      * Read the VERSION file.
; 98   :      */
; 99   :     fd = openFile(versionFile);

	mov	ecx, DWORD PTR _versionFile$[ebp]
	push	ecx
	call	_openFile
	add	esp, 4
	mov	DWORD PTR _fd$[ebp], eax

; 100  :     if (fgets(version, sizeof (version)-1, fd) == NULL) {

	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	push	127					; 0000007fH
	lea	eax, DWORD PTR _version$[ebp]
	push	eax
	call	_fgets
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L1042

; 101  : 	fprintf(stderr, "mkversion: No version information in %s.\n",
; 102  : 	    versionFile);

	mov	ecx, DWORD PTR _versionFile$[ebp]
	push	ecx
	push	OFFSET FLAT:$SG1043
	push	OFFSET FLAT:__iob+64
	call	_fprintf
	add	esp, 12					; 0000000cH

; 103  : 	exit(-1);

	push	-1
	call	_exit
$L1042:

; 105  :     cp = strchr(version, '\n');

	push	10					; 0000000aH
	lea	edx, DWORD PTR _version$[ebp]
	push	edx
	call	_strchr
	add	esp, 8
	mov	DWORD PTR _cp$[ebp], eax

; 106  :     if (cp)

	cmp	DWORD PTR _cp$[ebp], 0
	je	SHORT $L1044

; 107  : 	*cp = '\0';

	mov	eax, DWORD PTR _cp$[ebp]
	mov	BYTE PTR [eax], 0
$L1044:

; 108  :     fclose(fd);

	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fclose
	add	esp, 4

; 109  :     fd = openFile(alphaFile);

	mov	edx, DWORD PTR _alphaFile$[ebp]
	push	edx
	call	_openFile
	add	esp, 4
	mov	DWORD PTR _fd$[ebp], eax

; 110  :     if (fgets(alpha, sizeof (alpha)-1, fd) == NULL) {

	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	push	127					; 0000007fH
	lea	ecx, DWORD PTR _alpha$[ebp]
	push	ecx
	call	_fgets
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L1046

; 111  : 	fprintf(stderr, "mkversion: No alpha information in %s.\n", alphaFile);

	mov	edx, DWORD PTR _alphaFile$[ebp]
	push	edx
	push	OFFSET FLAT:$SG1047
	push	OFFSET FLAT:__iob+64
	call	_fprintf
	add	esp, 12					; 0000000cH

; 112  : 	exit(-1);

	push	-1
	call	_exit
$L1046:

; 114  :     fclose(fd);

	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fclose
	add	esp, 4

; 115  :     cp = strchr(alpha, ' ');		/* skip to 3rd blank-separated field */

	push	32					; 00000020H
	lea	ecx, DWORD PTR _alpha$[ebp]
	push	ecx
	call	_strchr
	add	esp, 8
	mov	DWORD PTR _cp$[ebp], eax

; 116  :     if (cp)

	cmp	DWORD PTR _cp$[ebp], 0
	je	SHORT $L1048

; 117  : 	cp = strchr(cp+1, ' ');

	push	32					; 00000020H
	mov	edx, DWORD PTR _cp$[ebp]
	add	edx, 1
	push	edx
	call	_strchr
	add	esp, 8
	mov	DWORD PTR _cp$[ebp], eax
$L1048:

; 118  :     if (cp) {				/* append alpha to version */

	cmp	DWORD PTR _cp$[ebp], 0
	je	$L1049

; 119  : 	char* tp;
; 120  : 	for (tp = strchr(version, '\0'), cp++; (*tp = *cp) != 0; tp++, cp++)

	push	0
	lea	eax, DWORD PTR _version$[ebp]
	push	eax
	call	_strchr
	add	esp, 8
	mov	DWORD PTR _tp$1050[ebp], eax
	mov	ecx, DWORD PTR _cp$[ebp]
	add	ecx, 1
	mov	DWORD PTR _cp$[ebp], ecx
	jmp	SHORT $L1051
$L1052:
	mov	edx, DWORD PTR _tp$1050[ebp]
	add	edx, 1
	mov	DWORD PTR _tp$1050[ebp], edx
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 1
	mov	DWORD PTR _cp$[ebp], eax
$L1051:
	mov	ecx, DWORD PTR _tp$1050[ebp]
	mov	edx, DWORD PTR _cp$[ebp]
	mov	al, BYTE PTR [edx]
	mov	BYTE PTR [ecx], al
	mov	ecx, DWORD PTR _tp$1050[ebp]
	movsx	edx, BYTE PTR [ecx]
	test	edx, edx
	je	SHORT $L1053

; 121  : 	    ;

	jmp	SHORT $L1052
$L1053:

; 122  : 	if (tp[-1] == '\n')

	mov	eax, DWORD PTR _tp$1050[ebp]
	movsx	ecx, BYTE PTR [eax-1]
	cmp	ecx, 10					; 0000000aH
	jne	SHORT $L1054

; 123  : 	    tp[-1] = '\0';

	mov	edx, DWORD PTR _tp$1050[ebp]
	mov	BYTE PTR [edx-1], 0
$L1054:

; 124  :     } else {

	jmp	SHORT $L1055
$L1049:

; 125  : 	fprintf(stderr, "mkversion: Malformed alpha information in %s.\n",
; 126  : 	    alphaFile);

	mov	eax, DWORD PTR _alphaFile$[ebp]
	push	eax
	push	OFFSET FLAT:$SG1056
	push	OFFSET FLAT:__iob+64
	call	_fprintf
	add	esp, 12					; 0000000cH

; 127  : 	exit(-1);

	push	-1
	call	_exit
$L1055:

; 129  : 
; 130  :     /*
; 131  :      * Read the RELEASE-DATE, and translate format to emit TIFFLIB_VERSION.
; 132  :      */
; 133  :     fd = openFile(releaseDateFile);

	mov	ecx, DWORD PTR _releaseDateFile$[ebp]
	push	ecx
	call	_openFile
	add	esp, 4
	mov	DWORD PTR _fd$[ebp], eax

; 134  :     if (fgets(rawReleaseDate, sizeof (version)-1, fd) == NULL) {

	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	push	127					; 0000007fH
	lea	eax, DWORD PTR _rawReleaseDate$[ebp]
	push	eax
	call	_fgets
	add	esp, 12					; 0000000cH
	test	eax, eax
	jne	SHORT $L1058

; 135  : 	fprintf(stderr, "mkversion: No release date information in %s.\n",
; 136  :                 releaseDateFile);

	mov	ecx, DWORD PTR _releaseDateFile$[ebp]
	push	ecx
	push	OFFSET FLAT:$SG1059
	push	OFFSET FLAT:__iob+64
	call	_fprintf
	add	esp, 12					; 0000000cH

; 137  : 	exit(-1);

	push	-1
	call	_exit
$L1058:

; 139  :     fclose(fd);

	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fclose
	add	esp, 4

; 140  : 
; 141  :     sprintf( tiffLibVersion, "#define TIFFLIB_VERSION %4.4s%2.2s%2.2s",
; 142  :              rawReleaseDate+6, 
; 143  :              rawReleaseDate+0,
; 144  :              rawReleaseDate+3 );

	lea	eax, DWORD PTR _rawReleaseDate$[ebp+3]
	push	eax
	lea	ecx, DWORD PTR _rawReleaseDate$[ebp]
	push	ecx
	lea	edx, DWORD PTR _rawReleaseDate$[ebp+6]
	push	edx
	push	OFFSET FLAT:$SG1060
	lea	eax, DWORD PTR _tiffLibVersion$[ebp]
	push	eax
	call	_sprintf
	add	esp, 20					; 00000014H

; 145  :     
; 146  :     /*
; 147  :      * Emit the version.h file.
; 148  :      */
; 149  :     if (argc > 0) {

	cmp	DWORD PTR _argc$[ebp], 0
	jle	SHORT $L1061

; 150  : 	fd = fopen(argv[0], "w");

	push	OFFSET FLAT:$SG1062
	mov	ecx, DWORD PTR _argv$[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	call	_fopen
	add	esp, 8
	mov	DWORD PTR _fd$[ebp], eax

; 151  : 	if (fd == NULL) {

	cmp	DWORD PTR _fd$[ebp], 0
	jne	SHORT $L1064

; 152  : 	    fprintf(stderr, "mkversion: %s: Could not open for writing.\n",
; 153  : 		argv[0]);

	mov	eax, DWORD PTR _argv$[ebp]
	mov	ecx, DWORD PTR [eax]
	push	ecx
	push	OFFSET FLAT:$SG1065
	push	OFFSET FLAT:__iob+64
	call	_fprintf
	add	esp, 12					; 0000000cH

; 154  : 	    exit(-1);

	push	-1
	call	_exit
$L1064:

; 156  :     } else

	jmp	SHORT $L1066
$L1061:

; 157  : 	fd = stdout;

	mov	DWORD PTR _fd$[ebp], OFFSET FLAT:__iob+32
$L1066:

; 158  :     fprintf(fd, "#define TIFFLIB_VERSION_STR \"LIBTIFF, Version %s\\n", version);

	lea	edx, DWORD PTR _version$[ebp]
	push	edx
	push	OFFSET FLAT:$SG1067
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 12					; 0000000cH

; 159  :     fprintf(fd, "Copyright (c) 1988-1996 Sam Leffler\\n");

	push	OFFSET FLAT:$SG1068
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 160  :     fprintf(fd, "Copyright (c) 1991-1996 Silicon Graphics, Inc.\"\n");

	push	OFFSET FLAT:$SG1069
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8

; 161  : 
; 162  :     fprintf( fd, 
; 163  :              "/*\n"
; 164  :              " * This define can be used in code that requires\n"
; 165  :              " * compilation-related definitions specific to a\n"
; 166  :              " * version or versions of the library.  Runtime\n"
; 167  :              " * version checking should be done based on the\n"
; 168  :              " * string returned by TIFFGetVersion.\n" 
; 169  :              " */\n" );

	push	OFFSET FLAT:$SG1070
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8

; 170  :     fprintf(fd, "%s\n", tiffLibVersion );

	lea	ecx, DWORD PTR _tiffLibVersion$[ebp]
	push	ecx
	push	OFFSET FLAT:$SG1071
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 12					; 0000000cH

; 171  : 
; 172  :     if (fd != stdout)

	cmp	DWORD PTR _fd$[ebp], OFFSET FLAT:__iob+32
	je	SHORT $L1072

; 173  : 	fclose(fd);

	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fclose
	add	esp, 4
$L1072:

; 174  :     return (0);

	xor	eax, eax
$L1013:

; 175  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_main	ENDP
_TEXT	ENDS
_DATA	SEGMENT
$SG998	DB	'usage: mkversion [-v version-file] [-a alpha-file]', 0aH
	DB	'                 [-r releasedate-file] [outfile]', 0aH, 00H
_DATA	ENDS
_TEXT	SEGMENT
_usage	PROC NEAR

; 42   : {

	push	ebp
	mov	ebp, esp

; 43   :     fprintf(stderr,
; 44   :             "usage: mkversion [-v version-file] [-a alpha-file]\n"
; 45   :             "                 [-r releasedate-file] [outfile]\n");

	push	OFFSET FLAT:$SG998
	push	OFFSET FLAT:__iob+64
	call	_fprintf
	add	esp, 8

; 46   :     exit(-1);

	push	-1
	call	_exit
$L997:

; 47   : }

	pop	ebp
	ret	0
_usage	ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+3
$SG1004	DB	'r', 00H
	ORG $+2
$SG1007	DB	'mkversion: %s: Could not open for reading.', 0aH, 00H
_DATA	ENDS
_TEXT	SEGMENT
_filename$ = 8
_fd$ = -4
_openFile PROC NEAR

; 51   : {

	push	ebp
	mov	ebp, esp
	push	ecx

; 52   :     FILE* fd = fopen(filename, "r");

	push	OFFSET FLAT:$SG1004
	mov	eax, DWORD PTR _filename$[ebp]
	push	eax
	call	_fopen
	add	esp, 8
	mov	DWORD PTR _fd$[ebp], eax

; 53   :     if (fd == NULL) {

	cmp	DWORD PTR _fd$[ebp], 0
	jne	SHORT $L1006

; 54   : 	fprintf(stderr, "mkversion: %s: Could not open for reading.\n",
; 55   : 	    filename);

	mov	ecx, DWORD PTR _filename$[ebp]
	push	ecx
	push	OFFSET FLAT:$SG1007
	push	OFFSET FLAT:__iob+64
	call	_fprintf
	add	esp, 12					; 0000000cH

; 56   : 	exit(-1);

	push	-1
	call	_exit
$L1006:

; 58   :     return (fd);

	mov	eax, DWORD PTR _fd$[ebp]
$L1002:

; 59   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_openFile ENDP
_TEXT	ENDS
END
