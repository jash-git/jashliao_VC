function validateinput() {    

    var comment = document.getElementById('PostComment_ascx_tbComment');
    var result = false;
    var msg = document.getElementById('divCommentMessage');
    var msgcontent = '請輸入內容';
    
    var ckeditor = document.getElementById('PostComment_ascx_richTextEditor_richTextEditor');

    if(comment)
    {
        if(comment.value.trim() == '')
        {
            msg.innerHTML = msgcontent;
            msg.style.display = '';

            var oEditor = CKEDITOR.instances.PostComment_ascx_tbComment;

            if (oEditor) {
                if (oEditor.getData().length == 7 &&
                    oEditor.getData().indexOf('<br />') == 0) {
                    msg.innerHTML = msgcontent;
                    msg.style.display = '';
                    return false;
                }

                if (oEditor.getData() == '') {
                    msg.innerHTML = msgcontent;
                    msg.style.display = '';
                }
                else {
                    msg.innerHTML = '';
                    result = true;
                }
            }
        }
        else
        {
            msg.innerHTML = '';
            result = true;
        }
        
    }                                
    else if(ckeditor)
    {        
        try
        {
            var oEditor = CKEDITOR.instances.PostComment_ascx_richTextEditor_richTextEditor;
        
            if(oEditor)
            {
                if(oEditor.getData().length == 7 &&
                    oEditor.getData().indexOf('<br />') == 0)
                {
                    msg.innerHTML = msgcontent;
                    msg.style.display = '';
                    return false;
                }
                
                if(oEditor.getData() == '')
                {
                    msg.innerHTML = msgcontent;
                    msg.style.display = '';
                }
                else
                {                
                    msg.innerHTML = '';
                    result = true;
                }
            }
        }
        catch(ex){}
        
        try
        {
            var fck = FCKeditorAPI.GetInstance('PostComment_ascx_richTextEditor_richTextEditor');
            if(fck)
            {
                if(fck.GetXHTML(true) == '')
                {
                    msg.innerHTML = msgcontent;
                    msg.style.display = '';
                }
                else
                {
                    msg.innerHTML = '';
                    result = true;
                }
            }     
        }
        catch(ex){}                    
        
    }                               
    else
    {
        var fck = FCKeditorAPI.GetInstance('PostComment_ascx_fckComment');
        if(fck)
        {
            if(fck.GetXHTML(true) == '')
            {
                msg.innerHTML = msgcontent;
                msg.style.display = '';
            }
            else
            {
                msg.innerHTML = '';
                result = true;
            }
        }                                    
    }
    
    return result;
}

function reply(name)
{
    var comment = document.getElementById('PostComment_ascx_tbComment');
    
    if(comment)
    {
        comment.value += 'to ' + name + ' : \n';
        comment.focus();

        try {
            var oEditor = CKEDITOR.instances.PostComment_ascx_tbComment;

            if (oEditor) {
                var l = CKEDITOR.dom.element.createFromHtml('<span>to ' + name + ' : <br /></span>',
                    CKEDITOR.instances.PostComment_ascx_tbComment.document);

                CKEDITOR.instances.PostComment_ascx_tbComment.insertElement(l);
            }

        }
        catch (ex) { }      
    }
    else
    {
        try
        {
            var fck = FCKeditorAPI.GetInstance('PostComment_ascx_richTextEditor_richTextEditor');        
    
            if(fck)
            {   
                if ( fck.EditMode == FCK_EDITMODE_WYSIWYG )
                {
                    fck.Focus();
                    fck.InsertHtml('to ' + name + ' : <br />');                 
                }                
            }        
        }
        catch(ex){}
        
        try
        {
            var oEditor = CKEDITOR.instances.PostComment_ascx_richTextEditor_richTextEditor;
        
            if(oEditor)
            {
                var l = CKEDITOR.dom.element.createFromHtml('<span>to ' + name + ' : <br /></span>', 
                    CKEDITOR.instances.PostComment_ascx_richTextEditor_richTextEditor.document);
                
                CKEDITOR.instances.PostComment_ascx_richTextEditor_richTextEditor.insertElement(l);         
            }  
            
        }
        catch(ex){}      
    }
}

function dosearch()
{
    var blogname = subtextBlogInfo.virtualBlogRoot.replace(/\//g,'');
    
    var url = 'http://www.google.com/search?q=' + 
                encodeURI(document.getElementById('txtSearch').value) + 
                '&ie=UTF8&oe=UTF8&hl=zh-TW&btnG=Search&domains=http://www.dotblogs.com.tw/' + 
                blogname + 
                '&sitesearch=http://www.dotblogs.com.tw/' + blogname;
                
     window.open(url);
}

function keypress(e)
{
    if (!e) var e = window.event;
        
    var keyCode;
    
    if (e.keyCode) 
        keyCode = e.keyCode;
    else if (e.which) 
        keyCode = e.which;    

	if (keyCode == 13) 
    {
	    if (e.stopPropagation) 
	        e.stopPropagation(); 
	    else 
	        e.cancelBubble = true;
	    
	    dosearch();
	    
	    return false;
    }
    
    return true;     
}

var oldOnload = window.onload || function () { };

window.onload = function ()
{
    oldOnload();    
    InsertCommentAD();
}

function InsertCommentAD() {
    try {
                                                       
        var submitbutton = document.getElementsByName('PostComment_ascx$btnSubmit');    
        
        if (submitbutton.length == 1) {
        
            //if (location.href.indexOf('/dotblogs/') == -1) return;

            var parent = submitbutton[0].parentNode;

            if (parent != null) {           
                parent.appendChild(document.createElement("br"));
                parent.appendChild(document.createElement("br"));
                parent.appendChild(CreateCommentAD());            
            }        
        }

        submitbutton = document.getElementsByName('PostComment_ascx$btnCompliantSubmit');

        if (submitbutton.length == 1) {
        
            var parent = submitbutton[0].parentNode;

            if (parent != null) {           
                parent.appendChild(document.createElement("br"));
                parent.appendChild(document.createElement("br"));
                parent.appendChild(CreateCommentAD());            
            }        
        }

    }
    catch(ex) {

    }
        
}

function CreateCommentAD(newelElement, targetElement) {
	
	var d = new Date();
	
    var frame = document.createElement("iframe");

    frame.width = "728";
    frame.height = "90"
    frame.frameBorder = "0";
    frame.style.zIndex = 1000;
    frame.scrolling = "no";        
    frame.src = "http://www.dotblogs.com.tw/js/ad.html?" + d.toString();

    return frame;
}
 


