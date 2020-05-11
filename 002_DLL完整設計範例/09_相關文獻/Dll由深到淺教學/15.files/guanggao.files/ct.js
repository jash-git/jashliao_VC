function q(s) {return s.replace(/%/g,"%25").replace(/&/g,"%26");}
function u(p) {return typeof(p) == 'undefined';}
function c(o)
{
	try{
		if(o == null || o == top) return 0;
		var e = o.parent.document.getElementsByTagName("iframe");
		if(e != null)
		{
			for(var i = 0; i < e.length; i++)
			{
				if(o.location.href.indexOf(e[i].src) >= 0)
				{
					var w = e[i].width == '' ? e[i].style.width : e[i].width;
					var h = e[i].height == '' ? e[i].style.height : e[i].height;
					w = w.replace("px", "");
					h = h.replace("px", "");
					if (w < 60 || h < 10) return 1;
					break;
				}
			}
		}	
		return c(o.parent);	
	}catch(err) { return 2;}
}
function s()
{
	var r = [];
	r.url = document.referrer;
	r.info = 0; 
	try{
		urls = new Array(window.top.location.href, document.location.href);
		for(var i = 0; i < urls.length; i++)
		{
			try{
				r.url = urls[i].toString();
				break;
			}catch(err){r.info |= 4;}
		}
	}catch(err){r.info |= 8;}
	return r;
}
function tt()
{
	var t = "";
	try {
		t = window.top.document.title.toString();
		t = t.replace(/\(/g,"£¨").replace(/\)/g,"£©").replace(/\"/g,"¡±");
		return t
	}catch(err){}
	try {
		t = document.title.toString();
		t = t.replace(/\(/g,"£¨").replace(/\)/g,"£©").replace(/\"/g,"¡±");
		return t;
	} catch(err){}
	return t;
}
function l(p)
{
	return typeof encodeURIComponent=="function" ? encodeURIComponent(p) :escape(p);
}
function mr(w, h)
{
	var wi = (parseInt(w)/20).toFixed(0);var hi = (parseInt(h)/20).toFixed(0);
	var a = wi.toString() + "_" + hi.toString();
	var arr = new Array();
	arr = ['10_5', '10_13', '12_3', '18_4', '23_3', '28_9', '30_10', '36_4', '36_5', '47_2', '48_3', '9_30', '50_5', '35_4'];
	for(var i=0;i<14;i++)
	{
		if(arr[i]==a)return "http://images.sohu.com/cs/htmlfile/"+a+".html";
	}
	return 0;
}
function sogou()
{
	if (u(sogou_param)) return;
	var sogou_ad_url = "";
	var ct = sogou_param["ct"];
	if (ct == "kwd")
		sogou_ad_url = "http://lu.sogou.com/";
	else
		sogou_ad_url = "http://inte.sogou.com/";
	if (u(ct)) return;
	var path = [{s:"matrix",p:"cpc_matrix"},{s:"context",p:"cpc_ads"},{s:"searchframe",p:"cpc_search"}, {s:"textlink",p:"textlink"},{s:"kwd",p:"kwd"}];
	for (var i = 0; i < path.length; i++)
	{
		if (ct == path[i].s)
		{
			sogou_ad_url += path[i].p;
			break;
		}
		if (i == (path.length - 1)) return;
	}
	var param_cnt = 0;
	var r = s();
	var t = c(self);
	var d = r.info | t;
	if (d != 0) sogou_param["orz"] = d.toString();
	if (typeof (sogou_param["kwd"]) != 'undefined') sogou_param["ti"] = sogou_param["kwd"].substring(0, 60);
	else if (d == 0) sogou_param["ti"] = tt().substring(0, 50);
	if (d == 0) {if(top==self) sogou_param["ref"] = (document.referrer).toString().substring(0, 256);}
	sogou_param["sohuurl"] = r.url.toString().substring(0, 512);
	if (sogou_param["iw"] < 60) sogou_param["iw"] = "60";
	if (sogou_param["ih"] < 15) sogou_param["ih"] = "15";

	for(var p in sogou_param)
	{
		if(typeof(sogou_param[p]) == "string" && p != "kwd")
		{
			if (p == "ti") {
				e_s = l(sogou_param[p]);
			} else {
				e_s = q(sogou_param[p]);
			}
			sogou_ad_url += (param_cnt++ ? "&" : "?") + q(p) + "=" + e_s;
		}
	}
	if (typeof(document.sogou_cts)=="undefined") document.sogou_cts = 0;else document.sogou_cts++;
	var ret_str = '<iframe id=\"cttbss'+document.sogou_cts+'\" onload="document.cc'+document.sogou_cts+'=true;" marginwidth="0" marginheight="0" frameborder="0" scrolling="no" allowtransparency="true" src="' + sogou_ad_url + '" width="' + sogou_param["iw"] + '" height="' + sogou_param["ih"] +'"></iframe>';
	if (u(sogou_param["nw"])) {document.write(ret_str);
	if(typeof(document.toctpb)=="undefined")document.toctpb=new Array();
	document.ctmrstr = mr(sogou_param["iw"], sogou_param["ih"]);
	ststr = '(function(){if(!document.cc'+document.sogou_cts+'){if(document.ctmrstr!=0){document.getElementById(\"cttbss'+document.sogou_cts+'\").src=\"'+document.ctmrstr + '\";}var _aa_p=new Image();_aa_p.src = \"http://wb.brand.sogou.com/ct_pv?pid='+ sogou_param["pid"]+ '\";document.toctpb.push(_aa_p)}}())';
	if(sogou_param["noto"] != 1)
		window.setTimeout(ststr, 5000);}
	return ret_str;	
}

sogou();
