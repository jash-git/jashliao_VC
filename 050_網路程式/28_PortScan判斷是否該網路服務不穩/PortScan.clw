; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPortScanDlg
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PortScan.h"

ClassCount=4
Class1=CPortScanApp
Class2=CPortScanDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CTheSocket
Resource3=IDD_PORTSCAN_DIALOG
Resource4=IDD_ABOUTBOX (Chinese (P.R.C.))
Resource5=IDD_PORTSCAN_DIALOG (Chinese (P.R.C.))

[CLS:CPortScanApp]
Type=0
HeaderFile=PortScan.h
ImplementationFile=PortScan.cpp
Filter=N

[CLS:CPortScanDlg]
Type=0
HeaderFile=PortScanDlg.h
ImplementationFile=PortScanDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CPortScanDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=PortScanDlg.h
ImplementationFile=PortScanDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PORTSCAN_DIALOG]
Type=1
Class=CPortScanDlg
ControlCount=19
Control1=IDC_BUTTON_SCAN,button,1342242817
Control2=IDC_BUTTON_STOP,button,1342242816
Control3=IDC_IP_ADDRESS,SysIPAddress32,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,button,1342177287
Control6=IDC_RADIO_SINGLE,button,1342177289
Control7=IDC_RADIO_RANGE,button,1342177289
Control8=IDC_EDIT_SINGLE_PORT,edit,1350631552
Control9=IDC_EDIT_SINGLE_PORT_FROM,edit,1350631552
Control10=IDC_EDIT_SINGLE_PORT_TO,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT_ATTEMPTS,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_LIST_RESULT,SysListView32,1350631425
Control15=IDC_STATIC,static,1342308352
Control16=IDC_PROGRESS,msctls_progress32,1350565888
Control17=IDC_STATIC_STATUS,static,1342308352
Control18=IDC_BUTTON_SAVE,button,1342242816
Control19=IDC_STATIC,button,1342177287

[CLS:CTheSocket]
Type=0
HeaderFile=TheSocket.h
ImplementationFile=TheSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq
LastObject=CTheSocket

[DLG:IDD_PORTSCAN_DIALOG (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=19
Control1=IDC_BUTTON_SCAN,button,1342242817
Control2=IDC_BUTTON_STOP,button,1342242816
Control3=IDC_IP_ADDRESS,SysIPAddress32,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,button,1342177287
Control6=IDC_RADIO_SINGLE,button,1342177289
Control7=IDC_RADIO_RANGE,button,1342177289
Control8=IDC_EDIT_SINGLE_PORT,edit,1350631552
Control9=IDC_EDIT_SINGLE_PORT_FROM,edit,1350631552
Control10=IDC_EDIT_SINGLE_PORT_TO,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT_ATTEMPTS,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_LIST_RESULT,SysListView32,1350631425
Control15=IDC_STATIC,static,1342308352
Control16=IDC_PROGRESS,msctls_progress32,1350565888
Control17=IDC_STATIC_STATUS,static,1342308352
Control18=IDC_BUTTON_SAVE,button,1342242816
Control19=IDC_STATIC,button,1342177287

[DLG:IDD_ABOUTBOX (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

