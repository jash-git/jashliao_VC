# Microsoft Developer Studio Project File - Name="testMySQL" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=testMySQL - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "testMySQL.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "testMySQL.mak" CFG="testMySQL - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "testMySQL - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "testMySQL - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "testMySQL - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "testMySQL - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "_DEBUG"
# ADD RSC /l 0x404 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "testMySQL - Win32 Release"
# Name "testMySQL - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\testMySQL.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=".\mysql++.h"
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\bad_query.hh
# End Source File
# Begin Source File

SOURCE=.\coldata1.hh
# End Source File
# Begin Source File

SOURCE=.\coldata2.hh
# End Source File
# Begin Source File

SOURCE=.\coldata3.hh
# End Source File
# Begin Source File

SOURCE=.\coldata4.hh
# End Source File
# Begin Source File

SOURCE=.\compare1.hh
# End Source File
# Begin Source File

SOURCE=.\compare2.hh
# End Source File
# Begin Source File

SOURCE=.\compare3.hh
# End Source File
# Begin Source File

SOURCE=.\connection0.hh
# End Source File
# Begin Source File

SOURCE=.\connection1.hh
# End Source File
# Begin Source File

SOURCE=.\connection2.hh
# End Source File
# Begin Source File

SOURCE=.\connection3.hh
# End Source File
# Begin Source File

SOURCE=.\const_string1.hh
# End Source File
# Begin Source File

SOURCE=.\const_string2.hh
# End Source File
# Begin Source File

SOURCE=.\const_string3.hh
# End Source File
# Begin Source File

SOURCE=.\convert1.hh
# End Source File
# Begin Source File

SOURCE=.\convert2.hh
# End Source File
# Begin Source File

SOURCE=.\convert3.hh
# End Source File
# Begin Source File

SOURCE=".\custom-macros.hh"
# End Source File
# Begin Source File

SOURCE=.\custom.hh
# End Source File
# Begin Source File

SOURCE=.\datetime1.hh
# End Source File
# Begin Source File

SOURCE=.\datetime2.hh
# End Source File
# Begin Source File

SOURCE=.\field_names1.hh
# End Source File
# Begin Source File

SOURCE=.\field_names2.hh
# End Source File
# Begin Source File

SOURCE=.\field_names3.hh
# End Source File
# Begin Source File

SOURCE=.\field_types1.hh
# End Source File
# Begin Source File

SOURCE=.\field_types2.hh
# End Source File
# Begin Source File

SOURCE=.\field_types3.hh
# End Source File
# Begin Source File

SOURCE=.\fields1.hh
# End Source File
# Begin Source File

SOURCE=.\fields2.hh
# End Source File
# Begin Source File

SOURCE=.\manip1.hh
# End Source File
# Begin Source File

SOURCE=.\manip2.hh
# End Source File
# Begin Source File

SOURCE=.\manip3.hh
# End Source File
# Begin Source File

SOURCE=".\mysql++"
# End Source File
# Begin Source File

SOURCE=.\null1.hh
# End Source File
# Begin Source File

SOURCE=.\null2.hh
# End Source File
# Begin Source File

SOURCE=.\null3.hh
# End Source File
# Begin Source File

SOURCE=.\query1.hh
# End Source File
# Begin Source File

SOURCE=.\query2.hh
# End Source File
# Begin Source File

SOURCE=.\query3.hh
# End Source File
# Begin Source File

SOURCE=.\resiter1.hh
# End Source File
# Begin Source File

SOURCE=.\result1.hh
# End Source File
# Begin Source File

SOURCE=.\result2.hh
# End Source File
# Begin Source File

SOURCE=.\result3.hh
# End Source File
# Begin Source File

SOURCE=.\row1.hh
# End Source File
# Begin Source File

SOURCE=.\row2.hh
# End Source File
# Begin Source File

SOURCE=.\row3.hh
# End Source File
# Begin Source File

SOURCE=.\set1.hh
# End Source File
# Begin Source File

SOURCE=.\set2.hh
# End Source File
# Begin Source File

SOURCE=.\set3.hh
# End Source File
# Begin Source File

SOURCE=.\sql_query0.hh
# End Source File
# Begin Source File

SOURCE=.\sql_query1.hh
# End Source File
# Begin Source File

SOURCE=.\sql_query2.hh
# End Source File
# Begin Source File

SOURCE=.\sql_query3.hh
# End Source File
# Begin Source File

SOURCE=.\sql_string1.hh
# End Source File
# Begin Source File

SOURCE=.\sql_string2.hh
# End Source File
# Begin Source File

SOURCE=.\sql_string3.hh
# End Source File
# Begin Source File

SOURCE=.\sqlplus.hh
# End Source File
# Begin Source File

SOURCE=.\stream2string1.hh
# End Source File
# Begin Source File

SOURCE=.\stream2string2.hh
# End Source File
# Begin Source File

SOURCE=.\stream2string3.hh
# End Source File
# Begin Source File

SOURCE=.\string_util.hh
# End Source File
# Begin Source File

SOURCE=.\tiny_int1.hh
# End Source File
# Begin Source File

SOURCE=.\tiny_int2.hh
# End Source File
# Begin Source File

SOURCE=.\tiny_int3.hh
# End Source File
# Begin Source File

SOURCE=.\type_info1.hh
# End Source File
# Begin Source File

SOURCE=.\type_info2.hh
# End Source File
# Begin Source File

SOURCE=.\type_info3.hh
# End Source File
# Begin Source File

SOURCE=.\vallist1.hh
# End Source File
# Begin Source File

SOURCE=.\vallist2.hh
# End Source File
# Begin Source File

SOURCE=.\vallist3.hh
# End Source File
# Begin Source File

SOURCE=".\mysql++.lib"
# End Source File
# Begin Source File

SOURCE=.\libmySQL.lib
# End Source File
# End Target
# End Project
