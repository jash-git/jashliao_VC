; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CKey_eventDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "key_event.h"

ClassCount=4
Class1=CKey_eventApp
Class2=CKey_eventDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_KEY_EVENT_DIALOG

[CLS:CKey_eventApp]
Type=0
HeaderFile=key_event.h
ImplementationFile=key_event.cpp
Filter=N

[CLS:CKey_eventDlg]
Type=0
HeaderFile=key_eventDlg.h
ImplementationFile=key_eventDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=key_eventDlg.h
ImplementationFile=key_eventDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_KEY_EVENT_DIALOG]
Type=1
Class=CKey_eventDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816

