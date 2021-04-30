/*
CopyRight 2010, YAMEDIA All Rights Reserved.
Developer: CSCWORM.
*/

var yamBoxBase = ("https:" == document.location.protocol ? "https://" : "http://") + "member.yam.com/BOX/";
var yamBox_is_ie6 = document.all && (navigator.userAgent.toLowerCase().indexOf("msie 6.") != -1);
var yamBox_is_ie7 = document.all && (navigator.userAgent.toLowerCase().indexOf("msie 7.") != -1);
var yamBox_is_Mobile = false;
var yamBox_navigator = navigator.userAgent||navigator.vendor||window.opera;
if (/android|avantgo|blackberry|blazer|compal|elaine|fennec|hiptop|iemobile|ip(hone|od)|iris|kindle|lge |maemo|midp|mmp|opera m(ob|in)i|palm( os)?|phone|p(ixi|re)\/|plucker|pocket|psp|symbian|treo|up\.(browser|link)|vodafone|wap|windows (ce|phone)|xda|xiino/i.test(yamBox_navigator) || /1207|6310|6590|3gso|4thp|50[1-6]i|770s|802s|a wa|abac|ac(er|oo|s\-)|ai(ko|rn)|al(av|ca|co)|amoi|an(ex|ny|yw)|aptu|ar(ch|go)|as(te|us)|attw|au(di|\-m|r |s )|avan|be(ck|ll|nq)|bi(lb|rd)|bl(ac|az)|br(e|v)w|bumb|bw\-(n|u)|c55\/|capi|ccwa|cdm\-|cell|chtm|cldc|cmd\-|co(mp|nd)|craw|da(it|ll|ng)|dbte|dc\-s|devi|dica|dmob|do(c|p)o|ds(12|\-d)|el(49|ai)|em(l2|ul)|er(ic|k0)|esl8|ez([4-7]0|os|wa|ze)|fetc|fly(\-|_)|g1 u|g560|gene|gf\-5|g\-mo|go(\.w|od)|gr(ad|un)|haie|hcit|hd\-(m|p|t)|hei\-|hi(pt|ta)|hp( i|ip)|hs\-c|ht(c(\-| |_|a|g|p|s|t)|tp)|hu(aw|tc)|i\-(20|go|ma)|i230|iac( |\-|\/)|ibro|idea|ig01|ikom|im1k|inno|ipaq|iris|ja(t|v)a|jbro|jemu|jigs|kddi|keji|kgt( |\/)|klon|kpt |kwc\-|kyo(c|k)|le(no|xi)|lg( g|\/(k|l|u)|50|54|e\-|e\/|\-[a-w])|libw|lynx|m1\-w|m3ga|m50\/|ma(te|ui|xo)|mc(01|21|ca)|m\-cr|me(di|rc|ri)|mi(o8|oa|ts)|mmef|mo(01|02|bi|de|do|t(\-| |o|v)|zz)|mt(50|p1|v )|mwbp|mywa|n10[0-2]|n20[2-3]|n30(0|2)|n50(0|2|5)|n7(0(0|1)|10)|ne((c|m)\-|on|tf|wf|wg|wt)|nok(6|i)|nzph|o2im|op(ti|wv)|oran|owg1|p800|pan(a|d|t)|pdxg|pg(13|\-([1-8]|c))|phil|pire|pl(ay|uc)|pn\-2|po(ck|rt|se)|prox|psio|pt\-g|qa\-a|qc(07|12|21|32|60|\-[2-7]|i\-)|qtek|r380|r600|raks|rim9|ro(ve|zo)|s55\/|sa(ge|ma|mm|ms|ny|va)|sc(01|h\-|oo|p\-)|sdk\/|se(c(\-|0|1)|47|mc|nd|ri)|sgh\-|shar|sie(\-|m)|sk\-0|sl(45|id)|sm(al|ar|b3|it|t5)|so(ft|ny)|sp(01|h\-|v\-|v )|sy(01|mb)|t2(18|50)|t6(00|10|18)|ta(gt|lk)|tcl\-|tdg\-|tel(i|m)|tim\-|t\-mo|to(pl|sh)|ts(70|m\-|m3|m5)|tx\-9|up(\.b|g1|si)|utst|v400|v750|veri|vi(rg|te)|vk(40|5[0-3]|\-v)|vm40|voda|vulc|vx(52|53|60|61|70|80|81|83|85|98)|w3c(\-| )|webc|whit|wi(g |nc|nw)|wmlb|wonu|x700|xda(\-|2|g)|yas\-|your|zeto|zte\-/i.test(yamBox_navigator.substr(0, 4))) yamBox_is_Mobile = true;

//名稱有*的表示 登入狀態不顯示的項目
var yamBox_Menu_Set = new Array(
    new Array("*登入", "LOGIN", yamBoxBase + "Login.aspx?URL=" + escape(location.href), yamBoxBase + "Images/tab-login-out.png", yamBoxBase + "Images/tab-login-hover.png", true, 550, 570),
    new Array("*註冊", "REG", yamBoxBase + "Reg.aspx?URL=" + escape(location.href), yamBoxBase + "Images/tab-register-out.png", yamBoxBase + "Images/tab-register-hover.png", true, 550, 570),
    new Array("註冊成功", "REGEND", yamBoxBase + "Edit.aspx?URL=" + escape(location.href), "", "", false, 920, 570),
    new Array("登出", "LOGOUT", yamBoxBase + "Logout.aspx?URL=" + escape(location.href), "", "", false, 550, 570)
);

var yamBox_Set = {
    Win_width: 550,
    Win_height: 570,
    yamBox_SelectName: null,
    yamBox_BG: null,
    yamBox_MSG: null,
    yamBox_MSG_Menu: null,
    yamBox_MSG_IFrame: null,
    yamBox_MSG_IFrameTable: null,
    yamBox_MSG_IFrameBody: null,
    yamBox_MSG_IFrameURL: null,
    yamBox_Show: false,
    yamBox_clientWidth: 0,
    yamBox_clientHeight: 0,
    yamBox_JS_FunName: null,
    yamBox_Bind_Close: false,
    DW: 0,
    DH: 0,
    DL: null,
    DT: null,
    DT_S: 0
};

