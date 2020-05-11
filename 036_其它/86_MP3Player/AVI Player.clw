; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAVIPlayerDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "AVI Player.h"

ClassCount=3
Class1=CAVIPlayerApp
Class2=CAVIPlayerDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MP3BASICPLAYER_DIALOG

[CLS:CAVIPlayerApp]
Type=0
HeaderFile=AVI Player.h
ImplementationFile=AVI Player.cpp
Filter=N

[CLS:CAVIPlayerDlg]
Type=0
HeaderFile=AVI PlayerDlg.h
ImplementationFile=AVI PlayerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CAVIPlayerDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=AVI PlayerDlg.h
ImplementationFile=AVI PlayerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MP3BASICPLAYER_DIALOG]
Type=1
Class=CAVIPlayerDlg
ControlCount=6
Control1=IDC_PLAY,button,1342242816
Control2=IDC_STOP,button,1342242816
Control3=IDC_PAUSE,button,1342242816
Control4=IDCANCEL,button,1342242816
Control5=IDC_PATH,edit,1350631552
Control6=IDC_BROWSE,button,1342242816

