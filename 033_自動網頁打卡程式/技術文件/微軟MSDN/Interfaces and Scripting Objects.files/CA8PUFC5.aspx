

function jsTrim(s) {return s.replace(/(^\s+)|(\s+$)/g, "");}

function Track(trackParm, objLink)
{
    if (objLink.innerText && jsTrim(objLink.innerText))
    {
        // anchor tag, use link text
        LinkText = objLink.innerText;
    }
    else if (objLink.all && objLink.all(0).alt)
    {
        // image, use alt text
        LinkText = objLink.all(0).alt;
    }
         
    var strDomain = document.domain;
    var s = trackParm.split("|");
    var strLinkArea;
    var strLinkId;
    var strPageRegion;
    
    if (trackParm.substring(0,1) == "|")
    {
        strPageRegion = s[1];
        strLinkArea = s[2];
        strLinkId = s[2] + s[3];
    }
    else
    {
            strLinkArea = s[0];
        strLinkId = s[0] + s[1];

    }
    
    if (typeof(LinkText)=="undefined" || !LinkText || LinkText == "")
        LinkText = strLinkId;

    ctUrl = objLink.href + "?LinkId=" + strLinkId + "&LinkArea=" + strLinkArea 

    if (typeof(DCSext)!="undefined") 
    {
            DCSext.wt_strHeadlnLocale = detectedLocale;
            DCSext.wt_strCat=strLinkArea+"|"+detectedLocale;
            DCSext.wt_strUrl = window.location.href.toLowerCase();
            DCSext.wt_strArea = strPageRegion;
    }
        return false; 
}











function TFly_Init(name,  offsetLeft, offsetTop, alignment, anyIter, anyTime, staticHover, popupHover, popupLatency, hideLatency, onInit, onPopup, onHide){
  var TFly = document.getElementById(name); 
  TFly.alignment = alignment;
  TFly.DT = document.getElementById(name+"_Popup")
  TFly.F = document.getElementById(name+"_Anim")
  
  TFly.oX = offsetLeft
  TFly.oY = offsetTop;

  TFly.AnyIter = anyIter;
  TFly.AnyTime = anyTime;

  TFly.popupLatency = popupLatency;
  TFly.hideLatency = hideLatency;
  TFly.onPopup = onPopup;
  TFly.onHide = onHide;
  
  TFly.IsHover=false;
  
  TFly.className_ = TFly.className;
  TFly.DT.className_=TFly.DT.className
  
  TFly.onmouseover = function(){TFly.IsHover=true; if(staticHover!=''){TFly.className=staticHover}; TFly_Popup(TFly,true);}
  TFly.onmouseout = function(){if(staticHover!=''){TFly.className=TFly.className_};TFly_Popup(TFly,false);TFly.DT.blur();TFly.IsHover=false;}

  if(document.all){
    TFly.onactivate = function(){if(!TFly.IsHover)TFly.onmouseover();}
    TFly.ondeactivate = function(){TFly.onmouseout();}
  }else{
    TFly.onfocus = function(){TFly.onmouseover()}
    TFly.onblur = function(){TFly.onmouseout()}
  }
 
 
  TFly.DT.onmouseover = function(){ TFly.IsHover=true; if(popupHover!=''){TFly.DT.className=popupHover;};TFly_Popup(TFly,true);}
  TFly.DT.onmouseout = function(){ if(popupHover!=''){TFly.DT.className=TFly.DT.className_};TFly_Popup(TFly,false);TFly.IsHover=false; }

  TFly_CallClientFunction(onInit, TFly)
}

function TFly_Reposition(TFly){
  var clientWidth = document.body.clientWidth - 20; //scroller width
  var width = TFly.DT.offsetWidth;
  var absX = TFly.DT.offsetLeft 
  var d = TFly.DT
  while(d = d.offsetParent)
    absX += d.offsetLeft

  if(clientWidth<(absX+width)){
   var diff = clientWidth - absX -width
   TFly.DT.style.left = TFly.DT.offsetLeft + diff + "px"
  }
}

function TFly_CallClientFunction(name, TFly){
    if(name!=null &&  name!="")
      eval( name + "(TFly);");
}

function TFly_SetPosition(TFly, obj){
  obj.style.top = TFly.oY + TFly.offsetHeight+ "px";
  obj.style.left = TFly.oX + (TFly.offsetWidth - obj.offsetWidth )*(1+TFly.alignment)/2 + "px";
}

function TFly_Popup(TFly,value){
  if(TFly.timer!=null ) window.clearTimeout(TFly.timer)
  if(value){
    if(TFly.status=="on") return
    var timeout = (TFly.status=="active") ? 0 : TFly.popupLatency
    if(TFly.AnyIter>0 && TFly.AnyTime>0)
      TFly.timer = window.setTimeout(function(){TFly_AnimateStart(TFly,true,TFly.F.curIter);},timeout)
    else
      TFly.timer = window.setTimeout(function(){TFly_SetVisibility(TFly,true);},timeout)
  }else{
    if(TFly.status=="off") return
    var timeout = (TFly.status=="active") ? 0 : TFly.hideLatency
    if(TFly.AnyIter>0 && TFly.AnyTime>0)
      TFly.timer = window.setTimeout(function(){TFly_AnimateStart(TFly,false,TFly.F.curIter);},timeout)
    else
      TFly.timer = window.setTimeout(function(){TFly_SetVisibility(TFly,false);},timeout)
  }
}

function TFly_SetVisibility(TFly, value){
      if(value==true){
        TFly_SetPosition(TFly,TFly.DT);
        TFly.DT.style.visibility = "visible"
        TFly.style.zIndex = "999"
        TFly_Reposition(TFly);
      }else{
        TFly.DT.style.visibility = "hidden"
        TFly.style.zIndex = "0"
        TFly.DT.style.left = "-10000px"
      }
}

