function google_ad_request_done(google_ads) {
	var s = '<div class="col-body"><h3 style="text-align:center">Google Adsense</h3><table width=90% border="0" cellspacing="0" cellpadding="6"><tr>';
	var i;
	if (google_ads.length == 0) {
		return;
	}

	if (google_ads[0].type="text") {
		for(i=0; i < google_ads.length; i++) {
			s += '<td valign="top" width="33%"><span class="entry-title"><B><a href="' + google_ads[i].url + '" target=_blank ' +
			'onmouseout="window.status=\'\';return true;" ' + 'onmouseover="window.status=\'go to ' +
			google_ads[i].visible_url + '\';return true;">' + google_ads[i].line1 + '</a></B></span><br>\n\n' +
			'<a href="' + google_ads[i].url + '" target=_blank style="text-decoration:none;" ' +
			'onmouseout="window.status=\'\';return true;" onmouseover="window.status=\'go to ' +
			google_ads[i].visible_url + '\';return true;"><span id="trackback">' + google_ads[i].line2 + '&nbsp;' + 
			google_ads[i].line3 + '</span></a>\n\n' +
			'<p><span><a href="' + google_ads[i].url + '" target=_blank ' +
			'onmouseout="window.status=\'\';return true;" onmouseover="window.status=\'go to ' +
			google_ads[i].visible_url + '\';return true;">' + google_ads[i].visible_url + '</a></span></p></td>\n\n';
		}
	}
	s +='</tr></table></div>';
	document.write(s);
	return;
}

google_ad_client = 'ca-bokee_js';
google_ad_output = 'js';
google_max_num_ads = '3';
google_language = 'zh-CN';
google_encoding = 'gb2312';
google_safe = 'medium';
google_adtest = 'off';
google_ad_section = 'default';
google_gl = 'CN';
google_ad_channel = 'bokee-oldblog';
