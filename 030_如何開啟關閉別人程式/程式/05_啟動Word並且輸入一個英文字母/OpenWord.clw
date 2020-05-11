; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=COpenWordDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "OpenWord.h"

ClassCount=4
Class1=COpenWordApp
Class2=COpenWordDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_OPENWORD_DIALOG

[CLS:COpenWordApp]
Type=0
HeaderFile=OpenWord.h
ImplementationFile=OpenWord.cpp
Filter=N

[CLS:COpenWordDlg]
Type=0
HeaderFile=OpenWordDlg.h
ImplementationFile=OpenWordDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=OpenWordDlg.h
ImplementationFile=OpenWordDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_OPENWORD_DIALOG]
Type=1
Class=COpenWordDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816

