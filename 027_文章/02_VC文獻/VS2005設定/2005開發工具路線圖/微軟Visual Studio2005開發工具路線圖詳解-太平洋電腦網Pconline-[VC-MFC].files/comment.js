with(document)with(body.insertBefore(createElement("script"),body.firstChild)) {
    defer=true;
    var server = document.getElementById("_comment_tag_").src.replace(/.*[?&]server=([^&]+)(&|$).*|.*/,"$1");
    if(server != null && server != '');
    else if(location.hostname=='www.pcauto.com.cn') server = "http://big5.pconline.com.cn/b5/cmt.pcauto.com.cn";
    else if(location.hostname=='www.pcgames.com.cn') server = "http://big5.pconline.com.cn/b5/cmt.pcgames.com.cn";
    else if(location.hostname=='www.pclady.com.cn') server = "http://big5.pconline.com.cn/b5/cmt.pclady.com.cn";
    else server = "http://big5.pconline.com.cn/b5/cmt.pconline.com.cn";

    src = server+"/index.jsp"
        +"?"+document.getElementById("_comment_tag_").src
            .replace(/([?&])server=[^&]*/,"$1")
            .replace(/^[^?]*[?](.*)$|^.*$/,"$1")
            .replace(/(url|title|referer)=(&|$)/g,"")

        +"&url="+escape(location.href)
        +"&referer="+escape(document.referrer)
        +"&title="+escape(document.title)
        ;
}        