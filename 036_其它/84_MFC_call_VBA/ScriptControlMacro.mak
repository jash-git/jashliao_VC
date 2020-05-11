# Microsoft Developer Studio Generated NMAKE File, Based on ScriptControlMacro.dsp
!IF "$(CFG)" == ""
CFG=ScriptControlMacro - Win32 Debug
!MESSAGE No configuration specified. Defaulting to ScriptControlMacro - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "ScriptControlMacro - Win32 Release" && "$(CFG)" != "ScriptControlMacro - Win32 Debug" && "$(CFG)" != "ScriptControlMacro - Win32 Unicode Release" && "$(CFG)" != "ScriptControlMacro - Win32 Unicode Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ScriptControlMacro.mak" CFG="ScriptControlMacro - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ScriptControlMacro - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ScriptControlMacro - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "ScriptControlMacro - Win32 Unicode Release" (based on "Win32 (x86) Application")
!MESSAGE "ScriptControlMacro - Win32 Unicode Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ScriptControlMacro - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\ScriptControlMacro.exe" "$(OUTDIR)\ScriptControlMacro.bsc"


CLEAN :
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\ChildFrm.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\MSScriptControl.obj"
	-@erase "$(INTDIR)\MSScriptControl.sbr"
	-@erase "$(INTDIR)\MultiDocTemplate.obj"
	-@erase "$(INTDIR)\MultiDocTemplate.sbr"
	-@erase "$(INTDIR)\ScriptControlMacro.obj"
	-@erase "$(INTDIR)\ScriptControlMacro.pch"
	-@erase "$(INTDIR)\ScriptControlMacro.res"
	-@erase "$(INTDIR)\ScriptControlMacro.sbr"
	-@erase "$(INTDIR)\ScriptControlMacroDispatch.obj"
	-@erase "$(INTDIR)\ScriptControlMacroDispatch.sbr"
	-@erase "$(INTDIR)\ScriptControlMacroDoc.obj"
	-@erase "$(INTDIR)\ScriptControlMacroDoc.sbr"
	-@erase "$(INTDIR)\ScriptControlMacroView.obj"
	-@erase "$(INTDIR)\ScriptControlMacroView.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ScriptControlMacro.bsc"
	-@erase "$(OUTDIR)\ScriptControlMacro.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /Zp1 /MD /W3 /GX /O1 /Op /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D _WIN32_WINNT=0x0500 /D WINVER=0x400 /D _WIN32_WINDOWS=0x400 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ScriptControlMacro.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ScriptControlMacro.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ScriptControlMacro.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ChildFrm.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\MSScriptControl.sbr" \
	"$(INTDIR)\MultiDocTemplate.sbr" \
	"$(INTDIR)\ScriptControlMacro.sbr" \
	"$(INTDIR)\ScriptControlMacroDispatch.sbr" \
	"$(INTDIR)\ScriptControlMacroDoc.sbr" \
	"$(INTDIR)\ScriptControlMacroView.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\ScriptControlMacro.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\ScriptControlMacro.pdb" /machine:I386 /out:"$(OUTDIR)\ScriptControlMacro.exe" /opt:nowin98,ref /ignore:4078 /merge:.rdata=.text /release 
LINK32_OBJS= \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MSScriptControl.obj" \
	"$(INTDIR)\MultiDocTemplate.obj" \
	"$(INTDIR)\ScriptControlMacro.obj" \
	"$(INTDIR)\ScriptControlMacroDispatch.obj" \
	"$(INTDIR)\ScriptControlMacroDoc.obj" \
	"$(INTDIR)\ScriptControlMacroView.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ScriptControlMacro.res"

"$(OUTDIR)\ScriptControlMacro.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ScriptControlMacro - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ScriptControlMacro.exe" "$(OUTDIR)\ScriptControlMacro.bsc"


