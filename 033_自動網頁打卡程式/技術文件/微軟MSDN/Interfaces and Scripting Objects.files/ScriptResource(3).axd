// (c) Copyright Microsoft Corporation.
// This source is subject to the Microsoft Permissive License.
// See http://www.microsoft.com/resources/sharedsource/licensingbasics/sharedsourcelicenses.mspx.
// All other rights reserved.


// Repository of old "Atlas" code that we're waiting to have integrated into the new Microsoft Ajax Library


///////////////////////////
/// Sys.UI.DomElement

// DELTA - not present in codebase but called from PopupBehavior
Sys.UI.DomElement.setVisible = function(e, value) {

    if (!e) return;

    if (value != Sys.UI.DomElement.getVisible(e)) {
        
        if (value) {
            if (e.style.removeAttribute) {
                e.style.removeAttribute("display");
            } else {
               e.style.removeProperty("display");
            }
        }
        else {
            e.style.display = 'none';
        }
        
        e.style.visibility = value ? 'visible' : 'hidden';
    }
}

Sys.UI.DomElement.getVisible = function(e) {

    if (!e) return false;

    return (("none" != Microsoft.Mtps.Rendering.Behaviors.Ajax.CommonToolkitScripts.getCurrentStyle(e, "display")) &&
        ("hidden" != Microsoft.Mtps.Rendering.Behaviors.Ajax.CommonToolkitScripts.getCurrentStyle(e, "visibility")));
}


//////////////////////////////////////
// Sys.UI.Control.overlaps
//

Sys.UI.Control.overlaps = function overlaps(r1, r2) {
    var xLeft = (r1.x >= r2.x && r1.x <= (r2.x + r2.width));
    var xRight = ((r1.x + r1.width) >= r2.x && (r1.x + r1.width) <= r2.x + r2.width);
    var xComplete = ((r1.x < r2.x) && ((r1.x + r1.height) > (r2.x + r2.height)));
    
    var yLeft = (r1.y >= r2.y && r1.y <= (r2.y + r2.height));
    var yRight = ((r1.y + r1.height) >= r2.y && (r1.y + r1.height) <= r2.y + r2.height);
    var yComplete = ((r1.y < r2.y) && ((r1.y + r1.height) > (r2.y + r2.height)));
    if ((xLeft || xRight || xComplete) && (yLeft || yRight || yComplete)) {
        return true;
    }
    
    return false;
}

if(typeof(Sys)!=='undefined')Sys.Application.notifyScriptLoaded();