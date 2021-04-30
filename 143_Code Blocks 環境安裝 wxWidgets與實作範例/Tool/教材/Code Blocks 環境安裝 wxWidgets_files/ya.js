var $yAFun = new function () {
    //Event
    this.yAPageEvent = function (obj, evType, fn) {
        try {
            if (obj.addEventListener) {
                obj.addEventListener(evType, fn, true);
                return true;
            } else if (obj.attachEvent) {
                var r = obj.attachEvent("on" + evType, fn);
                return r;
            } else {
                return false;
            }
        } catch (e) { }
    }

    //Cookie
    this.GetCookie = function (name) {
        try {
            var arg = name + "=";
            var alen = arg.length;
            var clen = document.cookie.length;
            var i = 0;
            while (i < clen) {
                var j = i + alen;
                if (document.cookie.substring(i, j) == arg) return this.GetCookieVal(j);
                i = document.cookie.indexOf(" ", i) + 1;
                if (i == 0) break;
            }
        } catch (e) { }
        return null;
    }
    this.GetCookieVal = function (offset) {
        try {
            var endstr = document.cookie.indexOf(";", offset);
            if (endstr == -1) endstr = document.cookie.length;
            return decodeURI(document.cookie.substring(offset, endstr));
        } catch (e) { }
        return null;
    }
    this.PostCookie = function (name, val, exp, expday) {
        try {
            var date = new Date();
            date.setDate(date.getDate() + expday);

            if (exp)
                document.cookie = name + "=" + val + " ; domain=" + yAcd + " ; expires=" + date.toGMTString() + " ; path=/";
            else
                document.cookie = name + "=" + val + " ; domain=" + yAcd + " ; path=/";

            //檢查是否以寫入 如果沒寫入 寫入本網域
            if (this.GetCookie(name) == null) {
                if (exp)
                    document.cookie = name + "=" + val + " ; expires=" + date.toGMTString() + " ; path=/";
                else
                    document.cookie = name + "=" + val + " ; path=/";
            }
        } catch (e) { }
    }
    this.DelCookie = function (name) {
        var date = new Date();
        date.setTime(date.getTime() + (-1 * 24 * 60 * 60 * 1000));
        document.cookie = name + "= ; domain=yam.com ; expires=" + date.toGMTString() + " ; path=/";
    }

    var yAld = (new Date()).getTime();
    var yAet = 0;
    var yApt = document.title;
    var yApc = document.characterSet ? document.characterSet.toLowerCase() : document.charset ? document.charset.toLowerCase() : "utf-8";
    var yAph = document.location.hostname;
    var yApl = document.location;
    var yApr = document.referrer;
    var yAuj = navigator.javaEnabled() ? 1 : 0;
    var yAus = screen.width + "x" + screen.height;
    var yAul = function () {
        var UL = (typeof navigator.language != "undefined") ? navigator.language.toLowerCase() : navigator.userLanguage.toLowerCase();
        if (UL.length == 0) UL = "Undefined";
        return UL;
    } ();
    var yAuc = function UserColor() {
        var UC = (typeof screen.pixelDepth != "undefined") ? screen.pixelDepth : screen.colorDepth;
        UC = UC.length == 0 ? "Undefined" : parseInt(UC, 10) >= 24 ? "32" : UC;
        return UC;
    } ();
    var yAuf = function UserFlash() {
        var version = "";
        if (typeof navigator.plugins != "undefined" && typeof navigator.plugins["Shockwave Flash"] == "object") {
            var obj = navigator.plugins["Shockwave Flash"].description;
            if (obj) version = obj.replace(/^.*\s+(\S+\s+\S+$)/, "$1");
        } else if (typeof window.ActiveXObject != "undefined") {
            var obj = null, fp6Crash = false;
            try {
                obj = new ActiveXObject("ShockwaveFlash.ShockwaveFlash.7");
            }
            catch (e) {
                try {
                    obj = new ActiveXObject("ShockwaveFlash.ShockwaveFlash.6");
                    version = "6.0 r21";
                    a.AllowScriptAccess = "always";
                }
                catch (e) { if (version.substr(0, 1) == 6) fp6Crash = true; }
                if (!fp6Crash) try { obj = new ActiveXObject("ShockwaveFlash.ShockwaveFlash"); } catch (e) { }
            }
            if (!fp6Crash && obj) {
                try {
                    var v = obj.GetVariable("$version");
                    if (v) {
                        v = v.split(" ")[1].split(",");
                        version = parseInt(v[0], 10) + "." + parseInt(v[1], 10) + " r" + parseInt(v[2], 10);
                    }
                }
                catch (e) { }
            }
        }
        if (version.length == 0) version = "Undefined";
        return version;
    } ();
    var yAcd = function () {
        var domain_root = window.location.hostname;
        try {
            var domain_country_list = "|ad|ae|af|ag|ai|al|am|an|ao|aq|ar|as|at|au|aw|az|ba|bb|bd|be|bf|bg|bh|bi|bj|bm|bn|bo|br|bs|bt|bv|bw|by|bz|ca|cc|cf|cg|ch|ci|ck|cl|cm|cn|co|cr|cu|cx|cy|cz|de|dj|dk|dm|do|dz|ec|ee|eg|eh|er|es|et|fi|fj|fk|fm|fo|fr|fx|ga|gb|gd|ge|gf|gh|gi|gl|gm|gn|gp|gq|gr|gs|gt|gu|gw|gy|hk|hm|hn|hr|ht|hu|id|ie|il|in|io|iq|ir|is|it|jm|jo|jp|ke|kg|kh|ki|km|kn|kp|kr|kw|ky|kz|la|lb|lc|li|lk|lr|ls|lt|lu|lv|ly|ma|mc|md|mg|mh|mk|ml|mm|mn|mo|mp|mq|mr|ms|mt|mu|mv|mw|mx|my|mz|na|nc|ne|nf|ng|ni|nl|no|np|nr|nu|nz|om|pa|pe|pf|pg|ph|pk|pl|pm|pn|pt|pw|py|qa|re|ro|ru|rw|sb|sc|sd|se|sg|sh|si|sl|sm|sn|so|sr|st|sv|sy|sz|tc|td|tf|tg|th|tj|tk|tm|tn|to|tp|tr|tt|tw|tz|ua|ug|um|us|uy|uz|va|vc|ve|vg|vi|vn|vu|wf|ws|ye|yt|yu|za|zm|zr|zw|";
            var domain_type_list = "|com|net|org|biz|info|asia|game|idv|name|club|info|ebiz|";
            var domain = window.location.hostname.split(".");
            if (domain.length >= 3) {
                var domain_1 = domain[domain.length - 1];
                var domain_2 = domain[domain.length - 2];
                if (domain_country_list.indexOf("|" + domain_1 + "|") > -1) {
                    domain_root = domain_type_list.indexOf("|" + domain_2 + "|") > -1 ? domain.slice(-3).join(".") : domain.slice(-2).join(".");
                }
                else if (domain_type_list.indexOf("|" + domain_1 + "|") > -1) {
                    domain_root = domain.slice(-2).join(".");
                } else {
                    domain_root = window.location.hostname;
                }
            }
        } catch (e) { }
        return domain_root;
    } ();
    function yAr() {
        return Math.round(Math.random() * 2147483647);
    }
    this.yAPadLeft = function (str, length, sign) {
        str += "";
        if (str.length >= length) return str;
        else return this.yAPadLeft(sign + str, length, sign);
    };
    this.yAunid_fun = function () {
        var unid = this.GetCookie("yamAnalytics");
        if (unid == null) {
            var rd = new Date();
            var rd_d = parseInt(this.yAPadLeft(rd.getMonth() + 1, 2, "0") + this.yAPadLeft(rd.getDate(), 2, "0") + this.yAPadLeft(rd.getHours(), 2, "0") + this.yAPadLeft(rd.getMinutes(), 2, "0"), 10).toString(16).toUpperCase();
            var rd_n = (Math.floor(Math.random() * (999999999 - 100000000 + 1)) + 100000000) + "";
            var rd_v = (999999999 - parseInt(rd_n, 10)).toString(16).toUpperCase();
            unid = rd_d + "_" + rd_n + "_" + rd_v;
            this.PostCookie("yamAnalytics", unid, true, 365);
        }
        return unid;
    };
    var yAQuery = ["yAunid=" + escape(this.yAunid_fun()), "yApt=" + escape(yApt), "yApc=" + escape(yApc), "yAph=" + escape(yAph), "yApl=" + escape(yApl), "yApr=" + escape(yApr), "yAuj=" + escape(yAuj), "yAus=" + escape(yAus), "yAul=" + escape(yAul), "yAuc=" + escape(yAuc), "yAuf=" + escape(yAuf)];
    var yAUrl = "//analytics.yam.com/Track.aspx?" + yAQuery.join("&");
    this.yATrack = function (online) {
        var Img = new Image();
        Img.src = yAUrl + "&yAr=" + yAr() + "&yAOnline=" + (online ? "1" : "0");
        Img.onerror = function () {
            setTimeout("$yAFun.yATrack(" + online + ")", 3000);
        };
    };

    //使用者資訊
    this.yATrackMember = function () {
        try {
            var _f = document.createElement("iframe");
            _f.src = "//analytics.yam.com/TrackMember.aspx?yAunid=" + escape(this.yAunid_fun());
            _f.style.display = "none";
            _f.style.width = "0px";
            _f.style.height = "0px";
            var _b = document.getElementsByTagName("body")[0]; _b.parentNode.insertBefore(_f, _b);
        } catch (e) { }
    };

    //離開時間計算
    this.yAPageEvent(window, "mouseover", function () {
        if (!yAld) yAld = (new Date()).getTime();
    });
    this.yAPageEvent(window, "mouseout", function () {
        if (yAld) {
            yAet += parseInt((new Date()).getTime() - yAld, 10);
            yAld = null;
        }
    });
    this.yAPageEvent(window, "unload", function () {
        try {
            if (yAld) yAet += parseInt((new Date()).getTime() - yAld, 10);
            yAet = parseInt(yAet / 1000, 10);
            var Img = new Image();
            Img.src = yAUrl.replace("http:", "https:") + "&yAr=" + yAr() + "&yAet=" + yAet + "&yAOnline=2";
        } catch (e) { }
    });

    //顯示線上人數    
    if (this.GetCookie("yam_Analytics_Online") == "TRUE") {
        var _d = document.createElement("div");
        _d.style.position = "fixed";
        _d.style.top = "5px";
        _d.style.left = "5px";
        _d.innerHTML = "<iframe src=\"//analytics.yam.com/Online.aspx?URL=" + escape(document.location) + "\" scrolling=\"no\" frameborder=\"0\" style=\"border:none; overflow:hidden; width:100px; height:100px;\" allowTransparency=\"true\"></iframe>";
        try {
            document.getElementsByTagName("body")[0].appendChild(_d);
        } catch (e) {
            var _b = document.getElementsByTagName("body")[0];
            _b.parentNode.insertBefore(_d, _b);
        }
    }
} ();
$yAFun.yATrack(false);
$yAFun.yATrackMember();
setInterval("$yAFun.yATrack(true)", 290000);

