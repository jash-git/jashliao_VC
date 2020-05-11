Attribute VB_Name = "mdlGlyphOutline"
' ***************************************************************************************
'     NAME: Modul GlyphOutline
'     DESC: Modul zum Handling der GlyphOutline-API der Windows gdi32.dll
'     DESC: zum ermittlen der Zeichenumrandungen von TrueType Zeichens酹zen
' ***************************************************************************************
'
'     AUTHOR:  Stefan Maag
'     CREATE:  12/01/2003
'     CHANGE:
'     COPY:    Der Code geht auf eine Ausschreibung bei Activevb und ein
'     COPY:    Beispiel von Klaus Langbein zur�ck. Die Idee dazu hatte Robert Christ
'     COPY:    Dieser Code ist frei verf�gbar. Die Verwendung des Codes
'     COPY:    oder Codeteilen erfolgt immer auf eigenes Risiko und Verantwortung

' ===========================================================================
'  REM: Quellenangaben:
' ===========================================================================
'  REM:
'  REM:  1: www.activevb.de Beispielcode zu GlyphOutline von Klaus Langbein
'  REM:  2: MSDN Library Juli 2001, Microsoft
'  REM:  3: Das Beispiel in C zu GetGlyphOutline aus der MSDN von Ron Gery
'  REM:     Microsoft Developer Network Technology Group reated: July 10, 1992
'  REM:
' ===========================================================================
'  REM: Weitere ben飆igte Dateien:
' ===========================================================================
'
'  REM: keine

'Option Explicit
Public Declare Function timeGetTime Lib "winmm.dll" () As Long
Public Enum TT_GlyphFormat
' DESC: Konstanten f�r den fuFormat-Paramter der GlyphOutline-Funktion
   GGO_BITMAP = 1&     ' DESC: liefert den Zeichenumriss als Bitmap
   GGO_METRICS = 0&    ' DESC: liefert nur die GlyphMetrics Struktur zur�ck Buffer wird ignoriertEnd Enum
   GGO_NATIVE = 2&     ' DESC: liefert den Zeichenumriss als Array von Eckpunkten, Polygon
End Enum

 
Public Enum TT_CurveType
' DESC: Typ der Punkte im Buffer
   TT_PRIM_LINE = 1&
   TT_PRIM_QSPLINE = 2&
   TT_POLYGON_TYPE = 24&
End Enum

'Public Const GGO_BITMAP = 1      ' DESC: liefert den Zeichenumriss als Bitmap
'Public Const GGO_METRICS = 0     ' DESC: liefert nur die GlyphMetrics Struktur zur�ck Buffer wird ignoriert
'Public Const GGO_NATIVE = 2      ' DESC: liefert den Zeichenumriss als Array von Eckpunkten, Polygon

'Public Const TT_POLYGON_TYPE = 24
'Public Const TT_PRIM_LINE = 1
'Public Const TT_PRIM_QSPLINE = 2

'  Bei dem Fixed Datentyp handelt es sich um eine 32 Bit Festkommawert
'  mit 16 Bit Ganzzahlanteil und 16 Bit Nachkommanateil. Dies ist
'  jedoch etwas umst鄚dlich zu handhaben. Leichter zu verstehen ist
'  es, wenn man diesen Wert als normalen Long betrachtet, der um eine
'  bessere Aufl飉ung der Koordinaten zu bekommen, einfach mit einem
'  Faktor multipliziert ist.
'  Hier ist dieser Faktor 65536, also um 16 Bits nach links geschoben.
'
'  Wir werden diesen Datentyp hier nicht verwenden, sondern die Werte
'  immer als Long betrachten und gegebenfalls durch 65536 teilen und
'  das Ergebnis in einen Gleitpunkt Datentyp (Single/Double) speichern.
'  Dies spart uns viel 礪ger!

Type FIXED
    Fract As Integer   ' Nachkommanteil
    Value As Integer   ' Ganzzahlanteil
End Type

Type POINTFX
' DESC: Punkt in der Festkommadefinition der GlyphOutline Funktion
    X As FIXED
    Y As FIXED
End Type

Type POINTAPI
' DESC: Punkt im Format des Windows API, diesen verwenden wir auch als Ersatz f�r POINTFX
    X As Double
    Y As Double
End Type
Type MyPointData
     check As Boolean '線段或圓弧
     startpoint As POINTAPI '起始點
     betweenpoint As POINTAPI '中間點
     endpoint As POINTAPI '終點
End Type
Type PointShort
' DESC: Punkt in der Definition mit 16 Bit Integer-Koordinaten
    X As Integer
    Y As Integer
End Type

Type PointSingle
' DESC:  Punkt in der Definition mit (32 Bit) Single-Koordinaten
    X As Single
    Y As Single
End Type

Type GLYPHMETRICS
    gmBlackBoxX As Long    ' Breite der Bitmaps bei fuFormat = CGO_BITMAP
    gmBlackBoxY As Long    ' H鐬e der Bitmaps bei fuFormat = CGO_BITMAP
    gmptGlyphOrigin As POINTAPI
    gmCellIncX As Integer
    gmCellIncY As Integer
End Type


Type mAt2   ' DESC: die f�r VB-Programme leichter zu handhabende MAT2 Struktur mit Long
    eM11 As Long
    eM12 As Long
    eM21 As Long
    eM22 As Long
End Type

'Type MAT2          ' DESC: Originaldefintion der MAT2 Struktur mit FIXED Datentyp
'    eM11 As FIXED
'    eM12 As FIXED
'    eM21 As FIXED
'    eM22 As FIXED
'End Type

