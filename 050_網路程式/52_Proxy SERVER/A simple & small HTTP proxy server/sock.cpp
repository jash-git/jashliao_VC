// sock.cpp : Defines the entry point for the console application.
//


#include<winsock.h>
#include<windows.h>
#include<iostream.h>
#include<stdio.h>

WSADATA ss;
SOCKET a,s[100];
sockaddr_in s1,s2;
int pos;
unsigned long id;
HANDLE han[100];

DWORD WINAPI thread(
  LPVOID lpParameter   // thread data
)
{
	int cur = pos;
	int sub = 0;
	char rec[20000];
	char host[100];
	char sen[20000];
	char sen1[20000];
	for(int z=0;z<20000;z++)
	{
		rec[z]=sen[z]=sen1[z]=0;
		host[z]=0;
	}
	z = 0;
	int sz;
	int pos = 0;
	char d1='A',d2,d3;
	goto mid;
mid:
	recv(s[cur],&d1,1,0);
	rec[pos] = d1;
	pos++;
	if(d1=='\n')
	{
		recv(s[cur],&d2,1,0);
		recv(s[cur],&d3,1,0);
		if(d2=='\r' && d3=='\n')
		{
			rec[pos] = d2;
			pos++;
			rec[pos] = d3;
			sz = pos;
			rec[pos+1]=NULL;
		}
		else
		{
			rec[pos] = d2;
			pos++;
			rec[pos] = d3;
			pos++;
			goto mid;
		}
	}
	
	else
	{
		goto mid;
	}
	//sz = recv(s[cur],rec,2000,0);
	printf("%s\n",rec);


	while(rec[z]!=':')
	{
		z++;
		if(rec[z]==NULL || rec[z]=='\n')
		{
			closesocket(s[cur]);
			return 0;
		}
	}
	z++;
	z++;
	z++;
	int temp = 0;
	while(rec[z]!='/')
	{
		host[temp] = rec[z];
		z++;
		temp++;

	}

	temp = 0;
	z=0;
	while(rec[z]!='h')
	{
		sen1[temp] = rec[z];
		z++;
		temp++;

	}

	z++;
	
	while(rec[z]!='/')
	{
		z++;
	}
	z++;
	z++;
	while(rec[z]!='/')
	{
		z++;
	}

	while(rec[z]!=NULL)
	{
		sen1[temp] = rec[z];
		z++;
		temp++;

	}

	PHOSTENT adr = NULL;
	adr = gethostbyname(host);
	if(adr==NULL)
	{
		send(s[cur],"Could not able to resolve host address",48,0);
		closesocket(s[cur]);
		DWORD ff;
		GetExitCodeThread(han[cur],&ff);
		ExitThread(ff);

	}
	
	SOCKET ss;
	sockaddr_in dd;
	ss = socket(AF_INET,SOCK_STREAM,0);
	memcpy((char FAR *)&(dd.sin_addr),adr->h_addr,adr->h_length);
	dd.sin_family = AF_INET;
	dd.sin_port = htons(80);
	if(connect(ss,(LPSOCKADDR)&dd,sizeof(dd))==SOCKET_ERROR)
	{
		send(s[cur],"Not able to connect to server",29,0);
		closesocket(s[cur]);
		DWORD ff;
		GetExitCodeThread(han[cur],&ff);
		ExitThread(ff);

	}

	send(ss,sen1,sz,0);
	sz = recv(ss,rec,2000,0);
	while(sz!=0)
	{
		send(s[cur],rec,sz,0);
		sz = recv(ss,rec,2000,0);
	}

	closesocket(ss);
	closesocket(s[cur]);

	
	DWORD ff;
	GetExitCodeThread(han[cur],&ff);
	ExitThread(ff);
	return 0;
}
 







void main()
{
	WSAStartup(MAKEWORD(1,1),&ss);
	a = socket(AF_INET,SOCK_STREAM,0);
	s1.sin_addr.s_addr = INADDR_ANY;
	s1.sin_family = AF_INET;
	s1.sin_port = htons(2323);

	if(bind(a,(LPSOCKADDR)&s1,sizeof(s1))==SOCKET_ERROR)
	{
		cout << WSAGetLastError();

	}

	if(listen(a,1)==SOCKET_ERROR)
	{

		cout << "Error";
	}
	int sz = sizeof(s2);
	goto re;
re:
	s[pos] = accept(a,(LPSOCKADDR)&s2,&sz);
	::han[pos]=CreateThread(NULL,0,&thread,0,0,&id);
		
	Sleep(500);
	if(pos==100)
	{
		pos=0;
	}
	else
	{
		pos++;
	}
	goto re;
	

}
