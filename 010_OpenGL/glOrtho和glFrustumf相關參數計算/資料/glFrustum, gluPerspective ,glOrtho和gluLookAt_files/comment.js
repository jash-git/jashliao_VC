jQuery(document).ready(
	function(){
		jQuery('.commentlist li .comments .commentcontent').each(
			function() {
				jQuery(this).html(showsmiles(jQuery(this).html()));
			}
		);	

		commentuser=$.cookie('comment_user');
		if (commentuser){
			//[user,email,url]=commentuser.split('#@#');
			data=commentuser.split('#@#');
			$('#author').val(data[0]);
			$('#email').val(data[1]);
			$('#url').val(data[2]);
	};
	})

function backcomment(author,id){
	backdb=document.getElementById('comment');
	backdb.focus();
	backdb.value=backdb.value+'<a href=\"#comment-'+id+'\">@'+author+'<\/a>'+'\n';
	return false;
}	

//以下表情
function grin(tag) { 
	if (typeof tinyMCE != 'undefined') { 
		grin_tinymcecomments(tag); 
	} else { 
		grin_plain(tag); 
	}
} 
function grin_tinymcecomments(tag) { 
	tinyMCE.execCommand('mceInsertContent', false, ' ' + tag + ' '); 
} 
function grin_plain(tag) { 
	var myField; 
	var myCommentTextarea = "comment"; 
	tag = ' ' + tag + ' '; 
	if (document.getElementById(myCommentTextarea) && document.getElementById(myCommentTextarea).type == 'textarea') { 
		myField = document.getElementById(myCommentTextarea); 
	} else { 
		return false; 
	} 
	if (document.selection) { 
		myField.focus(); 
		sel = document.selection.createRange(); 
		sel.text = tag; 
		myField.focus(); 
	} 
	else if (myField.selectionStart || myField.selectionStart == '0') { 
		var startPos = myField.selectionStart; 
		var endPos = myField.selectionEnd; 
		var cursorPos = endPos; 
		myField.value = myField.value.substring(0, startPos) 
					  + tag 
					  + myField.value.substring(endPos, myField.value.length); 
		cursorPos += tag.length; 
		myField.focus(); 
		myField.selectionStart = cursorPos; 
		myField.selectionEnd = cursorPos; 
	} 
	else { 
		myField.value += tag; 
		myField.focus(); 
	}
} 

function showsmiles(content)
{
	return content.replace(/\^~/ig,"<img src=http://hikeimg.appspot.com/static/images/icon/icon_").replace(/~\^/ig,'.gif />');
}