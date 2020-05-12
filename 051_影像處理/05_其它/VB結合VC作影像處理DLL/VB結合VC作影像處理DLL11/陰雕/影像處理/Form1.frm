VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   4500
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   4500
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text4 
      Height          =   495
      Left            =   8280
      TabIndex        =   7
      Text            =   "Text4"
      Top             =   10080
      Width           =   1455
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Command2"
      Height          =   615
      Left            =   10080
      TabIndex        =   6
      Top             =   10080
      Width           =   1575
   End
   Begin VB.TextBox Text3 
      Height          =   495
      Left            =   8280
      TabIndex        =   5
      Text            =   "Text3"
      Top             =   9360
      Width           =   3135
   End
   Begin VB.PictureBox Picture1 
      Height          =   1335
      Left            =   1080
      ScaleHeight     =   1275
      ScaleWidth      =   3915
      TabIndex        =   3
      Top             =   720
      Width           =   3975
      Begin VB.Label Label1 
         Alignment       =   2  'Center
         AutoSize        =   -1  'True
         BackColor       =   &H00FFFFFF&
         Caption         =   "Label1"
         BeginProperty Font 
            Name            =   "º–∑¢≈È"
            Size            =   72
            Charset         =   136
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00000000&
         Height          =   1440
         Left            =   -600
         TabIndex        =   4
         Top             =   120
         Width           =   4335
      End
   End
   Begin VB.TextBox Text2 
      Height          =   375
      Left            =   12600
      TabIndex        =   2
      Text            =   "Text2"
      Top             =   9480
      Width           =   975
   End
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   13920
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   9480
      Width           =   975
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   495
      Left            =   13320
      TabIndex        =   0
      Top             =   10080
      Width           =   1575
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Declare Function timeGetTime Lib "winmm.dll" () As Long
Private Declare Function GetDC Lib "user32" (ByVal hwnd As Long) As Long
Private Declare Function ReleaseDC Lib "user32" (ByVal hwnd As Long, ByVal hdc As Long) As Long

Private Sub Command1_Click()
Dim tm1 As Long
Dim tm2 As Long
Dim tm3 As Long
Dim hDC1 As Long
Dim h As Integer, w As Integer
Picture1.Width = Label1.Width
Picture1.Height = Label1.Height
Text1.Text = Picture1.ScaleWidth / 15
w = Val(Text1.Text)
Text2.Text = Picture1.ScaleHeight / 15
h = Val(Text2.Text)
tm1 = timeGetTime
hDC1 = GetDC(Picture1.hwnd)
Call DC2DC(hDC1, Picture1.ScaleWidth, Picture1.Height)
tm2 = timeGetTime
tm3 = tm2 - tm1
Form1.Caption = Str(tm3)
MsgBox "ok"
End Sub

Private Sub Command2_Click()
Label1.Caption = Text3.Text
Label1.Top = 0
Label1.Left = 0
Picture1.Top = 0
Picture1.Left = 0
Label1.Top = 0
Label1.Left = 0
Label1.FontSize = Val(Text4.Text)
Picture1.Width = Label1.Width
Picture1.Height = Label1.Height
End Sub

Private Sub Form_Activate()
Label1.Top = 0
Label1.Left = 0
Picture1.Width = Label1.Width
Picture1.Height = Label1.Height
End Sub

