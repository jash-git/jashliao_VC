<!--
var cid=0;
var sid=0;


function jk_insert_em(emvar) { document.write_frm.jk_word.value+=emvar; }

function jk_em_type(tvar)
{
  if (tvar=="b")
  {
    for(var i=0; i<13; i++) { document.write ("<img src='images/icon/emb" + (i+1) + ".gif' border=0 align=absMiddle onclick=\"javascript:jk_insert_em\('[emb" + (i+1) + "]'\);\" style=\"CURSOR: hand\">&nbsp;&nbsp;") }
  }
  else
  {
    for(var i=0; i<16; i++) { document.write ("<img src='images/icon/em" + (i+1) + ".gif' border=0 align=absMiddle onclick=\"javascript:jk_insert_em\('[em" + (i+1) + "]'\);\" style=\"CURSOR: hand\">&nbsp;&nbsp;") }
  }
}

function img_small(img_var) { return "<img border=0 src='images/small/" + img_var + ".gif' align=absmiddle>&nbsp;" }

function login_true()
{
  if (login_frm.username.value=="") { alert("请输入您在本站注册时的 用户名称 ！"); login_frm.username.focus(); return false; }
  if (login_frm.password.value=="") { alert("请输入您在本站注册时的 登陆密码 ！"); login_frm.password.focus(); return false; }
}

function open_win(url,name,width,height,scroll)
{
  var Left_size = (screen.width) ? (screen.width-width)/2 : 0;
  var Top_size = (screen.height) ? (screen.height-height)/2 : 0;
  var open_win=window.open(url,name,'width=' + width + ',height=' + height + ',left=' + Left_size + ',top=' + Top_size + ',toolbar=no,location=no,directories=no,status=no,menubar=no,scrollbars=' + scroll + ',resizable=no' );
}

function frm_submitonce(theform)
{
  if (document.all||document.getElementById)
  {
    for (i=0;i<theform.length;i++)
    {
      var tempobj=theform.elements[i]
      if(tempobj.type.toLowerCase()=="submit"||tempobj.type.toLowerCase()=="reset")
      tempobj.disabled=true
    }
  }
}

function frm_quicksubmit(eventobject)
{
  if (event.keyCode==13 && event.ctrlKey)
    write_frm.wsubmit.click();
}
-->