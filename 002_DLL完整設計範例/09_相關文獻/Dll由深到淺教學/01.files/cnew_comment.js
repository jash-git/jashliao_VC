	/* change ++ */
var c_hasPost = false;
var floor = 0;
var c_submitNum = 0;
var postNum = 0;
var re = /(\[s(\d{1,2})\])/ig;
var ree =/\./g;
var inited = false;
var tempContent = "";
if(typeof(referId) == "undefined") referId="0";
if(typeof(channelId) == "undefined") channelId="0";
if(typeof(site) == "undefined") site="";
if(typeof(type) == "undefined") type="";
if(typeof(isValidate) == "undefined") isValidate="1";
var articleUrl = window.location.href;
var commentHTML = "";
commentHTML += "<style style=\"type\/css\">";
commentHTML += ".c_commentname {margin-bottom:1px;font-size:14px;font-weight:bold;color:#FFF;}";
commentHTML += ".c_commentname a {color:#FFF;}";
commentHTML += ".c_commentname span {color:#FF6600;}";
commentHTML += ".c_commentlist td {background:#FFF;font-size:12px;padding:0 4px;line-height:21px;font-family:\"Arial\"}";
commentHTML += ".c_commentlist b {color:#F00;}";
commentHTML += ".c_commentlist span {color:#008000;}";
commentHTML += ".c_commentbox {border:#C2D9F2 1px solid;padding:6px;background:#FFF;margin-top:6px;font-size:12px;}";
commentHTML += "#content {cursor:text;padding:2px 1px;width:98%;height:75px;vertical-align:top;font-size:14px;border:1px solid #A3B9CD;background:url(http://image.yesky.com/TLimages/images/yesky_alpha_logo.gif) no-repeat center center #fff;font-size:13px;white-space:pre;margin-top:6px;}";
commentHTML += ".nickName {width:112px;height:20px;border:1px solid #A3B9CD;line-height:20px;font-size:12px;}";
commentHTML += ".submit {border:1px solid #A3B9CD;height:20px;padding:1px 2px;margin:0 0 0 10px;font-size:12px;background:#C8D8FB;color:#000;}";
commentHTML += ".noteBoxStyle {line-height:30px;background:#C1D3FB;border:1px solid #999;text-align:center;font-size:16px;color:#000;filter:Alpha(opacity=100);-moz-opacity:1;opacity:1;}";
commentHTML += "<\/style>";
var postURLDomian = "http://comment.yesky.com/"
commentHTML +="	<table width=\"100%\" height=\"26\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\" id=\"tlqtitle\" bgcolor=\"#005395\" class=\"c_commentname\"><tr><td width=\"50%\"><a href=\"#pls\" id=\"pls\" name=\"pls\" > </a>&nbsp;&nbsp;"+articletitle+"的评论共有&nbsp;<a target=\"_blank\" href=\""+postURLDomian+"more.htm?site="+site+"&referId="+referId+"&type="+type+"&channelId="+channelId+"&isValidate="+isValidate+"&articleUrl="+articleUrl+"\" ><span id=\"postFloor\"><\/span><\/a>&nbsp;条</td>";
commentHTML +="</tr></table>";
commentHTML += "<span id=\"commentList\"></span>";
commentHTML += "<table width=\"100%\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\" class=\"c_commentbox\"><form id=\"postForm\" name=\"postForm\" action=\"javascript:void(0)\" method=\"post\"><tr><td width=\"9%\" align=\"center\" bgcolor=\"#FFFFFF\"><strong>内容：</strong></td><td colspan=\"2\" bgcolor=\"#FFFFFF\"><textarea id=\"content\" name=\"content\" onfocus=\"checkIp()\"></textarea></td></tr><tr><td align=\"center\" bgcolor=\"#FFFFFF\"><strong>昵称：</strong></td><td width=\"66%\" height=\"36\" bgcolor=\"#FFFFFF\"><input id=\"nickName\" name=\"nickName\" type=\"text\" value=\"天极网友\" class=\"nickName\" onfocus=\"this.value=''\"/><input id=\"submitButton\" type=\"button\" onclick=\"handleSubmit('postForm')\" value=\"发表评论\" class=\"submit\"/></td><td width=\"25%\" bgcolor=\"#FFFFFF\"><strong><div id=\"moreLink\" ><\/div></strong></td></tr><tr id=\"validateDiv\" style=\"display:none\"><td width=\"11%\" align=\"center\" bgcolor=\"#FFFFFF\"><strong>验证码：</strong></td><td width=\"11%\" height=\"36\" bgcolor=\"#FFFFFF\"><input id=\"validateNum\" name=\"validateNum\" type=\"text\" value=\"请输入验证码\" class=\"nickName\" onfocus=\"this.value='';refresh();\" maxlength=\"4\"/>&nbsp;&nbsp;&nbsp;<img id=\"validatePic\" src=\"http://comment.yesky.com/jsps/randomnumber.jsp\"/></td></tr><\/form></table>";
document.writeln("  <input name=\"site\" id=\"site\" value=\""+site+"\" type=\"hidden\"> ");
document.writeln("	<input name=\"referId\" id=\"referId\" value=\""+referId+"\" type=\"hidden\">");
document.writeln("	<input name=\"type\" id=\"type\" value=\""+type+"\" type=\"hidden\"> ");
document.writeln("	<input name=\"channelId\" id=\"channelId\" value=\""+channelId+"\" type=\"hidden\"> ");
document.writeln("	<input name=\"isValidate\" id=\"isValidate\" value=\""+isValidate+"\" type=\"hidden\"> ");
document.writeln("	<input name=\"articleUrl\" id=\"articleUrl\" value=\""+articleUrl+"\" type=\"hidden\"> ");
commentHTML += "            <\/form>";
commentHTML += "<div id=\"noteBox\" class=\"noteBoxStyle\" onclick=\"closeNote()\" style=\"filter:alpha(opacity=90);-moz-opacity:0.9;opacity: 0.9;width:230px;height:60px;line-height:60px;font-weight:bold;z-index:1001;position:absolute;left:600px;top:300px;display:none\">恭喜，信息提交成功！<\/div>";
document.writeln(commentHTML);
var noteBox = $("noteBox");


