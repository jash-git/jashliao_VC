/*
Copyright (c) 2003-2010, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

CKEDITOR.editorConfig = function( config )
{
	// Define changes to default configuration here. For example:
	// config.language = 'fr';
    // config.uiColor = '#AADC6E';
    /*
    config.removePlugins = 'scayt';
    config.useComputedState = false;
    config.entities = false;
    config.fillEmptyBlocks = false;
    config.disableNativeSpellChecker = false;
    config.entities = false;
    config.entities_greek = false;
    config.entities_latin = false;
    config.fillEmptyBlocks = false;
    config.forcePasteAsPlainText = true;
    //拼字檢查 
    config.disableNativeSpellChecker = false;
    */
    config.skin = 'v2';
    config.toolbar_Full =
    [
        ['Source', '-'],
        ['Cut', 'Copy', 'Paste', 'PasteText', 'PasteFromWord', '-', 'Print', 'SpellChecker', 'Scayt'],
        ['Undo', 'Redo', '-', 'Find', 'Replace', '-', 'SelectAll', 'RemoveFormat'],
        ['Form', 'Checkbox', 'Radio', 'TextField', 'Textarea', 'Select', 'Button', 'ImageButton', 'HiddenField'],
        '/',
        ['Bold', 'Italic', 'Underline', 'Strike', '-', 'Subscript', 'Superscript'],
        ['NumberedList', 'BulletedList', '-', 'Outdent', 'Indent', 'Blockquote', 'CreateDiv'],
        ['JustifyLeft', 'JustifyCenter', 'JustifyRight', 'JustifyBlock'],
        ['Link', 'Unlink', 'Anchor'],
        ['Image', 'Flash', 'Table', 'HorizontalRule', 'Smiley', 'SpecialChar', 'PageBreak'],
        '/',
        ['Styles', 'Format', 'Font', 'FontSize', 'syntaxhighlight'],
        ['TextColor', 'BGColor'],
        ['Maximize', 'ShowBlocks', '-', 'About']
    ];
	/*
	config.format_tags = 'p;h2;h3;pre';
	
    config.fillEmptyBlocks = false;
    config.format_tags = 'p;h2;h3';
    */
    /*
    config.toolbar_Basic =
    [
        ['Bold', 'Italic', '-', 'NumberedList', 'BulletedList', '-', 'Link', 'Unlink','syntaxhighlight', '-', 'About']
    ];
    */

    /*
    config.toolbar_Basic =
    [
        ['Source','Bold','Italic','Underline','StrikeThrough','Link'],
	    ['FontFormat','FontSize','TextColor','syntaxhighlight']
    ];
    */
	
	 config.toolbar_Basic =
    [
        ['Bold','Italic','Underline','StrikeThrough','Link'],
	    ['FontFormat','TextColor','syntaxhighlight']
    ];
    
	
    
    config.extraPlugins = 'syntaxhighlight';
    config.toolbar_Full.push(['Code']);
    config.toolbar_Basic.push(['Code']);
     
};
