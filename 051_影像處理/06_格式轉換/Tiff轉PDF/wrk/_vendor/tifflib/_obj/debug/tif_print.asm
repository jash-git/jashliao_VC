	TITLE	C:\Documents and Settings\Administrator\®à­±\½d¨Ò\codeproject\wrk\_vendor\tifflib\libtiff\tif_print.c
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
_photoNames DD	FLAT:$SG65783
	DD	FLAT:$SG65784
	DD	FLAT:$SG65785
	DD	FLAT:$SG65786
	DD	FLAT:$SG65787
	DD	FLAT:$SG65788
	DD	FLAT:$SG65789
	DD	FLAT:$SG65790
	DD	FLAT:$SG65791
_orientNames DD	FLAT:$SG65794
	DD	FLAT:$SG65795
	DD	FLAT:$SG65796
	DD	FLAT:$SG65797
	DD	FLAT:$SG65798
	DD	FLAT:$SG65799
	DD	FLAT:$SG65800
	DD	FLAT:$SG65801
	DD	FLAT:$SG65802
$SG65783 DB	'min-is-white', 00H
	ORG $+3
$SG65784 DB	'min-is-black', 00H
	ORG $+3
$SG65785 DB	'RGB color', 00H
	ORG $+2
$SG65786 DB	'palette color (RGB from colormap)', 00H
	ORG $+2
$SG65787 DB	'transparency mask', 00H
	ORG $+2
$SG65788 DB	'separated', 00H
	ORG $+2
$SG65789 DB	'YCbCr', 00H
	ORG $+2
$SG65790 DB	'7 (0x7)', 00H
$SG65791 DB	'CIE L*a*b*', 00H
	ORG $+1
$SG65794 DB	'0 (0x0)', 00H
$SG65795 DB	'row 0 top, col 0 lhs', 00H
	ORG $+3
$SG65796 DB	'row 0 top, col 0 rhs', 00H
	ORG $+3
$SG65797 DB	'row 0 bottom, col 0 rhs', 00H
$SG65798 DB	'row 0 bottom, col 0 lhs', 00H
$SG65799 DB	'row 0 lhs, col 0 top', 00H
	ORG $+3
$SG65800 DB	'row 0 rhs, col 0 top', 00H
	ORG $+3
$SG65801 DB	'row 0 rhs, col 0 bottom', 00H
$SG65802 DB	'row 0 lhs, col 0 bottom', 00H
_DATA	ENDS
PUBLIC	__TIFFprintAscii
PUBLIC	__TIFFprintAsciiTag
PUBLIC	_TIFFPrintDirectory
EXTRN	_fprintf:NEAR
EXTRN	_fputc:NEAR
EXTRN	_TIFFFindCODEC:NEAR
EXTRN	_strchr:NEAR
EXTRN	__fltused:NEAR
_BSS	SEGMENT
$SG65953 DB	01H DUP (?)
	ALIGN	4

$SG65989 DB	01H DUP (?)
_BSS	ENDS
_DATA	SEGMENT
$SG65817 DB	'TIFF Directory at offset 0x%lx', 0aH, 00H
$SG65820 DB	'  Subfile Type:', 00H
$SG65821 DB	' ', 00H
	ORG $+2
$SG65823 DB	'%sreduced-resolution image', 00H
	ORG $+1
$SG65824 DB	'/', 00H
	ORG $+2
$SG65826 DB	'%smulti-page document', 00H
	ORG $+2
$SG65827 DB	'/', 00H
	ORG $+2
$SG65829 DB	'%stransparency mask', 00H
$SG65832 DB	' (%lu = 0x%lx)', 0aH, 00H
$SG65837 DB	'  Image Width: %lu Image Length: %lu', 00H
	ORG $+3
$SG65841 DB	' Image Depth: %lu', 00H
	ORG $+2
$SG65842 DB	0aH, 00H
	ORG $+2
$SG65849 DB	'  Pixar Full Image Width: %lu Full Image Length: %lu', 0aH
	DB	00H
	ORG $+2
$SG65852 DB	'Texture Format', 00H
	ORG $+1
$SG65855 DB	'Texture Wrap Modes', 00H
	ORG $+1
$SG65858 DB	'  Field of View Cotangent: %g', 0aH, 00H
	ORG $+1
$SG65864 DB	'  Matrix NP:', 0aH, 09H, '%g %g %g %g', 0aH, 09H, '%g %g'
	DB	' %g %g', 0aH, 09H, '%g %g %g %g', 0aH, 09H, '%g %g %g %g', 0aH
	DB	00H
	ORG $+2
$SG65870 DB	'  Matrix Nl:', 0aH, 09H, '%g %g %g %g', 0aH, 09H, '%g %g'
	DB	' %g %g', 0aH, 09H, '%g %g %g %g', 0aH, 09H, '%g %g %g %g', 0aH
	DB	00H
	ORG $+2
$SG65875 DB	'  Tile Width: %lu Tile Length: %lu', 00H
	ORG $+1
$SG65879 DB	' Tile Depth: %lu', 00H
	ORG $+3
$SG65880 DB	0aH, 00H
	ORG $+2
$SG65883 DB	'  Resolution: %g, %g', 00H
	ORG $+3
$SG65891 DB	' (unitless)', 00H
$SG65893 DB	' pixels/inch', 00H
	ORG $+3
$SG65895 DB	' pixels/cm', 00H
	ORG $+1
$SG65897 DB	' (unit %u = 0x%x)', 00H
	ORG $+2
$SG65898 DB	0aH, 00H
	ORG $+2
$SG65901 DB	'  Position: %g, %g', 0aH, 00H
$SG65904 DB	'  Bits/Sample: %u', 0aH, 00H
	ORG $+1
$SG65907 DB	'  Sample Format: ', 00H
	ORG $+2
$SG65913 DB	'void', 0aH, 00H
	ORG $+2
$SG65915 DB	'signed integer', 0aH, 00H
$SG65917 DB	'unsigned integer', 0aH, 00H
	ORG $+2
$SG65919 DB	'IEEE floating point', 0aH, 00H
	ORG $+3
$SG65921 DB	'complex signed integer', 0aH, 00H
$SG65923 DB	'complex IEEE floating point', 0aH, 00H
	ORG $+3
$SG65925 DB	'%u (0x%x)', 0aH, 00H
	ORG $+1
$SG65929 DB	'  Compression Scheme: ', 00H
	ORG $+1
$SG65931 DB	'%s', 0aH, 00H
$SG65933 DB	'%u (0x%x)', 0aH, 00H
	ORG $+1
$SG65936 DB	'  Photometric Interpretation: ', 00H
	ORG $+1
$SG65938 DB	'%s', 0aH, 00H
$SG65945 DB	'CIE Log2(L)', 0aH, 00H
	ORG $+3
$SG65947 DB	'CIE Log2(L) (u'',v'')', 0aH, 00H
	ORG $+3
$SG65949 DB	'%u (0x%x)', 0aH, 00H
	ORG $+1
$SG65952 DB	'  Extra Samples: %u<', 00H
	ORG $+3
$SG65962 DB	'%sunspecified', 00H
	ORG $+2
$SG65964 DB	'%sassoc-alpha', 00H
	ORG $+2
$SG65966 DB	'%sunassoc-alpha', 00H
$SG65968 DB	'%s%u (0x%x)', 00H
$SG65969 DB	', ', 00H
	ORG $+1
$SG65970 DB	'>', 0aH, 00H
	ORG $+1
$SG65973 DB	'  Sample to Nits conversion factor: %.4e', 0aH, 00H
	ORG $+2
$SG65976 DB	'  Ink Set: ', 00H
$SG65982 DB	'CMYK', 0aH, 00H
	ORG $+2
$SG65984 DB	'%u (0x%x)', 0aH, 00H
	ORG $+1
$SG65988 DB	'  Ink Names: ', 00H
	ORG $+2
$SG65993 DB	'%s', 00H
	ORG $+1
$SG65994 DB	', ', 00H
	ORG $+1
$SG65997 DB	' Number of Inks: %u', 0aH, 00H
	ORG $+3
$SG66000 DB	'  Dot Range: %u-%u', 0aH, 00H
$SG66003 DB	'Target Printer', 00H
	ORG $+1
$SG66006 DB	'  Thresholding: ', 00H
	ORG $+3
$SG66012 DB	'bilevel art scan', 0aH, 00H
	ORG $+2
$SG66014 DB	'halftone or dithered scan', 0aH, 00H
	ORG $+1
$SG66016 DB	'error diffused', 0aH, 00H
$SG66018 DB	'%u (0x%x)', 0aH, 00H
	ORG $+1
$SG66021 DB	'  FillOrder: ', 00H
	ORG $+2
$SG66027 DB	'msb-to-lsb', 0aH, 00H
$SG66029 DB	'lsb-to-msb', 0aH, 00H
$SG66031 DB	'%u (0x%x)', 0aH, 00H
	ORG $+1
$SG66034 DB	'  YCbCr Subsampling: %u, %u', 0aH, 00H
	ORG $+3
$SG66037 DB	'  YCbCr Positioning: ', 00H
	ORG $+2
$SG66043 DB	'centered', 0aH, 00H
	ORG $+2
$SG66045 DB	'cosited', 0aH, 00H
	ORG $+3
$SG66047 DB	'%u (0x%x)', 0aH, 00H
	ORG $+1
$SG66050 DB	'  YCbCr Coefficients: %g, %g, %g', 0aH, 00H
	ORG $+2
$SG66053 DB	'  Halftone Hints: light %u dark %u', 0aH, 00H
$SG66056 DB	'Artist', 00H
	ORG $+1
$SG66059 DB	'Date & Time', 00H
$SG66062 DB	'Host Computer', 00H
	ORG $+2
$SG66065 DB	'Software', 00H
	ORG $+3
$SG66068 DB	'Copyright', 00H
	ORG $+2
$SG66071 DB	'Document Name', 00H
	ORG $+2
$SG66074 DB	'Image Description', 00H
	ORG $+2
$SG66077 DB	'Make', 00H
	ORG $+3
$SG66080 DB	'Model', 00H
	ORG $+2
$SG66083 DB	'  Orientation: ', 00H
$SG66085 DB	'%s', 0aH, 00H
$SG66087 DB	'%u (0x%x)', 0aH, 00H
	ORG $+1
