#include <iostream>
#include "Parse.h"
using namespace std;



void parsePost (const char* post)
{
  string s_post (post);
  Parse p (s_post);
  p.parse();

  //return value by key
  cout << p.ValueByKey ("userid") << endl; //1
  cout << p.ValueByKey ("password") << endl; //guessme
}

void parseGet (const char* get)
{
  string s_get (get);
  Parse p (s_get);
  p.parse();

  cout << p.ValueByKey ("password") << endl; //1
  cout << p.ValueByKey ("userid") << endl; //joe
}

int main ()
{
  const char* post = "POST /login.jsp HTTP/1.1\nHost: www.mysite.com\nUser-Agent: Mozilla/4.0\nContent-Length: 27\nContent-Type: application/x-www-form-urlencoded\n\nuserid=1&password=guessme";

  const char* get = "GET /index.html?userid=joe&password=1 HTTP/1.1\nHost: www.mysite.com\nUser-Agent: Mozilla/4.0";

  parseGet (post);
  return 0;
}
