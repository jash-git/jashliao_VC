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
Dim data(0 To 4) As point
Dim n As Long
data(0).x = 0
data(0).y = 0
data(1).x = 1
data(1).y = 1
data(2).x = 2
data(2).y = 2
data(3).x = 3
data(3).y = 3
data(4).x = 4
data(4).y = 4
n = 5
Call GetValue1(data(0), n)
End Sub
