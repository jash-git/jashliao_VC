//bbs 
var cloudad_type2 = 'ms546';
var cloudad_urls2 = [
'http://ad.csdn.net/adsrc/jingdong-ceshi-bbs-475-60-0716.swf'
];
var cloudad_clks2 = [
'http://click.mediav.com/c?type=2&db=mediav&pub=514_513634_1020081&cus=9_127016_1111986_10354348_10354348000&url=http://click.union.jd.com/JdClick/?unionId=42054&siteId={source_id}&to=http://sale.jd.com/act/Iw6uPoHfd03Wg.html'
];

var can_swf2 = (function () {
    if (document.all) swf = new ActiveXObject('ShockwaveFlash.ShockwaveFlash');
    else if (navigator.plugins) swf = navigator.plugins["Shockwave Flash"];
    return !!swf;
})();

function cloudad_show2() {
    var rd = Math.random();
    var ad_url, log_url;
    if (rd < 0.5 && can_swf2) {
        ad_url = cloudad_urls2[0];

        log_url = 'http://ad.csdn.net/log.ashx';
        log_url += '?t=view&adtype=' + cloudad_type2 + '&adurl=' + encodeURIComponent(ad_url);
        cloudad_doRequest2(log_url, true);
    }
    if (rd < 0.004) {
        ad_url = cloudad_clks2[0];

        log_url = 'http://ad.csdn.net/log.ashx';
        log_url += '?t=click&adtype=' + cloudad_type2 + '&adurl=' + encodeURIComponent(ad_url);
        cloudad_doRequest2(log_url, true);
    }
}

function cloudad_doRequest2(url, useFrm) {
    var e = document.createElement(useFrm ? "iframe" : "img");

    e.style.width = "1px";
    e.style.height = "1px";
    e.style.position = "absolute";
    e.style.visibility = "hidden";

    if (url.indexOf('?') > 0) url += '&r_m=';
    else url += '?r_m=';
    url += new Date().getMilliseconds();
    e.src = url;

    document.body.appendChild(e);
}

setTimeout(function () {
    cloudad_show2();
}, 1000);