' DESC: MAT2 ist die Definition f�r die Transformationsmatrix.
' DESC: Diese Matrix gibt die Gr飉senverh鄟tnisse und die Ausrichtung,
' DESC: Drehung des erzeugten Zeichenumrisses an.
' DESC:
' DESC: Wir verwenden hier aber nicht die Originaldefinition mit den
' DESC: Werten als FIXED Datentyp sondern wir verwenden wegen besseren
' DESC: Handlings einen einfachen Long. Als Ausgangswert zur Berechung
' DESC: der em-Werte verwenden wir wieder einen Gleitkommawert und
' DESC: multiplizieren diesen mit 65536, speichern diesen in einem Long
' DESC: und erhalten so unseren Festkommawert

' DESC: Die Matrix hat folgendes Aussehen

' DESC: em11 em12
' DESC: em21 em22

Type TTPOLYGONHEADER
    cb As Long             ' Summe der Bytes f�r Header und Curves
    dwType As Long         ' immer TT_POLYGON_TYPE.
    ' pfxStart As POINTFX   ' erster Punkt als POINTFX Struktur: nicht verwenden
    pfxStart As POINTAPI      ' erster Punkt, Punktkoordinaten sind Long
End Type

Type TTPOLYCURVE
    wType As Integer    ' Typ: Polygon oder Bezier
    cpfx As Integer     ' Anzahl der folgenden Punkte incl. dem Startpunkt
    ' apfx As POINTFX    ' Startpunkt der Kurve als POINTFX Struktur: nicht verwenden
    apfx As POINTAPI       ' Startpunkt der Kurve, Punktkoordinaten sind Long
End Type

Public Declare Function GetGlyphOutline Lib "GDI32" Alias "GetGlyphOutlineA" _
                  (ByVal hDC As Long, ByVal uChar As Long, _
                   ByVal fuFormat As Long, lpgm As GLYPHMETRICS, _
                   ByVal cbBuffer As Long, lpBuffer As Any, lpmat2 As mAt2) As Long

' Die GlyphOutline Funktion ermittelt die Zeichenumrisse (Outline)

'DWORD GetGlyphOutline(
'  HDC hdc,             // handle to DC
'  UINT uChar,          // character to query
'  UINT uFormat,        // data format
'  LPGLYPHMETRICS lpgm, // glyph metrics
'  DWORD cbBuffer,      // size of data buffer
'  LPVOID lpvBuffer,    // data buffer
'  CONST MAT2 *lpmat2   // transformation matrix
');

Public Const FixedFaktor = 65536    ' DESC: Faktor zur Berechnung des FIXED Datenformates (:= Shift_16)

Private Declare Sub MoveMemory Lib "kernel32" Alias "RtlMoveMemory" _
                    (hpvDest As Any, hpvSource As Any, ByVal Bytes As Long)

Private Declare Sub MoveMemoryVal Lib "kernel32" Alias "RtlMoveMemory" _
                    (hpvDest As Any, ByVal hpvSource As Long, ByVal Bytes As Long)

Private Declare Sub PeekPoint Lib "msvbvm60.dll" Alias "GetMem8" (ptr As Any, RetVal As POINTAPI)
Public DrawData() As MyPointData

Public Function GetIdentityMatrix() As mAt2
' ===========================================================================
'  NAME:    GetIdentityMatrix
'  DESC:    Erzeugt die IdentityMatrix, diese ist im Prinzip eine 1 und
'  DESC:    ver鄚dert das Zeichen weder in Gr廲e noch Richtung
'  DESC:    man bekommt einen unmaipulierten Glyph
'  RETURN:  IdentityMatrix As MAT2
' ===========================================================================
   With GetIdentityMatrix
      .eM11 = 1 * FixedFaktor
      .eM12 = 0
      .eM21 = 0
      .eM22 = 1 * FixedFaktor
   End With
End Function

Public Function GetShearMatrix() As mAt2
' ===========================================================================
'  NAME:    GetShearMatrix
'  DESC:    Erzeugt die horizontale ShearMatrix, Italic Font Simualtion
'  RETURN:  ShearMatrix As MAT2
' ===========================================================================
   With GetShearMatrix
      .eM11 = 1 * FixedFaktor
      .eM12 = 0
      .eM21 = 0.25 * FixedFaktor
      .eM22 = 1 * FixedFaktor
   End With
End Function

Public Function GetRotationMatrix(Angle As Double) As mAt2
' ===========================================================================
'  NAME:    GetRotationMatrix
'  DESC:    Erzeugt eine Rotationsmatrix basierend auf dem Winkel in Grad
'  RETURN:  Rotationsmatrix As MAT2
' ===========================================================================
   Const PI = 3.14159265358979
   Dim angl As Double
   
   angl = Angle * PI / 180
   With GetRotationMatrix
      .eM11 = (Cos(angl)) * CDbl(FixedFaktor)
      .eM12 = Sin(angl) * CDbl(FixedFaktor)
      .eM21 = -.eM12
      .eM22 = .eM11
   End With
End Function

Public Function GetStrechMatrix(ByVal StrechX As Single, ByVal StrechY As Single) As mAt2
' ===========================================================================
'  NAME:    GetStrechMatrix
'  DESC:    Erzeugt eine Strechmatrix basierend auf den Steckfaktoren f�r x/y
'  DESC:    ver鄚dert das Zeichen in der Gr廲e
'  RETURN:  StrechMatrix As MAT2
' ===========================================================================
   With GetStrechMatrix
      .eM11 = StrechX * FixedFaktor
      .eM12 = 0
      .eM21 = 0
      .eM22 = StrechY * FixedFaktor
   End With