$SG66090 DB	'  Samples/Pixel: %u', 0aH, 00H
	ORG $+3
$SG66093 DB	'  Rows/Strip: ', 00H
	ORG $+1
$SG66096 DB	'(infinite)', 0aH, 00H
$SG66099 DB	'%lu', 0aH, 00H
	ORG $+3
$SG66102 DB	'  Min Sample Value: %u', 0aH, 00H
$SG66105 DB	'  Max Sample Value: %u', 0aH, 00H
$SG66108 DB	'  SMin Sample Value: %g', 0aH, 00H
	ORG $+3
$SG66111 DB	'  SMax Sample Value: %g', 0aH, 00H
	ORG $+3
$SG66114 DB	'  Planar Configuration: ', 00H
	ORG $+3
$SG66120 DB	'single image plane', 0aH, 00H
$SG66122 DB	'separate image planes', 0aH, 00H
	ORG $+1
$SG66124 DB	'%u (0x%x)', 0aH, 00H
	ORG $+1
$SG66127 DB	'Page Name', 00H
	ORG $+2
$SG66130 DB	'  Page Number: %u-%u', 0aH, 00H
	ORG $+2
$SG66133 DB	'  Color Map: ', 00H
	ORG $+2
$SG66135 DB	0aH, 00H
	ORG $+2
$SG66139 DB	'   %5lu: %5u %5u %5u', 0aH, 00H
	ORG $+2
$SG66141 DB	'(present)', 0aH, 00H
	ORG $+1
$SG66144 DB	'  White Point: %g-%g', 0aH, 00H
	ORG $+2
$SG66147 DB	'  Primary Chromaticities: %g,%g %g,%g %g,%g', 0aH, 00H
	ORG $+3
$SG66150 DB	'  Reference Black/White:', 0aH, 00H
	ORG $+2
$SG66154 DB	'    %2d: %5g %5g', 0aH, 00H
	ORG $+2
$SG66157 DB	'  Transfer Function: ', 00H
	ORG $+2
$SG66159 DB	0aH, 00H
	ORG $+2
$SG66163 DB	'    %2lu: %5u', 00H
	ORG $+2
$SG66167 DB	' %5u', 00H
	ORG $+3
$SG66169 DB	'(present)', 0aH, 00H
	ORG $+1
$SG66173 DB	'  ICC Profile: <present>, %lu bytes', 0aH, 00H
	ORG $+3
$SG66177 DB	'  Photoshop Data: <present>, %lu bytes', 0aH, 00H
$SG66181 DB	'  RichTIFFIPTC Data: <present>, %lu bytes', 0aH, 00H
	ORG $+1
$SG66184 DB	'  SubIFD Offsets:', 00H
	ORG $+2
$SG66189 DB	' %5lu', 00H
	ORG $+2
$SG66195 DB	'Tiles', 00H
	ORG $+2
$SG66196 DB	'Strips', 00H
	ORG $+1
$SG66197 DB	'  %lu %s:', 0aH, 00H
	ORG $+1
$SG66204 DB	'    %3lu: [%8lu, %8lu]', 0aH, 00H
_DATA	ENDS
_TEXT	SEGMENT
_tif$ = 8
_fd$ = 12
_flags$ = 16
_td$ = -12
_sep$ = -4
_i$ = -8
_l$ = -16
_n$ = -20
_m$65862 = -24
_m$65868 = -28
_c$65928 = -32
_cp$65987 = -36
_s$66193 = -40
_TIFFPrintDirectory PROC NEAR

; 69   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 80					; 00000050H

; 70   : 	register TIFFDirectory *td;
; 71   : 	char *sep;
; 72   : 	uint16 i;
; 73   : 	long l, n;
; 74   : 
; 75   : 	fprintf(fd, "TIFF Directory at offset 0x%lx\n", tif->tif_diroff);

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+16]
	push	ecx
	push	OFFSET FLAT:$SG65817
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 12					; 0000000cH

; 76   : 	td = &tif->tif_dir;

	mov	eax, DWORD PTR _tif$[ebp]
	add	eax, 24					; 00000018H
	mov	DWORD PTR _td$[ebp], eax

; 77   : 	if (TIFFFieldSet(tif,FIELD_SUBFILETYPE)) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	and	edx, 32					; 00000020H
	test	edx, edx
	je	$L65819

; 78   : 		fprintf(fd, "  Subfile Type:");

	push	OFFSET FLAT:$SG65820
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8

; 79   : 		sep = " ";

	mov	DWORD PTR _sep$[ebp], OFFSET FLAT:$SG65821

; 80   : 		if (td->td_subfiletype & FILETYPE_REDUCEDIMAGE) {

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+36]
	and	edx, 1
	test	edx, edx
	je	SHORT $L65822

; 81   : 			fprintf(fd, "%sreduced-resolution image", sep);

	mov	eax, DWORD PTR _sep$[ebp]
	push	eax
	push	OFFSET FLAT:$SG65823
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 12					; 0000000cH

; 82   : 			sep = "/";

	mov	DWORD PTR _sep$[ebp], OFFSET FLAT:$SG65824
$L65822:

; 84   : 		if (td->td_subfiletype & FILETYPE_PAGE) {

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+36]
	and	eax, 2
	test	eax, eax
	je	SHORT $L65825

; 85   : 			fprintf(fd, "%smulti-page document", sep);

	mov	ecx, DWORD PTR _sep$[ebp]
	push	ecx
	push	OFFSET FLAT:$SG65826
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 12					; 0000000cH

; 86   : 			sep = "/";

	mov	DWORD PTR _sep$[ebp], OFFSET FLAT:$SG65827
$L65825:

; 88   : 		if (td->td_subfiletype & FILETYPE_MASK)

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+36]
	and	ecx, 4
	test	ecx, ecx
	je	SHORT $L65828

; 89   : 			fprintf(fd, "%stransparency mask", sep);

	mov	edx, DWORD PTR _sep$[ebp]
	push	edx
	push	OFFSET FLAT:$SG65829
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 12					; 0000000cH
$L65828:

; 90   : 		fprintf(fd, " (%lu = 0x%lx)\n",
; 91   : 		    (long) td->td_subfiletype, (long) td->td_subfiletype);

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+36]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+36]
	push	ecx
	push	OFFSET FLAT:$SG65832
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 16					; 00000010H
$L65819:

; 93   : 	if (TIFFFieldSet(tif,FIELD_IMAGEDIMENSIONS)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 2
	test	ecx, ecx
	je	SHORT $L65834

; 94   : 		fprintf(fd, "  Image Width: %lu Image Length: %lu",
; 95   : 		    (u_long) td->td_imagewidth, (u_long) td->td_imagelength);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+16]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+12]
	push	edx
	push	OFFSET FLAT:$SG65837
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 16					; 00000010H

; 96   : 		if (TIFFFieldSet(tif,FIELD_IMAGEDEPTH))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	and	edx, 8
	test	edx, edx
	je	SHORT $L65839

; 97   : 			fprintf(fd, " Image Depth: %lu",
; 98   : 			    (u_long) td->td_imagedepth);

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+20]
	push	ecx
	push	OFFSET FLAT:$SG65841
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 12					; 0000000cH
$L65839:

; 99   : 		fprintf(fd, "\n");

	push	OFFSET FLAT:$SG65842
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8
$L65834:

; 101  : 
; 102  :  	/* Begin Pixar */
; 103  :  	if (TIFFFieldSet(tif,FIELD_IMAGEFULLWIDTH) ||
; 104  :  	    TIFFFieldSet(tif,FIELD_IMAGEFULLLENGTH)) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	and	edx, 8388608				; 00800000H
	test	edx, edx
	jne	SHORT $L65846
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	and	ecx, 16777216				; 01000000H
	test	ecx, ecx
	je	SHORT $L65845
$L65846:

; 105  : 	  fprintf(fd, "  Pixar Full Image Width: %lu Full Image Length: %lu\n",
; 106  : 		  (u_long) td->td_imagefullwidth,
; 107  : 		  (u_long) td->td_imagefulllength);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+284]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+280]
	push	edx
	push	OFFSET FLAT:$SG65849
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 16					; 00000010H
$L65845:

; 109  :  	if (TIFFFieldSet(tif,FIELD_TEXTUREFORMAT))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	and	edx, 33554432				; 02000000H
	test	edx, edx
	je	SHORT $L65851

; 110  : 	  _TIFFprintAsciiTag(fd, "Texture Format", td->td_textureformat);

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+288]
	push	ecx
	push	OFFSET FLAT:$SG65852
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	__TIFFprintAsciiTag
	add	esp, 12					; 0000000cH
$L65851:

; 111  :  	if (TIFFFieldSet(tif,FIELD_WRAPMODES))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	and	ecx, 67108864				; 04000000H
	test	ecx, ecx
	je	SHORT $L65854

; 112  : 	  _TIFFprintAsciiTag(fd, "Texture Wrap Modes", td->td_wrapmodes);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+292]
	push	eax
	push	OFFSET FLAT:$SG65855
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	__TIFFprintAsciiTag
	add	esp, 12					; 0000000cH
$L65854:

; 113  :  	if (TIFFFieldSet(tif,FIELD_FOVCOT))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+28]
	and	eax, 134217728				; 08000000H
	test	eax, eax
	je	SHORT $L65857

; 114  : 	  fprintf(fd, "  Field of View Cotangent: %g\n", td->td_fovcot);

	mov	ecx, DWORD PTR _td$[ebp]
	fld	DWORD PTR [ecx+296]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	push	OFFSET FLAT:$SG65858
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 16					; 00000010H
$L65857:

; 115  : 	if (TIFFFieldSet(tif,FIELD_MATRIX_WORLDTOSCREEN)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	and	ecx, 268435456				; 10000000H
	test	ecx, ecx
	je	$L65860

; 116  : 	  typedef float	Matrix[4][4];
; 117  : 	  Matrix*		m = (Matrix*)td->td_matrixWorldToScreen;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+300]
	mov	DWORD PTR _m$65862[ebp], eax

