; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CProGram2Dlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ProGram2.h"

ClassCount=10
Class1=CProGram2App
Class2=CProGram2Dlg
Class3=CAboutDlg

ResourceCount=21
Resource1=IDD_ResultDlg
Resource2=IDR_MAINFRAME
Resource3=IDD_ONorIN
Resource4=IDD_Factors
Resource5=IDR_MENU1
Class4=CSureExit
Resource6=IDD_ABOUTBOX
Class5=MainFactorsData
Resource7=IDD_PROGRAM2_DIALOG
Resource8=IDD_Sheet
Class6=FactorsData
Class7=ONorINData
Resource9=IDD_SureEXIT
Class8=SheetDlg
Resource10=IDD_MainFactors
Class9=CResultDlg
Class10=AMoment
Resource11=IDR_TOOLBAR1
Resource12=IDD_ABOUTBOX (Chinese (P.R.C.))
Resource13=IDD_PROGRAM2_DIALOG (Chinese (P.R.C.))
Resource14=IDD_SureEXIT (Chinese (P.R.C.))
Resource15=IDD_MainFactors (Chinese (P.R.C.))
Resource16=IDD_ONorIN (Chinese (P.R.C.))
Resource17=IDD_Factors (Chinese (P.R.C.))
Resource18=IDD_Sheet (Chinese (P.R.C.))
Resource19=IDD_ResultDlg (Chinese (P.R.C.))
Resource20=IDR_MENU1 (Chinese (P.R.C.))
Resource21=IDR_TOOLBAR1 (Chinese (P.R.C.))

[CLS:CProGram2App]
Type=0
HeaderFile=ProGram2.h
ImplementationFile=ProGram2.cpp
Filter=N
LastObject=CProGram2App

[CLS:CProGram2Dlg]
Type=0
HeaderFile=ProGram2Dlg.h
ImplementationFile=ProGram2Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CProGram2Dlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ProGram2Dlg.h
ImplementationFile=ProGram2Dlg.cpp
Filter=D
LastObject=IDOK
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=7
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308353
Control6=IDC_STATIC,static,1342308353
Control7=IDC_STATIC,static,1342308353

[DLG:IDD_PROGRAM2_DIALOG]
Type=1
Class=CProGram2Dlg
ControlCount=13
Control1=IDC_MSFLEXGRID1,{6262D3A0-531B-11CF-91F6-C2863C385E30},1342242816
Control2=IDC_EDIT1,edit,1082196096
Control3=IDC_STATIC,static,1342308352
Control4=IDButtonRowUp,button,1342246657
Control5=IDBuntonRowDown,button,1342246657
Control6=IDButtonColDown,button,1342246657
Control7=IDButtonColUp,button,1342246657
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDITMeanRows,edit,1350631553
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDITMeanCols,edit,1350631553
Control13=IDC_STATIC,static,1342308352

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_MENU1_NEW
Command2=ID_MENU1_CLEARN
Command3=ID_MENU1_GetIn
Command4=ID_MENU1_PutOut
Command5=ID_MENU2_MAIN
Command6=ID_MENU2_ONorIN
Command7=ID_MENU2_FACTORS
Command8=ID_MENU3_HELP
Command9=ID_MENU3_ABOUT
Command10=ID_MENU1_EXIT
CommandCount=10

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=ID_MENU1_NEW
CommandCount=1

[DLG:IDD_SureEXIT]
Type=1
Class=CSureExit
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308353

[CLS:CSureExit]
Type=0
HeaderFile=SureExit.h
ImplementationFile=SureExit.cpp
BaseClass=CDialog
Filter=D
LastObject=IDOK
VirtualFilter=dWC

[DLG:IDD_MainFactors]
Type=1
Class=MainFactorsData
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242817
Control3=IDC_STATIC,button,1342177287
Control4=IDC_MeanRows,edit,1350631553
Control5=IDC_MeanCols,edit,1350631553
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_OfferRate,edit,1350631553
Control10=IDC_STATIC,button,1342177287
Control11=IDC_RADIO1,button,1342373929
Control12=IDC_RADIO2,button,1342177321

[CLS:MainFactorsData]
Type=0
HeaderFile=MainFactorsData.h
ImplementationFile=MainFactorsData.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_MENU1_CLEARN
VirtualFilter=dWC

[DLG:IDD_ONorIN]
Type=1
Class=ONorINData
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242817
Control3=IDC_STATIC,button,1342177287
Control4=IDC_MeanRows,edit,1350631553
Control5=IDC_MeanCols,edit,1350631553
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_OfferRate,edit,1350631553

