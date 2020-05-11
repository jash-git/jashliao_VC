; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=dlg2
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "dlg.h"

ClassCount=4
Class1=CDlgApp
Class2=CDlgDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DLG_DIALOG
Class4=dlg2
Resource4=IDD_DIALOG1

[CLS:CDlgApp]
Type=0
HeaderFile=dlg.h
ImplementationFile=dlg.cpp
Filter=N

[CLS:CDlgDlg]
Type=0
HeaderFile=dlgDlg.h
ImplementationFile=dlgDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT1

[CLS:CAboutDlg]
Type=0
HeaderFile=dlgDlg.h
ImplementationFile=dlgDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DLG_DIALOG]
Type=1
Class=CDlgDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_EDIT1,edit,1350631552

[DLG:IDD_DIALOG1]
Type=1
Class=dlg2
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_EDIT1,edit,1350631552

[CLS:dlg2]
Type=0
HeaderFile=dlg2.h
ImplementationFile=dlg2.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