CLEAN :
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\ChildFrm.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\MSScriptControl.obj"
	-@erase "$(INTDIR)\MSScriptControl.sbr"
	-@erase "$(INTDIR)\MultiDocTemplate.obj"
	-@erase "$(INTDIR)\MultiDocTemplate.sbr"
	-@erase "$(INTDIR)\ScriptControlMacro.obj"
	-@erase "$(INTDIR)\ScriptControlMacro.pch"
	-@erase "$(INTDIR)\ScriptControlMacro.res"
	-@erase "$(INTDIR)\ScriptControlMacro.sbr"
	-@erase "$(INTDIR)\ScriptControlMacroDispatch.obj"
	-@erase "$(INTDIR)\ScriptControlMacroDispatch.sbr"
	-@erase "$(INTDIR)\ScriptControlMacroDoc.obj"
	-@erase "$(INTDIR)\ScriptControlMacroDoc.sbr"
	-@erase "$(INTDIR)\ScriptControlMacroView.obj"
	-@erase "$(INTDIR)\ScriptControlMacroView.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ScriptControlMacro.bsc"
	-@erase "$(OUTDIR)\ScriptControlMacro.exe"
	-@erase "$(OUTDIR)\ScriptControlMacro.ilk"
	-@erase "$(OUTDIR)\ScriptControlMacro.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /Zp1 /MDd /W3 /Gm /GR /GX /ZI /Op /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D WINVER=0x400 /D _WIN32_WINDOWS=0x400 /D _WIN32_WINNT=0x0500 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ScriptControlMacro.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ScriptControlMacro.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ScriptControlMacro.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ChildFrm.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\MSScriptControl.sbr" \
	"$(INTDIR)\MultiDocTemplate.sbr" \
	"$(INTDIR)\ScriptControlMacro.sbr" \
	"$(INTDIR)\ScriptControlMacroDispatch.sbr" \
	"$(INTDIR)\ScriptControlMacroDoc.sbr" \
	"$(INTDIR)\ScriptControlMacroView.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\ScriptControlMacro.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\ScriptControlMacro.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ScriptControlMacro.exe" /pdbtype:sept /opt:nowin98 /ignore:4078 /merge:.rdata=.text 
LINK32_OBJS= \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MSScriptControl.obj" \
	"$(INTDIR)\MultiDocTemplate.obj" \
	"$(INTDIR)\ScriptControlMacro.obj" \
	"$(INTDIR)\ScriptControlMacroDispatch.obj" \
	"$(INTDIR)\ScriptControlMacroDoc.obj" \
	"$(INTDIR)\ScriptControlMacroView.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ScriptControlMacro.res"

"$(OUTDIR)\ScriptControlMacro.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ScriptControlMacro - Win32 Unicode Release"

OUTDIR=.\ScriptControlMacro___Win32_Unicode_Release
INTDIR=.\ScriptControlMacro___Win32_Unicode_Release
# Begin Custom Macros
OutDir=.\ScriptControlMacro___Win32_Unicode_Release
# End Custom Macros

ALL : "$(OUTDIR)\ScriptControlMacro.exe" "$(OUTDIR)\ScriptControlMacro.bsc"


CLEAN :
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\ChildFrm.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\MSScriptControl.obj"
	-@erase "$(INTDIR)\MSScriptControl.sbr"
	-@erase "$(INTDIR)\MultiDocTemplate.obj"
	-@erase "$(INTDIR)\MultiDocTemplate.sbr"
	-@erase "$(INTDIR)\ScriptControlMacro.obj"
	-@erase "$(INTDIR)\ScriptControlMacro.pch"
	-@erase "$(INTDIR)\ScriptControlMacro.res"
	-@erase "$(INTDIR)\ScriptControlMacro.sbr"
	-@erase "$(INTDIR)\ScriptControlMacroDispatch.obj"
	-@erase "$(INTDIR)\ScriptControlMacroDispatch.sbr"
	-@erase "$(INTDIR)\ScriptControlMacroDoc.obj"
	-@erase "$(INTDIR)\ScriptControlMacroDoc.sbr"
	-@erase "$(INTDIR)\ScriptControlMacroView.obj"
	-@erase "$(INTDIR)\ScriptControlMacroView.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ScriptControlMacro.bsc"
	-@erase "$(OUTDIR)\ScriptControlMacro.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /Zp1 /MD /W3 /GX /O1 /Op /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D _WIN32_WINNT=0x0500 /D WINVER=0x400 /D _WIN32_WINDOWS=0x400 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ScriptControlMacro.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ScriptControlMacro.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ScriptControlMacro.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ChildFrm.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\MSScriptControl.sbr" \
	"$(INTDIR)\MultiDocTemplate.sbr" \
	"$(INTDIR)\ScriptControlMacro.sbr" \
	"$(INTDIR)\ScriptControlMacroDispatch.sbr" \
	"$(INTDIR)\ScriptControlMacroDoc.sbr" \
	"$(INTDIR)\ScriptControlMacroView.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\ScriptControlMacro.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\ScriptControlMacro.pdb" /machine:I386 /out:"$(OUTDIR)\ScriptControlMacro.exe" /opt:nowin98,ref /ignore:4078 /merge:.rdata=.text /release 
