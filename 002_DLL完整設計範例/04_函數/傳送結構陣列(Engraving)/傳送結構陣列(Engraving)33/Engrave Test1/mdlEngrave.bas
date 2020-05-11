Attribute VB_Name = "mdlEngrave"
Option Base 0
Public Sort() As MyBlock
Public Sub mod_AutoDirection(Sort() As MyBlock)   '0111/2005 Claudine
'宣告內外,找出左右
Dim i As Long, j As Long, k As Long

Dim Maxe_t, Maxe_b, Maxe_l, Maxe_r
Dim Mine_t, Mine_b, Mine_l, Mine_r
Dim CCW As Integer, max_right As Double, c_n As Integer
Dim InOutFlag As Boolean, OpenFlag As Boolean
Dim TempPick() As Long:    ReDim Preserve TempPick(0)
Dim TempPick1() As Long:    ReDim Preserve TempPick1(0)
Dim FirstRun() As Long:    ReDim Preserve FirstRun(0)
Dim SecondRun() As Long:   ReDim Preserve SecondRun(0)
Dim ThirdRun() As Long:    ReDim Preserve ThirdRun(0)
Dim InterNo As Integer
Dim MinId As Long
Dim MaxId As Long
Dim InFlag As Integer, Direc As Integer
Dim MaxFlag As Boolean

If UBound(Sort) > 0 Then
'1.先篩選封閉的圖形
   For i = 1 To UBound(Sort)
'       If Sort(i).IsClose = False And Sort(i).Child(1).C3 <> 3 Then
'          OpenFlag = True
'       Else
           ReDim Preserve TempPick(UBound(TempPick) + 1)
           TempPick(UBound(TempPick)) = i
'       End If
   Next i
'   If OpenFlag = True Then
'      MsgBox ("Open Geometry!")
'      Exit Sub
'   End If
'2.找出最小的圖元
Recursive:
  ' e_t = Maxe_t
  ' e_b = Maxe_b
  ' e_l = Maxe_l
  ' e_r = Maxe_r
   If UBound(TempPick) <= 0 Then GoSub Exit100
   For ii = 1 To UBound(TempPick)
       j = TempPick(ii)
       e_t = Sort(j).C21
       e_b = Sort(j).C22
       e_l = Sort(j).C23
       e_r = Sort(j).C24
       ReDim Preserve FirstRun(UBound(FirstRun) + 1)
       FirstRun(UBound(FirstRun)) = TempPick(ii)
       For kk = 1 To UBound(TempPick)
           If kk <> ii Then
              If Sort(TempPick(kk)).C21 > e_t And Sort(TempPick(kk)).C22 < e_b And _
                 Sort(TempPick(kk)).C23 < e_l And Sort(TempPick(kk)).C24 > e_r Then
                 ReDim Preserve FirstRun(UBound(FirstRun) + 1)
                 FirstRun(UBound(FirstRun)) = TempPick(kk)
              End If
           End If
       Next kk
   
'3.SWAP 排序由小到大
   For i = UBound(FirstRun) - 1 To 1 Step -1
       For j = 1 To i
           e_t = Sort(FirstRun(j + 1)).C21
           e_b = Sort(FirstRun(j + 1)).C22
           e_l = Sort(FirstRun(j + 1)).C23
           e_r = Sort(FirstRun(j + 1)).C24
           If Sort(FirstRun(j)).C21 > e_t And Sort(FirstRun(j)).C22 < e_b And _
              Sort(FirstRun(j)).C23 < e_l And Sort(FirstRun(j)).C24 > e_r Then
              temp = FirstRun(j)
              FirstRun(j) = FirstRun(j + 1)
              FirstRun(j + 1) = temp
           End If
       Next j
   Next i
   MinId = FirstRun(1)