; 118  : 	  
; 119  : 	  fprintf(fd, "  Matrix NP:\n\t%g %g %g %g\n\t%g %g %g %g\n\t%g %g %g %g\n\t%g %g %g %g\n",
; 120  : 		  (*m)[0][0], (*m)[0][1], (*m)[0][2], (*m)[0][3],
; 121  : 		  (*m)[1][0], (*m)[1][1], (*m)[1][2], (*m)[1][3],
; 122  : 		  (*m)[2][0], (*m)[2][1], (*m)[2][2], (*m)[2][3],
; 123  : 		  (*m)[3][0], (*m)[3][1], (*m)[3][2], (*m)[3][3]);

	mov	ecx, DWORD PTR _m$65862[ebp]
	fld	DWORD PTR [ecx+60]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	edx, DWORD PTR _m$65862[ebp]
	fld	DWORD PTR [edx+56]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	eax, DWORD PTR _m$65862[ebp]
	fld	DWORD PTR [eax+52]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	ecx, DWORD PTR _m$65862[ebp]
	fld	DWORD PTR [ecx+48]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	edx, DWORD PTR _m$65862[ebp]
	fld	DWORD PTR [edx+44]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	eax, DWORD PTR _m$65862[ebp]
	fld	DWORD PTR [eax+40]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	ecx, DWORD PTR _m$65862[ebp]
	fld	DWORD PTR [ecx+36]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	edx, DWORD PTR _m$65862[ebp]
	fld	DWORD PTR [edx+32]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	eax, DWORD PTR _m$65862[ebp]
	fld	DWORD PTR [eax+28]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	ecx, DWORD PTR _m$65862[ebp]
	fld	DWORD PTR [ecx+24]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	edx, DWORD PTR _m$65862[ebp]
	fld	DWORD PTR [edx+20]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	eax, DWORD PTR _m$65862[ebp]
	fld	DWORD PTR [eax+16]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	ecx, DWORD PTR _m$65862[ebp]
	fld	DWORD PTR [ecx+12]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	edx, DWORD PTR _m$65862[ebp]
	fld	DWORD PTR [edx+8]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	eax, DWORD PTR _m$65862[ebp]
	fld	DWORD PTR [eax+4]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	ecx, DWORD PTR _m$65862[ebp]
	fld	DWORD PTR [ecx]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	push	OFFSET FLAT:$SG65864
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 136				; 00000088H
$L65860:

; 125  :  	if (TIFFFieldSet(tif,FIELD_MATRIX_WORLDTOCAMERA)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	and	ecx, 536870912				; 20000000H
	test	ecx, ecx
	je	$L65866

; 126  : 	  typedef float	Matrix[4][4];
; 127  : 	  Matrix*		m = (Matrix*)td->td_matrixWorldToCamera;

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+304]
	mov	DWORD PTR _m$65868[ebp], eax

; 128  : 	  
; 129  : 	  fprintf(fd, "  Matrix Nl:\n\t%g %g %g %g\n\t%g %g %g %g\n\t%g %g %g %g\n\t%g %g %g %g\n",
; 130  : 		  (*m)[0][0], (*m)[0][1], (*m)[0][2], (*m)[0][3],
; 131  : 		  (*m)[1][0], (*m)[1][1], (*m)[1][2], (*m)[1][3],
; 132  : 		  (*m)[2][0], (*m)[2][1], (*m)[2][2], (*m)[2][3],
; 133  : 		  (*m)[3][0], (*m)[3][1], (*m)[3][2], (*m)[3][3]);

	mov	ecx, DWORD PTR _m$65868[ebp]
	fld	DWORD PTR [ecx+60]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	edx, DWORD PTR _m$65868[ebp]
	fld	DWORD PTR [edx+56]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	eax, DWORD PTR _m$65868[ebp]
	fld	DWORD PTR [eax+52]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	ecx, DWORD PTR _m$65868[ebp]
	fld	DWORD PTR [ecx+48]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	edx, DWORD PTR _m$65868[ebp]
	fld	DWORD PTR [edx+44]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	eax, DWORD PTR _m$65868[ebp]
	fld	DWORD PTR [eax+40]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	ecx, DWORD PTR _m$65868[ebp]
	fld	DWORD PTR [ecx+36]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	edx, DWORD PTR _m$65868[ebp]
	fld	DWORD PTR [edx+32]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	eax, DWORD PTR _m$65868[ebp]
	fld	DWORD PTR [eax+28]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	ecx, DWORD PTR _m$65868[ebp]
	fld	DWORD PTR [ecx+24]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	edx, DWORD PTR _m$65868[ebp]
	fld	DWORD PTR [edx+20]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	eax, DWORD PTR _m$65868[ebp]
	fld	DWORD PTR [eax+16]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	ecx, DWORD PTR _m$65868[ebp]
	fld	DWORD PTR [ecx+12]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	edx, DWORD PTR _m$65868[ebp]
	fld	DWORD PTR [edx+8]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	eax, DWORD PTR _m$65868[ebp]
	fld	DWORD PTR [eax+4]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	ecx, DWORD PTR _m$65868[ebp]
	fld	DWORD PTR [ecx]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	push	OFFSET FLAT:$SG65870
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 136				; 00000088H
$L65866:

; 135  :  	/* End Pixar */
; 136  : 	
; 137  : 	if (TIFFFieldSet(tif,FIELD_TILEDIMENSIONS)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 4
	test	ecx, ecx
	je	SHORT $L65872

; 138  : 		fprintf(fd, "  Tile Width: %lu Tile Length: %lu",
; 139  : 		    (u_long) td->td_tilewidth, (u_long) td->td_tilelength);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+28]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	push	edx
	push	OFFSET FLAT:$SG65875
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 16					; 00000010H

; 140  : 		if (TIFFFieldSet(tif,FIELD_TILEDEPTH))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	and	edx, 16					; 00000010H
	test	edx, edx
	je	SHORT $L65877

; 141  : 			fprintf(fd, " Tile Depth: %lu",
; 142  : 			    (u_long) td->td_tiledepth);

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+32]
	push	ecx
	push	OFFSET FLAT:$SG65879
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 12					; 0000000cH
$L65877:

; 143  : 		fprintf(fd, "\n");

	push	OFFSET FLAT:$SG65880
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8
$L65872:

; 145  : 	if (TIFFFieldSet(tif,FIELD_RESOLUTION)) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	and	edx, 8
	test	edx, edx
	je	$L65882

; 146  : 		fprintf(fd, "  Resolution: %g, %g",
; 147  : 		    td->td_xresolution, td->td_yresolution);

	mov	eax, DWORD PTR _td$[ebp]
	fld	DWORD PTR [eax+84]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	ecx, DWORD PTR _td$[ebp]
	fld	DWORD PTR [ecx+80]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	push	OFFSET FLAT:$SG65883
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 24					; 00000018H

; 148  : 		if (TIFFFieldSet(tif,FIELD_RESOLUTIONUNIT)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 4194304				; 00400000H
	test	ecx, ecx
	je	SHORT $L65887

; 149  : 			switch (td->td_resolutionunit) {

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+88]
	mov	DWORD PTR -44+[ebp], eax
	cmp	DWORD PTR -44+[ebp], 1
	je	SHORT $L65890
	cmp	DWORD PTR -44+[ebp], 2
	je	SHORT $L65892
	cmp	DWORD PTR -44+[ebp], 3
	je	SHORT $L65894
	jmp	SHORT $L65896
$L65890:

; 150  : 			case RESUNIT_NONE:
; 151  : 				fprintf(fd, " (unitless)");

	push	OFFSET FLAT:$SG65891
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 152  : 				break;

	jmp	SHORT $L65887
$L65892:

; 153  : 			case RESUNIT_INCH:
; 154  : 				fprintf(fd, " pixels/inch");

	push	OFFSET FLAT:$SG65893
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8

; 155  : 				break;

	jmp	SHORT $L65887
$L65894:

; 156  : 			case RESUNIT_CENTIMETER:
; 157  : 				fprintf(fd, " pixels/cm");

	push	OFFSET FLAT:$SG65895
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8

; 158  : 				break;

	jmp	SHORT $L65887
$L65896:

; 159  : 			default:
; 160  : 				fprintf(fd, " (unit %u = 0x%x)",
; 161  : 				    td->td_resolutionunit,
; 162  : 				    td->td_resolutionunit);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+88]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+88]
	push	ecx
	push	OFFSET FLAT:$SG65897
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 16					; 00000010H
$L65887:

; 166  : 		fprintf(fd, "\n");

	push	OFFSET FLAT:$SG65898
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8
$L65882:

; 168  : 	if (TIFFFieldSet(tif,FIELD_POSITION))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	and	edx, 16					; 00000010H
	test	edx, edx
	je	SHORT $L65900

; 169  : 		fprintf(fd, "  Position: %g, %g\n",
; 170  : 		    td->td_xposition, td->td_yposition);

	mov	eax, DWORD PTR _td$[ebp]
	fld	DWORD PTR [eax+96]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	ecx, DWORD PTR _td$[ebp]
	fld	DWORD PTR [ecx+92]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	push	OFFSET FLAT:$SG65901
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 24					; 00000018H
$L65900:

; 171  : 	if (TIFFFieldSet(tif,FIELD_BITSPERSAMPLE))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 64					; 00000040H
	test	ecx, ecx
	je	SHORT $L65903

; 172  : 		fprintf(fd, "  Bits/Sample: %u\n", td->td_bitspersample);

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+40]
	push	eax
	push	OFFSET FLAT:$SG65904
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 12					; 0000000cH
$L65903:

; 173  : 	if (TIFFFieldSet(tif,FIELD_SAMPLEFORMAT)) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+28]
	and	eax, 1
	test	eax, eax
	je	$L65909

; 174  : 		fprintf(fd, "  Sample Format: ");

	push	OFFSET FLAT:$SG65907
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 175  : 		switch (td->td_sampleformat) {

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+42]
	mov	DWORD PTR -48+[ebp], eax
	mov	ecx, DWORD PTR -48+[ebp]
	sub	ecx, 1
	mov	DWORD PTR -48+[ebp], ecx
	cmp	DWORD PTR -48+[ebp], 5
	ja	SHORT $L65924
	mov	edx, DWORD PTR -48+[ebp]
	jmp	DWORD PTR $L66238[edx*4]
$L65912:

; 176  : 		case SAMPLEFORMAT_VOID:
; 177  : 			fprintf(fd, "void\n");

	push	OFFSET FLAT:$SG65913
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8

; 178  : 			break;

	jmp	$L65909
$L65914:

; 179  : 		case SAMPLEFORMAT_INT:
; 180  : 			fprintf(fd, "signed integer\n");

	push	OFFSET FLAT:$SG65915
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 181  : 			break;

	jmp	SHORT $L65909
