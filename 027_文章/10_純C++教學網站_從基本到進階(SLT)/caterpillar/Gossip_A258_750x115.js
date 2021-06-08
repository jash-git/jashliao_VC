document.write('')
var ts1 = document.charset; 
if(typeof(ts1)=='undefined'){ 
 ts1=document.characterSet; 
} 
if (typeof(ts1)=='undefined'){ 
	ts1='big5'; 
 } 
var ts2 = encodeURIComponent(location.href); 
var ts3 = ''; 
var ts4 =Math.random(); 
var ts5 = 'http://www.scupio.com/RedirectWeb/Redirect.aspx?class=1&channel=99999&type=007&event=07021201&url=http://ad.scupio.com.tw'; 
ts5 = encodeURIComponent(ts5); 
document.write('<scr' + 'ipt language="JavaScript" type="text/javascript" src="http://adsense2.scupio.com/ADPInline/ADViewer.aspx?s=0,4,750,115,FFFFFF,20,FFFFFF,2,1,15,1,13,3,0,6,1,,RM,BMK1,17,42&m=4&sh=color:333333;font-size:12px;line-height:18px;text-decoration:none;&ss=color:46839C;font-size:10pt;line-height:18px;text-decoration:underline;font-weight:bold;&sc=color:333333;font-size:10pt;MARGIN-TOP:1em;MARGIN-BOTTOM:1em;text-decoration:none;&su=color:FF9900;font-size:10pt&si=&r='+ts5+'&lang='+ts1+'&PubID=lSwDBRA3VQ==&CA='+ts4+'&KeyValue='+ts3+'&u=' + ts2 + '"></scr' + 'ipt>'); 
document.write(' ')