function $yAImportJS(src, look_for, onload) {
    var s = document.createElement("script");
    s.setAttribute("type", "text/javascript");
    s.setAttribute("src", src);
    if (onload) $yAImportJSLoad(look_for, onload);
    if (eval("typeof " + look_for) == "undefined") {
        var head = document.getElementsByTagName("head")[0];
        if (head) head.appendChild(s); else document.body.appendChild(s);
    }
}
function $yAImportJSLoad(look_for, callback) {
    var interval = setInterval(function () {
        if (eval("typeof " + look_for) != "undefined") {
            clearInterval(interval);
            callback();
        }
    }, 50);
}

/*Google Map API*/
if ($yAFun.GetCookie("yamIP") != (new Date()).getHours() + "") {
    try {
        var _g = document.createElement("script");
        _g.type = "text/javascript";
        _g.async = true;
        _g.src = "//www.google.com/jsapi?" + parseInt(new Date().getTime(), 10);
        var _h = document.getElementsByTagName("head")[0];
        if (_h) _h.appendChild(_g); else document.body.appendChild(_g);
    } catch (e) { }
    function GIPLocation() {
        try {
            var _loc = google.loader.ClientLocation;
            if (_loc) {
                $.getJSON("//analytics.yam.com/TrackIP.aspx?LATITUDE=" + escape(_loc.latitude) + "&LONGITUDE=" + escape(_loc.longitude) + "&COUNTRY_CODE=" + escape(_loc.address.country_code) + "&COUNTRY=" + escape(_loc.address.country) + "&REGION=" + escape(_loc.address.region) + "&CITY=" + escape(_loc.address.city) + "&CALLBACK=?", function (data) {
                    if (data.STATE) $yAFun.PostCookie("yamIP", (new Date()).getHours() + "", false, 0);
                });
            }
            else {
                setTimeout("GIPLocation()", 500);
            }
        } catch (e) { }
    }
    $yAImportJS("//analytics.yam.com/JS/jquery-1.7.1.min.js", "jQuery", function () { GIPLocation(); });
}

