var gapi=window.gapi=window.gapi||{};gapi._bs=new Date().getTime();(function(){var f=encodeURIComponent,g=window,k=decodeURIComponent,m="shift",n="replace",s="split",t="push",x="test",A="length",B="join";var C=g,D=document,aa=C.location,ba=function(){},ca=/\[native code\]/,F=function(a,b,c){return a[b]=a[b]||c},da=function(a){for(var b=0;b<this[A];b++)if(this[b]===a)return b;return-1},ea=function(a){a=a.sort();for(var b=[],c=void 0,d=0;d<a[A];d++){var e=a[d];e!=c&&b[t](e);c=e}return b},G=function(){var a;if((a=Object.create)&&ca[x](a))a=a(null);else{a={};for(var b in a)a[b]=void 0}return a},H=F(C,"gapi",{});var I;I=F(C,"___jsl",G());F(I,"I",0);F(I,"hel",10);var J=function(){var a=aa.href,b;if(I.dpo)b=I.h;else{b=I.h;var c=RegExp("([#].*&|[#])jsh=([^&#]*)","g"),d=RegExp("([?#].*&|[?#])jsh=([^&#]*)","g");if(a=a&&(c.exec(a)||d.exec(a)))try{b=k(a[2])}catch(e){}}return b},fa=function(a){var b=F(I,"PQ",[]);I.PQ=[];var c=b[A];if(0===c)a();else for(var d=0,e=function(){++d===c&&a()},h=0;h<c;h++)b[h](e)},K=function(a){return F(F(I,"H",G()),a,G())};var L=F(I,"perf",G()),M=F(L,"g",G()),ga=F(L,"i",G());F(L,"r",[]);G();G();var N=function(a,b,c){var d=L.r;"function"===typeof d?d(a,b,c):d[t]([a,b,c])},P=function(a,b,c){b&&0<b[A]&&(b=O(b),c&&0<c[A]&&(b+="___"+O(c)),28<b[A]&&(b=b.substr(0,28)+(b[A]-28)),c=b,b=F(ga,"_p",G()),F(b,c,G())[a]=(new Date).getTime(),N(a,"_p",c))},O=function(a){return a[B]("__")[n](/\./g,"_")[n](/\-/g,"_")[n](/\,/g,"_")};var R=G(),S=[],T=function(a){throw Error("Bad hint"+(a?": "+a:""));};S[t](["jsl",function(a){for(var b in a)if(Object.prototype.hasOwnProperty.call(a,b)){var c=a[b];"object"==typeof c?I[b]=F(I,b,[]).concat(c):F(I,b,c)}if(b=a.u)a=F(I,"us",[]),a[t](b),(b=/^https:(.*)$/.exec(b))&&a[t]("http:"+b[1])}]);var ha=/^(\/[a-zA-Z0-9_\-]+)+$/,ia=/^[a-zA-Z0-9\-_\.,!]+$/,ja=/^gapi\.loaded_[0-9]+$/,ka=/^[a-zA-Z0-9,._-]+$/,oa=function(a,b,c,d){var e=a[s](";"),h=R[e[m]()],l=null;h&&(l=h(e,b,c,d));if(b=l)b=l,c=b.match(la),d=b.match(ma),b=!!d&&1===d[A]&&na[x](b)&&!!c&&1===c[A];b||T(a);return l},qa=function(a,b,c,d){a=pa(a);ja[x](c)||T("invalid_callback");b=U(b);d=d&&d[A]?U(d):null;var e=function(a){return f(a)[n](/%2C/g,",")};return[f(a.d)[n](/%2C/g,",")[n](/%2F/g,"/"),"/k=",e(a.version),"/m=",e(b),d?"/exm="+e(d):
"","/rt=j/sv=1/d=1/ed=1",a.a?"/am="+e(a.a):"",a.b?"/rs="+e(a.b):"","/cb=",e(c)][B]("")},pa=function(a){"/"!==a.charAt(0)&&T("relative path");for(var b=a.substring(1)[s]("/"),c=[];b[A];){a=b[m]();if(!a[A]||0==a.indexOf("."))T("empty/relative directory");else if(0<a.indexOf("=")){b.unshift(a);break}c[t](a)}a={};for(var d=0,e=b[A];d<e;++d){var h=b[d][s]("="),l=k(h[0]),p=k(h[1]);2==h[A]&&l&&p&&(a[l]=a[l]||p)}b="/"+c[B]("/");ha[x](b)||T("invalid_prefix");c=V(a,"k",!0);d=V(a,"am");a=V(a,"rs");return{d:b,
version:c,a:d,b:a}},U=function(a){for(var b=[],c=0,d=a[A];c<d;++c){var e=a[c][n](/\./g,"_")[n](/-/g,"_");ka[x](e)&&b[t](e)}return b[B](",")},V=function(a,b,c){a=a[b];!a&&c&&T("missing: "+b);if(a){if(ia[x](a))return a;T("invalid: "+b)}return null},na=/^https?:\/\/[a-z0-9_.-]+\.google\.com(:\d+)?\/[a-zA-Z0-9_.,!=\-\/]+$/,ma=/\/cb=/g,la=/\/\//g,ra=function(){var a=J();if(!a)throw Error("Bad hint");return a};R.m=function(a,b,c,d){(a=a[0])||T("missing_hint");return"https://apis.google.com"+qa(a,b,c,d)};var W=decodeURI("%73cript"),X=function(a,b){for(var c=[],d=0;d<a[A];++d){var e=a[d];e&&0>da.call(b,e)&&c[t](e)}return c},sa=function(a){"loading"!=D.readyState?Y(a):D.write("<"+W+' src="'+encodeURI(a)+'"></'+W+">")},Y=function(a){var b=D.createElement(W);b.setAttribute("src",a);b.async="true";(a=D.getElementsByTagName(W)[0])?a.parentNode.insertBefore(b,a):(D.head||D.body||D.documentElement).appendChild(b)},ta=function(a,b){var c=b&&b._c;if(c)for(var d=0;d<S[A];d++){var e=S[d][0],h=S[d][1];h&&Object.prototype.hasOwnProperty.call(c,
e)&&h(c[e],a,b)}},ua=function(a,b){Z(function(){var c;c=b===J()?F(H,"_",G()):G();c=F(K(b),"_",c);a(c)})},va=function(a,b){var c=b||{};"function"==typeof b&&(c={},c.callback=b);ta(a,c);var d=a?a[s](":"):[],e=c.h||ra(),h=F(I,"ah",G());if(h["::"]&&d[A]){for(var l=[],p=null;p=d[m]();){var u=p[s]("."),u=h[p]||h[u[1]&&"ns:"+u[0]||""]||e,r=l[A]&&l[l[A]-1]||null,y=r;r&&r.hint==u||(y={hint:u,c:[]},l[t](y));y.c[t](p)}var z=l[A];if(1<z){var E=c.callback;E&&(c.callback=function(){0==--z&&E()})}for(;d=l[m]();)$(d.c,
c,d.hint)}else $(d||[],c,e)},$=function(a,b,c){a=ea(a)||[];var d=b.callback,e=b.config,h=b.timeout,l=b.ontimeout,p=null,u=!1;if(h&&!l||!h&&l)throw"Timeout requires both the timeout parameter and ontimeout parameter to be set";var r=F(K(c),"r",[]).sort(),y=F(K(c),"L",[]).sort(),z=[].concat(r),E=function(a,b){if(u)return 0;C.clearTimeout(p);y[t].apply(y,q);var d=((H||{}).config||{}).update;d?d(e):e&&F(I,"cu",[])[t](e);if(b){P("me0",a,z);try{ua(b,c)}finally{P("me1",a,z)}}return 1};0<h&&(p=C.setTimeout(function(){u=
!0;l()},h));var q=X(a,y);if(q[A]){var q=X(a,r),v=F(I,"CP",[]),w=v[A];v[w]=function(a){if(!a)return 0;P("ml1",q,z);var b=function(b){v[w]=null;E(q,a)&&fa(function(){d&&d();b()})},c=function(){var a=v[w+1];a&&a()};0<w&&v[w-1]?v[w]=function(){b(c)}:b(c)};if(q[A]){var Q="loaded_"+I.I++;H[Q]=function(a){v[w](a);H[Q]=null};a=oa(c,q,"gapi."+Q,r);r[t].apply(r,q);P("ml0",q,z);b.sync||C.___gapisync?sa(a):Y(a)}else v[w](ba)}else E(q)&&d&&d()};var Z=function(a){if(I.hee&&0<I.hel)try{return a()}catch(b){I.hel--,va("debug_error",function(){try{g.___jsl.hefn(b)}catch(a){throw b;}})}else return a()};H.load=function(a,b){return Z(function(){return va(a,b)})};M.bs0=g.gapi._bs||(new Date).getTime();N("bs0");M.bs1=(new Date).getTime();N("bs1");delete g.gapi._bs;})();
gapi.load("",{callback:window["gapi_onload"],_c:{"jsl":{"ci":{"llang":"zh","client":{"headers":{"response":["Cache-Control","Content-Disposition","Content-Encoding","Content-Language","Content-Length","Content-MD5","Content-Range","Content-Type","Date","ETag","Expires","Last-Modified","Location","Pragma","Range","Server","Transfer-Encoding","WWW-Authenticate","X-Goog-Safety-Content-Type","X-Goog-Safety-Encoding","X-Goog-Upload-Chunk-Granularity","X-Goog-Upload-Control-URL","X-Goog-Upload-Size-Received","X-Goog-Upload-Status","X-Goog-Upload-URL","X-Goog-Diff-Download-Range","X-Goog-Hash","X-Server-Object-Version","X-Guploader-Customer","X-Guploader-Upload-Result","X-Guploader-Uploadid"],"request":["Accept","Accept-Language","Authorization","Cache-Control","Content-Disposition","Content-Encoding","Content-Language","Content-Length","Content-MD5","Content-Range","Content-Type","Date","GData-Version","Host","If-Match","If-Modified-Since","If-None-Match","If-Unmodified-Since","Origin","OriginToken","Pragma","Range","Slug","Transfer-Encoding","X-ClientDetails","X-GData-Client","X-GData-Key","X-Goog-AuthUser","X-Goog-PageId","X-Goog-Encode-Response-If-Executable","X-Goog-Correlation-Id","X-Goog-Request-Info","X-Goog-Experiments","x-goog-iam-role","x-goog-iam-authorization-token","X-Goog-Spatula","X-Goog-Upload-Command","X-Goog-Upload-Content-Disposition","X-Goog-Upload-Content-Length","X-Goog-Upload-Content-Type","X-Goog-Upload-File-Name","X-Goog-Upload-Offset","X-Goog-Upload-Protocol","X-Goog-Visitor-Id","X-HTTP-Method-Override","X-JavaScript-User-Agent","X-Pan-Versionid","X-Origin","X-Referer","X-Upload-Content-Length","X-Upload-Content-Type","X-Use-HTTP-Status-Code-Override","X-YouTube-VVT","X-YouTube-Page-CL","X-YouTube-Page-Timestamp"]},"cors":false},"plus_layer":{"isEnabled":false},"enableMultilogin":true,"disableRealtimeCallback":false,"isLoggedIn":false,"iframes":{"additnow":{"methods":["launchurl"],"url":"https://apis.google.com/additnow/additnow.html?usegapi\u003d1"},"person":{"url":":socialhost:/:session_prefix:_/widget/render/person?usegapi\u003d1"},"visibility":{"params":{"url":""},"url":":socialhost:/:session_prefix:_/widget/render/visibility?usegapi\u003d1"},"photocomments":{"url":":socialhost:/:session_prefix:_/widget/render/photocomments?usegapi\u003d1"},"plus_followers":{"params":{"url":""},"url":":socialhost:/_/im/_/widget/render/plus/followers?usegapi\u003d1"},"signin":{"methods":["onauth"],"params":{"url":""},"url":":socialhost:/:session_prefix:_/widget/render/signin?usegapi\u003d1"},"share":{"url":":socialhost:/:session_prefix::im_prefix:_/widget/render/share?usegapi\u003d1"},"commentcount":{"url":":socialhost:/:session_prefix:_/widget/render/commentcount?usegapi\u003d1"},"page":{"url":":socialhost:/:session_prefix:_/widget/render/page?usegapi\u003d1"},"hangout":{"url":"https://talkgadget.google.com/:session_prefix:talkgadget/_/widget"},"plus_circle":{"params":{"url":""},"url":":socialhost:/:session_prefix::se:_/widget/plus/circle?usegapi\u003d1"},"youtube":{"methods":["scroll","openwindow"],"params":{"location":["search","hash"]},"url":":socialhost:/:session_prefix:_/widget/render/youtube?usegapi\u003d1"},"zoomableimage":{"url":"https://ssl.gstatic.com/microscope/embed/"},"card":{"url":":socialhost:/:session_prefix:_/hovercard/card"},"evwidget":{"params":{"url":""},"url":":socialhost:/:session_prefix:_/events/widget?usegapi\u003d1"},"reportabuse":{"params":{"url":""},"url":":socialhost:/:session_prefix:_/widget/render/reportabuse?usegapi\u003d1"},"follow":{"url":":socialhost:/:session_prefix:_/widget/render/follow?usegapi\u003d1"},"shortlists":{"url":""},"plus":{"url":":socialhost:/:session_prefix:_/widget/render/badge?usegapi\u003d1"},"configurator":{"url":":socialhost:/:session_prefix:_/plusbuttonconfigurator?usegapi\u003d1"},":socialhost:":"https://apis.google.com","post":{"params":{"url":""},"url":":socialhost:/:session_prefix::im_prefix:_/widget/render/post?usegapi\u003d1"},"community":{"url":":ctx_socialhost:/:session_prefix::im_prefix:_/widget/render/community?usegapi\u003d1"},":gplus_url:":"https://plus.google.com","rbr_s":{"params":{"url":""},"url":":socialhost:/:session_prefix::se:_/widget/render/recobarsimplescroller"},"autocomplete":{"params":{"url":""},"url":":socialhost:/:session_prefix:_/widget/render/autocomplete"},"plus_share":{"params":{"url":""},"url":":socialhost:/:session_prefix::se:_/+1/sharebutton?plusShare\u003dtrue\u0026usegapi\u003d1"},":source:":"3p","blogger":{"methods":["scroll","openwindow"],"params":{"location":["search","hash"]},"url":":socialhost:/:session_prefix:_/widget/render/blogger?usegapi\u003d1"},"savetowallet":{"url":"https://clients5.google.com/s2w/o/savetowallet"},"rbr_i":{"params":{"url":""},"url":":socialhost:/:session_prefix::se:_/widget/render/recobarinvitation"},"appcirclepicker":{"url":":socialhost:/:session_prefix:_/widget/render/appcirclepicker"},"savetodrive":{"methods":["save"],"url":"https://drive.google.com/savetodrivebutton?usegapi\u003d1"},":im_socialhost:":"https://plus.googleapis.com","ytshare":{"params":{"url":""},"url":":socialhost:/:session_prefix:_/widget/render/ytshare?usegapi\u003d1"},":signuphost:":"https://plus.google.com","plusone":{"params":{"count":"","size":"","url":""},"url":":socialhost:/:session_prefix::se:_/+1/fastbutton?usegapi\u003d1"},"comments":{"methods":["scroll","openwindow"],"params":{"location":["search","hash"]},"url":":socialhost:/:session_prefix:_/widget/render/comments?usegapi\u003d1"},"ytsubscribe":{"url":"https://www.youtube.com/subscribe_embed?usegapi\u003d1"}},"isPlusUser":false,"debug":{"host":"https://apis.google.com","forceIm":false,"reportExceptionRate":0.05,"rethrowException":false},"enableContextualSignin":false,"enableSigninTooltip":false,"deviceType":"desktop","inline":{"css":1},"lexps":[102,99,97,79,109,45,17,117,115,81,127,123,122,61,30],"include_granted_scopes":true,"oauth-flow":{"usegapi":false,"disableOpt":true,"authUrl":"https://accounts.google.com/o/oauth2/auth","proxyUrl":"https://accounts.google.com/o/oauth2/postmessageRelay"},"report":{"apiRate":{"gapi\\.signin\\..*":0.05},"host":"https://apis.google.com","rate":0.001,"apis":["iframes\\..*","gadgets\\..*","gapi\\.appcirclepicker\\..*","gapi\\.auth\\..*","gapi\\.client\\..*"]},"csi":{"rate":0.01},"googleapis.config":{"auth":{"useFirstPartyAuthV2":false}}},"h":"m;/_/scs/apps-static/_/js/k\u003doz.gapi.zh_TW.ztEEecoES9o.O/m\u003d__features__/am\u003dAQ/rt\u003dj/d\u003d1/t\u003dzcms/rs\u003dAItRSTP_Lu4DwGaRjLIKvugpcbbIRXTYxA","u":"https://apis.google.com/js/api.js","hee":true,"fp":"0849350dce2cb502a5f909e55ba02710e7d5e531","dpo":false},"fp":"0849350dce2cb502a5f909e55ba02710e7d5e531","annotation":["interactivepost","recobar","autocomplete","profile"],"bimodal":["signin","share"]}});