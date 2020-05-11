function init_loginAndEmail()
{
	var logind=ycn.Common.getEl('login');
	var emaild=ycn.Common.getEl('email');
	var emailfClose = ycn.Common.getEl('emailfClose');
	var loginfClose = ycn.Common.getEl('loginfClose');

	logind.style.cursor="hand";
	emaild.style.cursor="hand";

	ycn.Event.addEvent(logind,'click',displayDiv);
	ycn.Event.addEvent(emaild,'click',displayDiv);

	emailfClose.style.cursor="hand";
	loginfClose.style.cursor="hand";
	ycn.Event.addEvent(emailfClose,'click',closeDiv);
	ycn.Event.addEvent(loginfClose,'click',closeDiv);
	
}

function GetDefineX(ObjectID)   
{   
	var iPositionX=ObjectID.offsetLeft;   
	while(ObjectID=ObjectID.offsetParent)   
	{   
		iPositionX+=ObjectID.offsetLeft;   
	}   
	return iPositionX;   
}  

function GetDefineY(ObjectID)   
{   
	var iPositionY=ObjectID.offsetTop;   
	while(ObjectID=ObjectID.offsetParent)   
	{   
	    iPositionY+=ObjectID.offsetTop;   
	}   
	return iPositionY;   
}

function displayDiv()
{
	if(ycn.Common.isIE()){var el=window.event.srcElement;}else{var el=this;}

	var disDiv = ycn.Common.getEl(el.id+"f");
	hidD();
	
	posX= GetDefineX(el);
	posY= GetDefineY(el);

	var body = document.getElementsByTagName("body")[0];
	ycn.Event.addEvent(body,'click',hiddenDiv);
	
	disDiv.style.visibility="visible";
	disDiv.style.display="block";

	if(el.id=="login"){
		disDiv.style.left = posX-23;
		disDiv.style.top = posY-5;

		var personT = ycn.Common.getEl('personT');
		var corpT = ycn.Common.getEl('corpT');
		personT.className = "dl1";
		corpT.className = "dl01";

		
//		var yzimg = ycn.Common.getEl('yzimg');
//		yzimg.src = "http://sso.it168.com/sso/Image";
		
		
		var login_con = ycn.Common.getEl('login_con');
		var personT_con = ycn.Common.getEl('person_login_con');
		login_con.innerHTML = personT_con.innerHTML;
	}
	else if(el.id=="email"){
		disDiv.style.left = posX-110;
		disDiv.style.top = posY-5;
	}
	
}

function hiddenDiv(evt)
{
	if(ycn.Common.isIE()){var el=window.event.srcElement;}else{var el=evt.target;}

	if(el.id=="login" || el.id=="email")
	{
		return;
	}
	
	
	while(el.id.toLowerCase()!='emailf' && el.id.toLowerCase()!='loginf' && el.tagName.toLowerCase()!='body')
	{
		el=el.parentNode;
	}
	
	if(el.id=='' && el.id!="emailf" && el.id!="loginf")
	{
		hidD();
	}
}

function hidD()
{
	var disDiv = ycn.Common.getEl("emailf");
	var disDiv2 = ycn.Common.getEl("loginf");


	if(disDiv.style.visibility=="visible" || disDiv.style.display=="block")
	{
		disDiv.style.visibility="hidden";
		disDiv.style.display="none";
	}

	if(disDiv2.style.visibility=="visible" || disDiv2.style.display=="block")
	{
		disDiv2.style.visibility="hidden";
		disDiv2.style.display="none";
	}
	
}


function init_loginTab()
{
	var personT = ycn.Common.getEl('personT');
	var corpT = ycn.Common.getEl('corpT');

	ycn.Event.addEvent(personT,'mouseover',changeLoginType);
	ycn.Event.addEvent(corpT,'mouseover',changeLoginType);
}

function changeLoginType(evt)
{
	if(ycn.Common.isIE()){var el=window.event.srcElement;}else{var el=evt.target;}
	
	var personT = ycn.Common.getEl('personT');
	var corpT = ycn.Common.getEl('corpT');
	if(el.className != "dl1")
	{
		personT.className ="dl01";
		corpT.className = "dl01";

		el.className= "dl1";

		var login_con = ycn.Common.getEl('login_con');

		if(el.id =="personT")
		{
			var personT_con = ycn.Common.getEl('person_login_con');
			login_con.innerHTML = personT_con.innerHTML;
		}
		else
		{
			var corp_con = ycn.Common.getEl('corp_login_con');
			login_con.innerHTML = corp_con.innerHTML;
		}
	}

}

function closeDiv(evt)
{
	if(ycn.Common.isIE()){var el=window.event.srcElement;}else{var el=evt.target;}
	var temp = ycn.Common.getEl(el.id.replace("Close",""));
	temp.style.visibility="hidden";
	temp.style.display="none";
}