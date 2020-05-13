wget.exe "ftp://jash:chwbnnoc@192.168.0.200/01NEWS/20140113/s1401137012.mp4" -O s1401137012.mp4
cscript.exe wmcmd.vbs -input s1401137012.mp4 -output s1401137012.wmv -loadprofile wmv_1m.prx
Del s1401137012.mp4
