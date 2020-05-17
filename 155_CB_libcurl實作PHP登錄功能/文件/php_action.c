//C++ libcurl CURLOPT_COOKIEJAR CURLOPT_COOKIEFILE
//http://zhidao.baidu.com/question/359106654.html
//http://blog.csdn.net/wslz2001/article/details/8952890
#include  < stdio.h > 
#include  < string .h > 
#include  < curl / curl.h > 
#include  < curl / types.h > 
#include  < curl / easy.h > 
   
int  main( int  argc,  char   * argv[])
{
	CURL  * curl;
	CURLcode res;
  
	struct  curl_slist  * headerlist = NULL;
	static   const   char  buf[]  =   " Expect: " ;
   
	curl_global_init(CURL_GLOBAL_ALL);
	curl  =  curl_easy_init();
	headerlist  =  curl_slist_append(headerlist, buf);
   
	if (curl) 
	{
		curl_easy_setopt(curl, CURLOPT_URL,  " https://passport.baidu.com/?login " );
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
   
		curl_easy_setopt(curl,CURLOPT_POSTFIELDS, " username=ea99&password=&psp_tt=0&safeflg=0&return_method=get&u=http://hi.baidu.com/s%5Fyqguo " ); // 设置帐号密码，其余的信息是页面要求的，抓包即可看见。 
   
		curl_easy_setopt(curl,CURLOPT_COOKIEFILE, " cookie_open.txt " ); // 提交第一步保存的cookie 
		curl_easy_setopt(curl,CURLOPT_COOKIEJAR, " cookie_login.txt " ); // 保存登陆后的cookie 
		
		#ifdef SKIP_PEER_VERIFICATION
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER,  0L );
		#endif 
   
		#ifdef SKIP_HOSTNAME_VERFICATION
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST,  0L );
		#endif 
   
		res  =  curl_easy_perform(curl);
		
		/**/ /*  always cleanup  */ 
		curl_easy_cleanup(curl);
        /**/ /*  free slist  */ 
		curl_slist_free_all(headerlist);
	} 
	return   0 ;
 }