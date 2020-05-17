// JScript File
var max = 5;
var maxBrk = 3;
var check = -1;
var checkBrk = -1;
var onlyOnce = 0;
var maxBLeaders = 5;
var checkBLeaders = -1;
var maxSponsors = 5;
var checkSponsors = -1;
function ChangeByOne()
{
    if (document.getElementById("ctl00_ContentPlaceHolder1_FeaturedArticle1_hideNum") != null)
        max = parseInt(document.getElementById("ctl00_ContentPlaceHolder1_FeaturedArticle1_hideNum").value);
	
	if(check == -1)
		setTimeout("forSetTimeOne()",1);
	else
		setTimeout("forSetTimeOne()",30000);
	if (onlyOnce == 0)
	{
		ChangeByOneBrk();
		onlyOnce = 1;
	}
}
function ChangeByOneBrk()
{
	if(document.getElementById("ctl00_ContentPlaceHolder1_HomeCenter1_BreakingNews1_hideNumBrk") != null)
	{
		maxBrk = parseInt(document.getElementById("ctl00_ContentPlaceHolder1_HomeCenter1_BreakingNews1_hideNumBrk").value);
	}
	
	if(checkBrk == -1)
		setTimeout("forSetTimeOneBrk()",1);
	else
		setTimeout("forSetTimeOneBrk()",30000);
}

function forSetTimeOne()
{
	check++;
	if(check == max)
		check = 0;
		
	HideShowOne(check);
	ChangeByOne();
}

function forSetTimeOneBrk()
{
	checkBrk++;
	if(checkBrk == maxBrk)
		checkBrk = 0;
		
	HideShowOneBrk(checkBrk);
	ChangeByOneBrk();
}

function HideShowOne(check)
{
	if(document.getElementById("ctl00_ContentPlaceHolder1_FeaturedArticle1_onlyOneRow") != null)
	{
		if(document.getElementById("ctl00_ContentPlaceHolder1_FeaturedArticle1_hide"+check) != null)
		{
			document.getElementById("ctl00_ContentPlaceHolder1_FeaturedArticle1_onlyOneRow").innerHTML = document.getElementById("ctl00_ContentPlaceHolder1_FeaturedArticle1_hide"+check).value;
		}
	}
}
function HideShowOneBrk(checkBrk)
{
	if(document.getElementById("ctl00_ContentPlaceHolder1_HomeCenter1_BreakingNews1_onlyOneRow") != null)
	{
		if(document.getElementById("ctl00_ContentPlaceHolder1_HomeCenter1_BreakingNews1_hideBrk" + checkBrk) != null)
		{
			document.getElementById("ctl00_ContentPlaceHolder1_HomeCenter1_BreakingNews1_onlyOneRow").innerHTML = document.getElementById("ctl00_ContentPlaceHolder1_HomeCenter1_BreakingNews1_hideBrk"+checkBrk).value;
		}
	}
}

	/*This fuction is used to get a print version of an article */
	function GetNewsLetterContent()
	{
		if (document.getElementById != null)
		{
			var html = '<HTML>\n<HEAD>\n';
			if (document.getElementsByTagName != null)
			{
				var headTags = document.getElementsByTagName("head");
				if (headTags.length > 0)
					html += headTags[0].innerHTML;
			}
			html += '\n</HEAD>\n<BODY>\n<form name = frmform>\n';
			var printReadyElement1 = document.getElementById("div1");
			if (printReadyElement1 != null)
			{
				html += printReadyElement1.innerHTML;
			}
			html += '\n</div>\n</form>\n</BODY>\n</HTML>';
			var sReturnString = document.getElementById("ctl00_ContentPlaceHolder1_txtNewsLetterContent");
			sReturnString.value = html;
//			var printWin = window.open();
//			printWin.document.open();
//			printWin.document.write(html);
			//return true;
		}
		else
		{
			//return false;
		}
	}

