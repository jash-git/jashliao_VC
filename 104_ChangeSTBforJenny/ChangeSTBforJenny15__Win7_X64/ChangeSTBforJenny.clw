; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ChangeSTBforJenny.h"

ClassCount=4
Class1=CChangeSTBforJennyApp
Class2=CChangeSTBforJennyDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_CHANGESTBFORJENNY_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CWebInformation
Resource4=IDD_WebInfor

[CLS:CChangeSTBforJennyApp]
Type=0
HeaderFile=ChangeSTBforJenny.h
ImplementationFile=ChangeSTBforJenny.cpp
Filter=N

[CLS:CChangeSTBforJennyDlg]
Type=0
HeaderFile=ChangeSTBforJennyDlg.h
ImplementationFile=ChangeSTBforJennyDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_COMBOSTBCommand

[CLS:CAboutDlg]
Type=0
HeaderFile=ChangeSTBforJennyDlg.h
ImplementationFile=ChangeSTBforJennyDlg.cpp
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

[DLG:IDD_CHANGESTBFORJENNY_DIALOG]
Type=1
Class=CChangeSTBforJennyDlg
ControlCount=48
Control1=IDC_STATIC,static,1342308992
Control2=IDC_STATIC,static,1342308992
Control3=IDC_STATIC,static,1342308992
Control4=IDC_STATIC,static,1342308992
Control5=IDC_STATIC,static,1342308992
Control6=IDC_STATIC,static,1342308992
Control7=IDC_STATIC,static,1342308992
Control8=IDC_STATIC,static,1342308992
Control9=IDC_STATIC,static,1342308992
Control10=IDC_IPADDRESS,SysIPAddress32,1342242816
Control11=IDC_ButtSetIPandUID,button,1342242816
Control12=IDC_STATIC,static,1342308992
Control13=IDC_EDITUID,edit,1350631552
Control14=IDC_CHECKRegist,button,1342242819
Control15=IDC_ButtALLAuto,button,1342242816
Control16=IDC_CHECKUpdateData,button,1342242819
Control17=IDC_COMBOVolume,combobox,1344340226
Control18=IDC_CHECKLayout,button,1342242819
Control19=IDC_CHECKVolume,button,1342242819
Control20=IDC_CHECKTime,button,1342242819
Control21=IDC_CHECKRemoteControl,button,1342242819
Control22=IDC_CHECKMovie,button,1342242819
Control23=IDC_ButtRegistration,button,1342242816
Control24=IDC_ButtUpdateData,button,1342242816
Control25=IDC_ButtLayout,button,1342242816
Control26=IDC_ButtVolume,button,1342242816
Control27=IDC_ButtBootTime,button,1342242816
Control28=IDC_ButtRemoteControl,button,1342242816
Control29=IDC_ButtMovie,button,1342242816
Control30=IDC_EDITTime,edit,1350631552
Control31=IDC_STATIC,static,1342308992
Control32=IDC_EDITLayout,edit,1350631552
Control33=IDC_ButtSelectLayout,button,1342242816
Control34=IDC_ShowState,static,1342312448
Control35=IDC_CHECKDeleteMovie,button,1342242819
Control36=IDC_ButtDeleteMovie,button,1342242816
Control37=IDC_CHECKTUKA,button,1342242819
Control38=IDC_ButtTUKA,button,1342242816
Control39=IDC_STATIC,static,1342308992
Control40=IDC_CHECKEIPFlow,button,1342242819
Control41=IDC_ButtEIPFlow,button,1342242816
Control42=IDC_STATIC,static,1342308992
Control43=IDC_CHECKCompletionSerch,button,1342242819
Control44=IDC_ButtCompletionSerch,button,1342242816
Control45=IDC_STATIC,static,1342308992
Control46=IDC_COMBOSTBCommand,combobox,1344340226
Control47=IDC_CHECKSTBCommand,button,1342242819
Control48=IDC_ButtSTBCommand,button,1342242816

[DLG:IDD_WebInfor]
Type=1
Class=CWebInformation
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_ShowURL,static,1342308608
Control4=IDC_ShowName,static,1342308352
Control5=IDC_ShowPassWord,static,1342308352

[CLS:CWebInformation]
Type=0
HeaderFile=WebInformation.h
ImplementationFile=WebInformation.cpp
BaseClass=CDialog
Filter=D
LastObject=CWebInformation
VirtualFilter=dWC

