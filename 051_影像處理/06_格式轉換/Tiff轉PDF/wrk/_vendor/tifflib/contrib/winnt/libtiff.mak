# Microsoft Developer Studio Generated NMAKE File, Based on libtiff.dsp
!IF "$(CFG)" == ""
CFG=libtiff - Win32 Debug
!MESSAGE No configuration specified. Defaulting to libtiff - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "libtiff - Win32 Release" && "$(CFG)" != "libtiff - Win32 Debug" && "$(CFG)" != "libtiff - Win32 (ALPHA) APXrel" && "$(CFG)" != "libtiff - Win32 (ALPHA) APXdeb"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "libtiff.mak" CFG="libtiff - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "libtiff - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "libtiff - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "libtiff - Win32 (ALPHA) APXrel" (based on "Win32 (ALPHA) Static Library")
!MESSAGE "libtiff - Win32 (ALPHA) APXdeb" (based on "Win32 (ALPHA) Static Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "libtiff - Win32 Release"

OUTDIR=.\..\..\lib
INTDIR=.\..\..\_obj\release
# Begin Custom Macros
OutDir=.\..\..\lib
# End Custom Macros

ALL : "$(OUTDIR)\libtiff.lib" "$(OUTDIR)\libtiff.bsc"


CLEAN :
	-@erase "$(INTDIR)\fax3sm_winnt.obj"
	-@erase "$(INTDIR)\fax3sm_winnt.sbr"
	-@erase "$(INTDIR)\mkg3states.obj"
	-@erase "$(INTDIR)\mkg3states.sbr"
	-@erase "$(INTDIR)\mkspans.obj"
	-@erase "$(INTDIR)\mkspans.sbr"
	-@erase "$(INTDIR)\mkversion.obj"
	-@erase "$(INTDIR)\mkversion.sbr"
	-@erase "$(INTDIR)\tif_aux.obj"
	-@erase "$(INTDIR)\tif_aux.sbr"
	-@erase "$(INTDIR)\tif_close.obj"
	-@erase "$(INTDIR)\tif_close.sbr"
	-@erase "$(INTDIR)\tif_codec.obj"
	-@erase "$(INTDIR)\tif_codec.sbr"
	-@erase "$(INTDIR)\tif_compress.obj"
	-@erase "$(INTDIR)\tif_compress.sbr"
	-@erase "$(INTDIR)\tif_dir.obj"
	-@erase "$(INTDIR)\tif_dir.sbr"
	-@erase "$(INTDIR)\tif_dirinfo.obj"
	-@erase "$(INTDIR)\tif_dirinfo.sbr"
	-@erase "$(INTDIR)\tif_dirread.obj"
	-@erase "$(INTDIR)\tif_dirread.sbr"
	-@erase "$(INTDIR)\tif_dirwrite.obj"
	-@erase "$(INTDIR)\tif_dirwrite.sbr"
	-@erase "$(INTDIR)\tif_dumpmode.obj"
	-@erase "$(INTDIR)\tif_dumpmode.sbr"
	-@erase "$(INTDIR)\tif_error.obj"
	-@erase "$(INTDIR)\tif_error.sbr"
	-@erase "$(INTDIR)\tif_fax3.obj"
	-@erase "$(INTDIR)\tif_fax3.sbr"
	-@erase "$(INTDIR)\tif_flush.obj"
	-@erase "$(INTDIR)\tif_flush.sbr"
	-@erase "$(INTDIR)\tif_getimage.obj"
	-@erase "$(INTDIR)\tif_getimage.sbr"
	-@erase "$(INTDIR)\tif_jpeg.obj"
	-@erase "$(INTDIR)\tif_jpeg.sbr"
	-@erase "$(INTDIR)\tif_luv.obj"
	-@erase "$(INTDIR)\tif_luv.sbr"
	-@erase "$(INTDIR)\tif_lzw.obj"
	-@erase "$(INTDIR)\tif_lzw.sbr"
	-@erase "$(INTDIR)\tif_next.obj"
	-@erase "$(INTDIR)\tif_next.sbr"
	-@erase "$(INTDIR)\tif_ojpeg.obj"
	-@erase "$(INTDIR)\tif_ojpeg.sbr"
	-@erase "$(INTDIR)\tif_open.obj"
	-@erase "$(INTDIR)\tif_open.sbr"
	-@erase "$(INTDIR)\tif_packbits.obj"
	-@erase "$(INTDIR)\tif_packbits.sbr"
	-@erase "$(INTDIR)\tif_pixarlog.obj"
	-@erase "$(INTDIR)\tif_pixarlog.sbr"
	-@erase "$(INTDIR)\tif_predict.obj"
	-@erase "$(INTDIR)\tif_predict.sbr"
	-@erase "$(INTDIR)\tif_print.obj"
	-@erase "$(INTDIR)\tif_print.sbr"
	-@erase "$(INTDIR)\tif_read.obj"
	-@erase "$(INTDIR)\tif_read.sbr"
	-@erase "$(INTDIR)\tif_strip.obj"
	-@erase "$(INTDIR)\tif_strip.sbr"
	-@erase "$(INTDIR)\tif_swab.obj"
	-@erase "$(INTDIR)\tif_swab.sbr"
	-@erase "$(INTDIR)\tif_thunder.obj"
	-@erase "$(INTDIR)\tif_thunder.sbr"
	-@erase "$(INTDIR)\tif_tile.obj"
	-@erase "$(INTDIR)\tif_tile.sbr"
	-@erase "$(INTDIR)\tif_version.obj"
	-@erase "$(INTDIR)\tif_version.sbr"
	-@erase "$(INTDIR)\tif_warning.obj"
	-@erase "$(INTDIR)\tif_warning.sbr"
	-@erase "$(INTDIR)\tif_win32.obj"
	-@erase "$(INTDIR)\tif_win32.sbr"
	-@erase "$(INTDIR)\tif_write.obj"
	-@erase "$(INTDIR)\tif_write.sbr"
	-@erase "$(INTDIR)\tif_zip.obj"
	-@erase "$(INTDIR)\tif_zip.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\libtiff.bsc"
	-@erase "$(OUTDIR)\libtiff.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

MTL=midl.exe
LINK32=link.exe
CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /I "." /I ".." /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\libtiff.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\libtiff.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\fax3sm_winnt.sbr" \
	"$(INTDIR)\mkg3states.sbr" \
	"$(INTDIR)\mkspans.sbr" \
	"$(INTDIR)\mkversion.sbr" \
	"$(INTDIR)\tif_aux.sbr" \
	"$(INTDIR)\tif_close.sbr" \
	"$(INTDIR)\tif_codec.sbr" \
	"$(INTDIR)\tif_compress.sbr" \
	"$(INTDIR)\tif_dir.sbr" \
	"$(INTDIR)\tif_dirinfo.sbr" \
	"$(INTDIR)\tif_dirread.sbr" \
	"$(INTDIR)\tif_dirwrite.sbr" \
	"$(INTDIR)\tif_dumpmode.sbr" \
	"$(INTDIR)\tif_error.sbr" \
	"$(INTDIR)\tif_fax3.sbr" \
	"$(INTDIR)\tif_flush.sbr" \
	"$(INTDIR)\tif_getimage.sbr" \
	"$(INTDIR)\tif_jpeg.sbr" \
	"$(INTDIR)\tif_luv.sbr" \
	"$(INTDIR)\tif_lzw.sbr" \
	"$(INTDIR)\tif_next.sbr" \
	"$(INTDIR)\tif_ojpeg.sbr" \
	"$(INTDIR)\tif_open.sbr" \
	"$(INTDIR)\tif_packbits.sbr" \
	"$(INTDIR)\tif_pixarlog.sbr" \
	"$(INTDIR)\tif_predict.sbr" \
	"$(INTDIR)\tif_print.sbr" \
	"$(INTDIR)\tif_read.sbr" \
	"$(INTDIR)\tif_strip.sbr" \
	"$(INTDIR)\tif_swab.sbr" \
	"$(INTDIR)\tif_thunder.sbr" \
	"$(INTDIR)\tif_tile.sbr" \
	"$(INTDIR)\tif_version.sbr" \
	"$(INTDIR)\tif_warning.sbr" \
	"$(INTDIR)\tif_win32.sbr" \
	"$(INTDIR)\tif_write.sbr" \
	"$(INTDIR)\tif_zip.sbr"

"$(OUTDIR)\libtiff.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\libtiff.lib" 
LIB32_OBJS= \
	"$(INTDIR)\fax3sm_winnt.obj" \
	"$(INTDIR)\mkg3states.obj" \
	"$(INTDIR)\mkspans.obj" \
	"$(INTDIR)\mkversion.obj" \
	"$(INTDIR)\tif_aux.obj" \
	"$(INTDIR)\tif_close.obj" \
	"$(INTDIR)\tif_codec.obj" \
	"$(INTDIR)\tif_compress.obj" \
	"$(INTDIR)\tif_dir.obj" \
	"$(INTDIR)\tif_dirinfo.obj" \
	"$(INTDIR)\tif_dirread.obj" \
	"$(INTDIR)\tif_dirwrite.obj" \
	"$(INTDIR)\tif_dumpmode.obj" \
	"$(INTDIR)\tif_error.obj" \
	"$(INTDIR)\tif_fax3.obj" \
	"$(INTDIR)\tif_flush.obj" \
	"$(INTDIR)\tif_getimage.obj" \
	"$(INTDIR)\tif_jpeg.obj" \
	"$(INTDIR)\tif_luv.obj" \
	"$(INTDIR)\tif_lzw.obj" \
	"$(INTDIR)\tif_next.obj" \
	"$(INTDIR)\tif_ojpeg.obj" \
	"$(INTDIR)\tif_open.obj" \
	"$(INTDIR)\tif_packbits.obj" \
	"$(INTDIR)\tif_pixarlog.obj" \
	"$(INTDIR)\tif_predict.obj" \
	"$(INTDIR)\tif_print.obj" \
	"$(INTDIR)\tif_read.obj" \
	"$(INTDIR)\tif_strip.obj" \
	"$(INTDIR)\tif_swab.obj" \
	"$(INTDIR)\tif_thunder.obj" \
	"$(INTDIR)\tif_tile.obj" \
	"$(INTDIR)\tif_version.obj" \
	"$(INTDIR)\tif_warning.obj" \
	"$(INTDIR)\tif_win32.obj" \
	"$(INTDIR)\tif_write.obj" \
	"$(INTDIR)\tif_zip.obj"

"$(OUTDIR)\libtiff.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

OUTDIR=.\..\..\lib
INTDIR=.\..\..\_obj\debug
# Begin Custom Macros
OutDir=.\..\..\lib
# End Custom Macros

ALL : "$(OUTDIR)\dlibtiff.lib" "$(OUTDIR)\libtiff.bsc"


CLEAN :
	-@erase "$(INTDIR)\fax3sm_winnt.obj"
	-@erase "$(INTDIR)\fax3sm_winnt.sbr"
	-@erase "$(INTDIR)\mkg3states.obj"
	-@erase "$(INTDIR)\mkg3states.sbr"
	-@erase "$(INTDIR)\mkspans.obj"
	-@erase "$(INTDIR)\mkspans.sbr"
	-@erase "$(INTDIR)\mkversion.obj"
	-@erase "$(INTDIR)\mkversion.sbr"
	-@erase "$(INTDIR)\tif_aux.obj"
	-@erase "$(INTDIR)\tif_aux.sbr"
	-@erase "$(INTDIR)\tif_close.obj"
	-@erase "$(INTDIR)\tif_close.sbr"
	-@erase "$(INTDIR)\tif_codec.obj"
	-@erase "$(INTDIR)\tif_codec.sbr"
	-@erase "$(INTDIR)\tif_compress.obj"
	-@erase "$(INTDIR)\tif_compress.sbr"
	-@erase "$(INTDIR)\tif_dir.obj"
	-@erase "$(INTDIR)\tif_dir.sbr"
	-@erase "$(INTDIR)\tif_dirinfo.obj"
	-@erase "$(INTDIR)\tif_dirinfo.sbr"
	-@erase "$(INTDIR)\tif_dirread.obj"
	-@erase "$(INTDIR)\tif_dirread.sbr"
	-@erase "$(INTDIR)\tif_dirwrite.obj"
	-@erase "$(INTDIR)\tif_dirwrite.sbr"
	-@erase "$(INTDIR)\tif_dumpmode.obj"
	-@erase "$(INTDIR)\tif_dumpmode.sbr"
	-@erase "$(INTDIR)\tif_error.obj"
	-@erase "$(INTDIR)\tif_error.sbr"
	-@erase "$(INTDIR)\tif_fax3.obj"
	-@erase "$(INTDIR)\tif_fax3.sbr"
	-@erase "$(INTDIR)\tif_flush.obj"
	-@erase "$(INTDIR)\tif_flush.sbr"
	-@erase "$(INTDIR)\tif_getimage.obj"
	-@erase "$(INTDIR)\tif_getimage.sbr"
	-@erase "$(INTDIR)\tif_jpeg.obj"
	-@erase "$(INTDIR)\tif_jpeg.sbr"
	-@erase "$(INTDIR)\tif_luv.obj"
	-@erase "$(INTDIR)\tif_luv.sbr"
	-@erase "$(INTDIR)\tif_lzw.obj"
	-@erase "$(INTDIR)\tif_lzw.sbr"
	-@erase "$(INTDIR)\tif_next.obj"
	-@erase "$(INTDIR)\tif_next.sbr"
	-@erase "$(INTDIR)\tif_ojpeg.obj"
	-@erase "$(INTDIR)\tif_ojpeg.sbr"
	-@erase "$(INTDIR)\tif_open.obj"
	-@erase "$(INTDIR)\tif_open.sbr"
	-@erase "$(INTDIR)\tif_packbits.obj"
	-@erase "$(INTDIR)\tif_packbits.sbr"
	-@erase "$(INTDIR)\tif_pixarlog.obj"
	-@erase "$(INTDIR)\tif_pixarlog.sbr"
	-@erase "$(INTDIR)\tif_predict.obj"
	-@erase "$(INTDIR)\tif_predict.sbr"
	-@erase "$(INTDIR)\tif_print.obj"
	-@erase "$(INTDIR)\tif_print.sbr"
	-@erase "$(INTDIR)\tif_read.obj"
	-@erase "$(INTDIR)\tif_read.sbr"
	-@erase "$(INTDIR)\tif_strip.obj"
	-@erase "$(INTDIR)\tif_strip.sbr"
	-@erase "$(INTDIR)\tif_swab.obj"
	-@erase "$(INTDIR)\tif_swab.sbr"
	-@erase "$(INTDIR)\tif_thunder.obj"
	-@erase "$(INTDIR)\tif_thunder.sbr"
	-@erase "$(INTDIR)\tif_tile.obj"
	-@erase "$(INTDIR)\tif_tile.sbr"
	-@erase "$(INTDIR)\tif_version.obj"
	-@erase "$(INTDIR)\tif_version.sbr"
	-@erase "$(INTDIR)\tif_warning.obj"
	-@erase "$(INTDIR)\tif_warning.sbr"
	-@erase "$(INTDIR)\tif_win32.obj"
	-@erase "$(INTDIR)\tif_win32.sbr"
	-@erase "$(INTDIR)\tif_write.obj"
	-@erase "$(INTDIR)\tif_write.sbr"
	-@erase "$(INTDIR)\tif_zip.obj"
	-@erase "$(INTDIR)\tif_zip.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\dlibtiff.lib"
	-@erase "$(OUTDIR)\libtiff.bsc"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

MTL=midl.exe
LINK32=link.exe
CPP=cl.exe
CPP_PROJ=/nologo /MTd /W3 /GX /Z7 /Od /I "." /I ".." /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FAs /Fa"$(INTDIR)\\" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\libtiff.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\libtiff.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\fax3sm_winnt.sbr" \
	"$(INTDIR)\mkg3states.sbr" \
	"$(INTDIR)\mkspans.sbr" \
	"$(INTDIR)\mkversion.sbr" \
	"$(INTDIR)\tif_aux.sbr" \
	"$(INTDIR)\tif_close.sbr" \
	"$(INTDIR)\tif_codec.sbr" \
	"$(INTDIR)\tif_compress.sbr" \
	"$(INTDIR)\tif_dir.sbr" \
	"$(INTDIR)\tif_dirinfo.sbr" \
	"$(INTDIR)\tif_dirread.sbr" \
	"$(INTDIR)\tif_dirwrite.sbr" \
	"$(INTDIR)\tif_dumpmode.sbr" \
	"$(INTDIR)\tif_error.sbr" \
	"$(INTDIR)\tif_fax3.sbr" \
	"$(INTDIR)\tif_flush.sbr" \
	"$(INTDIR)\tif_getimage.sbr" \
	"$(INTDIR)\tif_jpeg.sbr" \
	"$(INTDIR)\tif_luv.sbr" \
	"$(INTDIR)\tif_lzw.sbr" \
	"$(INTDIR)\tif_next.sbr" \
	"$(INTDIR)\tif_ojpeg.sbr" \
	"$(INTDIR)\tif_open.sbr" \
	"$(INTDIR)\tif_packbits.sbr" \
	"$(INTDIR)\tif_pixarlog.sbr" \
	"$(INTDIR)\tif_predict.sbr" \
	"$(INTDIR)\tif_print.sbr" \
	"$(INTDIR)\tif_read.sbr" \
	"$(INTDIR)\tif_strip.sbr" \
	"$(INTDIR)\tif_swab.sbr" \
	"$(INTDIR)\tif_thunder.sbr" \
	"$(INTDIR)\tif_tile.sbr" \
	"$(INTDIR)\tif_version.sbr" \
	"$(INTDIR)\tif_warning.sbr" \
	"$(INTDIR)\tif_win32.sbr" \
	"$(INTDIR)\tif_write.sbr" \
	"$(INTDIR)\tif_zip.sbr"

"$(OUTDIR)\libtiff.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\dlibtiff.lib" 
LIB32_OBJS= \
	"$(INTDIR)\fax3sm_winnt.obj" \
	"$(INTDIR)\mkg3states.obj" \
	"$(INTDIR)\mkspans.obj" \
	"$(INTDIR)\mkversion.obj" \
	"$(INTDIR)\tif_aux.obj" \
	"$(INTDIR)\tif_close.obj" \
	"$(INTDIR)\tif_codec.obj" \
	"$(INTDIR)\tif_compress.obj" \
	"$(INTDIR)\tif_dir.obj" \
	"$(INTDIR)\tif_dirinfo.obj" \
	"$(INTDIR)\tif_dirread.obj" \
	"$(INTDIR)\tif_dirwrite.obj" \
	"$(INTDIR)\tif_dumpmode.obj" \
	"$(INTDIR)\tif_error.obj" \
	"$(INTDIR)\tif_fax3.obj" \
	"$(INTDIR)\tif_flush.obj" \
	"$(INTDIR)\tif_getimage.obj" \
	"$(INTDIR)\tif_jpeg.obj" \
	"$(INTDIR)\tif_luv.obj" \
	"$(INTDIR)\tif_lzw.obj" \
	"$(INTDIR)\tif_next.obj" \
	"$(INTDIR)\tif_ojpeg.obj" \
	"$(INTDIR)\tif_open.obj" \
	"$(INTDIR)\tif_packbits.obj" \
	"$(INTDIR)\tif_pixarlog.obj" \
	"$(INTDIR)\tif_predict.obj" \
	"$(INTDIR)\tif_print.obj" \
	"$(INTDIR)\tif_read.obj" \
	"$(INTDIR)\tif_strip.obj" \
	"$(INTDIR)\tif_swab.obj" \
	"$(INTDIR)\tif_thunder.obj" \
	"$(INTDIR)\tif_tile.obj" \
	"$(INTDIR)\tif_version.obj" \
	"$(INTDIR)\tif_warning.obj" \
	"$(INTDIR)\tif_win32.obj" \
	"$(INTDIR)\tif_write.obj" \
	"$(INTDIR)\tif_zip.obj"

"$(OUTDIR)\dlibtiff.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

OUTDIR=.\APXrel
INTDIR=.\APXrel

ALL : 


CLEAN :
	-@erase 

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\libtiff.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\libtiff.lib" 
LIB32_OBJS= \
	

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

OUTDIR=.\APXdeb
INTDIR=.\APXdeb

ALL : 


CLEAN :
	-@erase 

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\libtiff.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\dlibtiff.lib" 
LIB32_OBJS= \
	

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("libtiff.dep")
!INCLUDE "libtiff.dep"
!ELSE 
!MESSAGE Warning: cannot find "libtiff.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "libtiff - Win32 Release" || "$(CFG)" == "libtiff - Win32 Debug" || "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel" || "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"
SOURCE=..\..\libtiff\fax3sm_winnt.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\fax3sm_winnt.obj"	"$(INTDIR)\fax3sm_winnt.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\fax3sm_winnt.obj"	"$(INTDIR)\fax3sm_winnt.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\mkg3states.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\mkg3states.obj"	"$(INTDIR)\mkg3states.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\mkg3states.obj"	"$(INTDIR)\mkg3states.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\mkspans.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\mkspans.obj"	"$(INTDIR)\mkspans.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\mkspans.obj"	"$(INTDIR)\mkspans.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\mkversion.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\mkversion.obj"	"$(INTDIR)\mkversion.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\mkversion.obj"	"$(INTDIR)\mkversion.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_aux.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_aux.obj"	"$(INTDIR)\tif_aux.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_aux.obj"	"$(INTDIR)\tif_aux.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_close.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_close.obj"	"$(INTDIR)\tif_close.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_close.obj"	"$(INTDIR)\tif_close.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_codec.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_codec.obj"	"$(INTDIR)\tif_codec.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_codec.obj"	"$(INTDIR)\tif_codec.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_compress.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_compress.obj"	"$(INTDIR)\tif_compress.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_compress.obj"	"$(INTDIR)\tif_compress.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_dir.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_dir.obj"	"$(INTDIR)\tif_dir.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_dir.obj"	"$(INTDIR)\tif_dir.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_dirinfo.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_dirinfo.obj"	"$(INTDIR)\tif_dirinfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_dirinfo.obj"	"$(INTDIR)\tif_dirinfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_dirread.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_dirread.obj"	"$(INTDIR)\tif_dirread.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_dirread.obj"	"$(INTDIR)\tif_dirread.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_dirwrite.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_dirwrite.obj"	"$(INTDIR)\tif_dirwrite.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_dirwrite.obj"	"$(INTDIR)\tif_dirwrite.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_dumpmode.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_dumpmode.obj"	"$(INTDIR)\tif_dumpmode.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_dumpmode.obj"	"$(INTDIR)\tif_dumpmode.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_error.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_error.obj"	"$(INTDIR)\tif_error.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_error.obj"	"$(INTDIR)\tif_error.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_fax3.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_fax3.obj"	"$(INTDIR)\tif_fax3.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_fax3.obj"	"$(INTDIR)\tif_fax3.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_flush.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_flush.obj"	"$(INTDIR)\tif_flush.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_flush.obj"	"$(INTDIR)\tif_flush.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_getimage.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_getimage.obj"	"$(INTDIR)\tif_getimage.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_getimage.obj"	"$(INTDIR)\tif_getimage.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_jpeg.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_jpeg.obj"	"$(INTDIR)\tif_jpeg.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_jpeg.obj"	"$(INTDIR)\tif_jpeg.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_luv.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_luv.obj"	"$(INTDIR)\tif_luv.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_luv.obj"	"$(INTDIR)\tif_luv.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_lzw.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_lzw.obj"	"$(INTDIR)\tif_lzw.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_lzw.obj"	"$(INTDIR)\tif_lzw.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_next.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_next.obj"	"$(INTDIR)\tif_next.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_next.obj"	"$(INTDIR)\tif_next.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_ojpeg.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_ojpeg.obj"	"$(INTDIR)\tif_ojpeg.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_ojpeg.obj"	"$(INTDIR)\tif_ojpeg.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_open.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_open.obj"	"$(INTDIR)\tif_open.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_open.obj"	"$(INTDIR)\tif_open.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_packbits.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_packbits.obj"	"$(INTDIR)\tif_packbits.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_packbits.obj"	"$(INTDIR)\tif_packbits.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_pixarlog.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_pixarlog.obj"	"$(INTDIR)\tif_pixarlog.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_pixarlog.obj"	"$(INTDIR)\tif_pixarlog.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_predict.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_predict.obj"	"$(INTDIR)\tif_predict.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_predict.obj"	"$(INTDIR)\tif_predict.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_print.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_print.obj"	"$(INTDIR)\tif_print.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_print.obj"	"$(INTDIR)\tif_print.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_read.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_read.obj"	"$(INTDIR)\tif_read.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_read.obj"	"$(INTDIR)\tif_read.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_strip.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_strip.obj"	"$(INTDIR)\tif_strip.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_strip.obj"	"$(INTDIR)\tif_strip.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_swab.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_swab.obj"	"$(INTDIR)\tif_swab.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_swab.obj"	"$(INTDIR)\tif_swab.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_thunder.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_thunder.obj"	"$(INTDIR)\tif_thunder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_thunder.obj"	"$(INTDIR)\tif_thunder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_tile.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_tile.obj"	"$(INTDIR)\tif_tile.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_tile.obj"	"$(INTDIR)\tif_tile.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_version.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_version.obj"	"$(INTDIR)\tif_version.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_version.obj"	"$(INTDIR)\tif_version.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_warning.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_warning.obj"	"$(INTDIR)\tif_warning.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_warning.obj"	"$(INTDIR)\tif_warning.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_win32.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_win32.obj"	"$(INTDIR)\tif_win32.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_win32.obj"	"$(INTDIR)\tif_win32.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_write.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_write.obj"	"$(INTDIR)\tif_write.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_write.obj"	"$(INTDIR)\tif_write.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

SOURCE=..\..\libtiff\tif_zip.c

!IF  "$(CFG)" == "libtiff - Win32 Release"


"$(INTDIR)\tif_zip.obj"	"$(INTDIR)\tif_zip.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"


"$(INTDIR)\tif_zip.obj"	"$(INTDIR)\tif_zip.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 


!ENDIF 