'4.計算交點數
   If UBound(FirstRun) > 0 Then
      For i = 1 To UBound(FirstRun)
          If FirstRun(i) <> MinId Then
             Call mdlEngrave.Get_InterNo(Sort(), MinId, FirstRun(i), InterNo)
             If InterNo > 0 And InterNo Mod 2 = 0 Then  '沒有完全包住
             ElseIf InterNo > 0 And InterNo Mod 2 = 1 Then '完全被包住
                    ReDim Preserve ThirdRun(UBound(ThirdRun) + 1)
                    ThirdRun(UBound(ThirdRun)) = FirstRun(i)
             Else
             End If
          ElseIf FirstRun(i) = MinId Then
                 ReDim Preserve ThirdRun(UBound(ThirdRun) + 1)
                 ThirdRun(UBound(ThirdRun)) = FirstRun(i)
          End If
      Next i
   End If
'5.由外向內定義方向 ->  內外內外............
   k = UBound(ThirdRun)
   If k Mod 2 = 1 Then InFlag = 10 '內:10  外:20
   If k Mod 2 = 0 Then InFlag = 20
   j = ThirdRun(1)
   Call mdlEngrave.SetDirection(Sort(), j, InFlag, Direc)
  'ReDim Preserve Sort(UBound(Sort) + 1)
   Sort(UBound(Sort)) = Sort(TempPick(ii))
   Sort(UBound(Sort)).C9 = Direc
   
   ReDim Preserve FirstRun(0)
   ReDim Preserve SecondRun(0)
   ReDim Preserve ThirdRun(0)
  
   Next ii
   'Debug.Print UBound(Sort)
   
'   Call File.OpenM7(kk)
'   CCW = kk Mod 1000: CCW = Int(CCW / 100)
'   For i = 1 To UBound(Sort)
'       If CCW Mod 100 = 0 Then
'       Else
'          Direc = Sort(i).C9
'          If Direc = 11 Or Direc = 22 Then 'CCW
'             If CCW = 2 Then
'                Call mdlScale.DataReverse(Sort(), i)
'                If Direc = 11 Then Direc = 12
'                If Direc = 22 Then Direc = 21
'             End If
'          ElseIf Direc = 12 Or Direc = 21 Then 'CW
'                 If CCW = 1 Then
'                    Call mdlScale.DataReverse(Sort(), i)
'                    If Direc = 12 Then Direc = 11
'                    If Direc = 21 Then Direc = 22
'                 End If
'          End If
'          Sort(i).C9 = Direc
'       End If
'   Next i
   
   
Exit100:
   
End If

End Sub

Public Sub Engrave_DataOutPut(SortIn() As MyBlock, Divide, Ignore_A, Cone_A, Final_D, SortOut() As EngraveBlock)
Dim i As Long, j As Long
On Error GoTo ErrHandle
ReDim Preserve SortOut(0)
For i = 1 To UBound(SortIn)
    
    ReDim Preserve SortOut(UBound(SortOut) + 1)
    
    With SortOut(UBound(SortOut))
         .Divide = Divide
         .Ignore_A = Ignore_A
         .Cone_A = Cone_A
         .F_Depth = Final_D
         .Direction = SortIn(i).C9
    End With
    ReDim Preserve SortOut(UBound(SortOut)).Child(UBound(SortIn(i).Child))
    For j = 1 To UBound(SortIn(i).Child)
        With SortOut(UBound(SortOut)).Child(j)
             .Type = SortIn(i).Child(j).C3
             .X1 = SortIn(i).Child(j).C10
             .Y1 = SortIn(i).Child(j).C12
             .X2 = SortIn(i).Child(j).C11
             .Y2 = SortIn(i).Child(j).C13
             .Z2 = SortIn(i).Child(j).C14
             .CCW = SortIn(i).Child(j).C49
        End With
    Next j
Next i
       
ErrHandle:

End Sub

