ycn=window.ycnui||{};
ycn.Common=new function(){
	this.lTrim=function(i){return i.replace(/^\s*/,"");};
	this.rTrim=function(i){return i.replace(/\s*$/,"");};
	this.trim=function(i){return this.rTrim(this.lTrim(i));};
	this.getEl=function(i)
	{
		if(!document.getElementById)return false;
		if(typeof i==="string")
		{
			return document.getElementById(i);
		}
		else
		{
			return i;
		}
	};
	this.getElByClassName=function(t,n,s,el)
	{
		var el=(el)?el:document;
		var itm=el.getElementsByTagName(t);
		var num=1;
		for(i=0;i<itm.length;i++)
		{
			if(itm[i].className===n&&s===num)
			{
				return itm[i];
			}
			else if(itm[i].className===n)
			{
				num++;
			}
		}
		return false;
	};
	this.isIE6=function()
	{
		return navigator.userAgent.search('MSIE')>0&&navigator.userAgent.search('6')>0;
	}
	this.isIE=function()
	{
		return navigator.userAgent.search('MSIE')>0;
	}
	this.isOpera=function()
	{
		return navigator.userAgent.indexOf('Opera')>-1;
	}
	this.isMoz=function()
	{
		return navigator.userAgent.indexOf('Mozilla/5.')>-1;
	}
	this.setCookie=function(cn,cv,d,dm)
	{
		var now=new Date();
		var expire=new Date();
		if(d==null||d==0)d=1;
		expire.setTime(now.getTime()+3600000*24*d);
		document.cookie=cn+"="+escape(cv)+";expires="+expire.toGMTString()+";domain="+dm;
	}
	this.deleteCookie=function(cn,dm)
	{
		if(getCookie(cn))
		{
			document.cookie=cn+"="+((domain)?"; domain="+dm:"")+"; expires=Thu,01-Jan-70 00:00:01 GMT";
		}
	}
	this.getCookie=function(cn)
	{
		var dc=document.cookie;
		var prefix=cn+"=";
		var begin=dc.indexOf("; "+prefix);
		if(begin==-1)
		{
			begin=dc.indexOf(prefix);
			if(begin!=0)return null;
		}
		else
		{
			begin+=2;
		}
		var end=document.cookie.indexOf(";",begin);
		if(end==-1)
		{
			end=dc.length;
		}
		return unescape(dc.substring(begin+prefix.length,end));
	}
};