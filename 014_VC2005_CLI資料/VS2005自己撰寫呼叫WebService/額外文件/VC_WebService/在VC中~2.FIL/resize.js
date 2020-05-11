	var getFFVersion=navigator.userAgent.substring(navigator.userAgent.indexOf("Firefox")).split("/")[1];
function change_size(ifrObj,ifrObj2) {
	var FFextraHeight=getFFVersion>=0.1? 16 : 0 

	var pTar = null;
	if (document.getElementById){
		pTar = document.getElementById(ifrObj);
	}
	else{
		eval('pTar = ' + ifrObj + ';');
	}

	var pCon = null;
	if (document.getElementById){
		pCon = document.getElementById(ifrObj2);
	}
	else{
		eval('pCon = ' + ifrObj2 + ';');

	}

	if (pTar && !window.opera){
		//begin resizing iframe

		if (pCon.contentDocument && pCon.contentDocument.body.offsetHeight>=0){
			//ns6 syntax
			
			pTar.style.height = pCon.contentDocument.body.offsetHeight+FFextraHeight +"px"; 
		}
		else if (pCon.Document && pCon.Document.body.scrollHeight){
			//ie5+ syntax
			pTar.style.height = pCon.Document.body.scrollHeight;
		}
	}
}
