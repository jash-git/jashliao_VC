    var keymap = {
                "Hp":["联想Y460","联想560","DELL","戴尔"],
                "lphone":["iphone","MOTO X6"],
                "Intel":["AMD","星际2","单反"]
     };
     /**
      * 根据class的名称查找文章正文部分
      */
     function findContent(){
         var contentEl = document.getElementsByTagName("DIV");
         for(i=0;i < contentEl.length;i++){
             if(contentEl[i].className=='ArticleCnt'){
                 return contentEl[i].innerHTML;
             }                                                                        
         }
     }
     /**
      * 在文章正文中查找特定的关键词，找到后调用omniture提供的mboxCreate方法
      * @param content
      */
     function doSearchInContent(){
		 var content = findContent();
         if(content){
             for(var key in keymap) {
                 var keywords = keymap[key];
                 for(var i =0 ;i < keywords.length;i++){
                     if(content.toLowerCase().indexOf(keywords[i].toLowerCase()) > 0){
                        //mboxCreate(key);
                        return key;
                     }
                 }

             }
         }
     }
     /**
      * 创建一个空的层
      */
     function createMboxDiv(){
         var mboxEl =  document.createElement("div");
         mboxEl.className = "mboxDefault";
         document.body.appendChild(mboxEl);
         return mboxEl;        
     }
    
    var onloadFunction = function(){
        if(oldOnloadFunction != null){
            oldOnloadFunction();
        }
        //createMboxDiv();
        doSearchInContent();
    };
    //var oldOnloadFunction = null;
    //if(document.body.onload && document.body.onload != null)
    //    oldOnloadFunction = document.body.onload;
    //document.body.onload = onloadFunction;      


