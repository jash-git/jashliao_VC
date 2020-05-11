<!--
var adc;
var arrP=new Array("id","adv_ch","adv_w","adv_h","adv_l","adv_t","adv_id","adv_sid","adv_st","adv_ifm","adv_ctc","adv_cbc","btn_cls","adv_tmp","adv_tmpid","classname")
var arrDP=new Array("","","","","","","adv_{$id$}","adspan_{$id$}","0","adifm_{$id$}","","","0","","","")	


function $(obj){return document.getElementById(obj)}

function ad_span(adId,spanId){if($(adId)){if($(spanId)){$(adId).innerHTML=$(spanId).innerHTML}}if($(spanId)){$(spanId).innerHTML=""}}

function getPosition(obj) {
    var top=0;
    var left=0;
    var width=obj.offsetWidth;
    var height=obj.offsetHeight;
while (obj.offsetParent) {
    top += obj.offsetTop;
    left += obj.offsetLeft;
    obj = obj.offsetParent;
    }
    return {"top":top,"left":left,"width":width,"height":height};	
 }
 
function getArgs() {
    var args = new Object();
    var query = location.search.substring(1).toLowerCase();     // Get query string.
    var pairs = query.split("&");                 // Break at comma.
    for(var i = 0; i < pairs.length; i++) {
	var pos = pairs[i].indexOf('=');          // Look for "name=value".
	if (pos == -1) continue;                  // If not found, skip.
	var argname = pairs[i].substring(0,pos);  // Extract the name.
	var value = pairs[i].substring(pos+1);    // Extract the value.
	args[argname] = unescape(value);          // Store as a property.
	// In JavaScript 1.5, use decodeURIComponent() instead of escape()
    }
    return args;                                  // Return the object.
}

function $import(path, type){
  if (type == "css") {
      document.write("<" + "link href=\"" + path + "\" rel=\"stylesheet\" type=\"text/css\"></" + "link>");
  } else {
      document.write("<" + "script src=\"" + path + "\"></" + "script>");
  }
} 

function advs(){
//  document.domain="it168.com"
  this.items = [];
  this.add =  function(obj){ 
	  var aditem=eval("("+obj+")")  
	  for(var i=0;i<arrP.length;i++){
		  if(aditem[arrP[i]]==undefined){
				aditem[arrP[i]]=arrDP[i].replace("{$id$}",aditem.id)
			  }
		  }	  
	  var adstyle="";
	  aditem.ifmurl="http://adshow.it168.com/adfile/advs_publish_v4.asp?id="+aditem.id+(aditem.adv_ctc!=""?"&ctc="+aditem.adv_ctc:"")+(aditem.adv_cbc!=""?"&cbc="+aditem.adv_cbc:"")+"&ifm="+aditem.adv_ifm+"&w="+aditem.adv_w+"&h="+aditem.adv_h+"&btn_cls="+aditem.btn_cls+"&st="+aditem.adv_st+"&tmp="+aditem.adv_tmp+"&tmpid="+aditem.adv_tmpid+"&adv_id="+aditem.adv_id+"&classname="+aditem.classname;
	  if(aditem.adv_l!=""){adstyle="left:"+(typeof(aditem.adv_l)=='string'?eval(aditem.adv_l):aditem.adv_l)+"px;"}
	  if(aditem.adv_t!=""){adstyle+="top:"+(typeof(aditem.adv_t)=='string'?eval(aditem.adv_t):aditem.adv_t)+"px;"}	  
	  if(adstyle!=""){adstyle+="position: absolute;"}	  
	  var ua = window.navigator.userAgent.toLowerCase();      
	  
      if(ua.indexOf('msie')!=-1){
		  aditem.adhtml="<span style='display:none;width:0px;height:0px;"+adstyle+"' id="+aditem.adv_sid+">"+"<iframe name='"+aditem.adv_ifm+"' id='"+aditem.adv_ifm+"' style='height:0px;width:0px;display:none;' src='"+aditem.ifmurl+"' noresize scrolling=No frameborder=0 marginheight=0 marginwidth=0 allowTransparency='true'></iframe></span>"	
	  }
	  else{		  aditem.adhtml="<span style='display:none;"+adstyle+"' id="+aditem.adv_sid+">"+"<iframe name='"+aditem.adv_ifm+"' id='"+aditem.adv_ifm+"' style='height:"+aditem.adv_h+"px;width:"+aditem.adv_w+"px;display:none;' src='"+aditem.ifmurl+"' noresize scrolling=No frameborder=0 marginheight=0 marginwidth=0 allowTransparency='true'></iframe></span>"	}
      //aditem.adhtml="<span style='display:block;"+adstyle+"' id="+aditem.adv_sid+">"+"<iframe name='"+aditem.adv_ifm+"' id='"+aditem.adv_ifm+"' style='height:0px;width:0px;display:block;' src='"+aditem.ifmurl+"' noresize scrolling=No frameborder=0 marginheight=0 marginwidth=0 allowTransparency='true'></iframe></span>"	
      if(aditem.adv_tmp!="")window.open(aditem.ifmurl,'')
	  aditem.object=document.getElementById(aditem.adv_sid);	  
	  this.items[this.items.length]=aditem;	  
	}	
  this.show = function(){
		adcollection=this.items;
	    for(var i=0;i<adcollection.length;i++){
		var advarr=new Array()
		advarr=adcollection[i].adv_id.split("$")
			for(var k=0;k<advarr.length;k++){
			switch(adcollection[i].adv_st){
	  			case "0":
					if($(advarr[k]))
					{$(advarr[k]).innerHTML=adcollection[i].adhtml}			
					break;
				case "1":	
					document.write(adcollection[i].adhtml)
					break;	
				case "2":                    					
					//var s=document.createElement('script');
                    //s.src=adcollection[i].ifmurl;
                    //document.body.appendChild(s);
                    document.write("<script type='text/javascript' src='"+adcollection[i].ifmurl+"'><\/script>")
                    if(typeof(adv_debug)!="undefined"){if(adv_debug=="1")window.open(adcollection[i].ifmurl,'')}
					break;							
				case "3":                    					
					//var s1=document.createElement('script');
                    //s1.src=adcollection[i].ifmurl;
                    //document.body.appendChild(s1);
                    document.write("<script type='text/javascript' src='"+adcollection[i].ifmurl+"'><\/script>")
                    if(typeof(adv_debug)!="undefined"){if(adv_debug=="1")window.open(adcollection[i].ifmurl,'')}
					break;	
				default:
					if($(advarr[k]))
					{$(advarr[k]).innerHTML=adcollection[i].adhtml}							
					break;				
				  }		
			}	    
    	}     
	}		
  this.hide=function(){
	 adcollection=this.items;
     for(var i=0;i<adcollection.length;i++){
		var advarr=new Array()
		advarr=adcollection[i].adv_id.split("$")
		for(var k=0;k<advarr.length;k++){
			if($(advarr[k])){$(advarr[k]).innerHTML=""}			
			}	    
    	}     
	}	
}

//-->