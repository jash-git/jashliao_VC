// (c) Copyright Microsoft Corporation.
// This source is subject to the Microsoft Permissive License.
// See http://www.microsoft.com/resources/sharedsource/licensingbasics/sharedsourcelicenses.mspx.
// All other rights reserved.
Type.registerNamespace('Microsoft.Mtps.Rendering.Behaviors.Ajax');

Microsoft.Mtps.Rendering.Behaviors.Ajax.PositioningMode = function() {
    throw Error.invalidOperation();
}
Microsoft.Mtps.Rendering.Behaviors.Ajax.PositioningMode.prototype = {
    Absolute: 0,
    Center: 1,
    BottomLeft: 2,
    BottomRight: 3,
    TopLeft: 4,
    TopRight: 5
}
Microsoft.Mtps.Rendering.Behaviors.Ajax.PositioningMode.registerEnum('Microsoft.Mtps.Rendering.Behaviors.Ajax.PositioningMode');

Microsoft.Mtps.Rendering.Behaviors.Ajax.PopupBehavior = function(element) {
    /// <param name="element">The DOM element the behavior is associated with.</param>
    Microsoft.Mtps.Rendering.Behaviors.Ajax.PopupBehavior.initializeBase(this, [element]);

    this._x = 0;
    this._y = 0;
    this._positioningMode = Microsoft.Mtps.Rendering.Behaviors.Ajax.PositioningMode.Absolute;
    this._parentElement = null;
    this._parentElementID = null;
    this._moveHandler = null;
    this._firstPopup = true;    
    this._originalParent = null;
}
Microsoft.Mtps.Rendering.Behaviors.Ajax.PopupBehavior.prototype = {
    
    get_parentElement : function() {
        /// <value>Parent dom element.</value>        
        if (!this._parentElement && this._parentElementID) {
            this.set_parentElement($get(this._parentElementID));
            Sys.Debug.assert(this._parentElement != null, String.format(Microsoft.Mtps.Rendering.Behaviors.Ajax.Resources.PopupExtender_NoParentElement, this._parentElementID));
        }        
        return this._parentElement;
    },    
    set_parentElement : function(element) {
        this._parentElement = element;
        this.raisePropertyChanged('parentElement');
    },
    
    get_parentElementID : function() {
        /// <value>Parent dom element.</value>
        if (this._parentElement) return this._parentElement.id
        return this._parentElementID;
    },
    set_parentElementID : function(elementID) {
        this._parentElementID = elementID;
        if (this.get_isInitialized()) {
            this.set_parentElement($get(elementID));
        }
    },
        
    get_positioningMode : function() {
        /// <value type="Microsoft.Mtps.Rendering.Behaviors.Ajax.PositioningMode">Positioning mode.</value>
        return this._positioningMode;
    },
    set_positioningMode : function(mode) {
        this._positioningMode = mode;
        this.raisePropertyChanged('positioningMode');
    },
    
    get_x : function() {
        /// <value type="Number">X coordinate.</value>
        return this._x;
    },
    set_x : function(value) {
        if (value != this._x) {
            this._x = value;
            if (Sys.UI.DomElement.getVisible(this.get_element())) {
                this.show();
            }
            this.raisePropertyChanged('x');
        }
    },
    
    get_y : function() {
        /// <value type="Number">Y coordinate.</value>
        return this._y;
    },
    set_y : function(value) {
        if (value != this._y) {
            this._y = value;
            if (Sys.UI.DomElement.getVisible(this.get_element())) {
                this.show();
            }
            this.raisePropertyChanged('y');
        }
    },   

    hide : function() {
        var elt = this.get_element();
        Sys.UI.DomElement.setVisible(elt, false);
        if (this._moveHandler) {
            Sys.UI.DomEvent.removeHandler(elt, "move", this._moveHandler);
            this._moveHandler = null;
        }
        if (elt.originalWidth) {
            elt.style.width = elt.originalWidth + "px";
            elt.originalWidth = null;
        }
        if (Sys.Browser.agent === Sys.Browser.InternetExplorer) {
            var childFrame = elt._hideWindowedElementsIFrame;
            if (childFrame) {
                childFrame.style.display = "none";
            }
        }
    },    
    
    show : function() {
        var elt = this.get_element();
        
        Sys.UI.DomElement.setVisible(elt, true);
        
        // offsetParent (doc element if absolutely positioned or no offsetparent available)
        var offsetParent = elt.offsetParent || document.documentElement;

        // diff = difference in position between element's offsetParent and the element we will attach popup to.
        // this is basically so we can position the popup in the right spot even though it may not be absolutely positioned
        var diff;
        var parentBounds;
        if(this._parentElement) {
            // we will be positioning the element against the assigned parent
            parentBounds = CommonToolkitScripts.getBounds(this._parentElement);
            
            var offsetParentLocation = CommonToolkitScripts.getLocation(offsetParent);
            diff = {x: parentBounds.x - offsetParentLocation.x, y:parentBounds.y - offsetParentLocation.y};            
        }
        else {
            // we will be positioning the element against the offset parent by default, since no parent element given
            parentBounds = CommonToolkitScripts.getBounds(offsetParent);            
            diff = {x:0, y:0};
        }

        // width/height of the element, needed for calculations that involve width like centering
        var width = elt.offsetWidth - (elt.clientLeft ? elt.clientLeft * 2 : 0);
        if ( width < 0 ) width = 0;
        var height = elt.offsetHeight - (elt.clientTop ? elt.clientTop * 2 : 0);
        
        var position;
        switch (this._positioningMode) {
            case Microsoft.Mtps.Rendering.Behaviors.Ajax.PositioningMode.Center:
                position = {
                    x: Math.round(parentBounds.width / 2 - width / 2),
                    y: Math.round(parentBounds.height / 2 - height / 2)
                };
                break;
            case Microsoft.Mtps.Rendering.Behaviors.Ajax.PositioningMode.BottomLeft:
                position = {
                    x: 0,
                    y: parentBounds.height
                };
                break;
            case Microsoft.Mtps.Rendering.Behaviors.Ajax.PositioningMode.BottomRight:
                position = {
                    x: parentBounds.width - width,
                    y: parentBounds.height
                };
                break;
            case Microsoft.Mtps.Rendering.Behaviors.Ajax.PositioningMode.TopLeft:
                position = {
                    x: 0,
                    y: -elt.offsetHeight
                };
                break;
            case Microsoft.Mtps.Rendering.Behaviors.Ajax.PositioningMode.TopRight:
                position = {
                    x: parentBounds.width - width,
                    y: -elt.offsetHeight
                };
                break;
            default:
                position = {x: 0, y: 0};
        }
        position.x += this._x + diff.x;
        position.y += this._y + diff.y;
        
        CommonToolkitScripts.setLocation(elt, position);
       
        if(this._firstPopup) {
            // 23098: Setting the width causes the element to grow by border+passing every time. But not setting it
            // causes strange behavior in safari. Just set it once.
            elt.style.width = width + "px";
        }
        this._firstPopup = false;


        var newPosition = CommonToolkitScripts.getBounds(elt);
        var updateNeeded = false;

        var documentWidth = self.innerWidth ? self.innerWidth : document.documentElement.clientWidth;
        // CONSIDER: Create a generic function to return this information.
        if (!documentWidth) {
            documentWidth = document.body.clientWidth;
        }
        if (newPosition.x + newPosition.width > documentWidth - 5) {
            position.x -= newPosition.x + newPosition.width - documentWidth + 5;
            updateNeeded = true;
        }
        if (newPosition.x < 0) {
            position.x -= newPosition.x;
            updateNeeded = true;
        }
        if (newPosition.y < 0) {
            position.y -= newPosition.y;
            updateNeeded = true;
        }

        if (updateNeeded) {        
            CommonToolkitScripts.setLocation(elt, position);
        }
        elt.zIndex = 1000;

        if ((Sys.Browser.agent === Sys.Browser.InternetExplorer) && (Sys.Browser.version < 7)) {
            var childFrame = elt._hideWindowedElementsIFrame;
            if (!childFrame) {
                childFrame = document.createElement("iframe");
                childFrame.src = "javascript:'<html></html>';";
                childFrame.style.position = "absolute";
                childFrame.style.display = "none";
                childFrame.scrolling = "no";
                childFrame.frameBorder = "0";
                childFrame.tabIndex = "-1";
                childFrame.style.filter = "progid:DXImageTransform.Microsoft.Alpha(style=0,opacity=0)";
                elt.parentNode.insertBefore(childFrame, elt);
                elt._hideWindowedElementsIFrame = childFrame;
                this._moveHandler = Function.createDelegate(this, this._onMove);
                Sys.UI.DomEvent.addHandler(elt, "move", this._moveHandler);
            }

            CommonToolkitScripts.setBounds(childFrame, newPosition);
            
            childFrame.style.display = elt.style.display;
            if (elt.currentStyle && elt.currentStyle.zIndex) {
                childFrame.style.zIndex = elt.currentStyle.zIndex;
            }
            else if (elt.style.zIndex) {
                childFrame.style.zIndex = elt.style.zIndex;
            }
        }
    },
    
    initialize : function() {
        Microsoft.Mtps.Rendering.Behaviors.Ajax.PopupBehavior.callBaseMethod(this, 'initialize');
        this.hide();
        this.get_element().style.position = "absolute";
    },
    
    dispose : function() {
        var elt = this.get_element();
        if (elt) {
            if (Sys.UI.DomElement.getVisible(elt)) {
                this.hide();
            }
            if (this._originalParent) {
                elt.parentNode.removeChild(elt);
                this._originalParent.appendChild(elt);
                this._originalParent = null;
            }
        }
        this._parentElement = null;
        Microsoft.Mtps.Rendering.Behaviors.Ajax.PopupBehavior.callBaseMethod(this, 'dispose');
    },
    
    _onMove : function() {
        var elt = this.get_element();
        if (elt._hideWindowedElementsIFrame) {
            elt.parentNode.insertBefore(elt._hideWindowedElementsIFrame, elt);
            elt._hideWindowedElementsIFrame.style.top = elt.style.top;
            elt._hideWindowedElementsIFrame.style.left = elt.style.left;
        }
    }

}
//Microsoft.Mtps.Rendering.Behaviors.Ajax.PopupBehavior.descriptor = {
//    properties: [   {name: 'parentElement', attributes: [ Sys.Attributes.Element, true ] },
//                    {name: 'positioningMode', type: Microsoft.Mtps.Rendering.Behaviors.Ajax.PositioningMode},
//                    {name: 'x', type: Number},
//                    {name: 'y', type: Number} ],
//    events: [   {name: 'show'},
//                {name: 'hide'} ]
//}
Microsoft.Mtps.Rendering.Behaviors.Ajax.PopupBehavior.registerClass('Microsoft.Mtps.Rendering.Behaviors.Ajax.PopupBehavior', Microsoft.Mtps.Rendering.Behaviors.Ajax.BehaviorBase);



if(typeof(Sys)!=='undefined')Sys.Application.notifyScriptLoaded();