Attribute VB_Name = "Module1"
Public Type point
x As Double
y As Double
End Type
Public Type EngarveElement
    Type As Long
    CCW As Long
    X1 As Double
    Y1 As Double
    Z1 As Double
    X2 As Double
    Y2 As Double
    Z2 As Double
End Type
Type EngarveBlock
          Direction As Long ' :¤è¦V     CW:0      CCW:1
          Child() As EngarveElement
End Type

Declare Sub GetValue1 Lib "testEngraving" (P As EngarveElement, ByVal c As Long)
Declare Function SendValue1 Lib "testEngraving" (P As EngarveElement) As Long
