; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDataSocket
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MultiServer.h"

ClassCount=5
Class1=CMultiServerApp
Class2=CMultiServerDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CDataSocket
Class4=CListenSocket
Resource3=IDD_MULTISERVER_DIALOG

[CLS:CMultiServerApp]
Type=0
HeaderFile=MultiServer.h
ImplementationFile=MultiServer.cpp
Filter=N

[CLS:CMultiServerDlg]
Type=0
HeaderFile=MultiServerDlg.h
ImplementationFile=MultiServerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT1

[CLS:CAboutDlg]
Type=0
HeaderFile=MultiServerDlg.h
ImplementationFile=MultiServerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MULTISERVER_DIALOG]
Type=1
Class=CMultiServerDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308353
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_STATIC,static,1342308353
Control7=IDC_EDIT3,edit,1350631552
Control8=IDC_STATIC,static,1342308353
Control9=IDC_EDIT4,edit,1350631552
Control10=IDC_STATIC,static,1342308353

[CLS:CListenSocket]
Type=0
HeaderFile=ListenSocket.h
ImplementationFile=ListenSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq
LastObject=CListenSocket

[CLS:CDataSocket]
Type=0
HeaderFile=DataSocket.h
ImplementationFile=DataSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq
LastObject=CDataSocket

