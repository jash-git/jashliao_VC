function setCookie(Key,value) {
var today = new Date();
var expireDay = new Date();
var month1 = 30*60*1000;
expireDay.setTime(today.getTime() + month1);
document.cookie = Key + "=" + value +
";expires=" + expireDay.toGMTString();
}
function getCookie(Key){
var search = Key + "=";
begin = document.cookie.indexOf(search);
if (begin != -1){
begin += search.length;
end = document.cookie.indexOf(";",begin);
if (end == -1) end = document.cookie.length;
return document.cookie.substring(begin,end);
}
}
setCookie("Aboutweb_120x90 Button","time");
if (getCookie("Aboutweb_120x90 Button")==null){
var bbb=100000000;    
var aaa=0.00000000000001; 
var ccc=0.00000000000001; 
tips = new Array(10);
tips[0] = "<iframe name='Aboutweb_120x90 Button' src='http://admin1.aboutweb.com.tw/js/ad.aspx?ad_mode=Microsoft%2c&xml=jammy98&word=120x90 Button' height='90' width='120' scrolling='no' border='0' frameborder='0' marginwidth='0' marginheight='0'></iframe>"
tips[1] = "<iframe name='Aboutweb_120x90 Button' src='http://admin1.aboutweb.com.tw/js/ad.aspx?ad_mode=Microsoft%2c&xml=jammy98&word=120x90 Button_Cookies' height='90' width='120' scrolling='no' border='0' frameborder='0' marginwidth='0' marginheight='0'></iframe>"
tips[2] = "<iframe name='Aboutweb_120x90 Button' src='http://admin1.aboutweb.com.tw/js/ad.aspx?ad_mode=Microsoft%2c&xml=jammy98&word=120x90 Button_Cookies' height='90' width='120' scrolling='no' border='0' frameborder='0' marginwidth='0' marginheight='0'></iframe>"
tips[3] = "<iframe name='Aboutweb_120x90 Button' src='http://admin1.aboutweb.com.tw/js/ad.aspx?ad_mode=Microsoft%2c&xml=jammy98&word=120x90 Button_Cookies' height='90' width='120' scrolling='no' border='0' frameborder='0' marginwidth='0' marginheight='0'></iframe>"
tips[4] = "<iframe name='Aboutweb_120x90 Button' src='http://admin1.aboutweb.com.tw/js/ad.aspx?ad_mode=Microsoft%2c&xml=jammy98&word=120x90 Button_Cookies' height='90' width='120' scrolling='no' border='0' frameborder='0' marginwidth='0' marginheight='0'></iframe>"
tips[5] = "<iframe name='Aboutweb_120x90 Button' src='http://admin1.aboutweb.com.tw/js/ad.aspx?ad_mode=Microsoft%2c&xml=jammy98&word=120x90 Button_Cookies' height='90' width='120' scrolling='no' border='0' frameborder='0' marginwidth='0' marginheight='0'></iframe>"
tips[6] = "<iframe name='Aboutweb_120x90 Button' src='http://admin1.aboutweb.com.tw/js/ad.aspx?ad_mode=Microsoft%2c&xml=jammy98&word=120x90 Button_Cookies' height='90' width='120' scrolling='no' border='0' frameborder='0' marginwidth='0' marginheight='0'></iframe>"
tips[7] = "<iframe name='Aboutweb_120x90 Button' src='http://admin1.aboutweb.com.tw/js/ad.aspx?ad_mode=Microsoft%2c&xml=jammy98&word=120x90 Button_Cookies' height='90' width='120' scrolling='no' border='0' frameborder='0' marginwidth='0' marginheight='0'></iframe>"
tips[8] = "<iframe name='Aboutweb_120x90 Button' src='http://admin1.aboutweb.com.tw/js/ad.aspx?ad_mode=Microsoft%2c&xml=jammy98&word=120x90 Button_Cookies' height='90' width='120' scrolling='no' border='0' frameborder='0' marginwidth='0' marginheight='0'></iframe>"
tips[9] = "<iframe name='Aboutweb_120x90 Button' src='http://admin1.aboutweb.com.tw/js/ad.aspx?ad_mode=Microsoft%2c&xml=jammy98&word=120x90 Button_Cookies' height='90' width='120' scrolling='no' border='0' frameborder='0' marginwidth='0' marginheight='0'></iframe>"
index = Math.floor(Math.random() * tips.length);
document.write(tips[index]);
}else{
if (getCookie("Aboutweb_120x90 Button1")==null){
document.write('<iframe name="Aboutweb_120x90 Button" src="http://admin1.aboutweb.com.tw/js/ad.aspx?ad_mode=Microsoft%2c&xml=jammy98&word=120x90 Button" height="90" width="120" scrolling="no" border="0" frameborder="0" marginwidth="0" marginheight="0"></iframe>')
setCookie("Aboutweb_120x90 Button1","time");
}else{
document.write('<iframe name="Aboutweb_120x90 Button" src="http://admin1.aboutweb.com.tw/js/ad.aspx?ad_mode=Microsoft%2c&xml=jammy98&word=120x90 Button_Cookies" height="90" width="120" scrolling="no" border="0" frameborder="0" marginwidth="0" marginheight="0"></iframe>')
}
}