$L65916:

; 182  : 		case SAMPLEFORMAT_UINT:
; 183  : 			fprintf(fd, "unsigned integer\n");

	push	OFFSET FLAT:$SG65917
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8

; 184  : 			break;

	jmp	SHORT $L65909
$L65918:

; 185  : 		case SAMPLEFORMAT_IEEEFP:
; 186  : 			fprintf(fd, "IEEE floating point\n");

	push	OFFSET FLAT:$SG65919
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8

; 187  : 			break;

	jmp	SHORT $L65909
$L65920:

; 188  : 		case SAMPLEFORMAT_COMPLEXINT:
; 189  : 			fprintf(fd, "complex signed integer\n");

	push	OFFSET FLAT:$SG65921
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 190  : 			break;

	jmp	SHORT $L65909
$L65922:

; 191  : 		case SAMPLEFORMAT_COMPLEXIEEEFP:
; 192  : 			fprintf(fd, "complex IEEE floating point\n");

	push	OFFSET FLAT:$SG65923
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8

; 193  : 			break;

	jmp	SHORT $L65909
$L65924:

; 194  : 		default:
; 195  : 			fprintf(fd, "%u (0x%x)\n",
; 196  : 			    td->td_sampleformat, td->td_sampleformat);

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+42]
	push	ecx
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+42]
	push	eax
	push	OFFSET FLAT:$SG65925
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 16					; 00000010H
$L65909:

; 200  : 	if (TIFFFieldSet(tif,FIELD_COMPRESSION)) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+24]
	and	eax, 128				; 00000080H
	test	eax, eax
	je	SHORT $L65932

; 201  : 		const TIFFCodec* c = TIFFFindCODEC(td->td_compression);

	mov	ecx, DWORD PTR _td$[ebp]
	mov	dx, WORD PTR [ecx+44]
	push	edx
	call	_TIFFFindCODEC
	add	esp, 4
	mov	DWORD PTR _c$65928[ebp], eax

; 202  : 		fprintf(fd, "  Compression Scheme: ");

	push	OFFSET FLAT:$SG65929
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8

; 203  : 		if (c)

	cmp	DWORD PTR _c$65928[ebp], 0
	je	SHORT $L65930

; 204  : 			fprintf(fd, "%s\n", c->name);

	mov	ecx, DWORD PTR _c$65928[ebp]
	mov	edx, DWORD PTR [ecx]
	push	edx
	push	OFFSET FLAT:$SG65931
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 12					; 0000000cH

; 205  : 		else

	jmp	SHORT $L65932
$L65930:

; 206  : 			fprintf(fd, "%u (0x%x)\n",
; 207  : 			    td->td_compression, td->td_compression);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+44]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+44]
	push	ecx
	push	OFFSET FLAT:$SG65933
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 16					; 00000010H
$L65932:

; 209  : 	if (TIFFFieldSet(tif,FIELD_PHOTOMETRIC)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 256				; 00000100H
	test	ecx, ecx
	je	$L65941

; 210  : 		fprintf(fd, "  Photometric Interpretation: ");

	push	OFFSET FLAT:$SG65936
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8

; 211  : 		if (td->td_photometric < NPHOTONAMES)

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+46]
	cmp	ecx, 9
	jae	SHORT $L65937

; 212  : 			fprintf(fd, "%s\n", photoNames[td->td_photometric]);

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+46]
	mov	ecx, DWORD PTR _photoNames[eax*4]
	push	ecx
	push	OFFSET FLAT:$SG65938
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 12					; 0000000cH

; 213  : 		else {

	jmp	SHORT $L65941
$L65937:

; 214  : 			switch (td->td_photometric) {

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+46]
	mov	DWORD PTR -52+[ebp], ecx
	cmp	DWORD PTR -52+[ebp], 32844		; 0000804cH
	je	SHORT $L65944
	cmp	DWORD PTR -52+[ebp], 32845		; 0000804dH
	je	SHORT $L65946
	jmp	SHORT $L65948
$L65944:

; 215  : 			case PHOTOMETRIC_LOGL:
; 216  : 				fprintf(fd, "CIE Log2(L)\n");

	push	OFFSET FLAT:$SG65945
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8

; 217  : 				break;

	jmp	SHORT $L65941
$L65946:

; 218  : 			case PHOTOMETRIC_LOGLUV:
; 219  : 				fprintf(fd, "CIE Log2(L) (u',v')\n");

	push	OFFSET FLAT:$SG65947
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8

; 220  : 				break;

	jmp	SHORT $L65941
$L65948:

; 221  : 			default:
; 222  : 				fprintf(fd, "%u (0x%x)\n",
; 223  : 				    td->td_photometric, td->td_photometric);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+46]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+46]
	push	ecx
	push	OFFSET FLAT:$SG65949
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 16					; 00000010H
$L65941:

; 228  : 	if (TIFFFieldSet(tif,FIELD_EXTRASAMPLES) && td->td_extrasamples) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, -2147483648			; 80000000H
	test	ecx, ecx
	je	$L65951
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+120]
	test	eax, eax
	je	$L65951

; 229  : 		fprintf(fd, "  Extra Samples: %u<", td->td_extrasamples);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+120]
	push	edx
	push	OFFSET FLAT:$SG65952
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 12					; 0000000cH

; 230  : 		sep = "";

	mov	DWORD PTR _sep$[ebp], OFFSET FLAT:$SG65953

; 231  : 		for (i = 0; i < td->td_extrasamples; i++) {

	mov	WORD PTR _i$[ebp], 0
	jmp	SHORT $L65954
$L65955:
	mov	cx, WORD PTR _i$[ebp]
	add	cx, 1
	mov	WORD PTR _i$[ebp], cx
$L65954:
	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+120]
	cmp	edx, ecx
	jge	$L65956

; 232  : 			switch (td->td_sampleinfo[i]) {

	mov	edx, DWORD PTR _i$[ebp]
	and	edx, 65535				; 0000ffffH
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+124]
	xor	eax, eax
	mov	ax, WORD PTR [ecx+edx*2]
	mov	DWORD PTR -56+[ebp], eax
	cmp	DWORD PTR -56+[ebp], 0
	je	SHORT $L65961
	cmp	DWORD PTR -56+[ebp], 1
	je	SHORT $L65963
	cmp	DWORD PTR -56+[ebp], 2
	je	SHORT $L65965
	jmp	SHORT $L65967
$L65961:

; 233  : 			case EXTRASAMPLE_UNSPECIFIED:
; 234  : 				fprintf(fd, "%sunspecified", sep);

	mov	ecx, DWORD PTR _sep$[ebp]
	push	ecx
	push	OFFSET FLAT:$SG65962
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 12					; 0000000cH

; 235  : 				break;

	jmp	SHORT $L65958
$L65963:

; 236  : 			case EXTRASAMPLE_ASSOCALPHA:
; 237  : 				fprintf(fd, "%sassoc-alpha", sep);

	mov	eax, DWORD PTR _sep$[ebp]
	push	eax
	push	OFFSET FLAT:$SG65964
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 12					; 0000000cH

; 238  : 				break;

	jmp	SHORT $L65958
$L65965:

; 239  : 			case EXTRASAMPLE_UNASSALPHA:
; 240  : 				fprintf(fd, "%sunassoc-alpha", sep);

	mov	edx, DWORD PTR _sep$[ebp]
	push	edx
	push	OFFSET FLAT:$SG65966
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 12					; 0000000cH

; 241  : 				break;

	jmp	SHORT $L65958
$L65967:

; 242  : 			default:
; 243  : 				fprintf(fd, "%s%u (0x%x)", sep,
; 244  : 				    td->td_sampleinfo[i], td->td_sampleinfo[i]);

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+124]
	xor	edx, edx
	mov	dx, WORD PTR [eax+ecx*2]
	push	edx
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+124]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+eax*2]
	push	ecx
	mov	edx, DWORD PTR _sep$[ebp]
	push	edx
	push	OFFSET FLAT:$SG65968
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 20					; 00000014H
$L65958:

; 247  : 			sep = ", ";

	mov	DWORD PTR _sep$[ebp], OFFSET FLAT:$SG65969

; 248  : 		}

	jmp	$L65955
$L65956:

; 249  : 		fprintf(fd, ">\n");

	push	OFFSET FLAT:$SG65970
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8
$L65951:

; 251  : 	if (TIFFFieldSet(tif,FIELD_STONITS)) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+28]
	and	eax, 4194304				; 00400000H
	test	eax, eax
	je	SHORT $L65972

; 252  : 		fprintf(fd, "  Sample to Nits conversion factor: %.4e\n",
; 253  : 				td->td_stonits);

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+132]
	push	edx
	mov	eax, DWORD PTR [ecx+128]
	push	eax
	push	OFFSET FLAT:$SG65973
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 16					; 00000010H
$L65972:

; 255  : #ifdef CMYK_SUPPORT
; 256  : 	if (TIFFFieldSet(tif,FIELD_INKSET)) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+28]
	and	eax, 8192				; 00002000H
	test	eax, eax
	je	SHORT $L65978

; 257  : 		fprintf(fd, "  Ink Set: ");

	push	OFFSET FLAT:$SG65976
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 258  : 		switch (td->td_inkset) {

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+236]
	mov	DWORD PTR -60+[ebp], eax
	cmp	DWORD PTR -60+[ebp], 1
	je	SHORT $L65981
	jmp	SHORT $L65983
$L65981:

; 259  : 		case INKSET_CMYK:
; 260  : 			fprintf(fd, "CMYK\n");

	push	OFFSET FLAT:$SG65982
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 261  : 			break;

	jmp	SHORT $L65978
$L65983:

; 262  : 		default:
; 263  : 			fprintf(fd, "%u (0x%x)\n",
; 264  : 			    td->td_inkset, td->td_inkset);

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+236]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+236]
	push	edx
	push	OFFSET FLAT:$SG65984
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 16					; 00000010H
$L65978:

; 268  : 	if (TIFFFieldSet(tif,FIELD_INKNAMES)) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	and	edx, 16384				; 00004000H
	test	edx, edx
	je	$L65992

; 269  : 		char* cp;
; 270  : 		fprintf(fd, "  Ink Names: ");

	push	OFFSET FLAT:$SG65988
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8

