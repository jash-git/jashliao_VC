#include <iostream>
#include <cstdio>
#include <winsock2.h>
using namespace std;
//¸ê®Æ¨Ó·½:https://yq.aliyun.com/articles/47195

void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main()
{
    cout << "Hello world!" << endl;
    WSADATA wsaData;
    WORD version = MAKEWORD(2, 2);
    if(::WSAStartup(version, &wsaData) != 0)
    {
        exit(0);
    }

    char szHost[256];
    ::gethostname(szHost, 256);
    hostent *pHost = ::gethostbyname(szHost);
    in_addr addr;
    for (int i = 0; ; i++)
    {
        char *p = pHost->h_addr_list[i];
        if (p == NULL)
        {
            break;
        }
        memcpy(&addr.S_un.S_addr, p, pHost->h_length);
        char *szIp = ::inet_ntoa(addr);
        cout<<szIp<<endl;
    }

    ::WSACleanup();

    Pause();
    return 0;
}
