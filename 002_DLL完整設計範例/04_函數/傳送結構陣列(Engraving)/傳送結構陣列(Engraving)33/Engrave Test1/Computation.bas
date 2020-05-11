Attribute VB_Name = "Computation"
Private Type TypezxdPoint
    X As Single
    Y As Single
    any As Single
End Type







  




'================================================================================
' 名    稱:     IntS_Point()
' 程 式 師:     Jason Wang
' 日    期:     July/13/2004
' 目    的:     已知兩個Element(Line & Line //Line & Arc // Arc & Arc) 求交點。
' 輸 入 值:
'               Element1:     mA1, mB1, mC1, mD1, mE1
'               Element2:     mA2, mB2, mC2, mD2, mE2
'               mType : 1: line-line 2: line-arc 3: arc-arc
'               mA1:X1sX1c;  mB1:Y1sY1c;  mC1:X1eR1;  mD1:Y1eA1s;  mE1:A1e
'               mA2:X2sX2c;  mB2:Y2sY2c;  mC2:X2eR2;  mD2:Y2eA2s;  mE2:A2e
'               mGap : tolerance
' 傳 回 值:
'               mAns = 0 ' no intersection point
'               mAns = XY, X=1~4, Y=1~4, X:first intersection status Y:second intersection status
'               1 : virtual intersection on first entity and second entity
'               2 : real intersection on first entity and virtual intersection on second entity
'               3 : virtual intersection on first entity and real intersection on second entity
'               4 : real intersection on first entity and real intersection on second entity
'               mAx: the X coordinate of first intersection
'               mAy: the Y coordinate of first intersection
'               mBx: the X coordinate of second intersection
'               mBy: the Y coordinate of second intersection
'               mAs: the angle of first intersection on first arc entity
'               mAe: the angle of second intersection on first arc entity
'               mBs: the angle of first intersection on second arc entity
'               mBe: the angle of second intersection on second arc entity
' 功    能:     求交點並傳回實交點或虛交點。
'================================================================================
Public Sub IntS_Point(mType, mA1, mB1, mC1, mD1, mE1, mA2, mB2, mC2, mD2, mE2, mGap, _
                      mAns, mAx, mAy, mBx, mBy, mAs, mAe, mBs, mBe, mAt1, mAt2, mBt1, mBt2)
'mType : [in] 1: line-line 2: line-arc 3: arc-arc
'mA1   : [in] X1sX1c;
'mB1   : [in] Y1sY1c;
'mC1   : [in] X1eR1;
'mD1   : [in] Y1eA1s;
'mE1   : [in] A1e;
'mA2   : [in] X2sX2c;
'mB2   : [in] Y2sY2c;
'mC2   : [in] X2eR2;
'mD2   : [in] Y2eA2s;
'mE2   : [in] A2e;
'mGap  : [in] tolerance
'mAns  : [out] = 0 ' no intersection point
'              = XY, X=1~4, Y=1~4, X:first intersection status Y:second intersection status
'              1 : virtual intersection on first entity and second entity
'              2 : real intersection on first entity and virtual intersection on second entity
'              3 : virtual intersection on first entity and real intersection on second entity
'              4 : real intersection on first entity and real intersection on second entity
'mAx   : [out] the X coordinate of first intersection
'mAy   : [out] the Y coordinate of first intersection
'mBx   : [out] the X coordinate of second intersection
'mBy   : [out] the Y coordinate of second intersection
'mAs   : [out] the angle of first intersection on first arc entity
'mAe   : [out] the angle of second intersection on first arc entity
'mBs   : [out] the angle of first intersection on second arc entity
'mBe   : [out] the angle of second intersection on second arc entity
'mAt1  : [out] the t parameter coordinate of first intersection on first entity
'mAt2  : [out] the t parameter coordinate of second intersection on first entity
'mBt1  : [out] the t parameter coordinate of first intersection on second entity
'mBt2  : [out] the t parameter coordinate of second intersection on second entity

