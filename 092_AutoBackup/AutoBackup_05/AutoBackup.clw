; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAutoBackupDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "AutoBackup.h"

ClassCount=4
Class1=CAutoBackupApp
Class2=CAutoBackupDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_AUTOBACKUP_DIALOG

[CLS:CAutoBackupApp]
Type=0
HeaderFile=AutoBackup.h
ImplementationFile=AutoBackup.cpp
Filter=N

[CLS:CAutoBackupDlg]
Type=0
HeaderFile=AutoBackupDlg.h
ImplementationFile=AutoBackupDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=AutoBackupDlg.h
ImplementationFile=AutoBackupDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_AUTOBACKUP_DIALOG]
Type=1
Class=CAutoBackupDlg
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDC_Findfolders,button,1342242816
Control3=IDC_FindWord,button,1342242816
Control4=IDC_FindExcel,button,1342242816
Control5=IDC_FindPowerPoint1,button,1342251008
Control6=IDC_FindPowerPoint2,button,1342251008
Control7=IDC_FindWinZip,button,1342251008
Control8=IDC_FindWinRAR,button,1342251008
Control9=IDC_FindAccess,button,1342251008
Control10=IDC_FindMXF,button,1342242816
Control11=IDC_EDIT1,edit,1350631552
Control12=IDC_FindName,button,1342242816

