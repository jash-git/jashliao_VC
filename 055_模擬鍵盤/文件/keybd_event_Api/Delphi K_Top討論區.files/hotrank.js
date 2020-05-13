
var expdate = new Date();
expdate.setTime (expdate.getTime() +  (60 * 1000 )); 
document.cookie = "HMS=6050e14e2eec648c; expires=" + expdate.toGMTString() +  "; path=/";

var nav = navigator;
var doc = document;
var agt = nav.userAgent.toLowerCase();
var apv = nav.appVersion.toLowerCase();
var cpu = nav.cpuClass ? escape(nav.cpuClass) : escape(nav.oscpu);
var plf = escape(nav.platform);
var lan = nav.browserLanguage ? nav.browserLanguage : 
	nav.userLanguage ? nav.userLanguage : nav.language;
var apn = (nav.appName == 'Microsoft Internet Explorer') ? '_MSIE' :
	(nav.appName == 'Netscape') ? '_NS' : escape(nav.appName);

var tz = (new Date()).getTimezoneOffset() * (-1);
var sc = 'W' + screen.width + 'H' + screen.height;
var cd = screen.colorDepth;
var wv,fv,xv,cy,acv,xmv,qtv;
var dt = encodeURIComponent(doc.title);
var dl = encodeURIComponent(doc.location);
var rr = encodeURIComponent(doc.referrer);

var qs = 'uid=' + '42197';
qs += '&ts=1125987446';
qs += '&cs=6050e14e2eec648c';
qs += '&apn=' + apn;
qs += '&plf=' + plf;
qs += '&cpu=' + cpu;
qs += '&lan=' + lan;
qs += '&tz=' + tz;
qs += '&sc=' + sc;
qs += '&cd=' + cd;
qs += '&dl=' + dl;
qs += '&rr=' + rr;

if ( nav.product ) {
	qs += '&npd=' + escape(nav.product);
	}
if ( nav.productSub ) {
	qs += '&nps=' + escape(nav.productSub);
	}
if ( nav.vendor ) {
	qs += '&nvd=' + escape(nav.vendor);
	}
if ( nav.vendorSub ) {
	qs += '&nvs=' + escape(nav.vendorSub);
	}
// document.write("<h3>CNFO...</h3>");
qs += '&cy=' + 'lan';
qs += '&fv=' + '7,0,19,0';
qs += '&wv=' + '6,4,7,1121';
qs += '&xv=' + '6,0,2800,1106';
qs += '&acv=' + '0.0';
qs += '&xmv=' + '3.0';
qs += '&qtv=' + '0.0';
qs += '&jsv=' + 'JS13';
qs += '&dt=' + dt;
document.write("<script src=http://h03.hotrank.com.tw/hotrank88?" + qs + "></script>");
