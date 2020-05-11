Attribute VB_Name = "Module1"
Declare Function ConnectFTP Lib "FTPUpLoad" (ByVal FTPServer As String, ByVal FTPuser As String, ByVal FTPpws As String, ByVal port As Integer) As Boolean
Declare Sub ClosetFTP Lib "FTPUpLoad" ()
Declare Function UpLoadFTP Lib "FTPUpLoad" (ByVal FileName As String) As Boolean

