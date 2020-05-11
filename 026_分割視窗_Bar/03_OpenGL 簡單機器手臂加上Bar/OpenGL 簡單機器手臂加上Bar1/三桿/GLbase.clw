; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGLbaseView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GLbase.h"
LastPage=0

ClassCount=7
Class1=CGLbaseApp
Class2=CGLbaseDoc
Class3=CGLbaseView
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_DIALOG1
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=CDlg1
Resource3=IDR_MAINFRAME
Class7=CBar
Resource4=IDD_DIALOGBAR (English (U.S.))

[CLS:CGLbaseApp]
Type=0
HeaderFile=GLbase.h
ImplementationFile=GLbase.cpp
Filter=N

[CLS:CGLbaseDoc]
Type=0
HeaderFile=GLbaseDoc.h
ImplementationFile=GLbaseDoc.cpp
Filter=N

[CLS:CGLbaseView]
Type=0
HeaderFile=GLbaseView.h
ImplementationFile=GLbaseView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=IDC_A


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=GLbase.cpp
ImplementationFile=GLbase.cpp
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
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_set
Command9=ID_APP_ABOUT
CommandCount=9

[DLG:IDD_DIALOG1]
Type=1
Class=CDlg1
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_EDIT2,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT3,edit,1350631552

[CLS:CDlg1]
Type=0
HeaderFile=Dlg1.h
ImplementationFile=Dlg1.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDlg1

[DLG:IDD_DIALOGBAR (English (U.S.))]
Type=1
Class=CBar
ControlCount=16
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_EDIT2,edit,1350631552
Control3=IDC_EDIT3,edit,1350631552
Control4=IDC_BUTTON1,button,1342242816
Control5=IDC_EDIT4,edit,1342244992
Control6=IDC_EDIT5,edit,1342244992
Control7=IDC_EDIT6,edit,1342244992
Control8=IDC_Q,button,1342242816
Control9=IDC_W,button,1342242816
Control10=IDC_E,button,1342242816
Control11=IDC_A,button,1342242816
Control12=IDC_S,button,1342242816
Control13=IDC_D,button,1342242816
Control14=IDC_Z,button,1342242816
Control15=IDC_X,button,1342242816
Control16=IDC_C,button,1342242816

[CLS:CBar]
Type=0
HeaderFile=Bar.h
ImplementationFile=Bar.cpp
BaseClass=CDialogBar
Filter=D
LastObject=IDC_W
VirtualFilter=dWC

