VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3105
   ClientLeft      =   60
   ClientTop       =   435
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3105
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "Command2"
      Height          =   615
      Left            =   600
      TabIndex        =   1
      Top             =   1200
      Width           =   2055
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   735
      Left            =   600
      TabIndex        =   0
      Top             =   120
      Width           =   2055
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim size As Long
Private Sub Command1_Click()
Dim tmp() As Integer, tmp1() As Long, i As Integer, j As Integer, l As Integer

ReDim xy(0 To 2)
ReDim tmp(0 To 3, 0 To 2)
For i = 0 To 3
    For j = 0 To 2
        tmp(i, j) = i * j
    Next j
Next i

l = 0
ReDim tmp1(0 To 11)
For i = 0 To 3
    For j = 0 To 2
        tmp1(l) = tmp(i, j)
        l = l + 1
    Next j
Next i

GetValue1 tmp1(0), 4, 3
Call SetValue1(size)
End Sub

Private Sub Command2_Click()
Dim tmp() As Long
ReDim tmp(0 To size)
Call SetValue2(tmp(0))
DeleteArray
End Sub
