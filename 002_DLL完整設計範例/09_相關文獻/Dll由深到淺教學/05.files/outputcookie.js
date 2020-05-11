var Base64 = function() {
}
Base64.encodeChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
Base64.decodeChars = new Array(- 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, - 1, 62, - 1, - 1, - 1, 63, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, - 1, - 1, - 1, - 1, - 1, - 1, - 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, - 1, - 1, - 1, - 1, - 1, - 1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, - 1, - 1, - 1, - 1, - 1);
Base64.encode = function(str)
{
    var out, i, len;
    var c1, c2, c3;

    len = str.length;
    i = 0;
    out = "";
    while (i < len)
    {
        c1 = str.charCodeAt(i++) & 0xff;
        if (i == len)
        {
            out += Base64.encodeChars.charAt(c1 >> 2);
            out += Base64.encodeChars.charAt((c1 & 0x3) << 4);
            out += "==";
            break;
        }
        c2 = str.charCodeAt(i++);
        if (i == len)
        {
            out += Base64.encodeChars.charAt(c1 >> 2);
            out += Base64.encodeChars.charAt(((c1 & 0x3) << 4) | ((c2 & 0xF0)
                    >> 4));
            out += Base64.encodeChars.charAt((c2 & 0xF) << 2);
            out += "=";
            break;
        }
        c3 = str.charCodeAt(i++);
        out += Base64.encodeChars.charAt(c1 >> 2);
        out += Base64.encodeChars.charAt(((c1 & 0x3) << 4) | ((c2 & 0xF0) >> 4))
                ;
        out += Base64.encodeChars.charAt(((c2 & 0xF) << 2) | ((c3 & 0xC0) >> 6))
                ;
        out += Base64.encodeChars.charAt(c3 & 0x3F);
    }
    return out;
}

Base64.decode = function(str)
{
    var c1, c2, c3, c4;
    var i, len, out;

    len = str.length;
    i = 0;
    out = "";
    while (i < len)
    {
        /* c1 */
        do
        {
            c1 = Base64.decodeChars[str.charCodeAt(i++) & 0xff];
        }
        while (i < len && c1 == - 1);
        if (c1 == - 1)
            break;

        /* c2 */
        do
        {
            c2 = Base64.decodeChars[str.charCodeAt(i++) & 0xff];
        }
        while (i < len && c2 == - 1);
        if (c2 == - 1)
            break;

        out += String.fromCharCode((c1 << 2) | ((c2 & 0x30) >> 4));

        /* c3 */
        do
        {
            c3 = str.charCodeAt(i++) & 0xff;
            if (c3 == 61)
                return out;
            c3 = Base64.decodeChars[c3];
        }
        while (i < len && c3 == - 1);
        if (c3 == - 1)
            break;

        out += String.fromCharCode(((c2 & 0XF) << 4) | ((c3 & 0x3C) >> 2));

        /* c4 */
        do
        {
            c4 = str.charCodeAt(i++) & 0xff;
            if (c4 == 61)
                return out;
            c4 = Base64.decodeChars[c4];
        }
        while (i < len && c4 == - 1);
        if (c4 == - 1)
            break;
        out += String.fromCharCode(((c3 & 0x03) << 6) | c4);
    }
    return out;
}

Base64.utf16to8 = function(str)
{
    var out, i, len, c;

    out = "";
    len = str.length;
    for (i = 0; i < len; i++)
    {
        c = str.charCodeAt(i);
        if ((c >= 0x0001) && (c <= 0x007F))
        {
            out += str.charAt(i);
        }
        else if (c > 0x07FF)
        {
            out += String.fromCharCode(0xE0 | ((c >> 12) & 0x0F));
            out += String.fromCharCode(0x80 | ((c >> 6) & 0x3F));
            out += String.fromCharCode(0x80 | ((c >> 0) & 0x3F));
        }
        else
        {
            out += String.fromCharCode(0xC0 | ((c >> 6) & 0x1F));
            out += String.fromCharCode(0x80 | ((c >> 0) & 0x3F));
        }
    }
    return out;
}

