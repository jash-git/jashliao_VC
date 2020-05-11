
#pragma once

struct connections {
        SOCKET serv;           //SOCKET on server side after accept()
        sockaddr_in clntaddr;  //client address connected to server
};

class Socket
{
        int res;
        char mess[256];
        SOCKET sock;

        sockaddr_in saddr;                 //address to which get connected
        char hostname[NI_MAXHOST];         //host name
        int family, socktype, protocol, port;

        char *buff;                        //buff for 1 single read
        DWORD lastread;                    //len of last read
        char *err;                         //err pointer

        CArray<BYTE> array;                             //whole packet recieved
        CArray<connections *> active_connections;     //connections
        SOCKET lastaccepted;


public:
        Socket(void);
        ~Socket(void);

        char *Create(int, int, int);
        char *Select(HWND, UINT, long);
        char *Connect(const char*, WORD);
        char *Listen(WORD);
        char *Accept();
        char *Disconnect(SOCKET);
        bool Canceled(SOCKET);
        char *Read(SOCKET s = 0);                                    //return 0-terminated char string
        char *Send(char *, SOCKET s = 0);
        char *GetError();


        /////////CLIENT////////////////////////////////////////////////////////////////
        char *gethostname() {
                return &hostname[0];        //client connected host name
        }
        char *getaddr() {
                return inet_ntoa(saddr.sin_addr);        //client socket
        }
        int getport() {
                return port;        //client socket
        }
        int getlastread() {
                return lastread;
        }
        CArray<BYTE> *getarray() {
                return &array;
        }


        /////////SERVER/////////////////////////////////////////////////////////////////
        char *getaddr(SOCKET);                                       //server active connections
        char *getaddr(int);                                          //server active connections
        SOCKET getclientsocket(char *);                              //server active connections
        int getport(SOCKET);                                         //server active connections
        SOCKET getlastaccepted() {
                return lastaccepted;        //lastaccepted socket
        }
        int getclientsnum() {
                return (int)active_connections.GetCount();
        }

};

