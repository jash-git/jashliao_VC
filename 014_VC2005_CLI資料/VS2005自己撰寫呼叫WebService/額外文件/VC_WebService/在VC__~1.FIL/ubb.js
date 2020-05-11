strIcons = "1"  //允许笑脸转换
strSmile="1"   //同上
ImgName="em"
picurl="/images/emot/"

function UBBCode(content,html){
    content=content.replace("\\r","");
    content=content.replace("\\n","");
    return (trans(content));
}


function trans(strContent){
    var re;

	re=/\[IMG\](.+?)\[\/IMG\]/ig;
	strContent=strContent.replace(re,"<a href=$1 target=_blank><div><IMG SRC=$1 border=0 alt=按此在新窗口浏览图片 onload=\"javascript:if(this.width>screen.width*0.7)this.width=screen.width*0.7;\" galleryImg=no></div></a> ");
	re=/\[DIR=*([0-9]*),*([0-9]*)\](.*?)\[\/DIR]/ig
	strContent=strContent.replace(re,"<object classid=clsid:166B1BCA-3F9C-11CF-8075-444553540000 codebase=http://download.macromedia.com/pub/shockwave/cabs/director/sw.cab#version=7,0,2,0 width=$1 height=$2><param name=src value=$3><embed src=$3 pluginspage=http://www.macromedia.com/shockwave/download/ width=$1 height=$2></embed></object>")
	re=/\[QT=*([0-9]*),*([0-9]*)\](.*?)\[\/QT]/ig
	strContent=strContent.replace(re,"<embed src=$3 width=$1 height=$2 autoplay=true loop=false controller=true playeveryframe=false cache=false scale=TOFIT bgcolor=#000000 kioskmode=false targetcache=false pluginspage=http://www.apple.com/quicktime/>")
	re=/\[MP=*([0-9]*),*([0-9]*)\](.*?)\[\/MP]/ig
	strContent=strContent.replace(re,"<object align=middle classid=CLSID:22d6f312-b0f6-11d0-94ab-0080c74c7e95 class=OBJECT id=MediaPlayer width=$1 height=$2 ><param name=ShowStatusBar value=-1><param name=Filename value=$3><embed type=application/x-oleobject codebase=http://activex.microsoft.com/activex/controls/mplayer/en/nsmp2inf.cab#Version=5,1,52,701 flename=mp src=$3  width=$1 height=$2></embed></object>")
	re=/\[RM=*([0-9]*),*([0-9]*)\](.*?)\[\/RM]/ig
	strContent=strContent.replace(re,"<OBJECT classid=clsid:CFCDAA03-8BE4-11cf-B84B-0020AFBBCCFA class=OBJECT id=RAOCX width=$1 height=$2><PARAM NAME=SRC VALUE=$3><PARAM NAME=CONSOLE VALUE=Clip1><PARAM NAME=CONTROLS VALUE=imagewindow><PARAM NAME=AUTOSTART VALUE=true></OBJECT><br><OBJECT classid=CLSID:CFCDAA03-8BE4-11CF-B84B-0020AFBBCCFA height=32 id=video2 width=$1><PARAM NAME=SRC VALUE=$3><PARAM NAME=AUTOSTART VALUE=-1><PARAM NAME=CONTROLS VALUE=controlpanel><PARAM NAME=CONSOLE VALUE=Clip1></OBJECT>")


	re=/(\[FLASH\])(.*?)(\[\/FLASH\])/ig
	strContent= strContent.replace(re,"<OBJECT codeBase=http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=6,0,29,0 classid=clsid:D27CDB6E-AE6D-11cf-96B8-444553540000 width=500 height=400><PARAM NAME=movie VALUE=$2><PARAM NAME=quality VALUE=high><embed src=$2 quality=high pluginspage='http://www.macromedia.com/go/getflashplayer' type='application/x-shockwave-flash' width=500 height=400>$2</embed></OBJECT>")
	re=/(\[FLASH=*([0-9]*),*([0-9]*)\])(.*?)(\[\/FLASH\])/ig
	strContent= strContent.replace(re,"<a href=$4 TARGET=_blank><IMG SRC="+picurl+"swf.gif border=0 alt=点击开新窗口欣赏该FLASH动画!> [全屏欣赏]</a><br><br><OBJECT codeBase=http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=6,0,29,0 classid=clsid:D27CDB6E-AE6D-11cf-96B8-444553540000 width=$2 height=$3><PARAM NAME=movie VALUE=$4><PARAM NAME=quality VALUE=high><param name=menu value=false><embed src=$4 quality=high menu=false pluginspage='http://www.macromedia.com/go/getflashplayer' type='application/x-shockwave-flash' width=$2 height=$3>$4</embed></OBJECT>")

	re=/(\[UPLOAD=gif\])(.*?)(\[\/UPLOAD\])/ig
	strContent= strContent.replace(re,"<br><IMG SRC="+picurl+"gif.gif border=0>此主题相关图片如下：<br><A HREF=$2 TARGET=_blank><IMG SRC=$2 border=0 alt=按此在新窗口浏览图片 onerror='if(this.src.indexOf(\"219.239\") == -1)this.src=\"http://219.239.88.21$2\"' onload=\"javascript:if(this.width>screen.width-333)this.width=screen.width-333\"></A>")
	re=/(\[UPLOAD=jpg\])(.*?)(\[\/UPLOAD\])/ig
	strContent= strContent.replace(re,"<br><IMG SRC="+picurl+"jpg.gif border=0>此主题相关图片如下：<br><A HREF=$2 TARGET=_blank><IMG SRC=$2 border=0 alt=按此在新窗口浏览图片 onerror='if(this.src.indexOf(\"219.239\") == -1)this.src=\"http://219.239.88.21$2\"' onload=\"javascript:if(this.width>screen.width-333)this.width=screen.width-333\"></A>")
	re=/(\[UPLOAD=png\])(.*?)(\[\/UPLOAD\])/ig
	strContent= strContent.replace(re,"<br><IMG SRC="+picurl+"png.gif border=0>此主题相关图片如下：<br><A HREF=$2 TARGET=_blank><IMG SRC=$2 border=0 alt=按此在新窗口浏览图片 onerror='if(this.src.indexOf(\"219.239\") == -1)this.src=\"http://219.239.88.21$2\"' onload=\"javascript:if(this.width>screen.width-333)this.width=screen.width-333\"></A>")

	re=/(\[UPLOAD=swf\])(.*?)(\[\/UPLOAD\])/ig
	strContent= strContent.replace(re,"<br><a href=$2 TARGET=_blank><IMG SRC="+picurl+"swf.gif border=0 alt=点击开新窗口欣赏该FLASH动画!> [全屏欣赏]</a><br><br><OBJECT codeBase=http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=6,0,29,0 classid=clsid:D27CDB6E-AE6D-11cf-96B8-444553540000 width=400 height=100><PARAM NAME=movie VALUE=$2><PARAM NAME=quality VALUE=high><param name=menu value=false><embed src=$2 quality=high menu=false pluginspage='http://www.macromedia.com/go/getflashplayer' type='application/x-shockwave-flash' width=400 height=100>$2</embed></OBJECT>")

	re=/(\[UPLOAD=asf\])(.*?)(\[\/UPLOAD\])/ig
	strContent= strContent.replace(re,"<br><object align=middle classid=CLSID:22d6f312-b0f6-11d0-94ab-0080c74c7e95 class=OBJECT id=MediaPlayer width=400 height=300 ><param name=ShowStatusBar value=-1><param name=Filename value=$2><embed type=application/x-oleobject codebase=http://activex.microsoft.com/activex/controls/mplayer/en/nsmp2inf.cab#Version=5,1,52,701 flename=mp src=$2  width=400 height=300></embed></object>")
	re=/(\[UPLOAD=avi\])(.*?)(\[\/UPLOAD\])/ig
	strContent= strContent.replace(re,"<br><object align=middle classid=CLSID:22d6f312-b0f6-11d0-94ab-0080c74c7e95 class=OBJECT id=MediaPlayer width=400 height=300 ><param name=ShowStatusBar value=-1><param name=Filename value=$2><embed type=application/x-oleobject codebase=http://activex.microsoft.com/activex/controls/mplayer/en/nsmp2inf.cab#Version=5,1,52,701 flename=mp src=$2  width=400 height=300></embed></object>")
	re=/(\[UPLOAD=mpg\])(.*?)(\[\/UPLOAD\])/ig
	strContent= strContent.replace(re,"<br><object align=middle classid=CLSID:22d6f312-b0f6-11d0-94ab-0080c74c7e95 class=OBJECT id=MediaPlayer width=400 height=300 ><param name=ShowStatusBar value=-1><param name=Filename value=$2><embed type=application/x-oleobject codebase=http://activex.microsoft.com/activex/controls/mplayer/en/nsmp2inf.cab#Version=5,1,52,701 flename=mp src=$2  width=400 height=300></embed></object>")
	re=/(\[UPLOAD=wmv\])(.*?)(\[\/UPLOAD\])/ig
	strContent= strContent.replace(re,"<br><object align=middle classid=CLSID:22d6f312-b0f6-11d0-94ab-0080c74c7e95 class=OBJECT id=MediaPlayer width=400 height=300 ><param name=ShowStatusBar value=-1><param name=Filename value=$2><embed type=application/x-oleobject codebase=http://activex.microsoft.com/activex/controls/mplayer/en/nsmp2inf.cab#Version=5,1,52,701 flename=mp src=$2  width=400 height=300></embed></object>")

	re=/(\[UPLOAD=mp3\])(.*?)(\[\/UPLOAD\])/ig
	strContent= strContent.replace(re,"<br><object align=middle classid=CLSID:22d6f312-b0f6-11d0-94ab-0080c74c7e95 class=OBJECT id=MediaPlayer width=400 height=68 ><param name=ShowStatusBar value=-1><param name=Filename value=$2><embed type=application/x-oleobject codebase=http://activex.microsoft.com/activex/controls/mplayer/en/nsmp2inf.cab#Version=5,1,52,701 flename=mp src=$2  width=400 height=68></embed></object>")
	re=/(\[UPLOAD=wav\])(.*?)(\[\/UPLOAD\])/ig
	strContent= strContent.replace(re,"<br><object align=middle classid=CLSID:22d6f312-b0f6-11d0-94ab-0080c74c7e95 class=OBJECT id=MediaPlayer width=400 height=68 ><param name=ShowStatusBar value=-1><param name=Filename value=$2><embed type=application/x-oleobject codebase=http://activex.microsoft.com/activex/controls/mplayer/en/nsmp2inf.cab#Version=5,1,52,701 flename=mp src=$2  width=400 height=68></embed></object>")
	re=/(\[UPLOAD=mid\])(.*?)(\[\/UPLOAD\])/ig
	strContent= strContent.replace(re,"<br><object align=middle classid=CLSID:22d6f312-b0f6-11d0-94ab-0080c74c7e95 class=OBJECT id=MediaPlayer width=400 height=68 ><param name=ShowStatusBar value=-1><param name=Filename value=$2><embed type=application/x-oleobject codebase=http://activex.microsoft.com/activex/controls/mplayer/en/nsmp2inf.cab#Version=5,1,52,701 flename=mp src=$2  width=400 height=68></embed></object>")

    re=/(\[UPLOAD=(.[^\[]*)\])(.*?)(\[\/UPLOAD\])/ig
    strContent= strContent.replace(re,"<br><IMG SRC="+picurl+"$2.gif border=0> <a href=$3 target=blank>点击浏览该文件</a>")

    re=/(\[refer=(\d{1,}),(.*?)\])(.*?)(\[\/refer\])/ig
    strContent=strContent.replace(re,"<table cellspacing=0 cellpadding=4 width=\"100%\" style=\"padding-top: 12px;\" border=0><tr><td background=\"/images/002.gif\" bgcolor=#F9F8FC  height=\"1\"></td></tr><tr><td style=\"padding-left: 16px\" bgcolor=#F9F8FC>回复$2楼<font color=\"#669900\">$3</font>发表：</td></tr><tr><td background=\"/images/002.gif\" bgcolor=#F9F8FC  height=\"1\"></td></tr><tr><td style=\"padding-left: 16px\" bgcolor=#F9F8FC> <font style=\"color:#A1A1A1\">$4</font> </td></tr><tr><td background=\"/images/002.gif\" bgcolor=#F9F8FC  height=\"1\"></td></tr></table>");

	re=/(\[URL\])(.*?)(\[\/URL\])/ig
	strContent= strContent.replace(re,"<A HREF=$2 TARGET=_blank>$2</A>")
	re=/(\[URL=(.[^\[]*)\])(.*?)(\[\/URL\])/ig
	strContent= strContent.replace(re,"<A HREF=$2 TARGET=_blank>$3</A>")

	re=/(\[EMAIL\])(.*?)(\[\/EMAIL\])/ig
	strContent= strContent.replace(re,"<img align=absmiddle src=/images/email.gif><A HREF=\"mailto:$2\">$2</A>")
	re=/(\[EMAIL=(.[^\[]*)\])(.*?)(\[\/EMAIL\])/ig
	strContent= strContent.replace(re,"<img align=absmiddle src=/images/email.gif><A HREF=\"mailto:$2\" TARGET=_blank>$3</A>")

	re =/^(http:\/\/[A-Za-z0-9\.\/=\?%\-&_~`@':+!]+)/ig
	strContent = strContent.replace(re,"<img align=absmiddle src=/images/url.gif><a target=_blank href=$1>$1</a>")
	re =/(http:\/\/[A-Za-z0-9\.\/=\?%\-&_~`@':+!]+)$/ig
	strContent = strContent.replace(re,"<img align=absmiddle src=/images/url.gif><a target=_blank href=$1>$1</a>")
	re =/[^>=""](http:\/\/[A-Za-z0-9\.\/=\?%\-&_~`@':+!]+)/ig
	strContent = strContent.replace(re,"<img align=absmiddle src=/images/url.gif><a target=_blank href=$1>$1</a>")
	re =/^(ftp:\/\/[A-Za-z0-9\.\/=\?%\-&_~`@':+!]+)/ig
	strContent = strContent.replace(re,"<img align=absmiddle src=/images/url.gif><a target=_blank href=$1>$1</a>")
	re =/(ftp:\/\/[A-Za-z0-9\.\/=\?%\-&_~`@':+!]+)$/ig
	strContent = strContent.replace(re,"<img align=absmiddle src=/images/url.gif><a target=_blank href=$1>$1</a>")
	re =/[^>=""](ftp:\/\/[A-Za-z0-9\.\/=\?%\-&_~`@':+!]+)/ig
	strContent = strContent.replace(re,"<img align=absmiddle src=/images/url.gif><a target=_blank href=$1>$1</a>")
	re =/^(rtsp:\/\/[A-Za-z0-9\.\/=\?%\-&_~`@':+!]+)/ig
	strContent = strContent.replace(re,"<img align=absmiddle src=/images/url.gif><a target=_blank href=$1>$1</a>")
	re =/(rtsp:\/\/[A-Za-z0-9\.\/=\?%\-&_~`@':+!]+)$/ig
	strContent = strContent.replace(re,"<img align=absmiddle src=/images/url.gif><a target=_blank href=$1>$1</a>")
	re =/[^>=""](rtsp:\/\/[A-Za-z0-9\.\/=\?%\-&_~`@':+!]+)/ig
	strContent = strContent.replace(re,"<img align=absmiddle src=/images/url.gif><a target=_blank href=$1>$1</a>")
	re =/^(mms:\/\/[A-Za-z0-9\.\/=\?%\-&_~`@':+!]+)/ig
	strContent = strContent.replace(re,"<img align=absmiddle src=/images/url.gif><a target=_blank href=$1>$1</a>")
	re =/(mms:\/\/[A-Za-z0-9\.\/=\?%\-&_~`@':+!]+)$/ig
	strContent = strContent.replace(re,"<img align=absmiddle src=/images/url.gif><a target=_blank href=$1>$1</a>")
	re =/[^>=""](mms:\/\/[A-Za-z0-9\.\/=\?%\-&_~`@':+!]+)/ig
	strContent = strContent.replace(re,"<img align=absmiddle src=/images/url.gif><a target=_blank href=$1>$1</a>")

	if(strIcons == "1"){                       //笑脸转换
	re=/(\[em(.*?)\])/ig
	strContent=strContent.replace(re,"<img src="+picurl+ImgName+"$2.gif border=0 align=middle> ")
	}

	if(strSmile == "1"){                       //笑脸转换
	re=/(\[s(\d{1,2})\])/ig
	strContent=strContent.replace(re,"<img src=/images/smile/face$2.gif border=0 align=middle> ")
	}

	re=/(\[color=(.[^\[]*)\])(.*?)(\[\/color\])/ig
	strContent=strContent.replace(re,"<font color=$2>$3</font>")
	re=/(\[face=(.[^\[]*)\])(.*?)(\[\/face\])/ig
	strContent=strContent.replace(re,"<font face=$2>$3</font>")
	re=/(\[align=(.[^\[]*)\])(.*?)(\[\/align\])/ig
	strContent=strContent.replace(re,"<div align=$2>$3</div>")
//循环转换quote
	re=/(\[quote\])(.*?)(\[\/quote\])/ig
	while(strContent.indexOf("[quote]")>-1 && strContent.indexOf("[/quote]")>0){
	strContent=strContent.replace(re,"<blockquote>引用:<hr><span>$2</span><hr></blockquote>")
	}
	re=/(\[fly\])(.*?)(\[\/fly\])/ig
	strContent=strContent.replace(re,"<marquee width=90% behavior=alternate scrollamount=3>$2</marquee>")
	re=/(\[move\])(.*?)(\[\/move\])/ig
	strContent=strContent.replace(re,"<MARQUEE scrollamount=3>$2</marquee>")	
	re=/\[GLOW=*([0-9]*),*(#*[a-z0-9]*),*([0-9]*)\](.*?)\[\/GLOW]/ig
	strContent=strContent.replace(re,"<table width=$1 style=\"filter:glow(color=$2, strength=$3)\">$4</table>")
	re=/\[SHADOW=*([0-9]*),*(#*[a-z0-9]*),*([0-9]*)\](.*?)\[\/SHADOW]/ig
	strContent=strContent.replace(re,"<table width=$1 style=\"filter:shadow(color=$2, strength=$3)\">$4</table>")

	re=/(\[i\])(.*?)(\[\/i\])/ig
	strContent=strContent.replace(re,"<i>$2</i>")
	re=/(\[u\])(.*?)(\[\/u\])/ig
	strContent=strContent.replace(re,"<u>$2</u>")
	re=/(\[b\])(.*?)(\[\/b\])/ig
	strContent=strContent.replace(re,"<b>$2</b>")

	re=/(\[size=1\])(.*?)(\[\/size\])/ig
	strContent=strContent.replace(re,"<font size=1>$2</font>")
	re=/(\[size=2\])(.*?)(\[\/size\])/ig
	strContent=strContent.replace(re,"<font size=2>$2</font>")
	re=/(\[size=3\])(.*?)(\[\/size\])/ig
	strContent=strContent.replace(re,"<font size=5>$2</font>")
	re=/(\[size=4\])(.*?)(\[\/size\])/ig
	strContent=strContent.replace(re,"<font size=6>$2</font>")
	
	re=/\[size=([+|-]?[0-7])\](.*?)(\[\/size\])/ig
	strContent=strContent.replace(re,"<font size=$1>$2</font>")
	
	re=/(\[list\])(.+?)(\[\/list\])/ig;
    strContent=strContent.replace(re,"<UL TYPE=SQUARE>$2<\/UL>");
    re=/(\[list=)(A|1)(\])(.+?)(\[\/list\])/ig;
    strContent=strContent.replace(re,"<OL TYPE=$2>$4<\/OL>");
    re=/(\[\*\])/ig;
    strContent=strContent.replace(re,"<LI>");

	re=/(\[center\])(.*?)(\[\/center\])/ig
	strContent=strContent.replace(re,"<center>$2</center>")

return(strContent);
}
