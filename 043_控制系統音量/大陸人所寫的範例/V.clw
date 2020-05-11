; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CVDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "V.h"

ClassCount=4
Class1=CVApp
Class2=CVDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_V_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CPPDlg
Resource4=IDR_MENU1
Resource5=IDD_PP
Resource6=IDR_TOOLBAR1

[CLS:CVApp]
Type=0
HeaderFile=V.h
ImplementationFile=V.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CVDlg]
Type=0
HeaderFile=VDlg.h
ImplementationFile=VDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CVDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=VDlg.h
ImplementationFile=VDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=7
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_LINK,static,1342308352
Control6=IDC_LINK2,static,1342308352
Control7=IDC_STATIC,static,1342308352

[DLG:IDD_V_DIALOG]
Type=1
Class=CVDlg
ControlCount=12
Control1=IDC_SAVE,button,1342242816
Control2=IDC_HOTKEY1,msctls_hotkey32,1350631424
Control3=IDC_HOTKEY2,msctls_hotkey32,1350631424
Control4=IDC_HOTKEY3,msctls_hotkey32,1350631424
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_MINIMIZED,button,1342242819
Control10=IDC_ABOUT,button,1342242816
Control11=IDC_EXIT,button,1342242816
Control12=IDC_STATE,static,1342308352

[CLS:CPPDlg]
Type=0
HeaderFile=PPDlg.h
ImplementationFile=PPDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_ICON

[DLG:IDD_PP]
Type=1
Class=CPPDlg
ControlCount=3
Control1=IDC_PROGRESS1,msctls_progress32,1342177281
Control2=IDC_STATICICON,static,1342177283
Control3=IDC_SLIDER1,msctls_trackbar32,1073807384

[MNU:IDR_MENU1]
Type=1
Class=CVDlg
Command1=IDC_ABOUT
Command2=IDC_SET
Command3=IDC_EXIT
CommandCount=3

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=IDC_ABOUT
Command2=IDC_SET
Command3=IDC_EXIT
CommandCount=3

