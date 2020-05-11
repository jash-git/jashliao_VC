Attribute VB_Name = "Module1"
Declare Function KbdHookProc Lib "mfcdll" (ByVal a As Integer, ByVal c As Integer) As Integer
Declare Sub jashSetValue Lib "mfcdll" (ByVal a As Integer)
Declare Function jashGetValue Lib "mfcdll" () As Integer
