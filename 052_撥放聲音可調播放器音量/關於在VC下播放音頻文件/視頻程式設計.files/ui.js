var intBaiduCproDebug = 0;	
var strBaiduCproUiUrl = 'http://cpro.baidu.com/cpro/ui/uijs.php?';

function ss(w)
{
    window.status=w;
    return true;
}

function baiduCproWriteStyle()
{
	strBaiduCproStyle = '<style type="text/css">'
	strBaiduCproStyle += '<!--';
	strBaiduCproStyle += 'table.baidu_cpro_table td,table.baidu_cpro_table a,table.baidu_cpro_table div{font-size:12px;font-family:Arial; table-layout:fixed; word-break:break-all;overflow:hidden;}';
	strBaiduCproStyle += 'table.baidu_cpro_table a:link.baidu_cpro_title{text-decoration:underline},table.baidu_cpro_table a:visited.baidu_cpro_title{text-decoration:underline;}';
	strBaiduCproStyle += 'table.baidu_cpro_table a:active.baidu_cpro_title{text-decoration:none},table.baidu_cpro_table a:hover.baidu_cpro_title{text-decoration:none;}';
	strBaiduCproStyle += 'table.baidu_cpro_table a:link.baidu_cpro_logo{text-decoration:none}';
	strBaiduCproStyle += 'table.baidu_cpro_table a:visited.baidu_cpro_logo{text-decoration:none}';
	strBaiduCproStyle += 'table.baidu_cpro_table a:active.baidu_cpro_logo{text-decoration:underline;}';
	strBaiduCproStyle += 'table.baidu_cpro_table a:hover.baidu_cpro_logo{text-decoration:underline;}';
	strBaiduCproStyle += '//-->';
	strBaiduCproStyle += '</style>';
	return strBaiduCproStyle;
}

