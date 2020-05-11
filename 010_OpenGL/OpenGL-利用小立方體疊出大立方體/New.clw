; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNewView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "New.h"
LastPage=0

ClassCount=7
Class1=CNewApp
Class2=CNewDoc
Class3=CNewView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=viewbar
Class7=CSplashWnd
Resource3=IDD_DIALOGBAR (English (U.S.))

[CLS:CNewApp]
Type=0
HeaderFile=New.h
ImplementationFile=New.cpp
Filter=N

[CLS:CNewDoc]
Type=0
HeaderFile=NewDoc.h
ImplementationFile=NewDoc.cpp
Filter=N

[CLS:CNewView]
Type=0
HeaderFile=NewView.h
ImplementationFile=NewView.cpp
Filter=C
LastObject=ID_test
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_Front1




[CLS:CAboutDlg]
Type=0
HeaderFile=New.cpp
ImplementationFile=New.cpp
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
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_shiftX
Command10=ID_shiftY
Command11=ID_shiftZ
Command12=ID_watch_R
Command13=ID_TimerStart
Command14=ID_Front
Command15=ID_Flank
Command16=ID_Front1
Command17=ID_Flank1
Command18=ID_Bar
CommandCount=18

[DLG:IDD_DIALOGBAR (English (U.S.))]
Type=1
Class=viewbar
ControlCount=18
Control1=IDC_EDIT1,edit,1350631554
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT2,edit,1350631554
Control8=IDC_EDIT3,edit,1350631554
Control9=IDC_EDIT4,edit,1350631554
Control10=IDC_EDIT5,edit,1350631554
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_Pxr3,edit,1350631554
Control15=IDC_Pyr3,edit,1350631554
Control16=IDC_Pzr3,edit,1350631554
Control17=IDC_STATIC,static,1342308352
Control18=IDC_Theta,edit,1350631554

[CLS:viewbar]
Type=0
HeaderFile=viewbar.h
ImplementationFile=viewbar.cpp
BaseClass=CDialogBar
Filter=D
LastObject=ID_APP_ABOUT
VirtualFilter=dWC

[CLS:CSplashWnd]
Type=0
HeaderFile=Splash.h
ImplementationFile=Splash.cpp
BaseClass=CWnd
LastObject=CSplashWnd

