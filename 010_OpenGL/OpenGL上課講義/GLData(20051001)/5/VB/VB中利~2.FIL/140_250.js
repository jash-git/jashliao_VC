var srcurl;

function get_url(){
	var temp;
	for (i=0;i<document.scripts.length;i++)	{
		temp = document.scripts[i].src;
				if( (temp.indexOf('sinauserid') != -1) || (temp.indexOf("&key=0")!= -1) ) return temp;			
			
	}
}

srcurl = get_url();
var mkey;

mkey = srcurl.indexOf("&key=0")

function sub_cl(src,num){
	
	return eval("'"+src+"'.substr('"+src+"'.indexOf('c"+num+"=')+3,7)");
	

}

if ( mkey != -1 ){
	var c1=parent.document.tablestyle.h1.value
	var c2=parent.document.tablestyle.h2.value
	var c3=parent.document.tablestyle.h3.value
} else {
	
	var c1=sub_cl(srcurl,1)
	var c2=sub_cl(srcurl,2)
	var c3=sub_cl(srcurl,3)
}


function getuser(src){
	
	var I = src.substr(src.indexOf("?sinauserid=") + 12).length;
	
	if (0 >= I) return -1;
	if (I == src.length) return -1;
	return src.substr(src.indexOf("?sinauserid=") + 12,src.indexOf("&") - src.indexOf("?sinauserid=") - 12);
}


var tempid = getuser(srcurl);
function preview(id,aid) { //v2.0
	var tempid = getuser(srcurl)
	window.open('http://sms.sina.com.cn/cgi-bin/sms/picpre.cgi?aid='+aid+'&from='+tempid+'&id='+id,'logo','location=yes,width=400,height=500');
}

function prelisten(id) { //v2.0
	var tempid = getuser(srcurl)
	window.open('http://sms.sina.com.cn/cgi-bin/sms/ringpre.cgi?aid=27&id='+id+'&from='+tempid,'music','location=yes,width=400,height=500');
}


function listmore(aid) { //v2.0
	var tempid = getuser(srcurl)
	window.open('http://sms.sina.com.cn/cgi-bin/sms/piclist.cgi?aid='+aid+'&from='+tempid,'music');
}

function listmore1(aid) { //v2.0
	var tempid = getuser(srcurl)
	window.open('http://sms.sina.com.cn/cgi-bin/sms/ringlist.cgi?aid='+aid+'&from='+tempid,'music');
}

function dxdy(aid){//v2.0	上海
	var tempid = getuser(srcurl)
	window.open('http://sms2.sina.com.cn/cgi-bin/smsally/ally_custom.cgi?from='+tempid);
}


