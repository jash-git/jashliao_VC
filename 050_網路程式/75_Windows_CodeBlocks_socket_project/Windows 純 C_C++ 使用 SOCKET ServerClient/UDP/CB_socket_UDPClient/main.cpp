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

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(4567);
    addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

    char szText[] = "TCP Server Demo!\r\n";
    ::sendto(s, szText, strlen(szText), 0, (sockaddr*)&addr, sizeof(addr));
    closesocket(s);
    ::WSACleanup();
    Pause();
    return 0;
}
