wget.exe "ftp://jash:chwbnnoc@192.168.0.200/01NEWS/20130610/s130610158.mp4"
cscript.exe wmcmd.vbs -input s130610158.mp4 -output s130610158.wmv -loadprofile wmv_1m.prx
del s130610158.mp4