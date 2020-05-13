// Copyright (c) 2008, The Code Project. All rights reserved.
var objectId, objectTypeId;
var bnoteNode;

function bookmarkMe(objId, objTypeId)
{
	objectId = objId.toString();
	objectTypeId = objTypeId.toString();
	LoadBookmarkWaitMessage();
	jx.load("/Script/Bookmarks/Ajax/Add.aspx?obtid="+ objTypeId + "&obid=" + objId + "&bma=addbookmark", bookmarkCallback);
	return false;
}

function watchMe(objId, objTypeId)
{
	objectId = objId.toString();
	objectTypeId = objTypeId.toString();
	LoadBookmarkWatchWaitMessage();
	jx.load("/Script/Bookmarks/Ajax/Add.aspx?obtid="+ objTypeId + "&obid=" + objId + "&bma=addwatch", bookmarkCallback);
	return false;
}

function bookmarkCallback(data)
{
	if(data.length > 0) {
		var re = new RegExp("<span id=\"bmResult\">(.+)<\/span>");
		var match = re.exec(data);
		if(match&&match[1]) bnoteNode.innerHTML = match[1];
	}
}

function NextSibling(el)
{
	var result = el.nextSibling;
	while (result&&result.innerHTML == null)
		result = result.nextSibling;
	return result;
}

function LoadBookmarkWaitMessage()
{
	LoadWaitMessage("bm_");
}

function LoadBookmarkWatchWaitMessage()
{
	LoadWaitMessage("bmw_");
}

function LoadWaitMessage(idPrefix)
{
	var sel = document.getElementById(idPrefix + objectId + "," + objectTypeId);
	if(sel) {
		bnoteNode = NextSibling(sel);
		if (sel.parentNode)sel.parentNode.removeChild(sel);
		if(bnoteNode&&bnoteNode.style.visibility == "hidden") {
			bnoteNode.innerHTML = " please wait... ";
			bnoteNode.style.visibility = "visible";
		}
	}
}
