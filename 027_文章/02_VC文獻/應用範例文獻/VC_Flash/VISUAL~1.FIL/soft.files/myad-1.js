
a = 3 
var slump = Math.random();
var talet = Math.round(slump * (a-1))+1;
function create() {
        this.src = ''
        this.border = ''
	this.alt = ''
	
}

b = new Array()
for(var i=1; i<=a; i++) { b[i] = new create() }
b[1].src    = "http://bbs.yesky.com/banner/cc.gif"
b[1].border = "0"
b[1].url    = "http://gamedown.yesky.com/game/index.htm"

b[2].src    = "http://www.yesky.com/newimages/gg/pingce760.gif"
b[2].border = "0"
b[2].url    = "http://www.yesky.com/pingce/76842668642009088/index.shtml"

b[3].src    = "http://www.yesky.com/newimages/gg/soft760.gif"
b[3].border = "0"
b[3].url    = "http://www.yesky.com/SoftChannel/72339069014638592/index.shtml"



var visa = "";

visa += '<a href='+b[talet].url+' target=_blank><img src='+b[talet].src+' border="0"'+'></a>';
document.write(visa)