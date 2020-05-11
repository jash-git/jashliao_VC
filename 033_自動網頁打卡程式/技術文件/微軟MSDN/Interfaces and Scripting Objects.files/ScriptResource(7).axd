// (c) Copyright Microsoft Corporation.
// This source is subject to the Microsoft Permissive License.
// See http://www.microsoft.com/resources/sharedsource/licensingbasics/sharedsourcelicenses.mspx.
// All other rights reserved.

// This behavior can be attached to a textbox to enable auto-complete/auto-suggest
// scenarios.

Microsoft.Mtps.Rendering.Behaviors.Ajax.AutoCompleteBehavior = function(element) {
    /// <param name="element" domElement="true">The DOM element the behavior is associated with.</param>
    Microsoft.Mtps.Rendering.Behaviors.Ajax.AutoCompleteBehavior.initializeBase(this, [element]);
        this._servicePath = null;
        this._serviceMethod = null;
        this._minimumPrefixLength = 3;
        this._completionSetCount = 10;
        this._completionInterval = 1000;        
        this._completionListElementID = null;
        this._completionListElement = null;
        this._textColor = 'windowtext';
        this._textBackground = 'window';
        this._popupBehavior = null;
        this._timer = null;
        this._cache = null;
        this._currentPrefix = null;
        this._selectIndex = -1;
        this._focusHandler = null;
        this._blurHandler = null;
        this._keyDownHandler = null;
        this._mouseDownHandler = null;
        this._mouseUpHandler = null;
        this._mouseOverHandler = null;
        this._tickHandler = null;
        this._enableCaching = true;
}
Microsoft.Mtps.Rendering.Behaviors.Ajax.AutoCompleteBehavior.prototype = {
    initialize: function() {
    
        Microsoft.Mtps.Rendering.Behaviors.Ajax.AutoCompleteBehavior.callBaseMethod(this, 'initialize');

        this._tickHandler = Function.createDelegate(this, this._onTimerTick);
        this._focusHandler = Function.createDelegate(this, this._onGotFocus);
        this._blurHandler = Function.createDelegate(this, this._onLostFocus);
        this._keyDownHandler = Function.createDelegate(this, this._onKeyDown);
        this._mouseDownHandler = Function.createDelegate(this, this._onListMouseDown);
        this._mouseUpHandler = Function.createDelegate(this, this._onListMouseUp);
        this._mouseOverHandler = Function.createDelegate(this, this._onListMouseOver);
        
        this._timer = new Sys.Timer();
        this.initializeTimer(this._timer);
        
        var element = this.get_element();
        this.initializeTextBox(element);
        
        if(this._completionListElementID !== null)
            this._completionListElement = $get(this._completionListElementID);
        if (this._completionListElement == null ) {
            this._completionListElement = document.createElement('DIV');
            this._completionListElement.id = this.get_id() + '_completionListElem';

            // Safari styles the element incorrectly if it's added to the desired location
            if (Sys.Browser.agent === Sys.Browser.Safari) {
                document.body.appendChild(this._completionListElement);
            } else {
                element.parentNode.appendChild(this._completionListElement);
            }
        }
        
        this.initializeCompletionList(this._completionListElement);
        
        this._popupBehavior = $create(Microsoft.Mtps.Rendering.Behaviors.Ajax.PopupBehavior, 
                { 'id':this.get_id()+'PopupBehavior', 'parentElement':element, "positioningMode": Microsoft.Mtps.Rendering.Behaviors.Ajax.PositioningMode.BottomLeft }, null, null, this._completionListElement);        
    },
    
    get_completionInterval: function() {
        /// <value type="Number">Auto completion timer interval in milliseconds.</value>
        return this._completionInterval;
    },
    set_completionInterval: function(value) {
        this._completionInterval = value;
    },
    
    get_completionList: function() {
        /// <value domElement="true">List dom element.</value>
        return this._completionListElement;
    },
    set_completionList: function(value) {
        this._completionListElement = value;
    },
    
    get_completionSetCount: function() {
        /// <value type="Number">Maximum completion set size.</value>
        return this._completionSetCount;
    },
    set_completionSetCount: function(value) {
        this._completionSetCount = value;
    },
    
    get_minimumPrefixLength: function() {
        /// <value type="Number">Minimum text prefix length required to perform behavior.</value>
        return this._minimumPrefixLength;
    },
    set_minimumPrefixLength: function(value) {
        this._minimumPrefixLength = value;
    },
    
    get_serviceMethod: function() {
        /// <value type="String">Web service method.</value>
        return this._serviceMethod;
    },
    set_serviceMethod: function(value) {
        this._serviceMethod = value;
    },
    
    get_servicePath: function() {
        /// <value type="String">Web service url.</value>
        return this._servicePath;
    },
    set_servicePath: function(value) {
        this._servicePath = value;
    },
    
    get_enableCaching: function() {
        /// <value type="Boolean">Get or sets whether suggestions retrieved from the webservice should be cached.</value>
        return this._enableCaching;
    },
    set_enableCaching: function(value) {
        this._enableCaching = value;
    },
    
    get_completionListElementID: function(){
        /// <value type="String>ID of the completion div element. </value>
        return this._completionListElementID;
    },
    set_completionListElementID: function(value) {
        this._completionListElementID = value;  
    },    
    
    dispose: function() {
        
        if (this._popupBehavior) {
            this._popupBehavior.dispose();
            this._popupBehavior = null;
        }
        if(this._timer) {        
            this._timer.dispose();
            this._timer = null;
        }

        var element = this.get_element();
        if(element) {
            $removeHandler(element, "focus", this._focusHandler);
            $removeHandler(element, "blur", this._blurHandler);
            $removeHandler(element, "keydown", this._keyDownHandler);
            $removeHandler(this._completionListElement, 'mousedown', this._mouseDownHandler);
            $removeHandler(this._completionListElement, 'mouseup', this._mouseUpHandler);
            $removeHandler(this._completionListElement, 'mouseover', this._mouseOverHandler);
        }
        
        this._tickHandler = null;
        this._focusHandler = null;
        this._blurHandler = null;
        this._keyDownHandler = null;
        this._mouseDownHandler = null;
        this._mouseUpHandler = null;
        this._mouseOverHandler = null;
        

        Microsoft.Mtps.Rendering.Behaviors.Ajax.AutoCompleteBehavior.callBaseMethod(this, 'dispose');
    },
    
    initializeTimer: function(timer) {
        timer.set_interval(this._completionInterval);
        timer.add_tick(this._tickHandler);
    },
    
    initializeTextBox: function(element) {
        element.autocomplete = "off";
        $addHandler(element, "focus", this._focusHandler);
        $addHandler(element, "blur", this._blurHandler);
        $addHandler(element, "keydown", this._keyDownHandler);
    },
    
    initializeCompletionList: function(element) {
        var completionListStyle = element.style;
        completionListStyle.visibility = 'hidden';
        completionListStyle.backgroundColor = this._textBackground;
        completionListStyle.color = this._textColor;
        completionListStyle.border = 'solid 1px buttonshadow';
        completionListStyle.cursor = 'default';
        completionListStyle.unselectable = 'unselectable';
        completionListStyle.overflow = 'hidden';
        
        $addHandler(element, "mousedown", this._mouseDownHandler);
        $addHandler(element, "mouseup", this._mouseUpHandler);
        $addHandler(element, "mouseover", this._mouseOverHandler);
    },
    
    _hideCompletionList: function() {
        this._popupBehavior.hide();
        this._completionListElement.innerHTML = '';
        this._selectIndex = -1;
    },
    
    _highlightItem: function(item) {
        /// <param name="item">DOM element.</param>
        var children = this._completionListElement.childNodes;
        
        for (var i = 0; i < children.length; i++) {
            var child = children[i];
            if (child !== item) {
                child.style.backgroundColor = this._textBackground;
                child.style.color = this._textColor;
            }
        }

        // Only on Safari set the background color to be the same as "DropDown"
        // hightlighted item otherwise the text and the background are the same
        // color and the item hides itself.
        if (Sys.Browser.agent === Sys.Browser.Safari) 
        {
            item.style.backgroundColor = '#FFF3DB';        
            item.style.color = 'black';
        }
        else
        {
            item.style.backgroundColor = 'highlight';
            item.style.color = 'highlighttext';

        }
    },
    
    _onListMouseDown: function(ev) {
        if (ev.target !== this._completionListElement) {
            this._setText(ev.target.firstChild.nodeValue);
        }
    },
    
    _onListMouseUp: function(ev) {
        this.get_element().focus();
    },
    
    _onListMouseOver: function(ev) {
        var item = ev.target;
        this._selectIndex = -1;
        this._highlightItem(item);
    },

    _onGotFocus: function(ev) {
        this._timer.set_enabled(true);
    },
    
    _onKeyDown: function(ev) {
        var k = ev.keyCode ? ev.keyCode : ev.rawEvent.keyCode;
        if (k === Sys.UI.Key.esc) {
            this._hideCompletionList();
            ev.preventDefault();
        }
        else if (k === Sys.UI.Key.up) {
            if (this._selectIndex > 0) {
                this._selectIndex--;
                this._highlightItem(this._completionListElement.childNodes[this._selectIndex]);
                ev.preventDefault();
            }
        }
        else if (k === Sys.UI.Key.down) {
            if (this._selectIndex < (this._completionListElement.childNodes.length - 1)) {
                this._selectIndex++;
                this._highlightItem(this._completionListElement.childNodes[this._selectIndex]);
                ev.preventDefault();
            }
        }
        else if (k === Sys.UI.Key.enter) {
            if (this._selectIndex !== -1) {
                this._setText(this._completionListElement.childNodes[this._selectIndex].firstChild.nodeValue);
                ev.preventDefault();
            }
        }
        else if (k === Sys.UI.Key.tab) {
            if (this._selectIndex !== -1) {
                this._setText(this._completionListElement.childNodes[this._selectIndex].firstChild.nodeValue);
            }
        }
        else {
            this._timer.set_enabled(true);
        }
    },
    
    _onLostFocus: function() {
        this._timer.set_enabled(false);
        this._hideCompletionList();
    },
    
    _onMethodComplete: function(result, context, methodName) {
        this._update(context, result, /* cacheResults */ true);
    },
    _onMethodFailed: function(err, response, context) {
        // no op
    },
    
    _onTimerTick: function(sender, eventArgs) {
        if (this._servicePath && this._serviceMethod) {
            var text = this.get_element().value;
            
            if (text.trim().length < this._minimumPrefixLength) {
                this._currentPrefix = null;
                this._update('', null, /* cacheResults */ false);
                return;
            }
            
            if (this._currentPrefix !== text) {
                this._currentPrefix = text;
                if (this._cache && this._cache[text]) {
                    this._update(text, this._cache[text], /* cacheResults */ false);
                    return;
            }
            
            Sys.Net.WebServiceProxy.invoke(this.get_servicePath(), this.get_serviceMethod(), false,
                                        { prefixText : this._currentPrefix, count: this._completionSetCount },
                                        Function.createDelegate(this, this._onMethodComplete),
                                        Function.createDelegate(this, this._onMethodFailed),
                                        text);
            }
        }
    },
    
    _setText: function(text) {
        this._timer.set_enabled(false);
        this._currentPrefix = text;
        var element = this.get_element();
        var control = element.control;
        // todo: should check for 'derives from' too and should somehow manually cause TB to raise property changed event
        if (control && control.set_text) {
            control.set_text(text);
        }
        else {
            element.value = text;
        }
        this._hideCompletionList();
    },
    
    _update: function(prefixText, completionItems, cacheResults) {
        if (cacheResults && this.get_enableCaching()) {
            if (!this._cache) {
                this._cache = {};
            }
            this._cache[prefixText] = completionItems;
        }

        this._completionListElement.innerHTML = '';
        this._selectIndex = -1;
        if (completionItems && completionItems.length) {
            for (var i = 0; i < completionItems.length; i++) {
                var itemElement = document.createElement('div');
                itemElement.appendChild(document.createTextNode(completionItems[i]));
                itemElement.__item = '';
                
                var itemElementStyle = itemElement.style;
                itemElementStyle.padding = '1px';
                itemElementStyle.textAlign = 'left';
                itemElementStyle.textOverflow = 'ellipsis';
                itemElementStyle.backgroundColor = this._textBackground;
                itemElementStyle.color = this._textColor;
                
                this._completionListElement.appendChild(itemElement);
            }
            var elementBounds = CommonToolkitScripts.getBounds(this.get_element());        
            this._completionListElement.style.width = Math.max(1, elementBounds.width - 2) + 'px';
            this._popupBehavior.show();
        }
        else {
            this._popupBehavior.hide();
        }
    }    
}
Microsoft.Mtps.Rendering.Behaviors.Ajax.AutoCompleteBehavior.descriptor = {
    properties: [   {name: 'completionInterval', type: Number},
                    {name: 'completionList', isDomElement: true},
                    {name: 'completionListElementID', type: String},
                    {name: 'completionSetCount', type: Number},
                    {name: 'minimumPrefixLength', type: Number},
                    {name: 'serviceMethod', type: String},
                    {name: 'servicePath', type: String},
                    {name: 'enableCaching', type: Boolean} ]
}
Microsoft.Mtps.Rendering.Behaviors.Ajax.AutoCompleteBehavior.registerClass('Microsoft.Mtps.Rendering.Behaviors.Ajax.AutoCompleteBehavior', Microsoft.Mtps.Rendering.Behaviors.Ajax.BehaviorBase);
if(typeof(Sys)!=='undefined')Sys.Application.notifyScriptLoaded();