function TFly_AnimateStart(TFly, inout, curIter){
    if(TFly.F.timer!=null) window.clearTimeout(TFly.F.timer);
    if(curIter==null) curIter=0;
    if(TFly.status !="active"){
        TFly.status ="active";
        TFly.F.style.visibility = "visible";
        TFly.DT.style.visibility="hidden";
    }
    if(curIter<0 || curIter>TFly.AnyIter ){
        TFly.F.curIter = (curIter<1) ? 0 : TFly.AnyIter;
        TFly.status = (TFly.F.curIter==TFly.AnyIter) ? "on": "off";
        TFly.F.style.visibility = "hidden";
        TFly_SetPosition(TFly,TFly.DT);
        TFly.style.zIndex=(TFly.F.curIter==TFly.AnyIter) ? "999" : "0";
        if(TFly.F.curIter==TFly.AnyIter){
          TFly.status = "on";
          TFly_SetVisibility(TFly,true);
          TFly_CallClientFunction(TFly.onPopup, TFly)
        }else{
          TFly.status = "off";
          TFly_SetVisibility(TFly,false);
          TFly_CallClientFunction(TFly.onHide, TFly)
        }
    }else{
        var per = curIter*(95/TFly.AnyIter)+ 5;
        TFly.F.style.visibility = "hidden";
        TFly.F.style.width=TFly.DT.offsetWidth/100*per + "px";
        TFly.F.style.height=TFly.DT.offsetHeight/100*per + "px";
        TFly_SetPosition(TFly, TFly.F);
        TFly.F.style.visibility = "visible";
        var timeout = (per==100 ) ? 0 : TFly.AnyTime - (TFly.AnyTime/(TFly.AnyIter)*(curIter)); 
        curIter += (inout) ? 1:-1;
        TFly.F.timer = window.setTimeout(function(){TFly_AnimateStart(TFly, inout, curIter)},timeout);
        TFly.F.curIter = curIter;
    }
}




var search_state;
var theForm = document.forms['aspnetForm'];
if (!theForm) {
    theForm = document.aspnetForm;
}

if (window.addEventListener) 
{
    window.addEventListener('load', init, false);
} 
else if (window.attachEvent) 
{
    window.attachEvent('onload', init);
}

function init() 
{
    search_state = theForm.elements["ctl00$NavigationTabStrip$HiddenText"].value;
    
    if (search_state == "active")
    {
        theForm.elements["ctl00$NavigationTabStrip$SearchTextBox"].className = "TabStrip_SearchBoxActive";
    }
}

function onMouseDownSearch()
{
    if (search_state == "default")
    {
          search_state = "active";
          theForm.elements["ctl00$NavigationTabStrip$HiddenText"].value = search_state;
          theForm.elements["ctl00$NavigationTabStrip$SearchTextBox"].value = "";
          theForm.elements["ctl00$NavigationTabStrip$SearchTextBox"].className = "TabStrip_SearchBoxActive";
    }
}

function IsPageRated(objID,labelID, text, flyoutID, btn){
  obj = $get(objID)
  if (obj.Rated)
  { 
    flyout = $get(flyoutID)
    TFly_Popup(flyout,false)
    window.setTimeout(function(){btn.disabled=true}, 100);
    return true;
  }
  else
  {
    label = $get(labelID)
    
    if(label.timer){
      window.clearTimeout(label.timer)
    }else{
      label.className_ = label.className;
      label.innerHTML_ = label.innerHTML;
      label.className = 'WarningMessage';
      label.innerHTML = text;
    }

    label.timer = window.setTimeout(function(){
                            label.className = label.className_;
                            label.innerHTML = label.innerHTML_;
                            label.timer=null;
                         }
                      ,3000);
  }  
  return false;
}

function tbNavParent(navUrl)
{
    window.top.location.href = navUrl;
}
function RegisterAutoSubmit( objName, btnName,tag){
  window.onbeforeunload_autosubmit = window.onbeforeunload;
  window.onbeforeunload = function(){
                                 if(window.onbeforeunload_autosubmit)
                                    window.onbeforeunload_autosubmit()
                                 SubmitRating(objName, btnName,tag)
                              }
}

function SubmitRating(objName, btnName, tag){
  var obj = $get(objName)
  var btn = document.getElementById(btnName)
  if(obj && obj.Rated && btn){
      btn.disabled=false;
      btn.click();
      var d = new Date();
      d.setFullYear(d.getFullYear() +1)
      var CookieInfo = tag + "=" + escape("xxx") + ";expires="+d.toGMTString()+" path=/;"; 
      document.cookie = CookieInfo;
   }
}



var minWidth = 0;
var ideUA = false;
var dragging = false;


function windowLoaded(evt) {
    // prevent IE text selection while dragging!!!
    // Little-known trick!
    document.body.ondrag = function () { return !dragging; };
    document.body.onselectstart = function () { return !dragging; };
}


// CHange the color and image of the splitter bar
function HighlightSplitterBar(strObjName, intOnOff)
{       
    var sliderBar = document.getElementById(strObjName);
	
    if (intOnOff == 0)
    {
        sliderBar.style.backgroundImage ='url(/msdn/controls/resizablearea/en-us/lib_grippy1.gif)';
    }
    else
    {
        sliderBar.style.backgroundImage ='url(/msdn/controls/resizablearea/en-us/lib_grippy.gif)';
    }
   return;
}

//  Main 
//	All global variables written by server control
function DoControlSetup()
{
	minWidth=0;
	this.name = "DoControlSetup";
	
   	if (browser == "Netscape")
	{
        document.addEventListener("onkeypress",KeyPressOpenCloseToc,true);
    }
    document.onkeypress = KeyPressOpenCloseToc;

    FetchResizableAreaCells();
    return;
}

//  Layout the <div> elements based on the client side renderable area
function FetchResizableAreaCells()
{
    winWidth = parseInt(document.body.clientWidth);
    oContainerCell = document.getElementById(sContainerCell);
    oNavCell = document.getElementById(sNavCell);
    oSplitterCell = document.getElementById(sSplitterCell);
    oContentCell = document.getElementById(sContentCell);
    oSplitterCell.style.width = "5px";

    if (GetTocPanelCookie(cookieName) != -1)
    {
        sSplitterDefault = GetTocPanelCookie(cookieName);
    }

	if (oNavCell.style.width != sSplitterDefault)
	{
	    oNavCell.style.width = sSplitterDefault;
	    oSplitterCell.style.left = sSplitterDefault;
	    oSplitterCell.style.width = "5px";
	    oContentCell.style.left = parseInt(oSplitterCell.style.width) + parseInt(sSplitterDefault) + px;
	}    

    if (winWidth - parseInt(oContentCell.style.left) < minWidth)
    {
    	var newWidth = winWidth-605;
	    if (newWidth < 0)
	    {
    		newWidth = parseInt(oNavCell.style.width);
	    }

	    oNavCell.style.width = newWidth + px;
        oSplitterCell.style.left = oNavCell.style.width;
        oSplitterCell.style.width = "5px";
        oContentCell.style.left = parseInt(oSplitterCell.style.width) + newWidth  + px;
	}
    
    ResizeContentArea();
    return;
}