Public Sub SetDirection(Mydata() As MyBlock, ID As Long, InFlag As Integer, Direc As Integer)
Dim MidX As Double, MidY As Double, Vx As Double, Vy As Double, TX As Double, TY As Double
Dim i As Long, j As Long, k As Long
Dim InterNo As Integer
Dim Tns, Tne
Dim Xo, Yo, EL, ER, ET, EB, d, R
'找出第一個Entity的中點座標
 Call mdlEngrave.Get_snapmid(Mydata(), ID, 1, MidX, MidY)
 ''call mark(MidX, MidY)
 Call mdlEngrave.Cal_VxVy(Mydata(), ID, 1, MidX, MidY, Vx, Vy, TX, TY)
 ''call mark(MidX + Vx, MidY + Vy)
 mA1 = MidX
 mB1 = MidY
 mC1 = MidX + Vx
 mD1 = MidY + Vy
 mE1 = 0
 If UBound(Mydata(ID).Child) = 1 And Mydata(ID).Child(1).C3 = 3 Then
    If Mydata(ID).Child(1).C49 = 1 Then
       InterNo = InterNo + 1
    Else
       InterNo = 0
    End If
 Else
 For j = 2 To UBound(Mydata(ID).Child)
     ET = Mydata(ID).Child(j).C17
     EB = Mydata(ID).Child(j).C18
     EL = Mydata(ID).Child(j).C19
     ER = Mydata(ID).Child(j).C20
     Xo = (ER + EL) / 2
     Yo = (ET + EB) / 2
     d = Abs((Xo - mA1) * Vy - (Yo - mB1) * Vx)
     R = Sqr((ER - EL) ^ 2 + (ET - EB) ^ 2) / 2
     If d <= R Then
     Select Case Mydata(ID).Child(j).C3
            Case Is = 1
                     mA2 = Mydata(ID).Child(j).C10
                     mB2 = Mydata(ID).Child(j).C12
                     mC2 = Mydata(ID).Child(j).C11
                     mD2 = Mydata(ID).Child(j).C13
                     mE2 = 0
                     Call Computation.IntS_Point(1, mA1, mB1, mC1, mD1, mE1, mA2, mB2, mC2, mD2, mE2, mGap, mAns, mAx, mAy, mBx, mBy, mAs, mAe, mBs, mBe, mAt1, mAt2, mBt1, mBt2)
                     If mAns > 0 Then
                        If Int(mAns / 10) = 3 Or Int(mAns / 10) = 4 Then
                           '1.實交點才成立
                           If mBt1 > 0 And mBt1 < 1 And mAt1 * mBt1 > 0 Then InterNo = InterNo + 1 ': 'call mark(mAx, mAy)
                          
                        End If
                     End If
            Case Is = 2
                     mA2 = Mydata(ID).Child(j).C10
                     mB2 = Mydata(ID).Child(j).C12
                     mC2 = Mydata(ID).Child(j).C11
                     mD2 = Mydata(ID).Child(j).C13
                     mE2 = Mydata(ID).Child(j).C14
                     Call Computation.IntS_Point(2, mA1, mB1, mC1, mD1, mE1, mA2, mB2, mC2, mD2, mE2, mGap, mAns, mAx, mAy, mBx, mBy, mAs, mAe, mBs, mBe, mAt1, mAt2, mBt1, mBt2)
                     If mAns > 0 Then '切點不算交點
                        If Int(mAns / 10) = 3 Or Int(mAns / 10) = 4 Then
                           '1.非頭尾之實交點才成立
                           If mBt1 > 0 And mBt1 < 1 And mAt1 * mBt1 > 0 Then InterNo = InterNo + 1 ': 'call mark(mAx, mAy)
                           '2.位在頭尾相接之實交點
                           If mBt1 = 0 Or mBt1 = 1 Then 'MsgBox (mBt1)
                              Call mdlEngrave.Cal_VxVy(Mydata(), ID, j, mAx, mAy, V1x, V1y, T1X, T1Y)
                              DOT1 = T1X * Vx + T1Y * Vy
                              Cross1 = T1X * Vy - T1Y * Vx
                              If j = UBound(Mydata(ID).Child) Then
                                 k = 1
                              Else
                                 k = j + 1
                              End If
                              Call mdlEngrave.Cal_VxVy(Mydata(), ID, k, mAx, mAy, V1x, V1y, T1X, T1Y)
                              DOT2 = T1X * Vx + T1Y * Vy
                              Cross2 = T1X * Vy - T1Y * Vx
                              If Cross1 * Cross2 > 0 Then InterNo = InterNo + 1 ': 'call mark(mAx, mAy)
                           End If
                        End If
                        
                        If mAns Mod 10 = 3 Or mAns Mod 10 = 4 Then
                           If mBt2 > 0 And mBt2 < 1 And mAt2 * mBt2 > 0 Then InterNo = InterNo + 1
                           If mBt2 = 0 Or mBt2 = 1 Then 'MsgBox (mBt2)
                              Call mdlEngrave.Cal_VxVy(Mydata(), ID, j, mBx, mBy, V1x, V1y, T1X, T1Y)
                              DOT1 = T1X * Vx + T1Y * Vy
                              Cross1 = T1X * Vy - T1Y * Vx
                              If j = UBound(Mydata(ID).Child) Then
                                 k = 1
                              Else
                                 k = j + 1
                              End If
                              Call mdlEngrave.Cal_VxVy(Mydata(), ID, k, mAx, mAy, V1x, V1y, T1X, T1Y)
                              DOT2 = T1X * Vx + T1Y * Vy
                              Cross2 = T1X * Vy - T1Y * Vx
                              If Cross1 * Cross2 > 0 Then InterNo = InterNo + 1: 'call mark(mBx, mBy)
                           End If
                        End If
                     End If
     End Select
     End If
 Next j
 End If

 If InterNo Mod 2 = 0 Then '偶數左為外
    If InFlag = 10 Then  'Inside
       Direc = 12
    ElseIf InFlag = 20 Then 'Outside
           Direc = 21
    ElseIf InFlag = 1 Then 'Left
           Direc = 21
    ElseIf InFlag = 2 Then 'Right
           Direc = 12
    ElseIf InFlag = 0 Then
           Direc = 200
    End If
 Else '奇數左為內
    If InFlag = 10 Then  'Inside
       Direc = 11
    ElseIf InFlag = 20 Then 'Outside
           Direc = 22
    ElseIf InFlag = 1 Then 'Left
           Direc = 11
    ElseIf InFlag = 2 Then 'Right
           Direc = 22
    ElseIf InFlag = 0 Then
           Direc = 100
    End If
 End If
