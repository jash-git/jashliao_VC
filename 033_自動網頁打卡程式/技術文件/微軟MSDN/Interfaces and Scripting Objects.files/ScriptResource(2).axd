// (c) Copyright Microsoft Corporation.
// This source is subject to the Microsoft Permissive License.
// See http://www.microsoft.com/resources/sharedsource/licensingbasics/sharedsourcelicenses.mspx.
// All other rights reserved.


// Add common toolkit scripts here.  To consume the scripts on a control add
// 
//      [RequiredScript(typeof(CommonToolkitScripts))] 
//      public class SomeExtender : ...
// 
// to the controls extender class declaration.


Type.registerNamespace('Microsoft.Mtps.Rendering.Behaviors.Ajax');
Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide = function() {
    /// <summary>
    /// The BoxSide enumeration describes the sides of a DOM element
    /// </summary>
    /// <field name="Top" type="Number" integer="true" static="true" />
    /// <field name="Right" type="Number" integer="true" static="true" />
    /// <field name="Bottom" type="Number" integer="true" static="true" />
    /// <field name="Left" type="Number" integer="true" static="true" />
}
Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.prototype = {
    Top : 0,
    Right : 1,
    Bottom : 2,
    Left : 3
}
Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.registerEnum("Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide", false);





Microsoft.Mtps.Rendering.Behaviors.Ajax._CommonToolkitScripts = function() {
    /// <summary>
    /// The _CommonToolkitScripts class contains functionality utilized across a number
    /// of controls (but not universally)
    /// </summary>
    
    // Populate the borderThicknesses lookup table
    this._borderThicknesses = { };

    var div0 = document.createElement('div');
    var div1 = document.createElement('div');

    div0.style.visibility = 'hidden';
    div0.style.position = 'absolute';
    div0.style.fontSize = '1px';
    
    div1.style.height = '0px';
    div1.style.overflow = 'hidden';
    
    document.body.appendChild(div0).appendChild(div1);
                    
    var base = div0.offsetHeight;
    div1.style.borderTop = 'solid black';        

    div1.style.borderTopWidth = 'thin';
    this._borderThicknesses['thin'] = div0.offsetHeight - base;
    
    div1.style.borderTopWidth = 'medium';
    this._borderThicknesses['medium'] = div0.offsetHeight - base;
    
    div1.style.borderTopWidth = 'thick';
    this._borderThicknesses['thick'] = div0.offsetHeight - base;
    
    div0.removeChild(div1);
    document.body.removeChild(div0);
    div0 = null;
    div1 = null;
}
Microsoft.Mtps.Rendering.Behaviors.Ajax._CommonToolkitScripts.prototype = {
    // The order of these lookup tables is directly linked to the BoxSide enum defined above
    _borderStyleNames : ['borderTopStyle','borderRightStyle','borderBottomStyle','borderLeftStyle'],
    _borderWidthNames : ['borderTopWidth', 'borderRightWidth', 'borderBottomWidth', 'borderLeftWidth'],
    _paddingWidthNames : ['paddingTop', 'paddingRight', 'paddingBottom', 'paddingLeft'],
    
    getCurrentStyle : function(element, attribute, defaultValue) {
        /// <summary>
        /// CommonToolkitScripts.getCurrentStyle is used to compute the value of a style attribute on an
        /// element that is currently being displayed.  This is especially useful for scenarios where
        /// several CSS classes and style attributes are merged, or when you need information about the
        /// size of an element (such as its padding or margins) that is not exposed in any other fashion.
        /// </summary>
        /// <param name="element" type="Sys.UI.DomElement">Live DOM element to check style of</param>
        /// <param name="attribute" type="String">
        /// The style attribute's name is expected to be in a camel-cased form that you would use when
        /// accessing a JavaScript property instead of the hyphenated form you would use in a CSS
        /// stylesheet (i.e. it should be "backgroundColor" and not "background-color").
        /// </param>
        /// <param name="defaultValue" type="Object" mayBeNull="true" optional="true">
        /// In the event of a problem (i.e. a null element or an attribute that cannot be found) we
        /// return this object (or null if none if not specified).
        /// </param>
        /// <returns />

       var currentValue = null;
        if (element) {
            if (element.currentStyle) {
                currentValue = element.currentStyle[attribute];
            } else if (document.defaultView && document.defaultView.getComputedStyle) {
                var style = document.defaultView.getComputedStyle(element, null);
                if (style) {
                    currentValue = style[attribute];
                }
            }
            
            if (!currentValue && element.style.getPropertyValue) {
                currentValue = element.style.getPropertyValue(attribute);
            }
            else if (!currentValue && element.style.getAttribute) {
                currentValue = element.style.getAttribute(attribute);
            }       
        }
        
        if ((!currentValue || currentValue == "" || typeof(currentValue) === 'undefined')) {
            if (typeof(defaultValue) != 'undefined') {
                currentValue = defaultValue;
            }
            else {
                currentValue = null;
            }
        }   
        return currentValue;     
    },

    getInheritedBackgroundColor : function(element) {
        /// <summary>
        /// CommonToolkitScripts.getInheritedBackgroundColor provides the ability to get the displayed
        /// background-color of an element.  In most cases calling CommonToolkitScripts.getCurrentStyle
        /// won't do the job because it will return "transparent" unless the element has been given a
        /// specific background color.  This function will walk up the element's parents until it finds
        /// a non-transparent color.  If we get all the way to the top of the document or have any other
        /// problem finding a color, we will return the default value '#FFFFFF'.  This function is
        /// especially important when we're using opacity in IE (because ClearType will make text look
        /// horrendous if you fade it with a transparent background color).
        /// </summary>
        /// <param name="element" type="Sys.UI.DomElement">
        /// Live DOM element to get the background color of
        /// </param>
        /// <returns />
        
        if (!element) return '#FFFFFF';
        var background = this.getCurrentStyle(element, 'backgroundColor');
        try {
            while (!background || background == '' || background == 'transparent' || background == 'rgba(0, 0, 0, 0)') {
                element = element.parentNode;
                if (!element) {
                    background = '#FFFFFF';
                } else {
                    background = this.getCurrentStyle(element, 'backgroundColor');
                }
            }
        } catch(ex) {
            background = '#FFFFFF';
        }
        return background;
    },
    
    getLocation : function(element) {
        /// <summary>
        /// Gets the actual location of an element.
        /// </summary>
        /// <remarks>
        /// Gets the top/left distance from the top/left corner of the browser window.
        /// Overcomes offsetTop/Left calculation issues in IE5+.
        /// </remarks>
        /// <param name="element" type="Sys.UI.DomElement">DOM element</param>
        /// <returns type="Object">Location (of the form {x,y}) with respect to the top/left corner</returns>
    
        if (!element) {
            throw Error.argumentNull('element');
        }
        var offsetX = element.offsetLeft;
        var offsetY = element.offsetTop;
        var parent;
        var tdLeftBorderFound;
        var tdTopBorderFound;
        var leftBorderThickness;
        var topBorderThickness;
        var defaultTdLeftBorderFound;
        var defaultTdTopBorderFound;        
        for (parent = element.offsetParent; parent; parent = parent.offsetParent) {
            if (Sys.Browser.agent == Sys.Browser.InternetExplorer && parent.nodeName != 'BODY') {                
                if(parent.nodeName == 'TD' && parent.currentStyle.borderLeftStyle == 'inset' && parent.currentStyle.borderLeftWidth == 'medium') {
                    defaultTdLeftBorderFound = true;
                }
                if(parent.nodeName == 'TD' && parent.currentStyle.borderTopStyle == 'inset' && parent.currentStyle.borderTopWidth == 'medium') {
                    defaultTdTopBorderFound = true;
                }
                if(parent.nodeName == 'TABLE') {
                    if(parent.rules == "all") {
                        var mediumThickness = this.parseBorderWidth("medium");
                        if(defaultTdLeftBorderFound) offsetX -= mediumThickness - 1;
                        if(defaultTdTopBorderFound) offsetY -= mediumThickness - 1;
                    }
                    if(parent.currentStyle.borderCollapse == 'collapse') {
                        if(tdLeftBorderFound && !defaultTdLeftBorderFound && leftBorderThickness > 1) offsetX --;
                        if(tdTopBorderFound && !defaultTdTopBorderFound && topBorderThickness > 1) offsetY --;
                    }
                    tdTopBorderFound = false;
                    tdLeftBorderFound = false;
                    defaultTdLeftBorderFound = false;
                    defaultTdTopBorderFound = false;
                }
                if(this.isBorderVisible(parent, Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.Left)) {
                    if(parent.nodeName == 'TD') tdLeftBorderFound = true;
                    offsetX += leftBorderThickness = this.getBorderWidth(parent, Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.Left);
                }
                if(this.isBorderVisible(parent, Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.Top)) {  
                    if(parent.nodeName == 'TD') tdTopBorderFound = true;
                    offsetY += topBorderThickness = this.getBorderWidth(parent, Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.Top);
                }
            }
            if (parent.offsetLeft) {
                offsetX += parent.offsetLeft;   
            }
            if (parent.offsetTop) {
                offsetY += parent.offsetTop;
            }
            if (parent.nodeName != 'BODY' && parent.nodeName != 'HTML') {
                if (parent.scrollLeft) {
                    offsetX -= parent.scrollLeft;
                }
                if (parent.scrollTop) {
                    offsetY -= parent.scrollTop;
                }
            }
        }
        return { x : offsetX, y : offsetY };
    },
    
    setLocation : function(element, point) {
        /// <summary>
        /// Sets the current location for an element.  
        /// </summary>
        /// <remarks>
        /// This method does not attempt to set the positioning mode of an element. 
        /// The position is relative from the elements nearest position:relative or 
        /// position:absolute element.
        /// </remarks>
        /// <param name="element" type="Sys.UI.DomElement">DOM element</param>
        /// <param name="element" type="Object">Point object (of the form {x,y})</param>
        /// <returns />
        
        if (!element) {
            throw Error.argumentNull('element');
        }
        if (!point) {
            throw Error.argumentNull('point');
        }
        element.style.left = point.x.toString() + 'px';
        element.style.top = point.y.toString() + 'px';
    },
    
    getContentSize : function(element) {
        /// <summary>
        /// Gets the "content-box" size of an element.
        /// </summary>
        /// <remarks>
        /// The "content-box" is the size of the content area *inside* of the borders and 
        /// padding of an element. The "content-box" size does not include the margins around
        /// the element.
        /// </remarks>
        /// <param name="element" type="Sys.UI.DomElement">DOM element</param>
        /// <returns type="Object">Size of the element (in the form {width,height})</returns>
        
        if (!element) {
            throw Error.argumentNull('element');
        }
        var size = this.getSize(element);
        var borderBox = this.getBorderBox(element);
        var paddingBox = this.getPaddingBox(element);
        return {
            width :  size.width - borderBox.horizontal - paddingBox.horizontal,
            height : size.height - borderBox.vertical - paddingBox.vertical
        }
    },

    getSize : function(element) {
        /// <summary>
        /// Gets the "border-box" size of an element.
        /// </summary>
        /// <remarks>
        /// The "border-box" is the size of the content area *outside* of the borders and 
        /// padding of an element.  The "border-box" size does not include the margins around
        /// the element.
        /// </remarks>
        /// <param name="element" type="Sys.UI.DomElement">DOM element</param>
        /// <returns type="Object">Size of the element (in the form {width,height})</returns>
        
        if (!element) {
            throw Error.argumentNull('element');
        }
        return {
            width:  element.offsetWidth,
            height: element.offsetHeight
        };
    },
    
    setContentSize : function(element, size) {
        /// <summary>
        /// Sets the "content-box" size of an element.
        /// </summary>
        /// <remarks>
        /// The "content-box" is the size of the content area *inside* of the borders and 
        /// padding of an element. The "content-box" size does not include the margins around
        /// the element.
        /// </remarks>
        /// <param name="element" type="Sys.UI.DomElement">DOM element</param>
        /// <param name="size" type="Object">Size of the element (in the form {width,height})</param>
        /// <returns />
        
        if (!element) {
            throw Error.argumentNull('element');
        }
        if (!size) {
            throw Error.argumentNull('size');
        }
        // FF respects -moz-box-sizing css extension, so adjust the box size for the border-box
        if(this.getCurrentStyle(element, 'MozBoxSizing') == 'border-box' || this.getCurrentStyle(element, 'BoxSizing') == 'border-box') {
            var borderBox = this.getBorderBox(element);
            var paddingBox = this.getPaddingBox(element);
            size = {
                width: size.width + borderBox.horizontal + paddingBox.horizontal,
                height: size.height + borderBox.vertical + paddingBox.vertical
            };
        }
        element.style.width = size.width.toString() + 'px';
        element.style.height = size.height.toString() + 'px';
    },
    
    setSize : function(element, size) {
        /// <summary>
        /// Sets the "border-box" size of an element.
        /// </summary>
        /// <remarks>
        /// The "border-box" is the size of the content area *outside* of the borders and 
        /// padding of an element.  The "border-box" size does not include the margins around
        /// the element.
        /// </remarks>
        /// <param name="element" type="Sys.UI.DomElement">DOM element</param>
        /// <param name="size" type="Object">Size of the element (in the form {width,height})</param>
        /// <returns />
        
        if (!element) {
            throw Error.argumentNull('element');
        }
        if (!size) {
            throw Error.argumentNull('size');
        }
        var borderBox = this.getBorderBox(element);
        var paddingBox = this.getPaddingBox(element);
        var contentSize = {
            width:  size.width - borderBox.horizontal - paddingBox.horizontal,
            height: size.height - borderBox.vertical - paddingBox.vertical
        };
        this.setContentSize(element, contentSize);
    },
    
    getBounds : function(element) {
        /// <summary>
        /// Gets the "border-box" bounds of an element
        /// </summary>
        /// <remarks>
        /// The "border-box" is the size of the content area *outside* of the borders and 
        /// padding of an element.  The "border-box" size does not include the margins around
        /// the element.
        /// </remarks>
        /// <param name="element" type="Sys.UI.DomElement">DOM element</param>
        /// <returns type="object">
        /// Bounds of the element (of the form
        /// {x,y,width,height,right,bottom,location:{x,y},size:{width,height}})
        /// </returns>
        
        if (!element) {
            throw Error.argumentNull('element');
        }
        var location = this.getLocation(element);
        var size = this.getSize(element);
        return { 
            x: location.x, 
            y: location.y, 
            width: size.width, 
            height: size.height,
            right: location.x + size.width,
            bottom: location.y + size.height,
            location: location,
            size: size
        };
    }, 
    
    setBounds : function(element, bounds) {
        /// <summary>
        /// Sets the "border-box" bounds of an element
        /// </summary>
        /// <remarks>
        /// The "border-box" is the size of the content area *outside* of the borders and 
        /// padding of an element.  The "border-box" size does not include the margins around
        /// the element.
        /// </remarks>
        /// <param name="element" type="Sys.UI.DomElement">DOM element</param>
        /// <param name="bounds" type="Object">Bounds of the element (of the form {x,y,width,height})</param>
        /// <returns />
        
        if (!element) {
            throw Error.argumentNull('element');
        }
        if (!bounds) {
            throw Error.argumentNull('bounds');
        }
        this.setSize(element, bounds);
        this.setLocation(element, bounds);
    },
    
    getBorderBox : function(element) {
        /// <summary>
        /// Gets the entire border box sizes.
        /// </summary>
        /// <param name="element" type="Sys.UI.DomElement">DOM element</param>
        /// <returns type="Object">Element's border box sizes (of the form {top,left,bottom,right,horizontal,vertical})</returns>
        
        if (!element) {
            throw Error.argumentNull('element');
        }
        var box = {
            top: this.getBorderWidth(element, Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.Top),
            right: this.getBorderWidth(element, Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.Right),
            bottom: this.getBorderWidth(element, Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.Bottom),
            left: this.getBorderWidth(element, Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.Left)
        }
        box.horizontal = box.left + box.right;
        box.vertical = box.top + box.bottom;
        return box;
    },
    
    getPaddingBox : function(element) {
        /// <summary>
        /// Gets the entire padding box sizes.
        /// </summary>
        /// <param name="element" type="Sys.UI.DomElement">DOM element</param>
        /// <returns type="Object">Element's padding box sizes (of the form {top,left,bottom,right,horizontal,vertical})</returns>
        
        if (!element) {
            throw Error.argumentNull('element');
        }
        var box = {
            top: this.getPadding(element, Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.Top),
            right: this.getPadding(element, Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.Right),
            bottom: this.getPadding(element, Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.Bottom),
            left: this.getPadding(element, Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.Left)
        }
        box.horizontal = box.left + box.right;
        box.vertical = box.top + box.bottom;
        return box;
    },
    
    isBorderVisible : function(element, boxSide) {
        /// <summary>
        /// Gets whether the current border style for an element on a specific boxSide is not 'none'.
        /// </summary>
        /// <param name="element" type="Sys.UI.DomElement">DOM element</param>
        /// <param name="boxSide" type="Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide">Side of the element</param>
        /// <returns type="Boolean">
        /// Whether the current border style for an element on a specific boxSide is not 'none'.
        /// </returns>
        
        if (!element) {
            throw Error.argumentNull('element');
        }
        if(boxSide < Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.Top || boxSide > Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.Left) {
            throw Error.argumentOutOfRange("Argument 'boxSide' out of the range of expected values");
        }
        var styleName = this._borderStyleNames[boxSide];
        var styleValue = this.getCurrentStyle(element, styleName);
        return styleValue != "none";
    },

    getBorderWidth : function(element, boxSide) {
        /// <summary>
        /// Gets the border thickness of an element on a specific boxSide.
        /// </summary>
        /// <param name="element" type="Sys.UI.DomElement">DOM element</param>
        /// <param name="boxSide" type="Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide">Side of the element</param>
        /// <returns type="Number">Border thickness on the element's specified side</returns>
        
        if (!element) {
            throw Error.argumentNull('element');
        }
        if(boxSide < Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.Top || boxSide > Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.Left) {
            throw Error.argumentOutOfRange("Argument 'boxSide' out of the range of expected values");
        }
        if(!this.isBorderVisible(element, boxSide)) {
            return 0;
        }        
        var styleName = this._borderWidthNames[boxSide];    
        var styleValue = this.getCurrentStyle(element, styleName);
        return this.parseBorderWidth(styleValue);
    },
    
    getPadding : function(element, boxSide) {
        /// <summary>
        /// Gets the padding thickness of an element on a specific boxSide.
        /// </summary>
        /// <param name="element" type="Sys.UI.DomElement">DOM element</param>
        /// <param name="boxSide" type="Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide">Side of the element</param>
        /// <returns type="Number">Padding on the element's specified side</returns>
        
        if (!element) {
            throw Error.argumentNull('element');
        }
        if(boxSide < Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.Top || boxSide > Microsoft.Mtps.Rendering.Behaviors.Ajax.BoxSide.Left) {
            throw Error.argumentOutOfRange("Argument 'boxSide' out of the range of expected values");
        }
        var styleName = this._paddingWidthNames[boxSide];
        var styleValue = this.getCurrentStyle(element, styleName);
        return this.parsePadding(styleValue);
    },
    
    parseBorderWidth : function(borderWidth) {
        /// <summary>
        /// Parses a border-width string into a pixel size
        /// </summary>
        /// <param type="String" mayBeNull="true">borderWidth is String ('thin','medium','thick','inherit',<px unit>,null,'')</param>
        /// <returns type="Number">Number of pixels in the border-width</returns>
        
        if(borderWidth) {
            switch(borderWidth) {
                case 'thin':
                case 'medium':
                case 'thick':
                    return this._borderThicknesses[borderWidth];
                case 'inherit':
                    return 0;
            }
            var unit = this.parseUnit(borderWidth);
//            debug.assert(unit.type == 'px', 'A unit type of ' + unit.type + ' is invalid for parseBorderWidth');
            return unit.size;
        }
        return 0;
    },
    
    parsePadding : function(padding) {
        /// <summary>
        /// Parses a padding string into a pixel size
        /// </summary>
        /// <param type="String" mayBeNull="true">Padding to parse ('inherit',<px unit>,null,'')</param>
        /// <returns type="Number">Number of pixels in the padding</returns>
        
        if(padding) {
            if(padding == 'inherit') {
                return 0;
            }
            var unit = this.parseUnit(padding);
//            debug.assert(unit.type == 'px', 'A unit type of ' + unit.type + ' is invalid for parsePadding');
            return unit.size;
        }
        return 0;
    },
    
    parseUnit : function(value) {
        /// <summary>
        /// Parses a unit string into a unit object
        /// </summary>
        /// <param type="String" mayBeNull="false">Value to parse (of the form <px unit>,<% unit>,<em unit>,...)</param>
        /// <returns type="Object">Parsed unit (of the form {size,type})</returns>
        
        if (!value) {
            throw Error.argumentNull('value');
        }
        
        value = value.trim().toLowerCase();
        var l = value.length;
        var s = -1;
        for(var i = 0; i < l; i++) {
            var ch = value.substr(i, 1);
            if((ch < '0' || ch > '9') && ch != '-' && ch != '.' && ch != ',') {
                break;
            }
            s = i;
        }
        if(s == -1) {
            throw Error.create("No digits.");
        }
        var type;
        var size;
        if(s < (l - 1)) {
            type = value.substring(s + 1).trim();
        } else {
            type = 'px';
        }
        size = parseFloat(value.substr(0, s + 1));
        if(type == 'px') {
            size = Math.floor(size);
        }
        return { 
            size: size,
            type: type
        };
    },
    
    getElementOpacity : function(element) {
        /// <summary>
        /// Get the element's opacity
        /// </summary>
        /// <param name="element" type="Sys.UI.DomElement">Element</param>
        /// <returns type="Number">Opacity of the element</returns>
        
        if (!element) {
            throw Error.argumentNull('element');
        }
        
        var hasOpacity = false;
        var opacity;
        
        if (element.filters) {
            var filters = element.filters;
            if (filters.length !== 0) {
                var alphaFilter = filters['DXImageTransform.Microsoft.Alpha'];
                if (alphaFilter) {
                    opacity = alphaFilter.opacity / 100.0;
                    hasOpacity = true;
                }
            }
        }
        else {
            opacity = this.getCurrentStyle(element, 'opacity', 1);
//            var computedStyle = document.defaultView.getComputedStyle;
//            opacity = computedStyle(element, null).getPropertyValue('opacity');
            hasOpacity = true;
        }
        
        if (hasOpacity === false) {
            return 1.0;
        }
        return parseFloat(opacity);
    },

    setElementOpacity : function(element, value) {
        /// <summary>
        /// Set the element's opacity
        /// </summary>
        /// <param name="element" type="Sys.UI.DomElement">Element</param>
        /// <param name="value" type="Number">Opacity of the element</param>
        /// <returns />
        
        if (!element) {
            throw Error.argumentNull('element');
        }
        
        if (element.filters) {
            var filters = element.filters;
            var createFilter = true;
            if (filters.length !== 0) {
                var alphaFilter = filters['DXImageTransform.Microsoft.Alpha'];
                if (alphaFilter) {
                    createFilter = false;
                    alphaFilter.opacity = value * 100;
                }
            }
            if (createFilter) {
                element.style.filter = 'progid:DXImageTransform.Microsoft.Alpha(opacity=' + (value * 100) + ')';
            }
        }
        else {
            element.style.opacity = value;
        }
    },
    
    resolveFunction : function(value) {
        /// <summary>
        /// Returns a function reference that corresponds to the provided value
        /// </summary>
        /// <param name="value" type="Object">
        /// The value can either be a Function, the name of a function (that can be found using window['name']),
        /// or an expression that evaluates to a function.
        /// </param>
        /// <returns type="Function">Reference to the function, or null if not found</returns>
        
        if (value) {
            if (value instanceof Function) {
                return value;
            } else if (String.isInstanceOfType(value) && value.length > 0) {
                var func;
                if ((func = window[value]) instanceof Function) {
                    return func;
                } else if ((func = eval(value)) instanceof Function) {
                    return func;
                }
            }
        }
        return null;
    }
}

// Create the singleton instance of the CommonToolkitScripts
var CommonToolkitScripts = Microsoft.Mtps.Rendering.Behaviors.Ajax.CommonToolkitScripts = new Microsoft.Mtps.Rendering.Behaviors.Ajax._CommonToolkitScripts();

if(typeof(Sys)!=='undefined')Sys.Application.notifyScriptLoaded();