//  Attach Event Handlers
function SelectSplitter()
{	// Required for Mozilla 1.0, Netscape 7.2
oContainerCell.className = "OverlayShow";
	if (browser == "Netscape")
	{	//	NS4: document.captureEvents(Event.MOUSEMOVE);
        oContainerCell.addEventListener("onmousemove",ResizePanel,true);
        oContainerCell.addEventListener("onmouseup",ReleaseSplitter,true);
	}
	//	IE

//		document.onmousemove = ResizePanel;
//		document.onmouseup = ReleaseSplitter;

	oContainerCell.onmousemove = ResizePanel;
	oContainerCell.onmouseup = ReleaseSplitter;
	dragging = true;
	return;
}

//	Changed to OnMouseMove functionality
function ResizePanel(e)
{
// oSplitterCell
	var contentSizeLimit;

	if (browser == "Netscape")
	{
		e.cancelBubble = true;
		splitterX = e.pageX;
    }
	else
	{
	    window.event.cancelBubble = true;
		if (window.event.clientX - 4 < 0)
		{
		    splitterX = 0;
		}
		else
		{
		    splitterX = window.event.clientX - 4;
		}
	}

  window.status = splitterX
  sSplitterCookieX =splitterX
  
      //  alert("sSplitterCookieX = " + sSplitterCookieX);
    if (parseInt(sSplitterCookieX) == 0)
    {
       DisableTocPanel(true);
    }
    else
    {
       DisableTocPanel(false);       
    }  

//    oNavCell.style.width = parseInt(sSplitterCookieX) + px;
    oSplitterCell.style.left = parseInt(sSplitterCookieX) + px;
//    oContentCell.style.left = sSplitterCookieX + parseInt(oSplitterCell.style.width) + px;
//    ResizeContentArea();

	return;
}

//	Changed to OnMouseUp functionality
function ReleaseSplitter()
{
    oContainerCell.className = "OverlayHidden";

    //  alert("sSplitterCookieX = " + sSplitterCookieX);
    if (parseInt(sSplitterCookieX) < 1)
    {
       DisableTocPanel(true);
    }
    else
    {
       DisableTocPanel(false);       
    } 
    sTmpNavCellWidth = parseInt(sSplitterCookieX) + px;
    oNavCell.style.width = parseInt(sSplitterCookieX) + px;
    oSplitterCell.style.left = parseInt(sSplitterCookieX) + px;
    oContentCell.style.left = sSplitterCookieX + parseInt(oSplitterCell.style.width) + px;
    ResizeContentArea();
	SetTocPanelCookie(cookieName,oNavCell.style.width, days);
	oContainerCell.onmousemove = null;
	oContainerCell.onmouseup = null;
	dragging = false;
	return;
}

//	ONKEYPRESS:
//	CHECK WHICH KEYS HAVE BEEN PRESSED
//	IF A MATCH IS FOUND, SHOW/HIDE TOC PANEL
function KeyPressOpenCloseToc(e)
{
    if (browser == "Netscape")
	{	//     //   alert(e.which + "\n" + e.target.tagName);
		if (e.which == 116)
		{
		    if (e.target.tagName.toLowerCase() != "input" && e.target.tagName.toLowerCase() != "textarea" )
		    {
		        OpenClosePanel();
            }
			e.cancelBubble = true;
		}
	}
	else if(window.event.keyCode == 116)
	{   
		if (window.event.srcElement.tagName.toLowerCase() != "textarea" && window.event.srcElement.tagName.toLowerCase() != "input")
		{
		    OpenClosePanel();
		}
		window.event.cancelBubble = true;
	}
	return;
}

//  This function enables/disabled the nodes in the TOC, 
//  depending on the state/size of the TOC panel.
function DisableTocPanel(boolEnabled)
{
    var tocPanel = document.getElementById(TocPaneNameId);
    if(tocPanel.disabled == "undefined")
    {
        tocPanel.disabled = boolEnabled;
    }
    
    if(tocPanel.style.display == "none" && boolEnabled == true)
    {
        boolEnabled == false;
    }  
   
    if (boolEnabled == true )
    {
        tocPanel.disabled = true;
        tocPanel.style.display = "none";
    }
    else
    {
        tocPanel.disabled = false;
        tocPanel.style.display = "inline";
    }
     if(tocOpenCollapseHandler!=null  && typeof(tocOpenCollapseHandler)=="function")
     {
        tocOpenCollapseHandler(boolEnabled);
     };
    
    return; 
}


//  Simple Hide/Show Functionality
//  Need to add cookie setting
//  Add CSS ClassName change for ContentPanel
function OpenClosePanel()
{
    //  alert(oNavCell.style.width + "\n" + sTmpNavCellWidth);
    if (oNavCell.style.width != "0px")
    {
        sTmpNavCellWidth = oNavCell.style.width;
        oNavCell.style.width = "0px";
        oContentCell.style.left = parseInt(oSplitterCell.style.width) + px;
        oSplitterCell.style.left = "0px";
        DisableTocPanel(true);
    }
    else if ( (oNavCell.style.width == "0px" && sTmpNavCellWidth == undefined) ||  (oNavCell.style.width == "0px" && sTmpNavCellWidth == "0px"))
    {
        oNavCell.style.width = "250px";
        oSplitterCell.style.left = "250px";
        sTmpNavCellWidth = oNavCell.style.width;
        oContentCell.style.left = parseInt(oNavCell.style.width) + parseInt(oSplitterCell.style.width) + px;
        DisableTocPanel(false); 
    }
    else
    {
        oNavCell.style.width = sTmpNavCellWidth;
        oSplitterCell.style.left = sTmpNavCellWidth;
        oContentCell.style.left = parseInt(oNavCell.style.width) + parseInt(oSplitterCell.style.width) + px;
        DisableTocPanel(false);
    }

    if (winWidth - parseInt(oContentCell.style.left) < minWidth)
    {
	    var newWidth = winWidth - minWidth - 5;
	    if (newWidth < 0)
	    {
            if (parseInt(oNavCell.style.width) > 76)
            {
		        newWidth=76;
            } 
	        else
	        {
		        newWidth = parseInt(oNavCell.style.width);
            } 
	    }
	    oNavCell.style.width = newWidth + px;
        oSplitterCell.style.left = oNavCell.style.width;
        oSplitterCell.style.width = "5px";
        oContentCell.style.left = parseInt(oSplitterCell.style.width) + newWidth  + px;
    }

    SetTocPanelCookie(cookieName,oNavCell.style.width, days);
    ResizeContentArea();
    return;
}

