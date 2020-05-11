#include "Parse.h"

/*public*/
Parse::Parse (string query)
{ 
  this->split (this->_query,query,'\n');
}

void Parse::parse ()
{
  try 
  {
    char symbol = whatIsIt();
    if (symbol == POST)
    {
      this->parsePost();
    }
    else if (symbol == GET)
    {
      this->parseGet(); 
    }
  }
  catch (const char* a)
  {
    cerr << a << endl;
  }
}

string Parse::ValueByKey (string key) const
{
  map<string,string> all;
  map<string,string>::const_iterator it;

  all.insert (this->_attributes.begin(),this->_attributes.end());
  all.insert (this->_head.begin(),this->_head.end());
  all.insert (this->_variables.begin(),this->_variables.end());

  it = all.find(key);
  if (it != all.end())
  {
    return it->second;
  }
  
  else return FAIL_MESSAGE;
}

/*private*/
void Parse::split (vector<string>& tmp,string query,char delimiter)
{
  std::stringstream ss(query);
  std::string item;
  while (std::getline(ss, item, delimiter)) {
        if (query[0] != '\n') {
          tmp.push_back(item);
        }
  }
}

/*return P if this POST request else if this GET request return G*/
char Parse::whatIsIt () const
{
  if (this->_query[0][0] == GET)
  {
    return GET; 
  }
  else if (this->_query[0][0] == POST)
  {
    return POST;
  }
  else
  {
    throw "ABORT : NO POST NO GET.";
  }
}

void Parse::parsePost ()
{
  for (unsigned int i = 0; i < this->_query.size(); ++i)
  {
    if (i == 0)
    {
      //parse head post's query
    }
    else if (i > 0 && i < this->_query.size()-1)
    {
      //parse attributes post's query
      /*this->_query[i].erase(std::remove(this->_query[i].begin(), this->_query[i].end(), ' '), this->_query[i].end());*/
    }
    else
    {
      vector<string> step;
      this->split (step,this->_query[i],'&');
      for (unsigned int i = 0; i < step.size(); ++i)
      {
        vector<string> data;
        this->split (data,step[i],'=');
	if (data.size() > 2)
	{
	  data.erase(data.begin()+2,data.end());
	}
	if (data.size() == 2)
	{
          this->setMap (this->_variables,data);
	}
      }
    }
  }
}

void Parse::parseGet ()
{
  for (unsigned int i = 0; i < this->_query.size(); ++i)
  {
    if (i == 0)
    {
      vector<string> step1;
      this->split(step1,this->_query[i],' ');
      vector<string> step2;
      this->split (step2,step1[1],'?');
      vector<string> step3;
      this->split (step3,step2[1],'&');
      for (unsigned int i = 0; i < step3.size(); i++)
      {
        vector<string> data;
        this->split (data,step3[i],'=');
	if (data.size() > 2)
	{
	  data.erase(data.begin()+2,data.end());
	}
	if (data.size() == 2)
	{
          this->setMap (this->_variables,data);
        }
      }
    }
    else
    {
      //parse attribute get's query
      /*this->_query[i].erase(std::remove(this->_query[i].begin(), this->_query[i].end(), ' '), this->_query[i].end());*/
    }
  }      
}

void Parse::setMap (map<string,string>& sMap,vector<string> a)
{
  for (unsigned int i = 0; i < a.size(); i+=2)
  {
    sMap[a[i]] = a[i+1];
  }
}
