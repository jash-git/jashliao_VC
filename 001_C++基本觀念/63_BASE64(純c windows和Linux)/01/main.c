#include<stdio.h>
#include<string.h>

char BASE64CODE[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '+', '/'
};

void base64en(char *srcStr, char *desStr);
void base64de(char *srcStr, char *desStr);

int main(int argc, char **argv)
{
    char src[1000] = {0};
    char en[1000] = {0},de[1000];

    if(argc == 1)
        strcpy(src, "test");
    else
        strcpy(src, argv[1]);

    base64en(src, en);
    printf("%s => %s\n", src, en);
    base64de(en, de);
    printf("%s => %s\n", en, de);
/*
    base64de("aHR0cDovL3d3dy5tb2QubC1jZW8udHcvYXV0aC5hc3B4", de);
    printf("%s => %s\n", en, de);
    base64de("VEVTVCBDaGFubmVs", de);
    printf("%s => %s\n", en, de);
    base64de("cHdk", de);
    printf("%s => %s\n", en, de);
    base64de("dGVzdA==", de);
    printf("%s => %s\n", en, de);
*/
    return 0;
}

void base64en(char *srcStr, char *desStr)
{
    unsigned char srcCode[3];
    unsigned int i,j,len;

    len = strlen(srcStr)/3;
    for (i = 0; i < len; i++)
    {
        srcCode[0] = srcStr[i * 3 + 0];
        srcCode[1] = srcStr[i * 3 + 1];
        srcCode[2] = srcStr[i * 3 + 2];

        desStr[i * 4 + 0] = BASE64CODE[srcCode[0] >> 2];
        desStr[i * 4 + 1] = BASE64CODE[((srcCode[0]&0x03)<<4) + (srcCode[1]>>4)];
        desStr[i * 4 + 2] = BASE64CODE[((srcCode[1]&0x0f)<<2) + (srcCode[2]>>6)];
        desStr[i * 4 + 3] = BASE64CODE[srcCode[2]&0x3f];
    }

    i = len;
    j = strlen(srcStr) - len * 3;
    if (j > 0)
    {
        srcCode[0] = srcStr[i * 3 + 0];
        srcCode[1] = (j > 1) ? srcStr[i * 3 + 1] : '\0';
        srcCode[2] = '\0';

        desStr[i * 4 + 0] = BASE64CODE[srcCode[0] >> 2];
        desStr[i * 4 + 1] = BASE64CODE[((srcCode[0]&0x03)<<4) + (srcCode[1]>>4)];
        desStr[i * 4 + 2] = (srcCode[1] == '\0') ? '=' : BASE64CODE[(srcCode[1]&0x0f)<<2];
        desStr[i * 4 + 3] = '=';

        i++;
    }

    desStr[i * 4] = '\0';
}

int base64_index(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A';
    if (ch >= 'a' && ch <= 'z')
        return ch - 'a' + 26;
    if (ch >= '0' && ch <= '9')
        return ch - '0' + 52;
    if (ch == '+')
        return 62;
    if (ch == '/')
        return 63;
}

void base64de(char *srcStr, char *desStr)
{
    unsigned char srcCode[4];
    unsigned int i, j, len;

    len = strlen(srcStr)/4 - 1;
    for (i = 0; i < len; i++)
    {
        srcCode[0] = base64_index(srcStr[i * 4 + 0]);
        srcCode[1] = base64_index(srcStr[i * 4 + 1]);
        srcCode[2] = base64_index(srcStr[i * 4 + 2]);
        srcCode[3] = base64_index(srcStr[i * 4 + 3]);

        desStr[i * 3 + 0] = (srcCode[0]<<2) + (srcCode[1]>>4);
        desStr[i * 3 + 1] = (srcCode[1]<<4) + (srcCode[2]>>2);
        desStr[i * 3 + 2] = ((srcCode[2]&0x03)<<6) + srcCode[3];
    }

    i = len;

    srcCode[0] = base64_index(srcStr[i * 4 + 0]);
    srcCode[1] = base64_index(srcStr[i * 4 + 1]);

    desStr[i * 3 + 0] = (srcCode[0]<<2) + (srcCode[1]>>4);

    if (srcStr[i * 4 + 2] == '=')
    {
        desStr[i * 3 + 1] = '\0';
    }
    else if (srcStr[i * 4 + 3] == '=')
    {
        srcCode[2] = base64_index(srcStr[i * 4 + 2]);

        desStr[i * 3 + 1] = (srcCode[1]<<4) + (srcCode[2]>>2);
        desStr[i * 3 + 2] = '\0';
    }
    else
    {
        srcCode[2] = base64_index(srcStr[i * 4 + 2]);
        srcCode[3] = base64_index(srcStr[i * 4 + 3]);

        desStr[i * 3 + 1] = (srcCode[1]<<4) + (srcCode[2]>>2);
        desStr[i * 3 + 2] = ((srcCode[2]&0x03)<<6) + srcCode[3];
        desStr[i * 3 + 3] = '\0';
    }
}
