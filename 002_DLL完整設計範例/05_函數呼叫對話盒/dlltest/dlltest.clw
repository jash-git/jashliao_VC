; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlltestDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "dlltest.h"

ClassCount=3
Class1=CDlltestApp
Class2=CDlltestDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DLLTEST_DIALOG

[CLS:CDlltestApp]
Type=0
HeaderFile=dlltest.h
ImplementationFile=dlltest.cpp
Filter=N

[CLS:CDlltestDlg]
Type=0
HeaderFile=dlltestDlg.h
ImplementationFile=dlltestDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT1

[CLS:CAboutDlg]
Type=0
HeaderFile=dlltestDlg.h
ImplementationFile=dlltestDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DLLTEST_DIALOG]
Type=1
Class=CDlltestDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_EDIT3,edit,1350631552
Control6=IDC_BUTTON1,button,1342242816

