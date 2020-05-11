; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgMenuToolbarDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DlgMenuToolbar.h"

ClassCount=3
Class1=CDlgMenuToolbarApp
Class2=CDlgMenuToolbarDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDR_MENU1
Resource4=IDD_DLGMENUTOOLBAR_DIALOG
Resource5=IDR_TOOLBAR1

[CLS:CDlgMenuToolbarApp]
Type=0
HeaderFile=DlgMenuToolbar.h
ImplementationFile=DlgMenuToolbar.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CDlgMenuToolbarApp

[CLS:CDlgMenuToolbarDlg]
Type=0
HeaderFile=DlgMenuToolbarDlg.h
ImplementationFile=DlgMenuToolbarDlg.cpp
Filter=D
LastObject=CDlgMenuToolbarDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=DlgMenuToolbarDlg.h
ImplementationFile=DlgMenuToolbarDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=3
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDOK,button,1342373889

[DLG:IDD_DLGMENUTOOLBAR_DIALOG]
Type=1
Class=CDlgMenuToolbarDlg
ControlCount=3
Control1=IDC_STATIC,static,1342181383
Control2=IDC_STATIC,static,1342181383
Control3=IDC_STATIC,static,1342312449

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_APP_EXIT
Command2=ID_APP_ABOUT
CommandCount=2

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=ID_APP_EXIT
Command2=ID_APP_ABOUT
CommandCount=2

