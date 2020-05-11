VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False


Private Sub Form_Load()
Dim data(0 To 1) As EngarveElement
Dim data1(0 To 1) As EngarveElement
Dim n As Long
data(0).CCW = 0
data(0).Type = 0
data(0).X1 = 0.1
data(0).Y1 = 0.2
data(0).Z1 = 0.3
data(0).X2 = 0.4
data(0).Y2 = 0.5
data(0).Z2 = 0.6
data(1).CCW = 1
data(1).Type = 1
data(1).X1 = 1.1
data(1).Y1 = 1.2
data(1).Z1 = 1.3
data(1).X2 = 1.4
data(1).Y2 = 1.5
data(1).Z2 = 1.6
n = 2
Dim EB As EngarveBlock
ReDim EB.Child(0 To 2)
EB.Child(0).CCW = 0
EB.Child(0).Type = 0
EB.Child(0).X1 = 0.1
EB.Child(0).Y1 = 0.2
EB.Child(0).Z1 = 0.3
EB.Child(0).X2 = 0.4
EB.Child(0).Y2 = 0.5
EB.Child(0).Z2 = 0.6

EB.Child(1).CCW = 1
EB.Child(1).Type = 1
EB.Child(1).X1 = 1.1
EB.Child(1).Y1 = 1.2
EB.Child(1).Z1 = 1.3
EB.Child(1).X2 = 1.4
EB.Child(1).Y2 = 1.5
EB.Child(1).Z2 = 1.6
Call GetValue1(EB.Child(0), n)
n = 0
n = SendValue1(data1(0))

End Sub
