/***************************************
*                                      *
*           OUTLOOK-LIKE BAR           *
*                                      *
*             Written by               *
*           Massimo Guccione           *
*            Multimedia Lab            *
*       Intersiel S.p.A. (W)1999       *
*                                      *
* Important: to use this script don't  *
*            remove these comments     *
*                                      *
*                                      *
* Version 1.0Beta Freeware (MSIE only) *
*                                      *
* mail : m.guccione@telcal.it          *
*        obyone@antares.it             *
*        please report for bugs        *
*                                      *
*  for both Netscape and MSIE version  *
*  contact me! (freeware of course)    *
****************************************/
document.write("<DIV id='OutlookLikeBar' style='position:absolute;top:"+OB_Top+";left:"+OB_Left+";width:"+OB_Width+";height:"+OB_Height+";border:"+OB_BorderWidth+" "+OB_BorderStyle+" "+OB_BorderColor+";background-color:"+OB_BackgroundColor+";z-index:0;visibility:hidden;clip:rect(0,"+OB_Width+","+OB_Height+",0)'>");
document.write("<img onMouseUp='OutlookLikeBar.ArrowSelected(this)' onMouseDown='OutlookLikeBar.ArrowClicked(this)' onMouseOver='OutlookLikeBar.OverArrow(this)' onMouseOut='OutlookLikeBar.OutArrow(this)' id='OB_SlideUp' height='"+OB_ArrowHeight+"' width='"+OB_ArrowWidth+"' src='"+OB_UpArrow+"' style='position:absolute;top:0;left:0;cursor:hand;visibility:hidden;z-index:500'>");
document.write("<img onMouseUp='OutlookLikeBar.ArrowSelected(this)' onMouseDown='OutlookLikeBar.ArrowClicked(this)' onMouseOver='OutlookLikeBar.OverArrow(this)' onMouseOut='OutlookLikeBar.OutArrow(this)' id='OB_SlideDown' height='"+OB_ArrowHeight+"' width='"+OB_ArrowWidth+"' src='"+OB_DownArrow+"' style='position:absolute;top:0;left:0;cursor:hand;visibility:hidden;z-index:500'>");
j=1;
while(eval("window.OutBarFolder"+j))
	j++;
i=j-1;
while(i>0)
{
	Folder=eval("OutBarFolder"+i)
	window.status="Outlook-Like Bar is making folder '"+Folder[0]+"'";
	if(i==1)
	{
		document.write("<INPUT position='UP' id='OB_Button1' onDblClick='OutlookLikeBar.FolderClicked("+i+");this.blur()' onClick='OutlookLikeBar.FolderClicked("+i+");this.blur()' TYPE='button' value='"+Folder[0]+"' style='position:absolute;top:0;left:0;width:90;height:"+OB_ButtonHeight+";font-family:"+OB_ButtonFontFamily+";font-size:"+OB_ButtonFontSize+"pt;cursor:hand;color:"+OB_ButtonFontColor+";z-index:100'>");
		MakeItems(Folder,i,OB_ButtonHeight);		
	}	
	else
	{
		document.write("<INPUT position='DOWN' id='OB_Button"+i+"' onDblClick='OutlookLikeBar.FolderClicked("+i+");this.blur()' onClick='OutlookLikeBar.FolderClicked("+i+");this.blur()' TYPE='button' value='"+Folder[0]+"' style='position:absolute;top:"+(OB_Height-(j-i)*OB_ButtonHeight-OB_BorderWidth*2)+";left:0;width:90;height:"+OB_ButtonHeight+";font-family:"+OB_ButtonFontFamily+";font-size:"+OB_ButtonFontSize+"pt;cursor:hand;color:"+OB_ButtonFontColor+";z-index:100'>");
		MakeItems(Folder,i,(OB_Height-(j-i)*OB_ButtonHeight-OB_BorderWidth*2)+OB_ButtonHeight);		
	}		
	i--;
}	
document.write("</DIV>");
var OutlookLikeBar=new OutBar(OB_Width,OB_Height,j-1,OB_ButtonHeight,OB_BorderWidth,OB_SlideSpeed,OB_IconsHeight+OB_LabelFontSize+OB_LabelMargin+OB_ItemsSpacing,OB_ArrowSlideSpeed);
window.status="Outlook-Like Bar successful created!";
document.all["OutlookLikeBar"].style.visibility="visible";

