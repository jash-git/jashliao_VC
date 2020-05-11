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
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   495
      Left            =   3360
      TabIndex        =   4
      Top             =   960
      Width           =   975
   End
   Begin VB.TextBox Text4 
      Height          =   495
      Left            =   2160
      TabIndex        =   3
      Text            =   "Text4"
      Top             =   960
      Width           =   975
   End
   Begin VB.TextBox Text3 
      Height          =   495
      Left            =   840
      TabIndex        =   2
      Text            =   "Text3"
      Top             =   960
      Width           =   1095
   End
   Begin VB.TextBox Text2 
      Height          =   495
      Left            =   2160
      TabIndex        =   1
      Text            =   "Text2"
      Top             =   360
      Width           =   975
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   840
      TabIndex        =   0
      Text            =   "Text1"
      Top             =   360
      Width           =   1095
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False


Private Sub Command1_Click()
Dim data1 As point
Dim data2 As point
data1.x = Val(Text1.Text)
data1.y = Val(Text2.Text)
data2.x = 0
data2.y = 0
Call ChangeValue1(data1, data2)
Text3.Text = data2.x
Text4.Text = data2.y
End Sub

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
