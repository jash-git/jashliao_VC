function getCookieVal(offset) {
    var endstr = document.cookie.indexOf(";", offset);
    if (endstr == -1)
        endstr = document.cookie.length;
    return unescape(document.cookie.substring(offset, endstr));
}
function getCookie(name) {
    var arg = name + "=";
    var alen = arg.length;
    var clen = document.cookie.length;
    var i = 0;
    while (i < clen) {
        var j = i + alen;
        if (document.cookie.substring(i, j) == arg)
            return getCookieVal(j);
        i = document.cookie.indexOf(" ", i) + 1;
        if (i == 0) break;
    }
    return null;
}
function setCookie(name, value) {
    var argv = setCookie.arguments;
    var argc = setCookie.arguments.length;
    var expires = (argc > 2) ? argv[2] : null;
    var path = (argc > 3) ? argv[3] : null;
    var domain = (argc > 4) ? argv[4] : null;
    var secure = (argc > 5) ? argv[5] : false;
    document.cookie = name + "=" + escape(value) +
                      ((expires == null) ? "" : ("; expires=" + expires.toGMTString())) +
                      ((path == null) ? "" : ("; path=" + path)) +
                      ((domain == null) ? "" : ("; domain=" + domain)) +
                      ((secure == true) ? "; secure" : "");
}

function deleteCookie(name) {
    var exp = new Date();
    exp.setTime(exp.getTime() - 1);
    var cval = GetCookie(name);
    document.cookie = name + "=" + cval + "; expires=" + exp.toGMTString();
}


function html_trans(str) {
    str = str.replace(/\r/g, "");
    str = str.replace(/on(load|click|dbclick|mouseover|mousedown|mouseup)="[^"]+"/ig, "");
    str = str.replace(/<"+"script[^>]*?>([\w\W]*?)<\/script>/ig, "");
    str = str.replace(/<PARAM NAME="Movie" VALUE="([^"]+)"[^>]*>/ig, "\n[FLASH]$1[/FLASH]\n");
    str = str.replace(/<PARAM NAME="src" VALUE="([^"]+)"[^>]*>/ig, "\n[RM=500,350]$1[/RM]\n");
    str = str.replace(/<PARAM NAME="URl" VALUE="([^"]+)"[^>]*>/ig, "\n[MP=500,350]$1[/MP]\n");
    //	str = str.replace(/<a[^>]+href="([^"]+)"[^>]*>(.*?)<\/a>/ig,"\n[URL=$1]$2[/URL]\n");

    str = str.replace(/<font[^>]+color=([^ >]+)[^>]*>(.*?)<\/font>/ig, "$2");

    str = str.replace(/<img[^>]+src="([^"]+)"[^>]*>/ig, "\n[IMG]$1[/IMG]\n");

    str = str.replace(/<([\/]?)b>/ig, "");
    str = str.replace(/<([\/]?)strong>/ig, "");
    str = str.replace(/<([\/]?)u>/ig, "");
    str = str.replace(/<([\/]?)i>/ig, "");

    str = str.replace(/&nbsp;/g, " ");
    str = str.replace(/&amp;/g, "&");
    str = str.replace(/&quot;/g, "\"");
    str = str.replace(/&lt;/g, "<");
    str = str.replace(/&gt;/g, ">");

    str = str.replace(/<br>/ig, "\n");
    str = str.replace(/<[^>]*?>/g, "");
    str = str.replace(/\[url=([^\]]+)\]\n(\[img\]\1\[\/img\])\n\[\/url\]/g,"$2");
    str = str.replace(/\n+/g, "\n");
    return str;
}
function transUbbCode() {
    var str = "";
    rtf.focus();
    rtf.document.body.innerHTML = "";
    rtf.document.execCommand("paste");
    str = rtf.document.body.innerHTML;
    if (str.length == 0) {
        alert("剪切版不存在超文本数据！");
        return "";
    }
    return html_trans(str);
}


var Quote = 0;
var Bold = 0;
var Italic = 0;
var Underline = 0;
var Code = 0;
var Center = 0;
var Strike = 0;
var Sound = 0;
var Swf = 0;
var Ra = 0;
var Rm = 0;
var Marquee = 0;
var Fly = 0;
var fanzi = 0;
var text_enter_url = "请输入连接网址";
var text_enter_txt = "请输入连接说明";
var text_enter_image = "请输入图片网址";
var text_enter_sound = "请输入声音文件网址";
var text_enter_swf = "请输入FLASH动画网址";
var text_enter_ra = "请输入Real音乐网址";
var text_enter_rm = "请输入Real影片网址";
var text_enter_wmv = "请输入Media影片网址";
var text_enter_wma = "请输入Media音乐网址";
var text_enter_mov = "请输入QuickTime音乐网址";
var text_enter_sw = "请输入shockwave音乐网址";
var text_enter_email = "请输入邮件网址";
var error_no_url = "您必须输入网址";
var error_no_txt = "您必须连接说明";
var error_no_title = "您必须输入首页标题";
var error_no_email = "您必须输入邮件网址";
var error_no_gset = "必须正确按照各式输入！";
var error_no_gtxt = "必须输入文字！";
var text_enter_guang1 = "文字的长度、颜色和边界大小";
var text_enter_guang2 = "要产生效果的文字！";
function commentWrite(NewCode) {
    document.frmReviewPost.contents.value += NewCode;
    document.frmReviewPost.contents.focus();
    return;
}

