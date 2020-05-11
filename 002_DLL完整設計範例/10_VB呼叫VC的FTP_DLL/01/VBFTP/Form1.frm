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
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   735
      Left            =   1080
      TabIndex        =   0
      Top             =   600
      Width           =   2295
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
'ConnectFTP Lib "FTPUpLoad" (FTPServer As String, FTPuser As String, FTPpws As String, ByVal port As Integer)
Dim a As String
Dim b As String
Dim c As String
Dim d As Integer
Dim e As Boolean
a = "61.67.112.20"
b = "jash"
c = "jash"
d = 21
e = ConnectFTP(a, b, c, d)
e = UpLoadFTP("ANSI.txt")
Call ClosetFTP
End Sub
