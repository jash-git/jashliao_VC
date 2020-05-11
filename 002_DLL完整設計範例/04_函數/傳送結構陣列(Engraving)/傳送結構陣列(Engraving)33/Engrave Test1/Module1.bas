Attribute VB_Name = "Module1"
Declare Function EngInitial Lib "Engrave32" (ByVal lngBlockAmount As Long, ByVal tolerance As Double, ByVal Direction As Long) As Long
Declare Function EngGetValue Lib "Engrave32" (p As EngraveElement, ByVal lngBlock As Long, ByVal lngAmount As Long) As Long
Declare Function EngCalculate Lib "Engrave32" () As Long

