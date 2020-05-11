; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TelnetServer.h"

ClassCount=6
Class1=CTelnetServerApp
Class2=CTelnetServerDlg

ResourceCount=5
Resource1=IDR_MAINFRAME
Class3=CServerSocket
Class4=CListenerSocket
Class5=CMyDlg
Resource2=IDD_TELNETSERVER_DIALOG
Class6=CMyDialog
Resource3=IDD_TEMP_DLG
Resource4=IDD_TELNETSERVER_DIALOG (English (U.S.))
Resource5=IDD_TEMP_DLG (English (U.S.))

[CLS:CTelnetServerApp]
Type=0
HeaderFile=TelnetServer.h
ImplementationFile=TelnetServer.cpp
Filter=N

[CLS:CTelnetServerDlg]
Type=0
HeaderFile=TelnetServerDlg.h
ImplementationFile=TelnetServerDlg.cpp
Filter=D
LastObject=CTelnetServerDlg
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_TELNETSERVER_DIALOG]
Type=1
Class=CTelnetServerDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDC_STATIC_PORT,static,1342308352
Control3=IDC_EDIT_PORT,edit,1350631552
Control4=IDC_BUTTON_LISTEN,button,1342242816

[CLS:CServerSocket]
Type=0
HeaderFile=ServerSocket.h
ImplementationFile=ServerSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq
LastObject=CServerSocket

[CLS:CListenerSocket]
Type=0
HeaderFile=ListenerSocket.h
ImplementationFile=ListenerSocket.cpp
BaseClass=CSocket
Filter=N
LastObject=CListenerSocket
VirtualFilter=uq

[CLS:CMyDlg]
Type=0
HeaderFile=MyDlg.h
ImplementationFile=MyDlg.cpp
BaseClass=CDialog
Filter=D

[DLG:IDD_TEMP_DLG]
Type=1
Class=CMyDialog
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_MESSAGE,static,1342308352

[CLS:CMyDialog]
Type=0
HeaderFile=MyDialog.h
ImplementationFile=MyDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_MESSAGE

[DLG:IDD_TELNETSERVER_DIALOG (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDC_STATIC_PORT,static,1342308352
Control3=IDC_EDIT_PORT,edit,1350631552
Control4=IDC_BUTTON_LISTEN,button,1342242816

[DLG:IDD_TEMP_DLG (English (U.S.))]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_MESSAGE,static,1342308352