function MakeItems(Folder,zorder,top)
{
	var items=0;
	var folderWidth=(OB_Width-OB_BorderWidth*2);
	while(Folder[items+1])
		items+=4;
	items/=4;
	document.write("<DIV id='OB_Folder"+zorder+"' style='position:absolute;left:0;top:"+top+";width:"+folderWidth+";height:"+(OB_Margin*2+items*(OB_IconsHeight+OB_LabelFontSize+OB_LabelMargin)+(items-1)*OB_ItemsSpacing)+";z-index:"+zorder+";clip:rect(0 0 0 0);'>");
	for(var i=1;i<items*4;i+=4)
	{
		document.write("<div targetFrame='"+Folder[i+3]+"' link='"+Folder[i+2]+"' onMouseDown='OutlookLikeBar.ItemClicked(this)' onMouseUp='OutlookLikeBar.ItemSelected(this)' onMouseOver='OutlookLikeBar.OverItems(this)' onMouseOut='OutlookLikeBar.OutItems(this)' style='position:absolute;left:"+(Math.ceil((OB_Width-OB_BorderWidth*2-OB_IconsHeight)/2)-1)+";top:"+(OB_Margin+Math.ceil((i-1)/4)*(OB_ItemsSpacing+OB_LabelFontSize+OB_IconsHeight))+";cursor:hand;clip:rect(0 "+OB_IconsWidth+" "+OB_IconsHeight+" 0;width:"+OB_IconsWidth+";height:"+OB_IconsHeight+"'>");
 		document.write("<img src='"+Folder[i]+"'>");
		document.write("</div>");
		document.write("<div align='center' style='position:absolute;left:0;top:"+(OB_LabelMargin+OB_IconsHeight+OB_Margin+Math.ceil((i-1)/4)*(OB_ItemsSpacing+OB_LabelFontSize+OB_IconsHeight))+";font-family:"+OB_LabelFontFamily+";font-size:"+OB_LabelFontSize+"pt;color:"+OB_LabelFontColor+"'>");
		document.write(Folder[i+1]);
		document.write("</div>");
	}	
	document.write("</DIV>");
}


//***************************
//* Outlook-Like Bar Object *
//***************************
function OutBar(width,height,items,buttonHeight,borderWidth,slideSpeed,slideArrowValue,ArrowSlideSpeed)
{
	this.currentFolder=1;
	this.currentItem=null;
	this.slideCount=0;
	this.slideStep=1;
	this.slideArrowValue=slideArrowValue;
	this.slideSpeed=slideSpeed;
	this.borderWidth=borderWidth;
	this.width=width;
	this.visibleAreaHeight=height-2*borderWidth-items*buttonHeight;
	this.visibleAreaWidth=width;
	this.FolderClicked=FolderClicked;
	this.SlideFolders=SlideFolders;
	this.ItemClicked=ItemClicked;
	this.ItemSelected=ItemSelected;
	this.OverItems=OverItems;
	this.OutItems=OutItems;
	this.OverArrow=OverArrow;
	this.OutArrow=OutArrow;
	this.ArrowClicked=ArrowClicked;
	this.ArrowSelected=ArrowSelected;
	this.ArrowSlideSpeed=ArrowSlideSpeed;
	this.SlideItems=SlideItems;
	this.SlideItemsAction=SlideItemsAction;
	this.Start=Start;
	this.ClipFolder=ClipFolder;
	this.SetArrows=SetArrows;
	this.HideArrows=HideArrows;
	this.sliding=false;
	this.items=items;
	this.started=false;
	this.Start();
}

function FolderClicked(folder)
{
	if(this.sliding)
		return;
	if(folder==this.currentFolder)
		return;
	this.sliding=true;		
	this.slideCount=this.visibleAreaHeight;
	this.slideStep=1;
	this.countStep=0;
	this.HideArrows();
	this.SlideFolders(folder,document.all["OB_Button"+folder].position=="DOWN");
}

