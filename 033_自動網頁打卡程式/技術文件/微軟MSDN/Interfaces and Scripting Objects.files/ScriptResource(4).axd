// (c) Copyright Microsoft Corporation.
// This source is subject to the Microsoft Permissive License.
// See http://www.microsoft.com/resources/sharedsource/licensingbasics/sharedsourcelicenses.mspx.
// All other rights reserved.


Type.registerNamespace('Microsoft.Mtps.Rendering.Behaviors.Ajax');

// This is the base behavior for all extender behaviors
//
Microsoft.Mtps.Rendering.Behaviors.Ajax.BehaviorBase = function(element) {
    Microsoft.Mtps.Rendering.Behaviors.Ajax.BehaviorBase.initializeBase(this,[element]);
    
    // Properties
    this._clientStateFieldID = null;

    // Variables
    this._pageRequestManager = null;
    this._partialUpdateBeginRequestHandler = null;
    this._partialUpdateEndRequestHandler = null;
}
Microsoft.Mtps.Rendering.Behaviors.Ajax.BehaviorBase.prototype = {
    initialize : function() {
        Microsoft.Mtps.Rendering.Behaviors.Ajax.BehaviorBase.callBaseMethod(this, 'initialize');
    },

    dispose : function() {
        Microsoft.Mtps.Rendering.Behaviors.Ajax.BehaviorBase.callBaseMethod(this, 'dispose');

        if (this._pageRequestManager) {
            if (this._partialUpdateBeginRequestHandler) {
                this._pageRequestManager.remove_beginRequest(this._partialUpdateBeginRequestHandler);
                this._partialUpdateBeginRequestHandler = null;
            }
            if (this._partialUpdateEndRequestHandler) {
                this._pageRequestManager.remove_endRequest(this._partialUpdateEndRequestHandler);
                this._partialUpdateEndRequestHandler = null;
            }
            this._pageRequestManager = null;
        }
    },

//    getDescriptor : function() {
//        var td = Microsoft.Mtps.Rendering.Behaviors.Ajax.BehaviorBase.callBaseMethod(this, 'getDescriptor');
//        td.addProperty('ClientStateFieldID', String);
//        return td;
//    },

    get_ClientStateFieldID : function() {
        return this._clientStateFieldID;
    },

    set_ClientStateFieldID : function(value) {
        if (this._clientStateFieldID != value) {
            this._clientStateFieldID = value;
            this.raisePropertyChanged('ClientStateFieldID');
        }
    },

    get_ClientState : function() {
        if (this._clientStateFieldID) {
            var input = document.getElementById(this._clientStateFieldID);
            if (input) {
                return input.value;
            }
        }
        return null;
    },

    set_ClientState : function(value) {
        if (this._clientStateFieldID) {
            var input = document.getElementById(this._clientStateFieldID);
            if (input) {
                input.value = value;
            }
        }
    },

    // Called by a derived class to register a property changed handler for partial updates
    registerPartialUpdateEvents : function() {
        if (Sys && Sys.WebForms && Sys.WebForms.PageRequestManager){
            this._pageRequestManager = Sys.WebForms.PageRequestManager.getInstance();
            if (this._pageRequestManager) {
                this._partialUpdateBeginRequestHandler = Function.createDelegate(this, this._partialUpdateBeginRequest);
                this._pageRequestManager.add_beginRequest(this._partialUpdateBeginRequestHandler);
                this._partialUpdateEndRequestHandler = Function.createDelegate(this, this._partialUpdateEndRequest);
                this._pageRequestManager.add_endRequest(this._partialUpdateEndRequestHandler);
            }
        }
    },

    // Methods called triggered when a partial update begins/ends
    // Note: Valid iff registerPartialUpdateEvents was already called
    _partialUpdateBeginRequest : function(sender, beginRequestEventArgs) {
        // Nothing done here; override this method in a child class
    },
    _partialUpdateEndRequest : function(sender, endRequestEventArgs) {
        // Nothing done here; override this method in a child class
    }
}
Microsoft.Mtps.Rendering.Behaviors.Ajax.BehaviorBase.registerClass('Microsoft.Mtps.Rendering.Behaviors.Ajax.BehaviorBase', Sys.UI.Behavior);


