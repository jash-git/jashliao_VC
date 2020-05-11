; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CShowGPSData
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFCPaPaGo.h"
LastPage=0

ClassCount=7
Class1=CMFCPaPaGoApp
Class2=CMFCPaPaGoDoc
Class3=CMFCPaPaGoView
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Resource2=IDR_MAINFRAME
Class6=CDlgSetTimer
Resource3=IDD_DIALOG1
Class7=CShowGPSData
Resource4=IDD_DIALOGBAR (English (U.S.))

[CLS:CMFCPaPaGoApp]
Type=0
HeaderFile=MFCPaPaGo.h
ImplementationFile=MFCPaPaGo.cpp
Filter=N

[CLS:CMFCPaPaGoDoc]
Type=0
HeaderFile=MFCPaPaGoDoc.h
ImplementationFile=MFCPaPaGoDoc.cpp
Filter=N

[CLS:CMFCPaPaGoView]
Type=0
HeaderFile=MFCPaPaGoView.h
ImplementationFile=MFCPaPaGoView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CMFCPaPaGoView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=MFCPaPaGo.cpp
ImplementationFile=MFCPaPaGo.cpp
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
Command14=ID_LoadMap
Command15=ID_UPMAP
Command16=ID_DOWNMAP
Command17=ID_RIGHTMAP
Command18=ID_LEFTMAP
Command19=ID_CENTER
Command20=ID_RUNTIMER
Command21=ID_DirectBMP
Command22=ID_Routing
Command23=ID_VIEW_TOOLBAR
Command24=ID_VIEW_STATUS_BAR
Command25=ID_APP_ABOUT
CommandCount=25

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

[DLG:IDD_DIALOG1]
Type=1
Class=CDlgSetTimer
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[CLS:CDlgSetTimer]
Type=0
HeaderFile=DlgSetTimer.h
ImplementationFile=DlgSetTimer.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_DIALOGBAR (English (U.S.))]
Type=1
Class=CShowGPSData
ControlCount=12
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_EDIT2,edit,1350631552
Control3=IDC_EDIT3,edit,1350631552
Control4=IDC_STATIC,static,1342308353
Control5=IDC_STATIC,static,1342308353
Control6=IDC_STATIC,static,1342308353
Control7=IDC_EDIT4,edit,1350631552
Control8=IDC_STATIC,static,1342308353
Control9=IDC_EDIT5,edit,1350631552
Control10=IDC_EDIT6,edit,1350631552
Control11=IDC_STATIC,static,1342308353
Control12=IDC_STATIC,static,1342308353

[CLS:CShowGPSData]
Type=0
HeaderFile=ShowGPSData.h
ImplementationFile=ShowGPSData.cpp
BaseClass=CDialogBar
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

