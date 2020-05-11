///////////////////////////////
// http://ff320232.blogspot.tw///
//  Atien (c) 2013  //
///////////////////////////////

#include "stdafx.h"
#include "stdlib.h"
#include "AES.h"
#include <string.h>

int main(int argc, char* argv[])
{

	int i,j;
	char str[100];
    unsigned char key[20];

    printf("請輸入要加密的內容:");
	scanf("%s",&str);
	printf("請輸入要加密的鑰匙:");
	scanf("%s",&key);

	AES aes(key);//設定KEY

	printf("\n");
    i=strlen(str);
    printf("要加密的文字");
	for(j=0; j<i;j++)printf("%c",(unsigned char)str[j]);
	printf("\n");

	printf("加密後:");
	aes.Cipher((void *)str);
	for(j=0; j<i;j++)printf("%X",(unsigned char)str[j]);
	printf("\n");

    printf("解密後:");
	aes.InvCipher((void *)str,i);
	for(j=0; j<i;j++)printf("%c",(unsigned char)str[j]);
	printf("\n");

	system("pause");
	return 0;
}