LINK32_OBJS= \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MSScriptControl.obj" \
	"$(INTDIR)\MultiDocTemplate.obj" \
	"$(INTDIR)\ScriptControlMacro.obj" \
	"$(INTDIR)\ScriptControlMacroDispatch.obj" \
	"$(INTDIR)\ScriptControlMacroDoc.obj" \
	"$(INTDIR)\ScriptControlMacroView.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ScriptControlMacro.res"

"$(OUTDIR)\ScriptControlMacro.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ScriptControlMacro - Win32 Unicode Debug"

OUTDIR=.\ScriptControlMacro___Win32_Unicode_Debug
INTDIR=.\ScriptControlMacro___Win32_Unicode_Debug
# Begin Custom Macros
OutDir=.\ScriptControlMacro___Win32_Unicode_Debug
# End Custom Macros

ALL : "$(OUTDIR)\ScriptControlMacro.exe" "$(OUTDIR)\ScriptControlMacro.bsc"


CLEAN :
	-@erase "$(INTDIR)\ChildFrm.obj"
	-@erase "$(INTDIR)\ChildFrm.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\MSScriptControl.obj"
	-@erase "$(INTDIR)\MSScriptControl.sbr"
	-@erase "$(INTDIR)\MultiDocTemplate.obj"
	-@erase "$(INTDIR)\MultiDocTemplate.sbr"
	-@erase "$(INTDIR)\ScriptControlMacro.obj"
	-@erase "$(INTDIR)\ScriptControlMacro.pch"
	-@erase "$(INTDIR)\ScriptControlMacro.res"
	-@erase "$(INTDIR)\ScriptControlMacro.sbr"
	-@erase "$(INTDIR)\ScriptControlMacroDispatch.obj"
	-@erase "$(INTDIR)\ScriptControlMacroDispatch.sbr"
	-@erase "$(INTDIR)\ScriptControlMacroDoc.obj"
	-@erase "$(INTDIR)\ScriptControlMacroDoc.sbr"
	-@erase "$(INTDIR)\ScriptControlMacroView.obj"
	-@erase "$(INTDIR)\ScriptControlMacroView.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ScriptControlMacro.bsc"
	-@erase "$(OUTDIR)\ScriptControlMacro.exe"
	-@erase "$(OUTDIR)\ScriptControlMacro.ilk"
	-@erase "$(OUTDIR)\ScriptControlMacro.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /Zp1 /MDd /W3 /Gm /GR /GX /ZI /Op /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D WINVER=0x400 /D _WIN32_WINDOWS=0x400 /D _WIN32_WINNT=0x0500 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ScriptControlMacro.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\ScriptControlMacro.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ScriptControlMacro.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ChildFrm.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\MSScriptControl.sbr" \
	"$(INTDIR)\MultiDocTemplate.sbr" \
	"$(INTDIR)\ScriptControlMacro.sbr" \
	"$(INTDIR)\ScriptControlMacroDispatch.sbr" \
	"$(INTDIR)\ScriptControlMacroDoc.sbr" \
	"$(INTDIR)\ScriptControlMacroView.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\ScriptControlMacro.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\ScriptControlMacro.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ScriptControlMacro.exe" /pdbtype:sept /opt:nowin98 /ignore:4078 /merge:.rdata=.text 