Dim T1, T2, TT, AT1, AT2, mGapp As Double
Dim mL, mLMax, mLMin, mV1, mV2 As Double
Dim rA1, rB1, rC1, rD1 As Double
'On Error GoTo err1:
   mAns = 0
   pie = 4 * Atn(1)
   
   Select Case mType
          Case 1 ' intersection between two lines
               TT = (mD1 - mB1) * (mC2 - mA2) - (mC1 - mA1) * (mD2 - mB2)
               If TT = 0 Then Exit Sub
               mAt1 = ((mB2 - mB1) * (mC2 - mA2) - (mA2 - mA1) * (mD2 - mB2)) / TT
               mBt1 = ((mD1 - mB1) * (mA1 - mA2) - (mC1 - mA1) * (mB1 - mB2)) / TT
               mAx = (mC1 - mA1) * mAt1 + mA1
               mAy = (mD1 - mB1) * mAt1 + mB1
               
               T1 = Abs(mAt1 - 0.5)
               T2 = Abs(mBt1 - 0.5)
               If T1 > 0.5 + mGap And T2 > 0.5 + mGap Then
                  mAns = 10
               ElseIf T1 <= 0.5 + mGap And T2 > 0.5 + mGap Then
                  mAns = 20
               ElseIf T1 > 0.5 + mGap And T2 <= 0.5 + mGap Then
                  mAns = 30
               Else
                  mAns = 40
               End If
               
          Case 2 ' intersection between line and arc
               mL = (mC1 - mA1) ^ 2 + (mD1 - mB1) ^ 2
               mV1 = mL * (mC2 ^ 2) - ((mD1 - mB1) * (mA2 - mA1) - (mC1 - mA1) * (mB2 - mB1)) ^ 2
               If mL = 0 Or mC2 = 0 Then Exit Sub     ' no line or no radius
               mLMax = mC2 - Abs((mC1 - mA1) * (mB2 - mB1) - (mD1 - mB1) * (mA2 - mA1)) / Sqr(mL)
               mV2 = (mC1 - mA1) * (mA2 - mA1) + (mD1 - mB1) * (mB2 - mB1)
               mGapp = mGap * 2 ^ Len(CStr(Fix(Abs(mA1) + Abs(mA2) + Abs(mB1) + Abs(mB2) + Abs(mC1) + Abs(mD1))))
               
               If mLMax < mGapp Then
                  If Abs(mLMax) < mGapp Then           'tangent point
                     mAt1 = mV2 / mL
                     mAx = (mC1 - mA1) * mAt1 + mA1
                     mAy = (mD1 - mB1) * mAt1 + mB1
                     Call CalIntTconst(mAx, mAy, mA2, mB2, mC2, mD2, mE2, pie, mBs, mBt1)
                     T1 = Abs(mAt1 - 0.5)
                     AT1 = Abs(mBt1 - 0.5)
                     If T1 > 0.5 + mGap And AT1 > 0.5 + mGap Then
                        mAns = 10
                     ElseIf T1 <= 0.5 + mGap And AT1 > 0.5 + mGap Then
                        mAns = 20
                     ElseIf T1 > 0.5 + mGap And AT1 <= 0.5 + mGap Then
                        mAns = 30
                     Else
                        mAns = 40
                     End If
                     Exit Sub
                  Else
                     Exit Sub                          'no intersetion
                  End If
               End If
               
               mAt1 = (mV2 + Sqr(mV1)) / mL
               mAt2 = (mV2 - Sqr(mV1)) / mL
               
               mAx = (mC1 - mA1) * mAt1 + mA1
               mAy = (mD1 - mB1) * mAt1 + mB1
               mBx = (mC1 - mA1) * mAt2 + mA1
               mBy = (mD1 - mB1) * mAt2 + mB1
               
               Call CalIntTconst(mAx, mAy, mA2, mB2, mC2, mD2, mE2, pie, mBs, mBt1)
               
               Call CalIntTconst(mBx, mBy, mA2, mB2, mC2, mD2, mE2, pie, mBe, mBt2)
               
               
               T1 = Abs(mAt1 - 0.5)
               AT1 = Abs(mBt1 - 0.5)
               If T1 > 0.5 + mGap And AT1 > 0.5 + mGap Then
                  mAns = 10
               ElseIf T1 <= 0.5 + mGap And AT1 > 0.5 + mGap Then
                  mAns = 20
               ElseIf T1 > 0.5 + mGap And AT1 <= 0.5 + mGap Then
                  mAns = 30
               Else
                  mAns = 40
               End If
               
               T2 = Abs(mAt2 - 0.5)
               AT2 = Abs(mBt2 - 0.5)
               If T2 > 0.5 + mGap And AT2 > 0.5 + mGap Then
                  mAns = mAns + 1
               ElseIf T2 <= 0.5 + mGap And AT2 > 0.5 + mGap Then
                  mAns = mAns + 2
               ElseIf T2 > 0.5 + mGap And AT2 <= 0.5 + mGap Then
                  mAns = mAns + 3
               Else
                  mAns = mAns + 4
               End If
               
               
          Case 3 'intersection between two arcs
               mL = Sqr((mA2 - mA1) ^ 2 + (mB2 - mB1) ^ 2)
               mLMax = mL - mC2 - mC1
               mLMin = mL - Abs(mC1 - mC2)
               mGapp = mGap * 2 ^ Len(CStr(Fix(Abs(mA1) + Abs(mA2) + Abs(mB1) + Abs(mB2))))
               
               If mLMax > mGapp Or mLMin < -mGapp Or mL < mGap Then Exit Sub 'no intersection (inside or outside)
               
               If Abs(mLMax) < mGapp Or Abs(mLMin) < mGapp Then            ''tangent
                  
                  If Abs(mLMax) < mGapp Then
                     mAx = mA1 + (mA2 - mA1) * mC1 / (mC1 + mC2)
                     mAy = mB1 + (mB2 - mB1) * mC1 / (mC1 + mC2)
                  Else
                     mAx = mA1 + (mA2 - mA1) * mC1 / (mC1 - mC2)
                     mAy = mB1 + (mB2 - mB1) * mC1 / (mC1 - mC2)
                  End If
                  Call CalIntTconst(mAx, mAy, mA1, mB1, mC1, mD1, mE1, pie, mAs, mAt1)
                  Call CalIntTconst(mAx, mAy, mA2, mB2, mC2, mD2, mE2, pie, mBs, mBt1)

                  T1 = Abs(mAt1 - 0.5)
                  AT1 = Abs(mBt1 - 0.5)
                  If T1 > 0.5 + mGap And AT1 > 0.5 + mGap Then
                     mAns = 10
                  ElseIf T1 <= 0.5 + mGap And AT1 > 0.5 + mGap Then
                     mAns = 20
                  ElseIf T1 > 0.5 + mGap And AT1 <= 0.5 + mGap Then
                     mAns = 30
                  Else
                     mAns = 40
                  End If
                  
                  Exit Sub
               End If
                  
               mV1 = (mL ^ 2 + mC2 ^ 2 - mC1 ^ 2) / (2 * mL ^ 2)
               rA1 = (mA1 - mA2) * mV1 + mA2
               rB1 = (mB1 - mB2) * mV1 + mB2
               rC1 = rA1 + mB2 - mB1
               rD1 = rB1 + mA1 - mA2
               
               mL = (rC1 - rA1) ^ 2 + (rD1 - rB1) ^ 2
               mV1 = mL * (mC2 ^ 2) - ((rD1 - rB1) * (mA2 - rA1) - (rC1 - rA1) * (mB2 - rB1)) ^ 2
               mV2 = (rC1 - rA1) * (mA2 - rA1) + (rD1 - rB1) * (mB2 - rB1)
               T1 = (mV2 + Sqr(mV1)) / mL
                              
               mAx = (rC1 - rA1) * T1 + rA1
               mAy = (rD1 - rB1) * T1 + rB1
               mBx = (rC1 - rA1) * (-T1) + rA1
               mBy = (rD1 - rB1) * (-T1) + rB1
               
               Call CalIntTconst(mAx, mAy, mA1, mB1, mC1, mD1, mE1, pie, mAs, mAt1)
               Call CalIntTconst(mBx, mBy, mA1, mB1, mC1, mD1, mE1, pie, mAe, mAt2)
               
               
               '*********
               'second arc
               Call CalIntTconst(mAx, mAy, mA2, mB2, mC2, mD2, mE2, pie, mBs, mBt1)
               Call CalIntTconst(mBx, mBy, mA2, mB2, mC2, mD2, mE2, pie, mBe, mBt2)
               
               
               T1 = Abs(mAt1 - 0.5)
               AT1 = Abs(mBt1 - 0.5)
               If T1 > 0.5 + mGap And AT1 > 0.5 + mGap Then
                  mAns = 10
               ElseIf T1 <= 0.5 + mGap And AT1 > 0.5 + mGap Then
                  mAns = 20
               ElseIf T1 > 0.5 + mGap And AT1 <= 0.5 + mGap Then
                  mAns = 30
               Else
                  mAns = 40
               End If
               
               
               
               T2 = Abs(mAt2 - 0.5)
               AT2 = Abs(mBt2 - 0.5)
               If T2 > 0.5 + mGap And AT2 > 0.5 + mGap Then
                  mAns = mAns + 1
               ElseIf T2 <= 0.5 + mGap And AT2 > 0.5 + mGap Then
                  mAns = mAns + 2
               ElseIf T2 > 0.5 + mGap And AT2 <= 0.5 + mGap Then
                  mAns = mAns + 3
               Else
                  mAns = mAns + 4
               End If
               
   End Select
