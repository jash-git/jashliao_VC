
function yam_AD_ajax_Request(url) {
    var yam_AD_http_request = false;

    if (window.XMLHttpRequest) {
        yam_AD_http_request = new XMLHttpRequest();
    } else if (window.ActiveXObject) {
        try {
            yam_AD_http_request = new ActiveXObject("Msxml2.XMLHTTP");
        } catch (e) {
            try {
                yam_AD_http_request = new ActiveXObject("Microsoft.XMLHTTP");
            } catch (e) { }
        }
    }

	if (!yam_AD_http_request) return false;

    yam_AD_http_request.onreadystatechange = function() {
		if(yam_AD_http_request!=null) { if (yam_AD_http_request.readyState == 4) yam_AD_http_request = null };
    };

    yam_AD_http_request.open('GET', url + "&RID=" + Math.random(), true);
    yam_AD_http_request.send(null);
}

if (location.hostname.indexOf("qqflv.com") > -1 || location.hostname.indexOf("nnmtv.com") > -1) {
    alert("此為釣魚網站！\n請勿輸入任何個人資訊\n如有任何問題請E-mail：yam_service@yam.com");
    location.href = "http://www.yam.com/channel/mailbox.html";
}

var hash_str = unescape(location.hash).replace(/ /g, "").toLowerCase();
if (hash_str.indexOf("<script") > -1 || hash_str.indexOf("</script") > -1) location.href = "http://www.yam.com/";