Base64.utf8to16 = function(str)
{
    var out, i, len, c;
    var char2, char3;

    out = "";
    len = str.length;
    i = 0;
    while (i < len)
    {
        c = str.charCodeAt(i++);
        switch (c >> 4)
                {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            // 0xxxxxxx
                out += str.charAt(i - 1);
                break;
            case 12:
            case 13:
            // 110x xxxx   10xx xxxx
                char2 = str.charCodeAt(i++);
                out += String.fromCharCode(((c & 0x1F) << 6) | (char2 & 0x3F));
                break;
            case 14:
            // 1110 xxxx  10xx xxxx  10xx xxxx
                char2 = str.charCodeAt(i++);
                char3 = str.charCodeAt(i++);
                out += String.fromCharCode(((c & 0x0F) << 12) | ((char2 & 0x3F)
                        << 6) | ((char3 & 0x3F) << 0));
                break;
        }
    }

    return out;
}


function getCookie(name) //取cookies函数
{
    var arr = document.cookie.match(new RegExp("(^| )" + name + "=([^;]*)(;|$)"));
    if (arr != null) return unescape(Base64.decode(arr[2].toString()));
    return null;
}


var findInfoCookie = "my_tmggroup_info_ck";
//pin&sex
var findNickCookie = "my_tmggroup_nick_ck";
//nickname

function pinCookie() {
    var pin = null;
    var start = "up=";
    var info = getCookie(findInfoCookie);
    if (info != null) {
        if (info.indexOf("&") != -1) {
            pin = info.substring(start.length, info.indexOf("&"));
        }
    }
    return pin;
}
function uidCookie() {
    var uid = null;
    var start = "uid=";
    var info = getCookie(findInfoCookie);
    //alert(info);
    if (info != null) {
        if (info.indexOf(start) != -1) {
            uid = info.substring(info.indexOf(start)+start.length, info.length);
        }
    }
    return uid;
}

/**
 sex 对应值
 0未知
 1保密
 2男
 3女
 */
function sexCookie() {
    var sex = null;
    var start = "sex=";
    var info = getCookie(findInfoCookie);
    if (info != null) {
        if (info.indexOf(start) != -1) {
            sex = info.substring(info.indexOf(start) + start.length, info.length);
            if (sex == "0") sex = "未知";
            if (sex == "1") sex = "保密";
            if (sex == "2") sex = "男";
            if (sex == "3") sex = "女";
        }
    }
    document.getElementById("sex").innerHTML = sex;
    //return sex;
}
function nickCookie() {
    document.getElementById("nick").innerHTML = getCookie(findNickCookie);

}

function nickCookieValue() {
    document.getElementById("nick").value = getCookie(findNickCookie);

}

//登陆频道cookie
var findLogCookie = "my_tmggroup_loginfo_ck";


function passportloginfo(){
   //登陆cookie存在
   if(pinCookie() != null){
       //频道cookie不存在，则生成频道cookie
	   if(passportGetCookieNoBase(findLogCookie)==null){
          var domainStr=document.domain; 
	      passportSetCookie(findLogCookie,domainStr);
          var image=document.createElement("img");
	      image.src="http://passport.yesky.com/cas/clogin?customerid="+uidCookie()+"&domain="+location.hostname+"&ty=1";
	      
	      
		//如果频道cookie存在，则查找当前访问域名是否存在于频道cookie中
	   }else{
	      var domainValue=passportGetCookieNoBase(findLogCookie);
	      var nowDomain=document.domain;
          //写入频道cookie。并且写入日志。
	      if(domainValue.indexOf(nowDomain)<0){
	         passportSetCookie(findLogCookie,domainValue+";"+nowDomain);
	         //代码预留，写入数据库，带url，入库时，字典判断url，获得站点和产品id，写入记录。入口判断可以在login.java中直接写入
             var image=document.createElement("img");
		     image.src="http://passport.yesky.com/cas/clogin?customerid="+uidCookie()+"&domain="+location.hostname+"&ty=2";
	      }
	   }
   }
}


//设置cookie
function passportSetCookie(c_name,value){
  var date=new Date();
  var expireDate=new Date(date.getFullYear(),date.getMonth(),date.getDate()+1);
  document.cookie=c_name+ "=" +escape(value)+";path=/;domain=.yesky.com"+";expires="+expireDate.toGMTString();
}


//获得不需要转义的cookie值
function passportGetCookieNoBase(name) //取cookies函数
{
    var arr = document.cookie.match(new RegExp("(^| )" + name + "=([^;]*)(;|$)"));
    if (arr != null) return arr[2].toString();
    return null;
}
//随着getcookie变化，这个也重写
function passportUidCookie() {
    var uid = null;
    var start = "uid=";
    var info = getCookie(findInfoCookie);
    //alert(info);
    if (info != null) {
        if (info.indexOf(start) != -1) {
            uid = info.substring(info.indexOf(start)+start.length, info.length);
        }
    }
    return uid;
}

//执行
passportloginfo();