function loadDwr(){
  dwr.engine.setRpcType(dwr.engine.ScriptTag);
  CheckComment._path = "http://comment.yesky.com/dwr";
  
}
function writePostList() {
	if( typeof(latest_comments_poster) == "object" && latest_comments_poster.length && latest_comments_poster.length > 0) { 
		postNum = latest_comments_poster.length;
		c_hasPost = true;
		floor = latest_comments_floorno[0]; 
	}
	if(c_hasPost){
		$("postFloor").innerHTML = floor.toString();
		$("moreLink").innerHTML = "<div><a target=\"_blank\" href=\""+postURLDomian+"more.htm?site="+site+"&referId="+referId+"&type="+type+"&channelId="+channelId+"&isValidate="+isValidate+"&articleUrl="+articleUrl+"\" > 查看所有网友评论 <\/a><\/div>";
		var postList="<table width=\"100%\" border=\"0\" cellpadding=\"0\" cellspacing=\"1\" bgcolor=\"#C2D9F2\" class=\"c_commentlist\">";
		for(var i=0;i<postNum;i++){ 
			postList += "<tr><td width=\"6%\" align=\"center\"><b>"+latest_comments_floorno[i]+"</b>楼</td>    <td width=\"10%\" align=\"center\"><span>"+latest_comments_poster[i]+"</span></td><td width=\"64%\">"+latest_comments_contents[i]+"</td><td width=\"20%\" align=\"center\">"+latest_comments_postdate[i].substring(0,17).replace(ree,":")+"</td></tr>";
		}
        postList += "</table>";
		$("commentList").innerHTML = postList + $("commentList").innerHTML;
	}else{
		$("commentList").innerHTML = "<center id=\"no_comment\" style=\"display:block;margin-top:8px;\">欢迎评论！<\/center>";
		$("postFloor").innerHTML = "0";
	}
	$("commentList").style.background = "none";
	inited = true;
}
function addPostList(){
	if( ! $("moreLink") ) $("moreLink").innerHTML = "<div><a target=\"_blank\" href=\""+postURLDomian+"more.htm?site="+site+"&referId="+referId+"&type="+type+"&channelId="+channelId+"&isValidate="+isValidate+"&articleUrl="+articleUrl+"\" > 查看所有网友评论 <\/a><\/div>";
	if( $("no_comment") ) $("no_comment").style.display = "none";
	var postList="<table width=\"100%\" border=\"0\" cellpadding=\"0\" cellspacing=\"1\" bgcolor=\"#C2D9F2\" class=\"c_commentlist\">";
	postList += "<tr><td width=\"6%\" align=\"center\"><b>"+(++floor)+"</b>楼</td><td width=\"10%\" align=\"center\"><span>"+toTXT($("nickName").value)+"</span></td><td width=\"64%\">"+toTXT(tempContent).replace(re,"<img src=http:\/\/image.yesky.com\/TLimages\/smile\/face$2.gif border=0 align=absmiddle> ")+"</td><td width=\"20%\" align=\"center\">"+parseDate(new Date())+"</td></tr>";
	postList += "</table>";
	$("commentList").innerHTML = postList + "\n" + $("commentList").innerHTML;
	tempContent = "";
	$("postFloor").innerHTML = floor.toString();
	showNote();
}
function $(id){
	if ( typeof (document.getElementById(id)) != "undefined" ) {
		return document.getElementById(id);
	}else return false;
}

