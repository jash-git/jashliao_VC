; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGlView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "gl.h"
LastPage=0

ClassCount=7
Class1=CGlApp
Class2=CGlDoc
Class3=CGlView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=gl
Resource2=IDR_MAINFRAME
Class7=ControlDialog
Resource3=IDD_DIALOG1

[CLS:CGlApp]
Type=0
HeaderFile=gl.h
ImplementationFile=gl.cpp
Filter=N

[CLS:CGlDoc]
Type=0
HeaderFile=glDoc.h
ImplementationFile=glDoc.cpp
Filter=N

[CLS:CGlView]
Type=0
HeaderFile=glView.h
ImplementationFile=glView.cpp
Filter=C
LastObject=ID_TT
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_input




[CLS:CAboutDlg]
Type=0
HeaderFile=gl.cpp
ImplementationFile=gl.cpp
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
Command14=ID_input
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_APP_ABOUT
CommandCount=17

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
Command8=ID_walkstart
Command9=ID_APP_ABOUT
Command10=ID_TT
CommandCount=10

[CLS:gl]
Type=0
HeaderFile=gl1.h
ImplementationFile=gl1.cpp
BaseClass=CDialog
Filter=D
LastObject=gl
VirtualFilter=dWC

[DLG:IDD_DIALOG1]
Type=1
Class=ControlDialog
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:ControlDialog]
Type=0
HeaderFile=ontrolDialog.h
ImplementationFile=ontrolDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=ControlDialog
VirtualFilter=dWC

