#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <locale.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "utf8.h"

static const char g_hex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
static const char BOM_UTF8[] = {0xEF,0xBB,0xBF};
static const char BOM_UTF16BF[] = {0xFE,0xFF};
static const char BOM_UTF16LE[] = {0xFF,0xFE};
static const char BOM_UTF32BE[] = {0x00,0x00,0xFE,0xFF};
static const char BOM_UTF32LE[] = {0xFF,0xFE,0x00,0x00};

#ifdef _MSC_VER
static const char CHINESE_TAIWAN[] = "chinese_taiwan";    //OK
static const char CHINESE_TAIWAN_UTF8[] = "chinese_taiwan.UTF-8"; //Failed
static const char CHINESE_TAIWAN_UTF16[] = "chinese_taiwan.UTF-16"; //Failed
#define UTF8TOWCHAR utf8to16
#define WCHARTOUTF8 utf16to8
#else
static const char CHINESE_TAIWAN[] = "zh_TW";
static const char CHINESE_TAIWAN_UTF8[] = "zh_TW.UTF-8"; //OK
static const char CHINESE_TAIWAN_UTF16[] = "zh_TW.UTF-16"; //Failed
#define UTF8TOWCHAR utf8to32
#define WCHARTOUTF8 utf32to8
#endif

int AnsiToUTF8(char* out, int outsize, const char* in, int insize, const char* codepage)
{
    if(outsize > 0 && insize > 0 && out && in && setlocale(LC_ALL,codepage))
    {
        wchar_t* wcstmp = new wchar_t[insize/2 + 1];
        mbstowcs(wcstmp, in, insize/2+1);
        char* end_it = utf8::unchecked::WCHARTOUTF8(wcstmp, wcstmp + wcslen(wcstmp) + 1 , out);
        delete [] wcstmp;
        int size = end_it - out - 1;
        if(size < outsize-1){out[size]=0;out[size+1]=0;}
        return size;
    }
    return 0;
}

int UTF8ToAnsi(char* out, int outsize, const char* in, int insize, const char* codepage)
{
    if(outsize > 0 && insize > 0 && out && in && setlocale(LC_ALL,codepage))
    {
        wchar_t* wcstmp = new wchar_t[insize/2 + 1];
        wchar_t* end_it = utf8::unchecked::UTF8TOWCHAR(in, in + strlen(in) + 1 , wcstmp);
        int size = wcstombs(out, wcstmp, outsize);
        delete [] wcstmp;
        if(size < outsize-1){out[size]=0;out[size+1]=0;}
        return size;
    }
    return 0;
}

int AnsiToWCHAR(wchar_t* out, int outsize, const char* in, int insize, const char* codepage)
{
    if(outsize > 0 && insize > 0 && out && in && setlocale(LC_ALL,codepage))
    {
        int size = mbstowcs(out,in,outsize);
        if(size < outsize - 1){out[size]=0;out[size+1]=0;}
        return size;
    }
    return 0;
}

int WCHARToAnsi(char* out, int outsize, const wchar_t* in, int insize, const char* codepage)
{
    if(outsize > 0 && insize > 0 && out && in && setlocale(LC_ALL,codepage))
    {
        int size = wcstombs(out, in, outsize);
        if(size < outsize - 1){out[size]=0;out[size+1]=0;}
        return size;
    }
    return 0;
}

void buftostr(unsigned char* buf, unsigned short size, char* str, unsigned short len)
{
    unsigned char c,l,r;
    unsigned short i,j;
    if(size==0||len<3){*str=0;return;}
    for(i=0,j=0; i<size&&j<len-3; ++i)
    {
        c = *(buf+i);
        l = c>>4;
        r = c - (l<<4);
        *(str+j++) = g_hex[l];
        *(str+j++) = g_hex[r];
        //*(str+j++) = ' ';
    }
    *(str+j) = 0;
}

