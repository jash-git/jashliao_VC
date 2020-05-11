; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPlayerDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "player.h"
ODLFile=player.odl

ClassCount=4
Class1=CPlayerApp
Class2=CPlayerDlg
Class3=CAboutDlg
Class4=CPlayerDlgAutoProxy

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PLAYER_DIALOG

[CLS:CPlayerApp]
Type=0
HeaderFile=player.h
ImplementationFile=player.cpp
Filter=N

[CLS:CPlayerDlg]
Type=0
HeaderFile=playerDlg.h
ImplementationFile=playerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CPlayerDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=playerDlg.h
ImplementationFile=playerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CPlayerDlgAutoProxy]
Type=0
HeaderFile=DlgProxy.h
ImplementationFile=DlgProxy.cpp
BaseClass=CCmdTarget
Filter=N

[DLG:IDD_PLAYER_DIALOG]
Type=1
Class=CPlayerDlg
ControlCount=5
Control1=IDC_ACTIVEMOVIECONTROL1,{05589FA1-C356-11CE-BF01-00AA0055595A},1342242816
Control2=IDC_LIST1,listbox,1352728835
Control3=IDC_BUTTON1,button,1342275584
Control4=IDC_BUTTON2,button,1342275584
Control5=IDC_BUTTON3,button,1342275584