function SlideFolders(folder,down)
{
	var step;	
	if(down)
	{
		this.slideCount-=Math.floor(this.slideStep);
		if(this.slideCount<0)
			this.slideStep+=this.slideCount;
		step=Math.floor(this.slideStep);
		for(var i=2;i<=folder;i++)
			if(document.all["OB_Button"+i].position=="DOWN")
			{
				document.all["OB_Button"+i].style.pixelTop-=step;
				document.all["OB_Folder"+i].style.pixelTop-=step;
			}				

	    filter = /rect\((\d*)px (\d*)px (\d*)px (\d*)px\)/;

		var clipString=document.all["OB_Folder"+folder].style.clip;
		var clip=clipString.match(filter);
		this.ClipFolder(folder,parseInt(clip[1]),this.visibleAreaWidth,(parseInt(clip[3])+step),0);

		var clipString=document.all["OB_Folder"+this.currentFolder].style.clip;
		var clip=clipString.match(filter);
		this.ClipFolder(this.currentFolder,parseInt(clip[1]),this.visibleAreaWidth,(parseInt(clip[3])-step),0);

		this.slideStep*=this.slideSpeed;
		if(this.slideCount>0)
			setTimeout("OutlookLikeBar.SlideFolders("+folder+",true)",20);
		else		
		{
			for(var k=2;k<=folder;k++)
				document.all["OB_Button"+k].position="UP";
			this.currentFolder=folder;		
			this.SetArrows();
			this.sliding=false;		
		}		
	}
	else		
	{
		this.slideCount-=Math.floor(this.slideStep);
		if(this.slideCount<0)
			this.slideStep+=this.slideCount;
		step=Math.floor(this.slideStep);
		for(var i=folder+1;i<=this.items;i++)
			if(document.all["OB_Button"+i].position=="UP")
			{
				document.all["OB_Button"+i].style.pixelTop+=step;
				document.all["OB_Folder"+i].style.pixelTop+=step;
			}

	    filter = /rect\((\d*)px (\d*)px (\d*)px (\d*)px\)/;

		var clipString=document.all["OB_Folder"+folder].style.clip;
		var clip=clipString.match(filter);
		this.ClipFolder(folder,parseInt(clip[1]),this.visibleAreaWidth,(parseInt(clip[3])+step),0);

		var clipString=document.all["OB_Folder"+this.currentFolder].style.clip;
		var clip=clipString.match(filter);
		this.ClipFolder(this.currentFolder,parseInt(clip[1]),this.visibleAreaWidth,(parseInt(clip[3])-step),0);

		this.slideStep*=this.slideSpeed;
		if(this.slideCount>0)
			setTimeout("OutlookLikeBar.SlideFolders("+folder+",false)",20);
		else		
		{
			for(var k=folder+1;k<=this.items;k++)
				document.all["OB_Button"+k].position="DOWN";
			this.currentFolder=folder;		
			this.SetArrows();
			this.sliding=false;		
		}		
	}
}

function ItemClicked(item)
{
	if(this.sliding)
		return;		
	item.style.border="2 inset #ffffff";
}

function ItemSelected(item)
{
	if(this.sliding)
		return;		
	item.style.border="1 outset #ffffff";
	if(item.link.indexOf("javascript")!=-1) 
		eval(item.link)
	else 
		eval(item.targetFrame+".location='"+item.link+"'");
}

function OverItems(item)
{
	if(this.sliding)
		return;		
	item.style.border="1 outset #ffffff";
}

function OutItems(item)
{
	if(this.sliding)
		return;		
	item.style.border="0 none black";
}

function ArrowClicked(arrow)
{
	if(this.sliding)
		return;		
	arrow.style.border="1 inset #ffffff";
}

function ArrowSelected(arrow)
{
	if(this.sliding)
		return;		
	arrow.style.border="0 none black";
	this.SlideItems(arrow.id=="OB_SlideUp");
}

