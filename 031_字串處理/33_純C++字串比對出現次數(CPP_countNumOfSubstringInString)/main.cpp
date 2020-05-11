#include <iostream>
#include <string>
using namespace std;

//計算字串str中某字串substring出現的次數
int countNumOfSubstringInString(string substring,string str)
{
 int startIndex=-1;
 int endStartIndex = -1;
 int num=0;
 endStartIndex = str.find(substring);
 while (endStartIndex!=string::npos)
 {
  num++;
  startIndex = endStartIndex + substring.length();
  endStartIndex = str.find(substring,startIndex);
  
 }
 return num; 
}

int main(void)
{
	string strData="my my your your 123456789";
	string strsub="y";
	cout<<"strData= "<<strData<<endl;
	cout<<"strsub= "<<strsub<<endl;
	cout<<"countNumOfSubstringInString= "<<countNumOfSubstringInString(strsub,strData)<<endl;
}