/*
//Tag分析
function $yARemoveHTML(strText) {
return strText.replace(/<[^>]*>/g, " ");
}
function $yAcheckVal(str) {
var regExp = /^[\d|a-zA-Z0-9.:]+$/;
if (regExp.test(str))
return true;
else
return false;
}

var $yAURL = "//analytics.yam.com";
$yAImportJS($yAURL + "/JS/jquery-1.7.1.min.js", "jQuery", function () {
$("body").ready(function () {
var body_str = [];
var body_title = document.title;
var body_description = "";
var body_keyword = "";
$("meta").each(function () {
try {
switch ($(this).attr("name").toLowerCase()) {
case "title":
body_title = $.trim($yARemoveHTML($(this).attr("content")));
break;
case "description":
body_description = $.trim($yARemoveHTML($(this).attr("content")));
break;
case "keywords":
body_keyword = $.trim($yARemoveHTML($(this).attr("content")));
break;
default: break;
}
} catch (e) { }
});
if (body_title != "") body_str.push(body_title);
if (body_description != "") body_str.push(body_description);
if (body_keyword != "") body_str.push(body_keyword);

//讀取頁面資訊
var body_html = $("body").text();
$("script").each(function () {
body_html = body_html.replace($(this).text(), "");
});
$("style").each(function () {
body_html = body_html.replace($(this).text(), "");
});
body_html = body_html.replace(/ /g, "\n");
var body_line = body_html.split("\n");
for (var sid in body_line) {
var str = $.trim($yARemoveHTML(body_line[sid]));
if (str.length > 5 && !(new Date(str)).getFullYear() && !$yAcheckVal(str)) body_str.push(str);
}
var body_keyword = body_str.join("\n");
body_keyword = body_keyword.substring(0, 4500);
$.ajax({
url: $yAURL + "/TrackKeyword.aspx?callback=?",
dataType: 'json',
cache: false,
crossDomain: true,
data: { "keyword": escape(body_keyword) },
success: function (data) {
$.each(data, function (key, val) {
//alert(val);
});
}
});

//document.write(body_keyword);


});
});
*/