function parseDate(d){
   var s = "";
   s += d.getUTCFullYear()+"-";               
   s += fillLeftZero(d.getMonth() + 1) + "-";            
   s += fillLeftZero(d.getDate()) + " ";                  
   s += fillLeftZero(d.getHours()) + ":";
   s += fillLeftZero(d.getMinutes());        
   return(s);                          
}
function fillLeftZero(v){
	return ""+v<10?("0"+v):v;
}					
function getCookie_commentVal_comment(offset) {
    var endstr = document.cookie.indexOf(";", offset);
    if (endstr == -1)
        endstr = document.cookie.length;
    return unescape(document.cookie.substring(offset, endstr));
}
function getCookie_comment(name) {
    var arg = name + "=";
    var alen = arg.length;
    var clen = document.cookie.length;
    var i = 0;
    while (i < clen) {
        var j = i + alen;
        if (document.cookie.substring(i, j) == arg)
            return getCookie_commentVal_comment(j);
        i = document.cookie.indexOf(" ", i) + 1;
        if (i == 0) break;
    }
    return null;
}
function setCookie_comment(name, value, expireTime) { 
    var argv = setCookie_comment.arguments;
    var argc = setCookie_comment.arguments.length;
    var expireTime = expireTime;
    var path = (argc > 3) ? argv[3] : null;
    var domain = (argc > 4) ? argv[4] : null;
    var secure = (argc > 5) ? argv[5] : false;
	var expires=new Date();
	expires.setTime(expires.getTime()+expireTime);
    document.cookie = name + "=" + escape(value) +
                      ((expires == null) ? "" : ("; expires=" + expires.toGMTString())) +
                      ((path == null) ? "" : ("; path=" + path)) +
                      ((domain == null) ? "" : ("; domain=" + domain)) +
                      ((secure == true) ? "; secure" : "");
}
function deleteCookie_comment(name) {
    var exp = new Date();
    exp.setTime(exp.getTime() - 1);
    var cval = getCookie_comment(name);
    document.cookie = name + "=" + cval + "; expires=" + exp.toGMTString();
}
function validateForm(f) {
    with(f) {
	if(nickName.value.length ==  0) {
		alert("请输入您的昵称！");
		nickName.focus();
		return;
	}
	if(nickName.value.length > 20) {
		alert("昵称太长，字数不能超过20！");
		nickName.focus();
		return;
	}
	if(content.value.length ==  0) {
		alert("请输入评论内容");
		content.focus();
		return;
	}
	if(content.value.length > 300) {
		alert("内容太长，字数不能超过300");
		content.focus();
		return;
	}	
	if(getCookie_comment("submitted") == null){
		setCookie_comment("submitted",1,1000*60*1);
	}else{
	
		var submitted = parseInt(getCookie_comment("submitted"));
		if(submitted < 3){
			setCookie_comment("submitted",++submitted,1000*60*1);
		}else{
			alert("对不起，您发帖速度太快了，请稍后再试！");
			return false;
		}
	}
	return true;
    }

}
function toTXT(str){ 
     var RexStr = /\<|\>|\"|\'|\&/g 
     var str = str.replace(RexStr, 
         function(MatchStr){ 
             switch(MatchStr){ 
                 case "<": 
                     return "&lt;"; 
                     break; 
                 case ">": 
                     return "&gt;"; 
                     break; 
                 case "\"": 
                     return "&quot;"; 
                     break; 
                 case "'": 
                     return "&#39;"; 
                     break; 
                 case "&": 
                     return "&amp;"; 
                     break; 
                 default : 
                     break; 
             } 
         } 
     ) 
     return str; 
} 
function lockInput(){
	tempContent = $("content").value;
	$("content").disabled = "disabled";
	$("submitButton").value = "信息提交中...";
	$("submitButton").disabled = "disabled";
}
function unlockInput(){
	$("content").disabled = "";
	$("content").value = "";
	$("submitButton").disabled = "";
	$("submitButton").value = "发表评论";
}

