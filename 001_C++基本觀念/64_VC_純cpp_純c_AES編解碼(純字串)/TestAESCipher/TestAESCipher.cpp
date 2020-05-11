///////////////////////////////
// http://mingcn.cnblogs.com //
//  xelz CopyRight (c) 2010  //
///////////////////////////////

#include "stdafx.h"
#include "AES.h"

void print(unsigned char* state);

int main(int argc, char* argv[])
{
	unsigned char input[] = 
	{
		0x32, 0x43, 0xf6, 0xa8, 
		0x88, 0x5a, 0x30, 0x8d, 
		0x31, 0x31, 0x98, 0xa2, 
		0xe0, 0x37, 0x07, 0x34
	};
	unsigned char key[] = 
	{
		0x2b, 0x7e, 0x15, 0x16, 
		0x28, 0xae, 0xd2, 0xa6, 
		0xab, 0xf7, 0x15, 0x88, 
		0x09, 0xcf, 0x4f, 0x3c
	};
	AES aes(key);
	
	printf("Input:\n");
	print(input);

	aes.Cipher(input);
	printf("After Cipher:\n");
	print(input);

	aes.InvCipher(input);
	printf("After InvCipher:\n");
	print(input);

	int j;
	printf("\n");
	char str[32] = "Hello,My AES Cipher!";
	for(j=0; j<32; j++)printf("%X ",(unsigned char)str[j]);
	printf("%s\n",str);
	printf("\n");
	aes.Cipher((void *)str);
	for(j=0; j<32; j++)printf("%X ",(unsigned char)str[j]);
	printf("%s\n",str);
	printf("\n");
	aes.InvCipher((void *)str,21);
	for(j=0; j<32; j++)printf("%X ",(unsigned char)str[j]);
	printf("%s\n",str);
	printf("\n");
	return 0;
}

void print(unsigned char* state)
{
	int i;
	for(i=0; i<16; i++)
	{
		printf("%s%X ",state[i]>15 ? "" : "0", state[i]);
	}
	printf("\n");
}

