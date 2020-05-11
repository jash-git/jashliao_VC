(function(){








if( window == top ){
    

        (function(){(function(a,b,c){function d(a){return"[object Function]"==o.call(a)}function e(a){return"string"==typeof a}function f(){}function g(a){return!a||"loaded"==a||"complete"==a||"uninitialized"==a}function h(){var a=p.shift();q=1,a?a.t?m(function(){("c"==a.t?B.injectCss:B.injectJs)(a.s,0,a.a,a.x,a.e,1)},0):(a(),h()):q=0}function i(a,c,d,e,f,i,j){function k(b){if(!o&&g(l.readyState)&&(u.r=o=1,!q&&h(),l.onload=l.onreadystatechange=null,b)){"img"!=a&&m(function(){t.removeChild(l)},50);for(var d in y[c])y[c].hasOwnProperty(d)&&y[c][d].onload()}}var j=j||B.errorTimeout,l=b.createElement(a),o=0,r=0,u={t:d,s:c,e:f,a:i,x:j};1===y[c]&&(r=1,y[c]=[]),"object"==a?l.data=c:(l.src=c,l.type=a),l.width=l.height="0",l.onerror=l.onload=l.onreadystatechange=function(){k.call(this,r)},p.splice(e,0,u),"img"!=a&&(r||2===y[c]?(t.insertBefore(l,s?null:n),m(k,j)):y[c].push(l))}function j(a,b,c,d,f){return q=0,b=b||"j",e(a)?i("c"==b?v:u,a,b,this.i++,c,d,f):(p.splice(this.i++,0,a),1==p.length&&h()),this}function k(){var a=B;return a.loader={load:j,i:0},a}var l=b.documentElement,m=a.setTimeout,n=b.getElementsByTagName("script")[0],o={}.toString,p=[],q=0,r="MozAppearance"in l.style,s=r&&!!b.createRange().compareNode,t=s?l:n.parentNode,l=a.opera&&"[object Opera]"==o.call(a.opera),l=!!b.attachEvent&&!l,u=r?"object":l?"script":"img",v=l?"script":u,w=Array.isArray||function(a){return"[object Array]"==o.call(a)},x=[],y={},z={timeout:function(a,b){return b.length&&(a.timeout=b[0]),a}},A,B;B=function(a){function b(a){var a=a.split("!"),b=x.length,c=a.pop(),d=a.length,c={url:c,origUrl:c,prefixes:a},e,f,g;for(f=0;f<d;f++)g=a[f].split("="),(e=z[g.shift()])&&(c=e(c,g));for(f=0;f<b;f++)c=x[f](c);return c}function g(a,e,f,g,h){var i=b(a),j=i.autoCallback;i.url.split(".").pop().split("?").shift(),i.bypass||(e&&(e=d(e)?e:e[a]||e[g]||e[a.split("/").pop().split("?")[0]]),i.instead?i.instead(a,e,f,g,h):(y[i.url]?i.noexec=!0:y[i.url]=1,f.load(i.url,i.forceCSS||!i.forceJS&&"css"==i.url.split(".").pop().split("?").shift()?"c":c,i.noexec,i.attrs,i.timeout),(d(e)||d(j))&&f.load(function(){k(),e&&e(i.origUrl,h,g),j&&j(i.origUrl,h,g),y[i.url]=2})))}function h(a,b){function c(a,c){if(a){if(e(a))c||(j=function(){var a=[].slice.call(arguments);k.apply(this,a),l()}),g(a,j,b,0,h);else if(Object(a)===a)for(n in m=function(){var b=0,c;for(c in a)a.hasOwnProperty(c)&&b++;return b}(),a)a.hasOwnProperty(n)&&(!c&&!--m&&(d(j)?j=function(){var a=[].slice.call(arguments);k.apply(this,a),l()}:j[n]=function(a){return function(){var b=[].slice.call(arguments);a&&a.apply(this,b),l()}}(k[n])),g(a[n],j,b,n,h))}else!c&&l()}var h=!!a.test,i=a.load||a.both,j=a.callback||f,k=j,l=a.complete||f,m,n;c(h?a.yep:a.nope,!!i),i&&c(i)}var i,j,l=this.yepnope.loader;if(e(a))g(a,0,l,0);else if(w(a))for(i=0;i<a.length;i++)j=a[i],e(j)?g(j,0,l,0):w(j)?B(j):Object(j)===j&&h(j,l);else Object(a)===a&&h(a,l)},B.addPrefix=function(a,b){z[a]=b},B.addFilter=function(a){x.push(a)},B.errorTimeout=1e4,null==b.readyState&&b.addEventListener&&(b.readyState="loading",b.addEventListener("DOMContentLoaded",A=function(){b.removeEventListener("DOMContentLoaded",A,0),b.readyState="complete"},0)),a.yepnope=k(),a.yepnope.executeStack=h,a.yepnope.injectJs=function(a,c,d,e,i,j){var k=b.createElement("script"),l,o,e=e||B.errorTimeout;k.src=a;for(o in d)k.setAttribute(o,d[o]);c=j?h:c||f,k.onreadystatechange=k.onload=function(){!l&&g(k.readyState)&&(l=1,c(),k.onload=k.onreadystatechange=null)},m(function(){l||(l=1,c(1))},e),i?k.onload():n.parentNode.insertBefore(k,n)},a.yepnope.injectCss=function(a,c,d,e,g,i){var e=b.createElement("link"),j,c=i?h:c||f;e.href=a,e.rel="stylesheet",e.type="text/css";for(j in d)e.setAttribute(j,d[j]);g||(n.parentNode.insertBefore(e,n),m(c,0))}})(this,document),sfjq={originalJq:window.jQuery,jq:null,
        load:function(a){
            var b = this;
            this.url = a.url || "https://ajax.googleapis.com/ajax/libs/jquery/1.7/jquery.min.js";
            this.callback = a.callback || !1;
            try {
                yepnope([{
                    load: b.url,
                    callback: function () {
                        (function (a) {
                            b.jq = jQuery.noConflict(!0), 
                            window.jQuery = b.originalJq, 
                            sfjq.jq.expr[":"].regex = function (a, b, c) {
                                var d = c[3].split(","),
                                e = /^(data|css):/,
                                f = {
                                    method: d[0].match(e) ? d[0].split(":")[0] : "attr",
                                    property: d.shift().replace(e, "")
                                }, g = "ig",
                                h = new RegExp(d.join("").replace(/^\s+|\s+$/g, ""), g);
                                return h.test(sfjq.jq(a)[f.method](f.property))
                            }, b.callback && b.callback.call(window)
                        })(jQuery)
                    }
                }]);
            }
            catch(ex) {
                    superfish.b.inj(window.document, this.url,
                        1,
                        (function(jq){
                            if (!spsupport.p.jJqcb) {
                                spsupport.p.jJqcb = 1;
                                spsupport.p.$ = jq;
                                window.jQuery = sfjq.originalJq,
                                spsupport.api.jQLoaded();
                            }                        
                        })(jQuery));
            }
    }},window.sfjq=sfjq})()
        superfish.utilities = {
    blacklistHandler: blacklistHandler = function(){
        var WSblacklist = "|delta-search.com|architecte3d.com|zazzle.com|mycouponbuddy.com|leobell.net|fotosnaturaleza.es|www.easymobility.co.uk|www.theground-up.com|www.thegroundup-ssi.com|portail.dartybox.com|gadgets-toons-cadeaux.com|mercadolibre.com.ar|mercaodlibre.com.co|mercadolibre.com.cr|mercadolibre.com.cl|mercadolibre.com.do|mercadolibre.com.ec|mercadolibre.com.mx|mercadolibre.com.pa|mercadolibre.com.pe|mercadolibre.com.pt|mercadolibre.com.uy|mercadolibre.com.ve|mercadolivre.com.br|mercadolivre.com|abajournal.com|alexa.com|autotrader.com|baidu.com|bedandbreakfast.com|bernadettelivingston.com|beso.com|birdviewprojects.com|bizrate.com|booking.com|cam4.com|cj.com|cnn.com|crunchyroll.com|cvsphoto.com|dcinside.com|deviantart.com|drudgereport.com|facebook.com|flickr.com|furniture-quest.com|history.com|hotmail.com|imdb.com|imvu.com|linkedin.com|lolhehehe.com|lowpriceshopper.com|microsoft.com|mercadolivre.com|msn.com|myspace.com|netflix.com|nytimes.com|pandora.com|picasa.com|pinterest.com|politico.com|polybags4less.com|pricegrabber.com|publicstorage.com|qq.com|rue89.com|salon.com|searchenginewatch.com|sfgate.com|shopzilla.com|shutterfly.com|sommerfrischeamsemmering.wg.vu|spardeingeld.com|techcrunch.com|usamm.com|verizon.com|venturebeat.com|westsiderentals.com|wired.com|yankodesign.com|yahoo.com|youtube.com|";
        var WSAddblacklist = "|123inkjets.com|24hourfitness.com|4inkjets.com|6pm.com|att.com|adobe.com|adorama.com|shop.com|advanceautoparts.com|audible.com|autopartswarehouse.com|avenue.com|backcountry.com|basspro.com|bestbuy.com|bodenusa.com|brooksbrothers.com|carbonite.com|celebrateexpress.com|chainlove.com|chegg.com|competitivecyclist.com|dell.com|departmentofgoods.com|dogfunk.com|endless.com|ftd.com|footsmart.com|gamefly.com|gamehouse.com|gap.com|garmin.com|golfnow.com|hp.com|snapfish.com|hsn.com|harryanddavid.com|homedecorators.com|homedepot.com|lenovo.com|lightinthebox.com|lowes.com|musiciansfriend.com|newegg.com|overstock.com|petco.com|qvc.com|quill.com|rei.com|shindigz.com|shoebuy.com|shopbop.com|skinstore.com|store.com|sony.com|staples.com|strawberrynet.com|tirerack.com|harryanddavid.com|footsmart.com|plaingreenloans.com|fansedge.com|hottopic.com|ecampus.com|gotomypc.com|buycostumes.com|keen.com|crucial.com|altrec.com|blair.com|smoothfitness.com|callawaygolfpreowned.com|fonts.com|perfumania.com|graveyardmall.com|wbshop.com|framesdirect.com|lids.com|fragrancex.com|tracfone.com|cyberlink.com|golfsmith.com|trendmicro.com|ingdirect.com|shoemall.com|fossil.com|autoanything.com|shopperschoice.com|josbank.com|bodycandy.com|fanatics.com|coffeeforless.com|marylandsquare.com|oakley.com|softsurroundings.com|realcyclist.com|roxio.com|entirelypets.com|lens.com|steepandcheap.com|stamps.com|shoeline.com|vitaminshoppe.com|masoneasypay.com|rosettastone.com|cooking.com|shopjustice.com|dog.com|bird.com|fish.com|masseys.com|thinkgeek.com|venturebeat.com|whiskeymalitia.com|polybags4less.com|pricegrabber.com|zappos.com|sears.com|";
        var CPNblacklist = ";delta-search.com;pandora.com;go.com;facebook.com;mycouponbuddy.com;yahoo.com;cashnetusa.com;hulu.com;google.com;ebay.com;ihg.com;publicstorage.com;youtube.com;travelocity.com;";
        var CPNenabled = "0";
        var CpnEnabledData = CPNenabled.split('|');
        var WSBL = null; // black list value stays. to avoid double checking.
        var CPNBL = null; // Coupons black list value stays. to avoid double checking.

        CpnEnabledData[0] = (+CpnEnabledData[0]);
        CpnEnabledData[1] = (+CpnEnabledData[1]);

        if(CpnEnabledData[0])
            WSblacklist += WSAddblacklist;

        function isWSBlacklist(){
            if(!WSBL)
                isBlacklist();
            return WSBL;
        }

        function isCPNBlacklist(){
            if(!CPNBL)
                isBlacklist();
            return CPNBL;
        }

        function isBlacklist(){
            if(WSBL != null && CPNBL != null)
                return; // sinse we already were inside this.

            WSBL = 0;
            CPNBL = 0;

            var ourHostName = document.location.host;
            var subsHosts;

            if (ourHostName == undefined || ourHostName.length == 0)
                return;

            ourHostName = ourHostName.toLowerCase();
            subsHosts = ourHostName.replace(/[^.]/g, "").length; // how many time there are "."
            for(var i=0 ; i < subsHosts ; i++) {
                if(WSblacklist.indexOf("|"+ourHostName+"|") != -1){
                    WSBL = 1;
                }
                if(CPNblacklist.indexOf(";"+ourHostName+";") != -1){
                    CPNBL = 1;
                }
                ourHostName = ourHostName.substring(ourHostName.indexOf(".")+1,ourHostName.length);
            }
        }

        function getCpnData(){
            return CpnEnabledData;
        }

        function getWSBlacklist(){
            return WSblacklist;
        }

        return {
            isWSBlacklist : isWSBlacklist,
            isCPNBlacklist : isCPNBlacklist,
            getCpnData : getCpnData,
            getWSBlacklist : getWSBlacklist
        };

    }(),

    getUserHash: function(){
        var nowTime = new Date();
        var chr;
        var userHash = 0 ;
        var str = navigator.userAgent + navigator.platform + screen.height + screen.pixelDepth + screen.width + nowTime.getTimezoneOffset();
        str = str.toLowerCase();
        for (var i = 0; i < str.length; i++) {
            chr = str.charCodeAt(i);
            userHash = ((userHash<<5)-userHash)+chr;
            userHash = userHash & userHash; // Convert to 32bit integer
        }
        if(userHash<0)
            userHash=userHash*(-1);

        return userHash;
    },

    versionManager: versionManager = function(){
        function useNewVer(groupsDivNum ,Sdate, Edate){ // date format 2012.12.30
            if(!groupsDivNum)
                groupsDivNum = 100;
            var totalDays,daysLeft,daysBeen,MyDownloadGroup;
            var groupJumps;
            var nowTime = new Date();

            daysLeft = compareDates(nowTime, Edate);
            if(daysLeft <= 0)
                return true; // new version

            MyDownloadGroup = superfish.utilities.getGroup(groupsDivNum);

            totalDays = compareDates(Sdate, Edate);
            daysBeen = compareDates(Sdate, nowTime);
            daysBeen++;

            groupJumps = Math.round(daysBeen*(groupsDivNum/totalDays));

            if(MyDownloadGroup <= groupJumps)
                return true; // use new version
            else
                return false; // use old version
        }

        function compareDates(OD,ND){//od = old date, nd= new date
            if(!OD || !ND){
                return -1;
            }

            var miliDays=1000*60*60*24;
            var dif;
            nowTime = getRealDate(OD);
            NewDate = getRealDate(ND);

            dif=(NewDate.getTime()-nowTime.getTime())/miliDays;
            dif=Math.round(dif);
            return dif;
        }

        function getRealDate(Ldate){ //yyyy.mm.dd
            if(!Ldate){
                return 0;
            }
            if(Ldate.getTime){
                return Ldate;
            }
            var tSp=Ldate.split('.');
            var newTime= new Date();
            newTime.setYear(tSp[0]);
            newTime.setMonth(tSp[1]-1);
            newTime.setDate(tSp[2]);
            return newTime;
        }

        return {
            useNewVer: useNewVer
        };

    }(),

    getGroup: function (groupsDiv){
        var userHash = superfish.utilities.getUserHash();
        var usrGroupNumber = (userHash % groupsDiv);
        return(usrGroupNumber);
    },

    abTestUser: function(groupDevision, abTestGroupMax){ // (100 groups get 0-3 of people = (100,3)
        abTestGroupMax--;
        var currGroup = superfish.utilities.getGroup(groupDevision);
        return (abTestGroupMax >= currGroup);
    }
};
        spsupport = {
            log : function(){if (window.console) {for(var i in arguments) {console.log(arguments[i]);}}},
            dtBr: dtBr = function(matchStr) {
    var ua = navigator.userAgent;
    var br = "unknown";
    if (ua) {ua = ua.toLowerCase();if (ua.indexOf("msie 7") > -1){br = "ie7";}
    else if (ua.indexOf("msie 8") > -1) {br = "ie8";}
    else if (ua.indexOf("msie 9") > -1) {br = "ie9";}
    else if (ua.indexOf("msie 10") > -1 ) {br = "ie10"}
    else if (ua.indexOf("firefox/5") > -1) {br = "ff5";}
    else if (ua.indexOf("firefox/6") > -1) {br = "ff6";}
    else if (ua.indexOf("firefox/7") > -1) {br = "ff7";}
    else if (ua.indexOf("firefox/8") > -1) {br = "ff8";}
    else if (ua.indexOf("firefox/9") > -1) {br = "ff9";}
    else if (ua.indexOf("firefox/10") > -1) {br = "ff10";}
    else if (ua.indexOf("firefox") > -1) {br = "ff";}
    else if (ua.indexOf("chrome") > -1) {br = "ch";}
    else if (ua.indexOf("apple") > -1) {br = "sa";}}
    return matchStr ? br.indexOf(matchStr) > 0 : br;
}

        };
        if( window.location.href.indexOf( "amazon.com/" ) > 0 && window.location.href.indexOf( "/search/" ) > 0 && window.location.href.indexOf( "#sf" ) > 0 ){
            window.location.replace( window.location.href.substring( 0, window.location.href.indexOf( "#sf" ) ) );
        }
        spsupport.b = {};
        spsupport.br = { isIE7: (navigator.userAgent.toLowerCase().indexOf("msie 7") > -1)};

        superfish.b.// This function extracts key value data from the selected querystring obj
// Input parameters:
// obj_to_add = the desired object to add the querystring object into
// initial_QS the querystring value

setQueryString = function(obj_to_add,initial_QS){
    obj_to_add.qsObj={};
    initial_QS.replace(
        new RegExp("([^?=&]+)(=([^&]*))?", "g"),
        function($0, $1, $2, $3) { 
            obj_to_add.qsObj[$1] = decodeURIComponent($3); }
    );
}

        superfish.b.setQueryString(superfish.b, superfish.b.initialQS);
        if (!superfish.b.qsObj.statsReporter) {
            superfish.b.qsObj.statsReporter = "true";
        }
        if (!superfish.b.qsObj.dlsource) {
            superfish.b.qsObj.dlsource = "zumzqir";
        }
        superfish.b.qsObj.userid = superfish.b.qsObj.userid || "";
        if (superfish.b.qsObj.dlsource == "pagetweak" && superfish.b.qsObj.userid == "") {
              superfish.b.qsObj.userid = superfish.b.qsObj.dlsource;
        }
        superfish.b.qsObj.CTID = (superfish.b.qsObj.CTID == "null" ? "" : (superfish.b.qsObj.CTID || ""));
        spsupport.isShowConduitWinFirstTimeIcons = superfish.b.qsObj.isShowConduitWinFirstTimeIcons == "true" || superfish.b.qsObj.isShowConduitWinFirstTimeIcons == "1";

        if (!superfish.utilities.blacklistHandler.isWSBlacklist() || !superfish.utilities.blacklistHandler.isCPNBlacklist()) {
            superfish.b.inj(window.document, "https://www.superfish.com/ws/sf_code.jsp" + superfish.b.initialQS, 1);
        }
        superfish.partner = {};

superfish.partner.init = function() {
    if (this._init) { this._init(); }
};

superfish.partner.logoClick = function() {
    if (this._logoClick) { this._logoClick(); }
};

        superfish.publisher = {};
superfish.publisher.reqCount = 0;
superfish.publisher.valCount = 0;
superfish.publisher.imgs = [];
superfish.publisher.limit = 0;

superfish.publisher.init = function() {
    if (this._init) {
        this._init();
    }
};

superfish.publisher.pushImg = function(img) {
    var cond = (spsupport.whiteStage.rv || spsupport.whiteStage.st || (superfish.sg && superfish.sg.sSite ? true : this.imgs.length < this.limit));
    // var cond = this.imgs.length < this.limit;
    if(superfish.b.multiImg && cond){
        this.imgs[ this.imgs.length ] = img;
        if( !this.reqCount ){
            this.send();
        }
    }
};

superfish.publisher.send = function() { 
 //   spsupport.log("send " + this.reqCount + "  " + this.limit + "  " +  this.valCount +  "  " + this.imgs.length);
    if (superfish.b.multiImg && this.reqCount < this.limit && this.valCount < this.imgs.length) {
        var im = this.imgs[this.valCount];
        var imgPos = spsupport.api.getImagePosition(im);
        var val = spsupport.api.validateSU(im, parseInt(imgPos.y + im.height - 45));
        // spsupport.log("validate = " + val);
        this.reqCount += val;
        this.valCount++;
    }
    else {
        // superfish.util.bCloseEvent( document.getElementById("SF_CloseButton"), 2 );
        spsupport.p.prodPage.e = 1;
    }
};

superfish.publisher.fixSuPos = function(top) {
    return (this._fixSuPos ? this._fixSuPos(top) : top);
};

superfish.publisher.report = function(action) {
    if (this._report) {
        this._report(action);
    }
};

superfish.publisher.extractTxt = function(img) {
    if (this._extractTxt) {
        return this._extractTxt(img);
    }
    else {
        return '';
    }
};




}

}());