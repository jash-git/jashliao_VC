#include <cstdlib>
#include <iostream>
#include <fstream>//純c++
#include <cstdio>//純c 
using namespace std;

int main(int argc, char *argv[])
{
    char C_chrinputdata[100]="a c_string",C_chroutputdata[100];
    FILE *pf;
    pf=fopen("c.txt","w");
    fprintf(pf,"%s\n",C_chrinputdata);
    fclose(pf);
    pf=fopen("c.txt","r");
    fgets(C_chroutputdata,100,pf);
    printf("取出輸入字串%s\n",C_chroutputdata);
    fclose(pf);
    ////////////////////////////////////////////////////////////
    char Cpp_chrinputdata[100]="a cpp_string",Cpp_chroutputdata[100];
    fstream fp;
    fp.open("cpp.txt",ios::out|ios::trunc);
    fp<<Cpp_chrinputdata;
    fp.close();
    fp.open("cpp.txt",ios::in);
    fp.getline(Cpp_chroutputdata,100);
    cout<<"取出輸入字串"<<Cpp_chroutputdata<<"\n";
    fp.close(); 
    system("PAUSE");
    return EXIT_SUCCESS;
}
