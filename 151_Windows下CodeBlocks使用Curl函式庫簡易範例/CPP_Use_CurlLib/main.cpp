#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
using namespace std;

int main(int argc, char *argv[])
{
  char POST[255] = "" ;
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();

  //sprintf(POST,"ei=UTF-8&p=%s",argv[1]);

  curl_easy_setopt(curl, CURLOPT_URL, "http://phpruntime.byethost5.com/index.php");
  //curl_easy_setopt(curl, CURLOPT_POSTFIELDS, POST);
  res = curl_easy_perform(curl);

  curl_easy_cleanup(curl);
    //cout << "Hello world!" << endl;
    return 0;
}