function baiduCproTableBuild(strBaiduCproData, bolDebug)
{
	intBaiduCproRow=arrBaiduCproConfig['hn'];
	intBaiduCproCol=arrBaiduCproConfig['wn'];

	if(arrBaiduCproConfig['bd'].toLowerCase()=='#trans')	
	{
		arrBaiduCproConfig['bd']='""';
		thick=0;
	}
	else
	{
		thick=1;
	}
	if(arrBaiduCproConfig['bg'].toLowerCase()=='#trans')
	{
		arrBaiduCproConfig['bg']='""';
	}


	strBaiduCproTitleText = '百度主题推广';
	strBaiduCproTitleUrl = 'http://union.baidu.com/';
	
	intBaiduCproTdLeave=100-Math.floor(100/intBaiduCproCol)*intBaiduCproCol;

	arrBaiduCproData = strBaiduCproData.split('\n');
	for(i=0;i<arrBaiduCproData.length;i++)
	{
		arrBaiduCproData[i] = arrBaiduCproData[i].split('\t');
	}

	strBaiduCproOut='';
	if(arrBaiduCproData[0].length==2)
	{
		strBaiduCproOut+='<center><a href=\"'+arrBaiduCproData[0][1]+'\" target=\"_blank\">';
		strBaiduCproOut+='<img border=0 src=\"'+arrBaiduCproData[0][0]+'\"></a></center>';
	}
	else
	{
		strBaiduCproOut = '<table align=center width='+arrBaiduCproConfig['w']+' height='+arrBaiduCproConfig['h']+' cellpadding=1 cellspacing=0 bgcolor='+arrBaiduCproConfig['bd']+' style="border:'+thick+'px solid '+arrBaiduCproConfig['bd']+';" class="baidu_cpro_table">';
		strBaiduCproTitle  = '<tr>';
		strBaiduCproTitle += '<td height=18 colspan='+arrBaiduCproConfig['wn']+' align='+arrBaiduCproConfig['ta']+' bgcolor='+arrBaiduCproConfig['bd']+' style="border:0px; border-top:'+thick+'px solid '+arrBaiduCproConfig['bd']+'; background-color:'+arrBaiduCproConfig['bd']+'"><a class="baidu_cpro_logo" href="http://union.baidu.com/cpro.html" target="blank" style="color:'+arrBaiduCproConfig['bdl']+'";>';
		strBaiduCproTitle += strBaiduCproTitleText;
		strBaiduCproTitle += '</a></td></tr>';
		if(arrBaiduCproConfig['tl'] != 'bottom')
		{
			strBaiduCproOut+=strBaiduCproTitle;
		}
		if(intBaiduCproCol>arrBaiduCproData.length)
		{
			 intBaiduCproCol = arrBaiduCproData.length;
		}
		intBaiduCproRow = Math.ceil(arrBaiduCproData.length/intBaiduCproCol);

		intBaiduCproTdWidth_t = Math.floor(100/intBaiduCproCol);
	        intBaiduCproTdWidth=0;
		intBaiduCproTdHeight = Math.ceil((arrBaiduCproConfig['h']-22)/intBaiduCproRow);

		index = 0;
		for(i = 0; i < intBaiduCproRow; i++)
		{
			strBaiduCproOut +='<tr>';
			for(j = 0; j < intBaiduCproCol; j++)
			{
				if(j < intBaiduCproTdLeave)
				{
					intBaiduCproTdWidth=intBaiduCproTdWidth_t+1;
				}
				else
				{
					intBaiduCproTdWidth=intBaiduCproTdWidth_t;
				}
				strBaiduCproOut +='<td style="line-height:18px; padding:4px 4px 1px 4px; border:0px;'+(i!=0?' border-top:'+thick+'px solid '+arrBaiduCproConfig['bd']+';':'')+' background-color:'+arrBaiduCproConfig['bg']+';width:'+intBaiduCproTdWidth+'%; height:'+intBaiduCproTdHeight+'px;" bgcolor="'+arrBaiduCproConfig['bg']+'" height="'+intBaiduCproTdHeight+'"width="'+intBaiduCproTdWidth+'%" valign="middle"'; 
				if (index >= arrBaiduCproData.length)
				{
					strBaiduCproOut+='>';				
					break;
				}
				else
				{
					strBaiduCproOut += 'onmouseover="return ss(\'链接至 ' + arrBaiduCproData[index][2].replace(/^(\w+:\/\/)?([^\/]+).*$/ig,'$2') + '\')" onmouseout="return ss(\' \')">';
					strBaiduCproOut +='<div><a href="'+arrBaiduCproData[index][3]+'" target="_blank" class="baidu_cpro_title" style="color:'+arrBaiduCproConfig['tt']+';font-weight:bold;line-height:16px;width:100%;display:block;"><b>';
					if(arrBaiduCproData[index].length == 6 && arrBaiduCproConfig['nfr'] == 0)
					{
						if(arrBaiduCproConfig['tt'] == '#e10900')
							strTT = '#0000cc';
						else
							strTT = '#e10900';
						strTitle = arrBaiduCproData[index][0].replace(eval('/('+RegexEscape(arrBaiduCproData[index][4])+')/ig'), '<font color="'+strTT+'">$1</font>');
					}
					else
					{
						strTitle = arrBaiduCproData[index][0];
					}
					strBaiduCproOut +=strTitle+'</b></a></div>';
					strBaiduCproOut +='<a href="'+arrBaiduCproData[index][3]+'" target="_blank" style="text-decoration:none; line-height:16px;width:100%;display:block;"';
					if(arrBaiduCproData[index][1]!='...')
					{
						strBaiduCproOut +='<div style=" color:'+arrBaiduCproConfig['ct']+';text-decoration:none;">'+arrBaiduCproData[index][1]+'</div>';
					}

					if(arrBaiduCproConfig['bu']=='1' || arrBaiduCproConfig['bu']==1)
					{
						strBaiduCproOut +='<div style="color:'+arrBaiduCproConfig['url']+';text-decoration:none;font-size:11px">'+arrBaiduCproData[index][2].replace(/^(\w+:\/\/)?([^\/]+).*$/ig,'$2')+'</div>';
					}
					strBaiduCproOut +='</a>';
					index++;
				}
				strBaiduCproOut +='</td>';
			}
			strBaiduCproOut +='</tr>';
			if (index>=arrBaiduCproData.length)
			{
				break;
			}
		}

		if(arrBaiduCproConfig['tl'] == 'bottom'){
			strBaiduCproOut+=strBaiduCproTitle;
		}
		strBaiduCproOut += '</table>';
		strBaiduCproOut = baiduCproWriteStyle()+strBaiduCproOut;
	}
	
	if (intBaiduCproDebug==1)
	{
		return strBaiduCproOut;
	}
	else
	{
		document.write(strBaiduCproOut);
	}
}

