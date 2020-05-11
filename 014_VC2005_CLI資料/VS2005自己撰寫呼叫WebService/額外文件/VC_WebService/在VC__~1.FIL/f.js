function setTrBgcolor(obj, types, bgtypes) {
    if (types == 1) {
        obj.style.background = "#999999";
    }
    else {
        if (bgtypes == 1) {
            obj.style.background = "#F6F6F6";
        }
        else {
            obj.style.background = "";
        }
    }
}


function tunePage(toPageNo, pageNo) {
    try {
        var topage = 1;
        if (typeof(toPageNo) != "number" || toPageNo < 1) topage = 1;
        else topage = toPageNo;
        var olds = window.location.search;
        if (typeof(pageNo) == "undefined" || pageNo == "") pageNo = "pageNo";
        var news = "";
        if (olds.length > 1) {
            olds = olds.substring(1, olds.length);
            var arrays = olds.split("&");
            for (var i = 0; i < arrays.length; i++)
            {
                if (arrays[i].indexOf(pageNo + "=") < 0 && arrays[i].length > 1) {
                    news += "&" + arrays[i];
                }
            }
            if (news.length > 1) {
                news = "?" + news.substring(1, news.length) + "&" + pageNo + "=" + topage;
            }
            else {
                news = "?" + pageNo + "=" + topage;
            }
        }
        else {
            news = "?" + pageNo + "=" + topage;
        }
        window.location = window.location.pathname + news;
    }
    catch(e) {
        window.location = window.location.pathname + window.location.search;
    }
}

function sAll(thisObj, dObj) {
    with (thisObj.form) {
        for (var i = 0; i < elements.length; i++) {
            var element = elements[i];
            if (!element.disabled && element.type == "checkbox" && element.name == dObj) {
                element.checked = thisObj.checked;
            }
        }
    }
}


function sReverse(thisObj, dObj) {
    with (thisObj.form) {
        for (var i = 0; i < elements.length; i++) {
            var element = elements[i];
            if (!element.disabled && element.type == "checkbox" && element.name == dObj) {
                element.checked = !element.checked;
            }
        }
    }
}

function imgzoom(o){
	var zoom=parseInt(o.style.zoom, 10)||100;zoom+=event.wheelDelta/12;if (zoom>0) o.style.zoom=zoom+'%';
	return false;
}

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
    str = str.replace(/<a[^>]+href="([^"]+)"[^>]*>(.*?)<\/a>/ig,"\n[URL=$1]$2[/URL]\n");

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
var text_enter_blockquote = "要引用的文字！";
var list_help = "插入列表\n\n插入可由浏览器显示来的规则列表项。\n例如：\n[list]\n[*]；列表项 #1\n[*]；列表项 #2\n[*]；列表项 #3\n[/list]";
var list_normal = "请选择列表格式(可选字段)：字母式列表输入 \"A\"；数字式列表输入 \"1\"。";
var list_normal_error = "错误：列表格式只能选择输入 \"A\" 或 \"1\"。";
var list_normal_input = "请输入列表项目内容，如果留空表示项目结束。";

if(!postForm) {
    var postForm = document.frmReviewPost;

}

function setContentValue(val, postForm){
  	if(!postForm) {
		var postForm = document.frmReviewPost;
	}
    postForm.contents.value += val;
    postForm.contents.focus();

}


function AddText(text) {
	if(!postForm) {
		var postForm = document.frmReviewPost;
	}

	if (postForm.contents.createTextRange && postForm.contents.caretPos) {
        var caretPos = postForm.contents.caretPos;
        caretPos.text = caretPos.text.charAt(caretPos.text.length - 1) == ' ' ?
                        text + ' ' : text;
    }
    else postForm.contents.value += text;
    postForm.contents.focus(caretPos);
}
function inputs(str)
{
    AddText(str);
}

function Clist() {
    txt=prompt(list_normal,"");
    while ((txt!="") && (txt!="A") && (txt!="a") && (txt!="1") && (txt!=null)) {
        txt=prompt(list_normal_error,"");
    }
    if (txt!=null) {
        if (txt=="") {
            AddTxt="[list]";
        } else {
            AddTxt="[list="+txt+"]";
        }
        txt="1";
        while ((txt!="") && (txt!=null)) {
            txt=prompt(list_normal_input,"");
            if (txt!="") {
                AddTxt+="[*]"+txt+"";
            }
        }
        AddTxt+="[/list]\r\n";
        AddText(AddTxt);
    }
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
    setContentValue(ToAdd, postForm);
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
    setContentValue(ToAdd, postForm);
}
function Cemail() {
    var emailAddress = prompt(text_enter_email, "");
    if (!emailAddress) {
        alert(error_no_email);
        return;
    }
    var ToAdd = "[EMAIL]" + emailAddress + "[/EMAIL]";
    setContentValue(ToAdd, postForm);
}

function Cbold() {

    fontbegin = "[B]";
    fontend = "[/B]";
    fontchuli(postForm);
}
function Citalic() {
    fontbegin = "[I]";
    fontend = "[/I]";
    fontchuli(postForm)
}
function Cunder() {
    fontbegin = "[U]";
    fontend = "[/U]";
    fontchuli(postForm)
}
function Ccenter() {
    fontbegin = "[center]";
    fontend = "[/center]";
    fontchuli(postForm)
}
function Cstrike() {
    fontbegin = "[strike]";
    fontend = "[/strike]";
    fontchuli(postForm)
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
    setContentValue(ToAdd, postForm);
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
    setContentValue(ToAdd, postForm);
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
    setContentValue(ToAdd, postForm);
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
    setContentValue(ToAdd, postForm);
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
    setContentValue(ToAdd, postForm);
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
    setContentValue(ToAdd, postForm);
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
    setContentValue(ToAdd, postForm);
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
    setContentValue(ToAdd, postForm);
}
function Cmarquee() {
    fontbegin = "[move]";
    fontend = "[/move]";
    fontchuli(postForm)
}
function Cfly() {
    fontbegin = "[fly]";
    fontend = "[/fly]";
    fontchuli(postForm)
}

function showsize(size) {
    fontbegin = "[size=" + size + "]";
    fontend = "[/size]";
    fontchuli(postForm)
}

function showfont(font) {
    fontbegin = "[face=" + font + "]";
    fontend = "[/face]";
    fontchuli(postForm)
}

function showcolor(color) {
    fontbegin = "[color=" + color + "]";
    fontend = "[/color]";
    fontchuli(postForm)
}


	
function fontchuli(postForm) {

    if ((document.selection) && (document.selection.type == "Text") &&  (document.selection.createRange().parentElement() == "object") && (document.selection.createRange().parentElement().tagName = "TEXTAREA")) {
        var range = document.selection.createRange();
        var ch_text = range.text;
        range.text = fontbegin + ch_text + fontend;
    }
    else {
		if(!postForm) {
			var postForm = document.frmReviewPost;
		}
        postForm.contents.value = fontbegin + postForm.contents.value + fontend;
        postForm.contents.focus();
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
    setContentValue(ToAdd, postForm);
}

function Cblockquote() {
    var FoundErrors = '';
    var enterTxT = prompt(text_enter_guang2, "引用");
    if (!enterTxT) {
        FoundErrors += "\n" + error_no_gtxt;
    }
    if (FoundErrors) {
        alert("错误！" + FoundErrors);
        return;
    }
    var ToAdd = "[quote]" + enterTxT + "[/quote]";
    setContentValue(ToAdd, postForm);
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
    setContentValue(ToAdd, postForm);
}
