VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form frm_Glyph 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "TTF"
   ClientHeight    =   8355
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   9195
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   8355
   ScaleWidth      =   9195
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton CmdCancel 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   2760
      TabIndex        =   16
      Top             =   7920
      Width           =   2175
   End
   Begin VB.CommandButton CmdOk 
      Caption         =   "OK"
      Height          =   375
      Left            =   120
      TabIndex        =   15
      Top             =   7920
      Width           =   2175
   End
   Begin VB.TextBox Text6 
      Height          =   285
      Left            =   8160
      TabIndex        =   14
      Text            =   "1"
      Top             =   2880
      Visible         =   0   'False
      Width           =   975
   End
   Begin VB.TextBox Text5 
      Height          =   285
      Left            =   7200
      TabIndex        =   11
      Text            =   "100"
      Top             =   2400
      Width           =   975
   End
   Begin VB.TextBox Text4 
      Height          =   285
      Left            =   8160
      TabIndex        =   10
      Text            =   "0 "
      Top             =   1560
      Width           =   975
   End
   Begin VB.TextBox Text3 
      Height          =   285
      Left            =   8160
      TabIndex        =   7
      Text            =   "0 "
      Top             =   1080
      Width           =   975
   End
   Begin VB.TextBox Text2 
      Height          =   285
      Left            =   8160
      TabIndex        =   5
      Text            =   "100"
      Top             =   600
      Width           =   975
   End
   Begin VB.TextBox Text1 
      Height          =   405
      Left            =   1320
      TabIndex        =   4
      Text            =   "a"
      Top             =   120
      Width           =   5655
   End
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   6480
      Top             =   7800
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.ListBox List1 
      Height          =   4350
      Left            =   7200
      Sorted          =   -1  'True
      TabIndex        =   2
      Top             =   3360
      Width           =   1890
   End
   Begin VB.PictureBox Picture1 
      AutoRedraw      =   -1  'True
      BackColor       =   &H00FFFFFF&
      Height          =   7065
      Left            =   120
      ScaleHeight     =   467
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   453
      TabIndex        =   0
      Top             =   720
      Width           =   6855
      Begin VB.Label Label1 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "T"
         BeginProperty Font 
            Name            =   "Arial"
            Size            =   27.75
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   855
         Left            =   120
         TabIndex        =   1
         ToolTipText     =   "Vergleichslabel"
         Top             =   120
         Width           =   945
      End
   End
   Begin VB.Label Label9 
      Caption         =   "Input String"
      Height          =   375
      Left            =   120
      TabIndex        =   17
      Top             =   120
      Width           =   1095
   End
   Begin VB.Label Label8 
      Caption         =   "Chord Error"
      Height          =   255
      Left            =   7200
      TabIndex        =   13
      Top             =   2880
      Visible         =   0   'False
      Width           =   855
   End
   Begin VB.Label Label7 
      Caption         =   "% * Height"
      Height          =   255
      Left            =   8280
      TabIndex        =   12
      Top             =   2400
      Width           =   855
   End
   Begin VB.Label Label6 
      Caption         =   "Character Pitch"
      Height          =   255
      Left            =   7200
      TabIndex        =   9
      Top             =   2040
      Width           =   1815
   End
   Begin VB.Label Label5 
      Caption         =   "Y"
      Height          =   255
      Left            =   7200
      TabIndex        =   8
      Top             =   1560
      Width           =   855
   End
   Begin VB.Label Label4 
      Caption         =   "X"
      Height          =   255
      Left            =   7200
      TabIndex        =   6
      Top             =   1080
      Width           =   855
   End
   Begin VB.Label Label3 
      Caption         =   "Height"
      Height          =   255
      Left            =   7200
      TabIndex        =   3
      Top             =   600
      Width           =   855
   End
End
Attribute VB_Name = "frm_Glyph"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Private buf() As Long
Dim X1 As Long
Dim Y1 As Long
Dim fn As Long
Dim myFontSize As Single
Dim IfSave As Boolean


Private Sub GlyphTest()
   Dim metr As GLYPHMETRICS
   Dim char As Long
   Dim ret As Long
   Dim matz As mAt2
   
   Dim lngStartTime    As Long '計算時間長短變數
   Dim lngFinishTime   As Long

   If Trim(Text1.Text) <> "" Then char = Asc(Left$(Text1.Text, 1))
   
   If List1.ListIndex < 0 Then
       List1.ListIndex = 0
   End If
   
   Picture1.Cls         ' PictureBox
   Picture1.FontName = List1.List(List1.ListIndex)
   Picture1.FontSize = myFontSize
   Picture1.DrawWidth = 1
  
   matz = GetIdentityMatrix()             ' normale 1:1 Matrix
   'matz = GetShearMatrix()               ' lt. Beschreibung Italic Simluation, sieht aber nach Kursiv aus
   'matz = GetStrechMatrix(1.5, 0.75)     ' hier kann man um x/y Faktoren strecken
   'matz = GetRotationMatrix(360 - 45)    ' Rotation, funktioniert aber nicht mit 90 Grad
   
   lngStartTime = timeGetTime '紀錄未執行的時間
   ret = GetOutline(buf(), Picture1.hDC, char, GGO_NATIVE, metr, matz)
   DrawGlyph Sort(), buf(), Picture1, 0, 0, IfSave
   lngFinishTime = timeGetTime '紀錄執行後的時間
   

   Label1.FontName = Picture1.FontName
   Label1.FontSize = 80
   Label1.Caption = Chr$(char)
   On Error GoTo save1
