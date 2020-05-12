# Microsoft Developer Studio Generated NMAKE File, Based on TiFFToPdf.dsp
!IF "$(CFG)" == ""
CFG=TiFFToPdf - Win32 Debug
!MESSAGE No configuration specified. Defaulting to TiFFToPdf - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "TiFFToPdf - Win32 Release" && "$(CFG)" != "TiFFToPdf - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TiFFToPdf.mak" CFG="TiFFToPdf - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TiFFToPdf - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "TiFFToPdf - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TiFFToPdf - Win32 Release"

OUTDIR=.\..\_bin\release\static
INTDIR=.\..\_obj\release\tifftopdf
# Begin Custom Macros
OutDir=.\..\_bin\release\static
# End Custom Macros

ALL : "$(OUTDIR)\TiFFToPdf.exe"


CLEAN :
	-@erase "$(INTDIR)\dtimageinfo.obj"
	-@erase "$(INTDIR)\dtpdfconvert.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TiFFToPdf.obj"
	-@erase "$(INTDIR)\TiFFToPdf.pch"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\TiFFToPdf.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\TiFFToPdf.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TiFFToPdf.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=llibtiff.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\TiFFToPdf.pdb" /machine:I386 /out:"$(OUTDIR)\TiFFToPdf.exe" 
LINK32_OBJS= \
	"$(INTDIR)\dtimageinfo.obj" \
	"$(INTDIR)\dtpdfconvert.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TiFFToPdf.obj"

"$(OUTDIR)\TiFFToPdf.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "TiFFToPdf - Win32 Debug"

OUTDIR=.\..\_bin\debug
INTDIR=.\..\_obj\debug\tifftopdf
# Begin Custom Macros
OutDir=.\..\_bin\debug
# End Custom Macros

ALL : "$(OUTDIR)\TiFFToPdf.exe"


CLEAN :
	-@erase "$(INTDIR)\dtimageinfo.obj"
	-@erase "$(INTDIR)\dtpdfconvert.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\TiFFToPdf.obj"
	-@erase "$(INTDIR)\TiFFToPdf.pch"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\TiFFToPdf.exe"
	-@erase "$(OUTDIR)\TiFFToPdf.ilk"
	-@erase "$(OUTDIR)\TiFFToPdf.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\TiFFToPdf.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\TiFFToPdf.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=dlibtiff.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\TiFFToPdf.pdb" /debug /machine:I386 /nodefaultlib:"libcmtd.lib" /out:"$(OUTDIR)\TiFFToPdf.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\dtimageinfo.obj" \
	"$(INTDIR)\dtpdfconvert.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\TiFFToPdf.obj"

"$(OUTDIR)\TiFFToPdf.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

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


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("TiFFToPdf.dep")
!INCLUDE "TiFFToPdf.dep"
!ELSE 
!MESSAGE Warning: cannot find "TiFFToPdf.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "TiFFToPdf - Win32 Release" || "$(CFG)" == "TiFFToPdf - Win32 Debug"
SOURCE=.\dtimageinfo.cpp

"$(INTDIR)\dtimageinfo.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TiFFToPdf.pch"


SOURCE=.\dtpdfconvert.cpp

"$(INTDIR)\dtpdfconvert.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TiFFToPdf.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "TiFFToPdf - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\TiFFToPdf.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\TiFFToPdf.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "TiFFToPdf - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "_AFXDLL" /Fp"$(INTDIR)\TiFFToPdf.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\TiFFToPdf.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\TiFFToPdf.cpp

"$(INTDIR)\TiFFToPdf.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\TiFFToPdf.pch"



!ENDIF 

