; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCreate_2003AD_UserDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Create_2003AD_User.h"

ClassCount=4
Class1=CCreate_2003AD_UserApp
Class2=CCreate_2003AD_UserDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CREATE_2003AD_USER_DIALOG

[CLS:CCreate_2003AD_UserApp]
Type=0
HeaderFile=Create_2003AD_User.h
ImplementationFile=Create_2003AD_User.cpp
Filter=N

[CLS:CCreate_2003AD_UserDlg]
Type=0
HeaderFile=Create_2003AD_UserDlg.h
ImplementationFile=Create_2003AD_UserDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=Create_2003AD_UserDlg.h
ImplementationFile=Create_2003AD_UserDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CREATE_2003AD_USER_DIALOG]
Type=1
Class=CCreate_2003AD_UserDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_CreateFile,button,1342242816

