; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTabDlg
LastTemplate=CPropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Tab.h"

ClassCount=6
Class1=CTabApp
Class2=CTabDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_TAB_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_PROPPAGE_SMALL (English (U.S.))
Class4=CDlg1
Resource4=IDD_ABOUTBOX
Resource5=IDD_DIALOG1
Class5=CCommand
Class6=CText
Resource6=IDD_PROPPAGE_SMALL1 (English (U.S.))

[CLS:CTabApp]
Type=0
HeaderFile=Tab.h
ImplementationFile=Tab.cpp
Filter=N

[CLS:CTabDlg]
Type=0
HeaderFile=TabDlg.h
ImplementationFile=TabDlg.cpp
Filter=D
LastObject=CTabDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=TabDlg.h
ImplementationFile=TabDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TAB_DIALOG]
Type=1
Class=CTabDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_EDIT2,edit,1350631552

[DLG:IDD_DIALOG1]
Type=1
Class=CDlg1
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CDlg1]
Type=0
HeaderFile=Dlg1.h
ImplementationFile=Dlg1.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlg1
VirtualFilter=dWC

[DLG:IDD_PROPPAGE_SMALL (English (U.S.))]
Type=1
Class=CText
ControlCount=2
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_BUTTON1,button,1342242816

[DLG:IDD_PROPPAGE_SMALL1 (English (U.S.))]
Type=1
Class=CCommand
ControlCount=2
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_BUTTON1,button,1342242816

[CLS:CCommand]
Type=0
HeaderFile=Command.h
ImplementationFile=Command.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CCommand
VirtualFilter=idWC

[CLS:CText]
Type=0
HeaderFile=Text.h
ImplementationFile=Text.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CText
VirtualFilter=idWC