function unlockInputFalse(){
	$("content").disabled = "";
	//$("content").value = "";
	$("submitButton").disabled = "";
	$("submitButton").value = "发表评论";
}


function postBack(_post_success){
	
	  if(_post_success=='10'){
      alert('请输入验证码！');
      unlockInputFalse();
      return;
    }
    
    if(_post_success=='11'){
      alert('验证码错误！');
      unlockInputFalse();
      return;
    }
    
    if(_post_success=='12'){
      alert('不能输入全数字、全符号或者是数字和符号的组合！');
      unlockInputFalse();
      return;
    }

	if(_post_success){
	    unlockInput();
  		addPostList();
    }else{
  	  alert('对不起，内容不合法或者该IP被禁止发言。');
  	  unlockInputFalse();
  	}
}
function addComments(f){
	var f = document.getElementById(f);
	if( validateForm(f) && inited){
		commentPost('postBack');
		lockInput();
		
	}
}
function handleSubmit(f){
	addComments(f);             
}

function closeNote(){
	noteBox.style.display = "none";
}

function showNote(){
	var win_width = document.documentElement.clientWidth;
	var win_height =document.documentElement.clientHeight;
	var win_scrollLeft = document.documentElement.scrollLeft;
	var win_scrollTop = document.documentElement.scrollTop;
	
	var chat_width = (noteBox.style.width).substring(0,noteBox.style.width.indexOf("px"));
	var chat_height = (noteBox.style.height).substring(0,noteBox.style.height.indexOf("px"));
	noteBox.style.left = (parseInt(win_width) / 2 - parseInt(chat_width) / 2 + win_scrollLeft)+"px";
	noteBox.style.top = (parseInt(win_height) / 2 - parseInt(chat_height) / 2 + win_scrollTop)+"px";
	noteBox.style.display = "";
	refresh();
	setTimeout("closeNote()",2000);
}

function refresh(){
  var img = document.getElementById("validatePic");
  img.src = "http://comment.yesky.com/jsps/randomnumber.jsp?dumy=" + Math.random();
}

function callBackCheckIp(result){
    if(result){ 
        document.getElementById("validateDiv").style.display="block";
    }
  
}

function checkIp(){
  if(document.getElementById("isValidate").value == "1"){
  	try{
  		 loadDwr();
       CheckComment.checkIp(callBackCheckIp);
    }catch(e){
    }
  }
}

setTimeout("writePostList()",2000);
function addScript(){

	var url_1 = "http://image.yesky.com/TLimages/comment/js/asyncCall.js";
	var url_2 = "http://image.yesky.com/TLimages/comment/js/post.js";
	var url_3 = "http://comment.yesky.com/dwr/engine.js";
	var url_4 = "http://comment.yesky.com/dwr/interface/CheckComment.js";
	var url_6 = "http://comment.yesky.com/dwr/util.js";
	var head = document.getElementsByTagName("head").item(0);
	oScript1 = document.createElement("script");
	oScript2 = document.createElement("script");
	oScript3 = document.createElement("script");
	oScript4 = document.createElement("script");

	oScript6 = document.createElement("script");
	oScript1.setAttribute("src", url_1);
	oScript2.setAttribute("src", url_2);
	oScript3.setAttribute("src", url_3);
	oScript4.setAttribute("src", url_4);

	oScript6.setAttribute("src", url_6);
	head.appendChild(oScript1);
	head.appendChild(oScript2);
	head.appendChild(oScript3);
	head.appendChild(oScript4);

	head.appendChild(oScript6);

}



addScript();