End Sub
Public Sub Get_snapmid(ByRef Mydata() As MyBlock, TreeId, ChildID, x_snap, y_snap)
'輸入指定的資料Mydata(),TreeID,ChildID,回傳中點座標值
Dim del_y, del_x, s_a, e_a, Theta
Dim X1 As Double, X2 As Double, Y1 As Double, Y2 As Double
Dim mA1 As Double, mB1 As Double, mC1 As Double, mD1 As Double, mE1 As Double
Dim PI As Double
On Error Resume Next
Dim Ints() As Double
PI = 4 * Atn(1)

Select Case Mydata(TreeId).Child(ChildID).C3
            Case Is = 1, 7, 51
                 X1 = Mydata(TreeId).Child(ChildID).C10
                 X2 = Mydata(TreeId).Child(ChildID).C11
                 Y1 = Mydata(TreeId).Child(ChildID).C12
                 Y2 = Mydata(TreeId).Child(ChildID).C13
                 x_snap = (X1 + X2) / 2
                 y_snap = (Y1 + Y2) / 2
            Case Is = 2, 3, 52, 53, 54, 55
                  ReDim Ints(7, 3)
                  mA1 = Mydata(TreeId).Child(ChildID).C10
                  mB1 = Mydata(TreeId).Child(ChildID).C12
                  mC1 = Mydata(TreeId).Child(ChildID).C11
                  mD1 = Mydata(TreeId).Child(ChildID).C13
                  mE1 = Mydata(TreeId).Child(ChildID).C14
                  Ints(1, 1) = mA1 + mC1 * Cos(mD1)
                  Ints(2, 1) = mB1 + mC1 * Sin(mD1)
                  Ints(5, 1) = 1 'end point
                  Ints(1, 2) = mA1 + mC1 * Cos(mE1)
                  Ints(2, 2) = mB1 + mC1 * Sin(mE1)
                  Ints(5, 2) = 1 'end point
      
                  mAi = (mE1 + mD1) / 2
                  If mE1 <= mD1 Then
                     mAi = (mE1 + 2 * PI + mD1) / 2
                     If (mE1 + 2 * PI + mD1) / 2 > 2 * PI Then
                        mAi = mAi - 2 * PI
                     End If
                  End If
         
                  Ints(1, 3) = mA1 + mC1 * Cos(mAi)
                  Ints(2, 3) = mB1 + mC1 * Sin(mAi)
                  Ints(5, 3) = 2 'mid point
                  Ints(3, 3) = mAi
                  x_snap = Ints(1, 3)
                  y_snap = Ints(2, 3)