// Dynamically populates content when the populate method is called
//
Microsoft.Mtps.Rendering.Behaviors.Ajax.DynamicPopulateBehaviorBase = function(element) {
    Microsoft.Mtps.Rendering.Behaviors.Ajax.DynamicPopulateBehaviorBase.initializeBase(this, [element]);
    
    // Properties
    this._DynamicControlID = null;
    this._DynamicContextKey = null;
    this._DynamicServicePath = null;
    this._DynamicServiceMethod = null;

    // Variables
    this._dynamicPopulateBehavior = null;
}
Microsoft.Mtps.Rendering.Behaviors.Ajax.DynamicPopulateBehaviorBase.prototype = {
    initialize : function() {
        Microsoft.Mtps.Rendering.Behaviors.Ajax.DynamicPopulateBehaviorBase.callBaseMethod(this, 'initialize');
    },

    dispose : function() {
        // Dispose of the placeholder control and behavior
        if (this._dynamicPopulateBehavior) {
            this._dynamicPopulateBehavior.dispose();
            this._dynamicPopulateBehavior = null;
        }

        Microsoft.Mtps.Rendering.Behaviors.Ajax.DynamicPopulateBehaviorBase.callBaseMethod(this, 'dispose');
    },

//    getDescriptor : function() {
//        var td = Microsoft.Mtps.Rendering.Behaviors.Ajax.DynamicPopulateBehaviorBase.callBaseMethod(this, 'getDescriptor');
//        td.addProperty('DynamicControlID', String);
//        td.addProperty('DynamicContextKey', String);
//        td.addProperty('DynamicServicePath', String);
//        td.addProperty('DynamicServiceMethod', String);
//        return td;
//    },

    populate : function(contextKeyOverride) {
        // If the DynamicPopulateBehavior's element is out of date, dispose of it
        if (this._dynamicPopulateBehavior && (this._dynamicPopulateBehavior.get_element() != $get(this._DynamicControlID))) {
            this._dynamicPopulateBehavior.dispose();
            this._dynamicPopulateBehavior = null;
        }
        // If a DynamicPopulateBehavior is not available and the necessary information is, create one
        if (!this._dynamicPopulateBehavior && this._DynamicControlID && this._DynamicServiceMethod) {
            this._dynamicPopulateBehavior = $create(Microsoft.Mtps.Rendering.Behaviors.Ajax.DynamicPopulateBehavior, {"id":this.get_id()+"_DynamicPopulateBehavior", "ContextKey":this._DynamicContextKey, "ServicePath":this._DynamicServicePath, "ServiceMethod":this._DynamicServiceMethod }, null, null, $get(this._DynamicControlID));
        }
        // If a DynamicPopulateBehavior is available, use it to populate the dynamic content
        if(this._dynamicPopulateBehavior) {
            this._dynamicPopulateBehavior.populate(contextKeyOverride ? contextKeyOverride : this._DynamicContextKey);
        }
    },

    get_DynamicControlID : function() {
        return this._DynamicControlID;
    },

    set_DynamicControlID : function(value) {
        if (this._DynamicControlID != value) {
            this._DynamicControlID = value;
            this.raisePropertyChanged('DynamicControlID');
        }
    },

    get_DynamicContextKey : function() {
        return this._DynamicContextKey;
    },

    set_DynamicContextKey : function(value) {
        if (this._DynamicContextKey != value) {
            this._DynamicContextKey = value;
            this.raisePropertyChanged('DynamicContextKey');
        }
    },

    get_DynamicServicePath : function() {
        return this._DynamicServicePath;
    },

    set_DynamicServicePath : function(value) {
        if (this._DynamicServicePath != value) {
            this._DynamicServicePath = value;
            this.raisePropertyChanged('DynamicServicePath');
        }
    },

    get_DynamicServiceMethod : function() {
        return this._DynamicServiceMethod;
    },

    set_DynamicServiceMethod : function(value) {
        if (this._DynamicServiceMethod != value) {
            this._DynamicServiceMethod = value;
            this.raisePropertyChanged('DynamicServiceMethod');
        }
    }
}

Microsoft.Mtps.Rendering.Behaviors.Ajax.DynamicPopulateBehaviorBase.registerClass('Microsoft.Mtps.Rendering.Behaviors.Ajax.DynamicPopulateBehaviorBase', Microsoft.Mtps.Rendering.Behaviors.Ajax.BehaviorBase);

if(typeof(Sys)!=='undefined')Sys.Application.notifyScriptLoaded();