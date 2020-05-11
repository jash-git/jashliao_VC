Attribute VB_Name = "Module1"
Public Type point
x As Double
y As Double
End Type
Declare Sub GetValue1 Lib "PointData" (P As point, ByVal c As Long)
Declare Sub ChangeValue1 Lib "PointData" (P As point, P1 As point)
Declare Sub Get2DArray Lib "PointData" (data As Long, ByVal x As Long, ByVal y As Long)

