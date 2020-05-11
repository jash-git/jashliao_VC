#include <iostream>
#include "pthread.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>//#include <unistd.h>//Sleep(WINDOWS) vs sleep(LINUX)
#include <winsock2.h>
#pragma comment(lib, "ws2_32")
using namespace std;
#define MAX 20
/* LINUX C的 jash_thread 轉WINDOWS */
pthread_t thread[4];
pthread_mutex_t mut;
int number;
int i;
void *thread1(void *p)
{
	printf ("thread1 : I'm thread 1\n");
	for (i = 0; i < MAX; i++)
	{
		printf("thread1 : %d\n",i);
		pthread_mutex_lock(&mut);
			if(i<MAX)
			{
				number++;
				printf("thread1 : number = %d\n",number);
			}
		pthread_mutex_unlock(&mut);
		Sleep( 30 );//sleep(1);
	}
	printf("thread1 :主函數在等我完成任務嗎？\n");
	pthread_exit(NULL);
}
void *thread2(void *p)
{
	printf("thread2 : I'm thread 2\n");
	for (i = 0; i < MAX; i++)
	{
		printf("thread2 : %d\n",i);
		pthread_mutex_lock(&mut);
			if(i<MAX)
			{
				number++;
				printf("thread2 : number = %d\n",number);
			}
		pthread_mutex_unlock(&mut);
		Sleep( 30 );//sleep(1);
	}
	printf("thread2 :主函數在等我完成任務嗎？\n");
	pthread_exit(NULL);
}
void *thread3(void *p)
{
	printf("thread3 : I'm thread 3\n");
	for (i = 0; i < MAX; i++)
	{
		printf("thread3 : %d\n",i);
		pthread_mutex_lock(&mut);
			if(i<MAX)
			{
				number++;
				printf("thread3 : number = %d\n",number);
			}
		pthread_mutex_unlock(&mut);
		Sleep( 30 );//sleep(1);
	}
	printf("thread3 :主函數在等我完成任務嗎？\n");
	pthread_exit(NULL);
}
void *thread4(void *p)
{
	printf("thread4 : I'm thread 4\n");
	for (i = 0; i < MAX; i++)
	{
		printf("thread4 : %d\n",i);
		pthread_mutex_lock(&mut);
			if(i<MAX)
			{
				number++;
				printf("thread4 : number = %d\n",number);
			}
		pthread_mutex_unlock(&mut);
		Sleep( 30 );//sleep(1);
	}
	printf("thread4 :主函數在等我完成任務嗎？\n");
	pthread_exit(NULL);
}
void thread_create(void)
{
	int temp;
	memset(&thread, 0, sizeof(thread));          //comment1
	/*創建線程*/
	if((temp = pthread_create(&thread[0], NULL, thread1, NULL)) != 0)       //comment2
	{
		printf("線程1創建失敗!\n");
	}
	else
	{
		printf("線程1被創建\n");
	}
	if((temp = pthread_create(&thread[1], NULL, thread2, NULL)) != 0)  //comment3
	{
		printf("線程2創建失敗");
	}
	else
	{
		printf("線程2被創建\n");
	}

	if((temp = pthread_create(&thread[2], NULL, thread3, NULL)) != 0)  //comment3
	{
		printf("線程3創建失敗");
	}
	else
	{
		printf("線程3被創建\n");
	}
	if((temp = pthread_create(&thread[3], NULL, thread4, NULL)) != 0)  //comment3
	{
		printf("線程4創建失敗");
	}
	else
	{
		printf("線程4被創建\n");
	}
}
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
void thread_wait(void)
{
	/*等待線程結束*/
	for(int i=0;i<4;i++)
	{
        pthread_join(thread[i],NULL);
        printf("線程%d已經結束\n",i);
	}
}
void *connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    SOCKET sock = *(SOCKET*)socket_desc;
    int read_size;
    char *message , client_message[2000];
    char *p='\0';
    printf("thread_%d open\n",sock);
    //Send some messages to the client
    message = "Greetings! I am your connection handler\n";
    ::send(sock , message , strlen(message),0);

    message = "Now type something and i shall repeat what you type \n";
    ::send(sock , message , strlen(message),0);

    //Receive a message from client
    while(1)
    {
        //Send the message back to client
		memset(client_message , '\0' , sizeof(client_message));//clean buffer
		read_size= ::recv(sock , client_message , 2000 , 0);
		printf("\n%s\n",client_message);
		if(read_size > 0)
		{
			p=strstr(client_message,"bye2");
			if((p-client_message)>=0)
			{
				//message="Good Bye Client...";//
				memset(client_message , '\0' , sizeof(client_message));
				sprintf(client_message,"Good Bye Client...[server id: %d]\n",sock);
				::send(sock , client_message , strlen(client_message),0);
				//printf("%s\n",message);
				break;
			}
			else
			{
				p='\0';
				printf("client send: %s\n",client_message);
				strcat(client_message,"-form Server\n");
				::send(sock , client_message , strlen(client_message),0);
				memset(client_message , '\0' , sizeof(client_message));//clean buffer
			}
		}
    }

    if(read_size == 0)
    {
        puts("multi_thread_server: Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }

    //Free the socket pointer
    ::closesocket(sock);

    printf("thread_%d close\n",sock);
    free(socket_desc);

    return 0;
}
int main()
{
    /*
		number=0;
		setlocale(LC_ALL,"Chinese_Taiwan.950");
        //用默認屬性初始化互斥鎖
        pthread_mutex_init(&mut,NULL);
        printf("我是主函數哦，我正在創建線程，呵呵\n");
        thread_create();
        printf("我是主函數哦，我正在等待線程完成任務阿，呵呵\n");
        thread_wait();
    */
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
    SOCKET sClient,*new_sock;
    char szText[] = "TCP Server Demo!\r\n";
    while (true)
    {
        //sClient = ::accept(sListen, (SOCKADDR*)&remoteAddr, &nAddrLen);
        sClient = ::accept(sListen, (LPSOCKADDR)&remoteAddr, &nAddrLen);
        if (sClient == INVALID_SOCKET)
        {
            cout<<"Failed accept()";
            ::closesocket(sClient);
            continue;
        }
        else
        {
            pthread_t sniffer_thread;
            new_sock = (SOCKET*)malloc(sizeof(SOCKET));
            *new_sock = sClient;
            pthread_create( &sniffer_thread , NULL ,  connection_handler , (void*) new_sock);
        }
        cout<<"Received an connection: "<<inet_ntoa(remoteAddr.sin_addr)<<endl;
        //::send(sClient, szText, strlen(szText), 0);

    }
    ::closesocket(sListen);
    Pause();
    return 0;
}
