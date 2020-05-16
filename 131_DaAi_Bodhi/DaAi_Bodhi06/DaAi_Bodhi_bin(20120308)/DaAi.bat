echo 0 > BatState.txt
wget -c ftp://skylink:skylink2008@60.248.192.140/%%E4%%BA%%BA%%E9%%96%%93%%E8%%8F%%A9%%E6%%8F%%90/puti_20120307.mov
echo 1 > BatState.txt
ffmpeg.exe -i puti_20120307.mov -deinterlace -target ntsc-dvd -ab 128k -aspect 4:3 -s 720x480 puti_20120307.mpg
echo 2 > BatState.txt
cscript.exe wmcmd.vbs -input puti_20120307.mpg -output puti_20120307_1000K.wmv -loadprofile 1000k.prx
cscript.exe wmcmd.vbs -input puti_20120307.mpg -output puti_20120307_500K.wmv -loadprofile 500k.prx
echo 3 > BatState.txt
