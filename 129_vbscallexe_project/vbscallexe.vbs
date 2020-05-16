'vbs call exe

Set WshShell = CreateObject("WScript.Shell") 
RetCode = WshShell.Run("ping www.hinet.net", 1, true) 
If RetCode >= 0 Then
WScript.Sleep(60000) 
WshShell.Run "D:\\NabroVpnApp.exe", 1, true 
End If