End Select
End Sub
Public Sub Cal_VxVy(ByRef Sort() As MyBlock, TreeId As Long, ChildID As Long, X, Y, Vx, Vy, TX, TY)
Dim X1, Y1, X2, Y2, X0, Y0
On Error Resume Next
  
   
      If Sort(TreeId).Child(ChildID).C3 = 1 Then
         X1 = Sort(TreeId).Child(ChildID).C10
         X2 = Sort(TreeId).Child(ChildID).C11
         Y1 = Sort(TreeId).Child(ChildID).C12
         Y2 = Sort(TreeId).Child(ChildID).C13
         Dist = Sqr((X2 - X1) ^ 2 + (Y2 - Y1) ^ 2) 'scale length
         '單位方向向量
         TX = (X2 - X1) / Dist
         TY = (Y2 - Y1) / Dist
         '單位法向向量
         '定義往左為正
         Vx = -TY
         Vy = TX
      Else
         X0 = Sort(TreeId).Child(ChildID).C10
         Y0 = Sort(TreeId).Child(ChildID).C12
         Dist = Sqr((X - X0) ^ 2 + (Y - Y0) ^ 2) 'scale length
         Rx = (X - X0) / Dist
         Ry = (Y - Y0) / Dist
         '單位方向向量
         If Sort(TreeId).Child(ChildID).C49 = 0 Then
            TX = Ry '-Sin(StaA)
            TY = -Rx 'Cos(StaA)
         Else
            TX = -Ry 'Sin(EndA)
            TY = Rx '-Cos(EndA)
         End If
         '單位法向向量
         '定義往左為正
         Vx = -TY
         Vy = TX
      End If
End Sub
Public Sub CheckEntity(draw_type, X1, Y1, X2, Y2, StartAngle, EndAngle, _
                       Top, Bottom, Left, Right)
Dim temp 'As Single
Dim start_a, End_A ' As Single
Dim PI 'As Single

PI = 4 * Atn(1)

