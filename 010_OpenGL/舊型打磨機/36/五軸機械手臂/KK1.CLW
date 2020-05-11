; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CKk1View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "kk1.h"
LastPage=0

ClassCount=9
Class1=CKk1App
Class2=CKk1Doc
Class3=CKk1View
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=view1
Resource2=IDR_MAINFRAME
Class7=viewbar
Resource3=IDD_DIALOG1
Class8=Dialog_set
Resource4=IDD_DIALOG2
Class9=SetCoordinate
Resource5=IDD_DIALOGBAR (English (U.S.))

[CLS:CKk1App]
Type=0
HeaderFile=kk1.h
ImplementationFile=kk1.cpp
Filter=N

[CLS:CKk1Doc]
Type=0
HeaderFile=kk1Doc.h
ImplementationFile=kk1Doc.cpp
Filter=N

[CLS:CKk1View]
Type=0
HeaderFile=kk1View.h
ImplementationFile=kk1View.cpp
Filter=C
BaseClass=CScrollView
VirtualFilter=VWC
LastObject=ID_Flank


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_Set1




[CLS:CAboutDlg]
Type=0
HeaderFile=kk1.cpp
ImplementationFile=kk1.cpp
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

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_Set
Command15=ID_Set1
Command16=ID_settimer
Command17=ID_Directly
Command18=ID_Flank
Command19=ID_VIEW_TOOLBAR
Command20=ID_VIEW_STATUS_BAR
Command21=ID_APP_ABOUT
CommandCount=21

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_bar
Command10=ID_test
CommandCount=10

[CLS:view1]
Type=0
HeaderFile=view1.h
ImplementationFile=view1.cpp
BaseClass=CScrollView
Filter=C
LastObject=IDC_EDIT1
VirtualFilter=VWC

[DLG:IDD_DIALOGBAR (English (U.S.))]
Type=1
Class=viewbar
ControlCount=2
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_EDIT2,edit,1350631552

[CLS:viewbar]
Type=0
HeaderFile=viewbar.h
ImplementationFile=viewbar.cpp
BaseClass=CDialogBar
Filter=D
LastObject=ID_APP_ABOUT
VirtualFilter=dWC

[DLG:IDD_DIALOG1]
Type=1
Class=Dialog_set
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_STATIC,static,1342308352

[CLS:Dialog_set]
Type=0
HeaderFile=Dialog_set.h
ImplementationFile=Dialog_set.cpp
BaseClass=CDialog
Filter=D
LastObject=Dialog_set
VirtualFilter=dWC

[DLG:IDD_DIALOG2]
Type=1
Class=SetCoordinate
ControlCount=23
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_EDIT2,edit,1350631552
Control4=IDC_EDIT3,edit,1350631552
Control5=IDC_EDIT4,edit,1350631552
Control6=IDC_EDIT5,edit,1350631552
Control7=IDC_EDIT6,edit,1350631552
Control8=IDC_EDIT7,edit,1350631552
Control9=IDC_EDIT8,edit,1350631552
Control10=IDC_EDIT9,edit,1350631552
Control11=IDC_EDIT10,edit,1350631552
Control12=IDC_EDIT11,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352

[CLS:SetCoordinate]
Type=0
HeaderFile=SetCoordinate.h
ImplementationFile=SetCoordinate.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT1

