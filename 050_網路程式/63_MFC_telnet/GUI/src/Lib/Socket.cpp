
#include "StdAfx.h"
#include ".\socket.h"

Socket::Socket(void) : sock(0), buff(0)
{
        array.SetSize(0, 0xFFFF);
        active_connections.SetSize(0, 0x1000);

        strcpy(hostname, "?\0");
}
Socket::~Socket(void)
{
        for (int i = 0; i < active_connections.GetCount(); i++) {          //close server connections
                closesocket(((connections *)active_connections[i])->serv);
                delete((connections *)active_connections[i]);
        }

        if (sock)
                closesocket(sock);
        if (buff)
                delete[] buff;
}

char * Socket::Create(int af, int type, int proto)
{
        family = af;
        socktype = type;
        protocol = proto;
        sock = WSASocket(af, type, proto, 0, 0, WSA_FLAG_OVERLAPPED);
        if (sock == INVALID_SOCKET) {
                sprintf(mess, "Error - %s - in [Socket::Create()]", GetError());
                return mess;
        }

        return 0;
}

char * Socket::Select(HWND handle, UINT msg, long events)
{
        if (WSAAsyncSelect(sock, handle, msg, events)) {
                sprintf(mess, "Error - %s - in [Socket::Select()]", GetError());
                return mess;
        }

        return 0;
}

char *Socket::Connect(const char *addr, WORD port)
{
        this->port = port;
        saddr.sin_family = family;
        saddr.sin_port = htons(port);

        if ((saddr.sin_addr.S_un.S_addr = inet_addr(addr)) == INADDR_NONE) {        //name -> IP
                hostent *host = gethostbyname(addr);
                if (host) {
                        saddr.sin_addr = *((in_addr *)host->h_addr_list[0]);
                        strcpy(hostname, host->h_name);
                } else {
                        sprintf(mess, "Error - %s - in [Socket::Connect() gethostbyname ]", GetError());
                        return mess;
                }
        } else {    //IP -> name
                getnameinfo((sockaddr *)&saddr, sizeof(saddr), hostname, NI_MAXHOST, 0, 0, NI_NAMEREQD);
        }

        if (WSAConnect(sock, (sockaddr *)&saddr, sizeof(saddr), 0, 0, 0, 0)) {
                if (err = GetError()) {
                        sprintf(mess, "Error - %s - in [Socket::WSAConnect() WSAConnect ]", err);
                        return mess;
                }
        }

        return 0;
}

char *Socket::Listen(WORD port)
{
        this->port = port;
        saddr.sin_family = family;
        saddr.sin_port = htons(port);
        saddr.sin_addr.S_un.S_addr = 0;//inet_addr("217.118.81.2");//ADDR_ANY;

        if (bind(sock, (sockaddr *)&saddr, sizeof(saddr))) {
                sprintf(mess, "Error - %s - in [Socket::Listen() bind ]", GetError());
                return mess;
        }
        if (listen(sock, 10)) {
                sprintf(mess, "Error - %s - in [Socket::Listen() listen ]", GetError());
                return mess;
        }

        return 0;
}

char *Socket::Accept()
{
        sockaddr_in caddr;
        int size = sizeof(caddr);

        SOCKET server = accept(sock, (sockaddr *) & caddr, &size);
        if (server == INVALID_SOCKET) {
                sprintf(mess, "Error - %s - in [Socket::Listen() accept ]", GetError());
                return mess;
        }

        connections *newconnection = new connections;
        newconnection->serv = server;
        memcpy(&newconnection->clntaddr, &caddr, sizeof(caddr));
        active_connections.Add(newconnection);

        lastaccepted = server;

        return 0;
}

char *Socket::Disconnect(SOCKET s)
{
        if (s) {
                if (res = closesocket(s)) {
                        sprintf(mess, "Error - %s - in [Socket::Disconnect() closesocket ]", GetError());
                        return mess;
                } else
                        return 0;
        }

        return "zero socket?";
}

