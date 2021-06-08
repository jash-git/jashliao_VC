var __cc_sys_url = "http://www.gissky.net/count/"
/*
	COCOON Counter 6 1900 count.js
	Copyright(r) Cocoon Studio (www.ccopus.com)
	coding by Sunrise_Chen (sunrise_chen@msn.com)
	2003-12-19
	
	Please don't remove these information.
*/

//var __cc_uid = "username";
//var __cc_style = 18;

function cc6_readCookie(name){
  var cookieValue = "";
  var search = name + "=";
  if(document.cookie.length > 0){ 
    offset = document.cookie.indexOf(search);
    if (offset != -1){ 
      offset += search.length;
      end = document.cookie.indexOf(";", offset);
      if (end == -1) end = document.cookie.length;
      cookieValue = unescape(document.cookie.substring(offset, end))
    }
  }
  return cookieValue;
}

function cc6_writeCookie(name, value, hours){
  var expire = "";
  if(hours != null){
    expire = new Date((new Date()).getTime() + hours * 3600000);
    expire = "; expires=" + expire.toGMTString();
  }
  document.cookie = name + "=" + escape(value) + expire;
}


var __cc_visited = 1;
var __cc_cookies_name = 'cc_6_visited_site_'+__cc_uid;
if(cc6_readCookie(__cc_cookies_name).length<1){
	cc6_writeCookie(__cc_cookies_name,1);
	__cc_visited=0;
}
if(typeof(__cc_style)=="undefined") __cc_style=18;
var __cc_page = escape(location.href);
var __cc_ref = escape(document.referrer);
var __cc_Color = screen.colorDepth;
var __cc_Language = (navigator.systemLanguage?navigator.systemLanguage:navigator.language);
var __cc_sSize = screen.width + '_' + screen.height;
var __cc_count = __cc_sys_url 
			   + "core/default.asp" + "?id=" + __cc_uid
			   + "&l=" + __cc_Language + "&t=" + __cc_style
			   + "&p=" + __cc_page + "&r=" + __cc_ref
			   + "&s=" + __cc_sSize + "&c=" + __cc_Color
			   + "&v=" + __cc_visited
			   + "&z=" + (new Date()).getTimezoneOffset()/60;
			   
document.write('<a href="'+__cc_sys_url+'supervise/index.asp?uid='+__cc_uid+'" target="_blank">'
	+ '<img src="'+__cc_count+'" width='+__cc_style+' height='+__cc_style+' alt="COCOON Counter 6" border=0>'
	+ '</a>');

//End of count.js