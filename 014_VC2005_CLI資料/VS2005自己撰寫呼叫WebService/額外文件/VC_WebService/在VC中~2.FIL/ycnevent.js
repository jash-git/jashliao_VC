
ycn=window.ycn||{};ycn.Event={addEvent:function(obj,evType,fn){if(obj.addEventListener)
{obj.addEventListener(evType,fn,false);return true;}
else if(obj.attachEvent)
{var r=obj.attachEvent("on"+evType,fn);ycn.EventCache.add(obj,evType,fn);return r;}
else
{return false;}},removeEvent:function(obj,evType,fn){if(obj.removeEventListener){obj.removeEventListener(evType,fn,false);return true;}else if(obj.detachEvent){var r=obj.detachEvent("on"+evType,fn);return r;}else{return false;}},getEvent:function(e)
{e=window.event||e;e.leftButton=false;if(e.srcElement==null&&e.target!=null)
{e.srcElement=e.target;e.leftButton=(e.button==1);}
else if(e.target==null&&e.srcElement!=null)
{e.target=e.srcElement;e.leftButton=(e.button==0);}
else if(e.srcElement!=null&&e.target!=null)
{}
else{return null}
if(document.body&&document.documentElement)
{e.mouseX=e.pageX||(e.clientX+Math.max(document.body.scrollLeft,document.documentElement.scrollLeft));e.mouseY=e.pageY||(e.clientY+Math.max(document.body.scrollTop,document.documentElement.scrollTop));}
else
{e.mouseX=-1;e.mouseY=-1;}
return e;},stopEvent:function(e)
{if(e&&e.cancelBubble!=null)
{e.cancelBubble=true;e.returnValue=false;}
if(e&&e.stopPropagation&&e.preventDefault)
{e.stopPropagation();e.preventDefault();}
return false;}};ycn.EventCache=function()
{var listEvents=[];return{listEvents:listEvents,add:function(node,sEventName,fHandler,bCapture){listEvents[listEvents.length]=arguments;},flush:function(){var i,item;for(i=listEvents.length-1;i>=0;i=i-1)
{item=listEvents[i];if(item[0].removeEventListener){item[0].removeEventListener(item[1],item[2],item[3]);};if(item[1].substring(0,2)!="on"){item[1]="on"+item[1];};if(item[0].detachEvent){item[0].detachEvent(item[1],item[2]);};item[0][item[1]]=null;};}};}();ycn.Event.addEvent(window,"unload",ycn.EventCache.flush);function error_handler(a,b,c)
{window.status=(c+"\n"+b+"\n\n"+a+"\n\n"+error_handler.caller);return true;}