int main(int argc, char* argv[])
{
    cout<<"CHAR SIZE:"<<sizeof(char)<<" WCHAR SIZE:"<<sizeof(wchar_t)<<endl;

    wchar_t wt1[256],wt2[256],wt3[256],wt4[256];
    char t1[512],t2[512],t3[512],t4[512],t5[512],t6[512],t7[512],t8[512],t9[512],ta[512],tb[512],tc[512],td[512],te[512],tf[512];

    fstream fsIB5,fsIU8,fsIU2;
    fsIB5.rdbuf()->open("b5.txt",ios::in|ios::binary);
    fsIU8.rdbuf()->open("u8.txt",ios::in|ios::binary);
    fsIU2.rdbuf()->open("u2.txt",ios::in|ios::binary);

    if (fsIB5.fail() || !fsIB5.good() || !fsIB5.rdbuf()->is_open()) {
        cout << "Could not open b.txt" << endl;
        return 0;
    }
    if (fsIU8.fail() || !fsIU8.good() || !fsIU8.rdbuf()->is_open()) {
        cout << "Could not open u.txt" << endl;
        return 0;
    }
    if (fsIU2.fail() || !fsIU2.good() || !fsIU2.rdbuf()->is_open()) {
        cout << "Could not open u2.txt" << endl;
        return 0;
    }

    int size1 = fsIB5.rdbuf()->sgetn(t1,508);
    int size2 = fsIU8.rdbuf()->sgetn(t2,508);
    int size3 = fsIU2.rdbuf()->sgetn(t3,508);
    t1[size1] = 0;
    t1[size1+1] = 0;
    t2[size2] = 0;
    t3[size3] = 0;

    if( memcmp(t2,BOM_UTF8,sizeof(BOM_UTF8)) == 0)
    {
        fsIU8.rdbuf()->pubseekoff(sizeof(BOM_UTF8),ios_base::beg);
        size2 = fsIU8.rdbuf()->sgetn(t2,508);
        t2[size2] = 0;
        t2[size2+1] = 0;
        t2[size2+2] = 0;
        t2[size2+3] = 0;
    }

    if( memcmp(t3,BOM_UTF16LE,sizeof(BOM_UTF16LE)) == 0)
    {
        fsIU2.rdbuf()->pubseekoff(sizeof(BOM_UTF16LE),ios_base::beg);
        size3 = fsIU2.rdbuf()->sgetn(t3,508);
        t3[size3] = 0;
        t3[size3+1] = 0;
        t3[size3+2] = 0;
        t3[size3+3] = 0;
    }

    buftostr((unsigned char*)t1,size1,t4,512);
    buftostr((unsigned char*)t2,size2,t5,512);
    buftostr((unsigned char*)t3,size3,t6,512);

    cout<<"Big5("<<size1<<"):"<<t4<<endl;
    cout<<"UTF8("<<size2<<"):"<<t5<<endl;
    cout<<"UTF16("<<size3<<"):"<<t6<<endl;

    char* tloc;
    tloc = setlocale(LC_ALL,CHINESE_TAIWAN);
    int size4 = mbstowcs(wt1,t1,256);
    if(tloc != 0)
        cout<<tloc<<endl;
    else
        cout<<"set locale 950(Chinese Taiwan Big5) Error!"<<endl;

    tloc = setlocale(LC_ALL,CHINESE_TAIWAN_UTF8);
    int size5 = mbstowcs(wt2,t2,256);
    if(tloc != 0)
        cout<<tloc<<endl;
    else
        cout<<"set locale 65001(UTF-8) Error!"<<endl;

    tloc = setlocale(LC_ALL,CHINESE_TAIWAN_UTF16);
    int size6 = mbstowcs(wt3,t3,256);
    if(tloc != 0)
        cout<<tloc<<endl;
    else
        cout<<"set locale 1200(UTF-16) Error!"<<endl;

    buftostr((unsigned char*)wt1,wcslen(wt1)*sizeof(wchar_t),t7,512);
    buftostr((unsigned char*)wt2,wcslen(wt2)*sizeof(wchar_t),t8,512);
    buftostr((unsigned char*)wt3,wcslen(wt3)*sizeof(wchar_t),t9,512);

    cout<<"Big5 to WCHAR("<<size4<<"):"<<t7<<endl;
    cout<<"UTF8 to WCHAR("<<size5<<"):"<<t8<<endl;
    cout<<"UTF16 to WCHAR("<<size6<<"):"<<t9<<endl;

    tloc = setlocale(LC_ALL,CHINESE_TAIWAN);
    int size7 = wcstombs(ta,wt1,512);
    if(tloc != 0)
        cout<<tloc<<endl;
    else
        cout<<"set locale 950(Chinese Taiwan Big5) Error!"<<endl;

    tloc = setlocale(LC_ALL,CHINESE_TAIWAN_UTF8);
    int size8 = wcstombs(tb,wt2,512);
    if(tloc != 0)
        cout<<tloc<<endl;
    else
        cout<<"set locale 65001(UTF-8) Error!"<<endl;

    tloc = setlocale(LC_ALL,CHINESE_TAIWAN_UTF16);
    int size9 = wcstombs(tc,wt3,512);
    if(tloc != 0)
        cout<<tloc<<endl;
    else
        cout<<"set locale 1200(UTF-16) Error!"<<endl;

    buftostr((unsigned char*)ta,strlen(ta)*sizeof(char),td,512);
    buftostr((unsigned char*)tb,strlen(tb)*sizeof(char),te,512);
    buftostr((unsigned char*)tc,strlen(tc)*sizeof(char),tf,512);

    cout<<"Big5 to WCHAR to Big5("<<size7<<"):"<<td<<endl;
    cout<<"UTF8 to WCHAR to UTF8("<<size8<<"):"<<te<<endl;
    cout<<"UTF16 to WCHAR to UTF16("<<size9<<"):"<<tf<<endl;

    cout<<"=========================================================="<<endl;

    char* cend;
    cend = (char*)utf8::unchecked::utf8to16(t2, t2 + size2 + 1, (unsigned short*)t5);
    size5 = cend - t5 - 2;
    cend = utf8::unchecked::utf16to8((unsigned short*)t3, (unsigned short*)(t3 + size3 + 2), t6);
    size6 = cend - t6 - 1;

    buftostr((unsigned char*)t5,size5*sizeof(char),t9,512);
    buftostr((unsigned char*)t6,size6*sizeof(char),ta,512);

    cout<<"UTF8 to UTF16("<<size5<<"):"<<t9<<endl;
    cout<<"UTF16 to UTF8("<<size6<<"):"<<ta<<endl;

    cend = (char*)utf8::unchecked::utf8to32(t2, t2 + size2 + 1, (unsigned int*)t7);
    size7 = cend - t7 - 4;
    cend = (char*)utf8::unchecked::utf8to32(t6, t6 + size6 + 1, (unsigned int*)t8);
    size8 = cend - t8 - 4;

    buftostr((unsigned char*)t7,size7*sizeof(char),t9,512);
    buftostr((unsigned char*)t8,size8*sizeof(char),ta,512);

    cout<<"UTF8 to UTF32("<<size7<<"):"<<t9<<endl;
    cout<<"UTF16 to UTF8 to UTF32("<<size8<<"):"<<ta<<endl;

    size4 = AnsiToWCHAR(wt4, 256, t1 ,size1+1,CHINESE_TAIWAN);
    wchar_t* wtp = utf8::unchecked::UTF8TOWCHAR(t2, t2 + size2 + 1, wt2);
    size9 = wtp - wt2 - 1;

    buftostr((unsigned char*)wt4,size4*sizeof(wchar_t),t9,512);
    buftostr((unsigned char*)wt2,size9*sizeof(wchar_t),ta,512);

    cout<<"ANSI to WCHAR("<<size4<<"):"<<t9<<endl;
    cout<<"UTF8 to WCHAR("<<size9<<"):"<<ta<<endl;

    size2 = WCHARToAnsi(t2,512,wt2,size9,CHINESE_TAIWAN);
    cend = utf8::unchecked::WCHARTOUTF8(wt4,wt4+size4 + 1,t3);
    size3 = cend - t3 - 1;

    buftostr((unsigned char*)t2,size2*sizeof(char),t9,512);
    buftostr((unsigned char*)t3,size3*sizeof(char),ta,512);

    cout<<"ANSI to WCHAR to UTF8("<<size3<<"):"<<ta<<endl;
    cout<<"UTF8 to WCHAR to ANSI("<<size2<<"):"<<t9<<endl;

    size4 = UTF8ToAnsi(t4,512,t3,size3,CHINESE_TAIWAN);
    size5 = AnsiToUTF8(t5,512,t2,size2,CHINESE_TAIWAN);
    buftostr((unsigned char*)t4,size4*sizeof(char),t9,512);
    buftostr((unsigned char*)t5,size5*sizeof(char),ta,512);

    cout<<"ANSI to WCHAR to UTF8 to ANSI("<<size4<<"):"<<t9<<endl;
    cout<<"UTF8 to WCHAR to ANSI to UTF8("<<size5<<"):"<<ta<<endl;
	system("pause");
        return 0;
}