/* To chech weather user is logged in or not
This event is called when we are adding Attributes.Add of a control*/
	function CheckSession(sCheck)
	{
		if(sCheck == "")
		{
			var str = window.location.toString().toLowerCase();
			str = str.substring(str.indexOf('/c-sharpcorner/')+14);
			window.location.href('../UserRegistration/LoginCheck.aspx?ReturnURL=..'+str);
			
			return false;
		}
		else
			return true;	
	}	
	
	function CheckSessionArticle(sCheck)
	{
		if(sCheck == "")
		{
			var str = window.location.toString().toLowerCase();			
			window.location.href('/UserRegistration/LoginCheck.aspx?ReturnURL='+str);
			return false; 
		}
		else
			return true;	
	}
	function CheckSessionArticleNewURL(sCheck)
	{
		if(sCheck == "")
		{
			var str = window.location.toString().toLowerCase();			
			window.location.href('/UserRegistration/LoginCheck.aspx?ReturnURL='+str);
			return false; 
		}
		else
			return true;
	}	
	
/* to check login, valid author and for comfirmation message to perform an author action*/ 	
	function CheckSessionAndMsgAuthor(sUserID, sAuthor, sCommand)
	{
		if(sUserID == "")
		{
		    var str = window.location.toString().toLowerCase();	
			window.location.href('/UserRegistration/LoginCheck.aspx?ReturnURL='+str);
			return false;
		}
		else if(sUserID != sAuthor)
		{
		    alert("You are not authorized to " + sCommand + " the Comment");
			return false;
		}
		else
			return confirm(sCommand+" the Message!");			
	}
	function CheckSessionAndMsgAuthorForArticle(sUserID, sAuthor, sCommand,role)
	{
		if(sUserID == "")
		{
		    var str = window.location.toString().toLowerCase();	
			window.location.href('/UserRegistration/LoginCheck.aspx?ReturnURL='+str);
			return false;
		}
		else if(sUserID != sAuthor && role == "S")
		{
			alert("You are not authorized to "+sCommand+" this Comment");
			return false;
		}
		else
			return confirm(sCommand+" the Message!");			
	}

	/*This fuction is used to get a print version of an article */
	
	function GetPrintVersion()
	{
		if (document.getElementById != null)
		{
			var html = '<HTML>\n<HEAD>\n';
			if (document.getElementsByTagName != null)
			{
				var headTags = document.getElementsByTagName("head");
				if (headTags.length > 0)
					html += headTags[0].innerHTML;
			}
			html += '\n<script language = "javascript">';
			html += '\n function printWindow()\n{';
			html += ' var printReadyEle = document.getElementById("printContent");\nvar shtml = \'<HTML>\\n<HEAD>\\n\';\nif (document.getElementsByTagName != null)\n{\nvar sheadTags = document.getElementsByTagName("head");\nif (sheadTags.length > 0)\nshtml += sheadTags[0].innerHTML;\n}\nshtml += \'</HEAD>\\n<BODY>\\n\';\nif (printReadyEle != null)\n{\n';
			html += 'shtml += \'<form name = frmform1>\';\nshtml += printReadyEle.innerHTML;\n}\nshtml += \'\\n</form>\\n</BODY>\\n</HTML>\';\nvar printWin1 = window.open();\nprintWin1.document.open();\nwindow.parent.close();\nprintWin1.document.write(shtml);\nprintWin1.document.close();\nprintWin1.print();';
			html += '\n}\n</script>\n</HEAD>\n<BODY>\n';

			var printReadyElement1 = document.getElementById("div1");
			var printReadyElement2 = document.getElementById("div2");
			if (printReadyElement1 != null)
			{
				html += '<form name = frmform>';
				html += '\n<div id = printContent>\n<table cellspacing = 0 cellpadding = 0 width = 100% class=grayBG>\n<tr>\n<td >Source : C# Corner (<a href = "http://www.c-sharpcorner.com" class = specific>www.c-sharpcorner.com</a>) <input type = button value = Print class = CommonTextBoxStyle  onclick = "printWindow();"> </td>\n</tr>\n</table>\n';
				html += '<TABLE cellSpacing=0 cellPadding=10 width=100% border=0>\n<TR>\n<TD class=tblArticleHeadingBG>\n';
				html += printReadyElement1.innerHTML;
				html += '\n</td>\n</tr>\n</table>';
				html += '\n<table cellspacing = 0 cellpadding = 0 width = 100%>\n<tr class=grayBG>\n<td>&nbsp;</td>\n</td>\n</tr>\n</table>\n';
				if(printReadyElement2 != null)
				{
					html += '<TABLE cellSpacing=0 cellPadding=10 width=100% border=0 class=ArticlePublisherBackgroundWhite align = center>\n<TR>\n<TD>\n';
					html += printReadyElement2.innerHTML;
					html += '\n</td>\n</tr>\n</table>\n\n';
					html += '\n<table cellspacing = 0 cellpadding = 0 width = 100%>\n<tr>\n<td class=grayBG>Thank you for using C# Corner</td>\n</tr>\n</table>\n';
				}
				else
				{
					alert("This article doesn't contains any content! Sorry for inconvenience");
					return;
				}
			}
			else
			{
				alert("Could not find the header of the article");
				return;
			}

			html += '\n</div>\n</form>\n</BODY>\n</HTML>';
                
			var printWin = window.open();
			printWin.document.open();
			printWin.document.write(html);
			
		}
		else
		{
			alert("The print ready feature is only available if you are using an browser. Please update your browswer.");
		}
	}	
    

   /* Functions for rotatiing top 5 blog leaders on Blog Default page. */
   function ChangeByBlogLeaders()
    { 
        if(document.getElementById("ctl00_ContentPlaceHolder3_WeeklyBlogLeaders1_hideNum") != null)
        maxBLeaders = parseInt(document.getElementById("ctl00_ContentPlaceHolder3_WeeklyBlogLeaders1_hideNum").value); 
        if(checkBLeaders == -1)
        setTimeout("forSetTimeBlogLeaders()",1);
        else
        setTimeout("forSetTimeBlogLeaders()",15000);
    }
    
    function forSetTimeBlogLeaders()
    { 
        checkBLeaders++;
        if(checkBLeaders == maxBLeaders)
        checkBLeaders = 0; 
        HideShowBlogLeaders(checkBLeaders);
        ChangeByBlogLeaders();
    }

    function HideShowBlogLeaders(checkBLeaders)
    { 
        if(document.getElementById("ctl00_ContentPlaceHolder3_WeeklyBlogLeaders1_onlyOneRow") != null)
        { 
            if(document.getElementById("ctl00_ContentPlaceHolder3_WeeklyBlogLeaders1_hide"+checkBLeaders) != null)
            { 
                document.getElementById("ctl00_ContentPlaceHolder3_WeeklyBlogLeaders1_onlyOneRow").innerHTML = document.getElementById("ctl00_ContentPlaceHolder3_WeeklyBlogLeaders1_hide"+checkBLeaders).value;
            }
        }
    }
    /* Functions for rotating the author photo gallery */
     function ChangeByAuthorPhotoGallery()
    { 
        if(document.getElementById("ctl00_ContentPlaceHolder2_PhotoGallery1_hideNum") != null)
        maxBLeaders = parseInt(document.getElementById("ctl00_ContentPlaceHolder2_PhotoGallery1_hideNum").value); 
        if(checkBLeaders == -1)
        setTimeout("forSetTimeAuthorPhotoGallery()",1);
        else
        setTimeout("forSetTimeAuthorPhotoGallery()",3500);
    }
    
    function forSetTimeAuthorPhotoGallery()
    { 
        checkBLeaders++;
        if(checkBLeaders == maxBLeaders)
        checkBLeaders = 0; 
        HideShowAuthorPhotoGallery(checkBLeaders);
        ChangeByAuthorPhotoGallery();
    }

    function HideShowAuthorPhotoGallery(checkBLeaders)
    { 
        if(document.getElementById("ctl00_ContentPlaceHolder2_PhotoGallery1_onlyOneRow") != null)
        { 
            if(document.getElementById("ctl00_ContentPlaceHolder2_PhotoGallery1_hide"+checkBLeaders) != null)
            { 
                document.getElementById("ctl00_ContentPlaceHolder2_PhotoGallery1_onlyOneRow").innerHTML = document.getElementById("ctl00_ContentPlaceHolder2_PhotoGallery1_hide"+checkBLeaders).value;
            }
        }
    }
    