; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Dlg.h"

ClassCount=4
Class1=CDlgApp
Class2=CDlgDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_DLG_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CDlg2
Resource4=IDD_DIALOG1

[CLS:CDlgApp]
Type=0
HeaderFile=Dlg.h
ImplementationFile=Dlg.cpp
Filter=N

[CLS:CDlgDlg]
Type=0
HeaderFile=DlgDlg.h
ImplementationFile=DlgDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CDlgDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=DlgDlg.h
ImplementationFile=DlgDlg.cpp
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
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_EDIT1,edit,1350631552

[DLG:IDD_DIALOG1]
Type=1
Class=CDlg2
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_COMBO1,combobox,1344340226

[CLS:CDlg2]
Type=0
HeaderFile=Dlg2.h
ImplementationFile=Dlg2.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