If draw_type = 1 Or draw_type = 7 Or draw_type = 51 Then 'Line
     If X2 >= X1 Then
        Left = X1
        Right = X2
     ElseIf X2 < X1 Then
        Left = X2
        Right = X1
     End If
     If Y2 >= Y1 Then
        Bottom = Y1
        Top = Y2
     Else
        Bottom = Y2
        Top = Y1
     End If
    
  ElseIf draw_type = 2 Or draw_type = 52 Then  'Arc
         start_a = StartAngle
         End_A = EndAngle
         'CheckEntity(draw_type, x1, y1,x2,y2,startangle,endangle)
         'CheckEntity(draw_type, xo, yo, RAD, 0,startangle,endangle)
         Right = X1 + X2 * Cos(start_a)
         Left = X1 + X2 * Cos(End_A)
         Top = Y1 + X2 * Sin(End_A)
         Bottom = Y1 + X2 * Sin(start_a)
         If Left > Right Then
            temp = Left:            Left = Right:            Right = temp
         End If
         If Bottom > Top Then
            temp = Top:            Top = Bottom:            Bottom = temp
         End If
         'Select Case start_a
         'Case Is <= PI / 2 And start_a > 0
         If start_a <= PI / 2 And start_a > 0 Then
              If End_A >= PI / 2 Then Top = Y1 + X2
              If End_A >= PI Then Left = X1 - X2
              If End_A >= 3 * PI / 2 Then Bottom = Y1 - X2
              If End_A <= PI / 2 And start_a > End_A Then
                 Left = X1 - X2
                 Right = X1 + X2
                 Top = Y1 + X2
                 Bottom = Y1 - X2
              End If
         ElseIf start_a <= PI And start_a > PI / 2 Then
              If End_A >= PI Then Left = X1 - X2
              If End_A >= 3 * PI / 2 Then
                 Left = X1 - X2
                 Bottom = Y1 - X2
              End If
              If End_A <= PI / 2 And start_a > End_A Then
                 Left = X1 - X2
                 Right = X1 + X2
                 Bottom = Y1 - X2
              End If
              If End_A <= PI And start_a > End_A Then
                 Left = X1 - X2
                 Right = X1 + X2
                 Top = Y1 + X2
                 Bottom = Y1 - X2
              End If
          ElseIf start_a <= 3 * PI / 2 And start_a > PI Then
              If End_A >= 3 * PI / 2 Then Bottom = Y1 - X2
              If End_A <= PI / 2 And start_a > End_A Then
                 Right = X1 + X2
                 Bottom = Y1 - X2
              End If
              If End_A <= PI And start_a > End_A Then
                 Right = X1 + X2
                 Top = Y1 + X2
                 Bottom = Y1 - X2
              End If
              If End_A <= 3 * PI / 2 And start_a > End_A Then
                 Left = X1 - X2
                 Right = X1 + X2
                 Top = Y1 + X2
                 Bottom = Y1 - X2
              End If
          ElseIf start_a <= 2 * PI And start_a > 3 * PI / 2 Then
              If End_A <= PI / 2 Then Right = X1 + X2
              If End_A <= PI Then
                 Right = X1 + X2
                 Top = Y1 + X2
              End If
              If End_A <= 3 * PI / 2 Then
                 Right = X1 + X2
                 Top = Y1 + X2
                 Left = X1 - X2
              End If
              If End_A <= 2 * PI And start_a > End_A Then
                 Left = X1 - X2
                 Right = X1 + X2
                 Top = Y1 + X2
                 Bottom = Y1 - X2
              End If
          End If
        '  '''debug.print top, Bottom, Left, Right
  ElseIf draw_type = 3 Or draw_type = 53 Then  'Circle
         'Check(draw_type, x1, y1,x2,y2,startangle,endangle)
         'Check(draw_type, xo, yo, RAD, 0,0,0)
         Top = Y1 + X2     'yo+RAD
         Bottom = Y1 - X2  'yo-RAD
         Left = X1 - X2    'xo-RAD
         Right = X1 + X2   'xo+RAD
Dim w As Single, H As Single, D1 As Single, D2 As Single
  ElseIf draw_type = 8 Then  'Ellipse
         w = X2: H = Y2 ': D1 = Startangle: D2 = Endangle
         Top = Y1 + H
         Bottom = Y1 - H
         Left = X1 - w
         Right = X1 + w
  End If
