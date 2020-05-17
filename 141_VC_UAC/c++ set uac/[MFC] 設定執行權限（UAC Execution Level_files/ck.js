

//延遲載入
setTimeout('InitCKEditor()',700);

function InitCKEditor() {

    //找出頁面所有的 TextArea
    var textarea = document.getElementsByTagName('textarea');

    if(location.href.indexOf('EditPosts.aspx') != -1)
    {
        //若在編輯文章的頁面，把ck設成和文章標題同寬
        var txt = document.getElementById('ctl00_pageContent_Editor_Edit_txbTitle');
    
        _width = (txt.style.width == '') ? txt.offsetWidth : txt.style.width;       
    }
    
    for(var i = 0; i < textarea.length;i++)
    {      
        if (location.href.indexOf('EditPosts.aspx') != -1) {

            CKEDITOR.replace(textarea[i].id,
            {
                toolbar: _toolbarset,
                width:  _width            
            });           
           
            //編輯文章的頁面，只套第一個 TextArea
            break;
        }
        else {

            if (textarea[i].className.indexOf('customcss') != -1)
                continue;

            CKEDITOR.replace(textarea[i].id,
            {
                toolbar: _toolbarset,
                //width:  _width
                width: textarea[i].style.width
            });
        }
    }   
}
  