; 271  : 		i = td->td_samplesperpixel;

	mov	ecx, DWORD PTR _td$[ebp]
	mov	dx, WORD PTR [ecx+54]
	mov	WORD PTR _i$[ebp], dx

; 272  : 		sep = "";

	mov	DWORD PTR _sep$[ebp], OFFSET FLAT:$SG65989

; 273  : 		for (cp = td->td_inknames; i > 0; cp = strchr(cp,'\0')+1, i--) {

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+248]
	mov	DWORD PTR _cp$65987[ebp], ecx
	jmp	SHORT $L65990
$L65991:
	push	0
	mov	edx, DWORD PTR _cp$65987[ebp]
	push	edx
	call	_strchr
	add	esp, 8
	add	eax, 1
	mov	DWORD PTR _cp$65987[ebp], eax
	mov	ax, WORD PTR _i$[ebp]
	sub	ax, 1
	mov	WORD PTR _i$[ebp], ax
$L65990:
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 65535				; 0000ffffH
	test	ecx, ecx
	jle	SHORT $L65992

; 274  : 			fprintf(fd, "%s", sep);

	mov	edx, DWORD PTR _sep$[ebp]
	push	edx
	push	OFFSET FLAT:$SG65993
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 12					; 0000000cH

; 275  : 			_TIFFprintAscii(fd, cp);

	mov	ecx, DWORD PTR _cp$65987[ebp]
	push	ecx
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	__TIFFprintAscii
	add	esp, 8

; 276  : 			sep = ", ";

	mov	DWORD PTR _sep$[ebp], OFFSET FLAT:$SG65994

; 277  : 		}

	jmp	SHORT $L65991
$L65992:

; 279  : 	if (TIFFFieldSet(tif,FIELD_NUMBEROFINKS))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	and	ecx, 262144				; 00040000H
	test	ecx, ecx
	je	SHORT $L65996

; 280  : 		fprintf(fd, " Number of Inks: %u\n", td->td_ninks);

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+238]
	push	eax
	push	OFFSET FLAT:$SG65997
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 12					; 0000000cH
$L65996:

; 281  : 	if (TIFFFieldSet(tif,FIELD_DOTRANGE))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+28]
	and	eax, 32768				; 00008000H
	test	eax, eax
	je	SHORT $L65999

; 282  : 		fprintf(fd, "  Dot Range: %u-%u\n",
; 283  : 		    td->td_dotrange[0], td->td_dotrange[1]);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+242]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+240]
	push	ecx
	push	OFFSET FLAT:$SG66000
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 16					; 00000010H
$L65999:

; 284  : 	if (TIFFFieldSet(tif,FIELD_TARGETPRINTER))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	and	ecx, 65536				; 00010000H
	test	ecx, ecx
	je	SHORT $L66002

; 285  : 		_TIFFprintAsciiTag(fd, "Target Printer", td->td_targetprinter);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+252]
	push	eax
	push	OFFSET FLAT:$SG66003
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	__TIFFprintAsciiTag
	add	esp, 12					; 0000000cH
$L66002:

; 286  : #endif
; 287  : 	if (TIFFFieldSet(tif,FIELD_THRESHHOLDING)) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+24]
	and	eax, 512				; 00000200H
	test	eax, eax
	je	$L66008

; 288  : 		fprintf(fd, "  Thresholding: ");

	push	OFFSET FLAT:$SG66006
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 289  : 		switch (td->td_threshholding) {

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+48]
	mov	DWORD PTR -64+[ebp], eax
	cmp	DWORD PTR -64+[ebp], 1
	je	SHORT $L66011
	cmp	DWORD PTR -64+[ebp], 2
	je	SHORT $L66013
	cmp	DWORD PTR -64+[ebp], 3
	je	SHORT $L66015
	jmp	SHORT $L66017
$L66011:

; 290  : 		case THRESHHOLD_BILEVEL:
; 291  : 			fprintf(fd, "bilevel art scan\n");

	push	OFFSET FLAT:$SG66012
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 292  : 			break;

	jmp	SHORT $L66008
$L66013:

; 293  : 		case THRESHHOLD_HALFTONE:
; 294  : 			fprintf(fd, "halftone or dithered scan\n");

	push	OFFSET FLAT:$SG66014
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8

; 295  : 			break;

	jmp	SHORT $L66008
$L66015:

; 296  : 		case THRESHHOLD_ERRORDIFFUSE:
; 297  : 			fprintf(fd, "error diffused\n");

	push	OFFSET FLAT:$SG66016
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8

; 298  : 			break;

	jmp	SHORT $L66008
$L66017:

; 299  : 		default:
; 300  : 			fprintf(fd, "%u (0x%x)\n",
; 301  : 			    td->td_threshholding, td->td_threshholding);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+48]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+48]
	push	ecx
	push	OFFSET FLAT:$SG66018
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 16					; 00000010H
$L66008:

; 305  : 	if (TIFFFieldSet(tif,FIELD_FILLORDER)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 1024				; 00000400H
	test	ecx, ecx
	je	SHORT $L66023

; 306  : 		fprintf(fd, "  FillOrder: ");

	push	OFFSET FLAT:$SG66021
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8

; 307  : 		switch (td->td_fillorder) {

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+50]
	mov	DWORD PTR -68+[ebp], ecx
	cmp	DWORD PTR -68+[ebp], 1
	je	SHORT $L66026
	cmp	DWORD PTR -68+[ebp], 2
	je	SHORT $L66028
	jmp	SHORT $L66030
$L66026:

; 308  : 		case FILLORDER_MSB2LSB:
; 309  : 			fprintf(fd, "msb-to-lsb\n");

	push	OFFSET FLAT:$SG66027
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8

; 310  : 			break;

	jmp	SHORT $L66023
$L66028:

; 311  : 		case FILLORDER_LSB2MSB:
; 312  : 			fprintf(fd, "lsb-to-msb\n");

	push	OFFSET FLAT:$SG66029
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8

; 313  : 			break;

	jmp	SHORT $L66023
$L66030:

; 314  : 		default:
; 315  : 			fprintf(fd, "%u (0x%x)\n",
; 316  : 			    td->td_fillorder, td->td_fillorder);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+50]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+50]
	push	ecx
	push	OFFSET FLAT:$SG66031
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 16					; 00000010H
$L66023:

; 320  : #ifdef YCBCR_SUPPORT
; 321  : 	if (TIFFFieldSet(tif,FIELD_YCBCRSUBSAMPLING))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	and	ecx, 128				; 00000080H
	test	ecx, ecx
	je	SHORT $L66033

; 322  : 		fprintf(fd, "  YCbCr Subsampling: %u, %u\n",
; 323  : 		    td->td_ycbcrsubsampling[0], td->td_ycbcrsubsampling[1]);

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+206]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+204]
	push	edx
	push	OFFSET FLAT:$SG66034
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 16					; 00000010H
$L66033:

; 324  : 	if (TIFFFieldSet(tif,FIELD_YCBCRPOSITIONING)) {

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	and	edx, 256				; 00000100H
	test	edx, edx
	je	SHORT $L66039

; 325  : 		fprintf(fd, "  YCbCr Positioning: ");

	push	OFFSET FLAT:$SG66037
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8

; 326  : 		switch (td->td_ycbcrpositioning) {

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+208]
	mov	DWORD PTR -72+[ebp], edx
	cmp	DWORD PTR -72+[ebp], 1
	je	SHORT $L66042
	cmp	DWORD PTR -72+[ebp], 2
	je	SHORT $L66044
	jmp	SHORT $L66046
$L66042:

; 327  : 		case YCBCRPOSITION_CENTERED:
; 328  : 			fprintf(fd, "centered\n");

	push	OFFSET FLAT:$SG66043
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8

; 329  : 			break;

	jmp	SHORT $L66039
$L66044:

; 330  : 		case YCBCRPOSITION_COSITED:
; 331  : 			fprintf(fd, "cosited\n");

	push	OFFSET FLAT:$SG66045
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 332  : 			break;

	jmp	SHORT $L66039
$L66046:

; 333  : 		default:
; 334  : 			fprintf(fd, "%u (0x%x)\n",
; 335  : 			    td->td_ycbcrpositioning, td->td_ycbcrpositioning);

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+208]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+208]
	push	edx
	push	OFFSET FLAT:$SG66047
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 16					; 00000010H
$L66039:

; 339  : 	if (TIFFFieldSet(tif,FIELD_YCBCRCOEFFICIENTS))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	and	edx, 64					; 00000040H
	test	edx, edx
	je	SHORT $L66049

; 340  : 		fprintf(fd, "  YCbCr Coefficients: %g, %g, %g\n",
; 341  : 		    td->td_ycbcrcoeffs[0],
; 342  : 		    td->td_ycbcrcoeffs[1],
; 343  : 		    td->td_ycbcrcoeffs[2]);

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+200]
	fld	DWORD PTR [ecx+8]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+200]
	fld	DWORD PTR [eax+4]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+200]
	fld	DWORD PTR [edx]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	push	OFFSET FLAT:$SG66050
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 32					; 00000020H
$L66049:

; 344  : #endif
; 345  : 	if (TIFFFieldSet(tif,FIELD_HALFTONEHINTS))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	and	edx, 32					; 00000020H
	test	edx, edx
	je	SHORT $L66052

; 346  : 		fprintf(fd, "  Halftone Hints: light %u dark %u\n",
; 347  : 		    td->td_halftonehints[0], td->td_halftonehints[1]);

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+118]
	push	ecx
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+116]
	push	eax
	push	OFFSET FLAT:$SG66053
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 16					; 00000010H
$L66052:

; 348  : 	if (TIFFFieldSet(tif,FIELD_ARTIST))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+24]
	and	eax, 134217728				; 08000000H
	test	eax, eax
	je	SHORT $L66055

; 349  : 		_TIFFprintAsciiTag(fd, "Artist", td->td_artist);

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+140]
	push	edx
	push	OFFSET FLAT:$SG66056
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	__TIFFprintAsciiTag
	add	esp, 12					; 0000000cH
$L66055:

; 350  : 	if (TIFFFieldSet(tif,FIELD_DATETIME))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	and	edx, 268435456				; 10000000H
	test	edx, edx
	je	SHORT $L66058

; 351  : 		_TIFFprintAsciiTag(fd, "Date & Time", td->td_datetime);

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+144]
	push	ecx
	push	OFFSET FLAT:$SG66059
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	__TIFFprintAsciiTag
	add	esp, 12					; 0000000cH
