// number2English.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

void main()
{
        ifstream data("d.txt");
        int str;
        data >> str;
        cout << str << endl;
        int temp[100]={NULL};
        cout << "Ans=";

        for(int i=1;i<=9;i++) 
        {
                if(str!=0)        
                {
                        temp[i]=str%10;  
                        str=int(str)/10; 
                }        
                if(i==9)             
                {                
                        if(temp[9]==1)    
                                cout << "one hundred ";
                        else if(temp[9]==2)
                                cout << "two hundred " ;
                        else if(temp[9]==3)
                                cout << "three hundred ";
                        else if(temp[9]==4)
                                cout << "four hundred ";
                        else if(temp[9]==5)
                                cout << "five hundred ";
                        else if(temp[9]==6)
                                cout << "six hundred ";
                        else if(temp[9]==7)
                                cout << "seven hundred ";
                        else if(temp[9]==8)
                                cout << "eight hundred ";
                        else if(temp[9]==9)
                                cout << "nine hundred ";

                        if(temp[8]==1 && temp[7]==0 )
                                cout << "ten";
                        else if(temp[8]==1 && temp[7]==1)
                                cout << "eleven";
                        else if(temp[8]==1 && temp[7]==2)
                                cout << "twelve";
                        else if(temp[8]==1 && temp[7]==3)
                                cout << "thirteen";
                        else if(temp[8]==1 && temp[7]==4)
                                cout << "fourteen";
                        else if(temp[8]==1 && temp[7]==5)
                                cout << "fifteen";
                        else if(temp[8]==1 && temp[7]==6)
                                cout << "sixteen";
                        else if(temp[8]==1 && temp[7]==7)
                                cout << "sevevteen";
                        else if(temp[8]==1 && temp[7]==8)
                                cout << "eighteen";
                        else if(temp[8]==1 && temp[7]==9)
                                cout << "nineteen";
                        else if(temp[8]==2)
                                cout << "twenty";
                        else if(temp[8]==3)
                                cout << "thirty";
                        else if(temp[8]==4)
                                cout << "forty";
                        else if(temp[8]==5)
                                cout << "fifty";
                        else if(temp[8]==6)
                                cout << "sixty";
                        else if(temp[8]==7)
                                cout << "seventy";
                        else if(temp[8]==8)
                                cout << "eighty";
                        else if(temp[8]==9)
                                cout << "ninety";

                        if(temp[8]>1 && temp[7]!=0)
                                cout << "-";

                        if(temp[8]!=1)
                        {
                                if(temp[7]==1)
                                        cout << "one";
                                else if(temp[7]==2)
                                        cout << "two";
                                else if(temp[7]==3)
                                        cout << "three";
                                else if(temp[7]==4)
                                        cout << "four";
                                else if(temp[7]==5)
                                        cout << "five";
                                else if(temp[7]==6)
                                        cout << "six";
                                else if(temp[7]==7)
                                        cout << "seven";
                                else if(temp[7]==8)
                                        cout << "eight";
                                else if(temp[7]==9)
                                        cout << "nine";
                        }

                        if(temp[8]!=0 || temp[7]!=0) 
                                cout << " million ";
                        else if(temp[9]!=0 && temp[8]==0 && temp[7]==0)
                                cout << "million "; 
                        
                        if(temp[6]==1)
                                cout << "one hundred ";
                        else if(temp[6]==2)
                                cout << "two hundred " ;
                        else if(temp[6]==3)
                                cout << "three hundred ";
                        else if(temp[6]==4)
                                cout << "four hundred ";
                        else if(temp[6]==5)
                                cout << "five hundred ";
                        else if(temp[6]==6)
                                cout << "six hundred ";
                        else if(temp[6]==7)
                                cout << "seven hundred ";
                        else if(temp[6]==8)
                                cout << "eight hundred ";
                        else if(temp[6]==9)
                                cout << "nine hundred ";

                        if(temp[5]==1 && temp[4]==0)
                                cout << "ten";
                        else if(temp[5]==1 && temp[4]==1)
                                cout << "eleven";
                        else if(temp[5]==1 && temp[4]==2)
                                cout << "twelve";
                        else if(temp[5]==1 && temp[4]==3)
                                cout << "thirteen";
                        else if(temp[5]==1 && temp[4]==4)
                                cout << "fourteen";
                        else if(temp[5]==1 && temp[4]==5)
                                cout << "fifteen";
                        else if(temp[5]==1 && temp[4]==6)
                                cout << "sixteen";
                        else if(temp[5]==1 && temp[4]==7)
                                cout << "sevevteen";
                        else if(temp[5]==1 && temp[4]==8)
                                cout << "eighteen";
                        else if(temp[5]==1 && temp[4]==9)
                                cout << "nineteen";
                        else if(temp[5]==2)
                                cout << "twenty";
                        else if(temp[5]==3)
                                cout << "thirty";
                        else if(temp[5]==4)
                                cout << "forty";
                        else if(temp[5]==5)
                                cout << "fifty";
                        else if(temp[5]==6)
                                cout << "sixty";
                        else if(temp[5]==7)
                                cout << "seventy";
                        else if(temp[5]==8)
                                cout << "eighty";
                        else if(temp[5]==9)
                                cout << "ninety";

                        if(temp[5]>1 && temp[4]!=0)
                                cout << "-";

                        if(temp[5]!=1)
                        {
                                if(temp[4]==1)
                                        cout << "one";
                                else if(temp[4]==2)
                                        cout << "two";
                                else if(temp[4]==3)
                                        cout << "three";
                                else if(temp[4]==4)
                                        cout << "four";
                                else if(temp[4]==5)
                                        cout << "five";
                                else if(temp[4]==6)
                                        cout << "six";
                                else if(temp[4]==7)
                                        cout << "seven";
                                else if(temp[4]==8)
                                        cout << "eight";
                                else if(temp[4]==9)
                                        cout << "nine";
                        }

                        if(temp[5]!=0 || temp[4]!=0)
                                cout << " thousand ";
                        else if(temp[6]!=0 && temp[5]==0 && temp[4]==0)
                                cout << "thousand ";

                        if(temp[3]==1)
                                cout << "one";
                        else if(temp[3]==2)
                                cout << "two";
                        else if(temp[3]==3)
                                cout << "three";
                        else if(temp[3]==4)
                                cout << "four";
                        else if(temp[3]==5)
                                cout << "five";
                        else if(temp[3]==6)
                                cout << "six";
                        else if(temp[3]==7)
                                cout << "seven";
                        else if(temp[3]==8)
                                cout << "eight";
                        else if(temp[3]==9)
                                cout << "nine";

                        if(temp[3]!=0)
                                cout << " hundred ";

                        if(temp[2]==1 && temp[1]==0)
                                cout << "ten";
                        else if(temp[2]==1 && temp[1]==1)
                                cout << "eleven";
                        else if(temp[2]==1 && temp[1]==2)
                                cout << "twelve";
                        else if(temp[2]==1 && temp[1]==3)
                                cout << "thirteen";
                        else if(temp[2]==1 && temp[1]==4)
                                cout << "fourteen";
                        else if(temp[2]==1 && temp[1]==5)
                                cout << "fifteen";
                        else if(temp[2]==1 && temp[1]==6)
                                cout << "sixteen";
                        else if(temp[2]==1 && temp[1]==7)
                                cout << "sevevteen";
                        else if(temp[2]==1 && temp[1]==8)
                                cout << "eighteen";
                        else if(temp[2]==1 && temp[1]==9)
                                cout << "nineteen";
                        else if(temp[2]==2)
                                cout << "twenty";
                        else if(temp[2]==3)
                                cout << "thirty";
                        else if(temp[2]==4)
                                cout << "forty";
                        else if(temp[2]==5)
                                cout << "fifty";
                        else if(temp[2]==6)
                                cout << "sixty";
                        else if(temp[2]==7)
                                cout << "seventy";
                        else if(temp[2]==8)
                                cout << "eighty";
                        else if(temp[2]==9)
                                cout << "ninety";

                        if(temp[2]>1 && temp[1]!=0)
                                cout << "-";

                        if(temp[2]!=1)
                        {
                                if(temp[1]==1)
                                        cout << "one";
                                else if(temp[1]==2)
                                        cout << "two";
                                else if(temp[1]==3)
                                        cout << "three";
                                else if(temp[1]==4)
                                        cout << "four";
                                else if(temp[1]==5)
                                        cout << "five";
                                else if(temp[1]==6)
                                        cout << "six";
                                else if(temp[1]==7)
                                        cout << "seven";
                                else if(temp[1]==8)
                                        cout << "eight";
                                else if(temp[1]==9)
                                        cout << "nine";
                        }
                }
        }
        cout << endl;
}

