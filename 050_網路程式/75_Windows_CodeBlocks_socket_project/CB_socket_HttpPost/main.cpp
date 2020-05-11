#include <iostream>
#include <cstdio>

#include <vector>
#include <sstream>

#include <winsock2.h>
#pragma comment(lib, "ws2_32")
using namespace std;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

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
    servAddr.sin_port = htons(8080);
    servAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    if (::connect(s, (sockaddr*)&servAddr, sizeof(servAddr)) == -1)
    {
        cout<<"Failed connect()"<<endl;
        return 0;
    }

    //--
    char *pHttpPost = "POST %s HTTP/1.1\r\n"
        "Host: %s:%d\r\n"
        "Content-Type: application/x-www-form-urlencoded\r\n"
        "Content-Length: %d\r\n\r\n"
        "%s";
    char* msg = "username=jash&password=1234";

    char strHttpPost[1024] = {0};
    char* addr = "http://localhost:8080/cs2php/login.php";
    char* host = "127.0.0.1";
    int port = 8080;

    sprintf(strHttpPost, pHttpPost, addr, host, port, strlen(msg), msg);
    send(s, strHttpPost, strlen(strHttpPost), 0);

    char buff[256];
    std::string strbuf="";
    int nRecv;
    do
    {
        nRecv = ::recv(s, buff, 256, 0);
        if(nRecv>0)
        {
            cout<<buff;
            strbuf+=buff;
            buff[0]='\0';
        }
    }while(nRecv>0);
    //--
    ::closesocket(s);

    vector<string> headerLines = split(strbuf, '\r\n');
    cout <<endl<<headerLines.size()<<endl;
    strbuf="";
    for (int i=0; i != headerLines.size(); ++i) {
        //cout <<headerLines[i]<<endl;
        if (headerLines[i].find("Set-Cookie:") != std::string::npos) {
            std::string variablesPart = split(split(headerLines[i], ';')[0], ':')[1];
            std::cout << "\nExtracted: {" << variablesPart << "}";
            strbuf+="Set-Cookie:"+variablesPart+";path=/\r\n";
        }
    }

    ::WSACleanup();
    Pause();
    return 0;
}

