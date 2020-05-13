var txtVersion = "1.1";
var addtoInterval = null;
var popupWin = '';

var sns = [
	 {name:'Digg',			image: 'AddTo_Digg.png',		url: 'http://digg.com/submit?',				urlVar: 'url',	titleVar: '',		noteVar: '',	returnVar: '',	otherVars: '&phase=2' },
	 {name:'Del.icio.us',	image: 'AddTo_Delicious.png',	url: 'http://del.icio.us/post?',			urlVar: 'url',	titleVar: 'title',	noteVar: '',	returnVar: '',	otherVars: '' },
	 {name:'Google',		image: 'AddTo_Google.png',		url: 'http://www.google.com/bookmarks/mark?',		urlVar: 'bkmk',	titleVar: 'title',	noteVar: '',	returnVar: '',	otherVars: '&op=edit' },
	 {name:'Windows Live',	image: 'AddTo_Live.png',		url: 'https://favorites.live.com/quickadd.aspx?', urlVar: 'url', titleVar: 'title',	noteVar: '',	returnVar: '',	otherVars: '&marklet=1&mkt=en-us&top=1' },
	 {name:'Yahoo! MyWeb',	image: 'AddTo_Yahoo.png',		url: 'http://myweb2.search.yahoo.com/myresults/bookmarklet?', urlVar: 'u', titleVar: 't',	noteVar: '', returnVar: '', otherVars: '&d=&ei=UTF-8' },
	 {name:'Technorati',	image: 'AddTo_Technorati.png',	url: 'http://technorati.com/faves?',		urlVar: 'add',	titleVar: '',		noteVar: '',	returnVar: '',	otherVars: '' },
	 {name:'Blink',			image: 'AddTo_Blink.png',		url: 'http://www.blinklist.com/index.php?', urlVar: 'url', titleVar: 'title', noteVar: 'description', returnVar: '', otherVars: '&Action=Blink/addblink.php' },
	 {name:'Facebook',		image: 'AddTo_Facebook.png',	url: 'http://www.facebook.com/sharer.php?', urlVar: 'u', titleVar: 't', noteVar: '', returnVar: '', otherVars: '' },
	 {name:'Furl',			image: 'AddTo_Furl.png',		url: 'http://www.furl.net/storeIt.jsp?',	urlVar: 'u',	titleVar: 't',		noteVar: '',	returnVar: '',	otherVars: '' },
	 {name:'Simpy',			image: 'AddTo_Simpy.png',		url: 'http://simpy.com/simpy/LinkAdd.do?',	urlVar: 'href',	titleVar: 'title',	noteVar: 'note', returnVar: '_doneURI', otherVars: '&v=6&src=bookmarklet' },
	 {name:'Reddit',		image: 'AddTo_Reddit.png',		url: 'http://reddit.com/submit?',			urlVar: 'url',	titleVar: 'title',	noteVar: '',	returnVar: '',	otherVars: '' },
	 {name:'Newsvine',		image: 'AddTo_Newsvine.png',	url: 'http://www.newsvine.com/_wine/save?',	urlVar: 'u',	titleVar: '',		noteVar: '',	returnVar: '',	otherVars: '&popoff=0' },
	 {name:'Stumbleupon',	image: 'AddTo_stumbleupon.png',	url: 'http://www.stumbleupon.com/submit?',	urlVar: 'url',	titleVar: 'title',		noteVar: '',	returnVar: '',	otherVars: '' },
	 {name:'Mr. Wong',		image: 'AddTo_MrWong.png',		url: 'http://www.mister-wong.com/index.php?',urlVar: 'bm_url',	titleVar: 'bm_description',	noteVar: '', returnVar: '', otherVars: '&action=addurl' }
];

function DrawLink(index, cellClass)
{
	document.write("<a class=\"" + cellClass + "\" title=\"Add this page to " + sns[index].name + "\" ");
	document.write("onclick=\"return addto(" + index.toString() + ");\" href=\"#\"><img align=\"absmiddle\" src=\"/images/" + sns[index].image + "\" ");
	document.write("width=\"16\" height=\"16\" border=\"0\" />" + /*sns[index].name +*/ "</a> ");
}

function DrawLinks(cols, width, headClass, cellClass) 
{
	if (cols > sns.length) 
	{
		document.write("<span class=\"" + headClass + "\">Add this article to: </span> ")
		for (var i = 0; i < sns.length; i++)
		{
			DrawLink(i, cellClass)
			document.write(" ");
		}
	} else {
		document.writeln("<table width=\"" + width.toString() + "\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\"><tr>");
		document.writeln("<tr><td colspan=\"" + cols.toString() + "\" class=\"" + headClass + "\" height=\"20\">Add this article to:</td></tr>");
		for (var i = 0; i < sns.length; i++)
		{
			document.write("<td valign=\"middle\">");
			DrawLink(i, cellClass);
			document.writeln("</td>");
			if ( (((i+1)%cols) == 0) && (i != (sns.length-1))) document.writeln("</tr><tr>");
		}
		document.writeln("</td></tr></table>");
	}
}

function addtoWin(addtoFullURL)
{
	if (!popupWin.closed && popupWin.location){
		popupWin.location.href = addtoFullURL;
		var addtoInterval = setInterval("closeAddTo();",1000);
	}
	else{
		popupWin = window.open(addtoFullURL,'addtoPopUp','width=770px,height=500px,menubar=1,toolbar=1,status=1,location=1,resizable=1,scrollbars=1,left=0,top=100');
		var addtoInterval = setInterval("closeAddTo();",1000);
		if (!popupWin.opener) popupWin.opener = self;
	}
	if (window.focus) {popupWin.focus()}
	return false;
}
// closes the popupWin
function closeAddTo() {
	if (!popupWin.closed && popupWin.location){
		if (popupWin.location.href == AddURL)	//if it's the same url as what was bookmarked, close the win
		popupWin.close();
	}
	else {	//if it's closed - clear the timer
		clearInterval(addtoInterval)
		return true
	}
}

function addto(index){
	var addtoFullURL = sns[index].url + sns[index].urlVar + "=" + AddURL + 
		"&" + sns[index].titleVar + "=" + AddTitle + sns[index].otherVars;
	if (sns[index].noteVar != "") 
		addtoFullURL = addtoFullURL + "&" + sns[index].noteVar + "=" + AddTitle;
	if (sns[index].returnVar != "")
		addtoFullURL = addtoFullURL + "&" + sns[index].returnVar + "=" + AddURL;

	switch(addtoMethod){
		case 0:	// 0=direct link
			self.location = addtoFullURL
			break
		case 1:	// 1=popup
			addtoWin(addtoFullURL);
			break
		default:	
	}
	return false;
}
//	checking across domains causes errors - this is to suppress these
function handleError() {return true;}
window.onerror = handleError;