$L66058:

; 352  : 	if (TIFFFieldSet(tif,FIELD_HOSTCOMPUTER))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 536870912				; 20000000H
	test	ecx, ecx
	je	SHORT $L66061

; 353  : 		_TIFFprintAsciiTag(fd, "Host Computer", td->td_hostcomputer);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+148]
	push	eax
	push	OFFSET FLAT:$SG66062
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	__TIFFprintAsciiTag
	add	esp, 12					; 0000000cH
$L66061:

; 354  : 	if (TIFFFieldSet(tif,FIELD_SOFTWARE))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+24]
	and	eax, 1073741824				; 40000000H
	test	eax, eax
	je	SHORT $L66064

; 355  : 		_TIFFprintAsciiTag(fd, "Software", td->td_software);

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+164]
	push	edx
	push	OFFSET FLAT:$SG66065
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	__TIFFprintAsciiTag
	add	esp, 12					; 0000000cH
$L66064:

; 356  : 	if (TIFFFieldSet(tif,FIELD_COPYRIGHT))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	and	edx, 1073741824				; 40000000H
	test	edx, edx
	je	SHORT $L66067

; 357  : 		_TIFFprintAsciiTag(fd, "Copyright", td->td_copyright);

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+168]
	push	ecx
	push	OFFSET FLAT:$SG66068
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	__TIFFprintAsciiTag
	add	esp, 12					; 0000000cH
$L66067:

; 358  : 	if (TIFFFieldSet(tif,FIELD_DOCUMENTNAME))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 2048				; 00000800H
	test	ecx, ecx
	je	SHORT $L66070

; 359  : 		_TIFFprintAsciiTag(fd, "Document Name", td->td_documentname);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+136]
	push	eax
	push	OFFSET FLAT:$SG66071
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	__TIFFprintAsciiTag
	add	esp, 12					; 0000000cH
$L66070:

; 360  : 	if (TIFFFieldSet(tif,FIELD_IMAGEDESCRIPTION))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+24]
	and	eax, 4096				; 00001000H
	test	eax, eax
	je	SHORT $L66073

; 361  : 		_TIFFprintAsciiTag(fd, "Image Description", td->td_imagedescription);

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+152]
	push	edx
	push	OFFSET FLAT:$SG66074
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	__TIFFprintAsciiTag
	add	esp, 12					; 0000000cH
$L66073:

; 362  : 	if (TIFFFieldSet(tif,FIELD_MAKE))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	and	edx, 8192				; 00002000H
	test	edx, edx
	je	SHORT $L66076

; 363  : 		_TIFFprintAsciiTag(fd, "Make", td->td_make);

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+156]
	push	ecx
	push	OFFSET FLAT:$SG66077
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	__TIFFprintAsciiTag
	add	esp, 12					; 0000000cH
$L66076:

; 364  : 	if (TIFFFieldSet(tif,FIELD_MODEL))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 16384				; 00004000H
	test	ecx, ecx
	je	SHORT $L66079

; 365  : 		_TIFFprintAsciiTag(fd, "Model", td->td_model);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+160]
	push	eax
	push	OFFSET FLAT:$SG66080
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	__TIFFprintAsciiTag
	add	esp, 12					; 0000000cH
$L66079:

; 366  : 	if (TIFFFieldSet(tif,FIELD_ORIENTATION)) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+24]
	and	eax, 32768				; 00008000H
	test	eax, eax
	je	SHORT $L66086

; 367  : 		fprintf(fd, "  Orientation: ");

	push	OFFSET FLAT:$SG66083
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 368  : 		if (td->td_orientation < NORIENTNAMES)

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+52]
	cmp	eax, 9
	jae	SHORT $L66084

; 369  : 			fprintf(fd, "%s\n", orientNames[td->td_orientation]);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+52]
	mov	eax, DWORD PTR _orientNames[edx*4]
	push	eax
	push	OFFSET FLAT:$SG66085
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 12					; 0000000cH

; 370  : 		else

	jmp	SHORT $L66086
$L66084:

; 371  : 			fprintf(fd, "%u (0x%x)\n",
; 372  : 			    td->td_orientation, td->td_orientation);

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+52]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+52]
	push	edx
	push	OFFSET FLAT:$SG66087
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 16					; 00000010H
$L66086:

; 374  : 	if (TIFFFieldSet(tif,FIELD_SAMPLESPERPIXEL))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	and	edx, 65536				; 00010000H
	test	edx, edx
	je	SHORT $L66089

; 375  : 		fprintf(fd, "  Samples/Pixel: %u\n", td->td_samplesperpixel);

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+54]
	push	ecx
	push	OFFSET FLAT:$SG66090
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 12					; 0000000cH
$L66089:

; 376  : 	if (TIFFFieldSet(tif,FIELD_ROWSPERSTRIP)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 131072				; 00020000H
	test	ecx, ecx
	je	SHORT $L66097

; 377  : 		fprintf(fd, "  Rows/Strip: ");

	push	OFFSET FLAT:$SG66093
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8

; 378  : 		if (td->td_rowsperstrip == (uint32) -1)

	mov	eax, DWORD PTR _td$[ebp]
	cmp	DWORD PTR [eax+56], -1
	jne	SHORT $L66095

; 379  : 			fprintf(fd, "(infinite)\n");

	push	OFFSET FLAT:$SG66096
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 380  : 		else

	jmp	SHORT $L66097
$L66095:

; 381  : 			fprintf(fd, "%lu\n", (u_long) td->td_rowsperstrip);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+56]
	push	eax
	push	OFFSET FLAT:$SG66099
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 12					; 0000000cH
$L66097:

; 383  : 	if (TIFFFieldSet(tif,FIELD_MINSAMPLEVALUE))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+24]
	and	eax, 262144				; 00040000H
	test	eax, eax
	je	SHORT $L66101

; 384  : 		fprintf(fd, "  Min Sample Value: %u\n", td->td_minsamplevalue);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+60]
	push	edx
	push	OFFSET FLAT:$SG66102
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 12					; 0000000cH
$L66101:

; 385  : 	if (TIFFFieldSet(tif,FIELD_MAXSAMPLEVALUE))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+24]
	and	edx, 524288				; 00080000H
	test	edx, edx
	je	SHORT $L66104

; 386  : 		fprintf(fd, "  Max Sample Value: %u\n", td->td_maxsamplevalue);

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+62]
	push	ecx
	push	OFFSET FLAT:$SG66105
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 12					; 0000000cH
$L66104:

; 387  : 	if (TIFFFieldSet(tif,FIELD_SMINSAMPLEVALUE))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	and	ecx, 2
	test	ecx, ecx
	je	SHORT $L66107

; 388  : 		fprintf(fd, "  SMin Sample Value: %g\n",
; 389  : 		    td->td_sminsamplevalue);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+68]
	push	eax
	mov	ecx, DWORD PTR [edx+64]
	push	ecx
	push	OFFSET FLAT:$SG66108
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 16					; 00000010H
$L66107:

; 390  : 	if (TIFFFieldSet(tif,FIELD_SMAXSAMPLEVALUE))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	and	ecx, 4
	test	ecx, ecx
	je	SHORT $L66110

; 391  : 		fprintf(fd, "  SMax Sample Value: %g\n",
; 392  : 		    td->td_smaxsamplevalue);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+76]
	push	eax
	mov	ecx, DWORD PTR [edx+72]
	push	ecx
	push	OFFSET FLAT:$SG66111
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 16					; 00000010H
$L66110:

; 393  : 	if (TIFFFieldSet(tif,FIELD_PLANARCONFIG)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 1048576				; 00100000H
	test	ecx, ecx
	je	SHORT $L66116

; 394  : 		fprintf(fd, "  Planar Configuration: ");

	push	OFFSET FLAT:$SG66114
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8

; 395  : 		switch (td->td_planarconfig) {

	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+90]
	mov	DWORD PTR -76+[ebp], ecx
	cmp	DWORD PTR -76+[ebp], 1
	je	SHORT $L66119
	cmp	DWORD PTR -76+[ebp], 2
	je	SHORT $L66121
	jmp	SHORT $L66123
$L66119:

; 396  : 		case PLANARCONFIG_CONTIG:
; 397  : 			fprintf(fd, "single image plane\n");

	push	OFFSET FLAT:$SG66120
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8

; 398  : 			break;

	jmp	SHORT $L66116
$L66121:

; 399  : 		case PLANARCONFIG_SEPARATE:
; 400  : 			fprintf(fd, "separate image planes\n");

	push	OFFSET FLAT:$SG66122
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 8

; 401  : 			break;

	jmp	SHORT $L66116
$L66123:

; 402  : 		default:
; 403  : 			fprintf(fd, "%u (0x%x)\n",
; 404  : 			    td->td_planarconfig, td->td_planarconfig);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+90]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+90]
	push	ecx
	push	OFFSET FLAT:$SG66124
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 16					; 00000010H
$L66116:

; 408  : 	if (TIFFFieldSet(tif,FIELD_PAGENAME))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 2097152				; 00200000H
	test	ecx, ecx
	je	SHORT $L66126

; 409  : 		_TIFFprintAsciiTag(fd, "Page Name", td->td_pagename);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+172]
	push	eax
	push	OFFSET FLAT:$SG66127
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	__TIFFprintAsciiTag
	add	esp, 12					; 0000000cH
$L66126:

; 410  : 	if (TIFFFieldSet(tif,FIELD_PAGENUMBER))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+24]
	and	eax, 8388608				; 00800000H
	test	eax, eax
	je	SHORT $L66129

; 411  : 		fprintf(fd, "  Page Number: %u-%u\n",
; 412  : 		    td->td_pagenumber[0], td->td_pagenumber[1]);

	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+102]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [eax+100]
	push	ecx
	push	OFFSET FLAT:$SG66130
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 16					; 00000010H
$L66129:

