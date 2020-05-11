#include <iostream>
#include "pthread.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>//#include <unistd.h>//Sleep(WINDOWS) vs sleep(LINUX)
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
int main()
{
		number=0;
		setlocale(LC_ALL,"Chinese_Taiwan.950");
        /*用默認屬性初始化互斥鎖*/
        pthread_mutex_init(&mut,NULL);
        printf("我是主函數哦，我正在創建線程，呵呵\n");
        thread_create();
        printf("我是主函數哦，我正在等待線程完成任務阿，呵呵\n");
        thread_wait();
        Pause();
    return 0;
}
