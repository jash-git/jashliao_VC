#include <stdio.h>
#include "aes.h"

int main(int argc, char *argv[])
{
    char mingwen[] = "http://www.baidu.com";
    char miwen_hex[1024];
    //char miwen_hex[] = "8FEEEFE524F8B68DC1FCA2899AC1A6B82E636F6D";
    char result[1024];
    unsigned char key[] = "my name is jash";
    AES aes(key);
    aes.Cipher(mingwen, miwen_hex);
    printf("%s\n",miwen_hex);
    aes.InvCipher(miwen_hex, result);
    printf("%s\n",result);
    getchar();
    return 0;
}
