var qs = '&tx=1099408149&cs=961d8d79682735cd&rd=0';
qs += '&ni=1';
qs += '&nn=1';
var	nc = 0;

if (navigator) {
	if (navigator.appName.indexOf('Netscape') >= 0) nc = 1;
	qs += '&je=' + (navigator.javaEnabled() ? 1 : 0);
}

qs += '&tz=' + (new Date()).getTimezoneOffset() * (-1);

if (screen) {
	qs += '&re=W' + screen.width + 'H' + screen.height
	   +  '&cd=' + ((nc) ? screen.pixelDepth : screen.colorDepth);
}

qs += '&rr=' + document.referrer;

if (nc && navigator.plugins) {
	qs += '&np=';
	for (var re = false, i = 0, j = 0; i < navigator.plugins.length && j < 30; i++, re = false) {
		for (k = 0; k < i; k++) {
			if (navigator.plugins[i].name == navigator.plugins[k].name) {
				re = true;
				break;
			}
		}
		if (!re) {
			qs += escape(navigator.plugins[i].name + '```');
			j++;
		}
	}
}

document.write('<A HREF="http://www.hotrank.com.tw/" TARGET="HotRank">'
	     + '<IMG SRC="http://h03.hotrank.com.tw:1688/hotrank.gif?myid=h03-20418'
	     + qs + '" BORDER="0" ALT="«e©¹ Hotrank ­º­¶" WIDTH="1" HEIGHT="1"></A>');
