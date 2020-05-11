/*
 * Copyright (c) 2008-2010, PIXNET Digital Media Corporation.
 * All rights reserved.
 */
_refererCount=function(){try{var _image_src="http://referer.pixplug.in/stat";var _userdata="&ver=1.0&random="+Math.random();var _attr=new Array("_currentPageUsername","document.URL","document.referrer","navigator.userAgent","window.closed","window.location");for(i=0;i<_attr.length;i++){_userdata+="&"+_attr[i]+"="+encodeURIComponent(eval(_attr[i]))}var i=new Image(1,1);i.src=_image_src+"?"+_userdata}catch(e){}};