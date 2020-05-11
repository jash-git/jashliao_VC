; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=OpenGLView
LastTemplate=CView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TestGL.h"
LastPage=0

ClassCount=10
Class1=CTestGLApp
Class2=CTestGLDoc
Class3=CTestGLView
Class4=CMainFrame
Class9=CAboutDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class10=OpenGLView
Resource2=IDD_ABOUTBOX

[CLS:CTestGLApp]
Type=0
HeaderFile=TestGL.h
ImplementationFile=TestGL.cpp
Filter=N

[CLS:CTestGLDoc]
Type=0
HeaderFile=TestGLDoc.h
ImplementationFile=TestGLDoc.cpp
Filter=N

[CLS:CTestGLView]
Type=0
HeaderFile=TestGLView.h
ImplementationFile=TestGLView.cpp
Filter=C
BaseClass=OpenGLView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=TestGL.cpp
ImplementationFile=TestGL.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[CLS:OpenGLView]
Type=0
HeaderFile=OpenGLView.h
ImplementationFile=OpenGLView.cpp
BaseClass=CView
Filter=C
VirtualFilter=VWC