bool Socket::Canceled(SOCKET s)
{
        for (int i = 0; i < active_connections.GetCount(); i++)
                if (((connections *)active_connections[i])->serv == s) {
                        closesocket(((connections *)active_connections[i])->serv);
                        delete((connections *)active_connections[i]);
                        active_connections.RemoveAt(i);
                        return true;
                }

        return false;
}



char *Socket::getaddr(SOCKET s)
{
        for (int i = 0; i < active_connections.GetCount(); i++)
                if (((connections *)active_connections[i])->serv == s) {
                        sprintf(mess, "%s", inet_ntoa(((connections *)active_connections[i])->clntaddr.sin_addr));
                        return mess;
                }

        sprintf(mess, "sock %d not found in list?", s);
        return mess;
}
int Socket::getport(SOCKET s)
{
        for (int i = 0; i < active_connections.GetCount(); i++)
                if (((connections *)active_connections[i])->serv == s)
                        return ntohs(((connections *)active_connections[i])->clntaddr.sin_port);

        return 0;
}
char *Socket::getaddr(int index)
{
        for (int i = 0; i < getclientsnum(); i++)
                if (index == i) {
                        sprintf(mess, "%s/%d", inet_ntoa(((connections *)active_connections[i])->clntaddr.sin_addr),
                                ntohs(((connections *)active_connections[i])->clntaddr.sin_port));
                        return mess;
                }

        sprintf(mess, "index %d not found in list?", index);
        return mess;
}
SOCKET Socket::getclientsocket(char *client)             //client = 127.0.0.1/3022
{
        for (int i = 0; i < getclientsnum(); i++) {
                sprintf(mess, "%s/%d", inet_ntoa(((connections *)active_connections[i])->clntaddr.sin_addr),
                        ntohs(((connections *)active_connections[i])->clntaddr.sin_port));
                if (_strcmpi(mess, client) == 0)
                        return ((connections *)active_connections[i])->serv;
        }
        return 0;
}







char *Socket::Read(SOCKET s)
{
        if (s == 0) s = sock;
        if (buff) {
                delete[] buff;
                buff = 0;
        }

        if (res = ioctlsocket(s, FIONREAD, &lastread)) {
                sprintf(mess, "Error - %s - in [Socket::Read() ioctlsocket ]", GetError());
                return mess;
        }

        buff = new char[lastread+1];
        buff[lastread] = 0;
        res = recv(s, buff, lastread, 0);
        if (res == 0)
                return "connection have been closed...";
        if (res == SOCKET_ERROR) {
                sprintf(mess, "Error - %s - in [Socket::Read() recv ]", GetError());
                return mess;
        }


        for (UINT i = 0; i < lastread; i++)
                array.Add((BYTE)buff[i]);


        return buff;
}


char *Socket::Send(char *message, SOCKET s)
{
        if (s == 0) s = sock;

        if (array.GetCount()) {
                array.RemoveAll();
                array.SetSize(0, 0xFFFF);
        }

        res = send(s, message, (int)strlen(message), 0);
        if (res == SOCKET_ERROR) {
                sprintf(mess, "Error - %s - in [Socket::Send() send ]", GetError());
                return mess;
        }

        return 0;
}

