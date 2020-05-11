#include <iostream>
#include <cstdio>
#include <cstdlib>/* malloc, free, rand */

using namespace std;

void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main()
{
    //---
    //C字串範例
    char* s1 = "Hello SYSU!"; //创建指针指向字符串常量，这段字符串我们是不能修改的
    printf("s1=%s\n",s1);
    //想要创建 可以修改的字符串，我们可以使用数组分配空间
    char s2[20] = "Hello SYSU!";
    printf("s2=%s\n",s2);
    //或者这样
    char s3[] = "Hello SYSU!";
    printf("s3=%s\n",s3);
    //当然我们也可以动态分配内存
    char* s4 = (char*)malloc(20);
    gets(s4);//接收輸入字串
    printf("s4=%s\n",s4);
    free(s4);
    //---C字串範例

    Pause();
    return 0;
}