function AddText(text) {
    if (document.frmReviewPost.contents.createTextRange && document.frmReviewPost.contents.caretPos) {
        var caretPos = document.frmReviewPost.contents.caretPos;
        caretPos.text = caretPos.text.charAt(caretPos.text.length - 1) == ' ' ?
                        text + ' ' : text;
    }
    else document.frmReviewPost.contents.value += text;
    document.frmReviewPost.contents.focus(caretPos);
}
function inputs(str)
{
    AddText(str);
}
function Curl() {
    var FoundErrors = '';
    var enterURL = prompt(text_enter_url, "http://");
    var enterTxT = prompt(text_enter_txt, enterURL);
    if (!enterURL) {
        FoundErrors += "\n" + error_no_url;
    }
    if (!enterTxT) {
        FoundErrors += "\n" + error_no_txt;
    }
    if (FoundErrors) {
        alert("错误！" + FoundErrors);
        return;
    }
    var ToAdd = "[URL=" + enterURL + "]" + enterTxT + "[/URL]";
    document.frmReviewPost.contents.value += ToAdd;
    document.frmReviewPost.contents.focus();
}
function Cimage() {
    var FoundErrors = '';
    var enterURL = prompt(text_enter_image, "http://");
    if (!enterURL) {
        FoundErrors += "\n" + error_no_url;
    }
    if (FoundErrors) {
        alert("错误！" + FoundErrors);
        return;
    }
    var ToAdd = "[IMG]" + enterURL + "[/IMG]";
    document.frmReviewPost.contents.value += ToAdd;
    document.frmReviewPost.contents.focus();
}
function Cemail() {
    var emailAddress = prompt(text_enter_email, "");
    if (!emailAddress) {
        alert(error_no_email);
        return;
    }
    var ToAdd = "[EMAIL]" + emailAddress + "[/EMAIL]";
    commentWrite(ToAdd);
}

function Cbold() {
    fontbegin = "[B]";
    fontend = "[/B]";
    fontchuli();
}
function Citalic() {
    fontbegin = "[I]";
    fontend = "[/I]";
    fontchuli();
}
function Cunder() {
    fontbegin = "[U]";
    fontend = "[/U]";
    fontchuli();
}
function Ccenter() {
    fontbegin = "[center]";
    fontend = "[/center]";
    fontchuli();
}
function Cstrike() {
    fontbegin = "[strike]";
    fontend = "[/strike]";
    fontchuli();
}
function Csound() {
    var FoundErrors = '';
    var enterURL = prompt(text_enter_sound, "http://");
    if (!enterURL) {
        FoundErrors += "\n" + error_no_url;
    }
    if (FoundErrors) {
        alert("错误！" + FoundErrors);
        return;
    }
    var ToAdd = "[SOUND]" + enterURL + "[/SOUND]";
    document.frmReviewPost.contents.value += ToAdd;
    document.frmReviewPost.contents.focus();
}

function Cswf() {
    var FoundErrors = '';
    var enterURL = prompt(text_enter_swf, "http://");
    if (!enterURL) {
        FoundErrors += "\n" + error_no_url;
    }
    if (FoundErrors) {
        alert("错误！" + FoundErrors);
        return;
    }
    var ToAdd = "[FLASH]" + enterURL + "[/FLASH]";
    document.frmReviewPost.contents.value += ToAdd;
    document.frmReviewPost.contents.focus();
}
function Cra() {
    var FoundErrors = '';
    var enterURL = prompt(text_enter_ra, "http://");
    if (!enterURL) {
        FoundErrors += "\n" + error_no_url;
    }
    if (FoundErrors) {
        alert("错误！" + FoundErrors);
        return;
    }
    var ToAdd = "[RA]" + enterURL + "[/RA]";
    document.frmReviewPost.contents.value += ToAdd;
    document.frmReviewPost.contents.focus();
}
function Crm() {
    var FoundErrors = '';
    var enterURL = prompt(text_enter_rm, "http://");
    if (!enterURL) {
        FoundErrors += "\n" + error_no_url;
    }
    if (FoundErrors) {
        alert("错误！" + FoundErrors);
        return;
    }
    var ToAdd = "[RM=500,350]" + enterURL + "[/RM]";
    document.frmReviewPost.contents.value += ToAdd;
    document.frmReviewPost.contents.focus();
}
function Cwmv() {
    var FoundErrors = '';
    var enterURL = prompt(text_enter_wmv, "http://");
    if (!enterURL) {
        FoundErrors += "\n" + error_no_url;
    }
    if (FoundErrors) {
        alert("错误！" + FoundErrors);
        return;
    }
    var ToAdd = "[MP=500,350]" + enterURL + "[/MP]";
    document.frmReviewPost.contents.value += ToAdd;
    document.frmReviewPost.contents.focus();
}