char *Socket::GetError()
{
        switch (WSAGetLastError()) {
        case WSAEINTR:
                return "Interrupted function call.";
        case WSAEACCES:
                return "Permission denied.";
        case WSAEFAULT:
                return "Bad address.";
        case WSAEINVAL:
                return "Invalid argument.";
        case WSAEMFILE:
                return "Too many open files.";
        case WSAEWOULDBLOCK:
                return 0;
        case WSAEINPROGRESS:
                return "Operation now in progress.";
        case WSAEALREADY:
                return "Operation already in progress.";
        case WSAENOTSOCK:
                return "Socket operation on nonsocket.";
        case WSAEDESTADDRREQ:
                return "Destination address required.";
        case WSAEMSGSIZE:
                return "Message too long.";
        case WSAEPROTOTYPE:
                return "Protocol wrong type for socket.";
        case WSAENOPROTOOPT:
                return "Bad protocol option.";
        case WSAEPROTONOSUPPORT:
                return "Protocol not supported.";
        case WSAESOCKTNOSUPPORT:
                return "Socket type not supported.";
        case WSAEOPNOTSUPP:
                return "Operation not supported.";
        case WSAEPFNOSUPPORT:
                return "Protocol family not supported.";
        case WSAEAFNOSUPPORT:
                return "Address family not supported by protocol family.";
        case WSAEADDRINUSE:
                return "Address already in use.";
        case WSAEADDRNOTAVAIL:
                return "Cannot assign requested address.";
        case WSAENETDOWN:
                return "Network is down.";
        case WSAENETUNREACH:
                return "Network is unreachable.";
        case WSAENETRESET:
                return "Network dropped connection on reset.";
        case WSAECONNABORTED:
                return "Software caused connection abort.";
        case WSAECONNRESET:
                return "Connection reset by peer.";
        case WSAENOBUFS:
                return "No buffer space available.";
        case WSAEISCONN:
                return "Socket is already connected.";
        case WSAENOTCONN:
                return "Socket is not connected.";
        case WSAESHUTDOWN:
                return "Cannot send after socket shutdown.";
        case WSAETIMEDOUT:
                return "Connection timed out.";
        case WSAECONNREFUSED:
                return "Connection refused.";
        case WSAEHOSTDOWN:
                return "Host is down.";
        case WSAEHOSTUNREACH:
                return "No route to host.";
        case WSAEPROCLIM:
                return "Too many processes.";
        case WSASYSNOTREADY:
                return "Network subsystem is unavailable.";
        case WSAVERNOTSUPPORTED:
                return "Winsock.dll version out of range.";
        case WSANOTINITIALISED:
                return "Successful WSAStartup not yet performed.";
        case WSAEDISCON:
                return "Graceful shutdown in progress.";
        case WSATYPE_NOT_FOUND:
                return "Class type not found.";
        case WSAHOST_NOT_FOUND:
                return "Host not found.";
        case WSATRY_AGAIN:
                return "Nonauthoritative host not found.";
        case WSANO_RECOVERY:
                return "This is a nonrecoverable error.";
        case WSANO_DATA:
                return "Valid name, no data record of requested type.";
        case WSA_INVALID_HANDLE:
                return "Specified event object handle is invalid.";
        case WSA_INVALID_PARAMETER:
                return "One or more parameters are invalid.";
        case WSA_IO_INCOMPLETE:
                return "Overlapped I/O event object not in signaled state.";
        case WSA_IO_PENDING:
                return "Overlapped operations will complete later.";
        case WSA_NOT_ENOUGH_MEMORY:
                return "Insufficient memory available.";
        case WSA_OPERATION_ABORTED:
                return "Overlapped operation aborted.";
                //case WSAINVALIDPROCTABLE:                                            //not in Visual C++ 7.0
                // return "Invalid procedure table from service provider.";
                //case WSAINVALIDPROVIDER:
                // return "Invalid service provider version number.";
                //case WSAPROVIDERFAILEDINIT:
                // return "Unable to initialize a service provider.";
        case WSASYSCALLFAILURE:
                return "System call failure.";
        default:
                return "Unknown code?";
        }
}



/*addrinfo addrout;
        addrinfo addrin;

         addrin.ai_family = family;
         addrin.ai_socktype = socktype;
         addrin.ai_protocol = protocol;
         addrin.ai_addrlen = 0;
         addrin.ai_canonname = 0;
         addrin.ai_addr = 0;
         addrin.ai_next = 0;
         addrin.ai_flags = 0;
    sprintf(mess,"%d",port);
  if(res = getaddrinfo(addr,mess,0,(addrinfo **)&addrout))
       {
     sprintf(mess,"Error - %s - in [Socket::Connect()]",GetError());
          return mess;
       }*/

//saddr.sin_addr = ((sockaddr_in *)(addrout[0].ai_addr))->sin_addr;