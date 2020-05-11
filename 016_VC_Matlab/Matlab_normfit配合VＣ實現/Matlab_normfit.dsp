# Microsoft Developer Studio Project File - Name="Matlab_normfit" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Matlab_normfit - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Matlab_normfit.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Matlab_normfit.mak" CFG="Matlab_normfit - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Matlab_normfit - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Matlab_normfit - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Matlab_normfit - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x404 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x404 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Matlab_normfit - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "MSVC" /D "IBMPC" /D "MSWIND" /YX"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x404 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x404 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 libmmfile.lib libmatlb.lib libmx.lib libmat.lib libmatpm.lib sgl.lib libmwsglm.lib libmwservices.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Matlab_normfit - Win32 Release"
# Name "Matlab_normfit - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\normfit_C\betacdf.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\betacore.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\betainc.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\betainv.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\betaln.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\betapdf.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\cellfun_mex_interface.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\chi2inv.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\distchck.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\erfc.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\erfcinv.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\erfcore_mex_interface.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\gamcdf.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\gaminv.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\gammainc.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\gammaln_mex_interface.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\gampdf.cpp
# End Source File
# Begin Source File

SOURCE=.\Matlab_normfit.cpp
# End Source File
# Begin Source File

SOURCE=.\Matlab_normfit.rc
# End Source File
# Begin Source File

SOURCE=.\Matlab_normfitDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\mean.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\normfit.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\norminv.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\realmax.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\repmat.cpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\std.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\normfit_C\tinv.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\normfit_C\betacdf.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\betacore.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\betainc.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\betainv.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\betaln.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\betapdf.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\cellfun_mex_interface.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\chi2inv.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\distchck.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\erfc.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\erfcinv.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\erfcore_mex_interface.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\gamcdf.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\gaminv.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\gammainc.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\gammaln_mex_interface.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\gampdf.hpp
# End Source File
# Begin Source File

SOURCE=.\Matlab_normfit.h
# End Source File
# Begin Source File

SOURCE=.\Matlab_normfitDlg.h
# End Source File
# Begin Source File

SOURCE=.\normfit_C\mean.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\normfit.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\norminv.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\realmax.hpp
# End Source File
# Begin Source File

SOURCE=.\normfit_C\repmat.hpp
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\normfit_C\std.hpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\normfit_C\tinv.hpp
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\Matlab_normfit.ico
# End Source File
# Begin Source File

SOURCE=.\res\Matlab_normfit.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
