; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTest_ListControlDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "test_ListControl.h"

ClassCount=3
Class1=CTest_ListControlApp
Class2=CTest_ListControlDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TEST_LISTCONTROL_DIALOG

[CLS:CTest_ListControlApp]
Type=0
HeaderFile=test_ListControl.h
ImplementationFile=test_ListControl.cpp
Filter=N

[CLS:CTest_ListControlDlg]
Type=0
HeaderFile=test_ListControlDlg.h
ImplementationFile=test_ListControlDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CAboutDlg]
Type=0
HeaderFile=test_ListControlDlg.h
ImplementationFile=test_ListControlDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TEST_LISTCONTROL_DIALOG]
Type=1
Class=CTest_ListControlDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,SysListView32,1350634381

