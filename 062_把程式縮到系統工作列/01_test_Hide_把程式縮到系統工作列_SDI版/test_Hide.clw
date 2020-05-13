; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTest_HideView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "test_Hide.h"
LastPage=0

ClassCount=5
Class1=CTest_HideApp
Class2=CTest_HideDoc
Class3=CTest_HideView
Class4=CMainFrame

ResourceCount=8
Resource1=IDR_MENU1
Resource2=IDD_ABOUTBOX
Resource7=IDR_MAINFRAME
Class5=CAboutDlg
Resource8=IDD_TEST_HIDE_FORM

[CLS:CTest_HideApp]
Type=0
HeaderFile=test_Hide.h
ImplementationFile=test_Hide.cpp
Filter=N

[CLS:CTest_HideDoc]
Type=0
HeaderFile=test_HideDoc.h
ImplementationFile=test_HideDoc.cpp
Filter=N

[CLS:CTest_HideView]
Type=0
HeaderFile=test_HideView.h
ImplementationFile=test_HideView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=IDC_BUTTON2


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_APP_SUSPEND




[CLS:CAboutDlg]
Type=0
HeaderFile=test_Hide.cpp
ImplementationFile=test_Hide.cpp
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

[DLG:IDD_TEST_HIDE_FORM]
Type=1
Class=CTest_HideView
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_BUTTON2,button,1342242816

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

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_APP_OPEN
Command2=ID_APP_ABOUT
Command3=ID_APP_SUSPEND
CommandCount=3