End Function

Public Function GetOutline(buffer() As Long, ByVal hDC As Long, ByVal CharASCII As Long, ByVal fuFormat As TT_GlyphFormat, _
                           metr As GLYPHMETRICS, Matrix As mAt2) As Long
' ===========================================================================
'  NAME:    GetOutline
'  DESC:    speichert die Punkte der Outline-Kurve in Buffer
'  RETURN:  Anzahl der Bytes in Buffer (nicht der Eintr輍e)
' ===========================================================================
   
   Dim ret As Long
   Dim ByteSize As Long       ' Anzahl der ben飆igten Bytes im Buffer
   Dim BufSize As Long        ' Eintr輍e im Buffer ( := Ubound(Buffer()) )
   Dim ptr As Long            ' Pointerwert
   
   ' Beim ersten Aufruf (ByteSize=0) wird die ben飆igte L鄚ge des Buffers in
   ' Bytes zur�ckgegen. Oder falls Funktion fehlschl輍t der Fehlercode (<0)
   ret = GetGlyphOutline(hDC, CharASCII, fuFormat, metr, ByteSize, ByVal ptr, Matrix)
   
   If ret > 0 Then
        ByteSize = ret
        BufSize = (ret / 4) - 1  ' /4, da es sich um einen LongBuffer und nicht um Bytes handelt
        ' -1, da von 0 ab dimensioniert wird und BufSize die Anzahl der Eintr輍e darstellt
   Else
        GetOutline = ret       ' Fehlercode zur�ckgeben
        Exit Function
   End If

   ReDim buffer(BufSize) As Long    ' Buffer in der Ben飆igten Gr廲e anlegen
   
   
   ptr = VarPtr(buffer(0))          ' Startadresse von Buffer()
   
   ' Nun beim 2ten Aufruf wird wirklich der Umriss generiert und in Buffer() gespeichert
   ret = GetGlyphOutline(hDC, CharASCII, fuFormat, metr, ByteSize, ByVal ptr, Matrix)
   
   GetOutline = ret       ' Returncode zur�ckgeben
   
   If ret <= 0 Then
      MsgBox "GetGlyphOutline: Error!"
      Exit Function
   End If
   
End Function