save1:
End Sub

Private Sub CmdCancel_Click()
Unload Me
End Sub
Private Sub cmdOK_Click()
Dim MString As String
Dim metr As GLYPHMETRICS
Dim char As Long
Dim ret As Long
Dim matz As mAt2
Dim Xoff, Yoff, FontPercent
Dim lngStartTime    As Long '計算時間長短變數
Dim lngFinishTime   As Long


Xoff = CSng(Text3.Text)
Yoff = -CSng(Text4.Text)
FontPercent = CSng(Text5.Text)
lngStartTime = timeGetTime '紀錄未執行的時間

IfSave = True
If Trim(Text1.Text) <> "" Then
   MString = Text1.Text
   Do Until MString = ""
       char = Asc(Left$(MString, 1))
       MString = Right(MString, Len(MString) - 1)
       matz = GetIdentityMatrix()
       ret = GetOutline(buf(), Picture1.hDC, char, GGO_NATIVE, metr, matz)
       DrawGlyph Sort(), buf(), Picture1, Xoff, Yoff, IfSave
       Xoff = Xoff + myFontSize * (FontPercent / 100)
   On Error GoTo save1
  
save1:
   Loop
    Dim Divide, Ignore_A, Cone_A, Final_D
    Dim SortOut() As EngraveBlock
    Dim buf1 As Integer
    Dim ok As Integer
    Dim i As Integer
    Call mdlEngrave.mod_AutoDirection(Sort())
    Call mdlEngrave.Engrave_DataOutPut(Sort(), Divide, Ignore_A, Cone_A, Final_D, SortOut())
    ok = EngInitial(1, 0.1, (SortOut(1).Direction Mod 10))
    buf1 = UBound(SortOut)
    buf1 = UBound(SortOut(1).Child)
    ok = EngGetValue(SortOut(1).Child(1), 0, buf1)
    ok = EngCalculate()
    'Debug.Print UBound(SortOut)
 lngFinishTime = timeGetTime '紀錄執行後的時間
   MsgBox ("總計耗時：" & lngFinishTime - lngStartTime & " milliseconds!") '顯示花的總時間
Else
    Exit Sub
End If
Unload Me
End Sub

Private Sub Form_Activate()
'Open "test.txt" For Output As #1
End Sub

Private Sub Form_Unload(Cancel As Integer)
'Close #1
End Sub
Private Sub Form_Load()
Dim a1, a2, screenright1
Dim Ratio1 As Single, i As Long
Dim unit_index
ReDim Sort(0)
For i = 0 To Screen.FontCount - 1
    List1.AddItem Screen.Fonts(i)
Next
IfSave = False
myFontSize = CSng(Text2.Text)
    
Picture1.Cls
unit_index = Int(Picture1.ScaleHeight / 100)
Picture1.Line (0, 0 - unit_index)-(0, 0 + unit_index), RGB(0, 0, 255)
Picture1.Line (0 - unit_index, 0)-(0 + unit_index, 0), RGB(0, 0, 255)
Dim LimitTop, LimitBottom, LimitLeft, LimitRight
      LimitTop = myFontSize * 2
      LimitBottom = -myFontSize
      LimitLeft = -myFontSize
      LimitRight = Abs(Picture1.ScaleWidth / Picture1.ScaleHeight) * (LimitTop - LimitBottom) + LimitLeft
      Picture1.Scale (LimitLeft, LimitTop)-(LimitRight, LimitBottom)
List1.ListIndex = 0
End Sub

Private Sub Label1_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
    X1 = X
    Y1 = Y
End Sub

Private Sub List1_Click()
GlyphTest
End Sub

Private Sub Text1_Change()
GlyphTest
End Sub

Private Sub Text2_Change()
Dim LimitTop, LimitBottom, LimitLeft, LimitRight
If IsNumeric(Text2.Text) Then
    If Val(Text2.Text) < 0 Then
       Text2.Text = 100: Text2.SetFocus: Exit Sub
    ElseIf Val(Text2.Text) > 2000 Then
           Text2.Text = 2000: Text2.SetFocus: Exit Sub
    Else
           myFontSize = Val(Text2.Text)
    End If
Else
    Text2.SelStart = 0
    Text2.SelLength = Len(Text2.Text)
    Text2.SetFocus: Exit Sub
End If
End Sub