; 413  : 	if (TIFFFieldSet(tif,FIELD_COLORMAP)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 67108864				; 04000000H
	test	ecx, ecx
	je	$L66140

; 414  : 		fprintf(fd, "  Color Map: ");

	push	OFFSET FLAT:$SG66133
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8

; 415  : 		if (flags & TIFFPRINT_COLORMAP) {

	mov	eax, DWORD PTR _flags$[ebp]
	and	eax, 4
	test	eax, eax
	je	$L66134

; 416  : 			fprintf(fd, "\n");

	push	OFFSET FLAT:$SG66135
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 417  : 			n = 1L<<td->td_bitspersample;

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+40]
	mov	ecx, eax
	mov	edx, 1
	shl	edx, cl
	mov	DWORD PTR _n$[ebp], edx

; 418  : 			for (l = 0; l < n; l++)

	mov	DWORD PTR _l$[ebp], 0
	jmp	SHORT $L66136
$L66137:
	mov	eax, DWORD PTR _l$[ebp]
	add	eax, 1
	mov	DWORD PTR _l$[ebp], eax
$L66136:
	mov	ecx, DWORD PTR _l$[ebp]
	cmp	ecx, DWORD PTR _n$[ebp]
	jge	SHORT $L66138

; 419  : 				fprintf(fd, "   %5lu: %5u %5u %5u\n",
; 420  : 				    l,
; 421  : 				    td->td_colormap[0][l],
; 422  : 				    td->td_colormap[1][l],
; 423  : 				    td->td_colormap[2][l]);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+112]
	mov	ecx, DWORD PTR _l$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [eax+ecx*2]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+108]
	mov	edx, DWORD PTR _l$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [ecx+edx*2]
	push	eax
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+104]
	mov	eax, DWORD PTR _l$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+eax*2]
	push	ecx
	mov	edx, DWORD PTR _l$[ebp]
	push	edx
	push	OFFSET FLAT:$SG66139
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 24					; 00000018H
	jmp	SHORT $L66137
$L66138:

; 424  : 		} else

	jmp	SHORT $L66140
$L66134:

; 425  : 			fprintf(fd, "(present)\n");

	push	OFFSET FLAT:$SG66141
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8
$L66140:

; 427  : #ifdef COLORIMETRY_SUPPORT
; 428  : 	if (TIFFFieldSet(tif,FIELD_WHITEPOINT))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+28]
	and	eax, 1024				; 00000400H
	test	eax, eax
	je	SHORT $L66143

; 429  : 		fprintf(fd, "  White Point: %g-%g\n",
; 430  : 		    td->td_whitepoint[0], td->td_whitepoint[1]);

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+212]
	fld	DWORD PTR [edx+4]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+212]
	fld	DWORD PTR [ecx]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	push	OFFSET FLAT:$SG66144
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 24					; 00000018H
$L66143:

; 431  : 	if (TIFFFieldSet(tif,FIELD_PRIMARYCHROMAS))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	and	ecx, 2048				; 00000800H
	test	ecx, ecx
	je	SHORT $L66146

; 432  : 		fprintf(fd, "  Primary Chromaticities: %g,%g %g,%g %g,%g\n",
; 433  : 		    td->td_primarychromas[0], td->td_primarychromas[1],
; 434  : 		    td->td_primarychromas[2], td->td_primarychromas[3],
; 435  : 		    td->td_primarychromas[4], td->td_primarychromas[5]);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+216]
	fld	DWORD PTR [eax+20]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+216]
	fld	DWORD PTR [edx+16]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+216]
	fld	DWORD PTR [ecx+12]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+216]
	fld	DWORD PTR [eax+8]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+216]
	fld	DWORD PTR [edx+4]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+216]
	fld	DWORD PTR [ecx]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	push	OFFSET FLAT:$SG66147
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 56					; 00000038H
$L66146:

; 436  : 	if (TIFFFieldSet(tif,FIELD_REFBLACKWHITE)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	and	ecx, 512				; 00000200H
	test	ecx, ecx
	je	$L66153

; 437  : 		fprintf(fd, "  Reference Black/White:\n");

	push	OFFSET FLAT:$SG66150
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8

; 438  : 		for (i = 0; i < td->td_samplesperpixel; i++)

	mov	WORD PTR _i$[ebp], 0
	jmp	SHORT $L66151
$L66152:
	mov	ax, WORD PTR _i$[ebp]
	add	ax, 1
	mov	WORD PTR _i$[ebp], ax
$L66151:
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 65535				; 0000ffffH
	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+54]
	cmp	ecx, eax
	jge	SHORT $L66153

; 439  : 			fprintf(fd, "    %2d: %5g %5g\n",
; 440  : 			    i,
; 441  : 			    td->td_refblackwhite[2*i+0],
; 442  : 			    td->td_refblackwhite[2*i+1]);

	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 1
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+220]
	fld	DWORD PTR [eax+ecx*4+4]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 65535				; 0000ffffH
	shl	ecx, 1
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+220]
	fld	DWORD PTR [eax+ecx*4]
	sub	esp, 8
	fstp	QWORD PTR [esp]
	mov	ecx, DWORD PTR _i$[ebp]
	and	ecx, 65535				; 0000ffffH
	push	ecx
	push	OFFSET FLAT:$SG66154
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 28					; 0000001cH
	jmp	SHORT $L66152
$L66153:

; 444  : 	if (TIFFFieldSet(tif,FIELD_TRANSFERFUNCTION)) {

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	and	ecx, 4096				; 00001000H
	test	ecx, ecx
	je	$L66168

; 445  : 		fprintf(fd, "  Transfer Function: ");

	push	OFFSET FLAT:$SG66157
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 8

; 446  : 		if (flags & TIFFPRINT_CURVES) {

	mov	eax, DWORD PTR _flags$[ebp]
	and	eax, 2
	test	eax, eax
	je	$L66158

; 447  : 			fprintf(fd, "\n");

	push	OFFSET FLAT:$SG66159
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 448  : 			n = 1L<<td->td_bitspersample;

	mov	edx, DWORD PTR _td$[ebp]
	xor	eax, eax
	mov	ax, WORD PTR [edx+40]
	mov	ecx, eax
	mov	edx, 1
	shl	edx, cl
	mov	DWORD PTR _n$[ebp], edx

; 449  : 			for (l = 0; l < n; l++) {

	mov	DWORD PTR _l$[ebp], 0
	jmp	SHORT $L66160
$L66161:
	mov	eax, DWORD PTR _l$[ebp]
	add	eax, 1
	mov	DWORD PTR _l$[ebp], eax
$L66160:
	mov	ecx, DWORD PTR _l$[ebp]
	cmp	ecx, DWORD PTR _n$[ebp]
	jge	$L66162

; 450  : 				fprintf(fd, "    %2lu: %5u",
; 451  : 				    l, td->td_transferfunction[0][l]);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+224]
	mov	ecx, DWORD PTR _l$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [eax+ecx*2]
	push	edx
	mov	eax, DWORD PTR _l$[ebp]
	push	eax
	push	OFFSET FLAT:$SG66163
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 16					; 00000010H

; 452  : 				for (i = 1; i < td->td_samplesperpixel; i++)

	mov	WORD PTR _i$[ebp], 1
	jmp	SHORT $L66164
$L66165:
	mov	dx, WORD PTR _i$[ebp]
	add	dx, 1
	mov	WORD PTR _i$[ebp], dx
$L66164:
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+54]
	cmp	eax, edx
	jge	SHORT $L66166

; 453  : 					fprintf(fd, " %5u",
; 454  : 					    td->td_transferfunction[i][l]);

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+eax*4+224]
	mov	eax, DWORD PTR _l$[ebp]
	xor	ecx, ecx
	mov	cx, WORD PTR [edx+eax*2]
	push	ecx
	push	OFFSET FLAT:$SG66167
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 12					; 0000000cH
	jmp	SHORT $L66165
$L66166:

; 455  : 				fputc('\n', fd);

	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	push	10					; 0000000aH
	call	_fputc
	add	esp, 8

; 456  : 			}

	jmp	$L66161
$L66162:

; 457  : 		} else

	jmp	SHORT $L66168
$L66158:

; 458  : 			fprintf(fd, "(present)\n");

	push	OFFSET FLAT:$SG66169
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8
$L66168:

; 460  : #endif
; 461  : #ifdef ICC_SUPPORT
; 462  : 	if (TIFFFieldSet(tif,FIELD_ICCPROFILE))

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+28]
	and	eax, 524288				; 00080000H
	test	eax, eax
	je	SHORT $L66171

; 463  : 		fprintf(fd, "  ICC Profile: <present>, %lu bytes\n",
; 464  : 		    (u_long) td->td_profileLength);

	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+256]
	push	edx
	push	OFFSET FLAT:$SG66173
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	_fprintf
	add	esp, 12					; 0000000cH
$L66171:

; 465  : #endif
; 466  : #ifdef PHOTOSHOP_SUPPORT
; 467  :  	if (TIFFFieldSet(tif,FIELD_PHOTOSHOP))

	mov	ecx, DWORD PTR _tif$[ebp]
	mov	edx, DWORD PTR [ecx+28]
	and	edx, 1048576				; 00100000H
	test	edx, edx
	je	SHORT $L66175

; 468  :  		fprintf(fd, "  Photoshop Data: <present>, %lu bytes\n",
; 469  :  		    (u_long) td->td_photoshopLength);

	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+264]
	push	ecx
	push	OFFSET FLAT:$SG66177
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 12					; 0000000cH
$L66175:

; 470  : #endif
; 471  : #ifdef IPTC_SUPPORT
; 472  :  	if (TIFFFieldSet(tif,FIELD_RICHTIFFIPTC))

	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+28]
	and	ecx, 2097152				; 00200000H
	test	ecx, ecx
	je	SHORT $L66179

; 473  :  		fprintf(fd, "  RichTIFFIPTC Data: <present>, %lu bytes\n",
; 474  :  		    (u_long) td->td_richtiffiptcLength);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+272]
	push	eax
	push	OFFSET FLAT:$SG66181
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 12					; 0000000cH
$L66179:

; 475  : #endif
; 476  : #if SUBIFD_SUPPORT
; 477  : 	if (TIFFFieldSet(tif, FIELD_SUBIFD)) {

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+28]
	and	eax, 131072				; 00020000H
	test	eax, eax
	je	SHORT $L66183

; 478  : 		fprintf(fd, "  SubIFD Offsets:");

	push	OFFSET FLAT:$SG66184
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 479  : 		for (i = 0; i < td->td_nsubifd; i++)

	mov	WORD PTR _i$[ebp], 0
	jmp	SHORT $L66185
$L66186:
	mov	dx, WORD PTR _i$[ebp]
	add	dx, 1
	mov	WORD PTR _i$[ebp], dx
