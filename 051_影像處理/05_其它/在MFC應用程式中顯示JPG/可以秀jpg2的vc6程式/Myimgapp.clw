; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Myimgapp.h"
LastPage=0

ClassCount=5
Class1=CMyApp
Class2=CPictureDoc
Class3=CPictureView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDR_FILEDROPDOWN
Resource3=IDD_ABOUTBOX

[CLS:CMyApp]
Type=0
HeaderFile=Myimgapp.h
ImplementationFile=Myimgapp.cpp
Filter=N

[CLS:CPictureDoc]
Type=0
HeaderFile=Doc.h
ImplementationFile=Doc.cpp
Filter=N

[CLS:CPictureView]
Type=0
HeaderFile=View.h
ImplementationFile=View.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_VIEW_TOOLBAR




[CLS:CAboutDlg]
Type=0
HeaderFile=Myimgapp.cpp
ImplementationFile=Myimgapp.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=8
Control1=IDC_STATIC_ICON,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDB_STATIC_IMG,static,1350565902
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC_TEXT,static,1342308352
Control6=IDOK,button,1342373889
Control7=IDC_STATIC_MAIL,static,1342308352
Control8=IDC_IMAGEMYDOG,static,1342181383

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_OPEN
Command2=ID_FILE_MRU_FILE1
Command3=ID_APP_EXIT
Command4=ID_VIEW25
Command5=ID_VIEW33
Command6=ID_VIEW50
Command7=ID_VIEW75
Command8=ID_VIEW100
Command9=ID_VIEW_TOFIT
Command10=ID_VIEW_TOOLBAR
Command11=ID_VIEW_STATUS_BAR
Command12=ID_APP_ABOUT
CommandCount=12

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
Class=?
Command1=ID_FILE_OPEN
Command2=ID_VIEW25
Command3=ID_VIEW33
Command4=ID_VIEW50
Command5=ID_VIEW75
Command6=ID_VIEW100
Command7=ID_VIEW_TOFIT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_FILEDROPDOWN]
Type=1
Class=?
Command1=ID_FILE_MRU_FILE1
CommandCount=1

