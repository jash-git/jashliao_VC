// (c) Copyright Microsoft Corporation.
// This source is subject to the Microsoft Permissive License.
// See http://www.microsoft.com/resources/sharedsource/licensingbasics/sharedsourcelicenses.mspx.
// All other rights reserved.


Type.registerNamespace('Microsoft.Mtps.Rendering.Behaviors.Ajax');

Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingBehavior = function (element) {
    Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingBehavior.initializeBase(this, [element]);
    this._starCssClass = null;
    this._filledStarCssClass = null;
    this._emptyStarCssClass = null;
    this._waitingStarCssClass = null;
    this._readOnly = false;
    this._ratingValue = 0;
    this._currentRating = 0;
    this._maxRatingValue = 5;
    this._tag = "";
    this._ratingDirection = 0;
    this._stars = null;
    this._callbackID = null;
    this._mouseOutHandler = Function.createDelegate(this, this._onMouseOut);
    this._starClickHandler = Function.createDelegate(this, this._onStarClick);
    this._starMouseOverHandler = Function.createDelegate(this, this._onStarMouseOver);
}
Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingBehavior.prototype = {

    add_Rated : function(handler) {
        this.get_events().addHandler("Rated", handler);
    },
    remove_Rated : function(handler) {
        this.get_events().removeHandler("Rated", handler);
    },
    raiseRated : function(rating) {
        var handler = this.get_events().getHandler("Rated");
        if (handler) {
            handler(this, new Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingEventArgs(rating));
        }
    },
    
    add_EndClientCallback : function(handler) {
        this.get_events().addHandler("EndClientCallback", handler);
    },
    remove_EndClientCallback : function(handler) {
        this.get_events().removeHandler("EndClientCallback", handler);
    },
    raiseEndClientCallback : function(result) {
        var handler = this.get_events().getHandler("EndClientCallback");
        if (handler) {
            handler(this, new Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingCallbackResultEventArgs(result));
        }
    },

    get_Stars : function() {
        return this._stars;    
    },
    
    get_Tag : function() {
        return this._tag;
    },
    set_Tag : function(value) {
        if (this._tag != value) {
            this._tag = value;
            this.raisePropertyChanged('Tag');
        }
    },
    
    get_CallbackID : function() {
        return this._callbackID;
    },
    set_CallbackID : function(value) {
        this._callbackID = value;
    },
    
    get_RatingDirection : function() {
        return this._ratingDirection;
    },
    set_RatingDirection : function(value) {
        if (this._ratingDirection != value) {
            this._ratingDirection = value;
            if (this.get_isInitialized()) {
                this._update();
            }
            this.raisePropertyChanged('RatingDirection');
        }
    },
    
    get_EmptyStarCssClass : function() {
        return this._emptyStarCssClass;
    },
    set_EmptyStarCssClass : function(value) {
        if (this._emptyStarCssClass != value) {
            this._emptyStarCssClass = value;
            this.raisePropertyChanged('EmptyStarCssClass');
        }
    },
    
    get_FilledStarCssClass : function() {
        return this._FilledStarCssClass;
    },
    set_FilledStarCssClass : function(value) {
        if (this._filledStarCssClass != value) {
            this._filledStarCssClass = value;
            this.raisePropertyChanged('FilledStarCssClass');
        }
    },
    
    get_WaitingStarCssClass : function() {
        return this._waitingStarCssClass;
    },
    set_WaitingStarCssClass : function(value) {
        if (this._waitingStarCssClass != value) {
            this._waitingStarCssClass = value;
            this.raisePropertyChanged('WaitingStarCssClass');
        }
    },
    
    get_Rating : function() {
        this._ratingValue = Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingBehavior.callBaseMethod(this, 'get_ClientState');
        if (this._ratingValue == '') 
            this._ratingValue = null;
        return this._ratingValue;
    },
    set_Rating : function(value) {
        
//zafarbay: tweak//        if (this._ratingValue != value) {
            this._ratingValue = value;
            this._currentRating = value;
            if (this.get_isInitialized()) {
                if ((value < 0) || (value > this._maxRatingValue)) 
                    return;                
               
               this._update();
               
               Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingBehavior.callBaseMethod(this, 'set_ClientState', [ this._ratingValue ]);
               this.raisePropertyChanged('Rating');
               this.raiseRated(this._currentRating);
               this._waitingMode(true);
               
               var args = this._currentRating + ";" + this._tag;
               
//zafarbay: tweak//               WebForm_DoCallback(this._callbackID, args, this._receiveServerData, this, this._onError, true)

          var el = this.get_element();//zafarbay
          el.Rated=true;//zafarbay
            }
//zafarbay: tweak        }
    },

    get_MaxRating : function() {
        return this._maxRatingValue;
    },
    set_MaxRating : function(value) {
        if (this._maxRatingValue != value) {
            this._maxRatingValue = value;
            this.raisePropertyChanged('MaxRating');
        }
    },

    get_ReadOnly : function() {
        return this._readOnly;
    },
    set_ReadOnly : function(value) {
        if (this._readOnly != value) {
            this._readOnly = value;
            this.raisePropertyChanged('ReadOnly');
        }
    },
    
    get_StarCssClass : function() {
        return this._starCssClass;
    },
    set_StarCssClass : function(value) {
        if (this._starCssClass != value) {
            this._starCssClass = value;
            this.raisePropertyChanged('StarCssClass');
        }
    },
    
    initialize : function() {
        Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingBehavior.callBaseMethod(this, 'initialize');
        var elt = this.get_element();
        this._stars = [];
        for (var i = 1; i <= this._maxRatingValue; i++) {
            starElement = document.getElementById(elt.id + '_Star_' + i);
            starElement.value = i;
            Array.add(this._stars, starElement);
            $addHandler(starElement, 'click', this._starClickHandler);
            $addHandler(starElement, 'mouseover', this._starMouseOverHandler);
        }
        $addHandler(elt, 'mouseout', this._mouseOutHandler);        
        this._update();        
    },
    dispose : function() {
        var elt = this.get_element();
        if (this._stars) {
            for (var i = 0; i < this._stars.length; i++) {
                var starElement = this._stars[i];
                $removeHandler(starElement, 'click', this._starClickHandler);
                $removeHandler(starElement, 'mouseover', this._starMouseOverHandler);
            }
            this._stars = null;
        }
        $removeHandler(elt, 'mouseout', this._mouseOutHandler);        
        Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingBehavior.callBaseMethod(this, 'dispose');
    },
    _onError : function(message, context) {
        alert('An unhandled exception has occurred:\n' + message);
    },
    _receiveServerData : function(arg, context) {
        context._waitingMode(false);
        context.raiseEndClientCallback(arg);
    },
    _onMouseOut : function(e) {
        if (this._readOnly) {
            return;
        }
        this._currentRating = this._ratingValue;
        this._update();
    },    
    _onStarClick : function(e) {
        if (this._readOnly) {
            return;
        }
//        if (this._ratingValue != this._currentRating) {
            this.set_Rating(this._currentRating);
//        }
    },    
    _onStarMouseOver : function(e) {
        if (this._readOnly) {
            return;
        }
        if (this._ratingDirection == 0) {
            this._currentRating = e.target.value;
        } else {
            this._currentRating = this._maxRatingValue + 1 - e.target.value;
        }
        this._update();
    },    
    _waitingMode : function(activated) {
        for (var i = 0; i < this._maxRatingValue; i++) {
            var starElement;
            if (this._ratingDirection == 0) 
                starElement = this._stars[i];
            else 
                starElement = this._stars[this._maxRatingValue - i - 1]
            if (this._currentRating > i) {
                if (activated)
                {
                    Sys.UI.DomElement.removeCssClass(starElement, this._filledStarCssClass);
                    Sys.UI.DomElement.addCssClass(starElement, this._waitingStarCssClass);
                } else {
                    Sys.UI.DomElement.removeCssClass(starElement, this._waitingStarCssClass);
                    Sys.UI.DomElement.addCssClass(starElement, this._filledStarCssClass);
                }
            } else {
                Sys.UI.DomElement.removeCssClass(starElement, this._waitingStarCssClass);
                Sys.UI.DomElement.removeCssClass(starElement, this._filledStarCssClass);
                Sys.UI.DomElement.addCssClass(starElement, this._emptyStarCssClass);
            }
        }
    },    
    _update : function() {
        for (var i = 0; i < this._maxRatingValue; i++) {
            var starElement;
            if (this._ratingDirection == 0)
                starElement = this._stars[i];
            else
                starElement = this._stars[this._maxRatingValue - i - 1]

            if (this._currentRating > i) {
                Sys.UI.DomElement.removeCssClass(starElement, this._emptyStarCssClass);
                Sys.UI.DomElement.addCssClass(starElement, this._filledStarCssClass);
            }
            else {
                Sys.UI.DomElement.removeCssClass(starElement, this._filledStarCssClass);
                Sys.UI.DomElement.addCssClass(starElement, this._emptyStarCssClass);
            }
        }
    }
}

Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingBehavior.registerClass('Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingBehavior', Microsoft.Mtps.Rendering.Behaviors.Ajax.BehaviorBase);

Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingEventArgs = function (rating) {

    Sys.EventArgs.initializeBase(this);

    this._rating = rating;
}
Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingEventArgs.prototype = {
    get_Rating : function() {
        return this._rating;
    }
}
Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingEventArgs.registerClass('Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingEventArgs', Sys.EventArgs);

Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingCallbackResultEventArgs = function(result) {

    Sys.EventArgs.initializeBase(this);

    this._result = result;
}
Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingCallbackResultEventArgs.prototype = {
    get_CallbackResult : function() {
        return this._result;
    }
}
Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingCallbackResultEventArgs.registerClass('Microsoft.Mtps.Rendering.Behaviors.Ajax.RatingCallbackResultEventArgs', Sys.EventArgs);

if(typeof(Sys)!=='undefined')Sys.Application.notifyScriptLoaded();