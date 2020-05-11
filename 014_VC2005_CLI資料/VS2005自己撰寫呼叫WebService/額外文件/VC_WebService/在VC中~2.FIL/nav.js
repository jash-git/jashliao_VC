function init_Nav()
{

	var nav1 = ycn.Common.getEl('Nav1');
	var navMenu1 = ycn.Common.getEl('Nav1Menu');

	ycn.Event.addEvent(nav1,'click',disMenu);
	ycn.Event.addEvent(navMenu1,'mouseover',disMenu);

	ycn.Event.addEvent(nav1,'mouseout',hidMenu);
	ycn.Event.addEvent(navMenu1,'mouseout',hidMenu);
}


function disMenu(evt)
{
	if(ycn.Common.isIE()){var el=window.event.srcElement;}else{var el=evt.target;}
	while(el.id == "")
	{
		el = el.parentNode
	}
	
	var navMenu = ycn.Common.getEl(el.id.substring(0,4) + "Menu");
	navMenu.style.visibility="visible";
}

function hidMenu(evt)
{
	if(ycn.Common.isIE()){var el=window.event.srcElement;}else{var el=evt.target;}
	while(el.id == "")
	{
		el = el.parentNode
	}

	var navMenu = ycn.Common.getEl(el.id.substring(0,4) + "Menu");
	navMenu.style.visibility="hidden";
}






function SetCookie() {
	var cookieValue="it168";
	var cookieName="it168tag";
	var today = new Date();
	var expire = new Date();
	expire.setTime(today.getTime() + 3600000*24*1); 
	document.cookie = cookieName+"="+escape(cookieValue) + ";path=/;domain=.it168.com;expires="+expire.toGMTString();
}

SetCookie();
