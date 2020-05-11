// //
// Copyright 2007 comScore Networks. All rights reserved.

// Name: Microsoft-msdn2
// Date: 2007-07-17


// Multiple script protection.
if (!window.SiteRecruit_Globals) {

// Create the configuration, globals, and constants namespaces.
var SiteRecruit_Config = new Object();
var SiteRecruit_Globals = new Object();
var SiteRecruit_Constants = new Object();

// Validation variables.
SiteRecruit_Globals.parseFlag = false;
SiteRecruit_Globals.empty = false;

// Browser information.
SiteRecruit_Constants.browser = new Object();
SiteRecruit_Constants.browser.internetExplorer = 'Microsoft Internet Explorer';
SiteRecruit_Constants.browser.mozilla = 'Netscape';
SiteRecruit_Constants.browser.opera = 'Opera';

// Check browser information.
SiteRecruit_Globals.browserName = navigator.appName; 
SiteRecruit_Globals.browserVersion = parseInt(navigator.appVersion);

// Initialize browser flags.
SiteRecruit_Globals.isInternetExplorer = false;
SiteRecruit_Globals.isMozilla = false;
SiteRecruit_Globals.isInternetExplorer7 = false;

// Check for Internet Explorer based browsers.
if (SiteRecruit_Globals.browserName == SiteRecruit_Constants.browser.internetExplorer)
{
    if (SiteRecruit_Globals.browserVersion > 3)
    {
        // Only 5.5 and above.
        var a = navigator.userAgent.toLowerCase();
        if (a.indexOf("msie 5.0") == -1 && a.indexOf("msie 5.0") == -1)
        {
            SiteRecruit_Globals.isInternetExplorer = true;
        }
        
        // Check for 7.
        if (a.indexOf("msie 7") != -1)
        {
            SiteRecruit_Globals.isInternetExplorer7 = true;
        }
    }
}

// Check for Mozilla based browsers.
if (SiteRecruit_Globals.browserName == SiteRecruit_Constants.browser.mozilla)
{
    if (SiteRecruit_Globals.browserVersion > 4)
    {
        SiteRecruit_Globals.isMozilla = true;
    }
}

// Since Opera 9.02, they no longer use 'Mozilla' in the browser name
if (SiteRecruit_Globals.browserName == SiteRecruit_Constants.browser.opera)
{
	SiteRecruit_Globals.isMozilla = true;	// treat the same as Mozilla
}



// Cookie lifetime.
SiteRecruit_Constants.cookieLifetimeType = new Object();
SiteRecruit_Constants.cookieLifetimeType.duration = 1;
SiteRecruit_Constants.cookieLifetimeType.expireDate = 2;
    
// Invitation type.
SiteRecruit_Constants.invitationType = new Object();
SiteRecruit_Constants.invitationType.standard = 0;
SiteRecruit_Constants.invitationType.email = 1;
SiteRecruit_Constants.invitationType.domainDeparture = 2;
SiteRecruit_Constants.invitationType.emailDomainDeparture = 3;
    
// Cookie type flags.
SiteRecruit_Constants.cookieType = new Object();
SiteRecruit_Constants.cookieType.alreadyAsked = 1;
SiteRecruit_Constants.cookieType.inProgress = 2;
SiteRecruit_Constants.cookieType.emailDomainDeparture = 3;

// Alignment types.
SiteRecruit_Constants.horizontalAlignment = new Object();
SiteRecruit_Constants.horizontalAlignment.left = 0;
SiteRecruit_Constants.horizontalAlignment.middle = 1;
SiteRecruit_Constants.horizontalAlignment.right = 2;
SiteRecruit_Constants.verticalAlignment = new Object();
SiteRecruit_Constants.verticalAlignment.top = 0;
SiteRecruit_Constants.verticalAlignment.middle = 1;
SiteRecruit_Constants.verticalAlignment.bottom = 2;

// Survey cookie configuration.
SiteRecruit_Config.cookieName = 'msresearch';
SiteRecruit_Config.cookieDomain = '.microsoft.com';
SiteRecruit_Config.cookiePath = '/';

SiteRecruit_Constants.cookieJoinChar = ':';

// Settings for cookie lifetime.
SiteRecruit_Config.cookieLifetimeType = 1;

    // Duration of the cookie in days.
    SiteRecruit_Config.cookieDuration = 90 * 86400000;

// Duration of the rapid cookie.
SiteRecruit_Config.rapidCookieDuration = 0 * 86400000;

// URL of the email domain dep server.
SiteRecruit_Config.listenerUrl = '';// //
// Copyright 2007 comScore Networks. All rights reserved.

// KeepAlive class definition.
function SiteRecruit_KeepAlive()
{
    // Time between page checks.
    this.keepAlivePollDelay = 1000;

    // Unique (well, sorta) ID for this page.
    this.id = Math.random();

    // Attach methods.
    this.attemptStart = KeepAlive_attemptStart;
    this.checkCookie = KeepAlive_checkCookie;
    this.inProgressCookieExists = KeepAlive_inProgressCookieExists;
    this.cookieExists = KeepAlive_cookieExists;

    // Check for either domain dep or email domain dep cookies and act accordingly.
    function KeepAlive_attemptStart()
    {
        if (this.inProgressCookieExists())
        {
            setInterval('SiteRecruit_Globals.keepAlive.checkCookie()', this.keepAlivePollDelay);
        }
        else
        {
            if (this.cookieExists(SiteRecruit_Constants.cookieType.emailDomainDeparture))
            {
                var c = document.cookie.toString();
                var index = c.indexOf(SiteRecruit_Config.cookieName + '=' + SiteRecruit_Constants.cookieType.emailDomainDeparture);
                var endc = c.length;
                c = c.substring(index, endc);
                var ind1 = c.indexOf(';');
                if (ind1 != -1) c = c.substring(0, ind1);        
                var ind2 = c.indexOf('=');
                c = c.substring(ind2 + 1);
                var values = c.split(':');
                if (values.length == 2)
                {
                    var url = SiteRecruit_Config.listenerUrl;
                    
                    // append ? to qs if needed
					url += (url.indexOf('?') == -1 ? '?' : '&');
					
                    url += 'action=log'
                        + '&user=' + values[1]
                        + '&location=' + escape(window.location);
                    
                    setTimeout("var i = new Image(); i.src = '" + url + "&' + (new Date()).getTime(); ", 5);
                }
            }
        }
    }
    
    // Check and update the cookie.
    function KeepAlive_checkCookie()
    {
        if (this.inProgressCookieExists())
        {
            var c = SiteRecruit_Config.cookieName + '=' + SiteRecruit_Constants.cookieType.inProgress
                + ':' + escape(document.location)
                + ':' + (new Date()).getTime()
                + ':' + this.id
                + '; path=' + SiteRecruit_Config.cookiePath;
            
            if (SiteRecruit_Config.cookieDomain != '')
            {
                c += '; domain=' + SiteRecruit_Config.cookieDomain;
            }
            
            document.cookie = c;
        }
    }

    // Return true if an in-progress cookie exists.
    function KeepAlive_inProgressCookieExists()
    {
        return this.cookieExists(SiteRecruit_Constants.cookieType.inProgress);
    }
    
    // Return true if a cookie of the given type exists.
    function KeepAlive_cookieExists(cookieType)
    {
        var c = SiteRecruit_Config.cookieName + '=' + cookieType;
        if (document.cookie.indexOf(c) != -1)
        {
            return true;
        }
        return false;
    }
}

// Create the KeepAlive if a suitable cookie exists.
SiteRecruit_Globals.keepAlive = new SiteRecruit_KeepAlive();
SiteRecruit_Globals.keepAlive.attemptStart();
// //
// Copyright 2007 comScore Networks. All rights reserved.

// Broker class definition.
function SiteRecruit_PageConfigurationBroker()
{
    // List of mappings, each contains [url, page, priority, prereqs]    
    this.m = [        
    ['//[\\w\\.-]+/en-us', '/msdn/Controls/MTPS_SurveyLauncherCtrl/en-us/SiteRecruit_PageConfiguration_p15808382mt-3332mt.js', 0, null],
    ['//[\\w\\.-]+/en-ca', '/msdn/Controls/MTPS_SurveyLauncherCtrl/en-us/SiteRecruit_PageConfiguration_p15808382-en-ca.js', 0, null],
    ['//[\\w\\.-]+/en-gb', '/msdn/Controls/MTPS_SurveyLauncherCtrl/en-us/SiteRecruit_PageConfiguration_p15808382mt-en-gb.js', 1, null],
    ['//[\\w\\.-]+/en-us/practices(/|$)', '/msdn/Controls/MTPS_SurveyLauncherCtrl/en-us/SiteRecruit_PageConfiguration_P-2692mt-3332mt-p15808382mt.js', 1, null],
    ['//[\\w\\.-]+/fr-ca...', '/msdn/Controls/MTPS_SurveyLauncherCtrl/en-us/SiteRecruit_PageConfiguration_p15808382mt-fr-ca.js', 0, null],
    ['//[\\w\\.-]+/fr-fr', '/msdn/Controls/MTPS_SurveyLauncherCtrl/en-us/SiteRecruit_PageConfiguration_France-p12038685.js', 0, null],
    ];
    
    // Attach methods.
    this.start = PageConfigurationBroker_start;
    this.getConfigurationForPage = PageConfigurationBroker_getConfigurationForPage;
    this.loadConfiguration = PageConfigurationBroker_loadConfiguration;

    // Start the Broker.
    function PageConfigurationBroker_start(url)
    {        
        // Decide if there are surveys to run for this page.
        var configuration = this.getConfigurationForPage(url);
        
        // If there is, load id up.
        if (configuration != null)
        {
            this.loadConfiguration(configuration);
        }
    }
    
    // Return the appropriate configuration for the given URL, if any.
    function PageConfigurationBroker_getConfigurationForPage(url)
    {
        
        var currentScore = 0;
        var currentMatch = -1;
        
        // Iterate over each URL.
        for (var i = 0; i < this.m.length; i++)
        {
            if (this.m[i] != null)
            {
                // Do the reg exp match.
                var r = new RegExp(this.m[i][0], 'i');
                if (url.toString().search(r) != -1)
                {
                    var prereqs = this.m[i][3];
                    var matchPrereqs = true;
                    
                    // Now check the prereqs.
                    if (prereqs != null)
                    {
                        for (var j = 0; j < prereqs.length; j++)
                        {
                            var p = prereqs[j];
                            if (p != null)
                            {
                                if (p.elementType)
                                {
                                    var matchContent = false;
                                    var matchAttribute = false;
                                    
                                    var elements = document.getElementsByTagName(p.elementType);
                                    for (var k = 0; k < elements.length; k++)
                                    {
                                        if (p.contentValue != '')
                                        {
                                            if (elements[k].innerHTML.search(p.contentValue) != -1)
                                            {
                                                matchContent = true;
                                            }
                                        }
                                        else
                                        {
                                            matchContent = true;
                                        }
                                        
                                        if (p.attributeName != '')
                                        {
                                            var a = elements[k].attributes.getNamedItem(p.attributeName);
                                            if (a != null)
                                            {
                                                if (p.attributeValue != '')
                                                {
                                                    if (a.value.search(p.attributeValue) != -1)
                                                    {
                                                        matchAttribute = true;
                                                    }
                                                }
                                                else
                                                {
                                                    matchAttribute = true;
                                                }
                                             }
                                        }
                                        else
                                        {
                                            matchAttribute = true;
                                        }
                                    }
                                    
                                    if (!matchContent || !matchAttribute)
                                    {
                                        matchPrereqs = false;
                                        break;
                                    }
                                }
                                else if (p.cookieName)
                                {
                                    var cookieTemplate = p.cookieName + '=';
                                    if (p.cookieValue)
                                    {
                                        cookieTemplate += p.cookieValue;
                                    }
                                    if (document.cookie.indexOf(cookieTemplate) == -1)
                                    {
                                        matchPrereqs = false;
                                        break;
                                    }
                                }
                                else if (p.language)
                                {
                                    if (navigator.language && navigator.language.toString().toLowerCase().indexOf(p.language) == -1)
                                    {
                                        matchPrereqs = false;
                                        break;
                                    }
                                    else if (navigator.userLanguage && navigator.userLanguage.toString().toLowerCase().indexOf(p.language) == -1)
                                    {
                                        matchPrereqs = false;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        matchPrereqs = true;
                    }
                    
                    if (matchPrereqs)
                    {
                        // Take the current if the score is equal or better.
                        var newScore = this.m[i][2];
                        if (newScore >= currentScore)
                        {
                            currentMatch = i;
                            currentScore = newScore;
                        }
                    }
                }
            }
        }
        
        // If there was a match, return the appropriate page configuration.
        var page = null;
        if (currentMatch >= 0)
        {
            page = this.m[currentMatch][1];
        }
        
                
        return page;
    }
    
    // Dynamically loads the associated configuration.
    function PageConfigurationBroker_loadConfiguration(configuration)
    {
                
        document.write('<script language="JavaScript" src="' + configuration + '"></script>');
    }
}

try
{
    // Only run if the browser is supported.
    if (SiteRecruit_Globals.isInternetExplorer || SiteRecruit_Globals.isMozilla)
    {
        // Create and start the Broker for the current location.
        SiteRecruit_Globals.broker = new SiteRecruit_PageConfigurationBroker();
        SiteRecruit_Globals.broker.start(window.location);
    }
}
catch (e)
{
    // Suppress any errors.
}

SiteRecruit_Globals.parseFlag = true;

// Multiple script protection.
}