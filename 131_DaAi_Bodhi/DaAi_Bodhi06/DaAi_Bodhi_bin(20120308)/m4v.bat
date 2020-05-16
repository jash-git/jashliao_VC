ffmpeg.exe -i Z:\Video_Source\puti_20120301.mov -deinterlace -target ntsc-dvd -ab 128k -aspect 4:3 -s 720x480 D:\DaAi_Bodhi_bin\puti_20120301.mpg

cscript.exe wmcmd.vbs -input D:\DaAi_Bodhi_bin\puti_20120301.mpg -output D:\DaAi_Bodhi_bin\puti_20120301_1000K.wmv -loadprofile 1000k.prx
cscript.exe wmcmd.vbs -input D:\DaAi_Bodhi_bin\puti_20120301.mpg -output D:\DaAi_Bodhi_bin\puti_20120301_500K.wmv -loadprofile 500k.prx