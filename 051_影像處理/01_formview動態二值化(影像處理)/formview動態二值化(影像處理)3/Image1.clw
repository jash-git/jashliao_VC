; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CShowBmp
LastTemplate=CView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Image1.h"
LastPage=0

ClassCount=6
Class1=CImage1App
Class2=CImage1Doc
Class3=CImage1View
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CShowBmp
Resource3=IDD_IMAGE1_FORM

[CLS:CImage1App]
Type=0
HeaderFile=Image1.h
ImplementationFile=Image1.cpp
Filter=N

[CLS:CImage1Doc]
Type=0
HeaderFile=Image1Doc.h
ImplementationFile=Image1Doc.cpp
Filter=N

[CLS:CImage1View]
Type=0
HeaderFile=Image1View.h
ImplementationFile=Image1View.cpp
Filter=D
LastObject=CImage1View
BaseClass=CFormView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=Image1.cpp
ImplementationFile=Image1.cpp
Filter=D

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
Command14=ID_show1
Command15=ID_show2
Command16=ID_VIEW_TOOLBAR
Command17=ID_VIEW_STATUS_BAR
Command18=ID_APP_ABOUT
CommandCount=18

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

[DLG:IDD_IMAGE1_FORM]
Type=1
Class=CImage1View
ControlCount=4
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDC_SLIDER1,msctls_trackbar32,1342242840
Control4=IDC_BUTTON1,button,1342242816

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
CommandCount=8

[CLS:CShowBmp]
Type=0
HeaderFile=ShowBmp.h
ImplementationFile=ShowBmp.cpp
BaseClass=CView
Filter=C
LastObject=ID_show2
VirtualFilter=VWC

