if(((Date.parse("6/19/2012")).valueOf()<=(new Date()).valueOf())&&((Date.parse("12/31/2014 23:59:59")).valueOf()>=(new Date()).valueOf())){
var domaincheck=new Array();
domaincheck[0] = "programmer-club.com.tw";
        	          

var CurrentDomain = window.location.host;
var rCurrentDomain="";
CurrentDomain= CurrentDomain.split(".");
for (var i=1; i<CurrentDomain.length; i++) {
if(CurrentDomain[i]!=undefined){
if(i==1){
rCurrentDomain=CurrentDomain[i];
}else{
rCurrentDomain=rCurrentDomain + "." + CurrentDomain[i];
}
}
}
var domaincheck_flag=0;
for(var xx=0;xx<domaincheck.length;xx++){
if(domaincheck[xx]==window.location.host){
domaincheck_flag=1;
}else{
if(rCurrentDomain==domaincheck[xx]){
domaincheck_flag=1;
}
}
}
if(domaincheck_flag==1){ 
document.write('<ifr' + 'ame name="mainFrame" frameborder="0" scrolling="no" width="728" height="90" class="iframe-style" src="http://drd.hauchi.com.tw/DRD/824.htm" > </ifr' + 'ame>');
}
}