function baiduCproGetUri(strBaiduCproUrl)
{
	strBaiduCproGetParamMap = ',w|rsi0,h|rsi1,bu|rsi2,nfr|rsi5,bd|rss0,bg|rss1,tt|rss2,ct|rss3,url|rss4,bdl|rss5,ta|rssl0,tl|rssl1,';

	strBaiduCproUiUri = strBaiduCproUiUrl;
	for (key in arrBaiduCproConfig){
		if ((key =='uid')||(key =='n')||(key =='tm')||(key =='cm')||(key =='um')||(key =='rad')||(key =='w')||(key =='h')||(key =='bd')||(key =='bg')||(key =='tt')||(key =='ct')||(key =='url')||(key =='bdl')||(key =='wn')||(key =='hn')||(key=='bu')||(key == 'ta')||(key == 'tl'))
		{
			strBaiduCproUiUrlRegExp = '/^.*,'+key+'\\|([^,]+),.*$/ig';
			strBaiduCproUiUrlParamName = eval('strBaiduCproGetParamMap.match(' + strBaiduCproUiUrlRegExp + ')?strBaiduCproGetParamMap.replace(' + strBaiduCproUiUrlRegExp + ',"$1"):"' + key + '"');
			strBaiduCproUiUri += '&'+strBaiduCproUiUrlParamName+'='+escape(arrBaiduCproConfig[key]);
		}
	}
	if(strBaiduCproUrl=='')	{
		strBaiduCproUrl= document.referrer;
		if (top.location == document.location) 	{
		      strBaiduCproUrl = document.location;    
		}
	}
	strBaiduCproUiUri += '&word=';
	strBaiduCproUiUri += typeof(encodeURIComponent)=='function' ? encodeURIComponent(strBaiduCproUrl) : escape(strBaiduCproUrl);
	return strBaiduCproUiUri;

}
function baiduCproGetIFrame()
{
	return '<iframe marginWidth=0 marginHeight=0 scrolling=no frameBorder=0 width='+arrBaiduCproConfig['w']+' height='+arrBaiduCproConfig['h']+' allowtransparency="1"  ;  src="'+baiduCproGetUri('')+'"></iframe>';		
}

function baiduCproIFrame()
{
	var baiduCproImg = new Image();
	baiduCproImg.src = "http://cpro.baidu.com/refer.php?" + escape(document.referrer);	
	var myBaiduCpro=document.getElementById("baiduCpro");	
	var strBaiduCproRet="";
	if(myBaiduCpro!=null)
	{	
		strBaiduCproRet+="<script language=\"javascript\">";
		strBaiduCproRet+="document.getElementById(\"baiduCpro\").innerHTML = baiduCproGetIFrame();"
		strBaiduCproRet+="</script>"	
	}
	else
	{
		strBaiduCproRet+=baiduCproGetIFrame();		
	}
	return strBaiduCproRet;
}

function RegexEscape(str)
{
	regstr = /([\\\/\.\?\+\*\(\)\[\]\{\}\^\$\|\=\!\:])/g;
	return str.replace(regstr, '\\$1');
}	
