#include <iostream>
#include <cstdio>
using namespace std;
# define CPP_mode 0
int main()
{
    int intvalue;//�ŧi�@���ܼ�
    intvalue=0;//�ܼƪ�l��
    #if (CPP_mode)
        cout<<"CPP mode:\n";
        cout<<"�п�J�@�Ӿ��:\t";
        cin >>intvalue;
        cout<<"�z��J����Ƭ��G"<<intvalue<<" �Ӿ�ƥ[ 7�� "<<(intvalue+7)<<endl;
    #else
        printf("C mode:\n");
        printf("�п�J�@�Ӿ��:\t");
        scanf("%d",&intvalue);
        printf("�z��J����Ƭ��G%d �Ӿ�ƥ[ 7�� %d",intvalue,(intvalue+7));
    #endif


    return 0;
}
