function selectf(id){
document.getElementById("ss"+id+"").style.color = "#000000"
}
//台式机/网友关注等
function nTabs(thisObj,Num){
if(thisObj.className == "active")return;
var tabObj = thisObj.parentNode.id;
var tabList = document.getElementById(tabObj).getElementsByTagName("div");
for(i=0; i <tabList.length; i++)
{
  if (i == Num)
  {
   thisObj.className = "active"; 
      document.getElementById(tabObj+"_Content"+i).style.display = "block";
  }else{
   tabList[i].className = "normal"; 
   document.getElementById(tabObj+"_Content"+i).style.display = "none";
  }
} 
}
//台式机/网友关注等
function nTabs1(thisObj,Num){
if(thisObj.className == "active1")return;
var tabObj = thisObj.parentNode.id;
var tabList = document.getElementById(tabObj).getElementsByTagName("dd");
for(i=0; i <tabList.length; i++)
{
  if (i == Num)
  {
   thisObj.className = "active1"; 
      document.getElementById(tabObj+"_Content"+i).style.display = "block";
  }else{
   tabList[i].className = "normal1"; 
   document.getElementById(tabObj+"_Content"+i).style.display = "none";
  }
} 
}
function qlshow(id){
     document.getElementById(""+id+"").style.display='block';} 
function qlhide(id){
document.getElementById(""+id+"").style.display='none';
}  

function opedealerfl(id,name)
{
var flags = new Array();
for (i=0;i<regionid.length;i++ )
{
   if(flags[regionid[i]] != 1){
      flags[regionid[i]] = 1;
		document.getElementById("svg"+regionid[i]).className="none";
		document.getElementById("dq"+regionid[i]).className="normal";
	}
	}
	if (id!=0)
	{
	document.getElementById("svg"+id).className="block";
    document.getElementById("dq"+id).className="active";
	}
}
function opedealerfl123(id,name)
{
var flags = new Array();
for (i=0;i<regionid.length;i++ )
{
   if(flags[regionid[i]] != 1){
      flags[regionid[i]] = 1;
		document.getElementById("svg1"+regionid[i]).className="none";
		document.getElementById("dq1"+regionid[i]).className="normal1";
	}
	}
	if (id!=0)
	{
	document.getElementById("svg1"+id).className="block";
    document.getElementById("dq1"+id).className="active1";
	}
}


