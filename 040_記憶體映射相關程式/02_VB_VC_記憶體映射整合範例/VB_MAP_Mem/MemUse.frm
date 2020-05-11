VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "MemUse - 使用「共用記憶體」"
   ClientHeight    =   945
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5250
   LinkTopic       =   "Form1"
   ScaleHeight     =   945
   ScaleWidth      =   5250
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text1 
      Height          =   375
      Left            =   240
      TabIndex        =   1
      Text            =   "Text1"
      Top             =   240
      Width           =   3255
   End
   Begin VB.CommandButton Command1 
      Caption         =   "讀取"
      Height          =   375
      Left            =   3840
      TabIndex        =   0
      Top             =   240
      Width           =   1095
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim hFileMap As Long
Dim lpView As Long

Private Sub Command1_Click()
    Dim S As String * 80
    
    If lpView <> 0 Then
        ' 讀取 80 個字元
        RtlMoveMemory ByVal S, ByVal lpView, 80
        Text1.Text = S
    End If
End Sub

Private Sub Form_Load()
    ' 開啟名稱為 "MemMap" 的共用記憶體
    'hFileMap = OpenFileMapping(FILE_MAP_READ Or FILE_MAP_WRITE, False, "MemMap")
    hFileMap = OpenFileMapping(FILE_MAP_READ Or FILE_MAP_WRITE, False, "spacesoft corp.")
    If hFileMap = 0 Then
        MsgBox "無法開啟名稱為 ""MemMap"" 的共用記憶體"
    Else
        lpView = MapViewOfFile(hFileMap, FILE_MAP_READ Or FILE_MAP_WRITE, 0, 0, 0)
    End If
End Sub

Private Sub Form_Unload(Cancel As Integer)
    CloseHandle hFileMap
End Sub
