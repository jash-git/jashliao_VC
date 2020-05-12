# Microsoft Developer Studio Project File - Name="libtiff" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (ALPHA) Static Library" 0x0604
# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=libtiff - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "libtiff.mak".
!MESSAGE 
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

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""

!IF  "$(CFG)" == "libtiff - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "..\..\_obj\release"
MTL=midl.exe
LINK32=link.exe
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /YX /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "." /I ".." /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /YX /FD /c
RSC=rc.exe
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\lib"
# PROP Intermediate_Dir "..\..\_obj\debug"
MTL=midl.exe
LINK32=link.exe
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /YX /c
# ADD CPP /nologo /MTd /W3 /GX /Z7 /Od /I "." /I ".." /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FAs /FR /YX /FD /c
RSC=rc.exe
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\lib\dlibtiff.lib"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "APXrel"
# PROP BASE Intermediate_Dir "APXrel"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "APXrel"
# PROP Intermediate_Dir "APXrel"
CPP=cl.exe
# ADD BASE CPP /nologo /ML /Gt0 /W3 /GX /YX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /MT /Gt0 /W3 /GX /YX /O2 /I ".." /I "." /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /c
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "APXdeb"
# PROP BASE Intermediate_Dir "APXdeb"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "APXdeb"
# PROP Intermediate_Dir "APXdeb"
CPP=cl.exe
# ADD BASE CPP /nologo /ML /Gt0 /W3 /GX /Z7 /YX /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /MT /Gt0 /W3 /GX /Z7 /YX /Od /I ".." /I "." /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /c
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"APXdeb\dlibtiff.lib"

!ENDIF 

# Begin Target

# Name "libtiff - Win32 Release"
# Name "libtiff - Win32 Debug"
# Name "libtiff - Win32 (ALPHA) APXrel"
# Name "libtiff - Win32 (ALPHA) APXdeb"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=..\..\libtiff\fax3sm_winnt.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\mkg3states.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\mkspans.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\mkversion.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_aux.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_close.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_codec.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_compress.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_dir.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_dirinfo.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_dirread.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_dirwrite.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_dumpmode.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_error.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_fax3.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_flush.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_getimage.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_jpeg.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_luv.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_lzw.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_next.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_ojpeg.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_open.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_packbits.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_pixarlog.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_predict.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_print.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_read.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_strip.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_swab.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_thunder.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_tile.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_version.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_warning.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_win32.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_write.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_zip.c

!IF  "$(CFG)" == "libtiff - Win32 Release"

!ELSEIF  "$(CFG)" == "libtiff - Win32 Debug"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXrel"

!ELSEIF  "$(CFG)" == "libtiff - Win32 (ALPHA) APXdeb"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=..\..\libtiff\t4.h
# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_dir.h
# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_fax3.h
# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tif_predict.h
# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tiff.h
# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tiffcomp.h
# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tiffconf.h
# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tiffio.h
# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tiffiop.h
# End Source File
# Begin Source File

SOURCE=..\..\libtiff\tiffvers.h
# End Source File
# Begin Source File

SOURCE=..\..\libtiff\uvcode.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\libtiff.def
# End Source File
# End Target
# End Project