End Sub
Public Sub Get_InterNo(Mydata() As MyBlock, ID1 As Long, ID As Long, InterNo As Integer)
Dim MidX As Double, MidY As Double, Vx As Double, Vy As Double, TX As Double, TY As Double
Dim i As Long, j As Long, k As Long
Dim Tns, Tne
Dim Xo, Yo, EL, ER, ET, EB, d, R
'找出第一個Entity的中點座標
 Call mdlEngrave.Get_snapmid(Mydata(), ID1, 1, MidX, MidY)
 ''call mark(MidX, MidY)
 Call mdlEngrave.Cal_VxVy(Mydata(), ID1, 1, MidX, MidY, Vx, Vy, TX, TY)
 ''call mark(MidX + Vx, MidY + Vy)
 mA1 = MidX
 mB1 = MidY
 mC1 = MidX + Vx
 mD1 = MidY + Vy
 mE1 = 0
  
 InterNo = 0
 For j = 1 To UBound(Mydata(ID).Child)
     ET = Mydata(ID).Child(j).C17
     EB = Mydata(ID).Child(j).C18
     EL = Mydata(ID).Child(j).C19
     ER = Mydata(ID).Child(j).C20
     Xo = (ER + EL) / 2
     Yo = (ET + EB) / 2
     d = Abs((Xo - mA1) * Vy - (Yo - mB1) * Vx)
     R = Sqr((ER - EL) ^ 2 + (ET - EB) ^ 2) / 2
     If d <= R Then
     Select Case Mydata(ID).Child(j).C3
            Case Is = 1
                     mA2 = Mydata(ID).Child(j).C10
                     mB2 = Mydata(ID).Child(j).C12
                     mC2 = Mydata(ID).Child(j).C11
                     mD2 = Mydata(ID).Child(j).C13
                     mE2 = 0
                     Call Computation.IntS_Point(1, mA1, mB1, mC1, mD1, mE1, mA2, mB2, mC2, mD2, mE2, mGap, mAns, mAx, mAy, mBx, mBy, mAs, mAe, mBs, mBe, mAt1, mAt2, mBt1, mBt2)
                     If mAns > 0 Then
                        If Int(mAns / 10) = 3 Or Int(mAns / 10) = 4 Then
                           '1.實交點才成立
                           If mBt1 > 0 And mBt1 < 1 And mAt1 * mBt1 > 0 Then InterNo = InterNo + 1 ': 'call mark(mAx, mAy)
                          
                        End If
                     End If
            Case Is = 2, 3
                     mA2 = Mydata(ID).Child(j).C10
                     mB2 = Mydata(ID).Child(j).C12
                     mC2 = Mydata(ID).Child(j).C11
                     mD2 = Mydata(ID).Child(j).C13
                     mE2 = Mydata(ID).Child(j).C14
                     Call Computation.IntS_Point(2, mA1, mB1, mC1, mD1, mE1, mA2, mB2, mC2, mD2, mE2, mGap, mAns, mAx, mAy, mBx, mBy, mAs, mAe, mBs, mBe, mAt1, mAt2, mBt1, mBt2)
                     If mAns > 0 Then '切點不算交點
                        If Int(mAns / 10) = 3 Or Int(mAns / 10) = 4 Then
                           '1.非頭尾之實交點才成立
                           If mBt1 > 0 And mBt1 < 1 And mAt1 * mBt1 > 0 Then InterNo = InterNo + 1 ': 'call mark(mAx, mAy)
                           '2.位在頭尾相接之實交點
                           If mBt1 = 0 Or mBt1 = 1 Then 'MsgBox (mBt1)
                              Call mdlEngrave.Cal_VxVy(Mydata(), ID, j, mAx, mAy, V1x, V1y, T1X, T1Y)
                              DOT1 = T1X * Vx + T1Y * Vy
                              Cross1 = T1X * Vy - T1Y * Vx
                              If j = UBound(Mydata(ID).Child) Then
                                 k = 1
                              Else
                                 k = j + 1
                              End If
                              Call mdlEngrave.Cal_VxVy(Mydata(), ID, k, mAx, mAy, V1x, V1y, T1X, T1Y)
                              DOT2 = T1X * Vx + T1Y * Vy
                              Cross2 = T1X * Vy - T1Y * Vx
                              If Cross1 * Cross2 > 0 Then InterNo = InterNo + 1 ': 'call mark(mAx, mAy)
                           End If
                        End If
                        
                        If mAns Mod 10 = 3 Or mAns Mod 10 = 4 Then
                           If mBt2 > 0 And mBt2 < 1 And mAt2 * mBt2 > 0 Then InterNo = InterNo + 1: 'call mark(mBx, mBy)
                           If mBt2 = 0 Or mBt2 = 1 Then 'MsgBox (mBt2)
                              Call mdlEngrave.Cal_VxVy(Mydata(), ID, j, mBx, mBy, V1x, V1y, T1X, T1Y)
                              DOT1 = T1X * Vx + T1Y * Vy
                              Cross1 = T1X * Vy - T1Y * Vx
                              If j = UBound(Mydata(ID).Child) Then
                                 k = 1
                              Else
                                 k = j + 1
                              End If
                              Call mdlEngrave.Cal_VxVy(Mydata(), ID, k, mAx, mAy, V1x, V1y, T1X, T1Y)
                              DOT2 = T1X * Vx + T1Y * Vy
                              Cross2 = T1X * Vy - T1Y * Vx
                              If Cross1 * Cross2 > 0 Then InterNo = InterNo + 1: 'call mark(mBx, mBy)
                           End If
                        End If
                     End If
     End Select
     End If
 Next j


End Sub

