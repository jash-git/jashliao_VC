  
function updateHit(id, type, ts)
{
  if (!getCookie(type + id))
  {
    document.write("<img style='display:none;' src='http://blog.yam.com/hits/action.php?id=" + id + "&type=" + type + "&op=add&"+ ts +"' width='0' height='0'/>");
  }
}

function getCookie(c_name)
{
  if (document.cookie.length>0)
  {
    c_start=document.cookie.indexOf(c_name + "=");
    if (c_start!=-1)
    { 
      c_start=c_start + c_name.length+1 ;
      c_end=document.cookie.indexOf(";",c_start);
      if (c_end==-1) c_end=document.cookie.length;
      return unescape(document.cookie.substring(c_start,c_end));
    } 
  }
  return null;
}

function setCookie(c_name,value,expiretime)
{
  var exdate=new Date();
  exdate.setTime(exdate.getTime()+expiretime);
  
  document.cookie=c_name+ "=" +escape(value)+ ";expires="+exdate;
} 


  function mypop(url,w,h,name)
   { 
     x = (screen.width/2)-(w/2);y = (screen.height/2)-(h/2);
     if (x<0) x=0;if (y<0) y=0;
       w = window.open(url, name,"alwaysRaised=yes,status=no,width="+w+",height="+h+",toolbar=no,directories=no,top="+y+",left="+x+",scrollbars=no,dependent=no");
     w.focus();
   }   

/**
 * @param string url to load the page from
 * @param integer window width
 * @param integer window height
 * @param string extra options
 */
 function popupCenter(url,width,height,xtr,name) {
  var top=(screen.height-height)/2;
  var left=(screen.width-width)/2;
  window.open(url,name ,xtr+",top=" +top+ ",left="+left+",width="+width+",height="+height);
}

/**
 * @param string element ID
 * @return object
 */
function getByID(id) {
    if (document.getElementById)
        return document.getElementById(id);
    else if (document.all)
        return document.all[id];
}

/**
 * @param string element ID
 * @param string on|off displayed or not? (optional)
 * @param string CSS value for property 'display:' (optional)
 */
function toggle(blockid) {
    var args;
    var o = getByID(blockid);
    if (!o) return;
    if (!toggle.arguments || !arguments) return; // old version of javascript
    if (toggle.arguments) {
        args = toggle.arguments;
    } else {
        args = arguments;
    }
    if (args.length == 2) {
        if (args[1]=='on') {
            o.style.display = 'block';
        } else if (args[1]=='off') {
            o.style.display = 'none';
        } else {
            if (o.style.display == 'none' || o.style.display == '') {
            toggle(blockid,'on',args[1]);
          } else {
            toggle(blockid,'off',args[1]);
          }
        }
    } else if (args.length == 3) {
        if (args[1]=='on') {
        o.style.display = args[2];
      } else { // args[1]=='off'
        o.style.display = 'none';
      }
    } else if (args.length == 1) {
        if (o.style.display == 'none' || o.style.display == '') {
        o.style.display = 'block';
      } else {
        o.style.display = 'none';
      }
    }
}

function writeBack( msg )
{
  var back = window.opener;
  var myField = back.document.NewComment.commentText;

  msg = "<img src='" + msg + "'>";
  if (back.document.selection) {
    myField.focus();
    sel = back.document.selection.createRange();
    sel.text = msg;
    myField.focus();
  }
  else if (myField.selectionStart || myField.selectionStart == '0') {
    var startPos = myField.selectionStart;
    var endPos = myField.selectionEnd;
    var cursorPos = endPos;
    myField.value = myField.value.substring(0, startPos)
            + msg
            + myField.value.substring(endPos, myField.value.length);
    cursorPos += msg.length;
    myField.focus();
    myField.selectionStart = cursorPos;
    myField.selectionEnd = cursorPos;
  }
  else {
    myField.value += msg;
    myField.focus();
  }
  close();
}

function hidePage() {
    var agt=navigator.userAgent.toLowerCase();
    var is_safari = ((agt.indexOf('safari')!=-1)&&(agt.indexOf('mac')!=-1))?true:false;
    if(is_safari) return true;
    var el = document.forms[0];
    while (el.tagName != "BODY") {
        el = el.parentNode;
    }
    for(i=0;i<el.childNodes.length;i++) {
        if(el.childNodes[i].style) {
            el.childNodes[i].style.display='none';
        }
    }
    var newDiv = document.createElement('div');
    newDiv.innerHTML='<div class="wait-message" id="waiting-message">'+messageHidePage+'<br /></div>';
    el.appendChild(newDiv);
    document.getElementById('waiting-message').appendChild(document.getElementById('waiting-image'));
    
    writeBack("");
}

function addClassName(el, sClassName) {
  var s = el.className;
  var p = s.split(" ");
  var l = p.length;
  for (var i = 0; i < l; i++) {
    if (p[i] == sClassName)
      return;
  }
  p[p.length] = sClassName;
  el.className = p.join(" ");

}

function removeClassName(el, sClassName) {
  var s = el.className;
  var p = s.split(" ");
  var np = [];
  var l = p.length;
  var j = 0;
  for (var i = 0; i < l; i++) {
    if (p[i] != sClassName)
      np[j++] = p[i];
  }
  el.className = np.join(" ");
}

function goMonthly(p)
{
  var pi = p.selectedIndex;
  var link = p.options[pi].value;

  if(link != -1)
  {
    document.location = link;
  }

}

function goOpenWindowUrl(p)
{
  var pi = p.selectedIndex;
  var link = p.options[pi].value;

  if(link != -1)
  {
    window.open(link, "food",'');
    //document.location = link;
  }

}


function cbox_switch(arg)
{
  var myform = document.func;
  for(var i =0;i<myform.elements.length;i++)
  {
    if(myform.elements[i].type == "checkbox")
    {
      myform.elements[i].checked = arg;
    }
  }
}

function OpenTrackback (c) {
    window.open(c,
                    'trackback',
                    'width=480,height=480,scrollbars=yes,status=yes');
}


function disable_rbutton()
{
  if (event.button == 2)
  {
    alert("此相簿不開放右鍵喔!");
  }
}

function setCopy(_sTxt){
try{clipboardData.setData('Text',_sTxt)}catch(e){}
}

function showAlbumSlide(xmlURL)
{
  document.write('<object classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000" codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=7,0,19,0" width="135" height="257">');
  document.write('<param name="movie" value="http://pics.blog.yam.com/images/flash/pic-player.swf" />');
  document.write('<param name="quality" value="high" />');
  document.write('<param name="wmode" value="transparent" />');
  document.write('<PARAM NAME=FlashVars VALUE="xmlURL='+xmlURL+'">');
  document.write('<embed src="http://pics.blog.yam.com/images/flash/pic-player.swf" FlashVars="xmlURL='+xmlURL+'"  quality="high" pluginspage="http://www.macromedia.com/go/getflashplayer" type="application/x-shockwave-flash" width="135" height="257" wmode="transparent"></embed>');
  document.write('</object>');
}
function recommend_resize(obj){var size='30px';var h=obj.offsetHeight;var w=obj.offsetWidth;if(h>=w)obj.style.height=size;else obj.style.width=size;if(obj.offsetWidth>30)obj.style.width='20px';}

function getDomain(){
  return location.href;
}