//  Change the size of the Content container
function ResizeContentArea()
{
    if (winWidth - parseInt(oContentCell.style.left) < minWidth)
    { 
        oContentCell.style.width = minWidth + px;
    } 
    else
    { 
	    oContentCell.style.width = winWidth - parseInt(oContentCell.style.left)  + px;
    } 
    return;
}

/*
------------------------------------------
Cookies and Misc Functions
-------------------------------------
*/
// Set cookie on each event
// Function to set the Toc panel size
// Browser must support cookies and script
function SetTocPanelCookie(sName, sValue, days)
{
    if (window.navigator.cookieEnabled == true)
    {
	    var expires = ";";
	    if (days > 0)
	    {
            var cookieDate = new Date();
		    cookieDate.setTime(cookieDate.getTime()+(days*24*360000));
            expires = "; expires=" + cookieDate.toGMTString();
	    }
        var CookieInfo = sName + "=" + escape(sValue) + "; expires=-1" + "; path=/"; 
        document.cookie = CookieInfo;

        var CookieInfo = sName + "=" + escape(sValue) + expires + "; path=/"; 
        document.cookie = CookieInfo;
   }
   return;
}

// Function to get the Toc panel size
// Browser must support cookies and script
// Special for VS, by default do not show the TOC on first instance,
// and support the cookie state on subsquent pages
function GetTocPanelCookie(sName)
{    
    var currentTocWidth = -1;
	var allCookie = String(document.cookie);
	var pos = allCookie.indexOf(sName);
    //  alert(window.history.length);
    
    if (document.referrer == "" && ideUA == true && window.history.length == 0)
	{  
	    SetTocPanelCookie(cookieName, "0px", days);
	    return currentTocWidth;
    }
    else
    {     
	    if (pos != -1 )
	    {
            var tocValue = allCookie.split("; ");

            for (i = 0 ; i < tocValue.length; i++)
            {
	            var cookieValue = tocValue[i].split("=");
	            if (sName == cookieValue[0])
	            {
		            currentTocWidth = cookieValue[1];
		            break;
	            }
            }
	    }
	}
	return currentTocWidth;
}


function TocLoader_HideMessage(){
  document.getElementById("tocLoadingMessage").style.display = "none";
}


function EyeBrowMenuBarSetHeight(TFly){
  var maxHeight = 200;
  var overflow = (TFly.DT.clientHeight > maxHeight);
    TFly.DT.style.height = ((overflow) ? maxHeight : TFly.DT.scrollHeight) + "px";
    TFly.DT.style.width = TFly.DT.scrollWidth + ((overflow) ? 20 :0) + "px";
  if(overflow) TFly.DT.style.overflow="auto"
}



var expcalallPres = true;
var cleanedDivIds, cleanedImgIds, oExpColSpan, oExpColImg;
var expState = true;

function ExpCollAll()
{
   expcalallPres = true;
   expCollButtonToggle();  
   cleanImgVars();
   
   for (i = 0; i < cleanedDivIds.length; i++)
   {
        try
        {
            oDiv = document.getElementById(cleanedDivIds[i]);
            oImg = document.getElementById(cleanedImgIds[i]);
            
            if (expState)
            {
                oDiv.style.display = 'block';
                oImg.src = CollPath;
            }
            else
            {
                oDiv.style.display = 'none';
                oImg.src = ExpPath;
            }
        }
        catch(e)
	    {
	    }
   }
}

function expCollButtonToggle()
{
   
   if (typeof(oExpColSpan)=='undefined')
   {
        oExpColImg = document.getElementById("ExpColImg");
        oExpColSpan = document.getElementById("ExpColSpan");
   }
   
   if (expState)
   {
        oExpColImg.src = ExpPath;
        oExpColSpan.innerHTML = ExpText;
        expState = false;
   }
   else
   {
        oExpColImg.src = CollPath;
        oExpColSpan.innerHTML= CollText;
        expState = true;
   }
}

var b = window.navigator.appName;
var spr = " : ";

//	Show the languages list in the it's panel
function DDFilterOn(e)
{   
	try
	{
		//	Change Image
		ChangeDropDownImage(true);
		//	Set Position
		oMTPS_DD_PopUpDiv.style.top = oMTPS_DD_ImgArrow.height;
		
		//	Add Event Handlers
		if(oMTPS_DD_PopUpDiv.style.display != "inline")
		{
			oMTPS_DD_PopUpDiv.style.display = "inline";

            if(document.addEventListener)
            {       //  Commented for # 32609
				    //  document.addEventListener("keydown", HandleEvent, false);
				    document.addEventListener("click", TestForResizableAreaControl, false);
				    window.addEventListener("resize", TestForResizableAreaControl, false);			
            } 
            else
            { 
				    document.attachEvent("onkeydown", HandleEvent, false);
       				document.body.onclick = HideFromClick;	
            } 

		}
		else
		{
			//	oMTPS_DD_PopUpDiv.style.display = "none";
			setTimeout(HideThisMenu, 0);			
		}
		
	}
	catch(err)
	{
		throw err;
	}
	e.cancelBubble = true;
	oMTPS_DD_Div.normalize();
	return;
}

// Handle the enter key for a section of a form, binding it to the provided submit buton 
function HandleEvent(event)
{ 
    var nav = window.Event ? true : false; 
    if (nav) { 
        return NetscapeEventHandler(event); 
    } else { 
        return MicrosoftEventHandler(); 
    } 
} 