document.write("<style>");
document.write(".l15 {line-height:150%}");
document.write("A.lk5:link,A.lk5:visited {color:#ffffff;font-size:12px;}");
document.write("A.lk5:active,A.lk5:hover {color:#FBDF6F;font-size:12px;}");
document.write(".cs1{color:"+c1+"}");
document.write(".cs2{color:"+c2+"}");
document.write(".cs3{color:"+c3+"}");
document.write(".cs4{color:"+c1+";border-color:"+c1+"}");
document.write(".cs5{background-color:"+c1+";color:#ffffff;}");
document.write(".cs6{background-color:"+c2+"}");
document.write("td{font-size:12px;}");
document.write("</style>");
document.write("<table width=140 border=0 cellpadding=0 cellspacing=0>");
document.write("<tr valign=bottom>");
document.write("<td >");
document.write("	<table width=140 border=0 cellpadding=0 cellspacing=0>");
document.write("	<tr><td height=21 class=cs5>&nbsp<b>精彩短信</b>&nbsp&nbsp<a href=javascript:dxdy() class=cs1><font color=#ffffff>短信订阅</font></a></td></tr>");
document.write("	</table></td></tr>");
document.write("<tr><td height=2></td></tr>");
document.write("</table>");
document.write("<table border=0 cellpadding=1 cellspacing=0 class=cs5 width=140>");
document.write("<tr><td>");
document.write("	  <table border=0 cellpadding=0 cellspacing=0 class=cs6 width=138 height=194>");
document.write("        <tr>");
document.write("          <td width=140 align=center valign=top> ");
document.write("            <table border=0 cellpadding=0 cellspacing=0 width=134>");
document.write("              <tr> ");
document.write("                <td height=24 align=center><a href=javascript:listmore(10) class=cs1>诺基亚图片</a></td>");
document.write("                <td class=l15 height=24 colspan=2 align=center valign=middle><a href=javascript:listmore1(27) class=cs1>铃声传情</a></td>");
document.write("              </tr>");
document.write("              <tr> ");
document.write("                <td><a href=javascript:preview(101243,10)><img src=http://image2.sina.com.cn/sms/sinarc/preview/10/101/101243.gif width=72 height=14 class=cs4 border=1></a></td>");
document.write("                <td rowspan=12 valign=top> ");
document.write("                  <table width=100% border=0>");
document.write("                    <tr> ");
document.write("                      <td height=19><a href=javascript:prelisten('103217') class=cs3>简单情歌</a></td>");
document.write("                    </tr>");
document.write("                    <tr> ");
document.write("                      <td height=19><a href=javascript:prelisten('103218') class=cs3>小薇</a></td>");
document.write("                    </tr>");
document.write("                    <tr> ");
document.write("                      <td height=19><a href=javascript:prelisten('103219') class=cs3>只为你唱</a></td>");
document.write("                    </tr>");
document.write("                    <tr> ");
document.write("                      <td heigh=19><a href=javascript:prelisten('103214') class=cs3>咖啡</a></td>");
document.write("                    </tr>");
document.write("                    <tr> ");
document.write("                      <td height=19><a href=javascript:prelisten('103221') class=cs3>坚持到底</a></td>");
document.write("                    </tr>");
document.write("                    <tr> ");
document.write("                      <td height=19><a href=javascript:prelisten('103222') class=cs3>惩罚</a></td>");
document.write("                    </tr>");
document.write("                    <tr> ");
document.write("                      <td height=19><a href=javascript:prelisten('103224') class=cs3>专注</a></td>");
document.write("                    </tr>");
document.write("					<tr> ");
document.write("                      <td height=18><a href=javascript:prelisten('103211') class=cs3>握你的手</a></td>");
document.write("                    </tr>");
document.write("                  </table>");
document.write("                </td>");
document.write("              </tr>");
document.write("              <tr> ");
document.write("                <td height=8></td>");
document.write("              </tr>");
document.write("              <tr> ");
document.write("                <td><a href=javascript:preview(101455,10)><img src=http://image2.sina.com.cn/sms/sinarc/preview/10/101/101455.gif border=1 class=cs4></a></td>");
document.write("              </tr>");
document.write("              <tr> ");
document.write("                <td height=6></td>");
document.write("              </tr>");
document.write("              <tr> ");
document.write("                <td><a href=javascript:preview(102252,10)><img src=http://image2.sina.com.cn/sms/sinarc/preview/10/102/102252.gif border=1 class=cs4></a></td>");
document.write("              </tr>");
document.write("              <tr> ");
document.write("                <td height=6></td>");
document.write("              </tr>");
document.write("              <tr> ");
document.write("                <td><a href=javascript:preview(100385,10)><img src=http://image2.sina.com.cn/sms/sinarc/preview/10/100/100385.gif border=1 class=cs4></a></td>");
document.write("              </tr>");
document.write("              <tr> ");
document.write("                <td height=8></td>");
document.write("              </tr>");
document.write("              <tr> ");
document.write("                <td><a href=javascript:preview(109649,14,0)><img src=http://image2.sina.com.cn/sms/sinarc/preview/10/109/109649.gif border=1 class=cs4></a></td>");
document.write("              </tr>");
document.write("              <tr> ");
document.write("                <td height=6></td>");
document.write("              </tr>");
document.write("              <tr> ");
document.write("                <td><a href=javascript:preview(109507,14,0)><img src=http://image2.sina.com.cn/sms/sinarc/preview/10/109/109507.gif border=1 class=cs4></a></td>");
document.write("              </tr>");
document.write("              <tr> ");
document.write("                <td height=6></td>");
document.write("              </tr>");
document.write("            </table>");
document.write("          </td>");
document.write("        </tr>");
document.write("      </table>");
document.write("    </td></tr>");
document.write("</table>");