LINK32_OBJS= \
	"$(INTDIR)\ChildFrm.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\MSScriptControl.obj" \
	"$(INTDIR)\MultiDocTemplate.obj" \
	"$(INTDIR)\ScriptControlMacro.obj" \
	"$(INTDIR)\ScriptControlMacroDispatch.obj" \
	"$(INTDIR)\ScriptControlMacroDoc.obj" \
	"$(INTDIR)\ScriptControlMacroView.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ScriptControlMacro.res"

"$(OUTDIR)\ScriptControlMacro.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("ScriptControlMacro.dep")
!INCLUDE "ScriptControlMacro.dep"
!ELSE 
!MESSAGE Warning: cannot find "ScriptControlMacro.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "ScriptControlMacro - Win32 Release" || "$(CFG)" == "ScriptControlMacro - Win32 Debug" || "$(CFG)" == "ScriptControlMacro - Win32 Unicode Release" || "$(CFG)" == "ScriptControlMacro - Win32 Unicode Debug"
SOURCE=.\ChildFrm.cpp

"$(INTDIR)\ChildFrm.obj"	"$(INTDIR)\ChildFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ScriptControlMacro.pch"


SOURCE=.\MainFrm.cpp

"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ScriptControlMacro.pch"


SOURCE=.\MSScriptControl.cpp

"$(INTDIR)\MSScriptControl.obj"	"$(INTDIR)\MSScriptControl.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ScriptControlMacro.pch"


SOURCE=.\MultiDocTemplate.cpp

"$(INTDIR)\MultiDocTemplate.obj"	"$(INTDIR)\MultiDocTemplate.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ScriptControlMacro.pch"


SOURCE=.\ScriptControlMacro.cpp

"$(INTDIR)\ScriptControlMacro.obj"	"$(INTDIR)\ScriptControlMacro.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ScriptControlMacro.pch"


SOURCE=.\ScriptControlMacroDispatch.cpp

"$(INTDIR)\ScriptControlMacroDispatch.obj"	"$(INTDIR)\ScriptControlMacroDispatch.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ScriptControlMacro.pch"


SOURCE=.\ScriptControlMacroDoc.cpp

"$(INTDIR)\ScriptControlMacroDoc.obj"	"$(INTDIR)\ScriptControlMacroDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ScriptControlMacro.pch"


SOURCE=.\ScriptControlMacroView.cpp

"$(INTDIR)\ScriptControlMacroView.obj"	"$(INTDIR)\ScriptControlMacroView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ScriptControlMacro.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "ScriptControlMacro - Win32 Release"

CPP_SWITCHES=/nologo /Zp1 /MD /W3 /GX /O1 /Op /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D _WIN32_WINNT=0x0500 /D WINVER=0x400 /D _WIN32_WINDOWS=0x400 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ScriptControlMacro.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\ScriptControlMacro.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ScriptControlMacro - Win32 Debug"

CPP_SWITCHES=/nologo /Zp1 /MDd /W3 /Gm /GR /GX /ZI /Op /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D WINVER=0x400 /D _WIN32_WINDOWS=0x400 /D _WIN32_WINNT=0x0500 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ScriptControlMacro.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\ScriptControlMacro.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ScriptControlMacro - Win32 Unicode Release"

CPP_SWITCHES=/nologo /Zp1 /MD /W3 /GX /O1 /Op /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D _WIN32_WINNT=0x0500 /D WINVER=0x400 /D _WIN32_WINDOWS=0x400 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ScriptControlMacro.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\ScriptControlMacro.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ScriptControlMacro - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /Zp1 /MDd /W3 /Gm /GR /GX /ZI /Op /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D WINVER=0x400 /D _WIN32_WINDOWS=0x400 /D _WIN32_WINNT=0x0500 /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ScriptControlMacro.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\ScriptControlMacro.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\ScriptControlMacro.rc

"$(INTDIR)\ScriptControlMacro.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