function NetscapeEventHandler(e)
{ 
//trap for enter (13), escape (27) and "t" (84)
    if ((e.which == 13 || e.which == 27 || e.which == 84) && e.target.type != 'textarea' && e.target.type != 'submit')
     { 
		setTimeout(HideThisMenu, 0);
		document.removeEventListener("keydown", HandleEvent, false);
		e.cancelBubble = true;
        e.returnValue = false; 
        e.cancel = true; 
        e.preventDefault(); 
    } 
    return; 
} 

function MicrosoftEventHandler() { 
//trap for enter (13), escape (27) and "t" (84)
    if ((event.keyCode == 13 || event.keyCode == 27 || event.keyCode == 84 )&& event.srcElement.type != 'textarea' && event.srcElement.type != 'submit') { 
        event.returnValue = false; 
        event.cancel = true;
    	setTimeout(HideThisMenu, 0);
    	document.detachEvent("onkeydown", HandleEvent, false);
    	event.cancelBubble = true;
    } 
    return; 
}


//	Only used by IE
function HideFromClick(event)
{
	var objClicked = window.event.srcElement;
	var objParent = objClicked.parentNode.parentNode;
	
	if (objParent.id != oMTPS_DD_PopUpDiv.id && objParent.id != oMTPS_DD_Div.id ) 
	{
		setTimeout(HideThisMenu, 0);
		return;
	}
	else
	{
		window.event.cancelBubble = true;
		return;
	}
}

/// FF & NN only
function TestForResizableAreaControl(e)
{
	try
	{
	//	For keydown events
	if (e.type == "keydown")
	{
		//	alert(e.which);
		if (e.which == 84 || e.which == 13)
		{
			setTimeout(HideThisMenu, 0);
			document.removeEventListener("keydown", TestForResizableAreaControl, false);
			e.cancelBubble = true;
			return;
		}
	}
	else if (e.type == "resize")
	{
		setTimeout(HideThisMenu, 0);
		window.removeEventListener("resize", TestForResizableAreaControl, false);
		e.cancelBubble = true;
		return;		
	}
	
	// for mousedown event
		if (e.type == "click")
		{
			if (e.which == 1 || e.which == 32)
			{	
				var eNode = e.target;
				if (eNode.id.length == 0)
				{	//	alert("returning false");
					setTimeout(HideThisMenu, 0);
					document.removeEventListener("click", TestForResizableAreaControl, false);
					return false;
				}
				else
				{
					var pNode = document.getElementById(eNode.id).parentNode.parentNode;
					if (eNode.id != oMTPS_DD_PopUpDiv.id)
					{
						if (pNode.id != oMTPS_DD_PopUpDiv.id)
						{
							setTimeout(HideThisMenu, 0);
							document.removeEventListener("mousedown", TestForResizableAreaControl, false);
						}
					}			
					if (e.target.id == oMTPS_DD_ImgArrow.id)
					{
						setTimeout(HideThisMenu, 0);
						document.removeEventListener("mousedown", TestForResizableAreaControl, false);
					}
					if (e.target.id == oMTPS_DD_PanelLink.id)
					{
						setTimeout(HideThisMenu, 0);
						document.removeEventListener("mousedown", TestForResizableAreaControl, false);
					}
				}
				return;
			}
		}
	}
	catch(err)
	{
		throw err;
	}
}

// Persist Menu long enough for client to click check boxes
function HideThisMenu()
{
	oMTPS_DD_PopUpDiv.style.display = "none";
	oMTPS_DD_ImgArrow.src = ArrowOffPath;
	document.body.onclick = null;
	return;
}

//	Handle Image changes
function ChangeDropDownImage(boolOnOff)
{
	if (boolOnOff == true)
	{
		oMTPS_DD_ImgArrow.src = ArrowOnPath;
	}
	else
	{
		oMTPS_DD_ImgArrow.src = ArrowOffPath;
	}
}


//	Set individual checkbox
function SetLangFilter(CodeSnipID)
{
	try
	{
		if (CodeSnipID != null)
		{
			ToggleLang(CodeSnipID);
			 oServerBool = false;
		}
		
		SetFilterText();	
		SetCodeSnippetLangFilterCookie();	
	}
	catch(err)
	{
		throw err;
	}
	return;
}

//	This method is only for changing the value on the client side
//	The server side code should read the cookie and set the checkbox prior to rendering 
function ToggleLang(strThis)
{
	var langArray = "";
	
	try
	{
		langArray = eval(strThis);
	}
	catch(err)
	{
		//	no script variables where written out by the server side code
		return;
	}
	
	try
	{
		for (i = 0; i < langArray.length; i++)
		{
			var thisCodeSnip = document.getElementById(langArray[i]);
			if (thisCodeSnip.className == "code")
			{
				thisCodeSnip.className = "codeHide";
			}
			else
			{
				thisCodeSnip.className = "code";
			}
		}
	}
	catch(err)
	{
		throw err;
	}
	return;
}


// set filter language test
function SetFilterText()
{
	try
	{
		var intSetoMTPS_DD_PanelLinkText = 0;
		var objLastChecked = null;
		var cbxColl = oMTPS_DD_PopUpDiv.getElementsByTagName("input");
		
		for (var i = 0; i < cbxColl.length;i++)
		{
			if (cbxColl[i].checked == true)
			{
				intSetoMTPS_DD_PanelLinkText++;
				objLastChecked = cbxColl[i].value;
			}
		}
			
		if (intSetoMTPS_DD_PanelLinkText == 0)
		{
			oMTPS_DD_PanelLink.innerHTML = strConstLangFilterText + spr + strConstLangFilterNone;
		}
		if (intSetoMTPS_DD_PanelLinkText == 1)
		{
			oMTPS_DD_PanelLink.innerHTML = strConstLangFilterText + spr + objLastChecked;
		}
		if (intSetoMTPS_DD_PanelLinkText > 1)
		{
			oMTPS_DD_PanelLink.innerHTML = strConstLangFilterText + spr + strConstLangFilterMulti;	
		}
		if (intSetoMTPS_DD_PanelLinkText == oMTPS_DD_PopUpDiv.childNodes.length)
		{
			oMTPS_DD_PanelLink.innerHTML = strConstLangFilterText + spr + strConstLangFilterAll;
		}	
		intSetoMTPS_DD_PanelLinkText = 0;
		objLastChecked = null;
	}
	catch(err)
	{
		throw err;
	}
	return;
}

