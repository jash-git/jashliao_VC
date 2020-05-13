; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CChangeDesktopDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ChangeDesktop.h"

ClassCount=4
Class1=CChangeDesktopApp
Class2=CChangeDesktopDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_DIALOG1
Resource2=IDR_MAINFRAME
Resource3=IDD_CHANGEDESKTOP_DIALOG
Class4=CSetDlg
Resource4=IDD_ABOUTBOX
Resource5=IDR_MENU1

[CLS:CChangeDesktopApp]
Type=0
HeaderFile=ChangeDesktop.h
ImplementationFile=ChangeDesktop.cpp
Filter=N

[CLS:CChangeDesktopDlg]
Type=0
HeaderFile=ChangeDesktopDlg.h
ImplementationFile=ChangeDesktopDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_NextPage

[CLS:CAboutDlg]
Type=0
HeaderFile=ChangeDesktopDlg.h
ImplementationFile=ChangeDesktopDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CHANGEDESKTOP_DIALOG]
Type=1
Class=CChangeDesktopDlg
ControlCount=9
Control1=IDOK,button,1342242816
Control2=IDC_Run,button,1342242816
Control3=IDC_Hide,button,1342242816
Control4=IDC_SetShow,button,1342242816
Control5=IDC_STATIC,static,1342308353
Control6=IDC_STATIC,static,1342308353
Control7=IDC_ALL,edit,1484849280
Control8=IDC_NOW,edit,1484849280
Control9=IDC_STATIC,button,1342177287

[DLG:IDD_DIALOG1]
Type=1
Class=CSetDlg
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_STATIC,static,1342308353
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308353
Control6=IDC_EDIT3,edit,1484849280
Control7=IDC_STATIC,static,1342308353
Control8=IDC_COMBO1,combobox,1344340226
Control9=IDC_SwitchDir,button,1342242816

[CLS:CSetDlg]
Type=0
HeaderFile=SetDlg.h
ImplementationFile=SetDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_SwitchDir
VirtualFilter=dWC

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=IDC_NextPage
CommandCount=1