Public Sub DrawGlyph(Sort() As MyBlock, buffer() As Long, pb As PictureBox, ByVal Xoff As Long, ByVal Yoff As Long, IfSave As Boolean)
' ===========================================================================
'  NAME:    DrawGlyph
'  DESC:    zeichnet den Umriss in die angegeben Picturebox
' ===========================================================================
   
   Dim i As Long
   Dim j As Long
   Dim idx As Long
   Dim UB As Long
   Dim EndPoly As Long
   Dim PtsCnt As Long
   Dim ptStart As POINTAPI
   Dim X As Single
   Dim Y As Single
   Dim typ As Long
   
   Dim xs() As Double ' Long
   Dim ys() As Double 'Long
   Dim Xp(2) As Double 'Long
   Dim Yp(2) As Double 'Long
   Dim pt() As POINTAPI
   Dim DrawIndex As Long, O_DrawIndex As Long
   
   Dim X0 As Double, Y0 As Double, rad As Double
   Dim Xa As Double, Ya As Double, Xb As Double, Yb As Double, xc As Double, yc As Double
   
   UB = UBound(buffer())
   ReDim DrawData(UB)
   
   Dim B_NO() As Integer
   ReDim B_NO(0)
   DrawIndex = 0
   X0 = 0
   Y0 = 0
   rad = 0
   ' Alle Polygonheader mit untergeordneten PolyCurves durchlaufen
   Do
      ' --------------------------------------------------------------
      '  Daten der TTPOLGONHEADER - Struktur ausarbeiten
      ' --------------------------------------------------------------
      
      ' Berechnung des letzten Eintrags des Polygonzugs
      ' EndPoly = L鄚ge_Polygon_in_Bytes /4 + aktueller_BufferIndex
      EndPoly = buffer(idx) \ 4 + idx
      
      If buffer(idx + 1) <> TT_POLYGON_TYPE Then
         MsgBox "Fehler Polygon zeichnen: Kurve ist kein Polygonzug"
         Exit Sub
      End If
      
      ' Startpunkt des Polygonzuges
      ptStart.X = buffer(idx + 2)
      ptStart.Y = buffer(idx + 3)
      
      X = ptStart.X / FixedFaktor + Xoff
      Y = Yoff - ptStart.Y / FixedFaktor
      
      pb.PSet (X, Y), 0
      idx = idx + 4
      ReDim Preserve B_NO(UBound(B_NO) + 1)
      B_NO(UBound(B_NO)) = DrawIndex
      
      
      Do
      ' --------------------------------------------------------------
      ' Es beginnen die TTPOLYCURVE-Strukturen
      ' --------------------------------------------------------------
         
         ' Alle Kurven des Polygons durchlaufen
         PtsCnt = buffer(idx) \ 65536   ' HiWord = Anzahl der folgenden Punkte
         typ = buffer(idx) And 65535
         
         idx = idx + 1              ' idx auf X-Koordinate des Ersten der PtsCnt-Punkte
         
         Select Case typ

         Case TT_PRIM_LINE
            
            For i = 1 To PtsCnt
               X = buffer(idx) / FixedFaktor + Xoff
               Y = Yoff - buffer(idx + 1) / FixedFaktor
               ''''''''''''''''''''''pb.Line -(x, y)
               DrawData(DrawIndex).check = False
               DrawData(DrawIndex).startpoint.X = pb.CurrentX
               DrawData(DrawIndex).startpoint.Y = pb.CurrentY
               DrawData(DrawIndex).endpoint.X = X
               DrawData(DrawIndex).endpoint.Y = Y
               DrawIndex = DrawIndex + 1
               pb.CurrentX = X
               pb.CurrentY = Y
               idx = idx + 2
               ' MsgBox idx
            Next
         
         Case TT_PRIM_QSPLINE
'            For I = 1 To PtsCnt
'               x = Buffer(idx) / FixedFaktor + xoff
'               y = yoff - Buffer(idx + 1) / FixedFaktor
'               pb.Line -(x, y)
'               idx = idx + 2
'               ' MsgBox idx
'            Next
            
            ReDim xs(1 To PtsCnt)
            ReDim ys(1 To PtsCnt)

            For i = 1 To PtsCnt
               xs(i) = Xoff + buffer(idx) / FixedFaktor
               ys(i) = Yoff - buffer(idx + 1) / FixedFaktor
               idx = idx + 2
            Next i

            For i = 1 To PtsCnt - 1

               Xp(0) = pb.CurrentX
               Yp(0) = pb.CurrentY

               Xp(1) = xs(i)
               Yp(1) = ys(i)

               Select Case PtsCnt - i
               Case 0

               Case 1
                  Xp(2) = xs(i + 1)
                  Yp(2) = ys(i + 1)
               Case Else
                  Xp(2) = Xp(1) + (xs(i + 1) - Xp(1)) / 2
                  Yp(2) = Yp(1) + (ys(i + 1) - Yp(1)) / 2
               End Select


               pb.CurrentX = Xp(0)
               pb.CurrentY = Yp(0)


               Call Qspline(2, Xp(), Yp(), pt())

               'For j = 0 To UBound(pt)
                   '''''''''''''''''''''''''pb.Line -(pt(j).x, pt(j).y)
                    DrawData(DrawIndex).check = True
                    DrawData(DrawIndex).startpoint.X = pb.CurrentX
                    DrawData(DrawIndex).startpoint.Y = pb.CurrentY
                    DrawData(DrawIndex).betweenpoint.X = pt(1).X
                    DrawData(DrawIndex).betweenpoint.Y = pt(1).Y
                    DrawData(DrawIndex).endpoint.X = pt(2).X
                    DrawData(DrawIndex).endpoint.Y = pt(2).Y
                    DrawIndex = DrawIndex + 1
                    pb.CurrentX = pt(2).X
                    pb.CurrentY = pt(2).Y
               'Next j

            Next i
         
         End Select
      ' --------------------------------------------------------------
      ' Alle TTPOLYCURVE-Strukturen diese Polygonzuges abgeschlossen?
      ' --------------------------------------------------------------
      Loop Until idx >= (EndPoly)
        
        
      ' nun noch die Kurve zum Ausgangspunkt schliessen
      ''''''''''''''''''''''''''pb.Line -(ptStart.x / FixedFaktor + xoff, yoff - ptStart.y / FixedFaktor)
        DrawData(DrawIndex).check = False
        DrawData(DrawIndex).startpoint.X = pb.CurrentX
        DrawData(DrawIndex).startpoint.Y = pb.CurrentY
        DrawData(DrawIndex).endpoint.X = ptStart.X / FixedFaktor + Xoff
        DrawData(DrawIndex).endpoint.Y = Yoff - ptStart.Y / FixedFaktor
        DrawIndex = DrawIndex + 1
        pb.CurrentX = ptStart.X / FixedFaktor + Xoff
        pb.CurrentY = Yoff - ptStart.Y / FixedFaktor
   ' --------------------------------------------------------------
   ' Alle TTPOLYGONHEADER-Strukturen des Glyph abgearbeitet?
   ' --------------------------------------------------------------
   Loop Until idx >= UB ' Ende des Buffers erreicht?
   Dim C_CCW As Integer
   
   If IfSave = False Then
      O_DrawIndex = DrawIndex - 1
      DrawIndex = 0
      For DrawIndex = 0 To O_DrawIndex '(UB * 30)
          If DrawData(DrawIndex).check = False Then
             pb.Line (DrawData(DrawIndex).startpoint.X, -DrawData(DrawIndex).startpoint.Y)-(DrawData(DrawIndex).endpoint.X, -DrawData(DrawIndex).endpoint.Y)
          Else
             Xa = DrawData(DrawIndex).startpoint.X
             Ya = -DrawData(DrawIndex).startpoint.Y
             Xb = DrawData(DrawIndex).betweenpoint.X
             Yb = -DrawData(DrawIndex).betweenpoint.Y
             xc = DrawData(DrawIndex).endpoint.X
             yc = -DrawData(DrawIndex).endpoint.Y
             pb.Line (DrawData(DrawIndex).startpoint.X, -DrawData(DrawIndex).startpoint.Y)-(DrawData(DrawIndex).betweenpoint.X, -DrawData(DrawIndex).betweenpoint.Y)
             pb.Line (DrawData(DrawIndex).betweenpoint.X, -DrawData(DrawIndex).betweenpoint.Y)-(DrawData(DrawIndex).endpoint.X, -DrawData(DrawIndex).endpoint.Y)
             
             'If (Xa = Xb And Xb = xc) Or (Ya = Yb And Yb = yc) Then
             '    pb.Line (Xa, Ya)-(xc, yc)
             '    GoTo 100
             'End If
            ' Call arc_ppp(Xa, Ya, Xb, Yb, xc, yc, X0, Y0, rad, StartAngle, EndAngle, C_CCW)
            ' Call Com_3P_center(Xa, Ya, Xb, Yb, xc, yc, X0, Y0, rad)
            ' StartAngle = Slope(Xa, Ya, X0, Y0)
            ' SecondAngle = Slope(Xb, Yb, X0, Y0)
            ' EndAngle = Slope(xc, yc, X0, Y0)
            ' Call Draw.SwitchAngle
            ' pb.Circle (X0, Y0), rad, , StartAngle, EndAngle
            ' X0 = 0: Y0 = 0: rad = 0: StartAngle = 0: SecondAngle = 0: EndAngle = 0
          End If
100:
      Next DrawIndex
   Else
      SaveGlyph DrawData(), B_NO(), DrawIndex, pb, Xoff, Yoff, Sort()
   End If
End Sub
Public Sub SaveGlyph(DrawData() As MyPointData, B_NO() As Integer, O_DrawIndex As Long, pb As PictureBox, ByVal Xoff As Long, ByVal Yoff As Long, Sort() As MyBlock)
Dim DrawIndex As Long, DrawItem As Long
Dim X0 As Double, Y0 As Double, rad As Double
Dim Xa, Ya, Xb, Yb, xc, yc
Dim drawtype As Integer, EntityName As String
Dim StartAngle, EndAngle, SecondAngle
Dim sta_X As Double, sta_Y As Double, end_X As Double, end_Y As Double
Dim Top  As Double, Bottom As Double, Left As Double, Right As Double
Dim EntityTop, EntityBottom, EntityLeft, EntityRight
Dim n10 As Double, n11 As Double, n12 As Double, n13 As Double, n14 As Double, n49 As Integer
Dim PI As Double, Gap As Double, c_plane As Integer
Dim Block_no, group_no, Cam_no, Dim_no, Const_no
Dim StartNo, EndNo, i As Long
Dim last_x As Double, last_y As Double, C_CCW As Integer
PI = 4 * Atn(1)
Gap = 10 ^ -6

'Call File.what_plane(c_plane)
'Call DataTree.Find_Max_Para(Block_no, group_no, Cam_no, Dim_no, Const_no)




For i = 1 To UBound(B_NO)
    DrawItem = 0: X0 = 0: Y0 = 0: rad = 0: Block_no = Block_no + 1
    StartNo = B_NO(i)
    If i < UBound(B_NO) Then
       EndNo = B_NO(i + 1) - 1
    ElseIf i = UBound(B_NO) Then
           EndNo = O_DrawIndex - 1
    End If
    
    ReDim Preserve Sort(UBound(Sort) + 1)
    ReDim Preserve Sort(UBound(Sort)).Child(0)
    For DrawIndex = StartNo To EndNo 'O_DrawIndex
    If DrawData(DrawIndex).check = False Then
       drawtype = 1: EntityName = "LINE": n49 = 0: DrawItem = DrawItem + 1
       If DrawItem > 1 Then
          n10 = last_x
          n12 = last_y
       Else
          n10 = DrawData(DrawIndex).startpoint.X
          n12 = -DrawData(DrawIndex).startpoint.Y
       End If
       If DrawIndex = EndNo Then
          n11 = DrawData(StartNo).startpoint.X
          n13 = -DrawData(StartNo).startpoint.Y
       Else
          n11 = DrawData(DrawIndex).endpoint.X
          n13 = -DrawData(DrawIndex).endpoint.Y
       End If
       n14 = 0
       sta_X = n10: sta_Y = n12: end_X = n11: end_Y = n13
       Call CheckEntity(1, n10, n12, n11, n13, 0, 0, _
                        EntityTop, EntityBottom, EntityLeft, EntityRight)
       GoSub SaveEntity
      
    Else
       drawtype = 2: EntityName = "ARC": n49 = 1: DrawItem = DrawItem + 1
       If DrawItem > 1 Then
          Xa = last_x
          Ya = last_y
       Else
          Xa = DrawData(DrawIndex).startpoint.X
          Ya = -DrawData(DrawIndex).startpoint.Y
       End If
       If DrawIndex = EndNo Then
          xc = DrawData(StartNo).startpoint.X
          yc = -DrawData(StartNo).startpoint.Y
       Else
          xc = DrawData(DrawIndex).endpoint.X
          yc = -DrawData(DrawIndex).endpoint.Y
       End If
       
        Xb = DrawData(DrawIndex).betweenpoint.X
        Yb = -DrawData(DrawIndex).betweenpoint.Y
        If (Xa = Xb And Xb = xc) Or (Ya = Yb And Yb = yc) Then
            drawtype = 1: EntityName = "LINE": n49 = 0
            n10 = Xa
            n11 = xc
            n12 = Ya
            n13 = yc
            sta_X = n10: sta_Y = n12: end_X = n11: end_Y = n13
            Call CheckEntity(1, n10, n12, n11, n13, 0, 0, _
                        EntityTop, EntityBottom, EntityLeft, EntityRight)
       
            GoSub SaveEntity
            GoTo 100
        End If
        Call arc_ppp(Xa, Ya, Xb, Yb, xc, yc, X0, Y0, rad, StartAngle, EndAngle, C_CCW)
      '  Call Com_3P_center(Xa, Ya, Xb, Yb, xc, yc, X0, Y0, rad)
      '  StartAngle = Slope(Xa, Ya, X0, Y0)
      '  SecondAngle = Slope(Xb, Yb, X0, Y0)
      '  EndAngle = Slope(xc, yc, X0, Y0)
      '  Call Draw.SwitchAngle
        n10 = X0
        n11 = rad
        n12 = Y0
        n13 = StartAngle
        n14 = EndAngle
        Call arc_limit(X0, Y0, rad, StartAngle, EndAngle, EntityTop, EntityBottom, EntityLeft, EntityRight)
        sta_X = n10 + n11 * Cos(n13)
        end_X = n10 + n11 * Cos(n14)
        sta_Y = n12 + n11 * Sin(n13)
        end_Y = n12 + n11 * Sin(n14)
        'Debug.Print C_CCW
        If Abs(sta_X - Xa) < Gap And Abs(sta_Y - Ya) < Gap And Abs(end_X - xc) < Gap And Abs(end_Y - yc) < Gap Then
           n49 = 1
        Else
           n49 = 0
        End If
        GoSub SaveEntity
        X0 = 0: Y0 = 0: rad = 0: StartAngle = 0: SecondAngle = 0: EndAngle = 0
       
    End If
    If DrawItem = 1 Then
       Top = EntityTop
       Bottom = EntityBottom
       Left = EntityLeft
       Right = EntityRight
    Else
       If Top < EntityTop Then Top = EntityTop
       If Bottom > EntityBottom Then Bottom = EntityBottom
       If Left > EntityLeft Then Left = EntityLeft
       If Right < EntityRight Then Right = EntityRight
    End If
    last_x = end_X
    last_y = end_Y
100
   Next DrawIndex
   
   With Sort(UBound(Sort))
              .C5 = layer
              .C6 = ecolor
              .C7 = Block_no
              .C9 = 0
              .C15 = True
              .C16 = True
              .C21 = Top
              .C22 = Bottom
              .C23 = Left
              .C24 = Right
              .C43 = c_plane
              .C52 = 0
              .C53 = 0
              .C58 = 0
              .C60 = 0
              .IsClose = False
              .IsGroup = False
              .BCatageory = 1
   End With
   
Next i

Exit Sub
   
         
SaveEntity:
         ReDim Preserve Sort(UBound(Sort)).Child(UBound(Sort(UBound(Sort)).Child) + 1)
         If n49 = 1 And (drawtype = 2 Or drawtype = 3) Then
            If Abs(n14 - 2 * PI) < Gap Then n14 = 0
            sta_X = n10 + n11 * Cos(n13) 'res![25] + dx
            end_X = n10 + n11 * Cos(n14) 'res![26] + dx
            sta_Y = n12 + n11 * Sin(n13) 'res![27] + dy
            end_Y = n12 + n11 * Sin(n14) 'res![28] + dy
         ElseIf n49 = 0 And (drawtype = 2 Or drawtype = 3) Then
            If Abs(n14 - 2 * PI) < Gap Then n14 = 0
            sta_X = n10 + n11 * Cos(n14) 'res![25] + dx
            end_X = n10 + n11 * Cos(n13) 'res![26] + dx
            sta_Y = n12 + n11 * Sin(n14) 'res![27] + dy
            end_Y = n12 + n11 * Sin(n13) 'res![28] + dy
         End If
         
         With Sort(UBound(Sort)).Child(UBound(Sort(UBound(Sort)).Child))
             .C3 = drawtype
             .C4 = EntityName
             .C5 = layer
             .C8 = UBound(Sort(UBound(Sort)).Child)
             .C10 = n10
             .C11 = n11
             .C12 = n12
             .C13 = n13
             .C14 = n14
             .C17 = EntityTop
             .C18 = EntityBottom
             .C19 = EntityLeft
             .C20 = EntityRight
             .C25 = sta_X
             .C26 = end_X
             .C27 = sta_Y
             .C28 = end_Y
             .C29 = 0
             .C30 = 0
             .C31 = 0 'n31
             .C32 = 0
             .C33 = 0
             .C39 = 0
             .C40 = 0
             .C47 = 0
             .C48 = 0
             .C49 = n49
             .C50 = 0
             .C51 = 0
             .C54 = 0
             .C55 = 0
             .C56 = 0
             .C57 = False
             .CCAM.C21 = 0
             .CCAM.C22 = 0
             .CCAM.C23 = 0
             .CCAM.C24 = 0
             .CCAM.C34 = 0
             .CCAM.C35 = 0
             .CCAM.C36 = 0
             .CCAM.C37 = 0
             .CCAM.C38 = 0
             .CCAM.C41 = 0
             .CCAM.C42 = 0
             .CCAM.C44 = 0
             .CCAM.C45 = 0
             .CCAM.C46 = 0
             .CCAM.C59 = 0
             .CCAM.C61 = 0
        End With
Return

End Sub


Sub Qspline(ByVal n As Long, ByRef X() As Double, ByRef Y() As Double, ByRef ptOut() As POINTAPI)
    
    Dim i As Long
    Dim t As Double
    Dim tstep As Double
    ReDim ptOut(0 To n)
    
    tstep = 1 / (n)
    
    For i = 0 To n
    
        t = i * tstep
        ptOut(i).X = (X(0) - 2 * X(1) + X(2)) * t ^ 2 + (2 * X(1) - 2 * X(0)) * t ^ 1 + X(0)
        ptOut(i).Y = (Y(0) - 2 * Y(1) + Y(2)) * t ^ 2 + (2 * Y(1) - 2 * Y(0)) * t ^ 1 + Y(0)
         
    Next i

End Sub
Private Sub Com_3P_center(ByVal x1 As Double, ByVal y1 As Double, _
                             ByVal x2 As Double, ByVal y2 As Double, _
                             ByVal X3 As Double, ByVal Y3 As Double, _
                             cx, cy, rad)
Dim c As Double
Dim a1 As Double, a2 As Double

c = -2 * (x1 - x2) * (Y3 - y2) + 2 * (x2 - X3) * (y2 - y1)
a1 = (x1 - x2) * (y2 ^ 2 - Y3 ^ 2 - (X3 ^ 2 - x2 ^ 2))
a2 = (x2 - X3) * (y1 ^ 2 - y2 ^ 2 - (x2 ^ 2 - x1 ^ 2))
If c <> 0 Then
   cy = (a1 - a2) / c
ElseIf c = 0 Then
       rad = 0: Exit Sub
End If
c = 2 * (x2 - X3) * (y2 - y1) - 2 * (x1 - x2) * (Y3 - y2)
a1 = (y2 - y1) * (y2 ^ 2 - Y3 ^ 2 - (X3 ^ 2 - x2 ^ 2))
a2 = (Y3 - y2) * (y1 ^ 2 - y2 ^ 2 - (x2 ^ 2 - x1 ^ 2))
If c <> 0 Then
   cx = (a1 - a2) / c
ElseIf c = 0 Then
       rad = 0: Exit Sub
End If
rad = Sqr((cx - x1) ^ 2 + (cy - y1) ^ 2)
End Sub

Private Sub arc_ppp(x1, y1, x2, y2, X3, Y3, cx, cy, rad, ang_s, ang_e, C_CCW)
Dim the1, the2, the3
On Error Resume Next
   Call circle_3p(x1, y1, x2, y2, X3, Y3, cx, cy, rad)
   Call Get_Arc_Tan(x1, y1, cx, cy, the1)
   Call Get_Arc_Tan(x2, y2, cx, cy, the2)
   Call Get_Arc_Tan(X3, Y3, cx, cy, the3)
   Call find_Geo_ang(the1, the2, the3, ang_s, ang_e)
   If Abs(the1 - ang_s) < (1 / 100000) Then
      C_CCW = 1
    Else
      C_CCW = 0
   End If
End Sub
Private Sub circle_3p(x1, y1, x2, y2, X3, Y3, cx, cy, rad)
Dim c As Double, a1 As Double, a2 As Double, b1 As Double, b2 As Double
On Error Resume Next
   a1 = ((x1 ^ 2 - x2 ^ 2) + (y1 ^ 2 - y2 ^ 2)) * (X3 - x2)
   b1 = 2 * ((y1 - y2) * (X3 - x2) - (Y3 - y2) * (x1 - x2))
   c = ((X3 ^ 2 - x2 ^ 2) + (Y3 ^ 2 - y2 ^ 2)) * (x1 - x2)
   If b1 <> 0 Then
      cy = (a1 - c) / b1
      a2 = (x1 ^ 2 - x2 ^ 2) + (y1 ^ 2 - y2 ^ 2) - 2 * cy * (y1 - y2)
      b2 = 2 * (x1 - x2)
      If b2 <> 0 Then
         cx = a2 / b2
         rad = Sqr((cx - x1) ^ 2 + (cy - y1) ^ 2)
      Else
         rad = 0
      End If
   Else
      rad = 0
   End If
End Sub
Private Sub Get_Arc_Tan(x1, y1, X0, Y0, the)
Dim pie
On Error Resume Next
   pie = 4 * Atn(1)
   
   If Abs(x1 - X0) < (1 / 100000) Then
      the = pie / 2
   Else
      the = Atn(Abs((y1 - Y0) / (x1 - X0)))
   End If
   If Abs(the) < (1 / 100000) And x1 >= X0 Then  '0.001
      the = 0
   ElseIf y1 >= Y0 And x1 <= X0 Then
      the = pie - the
   ElseIf y1 <= Y0 And x1 <= X0 Then
      the = pie + the
   ElseIf y1 <= Y0 And x1 >= X0 Then
      the = 2 * pie - the
   End If
End Sub
Private Function find_Geo_ang(Ang1, Ang2, ang3, ang_s, ang_e)
On Error Resume Next
   'Call get_ang(x1, y1, c_x, c_y, ang1)
   'Call get_ang(x2, y2, c_x, c_y, ang2)
   'Call get_ang(x3, y3, c_x, c_y, ang3)
   If ang3 > Ang2 And Ang2 > Ang1 Then
      ang_s = Ang1: ang_e = ang3
   ElseIf Ang1 > Ang2 And Ang2 > ang3 Then
      ang_s = ang3: ang_e = Ang1
   ElseIf (Ang2 > Ang1 And Ang1 > ang3) Or (ang3 > Ang2 And Ang1 > ang3) Then
      ang_s = Ang1: ang_e = ang3
   ElseIf (Ang1 > Ang2 And ang3 > Ang1) Or (Ang2 > ang3 And ang3 > Ang1) Then
      ang_s = ang3: ang_e = Ang1
   End If
End Function
Private Function Slope(ByVal x1 As Double, ByVal y1 As Double, _
                      ByVal x2 As Double, ByVal y2 As Double) ' As Single
                      
Dim PI
PI = 4 * Atn(1)
' 1.計算角度。
           '-----------------------------------------
           '計算角度 Tan(Q) =  (y1 - y2) / (x1 - x2)
           '-----------------------------------------
            If x1 >= x2 Then
               If y1 = y2 Then
                  Slope = 0
               ElseIf y1 > y2 Then      '第一項限
                   If x1 = x2 Then
                      Slope = PI / 2
                   Else
                     Slope = Atn((y1 - y2) / (x1 - x2))
                   End If
               ElseIf y1 < y2 Then      '第四項限
                   If x1 = x2 Then
                      Slope = 3 * PI / 2
                   Else
                     Slope = 2 * PI - Atn((Abs(y1 - y2) / (x1 - x2)))
                   End If
               End If
            ElseIf x1 < x2 Then
               If y1 = y2 Then
                  Slope = PI
               ElseIf y1 > y2 Then       '第二項限
                  Slope = PI - Atn(((y1 - y2) / Abs(x1 - x2)))
               ElseIf y1 < y2 Then       '第三項限
                  Slope = PI + Atn((Abs(y1 - y2) / Abs(x1 - x2)))
               End If
            End If
End Function
Sub arc_limit(X0, Y0, r0, A0, B0, e_t, e_b, e_l, e_r)
Dim x1, y1, x2, y2
On Error Resume Next
pie = 4 * Atn(1)
            'a = 1
            'DoEvents
            x1 = X0 + r0 * Cos(A0)
            y1 = Y0 + r0 * Sin(A0)
            x2 = X0 + r0 * Cos(B0)
            y2 = Y0 + r0 * Sin(B0)
            If x1 > x2 Then
               e_r = x1: e_l = x2
            Else
               e_r = x2: e_l = x1
            End If
            If y1 > y2 Then
               e_t = y1: e_b = y2
            Else
               e_t = y2: e_b = y1
            End If
            If B0 < A0 And B0 = 0 Then B0 = 2 * pie
            a_1 = A0
            a_2 = B0
            If B0 > A0 Then
               If a_1 <= (pie / 2) And a_2 >= (pie / 2) Then e_t = Y0 + r0
               If a_1 <= (3 * pie / 2) And a_2 >= (3 * pie / 2) Then e_b = Y0 - r0
               If a_1 <= (pie) And a_2 >= (pie) Then e_l = X0 - r0
            Else
               If A0 > (3 * pie) / 2 Then
                  If B0 > 0 Then e_r = X0 + r0
                  If B0 > pie / 2 Then e_t = Y0 + r0 ': e_r = X0 + r0
                  If B0 > pie Then e_l = X0 - r0 ': e_t = Y0 + r0: e_r = X0 + r0
                  If B0 > (3 * pie) / 2 Then e_b = Y0 - r0 ': e_l = X0 - r0: e_t = Y0 + r0: e_r = X0 + r0
               ElseIf A0 > (pie) Then
                  If B0 > 0 Then e_r = X0 + r0: e_b = Y0 - r0
                  If B0 > pie / 2 Then e_t = Y0 + r0 ': e_b = Y0 - r0: e_r = X0 + r0
                  If B0 > pie Then e_l = X0 - r0 ': e_t = Y0 + r0: e_b = Y0 - r0: e_r = X0 + r0                 'If B0 > (3 * pie) / 2 Then e_b = y0 - r0
               ElseIf A0 > (pie / 2) Then
                  If B0 > 0 Then e_r = X0 + r0: e_b = Y0 - r0: e_l = X0 - r0
                  If B0 > pie / 2 Then e_t = Y0 + r0 ': e_r = X0 + r0
                  'If B0 > pie Then e_l = x0 - r0
                  'If B0 > (3 * pie) / 2 Then e_b = y0 - r0
               ElseIf A0 > 0 Then
                  If B0 > 0 Then e_r = X0 + r0: e_t = Y0 + r0: e_l = X0 - r0: e_b = Y0 - r0
                  'If B0 > pie / 2 Then e_t = y0 + r0
                  'If B0 > pie Then e_l = x0 - r0
                  'If B0 > (3 * pie) / 2 Then e_b = y0 - r0
               End If
               'If A0 > (3 * pie) / 2 Then
               '   a_1 = (A0 - 2 * pie) 'a_e = (b0 + 2 * pie)
               '   If a_1 <= (pie / 2) And a_2 >= (pie / 2) Then e_t = y0 + r0
               '   If a_1 <= (3 * pie / 2) And a_2 >= (3 * pie / 2) Then e_b = y0 - r0
               '   If a_1 <= (pie) And a_2 >= (pie) Then e_l = x0 - r0
               '   If a_1 <= 0 And a_2 >= 0 Then e_r = x0 + r0
               'Else
               '   a_2 = (B0 + 2 * pie) 'a_e = (b0 + 2 * pie)
               '   If a_1 <= (pie / 2) And a_2 >= (pie / 2) Then e_t = y0 + r0
               '   If a_1 <= (3 * pie / 2) And a_2 >= (3 * pie / 2) Then e_b = y0 - r0
               '   If a_1 <= (pie) And a_2 >= (pie) Then e_l = x0 - r0
               '   If a_1 <= (2 * pie) And a_2 >= (2 * pie) Then e_r = x0 + r0
               'End If
            End If
            
            'If a0 > b0 Then a_e = (b0 + 2 * pie)
            'If a_s <= (pie / 2) And a_e >= (pie / 2) Then e_t = y0 + r0
            'If a_s <= (3 * pie / 2) And a_e >= (3 * pie / 2) Then e_b = y0 - r0
            'If a_s <= (pie) And a_e >= (pie) Then e_l = x0 - r0
            'If a0 > b0 Then a_s = (a0 - 2 * pie)
            'If a_s <= 0 And a_e >= 0 Then e_r = x0 + r0
            'n17 = e_t
            'n18 = e_b
            'n19 = e_l
            'n20 = e_r

End Sub
