

//	Resize the TOC Container DIV to match the Resizable Area Control
//	resize TOC Panel to match Resizable Area control
function ResizeTocPanel()
{
	var o = document.getElementById(MtpsTocCtrlTopName);
	if (typeof(o) != "undefined")
	{
	    o.style.height = parseInt(document.body.clientHeight) - parseInt(TocPanelHeight);
	    o.style.width = "100%";
	}
}

//	Scroll the current node into view
function SyncToNode()
{
	try
	{
		var o = document.getElementById(MtpsTocCtrlTopName);
				
		var oLinks = o.getElementsByTagName("A");
		for (var i = 0 ; i < oLinks.length;i++)
		{
			if (oLinks[i].href == selectedTocSyncUrl)
			{
				var oSelected = document.getElementById(oLinks[i].id);
				oSelected.focus();				
				oSelected.scrollIntoView(true);
				oSelected.parentNode.scrollIntoView(true);
			}
		}
	}
	catch(e)
	{	//alert(	e.message + "\n" + e.description);
		return false;
	}
	return true;
}

