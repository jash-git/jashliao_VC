#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
char * create1()
{
     cJSON *root,*dir1,*dir2,*dir3;
     char *out;
     //創建json陣列型結構體
     root = cJSON_CreateArray();
     //為陣列添加物件
     cJSON_AddItemToArray(root,dir1=cJSON_CreateObject());
     //為物件添加字串鍵值對
     cJSON_AddStringToObject(dir1,"name",".");
     cJSON_AddStringToObject(dir1,"path","uploads/");
     cJSON_AddStringToObject(dir1,"flag","true");
     cJSON_AddItemToArray(root,dir2=cJSON_CreateObject());
     cJSON_AddStringToObject(dir2,"name","..");
     cJSON_AddStringToObject(dir2,"path","uploads");
     cJSON_AddStringToObject(dir2,"flag","true");
     cJSON_AddItemToArray(root,dir3=cJSON_CreateObject());
     cJSON_AddStringToObject(dir3,"name","wang.txt");
     cJSON_AddStringToObject(dir3,"path","uploads/wang.txt");
     cJSON_AddStringToObject(dir3,"flag","false");
     //將json結構體轉換為字串
     out=cJSON_Print(root);
     //刪除
     cJSON_Delete(root);
     return out;
}

char * create2()
{
     cJSON *root,*dir,*subdir,*dir1,*dir2,*dir3;
     char *out;
     root=cJSON_CreateObject();

     cJSON_AddItemToObject(root,"Root",dir=cJSON_CreateObject());
     cJSON_AddStringToObject(dir,"name","/");
     cJSON_AddStringToObject(dir,"path","/");
     cJSON_AddStringToObject(dir,"flag","true");

     cJSON_AddItemToObject(root,"Child",subdir = cJSON_CreateArray());
     cJSON_AddItemToObject(subdir,"dira",dir1=cJSON_CreateObject());
     cJSON_AddStringToObject(dir1,"name",".");
     cJSON_AddStringToObject(dir1,"path","/./");
     cJSON_AddStringToObject(dir1,"flag","true");
     cJSON_AddItemToObject(subdir,"dira",dir2=cJSON_CreateObject());
     cJSON_AddStringToObject(dir2,"name","..");
     cJSON_AddStringToObject(dir2,"path","/../");
     cJSON_AddStringToObject(dir2,"flag","true");
     cJSON_AddItemToObject(subdir,"dira",dir3=cJSON_CreateObject());
     cJSON_AddStringToObject(dir3,"name","uploads");
     cJSON_AddStringToObject(dir3,"path","/uploads/");
     cJSON_AddStringToObject(dir3,"flag","true");

     out=cJSON_Print(root);
     cJSON_Delete(root);
     return out;
}


char * create3()
{
     cJSON *root,*img,*thm;
     char *out;
     int nums[4]={100,200,300,400};
     root=cJSON_CreateObject();
     cJSON_AddItemToObject(root, "Root", img=cJSON_CreateObject());
     cJSON_AddNumberToObject(img,"key",800);
     cJSON_AddNumberToObject(img,"value",600);
     cJSON_AddStringToObject(img,"Title","Sugon");
     cJSON_AddItemToObject(img,"child",thm=cJSON_CreateObject());
     cJSON_AddNumberToObject(thm,"key",125);
     cJSON_AddStringToObject(thm,"value","100");
         cJSON_AddStringToObject(thm,"Url","www.sugon.com");
     cJSON_AddItemToObject(img,"nums", cJSON_CreateIntArray(nums,4));
     out=cJSON_Print(root);
     cJSON_Delete(root);
     return out;
}

