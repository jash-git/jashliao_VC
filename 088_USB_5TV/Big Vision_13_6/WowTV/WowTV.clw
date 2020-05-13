; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWowTVDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "WowTV.h"

ClassCount=4
Class1=CWowTVApp
Class2=CWowTVDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_WOWTV_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CDlgLoginFrm
Resource4=IDD_Login

[CLS:CWowTVApp]
Type=0
HeaderFile=WowTV.h
ImplementationFile=WowTV.cpp
Filter=N
LastObject=CWowTVApp

[CLS:CWowTVDlg]
Type=0
HeaderFile=WowTVDlg.h
ImplementationFile=WowTVDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CWowTVDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=WowTVDlg.h
ImplementationFile=WowTVDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_WOWTV_DIALOG]
Type=1
Class=CWowTVDlg
ControlCount=3
Control1=IDOK,button,1073807361
Control2=IDC_EXPLORER1,{8856F961-340A-11D0-A96B-00C04FD705A2},1342242816
Control3=IDC_EXPLORER2,{8856F961-340A-11D0-A96B-00C04FD705A2},1073807360

[DLG:IDD_Login]
Type=1
Class=CDlgLoginFrm
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[CLS:CDlgLoginFrm]
Type=0
HeaderFile=DlgLoginFrm.h
ImplementationFile=DlgLoginFrm.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgLoginFrm
VirtualFilter=dWC