//	This function redraws the selected code snippet controls,
//	based on the state of the check boxes in the drop down,
//	which is read from the cookie on the server side.
function CheckDropDownClientCookie()
{
	var cbxColl = oMTPS_DD_PopUpDiv.getElementsByTagName("input");
	
	for (var i = 0; i < cbxColl.length;i++)
	{
		if (cbxColl[i].checked != true)
		{
			var tStr = cbxColl[i].getAttribute("arrayValue");
			SetLangFilter(tStr);
		}
	}
	return;
}

// Set cookie on each event
// Function to set the Toc panel size
// Browser must support cookies and script
// "days" variable declared in ResizableArea Control, line # 156
function SetCodeSnippetLangFilterCookie()
{
    var cookieDate = new Date();
	cookieDate.setTime(cookieDate.getTime()+(days*24*360000));
    expires = "expires=" + cookieDate.toGMTString();
            
	if (window.navigator.cookieEnabled == true)
	{
		var cbxColl = oMTPS_DD_PopUpDiv.getElementsByTagName("input");
	
		for (i = 0 ; i < cbxColl.length; i ++)
		{
			document.cookie = cbxColl[i].id + "_" + i + "=" + cbxColl[i].checked + "; " + expires;
		}
	}
	return;
}











var _contentID;
var _contentLocale;
var _contentVersion;
var _noTagsMessage;
var _errorMessage;
var _browseByTagTooltip;
var _removeTagTooltip;
var _currentBlockID = 0;

function TagEditor_AddATag(url,blockID)
{
	if ( url != "" )
	{	// Need to authenticate
		document.cookie = "edit=" + blockID;
		document.cookie = "scroll=" + blockID;
		document.location.href = url;
	}
	else
	{	// Already authenticated
		showTagEditorEditPanel(blockID);
		TagEditor_GetControl(blockID,'textbox').focus();
	}
	return false;
}

function TagEditor_AddTags(blockID)
{
  if ( blockID >= 0 )
  {
    var value = TagEditor_GetControl(blockID,'textbox').value;
	  if ( value != "" )
	  {
		  _currentBlockID = blockID;
		  Microsoft.Mtps.Rendering.Behaviors.Ajax.TagWebService.AddTags( _contentID,
		                                                                _contentLocale,
		                                                                _contentVersion,
		                                                                value,
		                                                                blockID,
		                                                                _browseByTagTooltip,
		                                                                _removeTagTooltip,
		                                                                tagEditorChangeComplete,
		                                                                tagEditorChangeFailure );
		  showTagEditorViewPanel(blockID);
	  }
	  else
	  {
		  TagEditor_GetControl(blockID,'message').innerText = _noTagsMessage;
	  }
	}
	return false;
}

function TagEditor_BrowseTag(url,blockID)
{
	document.cookie = "scroll=" + blockID;
	document.location.href = url;
	return false;
}

function TagEditor_CancelAddTag(blockID)
{
  if ( blockID >= 0 )
  {
	  showTagEditorViewPanel(blockID);
	}
	return false;
}

//function TagEditor_ClickAddTag(evt)
//{
//  TagEditor_AddTags(TagEditor_GetBlockID(evt.target.id));
//  evt.preventDefault();
//}

//function TagEditor_ClickCancelAddTag(evt)
//{
//  TagEditor_CancelAddTag(TagEditor_GetBlockID(evt.target.id));
//  evt.preventDefault();
//}

function TagEditor_GetBlockID(controlID)
{
  var count = TagEditorControls.length;
  for ( var i=0; i<count; i++ )
  {
    var value = TagEditorControls[i];
    var idx = controlID.indexOf(value['prefix']);
    if ( idx != -1 )
    {
      return value['id'];
    }
  }
  return -1;
}

function TagEditor_GetControl(blockID,control)
{
  var count = TagEditorControls.length;
  for ( var i=0; i<count; i++ )
  {
    var value = TagEditorControls[i];
    if ( value['id'] == blockID )
    {
      return $get(value['prefix']+control);
    }
  }
}

function TagEditor_GetTags(blockID)
{
  var tags = "";
	var tagEditorBody = TagEditor_GetControl(blockID,'tags');
	if ( tagEditorBody )
	{
	  var childElems = tagEditorBody.children;
	  if ( childElems.length > 0 )
	  {
      // Deal with DIV that is inserted when a tag is added from client
	    if ( childElems[0].tagName == "DIV" )
	    {
	       childElems = childElems[0].children;
	    }

	    if ( childElems.length > 0 )
	    {
        // Get tag values from spans (each has two hyperlinks - we need the first)
	      for ( var i=0; i<childElems.length; i++)
	      {
	        var elem = childElems[i].children[0];
	        if ( elem.tagName == "A" )
	        {
            tags += elem.innerText + " ";
          }
	      }
	    }
	  }
	}
  return tags;
}

function TagEditor_Init(itemID,itemLocale,itemVersion,auth)
{
	_contentID = itemID;
	_contentLocale = itemLocale;
	_contentVersion = itemVersion;

	var cookieParts = document.cookie.split("; ");
	var crumb="";
	for (var i=0; i<cookieParts.length; i++)
	{
		var crumbs = cookieParts[i].split("=");
		if (crumbs[0] == "scroll"
		 && crumbs[1] != "")
		{
			scrollToTagEditor(crumbs[1]);
			removeTagEditorCookie("scroll");
		}
		if (crumbs[0] == "edit"
		 && crumbs[1] != ""
		 && auth == "true")
		{
			showTagEditorEditPanel(crumbs[1]);
		}
	}
}

function TagEditor_InitStrings(noTagsMessage,errorMessage,browseByTagTooltip,removeTagTooltip)
{
	_noTagsMessage = noTagsMessage;
	_errorMessage = errorMessage;
  _browseByTagTooltip = browseByTagTooltip;
  _removeTagTooltip = removeTagTooltip;
}