err1:
' MsgBox ("IntS_Point Error!")
End Sub

Public Sub CalIntTconst(IX, IY, mCx, mCy, mR, Sta_A, End_A, pie, Int_A, Cnt_T)
'IX    :    [in] the x coordinate of pick point on arc
'IY    :    [in] the y coordinate of pick point on arc
'mCx   :    [in] the x coordinate of arc center
'mCy   :    [in] the y coordinate of arc center
'mR    :    [in] radius of arc
'Sta_A :    [in] the start angle of arc
'End_A :    [in] the end angle of arc
'pie   :    [in] pie constant
'Int_A :    [out] the angle of intersection point
'Cnt_T :    [out] the t constant of intersection point
'On Error GoTo err1:
Dim mV1, mV2, mQ1, mE1, mGap As Double

mGap = 1 / 1000000

   mV1 = (IX - mCx) / mR  'cos
   mV2 = (IY - mCy) / mR  'sin
               
   If mV1 <> 0 And mV2 <> 0 Then
      Int_A = (1 - Abs(mV1) / mV1) * (1 + Abs(mV2 * mV1) / (mV2 * mV1)) * pie / 4 + Atn(mV2 / mV1) + _
            pie * (1 - Abs(mV1 * mV2) / (mV1 * mV2)) * (1 + (1 - Abs(mV2) / mV2) / 2) / 2
   ElseIf mV1 = 0 And mV2 <> 0 Then
      Int_A = pie / 2 + (1 - (Abs(mV2)) / mV2) * pie / 2
   ElseIf mV2 = 0 And mV1 <> 0 Then
      If mV1 < 0 Then
         Int_A = pie
      ElseIf mV1 > 0 And Sta_A = 0 Then
         Int_A = 0
      Else
         Int_A = 2 * pie
      End If
   End If
               
   If Abs(Int_A - Sta_A) < mGap Then
     Int_A = Sta_A
   ElseIf Abs(Int_A - End_A) < mGap Then
     Int_A = End_A
   ElseIf Abs(2 * pie - Int_A + Sta_A) < mGap Then
     Int_A = Sta_A
   ElseIf Abs(2 * pie + Int_A - End_A) < mGap Then
     Int_A = End_A
   End If
   mQ1 = Int_A
   mE11 = End_A
   If Sta_A >= End_A Then
      'If Int_A >= End_A Then
      If Int_A < (Sta_A + End_A) / 2 Then
         mQ1 = Int_A + 2 * pie
      End If
       mE11 = End_A + 2 * pie
   Else
      If Int_A > (Sta_A + End_A) / 2 + PI Then
         mQ1 = 2 * pie - Int_A
      End If
   End If
               
   Cnt_T = (mQ1 - Sta_A) / (mE11 - Sta_A)
err1:
 'MsgBox ("CalIntTconst Error!")
End Sub

