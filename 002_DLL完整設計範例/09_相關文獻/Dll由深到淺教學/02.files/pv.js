var _ho=window.location.host;
if(_ho.indexOf("52pk.com")!=-1){}else{
	if(typeof(pvhitimgview)=="undefined"){
		var pvhitimgview=true;
		function pv_d(){
			var now = new Date().getTime();
			var datestr=escape(now*1000+Math.round(Math.random()*1000));
			var imgsrc='';
			if(top.location==self.location){
				imgsrc='http://pv.tianjimedia.com/images/pvhit0001.gif?t='+datestr+'&'+document.referrer;
			}else {
				imgsrc='http://pv.tianjimedia.com/images/pvhit0002.gif?t='+datestr+'&'+document.referrer;
			}
			document.write('<div style="width:0px;height:0px"><img border=0 width=1 height=1 src="'+imgsrc+'" style="width:0px;height:0px;margin:0px;padding:0px;clear:none" /></div>');
			_r_h = _ho.replace(".yesky.com","");
		    try{
					if(typeof(v_productid)!="undefined" && _r_h == "product"){
					  (function(){function readcookie(b){var d=document.cookie;var c=d.indexOf(b+"=");if(c==-1){return null}else{start=d.indexOf("=",c)+1;var a=d.indexOf(";",start);if(a==-1){a=d.length}return unescape(d.substring(start,a))}}window.onload=sendStsData;function sendStsData(){var c = readcookie("p2pcookie") || "";var a = v_productid || "";if (c!="" && c != a && a != "") {document.cookie = "p2pcookie=" + a + ";max-age=1800;path=/";var d = document.createElement("img");d.id = "stsDataImg";d.src = "http://object.yesky.com/1.gif?&"+c+"&"+a+"&2";document.body.appendChild(d)}else if(c=="" && a!="")document.cookie = "p2pcookie=" + a + ";max-age=1800;path=/";};})();
					}
			}catch(e){}
		}
		pv_d();
	}    
}
