; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=viewbar
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Showview.h"
LastPage=0

ClassCount=6
Class1=CShowviewApp
Class2=CShowviewDoc
Class3=CShowviewView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=viewbar
Resource3=IDD_DIALOGBAR (English (U.S.))

[CLS:CShowviewApp]
Type=0
HeaderFile=Showview.h
ImplementationFile=Showview.cpp
Filter=N

[CLS:CShowviewDoc]
Type=0
HeaderFile=ShowviewDoc.h
ImplementationFile=ShowviewDoc.cpp
Filter=N

[CLS:CShowviewView]
Type=0
HeaderFile=ShowviewView.h
ImplementationFile=ShowviewView.cpp
Filter=C
BaseClass=CScrollView
VirtualFilter=VWC
LastObject=ID_Bar


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=Showview.cpp
ImplementationFile=Showview.cpp
Filter=D
LastObject=CAboutDlg

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
Command14=ID_Settimer
Command15=ID_Bar
Command16=ID_VIEW_TOOLBAR
Command17=ID_VIEW_STATUS_BAR
Command18=ID_APP_ABOUT
CommandCount=18

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

[DLG:IDD_DIALOGBAR (English (U.S.))]
Type=1
Class=viewbar
ControlCount=24
Control1=IDC_STATIC,static,1342308353
Control2=IDC_Slope,edit,1350631554
Control3=IDC_STATIC,static,1342308353
Control4=IDC_Kdx,edit,1350631554
Control5=IDC_STATIC,static,1342308353
Control6=IDC_Kpx,edit,1350631554
Control7=IDC_STATIC,static,1342308353
Control8=IDC_Kix,edit,1350631554
Control9=IDC_STATIC,static,1342308353
Control10=IDC_Kdy,edit,1350631554
Control11=IDC_STATIC,static,1342308353
Control12=IDC_Kpy,edit,1350631554
Control13=IDC_STATIC,static,1342308353
Control14=IDC_Kiy,edit,1350631554
Control15=IDC_STATIC,static,1342308353
Control16=IDC_Kdc,edit,1350631554
Control17=IDC_STATIC,static,1342308353
Control18=IDC_Kpc,edit,1350631554
Control19=IDC_STATIC,static,1342308353
Control20=IDC_Kic,edit,1350631554
Control21=IDC_LifeX,edit,1350631552
Control22=IDC_LifeZ,edit,1350631552
Control23=IDC_LifeY,edit,1350631552
Control24=IDC_WorkN,edit,1350631552

[CLS:viewbar]
Type=0
HeaderFile=viewbar.h
ImplementationFile=viewbar.cpp
BaseClass=CDialogBar
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT1

