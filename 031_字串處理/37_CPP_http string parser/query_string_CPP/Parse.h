/*class Parse parsing http query */
#ifndef _PARSE_
#define _PARSE_

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <string.h>
#include <algorithm>

#define POST 'P'
#define GET 'G'

#define FAIL_MESSAGE "Fail"
#define FAIL_SPLIT "Error in split function : "

using namespace std;

class Parse {
public:
  Parse (string s);
  
public:
  void parse ();

public:
  string ValueByKey (string) const;

private:
  char whatIsIt () const; //post or get or some else
  void split (vector<string>&,string,char);
  void setMap (map<string,string>&,vector<string>);

  void parseGet();
  void parsePost();

private:
  vector<string> _query;

  map<string,string> _head; //head in query, example (GET /index.php?x=y&x1=y1 HTTP1.1)
  map<string,string> _variables; //variables in query (x=y&x1=y1...)
  map<string,string> _attributes; //attributes in query (Host : ...\nUser-Agent : ...\n)
};

#endif
