; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMatlab_testDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "matlab_test.h"

ClassCount=4
Class1=CMatlab_testApp
Class2=CMatlab_testDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MATLAB_TEST_DIALOG

[CLS:CMatlab_testApp]
Type=0
HeaderFile=matlab_test.h
ImplementationFile=matlab_test.cpp
Filter=N

[CLS:CMatlab_testDlg]
Type=0
HeaderFile=matlab_testDlg.h
ImplementationFile=matlab_testDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=matlab_testDlg.h
ImplementationFile=matlab_testDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MATLAB_TEST_DIALOG]
Type=1
Class=CMatlab_testDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816