function TagEditor_KeyDown(evt)
{
  if ( evt.keyCode == 13 )
  { // Enter pressed - add the tags
    TagEditor_AddTags(TagEditor_GetBlockID(evt.target.id));
    evt.preventDefault();
	}
	else if ( evt.keyCode == 27 )
	{ // Escape pressed - cancel the operation
	  TagEditor_CancelAddTag(TagEditor_GetBlockID(evt.target.id));
    evt.preventDefault();
	}
	else
	{
	  return true;
	}
}

function TagEditor_RemoveTag(tag,url,blockID)
{
	if ( url != "" )
	{	// Need to authenticate
		document.cookie = "remove=" + tag + ":" + blockID;
		document.cookie = "scroll=" + blockID;
		document.location.href = url;
	}
	else
	{	// Already authenticated
		_currentBlockID = blockID;
		Microsoft.Mtps.Rendering.Behaviors.Ajax.TagWebService.RemoveTag( _contentID,
	                                                                  _contentLocale,
	                                                                  _contentVersion,
	                                                                  tag,
	                                                                  blockID,
	                                                                  _browseByTagTooltip,
	                                                                  _removeTagTooltip,
	                                                                  tagEditorChangeComplete,
	                                                                  tagEditorChangeFailure );
	}
	return false;
}

function removeTagEditorCookie(name)
{
	document.cookie = name + "=; expires=Fri, 02-Jan-1970 00:00:00 GMT";
}

function scrollToTagEditor(blockID)
{
	var ctrl = TagEditor_GetControl(blockID,'textbox');
	ctrl.scrollIntoView(false);
}

function showTagEditorEditPanel(blockID)
{
	TagEditor_GetControl(blockID,'view').style.display = "none";
	TagEditor_GetControl(blockID,'edit').style.display = "";
	TagEditor_GetControl(blockID,'textbox').value = "";
	TagEditor_GetControl(blockID,'message').innerText = "";
	removeTagEditorCookie("edit");
}

function showTagEditorViewPanel(blockID)
{
	TagEditor_GetControl(blockID,'view').style.display = "";
	TagEditor_GetControl(blockID,'edit').style.display = "none";
	TagEditor_GetControl(blockID,'message').innerText = "";
}

function tagEditorChangeComplete(result)
{
	var elem = document.createElement( "div" );
	elem.innerHTML = result;
	elem.style.display = "inline";
	var tagEditorBody = TagEditor_GetControl(_currentBlockID,'tags');
	if ( tagEditorBody )
	{
	  tagEditorBody.innerHTML = "";
	  tagEditorBody.appendChild( elem );
	}
	_currentBlockID = 0;
}

function tagEditorChangeFailure(error)
{
	TagEditor_GetControl(_currentBlockID,'message').innerText = _errorMessage;
	TagEditor_GetControl(_currentBlockID,'message').title = error.get_message();
}

if (typeof(Sys) !== "undefined")
{
    Sys.Application.notifyScriptLoaded();
}

function CopyCode(elemName)
{
    var obj = document.getElementById(elemName)
    window.clipboardData.setData("Text", obj.innerText);
}


function DoSave(editorId, hfDataID, titleID, tDataID, headerID, saveID, cancelID, labelID,  lastTitle, tagTextBoxID, tagDataID, blockID)
{
  var editorObj = $find(editorId);
  var title = $get(titleID).value;
  var cont = editorObj.get_ModifiedContent();
  var label = $get(labelID);
  var tagTextBox = $get(tagTextBoxID);
  var tags = "";
  if (tagTextBox != null )
  {
	  tags = tagTextBox.value;
  }
  if(title == null || title.trim() == ""){
    label.style.display="";
    label.innerText = errEmptySubject;
    return false;
  }
  if(cont.trim() == ""
  || cont.trim() == '&nbsp;'
  || cont.trim() == "<br>"){
    label.style.display="";
    label.innerText = errEmptyContent;
    return false;
  }
  if (cont.trim() == editorObj.get_OriginalContent().trim()
   && title.trim() == lastTitle.trim()
   && tags.trim() == $get(tagDataID).value.trim()){
    label.style.display="";
    label.innerText = errSameContent;
    return false;
  }

  if( headerID!=null && headerID!="")
  {
    SwitchToView(headerID, editorId, titleID, saveID, cancelID, blockID);
  }
  
  $get(hfDataID).value = cont;
  $get(tDataID).value = title;
  $get(tagDataID).value = tags;
  return true;
}

function DoCancel(headerID, editorId, titleID, saveID, cancelID, labelID, blockID){
  var label = $get(labelID);
  label.style.display="none";
  SwitchToView(headerID, editorId, titleID, saveID, cancelID, blockID);
}

function toggleEditUI(editorId, titleID, saveID, cancelID)
{   
    var titleLabel = $get(titleID);
    if (titleLabel)
    {
        if (titleLabel.style.display == "none")
            titleLabel.style.display = "block";
        else
            titleLabel.style.display = "none";
    }
    
    var saveButton = $get(saveID);
    if (saveButton)
    {
        if (saveButton.style.display == "none")
            saveButton.style.display = "";
        else
            saveButton.style.display = "none";
    }
    
    var cancelButton = $get(cancelID);
    if (cancelButton)
    {
        if (cancelButton.style.display == "none")
            cancelButton.style.display = "";
        else
            cancelButton.style.display = "none";
    }
}

function GetHistoryItems(btnLoad){
    var btn = $get(btnLoad);
    if(btn)
      //eval(btn.href)
      window.setTimeout(function() {eval(btn.href)},400);
}

function SwitchToEdit(headerID, inlineEditorID, titleID, saveID, cancelID, blockID, tagTextboxID, cpHistoryID)
{
  var tagEditor = TagEditor_GetControl(blockID,'panel');
  if ( tagEditor )
  {
  	tagEditor.style.display = "none";
  	var tagEditorTextbox = $get(tagTextboxID);
  	tagEditorTextbox.value = TagEditor_GetTags(blockID);
  }
  if ( cpHistoryID !== undefined )
  {
    var cpHistory = $find(cpHistoryID);
    cpHistory.set_Collapsed(true)
    var header =  $get(headerID);
    header.style.display = "none";
    header.parentNode.className = "wkViewerContainer_Edit";
  }
  try
  {
    $find(inlineEditorID).switchToEditMode();
    toggleEditUI(inlineEditorID, titleID, saveID, cancelID);
  }
  catch (e) {}
}

