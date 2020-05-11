; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTCPDlg
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TCP.h"

ClassCount=5
Class1=CTCPApp
Class2=CTCPDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=DataSocket
Class5=ListenSocket
Resource3=IDD_TCP_DIALOG

[CLS:CTCPApp]
Type=0
HeaderFile=TCP.h
ImplementationFile=TCP.cpp
Filter=N
LastObject=CTCPApp

[CLS:CTCPDlg]
Type=0
HeaderFile=TCPDlg.h
ImplementationFile=TCPDlg.cpp
Filter=D
LastObject=IDC_EDIT2
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=TCPDlg.h
ImplementationFile=TCPDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TCP_DIALOG]
Type=1
Class=CTCPDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_Create,button,1342242816
Control5=IDC_Listen,button,1342242816
Control6=IDC_EDIT1,edit,1350631552
Control7=IDC_EDIT2,edit,1350631552
Control8=IDC_EDIT3,edit,1350631552

[CLS:DataSocket]
Type=0
HeaderFile=DataSocket.h
ImplementationFile=DataSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq
LastObject=DataSocket

[CLS:ListenSocket]
Type=0
HeaderFile=listensocket.h
ImplementationFile=listensocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq
LastObject=ListenSocket