$L66185:
	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _td$[ebp]
	xor	edx, edx
	mov	dx, WORD PTR [ecx+192]
	cmp	eax, edx
	jge	SHORT $L66187

; 480  : 			fprintf(fd, " %5lu", (long) td->td_subifd[i]);

	mov	eax, DWORD PTR _i$[ebp]
	and	eax, 65535				; 0000ffffH
	mov	ecx, DWORD PTR _td$[ebp]
	mov	edx, DWORD PTR [ecx+196]
	mov	eax, DWORD PTR [edx+eax*4]
	push	eax
	push	OFFSET FLAT:$SG66189
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 12					; 0000000cH
	jmp	SHORT $L66186
$L66187:

; 481  : 		fputc('\n', fd);

	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	push	10					; 0000000aH
	call	_fputc
	add	esp, 8
$L66183:

; 483  : #endif
; 484  : 	if (tif->tif_printdir)

	mov	eax, DWORD PTR _tif$[ebp]
	cmp	DWORD PTR [eax+548], 0
	je	SHORT $L66190

; 485  : 		(*tif->tif_printdir)(tif, fd, flags);

	mov	ecx, DWORD PTR _flags$[ebp]
	push	ecx
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	mov	eax, DWORD PTR _tif$[ebp]
	push	eax
	mov	ecx, DWORD PTR _tif$[ebp]
	call	DWORD PTR [ecx+548]
	add	esp, 12					; 0000000cH
$L66190:

; 486  : 	if ((flags & TIFFPRINT_STRIPS) &&
; 487  : 	    TIFFFieldSet(tif,FIELD_STRIPOFFSETS)) {

	mov	edx, DWORD PTR _flags$[ebp]
	and	edx, 1
	test	edx, edx
	je	$L66200
	mov	eax, DWORD PTR _tif$[ebp]
	mov	ecx, DWORD PTR [eax+24]
	and	ecx, 33554432				; 02000000H
	test	ecx, ecx
	je	$L66200

; 488  : 		tstrip_t s;
; 489  : 
; 490  : 		fprintf(fd, "  %lu %s:\n",
; 491  : 		    (long) td->td_nstrips,
; 492  : 		    isTiled(tif) ? "Tiles" : "Strips");

	mov	edx, DWORD PTR _tif$[ebp]
	mov	eax, DWORD PTR [edx+12]
	and	eax, 1024				; 00000400H
	test	eax, eax
	je	SHORT $L66236
	mov	DWORD PTR -80+[ebp], OFFSET FLAT:$SG66195
	jmp	SHORT $L66237
$L66236:
	mov	DWORD PTR -80+[ebp], OFFSET FLAT:$SG66196
$L66237:
	mov	ecx, DWORD PTR -80+[ebp]
	push	ecx
	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+180]
	push	eax
	push	OFFSET FLAT:$SG66197
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 16					; 00000010H

; 493  : 		for (s = 0; s < td->td_nstrips; s++)

	mov	DWORD PTR _s$66193[ebp], 0
	jmp	SHORT $L66198
$L66199:
	mov	edx, DWORD PTR _s$66193[ebp]
	add	edx, 1
	mov	DWORD PTR _s$66193[ebp], edx
$L66198:
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR _s$66193[ebp]
	cmp	ecx, DWORD PTR [eax+180]
	jae	SHORT $L66200

; 494  : 			fprintf(fd, "    %3lu: [%8lu, %8lu]\n",
; 495  : 			    (u_long) s,
; 496  : 			    (u_long) td->td_stripoffset[s],
; 497  : 			    (u_long) td->td_stripbytecount[s]);

	mov	edx, DWORD PTR _td$[ebp]
	mov	eax, DWORD PTR [edx+188]
	mov	ecx, DWORD PTR _s$66193[ebp]
	mov	edx, DWORD PTR [eax+ecx*4]
	push	edx
	mov	eax, DWORD PTR _td$[ebp]
	mov	ecx, DWORD PTR [eax+184]
	mov	edx, DWORD PTR _s$66193[ebp]
	mov	eax, DWORD PTR [ecx+edx*4]
	push	eax
	mov	ecx, DWORD PTR _s$66193[ebp]
	push	ecx
	push	OFFSET FLAT:$SG66204
	mov	edx, DWORD PTR _fd$[ebp]
	push	edx
	call	_fprintf
	add	esp, 20					; 00000014H
	jmp	SHORT $L66199
$L66200:

; 499  : }

	mov	esp, ebp
	pop	ebp
	ret	0
$L66238:
	DD	$L65916
	DD	$L65914
	DD	$L65918
	DD	$L65912
	DD	$L65920
	DD	$L65922
_TIFFPrintDirectory ENDP
_TEXT	ENDS
EXTRN	__pctype:DWORD
EXTRN	__isctype:NEAR
EXTRN	___mb_cur_max:DWORD
_DATA	SEGMENT
$SG66218 DB	09H, 't', 08H, 'b', 0dH, 'r', 0aH, 'n', 0bH, 'v', 00H
	ORG $+1
$SG66221 DB	'\%c', 00H
$SG66223 DB	'\%03o', 00H
_DATA	ENDS
_TEXT	SEGMENT
_fd$ = 8
_cp$ = 12
_tp$66213 = -4
__TIFFprintAscii PROC NEAR

; 503  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 8

; 504  : 	for (; *cp != '\0'; cp++) {

	jmp	SHORT $L66210
$L66211:
	mov	eax, DWORD PTR _cp$[ebp]
	add	eax, 1
	mov	DWORD PTR _cp$[ebp], eax
$L66210:
	mov	ecx, DWORD PTR _cp$[ebp]
	movsx	edx, BYTE PTR [ecx]
	test	edx, edx
	je	$L66212

; 505  : 		const char* tp;
; 506  : 
; 507  : 		if (isprint(*cp)) {

	cmp	DWORD PTR ___mb_cur_max, 1
	jle	SHORT $L66241
	push	343					; 00000157H
	mov	eax, DWORD PTR _cp$[ebp]
	movsx	ecx, BYTE PTR [eax]
	push	ecx
	call	__isctype
	add	esp, 8
	mov	DWORD PTR -8+[ebp], eax
	jmp	SHORT $L66242
$L66241:
	mov	edx, DWORD PTR _cp$[ebp]
	movsx	eax, BYTE PTR [edx]
	mov	ecx, DWORD PTR __pctype
	xor	edx, edx
	mov	dx, WORD PTR [ecx+eax*2]
	and	edx, 343				; 00000157H
	mov	DWORD PTR -8+[ebp], edx
$L66242:
	cmp	DWORD PTR -8+[ebp], 0
	je	SHORT $L66214

; 508  : 			fputc(*cp, fd);

	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	mov	ecx, DWORD PTR _cp$[ebp]
	movsx	edx, BYTE PTR [ecx]
	push	edx
	call	_fputc
	add	esp, 8

; 509  : 			continue;

	jmp	SHORT $L66211
$L66214:

; 511  : 		for (tp = "\tt\bb\rr\nn\vv"; *tp; tp++)

	mov	DWORD PTR _tp$66213[ebp], OFFSET FLAT:$SG66218
	jmp	SHORT $L66215
$L66216:
	mov	eax, DWORD PTR _tp$66213[ebp]
	add	eax, 1
	mov	DWORD PTR _tp$66213[ebp], eax
$L66215:
	mov	ecx, DWORD PTR _tp$66213[ebp]
	movsx	edx, BYTE PTR [ecx]
	test	edx, edx
	je	SHORT $L66217

; 512  : 			if (*tp++ == *cp)

	mov	eax, DWORD PTR _tp$66213[ebp]
	movsx	ecx, BYTE PTR [eax]
	mov	edx, DWORD PTR _cp$[ebp]
	movsx	eax, BYTE PTR [edx]
	mov	edx, DWORD PTR _tp$66213[ebp]
	add	edx, 1
	mov	DWORD PTR _tp$66213[ebp], edx
	cmp	ecx, eax
	jne	SHORT $L66219

; 513  : 				break;

	jmp	SHORT $L66217
$L66219:

; 514  : 		if (*tp)

	jmp	SHORT $L66216
$L66217:
	mov	eax, DWORD PTR _tp$66213[ebp]
	movsx	ecx, BYTE PTR [eax]
	test	ecx, ecx
	je	SHORT $L66220

; 515  : 			fprintf(fd, "\\%c", *tp);

	mov	edx, DWORD PTR _tp$66213[ebp]
	movsx	eax, BYTE PTR [edx]
	push	eax
	push	OFFSET FLAT:$SG66221
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 12					; 0000000cH

; 516  : 		else

	jmp	SHORT $L66222
$L66220:

; 517  : 			fprintf(fd, "\\%03o", *cp & 0xff);

	mov	edx, DWORD PTR _cp$[ebp]
	movsx	eax, BYTE PTR [edx]
	and	eax, 255				; 000000ffH
	push	eax
	push	OFFSET FLAT:$SG66223
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 12					; 0000000cH
$L66222:

; 518  : 	}

	jmp	$L66211
$L66212:

; 519  : }

	mov	esp, ebp
	pop	ebp
	ret	0
__TIFFprintAscii ENDP
_TEXT	ENDS
_DATA	SEGMENT
	ORG $+2
$SG66231 DB	'  %s: "', 00H
$SG66232 DB	'"', 0aH, 00H
_DATA	ENDS
_TEXT	SEGMENT
_fd$ = 8
_name$ = 12
_value$ = 16
__TIFFprintAsciiTag PROC NEAR

; 523  : {

	push	ebp
	mov	ebp, esp

; 524  : 	fprintf(fd, "  %s: \"", name);

	mov	eax, DWORD PTR _name$[ebp]
	push	eax
	push	OFFSET FLAT:$SG66231
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 12					; 0000000cH

; 525  : 	_TIFFprintAscii(fd, value);

	mov	edx, DWORD PTR _value$[ebp]
	push	edx
	mov	eax, DWORD PTR _fd$[ebp]
	push	eax
	call	__TIFFprintAscii
	add	esp, 8

; 526  : 	fprintf(fd, "\"\n");

	push	OFFSET FLAT:$SG66232
	mov	ecx, DWORD PTR _fd$[ebp]
	push	ecx
	call	_fprintf
	add	esp, 8

; 527  : }

	pop	ebp
	ret	0
__TIFFprintAsciiTag ENDP
_TEXT	ENDS
END
