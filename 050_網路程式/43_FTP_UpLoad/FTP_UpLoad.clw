; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFTP_UpLoadDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FTP_UpLoad.h"

ClassCount=3
Class1=CFTP_UpLoadApp
Class2=CFTP_UpLoadDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FTP_UPLOAD_DIALOG

[CLS:CFTP_UpLoadApp]
Type=0
HeaderFile=FTP_UpLoad.h
ImplementationFile=FTP_UpLoad.cpp
Filter=N

[CLS:CFTP_UpLoadDlg]
Type=0
HeaderFile=FTP_UpLoadDlg.h
ImplementationFile=FTP_UpLoadDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CFTP_UpLoadDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=FTP_UpLoadDlg.h
ImplementationFile=FTP_UpLoadDlg.cpp
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

[DLG:IDD_FTP_UPLOAD_DIALOG]
Type=1
Class=CFTP_UpLoadDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

