Attribute VB_Name = "Module1"
Private Type NETRESOURCE
dwScope As Long
dwType As Long
dwDisplayType As Long
dwUsage As Long
pLocalName As Long
pRemoteName As String 'Long
pComment As Long
pProvider As Long
End Type
Private Declare Function WNetAddConnection2 Lib "mpr.dll" Alias "WNetAddConnection2A" (lpNetResource As NETRESOURCE, ByVal lpPassword As String, ByVal lpUserName As String, ByVal dwFlags As Long) As Long
Public Sub ConnectServerShare(servername As String, username As String, PassWord As String) '對於一些必須連接一次伺服器才能連接的電腦採用先用程式連一次的方法
On Error Resume Next
Dim LL As NETRESOURCE
With LL
.pRemoteName = "\\" & servername
.dwType = 0
End With
WNetAddConnection2 LL, PassWord, username, 0
End Sub
