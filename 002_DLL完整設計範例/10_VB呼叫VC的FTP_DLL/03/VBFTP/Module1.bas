Attribute VB_Name = "Module1"
Declare Function ConnectFTP Lib "FTPUpLoad" (ByVal FTPServer As String, ByVal FTPuser As String, ByVal FTPpws As String, ByVal port As Integer) As Boolean
Declare Sub ClosetFTP Lib "FTPUpLoad" ()
Declare Function UpLoadFTP Lib "FTPUpLoad" (ByVal LocalFile As String, ByVal RemoteFile As String) As Boolean
Declare Function DownLoadFTP Lib "FTPUpLoad" (ByVal RemoteFile As String, ByVal LocalFile As String) As Boolean