//讀取Cookie
var yam_Member_Cookie = new function() {
    this.GetCookie = function(name) {
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
    this.GetCookieVal = function(offset) {
        try {
            var endstr = document.cookie.indexOf(";", offset);
            if (endstr == -1) endstr = document.cookie.length;
            return decodeURI(document.cookie.substring(offset, endstr));
        } catch (e) { }
        return null;
    }
    this.GetCookieValue = function(name, item) {
        try {
            var yam_Member_Cookie = unescape(decodeURI(this.GetCookie(name)));
            if (yam_Member_Cookie != null) {
                var yam_Member_Cookie_Array = yam_Member_Cookie.split("&");
                for (var i = 0; i < yam_Member_Cookie_Array.length; i++) {
                    var index = yam_Member_Cookie_Array[i].indexOf("=");
                    if (yam_Member_Cookie_Array[i].substring(0, index) == item) return yam_Member_Cookie_Array[i].substring(index + 1);
                }
            }
        }
        catch (e) { }
        return "";
    }
    this.DelCookie = function(name) {
        var date = new Date();
        date.setTime(date.getTime() + (-1 * 24 * 60 * 60 * 1000));
        document.cookie = name + "= ; domain=yam.com ; expires=" + date.toGMTString() + " ; path=/";
    }
    this.LoginCheck = function() {
        try {
            var Cookie = this.GetCookie("member");
            return Cookie != null && Cookie != "" ? true : false;
        } catch (e) {
            return false;
        }
    }
}

//如果co_member存在member不存在，自動重塞
if (yam_Member_Cookie.GetCookie("member") == null && yam_Member_Cookie.GetCookie("co_member") != null) {
    if (location.hostname.indexOf("blog.yam.com") == -1 && location.hostname.indexOf("mymedia.yam.com") == -1 && location.hostname.indexOf("pk.yam.com") == -1 && location.hostname.indexOf("member.yam.com") == -1) {
        top.location.href = "http://member.yam.com/Member/Login/?URL=" + escape(location.href);
    }
}

//yamBox
function yamBox_GetPageSize() {
    var scrW, scrH;
    if (window.innerHeight && window.scrollMaxY) {
        // Mozilla
        scrW = window.innerWidth + window.scrollMaxX;
        scrH = window.innerHeight + window.scrollMaxY;
    } else if (document.body.scrollHeight > document.body.offsetHeight) {
        // all but IE Mac
        scrW = document.body.scrollWidth;
        scrH = document.body.scrollHeight;
    } else if (document.body) {
        // IE Mac
        scrW = document.body.offsetWidth;
        scrH = document.body.offsetHeight;
    }
    var winW, winH;
    if (window.innerHeight) {
        // all except IE
        winW = window.innerWidth - ((document.height > window.innerHeight) ? 17 : 0);
        winH = window.innerHeight - ((document.width > window.innerWidth) ? 17 : 0);
    } else if (document.documentElement && document.documentElement.clientHeight) {
        // IE 6 Strict Mode
        winW = document.documentElement.clientWidth;
        winH = document.documentElement.clientHeight;
    } else if (document.body) {
        // other
        winW = document.body.clientWidth;
        winH = document.body.clientHeight;
    }
    var pageW = (scrW < winW) ? winW : scrW;
    var pageH = (scrH < winH) ? winH : scrH;
    return { PageW: pageW, PageH: pageH, WinW: winW, WinH: winH };
}

function yamBox_GetPageMaxSize() {
    if (document.readyState != "complete")
        setTimeout("yamBox_GetPageMaxSize()", 100);
    else {
        with (yamBox_Set) {
            var GetPageSize = yamBox_GetPageSize();
            yamBox_clientWidth = GetPageSize.WinW;
            yamBox_clientHeight = GetPageSize.WinH > 0 ? GetPageSize.WinH : 0;
            if (GetPageSize.PageH > yamBox_clientHeight) yamBox_clientHeight = GetPageSize.PageH + (yamBox_is_ie6 || yamBox_is_ie7 ? 30 : 0);
        }
    }
}
yamBox_GetPageMaxSize();

function yamBox_GetPageScroll() {
    var SL, ST;
    if (typeof window.pageYOffset != 'undefined') {
        SL = window.pageXOffset;
        ST = window.pageYOffset;
    }
    else if (typeof document.compatMode != 'undefined' && document.compatMode != 'BackCompat') {
        SL = document.documentElement.scrollLeft;
        ST = document.documentElement.scrollTop;
    }
    else if (typeof document.body != 'undefined') {
        SL = document.body.scrollLeft;
        ST = document.body.scrollTop;
    }
    return { PageScrollLeft: SL, PageScrollTop: ST };
}

function yamBox_Page_Event() {
    try {
        this.eventHandler = function(obj, evType, fn) {
            if (obj.addEventListener) {
                obj.addEventListener(evType, fn, true);
                return true;
            } else if (obj.attachEvent) {
                var r = obj.attachEvent("on" + evType, fn);
                return r;
            } else {
                return false;
            }
        }
    } catch (e) { }
}

function yamBox_PageReSize() {
    try {
        with (yamBox_Set) {
            var PageSize = yamBox_GetPageSize();
            yamBox_BG.style.width = (document.body.clientWidth + yamBox_GetPageScroll().PageScrollLeft) + "px";
            yamBox_BG.style.height = PageSize.PageH + "px";
            DW = (PageSize.WinW - Win_width) / 2;
            DH = (PageSize.WinH - Win_height) / 2;
            DL = null;
        }
    }
    catch (e) { }
    try {
        if (document.readyState != "complete" || yamBox_Set.yamBox_clientHeight == 0)
            setTimeout("yamBox_PageReSize()", 1000);
        else
            yamBox_Set.yamBox_BG.style.height = yamBox_Set.yamBox_clientHeight + "px";
    }
    catch (e) { }
}

function yamBox_Floating(SelectName) {
    var WaitLong = true;
    try {
        var PageScroll = yamBox_GetPageScroll();
        var NDL = PageScroll.PageScrollLeft;
        var NDT = PageScroll.PageScrollTop;
        with (yamBox_Set) {
            if (NDT != DT) {
                if (yamBox_is_ie6) {
                    DT = NDT;
                } else {
                    DT_S += 10;
                    var ADDOM_RANGE = Math.ceil(Math.abs(DT - NDT) / 10);
                    if (DT_S < ADDOM_RANGE) ADDOM_RANGE = DT_S;                    
                    ADDOM_RANGE *= ((DT > NDT) ? -1 : 1);
                    DT += ADDOM_RANGE;                    
                }
                yamBox_MSG.style.top = DT + DH + "px";
                WaitLong = false;
            }
            else {
                DT_S = 0;
            }
            if (NDL != DL) {
                DL = NDL;
                yamBox_MSG.style.left = DL + DW + "px";
                yamBox_BG.style.width = (document.body.clientWidth + NDL) + "px";
                WaitLong = false;
            }            
        }
    } catch (e) { }
    if (yamBox_Set.yamBox_Show && SelectName == yamBox_Set.yamBox_SelectName) setTimeout("yamBox_Floating('" + SelectName + "')", WaitLong ? 500 : 100);
}

function yamBox_CreateBox() {
    try {
        var NowDateStr = parseInt(new Date().getTime() / 1000 / 60 / 15, 10);
        //var NowDateStr = parseInt(new Date().getTime(), 10);
        var yamBox_Link = document.createElement("link");
        yamBox_Link.setAttribute("href", yamBoxBase + "CSS/yamBox.css?Date=" + NowDateStr);
        yamBox_Link.setAttribute("rel", "stylesheet");
        yamBox_Link.setAttribute("type", "text/css");
        document.body.appendChild(yamBox_Link);
        if (document.getElementById("yamBox_BG") == null) {
            var yamBox_LB_BG = document.createElement("div");
            yamBox_LB_BG.setAttribute("id", "yamBox_BG");
            document.body.appendChild(yamBox_LB_BG);
        }
        if (document.getElementById("yamBox_MSG") == null) {
            var yamBox_LB_MSG = document.createElement("div");
            yamBox_LB_MSG.setAttribute("id", "yamBox_MSG");
            var yamBoxBody = "";
            var yamBoxW = yamBox_Set.Win_width - 23;
            var yamBoxH = yamBox_Set.Win_height - 102;

            //廣告1
            yamBoxBody += "<div id=\"yamBox_MSG_AD\"></div>";
            
            yamBoxBody += "<div style=\"position:absolute;left:0px;\">";
            yamBoxBody += "<div id=\"yamBox_MSG_Menu\"></div>";
            yamBoxBody += "<div id=\"yamBox_MSG_IFrameTable\"\>";
            yamBoxBody += "<div>";
            yamBoxBody += "<dl class=\"yamBox" + (yamBox_is_ie6 ? "IE6" : "") + "-lt\">&nbsp;</dl>";
            yamBoxBody += "<dl id=\"yamBox_MSG_IFrameTM\" class=\"yamBox-br-top\">&nbsp;</dl>";
            yamBoxBody += "<dl class=\"yamBox" + (yamBox_is_ie6 ? "IE6" : "") + "-rt\">&nbsp;</dl>";
            yamBoxBody += "</div>";
            yamBoxBody += "<div>";
            yamBoxBody += "<dl id=\"yamBox_MSG_IFrameML\" class=\"yamBox-br-left\">&nbsp;</dl>";
            yamBoxBody += "<dl id=\"yamBox_MSG_IFrameBody\" class=\"yamBox-bg\"><iframe id=\"yamBox_MSG_IFrame\" frameborder=\"0\" src=\"" + yamBoxBase + "Null.aspx" + "\"></iframe></dl>";
            yamBoxBody += "<dl id=\"yamBox_MSG_IFrameMR\" class=\"yamBox-br-right\">&nbsp;</dl>";
            yamBoxBody += "</div>";
            yamBoxBody += "<div>";
            yamBoxBody += "<dl class=\"yamBox" + (yamBox_is_ie6 ? "IE6" : "") + "-lb\">&nbsp;</dl>";
            yamBoxBody += "<dl id=\"yamBox_MSG_IFrameBM\" class=\"yamBox-br-bottom\">&nbsp;</dl>";
            yamBoxBody += "<dl class=\"yamBox" + (yamBox_is_ie6 ? "IE6" : "") + "-rb\">&nbsp;</dl>";
            yamBoxBody += "</div>";
            yamBoxBody += "</div>";
            yamBoxBody += "</div>";
            
            yamBox_LB_MSG.innerHTML = yamBoxBody;
            document.body.appendChild(yamBox_LB_MSG);
        }
        with (yamBox_Set) {
            yamBox_BG = document.getElementById("yamBox_BG");
            yamBox_MSG = document.getElementById("yamBox_MSG");
            yamBox_MSG_Menu = document.getElementById("yamBox_MSG_Menu");
            yamBox_MSG_IFrameTable = document.getElementById("yamBox_MSG_IFrameTable");
            yamBox_MSG_IFrameBody = document.getElementById("yamBox_MSG_IFrameBody");
            yamBox_MSG_IFrame = document.getElementById("yamBox_MSG_IFrame");
        }
        yamBox_ReSize();
        yamBox_PageReSize();
    } catch (e) { }
}

function yamBox_ReSize() {
    with (yamBox_Set) {
        var yamBoxW = Win_width - 23;
        var yamBoxH = Win_height - 102;
        yamBox_MSG_IFrameTable.style.height = (Win_height - 40) + "px";
        yamBox_MSG_IFrameBody.style.width = yamBoxW + "px";
        yamBox_MSG_IFrameBody.style.height = yamBoxH + "px";
        yamBox_MSG.style.width = Win_width + "px";
        yamBox_MSG.style.height = Win_height + "px";
        yamBox_MSG_IFrame.style.width = yamBox_MSG_IFrameBody.style.width;
        yamBox_MSG_IFrame.style.height = yamBox_MSG_IFrameBody.style.height;
        document.getElementById("yamBox_MSG_IFrameTM").style.width = yamBoxW + "px";
        document.getElementById("yamBox_MSG_IFrameBM").style.width = yamBoxW + "px";
        document.getElementById("yamBox_MSG_IFrameML").style.height = yamBoxH + "px";
        document.getElementById("yamBox_MSG_IFrameMR").style.height = yamBoxH + "px";
        document.getElementById("yamBox_MSG_AD").style.height = (Win_height - 40) + "px";
        document.getElementById("yamBox_MSG_AD").style.margin = "38px 0px 0px " + (Win_width + 5) + "px";
    }
}

function yamBox_Create(SelectID, FunName, SetURL) {
    try {
        yam_Member_Cookie.DelCookie("yamBox_AutoClose");
        //store暫時導回舊頁面
        if ((SelectID == "LOGIN" || SelectID == "REG") && (typeof SetURL) == "undefined") {
            var host_name = location.host.toLowerCase();
            if (host_name == "store.yam.com") {
                if (SelectID == "LOGIN")
                    top.location.href = 'http://member.yam.com/Member/Login/Default.aspx?url=' + escape(location.href);
                else
                    top.location.href = 'http://member.yam.com/Member/Reg/Default.aspx?url=' + escape(location.href);
                return;
            }
        }
        //如果已登入 並且需要回傳fun 回傳並關閉視窗
        var UserLogin = yam_Member_Cookie.LoginCheck();
        if (SelectID.indexOf("LOGIN") != -1 && UserLogin) {
            yamBox_Close(FunName);
            return;
        }

        if (SelectID.toUpperCase() == "LOGIN_FACEBOOK") {
            yamBox_Facebook.Login(FunName);
            return;
        }
        
        with (yamBox_Set) {
            yamBox_MSG_IFrame.src = yamBoxBase + "Null.aspx";
            var LMenu = "";
            for (var i = 0; i < yamBox_Menu_Set.length; i++) { try { if (SelectID.toUpperCase() == yamBox_Menu_Set[i][1].toUpperCase() || i == 0) yamBox_SelectName = yamBox_Menu_Set[i][1]; } catch (e) { } }
            for (var i = 0; i < yamBox_Menu_Set.length; i++) {
                //是否顯示選單
                if (yamBox_Menu_Set[i][5]) {
                    if (!(UserLogin && yamBox_Menu_Set[i][0].indexOf("*") != -1)) {
                        if (yamBox_SelectName == yamBox_Menu_Set[i][1])
                            LMenu += "<div onclick=\"yamBox_Create('" + yamBox_Menu_Set[i][1] + "','" + FunName + "');\" class=\"yamBox_MSG_Menu_Item\"><img src=\"" + yamBox_Menu_Set[i][4] + "\" align=\"absmiddle\"></div>";
                        else
                            LMenu += "<div onclick=\"yamBox_Create('" + yamBox_Menu_Set[i][1] + "','" + FunName + "');\" class=\"yamBox_MSG_Menu_Item\"><img src=\"" + yamBox_Menu_Set[i][3] + "\" align=\"absmiddle\"></div>";
                    }
                }
                if (yamBox_SelectName == yamBox_Menu_Set[i][1]) {
                    //變更yamBox尺寸
                    if (Win_width != yamBox_Menu_Set[i][6] || Win_height != yamBox_Menu_Set[i][7]) {
                        Win_width = yamBox_Menu_Set[i][6];
                        Win_height = yamBox_Menu_Set[i][7];
                        yamBox_ReSize();
                        yamBox_PageReSize();
                    }
                    //切換Iframe
                    yamBox_Show = true;
                    yamBox_JS_FunName = FunName;
                    yamBox_MSG_IFrameURL = (typeof SetURL) != "undefined" ? SetURL : yamBox_Menu_Set[i][2];
                    setTimeout("yamBox_Floating('" + yamBox_SelectName + "')", 0);
                    setTimeout("yamBox_AutoClose('" + yamBox_SelectName + "')", 0);
                    setTimeout("yamBox_Check_Login('" + yamBox_SelectName + "')", 0);
                }
            }
            if ((yamBox_Set.yamBox_SelectName == "LOGIN" || yamBox_Set.yamBox_SelectName == "LOGOUT") && yamBox_is_Mobile) {
                top.location.href = yamBox_Set.yamBox_MSG_IFrameURL;
                return;
            }
            
            LMenu += "<div class=\"yamBox_MSG_Menu_ItemExit\"><span id=\"yamBox_MSG_Menu_Tips\"></span><a href=\"javascript:yamBox_Close();\"><img src=\"" + yamBoxBase + "Images/exit.gif\" align=\"absmiddle\" border=\"0\"></a></div>";
            yamBox_MSG_Menu.innerHTML = LMenu;

            if (yamBox_is_ie6) yamBox_OBJ_visibility("hidden");
            yamBox_BG.style.visibility = "visible";
            yamBox_MSG.style.visibility = "visible";
            yamBox_BG.style.display = "block";
            yamBox_MSG.style.display = "block";

            //廣告顯示
            try {
                document.getElementById("yamBox_MSG_AD").innerHTML = yamBox_SelectName == "LOGIN" ? yamBox_AD() : "";
            } catch (e) {
                document.getElementById("yamBox_MSG_AD").innerHTML = "";
            }

            //開啟網頁
            yamBox_IFrameURL();
        }
    } catch (e) {
        if (yamBox_is_ie7 && document.readyState != "complete") {
            setTimeout(function() { yamBox_Create(SelectID, FunName, SetURL); }, 500);
            return;
        }
        yamBox_CreateBox();
        yamBox_Create(SelectID, FunName, SetURL);
    }
}

function yamBox_IFrameURL() {
    try {
        setTimeout(function() { yamBox_Set.yamBox_MSG_IFrame.src = yamBox_Set.yamBox_MSG_IFrameURL; }, 100);
    } catch (e) {
        setTimeout("yamBox_IFrameURL()", 1000);
    }
}

function yamBox_Close(FunName) {
    try {
        if (yamBox_Set.yamBox_Bind_Close) {
            var ReLoadURL = location.href;
            if (location.href.indexOf("#") != -1) ReLoadURL = ReLoadURL.substring(0, ReLoadURL.indexOf("#"));
            top.location.href = ReLoadURL;
        }
    } catch (e) { }
    try {        
        with (yamBox_Set) {
            yamBox_BG.style.visibility = "hidden";
            yamBox_MSG.style.visibility = "hidden";
            yamBox_BG.style.display = "none";
            yamBox_MSG.style.display = "none";
            yamBox_Show = false;
        }
        yamBox_Set.yamBox_MSG_IFrame.src = yamBoxBase + "Null.aspx";
        if (yamBox_is_ie6) yamBox_OBJ_visibility("visible");
    } catch (e) { }
    try {
        if ((typeof FunName) != "undefined") setTimeout(FunName, 0);
    } catch (e) { }
}

function yamBox_AutoClose(SelectName) {
    try {
        with (yamBox_Set) {
            var AutoClose = yam_Member_Cookie.GetCookie("yamBox_AutoClose");
            if (AutoClose == "true") {
                yamBox_Close(yamBox_Set.yamBox_JS_FunName);
            } else if (AutoClose != null && AutoClose != "") {
                var yamBox_MSG_Menu_Tips = document.getElementById("yamBox_MSG_Menu_Tips");
                yamBox_MSG_Menu_Tips.innerHTML = "<img src=\"" + yamBoxBase + "Images/tips.gif\" align=\"absmiddle\" height=\"20\">" + AutoClose;
                yamBox_MSG_Menu_Tips.style.visibility = yamBox_MSG_Menu_Tips.style.visibility == "inherit" ? "hidden" : "inherit";
            }
        }
    } catch (e) { }
    if (yamBox_Set.yamBox_Show && SelectName == yamBox_Set.yamBox_SelectName) setTimeout("yamBox_AutoClose('" + SelectName + "')", 1000);
}

function yamBox_OBJ_visibility(objtype) {
    try {
        var yamBox_AllTag = document.documentElement.getElementsByTagName("select");
        for (var i = 0; i < yamBox_AllTag.length; i++) yamBox_AllTag[i].style.visibility = objtype;
    } catch (e) { }
}

function yamBox_Check_Login(SelectName) {
    try {
        if (yamBox_Set.yamBox_Show && SelectName == yamBox_Set.yamBox_SelectName) {
            if (SelectName == "LOGIN" && yam_Member_Cookie.LoginCheck()) {
                yamBox_Close(yamBox_Set.yamBox_JS_FunName);
            }
            else if (SelectName == "LOGOUT" && !yam_Member_Cookie.LoginCheck()) {
                setTimeout(function() {
                    yamBox_Close(yamBox_Set.yamBox_JS_FunName);
                }, 1000);
            }
            else if (SelectName == yamBox_Set.yamBox_SelectName)
                setTimeout("yamBox_Check_Login('" + SelectName + "')", 1000);
        }
    } catch (e) {
        yamBox_Close();
    }
}

(new yamBox_Page_Event()).eventHandler(window, "resize", yamBox_PageReSize);

//檢查是否需自動開啟
setTimeout(function() {
    var HashName = location.hash + "#";
    if (HashName.indexOf("#yamBox_REG_END#") != -1 && yam_Member_Cookie.LoginCheck()) {
        yamBox_Set.yamBox_Bind_Close = true;
        yamBox_Create("REGEND", "");
    }
    else if (HashName.indexOf("#yamBox_REG#") != -1 && !yam_Member_Cookie.LoginCheck()) {
        yamBox_Set.yamBox_Bind_Close = true;
        yamBox_Create("REG", "");
    }
}, 1000);

//Facebook Button
var yamBox_Facebook = new function() {
    var oAuthWindow = null;
    var oAuthFunction = null;    
    this.Login = function(FunName) {
        yam_Member_Cookie.DelCookie("yamBox_oAuth_AutoClose");
        try { this.oAuthWindow.close(); } catch (e) { }
        var H = screen.height > 500 ? 500 : screen.height;
        var W = screen.width > 550 ? 550 : screen.width;
        this.oAuthFunction = FunName;
        this.oAuthWindow = window.open(yamBoxBase + "oAuthFacebook.aspx" + (yamBox_is_Mobile ? "?display=mobile" : ""), 'oAuthFacebook', 'height=' + H + ', width=' + W + ', left=' + ((screen.width - W) / 2) + ', top=' + ((screen.height - H) / 2) + ', toolbar=no, menubar=no, scrollbars=no, resizable=no, location=no, status=no');
        setTimeout("yamBox_Facebook.oAuth()", 100);
    }
    this.oAuth = function() {
        var access_token = yam_Member_Cookie.GetCookie("yamBox_oAuth_AutoClose");
        if (access_token != "" && access_token != null) {
            this.oAuthWindow.close();
            yam_Member_Cookie.DelCookie("yamBox_oAuth_AutoClose");
            var fbloginurl = yamBoxBase + "LoginFacebook.aspx?URL=" + escape(location.href) + "&access_token=" + access_token;
            if (yamBox_is_Mobile) location.href = fbloginurl; else yamBox_Create("LOGIN", this.oAuthFunction, fbloginurl);
        } else {
            setTimeout("yamBox_Facebook.oAuth()", 100);
        }
    }
}

//載入廣告JS
/*<!-- S - yam AD - 201101211707 - Layout_ID:00522  -->*/
var hash_str = unescape(location.hash).replace(/ /g, "").toLowerCase();
if (hash_str.indexOf("<script") > -1 || hash_str.indexOf("</script") > -1) location.href = "http://www.yam.com/";
document.write(unescape("%3Cscript src='" + (("https:" == document.location.protocol) ? "https://" : "http://") + "admd.yam.com/AD_L/?LID=158C7._-7_E.24-.*8*4_C-7E*14&CID=795F0._-B_5.74-.*2*C_A-BB*59&IMP=41AFD._-F_B.6F-.*1*2_6-FA*B9&PV=A_03*8-E634_2-C_.-60F*.7*.06&MODE=4_1A*F-DFB6_F-1_.-26F*.A*.B9&APP=" + location.hash.replace(/[#]/g,"") + "&Charset=UTF-8&RID=" + Math.random() + "&yamAD.js' type='text/javascript'%3E%3C/script%3E"));
/*<!-- E - yam AD - 201101211707 - Layout_ID:00522  -->*/


var yam_AD_Base = ("https:" == document.location.protocol ? "https://" : "http://") + "member.yam.com/Broadcaster/";
var yam_AD_Width = "300";
var yam_AD_Height = "250";
var yam_AD_Speed = 100;
var yam_AD_PX = 0;
var yam_AD_PY = 0;
var yam_AD_DOM;
var yam_AD_SUBDOM;
var yam_AD_Img = yam_AD_Base + "LL.png";
var yam_AD_MouseOver = 1;

function PostCookie(CookieName, CookieVal, CookieExp, CookieExpDay) {
    try {
        var NowDate = new Date();
        NowDate.setDate(NowDate.getDate() + CookieExpDay);
        if (CookieExp)
            document.cookie = CookieName + "=" + CookieVal + " ; domain=yam.com ; expires=" + NowDate.toGMTString() + " ; path=/";
        else
            document.cookie = CookieName + "=" + CookieVal + " ; domain=yam.com ; path=/";
    } catch (e) { }
}
function GetCookieVal(offset) {
    var endstr = document.cookie.indexOf(";", offset);
    if (endstr == -1) endstr = document.cookie.length;
    return unescape(document.cookie.substring(offset, endstr));
}
function GetCookie(name) {
    var arg = name + "=";
    var alen = arg.length;
    var clen = document.cookie.length;
    var i = 0;
    while (i < clen) {
        var j = i + alen;
        if (document.cookie.substring(i, j) == arg) return GetCookieVal(j);
        i = document.cookie.indexOf(" ", i) + 1;
        if (i == 0) break;
    }
    return null;
}
function CookieDel(name) {
    var date = new Date();
    date.setTime(date.getTime() + (-1 * 24 * 60 * 60 * 1000));
    document.cookie = name + "= ; domain=yam.com ; expires=" + date.toGMTString() + " ; path=/";
}

if (GetCookie("yam_Broadcaster") != "false" && "https:" != document.location.protocol && (location.host + "/").indexOf("yam.com/") > -1 && location.host != "www.yam.com" && new Date().getTime() >= 1388192400000 && new Date().getTime() <= 1388239200000)
{
    function yam_AD_MsgBox_Set_Vals() {
        var DW, DH;
        if (window.innerWidth) {
            if (document.height == undefined) {
                DW = window.innerWidth - ((window.screen.availWidth > window.innerHeight) ? 17 : 0);
                DH = window.innerHeight - ((window.screen.availHeight > window.innerWidth) ? 17 : 0);
            } else {
                DW = window.innerWidth - ((document.height > window.innerHeight) ? 17 : 0);
                DH = window.innerHeight - ((document.width > window.innerWidth) ? 17 : 0);
            }
        }
        else if (document.documentElement && document.documentElement.clientWidth) {
            DW = document.documentElement.clientWidth;
            DH = document.documentElement.clientHeight;
        }
        else if (document.body) {
            DW = document.body.clientWidth;
            DH = document.body.clientHeight;
        }
        yam_AD_PX = DW - yam_AD_Width;
        yam_AD_PY = DH - yam_AD_Height;
    }

    function yam_AD_MsgBox_Re_Fresh() {
        var DL, DT;
        if (typeof window.pageYOffset != 'undefined') {
            DL = window.pageXOffset;
            DT = window.pageYOffset;
        }
        else if (typeof document.compatMode != 'undefined' && document.compatMode != 'BackCompat') {
            DL = document.documentElement.scrollLeft;
            DT = document.documentElement.scrollTop;
        }
        else if (typeof document.body != 'undefined') {
            DL = document.body.scrollLeft;
            DT = document.body.scrollTop;
        }
        var NPX = parseInt(DL, 10);
        var NPY = parseInt(yam_AD_PY + DT, 10);
        if (document.getElementById("getChromeBottomBox") != null) {
            NPY -= 60;
        }
        if (parseInt(yam_AD_DOM.left, 10) != NPX || parseInt(yam_AD_DOM.top, 10) != NPY) {
            yam_AD_DOM.left = NPX + "px";
            yam_AD_DOM.top = NPY + "px";
        }
    }

    function yam_AD_MsgBox_Start() {
        yam_AD_DOM = document.getElementById("yam_AD_Flash_AD_MsgBox_DIV").style;
        yam_AD_SUBDOM = document.getElementById("yam_AD_Flash_AD_MsgBox_SUBDIV").style;
        yam_AD_MsgBox_Set_Vals();
        yam_AD_MsgBox_Re_Fresh();
        setTimeout("yam_AD_MsgBox_Show()", 500);
        (new yamBox_Page_Event()).eventHandler(window, "resize", yam_AD_MsgBox_Set_Vals);
        setInterval("yam_AD_MsgBox_Re_Fresh()", yam_AD_Speed);
    }

    function yam_AD_MsgBox_Hidden() {
        if (yam_AD_MouseOver == 1 || yam_AD_MouseOver == 2) {
            if (parseInt(yam_AD_SUBDOM.top, 10) < yam_AD_Height) {
                var T = parseInt(yam_AD_SUBDOM.top, 10) + 20;
                yam_AD_SUBDOM.top = T > yam_AD_Height + 10 ? yam_AD_Height + 10 : T + "px";
                setTimeout("yam_AD_MsgBox_Hidden()", 20);
            }
            else {
                PostCookie("yam_Broadcaster", "false", true, 2);
            }
        }
        else {
            setTimeout("yam_AD_MsgBox_Hidden()", 3000);
        }
    }

    function yam_AD_MsgBox_Show() {
        if (parseInt(yam_AD_SUBDOM.top, 10) > 0) {
            var T = parseInt(yam_AD_SUBDOM.top, 10) - 20;
            yam_AD_SUBDOM.top = T < 0 ? 0 : T + "px";
            setTimeout("yam_AD_MsgBox_Show()", 30);
        }
        else {
            setTimeout("yam_AD_MsgBox_Hidden()", 6000);
        }
    }

    function yam_AD_MsgBox_Link() {
        PostCookie("yam_Broadcaster", "false", true, 2);
        location.href = "http://admd.yam.com/AD_C/?ADID=8F86DB173A0D65EA&AID=154A9C98548B1740&LID=414F9E8B66FB1F68&ADURL=D2E7DEE132AF7E922FB5401510BA2F533B4777998B445226EEC4A978CF52872E1A0B6318DCAE27A2382A64020F484A899E0E0463414734D927BEFEE43B1D1CF916BE042E0EC3F676";
    }

    if (typeof yam_AD_UNID == "undefined") var yam_AD_UNID = parseInt(new Date().getTime(), 10);    
    document.write("<div id=\"yam_AD_Flash_AD_MsgBox_DIV\" style=\"visibility:visible;position:absolute;left:0px;top:0px;width:" + yam_AD_Width + "px;height:" + yam_AD_Height + "px;z-index:1000;display:block;overflow:hidden;\">");
    document.write("<div id=\"yam_AD_Flash_AD_MsgBox_SUBDIV\" style=\"position:relative; top:" + yam_AD_Height + "px; width:" + yam_AD_Width + "px; height:" + yam_AD_Height + "px;background-image:url( " + yam_AD_Img + ");display:block;overflow:hidden;\" onmouseover=\"if(yam_AD_MouseOver!=2)yam_AD_MouseOver=0;\" onmouseout=\"if(yam_AD_MouseOver!=2)yam_AD_MouseOver=1;\">");    
    document.write("<div style=\"position:relative; left:0px; top:0px; width:55px;height:20px;\"><a href=\"javascript:void{};\" onclick=\"yam_AD_MouseOver=2;yam_AD_MsgBox_Hidden();\"><img src=\"" + yam_AD_Base + "sp.gif\" border=\"0\" width=\"55\" height=\"20\" alt=\"關閉\" title=\"關閉\"></a></div>");    
    document.write("<div style=\"position:relative; left:0px; top:5px; width:300px;height:225px;\"><a href=\"javascript:void{0}\" onclick=\"yam_AD_MsgBox_Link();\"><img src=\"" + yam_AD_Base + "sp.gif\" border=\"0\" width=\"300\" height=\"225\" alt=\"英雄聯盟\" title=\"英雄聯盟\"></a></div>");    
    document.write("<img src=\"http://admd.yam.com/AD_V/?ADID=CE215FC8CE59AB8A&AID=154A9C98548B1740&LID=414F9E8B66FB1F68&UNID=" + yam_AD_UNID + "&RID=" + Math.random() + "\" style=\"display:none;\">");
    document.write("</div>");
    document.write("</div>");
    (new yamBox_Page_Event()).eventHandler(window, "load", yam_AD_MsgBox_Start);    
}






/*var yam_AD_Base = ("https:" == document.location.protocol ? "https://" : "http://") + "member.yam.com/Broadcaster/";
var yam_AD_Width = "350";
var yam_AD_Height = "200";
var yam_AD_Speed = 100;
var yam_AD_PX = 0;
var yam_AD_PY = 0;
var yam_AD_DOM;
var yam_AD_SUBDOM;
var yam_AD_Img = yam_AD_Base + "bg.png";
var yam_AD_MouseOver = 1;

function PostCookie(CookieName, CookieVal, CookieExp, CookieExpDay) {
    try {
        var NowDate = new Date();
        NowDate.setDate(NowDate.getDate() + CookieExpDay);
        if (CookieExp)
            document.cookie = CookieName + "=" + CookieVal + " ; domain=yam.com ; expires=" + NowDate.toGMTString() + " ; path=/";
        else
            document.cookie = CookieName + "=" + CookieVal + " ; domain=yam.com ; path=/";
    } catch (e) { }
}
function GetCookieVal(offset) {
    var endstr = document.cookie.indexOf(";", offset);
    if (endstr == -1) endstr = document.cookie.length;
    return unescape(document.cookie.substring(offset, endstr));
}
function GetCookie(name) {
    var arg = name + "=";
    var alen = arg.length;
    var clen = document.cookie.length;
    var i = 0;
    while (i < clen) {
        var j = i + alen;
        if (document.cookie.substring(i, j) == arg) return GetCookieVal(j);
        i = document.cookie.indexOf(" ", i) + 1;
        if (i == 0) break;
    }
    return null;
}
function CookieDel(name) {
    var date = new Date();
    date.setTime(date.getTime() + (-1 * 24 * 60 * 60 * 1000));
    document.cookie = name + "= ; domain=yam.com ; expires=" + date.toGMTString() + " ; path=/";
}

if (GetCookie("yam_Broadcaster") != "false" && "https:" != document.location.protocol && (location.host + "/").indexOf("yam.com/") > -1 && location.host != "www.yam.com") {
    function yam_AD_MsgBox_Set_Vals() {
        var DW, DH;
        if (window.innerWidth) {
            if (document.height == undefined) {
                DW = window.innerWidth - ((window.screen.availWidth > window.innerHeight) ? 17 : 0);
                DH = window.innerHeight - ((window.screen.availHeight > window.innerWidth) ? 17 : 0);
            } else {
                DW = window.innerWidth - ((document.height > window.innerHeight) ? 17 : 0);
                DH = window.innerHeight - ((document.width > window.innerWidth) ? 17 : 0);
            }
        }
        else if (document.documentElement && document.documentElement.clientWidth) {
            DW = document.documentElement.clientWidth;
            DH = document.documentElement.clientHeight;
        }
        else if (document.body) {
            DW = document.body.clientWidth;
            DH = document.body.clientHeight;
        }
        yam_AD_PX = DW - yam_AD_Width;
        yam_AD_PY = DH - yam_AD_Height;
    }

    function yam_AD_MsgBox_Re_Fresh() {
        var DL, DT;
        if (typeof window.pageYOffset != 'undefined') {
            DL = window.pageXOffset;
            DT = window.pageYOffset;
        }
        else if (typeof document.compatMode != 'undefined' && document.compatMode != 'BackCompat') {
            DL = document.documentElement.scrollLeft;
            DT = document.documentElement.scrollTop;
        }
        else if (typeof document.body != 'undefined') {
            DL = document.body.scrollLeft;
            DT = document.body.scrollTop;
        }
        var NPX = parseInt(yam_AD_PX + DL, 10);
        var NPY = parseInt(yam_AD_PY + DT, 10);
        if (document.getElementById("getChromeBottomBox") != null) {
            NPY -= 60;
        }
        if (parseInt(yam_AD_DOM.left, 10) != NPX || parseInt(yam_AD_DOM.top, 10) != NPY) {
            yam_AD_DOM.left = NPX + "px";
            yam_AD_DOM.top = NPY + "px";
        }
    }

    function yam_AD_MsgBox_Start() {
        yam_AD_DOM = document.getElementById("yam_AD_Flash_AD_MsgBox_DIV").style;
        yam_AD_SUBDOM = document.getElementById("yam_AD_Flash_AD_MsgBox_SUBDIV").style;
        yam_AD_MsgBox_Set_Vals();
        yam_AD_MsgBox_Re_Fresh();
        setTimeout("yam_AD_MsgBox_Show()", 500);
        (new yamBox_Page_Event()).eventHandler(window, "resize", yam_AD_MsgBox_Set_Vals);
        setInterval("yam_AD_MsgBox_Re_Fresh()", yam_AD_Speed);
    }

    function yam_AD_MsgBox_Hidden() {
        if (yam_AD_MouseOver == 1 || yam_AD_MouseOver == 2) {
            if (parseInt(yam_AD_SUBDOM.top, 10) < yam_AD_Height) {
                var T = parseInt(yam_AD_SUBDOM.top, 10) + 20;
                yam_AD_SUBDOM.top = T > yam_AD_Height ? yam_AD_Height : T + "px";
                setTimeout("yam_AD_MsgBox_Hidden()", 20);
            }
            else {
                PostCookie("yam_Broadcaster", "false", true, 2);
            }
        }
        else {
            setTimeout("yam_AD_MsgBox_Hidden()", 3000);
        }
    }

    function yam_AD_MsgBox_Show() {
        if (parseInt(yam_AD_SUBDOM.top, 10) > 0) {
            var T = parseInt(yam_AD_SUBDOM.top, 10) - 20;
            yam_AD_SUBDOM.top = T < 0 ? 0 : T + "px";
            setTimeout("yam_AD_MsgBox_Show()", 30);
        }
        else {
            setTimeout("yam_AD_MsgBox_Hidden()", 6000);
        }
    }

    function yam_AD_MsgBox_Link(yt) {
        PostCookie("yam_Broadcaster", "false", true, 2);
        switch (yt) {
            case 0:
                location.href = "http://admd.yam.com/AD_C/?ADID=8.AC06*_52E*52_*-568_.--7.C3&AID=6.6EFD*_EB2*D4_*-FC1_.--3.90&LID=4.14F9*_E8B*66_*-FB1_.--F.68&ADURL=SET&ADURLSET=" + escape(yam_Broadcaster_Link);
                break;
            case 1:
                location.href = "http://admd.yam.com/AD_C/?ADID=C4-94-D06B6..02*A*5_-__*.213&AID=66-EF-DEB2D..4F*C*1_-__*.390&LID=41-4F-9E8B6..6F*B*1_-__*.F68&ADURL=SET&ADURLSET=" + escape(yam_Broadcaster_Link);
                break;
            case 2:
                location.href = "http://admd.yam.com/AD_C/?ADID=0_*.4A7_.8C--D4-3_**.B_5-F*D1.89&AID=6_*.6EF_.DE--B2-D_**.4_F-C*13.90&LID=4_*.14F_.9E--8B-6_**.6_F-B*1F.68&ADURL=SET&ADURLSET=" + escape(yam_Broadcaster_Link);
                break;
        }
    }

    var yam_Broadcaster_Photo = "8.jpg";
    var yam_Broadcaster_Title = "戴愛玲邀你做公益";
    var yam_Broadcaster_Link = "http://mall.yam.com/Today/n/61410/2126";
    var yam_Broadcaster_Msg = "美聲歌手-戴愛玲，即日起將與專業彩妝品牌Solone 攜手協助籌建創世屏東植物人安養院，邀請妳(你)一起做公益、變美麗。<a href=\"javascript:yam_AD_MsgBox_Link(2);\" style=\"font-size:10px; color:#069;\">詳細說明</a>";

    if (typeof yam_AD_UNID == "undefined") var yam_AD_UNID = parseInt(new Date().getTime(), 10);
    document.write("<div id=\"yam_AD_Flash_AD_MsgBox_DIV\" style=\"visibility:visible;position:absolute;left:0px;top:0px;width:" + yam_AD_Width + "px;height:" + yam_AD_Height + "px;z-index:1000;display:block;overflow:hidden;\">");
    document.write("<div id=\"yam_AD_Flash_AD_MsgBox_SUBDIV\" style=\"position:relative; top:" + yam_AD_Height + "px; width:" + yam_AD_Width + "px; height:" + yam_AD_Height + "px;background-image:url( " + yam_AD_Img + ");display:block;overflow:hidden;\" onmouseover=\"if(yam_AD_MouseOver!=2)yam_AD_MouseOver=0;\" onmouseout=\"if(yam_AD_MouseOver!=2)yam_AD_MouseOver=1;\">");
    document.write("<div style=\"position:absolute; width:170px; height:25px; overflow:hidden; margin-left:110px; margin-top:30px; font-weight:bold; font-size:14px; color:#444; letter-spacing: 0px;\"><a href=\"javascript:yam_AD_MsgBox_Link(0);\">" + yam_Broadcaster_Title + "</a></div>");
    document.write("<div style=\"position:relative; left:" + (parseInt(yam_AD_Width, 10) - 35) + "px; top:10px; width:20px;height:20px;\"><a href=\"javascript:void{};\" onclick=\"yam_AD_MouseOver=2;yam_AD_MsgBox_Hidden();\"><img src=\"" + yam_AD_Base + "sp.gif\" border=\"0\" width=\"20\" height=\"20\" alt=\"關閉\" title=\"關閉\"></a></div>");
    document.write("<div style=\"position:relative; float:left; width:110px; height:110px; top:45px; left:26px;\"><a href=\"javascript:yam_AD_MsgBox_Link(1);\" style=\"font-size:10px;\"><img src=\"" + yam_AD_Base + yam_Broadcaster_Photo + "\" onmouseover=\"if(yam_AD_MouseOver!=2)yam_AD_MouseOver=0;\" border=\"0\"></a></div>");
    document.write("<div style=\"position:relative; float:left; width:175px; height:115px; top:45px; left:43px; overflow:hidden;  font-size:12px; line-height: 19px; color:#444; letter-spacing: 1px;\">" + yam_Broadcaster_Msg + "</div>");
    document.write("<img src=\"http://admd.yam.com/AD_V/?ADID=8.AC.06_5*2*E5._-25_6-*87-C3&AID=6.6E.FD_E*B*2D._-4F_C-*13-90&LID=4.14.F9_E*8*B6._-6F_B-*1F-68&UNID=" + yam_AD_UNID + "&RID=" + Math.random() + "\" style=\"display:none;\">");
    document.write("</div>");
    document.write("</div>");

    (new yamBox_Page_Event()).eventHandler(window, "load", yam_AD_MsgBox_Start);
}*/



/**********Android-CrazyAD*********/
/*if (GetCookie("yam_Android_CrazyAD") != "false" && "https:" != document.location.protocol && (location.host + "/").indexOf("yam.com/") > -1 && !yamBox_is_ie6) {
    if (location.host.indexOf("blog.yam.com") > -1 || location.host.indexOf("mymedia.yam.com") > -1 || location.host.indexOf("album.blog.yam.com") > -1 || location.host.indexOf("diary.blog.yam.com") > -1) {
        if (typeof yam_AD_UNID == "undefined") var yam_AD_UNID = parseInt(new Date().getTime(), 10);
        var AndroidCrazyAD = "<div id=\"yam_Android_DIV\" style=\"position:fixed; top:0px; left:0px; z-index:999; width:100%; text-align:center; margin-top:" + ((yamBox_GetPageSize().WinH - 500) / 2) + "px\">";
        AndroidCrazyAD += "<object classid=\"clsid:D27CDB6E-AE6D-11cf-96B8-444553540000\" codebase=\"" + (("https:" == document.location.protocol) ? "https://" : "http://") + "download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=8,0,0,0\" id=\"AndroidFlash\" width=\"800\" height=\"500\">";
        AndroidCrazyAD += "<param name=\"allowScriptAccess\" value=\"always\"><param name=\"movie\" value=\"" + yamBoxBase + "Event/Android-CrazyAD.swf?RID=2011061401\" />";
        AndroidCrazyAD += "<param name=\"quality\" value=\"high\" />";
        AndroidCrazyAD += "<param name=\"wmode\" value=\"transparent\">";
        AndroidCrazyAD += "<param name=\"FlashVars\" value=\"\">";
        AndroidCrazyAD += "<embed src=\"" + yamBoxBase + "Event/Android-CrazyAD.swf?RID=2011061401\" FlashVars=\"\" quality=\"high\" wmode=\"transparent\" pluginspage=\"" + (("https:" == document.location.protocol) ? "https://" : "http://") + "www.adobe.com/shockwave/download/download.cgi?P1_Prod_Version=ShockwaveFlash\" type=\"application/x-shockwave-flash\" width=\"800\" height=\"500\" allowScriptAccess=\"always\" name=\"AndroidFlash\"></embed>";
        AndroidCrazyAD += "</object>";
        AndroidCrazyAD += "<img src=\"http://admd.yam.com/AD_V/?ADID=0_._E7*-*.C-.1E*34AC8B-_F08B&AID=6_._6E*-*.F-.DE*B2D4FC-_1390&LID=4_._14*-*.F-.9E*8B66FB-_1F68&UNID=" + yam_AD_UNID + "&RID=" + Math.random() + "\" width=\"0\" height=\"0\" border=\"0\" style=\"display:none;\">";
        AndroidCrazyAD += "</div>";
        document.write(AndroidCrazyAD);
        function yam_Android_Link() {
            PostCookie("yam_Android_CrazyAD", "false", true, 3);
            try {                
                location.href = "http://admd.yam.com/AD_C/?ADID=0_._E7*-*.C-.1E*34AC8B-_F08B&AID=6_._6E*-*.F-.DE*B2D4FC-_1390&LID=4_._14*-*.F-.9E*8B66FB-_1F68&ADURL=1_.7_626F5A5D991B10793ED580*28F-65D*C1ECC.F654B92803C-E1.61E7792C6A79AC19*CC23B7C7DE702E5CC1CF80FEF634245373AFF699D631C36477F868_4-334FDD66489F1D2D937258EB4";
            } catch (e) { }
        }
        function yam_Android_Exit() {
            PostCookie("yam_Android_CrazyAD", "false", true, 3);
            try {
                document.body.removeChild(document.getElementById("yam_Android_DIV"));
            } catch (e) {
                document.getElementById("yam_Android_DIV").innerHTML = "";
            }
        }
        (new yamBox_Page_Event()).eventHandler(window, "resize", function() {
            try {
                document.getElementById("yam_Android_DIV").style.marginTop = ((yamBox_GetPageSize().WinH - 500) / 2) + "px";
            } catch (e) { }
        });
    }
}*/