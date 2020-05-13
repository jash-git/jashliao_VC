cscript.exe wmcmd.vbs -input s140113706.mp4 -output s140113706.wmv -loadprofile wmv_1m.prx
ffmpeg -i s140113706.wmv -y -f  image2  -ss 1 -vframes 1  s140113706.jpg