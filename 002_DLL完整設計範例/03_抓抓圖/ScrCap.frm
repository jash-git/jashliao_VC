VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form frmCopyScreen 
   Caption         =   "螢幕抓取程式"
   ClientHeight    =   2910
   ClientLeft      =   2055
   ClientTop       =   2970
   ClientWidth     =   4425
   LinkTopic       =   "Form1"
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   2910
   ScaleWidth      =   4425
   Begin VB.Timer Timer1 
      Interval        =   1000
      Left            =   3960
      Top             =   2400
   End
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   3600
      Top             =   960
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.PictureBox Picture1 
      AutoRedraw      =   -1  'True
      FillStyle       =   4  'Upward Diagonal
      Height          =   2535
      Left            =   0
      ScaleHeight     =   2475
      ScaleWidth      =   2835
      TabIndex        =   2
      Top             =   0
      Width           =   2895
      Begin VB.PictureBox picCopy 
         BorderStyle     =   0  'None
         Height          =   855
         Left            =   840
         ScaleHeight     =   855
         ScaleWidth      =   1335
         TabIndex        =   3
         Top             =   1080
         Width           =   1335
      End
   End
   Begin VB.HScrollBar HScroll1 
      Height          =   255
      Left            =   0
      TabIndex        =   1
      Top             =   2520
      Width           =   2895
   End
   Begin VB.VScrollBar VScroll1 
      Height          =   2535
      Left            =   2880
      TabIndex        =   0
      Top             =   0
      Width           =   255
   End
   Begin VB.Menu mCopyScreen 
      Caption         =   "我抓我抓我抓抓"
   End
   Begin VB.Menu mSaveFile 
      Caption         =   "儲存檔案"
   End
End
Attribute VB_Name = "frmCopyScreen"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim time As Integer
Sub SetPicture()
   picCopy.Visible = True
   ' 判別 Image 的寬度是否小於 PictureBox 的寬度
   If picCopy.Width <= Picture1.ScaleWidth Then
       picCopy.Left = (Picture1.ScaleWidth - picCopy.Width) / 2
   Else ' Image 的寬度大於 PictureBox 的寬度
       picCopy.Left = 0
       HScroll1.Min = 0
       HScroll1.Value = 0
       HScroll1.Max = picCopy.Width - Picture1.ScaleWidth
       HScroll1.SmallChange = HScroll1.Max / 100
       HScroll1.LargeChange = HScroll1.Max / 10
   End If

   ' 判別 Image 的高度是否小於 PictureBox 的高度
   If picCopy.Height <= Picture1.ScaleHeight Then
       picCopy.Top = (Picture1.ScaleHeight - picCopy.Height) / 2
   Else ' Image 的高度大於 PictureBox 的高度
       picCopy.Top = 0
       VScroll1.Min = 0
       VScroll1.Value = 0
       VScroll1.Max = picCopy.Height - Picture1.ScaleHeight
       VScroll1.SmallChange = VScroll1.Max / 100
       VScroll1.LargeChange = VScroll1.Max / 10
   End If
End Sub

Private Sub Form_Resize()
    On Error Resume Next
    Picture1.Width = Me.ScaleWidth - VScroll1.Width
    Picture1.Height = Me.ScaleHeight - HScroll1.Height
    VScroll1.Left = Picture1.Width
    HScroll1.Top = Picture1.Height
    VScroll1.Height = Picture1.Height
    HScroll1.Width = Picture1.Width
    
    SetPicture
End Sub

Private Sub HScroll1_Change()
    picCopy.Left = -HScroll1.Value
End Sub
Private Sub mCopyScreen_Click()
    Dim hDC As Long, sx As Integer, sy As Integer
    
    Me.Hide
    DoEvents    ' 若不執行此一敘述，可讓 Me.Hide 不會即時被執行
    
    picCopy.Width = Screen.Width
    picCopy.Height = Screen.Height
    
    picCopy.AutoRedraw = True
    
    ' 圖像的轉移
    hDC = GetDC(0)                              ' 取得螢幕DC
    sx = Screen.Width \ Screen.TwipsPerPixelX   ' 螢幕寬度(以Pixel為單位)
    sy = Screen.Height \ Screen.TwipsPerPixelY  ' 螢幕高度(以Pixel為單位)
    ' 將螢幕DC的圖像轉移到名稱為picCopy的PictureBox中
    BitBlt picCopy.hDC, 0, 0, sx, sy, hDC, 0, 0, vbSrcCopy
    ReleaseDC 0, hDC                            ' 釋放螢幕DC
    
    picCopy.AutoRedraw = False
    
    SetPicture      ' 設定 PictureBox 與捲動軸之間的關係
    Me.Show
End Sub

Private Sub mSaveFile_Click()
   On Error Resume Next
   With CommonDialog1
      .DialogTitle = "儲存檔案"
      .Filter = "點陣檔(*.bmp)|*.bmp"
      .CancelError = True
      .ShowOpen
      If Err.Number <> cdlCancel Then
         SavePicture picCopy.Picture, .FileName
      End If
   End With
End Sub

Private Sub Timer1_Timer()
mCopyScreen_Click
Dim str1 As String
time = time + 1
Call DC2DC(picCopy.hDC, picCopy.ScaleWidth / 15, picCopy.ScaleHeight / 15)

End Sub

Private Sub VScroll1_Change()
    picCopy.Top = -VScroll1.Value
End Sub