function Cwma() {
    var FoundErrors = '';
    var enterURL = prompt(text_enter_wma, "http://");
    if (!enterURL) {
        FoundErrors += "\n" + error_no_url;
    }
    if (FoundErrors) {
        alert("错误！" + FoundErrors);
        return;
    }
    var ToAdd = "[wma]" + enterURL + "[/wma]";
    document.frmReviewPost.contents.value += ToAdd;
    document.frmReviewPost.contents.focus();
}
function Cmov() {
    var FoundErrors = '';
    var enterURL = prompt(text_enter_mov, "http://");
    if (!enterURL) {
        FoundErrors += "\n" + error_no_url;
    }
    if (FoundErrors) {
        alert("错误！" + FoundErrors);
        return;
    }
    var ToAdd = "[QT=500,350]" + enterURL + "[/QT]";
    document.frmReviewPost.contents.value += ToAdd;
    document.frmReviewPost.contents.focus();
}
function Cdir() {
    var FoundErrors = '';
    var enterURL = prompt(text_enter_sw, "http://");
    if (!enterURL) {
        FoundErrors += "\n" + error_no_url;
    }
    if (FoundErrors) {
        alert("错误！" + FoundErrors);
        return;
    }
    var ToAdd = "[DIR=500,350]" + enterURL + "[/DIR]";
    document.frmReviewPost.contents.value += ToAdd;
    document.frmReviewPost.contents.focus();
}
function Cmarquee() {
    fontbegin = "[move]";
    fontend = "[/move]";
    fontchuli();
}
function Cfly() {
    fontbegin = "[fly]";
    fontend = "[/fly]";
    fontchuli();
}

function showsize(size) {
    fontbegin = "[size=" + size + "]";
    fontend = "[/size]";
    fontchuli();
}

function showfont(font) {
    fontbegin = "[face=" + font + "]";
    fontend = "[/face]";
    fontchuli();
}

function showcolor(color) {
    fontbegin = "[color=" + color + "]";
    fontend = "[/color]";
    fontchuli();
}

function fontchuli() {
    if ((document.selection) && (document.selection.type == "Text")) {
        var range = document.selection.createRange();
        var ch_text = range.text;
        range.text = fontbegin + ch_text + fontend;
    }
    else {
        document.frmReviewPost.contents.value = fontbegin + document.frmReviewPost.contents.value + fontend;
        document.frmReviewPost.contents.focus();
    }
}

function Cguang() {
    var FoundErrors = '';
    var enterSET = prompt(text_enter_guang1, "255,red,2");
    var enterTxT = prompt(text_enter_guang2, "文字");
    if (!enterSET) {
        FoundErrors += "\n" + error_no_gset;
    }
    if (!enterTxT) {
        FoundErrors += "\n" + error_no_gtxt;
    }
    if (FoundErrors) {
        alert("错误！" + FoundErrors);
        return;
    }
    var ToAdd = "[glow=" + enterSET + "]" + enterTxT + "[/glow]";
    document.frmReviewPost.contents.value += ToAdd;
    document.frmReviewPost.contents.focus();
}

function Cying() {
    var FoundErrors = '';
    var enterSET = prompt(text_enter_guang1, "255,blue,1");
    var enterTxT = prompt(text_enter_guang2, "文字");
    if (!enterSET) {
        FoundErrors += "\n" + error_no_gset;
    }
    if (!enterTxT) {
        FoundErrors += "\n" + error_no_gtxt;
    }
    if (FoundErrors) {
        alert("错误！" + FoundErrors);
        return;
    }
    var ToAdd = "[SHADOW=" + enterSET + "]" + enterTxT + "[/SHADOW]";
    document.frmReviewPost.contents.value += ToAdd;
    document.frmReviewPost.contents.focus();
}

ie = (document.all)? true:false
if (ie) {
    function ctlent(eventobject) {
        if (event.ctrlKey && window.event.keyCode == 13) {
            this.document.frmReviewPost.submit();
        }
    }
}
