#include <iostream>
#include <cstdio>
#include <winsock2.h>
#pragma comment(lib, "ws2_32")
using namespace std;
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main()
{
    WSADATA wsaData;
    WORD version = MAKEWORD(2, 2);
    if (::WSAStartup(version, &wsaData) != 0)
    {
        exit(0);
    }

    SOCKET s = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (s == INVALID_SOCKET)
    {
        cout<<"Failed socket()\n";
        return 0;
    }

    sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(4567);
    sin.sin_addr.S_un.S_addr = INADDR_ANY;
    if (::bind(s, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
    {
        cout<<"Failed bind()\n";
        return 0;
    }
    char buff[1024];
    sockaddr_in addr;
    int nLen = sizeof(addr);
    while (true)
    {
        int nRecv = ::recvfrom(s, buff, 1024, 0, (sockaddr*)&addr, &nLen);
        if (nRecv > 0)
        {
            buff[nRecv] = '\0';
            cout<<"Received information ("<<inet_ntoa(addr.sin_addr)<<"):"<<buff<<endl;
        }
    }
    ::closesocket(s);
    ::WSACleanup();
    Pause();
    return 0;
}
