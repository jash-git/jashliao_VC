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
    WSAStartup(version, &wsaData);

    SOCKET sListen = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sListen == INVALID_SOCKET)
    {
        return 0;
    }

    sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(4567);
    sin.sin_addr.S_un.S_addr = INADDR_ANY;
    if (::bind(sListen, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
    {
        cout<<"Failed bind()"<<endl;
        return 0;
    }

    if (::listen(sListen, 2) == SOCKET_ERROR)
    {
        cout<<"Failed listen()"<<endl;
        return 0;
    }

    sockaddr_in remoteAddr;
    int nAddrLen = sizeof(remoteAddr);
    SOCKET sClient;
    char szText[] = "TCP Server Demo!\r\n";
    while (true)
    {
        //sClient = ::accept(sListen, (SOCKADDR*)&remoteAddr, &nAddrLen);
        sClient = ::accept(sListen, (LPSOCKADDR)&remoteAddr, &nAddrLen);
        if (sClient == INVALID_SOCKET)
        {
            cout<<"Failed accept()";
            continue;
        }
        cout<<"Received an connection: "<<inet_ntoa(remoteAddr.sin_addr)<<endl;
        ::send(sClient, szText, strlen(szText), 0);
        ::closesocket(sClient);
    }
    ::closesocket(sListen);
    Pause();
    return 0;
}
