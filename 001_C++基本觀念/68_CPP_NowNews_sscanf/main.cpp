#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
using namespace std;
char chrFileName[200],chrPath[200];
char chrFileExt[20];
void GetFileName(char *data);
int main()
{
	fstream a;
	char fg[700];
	char chrd1[100],chrd2[100],chrd3[100],chrd4[100],chrd5[100],chrd6[100],chrd7[100],chrd8[100];
	a.open("123.txt",ios::in);
	while(!a.eof())
	{
        a.getline(fg,700);
        sscanf (fg ,"%[^ || ] || %s || %s %s || %s || %s || %s || %s ",chrd1,chrd2,chrd3,chrd4,chrd5,chrd6,chrd7,chrd8);
        cout<<chrd6<<"\n";
        GetFileName(chrd6);
        cout<<chrPath<<"\n";
        cout<<chrFileName<<"\n";
        cout<<chrFileExt<<"\n";
	}
    return 0;
}
void GetFileName(char *data)
{
    chrPath[0]='\0';
    chrFileName[0]='\0';
    chrFileExt[0]='\0';
    int i,intcount;
    int j=0;
    int k=0;
    char d;
    intcount=strlen(data);
    for(i=(intcount-1);i>=0;i--)
    {
        if((data[i]!='/')&&(data[i]!='\\'))
        {
            d=data[i];
            chrPath[j]=d;
            j++;
        }
        else
        {
            break;
        }
    }
    chrPath[j]='\0';
    for(int i=0;i<j;i++)
    {
        if(i<(j-4))
        {
            chrFileName[i]=chrPath[j-i-1];
            chrFileName[i+1]='\0';
        }
        else
        {
            chrFileExt[k]=chrPath[j-i-1];
            k++;
            chrFileExt[k]='\0';
        }
    }
    chrPath[0]='\0';
    for(i=0;i<(intcount-j);i++)
    {
        chrPath[i]=data[i];
    }
    chrPath[(intcount-j)]='\0';
    //cout<<chrPath<<"\n";
    //cout<<chrFileName<<"\n";
}
