; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=getwme
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "playlist.h"
LastPage=0

ClassCount=6
Class1=CPlaylistApp
Class2=CPlaylistDoc
Class3=CPlaylistView
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDD_PLAYLIST_FORM
Class5=CAboutDlg
Resource3=IDR_MAINFRAME
Class6=getwme
Resource4=IDD_GETWME

[CLS:CPlaylistApp]
Type=0
HeaderFile=playlist.h
ImplementationFile=playlist.cpp
Filter=N

[CLS:CPlaylistDoc]
Type=0
HeaderFile=playlistDoc.h
ImplementationFile=playlistDoc.cpp
Filter=N

[CLS:CPlaylistView]
Type=0
HeaderFile=playlistView.h
ImplementationFile=playlistView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=IDC_EXPLORER1


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=playlist.cpp
ImplementationFile=playlist.cpp
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
Command1=ID_APP_EXIT
Command2=ID_APP_ABOUT
CommandCount=2

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[DLG:IDD_PLAYLIST_FORM]
Type=1
Class=CPlaylistView
ControlCount=5
Control1=IDC_LIST1,listbox,1352728833
Control2=IDC_OCX1,{6BF52A52-394A-11D3-B153-00C04F79FAA6},1342242816
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_EDIT1,edit,1350633600
Control5=IDC_EXPLORER1,{8856F961-340A-11D0-A96B-00C04FD705A2},1073807360

[DLG:IDD_GETWME]
Type=1
Class=getwme
ControlCount=2
Control1=IDC_LIST1,listbox,1352728835
Control2=IDC_EXPLORER1,{8856F961-340A-11D0-A96B-00C04FD705A2},1073807360

[CLS:getwme]
Type=0
HeaderFile=getwme.h
ImplementationFile=getwme.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EXPLORER1

