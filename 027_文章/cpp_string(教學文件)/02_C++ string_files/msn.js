/*
	[Discuz!] (C)2001-2007 Comsenz Inc.
	This is NOT a freeware, use is subject to license terms

	$RCSfile: msn.js,v $
	$Revision: 1.4 $
	$Date: 2007/03/21 15:57:53 $
*/

function msnoperate(action, msn) {
	var actionArray = new Array();
	actionArray = {
                'reghotmail' : 'http://www.hotmail.com',
                'reglivemail' : 'http://mail.live.com',
                'regliveid' : 'http://www.passport.net',
                'download' : 'http://messenger.live.com',
                'add' : 'msnim:add?contact=' + msn,
                'chat' : 'msnim:chat?contact=' + msn
	}

	if(messengerInstalled()) {
		window.open(actionArray[action]);
	} else {
		window.open('http://get.live.com/messenger/overview','_blank');
	}
}

function messengerInstalled() {
      try {
            new ActiveXObject("MSNMessenger.P4QuickLaunch");
            return true;
      }
      catch (e) {
            return false;
      }
}