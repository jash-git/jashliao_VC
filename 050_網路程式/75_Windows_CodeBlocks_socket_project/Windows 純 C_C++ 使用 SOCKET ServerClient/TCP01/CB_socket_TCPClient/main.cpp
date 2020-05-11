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

    SOCKET s = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (s == INVALID_SOCKET)
    {
        cout<<"Failed socket()"<<endl;
        return 0;
    }

    sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(4567);
    servAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    if (::connect(s, (sockaddr*)&servAddr, sizeof(servAddr)) == -1)
    {
        cout<<"Failed connect()"<<endl;
        return 0;
    }

    char buff[255];
    int nRecv = ::recv(s, buff, 256, 0);
    if (nRecv > 0)
    {
        buff[nRecv] = '\0';
        cout<<"Received information: "<<buff<<endl;
    }

    ::closesocket(s);
    ::WSACleanup();
    Pause();
    return 0;
}