function SwitchToView(headerID, inlineEditorID, titleID, saveID, cancelID, blockID)
{
  var header =  $get(headerID);
  header.style.display = "block";
  header.parentNode.className="wkViewerContainer";
  var tagEditor = TagEditor_GetControl(blockID,'panel');
  if ( tagEditor )
  {
  	tagEditor.style.display = "";
  }
  
  try
  {
    $find(inlineEditorID).switchToViewMode();
    toggleEditUI(inlineEditorID, titleID, saveID, cancelID);
  }
  catch (e) {}
}

function wkItemHighlight(val,headerID,textID,collArea){
  var header = $get(headerID);
  var text = $get(textID);
  if(header.style.display == "none") val = false; // do not highlight in editMode
  if(val){
    header.className+="Hover";
    text.className+="Hover";
  }else{
    header.className = header.className.replace("Hover","");
    text.className = text.className.replace("Hover","");
  }
}


function wkScrollToView(elementID){
  $get(elementID).scrollIntoView();
  window.setTimeout("$get('"+elementID+"').focus()",0);
}

function wkAddNewItem(buttonID, newItemPanelID, editorID, titleID)
{
  if( $get(newItemPanelID).style.display == "block"){
      $get(newItemPanelID).scrollIntoView();
      window.setTimeout("$get('"+titleID+"').focus()",0);
    return;
  }
  $get(newItemPanelID).style.display = "block";
  $get(buttonID).className="ccAddLinkDisabled";
  $find(editorID).switchToEditMode();
  window.setTimeout("$get('"+titleID+"').focus()",0);
}

function wkRemoveNewItem(buttonID, newItemPanelID, editorID, labelID)
{
  $get(newItemPanelID).style.display = "none";
  $get(buttonID).className="ccAddLink";
  $get(labelID).innerText = "";
  $find(editorID).switchToViewMode();
}

function saveNewWikiItem(editorID, hfDataID, titleID, tDataID, labelID, newWikiItemPanelID, tagTextBoxID, tagDataID)
{
  var editorObj = $find(editorID);
  var title = $get(titleID).value;
  var cont = editorObj.get_ModifiedContent();
  var label = $get(labelID);
  var tagTextBox = $get(tagTextBoxID);
  var tags = "";
  if ( tagTextBox != null )
  {
  	tags = tagTextBox.value;
  }

  if(title == null || title.trim() == ""){
    label.innerText = errEmptySubject;
    return false;
  }
  if(cont.trim() == "" || cont.trim() == '&nbsp;'){
    label.innerText = errEmptyContent;
    return false
  }
  
  $get(hfDataID).value = cont;
  $get(tDataID).value = title;
  $get(titleID).value = title;
  $get(tagDataID).value = tags;
  editorObj.switchToViewMode();
  window.setTimeout(function(){$get(newWikiItemPanelID).style.display="none";},10);

  return true;
}












var cleanedDivIds, cleanedImgIds, oExpColSpan, oExpColImg;
var expState = true;

function checkExpCollAll()
{
   
   cleanImgVars();
   
   var open = false;
   var closed = false;
   
   for (i = 0; i < cleanedDivIds.length-1; i++)
   {
		// alert(cleanedDivIds[i]);
        try
        {
            oDiv = document.getElementById(cleanedDivIds[i]);
            oImg = document.getElementById(cleanedImgIds[i]);
            
            if (oDiv.style.display == 'block')
            {
                open = true;
            }
            else
            {
                closed = true;
            }
        }
        catch(e)
	    {
			throw e;
	    }
   }
   if (open != closed)
	{	        
	    if (open)
	        expState = false;
	    if (closed)
	        expState = true;
	        
	    if (typeof(expcalallPres)!='undefined' && expcalallPres == true)
	        expCollButtonToggle();
	}
}

function cleanImgVars()
{
   if (typeof(cleanedDivIds)=='undefined')
   {
        var r1, r2, re;
        re = /undefined/g; 
        r1 = ExpCollDivStr.replace(re, "");
        cleanedDivIds = r1.substring(0, r1.length).split(',');
        
        r2 = ExpCollImgStr.replace(re, "");
        cleanedImgIds = r2.substring(0, r2.length).split(',');
   }
}

//	#5406
function ShowHideCollapsibleArea(strAreaId,strImg)
{
	var oCollAreaDiv = document.getElementById(strAreaId);
	var oCollAreaImg = document.getElementById(strImg);	
	if (oCollAreaDiv.style.display == 'none')
	{
		oCollAreaDiv.style.display = 'block';
		oCollAreaImg.src = imgMinus;
	}
	else
	{		
		oCollAreaDiv.style.display = 'none';
		oCollAreaImg.src = imgPlus;	
	}

	checkExpCollAll();
}









//  function to expand and shorten the main content panel
function ToggleMutliViewTable(strImage)
{
    var thisImgObj = document.getElementById(strImage);  
    var thisPanelOb = document.getElementById(currentDisplayPanel);
    if ( thisPanelOb != null)
    {
        for (i = 0; i < thisPanelOb.parentNode.childNodes.length; i++)
        {
            if(thisPanelOb.parentNode.childNodes[i].style.height == "300px" )
            {
                thisPanelOb.parentNode.childNodes[i].style.height = "auto";
                thisImgObj.childNodes[0].src = mvt_collImage;
            }
            else
            {
                thisPanelOb.parentNode.childNodes[i].style.height = "300px";
                thisImgObj.childNodes[0].src = mvt_expImage; 
            }  
        }
    }
    return;
}   


// function to display the assigned text from the assigned button
function ShowThisTableView(strBannerID,strBannerText, strPanel)
{
    var bannerObj = document.getElementById(strBannerID);
    if ( bannerObj != null)
    {
        bannerObj.innerHTML = strBannerText;
    } 
   
    var currentObj = document.getElementById(strPanel);
    if ( currentObj != null)
    {
        for (i = 0; i < currentObj.parentNode.childNodes.length; i++)
        {
            currentObj.parentNode.childNodes[i].className = "MultiViewPanelClosed";
        }
        currentObj.className = "MultiViewPanelOpen";
        currentDisplayPanel = strPanel;
    }
   return; 
}