[DLG:IDD_Factors]
Type=1
Class=FactorsData
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,button,1342177287
Control3=IDCANCEL,button,1342242817
Control4=IDC_MeanRows,edit,1350631553
Control5=IDC_MeanCols,edit,1350631553
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_OfferRate,edit,1350631553
Control10=IDC_STATIC,button,1342177287
Control11=IDC_CHECK1,button,1342242851
Control12=IDC_CHECK2,button,1342242851
Control13=IDC_CHECK3,button,1342251043
Control14=IDC_CHECK4,button,1342251299

[CLS:ONorINData]
Type=0
HeaderFile=ONorINData.h
ImplementationFile=ONorINData.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_MENU1_CLEARN
VirtualFilter=dWC

[DLG:IDD_Sheet]
Type=1
Class=SheetDlg
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242817
Control3=IDC_STATIC,static,1342308352
Control4=IDC_Sheet,edit,1350631553
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_TabelRows,edit,1350631553
Control9=IDC_TabelCols,edit,1350631553
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352

[CLS:SheetDlg]
Type=0
HeaderFile=SheetDlg.h
ImplementationFile=SheetDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_TabelRows

[DLG:IDD_ResultDlg]
Type=1
Class=CResultDlg
ControlCount=1
Control1=IDC_LIST1,listbox,1352663297

[CLS:CResultDlg]
Type=0
HeaderFile=ResultDlg.h
ImplementationFile=ResultDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CResultDlg
VirtualFilter=dWC

[CLS:AMoment]
Type=0
HeaderFile=AMoment.h
ImplementationFile=AMoment.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_OK
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=7
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308353
Control6=IDC_STATIC,static,1342308353
Control7=IDC_STATIC,static,1342308353

[DLG:IDD_PROGRAM2_DIALOG (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=13
Control1=IDC_MSFLEXGRID1,{6262D3A0-531B-11CF-91F6-C2863C385E30},1342242816
Control2=IDC_EDIT1,edit,1082196096
Control3=IDC_STATIC,static,1342308352
Control4=IDButtonRowUp,button,1342246657
Control5=IDBuntonRowDown,button,1342246657
Control6=IDButtonColDown,button,1342246657
Control7=IDButtonColUp,button,1342246657
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDITMeanRows,edit,1350631553
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDITMeanCols,edit,1350631553
Control13=IDC_STATIC,static,1342308352

[DLG:IDD_SureEXIT (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308353

[DLG:IDD_MainFactors (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242817
Control3=IDC_STATIC,button,1342177287
Control4=IDC_MeanRows,edit,1350631553
Control5=IDC_MeanCols,edit,1350631553
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_OfferRate,edit,1350631553
Control10=IDC_STATIC,button,1342177287
Control11=IDC_RADIO1,button,1342373929
Control12=IDC_RADIO2,button,1342177321

[DLG:IDD_ONorIN (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242817
Control3=IDC_STATIC,button,1342177287
Control4=IDC_MeanRows,edit,1350631553
Control5=IDC_MeanCols,edit,1350631553
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_OfferRate,edit,1350631553

[DLG:IDD_Factors (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,button,1342177287
Control3=IDCANCEL,button,1342242817
Control4=IDC_MeanRows,edit,1350631553
Control5=IDC_MeanCols,edit,1350631553
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_OfferRate,edit,1350631553
Control10=IDC_STATIC,button,1342177287
Control11=IDC_CHECK1,button,1342242851
Control12=IDC_CHECK2,button,1342242851
Control13=IDC_CHECK3,button,1342251043
Control14=IDC_CHECK4,button,1342251299

[DLG:IDD_Sheet (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242817
Control3=IDC_STATIC,static,1342308352
Control4=IDC_Sheet,edit,1350631553
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_TabelRows,edit,1350631553
Control9=IDC_TabelCols,edit,1350631553
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352

[DLG:IDD_ResultDlg (Chinese (P.R.C.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_LIST1,listbox,1352663297

[MNU:IDR_MENU1 (Chinese (P.R.C.))]
Type=1
Class=?
Command1=ID_MENU1_NEW
Command2=ID_MENU1_CLEARN
Command3=ID_MENU1_GetIn
Command4=ID_MENU1_PutOut
Command5=ID_MENU2_MAIN
Command6=ID_MENU2_ONorIN
Command7=ID_MENU2_FACTORS
Command8=ID_MENU3_HELP
Command9=ID_MENU3_ABOUT
Command10=ID_MENU1_EXIT
CommandCount=10

[TB:IDR_TOOLBAR1 (Chinese (P.R.C.))]
Type=1
Class=?
Command1=ID_MENU1_NEW
CommandCount=1

