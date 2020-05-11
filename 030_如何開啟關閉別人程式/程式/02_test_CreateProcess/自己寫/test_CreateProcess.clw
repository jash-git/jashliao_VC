; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTest_CreateProcessDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "test_CreateProcess.h"

ClassCount=4
Class1=CTest_CreateProcessApp
Class2=CTest_CreateProcessDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TEST_CREATEPROCESS_DIALOG

[CLS:CTest_CreateProcessApp]
Type=0
HeaderFile=test_CreateProcess.h
ImplementationFile=test_CreateProcess.cpp
Filter=N

[CLS:CTest_CreateProcessDlg]
Type=0
HeaderFile=test_CreateProcessDlg.h
ImplementationFile=test_CreateProcessDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=test_CreateProcessDlg.h
ImplementationFile=test_CreateProcessDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TEST_CREATEPROCESS_DIALOG]
Type=1
Class=CTest_CreateProcessDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816

