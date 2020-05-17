//C++ libcurl CURLOPT_COOKIEJAR CURLOPT_COOKIEFILE
//http://zhidao.baidu.com/question/359106654.html
//http://blog.csdn.net/wslz2001/article/details/8952890
//http://www.cnblogs.com/moodlxs/archive/2012/10/15/2724318.html
#include  <stdio.h>
#include  <string.h>
#include  <curl/curl.h>
//#include  <curl/types.h>
#include  <curl/easy.h>
#include <stdlib.h>

int main()
{
	CURL  * curl;
	CURLcode res;

	struct  curl_slist  * headerlist = NULL;
	static   const   char  buf[]  =   " Expect: " ;
	static   const   char  postdata[]="username=jash&password=1234";

	curl_global_init(CURL_GLOBAL_ALL);

	curl  =  curl_easy_init();
	headerlist  =  curl_slist_append(headerlist, buf);

	if (curl)
    {
		curl_easy_setopt(curl,CURLOPT_URL,  "http://127.0.0.1:8080/cs2php/login.php" );
		curl_easy_setopt(curl,CURLOPT_HTTPHEADER, headerlist);
		curl_easy_setopt(curl,CURLOPT_COOKIEJAR, "cookie_open.txt" ); // 把服务器发过来的cookie保存到cookie_open.txt
        curl_easy_setopt(curl,CURLOPT_POSTFIELDS, postdata);
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

	//--
    FILE *fp;
    if ((fp = fopen("data.json", "w")) == NULL)
        return 0;

	CURL  * curl1;
	CURLcode res1;

	struct  curl_slist  * headerlist1 = NULL;

	curl1  =  curl_easy_init();
	headerlist1  =  curl_slist_append(headerlist1, buf);

	if (curl1)
    {
		curl_easy_setopt(curl1,CURLOPT_URL, "http://127.0.0.1:8080/cs2php/outjson.php" );
		curl_easy_setopt(curl1,CURLOPT_HTTPHEADER, headerlist1);
		curl_easy_setopt(curl1,CURLOPT_COOKIEFILE, "cookie_open.txt" ); // 提交第一步保存的cookie
		curl_easy_setopt(curl1,CURLOPT_COOKIEJAR, "cookie_open.txt" ); // 保存登陆后的cookie
        curl_easy_setopt(curl1,CURLOPT_WRITEDATA, fp);

		#ifdef SKIP_PEER_VERIFICATION
			curl_easy_setopt(curl1, CURLOPT_SSL_VERIFYPEER,  0L );
		#endif

		#ifdef SKIP_HOSTNAME_VERFICATION
			curl_easy_setopt(curl1, CURLOPT_SSL_VERIFYHOST,  0L );
		#endif

		res1  =  curl_easy_perform(curl1);

		/**/ /*  always cleanup  */
		curl_easy_cleanup(curl1);

		/**/ /*  free slist  */
		curl_slist_free_all(headerlist1);
	}
	fclose(fp);
    return 0;
}