char * create4()
{
     cJSON *root,*dir1,*dir2;
     char *out;
     const char *ro = "Root";
     root=cJSON_CreateObject();
     cJSON_AddItemToObject(root,ro,dir1=cJSON_CreateArray());
     cJSON_AddNumberToObject(dir1,"key",800);
     cJSON_AddNumberToObject(dir1,"value",600);
     cJSON_AddStringToObject(dir1,"Title","key and value");
     cJSON_AddItemToObject(root,ro,dir2=cJSON_CreateArray());
     cJSON_AddNumberToObject(dir2,"value",125);
     cJSON_AddStringToObject(dir2,"key","100");
     cJSON_AddStringToObject(dir2,"Title","value and key");
     out=cJSON_Print(root);
     cJSON_Delete(root);
     return out;
}

void parse1(char *out)
{
     cJSON * root,*arrayItem,*item,*name,*path,*flag;
     int i = 0,size = 0;
     char *pr = NULL,*na = NULL,*pa = NULL,*fl = NULL;

     //將字串解析成json結構體
     root = cJSON_Parse(out);
     //根據結構體獲取陣列大小
     size = cJSON_GetArraySize(root);
     //printf("%d\n",size);
     //遍歷數組
     for(i=0;i<size;i++)
     {
         //獲取第i個陣列項
         arrayItem = cJSON_GetArrayItem(root,i);
         if(arrayItem)
         {
              //printf("%s\n","start......");
              //講json結構體轉換成字串
              pr = cJSON_Print(arrayItem);
              item = cJSON_Parse(pr);
              name = cJSON_GetObjectItem(item,"name");
              path = cJSON_GetObjectItem(item,"path");
              flag = cJSON_GetObjectItem(item,"flag");
              na = cJSON_Print(name);
              pa = cJSON_Print(path);
              fl = cJSON_Print(flag);
              //printf("%s\n",pr);
              printf("name:%s\n",na);
              printf("path:%s\n",pa);
              printf("flag:%s\n\n",fl);
         }
     }
}

void parse2(char *out)
{
     cJSON * root,*Root,*Child,*arrayItem,*item,*name,*path,*flag;
     int i = 0,size = 0;
     char *pr = NULL,*na = NULL,*pa = NULL,*fl = NULL;
     root = cJSON_Parse(out);
     if(root)
     {
         Root = cJSON_GetObjectItem(root,"Root");
         if(Root)
         {
              name = cJSON_GetObjectItem(Root,"name");
              path = cJSON_GetObjectItem(Root,"path");
              flag = cJSON_GetObjectItem(Root,"flag");
              na = cJSON_Print(name);
              pa = cJSON_Print(path);
              fl = cJSON_Print(flag);
              printf("Root:\n");
              printf("name:%s\n",na);
              printf("path:%s\n",pa);
              printf("flag:%s\n\n",fl);
         }
         Child = cJSON_GetObjectItem(root,"Child");
         if(Child)
         {
              size = cJSON_GetArraySize(Child);
              //printf("%d\n",size);
              printf("Child:\n");
              for(i=0;i<size;i++)
              {
                   arrayItem = cJSON_GetArrayItem(Child,i);
                   if(arrayItem)
                   {
                       //printf("%s\n","start......");
                       pr = cJSON_Print(arrayItem);
                       item = cJSON_Parse(pr);
                       name = cJSON_GetObjectItem(item,"name");
                       path = cJSON_GetObjectItem(item,"path");
                       flag = cJSON_GetObjectItem(item,"flag");
                       na = cJSON_Print(name);
                       pa = cJSON_Print(path);
                       fl = cJSON_Print(flag);
                       //printf("%s\n",pr);
                       printf("name:%s\n",na);
                       printf("path:%s\n",pa);
                       printf("flag:%s\n\n",fl);
                   }
              }
         }
     }
}

int main()
{
     char *out1 = create1();
     char *out2 = create2();
     char *out3 = create3();
     char *out4 = create4();
     printf("%s\n\n\n",out1);
     parse1(out1);
     printf("%s\n\n\n",out2);
     parse2(out2);
     printf("%s\n\n\n",out3);
     printf("%s\n\n\n",out4);
     return 0;
}