function OverArrow(arrow)
{
	if(this.sliding)
		return;		
	arrow.style.border="1 outset #ffffff";
}

function OutArrow(arrow)
{
	if(this.sliding)
		return;		
	arrow.style.border="0 none black";
}

function ClipFolder(folder,top,right,bottom,left)
{
	document.all["OB_Folder"+folder].style.clip=clip='rect('+top+' '+right+' '+bottom+' '+left+')';
}

function Start()
{
	if(!this.started)
	{
		this.ClipFolder(1,0,this.visibleAreaWidth,this.visibleAreaHeight,0);
		this.SetArrows();
	}		
}

function SetArrows()
{
	document.all["OB_SlideUp"].style.pixelTop=document.all["OB_Button"+this.currentFolder].style.pixelTop+document.all["OB_Button"+this.currentFolder].style.pixelHeight+20;
	document.all["OB_SlideUp"].style.pixelLeft=this.width-document.all["OB_SlideUp"].width-this.borderWidth-10;
	document.all["OB_SlideDown"].style.pixelTop=document.all["OB_Button"+this.currentFolder].style.pixelTop+document.all["OB_Button"+this.currentFolder].style.pixelHeight+this.visibleAreaHeight-document.all["OB_SlideDown"].height-20;
	document.all["OB_SlideDown"].style.pixelLeft=this.width-document.all["OB_SlideDown"].width-this.borderWidth-10;

	var folder=document.all["OB_Folder"+this.currentFolder].style;
	var startTop=document.all["OB_Button"+this.currentFolder].style.pixelTop+document.all["OB_Button"+this.currentFolder].style.pixelHeight;

	if(folder.pixelTop<startTop)
		document.all["OB_SlideDown"].style.visibility="visible";
	else		
		document.all["OB_SlideDown"].style.visibility="hidden";

	if(folder.pixelHeight-(startTop-folder.pixelTop)>this.visibleAreaHeight)
		document.all["OB_SlideUp"].style.visibility="visible";
	else		
		document.all["OB_SlideUp"].style.visibility="hidden";
}

function HideArrows()
{
	document.all["OB_SlideUp"].style.visibility="hidden";
	document.all["OB_SlideDown"].style.visibility="hidden";
}

function SlideItems(up)
{
	this.sliding=true;
	this.slideCount=Math.floor(this.slideArrowValue/this.ArrowSlideSpeed);
	up ? this.SlideItemsAction(-this.ArrowSlideSpeed) : this.SlideItemsAction(this.ArrowSlideSpeed);
}

function SlideItemsAction(value)
{
	document.all["OB_Folder"+this.currentFolder].style.pixelTop+=value;
    filter = /rect\((\d*)px (\d*)px (\d*)px (\d*)px\)/;
    var clipString=document.all["OB_Folder"+this.currentFolder].style.clip;
    var clip=clipString.match(filter);
    this.ClipFolder(this.currentFolder,(parseInt(clip[1])-value),parseInt(clip[2]),(parseInt(clip[3])-value),parseInt(clip[4]));
	this.slideCount--;
	if(this.slideCount>0)
		setTimeout("OutlookLikeBar.SlideItemsAction("+value+")",20);
	else
	{
		if(Math.abs(value)*this.ArrowSlideSpeed!=this.slideArrowValue)		
		{
			document.all["OB_Folder"+this.currentFolder].style.pixelTop+=(value/Math.abs(value)*(this.slideArrowValue%this.ArrowSlideSpeed));
		    filter = /rect\((\d*)px (\d*)px (\d*)px (\d*)px\)/;
			var clipString=document.all["OB_Folder"+this.currentFolder].style.clip;
			var clip=clipString.match(filter);
		    this.ClipFolder(this.currentFolder,(parseInt(clip[1])-(value/Math.abs(value)*(this.slideArrowValue%this.ArrowSlideSpeed))),parseInt(clip[2]),(parseInt(clip[3])-(value/Math.abs(value)*(this.slideArrowValue%this.ArrowSlideSpeed))),parseInt(clip[4]));
		}		    
		this.SetArrows();
		this.sliding=false;
	}		
}